#include "UI/DMFSocialActionButton.h"

void UDMFSocialActionButton::InitializeSocialAction(const EDMFSocialUIAction InAction, const FString& InUsername, const FGuid& InGuildId, const bool bInValue)
{
    SocialAction = InAction;
    SubjectUsername = InUsername;
    SubjectGuildId = InGuildId;
    bValue = bInValue;
    OnClicked.RemoveDynamic(this, &UDMFSocialActionButton::HandleClicked);
    OnClicked.AddDynamic(this, &UDMFSocialActionButton::HandleClicked);
}

void UDMFSocialActionButton::HandleClicked()
{
    OnSocialActionPressed.Broadcast(this);
}
