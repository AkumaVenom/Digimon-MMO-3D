#include "UI/DMFHomeTeleportNotificationWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Settings/DMFFrameworkSettings.h"
#include "TimerManager.h"
#include "UI/DMFNativeUIStyle.h"

TSharedRef<SWidget> UDMFHomeTeleportNotificationWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFHomeTeleportNotificationTree"));
    }
    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }
    return Super::RebuildWidget();
}

void UDMFHomeTeleportNotificationWidget::BuildNativeFallbackUI()
{
    UOverlay* Root = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("HomeTeleportToastRoot"));
    Root->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    WidgetTree->RootWidget = Root;

    USizeBox* Size = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("HomeTeleportToastSize"));
    Size->SetWidthOverride(430.0f);
    Size->SetHeightOverride(82.0f);
    if (UOverlaySlot* OverlaySlot = Root->AddChildToOverlay(Size))
    {
        OverlaySlot->SetHorizontalAlignment(HAlign_Center);
        OverlaySlot->SetVerticalAlignment(VAlign_Top);
        OverlaySlot->SetPadding(FMargin(24.0f, 78.0f, 24.0f, 0.0f));
    }

    UBorder* Panel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("HomeTeleportToastPanel"));
    DMFNativeUI::StylePanel(Panel, DMFNativeUI::PanelRaised(), FMargin(14.0f, 10.0f));
    Size->AddChild(Panel);

    UVerticalBox* Column = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("HomeTeleportToastColumn"));
    Panel->AddChild(Column);

    HomeTitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("HomeTitleText"));
    HomeTitleText->SetText(NSLOCTEXT("DMF", "HomeTeleportToastTitle", "HOME"));
    HomeTitleText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(HomeTitleText, 15, DMFNativeUI::Gold(), true);
    Column->AddChildToVerticalBox(HomeTitleText);

    HomeMessageText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("HomeMessageText"));
    HomeMessageText->SetJustification(ETextJustify::Center);
    HomeMessageText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(HomeMessageText, 12, DMFNativeUI::Text(), true);
    if (UVerticalBoxSlot* MessageSlot = Column->AddChildToVerticalBox(HomeMessageText))
    {
        MessageSlot->SetPadding(FMargin(4.0f, 4.0f, 4.0f, 0.0f));
    }
}

void UDMFHomeTeleportNotificationWidget::ShowHomeTeleportResult(const bool bSuccess, const FText& Message)
{
    if (HomeTitleText)
    {
        HomeTitleText->SetText(bSuccess
            ? NSLOCTEXT("DMF", "HomeTeleportToastSuccess", "HOME • ARRIVED")
            : NSLOCTEXT("DMF", "HomeTeleportToastFailure", "HOME • UNAVAILABLE"));
        HomeTitleText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Gold() : DMFNativeUI::Danger()));
    }
    if (HomeMessageText)
    {
        HomeMessageText->SetText(Message);
        HomeMessageText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Text() : DMFNativeUI::Danger()));
    }

    SetVisibility(ESlateVisibility::HitTestInvisible);
    if (UWorld* World = GetWorld())
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        const float HoldSeconds = Settings ? FMath::Max(0.25f, Settings->HomeTeleportNotificationHoldSeconds) : 3.0f;
        World->GetTimerManager().ClearTimer(HideTimer);
        World->GetTimerManager().SetTimer(HideTimer, this, &UDMFHomeTeleportNotificationWidget::HideToast, HoldSeconds, false);
    }
    BP_OnHomeTeleportResultPresented(bSuccess, Message);
}

void UDMFHomeTeleportNotificationWidget::HideToast()
{
    SetVisibility(ESlateVisibility::Collapsed);
}
