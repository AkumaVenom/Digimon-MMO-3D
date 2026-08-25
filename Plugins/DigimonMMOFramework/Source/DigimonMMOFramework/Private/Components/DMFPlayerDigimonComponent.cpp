#include "Components/DMFPlayerDigimonComponent.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Data/DMFStarterRosterData.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFDigimonCarePropActor.h"
#include "Game/DMFWildDigimonCharacter.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Data/DMFDigimonAbilityData.h"
#include "Game/DMFMMOGameMode.h"
#include "Game/DMFPlayerState.h"
#include "Persistence/DMFAccountPersistenceSubsystem.h"
#include "Settings/DMFFrameworkSettings.h"
#include "DigimonMMOFramework.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "Engine/StaticMesh.h"
#include "Engine/AssetManager.h"
#include "TimerManager.h"
#include "AIController.h"
#include "Animation/AnimMontage.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"

UDMFPlayerDigimonComponent::UDMFPlayerDigimonComponent()
{
    SetIsReplicatedByDefault(true);
}

void UDMFPlayerDigimonComponent::BeginPlay()
{
    Super::BeginPlay();
    if (GetOwner() && GetOwner()->HasAuthority())
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        const float Interval = Settings ? FMath::Max(5.0f, Settings->AccountAutosaveInterval) : 30.0f;
        GetWorld()->GetTimerManager().SetTimer(AutosaveTimer, this, &UDMFPlayerDigimonComponent::PersistOwningPlayer, Interval, true, Interval);

        const float CareInterval = Settings ? FMath::Clamp(Settings->CareServerTickInterval, 1.0f, 60.0f) : 10.0f;
        GetWorld()->GetTimerManager().SetTimer(CareTickTimer, this, &UDMFPlayerDigimonComponent::CareTick, CareInterval, true, CareInterval);
    }
}

void UDMFPlayerDigimonComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (GetOwner() && GetOwner()->HasAuthority())
    {
        PersistOwningPlayer();
    }
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(AutosaveTimer);
        World->GetTimerManager().ClearTimer(CareTickTimer);
        World->GetTimerManager().ClearTimer(CareSequenceTimer);
    }
    DestroyActiveCareMeat();
    Super::EndPlay(EndPlayReason);
}

void UDMFPlayerDigimonComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ReplicatedInventory, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ActivePartnerInstanceId, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, bStarterSelectionRequired, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ActivePartnerActor, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, CommandTarget, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, Money, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ReplicatedScanData, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, bCareSequenceActive, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, CareSequenceInstanceId, COND_OwnerOnly);
}

TArray<FDMFDigimonInstance> UDMFPlayerDigimonComponent::GetDigimonInventory() const
{
    TArray<FDMFDigimonInstance> Result;
    Result.Reserve(ReplicatedInventory.Items.Num());
    for (const FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        Result.Add(Entry.Digimon);
    }
    return Result;
}

bool UDMFPlayerDigimonComponent::IsActivePartnerSummoned() const
{
    return IsValid(ActivePartnerActor.Get());
}

bool UDMFPlayerDigimonComponent::GetDigimonByInstanceId(const FGuid InstanceId, FDMFDigimonInstance& OutDigimon) const
{
    for (const FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        if (Entry.Digimon.InstanceId == InstanceId)
        {
            OutDigimon = Entry.Digimon;
            return true;
        }
    }
    return false;
}

void UDMFPlayerDigimonComponent::InitializeFromAccountRecord(const FDMFAccountRecord& Record)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    ReplicatedInventory.Items.Reset();
    const int64 NowUtcTicks = FDateTime::UtcNow().GetTicks();
    const UDMFFrameworkSettings* CareSettings = GetDefault<UDMFFrameworkSettings>();
    for (const FDMFDigimonInstance& Digimon : Record.DigimonInventory)
    {
        FDMFReplicatedDigimonEntry& NewEntry = ReplicatedInventory.Items.AddDefaulted_GetRef();
        NewEntry.Digimon = Digimon;
        if (CareSettings && CareSettings->bEnableCareSystem)
        {
            if (UDMFDigimonSpeciesData* Species = ResolveSpeciesById(NewEntry.Digimon.SpeciesId))
            {
                NormalizeAndApplyCareDecay(NewEntry, *Species, NowUtcTicks);
            }
        }
        ReplicatedInventory.MarkItemDirty(NewEntry);
    }
    ReplicatedInventory.MarkArrayDirty();

    ActivePartnerInstanceId = Record.ActivePartnerInstanceId;
    Money = Record.Money;
    ReplicatedScanData = Record.ScanData;
    bCareSequenceActive = false;
    CareSequenceInstanceId.Invalidate();
    bStarterSelectionRequired = !Record.bStarterSelected || !ActivePartnerInstanceId.IsValid();

    OnDigimonInventoryChanged.Broadcast();
    OnStarterRequirementChanged.Broadcast(bStarterSelectionRequired);
    for (const FDMFScanDataEntry& ScanEntry : ReplicatedScanData)
    {
        BroadcastScanState(ScanEntry.SpeciesId);
    }
    if (const FDMFReplicatedDigimonEntry* ActiveEntry = FindInventoryEntry(ActivePartnerInstanceId))
    {
        BroadcastCareState(*ActiveEntry);
    }
}

void UDMFPlayerDigimonComponent::ApplyToAccountRecord(FDMFAccountRecord& Record) const
{
    Record.DigimonInventory = GetDigimonInventory();
    Record.ActivePartnerInstanceId = ActivePartnerInstanceId;
    Record.bStarterSelected = !bStarterSelectionRequired && ActivePartnerInstanceId.IsValid();
    Record.Money = Money;
    Record.ScanData = ReplicatedScanData;
}

bool UDMFPlayerDigimonComponent::ResolveStarterSpecies(const FPrimaryAssetId StarterSpeciesId, UDMFDigimonSpeciesData*& OutSpecies) const
{
    OutSpecies = nullptr;
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UDMFStarterRosterData* Roster = Settings ? Settings->StarterRoster.LoadSynchronous() : nullptr;
    if (!Roster)
    {
        return false;
    }

    for (const FDMFStarterRosterEntry& Entry : Roster->Starters)
    {
        if (!Entry.bEnabled)
        {
            continue;
        }

        UDMFDigimonSpeciesData* Species = Entry.Species.LoadSynchronous();
        if (Species && Species->GetPrimaryAssetId() == StarterSpeciesId)
        {
            OutSpecies = Species;
            return true;
        }
    }

    return false;
}

