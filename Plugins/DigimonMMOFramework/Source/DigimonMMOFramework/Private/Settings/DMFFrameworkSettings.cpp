#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFLoginMainMenuWidget.h"
#include "UI/DMFStarterSelectionWidget.h"
#include "Game/DMFDigimonCarePropActor.h"
#include "UI/DMFPlayerSkinSelectionWidget.h"
#include "UI/DMFDigimonInventoryWidget.h"
#include "UI/DMFPartyQuickBarWidget.h"
#include "UI/DMFScanNotificationWidget.h"
#include "UI/DMFExperienceNotificationWidget.h"
#include "UI/DMFHomeTeleportNotificationWidget.h"
#include "UI/DMFWorldNameplateWidget.h"
#include "UI/DMFWorldChatWidget.h"
#include "UI/DMFPlayerSocialContextWidget.h"
#include "UI/DMFFriendTrackerWidget.h"
#include "Utility/DMFCredentialUtility.h"
#if WITH_EDITOR
#include "UObject/UnrealType.h"
#endif

UDMFFrameworkSettings::UDMFFrameworkSettings()
{
    LoginWidgetClass = UDMFLoginMainMenuWidget::StaticClass();
    StarterSelectionWidgetClass = UDMFStarterSelectionWidget::StaticClass();
    PlayerSkinSelectionWidgetClass = UDMFPlayerSkinSelectionWidget::StaticClass();
    DigimonInventoryWidgetClass = UDMFDigimonInventoryWidget::StaticClass();
    PartyQuickBarWidgetClass = UDMFPartyQuickBarWidget::StaticClass();
    ScanNotificationWidgetClass = UDMFScanNotificationWidget::StaticClass();
    ExperienceNotificationWidgetClass = UDMFExperienceNotificationWidget::StaticClass();
    HomeTeleportNotificationWidgetClass = UDMFHomeTeleportNotificationWidget::StaticClass();
    WorldChatWidgetClass = UDMFWorldChatWidget::StaticClass();
    PlayerSocialContextWidgetClass = UDMFPlayerSocialContextWidget::StaticClass();
    FriendTrackerWidgetClass = UDMFFriendTrackerWidget::StaticClass();
    PlayerNameplateWidgetClass = UDMFWorldNameplateWidget::StaticClass();
    DigimonNameplateWidgetClass = UDMFWorldNameplateWidget::StaticClass();
    CarePropActorClass = ADMFDigimonCarePropActor::StaticClass();
}

#if WITH_EDITOR
void UDMFFrameworkSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    const FName ChangedPropertyName = PropertyChangedEvent.GetPropertyName();
    if (ChangedPropertyName == GET_MEMBER_NAME_CHECKED(UDMFFrameworkSettings, AdminHostingPasswordInput))
    {
        if (!AdminHostingPasswordInput.IsEmpty())
        {
            if (AdminHostingPasswordInput.Len() >= 4 && AdminHostingPasswordInput.Len() <= 128)
            {
                AdminHostingPasswordDigest = UDMFCredentialUtility::HashCredential(AdminHostingPasswordInput);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Digimon MMO Framework: Admin Hosting Password must be 4-128 characters. Existing Admin password was not changed."));
            }

            // Never retain the plaintext setter value on the developer settings object/config.
            AdminHostingPasswordInput.Reset();
        }
    }

    Super::PostEditChangeProperty(PropertyChangedEvent);

    if (ChangedPropertyName == GET_MEMBER_NAME_CHECKED(UDMFFrameworkSettings, AdminHostingPasswordInput))
    {
        // Persist the hidden digest to Config/DefaultGame.ini immediately; the transient plaintext setter is never serialized.
        TryUpdateDefaultConfigFile(FString(), true);
    }
}
#endif
