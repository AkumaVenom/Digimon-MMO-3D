#include "UI/DMFDigimonVendorWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
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
#include "Data/DMFDigimonSpeciesData.h"
#include "Engine/AssetManager.h"
#include "Engine/Texture2D.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "TimerManager.h"
#include "UI/DMFNativeUIStyle.h"
#include "Utility/DMFDigimonPresentationLibrary.h"

namespace
{
    UDMFDigimonSpeciesData* ResolveVendorSpecies(const FPrimaryAssetId SpeciesId)
    {
        if (!SpeciesId.IsValid() || !UAssetManager::IsInitialized()) return nullptr;
        UAssetManager& Manager = UAssetManager::Get();
        if (UObject* Loaded = Manager.GetPrimaryAssetObject(SpeciesId)) return Cast<UDMFDigimonSpeciesData>(Loaded);
        const FSoftObjectPath Path = Manager.GetPrimaryAssetPath(SpeciesId);
        return Path.IsValid() ? Cast<UDMFDigimonSpeciesData>(Path.TryLoad()) : nullptr;
    }

    FText AttributeText(const EDMFDigimonAttribute Attribute)
    {
        const UEnum* Enum = StaticEnum<EDMFDigimonAttribute>();
        return Enum ? Enum->GetDisplayNameTextByValue(static_cast<int64>(Attribute)) : FText::GetEmpty();
    }

    FString FormatRotationSeconds(const float Seconds)
    {
        if (Seconds < 0.0f) return TEXT("MANUAL STOCK");
        const int32 Total = FMath::Max(0, FMath::CeilToInt(Seconds));
        return FString::Printf(TEXT("NEXT STOCK %02d:%02d"), Total / 60, Total % 60);
    }
}

void UDMFDigimonVendorEntryButton::InitializeVendorEntry(const EDMFDigimonVendorTransactionType InTransactionType, const FGuid InIdentifier)
{
    TransactionType = InTransactionType;
    Identifier = InIdentifier;
    OnClicked.RemoveDynamic(this, &UDMFDigimonVendorEntryButton::HandlePressed);
    OnClicked.AddDynamic(this, &UDMFDigimonVendorEntryButton::HandlePressed);
}

void UDMFDigimonVendorEntryButton::HandlePressed()
{
    OnVendorEntryPressed.Broadcast(TransactionType, Identifier);
}

TSharedRef<SWidget> UDMFDigimonVendorWidget::RebuildWidget()
{
    if (!WidgetTree) WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFDigimonVendorWidgetTree"));
    if (WidgetTree && !WidgetTree->RootWidget) BuildNativeFallbackUI();
    return Super::RebuildWidget();
}

void UDMFDigimonVendorWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (BuyTabButton) BuyTabButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonVendorWidget::HandleBuyTabClicked);
    if (SellTabButton) SellTabButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonVendorWidget::HandleSellTabClicked);
    if (TransactionButton) TransactionButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonVendorWidget::HandleTransactionClicked);
    if (CloseButton) CloseButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonVendorWidget::HandleCloseClicked);
    RebindSources();
    if (UWorld* World = GetWorld()) World->GetTimerManager().SetTimer(HeaderRefreshTimer, this, &UDMFDigimonVendorWidget::HandleHeaderTimer, 1.0f, true, 0.2f);
    RefreshVendorUI();
}

void UDMFDigimonVendorWidget::NativeDestruct()
{
    if (UWorld* World = GetWorld()) World->GetTimerManager().ClearTimer(HeaderRefreshTimer);
    if (Vendor.IsValid())
    {
        Vendor->OnVendorStockChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorStockChanged);
        Vendor->OnVendorEnabledChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorEnabledChanged);
        Vendor->OnVendorConfigurationChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorConfigurationChanged);
    }
    if (DigimonComponent.IsValid())
    {
        DigimonComponent->OnDigimonInventoryChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandlePartyChanged);
        DigimonComponent->OnDigimonBankChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleBankChanged);
        DigimonComponent->OnMoneyChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleMoneyChanged);
    }
    if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        PC->OnDigimonVendorTransactionResult.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorTransactionResult);
    }
    Super::NativeDestruct();
}

void UDMFDigimonVendorWidget::InitializeVendor(ADMFDigimonVendorActor* InVendor)
{
    if (Vendor.Get() == InVendor)
    {
        RefreshVendorUI();
        return;
    }
    if (Vendor.IsValid())
    {
        Vendor->OnVendorStockChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorStockChanged);
        Vendor->OnVendorEnabledChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorEnabledChanged);
        Vendor->OnVendorConfigurationChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorConfigurationChanged);
    }
    Vendor = InVendor;
    SelectedIdentifier.Invalidate();
    ResetTransactionConfirmation();
    RebindSources();
    RefreshVendorUI();
}

