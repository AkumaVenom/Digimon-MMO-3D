#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UObject/PrimaryAssetId.h"
#include "DMFStarterEntryButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFStarterEntryPressed, FPrimaryAssetId, SpeciesId);

UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFStarterEntryButton : public UButton
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FDMFStarterEntryPressed OnStarterPressed;

    UPROPERTY(BlueprintReadOnly)
    FPrimaryAssetId SpeciesId;

    UFUNCTION(BlueprintCallable)
    void InitializeStarterChoice(FPrimaryAssetId InSpeciesId);

private:
    UFUNCTION()
    void HandlePressed();
};
