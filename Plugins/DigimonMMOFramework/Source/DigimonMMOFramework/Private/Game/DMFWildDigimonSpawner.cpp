#include "Game/DMFWildDigimonSpawner.h"

#include "Components/DMFDigimonCombatComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/Pawn.h"
#include "Game/DMFDayNightSky.h"
#include "Game/DMFWildDigimonCharacter.h"
#include "DigimonMMOFramework.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"

float FDMFWildSpawnRarityWeights::GetWeight(const EDMFWildSpawnRarity Rarity) const
{
    switch (Rarity)
    {
    case EDMFWildSpawnRarity::Common: return FMath::Max(0.0f, Common);
    case EDMFWildSpawnRarity::Uncommon: return FMath::Max(0.0f, Uncommon);
    case EDMFWildSpawnRarity::Rare: return FMath::Max(0.0f, Rare);
    case EDMFWildSpawnRarity::Epic: return FMath::Max(0.0f, Epic);
    case EDMFWildSpawnRarity::Legendary: return FMath::Max(0.0f, Legendary);
    case EDMFWildSpawnRarity::Mythic: return FMath::Max(0.0f, Mythic);
    default: return 0.0f;
    }
}

ADMFWildDigimonSpawner::ADMFWildDigimonSpawner()
{
    bReplicates = true;
    SetReplicateMovement(false);
    PrimaryActorTick.bCanEverTick = false;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    SpawnAreaPreview = CreateDefaultSubobject<USphereComponent>(TEXT("SpawnAreaPreview"));
    SpawnAreaPreview->SetupAttachment(SceneRoot);
    SpawnAreaPreview->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SpawnAreaPreview->SetGenerateOverlapEvents(false);
    SpawnAreaPreview->SetCanEverAffectNavigation(false);
    SpawnAreaPreview->SetHiddenInGame(true);
}

void ADMFWildDigimonSpawner::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    DeactivationRadius = FMath::Max(ActivationRadius, DeactivationRadius);
    MaximumSpawnCount = FMath::Max(MinimumSpawnCount, MaximumSpawnCount);
    MaximumRespawnDelay = FMath::Max(MinimumRespawnDelay, MaximumRespawnDelay);
    MaximumRoamDelay = FMath::Max(MinimumRoamDelay, MaximumRoamDelay);
    LeashRadius = FMath::Max(AggroRange, LeashRadius);
    RoamRadius = FMath::Min(FMath::Max(0.0f, RoamRadius), FMath::Max(0.0f, LeashRadius));

    if (SpawnAreaPreview)
    {
        SpawnAreaPreview->SetSphereRadius(FMath::Max(0.0f, SpawnRadius));
    }
}

void ADMFWildDigimonSpawner::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority() && GetWorld())
    {
        RefreshDayNightPopulationPhase();
        const float Interval = FMath::Max(0.1f, ProximityCheckInterval);
        GetWorld()->GetTimerManager().SetTimer(ProximityTimer, this, &ADMFWildDigimonSpawner::EvaluatePlayerProximity, Interval, true, 0.1f);
    }
}

void ADMFWildDigimonSpawner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(ProximityTimer);
        World->GetTimerManager().ClearTimer(PopulationTimer);
    }
    Super::EndPlay(EndPlayReason);
}

void ADMFWildDigimonSpawner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFWildDigimonSpawner, bSpawnerActive);
    DOREPLIFETIME(ADMFWildDigimonSpawner, ReplicatedAliveCount);
    DOREPLIFETIME(ADMFWildDigimonSpawner, ReplicatedTargetPopulation);
    DOREPLIFETIME(ADMFWildDigimonSpawner, ReplicatedPopulationPhase);
}

void ADMFWildDigimonSpawner::RefreshSpawnerNow()
{
    if (HasAuthority())
    {
        RefreshDayNightPopulationPhase();
        EvaluatePlayerProximity();
    }
}

void ADMFWildDigimonSpawner::ForceActivateSpawner()
{
    if (HasAuthority())
    {
        RefreshDayNightPopulationPhase();
        ActivateSpawnerInternal();
    }
}

void ADMFWildDigimonSpawner::ForceDeactivateSpawner()
{
    if (HasAuthority())
    {
        DeactivateSpawnerInternal();
    }
}

void ADMFWildDigimonSpawner::EvaluatePlayerProximity()
{
    if (!HasAuthority())
    {
        return;
    }

    RefreshDayNightPopulationPhase();
    RetireInactivePhaseWild();
    CleanupInvalidManagedWild();

    if (!bSpawnerEnabled)
    {
        if (bSpawnerActive)
        {
            DeactivateSpawnerInternal();
        }
        return;
    }

    if (!bSpawnerActive)
    {
        if (CountNearbyPlayers(FMath::Max(0.0f, ActivationRadius)) >= FMath::Max(1, MinimumNearbyPlayers))
        {
            ActivateSpawnerInternal();
        }
        return;
    }

    if (CountNearbyPlayers(FMath::Max(ActivationRadius, DeactivationRadius)) >= FMath::Max(1, MinimumNearbyPlayers))
    {
        PlayersOutsideSinceTime = -1.0;
        return;
    }

    const double Now = GetServerTimeSeconds();
    if (PlayersOutsideSinceTime < 0.0)
    {
        PlayersOutsideSinceTime = Now;
        return;
    }

    if (Now - PlayersOutsideSinceTime >= FMath::Max(0.0, static_cast<double>(DeactivationGracePeriod)))
    {
        DeactivateSpawnerInternal();
    }
}

