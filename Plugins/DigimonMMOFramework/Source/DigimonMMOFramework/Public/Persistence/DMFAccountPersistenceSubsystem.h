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

    /** C++ server service helpers used by the persistent Social/Guild authority. */
    bool GetAllAccounts(TArray<FDMFAccountRecord>& OutRecords);
    bool GetGuild(const FGuid& GuildId, FDMFGuildRecord& OutGuild);
    bool GetAllGuilds(TArray<FDMFGuildRecord>& OutGuilds);

    /**
     * Commits a social mutation as one SaveGame write. All supplied account/guild records are applied
     * together and restored in memory if the disk write fails, preventing half-applied friendships/guild joins.
     */
    bool SaveSocialTransaction(
        const TArray<FDMFAccountRecord>& AccountRecords,
        const TArray<FDMFGuildRecord>& GuildsToUpsert,
        const TArray<FGuid>& GuildIdsToRemove,
        FString& OutError);

private:
    UPROPERTY(Transient)
    TObjectPtr<UDMFAccountDatabaseSaveGame> Database;

    bool EnsureLoaded(FString& OutError);
    FString NormalizeAccountKey(const FString& Username) const;
};
