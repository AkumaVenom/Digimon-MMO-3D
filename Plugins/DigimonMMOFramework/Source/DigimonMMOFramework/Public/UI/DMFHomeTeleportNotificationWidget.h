#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMFHomeTeleportNotificationWidget.generated.h"

class UTextBlock;

/** Owner-only transient result toast for the server-authoritative Return Home action. */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFHomeTeleportNotificationWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party Quick Access|Home")
    void ShowHomeTeleportResult(bool bSuccess, const FText& Message);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Party Quick Access|Home")
    void BP_OnHomeTeleportResultPresented(bool bSuccess, const FText& Message);

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> HomeTitleText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> HomeMessageText;

private:
    FTimerHandle HideTimer;
    void BuildNativeFallbackUI();
    void HideToast();
};
