#include "UI/DMFScanNotificationWidget.h"
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
#include "Data/DMFDigimonSpeciesData.h"
#include "Engine/AssetManager.h"
#include "Engine/Texture2D.h"
#include "TimerManager.h"
#include "UI/DMFNativeUIStyle.h"

TSharedRef<SWidget> UDMFScanNotificationWidget::RebuildWidget()
{
    if (!WidgetTree) WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFScanNotificationTree"));
    if (WidgetTree && !WidgetTree->RootWidget) BuildNativeFallbackUI();
    return Super::RebuildWidget();
}

void UDMFScanNotificationWidget::BuildNativeFallbackUI()
{
    UOverlay* Root = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("ScanToastRoot"));
    WidgetTree->RootWidget = Root;
    USizeBox* Size = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("ScanToastSize"));
    Size->SetWidthOverride(430.0f); Size->SetHeightOverride(116.0f);
    if (UOverlaySlot* ToastOverlaySlot = Root->AddChildToOverlay(Size)) { ToastOverlaySlot->SetHorizontalAlignment(HAlign_Right); ToastOverlaySlot->SetVerticalAlignment(VAlign_Top); ToastOverlaySlot->SetPadding(FMargin(24.0f, 120.0f, 24.0f, 0.0f)); }
    UBorder* Panel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ScanToastPanel"));
    DMFNativeUI::StylePanel(Panel, DMFNativeUI::PanelRaised(), FMargin(10.0f)); Size->AddChild(Panel);
    UHorizontalBox* Row = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ScanToastRow")); Panel->AddChild(Row);
    USizeBox* PortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("ScanToastPortraitSize")); PortraitSize->SetWidthOverride(88.0f); PortraitSize->SetHeightOverride(88.0f);
    SpeciesPortraitImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("SpeciesPortraitImage")); PortraitSize->AddChild(SpeciesPortraitImage);
    Row->AddChildToHorizontalBox(PortraitSize)->SetPadding(FMargin(0,0,12,0));
    UVerticalBox* Column = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("ScanToastColumn")); Row->AddChildToHorizontalBox(Column)->SetSize(DMFNativeUI::FillSize());
    SpeciesNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SpeciesNameText")); DMFNativeUI::StyleText(SpeciesNameText,18,DMFNativeUI::Text(),true); Column->AddChildToVerticalBox(SpeciesNameText);
    RewardText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("RewardText")); DMFNativeUI::StyleText(RewardText,14,DMFNativeUI::Accent(),true); Column->AddChildToVerticalBox(RewardText);
    ScanProgressBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("ScanProgressBar")); ScanProgressBar->SetFillColorAndOpacity(DMFNativeUI::Accent()); Column->AddChildToVerticalBox(ScanProgressBar)->SetPadding(FMargin(0,6,0,4));
    ReadyText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ReadyText")); DMFNativeUI::StyleText(ReadyText,12,DMFNativeUI::Gold(),true); Column->AddChildToVerticalBox(ReadyText);
}

UDMFDigimonSpeciesData* UDMFScanNotificationWidget::ResolveSpecies(const FPrimaryAssetId SpeciesId) const
{
    UAssetManager& Manager = UAssetManager::Get();
    if (UDMFDigimonSpeciesData* Loaded = Manager.GetPrimaryAssetObject<UDMFDigimonSpeciesData>(SpeciesId)) return Loaded;
    const FSoftObjectPath Path = Manager.GetPrimaryAssetPath(SpeciesId);
    return Path.IsValid() ? Cast<UDMFDigimonSpeciesData>(Path.TryLoad()) : nullptr;
}

void UDMFScanNotificationWidget::ShowScanReward(const FPrimaryAssetId SpeciesId, const float AddedPercent, const float NewPercent, const bool bMaterializationReady)
{
    UDMFDigimonSpeciesData* Species = ResolveSpecies(SpeciesId);
    const float Requirement = Species ? FMath::Max(1.0f, Species->MaterializationRequiredScanPercent) : 100.0f;
    if (SpeciesNameText) SpeciesNameText->SetText(Species && !Species->DisplayName.IsEmpty() ? Species->DisplayName : FText::FromName(SpeciesId.PrimaryAssetName));
    if (RewardText) RewardText->SetText(FText::Format(NSLOCTEXT("DMF","ScanRewardToastFormat","SCAN DATA  +{0}%   •   {1}%"), FText::AsNumber(FMath::RoundToInt(AddedPercent)), FText::AsNumber(FMath::RoundToInt(NewPercent))));
    if (ScanProgressBar) ScanProgressBar->SetPercent(FMath::Clamp(NewPercent / Requirement, 0.0f, 1.0f));
    if (ReadyText) { ReadyText->SetText(bMaterializationReady ? NSLOCTEXT("DMF","MaterializationReadyToast","MATERIALIZATION READY") : NSLOCTEXT("DMF","ScanDatabaseUpdatedToast","SCAN DATABASE UPDATED")); ReadyText->SetColorAndOpacity(FSlateColor(bMaterializationReady ? DMFNativeUI::Gold() : DMFNativeUI::Muted())); }
    if (SpeciesPortraitImage)
    {
        if (UTexture2D* Portrait = Species ? Species->Portrait.LoadSynchronous() : nullptr) { SpeciesPortraitImage->SetBrushFromTexture(Portrait,true); SpeciesPortraitImage->SetVisibility(ESlateVisibility::HitTestInvisible); }
        else SpeciesPortraitImage->SetVisibility(ESlateVisibility::Hidden);
    }
    SetVisibility(ESlateVisibility::HitTestInvisible);
    if (UWorld* World = GetWorld()) { World->GetTimerManager().ClearTimer(HideTimer); World->GetTimerManager().SetTimer(HideTimer, this, &UDMFScanNotificationWidget::HideToast, bMaterializationReady ? 5.0f : 3.5f, false); }
    BP_OnScanRewardPresented(SpeciesId, AddedPercent, NewPercent, bMaterializationReady);
}

void UDMFScanNotificationWidget::HideToast()
{
    SetVisibility(ESlateVisibility::Collapsed);
}
