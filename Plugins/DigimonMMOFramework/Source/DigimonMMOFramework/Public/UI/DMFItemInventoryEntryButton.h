#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "DMFItemInventoryEntryButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFItemInventoryEntryPressed, FGuid, StackId);

/** Native stack button used by the polished ITEMS page. Stack identity never contains gameplay effect values. */
UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFItemInventoryEntryButton : public UButton
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Items")
    FDMFItemInventoryEntryPressed OnItemStackPressed;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Items")
    FGuid StackId;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Items")
    void InitializeItemEntry(FGuid InStackId);

private:
    UFUNCTION()
    void HandlePressed();
};
