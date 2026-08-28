#include "UI/DMFExperienceNotificationWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
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
#include "Progression/DMFLevelProgressionMath.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Engine/AssetManager.h"
#include "Engine/Texture2D.h"
#include "Settings/DMFFrameworkSettings.h"
#include "TimerManager.h"
#include "UI/DMFNativeUIStyle.h"

TSharedRef<SWidget> UDMFExperienceNotificationWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFExperienceNotificationTree"));
    }
    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }
    return Super::RebuildWidget();
}

void UDMFExperienceNotificationWidget::NativeDestruct()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(AnimationTimer);
        World->GetTimerManager().ClearTimer(HideTimer);
    }
    PendingPresentations.Reset();
    bPresentationActive = false;
    Super::NativeDestruct();
}

void UDMFExperienceNotificationWidget::BuildNativeFallbackUI()
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const float BottomOffset = Settings ? FMath::Max(0.0f, Settings->ExperienceNotificationBottomSafeOffset) : 280.0f;

    UOverlay* Root = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("ExperienceToastRoot"));
    WidgetTree->RootWidget = Root;

    USizeBox* Size = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("ExperienceToastSize"));
    Size->SetWidthOverride(560.0f);
    Size->SetHeightOverride(142.0f);
    if (UOverlaySlot* RootSlot = Root->AddChildToOverlay(Size))
    {
        RootSlot->SetHorizontalAlignment(HAlign_Center);
        RootSlot->SetVerticalAlignment(VAlign_Bottom);
        RootSlot->SetPadding(FMargin(16.0f, 0.0f, 16.0f, BottomOffset));
    }

    UBorder* Panel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ExperienceToastPanel"));
    DMFNativeUI::StylePanel(Panel, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    Size->AddChild(Panel);

    UHorizontalBox* Row = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ExperienceToastRow"));
    Panel->AddChild(Row);

    USizeBox* PortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("ExperiencePortraitSize"));
    PortraitSize->SetWidthOverride(92.0f);
    PortraitSize->SetHeightOverride(92.0f);
    SpeciesPortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("SpeciesPortraitImage"));
    PortraitSize->AddChild(SpeciesPortraitImage);
    Row->AddChildToHorizontalBox(PortraitSize)->SetPadding(FMargin(0.0f, 0.0f, 14.0f, 0.0f));

    UVerticalBox* Column = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("ExperienceToastColumn"));
    Row->AddChildToHorizontalBox(Column)->SetSize(DMFNativeUI::FillSize());

    UHorizontalBox* HeaderRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ExperienceHeaderRow"));
    Column->AddChildToVerticalBox(HeaderRow);

    SpeciesNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SpeciesNameText"));
    DMFNativeUI::StyleText(SpeciesNameText, 18, DMFNativeUI::Text(), true);
    HeaderRow->AddChildToHorizontalBox(SpeciesNameText)->SetSize(DMFNativeUI::FillSize());

    ExperienceGainText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ExperienceGainText"));
    ExperienceGainText->SetJustification(ETextJustify::Right);
    DMFNativeUI::StyleText(ExperienceGainText, 18, DMFNativeUI::Accent(), true);
    HeaderRow->AddChildToHorizontalBox(ExperienceGainText);

    LevelText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("LevelText"));
    DMFNativeUI::StyleText(LevelText, 13, DMFNativeUI::Muted(), true);
    Column->AddChildToVerticalBox(LevelText)->SetPadding(FMargin(0.0f, 1.0f, 0.0f, 4.0f));

    ExperienceProgressBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("ExperienceProgressBar"));
    ExperienceProgressBar->SetFillColorAndOpacity(DMFNativeUI::Accent());
    Column->AddChildToVerticalBox(ExperienceProgressBar)->SetPadding(FMargin(0.0f, 2.0f, 0.0f, 2.0f));

    ExperienceProgressText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ExperienceProgressText"));
    ExperienceProgressText->SetJustification(ETextJustify::Right);
    DMFNativeUI::StyleText(ExperienceProgressText, 12, DMFNativeUI::Muted(), true);
    Column->AddChildToVerticalBox(ExperienceProgressText);

    LevelUpText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("LevelUpText"));
    LevelUpText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(LevelUpText, 15, DMFNativeUI::Gold(), true);
    Column->AddChildToVerticalBox(LevelUpText)->SetPadding(FMargin(0.0f, 3.0f, 0.0f, 0.0f));

    SetVisibility(ESlateVisibility::Collapsed);
}

