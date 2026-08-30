#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DMFTypes.h"
#include "DMFPlayerDigimonComponent.generated.h"

class ADMFDigimonCharacter;
class ADMFDigimonCarePropActor;
class ADMFPlayerState;
class UDMFDigimonCombatComponent;
class UDMFDigimonSpeciesData;
class UDMFItemData;
struct FDMFDigivolutionRequirement;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDMFDigimonInventoryChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDMFDigimonBankChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FDMFDigimonStorageActionResult, bool, bSuccess, FText, Message, FGuid, DigimonInstanceId, EDMFDigimonStorageLocation, NewLocation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFStarterRequirementChanged, bool, bStarterRequired);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFStarterSelectionFinished, FGuid, NewPartnerInstanceId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFStarterSelectionResult, bool, bSuccess, FText, Message, FGuid, PartnerInstanceId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFCommandTargetChanged, ADMFDigimonCharacter*, NewTarget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFBattleRewardGranted, FPrimaryAssetId, DefeatedSpeciesId, int64, Experience, int64, Money);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFDigimonExperienceProgressed, FDMFDigimonExperienceProgression, Progression);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FDMFAttributePointSpendResult, bool, bSuccess, FText, Message, FGuid, DigimonInstanceId, EDMFDigimonAttributeStat, Stat, int32, NewStatValue, int32, RemainingPoints);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFMoneyChanged, int64, NewMoney);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDMFItemInventoryChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FDMFItemUseResult, bool, bSuccess, FText, Message, FGuid, StackId, FPrimaryAssetId, ItemAssetId, FGuid, DigimonInstanceId, int32, RemainingQuantity, int32, RestoredAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFPartnerActionResult, bool, bSuccess, FText, Message, FGuid, PartnerInstanceId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFPartyHealed, int32, DigimonHealed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFScanDataChanged, FPrimaryAssetId, SpeciesId, float, ScanPercent, bool, bMaterializationReady);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FDMFScanDataRewardGranted, FPrimaryAssetId, SpeciesId, float, AddedPercent, float, NewPercent, bool, bMaterializationReady);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FDMFMaterializationResult, bool, bSuccess, FText, Message, FPrimaryAssetId, SpeciesId, FGuid, NewDigimonInstanceId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFCareStateChanged, FGuid, DigimonInstanceId, FDMFDigimonCareState, CareState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFCareSequenceStarted, FGuid, DigimonInstanceId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFCareSequenceFinished, bool, bSuccess, FText, Message, FGuid, DigimonInstanceId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FDMFDigivolutionResult, bool, bSuccess, FText, Message, FGuid, DigimonInstanceId, FPrimaryAssetId, PreviousSpeciesId, FPrimaryAssetId, NewSpeciesId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFDigivolutionSequenceStarted, FGuid, DigimonInstanceId, FPrimaryAssetId, PreviousSpeciesId, FPrimaryAssetId, TargetSpeciesId);

