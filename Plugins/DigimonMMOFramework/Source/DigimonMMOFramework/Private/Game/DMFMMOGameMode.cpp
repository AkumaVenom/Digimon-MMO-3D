#include "Game/DMFMMOGameMode.h"
#include "Game/DMFPlayerState.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFNewPlayerStart.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFAbilityProjectileActor.h"
#include "Persistence/DMFAccountPersistenceSubsystem.h"
#include "Utility/DMFCredentialUtility.h"
#include "Settings/DMFFrameworkSettings.h"
#include "DigimonMMOFramework.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"
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

bool ADMFMMOGameMode::BroadcastWorldChatMessage(ADMFMMOPlayerController* SenderController, const FString& SanitizedMessage)
{
    if (!HasAuthority() || !IsValid(SenderController) || SanitizedMessage.IsEmpty())
    {
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableWorldChat)
    {
        return false;
    }

    ADMFPlayerState* SenderPlayerState = SenderController->GetPlayerState<ADMFPlayerState>();
    if (!SenderPlayerState)
    {
        return false;
    }

    FString PublicSenderName = SenderPlayerState->GetPlayerName();
    PublicSenderName.TrimStartAndEndInline();
    if (PublicSenderName.IsEmpty())
    {
        PublicSenderName = TEXT("Player");
    }

    FDMFWorldChatMessage ChatMessage;
    ChatMessage.SenderName = PublicSenderName;
    ChatMessage.Message = SanitizedMessage;
    ChatMessage.SentUtcTicks = FDateTime::UtcNow().GetTicks();
    ChatMessage.MessageType = EDMFWorldChatMessageType::Player;

    const int32 HistoryLimit = Settings ? FMath::Clamp(Settings->WorldChatServerHistoryLimit, 0, 250) : 50;
    if (HistoryLimit > 0)
    {
        RecentWorldChatMessages.Add(ChatMessage);
        while (RecentWorldChatMessages.Num() > HistoryLimit)
        {
            RecentWorldChatMessages.RemoveAt(0);
        }
    }
    else
    {
        RecentWorldChatMessages.Reset();
    }

    if (UWorld* World = GetWorld())
    {
        for (FConstPlayerControllerIterator Iterator = World->GetPlayerControllerIterator(); Iterator; ++Iterator)
        {
            if (ADMFMMOPlayerController* Recipient = Cast<ADMFMMOPlayerController>(Iterator->Get()))
            {
                Recipient->ClientReceiveWorldChatMessage(ChatMessage);
            }
        }
    }

    BP_OnWorldChatMessageAccepted(ChatMessage, SenderController);
    return true;
}

void ADMFMMOGameMode::SendRecentWorldChatHistory(ADMFMMOPlayerController* RecipientController) const
{
    if (!HasAuthority() || !IsValid(RecipientController))
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableWorldChat)
    {
        RecipientController->ClientReceiveWorldChatHistory(TArray<FDMFWorldChatMessage>());
        return;
    }

    const int32 HistoryLimit = Settings ? FMath::Clamp(Settings->WorldChatServerHistoryLimit, 0, 250) : 50;
    if (HistoryLimit <= 0 || RecentWorldChatMessages.IsEmpty())
    {
        RecipientController->ClientReceiveWorldChatHistory(TArray<FDMFWorldChatMessage>());
        return;
    }

    const int32 StartIndex = FMath::Max(0, RecentWorldChatMessages.Num() - HistoryLimit);
    TArray<FDMFWorldChatMessage> BoundedHistory;
    BoundedHistory.Reserve(RecentWorldChatMessages.Num() - StartIndex);
    for (int32 Index = StartIndex; Index < RecentWorldChatMessages.Num(); ++Index)
    {
        BoundedHistory.Add(RecentWorldChatMessages[Index]);
    }
    RecipientController->ClientReceiveWorldChatHistory(BoundedHistory);
}

