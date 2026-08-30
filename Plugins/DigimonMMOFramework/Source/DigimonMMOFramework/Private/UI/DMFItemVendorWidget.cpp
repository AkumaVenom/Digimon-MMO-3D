#include "UI/DMFItemVendorWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/ScaleBox.h"
#include "Components/ScrollBox.h"
#include "Components/SizeBox.h"
#include "Components/Spacer.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Data/DMFItemData.h"
#include "Engine/Texture2D.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "TimerManager.h"
#include "UI/DMFNativeUIStyle.h"

namespace
{
    FString FormatItemVendorRotation(const float Seconds)
    {
        if (Seconds < 0.0f) return TEXT("MANUAL STOCK");
        const int32 Total = FMath::Max(0, FMath::CeilToInt(Seconds));
        return FString::Printf(TEXT("NEXT STOCK %02d:%02d"), Total / 60, Total % 60);
    }

    FText ItemCategoryText(const EDMFItemCategory Category)
    {
        const UEnum* Enum = StaticEnum<EDMFItemCategory>();
        return Enum ? Enum->GetDisplayNameTextByValue(static_cast<int64>(Category)) : FText::GetEmpty();
    }

    int64 SafeQuantityPrice(const int64 UnitPrice, const int32 Quantity)
    {
        const int64 SafeUnit = FMath::Max<int64>(0, UnitPrice);
        const int64 SafeQuantity = FMath::Max<int64>(0, Quantity);
        if (SafeUnit == 0 || SafeQuantity == 0) return 0;
        return SafeUnit > MAX_int64 / SafeQuantity ? MAX_int64 : SafeUnit * SafeQuantity;
    }

    UTextBlock* MakeButtonLabel(UWidgetTree* Tree, const FText& Text, const int32 FontSize = 13)
    {
        UTextBlock* Label = Tree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        Label->SetText(Text);
        Label->SetJustification(ETextJustify::Center);
        DMFNativeUI::StyleText(Label, FontSize, DMFNativeUI::Text(), true);
        return Label;
    }
}

void UDMFItemVendorEntryButton::InitializeItemVendorEntry(const EDMFItemVendorTransactionType InTransactionType, const FGuid InStockId, const FPrimaryAssetId InItemAssetId)
{
    TransactionType = InTransactionType;
    StockId = InStockId;
    ItemAssetId = InItemAssetId;
    OnClicked.RemoveDynamic(this, &UDMFItemVendorEntryButton::HandlePressed);
    OnClicked.AddDynamic(this, &UDMFItemVendorEntryButton::HandlePressed);
}

void UDMFItemVendorEntryButton::HandlePressed()
{
    OnItemVendorEntryPressed.Broadcast(TransactionType, StockId, ItemAssetId);
}

TSharedRef<SWidget> UDMFItemVendorWidget::RebuildWidget()
{
    if (!WidgetTree) WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFItemVendorWidgetTree"));
    if (WidgetTree && !WidgetTree->RootWidget) BuildNativeFallbackUI();
    return Super::RebuildWidget();
}

void UDMFItemVendorWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (BuyTabButton) BuyTabButton->OnClicked.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleBuyTabClicked);
    if (SellTabButton) SellTabButton->OnClicked.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleSellTabClicked);
    if (QuantityMinusTenButton) QuantityMinusTenButton->OnClicked.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleQuantityMinusTen);
    if (QuantityMinusOneButton) QuantityMinusOneButton->OnClicked.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleQuantityMinusOne);
    if (QuantityPlusOneButton) QuantityPlusOneButton->OnClicked.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleQuantityPlusOne);
    if (QuantityPlusTenButton) QuantityPlusTenButton->OnClicked.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleQuantityPlusTen);
    if (QuantityMaxButton) QuantityMaxButton->OnClicked.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleQuantityMax);
    if (TransactionButton) TransactionButton->OnClicked.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleTransactionClicked);
    if (CloseButton) CloseButton->OnClicked.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleCloseClicked);
    RebindSources();
    if (UWorld* World = GetWorld()) World->GetTimerManager().SetTimer(HeaderRefreshTimer, this, &UDMFItemVendorWidget::HandleHeaderTimer, 1.0f, true, 0.2f);
    RefreshVendorUI();
}

void UDMFItemVendorWidget::NativeDestruct()
{
    if (UWorld* World = GetWorld()) World->GetTimerManager().ClearTimer(HeaderRefreshTimer);
    if (Vendor.IsValid())
    {
        Vendor->OnVendorStockChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleVendorStockChanged);
        Vendor->OnVendorEnabledChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleVendorEnabledChanged);
        Vendor->OnVendorConfigurationChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleVendorConfigurationChanged);
    }
    if (DigimonComponent.IsValid())
    {
        DigimonComponent->OnItemInventoryChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleItemInventoryChanged);
        DigimonComponent->OnMoneyChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleMoneyChanged);
    }
    if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        PC->OnItemVendorTransactionResult.RemoveDynamic(this, &UDMFItemVendorWidget::HandleVendorTransactionResult);
    }
    Super::NativeDestruct();
}

void UDMFItemVendorWidget::InitializeVendor(ADMFItemVendorActor* InVendor)
{
    if (Vendor.Get() != InVendor)
    {
        SelectedStockId.Invalidate();
        SelectedItemAssetId = FPrimaryAssetId();
        SelectedQuantity = 1;
        ResetTransactionConfirmation();
    }
    Vendor = InVendor;
    RebindSources();
    RefreshVendorUI();
}

