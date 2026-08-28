#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "DMFNewPlayerStart.generated.h"

/**
 * Dedicated first-login gameplay spawn point for accounts that do not yet have a persisted world location.
 *
 * Place one (or more) in the configured Open World map. The authoritative MMO GameMode selects the enabled
 * point with the highest Spawn Priority. Returning players with a valid persisted location do not use this actor.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFNewPlayerStart : public APlayerStart
{
    GENERATED_BODY()

public:
    ADMFNewPlayerStart(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    /** Disabled points are ignored by the framework without needing to remove them from the level. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|New Player Spawn")
    bool bEnabled = true;

    /** Highest enabled priority wins. Multiple equal-priority points are resolved deterministically by actor name. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|New Player Spawn")
    int32 SpawnPriority = 0;
};