ADMFNewPlayerStart* ADMFMMOGameMode::ChooseNewPlayerSpawnPoint_Implementation(APlayerController* PlayerController) const
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return nullptr;
    }

    ADMFNewPlayerStart* BestStart = nullptr;
    for (TActorIterator<ADMFNewPlayerStart> It(World); It; ++It)
    {
        ADMFNewPlayerStart* Candidate = *It;
        if (!IsValid(Candidate) || !Candidate->bEnabled)
        {
            continue;
        }

        const bool bHigherPriority = !BestStart || Candidate->SpawnPriority > BestStart->SpawnPriority;
        const bool bDeterministicTieBreak = BestStart
            && Candidate->SpawnPriority == BestStart->SpawnPriority
            && Candidate->GetName() < BestStart->GetName();
        if (bHigherPriority || bDeterministicTieBreak)
        {
            BestStart = Candidate;
        }
    }

    return BestStart;
}

bool ADMFMMOGameMode::SaveAuthenticatedPlayerWorldLocationNow(APlayerController* PlayerController) const
{
    if (!HasAuthority() || !IsValid(PlayerController))
    {
        return false;
    }

    ADMFPlayerState* PlayerState = PlayerController->GetPlayerState<ADMFPlayerState>();
    if (!PlayerState || !PlayerState->AvatarComponent || PlayerState->GetAuthenticatedUsername().IsEmpty())
    {
        return false;
    }

    UGameInstance* GameInstance = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GameInstance ? GameInstance->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!Persistence)
    {
        return false;
    }

    FDMFAccountRecord Record;
    if (!Persistence->GetAccount(PlayerState->GetAuthenticatedUsername(), Record))
    {
        return false;
    }

    if (!PlayerState->AvatarComponent->ApplyCurrentWorldLocationToAccountRecord(Record))
    {
        return false;
    }

    FString Error;
    if (!Persistence->SaveAccount(Record, Error))
    {
        UE_LOG(LogDigimonMMOFramework, Error,
            TEXT("Player world-location checkpoint failed for '%s': %s"),
            *PlayerState->GetAuthenticatedUsername(), *Error);
        return false;
    }

    return true;
}