int32 ADMFWildDigimonSpawner::CountNearbyPlayers(const float Radius) const
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return 0;
    }

    const FVector Origin = GetActorLocation();
    const float RadiusSq = FMath::Square(FMath::Max(0.0f, Radius));
    int32 Count = 0;

    for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
    {
        const APlayerController* PlayerController = It->Get();
        const APawn* Pawn = PlayerController ? PlayerController->GetPawn() : nullptr;
        if (!IsValid(Pawn))
        {
            continue;
        }

        const float DistSq = bUse2DPlayerDistance
            ? FVector::DistSquared2D(Origin, Pawn->GetActorLocation())
            : FVector::DistSquared(Origin, Pawn->GetActorLocation());
        if (DistSq <= RadiusSq)
        {
            ++Count;
        }
    }
    return Count;
}

bool ADMFWildDigimonSpawner::IsSpawnLocationTooCloseToPlayer(const FVector& Location) const
{
    if (MinimumSpawnDistanceFromPlayers <= 0.0f)
    {
        return false;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        return false;
    }

    const float MinDistSq = FMath::Square(MinimumSpawnDistanceFromPlayers);
    for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
    {
        const APlayerController* PlayerController = It->Get();
        const APawn* Pawn = PlayerController ? PlayerController->GetPawn() : nullptr;
        if (IsValid(Pawn) && FVector::DistSquared(Location, Pawn->GetActorLocation()) < MinDistSq)
        {
            return true;
        }
    }
    return false;
}

ADMFDayNightSky* ADMFWildDigimonSpawner::ResolveDayNightSky()
{
    if (PopulationScheduleMode != EDMFWildPopulationScheduleMode::DayNight)
    {
        return nullptr;
    }

    if (IsValid(DayNightSkyOverride))
    {
        CachedDayNightSky = DayNightSkyOverride;
        return DayNightSkyOverride;
    }
    if (CachedDayNightSky.IsValid())
    {
        return CachedDayNightSky.Get();
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        return nullptr;
    }
    for (TActorIterator<ADMFDayNightSky> It(World); It; ++It)
    {
        if (IsValid(*It))
        {
            CachedDayNightSky = *It;
            return *It;
        }
    }
    return nullptr;
}

bool ADMFWildDigimonSpawner::IsUsingLegacyFallbackForActivePhase() const
{
    if (PopulationScheduleMode != EDMFWildPopulationScheduleMode::DayNight || !bFallbackToLegacyPopulationWhenPhaseTableEmpty)
    {
        return PopulationScheduleMode != EDMFWildPopulationScheduleMode::DayNight;
    }
    return ReplicatedPopulationPhase == EDMFDayNightPhase::Day ? DaySpawnEntries.IsEmpty() : NightSpawnEntries.IsEmpty();
}

const TArray<FDMFWildSpawnEntry>& ADMFWildDigimonSpawner::GetActiveSpawnEntries() const
{
    if (PopulationScheduleMode != EDMFWildPopulationScheduleMode::DayNight || IsUsingLegacyFallbackForActivePhase())
    {
        return SpawnEntries;
    }
    return ReplicatedPopulationPhase == EDMFDayNightPhase::Day ? DaySpawnEntries : NightSpawnEntries;
}

const FDMFWildSpawnRarityWeights& ADMFWildDigimonSpawner::GetActiveRarityWeights() const
{
    if (PopulationScheduleMode != EDMFWildPopulationScheduleMode::DayNight || IsUsingLegacyFallbackForActivePhase())
    {
        return RarityWeights;
    }
    return ReplicatedPopulationPhase == EDMFDayNightPhase::Day ? DayRarityWeights : NightRarityWeights;
}

bool ADMFWildDigimonSpawner::ShouldRecordCountForCurrentPopulation(const FManagedWildRecord& Record) const
{
    return PopulationScheduleMode != EDMFWildPopulationScheduleMode::DayNight || Record.SpawnPhase == ReplicatedPopulationPhase;
}

int32 ADMFWildDigimonSpawner::RollTargetPopulationForActiveSet() const
{
    const int32 MinCount = FMath::Max(0, MinimumSpawnCount);
    const int32 MaxCount = FMath::Max(MinCount, MaximumSpawnCount);
    int32 Target = FMath::RandRange(MinCount, MaxCount);
    const int32 ConfiguredCapacity = ComputeConfiguredPopulationCapacity();
    if (ConfiguredCapacity >= 0)
    {
        Target = FMath::Min(Target, ConfiguredCapacity);
    }
    return Target;
}

void ADMFWildDigimonSpawner::RefreshDayNightPopulationPhase()
{
    if (!HasAuthority())
    {
        return;
    }

    EDMFDayNightPhase NewPhase = EDMFDayNightPhase::Day;
    if (PopulationScheduleMode == EDMFWildPopulationScheduleMode::DayNight)
    {
        if (ADMFDayNightSky* Sky = ResolveDayNightSky())
        {
            bWarnedMissingDayNightSky = false;
            NewPhase = Sky->GetDayNightPhase();
        }
        else
        {
            if (!bWarnedMissingDayNightSky)
            {
                bWarnedMissingDayNightSky = true;
                UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Wild spawner %s is configured for Day/Night populations but could not resolve DMFDayNightSky. Using the configured missing-sky fallback phase until a sky becomes available."), *GetName());
            }
            NewPhase = bTreatMissingDayNightSkyAsDay ? EDMFDayNightPhase::Day : EDMFDayNightPhase::Night;
        }
    }

    const EDMFDayNightPhase PreviousPhase = ReplicatedPopulationPhase;
    const bool bWasInitialized = bAuthorityPopulationPhaseInitialized;
    bAuthorityPopulationPhaseInitialized = true;
    if (PreviousPhase == NewPhase && bWasInitialized)
    {
        return;
    }

    ReplicatedPopulationPhase = NewPhase;
    ForceNetUpdate();
    if (PreviousPhase != NewPhase)
    {
        BP_OnPopulationPhaseChanged(NewPhase, PreviousPhase);
    }

    if (bWasInitialized && PreviousPhase != NewPhase && bSpawnerActive)
    {
        HandlePopulationPhaseTransition(PreviousPhase, NewPhase);
    }
}

