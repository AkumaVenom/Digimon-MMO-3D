#include "UI/DMFPlayerSkinSelectionWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/DMFPlayerAvatarComponent.h"
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
#include "Data/DMFPlayerSkinData.h"
#include "Engine/AssetManager.h"
#include "Engine/Texture2D.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "UI/DMFNativeUIStyle.h"
#include "UI/DMFPlayerSkinEntryButton.h"

TSharedRef<SWidget> UDMFPlayerSkinSelectionWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFPlayerSkinWidgetTree"));
    }

    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }

    return Super::RebuildWidget();
}

void UDMFPlayerSkinSelectionWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ApplyPlayerSkinButton)
    {
        ApplyPlayerSkinButton->OnClicked.AddUniqueDynamic(this, &UDMFPlayerSkinSelectionWidget::HandleApplyPlayerSkin);
        ApplyPlayerSkinButton->SetIsEnabled(false);
    }

    if (ClosePlayerSkinButton)
    {
        ClosePlayerSkinButton->OnClicked.AddUniqueDynamic(this, &UDMFPlayerSkinSelectionWidget::HandleClosePlayerSkin);
    }

    if (APlayerController* OwningController = GetOwningPlayer())
    {
        if (ADMFPlayerState* FrameworkPlayerState = OwningController->GetPlayerState<ADMFPlayerState>())
        {
            if (FrameworkPlayerState->AvatarComponent)
            {
                FrameworkPlayerState->AvatarComponent->OnPlayerSkinSelectionResult.RemoveDynamic(this, &UDMFPlayerSkinSelectionWidget::HandlePlayerSkinSelectionResult);
                FrameworkPlayerState->AvatarComponent->OnPlayerSkinSelectionResult.AddDynamic(this, &UDMFPlayerSkinSelectionWidget::HandlePlayerSkinSelectionResult);

                PreviewedSkinId = FrameworkPlayerState->AvatarComponent->GetSelectedPlayerSkinId();
                if (ClosePlayerSkinButton)
                {
                    ClosePlayerSkinButton->SetIsEnabled(!FrameworkPlayerState->AvatarComponent->IsPlayerSkinSelectionRequired());
                }
            }
        }
    }

    RefreshAvailablePlayerSkins();
    if (PreviewedSkinId.IsValid())
    {
        HandlePlayerSkinPressed(PreviewedSkinId);
    }
}

void UDMFPlayerSkinSelectionWidget::NativeDestruct()
{
    if (APlayerController* OwningController = GetOwningPlayer())
    {
        if (ADMFPlayerState* FrameworkPlayerState = OwningController->GetPlayerState<ADMFPlayerState>())
        {
            if (FrameworkPlayerState->AvatarComponent)
            {
                FrameworkPlayerState->AvatarComponent->OnPlayerSkinSelectionResult.RemoveDynamic(this, &UDMFPlayerSkinSelectionWidget::HandlePlayerSkinSelectionResult);
            }
        }
    }

    Super::NativeDestruct();
}