bool ADMFMMOGameMode::ReturnAuthenticatedPlayerHome(APlayerController* PlayerController, FText& OutMessage) const
{
    OutMessage = FText::GetEmpty();
    if (!HasAuthority() || !IsValid(PlayerController))
    {
        OutMessage = NSLOCTEXT("DMF", "ReturnHomeAuthorityRequired", "Return Home must be validated by the server.");
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnablePartyQuickAccessHomeButton)
    {
        OutMessage = NSLOCTEXT("DMF", "ReturnHomeDisabled", "Return Home is disabled for this world.");
        return false;
    }

    ADMFPlayerState* PlayerState = PlayerController->GetPlayerState<ADMFPlayerState>();
    ADMFPlayerAvatarCharacter* AvatarPawn = Cast<ADMFPlayerAvatarCharacter>(PlayerController->GetPawn());
    if (!PlayerState || PlayerState->GetAuthenticatedUsername().IsEmpty() || !IsValid(AvatarPawn))
    {
        OutMessage = NSLOCTEXT("DMF", "ReturnHomePlayerUnavailable", "Your authenticated player avatar is not ready yet.");
        return false;
    }

    UDMFPlayerDigimonComponent* DigimonComponent = PlayerState->DigimonComponent;
    if (DigimonComponent && (DigimonComponent->IsCareSequenceActive() || DigimonComponent->IsDigivolutionSequenceActive()))
    {
        OutMessage = NSLOCTEXT("DMF", "ReturnHomePresentationBusy", "Finish the current Digimon care or Digivolution sequence before returning Home.");
        return false;
    }

    ADMFNewPlayerStart* HomeStart = ChooseNewPlayerSpawnPoint(PlayerController);
    if (!IsValid(HomeStart))
    {
        OutMessage = NSLOCTEXT("DMF", "ReturnHomeSpawnMissing", "No enabled DMFNewPlayerStart is configured for this world.");
        return false;
    }

    if (UCharacterMovementComponent* Movement = AvatarPawn->GetCharacterMovement())
    {
        Movement->StopMovementImmediately();
    }
    AvatarPawn->ResetNativeInputState();

    const FTransform HomeTransform(HomeStart->GetActorRotation(), HomeStart->GetActorLocation(), FVector::OneVector);
    if (!AvatarPawn->TeleportTo(HomeTransform.GetLocation(), HomeTransform.Rotator(), false, false))
    {
        OutMessage = NSLOCTEXT("DMF", "ReturnHomeObstructed", "Home is currently obstructed. Move the DMFNewPlayerStart to a clear location.");
        return false;
    }

    PlayerController->SetControlRotation(HomeTransform.Rotator());
    if (UCharacterMovementComponent* Movement = AvatarPawn->GetCharacterMovement())
    {
        Movement->StopMovementImmediately();
    }

    // Teleports can bypass normal overlap transition timing. Reconcile from world geometry immediately so Home
    // cannot leave a stale swimming/fog state if the source was underwater (and also supports a deliberately
    // water-placed Home spawn without waiting for a later overlap callback).
    AvatarPawn->RebuildSwimmingStateFromWorld(true);

    if (DigimonComponent)
    {
        DigimonComponent->ServerSetCommandTarget(nullptr);

        if (ADMFDigimonCharacter* Partner = DigimonComponent->ActivePartnerActor)
        {
            if (Partner->CombatComponent)
            {
                Partner->CombatComponent->ForceAuthoritativeDisengage();
            }

            // Return Home is an encounter boundary. Disengage any authoritative Digimon still targeting
            // this partner and remove already-launched projectiles aimed at it so combat cannot follow the
            // player across the world and land a delayed hit at the Home spawn.
            if (UWorld* World = GetWorld())
            {
                for (TActorIterator<ADMFDigimonCharacter> It(World); It; ++It)
                {
                    ADMFDigimonCharacter* Other = *It;
                    if (IsValid(Other) && Other != Partner && Other->CombatComponent
                        && Other->CombatComponent->GetCurrentTarget() == Partner)
                    {
                        Other->CombatComponent->ForceAuthoritativeDisengage();
                    }
                }
                for (TActorIterator<ADMFAbilityProjectileActor> It(World); It; ++It)
                {
                    ADMFAbilityProjectileActor* Projectile = *It;
                    if (IsValid(Projectile)
                        && (Projectile->GetTargetDigimon() == Partner || Projectile->GetSourceDigimon() == Partner))
                    {
                        Projectile->Destroy();
                    }
                }
            }

            const FVector PartnerOffset = Settings ? Settings->PartnerSpawnOffset : FVector(150.0, 120.0, 0.0);
            const FVector DesiredPartnerLocation = AvatarPawn->GetActorTransform().TransformPosition(PartnerOffset);
            if (!Partner->TeleportTo(DesiredPartnerLocation, AvatarPawn->GetActorRotation(), false, false))
            {
                // If the normal offset is blocked, keep the partner coherent with its owner by trying the
                // authoritative player's safe destination. The follow-anchor can recover naturally if both fail.
                if (!Partner->TeleportTo(AvatarPawn->GetActorLocation(), AvatarPawn->GetActorRotation(), false, false))
                {
                    UE_LOG(LogDigimonMMOFramework, Warning,
                        TEXT("Return Home could not immediately relocate partner '%s' for account '%s'; normal follow recovery remains active."),
                        *GetNameSafe(Partner), *PlayerState->GetAuthenticatedUsername());
                }
            }
            Partner->ForceNetUpdate();
        }
    }

    // The private command-target state lives on the PlayerState-owned component; flush that owner as well
    // so the local targeting marker clears promptly after an authoritative Return Home.
    PlayerState->ForceNetUpdate();
    AvatarPawn->ForceNetUpdate();
    PlayerController->ForceNetUpdate();

    // Return Home is an explicit persistent checkpoint. Saving immediately prevents a crash/disconnect
    // from restoring the pre-teleport location on the next login.
    if (!SaveAuthenticatedPlayerWorldLocationNow(PlayerController))
    {
        UE_LOG(LogDigimonMMOFramework, Warning,
            TEXT("Return Home succeeded for '%s' but the immediate world-location checkpoint failed; the normal autosave may still recover it."),
            *PlayerState->GetAuthenticatedUsername());
    }

    OutMessage = NSLOCTEXT("DMF", "ReturnHomeSuccess", "Teleported to the Home spawn point.");
    return true;
}

