#include "Game/DMFWildDigimonCharacter.h"

#include "AIController.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Components/CapsuleComponent.h"
#include "Data/DMFDigimonAbilityData.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/GameStateBase.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"

ADMFWildDigimonCharacter::ADMFWildDigimonCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = false;
}

void ADMFWildDigimonCharacter::BeginPlay()
{
    Super::BeginPlay();
    CacheBaseMeshRelativeLocation();

    if (!bSpawnerManaged)
    {
        SpawnHomeLocation = GetActorLocation();
    }

    if (HasAuthority())
    {
        InitializeWildDigimon();
        if (bStartWithGroundEmergence)
        {
            BeginGroundEmergence(GroundEmergenceDepth, GroundEmergenceDuration);
        }
        else
        {
            ScheduleNextRoam();
        }
    }
}

void ADMFWildDigimonCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(RoamTimer);
    }
    Super::EndPlay(EndPlayReason);
}

void ADMFWildDigimonCharacter::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (GroundTransitionState.Mode == EDMFWildGroundTransitionMode::None)
    {
        SetActorTickEnabled(false);
        return;
    }

    ApplyGroundTransitionVisual();

    const double Duration = FMath::Max(0.01, static_cast<double>(GroundTransitionState.Duration));
    if (HasAuthority() && GetSynchronizedServerTimeSeconds() - GroundTransitionState.StartServerTimeSeconds >= Duration)
    {
        FinishGroundTransitionIfAuthority();
    }
}

void ADMFWildDigimonCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFWildDigimonCharacter, bSpawnerManaged);
    DOREPLIFETIME(ADMFWildDigimonCharacter, bAutoBattle);
    DOREPLIFETIME(ADMFWildDigimonCharacter, bRetaliateWhenAttacked);
    DOREPLIFETIME(ADMFWildDigimonCharacter, SpawnRarity);
    DOREPLIFETIME(ADMFWildDigimonCharacter, SpawnHomeLocation);
    DOREPLIFETIME(ADMFWildDigimonCharacter, GroundTransitionState);
}

bool ADMFWildDigimonCharacter::InitializeWildDigimon()
{
    if (!HasAuthority())
    {
        return false;
    }

    UDMFDigimonSpeciesData* SpeciesData = Species.LoadSynchronous();
    if (!SpeciesData)
    {
        return false;
    }

    FDMFDigimonInstance Runtime;
    Runtime.InstanceId = FGuid::NewGuid();
    Runtime.SpeciesId = SpeciesData->GetPrimaryAssetId();
    Runtime.Stats = SpeciesData->BaseStats;
    Runtime.Stats.Level = FMath::Max(1, Level);
    const int32 ExtraLevels = FMath::Max(0, Runtime.Stats.Level - FMath::Max(1, SpeciesData->StartingLevel));
    Runtime.Stats.MaxHP += ExtraLevels * SpeciesData->HPPerLevel;
    Runtime.Stats.MaxSP += ExtraLevels * SpeciesData->SPPerLevel;
    Runtime.Stats.Strength += ExtraLevels * SpeciesData->StrengthPerLevel;
    Runtime.Stats.Intelligence += ExtraLevels * SpeciesData->IntelligencePerLevel;
    Runtime.Stats.Defense += ExtraLevels * SpeciesData->DefensePerLevel;
    Runtime.Stats.Speed += ExtraLevels * SpeciesData->SpeedPerLevel;
    Runtime.CurrentHP = Runtime.Stats.MaxHP;
    Runtime.CurrentSP = Runtime.Stats.MaxSP;
    Runtime.EquippedAbilityIds = SpeciesData->StartingAbilityIds;

    for (const TSoftObjectPtr<UDMFDigimonAbilityData>& SoftAbility : SpeciesData->StartingAbilities)
    {
        if (UDMFDigimonAbilityData* Ability = SoftAbility.LoadSynchronous())
        {
            const FName Id = Ability->AbilityId.IsNone() ? Ability->GetPrimaryAssetId().PrimaryAssetName : Ability->AbilityId;
            Runtime.EquippedAbilityIds.AddUnique(Id);
        }
    }

    if (UDMFDigimonAbilityData* Basic = SpeciesData->BasicAutoAttack.LoadSynchronous())
    {
        const FName BasicId = Basic->AbilityId.IsNone() ? Basic->GetPrimaryAssetId().PrimaryAssetName : Basic->AbilityId;
        Runtime.EquippedAbilityIds.AddUnique(BasicId);
    }

    InitializeFromInstance(Runtime, nullptr);
    SetCombatTeamId(WildCombatTeamId);
    if (CombatComponent)
    {
        CombatComponent->ConfigureDamageTuning(OutgoingDamageMultiplier, IncomingDamageMultiplier);
    }
    RefreshWildHomeAndAutomation();
    return true;
}

