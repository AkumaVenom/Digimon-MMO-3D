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
    int32 SchemaVersion = 8;

    UPROPERTY(SaveGame)
    TMap<FString, FDMFAccountRecord> Accounts;

    /** Persistent global guild registry introduced in schema v8. */
    UPROPERTY(SaveGame)
    TMap<FGuid, FDMFGuildRecord> Guilds;
};