void UDMFPlayerSkinSelectionWidget::BuildNativeFallbackUI()
{
    if (!WidgetTree)
    {
        return;
    }

    UOverlay* RootOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("PlayerSkinRootOverlay"));
    WidgetTree->RootWidget = RootOverlay;

    UBorder* BackdropBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("PlayerSkinBackdrop"));
    DMFNativeUI::StylePanel(BackdropBorder, DMFNativeUI::Backdrop(), FMargin(0.0f));
    if (UOverlaySlot* BackdropSlot = RootOverlay->AddChildToOverlay(BackdropBorder))
    {
        BackdropSlot->SetHorizontalAlignment(HAlign_Fill);
        BackdropSlot->SetVerticalAlignment(VAlign_Fill);
    }

    UScaleBox* ScreenScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("PlayerSkinScreenScale"));
    ScreenScale->SetStretch(EStretch::ScaleToFit);
    ScreenScale->SetStretchDirection(EStretchDirection::DownOnly);
    if (UOverlaySlot* ScaleSlot = RootOverlay->AddChildToOverlay(ScreenScale))
    {
        ScaleSlot->SetHorizontalAlignment(HAlign_Center);
        ScaleSlot->SetVerticalAlignment(VAlign_Center);
        ScaleSlot->SetPadding(FMargin(24.0f));
    }

    USizeBox* WindowSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("PlayerSkinWindowSize"));
    WindowSize->SetWidthOverride(1040.0f);
    WindowSize->SetHeightOverride(620.0f);
    ScreenScale->AddChild(WindowSize);

    UBorder* WindowBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("PlayerSkinWindowBorder"));
    DMFNativeUI::StylePanel(WindowBorder, DMFNativeUI::Panel(), FMargin(18.0f));
    WindowSize->AddChild(WindowBorder);

    UVerticalBox* WindowColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("PlayerSkinWindowColumn"));
    WindowBorder->AddChild(WindowColumn);

    UTextBlock* TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSkinTitle"));
    TitleText->SetText(NSLOCTEXT("DMF", "PlayerSkinTitlePolished", "SELECT CHARACTER SKIN"));
    DMFNativeUI::StyleText(TitleText, 30, DMFNativeUI::Text(), true);
    WindowColumn->AddChildToVerticalBox(TitleText);

    PlayerSkinStatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSkinStatusText"));
    PlayerSkinStatusText->SetText(NSLOCTEXT("DMF", "PlayerSkinPolishedPrompt", "Choose your avatar presentation. The server validates and saves the selected skin to your account."));
    PlayerSkinStatusText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(PlayerSkinStatusText, 14, DMFNativeUI::Muted());
    WindowColumn->AddChildToVerticalBox(PlayerSkinStatusText)->SetPadding(FMargin(0.0f, 2.0f, 0.0f, 14.0f));

    UHorizontalBox* MainRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("PlayerSkinMainRow"));
    if (UVerticalBoxSlot* MainSlot = WindowColumn->AddChildToVerticalBox(MainRow))
    {
        MainSlot->SetSize(DMFNativeUI::FillSize());
    }

    USizeBox* GridAreaSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("PlayerSkinGridAreaSize"));
    GridAreaSize->SetWidthOverride(650.0f);
    if (UHorizontalBoxSlot* GridAreaSlot = MainRow->AddChildToHorizontalBox(GridAreaSize))
    {
        GridAreaSlot->SetPadding(FMargin(0.0f, 0.0f, 14.0f, 0.0f));
        GridAreaSlot->SetVerticalAlignment(VAlign_Fill);
    }

    UBorder* GridAreaBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("PlayerSkinGridAreaBorder"));
    DMFNativeUI::StylePanel(GridAreaBorder, DMFNativeUI::PanelRaised(), FMargin(12.0f));
    GridAreaSize->AddChild(GridAreaBorder);

    UVerticalBox* GridColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("PlayerSkinGridColumn"));
    GridAreaBorder->AddChild(GridColumn);

    UTextBlock* GridHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSkinGridHeader"));
    GridHeader->SetText(NSLOCTEXT("DMF", "AvailableCharacterSkins", "AVAILABLE CHARACTERS"));
    DMFNativeUI::StyleText(GridHeader, 16, DMFNativeUI::Accent(), true);
    GridColumn->AddChildToVerticalBox(GridHeader)->SetPadding(FMargin(2.0f, 0.0f, 0.0f, 8.0f));

    UScrollBox* GridScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("PlayerSkinGridScroll"));
    if (UVerticalBoxSlot* ScrollSlot = GridColumn->AddChildToVerticalBox(GridScroll))
    {
        ScrollSlot->SetSize(DMFNativeUI::FillSize());
    }

    PlayerSkinChoicesGrid = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("PlayerSkinChoicesGrid"));
    PlayerSkinChoicesGrid->SetSlotPadding(FMargin(7.0f));
    GridScroll->AddChild(PlayerSkinChoicesGrid);

    USizeBox* DetailsAreaSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("PlayerSkinDetailsAreaSize"));
    DetailsAreaSize->SetWidthOverride(335.0f);
    MainRow->AddChildToHorizontalBox(DetailsAreaSize)->SetVerticalAlignment(VAlign_Fill);

    UBorder* DetailsBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("PlayerSkinDetailsBorder"));
    DMFNativeUI::StylePanel(DetailsBorder, DMFNativeUI::PanelRaised(), FMargin(16.0f));
    DetailsAreaSize->AddChild(DetailsBorder);

    UVerticalBox* DetailsColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("PlayerSkinDetailsColumn"));
    DetailsBorder->AddChild(DetailsColumn);

    UTextBlock* PreviewHeader = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSkinPreviewHeader"));
    PreviewHeader->SetText(NSLOCTEXT("DMF", "CharacterPreviewHeader", "CHARACTER PROFILE"));
    DMFNativeUI::StyleText(PreviewHeader, 14, DMFNativeUI::Accent(), true);
    DetailsColumn->AddChildToVerticalBox(PreviewHeader)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 8.0f));

    USizeBox* PortraitSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("PlayerSkinPortraitSize"));
    PortraitSize->SetHeightOverride(255.0f);
    DetailsColumn->AddChildToVerticalBox(PortraitSize)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 10.0f));

    UBorder* PortraitBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("PlayerSkinPortraitBorder"));
    DMFNativeUI::StylePanel(PortraitBorder, DMFNativeUI::SlotEmpty(), FMargin(5.0f));
    PortraitSize->AddChild(PortraitBorder);

    PreviewedSkinPortrait = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("PreviewedSkinPortrait"));
    PreviewedSkinPortrait->SetVisibility(ESlateVisibility::Hidden);
    PortraitBorder->AddChild(PreviewedSkinPortrait);

    PreviewedSkinNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PreviewedSkinNameText"));
    PreviewedSkinNameText->SetText(NSLOCTEXT("DMF", "NoSkinSelected", "SELECT A CHARACTER"));
    PreviewedSkinNameText->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(PreviewedSkinNameText, 24, DMFNativeUI::Text(), true);
    DetailsColumn->AddChildToVerticalBox(PreviewedSkinNameText);

    PlayerSkinDetailsText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PlayerSkinDetailsText"));
    PlayerSkinDetailsText->SetText(NSLOCTEXT("DMF", "PlayerSkinPrompt", "Choose a character card to inspect its profile."));
    PlayerSkinDetailsText->SetAutoWrapText(true);
    DMFNativeUI::StyleText(PlayerSkinDetailsText, 13, DMFNativeUI::Muted());
    if (UVerticalBoxSlot* DetailsTextSlot = DetailsColumn->AddChildToVerticalBox(PlayerSkinDetailsText))
    {
        DetailsTextSlot->SetSize(DMFNativeUI::FillSize());
        DetailsTextSlot->SetPadding(FMargin(2.0f, 8.0f));
    }

    ApplyPlayerSkinButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("ApplyPlayerSkinButton"));
    DMFNativeUI::StyleButton(ApplyPlayerSkinButton, true);
    UTextBlock* ApplyLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ApplyPlayerSkinLabel"));
    ApplyLabel->SetText(NSLOCTEXT("DMF", "ApplyPlayerSkin", "APPLY CHARACTER"));
    ApplyLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(ApplyLabel, 16, DMFNativeUI::Text(), true);
    ApplyPlayerSkinButton->AddChild(ApplyLabel);
    DetailsColumn->AddChildToVerticalBox(ApplyPlayerSkinButton)->SetPadding(FMargin(0.0f, 4.0f));

    ClosePlayerSkinButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("ClosePlayerSkinButton"));
    DMFNativeUI::StyleButton(ClosePlayerSkinButton);
    UTextBlock* CloseLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ClosePlayerSkinLabel"));
    CloseLabel->SetText(NSLOCTEXT("DMF", "ClosePlayerSkin", "CLOSE"));
    CloseLabel->SetJustification(ETextJustify::Center);
    DMFNativeUI::StyleText(CloseLabel, 14, DMFNativeUI::Text(), true);
    ClosePlayerSkinButton->AddChild(CloseLabel);
    DetailsColumn->AddChildToVerticalBox(ClosePlayerSkinButton)->SetPadding(FMargin(0.0f, 4.0f, 0.0f, 0.0f));
}

