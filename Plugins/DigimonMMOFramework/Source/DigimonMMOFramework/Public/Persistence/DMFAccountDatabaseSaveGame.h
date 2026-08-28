#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DMFTypes.h"
#include "DMFAccountDatabaseSaveGame.generated.h"

UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFAccountDatabaseSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    UPROPERTY(SaveGame)
    int32 SchemaVersion = 6;

    UPROPERTY(SaveGame)
    TMap<FString, FDMFAccountRecord> Accounts;
};
