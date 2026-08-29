#include "UI/DMFFriendTrackerWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Game/DMFPlayerState.h"
#include "GameFramework/PlayerController.h"
#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFNativeUIStyle.h"

TSharedRef<SWidget> UDMFFriendTrackerWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFFriendTrackerWidgetTree"));
    }
    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }
    return Super::RebuildWidget();
}

void UDMFFriendTrackerWidget::NativeTick(const FGeometry& MyGeometry, const float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
    RefreshAccumulator += FMath::Max(0.0f, InDeltaTime);
    if (RefreshAccumulator >= 0.20f)
    {
        RefreshAccumulator = 0.0f;
        RefreshTracker();
    }
}

void UDMFFriendTrackerWidget::SetObservedFriend(ADMFPlayerAvatarCharacter* InFriendAvatar)
{
    ObservedFriend = InFriendAvatar;
    RefreshAccumulator = 0.0f;
    RefreshTracker();
}

void UDMFFriendTrackerWidget::BuildNativeFallbackUI()
{
    TrackerPanel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("FriendTrackerPanel"));
    DMFNativeUI::StylePanel(TrackerPanel, FLinearColor(0.01f, 0.08f, 0.075f, 0.94f), FMargin(8.0f, 5.0f));
    WidgetTree->RootWidget = TrackerPanel;

    UVerticalBox* Column = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("FriendTrackerColumn"));
    TrackerPanel->AddChild(Column);

    FriendNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("FriendNameText"));
    FriendNameText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(FriendNameText, 12, DMFNativeUI::Success(), true);
    Column->AddChildToVerticalBox(FriendNameText);

    DistanceText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("FriendDistanceText"));
    DistanceText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(DistanceText, 11, DMFNativeUI::Text(), true);
    Column->AddChildToVerticalBox(DistanceText);
}

void UDMFFriendTrackerWidget::RefreshTracker()
{
    ADMFPlayerAvatarCharacter* FriendAvatar = ObservedFriend.Get();
    UWorld* World = GetWorld();
    APlayerController* LocalController = GetOwningPlayer();
    if (!LocalController && World)
    {
        LocalController = World->GetFirstPlayerController();
    }

    APawn* LocalPawn = LocalController ? LocalController->GetPawn() : nullptr;
    if (!IsValid(FriendAvatar) || !IsValid(LocalPawn) || FriendAvatar == LocalPawn)
    {
        SetVisibility(ESlateVisibility::Collapsed);
        return;
    }

    FString FriendName = TEXT("Friend");
    if (const ADMFPlayerState* FriendState = FriendAvatar->GetPlayerState<ADMFPlayerState>())
    {
        const FString PublicName = FriendState->GetPlayerName().TrimStartAndEnd();
        if (!PublicName.IsEmpty())
        {
            FriendName = PublicName;
        }
    }

    const int32 DistanceMeters = FMath::Max(0, FMath::RoundToInt(FVector::Dist(LocalPawn->GetActorLocation(), FriendAvatar->GetActorLocation()) / 100.0f));
    if (FriendNameText)
    {
        FriendNameText->SetText(FText::FromString(FriendName));
    }
    if (DistanceText)
    {
        DistanceText->SetText(FText::Format(NSLOCTEXT("DMF", "FriendTrackerDistanceMeters", "{0} m"), FText::AsNumber(DistanceMeters)));
    }

    SetVisibility(ESlateVisibility::HitTestInvisible);
    BP_OnFriendTrackerRefreshed(FriendAvatar, DistanceMeters);
}
