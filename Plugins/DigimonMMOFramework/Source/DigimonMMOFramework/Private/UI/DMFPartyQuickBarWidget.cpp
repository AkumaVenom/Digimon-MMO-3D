#include "UI/DMFPartyQuickBarWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/ProgressBar.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Engine/AssetManager.h"
#include "Engine/Texture2D.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFNativeUIStyle.h"

void UDMFPartyQuickSlotButton::ConfigurePartySlot(const int32 InSlotIndex, UDMFPartyQuickBarWidget* InOwnerBar)
{
    SlotIndex = InSlotIndex;
    OwnerBar = InOwnerBar;
    OnClicked.RemoveDynamic(this, &UDMFPartyQuickSlotButton::HandleClicked);
    OnClicked.AddDynamic(this, &UDMFPartyQuickSlotButton::HandleClicked);
}

void UDMFPartyQuickSlotButton::HandleClicked()
{
    if (OwnerBar.IsValid())
    {
        OwnerBar->ExecutePartySlot(SlotIndex);
    }
}

TSharedRef<SWidget> UDMFPartyQuickBarWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFPartyQuickBarWidgetTree"));
    }
    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallback();
    }
    return Super::RebuildWidget();
}

void UDMFPartyQuickBarWidget::NativeConstruct()
{
    Super::NativeConstruct();
    BindDigimonComponent();
    SetInteractionMode(false);
    RefreshParty();
}

void UDMFPartyQuickBarWidget::NativeDestruct()
{
    if (BoundDigimonComponent)
    {
        BoundDigimonComponent->OnDigimonInventoryChanged.RemoveDynamic(this, &UDMFPartyQuickBarWidget::HandlePartyChanged);
        BoundDigimonComponent->OnDigimonStorageActionResult.RemoveDynamic(this, &UDMFPartyQuickBarWidget::HandleStorageResult);
    }
    BoundDigimonComponent = nullptr;
    Super::NativeDestruct();
}

