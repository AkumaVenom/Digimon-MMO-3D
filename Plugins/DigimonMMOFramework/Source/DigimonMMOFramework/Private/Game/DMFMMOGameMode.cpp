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
#include "GameFramework/GameSession.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"

ADMFMMOGameMode::ADMFMMOGameMode()
{
    PlayerStateClass = ADMFPlayerState::StaticClass();
    PlayerControllerClass = ADMFMMOPlayerController::StaticClass();
    DefaultPawnClass = ADMFPlayerAvatarCharacter::StaticClass();
}

int32 ADMFMMOGameMode::ResolveConfiguredMaximumPlayers() const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    return Settings ? FMath::Clamp(Settings->GlobalMaxPlayers, 1, 10000) : 100;
}

void ADMFMMOGameMode::ApplyConfiguredPlayerCapacity()
{
    if (GameSession)
    {
        // Reassert the deployment setting on authority instead of trusting a client-supplied URL option.
        // AGameMode::PreLogin subsequently asks GameSession to approve the connection and enforces MaxPlayers.
        GameSession->MaxPlayers = ResolveConfiguredMaximumPlayers();
    }
}

void ADMFMMOGameMode::StartPlay()
{
    Super::StartPlay();

    ApplyConfiguredPlayerCapacity();
    if (HasAuthority())
    {
        UE_LOG(LogDigimonMMOFramework, Log,
            TEXT("Authoritative server player capacity initialized to %d simultaneous player(s)."),
            ResolveConfiguredMaximumPlayers());
    }

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
    // Apply the server-owned Project Settings capacity immediately before Unreal's normal GameSession approval.
    // This deliberately occurs before Super::PreLogin so AGameSession::ApproveLogin/AtCapacity uses the DMF cap.
    // Reapplying it per connection also prevents a manually crafted client URL from changing server capacity.
    ApplyConfiguredPlayerCapacity();
    const int32 PlayersBeforeLogin = GetNumPlayers();
    const int32 MaximumPlayers = ResolveConfiguredMaximumPlayers();

    Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
    if (!ErrorMessage.IsEmpty())
    {
        if (PlayersBeforeLogin >= MaximumPlayers)
        {
            UE_LOG(LogDigimonMMOFramework, Log,
                TEXT("Rejected incoming connection because the server is at player capacity (%d/%d)."),
                PlayersBeforeLogin, MaximumPlayers);
        }
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

bool ADMFMMOGameMode::DispatchWorldChatMessage(const FDMFWorldChatMessage& ChatMessage, ADMFMMOPlayerController* EventSourceController)
{
    if (!HasAuthority() || ChatMessage.Message.IsEmpty())
    {
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableWorldChat)
    {
        return false;
    }

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
                if (ShouldDeliverWorldChatMessageToRecipient(ChatMessage, Recipient))
                {
                    Recipient->ClientReceiveWorldChatMessage(ChatMessage);
                }
            }
        }
    }

    BP_OnWorldChatMessageAccepted(ChatMessage, EventSourceController);
    return true;
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
    return DispatchWorldChatMessage(ChatMessage, SenderController);
}

bool ADMFMMOGameMode::BroadcastWorldChatPresenceEvent(ADMFMMOPlayerController* SubjectController, const EDMFWorldChatMessageType PresenceType)
{
    if (!HasAuthority() || !IsValid(SubjectController)
        || (PresenceType != EDMFWorldChatMessageType::PlayerJoined && PresenceType != EDMFWorldChatMessageType::PlayerLeft))
    {
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && (!Settings->bEnableWorldChat || !Settings->bEnableWorldChatPresenceAnnouncements))
    {
        return false;
    }

    const ADMFPlayerState* SubjectPlayerState = SubjectController->GetPlayerState<ADMFPlayerState>();
    if (!SubjectPlayerState)
    {
        return false;
    }

    // Presence identity comes from the authenticated owner-only account value while it still exists on authority.
    // PlayerName is only a defensive public-display fallback; clients never supply the event username.
    FString PublicUsername = SubjectPlayerState->GetAuthenticatedUsername();
    PublicUsername.TrimStartAndEndInline();
    if (PublicUsername.IsEmpty())
    {
        PublicUsername = SubjectPlayerState->GetPlayerName();
        PublicUsername.TrimStartAndEndInline();
    }
    if (PublicUsername.IsEmpty())
    {
        return false;
    }

    FDMFWorldChatMessage ChatMessage;
    ChatMessage.SenderName = PublicUsername;
    ChatMessage.Message = PresenceType == EDMFWorldChatMessageType::PlayerJoined
        ? TEXT("has joined the server.")
        : TEXT("has left the server.");
    ChatMessage.SentUtcTicks = FDateTime::UtcNow().GetTicks();
    ChatMessage.MessageType = PresenceType;
    return DispatchWorldChatMessage(ChatMessage, SubjectController);
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
        if (ShouldDeliverWorldChatMessageToRecipient(RecentWorldChatMessages[Index], RecipientController))
        {
            BoundedHistory.Add(RecentWorldChatMessages[Index]);
        }
    }
    RecipientController->ClientReceiveWorldChatHistory(BoundedHistory);
}

bool ADMFMMOGameMode::ShouldDeliverWorldChatMessageToRecipient(const FDMFWorldChatMessage& ChatMessage, ADMFMMOPlayerController* RecipientController) const
{
    if (!IsValid(RecipientController) || ChatMessage.MessageType != EDMFWorldChatMessageType::Player || ChatMessage.SenderName.TrimStartAndEnd().IsEmpty())
    {
        return true;
    }

    const ADMFPlayerState* RecipientState = RecipientController->GetPlayerState<ADMFPlayerState>();
    const FString RecipientUsername = RecipientState ? RecipientState->GetAuthenticatedUsername().TrimStartAndEnd() : FString();
    if (RecipientUsername.IsEmpty())
    {
        return true;
    }

    UGameInstance* GI = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    FDMFAccountRecord RecipientRecord;
    if (!Persistence || !Persistence->GetAccount(RecipientUsername, RecipientRecord))
    {
        return true;
    }

    return !RecipientRecord.IgnoredUsernames.ContainsByPredicate([&ChatMessage](const FString& IgnoredName)
    {
        return IgnoredName.Equals(ChatMessage.SenderName, ESearchCase::IgnoreCase);
    });
}

