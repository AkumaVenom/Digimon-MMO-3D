#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DMFTypes.h"
#include "DMFDigimonPresentationLibrary.generated.h"

/**
 * Canonical runtime presentation helpers for Digimon-authored data.
 *
 * Important: EDMFDigimonStage keeps its original serialized enum identifiers
 * (BabyI/BabyII) for backward compatibility with existing assets and saves.
 * Presentation must go through this library so cooked/runtime UI always shows
 * the canonical Digimon stage names (Fresh, In-Training, etc.).
 */
UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFDigimonPresentationLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Presentation", meta=(DisplayName="Get Digimon Stage Display Text"))
    static FText GetDigimonStageDisplayText(EDMFDigimonStage Stage);
};