void UDMFPartyQuickBarWidget::BuildNativeFallback()
{
    UOverlay* Root = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("PartyQuickRoot"));
    WidgetTree->RootWidget = Root;

    USizeBox* BarSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("PartyQuickSize"));
    BarSize->SetWidthOverride(790.0f);
    if (UOverlaySlot* RootSlot = Root->AddChildToOverlay(BarSize))
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        const float BottomOffset = Settings ? FMath::Max(0.0f, Settings->PartyQuickBarBottomSafeOffset) : 176.0f;
        RootSlot->SetHorizontalAlignment(HAlign_Right);
        RootSlot->SetVerticalAlignment(VAlign_Bottom);
        RootSlot->SetPadding(FMargin(18.0f, 18.0f, 26.0f, BottomOffset));
    }

    UBorder* BarBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("PartyQuickBorder"));
    DMFNativeUI::StylePanel(BarBorder, FLinearColor(0.008f, 0.025f, 0.050f, 0.95f), FMargin(10.0f));
    BarSize->AddChild(BarBorder);

    UVerticalBox* Column = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("PartyQuickColumn"));
    BarBorder->AddChild(Column);

    UHorizontalBox* Header = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("PartyQuickHeader"));
    Column->AddChildToVerticalBox(Header)->SetPadding(FMargin(2.0f, 0.0f, 2.0f, 6.0f));

    UTextBlock* Title = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PartyQuickTitle"));
    Title->SetText(NSLOCTEXT("DMF", "PartyQuickTitle", "PARTY QUICK ACCESS"));
    DMFNativeUI::StyleText(Title, 12, DMFNativeUI::Accent(), true);
    if (UHorizontalBoxSlot* TitleSlot = Header->AddChildToHorizontalBox(Title))
    {
        TitleSlot->SetSize(DMFNativeUI::FillSize());
        TitleSlot->SetVerticalAlignment(VAlign_Center);
    }

    PartyStatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PartyStatusText"));
    PartyStatusText->SetText(NSLOCTEXT("DMF", "PartyQuickHint", "TAB  •  INTERACT"));
    DMFNativeUI::StyleText(PartyStatusText, 10, DMFNativeUI::Muted(), true);
    Header->AddChildToHorizontalBox(PartyStatusText)->SetVerticalAlignment(VAlign_Center);

    PartySlotsBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("PartySlotsBox"));
    Column->AddChildToVerticalBox(PartySlotsBox);

    NativePortraits.Reset();
    NativeLabels.Reset();
    NativeHealthBars.Reset();
    NativeSlotButtons.Reset();

    for (int32 Index = 0; Index < 6; ++Index)
    {
        USizeBox* SlotSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        SlotSize->SetWidthOverride(120.0f);
        SlotSize->SetHeightOverride(112.0f);

        UDMFPartyQuickSlotButton* Button = WidgetTree->ConstructWidget<UDMFPartyQuickSlotButton>(UDMFPartyQuickSlotButton::StaticClass());
        Button->ConfigurePartySlot(Index, this);
        DMFNativeUI::StyleCompactButton(Button);
        SlotSize->AddChild(Button);
        NativeSlotButtons.Add(Button);

        UVerticalBox* SlotColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
        Button->AddChild(SlotColumn);

        USizeBox* PortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        PortraitSize->SetWidthOverride(44.0f);
        PortraitSize->SetHeightOverride(44.0f);
        if (UVerticalBoxSlot* PortraitLayoutSlot = SlotColumn->AddChildToVerticalBox(PortraitSize))
        {
            PortraitLayoutSlot->SetHorizontalAlignment(HAlign_Center);
            PortraitLayoutSlot->SetPadding(FMargin(0.0f, 1.0f, 0.0f, 2.0f));
        }
        UImage* Portrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
        Portrait->SetColorAndOpacity(FLinearColor(1,1,1,0));
        PortraitSize->AddChild(Portrait);
        NativePortraits.Add(Portrait);

        UTextBlock* Label = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        Label->SetText(FText::Format(NSLOCTEXT("DMF", "PartyQuickEmpty", "[{0}]  EMPTY"), FText::AsNumber(Index + 1)));
        Label->SetAutoWrapText(true);
        Label->SetJustification(ETextJustify::Center);
        DMFNativeUI::StyleText(Label, 9, DMFNativeUI::Muted(), true);
        if (UVerticalBoxSlot* LabelSlot = SlotColumn->AddChildToVerticalBox(Label))
        {
            LabelSlot->SetSize(DMFNativeUI::FillSize());
            LabelSlot->SetVerticalAlignment(VAlign_Center);
            LabelSlot->SetPadding(FMargin(2.0f, 0.0f));
        }
        NativeLabels.Add(Label);

        UProgressBar* Health = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass());
        Health->SetPercent(0.0f);
        Health->SetFillColorAndOpacity(DMFNativeUI::Success());
        SlotColumn->AddChildToVerticalBox(Health)->SetPadding(FMargin(2.0f, 3.0f, 2.0f, 0.0f));
        NativeHealthBars.Add(Health);

        if (UHorizontalBoxSlot* PartySlot = PartySlotsBox->AddChildToHorizontalBox(SlotSize))
        {
            PartySlot->SetSize(DMFNativeUI::FillSize());
            PartySlot->SetPadding(FMargin(3.0f, 0.0f));
        }
    }

    PartyActionRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("PartyActionRow"));
    Column->AddChildToVerticalBox(PartyActionRow)->SetPadding(FMargin(2.0f, 7.0f, 2.0f, 0.0f));

    UButton* RecallButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PartyQuickRecall"));
    DMFNativeUI::StyleButton(RecallButton);
    UTextBlock* RecallText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
    RecallText->SetText(NSLOCTEXT("DMF", "PartyQuickRecall", "RECALL"));
    RecallText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(RecallText, 10, DMFNativeUI::Text(), true);
    RecallButton->AddChild(RecallText);
    RecallButton->OnClicked.AddUniqueDynamic(this, &UDMFPartyQuickBarWidget::HandleRecallClicked);
    if (UHorizontalBoxSlot* RecallActionSlot = PartyActionRow->AddChildToHorizontalBox(RecallButton)) { RecallActionSlot->SetSize(DMFNativeUI::FillSize()); RecallActionSlot->SetPadding(FMargin(3.0f,0.0f)); }

    UButton* PartyButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PartyQuickOpenParty"));
    DMFNativeUI::StyleButton(PartyButton, true);
    UTextBlock* PartyText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
    PartyText->SetText(NSLOCTEXT("DMF", "PartyQuickOpenParty", "OPEN PARTY"));
    PartyText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(PartyText, 10, DMFNativeUI::Text(), true);
    PartyButton->AddChild(PartyText);
    PartyButton->OnClicked.AddUniqueDynamic(this, &UDMFPartyQuickBarWidget::HandleOpenPartyClicked);
    if (UHorizontalBoxSlot* PartyActionSlot = PartyActionRow->AddChildToHorizontalBox(PartyButton)) { PartyActionSlot->SetSize(DMFNativeUI::FillSize()); PartyActionSlot->SetPadding(FMargin(3.0f,0.0f)); }

    UButton* BankButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PartyQuickOpenBank"));
    DMFNativeUI::StyleButton(BankButton);
    UTextBlock* BankText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
    BankText->SetText(NSLOCTEXT("DMF", "PartyQuickOpenBank", "OPEN BANK"));
    BankText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(BankText, 10, DMFNativeUI::Text(), true);
    BankButton->AddChild(BankText);
    BankButton->OnClicked.AddUniqueDynamic(this, &UDMFPartyQuickBarWidget::HandleOpenBankClicked);
    if (UHorizontalBoxSlot* BankActionSlot = PartyActionRow->AddChildToHorizontalBox(BankButton)) { BankActionSlot->SetSize(DMFNativeUI::FillSize()); BankActionSlot->SetPadding(FMargin(3.0f,0.0f)); }

}

