#include "Game/DMFMMOPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Engine/World.h"
#include "Engine/LocalPlayer.h"
#include "EngineUtils.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFDigimonVendorActor.h"
#include "Game/DMFItemVendorActor.h"
#include "Game/DMFHealerActor.h"
#include "Game/DMFMMOGameMode.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Game/DMFPlayerState.h"
#include "Game/DMFTargetingPresentationActor.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Settings/DMFFrameworkSettings.h"
#include "TimerManager.h"
#include "UI/DMFCombatQuickBarWidget.h"
#include "UI/DMFPartyQuickBarWidget.h"
#include "UI/DMFDigimonInventoryWidget.h"
#include "UI/DMFDigimonVendorWidget.h"
#include "UI/DMFItemVendorWidget.h"
#include "UI/DMFScanNotificationWidget.h"
#include "UI/DMFExperienceNotificationWidget.h"
#include "UI/DMFHomeTeleportNotificationWidget.h"
#include "UI/DMFPlayerSkinSelectionWidget.h"
#include "UI/DMFStarterSelectionWidget.h"
#include "UI/DMFWorldChatWidget.h"
#include "UI/DMFPlayerSocialContextWidget.h"
#include "UI/DMFFriendTrackerWidget.h"

void ADMFMMOPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (IsLocalController())
    {
        GetWorldTimerManager().ClearTimer(FriendTrackerRefreshTimer);
        ClosePlayerSocialContextUI();
        DestroyFriendTrackerComponents();
    }

    if (HasAuthority())
    {
        // GameMode::Logout is the primary path. This is an idempotent safety net for unusual net-driver/world
        // teardown ordering so an internet client cannot bypass account finalization by disappearing abruptly.
        if (UWorld* World = GetWorld())
        {
            if (ADMFMMOGameMode* GameMode = World->GetAuthGameMode<ADMFMMOGameMode>())
            {
                GameMode->FinalizeAuthenticatedPlayerSession(this);
            }
        }
    }

    Super::EndPlay(EndPlayReason);
}

void ADMFMMOPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (!InputComponent)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || Settings->bEnableDefaultCombatInputBindings)
    {
        if (!Settings || Settings->bEnableDefaultClickTargetInput)
        {
            InputComponent->BindKey(EKeys::LeftMouseButton, IE_Pressed, this, &ADMFMMOPlayerController::HandleDefaultTargetInput);
        }

        if (!Settings || Settings->bEnableDefaultAbilitySlotInput)
        {
            InputComponent->BindKey(EKeys::One, IE_Pressed, this, &ADMFMMOPlayerController::HandleAbilitySlot1);
            InputComponent->BindKey(EKeys::Two, IE_Pressed, this, &ADMFMMOPlayerController::HandleAbilitySlot2);
            InputComponent->BindKey(EKeys::Three, IE_Pressed, this, &ADMFMMOPlayerController::HandleAbilitySlot3);
            InputComponent->BindKey(EKeys::Four, IE_Pressed, this, &ADMFMMOPlayerController::HandleAbilitySlot4);
        }
    }

    if (!Settings || Settings->bEnableDefaultPlayerSkinMenuInput)
    {
        InputComponent->BindKey(EKeys::F6, IE_Pressed, this, &ADMFMMOPlayerController::HandlePlayerSkinMenuInput);
    }

    if (!Settings || Settings->bEnableDefaultDigimonInventoryMenuInput)
    {
        InputComponent->BindKey(EKeys::I, IE_Pressed, this, &ADMFMMOPlayerController::HandleDigimonInventoryMenuInput);
    }

    if (!Settings || (Settings->bEnableWorldChat && Settings->bEnableDefaultWorldChatInput))
    {
        InputComponent->BindKey(EKeys::Enter, IE_Pressed, this, &ADMFMMOPlayerController::HandleWorldChatInput);
    }

    if (!Settings || (Settings->bShowNativePartyQuickBar && Settings->bEnableDefaultPartyQuickAccessInput))
    {
        InputComponent->BindKey(EKeys::Tab, IE_Pressed, this, &ADMFMMOPlayerController::HandlePartyQuickAccessInput);
        InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &ADMFMMOPlayerController::HandlePartyQuickAccessCancelInput);
    }
}

void ADMFMMOPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (!IsLocalController())
    {
        return;
    }

    BindStarterState();
    BindAvatarState();
    GetWorldTimerManager().SetTimer(StarterUIRetryTimer, this, &ADMFMMOPlayerController::BindStarterState, 0.25f, true);
    GetWorldTimerManager().SetTimer(AvatarUIRetryTimer, this, &ADMFMMOPlayerController::BindAvatarState, 0.25f, true);

    RefreshWorldChatUI();
    RefreshPartyQuickBar();
    EnsureTargetingPresentation();
    const UDMFFrameworkSettings* ChatSettings = GetDefault<UDMFFrameworkSettings>();
    if (!ChatSettings || ChatSettings->bEnableWorldChat)
    {
        ServerRequestWorldChatHistory();
    }

    const UDMFFrameworkSettings* SocialSettings = GetDefault<UDMFFrameworkSettings>();
    if (!SocialSettings || SocialSettings->bEnableSocialSystem)
    {
        ServerRequestSocialSnapshot();
        const float ReconcileInterval = SocialSettings
            ? FMath::Clamp(SocialSettings->FriendTrackerReconcileInterval, 0.2f, 5.0f)
            : 0.75f;
        GetWorldTimerManager().SetTimer(FriendTrackerRefreshTimer, this, &ADMFMMOPlayerController::RefreshFriendTrackingPresentation, ReconcileInterval, true);
    }

    // Only remote network clients need the late-join possession safety net. The listen-host path is
    // already authoritative/local and is intentionally left alone to avoid duplicate restart work.
    if (GetNetMode() == NM_Client)
    {
        ServerEnsureFrameworkPlayerAvatar();
        GetWorldTimerManager().SetTimer(AvatarPossessionRetryTimer, this, &ADMFMMOPlayerController::ValidateLocalAvatarPossession, 0.35f, true);
    }
}

bool ADMFMMOPlayerController::IsFrameworkPlayerAvatarPossessed() const
{
    return IsValid(Cast<ADMFPlayerAvatarCharacter>(GetPawn()));
}

void ADMFMMOPlayerController::ServerEnsureFrameworkPlayerAvatar_Implementation()
{
    ADMFMMOGameMode* MMOGameMode = GetWorld() ? GetWorld()->GetAuthGameMode<ADMFMMOGameMode>() : nullptr;
    if (MMOGameMode)
    {
        MMOGameMode->EnsureFrameworkPlayerAvatar(this);
    }
}

void ADMFMMOPlayerController::ValidateLocalAvatarPossession()
{
    if (!IsLocalController())
    {
        GetWorldTimerManager().ClearTimer(AvatarPossessionRetryTimer);
        return;
    }

    if (IsFrameworkPlayerAvatarPossessed())
    {
        GetWorldTimerManager().ClearTimer(AvatarPossessionRetryTimer);
        AvatarPossessionRetryAttempts = 0;
        return;
    }

    ++AvatarPossessionRetryAttempts;
    ServerEnsureFrameworkPlayerAvatar();

    // This timer is a bounded network-recovery safety net, not a permanent poll. Normal joins should
    // resolve on the first request; the extra attempts cover packet/order/travel edge cases.
    if (AvatarPossessionRetryAttempts >= 20)
    {
        GetWorldTimerManager().ClearTimer(AvatarPossessionRetryTimer);
    }
}

void ADMFMMOPlayerController::BindStarterState()
{
    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (!DMFPlayerState || !DMFPlayerState->DigimonComponent)
    {
        return;
    }

    DMFPlayerState->DigimonComponent->OnStarterRequirementChanged.RemoveDynamic(this, &ADMFMMOPlayerController::HandleStarterRequirementChanged);
    DMFPlayerState->DigimonComponent->OnStarterRequirementChanged.AddDynamic(this, &ADMFMMOPlayerController::HandleStarterRequirementChanged);
    DMFPlayerState->DigimonComponent->OnScanDataRewardGranted.RemoveDynamic(this, &ADMFMMOPlayerController::HandleScanDataRewardGranted);
    DMFPlayerState->DigimonComponent->OnScanDataRewardGranted.AddDynamic(this, &ADMFMMOPlayerController::HandleScanDataRewardGranted);
    DMFPlayerState->DigimonComponent->OnDigimonExperienceProgressed.RemoveDynamic(this, &ADMFMMOPlayerController::HandleDigimonExperienceProgressed);
    DMFPlayerState->DigimonComponent->OnDigimonExperienceProgressed.AddDynamic(this, &ADMFMMOPlayerController::HandleDigimonExperienceProgressed);
    DMFPlayerState->DigimonComponent->OnCareSequenceStarted.RemoveDynamic(this, &ADMFMMOPlayerController::HandleCareSequenceStarted);
    DMFPlayerState->DigimonComponent->OnCareSequenceStarted.AddDynamic(this, &ADMFMMOPlayerController::HandleCareSequenceStarted);
    DMFPlayerState->DigimonComponent->OnCareSequenceFinished.RemoveDynamic(this, &ADMFMMOPlayerController::HandleCareSequenceFinished);
    DMFPlayerState->DigimonComponent->OnCareSequenceFinished.AddDynamic(this, &ADMFMMOPlayerController::HandleCareSequenceFinished);
    DMFPlayerState->DigimonComponent->OnDigivolutionSequenceStarted.RemoveDynamic(this, &ADMFMMOPlayerController::HandleDigivolutionSequenceStarted);
    DMFPlayerState->DigimonComponent->OnDigivolutionSequenceStarted.AddDynamic(this, &ADMFMMOPlayerController::HandleDigivolutionSequenceStarted);
    DMFPlayerState->DigimonComponent->OnDigivolutionResult.RemoveDynamic(this, &ADMFMMOPlayerController::HandleDigivolutionResult);
    DMFPlayerState->DigimonComponent->OnDigivolutionResult.AddDynamic(this, &ADMFMMOPlayerController::HandleDigivolutionResult);
    GetWorldTimerManager().ClearTimer(StarterUIRetryTimer);
    RefreshStarterSelectionUI();
    RefreshPartyQuickBar();
}

void ADMFMMOPlayerController::BindAvatarState()
{
    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (!DMFPlayerState || !DMFPlayerState->AvatarComponent)
    {
        return;
    }

    DMFPlayerState->AvatarComponent->OnPlayerSkinRequirementChanged.RemoveDynamic(this, &ADMFMMOPlayerController::HandlePlayerSkinRequirementChanged);
    DMFPlayerState->AvatarComponent->OnPlayerSkinRequirementChanged.AddDynamic(this, &ADMFMMOPlayerController::HandlePlayerSkinRequirementChanged);
    GetWorldTimerManager().ClearTimer(AvatarUIRetryTimer);
    RefreshPlayerSkinSelectionUI();
}

void ADMFMMOPlayerController::HandleStarterRequirementChanged(const bool bRequired)
{
    RefreshStarterSelectionUI();
}

