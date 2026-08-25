#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UObject/PrimaryAssetId.h"
#include "DMFScanSpeciesEntryButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFScanSpeciesPressed, FPrimaryAssetId, SpeciesId);

/** Payload-aware native scan database card button. */
UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFScanSpeciesEntryButton : public UButton
{
    GENERATED_BODY()
public:
    void InitializeScanSpecies(FPrimaryAssetId InSpeciesId);

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Scan & Materialization")
    FDMFScanSpeciesPressed OnSpeciesPressed;

private:
    UPROPERTY()
    FPrimaryAssetId SpeciesId;

    UFUNCTION()
    void HandleClicked();
};