void ADMFWildDigimonCharacter::RefreshWildHomeAndAutomation()
{
    if (!HasAuthority())
    {
        return;
    }

    if (!bSpawnerManaged)
    {
        SpawnHomeLocation = GetActorLocation();
    }

    const bool bGameplayReady = GroundTransitionState.Mode == EDMFWildGroundTransitionMode::None;
    const bool bEffectiveAutoBattle = bAutoBattle && bGameplayReady;
    const bool bEffectiveRetaliation = bRetaliateWhenAttacked && bGameplayReady;

    // Proactive acquisition and retaliation are separate policies. This is the important MMO rule:
    // Auto Battle=false + Retaliate=true means peaceful until attacked, then fight back.
    ConfigureCombatAutomation(bEffectiveAutoBattle,
        FMath::Max(0.0f, AggroRange), FMath::Max(AggroRange, LeashRange), nullptr);
    if (CombatComponent)
    {
        CombatComponent->ConfigureRetaliation(bEffectiveRetaliation);
    }
}

void ADMFWildDigimonCharacter::SetWildAutoBattleEnabled(const bool bEnabled)
{
    if (!HasAuthority())
    {
        return;
    }

    if (bAutoBattle == bEnabled)
    {
        RefreshWildHomeAndAutomation();
        return;
    }

    bAutoBattle = bEnabled;
    RefreshWildHomeAndAutomation();

    if (!bAutoBattle)
    {
        ScheduleNextRoam();
    }

    ForceNetUpdate();
}

void ADMFWildDigimonCharacter::SetWildRetaliationEnabled(const bool bEnabled)
{
    if (!HasAuthority())
    {
        return;
    }

    bRetaliateWhenAttacked = bEnabled;
    RefreshWildHomeAndAutomation();
    if (!bAutoBattle && !bRetaliateWhenAttacked)
    {
        ScheduleNextRoam();
    }
    ForceNetUpdate();
}

void ADMFWildDigimonCharacter::BeginGroundEmergence(const float Depth, const float Duration)
{
    if (HasAuthority())
    {
        StartGroundTransition(EDMFWildGroundTransitionMode::Emerging, Depth, Duration);
    }
}

void ADMFWildDigimonCharacter::BeginGroundDespawn(const float Depth, const float Duration)
{
    if (HasAuthority())
    {
        StartGroundTransition(EDMFWildGroundTransitionMode::Despawning, Depth, Duration);
    }
}