UDMFDigimonSpeciesData* UDMFPlayerDigimonComponent::ResolveSpeciesById(const FPrimaryAssetId SpeciesId) const
{
    if (!SpeciesId.IsValid())
    {
        return nullptr;
    }

    // Primary Asset Manager is the long-term species resolver for starter, captured, evolved,
    // wild and ranked Digimon. The starter-roster fallback keeps onboarding usable even before
    // a project has opted into global species scanning.
    UAssetManager& AssetManager = UAssetManager::Get();
    if (UDMFDigimonSpeciesData* Loaded = AssetManager.GetPrimaryAssetObject<UDMFDigimonSpeciesData>(SpeciesId))
    {
        return Loaded;
    }

    const FSoftObjectPath AssetPath = AssetManager.GetPrimaryAssetPath(SpeciesId);
    if (AssetPath.IsValid())
    {
        if (UDMFDigimonSpeciesData* Loaded = Cast<UDMFDigimonSpeciesData>(AssetPath.TryLoad()))
        {
            return Loaded;
        }
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UDMFStarterRosterData* Roster = Settings ? Settings->StarterRoster.LoadSynchronous() : nullptr;
    if (Roster)
    {
        for (const FDMFStarterRosterEntry& Entry : Roster->Starters)
        {
            UDMFDigimonSpeciesData* Candidate = Entry.Species.LoadSynchronous();
            if (Candidate && Candidate->GetPrimaryAssetId() == SpeciesId)
            {
                return Candidate;
            }
        }
    }

    return nullptr;
}

FDMFDigimonInstance UDMFPlayerDigimonComponent::BuildStarterInstance(const UDMFDigimonSpeciesData& Species) const
{
    FDMFDigimonInstance Result;
    Result.InstanceId = FGuid::NewGuid();
    Result.SpeciesId = Species.GetPrimaryAssetId();
    Result.Stats = Species.BaseStats;
    Result.Stats.Level = FMath::Max(1, Species.StartingLevel);
    Result.CurrentHP = Result.Stats.MaxHP;
    Result.CurrentSP = Result.Stats.MaxSP;
    Result.EquippedAbilityIds = Species.StartingAbilityIds;
    for (const TSoftObjectPtr<UDMFDigimonAbilityData>& SoftAbility : Species.StartingAbilities)
    {
        if (UDMFDigimonAbilityData* Ability = SoftAbility.LoadSynchronous())
        {
            const FName Id = Ability->AbilityId.IsNone() ? Ability->GetPrimaryAssetId().PrimaryAssetName : Ability->AbilityId;
            Result.EquippedAbilityIds.AddUnique(Id);
        }
    }
    if (UDMFDigimonAbilityData* Basic = Species.BasicAutoAttack.LoadSynchronous())
    {
        const FName BasicId = Basic->AbilityId.IsNone() ? Basic->GetPrimaryAssetId().PrimaryAssetName : Basic->AbilityId;
        Result.EquippedAbilityIds.AddUnique(BasicId);
    }
    Result.UnspentAttributePoints = 0;
    Result.Care.Hunger = FMath::Clamp(Species.StartingHungerPercent, 0.0f, 100.0f);
    Result.Care.Fullness = Result.Care.Hunger;
    Result.Care.LastCareUpdateUtcTicks = FDateTime::UtcNow().GetTicks();
    Result.bStarterPartner = true;
    return Result;
}

FDMFDigimonInstance UDMFPlayerDigimonComponent::BuildMaterializedInstance(const UDMFDigimonSpeciesData& Species) const
{
    FDMFDigimonInstance Result = BuildStarterInstance(Species);
    Result.bStarterPartner = false;
    return Result;
}

float UDMFPlayerDigimonComponent::GetScanPercent(const FPrimaryAssetId SpeciesId) const
{
    for (const FDMFScanDataEntry& Entry : ReplicatedScanData)
    {
        if (Entry.SpeciesId == SpeciesId)
        {
            return FMath::Max(0.0f, Entry.ScanPercent);
        }
    }
    return 0.0f;
}

bool UDMFPlayerDigimonComponent::IsSpeciesReadyToMaterialize(const FPrimaryAssetId SpeciesId) const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableScanAndMaterialization)
    {
        return false;
    }

    const UDMFDigimonSpeciesData* Species = ResolveSpeciesById(SpeciesId);
    if (!Species || !Species->bMaterializationEnabled)
    {
        return false;
    }

    return GetScanPercent(SpeciesId) + KINDA_SMALL_NUMBER >= FMath::Max(1.0f, Species->MaterializationRequiredScanPercent);
}

int32 UDMFPlayerDigimonComponent::GetOwnedSpeciesCount(const FPrimaryAssetId SpeciesId) const
{
    int32 Count = 0;
    for (const FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        Count += Entry.Digimon.SpeciesId == SpeciesId ? 1 : 0;
    }
    return Count;
}

void UDMFPlayerDigimonComponent::BroadcastScanState(const FPrimaryAssetId SpeciesId)
{
    OnScanDataChanged.Broadcast(SpeciesId, GetScanPercent(SpeciesId), IsSpeciesReadyToMaterialize(SpeciesId));
}

bool UDMFPlayerDigimonComponent::AwardScanDataForVictory(const UDMFDigimonSpeciesData& Species, float& OutAddedPercent, float& OutNewPercent, bool& bOutReady)
{
    OutAddedPercent = 0.0f;
    OutNewPercent = GetScanPercent(Species.GetPrimaryAssetId());
    bOutReady = false;

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableScanAndMaterialization || !Species.bScanDataEnabled)
    {
        return false;
    }

    const float Reward = FMath::Max(0.0f, Species.BattleScanPercentReward);
    if (Reward <= KINDA_SMALL_NUMBER)
    {
        return false;
    }

    const FPrimaryAssetId SpeciesId = Species.GetPrimaryAssetId();
    const float Cap = FMath::Max(1.0f, Species.ScanPercentCap);
    FDMFScanDataEntry* ExistingEntry = ReplicatedScanData.FindByPredicate([&](const FDMFScanDataEntry& Entry)
    {
        return Entry.SpeciesId == SpeciesId;
    });

    const float OldPercent = ExistingEntry ? FMath::Clamp(ExistingEntry->ScanPercent, 0.0f, Cap) : 0.0f;
    const float NewPercent = FMath::Clamp(OldPercent + Reward, 0.0f, Cap);
    OutAddedPercent = FMath::Max(0.0f, NewPercent - OldPercent);
    OutNewPercent = NewPercent;

    if (OutAddedPercent <= KINDA_SMALL_NUMBER)
    {
        bOutReady = IsSpeciesReadyToMaterialize(SpeciesId);
        return false;
    }

    if (!ExistingEntry)
    {
        FDMFScanDataEntry& NewEntry = ReplicatedScanData.AddDefaulted_GetRef();
        NewEntry.SpeciesId = SpeciesId;
        NewEntry.ScanPercent = NewPercent;
    }
    else
    {
        ExistingEntry->ScanPercent = NewPercent;
    }

    bOutReady = NewPercent + KINDA_SMALL_NUMBER >= FMath::Max(1.0f, Species.MaterializationRequiredScanPercent);
    BroadcastScanState(SpeciesId);
    return true;
}

void UDMFPlayerDigimonComponent::ServerMaterializeDigimon_Implementation(const FPrimaryAssetId SpeciesId)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableScanAndMaterialization)
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "MaterializationSystemDisabled", "Scan & Materialization is disabled."), SpeciesId, FGuid());
        return;
    }

    UDMFDigimonSpeciesData* Species = ResolveSpeciesById(SpeciesId);
    if (!Species || !Species->bScanDataEnabled || !Species->bMaterializationEnabled)
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "SpeciesCannotMaterialize", "This species cannot be materialized."), SpeciesId, FGuid());
        return;
    }

    const float Required = FMath::Max(1.0f, Species->MaterializationRequiredScanPercent);
    if (GetScanPercent(SpeciesId) + KINDA_SMALL_NUMBER < Required)
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "NotEnoughScanData", "Not enough Scan Data has been collected yet."), SpeciesId, FGuid());
        return;
    }

    if (ReplicatedInventory.Items.Num() >= FMath::Max(1, Settings->MaxActiveDigimonInventory))
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "MaterializationInventoryFull", "The active Digimon Collection is full. Free a slot before materializing."), SpeciesId, FGuid());
        return;
    }

    UClass* PartnerClass = Species->WorldActorClass.LoadSynchronous();
    if (!PartnerClass || !PartnerClass->IsChildOf(ADMFDigimonCharacter::StaticClass()) || PartnerClass->IsChildOf(ADMFWildDigimonCharacter::StaticClass()))
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "MaterializationInvalidPartnerClass", "Species World Actor Class must be a partner DMFDigimonCharacter Blueprint, not a Wild Digimon class."), SpeciesId, FGuid());
        return;
    }

    FDMFScanDataEntry* ScanEntry = ReplicatedScanData.FindByPredicate([&](const FDMFScanDataEntry& Entry)
    {
        return Entry.SpeciesId == SpeciesId;
    });
    if (!ScanEntry)
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "MaterializationScanRecordMissing", "Scan Data record is unavailable."), SpeciesId, FGuid());
        return;
    }

    const FDMFDigimonInstance NewDigimon = BuildMaterializedInstance(*Species);
    FDMFReplicatedDigimonEntry& NewInventoryEntry = ReplicatedInventory.Items.AddDefaulted_GetRef();
    NewInventoryEntry.Digimon = NewDigimon;
    ReplicatedInventory.MarkItemDirty(NewInventoryEntry);
    ReplicatedInventory.MarkArrayDirty();

    ScanEntry->ScanPercent = FMath::Max(0.0f, ScanEntry->ScanPercent - Required);
    OnDigimonInventoryChanged.Broadcast();
    BroadcastScanState(SpeciesId);
    PersistOwningPlayer();
    ClientMaterializationResult(true, NSLOCTEXT("DMF", "MaterializationSucceeded", "Materialization complete. The new Digimon has been added to your Collection."), SpeciesId, NewDigimon.InstanceId);
}

