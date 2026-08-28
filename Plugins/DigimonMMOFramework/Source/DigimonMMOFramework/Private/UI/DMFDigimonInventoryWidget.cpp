#include "UI/DMFDigimonInventoryWidget.h"
#include "Utility/DMFDigimonPresentationLibrary.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/ProgressBar.h"
#include "Components/ScaleBox.h"
#include "Components/ScrollBox.h"
#include "Components/SizeBox.h"
#include "Components/Spacer.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Data/DMFDigimonAbilityData.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Data/DMFStarterRosterData.h"
#include "Engine/AssetManager.h"
#include "Engine/Texture2D.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFDigimonInventoryEntryButton.h"
#include "UI/DMFScanSpeciesEntryButton.h"
#include "UI/DMFNativeUIStyle.h"
#include "UI/DMFPartyDestinationButton.h"

namespace DMFInventoryUI
{
    constexpr int32 Columns = 6;
    constexpr float SlotSize = 122.0f;
    constexpr float BankSlotSize = 96.0f;
    constexpr float PartyDestinationSlotWidth = 120.0f;
    constexpr int32 DigivolutionOwnedColumns = 3;
    constexpr float DigivolutionOwnedCardWidth = 132.0f;
    constexpr float DigivolutionOwnedCardHeight = 166.0f;
    constexpr float DigivolutionOwnedPortraitSize = 104.0f;
    constexpr int32 DigiDexColumns = 4;
    constexpr float DigiDexCardWidth = 174.0f;
    constexpr float DigiDexCardHeight = 196.0f;
    constexpr float DigiDexPortraitSize = 128.0f;

    FText EnumDisplay(const UEnum* EnumType, const int64 Value)
    {
        return EnumType ? EnumType->GetDisplayNameTextByValue(Value) : FText::GetEmpty();
    }
}

TSharedRef<SWidget> UDMFDigimonInventoryWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFDigimonInventoryWidgetTree"));
    }

    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }

    return Super::RebuildWidget();
}

void UDMFDigimonInventoryWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (SummonDigimonButton)
    {
        SummonDigimonButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSummonSelected);
    }
    if (RecallDigimonButton)
    {
        RecallDigimonButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleRecallPartner);
    }
    if (MoveSelectedToBankButton)
    {
        MoveSelectedToBankButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleMoveSelectedToBank);
    }
    if (CloseDigimonInventoryButton)
    {
        CloseDigimonInventoryButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleClose);
    }
    if (CollectionTabButton)
    {
        CollectionTabButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleCollectionTab);
    }
    if (BankTabButton)
    {
        BankTabButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleBankTab);
    }
    if (ScanMaterializeTabButton)
    {
        ScanMaterializeTabButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleScanMaterializeTab);
    }
    if (CareTabButton)
    {
        CareTabButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleCareTab);
    }
    if (DigivolutionTabButton)
    {
        DigivolutionTabButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleDigivolutionTab);
    }
    if (DigiDexTabButton)
    {
        DigiDexTabButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleDigiDexTab);
    }
    if (DigiDexSearchBox)
    {
        DigiDexSearchBox->OnTextChanged.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleDigiDexSearchChanged);
    }
    if (DigiDexStageFilterButton)
    {
        DigiDexStageFilterButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleDigiDexStageFilter);
    }
    if (DigiDexAttributeFilterButton)
    {
        DigiDexAttributeFilterButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleDigiDexAttributeFilter);
    }
    if (FeedDigiMeatButton)
    {
        FeedDigiMeatButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleFeedDigiMeat);
    }
    if (MaterializeDigimonButton)
    {
        MaterializeDigimonButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleMaterializeSelected);
    }
    if (DigivolveButton)
    {
        DigivolveButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleDigivolveSelected);
    }
    if (BankPreviousPageButton)
    {
        BankPreviousPageButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleBankPreviousPage);
    }
    if (BankNextPageButton)
    {
        BankNextPageButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleBankNextPage);
    }
    if (MoveSelectedBankToPartyButton)
    {
        MoveSelectedBankToPartyButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleMoveSelectedBankToParty);
    }
    if (SpendPartyHPButton) SpendPartyHPButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendPartyHP);
    if (SpendPartySPButton) SpendPartySPButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendPartySP);
    if (SpendPartyStrengthButton) SpendPartyStrengthButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendPartyStrength);
    if (SpendPartyIntelligenceButton) SpendPartyIntelligenceButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendPartyIntelligence);
    if (SpendPartyDefenseButton) SpendPartyDefenseButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendPartyDefense);
    if (SpendPartySpeedButton) SpendPartySpeedButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendPartySpeed);
    if (SpendBankHPButton) SpendBankHPButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendBankHP);
    if (SpendBankSPButton) SpendBankSPButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendBankSP);
    if (SpendBankStrengthButton) SpendBankStrengthButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendBankStrength);
    if (SpendBankIntelligenceButton) SpendBankIntelligenceButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendBankIntelligence);
    if (SpendBankDefenseButton) SpendBankDefenseButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendBankDefense);
    if (SpendBankSpeedButton) SpendBankSpeedButton->OnClicked.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleSpendBankSpeed);

    BindDigimonComponent();
    RefreshInventory();
    RefreshBankData();
    RefreshScanData();
    RefreshCareData();
    RefreshDigivolutionData();
    RefreshDigiDexData();
    RefreshTabPresentation();
}

void UDMFDigimonInventoryWidget::NativeDestruct()
{
    if (BoundDigimonComponent)
    {
        BoundDigimonComponent->OnDigimonInventoryChanged.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleInventoryChanged);
        BoundDigimonComponent->OnDigimonBankChanged.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleBankChanged);
        BoundDigimonComponent->OnDigimonStorageActionResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleStorageActionResult);
        BoundDigimonComponent->OnAttributePointSpendResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleAttributePointSpendResult);
        BoundDigimonComponent->OnPartnerActionResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandlePartnerActionResult);
        BoundDigimonComponent->OnScanDataChanged.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleScanDataChanged);
        BoundDigimonComponent->OnMaterializationResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleMaterializationResult);
        BoundDigimonComponent->OnCareStateChanged.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleCareStateChanged);
        BoundDigimonComponent->OnCareSequenceFinished.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleCareSequenceFinished);
        BoundDigimonComponent->OnDigivolutionResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleDigivolutionResult);
    }
    BoundDigimonComponent = nullptr;
    Super::NativeDestruct();
}