bool ADMFMMOGameMode::BuildSocialSnapshot(ADMFMMOPlayerController* RecipientController, FDMFSocialSnapshot& OutSnapshot) const
{
    OutSnapshot = FDMFSocialSnapshot();
    if (!HasAuthority() || !IsValid(RecipientController))
    {
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableSocialSystem)
    {
        return true;
    }

    const ADMFPlayerState* RecipientState = RecipientController->GetPlayerState<ADMFPlayerState>();
    const FString Username = RecipientState ? RecipientState->GetAuthenticatedUsername().TrimStartAndEnd() : FString();
    UGameInstance* GI = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    FDMFAccountRecord Account;
    if (Username.IsEmpty() || !Persistence || !Persistence->GetAccount(Username, Account))
    {
        return false;
    }

    auto IsOnline = [this](const FString& CandidateUsername) -> bool
    {
        if (CandidateUsername.TrimStartAndEnd().IsEmpty() || !GetWorld())
        {
            return false;
        }
        for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
        {
            const ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(It->Get());
            const ADMFPlayerState* PS = PC ? PC->GetPlayerState<ADMFPlayerState>() : nullptr;
            if (PS && PS->GetAuthenticatedUsername().Equals(CandidateUsername, ESearchCase::IgnoreCase))
            {
                return true;
            }
        }
        return false;
    };

    for (const FString& FriendUsername : Account.FriendUsernames)
    {
        if (FriendUsername.TrimStartAndEnd().IsEmpty())
        {
            continue;
        }
        FDMFSocialFriendEntry Entry;
        Entry.Username = FriendUsername;
        Entry.bOnline = IsOnline(FriendUsername);
        Entry.bTrackingEnabled = Account.TrackedFriendUsernames.ContainsByPredicate([&FriendUsername](const FString& TrackedName)
        {
            return TrackedName.Equals(FriendUsername, ESearchCase::IgnoreCase);
        });
        OutSnapshot.Friends.Add(Entry);
    }
    OutSnapshot.Friends.Sort([](const FDMFSocialFriendEntry& A, const FDMFSocialFriendEntry& B)
    {
        if (A.bOnline != B.bOnline)
        {
            return A.bOnline && !B.bOnline;
        }
        return A.Username.Compare(B.Username, ESearchCase::IgnoreCase) < 0;
    });

    OutSnapshot.PendingFriendRequests = Account.PendingFriendRequests;
    OutSnapshot.PendingFriendRequests.Sort([](const FString& A, const FString& B) { return A.Compare(B, ESearchCase::IgnoreCase) < 0; });
    OutSnapshot.PendingOutgoingFriendRequests = Account.PendingOutgoingFriendRequests;
    OutSnapshot.PendingOutgoingFriendRequests.Sort([](const FString& A, const FString& B) { return A.Compare(B, ESearchCase::IgnoreCase) < 0; });
    OutSnapshot.IgnoredPlayers = Account.IgnoredUsernames;
    OutSnapshot.IgnoredPlayers.Sort([](const FString& A, const FString& B) { return A.Compare(B, ESearchCase::IgnoreCase) < 0; });

    for (const FDMFGuildInvite& StoredInvite : Account.PendingGuildInvites)
    {
        FDMFGuildRecord Guild;
        if (!StoredInvite.GuildId.IsValid() || !Persistence->GetGuild(StoredInvite.GuildId, Guild))
        {
            continue;
        }
        FDMFGuildInvite Invite = StoredInvite;
        Invite.GuildName = Guild.Name;
        OutSnapshot.PendingGuildInvites.Add(Invite);
    }

    TArray<FDMFGuildRecord> Guilds;
    Persistence->GetAllGuilds(Guilds);
    Guilds.Sort([](const FDMFGuildRecord& A, const FDMFGuildRecord& B)
    {
        return A.Name.Compare(B.Name, ESearchCase::IgnoreCase) < 0;
    });

    for (const FDMFGuildRecord& Guild : Guilds)
    {
        if (!Guild.GuildId.IsValid() || Guild.Name.TrimStartAndEnd().IsEmpty())
        {
            continue;
        }
        FDMFGuildSummary Summary;
        Summary.GuildId = Guild.GuildId;
        Summary.Name = Guild.Name;
        Summary.OwnerUsername = Guild.OwnerUsername;
        Summary.MemberCount = Guild.MemberUsernames.Num();
        Summary.bApplicationPending = Guild.PendingApplications.ContainsByPredicate([&Username](const FString& Applicant)
        {
            return Applicant.Equals(Username, ESearchCase::IgnoreCase);
        });
        OutSnapshot.GuildSearchResults.Add(Summary);
    }

    FDMFGuildRecord OwnGuild;
    if (Account.GuildId.IsValid() && Persistence->GetGuild(Account.GuildId, OwnGuild))
    {
        const bool bIsMember = OwnGuild.MemberUsernames.ContainsByPredicate([&Username](const FString& Member)
        {
            return Member.Equals(Username, ESearchCase::IgnoreCase);
        });
        if (bIsMember)
        {
            OutSnapshot.GuildId = OwnGuild.GuildId;
            OutSnapshot.GuildName = OwnGuild.Name;
            OutSnapshot.GuildOwnerUsername = OwnGuild.OwnerUsername;
            OutSnapshot.bIsGuildOwner = OwnGuild.OwnerUsername.Equals(Username, ESearchCase::IgnoreCase);
            for (const FString& MemberUsername : OwnGuild.MemberUsernames)
            {
                FDMFGuildMemberEntry Member;
                Member.Username = MemberUsername;
                Member.bOwner = OwnGuild.OwnerUsername.Equals(MemberUsername, ESearchCase::IgnoreCase);
                Member.bOnline = IsOnline(MemberUsername);
                OutSnapshot.GuildMembers.Add(Member);
            }
            OutSnapshot.GuildMembers.Sort([](const FDMFGuildMemberEntry& A, const FDMFGuildMemberEntry& B)
            {
                if (A.bOwner != B.bOwner) return A.bOwner && !B.bOwner;
                if (A.bOnline != B.bOnline) return A.bOnline && !B.bOnline;
                return A.Username.Compare(B.Username, ESearchCase::IgnoreCase) < 0;
            });
            if (OutSnapshot.bIsGuildOwner)
            {
                OutSnapshot.PendingGuildApplications = OwnGuild.PendingApplications;
                OutSnapshot.PendingGuildApplications.Sort([](const FString& A, const FString& B) { return A.Compare(B, ESearchCase::IgnoreCase) < 0; });
            }
        }
    }

    return true;
}

