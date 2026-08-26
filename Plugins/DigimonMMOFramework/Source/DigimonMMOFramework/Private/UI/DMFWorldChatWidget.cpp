#include "UI/DMFWorldChatWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/EditableTextBox.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/ScrollBox.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Game/DMFMMOPlayerController.h"
#include "InputCoreTypes.h"
#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFNativeUIStyle.h"

TSharedRef<SWidget> UDMFWorldChatWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFWorldChatTree"));
    }

    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }

    return Super::RebuildWidget();
}

void UDMFWorldChatWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (MessageInput)
    {
        MessageInput->OnTextCommitted.RemoveDynamic(this, &UDMFWorldChatWidget::HandleMessageCommitted);
        MessageInput->OnTextCommitted.AddDynamic(this, &UDMFWorldChatWidget::HandleMessageCommitted);
    }

    RefreshInputPresentation();
}

FReply UDMFWorldChatWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
    if (bChatInputOpen && InKeyEvent.GetKey() == EKeys::Escape)
    {
        if (ADMFMMOPlayerController* Controller = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
        {
            Controller->CloseWorldChatInput();
        }
        else
        {
            CloseChatInput();
        }
        return FReply::Handled();
    }

    return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}

void UDMFWorldChatWidget::BuildNativeFallbackUI()
{
    UOverlay* RootOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("WorldChatRoot"));
    RootOverlay->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    WidgetTree->RootWidget = RootOverlay;

    USizeBox* ChatSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("WorldChatSize"));
    ChatSize->SetWidthOverride(610.0f);
    ChatSize->SetHeightOverride(318.0f);

    // Keep the native WORLD chat in a dedicated lower-left HUD lane instead of sharing the
    // centered combat quick-access lane. The combat bar occupies 128 Slate units plus its
    // 26-unit bottom inset; 176 leaves a deliberate 22-unit visual gutter between both HUDs.
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const float ChatBottomOffset = (Settings && Settings->bShowNativeCombatQuickBar)
        ? FMath::Max(30.0f, Settings->WorldChatBottomSafeOffset)
        : 30.0f;

    if (UOverlaySlot* ChatRootSlot = RootOverlay->AddChildToOverlay(ChatSize))
    {
        ChatRootSlot->SetHorizontalAlignment(HAlign_Left);
        ChatRootSlot->SetVerticalAlignment(VAlign_Bottom);
        ChatRootSlot->SetPadding(FMargin(24.0f, 24.0f, 24.0f, ChatBottomOffset));
    }

    ChatPanel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ChatPanel"));
    DMFNativeUI::StylePanel(ChatPanel, FLinearColor(0.006f, 0.018f, 0.040f, 0.86f), FMargin(12.0f, 10.0f));
    ChatSize->AddChild(ChatPanel);

    UVerticalBox* ChatColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("ChatColumn"));
    ChatPanel->AddChild(ChatColumn);

    UHorizontalBox* HeaderRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ChatHeaderRow"));
    if (UVerticalBoxSlot* HeaderSlot = ChatColumn->AddChildToVerticalBox(HeaderRow))
    {
        HeaderSlot->SetPadding(FMargin(1.0f, 0.0f, 1.0f, 7.0f));
    }

    UTextBlock* ChannelTitle = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ChannelTitle"));
    ChannelTitle->SetText(NSLOCTEXT("DMF", "WorldChatChannelTitle", "WORLD"));
    DMFNativeUI::StyleText(ChannelTitle, 13, DMFNativeUI::Accent(), true);
    HeaderRow->AddChildToHorizontalBox(ChannelTitle);

    InputHintText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("InputHintText"));
    InputHintText->SetText(NSLOCTEXT("DMF", "WorldChatEnterHint", "ENTER TO CHAT"));
    InputHintText->SetJustification(ETextJustify::Right);
    DMFNativeUI::StyleText(InputHintText, 11, DMFNativeUI::Muted(), true);
    if (UHorizontalBoxSlot* HintSlot = HeaderRow->AddChildToHorizontalBox(InputHintText))
    {
        HintSlot->SetSize(DMFNativeUI::FillSize());
        HintSlot->SetHorizontalAlignment(HAlign_Right);
        HintSlot->SetVerticalAlignment(VAlign_Center);
    }

    MessageScrollBox = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("MessageScrollBox"));
    MessageScrollBox->SetScrollBarVisibility(ESlateVisibility::Collapsed);
    if (UVerticalBoxSlot* ScrollSlot = ChatColumn->AddChildToVerticalBox(MessageScrollBox))
    {
        ScrollSlot->SetSize(DMFNativeUI::FillSize());
        ScrollSlot->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 8.0f));
    }

    MessageList = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("MessageList"));
    MessageScrollBox->AddChild(MessageList);

    InputPanel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("InputPanel"));
    DMFNativeUI::StylePanel(InputPanel, FLinearColor(0.020f, 0.055f, 0.100f, 0.98f), FMargin(6.0f));
    ChatColumn->AddChildToVerticalBox(InputPanel);

    UHorizontalBox* InputRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("InputRow"));
    InputPanel->AddChild(InputRow);

    UTextBlock* InputChannel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("InputChannel"));
    InputChannel->SetText(NSLOCTEXT("DMF", "WorldChatInputPrefix", "[WORLD]"));
    DMFNativeUI::StyleText(InputChannel, 12, DMFNativeUI::Accent(), true);
    if (UHorizontalBoxSlot* ChannelSlot = InputRow->AddChildToHorizontalBox(InputChannel))
    {
        ChannelSlot->SetVerticalAlignment(VAlign_Center);
        ChannelSlot->SetPadding(FMargin(2.0f, 0.0f, 8.0f, 0.0f));
    }

    MessageInput = WidgetTree->ConstructWidget<UEditableTextBox>(UEditableTextBox::StaticClass(), TEXT("MessageInput"));
    MessageInput->SetHintText(NSLOCTEXT("DMF", "WorldChatMessageHint", "Type a message..."));
    DMFNativeUI::StyleInput(MessageInput);
    if (UHorizontalBoxSlot* InputSlot = InputRow->AddChildToHorizontalBox(MessageInput))
    {
        InputSlot->SetSize(DMFNativeUI::FillSize());
        InputSlot->SetVerticalAlignment(VAlign_Center);
    }
}

