#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Game/DMFNewPlayerStart.h"
#include "DMFTypes.h"
#include "DMFMMOGameMode.generated.h"

class ADMFPlayerAvatarCharacter;
class ADMFMMOPlayerController;

UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFMMOGameMode : public AGameMode
{
    GENERATED_BODY()

public:
    ADMFMMOGameMode();

    virtual void StartPlay() override;
    virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
    virtual FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal) override;
    virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;
    virtual void PostLogin(APlayerController* NewPlayer) override;
    virtual void AddInactivePlayer(APlayerState* PlayerState, APlayerController* PC) override;
    virtual bool FindInactivePlayer(APlayerController* PC) override;
    virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
    virtual void Logout(AController* Exiting) override;

    /**
     * Idempotent server-side disconnect finalization used by Logout and the PlayerController teardown fallback.
     * Commits the fully initialized account before transient owner/pawn state can disappear, then removes the
     * summoned partner actor so disconnected players never leave an orphaned Digimon in the world.
     */
    bool FinalizeAuthenticatedPlayerSession(APlayerController* PlayerController);

    /**
     * Server-authoritative recovery/validation hook for late-joining players. Ensures the controller owns
     * a DMF player-avatar pawn, force-resynchronizes possession to the owning client, reapplies the
     * account skin, and restores the active partner when onboarding allows it.
     */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Networking|Player Spawn")
    bool EnsureFrameworkPlayerAvatar(APlayerController* PlayerController);

    /** Returns true when the controller currently owns a valid framework player-avatar pawn. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Networking|Player Spawn")
    bool HasFrameworkPlayerAvatar(APlayerController* PlayerController) const;

    /**
     * Chooses the dedicated first-login spawn actor for an account with no saved gameplay location.
     * Native behavior picks the enabled DMFNewPlayerStart with the highest priority. Projects may override in Blueprint.
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Persistence|Player World Location")
    ADMFNewPlayerStart* ChooseNewPlayerSpawnPoint(APlayerController* PlayerController) const;

    /** Saves only the controller's current authoritative gameplay location into its existing account record. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Persistence|Player World Location")
    bool SaveAuthenticatedPlayerWorldLocationNow(APlayerController* PlayerController) const;


    /**
     * Resolves the configured DMFNewPlayerStart on authority and safely returns an authenticated player to it.
     * The client supplies no transform. Summoned partner combat is disengaged/repositioned and the new location is checkpointed immediately.
     */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Persistence|Player World Location|Home")
    bool ReturnAuthenticatedPlayerHome(APlayerController* PlayerController, FText& OutMessage) const;

    /** Broadcasts an already-sanitized player message using server-authored identity/timestamp metadata. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|World Chat")
    bool BroadcastWorldChatMessage(ADMFMMOPlayerController* SenderController, const FString& SanitizedMessage);

    /** Sends the bounded authoritative session history to one owning player controller. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|World Chat")
    void SendRecentWorldChatHistory(ADMFMMOPlayerController* RecipientController) const;

protected:
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Account")
    void BP_OnPlayerAccountLoaded(APlayerController* PlayerController, const FString& Username, bool bNewAccount);

    /** Presentation/diagnostic hook fired after an invalid or missing pawn was recovered. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Networking|Player Spawn")
    void BP_OnFrameworkPlayerAvatarRecovered(APlayerController* PlayerController, ADMFPlayerAvatarCharacter* AvatarPawn);

    /** Presentation/analytics hook after the server has resolved this login's initial gameplay transform. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Persistence|Player World Location")
    void BP_OnInitialPlayerWorldLocationApplied(APlayerController* PlayerController, bool bRestoredSavedLocation, bool bFirstLocationCheckpoint, FVector Location, FRotator Rotation);

    /** Server-side hook for logging, analytics or future backend/channel integrations after a world-chat message has been accepted. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|World Chat")
    void BP_OnWorldChatMessageAccepted(const FDMFWorldChatMessage& ChatMessage, ADMFMMOPlayerController* SenderController);

private:
    bool ValidateCredentialsFromOptions(const FString& Options, FString& OutUsername, FString& OutCredentialDigest, bool& bOutCreatedNew, FString& OutError) const;
    bool RehydrateAuthenticatedPlayerState(APlayerController* PlayerController, const TCHAR* Context) const;
    UClass* ResolveFrameworkPlayerAvatarClass() const;
    void ScheduleFrameworkPlayerAvatarValidation(APlayerController* PlayerController);
    bool ApplyInitialPlayerWorldLocation(APlayerController* PlayerController);
    bool ResolveInitialPlayerWorldTransform(APlayerController* PlayerController, FTransform& OutTransform, bool& bOutHasCustomTransform, bool& bOutRestoredSavedLocation, bool& bOutFirstLocationCheckpoint) const;
    bool SavePlayerState(class ADMFPlayerState* PlayerState) const;

    TSet<TWeakObjectPtr<APlayerController>> InitialWorldLocationApplied;

    UPROPERTY(Transient)
    TArray<FDMFWorldChatMessage> RecentWorldChatMessages;
};