bool ADMFMMOGameMode::ResolveInitialPlayerWorldTransform(
    APlayerController* PlayerController,
    FTransform& OutTransform,
    bool& bOutHasCustomTransform,
    bool& bOutRestoredSavedLocation,
    bool& bOutFirstLocationCheckpoint) const
{
    OutTransform = FTransform::Identity;
    bOutHasCustomTransform = false;
    bOutRestoredSavedLocation = false;
    bOutFirstLocationCheckpoint = false;

    const ADMFPlayerState* PlayerState = PlayerController ? PlayerController->GetPlayerState<ADMFPlayerState>() : nullptr;
    if (!PlayerState || PlayerState->GetAuthenticatedUsername().IsEmpty())
    {
        return false;
    }

    UGameInstance* GameInstance = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GameInstance ? GameInstance->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!Persistence)
    {
        return false;
    }

    FDMFAccountRecord Record;
    if (!Persistence->GetAccount(PlayerState->GetAuthenticatedUsername(), Record))
    {
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bLocationPersistenceEnabled = !Settings || Settings->bEnablePlayerWorldLocationPersistence;
    const bool bHasSavedLocation = Record.PlayerWorldLocation.bHasSavedLocation;
    bOutFirstLocationCheckpoint = !bHasSavedLocation;

    if (bLocationPersistenceEnabled && bHasSavedLocation)
    {
        const FString CurrentMapName = UGameplayStatics::GetCurrentLevelName(this, true);
        const FDMFPlayerWorldLocationState& Saved = Record.PlayerWorldLocation;
        const bool bMapMatches = !Saved.MapName.IsEmpty() && Saved.MapName.Equals(CurrentMapName, ESearchCase::IgnoreCase);
        const bool bFiniteTransform = !Saved.Location.ContainsNaN() && !Saved.Rotation.ContainsNaN();

        if (bMapMatches && bFiniteTransform)
        {
            OutTransform = FTransform(Saved.Rotation.GetNormalized(), Saved.Location);
            bOutHasCustomTransform = true;
            bOutRestoredSavedLocation = true;
            return true;
        }

        UE_LOG(LogDigimonMMOFramework, Warning,
            TEXT("Saved player location for '%s' was not restored (saved map='%s', current map='%s', finite=%s). Using the normal PlayerStart for this login."),
            *PlayerState->GetAuthenticatedUsername(), *Saved.MapName, *CurrentMapName, bFiniteTransform ? TEXT("true") : TEXT("false"));
        return true;
    }

    const bool bUseDedicatedNewPlayerSpawn = !Settings || Settings->bUseDedicatedNewPlayerSpawn;
    const bool bFreshOnboardingAccount = !Record.bStarterSelected
        && !Record.ActivePartnerInstanceId.IsValid()
        && Record.DigimonInventory.IsEmpty()
        && Record.DigimonBank.IsEmpty();

    if (!bHasSavedLocation && bUseDedicatedNewPlayerSpawn && bFreshOnboardingAccount)
    {
        if (ADMFNewPlayerStart* NewPlayerStart = ChooseNewPlayerSpawnPoint(PlayerController))
        {
            OutTransform = NewPlayerStart->GetActorTransform();
            OutTransform.SetScale3D(FVector::OneVector);
            bOutHasCustomTransform = true;
            return true;
        }

        UE_LOG(LogDigimonMMOFramework, Warning,
            TEXT("Fresh account '%s' has no saved world location, but no enabled DMFNewPlayerStart exists. Falling back to Unreal's normal PlayerStart and checkpointing that location."),
            *PlayerState->GetAuthenticatedUsername());
    }
    else if (!bHasSavedLocation && !bFreshOnboardingAccount)
    {
        // Pre-v0.15.1 established accounts have no world-location field yet, but they are not new players.
        // Give them the normal PlayerStart once, checkpoint it immediately, then restore normally thereafter.
        UE_LOG(LogDigimonMMOFramework, Log,
            TEXT("Established account '%s' has no v6 world-location checkpoint yet. Using the normal PlayerStart once before creating its first checkpoint."),
            *PlayerState->GetAuthenticatedUsername());
    }

    return true;
}