void UDMFItemVendorWidget::RebindSources()
{
    if (Vendor.IsValid())
    {
        Vendor->OnVendorStockChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleVendorStockChanged);
        Vendor->OnVendorEnabledChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleVendorEnabledChanged);
        Vendor->OnVendorConfigurationChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleVendorConfigurationChanged);
        Vendor->OnVendorStockChanged.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleVendorStockChanged);
        Vendor->OnVendorEnabledChanged.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleVendorEnabledChanged);
        Vendor->OnVendorConfigurationChanged.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleVendorConfigurationChanged);
    }

    ADMFPlayerState* PlayerState = GetOwningPlayer() ? GetOwningPlayer()->GetPlayerState<ADMFPlayerState>() : nullptr;
    UDMFPlayerDigimonComponent* NewComponent = PlayerState ? PlayerState->DigimonComponent.Get() : nullptr;
    if (DigimonComponent.Get() != NewComponent && DigimonComponent.IsValid())
    {
        DigimonComponent->OnItemInventoryChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleItemInventoryChanged);
        DigimonComponent->OnMoneyChanged.RemoveDynamic(this, &UDMFItemVendorWidget::HandleMoneyChanged);
    }
    DigimonComponent = NewComponent;
    if (DigimonComponent.IsValid())
    {
        DigimonComponent->OnItemInventoryChanged.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleItemInventoryChanged);
        DigimonComponent->OnMoneyChanged.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleMoneyChanged);
    }

    if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        PC->OnItemVendorTransactionResult.RemoveDynamic(this, &UDMFItemVendorWidget::HandleVendorTransactionResult);
        PC->OnItemVendorTransactionResult.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleVendorTransactionResult);
    }
}

