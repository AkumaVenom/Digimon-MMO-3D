#include "UI/DMFCombatQuickBarWidget.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFPlayerState.h"
#include "Game/DMFDayNightSky.h"
#include "Settings/DMFFrameworkSettings.h"
#include "Data/DMFDigimonAbilityData.h"
#include "Components/Border.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Blueprint/WidgetTree.h"
#include "Engine/Texture2D.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "UI/DMFNativeUIStyle.h"

void UDMFCombatQuickSlotButton::ConfigureSlot(const int32 InSlotIndex, UDMFCombatQuickBarWidget* InOwnerBar)
{
    SlotIndex = InSlotIndex;
    OwnerBar = InOwnerBar;
    OnClicked.RemoveDynamic(this, &UDMFCombatQuickSlotButton::HandleClicked);
    OnClicked.AddDynamic(this, &UDMFCombatQuickSlotButton::HandleClicked);
}

void UDMFCombatQuickSlotButton::SynchronizeProperties()
{
    Super::SynchronizeProperties();
    OnClicked.RemoveDynamic(this, &UDMFCombatQuickSlotButton::HandleClicked);
    OnClicked.AddDynamic(this, &UDMFCombatQuickSlotButton::HandleClicked);
}

void UDMFCombatQuickSlotButton::HandleClicked()
{
    if (OwnerBar.IsValid())
    {
        OwnerBar->ExecuteAbilitySlot(SlotIndex);
    }
}

TSharedRef<SWidget> UDMFCombatQuickBarWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFCombatQuickBarWidgetTree"));
    }

    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallback();
    }

    return Super::RebuildWidget();
}

void UDMFCombatQuickBarWidget::NativeConstruct()
{
    Super::NativeConstruct();
    BoundDigimonComponent = ResolveDigimonComponent();
    RefreshFromPartner();
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().SetTimer(RefreshTimer, this, &UDMFCombatQuickBarWidget::RefreshFromPartner, 0.15f, true, 0.15f);
    }
}

void UDMFCombatQuickBarWidget::NativeDestruct()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(RefreshTimer);
    }
    Super::NativeDestruct();
}