void UDMFDigimonVendorWidget::RebindSources()
{
    if (Vendor.IsValid())
    {
        Vendor->OnVendorStockChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorStockChanged);
        Vendor->OnVendorStockChanged.AddDynamic(this, &UDMFDigimonVendorWidget::HandleVendorStockChanged);
        Vendor->OnVendorEnabledChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorEnabledChanged);
        Vendor->OnVendorConfigurationChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorConfigurationChanged);
        Vendor->OnVendorEnabledChanged.AddDynamic(this, &UDMFDigimonVendorWidget::HandleVendorEnabledChanged);
        Vendor->OnVendorConfigurationChanged.AddDynamic(this, &UDMFDigimonVendorWidget::HandleVendorConfigurationChanged);
    }

    UDMFPlayerDigimonComponent* NewComponent = nullptr;
    if (APlayerController* Owning = GetOwningPlayer())
    {
        if (ADMFPlayerState* PS = Owning->GetPlayerState<ADMFPlayerState>()) NewComponent = PS->DigimonComponent.Get();
    }
    if (DigimonComponent.Get() != NewComponent)
    {
        if (DigimonComponent.IsValid())
        {
            DigimonComponent->OnDigimonInventoryChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandlePartyChanged);
            DigimonComponent->OnDigimonBankChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleBankChanged);
            DigimonComponent->OnMoneyChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleMoneyChanged);
        }
        DigimonComponent = NewComponent;
    }
    if (DigimonComponent.IsValid())
    {
        DigimonComponent->OnDigimonInventoryChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandlePartyChanged);
        DigimonComponent->OnDigimonInventoryChanged.AddDynamic(this, &UDMFDigimonVendorWidget::HandlePartyChanged);
        DigimonComponent->OnDigimonBankChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleBankChanged);
        DigimonComponent->OnDigimonBankChanged.AddDynamic(this, &UDMFDigimonVendorWidget::HandleBankChanged);
        DigimonComponent->OnMoneyChanged.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleMoneyChanged);
        DigimonComponent->OnMoneyChanged.AddDynamic(this, &UDMFDigimonVendorWidget::HandleMoneyChanged);
    }
    if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        PC->OnDigimonVendorTransactionResult.RemoveDynamic(this, &UDMFDigimonVendorWidget::HandleVendorTransactionResult);
        PC->OnDigimonVendorTransactionResult.AddDynamic(this, &UDMFDigimonVendorWidget::HandleVendorTransactionResult);
    }
}

