#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMFTypes.h"
#include "DMFDigimonInventoryWidget.generated.h"

class UVerticalBox;
class UUniformGridPanel;
class UTextBlock;
class UButton;
class UImage;
class UHorizontalBox;
class UProgressBar;
class UDMFPlayerDigimonComponent;
class UDMFDigimonSpeciesData;
class UDMFPartyDestinationButton;

/**
 * Polished native Digimon roster/partner menu.
 * The framework fallback is a portrait-slot grid with a selected Digimon inspection panel,
 * summon/recall actions, status badges and account-owned replicated data. Blueprint children
 * may replace the presentation without replacing server authority.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFDigimonInventoryWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Inventory")
    void RefreshInventory();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Bank")
    void RefreshBankData();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Scan & Materialization")
    void RefreshScanData();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Care")
    void RefreshCareData();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI")
    void SetActiveMenuTab(EDMFDigimonMenuTab NewTab);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|UI")
    EDMFDigimonMenuTab GetActiveMenuTab() const { return ActiveMenuTab; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Inventory")
    FGuid GetSelectedDigimonInstanceId() const { return SelectedInstanceId; }

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Inventory")
    void BP_OnDigimonPreviewChanged(FDMFDigimonInstance Digimon, UDMFDigimonSpeciesData* Species);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Inventory")
    void BP_OnPartnerActionResult(bool bSuccess, const FText& Message, FGuid PartnerInstanceId);

protected:
    /** Legacy/custom Blueprint list binding. Native fallback uses DigimonGrid. */
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UVerticalBox> DigimonChoicesBox;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> DigimonGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigimonDetailsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigimonStatusText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> InventoryCountText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedStageText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedStateText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedDescriptionText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> SelectedPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> SummonDigimonButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> RecallDigimonButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> MoveSelectedToBankButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> CloseDigimonInventoryButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> CollectionTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> BankTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> ScanMaterializeTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> CareTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> BankDigimonGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankCountText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankPageText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankSelectionText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> BankSelectedPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankSelectedNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankSelectedMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankSelectedStatsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> BankPartyDestinationGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> BankPreviousPageButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> BankNextPageButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> MoveSelectedBankToPartyButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> ScanSpeciesGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanDatabaseCountText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> ScanSelectedPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedProgressText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> ScanSelectedProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedDetailsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedDescriptionText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> MaterializeDigimonButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> CarePortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareHungerText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> CareHungerProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> CareHappinessProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> CareDisciplineProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareStatisticsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareWasteStatusText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareFeedingRulesText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> FeedDigiMeatButton;

private:
    UPROPERTY(Transient)
    TObjectPtr<UDMFPlayerDigimonComponent> BoundDigimonComponent;

    FGuid SelectedInstanceId;
    FGuid SelectedBankInstanceId;
    FGuid PendingStorageSelectionId;
    FPrimaryAssetId SelectedScanSpeciesId;
    int32 BankPageIndex = 0;
    int32 SelectedBankPartyDestinationIndex = INDEX_NONE;
    EDMFDigimonMenuTab ActiveMenuTab = EDMFDigimonMenuTab::Collection;

    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> InventoryContentRow;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> BankContentRow;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> ScanContentRow;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> CareContentRow;

    void BuildNativeFallbackUI();
    void BindDigimonComponent();
    void RefreshSelectedDetails();
    void RefreshSelectedBankDetails();
    void RefreshSelectedScanDetails();
    void RefreshTabPresentation();
    UDMFDigimonSpeciesData* ResolveSpecies(FPrimaryAssetId SpeciesId) const;

    UFUNCTION()
    void HandleInventoryChanged();

    UFUNCTION()
    void HandleBankChanged();

    UFUNCTION()
    void HandleStorageActionResult(bool bSuccess, FText Message, FGuid DigimonInstanceId, EDMFDigimonStorageLocation NewLocation);

    UFUNCTION()
    void HandleScanDataChanged(FPrimaryAssetId SpeciesId, float ScanPercent, bool bMaterializationReady);

    UFUNCTION()
    void HandleMaterializationResult(bool bSuccess, FText Message, FPrimaryAssetId SpeciesId, FGuid NewDigimonInstanceId);

    UFUNCTION()
    void HandleCollectionTab();

    UFUNCTION()
    void HandleBankTab();

    UFUNCTION()
    void HandleScanMaterializeTab();

    UFUNCTION()
    void HandleCareTab();

    UFUNCTION()
    void HandleFeedDigiMeat();

    UFUNCTION()
    void HandleCareStateChanged(FGuid DigimonInstanceId, FDMFDigimonCareState CareState);

    UFUNCTION()
    void HandleCareSequenceFinished(bool bSuccess, FText Message, FGuid DigimonInstanceId);

    UFUNCTION()
    void HandleScanSpeciesPressed(FPrimaryAssetId SpeciesId);

    UFUNCTION()
    void HandleMaterializeSelected();

    UFUNCTION()
    void HandleBankDigimonPressed(FGuid InstanceId);

    UFUNCTION()
    void HandleBankPartyDestinationPressed(int32 PartySlotIndex);

    UFUNCTION()
    void HandleMoveSelectedToBank();

    UFUNCTION()
    void HandleMoveSelectedBankToParty();

    UFUNCTION()
    void HandleBankPreviousPage();

    UFUNCTION()
    void HandleBankNextPage();

    UFUNCTION()
    void HandleDigimonPressed(FGuid InstanceId);

    UFUNCTION()
    void HandleSummonSelected();

    UFUNCTION()
    void HandleRecallPartner();

    UFUNCTION()
    void HandleClose();

    UFUNCTION()
    void HandlePartnerActionResult(bool bSuccess, FText Message, FGuid PartnerInstanceId);
};