void UDMFItemVendorWidget::BuildNativeFallbackUI()
{
    UOverlay* RootOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("RootOverlay"));
    WidgetTree->RootWidget = RootOverlay;

    UBorder* Backdrop = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
    Backdrop->SetBrushColor(DMFNativeUI::Backdrop());
    if (UOverlaySlot* BackdropOverlaySlot = RootOverlay->AddChildToOverlay(Backdrop))
    {
        BackdropOverlaySlot->SetHorizontalAlignment(HAlign_Fill);
        BackdropOverlaySlot->SetVerticalAlignment(VAlign_Fill);
    }

    USizeBox* WindowSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
    WindowSize->SetWidthOverride(1240.0f);
    WindowSize->SetHeightOverride(760.0f);
    if (UOverlaySlot* WindowOverlaySlot = RootOverlay->AddChildToOverlay(WindowSize))
    {
        WindowOverlaySlot->SetHorizontalAlignment(HAlign_Center);
        WindowOverlaySlot->SetVerticalAlignment(VAlign_Center);
    }

    UBorder* WindowBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
    DMFNativeUI::StylePanel(WindowBorder, DMFNativeUI::Panel(), FMargin(22.0f));
    WindowSize->AddChild(WindowBorder);
    UVerticalBox* RootColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
    WindowBorder->AddChild(RootColumn);

    UHorizontalBox* HeaderRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
    RootColumn->AddChildToVerticalBox(HeaderRow)->SetPadding(FMargin(0,0,0,14));
    UVerticalBox* HeaderLabels = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
    if (UHorizontalBoxSlot* HeaderLabelSlot = HeaderRow->AddChildToHorizontalBox(HeaderLabels)) HeaderLabelSlot->SetSize(DMFNativeUI::FillSize());
    VendorNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorNameText"));
    DMFNativeUI::StyleText(VendorNameText, 28, DMFNativeUI::Text(), true);
    HeaderLabels->AddChildToVerticalBox(VendorNameText);
    VendorSubtitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorSubtitleText"));
    VendorSubtitleText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(VendorSubtitleText, 13, DMFNativeUI::Muted());
    HeaderLabels->AddChildToVerticalBox(VendorSubtitleText)->SetPadding(FMargin(0,3,10,0));

    UVerticalBox* HeaderEconomy = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
    if (UHorizontalBoxSlot* HeaderEconomySlot = HeaderRow->AddChildToHorizontalBox(HeaderEconomy))
    {
        HeaderEconomySlot->SetHorizontalAlignment(HAlign_Right);
        HeaderEconomySlot->SetVerticalAlignment(VAlign_Center);
    }
    MoneyText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("MoneyText"));
    MoneyText->SetJustification(ETextJustify::Right);
    DMFNativeUI::StyleText(MoneyText, 18, DMFNativeUI::Gold(), true);
    HeaderEconomy->AddChildToVerticalBox(MoneyText);
    RotationText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("RotationText"));
    RotationText->SetJustification(ETextJustify::Right);
    DMFNativeUI::StyleText(RotationText, 11, DMFNativeUI::Accent(), true);
    HeaderEconomy->AddChildToVerticalBox(RotationText)->SetPadding(FMargin(0,3,0,0));

    UHorizontalBox* Tabs = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
    RootColumn->AddChildToVerticalBox(Tabs)->SetPadding(FMargin(0,0,0,14));
    BuyTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("BuyTabButton"));
    BuyTabButton->AddChild(MakeButtonLabel(WidgetTree, NSLOCTEXT("DMF","ItemVendorBuyTab","BUY"), 14));
    if (UHorizontalBoxSlot* BuySlot = Tabs->AddChildToHorizontalBox(BuyTabButton)) { BuySlot->SetSize(DMFNativeUI::FillSize()); BuySlot->SetPadding(FMargin(0,0,5,0)); }
    SellTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("SellTabButton"));
    SellTabButton->AddChild(MakeButtonLabel(WidgetTree, NSLOCTEXT("DMF","ItemVendorSellTab","SELL"), 14));
    if (UHorizontalBoxSlot* SellSlot = Tabs->AddChildToHorizontalBox(SellTabButton)) { SellSlot->SetSize(DMFNativeUI::FillSize()); SellSlot->SetPadding(FMargin(5,0,0,0)); }

    UHorizontalBox* ContentRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
    if (UVerticalBoxSlot* ContentVerticalSlot = RootColumn->AddChildToVerticalBox(ContentRow)) ContentVerticalSlot->SetSize(DMFNativeUI::FillSize());

    UBorder* ListPanel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
    DMFNativeUI::StylePanel(ListPanel, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    if (UHorizontalBoxSlot* ListPanelSlot = ContentRow->AddChildToHorizontalBox(ListPanel)) { ListPanelSlot->SetSize(DMFNativeUI::FillSize(0.92f)); ListPanelSlot->SetPadding(FMargin(0,0,8,0)); }
    UScrollBox* EntryScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass());
    ListPanel->AddChild(EntryScroll);
    EntryListBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("EntryListBox"));
    EntryScroll->AddChild(EntryListBox);

    UBorder* DetailPanel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
    DMFNativeUI::StylePanel(DetailPanel, DMFNativeUI::PanelRaised(), FMargin(16.0f));
    if (UHorizontalBoxSlot* DetailPanelSlot = ContentRow->AddChildToHorizontalBox(DetailPanel)) { DetailPanelSlot->SetSize(DMFNativeUI::FillSize(1.08f)); DetailPanelSlot->SetPadding(FMargin(8,0,0,0)); }
    UVerticalBox* DetailColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
    DetailPanel->AddChild(DetailColumn);

    UHorizontalBox* DetailHeader = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
    DetailColumn->AddChildToVerticalBox(DetailHeader)->SetPadding(FMargin(0,0,0,10));
    USizeBox* IconSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
    IconSize->SetWidthOverride(92.0f); IconSize->SetHeightOverride(92.0f);
    if (UHorizontalBoxSlot* IconBoxSlot = DetailHeader->AddChildToHorizontalBox(IconSize)) IconBoxSlot->SetPadding(FMargin(0,0,14,0));
    DetailIcon = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("DetailIcon"));
    IconSize->AddChild(DetailIcon);
    UVerticalBox* DetailLabels = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
    if (UHorizontalBoxSlot* DetailLabelSlot = DetailHeader->AddChildToHorizontalBox(DetailLabels)) { DetailLabelSlot->SetSize(DMFNativeUI::FillSize()); DetailLabelSlot->SetVerticalAlignment(VAlign_Center); }
    DetailNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailNameText"));
    DMFNativeUI::StyleText(DetailNameText, 22, DMFNativeUI::Text(), true);
    DetailLabels->AddChildToVerticalBox(DetailNameText);
    DetailMetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailMetaText"));
    DMFNativeUI::StyleText(DetailMetaText, 12, DMFNativeUI::Accent(), true);
    DetailLabels->AddChildToVerticalBox(DetailMetaText)->SetPadding(FMargin(0,3,0,0));

    DetailDescriptionText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailDescriptionText"));
    DetailDescriptionText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DetailDescriptionText, 13, DMFNativeUI::Muted());
    DetailColumn->AddChildToVerticalBox(DetailDescriptionText)->SetPadding(FMargin(0,0,0,12));

    DetailInventoryText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailInventoryText"));
    DetailInventoryText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DetailInventoryText, 13, DMFNativeUI::Text());
    DetailColumn->AddChildToVerticalBox(DetailInventoryText)->SetPadding(FMargin(0,0,0,8));
    DetailPriceText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailPriceText"));
    DetailPriceText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DetailPriceText, 16, DMFNativeUI::Gold(), true);
    DetailColumn->AddChildToVerticalBox(DetailPriceText)->SetPadding(FMargin(0,0,0,14));

    UBorder* QuantityPanel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
    DMFNativeUI::StylePanel(QuantityPanel, DMFNativeUI::PanelSoft(), FMargin(10.0f));
    DetailColumn->AddChildToVerticalBox(QuantityPanel)->SetPadding(FMargin(0,0,0,12));
    UHorizontalBox* QuantityRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
    QuantityPanel->AddChild(QuantityRow);

    auto AddQuantityButton = [&](const FName WidgetName, const FText& LabelText, TObjectPtr<UButton>& OutButton)
    {
        OutButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), WidgetName);
        DMFNativeUI::StyleCompactButton(OutButton);
        OutButton->AddChild(MakeButtonLabel(WidgetTree, LabelText, 12));
        if (UHorizontalBoxSlot* QuantityButtonSlot = QuantityRow->AddChildToHorizontalBox(OutButton)) QuantityButtonSlot->SetPadding(FMargin(2,0));
    };
    AddQuantityButton(TEXT("QuantityMinusTenButton"), FText::FromString(TEXT("-10")), QuantityMinusTenButton);
    AddQuantityButton(TEXT("QuantityMinusOneButton"), FText::FromString(TEXT("-1")), QuantityMinusOneButton);
    QuantityText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("QuantityText"));
    QuantityText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(QuantityText, 16, DMFNativeUI::Text(), true);
    if (UHorizontalBoxSlot* QuantityLabelSlot = QuantityRow->AddChildToHorizontalBox(QuantityText)) { QuantityLabelSlot->SetSize(DMFNativeUI::FillSize()); QuantityLabelSlot->SetVerticalAlignment(VAlign_Center); QuantityLabelSlot->SetPadding(FMargin(10,0)); }
    AddQuantityButton(TEXT("QuantityPlusOneButton"), FText::FromString(TEXT("+1")), QuantityPlusOneButton);
    AddQuantityButton(TEXT("QuantityPlusTenButton"), FText::FromString(TEXT("+10")), QuantityPlusTenButton);
    AddQuantityButton(TEXT("QuantityMaxButton"), NSLOCTEXT("DMF","ItemVendorQuantityMax","MAX"), QuantityMaxButton);

    VendorStatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorStatusText"));
    VendorStatusText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(VendorStatusText, 12, DMFNativeUI::Muted());
    if (UVerticalBoxSlot* StatusVerticalSlot = DetailColumn->AddChildToVerticalBox(VendorStatusText)) { StatusVerticalSlot->SetSize(DMFNativeUI::FillSize()); StatusVerticalSlot->SetVerticalAlignment(VAlign_Bottom); StatusVerticalSlot->SetPadding(FMargin(0,0,0,10)); }

    TransactionButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("TransactionButton"));
    DMFNativeUI::StyleButton(TransactionButton, true);
    TransactionButtonText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TransactionButtonText"));
    TransactionButtonText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(TransactionButtonText, 15, DMFNativeUI::Text(), true);
    TransactionButton->AddChild(TransactionButtonText);
    DetailColumn->AddChildToVerticalBox(TransactionButton)->SetPadding(FMargin(0,0,0,8));

    CloseButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("CloseButton"));
    DMFNativeUI::StyleButton(CloseButton);
    CloseButton->AddChild(MakeButtonLabel(WidgetTree, NSLOCTEXT("DMF","ItemVendorClose","CLOSE"), 13));
    DetailColumn->AddChildToVerticalBox(CloseButton);
}