void UDMFDigimonInventoryWidget::BuildNativeFallbackUI()
{
    if (!WidgetTree)
    {
        return;
    }

    auto MakeAttributeSpendButton = [this](const FName WidgetName, const FText& LabelText) -> UButton*
    {
        UButton* Button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), WidgetName);
        DMFNativeUI::StyleButton(Button);
        UTextBlock* Label = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        Label->SetText(LabelText);
        Label->SetJustification(ETextJustify::Center);
        DMFNativeUI::StyleText(Label, 11, DMFNativeUI::Accent(), true);
        Button->AddChild(Label);
        return Button;
    };

    UOverlay* RootOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("InventoryRootOverlay"));
    WidgetTree->RootWidget = RootOverlay;

    UBorder* BackdropBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("InventoryBackdrop"));
    DMFNativeUI::StylePanel(BackdropBorder, DMFNativeUI::Backdrop(), FMargin(0.0f));
    if (UOverlaySlot* BackdropSlot = RootOverlay->AddChildToOverlay(BackdropBorder))
    {
        BackdropSlot->SetHorizontalAlignment(HAlign_Fill);
        BackdropSlot->SetVerticalAlignment(VAlign_Fill);
    }

    UScaleBox* ScreenScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("InventoryScreenScale"));
    ScreenScale->SetStretch(EStretch::ScaleToFit);
    ScreenScale->SetStretchDirection(EStretchDirection::DownOnly);
    if (UOverlaySlot* ScaleSlot = RootOverlay->AddChildToOverlay(ScreenScale))
    {
        ScaleSlot->SetHorizontalAlignment(HAlign_Center);
        ScaleSlot->SetVerticalAlignment(VAlign_Center);
        ScaleSlot->SetPadding(FMargin(24.0f));
    }

    USizeBox* WindowSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("InventoryWindowSize"));
    WindowSize->SetWidthOverride(1240.0f);
    WindowSize->SetHeightOverride(900.0f);
    ScreenScale->AddChild(WindowSize);

    UBorder* WindowBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("InventoryWindowBorder"));
    DMFNativeUI::StylePanel(WindowBorder, DMFNativeUI::Panel(), FMargin(18.0f));
    // The menu has grown into a multi-system shell. Hard clipping plus ScaleToFit guarantees that no tab
    // can visually escape the window on low-height/DPI-scaled viewports even when content is project-authored.
    WindowBorder->SetClipping(EWidgetClipping::ClipToBoundsAlways);
    WindowSize->AddChild(WindowBorder);

    UVerticalBox* WindowColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("InventoryWindowColumn"));
    WindowBorder->AddChild(WindowColumn);

    UHorizontalBox* HeaderRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("InventoryHeaderRow"));
    WindowColumn->AddChildToVerticalBox(HeaderRow)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 10.0f));

    UVerticalBox* HeadingColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("InventoryHeadingColumn"));
    if (UHorizontalBoxSlot* HeadingSlot = HeaderRow->AddChildToHorizontalBox(HeadingColumn))
    {
        HeadingSlot->SetSize(DMFNativeUI::FillSize());
        HeadingSlot->SetVerticalAlignment(VAlign_Center);
    }

    UTextBlock* TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("InventoryTitle"));
    TitleText->SetText(NSLOCTEXT("DMF", "InventoryPolishedTitle", "DIGIMON MENU"));
    DMFNativeUI::StyleText(TitleText, 30, DMFNativeUI::Text(), true);
    HeadingColumn->AddChildToVerticalBox(TitleText);

    DigimonStatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigimonStatusText"));
    DigimonStatusText->SetText(NSLOCTEXT("DMF", "DigimonMenuPrompt", "Manage your Party, Bank, Scan Database, DigiDex, Digivolution paths and Care systems from anywhere in the Digital World."));
    DMFNativeUI::StyleText(DigimonStatusText, 14, DMFNativeUI::Muted());
    DigimonStatusText->SetAutoWrapText(true);
    HeadingColumn->AddChildToVerticalBox(DigimonStatusText);

    CloseDigimonInventoryButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("CloseDigimonInventoryButton"));
    DMFNativeUI::StyleButton(CloseDigimonInventoryButton);
    UTextBlock* HeaderCloseLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("HeaderCloseLabel"));
    HeaderCloseLabel->SetText(NSLOCTEXT("DMF", "CloseDigimonInventoryShort", "CLOSE  [I]"));
    DMFNativeUI::StyleText(HeaderCloseLabel, 14, DMFNativeUI::Text(), true);
    CloseDigimonInventoryButton->AddChild(HeaderCloseLabel);
    if (UHorizontalBoxSlot* CloseSlot = HeaderRow->AddChildToHorizontalBox(CloseDigimonInventoryButton))
    {
        CloseSlot->SetHorizontalAlignment(HAlign_Right);
        CloseSlot->SetVerticalAlignment(VAlign_Center);
    }

    UHorizontalBox* TabRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("DigimonMenuTabRow"));
    WindowColumn->AddChildToVerticalBox(TabRow)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 12.0f));

    CollectionTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("CollectionTabButton"));
    DMFNativeUI::StyleButton(CollectionTabButton, false, false, true);
    UTextBlock* CollectionTabLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CollectionTabLabel"));
    CollectionTabLabel->SetText(NSLOCTEXT("DMF", "PartyTabLabel", "PARTY"));
    DMFNativeUI::StyleText(CollectionTabLabel, 15, DMFNativeUI::Text(), true);
    CollectionTabButton->AddChild(CollectionTabLabel);
    TabRow->AddChildToHorizontalBox(CollectionTabButton)->SetPadding(FMargin(0,0,8,0));

    BankTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("BankTabButton"));
    DMFNativeUI::StyleButton(BankTabButton);
    UTextBlock* BankTabLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankTabLabel"));
    BankTabLabel->SetText(NSLOCTEXT("DMF", "BankTabLabel", "BANK / BOXES"));
    DMFNativeUI::StyleText(BankTabLabel, 15, DMFNativeUI::Text(), true);
    BankTabButton->AddChild(BankTabLabel);
    TabRow->AddChildToHorizontalBox(BankTabButton)->SetPadding(FMargin(0,0,8,0));

    ScanMaterializeTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("ScanMaterializeTabButton"));
    DMFNativeUI::StyleButton(ScanMaterializeTabButton);
    UTextBlock* ScanTabLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ScanTabLabel"));
    ScanTabLabel->SetText(NSLOCTEXT("DMF", "ScanMaterializeTabLabel", "SCAN & MATERIALIZE"));
    DMFNativeUI::StyleText(ScanTabLabel, 15, DMFNativeUI::Text(), true);
    ScanMaterializeTabButton->AddChild(ScanTabLabel);
    TabRow->AddChildToHorizontalBox(ScanMaterializeTabButton)->SetPadding(FMargin(0,0,8,0));

    DigiDexTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("DigiDexTabButton"));
    DMFNativeUI::StyleButton(DigiDexTabButton);
    UTextBlock* DigiDexTabLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexTabLabel"));
    DigiDexTabLabel->SetText(NSLOCTEXT("DMF", "DigiDexTabLabel", "DIGIDEX"));
    DMFNativeUI::StyleText(DigiDexTabLabel, 15, DMFNativeUI::Text(), true);
    DigiDexTabButton->AddChild(DigiDexTabLabel);
    TabRow->AddChildToHorizontalBox(DigiDexTabButton)->SetPadding(FMargin(0,0,8,0));

    DigivolutionTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("DigivolutionTabButton"));
    DMFNativeUI::StyleButton(DigivolutionTabButton);
    UTextBlock* DigivolutionTabLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionTabLabel"));
    DigivolutionTabLabel->SetText(NSLOCTEXT("DMF", "DigivolutionTabLabel", "DIGIVOLUTION"));
    DMFNativeUI::StyleText(DigivolutionTabLabel, 15, DMFNativeUI::Text(), true);
    DigivolutionTabButton->AddChild(DigivolutionTabLabel);
    TabRow->AddChildToHorizontalBox(DigivolutionTabButton)->SetPadding(FMargin(0,0,8,0));

    CareTabButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("CareTabButton"));
    DMFNativeUI::StyleButton(CareTabButton);
    UTextBlock* CareTabLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareTabLabel"));
    CareTabLabel->SetText(NSLOCTEXT("DMF", "CareTabLabel", "CARE"));
    DMFNativeUI::StyleText(CareTabLabel, 15, DMFNativeUI::Text(), true);
    CareTabButton->AddChild(CareTabLabel);
    TabRow->AddChildToHorizontalBox(CareTabButton);

    UTextBlock* FutureTabsLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("FutureTabsLabel"));
    FutureTabsLabel->SetText(NSLOCTEXT("DMF", "FutureTabsLabel", "FUTURE MODULES"));
    DMFNativeUI::StyleText(FutureTabsLabel, 11, DMFNativeUI::Muted(), true);
    if (UHorizontalBoxSlot* FutureSlot = TabRow->AddChildToHorizontalBox(FutureTabsLabel)) { FutureSlot->SetSize(DMFNativeUI::FillSize()); FutureSlot->SetVerticalAlignment(VAlign_Center); FutureSlot->SetHorizontalAlignment(HAlign_Right); }

    InventoryContentRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("InventoryMainRow"));
    if (UVerticalBoxSlot* MainRowSlot = WindowColumn->AddChildToVerticalBox(InventoryContentRow))
    {
        MainRowSlot->SetSize(DMFNativeUI::FillSize());
    }

    USizeBox* GridAreaSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("InventoryGridAreaSize"));
    GridAreaSize->SetWidthOverride(835.0f);
    if (UHorizontalBoxSlot* GridAreaSlot = InventoryContentRow->AddChildToHorizontalBox(GridAreaSize))
    {
        GridAreaSlot->SetPadding(FMargin(0.0f, 0.0f, 14.0f, 0.0f));
        GridAreaSlot->SetVerticalAlignment(VAlign_Fill);
    }

    UBorder* GridAreaBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("InventoryGridAreaBorder"));
    DMFNativeUI::StylePanel(GridAreaBorder, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    GridAreaSize->AddChild(GridAreaBorder);

    UVerticalBox* GridColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("InventoryGridColumn"));
    GridAreaBorder->AddChild(GridColumn);

    UHorizontalBox* GridHeader = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("InventoryGridHeader"));
    GridColumn->AddChildToVerticalBox(GridHeader)->SetPadding(FMargin(2.0f, 0.0f, 2.0f, 8.0f));

    UTextBlock* StorageTitle = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("StorageTitle"));
    StorageTitle->SetText(NSLOCTEXT("DMF", "ActiveRosterTitle", "ACTIVE PARTY"));
    DMFNativeUI::StyleText(StorageTitle, 17, DMFNativeUI::Accent(), true);
    GridHeader->AddChildToHorizontalBox(StorageTitle)->SetSize(DMFNativeUI::FillSize());

    InventoryCountText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("InventoryCountText"));
    InventoryCountText->SetText(FText::GetEmpty());
    DMFNativeUI::StyleText(InventoryCountText, 14, DMFNativeUI::Muted(), true);
    GridHeader->AddChildToHorizontalBox(InventoryCountText)->SetHorizontalAlignment(HAlign_Right);

    UScrollBox* GridScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("DigimonGridScroll"));
    if (UVerticalBoxSlot* GridScrollSlot = GridColumn->AddChildToVerticalBox(GridScroll))
    {
        GridScrollSlot->SetSize(DMFNativeUI::FillSize());
    }

    DigimonGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("DigimonGrid"));
    DigimonGrid->SetSlotPadding(FMargin(5.0f));
    GridScroll->AddChild(DigimonGrid);

    USizeBox* DetailsAreaSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("InventoryDetailsAreaSize"));
    DetailsAreaSize->SetWidthOverride(355.0f);
    InventoryContentRow->AddChildToHorizontalBox(DetailsAreaSize)->SetVerticalAlignment(VAlign_Fill);

    UBorder* DetailsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("InventoryDetailsBorder"));
    DMFNativeUI::StylePanel(DetailsBorder, DMFNativeUI::PanelRaised(), FMargin(16.0f));
    DetailsAreaSize->AddChild(DetailsBorder);

    UVerticalBox* DetailsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("InventoryDetailsColumn"));
    DetailsBorder->AddChild(DetailsColumn);

    UTextBlock* SelectedHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SelectedHeader"));
    SelectedHeader->SetText(NSLOCTEXT("DMF", "SelectedDigimonHeader", "SELECTED DIGIMON"));
    DMFNativeUI::StyleText(SelectedHeader, 14, DMFNativeUI::Accent(), true);
    DetailsColumn->AddChildToVerticalBox(SelectedHeader)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 8.0f));

    USizeBox* PortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("SelectedPortraitSize"));
    PortraitSize->SetHeightOverride(175.0f);
    PortraitSize->SetWidthOverride(320.0f);
    DetailsColumn->AddChildToVerticalBox(PortraitSize)->SetHorizontalAlignment(HAlign_Center);

    UBorder* PortraitBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("SelectedPortraitBorder"));
    DMFNativeUI::StylePanel(PortraitBorder, DMFNativeUI::SlotEmpty(), FMargin(5.0f));
    PortraitSize->AddChild(PortraitBorder);

    SelectedPortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("SelectedPortraitImage"));
    SelectedPortraitImage->SetColorAndOpacity(FLinearColor::White);
    PortraitBorder->AddChild(SelectedPortraitImage);

    SelectedNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SelectedNameText"));
    SelectedNameText->SetText(NSLOCTEXT("DMF", "NoSelectedDigimonName", "NO DIGIMON SELECTED"));
    SelectedNameText->SetJustification(ETextJustify::Center);
    SelectedNameText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(SelectedNameText, 24, DMFNativeUI::Text(), true);
    DetailsColumn->AddChildToVerticalBox(SelectedNameText)->SetPadding(FMargin(0.0f, 10.0f, 0.0f, 0.0f));

    SelectedStageText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SelectedStageText"));
    SelectedStageText->SetText(FText::GetEmpty());
    SelectedStageText->SetJustification(ETextJustify::Center);
    SelectedStageText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(SelectedStageText, 14, DMFNativeUI::Gold(), true);
    DetailsColumn->AddChildToVerticalBox(SelectedStageText);

    SelectedStateText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SelectedStateText"));
    SelectedStateText->SetText(NSLOCTEXT("DMF", "SelectDigimonState", "Choose a slot from the Party."));
    SelectedStateText->SetJustification(ETextJustify::Center);
    SelectedStateText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(SelectedStateText, 13, DMFNativeUI::Muted(), true);
    DetailsColumn->AddChildToVerticalBox(SelectedStateText)->SetPadding(FMargin(0.0f, 2.0f, 0.0f, 10.0f));

    // The Party detail body must remain reachable on short viewports.  Keep the identity/portrait
    // header fixed and give every interactive detail below it one bounded vertical scroll lane.
    // This mirrors the Bank tab's mature layout contract and prevents newly-added progression/UI
    // controls from pushing summon/recall/storage actions outside the modal.
    UScrollBox* PartyDetailsBodyScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("PartyDetailsBodyScroll"));
    if (UVerticalBoxSlot* PartyBodyScrollSlot = DetailsColumn->AddChildToVerticalBox(PartyDetailsBodyScroll))
    {
        PartyBodyScrollSlot->SetSize(DMFNativeUI::FillSize());
    }

    UVerticalBox* PartyDetailsBody = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("PartyDetailsBody"));
    PartyDetailsBodyScroll->AddChild(PartyDetailsBody);

    UBorder* StatsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("SelectedStatsBorder"));
    DMFNativeUI::StylePanel(StatsBorder, DMFNativeUI::PanelSoft(), FMargin(12.0f));
    PartyDetailsBody->AddChildToVerticalBox(StatsBorder)->SetPadding(FMargin(0.0f, 0.0f, 4.0f, 8.0f));

    UVerticalBox* StatsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("SelectedStatsColumn"));
    StatsBorder->AddChild(StatsColumn);
    DigimonDetailsText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigimonDetailsText"));
    DigimonDetailsText->SetText(NSLOCTEXT("DMF", "DigimonInventoryNoSelection", "LEVEL  --        EXP  -- / --\nHP     -- / --\nSP     -- / --\n\nSTR --     INT --\nDEF --     SPD --\nABI --     CAM --\nATTRIBUTE PTS  --"));
    DigimonDetailsText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigimonDetailsText, 15, DMFNativeUI::Text());
    StatsColumn->AddChildToVerticalBox(DigimonDetailsText);
    SelectedExperienceProgressBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("SelectedExperienceProgressBar"));
    SelectedExperienceProgressBar->SetFillColorAndOpacity(DMFNativeUI::Accent());
    SelectedExperienceProgressBar->SetPercent(0.0f);
    StatsColumn->AddChildToVerticalBox(SelectedExperienceProgressBar)->SetPadding(FMargin(0.0f, 8.0f, 0.0f, 0.0f));

    UTextBlock* PartyAttributeSpendLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PartyAttributeSpendLabel"));
    PartyAttributeSpendLabel->SetText(NSLOCTEXT("DMF", "PartyAttributeSpendLabel", "SPEND ATTRIBUTE POINTS"));
    DMFNativeUI::StyleText(PartyAttributeSpendLabel, 10, DMFNativeUI::Muted(), true);
    StatsColumn->AddChildToVerticalBox(PartyAttributeSpendLabel)->SetPadding(FMargin(0,8,0,3));
    UUniformGridPanel* PartyAttributeSpendGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("PartyAttributeSpendGrid"));
    PartyAttributeSpendGrid->SetSlotPadding(FMargin(2.0f));
    StatsColumn->AddChildToVerticalBox(PartyAttributeSpendGrid);
    SpendPartyHPButton = MakeAttributeSpendButton(TEXT("SpendPartyHPButton"), NSLOCTEXT("DMF", "SpendHPShort", "+ HP"));
    SpendPartySPButton = MakeAttributeSpendButton(TEXT("SpendPartySPButton"), NSLOCTEXT("DMF", "SpendSPShort", "+ SP"));
    SpendPartyStrengthButton = MakeAttributeSpendButton(TEXT("SpendPartyStrengthButton"), NSLOCTEXT("DMF", "SpendSTRShort", "+ STR"));
    SpendPartyIntelligenceButton = MakeAttributeSpendButton(TEXT("SpendPartyIntelligenceButton"), NSLOCTEXT("DMF", "SpendINTShort", "+ INT"));
    SpendPartyDefenseButton = MakeAttributeSpendButton(TEXT("SpendPartyDefenseButton"), NSLOCTEXT("DMF", "SpendDEFShort", "+ DEF"));
    SpendPartySpeedButton = MakeAttributeSpendButton(TEXT("SpendPartySpeedButton"), NSLOCTEXT("DMF", "SpendSPDShort", "+ SPD"));
    PartyAttributeSpendGrid->AddChildToUniformGrid(SpendPartyHPButton, 0, 0);
    PartyAttributeSpendGrid->AddChildToUniformGrid(SpendPartySPButton, 0, 1);
    PartyAttributeSpendGrid->AddChildToUniformGrid(SpendPartyStrengthButton, 0, 2);
    PartyAttributeSpendGrid->AddChildToUniformGrid(SpendPartyIntelligenceButton, 1, 0);
    PartyAttributeSpendGrid->AddChildToUniformGrid(SpendPartyDefenseButton, 1, 1);
    PartyAttributeSpendGrid->AddChildToUniformGrid(SpendPartySpeedButton, 1, 2);

    // The description participates in the same outer scroll lane; avoiding a nested vertical
    // ScrollBox keeps mouse-wheel/gamepad scrolling deterministic and lets long localized/species
    // profiles naturally increase the Party detail body's scroll extent.
    SelectedDescriptionText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SelectedDescriptionText"));
    SelectedDescriptionText->SetText(NSLOCTEXT("DMF", "SelectedDigimonDescriptionEmpty", "Select a Digimon to view its species profile and current combat state."));
    SelectedDescriptionText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(SelectedDescriptionText, 12, DMFNativeUI::Muted());
    PartyDetailsBody->AddChildToVerticalBox(SelectedDescriptionText)->SetPadding(FMargin(2.0f, 0.0f, 6.0f, 8.0f));

    SummonDigimonButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("SummonDigimonButton"));
    DMFNativeUI::StyleButton(SummonDigimonButton, true);
    UTextBlock* SummonLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SummonLabel"));
    SummonLabel->SetText(NSLOCTEXT("DMF", "SummonSelectedDigimon", "SET ACTIVE / SUMMON"));
    SummonLabel->SetJustification(ETextJustify::Center);
    SummonLabel->SetAutoWrapText(true);
    DMFNativeUI::StyleText(SummonLabel, 15, DMFNativeUI::Text(), true);
    SummonDigimonButton->AddChild(SummonLabel);
    PartyDetailsBody->AddChildToVerticalBox(SummonDigimonButton)->SetPadding(FMargin(0.0f, 4.0f, 4.0f, 4.0f));

    RecallDigimonButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("RecallDigimonButton"));
    DMFNativeUI::StyleButton(RecallDigimonButton);
    UTextBlock* RecallLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("RecallLabel"));
    RecallLabel->SetText(NSLOCTEXT("DMF", "RecallPartnerDigimon", "RECALL ACTIVE PARTNER"));
    RecallLabel->SetJustification(ETextJustify::Center);
    RecallLabel->SetAutoWrapText(true);
    DMFNativeUI::StyleText(RecallLabel, 14, DMFNativeUI::Text(), true);
    RecallDigimonButton->AddChild(RecallLabel);
    PartyDetailsBody->AddChildToVerticalBox(RecallDigimonButton)->SetPadding(FMargin(0.0f, 4.0f, 4.0f, 0.0f));

    MoveSelectedToBankButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("MoveSelectedToBankButton"));
    DMFNativeUI::StyleButton(MoveSelectedToBankButton);
    UTextBlock* MoveToBankLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("MoveSelectedToBankLabel"));
    MoveToBankLabel->SetText(NSLOCTEXT("DMF", "MoveSelectedToBankLabel", "MOVE TO BANK"));
    MoveToBankLabel->SetJustification(ETextJustify::Center);
    MoveToBankLabel->SetAutoWrapText(true);
    DMFNativeUI::StyleText(MoveToBankLabel, 14, DMFNativeUI::Gold(), true);
    MoveSelectedToBankButton->AddChild(MoveToBankLabel);
    PartyDetailsBody->AddChildToVerticalBox(MoveSelectedToBankButton)->SetPadding(FMargin(0.0f, 6.0f, 4.0f, 8.0f));

    // Bank / Box tab: paged owner-only storage plus an explicit Party destination strip for atomic swaps.
    BankContentRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("BankContentRow"));
    if (UVerticalBoxSlot* BankContentSlot = WindowColumn->AddChildToVerticalBox(BankContentRow))
    {
        BankContentSlot->SetSize(DMFNativeUI::FillSize());
    }

    USizeBox* BankGridAreaSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("BankGridAreaSize"));
    BankGridAreaSize->SetWidthOverride(835.0f);
    if (UHorizontalBoxSlot* BankGridAreaSlot = BankContentRow->AddChildToHorizontalBox(BankGridAreaSize))
    {
        BankGridAreaSlot->SetPadding(FMargin(0.0f, 0.0f, 14.0f, 0.0f));
        BankGridAreaSlot->SetVerticalAlignment(VAlign_Fill);
    }

    UBorder* BankGridBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("BankGridBorder"));
    DMFNativeUI::StylePanel(BankGridBorder, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    BankGridAreaSize->AddChild(BankGridBorder);
    UVerticalBox* BankGridColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("BankGridColumn"));
    BankGridBorder->AddChild(BankGridColumn);

    UHorizontalBox* BankHeaderRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("BankHeaderRow"));
    BankGridColumn->AddChildToVerticalBox(BankHeaderRow)->SetPadding(FMargin(2.0f, 0.0f, 2.0f, 7.0f));
    UTextBlock* BankHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankHeader"));
    BankHeader->SetText(NSLOCTEXT("DMF", "BankStorageHeader", "DIGIMON BANK  •  BOX STORAGE"));
    DMFNativeUI::StyleText(BankHeader, 17, DMFNativeUI::Accent(), true);
    BankHeaderRow->AddChildToHorizontalBox(BankHeader)->SetSize(DMFNativeUI::FillSize());
    BankCountText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankCountText"));
    DMFNativeUI::StyleText(BankCountText, 13, DMFNativeUI::Muted(), true);
    BankHeaderRow->AddChildToHorizontalBox(BankCountText)->SetHorizontalAlignment(HAlign_Right);

    UHorizontalBox* BankPagingRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("BankPagingRow"));
    BankGridColumn->AddChildToVerticalBox(BankPagingRow)->SetPadding(FMargin(0,0,0,7));
    BankPreviousPageButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("BankPreviousPageButton"));
    DMFNativeUI::StyleButton(BankPreviousPageButton);
    UTextBlock* PrevLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankPrevLabel"));
    PrevLabel->SetText(NSLOCTEXT("DMF", "BankPrevLabel", "◀  PREVIOUS BOX"));
    DMFNativeUI::StyleText(PrevLabel, 11, DMFNativeUI::Text(), true);
    BankPreviousPageButton->AddChild(PrevLabel);
    BankPagingRow->AddChildToHorizontalBox(BankPreviousPageButton);
    BankPageText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankPageText"));
    BankPageText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(BankPageText, 13, DMFNativeUI::Gold(), true);
    if (UHorizontalBoxSlot* PageLabelSlot = BankPagingRow->AddChildToHorizontalBox(BankPageText))
    {
        PageLabelSlot->SetSize(DMFNativeUI::FillSize());
        PageLabelSlot->SetVerticalAlignment(VAlign_Center);
    }
    BankNextPageButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("BankNextPageButton"));
    DMFNativeUI::StyleButton(BankNextPageButton);
    UTextBlock* NextLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankNextLabel"));
    NextLabel->SetText(NSLOCTEXT("DMF", "BankNextLabel", "NEXT BOX  ▶"));
    DMFNativeUI::StyleText(NextLabel, 11, DMFNativeUI::Text(), true);
    BankNextPageButton->AddChild(NextLabel);
    BankPagingRow->AddChildToHorizontalBox(BankNextPageButton);

    UScrollBox* BankGridScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("BankGridScroll"));
    if (UVerticalBoxSlot* BankGridScrollSlot = BankGridColumn->AddChildToVerticalBox(BankGridScroll))
    {
        BankGridScrollSlot->SetSize(DMFNativeUI::FillSize());
        BankGridScrollSlot->SetPadding(FMargin(0,0,0,2));
    }
    BankDigimonGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("BankDigimonGrid"));
    BankDigimonGrid->SetSlotPadding(FMargin(3.0f));
    BankGridScroll->AddChild(BankDigimonGrid);

    UBorder* PartyDestinationBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("BankPartyDestinationBorder"));
    DMFNativeUI::StylePanel(PartyDestinationBorder, DMFNativeUI::PanelSoft(), FMargin(8.0f));
    BankGridColumn->AddChildToVerticalBox(PartyDestinationBorder)->SetPadding(FMargin(0,7,0,0));
    UVerticalBox* PartyDestinationColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("BankPartyDestinationColumn"));
    PartyDestinationBorder->AddChild(PartyDestinationColumn);
    UTextBlock* PartyDestinationHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PartyDestinationHeader"));
    PartyDestinationHeader->SetText(NSLOCTEXT("DMF", "PartyDestinationHeader", "PARTY DESTINATION  •  choose a slot to swap, or leave unselected when Party has room"));
    PartyDestinationHeader->SetAutoWrapText(true);
    DMFNativeUI::StyleText(PartyDestinationHeader, 10, DMFNativeUI::Muted(), true);
    PartyDestinationColumn->AddChildToVerticalBox(PartyDestinationHeader)->SetPadding(FMargin(0,0,0,5));
    BankPartyDestinationGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("BankPartyDestinationGrid"));
    BankPartyDestinationGrid->SetSlotPadding(FMargin(3.0f));
    PartyDestinationColumn->AddChildToVerticalBox(BankPartyDestinationGrid);

    USizeBox* BankDetailsSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("BankDetailsSize"));
    BankDetailsSize->SetWidthOverride(355.0f);
    BankContentRow->AddChildToHorizontalBox(BankDetailsSize)->SetVerticalAlignment(VAlign_Fill);
    UBorder* BankDetailsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("BankDetailsBorder"));
    DMFNativeUI::StylePanel(BankDetailsBorder, DMFNativeUI::PanelRaised(), FMargin(16.0f));
    BankDetailsSize->AddChild(BankDetailsBorder);
    UVerticalBox* BankDetailsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("BankDetailsColumn"));
    BankDetailsBorder->AddChild(BankDetailsColumn);
    UTextBlock* BankSelectedHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankSelectedHeader"));
    BankSelectedHeader->SetText(NSLOCTEXT("DMF", "BankSelectedHeader", "SELECTED BANK DIGIMON"));
    DMFNativeUI::StyleText(BankSelectedHeader, 13, DMFNativeUI::Gold(), true);
    BankDetailsColumn->AddChildToVerticalBox(BankSelectedHeader)->SetPadding(FMargin(0,0,0,8));
    USizeBox* BankPortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("BankPortraitSize"));
    BankPortraitSize->SetHeightOverride(160.0f);
    UBorder* BankPortraitBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("BankPortraitBorder"));
    DMFNativeUI::StylePanel(BankPortraitBorder, DMFNativeUI::SlotEmpty(), FMargin(5.0f));
    BankPortraitSize->AddChild(BankPortraitBorder);
    BankSelectedPortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("BankSelectedPortraitImage"));
    BankPortraitBorder->AddChild(BankSelectedPortraitImage);
    BankDetailsColumn->AddChildToVerticalBox(BankPortraitSize)->SetPadding(FMargin(0,0,0,8));
    BankSelectedNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankSelectedNameText"));
    BankSelectedNameText->SetJustification(ETextJustify::Center);
    BankSelectedNameText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(BankSelectedNameText, 23, DMFNativeUI::Text(), true);
    BankDetailsColumn->AddChildToVerticalBox(BankSelectedNameText);
    BankSelectedMetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankSelectedMetaText"));
    BankSelectedMetaText->SetJustification(ETextJustify::Center);
    BankSelectedMetaText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(BankSelectedMetaText, 13, DMFNativeUI::Gold(), true);
    BankDetailsColumn->AddChildToVerticalBox(BankSelectedMetaText)->SetPadding(FMargin(0,2,0,8));
    UScrollBox* BankDetailsBodyScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("BankDetailsBodyScroll"));
    if (UVerticalBoxSlot* BankBodyScrollSlot = BankDetailsColumn->AddChildToVerticalBox(BankDetailsBodyScroll))
    {
        BankBodyScrollSlot->SetSize(DMFNativeUI::FillSize());
        BankBodyScrollSlot->SetPadding(FMargin(0,0,0,8));
    }
    UVerticalBox* BankDetailsBody = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("BankDetailsBody"));
    BankDetailsBodyScroll->AddChild(BankDetailsBody);
    UBorder* BankStatsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("BankStatsBorder"));
    DMFNativeUI::StylePanel(BankStatsBorder, DMFNativeUI::PanelSoft(), FMargin(12.0f));
    BankDetailsBody->AddChildToVerticalBox(BankStatsBorder);
    UVerticalBox* BankStatsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("BankStatsColumn"));
    BankStatsBorder->AddChild(BankStatsColumn);
    BankSelectedStatsText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankSelectedStatsText"));
    BankSelectedStatsText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(BankSelectedStatsText, 14, DMFNativeUI::Text());
    BankStatsColumn->AddChildToVerticalBox(BankSelectedStatsText);
    BankExperienceProgressBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("BankExperienceProgressBar"));
    BankExperienceProgressBar->SetFillColorAndOpacity(DMFNativeUI::Accent());
    BankExperienceProgressBar->SetPercent(0.0f);
    BankStatsColumn->AddChildToVerticalBox(BankExperienceProgressBar)->SetPadding(FMargin(0.0f, 8.0f, 0.0f, 0.0f));
    UTextBlock* BankAttributeSpendLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankAttributeSpendLabel"));
    BankAttributeSpendLabel->SetText(NSLOCTEXT("DMF", "BankAttributeSpendLabel", "SPEND ATTRIBUTE POINTS"));
    DMFNativeUI::StyleText(BankAttributeSpendLabel, 10, DMFNativeUI::Muted(), true);
    BankStatsColumn->AddChildToVerticalBox(BankAttributeSpendLabel)->SetPadding(FMargin(0,8,0,3));
    UUniformGridPanel* BankAttributeSpendGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("BankAttributeSpendGrid"));
    BankAttributeSpendGrid->SetSlotPadding(FMargin(2.0f));
    BankStatsColumn->AddChildToVerticalBox(BankAttributeSpendGrid);
    SpendBankHPButton = MakeAttributeSpendButton(TEXT("SpendBankHPButton"), NSLOCTEXT("DMF", "SpendBankHPShort", "+ HP"));
    SpendBankSPButton = MakeAttributeSpendButton(TEXT("SpendBankSPButton"), NSLOCTEXT("DMF", "SpendBankSPShort", "+ SP"));
    SpendBankStrengthButton = MakeAttributeSpendButton(TEXT("SpendBankStrengthButton"), NSLOCTEXT("DMF", "SpendBankSTRShort", "+ STR"));
    SpendBankIntelligenceButton = MakeAttributeSpendButton(TEXT("SpendBankIntelligenceButton"), NSLOCTEXT("DMF", "SpendBankINTShort", "+ INT"));
    SpendBankDefenseButton = MakeAttributeSpendButton(TEXT("SpendBankDefenseButton"), NSLOCTEXT("DMF", "SpendBankDEFShort", "+ DEF"));
    SpendBankSpeedButton = MakeAttributeSpendButton(TEXT("SpendBankSpeedButton"), NSLOCTEXT("DMF", "SpendBankSPDShort", "+ SPD"));
    BankAttributeSpendGrid->AddChildToUniformGrid(SpendBankHPButton, 0, 0);
    BankAttributeSpendGrid->AddChildToUniformGrid(SpendBankSPButton, 0, 1);
    BankAttributeSpendGrid->AddChildToUniformGrid(SpendBankStrengthButton, 0, 2);
    BankAttributeSpendGrid->AddChildToUniformGrid(SpendBankIntelligenceButton, 1, 0);
    BankAttributeSpendGrid->AddChildToUniformGrid(SpendBankDefenseButton, 1, 1);
    BankAttributeSpendGrid->AddChildToUniformGrid(SpendBankSpeedButton, 1, 2);
    BankSelectionText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BankSelectionText"));
    BankSelectionText->SetAutoWrapText(true);
    BankSelectionText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(BankSelectionText, 11, DMFNativeUI::Muted());
    BankDetailsBody->AddChildToVerticalBox(BankSelectionText)->SetPadding(FMargin(2,8,2,0));
    MoveSelectedBankToPartyButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("MoveSelectedBankToPartyButton"));
    DMFNativeUI::StyleButton(MoveSelectedBankToPartyButton, true);
    UTextBlock* MoveBankToPartyLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("MoveBankToPartyLabel"));
    MoveBankToPartyLabel->SetText(NSLOCTEXT("DMF", "MoveBankToPartyLabel", "MOVE / SWAP TO PARTY"));
    MoveBankToPartyLabel->SetJustification(ETextJustify::Center);
    MoveBankToPartyLabel->SetAutoWrapText(true);
    DMFNativeUI::StyleText(MoveBankToPartyLabel, 14, DMFNativeUI::Text(), true);
    MoveSelectedBankToPartyButton->AddChild(MoveBankToPartyLabel);
    BankDetailsColumn->AddChildToVerticalBox(MoveSelectedBankToPartyButton);

    // Scan & Materialize tab: database cards on the left, high-detail materialization terminal on the right.
    ScanContentRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ScanContentRow"));
    if (UVerticalBoxSlot* ScanContentSlot = WindowColumn->AddChildToVerticalBox(ScanContentRow))
    {
        ScanContentSlot->SetSize(DMFNativeUI::FillSize());
    }

    USizeBox* ScanGridAreaSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("ScanGridAreaSize"));
    ScanGridAreaSize->SetWidthOverride(835.0f);
    if (UHorizontalBoxSlot* ScanGridAreaSlot = ScanContentRow->AddChildToHorizontalBox(ScanGridAreaSize))
    {
        ScanGridAreaSlot->SetPadding(FMargin(0.0f, 0.0f, 14.0f, 0.0f));
        ScanGridAreaSlot->SetVerticalAlignment(VAlign_Fill);
    }

    UBorder* ScanGridBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ScanGridBorder"));
    DMFNativeUI::StylePanel(ScanGridBorder, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    ScanGridAreaSize->AddChild(ScanGridBorder);
    UVerticalBox* ScanGridColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("ScanGridColumn"));
    ScanGridBorder->AddChild(ScanGridColumn);

    UHorizontalBox* ScanHeader = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ScanHeader"));
    ScanGridColumn->AddChildToVerticalBox(ScanHeader)->SetPadding(FMargin(2.0f,0.0f,2.0f,8.0f));
    UTextBlock* ScanTitle = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ScanTitle"));
    ScanTitle->SetText(NSLOCTEXT("DMF","ScanDatabaseTitle","DIGIMON SCAN DATABASE"));
    DMFNativeUI::StyleText(ScanTitle,17,DMFNativeUI::Accent(),true);
    ScanHeader->AddChildToHorizontalBox(ScanTitle)->SetSize(DMFNativeUI::FillSize());
    ScanDatabaseCountText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ScanDatabaseCountText"));
    DMFNativeUI::StyleText(ScanDatabaseCountText,13,DMFNativeUI::Muted(),true);
    ScanHeader->AddChildToHorizontalBox(ScanDatabaseCountText)->SetHorizontalAlignment(HAlign_Right);

    UTextBlock* ScanHelp = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ScanHelp"));
    ScanHelp->SetText(NSLOCTEXT("DMF","ScanDatabaseHelp","Defeat eligible Wild Digimon to analyze their species. Reach the required Scan Data threshold to create a permanent Digimon."));
    ScanHelp->SetAutoWrapText(true);
    DMFNativeUI::StyleText(ScanHelp,12,DMFNativeUI::Muted());
    ScanGridColumn->AddChildToVerticalBox(ScanHelp)->SetPadding(FMargin(2,0,2,10));

    UScrollBox* ScanScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("ScanSpeciesScroll"));
    if (UVerticalBoxSlot* ScanScrollSlot = ScanGridColumn->AddChildToVerticalBox(ScanScroll)) ScanScrollSlot->SetSize(DMFNativeUI::FillSize());
    ScanSpeciesGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("ScanSpeciesGrid"));
    ScanSpeciesGrid->SetSlotPadding(FMargin(5.0f));
    ScanScroll->AddChild(ScanSpeciesGrid);

    USizeBox* ScanDetailsSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("ScanDetailsSize"));
    ScanDetailsSize->SetWidthOverride(355.0f);
    ScanContentRow->AddChildToHorizontalBox(ScanDetailsSize)->SetVerticalAlignment(VAlign_Fill);
    UBorder* ScanDetailsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ScanDetailsBorder"));
    DMFNativeUI::StylePanel(ScanDetailsBorder, DMFNativeUI::PanelRaised(), FMargin(16.0f));
    ScanDetailsSize->AddChild(ScanDetailsBorder);
    UVerticalBox* ScanDetailsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("ScanDetailsColumn"));
    ScanDetailsBorder->AddChild(ScanDetailsColumn);

    UTextBlock* MaterializationHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("MaterializationHeader"));
    MaterializationHeader->SetText(NSLOCTEXT("DMF","MaterializationTerminalHeader","MATERIALIZATION TERMINAL"));
    DMFNativeUI::StyleText(MaterializationHeader,14,DMFNativeUI::Gold(),true);
    ScanDetailsColumn->AddChildToVerticalBox(MaterializationHeader)->SetPadding(FMargin(0,0,0,8));

    USizeBox* ScanPortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("ScanSelectedPortraitSize"));
    ScanPortraitSize->SetHeightOverride(165.0f); ScanPortraitSize->SetWidthOverride(320.0f);
    ScanDetailsColumn->AddChildToVerticalBox(ScanPortraitSize)->SetHorizontalAlignment(HAlign_Center);
    UBorder* ScanPortraitBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ScanSelectedPortraitBorder"));
    DMFNativeUI::StylePanel(ScanPortraitBorder,DMFNativeUI::SlotEmpty(),FMargin(5.0f)); ScanPortraitSize->AddChild(ScanPortraitBorder);
    ScanSelectedPortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("ScanSelectedPortraitImage")); ScanPortraitBorder->AddChild(ScanSelectedPortraitImage);

    ScanSelectedNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ScanSelectedNameText"));
    ScanSelectedNameText->SetJustification(ETextJustify::Center);
    ScanSelectedNameText->SetAutoWrapText(true); DMFNativeUI::StyleText(ScanSelectedNameText,24,DMFNativeUI::Text(),true);
    ScanDetailsColumn->AddChildToVerticalBox(ScanSelectedNameText)->SetPadding(FMargin(0,10,0,0));
    ScanSelectedMetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ScanSelectedMetaText"));
    ScanSelectedMetaText->SetJustification(ETextJustify::Center);
    ScanSelectedMetaText->SetAutoWrapText(true); DMFNativeUI::StyleText(ScanSelectedMetaText,13,DMFNativeUI::Gold(),true);
    ScanDetailsColumn->AddChildToVerticalBox(ScanSelectedMetaText)->SetPadding(FMargin(0,0,0,8));

    ScanSelectedProgressText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ScanSelectedProgressText"));
    ScanSelectedProgressText->SetJustification(ETextJustify::Center); DMFNativeUI::StyleText(ScanSelectedProgressText,15,DMFNativeUI::Accent(),true);
    ScanDetailsColumn->AddChildToVerticalBox(ScanSelectedProgressText);
    ScanSelectedProgressBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("ScanSelectedProgressBar"));
    ScanSelectedProgressBar->SetFillColorAndOpacity(DMFNativeUI::Accent());
    ScanDetailsColumn->AddChildToVerticalBox(ScanSelectedProgressBar)->SetPadding(FMargin(0,6,0,10));

    UBorder* ScanInfoBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ScanInfoBorder"));
    DMFNativeUI::StylePanel(ScanInfoBorder,DMFNativeUI::PanelSoft(),FMargin(12.0f));
    ScanDetailsColumn->AddChildToVerticalBox(ScanInfoBorder)->SetPadding(FMargin(0,0,0,8));
    ScanSelectedDetailsText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ScanSelectedDetailsText"));
    ScanSelectedDetailsText->SetAutoWrapText(true); DMFNativeUI::StyleText(ScanSelectedDetailsText,13,DMFNativeUI::Text()); ScanInfoBorder->AddChild(ScanSelectedDetailsText);

    USizeBox* ScanDescriptionViewport = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("ScanDescriptionViewport"));
    ScanDescriptionViewport->SetMinDesiredHeight(48.0f);
    UScrollBox* ScanDescriptionScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("ScanDescriptionScroll"));
    ScanDescriptionViewport->AddChild(ScanDescriptionScroll);
    ScanSelectedDescriptionText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ScanSelectedDescriptionText"));
    ScanSelectedDescriptionText->SetAutoWrapText(true); DMFNativeUI::StyleText(ScanSelectedDescriptionText,12,DMFNativeUI::Muted());
    ScanDescriptionScroll->AddChild(ScanSelectedDescriptionText);
    if (UVerticalBoxSlot* ScanDescSlot = ScanDetailsColumn->AddChildToVerticalBox(ScanDescriptionViewport)) { ScanDescSlot->SetSize(DMFNativeUI::FillSize()); ScanDescSlot->SetPadding(FMargin(2,0,2,8)); }

    MaterializeDigimonButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("MaterializeDigimonButton"));
    DMFNativeUI::StyleButton(MaterializeDigimonButton,true);
    UTextBlock* MaterializeLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("MaterializeLabel"));
    MaterializeLabel->SetText(NSLOCTEXT("DMF","MaterializeDigimonButtonLabel","MATERIALIZE DIGIMON")); MaterializeLabel->SetJustification(ETextJustify::Center); MaterializeLabel->SetAutoWrapText(true); DMFNativeUI::StyleText(MaterializeLabel,15,DMFNativeUI::Text(),true);
    MaterializeDigimonButton->AddChild(MaterializeLabel);
    ScanDetailsColumn->AddChildToVerticalBox(MaterializeDigimonButton)->SetPadding(FMargin(0,4,0,0));

    // DIGIDEX tab: read-only encyclopedia of every registered Digimon species primary asset.
    // It deliberately exposes no summon/storage/mutation actions; owner state is used only for Scan/Owned status badges.
    DigiDexContentRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("DigiDexContentRow"));
    if (UVerticalBoxSlot* DigiDexContentSlot = WindowColumn->AddChildToVerticalBox(DigiDexContentRow))
    {
        DigiDexContentSlot->SetSize(DMFNativeUI::FillSize());
    }

    USizeBox* DigiDexBrowserSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("DigiDexBrowserSize"));
    DigiDexBrowserSize->SetWidthOverride(835.0f);
    if (UHorizontalBoxSlot* DigiDexBrowserLayout = DigiDexContentRow->AddChildToHorizontalBox(DigiDexBrowserSize))
    {
        DigiDexBrowserLayout->SetPadding(FMargin(0.0f, 0.0f, 14.0f, 0.0f));
        DigiDexBrowserLayout->SetVerticalAlignment(VAlign_Fill);
    }
    UBorder* DigiDexBrowserBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigiDexBrowserBorder"));
    DMFNativeUI::StylePanel(DigiDexBrowserBorder, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    DigiDexBrowserSize->AddChild(DigiDexBrowserBorder);
    UVerticalBox* DigiDexBrowserColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DigiDexBrowserColumn"));
    DigiDexBrowserBorder->AddChild(DigiDexBrowserColumn);

    UHorizontalBox* DigiDexHeaderRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("DigiDexHeaderRow"));
    DigiDexBrowserColumn->AddChildToVerticalBox(DigiDexHeaderRow)->SetPadding(FMargin(2,0,2,8));
    UTextBlock* DigiDexHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexHeader"));
    DigiDexHeader->SetText(NSLOCTEXT("DMF", "DigiDexHeader", "DIGIDEX  •  SPECIES DATABASE"));
    DMFNativeUI::StyleText(DigiDexHeader, 17, DMFNativeUI::Accent(), true);
    DigiDexHeaderRow->AddChildToHorizontalBox(DigiDexHeader)->SetSize(DMFNativeUI::FillSize());
    DigiDexCountText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexCountText"));
    DMFNativeUI::StyleText(DigiDexCountText, 12, DMFNativeUI::Muted(), true);
    DigiDexHeaderRow->AddChildToHorizontalBox(DigiDexCountText)->SetHorizontalAlignment(HAlign_Right);

    UTextBlock* DigiDexHelp = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexHelp"));
    DigiDexHelp->SetText(NSLOCTEXT("DMF", "DigiDexHelp", "Browse every Digimon species implemented in the project. Search and filter the registry, then inspect species data, Scan/ownership status and evolution links."));
    DigiDexHelp->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigiDexHelp, 12, DMFNativeUI::Muted());
    DigiDexBrowserColumn->AddChildToVerticalBox(DigiDexHelp)->SetPadding(FMargin(2,0,2,10));

    UHorizontalBox* DigiDexFilterRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("DigiDexFilterRow"));
    DigiDexBrowserColumn->AddChildToVerticalBox(DigiDexFilterRow)->SetPadding(FMargin(0,0,0,10));
    USizeBox* DigiDexSearchSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("DigiDexSearchSize"));
    DigiDexSearchSize->SetWidthOverride(330.0f);
    DigiDexSearchBox = WidgetTree->ConstructWidget<UEditableTextBox>(UEditableTextBox::StaticClass(), TEXT("DigiDexSearchBox"));
    DigiDexSearchBox->SetHintText(NSLOCTEXT("DMF", "DigiDexSearchHint", "Search species, stage, attribute or element..."));
    DigiDexSearchSize->AddChild(DigiDexSearchBox);
    DigiDexFilterRow->AddChildToHorizontalBox(DigiDexSearchSize)->SetPadding(FMargin(0,0,8,0));

    DigiDexStageFilterButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("DigiDexStageFilterButton"));
    DMFNativeUI::StyleButton(DigiDexStageFilterButton);
    DigiDexStageFilterText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexStageFilterText"));
    DigiDexStageFilterText->SetText(NSLOCTEXT("DMF", "DigiDexAllStages", "ALL STAGES"));
    DMFNativeUI::StyleText(DigiDexStageFilterText, 11, DMFNativeUI::Text(), true);
    DigiDexStageFilterButton->AddChild(DigiDexStageFilterText);
    DigiDexFilterRow->AddChildToHorizontalBox(DigiDexStageFilterButton)->SetPadding(FMargin(0,0,8,0));

    DigiDexAttributeFilterButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("DigiDexAttributeFilterButton"));
    DMFNativeUI::StyleButton(DigiDexAttributeFilterButton);
    DigiDexAttributeFilterText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexAttributeFilterText"));
    DigiDexAttributeFilterText->SetText(NSLOCTEXT("DMF", "DigiDexAllAttributes", "ALL ATTRIBUTES"));
    DMFNativeUI::StyleText(DigiDexAttributeFilterText, 11, DMFNativeUI::Text(), true);
    DigiDexAttributeFilterButton->AddChild(DigiDexAttributeFilterText);
    DigiDexFilterRow->AddChildToHorizontalBox(DigiDexAttributeFilterButton);

    UScrollBox* DigiDexScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("DigiDexSpeciesScroll"));
    if (UVerticalBoxSlot* DigiDexScrollSlot = DigiDexBrowserColumn->AddChildToVerticalBox(DigiDexScroll))
    {
        DigiDexScrollSlot->SetSize(DMFNativeUI::FillSize());
    }
    DigiDexSpeciesGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("DigiDexSpeciesGrid"));
    DigiDexSpeciesGrid->SetSlotPadding(FMargin(5.0f));
    DigiDexScroll->AddChild(DigiDexSpeciesGrid);

    USizeBox* DigiDexDetailsSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("DigiDexDetailsSize"));
    DigiDexDetailsSize->SetWidthOverride(355.0f);
    DigiDexContentRow->AddChildToHorizontalBox(DigiDexDetailsSize)->SetVerticalAlignment(VAlign_Fill);
    UBorder* DigiDexDetailsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigiDexDetailsBorder"));
    DMFNativeUI::StylePanel(DigiDexDetailsBorder, DMFNativeUI::PanelRaised(), FMargin(14.0f));
    DigiDexDetailsSize->AddChild(DigiDexDetailsBorder);
    UVerticalBox* DigiDexDetailsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DigiDexDetailsColumn"));
    DigiDexDetailsBorder->AddChild(DigiDexDetailsColumn);

    UTextBlock* DigiDexProfileHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexProfileHeader"));
    DigiDexProfileHeader->SetText(NSLOCTEXT("DMF", "DigiDexProfileHeader", "DIGIDEX ENTRY"));
    DMFNativeUI::StyleText(DigiDexProfileHeader, 14, DMFNativeUI::Gold(), true);
    DigiDexDetailsColumn->AddChildToVerticalBox(DigiDexProfileHeader)->SetPadding(FMargin(0,0,0,8));

    USizeBox* DigiDexPortraitViewport = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("DigiDexPortraitViewport"));
    DigiDexPortraitViewport->SetWidthOverride(300.0f);
    DigiDexPortraitViewport->SetHeightOverride(185.0f);
    DigiDexDetailsColumn->AddChildToVerticalBox(DigiDexPortraitViewport)->SetHorizontalAlignment(HAlign_Center);
    UBorder* DigiDexPortraitBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigiDexPortraitBorder"));
    DMFNativeUI::StylePanel(DigiDexPortraitBorder, DMFNativeUI::SlotEmpty(), FMargin(5.0f));
    DigiDexPortraitViewport->AddChild(DigiDexPortraitBorder);
    UScaleBox* DigiDexPortraitScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("DigiDexPortraitScale"));
    DigiDexPortraitScale->SetStretch(EStretch::ScaleToFit);
    DigiDexPortraitScale->SetStretchDirection(EStretchDirection::DownOnly);
    DigiDexPortraitBorder->AddChild(DigiDexPortraitScale);
    DigiDexSelectedPortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("DigiDexSelectedPortraitImage"));
    DigiDexPortraitScale->AddChild(DigiDexSelectedPortraitImage);

    DigiDexSelectedNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexSelectedNameText"));
    DigiDexSelectedNameText->SetJustification(ETextJustify::Center);
    DigiDexSelectedNameText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigiDexSelectedNameText, 24, DMFNativeUI::Text(), true);
    DigiDexDetailsColumn->AddChildToVerticalBox(DigiDexSelectedNameText)->SetPadding(FMargin(0,8,0,0));
    DigiDexSelectedMetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexSelectedMetaText"));
    DigiDexSelectedMetaText->SetJustification(ETextJustify::Center);
    DigiDexSelectedMetaText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigiDexSelectedMetaText, 12, DMFNativeUI::Gold(), true);
    DigiDexDetailsColumn->AddChildToVerticalBox(DigiDexSelectedMetaText)->SetPadding(FMargin(0,0,0,4));
    DigiDexSelectedStatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexSelectedStatusText"));
    DigiDexSelectedStatusText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(DigiDexSelectedStatusText, 12, DMFNativeUI::Accent(), true);
    DigiDexDetailsColumn->AddChildToVerticalBox(DigiDexSelectedStatusText)->SetPadding(FMargin(0,0,0,8));

    UScrollBox* DigiDexInfoScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("DigiDexInfoScroll"));
    if (UVerticalBoxSlot* DigiDexInfoScrollSlot = DigiDexDetailsColumn->AddChildToVerticalBox(DigiDexInfoScroll))
    {
        DigiDexInfoScrollSlot->SetSize(DMFNativeUI::FillSize());
    }
    UVerticalBox* DigiDexInfoColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DigiDexInfoColumn"));
    DigiDexInfoScroll->AddChild(DigiDexInfoColumn);

    UBorder* DigiDexStatsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigiDexStatsBorder"));
    DMFNativeUI::StylePanel(DigiDexStatsBorder, DMFNativeUI::PanelSoft(), FMargin(10.0f));
    DigiDexInfoColumn->AddChildToVerticalBox(DigiDexStatsBorder)->SetPadding(FMargin(0,0,0,8));
    DigiDexSelectedStatsText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexSelectedStatsText"));
    DigiDexSelectedStatsText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigiDexSelectedStatsText, 12, DMFNativeUI::Text());
    DigiDexStatsBorder->AddChild(DigiDexSelectedStatsText);

    UBorder* DigiDexEvolutionBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigiDexEvolutionBorder"));
    DMFNativeUI::StylePanel(DigiDexEvolutionBorder, DMFNativeUI::PanelSoft(), FMargin(10.0f));
    DigiDexInfoColumn->AddChildToVerticalBox(DigiDexEvolutionBorder)->SetPadding(FMargin(0,0,0,8));
    DigiDexSelectedEvolutionText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexSelectedEvolutionText"));
    DigiDexSelectedEvolutionText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigiDexSelectedEvolutionText, 12, DMFNativeUI::Text());
    DigiDexEvolutionBorder->AddChild(DigiDexSelectedEvolutionText);

    UTextBlock* DigiDexDescriptionLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexDescriptionLabel"));
    DigiDexDescriptionLabel->SetText(NSLOCTEXT("DMF", "DigiDexDescriptionLabel", "SPECIES NOTES"));
    DMFNativeUI::StyleText(DigiDexDescriptionLabel, 11, DMFNativeUI::Muted(), true);
    DigiDexInfoColumn->AddChildToVerticalBox(DigiDexDescriptionLabel)->SetPadding(FMargin(2,0,2,4));
    DigiDexSelectedDescriptionText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexSelectedDescriptionText"));
    DigiDexSelectedDescriptionText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigiDexSelectedDescriptionText, 12, DMFNativeUI::Muted());
    DigiDexInfoColumn->AddChildToVerticalBox(DigiDexSelectedDescriptionText)->SetPadding(FMargin(2,0,2,10));

    UBorder* DigiDexReadOnlyBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigiDexReadOnlyBorder"));
    DMFNativeUI::StylePanel(DigiDexReadOnlyBorder, FLinearColor(0.015f,0.12f,0.14f,0.98f), FMargin(8.0f,6.0f));
    UTextBlock* DigiDexReadOnlyText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigiDexReadOnlyText"));
    DigiDexReadOnlyText->SetText(NSLOCTEXT("DMF", "DigiDexReadOnlyText", "ENCYCLOPEDIA ONLY  •  NO SUMMON / STORAGE ACTIONS"));
    DigiDexReadOnlyText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(DigiDexReadOnlyText, 10, DMFNativeUI::Accent(), true);
    DigiDexReadOnlyBorder->AddChild(DigiDexReadOnlyText);
    DigiDexDetailsColumn->AddChildToVerticalBox(DigiDexReadOnlyBorder)->SetPadding(FMargin(0,8,0,0));

    // DIGIVOLUTION tab: account-owned Party + Bank selection on the left and authoritative path evaluation on the right.
    DigivolutionContentRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("DigivolutionContentRow"));
    if (UVerticalBoxSlot* DigivolutionContentSlot = WindowColumn->AddChildToVerticalBox(DigivolutionContentRow))
    {
        DigivolutionContentSlot->SetSize(DMFNativeUI::FillSize());
    }

    USizeBox* DigivolutionOwnedSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("DigivolutionOwnedSize"));
    DigivolutionOwnedSize->SetWidthOverride(500.0f);
    if (UHorizontalBoxSlot* OwnedLayoutSlot = DigivolutionContentRow->AddChildToHorizontalBox(DigivolutionOwnedSize))
    {
        OwnedLayoutSlot->SetPadding(FMargin(0.0f, 0.0f, 14.0f, 0.0f));
        OwnedLayoutSlot->SetVerticalAlignment(VAlign_Fill);
    }
    UBorder* DigivolutionOwnedBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigivolutionOwnedBorder"));
    DMFNativeUI::StylePanel(DigivolutionOwnedBorder, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    DigivolutionOwnedSize->AddChild(DigivolutionOwnedBorder);
    UVerticalBox* DigivolutionOwnedColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DigivolutionOwnedColumn"));
    DigivolutionOwnedBorder->AddChild(DigivolutionOwnedColumn);

    UTextBlock* DigivolutionOwnedHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionOwnedHeader"));
    DigivolutionOwnedHeader->SetText(NSLOCTEXT("DMF", "DigivolutionOwnedHeader", "OWNED DIGIMON  •  PARTY + BANK"));
    DMFNativeUI::StyleText(DigivolutionOwnedHeader, 17, DMFNativeUI::Accent(), true);
    DigivolutionOwnedColumn->AddChildToVerticalBox(DigivolutionOwnedHeader)->SetPadding(FMargin(2,0,2,8));

    UBorder* CurrentFormBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigivolutionCurrentFormBorder"));
    DMFNativeUI::StylePanel(CurrentFormBorder, DMFNativeUI::PanelSoft(), FMargin(10.0f));
    DigivolutionOwnedColumn->AddChildToVerticalBox(CurrentFormBorder)->SetPadding(FMargin(0,0,0,10));
    UHorizontalBox* CurrentFormRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("DigivolutionCurrentFormRow"));
    CurrentFormBorder->AddChild(CurrentFormRow);
    USizeBox* CurrentPortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("DigivolutionCurrentPortraitSize"));
    CurrentPortraitSize->SetWidthOverride(142.0f);
    CurrentPortraitSize->SetHeightOverride(142.0f);
    CurrentFormRow->AddChildToHorizontalBox(CurrentPortraitSize)->SetPadding(FMargin(0,0,12,0));
    DigivolutionCurrentPortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("DigivolutionCurrentPortraitImage"));
    CurrentPortraitSize->AddChild(DigivolutionCurrentPortraitImage);
    UVerticalBox* CurrentIdentityColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DigivolutionCurrentIdentityColumn"));
    if (UHorizontalBoxSlot* CurrentIdentitySlot = CurrentFormRow->AddChildToHorizontalBox(CurrentIdentityColumn))
    {
        CurrentIdentitySlot->SetSize(DMFNativeUI::FillSize());
        CurrentIdentitySlot->SetVerticalAlignment(VAlign_Center);
    }
    UTextBlock* CurrentFormCaption = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionCurrentFormCaption"));
    CurrentFormCaption->SetText(NSLOCTEXT("DMF", "DigivolutionCurrentFormCaption", "CURRENT FORM"));
    DMFNativeUI::StyleText(CurrentFormCaption, 11, DMFNativeUI::Muted(), true);
    CurrentIdentityColumn->AddChildToVerticalBox(CurrentFormCaption);
    DigivolutionCurrentNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionCurrentNameText"));
    DigivolutionCurrentNameText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigivolutionCurrentNameText, 23, DMFNativeUI::Text(), true);
    CurrentIdentityColumn->AddChildToVerticalBox(DigivolutionCurrentNameText)->SetPadding(FMargin(0,3,0,3));
    DigivolutionCurrentMetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionCurrentMetaText"));
    DigivolutionCurrentMetaText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigivolutionCurrentMetaText, 12, DMFNativeUI::Gold(), true);
    CurrentIdentityColumn->AddChildToVerticalBox(DigivolutionCurrentMetaText);

    UTextBlock* OwnedHelpText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionOwnedHelpText"));
    OwnedHelpText->SetText(NSLOCTEXT("DMF", "DigivolutionOwnedHelp", "Choose any Digimon from Party or Bank. Bank Digivolution can be disabled globally or per path."));
    OwnedHelpText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(OwnedHelpText, 11, DMFNativeUI::Muted());
    DigivolutionOwnedColumn->AddChildToVerticalBox(OwnedHelpText)->SetPadding(FMargin(2,0,2,8));

    UScrollBox* DigivolutionOwnedScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("DigivolutionOwnedScroll"));
    if (UVerticalBoxSlot* OwnedScrollSlot = DigivolutionOwnedColumn->AddChildToVerticalBox(DigivolutionOwnedScroll))
    {
        OwnedScrollSlot->SetSize(DMFNativeUI::FillSize());
    }
    DigivolutionOwnedGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("DigivolutionOwnedGrid"));
    DigivolutionOwnedGrid->SetSlotPadding(FMargin(4.0f));
    DigivolutionOwnedScroll->AddChild(DigivolutionOwnedGrid);

    UBorder* DigivolutionPathsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigivolutionPathsBorder"));
    DMFNativeUI::StylePanel(DigivolutionPathsBorder, DMFNativeUI::PanelRaised(), FMargin(14.0f));
    if (UHorizontalBoxSlot* PathLayoutSlot = DigivolutionContentRow->AddChildToHorizontalBox(DigivolutionPathsBorder))
    {
        PathLayoutSlot->SetSize(DMFNativeUI::FillSize());
        PathLayoutSlot->SetVerticalAlignment(VAlign_Fill);
    }
    UVerticalBox* DigivolutionPathsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DigivolutionPathsColumn"));
    DigivolutionPathsBorder->AddChild(DigivolutionPathsColumn);
    UTextBlock* DigivolutionPathsHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionPathsHeader"));
    DigivolutionPathsHeader->SetText(NSLOCTEXT("DMF", "DigivolutionPathsHeader", "AVAILABLE DIGIVOLUTION PATHS"));
    DMFNativeUI::StyleText(DigivolutionPathsHeader, 16, DMFNativeUI::Gold(), true);
    DigivolutionPathsColumn->AddChildToVerticalBox(DigivolutionPathsHeader)->SetPadding(FMargin(0,0,0,8));

    USizeBox* PathListViewport = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("DigivolutionPathListViewport"));
    PathListViewport->SetHeightOverride(260.0f);
    UScrollBox* PathListScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("DigivolutionPathListScroll"));
    PathListViewport->AddChild(PathListScroll);
    DigivolutionPathList = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DigivolutionPathList"));
    PathListScroll->AddChild(DigivolutionPathList);
    DigivolutionPathsColumn->AddChildToVerticalBox(PathListViewport)->SetPadding(FMargin(0,0,0,10));

    UBorder* TargetPreviewBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigivolutionTargetPreviewBorder"));
    DMFNativeUI::StylePanel(TargetPreviewBorder, DMFNativeUI::PanelSoft(), FMargin(10.0f));
    DigivolutionPathsColumn->AddChildToVerticalBox(TargetPreviewBorder)->SetPadding(FMargin(0,0,0,8));
    UHorizontalBox* TargetPreviewRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("DigivolutionTargetPreviewRow"));
    TargetPreviewBorder->AddChild(TargetPreviewRow);
    USizeBox* TargetPortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("DigivolutionTargetPortraitSize"));
    TargetPortraitSize->SetWidthOverride(145.0f);
    TargetPortraitSize->SetHeightOverride(145.0f);
    TargetPreviewRow->AddChildToHorizontalBox(TargetPortraitSize)->SetPadding(FMargin(0,0,12,0));
    DigivolutionTargetPortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("DigivolutionTargetPortraitImage"));
    TargetPortraitSize->AddChild(DigivolutionTargetPortraitImage);
    UVerticalBox* TargetTextColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DigivolutionTargetTextColumn"));
    if (UHorizontalBoxSlot* TargetTextSlot = TargetPreviewRow->AddChildToHorizontalBox(TargetTextColumn))
    {
        TargetTextSlot->SetSize(DMFNativeUI::FillSize());
        TargetTextSlot->SetVerticalAlignment(VAlign_Center);
    }
    UTextBlock* TargetCaption = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionTargetCaption"));
    TargetCaption->SetText(NSLOCTEXT("DMF", "DigivolutionTargetCaption", "TARGET FORM"));
    DMFNativeUI::StyleText(TargetCaption, 11, DMFNativeUI::Muted(), true);
    TargetTextColumn->AddChildToVerticalBox(TargetCaption);
    DigivolutionTargetNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionTargetNameText"));
    DigivolutionTargetNameText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigivolutionTargetNameText, 24, DMFNativeUI::Text(), true);
    TargetTextColumn->AddChildToVerticalBox(DigivolutionTargetNameText)->SetPadding(FMargin(0,3,0,3));
    DigivolutionTargetMetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionTargetMetaText"));
    DigivolutionTargetMetaText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigivolutionTargetMetaText, 13, DMFNativeUI::Gold(), true);
    TargetTextColumn->AddChildToVerticalBox(DigivolutionTargetMetaText);

    UBorder* RequirementBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DigivolutionRequirementBorder"));
    DMFNativeUI::StylePanel(RequirementBorder, DMFNativeUI::SlotEmpty(), FMargin(10.0f));
    if (UVerticalBoxSlot* RequirementLayoutSlot = DigivolutionPathsColumn->AddChildToVerticalBox(RequirementBorder))
    {
        RequirementLayoutSlot->SetSize(DMFNativeUI::FillSize());
        RequirementLayoutSlot->SetPadding(FMargin(0,0,0,8));
    }
    UScrollBox* RequirementScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("DigivolutionRequirementScroll"));
    RequirementBorder->AddChild(RequirementScroll);
    DigivolutionRequirementText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolutionRequirementText"));
    DigivolutionRequirementText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigivolutionRequirementText, 12, DMFNativeUI::Text());
    RequirementScroll->AddChild(DigivolutionRequirementText);

    DigivolveButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("DigivolveButton"));
    DMFNativeUI::StyleButton(DigivolveButton, true);
    UTextBlock* DigivolveLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DigivolveLabel"));
    DigivolveLabel->SetText(NSLOCTEXT("DMF", "DigivolveButtonLabel", "DIGIVOLVE TO SELECTED FORM"));
    DigivolveLabel->SetJustification(ETextJustify::Center);
    DigivolveLabel->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DigivolveLabel, 15, DMFNativeUI::Text(), true);
    DigivolveButton->AddChild(DigivolveLabel);
    DigivolutionPathsColumn->AddChildToVerticalBox(DigivolveButton);

    // CARE tab: polished virtual-pet dashboard. All mutation buttons route through the owner component's server RPC.
    CareContentRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("CareContentRow"));
    if (UVerticalBoxSlot* CareContentLayoutSlot = WindowColumn->AddChildToVerticalBox(CareContentRow))
    {
        CareContentLayoutSlot->SetSize(DMFNativeUI::FillSize());
    }

    USizeBox* CareMainSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("CareMainSize"));
    CareMainSize->SetWidthOverride(835.0f);
    if (UHorizontalBoxSlot* CareMainLayoutSlot = CareContentRow->AddChildToHorizontalBox(CareMainSize))
    {
        CareMainLayoutSlot->SetPadding(FMargin(0,0,14,0));
        CareMainLayoutSlot->SetVerticalAlignment(VAlign_Fill);
    }
    UBorder* CareMainBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("CareMainBorder"));
    DMFNativeUI::StylePanel(CareMainBorder, DMFNativeUI::PanelRaised(), FMargin(16.0f));
    CareMainSize->AddChild(CareMainBorder);
    UVerticalBox* CareMainColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("CareMainColumn"));
    CareMainBorder->AddChild(CareMainColumn);

    UTextBlock* CareHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareHeader"));
    CareHeader->SetText(NSLOCTEXT("DMF", "CareHeader", "VIRTUAL PET CARE"));
    DMFNativeUI::StyleText(CareHeader, 17, DMFNativeUI::Accent(), true);
    CareMainColumn->AddChildToVerticalBox(CareHeader)->SetPadding(FMargin(0,0,0,10));

    UHorizontalBox* CareProfileRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("CareProfileRow"));
    CareMainColumn->AddChildToVerticalBox(CareProfileRow)->SetPadding(FMargin(0,0,0,14));
    USizeBox* CarePortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("CarePortraitSize"));
    CarePortraitSize->SetWidthOverride(220.0f); CarePortraitSize->SetHeightOverride(170.0f);
    UBorder* CarePortraitBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("CarePortraitBorder"));
    DMFNativeUI::StylePanel(CarePortraitBorder, DMFNativeUI::SlotEmpty(), FMargin(5.0f));
    CarePortraitSize->AddChild(CarePortraitBorder);
    CarePortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("CarePortraitImage"));
    CarePortraitBorder->AddChild(CarePortraitImage);
    CareProfileRow->AddChildToHorizontalBox(CarePortraitSize)->SetPadding(FMargin(0,0,16,0));

    UVerticalBox* CareIdentityColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("CareIdentityColumn"));
    if (UHorizontalBoxSlot* CareIdentityLayoutSlot = CareProfileRow->AddChildToHorizontalBox(CareIdentityColumn))
    {
        CareIdentityLayoutSlot->SetSize(DMFNativeUI::FillSize());
        CareIdentityLayoutSlot->SetVerticalAlignment(VAlign_Center);
    }
    CareNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareNameText"));
    CareNameText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(CareNameText, 28, DMFNativeUI::Text(), true);
    CareIdentityColumn->AddChildToVerticalBox(CareNameText);
    CareMetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareMetaText"));
    CareMetaText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(CareMetaText, 14, DMFNativeUI::Gold(), true);
    CareIdentityColumn->AddChildToVerticalBox(CareMetaText)->SetPadding(FMargin(0,2,0,14));
    UTextBlock* UnlimitedText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("UnlimitedDigiMeatText"));
    UnlimitedText->SetText(NSLOCTEXT("DMF", "UnlimitedDigiMeat", "∞  UNLIMITED DIGIMEAT"));
    DMFNativeUI::StyleText(UnlimitedText, 18, DMFNativeUI::Success(), true);
    CareIdentityColumn->AddChildToVerticalBox(UnlimitedText)->SetPadding(FMargin(0,0,0,6));
    UTextBlock* CareHelpText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareHelpText"));
    CareHelpText->SetText(NSLOCTEXT("DMF", "CareHelp", "Feed your summoned partner until full. The menu hides during eating so the complete in-world animation can be watched."));
    CareHelpText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(CareHelpText, 12, DMFNativeUI::Muted());
    CareIdentityColumn->AddChildToVerticalBox(CareHelpText);

    UTextBlock* HungerLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("HungerLabel"));
    HungerLabel->SetText(NSLOCTEXT("DMF", "HungerLabel", "HUNGER / FULLNESS"));
    DMFNativeUI::StyleText(HungerLabel, 13, DMFNativeUI::Muted(), true);
    CareMainColumn->AddChildToVerticalBox(HungerLabel);
    CareHungerText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareHungerText"));
    DMFNativeUI::StyleText(CareHungerText, 22, DMFNativeUI::Accent(), true);
    CareMainColumn->AddChildToVerticalBox(CareHungerText);
    CareHungerProgressBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("CareHungerProgressBar"));
    CareHungerProgressBar->SetFillColorAndOpacity(DMFNativeUI::Accent());
    CareMainColumn->AddChildToVerticalBox(CareHungerProgressBar)->SetPadding(FMargin(0,4,0,14));

    UHorizontalBox* MoodBars = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("CareMoodBars"));
    CareMainColumn->AddChildToVerticalBox(MoodBars)->SetPadding(FMargin(0,0,0,12));
    UVerticalBox* HappinessColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("HappinessColumn"));
    if (UHorizontalBoxSlot* HappinessLayoutSlot = MoodBars->AddChildToHorizontalBox(HappinessColumn)) { HappinessLayoutSlot->SetSize(DMFNativeUI::FillSize()); HappinessLayoutSlot->SetPadding(FMargin(0,0,8,0)); }
    UTextBlock* HappinessLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("HappinessLabel")); HappinessLabel->SetText(NSLOCTEXT("DMF","HappinessLabel","HAPPINESS")); DMFNativeUI::StyleText(HappinessLabel,11,DMFNativeUI::Muted(),true); HappinessColumn->AddChildToVerticalBox(HappinessLabel);
    CareHappinessProgressBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("CareHappinessProgressBar")); CareHappinessProgressBar->SetFillColorAndOpacity(DMFNativeUI::Success()); HappinessColumn->AddChildToVerticalBox(CareHappinessProgressBar)->SetPadding(FMargin(0,4,0,0));
    UVerticalBox* DisciplineColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DisciplineColumn"));
    if (UHorizontalBoxSlot* DisciplineLayoutSlot = MoodBars->AddChildToHorizontalBox(DisciplineColumn)) { DisciplineLayoutSlot->SetSize(DMFNativeUI::FillSize()); DisciplineLayoutSlot->SetPadding(FMargin(8,0,0,0)); }
    UTextBlock* DisciplineLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DisciplineLabel")); DisciplineLabel->SetText(NSLOCTEXT("DMF","DisciplineLabel","DISCIPLINE")); DMFNativeUI::StyleText(DisciplineLabel,11,DMFNativeUI::Muted(),true); DisciplineColumn->AddChildToVerticalBox(DisciplineLabel);
    CareDisciplineProgressBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("CareDisciplineProgressBar")); CareDisciplineProgressBar->SetFillColorAndOpacity(DMFNativeUI::Gold()); DisciplineColumn->AddChildToVerticalBox(CareDisciplineProgressBar)->SetPadding(FMargin(0,4,0,0));

    UBorder* CareStatsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("CareStatsBorder"));
    DMFNativeUI::StylePanel(CareStatsBorder, DMFNativeUI::PanelSoft(), FMargin(12.0f));
    if (UVerticalBoxSlot* CareStatsLayoutSlot = CareMainColumn->AddChildToVerticalBox(CareStatsBorder)) { CareStatsLayoutSlot->SetSize(DMFNativeUI::FillSize()); }
    CareStatisticsText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareStatisticsText"));
    CareStatisticsText->SetAutoWrapText(true); DMFNativeUI::StyleText(CareStatisticsText, 14, DMFNativeUI::Text()); CareStatsBorder->AddChild(CareStatisticsText);

    USizeBox* CareActionSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("CareActionSize"));
    CareActionSize->SetWidthOverride(355.0f);
    CareContentRow->AddChildToHorizontalBox(CareActionSize)->SetVerticalAlignment(VAlign_Fill);
    UBorder* CareActionBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("CareActionBorder"));
    DMFNativeUI::StylePanel(CareActionBorder, DMFNativeUI::PanelRaised(), FMargin(16.0f)); CareActionSize->AddChild(CareActionBorder);
    UVerticalBox* CareActionColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("CareActionColumn")); CareActionBorder->AddChild(CareActionColumn);
    UTextBlock* FeedingHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("FeedingHeader")); FeedingHeader->SetText(NSLOCTEXT("DMF","FeedingHeader","DIGIMEAT FEEDING")); DMFNativeUI::StyleText(FeedingHeader,14,DMFNativeUI::Gold(),true); CareActionColumn->AddChildToVerticalBox(FeedingHeader)->SetPadding(FMargin(0,0,0,10));
    CareFeedingRulesText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareFeedingRulesText")); CareFeedingRulesText->SetAutoWrapText(true); DMFNativeUI::StyleText(CareFeedingRulesText,13,DMFNativeUI::Text()); CareActionColumn->AddChildToVerticalBox(CareFeedingRulesText)->SetPadding(FMargin(0,0,0,12));
    UBorder* WasteBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("WasteStatusBorder")); DMFNativeUI::StylePanel(WasteBorder,DMFNativeUI::PanelSoft(),FMargin(12)); CareActionColumn->AddChildToVerticalBox(WasteBorder)->SetPadding(FMargin(0,0,0,10));
    CareWasteStatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareWasteStatusText")); CareWasteStatusText->SetAutoWrapText(true); DMFNativeUI::StyleText(CareWasteStatusText,13,DMFNativeUI::Muted()); WasteBorder->AddChild(CareWasteStatusText);
    UScrollBox* CareSafetyScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("CareSafetyScroll"));
    if (UVerticalBoxSlot* CareSafetyLayoutSlot = CareActionColumn->AddChildToVerticalBox(CareSafetyScroll)) { CareSafetyLayoutSlot->SetSize(DMFNativeUI::FillSize()); CareSafetyLayoutSlot->SetPadding(FMargin(0,0,0,10)); }
    UTextBlock* CareSafetyText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CareSafetyText"));
    CareSafetyText->SetText(NSLOCTEXT("DMF","CareSafetyText","CARE RULES\n• Feeding is server-authoritative.\n• Combat is paused while eating.\n• Waste has zero collision and cleans itself up automatically."));
    CareSafetyText->SetAutoWrapText(true); DMFNativeUI::StyleText(CareSafetyText,12,DMFNativeUI::Muted());
    CareSafetyScroll->AddChild(CareSafetyText);
    FeedDigiMeatButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("FeedDigiMeatButton")); DMFNativeUI::StyleButton(FeedDigiMeatButton,true);
    UTextBlock* FeedLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("FeedDigiMeatLabel")); FeedLabel->SetText(NSLOCTEXT("DMF","FeedDigiMeatUntilFull","FEED DIGIMEAT UNTIL FULL")); FeedLabel->SetJustification(ETextJustify::Center); FeedLabel->SetAutoWrapText(true); DMFNativeUI::StyleText(FeedLabel,14,DMFNativeUI::Text(),true); FeedDigiMeatButton->AddChild(FeedLabel); CareActionColumn->AddChildToVerticalBox(FeedDigiMeatButton);
}

