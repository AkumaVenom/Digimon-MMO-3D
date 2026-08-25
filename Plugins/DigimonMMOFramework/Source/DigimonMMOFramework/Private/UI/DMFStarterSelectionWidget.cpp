#include "UI/DMFStarterSelectionWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/ScaleBox.h"
#include "Components/ScrollBox.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Data/DMFStarterRosterData.h"
#include "Engine/Texture2D.h"
#include "Game/DMFPlayerState.h"
#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFNativeUIStyle.h"
#include "UI/DMFStarterEntryButton.h"

namespace DMFStarterUI
{
    FText EnumDisplay(const UEnum* EnumType, const int64 Value)
    {
        return EnumType ? EnumType->GetDisplayNameTextByValue(Value) : FText::GetEmpty();
    }
}

TSharedRef<SWidget> UDMFStarterSelectionWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFStarterWidgetTree"));
    }

    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }

    return Super::RebuildWidget();
}

void UDMFStarterSelectionWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ConfirmButton)
    {
        ConfirmButton->OnClicked.AddUniqueDynamic(this, &UDMFStarterSelectionWidget::HandleConfirm);
        ConfirmButton->SetIsEnabled(false);
    }

    if (APlayerController* OwningController = GetOwningPlayer())
    {
        if (ADMFPlayerState* FrameworkPlayerState = OwningController->GetPlayerState<ADMFPlayerState>())
        {
            if (FrameworkPlayerState->DigimonComponent)
            {
                FrameworkPlayerState->DigimonComponent->OnStarterSelectionResult.RemoveDynamic(this, &UDMFStarterSelectionWidget::HandleStarterSelectionResult);
                FrameworkPlayerState->DigimonComponent->OnStarterSelectionResult.AddDynamic(this, &UDMFStarterSelectionWidget::HandleStarterSelectionResult);
            }
        }
    }

    PopulateChoices();
}

void UDMFStarterSelectionWidget::NativeDestruct()
{
    if (APlayerController* OwningController = GetOwningPlayer())
    {
        if (ADMFPlayerState* FrameworkPlayerState = OwningController->GetPlayerState<ADMFPlayerState>())
        {
            if (FrameworkPlayerState->DigimonComponent)
            {
                FrameworkPlayerState->DigimonComponent->OnStarterSelectionResult.RemoveDynamic(this, &UDMFStarterSelectionWidget::HandleStarterSelectionResult);
            }
        }
    }

    Super::NativeDestruct();
}

