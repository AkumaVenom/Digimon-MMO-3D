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