void ADMFWildDigimonSpawner::HandlePopulationPhaseTransition(const EDMFDayNightPhase PreviousPhase, const EDMFDayNightPhase NewPhase)
{
    if (!HasAuthority() || PopulationScheduleMode != EDMFWildPopulationScheduleMode::DayNight)
    {
        return;
    }

    PendingInitialSpawns = 0;
    PendingRespawnReadyTimes.Reset();
    ReplicatedTargetPopulation = RollTargetPopulationForActiveSet();

    // If an unusually long encounter survived an entire opposite phase and this phase has returned,
    // let that still-valid actor rejoin its own population contract instead of remaining permanently suppress-respawn.
    for (FManagedWildRecord& Record : ManagedWild)
    {
        if (Record.SpawnPhase == NewPhase && Record.Actor.IsValid() && !Record.bDefeated && !Record.bPendingSpawnerDespawn)
        {
            Record.bSuppressRespawn = false;
        }
    }

    if (bRetirePreviousPopulationOnPhaseChange)
    {
        TArray<TWeakObjectPtr<ADMFWildDigimonCharacter>> ActorsToRetire;
        for (FManagedWildRecord& Record : ManagedWild)
        {
            ADMFWildDigimonCharacter* Wild = Record.Actor.Get();
            if (!IsValid(Wild) || Record.SpawnPhase == NewPhase || Record.bDefeated || Record.bPendingSpawnerDespawn)
            {
                continue;
            }

            Record.bSuppressRespawn = true;
            const bool bEngaged = Wild->CombatComponent && Wild->CombatComponent->IsBattleEncounterActive();
            if (bKeepEngagedWildUntilCombatEnds && bEngaged)
            {
                continue;
            }

            Record.bPendingSpawnerDespawn = true;
            ActorsToRetire.Add(Wild);
        }

        for (const TWeakObjectPtr<ADMFWildDigimonCharacter>& WeakWild : ActorsToRetire)
        {
            if (ADMFWildDigimonCharacter* Wild = WeakWild.Get())
            {
                if (bUseGroundDespawnWhenInactive)
                {
                    Wild->BeginGroundDespawn(Wild->GroundEmergenceDepth, GroundDespawnDuration);
                }
                else
                {
                    Wild->Destroy();
                }
            }
        }
    }
    else
    {
        // Old-phase actors may remain naturally, but they never consume new-phase capacity or schedule replacements.
        for (FManagedWildRecord& Record : ManagedWild)
        {
            if (Record.SpawnPhase != NewPhase)
            {
                Record.bSuppressRespawn = true;
            }
        }
    }

    PendingInitialSpawns = FMath::Max(0, ReplicatedTargetPopulation - CountAliveManagedWild());
    UpdateReplicatedRuntimeState();
    if (PendingInitialSpawns > 0)
    {
        SchedulePopulationProcessing(FMath::Max(0.05f, PopulationSpawnInterval));
    }

    UE_LOG(LogDigimonMMOFramework, Log, TEXT("Wild spawner %s swapped population phase %s -> %s; target %d, active entries %d."),
        *GetName(),
        PreviousPhase == EDMFDayNightPhase::Day ? TEXT("Day") : TEXT("Night"),
        NewPhase == EDMFDayNightPhase::Day ? TEXT("Day") : TEXT("Night"),
        ReplicatedTargetPopulation,
        GetActiveSpawnEntries().Num());
}

void ADMFWildDigimonSpawner::RetireInactivePhaseWild()
{
    if (!HasAuthority() || PopulationScheduleMode != EDMFWildPopulationScheduleMode::DayNight || !bRetirePreviousPopulationOnPhaseChange)
    {
        return;
    }

    TArray<TWeakObjectPtr<ADMFWildDigimonCharacter>> ActorsToRetire;
    for (FManagedWildRecord& Record : ManagedWild)
    {
        ADMFWildDigimonCharacter* Wild = Record.Actor.Get();
        if (!IsValid(Wild) || Record.SpawnPhase == ReplicatedPopulationPhase || Record.bDefeated || Record.bPendingSpawnerDespawn)
        {
            continue;
        }

        Record.bSuppressRespawn = true;
        if (bKeepEngagedWildUntilCombatEnds && Wild->CombatComponent && Wild->CombatComponent->IsBattleEncounterActive())
        {
            continue;
        }

        Record.bPendingSpawnerDespawn = true;
        ActorsToRetire.Add(Wild);
    }

    for (const TWeakObjectPtr<ADMFWildDigimonCharacter>& WeakWild : ActorsToRetire)
    {
        if (ADMFWildDigimonCharacter* Wild = WeakWild.Get())
        {
            if (bUseGroundDespawnWhenInactive)
            {
                Wild->BeginGroundDespawn(Wild->GroundEmergenceDepth, GroundDespawnDuration);
            }
            else
            {
                Wild->Destroy();
            }
        }
    }
}

void ADMFWildDigimonSpawner::ActivateSpawnerInternal()
{
    if (!HasAuthority() || bSpawnerActive || !bSpawnerEnabled)
    {
        return;
    }

    bSpawnerActive = true;
    PlayersOutsideSinceTime = -1.0;
    ReplicatedTargetPopulation = RollTargetPopulationForActiveSet();
    PendingInitialSpawns = FMath::Max(0, ReplicatedTargetPopulation - CountAliveManagedWild());
    PendingRespawnReadyTimes.Reset();
    if (ReplicatedTargetPopulation <= 0 && MaximumSpawnCount > 0)
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Wild spawner %s activated with no eligible spawn-table capacity. Check enabled entries, classes, species references, rarity weights and live caps."), *GetName());
    }
    UpdateReplicatedRuntimeState();
    UE_LOG(LogDigimonMMOFramework, Log, TEXT("Wild spawner %s activated: target population %d, configured active entries %d, phase %s."), *GetName(), ReplicatedTargetPopulation, GetActiveSpawnEntries().Num(), ReplicatedPopulationPhase == EDMFDayNightPhase::Day ? TEXT("Day") : TEXT("Night"));
    SchedulePopulationProcessing(0.05f);
}

