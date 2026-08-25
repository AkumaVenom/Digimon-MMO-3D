#include "Game/DMFPlayerState.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "Net/UnrealNetwork.h"

ADMFPlayerState::ADMFPlayerState()
{
    DigimonComponent = CreateDefaultSubobject<UDMFPlayerDigimonComponent>(TEXT("DigimonComponent"));
    AvatarComponent = CreateDefaultSubobject<UDMFPlayerAvatarComponent>(TEXT("AvatarComponent"));
}

void ADMFPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME_CONDITION(ADMFPlayerState, AuthenticatedUsername, COND_OwnerOnly);
}

void ADMFPlayerState::SetAuthenticatedAccount(const FString& Username, const FString& CredentialDigest)
{
    if (!HasAuthority())
    {
        return;
    }

    AuthenticatedUsername = Username;
    CredentialDigestServerOnly = CredentialDigest;
}