void ADMFMMOPlayerController::HandleScanDataRewardGranted(const FPrimaryAssetId SpeciesId, const float AddedPercent, const float NewPercent, const bool bMaterializationReady)
{
    if (!IsLocalController())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bShowNativeScanNotifications)
    {
        return;
    }

    if (!ScanNotificationWidget)
    {
        TSubclassOf<UDMFScanNotificationWidget> WidgetClass = Settings ? Settings->ScanNotificationWidgetClass : nullptr;
        if (!WidgetClass)
        {
            WidgetClass = UDMFScanNotificationWidget::StaticClass();
        }
        ScanNotificationWidget = CreateWidget<UDMFScanNotificationWidget>(this, WidgetClass);
        if (ScanNotificationWidget)
        {
            ScanNotificationWidget->AddToViewport(800);
        }
    }

    if (ScanNotificationWidget)
    {
        ScanNotificationWidget->ShowScanReward(SpeciesId, AddedPercent, NewPercent, bMaterializationReady);
    }

    if (DigimonInventoryWidget && DigimonInventoryWidget->GetActiveMenuTab() == EDMFDigimonMenuTab::ScanAndMaterialize)
    {
        DigimonInventoryWidget->RefreshScanData();
    }
}

void ADMFMMOPlayerController::HandleDigimonExperienceProgressed(const FDMFDigimonExperienceProgression Progression)
{
    if (!IsLocalController())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bShowNativeExperienceNotifications)
    {
        return;
    }

    if (!ExperienceNotificationWidget)
    {
        TSubclassOf<UDMFExperienceNotificationWidget> WidgetClass = Settings ? Settings->ExperienceNotificationWidgetClass : nullptr;
        if (!WidgetClass)
        {
            WidgetClass = UDMFExperienceNotificationWidget::StaticClass();
        }
        ExperienceNotificationWidget = CreateWidget<UDMFExperienceNotificationWidget>(this, WidgetClass);
        if (ExperienceNotificationWidget)
        {
            ExperienceNotificationWidget->AddToViewport(850);
        }
    }

    if (ExperienceNotificationWidget)
    {
        ExperienceNotificationWidget->ShowExperienceProgress(Progression);
    }

    // The owner-only Fast Array remains the durable UI source. Refresh an open menu immediately when
    // its corresponding replication has already arrived; OnRep will safely refresh again if it arrives later.
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RefreshInventory();
        DigimonInventoryWidget->RefreshBankData();
    }
}

void ADMFMMOPlayerController::HandleCareSequenceStarted(const FGuid DigimonInstanceId)
{
    if (!IsLocalController()) return;

    if (bWorldChatInputActive)
    {
        CloseWorldChatInput();
    }

    bCarePresentationActive = true;
    bReopenCareMenuAfterSequence = DigimonInventoryWidget != nullptr;
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RemoveFromParent();
        DigimonInventoryWidget = nullptr;
    }
    if (CombatQuickBarWidget)
    {
        CombatQuickBarWidget->RemoveFromParent();
        CombatQuickBarWidget = nullptr;
    }
    if (bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
    if (PartyQuickBarWidget)
    {
        PartyQuickBarWidget->RemoveFromParent();
        PartyQuickBarWidget = nullptr;
    }
    if (WorldChatWidget)
    {
        WorldChatWidget->SetVisibility(ESlateVisibility::Collapsed);
    }
    // Feeding is an in-world presentation. Remove modal UI/input locks before the server starts the first Montage.
    RestoreGameplayInputMode();
}

void ADMFMMOPlayerController::HandleCareSequenceFinished(const bool bSuccess, const FText Message, const FGuid DigimonInstanceId)
{
    if (!IsLocalController()) return;

    const bool bShouldReopenCare = bReopenCareMenuAfterSequence;
    bCarePresentationActive = false;
    bReopenCareMenuAfterSequence = false;
    RefreshWorldChatUI();
    if (bShouldReopenCare)
    {
        OpenCareUI();
        if (DigimonInventoryWidget) DigimonInventoryWidget->RefreshCareData();
    }
    else
    {
        RefreshCombatQuickBar();
        RefreshPartyQuickBar();
    }
}

void ADMFMMOPlayerController::HandleDigivolutionSequenceStarted(const FGuid DigimonInstanceId, const FPrimaryAssetId PreviousSpeciesId, const FPrimaryAssetId TargetSpeciesId)
{
    if (!IsLocalController())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bHideUIForSummonedDigivolution)
    {
        return;
    }

    if (bWorldChatInputActive)
    {
        CloseWorldChatInput();
    }

    bDigivolutionPresentationActive = true;
    bReopenDigivolutionMenuAfterSequence = DigimonInventoryWidget != nullptr;
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RemoveFromParent();
        DigimonInventoryWidget = nullptr;
    }
    if (CombatQuickBarWidget)
    {
        CombatQuickBarWidget->RemoveFromParent();
        CombatQuickBarWidget = nullptr;
    }
    if (bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
    if (PartyQuickBarWidget)
    {
        PartyQuickBarWidget->RemoveFromParent();
        PartyQuickBarWidget = nullptr;
    }
    if (WorldChatWidget)
    {
        WorldChatWidget->SetVisibility(ESlateVisibility::Collapsed);
    }

    // The transformation belongs in the world, not behind modal UI. Local gameplay view is restored
    // while the server keeps all mutation/combat commands locked until the authoritative commit finishes.
    RestoreGameplayInputMode();
}

void ADMFMMOPlayerController::HandleDigivolutionResult(const bool bSuccess, const FText Message, const FGuid DigimonInstanceId, const FPrimaryAssetId PreviousSpeciesId, const FPrimaryAssetId NewSpeciesId)
{
    if (!IsLocalController())
    {
        return;
    }

    const bool bWasWorldPresentation = bDigivolutionPresentationActive;
    const bool bShouldReopen = bReopenDigivolutionMenuAfterSequence;
    bDigivolutionPresentationActive = false;
    bReopenDigivolutionMenuAfterSequence = false;

    if (bWasWorldPresentation)
    {
        RefreshWorldChatUI();
        if (bShouldReopen)
        {
            OpenDigivolutionUI();
        }
        else
        {
            RefreshCombatQuickBar();
            RefreshPartyQuickBar();
        }
    }
    else if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RefreshInventory();
        DigimonInventoryWidget->RefreshBankData();
        DigimonInventoryWidget->RefreshDigivolutionData();
    }

    // World actor replacement and owner-only Party/Bank mutation can arrive in either network order.
    // Refreshing the HUD here is harmless and ensures the newly evolved form is visible immediately.
    RefreshCombatQuickBar();
    RefreshPartyQuickBar();
}

void ADMFMMOPlayerController::HandlePlayerSkinRequirementChanged(const bool bRequired)
{
    // Mandatory onboarding uses bPlayerSkinMenuOpenedManually=false and closes naturally when the
    // requirement clears. A manually opened wardrobe remains open after applying a skin so the
    // player can preview/apply several choices before explicitly closing it.
    RefreshPlayerSkinSelectionUI();
}

bool ADMFMMOPlayerController::IsMandatoryPlayerSkinSelectionActive() const
{
    const ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    return DMFPlayerState && DMFPlayerState->AvatarComponent && DMFPlayerState->AvatarComponent->IsPlayerSkinSelectionRequired();
}

void ADMFMMOPlayerController::RefreshPlayerSkinSelectionUI()
{
    if (!IsLocalController() || IsWorldPresentationActive())
    {
        return;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    UDMFPlayerAvatarComponent* AvatarComponent = DMFPlayerState ? DMFPlayerState->AvatarComponent : nullptr;
    if (!AvatarComponent)
    {
        return;
    }

    const bool bRequired = AvatarComponent->IsPlayerSkinSelectionRequired();
    const bool bShouldShow = bRequired || bPlayerSkinMenuOpenedManually;

    if (!bShouldShow)
    {
        if (PlayerSkinWidget)
        {
            PlayerSkinWidget->RemoveFromParent();
            PlayerSkinWidget = nullptr;
        }

        if (DMFPlayerState->DigimonComponent && DMFPlayerState->DigimonComponent->IsStarterSelectionRequired())
        {
            RefreshStarterSelectionUI();
        }
        else if (!DigimonInventoryWidget && !DigimonVendorWidget && !ItemVendorWidget)
        {
            RestoreGameplayInputMode();
            RefreshCombatQuickBar();
            RefreshPartyQuickBar();
        }
        return;
    }

    if (StarterWidget)
    {
        StarterWidget->RemoveFromParent();
        StarterWidget = nullptr;
    }

    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RemoveFromParent();
        DigimonInventoryWidget = nullptr;
    }
    if (DigimonVendorWidget)
    {
        DigimonVendorWidget->RemoveFromParent();
        DigimonVendorWidget = nullptr;
        ActiveDigimonVendor = nullptr;
    }
    if (ItemVendorWidget)
    {
        ItemVendorWidget->RemoveFromParent();
        ItemVendorWidget = nullptr;
        ActiveItemVendor = nullptr;
    }

    if (CombatQuickBarWidget)
    {
        CombatQuickBarWidget->RemoveFromParent();
        CombatQuickBarWidget = nullptr;
    }
    if (bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
    if (PartyQuickBarWidget)
    {
        PartyQuickBarWidget->RemoveFromParent();
        PartyQuickBarWidget = nullptr;
    }

    if (!PlayerSkinWidget)
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        TSubclassOf<UDMFPlayerSkinSelectionWidget> WidgetClass = Settings ? Settings->PlayerSkinSelectionWidgetClass : nullptr;
        if (!WidgetClass)
        {
            WidgetClass = UDMFPlayerSkinSelectionWidget::StaticClass();
        }

        PlayerSkinWidget = CreateWidget<UDMFPlayerSkinSelectionWidget>(this, WidgetClass);
        if (PlayerSkinWidget)
        {
            PlayerSkinWidget->AddToViewport(1100);
        }
    }

    ApplyFrameworkModalInputMode();
}

void ADMFMMOPlayerController::OpenPlayerSkinSelectionUI()
{
    if (!IsLocalController() || IsWorldPresentationActive())
    {
        return;
    }

    bPlayerSkinMenuOpenedManually = true;
    RefreshPlayerSkinSelectionUI();
}

void ADMFMMOPlayerController::ClosePlayerSkinSelectionUI()
{
    if (!IsLocalController() || IsMandatoryPlayerSkinSelectionActive())
    {
        return;
    }

    bPlayerSkinMenuOpenedManually = false;
    RefreshPlayerSkinSelectionUI();
}

void ADMFMMOPlayerController::TogglePlayerSkinSelectionUI()
{
    if (IsWorldPresentationActive()) return;
    if (PlayerSkinWidget)
    {
        ClosePlayerSkinSelectionUI();
    }
    else
    {
        OpenPlayerSkinSelectionUI();
    }
}