void UDMFItemVendorWidget::SetVendorTab(const EDMFItemVendorTransactionType NewTab)
{
    if (CurrentTab == NewTab) return;
    CurrentTab = NewTab;
    SelectedStockId.Invalidate();
    SelectedItemAssetId = FPrimaryAssetId();
    SelectedQuantity = 1;
    ResetTransactionConfirmation();
    RefreshVendorUI();
}

void UDMFItemVendorWidget::RefreshVendorUI()
{
    RebindSources();
    RefreshHeader();
    RefreshEntryList();
    SetSelectedQuantityClamped(SelectedQuantity);
    RefreshDetails();
    if (BuyTabButton) DMFNativeUI::StyleButton(BuyTabButton, CurrentTab == EDMFItemVendorTransactionType::Buy, false, CurrentTab == EDMFItemVendorTransactionType::Buy);
    if (SellTabButton) DMFNativeUI::StyleButton(SellTabButton, CurrentTab == EDMFItemVendorTransactionType::Sell, false, CurrentTab == EDMFItemVendorTransactionType::Sell);
    BP_OnVendorRefreshed();
}

void UDMFItemVendorWidget::RefreshHeader()
{
    ADMFItemVendorActor* ActiveVendor = Vendor.Get();
    if (VendorNameText) VendorNameText->SetText(ActiveVendor ? ActiveVendor->VendorDisplayName : NSLOCTEXT("DMF","ItemVendorUnavailableName","ITEM EXCHANGE"));
    if (VendorSubtitleText) VendorSubtitleText->SetText(ActiveVendor ? ActiveVendor->VendorSubtitle : FText::GetEmpty());
    const int64 Money = DigimonComponent.IsValid() ? DigimonComponent->GetMoney() : 0;
    if (MoneyText) MoneyText->SetText(FText::Format(NSLOCTEXT("DMF","ItemVendorBitsFmt","BITS  {0}"), FText::AsNumber(Money)));
    if (RotationText) RotationText->SetText(FText::FromString(ActiveVendor ? FormatItemVendorRotation(ActiveVendor->GetSecondsUntilStockRotation()) : TEXT("STOCK OFFLINE")));
}

