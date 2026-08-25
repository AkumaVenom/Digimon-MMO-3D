#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DMFTypes.h"
#include "DMFPlayerDigimonComponent.generated.h"

class ADMFDigimonCharacter;
class ADMFPlayerState;
class UDMFDigimonCombatComponent;
class UDMFDigimonSpeciesData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDMFDigimonInventoryChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFStarterRequirementChanged, bool, bStarterRequired);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFStarterSelectionFinished, FGuid, NewPartnerInstanceId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFStarterSelectionResult, bool, bSuccess, FText, Message, FGuid, PartnerInstanceId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFCommandTargetChanged, ADMFDigimonCharacter*, NewTarget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFBattleRewardGranted, FPrimaryAssetId, DefeatedSpeciesId, int64, Experience, int64, Money);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFMoneyChanged, int64, NewMoney);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFPartnerActionResult, bool, bSuccess, FText, Message, FGuid, PartnerInstanceId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFPartyHealed, int32, DigimonHealed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFScanDataChanged, FPrimaryAssetId, SpeciesId, float, ScanPercent, bool, bMaterializationReady);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FDMFScanDataRewardGranted, FPrimaryAssetId, SpeciesId, float, AddedPercent, float, NewPercent, bool, bMaterializationReady);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FDMFMaterializationResult, bool, bSuccess, FText, Message, FPrimaryAssetId, SpeciesId, FGuid, NewDigimonInstanceId);

UCLASS(ClassGroup=(DigimonMMO), meta=(BlueprintSpawnableComponent))
class DIGIMONMMOFRAMEWORK_API UDMFPlayerDigimonComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDMFPlayerDigimonComponent();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Inventory")
    FDMFDigimonInventoryChanged OnDigimonInventoryChanged;

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

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Economy")
    FDMFMoneyChanged OnMoneyChanged;

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

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Inventory")
    TArray<FDMFDigimonInstance> GetDigimonInventory() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Inventory")
    bool GetDigimonByInstanceId(FGuid InstanceId, FDMFDigimonInstance& OutDigimon) const;

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

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Scan & Materialization")
    TArray<FDMFScanDataEntry> GetScanDataEntries() const { return ReplicatedScanData; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Scan & Materialization")
    float GetScanPercent(FPrimaryAssetId SpeciesId) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Scan & Materialization")
    bool IsSpeciesReadyToMaterialize(FPrimaryAssetId SpeciesId) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Scan & Materialization")
    int32 GetOwnedSpeciesCount(FPrimaryAssetId SpeciesId) const;

    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Scan & Materialization")
    void ServerMaterializeDigimon(FPrimaryAssetId SpeciesId);

    UFUNCTION(Client, Reliable)
    void ClientScanDataRewardGranted(FPrimaryAssetId SpeciesId, float AddedPercent, float NewPercent, bool bMaterializationReady);

    UFUNCTION(Client, Reliable)
    void ClientMaterializationResult(bool bSuccess, const FText& Message, FPrimaryAssetId SpeciesId, FGuid NewDigimonInstanceId);

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

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Onboarding|Admin")
    bool ResetStarterOnboarding(bool bRemoveStarterDigimon = true);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Persistence")
    void InitializeFromAccountRecord(const FDMFAccountRecord& Record);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Persistence")
    void ApplyToAccountRecord(UPARAM(ref) FDMFAccountRecord& Record) const;

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Partner")
    ADMFDigimonCharacter* SpawnOrRefreshActivePartner(APawn* PlayerPawn);

    UPROPERTY(ReplicatedUsing=OnRep_ActivePartnerActor, BlueprintReadOnly, Category="Digimon MMO|Partner")
    TObjectPtr<ADMFDigimonCharacter> ActivePartnerActor;

private:
    UPROPERTY(ReplicatedUsing=OnRep_Inventory)
    FDMFReplicatedDigimonList ReplicatedInventory;

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

    FTimerHandle AutosaveTimer;
    double LastAbilityCommandServerTime = -1000.0;

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
    void OnRep_ActivePartnerInstanceId();

    UFUNCTION()
    void OnRep_ActivePartnerActor();

    UFUNCTION()
    void OnRep_StarterSelectionRequired();

    bool ResolveStarterSpecies(FPrimaryAssetId StarterSpeciesId, class UDMFDigimonSpeciesData*& OutSpecies) const;
    UDMFDigimonSpeciesData* ResolveSpeciesById(FPrimaryAssetId SpeciesId) const;
    FDMFDigimonInstance BuildStarterInstance(const UDMFDigimonSpeciesData& Species) const;
    FDMFDigimonInstance BuildMaterializedInstance(const UDMFDigimonSpeciesData& Species) const;
    bool AwardScanDataForVictory(const UDMFDigimonSpeciesData& Species, float& OutAddedPercent, float& OutNewPercent, bool& bOutReady);
    void BroadcastScanState(FPrimaryAssetId SpeciesId);
    void PersistOwningPlayer();
};
