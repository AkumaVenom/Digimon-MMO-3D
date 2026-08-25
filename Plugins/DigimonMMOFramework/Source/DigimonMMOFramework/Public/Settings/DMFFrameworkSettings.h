#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DMFFrameworkSettings.generated.h"

class UDMFStarterRosterData;
class UDMFLoginMainMenuWidget;
class UDMFStarterSelectionWidget;
class UDMFCombatQuickBarWidget;
class UDMFDigimonInventoryWidget;
class UDMFScanNotificationWidget;
class UDMFPlayerSkinSelectionWidget;
class UDMFPlayerSkinData;
class UWorld;

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Digimon MMO Framework"))
class DIGIMONMMOFRAMEWORK_API UDMFFrameworkSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UDMFFrameworkSettings();

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Frontend")
    TSoftObjectPtr<UWorld> FrontendMap;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="World")
    TSoftObjectPtr<UWorld> OpenWorldMap;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Onboarding")
    TSoftObjectPtr<UDMFStarterRosterData> StarterRoster;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFLoginMainMenuWidget> LoginWidgetClass;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFStarterSelectionWidget> StarterSelectionWidgetClass;

    /** Native fallback is supplied; assign a Blueprint child to reskin without replacing authority logic. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFPlayerSkinSelectionWidget> PlayerSkinSelectionWidgetClass;

    /** If true, accounts without a saved skin must choose one before starter onboarding/gameplay UI proceeds. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar")
    bool bRequirePlayerSkinSelection = true;

    /** Optional automatic skin when bRequirePlayerSkinSelection is false. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar")
    TSoftObjectPtr<UDMFPlayerSkinData> DefaultPlayerSkin;

    /** Ready-to-use F6 menu toggle. Disable when the project wants to open the menu from its own UI/input. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar")
    bool bEnableDefaultPlayerSkinMenuInput = true;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Account")
    FString AccountSaveSlot = TEXT("DMF_ServerAccounts");

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Account")
    bool bAutoRegisterUnknownAccounts = true;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Inventory", meta=(ClampMin="1"))
    int32 MaxActiveDigimonInventory = 30;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Inventory", meta=(ClampMin="1"))
    int32 MaxDigimonBankStorage = 200;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Partner")
    FVector PartnerSpawnOffset = FVector(150.0, 120.0, 0.0);


    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFCombatQuickBarWidget> CombatQuickBarWidgetClass;

    /** Native roster/partner menu fallback; assign a Blueprint child to fully reskin it. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFDigimonInventoryWidget> DigimonInventoryWidgetClass;

    /** Ready-to-use I-key toggle for the tabbed Digimon menu. Disable for project-owned input. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    bool bEnableDefaultDigimonInventoryMenuInput = true;

    /** Native scan reward toast fallback; assign a Blueprint child to fully reskin it. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFScanNotificationWidget> ScanNotificationWidgetClass;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    bool bShowNativeScanNotifications = true;

    /** Master switch for the persistent Scan Data / Materialization system. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Scan & Materialization")
    bool bEnableScanAndMaterialization = true;

    /** Default MMO rule: only framework Wild Digimon victories award Scan Data. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Scan & Materialization")
    bool bAwardScanDataFromWildVictoriesOnly = true;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat")
    bool bShowNativeCombatQuickBar = true;

    /** Master switch for the framework's legacy/default controller combat bindings. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Input")
    bool bEnableDefaultCombatInputBindings = true;

    /** Legacy Left-Mouse target selection. Disabled by default in v0.5.2 because player Interact/E is the preferred target flow. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Input")
    bool bEnableDefaultClickTargetInput = false;

    /** Ready-to-use number-key ability commands (1-4). Keep enabled when using E/Interact for target selection. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Input")
    bool bEnableDefaultAbilitySlotInput = true;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat")
    FName PlayerCombatTeamId = TEXT("Players");

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0.1"))
    float CombatAutomationInterval = 0.25f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0.0"))
    float MinimumCombatCommandInterval = 0.05f;

    /** Maximum time an out-of-range player ability command may remain queued while the partner chases. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0.5"))
    float CombatCommandQueueTimeout = 8.0f;

    /** Owned partners never auto-acquire/auto-attack by default. Manual Blueprint/quick-slot commands still chase and execute. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner")
    bool bPlayerPartnerAutoBattle = false;

    /** Used only when player-partner auto battle is deliberately enabled at runtime/project level. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner", meta=(ClampMin="0.0"))
    float PartnerAggroRange = 1200.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner", meta=(ClampMin="0.0"))
    float PartnerLeashRange = 2500.0f;

    /** Player-owned partner damage multiplier. 1.50 gives an intentional MMORPG/JRPG advantage over equal-level wild encounters. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner|Balance", meta=(ClampMin="0.0"))
    float PlayerPartnerOutgoingDamageMultiplier = 1.50f;

    /** Incoming combat damage multiplier for player-owned partners. 0.50 means they take half normal Digimon combat damage. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner|Balance", meta=(ClampMin="0.0"))
    float PlayerPartnerIncomingDamageMultiplier = 0.50f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Persistence", meta=(ClampMin="5.0"))
    float AccountAutosaveInterval = 30.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Networking", meta=(ClampMin="1", ClampMax="65535"))
    int32 GamePort = 7777;
};
