#include "Game/DMFSessionSubsystem.h"
#include "Utility/DMFCredentialUtility.h"
#include "Settings/DMFFrameworkSettings.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/PackageName.h"
#include "Engine/Engine.h"

namespace DMFPrivate
{
    // SHA-1 digest of the required admin passphrase. The plaintext is intentionally not shipped in plugin source.
    static constexpr TCHAR AdminPasswordDigest[] = TEXT("44d5c8be1c38b3c4b3030eab3666607d4db5983a");
}

void UDMFSessionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    if (GEngine)
    {
        NetworkFailureHandle = GEngine->OnNetworkFailure().AddUObject(this, &UDMFSessionSubsystem::HandleNetworkFailure);
        TravelFailureHandle = GEngine->OnTravelFailure().AddUObject(this, &UDMFSessionSubsystem::HandleTravelFailure);
    }
}

void UDMFSessionSubsystem::Deinitialize()
{
    if (GEngine)
    {
        if (NetworkFailureHandle.IsValid())
        {
            GEngine->OnNetworkFailure().Remove(NetworkFailureHandle);
        }
        if (TravelFailureHandle.IsValid())
        {
            GEngine->OnTravelFailure().Remove(TravelFailureHandle);
        }
    }
    Super::Deinitialize();
}

void UDMFSessionSubsystem::HandleNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString)
{
    const FText Message = FText::Format(
        NSLOCTEXT("DMF", "NetworkFailure", "Network connection failed: {0}"),
        FText::FromString(ErrorString.IsEmpty() ? FString(ENetworkFailure::ToString(FailureType)) : ErrorString));
    BroadcastStatus(Message);
}

void UDMFSessionSubsystem::HandleTravelFailure(UWorld* World, ETravelFailure::Type FailureType, const FString& ErrorString)
{
    const FText Message = FText::Format(
        NSLOCTEXT("DMF", "TravelFailure", "Travel failed: {0}"),
        FText::FromString(ErrorString.IsEmpty() ? TEXT("Unable to load or connect to the requested world.") : ErrorString));
    BroadcastStatus(Message);
}

void UDMFSessionSubsystem::BroadcastStatus(const FText& Message)
{
    LastStatus = Message;
    OnStatusChanged.Broadcast(Message);
}

bool UDMFSessionSubsystem::Login(const FString& Username, const FString& Password, FText& OutMessage)
{
    const FString CleanUsername = Username.TrimStartAndEnd();
    if (!UDMFCredentialUtility::IsValidUsername(CleanUsername))
    {
        OutMessage = NSLOCTEXT("DMF", "InvalidUsername", "Username must be 3-24 characters and contain only letters, numbers, '_' or '-'.");
        BroadcastStatus(OutMessage);
        return false;
    }

    if (Password.Len() < 4)
    {
        OutMessage = NSLOCTEXT("DMF", "InvalidPassword", "Please enter a password.");
        BroadcastStatus(OutMessage);
        return false;
    }

    StagedUsername = CleanUsername;
    StagedCredentialDigest = UDMFCredentialUtility::HashCredential(Password);
    bCredentialsStaged = true;
    bAdminUnlocked = false;

    OutMessage = NSLOCTEXT("DMF", "LoginStaged", "Login ready. Choose Join Game, or unlock Admin controls to host.");
    BroadcastStatus(OutMessage);
    return true;
}

void UDMFSessionSubsystem::Logout()
{
    StagedUsername.Reset();
    StagedCredentialDigest.Reset();
    bCredentialsStaged = false;
    bAdminUnlocked = false;
    BroadcastStatus(NSLOCTEXT("DMF", "LoggedOut", "Logged out. Enter your account credentials to continue."));
}

bool UDMFSessionSubsystem::UnlockAdmin(const FString& AdminPassword, FText& OutMessage)
{
    if (!bCredentialsStaged)
    {
        OutMessage = NSLOCTEXT("DMF", "LoginFirst", "Log in before opening Admin controls.");
        BroadcastStatus(OutMessage);
        return false;
    }

    const FString Candidate = UDMFCredentialUtility::HashCredential(AdminPassword);
    bAdminUnlocked = Candidate.Equals(DMFPrivate::AdminPasswordDigest, ESearchCase::CaseSensitive);

    OutMessage = bAdminUnlocked
        ? NSLOCTEXT("DMF", "AdminUnlocked", "Admin hosting controls unlocked.")
        : NSLOCTEXT("DMF", "AdminDenied", "Incorrect admin password.");
    BroadcastStatus(OutMessage);
    return bAdminUnlocked;
}