void UDMFStarterSelectionWidget::BuildNativeFallbackUI()
{
    if (!WidgetTree)
    {
        return;
    }

    UOverlay* RootOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("StarterRootOverlay"));
    WidgetTree->RootWidget = RootOverlay;

    UBorder* BackdropBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("StarterBackdrop"));
    DMFNativeUI::StylePanel(BackdropBorder, DMFNativeUI::Backdrop(), FMargin(0.0f));
    if (UOverlaySlot* BackdropSlot = RootOverlay->AddChildToOverlay(BackdropBorder))
    {
        BackdropSlot->SetHorizontalAlignment(HAlign_Fill);
        BackdropSlot->SetVerticalAlignment(VAlign_Fill);
    }

    UScaleBox* ScreenScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("StarterScreenScale"));
    ScreenScale->SetStretch(EStretch::ScaleToFit);
    ScreenScale->SetStretchDirection(EStretchDirection::DownOnly);
    if (UOverlaySlot* ScaleSlot = RootOverlay->AddChildToOverlay(ScreenScale))
    {
        ScaleSlot->SetHorizontalAlignment(HAlign_Center);
        ScaleSlot->SetVerticalAlignment(VAlign_Center);
        ScaleSlot->SetPadding(FMargin(24.0f));
    }

    USizeBox* WindowSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("StarterWindowSize"));
    WindowSize->SetWidthOverride(1060.0f);
    WindowSize->SetHeightOverride(650.0f);
    ScreenScale->AddChild(WindowSize);

    UBorder* WindowBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("StarterWindowBorder"));
    DMFNativeUI::StylePanel(WindowBorder, DMFNativeUI::Panel(), FMargin(18.0f));
    WindowSize->AddChild(WindowBorder);

    UVerticalBox* WindowColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("StarterWindowColumn"));
    WindowBorder->AddChild(WindowColumn);

    UTextBlock* TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("StarterTitle"));
    TitleText->SetText(NSLOCTEXT("DMF", "StarterPolishedTitle", "CHOOSE YOUR PARTNER DIGIMON"));
    DMFNativeUI::StyleText(TitleText, 30, DMFNativeUI::Text(), true);
    WindowColumn->AddChildToVerticalBox(TitleText);

    StarterStatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("StarterStatusText"));
    StarterStatusText->SetText(NSLOCTEXT("DMF", "StarterPolishedSubtitle", "Your first partner is persistent to this account. Select a card to inspect its starting profile."));
    StarterStatusText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(StarterStatusText, 14, DMFNativeUI::Muted());
    WindowColumn->AddChildToVerticalBox(StarterStatusText)->SetPadding(FMargin(0.0f, 2.0f, 0.0f, 14.0f));

    UHorizontalBox* MainRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("StarterMainRow"));
    if (UVerticalBoxSlot* MainSlot = WindowColumn->AddChildToVerticalBox(MainRow))
    {
        MainSlot->SetSize(DMFNativeUI::FillSize());
    }

    USizeBox* ChoiceAreaSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("StarterChoiceAreaSize"));
    ChoiceAreaSize->SetWidthOverride(650.0f);
    if (UHorizontalBoxSlot* ChoiceAreaSlot = MainRow->AddChildToHorizontalBox(ChoiceAreaSize))
    {
        ChoiceAreaSlot->SetPadding(FMargin(0.0f, 0.0f, 14.0f, 0.0f));
        ChoiceAreaSlot->SetVerticalAlignment(VAlign_Fill);
    }

    UBorder* ChoiceAreaBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("StarterChoiceAreaBorder"));
    DMFNativeUI::StylePanel(ChoiceAreaBorder, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    ChoiceAreaSize->AddChild(ChoiceAreaBorder);

    UVerticalBox* ChoiceColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("StarterChoiceColumn"));
    ChoiceAreaBorder->AddChild(ChoiceColumn);

    UTextBlock* ChoiceHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("StarterChoiceHeader"));
    ChoiceHeader->SetText(NSLOCTEXT("DMF", "StarterAvailableHeader", "AVAILABLE PARTNERS"));
    DMFNativeUI::StyleText(ChoiceHeader, 16, DMFNativeUI::Accent(), true);
    ChoiceColumn->AddChildToVerticalBox(ChoiceHeader)->SetPadding(FMargin(2.0f, 0.0f, 0.0f, 8.0f));

    UScrollBox* ChoiceScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("StarterChoiceScroll"));
    if (UVerticalBoxSlot* ChoiceScrollSlot = ChoiceColumn->AddChildToVerticalBox(ChoiceScroll))
    {
        ChoiceScrollSlot->SetSize(DMFNativeUI::FillSize());
    }

    ChoicesGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("ChoicesGrid"));
    ChoicesGrid->SetSlotPadding(FMargin(7.0f));
    ChoiceScroll->AddChild(ChoicesGrid);

    USizeBox* DetailsAreaSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("StarterDetailsAreaSize"));
    DetailsAreaSize->SetWidthOverride(350.0f);
    MainRow->AddChildToHorizontalBox(DetailsAreaSize)->SetVerticalAlignment(VAlign_Fill);

    UBorder* DetailsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("StarterDetailsBorder"));
    DMFNativeUI::StylePanel(DetailsBorder, DMFNativeUI::PanelRaised(), FMargin(16.0f));
    DetailsAreaSize->AddChild(DetailsBorder);

    UVerticalBox* DetailsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("StarterDetailsColumn"));
    DetailsBorder->AddChild(DetailsColumn);

    USizeBox* PortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("StarterPortraitSize"));
    PortraitSize->SetHeightOverride(230.0f);
    DetailsColumn->AddChildToVerticalBox(PortraitSize)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 10.0f));

    UBorder* PortraitBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("StarterPortraitBorder"));
    DMFNativeUI::StylePanel(PortraitBorder, DMFNativeUI::SlotEmpty(), FMargin(5.0f));
    PortraitSize->AddChild(PortraitBorder);

    SelectedStarterPortrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("SelectedStarterPortrait"));
    SelectedStarterPortrait->SetVisibility(ESlateVisibility::Hidden);
    PortraitBorder->AddChild(SelectedStarterPortrait);

    SelectedStarterNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SelectedStarterNameText"));
    SelectedStarterNameText->SetText(NSLOCTEXT("DMF", "StarterNoneSelected", "SELECT A PARTNER"));
    SelectedStarterNameText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(SelectedStarterNameText, 24, DMFNativeUI::Text(), true);
    DetailsColumn->AddChildToVerticalBox(SelectedStarterNameText);

    SelectedStarterMetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SelectedStarterMetaText"));
    SelectedStarterMetaText->SetText(FText::GetEmpty());
    SelectedStarterMetaText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(SelectedStarterMetaText, 14, DMFNativeUI::Gold(), true);
    DetailsColumn->AddChildToVerticalBox(SelectedStarterMetaText)->SetPadding(FMargin(0.0f, 1.0f, 0.0f, 10.0f));

    UBorder* StatsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("StarterStatsBorder"));
    DMFNativeUI::StylePanel(StatsBorder, DMFNativeUI::PanelSoft(), FMargin(12.0f));
    DetailsColumn->AddChildToVerticalBox(StatsBorder)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 10.0f));

    DetailsText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("DetailsText"));
    DetailsText->SetText(NSLOCTEXT("DMF", "StarterPrompt", "LEVEL --\nHP --    SP --\nSTR --  INT --\nDEF --  SPD --\n\nSelect a partner card to inspect its starting stats."));
    DetailsText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(DetailsText, 14, DMFNativeUI::Text());
    StatsBorder->AddChild(DetailsText);

    ConfirmButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("ConfirmButton"));
    DMFNativeUI::StyleButton(ConfirmButton, true);
    UTextBlock* ConfirmLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ConfirmLabel"));
    ConfirmLabel->SetText(NSLOCTEXT("DMF", "ConfirmStarter", "CONFIRM PARTNER"));
    ConfirmLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(ConfirmLabel, 16, DMFNativeUI::Text(), true);
    ConfirmButton->AddChild(ConfirmLabel);
    DetailsColumn->AddChildToVerticalBox(ConfirmButton)->SetPadding(FMargin(0.0f, 4.0f, 0.0f, 0.0f));
}