void UDMFDigimonInventoryWidget::BindDigimonComponent()
{
    APlayerController* OwningController = GetOwningPlayer();
    ADMFPlayerState* FrameworkPlayerState = OwningController ? OwningController->GetPlayerState<ADMFPlayerState>() : nullptr;
    UDMFPlayerDigimonComponent* NewComponent = FrameworkPlayerState ? FrameworkPlayerState->DigimonComponent : nullptr;
    if (BoundDigimonComponent == NewComponent)
    {
        return;
    }

    if (BoundDigimonComponent)
    {
        BoundDigimonComponent->OnDigimonInventoryChanged.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleInventoryChanged);
        BoundDigimonComponent->OnDigimonBankChanged.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleBankChanged);
        BoundDigimonComponent->OnDigimonStorageActionResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleStorageActionResult);
        BoundDigimonComponent->OnAttributePointSpendResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleAttributePointSpendResult);
        BoundDigimonComponent->OnPartnerActionResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandlePartnerActionResult);
        BoundDigimonComponent->OnScanDataChanged.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleScanDataChanged);
        BoundDigimonComponent->OnMaterializationResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleMaterializationResult);
        BoundDigimonComponent->OnCareStateChanged.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleCareStateChanged);
        BoundDigimonComponent->OnCareSequenceFinished.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleCareSequenceFinished);
        BoundDigimonComponent->OnDigivolutionResult.RemoveDynamic(this, &UDMFDigimonInventoryWidget::HandleDigivolutionResult);
    }

    BoundDigimonComponent = NewComponent;
    if (BoundDigimonComponent)
    {
        BoundDigimonComponent->OnDigimonInventoryChanged.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleInventoryChanged);
        BoundDigimonComponent->OnDigimonBankChanged.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleBankChanged);
        BoundDigimonComponent->OnDigimonStorageActionResult.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleStorageActionResult);
        BoundDigimonComponent->OnAttributePointSpendResult.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleAttributePointSpendResult);
        BoundDigimonComponent->OnPartnerActionResult.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandlePartnerActionResult);
        BoundDigimonComponent->OnScanDataChanged.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleScanDataChanged);
        BoundDigimonComponent->OnMaterializationResult.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleMaterializationResult);
        BoundDigimonComponent->OnCareStateChanged.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleCareStateChanged);
        BoundDigimonComponent->OnCareSequenceFinished.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleCareSequenceFinished);
        BoundDigimonComponent->OnDigivolutionResult.AddUniqueDynamic(this, &UDMFDigimonInventoryWidget::HandleDigivolutionResult);
    }
}