void ADMFWildDigimonSpawner::DeactivateSpawnerInternal()
{
    if (!HasAuthority())
    {
        return;
    }

    bSpawnerActive = false;
    PlayersOutsideSinceTime = -1.0;
    ReplicatedTargetPopulation = 0;
    PendingInitialSpawns = 0;
    PendingRespawnReadyTimes.Reset();

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(PopulationTimer);
    }

    TArray<TWeakObjectPtr<ADMFWildDigimonCharacter>> ActorsToUnload;
    ActorsToUnload.Reserve(ManagedWild.Num());
    for (FManagedWildRecord& Record : ManagedWild)
    {
        if (Record.Actor.IsValid())
        {
            Record.bPendingSpawnerDespawn = true;
            Record.bSuppressRespawn = true;
            ActorsToUnload.Add(Record.Actor);
        }
    }

    // Destruction can synchronously fire OnDestroyed and mutate ManagedWild, so do it only after
    // the record-marking pass has completed.
    for (const TWeakObjectPtr<ADMFWildDigimonCharacter>& WeakWild : ActorsToUnload)
    {
        ADMFWildDigimonCharacter* Wild = WeakWild.Get();
        if (!IsValid(Wild))
        {
            continue;
        }

        const int32 RecordIndex = FindManagedRecordIndex(Wild);
        const bool bWasDefeated = ManagedWild.IsValidIndex(RecordIndex) && ManagedWild[RecordIndex].bDefeated;
        if (bUseGroundDespawnWhenInactive && !bWasDefeated)
        {
            Wild->BeginGroundDespawn(Wild->GroundEmergenceDepth, GroundDespawnDuration);
        }
        else
        {
            Wild->Destroy();
        }
    }

    UpdateReplicatedRuntimeState();
}

void ADMFWildDigimonSpawner::SchedulePopulationProcessing(const float DelaySeconds)
{
    if (!HasAuthority() || !bSpawnerActive || !GetWorld())
    {
        return;
    }

    FTimerManager& TimerManager = GetWorld()->GetTimerManager();
    const float Delay = FMath::Max(0.01f, DelaySeconds);
    if (TimerManager.IsTimerActive(PopulationTimer))
    {
        const float Remaining = TimerManager.GetTimerRemaining(PopulationTimer);
        if (Remaining >= 0.0f && Remaining <= Delay)
        {
            return;
        }
    }
    TimerManager.SetTimer(PopulationTimer, this, &ADMFWildDigimonSpawner::ProcessPopulationQueue, Delay, false);
}

void ADMFWildDigimonSpawner::ProcessPopulationQueue()
{
    if (!HasAuthority() || !bSpawnerActive)
    {
        return;
    }

    CleanupInvalidManagedWild();
    const int32 Alive = CountAliveManagedWild();
    if (Alive >= ReplicatedTargetPopulation)
    {
        PendingInitialSpawns = 0;
        PendingRespawnReadyTimes.Reset();
        UpdateReplicatedRuntimeState();
        return;
    }

    const double Now = GetServerTimeSeconds();
    bool bHasSpawnToken = false;
    int32 ReadyRespawnIndex = INDEX_NONE;

    if (PendingInitialSpawns > 0)
    {
        bHasSpawnToken = true;
    }
    else
    {
        double EarliestFuture = TNumericLimits<double>::Max();
        for (int32 Index = 0; Index < PendingRespawnReadyTimes.Num(); ++Index)
        {
            const double ReadyTime = PendingRespawnReadyTimes[Index];
            if (ReadyTime <= Now)
            {
                ReadyRespawnIndex = Index;
                bHasSpawnToken = true;
                break;
            }
            EarliestFuture = FMath::Min(EarliestFuture, ReadyTime);
        }

        if (!bHasSpawnToken && EarliestFuture < TNumericLimits<double>::Max())
        {
            SchedulePopulationProcessing(static_cast<float>(FMath::Max(0.01, EarliestFuture - Now)));
            return;
        }
    }

    if (!bHasSpawnToken)
    {
        // Defensive self-heal if the live population changed outside the normal callbacks.
        PendingInitialSpawns = FMath::Max(0, ReplicatedTargetPopulation - Alive);
        if (PendingInitialSpawns <= 0)
        {
            return;
        }
    }

    ADMFWildDigimonCharacter* Spawned = SpawnOneWildDigimon();
    if (Spawned)
    {
        if (PendingInitialSpawns > 0)
        {
            --PendingInitialSpawns;
        }
        else if (ReadyRespawnIndex != INDEX_NONE && PendingRespawnReadyTimes.IsValidIndex(ReadyRespawnIndex))
        {
            PendingRespawnReadyTimes.RemoveAtSwap(ReadyRespawnIndex);
        }
    }

    UpdateReplicatedRuntimeState();

    if (CountAliveManagedWild() < ReplicatedTargetPopulation)
    {
        SchedulePopulationProcessing(Spawned ? FMath::Max(0.05f, PopulationSpawnInterval) : 1.0f);
    }
}