void UDMFStarterSelectionWidget::PopulateChoices()
{
    if ((!ChoicesGrid && !ChoicesBox) || !WidgetTree)
    {
        return;
    }

    if (ChoicesGrid)
    {
        ChoicesGrid->ClearChildren();
    }
    if (ChoicesBox)
    {
        ChoicesBox->ClearChildren();
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UDMFStarterRosterData* Roster = Settings ? Settings->StarterRoster.LoadSynchronous() : nullptr;
    if (!Roster)
    {
        const FText MissingMessage = NSLOCTEXT("DMF", "NoRoster", "No Starter Roster is configured. Assign one in Project Settings > Digimon MMO Framework.");
        if (DetailsText)
        {
            DetailsText->SetText(MissingMessage);
        }
        if (StarterStatusText)
        {
            StarterStatusText->SetText(MissingMessage);
            StarterStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Danger()));
        }
        return;
    }

    TArray<FDMFStarterRosterEntry> SortedEntries = Roster->Starters;
    SortedEntries.Sort([](const FDMFStarterRosterEntry& EntryA, const FDMFStarterRosterEntry& EntryB)
    {
        return EntryA.DisplayOrder < EntryB.DisplayOrder;
    });

    int32 VisualIndex = 0;
    for (const FDMFStarterRosterEntry& RosterEntry : SortedEntries)
    {
        if (!RosterEntry.bEnabled)
        {
            continue;
        }

        UDMFDigimonSpeciesData* Species = RosterEntry.Species.LoadSynchronous();
        if (!Species)
        {
            continue;
        }

        UDMFStarterEntryButton* ChoiceButton = WidgetTree->ConstructWidget<UDMFStarterEntryButton>(UDMFStarterEntryButton::StaticClass());
        ChoiceButton->InitializeStarterChoice(Species->GetPrimaryAssetId());
        ChoiceButton->OnStarterPressed.AddDynamic(this, &UDMFStarterSelectionWidget::HandleStarterPressed);
        DMFNativeUI::StyleButton(ChoiceButton, false, false, Species->GetPrimaryAssetId() == SelectedSpeciesId);

        UOverlay* CardOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass());
        ChoiceButton->AddChild(CardOverlay);

        UBorder* CardBackground = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(CardBackground, DMFNativeUI::SlotEmpty(), FMargin(4.0f));
        CardOverlay->AddChildToOverlay(CardBackground);

        UTexture2D* PortraitTexture = Species->Portrait.LoadSynchronous();
        UImage* CardPortrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
        if (PortraitTexture)
        {
            CardPortrait->SetBrushFromTexture(PortraitTexture, true);
        }
        else
        {
            CardPortrait->SetColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.0f));
        }
        if (UOverlaySlot* PortraitSlot = CardOverlay->AddChildToOverlay(CardPortrait))
        {
            PortraitSlot->SetPadding(FMargin(8.0f, 8.0f, 8.0f, 48.0f));
            PortraitSlot->SetHorizontalAlignment(HAlign_Fill);
            PortraitSlot->SetVerticalAlignment(VAlign_Fill);
        }

        UBorder* NameStrip = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(NameStrip, FLinearColor(0.005f, 0.015f, 0.035f, 0.95f), FMargin(5.0f, 4.0f));
        UVerticalBox* NameColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
        NameStrip->AddChild(NameColumn);

        UTextBlock* NameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        NameText->SetText(Species->DisplayName.IsEmpty() ? FText::FromName(Species->SpeciesKey) : Species->DisplayName);
        NameText->SetJustification(ETextJustify::Center);
        DMFNativeUI::StyleText(NameText, 14, DMFNativeUI::Text(), true);
        NameColumn->AddChildToVerticalBox(NameText);

        UTextBlock* StageText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        StageText->SetText(DMFStarterUI::EnumDisplay(StaticEnum<EDMFDigimonStage>(), static_cast<int64>(Species->Stage)));
        StageText->SetJustification(ETextJustify::Center);
        DMFNativeUI::StyleText(StageText, 10, DMFNativeUI::Gold(), true);
        NameColumn->AddChildToVerticalBox(StageText);

        if (UOverlaySlot* NameStripSlot = CardOverlay->AddChildToOverlay(NameStrip))
        {
            NameStripSlot->SetHorizontalAlignment(HAlign_Fill);
            NameStripSlot->SetVerticalAlignment(VAlign_Bottom);
        }

        if (!PortraitTexture)
        {
            UTextBlock* MissingText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            MissingText->SetText(NSLOCTEXT("DMF", "StarterPortraitMissing", "ASSIGN\nPORTRAIT"));
            MissingText->SetJustification(ETextJustify::Center);
            DMFNativeUI::StyleText(MissingText, 12, DMFNativeUI::Muted(), true);
            if (UOverlaySlot* MissingSlot = CardOverlay->AddChildToOverlay(MissingText))
            {
                MissingSlot->SetHorizontalAlignment(HAlign_Center);
                MissingSlot->SetVerticalAlignment(VAlign_Center);
                MissingSlot->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 35.0f));
            }
        }

        USizeBox* CardSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        CardSize->SetWidthOverride(190.0f);
        CardSize->SetHeightOverride(230.0f);
        CardSize->AddChild(ChoiceButton);

        if (ChoicesGrid)
        {
            const int32 Row = VisualIndex / 3;
            const int32 Column = VisualIndex % 3;
            ChoicesGrid->AddChildToUniformGrid(CardSize, Row, Column);
        }
        else if (ChoicesBox)
        {
            ChoicesBox->AddChildToVerticalBox(ChoiceButton);
        }
        ++VisualIndex;
    }
}

