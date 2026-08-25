#include "UI/DMFLoginMainMenuWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/ScaleBox.h"
#include "Components/SizeBox.h"
#include "Components/Spacer.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Game/DMFSessionSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/DMFNativeUIStyle.h"

TSharedRef<SWidget> UDMFLoginMainMenuWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFLoginWidgetTree"));
    }

    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }

    return Super::RebuildWidget();
}

void UDMFLoginMainMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (LoginButton) LoginButton->OnClicked.AddUniqueDynamic(this, &UDMFLoginMainMenuWidget::HandleLogin);
    if (JoinButton) JoinButton->OnClicked.AddUniqueDynamic(this, &UDMFLoginMainMenuWidget::HandleJoin);
    if (AdminButton) AdminButton->OnClicked.AddUniqueDynamic(this, &UDMFLoginMainMenuWidget::HandleAdminToggle);
    if (UnlockAdminButton) UnlockAdminButton->OnClicked.AddUniqueDynamic(this, &UDMFLoginMainMenuWidget::HandleUnlockAdmin);
    if (HostButton) HostButton->OnClicked.AddUniqueDynamic(this, &UDMFLoginMainMenuWidget::HandleHost);
    if (LogoutButton) LogoutButton->OnClicked.AddUniqueDynamic(this, &UDMFLoginMainMenuWidget::HandleLogout);
    if (QuitButton) QuitButton->OnClicked.AddUniqueDynamic(this, &UDMFLoginMainMenuWidget::HandleQuit);

    if (UDMFSessionSubsystem* Session = GetGameInstance() ? GetGameInstance()->GetSubsystem<UDMFSessionSubsystem>() : nullptr)
    {
        Session->OnStatusChanged.RemoveDynamic(this, &UDMFLoginMainMenuWidget::HandleExternalStatus);
        Session->OnStatusChanged.AddDynamic(this, &UDMFLoginMainMenuWidget::HandleExternalStatus);
        if (!Session->GetLastStatus().IsEmpty())
        {
            UpdateStatus(Session->GetLastStatus());
        }
    }

    ApplyFrontendState();
}

void UDMFLoginMainMenuWidget::NativeDestruct()
{
    if (UDMFSessionSubsystem* Session = GetGameInstance() ? GetGameInstance()->GetSubsystem<UDMFSessionSubsystem>() : nullptr)
    {
        Session->OnStatusChanged.RemoveDynamic(this, &UDMFLoginMainMenuWidget::HandleExternalStatus);
    }
    Super::NativeDestruct();
}

