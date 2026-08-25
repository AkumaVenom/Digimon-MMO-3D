#include "Game/DMFMMOPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/InputComponent.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFHealerActor.h"
#include "Game/DMFMMOGameMode.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Game/DMFPlayerState.h"
#include "InputCoreTypes.h"
#include "Settings/DMFFrameworkSettings.h"
#include "TimerManager.h"
#include "UI/DMFCombatQuickBarWidget.h"
#include "UI/DMFDigimonInventoryWidget.h"
#include "UI/DMFScanNotificationWidget.h"
#include "UI/DMFPlayerSkinSelectionWidget.h"
#include "UI/DMFStarterSelectionWidget.h"

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
    GetWorldTimerManager().ClearTimer(StarterUIRetryTimer);
    RefreshStarterSelectionUI();
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
    if (!IsLocalController())
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
    if (!IsLocalController())
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
    if (!IsLocalController())
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

    if (CombatQuickBarWidget)
    {
        CombatQuickBarWidget->RemoveFromParent();
        CombatQuickBarWidget = nullptr;
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
    }
}

void ADMFMMOPlayerController::ToggleDigimonInventoryUI()
{
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
        DigimonInventoryWidget->RefreshScanData();
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

void ADMFMMOPlayerController::ApplyFrameworkModalInputMode()
{
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

void ADMFMMOPlayerController::RefreshCombatQuickBar()
{
    if (!IsLocalController() || PlayerSkinWidget || StarterWidget || DigimonInventoryWidget)
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

void ADMFMMOPlayerController::SetDigimonCommandTarget(ADMFDigimonCharacter* NewTarget)
{
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
    if (!Target || SlotIndex < 0)
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
    if (SlotIndex < 0)
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
}

void ADMFMMOPlayerController::HandleDefaultTargetInput()
{
    if (!PlayerSkinWidget && !StarterWidget && !DigimonInventoryWidget)
    {
        SelectDigimonCommandTargetUnderCursor();
    }
}

void ADMFMMOPlayerController::HandlePlayerSkinMenuInput()
{
    TogglePlayerSkinSelectionUI();
}

void ADMFMMOPlayerController::HandleDigimonInventoryMenuInput()
{
    ToggleDigimonInventoryUI();
}

void ADMFMMOPlayerController::ExecuteDefaultAbilitySlot(const int32 SlotIndex)
{
    if (PlayerSkinWidget || StarterWidget || DigimonInventoryWidget)
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
