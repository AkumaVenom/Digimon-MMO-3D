#include "Game/DMFSessionSubsystem.h"
#include "Utility/DMFCredentialUtility.h"
#include "Settings/DMFFrameworkSettings.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/PackageName.h"
#include "Engine/Engine.h"

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

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings)
    {
        OutMessage = NSLOCTEXT("DMF", "AdminSettingsUnavailable", "Digimon MMO Framework Admin hosting settings are unavailable.");
        BroadcastStatus(OutMessage);
        return false;
    }

    const FString CandidateDigest = UDMFCredentialUtility::HashCredential(AdminPassword);
    const FString& ExpectedDigest = Settings->AdminHostingPasswordDigest;

    // A SHA-1 digest is 40 hexadecimal characters. Refuse a malformed deployment setting rather than silently weakening the gate.
    if (ExpectedDigest.Len() != 40)
    {
        bAdminUnlocked = false;
        OutMessage = NSLOCTEXT("DMF", "AdminPasswordConfigInvalid", "Admin Hosting Password is not configured correctly. Set it in Project Settings > Digimon MMO Framework > Networking > Admin Hosting.");
        BroadcastStatus(OutMessage);
        return false;
    }

    bAdminUnlocked = CandidateDigest.Equals(ExpectedDigest, ESearchCase::CaseSensitive);

    OutMessage = bAdminUnlocked
        ? NSLOCTEXT("DMF", "AdminUnlocked", "Admin hosting controls unlocked.")
        : NSLOCTEXT("DMF", "AdminDenied", "Incorrect admin password.");
    BroadcastStatus(OutMessage);
    return bAdminUnlocked;
}

bool UDMFSessionSubsystem::BuildConfiguredServerAddress(FString& OutAddress, FText& OutError) const
{
    OutAddress.Reset();
    OutError = FText::GetEmpty();

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings)
    {
        OutError = NSLOCTEXT("DMF", "ServerEndpointSettingsUnavailable", "Digimon MMO Framework networking settings are unavailable.");
        return false;
    }

    const FString Host = Settings->ServerPublicAddress.TrimStartAndEnd();
    if (Host.IsEmpty())
    {
        OutError = NSLOCTEXT("DMF", "ServerEndpointMissing", "Server Public Address / Hostname is not configured in Project Settings > Digimon MMO Framework > Networking > Server Endpoint.");
        return false;
    }

    // Keep the endpoint deliberately narrow: a host/IP only, never a URL, path, travel option or user-info string.
    // This prevents project configuration from accidentally injecting Unreal travel options into the client URL.
    if (Host.Len() > 253)
    {
        OutError = NSLOCTEXT("DMF", "ServerEndpointTooLong", "Server Public Address / Hostname is too long.");
        return false;
    }

    for (const TCHAR Character : Host)
    {
        const bool bAllowed = FChar::IsAlnum(Character)
            || Character == TEXT('.')
            || Character == TEXT('-')
            || Character == TEXT('_');
        if (!bAllowed)
        {
            OutError = NSLOCTEXT("DMF", "ServerEndpointInvalidCharacters", "Server Public Address / Hostname must contain only letters, numbers, dots, hyphens or underscores. Do not enter http://, a path, a port or Unreal travel options.");
            return false;
        }
    }

    const int32 Port = FMath::Clamp(Settings->GamePort, 1, 65535);
    OutAddress = FString::Printf(TEXT("%s:%d"), *Host, Port);
    return true;
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

    FString ServerAddress;
    FText EndpointError;
    if (!BuildConfiguredServerAddress(ServerAddress, EndpointError))
    {
        OutMessage = EndpointError;
        BroadcastStatus(OutMessage);
        return false;
    }

    const FString URL = ServerAddress + BuildTravelOptions(false);
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

    FString ConfiguredServerAddress;
    FText EndpointError;
    if (!BuildConfiguredServerAddress(ConfiguredServerAddress, EndpointError))
    {
        OutMessage = EndpointError;
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

    const int32 MaximumPlayers = FMath::Clamp(Settings->GlobalMaxPlayers, 1, 10000);

    // Seed Unreal's native GameSession capacity as the gameplay world is created. DMFMMOGameMode also
    // reasserts the Project Settings value before every PreLogin, so a client URL can never override it.
    const FString Options = FString::Printf(TEXT("listen?MaxPlayers=%d"), MaximumPlayers) + BuildTravelOptions(true);
    UGameplayStatics::OpenLevel(World, FName(*PackageName), true, Options);
    OutMessage = FText::Format(
        NSLOCTEXT("DMF", "Hosting", "Starting authoritative listen host for up to {0} players. Configured player endpoint: {1}"),
        FText::AsNumber(MaximumPlayers),
        FText::FromString(ConfiguredServerAddress));
    BroadcastStatus(OutMessage);
    return true;
}