void UDMFLoginMainMenuWidget::BuildNativeFallbackUI()
{
    if (!WidgetTree)
    {
        return;
    }

    UOverlay* RootOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("FrontendRootOverlay"));
    WidgetTree->RootWidget = RootOverlay;

    UBorder* BackdropBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("FrontendBackdrop"));
    DMFNativeUI::StylePanel(BackdropBorder, FLinearColor(0.005f, 0.010f, 0.020f, 0.34f), FMargin(0.0f));
    if (UOverlaySlot* BackdropSlot = RootOverlay->AddChildToOverlay(BackdropBorder))
    {
        BackdropSlot->SetHorizontalAlignment(HAlign_Fill);
        BackdropSlot->SetVerticalAlignment(VAlign_Fill);
    }

    UScaleBox* ScreenScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("FrontendScreenScale"));
    ScreenScale->SetStretch(EStretch::ScaleToFit);
    ScreenScale->SetStretchDirection(EStretchDirection::DownOnly);
    if (UOverlaySlot* ScaleSlot = RootOverlay->AddChildToOverlay(ScreenScale))
    {
        ScaleSlot->SetHorizontalAlignment(HAlign_Center);
        ScaleSlot->SetVerticalAlignment(VAlign_Center);
        ScaleSlot->SetPadding(FMargin(24.0f));
    }

    USizeBox* WindowSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("FrontendWindowSize"));
    WindowSize->SetWidthOverride(520.0f);
    WindowSize->SetMinDesiredHeight(500.0f);
    ScreenScale->AddChild(WindowSize);

    UBorder* WindowBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("FrontendWindowBorder"));
    DMFNativeUI::StylePanel(WindowBorder, DMFNativeUI::Panel(), FMargin(22.0f));
    WindowSize->AddChild(WindowBorder);

    UVerticalBox* WindowColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("FrontendWindowColumn"));
    WindowBorder->AddChild(WindowColumn);

    UTextBlock* TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("FrontendTitle"));
    TitleText->SetText(NSLOCTEXT("DMF", "FrontendTitlePolished", "DIGIMON MMO"));
    DMFNativeUI::StyleText(TitleText, 34, DMFNativeUI::Gold(), true);
    WindowColumn->AddChildToVerticalBox(TitleText);

    UTextBlock* SubtitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("FrontendSubtitle"));
    SubtitleText->SetText(NSLOCTEXT("DMF", "FrontendSubtitlePolished", "MULTIPLAYER LOGIN"));
    DMFNativeUI::StyleText(SubtitleText, 13, DMFNativeUI::Muted(), true);
    WindowColumn->AddChildToVerticalBox(SubtitleText)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 16.0f));

    LoginSection = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("LoginSection"));
    WindowColumn->AddChildToVerticalBox(LoginSection);

    UTextBlock* UsernameLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("UsernameLabel"));
    UsernameLabel->SetText(NSLOCTEXT("DMF", "UserLabel", "USERNAME"));
    DMFNativeUI::StyleText(UsernameLabel, 12, DMFNativeUI::Muted(), true);
    LoginSection->AddChildToVerticalBox(UsernameLabel)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 4.0f));

    UsernameInput = WidgetTree->ConstructWidget<UEditableTextBox>(UEditableTextBox::StaticClass(), TEXT("UsernameInput"));
    UsernameInput->SetHintText(NSLOCTEXT("DMF", "UsernameHint", "Enter username"));
    DMFNativeUI::StyleInput(UsernameInput);
    LoginSection->AddChildToVerticalBox(UsernameInput)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 12.0f));

    UTextBlock* PasswordLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PasswordLabel"));
    PasswordLabel->SetText(NSLOCTEXT("DMF", "PassLabel", "PASSWORD"));
    DMFNativeUI::StyleText(PasswordLabel, 12, DMFNativeUI::Muted(), true);
    LoginSection->AddChildToVerticalBox(PasswordLabel)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 4.0f));

    PasswordInput = WidgetTree->ConstructWidget<UEditableTextBox>(UEditableTextBox::StaticClass(), TEXT("PasswordInput"));
    PasswordInput->SetHintText(NSLOCTEXT("DMF", "PasswordHint", "Enter password"));
    PasswordInput->SetIsPassword(true);
    DMFNativeUI::StyleInput(PasswordInput);
    LoginSection->AddChildToVerticalBox(PasswordInput)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 14.0f));

    LoginButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("LoginButton"));
    DMFNativeUI::StyleButton(LoginButton, true);
    UTextBlock* LoginLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("LoginButtonLabel"));
    LoginLabel->SetText(NSLOCTEXT("DMF", "Login", "LOGIN / CONTINUE"));
    LoginLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(LoginLabel, 16, DMFNativeUI::Gold(), true);
    LoginButton->AddChild(LoginLabel);
    LoginSection->AddChildToVerticalBox(LoginButton);

    PlaySection = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("PlaySection"));
    PlaySection->SetVisibility(ESlateVisibility::Collapsed);
    WindowColumn->AddChildToVerticalBox(PlaySection);

    LoggedInUserText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("LoggedInUserText"));
    LoggedInUserText->SetText(NSLOCTEXT("DMF", "LoggedInUserPlaceholder", "Logged in"));
    DMFNativeUI::StyleText(LoggedInUserText, 15, DMFNativeUI::Text(), true);
    PlaySection->AddChildToVerticalBox(LoggedInUserText)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 16.0f));

    UTextBlock* PlayHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayHeader"));
    PlayHeader->SetText(NSLOCTEXT("DMF", "PlayHeader", "PLAY"));
    DMFNativeUI::StyleText(PlayHeader, 13, DMFNativeUI::Gold(), true);
    PlaySection->AddChildToVerticalBox(PlayHeader)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 5.0f));

    JoinButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("JoinButton"));
    DMFNativeUI::StyleButton(JoinButton, true);
    UTextBlock* JoinLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("JoinButtonLabel"));
    JoinLabel->SetText(NSLOCTEXT("DMF", "Join", "JOIN GAME"));
    JoinLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(JoinLabel, 16, DMFNativeUI::Gold(), true);
    JoinButton->AddChild(JoinLabel);
    PlaySection->AddChildToVerticalBox(JoinButton)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 8.0f));

    AdminButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("AdminButton"));
    DMFNativeUI::StyleButton(AdminButton);
    UTextBlock* AdminLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("AdminButtonLabel"));
    AdminLabel->SetText(NSLOCTEXT("DMF", "Admin", "ADMIN"));
    AdminLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(AdminLabel, 15, DMFNativeUI::Gold(), true);
    AdminButton->AddChild(AdminLabel);
    PlaySection->AddChildToVerticalBox(AdminButton)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 10.0f));

    AdminSection = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("AdminSection"));
    AdminSection->SetVisibility(ESlateVisibility::Collapsed);
    PlaySection->AddChildToVerticalBox(AdminSection);

    UBorder* AdminPanelBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("AdminPanelBorder"));
    DMFNativeUI::StylePanel(AdminPanelBorder, DMFNativeUI::PanelRaised(), FMargin(14.0f));
    AdminSection->AddChildToVerticalBox(AdminPanelBorder)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 12.0f));

    UVerticalBox* AdminColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("AdminColumn"));
    AdminPanelBorder->AddChild(AdminColumn);

    UTextBlock* AdminHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("AdminHeader"));
    AdminHeader->SetText(NSLOCTEXT("DMF", "AdminServerHostingHeader", "ADMIN SERVER HOSTING"));
    DMFNativeUI::StyleText(AdminHeader, 14, DMFNativeUI::Gold(), true);
    AdminColumn->AddChildToVerticalBox(AdminHeader);

    UTextBlock* AdminInfo = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("AdminInfo"));
    AdminInfo->SetText(NSLOCTEXT("DMF", "AdminServerHostingInfo", "Authorized administrators only. Host & Play opens the configured MMO world as a listen server."));
    AdminInfo->SetAutoWrapText(true);
    DMFNativeUI::StyleText(AdminInfo, 11, DMFNativeUI::Muted());
    AdminColumn->AddChildToVerticalBox(AdminInfo)->SetPadding(FMargin(0.0f, 2.0f, 0.0f, 10.0f));

    UTextBlock* AdminPasswordLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("AdminPasswordLabel"));
    AdminPasswordLabel->SetText(NSLOCTEXT("DMF", "AdminPasswordLabel", "ADMIN PASSWORD"));
    DMFNativeUI::StyleText(AdminPasswordLabel, 11, DMFNativeUI::Muted(), true);
    AdminColumn->AddChildToVerticalBox(AdminPasswordLabel)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 4.0f));

    AdminPasswordInput = WidgetTree->ConstructWidget<UEditableTextBox>(UEditableTextBox::StaticClass(), TEXT("AdminPasswordInput"));
    AdminPasswordInput->SetIsPassword(true);
    AdminPasswordInput->SetHintText(NSLOCTEXT("DMF", "AdminPasswordHint", "Enter admin password"));
    DMFNativeUI::StyleInput(AdminPasswordInput);
    AdminColumn->AddChildToVerticalBox(AdminPasswordInput)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 8.0f));

    UnlockAdminButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("UnlockAdminButton"));
    DMFNativeUI::StyleButton(UnlockAdminButton);
    UTextBlock* UnlockLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("UnlockAdminLabel"));
    UnlockLabel->SetText(NSLOCTEXT("DMF", "UnlockAdmin", "UNLOCK ADMIN"));
    UnlockLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(UnlockLabel, 14, DMFNativeUI::Gold(), true);
    UnlockAdminButton->AddChild(UnlockLabel);
    AdminColumn->AddChildToVerticalBox(UnlockAdminButton)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 8.0f));

    HostButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("HostButton"));
    DMFNativeUI::StyleButton(HostButton, true);
    UTextBlock* HostLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("HostButtonLabel"));
    HostLabel->SetText(NSLOCTEXT("DMF", "Host", "HOST & PLAY"));
    HostLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(HostLabel, 15, DMFNativeUI::Gold(), true);
    HostButton->AddChild(HostLabel);
    HostButton->SetVisibility(ESlateVisibility::Collapsed);
    AdminColumn->AddChildToVerticalBox(HostButton);

    UHorizontalBox* FooterRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("FrontendFooterRow"));
    PlaySection->AddChildToVerticalBox(FooterRow);

    LogoutButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("LogoutButton"));
    DMFNativeUI::StyleButton(LogoutButton);
    UTextBlock* LogoutLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("LogoutLabel"));
    LogoutLabel->SetText(NSLOCTEXT("DMF", "Logout", "LOGOUT"));
    LogoutLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(LogoutLabel, 13, DMFNativeUI::Text(), true);
    LogoutButton->AddChild(LogoutLabel);
    if (UHorizontalBoxSlot* LogoutSlot = FooterRow->AddChildToHorizontalBox(LogoutButton))
    {
        LogoutSlot->SetSize(DMFNativeUI::FillSize());
        LogoutSlot->SetPadding(FMargin(0.0f, 0.0f, 5.0f, 0.0f));
    }

    QuitButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("QuitButton"));
    DMFNativeUI::StyleButton(QuitButton, false, true);
    UTextBlock* QuitLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("QuitLabel"));
    QuitLabel->SetText(NSLOCTEXT("DMF", "Quit", "QUIT"));
    QuitLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(QuitLabel, 13, DMFNativeUI::Text(), true);
    QuitButton->AddChild(QuitLabel);
    if (UHorizontalBoxSlot* QuitSlot = FooterRow->AddChildToHorizontalBox(QuitButton))
    {
        QuitSlot->SetSize(DMFNativeUI::FillSize());
        QuitSlot->SetPadding(FMargin(5.0f, 0.0f, 0.0f, 0.0f));
    }

    UBorder* StatusBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("FrontendStatusBorder"));
    DMFNativeUI::StylePanel(StatusBorder, FLinearColor(0.015f, 0.030f, 0.055f, 0.95f), FMargin(10.0f, 8.0f));
    WindowColumn->AddChildToVerticalBox(StatusBorder)->SetPadding(FMargin(0.0f, 14.0f, 0.0f, 0.0f));

    StatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("StatusText"));
    StatusText->SetText(NSLOCTEXT("DMF", "StatusReady", "Enter your account credentials."));
    StatusText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(StatusText, 12, DMFNativeUI::Muted());
    StatusBorder->AddChild(StatusText);
}