UDMFPlayerSkinData* UDMFPlayerSkinSelectionWidget::ResolveSkin(const FPrimaryAssetId SkinId) const
{
    if (!SkinId.IsValid())
    {
        return nullptr;
    }

    UAssetManager& AssetManager = UAssetManager::Get();
    if (UObject* LoadedObject = AssetManager.GetPrimaryAssetObject(SkinId))
    {
        return Cast<UDMFPlayerSkinData>(LoadedObject);
    }

    const FSoftObjectPath SkinPath = AssetManager.GetPrimaryAssetPath(SkinId);
    return SkinPath.IsValid() ? Cast<UDMFPlayerSkinData>(SkinPath.TryLoad()) : nullptr;
}

void UDMFPlayerSkinSelectionWidget::RefreshAvailablePlayerSkins()
{
    if ((!PlayerSkinChoicesGrid && !PlayerSkinChoicesBox) || !WidgetTree)
    {
        return;
    }

    if (PlayerSkinChoicesGrid)
    {
        PlayerSkinChoicesGrid->ClearChildren();
    }
    if (PlayerSkinChoicesBox)
    {
        PlayerSkinChoicesBox->ClearChildren();
    }

    TArray<FPrimaryAssetId> SkinIds;
    UAssetManager::Get().GetPrimaryAssetIdList(FPrimaryAssetType(TEXT("DMFPlayerSkin")), SkinIds, EAssetManagerFilter::Default);

    struct FResolvedSkin
    {
        FPrimaryAssetId Id;
        UDMFPlayerSkinData* Data = nullptr;
    };

    TArray<FResolvedSkin> ResolvedSkins;
    for (const FPrimaryAssetId SkinId : SkinIds)
    {
        UDMFPlayerSkinData* SkinData = ResolveSkin(SkinId);
        if (SkinData && SkinData->bEnabled)
        {
            FResolvedSkin& ResolvedEntry = ResolvedSkins.AddDefaulted_GetRef();
            ResolvedEntry.Id = SkinId;
            ResolvedEntry.Data = SkinData;
        }
    }

    ResolvedSkins.Sort([](const FResolvedSkin& SkinA, const FResolvedSkin& SkinB)
    {
        if (SkinA.Data->DisplayOrder != SkinB.Data->DisplayOrder)
        {
            return SkinA.Data->DisplayOrder < SkinB.Data->DisplayOrder;
        }
        return SkinA.Data->DisplayName.ToString() < SkinB.Data->DisplayName.ToString();
    });

    int32 VisualIndex = 0;
    for (const FResolvedSkin& ResolvedEntry : ResolvedSkins)
    {
        UDMFPlayerSkinEntryButton* SkinButton = WidgetTree->ConstructWidget<UDMFPlayerSkinEntryButton>(UDMFPlayerSkinEntryButton::StaticClass());
        SkinButton->InitializePlayerSkinChoice(ResolvedEntry.Id);
        SkinButton->OnPlayerSkinPressed.AddDynamic(this, &UDMFPlayerSkinSelectionWidget::HandlePlayerSkinPressed);
        DMFNativeUI::StyleButton(SkinButton, false, false, ResolvedEntry.Id == PreviewedSkinId);

        UOverlay* CardOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass());
        SkinButton->AddChild(CardOverlay);

        UBorder* CardBackground = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(CardBackground, DMFNativeUI::SlotEmpty(), FMargin(4.0f));
        CardOverlay->AddChildToOverlay(CardBackground);

        UTexture2D* PortraitTexture = ResolvedEntry.Data->Portrait.LoadSynchronous();
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
            PortraitSlot->SetPadding(FMargin(7.0f, 7.0f, 7.0f, 38.0f));
            PortraitSlot->SetHorizontalAlignment(HAlign_Fill);
            PortraitSlot->SetVerticalAlignment(VAlign_Fill);
        }

        if (!PortraitTexture)
        {
            UTextBlock* MissingPortraitText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            MissingPortraitText->SetText(NSLOCTEXT("DMF", "SkinPortraitMissing", "ASSIGN\nPORTRAIT"));
            MissingPortraitText->SetJustification(ETextJustify::Center);
            DMFNativeUI::StyleText(MissingPortraitText, 11, DMFNativeUI::Muted(), true);
            if (UOverlaySlot* MissingSlot = CardOverlay->AddChildToOverlay(MissingPortraitText))
            {
                MissingSlot->SetHorizontalAlignment(HAlign_Center);
                MissingSlot->SetVerticalAlignment(VAlign_Center);
                MissingSlot->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 30.0f));
            }
        }

        UBorder* NameStrip = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
        DMFNativeUI::StylePanel(NameStrip, FLinearColor(0.005f, 0.015f, 0.035f, 0.95f), FMargin(5.0f, 4.0f));
        UTextBlock* NameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
        NameText->SetText(ResolvedEntry.Data->DisplayName.IsEmpty()
            ? FText::FromName(ResolvedEntry.Data->SkinId.IsNone() ? ResolvedEntry.Data->GetFName() : ResolvedEntry.Data->SkinId)
            : ResolvedEntry.Data->DisplayName);
        NameText->SetJustification(ETextJustify::Center);
        DMFNativeUI::StyleText(NameText, 13, DMFNativeUI::Text(), true);
        NameStrip->AddChild(NameText);
        if (UOverlaySlot* NameStripSlot = CardOverlay->AddChildToOverlay(NameStrip))
        {
            NameStripSlot->SetHorizontalAlignment(HAlign_Fill);
            NameStripSlot->SetVerticalAlignment(VAlign_Bottom);
        }

        USizeBox* CardSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
        CardSize->SetWidthOverride(140.0f);
        CardSize->SetHeightOverride(185.0f);
        CardSize->AddChild(SkinButton);

        if (PlayerSkinChoicesGrid)
        {
            const int32 Row = VisualIndex / 4;
            const int32 Column = VisualIndex % 4;
            PlayerSkinChoicesGrid->AddChildToUniformGrid(CardSize, Row, Column);
        }
        else if (PlayerSkinChoicesBox)
        {
            PlayerSkinChoicesBox->AddChildToVerticalBox(SkinButton);
        }
        ++VisualIndex;
    }

    if (ResolvedSkins.IsEmpty())
    {
        const FText MissingMessage = NSLOCTEXT("DMF", "NoPlayerSkins", "No enabled DMFPlayerSkin Data Assets were discovered. Create DMFPlayerSkinData assets under the configured Asset Manager scan directory.");
        if (PlayerSkinDetailsText)
        {
            PlayerSkinDetailsText->SetText(MissingMessage);
        }
        if (PlayerSkinStatusText)
        {
            PlayerSkinStatusText->SetText(MissingMessage);
            PlayerSkinStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Danger()));
        }
    }
}

