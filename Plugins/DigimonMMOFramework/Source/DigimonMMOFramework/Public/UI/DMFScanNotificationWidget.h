#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/PrimaryAssetId.h"
#include "DMFScanNotificationWidget.generated.h"

class UTextBlock;
class UImage;
class UProgressBar;
class UDMFDigimonSpeciesData;

/** Polished transient Scan Data reward toast shown to the owning player only. */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFScanNotificationWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual TSharedRef<SWidget> RebuildWidget() override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Scan & Materialization")
    void ShowScanReward(FPrimaryAssetId SpeciesId, float AddedPercent, float NewPercent, bool bMaterializationReady);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Scan & Materialization")
    void BP_OnScanRewardPresented(FPrimaryAssetId SpeciesId, float AddedPercent, float NewPercent, bool bMaterializationReady);

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UImage> SpeciesPortraitImage;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> SpeciesNameText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> RewardText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> ReadyText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UProgressBar> ScanProgressBar;

private:
    FTimerHandle HideTimer;
    void BuildNativeFallbackUI();
    UDMFDigimonSpeciesData* ResolveSpecies(FPrimaryAssetId SpeciesId) const;
    void HideToast();
};
