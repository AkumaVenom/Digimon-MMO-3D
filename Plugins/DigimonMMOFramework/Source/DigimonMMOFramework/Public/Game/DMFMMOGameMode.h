#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DMFMMOGameMode.generated.h"

class ADMFPlayerAvatarCharacter;

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
    virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
    virtual void Logout(AController* Exiting) override;

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

protected:
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Account")
    void BP_OnPlayerAccountLoaded(APlayerController* PlayerController, const FString& Username, bool bNewAccount);

    /** Presentation/diagnostic hook fired after an invalid or missing pawn was recovered. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Networking|Player Spawn")
    void BP_OnFrameworkPlayerAvatarRecovered(APlayerController* PlayerController, ADMFPlayerAvatarCharacter* AvatarPawn);

private:
    bool ValidateCredentialsFromOptions(const FString& Options, FString& OutUsername, FString& OutCredentialDigest, bool& bOutCreatedNew, FString& OutError) const;
    UClass* ResolveFrameworkPlayerAvatarClass() const;
    void ScheduleFrameworkPlayerAvatarValidation(APlayerController* PlayerController);
    void SavePlayerState(class ADMFPlayerState* PlayerState) const;
};