void UDMFDigimonVendorWidget::BuildNativeFallbackUI()
{
    if (!WidgetTree) return;

    UOverlay* Root = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("VendorRoot"));
    WidgetTree->RootWidget = Root;
    UBorder* Backdrop = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("VendorBackdrop"));
    DMFNativeUI::StylePanel(Backdrop, DMFNativeUI::Backdrop(), FMargin(0.0f));
    if (UOverlaySlot* S = Root->AddChildToOverlay(Backdrop)) { S->SetHorizontalAlignment(HAlign_Fill); S->SetVerticalAlignment(VAlign_Fill); }

    UScaleBox* Scale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("VendorScale"));
    Scale->SetStretch(EStretch::ScaleToFit); Scale->SetStretchDirection(EStretchDirection::DownOnly);
    if (UOverlaySlot* S = Root->AddChildToOverlay(Scale)) { S->SetHorizontalAlignment(HAlign_Center); S->SetVerticalAlignment(VAlign_Center); S->SetPadding(FMargin(24.0f)); }

    USizeBox* WindowSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("VendorWindowSize"));
    // Keep a generous authored layout and let the ScaleBox reduce it only on smaller displays.
    // The previous 1180x720 layout compressed the right-hand details stack below its desired
    // height, allowing text to paint through neighbouring widgets. The wider/taller authored
    // canvas plus a dedicated details ScrollBox keeps every text block at natural height.
    WindowSize->SetWidthOverride(1280.0f); WindowSize->SetHeightOverride(780.0f); Scale->AddChild(WindowSize);
    UBorder* Window = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("VendorWindow"));
    DMFNativeUI::StylePanel(Window, DMFNativeUI::Panel(), FMargin(18.0f)); WindowSize->AddChild(Window);
    UVerticalBox* Column = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VendorColumn")); Window->AddChild(Column);

    UHorizontalBox* Header = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("VendorHeader"));
    Column->AddChildToVerticalBox(Header)->SetPadding(FMargin(0,0,0,8));
    UVerticalBox* HeaderNames = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VendorHeaderNames"));
    if (UHorizontalBoxSlot* S = Header->AddChildToHorizontalBox(HeaderNames)) S->SetSize(DMFNativeUI::FillSize());
    VendorNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorNameText")); DMFNativeUI::StyleText(VendorNameText, 28, DMFNativeUI::Text(), true); HeaderNames->AddChildToVerticalBox(VendorNameText);
    VendorSubtitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorSubtitleText")); VendorSubtitleText->SetAutoWrapText(true); DMFNativeUI::StyleText(VendorSubtitleText, 13, DMFNativeUI::Muted()); HeaderNames->AddChildToVerticalBox(VendorSubtitleText);
    UVerticalBox* HeaderMoney = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VendorHeaderMoney")); Header->AddChildToHorizontalBox(HeaderMoney)->SetHorizontalAlignment(HAlign_Right);
    MoneyText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorMoneyText")); MoneyText->SetJustification(ETextJustify::Right); DMFNativeUI::StyleText(MoneyText, 20, DMFNativeUI::Gold(), true); HeaderMoney->AddChildToVerticalBox(MoneyText);
    RotationText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorRotationText")); RotationText->SetJustification(ETextJustify::Right); DMFNativeUI::StyleText(RotationText, 12, DMFNativeUI::Accent()); HeaderMoney->AddChildToVerticalBox(RotationText);

    UHorizontalBox* Tabs = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("VendorTabs")); Column->AddChildToVerticalBox(Tabs)->SetPadding(FMargin(0,4,0,12));
    BuyTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("BuyTabButton")); DMFNativeUI::StyleButton(BuyTabButton, false, false, true); UTextBlock* BuyLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); BuyLabel->SetText(NSLOCTEXT("DMF","VendorBuyTab","BUY DIGIMON")); BuyLabel->SetJustification(ETextJustify::Center); DMFNativeUI::StyleText(BuyLabel, 16, DMFNativeUI::Text(), true); BuyTabButton->AddChild(BuyLabel); if(UHorizontalBoxSlot* S=Tabs->AddChildToHorizontalBox(BuyTabButton)){S->SetSize(DMFNativeUI::FillSize());S->SetPadding(FMargin(0,0,6,0));}
    SellTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("SellTabButton")); DMFNativeUI::StyleButton(SellTabButton); UTextBlock* SellLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); SellLabel->SetText(NSLOCTEXT("DMF","VendorSellTab","SELL DIGIMON")); SellLabel->SetJustification(ETextJustify::Center); DMFNativeUI::StyleText(SellLabel, 16, DMFNativeUI::Text(), true); SellTabButton->AddChild(SellLabel); if(UHorizontalBoxSlot* S=Tabs->AddChildToHorizontalBox(SellTabButton)){S->SetSize(DMFNativeUI::FillSize());S->SetPadding(FMargin(6,0,0,0));}

    UHorizontalBox* Main = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("VendorMain")); if(UVerticalBoxSlot* S=Column->AddChildToVerticalBox(Main)){S->SetSize(DMFNativeUI::FillSize());}
    USizeBox* ListSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("VendorListSize")); ListSize->SetWidthOverride(690.0f); if(UHorizontalBoxSlot* S=Main->AddChildToHorizontalBox(ListSize)){S->SetVerticalAlignment(VAlign_Fill);S->SetPadding(FMargin(0,0,16,0));}
    UBorder* ListBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("VendorListBorder")); DMFNativeUI::StylePanel(ListBorder, DMFNativeUI::PanelRaised(), FMargin(12)); ListSize->AddChild(ListBorder);
    UScrollBox* ListScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("VendorListScroll")); ListBorder->AddChild(ListScroll);
    EntryListBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("EntryListBox")); ListScroll->AddChild(EntryListBox);

    USizeBox* DetailsSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("VendorDetailsSize")); DetailsSize->SetWidthOverride(538.0f); Main->AddChildToHorizontalBox(DetailsSize)->SetVerticalAlignment(VAlign_Fill);
    UBorder* DetailsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("VendorDetailsBorder")); DMFNativeUI::StylePanel(DetailsBorder, DMFNativeUI::PanelRaised(), FMargin(16)); DetailsSize->AddChild(DetailsBorder);
    UVerticalBox* Details = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VendorDetails")); DetailsBorder->AddChild(Details);
    USizeBox* PortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("VendorPortraitSize")); PortraitSize->SetHeightOverride(150.0f); Details->AddChildToVerticalBox(PortraitSize)->SetPadding(FMargin(0,0,0,10));
    UBorder* PortraitBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("VendorPortraitBorder")); DMFNativeUI::StylePanel(PortraitBorder, DMFNativeUI::SlotEmpty(), FMargin(4)); PortraitSize->AddChild(PortraitBorder);
    UScaleBox* PortraitScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("VendorPortraitScale")); PortraitScale->SetStretch(EStretch::ScaleToFit); PortraitBorder->AddChild(PortraitScale);
    DetailPortrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("DetailPortrait")); DetailPortrait->SetVisibility(ESlateVisibility::Hidden); PortraitScale->AddChild(DetailPortrait);
    DetailNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailNameText")); DetailNameText->SetJustification(ETextJustify::Center); DMFNativeUI::StyleText(DetailNameText, 23, DMFNativeUI::Text(), true); Details->AddChildToVerticalBox(DetailNameText);
    DetailMetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailMetaText")); DetailMetaText->SetJustification(ETextJustify::Center); DMFNativeUI::StyleText(DetailMetaText, 13, DMFNativeUI::Gold()); Details->AddChildToVerticalBox(DetailMetaText)->SetPadding(FMargin(0,2,0,10));

    // The information region scrolls independently while the portrait/header and transaction
    // controls remain pinned. This is the important layout hardening: text is never placed in a
    // compressed Fill slot, so high-progression Digimon cannot overlap valuation/actions.
    UScrollBox* DetailsScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("VendorDetailsScroll"));
    if (UVerticalBoxSlot* S = Details->AddChildToVerticalBox(DetailsScroll)) { S->SetSize(DMFNativeUI::FillSize()); S->SetPadding(FMargin(0,0,0,8)); }
    UVerticalBox* DetailsScrollContent = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VendorDetailsScrollContent")); DetailsScroll->AddChild(DetailsScrollContent);

    UBorder* StatsCard = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("VendorStatsCard")); DMFNativeUI::StylePanel(StatsCard, DMFNativeUI::PanelSoft(), FMargin(12)); DetailsScrollContent->AddChildToVerticalBox(StatsCard)->SetPadding(FMargin(0,0,0,8));
    UVerticalBox* StatsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VendorStatsColumn")); StatsCard->AddChild(StatsColumn);
    UTextBlock* StatsHeading = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorStatsHeading")); StatsHeading->SetText(NSLOCTEXT("DMF","VendorStatsHeading","COMBAT & PROGRESSION")); DMFNativeUI::StyleText(StatsHeading, 11, DMFNativeUI::Accent(), true); StatsColumn->AddChildToVerticalBox(StatsHeading)->SetPadding(FMargin(0,0,0,6));
    DetailStatsText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailStatsText")); DetailStatsText->SetAutoWrapText(true); DMFNativeUI::StyleText(DetailStatsText, 12, DMFNativeUI::Text()); StatsColumn->AddChildToVerticalBox(DetailStatsText);

    UBorder* ValueCard = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("VendorValueCard")); DMFNativeUI::StylePanel(ValueCard, DMFNativeUI::SlotEmpty(), FMargin(12)); DetailsScrollContent->AddChildToVerticalBox(ValueCard)->SetPadding(FMargin(0,0,0,2));
    UVerticalBox* ValueColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VendorValueColumn")); ValueCard->AddChild(ValueColumn);
    UTextBlock* ValueHeading = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorValueHeading")); ValueHeading->SetText(NSLOCTEXT("DMF","VendorValueHeading","MARKET VALUATION")); DMFNativeUI::StyleText(ValueHeading, 11, DMFNativeUI::Gold(), true); ValueColumn->AddChildToVerticalBox(ValueHeading)->SetPadding(FMargin(0,0,0,6));
    DetailValueText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailValueText")); DetailValueText->SetAutoWrapText(true); DMFNativeUI::StyleText(DetailValueText, 12, DMFNativeUI::Accent()); ValueColumn->AddChildToVerticalBox(DetailValueText);

    USizeBox* TransactionSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("VendorTransactionSize")); TransactionSize->SetMinDesiredHeight(44.0f); Details->AddChildToVerticalBox(TransactionSize)->SetPadding(FMargin(0,2,0,6));
    TransactionButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("TransactionButton")); DMFNativeUI::StyleButton(TransactionButton, true); TransactionSize->AddChild(TransactionButton);
    TransactionButtonText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TransactionButtonText")); TransactionButtonText->SetJustification(ETextJustify::Center); DMFNativeUI::StyleText(TransactionButtonText, 15, DMFNativeUI::Text(), true); TransactionButton->AddChild(TransactionButtonText);

    USizeBox* CloseSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("VendorCloseSize")); CloseSize->SetMinDesiredHeight(38.0f); Details->AddChildToVerticalBox(CloseSize);
    CloseButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("VendorCloseButton")); DMFNativeUI::StyleButton(CloseButton); CloseSize->AddChild(CloseButton);
    UTextBlock* CloseLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); CloseLabel->SetText(NSLOCTEXT("DMF","VendorClose","CLOSE")); CloseLabel->SetJustification(ETextJustify::Center); DMFNativeUI::StyleText(CloseLabel, 13, DMFNativeUI::Text(), true); CloseButton->AddChild(CloseLabel);

    VendorStatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VendorStatusText")); VendorStatusText->SetText(NSLOCTEXT("DMF","VendorStatusReady","Select a Digimon to inspect its full market value.")); VendorStatusText->SetAutoWrapText(true); DMFNativeUI::StyleText(VendorStatusText, 12, DMFNativeUI::Muted()); Column->AddChildToVerticalBox(VendorStatusText)->SetPadding(FMargin(2,10,2,0));
}

