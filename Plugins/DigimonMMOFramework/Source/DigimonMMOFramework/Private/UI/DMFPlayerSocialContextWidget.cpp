#include "UI/DMFPlayerSocialContextWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Game/DMFPlayerState.h"
#include "UI/DMFNativeUIStyle.h"

TSharedRef<SWidget> UDMFPlayerSocialContextWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFPlayerSocialContextTree"));
    }
    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }
    return Super::RebuildWidget();
}

void UDMFPlayerSocialContextWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (FriendActionButton) FriendActionButton->OnClicked.AddUniqueDynamic(this, &UDMFPlayerSocialContextWidget::HandleFriendAction);
    if (IgnoreActionButton) IgnoreActionButton->OnClicked.AddUniqueDynamic(this, &UDMFPlayerSocialContextWidget::HandleIgnoreAction);
    if (GuildInviteButton) GuildInviteButton->OnClicked.AddUniqueDynamic(this, &UDMFPlayerSocialContextWidget::HandleGuildInvite);
    if (CloseButton) CloseButton->OnClicked.AddUniqueDynamic(this, &UDMFPlayerSocialContextWidget::HandleClose);
    RefreshActions();
}

void UDMFPlayerSocialContextWidget::BuildNativeFallbackUI()
{
    USizeBox* Size = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("PlayerSocialContextSize"));
    Size->SetWidthOverride(286.0f);
    WidgetTree->RootWidget = Size;

    UBorder* Panel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("PlayerSocialContextPanel"));
    DMFNativeUI::StylePanel(Panel, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    Size->AddChild(Panel);

    UVerticalBox* Column = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("PlayerSocialContextColumn"));
    Panel->AddChild(Column);

    UTextBlock* Header = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSocialContextHeader"));
    Header->SetText(NSLOCTEXT("DMF", "PlayerSocialContextHeader", "PLAYER ACTIONS"));
    DMFNativeUI::StyleText(Header, 11, DMFNativeUI::Accent(), true);
    Column->AddChildToVerticalBox(Header);

    TargetNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSocialTargetName"));
    TargetNameText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(TargetNameText, 19, DMFNativeUI::Text(), true);
    Column->AddChildToVerticalBox(TargetNameText)->SetPadding(FMargin(0,2,0,1));

    RelationshipText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSocialRelationship"));
    RelationshipText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(RelationshipText, 10, DMFNativeUI::Muted());
    Column->AddChildToVerticalBox(RelationshipText)->SetPadding(FMargin(0,0,0,9));

    FriendActionButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PlayerSocialFriendAction"));
    DMFNativeUI::StyleButton(FriendActionButton, true);
    FriendActionText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSocialFriendActionText"));
    FriendActionText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(FriendActionText, 12, DMFNativeUI::Text(), true);
    FriendActionButton->AddChild(FriendActionText);
    Column->AddChildToVerticalBox(FriendActionButton)->SetPadding(FMargin(0,0,0,5));

    IgnoreActionButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PlayerSocialIgnoreAction"));
    DMFNativeUI::StyleButton(IgnoreActionButton, false, true);
    IgnoreActionText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSocialIgnoreActionText"));
    IgnoreActionText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(IgnoreActionText, 12, DMFNativeUI::Text(), true);
    IgnoreActionButton->AddChild(IgnoreActionText);
    Column->AddChildToVerticalBox(IgnoreActionButton)->SetPadding(FMargin(0,0,0,5));

    GuildInviteButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PlayerSocialGuildInvite"));
    DMFNativeUI::StyleButton(GuildInviteButton);
    UTextBlock* GuildInviteText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSocialGuildInviteText"));
    GuildInviteText->SetText(NSLOCTEXT("DMF", "PlayerSocialGuildInvite", "INVITE TO GUILD"));
    GuildInviteText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(GuildInviteText, 12, DMFNativeUI::Gold(), true);
    GuildInviteButton->AddChild(GuildInviteText);
    Column->AddChildToVerticalBox(GuildInviteButton)->SetPadding(FMargin(0,0,0,8));

    CloseButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PlayerSocialContextClose"));
    DMFNativeUI::StyleButton(CloseButton);
    UTextBlock* CloseText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSocialContextCloseText"));
    CloseText->SetText(NSLOCTEXT("DMF", "PlayerSocialContextClose", "CLOSE"));
    CloseText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(CloseText, 11, DMFNativeUI::Muted(), true);
    CloseButton->AddChild(CloseText);
    Column->AddChildToVerticalBox(CloseButton);
}

void UDMFPlayerSocialContextWidget::SetTargetPlayer(ADMFPlayerAvatarCharacter* InTargetPlayer)
{
    TargetPlayer = InTargetPlayer;
    TargetUsername.Reset();
    bTargetIsFriend = false;
    bTargetHasInboundFriendRequest = false;
    bTargetHasOutboundFriendRequest = false;
    bTargetIsIgnored = false;
    if (IsValid(InTargetPlayer))
    {
        if (const ADMFPlayerState* TargetState = InTargetPlayer->GetPlayerState<ADMFPlayerState>())
        {
            TargetUsername = TargetState->GetPlayerName().TrimStartAndEnd();
        }
    }
    RefreshActions();
}