void UDMFCombatQuickBarWidget::BuildNativeFallback()
{
    if (!WidgetTree)
    {
        return;
    }

    UOverlay* RootOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("DMFCombatRoot"));
    RootOverlay->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    WidgetTree->RootWidget = RootOverlay;

    USizeBox* BarSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("CombatBarSize"));
    BarSize->SetWidthOverride(960.0f);
    BarSize->SetHeightOverride(140.0f);
    if (UOverlaySlot* BarRootSlot = RootOverlay->AddChildToOverlay(BarSize))
    {
        BarRootSlot->SetHorizontalAlignment(HAlign_Center);
        BarRootSlot->SetVerticalAlignment(VAlign_Bottom);
        BarRootSlot->SetPadding(FMargin(18.0f, 18.0f, 18.0f, 26.0f));
    }

    UBorder* BarBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("CombatBarBorder"));
    DMFNativeUI::StylePanel(BarBorder, FLinearColor(0.008f, 0.025f, 0.050f, 0.94f), FMargin(10.0f));
    BarSize->AddChild(BarBorder);

    UVerticalBox* BarColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("CombatBarColumn"));
    BarBorder->AddChild(BarColumn);

    UHorizontalBox* InfoRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("CombatInfoRow"));
    BarColumn->AddChildToVerticalBox(InfoRow)->SetPadding(FMargin(3.0f, 0.0f, 3.0f, 6.0f));

    VitalsText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("VitalsText"));
    VitalsText->SetText(NSLOCTEXT("DMF", "CombatVitalsWaiting", "PARTNER  •  combat initializing..."));
    DMFNativeUI::StyleText(VitalsText, 14, DMFNativeUI::Text(), true);
    if (UHorizontalBoxSlot* VitalsSlot = InfoRow->AddChildToHorizontalBox(VitalsText))
    {
        VitalsSlot->SetSize(DMFNativeUI::FillSize());
        VitalsSlot->SetVerticalAlignment(VAlign_Center);
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    USizeBox* ClockSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("WorldClockContainer"));
    ClockSize->SetWidthOverride(168.0f);
    ClockSize->SetHeightOverride(28.0f);
    ClockSize->SetVisibility(!Settings || Settings->bShowCombatQuickBarWorldClock ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
    NativeWorldClockContainer = ClockSize;
    if (UHorizontalBoxSlot* ClockRowSlot = InfoRow->AddChildToHorizontalBox(ClockSize))
    {
        ClockRowSlot->SetHorizontalAlignment(HAlign_Center);
        ClockRowSlot->SetVerticalAlignment(VAlign_Center);
        ClockRowSlot->SetPadding(FMargin(10.0f, 0.0f));
    }

    UBorder* ClockBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("WorldClockBorder"));
    DMFNativeUI::StylePanel(ClockBorder, FLinearColor(0.018f, 0.050f, 0.090f, 0.98f), FMargin(8.0f, 3.0f));
    ClockSize->AddChild(ClockBorder);

    UHorizontalBox* ClockRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("WorldClockRow"));
    ClockBorder->AddChild(ClockRow);

    WorldClockText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("WorldClockText"));
    WorldClockText->SetText(NSLOCTEXT("DMF", "WorldClockSyncing", "--:-- --"));
    WorldClockText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(WorldClockText, 13, DMFNativeUI::Text(), true);
    if (UHorizontalBoxSlot* ClockTimeSlot = ClockRow->AddChildToHorizontalBox(WorldClockText))
    {
        ClockTimeSlot->SetSize(DMFNativeUI::FillSize());
        ClockTimeSlot->SetVerticalAlignment(VAlign_Center);
    }

    WorldClockPhaseText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("WorldClockPhaseText"));
    WorldClockPhaseText->SetText(NSLOCTEXT("DMF", "WorldClockPhaseSyncing", "SYNC"));
    WorldClockPhaseText->SetJustification(ETextJustify::Right);
    WorldClockPhaseText->SetVisibility(!Settings || Settings->bShowCombatQuickBarWorldClockPhase ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
    DMFNativeUI::StyleText(WorldClockPhaseText, 9, DMFNativeUI::Muted(), true);
    if (UHorizontalBoxSlot* ClockPhaseSlot = ClockRow->AddChildToHorizontalBox(WorldClockPhaseText))
    {
        ClockPhaseSlot->SetVerticalAlignment(VAlign_Center);
        ClockPhaseSlot->SetPadding(FMargin(6.0f, 0.0f, 0.0f, 0.0f));
    }

    TargetText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TargetText"));
    TargetText->SetText(NSLOCTEXT("DMF", "NoCombatTargetPolished", "TARGET  •  NONE"));
    TargetText->SetJustification(ETextJustify::Right);
    DMFNativeUI::StyleText(TargetText, 13, DMFNativeUI::Muted(), true);
    if (UHorizontalBoxSlot* TargetInfoSlot = InfoRow->AddChildToHorizontalBox(TargetText))
    {
        TargetInfoSlot->SetHorizontalAlignment(HAlign_Right);
        TargetInfoSlot->SetVerticalAlignment(VAlign_Center);
    }

    AbilityBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("AbilityBox"));
    if (UVerticalBoxSlot* AbilityRowSlot = BarColumn->AddChildToVerticalBox(AbilityBox))
    {
        AbilityRowSlot->SetSize(DMFNativeUI::FillSize());
    }

    NativeSlotLabels.Reset();
    NativeSlotIcons.Reset();
    NativeSlotIconContainers.Reset();
    for (int32 Index = 0; Index < 4; ++Index)
    {
        USizeBox* SlotSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        SlotSize->SetWidthOverride(224.0f);
        SlotSize->SetHeightOverride(82.0f);

        UDMFCombatQuickSlotButton* AbilityButton = WidgetTree->ConstructWidget<UDMFCombatQuickSlotButton>(UDMFCombatQuickSlotButton::StaticClass());
        AbilityButton->ConfigureSlot(Index, this);
        DMFNativeUI::StyleCompactButton(AbilityButton, Index == 0);
        SlotSize->AddChild(AbilityButton);

        UHorizontalBox* AbilityContent = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
        AbilityButton->AddChild(AbilityContent);

        USizeBox* IconSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        IconSize->SetWidthOverride(52.0f);
        IconSize->SetHeightOverride(52.0f);
        IconSize->SetVisibility(ESlateVisibility::Collapsed);
        AbilityContent->AddChildToHorizontalBox(IconSize)->SetVerticalAlignment(VAlign_Center);
        NativeSlotIconContainers.Add(IconSize);

        UBorder* IconBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(IconBorder, DMFNativeUI::SlotEmpty(), FMargin(3.0f));
        IconSize->AddChild(IconBorder);

        UImage* AbilityIcon = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
        AbilityIcon->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.0f));
        IconBorder->AddChild(AbilityIcon);
        NativeSlotIcons.Add(AbilityIcon);

        UTextBlock* SlotLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        SlotLabel->SetText(FText::Format(NSLOCTEXT("DMF", "EmptyAbilitySlotPolished", "[{0}]  EMPTY"), FText::AsNumber(Index + 1)));
        SlotLabel->SetAutoWrapText(true);
        DMFNativeUI::StyleText(SlotLabel, 11, DMFNativeUI::Text(), true);
        if (UHorizontalBoxSlot* LabelSlot = AbilityContent->AddChildToHorizontalBox(SlotLabel))
        {
            LabelSlot->SetSize(DMFNativeUI::FillSize());
            LabelSlot->SetVerticalAlignment(VAlign_Center);
            LabelSlot->SetPadding(FMargin(8.0f, 0.0f));
        }
        NativeSlotLabels.Add(SlotLabel);

        if (UHorizontalBoxSlot* AbilitySlot = AbilityBox->AddChildToHorizontalBox(SlotSize))
        {
            AbilitySlot->SetSize(DMFNativeUI::FillSize());
            AbilitySlot->SetPadding(FMargin(4.0f, 0.0f));
        }
    }
}