void UDMFPlayerDigimonComponent::ClientScanDataRewardGranted_Implementation(const FPrimaryAssetId SpeciesId, const float AddedPercent, const float NewPercent, const bool bMaterializationReady)
{
    OnScanDataRewardGranted.Broadcast(SpeciesId, AddedPercent, NewPercent, bMaterializationReady);
    OnScanDataChanged.Broadcast(SpeciesId, NewPercent, bMaterializationReady);
}

void UDMFPlayerDigimonComponent::ClientMaterializationResult_Implementation(const bool bSuccess, const FText& Message, const FPrimaryAssetId SpeciesId, const FGuid NewDigimonInstanceId)
{
    OnMaterializationResult.Broadcast(bSuccess, Message, SpeciesId, NewDigimonInstanceId);
}

void UDMFPlayerDigimonComponent::ServerSelectStarter_Implementation(const FPrimaryAssetId StarterSpeciesId)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    if (!bStarterSelectionRequired)
    {
        ClientStarterSelectionResult(false, NSLOCTEXT("DMF", "StarterAlreadySelected", "Starter selection has already been completed for this account."), ActivePartnerInstanceId);
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && ReplicatedInventory.Items.Num() >= Settings->MaxActiveDigimonInventory)
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Starter selection rejected: active Digimon inventory is full."));
        ClientStarterSelectionResult(false, NSLOCTEXT("DMF", "StarterInventoryFull", "Starter selection failed because the active Digimon inventory is full."), FGuid());
        return;
    }

    UDMFDigimonSpeciesData* Species = nullptr;
    if (!ResolveStarterSpecies(StarterSpeciesId, Species) || !Species)
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Starter selection rejected: species is not in the configured starter roster."));
        ClientStarterSelectionResult(false, NSLOCTEXT("DMF", "StarterInvalidSpecies", "That Digimon is not an enabled starter choice."), FGuid());
        return;
    }

    const FDMFDigimonInstance NewStarter = BuildStarterInstance(*Species);
    FDMFReplicatedDigimonEntry& NewEntry = ReplicatedInventory.Items.AddDefaulted_GetRef();
    NewEntry.Digimon = NewStarter;
    ReplicatedInventory.MarkItemDirty(NewEntry);

    ActivePartnerInstanceId = NewStarter.InstanceId;
    bStarterSelectionRequired = false;

    PersistOwningPlayer();

    if (ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner()))
    {
        if (APlayerController* PC = Cast<APlayerController>(PS->GetOwner()))
        {
            if (ADMFMMOGameMode* MMOGameMode = GetWorld() ? GetWorld()->GetAuthGameMode<ADMFMMOGameMode>() : nullptr)
            {
                MMOGameMode->EnsureFrameworkPlayerAvatar(PC);
            }
            SpawnOrRefreshActivePartner(PC->GetPawn());
        }
    }

    OnDigimonInventoryChanged.Broadcast();
    OnStarterRequirementChanged.Broadcast(false);
    OnStarterSelectionFinished.Broadcast(NewStarter.InstanceId);
    ClientStarterSelectionResult(true, NSLOCTEXT("DMF", "StarterGranted", "Partner Digimon confirmed and saved."), NewStarter.InstanceId);
}

void UDMFPlayerDigimonComponent::ClientStarterSelectionResult_Implementation(bool bSuccess, const FText& Message, FGuid PartnerInstanceId)
{
    OnStarterSelectionResult.Broadcast(bSuccess, Message, PartnerInstanceId);
}

bool UDMFPlayerDigimonComponent::ResetStarterOnboarding(const bool bRemoveStarterDigimon)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return false;
    }

    bool bChangedInventory = false;
    if (bRemoveStarterDigimon)
    {
        for (int32 Index = ReplicatedInventory.Items.Num() - 1; Index >= 0; --Index)
        {
            if (ReplicatedInventory.Items[Index].Digimon.bStarterPartner)
            {
                ReplicatedInventory.Items.RemoveAt(Index);
                bChangedInventory = true;
            }
        }

        if (bChangedInventory)
        {
            ReplicatedInventory.MarkArrayDirty();
        }
    }

    if (IsValid(ActivePartnerActor))
    {
        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
    }

    ActivePartnerInstanceId.Invalidate();
    CommandTarget = nullptr;
    OnCommandTargetChanged.Broadcast(nullptr);
    bStarterSelectionRequired = true;
    PersistOwningPlayer();

    if (bChangedInventory)
    {
        OnDigimonInventoryChanged.Broadcast();
    }
    OnStarterRequirementChanged.Broadcast(true);
    return true;
}

void UDMFPlayerDigimonComponent::PersistOwningPlayer()
{
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    if (!PS || !PS->HasAuthority())
    {
        return;
    }

    UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!Persistence)
    {
        return;
    }

    FDMFAccountRecord Record;
    if (!Persistence->GetAccount(PS->GetAuthenticatedUsername(), Record))
    {
        return;
    }

    // Keep the complete owned collection authoritative in server UTC without turning every inactive
    // Digimon into a periodic replication source. Inactive Care values are advanced when the normal
    // account autosave runs; only the active partner is pushed to the owner immediately for live UI.
    // The project-level master switch freezes all Care progression, including offline/UTC decay.
    const UDMFFrameworkSettings* CareSettings = GetDefault<UDMFFrameworkSettings>();
    if (CareSettings && CareSettings->bEnableCareSystem)
    {
        const int64 NowUtcTicks = FDateTime::UtcNow().GetTicks();
        for (FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
        {
            UDMFDigimonSpeciesData* Species = ResolveSpeciesById(Entry.Digimon.SpeciesId);
            if (!Species || !Species->bCareEnabled)
            {
                continue;
            }

            const int64 PreviousCareTicks = Entry.Digimon.Care.LastCareUpdateUtcTicks;
            const bool bCareChanged = NormalizeAndApplyCareDecay(Entry, *Species, NowUtcTicks);
            if (Entry.Digimon.InstanceId == ActivePartnerInstanceId && (bCareChanged || PreviousCareTicks <= 0))
            {
                ReplicatedInventory.MarkItemDirty(Entry);
                BroadcastCareState(Entry);
            }
        }
    }

    ApplyToAccountRecord(Record);
    FString Error;
    if (!Persistence->SaveAccount(Record, Error))
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("Failed to persist player '%s': %s"), *PS->GetAuthenticatedUsername(), *Error);
    }
}

ADMFDigimonCharacter* UDMFPlayerDigimonComponent::SpawnOrRefreshActivePartner(APawn* PlayerPawn)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !PlayerPawn || !ActivePartnerInstanceId.IsValid())
    {
        return nullptr;
    }

    FDMFDigimonInstance Instance;
    if (!GetDigimonByInstanceId(ActivePartnerInstanceId, Instance))
    {
        return nullptr;
    }

    if (Instance.CurrentHP <= 0)
    {
        UE_LOG(LogDigimonMMOFramework, Log, TEXT("Partner '%s' is defeated and will not be summoned until healed."), *ActivePartnerInstanceId.ToString());
        return nullptr;
    }

    UDMFDigimonSpeciesData* Species = ResolveSpeciesById(Instance.SpeciesId);
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();

    if (!Species)
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Cannot spawn partner: species asset '%s' is not currently resolvable."), *Instance.SpeciesId.ToString());
        return nullptr;
    }

    UClass* SpawnClass = Species->WorldActorClass.LoadSynchronous();
    if (!SpawnClass || !SpawnClass->IsChildOf(ADMFDigimonCharacter::StaticClass()))
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Cannot spawn partner '%s': WorldActorClass must derive from ADMFDigimonCharacter."), *Species->GetName());
        return nullptr;
    }

    if (IsValid(ActivePartnerActor))
    {
        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
    }

    const FVector Offset = Settings ? Settings->PartnerSpawnOffset : FVector(150.0, 120.0, 0.0);
    const FVector SpawnLocation = PlayerPawn->GetActorTransform().TransformPosition(Offset);
    const FRotator SpawnRotation = PlayerPawn->GetActorRotation();

    FActorSpawnParameters Params;
    Params.Owner = GetOwner();
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    ActivePartnerActor = GetWorld()->SpawnActor<ADMFDigimonCharacter>(SpawnClass, SpawnLocation, SpawnRotation, Params);
    if (ActivePartnerActor)
    {
        ActivePartnerActor->InitializeFromInstance(Instance, Cast<ADMFPlayerState>(GetOwner()));
        const FName PlayerTeamId = Settings ? Settings->PlayerCombatTeamId : FName(TEXT("Players"));
        ActivePartnerActor->SetCombatTeamId(PlayerTeamId);
        ActivePartnerActor->ConfigureCombatAutomation(
            Settings ? Settings->bPlayerPartnerAutoBattle : false,
            Settings ? Settings->PartnerAggroRange : 1200.0f,
            Settings ? Settings->PartnerLeashRange : 2500.0f,
            PlayerPawn);
        if (ActivePartnerActor->CombatComponent)
        {
            ActivePartnerActor->CombatComponent->ConfigureDamageTuning(
                Settings ? Settings->PlayerPartnerOutgoingDamageMultiplier : 1.50f,
                Settings ? Settings->PlayerPartnerIncomingDamageMultiplier : 0.50f);
            ActivePartnerActor->CombatComponent->OnVitalsChanged.AddDynamic(this, &UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged);
        }
    }

    // A Digimon whose persisted waste timer expired while recalled/offline poops as soon as it is safely back in the world.
    CareTick();
    return ActivePartnerActor;
}