void ADMFMMOPlayerController::RefreshStarterSelectionUI()
{
    if (!IsLocalController())
    {
        return;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (!DMFPlayerState || !DMFPlayerState->DigimonComponent)
    {
        return;
    }

    if (DMFPlayerState->AvatarComponent && DMFPlayerState->AvatarComponent->IsPlayerSkinSelectionRequired())
    {
        if (StarterWidget)
        {
            StarterWidget->RemoveFromParent();
            StarterWidget = nullptr;
        }
        RefreshPlayerSkinSelectionUI();
        return;
    }

    if (!DMFPlayerState->DigimonComponent->IsStarterSelectionRequired())
    {
        if (StarterWidget)
        {
            StarterWidget->RemoveFromParent();
            StarterWidget = nullptr;
        }

        if (!PlayerSkinWidget && !DigimonInventoryWidget && !DigimonVendorWidget && !ItemVendorWidget)
        {
            RestoreGameplayInputMode();
            RefreshCombatQuickBar();
            RefreshPartyQuickBar();
        }
        return;
    }

    if (PlayerSkinWidget)
    {
        return;
    }

    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RemoveFromParent();
        DigimonInventoryWidget = nullptr;
    }
    if (DigimonVendorWidget)
    {
        DigimonVendorWidget->RemoveFromParent();
        DigimonVendorWidget = nullptr;
        ActiveDigimonVendor = nullptr;
    }
    if (ItemVendorWidget)
    {
        ItemVendorWidget->RemoveFromParent();
        ItemVendorWidget = nullptr;
        ActiveItemVendor = nullptr;
    }

    if (CombatQuickBarWidget)
    {
        CombatQuickBarWidget->RemoveFromParent();
        CombatQuickBarWidget = nullptr;
    }
    if (bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
    if (PartyQuickBarWidget)
    {
        PartyQuickBarWidget->RemoveFromParent();
        PartyQuickBarWidget = nullptr;
    }

    if (!StarterWidget)
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        TSubclassOf<UDMFStarterSelectionWidget> WidgetClass = Settings ? Settings->StarterSelectionWidgetClass : nullptr;
        if (!WidgetClass)
        {
            WidgetClass = UDMFStarterSelectionWidget::StaticClass();
        }

        StarterWidget = CreateWidget<UDMFStarterSelectionWidget>(this, WidgetClass);
        if (StarterWidget)
        {
            StarterWidget->AddToViewport(1000);
        }
    }

    ApplyFrameworkModalInputMode();
}

void ADMFMMOPlayerController::OpenDigimonInventoryUI()
{
    if (!IsLocalController() || IsWorldPresentationActive())
    {
        return;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (!DMFPlayerState || !DMFPlayerState->DigimonComponent)
    {
        return;
    }

    if (IsMandatoryPlayerSkinSelectionActive())
    {
        RefreshPlayerSkinSelectionUI();
        return;
    }
    if (DMFPlayerState->DigimonComponent->IsStarterSelectionRequired())
    {
        RefreshStarterSelectionUI();
        return;
    }

    if (bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
    if (DigimonVendorWidget)
    {
        CloseDigimonVendorUI();
    }
    if (ItemVendorWidget)
    {
        CloseItemVendorUI();
    }
    if (CombatQuickBarWidget)
    {
        CombatQuickBarWidget->RemoveFromParent();
        CombatQuickBarWidget = nullptr;
    }
    if (PartyQuickBarWidget)
    {
        PartyQuickBarWidget->RemoveFromParent();
        PartyQuickBarWidget = nullptr;
    }

    if (!DigimonInventoryWidget)
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        TSubclassOf<UDMFDigimonInventoryWidget> WidgetClass = Settings ? Settings->DigimonInventoryWidgetClass : nullptr;
        if (!WidgetClass)
        {
            WidgetClass = UDMFDigimonInventoryWidget::StaticClass();
        }
        DigimonInventoryWidget = CreateWidget<UDMFDigimonInventoryWidget>(this, WidgetClass);
        if (DigimonInventoryWidget)
        {
            DigimonInventoryWidget->AddToViewport(900);
        }
    }

    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RefreshInventory();
        DigimonInventoryWidget->RefreshBankData();
        ApplyFrameworkModalInputMode();
    }
}

void ADMFMMOPlayerController::CloseDigimonInventoryUI()
{
    if (!IsLocalController())
    {
        return;
    }

    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RemoveFromParent();
        DigimonInventoryWidget = nullptr;
    }

    if (!PlayerSkinWidget && !StarterWidget)
    {
        RestoreGameplayInputMode();
        RefreshCombatQuickBar();
        RefreshPartyQuickBar();
    }
}

void ADMFMMOPlayerController::ToggleDigimonInventoryUI()
{
    if (IsWorldPresentationActive()) return;
    if (DigimonInventoryWidget)
    {
        CloseDigimonInventoryUI();
    }
    else
    {
        OpenDigimonInventoryUI();
    }
}

void ADMFMMOPlayerController::RefreshDigimonInventoryUI()
{
    if (IsLocalController() && DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RefreshInventory();
        DigimonInventoryWidget->RefreshBankData();
        DigimonInventoryWidget->RefreshScanData();
        DigimonInventoryWidget->RefreshDigivolutionData();
        DigimonInventoryWidget->RefreshCareData();
        DigimonInventoryWidget->RefreshItemInventoryData();
        DigimonInventoryWidget->RefreshSocialData();
    }
}

void ADMFMMOPlayerController::OpenPartyUI()
{
    OpenDigimonInventoryUI();
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->SetActiveMenuTab(EDMFDigimonMenuTab::Collection);
    }
}

void ADMFMMOPlayerController::OpenBankUI()
{
    OpenDigimonInventoryUI();
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->SetActiveMenuTab(EDMFDigimonMenuTab::Bank);
    }
}

void ADMFMMOPlayerController::OpenScanMaterializeUI()
{
    OpenDigimonInventoryUI();
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->SetActiveMenuTab(EDMFDigimonMenuTab::ScanAndMaterialize);
    }
}

void ADMFMMOPlayerController::OpenCareUI()
{
    OpenDigimonInventoryUI();
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->SetActiveMenuTab(EDMFDigimonMenuTab::Care);
    }
}

void ADMFMMOPlayerController::OpenDigivolutionUI()
{
    OpenDigimonInventoryUI();
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->SetActiveMenuTab(EDMFDigimonMenuTab::Digivolution);
    }
}

void ADMFMMOPlayerController::OpenSocialUI()
{
    OpenDigimonInventoryUI();
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->SetActiveMenuTab(EDMFDigimonMenuTab::Social);
    }
}

void ADMFMMOPlayerController::OpenItemsUI()
{
    OpenDigimonInventoryUI();
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->SetActiveMenuTab(EDMFDigimonMenuTab::Items);
    }
}

