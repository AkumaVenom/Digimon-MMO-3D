#include "Game/DMFMMOGameMode.h"
#include "Game/DMFPlayerState.h"
#include "Game/DMFMMOPlayerController.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Persistence/DMFAccountPersistenceSubsystem.h"
#include "Utility/DMFCredentialUtility.h"
#include "Settings/DMFFrameworkSettings.h"
#include "DigimonMMOFramework.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "TimerManager.h"

ADMFMMOGameMode::ADMFMMOGameMode()
{
    PlayerStateClass = ADMFPlayerState::StaticClass();
    PlayerControllerClass = ADMFMMOPlayerController::StaticClass();
    DefaultPawnClass = ADMFPlayerAvatarCharacter::StaticClass();
}

void ADMFMMOGameMode::StartPlay()
{
    Super::StartPlay();

    if (GetNetMode() == NM_Standalone)
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("Standalone MMO gameplay is disabled. Returning to the configured frontend map."));
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        if (Settings && !Settings->FrontendMap.IsNull())
        {
            TWeakObjectPtr<ADMFMMOGameMode> WeakThis(this);
            GetWorldTimerManager().SetTimerForNextTick(FTimerDelegate::CreateLambda([WeakThis]()
            {
                if (ADMFMMOGameMode* GameMode = WeakThis.Get())
                {
                    const UDMFFrameworkSettings* RuntimeSettings = GetDefault<UDMFFrameworkSettings>();
                    if (RuntimeSettings && !RuntimeSettings->FrontendMap.IsNull())
                    {
                        UGameplayStatics::OpenLevelBySoftObjectPtr(GameMode, RuntimeSettings->FrontendMap, true, FString());
                    }
                }
            }));
        }
    }
}

bool ADMFMMOGameMode::ValidateCredentialsFromOptions(const FString& Options, FString& OutUsername, FString& OutCredentialDigest, bool& bOutCreatedNew, FString& OutError) const
{
    OutUsername = UGameplayStatics::ParseOption(Options, TEXT("DMFUser"));
    OutCredentialDigest = UGameplayStatics::ParseOption(Options, TEXT("DMFCred"));
    bOutCreatedNew = false;

    if (!UDMFCredentialUtility::IsValidUsername(OutUsername) || OutCredentialDigest.Len() != 40)
    {
        OutError = TEXT("Authentication data is missing or malformed.");
        return false;
    }

    UGameInstance* GI = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!Persistence)
    {
        OutError = TEXT("Account persistence subsystem is unavailable.");
        return false;
    }

    return Persistence->ValidateOrRegisterAccount(OutUsername, OutCredentialDigest, bOutCreatedNew, OutError);
}

void ADMFMMOGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
    if (!ErrorMessage.IsEmpty())
    {
        return;
    }

    FString Username;
    FString Digest;
    bool bCreatedNew = false;
    FString AuthError;
    if (!ValidateCredentialsFromOptions(Options, Username, Digest, bCreatedNew, AuthError))
    {
        ErrorMessage = AuthError;
    }
}

FString ADMFMMOGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{
    const FString SuperError = Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
    if (!SuperError.IsEmpty())
    {
        return SuperError;
    }

    FString Username;
    FString Digest;
    bool bCreatedNew = false;
    FString AuthError;
    if (!ValidateCredentialsFromOptions(Options, Username, Digest, bCreatedNew, AuthError))
    {
        return AuthError;
    }

    ADMFPlayerState* PS = NewPlayerController ? NewPlayerController->GetPlayerState<ADMFPlayerState>() : nullptr;
    UGameInstance* GI = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!PS || !Persistence)
    {
        return TEXT("Could not initialize authenticated player state.");
    }

    FDMFAccountRecord Record;
    if (!Persistence->GetAccount(Username, Record))
    {
        return TEXT("Authenticated account record could not be loaded.");
    }

    PS->SetAuthenticatedAccount(Record.Username, Digest);
    if (PS->AvatarComponent)
    {
        PS->AvatarComponent->InitializeFromAccountRecord(Record);
    }

    if (PS->DigimonComponent)
    {
        PS->DigimonComponent->InitializeFromAccountRecord(Record);
    }

    const bool bFreshOnboardingAccount = !Record.bStarterSelected
        && !Record.ActivePartnerInstanceId.IsValid()
        && Record.DigimonInventory.IsEmpty()
        && Record.DigimonBank.IsEmpty();

    BP_OnPlayerAccountLoaded(NewPlayerController, Record.Username, bFreshOnboardingAccount);
    return FString();
}