void ADMFWildDigimonSpawner::QueueReplacementSpawn()
{
    if (!HasAuthority() || !bSpawnerActive)
    {
        return;
    }

    const float MinDelay = FMath::Max(0.0f, MinimumRespawnDelay);
    const float MaxDelay = FMath::Max(MinDelay, MaximumRespawnDelay);
    const double ReadyTime = GetServerTimeSeconds() + static_cast<double>(FMath::FRandRange(MinDelay, MaxDelay));
    PendingRespawnReadyTimes.Add(ReadyTime);
    SchedulePopulationProcessing(static_cast<float>(FMath::Max(0.01, ReadyTime - GetServerTimeSeconds())));
}

ADMFWildDigimonCharacter* ADMFWildDigimonSpawner::SpawnOneWildDigimon()
{
    if (!HasAuthority() || !bSpawnerActive || CountAliveManagedWild() >= ReplicatedTargetPopulation)
    {
        return nullptr;
    }

    const TArray<FDMFWildSpawnEntry>& ActiveEntries = GetActiveSpawnEntries();
    const int32 EntryIndex = SelectWeightedSpawnEntryIndex();
    if (!ActiveEntries.IsValidIndex(EntryIndex))
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Wild spawner %s has no eligible spawn entry. Check Enabled, Species, Wild Character Class, rarity weight/multiplier, and Max Alive caps."), *GetName());
        return nullptr;
    }

    const int32 Attempts = FMath::Max(1, MaxPlacementAttemptsPerSpawn);
    for (int32 Attempt = 0; Attempt < Attempts; ++Attempt)
    {
        FTransform SpawnTransform;
        if (!FindSpawnTransform(EntryIndex, SpawnTransform))
        {
            continue;
        }

        if (ADMFWildDigimonCharacter* Spawned = SpawnEntryAtTransform(EntryIndex, SpawnTransform))
        {
            return Spawned;
        }
    }
    UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Wild spawner %s could not spawn entry %d after %d attempts. Check ground collision on channel %d, NavMesh coverage when Require Navigable Spawn is enabled, minimum player distance, and nearby blocking geometry."), *GetName(), EntryIndex, Attempts, static_cast<int32>(GroundTraceChannel.GetValue()));
    return nullptr;
}

int32 ADMFWildDigimonSpawner::SelectWeightedSpawnEntryIndex() const
{
    /**
     * Selection is intentionally two-stage.
     *
     * 1) Roll the rarity tier from the spawner's rarity weights.
     * 2) Roll one currently eligible entry inside that tier from its SelectionWeightMultiplier.
     *
     * The old implementation multiplied the rarity weight into every entry and then rolled the
     * entire table in one pass. That made a rarity tier more likely merely because designers added
     * more species to it (for example six Uncommon entries received six copies of the Uncommon
     * base weight). Rarity is a tier-level probability and must therefore be independent of the
     * number of species authored inside that tier.
     */
    struct FEligibleRarityBucket
    {
        EDMFWildSpawnRarity Rarity = EDMFWildSpawnRarity::Common;
        float RarityWeight = 0.0f;
        float TotalEntryWeight = 0.0f;
        TArray<TPair<int32, float>> Entries;
    };

    TArray<FEligibleRarityBucket> Buckets;
    const TArray<FDMFWildSpawnEntry>& ActiveEntries = GetActiveSpawnEntries();
    const FDMFWildSpawnRarityWeights& ActiveRarityWeights = GetActiveRarityWeights();

    for (int32 Index = 0; Index < ActiveEntries.Num(); ++Index)
    {
        const FDMFWildSpawnEntry& Entry = ActiveEntries[Index];
        if (!Entry.bEnabled || Entry.Species.IsNull() || !Entry.WildCharacterClass)
        {
            continue;
        }

        if (Entry.MaxAliveFromEntry > 0 && CountAliveForEntry(Index) >= Entry.MaxAliveFromEntry)
        {
            continue;
        }

        const float RarityWeight = ActiveRarityWeights.GetWeight(Entry.Rarity);
        const float EntryWeight = FMath::Max(0.0f, Entry.SelectionWeightMultiplier);
        if (RarityWeight <= 0.0f || EntryWeight <= 0.0f)
        {
            continue;
        }

        FEligibleRarityBucket* Bucket = Buckets.FindByPredicate([&Entry](const FEligibleRarityBucket& Existing)
        {
            return Existing.Rarity == Entry.Rarity;
        });

        if (!Bucket)
        {
            FEligibleRarityBucket& NewBucket = Buckets.AddDefaulted_GetRef();
            NewBucket.Rarity = Entry.Rarity;
            NewBucket.RarityWeight = RarityWeight;
            Bucket = &NewBucket;
        }

        Bucket->Entries.Emplace(Index, EntryWeight);
        Bucket->TotalEntryWeight += EntryWeight;
    }

    float TotalRarityWeight = 0.0f;
    for (const FEligibleRarityBucket& Bucket : Buckets)
    {
        if (Bucket.Entries.Num() > 0 && Bucket.TotalEntryWeight > 0.0f)
        {
            TotalRarityWeight += Bucket.RarityWeight;
        }
    }

    if (TotalRarityWeight <= 0.0f || Buckets.Num() == 0)
    {
        return INDEX_NONE;
    }

    const FEligibleRarityBucket* SelectedBucket = nullptr;
    float RarityRoll = FMath::FRand() * TotalRarityWeight;
    for (const FEligibleRarityBucket& Bucket : Buckets)
    {
        if (Bucket.Entries.Num() == 0 || Bucket.TotalEntryWeight <= 0.0f)
        {
            continue;
        }

        RarityRoll -= Bucket.RarityWeight;
        if (RarityRoll < 0.0f)
        {
            SelectedBucket = &Bucket;
            break;
        }
    }

    // Floating-point safety only; a valid roll should always select one eligible bucket.
    if (!SelectedBucket)
    {
        for (int32 BucketIndex = Buckets.Num() - 1; BucketIndex >= 0; --BucketIndex)
        {
            if (Buckets[BucketIndex].Entries.Num() > 0 && Buckets[BucketIndex].TotalEntryWeight > 0.0f)
            {
                SelectedBucket = &Buckets[BucketIndex];
                break;
            }
        }
    }

    if (!SelectedBucket)
    {
        return INDEX_NONE;
    }

    float EntryRoll = FMath::FRand() * SelectedBucket->TotalEntryWeight;
    for (const TPair<int32, float>& Candidate : SelectedBucket->Entries)
    {
        EntryRoll -= Candidate.Value;
        if (EntryRoll < 0.0f)
        {
            return Candidate.Key;
        }
    }

    return SelectedBucket->Entries.Last().Key;
}

