#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/PrimaryAssetId.h"
#include "DMFPlayerSkinSelectionWidget.generated.h"

class UVerticalBox;
class UUniformGridPanel;
class UTextBlock;
class UButton;
class UImage;
class UDMFPlayerSkinData;

/** Polished native character-skin selector with portrait cards and selected-skin inspection. */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFPlayerSkinSelectionWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar")
    FPrimaryAssetId GetPreviewedPlayerSkinId() const { return PreviewedSkinId; }

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar")
    void RefreshAvailablePlayerSkins();

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Player Avatar")
    void BP_OnPlayerSkinPreviewChanged(UDMFPlayerSkinData* SkinData);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Player Avatar")
    void BP_OnPlayerSkinSelectionResult(bool bSuccess, const FText& Message, UDMFPlayerSkinData* SkinData);

protected:
    /** Legacy/custom Blueprint list binding. Native fallback uses PlayerSkinChoicesGrid. */
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UVerticalBox> PlayerSkinChoicesBox;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> PlayerSkinChoicesGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> PlayerSkinDetailsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> PlayerSkinStatusText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> PreviewedSkinNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> PreviewedSkinPortrait;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> ApplyPlayerSkinButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> ClosePlayerSkinButton;

private:
    FPrimaryAssetId PreviewedSkinId;

    UFUNCTION()
    void HandlePlayerSkinPressed(FPrimaryAssetId SkinId);

    UFUNCTION()
    void HandleApplyPlayerSkin();

    UFUNCTION()
    void HandleClosePlayerSkin();

    UFUNCTION()
    void HandlePlayerSkinSelectionResult(bool bSuccess, FText Message, FPrimaryAssetId SkinId);

    void BuildNativeFallbackUI();
    UDMFPlayerSkinData* ResolveSkin(FPrimaryAssetId SkinId) const;
};
