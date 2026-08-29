#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DMFTypes.h"
#include "DMFMMOPlayerController.generated.h"

class UDMFStarterSelectionWidget;
class UDMFCombatQuickBarWidget;
class UDMFPartyQuickBarWidget;
class UDMFPlayerSkinSelectionWidget;
class UDMFDigimonInventoryWidget;
class UDMFDigimonVendorWidget;
class UDMFScanNotificationWidget;
class UDMFExperienceNotificationWidget;
class UDMFHomeTeleportNotificationWidget;
class UDMFWorldChatWidget;
class UDMFPlayerSocialContextWidget;
class UDMFFriendTrackerWidget;
class UWidgetComponent;
class ADMFDigimonCharacter;
class ADMFPlayerAvatarCharacter;
class ADMFHealerActor;
class ADMFDigimonVendorActor;
class ADMFTargetingPresentationActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFHealerInteractionResult, bool, bSuccess, FText, Message, int32, DigimonHealed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFWorldChatMessageReceived, FDMFWorldChatMessage, ChatMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFSocialSnapshotChanged, FDMFSocialSnapshot, SocialSnapshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFSocialActionResult, bool, bSuccess, FText, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFHomeTeleportResult, bool, bSuccess, FText, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FDMFDigimonVendorTransactionResult, bool, bSuccess, FText, Message, EDMFDigimonVendorTransactionType, TransactionType, FGuid, Identifier, int64, Price, int64, NewMoney);

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
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
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

    /** Opens the shared Digimon menu directly on the six-slot Party page. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party & Bank|UI")
    void OpenPartyUI();

    /** Opens the shared Digimon menu directly on world-accessible Bank/Box storage. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party & Bank|UI")
    void OpenBankUI();

    /** Opens the shared Digimon menu directly on Scan & Materialize. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Scan & Materialization|UI")
    void OpenScanMaterializeUI();

    /** Opens the shared Digimon menu directly on the virtual-pet CARE tab. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Care|UI")
    void OpenCareUI();

    /** Opens the shared Digimon menu directly on the persistent Party/Bank Digivolution terminal. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Digivolution|UI")
    void OpenDigivolutionUI();

    /** Opens the shared Digimon menu directly on the persistent Social hub. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|UI")
    void OpenSocialUI();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Care|UI")
    bool IsCarePresentationActive() const { return bCarePresentationActive; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Digivolution|UI")
    bool IsDigivolutionPresentationActive() const { return bDigivolutionPresentationActive; }

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

    /** Creates/reloads this client's non-replicated partner/target selection presentation from Project Settings. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Combat|Targeting Visuals")
    void RefreshTargetingVisuals();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Targeting Visuals")
    ADMFTargetingPresentationActor* GetTargetingPresentationActor() const { return TargetingPresentationActor; }

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

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party Quick Access|UI")
    void RefreshPartyQuickBar();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party Quick Access|UI")
    void OpenPartyQuickAccessInteraction();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party Quick Access|UI")
    void ClosePartyQuickAccessInteraction();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party Quick Access|UI")
    void TogglePartyQuickAccessInteraction();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Party Quick Access|UI")
    bool IsPartyQuickAccessInteractionActive() const { return bPartyQuickAccessInteractionActive; }


    /** Requests a server-authoritative teleport to the configured DMFNewPlayerStart. No client transform is accepted. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party Quick Access|Home")
    void RequestReturnHome();

    UFUNCTION(Server, Reliable)
    void ServerRequestReturnHome();

    UFUNCTION(Client, Reliable)
    void ClientReturnHomeResult(bool bSuccess, const FText& Message);

    /** Owner-local result/presentation hook for native or custom Blueprint HUDs. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Party Quick Access|Home")
    FDMFHomeTeleportResult OnHomeTeleportResult;

    /** Creates/refreshes the native persistent world-chat HUD when globally enabled. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|World Chat|UI")
    void RefreshWorldChatUI();

    /** Focuses the chat entry field. The default Enter binding calls this automatically. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|World Chat|UI")
    void OpenWorldChatInput();

    /** Cancels text entry and returns keyboard/gameplay focus to the world. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|World Chat|UI")
    void CloseWorldChatInput();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|World Chat|UI")
    void ToggleWorldChatInput();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|World Chat|UI")
    bool IsWorldChatInputActive() const { return bWorldChatInputActive; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|World Chat|UI")
    UDMFWorldChatWidget* GetWorldChatWidget() const { return WorldChatWidget; }

    /** Client-facing entry point. Identity/timestamps are intentionally not accepted from the caller. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|World Chat")
    void SendWorldChatMessage(const FString& Message);

    UFUNCTION(Server, Reliable)
    void ServerSendWorldChatMessage(const FString& Message);

    UFUNCTION(Server, Reliable)
    void ServerRequestWorldChatHistory();

    UFUNCTION(Client, Reliable)
    void ClientReceiveWorldChatMessage(const FDMFWorldChatMessage& ChatMessage);

    UFUNCTION(Client, Reliable)
    void ClientReceiveWorldChatHistory(const TArray<FDMFWorldChatMessage>& ChatMessages);

    UFUNCTION(Client, Reliable)
    void ClientWorldChatSendRejected(const FText& Reason);

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|World Chat")
    FDMFWorldChatMessageReceived OnWorldChatMessageReceived;

    /** Requests the authoritative owner-only Social snapshot. Safe to call when opening/reskinning the Social tab. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social")
    void RequestSocialSnapshot();

    /** Last owner-only snapshot received from authority; never replicated through PlayerState/world actors. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Social")
    FDMFSocialSnapshot GetCachedSocialSnapshot() const { return CachedSocialSnapshot; }

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Friends") void RequestAddFriend(const FString& TargetUsername);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Friends") void RespondToFriendRequest(const FString& RequesterUsername, bool bAccept);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Friends") void RequestCancelFriendRequest(const FString& TargetUsername);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Friends") void RequestRemoveFriend(const FString& FriendUsername);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Friends") void RequestSetFriendTracking(const FString& FriendUsername, bool bEnabled);

    /**
     * Returns nearby replicated player avatars inside the global Project Settings radius, nearest first.
     * This is owner-local discovery/presentation only; friend mutations remain server-authoritative.
     */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Social|Friends|Nearby Players")
    TArray<FDMFNearbySocialPlayerEntry> GetNearbySocialPlayers() const;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Ignore") void RequestIgnorePlayer(const FString& TargetUsername);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Ignore") void RequestRemoveIgnoredPlayer(const FString& TargetUsername);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Guild") void RequestCreateGuild(const FString& GuildName);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Guild") void RequestRenameGuild(const FString& GuildName);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Guild") void RequestInvitePlayerToGuild(const FString& TargetUsername);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Guild") void RespondToGuildInvite(FGuid GuildId, bool bAccept);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Guild") void RequestApplyToGuild(FGuid GuildId);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Guild") void RespondToGuildApplication(const FString& ApplicantUsername, bool bAccept);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Guild") void RequestRemoveGuildMember(const FString& MemberUsername);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Guild") void RequestLeaveGuild();
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Guild") void RequestDisbandGuild();

    /** Opens the owner-local dropdown next to the mouse cursor for an exact replicated player nameplate. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Nameplate Context")
    void OpenPlayerSocialContext(ADMFPlayerAvatarCharacter* TargetPlayer);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Nameplate Context")
    void ClosePlayerSocialContextUI();

    /** Reconciles local-only tracked-friend WidgetComponents against replicated online player avatars. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Friend Tracking")
    void RefreshFriendTrackingPresentation();

    UFUNCTION(Server, Reliable)
    void ServerRequestSocialSnapshot();

    /** One validated transport RPC keeps the Social mutation surface compact while public wrappers remain strongly named. */
    UFUNCTION(Server, Reliable)
    void ServerExecuteSocialAction(EDMFSocialActionType ActionType, const FString& SubjectUsername, FGuid GuildId, const FString& TextValue, bool bValue);

    UFUNCTION(Client, Reliable)
    void ClientReceiveSocialSnapshot(const FDMFSocialSnapshot& SocialSnapshot);

    UFUNCTION(Client, Reliable)
    void ClientSocialActionResult(bool bSuccess, const FText& Message);

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Social")
    FDMFSocialSnapshotChanged OnSocialSnapshotChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Social")
    FDMFSocialActionResult OnSocialActionResult;

    /** Opens the owner-local native BUY / SELL market UI for a nearby replicated vendor. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Vendor|UI")
    void OpenDigimonVendorUI(ADMFDigimonVendorActor* Vendor);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Vendor|UI")
    void CloseDigimonVendorUI();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Vendor|UI")
    void RefreshDigimonVendorUI();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor|UI")
    bool IsDigimonVendorUIOpen() const { return DigimonVendorWidget != nullptr; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor|UI")
    ADMFDigimonVendorActor* GetActiveDigimonVendor() const { return ActiveDigimonVendor; }

    /** Client-facing request. Price/stats/money are intentionally never accepted from the caller. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Vendor")
    void RequestDigimonVendorTransaction(ADMFDigimonVendorActor* Vendor, EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier);

    UFUNCTION(Server, Reliable)
    void ServerRequestDigimonVendorTransaction(ADMFDigimonVendorActor* Vendor, EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier);

    UFUNCTION(Client, Reliable)
    void ClientDigimonVendorTransactionResult(bool bSuccess, const FText& Message, EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier, int64 Price, int64 NewMoney);

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Vendor")
    FDMFDigimonVendorTransactionResult OnDigimonVendorTransactionResult;

private:
    UPROPERTY(Transient)
    TObjectPtr<UDMFStarterSelectionWidget> StarterWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFCombatQuickBarWidget> CombatQuickBarWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFPartyQuickBarWidget> PartyQuickBarWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFPlayerSkinSelectionWidget> PlayerSkinWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFDigimonInventoryWidget> DigimonInventoryWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFDigimonVendorWidget> DigimonVendorWidget;

    UPROPERTY(Transient)
    TObjectPtr<ADMFDigimonVendorActor> ActiveDigimonVendor;

    UPROPERTY(Transient)
    TObjectPtr<UDMFScanNotificationWidget> ScanNotificationWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFExperienceNotificationWidget> ExperienceNotificationWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFHomeTeleportNotificationWidget> HomeTeleportNotificationWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFWorldChatWidget> WorldChatWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFPlayerSocialContextWidget> PlayerSocialContextWidget;

    /** Last owner-only server snapshot. Social state is intentionally not public PlayerState replication. */
    UPROPERTY(Transient)
    FDMFSocialSnapshot CachedSocialSnapshot;

    /** Client-only components attached to currently online tracked friends; keys are lowercase usernames. */
    UPROPERTY(Transient)
    TMap<FString, TObjectPtr<UWidgetComponent>> FriendTrackerComponents;

    /** Local-only presentation actor. It is never replicated and exists only for the owning local PlayerController. */
    UPROPERTY(Transient)
    TObjectPtr<ADMFTargetingPresentationActor> TargetingPresentationActor;

    bool bPlayerSkinMenuOpenedManually = false;
    bool bFrameworkModalInputLocked = false;
    bool bCarePresentationActive = false;
    bool bReopenCareMenuAfterSequence = false;
    bool bDigivolutionPresentationActive = false;
    bool bReopenDigivolutionMenuAfterSequence = false;
    bool bWorldChatInputActive = false;
    bool bWorldChatInputLocked = false;
    bool bPartyQuickAccessInteractionActive = false;
    bool bPartyQuickAccessInputLocked = false;

    double LastWorldChatAcceptedServerTime = -1000000.0;
    double LastSocialActionAcceptedServerTime = -1000000.0;
    double LastSocialSnapshotAcceptedServerTime = -1000000.0;
    double LastReturnHomeAcceptedServerTime = -1000000.0;
    double LastDigimonVendorTransactionServerTime = -1000000.0;
    TArray<double> RecentWorldChatAcceptedServerTimes;

    FTimerHandle StarterUIRetryTimer;
    FTimerHandle AvatarUIRetryTimer;
    FTimerHandle AvatarPossessionRetryTimer;
    FTimerHandle FriendTrackerRefreshTimer;
    int32 AvatarPossessionRetryAttempts = 0;

    UFUNCTION()
    void HandleStarterRequirementChanged(bool bRequired);

    UFUNCTION()
    void HandleScanDataRewardGranted(FPrimaryAssetId SpeciesId, float AddedPercent, float NewPercent, bool bMaterializationReady);

    UFUNCTION()
    void HandleDigimonExperienceProgressed(FDMFDigimonExperienceProgression Progression);

    UFUNCTION()
    void HandleCareSequenceStarted(FGuid DigimonInstanceId);

    UFUNCTION()
    void HandleCareSequenceFinished(bool bSuccess, FText Message, FGuid DigimonInstanceId);

    UFUNCTION()
    void HandleDigivolutionSequenceStarted(FGuid DigimonInstanceId, FPrimaryAssetId PreviousSpeciesId, FPrimaryAssetId TargetSpeciesId);

    UFUNCTION()
    void HandleDigivolutionResult(bool bSuccess, FText Message, FGuid DigimonInstanceId, FPrimaryAssetId PreviousSpeciesId, FPrimaryAssetId NewSpeciesId);

    UFUNCTION()
    void HandlePlayerSkinRequirementChanged(bool bRequired);

    void BindStarterState();
    void BindAvatarState();
    void EnsureTargetingPresentation();
    void ValidateLocalAvatarPossession();
    void ApplyFrameworkModalInputMode();
    void RestoreGameplayInputMode();
    bool IsWorldPresentationActive() const { return bCarePresentationActive || bDigivolutionPresentationActive; }
    void ApplyWorldChatInputMode();
    void RestoreWorldChatInputMode();
    bool IsMandatoryPlayerSkinSelectionActive() const;
    FString SanitizeWorldChatMessage(const FString& Message) const;
    void PlayWorldChatPresenceSound(EDMFWorldChatMessageType MessageType) const;
    void ExecuteLocalSocialAction(EDMFSocialActionType ActionType, const FString& SubjectUsername = FString(), FGuid GuildId = FGuid(), const FString& TextValue = FString(), bool bValue = false);
    void HandleSocialActionResultPresentation(bool bSuccess, const FText& Message);
    void DestroyFriendTrackerComponents();
    ADMFPlayerAvatarCharacter* FindOnlinePlayerAvatarByUsername(const FString& Username) const;

    void HandleDefaultTargetInput();
    void HandleWorldChatInput();
    void HandlePartyQuickAccessInput();
    void HandlePartyQuickAccessCancelInput();
    void HandlePlayerSkinMenuInput();
    void HandleDigimonInventoryMenuInput();
    void HandleAbilitySlot1();
    void HandleAbilitySlot2();
    void HandleAbilitySlot3();
    void HandleAbilitySlot4();
    void ExecuteDefaultAbilitySlot(int32 SlotIndex);
};