void UDMFPlayerDigimonComponent::ServerSetActivePartner_Implementation(const FGuid InstanceId, const bool bSummonNow)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !InstanceId.IsValid() || bCareSequenceActive)
    {
        return;
    }

    FDMFDigimonInstance Instance;
    if (!GetDigimonByInstanceId(InstanceId, Instance) || !Instance.IsValid())
    {
        ClientPartnerActionResult(false, NSLOCTEXT("DMF", "PartnerNotOwned", "That Digimon is not available in your active Digimon inventory."), InstanceId);
        return;
    }

    if (bSummonNow && Instance.CurrentHP <= 0)
    {
        ClientPartnerActionResult(false, NSLOCTEXT("DMF", "PartnerDefeated", "That Digimon is defeated. Heal it before summoning."), InstanceId);
        return;
    }

    ActivePartnerInstanceId = InstanceId;

    // Inactive Digimon do not generate periodic owner replication. Bring the newly selected partner
    // fully current before it becomes the Care UI source, then replicate that one authoritative item.
    // When the global Care switch is disabled, selection must not advance Hunger behind the disabled UI.
    const UDMFFrameworkSettings* CareSettings = GetDefault<UDMFFrameworkSettings>();
    if (CareSettings && CareSettings->bEnableCareSystem)
    {
        if (FDMFReplicatedDigimonEntry* SelectedEntry = FindInventoryEntry(InstanceId))
        {
            if (UDMFDigimonSpeciesData* SelectedSpecies = ResolveSpeciesById(SelectedEntry->Digimon.SpeciesId))
            {
                const int64 PreviousCareTicks = SelectedEntry->Digimon.Care.LastCareUpdateUtcTicks;
                const bool bCareChanged = NormalizeAndApplyCareDecay(*SelectedEntry, *SelectedSpecies, FDateTime::UtcNow().GetTicks());
                if (bCareChanged || PreviousCareTicks <= 0)
                {
                    ReplicatedInventory.MarkItemDirty(*SelectedEntry);
                }
                BroadcastCareState(*SelectedEntry);
            }
        }
    }

    CommandTarget = nullptr;
    OnCommandTargetChanged.Broadcast(nullptr);
    PersistOwningPlayer();
    OnDigimonInventoryChanged.Broadcast();

    ADMFDigimonCharacter* Spawned = ActivePartnerActor.Get();
    if (!bSummonNow && IsValid(ActivePartnerActor))
    {
        if (ActivePartnerActor->CombatComponent)
        {
            ActivePartnerActor->CombatComponent->OnVitalsChanged.RemoveDynamic(this, &UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged);
        }
        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
        Spawned = nullptr;
    }
    if (bSummonNow)
    {
        ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
        APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
        Spawned = PC ? SpawnOrRefreshActivePartner(PC->GetPawn()) : nullptr;
        if (!Spawned)
        {
            ClientPartnerActionResult(false, NSLOCTEXT("DMF", "PartnerSpawnFailed", "The partner could not be summoned at the current location."), InstanceId);
            return;
        }
    }

    ClientPartnerActionResult(true,
        bSummonNow ? NSLOCTEXT("DMF", "PartnerSummoned", "Partner Digimon summoned.") : NSLOCTEXT("DMF", "PartnerSelected", "Active partner selected."),
        InstanceId);
}

void UDMFPlayerDigimonComponent::ServerRecallActivePartner_Implementation()
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || bCareSequenceActive)
    {
        return;
    }

    if (IsValid(ActivePartnerActor))
    {
        if (ActivePartnerActor->CombatComponent)
        {
            ActivePartnerActor->CombatComponent->OnVitalsChanged.RemoveDynamic(this, &UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged);
        }
        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
    }

    CommandTarget = nullptr;
    OnCommandTargetChanged.Broadcast(nullptr);
    OnDigimonInventoryChanged.Broadcast();
    ClientPartnerActionResult(true, NSLOCTEXT("DMF", "PartnerRecalled", "Partner Digimon recalled."), ActivePartnerInstanceId);
}

void UDMFPlayerDigimonComponent::ServerSetActivePartnerAutoBattle_Implementation(const bool bEnabled)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !ActivePartnerActor || bCareSequenceActive)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bProjectAllowsAutoBattle = Settings && Settings->bPlayerPartnerAutoBattle;
    const bool bEffectiveEnabled = bEnabled && bProjectAllowsAutoBattle;
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
    ActivePartnerActor->ConfigureCombatAutomation(
        bEffectiveEnabled,
        Settings ? Settings->PartnerAggroRange : 1200.0f,
        Settings ? Settings->PartnerLeashRange : 2500.0f,
        PC ? PC->GetPawn() : nullptr);
}

void UDMFPlayerDigimonComponent::ClientPartnerActionResult_Implementation(const bool bSuccess, const FText& Message, const FGuid PartnerInstanceId)
{
    OnPartnerActionResult.Broadcast(bSuccess, Message, PartnerInstanceId);
}

int32 UDMFPlayerDigimonComponent::HealAllOwnedDigimon(const bool bHealHP, const bool bHealSP, const bool bRestoreDefeated, const bool bIncludeBankStorage)
{
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    if (!PS || !PS->HasAuthority() || (!bHealHP && !bHealSP))
    {
        return 0;
    }

    int32 HealedCount = 0;
    for (FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        FDMFDigimonInstance& Digimon = Entry.Digimon;
        const bool bDefeated = Digimon.CurrentHP <= 0;
        bool bChanged = false;

        if (bHealHP && (!bDefeated || bRestoreDefeated))
        {
            const int32 NewHP = FMath::Max(1, Digimon.Stats.MaxHP);
            bChanged |= Digimon.CurrentHP != NewHP;
            Digimon.CurrentHP = NewHP;
        }
        if (bHealSP)
        {
            const int32 NewSP = FMath::Max(0, Digimon.Stats.MaxSP);
            bChanged |= Digimon.CurrentSP != NewSP;
            Digimon.CurrentSP = NewSP;
        }

        if (bChanged)
        {
            ReplicatedInventory.MarkItemDirty(Entry);
            ++HealedCount;
        }
    }

    UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    FDMFAccountRecord Record;
    const bool bHaveRecord = Persistence && Persistence->GetAccount(PS->GetAuthenticatedUsername(), Record);

    if (bIncludeBankStorage && bHaveRecord)
    {
        for (FDMFDigimonInstance& Digimon : Record.DigimonBank)
        {
            const bool bDefeated = Digimon.CurrentHP <= 0;
            bool bChanged = false;
            if (bHealHP && (!bDefeated || bRestoreDefeated))
            {
                const int32 NewHP = FMath::Max(1, Digimon.Stats.MaxHP);
                bChanged |= Digimon.CurrentHP != NewHP;
                Digimon.CurrentHP = NewHP;
            }
            if (bHealSP)
            {
                const int32 NewSP = FMath::Max(0, Digimon.Stats.MaxSP);
                bChanged |= Digimon.CurrentSP != NewSP;
                Digimon.CurrentSP = NewSP;
            }
            if (bChanged)
            {
                ++HealedCount;
            }
        }
    }

    if (IsValid(ActivePartnerActor) && ActivePartnerActor->CombatComponent)
    {
        FDMFDigimonInstance ActiveInstance;
        if (GetDigimonByInstanceId(ActivePartnerInstanceId, ActiveInstance))
        {
            ActivePartnerActor->CombatComponent->InitializeRuntimeVitals(ActiveInstance.CurrentHP, ActiveInstance.CurrentSP);
            if (ActiveInstance.CurrentHP > 0)
            {
                ActivePartnerActor->CombatComponent->RestoreVitals(bHealHP, bHealSP, true);
            }
        }
    }

    if (HealedCount > 0)
    {
        CommandTarget = nullptr;
        OnCommandTargetChanged.Broadcast(nullptr);
        ReplicatedInventory.MarkArrayDirty();
        OnDigimonInventoryChanged.Broadcast();
        OnPartyHealed.Broadcast(HealedCount);
    }

    if (bHaveRecord)
    {
        ApplyToAccountRecord(Record);
        FString Error;
        if (!Persistence->SaveAccount(Record, Error))
        {
            UE_LOG(LogDigimonMMOFramework, Error, TEXT("Healer persistence failed for '%s': %s"), *PS->GetAuthenticatedUsername(), *Error);
        }
    }
    else if (HealedCount > 0)
    {
        PersistOwningPlayer();
    }

    return HealedCount;
}