void UDMFLoginMainMenuWidget::UpdateStatus(const FText& Message, const bool bError)
{
    if (StatusText)
    {
        StatusText->SetText(Message);
        StatusText->SetColorAndOpacity(FSlateColor(bError ? DMFNativeUI::Danger() : DMFNativeUI::Muted()));
    }
}

void UDMFLoginMainMenuWidget::ApplyFrontendState()
{
    UDMFSessionSubsystem* Session = GetGameInstance() ? GetGameInstance()->GetSubsystem<UDMFSessionSubsystem>() : nullptr;
    const bool bLoggedIn = Session && Session->IsLoggedInLocally();
    const bool bAdminUnlocked = Session && Session->IsAdminUnlocked();

    if (LoginSection)
    {
        LoginSection->SetVisibility(bLoggedIn ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
    }
    if (PlaySection)
    {
        PlaySection->SetVisibility(bLoggedIn ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
    else
    {
        if (JoinButton) JoinButton->SetVisibility(bLoggedIn ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
        if (AdminButton) AdminButton->SetVisibility(bLoggedIn ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
    if (AdminSection && !bLoggedIn)
    {
        AdminSection->SetVisibility(ESlateVisibility::Collapsed);
    }
    if (HostButton)
    {
        HostButton->SetVisibility(bAdminUnlocked ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
    if (AdminPasswordInput && bAdminUnlocked)
    {
        AdminPasswordInput->SetVisibility(ESlateVisibility::Collapsed);
    }
    if (UnlockAdminButton && bAdminUnlocked)
    {
        UnlockAdminButton->SetVisibility(ESlateVisibility::Collapsed);
    }
    if (LoggedInUserText && bLoggedIn)
    {
        LoggedInUserText->SetText(FText::Format(
            NSLOCTEXT("DMF", "LoggedInAsFormat", "Logged in as  {0}"),
            FText::FromString(Session->GetStagedUsername())));
    }
}

void UDMFLoginMainMenuWidget::HandleLogin()
{
    UDMFSessionSubsystem* Session = GetGameInstance() ? GetGameInstance()->GetSubsystem<UDMFSessionSubsystem>() : nullptr;
    if (!Session || !UsernameInput || !PasswordInput)
    {
        return;
    }

    FText Message;
    const bool bAccepted = Session->Login(UsernameInput->GetText().ToString(), PasswordInput->GetText().ToString(), Message);
    PasswordInput->SetText(FText::GetEmpty());
    if (bAccepted)
    {
        BP_OnLoginAccepted();
        ApplyFrontendState();
    }
    UpdateStatus(Message, !bAccepted);
}

void UDMFLoginMainMenuWidget::HandleJoin()
{
    if (UDMFSessionSubsystem* Session = GetGameInstance() ? GetGameInstance()->GetSubsystem<UDMFSessionSubsystem>() : nullptr)
    {
        FText Message;
        const bool bStarted = Session->JoinGame(Message);
        UpdateStatus(Message, !bStarted);
    }
}

void UDMFLoginMainMenuWidget::HandleAdminToggle()
{
    if (AdminSection)
    {
        const bool bShow = AdminSection->GetVisibility() == ESlateVisibility::Collapsed;
        AdminSection->SetVisibility(bShow ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
        return;
    }

    // Compatibility for Blueprint subclasses authored against the pre-v0.6 native widget contract.
    const bool bShowLegacyAdmin = AdminPasswordInput && AdminPasswordInput->GetVisibility() == ESlateVisibility::Collapsed;
    if (AdminPasswordInput) AdminPasswordInput->SetVisibility(bShowLegacyAdmin ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    if (UnlockAdminButton) UnlockAdminButton->SetVisibility(bShowLegacyAdmin ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}

void UDMFLoginMainMenuWidget::HandleUnlockAdmin()
{
    UDMFSessionSubsystem* Session = GetGameInstance() ? GetGameInstance()->GetSubsystem<UDMFSessionSubsystem>() : nullptr;
    if (!Session || !AdminPasswordInput)
    {
        return;
    }

    FText Message;
    const bool bUnlocked = Session->UnlockAdmin(AdminPasswordInput->GetText().ToString(), Message);
    AdminPasswordInput->SetText(FText::GetEmpty());
    if (bUnlocked)
    {
        BP_OnAdminUnlocked();
        ApplyFrontendState();
    }
    UpdateStatus(Message, !bUnlocked);
}

void UDMFLoginMainMenuWidget::HandleHost()
{
    if (UDMFSessionSubsystem* Session = GetGameInstance() ? GetGameInstance()->GetSubsystem<UDMFSessionSubsystem>() : nullptr)
    {
        FText Message;
        const bool bStarted = Session->HostAndPlay(Message);
        UpdateStatus(Message, !bStarted);
    }
}

void UDMFLoginMainMenuWidget::HandleLogout()
{
    if (UDMFSessionSubsystem* Session = GetGameInstance() ? GetGameInstance()->GetSubsystem<UDMFSessionSubsystem>() : nullptr)
    {
        Session->Logout();
    }
    if (UsernameInput)
    {
        UsernameInput->SetText(FText::GetEmpty());
    }
    if (PasswordInput)
    {
        PasswordInput->SetText(FText::GetEmpty());
    }
    if (AdminSection)
    {
        AdminSection->SetVisibility(ESlateVisibility::Collapsed);
    }
    ApplyFrontendState();
}

void UDMFLoginMainMenuWidget::HandleQuit()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}

void UDMFLoginMainMenuWidget::HandleExternalStatus(const FText& Message)
{
    UpdateStatus(Message);
}
