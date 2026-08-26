#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "DMFPartyDestinationButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFPartyDestinationPressed, int32, PartySlotIndex);

/** Lightweight native button used by the Bank page to choose a Party swap destination. */
UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFPartyDestinationButton : public UButton
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Party & Bank")
    FDMFPartyDestinationPressed OnPartyDestinationPressed;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Party & Bank")
    int32 PartySlotIndex = INDEX_NONE;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party & Bank")
    void InitializePartyDestination(int32 InPartySlotIndex);

private:
    UFUNCTION()
    void HandlePressed();
};