void UDMFPartyQuickBarWidget::BindDigimonComponent()
{
    APlayerController* PC = GetOwningPlayer();
    ADMFPlayerState* PS = PC ? PC->GetPlayerState<ADMFPlayerState>() : nullptr;
    UDMFPlayerDigimonComponent* NewComponent = PS ? PS->DigimonComponent : nullptr;
    if (NewComponent == BoundDigimonComponent)
    {
        return;
    }
    if (BoundDigimonComponent)
    {
        BoundDigimonComponent->OnDigimonInventoryChanged.RemoveDynamic(this, &UDMFPartyQuickBarWidget::HandlePartyChanged);
        BoundDigimonComponent->OnDigimonStorageActionResult.RemoveDynamic(this, &UDMFPartyQuickBarWidget::HandleStorageResult);
    }
    BoundDigimonComponent = NewComponent;
    if (BoundDigimonComponent)
    {
        BoundDigimonComponent->OnDigimonInventoryChanged.AddUniqueDynamic(this, &UDMFPartyQuickBarWidget::HandlePartyChanged);
        BoundDigimonComponent->OnDigimonStorageActionResult.AddUniqueDynamic(this, &UDMFPartyQuickBarWidget::HandleStorageResult);
    }
}

void UDMFPartyQuickBarWidget::RefreshParty()
{
    BindDigimonComponent();
    if (!BoundDigimonComponent)
    {
        return;
    }

    const TArray<FDMFDigimonInstance> Party = BoundDigimonComponent->GetPartyDigimon();
    const FGuid ActiveId = BoundDigimonComponent->GetActivePartnerInstanceId();
    const bool bSummoned = BoundDigimonComponent->IsActivePartnerSummoned();
    UAssetManager& AssetManager = UAssetManager::Get();

    for (int32 Index = 0; Index < NativeSlotButtons.Num(); ++Index)
    {
        const bool bHasDigimon = Party.IsValidIndex(Index) && Party[Index].IsValid();
        UDMFPartyQuickSlotButton* Button = NativeSlotButtons[Index];
        UImage* Portrait = NativePortraits.IsValidIndex(Index) ? NativePortraits[Index] : nullptr;
        UTextBlock* Label = NativeLabels.IsValidIndex(Index) ? NativeLabels[Index] : nullptr;
        UProgressBar* Health = NativeHealthBars.IsValidIndex(Index) ? NativeHealthBars[Index] : nullptr;

        if (!bHasDigimon)
        {
            if (Button) { Button->SetIsEnabled(false); DMFNativeUI::StyleButton(Button); }
            if (Portrait) Portrait->SetColorAndOpacity(FLinearColor(1,1,1,0));
            if (Label) { Label->SetText(FText::Format(NSLOCTEXT("DMF", "PartyQuickEmpty", "[{0}]  EMPTY"), FText::AsNumber(Index + 1))); Label->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted())); }
            if (Health) Health->SetPercent(0.0f);
            continue;
        }

        const FDMFDigimonInstance& Digimon = Party[Index];
        UDMFDigimonSpeciesData* Species = AssetManager.GetPrimaryAssetObject<UDMFDigimonSpeciesData>(Digimon.SpeciesId);
        if (!Species)
        {
            const FSoftObjectPath Path = AssetManager.GetPrimaryAssetPath(Digimon.SpeciesId);
            Species = Path.IsValid() ? Cast<UDMFDigimonSpeciesData>(Path.TryLoad()) : nullptr;
        }
        const FText DisplayName = !Digimon.Nickname.IsEmpty() ? FText::FromString(Digimon.Nickname)
            : (Species && !Species->DisplayName.IsEmpty() ? Species->DisplayName : FText::FromName(Digimon.SpeciesId.PrimaryAssetName));
        const bool bActive = Digimon.InstanceId == ActiveId;
        const bool bDefeated = Digimon.CurrentHP <= 0;

        if (Button)
        {
            Button->SetIsEnabled(bInteractionMode && !bDefeated);
            DMFNativeUI::StyleButton(Button, bActive, false, bActive);
        }
        if (Portrait)
        {
            UTexture2D* Texture = Species ? Species->Portrait.LoadSynchronous() : nullptr;
            if (Texture)
            {
                Portrait->SetBrushFromTexture(Texture, true);
                Portrait->SetColorAndOpacity(bDefeated ? FLinearColor(0.45f,0.45f,0.45f,1.0f) : FLinearColor::White);
            }
            else
            {
                Portrait->SetColorAndOpacity(FLinearColor(1,1,1,0));
            }
        }
        if (Label)
        {
            const FText State = bDefeated ? NSLOCTEXT("DMF", "PartyQuickKO", "KO")
                : (bActive ? (bSummoned ? NSLOCTEXT("DMF", "PartyQuickActiveSummoned", "ACTIVE") : NSLOCTEXT("DMF", "PartyQuickActiveRecalled", "ACTIVE*")) : FText::GetEmpty());
            Label->SetText(FText::Format(NSLOCTEXT("DMF", "PartyQuickSlotFormat", "[{0}]  {1}\n{2}  •  Lv.{3}"), FText::AsNumber(Index + 1), State, DisplayName, FText::AsNumber(Digimon.Stats.Level)));
            Label->SetColorAndOpacity(FSlateColor(bActive ? DMFNativeUI::Gold() : (bDefeated ? DMFNativeUI::Danger() : DMFNativeUI::Text())));
        }
        if (Health)
        {
            const float MaxHP = static_cast<float>(FMath::Max(1, Digimon.Stats.MaxHP));
            Health->SetPercent(FMath::Clamp(static_cast<float>(Digimon.CurrentHP) / MaxHP, 0.0f, 1.0f));
            Health->SetFillColorAndOpacity(bDefeated ? DMFNativeUI::Danger() : DMFNativeUI::Success());
        }
    }

    if (PartyStatusText)
    {
        PartyStatusText->SetText(bInteractionMode
            ? NSLOCTEXT("DMF", "PartyQuickInteractive", "CLICK SLOT TO SWITCH  •  TAB / ESC CLOSE")
            : NSLOCTEXT("DMF", "PartyQuickHint", "TAB  •  INTERACT"));
        PartyStatusText->SetColorAndOpacity(FSlateColor(bInteractionMode ? DMFNativeUI::Gold() : DMFNativeUI::Muted()));
    }
    BP_OnPartyQuickBarRefreshed();
}