ADMFDayNightSky* UDMFCombatQuickBarWidget::ResolveDayNightSky()
{
    if (BoundDayNightSky.IsValid())
    {
        return BoundDayNightSky.Get();
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        return nullptr;
    }

    const double WorldSeconds = static_cast<double>(World->GetTimeSeconds());
    if (WorldSeconds < NextDayNightSkyResolveAttemptSeconds)
    {
        return nullptr;
    }
    NextDayNightSkyResolveAttemptSeconds = WorldSeconds + 1.0;

    for (TActorIterator<ADMFDayNightSky> It(World); It; ++It)
    {
        if (IsValid(*It))
        {
            BoundDayNightSky = *It;
            return *It;
        }
    }
    return nullptr;
}

void UDMFCombatQuickBarWidget::RefreshWorldClock()
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bShowClock = !Settings || Settings->bShowCombatQuickBarWorldClock;
    if (USizeBox* ClockContainer = NativeWorldClockContainer.Get())
    {
        ClockContainer->SetVisibility(bShowClock ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
    }
    if (WorldClockText)
    {
        WorldClockText->SetVisibility(bShowClock ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
    }
    if (WorldClockPhaseText && !bShowClock)
    {
        WorldClockPhaseText->SetVisibility(ESlateVisibility::Collapsed);
    }
    if (!bShowClock)
    {
        return;
    }

    ADMFDayNightSky* Sky = ResolveDayNightSky();
    if (!Sky)
    {
        if (WorldClockText)
        {
            WorldClockText->SetText(NSLOCTEXT("DMF", "WorldClockSyncing", "--:-- --"));
            WorldClockText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));
        }
        if (WorldClockPhaseText)
        {
            WorldClockPhaseText->SetVisibility(Settings && !Settings->bShowCombatQuickBarWorldClockPhase ? ESlateVisibility::Collapsed : ESlateVisibility::SelfHitTestInvisible);
            WorldClockPhaseText->SetText(NSLOCTEXT("DMF", "WorldClockPhaseSyncing", "SYNC"));
            WorldClockPhaseText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));
        }
        return;
    }

    if (WorldClockText)
    {
        WorldClockText->SetText(Sky->GetFormattedTime12Hour(false));
        WorldClockText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Text()));
    }

    if (WorldClockPhaseText)
    {
        const bool bShowPhase = !Settings || Settings->bShowCombatQuickBarWorldClockPhase;
        WorldClockPhaseText->SetVisibility(bShowPhase ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
        if (bShowPhase)
        {
            const bool bDay = Sky->GetDayNightPhase() == EDMFDayNightPhase::Day;
            WorldClockPhaseText->SetText(bDay
                ? NSLOCTEXT("DMF", "WorldClockDay", "DAY")
                : NSLOCTEXT("DMF", "WorldClockNight", "NIGHT"));
            WorldClockPhaseText->SetColorAndOpacity(FSlateColor(bDay ? DMFNativeUI::Gold() : DMFNativeUI::Accent()));
        }
    }
}