UDMFDigimonSpeciesData* UDMFDigimonInventoryWidget::ResolveSpecies(const FPrimaryAssetId SpeciesId) const
{
    if (!SpeciesId.IsValid())
    {
        return nullptr;
    }

    if (BoundDigimonComponent)
    {
        if (UDMFDigimonSpeciesData* Resolved = BoundDigimonComponent->ResolveDigimonSpecies(SpeciesId))
        {
            return Resolved;
        }
    }

    UAssetManager& AssetManager = UAssetManager::Get();
    if (UDMFDigimonSpeciesData* LoadedSpecies = AssetManager.GetPrimaryAssetObject<UDMFDigimonSpeciesData>(SpeciesId))
    {
        return LoadedSpecies;
    }
    const FSoftObjectPath SpeciesPath = AssetManager.GetPrimaryAssetPath(SpeciesId);
    if (SpeciesPath.IsValid())
    {
        if (UDMFDigimonSpeciesData* LoadedSpecies = Cast<UDMFDigimonSpeciesData>(SpeciesPath.TryLoad()))
        {
            return LoadedSpecies;
        }
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UDMFStarterRosterData* Roster = Settings ? Settings->StarterRoster.LoadSynchronous() : nullptr;
    if (Roster)
    {
        for (const FDMFStarterRosterEntry& RosterEntry : Roster->Starters)
        {
            UDMFDigimonSpeciesData* CandidateSpecies = RosterEntry.Species.LoadSynchronous();
            if (CandidateSpecies && CandidateSpecies->GetPrimaryAssetId() == SpeciesId)
            {
                return CandidateSpecies;
            }
        }
    }
    return nullptr;
}

void UDMFDigimonInventoryWidget::RefreshInventory()
{
    BindDigimonComponent();
    if (!WidgetTree || !BoundDigimonComponent || (!DigimonGrid && !DigimonChoicesBox))
    {
        return;
    }

    const TArray<FDMFDigimonInstance> Inventory = BoundDigimonComponent->GetPartyDigimon();
    const FGuid ActiveId = BoundDigimonComponent->GetActivePartnerInstanceId();
    const bool bActiveSummoned = BoundDigimonComponent->IsActivePartnerSummoned();
    const int32 Capacity = BoundDigimonComponent->GetPartyCapacity();

    // Reliable result RPCs and owner-only FastArray replication may arrive in either order. Resolve any
    // pending post-mutation/materialization selection from the authoritative replicated Party once it exists.
    if (PendingStorageSelectionId.IsValid())
    {
        const bool bPendingIsInParty = Inventory.ContainsByPredicate([&](const FDMFDigimonInstance& Digimon)
        {
            return Digimon.InstanceId == PendingStorageSelectionId;
        });
        if (bPendingIsInParty)
        {
            SelectedInstanceId = PendingStorageSelectionId;
            SelectedBankInstanceId.Invalidate();
            SelectedBankPartyDestinationIndex = INDEX_NONE;
            ActiveMenuTab = EDMFDigimonMenuTab::Collection;
            PendingStorageSelectionId.Invalidate();
            RefreshTabPresentation();
        }
    }

    if (DigimonGrid)
    {
        DigimonGrid->ClearChildren();
    }
    if (DigimonChoicesBox)
    {
        DigimonChoicesBox->ClearChildren();
    }

    if (InventoryCountText)
    {
        InventoryCountText->SetText(FText::Format(
            NSLOCTEXT("DMF", "InventoryCapacityFormat", "{0} / {1} PARTY"),
            FText::AsNumber(Inventory.Num()),
            FText::AsNumber(Capacity)));
    }

    bool bSelectionStillExists = false;
    int32 ValidInventoryIndex = 0;
    for (const FDMFDigimonInstance& Digimon : Inventory)
    {
        if (!Digimon.IsValid())
        {
            continue;
        }

        UDMFDigimonSpeciesData* Species = ResolveSpecies(Digimon.SpeciesId);
        const FText Name = Species && !Species->DisplayName.IsEmpty()
            ? Species->DisplayName
            : FText::FromName(Digimon.SpeciesId.PrimaryAssetName);

        UDMFDigimonInventoryEntryButton* EntryButton = WidgetTree->ConstructWidget<UDMFDigimonInventoryEntryButton>(UDMFDigimonInventoryEntryButton::StaticClass());
        EntryButton->InitializeDigimonEntry(Digimon.InstanceId);
        EntryButton->OnDigimonPressed.AddDynamic(this, &UDMFDigimonInventoryWidget::HandleDigimonPressed);
        DMFNativeUI::StyleCompactButton(EntryButton, false, false, Digimon.InstanceId == SelectedInstanceId);

        UOverlay* SlotOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass());
        EntryButton->AddChild(SlotOverlay);

        UBorder* SlotBackground = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(SlotBackground, Digimon.CurrentHP <= 0 ? FLinearColor(0.16f, 0.025f, 0.035f, 0.92f) : DMFNativeUI::SlotEmpty(), FMargin(3.0f));
        if (UOverlaySlot* BackgroundSlot = SlotOverlay->AddChildToOverlay(SlotBackground))
        {
            BackgroundSlot->SetHorizontalAlignment(HAlign_Fill);
            BackgroundSlot->SetVerticalAlignment(VAlign_Fill);
        }

        UImage* PortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
        UTexture2D* PortraitTexture = Species ? Species->Portrait.LoadSynchronous() : nullptr;
        if (PortraitTexture)
        {
            PortraitImage->SetBrushFromTexture(PortraitTexture, true);
            PortraitImage->SetColorAndOpacity(Digimon.CurrentHP <= 0 ? FLinearColor(0.55f, 0.55f, 0.55f, 1.0f) : FLinearColor::White);
        }
        else
        {
            PortraitImage->SetColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.0f));
        }
        if (UOverlaySlot* PortraitSlot = SlotOverlay->AddChildToOverlay(PortraitImage))
        {
            PortraitSlot->SetPadding(FMargin(7.0f, 7.0f, 7.0f, 31.0f));
            PortraitSlot->SetHorizontalAlignment(HAlign_Fill);
            PortraitSlot->SetVerticalAlignment(VAlign_Fill);
        }

        if (!PortraitTexture)
        {
            UTextBlock* MissingPortraitText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            MissingPortraitText->SetText(NSLOCTEXT("DMF", "PortraitNotAssigned", "PORTRAIT\nNOT SET"));
            MissingPortraitText->SetJustification(ETextJustify::Center);
            DMFNativeUI::StyleText(MissingPortraitText, 11, DMFNativeUI::Muted(), true);
            if (UOverlaySlot* MissingPortraitSlot = SlotOverlay->AddChildToOverlay(MissingPortraitText))
            {
                MissingPortraitSlot->SetPadding(FMargin(8.0f, 22.0f, 8.0f, 34.0f));
                MissingPortraitSlot->SetHorizontalAlignment(HAlign_Center);
                MissingPortraitSlot->SetVerticalAlignment(VAlign_Center);
            }
        }

        UBorder* NameStrip = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(NameStrip, FLinearColor(0.005f, 0.015f, 0.035f, 0.94f), FMargin(4.0f, 3.0f));
        UTextBlock* SlotNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        SlotNameText->SetText(FText::Format(NSLOCTEXT("DMF", "InventorySlotNameLevel", "{0}  •  Lv.{1}"), Name, FText::AsNumber(Digimon.Stats.Level)));
        SlotNameText->SetJustification(ETextJustify::Center);
        DMFNativeUI::StyleText(SlotNameText, 11, DMFNativeUI::Text(), true);
        NameStrip->AddChild(SlotNameText);
        if (UOverlaySlot* NameStripSlot = SlotOverlay->AddChildToOverlay(NameStrip))
        {
            NameStripSlot->SetHorizontalAlignment(HAlign_Fill);
            NameStripSlot->SetVerticalAlignment(VAlign_Bottom);
        }

        FString BadgeString;
        FLinearColor BadgeColor = DMFNativeUI::AccentSoft();
        if (Digimon.CurrentHP <= 0)
        {
            BadgeString = TEXT("KO");
            BadgeColor = DMFNativeUI::Danger();
        }
        else if (Digimon.InstanceId == ActiveId)
        {
            BadgeString = bActiveSummoned ? TEXT("SUMMONED") : TEXT("ACTIVE");
            BadgeColor = DMFNativeUI::Success();
        }

        if (!BadgeString.IsEmpty())
        {
            UBorder* BadgeBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
            DMFNativeUI::StylePanel(BadgeBorder, BadgeColor, FMargin(5.0f, 2.0f));
            UTextBlock* BadgeText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            BadgeText->SetText(FText::FromString(BadgeString));
            DMFNativeUI::StyleText(BadgeText, 9, FLinearColor::White, true);
            BadgeBorder->AddChild(BadgeText);
            if (UOverlaySlot* BadgeSlot = SlotOverlay->AddChildToOverlay(BadgeBorder))
            {
                BadgeSlot->SetPadding(FMargin(5.0f));
                BadgeSlot->SetHorizontalAlignment(HAlign_Right);
                BadgeSlot->SetVerticalAlignment(VAlign_Top);
            }
        }

        USizeBox* EntrySize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        EntrySize->SetWidthOverride(DMFInventoryUI::SlotSize);
        EntrySize->SetHeightOverride(DMFInventoryUI::SlotSize);
        EntrySize->AddChild(EntryButton);

        if (DigimonGrid)
        {
            const int32 Row = ValidInventoryIndex / DMFInventoryUI::Columns;
            const int32 Column = ValidInventoryIndex % DMFInventoryUI::Columns;
            if (UUniformGridSlot* GridSlot = DigimonGrid->AddChildToUniformGrid(EntrySize, Row, Column))
            {
                GridSlot->SetHorizontalAlignment(HAlign_Fill);
                GridSlot->SetVerticalAlignment(VAlign_Fill);
            }
        }
        else if (DigimonChoicesBox)
        {
            DigimonChoicesBox->AddChildToVerticalBox(EntryButton);
        }

        bSelectionStillExists |= Digimon.InstanceId == SelectedInstanceId;
        ++ValidInventoryIndex;
    }

    if (DigimonGrid)
    {
        for (int32 SlotIndex = ValidInventoryIndex; SlotIndex < Capacity; ++SlotIndex)
        {
            USizeBox* EmptySize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
            EmptySize->SetWidthOverride(DMFInventoryUI::SlotSize);
            EmptySize->SetHeightOverride(DMFInventoryUI::SlotSize);

            UBorder* EmptyBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
            DMFNativeUI::StylePanel(EmptyBorder, DMFNativeUI::SlotEmpty(), FMargin(6.0f));
            EmptySize->AddChild(EmptyBorder);

            UVerticalBox* EmptyColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
            EmptyBorder->AddChild(EmptyColumn);

            UTextBlock* EmptyIndexText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            EmptyIndexText->SetText(FText::Format(NSLOCTEXT("DMF", "EmptySlotIndex", "SLOT {0}"), FText::AsNumber(SlotIndex + 1)));
            EmptyIndexText->SetJustification(ETextJustify::Center);
            DMFNativeUI::StyleText(EmptyIndexText, 9, FLinearColor(0.22f, 0.34f, 0.47f, 1.0f), true);
            EmptyColumn->AddChildToVerticalBox(EmptyIndexText)->SetPadding(FMargin(0.0f, 12.0f, 0.0f, 0.0f));

            UTextBlock* EmptyLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            EmptyLabel->SetText(NSLOCTEXT("DMF", "EmptyDigimonSlot", "EMPTY"));
            EmptyLabel->SetJustification(ETextJustify::Center);
            DMFNativeUI::StyleText(EmptyLabel, 12, FLinearColor(0.26f, 0.39f, 0.52f, 1.0f), true);
            if (UVerticalBoxSlot* EmptyLabelSlot = EmptyColumn->AddChildToVerticalBox(EmptyLabel))
            {
                EmptyLabelSlot->SetSize(DMFNativeUI::FillSize());
                EmptyLabelSlot->SetVerticalAlignment(VAlign_Center);
            }

            const int32 Row = SlotIndex / DMFInventoryUI::Columns;
            const int32 Column = SlotIndex % DMFInventoryUI::Columns;
            DigimonGrid->AddChildToUniformGrid(EmptySize, Row, Column);
        }
    }

    if (!bSelectionStillExists)
    {
        SelectedInstanceId.Invalidate();
    }

    if (DigimonStatusText)
    {
        DigimonStatusText->SetText(Inventory.IsEmpty()
            ? NSLOCTEXT("DMF", "DigimonInventoryEmpty", "Your Party is empty. Move a Digimon from the Bank into Party.")
            : NSLOCTEXT("DMF", "DigimonInventoryPrompt", "Select a Party Digimon to inspect, summon, recall or move it into the Bank."));
        DigimonStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));
    }

    RefreshSelectedDetails();
}

void UDMFDigimonInventoryWidget::RefreshBankData()
{
    BindDigimonComponent();
    if (!BoundDigimonComponent || !WidgetTree)
    {
        return;
    }

    const TArray<FDMFDigimonInstance> Bank = BoundDigimonComponent->GetBankDigimon();
    const TArray<FDMFDigimonInstance> Party = BoundDigimonComponent->GetPartyDigimon();
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const int32 PageSize = FMath::Clamp(Settings ? Settings->DigimonBankSlotsPerPage : 30, 6, 60);
    const int32 Capacity = BoundDigimonComponent->GetBankCapacity();

    // Resolve pending selection from replicated Bank data and jump to the exact Box containing it. This
    // makes storage/materialization presentation deterministic regardless of RPC vs FastArray delivery order.
    if (PendingStorageSelectionId.IsValid())
    {
        const int32 PendingBankIndex = Bank.IndexOfByPredicate([&](const FDMFDigimonInstance& Digimon)
        {
            return Digimon.InstanceId == PendingStorageSelectionId;
        });
        if (PendingBankIndex != INDEX_NONE)
        {
            SelectedBankInstanceId = PendingStorageSelectionId;
            SelectedInstanceId.Invalidate();
            SelectedBankPartyDestinationIndex = INDEX_NONE;
            BankPageIndex = PendingBankIndex / PageSize;
            ActiveMenuTab = EDMFDigimonMenuTab::Bank;
            PendingStorageSelectionId.Invalidate();
            RefreshTabPresentation();
        }
    }

    const int32 TotalPages = FMath::Max(1, FMath::CeilToInt(static_cast<float>(FMath::Max(Capacity, Bank.Num())) / static_cast<float>(PageSize)));
    BankPageIndex = FMath::Clamp(BankPageIndex, 0, TotalPages - 1);

    if (BankCountText)
    {
        BankCountText->SetText(FText::Format(NSLOCTEXT("DMF", "BankCapacityFormat", "{0} / {1} STORED"), FText::AsNumber(Bank.Num()), FText::AsNumber(Capacity)));
    }
    if (BankPageText)
    {
        BankPageText->SetText(FText::Format(NSLOCTEXT("DMF", "BankPageFormat", "BOX {0} / {1}"), FText::AsNumber(BankPageIndex + 1), FText::AsNumber(TotalPages)));
    }
    if (BankPreviousPageButton)
    {
        BankPreviousPageButton->SetIsEnabled(BankPageIndex > 0);
    }
    if (BankNextPageButton)
    {
        BankNextPageButton->SetIsEnabled(BankPageIndex + 1 < TotalPages);
    }

    bool bSelectionStillExists = false;
    if (BankDigimonGrid)
    {
        BankDigimonGrid->ClearChildren();
        const int32 PageStart = BankPageIndex * PageSize;
        const int32 PageEnd = FMath::Min(PageStart + PageSize, FMath::Max(Capacity, Bank.Num()));
        for (int32 AbsoluteSlot = PageStart; AbsoluteSlot < PageEnd; ++AbsoluteSlot)
        {
            const int32 LocalSlot = AbsoluteSlot - PageStart;
            const int32 Row = LocalSlot / DMFInventoryUI::Columns;
            const int32 Column = LocalSlot % DMFInventoryUI::Columns;

            USizeBox* SlotSizeBox = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
            SlotSizeBox->SetWidthOverride(DMFInventoryUI::BankSlotSize);
            SlotSizeBox->SetHeightOverride(DMFInventoryUI::BankSlotSize);

            if (Bank.IsValidIndex(AbsoluteSlot) && Bank[AbsoluteSlot].IsValid())
            {
                const FDMFDigimonInstance& Digimon = Bank[AbsoluteSlot];
                bSelectionStillExists |= Digimon.InstanceId == SelectedBankInstanceId;
                UDMFDigimonSpeciesData* Species = ResolveSpecies(Digimon.SpeciesId);
                const FText SpeciesName = Species && !Species->DisplayName.IsEmpty() ? Species->DisplayName : FText::FromName(Digimon.SpeciesId.PrimaryAssetName);
                const FText DisplayName = Digimon.Nickname.IsEmpty() ? SpeciesName : FText::FromString(Digimon.Nickname);

                UDMFDigimonInventoryEntryButton* EntryButton = WidgetTree->ConstructWidget<UDMFDigimonInventoryEntryButton>(UDMFDigimonInventoryEntryButton::StaticClass());
                EntryButton->InitializeDigimonEntry(Digimon.InstanceId);
                EntryButton->OnDigimonPressed.AddDynamic(this, &UDMFDigimonInventoryWidget::HandleBankDigimonPressed);
                DMFNativeUI::StyleCompactButton(EntryButton, false, false, Digimon.InstanceId == SelectedBankInstanceId);

                UOverlay* SlotOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass());
                EntryButton->AddChild(SlotOverlay);
                UBorder* SlotBackground = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
                DMFNativeUI::StylePanel(SlotBackground, Digimon.CurrentHP <= 0 ? FLinearColor(0.15f,0.025f,0.035f,0.94f) : DMFNativeUI::SlotEmpty(), FMargin(2.0f));
                if (UOverlaySlot* BackgroundSlot = SlotOverlay->AddChildToOverlay(SlotBackground))
                {
                    BackgroundSlot->SetHorizontalAlignment(HAlign_Fill);
                    BackgroundSlot->SetVerticalAlignment(VAlign_Fill);
                }

                UImage* Portrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
                if (UTexture2D* Texture = Species ? Species->Portrait.LoadSynchronous() : nullptr)
                {
                    Portrait->SetBrushFromTexture(Texture, true);
                    Portrait->SetColorAndOpacity(Digimon.CurrentHP <= 0 ? FLinearColor(0.5f,0.5f,0.5f,1.0f) : FLinearColor::White);
                }
                else
                {
                    Portrait->SetColorAndOpacity(FLinearColor(0,0,0,0));
                }
                if (UOverlaySlot* PortraitSlot = SlotOverlay->AddChildToOverlay(Portrait))
                {
                    PortraitSlot->SetPadding(FMargin(5,5,5,25));
                    PortraitSlot->SetHorizontalAlignment(HAlign_Fill);
                    PortraitSlot->SetVerticalAlignment(VAlign_Fill);
                }

                UBorder* LabelStrip = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
                DMFNativeUI::StylePanel(LabelStrip, FLinearColor(0.004f,0.012f,0.03f,0.95f), FMargin(3,2));
                UTextBlock* Label = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
                Label->SetText(FText::Format(NSLOCTEXT("DMF", "BankSlotLabel", "{0}  Lv.{1}"), DisplayName, FText::AsNumber(Digimon.Stats.Level)));
                Label->SetJustification(ETextJustify::Center);
                DMFNativeUI::StyleText(Label, 9, DMFNativeUI::Text(), true);
                LabelStrip->AddChild(Label);
                if (UOverlaySlot* LabelSlot = SlotOverlay->AddChildToOverlay(LabelStrip))
                {
                    LabelSlot->SetHorizontalAlignment(HAlign_Fill);
                    LabelSlot->SetVerticalAlignment(VAlign_Bottom);
                }

                if (Digimon.CurrentHP <= 0)
                {
                    UBorder* KOBadge = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
                    DMFNativeUI::StylePanel(KOBadge, DMFNativeUI::Danger(), FMargin(4,1));
                    UTextBlock* KOText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
                    KOText->SetText(NSLOCTEXT("DMF", "BankKOBadge", "KO"));
                    DMFNativeUI::StyleText(KOText, 8, FLinearColor::White, true);
                    KOBadge->AddChild(KOText);
                    if (UOverlaySlot* BadgeSlot = SlotOverlay->AddChildToOverlay(KOBadge))
                    {
                        BadgeSlot->SetPadding(FMargin(3));
                        BadgeSlot->SetHorizontalAlignment(HAlign_Right);
                        BadgeSlot->SetVerticalAlignment(VAlign_Top);
                    }
                }

                SlotSizeBox->AddChild(EntryButton);
            }
            else
            {
                UBorder* EmptyBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
                DMFNativeUI::StylePanel(EmptyBorder, DMFNativeUI::SlotEmpty(), FMargin(4.0f));
                UVerticalBox* EmptyColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
                EmptyBorder->AddChild(EmptyColumn);
                UTextBlock* IndexLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
                IndexLabel->SetText(FText::Format(NSLOCTEXT("DMF", "BankEmptySlotNumber", "#{0}"), FText::AsNumber(AbsoluteSlot + 1)));
                IndexLabel->SetJustification(ETextJustify::Center);
                DMFNativeUI::StyleText(IndexLabel, 9, FLinearColor(0.2f,0.32f,0.43f,1), true);
                EmptyColumn->AddChildToVerticalBox(IndexLabel)->SetPadding(FMargin(0,8,0,0));
                UTextBlock* EmptyLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
                EmptyLabel->SetText(NSLOCTEXT("DMF", "BankEmptySlot", "EMPTY"));
                EmptyLabel->SetJustification(ETextJustify::Center);
                DMFNativeUI::StyleText(EmptyLabel, 10, FLinearColor(0.24f,0.38f,0.5f,1), true);
                if (UVerticalBoxSlot* EmptyLabelSlot = EmptyColumn->AddChildToVerticalBox(EmptyLabel))
                {
                    EmptyLabelSlot->SetSize(DMFNativeUI::FillSize());
                    EmptyLabelSlot->SetVerticalAlignment(VAlign_Center);
                }
                SlotSizeBox->AddChild(EmptyBorder);
            }

            if (UUniformGridSlot* GridSlot = BankDigimonGrid->AddChildToUniformGrid(SlotSizeBox, Row, Column))
            {
                GridSlot->SetHorizontalAlignment(HAlign_Fill);
                GridSlot->SetVerticalAlignment(VAlign_Fill);
            }
        }
    }

    if (!bSelectionStillExists)
    {
        SelectedBankInstanceId.Invalidate();
    }

    if (BankPartyDestinationGrid)
    {
        BankPartyDestinationGrid->ClearChildren();
        const int32 PartyCapacity = BoundDigimonComponent->GetPartyCapacity();
        for (int32 PartySlot = 0; PartySlot < PartyCapacity; ++PartySlot)
        {
            UDMFPartyDestinationButton* Button = WidgetTree->ConstructWidget<UDMFPartyDestinationButton>(UDMFPartyDestinationButton::StaticClass());
            Button->InitializePartyDestination(PartySlot);
            Button->OnPartyDestinationPressed.AddDynamic(this, &UDMFDigimonInventoryWidget::HandleBankPartyDestinationPressed);
            DMFNativeUI::StyleCompactButton(Button, false, false, PartySlot == SelectedBankPartyDestinationIndex);

            USizeBox* DestinationSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
            DestinationSize->SetWidthOverride(DMFInventoryUI::PartyDestinationSlotWidth);
            DestinationSize->SetHeightOverride(62.0f);
            UVerticalBox* DestinationColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
            Button->AddChild(DestinationColumn);
            UTextBlock* SlotText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            SlotText->SetText(FText::Format(NSLOCTEXT("DMF", "BankPartyDestinationNumber", "PARTY {0}"), FText::AsNumber(PartySlot + 1)));
            SlotText->SetJustification(ETextJustify::Center);
            DMFNativeUI::StyleText(SlotText, 9, PartySlot == SelectedBankPartyDestinationIndex ? DMFNativeUI::Gold() : DMFNativeUI::Muted(), true);
            DestinationColumn->AddChildToVerticalBox(SlotText);
            UTextBlock* NameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            FText PartyName = NSLOCTEXT("DMF", "BankPartyEmptyDestination", "EMPTY");
            if (Party.IsValidIndex(PartySlot))
            {
                const FDMFDigimonInstance& PartyDigimon = Party[PartySlot];
                UDMFDigimonSpeciesData* PartySpecies = ResolveSpecies(PartyDigimon.SpeciesId);
                PartyName = !PartyDigimon.Nickname.IsEmpty() ? FText::FromString(PartyDigimon.Nickname)
                    : (PartySpecies && !PartySpecies->DisplayName.IsEmpty() ? PartySpecies->DisplayName : FText::FromName(PartyDigimon.SpeciesId.PrimaryAssetName));
            }
            NameText->SetText(PartyName);
            NameText->SetJustification(ETextJustify::Center);
            DMFNativeUI::StyleText(NameText, 10, DMFNativeUI::Text(), true);
            DestinationColumn->AddChildToVerticalBox(NameText);
            DestinationSize->AddChild(Button);
            BankPartyDestinationGrid->AddChildToUniformGrid(DestinationSize, 0, PartySlot);
        }
    }

    RefreshSelectedBankDetails();
}