void ADMFMMOGameMode::SendSocialSnapshot(ADMFMMOPlayerController* RecipientController) const
{
    if (!HasAuthority() || !IsValid(RecipientController))
    {
        return;
    }

    FDMFSocialSnapshot Snapshot;
    if (BuildSocialSnapshot(RecipientController, Snapshot))
    {
        RecipientController->ClientReceiveSocialSnapshot(Snapshot);
    }
}

void ADMFMMOGameMode::PushSocialSnapshotForUsername(const FString& Username) const
{
    if (!HasAuthority() || Username.TrimStartAndEnd().IsEmpty() || !GetWorld())
    {
        return;
    }

    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(It->Get());
        const ADMFPlayerState* PS = PC ? PC->GetPlayerState<ADMFPlayerState>() : nullptr;
        if (PS && PS->GetAuthenticatedUsername().Equals(Username, ESearchCase::IgnoreCase))
        {
            SendSocialSnapshot(PC);
            return;
        }
    }
}

void ADMFMMOGameMode::PushSocialSnapshotsToAllOnlinePlayers(const ADMFMMOPlayerController* ExcludedController) const
{
    if (!HasAuthority() || !GetWorld())
    {
        return;
    }

    // Guild-directory identity/member-count changes are rare but globally visible. Build each snapshot
    // independently so every connected account receives only its own private friends/ignore/request data.
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(It->Get()))
        {
            if (PC == ExcludedController)
            {
                continue;
            }
            const ADMFPlayerState* PS = PC->GetPlayerState<ADMFPlayerState>();
            if (PS && !PS->GetAuthenticatedUsername().TrimStartAndEnd().IsEmpty())
            {
                SendSocialSnapshot(PC);
            }
        }
    }
}

void ADMFMMOGameMode::RefreshSocialPresenceForUsername(const FString& Username) const
{
    if (!HasAuthority() || Username.TrimStartAndEnd().IsEmpty())
    {
        return;
    }

    UGameInstance* GI = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    FDMFAccountRecord Account;
    if (!Persistence || !Persistence->GetAccount(Username, Account))
    {
        return;
    }

    PushSocialSnapshotForUsername(Username);
    for (const FString& FriendUsername : Account.FriendUsernames)
    {
        PushSocialSnapshotForUsername(FriendUsername);
    }

    FDMFGuildRecord Guild;
    if (Account.GuildId.IsValid() && Persistence->GetGuild(Account.GuildId, Guild))
    {
        for (const FString& MemberUsername : Guild.MemberUsernames)
        {
            if (!MemberUsername.Equals(Username, ESearchCase::IgnoreCase))
            {
                PushSocialSnapshotForUsername(MemberUsername);
            }
        }
    }
}

