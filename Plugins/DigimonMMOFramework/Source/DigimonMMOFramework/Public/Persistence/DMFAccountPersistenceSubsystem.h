#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DMFTypes.h"
#include "DMFAccountPersistenceSubsystem.generated.h"

class UDMFAccountDatabaseSaveGame;

UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFAccountPersistenceSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Accounts")
    bool ValidateOrRegisterAccount(const FString& Username, const FString& CredentialDigest, bool& bOutCreatedNewAccount, FString& OutError);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Accounts")
    bool GetAccount(const FString& Username, FDMFAccountRecord& OutRecord);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Accounts")
    bool SaveAccount(const FDMFAccountRecord& Record, FString& OutError);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Accounts")
    bool Flush(FString& OutError);

private:
    UPROPERTY(Transient)
    TObjectPtr<UDMFAccountDatabaseSaveGame> Database;

    bool EnsureLoaded(FString& OutError);
    FString NormalizeAccountKey(const FString& Username) const;
};
