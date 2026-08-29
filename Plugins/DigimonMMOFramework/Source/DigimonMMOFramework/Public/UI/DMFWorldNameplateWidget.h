#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMFWorldNameplateWidget.generated.h"

class UBorder;
class UProgressBar;
class UTextBlock;
class UVerticalBox;
class AActor;

/**
 * Compact native world-space MMO nameplate used by both player avatars and Digimon.
 *
 * The widget is presentation-only. It reads already replicated actor/PlayerState/combat state and
 * never owns authority or sends network traffic. Blueprint children may completely reskin the
 * BindWidgetOptional surface while preserving the framework's actor-side attachment/visibility rules.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFWorldNameplateWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI|World Nameplates")
    void SetObservedActor(AActor* InObservedActor);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI|World Nameplates")
    void RefreshPresentation();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|UI|World Nameplates")
    AActor* GetObservedActor() const { return ObservedActor.Get(); }

    /** Called after the native fallback has refreshed its presentation. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|UI|World Nameplates")
    void BP_OnNameplateRefreshed(AActor* InObservedActor);

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UBorder> NameplatePanel;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> NameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> MetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UVerticalBox> DigimonVitalsBox;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> HealthProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> HealthText;

private:
    UPROPERTY(Transient)
    TObjectPtr<AActor> ObservedActor;

    float RefreshAccumulator = 0.0f;

    void BuildNativeFallbackUI();
    void RefreshPlayerPresentation();
    void RefreshDigimonPresentation();
};
