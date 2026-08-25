#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "DMFDigimonInventoryEntryButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFDigimonInventoryEntryPressed, FGuid, InstanceId);

/** Native entry button used by the fallback Digimon roster UI. */
UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFDigimonInventoryEntryButton : public UButton
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Inventory")
    FDMFDigimonInventoryEntryPressed OnDigimonPressed;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Inventory")
    FGuid InstanceId;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Inventory")
    void InitializeDigimonEntry(FGuid InInstanceId);

private:
    UFUNCTION()
    void HandlePressed();
};
