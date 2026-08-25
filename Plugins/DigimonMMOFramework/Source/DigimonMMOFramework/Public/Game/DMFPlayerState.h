#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DMFPlayerState.generated.h"

class UDMFPlayerDigimonComponent;
class UDMFPlayerAvatarComponent;

UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    ADMFPlayerState();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO")
    TObjectPtr<UDMFPlayerDigimonComponent> DigimonComponent;

    /** Server-authoritative persistent player character skin selection. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Player Avatar")
    TObjectPtr<UDMFPlayerAvatarComponent> AvatarComponent;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Account")
    FString GetAuthenticatedUsername() const { return AuthenticatedUsername; }

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Account")
    void SetAuthenticatedAccount(const FString& Username, const FString& CredentialDigest);

    const FString& GetCredentialDigestServerOnly() const { return CredentialDigestServerOnly; }

private:
    UPROPERTY(Replicated)
    FString AuthenticatedUsername;

    FString CredentialDigestServerOnly;
};