UCLASS(ClassGroup=(DigimonMMO), meta=(BlueprintSpawnableComponent))
class DIGIMONMMOFRAMEWORK_API UDMFPlayerDigimonComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDMFPlayerDigimonComponent();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    /** Backward-compatible active-roster delegate. In v0.12+ the active inventory is the Party. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Party")
    FDMFDigimonInventoryChanged OnDigimonInventoryChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Bank")
    FDMFDigimonBankChanged OnDigimonBankChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Party & Bank")
    FDMFDigimonStorageActionResult OnDigimonStorageActionResult;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Onboarding")
    FDMFStarterRequirementChanged OnStarterRequirementChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Onboarding")
    FDMFStarterSelectionFinished OnStarterSelectionFinished;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Onboarding")
    FDMFStarterSelectionResult OnStarterSelectionResult;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Combat")
    FDMFCommandTargetChanged OnCommandTargetChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Combat")
    FDMFBattleRewardGranted OnBattleRewardGranted;

    /** Owner-only presentation signal emitted from the authoritative EXP result RPC. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Progression")
    FDMFDigimonExperienceProgressed OnDigimonExperienceProgressed;

    /** Owner-only result for an authoritative Attribute Point spend request. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Progression|Attributes")
    FDMFAttributePointSpendResult OnAttributePointSpendResult;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Economy")
    FDMFMoneyChanged OnMoneyChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Items")
    FDMFItemInventoryChanged OnItemInventoryChanged;

    /** Owner-only authoritative item-use feedback. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Items")
    FDMFItemUseResult OnItemUseResult;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Partner")
    FDMFPartnerActionResult OnPartnerActionResult;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Healing")
    FDMFPartyHealed OnPartyHealed;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Scan & Materialization")
    FDMFScanDataChanged OnScanDataChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Scan & Materialization")
    FDMFScanDataRewardGranted OnScanDataRewardGranted;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Scan & Materialization")
    FDMFMaterializationResult OnMaterializationResult;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Care")
    FDMFCareStateChanged OnCareStateChanged;

    /** Owner-only presentation event. The controller hides the Digimon menu before the first eating Montage. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Care")
    FDMFCareSequenceStarted OnCareSequenceStarted;

    /** Owner-only result. Successful sequences reopen the shared menu directly on CARE. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Care")
    FDMFCareSequenceFinished OnCareSequenceFinished;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Digivolution")
    FDMFDigivolutionResult OnDigivolutionResult;

    /** Owner-only world-presentation signal used to hide modal HUD while the summoned partner transforms. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Digivolution")
    FDMFDigivolutionSequenceStarted OnDigivolutionSequenceStarted;

    /** Backward-compatible alias for GetPartyDigimon(). */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Party")
    TArray<FDMFDigimonInstance> GetDigimonInventory() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Party")
    TArray<FDMFDigimonInstance> GetPartyDigimon() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Bank")
    TArray<FDMFDigimonInstance> GetBankDigimon() const;

    /** Party-only compatibility lookup used by existing combat/partner code. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Party")
    bool GetDigimonByInstanceId(FGuid InstanceId, FDMFDigimonInstance& OutDigimon) const;

    /** Searches both Party and Bank and reports the authoritative owner-storage location. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Party & Bank")
    bool GetOwnedDigimonByInstanceId(FGuid InstanceId, FDMFDigimonInstance& OutDigimon, EDMFDigimonStorageLocation& OutLocation) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Party")
    int32 GetPartyCapacity() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Bank")
    int32 GetBankCapacity() const;

    /** Moves a Bank Digimon into a Party slot. Occupied slots swap atomically back into Bank. INDEX_NONE uses the first free slot. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Party & Bank")
    void ServerMoveBankDigimonToParty(FGuid InstanceId, int32 PartySlotIndex = -1, bool bSummonIfBecomesActive = true);

    /** Deposits a Party Digimon into Bank. The final remaining Party member cannot be deposited. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Party & Bank")
    void ServerMovePartyDigimonToBank(FGuid InstanceId);

    /** Reorders two Party slots without changing ownership/storage. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Party & Bank")
    void ServerSwapPartySlots(int32 FirstPartySlotIndex, int32 SecondPartySlotIndex);

    UFUNCTION(Client, Reliable)
    void ClientDigimonStorageActionResult(bool bSuccess, const FText& Message, FGuid DigimonInstanceId, EDMFDigimonStorageLocation NewLocation);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Partner")
    FGuid GetActivePartnerInstanceId() const { return ActivePartnerInstanceId; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Partner")
    bool IsActivePartnerSummoned() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Onboarding")
    bool IsStarterSelectionRequired() const { return bStarterSelectionRequired; }

    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Onboarding")
    void ServerSelectStarter(FPrimaryAssetId StarterSpeciesId);

    UFUNCTION(Client, Reliable)
    void ClientStarterSelectionResult(bool bSuccess, const FText& Message, FGuid PartnerInstanceId);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    ADMFDigimonCharacter* GetCommandTarget() const { return CommandTarget; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Economy")
    int64 GetMoney() const { return Money; }

    /** Private owner item bag. Fast-array replication sends only changed stacks to the owning connection. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Items")
    TArray<FDMFItemStack> GetItemInventory() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Items")
    int32 GetItemInventoryCapacity() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Items")
    int32 GetTotalItemQuantity(FPrimaryAssetId ItemAssetId) const;

    /** Maximum additional units of this item that can fit using partial stacks plus free stack slots. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Items")
    int32 GetAvailableItemCapacity(FPrimaryAssetId ItemAssetId) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Items")
    bool CanStoreItemQuantity(FPrimaryAssetId ItemAssetId, int32 Quantity) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Items|Data")
    UDMFItemData* ResolveItemData(FPrimaryAssetId ItemAssetId) const;

    /** Authority-only grant hook for future vendors, drops, quest rewards and admin/gameplay systems. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Items")
    bool GrantItem(FPrimaryAssetId ItemAssetId, int32 Quantity, int32& OutGrantedQuantity, FText& OutFailureReason);

    /** Authority-only removal hook for future shops/crafting/quests. Removes across matching stacks atomically. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Items")
    bool RemoveItem(FPrimaryAssetId ItemAssetId, int32 Quantity, FText& OutFailureReason);

    /** Uses exactly one server-resolved item from a server-owned stack on one server-owned Digimon. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Items")
    void ServerUseItem(FGuid StackId, FGuid TargetDigimonInstanceId);

    UFUNCTION(Client, Reliable)
    void ClientItemUseResult(bool bSuccess, const FText& Message, FGuid StackId, FPrimaryAssetId ItemAssetId, FGuid DigimonInstanceId, int32 RemainingQuantity, int32 RestoredAmount);

    /** Server-only atomic vendor purchase. Price and offered Digimon are supplied only by the authoritative vendor actor. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Economy|Vendor")
    bool AuthorityPurchaseVendorDigimon(const FDMFDigimonInstance& OfferedDigimon, int64 PurchasePrice, bool bPreferBank, FGuid& OutNewInstanceId, EDMFDigimonStorageLocation& OutDestination, FText& OutFailureReason);

    /** Server-only atomic vendor sale. Removes the exact owned individual, credits money, reconciles the active partner, and persists immediately. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Economy|Vendor")
    bool AuthoritySellDigimonToVendor(FGuid DigimonInstanceId, int64 SalePrice, bool bAllowStarterSale, bool bRequireAtLeastOnePartyDigimon, FDMFDigimonInstance& OutSoldDigimon, FText& OutFailureReason);

    /** Atomic item-vendor purchase: preflights BITS + complete stack capacity, grants quantity, charges once, then saves once. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Economy|Item Vendor")
    bool AuthorityPurchaseVendorItem(FPrimaryAssetId ItemAssetId, int32 Quantity, int64 TotalPrice, FText& OutFailureReason);

    /** Atomic item-vendor sale: protects Key/Quest items, removes the exact quantity across stacks, credits BITS and saves once. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Economy|Item Vendor")
    bool AuthoritySellItemToVendor(FPrimaryAssetId ItemAssetId, int32 Quantity, int64 TotalPrice, FText& OutFailureReason);

    /** Returns the authored/fallback EXP requirement to advance from CurrentLevel to CurrentLevel + 1. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Progression")
    int64 GetExperienceRequiredForLevel(FPrimaryAssetId SpeciesId, int32 CurrentLevel) const;

    /** Returns the effective global/species level cap. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Progression")
    int32 GetMaximumLevelForSpecies(FPrimaryAssetId SpeciesId) const;

    /** Returns zero at max level or when InstanceId is not owned. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Progression")
    int64 GetExperienceRequiredForNextLevel(FGuid InstanceId) const;

    /** Current-level EXP progress in [0,1]. Max-level Digimon return 1. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Progression")
    float GetExperienceProgressNormalized(FGuid InstanceId) const;

    /** Local/read-only convenience check. The server repeats every ownership/point/stat validation before mutation. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Progression|Attributes")
    bool CanSpendDigimonAttributePoint(FGuid InstanceId, EDMFDigimonAttributeStat Stat, FText& OutFailureReason) const;

    /** Spends exactly one earned Attribute Point on one persistent core stat. Works for Party and Bank Digimon. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Progression|Attributes")
    void ServerSpendDigimonAttributePoint(FGuid InstanceId, EDMFDigimonAttributeStat Stat);

    /** Owning-client result only; gameplay mutation has already been committed by the server. */
    UFUNCTION(Client, Reliable)
    void ClientAttributePointSpendResult(bool bSuccess, const FText& Message, FGuid DigimonInstanceId, EDMFDigimonAttributeStat Stat, int32 NewStatValue, int32 RemainingPoints);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Scan & Materialization")
    TArray<FDMFScanDataEntry> GetScanDataEntries() const { return ReplicatedScanData; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Scan & Materialization")
    float GetScanPercent(FPrimaryAssetId SpeciesId) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Scan & Materialization")
    bool IsSpeciesReadyToMaterialize(FPrimaryAssetId SpeciesId) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Scan & Materialization")
    int32 GetOwnedSpeciesCount(FPrimaryAssetId SpeciesId) const;

    /** Resolves a species through Asset Manager, starter roster, or the recursively linked Digivolution graph. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Digivolution|Data")
    UDMFDigimonSpeciesData* ResolveDigimonSpecies(FPrimaryAssetId SpeciesId) const;

    /** Evaluates every configured path on this individual's current species. No client-authored mutation occurs here. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Digivolution")
    TArray<FDMFDigivolutionEvaluation> GetDigivolutionOptions(FGuid InstanceId) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Digivolution")
    bool CanDigivolveOwnedDigimonTo(FGuid InstanceId, FPrimaryAssetId TargetSpeciesId, FText& OutFailureReason) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Digivolution")
    bool IsDigivolutionSequenceActive() const { return bDigivolutionSequenceActive; }

    /** Server-authoritative one-way Digivolution. Party and Bank instances use the same persistent individual GUID. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Digivolution")
    void ServerDigivolveOwnedDigimon(FGuid InstanceId, FPrimaryAssetId TargetSpeciesId);

    /** Sent only when a currently summoned active partner needs an in-world transformation presentation. */
    UFUNCTION(Client, Reliable)
    void ClientDigivolutionSequenceStarted(FGuid DigimonInstanceId, FPrimaryAssetId PreviousSpeciesId, FPrimaryAssetId TargetSpeciesId);

    UFUNCTION(Client, Reliable)
    void ClientDigivolutionResult(bool bSuccess, const FText& Message, FGuid DigimonInstanceId, FPrimaryAssetId PreviousSpeciesId, FPrimaryAssetId NewSpeciesId);

    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Scan & Materialization")
    void ServerMaterializeDigimon(FPrimaryAssetId SpeciesId);

    UFUNCTION(Client, Reliable)
    void ClientScanDataRewardGranted(FPrimaryAssetId SpeciesId, float AddedPercent, float NewPercent, bool bMaterializationReady);

    UFUNCTION(Client, Reliable)
    void ClientMaterializationResult(bool bSuccess, const FText& Message, FPrimaryAssetId SpeciesId, FGuid NewDigimonInstanceId);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Care")
    bool GetActivePartnerCareState(FDMFDigimonCareState& OutCareState) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Care")
    bool IsCareSequenceActive() const { return bCareSequenceActive; }

    /** Returns -1 when no waste is scheduled; otherwise seconds until due (0 when overdue and waiting for a summoned partner). */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Care")
    float GetSecondsUntilActivePartnerWaste() const;

    /** Server-authoritative unlimited-DigiMeat loop. Each serving plays the species Feeding Montage twice by default. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Care")
    void ServerFeedActivePartnerUntilFull();

    UFUNCTION(Client, Reliable)
    void ClientCareSequenceStarted(FGuid DigimonInstanceId);

    UFUNCTION(Client, Reliable)
    void ClientCareSequenceFinished(bool bSuccess, const FText& Message, FGuid DigimonInstanceId);

    /** Sets an owned Digimon as active and optionally summons it beside the player's pawn. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Partner")
    void ServerSetActivePartner(FGuid InstanceId, bool bSummonNow);

    /** Dismisses the currently spawned partner actor but keeps the selected active partner in the account. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Partner")
    void ServerRecallActivePartner();

    /** Runtime opt-in/out for autonomous player-partner target acquisition. Default project setting is OFF. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Partner|Combat")
    void ServerSetActivePartnerAutoBattle(bool bEnabled);

    UFUNCTION(Client, Reliable)
    void ClientPartnerActionResult(bool bSuccess, const FText& Message, FGuid PartnerInstanceId);

    /** Fully restores owned Digimon according to the healer policy and persists the result immediately. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Healing")
    int32 HealAllOwnedDigimon(bool bHealHP = true, bool bHealSP = true, bool bRestoreDefeated = true, bool bIncludeBankStorage = true);

    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Combat")
    void ServerSetCommandTarget(ADMFDigimonCharacter* NewTarget);

    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Combat")
    void ServerCommandActivePartnerAbilitySlot(int32 SlotIndex, ADMFDigimonCharacter* RequestedTarget);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    void HandleAuthoritativeBattleVictory(ADMFDigimonCharacter* DefeatedDigimon);

    UFUNCTION(Client, Reliable)
    void ClientBattleRewardGranted(FPrimaryAssetId DefeatedSpeciesId, int64 Experience, int64 MoneyReward);

    /** Dedicated owning-client progression snapshot; avoids relying on Fast Array vs RPC arrival order for animated UI. */
    UFUNCTION(Client, Reliable)
    void ClientDigimonExperienceProgressed(FDMFDigimonExperienceProgression Progression);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Onboarding|Admin")
    bool ResetStarterOnboarding(bool bRemoveStarterDigimon = true);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Persistence")
    void InitializeFromAccountRecord(const FDMFAccountRecord& Record);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Persistence")
    void ApplyToAccountRecord(UPARAM(ref) FDMFAccountRecord& Record) const;

    /**
     * Internal server lifecycle guard. True only after InitializeFromAccountRecord has populated the
     * authoritative Party/Bank/avatar-linked runtime for this login. Disconnect persistence must never
     * serialize component defaults over an established account before this becomes true.
     */
    bool HasAuthoritativeAccountStateInitialized() const { return bAuthoritativeAccountStateInitialized; }
    bool IsDisconnectPersistenceFinalized() const { return bDisconnectPersistenceFinalized; }

    /** Copies the currently spawned partner's live combat vitals into its persistent Party instance. Authority only. */
    void SynchronizeActivePartnerRuntimeForPersistence();

    /**
     * Completes the presentation/actor side of an owner disconnect. If bPersistenceCommitted is true,
     * EndPlay is prevented from issuing a second teardown-time account write. The selected partner GUID
     * is intentionally preserved; only the transient world actor is destroyed.
     */
    void FinalizeForOwnerDisconnect(bool bPersistenceCommitted);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Partner")
    ADMFDigimonCharacter* SpawnOrRefreshActivePartner(APawn* PlayerPawn);

    UPROPERTY(ReplicatedUsing=OnRep_ActivePartnerActor, BlueprintReadOnly, Category="Digimon MMO|Partner")
    TObjectPtr<ADMFDigimonCharacter> ActivePartnerActor;

private:
    /** Owner-only active Party. Kept under the historical ReplicatedInventory name for source/API compatibility. */
    UPROPERTY(ReplicatedUsing=OnRep_Inventory)
    FDMFReplicatedDigimonList ReplicatedInventory;

    /** Owner-only persistent Bank/Box storage. */
    UPROPERTY(ReplicatedUsing=OnRep_Bank)
    FDMFReplicatedDigimonList ReplicatedBank;

    /** Private owner-only persistent player item bag. */
    UPROPERTY(ReplicatedUsing=OnRep_ItemInventory)
    FDMFReplicatedItemList ReplicatedItemInventory;

    UPROPERTY(ReplicatedUsing=OnRep_ActivePartnerInstanceId)
    FGuid ActivePartnerInstanceId;

    UPROPERTY(ReplicatedUsing=OnRep_StarterSelectionRequired)
    bool bStarterSelectionRequired = false;

    UPROPERTY(ReplicatedUsing=OnRep_CommandTarget)
    TObjectPtr<ADMFDigimonCharacter> CommandTarget;

    UPROPERTY(ReplicatedUsing=OnRep_Money)
    int64 Money = 0;

    UPROPERTY(ReplicatedUsing=OnRep_ScanData)
    TArray<FDMFScanDataEntry> ReplicatedScanData;

    UPROPERTY(ReplicatedUsing=OnRep_CareSequenceActive)
    bool bCareSequenceActive = false;

    UPROPERTY(Replicated)
    FGuid CareSequenceInstanceId;

    UPROPERTY(Replicated)
    bool bDigivolutionSequenceActive = false;

    UPROPERTY(Replicated)
    FGuid DigivolutionSequenceInstanceId;

    UPROPERTY(Replicated)
    FPrimaryAssetId DigivolutionSequenceTargetSpeciesId;

    UPROPERTY(Transient)
    TObjectPtr<ADMFDigimonCarePropActor> ActiveCareDigiMeatActor;

    FTimerHandle AutosaveTimer;
    FTimerHandle CareTickTimer;
    FTimerHandle CareSequenceTimer;
    FTimerHandle DigivolutionSequenceTimer;
    double LastAbilityCommandServerTime = -1000.0;
    int32 CareMontagePlayIndex = 0;
    int32 CareServingVoiceSoundIndex = INDEX_NONE;
    bool bCareRestoreAutoBattle = false;
    bool bCareRestoreRetaliation = false;

    /** Set only after authoritative account data has been loaded into this component for the current session. */
    bool bAuthoritativeAccountStateInitialized = false;
    /** Prevents a successful GameMode logout checkpoint from being overwritten during component teardown. */
    bool bDisconnectPersistenceFinalized = false;

    UFUNCTION()
    void OnRep_CommandTarget();

    UFUNCTION()
    void OnRep_Money();

    UFUNCTION()
    void OnRep_ScanData();

    UFUNCTION()
    void HandleActivePartnerVitalsChanged(int32 CurrentHP, int32 CurrentSP);

    UFUNCTION()
    void OnRep_Inventory();

    UFUNCTION()
    void OnRep_Bank();

    UFUNCTION()
    void OnRep_ItemInventory();

    UFUNCTION()
    void OnRep_ActivePartnerInstanceId();

    UFUNCTION()
    void OnRep_ActivePartnerActor();

    UFUNCTION()
    void OnRep_StarterSelectionRequired();

    UFUNCTION()
    void OnRep_CareSequenceActive();

    bool ResolveStarterSpecies(FPrimaryAssetId StarterSpeciesId, class UDMFDigimonSpeciesData*& OutSpecies) const;
    UDMFDigimonSpeciesData* ResolveSpeciesById(FPrimaryAssetId SpeciesId) const;
    const FDMFDigivolutionRequirement* FindDigivolutionPath(const UDMFDigimonSpeciesData& SourceSpecies, FPrimaryAssetId TargetSpeciesId, UDMFDigimonSpeciesData*& OutTargetSpecies) const;
    bool EvaluateDigivolutionRequirement(const FDMFDigimonInstance& Digimon, EDMFDigimonStorageLocation Location, const FDMFDigivolutionRequirement& Requirement, const UDMFDigimonSpeciesData& SourceSpecies, const UDMFDigimonSpeciesData& TargetSpecies, FText& OutFailure, FText* OutSummary = nullptr) const;
    bool ApplyDigivolutionMutation(FDMFReplicatedDigimonEntry& Entry, const UDMFDigimonSpeciesData& SourceSpecies, const UDMFDigimonSpeciesData& TargetSpecies, const FDMFDigivolutionRequirement& Requirement);
    int64 ResolveExperienceRequirement(const UDMFDigimonSpeciesData& Species, int32 CurrentLevel) const;
    int32 ResolveMaximumLevel(const UDMFDigimonSpeciesData& Species) const;
    bool ApplyExperienceReward(FDMFReplicatedDigimonEntry& Entry, int64 ExperienceReward, FDMFDigimonExperienceProgression& OutProgression) const;
    bool NormalizeStoredExperienceForLeveling(FDMFDigimonInstance& Digimon) const;
    void ApplyLevelGrowth(FDMFDigimonInstance& Digimon, const UDMFDigimonSpeciesData& Species, int32 LevelsGained, int32& OutAttributePointsGained) const;
    void CompleteDigivolutionSequence();
    void NormalizeDigivolutionProvenance(FDMFDigimonInstance& Digimon) const;
    FDMFDigimonInstance BuildStarterInstance(const UDMFDigimonSpeciesData& Species) const;
    FDMFDigimonInstance BuildMaterializedInstance(const UDMFDigimonSpeciesData& Species) const;
    bool AwardScanDataForVictory(const UDMFDigimonSpeciesData& Species, float& OutAddedPercent, float& OutNewPercent, bool& bOutReady);
    void BroadcastScanState(FPrimaryAssetId SpeciesId);

    FDMFReplicatedDigimonEntry* FindInventoryEntry(FGuid InstanceId);
    const FDMFReplicatedDigimonEntry* FindInventoryEntry(FGuid InstanceId) const;
    FDMFReplicatedDigimonEntry* FindBankEntry(FGuid InstanceId);
    const FDMFReplicatedDigimonEntry* FindBankEntry(FGuid InstanceId) const;
    FDMFReplicatedItemEntry* FindItemStack(FGuid StackId);
    const FDMFReplicatedItemEntry* FindItemStack(FGuid StackId) const;
    bool ConsumeItemStackQuantity(FDMFReplicatedItemEntry& Entry, int32 Quantity);
    bool IsPartyMutationAllowed(FText& OutFailure) const;
    void ReconcileActivePartnerAfterPartyMutation(FGuid PreviousActivePartnerId, bool bWasSummoned);
    void MarkPartyAndBankChanged(bool bPartyChanged, bool bBankChanged);
    bool NormalizeAndApplyCareDecay(FDMFReplicatedDigimonEntry& Entry, const UDMFDigimonSpeciesData& Species, int64 NowUtcTicks);
    void BroadcastCareState(const FDMFReplicatedDigimonEntry& Entry);
    void CareTick();
    bool ValidateCareFeedingRequest(FDMFReplicatedDigimonEntry*& OutEntry, UDMFDigimonSpeciesData*& OutSpecies, FText& OutFailure);
    void BeginCareServing();
    void PlayNextCareMontage();
    void CompleteCareServing();
    void FinishCareSequence(bool bSuccess, const FText& Message);
    void DestroyActiveCareMeat();
    bool SpawnScheduledWaste(FDMFReplicatedDigimonEntry& Entry, UDMFDigimonSpeciesData& Species);

    void PersistOwningPlayer();
};
