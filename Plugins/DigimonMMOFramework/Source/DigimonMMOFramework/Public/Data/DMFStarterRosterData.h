#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DMFStarterRosterData.generated.h"

class UDMFDigimonSpeciesData;

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFStarterRosterEntry
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Starter")
    TSoftObjectPtr<UDMFDigimonSpeciesData> Species;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Starter")
    bool bEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Starter")
    int32 DisplayOrder = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Starter", meta=(MultiLine=true))
    FText SelectionBlurb;
};

UCLASS(BlueprintType)
class DIGIMONMMOFRAMEWORK_API UDMFStarterRosterData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Starter")
    FText Title = NSLOCTEXT("DMF", "StarterRosterTitle", "Choose Your Partner Digimon");

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Starter")
    TArray<FDMFStarterRosterEntry> Starters;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        return FPrimaryAssetId(TEXT("DMFStarterRoster"), GetFName());
    }
};