void UDMFDigimonInventoryWidget::RefreshSelectedBankDetails()
{
    if (!BoundDigimonComponent)
    {
        return;
    }

    FDMFDigimonInstance Digimon;
    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Bank;
    const bool bHasSelection = SelectedBankInstanceId.IsValid()
        && BoundDigimonComponent->GetOwnedDigimonByInstanceId(SelectedBankInstanceId, Digimon, Location)
        && Location == EDMFDigimonStorageLocation::Bank;

    const TArray<FDMFDigimonInstance> Party = BoundDigimonComponent->GetPartyDigimon();
    const bool bPartyHasRoom = Party.Num() < BoundDigimonComponent->GetPartyCapacity();
    const bool bDestinationChosen = SelectedBankPartyDestinationIndex >= 0 && SelectedBankPartyDestinationIndex < BoundDigimonComponent->GetPartyCapacity();
    if (MoveSelectedBankToPartyButton)
    {
        MoveSelectedBankToPartyButton->SetIsEnabled(bHasSelection && (bPartyHasRoom || bDestinationChosen));
    }
    SetBankAttributeSpendEnabled(false);
    if (bHasSelection)
    {
        auto UpdateSpendButton = [&](UButton* Button, const EDMFDigimonAttributeStat Stat)
        {
            if (!Button) return;
            FText Failure;
            Button->SetIsEnabled(BoundDigimonComponent->CanSpendDigimonAttributePoint(Digimon.InstanceId, Stat, Failure));
        };
        UpdateSpendButton(SpendBankHPButton, EDMFDigimonAttributeStat::MaxHP);
        UpdateSpendButton(SpendBankSPButton, EDMFDigimonAttributeStat::MaxSP);
        UpdateSpendButton(SpendBankStrengthButton, EDMFDigimonAttributeStat::Strength);
        UpdateSpendButton(SpendBankIntelligenceButton, EDMFDigimonAttributeStat::Intelligence);
        UpdateSpendButton(SpendBankDefenseButton, EDMFDigimonAttributeStat::Defense);
        UpdateSpendButton(SpendBankSpeedButton, EDMFDigimonAttributeStat::Speed);
    }

    if (!bHasSelection)
    {
        if (BankSelectedPortraitImage) BankSelectedPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        if (BankSelectedNameText) BankSelectedNameText->SetText(NSLOCTEXT("DMF", "BankNoSelectionName", "NO BANK DIGIMON SELECTED"));
        if (BankSelectedMetaText) BankSelectedMetaText->SetText(NSLOCTEXT("DMF", "BankNoSelectionMeta", "Choose a stored Digimon from the current Box."));
        if (BankSelectedStatsText) BankSelectedStatsText->SetText(NSLOCTEXT("DMF", "BankNoSelectionStats", "LEVEL  --\nHP     -- / --\nSP     -- / --\n\nSelect a Bank Digimon to inspect it and move or swap it into your active Party."));
        if (BankSelectionText)
        {
            BankSelectionText->SetText(bPartyHasRoom
                ? NSLOCTEXT("DMF", "BankDestinationOptional", "Party has room: MOVE / SWAP appends automatically, or choose a specific Party slot.")
                : NSLOCTEXT("DMF", "BankDestinationRequired", "Party is full: select one of the six Party destination slots to perform an atomic swap."));
        }
        return;
    }

    UDMFDigimonSpeciesData* Species = ResolveSpecies(Digimon.SpeciesId);
    const FText SpeciesName = Species && !Species->DisplayName.IsEmpty() ? Species->DisplayName : FText::FromName(Digimon.SpeciesId.PrimaryAssetName);
    const FText DisplayName = Digimon.Nickname.IsEmpty() ? SpeciesName : FText::FromString(Digimon.Nickname);
    if (BankSelectedPortraitImage)
    {
        if (UTexture2D* Texture = Species ? Species->Portrait.LoadSynchronous() : nullptr)
        {
            BankSelectedPortraitImage->SetBrushFromTexture(Texture, true);
            BankSelectedPortraitImage->SetColorAndOpacity(Digimon.CurrentHP <= 0 ? FLinearColor(0.55f,0.55f,0.55f,1) : FLinearColor::White);
            BankSelectedPortraitImage->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            BankSelectedPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        }
    }
    if (BankSelectedNameText) BankSelectedNameText->SetText(DisplayName);
    if (BankSelectedMetaText)
    {
        const FText Stage = Species ? UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage) : FText::GetEmpty();
        const FText Attribute = Species ? DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), static_cast<int64>(Species->Attribute)) : FText::GetEmpty();
        BankSelectedMetaText->SetText(FText::Format(NSLOCTEXT("DMF", "BankSelectedMetaFormat", "Lv.{0}  •  {1}  •  {2}"), FText::AsNumber(Digimon.Stats.Level), Stage, Attribute));
    }
    const int64 BankExperienceRequired = BoundDigimonComponent->GetExperienceRequiredForLevel(Digimon.SpeciesId, Digimon.Stats.Level);
    const bool bBankMaxLevel = BankExperienceRequired <= 0;
    if (BankSelectedStatsText)
    {
        const FText ExperienceDisplay = bBankMaxLevel
            ? NSLOCTEXT("DMF", "BankMaxExperience", "MAX")
            : FText::Format(NSLOCTEXT("DMF", "BankExperienceFraction", "{0} / {1}"), FText::AsNumber(Digimon.Stats.Experience), FText::AsNumber(BankExperienceRequired));
        BankSelectedStatsText->SetText(FText::Format(NSLOCTEXT("DMF", "BankStatsFormat", "EXP    {0}\nHP     {1} / {2}\nSP     {3} / {4}\n\nSTR {5}     INT {6}\nDEF {7}     SPD {8}\nABI {9}     CAM {10}\nATTRIBUTE PTS  {11}\n\nStored safely in the account-owned Digimon Bank."),
            ExperienceDisplay, FText::AsNumber(Digimon.CurrentHP), FText::AsNumber(Digimon.Stats.MaxHP), FText::AsNumber(Digimon.CurrentSP), FText::AsNumber(Digimon.Stats.MaxSP),
            FText::AsNumber(Digimon.Stats.Strength), FText::AsNumber(Digimon.Stats.Intelligence), FText::AsNumber(Digimon.Stats.Defense), FText::AsNumber(Digimon.Stats.Speed),
            FText::AsNumber(Digimon.Stats.ABI), FText::AsNumber(Digimon.Stats.CAM), FText::AsNumber(Digimon.UnspentAttributePoints)));
    }
    if (BankExperienceProgressBar)
    {
        BankExperienceProgressBar->SetPercent(bBankMaxLevel ? 1.0f : BoundDigimonComponent->GetExperienceProgressNormalized(Digimon.InstanceId));
    }
    if (BankSelectionText)
    {
        if (bDestinationChosen)
        {
            BankSelectionText->SetText(FText::Format(NSLOCTEXT("DMF", "BankSelectedDestination", "Destination: PARTY SLOT {0}. If occupied, the current Party Digimon moves back into Bank atomically."), FText::AsNumber(SelectedBankPartyDestinationIndex + 1)));
        }
        else if (bPartyHasRoom)
        {
            BankSelectionText->SetText(NSLOCTEXT("DMF", "BankAutoDestination", "No destination selected. The Digimon will be appended to the first free Party slot."));
        }
        else
        {
            BankSelectionText->SetText(NSLOCTEXT("DMF", "BankNeedDestination", "Party is full. Choose a Party destination slot before moving this Digimon."));
        }
    }
}

void UDMFDigimonInventoryWidget::RefreshSelectedDetails()
{
    if (!BoundDigimonComponent)
    {
        return;
    }

    FDMFDigimonInstance Digimon;
    const bool bHasSelection = SelectedInstanceId.IsValid() && BoundDigimonComponent->GetDigimonByInstanceId(SelectedInstanceId, Digimon);
    if (SummonDigimonButton)
    {
        SummonDigimonButton->SetIsEnabled(bHasSelection && Digimon.CurrentHP > 0);
    }
    if (RecallDigimonButton)
    {
        RecallDigimonButton->SetIsEnabled(BoundDigimonComponent->IsActivePartnerSummoned());
    }
    if (MoveSelectedToBankButton)
    {
        MoveSelectedToBankButton->SetIsEnabled(bHasSelection && BoundDigimonComponent->GetPartyDigimon().Num() > 1 && BoundDigimonComponent->GetBankDigimon().Num() < BoundDigimonComponent->GetBankCapacity());
    }
    SetPartyAttributeSpendEnabled(false);
    if (bHasSelection)
    {
        auto UpdateSpendButton = [&](UButton* Button, const EDMFDigimonAttributeStat Stat)
        {
            if (!Button) return;
            FText Failure;
            Button->SetIsEnabled(BoundDigimonComponent->CanSpendDigimonAttributePoint(Digimon.InstanceId, Stat, Failure));
        };
        UpdateSpendButton(SpendPartyHPButton, EDMFDigimonAttributeStat::MaxHP);
        UpdateSpendButton(SpendPartySPButton, EDMFDigimonAttributeStat::MaxSP);
        UpdateSpendButton(SpendPartyStrengthButton, EDMFDigimonAttributeStat::Strength);
        UpdateSpendButton(SpendPartyIntelligenceButton, EDMFDigimonAttributeStat::Intelligence);
        UpdateSpendButton(SpendPartyDefenseButton, EDMFDigimonAttributeStat::Defense);
        UpdateSpendButton(SpendPartySpeedButton, EDMFDigimonAttributeStat::Speed);
    }

    if (!bHasSelection)
    {
        if (SelectedPortraitImage)
        {
            SelectedPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        }
        if (SelectedNameText)
        {
            SelectedNameText->SetText(NSLOCTEXT("DMF", "NoSelectedDigimonName", "NO DIGIMON SELECTED"));
        }
        if (SelectedStageText)
        {
            SelectedStageText->SetText(FText::GetEmpty());
        }
        if (SelectedStateText)
        {
            SelectedStateText->SetText(NSLOCTEXT("DMF", "SelectDigimonState", "Choose a slot from the Party."));
            SelectedStateText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));
        }
        if (DigimonDetailsText)
        {
            DigimonDetailsText->SetText(NSLOCTEXT("DMF", "DigimonInventoryNoSelection", "LEVEL  --        EXP  -- / --\nHP     -- / --\nSP     -- / --\n\nSTR --     INT --\nDEF --     SPD --\nABI --     CAM --\nATTRIBUTE PTS  --"));
        }
        if (SelectedDescriptionText)
        {
            SelectedDescriptionText->SetText(NSLOCTEXT("DMF", "SelectedDigimonDescriptionEmpty", "Select a Digimon to view its species profile and current combat state."));
        }
        if (SelectedExperienceProgressBar)
        {
            SelectedExperienceProgressBar->SetPercent(0.0f);
        }
        return;
    }

    UDMFDigimonSpeciesData* Species = ResolveSpecies(Digimon.SpeciesId);
    const FText Name = Species && !Species->DisplayName.IsEmpty()
        ? Species->DisplayName
        : FText::FromName(Digimon.SpeciesId.PrimaryAssetName);
    const bool bIsActive = Digimon.InstanceId == BoundDigimonComponent->GetActivePartnerInstanceId();
    const bool bIsSummoned = bIsActive && BoundDigimonComponent->IsActivePartnerSummoned();
    const bool bDefeated = Digimon.CurrentHP <= 0;

    if (SelectedPortraitImage)
    {
        UTexture2D* PortraitTexture = Species ? Species->Portrait.LoadSynchronous() : nullptr;
        if (PortraitTexture)
        {
            SelectedPortraitImage->SetBrushFromTexture(PortraitTexture, true);
            SelectedPortraitImage->SetColorAndOpacity(bDefeated ? FLinearColor(0.55f, 0.55f, 0.55f, 1.0f) : FLinearColor::White);
            SelectedPortraitImage->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            SelectedPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        }
    }

    if (SelectedNameText)
    {
        SelectedNameText->SetText(Name);
    }
    if (SelectedStageText)
    {
        const FText StageText = Species
            ? UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage)
            : FText::GetEmpty();
        const FText AttributeText = Species
            ? DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), static_cast<int64>(Species->Attribute))
            : FText::GetEmpty();
        SelectedStageText->SetText(FText::Format(NSLOCTEXT("DMF", "DigimonStageAttribute", "{0}  •  {1}"), StageText, AttributeText));
    }

    if (SelectedStateText)
    {
        FText StateText;
        FLinearColor StateColor = DMFNativeUI::Muted();
        if (bDefeated)
        {
            StateText = NSLOCTEXT("DMF", "DigimonDefeatedStatePolished", "DEFEATED  •  HEAL BEFORE SUMMONING");
            StateColor = DMFNativeUI::Danger();
        }
        else if (bIsSummoned)
        {
            StateText = NSLOCTEXT("DMF", "DigimonSummonedStatePolished", "ACTIVE PARTNER  •  SUMMONED");
            StateColor = DMFNativeUI::Success();
        }
        else if (bIsActive)
        {
            StateText = NSLOCTEXT("DMF", "DigimonActiveStoredStatePolished", "ACTIVE PARTNER  •  RECALLED");
            StateColor = DMFNativeUI::Accent();
        }
        else
        {
            StateText = NSLOCTEXT("DMF", "DigimonStoredStatePolished", "STORED DIGIMON");
        }
        SelectedStateText->SetText(StateText);
        SelectedStateText->SetColorAndOpacity(FSlateColor(StateColor));
    }

    const int64 ExperienceRequired = BoundDigimonComponent->GetExperienceRequiredForLevel(Digimon.SpeciesId, Digimon.Stats.Level);
    const bool bMaxLevel = ExperienceRequired <= 0;
    if (DigimonDetailsText)
    {
        const FText ExperienceDisplay = bMaxLevel
            ? NSLOCTEXT("DMF", "DigimonInventoryMaxExperience", "MAX")
            : FText::Format(NSLOCTEXT("DMF", "DigimonInventoryExperienceFraction", "{0} / {1}"), FText::AsNumber(Digimon.Stats.Experience), FText::AsNumber(ExperienceRequired));
        DigimonDetailsText->SetText(FText::Format(
            NSLOCTEXT("DMF", "DigimonInventoryDetailsPolished", "LEVEL  {0}        EXP  {1}\nHP     {2} / {3}\nSP     {4} / {5}\n\nSTR    {6}        INT    {7}\nDEF    {8}        SPD    {9}\nABI    {10}        CAM    {11}\nATTRIBUTE PTS  {12}"),
            FText::AsNumber(Digimon.Stats.Level),
            ExperienceDisplay,
            FText::AsNumber(Digimon.CurrentHP),
            FText::AsNumber(Digimon.Stats.MaxHP),
            FText::AsNumber(Digimon.CurrentSP),
            FText::AsNumber(Digimon.Stats.MaxSP),
            FText::AsNumber(Digimon.Stats.Strength),
            FText::AsNumber(Digimon.Stats.Intelligence),
            FText::AsNumber(Digimon.Stats.Defense),
            FText::AsNumber(Digimon.Stats.Speed),
            FText::AsNumber(Digimon.Stats.ABI),
            FText::AsNumber(Digimon.Stats.CAM),
            FText::AsNumber(Digimon.UnspentAttributePoints)));
    }
    if (SelectedExperienceProgressBar)
    {
        SelectedExperienceProgressBar->SetPercent(bMaxLevel ? 1.0f : BoundDigimonComponent->GetExperienceProgressNormalized(Digimon.InstanceId));
    }

    if (SelectedDescriptionText)
    {
        SelectedDescriptionText->SetText(Species && !Species->Description.IsEmpty()
            ? Species->Description
            : NSLOCTEXT("DMF", "NoSpeciesDescription", "No species description has been assigned yet."));
    }

    BP_OnDigimonPreviewChanged(Digimon, Species);
}

void UDMFDigimonInventoryWidget::SetPartyAttributeSpendEnabled(const bool bEnabled)
{
    if (SpendPartyHPButton) SpendPartyHPButton->SetIsEnabled(bEnabled);
    if (SpendPartySPButton) SpendPartySPButton->SetIsEnabled(bEnabled);
    if (SpendPartyStrengthButton) SpendPartyStrengthButton->SetIsEnabled(bEnabled);
    if (SpendPartyIntelligenceButton) SpendPartyIntelligenceButton->SetIsEnabled(bEnabled);
    if (SpendPartyDefenseButton) SpendPartyDefenseButton->SetIsEnabled(bEnabled);
    if (SpendPartySpeedButton) SpendPartySpeedButton->SetIsEnabled(bEnabled);
}

void UDMFDigimonInventoryWidget::SetBankAttributeSpendEnabled(const bool bEnabled)
{
    if (SpendBankHPButton) SpendBankHPButton->SetIsEnabled(bEnabled);
    if (SpendBankSPButton) SpendBankSPButton->SetIsEnabled(bEnabled);
    if (SpendBankStrengthButton) SpendBankStrengthButton->SetIsEnabled(bEnabled);
    if (SpendBankIntelligenceButton) SpendBankIntelligenceButton->SetIsEnabled(bEnabled);
    if (SpendBankDefenseButton) SpendBankDefenseButton->SetIsEnabled(bEnabled);
    if (SpendBankSpeedButton) SpendBankSpeedButton->SetIsEnabled(bEnabled);
}

void UDMFDigimonInventoryWidget::RequestAttributePointSpend(const EDMFDigimonAttributeStat Stat, const bool bUseBankSelection)
{
    if (!BoundDigimonComponent)
    {
        return;
    }
    const FGuid InstanceId = bUseBankSelection ? SelectedBankInstanceId : SelectedInstanceId;
    if (!InstanceId.IsValid())
    {
        return;
    }
    BoundDigimonComponent->ServerSpendDigimonAttributePoint(InstanceId, Stat);
}

void UDMFDigimonInventoryWidget::SetActiveMenuTab(const EDMFDigimonMenuTab NewTab)
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    ActiveMenuTab = (NewTab == EDMFDigimonMenuTab::DigiDex && Settings && !Settings->bEnableDigiDex)
        ? EDMFDigimonMenuTab::Collection
        : NewTab;
    RefreshTabPresentation();
    if (ActiveMenuTab == EDMFDigimonMenuTab::Collection) RefreshInventory();
    else if (ActiveMenuTab == EDMFDigimonMenuTab::Bank) RefreshBankData();
    else if (ActiveMenuTab == EDMFDigimonMenuTab::ScanAndMaterialize) RefreshScanData();
    else if (ActiveMenuTab == EDMFDigimonMenuTab::DigiDex) RefreshDigiDexData();
    else if (ActiveMenuTab == EDMFDigimonMenuTab::Digivolution) RefreshDigivolutionData();
    else RefreshCareData();
}

