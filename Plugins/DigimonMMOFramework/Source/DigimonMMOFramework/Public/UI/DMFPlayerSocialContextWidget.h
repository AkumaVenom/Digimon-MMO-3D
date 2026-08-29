#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMFPlayerSocialContextWidget.generated.h"

class UButton;
class UTextBlock;
class ADMFPlayerAvatarCharacter;

/**
 * Owner-local dropdown opened by clicking an exact replicated player nameplate. It never mutates social
 * state directly: each action is routed through the owning PlayerController's validated server RPC.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFPlayerSocialContextWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Nameplate Context")
    void SetTargetPlayer(ADMFPlayerAvatarCharacter* InTargetPlayer);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Social|Nameplate Context")
    FString GetTargetUsername() const { return TargetUsername; }

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Nameplate Context")
    void RefreshActions();

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> TargetNameText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> RelationshipText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> FriendActionButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> FriendActionText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> IgnoreActionButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> IgnoreActionText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> GuildInviteButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> CloseButton;

private:
    TWeakObjectPtr<ADMFPlayerAvatarCharacter> TargetPlayer;
    FString TargetUsername;
    bool bTargetIsFriend = false;
    bool bTargetHasInboundFriendRequest = false;
    bool bTargetHasOutboundFriendRequest = false;
    bool bTargetIsIgnored = false;

    void BuildNativeFallbackUI();

    UFUNCTION() void HandleFriendAction();
    UFUNCTION() void HandleIgnoreAction();
    UFUNCTION() void HandleGuildInvite();
    UFUNCTION() void HandleClose();
};