void UDMFWorldChatWidget::AddNativeMessageRow(const FDMFWorldChatMessage& ChatMessage)
{
    if (!WidgetTree || !MessageList)
    {
        return;
    }

    UHorizontalBox* MessageRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
    if (UVerticalBoxSlot* RowSlot = MessageList->AddChildToVerticalBox(MessageRow))
    {
        RowSlot->SetPadding(FMargin(1.0f, 1.0f, 1.0f, 3.0f));
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && Settings->bShowWorldChatTimestamps && ChatMessage.SentUtcTicks > 0)
    {
        const FDateTime SentUtc(ChatMessage.SentUtcTicks);
        UTextBlock* Timestamp = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        Timestamp->SetText(FText::FromString(FString::Printf(TEXT("[%s] "), *SentUtc.ToString(TEXT("%H:%M")))));
        DMFNativeUI::StyleText(Timestamp, 11, DMFNativeUI::Muted(), false);
        MessageRow->AddChildToHorizontalBox(Timestamp)->SetVerticalAlignment(VAlign_Top);
    }

    UTextBlock* Sender = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
    const bool bSystem = ChatMessage.MessageType == EDMFWorldChatMessageType::System;
    const FString SenderLabel = bSystem
        ? FString(TEXT("SYSTEM  •  "))
        : FString::Printf(TEXT("%s:  "), *ChatMessage.SenderName);
    Sender->SetText(FText::FromString(SenderLabel));
    DMFNativeUI::StyleText(Sender, 12, bSystem ? DMFNativeUI::Gold() : DMFNativeUI::Accent(), true);
    MessageRow->AddChildToHorizontalBox(Sender)->SetVerticalAlignment(VAlign_Top);

    UTextBlock* Body = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
    Body->SetText(FText::FromString(ChatMessage.Message));
    Body->SetAutoWrapText(true);
    Body->SetWrapTextAt(430.0f);
    DMFNativeUI::StyleText(Body, 12, bSystem ? DMFNativeUI::Muted() : DMFNativeUI::Text(), false);
    if (UHorizontalBoxSlot* BodySlot = MessageRow->AddChildToHorizontalBox(Body))
    {
        BodySlot->SetSize(DMFNativeUI::FillSize());
        BodySlot->SetVerticalAlignment(VAlign_Top);
    }
}