void UDMFItemVendorWidget::RefreshEntryList()
{
    if (!EntryListBox) return;
    EntryListBox->ClearChildren();
    ADMFItemVendorActor* ActiveVendor = Vendor.Get();
    if (!ActiveVendor || !DigimonComponent.IsValid()) return;

    bool bSelectionStillValid = false;
    if (CurrentTab == EDMFItemVendorTransactionType::Buy)
    {
        for (const FDMFItemVendorStockItem& Offer : ActiveVendor->ReplicatedStock)
        {
            if (!Offer.IsValid()) continue;
            UDMFItemData* Item = DigimonComponent->ResolveItemData(Offer.ItemAssetId);
            if (!Item) continue;

            UDMFItemVendorEntryButton* EntryButton = WidgetTree->ConstructWidget<UDMFItemVendorEntryButton>(UDMFItemVendorEntryButton::StaticClass());
            EntryButton->InitializeItemVendorEntry(CurrentTab, Offer.StockId, Offer.ItemAssetId);
            EntryButton->OnItemVendorEntryPressed.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleEntryPressed);
            const bool bSelected = Offer.StockId == SelectedStockId;
            DMFNativeUI::StyleButton(EntryButton, false, false, bSelected);

            UHorizontalBox* Row = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
            EntryButton->AddChild(Row);
            UVerticalBox* Labels = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
            if (UHorizontalBoxSlot* LabelsSlot = Row->AddChildToHorizontalBox(Labels)) { LabelsSlot->SetSize(DMFNativeUI::FillSize()); LabelsSlot->SetVerticalAlignment(VAlign_Center); }
            UTextBlock* NameLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            NameLabel->SetText(Item->DisplayName.IsEmpty() ? FText::FromName(Offer.ItemAssetId.PrimaryAssetName) : Item->DisplayName);
            DMFNativeUI::StyleText(NameLabel, 15, DMFNativeUI::Text(), true);
            Labels->AddChildToVerticalBox(NameLabel);
            UTextBlock* MetaLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            MetaLabel->SetText(FText::Format(NSLOCTEXT("DMF","ItemVendorBuyRowMeta","{0}  •  STOCK {1}"), ItemCategoryText(Item->Category), FText::AsNumber(Offer.AvailableQuantity)));
            DMFNativeUI::StyleText(MetaLabel, 11, DMFNativeUI::Muted());
            Labels->AddChildToVerticalBox(MetaLabel)->SetPadding(FMargin(0,2,6,0));
            UTextBlock* PriceLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            PriceLabel->SetText(FText::Format(NSLOCTEXT("DMF","ItemVendorBuyUnitFmt","{0} BITS EA"), FText::AsNumber(Offer.UnitBuyPrice)));
            PriceLabel->SetJustification(ETextJustify::Right);
            DMFNativeUI::StyleText(PriceLabel, 13, DMFNativeUI::Gold(), true);
            if (UHorizontalBoxSlot* PriceSlot = Row->AddChildToHorizontalBox(PriceLabel)) { PriceSlot->SetVerticalAlignment(VAlign_Center); PriceSlot->SetPadding(FMargin(8,0,2,0)); }
            EntryListBox->AddChildToVerticalBox(EntryButton)->SetPadding(FMargin(0,0,0,8));

            if (bSelected) bSelectionStillValid = true;
        }
        if (!bSelectionStillValid)
        {
            SelectedStockId.Invalidate(); SelectedItemAssetId = FPrimaryAssetId();
            for (const FDMFItemVendorStockItem& Offer : ActiveVendor->ReplicatedStock)
            {
                if (Offer.IsValid()) { SelectedStockId = Offer.StockId; SelectedItemAssetId = Offer.ItemAssetId; break; }
            }
        }
    }
    else
    {
        TMap<FPrimaryAssetId, int32> Aggregate;
        for (const FDMFItemStack& Stack : DigimonComponent->GetItemInventory())
        {
            if (!Stack.IsValid()) continue;
            Aggregate.FindOrAdd(Stack.ItemAssetId) = static_cast<int32>(FMath::Min<int64>(MAX_int32, static_cast<int64>(Aggregate.FindRef(Stack.ItemAssetId)) + static_cast<int64>(Stack.Quantity)));
        }
        TArray<FPrimaryAssetId> ItemIds;
        Aggregate.GetKeys(ItemIds);
        ItemIds.Sort([&](const FPrimaryAssetId& A, const FPrimaryAssetId& B)
        {
            UDMFItemData* ItemA = DigimonComponent->ResolveItemData(A);
            UDMFItemData* ItemB = DigimonComponent->ResolveItemData(B);
            const int32 SortA = ItemA ? ItemA->SortPriority : 0;
            const int32 SortB = ItemB ? ItemB->SortPriority : 0;
            if (SortA != SortB) return SortA < SortB;
            return A.ToString() < B.ToString();
        });

        for (const FPrimaryAssetId& ItemId : ItemIds)
        {
            UDMFItemData* Item = DigimonComponent->ResolveItemData(ItemId);
            if (!Item) continue;
            FText SellBlock;
            const bool bSellable = ActiveVendor->IsItemSellable(ItemId, SellBlock);
            const int64 UnitPrice = bSellable ? ActiveVendor->GetPlayerSellUnitPrice(ItemId) : 0;

            UDMFItemVendorEntryButton* EntryButton = WidgetTree->ConstructWidget<UDMFItemVendorEntryButton>(UDMFItemVendorEntryButton::StaticClass());
            EntryButton->InitializeItemVendorEntry(CurrentTab, FGuid(), ItemId);
            EntryButton->OnItemVendorEntryPressed.AddUniqueDynamic(this, &UDMFItemVendorWidget::HandleEntryPressed);
            const bool bSelected = ItemId == SelectedItemAssetId;
            DMFNativeUI::StyleButton(EntryButton, false, !bSellable, bSelected);
            UHorizontalBox* Row = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
            EntryButton->AddChild(Row);
            UVerticalBox* Labels = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
            if (UHorizontalBoxSlot* LabelsSlot = Row->AddChildToHorizontalBox(Labels)) { LabelsSlot->SetSize(DMFNativeUI::FillSize()); LabelsSlot->SetVerticalAlignment(VAlign_Center); }
            UTextBlock* NameLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            NameLabel->SetText(Item->DisplayName.IsEmpty() ? FText::FromName(ItemId.PrimaryAssetName) : Item->DisplayName);
            DMFNativeUI::StyleText(NameLabel, 15, DMFNativeUI::Text(), true);
            Labels->AddChildToVerticalBox(NameLabel);
            UTextBlock* MetaLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            MetaLabel->SetText(FText::Format(NSLOCTEXT("DMF","ItemVendorSellRowMeta","{0}  •  OWNED {1}"), ItemCategoryText(Item->Category), FText::AsNumber(Aggregate.FindRef(ItemId))));
            DMFNativeUI::StyleText(MetaLabel, 11, DMFNativeUI::Muted());
            Labels->AddChildToVerticalBox(MetaLabel)->SetPadding(FMargin(0,2,6,0));
            UTextBlock* QuoteLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            QuoteLabel->SetText(bSellable ? FText::Format(NSLOCTEXT("DMF","ItemVendorSellUnitFmt","+{0} BITS EA"), FText::AsNumber(UnitPrice)) : NSLOCTEXT("DMF","ItemVendorProtectedLabel","PROTECTED"));
            QuoteLabel->SetJustification(ETextJustify::Right);
            DMFNativeUI::StyleText(QuoteLabel, 12, bSellable ? DMFNativeUI::Gold() : DMFNativeUI::Danger(), true);
            if (UHorizontalBoxSlot* QuoteSlot = Row->AddChildToHorizontalBox(QuoteLabel)) { QuoteSlot->SetVerticalAlignment(VAlign_Center); QuoteSlot->SetPadding(FMargin(8,0,2,0)); }
            EntryListBox->AddChildToVerticalBox(EntryButton)->SetPadding(FMargin(0,0,0,8));
            if (bSelected) bSelectionStillValid = true;
        }
        if (!bSelectionStillValid)
        {
            SelectedStockId.Invalidate(); SelectedItemAssetId = ItemIds.IsEmpty() ? FPrimaryAssetId() : ItemIds[0];
        }
    }
}