UDMFDigimonSpeciesData* UDMFExperienceNotificationWidget::ResolveSpecies(const FPrimaryAssetId SpeciesId) const
{
    if (!SpeciesId.IsValid())
    {
        return nullptr;
    }
    UAssetManager& Manager = UAssetManager::Get();
    if (UDMFDigimonSpeciesData* Loaded = Manager.GetPrimaryAssetObject<UDMFDigimonSpeciesData>(SpeciesId))
    {
        return Loaded;
    }
    const FSoftObjectPath Path = Manager.GetPrimaryAssetPath(SpeciesId);
    return Path.IsValid() ? Cast<UDMFDigimonSpeciesData>(Path.TryLoad()) : nullptr;
}

int32 UDMFExperienceNotificationWidget::ResolveMaximumLevel(const UDMFDigimonSpeciesData* Species) const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const int32 GlobalMaximum = Settings ? FMath::Clamp(Settings->DefaultMaxDigimonLevel, 1, 999) : 99;
    return Species && Species->MaxLevelOverride > 0 ? FMath::Clamp(Species->MaxLevelOverride, 1, 999) : GlobalMaximum;
}

int64 UDMFExperienceNotificationWidget::ResolveExperienceRequirement(const UDMFDigimonSpeciesData* Species, const int32 CurrentLevel) const
{
    return Species ? DMFLevelProgressionMath::GetExperienceRequiredForLevel(*Species, CurrentLevel) : 0;
}

void UDMFExperienceNotificationWidget::ShowExperienceProgress(const FDMFDigimonExperienceProgression& Progression)
{
    if (!Progression.DigimonInstanceId.IsValid() || Progression.ExperienceGained <= 0)
    {
        return;
    }

    // Battle rewards are naturally spaced, but bound the queue defensively for scripted mass-reward scenarios.
    constexpr int32 MaxQueuedPresentations = 8;
    if (PendingPresentations.Num() >= MaxQueuedPresentations)
    {
        PendingPresentations.RemoveAt(0, PendingPresentations.Num() - MaxQueuedPresentations + 1, EAllowShrinking::No);
    }
    PendingPresentations.Add(Progression);

    if (!bPresentationActive)
    {
        BeginNextPresentation();
    }
}