void UDMFPlayerSkinSelectionWidget::HandlePlayerSkinPressed(const FPrimaryAssetId SkinId)
{
    UDMFPlayerSkinData* SkinData = ResolveSkin(SkinId);
    if (!SkinData || !SkinData->bEnabled)
    {
        return;
    }

    PreviewedSkinId = SkinId;
    RefreshAvailablePlayerSkins();

    const FText SkinName = SkinData->DisplayName.IsEmpty()
        ? FText::FromName(SkinData->SkinId.IsNone() ? SkinData->GetFName() : SkinData->SkinId)
        : SkinData->DisplayName;

    if (PreviewedSkinNameText)
    {
        PreviewedSkinNameText->SetText(SkinName);
    }

    if (PreviewedSkinPortrait)
    {
        UTexture2D* PortraitTexture = SkinData->Portrait.LoadSynchronous();
        if (PortraitTexture)
        {
            PreviewedSkinPortrait->SetBrushFromTexture(PortraitTexture, true);
            PreviewedSkinPortrait->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            PreviewedSkinPortrait->SetVisibility(ESlateVisibility::Hidden);
        }
    }

    if (PlayerSkinDetailsText)
    {
        PlayerSkinDetailsText->SetText(SkinData->Description.IsEmpty()
            ? NSLOCTEXT("DMF", "SkinNoDescription", "No character description has been assigned yet.")
            : SkinData->Description);
    }

    if (PlayerSkinStatusText)
    {
        PlayerSkinStatusText->SetText(FText::Format(NSLOCTEXT("DMF", "SkinPreviewStatus", "Previewing {0}. Apply to save this presentation to your account."), SkinName));
        PlayerSkinStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Accent()));
    }

    if (ApplyPlayerSkinButton)
    {
        ApplyPlayerSkinButton->SetIsEnabled(!SkinData->SkeletalMesh.IsNull());
    }

    BP_OnPlayerSkinPreviewChanged(SkinData);
}