int32 ADMFWildDigimonSpawner::ComputeConfiguredPopulationCapacity() const
{
    const TArray<FDMFWildSpawnEntry>& ActiveEntries = GetActiveSpawnEntries();
    const FDMFWildSpawnRarityWeights& ActiveRarityWeights = GetActiveRarityWeights();
    int32 Capacity = 0;
    bool bHasEligibleEntry = false;
    for (const FDMFWildSpawnEntry& Entry : ActiveEntries)
    {
        const float RarityWeight = ActiveRarityWeights.GetWeight(Entry.Rarity);
        const float EntryWeight = FMath::Max(0.0f, Entry.SelectionWeightMultiplier);
        if (!Entry.bEnabled || Entry.Species.IsNull() || !Entry.WildCharacterClass || RarityWeight <= 0.0f || EntryWeight <= 0.0f)
        {
            continue;
        }

        bHasEligibleEntry = true;
        if (Entry.MaxAliveFromEntry <= 0)
        {
            return -1; // Unlimited by entry caps; the spawner's MaximumSpawnCount remains the bound.
        }
        Capacity += Entry.MaxAliveFromEntry;
    }
    return bHasEligibleEntry ? Capacity : 0;
}

float ADMFWildDigimonSpawner::GetSpawnCapsuleHalfHeight(const int32 EntryIndex) const
{
    const TArray<FDMFWildSpawnEntry>& ActiveEntries = GetActiveSpawnEntries();
    if (!ActiveEntries.IsValidIndex(EntryIndex) || !ActiveEntries[EntryIndex].WildCharacterClass)
    {
        return 0.0f;
    }

    const UClass* WildClass = ActiveEntries[EntryIndex].WildCharacterClass.Get();
    const ADMFWildDigimonCharacter* WildCDO = WildClass ? WildClass->GetDefaultObject<ADMFWildDigimonCharacter>() : nullptr;
    const UCapsuleComponent* Capsule = WildCDO ? WildCDO->GetCapsuleComponent() : nullptr;
    return Capsule ? FMath::Max(0.0f, Capsule->GetScaledCapsuleHalfHeight()) : 0.0f;
}

bool ADMFWildDigimonSpawner::FindSpawnTransform(const int32 EntryIndex, FTransform& OutTransform) const
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return false;
    }

    const float Radius = FMath::Max(0.0f, SpawnRadius);
    const float Angle = FMath::FRandRange(0.0f, (2.0f * PI));
    const float Distance = FMath::Sqrt(FMath::FRand()) * Radius;
    const FVector Origin = GetActorLocation();
    FVector Candidate(Origin.X + FMath::Cos(Angle) * Distance, Origin.Y + FMath::Sin(Angle) * Distance, Origin.Z);

    const FVector TraceStart(Candidate.X, Candidate.Y, Origin.Z + FMath::Max(0.0f, GroundTraceHeight));
    const FVector TraceEnd(Candidate.X, Candidate.Y, Origin.Z - FMath::Max(0.0f, GroundTraceDepth));
    FHitResult Hit;
    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(DMFWildSpawnerGround), false, this);
    for (const FManagedWildRecord& Record : ManagedWild)
    {
        if (AActor* ManagedActor = Record.Actor.Get())
        {
            QueryParams.AddIgnoredActor(ManagedActor);
        }
    }
    for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
    {
        if (const APlayerController* PlayerController = It->Get())
        {
            if (APawn* PlayerPawn = PlayerController->GetPawn())
            {
                QueryParams.AddIgnoredActor(PlayerPawn);
            }
        }
    }
    if (!World->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, GroundTraceChannel, QueryParams))
    {
        return false;
    }

    // Hit.ImpactPoint (and ProjectPointToNavigation below) represent the FLOOR surface.
    // ACharacter's actor origin, however, is the CENTER of its capsule. v0.4.0 incorrectly
    // spawned the actor origin directly on the floor, embedding roughly half the capsule into
    // terrain and allowing AdjustIfPossibleButDontSpawnIfColliding to reject every spawn.
    Candidate = Hit.ImpactPoint;

    if (bRequireNavigableSpawn)
    {
        UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);
        FNavLocation NavLocation;
        FSharedConstNavQueryFilter QueryFilter;
        if (!NavSystem || !NavSystem->ProjectPointToNavigation(Candidate, NavLocation, NavigationProjectionExtent, static_cast<const ANavigationData*>(nullptr), QueryFilter))
        {
            return false;
        }
        Candidate = NavLocation.Location;
    }

    // Place the bottom of THIS selected Blueprint class's capsule on the resolved floor.
    // Using the class default object respects per-species capsule sizes set in BP_Wild_<Species>.
    const float CapsuleHalfHeight = GetSpawnCapsuleHalfHeight(EntryIndex);
    Candidate.Z += CapsuleHalfHeight + SpawnGroundOffset;

    if (IsSpawnLocationTooCloseToPlayer(Candidate))
    {
        return false;
    }

    OutTransform = FTransform(FRotator(0.0f, FMath::FRandRange(-180.0f, 180.0f), 0.0f), Candidate, FVector::OneVector);
    return true;
}