UDMFDigimonSpeciesData* UDMFStarterSelectionWidget::ResolveSpecies(const FPrimaryAssetId SpeciesId) const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UDMFStarterRosterData* Roster = Settings ? Settings->StarterRoster.LoadSynchronous() : nullptr;
    if (!Roster)
    {
        return nullptr;
    }

    for (const FDMFStarterRosterEntry& RosterEntry : Roster->Starters)
    {
        UDMFDigimonSpeciesData* Species = RosterEntry.Species.LoadSynchronous();
        if (Species && Species->GetPrimaryAssetId() == SpeciesId)
        {
            return Species;
        }
    }

    return nullptr;
}

FText UDMFStarterSelectionWidget::ResolveSelectionBlurb(const FPrimaryAssetId SpeciesId) const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UDMFStarterRosterData* Roster = Settings ? Settings->StarterRoster.LoadSynchronous() : nullptr;
    if (!Roster)
    {
        return FText::GetEmpty();
    }

    for (const FDMFStarterRosterEntry& RosterEntry : Roster->Starters)
    {
        UDMFDigimonSpeciesData* Species = RosterEntry.Species.LoadSynchronous();
        if (Species && Species->GetPrimaryAssetId() == SpeciesId)
        {
            return RosterEntry.SelectionBlurb;
        }
    }
    return FText::GetEmpty();
}