void ADMFWildDigimonCharacter::StartGroundTransition(const EDMFWildGroundTransitionMode Mode, const float Depth, const float Duration)
{
    if (!HasAuthority() || Mode == EDMFWildGroundTransitionMode::None)
    {
        return;
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(RoamTimer);
    }

    CacheBaseMeshRelativeLocation();
    bCombatTargetableBeforeTransition = bCombatTargetable;
    bCombatTargetable = false;
    if (UCapsuleComponent* Capsule = GetCapsuleComponent())
    {
        CapsuleCollisionBeforeTransition = Capsule->GetCollisionEnabled();
        bCapsuleCollisionCached = true;
        Capsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }
    ConfigureCombatAutomation(false, FMath::Max(0.0f, AggroRange), FMath::Max(AggroRange, LeashRange), nullptr);
    if (CombatComponent)
    {
        CombatComponent->ConfigureRetaliation(false);
        CombatComponent->SetAuthoritativeTarget(nullptr);
    }

    if (AAIController* AI = Cast<AAIController>(GetController()))
    {
        AI->StopMovement();
    }
    if (UCharacterMovementComponent* Movement = GetCharacterMovement())
    {
        Movement->DisableMovement();
    }

    GroundTransitionState.Mode = Mode;
    LastObservedGroundTransitionMode = Mode;
    GroundTransitionState.Depth = FMath::Max(0.0f, Depth);
    GroundTransitionState.Duration = FMath::Max(0.05f, Duration);
    GroundTransitionState.StartServerTimeSeconds = GetSynchronizedServerTimeSeconds();
    GroundTransitionState.Rarity = SpawnRarity;
    ++GroundTransitionState.Serial;
    SetActorTickEnabled(true);
    ApplyGroundTransitionVisual();
    BP_OnGroundTransitionStarted(Mode, GroundTransitionState.Rarity);
    ForceNetUpdate();
}

void ADMFWildDigimonCharacter::OnRep_GroundTransitionState()
{
    CacheBaseMeshRelativeLocation();
    if (GroundTransitionState.Mode == EDMFWildGroundTransitionMode::None)
    {
        if (GetMesh())
        {
            GetMesh()->SetRelativeLocation(BaseMeshRelativeLocation);
        }
        if (bCapsuleCollisionCached)
        {
            if (UCapsuleComponent* Capsule = GetCapsuleComponent())
            {
                Capsule->SetCollisionEnabled(CapsuleCollisionBeforeTransition);
            }
        }
        if (LastObservedGroundTransitionMode != EDMFWildGroundTransitionMode::None)
        {
            BP_OnGroundTransitionFinished(LastObservedGroundTransitionMode);
        }
        LastObservedGroundTransitionMode = EDMFWildGroundTransitionMode::None;
        SetActorTickEnabled(false);
        return;
    }

    if (UCapsuleComponent* Capsule = GetCapsuleComponent())
    {
        if (!bCapsuleCollisionCached)
        {
            CapsuleCollisionBeforeTransition = Capsule->GetCollisionEnabled();
            bCapsuleCollisionCached = true;
        }
        Capsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }
    LastObservedGroundTransitionMode = GroundTransitionState.Mode;
    SetActorTickEnabled(true);
    ApplyGroundTransitionVisual();
    BP_OnGroundTransitionStarted(GroundTransitionState.Mode, GroundTransitionState.Rarity);
}

void ADMFWildDigimonCharacter::ApplyGroundTransitionVisual()
{
    if (!GetMesh() || GroundTransitionState.Mode == EDMFWildGroundTransitionMode::None)
    {
        return;
    }

    CacheBaseMeshRelativeLocation();
    const double Duration = FMath::Max(0.01, static_cast<double>(GroundTransitionState.Duration));
    const double Elapsed = FMath::Max(0.0, GetSynchronizedServerTimeSeconds() - GroundTransitionState.StartServerTimeSeconds);
    const float Alpha = FMath::Clamp(static_cast<float>(Elapsed / Duration), 0.0f, 1.0f);
    const float SmoothAlpha = Alpha * Alpha * (3.0f - 2.0f * Alpha);
    const float Depth = FMath::Max(0.0f, GroundTransitionState.Depth);

    const float ZOffset = GroundTransitionState.Mode == EDMFWildGroundTransitionMode::Emerging
        ? -Depth * (1.0f - SmoothAlpha)
        : -Depth * SmoothAlpha;
    GetMesh()->SetRelativeLocation(BaseMeshRelativeLocation + FVector(0.0f, 0.0f, ZOffset));
}