void UDMFExperienceNotificationWidget::BeginNextPresentation()
{
    if (PendingPresentations.IsEmpty())
    {
        bPresentationActive = false;
        SetVisibility(ESlateVisibility::Collapsed);
        return;
    }

    ActiveProgression = PendingPresentations[0];
    PendingPresentations.RemoveAt(0, 1, EAllowShrinking::No);
    bPresentationActive = true;
    bLevelUpEventFired = false;

    UDMFDigimonSpeciesData* Species = ResolveSpecies(ActiveProgression.SpeciesId);
    const FText SpeciesName = Species && !Species->DisplayName.IsEmpty()
        ? Species->DisplayName
        : FText::FromName(ActiveProgression.SpeciesId.PrimaryAssetName);

    if (SpeciesNameText)
    {
        SpeciesNameText->SetText(SpeciesName);
    }
    if (ExperienceGainText)
    {
        ExperienceGainText->SetText(FText::Format(NSLOCTEXT("DMF", "ExperienceGainToast", "+{0} EXP"), FText::AsNumber(ActiveProgression.ExperienceGained)));
    }
    if (SpeciesPortraitImage)
    {
        if (UTexture2D* Portrait = Species ? Species->Portrait.LoadSynchronous() : nullptr)
        {
            SpeciesPortraitImage->SetBrushFromTexture(Portrait, true);
            SpeciesPortraitImage->SetVisibility(ESlateVisibility::HitTestInvisible);
        }
        else
        {
            SpeciesPortraitImage->SetVisibility(ESlateVisibility::Hidden);
        }
    }

    if (LevelUpText)
    {
        if (ActiveProgression.LevelsGained > 0)
        {
            FText LevelUp = ActiveProgression.AttributePointsGained > 0
                ? FText::Format(NSLOCTEXT("DMF", "LevelUpToastWithPoints", "LEVEL UP!  {0} → {1}   •   +{2} ATTRIBUTE PTS"),
                    FText::AsNumber(ActiveProgression.PreviousLevel), FText::AsNumber(ActiveProgression.NewLevel), FText::AsNumber(ActiveProgression.AttributePointsGained))
                : FText::Format(NSLOCTEXT("DMF", "LevelUpToast", "LEVEL UP!  {0} → {1}"),
                    FText::AsNumber(ActiveProgression.PreviousLevel), FText::AsNumber(ActiveProgression.NewLevel));
            if (ActiveProgression.bReachedMaxLevel)
            {
                LevelUp = FText::Format(NSLOCTEXT("DMF", "LevelUpToastMax", "{0}   •   MAX LEVEL"), LevelUp);
            }
            LevelUpText->SetText(LevelUp);
            // Reveal only when the animated bar actually crosses the first threshold.
            LevelUpText->SetVisibility(ESlateVisibility::Collapsed);
        }
        else
        {
            LevelUpText->SetVisibility(ESlateVisibility::Collapsed);
        }
    }

    SetVisibility(ESlateVisibility::HitTestInvisible);
    ApplyAnimatedProgress(0.0f);
    BP_OnExperienceProgressPresented(ActiveProgression);

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    AnimationDurationSeconds = Settings ? FMath::Clamp(Settings->ExperienceProgressAnimationSeconds, 0.05f, 5.0f) : 1.10f;
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(AnimationTimer);
        World->GetTimerManager().ClearTimer(HideTimer);
        AnimationStartTimeSeconds = World->GetTimeSeconds();
        World->GetTimerManager().SetTimer(AnimationTimer, this, &UDMFExperienceNotificationWidget::UpdateProgressAnimation, 0.016f, true, 0.0f);
    }
}

void UDMFExperienceNotificationWidget::UpdateProgressAnimation()
{
    UWorld* World = GetWorld();
    if (!World || !bPresentationActive)
    {
        return;
    }

    const float RawAlpha = AnimationDurationSeconds > KINDA_SMALL_NUMBER
        ? FMath::Clamp(static_cast<float>((World->GetTimeSeconds() - AnimationStartTimeSeconds) / static_cast<double>(AnimationDurationSeconds)), 0.0f, 1.0f)
        : 1.0f;
    const float EasedAlpha = FMath::InterpEaseOut(0.0f, 1.0f, RawAlpha, 2.0f);
    ApplyAnimatedProgress(EasedAlpha);

    if (RawAlpha >= 1.0f - KINDA_SMALL_NUMBER)
    {
        World->GetTimerManager().ClearTimer(AnimationTimer);
        ApplyAnimatedProgress(1.0f);
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        const float HoldSeconds = ActiveProgression.LevelsGained > 0
            ? (Settings ? FMath::Clamp(Settings->LevelUpNotificationHoldSeconds, 0.1f, 10.0f) : 3.40f)
            : (Settings ? FMath::Clamp(Settings->ExperienceNotificationHoldSeconds, 0.1f, 10.0f) : 2.20f);
        World->GetTimerManager().SetTimer(HideTimer, this, &UDMFExperienceNotificationWidget::FinishCurrentPresentation, HoldSeconds, false);
    }
}

