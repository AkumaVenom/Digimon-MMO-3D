#include "UI/DMFWorldNameplateWidget.h"
#include "Utility/DMFDigimonPresentationLibrary.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/ProgressBar.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Engine/World.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Game/DMFPlayerState.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFNativeUIStyle.h"

TSharedRef<SWidget> UDMFWorldNameplateWidget::RebuildWidget()
{
    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("DMFWorldNameplateTree"));
    }

    if (WidgetTree && !WidgetTree->RootWidget)
    {
        BuildNativeFallbackUI();
    }

    return Super::RebuildWidget();
}

void UDMFWorldNameplateWidget::NativeTick(const FGeometry& MyGeometry, const float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    RefreshAccumulator += FMath::Max(0.0f, InDeltaTime);
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const float RefreshInterval = Settings
        ? FMath::Clamp(Settings->WorldNameplateRefreshInterval, 0.05f, 1.0f)
        : 0.15f;

    if (RefreshAccumulator >= RefreshInterval)
    {
        RefreshAccumulator = 0.0f;
        RefreshPresentation();
    }
}

void UDMFWorldNameplateWidget::SetObservedActor(AActor* InObservedActor)
{
    ObservedActor = InObservedActor;
    RefreshAccumulator = 0.0f;
    RefreshPresentation();
}

void UDMFWorldNameplateWidget::RefreshPresentation()
{
    if (!IsValid(ObservedActor))
    {
        SetVisibility(ESlateVisibility::Collapsed);
        return;
    }

    SetVisibility(ESlateVisibility::HitTestInvisible);

    // Screen-space Widget Components stay crisp and camera-facing. Apply an explicit local camera
    // distance gate as well as the component cull distance so projects get predictable MMO clutter
    // control even if a platform treats Screen-space component culling differently.
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    float MaxDrawDistance = 0.0f;
    if (Cast<ADMFPlayerAvatarCharacter>(ObservedActor))
    {
        MaxDrawDistance = Settings ? Settings->PlayerNameplateMaxDrawDistance : 6000.0f;
    }
    else if (Cast<ADMFDigimonCharacter>(ObservedActor))
    {
        MaxDrawDistance = Settings ? Settings->DigimonNameplateMaxDrawDistance : 4500.0f;
    }

    if (MaxDrawDistance > 0.0f)
    {
        if (UWorld* World = GetWorld())
        {
            if (const APlayerController* LocalController = World->GetFirstPlayerController())
            {
                if (const APlayerCameraManager* CameraManager = LocalController->PlayerCameraManager)
                {
                    if (FVector::DistSquared(CameraManager->GetCameraLocation(), ObservedActor->GetActorLocation()) > FMath::Square(MaxDrawDistance))
                    {
                        SetRenderOpacity(0.0f);
                        return;
                    }
                }
            }
        }
    }
    SetRenderOpacity(1.0f);

    if (Cast<ADMFPlayerAvatarCharacter>(ObservedActor))
    {
        RefreshPlayerPresentation();
    }
    else if (Cast<ADMFDigimonCharacter>(ObservedActor))
    {
        RefreshDigimonPresentation();
    }
    else
    {
        SetVisibility(ESlateVisibility::Collapsed);
        return;
    }

    BP_OnNameplateRefreshed(ObservedActor);
}

void UDMFWorldNameplateWidget::BuildNativeFallbackUI()
{
    USizeBox* RootSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("WorldNameplateSize"));
    RootSize->SetWidthOverride(238.0f);
    WidgetTree->RootWidget = RootSize;

    NameplatePanel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("NameplatePanel"));
    DMFNativeUI::StylePanel(NameplatePanel, FLinearColor(0.008f, 0.020f, 0.040f, 0.88f), FMargin(7.0f, 5.0f));
    RootSize->AddChild(NameplatePanel);

    UVerticalBox* RootColumn = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("NameplateColumn"));
    NameplatePanel->AddChild(RootColumn);

    NameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("NameText"));
    DMFNativeUI::StyleText(NameText, 14, DMFNativeUI::Text(), true);
    NameText->SetJustification(ETextJustify::Center);
    if (UVerticalBoxSlot* NameRow = RootColumn->AddChildToVerticalBox(NameText))
    {
        NameRow->SetHorizontalAlignment(HAlign_Fill);
    }

    MetaText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("MetaText"));
    DMFNativeUI::StyleText(MetaText, 10, DMFNativeUI::Muted(), false);
    MetaText->SetJustification(ETextJustify::Center);
    if (UVerticalBoxSlot* MetaRow = RootColumn->AddChildToVerticalBox(MetaText))
    {
        MetaRow->SetHorizontalAlignment(HAlign_Fill);
        MetaRow->SetPadding(FMargin(0.0f, 1.0f, 0.0f, 3.0f));
    }

    DigimonVitalsBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("DigimonVitalsBox"));
    if (UVerticalBoxSlot* VitalsRow = RootColumn->AddChildToVerticalBox(DigimonVitalsBox))
    {
        VitalsRow->SetHorizontalAlignment(HAlign_Fill);
    }

    UHorizontalBox* HealthRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("HealthRow"));
    DigimonVitalsBox->AddChildToVerticalBox(HealthRow);

    USizeBox* BarSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("HealthBarSize"));
    BarSize->SetHeightOverride(8.0f);
    if (UHorizontalBoxSlot* BarRow = HealthRow->AddChildToHorizontalBox(BarSize))
    {
        BarRow->SetSize(DMFNativeUI::FillSize());
        BarRow->SetVerticalAlignment(VAlign_Center);
        BarRow->SetPadding(FMargin(0.0f, 0.0f, 7.0f, 0.0f));
    }

    HealthProgressBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("HealthProgressBar"));
    HealthProgressBar->SetFillColorAndOpacity(DMFNativeUI::Success());
    BarSize->AddChild(HealthProgressBar);

    HealthText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("HealthText"));
    DMFNativeUI::StyleText(HealthText, 9, DMFNativeUI::Text(), true);
    if (UHorizontalBoxSlot* HealthValueRow = HealthRow->AddChildToHorizontalBox(HealthText))
    {
        HealthValueRow->SetHorizontalAlignment(HAlign_Right);
        HealthValueRow->SetVerticalAlignment(VAlign_Center);
    }
}