FString UDMFSessionSubsystem::BuildHiddenServerAddress() const
{
    // Intentionally not exposed through settings, UI, logs or Blueprint. The endpoint is lightly encoded
    // to avoid casual plaintext discovery; this remains obscurity rather than a cryptographic boundary.
    static constexpr uint8 EncodedHost[] =
    {
        30, 51, 61, 51, 55, 53, 52, 23, 23, 21, 105, 30, 116, 57, 47,
        41, 46, 53, 55, 119, 61, 59, 55, 51, 52, 61, 116, 52, 63, 46
    };
    static constexpr uint8 Key = 0x5A;

    FString Host;
    Host.Reserve(UE_ARRAY_COUNT(EncodedHost));
    for (const uint8 Value : EncodedHost)
    {
        Host.AppendChar(static_cast<TCHAR>(Value ^ Key));
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const int32 Port = Settings ? Settings->GamePort : 7777;
    return FString::Printf(TEXT("%s:%d"), *Host, Port);
}

FString UDMFSessionSubsystem::BuildTravelOptions(const bool bHostAdmin) const
{
    FString Options = FString::Printf(TEXT("?DMFUser=%s?DMFCred=%s"), *StagedUsername, *StagedCredentialDigest);
    if (bHostAdmin)
    {
        Options += TEXT("?DMFHostAdmin=1");
    }
    return Options;
}

bool UDMFSessionSubsystem::JoinGame(FText& OutMessage)
{
    if (!bCredentialsStaged)
    {
        OutMessage = NSLOCTEXT("DMF", "JoinLoginFirst", "Log in before joining the MMO host.");
        BroadcastStatus(OutMessage);
        return false;
    }

    UWorld* World = GetWorld();
    APlayerController* PC = World ? World->GetFirstPlayerController() : nullptr;
    if (!PC)
    {
        OutMessage = NSLOCTEXT("DMF", "NoLocalPC", "No local PlayerController is available for network travel.");
        BroadcastStatus(OutMessage);
        return false;
    }

    const FString URL = BuildHiddenServerAddress() + BuildTravelOptions(false);
    PC->ClientTravel(URL, TRAVEL_Absolute);
    OutMessage = NSLOCTEXT("DMF", "Joining", "Connecting to the Digimon MMO host...");
    BroadcastStatus(OutMessage);
    return true;
}

bool UDMFSessionSubsystem::HostAndPlay(FText& OutMessage)
{
    if (!bCredentialsStaged || !bAdminUnlocked)
    {
        OutMessage = NSLOCTEXT("DMF", "HostDenied", "Admin controls must be unlocked before hosting.");
        BroadcastStatus(OutMessage);
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || Settings->OpenWorldMap.IsNull())
    {
        OutMessage = NSLOCTEXT("DMF", "WorldMapMissing", "Open World Map is not configured in Project Settings > Digimon MMO Framework.");
        BroadcastStatus(OutMessage);
        return false;
    }

    const FString ObjectPath = Settings->OpenWorldMap.ToSoftObjectPath().ToString();
    const FString PackageName = FPackageName::ObjectPathToPackageName(ObjectPath);
    if (PackageName.IsEmpty())
    {
        OutMessage = NSLOCTEXT("DMF", "InvalidWorldPath", "Configured Open World Map path is invalid.");
        BroadcastStatus(OutMessage);
        return false;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        OutMessage = NSLOCTEXT("DMF", "NoWorldForHost", "No world is available for hosting.");
        BroadcastStatus(OutMessage);
        return false;
    }

    const FString Options = TEXT("listen") + BuildTravelOptions(true);
    UGameplayStatics::OpenLevel(World, FName(*PackageName), true, Options);
    OutMessage = NSLOCTEXT("DMF", "Hosting", "Starting authoritative listen host...");
    BroadcastStatus(OutMessage);
    return true;
}
