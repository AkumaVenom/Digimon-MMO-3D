#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Game/DMFItemVendorActor.h"
#include "DMFItemVendorWidget.generated.h"

class UImage;
class UTextBlock;
class UVerticalBox;
class UHorizontalBox;
class ADMFMMOPlayerController;
class UDMFPlayerDigimonComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFItemVendorEntryPressed, EDMFItemVendorTransactionType, TransactionType, FGuid, StockId, FPrimaryAssetId, ItemAssetId);

/** Native list button carrying only selection identity; prices and quantities are never trusted from this widget. */
UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFItemVendorEntryButton : public UButton
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Item Vendor") FDMFItemVendorEntryPressed OnItemVendorEntryPressed;
    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Item Vendor") EDMFItemVendorTransactionType TransactionType = EDMFItemVendorTransactionType::Buy;
    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Item Vendor") FGuid StockId;
    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Item Vendor") FPrimaryAssetId ItemAssetId;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Item Vendor")
    void InitializeItemVendorEntry(EDMFItemVendorTransactionType InTransactionType, FGuid InStockId, FPrimaryAssetId InItemAssetId);

private:
    UFUNCTION() void HandlePressed();
};

/** Polished native BUY/SELL item exchange with shared stock and quantity-aware atomic transactions. */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFItemVendorWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Item Vendor") void InitializeVendor(ADMFItemVendorActor* InVendor);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Item Vendor") void RefreshVendorUI();
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Item Vendor") void SetVendorTab(EDMFItemVendorTransactionType NewTab);
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Item Vendor") ADMFItemVendorActor* GetVendor() const { return Vendor.Get(); }
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Item Vendor") EDMFItemVendorTransactionType GetVendorTab() const { return CurrentTab; }
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Item Vendor") int32 GetSelectedQuantity() const { return SelectedQuantity; }

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Item Vendor") void BP_OnVendorRefreshed();
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Item Vendor") void BP_OnVendorSelectionChanged(EDMFItemVendorTransactionType TransactionType, FGuid StockId, FPrimaryAssetId ItemAssetId);
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Item Vendor") void BP_OnVendorQuantityChanged(int32 Quantity);

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> VendorNameText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> VendorSubtitleText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> MoneyText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> RotationText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> BuyTabButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SellTabButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> EntryListBox;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UImage> DetailIcon;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> DetailNameText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> DetailMetaText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> DetailDescriptionText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> DetailInventoryText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> DetailPriceText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> QuantityText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> QuantityMinusTenButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> QuantityMinusOneButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> QuantityPlusOneButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> QuantityPlusTenButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> QuantityMaxButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> VendorStatusText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> TransactionButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> TransactionButtonText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> CloseButton;

private:
    TWeakObjectPtr<ADMFItemVendorActor> Vendor;
    TWeakObjectPtr<UDMFPlayerDigimonComponent> DigimonComponent;
    EDMFItemVendorTransactionType CurrentTab = EDMFItemVendorTransactionType::Buy;
    FGuid SelectedStockId;
    FPrimaryAssetId SelectedItemAssetId;
    int32 SelectedQuantity = 1;
    bool bTransactionConfirmationArmed = false;
    EDMFItemVendorTransactionType ConfirmationTransactionType = EDMFItemVendorTransactionType::Buy;
    FGuid ConfirmationStockId;
    FPrimaryAssetId ConfirmationItemAssetId;
    int32 ConfirmationQuantity = 0;
    FTimerHandle HeaderRefreshTimer;

    void BuildNativeFallbackUI();
    void RebindSources();
    void RefreshEntryList();
    void RefreshDetails();
    void RefreshHeader();
    void ResetTransactionConfirmation();
    void SetSelectedQuantityClamped(int32 NewQuantity);
    int32 GetMaximumSelectableQuantity() const;
    bool ResolveSelectedItem(class UDMFItemData*& OutItem, int64& OutUnitPrice, int32& OutAvailableQuantity, FText& OutBlockReason) const;

    UFUNCTION() void HandleBuyTabClicked();
    UFUNCTION() void HandleSellTabClicked();
    UFUNCTION() void HandleEntryPressed(EDMFItemVendorTransactionType TransactionType, FGuid StockId, FPrimaryAssetId ItemAssetId);
    UFUNCTION() void HandleQuantityMinusTen();
    UFUNCTION() void HandleQuantityMinusOne();
    UFUNCTION() void HandleQuantityPlusOne();
    UFUNCTION() void HandleQuantityPlusTen();
    UFUNCTION() void HandleQuantityMax();
    UFUNCTION() void HandleTransactionClicked();
    UFUNCTION() void HandleCloseClicked();
    UFUNCTION() void HandleVendorStockChanged();
    UFUNCTION() void HandleVendorEnabledChanged(bool bEnabled);
    UFUNCTION() void HandleVendorConfigurationChanged();
    UFUNCTION() void HandleItemInventoryChanged();
    UFUNCTION() void HandleMoneyChanged(int64 NewMoney);
    UFUNCTION() void HandleVendorTransactionResult(bool bSuccess, FText Message, EDMFItemVendorTransactionType TransactionType, FPrimaryAssetId ItemAssetId, int32 Quantity, int64 TotalPrice, int64 NewMoney);
    UFUNCTION() void HandleHeaderTimer();
};
