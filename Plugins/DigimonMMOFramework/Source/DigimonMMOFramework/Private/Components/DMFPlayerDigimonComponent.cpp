#include "Components/DMFPlayerDigimonComponent.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Data/DMFStarterRosterData.h"
#include "Game/DMFDigimonCharacter.h"
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
#include "Engine/World.h"
#include "Engine/AssetManager.h"
#include "TimerManager.h"

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
    }
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
    for (const FDMFDigimonInstance& Digimon : Record.DigimonInventory)
    {
        FDMFReplicatedDigimonEntry& NewEntry = ReplicatedInventory.Items.AddDefaulted_GetRef();
        NewEntry.Digimon = Digimon;
        ReplicatedInventory.MarkItemDirty(NewEntry);
    }
    ReplicatedInventory.MarkArrayDirty();

    ActivePartnerInstanceId = Record.ActivePartnerInstanceId;
    Money = Record.Money;
    ReplicatedScanData = Record.ScanData;
    bStarterSelectionRequired = !Record.bStarterSelected || !ActivePartnerInstanceId.IsValid();

    OnDigimonInventoryChanged.Broadcast();
    OnStarterRequirementChanged.Broadcast(bStarterSelectionRequired);
    for (const FDMFScanDataEntry& ScanEntry : ReplicatedScanData)
    {
        BroadcastScanState(ScanEntry.SpeciesId);
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

    return ActivePartnerActor;
}

void UDMFPlayerDigimonComponent::ServerSetActivePartner_Implementation(const FGuid InstanceId, const bool bSummonNow)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !InstanceId.IsValid())
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
    if (!GetOwner() || !GetOwner()->HasAuthority())
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
    if (!GetOwner() || !GetOwner()->HasAuthority() || !ActivePartnerActor)
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
    if (!GetOwner() || !GetOwner()->HasAuthority())
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
    if (!GetOwner() || !GetOwner()->HasAuthority() || !ActivePartnerActor || !ActivePartnerActor->CombatComponent)
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
