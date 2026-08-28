#include "Game/DMFFrontendHUD.h"
#include "DigimonMMOFramework.h"
#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFLoginMainMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "Engine/World.h"

namespace
{
    constexpr int32 DMFFrontendBackgroundZOrderGap = 100;

    int32 ResolveFrontendLoginZOrder(const UDMFFrameworkSettings* Settings)
    {
        return Settings ? FMath::Clamp(Settings->FrontendUIViewportZOrder, -100000, 100000) : 1000;
    }

    int32 ResolveFrontendBackgroundZOrder(const UDMFFrameworkSettings* Settings)
    {
        return ResolveFrontendLoginZOrder(Settings) - DMFFrontendBackgroundZOrderGap;
    }

    APlayerController* ResolveLocalFrontendPlayerController(ADMFFrontendHUD* HUD)
    {
        if (!HUD)
        {
            return nullptr;
        }

        APlayerController* PC = HUD->GetOwningPlayerController();
        if (!PC)
        {
            if (UWorld* World = HUD->GetWorld())
            {
                PC = World->GetFirstPlayerController();
            }
        }

        return (PC && PC->IsLocalController()) ? PC : nullptr;
    }

    bool AddFrontendWidgetToViewport(UUserWidget* Widget, const int32 ZOrder)
    {
        if (!Widget)
        {
            return false;
        }

        if (!Widget->IsInViewport())
        {
            // Frontend uses the global game viewport deliberately. Background and login must share the
            // same Slate layer so their Z-orders are directly comparable; mixing AddToPlayerScreen with
            // a project AddToViewport background can otherwise allow a fullscreen background to cover login.
            Widget->AddToViewport(ZOrder);
        }

        return Widget->IsInViewport();
    }
}

void ADMFFrontendHUD::BeginPlay()
{
    Super::BeginPlay();

    // v0.15.0: the framework now owns the complete local frontend stack. The optional project-authored
    // background is created first and the login/menu layer is scheduled only after that background is ready.
    EnsureFrontendBackgroundWidget();
}

void ADMFFrontendHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(FrontendBackgroundBootstrapTimer);
        World->GetTimerManager().ClearTimer(FrontendStartupDelayTimer);
        World->GetTimerManager().ClearTimer(FrontendBootstrapTimer);
    }

    if (FrontendWidget)
    {
        FrontendWidget->RemoveFromParent();
        FrontendWidget = nullptr;
    }

    if (FrontendBackgroundWidget)
    {
        FrontendBackgroundWidget->RemoveFromParent();
        FrontendBackgroundWidget = nullptr;
    }

    bFrontendLoginBootstrapScheduled = false;

    Super::EndPlay(EndPlayReason);
}

void ADMFFrontendHUD::EnsureFrontendBackgroundWidget()
{
    APlayerController* PC = ResolveLocalFrontendPlayerController(this);
    if (!PC)
    {
        ScheduleFrontendBackgroundRetry();
        return;
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(FrontendBackgroundBootstrapTimer);
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const TSubclassOf<UUserWidget> BackgroundWidgetClass = Settings ? Settings->FrontendBackgroundWidgetClass : nullptr;

    if (BackgroundWidgetClass)
    {
        if (!FrontendBackgroundWidget)
        {
            FrontendBackgroundWidget = CreateWidget<UUserWidget>(PC, BackgroundWidgetClass);
        }

        if (!FrontendBackgroundWidget)
        {
            // A decorative/background class must never lock the player out of the authoritative login flow.
            UE_LOG(
                LogDigimonMMOFramework,
                Error,
                TEXT("Frontend HUD could not create background widget class '%s'. Continuing with login/main-menu layer."),
                *GetNameSafe(BackgroundWidgetClass.Get()));
        }
        else
        {
            const int32 BackgroundZOrder = ResolveFrontendBackgroundZOrder(Settings);
            if (!AddFrontendWidgetToViewport(FrontendBackgroundWidget, BackgroundZOrder))
            {
                UE_LOG(
                    LogDigimonMMOFramework,
                    Warning,
                    TEXT("Frontend background widget '%s' could not be added to the local screen. Continuing with login/main-menu layer."),
                    *GetNameSafe(FrontendBackgroundWidget));
            }
            else
            {
                FrontendBackgroundWidget->SetVisibility(ESlateVisibility::Visible);
                UE_LOG(
                    LogDigimonMMOFramework,
                    Log,
                    TEXT("Frontend background widget '%s' initialized for local player '%s' at Z-order %d."),
                    *GetNameSafe(FrontendBackgroundWidget),
                    *GetNameSafe(PC),
                    BackgroundZOrder);
            }
        }
    }

    ScheduleFrontendLoginBootstrap();
}

void ADMFFrontendHUD::ScheduleFrontendBackgroundRetry()
{
    if (UWorld* World = GetWorld())
    {
        if (!World->GetTimerManager().IsTimerActive(FrontendBackgroundBootstrapTimer))
        {
            World->GetTimerManager().SetTimer(
                FrontendBackgroundBootstrapTimer,
                this,
                &ADMFFrontendHUD::EnsureFrontendBackgroundWidget,
                0.10f,
                true,
                0.10f);
        }
    }
}

void ADMFFrontendHUD::ScheduleFrontendLoginBootstrap()
{
    if (bFrontendLoginBootstrapScheduled)
    {
        return;
    }

    bFrontendLoginBootstrapScheduled = true;

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const float StartupDelaySeconds = Settings ? FMath::Max(0.0f, Settings->FrontendUIStartupDelaySeconds) : 0.25f;

    if (StartupDelaySeconds <= KINDA_SMALL_NUMBER)
    {
        BeginFrontendBootstrap();
        return;
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().SetTimer(
            FrontendStartupDelayTimer,
            this,
            &ADMFFrontendHUD::BeginFrontendBootstrap,
            StartupDelaySeconds,
            false);

        UE_LOG(
            LogDigimonMMOFramework,
            Verbose,
            TEXT("Frontend login/main-menu layer deferred by %.2f seconds after framework background initialization."),
            StartupDelaySeconds);
        return;
    }

    BeginFrontendBootstrap();
}

void ADMFFrontendHUD::BeginFrontendBootstrap()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(FrontendStartupDelayTimer);
    }

    EnsureFrontendWidget();

    if (!FrontendWidget || !FrontendWidget->IsInViewport())
    {
        ScheduleFrontendRetry();
    }
}

void ADMFFrontendHUD::ScheduleFrontendRetry()
{
    if (UWorld* World = GetWorld())
    {
        if (!World->GetTimerManager().IsTimerActive(FrontendBootstrapTimer))
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

    APlayerController* PC = ResolveLocalFrontendPlayerController(this);
    if (!PC)
    {
        ScheduleFrontendRetry();
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
        ScheduleFrontendRetry();
        return;
    }

    const int32 LoginZOrder = ResolveFrontendLoginZOrder(Settings);
    if (!AddFrontendWidgetToViewport(FrontendWidget, LoginZOrder))
    {
        ScheduleFrontendRetry();
        return;
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

    UE_LOG(
        LogDigimonMMOFramework,
        Log,
        TEXT("Frontend login/main-menu widget initialized for local player '%s' at Z-order %d. Background is guaranteed below this layer."),
        *GetNameSafe(PC),
        LoginZOrder);
}