UDMFPlayerDigimonComponent* UDMFCombatQuickBarWidget::ResolveDigimonComponent() const
{
    APlayerController* OwningController = GetOwningPlayer();
    ADMFPlayerState* FrameworkPlayerState = OwningController ? OwningController->GetPlayerState<ADMFPlayerState>() : nullptr;
    return FrameworkPlayerState ? FrameworkPlayerState->DigimonComponent : nullptr;
}

void UDMFCombatQuickBarWidget::RefreshFromPartner()
{
    // World time is independent of partner availability and comes exclusively from the replicated Day/Night sky.
    RefreshWorldClock();

    if (!BoundDigimonComponent)
    {
        BoundDigimonComponent = ResolveDigimonComponent();
    }
    if (!BoundDigimonComponent)
    {
        return;
    }

    ADMFDigimonCharacter* Partner = BoundDigimonComponent->ActivePartnerActor;
    ADMFDigimonCharacter* CommandTarget = BoundDigimonComponent->GetCommandTarget();
    if (!CommandTarget && Partner && Partner->CombatComponent)
    {
        CommandTarget = Partner->CombatComponent->GetCurrentTarget();
    }
    if (TargetText)
    {
        TargetText->SetText(CommandTarget
            ? FText::Format(NSLOCTEXT("DMF", "CombatTargetFormatPolished", "TARGET  •  {0}"), FText::FromName(CommandTarget->SpeciesId.PrimaryAssetName))
            : NSLOCTEXT("DMF", "NoCombatTargetPolished", "TARGET  •  NONE"));
        TargetText->SetColorAndOpacity(FSlateColor(CommandTarget ? DMFNativeUI::Gold() : DMFNativeUI::Muted()));
    }

    if (Partner && Partner->CombatComponent)
    {
        if (VitalsText)
        {
            VitalsText->SetText(FText::Format(
                NSLOCTEXT("DMF", "CombatVitalsFormatPolished", "PARTNER  •  HP {0}/{1}    SP {2}/{3}"),
                FText::AsNumber(Partner->CombatComponent->GetCurrentHP()),
                FText::AsNumber(Partner->ReplicatedStats.MaxHP),
                FText::AsNumber(Partner->CombatComponent->GetCurrentSP()),
                FText::AsNumber(Partner->ReplicatedStats.MaxSP)));
        }
        for (int32 Index = 0; Index < NativeSlotLabels.Num(); ++Index)
        {
            UTextBlock* SlotLabel = NativeSlotLabels[Index];
            UImage* AbilityIcon = NativeSlotIcons.IsValidIndex(Index) ? NativeSlotIcons[Index] : nullptr;
            USizeBox* AbilityIconContainer = NativeSlotIconContainers.IsValidIndex(Index) ? NativeSlotIconContainers[Index].Get() : nullptr;
            if (!SlotLabel)
            {
                continue;
            }
            if (!Partner->ReplicatedAbilityIds.IsValidIndex(Index))
            {
                SlotLabel->SetText(FText::Format(NSLOCTEXT("DMF", "EmptyAbilitySlotPolished", "[{0}]  EMPTY"), FText::AsNumber(Index + 1)));
                SlotLabel->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));
                if (AbilityIcon)
                {
                    AbilityIcon->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.0f));
                }
                if (AbilityIconContainer)
                {
                    AbilityIconContainer->SetVisibility(ESlateVisibility::Collapsed);
                }
                continue;
            }

            const FName AbilityId = Partner->ReplicatedAbilityIds[Index];
            UDMFDigimonAbilityData* Ability = Partner->CombatComponent->ResolveAbilityData(AbilityId);
            const FText AbilityName = Ability && !Ability->DisplayName.IsEmpty() ? Ability->DisplayName : FText::FromName(AbilityId);
            const float Remaining = Partner->CombatComponent->GetRemainingCooldown(AbilityId);
            SlotLabel->SetText(Remaining > 0.01f
                ? FText::Format(NSLOCTEXT("DMF", "AbilityCooldownFormatPolished", "[{0}]  {1}\nSP {2}  •  {3}s"), FText::AsNumber(Index + 1), AbilityName, FText::AsNumber(Ability ? Ability->SPCost : 0), FText::AsNumber(FMath::CeilToInt(Remaining * 10.0f) / 10.0f))
                : FText::Format(NSLOCTEXT("DMF", "AbilityReadyFormatPolished", "[{0}]  {1}\nSP {2}  •  READY"), FText::AsNumber(Index + 1), AbilityName, FText::AsNumber(Ability ? Ability->SPCost : 0)));
            SlotLabel->SetColorAndOpacity(FSlateColor(Remaining > 0.01f ? DMFNativeUI::Muted() : DMFNativeUI::Text()));

            if (AbilityIcon)
            {
                UTexture2D* IconTexture = Ability ? Ability->Icon.LoadSynchronous() : nullptr;
                if (IconTexture)
                {
                    AbilityIcon->SetBrushFromTexture(IconTexture, true);
                    AbilityIcon->SetColorAndOpacity(Remaining > 0.01f ? FLinearColor(0.45f, 0.45f, 0.45f, 1.0f) : FLinearColor::White);
                    if (AbilityIconContainer)
                    {
                        AbilityIconContainer->SetVisibility(ESlateVisibility::Visible);
                    }
                }
                else
                {
                    AbilityIcon->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.0f));
                    if (AbilityIconContainer)
                    {
                        AbilityIconContainer->SetVisibility(ESlateVisibility::Collapsed);
                    }
                }
            }
        }
    }
    else
    {
        if (VitalsText)
        {
            VitalsText->SetText(NSLOCTEXT("DMF", "NoPartnerCombatVitals", "PARTNER  •  NOT SUMMONED"));
            VitalsText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Muted()));
        }
    }
    BP_OnQuickBarRefreshed();
}

void UDMFCombatQuickBarWidget::ExecuteAbilitySlot(const int32 SlotIndex)
{
    if (!BoundDigimonComponent)
    {
        BoundDigimonComponent = ResolveDigimonComponent();
    }
    if (BoundDigimonComponent)
    {
        BoundDigimonComponent->ServerCommandActivePartnerAbilitySlot(SlotIndex, BoundDigimonComponent->GetCommandTarget());
    }
}