void UDMFDigimonInventoryWidget::RefreshTabPresentation()
{
    if (InventoryContentRow) InventoryContentRow->SetVisibility(ActiveMenuTab == EDMFDigimonMenuTab::Collection ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    if (BankContentRow) BankContentRow->SetVisibility(ActiveMenuTab == EDMFDigimonMenuTab::Bank ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    if (ScanContentRow) ScanContentRow->SetVisibility(ActiveMenuTab == EDMFDigimonMenuTab::ScanAndMaterialize ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    if (CareContentRow) CareContentRow->SetVisibility(ActiveMenuTab == EDMFDigimonMenuTab::Care ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    if (DigivolutionContentRow) DigivolutionContentRow->SetVisibility(ActiveMenuTab == EDMFDigimonMenuTab::Digivolution ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    if (DigiDexContentRow) DigiDexContentRow->SetVisibility(ActiveMenuTab == EDMFDigimonMenuTab::DigiDex ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    DMFNativeUI::StyleButton(CollectionTabButton, false, false, ActiveMenuTab == EDMFDigimonMenuTab::Collection);
    DMFNativeUI::StyleButton(BankTabButton, false, false, ActiveMenuTab == EDMFDigimonMenuTab::Bank);
    DMFNativeUI::StyleButton(ScanMaterializeTabButton, false, false, ActiveMenuTab == EDMFDigimonMenuTab::ScanAndMaterialize);
    DMFNativeUI::StyleButton(DigivolutionTabButton, false, false, ActiveMenuTab == EDMFDigimonMenuTab::Digivolution);
    DMFNativeUI::StyleButton(DigiDexTabButton, false, false, ActiveMenuTab == EDMFDigimonMenuTab::DigiDex);
    if (DigiDexTabButton)
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        DigiDexTabButton->SetVisibility(!Settings || Settings->bEnableDigiDex ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
    DMFNativeUI::StyleButton(CareTabButton, false, false, ActiveMenuTab == EDMFDigimonMenuTab::Care);
    if (DigimonStatusText)
    {
        FText Status = NSLOCTEXT("DMF","PartyTabStatus","Manage the six-Digimon active Party, summon your partner or deposit Party members into Bank.");
        if (ActiveMenuTab == EDMFDigimonMenuTab::Bank) Status = NSLOCTEXT("DMF","BankTabStatus","Browse account-owned Box storage anywhere in the world, then move or atomically swap Digimon with Party.");
        else if (ActiveMenuTab == EDMFDigimonMenuTab::ScanAndMaterialize) Status = NSLOCTEXT("DMF","ScanTabStatus","Battle Wild Digimon to build Scan Data. Materialization fills Party first, then Bank automatically.");
        else if (ActiveMenuTab == EDMFDigimonMenuTab::DigiDex) Status = NSLOCTEXT("DMF","DigiDexTabStatus","Browse the complete implemented-species encyclopedia. DigiDex is read-only and never summons, moves or mutates Digimon.");
        else if (ActiveMenuTab == EDMFDigimonMenuTab::Digivolution) Status = NSLOCTEXT("DMF","DigivolutionTabStatus","Inspect branching evolution paths for any Party or Bank Digimon. Requirements and transformation commits are server-authoritative.");
        else if (ActiveMenuTab == EDMFDigimonMenuTab::Care) Status = NSLOCTEXT("DMF","CareTabStatus","Care for your summoned partner with unlimited DigiMeat and monitor its persistent virtual-pet needs.");
        DigimonStatusText->SetText(Status);
        DigimonStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));
    }
}

void UDMFDigimonInventoryWidget::RefreshScanData()
{
    BindDigimonComponent();
    if (!WidgetTree || !BoundDigimonComponent || !ScanSpeciesGrid) return;
    const TArray<FDMFScanDataEntry> Entries = BoundDigimonComponent->GetScanDataEntries();
    ScanSpeciesGrid->ClearChildren();
    if (ScanDatabaseCountText) ScanDatabaseCountText->SetText(FText::Format(NSLOCTEXT("DMF","ScanSpeciesCount","{0} SPECIES ANALYZED"),FText::AsNumber(Entries.Num())));

    bool bSelectionStillExists = false;
    int32 VisualIndex = 0;
    for (const FDMFScanDataEntry& ScanEntry : Entries)
    {
        if (!ScanEntry.SpeciesId.IsValid()) continue;
        UDMFDigimonSpeciesData* Species = ResolveSpecies(ScanEntry.SpeciesId);
        if (!Species || !Species->bScanDataEnabled) continue;
        const float Required = FMath::Max(1.0f, Species->MaterializationRequiredScanPercent);
        const float Cap = FMath::Max(1.0f, Species->ScanPercentCap);
        const bool bReady = Species->bMaterializationEnabled && ScanEntry.ScanPercent + KINDA_SMALL_NUMBER >= Required;

        UDMFScanSpeciesEntryButton* Card = WidgetTree->ConstructWidget<UDMFScanSpeciesEntryButton>(UDMFScanSpeciesEntryButton::StaticClass());
        Card->InitializeScanSpecies(ScanEntry.SpeciesId);
        Card->OnSpeciesPressed.AddDynamic(this,&UDMFDigimonInventoryWidget::HandleScanSpeciesPressed);
        DMFNativeUI::StyleButton(Card,false,false,ScanEntry.SpeciesId==SelectedScanSpeciesId);
        UOverlay* CardOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass()); Card->AddChild(CardOverlay);
        UBorder* CardBack = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass()); DMFNativeUI::StylePanel(CardBack,bReady?FLinearColor(0.025f,0.13f,0.10f,0.96f):DMFNativeUI::SlotEmpty(),FMargin(3)); CardOverlay->AddChildToOverlay(CardBack);
        UImage* Portrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
        if (UTexture2D* Texture = Species->Portrait.LoadSynchronous()) Portrait->SetBrushFromTexture(Texture,true); else Portrait->SetColorAndOpacity(FLinearColor::Transparent);
        if (UOverlaySlot* PSlot = CardOverlay->AddChildToOverlay(Portrait)) { PSlot->SetPadding(FMargin(6,6,6,36)); PSlot->SetHorizontalAlignment(HAlign_Fill); PSlot->SetVerticalAlignment(VAlign_Fill); }
        UBorder* Footer = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass()); DMFNativeUI::StylePanel(Footer,FLinearColor(0.005f,0.015f,0.035f,0.96f),FMargin(4,3));
        UVerticalBox* FooterColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass()); Footer->AddChild(FooterColumn);
        UTextBlock* Name = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); Name->SetText(Species->DisplayName.IsEmpty()?FText::FromName(ScanEntry.SpeciesId.PrimaryAssetName):Species->DisplayName); Name->SetJustification(ETextJustify::Center); DMFNativeUI::StyleText(Name,11,DMFNativeUI::Text(),true); FooterColumn->AddChildToVerticalBox(Name);
        UTextBlock* Progress = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); Progress->SetText(FText::Format(NSLOCTEXT("DMF","ScanCardProgress","SCAN {0}% / {1}%"),FText::AsNumber(FMath::RoundToInt(FMath::Min(ScanEntry.ScanPercent,Cap))),FText::AsNumber(FMath::RoundToInt(Required)))); Progress->SetJustification(ETextJustify::Center); DMFNativeUI::StyleText(Progress,9,bReady?DMFNativeUI::Gold():DMFNativeUI::Accent(),true); FooterColumn->AddChildToVerticalBox(Progress);
        if (UOverlaySlot* FooterSlot = CardOverlay->AddChildToOverlay(Footer)) { FooterSlot->SetHorizontalAlignment(HAlign_Fill); FooterSlot->SetVerticalAlignment(VAlign_Bottom); }
        if (bReady) { UBorder* Badge = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass()); DMFNativeUI::StylePanel(Badge,DMFNativeUI::Gold(),FMargin(5,2)); UTextBlock* T=WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass()); T->SetText(NSLOCTEXT("DMF","ScanReadyBadge","READY")); DMFNativeUI::StyleText(T,9,FLinearColor(0.04f,0.04f,0.04f,1),true); Badge->AddChild(T); if(UOverlaySlot* B=CardOverlay->AddChildToOverlay(Badge)){B->SetPadding(FMargin(5));B->SetHorizontalAlignment(HAlign_Right);B->SetVerticalAlignment(VAlign_Top);} }
        USizeBox* CardSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass()); CardSize->SetWidthOverride(145); CardSize->SetHeightOverride(150); CardSize->AddChild(Card);
        const int32 Row=VisualIndex/4, Column=VisualIndex%4; ScanSpeciesGrid->AddChildToUniformGrid(CardSize,Row,Column);
        bSelectionStillExists |= ScanEntry.SpeciesId == SelectedScanSpeciesId;
        ++VisualIndex;
    }
    if (!bSelectionStillExists) SelectedScanSpeciesId = FPrimaryAssetId();
    RefreshSelectedScanDetails();
}

void UDMFDigimonInventoryWidget::RefreshSelectedScanDetails()
{
    if (!BoundDigimonComponent) return;
    UDMFDigimonSpeciesData* Species = ResolveSpecies(SelectedScanSpeciesId);
    const bool bHasSelection = Species != nullptr;
    if (!bHasSelection)
    {
        if (ScanSelectedPortraitImage) ScanSelectedPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        if (ScanSelectedNameText) ScanSelectedNameText->SetText(NSLOCTEXT("DMF","NoScanSpeciesSelected","NO SPECIES SELECTED"));
        if (ScanSelectedMetaText) ScanSelectedMetaText->SetText(FText::GetEmpty());
        if (ScanSelectedProgressText) ScanSelectedProgressText->SetText(NSLOCTEXT("DMF","SelectScanSpecies","Select an analyzed species from the database."));
        if (ScanSelectedProgressBar) ScanSelectedProgressBar->SetPercent(0.0f);
        if (ScanSelectedDetailsText) ScanSelectedDetailsText->SetText(NSLOCTEXT("DMF","ScanDetailsEmpty","SCAN DATA     --\nREQUIRED      --\nPER VICTORY   --\nOWNED         --"));
        if (ScanSelectedDescriptionText) ScanSelectedDescriptionText->SetText(NSLOCTEXT("DMF","ScanDescriptionEmpty","Defeat eligible Wild Digimon to begin analyzing their species."));
        if (MaterializeDigimonButton) MaterializeDigimonButton->SetIsEnabled(false);
        return;
    }
    const float Scan = BoundDigimonComponent->GetScanPercent(SelectedScanSpeciesId);
    const float Required = FMath::Max(1.0f,Species->MaterializationRequiredScanPercent);
    const float Cap = FMath::Max(1.0f,Species->ScanPercentCap);
    const bool bReady = BoundDigimonComponent->IsSpeciesReadyToMaterialize(SelectedScanSpeciesId);
    const bool bPartyHasSpace = BoundDigimonComponent->GetPartyDigimon().Num() < BoundDigimonComponent->GetPartyCapacity();
    const bool bBankHasSpace = BoundDigimonComponent->GetBankDigimon().Num() < BoundDigimonComponent->GetBankCapacity();
    const bool bHasSpace = bPartyHasSpace || bBankHasSpace;
    if (MaterializeDigimonButton) MaterializeDigimonButton->SetIsEnabled(bReady && bHasSpace);
    if (ScanSelectedPortraitImage) { if(UTexture2D* Texture=Species->Portrait.LoadSynchronous()){ScanSelectedPortraitImage->SetBrushFromTexture(Texture,true);ScanSelectedPortraitImage->SetVisibility(ESlateVisibility::Visible);}else ScanSelectedPortraitImage->SetVisibility(ESlateVisibility::Hidden); }
    if (ScanSelectedNameText) ScanSelectedNameText->SetText(Species->DisplayName.IsEmpty()?FText::FromName(SelectedScanSpeciesId.PrimaryAssetName):Species->DisplayName);
    if (ScanSelectedMetaText) ScanSelectedMetaText->SetText(FText::Format(NSLOCTEXT("DMF","ScanSpeciesMeta","{0}  •  {1}  •  START Lv.{2}"),UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage),DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(),static_cast<int64>(Species->Attribute)),FText::AsNumber(Species->StartingLevel)));
    if (ScanSelectedProgressText)
    {
        ScanSelectedProgressText->SetText(bReady
            ? FText::Format(NSLOCTEXT("DMF","ScanReadyProgress","{0}%  •  MATERIALIZATION READY"), FText::AsNumber(FMath::RoundToInt(Scan)))
            : FText::Format(NSLOCTEXT("DMF","ScanNormalProgress","{0}% / {1}% SCAN DATA"), FText::AsNumber(FMath::RoundToInt(Scan)), FText::AsNumber(FMath::RoundToInt(Required))));
        ScanSelectedProgressText->SetColorAndOpacity(FSlateColor(bReady?DMFNativeUI::Gold():DMFNativeUI::Accent()));
    }
    if (ScanSelectedProgressBar) { ScanSelectedProgressBar->SetPercent(FMath::Clamp(Scan/Required,0.0f,1.0f)); ScanSelectedProgressBar->SetFillColorAndOpacity(bReady?DMFNativeUI::Gold():DMFNativeUI::Accent()); }
    if (ScanSelectedDetailsText) ScanSelectedDetailsText->SetText(FText::Format(NSLOCTEXT("DMF","ScanDetailsFormat","SCAN DATA     {0}% / {1}% CAP\nREQUIRED      {2}%\nPER VICTORY   +{3}%\nOWNED         {4}\nPARTY         {5} / {6}\nBANK          {7} / {8}"),FText::AsNumber(FMath::RoundToInt(Scan)),FText::AsNumber(FMath::RoundToInt(Cap)),FText::AsNumber(FMath::RoundToInt(Required)),FText::AsNumber(FMath::RoundToInt(Species->BattleScanPercentReward)),FText::AsNumber(BoundDigimonComponent->GetOwnedSpeciesCount(SelectedScanSpeciesId)),FText::AsNumber(BoundDigimonComponent->GetPartyDigimon().Num()),FText::AsNumber(BoundDigimonComponent->GetPartyCapacity()),FText::AsNumber(BoundDigimonComponent->GetBankDigimon().Num()),FText::AsNumber(BoundDigimonComponent->GetBankCapacity())));
    if (ScanSelectedDescriptionText) ScanSelectedDescriptionText->SetText(Species->Description.IsEmpty()?NSLOCTEXT("DMF","NoScanSpeciesDescription","No species description has been assigned yet."):Species->Description);
}

void UDMFDigimonInventoryWidget::RefreshCareData()
{
    BindDigimonComponent();
    if (!BoundDigimonComponent) return;

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    FDMFDigimonCareState Care;
    FDMFDigimonInstance Instance;
    const FGuid ActiveId = BoundDigimonComponent->GetActivePartnerInstanceId();
    const bool bHasCare = ActiveId.IsValid() && BoundDigimonComponent->GetActivePartnerCareState(Care) && BoundDigimonComponent->GetDigimonByInstanceId(ActiveId, Instance);
    UDMFDigimonSpeciesData* Species = bHasCare ? ResolveSpecies(Instance.SpeciesId) : nullptr;
    const bool bSummoned = BoundDigimonComponent->IsActivePartnerSummoned();
    const bool bCareEnabled = Settings && Settings->bEnableCareSystem && Species && Species->bCareEnabled;

    if (!bHasCare || !Species)
    {
        if (CarePortraitImage) CarePortraitImage->SetVisibility(ESlateVisibility::Hidden);
        if (CareNameText) CareNameText->SetText(NSLOCTEXT("DMF","CareNoPartner","NO ACTIVE DIGIMON"));
        if (CareMetaText) CareMetaText->SetText(NSLOCTEXT("DMF","CareNoPartnerMeta","Select and summon a partner from PARTY."));
        if (CareHungerText) CareHungerText->SetText(NSLOCTEXT("DMF","CareNoHunger","-- / 100%"));
        if (CareHungerProgressBar) CareHungerProgressBar->SetPercent(0.0f);
        if (CareHappinessProgressBar) CareHappinessProgressBar->SetPercent(0.0f);
        if (CareDisciplineProgressBar) CareDisciplineProgressBar->SetPercent(0.0f);
        if (CareStatisticsText) CareStatisticsText->SetText(NSLOCTEXT("DMF","CareNoStats","HUNGER       --\nHAPPINESS    --\nDISCIPLINE   --\nCARE MISTAKES --"));
        if (CareWasteStatusText) CareWasteStatusText->SetText(NSLOCTEXT("DMF","CareNoWaste","DIGESTION\nNo active partner care state is available."));
        if (CareFeedingRulesText) CareFeedingRulesText->SetText(NSLOCTEXT("DMF","CareNoRules","Summon a Digimon to inspect its species feeding configuration."));
        if (FeedDigiMeatButton) FeedDigiMeatButton->SetIsEnabled(false);
        return;
    }

    if (CarePortraitImage)
    {
        if (UTexture2D* Texture = Species->Portrait.LoadSynchronous()) { CarePortraitImage->SetBrushFromTexture(Texture,true); CarePortraitImage->SetVisibility(ESlateVisibility::Visible); }
        else CarePortraitImage->SetVisibility(ESlateVisibility::Hidden);
    }
    const FText DisplayName = !Instance.Nickname.IsEmpty() ? FText::FromString(Instance.Nickname) : (Species->DisplayName.IsEmpty() ? FText::FromName(Instance.SpeciesId.PrimaryAssetName) : Species->DisplayName);
    if (CareNameText) CareNameText->SetText(DisplayName);
    if (CareMetaText) CareMetaText->SetText(FText::Format(NSLOCTEXT("DMF","CareMetaFormat","{0}  •  {1}  •  Lv.{2}  •  {3}"), UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage), DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(),static_cast<int64>(Species->Attribute)), FText::AsNumber(Instance.Stats.Level), bSummoned ? NSLOCTEXT("DMF","CareSummoned","SUMMONED") : NSLOCTEXT("DMF","CareRecalled","RECALLED")));

    const float Hunger = FMath::Clamp(Care.Hunger,0.0f,100.0f);
    if (CareHungerText) CareHungerText->SetText(Hunger >= 99.99f ? NSLOCTEXT("DMF","CareHungerFull","100%  •  FULL") : FText::Format(NSLOCTEXT("DMF","CareHungerFormat","{0}% / 100%"),FText::AsNumber(FMath::RoundToInt(Hunger))));
    if (CareHungerProgressBar) { CareHungerProgressBar->SetPercent(Hunger/100.0f); CareHungerProgressBar->SetFillColorAndOpacity(Hunger < 25.0f ? DMFNativeUI::Danger() : (Hunger >= 99.99f ? DMFNativeUI::Success() : DMFNativeUI::Accent())); }
    if (CareHappinessProgressBar) CareHappinessProgressBar->SetPercent(FMath::Clamp(Care.Happiness/100.0f,0.0f,1.0f));
    if (CareDisciplineProgressBar) CareDisciplineProgressBar->SetPercent(FMath::Clamp(Care.Discipline/100.0f,0.0f,1.0f));
    if (CareStatisticsText) CareStatisticsText->SetText(FText::Format(NSLOCTEXT("DMF","CareStatsFormat","HUNGER         {0}%\nHAPPINESS      {1}%\nDISCIPLINE     {2}%\nCARE MISTAKES  {3}"),FText::AsNumber(FMath::RoundToInt(Hunger)),FText::AsNumber(FMath::RoundToInt(Care.Happiness)),FText::AsNumber(FMath::RoundToInt(Care.Discipline)),FText::AsNumber(Care.CareMistakes)));

    if (CareFeedingRulesText)
    {
        CareFeedingRulesText->SetText(FText::Format(NSLOCTEXT("DMF","CareRulesFormat","UNLIMITED SUPPLY\n+{0}% Hunger per serving\nEating Montage ×{1}\nHunger decay: {2}% / real-time hour\nHand socket: {3}"), FText::AsNumber(FMath::RoundToInt(Species->DigiMeatHungerPercentPerServing)), FText::AsNumber(FMath::Clamp(Species->FeedingMontagePlaysPerServing,1,8)), FText::AsNumber(Species->HungerDecayPercentPerHour), FText::FromName(Species->DigiMeatHandSocketName)));
    }
    if (CareWasteStatusText)
    {
        const float Seconds = BoundDigimonComponent->GetSecondsUntilActivePartnerWaste();
        FText WasteState = !Species->bWasteEnabled
            ? NSLOCTEXT("DMF","CareWasteDisabled","DIGESTION\nWaste is disabled for this species.")
            : (Seconds < 0.0f ? NSLOCTEXT("DMF","CareWasteNone","DIGESTION\nNo poop is currently scheduled.")
                : (Seconds <= 0.01f ? NSLOCTEXT("DMF","CareWasteDue","DIGESTION\nPoop is due when the partner is available in-world.")
                    : FText::Format(NSLOCTEXT("DMF","CareWasteCountdown","DIGESTION\nNext poop in approximately {0} sec.\nCleanup lifetime: {1} sec."),FText::AsNumber(FMath::CeilToInt(Seconds)),FText::AsNumber(FMath::RoundToInt(Species->PooLifetimeSeconds)))));
        CareWasteStatusText->SetText(WasteState);
    }

    const bool bReadyToFeed = bCareEnabled && bSummoned && Instance.CurrentHP > 0 && Hunger < 99.99f && !BoundDigimonComponent->IsCareSequenceActive();
    if (FeedDigiMeatButton) FeedDigiMeatButton->SetIsEnabled(bReadyToFeed);
}

TArray<UDMFDigimonSpeciesData*> UDMFDigimonInventoryWidget::GatherRegisteredDigiDexSpecies() const
{
    TArray<UDMFDigimonSpeciesData*> Result;
    TSet<FPrimaryAssetId> AddedIds;

    UAssetManager& AssetManager = UAssetManager::Get();
    TArray<FPrimaryAssetId> SpeciesIds;
    AssetManager.GetPrimaryAssetIdList(FPrimaryAssetType(TEXT("DMFDigimonSpecies")), SpeciesIds, EAssetManagerFilter::Default);
    for (const FPrimaryAssetId& SpeciesId : SpeciesIds)
    {
        if (!SpeciesId.IsValid() || AddedIds.Contains(SpeciesId))
        {
            continue;
        }
        if (UDMFDigimonSpeciesData* Species = ResolveSpecies(SpeciesId))
        {
            AddedIds.Add(SpeciesId);
            Result.Add(Species);
        }
    }

    // Compatibility fallback for projects that have not yet copied the supplied Asset Manager scan
    // config: include the starter roster and walk its authored Digivolution graph. Packaged projects
    // should still register /Game/DigimonData recursively so every implemented species appears.
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UDMFStarterRosterData* Roster = Settings ? Settings->StarterRoster.LoadSynchronous() : nullptr;
    TArray<UDMFDigimonSpeciesData*> Pending;
    if (Roster)
    {
        for (const FDMFStarterRosterEntry& Entry : Roster->Starters)
        {
            if (UDMFDigimonSpeciesData* StarterSpecies = Entry.Species.LoadSynchronous())
            {
                Pending.Add(StarterSpecies);
            }
        }
    }
    while (!Pending.IsEmpty())
    {
        UDMFDigimonSpeciesData* Species = Pending.Pop(EAllowShrinking::No);
        if (!Species)
        {
            continue;
        }
        const FPrimaryAssetId SpeciesId = Species->GetPrimaryAssetId();
        if (!AddedIds.Contains(SpeciesId))
        {
            AddedIds.Add(SpeciesId);
            Result.Add(Species);
        }
        for (const FDMFDigivolutionRequirement& Path : Species->Digivolutions)
        {
            if (UDMFDigimonSpeciesData* Target = Path.TargetSpecies.LoadSynchronous())
            {
                const FPrimaryAssetId TargetId = Target->GetPrimaryAssetId();
                if (!AddedIds.Contains(TargetId))
                {
                    Pending.Add(Target);
                }
            }
        }
    }

    Result.RemoveAll([](const UDMFDigimonSpeciesData* Species)
    {
        return !Species || !Species->bShowInDigiDex;
    });
    Result.Sort([](const UDMFDigimonSpeciesData& A, const UDMFDigimonSpeciesData& B)
    {
        const bool bANumbered = A.DigiDexNumber > 0;
        const bool bBNumbered = B.DigiDexNumber > 0;
        if (bANumbered != bBNumbered) return bANumbered;
        if (bANumbered && A.DigiDexNumber != B.DigiDexNumber) return A.DigiDexNumber < B.DigiDexNumber;
        if (A.Stage != B.Stage) return static_cast<uint8>(A.Stage) < static_cast<uint8>(B.Stage);
        const FString AName = A.DisplayName.IsEmpty() ? A.GetPrimaryAssetId().PrimaryAssetName.ToString() : A.DisplayName.ToString();
        const FString BName = B.DisplayName.IsEmpty() ? B.GetPrimaryAssetId().PrimaryAssetName.ToString() : B.DisplayName.ToString();
        return AName.Compare(BName, ESearchCase::IgnoreCase) < 0;
    });
    return Result;
}

TArray<FPrimaryAssetId> UDMFDigimonInventoryWidget::GetDigiDexSpeciesIds() const
{
    TArray<FPrimaryAssetId> Result;
    for (UDMFDigimonSpeciesData* Species : GatherRegisteredDigiDexSpecies())
    {
        if (Species) Result.Add(Species->GetPrimaryAssetId());
    }
    return Result;
}