void ADMFMMOPlayerController::OpenDigimonVendorUI(ADMFDigimonVendorActor* Vendor)
{
    if (!IsLocalController() || !IsValid(Vendor) || IsWorldPresentationActive())
    {
        return;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (!DMFPlayerState || !DMFPlayerState->DigimonComponent || IsMandatoryPlayerSkinSelectionActive()
        || DMFPlayerState->DigimonComponent->IsStarterSelectionRequired())
    {
        return;
    }

    if (!Vendor->IsVendorEnabled() || !Vendor->IsPlayerWithinTradeRange(this))
    {
        return;
    }

    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RemoveFromParent();
        DigimonInventoryWidget = nullptr;
    }
    if (bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
    if (bWorldChatInputActive)
    {
        CloseWorldChatInput();
    }
    if (CombatQuickBarWidget)
    {
        CombatQuickBarWidget->RemoveFromParent();
        CombatQuickBarWidget = nullptr;
    }
    if (PartyQuickBarWidget)
    {
        PartyQuickBarWidget->RemoveFromParent();
        PartyQuickBarWidget = nullptr;
    }

    if (ItemVendorWidget)
    {
        ItemVendorWidget->RemoveFromParent();
        ItemVendorWidget = nullptr;
        ActiveItemVendor = nullptr;
    }
    if (DigimonVendorWidget && ActiveDigimonVendor != Vendor)
    {
        DigimonVendorWidget->RemoveFromParent();
        DigimonVendorWidget = nullptr;
    }
    ActiveDigimonVendor = Vendor;

    if (!DigimonVendorWidget && !ItemVendorWidget)
    {
        TSubclassOf<UDMFDigimonVendorWidget> WidgetClass = Vendor->VendorWidgetClass;
        if (!WidgetClass)
        {
            WidgetClass = UDMFDigimonVendorWidget::StaticClass();
        }
        DigimonVendorWidget = CreateWidget<UDMFDigimonVendorWidget>(this, WidgetClass);
        if (DigimonVendorWidget)
        {
            DigimonVendorWidget->AddToViewport(950);
        }
    }

    if (DigimonVendorWidget)
    {
        DigimonVendorWidget->InitializeVendor(Vendor);
        ApplyFrameworkModalInputMode();
    }
}

void ADMFMMOPlayerController::CloseDigimonVendorUI()
{
    if (!IsLocalController())
    {
        return;
    }

    if (DigimonVendorWidget)
    {
        DigimonVendorWidget->RemoveFromParent();
        DigimonVendorWidget = nullptr;
    }
    ActiveDigimonVendor = nullptr;

    if (!PlayerSkinWidget && !StarterWidget && !DigimonInventoryWidget && !ItemVendorWidget)
    {
        RestoreGameplayInputMode();
        RefreshCombatQuickBar();
        RefreshPartyQuickBar();
    }
}

void ADMFMMOPlayerController::RefreshDigimonVendorUI()
{
    if (IsLocalController() && DigimonVendorWidget)
    {
        if (!IsValid(ActiveDigimonVendor) || !ActiveDigimonVendor->IsVendorEnabled())
        {
            CloseDigimonVendorUI();
            return;
        }
        DigimonVendorWidget->RefreshVendorUI();
    }
}

void ADMFMMOPlayerController::RequestDigimonVendorTransaction(ADMFDigimonVendorActor* Vendor, const EDMFDigimonVendorTransactionType TransactionType, const FGuid Identifier)
{
    if (!IsLocalController() || !IsValid(Vendor) || !Identifier.IsValid())
    {
        return;
    }
    ServerRequestDigimonVendorTransaction(Vendor, TransactionType, Identifier);
}

void ADMFMMOPlayerController::ServerRequestDigimonVendorTransaction_Implementation(ADMFDigimonVendorActor* Vendor, const EDMFDigimonVendorTransactionType TransactionType, const FGuid Identifier)
{
    if (!IsValid(Vendor) || !Identifier.IsValid()
        || (TransactionType != EDMFDigimonVendorTransactionType::Buy && TransactionType != EDMFDigimonVendorTransactionType::Sell))
    {
        ClientDigimonVendorTransactionResult(false, NSLOCTEXT("DMF", "VendorInvalidRequest", "That trade request is invalid."), TransactionType, Identifier, 0, 0);
        return;
    }

    const double ServerTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
    if (ServerTime - LastDigimonVendorTransactionServerTime < 0.10)
    {
        ClientDigimonVendorTransactionResult(false, NSLOCTEXT("DMF", "VendorTransactionRateLimited", "Please wait a moment before making another trade."), TransactionType, Identifier, 0, 0);
        return;
    }
    LastDigimonVendorTransactionServerTime = ServerTime;

    bool bSuccess = false;
    int64 Price = 0;
    FText Message;
    if (TransactionType == EDMFDigimonVendorTransactionType::Buy)
    {
        FGuid PurchasedInstanceId;
        bSuccess = Vendor->TryPurchaseStockAuthoritative(this, Identifier, PurchasedInstanceId, Price, Message);
    }
    else
    {
        bSuccess = Vendor->TrySellDigimonAuthoritative(this, Identifier, Price, Message);
    }

    int64 CurrentMoney = 0;
    if (ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>())
    {
        if (DMFPlayerState->DigimonComponent)
        {
            CurrentMoney = DMFPlayerState->DigimonComponent->GetMoney();
        }
    }
    ClientDigimonVendorTransactionResult(bSuccess, Message, TransactionType, Identifier, Price, CurrentMoney);
}

void ADMFMMOPlayerController::ClientDigimonVendorTransactionResult_Implementation(const bool bSuccess, const FText& Message, const EDMFDigimonVendorTransactionType TransactionType, const FGuid Identifier, const int64 Price, const int64 NewMoney)
{
    OnDigimonVendorTransactionResult.Broadcast(bSuccess, Message, TransactionType, Identifier, Price, NewMoney);
    RefreshDigimonVendorUI();
    RefreshCombatQuickBar();
    RefreshPartyQuickBar();
}


void ADMFMMOPlayerController::OpenItemVendorUI(ADMFItemVendorActor* Vendor)
{
    if (!IsLocalController() || !IsValid(Vendor) || IsWorldPresentationActive())
    {
        return;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (!DMFPlayerState || !DMFPlayerState->DigimonComponent || IsMandatoryPlayerSkinSelectionActive()
        || DMFPlayerState->DigimonComponent->IsStarterSelectionRequired())
    {
        return;
    }
    if (!Vendor->IsVendorEnabled() || !Vendor->IsPlayerWithinTradeRange(this))
    {
        return;
    }

    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RemoveFromParent();
        DigimonInventoryWidget = nullptr;
    }
    if (DigimonVendorWidget)
    {
        DigimonVendorWidget->RemoveFromParent();
        DigimonVendorWidget = nullptr;
        ActiveDigimonVendor = nullptr;
    }
    if (bPartyQuickAccessInteractionActive) ClosePartyQuickAccessInteraction();
    if (bWorldChatInputActive) CloseWorldChatInput();
    if (CombatQuickBarWidget)
    {
        CombatQuickBarWidget->RemoveFromParent();
        CombatQuickBarWidget = nullptr;
    }
    if (PartyQuickBarWidget)
    {
        PartyQuickBarWidget->RemoveFromParent();
        PartyQuickBarWidget = nullptr;
    }

    if (ItemVendorWidget && ActiveItemVendor != Vendor)
    {
        ItemVendorWidget->RemoveFromParent();
        ItemVendorWidget = nullptr;
    }
    ActiveItemVendor = Vendor;

    if (!ItemVendorWidget)
    {
        TSubclassOf<UDMFItemVendorWidget> WidgetClass = Vendor->VendorWidgetClass;
        if (!WidgetClass) WidgetClass = UDMFItemVendorWidget::StaticClass();
        ItemVendorWidget = CreateWidget<UDMFItemVendorWidget>(this, WidgetClass);
        if (ItemVendorWidget) ItemVendorWidget->AddToViewport(950);
    }

    if (ItemVendorWidget)
    {
        ItemVendorWidget->InitializeVendor(Vendor);
        ApplyFrameworkModalInputMode();
    }
}

void ADMFMMOPlayerController::CloseItemVendorUI()
{
    if (!IsLocalController()) return;
    if (ItemVendorWidget)
    {
        ItemVendorWidget->RemoveFromParent();
        ItemVendorWidget = nullptr;
    }
    ActiveItemVendor = nullptr;

    if (!PlayerSkinWidget && !StarterWidget && !DigimonInventoryWidget && !DigimonVendorWidget)
    {
        RestoreGameplayInputMode();
        RefreshCombatQuickBar();
        RefreshPartyQuickBar();
    }
}

void ADMFMMOPlayerController::RefreshItemVendorUI()
{
    if (IsLocalController() && ItemVendorWidget)
    {
        if (!IsValid(ActiveItemVendor) || !ActiveItemVendor->IsVendorEnabled())
        {
            CloseItemVendorUI();
            return;
        }
        ItemVendorWidget->RefreshVendorUI();
    }
}

void ADMFMMOPlayerController::RequestItemVendorTransaction(ADMFItemVendorActor* Vendor, const EDMFItemVendorTransactionType TransactionType, const FGuid StockId, const FPrimaryAssetId ItemAssetId, const int32 Quantity)
{
    if (!IsLocalController() || !IsValid(Vendor) || Quantity <= 0 || Quantity > 999999)
    {
        return;
    }
    if (TransactionType == EDMFItemVendorTransactionType::Buy && !StockId.IsValid()) return;
    if (TransactionType == EDMFItemVendorTransactionType::Sell && !ItemAssetId.IsValid()) return;
    ServerRequestItemVendorTransaction(Vendor, TransactionType, StockId, ItemAssetId, Quantity);
}

void ADMFMMOPlayerController::ServerRequestItemVendorTransaction_Implementation(ADMFItemVendorActor* Vendor, const EDMFItemVendorTransactionType TransactionType, const FGuid StockId, const FPrimaryAssetId ItemAssetId, const int32 Quantity)
{
    const bool bValidDirection = TransactionType == EDMFItemVendorTransactionType::Buy || TransactionType == EDMFItemVendorTransactionType::Sell;
    const bool bValidIdentity = TransactionType == EDMFItemVendorTransactionType::Buy ? StockId.IsValid() : ItemAssetId.IsValid();
    if (!IsValid(Vendor) || !bValidDirection || !bValidIdentity || Quantity <= 0 || Quantity > 999999)
    {
        ClientItemVendorTransactionResult(false, NSLOCTEXT("DMF", "ItemVendorInvalidRequest", "That item trade request is invalid."), TransactionType, FPrimaryAssetId(), 0, 0, 0);
        return;
    }

    const double ServerTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
    if (ServerTime - LastItemVendorTransactionServerTime < 0.10)
    {
        ClientItemVendorTransactionResult(false, NSLOCTEXT("DMF", "ItemVendorTransactionRateLimited", "Please wait a moment before making another item trade."), TransactionType, FPrimaryAssetId(), 0, 0, 0);
        return;
    }
    LastItemVendorTransactionServerTime = ServerTime;

    bool bSuccess = false;
    int64 TotalPrice = 0;
    FPrimaryAssetId ResolvedItemId = ItemAssetId;
    FText Message;
    if (TransactionType == EDMFItemVendorTransactionType::Buy)
    {
        bSuccess = Vendor->TryPurchaseStockAuthoritative(this, StockId, Quantity, ResolvedItemId, TotalPrice, Message);
    }
    else
    {
        bSuccess = Vendor->TrySellItemAuthoritative(this, ItemAssetId, Quantity, TotalPrice, Message);
    }

    int64 CurrentMoney = 0;
    if (ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>())
    {
        if (DMFPlayerState->DigimonComponent) CurrentMoney = DMFPlayerState->DigimonComponent->GetMoney();
    }
    ClientItemVendorTransactionResult(bSuccess, Message, TransactionType, ResolvedItemId, Quantity, TotalPrice, CurrentMoney);
}

void ADMFMMOPlayerController::ClientItemVendorTransactionResult_Implementation(const bool bSuccess, const FText& Message, const EDMFItemVendorTransactionType TransactionType, const FPrimaryAssetId ItemAssetId, const int32 Quantity, const int64 TotalPrice, const int64 NewMoney)
{
    OnItemVendorTransactionResult.Broadcast(bSuccess, Message, TransactionType, ItemAssetId, Quantity, TotalPrice, NewMoney);
    RefreshItemVendorUI();
    RefreshCombatQuickBar();
    RefreshPartyQuickBar();
}

void ADMFMMOPlayerController::ApplyFrameworkModalInputMode()
{
    if (bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
    if (bWorldChatInputActive)
    {
        if (WorldChatWidget)
        {
            WorldChatWidget->CloseChatInput();
            WorldChatWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
        }
        if (bWorldChatInputLocked)
        {
            SetIgnoreMoveInput(false);
            SetIgnoreLookInput(false);
            bWorldChatInputLocked = false;
        }
        bWorldChatInputActive = false;
    }

    if (ADMFPlayerAvatarCharacter* AvatarPawn = Cast<ADMFPlayerAvatarCharacter>(GetPawn()))
    {
        AvatarPawn->ResetNativeInputState();
    }

    if (!bFrameworkModalInputLocked)
    {
        SetIgnoreMoveInput(true);
        SetIgnoreLookInput(true);
        bFrameworkModalInputLocked = true;
    }

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}

void ADMFMMOPlayerController::RestoreGameplayInputMode()
{
    if (bPartyQuickAccessInputLocked)
    {
        SetIgnoreMoveInput(false);
        SetIgnoreLookInput(false);
        bPartyQuickAccessInputLocked = false;
        bPartyQuickAccessInteractionActive = false;
        if (PartyQuickBarWidget)
        {
            PartyQuickBarWidget->SetInteractionMode(false);
        }
    }
    if (bFrameworkModalInputLocked)
    {
        // Balance exactly the one framework-owned ignore push. External systems retain their own stacks.
        SetIgnoreMoveInput(false);
        SetIgnoreLookInput(false);
        bFrameworkModalInputLocked = false;
    }
    SetInputMode(FInputModeGameOnly());
    bShowMouseCursor = false;
}

void ADMFMMOPlayerController::RefreshWorldChatUI()
{
    if (!IsLocalController())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableWorldChat)
    {
        if (bWorldChatInputActive)
        {
            CloseWorldChatInput();
        }
        if (WorldChatWidget)
        {
            WorldChatWidget->RemoveFromParent();
            WorldChatWidget = nullptr;
        }
        return;
    }

    if (!WorldChatWidget)
    {
        TSubclassOf<UDMFWorldChatWidget> WidgetClass = Settings ? Settings->WorldChatWidgetClass : nullptr;
        if (!WidgetClass)
        {
            WidgetClass = UDMFWorldChatWidget::StaticClass();
        }

        WorldChatWidget = CreateWidget<UDMFWorldChatWidget>(this, WidgetClass);
        if (WorldChatWidget)
        {
            WorldChatWidget->AddToViewport(140);
        }
    }

    if (WorldChatWidget)
    {
        WorldChatWidget->SetVisibility(IsWorldPresentationActive()
            ? ESlateVisibility::Collapsed
            : (bWorldChatInputActive ? ESlateVisibility::Visible : ESlateVisibility::HitTestInvisible));
    }
}

void ADMFMMOPlayerController::OpenWorldChatInput()
{
    if (!IsLocalController() || bWorldChatInputActive || IsWorldPresentationActive()
        || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || DigimonVendorWidget || ItemVendorWidget || bPartyQuickAccessInteractionActive)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableWorldChat)
    {
        return;
    }

    RefreshWorldChatUI();
    if (!WorldChatWidget)
    {
        return;
    }

    bWorldChatInputActive = true;
    ApplyWorldChatInputMode();
}