void UDMFWorldChatWidget::AddChatMessage(const FDMFWorldChatMessage& ChatMessage)
{
    if (ChatMessage.Message.IsEmpty())
    {
        return;
    }

    LocalMessageHistory.Add(ChatMessage);
    AddNativeMessageRow(ChatMessage);
    TrimLocalHistoryToLimit();

    if (MessageScrollBox)
    {
        MessageScrollBox->ScrollToEnd();
    }

    BP_OnWorldChatMessageAdded(ChatMessage);
}

void UDMFWorldChatWidget::SetChatHistory(const TArray<FDMFWorldChatMessage>& ChatMessages)
{
    ClearChatHistory();
    for (const FDMFWorldChatMessage& ChatMessage : ChatMessages)
    {
        AddChatMessage(ChatMessage);
    }
}

void UDMFWorldChatWidget::AddLocalSystemMessage(const FText& Message)
{
    if (Message.IsEmpty())
    {
        return;
    }

    FDMFWorldChatMessage ChatMessage;
    ChatMessage.SenderName = TEXT("SYSTEM");
    ChatMessage.Message = Message.ToString();
    ChatMessage.SentUtcTicks = FDateTime::UtcNow().GetTicks();
    ChatMessage.MessageType = EDMFWorldChatMessageType::System;
    AddChatMessage(ChatMessage);
}

void UDMFWorldChatWidget::ClearChatHistory()
{
    LocalMessageHistory.Reset();
    if (MessageList)
    {
        MessageList->ClearChildren();
    }
}

void UDMFWorldChatWidget::OpenChatInput()
{
    bChatInputOpen = true;
    RefreshInputPresentation();

    if (MessageInput)
    {
        MessageInput->SetText(FText::GetEmpty());
        MessageInput->SetKeyboardFocus();
    }

    BP_OnWorldChatInputStateChanged(true);
}

void UDMFWorldChatWidget::CloseChatInput()
{
    bChatInputOpen = false;
    if (MessageInput)
    {
        MessageInput->SetText(FText::GetEmpty());
    }
    RefreshInputPresentation();
    BP_OnWorldChatInputStateChanged(false);
}

void UDMFWorldChatWidget::RefreshInputPresentation()
{
    if (InputPanel)
    {
        InputPanel->SetVisibility(bChatInputOpen ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
    if (InputHintText)
    {
        InputHintText->SetText(bChatInputOpen
            ? NSLOCTEXT("DMF", "WorldChatEscapeHint", "ENTER SENDS  •  ESC CANCELS")
            : NSLOCTEXT("DMF", "WorldChatEnterHint", "ENTER TO CHAT"));
        InputHintText->SetColorAndOpacity(FSlateColor(bChatInputOpen ? DMFNativeUI::Accent() : DMFNativeUI::Muted()));
    }
}

void UDMFWorldChatWidget::TrimLocalHistoryToLimit()
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const int32 MaxMessages = Settings ? FMath::Clamp(Settings->WorldChatClientHistoryLimit, 10, 500) : 100;

    while (LocalMessageHistory.Num() > MaxMessages)
    {
        LocalMessageHistory.RemoveAt(0);
        if (MessageList && MessageList->GetChildrenCount() > 0)
        {
            MessageList->RemoveChildAt(0);
        }
    }
}

void UDMFWorldChatWidget::HandleMessageCommitted(const FText& Text, const ETextCommit::Type CommitMethod)
{
    if (CommitMethod == ETextCommit::OnEnter)
    {
        if (ADMFMMOPlayerController* Controller = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
        {
            const FString SubmittedText = Text.ToString();
            if (!SubmittedText.TrimStartAndEnd().IsEmpty())
            {
                Controller->SendWorldChatMessage(SubmittedText);
            }
            Controller->CloseWorldChatInput();
        }
        else
        {
            CloseChatInput();
        }
        return;
    }

    if (bChatInputOpen && CommitMethod == ETextCommit::OnCleared)
    {
        if (ADMFMMOPlayerController* Controller = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
        {
            Controller->CloseWorldChatInput();
        }
        else
        {
            CloseChatInput();
        }
    }
}