void UDMFPartyQuickBarWidget::SetInteractionMode(const bool bEnabled)
{
    bInteractionMode = bEnabled;
    SetVisibility(bInteractionMode ? ESlateVisibility::Visible : ESlateVisibility::HitTestInvisible);
    if (PartyActionRow)
    {
        PartyActionRow->SetVisibility(bInteractionMode ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
    RefreshParty();
}

void UDMFPartyQuickBarWidget::ExecutePartySlot(const int32 SlotIndex)
{
    if (!bInteractionMode || !BoundDigimonComponent)
    {
        return;
    }
    const TArray<FDMFDigimonInstance> Party = BoundDigimonComponent->GetPartyDigimon();
    if (Party.IsValidIndex(SlotIndex) && Party[SlotIndex].IsValid() && Party[SlotIndex].CurrentHP > 0)
    {
        BoundDigimonComponent->ServerSetActivePartner(Party[SlotIndex].InstanceId, true);
    }
}

void UDMFPartyQuickBarWidget::HandlePartyChanged()
{
    RefreshParty();
}

void UDMFPartyQuickBarWidget::HandleStorageResult(const bool bSuccess, const FText Message, const FGuid DigimonInstanceId, const EDMFDigimonStorageLocation NewLocation)
{
    RefreshParty();
    if (PartyStatusText && !Message.IsEmpty())
    {
        PartyStatusText->SetText(Message);
        PartyStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
}

void UDMFPartyQuickBarWidget::HandleRecallClicked()
{
    if (BoundDigimonComponent)
    {
        BoundDigimonComponent->ServerRecallActivePartner();
    }
}

void UDMFPartyQuickBarWidget::HandleOpenPartyClicked()
{
    if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        PC->ClosePartyQuickAccessInteraction();
        PC->OpenPartyUI();
    }
}

void UDMFPartyQuickBarWidget::HandleOpenBankClicked()
{
    if (ADMFMMOPlayerController* PC = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        PC->ClosePartyQuickAccessInteraction();
        PC->OpenBankUI();
    }
}