void ADMFMMOPlayerController::CloseWorldChatInput()
{
    if (!IsLocalController())
    {
        return;
    }

    if (WorldChatWidget)
    {
        WorldChatWidget->CloseChatInput();
        WorldChatWidget->SetVisibility(IsWorldPresentationActive()
            ? ESlateVisibility::Collapsed
            : ESlateVisibility::HitTestInvisible);
    }

    bWorldChatInputActive = false;
    RestoreWorldChatInputMode();
}

void ADMFMMOPlayerController::ToggleWorldChatInput()
{
    if (bWorldChatInputActive)
    {
        CloseWorldChatInput();
    }
    else
    {
        OpenWorldChatInput();
    }
}

void ADMFMMOPlayerController::ApplyWorldChatInputMode()
{
    if (!IsLocalController() || !WorldChatWidget)
    {
        return;
    }

    if (ADMFPlayerAvatarCharacter* AvatarPawn = Cast<ADMFPlayerAvatarCharacter>(GetPawn()))
    {
        AvatarPawn->ResetNativeInputState();
    }

    if (!bWorldChatInputLocked)
    {
        SetIgnoreMoveInput(true);
        SetIgnoreLookInput(true);
        bWorldChatInputLocked = true;
    }

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = false;
    WorldChatWidget->SetVisibility(ESlateVisibility::Visible);
    WorldChatWidget->OpenChatInput();
}

void ADMFMMOPlayerController::RestoreWorldChatInputMode()
{
    if (bWorldChatInputLocked)
    {
        SetIgnoreMoveInput(false);
        SetIgnoreLookInput(false);
        bWorldChatInputLocked = false;
    }

    if (!bFrameworkModalInputLocked)
    {
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
}

FString ADMFMMOPlayerController::SanitizeWorldChatMessage(const FString& Message) const
{
    FString Sanitized = Message;
    Sanitized.ReplaceInline(TEXT("\r"), TEXT(" "));
    Sanitized.ReplaceInline(TEXT("\n"), TEXT(" "));
    Sanitized.ReplaceInline(TEXT("\t"), TEXT(" "));
    Sanitized.TrimStartAndEndInline();

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const int32 MaxLength = Settings ? FMath::Clamp(Settings->WorldChatMaxMessageLength, 32, 1000) : 220;
    if (Sanitized.Len() > MaxLength)
    {
        Sanitized = Sanitized.Left(MaxLength);
        Sanitized.TrimEndInline();
    }

    return Sanitized;
}

void ADMFMMOPlayerController::SendWorldChatMessage(const FString& Message)
{
    if (!IsLocalController())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableWorldChat)
    {
        return;
    }

    const FString LocalTrimmed = Message.TrimStartAndEnd();
    if (!LocalTrimmed.IsEmpty())
    {
        ServerSendWorldChatMessage(LocalTrimmed);
    }
}

void ADMFMMOPlayerController::ServerSendWorldChatMessage_Implementation(const FString& Message)
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableWorldChat)
    {
        ClientWorldChatSendRejected(NSLOCTEXT("DMF", "WorldChatDisabled", "World chat is disabled on this server."));
        return;
    }

    const FString Sanitized = SanitizeWorldChatMessage(Message);
    if (Sanitized.IsEmpty())
    {
        return;
    }

    UWorld* World = GetWorld();
    const double Now = World ? static_cast<double>(World->GetTimeSeconds()) : 0.0;
    const double MinimumInterval = Settings ? FMath::Clamp(static_cast<double>(Settings->WorldChatMinimumSendInterval), 0.1, 10.0) : 0.65;
    if ((Now - LastWorldChatAcceptedServerTime) < MinimumInterval)
    {
        ClientWorldChatSendRejected(NSLOCTEXT("DMF", "WorldChatSlowDown", "Please wait a moment before sending another message."));
        return;
    }

    const double BurstWindow = Settings ? FMath::Clamp(static_cast<double>(Settings->WorldChatBurstWindowSeconds), 1.0, 60.0) : 10.0;
    const int32 BurstLimit = Settings ? FMath::Clamp(Settings->WorldChatMaxMessagesPerBurst, 1, 60) : 8;
    const double OldestAllowedTime = Now - BurstWindow;
    RecentWorldChatAcceptedServerTimes.RemoveAll([OldestAllowedTime](const double AcceptedTime)
    {
        return AcceptedTime < OldestAllowedTime;
    });

    if (RecentWorldChatAcceptedServerTimes.Num() >= BurstLimit)
    {
        ClientWorldChatSendRejected(NSLOCTEXT("DMF", "WorldChatRateLimited", "You are sending messages too quickly. Please wait a few seconds."));
        return;
    }

    ADMFMMOGameMode* MMOGameMode = World ? World->GetAuthGameMode<ADMFMMOGameMode>() : nullptr;
    if (!MMOGameMode || !MMOGameMode->BroadcastWorldChatMessage(this, Sanitized))
    {
        ClientWorldChatSendRejected(NSLOCTEXT("DMF", "WorldChatUnavailable", "World chat is temporarily unavailable."));
        return;
    }

    LastWorldChatAcceptedServerTime = Now;
    RecentWorldChatAcceptedServerTimes.Add(Now);
}

void ADMFMMOPlayerController::ServerRequestWorldChatHistory_Implementation()
{
    ADMFMMOGameMode* MMOGameMode = GetWorld() ? GetWorld()->GetAuthGameMode<ADMFMMOGameMode>() : nullptr;
    if (MMOGameMode)
    {
        MMOGameMode->SendRecentWorldChatHistory(this);
    }
}

void ADMFMMOPlayerController::PlayWorldChatPresenceSound(const EDMFWorldChatMessageType MessageType) const
{
    if (!IsLocalController())
    {
        return;
    }

    const bool bJoined = MessageType == EDMFWorldChatMessageType::PlayerJoined;
    const bool bLeft = MessageType == EDMFWorldChatMessageType::PlayerLeft;
    if (!bJoined && !bLeft)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableWorldChat || !Settings->bEnableWorldChatPresenceAnnouncements || !Settings->bEnableWorldChatPresenceSounds)
    {
        return;
    }

    const TSoftObjectPtr<USoundBase>& ConfiguredSound = bJoined
        ? Settings->WorldChatPlayerJoinedSound
        : Settings->WorldChatPlayerLeftSound;
    if (ConfiguredSound.IsNull())
    {
        return;
    }

    if (USoundBase* Sound = ConfiguredSound.LoadSynchronous())
    {
        const float Volume = FMath::Clamp(Settings->WorldChatPresenceSoundVolumeMultiplier, 0.0f, 4.0f);
        const float Pitch = FMath::Clamp(Settings->WorldChatPresenceSoundPitchMultiplier, 0.25f, 4.0f);
        UGameplayStatics::PlaySound2D(this, Sound, Volume, Pitch);
    }
}

void ADMFMMOPlayerController::ClientReceiveWorldChatMessage_Implementation(const FDMFWorldChatMessage& ChatMessage)
{
    RefreshWorldChatUI();
    if (WorldChatWidget)
    {
        WorldChatWidget->AddChatMessage(ChatMessage);
    }

    // Presence audio is deliberately tied only to the live reliable delivery path.
    // ClientReceiveWorldChatHistory never calls this helper, preventing stale login/logout sounds on join.
    PlayWorldChatPresenceSound(ChatMessage.MessageType);
    OnWorldChatMessageReceived.Broadcast(ChatMessage);
}

void ADMFMMOPlayerController::ClientReceiveWorldChatHistory_Implementation(const TArray<FDMFWorldChatMessage>& ChatMessages)
{
    RefreshWorldChatUI();
    if (WorldChatWidget)
    {
        WorldChatWidget->SetChatHistory(ChatMessages);
    }
}

void ADMFMMOPlayerController::ClientWorldChatSendRejected_Implementation(const FText& Reason)
{
    RefreshWorldChatUI();
    if (WorldChatWidget)
    {
        WorldChatWidget->AddLocalSystemMessage(Reason);
    }
}

void ADMFMMOPlayerController::RequestSocialSnapshot()
{
    if (!IsLocalController())
    {
        return;
    }
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || Settings->bEnableSocialSystem)
    {
        ServerRequestSocialSnapshot();
    }
}

void ADMFMMOPlayerController::ExecuteLocalSocialAction(const EDMFSocialActionType ActionType, const FString& SubjectUsername, const FGuid GuildId, const FString& TextValue, const bool bValue)
{
    if (!IsLocalController())
    {
        return;
    }
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableSocialSystem)
    {
        HandleSocialActionResultPresentation(false, NSLOCTEXT("DMF", "SocialDisabledLocal", "The Social system is disabled on this server."));
        return;
    }
    ServerExecuteSocialAction(ActionType, SubjectUsername, GuildId, TextValue, bValue);
}

