#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMFFriendTrackerWidget.generated.h"

class UBorder;
class UTextBlock;
class ADMFPlayerAvatarCharacter;

/**
 * Owner-local world-space friend marker. It reads already replicated avatar transforms and therefore
 * requires no distance RPC/tick replication. The persistent toggle lives in the authenticated account.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFFriendTrackerWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Friend Tracking")
    void SetObservedFriend(ADMFPlayerAvatarCharacter* InFriendAvatar);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Social|Friend Tracking")
    ADMFPlayerAvatarCharacter* GetObservedFriend() const { return ObservedFriend.Get(); }

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Social|Friend Tracking")
    void BP_OnFriendTrackerRefreshed(ADMFPlayerAvatarCharacter* FriendAvatar, int32 DistanceMeters);

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UBorder> TrackerPanel;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> FriendNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DistanceText;

private:
    TWeakObjectPtr<ADMFPlayerAvatarCharacter> ObservedFriend;
    float RefreshAccumulator = 0.0f;

    void BuildNativeFallbackUI();
    void RefreshTracker();
};
