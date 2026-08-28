#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMFTypes.h"
#include "DMFExperienceNotificationWidget.generated.h"

class UTextBlock;
class UImage;
class UProgressBar;
class UDMFDigimonSpeciesData;

/**
 * Owner-only transient EXP/level-up presentation. The server supplies an immutable progression
 * snapshot; this widget only animates that already-authoritative result locally.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFExperienceNotificationWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeDestruct() override;

    /** Queues one authoritative EXP result. Rapid rewards are serialized so no level-up toast is lost. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Progression")
    void ShowExperienceProgress(const FDMFDigimonExperienceProgression& Progression);

    /** Blueprint reskin hook fired when a queued progression result begins presentation. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Progression")
    void BP_OnExperienceProgressPresented(FDMFDigimonExperienceProgression Progression);

    /** Separate hook for projects that want a larger level-up burst/animation. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Progression")
    void BP_OnLevelUpPresented(FDMFDigimonExperienceProgression Progression);

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> SpeciesPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SpeciesNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ExperienceGainText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> LevelText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ExperienceProgressText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> ExperienceProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> LevelUpText;

private:
    TArray<FDMFDigimonExperienceProgression> PendingPresentations;
    FDMFDigimonExperienceProgression ActiveProgression;
    FTimerHandle AnimationTimer;
    FTimerHandle HideTimer;
    double AnimationStartTimeSeconds = 0.0;
    float AnimationDurationSeconds = 1.10f;
    bool bPresentationActive = false;
    bool bLevelUpEventFired = false;

    void BuildNativeFallbackUI();
    void BeginNextPresentation();
    void UpdateProgressAnimation();
    void FinishCurrentPresentation();
    void ApplyAnimatedProgress(float Alpha);
    UDMFDigimonSpeciesData* ResolveSpecies(FPrimaryAssetId SpeciesId) const;
    int64 ResolveExperienceRequirement(const UDMFDigimonSpeciesData* Species, int32 CurrentLevel) const;
    int32 ResolveMaximumLevel(const UDMFDigimonSpeciesData* Species) const;
};