TArray<FDMFNearbySocialPlayerEntry> ADMFMMOPlayerController::GetNearbySocialPlayers() const
{
    TArray<FDMFNearbySocialPlayerEntry> Result;
    if (!IsLocalController() || GetNetMode() == NM_DedicatedServer)
    {
        return Result;
    }

    const APawn* LocalPawn = GetPawn();
    UWorld* World = GetWorld();
    if (!IsValid(LocalPawn) || !World)
    {
        return Result;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const float RadiusMeters = FMath::Clamp(Settings ? Settings->NearbyPlayerFriendDiscoveryRadiusMeters : 50.0f, 1.0f, 100000.0f);
    const float RadiusCentimeters = RadiusMeters * 100.0f;
    const float RadiusSquared = FMath::Square(RadiusCentimeters);

    auto Canonical = [](const FString& Value)
    {
        return Value.TrimStartAndEnd().ToLower();
    };

    TSet<FString> FriendKeys;
    for (const FDMFSocialFriendEntry& Friend : CachedSocialSnapshot.Friends)
    {
        const FString Key = Canonical(Friend.Username);
        if (!Key.IsEmpty()) FriendKeys.Add(Key);
    }

    TSet<FString> IncomingKeys;
    for (const FString& Username : CachedSocialSnapshot.PendingFriendRequests)
    {
        const FString Key = Canonical(Username);
        if (!Key.IsEmpty()) IncomingKeys.Add(Key);
    }

    TSet<FString> OutgoingKeys;
    for (const FString& Username : CachedSocialSnapshot.PendingOutgoingFriendRequests)
    {
        const FString Key = Canonical(Username);
        if (!Key.IsEmpty()) OutgoingKeys.Add(Key);
    }

    TSet<FString> IgnoredKeys;
    for (const FString& Username : CachedSocialSnapshot.IgnoredPlayers)
    {
        const FString Key = Canonical(Username);
        if (!Key.IsEmpty()) IgnoredKeys.Add(Key);
    }

    // A short-lived reconnect transition can briefly leave two replicated avatars with the same public name.
    // Keep only the nearest valid actor for that authenticated identity so the UI never duplicates a player.
    TMap<FString, FDMFNearbySocialPlayerEntry> NearestByUsername;
    for (TActorIterator<ADMFPlayerAvatarCharacter> It(World); It; ++It)
    {
        ADMFPlayerAvatarCharacter* Avatar = *It;
        if (!IsValid(Avatar) || Avatar == LocalPawn || Avatar->IsActorBeingDestroyed())
        {
            continue;
        }

        const ADMFPlayerState* State = Avatar->GetPlayerState<ADMFPlayerState>();
        if (!State)
        {
            continue;
        }

        const FString Username = State->GetPlayerName().TrimStartAndEnd();
        const FString Key = Canonical(Username);
        if (Username.IsEmpty() || Key.IsEmpty())
        {
            continue;
        }

        const float DistanceSquared = FVector::DistSquared(LocalPawn->GetActorLocation(), Avatar->GetActorLocation());
        if (DistanceSquared > RadiusSquared)
        {
            continue;
        }

        const float DistanceMeters = FMath::Sqrt(DistanceSquared) / 100.0f;
        if (FDMFNearbySocialPlayerEntry* Existing = NearestByUsername.Find(Key))
        {
            if (Existing->DistanceMeters <= DistanceMeters)
            {
                continue;
            }
        }

        FDMFNearbySocialPlayerEntry Entry;
        Entry.Username = Username;
        Entry.DistanceMeters = DistanceMeters;
        Entry.bIsFriend = FriendKeys.Contains(Key);
        Entry.bHasIncomingFriendRequest = IncomingKeys.Contains(Key);
        Entry.bHasOutgoingFriendRequest = OutgoingKeys.Contains(Key);
        Entry.bIsIgnored = IgnoredKeys.Contains(Key);
        NearestByUsername.Add(Key, MoveTemp(Entry));
    }

    NearestByUsername.GenerateValueArray(Result);
    Result.Sort([](const FDMFNearbySocialPlayerEntry& A, const FDMFNearbySocialPlayerEntry& B)
    {
        if (!FMath::IsNearlyEqual(A.DistanceMeters, B.DistanceMeters, 0.001f))
        {
            return A.DistanceMeters < B.DistanceMeters;
        }
        return A.Username.Compare(B.Username, ESearchCase::IgnoreCase) < 0;
    });
    return Result;
}

void ADMFMMOPlayerController::RequestAddFriend(const FString& TargetUsername) { ExecuteLocalSocialAction(EDMFSocialActionType::SendFriendRequest, TargetUsername); }
void ADMFMMOPlayerController::RespondToFriendRequest(const FString& RequesterUsername, const bool bAccept) { ExecuteLocalSocialAction(EDMFSocialActionType::RespondFriendRequest, RequesterUsername, FGuid(), FString(), bAccept); }
void ADMFMMOPlayerController::RequestCancelFriendRequest(const FString& TargetUsername) { ExecuteLocalSocialAction(EDMFSocialActionType::CancelFriendRequest, TargetUsername); }
void ADMFMMOPlayerController::RequestRemoveFriend(const FString& FriendUsername) { ExecuteLocalSocialAction(EDMFSocialActionType::RemoveFriend, FriendUsername); }
void ADMFMMOPlayerController::RequestSetFriendTracking(const FString& FriendUsername, const bool bEnabled) { ExecuteLocalSocialAction(EDMFSocialActionType::SetFriendTracking, FriendUsername, FGuid(), FString(), bEnabled); }
void ADMFMMOPlayerController::RequestIgnorePlayer(const FString& TargetUsername) { ExecuteLocalSocialAction(EDMFSocialActionType::IgnorePlayer, TargetUsername); }
void ADMFMMOPlayerController::RequestRemoveIgnoredPlayer(const FString& TargetUsername) { ExecuteLocalSocialAction(EDMFSocialActionType::RemoveIgnoredPlayer, TargetUsername); }
void ADMFMMOPlayerController::RequestCreateGuild(const FString& GuildName) { ExecuteLocalSocialAction(EDMFSocialActionType::CreateGuild, FString(), FGuid(), GuildName); }
void ADMFMMOPlayerController::RequestRenameGuild(const FString& GuildName) { ExecuteLocalSocialAction(EDMFSocialActionType::RenameGuild, FString(), FGuid(), GuildName); }
void ADMFMMOPlayerController::RequestInvitePlayerToGuild(const FString& TargetUsername) { ExecuteLocalSocialAction(EDMFSocialActionType::InvitePlayerToGuild, TargetUsername); }
void ADMFMMOPlayerController::RespondToGuildInvite(const FGuid GuildId, const bool bAccept) { ExecuteLocalSocialAction(EDMFSocialActionType::RespondGuildInvite, FString(), GuildId, FString(), bAccept); }
void ADMFMMOPlayerController::RequestApplyToGuild(const FGuid GuildId) { ExecuteLocalSocialAction(EDMFSocialActionType::ApplyToGuild, FString(), GuildId); }
void ADMFMMOPlayerController::RespondToGuildApplication(const FString& ApplicantUsername, const bool bAccept) { ExecuteLocalSocialAction(EDMFSocialActionType::RespondGuildApplication, ApplicantUsername, FGuid(), FString(), bAccept); }
void ADMFMMOPlayerController::RequestRemoveGuildMember(const FString& MemberUsername) { ExecuteLocalSocialAction(EDMFSocialActionType::RemoveGuildMember, MemberUsername); }
void ADMFMMOPlayerController::RequestLeaveGuild() { ExecuteLocalSocialAction(EDMFSocialActionType::LeaveGuild); }
void ADMFMMOPlayerController::RequestDisbandGuild() { ExecuteLocalSocialAction(EDMFSocialActionType::DisbandGuild); }

void ADMFMMOPlayerController::ServerRequestSocialSnapshot_Implementation()
{
    UWorld* World = GetWorld();
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const double Now = World ? static_cast<double>(World->GetTimeSeconds()) : 0.0;
    const double MinimumInterval = Settings
        ? static_cast<double>(FMath::Clamp(Settings->MinimumSocialSnapshotRequestInterval, 0.1f, 5.0f))
        : 0.35;
    if ((Now - LastSocialSnapshotAcceptedServerTime) < MinimumInterval)
    {
        return;
    }
    LastSocialSnapshotAcceptedServerTime = Now;

    if (ADMFMMOGameMode* MMOGameMode = World ? World->GetAuthGameMode<ADMFMMOGameMode>() : nullptr)
    {
        MMOGameMode->SendSocialSnapshot(this);
    }
}

void ADMFMMOPlayerController::ServerExecuteSocialAction_Implementation(const EDMFSocialActionType ActionType, const FString& SubjectUsername, const FGuid GuildId, const FString& TextValue, const bool bValue)
{
    UWorld* World = GetWorld();
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const double Now = World ? static_cast<double>(World->GetTimeSeconds()) : 0.0;
    const double MinimumInterval = Settings ? static_cast<double>(FMath::Clamp(Settings->MinimumSocialActionInterval, 0.05f, 5.0f)) : 0.15;
    if ((Now - LastSocialActionAcceptedServerTime) < MinimumInterval)
    {
        ClientSocialActionResult(false, NSLOCTEXT("DMF", "SocialActionRateLimited", "Please wait a moment before making another Social change."));
        return;
    }
    LastSocialActionAcceptedServerTime = Now;

    // Bound generic string payloads before they reach persistence/search logic. Usernames are much shorter in the
    // account system and guild names are capped at 64, so these are defensive network-abuse ceilings only.
    if (SubjectUsername.Len() > 128 || TextValue.Len() > 256)
    {
        ClientSocialActionResult(false, NSLOCTEXT("DMF", "SocialPayloadTooLarge", "That Social request contains invalid text."));
        return;
    }

    ADMFMMOGameMode* MMOGameMode = World ? World->GetAuthGameMode<ADMFMMOGameMode>() : nullptr;
    FText Message;
    const bool bSuccess = MMOGameMode && MMOGameMode->ExecuteSocialAction(this, ActionType, SubjectUsername, GuildId, TextValue, bValue, Message);
    if (!MMOGameMode && Message.IsEmpty())
    {
        Message = NSLOCTEXT("DMF", "SocialAuthorityUnavailable", "Social services are temporarily unavailable.");
    }
    ClientSocialActionResult(bSuccess, Message);
    if (MMOGameMode)
    {
        MMOGameMode->SendSocialSnapshot(this);
    }
}

void ADMFMMOPlayerController::ClientReceiveSocialSnapshot_Implementation(const FDMFSocialSnapshot& SocialSnapshot)
{
    if (!IsLocalController())
    {
        return;
    }

    CachedSocialSnapshot = SocialSnapshot;
    RefreshFriendTrackingPresentation();
    if (PlayerSocialContextWidget)
    {
        PlayerSocialContextWidget->RefreshActions();
    }
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->RefreshSocialData();
    }
    OnSocialSnapshotChanged.Broadcast(CachedSocialSnapshot);
}

void ADMFMMOPlayerController::ClientSocialActionResult_Implementation(const bool bSuccess, const FText& Message)
{
    HandleSocialActionResultPresentation(bSuccess, Message);
}

void ADMFMMOPlayerController::HandleSocialActionResultPresentation(const bool bSuccess, const FText& Message)
{
    if (!IsLocalController())
    {
        return;
    }

    if (!Message.IsEmpty())
    {
        RefreshWorldChatUI();
        if (WorldChatWidget)
        {
            WorldChatWidget->AddLocalSystemMessage(Message);
        }
    }
    if (DigimonInventoryWidget)
    {
        DigimonInventoryWidget->HandleSocialActionFeedback(bSuccess, Message);
    }
    OnSocialActionResult.Broadcast(bSuccess, Message);
}

void ADMFMMOPlayerController::OpenPlayerSocialContext(ADMFPlayerAvatarCharacter* TargetPlayer)
{
    if (!IsLocalController() || !IsValid(TargetPlayer) || TargetPlayer == GetPawn())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && (!Settings->bEnableSocialSystem || !Settings->bEnablePlayerNameplateSocialContext))
    {
        return;
    }

    // Render immediately from the last owner-only snapshot, then ask authority for a throttled refresh so
    // relationship/guild actions converge even if this context menu was opened after a long gameplay period.
    RequestSocialSnapshot();
    ClosePlayerSocialContextUI();
    TSubclassOf<UDMFPlayerSocialContextWidget> WidgetClass = Settings ? Settings->PlayerSocialContextWidgetClass : nullptr;
    if (!WidgetClass)
    {
        WidgetClass = UDMFPlayerSocialContextWidget::StaticClass();
    }

    PlayerSocialContextWidget = CreateWidget<UDMFPlayerSocialContextWidget>(this, WidgetClass);
    if (!PlayerSocialContextWidget)
    {
        return;
    }

    PlayerSocialContextWidget->SetTargetPlayer(TargetPlayer);
    PlayerSocialContextWidget->AddToViewport(650);

    float MouseX = 0.0f;
    float MouseY = 0.0f;
    int32 ViewportX = 0;
    int32 ViewportY = 0;
    GetViewportSize(ViewportX, ViewportY);
    if (GetMousePosition(MouseX, MouseY))
    {
        constexpr float Width = 286.0f;
        constexpr float EstimatedHeight = 260.0f;
        const float X = FMath::Clamp(MouseX + 14.0f, 8.0f, FMath::Max(8.0f, static_cast<float>(ViewportX) - Width - 8.0f));
        const float Y = FMath::Clamp(MouseY + 10.0f, 8.0f, FMath::Max(8.0f, static_cast<float>(ViewportY) - EstimatedHeight - 8.0f));
        PlayerSocialContextWidget->SetPositionInViewport(FVector2D(X, Y), false);
    }
}

