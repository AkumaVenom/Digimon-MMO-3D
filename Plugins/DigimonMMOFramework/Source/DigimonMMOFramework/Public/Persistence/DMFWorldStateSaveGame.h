#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DMFTypes.h"
#include "DMFWorldStateSaveGame.generated.h"

/**
 * Server-owned persistent world state kept separate from per-account saves.
 * Day/night clock keys are map + stable sky persistence id so different worlds never overwrite one another.
 */
UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFWorldStateSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    UPROPERTY(SaveGame)
    int32 SchemaVersion = 1;

    UPROPERTY(SaveGame)
    TMap<FString, FDMFDayNightPersistentState> DayNightStates;
};
