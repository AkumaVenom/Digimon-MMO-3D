#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Game/DMFDigimonVendorActor.h"
#include "DMFDigimonVendorWidget.generated.h"

class UImage;
class UTextBlock;
class UVerticalBox;
class ADMFMMOPlayerController;
class UDMFPlayerDigimonComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFDigimonVendorEntryPressed, EDMFDigimonVendorTransactionType, TransactionType, FGuid, Identifier);

/** Lightweight native list button carrying a server-owned stock GUID or owned Digimon GUID. */
UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFDigimonVendorEntryButton : public UButton
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Vendor") FDMFDigimonVendorEntryPressed OnVendorEntryPressed;
    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Vendor") EDMFDigimonVendorTransactionType TransactionType = EDMFDigimonVendorTransactionType::Buy;
    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Vendor") FGuid Identifier;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Vendor")
    void InitializeVendorEntry(EDMFDigimonVendorTransactionType InTransactionType, FGuid InIdentifier);

private:
    UFUNCTION() void HandlePressed();
};

/** Polished native BUY/SELL Digimon vendor window. Blueprint subclasses may bind/replace the same public contract. */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFDigimonVendorWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Vendor") void InitializeVendor(ADMFDigimonVendorActor* InVendor);
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Vendor") void RefreshVendorUI();
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Vendor") void SetVendorTab(EDMFDigimonVendorTransactionType NewTab);
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor") ADMFDigimonVendorActor* GetVendor() const { return Vendor.Get(); }
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor") EDMFDigimonVendorTransactionType GetVendorTab() const { return CurrentTab; }

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Vendor") void BP_OnVendorRefreshed();
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Vendor") void BP_OnVendorSelectionChanged(EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier);

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> VendorNameText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> VendorSubtitleText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> MoneyText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> RotationText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> BuyTabButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SellTabButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> EntryListBox;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UImage> DetailPortrait;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> DetailNameText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> DetailMetaText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> DetailStatsText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> DetailValueText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> VendorStatusText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> TransactionButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> TransactionButtonText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> CloseButton;

private:
    TWeakObjectPtr<ADMFDigimonVendorActor> Vendor;
    TWeakObjectPtr<UDMFPlayerDigimonComponent> DigimonComponent;
    EDMFDigimonVendorTransactionType CurrentTab = EDMFDigimonVendorTransactionType::Buy;
    FGuid SelectedIdentifier;
    bool bTransactionConfirmationArmed = false;
    EDMFDigimonVendorTransactionType ConfirmationTransactionType = EDMFDigimonVendorTransactionType::Buy;
    FGuid ConfirmationIdentifier;
    FTimerHandle HeaderRefreshTimer;

    void BuildNativeFallbackUI();
    void RebindSources();
    void RefreshEntryList();
    void RefreshDetails();
    void RefreshHeader();
    void ResetTransactionConfirmation();
    bool ResolveSelectedDigimon(FDMFDigimonInstance& OutDigimon, int64& OutPrice, EDMFDigimonStorageLocation& OutStorage, FText& OutBlockReason) const;

    UFUNCTION() void HandleBuyTabClicked();
    UFUNCTION() void HandleSellTabClicked();
    UFUNCTION() void HandleEntryPressed(EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier);
    UFUNCTION() void HandleTransactionClicked();
    UFUNCTION() void HandleCloseClicked();
    UFUNCTION() void HandleVendorStockChanged();
    UFUNCTION() void HandleVendorEnabledChanged(bool bEnabled);
    UFUNCTION() void HandleVendorConfigurationChanged();
    UFUNCTION() void HandlePartyChanged();
    UFUNCTION() void HandleBankChanged();
    UFUNCTION() void HandleMoneyChanged(int64 NewMoney);
    UFUNCTION() void HandleVendorTransactionResult(bool bSuccess, FText Message, EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier, int64 Price, int64 NewMoney);
    UFUNCTION() void HandleHeaderTimer();
};