bool UDMFItemVendorWidget::ResolveSelectedItem(UDMFItemData*& OutItem, int64& OutUnitPrice, int32& OutAvailableQuantity, FText& OutBlockReason) const
{
    OutItem = nullptr; OutUnitPrice = 0; OutAvailableQuantity = 0; OutBlockReason = FText::GetEmpty();
    ADMFItemVendorActor* ActiveVendor = Vendor.Get();
    if (!ActiveVendor || !DigimonComponent.IsValid()) return false;

    if (CurrentTab == EDMFItemVendorTransactionType::Buy)
    {
        const FDMFItemVendorStockItem* Offer = ActiveVendor->ReplicatedStock.FindByPredicate([&](const FDMFItemVendorStockItem& Candidate){ return Candidate.StockId == SelectedStockId; });
        if (!Offer || !Offer->IsValid()) return false;
        OutItem = DigimonComponent->ResolveItemData(Offer->ItemAssetId);
        if (!OutItem) return false;
        OutUnitPrice = Offer->UnitBuyPrice;
        OutAvailableQuantity = Offer->AvailableQuantity;
        if (!ActiveVendor->bVendorEnabled || !ActiveVendor->bAllowBuying) OutBlockReason = NSLOCTEXT("DMF","ItemVendorBuyBlockedUI","Buying is currently unavailable.");
        else if (DigimonComponent->GetMoney() < OutUnitPrice) OutBlockReason = NSLOCTEXT("DMF","ItemVendorNotEnoughBitsUI","Not enough BITS for one item.");
        else if (DigimonComponent->GetAvailableItemCapacity(Offer->ItemAssetId) <= 0) OutBlockReason = NSLOCTEXT("DMF","ItemVendorBagFullUI","Your item inventory is full for this item.");
        return true;
    }

    OutItem = DigimonComponent->ResolveItemData(SelectedItemAssetId);
    if (!OutItem) return false;
    OutAvailableQuantity = DigimonComponent->GetTotalItemQuantity(SelectedItemAssetId);
    FText SellReason;
    if (!ActiveVendor->bVendorEnabled || !ActiveVendor->bAllowSelling) OutBlockReason = NSLOCTEXT("DMF","ItemVendorSellBlockedUI","Selling is currently unavailable.");
    else if (!ActiveVendor->IsItemSellable(SelectedItemAssetId, SellReason)) OutBlockReason = SellReason;
    OutUnitPrice = ActiveVendor->GetPlayerSellUnitPrice(SelectedItemAssetId);
    return true;
}

int32 UDMFItemVendorWidget::GetMaximumSelectableQuantity() const
{
    UDMFItemData* Item = nullptr; int64 UnitPrice = 0; int32 Available = 0; FText Block;
    if (!ResolveSelectedItem(Item, UnitPrice, Available, Block) || !Item || Available <= 0) return 0;
    if (CurrentTab == EDMFItemVendorTransactionType::Sell) return FMath::Clamp(Available, 0, 999999);
    if (UnitPrice <= 0 || !DigimonComponent.IsValid()) return 0;
    const int64 Affordable = DigimonComponent->GetMoney() / UnitPrice;
    const int32 Capacity = DigimonComponent->GetAvailableItemCapacity(Item->GetPrimaryAssetId());
    return static_cast<int32>(FMath::Clamp<int64>(FMath::Min<int64>(Available, FMath::Min<int64>(Affordable, Capacity)), 0, 999999));
}

void UDMFItemVendorWidget::SetSelectedQuantityClamped(const int32 NewQuantity)
{
    const int32 Maximum = GetMaximumSelectableQuantity();
    const int32 Previous = SelectedQuantity;
    SelectedQuantity = Maximum > 0 ? FMath::Clamp(NewQuantity, 1, Maximum) : 0;
    if (Previous != SelectedQuantity)
    {
        ResetTransactionConfirmation();
        BP_OnVendorQuantityChanged(SelectedQuantity);
    }
    if (QuantityText) QuantityText->SetText(FText::Format(NSLOCTEXT("DMF","ItemVendorQuantityFmt","QUANTITY  {0}"), FText::AsNumber(SelectedQuantity)));
}