void UDMFDigimonInventoryWidget::RefreshDigiDexData()
{
    BindDigimonComponent();
    if (!WidgetTree || !DigiDexSpeciesGrid)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && !Settings->bEnableDigiDex)
    {
        DigiDexSpeciesGrid->ClearChildren();
        return;
    }

    const TArray<UDMFDigimonSpeciesData*> AllSpecies = GatherRegisteredDigiDexSpecies();
    TArray<UDMFDigimonSpeciesData*> VisibleSpecies;
    int32 OwnedSpeciesCount = 0;
    int32 ScannedSpeciesCount = 0;

    for (UDMFDigimonSpeciesData* Species : AllSpecies)
    {
        if (!Species)
        {
            continue;
        }
        const FPrimaryAssetId SpeciesId = Species->GetPrimaryAssetId();
        const int32 OwnedCount = BoundDigimonComponent ? BoundDigimonComponent->GetOwnedSpeciesCount(SpeciesId) : 0;
        const float ScanPercent = BoundDigimonComponent ? BoundDigimonComponent->GetScanPercent(SpeciesId) : 0.0f;
        OwnedSpeciesCount += OwnedCount > 0 ? 1 : 0;
        ScannedSpeciesCount += ScanPercent > KINDA_SMALL_NUMBER ? 1 : 0;

        if (DigiDexStageFilterIndex != INDEX_NONE && static_cast<int32>(Species->Stage) != DigiDexStageFilterIndex)
        {
            continue;
        }
        if (DigiDexAttributeFilterIndex != INDEX_NONE && static_cast<int32>(Species->Attribute) != DigiDexAttributeFilterIndex)
        {
            continue;
        }
        if (!DigiDexSearchQuery.IsEmpty())
        {
            const FString StageName = UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage).ToString();
            const FString AttributeName = DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), static_cast<int64>(Species->Attribute)).ToString();
            const FString ElementName = DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonElement>(), static_cast<int64>(Species->Element)).ToString();
            const FString DisplayName = Species->DisplayName.IsEmpty() ? SpeciesId.PrimaryAssetName.ToString() : Species->DisplayName.ToString();
            const bool bMatches = DisplayName.Contains(DigiDexSearchQuery, ESearchCase::IgnoreCase)
                || Species->SpeciesKey.ToString().Contains(DigiDexSearchQuery, ESearchCase::IgnoreCase)
                || (Species->DigiDexNumber > 0 && FString::FromInt(Species->DigiDexNumber).Contains(DigiDexSearchQuery, ESearchCase::IgnoreCase))
                || StageName.Contains(DigiDexSearchQuery, ESearchCase::IgnoreCase)
                || AttributeName.Contains(DigiDexSearchQuery, ESearchCase::IgnoreCase)
                || ElementName.Contains(DigiDexSearchQuery, ESearchCase::IgnoreCase);
            if (!bMatches)
            {
                continue;
            }
        }
        VisibleSpecies.Add(Species);
    }

    if (DigiDexCountText)
    {
        DigiDexCountText->SetText(FText::Format(
            NSLOCTEXT("DMF", "DigiDexCountFormat", "{0} / {1} SHOWN  •  {2} OWNED  •  {3} SCANNED"),
            FText::AsNumber(VisibleSpecies.Num()), FText::AsNumber(AllSpecies.Num()),
            FText::AsNumber(OwnedSpeciesCount), FText::AsNumber(ScannedSpeciesCount)));
    }
    if (DigiDexStageFilterText)
    {
        DigiDexStageFilterText->SetText(DigiDexStageFilterIndex == INDEX_NONE
            ? NSLOCTEXT("DMF", "DigiDexAllStages", "ALL STAGES")
            : UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(static_cast<EDMFDigimonStage>(DigiDexStageFilterIndex)));
    }
    if (DigiDexAttributeFilterText)
    {
        DigiDexAttributeFilterText->SetText(DigiDexAttributeFilterIndex == INDEX_NONE
            ? NSLOCTEXT("DMF", "DigiDexAllAttributes", "ALL ATTRIBUTES")
            : DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), DigiDexAttributeFilterIndex));
    }

    const bool bSelectedVisible = SelectedDigiDexSpeciesId.IsValid() && VisibleSpecies.ContainsByPredicate([&](const UDMFDigimonSpeciesData* Species)
    {
        return Species && Species->GetPrimaryAssetId() == SelectedDigiDexSpeciesId;
    });
    if (!bSelectedVisible)
    {
        SelectedDigiDexSpeciesId = VisibleSpecies.Num() > 0 ? VisibleSpecies[0]->GetPrimaryAssetId() : FPrimaryAssetId();
    }

    DigiDexSpeciesGrid->ClearChildren();
    for (int32 Index = 0; Index < VisibleSpecies.Num(); ++Index)
    {
        UDMFDigimonSpeciesData* Species = VisibleSpecies[Index];
        if (!Species)
        {
            continue;
        }
        const FPrimaryAssetId SpeciesId = Species->GetPrimaryAssetId();
        const int32 RegistryIndex = Species->DigiDexNumber > 0 ? Species->DigiDexNumber : (AllSpecies.IndexOfByKey(Species) + 1);
        const int32 OwnedCount = BoundDigimonComponent ? BoundDigimonComponent->GetOwnedSpeciesCount(SpeciesId) : 0;
        const float ScanPercent = BoundDigimonComponent ? BoundDigimonComponent->GetScanPercent(SpeciesId) : 0.0f;
        const bool bOwned = OwnedCount > 0;
        const bool bScanned = ScanPercent > KINDA_SMALL_NUMBER;

        USizeBox* CardSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        CardSize->SetWidthOverride(DMFInventoryUI::DigiDexCardWidth);
        CardSize->SetHeightOverride(DMFInventoryUI::DigiDexCardHeight);
        UDMFScanSpeciesEntryButton* Card = WidgetTree->ConstructWidget<UDMFScanSpeciesEntryButton>(UDMFScanSpeciesEntryButton::StaticClass());
        Card->InitializeScanSpecies(SpeciesId);
        Card->OnSpeciesPressed.AddDynamic(this, &UDMFDigimonInventoryWidget::HandleDigiDexSpeciesPressed);
        DMFNativeUI::StyleCompactButton(Card, false, false, SpeciesId == SelectedDigiDexSpeciesId);
        CardSize->AddChild(Card);

        UBorder* CardBack = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(CardBack, bOwned ? FLinearColor(0.018f,0.105f,0.085f,0.98f) : DMFNativeUI::SlotEmpty(), FMargin(5.0f));
        Card->AddChild(CardBack);
        UVerticalBox* CardColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
        CardBack->AddChild(CardColumn);

        USizeBox* PortraitViewport = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        PortraitViewport->SetWidthOverride(DMFInventoryUI::DigiDexPortraitSize);
        PortraitViewport->SetHeightOverride(DMFInventoryUI::DigiDexPortraitSize);
        if (UVerticalBoxSlot* PortraitViewportSlot = CardColumn->AddChildToVerticalBox(PortraitViewport))
        {
            PortraitViewportSlot->SetHorizontalAlignment(HAlign_Center);
        }
        UOverlay* PortraitOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass());
        PortraitViewport->AddChild(PortraitOverlay);
        UScaleBox* PortraitScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass());
        PortraitScale->SetStretch(EStretch::ScaleToFit);
        PortraitScale->SetStretchDirection(EStretchDirection::DownOnly);
        if (UOverlaySlot* PortraitScaleSlot = PortraitOverlay->AddChildToOverlay(PortraitScale))
        {
            PortraitScaleSlot->SetHorizontalAlignment(HAlign_Center);
            PortraitScaleSlot->SetVerticalAlignment(VAlign_Center);
        }
        UImage* Portrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
        if (UTexture2D* Texture = Species->Portrait.LoadSynchronous())
        {
            Portrait->SetBrushFromTexture(Texture, true);
        }
        else
        {
            Portrait->SetColorAndOpacity(FLinearColor::Transparent);
        }
        PortraitScale->AddChild(Portrait);

        UBorder* NumberBadge = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(NumberBadge, FLinearColor(0.01f,0.03f,0.07f,0.94f), FMargin(4,2));
        UTextBlock* NumberText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        NumberText->SetText(FText::Format(NSLOCTEXT("DMF", "DigiDexNumberBadge", "#{0}"), FText::AsNumber(RegistryIndex)));
        DMFNativeUI::StyleText(NumberText, 9, DMFNativeUI::Muted(), true);
        NumberBadge->AddChild(NumberText);
        if (UOverlaySlot* NumberSlot = PortraitOverlay->AddChildToOverlay(NumberBadge))
        {
            NumberSlot->SetPadding(FMargin(2));
            NumberSlot->SetHorizontalAlignment(HAlign_Left);
            NumberSlot->SetVerticalAlignment(VAlign_Top);
        }

        UBorder* StateBadge = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        const FLinearColor StateColor = bOwned ? DMFNativeUI::Success() : (bScanned ? DMFNativeUI::AccentSoft() : FLinearColor(0.17f,0.20f,0.24f,0.96f));
        DMFNativeUI::StylePanel(StateBadge, StateColor, FMargin(4,2));
        UTextBlock* StateText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        StateText->SetText(bOwned ? NSLOCTEXT("DMF", "DigiDexOwnedBadge", "OWNED") : (bScanned ? NSLOCTEXT("DMF", "DigiDexScannedBadge", "SCANNED") : NSLOCTEXT("DMF", "DigiDexUnscannedBadge", "UNSCANNED")));
        DMFNativeUI::StyleText(StateText, 8, FLinearColor::White, true);
        StateBadge->AddChild(StateText);
        if (UOverlaySlot* StateSlot = PortraitOverlay->AddChildToOverlay(StateBadge))
        {
            StateSlot->SetPadding(FMargin(2));
            StateSlot->SetHorizontalAlignment(HAlign_Right);
            StateSlot->SetVerticalAlignment(VAlign_Top);
        }

        UBorder* Footer = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(Footer, FLinearColor(0.004f,0.012f,0.03f,0.96f), FMargin(4,3));
        if (UVerticalBoxSlot* FooterSlot = CardColumn->AddChildToVerticalBox(Footer))
        {
            FooterSlot->SetSize(DMFNativeUI::FillSize());
        }
        UVerticalBox* FooterColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
        Footer->AddChild(FooterColumn);
        UTextBlock* NameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        NameText->SetText(Species->DisplayName.IsEmpty() ? FText::FromName(SpeciesId.PrimaryAssetName) : Species->DisplayName);
        NameText->SetJustification(ETextJustify::Center);
        NameText->SetAutoWrapText(true);
        DMFNativeUI::StyleText(NameText, 11, DMFNativeUI::Text(), true);
        FooterColumn->AddChildToVerticalBox(NameText);
        UTextBlock* MetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        MetaText->SetText(FText::Format(NSLOCTEXT("DMF", "DigiDexCardMeta", "{0}  •  {1}"),
            UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage),
            DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), static_cast<int64>(Species->Attribute))));
        MetaText->SetJustification(ETextJustify::Center);
        DMFNativeUI::StyleText(MetaText, 9, DMFNativeUI::Gold(), true);
        FooterColumn->AddChildToVerticalBox(MetaText);

        const int32 Row = Index / DMFInventoryUI::DigiDexColumns;
        const int32 Column = Index % DMFInventoryUI::DigiDexColumns;
        if (UUniformGridSlot* GridSlot = DigiDexSpeciesGrid->AddChildToUniformGrid(CardSize, Row, Column))
        {
            GridSlot->SetHorizontalAlignment(HAlign_Center);
            GridSlot->SetVerticalAlignment(VAlign_Top);
        }
    }

    RefreshSelectedDigiDexDetails();
}

void UDMFDigimonInventoryWidget::RefreshSelectedDigiDexDetails()
{
    const TArray<UDMFDigimonSpeciesData*> AllSpecies = GatherRegisteredDigiDexSpecies();
    UDMFDigimonSpeciesData* Species = ResolveSpecies(SelectedDigiDexSpeciesId);
    if (!Species)
    {
        if (DigiDexSelectedPortraitImage) DigiDexSelectedPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        if (DigiDexSelectedNameText) DigiDexSelectedNameText->SetText(NSLOCTEXT("DMF", "DigiDexNoSelection", "NO SPECIES SELECTED"));
        if (DigiDexSelectedMetaText) DigiDexSelectedMetaText->SetText(NSLOCTEXT("DMF", "DigiDexNoSelectionMeta", "Choose an entry from the species database."));
        if (DigiDexSelectedStatusText) DigiDexSelectedStatusText->SetText(FText::GetEmpty());
        if (DigiDexSelectedStatsText) DigiDexSelectedStatsText->SetText(FText::GetEmpty());
        if (DigiDexSelectedEvolutionText) DigiDexSelectedEvolutionText->SetText(FText::GetEmpty());
        if (DigiDexSelectedDescriptionText) DigiDexSelectedDescriptionText->SetText(FText::GetEmpty());
        BP_OnDigiDexSelectionChanged(FPrimaryAssetId(), nullptr);
        return;
    }

    const FPrimaryAssetId SpeciesId = Species->GetPrimaryAssetId();
    const int32 RegistryIndex = Species->DigiDexNumber > 0 ? Species->DigiDexNumber : (AllSpecies.IndexOfByKey(Species) + 1);
    const int32 OwnedCount = BoundDigimonComponent ? BoundDigimonComponent->GetOwnedSpeciesCount(SpeciesId) : 0;
    const float ScanPercent = BoundDigimonComponent ? BoundDigimonComponent->GetScanPercent(SpeciesId) : 0.0f;

    if (DigiDexSelectedPortraitImage)
    {
        if (UTexture2D* Texture = Species->Portrait.LoadSynchronous())
        {
            DigiDexSelectedPortraitImage->SetBrushFromTexture(Texture, true);
            DigiDexSelectedPortraitImage->SetColorAndOpacity(FLinearColor::White);
            DigiDexSelectedPortraitImage->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            DigiDexSelectedPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        }
    }
    const FText SpeciesName = Species->DisplayName.IsEmpty() ? FText::FromName(SpeciesId.PrimaryAssetName) : Species->DisplayName;
    if (DigiDexSelectedNameText) DigiDexSelectedNameText->SetText(SpeciesName);
    if (DigiDexSelectedMetaText)
    {
        DigiDexSelectedMetaText->SetText(FText::Format(NSLOCTEXT("DMF", "DigiDexSelectedMeta", "#{0}  •  {1}  •  {2}  •  {3}"),
            FText::AsNumber(FMath::Max(1, RegistryIndex)),
            UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage),
            DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), static_cast<int64>(Species->Attribute)),
            DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonElement>(), static_cast<int64>(Species->Element))));
    }
    if (DigiDexSelectedStatusText)
    {
        const FText Status = OwnedCount > 0
            ? FText::Format(NSLOCTEXT("DMF", "DigiDexOwnedStatus", "OWNED ×{0}  •  SCAN {1}%"), FText::AsNumber(OwnedCount), FText::AsNumber(FMath::RoundToInt(ScanPercent)))
            : (ScanPercent > KINDA_SMALL_NUMBER
                ? FText::Format(NSLOCTEXT("DMF", "DigiDexScannedStatus", "SCANNED  •  {0}% DATA"), FText::AsNumber(FMath::RoundToInt(ScanPercent)))
                : NSLOCTEXT("DMF", "DigiDexUnscannedStatus", "UNSCANNED  •  NOT YET OWNED"));
        DigiDexSelectedStatusText->SetText(Status);
        DigiDexSelectedStatusText->SetColorAndOpacity(FSlateColor(OwnedCount > 0 ? DMFNativeUI::Success() : (ScanPercent > KINDA_SMALL_NUMBER ? DMFNativeUI::Accent() : DMFNativeUI::Muted())));
    }

    TArray<FString> AbilityNames;
    for (const FName AbilityId : Species->StartingAbilityIds)
    {
        if (!AbilityId.IsNone()) AbilityNames.AddUnique(AbilityId.ToString());
    }
    for (const TSoftObjectPtr<UDMFDigimonAbilityData>& Ability : Species->StartingAbilities)
    {
        const FString AssetName = Ability.ToSoftObjectPath().GetAssetName();
        if (!AssetName.IsEmpty()) AbilityNames.AddUnique(AssetName);
    }
    if (!Species->BasicAutoAttack.IsNull())
    {
        const FString AssetName = Species->BasicAutoAttack.ToSoftObjectPath().GetAssetName();
        if (!AssetName.IsEmpty()) AbilityNames.AddUnique(FString::Printf(TEXT("%s (Basic)"), *AssetName));
    }
    const FString AbilityList = AbilityNames.IsEmpty() ? TEXT("None configured") : FString::Join(AbilityNames, TEXT(", "));

    if (DigiDexSelectedStatsText)
    {
        DigiDexSelectedStatsText->SetText(FText::Format(NSLOCTEXT("DMF", "DigiDexStatsFormat",
            "BASE PROFILE\nSTART LEVEL  {0}\nHP  {1}     SP  {2}\nSTR {3}     INT {4}\nDEF {5}     SPD {6}\nATTR PTS / LV  {7}\n\nBATTLE REWARD\nEXP  {8}     MONEY  {9}\n\nSCAN / MATERIALIZE\nVICTORY  +{10}%\nREQUIRED  {11}%\n\nSTARTING MOVES\n{12}"),
            FText::AsNumber(Species->StartingLevel), FText::AsNumber(Species->BaseStats.MaxHP), FText::AsNumber(Species->BaseStats.MaxSP),
            FText::AsNumber(Species->BaseStats.Strength), FText::AsNumber(Species->BaseStats.Intelligence),
            FText::AsNumber(Species->BaseStats.Defense), FText::AsNumber(Species->BaseStats.Speed),
            FText::AsNumber(Species->AttributePointsPerLevel), FText::AsNumber(Species->BattleExperienceReward), FText::AsNumber(Species->BattleMoneyReward),
            FText::AsNumber(FMath::RoundToInt(Species->BattleScanPercentReward)), FText::AsNumber(FMath::RoundToInt(Species->MaterializationRequiredScanPercent)),
            FText::FromString(AbilityList)));
    }

    TArray<FString> PreviousForms;
    for (UDMFDigimonSpeciesData* Candidate : AllSpecies)
    {
        if (!Candidate || Candidate == Species) continue;
        for (const FDMFDigivolutionRequirement& Path : Candidate->Digivolutions)
        {
            UDMFDigimonSpeciesData* Target = Path.TargetSpecies.LoadSynchronous();
            if (Target && Target->GetPrimaryAssetId() == SpeciesId)
            {
                PreviousForms.AddUnique(Candidate->DisplayName.IsEmpty() ? Candidate->GetPrimaryAssetId().PrimaryAssetName.ToString() : Candidate->DisplayName.ToString());
            }
        }
    }
    TArray<FString> NextForms;
    for (const FDMFDigivolutionRequirement& Path : Species->Digivolutions)
    {
        if (UDMFDigimonSpeciesData* Target = Path.TargetSpecies.LoadSynchronous())
        {
            NextForms.AddUnique(Target->DisplayName.IsEmpty() ? Target->GetPrimaryAssetId().PrimaryAssetName.ToString() : Target->DisplayName.ToString());
        }
    }
    if (DigiDexSelectedEvolutionText)
    {
        DigiDexSelectedEvolutionText->SetText(FText::Format(NSLOCTEXT("DMF", "DigiDexEvolutionLinks",
            "EVOLUTION FAMILY\nFROM  {0}\nTO      {1}"),
            FText::FromString(PreviousForms.IsEmpty() ? TEXT("—") : FString::Join(PreviousForms, TEXT(", "))),
            FText::FromString(NextForms.IsEmpty() ? TEXT("—") : FString::Join(NextForms, TEXT(", ")))));
    }
    if (DigiDexSelectedDescriptionText)
    {
        DigiDexSelectedDescriptionText->SetText(Species->Description.IsEmpty()
            ? NSLOCTEXT("DMF", "DigiDexNoDescription", "No species description has been assigned yet.")
            : Species->Description);
    }
    BP_OnDigiDexSelectionChanged(SpeciesId, Species);
}

void UDMFDigimonInventoryWidget::RefreshDigivolutionData()
{
    BindDigimonComponent();
    if (!WidgetTree || !BoundDigimonComponent || !DigivolutionOwnedGrid)
    {
        return;
    }

    const TArray<FDMFDigimonInstance> Party = BoundDigimonComponent->GetPartyDigimon();
    const TArray<FDMFDigimonInstance> Bank = BoundDigimonComponent->GetBankDigimon();
    const FGuid ActiveId = BoundDigimonComponent->GetActivePartnerInstanceId();

    bool bSelectionExists = false;
    auto ContainsInstance = [&](const TArray<FDMFDigimonInstance>& Source, const FGuid Id)
    {
        return Source.ContainsByPredicate([&](const FDMFDigimonInstance& Digimon) { return Digimon.IsValid() && Digimon.InstanceId == Id; });
    };
    bSelectionExists = SelectedDigivolutionInstanceId.IsValid()
        && (ContainsInstance(Party, SelectedDigivolutionInstanceId) || ContainsInstance(Bank, SelectedDigivolutionInstanceId));
    if (!bSelectionExists)
    {
        SelectedDigivolutionInstanceId = ActiveId.IsValid() && ContainsInstance(Party, ActiveId)
            ? ActiveId
            : (Party.Num() > 0 ? Party[0].InstanceId : (Bank.Num() > 0 ? Bank[0].InstanceId : FGuid()));
        SelectedDigivolutionTargetSpeciesId = FPrimaryAssetId();
    }

    DigivolutionOwnedGrid->ClearChildren();
    int32 VisualIndex = 0;
    auto AddOwnedCard = [&](const FDMFDigimonInstance& Digimon, const EDMFDigimonStorageLocation Location)
    {
        if (!Digimon.IsValid()) return;
        UDMFDigimonSpeciesData* Species = ResolveSpecies(Digimon.SpeciesId);
        const FText SpeciesName = Species && !Species->DisplayName.IsEmpty() ? Species->DisplayName : FText::FromName(Digimon.SpeciesId.PrimaryAssetName);
        const FText DisplayName = Digimon.Nickname.IsEmpty() ? SpeciesName : FText::FromString(Digimon.Nickname);
        const bool bSelected = Digimon.InstanceId == SelectedDigivolutionInstanceId;
        const bool bActive = Location == EDMFDigimonStorageLocation::Party && Digimon.InstanceId == ActiveId;

        // Keep Digivolution-owned cards at a fixed, readable footprint. UniformGrid cells can become
        // much wider than their content when only one or two Digimon exist; centering the fixed
        // SizeBox prevents the button/portrait from stretching across the entire left panel.
        USizeBox* CardSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        CardSize->SetWidthOverride(DMFInventoryUI::DigivolutionOwnedCardWidth);
        CardSize->SetHeightOverride(DMFInventoryUI::DigivolutionOwnedCardHeight);

        UDMFDigimonInventoryEntryButton* Button = WidgetTree->ConstructWidget<UDMFDigimonInventoryEntryButton>(UDMFDigimonInventoryEntryButton::StaticClass());
        Button->InitializeDigimonEntry(Digimon.InstanceId);
        Button->OnDigimonPressed.AddDynamic(this, &UDMFDigimonInventoryWidget::HandleDigivolutionOwnedPressed);
        DMFNativeUI::StyleCompactButton(Button, false, false, bSelected);
        CardSize->AddChild(Button);

        UBorder* Back = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(Back, Digimon.CurrentHP <= 0 ? FLinearColor(0.15f,0.025f,0.035f,0.94f) : DMFNativeUI::SlotEmpty(), FMargin(5.0f));
        Button->AddChild(Back);

        UVerticalBox* CardColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
        Back->AddChild(CardColumn);

        // Portrait gets its own square viewport and ScaleBox. This guarantees that species portraits
        // keep their source aspect ratio instead of being distorted by a wide UniformGrid cell.
        USizeBox* PortraitViewport = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        PortraitViewport->SetWidthOverride(DMFInventoryUI::DigivolutionOwnedPortraitSize);
        PortraitViewport->SetHeightOverride(DMFInventoryUI::DigivolutionOwnedPortraitSize);
        if (UVerticalBoxSlot* PortraitViewportSlot = CardColumn->AddChildToVerticalBox(PortraitViewport))
        {
            PortraitViewportSlot->SetHorizontalAlignment(HAlign_Center);
            PortraitViewportSlot->SetPadding(FMargin(0.0f, 1.0f, 0.0f, 4.0f));
        }

        UOverlay* PortraitOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass());
        PortraitViewport->AddChild(PortraitOverlay);

        UScaleBox* PortraitScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass());
        PortraitScale->SetStretch(EStretch::ScaleToFit);
        PortraitScale->SetStretchDirection(EStretchDirection::DownOnly);
        if (UOverlaySlot* PortraitScaleSlot = PortraitOverlay->AddChildToOverlay(PortraitScale))
        {
            PortraitScaleSlot->SetHorizontalAlignment(HAlign_Center);
            PortraitScaleSlot->SetVerticalAlignment(VAlign_Center);
        }

        UImage* Portrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
        if (UTexture2D* Texture = Species ? Species->Portrait.LoadSynchronous() : nullptr)
        {
            Portrait->SetBrushFromTexture(Texture, true);
            Portrait->SetColorAndOpacity(Digimon.CurrentHP <= 0 ? FLinearColor(0.5f,0.5f,0.5f,1) : FLinearColor::White);
        }
        else
        {
            Portrait->SetColorAndOpacity(FLinearColor::Transparent);
        }
        PortraitScale->AddChild(Portrait);

        if (Digimon.CurrentHP <= 0 || bActive)
        {
            UBorder* Badge = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
            DMFNativeUI::StylePanel(Badge, Digimon.CurrentHP <= 0 ? DMFNativeUI::Danger() : DMFNativeUI::Success(), FMargin(4,1));
            UTextBlock* BadgeText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            BadgeText->SetText(Digimon.CurrentHP <= 0 ? NSLOCTEXT("DMF","DigivolutionKOBadge","KO") : NSLOCTEXT("DMF","DigivolutionActiveBadge","ACTIVE"));
            DMFNativeUI::StyleText(BadgeText, 8, FLinearColor::White, true);
            Badge->AddChild(BadgeText);
            if (UOverlaySlot* BadgeSlot = PortraitOverlay->AddChildToOverlay(Badge))
            {
                BadgeSlot->SetPadding(FMargin(2.0f));
                BadgeSlot->SetHorizontalAlignment(HAlign_Right);
                BadgeSlot->SetVerticalAlignment(VAlign_Top);
            }
        }

        UBorder* Footer = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(Footer, FLinearColor(0.004f,0.012f,0.03f,0.96f), FMargin(4.0f, 3.0f));
        if (UVerticalBoxSlot* FooterLayoutSlot = CardColumn->AddChildToVerticalBox(Footer))
        {
            FooterLayoutSlot->SetSize(DMFNativeUI::FillSize());
            FooterLayoutSlot->SetVerticalAlignment(VAlign_Fill);
        }

        UVerticalBox* FooterColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
        Footer->AddChild(FooterColumn);

        UTextBlock* LocationText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        LocationText->SetText(Location == EDMFDigimonStorageLocation::Party ? NSLOCTEXT("DMF","DigivolutionPartyBadge","PARTY") : NSLOCTEXT("DMF","DigivolutionBankBadge","BANK"));
        LocationText->SetJustification(ETextJustify::Center);
        DMFNativeUI::StyleText(LocationText, 8, bActive ? DMFNativeUI::Success() : DMFNativeUI::Gold(), true);
        FooterColumn->AddChildToVerticalBox(LocationText);

        UTextBlock* NameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        NameText->SetText(FText::Format(NSLOCTEXT("DMF","DigivolutionOwnedCardName","{0} • Lv.{1}"), DisplayName, FText::AsNumber(Digimon.Stats.Level)));
        NameText->SetJustification(ETextJustify::Center);
        NameText->SetAutoWrapText(true);
        DMFNativeUI::StyleText(NameText, 9, DMFNativeUI::Text(), true);
        if (UVerticalBoxSlot* NameLayoutSlot = FooterColumn->AddChildToVerticalBox(NameText))
        {
            NameLayoutSlot->SetSize(DMFNativeUI::FillSize());
            NameLayoutSlot->SetVerticalAlignment(VAlign_Center);
        }

        const int32 Row = VisualIndex / DMFInventoryUI::DigivolutionOwnedColumns;
        const int32 Column = VisualIndex % DMFInventoryUI::DigivolutionOwnedColumns;
        if (UUniformGridSlot* GridSlot = DigivolutionOwnedGrid->AddChildToUniformGrid(CardSize, Row, Column))
        {
            // Critical: Fill caused a one-card row to expand to the full panel width, distorting the
            // portrait. Centering honors the SizeBox overrides regardless of how many cards are present.
            GridSlot->SetHorizontalAlignment(HAlign_Center);
            GridSlot->SetVerticalAlignment(VAlign_Top);
        }
        ++VisualIndex;
    };

    for (const FDMFDigimonInstance& Digimon : Party) AddOwnedCard(Digimon, EDMFDigimonStorageLocation::Party);
    for (const FDMFDigimonInstance& Digimon : Bank) AddOwnedCard(Digimon, EDMFDigimonStorageLocation::Bank);

    // Preserve the three-column geometry even when the account owns only one or two Digimon.
    // Without these desired-size placeholders UniformGrid collapses to the number of occupied
    // columns, making sparse rows much wider than full rows.
    if (VisualIndex < DMFInventoryUI::DigivolutionOwnedColumns)
    {
        for (int32 EmptyColumn = VisualIndex; EmptyColumn < DMFInventoryUI::DigivolutionOwnedColumns; ++EmptyColumn)
        {
            USizeBox* ColumnPlaceholder = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
            ColumnPlaceholder->SetWidthOverride(DMFInventoryUI::DigivolutionOwnedCardWidth);
            ColumnPlaceholder->SetHeightOverride(1.0f);
            ColumnPlaceholder->SetVisibility(ESlateVisibility::HitTestInvisible);
            if (UUniformGridSlot* PlaceholderSlot = DigivolutionOwnedGrid->AddChildToUniformGrid(ColumnPlaceholder, 0, EmptyColumn))
            {
                PlaceholderSlot->SetHorizontalAlignment(HAlign_Center);
                PlaceholderSlot->SetVerticalAlignment(VAlign_Top);
            }
        }
    }

    RefreshSelectedDigivolutionDetails();
}

