#include "Settings/DMFFrameworkSettings.h"
#include "UI/DMFLoginMainMenuWidget.h"
#include "UI/DMFStarterSelectionWidget.h"
#include "Game/DMFDigimonCarePropActor.h"
#include "UI/DMFPlayerSkinSelectionWidget.h"
#include "UI/DMFDigimonInventoryWidget.h"
#include "UI/DMFScanNotificationWidget.h"

UDMFFrameworkSettings::UDMFFrameworkSettings()
{
    LoginWidgetClass = UDMFLoginMainMenuWidget::StaticClass();
    StarterSelectionWidgetClass = UDMFStarterSelectionWidget::StaticClass();
    PlayerSkinSelectionWidgetClass = UDMFPlayerSkinSelectionWidget::StaticClass();
    DigimonInventoryWidgetClass = UDMFDigimonInventoryWidget::StaticClass();
    ScanNotificationWidgetClass = UDMFScanNotificationWidget::StaticClass();
    CarePropActorClass = ADMFDigimonCarePropActor::StaticClass();
}