void UDMFPlayerDigimonComponent::ServerSetCommandTarget_Implementation(ADMFDigimonCharacter* NewTarget)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || bCareSequenceActive)
    {
        return;
    }

    if (NewTarget && (!ActivePartnerActor || !ActivePartnerActor->CombatComponent || !ActivePartnerActor->CombatComponent->CanAttackTarget(NewTarget)))
    {
        return;
    }

    CommandTarget = NewTarget;
    if (ActivePartnerActor && ActivePartnerActor->CombatComponent)
    {
        ActivePartnerActor->CombatComponent->SetAuthoritativeTarget(NewTarget);
    }
    OnCommandTargetChanged.Broadcast(CommandTarget);
}

void UDMFPlayerDigimonComponent::ServerCommandActivePartnerAbilitySlot_Implementation(const int32 SlotIndex, ADMFDigimonCharacter* RequestedTarget)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !ActivePartnerActor || !ActivePartnerActor->CombatComponent || bCareSequenceActive)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const double Now = GetWorld() ? static_cast<double>(GetWorld()->GetTimeSeconds()) : 0.0;
    const double MinimumInterval = Settings ? FMath::Max(0.0, static_cast<double>(Settings->MinimumCombatCommandInterval)) : 0.05;
    if (Now - LastAbilityCommandServerTime < MinimumInterval)
    {
        return;
    }
    LastAbilityCommandServerTime = Now;

    ADMFDigimonCharacter* EffectiveTarget = RequestedTarget ? RequestedTarget : CommandTarget.Get();
    if (EffectiveTarget && !ActivePartnerActor->CombatComponent->CanAttackTarget(EffectiveTarget))
    {
        if (CommandTarget == EffectiveTarget)
        {
            CommandTarget = nullptr;
            OnCommandTargetChanged.Broadcast(nullptr);
        }
        EffectiveTarget = ActivePartnerActor->CombatComponent->GetCurrentTarget();
        if (EffectiveTarget && !ActivePartnerActor->CombatComponent->CanAttackTarget(EffectiveTarget))
        {
            EffectiveTarget = nullptr;
        }
    }

    if (EffectiveTarget)
    {
        const bool bTargetChanged = CommandTarget != EffectiveTarget;
        CommandTarget = EffectiveTarget;
        ActivePartnerActor->CombatComponent->SetAuthoritativeTarget(EffectiveTarget);
        if (bTargetChanged)
        {
            OnCommandTargetChanged.Broadcast(CommandTarget);
        }
    }
    ActivePartnerActor->CombatComponent->QueueOrExecuteAbilitySlot(SlotIndex, EffectiveTarget);
}

void UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged(const int32 InCurrentHP, const int32 InCurrentSP)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !ActivePartnerInstanceId.IsValid())
    {
        return;
    }

    for (FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        if (Entry.Digimon.InstanceId == ActivePartnerInstanceId)
        {
            const bool bChanged = Entry.Digimon.CurrentHP != InCurrentHP || Entry.Digimon.CurrentSP != InCurrentSP;
            if (bChanged)
            {
                Entry.Digimon.CurrentHP = InCurrentHP;
                Entry.Digimon.CurrentSP = InCurrentSP;
                ReplicatedInventory.MarkItemDirty(Entry);
                OnDigimonInventoryChanged.Broadcast();

                // A defeat is a high-value persistence boundary; do not wait for the periodic autosave.
                if (InCurrentHP <= 0)
                {
                    PersistOwningPlayer();
                }
            }
            break;
        }
    }
}

void UDMFPlayerDigimonComponent::HandleAuthoritativeBattleVictory(ADMFDigimonCharacter* DefeatedDigimon)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !DefeatedDigimon || !ActivePartnerActor || DefeatedDigimon == ActivePartnerActor)
    {
        return;
    }

    UDMFDigimonSpeciesData* DefeatedSpecies = DefeatedDigimon->ResolveSpeciesData();
    if (!DefeatedSpecies)
    {
        return;
    }

    const int64 ExpReward = FMath::Max<int64>(0, DefeatedSpecies->BattleExperienceReward);
    const int64 MoneyReward = FMath::Max<int64>(0, DefeatedSpecies->BattleMoneyReward);
    for (FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        if (Entry.Digimon.InstanceId == ActivePartnerInstanceId)
        {
            Entry.Digimon.Stats.Experience = FMath::Max<int64>(0, Entry.Digimon.Stats.Experience + ExpReward);
            ReplicatedInventory.MarkItemDirty(Entry);
            break;
        }
    }

    Money = FMath::Max<int64>(0, Money + MoneyReward);
    if (CommandTarget == DefeatedDigimon)
    {
        CommandTarget = nullptr;
        OnCommandTargetChanged.Broadcast(nullptr);
    }
    OnDigimonInventoryChanged.Broadcast();
    OnMoneyChanged.Broadcast(Money);

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bEligibleWildVictory = !Settings || !Settings->bAwardScanDataFromWildVictoriesOnly || DefeatedDigimon->IsA<ADMFWildDigimonCharacter>();
    float ScanAdded = 0.0f;
    float NewScanPercent = GetScanPercent(DefeatedSpecies->GetPrimaryAssetId());
    bool bMaterializationReady = IsSpeciesReadyToMaterialize(DefeatedSpecies->GetPrimaryAssetId());
    if (bEligibleWildVictory && AwardScanDataForVictory(*DefeatedSpecies, ScanAdded, NewScanPercent, bMaterializationReady))
    {
        ClientScanDataRewardGranted(DefeatedSpecies->GetPrimaryAssetId(), ScanAdded, NewScanPercent, bMaterializationReady);
    }

    // Reward presentation is emitted through the owning-client RPC. This avoids double-firing
    // the Blueprint reward event for a listen-host player while still keeping all mutations server-side.
    ClientBattleRewardGranted(DefeatedDigimon->SpeciesId, ExpReward, MoneyReward);
    PersistOwningPlayer();
}

void UDMFPlayerDigimonComponent::ClientBattleRewardGranted_Implementation(const FPrimaryAssetId DefeatedSpeciesId, const int64 Experience, const int64 MoneyReward)
{
    OnBattleRewardGranted.Broadcast(DefeatedSpeciesId, Experience, MoneyReward);
}

void UDMFPlayerDigimonComponent::OnRep_CommandTarget()
{
    OnCommandTargetChanged.Broadcast(CommandTarget);
}

void UDMFPlayerDigimonComponent::OnRep_Money()
{
    OnMoneyChanged.Broadcast(Money);
}

void UDMFPlayerDigimonComponent::OnRep_ScanData()
{
    for (const FDMFScanDataEntry& Entry : ReplicatedScanData)
    {
        BroadcastScanState(Entry.SpeciesId);
    }
}