void UDMFPlayerSkinSelectionWidget::HandleApplyPlayerSkin()
{
    if (!PreviewedSkinId.IsValid())
    {
        return;
    }

    APlayerController* OwningController = GetOwningPlayer();
    ADMFPlayerState* FrameworkPlayerState = OwningController ? OwningController->GetPlayerState<ADMFPlayerState>() : nullptr;
    if (FrameworkPlayerState && FrameworkPlayerState->AvatarComponent)
    {
        if (ApplyPlayerSkinButton)
        {
            ApplyPlayerSkinButton->SetIsEnabled(false);
        }
        if (PlayerSkinStatusText)
        {
            PlayerSkinStatusText->SetText(NSLOCTEXT("DMF", "ApplyingSkinStatus", "Applying character skin through the authoritative server..."));
            PlayerSkinStatusText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Gold()));
        }
        FrameworkPlayerState->AvatarComponent->ServerSetPlayerSkin(PreviewedSkinId);
    }
}

void UDMFPlayerSkinSelectionWidget::HandleClosePlayerSkin()
{
    if (ADMFMMOPlayerController* FrameworkController = Cast<ADMFMMOPlayerController>(GetOwningPlayer()))
    {
        FrameworkController->ClosePlayerSkinSelectionUI();
    }
}

void UDMFPlayerSkinSelectionWidget::HandlePlayerSkinSelectionResult(const bool bSuccess, const FText Message, const FPrimaryAssetId SkinId)
{
    UDMFPlayerSkinData* SkinData = ResolveSkin(SkinId);
    if (PlayerSkinStatusText && !Message.IsEmpty())
    {
        PlayerSkinStatusText->SetText(Message);
        PlayerSkinStatusText->SetColorAndOpacity(FSlateColor(bSuccess ? DMFNativeUI::Success() : DMFNativeUI::Danger()));
    }
    else if (PlayerSkinDetailsText && !Message.IsEmpty())
    {
        PlayerSkinDetailsText->SetText(Message);
    }

    if (ApplyPlayerSkinButton && PreviewedSkinId.IsValid())
    {
        ApplyPlayerSkinButton->SetIsEnabled(true);
    }

    if (ClosePlayerSkinButton && bSuccess)
    {
        ClosePlayerSkinButton->SetIsEnabled(true);
    }

    BP_OnPlayerSkinSelectionResult(bSuccess, Message, SkinData);
}