bool ADMFMMOGameMode::ApplyInitialPlayerWorldLocation(APlayerController* PlayerController)
{
    if (!HasAuthority() || !IsValid(PlayerController))
    {
        return false;
    }

    const TWeakObjectPtr<APlayerController> PlayerKey(PlayerController);
    if (InitialWorldLocationApplied.Contains(PlayerKey))
    {
        return true;
    }

    ADMFPlayerAvatarCharacter* AvatarPawn = Cast<ADMFPlayerAvatarCharacter>(PlayerController->GetPawn());
    if (!IsValid(AvatarPawn))
    {
        return false;
    }

    FTransform DesiredTransform = FTransform::Identity;
    bool bHasCustomTransform = false;
    bool bRestoredSavedLocation = false;
    bool bFirstLocationCheckpoint = false;
    if (!ResolveInitialPlayerWorldTransform(PlayerController, DesiredTransform, bHasCustomTransform, bRestoredSavedLocation, bFirstLocationCheckpoint))
    {
        return false;
    }

    if (bHasCustomTransform)
    {
        const bool bTeleported = AvatarPawn->TeleportTo(
            DesiredTransform.GetLocation(),
            DesiredTransform.Rotator(),
            false,
            false);

        if (!bTeleported)
        {
            UE_LOG(LogDigimonMMOFramework, Warning,
                TEXT("Initial player transform for '%s' was obstructed; keeping Unreal's collision-safe PlayerStart result instead."),
                *GetNameSafe(PlayerController));
            bRestoredSavedLocation = false;
        }
    }

    // Initial restore may teleport directly into a swimmable volume before UE has delivered BeginOverlap. Rebuild
    // from authoritative water geometry now, before partner restoration and before another CharacterMovement frame
    // can apply Falling gravity. This also correctly clears stale water state when a transform restores onto land.
    AvatarPawn->RebuildSwimmingStateFromWorld(bRestoredSavedLocation);

    InitialWorldLocationApplied.Add(PlayerKey);
    AvatarPawn->ForceNetUpdate();
    PlayerController->ForceNetUpdate();

    if (bFirstLocationCheckpoint)
    {
        // Commit the first gameplay spawn immediately so a crash/disconnect before the periodic autosave
        // cannot make this account appear brand-new again on its next login.
        SaveAuthenticatedPlayerWorldLocationNow(PlayerController);
    }

    BP_OnInitialPlayerWorldLocationApplied(
        PlayerController,
        bRestoredSavedLocation,
        bFirstLocationCheckpoint,
        AvatarPawn->GetActorLocation(),
        AvatarPawn->GetActorRotation());
    return true;
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

    // Resolve first-login DMFNewPlayerStart or returning-account persisted coordinates before partner
    // spawning and before we reassert the owning client's possession presentation.
    ApplyInitialPlayerWorldLocation(PlayerController);

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

bool ADMFMMOGameMode::RehydrateAuthenticatedPlayerState(APlayerController* PlayerController, const TCHAR* Context) const
{
    if (!HasAuthority() || !IsValid(PlayerController))
    {
        return false;
    }

    ADMFPlayerState* PlayerState = PlayerController->GetPlayerState<ADMFPlayerState>();
    if (!PlayerState)
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("%s account rehydrate failed: controller has no DMF PlayerState."), Context ? Context : TEXT("Unknown"));
        return false;
    }

    const FString Username = PlayerState->GetAuthenticatedUsername();
    if (Username.IsEmpty())
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("%s account rehydrate failed: authenticated username is empty."), Context ? Context : TEXT("Unknown"));
        return false;
    }

    UGameInstance* GameInstance = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GameInstance ? GameInstance->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!Persistence)
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("%s account rehydrate failed for '%s': persistence subsystem unavailable."), Context ? Context : TEXT("Unknown"), *Username);
        return false;
    }

    FDMFAccountRecord Record;
    if (!Persistence->GetAccount(Username, Record))
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("%s account rehydrate failed for '%s': persistent record not found."), Context ? Context : TEXT("Unknown"), *Username);
        return false;
    }

    if (PlayerState->AvatarComponent)
    {
        PlayerState->AvatarComponent->InitializeFromAccountRecord(Record);
    }
    if (PlayerState->DigimonComponent)
    {
        PlayerState->DigimonComponent->InitializeFromAccountRecord(Record);
    }

    UE_LOG(LogDigimonMMOFramework, Log,
        TEXT("%s account rehydrate complete for '%s' (Party=%d, Bank=%d, ActivePartner=%s, Starter=%s, Skin=%s)."),
        Context ? Context : TEXT("Unknown"),
        *Username,
        Record.DigimonInventory.Num(),
        Record.DigimonBank.Num(),
        *Record.ActivePartnerInstanceId.ToString(),
        Record.bStarterSelected ? TEXT("true") : TEXT("false"),
        *Record.SelectedPlayerSkinId.ToString());
    return true;
}