void UDMFPlayerDigimonComponent::OnRep_Inventory()
{
    OnDigimonInventoryChanged.Broadcast();
    if (const FDMFReplicatedDigimonEntry* ActiveEntry = FindInventoryEntry(ActivePartnerInstanceId))
    {
        BroadcastCareState(*ActiveEntry);
    }
}


bool UDMFPlayerDigimonComponent::GetActivePartnerCareState(FDMFDigimonCareState& OutCareState) const
{
    if (const FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(ActivePartnerInstanceId))
    {
        OutCareState = Entry->Digimon.Care;
        return true;
    }
    OutCareState = FDMFDigimonCareState();
    return false;
}

float UDMFPlayerDigimonComponent::GetSecondsUntilActivePartnerWaste() const
{
    const FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(ActivePartnerInstanceId);
    if (!Entry || Entry->Digimon.Care.NextWasteUtcTicks <= 0)
    {
        return -1.0f;
    }
    const FDateTime Due(Entry->Digimon.Care.NextWasteUtcTicks);
    const double Seconds = (Due - FDateTime::UtcNow()).GetTotalSeconds();
    return static_cast<float>(FMath::Max(0.0, Seconds));
}

FDMFReplicatedDigimonEntry* UDMFPlayerDigimonComponent::FindInventoryEntry(const FGuid InstanceId)
{
    return ReplicatedInventory.Items.FindByPredicate([&](const FDMFReplicatedDigimonEntry& Entry)
    {
        return Entry.Digimon.InstanceId == InstanceId;
    });
}

const FDMFReplicatedDigimonEntry* UDMFPlayerDigimonComponent::FindInventoryEntry(const FGuid InstanceId) const
{
    return ReplicatedInventory.Items.FindByPredicate([&](const FDMFReplicatedDigimonEntry& Entry)
    {
        return Entry.Digimon.InstanceId == InstanceId;
    });
}

bool UDMFPlayerDigimonComponent::NormalizeAndApplyCareDecay(FDMFReplicatedDigimonEntry& Entry, const UDMFDigimonSpeciesData& Species, const int64 NowUtcTicks)
{
    if (!Species.bCareEnabled)
    {
        return false;
    }

    FDMFDigimonCareState& Care = Entry.Digimon.Care;
    bool bChanged = false;

    // v0.7.x already serialized a dormant care struct whose legacy defaults were Hunger=0 / Fullness=100.
    // Detect that untouched shape once and migrate it to the new 0=empty,100=full Hunger semantics without
    // punishing existing accounts when they first load v0.8.0.
    const bool bLegacyDormantCare = Care.LastCareUpdateUtcTicks <= 0
        && Care.LastFedUtcTicks <= 0
        && Care.NextWasteUtcTicks <= 0
        && FMath::IsNearlyZero(Care.Hunger)
        && Care.Fullness >= 99.0f;
    if (bLegacyDormantCare)
    {
        Care.Hunger = FMath::Clamp(Care.Fullness, 0.0f, 100.0f);
        bChanged = true;
    }

    const float ClampedHunger = FMath::Clamp(Care.Hunger, 0.0f, 100.0f);
    bChanged |= ClampedHunger != Care.Hunger;
    Care.Hunger = ClampedHunger;
    const int64 EffectiveLastTicks = Care.LastCareUpdateUtcTicks > 0 && Care.LastCareUpdateUtcTicks <= NowUtcTicks
        ? Care.LastCareUpdateUtcTicks
        : NowUtcTicks;
    if (EffectiveLastTicks < NowUtcTicks && Species.HungerDecayPercentPerHour > 0.0f)
    {
        const FTimespan Elapsed = FDateTime(NowUtcTicks) - FDateTime(EffectiveLastTicks);
        const float Decay = static_cast<float>(Elapsed.GetTotalHours()) * FMath::Max(0.0f, Species.HungerDecayPercentPerHour);
        const float NewHunger = FMath::Clamp(Care.Hunger - Decay, 0.0f, 100.0f);
        bChanged |= NewHunger != Care.Hunger;
        Care.Hunger = NewHunger;
    }

    Care.LastCareUpdateUtcTicks = NowUtcTicks;
    if (!FMath::IsNearlyEqual(Care.Fullness, Care.Hunger, 0.001f))
    {
        Care.Fullness = Care.Hunger; // backwards-compatible mirror for existing Blueprint/save consumers
        bChanged = true;
    }
    const float ClampedHappiness = FMath::Clamp(Care.Happiness, 0.0f, 100.0f);
    const float ClampedDiscipline = FMath::Clamp(Care.Discipline, 0.0f, 100.0f);
    const int32 ClampedMistakes = FMath::Max(0, Care.CareMistakes);
    bChanged |= ClampedHappiness != Care.Happiness || ClampedDiscipline != Care.Discipline || ClampedMistakes != Care.CareMistakes;
    Care.Happiness = ClampedHappiness;
    Care.Discipline = ClampedDiscipline;
    Care.CareMistakes = ClampedMistakes;
    return bChanged;
}

void UDMFPlayerDigimonComponent::BroadcastCareState(const FDMFReplicatedDigimonEntry& Entry)
{
    OnCareStateChanged.Broadcast(Entry.Digimon.InstanceId, Entry.Digimon.Care);
}

void UDMFPlayerDigimonComponent::CareTick()
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableCareSystem || !ActivePartnerInstanceId.IsValid())
    {
        return;
    }

    // MMO scalability: only the currently active partner needs live Care replication. The rest of the
    // collection advances from its UTC timestamp during autosave/selection instead of generating a
    // per-player x per-slot network update every Care tick.
    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(ActivePartnerInstanceId);
    UDMFDigimonSpeciesData* Species = Entry ? ResolveSpeciesById(Entry->Digimon.SpeciesId) : nullptr;
    if (!Entry || !Species || !Species->bCareEnabled)
    {
        return;
    }

    const int64 NowUtcTicks = FDateTime::UtcNow().GetTicks();
    const int64 PreviousCareTicks = Entry->Digimon.Care.LastCareUpdateUtcTicks;
    const bool bCareChanged = NormalizeAndApplyCareDecay(*Entry, *Species, NowUtcTicks);
    if (bCareChanged || PreviousCareTicks <= 0)
    {
        ReplicatedInventory.MarkItemDirty(*Entry);
        BroadcastCareState(*Entry);
    }

    if (Entry->Digimon.Care.NextWasteUtcTicks > 0
        && Entry->Digimon.Care.NextWasteUtcTicks <= NowUtcTicks
        && !bCareSequenceActive
        && IsValid(ActivePartnerActor)
        && SpawnScheduledWaste(*Entry, *Species))
    {
        ReplicatedInventory.MarkItemDirty(*Entry);
        BroadcastCareState(*Entry);
        PersistOwningPlayer(); // waste is an externally visible one-shot event; crash-safe it immediately
    }
}