UClass* ADMFMMOGameMode::ResolveFrameworkPlayerAvatarClass() const
{
    UClass* ConfiguredPawnClass = DefaultPawnClass.Get();
    if (ConfiguredPawnClass && ConfiguredPawnClass->IsChildOf(ADMFPlayerAvatarCharacter::StaticClass()))
    {
        return ConfiguredPawnClass;
    }

    if (ConfiguredPawnClass)
    {
        UE_LOG(LogDigimonMMOFramework, Error,
            TEXT("MMO GameMode DefaultPawnClass '%s' is not derived from DMFPlayerAvatarCharacter. "
                 "The framework will use native DMFPlayerAvatarCharacter so remote clients cannot fall back to DefaultPawn."),
            *GetNameSafe(ConfiguredPawnClass));
    }

    return ADMFPlayerAvatarCharacter::StaticClass();
}

UClass* ADMFMMOGameMode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
    return ResolveFrameworkPlayerAvatarClass();
}

bool ADMFMMOGameMode::HasFrameworkPlayerAvatar(APlayerController* PlayerController) const
{
    return PlayerController && IsValid(Cast<ADMFPlayerAvatarCharacter>(PlayerController->GetPawn()));
}

bool ADMFMMOGameMode::EnsureFrameworkPlayerAvatar(APlayerController* PlayerController)
{
    if (!HasAuthority() || !IsValid(PlayerController))
    {
        return false;
    }

    ADMFPlayerState* DMFPlayerState = PlayerController->GetPlayerState<ADMFPlayerState>();
    ADMFPlayerAvatarCharacter* AvatarPawn = Cast<ADMFPlayerAvatarCharacter>(PlayerController->GetPawn());
    bool bRecoveredPawn = false;

    if (!IsValid(AvatarPawn))
    {
        APawn* UnexpectedPawn = PlayerController->GetPawn();
        FTransform RecoveryTransform = FTransform::Identity;
        bool bHasRecoveryTransform = false;

        if (AActor* PlayerStart = FindPlayerStart(PlayerController))
        {
            RecoveryTransform = PlayerStart->GetActorTransform();
            bHasRecoveryTransform = true;
        }
        else if (IsValid(UnexpectedPawn))
        {
            RecoveryTransform = UnexpectedPawn->GetActorTransform();
            bHasRecoveryTransform = true;
        }

        if (IsValid(UnexpectedPawn))
        {
            UE_LOG(LogDigimonMMOFramework, Warning,
                TEXT("Recovering player '%s' from unexpected pawn '%s' into the framework MMO avatar."),
                *GetNameSafe(PlayerController), *GetNameSafe(UnexpectedPawn));
            PlayerController->UnPossess();
            UnexpectedPawn->Destroy();
        }
        else
        {
            UE_LOG(LogDigimonMMOFramework, Warning,
                TEXT("Recovering player '%s' because it has no possessed gameplay pawn."),
                *GetNameSafe(PlayerController));
        }

        if (bHasRecoveryTransform)
        {
            RestartPlayerAtTransform(PlayerController, RecoveryTransform);
        }
        else
        {
            RestartPlayer(PlayerController);
        }

        AvatarPawn = Cast<ADMFPlayerAvatarCharacter>(PlayerController->GetPawn());

        // Defensive fallback: a project Blueprint may have overridden the pawn-class event incorrectly.
        // Spawn the resolved DMF class explicitly instead of leaving a remote client in DefaultPawn/SpectatorPawn.
        if (!IsValid(AvatarPawn))
        {
            APawn* FailedRestartPawn = PlayerController->GetPawn();
            if (IsValid(FailedRestartPawn))
            {
                PlayerController->UnPossess();
                FailedRestartPawn->Destroy();
            }

            UWorld* World = GetWorld();
            UClass* AvatarClass = ResolveFrameworkPlayerAvatarClass();
            if (World && AvatarClass)
            {
                FActorSpawnParameters SpawnParameters;
                SpawnParameters.Owner = PlayerController;
                SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

                const FTransform SpawnTransform = bHasRecoveryTransform ? RecoveryTransform : FTransform::Identity;
                AvatarPawn = World->SpawnActor<ADMFPlayerAvatarCharacter>(AvatarClass, SpawnTransform, SpawnParameters);
                if (IsValid(AvatarPawn))
                {
                    PlayerController->Possess(AvatarPawn);
                }
            }
        }

        bRecoveredPawn = IsValid(AvatarPawn);
    }

    if (!IsValid(AvatarPawn))
    {
        UE_LOG(LogDigimonMMOFramework, Error,
            TEXT("Failed to establish a DMF player avatar for '%s'. Check the OpenWorld GameMode and PlayerStart setup."),
            *GetNameSafe(PlayerController));
        return false;
    }

    // ClientRestart is intentionally reasserted for remote players even when the server already had the
    // correct pawn. This repairs late-join cases where the owning client is still locally controlling
    // the frontend/default pawn while leaving the already-working listen-host path untouched.
    if (!PlayerController->IsLocalController())
    {
        PlayerController->ClientRestart(AvatarPawn);
    }
    PlayerController->ForceNetUpdate();
    AvatarPawn->ForceNetUpdate();

    if (DMFPlayerState)
    {
        DMFPlayerState->ForceNetUpdate();
        if (DMFPlayerState->AvatarComponent)
        {
            DMFPlayerState->AvatarComponent->ApplySelectedSkinToCurrentPawn();
        }

        if (DMFPlayerState->DigimonComponent && !DMFPlayerState->DigimonComponent->IsStarterSelectionRequired())
        {
            DMFPlayerState->DigimonComponent->SpawnOrRefreshActivePartner(AvatarPawn);
        }
    }

    if (bRecoveredPawn)
    {
        BP_OnFrameworkPlayerAvatarRecovered(PlayerController, AvatarPawn);
    }

    return true;
}

