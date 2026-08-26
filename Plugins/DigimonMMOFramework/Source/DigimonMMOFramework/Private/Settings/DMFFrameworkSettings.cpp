#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFLoginMainMenuWidget.h"
#include "UI/DMFStarterSelectionWidget.h"
#include "Game/DMFDigimonCarePropActor.h"
#include "UI/DMFPlayerSkinSelectionWidget.h"
#include "UI/DMFDigimonInventoryWidget.h"
#include "UI/DMFScanNotificationWidget.h"
#include "UI/DMFWorldNameplateWidget.h"
#include "UI/DMFWorldChatWidget.h"

UDMFFrameworkSettings::UDMFFrameworkSettings()
{
    LoginWidgetClass = UDMFLoginMainMenuWidget::StaticClass();
    StarterSelectionWidgetClass = UDMFStarterSelectionWidget::StaticClass();
    PlayerSkinSelectionWidgetClass = UDMFPlayerSkinSelectionWidget::StaticClass();
    DigimonInventoryWidgetClass = UDMFDigimonInventoryWidget::StaticClass();
    ScanNotificationWidgetClass = UDMFScanNotificationWidget::StaticClass();
    WorldChatWidgetClass = UDMFWorldChatWidget::StaticClass();
    PlayerNameplateWidgetClass = UDMFWorldNameplateWidget::StaticClass();
    DigimonNameplateWidgetClass = UDMFWorldNameplateWidget::StaticClass();
    CarePropActorClass = ADMFDigimonCarePropActor::StaticClass();
}