bool ADMFMMOGameMode::ExecuteSocialAction(ADMFMMOPlayerController* RequestingController, const EDMFSocialActionType ActionType, const FString& SubjectUsername, const FGuid GuildId, const FString& TextValue, const bool bValue, FText& OutMessage)
{
    OutMessage = FText::GetEmpty();
    if (!HasAuthority() || !IsValid(RequestingController))
    {
        OutMessage = NSLOCTEXT("DMF", "SocialInvalidRequester", "Social services are unavailable for this player.");
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableSocialSystem)
    {
        OutMessage = NSLOCTEXT("DMF", "SocialDisabled", "The Social system is disabled on this server.");
        return false;
    }

    ADMFPlayerState* ActorState = RequestingController->GetPlayerState<ADMFPlayerState>();
    const FString ActorUsername = ActorState ? ActorState->GetAuthenticatedUsername().TrimStartAndEnd() : FString();
    UGameInstance* GI = GetGameInstance();
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    FDMFAccountRecord Actor;
    if (ActorUsername.IsEmpty() || !Persistence || !Persistence->GetAccount(ActorUsername, Actor))
    {
        OutMessage = NSLOCTEXT("DMF", "SocialAccountUnavailable", "Your authenticated account could not be loaded.");
        return false;
    }

    auto ContainsUsername = [](const TArray<FString>& Names, const FString& Candidate) -> bool
    {
        return Names.ContainsByPredicate([&Candidate](const FString& Existing)
        {
            return Existing.Equals(Candidate, ESearchCase::IgnoreCase);
        });
    };
    auto RemoveUsername = [](TArray<FString>& Names, const FString& Candidate) -> bool
    {
        const int32 Removed = Names.RemoveAll([&Candidate](const FString& Existing)
        {
            return Existing.Equals(Candidate, ESearchCase::IgnoreCase);
        });
        return Removed > 0;
    };
    auto AddUsernameUnique = [&ContainsUsername](TArray<FString>& Names, const FString& CanonicalName)
    {
        if (!ContainsUsername(Names, CanonicalName))
        {
            Names.Add(CanonicalName);
        }
    };
    auto Commit = [Persistence](const TArray<FDMFAccountRecord>& Accounts, const TArray<FDMFGuildRecord>& Guilds, const TArray<FGuid>& RemovedGuilds, FText& Message) -> bool
    {
        FString Error;
        if (!Persistence->SaveSocialTransaction(Accounts, Guilds, RemovedGuilds, Error))
        {
            UE_LOG(LogDigimonMMOFramework, Error, TEXT("Social persistence transaction failed: %s"), *Error);
            Message = NSLOCTEXT("DMF", "SocialSaveFailed", "The server could not save that Social change. Nothing was committed.");
            return false;
        }
        return true;
    };
    auto ResolveTarget = [Persistence](const FString& RequestedName, FDMFAccountRecord& OutTarget) -> bool
    {
        const FString Trimmed = RequestedName.TrimStartAndEnd();
        return !Trimmed.IsEmpty() && Persistence->GetAccount(Trimmed, OutTarget);
    };
    auto GuildExistsForAccount = [Persistence](const FDMFAccountRecord& Account, FDMFGuildRecord& OutGuild) -> bool
    {
        return Account.GuildId.IsValid() && Persistence->GetGuild(Account.GuildId, OutGuild);
    };
    auto SanitizeGuildName = [](const FString& Raw) -> FString
    {
        FString Name = Raw;
        Name.ReplaceInline(TEXT("\r"), TEXT(" "));
        Name.ReplaceInline(TEXT("\n"), TEXT(" "));
        Name.ReplaceInline(TEXT("\t"), TEXT(" "));
        Name.TrimStartAndEndInline();
        while (Name.Contains(TEXT("  ")))
        {
            Name.ReplaceInline(TEXT("  "), TEXT(" "));
        }
        return Name;
    };
    auto ValidateGuildName = [Settings, Persistence, &SanitizeGuildName](const FString& Raw, const FGuid ExcludedGuildId, FString& OutSanitized, FText& Message) -> bool
    {
        OutSanitized = SanitizeGuildName(Raw);
        const int32 MinLength = Settings ? FMath::Clamp(Settings->MinimumGuildNameLength, 1, 32) : 3;
        const int32 MaxLength = Settings ? FMath::Clamp(Settings->MaximumGuildNameLength, MinLength, 64) : 32;
        if (OutSanitized.Len() < MinLength || OutSanitized.Len() > MaxLength)
        {
            Message = FText::Format(NSLOCTEXT("DMF", "GuildNameLength", "Guild names must be between {0} and {1} characters."), FText::AsNumber(MinLength), FText::AsNumber(MaxLength));
            return false;
        }
        for (const TCHAR Char : OutSanitized)
        {
            if (!(FChar::IsAlnum(Char) || Char == TCHAR(' ') || Char == TCHAR('-') || Char == TCHAR('_') || Char == TCHAR('\'')))
            {
                Message = NSLOCTEXT("DMF", "GuildNameCharacters", "Guild names may use letters, numbers, spaces, apostrophes, hyphens and underscores.");
                return false;
            }
        }
        TArray<FDMFGuildRecord> Guilds;
        Persistence->GetAllGuilds(Guilds);
        for (const FDMFGuildRecord& Guild : Guilds)
        {
            if (Guild.GuildId != ExcludedGuildId && Guild.Name.Equals(OutSanitized, ESearchCase::IgnoreCase))
            {
                Message = NSLOCTEXT("DMF", "GuildNameTaken", "That guild name is already in use.");
                return false;
            }
        }
        return true;
    };
    auto RemoveApplicantFromOtherGuilds = [Persistence, &RemoveUsername](const FString& Username, const FGuid KeepGuildId, TArray<FDMFGuildRecord>& InOutUpserts)
    {
        TArray<FDMFGuildRecord> AllGuilds;
        Persistence->GetAllGuilds(AllGuilds);
        for (FDMFGuildRecord& Other : AllGuilds)
        {
            if (Other.GuildId == KeepGuildId)
            {
                continue;
            }
            if (RemoveUsername(Other.PendingApplications, Username))
            {
                Other.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
                InOutUpserts.Add(Other);
            }
        }
    };

    const int32 MaxFriends = Settings ? FMath::Clamp(Settings->MaximumFriendsPerAccount, 1, 1000) : 200;
    const int32 MaxIgnored = Settings ? FMath::Clamp(Settings->MaximumIgnoredPlayersPerAccount, 1, 1000) : 200;
    const int32 MaxGuildMembers = Settings ? FMath::Clamp(Settings->MaximumGuildMembers, 2, 1000) : 100;
    const int32 MaxGuildInvites = Settings ? FMath::Clamp(Settings->MaximumPendingGuildInvitesPerAccount, 1, 1000) : 100;
    const int32 MaxGuildApplications = Settings ? FMath::Clamp(Settings->MaximumPendingGuildApplicationsPerGuild, 1, 5000) : 500;

    if (ActionType == EDMFSocialActionType::SendFriendRequest)
    {
        FDMFAccountRecord Target;
        if (!ResolveTarget(SubjectUsername, Target))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendTargetNotFound", "That player account could not be found.");
            return false;
        }
        if (Target.Username.Equals(Actor.Username, ESearchCase::IgnoreCase))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendSelf", "You cannot add yourself as a friend.");
            return false;
        }
        if (ContainsUsername(Actor.IgnoredUsernames, Target.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendTargetIgnoredBySelf", "Remove this player from your Ignore list before adding them as a friend.");
            return false;
        }
        if (ContainsUsername(Target.IgnoredUsernames, Actor.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendRequestBlocked", "That friend request could not be delivered.");
            return false;
        }
        if (ContainsUsername(Actor.FriendUsernames, Target.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "AlreadyFriends", "That player is already on your Friends list.");
            return false;
        }
        if (Actor.FriendUsernames.Num() >= MaxFriends || Target.FriendUsernames.Num() >= MaxFriends)
        {
            OutMessage = NSLOCTEXT("DMF", "FriendLimitReached", "A Friends list is at its configured maximum capacity.");
            return false;
        }

        if (ContainsUsername(Actor.PendingFriendRequests, Target.Username))
        {
            RemoveUsername(Actor.PendingFriendRequests, Target.Username);
            RemoveUsername(Actor.PendingOutgoingFriendRequests, Target.Username);
            RemoveUsername(Target.PendingFriendRequests, Actor.Username);
            RemoveUsername(Target.PendingOutgoingFriendRequests, Actor.Username);
            AddUsernameUnique(Actor.FriendUsernames, Target.Username);
            AddUsernameUnique(Target.FriendUsernames, Actor.Username);
            if (!Commit({Actor, Target}, {}, {}, OutMessage)) return false;
            PushSocialSnapshotForUsername(Target.Username);
            OutMessage = FText::Format(NSLOCTEXT("DMF", "FriendMutualAccepted", "You and {0} are now friends."), FText::FromString(Target.Username));
            return true;
        }
        if (ContainsUsername(Target.PendingFriendRequests, Actor.Username) || ContainsUsername(Actor.PendingOutgoingFriendRequests, Target.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendRequestAlreadyPending", "A friend request is already pending for that player.");
            return false;
        }
        if (Actor.PendingOutgoingFriendRequests.Num() >= MaxFriends || Target.PendingFriendRequests.Num() >= MaxFriends)
        {
            OutMessage = NSLOCTEXT("DMF", "FriendRequestInboxFull", "That player's friend-request list is currently full.");
            return false;
        }

        Target.PendingFriendRequests.Add(Actor.Username);
        Actor.PendingOutgoingFriendRequests.Add(Target.Username);
        if (!Commit({Actor, Target}, {}, {}, OutMessage)) return false;
        PushSocialSnapshotForUsername(Target.Username);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "FriendRequestSent", "Friend request sent to {0}."), FText::FromString(Target.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::RespondFriendRequest)
    {
        FDMFAccountRecord Requester;
        if (!ResolveTarget(SubjectUsername, Requester) || !ContainsUsername(Actor.PendingFriendRequests, Requester.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendRequestMissing", "That friend request is no longer available.");
            return false;
        }

        if (!bValue)
        {
            RemoveUsername(Actor.PendingFriendRequests, Requester.Username);
            RemoveUsername(Requester.PendingOutgoingFriendRequests, Actor.Username);
            if (!Commit({Actor, Requester}, {}, {}, OutMessage)) return false;
            PushSocialSnapshotForUsername(Requester.Username);
            OutMessage = FText::Format(NSLOCTEXT("DMF", "FriendRequestDeclined", "Friend request from {0} declined."), FText::FromString(Requester.Username));
            return true;
        }

        if (ContainsUsername(Actor.IgnoredUsernames, Requester.Username) || ContainsUsername(Requester.IgnoredUsernames, Actor.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendAcceptBlocked", "That friend request cannot be accepted while either player is ignoring the other.");
            return false;
        }
        if (Actor.FriendUsernames.Num() >= MaxFriends || Requester.FriendUsernames.Num() >= MaxFriends)
        {
            OutMessage = NSLOCTEXT("DMF", "FriendAcceptLimit", "A Friends list is at its configured maximum capacity.");
            return false;
        }

        RemoveUsername(Actor.PendingFriendRequests, Requester.Username);
        RemoveUsername(Actor.PendingOutgoingFriendRequests, Requester.Username);
        RemoveUsername(Requester.PendingFriendRequests, Actor.Username);
        RemoveUsername(Requester.PendingOutgoingFriendRequests, Actor.Username);
        AddUsernameUnique(Actor.FriendUsernames, Requester.Username);
        AddUsernameUnique(Requester.FriendUsernames, Actor.Username);
        if (!Commit({Actor, Requester}, {}, {}, OutMessage)) return false;
        PushSocialSnapshotForUsername(Requester.Username);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "FriendRequestAccepted", "{0} is now your friend."), FText::FromString(Requester.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::CancelFriendRequest)
    {
        FDMFAccountRecord Target;
        if (!ResolveTarget(SubjectUsername, Target) || !ContainsUsername(Actor.PendingOutgoingFriendRequests, Target.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendCancelMissing", "That outgoing friend request is no longer pending.");
            return false;
        }

        RemoveUsername(Actor.PendingOutgoingFriendRequests, Target.Username);
        RemoveUsername(Target.PendingFriendRequests, Actor.Username);
        if (!Commit({Actor, Target}, {}, {}, OutMessage)) return false;
        PushSocialSnapshotForUsername(Target.Username);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "FriendRequestCancelled", "Friend request to {0} cancelled."), FText::FromString(Target.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::RemoveFriend)
    {
        FDMFAccountRecord FriendAccount;
        if (!ResolveTarget(SubjectUsername, FriendAccount) || !ContainsUsername(Actor.FriendUsernames, FriendAccount.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendRemoveMissing", "That player is not on your Friends list.");
            return false;
        }
        RemoveUsername(Actor.FriendUsernames, FriendAccount.Username);
        RemoveUsername(Actor.TrackedFriendUsernames, FriendAccount.Username);
        RemoveUsername(FriendAccount.FriendUsernames, Actor.Username);
        RemoveUsername(FriendAccount.TrackedFriendUsernames, Actor.Username);
        if (!Commit({Actor, FriendAccount}, {}, {}, OutMessage)) return false;
        PushSocialSnapshotForUsername(FriendAccount.Username);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "FriendRemoved", "{0} was removed from your Friends list."), FText::FromString(FriendAccount.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::SetFriendTracking)
    {
        FDMFAccountRecord FriendAccount;
        if (!ResolveTarget(SubjectUsername, FriendAccount) || !ContainsUsername(Actor.FriendUsernames, FriendAccount.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "FriendTrackMissing", "Only accepted friends can be tracked.");
            return false;
        }
        if (bValue) AddUsernameUnique(Actor.TrackedFriendUsernames, FriendAccount.Username);
        else RemoveUsername(Actor.TrackedFriendUsernames, FriendAccount.Username);
        if (!Commit({Actor}, {}, {}, OutMessage)) return false;
        OutMessage = bValue
            ? FText::Format(NSLOCTEXT("DMF", "FriendTrackingEnabled", "Distance tracking enabled for {0}."), FText::FromString(FriendAccount.Username))
            : FText::Format(NSLOCTEXT("DMF", "FriendTrackingDisabled", "Distance tracking hidden for {0}."), FText::FromString(FriendAccount.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::IgnorePlayer)
    {
        FDMFAccountRecord Target;
        if (!ResolveTarget(SubjectUsername, Target))
        {
            OutMessage = NSLOCTEXT("DMF", "IgnoreTargetMissing", "That player account could not be found.");
            return false;
        }
        if (Target.Username.Equals(Actor.Username, ESearchCase::IgnoreCase))
        {
            OutMessage = NSLOCTEXT("DMF", "IgnoreSelf", "You cannot ignore yourself.");
            return false;
        }
        if (ContainsUsername(Actor.IgnoredUsernames, Target.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "AlreadyIgnored", "That player is already ignored.");
            return false;
        }
        if (Actor.IgnoredUsernames.Num() >= MaxIgnored)
        {
            OutMessage = NSLOCTEXT("DMF", "IgnoreLimit", "Your Ignore list is at its configured maximum capacity.");
            return false;
        }

        Actor.IgnoredUsernames.Add(Target.Username);
        RemoveUsername(Actor.FriendUsernames, Target.Username);
        RemoveUsername(Actor.TrackedFriendUsernames, Target.Username);
        RemoveUsername(Actor.PendingFriendRequests, Target.Username);
        RemoveUsername(Actor.PendingOutgoingFriendRequests, Target.Username);
        RemoveUsername(Target.FriendUsernames, Actor.Username);
        RemoveUsername(Target.TrackedFriendUsernames, Actor.Username);
        RemoveUsername(Target.PendingFriendRequests, Actor.Username);
        RemoveUsername(Target.PendingOutgoingFriendRequests, Actor.Username);

        // Ignore is also a social-request boundary. Remove outstanding direct guild invitations in either
        // direction and owner-facing guild applications between these two accounts so an ignored player
        // cannot remain in a queued Social request surface after the block is committed.
        Actor.PendingGuildInvites.RemoveAll([&Target](const FDMFGuildInvite& Invite)
        {
            return Invite.InviterUsername.Equals(Target.Username, ESearchCase::IgnoreCase);
        });
        Target.PendingGuildInvites.RemoveAll([&Actor](const FDMFGuildInvite& Invite)
        {
            return Invite.InviterUsername.Equals(Actor.Username, ESearchCase::IgnoreCase);
        });

        TArray<FDMFGuildRecord> GuildUpserts;
        FDMFGuildRecord ActorGuild;
        if (GuildExistsForAccount(Actor, ActorGuild)
            && ActorGuild.OwnerUsername.Equals(Actor.Username, ESearchCase::IgnoreCase)
            && RemoveUsername(ActorGuild.PendingApplications, Target.Username))
        {
            ActorGuild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
            GuildUpserts.Add(ActorGuild);
        }
        FDMFGuildRecord TargetGuild;
        if (GuildExistsForAccount(Target, TargetGuild)
            && TargetGuild.OwnerUsername.Equals(Target.Username, ESearchCase::IgnoreCase)
            && RemoveUsername(TargetGuild.PendingApplications, Actor.Username))
        {
            TargetGuild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
            GuildUpserts.Add(TargetGuild);
        }

        if (!Commit({Actor, Target}, GuildUpserts, {}, OutMessage)) return false;
        PushSocialSnapshotForUsername(Target.Username);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "PlayerIgnored", "{0} is now ignored. Their authored WORLD chat will be filtered; their world actor remains visible."), FText::FromString(Target.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::RemoveIgnoredPlayer)
    {
        FDMFAccountRecord Target;
        if (!ResolveTarget(SubjectUsername, Target) || !RemoveUsername(Actor.IgnoredUsernames, Target.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "IgnoreRemoveMissing", "That player is not on your Ignore list.");
            return false;
        }
        if (!Commit({Actor}, {}, {}, OutMessage)) return false;
        OutMessage = FText::Format(NSLOCTEXT("DMF", "IgnoreRemoved", "{0} was removed from your Ignore list."), FText::FromString(Target.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::CreateGuild)
    {
        FDMFGuildRecord ExistingGuild;
        if (GuildExistsForAccount(Actor, ExistingGuild))
        {
            OutMessage = NSLOCTEXT("DMF", "AlreadyInGuildCreate", "Leave your current guild before creating another one.");
            return false;
        }
        if (Actor.GuildId.IsValid())
        {
            Actor.GuildId.Invalidate();
        }

        FString GuildName;
        if (!ValidateGuildName(TextValue, FGuid(), GuildName, OutMessage)) return false;
        FDMFGuildRecord NewGuild;
        NewGuild.GuildId = FGuid::NewGuid();
        NewGuild.Name = GuildName;
        NewGuild.OwnerUsername = Actor.Username;
        NewGuild.MemberUsernames.Add(Actor.Username);
        NewGuild.CreatedUtcTicks = FDateTime::UtcNow().GetTicks();
        NewGuild.LastModifiedUtcTicks = NewGuild.CreatedUtcTicks;
        Actor.GuildId = NewGuild.GuildId;
        Actor.PendingGuildInvites.Reset();
        if (!Commit({Actor}, {NewGuild}, {}, OutMessage)) return false;
        PushSocialSnapshotsToAllOnlinePlayers(RequestingController);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildCreated", "Guild {0} created."), FText::FromString(GuildName));
        return true;
    }

    if (ActionType == EDMFSocialActionType::RenameGuild)
    {
        FDMFGuildRecord Guild;
        if (!GuildExistsForAccount(Actor, Guild) || !Guild.OwnerUsername.Equals(Actor.Username, ESearchCase::IgnoreCase))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildRenameOwnerOnly", "Only the guild owner can rename this guild.");
            return false;
        }
        FString NewName;
        if (!ValidateGuildName(TextValue, Guild.GuildId, NewName, OutMessage)) return false;
        Guild.Name = NewName;
        Guild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
        if (!Commit({}, {Guild}, {}, OutMessage)) return false;
        PushSocialSnapshotsToAllOnlinePlayers(RequestingController);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildRenamed", "Guild renamed to {0}."), FText::FromString(NewName));
        return true;
    }

    if (ActionType == EDMFSocialActionType::InvitePlayerToGuild)
    {
        FDMFGuildRecord Guild;
        if (!GuildExistsForAccount(Actor, Guild) || !Guild.OwnerUsername.Equals(Actor.Username, ESearchCase::IgnoreCase))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildInviteOwnerOnly", "Only the guild owner can invite players.");
            return false;
        }
        if (Guild.MemberUsernames.Num() >= MaxGuildMembers)
        {
            OutMessage = NSLOCTEXT("DMF", "GuildFullInvite", "Your guild is at its configured member limit.");
            return false;
        }
        FDMFAccountRecord Target;
        if (!ResolveTarget(SubjectUsername, Target) || Target.Username.Equals(Actor.Username, ESearchCase::IgnoreCase))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildInviteTargetMissing", "That player cannot be invited.");
            return false;
        }
        FDMFGuildRecord TargetGuild;
        if (GuildExistsForAccount(Target, TargetGuild))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildInviteAlreadyMember", "That player is already in a guild.");
            return false;
        }
        if (ContainsUsername(Actor.IgnoredUsernames, Target.Username) || ContainsUsername(Target.IgnoredUsernames, Actor.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildInviteBlocked", "That guild invitation could not be delivered while either player is ignoring the other.");
            return false;
        }
        if (Target.PendingGuildInvites.ContainsByPredicate([&Guild](const FDMFGuildInvite& Invite) { return Invite.GuildId == Guild.GuildId; }))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildInvitePending", "That player already has a pending invitation from your guild.");
            return false;
        }
        if (Target.PendingGuildInvites.Num() >= MaxGuildInvites)
        {
            OutMessage = NSLOCTEXT("DMF", "GuildInviteInboxFull", "That player's guild-invitation list is full.");
            return false;
        }

        FDMFGuildInvite Invite;
        Invite.GuildId = Guild.GuildId;
        Invite.GuildName = Guild.Name;
        Invite.InviterUsername = Actor.Username;
        Invite.SentUtcTicks = FDateTime::UtcNow().GetTicks();
        Target.PendingGuildInvites.Add(Invite);
        if (Target.GuildId.IsValid()) Target.GuildId.Invalidate();
        if (!Commit({Target}, {}, {}, OutMessage)) return false;
        PushSocialSnapshotForUsername(Target.Username);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildInviteSent", "Guild invitation sent to {0}."), FText::FromString(Target.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::RespondGuildInvite)
    {
        const int32 InviteIndex = Actor.PendingGuildInvites.IndexOfByPredicate([&GuildId](const FDMFGuildInvite& Invite) { return Invite.GuildId == GuildId; });
        if (InviteIndex == INDEX_NONE)
        {
            OutMessage = NSLOCTEXT("DMF", "GuildInviteMissing", "That guild invitation is no longer available.");
            return false;
        }
        const FDMFGuildInvite Invite = Actor.PendingGuildInvites[InviteIndex];
        if (!bValue)
        {
            Actor.PendingGuildInvites.RemoveAt(InviteIndex);
            if (!Commit({Actor}, {}, {}, OutMessage)) return false;
            OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildInviteDeclined", "Invitation to {0} declined."), FText::FromString(Invite.GuildName));
            return true;
        }

        FDMFGuildRecord Guild;
        if (!Persistence->GetGuild(GuildId, Guild))
        {
            Actor.PendingGuildInvites.RemoveAt(InviteIndex);
            if (!Commit({Actor}, {}, {}, OutMessage)) return false;
            OutMessage = NSLOCTEXT("DMF", "GuildInviteDisbanded", "That guild no longer exists.");
            return false;
        }
        FDMFGuildRecord CurrentGuild;
        if (GuildExistsForAccount(Actor, CurrentGuild))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildInviteAlreadyInGuild", "Leave your current guild before accepting another invitation.");
            return false;
        }
        if (Guild.MemberUsernames.Num() >= MaxGuildMembers)
        {
            OutMessage = NSLOCTEXT("DMF", "GuildInviteGuildFull", "That guild is currently full.");
            return false;
        }

        Actor.GuildId = Guild.GuildId;
        Actor.PendingGuildInvites.Reset();
        AddUsernameUnique(Guild.MemberUsernames, Actor.Username);
        RemoveUsername(Guild.PendingApplications, Actor.Username);
        Guild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
        TArray<FDMFGuildRecord> Upserts;
        Upserts.Add(Guild);
        RemoveApplicantFromOtherGuilds(Actor.Username, Guild.GuildId, Upserts);
        if (!Commit({Actor}, Upserts, {}, OutMessage)) return false;
        PushSocialSnapshotsToAllOnlinePlayers(RequestingController);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildInviteAccepted", "You joined {0}."), FText::FromString(Guild.Name));
        return true;
    }

    if (ActionType == EDMFSocialActionType::ApplyToGuild)
    {
        FDMFGuildRecord CurrentGuild;
        if (GuildExistsForAccount(Actor, CurrentGuild))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplyAlreadyMember", "Leave your current guild before applying to another one.");
            return false;
        }
        if (Actor.GuildId.IsValid()) Actor.GuildId.Invalidate();

        FDMFGuildRecord Guild;
        if (!GuildId.IsValid() || !Persistence->GetGuild(GuildId, Guild))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplyMissing", "That guild no longer exists.");
            return false;
        }
        if (Guild.MemberUsernames.Num() >= MaxGuildMembers)
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplyFull", "That guild is currently full.");
            return false;
        }
        FDMFAccountRecord GuildOwner;
        if (!ResolveTarget(Guild.OwnerUsername, GuildOwner))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplicationOwnerUnavailable", "That guild cannot currently receive applications.");
            return false;
        }
        if (ContainsUsername(Actor.IgnoredUsernames, GuildOwner.Username) || ContainsUsername(GuildOwner.IgnoredUsernames, Actor.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplicationBlocked", "That guild application could not be delivered while either account is ignoring the other.");
            return false;
        }
        if (ContainsUsername(Guild.PendingApplications, Actor.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplicationPending", "Your application to that guild is already pending.");
            return false;
        }
        if (Guild.PendingApplications.Num() >= MaxGuildApplications)
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplicationQueueFull", "That guild's application queue is currently full.");
            return false;
        }
        Guild.PendingApplications.Add(Actor.Username);
        Guild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
        if (!Commit({Actor}, {Guild}, {}, OutMessage)) return false;
        PushSocialSnapshotForUsername(Guild.OwnerUsername);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildApplicationSent", "Application sent to {0}."), FText::FromString(Guild.Name));
        return true;
    }

    if (ActionType == EDMFSocialActionType::RespondGuildApplication)
    {
        FDMFGuildRecord Guild;
        if (!GuildExistsForAccount(Actor, Guild) || !Guild.OwnerUsername.Equals(Actor.Username, ESearchCase::IgnoreCase))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplicationOwnerOnly", "Only the guild owner can review join applications.");
            return false;
        }
        FDMFAccountRecord Applicant;
        if (!ResolveTarget(SubjectUsername, Applicant) || !ContainsUsername(Guild.PendingApplications, Applicant.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplicationMissing", "That guild application is no longer available.");
            return false;
        }

        if (!bValue)
        {
            RemoveUsername(Guild.PendingApplications, Applicant.Username);
            Guild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
            if (!Commit({}, {Guild}, {}, OutMessage)) return false;
            PushSocialSnapshotForUsername(Applicant.Username);
            OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildApplicationDeclined", "Application from {0} declined."), FText::FromString(Applicant.Username));
            return true;
        }
        if (Guild.MemberUsernames.Num() >= MaxGuildMembers)
        {
            OutMessage = NSLOCTEXT("DMF", "GuildApplicationGuildFull", "Your guild is at its configured member limit.");
            return false;
        }
        FDMFGuildRecord ApplicantGuild;
        if (GuildExistsForAccount(Applicant, ApplicantGuild))
        {
            RemoveUsername(Guild.PendingApplications, Applicant.Username);
            Guild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
            if (!Commit({}, {Guild}, {}, OutMessage)) return false;
            PushSocialSnapshotForUsername(Applicant.Username);
            OutMessage = NSLOCTEXT("DMF", "GuildApplicationJoinedElsewhere", "That player has already joined another guild; the stale application was removed.");
            return false;
        }

        Applicant.GuildId = Guild.GuildId;
        Applicant.PendingGuildInvites.Reset();
        AddUsernameUnique(Guild.MemberUsernames, Applicant.Username);
        RemoveUsername(Guild.PendingApplications, Applicant.Username);
        Guild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
        TArray<FDMFGuildRecord> Upserts;
        Upserts.Add(Guild);
        RemoveApplicantFromOtherGuilds(Applicant.Username, Guild.GuildId, Upserts);
        if (!Commit({Applicant}, Upserts, {}, OutMessage)) return false;
        PushSocialSnapshotsToAllOnlinePlayers(RequestingController);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildApplicationAccepted", "{0} joined the guild."), FText::FromString(Applicant.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::RemoveGuildMember)
    {
        FDMFGuildRecord Guild;
        if (!GuildExistsForAccount(Actor, Guild) || !Guild.OwnerUsername.Equals(Actor.Username, ESearchCase::IgnoreCase))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildRemoveOwnerOnly", "Only the guild owner can remove members.");
            return false;
        }
        FDMFAccountRecord Member;
        if (!ResolveTarget(SubjectUsername, Member) || Member.Username.Equals(Actor.Username, ESearchCase::IgnoreCase) || !ContainsUsername(Guild.MemberUsernames, Member.Username))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildRemoveInvalidMember", "That guild member cannot be removed.");
            return false;
        }
        RemoveUsername(Guild.MemberUsernames, Member.Username);
        if (Member.GuildId == Guild.GuildId) Member.GuildId.Invalidate();
        Guild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
        if (!Commit({Member}, {Guild}, {}, OutMessage)) return false;
        PushSocialSnapshotsToAllOnlinePlayers(RequestingController);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildMemberRemoved", "{0} was removed from the guild."), FText::FromString(Member.Username));
        return true;
    }

    if (ActionType == EDMFSocialActionType::LeaveGuild)
    {
        FDMFGuildRecord Guild;
        if (!GuildExistsForAccount(Actor, Guild))
        {
            if (Actor.GuildId.IsValid())
            {
                Actor.GuildId.Invalidate();
                if (!Commit({Actor}, {}, {}, OutMessage)) return false;
            }
            OutMessage = NSLOCTEXT("DMF", "GuildLeaveNotMember", "You are not currently in a guild.");
            return false;
        }
        if (Guild.OwnerUsername.Equals(Actor.Username, ESearchCase::IgnoreCase))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildOwnerLeave", "Guild owners must disband the guild instead of leaving it.");
            return false;
        }
        RemoveUsername(Guild.MemberUsernames, Actor.Username);
        Actor.GuildId.Invalidate();
        Guild.LastModifiedUtcTicks = FDateTime::UtcNow().GetTicks();
        if (!Commit({Actor}, {Guild}, {}, OutMessage)) return false;
        PushSocialSnapshotsToAllOnlinePlayers(RequestingController);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildLeft", "You left {0}."), FText::FromString(Guild.Name));
        return true;
    }

    if (ActionType == EDMFSocialActionType::DisbandGuild)
    {
        FDMFGuildRecord Guild;
        if (!GuildExistsForAccount(Actor, Guild) || !Guild.OwnerUsername.Equals(Actor.Username, ESearchCase::IgnoreCase))
        {
            OutMessage = NSLOCTEXT("DMF", "GuildDisbandOwnerOnly", "Only the guild owner can disband the guild.");
            return false;
        }

        TArray<FDMFAccountRecord> AllAccounts;
        Persistence->GetAllAccounts(AllAccounts);
        TArray<FDMFAccountRecord> ChangedAccounts;
        for (FDMFAccountRecord& Account : AllAccounts)
        {
            bool bChanged = false;
            if (Account.GuildId == Guild.GuildId)
            {
                Account.GuildId.Invalidate();
                bChanged = true;
            }
            const int32 RemovedInvites = Account.PendingGuildInvites.RemoveAll([&Guild](const FDMFGuildInvite& Invite)
            {
                return Invite.GuildId == Guild.GuildId;
            });
            bChanged |= RemovedInvites > 0;
            if (bChanged)
            {
                ChangedAccounts.Add(Account);
            }
        }
        if (!Commit(ChangedAccounts, {}, {Guild.GuildId}, OutMessage)) return false;
        PushSocialSnapshotsToAllOnlinePlayers(RequestingController);
        OutMessage = FText::Format(NSLOCTEXT("DMF", "GuildDisbanded", "Guild {0} was disbanded."), FText::FromString(Guild.Name));
        return true;
    }

    OutMessage = NSLOCTEXT("DMF", "SocialUnknownAction", "The requested Social action is not supported.");
    return false;
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

    // PostLogin is Unreal's first authoritative point at which it is safe to address the owning PlayerController.
    // Announce only after DMF account integrity has been restored so reconnects always use the authenticated username.
    if (ADMFMMOPlayerController* MMOController = Cast<ADMFMMOPlayerController>(NewPlayer))
    {
        BroadcastWorldChatPresenceEvent(MMOController, EDMFWorldChatMessageType::PlayerJoined);
        if (const ADMFPlayerState* SocialPlayerState = MMOController->GetPlayerState<ADMFPlayerState>())
        {
            RefreshSocialPresenceForUsername(SocialPlayerState->GetAuthenticatedUsername());
        }
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
    FString DepartingUsername;
    if (APlayerController* PC = Cast<APlayerController>(Exiting))
    {
        if (const ADMFPlayerState* DepartingState = PC->GetPlayerState<ADMFPlayerState>())
        {
            DepartingUsername = DepartingState->GetAuthenticatedUsername();
        }

        // Canonical disconnect transaction MUST happen before Super::Logout, because Unreal may detach/retain
        // PlayerState/Pawn objects as part of the inactive-player lifecycle after this point.
        FinalizeAuthenticatedPlayerSession(PC);

        // Broadcast while the authenticated PlayerState still exists. Remaining peers receive the reliable event
        // before Unreal removes this controller from the authoritative world/controller list.
        if (ADMFMMOPlayerController* MMOController = Cast<ADMFMMOPlayerController>(PC))
        {
            BroadcastWorldChatPresenceEvent(MMOController, EDMFWorldChatMessageType::PlayerLeft);
        }
    }

    Super::Logout(Exiting);

    // Refresh after Super so friends/guildmates resolve the departed account as genuinely offline rather than
    // observing the still-present controller during the final teardown frame.
    if (!DepartingUsername.TrimStartAndEnd().IsEmpty())
    {
        RefreshSocialPresenceForUsername(DepartingUsername);
    }
}