void UDMFDigimonVendorWidget::ResetTransactionConfirmation()
{
    bTransactionConfirmationArmed = false;
    ConfirmationIdentifier.Invalidate();
}

void UDMFDigimonVendorWidget::SetVendorTab(const EDMFDigimonVendorTransactionType NewTab)
{
    if (CurrentTab == NewTab) return;
    CurrentTab = NewTab;
    SelectedIdentifier.Invalidate();
    ResetTransactionConfirmation();
    DMFNativeUI::StyleButton(BuyTabButton, false, false, CurrentTab == EDMFDigimonVendorTransactionType::Buy);
    DMFNativeUI::StyleButton(SellTabButton, false, false, CurrentTab == EDMFDigimonVendorTransactionType::Sell);
    RefreshVendorUI();
}

void UDMFDigimonVendorWidget::RefreshHeader()
{
    ADMFDigimonVendorActor* V = Vendor.Get();
    if (VendorNameText) VendorNameText->SetText(V ? V->VendorDisplayName : NSLOCTEXT("DMF","VendorUnavailableTitle","DIGIMON VENDOR UNAVAILABLE"));
    if (VendorSubtitleText) VendorSubtitleText->SetText(V ? V->VendorSubtitle : FText::GetEmpty());
    if (MoneyText) MoneyText->SetText(FText::Format(NSLOCTEXT("DMF","VendorMoneyFmt","BITS  {0}"), FText::AsNumber(DigimonComponent.IsValid() ? DigimonComponent->GetMoney() : 0)));
    if (RotationText) RotationText->SetText(FText::FromString(V ? FormatRotationSeconds(V->GetSecondsUntilStockRotation()) : TEXT("OFFLINE")));
}