void ADMFMMOGameMode::PostLogin(APlayerController* NewPlayer)
{
    // AGameMode::PostLogin normally calls FindInactivePlayer and can replace the freshly initialized
    // PlayerState with a duplicated disconnected PlayerState. DMF deliberately disables that path below:
    // the authenticated persistent account is the sole reconnect authority.
    Super::PostLogin(NewPlayer);

    ADMFPlayerState* PlayerState = NewPlayer ? NewPlayer->GetPlayerState<ADMFPlayerState>() : nullptr;
    if (PlayerState && PlayerState->DigimonComponent && !PlayerState->DigimonComponent->HasAuthoritativeAccountStateInitialized())
    {
        RehydrateAuthenticatedPlayerState(NewPlayer, TEXT("PostLogin integrity"));
    }
}

void ADMFMMOGameMode::AddInactivePlayer(APlayerState* PlayerState, APlayerController* PC)
{
    // Intentionally do NOT call Super. AGameMode's default implementation duplicates PlayerState into
    // InactivePlayerArray. That cache is unsuitable for DMF because the PlayerState owns replicated Party/Bank
    // and avatar components while the server account database is already our durable reconnect source.
    // Keeping the duplicate permits PostLogin to substitute stale teardown state over a freshly loaded account.
    UE_LOG(LogDigimonMMOFramework, Verbose,
        TEXT("DMF skipped inactive PlayerState caching for '%s'; reconnect will reload the authenticated account database."),
        PlayerState ? *PlayerState->GetPlayerName() : TEXT("Unknown"));
}

bool ADMFMMOGameMode::FindInactivePlayer(APlayerController* PC)
{
    // Never reassociate an engine-cached PlayerState. Authentication + UDMFAccountPersistenceSubsystem is the
    // canonical reconnect contract, including reconnects from another machine/IP and Shipping builds.
    return false;
}

void ADMFMMOGameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
    // Preserve Unreal's normal PlayerStart/restart path, then validate the result. Late-joining remote
    // clients are explicitly repaired if Unreal left them unpossessed or in a DefaultPawn/SpectatorPawn.
    Super::HandleStartingNewPlayer_Implementation(NewPlayer);

    EnsureFrameworkPlayerAvatar(NewPlayer);
    ScheduleFrameworkPlayerAvatarValidation(NewPlayer);
}