void UDMFPlayerSocialContextWidget::RefreshActions()
{
    ADMFMMOPlayerController* Controller = Cast<ADMFMMOPlayerController>(GetOwningPlayer());
    if (!Controller || TargetUsername.IsEmpty())
    {
        SetVisibility(ESlateVisibility::Collapsed);
        return;
    }

    const FDMFSocialSnapshot Snapshot = Controller->GetCachedSocialSnapshot();
    bTargetIsFriend = Snapshot.Friends.ContainsByPredicate([this](const FDMFSocialFriendEntry& Entry)
    {
        return Entry.Username.Equals(TargetUsername, ESearchCase::IgnoreCase);
    });
    bTargetHasInboundFriendRequest = Snapshot.PendingFriendRequests.ContainsByPredicate([this](const FString& Name)
    {
        return Name.Equals(TargetUsername, ESearchCase::IgnoreCase);
    });
    bTargetHasOutboundFriendRequest = Snapshot.PendingOutgoingFriendRequests.ContainsByPredicate([this](const FString& Name)
    {
        return Name.Equals(TargetUsername, ESearchCase::IgnoreCase);
    });
    bTargetIsIgnored = Snapshot.IgnoredPlayers.ContainsByPredicate([this](const FString& Name)
    {
        return Name.Equals(TargetUsername, ESearchCase::IgnoreCase);
    });

    if (TargetNameText) TargetNameText->SetText(FText::FromString(TargetUsername));
    if (FriendActionText)
    {
        FriendActionText->SetText(bTargetIsFriend
            ? NSLOCTEXT("DMF", "PlayerSocialRemoveFriend", "REMOVE FRIEND")
            : (bTargetHasInboundFriendRequest
                ? NSLOCTEXT("DMF", "PlayerSocialAcceptFriend", "ACCEPT FRIEND")
                : (bTargetHasOutboundFriendRequest
                    ? NSLOCTEXT("DMF", "PlayerSocialCancelFriend", "CANCEL REQUEST")
                    : NSLOCTEXT("DMF", "PlayerSocialAddFriend", "ADD FRIEND"))));
    }
    if (FriendActionButton)
    {
        FriendActionButton->SetIsEnabled(!bTargetIsIgnored || bTargetIsFriend);
    }
    if (IgnoreActionText)
    {
        IgnoreActionText->SetText(bTargetIsIgnored
            ? NSLOCTEXT("DMF", "PlayerSocialRemoveIgnore", "REMOVE IGNORE")
            : NSLOCTEXT("DMF", "PlayerSocialIgnore", "IGNORE PLAYER"));
    }
    if (RelationshipText)
    {
        const FText Relationship = bTargetIsIgnored
            ? NSLOCTEXT("DMF", "PlayerSocialIgnoredState", "Ignored • their WORLD chat is hidden")
            : (bTargetIsFriend
                ? NSLOCTEXT("DMF", "PlayerSocialFriendState", "Friend • tracking can be toggled in Social")
                : (bTargetHasInboundFriendRequest
                    ? NSLOCTEXT("DMF", "PlayerSocialInboundFriendState", "Friend request received • accept from here or Social")
                    : (bTargetHasOutboundFriendRequest
                        ? NSLOCTEXT("DMF", "PlayerSocialOutboundFriendState", "Friend request sent • waiting for response")
                        : NSLOCTEXT("DMF", "PlayerSocialNeutralState", "Player"))));
        RelationshipText->SetText(Relationship);
        RelationshipText->SetColorAndOpacity(FSlateColor(bTargetIsIgnored ? DMFNativeUI::Danger() : (bTargetIsFriend ? DMFNativeUI::Success() : DMFNativeUI::Muted())));
    }

    bool bTargetAlreadyInGuild = false;
    for (const FDMFGuildMemberEntry& Member : Snapshot.GuildMembers)
    {
        if (Member.Username.Equals(TargetUsername, ESearchCase::IgnoreCase))
        {
            bTargetAlreadyInGuild = true;
            break;
        }
    }
    if (GuildInviteButton)
    {
        GuildInviteButton->SetVisibility(Snapshot.bIsGuildOwner && !bTargetAlreadyInGuild && !bTargetIsIgnored ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
    SetVisibility(ESlateVisibility::Visible);
}

void UDMFPlayerSocialContextWidget::HandleFriendAction()
{
    if (ADMFMMOPlayerController* Controller = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        if (bTargetIsFriend) Controller->RequestRemoveFriend(TargetUsername);
        else if (bTargetHasInboundFriendRequest) Controller->RespondToFriendRequest(TargetUsername, true);
        else if (bTargetHasOutboundFriendRequest) Controller->RequestCancelFriendRequest(TargetUsername);
        else Controller->RequestAddFriend(TargetUsername);
        Controller->ClosePlayerSocialContextUI();
    }
}

void UDMFPlayerSocialContextWidget::HandleIgnoreAction()
{
    if (ADMFMMOPlayerController* Controller = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        if (bTargetIsIgnored) Controller->RequestRemoveIgnoredPlayer(TargetUsername);
        else Controller->RequestIgnorePlayer(TargetUsername);
        Controller->ClosePlayerSocialContextUI();
    }
}

void UDMFPlayerSocialContextWidget::HandleGuildInvite()
{
    if (ADMFMMOPlayerController* Controller = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        Controller->RequestInvitePlayerToGuild(TargetUsername);
        Controller->ClosePlayerSocialContextUI();
    }
}

void UDMFPlayerSocialContextWidget::HandleClose()
{
    if (ADMFMMOPlayerController* Controller = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        Controller->ClosePlayerSocialContextUI();
    }
}