void UDMFDigimonVendorWidget::RefreshVendorUI()
{
    RebindSources();
    RefreshHeader();
    RefreshEntryList();
    RefreshDetails();
    BP_OnVendorRefreshed();
}

void UDMFDigimonVendorWidget::RefreshEntryList()
{
    if (!EntryListBox || !WidgetTree) return;
    EntryListBox->ClearChildren();
    ADMFDigimonVendorActor* V = Vendor.Get();
    if (!V || !DigimonComponent.IsValid()) return;

    struct FRow { FGuid Id; FDMFDigimonInstance Digimon; int64 Price=0; EDMFDigimonStorageLocation Storage=EDMFDigimonStorageLocation::Party; };
    TArray<FRow> Rows;
    if (CurrentTab == EDMFDigimonVendorTransactionType::Buy)
    {
        for (const FDMFDigimonVendorStockItem& Item : V->GetVendorStock()) { FRow& R=Rows.AddDefaulted_GetRef(); R.Id=Item.StockId; R.Digimon=Item.Digimon; R.Price=Item.PurchasePrice; }
    }
    else
    {
        for (const FDMFDigimonInstance& D : DigimonComponent->GetPartyDigimon()) { FRow& R=Rows.AddDefaulted_GetRef(); R.Id=D.InstanceId; R.Digimon=D; R.Price=V->GetPlayerSellPrice(D); R.Storage=EDMFDigimonStorageLocation::Party; }
        for (const FDMFDigimonInstance& D : DigimonComponent->GetBankDigimon()) { FRow& R=Rows.AddDefaulted_GetRef(); R.Id=D.InstanceId; R.Digimon=D; R.Price=V->GetPlayerSellPrice(D); R.Storage=EDMFDigimonStorageLocation::Bank; }
    }

    for (const FRow& Row : Rows)
    {
        UDMFDigimonSpeciesData* Species = ResolveVendorSpecies(Row.Digimon.SpeciesId);
        UDMFDigimonVendorEntryButton* Button = WidgetTree->ConstructWidget<UDMFDigimonVendorEntryButton>(UDMFDigimonVendorEntryButton::StaticClass());
        Button->InitializeVendorEntry(CurrentTab, Row.Id); Button->OnVendorEntryPressed.AddDynamic(this, &UDMFDigimonVendorWidget::HandleEntryPressed);
        DMFNativeUI::StyleButton(Button, false, false, SelectedIdentifier == Row.Id);
        USizeBox* RowMinSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass()); RowMinSize->SetMinDesiredHeight(70.0f); Button->AddChild(RowMinSize);
        UHorizontalBox* RowBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass()); RowMinSize->AddChild(RowBox);
        USizeBox* IconSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass()); IconSize->SetWidthOverride(60); IconSize->SetHeightOverride(60); RowBox->AddChildToHorizontalBox(IconSize)->SetPadding(FMargin(2,2,12,2));
        UScaleBox* IconScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass()); IconScale->SetStretch(EStretch::ScaleToFit); IconSize->AddChild(IconScale);
        UImage* Icon = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass()); if(Species){ if(UTexture2D* Portrait=Species->Portrait.LoadSynchronous()) Icon->SetBrushFromTexture(Portrait,true); } IconScale->AddChild(Icon);
        UVerticalBox* Labels = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass()); if(UHorizontalBoxSlot* S=RowBox->AddChildToHorizontalBox(Labels)){S->SetSize(DMFNativeUI::FillSize());S->SetVerticalAlignment(VAlign_Center);}
        UTextBlock* Name = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); Name->SetText(Species ? Species->DisplayName : FText::FromString(Row.Digimon.SpeciesId.PrimaryAssetName.ToString())); DMFNativeUI::StyleText(Name,16,DMFNativeUI::Text(),true); Labels->AddChildToVerticalBox(Name);
        const FText Stage = Species ? UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage) : FText::GetEmpty();
        UTextBlock* Meta = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); Meta->SetText(FText::Format(NSLOCTEXT("DMF","VendorRowMetaFmtPolished","Lv.{0}  •  {1}  •  ABI {2}"),FText::AsNumber(Row.Digimon.Stats.Level),Stage,FText::AsNumber(Row.Digimon.Stats.ABI))); DMFNativeUI::StyleText(Meta,12,DMFNativeUI::Muted()); Labels->AddChildToVerticalBox(Meta)->SetPadding(FMargin(0,2,6,0));

        USizeBox* QuoteSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass()); QuoteSize->SetWidthOverride(148.0f); if(UHorizontalBoxSlot* S=RowBox->AddChildToHorizontalBox(QuoteSize)){S->SetVerticalAlignment(VAlign_Center);S->SetPadding(FMargin(8,0,2,0));}
        UVerticalBox* QuoteColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass()); QuoteSize->AddChild(QuoteColumn);
        UTextBlock* QuoteHeading = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); QuoteHeading->SetText(CurrentTab==EDMFDigimonVendorTransactionType::Buy?NSLOCTEXT("DMF","VendorBuyPriceHeading","BUY PRICE"):NSLOCTEXT("DMF","VendorSellPriceHeading","SELL QUOTE")); QuoteHeading->SetJustification(ETextJustify::Right); DMFNativeUI::StyleText(QuoteHeading,10,DMFNativeUI::Muted(),true); QuoteColumn->AddChildToVerticalBox(QuoteHeading);
        UTextBlock* Price = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); Price->SetText(FText::Format(CurrentTab==EDMFDigimonVendorTransactionType::Buy?NSLOCTEXT("DMF","VendorBuyPriceFmtPolished","{0} BITS"):NSLOCTEXT("DMF","VendorSellPriceFmtPolished","+{0} BITS"),FText::AsNumber(Row.Price))); Price->SetJustification(ETextJustify::Right); DMFNativeUI::StyleText(Price,15,DMFNativeUI::Gold(),true); QuoteColumn->AddChildToVerticalBox(Price)->SetPadding(FMargin(0,1,0,0));
        if (CurrentTab == EDMFDigimonVendorTransactionType::Sell)
        {
            UTextBlock* Storage = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); Storage->SetText(Row.Storage==EDMFDigimonStorageLocation::Party?NSLOCTEXT("DMF","VendorPartyStorageTag","PARTY"):NSLOCTEXT("DMF","VendorBankStorageTag","BANK")); Storage->SetJustification(ETextJustify::Right); DMFNativeUI::StyleText(Storage,10,DMFNativeUI::Accent(),true); QuoteColumn->AddChildToVerticalBox(Storage)->SetPadding(FMargin(0,1,0,0));
        }
        EntryListBox->AddChildToVerticalBox(Button)->SetPadding(FMargin(0,0,0,8));
    }

    if (!SelectedIdentifier.IsValid() && !Rows.IsEmpty()) SelectedIdentifier = Rows[0].Id;
}