ADMFWildDigimonCharacter* ADMFWildDigimonSpawner::SpawnEntryAtTransform(const int32 EntryIndex, const FTransform& SpawnTransform)
{
    const TArray<FDMFWildSpawnEntry>& ActiveEntries = GetActiveSpawnEntries();
    if (!ActiveEntries.IsValidIndex(EntryIndex) || !GetWorld())
    {
        return nullptr;
    }

    const FDMFWildSpawnEntry& Entry = ActiveEntries[EntryIndex];
    if (!Entry.WildCharacterClass || Entry.Species.IsNull())
    {
        return nullptr;
    }

    ADMFWildDigimonCharacter* Wild = GetWorld()->SpawnActorDeferred<ADMFWildDigimonCharacter>(
        Entry.WildCharacterClass,
        SpawnTransform,
        this,
        nullptr,
        ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding,
        ESpawnActorScaleMethod::MultiplyWithRoot);
    if (!Wild)
    {
        return nullptr;
    }

    const int32 MinLevel = FMath::Max(1, Entry.MinimumLevel);
    const int32 MaxLevel = FMath::Max(MinLevel, Entry.MaximumLevel);
    Wild->Species = Entry.Species;
    Wild->Level = FMath::RandRange(MinLevel, MaxLevel);
    Wild->WildCombatTeamId = WildCombatTeamId;

    // Auto-battle resolution is deliberately layered rather than blindly overwriting the Wild BP.
    // 1) The Wild Character Blueprint class default defines the species/variant's normal behavior.
    // 2) A Spawn Entry may explicitly override that class default.
    // 3) The spawner's Allow Proactive Auto Battle switch is a master gate for starting fights.
    const ADMFWildDigimonCharacter* WildClassDefaults = Entry.WildCharacterClass->GetDefaultObject<ADMFWildDigimonCharacter>();
    const bool bClassDefaultAutoBattle = WildClassDefaults ? WildClassDefaults->bAutoBattle : false;
    const bool bClassDefaultRetaliation = WildClassDefaults ? WildClassDefaults->bRetaliateWhenAttacked : true;
    const bool bEntryAutoBattle = Entry.bOverrideAutoBattle ? Entry.bAutoBattleOverride : bClassDefaultAutoBattle;
    Wild->bAutoBattle = bEnableAutoBattle && bEntryAutoBattle;
    Wild->bRetaliateWhenAttacked = bEnableRetaliation && bClassDefaultRetaliation;

    Wild->AggroRange = FMath::Max(0.0f, AggroRange);
    Wild->LeashRange = FMath::Max(Wild->AggroRange, LeashRadius);
    Wild->bEnableFreeRoaming = bEnableFreeRoaming;
    Wild->RoamRadius = FMath::Min(FMath::Max(0.0f, RoamRadius), Wild->LeashRange);
    Wild->MinimumRoamDelay = FMath::Max(0.05f, MinimumRoamDelay);
    Wild->MaximumRoamDelay = FMath::Max(Wild->MinimumRoamDelay, MaximumRoamDelay);
    Wild->RoamAcceptanceRadius = FMath::Max(0.0f, RoamAcceptanceRadius);
    Wild->bSpawnerManaged = true;
    Wild->SpawnRarity = Entry.Rarity;
    Wild->SpawnHomeLocation = SpawnTransform.GetLocation();
    Wild->bStartWithGroundEmergence = bUseGroundEmergence;
    const float EffectiveEmergenceDepth = Entry.bOverrideGroundEmergence ? Entry.GroundEmergenceDepthOverride : GroundEmergenceDepth;
    const float EffectiveEmergenceDuration = Entry.bOverrideGroundEmergence ? Entry.GroundEmergenceDurationOverride : GroundEmergenceDuration;
    Wild->GroundEmergenceDepth = FMath::Max(0.0f, EffectiveEmergenceDepth);
    Wild->GroundEmergenceDuration = FMath::Max(0.05f, EffectiveEmergenceDuration);

    UGameplayStatics::FinishSpawningActor(Wild, SpawnTransform);
    if (!IsValid(Wild))
    {
        return nullptr;
    }
    if (!Wild->SpeciesId.IsValid())
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Wild spawner %s rejected spawned class %s because its Species failed authoritative initialization."), *GetName(), *GetNameSafe(Entry.WildCharacterClass.Get()));
        Wild->Destroy();
        return nullptr;
    }

    FManagedWildRecord& Record = ManagedWild.AddDefaulted_GetRef();
    Record.Actor = Wild;
    Record.EntryIndex = EntryIndex;
    Record.SpawnPhase = ReplicatedPopulationPhase;
    Wild->OnDestroyed.AddDynamic(this, &ADMFWildDigimonSpawner::HandleManagedWildDestroyed);
    if (Wild->CombatComponent)
    {
        Wild->CombatComponent->OnDefeated.AddDynamic(this, &ADMFWildDigimonSpawner::HandleManagedWildDefeated);
    }

    UpdateReplicatedRuntimeState();
    UE_LOG(LogDigimonMMOFramework, Log, TEXT("Wild spawner %s spawned %s from entry %s at %s (Level %d, Rarity %d)."), *GetName(), *GetNameSafe(Wild), *Entry.EntryId.ToString(), *SpawnTransform.GetLocation().ToCompactString(), Wild->Level, static_cast<int32>(Entry.Rarity));
    BP_OnWildDigimonSpawned(Wild, Entry.EntryId, Entry.Rarity);
    return Wild;
}