void ADMFWildDigimonCharacter::FinishGroundTransitionIfAuthority()
{
    if (!HasAuthority() || GroundTransitionState.Mode == EDMFWildGroundTransitionMode::None)
    {
        return;
    }

    const EDMFWildGroundTransitionMode CompletedMode = GroundTransitionState.Mode;
    if (GetMesh())
    {
        GetMesh()->SetRelativeLocation(BaseMeshRelativeLocation + (CompletedMode == EDMFWildGroundTransitionMode::Despawning
            ? FVector(0.0f, 0.0f, -FMath::Max(0.0f, GroundTransitionState.Depth))
            : FVector::ZeroVector));
    }

    if (CompletedMode == EDMFWildGroundTransitionMode::Despawning)
    {
        Destroy();
        return;
    }

    GroundTransitionState.Mode = EDMFWildGroundTransitionMode::None;
    GroundTransitionState.Depth = 0.0f;
    GroundTransitionState.Duration = 0.0f;
    GroundTransitionState.StartServerTimeSeconds = GetSynchronizedServerTimeSeconds();
    ++GroundTransitionState.Serial;
    bCombatTargetable = bCombatTargetableBeforeTransition;
    if (bCapsuleCollisionCached)
    {
        if (UCapsuleComponent* Capsule = GetCapsuleComponent())
        {
            Capsule->SetCollisionEnabled(CapsuleCollisionBeforeTransition);
        }
    }

    if (UCharacterMovementComponent* Movement = GetCharacterMovement())
    {
        Movement->SetMovementMode(MOVE_Walking);
    }
    RefreshWildHomeAndAutomation();
    ScheduleNextRoam();
    BP_OnGroundTransitionFinished(CompletedMode);
    LastObservedGroundTransitionMode = EDMFWildGroundTransitionMode::None;
    SetActorTickEnabled(false);
    ForceNetUpdate();
}

void ADMFWildDigimonCharacter::ScheduleNextRoam()
{
    if (!HasAuthority() || !bEnableFreeRoaming || IsGroundTransitionActive() || !GetWorld())
    {
        return;
    }

    const float MinDelay = FMath::Max(0.05f, MinimumRoamDelay);
    const float MaxDelay = FMath::Max(MinDelay, MaximumRoamDelay);
    GetWorld()->GetTimerManager().SetTimer(RoamTimer, this, &ADMFWildDigimonCharacter::TryBeginIdleRoam, FMath::FRandRange(MinDelay, MaxDelay), false);
}

void ADMFWildDigimonCharacter::TryBeginIdleRoam()
{
    if (!HasAuthority() || !bEnableFreeRoaming || IsGroundTransitionActive())
    {
        return;
    }

    if (!CombatComponent || CombatComponent->IsDefeated())
    {
        return;
    }
    if (CombatComponent->GetCombatState() != EDMFCombatState::Idle || CombatComponent->GetCurrentTarget())
    {
        ScheduleNextRoam();
        return;
    }

    AAIController* AI = Cast<AAIController>(GetController());
    if (!AI)
    {
        ScheduleNextRoam();
        return;
    }

    // Do not constantly redirect an idle Digimon that is still walking toward its current roam point.
    // This keeps roaming organic and bounds NavigationSystem queries to meaningful idle decisions.
    if (AI->GetMoveStatus() == EPathFollowingStatus::Moving)
    {
        ScheduleNextRoam();
        return;
    }

    UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    FNavLocation Destination;
    const float EffectiveRoamRadius = FMath::Min(FMath::Max(0.0f, RoamRadius), FMath::Max(0.0f, LeashRange));
    FSharedConstNavQueryFilter QueryFilter;
    if (NavSystem && EffectiveRoamRadius > 0.0f && NavSystem->GetRandomReachablePointInRadius(SpawnHomeLocation, EffectiveRoamRadius, Destination, nullptr, QueryFilter))
    {
        AI->MoveToLocation(Destination.Location, FMath::Max(5.0f, RoamAcceptanceRadius), true, true, true, false, nullptr, true);
    }

    ScheduleNextRoam();
}

void ADMFWildDigimonCharacter::CacheBaseMeshRelativeLocation()
{
    if (!bBaseMeshRelativeLocationCached && GetMesh())
    {
        BaseMeshRelativeLocation = GetMesh()->GetRelativeLocation();
        bBaseMeshRelativeLocationCached = true;
    }
}

double ADMFWildDigimonCharacter::GetSynchronizedServerTimeSeconds() const
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
