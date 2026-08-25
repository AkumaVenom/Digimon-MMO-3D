#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DMFMMOPlayerController.generated.h"

class UDMFStarterSelectionWidget;
class UDMFCombatQuickBarWidget;
class UDMFPlayerSkinSelectionWidget;
class UDMFDigimonInventoryWidget;
class UDMFScanNotificationWidget;
class ADMFDigimonCharacter;
class ADMFHealerActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFHealerInteractionResult, bool, bSuccess, FText, Message, int32, DigimonHealed);

/**
 * MMO player controller with ready-to-use onboarding, avatar skin and Digimon combat UI routing.
 * Public menu/command functions are Blueprint-callable so projects can replace the default F6/I/combat bindings.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFMMOPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    /** Requests the authoritative GameMode to validate/recover this controller's MMO avatar possession. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Networking|Player Spawn")
    void ServerEnsureFrameworkPlayerAvatar();

    /** True only when this controller currently possesses a DMF player-avatar pawn. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Networking|Player Spawn")
    bool IsFrameworkPlayerAvatarPossessed() const;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI")
    void RefreshStarterSelectionUI();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|UI")
    void OpenPlayerSkinSelectionUI();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|UI")
    void ClosePlayerSkinSelectionUI();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|UI")
    void TogglePlayerSkinSelectionUI();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|UI")
    void RefreshPlayerSkinSelectionUI();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|UI")
    bool IsPlayerSkinSelectionUIOpen() const { return PlayerSkinWidget != nullptr; }

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Inventory|UI")
    void OpenDigimonInventoryUI();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Inventory|UI")
    void CloseDigimonInventoryUI();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Inventory|UI")
    void ToggleDigimonInventoryUI();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Inventory|UI")
    void RefreshDigimonInventoryUI();

    /** Opens the shared Digimon menu directly on Scan & Materialize. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Scan & Materialization|UI")
    void OpenScanMaterializeUI();

    /** Opens the shared Digimon menu directly on the virtual-pet CARE tab. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Care|UI")
    void OpenCareUI();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Care|UI")
    bool IsCarePresentationActive() const { return bCarePresentationActive; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Inventory|UI")
    bool IsDigimonInventoryUIOpen() const { return DigimonInventoryWidget != nullptr; }

    /** Preferred future-facing aliases for the shared tabbed Digimon menu. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI")
    void OpenDigimonMenuUI() { OpenDigimonInventoryUI(); }

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI")
    void CloseDigimonMenuUI() { CloseDigimonInventoryUI(); }

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI")
    void ToggleDigimonMenuUI() { ToggleDigimonInventoryUI(); }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|UI")
    bool IsDigimonMenuUIOpen() const { return IsDigimonInventoryUIOpen(); }

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Combat")
    void SetDigimonCommandTarget(ADMFDigimonCharacter* NewTarget);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Combat")
    bool SelectDigimonCommandTargetUnderCursor();

    /** Manual MMO command: selects the supplied hostile target and executes/queues the requested quick slot. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Combat")
    void CommandPartnerTargetAndAttack(ADMFDigimonCharacter* Target, int32 SlotIndex = 0);

    /** Executes/queues a quick slot against the currently selected target. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Combat")
    void CommandActivePartnerAbilitySlot(int32 SlotIndex);

    /** Called by ADMFHealerActor::RequestHeal; routes the interaction through this client-owned controller. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Healing")
    void RequestUseHealer(ADMFHealerActor* Healer);

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Healing")
    FDMFHealerInteractionResult OnHealerInteractionResult;

    UFUNCTION(Server, Reliable)
    void ServerRequestUseHealer(ADMFHealerActor* Healer);

    UFUNCTION(Client, Reliable)
    void ClientHealerInteractionResult(bool bSuccess, const FText& Message, int32 DigimonHealed);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI")
    void RefreshCombatQuickBar();

private:
    UPROPERTY(Transient)
    TObjectPtr<UDMFStarterSelectionWidget> StarterWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFCombatQuickBarWidget> CombatQuickBarWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFPlayerSkinSelectionWidget> PlayerSkinWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFDigimonInventoryWidget> DigimonInventoryWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFScanNotificationWidget> ScanNotificationWidget;

    bool bPlayerSkinMenuOpenedManually = false;
    bool bFrameworkModalInputLocked = false;
    bool bCarePresentationActive = false;
    bool bReopenCareMenuAfterSequence = false;

    FTimerHandle StarterUIRetryTimer;
    FTimerHandle AvatarUIRetryTimer;
    FTimerHandle AvatarPossessionRetryTimer;
    int32 AvatarPossessionRetryAttempts = 0;

    UFUNCTION()
    void HandleStarterRequirementChanged(bool bRequired);

    UFUNCTION()
    void HandleScanDataRewardGranted(FPrimaryAssetId SpeciesId, float AddedPercent, float NewPercent, bool bMaterializationReady);

    UFUNCTION()
    void HandleCareSequenceStarted(FGuid DigimonInstanceId);

    UFUNCTION()
    void HandleCareSequenceFinished(bool bSuccess, FText Message, FGuid DigimonInstanceId);

    UFUNCTION()
    void HandlePlayerSkinRequirementChanged(bool bRequired);

    void BindStarterState();
    void BindAvatarState();
    void ValidateLocalAvatarPossession();
    void ApplyFrameworkModalInputMode();
    void RestoreGameplayInputMode();
    bool IsMandatoryPlayerSkinSelectionActive() const;

    void HandleDefaultTargetInput();
    void HandlePlayerSkinMenuInput();
    void HandleDigimonInventoryMenuInput();
    void HandleAbilitySlot1();
    void HandleAbilitySlot2();
    void HandleAbilitySlot3();
    void HandleAbilitySlot4();
    void ExecuteDefaultAbilitySlot(int32 SlotIndex);
};