bool UDMFDigimonVendorWidget::ResolveSelectedDigimon(FDMFDigimonInstance& OutDigimon, int64& OutPrice, EDMFDigimonStorageLocation& OutStorage, FText& OutBlockReason) const
{
    OutDigimon = FDMFDigimonInstance(); OutPrice = 0; OutStorage = EDMFDigimonStorageLocation::Party; OutBlockReason=FText::GetEmpty();
    ADMFDigimonVendorActor* V = Vendor.Get(); if(!V || !DigimonComponent.IsValid() || !SelectedIdentifier.IsValid()) return false;
    if(CurrentTab==EDMFDigimonVendorTransactionType::Buy)
    {
        const FDMFDigimonVendorStockItem* Item=V->ReplicatedStock.FindByPredicate([&](const FDMFDigimonVendorStockItem& X){return X.StockId==SelectedIdentifier;}); if(!Item)return false; OutDigimon=Item->Digimon;OutPrice=Item->PurchasePrice;
        if(!V->bVendorEnabled||!V->bAllowBuying)OutBlockReason=NSLOCTEXT("DMF","VendorBuyBlocked","Buying is currently unavailable.");
        else if(DigimonComponent->GetMoney()<OutPrice)OutBlockReason=NSLOCTEXT("DMF","VendorNotEnoughBits","Not enough Bits for this Digimon.");
        else if(DigimonComponent->GetPartyDigimon().Num()>=DigimonComponent->GetPartyCapacity()&&DigimonComponent->GetBankDigimon().Num()>=DigimonComponent->GetBankCapacity())OutBlockReason=NSLOCTEXT("DMF","VendorStorageFullUI","Party and Bank are full.");
        return true;
    }
    if(!DigimonComponent->GetOwnedDigimonByInstanceId(SelectedIdentifier,OutDigimon,OutStorage))return false; OutPrice=V->GetPlayerSellPrice(OutDigimon);
    if(!V->bVendorEnabled||!V->bAllowSelling)OutBlockReason=NSLOCTEXT("DMF","VendorSellBlocked","Selling is currently unavailable.");
    else if(OutDigimon.bStarterPartner&&!V->bAllowSellingStarterDigimon)OutBlockReason=NSLOCTEXT("DMF","VendorStarterProtectedUI","Starter partners are protected by this vendor.");
    else if(OutStorage==EDMFDigimonStorageLocation::Party&&V->bRequireAtLeastOnePartyDigimon&&DigimonComponent->GetPartyDigimon().Num()<=1)OutBlockReason=NSLOCTEXT("DMF","VendorLastPartyProtectedUI","You must keep at least one Digimon in your Party.");
    return true;
}