void ADMFMMOPlayerController::ClosePlayerSocialContextUI()
{
    if (PlayerSocialContextWidget)
    {
        PlayerSocialContextWidget->RemoveFromParent();
        PlayerSocialContextWidget = nullptr;
    }
}

ADMFPlayerAvatarCharacter* ADMFMMOPlayerController::FindOnlinePlayerAvatarByUsername(const FString& Username) const
{
    UWorld* World = GetWorld();
    if (!World || Username.TrimStartAndEnd().IsEmpty())
    {
        return nullptr;
    }

    for (TActorIterator<ADMFPlayerAvatarCharacter> It(World); It; ++It)
    {
        ADMFPlayerAvatarCharacter* Avatar = *It;
        if (!IsValid(Avatar) || Avatar == GetPawn())
        {
            continue;
        }
        if (const ADMFPlayerState* State = Avatar->GetPlayerState<ADMFPlayerState>())
        {
            if (State->GetPlayerName().Equals(Username, ESearchCase::IgnoreCase))
            {
                return Avatar;
            }
        }
    }
    return nullptr;
}

void ADMFMMOPlayerController::DestroyFriendTrackerComponents()
{
    for (TPair<FString, TObjectPtr<UWidgetComponent>>& Pair : FriendTrackerComponents)
    {
        if (IsValid(Pair.Value))
        {
            Pair.Value->DestroyComponent();
        }
    }
    FriendTrackerComponents.Reset();
}

void ADMFMMOPlayerController::RefreshFriendTrackingPresentation()
{
    if (!IsLocalController() || GetNetMode() == NM_DedicatedServer)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableSocialSystem)
    {
        DestroyFriendTrackerComponents();
        return;
    }

    TMap<FString, const FDMFSocialFriendEntry*> Desired;
    for (const FDMFSocialFriendEntry& Friend : CachedSocialSnapshot.Friends)
    {
        if (Friend.bTrackingEnabled && Friend.bOnline && !Friend.Username.TrimStartAndEnd().IsEmpty())
        {
            Desired.Add(Friend.Username.TrimStartAndEnd().ToLower(), &Friend);
        }
    }

    TArray<FString> ExistingKeys;
    FriendTrackerComponents.GetKeys(ExistingKeys);
    for (const FString& Key : ExistingKeys)
    {
        TObjectPtr<UWidgetComponent>* Existing = FriendTrackerComponents.Find(Key);
        if (!Desired.Contains(Key) || !Existing || !IsValid(*Existing))
        {
            if (Existing && IsValid(*Existing))
            {
                (*Existing)->DestroyComponent();
            }
            FriendTrackerComponents.Remove(Key);
        }
    }

    for (const TPair<FString, const FDMFSocialFriendEntry*>& Pair : Desired)
    {
        ADMFPlayerAvatarCharacter* FriendAvatar = FindOnlinePlayerAvatarByUsername(Pair.Value->Username);
        if (!FriendAvatar)
        {
            if (TObjectPtr<UWidgetComponent>* Existing = FriendTrackerComponents.Find(Pair.Key))
            {
                if (IsValid(*Existing)) (*Existing)->DestroyComponent();
                FriendTrackerComponents.Remove(Pair.Key);
            }
            continue;
        }

        if (TObjectPtr<UWidgetComponent>* Existing = FriendTrackerComponents.Find(Pair.Key))
        {
            if (IsValid(*Existing) && (*Existing)->GetOwner() == FriendAvatar)
            {
                if (UDMFFriendTrackerWidget* Tracker = Cast<UDMFFriendTrackerWidget>((*Existing)->GetUserWidgetObject()))
                {
                    Tracker->SetObservedFriend(FriendAvatar);
                }
                continue;
            }
            if (IsValid(*Existing)) (*Existing)->DestroyComponent();
            FriendTrackerComponents.Remove(Pair.Key);
        }

        UWidgetComponent* TrackerComponent = NewObject<UWidgetComponent>(FriendAvatar, UWidgetComponent::StaticClass(), NAME_None, RF_Transient);
        if (!TrackerComponent)
        {
            continue;
        }

        TSubclassOf<UDMFFriendTrackerWidget> TrackerClass = Settings ? Settings->FriendTrackerWidgetClass : nullptr;
        if (!TrackerClass)
        {
            TrackerClass = UDMFFriendTrackerWidget::StaticClass();
        }

        TrackerComponent->SetIsReplicated(false);
        TrackerComponent->SetWidgetSpace(EWidgetSpace::Screen);
        TrackerComponent->SetDrawAtDesiredSize(true);
        TrackerComponent->SetPivot(FVector2D(0.5f, 1.0f));
        TrackerComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        TrackerComponent->SetGenerateOverlapEvents(false);
        TrackerComponent->SetWidgetClass(TrackerClass);
        if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
        {
            TrackerComponent->SetOwnerPlayer(LocalPlayer);
        }
        TrackerComponent->RegisterComponent();
        if (USceneComponent* FriendRoot = FriendAvatar->GetRootComponent())
        {
            TrackerComponent->AttachToComponent(FriendRoot, FAttachmentTransformRules::KeepRelativeTransform);
        }

        const float CapsuleHalfHeight = FriendAvatar->GetCapsuleComponent() ? FriendAvatar->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() : 96.0f;
        const float NameplateOffset = Settings ? FMath::Max(0.0f, Settings->PlayerNameplateHeightOffset) : 34.0f;
        const float TrackerOffset = Settings ? FMath::Max(0.0f, Settings->FriendTrackerHeightOffset) : 64.0f;
        TrackerComponent->SetRelativeLocation(FVector(0.0f, 0.0f, CapsuleHalfHeight + NameplateOffset + TrackerOffset));
        TrackerComponent->SetTickWhenOffscreen(false);
        TrackerComponent->InitWidget();
        if (UDMFFriendTrackerWidget* Tracker = Cast<UDMFFriendTrackerWidget>(TrackerComponent->GetUserWidgetObject()))
        {
            Tracker->SetObservedFriend(FriendAvatar);
        }
        FriendTrackerComponents.Add(Pair.Key, TrackerComponent);
    }
}

void ADMFMMOPlayerController::RefreshCombatQuickBar()
{
    if (!IsLocalController() || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || DigimonVendorWidget || ItemVendorWidget || IsWorldPresentationActive())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bShowNativeCombatQuickBar)
    {
        if (CombatQuickBarWidget)
        {
            CombatQuickBarWidget->RemoveFromParent();
            CombatQuickBarWidget = nullptr;
        }
        return;
    }

    if (!CombatQuickBarWidget)
    {
        TSubclassOf<UDMFCombatQuickBarWidget> WidgetClass = Settings ? Settings->CombatQuickBarWidgetClass : nullptr;
        if (!WidgetClass)
        {
            WidgetClass = UDMFCombatQuickBarWidget::StaticClass();
        }
        CombatQuickBarWidget = CreateWidget<UDMFCombatQuickBarWidget>(this, WidgetClass);
        if (CombatQuickBarWidget)
        {
            CombatQuickBarWidget->AddToViewport(100);
        }
    }
}

void ADMFMMOPlayerController::RefreshPartyQuickBar()
{
    if (!IsLocalController() || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || DigimonVendorWidget || ItemVendorWidget || IsWorldPresentationActive())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bShowNativePartyQuickBar)
    {
        if (PartyQuickBarWidget)
        {
            PartyQuickBarWidget->RemoveFromParent();
            PartyQuickBarWidget = nullptr;
        }
        if (bPartyQuickAccessInteractionActive)
        {
            ClosePartyQuickAccessInteraction();
        }
        return;
    }

    if (!PartyQuickBarWidget)
    {
        TSubclassOf<UDMFPartyQuickBarWidget> WidgetClass = Settings ? Settings->PartyQuickBarWidgetClass : nullptr;
        if (!WidgetClass)
        {
            WidgetClass = UDMFPartyQuickBarWidget::StaticClass();
        }
        PartyQuickBarWidget = CreateWidget<UDMFPartyQuickBarWidget>(this, WidgetClass);
        if (PartyQuickBarWidget)
        {
            PartyQuickBarWidget->AddToViewport(120);
        }
    }
    if (PartyQuickBarWidget)
    {
        PartyQuickBarWidget->SetInteractionMode(bPartyQuickAccessInteractionActive);
        PartyQuickBarWidget->RefreshParty();
    }
}

void ADMFMMOPlayerController::OpenPartyQuickAccessInteraction()
{
    if (!IsLocalController() || bPartyQuickAccessInteractionActive || IsWorldPresentationActive() || bWorldChatInputActive
        || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || DigimonVendorWidget || ItemVendorWidget)
    {
        return;
    }

    RefreshPartyQuickBar();
    if (!PartyQuickBarWidget)
    {
        return;
    }

    if (ADMFPlayerAvatarCharacter* AvatarPawn = Cast<ADMFPlayerAvatarCharacter>(GetPawn()))
    {
        AvatarPawn->ResetNativeInputState();
    }
    if (!bPartyQuickAccessInputLocked)
    {
        SetIgnoreMoveInput(true);
        SetIgnoreLookInput(true);
        bPartyQuickAccessInputLocked = true;
    }

    bPartyQuickAccessInteractionActive = true;
    FInputModeGameAndUI InputMode;
    InputMode.SetHideCursorDuringCapture(false);
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    SetInputMode(InputMode);
    bShowMouseCursor = true;
    PartyQuickBarWidget->SetInteractionMode(true);
}