bool UDMFPlayerDigimonComponent::ValidateCareFeedingRequest(FDMFReplicatedDigimonEntry*& OutEntry, UDMFDigimonSpeciesData*& OutSpecies, FText& OutFailure)
{
    OutEntry = nullptr;
    OutSpecies = nullptr;
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableCareSystem)
    {
        OutFailure = NSLOCTEXT("DMF", "CareDisabled", "Digimon Care is disabled for this project.");
        return false;
    }
    if (bCareSequenceActive)
    {
        OutFailure = NSLOCTEXT("DMF", "CareAlreadyActive", "This Digimon is already being cared for.");
        return false;
    }
    if (!ActivePartnerInstanceId.IsValid() || !IsValid(ActivePartnerActor))
    {
        OutFailure = NSLOCTEXT("DMF", "CareNeedsSummonedPartner", "Summon your active partner before feeding DigiMeat.");
        return false;
    }

    OutEntry = FindInventoryEntry(ActivePartnerInstanceId);
    OutSpecies = OutEntry ? ResolveSpeciesById(OutEntry->Digimon.SpeciesId) : nullptr;
    if (!OutEntry || !OutSpecies || !OutSpecies->bCareEnabled)
    {
        OutFailure = NSLOCTEXT("DMF", "CareSpeciesUnavailable", "Care is not available for this Digimon species.");
        return false;
    }
    NormalizeAndApplyCareDecay(*OutEntry, *OutSpecies, FDateTime::UtcNow().GetTicks());
    if (OutEntry->Digimon.CurrentHP <= 0 || !ActivePartnerActor->CombatComponent || ActivePartnerActor->CombatComponent->IsDefeated())
    {
        OutFailure = NSLOCTEXT("DMF", "CarePartnerDefeated", "Heal this Digimon before feeding it.");
        return false;
    }
    if (OutEntry->Digimon.Care.Hunger >= 99.99f)
    {
        OutFailure = NSLOCTEXT("DMF", "CareAlreadyFull", "This Digimon is already full.");
        return false;
    }
    if (ActivePartnerActor->CombatComponent->GetCombatState() != EDMFCombatState::Idle || ActivePartnerActor->CombatComponent->GetCurrentTarget())
    {
        OutFailure = NSLOCTEXT("DMF", "CareInCombat", "Finish the current battle before feeding your Digimon.");
        return false;
    }
    if (OutSpecies->FeedingMontage.IsNull() || !OutSpecies->FeedingMontage.LoadSynchronous())
    {
        OutFailure = NSLOCTEXT("DMF", "CareMontageMissing", "This species needs a Feeding Montage before it can eat.");
        return false;
    }
    UStaticMesh* MeatMesh = !OutSpecies->DigiMeatMesh.IsNull() ? OutSpecies->DigiMeatMesh.LoadSynchronous() : Settings->DefaultDigiMeatMesh.LoadSynchronous();
    if (!MeatMesh)
    {
        OutFailure = NSLOCTEXT("DMF", "CareMeatMeshMissing", "Assign a DigiMeat mesh in the species or Digimon MMO Framework settings.");
        return false;
    }
    if (OutSpecies->DigiMeatHandSocketName.IsNone() || !ActivePartnerActor->GetMesh() || !ActivePartnerActor->GetMesh()->DoesSocketExist(OutSpecies->DigiMeatHandSocketName))
    {
        OutFailure = NSLOCTEXT("DMF", "CareSocketMissing", "The configured DigiMeat hand socket does not exist on this Digimon skeleton.");
        return false;
    }
    return true;
}

void UDMFPlayerDigimonComponent::ServerFeedActivePartnerUntilFull_Implementation()
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }
    FDMFReplicatedDigimonEntry* Entry = nullptr;
    UDMFDigimonSpeciesData* Species = nullptr;
    FText Failure;
    if (!ValidateCareFeedingRequest(Entry, Species, Failure))
    {
        ClientCareSequenceFinished(false, Failure, ActivePartnerInstanceId);
        return;
    }

    bCareSequenceActive = true;
    CareSequenceInstanceId = ActivePartnerInstanceId;
    bCareRestoreAutoBattle = ActivePartnerActor->CombatComponent->IsAutoBattleEnabled();
    bCareRestoreRetaliation = ActivePartnerActor->CombatComponent->IsRetaliationEnabled();
    ActivePartnerActor->CombatComponent->ConfigureRetaliation(false);
    ActivePartnerActor->CombatComponent->SetAuthoritativeTarget(nullptr);
    CommandTarget = nullptr;
    OnCommandTargetChanged.Broadcast(nullptr);

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
    ActivePartnerActor->ConfigureCombatAutomation(false,
        Settings ? Settings->PartnerAggroRange : 1200.0f,
        Settings ? Settings->PartnerLeashRange : 2500.0f,
        PC ? PC->GetPawn() : nullptr);
    if (AAIController* AI = Cast<AAIController>(ActivePartnerActor->GetController()))
    {
        AI->StopMovement();
    }
    ActivePartnerActor->StopCombatFacingTarget();
    if (GetOwner()) GetOwner()->ForceNetUpdate();
    ClientCareSequenceStarted(CareSequenceInstanceId);

    const float LeadIn = Settings ? FMath::Max(0.0f, Settings->CarePresentationLeadInSeconds) : 0.35f;
    if (LeadIn <= KINDA_SMALL_NUMBER)
    {
        BeginCareServing();
    }
    else
    {
        GetWorld()->GetTimerManager().SetTimer(CareSequenceTimer, this, &UDMFPlayerDigimonComponent::BeginCareServing, LeadIn, false);
    }
}

void UDMFPlayerDigimonComponent::ClientCareSequenceStarted_Implementation(const FGuid DigimonInstanceId)
{
    OnCareSequenceStarted.Broadcast(DigimonInstanceId);
}

void UDMFPlayerDigimonComponent::ClientCareSequenceFinished_Implementation(const bool bSuccess, const FText& Message, const FGuid DigimonInstanceId)
{
    OnCareSequenceFinished.Broadcast(bSuccess, Message, DigimonInstanceId);
}

void UDMFPlayerDigimonComponent::BeginCareServing()
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !bCareSequenceActive || !IsValid(ActivePartnerActor))
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CarePartnerLost", "Feeding stopped because the active partner is no longer available."));
        return;
    }
    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(CareSequenceInstanceId);
    UDMFDigimonSpeciesData* Species = Entry ? ResolveSpeciesById(Entry->Digimon.SpeciesId) : nullptr;
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Entry || !Species || !Settings)
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareDataLost", "Feeding stopped because the Digimon care data could not be resolved."));
        return;
    }
    if (Entry->Digimon.Care.Hunger >= 99.99f)
    {
        FinishCareSequence(true, NSLOCTEXT("DMF", "CareFeedComplete", "Your Digimon is full and happy with its meal."));
        return;
    }

    DestroyActiveCareMeat();
    UClass* PropClass = Settings->CarePropActorClass ? Settings->CarePropActorClass.Get() : ADMFDigimonCarePropActor::StaticClass();
    if (!PropClass || !PropClass->IsChildOf(ADMFDigimonCarePropActor::StaticClass())) PropClass = ADMFDigimonCarePropActor::StaticClass();
    FActorSpawnParameters Params;
    Params.Owner = GetOwner();
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ActiveCareDigiMeatActor = GetWorld()->SpawnActor<ADMFDigimonCarePropActor>(PropClass, ActivePartnerActor->GetActorTransform(), Params);
    if (!ActiveCareDigiMeatActor)
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareMeatSpawnFailed", "The DigiMeat presentation actor could not be created."));
        return;
    }
    ActiveCareDigiMeatActor->InitializeCareProp(Species->GetPrimaryAssetId(), EDMFCarePropType::DigiMeat);
    ActiveCareDigiMeatActor->AttachToComponent(ActivePartnerActor->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, Species->DigiMeatHandSocketName);
    ActiveCareDigiMeatActor->SetActorRelativeTransform(Species->DigiMeatRelativeTransform);

    CareMontagePlayIndex = 0;
    CareServingVoiceSoundIndex = Species->FeedingVoiceSounds.IsEmpty() ? INDEX_NONE : FMath::RandRange(0, Species->FeedingVoiceSounds.Num() - 1);
    PlayNextCareMontage();
}

void UDMFPlayerDigimonComponent::PlayNextCareMontage()
{
    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(CareSequenceInstanceId);
    UDMFDigimonSpeciesData* Species = Entry ? ResolveSpeciesById(Entry->Digimon.SpeciesId) : nullptr;
    if (!bCareSequenceActive || !Entry || !Species || !IsValid(ActivePartnerActor)
        || !ActivePartnerActor->CombatComponent || ActivePartnerActor->CombatComponent->IsDefeated())
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareInterrupted", "The feeding presentation was interrupted."));
        return;
    }

    const int32 Plays = FMath::Clamp(Species->FeedingMontagePlaysPerServing, 1, 8);
    if (CareMontagePlayIndex >= Plays)
    {
        CompleteCareServing();
        return;
    }

    UAnimMontage* FeedingMontage = Species->FeedingMontage.LoadSynchronous();
    if (!FeedingMontage)
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareMontageBecameInvalid", "The Feeding Montage is no longer available."));
        return;
    }

    const int32 VoiceIndex = CareMontagePlayIndex == 0 ? CareServingVoiceSoundIndex : INDEX_NONE;
    ActivePartnerActor->MulticastPlayCareFeedingCue(VoiceIndex);
    ++CareMontagePlayIndex;

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const float PlayRate = FMath::Max(0.05f, Species->FeedingMontagePlayRate);
    const float RawDuration = FeedingMontage->GetPlayLength() / PlayRate;
    const float Duration = RawDuration > KINDA_SMALL_NUMBER ? RawDuration : (Settings ? Settings->CareFallbackMontageDurationSeconds : 1.0f);
    GetWorld()->GetTimerManager().SetTimer(CareSequenceTimer, this, &UDMFPlayerDigimonComponent::PlayNextCareMontage, FMath::Max(0.05f, Duration), false);
}