void UDMFDigimonVendorWidget::RefreshDetails()
{
    FDMFDigimonInstance D; int64 Price=0; EDMFDigimonStorageLocation Storage=EDMFDigimonStorageLocation::Party; FText Block;
    const bool bResolved=ResolveSelectedDigimon(D,Price,Storage,Block); UDMFDigimonSpeciesData* Species=bResolved?ResolveVendorSpecies(D.SpeciesId):nullptr;
    if(DetailPortrait){DetailPortrait->SetVisibility(Species&&Species->Portrait.LoadSynchronous()?ESlateVisibility::Visible:ESlateVisibility::Hidden);if(Species){if(UTexture2D* P=Species->Portrait.LoadSynchronous())DetailPortrait->SetBrushFromTexture(P,true);}}
    if(DetailNameText)DetailNameText->SetText(bResolved?(Species?Species->DisplayName:FText::FromString(D.SpeciesId.PrimaryAssetName.ToString())):NSLOCTEXT("DMF","VendorSelectPrompt","SELECT A DIGIMON"));
    if(DetailMetaText)DetailMetaText->SetText(bResolved&&Species?FText::Format(NSLOCTEXT("DMF","VendorDetailMetaFmt","Lv.{0}  •  {1}  •  {2}"),FText::AsNumber(D.Stats.Level),UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage),AttributeText(Species->Attribute)):FText::GetEmpty());
    if(DetailStatsText)
    {
        if (bResolved)
        {
            DetailStatsText->SetText(FText::FromString(FString::Printf(
                TEXT("HP %d  •  SP %d\nSTR %d  •  INT %d\nDEF %d  •  SPD %d\n\nABI %d  •  CAM %d\nSpent Attribute Points: %d\nUnspent Attribute Points: %d\nLifetime Battle EXP: %s\nDigivolution Forms Visited: %d"),
                D.Stats.MaxHP, D.Stats.MaxSP,
                D.Stats.Strength, D.Stats.Intelligence,
                D.Stats.Defense, D.Stats.Speed,
                D.Stats.ABI, D.Stats.CAM,
                D.TotalAttributePointsSpent,
                D.UnspentAttributePoints,
                *FText::AsNumber(D.LifetimeBattleExperience).ToString(),
                FMath::Max(1, D.DigivolutionHistory.Num()))));
        }
        else
        {
            DetailStatsText->SetText(NSLOCTEXT("DMF","VendorDetailPrompt","Choose a stock offer or one of your owned Digimon."));
        }
    }
    if(DetailValueText)
    {
        if(bResolved&&Vendor.IsValid())
        {
            const FDMFDigimonVendorValueBreakdown B=Vendor->CalculateDigimonValue(D);
            DetailValueText->SetText(FText::FromString(FString::Printf(
                TEXT("Market Value: %s Bits\nLevel: +%s  •  Battle EXP: +%s\nStats: +%s\nABI: +%s  •  CAM: +%s\nTraining: +%s  •  History: +%s\n\n%s PRICE: %s BITS"),
                *FText::AsNumber(B.MarketValue).ToString(),
                *FText::AsNumber(B.LevelValue).ToString(),
                *FText::AsNumber(B.ExperienceValue).ToString(),
                *FText::AsNumber(B.StatsValue).ToString(),
                *FText::AsNumber(B.ABIValue).ToString(),
                *FText::AsNumber(B.CAMValue).ToString(),
                *FText::AsNumber(B.AttributeTrainingValue).ToString(),
                *FText::AsNumber(B.DigivolutionHistoryValue).ToString(),
                CurrentTab==EDMFDigimonVendorTransactionType::Buy?TEXT("BUY"):TEXT("SELL"),
                *FText::AsNumber(Price).ToString())));
        }
        else DetailValueText->SetText(FText::GetEmpty());
    }
    if(TransactionButtonText)
    {
        const bool bConfirming = bTransactionConfirmationArmed && ConfirmationTransactionType == CurrentTab && ConfirmationIdentifier == SelectedIdentifier;
        if (bConfirming)
        {
            TransactionButtonText->SetText(CurrentTab==EDMFDigimonVendorTransactionType::Buy
                ? FText::Format(NSLOCTEXT("DMF","VendorConfirmBuyButtonFmt","CONFIRM BUY • {0} BITS"),FText::AsNumber(Price))
                : FText::Format(NSLOCTEXT("DMF","VendorConfirmSellButtonFmt","CONFIRM SELL • +{0} BITS"),FText::AsNumber(Price)));
        }
        else
        {
            TransactionButtonText->SetText(CurrentTab==EDMFDigimonVendorTransactionType::Buy
                ? FText::Format(NSLOCTEXT("DMF","VendorBuyButtonFmt","BUY • {0} BITS"),FText::AsNumber(Price))
                : FText::Format(NSLOCTEXT("DMF","VendorSellButtonFmt","SELL • +{0} BITS"),FText::AsNumber(Price)));
        }
    }
    if(TransactionButton)TransactionButton->SetIsEnabled(bResolved&&Block.IsEmpty());
    if(VendorStatusText&&!Block.IsEmpty()){VendorStatusText->SetText(Block);VendorStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Danger()));}
    else if(VendorStatusText){VendorStatusText->SetText(CurrentTab==EDMFDigimonVendorTransactionType::Buy?NSLOCTEXT("DMF","VendorBuyReady","Server-authoritative offer. Purchased Digimon is saved immediately to Party/Bank."):NSLOCTEXT("DMF","VendorSellReady","Sale value automatically rewards level, battle experience, stats, ABI, Attribute Point investment and Digivolution history."));VendorStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));}
}

