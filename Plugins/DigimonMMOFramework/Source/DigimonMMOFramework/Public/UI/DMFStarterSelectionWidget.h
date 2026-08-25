#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/PrimaryAssetId.h"
#include "DMFStarterSelectionWidget.generated.h"

class UVerticalBox;
class UUniformGridPanel;
class UTextBlock;
class UButton;
class UImage;
class UDMFDigimonSpeciesData;

/** Polished native starter selector with portrait cards and selected-species inspection. */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFStarterSelectionWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Starter")
    FPrimaryAssetId GetSelectedStarterSpeciesId() const { return SelectedSpeciesId; }

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Starter")
    void BP_OnStarterPreviewChanged(UDMFDigimonSpeciesData* Species);

protected:
    /** Legacy/custom Blueprint list binding. Native fallback uses ChoicesGrid. */
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UVerticalBox> ChoicesBox;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> ChoicesGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DetailsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedStarterNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedStarterMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> StarterStatusText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> SelectedStarterPortrait;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> ConfirmButton;

private:
    FPrimaryAssetId SelectedSpeciesId;

    UFUNCTION()
    void HandleStarterPressed(FPrimaryAssetId SpeciesId);

    UFUNCTION()
    void HandleConfirm();

    UFUNCTION()
    void HandleStarterSelectionResult(bool bSuccess, FText Message, FGuid PartnerInstanceId);

    void BuildNativeFallbackUI();
    void PopulateChoices();
    UDMFDigimonSpeciesData* ResolveSpecies(FPrimaryAssetId SpeciesId) const;
    FText ResolveSelectionBlurb(FPrimaryAssetId SpeciesId) const;
};
