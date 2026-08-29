#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "DMFSocialActionButton.generated.h"

class UDMFSocialActionButton;

UENUM(BlueprintType)
enum class EDMFSocialUIAction : uint8
{
    FriendAccept,
    FriendDecline,
    FriendCancel,
    FriendRemove,
    FriendTrackToggle,
    IgnoreRemove,
    GuildInviteAccept,
    GuildInviteDecline,
    GuildApply,
    GuildApplicationAccept,
    GuildApplicationDecline,
    GuildRemoveMember,
    /** Appended for v0.19.1 nearby-player discovery; existing UI action ordinals remain unchanged. */
    FriendAdd,
    /** Appended for v0.19.2 nearby-player Ignore action; all prior UI action ordinals remain unchanged. */
    IgnoreAdd
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFSocialActionButtonPressed, UDMFSocialActionButton*, Button);

/** Tiny native payload button used by dynamic Social lists without storing authority inside the UI. */
UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFSocialActionButton : public UButton
{
    GENERATED_BODY()

public:
    void InitializeSocialAction(EDMFSocialUIAction InAction, const FString& InUsername, const FGuid& InGuildId = FGuid(), bool bInValue = false);

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Social")
    EDMFSocialUIAction SocialAction = EDMFSocialUIAction::FriendAccept;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Social")
    FString SubjectUsername;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Social")
    FGuid SubjectGuildId;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Social")
    bool bValue = false;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Social")
    FDMFSocialActionButtonPressed OnSocialActionPressed;

private:
    UFUNCTION()
    void HandleClicked();
};