void UDMFItemVendorWidget::RefreshDetails()
{
    UDMFItemData* Item = nullptr; int64 UnitPrice = 0; int32 Available = 0; FText Block;
    const bool bResolved = ResolveSelectedItem(Item, UnitPrice, Available, Block);
    const FPrimaryAssetId ItemId = Item ? Item->GetPrimaryAssetId() : FPrimaryAssetId();
    if (DetailIcon)
    {
        UTexture2D* Icon = Item ? Item->Icon.LoadSynchronous() : nullptr;
        DetailIcon->SetVisibility(Icon ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
        if (Icon) DetailIcon->SetBrushFromTexture(Icon, true);
    }
    if (DetailNameText) DetailNameText->SetText(bResolved && Item ? (Item->DisplayName.IsEmpty() ? FText::FromName(ItemId.PrimaryAssetName) : Item->DisplayName) : NSLOCTEXT("DMF","ItemVendorSelectPrompt","SELECT AN ITEM"));
    if (DetailMetaText) DetailMetaText->SetText(bResolved && Item ? FText::Format(NSLOCTEXT("DMF","ItemVendorDetailMeta","{0}  •  MAX STACK {1}"), ItemCategoryText(Item->Category), FText::AsNumber(FMath::Max(1, Item->MaxStackSize))) : FText::GetEmpty());
    if (DetailDescriptionText) DetailDescriptionText->SetText(bResolved && Item ? Item->Description : NSLOCTEXT("DMF","ItemVendorDetailPrompt","Choose an item offer or one of your inventory items."));

    const int32 Owned = bResolved && DigimonComponent.IsValid() ? DigimonComponent->GetTotalItemQuantity(ItemId) : 0;
    const int32 Capacity = bResolved && DigimonComponent.IsValid() ? DigimonComponent->GetAvailableItemCapacity(ItemId) : 0;
    if (DetailInventoryText)
    {
        if (!bResolved)
        {
            DetailInventoryText->SetText(FText::GetEmpty());
        }
        else if (CurrentTab == EDMFItemVendorTransactionType::Buy)
        {
            DetailInventoryText->SetText(FText::Format(NSLOCTEXT("DMF","ItemVendorBuyInventoryFmt","Owned: {0}  •  Shared Stock: {1}\nAdditional inventory capacity: {2} item(s)"),
                FText::AsNumber(Owned), FText::AsNumber(Available), FText::AsNumber(Capacity)));
        }
        else
        {
            DetailInventoryText->SetText(FText::Format(NSLOCTEXT("DMF","ItemVendorSellInventoryFmt","Owned across all stacks: {0}\nProtected Key/Quest items can never be sold."), FText::AsNumber(Owned)));
        }
    }

    SetSelectedQuantityClamped(SelectedQuantity <= 0 ? 1 : SelectedQuantity);
    const int64 TotalPrice = bResolved ? SafeQuantityPrice(UnitPrice, SelectedQuantity) : 0;
    if (DetailPriceText)
    {
        DetailPriceText->SetText(bResolved
            ? FText::Format(CurrentTab == EDMFItemVendorTransactionType::Buy
                ? NSLOCTEXT("DMF","ItemVendorBuyDetailPrice","UNIT {0} BITS  •  TOTAL {1} BITS")
                : NSLOCTEXT("DMF","ItemVendorSellDetailPrice","UNIT +{0} BITS  •  TOTAL +{1} BITS"),
                FText::AsNumber(UnitPrice), FText::AsNumber(TotalPrice))
            : FText::GetEmpty());
    }

    const int32 Maximum = GetMaximumSelectableQuantity();
    if (QuantityMinusTenButton) QuantityMinusTenButton->SetIsEnabled(SelectedQuantity > 1);
    if (QuantityMinusOneButton) QuantityMinusOneButton->SetIsEnabled(SelectedQuantity > 1);
    if (QuantityPlusOneButton) QuantityPlusOneButton->SetIsEnabled(SelectedQuantity > 0 && SelectedQuantity < Maximum);
    if (QuantityPlusTenButton) QuantityPlusTenButton->SetIsEnabled(SelectedQuantity > 0 && SelectedQuantity < Maximum);
    if (QuantityMaxButton) QuantityMaxButton->SetIsEnabled(Maximum > 0 && SelectedQuantity != Maximum);

    const bool bConfirming = bTransactionConfirmationArmed
        && ConfirmationTransactionType == CurrentTab
        && ConfirmationStockId == SelectedStockId
        && ConfirmationItemAssetId == SelectedItemAssetId
        && ConfirmationQuantity == SelectedQuantity;
    if (TransactionButtonText)
    {
        if (bConfirming)
        {
            TransactionButtonText->SetText(CurrentTab == EDMFItemVendorTransactionType::Buy
                ? FText::Format(NSLOCTEXT("DMF","ItemVendorConfirmBuyFmt","CONFIRM BUY x{0}  •  {1} BITS"), FText::AsNumber(SelectedQuantity), FText::AsNumber(TotalPrice))
                : FText::Format(NSLOCTEXT("DMF","ItemVendorConfirmSellFmt","CONFIRM SELL x{0}  •  +{1} BITS"), FText::AsNumber(SelectedQuantity), FText::AsNumber(TotalPrice)));
        }
        else
        {
            TransactionButtonText->SetText(CurrentTab == EDMFItemVendorTransactionType::Buy
                ? FText::Format(NSLOCTEXT("DMF","ItemVendorBuyButtonFmt","BUY x{0}  •  {1} BITS"), FText::AsNumber(SelectedQuantity), FText::AsNumber(TotalPrice))
                : FText::Format(NSLOCTEXT("DMF","ItemVendorSellButtonFmt","SELL x{0}  •  +{1} BITS"), FText::AsNumber(SelectedQuantity), FText::AsNumber(TotalPrice)));
        }
    }

    const bool bQuantityValid = SelectedQuantity > 0 && SelectedQuantity <= Maximum;
    if (TransactionButton) TransactionButton->SetIsEnabled(bResolved && bQuantityValid && Block.IsEmpty() && TotalPrice > 0);
    if (VendorStatusText)
    {
        if (!Block.IsEmpty())
        {
            VendorStatusText->SetText(Block);
            VendorStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Danger()));
        }
        else if (CurrentTab == EDMFItemVendorTransactionType::Buy)
        {
            VendorStatusText->SetText(NSLOCTEXT("DMF","ItemVendorBuyReady","Shared replicated stock. The server validates BITS, remaining vendor stock and complete stack capacity before committing the purchase."));
            VendorStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));
        }
        else
        {
            VendorStatusText->SetText(NSLOCTEXT("DMF","ItemVendorSellReady","The server removes the selected quantity across your stacks, protects Key/Quest items, credits BITS and saves the account atomically."));
            VendorStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));
        }
    }
}