void UDMFWorldNameplateWidget::RefreshPlayerPresentation()
{
    const ADMFPlayerAvatarCharacter* PlayerAvatar = Cast<ADMFPlayerAvatarCharacter>(ObservedActor);
    if (!PlayerAvatar)
    {
        return;
    }

    FString DisplayName;
    if (const ADMFPlayerState* PlayerState = PlayerAvatar->GetPlayerState<ADMFPlayerState>())
    {
        DisplayName = PlayerState->GetPlayerName();
    }
    if (DisplayName.IsEmpty())
    {
        DisplayName = TEXT("Player");
    }

    if (NameText)
    {
        NameText->SetText(FText::FromString(DisplayName));
        NameText->SetColorAndOpacity(FSlateColor(DMFNativeUI::Text()));
    }
    if (MetaText)
    {
        MetaText->SetVisibility(ESlateVisibility::Collapsed);
    }
    if (DigimonVitalsBox)
    {
        DigimonVitalsBox->SetVisibility(ESlateVisibility::Collapsed);
    }
}

void UDMFWorldNameplateWidget::RefreshDigimonPresentation()
{
    const ADMFDigimonCharacter* Digimon = Cast<ADMFDigimonCharacter>(ObservedActor);
    if (!Digimon)
    {
        return;
    }

    const UDMFDigimonSpeciesData* Species = Digimon->ResolveSpeciesData();
    FText DisplayName = FText::FromName(Digimon->SpeciesId.PrimaryAssetName);
    if (!Digimon->ReplicatedNickname.IsEmpty())
    {
        DisplayName = FText::FromString(Digimon->ReplicatedNickname);
    }
    else if (Species && !Species->DisplayName.IsEmpty())
    {
        DisplayName = Species->DisplayName;
    }

    if (NameText)
    {
        NameText->SetText(DisplayName);
        NameText->SetColorAndOpacity(FSlateColor(Digimon->OwningPlayerState ? DMFNativeUI::Accent() : DMFNativeUI::Text()));
    }

    const int32 Level = FMath::Max(1, Digimon->ReplicatedStats.Level);
    const UEnum* AttributeEnum = StaticEnum<EDMFDigimonAttribute>();
    const FText StageText = Species
        ? UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(Species->Stage)
        : NSLOCTEXT("DMF", "UnknownDigimonStageNameplate", "Unknown");
    const FText AttributeText = Species && AttributeEnum
        ? AttributeEnum->GetDisplayNameTextByValue(static_cast<int64>(Species->Attribute))
        : NSLOCTEXT("DMF", "UnknownDigimonAttributeNameplate", "Unknown");

    if (MetaText)
    {
        MetaText->SetVisibility(ESlateVisibility::HitTestInvisible);
        MetaText->SetText(FText::Format(
            NSLOCTEXT("DMF", "DigimonWorldNameplateMeta", "Lv.{0}  •  {1}  •  {2}"),
            FText::AsNumber(Level), StageText, AttributeText));
        MetaText->SetColorAndOpacity(FSlateColor(Species ? DMFNativeUI::Gold() : DMFNativeUI::Muted()));
    }

    if (DigimonVitalsBox)
    {
        DigimonVitalsBox->SetVisibility(ESlateVisibility::HitTestInvisible);
    }

    const int32 MaxHP = FMath::Max(1, Digimon->ReplicatedStats.MaxHP);
    const int32 CurrentHP = Digimon->CombatComponent
        ? FMath::Clamp(Digimon->CombatComponent->GetCurrentHP(), 0, MaxHP)
        : MaxHP;
    const float HealthPercent = FMath::Clamp(static_cast<float>(CurrentHP) / static_cast<float>(MaxHP), 0.0f, 1.0f);

    if (HealthProgressBar)
    {
        HealthProgressBar->SetPercent(HealthPercent);
        HealthProgressBar->SetFillColorAndOpacity(
            HealthPercent <= 0.25f ? DMFNativeUI::Danger()
            : (HealthPercent <= 0.55f ? DMFNativeUI::Gold() : DMFNativeUI::Success()));
    }

    if (HealthText)
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        const bool bShowNumericHP = !Settings || Settings->bShowDigimonNumericHealthOnNameplates;
        HealthText->SetVisibility(bShowNumericHP ? ESlateVisibility::HitTestInvisible : ESlateVisibility::Collapsed);
        if (bShowNumericHP)
        {
            HealthText->SetText(FText::Format(
                NSLOCTEXT("DMF", "DigimonWorldNameplateHP", "{0}/{1}"),
                FText::AsNumber(CurrentHP), FText::AsNumber(MaxHP)));
        }
    }
}
