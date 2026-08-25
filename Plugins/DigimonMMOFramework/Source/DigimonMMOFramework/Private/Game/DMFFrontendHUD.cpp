#include "Game/DMFFrontendHUD.h"
#include "DigimonMMOFramework.h"
#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFLoginMainMenuWidget.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "Engine/World.h"

void ADMFFrontendHUD::BeginPlay()
{
    Super::BeginPlay();

    EnsureFrontendWidget();

    if (!FrontendWidget)
    {
        if (UWorld* World = GetWorld())
        {
            World->GetTimerManager().SetTimer(
                FrontendBootstrapTimer,
                this,
                &ADMFFrontendHUD::EnsureFrontendWidget,
                0.10f,
                true,
                0.10f);
        }
    }
}

void ADMFFrontendHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(FrontendBootstrapTimer);
    }

    if (FrontendWidget)
    {
        FrontendWidget->RemoveFromParent();
        FrontendWidget = nullptr;
    }

    Super::EndPlay(EndPlayReason);
}

void ADMFFrontendHUD::EnsureFrontendWidget()
{
    if (FrontendWidget && FrontendWidget->IsInViewport())
    {
        if (UWorld* World = GetWorld())
        {
            World->GetTimerManager().ClearTimer(FrontendBootstrapTimer);
        }
        return;
    }

    APlayerController* PC = GetOwningPlayerController();
    if (!PC)
    {
        PC = PlayerOwner;
    }
    if (!PC)
    {
        if (UWorld* World = GetWorld())
        {
            PC = World->GetFirstPlayerController();
        }
    }

    if (!PC || !PC->IsLocalController())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    TSubclassOf<UDMFLoginMainMenuWidget> WidgetClass = Settings ? Settings->LoginWidgetClass : nullptr;
    if (!WidgetClass)
    {
        WidgetClass = UDMFLoginMainMenuWidget::StaticClass();
    }

    if (!FrontendWidget)
    {
        FrontendWidget = CreateWidget<UDMFLoginMainMenuWidget>(PC, WidgetClass);
    }

    if (!FrontendWidget)
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("Frontend HUD could not create login/main-menu widget class '%s'."), *GetNameSafe(WidgetClass.Get()));
        return;
    }

    if (!FrontendWidget->IsInViewport())
    {
        const bool bAddedToPlayerScreen = FrontendWidget->AddToPlayerScreen(1000);
        if (!bAddedToPlayerScreen)
        {
            FrontendWidget->AddToViewport(1000);
        }
    }

    FrontendWidget->SetVisibility(ESlateVisibility::Visible);

    FInputModeUIOnly InputMode;
    InputMode.SetWidgetToFocus(FrontendWidget->TakeWidget());
    PC->SetInputMode(InputMode);
    PC->bShowMouseCursor = true;

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(FrontendBootstrapTimer);
    }

    UE_LOG(LogDigimonMMOFramework, Log, TEXT("Frontend login/main-menu widget initialized for local player '%s'."), *GetNameSafe(PC));
}