void UDMFItemVendorWidget::ResetTransactionConfirmation()
{
    bTransactionConfirmationArmed = false;
    ConfirmationStockId.Invalidate();
    ConfirmationItemAssetId = FPrimaryAssetId();
    ConfirmationQuantity = 0;
}

void UDMFItemVendorWidget::HandleBuyTabClicked() { SetVendorTab(EDMFItemVendorTransactionType::Buy); }
void UDMFItemVendorWidget::HandleSellTabClicked() { SetVendorTab(EDMFItemVendorTransactionType::Sell); }

void UDMFItemVendorWidget::HandleEntryPressed(const EDMFItemVendorTransactionType TransactionType, const FGuid StockId, const FPrimaryAssetId ItemAssetId)
{
    CurrentTab = TransactionType;
    SelectedStockId = StockId;
    SelectedItemAssetId = ItemAssetId;
    SelectedQuantity = 1;
    ResetTransactionConfirmation();
    RefreshVendorUI();
    BP_OnVendorSelectionChanged(TransactionType, StockId, ItemAssetId);
}

void UDMFItemVendorWidget::HandleQuantityMinusTen() { SetSelectedQuantityClamped(SelectedQuantity - 10); RefreshDetails(); }
void UDMFItemVendorWidget::HandleQuantityMinusOne() { SetSelectedQuantityClamped(SelectedQuantity - 1); RefreshDetails(); }
void UDMFItemVendorWidget::HandleQuantityPlusOne() { SetSelectedQuantityClamped(SelectedQuantity + 1); RefreshDetails(); }
void UDMFItemVendorWidget::HandleQuantityPlusTen() { SetSelectedQuantityClamped(SelectedQuantity + 10); RefreshDetails(); }
void UDMFItemVendorWidget::HandleQuantityMax() { SetSelectedQuantityClamped(GetMaximumSelectableQuantity()); RefreshDetails(); }

void UDMFItemVendorWidget::HandleTransactionClicked()
{
    ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer());
    ADMFItemVendorActor* ActiveVendor = Vendor.Get();
    const int32 Maximum = GetMaximumSelectableQuantity();
    if (!PC || !ActiveVendor || SelectedQuantity <= 0 || SelectedQuantity > Maximum) return;

    const bool bSameConfirmation = bTransactionConfirmationArmed
        && ConfirmationTransactionType == CurrentTab
        && ConfirmationStockId == SelectedStockId
        && ConfirmationItemAssetId == SelectedItemAssetId
        && ConfirmationQuantity == SelectedQuantity;
    if (!bSameConfirmation)
    {
        bTransactionConfirmationArmed = true;
        ConfirmationTransactionType = CurrentTab;
        ConfirmationStockId = SelectedStockId;
        ConfirmationItemAssetId = SelectedItemAssetId;
        ConfirmationQuantity = SelectedQuantity;
        RefreshDetails();
        return;
    }

    ResetTransactionConfirmation();
    PC->RequestItemVendorTransaction(ActiveVendor, CurrentTab, SelectedStockId, SelectedItemAssetId, SelectedQuantity);
    RefreshDetails();
}

void UDMFItemVendorWidget::HandleCloseClicked()
{
    if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer())) PC->CloseItemVendorUI();
}

void UDMFItemVendorWidget::HandleVendorStockChanged() { ResetTransactionConfirmation(); RefreshVendorUI(); }
void UDMFItemVendorWidget::HandleVendorEnabledChanged(bool bEnabled) { ResetTransactionConfirmation(); RefreshVendorUI(); }
void UDMFItemVendorWidget::HandleVendorConfigurationChanged() { ResetTransactionConfirmation(); RefreshVendorUI(); }
void UDMFItemVendorWidget::HandleItemInventoryChanged() { ResetTransactionConfirmation(); RefreshVendorUI(); }
void UDMFItemVendorWidget::HandleMoneyChanged(int64 NewMoney) { RefreshHeader(); SetSelectedQuantityClamped(SelectedQuantity); RefreshDetails(); }

void UDMFItemVendorWidget::HandleVendorTransactionResult(bool bSuccess, FText Message, EDMFItemVendorTransactionType TransactionType, FPrimaryAssetId ItemAssetId, int32 Quantity, int64 TotalPrice, int64 NewMoney)
{
    ResetTransactionConfirmation();
    RefreshVendorUI();
    if (VendorStatusText && !Message.IsEmpty())
    {
        VendorStatusText->SetText(Message);
        VendorStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
}

void UDMFItemVendorWidget::HandleHeaderTimer()
{
    RefreshHeader();
    if (Vendor.IsValid() && !Vendor->IsVendorEnabled())
    {
        if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer())) PC->CloseItemVendorUI();
    }
}
