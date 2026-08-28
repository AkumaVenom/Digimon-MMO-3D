#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DMFFrontendHUD.generated.h"

class UDMFLoginMainMenuWidget;
class UUserWidget;

UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFFrontendHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    void EnsureFrontendBackgroundWidget();
    void ScheduleFrontendBackgroundRetry();
    void ScheduleFrontendLoginBootstrap();
    void BeginFrontendBootstrap();
    void EnsureFrontendWidget();
    void ScheduleFrontendRetry();

    UPROPERTY(Transient)
    TObjectPtr<UUserWidget> FrontendBackgroundWidget;

    UPROPERTY(Transient)
    TObjectPtr<UDMFLoginMainMenuWidget> FrontendWidget;

    bool bFrontendLoginBootstrapScheduled = false;
    FTimerHandle FrontendBackgroundBootstrapTimer;
    FTimerHandle FrontendStartupDelayTimer;
    FTimerHandle FrontendBootstrapTimer;
};