void UDMFPlayerDigimonComponent::CompleteCareServing()
{
    DestroyActiveCareMeat();
    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(CareSequenceInstanceId);
    UDMFDigimonSpeciesData* Species = Entry ? ResolveSpeciesById(Entry->Digimon.SpeciesId) : nullptr;
    if (!Entry || !Species)
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareCompleteDataLost", "Feeding stopped because its care data became unavailable."));
        return;
    }

    const FDateTime Now = FDateTime::UtcNow();
    FDMFDigimonCareState& Care = Entry->Digimon.Care;
    Care.Hunger = FMath::Clamp(Care.Hunger + FMath::Max(0.1f, Species->DigiMeatHungerPercentPerServing), 0.0f, 100.0f);
    Care.Fullness = Care.Hunger;
    Care.LastFedUtcTicks = Now.GetTicks();
    Care.LastCareUpdateUtcTicks = Now.GetTicks();
    if (Species->bWasteEnabled && Care.NextWasteUtcTicks <= 0)
    {
        const float MinDelay = FMath::Max(1.0f, Species->MinimumWasteDelaySeconds);
        const float MaxDelay = FMath::Max(MinDelay, Species->MaximumWasteDelaySeconds);
        Care.NextWasteUtcTicks = (Now + FTimespan::FromSeconds(FMath::FRandRange(MinDelay, MaxDelay))).GetTicks();
    }
    ReplicatedInventory.MarkItemDirty(*Entry);
    BroadcastCareState(*Entry);
    PersistOwningPlayer();

    if (Care.Hunger >= 99.99f)
    {
        FinishCareSequence(true, NSLOCTEXT("DMF", "CareFeedComplete", "Your Digimon is full and the care state has been saved."));
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const float Pause = Settings ? FMath::Max(0.0f, Settings->CareInterServingPauseSeconds) : 0.20f;
    if (Pause <= KINDA_SMALL_NUMBER) BeginCareServing();
    else GetWorld()->GetTimerManager().SetTimer(CareSequenceTimer, this, &UDMFPlayerDigimonComponent::BeginCareServing, Pause, false);
}

void UDMFPlayerDigimonComponent::FinishCareSequence(const bool bSuccess, const FText& Message)
{
    if (UWorld* World = GetWorld()) World->GetTimerManager().ClearTimer(CareSequenceTimer);
    DestroyActiveCareMeat();
    const FGuid FinishedInstanceId = CareSequenceInstanceId;
    bCareSequenceActive = false;
    CareSequenceInstanceId.Invalidate();
    CareMontagePlayIndex = 0;
    CareServingVoiceSoundIndex = INDEX_NONE;

    if (IsValid(ActivePartnerActor) && ActivePartnerActor->CombatComponent)
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
        APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
        ActivePartnerActor->ConfigureCombatAutomation(
            bCareRestoreAutoBattle && Settings && Settings->bPlayerPartnerAutoBattle,
            Settings ? Settings->PartnerAggroRange : 1200.0f,
            Settings ? Settings->PartnerLeashRange : 2500.0f,
            PC ? PC->GetPawn() : nullptr);
        ActivePartnerActor->CombatComponent->ConfigureRetaliation(bCareRestoreRetaliation);
    }
    bCareRestoreAutoBattle = false;
    bCareRestoreRetaliation = false;
    if (GetOwner()) GetOwner()->ForceNetUpdate();
    ClientCareSequenceFinished(bSuccess, Message, FinishedInstanceId);
    CareTick();
}

void UDMFPlayerDigimonComponent::DestroyActiveCareMeat()
{
    if (IsValid(ActiveCareDigiMeatActor)) ActiveCareDigiMeatActor->Destroy();
    ActiveCareDigiMeatActor = nullptr;
}

bool UDMFPlayerDigimonComponent::SpawnScheduledWaste(FDMFReplicatedDigimonEntry& Entry, UDMFDigimonSpeciesData& Species)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !GetWorld() || !IsValid(ActivePartnerActor) || !Species.bWasteEnabled)
    {
        return false;
    }
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings) return false;

    UStaticMesh* WasteMesh = !Species.PooMesh.IsNull() ? Species.PooMesh.LoadSynchronous() : Settings->DefaultPooMesh.LoadSynchronous();
    if (!WasteMesh)
    {
        // Keep the timer overdue rather than silently consuming it; once a mesh is configured the next care tick succeeds.
        return false;
    }

    const FVector Origin = ActivePartnerActor->GetActorLocation();
    const FVector TraceStart = Origin + FVector(0.0, 0.0, 100.0);
    const FVector TraceEnd = Origin - FVector(0.0, 0.0, 750.0);
    FHitResult Hit;
    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(DMFCareWasteGroundTrace), false, ActivePartnerActor);
    ADMFPlayerState* OwnerPlayerState = Cast<ADMFPlayerState>(GetOwner());
    APlayerController* OwnerController = OwnerPlayerState ? Cast<APlayerController>(OwnerPlayerState->GetOwner()) : nullptr;
    if (APawn* OwnerPawn = OwnerController ? OwnerController->GetPawn() : nullptr)
    {
        QueryParams.AddIgnoredActor(OwnerPawn);
    }
    const bool bHitGround = GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, QueryParams);
    const FVector GroundNormal = bHitGround ? Hit.ImpactNormal.GetSafeNormal() : FVector::UpVector;
    const float CapsuleHalfHeight = ActivePartnerActor->GetCapsuleComponent() ? ActivePartnerActor->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() : 0.0f;
    const FVector FallbackGroundPoint = Origin - FVector(0.0, 0.0, CapsuleHalfHeight);
    const FVector SpawnLocation = (bHitGround ? Hit.ImpactPoint : FallbackGroundPoint) + GroundNormal * FMath::Max(0.0f, Species.PooGroundOffset);
    const FRotator SpawnRotation = FRotationMatrix::MakeFromZ(GroundNormal).Rotator();

    UClass* PropClass = Settings->CarePropActorClass ? Settings->CarePropActorClass.Get() : ADMFDigimonCarePropActor::StaticClass();
    if (!PropClass || !PropClass->IsChildOf(ADMFDigimonCarePropActor::StaticClass())) PropClass = ADMFDigimonCarePropActor::StaticClass();
    FActorSpawnParameters Params;
    Params.Owner = GetOwner();
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ADMFDigimonCarePropActor* WasteActor = GetWorld()->SpawnActor<ADMFDigimonCarePropActor>(PropClass, SpawnLocation, SpawnRotation, Params);
    if (!WasteActor) return false;

    WasteActor->InitializeCareProp(Species.GetPrimaryAssetId(), EDMFCarePropType::Waste);
    const FVector SafeScale(
        FMath::Max(0.01f, FMath::Abs(Species.PooWorldScale.X)),
        FMath::Max(0.01f, FMath::Abs(Species.PooWorldScale.Y)),
        FMath::Max(0.01f, FMath::Abs(Species.PooWorldScale.Z)));
    WasteActor->SetActorScale3D(SafeScale);
    WasteActor->SetLifeSpan(FMath::Max(1.0f, Species.PooLifetimeSeconds));

    const int32 FartIndex = Species.WasteFartSounds.IsEmpty() ? INDEX_NONE : FMath::RandRange(0, Species.WasteFartSounds.Num() - 1);
    ActivePartnerActor->MulticastPlayCareWasteCue(FartIndex);
    Entry.Digimon.Care.NextWasteUtcTicks = 0;
    return true;
}

void UDMFPlayerDigimonComponent::OnRep_CareSequenceActive()
{
    if (const FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(ActivePartnerInstanceId))
    {
        BroadcastCareState(*Entry);
    }
}

void UDMFPlayerDigimonComponent::OnRep_ActivePartnerInstanceId()
{
    OnDigimonInventoryChanged.Broadcast();
}

void UDMFPlayerDigimonComponent::OnRep_ActivePartnerActor()
{
    OnDigimonInventoryChanged.Broadcast();
}

void UDMFPlayerDigimonComponent::OnRep_StarterSelectionRequired()
{
    OnStarterRequirementChanged.Broadcast(bStarterSelectionRequired);
}