void ADMFMMOGameMode::ScheduleFrameworkPlayerAvatarValidation(APlayerController* PlayerController)
{
    if (!IsValid(PlayerController))
    {
        return;
    }

    TWeakObjectPtr<ADMFMMOGameMode> WeakGameMode(this);
    TWeakObjectPtr<APlayerController> WeakPlayerController(PlayerController);
    GetWorldTimerManager().SetTimerForNextTick(FTimerDelegate::CreateLambda([WeakGameMode, WeakPlayerController]()
    {
        if (ADMFMMOGameMode* GameMode = WeakGameMode.Get())
        {
            if (APlayerController* PendingPlayer = WeakPlayerController.Get())
            {
                GameMode->EnsureFrameworkPlayerAvatar(PendingPlayer);
            }
        }
    }));
}

void ADMFMMOGameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
    // Preserve Unreal's normal PlayerStart/restart path, then validate the result. Late-joining remote
    // clients are explicitly repaired if Unreal left them unpossessed or in a DefaultPawn/SpectatorPawn.
    Super::HandleStartingNewPlayer_Implementation(NewPlayer);

    EnsureFrameworkPlayerAvatar(NewPlayer);
    ScheduleFrameworkPlayerAvatarValidation(NewPlayer);
}

void ADMFMMOGameMode::SavePlayerState(ADMFPlayerState* PlayerState) const
{
    if (!PlayerState || !PlayerState->DigimonComponent || PlayerState->GetAuthenticatedUsername().IsEmpty())
    {
        return;
    }

    UGameInstance* GI = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!Persistence)
    {
        return;
    }

    FDMFAccountRecord Record;
    if (!Persistence->GetAccount(PlayerState->GetAuthenticatedUsername(), Record))
    {
        return;
    }

    PlayerState->DigimonComponent->ApplyToAccountRecord(Record);
    if (PlayerState->AvatarComponent)
    {
        PlayerState->AvatarComponent->ApplyToAccountRecord(Record);
    }
    FString Error;
    if (!Persistence->SaveAccount(Record, Error))
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("Logout save failed for '%s': %s"), *PlayerState->GetAuthenticatedUsername(), *Error);
    }
}

void ADMFMMOGameMode::Logout(AController* Exiting)
{
    if (APlayerController* PC = Cast<APlayerController>(Exiting))
    {
        SavePlayerState(PC->GetPlayerState<ADMFPlayerState>());
    }

    Super::Logout(Exiting);
}