void UDMFStarterSelectionWidget::HandleStarterPressed(const FPrimaryAssetId SpeciesId)
{
    SelectedSpeciesId = SpeciesId;
    UDMFDigimonSpeciesData* Species = ResolveSpecies(SpeciesId);
    if (!Species)
    {
        return;
    }

    PopulateChoices();

    if (SelectedStarterPortrait)
    {
        UTexture2D* PortraitTexture = Species->Portrait.LoadSynchronous();
        if (PortraitTexture)
        {
            SelectedStarterPortrait->SetBrushFromTexture(PortraitTexture, true);
            SelectedStarterPortrait->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            SelectedStarterPortrait->SetVisibility(ESlateVisibility::Hidden);
        }
    }

    const FText SpeciesName = Species->DisplayName.IsEmpty() ? FText::FromName(Species->SpeciesKey) : Species->DisplayName;
    if (SelectedStarterNameText)
    {
        SelectedStarterNameText->SetText(SpeciesName);
    }
    if (SelectedStarterMetaText)
    {
        SelectedStarterMetaText->SetText(FText::Format(
            NSLOCTEXT("DMF", "StarterMetaFormat", "{0}  •  {1}  •  Lv.{2}"),
            DMFStarterUI::EnumDisplay(StaticEnum<EDMFDigimonStage>(), static_cast<int64>(Species->Stage)),
            DMFStarterUI::EnumDisplay(StaticEnum<EDMFDigimonAttribute>(), static_cast<int64>(Species->Attribute)),
            FText::AsNumber(Species->StartingLevel)));
    }

    if (DetailsText)
    {
        const FDMFDigimonStats& Stats = Species->BaseStats;
        const FText SelectionBlurb = ResolveSelectionBlurb(SpeciesId);
        const FText DescriptionText = !SelectionBlurb.IsEmpty() ? SelectionBlurb : Species->Description;
        DetailsText->SetText(FText::Format(
            NSLOCTEXT("DMF", "StarterDetailsPolished", "HP     {0}       SP     {1}\nSTR    {2}       INT    {3}\nDEF    {4}       SPD    {5}\n\n{6}"),
            FText::AsNumber(Stats.MaxHP),
            FText::AsNumber(Stats.MaxSP),
            FText::AsNumber(Stats.Strength),
            FText::AsNumber(Stats.Intelligence),
            FText::AsNumber(Stats.Defense),
            FText::AsNumber(Stats.Speed),
            DescriptionText));
    }

    if (StarterStatusText)
    {
        StarterStatusText->SetText(FText::Format(NSLOCTEXT("DMF", "StarterSelectedStatus", "{0} selected. Review the profile, then confirm your partner."), SpeciesName));
        StarterStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Accent()));
    }

    if (ConfirmButton)
    {
        ConfirmButton->SetIsEnabled(true);
    }

    BP_OnStarterPreviewChanged(Species);
}

void UDMFStarterSelectionWidget::HandleConfirm()
{
    if (!SelectedSpeciesId.IsValid())
    {
        return;
    }

    APlayerController* OwningController = GetOwningPlayer();
    ADMFPlayerState* FrameworkPlayerState = OwningController ? OwningController->GetPlayerState<ADMFPlayerState>() : nullptr;
    if (FrameworkPlayerState && FrameworkPlayerState->DigimonComponent)
    {
        if (ConfirmButton)
        {
            ConfirmButton->SetIsEnabled(false);
        }
        if (StarterStatusText)
        {
            StarterStatusText->SetText(NSLOCTEXT("DMF", "StarterSubmitting", "Confirming partner with the server..."));
            StarterStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Gold()));
        }
        FrameworkPlayerState->DigimonComponent->ServerSelectStarter(SelectedSpeciesId);
    }
}

void UDMFStarterSelectionWidget::HandleStarterSelectionResult(const bool bSuccess, const FText Message, const FGuid PartnerInstanceId)
{
    if (StarterStatusText && !Message.IsEmpty())
    {
        StarterStatusText->SetText(Message);
        StarterStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
    else if (DetailsText && !Message.IsEmpty())
    {
        DetailsText->SetText(Message);
    }

    if (!bSuccess && ConfirmButton)
    {
        ConfirmButton->SetIsEnabled(SelectedSpeciesId.IsValid());
    }

}