void ADMFWildDigimonSpawner::HandleManagedWildDefeated(ADMFDigimonCharacter* DefeatedDigimon, ADMFDigimonCharacter* Killer)
{
    (void)Killer;
    if (!HasAuthority())
    {
        return;
    }

    ADMFWildDigimonCharacter* Wild = Cast<ADMFWildDigimonCharacter>(DefeatedDigimon);
    const int32 RecordIndex = FindManagedRecordIndex(Wild);
    if (!ManagedWild.IsValidIndex(RecordIndex) || ManagedWild[RecordIndex].bDefeated)
    {
        return;
    }

    const bool bShouldReplace = ShouldRecordCountForCurrentPopulation(ManagedWild[RecordIndex]);
    ManagedWild[RecordIndex].bDefeated = true;
    UpdateReplicatedRuntimeState();
    if (bShouldReplace)
    {
        QueueReplacementSpawn();
    }

    if (!GetWorld() || !IsValid(Wild))
    {
        return;
    }

    TWeakObjectPtr<ADMFWildDigimonCharacter> WeakWild(Wild);
    FTimerHandle DefeatedTimer;
    GetWorld()->GetTimerManager().SetTimer(DefeatedTimer, FTimerDelegate::CreateLambda([WeakWild]()
    {
        if (WeakWild.IsValid())
        {
            WeakWild->Destroy();
        }
    }), FMath::Max(0.01f, DefeatedDespawnDelay), false);
}

void ADMFWildDigimonSpawner::HandleManagedWildDestroyed(AActor* DestroyedActor)
{
    if (!HasAuthority())
    {
        return;
    }

    ADMFWildDigimonCharacter* Wild = Cast<ADMFWildDigimonCharacter>(DestroyedActor);
    const int32 RecordIndex = FindManagedRecordIndex(Wild);
    if (!ManagedWild.IsValidIndex(RecordIndex))
    {
        return;
    }

    const FManagedWildRecord Removed = ManagedWild[RecordIndex];
    ManagedWild.RemoveAtSwap(RecordIndex);
    if (bSpawnerActive && !Removed.bSuppressRespawn && !Removed.bDefeated && ShouldRecordCountForCurrentPopulation(Removed))
    {
        QueueReplacementSpawn();
    }
    UpdateReplicatedRuntimeState();
}

void ADMFWildDigimonSpawner::CleanupInvalidManagedWild()
{
    for (int32 Index = ManagedWild.Num() - 1; Index >= 0; --Index)
    {
        if (!ManagedWild[Index].Actor.IsValid())
        {
            const bool bShouldReplace = bSpawnerActive && !ManagedWild[Index].bSuppressRespawn && !ManagedWild[Index].bDefeated && ShouldRecordCountForCurrentPopulation(ManagedWild[Index]);
            ManagedWild.RemoveAtSwap(Index);
            if (bShouldReplace)
            {
                QueueReplacementSpawn();
            }
        }
    }
    UpdateReplicatedRuntimeState();
}

int32 ADMFWildDigimonSpawner::CountAliveManagedWild() const
{
    int32 Count = 0;
    for (const FManagedWildRecord& Record : ManagedWild)
    {
        if (ShouldRecordCountForCurrentPopulation(Record) && Record.Actor.IsValid() && !Record.bDefeated && !Record.bPendingSpawnerDespawn)
        {
            ++Count;
        }
    }
    return Count;
}

int32 ADMFWildDigimonSpawner::CountAliveForEntry(const int32 EntryIndex) const
{
    int32 Count = 0;
    for (const FManagedWildRecord& Record : ManagedWild)
    {
        if (ShouldRecordCountForCurrentPopulation(Record) && Record.EntryIndex == EntryIndex && Record.Actor.IsValid() && !Record.bDefeated && !Record.bPendingSpawnerDespawn)
        {
            ++Count;
        }
    }
    return Count;
}

int32 ADMFWildDigimonSpawner::FindManagedRecordIndex(const ADMFWildDigimonCharacter* Wild) const
{
    if (!Wild)
    {
        return INDEX_NONE;
    }

    for (int32 Index = 0; Index < ManagedWild.Num(); ++Index)
    {
        if (ManagedWild[Index].Actor.Get() == Wild)
        {
            return Index;
        }
    }
    return INDEX_NONE;
}

void ADMFWildDigimonSpawner::UpdateReplicatedRuntimeState()
{
    if (!HasAuthority())
    {
        return;
    }

    ReplicatedAliveCount = CountAliveManagedWild();
    const bool bStateChanged = bLastNotifiedActive != bSpawnerActive
        || LastNotifiedAliveCount != ReplicatedAliveCount
        || LastNotifiedTargetPopulation != ReplicatedTargetPopulation;
    if (!bStateChanged)
    {
        return;
    }

    bLastNotifiedActive = bSpawnerActive;
    LastNotifiedAliveCount = ReplicatedAliveCount;
    LastNotifiedTargetPopulation = ReplicatedTargetPopulation;
    ForceNetUpdate();
    BP_OnSpawnerStateChanged(bSpawnerActive, ReplicatedAliveCount, ReplicatedTargetPopulation);
}

void ADMFWildDigimonSpawner::OnRep_SpawnerState()
{
    BP_OnSpawnerStateChanged(bSpawnerActive, ReplicatedAliveCount, ReplicatedTargetPopulation);
}

void ADMFWildDigimonSpawner::OnRep_PopulationPhase(const EDMFDayNightPhase PreviousPhase)
{
    if (PreviousPhase != ReplicatedPopulationPhase)
    {
        BP_OnPopulationPhaseChanged(ReplicatedPopulationPhase, PreviousPhase);
    }
}

double ADMFWildDigimonSpawner::GetServerTimeSeconds() const
{
    if (const UWorld* World = GetWorld())
    {
        if (const AGameStateBase* GameState = World->GetGameState())
        {
            return GameState->GetServerWorldTimeSeconds();
        }
        return static_cast<double>(World->GetTimeSeconds());
    }
    return 0.0;
}
