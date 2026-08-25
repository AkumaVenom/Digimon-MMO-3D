// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/DMFFrameworkSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFFrameworkSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UWorld(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFFrameworkSettings(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFCombatQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCarePropActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFFrameworkSettings(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFLoginMainMenuWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFScanNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterRosterData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldNameplateWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFFrameworkSettings ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFFrameworkSettings_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "DisplayName", "Digimon MMO Framework" },
		{ "IncludePath", "Settings/DMFFrameworkSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrontendMap_MetaData[] = {
		{ "Category", "Frontend" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenWorldMap_MetaData[] = {
		{ "Category", "World" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarterRoster_MetaData[] = {
		{ "Category", "Onboarding" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarterSelectionWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSkinSelectionWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native fallback is supplied; assign a Blueprint child to reskin without replacing authority logic. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native fallback is supplied; assign a Blueprint child to reskin without replacing authority logic." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequirePlayerSkinSelection_MetaData[] = {
		{ "Category", "Player Avatar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, accounts without a saved skin must choose one before starter onboarding/gameplay UI proceeds. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, accounts without a saved skin must choose one before starter onboarding/gameplay UI proceeds." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPlayerSkin_MetaData[] = {
		{ "Category", "Player Avatar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional automatic skin when bRequirePlayerSkinSelection is false. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional automatic skin when bRequirePlayerSkinSelection is false." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDefaultPlayerSkinMenuInput_MetaData[] = {
		{ "Category", "Player Avatar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ready-to-use F6 menu toggle. Disable when the project wants to open the menu from its own UI/input. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ready-to-use F6 menu toggle. Disable when the project wants to open the menu from its own UI/input." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccountSaveSlot_MetaData[] = {
		{ "Category", "Account" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoRegisterUnknownAccounts_MetaData[] = {
		{ "Category", "Account" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxActiveDigimonInventory_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDigimonBankStorage_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartnerSpawnOffset_MetaData[] = {
		{ "Category", "Partner" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatQuickBarWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonInventoryWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native roster/partner menu fallback; assign a Blueprint child to fully reskin it. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native roster/partner menu fallback; assign a Blueprint child to fully reskin it." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDefaultDigimonInventoryMenuInput_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ready-to-use I-key toggle for the tabbed Digimon menu. Disable for project-owned input. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ready-to-use I-key toggle for the tabbed Digimon menu. Disable for project-owned input." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanNotificationWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native scan reward toast fallback; assign a Blueprint child to fully reskin it. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native scan reward toast fallback; assign a Blueprint child to fully reskin it." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowNativeScanNotifications_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableWorldNameplates_MetaData[] = {
		{ "Category", "UI|World Nameplates" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for all automatic world-space MMO nameplates. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for all automatic world-space MMO nameplates." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnablePlayerNameplates_MetaData[] = {
		{ "Category", "UI|World Nameplates|Players" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Show authenticated player usernames above replicated player avatars. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show authenticated player usernames above replicated player avatars." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowLocalPlayerNameplate_MetaData[] = {
		{ "Category", "UI|World Nameplates|Players" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local players normally do not need their own overhead username. Enable for debugging/specific MMO presentation. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates && bEnablePlayerNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local players normally do not need their own overhead username. Enable for debugging/specific MMO presentation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerNameplateMaxDrawDistance_MetaData[] = {
		{ "Category", "UI|World Nameplates|Players" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum camera distance at which player nameplates render. Zero disables distance culling. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates && bEnablePlayerNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum camera distance at which player nameplates render. Zero disables distance culling." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerNameplateHeightOffset_MetaData[] = {
		{ "Category", "UI|World Nameplates|Players" },
		{ "ClampMax", "500.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Additional height above the avatar collision capsule. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates && bEnablePlayerNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Additional height above the avatar collision capsule." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerNameplateWidgetClass_MetaData[] = {
		{ "Category", "UI|World Nameplates|Players" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native fallback is supplied; assign a Blueprint child to reskin player plates without replacing actor/network logic. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates && bEnablePlayerNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native fallback is supplied; assign a Blueprint child to reskin player plates without replacing actor/network logic." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDigimonNameplates_MetaData[] = {
		{ "Category", "UI|World Nameplates|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Show compact Digimon name/level/type/health plates above owned and wild Digimon. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show compact Digimon name/level/type/health plates above owned and wild Digimon." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonNameplateMaxDrawDistance_MetaData[] = {
		{ "Category", "UI|World Nameplates|Digimon" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum camera distance at which Digimon nameplates render. Zero disables distance culling. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates && bEnableDigimonNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum camera distance at which Digimon nameplates render. Zero disables distance culling." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonNameplateHeightOffset_MetaData[] = {
		{ "Category", "UI|World Nameplates|Digimon" },
		{ "ClampMax", "500.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Additional height above each Digimon collision capsule, allowing differently sized species to position cleanly. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates && bEnableDigimonNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Additional height above each Digimon collision capsule, allowing differently sized species to position cleanly." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDigimonNumericHealthOnNameplates_MetaData[] = {
		{ "Category", "UI|World Nameplates|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keep the health readout compact: disable this to show only the slim health bar. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates && bEnableDigimonNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keep the health readout compact: disable this to show only the slim health bar." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonNameplateWidgetClass_MetaData[] = {
		{ "Category", "UI|World Nameplates|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native fallback is supplied; assign a Blueprint child to reskin Digimon plates without replacing combat/network logic. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates && bEnableDigimonNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native fallback is supplied; assign a Blueprint child to reskin Digimon plates without replacing combat/network logic." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldNameplateRefreshInterval_MetaData[] = {
		{ "Category", "UI|World Nameplates|Performance" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.05" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Throttled presentation refresh interval. Actor state itself continues to replicate at its normal framework cadence. */" },
#endif
		{ "EditCondition", "bEnableWorldNameplates" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Throttled presentation refresh interval. Actor state itself continues to replicate at its normal framework cadence." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableScanAndMaterialization_MetaData[] = {
		{ "Category", "Scan & Materialization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for the persistent Scan Data / Materialization system. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for the persistent Scan Data / Materialization system." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAwardScanDataFromWildVictoriesOnly_MetaData[] = {
		{ "Category", "Scan & Materialization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default MMO rule: only framework Wild Digimon victories award Scan Data. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default MMO rule: only framework Wild Digimon victories award Scan Data." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableCareSystem_MetaData[] = {
		{ "Category", "Care" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for persistent virtual-pet care, feeding and world waste. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for persistent virtual-pet care, feeding and world waste." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareServerTickInterval_MetaData[] = {
		{ "Category", "Care" },
		{ "ClampMax", "60.0" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authoritative care maintenance cadence. Hunger decay uses UTC deltas, so this does not affect progression accuracy. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authoritative care maintenance cadence. Hunger decay uses UTC deltas, so this does not affect progression accuracy." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CarePresentationLeadInSeconds_MetaData[] = {
		{ "Category", "Care|Feeding" },
		{ "ClampMax", "5.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Small delay after the owner UI is hidden before the first eating Montage begins. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Small delay after the owner UI is hidden before the first eating Montage begins." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareInterServingPauseSeconds_MetaData[] = {
		{ "Category", "Care|Feeding" },
		{ "ClampMax", "5.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pause between complete DigiMeat servings while Feed Until Full is looping. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pause between complete DigiMeat servings while Feed Until Full is looping." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareFallbackMontageDurationSeconds_MetaData[] = {
		{ "Category", "Care|Feeding" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Used only when a feeding Montage is assigned but returns an unusable duration. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Used only when a feeding Montage is assigned but returns an unusable duration." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDigiMeatMesh_MetaData[] = {
		{ "Category", "Care|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Global DigiMeat mesh. A species can override this while keeping its own socket transform/scale. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global DigiMeat mesh. A species can override this while keeping its own socket transform/scale." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPooMesh_MetaData[] = {
		{ "Category", "Care|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Global poo mesh. A species can override this and always controls its own world scale. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global poo mesh. A species can override this and always controls its own world scale." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CarePropActorClass_MetaData[] = {
		{ "Category", "Care|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint-replaceable replicated prop actor used for both attached DigiMeat and no-collision world poo. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint-replaceable replicated prop actor used for both attached DigiMeat and no-collision world poo." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowNativeCombatQuickBar_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDefaultCombatInputBindings_MetaData[] = {
		{ "Category", "Combat|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for the framework's legacy/default controller combat bindings. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for the framework's legacy/default controller combat bindings." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDefaultClickTargetInput_MetaData[] = {
		{ "Category", "Combat|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy Left-Mouse target selection. Disabled by default in v0.5.2 because player Interact/E is the preferred target flow. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy Left-Mouse target selection. Disabled by default in v0.5.2 because player Interact/E is the preferred target flow." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDefaultAbilitySlotInput_MetaData[] = {
		{ "Category", "Combat|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ready-to-use number-key ability commands (1-4). Keep enabled when using E/Interact for target selection. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ready-to-use number-key ability commands (1-4). Keep enabled when using E/Interact for target selection." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCombatTeamId_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatAutomationInterval_MetaData[] = {
		{ "Category", "Combat" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumCombatCommandInterval_MetaData[] = {
		{ "Category", "Combat" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatCommandQueueTimeout_MetaData[] = {
		{ "Category", "Combat" },
		{ "ClampMin", "0.5" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum time an out-of-range player ability command may remain queued while the partner chases. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum time an out-of-range player ability command may remain queued while the partner chases." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPlayerPartnerAutoBattle_MetaData[] = {
		{ "Category", "Combat|Player Partner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Owned partners never auto-acquire/auto-attack by default. Manual Blueprint/quick-slot commands still chase and execute. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owned partners never auto-acquire/auto-attack by default. Manual Blueprint/quick-slot commands still chase and execute." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartnerAggroRange_MetaData[] = {
		{ "Category", "Combat|Player Partner" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Used only when player-partner auto battle is deliberately enabled at runtime/project level. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Used only when player-partner auto battle is deliberately enabled at runtime/project level." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartnerLeashRange_MetaData[] = {
		{ "Category", "Combat|Player Partner" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerPartnerOutgoingDamageMultiplier_MetaData[] = {
		{ "Category", "Combat|Player Partner|Balance" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Player-owned partner damage multiplier. 1.50 gives an intentional MMORPG/JRPG advantage over equal-level wild encounters. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player-owned partner damage multiplier. 1.50 gives an intentional MMORPG/JRPG advantage over equal-level wild encounters." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerPartnerIncomingDamageMultiplier_MetaData[] = {
		{ "Category", "Combat|Player Partner|Balance" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Incoming combat damage multiplier for player-owned partners. 0.50 means they take half normal Digimon combat damage. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Incoming combat damage multiplier for player-owned partners. 0.50 means they take half normal Digimon combat damage." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccountAutosaveInterval_MetaData[] = {
		{ "Category", "Persistence" },
		{ "ClampMin", "5.0" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GamePort_MetaData[] = {
		{ "Category", "Networking" },
		{ "ClampMax", "65535" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFFrameworkSettings constinit property declarations ********************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_FrontendMap;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_OpenWorldMap;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_StarterRoster;
	static const UECodeGen_Private::FClassPropertyParams NewProp_LoginWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_StarterSelectionWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerSkinSelectionWidgetClass;
	static void NewProp_bRequirePlayerSkinSelection_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bRequirePlayerSkinSelection = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequirePlayerSkinSelection;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultPlayerSkin;
	static void NewProp_bEnableDefaultPlayerSkinMenuInput_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDefaultPlayerSkinMenuInput = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDefaultPlayerSkinMenuInput;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AccountSaveSlot;
	static void NewProp_bAutoRegisterUnknownAccounts_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bAutoRegisterUnknownAccounts = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoRegisterUnknownAccounts;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxActiveDigimonInventory;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDigimonBankStorage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PartnerSpawnOffset;
	static const UECodeGen_Private::FClassPropertyParams NewProp_CombatQuickBarWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_DigimonInventoryWidgetClass;
	static void NewProp_bEnableDefaultDigimonInventoryMenuInput_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDefaultDigimonInventoryMenuInput = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDefaultDigimonInventoryMenuInput;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ScanNotificationWidgetClass;
	static void NewProp_bShowNativeScanNotifications_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowNativeScanNotifications = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowNativeScanNotifications;
	static void NewProp_bEnableWorldNameplates_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableWorldNameplates = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableWorldNameplates;
	static void NewProp_bEnablePlayerNameplates_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnablePlayerNameplates = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnablePlayerNameplates;
	static void NewProp_bShowLocalPlayerNameplate_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowLocalPlayerNameplate = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowLocalPlayerNameplate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerNameplateMaxDrawDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerNameplateHeightOffset;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerNameplateWidgetClass;
	static void NewProp_bEnableDigimonNameplates_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDigimonNameplates = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDigimonNameplates;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DigimonNameplateMaxDrawDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DigimonNameplateHeightOffset;
	static void NewProp_bShowDigimonNumericHealthOnNameplates_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowDigimonNumericHealthOnNameplates = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDigimonNumericHealthOnNameplates;
	static const UECodeGen_Private::FClassPropertyParams NewProp_DigimonNameplateWidgetClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldNameplateRefreshInterval;
	static void NewProp_bEnableScanAndMaterialization_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableScanAndMaterialization = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableScanAndMaterialization;
	static void NewProp_bAwardScanDataFromWildVictoriesOnly_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bAwardScanDataFromWildVictoriesOnly = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAwardScanDataFromWildVictoriesOnly;
	static void NewProp_bEnableCareSystem_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableCareSystem = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableCareSystem;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CareServerTickInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CarePresentationLeadInSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CareInterServingPauseSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CareFallbackMontageDurationSeconds;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultDigiMeatMesh;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultPooMesh;
	static const UECodeGen_Private::FClassPropertyParams NewProp_CarePropActorClass;
	static void NewProp_bShowNativeCombatQuickBar_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowNativeCombatQuickBar = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowNativeCombatQuickBar;
	static void NewProp_bEnableDefaultCombatInputBindings_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDefaultCombatInputBindings = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDefaultCombatInputBindings;
	static void NewProp_bEnableDefaultClickTargetInput_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDefaultClickTargetInput = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDefaultClickTargetInput;
	static void NewProp_bEnableDefaultAbilitySlotInput_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDefaultAbilitySlotInput = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDefaultAbilitySlotInput;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PlayerCombatTeamId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CombatAutomationInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumCombatCommandInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CombatCommandQueueTimeout;
	static void NewProp_bPlayerPartnerAutoBattle_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bPlayerPartnerAutoBattle = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlayerPartnerAutoBattle;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PartnerAggroRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PartnerLeashRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerPartnerOutgoingDamageMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerPartnerIncomingDamageMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AccountAutosaveInterval;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GamePort;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFFrameworkSettings constinit property declarations **********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFFrameworkSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFFrameworkSettings Property Definitions *******************************
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_FrontendMap = { "FrontendMap", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, FrontendMap), Z_Construct_UClass_UWorld, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrontendMap_MetaData), NewProp_FrontendMap_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_OpenWorldMap = { "OpenWorldMap", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, OpenWorldMap), Z_Construct_UClass_UWorld, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenWorldMap_MetaData), NewProp_OpenWorldMap_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_StarterRoster = { "StarterRoster", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, StarterRoster), Z_Construct_UClass_UDMFStarterRosterData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarterRoster_MetaData), NewProp_StarterRoster_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_LoginWidgetClass = { "LoginWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, LoginWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFLoginMainMenuWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginWidgetClass_MetaData), NewProp_LoginWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_StarterSelectionWidgetClass = { "StarterSelectionWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, StarterSelectionWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFStarterSelectionWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarterSelectionWidgetClass_MetaData), NewProp_StarterSelectionWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_PlayerSkinSelectionWidgetClass = { "PlayerSkinSelectionWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerSkinSelectionWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSkinSelectionWidgetClass_MetaData), NewProp_PlayerSkinSelectionWidgetClass_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequirePlayerSkinSelection = { "bRequirePlayerSkinSelection", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bRequirePlayerSkinSelection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequirePlayerSkinSelection_MetaData), NewProp_bRequirePlayerSkinSelection_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_DefaultPlayerSkin = { "DefaultPlayerSkin", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DefaultPlayerSkin), Z_Construct_UClass_UDMFPlayerSkinData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPlayerSkin_MetaData), NewProp_DefaultPlayerSkin_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDefaultPlayerSkinMenuInput = { "bEnableDefaultPlayerSkinMenuInput", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDefaultPlayerSkinMenuInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDefaultPlayerSkinMenuInput_MetaData), NewProp_bEnableDefaultPlayerSkinMenuInput_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_AccountSaveSlot = { "AccountSaveSlot", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, AccountSaveSlot), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccountSaveSlot_MetaData), NewProp_AccountSaveSlot_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAutoRegisterUnknownAccounts = { "bAutoRegisterUnknownAccounts", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bAutoRegisterUnknownAccounts_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoRegisterUnknownAccounts_MetaData), NewProp_bAutoRegisterUnknownAccounts_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxActiveDigimonInventory = { "MaxActiveDigimonInventory", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, MaxActiveDigimonInventory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxActiveDigimonInventory_MetaData), NewProp_MaxActiveDigimonInventory_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxDigimonBankStorage = { "MaxDigimonBankStorage", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, MaxDigimonBankStorage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDigimonBankStorage_MetaData), NewProp_MaxDigimonBankStorage_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PartnerSpawnOffset = { "PartnerSpawnOffset", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PartnerSpawnOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartnerSpawnOffset_MetaData), NewProp_PartnerSpawnOffset_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_CombatQuickBarWidgetClass = { "CombatQuickBarWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, CombatQuickBarWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFCombatQuickBarWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatQuickBarWidgetClass_MetaData), NewProp_CombatQuickBarWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_DigimonInventoryWidgetClass = { "DigimonInventoryWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DigimonInventoryWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFDigimonInventoryWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonInventoryWidgetClass_MetaData), NewProp_DigimonInventoryWidgetClass_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDefaultDigimonInventoryMenuInput = { "bEnableDefaultDigimonInventoryMenuInput", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDefaultDigimonInventoryMenuInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDefaultDigimonInventoryMenuInput_MetaData), NewProp_bEnableDefaultDigimonInventoryMenuInput_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_ScanNotificationWidgetClass = { "ScanNotificationWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, ScanNotificationWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFScanNotificationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanNotificationWidgetClass_MetaData), NewProp_ScanNotificationWidgetClass_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowNativeScanNotifications = { "bShowNativeScanNotifications", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowNativeScanNotifications_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowNativeScanNotifications_MetaData), NewProp_bShowNativeScanNotifications_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableWorldNameplates = { "bEnableWorldNameplates", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableWorldNameplates_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableWorldNameplates_MetaData), NewProp_bEnableWorldNameplates_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnablePlayerNameplates = { "bEnablePlayerNameplates", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnablePlayerNameplates_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnablePlayerNameplates_MetaData), NewProp_bEnablePlayerNameplates_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowLocalPlayerNameplate = { "bShowLocalPlayerNameplate", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowLocalPlayerNameplate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowLocalPlayerNameplate_MetaData), NewProp_bShowLocalPlayerNameplate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerNameplateMaxDrawDistance = { "PlayerNameplateMaxDrawDistance", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerNameplateMaxDrawDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerNameplateMaxDrawDistance_MetaData), NewProp_PlayerNameplateMaxDrawDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerNameplateHeightOffset = { "PlayerNameplateHeightOffset", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerNameplateHeightOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerNameplateHeightOffset_MetaData), NewProp_PlayerNameplateHeightOffset_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_PlayerNameplateWidgetClass = { "PlayerNameplateWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerNameplateWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFWorldNameplateWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerNameplateWidgetClass_MetaData), NewProp_PlayerNameplateWidgetClass_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDigimonNameplates = { "bEnableDigimonNameplates", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDigimonNameplates_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDigimonNameplates_MetaData), NewProp_bEnableDigimonNameplates_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DigimonNameplateMaxDrawDistance = { "DigimonNameplateMaxDrawDistance", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DigimonNameplateMaxDrawDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonNameplateMaxDrawDistance_MetaData), NewProp_DigimonNameplateMaxDrawDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DigimonNameplateHeightOffset = { "DigimonNameplateHeightOffset", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DigimonNameplateHeightOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonNameplateHeightOffset_MetaData), NewProp_DigimonNameplateHeightOffset_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowDigimonNumericHealthOnNameplates = { "bShowDigimonNumericHealthOnNameplates", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowDigimonNumericHealthOnNameplates_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDigimonNumericHealthOnNameplates_MetaData), NewProp_bShowDigimonNumericHealthOnNameplates_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_DigimonNameplateWidgetClass = { "DigimonNameplateWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DigimonNameplateWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFWorldNameplateWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonNameplateWidgetClass_MetaData), NewProp_DigimonNameplateWidgetClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_WorldNameplateRefreshInterval = { "WorldNameplateRefreshInterval", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, WorldNameplateRefreshInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldNameplateRefreshInterval_MetaData), NewProp_WorldNameplateRefreshInterval_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableScanAndMaterialization = { "bEnableScanAndMaterialization", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableScanAndMaterialization_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableScanAndMaterialization_MetaData), NewProp_bEnableScanAndMaterialization_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAwardScanDataFromWildVictoriesOnly = { "bAwardScanDataFromWildVictoriesOnly", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bAwardScanDataFromWildVictoriesOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAwardScanDataFromWildVictoriesOnly_MetaData), NewProp_bAwardScanDataFromWildVictoriesOnly_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableCareSystem = { "bEnableCareSystem", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableCareSystem_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableCareSystem_MetaData), NewProp_bEnableCareSystem_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CareServerTickInterval = { "CareServerTickInterval", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, CareServerTickInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareServerTickInterval_MetaData), NewProp_CareServerTickInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CarePresentationLeadInSeconds = { "CarePresentationLeadInSeconds", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, CarePresentationLeadInSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CarePresentationLeadInSeconds_MetaData), NewProp_CarePresentationLeadInSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CareInterServingPauseSeconds = { "CareInterServingPauseSeconds", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, CareInterServingPauseSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareInterServingPauseSeconds_MetaData), NewProp_CareInterServingPauseSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CareFallbackMontageDurationSeconds = { "CareFallbackMontageDurationSeconds", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, CareFallbackMontageDurationSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareFallbackMontageDurationSeconds_MetaData), NewProp_CareFallbackMontageDurationSeconds_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_DefaultDigiMeatMesh = { "DefaultDigiMeatMesh", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DefaultDigiMeatMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDigiMeatMesh_MetaData), NewProp_DefaultDigiMeatMesh_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_DefaultPooMesh = { "DefaultPooMesh", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DefaultPooMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPooMesh_MetaData), NewProp_DefaultPooMesh_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_CarePropActorClass = { "CarePropActorClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, CarePropActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ADMFDigimonCarePropActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CarePropActorClass_MetaData), NewProp_CarePropActorClass_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowNativeCombatQuickBar = { "bShowNativeCombatQuickBar", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowNativeCombatQuickBar_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowNativeCombatQuickBar_MetaData), NewProp_bShowNativeCombatQuickBar_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDefaultCombatInputBindings = { "bEnableDefaultCombatInputBindings", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDefaultCombatInputBindings_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDefaultCombatInputBindings_MetaData), NewProp_bEnableDefaultCombatInputBindings_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDefaultClickTargetInput = { "bEnableDefaultClickTargetInput", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDefaultClickTargetInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDefaultClickTargetInput_MetaData), NewProp_bEnableDefaultClickTargetInput_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDefaultAbilitySlotInput = { "bEnableDefaultAbilitySlotInput", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDefaultAbilitySlotInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDefaultAbilitySlotInput_MetaData), NewProp_bEnableDefaultAbilitySlotInput_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_PlayerCombatTeamId = { "PlayerCombatTeamId", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerCombatTeamId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCombatTeamId_MetaData), NewProp_PlayerCombatTeamId_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CombatAutomationInterval = { "CombatAutomationInterval", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, CombatAutomationInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatAutomationInterval_MetaData), NewProp_CombatAutomationInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumCombatCommandInterval = { "MinimumCombatCommandInterval", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, MinimumCombatCommandInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumCombatCommandInterval_MetaData), NewProp_MinimumCombatCommandInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CombatCommandQueueTimeout = { "CombatCommandQueueTimeout", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, CombatCommandQueueTimeout), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatCommandQueueTimeout_MetaData), NewProp_CombatCommandQueueTimeout_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPlayerPartnerAutoBattle = { "bPlayerPartnerAutoBattle", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bPlayerPartnerAutoBattle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPlayerPartnerAutoBattle_MetaData), NewProp_bPlayerPartnerAutoBattle_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PartnerAggroRange = { "PartnerAggroRange", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PartnerAggroRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartnerAggroRange_MetaData), NewProp_PartnerAggroRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PartnerLeashRange = { "PartnerLeashRange", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PartnerLeashRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartnerLeashRange_MetaData), NewProp_PartnerLeashRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerPartnerOutgoingDamageMultiplier = { "PlayerPartnerOutgoingDamageMultiplier", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerPartnerOutgoingDamageMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerPartnerOutgoingDamageMultiplier_MetaData), NewProp_PlayerPartnerOutgoingDamageMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerPartnerIncomingDamageMultiplier = { "PlayerPartnerIncomingDamageMultiplier", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerPartnerIncomingDamageMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerPartnerIncomingDamageMultiplier_MetaData), NewProp_PlayerPartnerIncomingDamageMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AccountAutosaveInterval = { "AccountAutosaveInterval", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, AccountAutosaveInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccountAutosaveInterval_MetaData), NewProp_AccountAutosaveInterval_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_GamePort = { "GamePort", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, GamePort), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GamePort_MetaData), NewProp_GamePort_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FrontendMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OpenWorldMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StarterRoster,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LoginWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StarterSelectionWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSkinSelectionWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequirePlayerSkinSelection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultPlayerSkin,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDefaultPlayerSkinMenuInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AccountSaveSlot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAutoRegisterUnknownAccounts,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxActiveDigimonInventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxDigimonBankStorage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartnerSpawnOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatQuickBarWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInventoryWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDefaultDigimonInventoryMenuInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanNotificationWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowNativeScanNotifications,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableWorldNameplates,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnablePlayerNameplates,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowLocalPlayerNameplate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerNameplateMaxDrawDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerNameplateHeightOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerNameplateWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDigimonNameplates,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonNameplateMaxDrawDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonNameplateHeightOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowDigimonNumericHealthOnNameplates,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonNameplateWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldNameplateRefreshInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableScanAndMaterialization,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAwardScanDataFromWildVictoriesOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableCareSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareServerTickInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CarePresentationLeadInSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareInterServingPauseSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareFallbackMontageDurationSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultDigiMeatMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultPooMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CarePropActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowNativeCombatQuickBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDefaultCombatInputBindings,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDefaultClickTargetInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDefaultAbilitySlotInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerCombatTeamId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatAutomationInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumCombatCommandInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatCommandQueueTimeout,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPlayerPartnerAutoBattle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartnerAggroRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartnerLeashRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerPartnerOutgoingDamageMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerPartnerIncomingDamageMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AccountAutosaveInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GamePort,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFFrameworkSettings Property Definitions *********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UDeveloperSettings,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFFrameworkSettings,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFFrameworkSettings;
UClass* Z_Construct_UClass_UDMFFrameworkSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFFrameworkSettings;
		if (!Z_Registration_Info_UClass_UDMFFrameworkSettings.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFFrameworkSettings"),
				Z_Registration_Info_UClass_UDMFFrameworkSettings.InnerSingleton,
				nullptr,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UDMFFrameworkSettings.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFFrameworkSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFFrameworkSettings.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFFrameworkSettings.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFFrameworkSettings);
UDMFFrameworkSettings::~UDMFFrameworkSettings() {}
// ********** End Class UDMFFrameworkSettings ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Settings_DMFFrameworkSettings_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFFrameworkSettings, TEXT("UDMFFrameworkSettings"), &Z_Registration_Info_UClass_UDMFFrameworkSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFFrameworkSettings), 1079031704U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Settings_DMFFrameworkSettings_h__Script_DigimonMMOFramework_3927f1f060376ac76cbba719bd779d80727df0d7{
	TEXT("/Script/DigimonMMOFramework"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
