#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DMFFrontendHUD.generated.h"

class UDMFLoginMainMenuWidget;

UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFFrontendHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    void EnsureFrontendWidget();

    UPROPERTY(Transient)
    TObjectPtr<UDMFLoginMainMenuWidget> FrontendWidget;

    FTimerHandle FrontendBootstrapTimer;
};