void UDMFExperienceNotificationWidget::ApplyAnimatedProgress(const float Alpha)
{
    UDMFDigimonSpeciesData* Species = ResolveSpecies(ActiveProgression.SpeciesId);
    const int32 ConfiguredMaxLevel = ResolveMaximumLevel(Species);
    const int32 MaxLevel = FMath::Max(ConfiguredMaxLevel, FMath::Max(ActiveProgression.PreviousLevel, ActiveProgression.NewLevel));
    const int32 PreviousLevel = FMath::Clamp(ActiveProgression.PreviousLevel, 1, MaxLevel);
    const int32 NewLevel = FMath::Clamp(ActiveProgression.NewLevel, PreviousLevel, MaxLevel);
    const int64 PreviousRequirement = PreviousLevel < MaxLevel ? ResolveExperienceRequirement(Species, PreviousLevel) : 1;
    const float StartFraction = PreviousLevel < MaxLevel
        ? FMath::Clamp(static_cast<float>(static_cast<double>(FMath::Max<int64>(0, ActiveProgression.PreviousExperience)) / static_cast<double>(PreviousRequirement)), 0.0f, 1.0f)
        : 1.0f;

    const int64 FinalRequirement = NewLevel < MaxLevel ? ResolveExperienceRequirement(Species, NewLevel) : 1;
    const float FinalFraction = NewLevel < MaxLevel
        ? FMath::Clamp(static_cast<float>(static_cast<double>(FMath::Max<int64>(0, ActiveProgression.NewExperience)) / static_cast<double>(FinalRequirement)), 0.0f, 1.0f)
        : 1.0f;

    const float EndTravel = static_cast<float>(FMath::Max(0, ActiveProgression.LevelsGained)) + FinalFraction;
    const float Travel = FMath::Lerp(StartFraction, EndTravel, FMath::Clamp(Alpha, 0.0f, 1.0f));
    const int32 SegmentOffset = FMath::Clamp(FMath::FloorToInt(Travel), 0, FMath::Max(0, NewLevel - PreviousLevel));
    const int32 DisplayLevel = FMath::Clamp(PreviousLevel + SegmentOffset, PreviousLevel, NewLevel);
    float DisplayFraction = FMath::Clamp(Travel - static_cast<float>(SegmentOffset), 0.0f, 1.0f);

    if (Alpha >= 1.0f - KINDA_SMALL_NUMBER)
    {
        DisplayFraction = FinalFraction;
    }
    if (DisplayLevel >= MaxLevel)
    {
        DisplayFraction = 1.0f;
    }

    if (!bLevelUpEventFired && ActiveProgression.LevelsGained > 0 && DisplayLevel > PreviousLevel)
    {
        bLevelUpEventFired = true;
        if (LevelUpText)
        {
            LevelUpText->SetVisibility(ESlateVisibility::HitTestInvisible);
        }
        BP_OnLevelUpPresented(ActiveProgression);
    }

    if (ExperienceProgressBar)
    {
        ExperienceProgressBar->SetPercent(DisplayFraction);
    }
    if (LevelText)
    {
        LevelText->SetText(FText::Format(NSLOCTEXT("DMF", "ExperienceToastLevel", "LEVEL {0}"), FText::AsNumber(DisplayLevel)));
    }
    if (ExperienceProgressText)
    {
        if (DisplayLevel >= MaxLevel)
        {
            ExperienceProgressText->SetText(NSLOCTEXT("DMF", "ExperienceToastMaxLevel", "MAX LEVEL"));
        }
        else
        {
            const int64 Requirement = ResolveExperienceRequirement(Species, DisplayLevel);
            const int64 DisplayExperience = (Alpha >= 1.0f - KINDA_SMALL_NUMBER && DisplayLevel == NewLevel)
                ? FMath::Clamp<int64>(ActiveProgression.NewExperience, 0, Requirement)
                : FMath::Clamp<int64>(static_cast<int64>(static_cast<double>(Requirement) * static_cast<double>(DisplayFraction) + 0.5), 0, Requirement);
            ExperienceProgressText->SetText(FText::Format(NSLOCTEXT("DMF", "ExperienceToastProgress", "EXP  {0} / {1}"), FText::AsNumber(DisplayExperience), FText::AsNumber(Requirement)));
        }
    }
}

void UDMFExperienceNotificationWidget::FinishCurrentPresentation()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(AnimationTimer);
        World->GetTimerManager().ClearTimer(HideTimer);
    }
    SetVisibility(ESlateVisibility::Collapsed);
    bPresentationActive = false;
    BeginNextPresentation();
}