void UDMFDigimonVendorWidget::HandleBuyTabClicked() { SetVendorTab(EDMFDigimonVendorTransactionType::Buy); }
void UDMFDigimonVendorWidget::HandleSellTabClicked() { SetVendorTab(EDMFDigimonVendorTransactionType::Sell); }

void UDMFDigimonVendorWidget::HandleEntryPressed(const EDMFDigimonVendorTransactionType TransactionType, const FGuid Identifier)
{
    CurrentTab = TransactionType;
    SelectedIdentifier = Identifier;
    ResetTransactionConfirmation();
    RefreshEntryList();
    RefreshDetails();
    BP_OnVendorSelectionChanged(TransactionType, Identifier);
}

void UDMFDigimonVendorWidget::HandleTransactionClicked()
{
    ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer());
    if (!PC || !Vendor.IsValid() || !SelectedIdentifier.IsValid())
    {
        return;
    }

    FDMFDigimonInstance Digimon;
    int64 Price = 0;
    EDMFDigimonStorageLocation Storage = EDMFDigimonStorageLocation::Party;
    FText BlockReason;
    if (!ResolveSelectedDigimon(Digimon, Price, Storage, BlockReason) || !BlockReason.IsEmpty())
    {
        RefreshDetails();
        return;
    }

    const bool bAlreadyArmed = bTransactionConfirmationArmed
        && ConfirmationTransactionType == CurrentTab
        && ConfirmationIdentifier == SelectedIdentifier;
    if (!bAlreadyArmed)
    {
        bTransactionConfirmationArmed = true;
        ConfirmationTransactionType = CurrentTab;
        ConfirmationIdentifier = SelectedIdentifier;
        RefreshDetails();
        if (VendorStatusText)
        {
            VendorStatusText->SetText(CurrentTab == EDMFDigimonVendorTransactionType::Buy
                ? NSLOCTEXT("DMF", "VendorConfirmBuyPrompt", "Review this Digimon and press CONFIRM BUY to complete the server-authoritative purchase.")
                : NSLOCTEXT("DMF", "VendorConfirmSellPrompt", "Selling permanently removes this individual from your collection. Press CONFIRM SELL to continue."));
            VendorStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Gold()));
        }
        return;
    }

    ResetTransactionConfirmation();
    PC->RequestDigimonVendorTransaction(Vendor.Get(), CurrentTab, SelectedIdentifier);
}

void UDMFDigimonVendorWidget::HandleCloseClicked()
{
    if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        PC->CloseDigimonVendorUI();
    }
}

void UDMFDigimonVendorWidget::HandleVendorStockChanged()
{
    ResetTransactionConfirmation();
    RefreshVendorUI();
}

void UDMFDigimonVendorWidget::HandleVendorEnabledChanged(bool)
{
    ResetTransactionConfirmation();
    RefreshVendorUI();
}

void UDMFDigimonVendorWidget::HandleVendorConfigurationChanged()
{
    ResetTransactionConfirmation();
    RefreshVendorUI();
}

void UDMFDigimonVendorWidget::HandlePartyChanged()
{
    if (CurrentTab == EDMFDigimonVendorTransactionType::Sell)
    {
        ResetTransactionConfirmation();
        RefreshVendorUI();
    }
}

void UDMFDigimonVendorWidget::HandleBankChanged()
{
    if (CurrentTab == EDMFDigimonVendorTransactionType::Sell)
    {
        ResetTransactionConfirmation();
        RefreshVendorUI();
    }
}

void UDMFDigimonVendorWidget::HandleMoneyChanged(int64)
{
    RefreshHeader();
    RefreshDetails();
}

void UDMFDigimonVendorWidget::HandleVendorTransactionResult(const bool bSuccess, const FText Message, const EDMFDigimonVendorTransactionType, const FGuid, const int64, const int64)
{
    ResetTransactionConfirmation();
    if (bSuccess)
    {
        SelectedIdentifier.Invalidate();
    }
    RefreshHeader();
    RefreshEntryList();
    RefreshDetails();
    if (VendorStatusText)
    {
        VendorStatusText->SetText(Message);
        VendorStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
}

void UDMFDigimonVendorWidget::HandleHeaderTimer()
{
    RefreshHeader();
    if (!Vendor.IsValid() || !Vendor->IsVendorEnabled())
    {
        HandleCloseClicked();
        return;
    }
    if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        if (!Vendor->IsPlayerWithinTradeRange(PC))
        {
            HandleCloseClicked();
        }
    }
}
