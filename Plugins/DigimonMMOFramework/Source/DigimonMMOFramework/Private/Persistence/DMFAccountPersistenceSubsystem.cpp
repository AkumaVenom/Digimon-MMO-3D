#include "Persistence/DMFAccountPersistenceSubsystem.h"
#include "Persistence/DMFAccountDatabaseSaveGame.h"
#include "Settings/DMFFrameworkSettings.h"
#include "Kismet/GameplayStatics.h"

FString UDMFAccountPersistenceSubsystem::NormalizeAccountKey(const FString& Username) const
{
    return Username.TrimStartAndEnd().ToLower();
}

bool UDMFAccountPersistenceSubsystem::EnsureLoaded(FString& OutError)
{
    if (Database)
    {
        return true;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const FString Slot = Settings ? Settings->AccountSaveSlot : TEXT("DMF_ServerAccounts");

    if (UGameplayStatics::DoesSaveGameExist(Slot, 0))
    {
        Database = Cast<UDMFAccountDatabaseSaveGame>(UGameplayStatics::LoadGameFromSlot(Slot, 0));
        if (!Database)
        {
            OutError = TEXT("Account database exists but could not be loaded or has an incompatible class.");
            return false;
        }

        if (Database->SchemaVersion < 2)
        {
            // v2 adds persistent player-avatar skin state. Existing accounts simply have no skin yet
            // and will follow the configured first-time skin-selection policy.
            Database->SchemaVersion = 2;
        }

        if (Database->SchemaVersion < 3)
        {
            // v3 formalizes persistent virtual-pet Care state. The serialized struct already carries
            // backward-compatible defaults; the authoritative Digimon component performs the one-time
            // legacy Hunger/Fullness semantic migration when each account is initialized.
            Database->SchemaVersion = 3;
        }

        if (Database->SchemaVersion < 4)
        {
            // v4 formalizes DigimonInventory as the active Party and DigimonBank as world-accessible Box storage.
            // Slot/capacity migration is performed authoritatively by UDMFPlayerDigimonComponent on account load
            // so the configured Party size can be honored without discarding older collected Digimon.
            Database->SchemaVersion = 4;
        }

        if (Database->SchemaVersion < 5)
        {
            // v5 adds persistent Digivolution provenance/history to each owned Digimon. Existing records are
            // normalized on authoritative account load so their current species becomes the origin/history seed.
            Database->SchemaVersion = 5;
        }

        if (Database->SchemaVersion < 6)
        {
            // v6 adds server-authored persistent player world location. Older accounts intentionally begin with
            // bHasSavedLocation=false and will use DMFNewPlayerStart once before their first checkpoint is saved.
            Database->SchemaVersion = 6;
        }

        if (Database->SchemaVersion < 7)
        {
            // v7 adds per-Digimon lifetime EXP and exact Attribute Point spend counters for vendor valuation.
            // Existing Digimon are conservatively reconstructed from their current level/EXP and unspent-point state
            // during authoritative account initialization; no owned Digimon or legacy stat is discarded.
            Database->SchemaVersion = 7;
        }

        if (Database->SchemaVersion < 8)
        {
            // v8 adds persistent friends, ignore/tracker preferences, guild membership/invites, and the global guild
            // registry. Existing accounts deserialize with empty social collections and no guild, requiring no rewrite.
            Database->SchemaVersion = 8;
        }

        if (Database->SchemaVersion < 9)
        {
            // v9 adds the private persistent player item bag. Older accounts deserialize with an empty bag; stack
            // identities/quantities are normalized by the authoritative player component when the account is loaded.
            Database->SchemaVersion = 9;
        }
    }
    else
    {
        Database = Cast<UDMFAccountDatabaseSaveGame>(UGameplayStatics::CreateSaveGameObject(UDMFAccountDatabaseSaveGame::StaticClass()));
        if (!Database)
        {
            OutError = TEXT("Could not allocate the Digimon MMO account database.");
            return false;
        }
    }

    return true;
}

bool UDMFAccountPersistenceSubsystem::ValidateOrRegisterAccount(const FString& Username, const FString& CredentialDigest, bool& bOutCreatedNewAccount, FString& OutError)
{
    bOutCreatedNewAccount = false;
    OutError.Reset();

    if (!EnsureLoaded(OutError))
    {
        return false;
    }

    const FString Key = NormalizeAccountKey(Username);
    if (Key.IsEmpty() || CredentialDigest.IsEmpty())
    {
        OutError = TEXT("Username or credential digest is empty.");
        return false;
    }

    if (FDMFAccountRecord* Existing = Database->Accounts.Find(Key))
    {
        if (!Existing->CredentialDigest.Equals(CredentialDigest, ESearchCase::CaseSensitive))
        {
            OutError = TEXT("Invalid username or password.");
            return false;
        }
        return true;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bAutoRegisterUnknownAccounts)
    {
        OutError = TEXT("Account does not exist.");
        return false;
    }

    FDMFAccountRecord NewRecord;
    NewRecord.Username = Username.TrimStartAndEnd();
    NewRecord.CredentialDigest = CredentialDigest;
    NewRecord.DigimonEconomyProvenanceVersion = 1;
    Database->Accounts.Add(Key, NewRecord);
    bOutCreatedNewAccount = true;

    return Flush(OutError);
}

bool UDMFAccountPersistenceSubsystem::GetAccount(const FString& Username, FDMFAccountRecord& OutRecord)
{
    FString Error;
    if (!EnsureLoaded(Error))
    {
        return false;
    }

    if (const FDMFAccountRecord* Record = Database->Accounts.Find(NormalizeAccountKey(Username)))
    {
        OutRecord = *Record;
        return true;
    }

    return false;
}

bool UDMFAccountPersistenceSubsystem::SaveAccount(const FDMFAccountRecord& Record, FString& OutError)
{
    OutError.Reset();
    if (!EnsureLoaded(OutError))
    {
        return false;
    }

    if (Record.Username.IsEmpty())
    {
        OutError = TEXT("Refusing to save an account with an empty username.");
        return false;
    }

    Database->Accounts.Add(NormalizeAccountKey(Record.Username), Record);
    return Flush(OutError);
}

bool UDMFAccountPersistenceSubsystem::GetAllAccounts(TArray<FDMFAccountRecord>& OutRecords)
{
    OutRecords.Reset();
    FString Error;
    if (!EnsureLoaded(Error) || !Database)
    {
        return false;
    }

    Database->Accounts.GenerateValueArray(OutRecords);
    return true;
}

bool UDMFAccountPersistenceSubsystem::GetGuild(const FGuid& GuildId, FDMFGuildRecord& OutGuild)
{
    FString Error;
    if (!GuildId.IsValid() || !EnsureLoaded(Error) || !Database)
    {
        return false;
    }

    if (const FDMFGuildRecord* Guild = Database->Guilds.Find(GuildId))
    {
        OutGuild = *Guild;
        return true;
    }
    return false;
}

bool UDMFAccountPersistenceSubsystem::GetAllGuilds(TArray<FDMFGuildRecord>& OutGuilds)
{
    OutGuilds.Reset();
    FString Error;
    if (!EnsureLoaded(Error) || !Database)
    {
        return false;
    }

    Database->Guilds.GenerateValueArray(OutGuilds);
    return true;
}

bool UDMFAccountPersistenceSubsystem::SaveSocialTransaction(
    const TArray<FDMFAccountRecord>& AccountRecords,
    const TArray<FDMFGuildRecord>& GuildsToUpsert,
    const TArray<FGuid>& GuildIdsToRemove,
    FString& OutError)
{
    OutError.Reset();
    if (!EnsureLoaded(OutError) || !Database)
    {
        return false;
    }

    for (const FDMFAccountRecord& Record : AccountRecords)
    {
        if (Record.Username.TrimStartAndEnd().IsEmpty())
        {
            OutError = TEXT("Refusing social transaction containing an account with an empty username.");
            return false;
        }
    }
    for (const FDMFGuildRecord& Guild : GuildsToUpsert)
    {
        if (!Guild.GuildId.IsValid() || Guild.Name.TrimStartAndEnd().IsEmpty() || Guild.OwnerUsername.TrimStartAndEnd().IsEmpty())
        {
            OutError = TEXT("Refusing social transaction containing an invalid guild record.");
            return false;
        }
    }

    // Transactions are comparatively rare and the SaveGame backend already serializes the complete database.
    // Copying the two maps gives us a simple, deterministic rollback if SaveGameToSlot fails.
    const TMap<FString, FDMFAccountRecord> AccountsBefore = Database->Accounts;
    const TMap<FGuid, FDMFGuildRecord> GuildsBefore = Database->Guilds;

    for (const FDMFAccountRecord& Record : AccountRecords)
    {
        Database->Accounts.Add(NormalizeAccountKey(Record.Username), Record);
    }
    for (const FDMFGuildRecord& Guild : GuildsToUpsert)
    {
        Database->Guilds.Add(Guild.GuildId, Guild);
    }
    for (const FGuid& GuildId : GuildIdsToRemove)
    {
        if (GuildId.IsValid())
        {
            Database->Guilds.Remove(GuildId);
        }
    }

    if (!Flush(OutError))
    {
        Database->Accounts = AccountsBefore;
        Database->Guilds = GuildsBefore;
        return false;
    }
    return true;
}

bool UDMFAccountPersistenceSubsystem::Flush(FString& OutError)
{
    OutError.Reset();
    if (!Database && !EnsureLoaded(OutError))
    {
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const FString Slot = Settings ? Settings->AccountSaveSlot : TEXT("DMF_ServerAccounts");
    if (!UGameplayStatics::SaveGameToSlot(Database, Slot, 0))
    {
        OutError = TEXT("SaveGameToSlot failed for the Digimon MMO account database.");
        return false;
    }

    return true;
}
