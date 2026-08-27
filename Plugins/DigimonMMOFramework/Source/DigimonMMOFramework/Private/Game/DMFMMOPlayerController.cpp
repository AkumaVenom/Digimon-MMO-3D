#include "Game/DMFMMOPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFHealerActor.h"
#include "Game/DMFMMOGameMode.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Game/DMFPlayerState.h"
#include "Game/DMFTargetingPresentationActor.h"
#include "InputCoreTypes.h"
#include "Settings/DMFFrameworkSettings.h"
#include "TimerManager.h"
#include "UI/DMFCombatQuickBarWidget.h"
#include "UI/DMFPartyQuickBarWidget.h"
#include "UI/DMFDigimonInventoryWidget.h"
#include "UI/DMFScanNotificationWidget.h"
#include "UI/DMFPlayerSkinSelectionWidget.h"
#include "UI/DMFStarterSelectionWidget.h"
#include "UI/DMFWorldChatWidget.h"

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
        else if (!DigimonInventoryWidget)
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

        if (!PlayerSkinWidget && !DigimonInventoryWidget)
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
        || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || bPartyQuickAccessInteractionActive)
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

void ADMFMMOPlayerController::ClientReceiveWorldChatMessage_Implementation(const FDMFWorldChatMessage& ChatMessage)
{
    RefreshWorldChatUI();
    if (WorldChatWidget)
    {
        WorldChatWidget->AddChatMessage(ChatMessage);
    }
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

void ADMFMMOPlayerController::RefreshCombatQuickBar()
{
    if (!IsLocalController() || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || IsWorldPresentationActive())
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
    if (!IsLocalController() || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || IsWorldPresentationActive())
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
        || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget)
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
    if (!PlayerSkinWidget && !StarterWidget && !DigimonInventoryWidget && !IsWorldPresentationActive() && !bWorldChatInputActive && !bPartyQuickAccessInteractionActive)
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
    if (!bWorldChatInputActive && !PlayerSkinWidget && !StarterWidget && !DigimonInventoryWidget && !IsWorldPresentationActive())
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
    if (PlayerSkinWidget || StarterWidget || DigimonInventoryWidget || IsWorldPresentationActive() || bWorldChatInputActive || bPartyQuickAccessInteractionActive)
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