bool ADMFMMOGameMode::SavePlayerState(ADMFPlayerState* PlayerState) const
{
    if (!PlayerState || !PlayerState->DigimonComponent || PlayerState->GetAuthenticatedUsername().IsEmpty())
    {
        return false;
    }

    // Never serialize a default/half-initialized PlayerState over an established account. This matters most
    // during remote Shipping disconnects where network teardown can race owner/pawn destruction.
    if (!PlayerState->DigimonComponent->HasAuthoritativeAccountStateInitialized())
    {
        UE_LOG(LogDigimonMMOFramework, Warning,
            TEXT("Refusing disconnect save for '%s' because its authoritative account state was not fully initialized; preserving the existing persistent record."),
            *PlayerState->GetAuthenticatedUsername());
        return false;
    }

    UGameInstance* GI = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!Persistence)
    {
        return false;
    }

    FDMFAccountRecord Record;
    if (!Persistence->GetAccount(PlayerState->GetAuthenticatedUsername(), Record))
    {
        UE_LOG(LogDigimonMMOFramework, Error,
            TEXT("Disconnect save could not reload the persistent account record for '%s'."),
            *PlayerState->GetAuthenticatedUsername());
        return false;
    }

    // Pull the final authoritative HP/SP directly from the live partner before building the account snapshot.
    // This closes the last-frame gap between combat replication/delegates and a sudden remote disconnect.
    PlayerState->DigimonComponent->SynchronizeActivePartnerRuntimeForPersistence();
    PlayerState->DigimonComponent->ApplyToAccountRecord(Record);

    if (PlayerState->AvatarComponent)
    {
        PlayerState->AvatarComponent->ApplyToAccountRecord(Record);
        // If Unreal has already detached the pawn, this intentionally returns false and leaves the most recent
        // valid world checkpoint in Record untouched rather than replacing it with invalid/default coordinates.
        PlayerState->AvatarComponent->ApplyCurrentWorldLocationToAccountRecord(Record);
    }

    FString Error;
    if (!Persistence->SaveAccount(Record, Error))
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("Logout save failed for '%s': %s"), *PlayerState->GetAuthenticatedUsername(), *Error);
        return false;
    }

    UE_LOG(LogDigimonMMOFramework, Log,
        TEXT("Committed disconnect account snapshot for '%s' (Party=%d, Bank=%d, ActivePartner=%s, Skin=%s)."),
        *PlayerState->GetAuthenticatedUsername(),
        Record.DigimonInventory.Num(),
        Record.DigimonBank.Num(),
        *Record.ActivePartnerInstanceId.ToString(),
        *Record.SelectedPlayerSkinId.ToString());
    return true;
}

bool ADMFMMOGameMode::FinalizeAuthenticatedPlayerSession(APlayerController* PlayerController)
{
    if (!HasAuthority() || !IsValid(PlayerController))
    {
        return false;
    }

    ADMFPlayerState* PlayerState = PlayerController->GetPlayerState<ADMFPlayerState>();
    if (!PlayerState)
    {
        return false;
    }

    if (PlayerState->DigimonComponent && PlayerState->DigimonComponent->IsDisconnectPersistenceFinalized())
    {
        // Logout and PlayerController::EndPlay can legitimately observe the same disconnect. Once the canonical
        // snapshot has committed, this path must be a no-op instead of issuing another teardown-time disk write.
        PlayerState->DigimonComponent->FinalizeForOwnerDisconnect(true);
        InitialWorldLocationApplied.Remove(TWeakObjectPtr<APlayerController>(PlayerController));
        return true;
    }

    const bool bSaved = SavePlayerState(PlayerState);
    if (PlayerState->DigimonComponent)
    {
        // Destroy the transient partner regardless of disk-save outcome so disconnected sessions never leave
        // combat-capable orphan actors. If bSaved is false, EndPlay keeps one guarded persistence retry available.
        PlayerState->DigimonComponent->FinalizeForOwnerDisconnect(bSaved);
    }

    InitialWorldLocationApplied.Remove(TWeakObjectPtr<APlayerController>(PlayerController));
    return bSaved;
}

void ADMFMMOGameMode::Logout(AController* Exiting)
{
    if (APlayerController* PC = Cast<APlayerController>(Exiting))
    {
        // Canonical disconnect transaction MUST happen before Super::Logout, because Unreal may detach/retain
        // PlayerState/Pawn objects as part of the inactive-player lifecycle after this point.
        FinalizeAuthenticatedPlayerSession(PC);
    }

    Super::Logout(Exiting);
}