void UDMFDigimonInventoryWidget::RefreshSelectedDigivolutionDetails()
{
    if (!BoundDigimonComponent)
    {
        return;
    }

    FDMFDigimonInstance Digimon;
    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Party;
    const bool bHasSelection = SelectedDigivolutionInstanceId.IsValid()
        && BoundDigimonComponent->GetOwnedDigimonByInstanceId(SelectedDigivolutionInstanceId, Digimon, Location);
    UDMFDigimonSpeciesData* SourceSpecies = bHasSelection ? ResolveSpecies(Digimon.SpeciesId) : nullptr;

    if (!bHasSelection || !SourceSpecies)
    {
        if (DigivolutionCurrentPortraitImage) DigivolutionCurrentPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        if (DigivolutionCurrentNameText) DigivolutionCurrentNameText->SetText(NSLOCTEXT("DMF","DigivolutionNoOwnedSelection","NO DIGIMON SELECTED"));
        if (DigivolutionCurrentMetaText) DigivolutionCurrentMetaText->SetText(NSLOCTEXT("DMF","DigivolutionNoOwnedMeta","Choose a Digimon from Party or Bank."));
        if (DigivolutionPathList) DigivolutionPathList->ClearChildren();
        if (DigivolutionTargetPortraitImage) DigivolutionTargetPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        if (DigivolutionTargetNameText) DigivolutionTargetNameText->SetText(NSLOCTEXT("DMF","DigivolutionNoTarget","NO TARGET FORM"));
        if (DigivolutionTargetMetaText) DigivolutionTargetMetaText->SetText(FText::GetEmpty());
        if (DigivolutionRequirementText) DigivolutionRequirementText->SetText(NSLOCTEXT("DMF","DigivolutionSelectOwnedHelp","Select an owned Digimon to inspect its configured Digivolution paths."));
        if (DigivolveButton) DigivolveButton->SetIsEnabled(false);
        SelectedDigivolutionTargetSpeciesId = FPrimaryAssetId();
        return;
    }

    const FText SpeciesName = SourceSpecies->DisplayName.IsEmpty() ? FText::FromName(Digimon.SpeciesId.PrimaryAssetName) : SourceSpecies->DisplayName;
    const FText DisplayName = Digimon.Nickname.IsEmpty() ? SpeciesName : FText::FromString(Digimon.Nickname);
    if (DigivolutionCurrentPortraitImage)
    {
        if (UTexture2D* Texture = SourceSpecies->Portrait.LoadSynchronous())
        {
            DigivolutionCurrentPortraitImage->SetBrushFromTexture(Texture, true);
            DigivolutionCurrentPortraitImage->SetColorAndOpacity(Digimon.CurrentHP <= 0 ? FLinearColor(0.55f,0.55f,0.55f,1) : FLinearColor::White);
            DigivolutionCurrentPortraitImage->SetVisibility(ESlateVisibility::Visible);
        }
        else DigivolutionCurrentPortraitImage->SetVisibility(ESlateVisibility::Hidden);
    }
    if (DigivolutionCurrentNameText) DigivolutionCurrentNameText->SetText(DisplayName);
    if (DigivolutionCurrentMetaText)
    {
        DigivolutionCurrentMetaText->SetText(FText::Format(
            NSLOCTEXT("DMF","DigivolutionCurrentMetaFormat","{0}  •  {1}  •  Lv.{2}\n{3}  •  HP {4}/{5}  •  ABI {6}  •  CAM {7}"),
            UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(SourceSpecies->Stage),
            DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), static_cast<int64>(SourceSpecies->Attribute)),
            FText::AsNumber(Digimon.Stats.Level),
            Location == EDMFDigimonStorageLocation::Party ? NSLOCTEXT("DMF","DigivolutionLocationParty","PARTY") : NSLOCTEXT("DMF","DigivolutionLocationBank","BANK"),
            FText::AsNumber(Digimon.CurrentHP), FText::AsNumber(Digimon.Stats.MaxHP), FText::AsNumber(Digimon.Stats.ABI), FText::AsNumber(Digimon.Stats.CAM)));
    }

    const TArray<FDMFDigivolutionEvaluation> Options = BoundDigimonComponent->GetDigivolutionOptions(SelectedDigivolutionInstanceId);
    bool bTargetStillExists = Options.ContainsByPredicate([&](const FDMFDigivolutionEvaluation& Evaluation)
    {
        return Evaluation.TargetSpeciesId == SelectedDigivolutionTargetSpeciesId;
    });
    if (!bTargetStillExists)
    {
        SelectedDigivolutionTargetSpeciesId = FPrimaryAssetId();
        for (const FDMFDigivolutionEvaluation& Evaluation : Options)
        {
            if (Evaluation.bEligible) { SelectedDigivolutionTargetSpeciesId = Evaluation.TargetSpeciesId; break; }
        }
        if (!SelectedDigivolutionTargetSpeciesId.IsValid() && Options.Num() > 0)
        {
            SelectedDigivolutionTargetSpeciesId = Options[0].TargetSpeciesId;
        }
    }

    if (DigivolutionPathList)
    {
        DigivolutionPathList->ClearChildren();
        if (Options.IsEmpty())
        {
            UBorder* EmptyBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
            DMFNativeUI::StylePanel(EmptyBorder, DMFNativeUI::SlotEmpty(), FMargin(12));
            UTextBlock* EmptyText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            EmptyText->SetText(NSLOCTEXT("DMF","DigivolutionNoPaths","NO DIGIVOLUTION PATHS CONFIGURED\nAdd one or more target species to this species Data Asset."));
            EmptyText->SetAutoWrapText(true);
            EmptyText->SetJustification(ETextJustify::Center);
            DMFNativeUI::StyleText(EmptyText, 12, DMFNativeUI::Muted(), true);
            EmptyBorder->AddChild(EmptyText);
            DigivolutionPathList->AddChildToVerticalBox(EmptyBorder)->SetPadding(FMargin(0,0,0,6));
        }
        for (const FDMFDigivolutionEvaluation& Evaluation : Options)
        {
            UDMFDigimonSpeciesData* TargetSpecies = ResolveSpecies(Evaluation.TargetSpeciesId);
            if (!TargetSpecies) continue;
            UDMFScanSpeciesEntryButton* PathButton = WidgetTree->ConstructWidget<UDMFScanSpeciesEntryButton>(UDMFScanSpeciesEntryButton::StaticClass());
            PathButton->InitializeScanSpecies(Evaluation.TargetSpeciesId);
            PathButton->OnSpeciesPressed.AddDynamic(this, &UDMFDigimonInventoryWidget::HandleDigivolutionTargetPressed);
            DMFNativeUI::StyleCompactButton(PathButton, Evaluation.bEligible, false, Evaluation.TargetSpeciesId == SelectedDigivolutionTargetSpeciesId);

            UBorder* PathBack = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
            DMFNativeUI::StylePanel(PathBack, Evaluation.bEligible ? FLinearColor(0.018f,0.10f,0.08f,0.96f) : DMFNativeUI::SlotEmpty(), FMargin(6));
            PathButton->AddChild(PathBack);
            UHorizontalBox* PathRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
            PathBack->AddChild(PathRow);
            USizeBox* PathPortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
            PathPortraitSize->SetWidthOverride(76.0f); PathPortraitSize->SetHeightOverride(76.0f);
            PathRow->AddChildToHorizontalBox(PathPortraitSize)->SetPadding(FMargin(0,0,10,0));
            UImage* PathPortrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
            if (UTexture2D* Texture = TargetSpecies->Portrait.LoadSynchronous()) PathPortrait->SetBrushFromTexture(Texture,true); else PathPortrait->SetColorAndOpacity(FLinearColor::Transparent);
            PathPortraitSize->AddChild(PathPortrait);
            UVerticalBox* PathTextColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
            if (UHorizontalBoxSlot* PathTextSlot = PathRow->AddChildToHorizontalBox(PathTextColumn)) { PathTextSlot->SetSize(DMFNativeUI::FillSize()); PathTextSlot->SetVerticalAlignment(VAlign_Center); }
            UTextBlock* PathName = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            PathName->SetText(TargetSpecies->DisplayName.IsEmpty() ? FText::FromName(Evaluation.TargetSpeciesId.PrimaryAssetName) : TargetSpecies->DisplayName);
            DMFNativeUI::StyleText(PathName, 15, Evaluation.bEligible ? DMFNativeUI::Success() : DMFNativeUI::Text(), true);
            PathTextColumn->AddChildToVerticalBox(PathName);
            UTextBlock* PathMeta = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            PathMeta->SetText(FText::Format(NSLOCTEXT("DMF","DigivolutionPathMeta","{0}  •  {1}"),
                UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(TargetSpecies->Stage),
                DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), static_cast<int64>(TargetSpecies->Attribute))));
            DMFNativeUI::StyleText(PathMeta, 10, DMFNativeUI::Gold(), true);
            PathTextColumn->AddChildToVerticalBox(PathMeta);
            UTextBlock* PathRequirements = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            PathRequirements->SetText(Evaluation.RequirementSummary.IsEmpty() ? NSLOCTEXT("DMF","DigivolutionNoRequirements","No additional requirements") : Evaluation.RequirementSummary);
            PathRequirements->SetAutoWrapText(true);
            DMFNativeUI::StyleText(PathRequirements, 9, DMFNativeUI::Muted());
            PathTextColumn->AddChildToVerticalBox(PathRequirements);
            UTextBlock* PathState = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            PathState->SetText(Evaluation.bEligible ? NSLOCTEXT("DMF","DigivolutionReadyState","READY TO DIGIVOLVE") : FText::Format(NSLOCTEXT("DMF","DigivolutionLockedState","LOCKED • {0}"), Evaluation.FailureReason));
            PathState->SetAutoWrapText(true);
            DMFNativeUI::StyleText(PathState, 9, Evaluation.bEligible ? DMFNativeUI::Success() : DMFNativeUI::Danger(), true);
            PathTextColumn->AddChildToVerticalBox(PathState);
            DigivolutionPathList->AddChildToVerticalBox(PathButton)->SetPadding(FMargin(0,0,0,6));
        }
    }

    UDMFDigimonSpeciesData* TargetSpecies = ResolveSpecies(SelectedDigivolutionTargetSpeciesId);
    if (!TargetSpecies)
    {
        if (DigivolutionTargetPortraitImage) DigivolutionTargetPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        if (DigivolutionTargetNameText) DigivolutionTargetNameText->SetText(NSLOCTEXT("DMF","DigivolutionNoTargetConfigured","NO TARGET FORM"));
        if (DigivolutionTargetMetaText) DigivolutionTargetMetaText->SetText(Options.IsEmpty() ? NSLOCTEXT("DMF","DigivolutionNoTargetConfiguredMeta","This form has no configured Digivolution paths.") : FText::GetEmpty());
        if (DigivolutionRequirementText) DigivolutionRequirementText->SetText(NSLOCTEXT("DMF","DigivolutionNoTargetRequirements","Choose a configured target form to inspect its requirements."));
        if (DigivolveButton) DigivolveButton->SetIsEnabled(false);
        return;
    }

    if (DigivolutionTargetPortraitImage)
    {
        if (UTexture2D* Texture = TargetSpecies->Portrait.LoadSynchronous()) { DigivolutionTargetPortraitImage->SetBrushFromTexture(Texture,true); DigivolutionTargetPortraitImage->SetVisibility(ESlateVisibility::Visible); }
        else DigivolutionTargetPortraitImage->SetVisibility(ESlateVisibility::Hidden);
    }
    if (DigivolutionTargetNameText) DigivolutionTargetNameText->SetText(TargetSpecies->DisplayName.IsEmpty() ? FText::FromName(SelectedDigivolutionTargetSpeciesId.PrimaryAssetName) : TargetSpecies->DisplayName);
    if (DigivolutionTargetMetaText)
    {
        DigivolutionTargetMetaText->SetText(FText::Format(NSLOCTEXT("DMF","DigivolutionTargetMetaFormat","{0}  •  {1}\nWorld class: {2}"),
            UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(TargetSpecies->Stage),
            DMFInventoryUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), static_cast<int64>(TargetSpecies->Attribute)),
            TargetSpecies->WorldActorClass.IsNull() ? NSLOCTEXT("DMF","DigivolutionWorldClassMissing","NOT ASSIGNED") : NSLOCTEXT("DMF","DigivolutionWorldClassReady","READY")));
    }

    const FDMFDigivolutionEvaluation* SelectedEvaluation = Options.FindByPredicate([&](const FDMFDigivolutionEvaluation& Evaluation)
    {
        return Evaluation.TargetSpeciesId == SelectedDigivolutionTargetSpeciesId;
    });
    FText Failure;
    const bool bCanDigivolve = BoundDigimonComponent->CanDigivolveOwnedDigimonTo(SelectedDigivolutionInstanceId, SelectedDigivolutionTargetSpeciesId, Failure);
    if (DigivolutionRequirementText)
    {
        const FText RequirementSummary = SelectedEvaluation && !SelectedEvaluation->RequirementSummary.IsEmpty()
            ? SelectedEvaluation->RequirementSummary
            : NSLOCTEXT("DMF","DigivolutionRequirementsNone","No additional progression requirements.");
        const FText StateText = bCanDigivolve
            ? NSLOCTEXT("DMF","DigivolutionRequirementsReady","STATUS: READY\nThe server will validate these requirements again when you confirm. The individual GUID, nickname, Care state, Level/EXP and configured stat investment are preserved.")
            : FText::Format(NSLOCTEXT("DMF","DigivolutionRequirementsLocked","STATUS: LOCKED\n{0}\n\nThe server revalidates every requirement; clients cannot force a form change."), Failure);
        DigivolutionRequirementText->SetText(FText::Format(NSLOCTEXT("DMF","DigivolutionRequirementsPanel","REQUIREMENTS\n{0}\n\n{1}"), RequirementSummary, StateText));
        DigivolutionRequirementText->SetColorAndOpacity(FSlateColor(bCanDigivolve ? DMFNativeUI::Text() : DMFNativeUI::Muted()));
    }
    if (DigivolveButton)
    {
        DigivolveButton->SetIsEnabled(bCanDigivolve && !BoundDigimonComponent->IsDigivolutionSequenceActive());
    }
}

void UDMFDigimonInventoryWidget::HandleDigivolutionOwnedPressed(const FGuid InstanceId)
{
    SelectedDigivolutionInstanceId = InstanceId;
    SelectedDigivolutionTargetSpeciesId = FPrimaryAssetId();
    RefreshDigivolutionData();
}

void UDMFDigimonInventoryWidget::HandleDigivolutionTargetPressed(const FPrimaryAssetId SpeciesId)
{
    SelectedDigivolutionTargetSpeciesId = SpeciesId;
    RefreshSelectedDigivolutionDetails();
}

void UDMFDigimonInventoryWidget::HandleDigivolveSelected()
{
    if (BoundDigimonComponent && SelectedDigivolutionInstanceId.IsValid() && SelectedDigivolutionTargetSpeciesId.IsValid())
    {
        BoundDigimonComponent->ServerDigivolveOwnedDigimon(SelectedDigivolutionInstanceId, SelectedDigivolutionTargetSpeciesId);
    }
}

void UDMFDigimonInventoryWidget::HandleDigivolutionResult(const bool bSuccess, const FText Message, const FGuid DigimonInstanceId, const FPrimaryAssetId PreviousSpeciesId, const FPrimaryAssetId NewSpeciesId)
{
    if (bSuccess && DigimonInstanceId.IsValid())
    {
        SelectedDigivolutionInstanceId = DigimonInstanceId;
        SelectedDigivolutionTargetSpeciesId = FPrimaryAssetId();
    }
    RefreshInventory();
    RefreshBankData();
    RefreshDigivolutionData();
    RefreshDigiDexData();
    if (DigimonStatusText && !Message.IsEmpty())
    {
        DigimonStatusText->SetText(Message);
        DigimonStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
}

void UDMFDigimonInventoryWidget::HandleDigivolutionTab()
{
    SetActiveMenuTab(EDMFDigimonMenuTab::Digivolution);
}


void UDMFDigimonInventoryWidget::HandleDigiDexTab()
{
    SetActiveMenuTab(EDMFDigimonMenuTab::DigiDex);
}

void UDMFDigimonInventoryWidget::HandleDigiDexSpeciesPressed(const FPrimaryAssetId SpeciesId)
{
    SelectedDigiDexSpeciesId = SpeciesId;
    RefreshDigiDexData();
}

void UDMFDigimonInventoryWidget::HandleDigiDexSearchChanged(const FText& SearchText)
{
    DigiDexSearchQuery = SearchText.ToString().TrimStartAndEnd();
    RefreshDigiDexData();
}

void UDMFDigimonInventoryWidget::HandleDigiDexStageFilter()
{
    const UEnum* StageEnum = StaticEnum<EDMFDigimonStage>();
    const int32 RealStageCount = StageEnum ? FMath::Max(0, StageEnum->NumEnums() - 1) : 0;
    if (RealStageCount <= 0)
    {
        DigiDexStageFilterIndex = INDEX_NONE;
    }
    else if (DigiDexStageFilterIndex == INDEX_NONE)
    {
        DigiDexStageFilterIndex = 0;
    }
    else
    {
        ++DigiDexStageFilterIndex;
        if (DigiDexStageFilterIndex >= RealStageCount) DigiDexStageFilterIndex = INDEX_NONE;
    }
    RefreshDigiDexData();
}

void UDMFDigimonInventoryWidget::HandleDigiDexAttributeFilter()
{
    const UEnum* AttributeEnum = StaticEnum<EDMFDigimonAttribute>();
    const int32 RealAttributeCount = AttributeEnum ? FMath::Max(0, AttributeEnum->NumEnums() - 1) : 0;
    if (RealAttributeCount <= 0)
    {
        DigiDexAttributeFilterIndex = INDEX_NONE;
    }
    else if (DigiDexAttributeFilterIndex == INDEX_NONE)
    {
        DigiDexAttributeFilterIndex = 0;
    }
    else
    {
        ++DigiDexAttributeFilterIndex;
        if (DigiDexAttributeFilterIndex >= RealAttributeCount) DigiDexAttributeFilterIndex = INDEX_NONE;
    }
    RefreshDigiDexData();
}

void UDMFDigimonInventoryWidget::HandleInventoryChanged()
{
    RefreshInventory();
    RefreshBankData();
    RefreshSelectedScanDetails();
    RefreshCareData();
    RefreshDigivolutionData();
    if (ActiveMenuTab == EDMFDigimonMenuTab::DigiDex) RefreshDigiDexData();
}

void UDMFDigimonInventoryWidget::HandleBankChanged()
{
    RefreshBankData();
    RefreshSelectedScanDetails();
    RefreshDigivolutionData();
    if (ActiveMenuTab == EDMFDigimonMenuTab::DigiDex) RefreshDigiDexData();
}

void UDMFDigimonInventoryWidget::HandleStorageActionResult(const bool bSuccess, const FText Message, const FGuid DigimonInstanceId, const EDMFDigimonStorageLocation NewLocation)
{
    if (bSuccess && DigimonInstanceId.IsValid())
    {
        PendingStorageSelectionId = DigimonInstanceId;
        if (NewLocation == EDMFDigimonStorageLocation::Bank)
        {
            SelectedInstanceId.Invalidate();
            SelectedBankInstanceId = DigimonInstanceId;
            const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
            const int32 PageSize = FMath::Clamp(Settings ? Settings->DigimonBankSlotsPerPage : 30, 6, 60);
            if (BoundDigimonComponent)
            {
                const TArray<FDMFDigimonInstance> Bank = BoundDigimonComponent->GetBankDigimon();
                const int32 BankIndex = Bank.IndexOfByPredicate([&](const FDMFDigimonInstance& Digimon)
                {
                    return Digimon.InstanceId == DigimonInstanceId;
                });
                if (BankIndex != INDEX_NONE)
                {
                    BankPageIndex = BankIndex / PageSize;
                }
            }
            ActiveMenuTab = EDMFDigimonMenuTab::Bank;
        }
        else
        {
            SelectedBankInstanceId.Invalidate();
            SelectedBankPartyDestinationIndex = INDEX_NONE;
            SelectedInstanceId = DigimonInstanceId;
            ActiveMenuTab = EDMFDigimonMenuTab::Collection;
        }
    }
    RefreshInventory();
    RefreshBankData();
    RefreshTabPresentation();
    if (DigimonStatusText && !Message.IsEmpty())
    {
        DigimonStatusText->SetText(Message);
        DigimonStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
}

void UDMFDigimonInventoryWidget::HandleAttributePointSpendResult(const bool bSuccess, const FText Message, const FGuid DigimonInstanceId, const EDMFDigimonAttributeStat Stat, const int32 NewStatValue, const int32 RemainingPoints)
{
    RefreshInventory();
    RefreshBankData();
    if (DigimonStatusText && !Message.IsEmpty())
    {
        DigimonStatusText->SetText(Message);
        DigimonStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
}

void UDMFDigimonInventoryWidget::HandleScanDataChanged(const FPrimaryAssetId SpeciesId, const float ScanPercent, const bool bMaterializationReady)
{
    RefreshScanData();
    if (ActiveMenuTab == EDMFDigimonMenuTab::DigiDex) RefreshDigiDexData();
}

void UDMFDigimonInventoryWidget::HandleMaterializationResult(const bool bSuccess, const FText Message, const FPrimaryAssetId SpeciesId, const FGuid NewDigimonInstanceId)
{
    if (bSuccess && NewDigimonInstanceId.IsValid())
    {
        // Do not infer placement from counts: the reliable RPC and owner-only Party/Bank FastArrays can be
        // delivered in either order. Keep the GUID pending; RefreshInventory/RefreshBankData selects the
        // authoritative location as soon as the corresponding replicated entry is visible.
        PendingStorageSelectionId = NewDigimonInstanceId;
    }

    RefreshInventory();
    RefreshBankData();
    RefreshScanData();
    RefreshDigivolutionData();
    RefreshDigiDexData();
    RefreshTabPresentation();
    if (DigimonStatusText && !Message.IsEmpty())
    {
        DigimonStatusText->SetText(Message);
        DigimonStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
}

void UDMFDigimonInventoryWidget::HandleCollectionTab() { SetActiveMenuTab(EDMFDigimonMenuTab::Collection); }
void UDMFDigimonInventoryWidget::HandleBankTab() { SetActiveMenuTab(EDMFDigimonMenuTab::Bank); }
void UDMFDigimonInventoryWidget::HandleScanMaterializeTab() { SetActiveMenuTab(EDMFDigimonMenuTab::ScanAndMaterialize); }
void UDMFDigimonInventoryWidget::HandleCareTab() { SetActiveMenuTab(EDMFDigimonMenuTab::Care); }
void UDMFDigimonInventoryWidget::HandleFeedDigiMeat() { if (BoundDigimonComponent) BoundDigimonComponent->ServerFeedActivePartnerUntilFull(); }
void UDMFDigimonInventoryWidget::HandleCareStateChanged(const FGuid DigimonInstanceId, const FDMFDigimonCareState CareState) { RefreshCareData(); }
void UDMFDigimonInventoryWidget::HandleCareSequenceFinished(const bool bSuccess, const FText Message, const FGuid DigimonInstanceId) { RefreshCareData(); if (DigimonStatusText && !Message.IsEmpty()) { DigimonStatusText->SetText(Message); DigimonStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger())); } }
void UDMFDigimonInventoryWidget::HandleScanSpeciesPressed(const FPrimaryAssetId SpeciesId) { SelectedScanSpeciesId=SpeciesId; RefreshScanData(); }
void UDMFDigimonInventoryWidget::HandleMaterializeSelected() { if(BoundDigimonComponent && SelectedScanSpeciesId.IsValid()) BoundDigimonComponent->ServerMaterializeDigimon(SelectedScanSpeciesId); }

void UDMFDigimonInventoryWidget::HandleBankDigimonPressed(const FGuid InstanceId)
{
    SelectedBankInstanceId = InstanceId;
    RefreshBankData();
}

void UDMFDigimonInventoryWidget::HandleBankPartyDestinationPressed(const int32 PartySlotIndex)
{
    SelectedBankPartyDestinationIndex = SelectedBankPartyDestinationIndex == PartySlotIndex ? INDEX_NONE : PartySlotIndex;
    RefreshBankData();
}

void UDMFDigimonInventoryWidget::HandleMoveSelectedToBank()
{
    if (BoundDigimonComponent && SelectedInstanceId.IsValid())
    {
        BoundDigimonComponent->ServerMovePartyDigimonToBank(SelectedInstanceId);
    }
}

void UDMFDigimonInventoryWidget::HandleMoveSelectedBankToParty()
{
    if (BoundDigimonComponent && SelectedBankInstanceId.IsValid())
    {
        const int32 Destination = SelectedBankPartyDestinationIndex;
        BoundDigimonComponent->ServerMoveBankDigimonToParty(SelectedBankInstanceId, Destination, true);
    }
}

void UDMFDigimonInventoryWidget::HandleBankPreviousPage()
{
    BankPageIndex = FMath::Max(0, BankPageIndex - 1);
    SelectedBankInstanceId.Invalidate();
    SelectedBankPartyDestinationIndex = INDEX_NONE;
    RefreshBankData();
}

void UDMFDigimonInventoryWidget::HandleBankNextPage()
{
    ++BankPageIndex;
    SelectedBankInstanceId.Invalidate();
    SelectedBankPartyDestinationIndex = INDEX_NONE;
    RefreshBankData();
}

void UDMFDigimonInventoryWidget::HandleDigimonPressed(const FGuid InstanceId)
{
    SelectedInstanceId = InstanceId;
    RefreshInventory();
}

void UDMFDigimonInventoryWidget::HandleSummonSelected()
{
    if (BoundDigimonComponent && SelectedInstanceId.IsValid())
    {
        BoundDigimonComponent->ServerSetActivePartner(SelectedInstanceId, true);
    }
}

void UDMFDigimonInventoryWidget::HandleRecallPartner()
{
    if (BoundDigimonComponent)
    {
        BoundDigimonComponent->ServerRecallActivePartner();
    }
}

void UDMFDigimonInventoryWidget::HandleSpendPartyHP() { RequestAttributePointSpend(EDMFDigimonAttributeStat::MaxHP, false); }
void UDMFDigimonInventoryWidget::HandleSpendPartySP() { RequestAttributePointSpend(EDMFDigimonAttributeStat::MaxSP, false); }
void UDMFDigimonInventoryWidget::HandleSpendPartyStrength() { RequestAttributePointSpend(EDMFDigimonAttributeStat::Strength, false); }
void UDMFDigimonInventoryWidget::HandleSpendPartyIntelligence() { RequestAttributePointSpend(EDMFDigimonAttributeStat::Intelligence, false); }
void UDMFDigimonInventoryWidget::HandleSpendPartyDefense() { RequestAttributePointSpend(EDMFDigimonAttributeStat::Defense, false); }
void UDMFDigimonInventoryWidget::HandleSpendPartySpeed() { RequestAttributePointSpend(EDMFDigimonAttributeStat::Speed, false); }
void UDMFDigimonInventoryWidget::HandleSpendBankHP() { RequestAttributePointSpend(EDMFDigimonAttributeStat::MaxHP, true); }
void UDMFDigimonInventoryWidget::HandleSpendBankSP() { RequestAttributePointSpend(EDMFDigimonAttributeStat::MaxSP, true); }
void UDMFDigimonInventoryWidget::HandleSpendBankStrength() { RequestAttributePointSpend(EDMFDigimonAttributeStat::Strength, true); }
void UDMFDigimonInventoryWidget::HandleSpendBankIntelligence() { RequestAttributePointSpend(EDMFDigimonAttributeStat::Intelligence, true); }
void UDMFDigimonInventoryWidget::HandleSpendBankDefense() { RequestAttributePointSpend(EDMFDigimonAttributeStat::Defense, true); }
void UDMFDigimonInventoryWidget::HandleSpendBankSpeed() { RequestAttributePointSpend(EDMFDigimonAttributeStat::Speed, true); }

void UDMFDigimonInventoryWidget::HandleClose()
{
    if (ADMFMMOPlayerController* FrameworkController = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        FrameworkController->CloseDigimonInventoryUI();
    }
}

void UDMFDigimonInventoryWidget::HandlePartnerActionResult(const bool bSuccess, const FText Message, const FGuid PartnerInstanceId)
{
    if (bSuccess && PartnerInstanceId.IsValid())
    {
        SelectedInstanceId = PartnerInstanceId;
    }
    RefreshInventory();
    if (DigimonStatusText && !Message.IsEmpty())
    {
        DigimonStatusText->SetText(Message);
        DigimonStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
    BP_OnPartnerActionResult(bSuccess, Message, PartnerInstanceId);
}