void ADMFMMOPlayerController::ClosePartyQuickAccessInteraction()
{
    if (!IsLocalController())
    {
        return;
    }

    bPartyQuickAccessInteractionActive = false;
    if (PartyQuickBarWidget)
    {
        PartyQuickBarWidget->SetInteractionMode(false);
    }
    if (bPartyQuickAccessInputLocked)
    {
        SetIgnoreMoveInput(false);
        SetIgnoreLookInput(false);
        bPartyQuickAccessInputLocked = false;
    }
    if (!bFrameworkModalInputLocked && !bWorldChatInputActive)
    {
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
}

void ADMFMMOPlayerController::TogglePartyQuickAccessInteraction()
{
    if (bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
    else
    {
        OpenPartyQuickAccessInteraction();
    }
}

void ADMFMMOPlayerController::RequestReturnHome()
{
    if (!IsLocalController() || IsWorldPresentationActive() || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || DigimonVendorWidget || ItemVendorWidget || bWorldChatInputActive)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnablePartyQuickAccessHomeButton)
    {
        OnHomeTeleportResult.Broadcast(false, NSLOCTEXT("DMF", "ReturnHomeDisabledLocal", "Return Home is disabled for this world."));
        return;
    }

    ServerRequestReturnHome();
}

void ADMFMMOPlayerController::ServerRequestReturnHome_Implementation()
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnablePartyQuickAccessHomeButton)
    {
        ClientReturnHomeResult(false, NSLOCTEXT("DMF", "ReturnHomeDisabledServer", "Return Home is disabled for this world."));
        return;
    }

    UWorld* World = GetWorld();
    ADMFMMOGameMode* GameMode = World ? World->GetAuthGameMode<ADMFMMOGameMode>() : nullptr;
    if (!World || !GameMode)
    {
        ClientReturnHomeResult(false, NSLOCTEXT("DMF", "ReturnHomeWorldUnavailable", "Return Home is unavailable in this map."));
        return;
    }

    const double Now = World->GetTimeSeconds();
    const double Cooldown = Settings ? FMath::Max(0.0, static_cast<double>(Settings->HomeTeleportRequestCooldownSeconds)) : 4.0;
    const double Remaining = (LastReturnHomeAcceptedServerTime + Cooldown) - Now;
    if (Remaining > KINDA_SMALL_NUMBER)
    {
        ClientReturnHomeResult(false, FText::Format(
            NSLOCTEXT("DMF", "ReturnHomeCooldown", "Return Home will be ready again in {0} seconds."),
            FText::AsNumber(FMath::CeilToInt(Remaining))));
        return;
    }

    FText Message;
    const bool bSuccess = GameMode->ReturnAuthenticatedPlayerHome(this, Message);
    if (bSuccess)
    {
        LastReturnHomeAcceptedServerTime = Now;
    }
    ClientReturnHomeResult(bSuccess, Message.IsEmpty()
        ? (bSuccess ? NSLOCTEXT("DMF", "ReturnHomeSuccessFallback", "Teleported Home.") : NSLOCTEXT("DMF", "ReturnHomeFailureFallback", "Return Home failed."))
        : Message);
}

void ADMFMMOPlayerController::ClientReturnHomeResult_Implementation(const bool bSuccess, const FText& Message)
{
    if (!IsLocalController())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if ((!Settings || Settings->bShowNativeHomeTeleportNotifications))
    {
        if (!HomeTeleportNotificationWidget)
        {
            TSubclassOf<UDMFHomeTeleportNotificationWidget> WidgetClass = Settings ? Settings->HomeTeleportNotificationWidgetClass : nullptr;
            if (!WidgetClass)
            {
                WidgetClass = UDMFHomeTeleportNotificationWidget::StaticClass();
            }
            HomeTeleportNotificationWidget = CreateWidget<UDMFHomeTeleportNotificationWidget>(this, WidgetClass);
            if (HomeTeleportNotificationWidget)
            {
                HomeTeleportNotificationWidget->AddToViewport(875);
            }
        }
        if (HomeTeleportNotificationWidget)
        {
            HomeTeleportNotificationWidget->ShowHomeTeleportResult(bSuccess, Message);
        }
    }

    OnHomeTeleportResult.Broadcast(bSuccess, Message);

    if (bSuccess && bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
    RefreshPartyQuickBar();
    RefreshCombatQuickBar();
}

void ADMFMMOPlayerController::EnsureTargetingPresentation()
{
    if (!IsLocalController() || GetNetMode() == NM_DedicatedServer || IsValid(TargetingPresentationActor))
    {
        return;
    }

    // Always keep the tiny local-only presentation actor available. The actor itself reads the
    // global enable switch and hides all components while targeting visuals are disabled. This also
    // allows Project Settings changes made during PIE to become visible without restarting the world.
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = GetPawn();
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    SpawnParams.ObjectFlags |= RF_Transient;
    TargetingPresentationActor = World->SpawnActor<ADMFTargetingPresentationActor>(
        ADMFTargetingPresentationActor::StaticClass(),
        FTransform::Identity,
        SpawnParams);
}

void ADMFMMOPlayerController::RefreshTargetingVisuals()
{
    EnsureTargetingPresentation();
    if (IsValid(TargetingPresentationActor))
    {
        TargetingPresentationActor->RefreshPresentationAssets();
    }
}

void ADMFMMOPlayerController::SetDigimonCommandTarget(ADMFDigimonCharacter* NewTarget)
{
    if (IsWorldPresentationActive() || bWorldChatInputActive || bPartyQuickAccessInteractionActive) return;
    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (DMFPlayerState && DMFPlayerState->DigimonComponent)
    {
        DMFPlayerState->DigimonComponent->ServerSetCommandTarget(NewTarget);
    }
}

bool ADMFMMOPlayerController::SelectDigimonCommandTargetUnderCursor()
{
    FHitResult Hit;
    bool bHit = false;

    float MouseX = 0.0f;
    float MouseY = 0.0f;
    if (bShowMouseCursor && GetMousePosition(MouseX, MouseY))
    {
        bHit = GetHitResultAtScreenPosition(FVector2D(MouseX, MouseY), ECC_Visibility, false, Hit);
    }
    else
    {
        int32 ViewportX = 0;
        int32 ViewportY = 0;
        GetViewportSize(ViewportX, ViewportY);
        if (ViewportX > 0 && ViewportY > 0)
        {
            bHit = GetHitResultAtScreenPosition(FVector2D(ViewportX * 0.5f, ViewportY * 0.5f), ECC_Visibility, false, Hit);
        }
    }

    if (!bHit)
    {
        return false;
    }

    ADMFDigimonCharacter* Target = Cast<ADMFDigimonCharacter>(Hit.GetActor());
    if (!Target)
    {
        return false;
    }
    SetDigimonCommandTarget(Target);
    return true;
}

void ADMFMMOPlayerController::CommandPartnerTargetAndAttack(ADMFDigimonCharacter* Target, const int32 SlotIndex)
{
    if (IsWorldPresentationActive() || bWorldChatInputActive || bPartyQuickAccessInteractionActive || !Target || SlotIndex < 0)
    {
        return;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (DMFPlayerState && DMFPlayerState->DigimonComponent)
    {
        DMFPlayerState->DigimonComponent->ServerCommandActivePartnerAbilitySlot(SlotIndex, Target);
    }
}

void ADMFMMOPlayerController::CommandActivePartnerAbilitySlot(const int32 SlotIndex)
{
    if (IsWorldPresentationActive() || bWorldChatInputActive || bPartyQuickAccessInteractionActive || SlotIndex < 0)
    {
        return;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (DMFPlayerState && DMFPlayerState->DigimonComponent)
    {
        DMFPlayerState->DigimonComponent->ServerCommandActivePartnerAbilitySlot(SlotIndex, DMFPlayerState->DigimonComponent->GetCommandTarget());
    }
}

void ADMFMMOPlayerController::RequestUseHealer(ADMFHealerActor* Healer)
{
    if (IsLocalController() && IsValid(Healer))
    {
        ServerRequestUseHealer(Healer);
    }
}

void ADMFMMOPlayerController::ServerRequestUseHealer_Implementation(ADMFHealerActor* Healer)
{
    if (!IsValid(Healer))
    {
        ClientHealerInteractionResult(false, NSLOCTEXT("DMF", "InvalidHealer", "That healer is unavailable."), 0);
        return;
    }

    int32 DigimonHealed = 0;
    FText Message;
    const bool bSuccess = Healer->TryHealPlayerAuthoritative(this, DigimonHealed, Message);
    ClientHealerInteractionResult(bSuccess, Message, DigimonHealed);
}

void ADMFMMOPlayerController::ClientHealerInteractionResult_Implementation(const bool bSuccess, const FText& Message, const int32 DigimonHealed)
{
    OnHealerInteractionResult.Broadcast(bSuccess, Message, DigimonHealed);
    RefreshDigimonInventoryUI();
    RefreshCombatQuickBar();
    RefreshPartyQuickBar();
}

void ADMFMMOPlayerController::HandleDefaultTargetInput()
{
    if (!PlayerSkinWidget && !StarterWidget && !DigimonInventoryWidget && !DigimonVendorWidget && !ItemVendorWidget && !IsWorldPresentationActive() && !bWorldChatInputActive && !bPartyQuickAccessInteractionActive)
    {
        SelectDigimonCommandTargetUnderCursor();
    }
}

void ADMFMMOPlayerController::HandleWorldChatInput()
{
    if (!bWorldChatInputActive && !bPartyQuickAccessInteractionActive)
    {
        OpenWorldChatInput();
    }
}

void ADMFMMOPlayerController::HandlePartyQuickAccessInput()
{
    if (!bWorldChatInputActive && !PlayerSkinWidget && !StarterWidget && !DigimonInventoryWidget && !DigimonVendorWidget && !ItemVendorWidget && !IsWorldPresentationActive())
    {
        TogglePartyQuickAccessInteraction();
    }
}

void ADMFMMOPlayerController::HandlePartyQuickAccessCancelInput()
{
    if (bPartyQuickAccessInteractionActive)
    {
        ClosePartyQuickAccessInteraction();
    }
}

void ADMFMMOPlayerController::HandlePlayerSkinMenuInput()
{
    if (!bWorldChatInputActive && !bPartyQuickAccessInteractionActive)
    {
        TogglePlayerSkinSelectionUI();
    }
}

void ADMFMMOPlayerController::HandleDigimonInventoryMenuInput()
{
    if (!bWorldChatInputActive && !bPartyQuickAccessInteractionActive)
    {
        ToggleDigimonInventoryUI();
    }
}

void ADMFMMOPlayerController::ExecuteDefaultAbilitySlot(const int32 SlotIndex)
{
    if (PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || DigimonVendorWidget || ItemVendorWidget || IsWorldPresentationActive() || bWorldChatInputActive || bPartyQuickAccessInteractionActive)
    {
        return;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (DMFPlayerState && DMFPlayerState->DigimonComponent)
    {
        DMFPlayerState->DigimonComponent->ServerCommandActivePartnerAbilitySlot(SlotIndex, DMFPlayerState->DigimonComponent->GetCommandTarget());
    }
}

void ADMFMMOPlayerController::HandleAbilitySlot1() { ExecuteDefaultAbilitySlot(0); }
void ADMFMMOPlayerController::HandleAbilitySlot2() { ExecuteDefaultAbilitySlot(1); }
void ADMFMMOPlayerController::HandleAbilitySlot3() { ExecuteDefaultAbilitySlot(2); }
void ADMFMMOPlayerController::HandleAbilitySlot4() { ExecuteDefaultAbilitySlot(3); }
