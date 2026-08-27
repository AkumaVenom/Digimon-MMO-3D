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
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UParticleSystem(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USoundBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UWorld(ETypeConstructPhase);
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem(ETypeConstructPhase);
PAPER2D_API UClass* Z_Construct_UClass_UPaperSprite(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFFrameworkSettings(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFCombatQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCarePropActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFFrameworkSettings(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFLoginMainMenuWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPartyQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFScanNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterRosterData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldChatWidget(ETypeConstructPhase);
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnablePlayerCameraZoom_MetaData[] = {
		{ "Category", "Camera|Zoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for the framework's local third-person camera boom zoom system. Camera distance is never replicated. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for the framework's local third-person camera boom zoom system. Camera distance is never replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDefaultPlayerCameraZoomInput_MetaData[] = {
		{ "Category", "Camera|Zoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ready-to-use Mouse Wheel Up/Down zoom binding. Disable when an Enhanced Input mapping supplies zoom instead. */" },
#endif
		{ "EditCondition", "bEnablePlayerCameraZoom" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ready-to-use Mouse Wheel Up/Down zoom binding. Disable when an Enhanced Input mapping supplies zoom instead." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCameraDefaultBoomLength_MetaData[] = {
		{ "Category", "Camera|Zoom" },
		{ "ClampMax", "5000.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom distance used when the locally controlled player first enters gameplay or resets zoom. */" },
#endif
		{ "EditCondition", "bEnablePlayerCameraZoom" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom distance used when the locally controlled player first enters gameplay or resets zoom." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCameraMinimumBoomLength_MetaData[] = {
		{ "Category", "Camera|Zoom" },
		{ "ClampMax", "5000.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Closest permitted third-person camera distance. */" },
#endif
		{ "EditCondition", "bEnablePlayerCameraZoom" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Closest permitted third-person camera distance." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCameraMaximumBoomLength_MetaData[] = {
		{ "Category", "Camera|Zoom" },
		{ "ClampMax", "10000.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Farthest permitted third-person camera distance. */" },
#endif
		{ "EditCondition", "bEnablePlayerCameraZoom" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Farthest permitted third-person camera distance." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCameraMouseWheelZoomStep_MetaData[] = {
		{ "Category", "Camera|Zoom" },
		{ "ClampMax", "1000.0" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Boom-length change requested by one mouse-wheel notch. Positive zoom input moves the camera closer. */" },
#endif
		{ "EditCondition", "bEnablePlayerCameraZoom" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Boom-length change requested by one mouse-wheel notch. Positive zoom input moves the camera closer." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCameraZoomInterpolationSpeed_MetaData[] = {
		{ "Category", "Camera|Zoom" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Interpolation speed used when moving toward the requested boom distance. Set to zero for instant zoom. */" },
#endif
		{ "EditCondition", "bEnablePlayerCameraZoom" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Interpolation speed used when moving toward the requested boom distance. Set to zero for instant zoom." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIgnorePlayersAndDigimonForCameraCollision_MetaData[] = {
		{ "Category", "Camera|Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * When enabled, framework player capsules/meshes and Digimon capsules/meshes ignore ECC_Camera.\n     * The spring arm still collides with level/world geometry, but another character can no longer shove the camera inward.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When enabled, framework player capsules/meshes and Digimon capsules/meshes ignore ECC_Camera.\nThe spring arm still collides with level/world geometry, but another character can no longer shove the camera inward." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnablePlayerFootsteps_MetaData[] = {
		{ "Category", "Player Avatar|Footsteps" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for automatic replicated player-avatar footsteps. Digimon are intentionally not affected. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for automatic replicated player-avatar footsteps. Digimon are intentionally not affected." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerFootstepSound_MetaData[] = {
		{ "Category", "Player Avatar|Footsteps" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Global player footstep audio asset. A Sound Cue is recommended so projects can randomize samples/pitch\n     * and configure spatial attenuation without changing framework code.\n     */" },
#endif
		{ "DisplayName", "Player Footstep Sound (Sound Cue Recommended)" },
		{ "EditCondition", "bEnablePlayerFootsteps" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global player footstep audio asset. A Sound Cue is recommended so projects can randomize samples/pitch\nand configure spatial attenuation without changing framework code." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerFootstepMinimumSpeed_MetaData[] = {
		{ "Category", "Player Avatar|Footsteps|Cadence" },
		{ "ClampMax", "1000.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimum grounded horizontal movement speed required before footsteps accumulate. */" },
#endif
		{ "EditCondition", "bEnablePlayerFootsteps" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum grounded horizontal movement speed required before footsteps accumulate." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerFootstepWalkStrideDistance_MetaData[] = {
		{ "Category", "Player Avatar|Footsteps|Cadence" },
		{ "ClampMax", "500.0" },
		{ "ClampMin", "25.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Approximate distance travelled between normal walking footsteps. */" },
#endif
		{ "EditCondition", "bEnablePlayerFootsteps" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Approximate distance travelled between normal walking footsteps." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerFootstepSprintStrideDistance_MetaData[] = {
		{ "Category", "Player Avatar|Footsteps|Cadence" },
		{ "ClampMax", "500.0" },
		{ "ClampMin", "25.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Approximate distance travelled between sprinting footsteps. */" },
#endif
		{ "EditCondition", "bEnablePlayerFootsteps" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Approximate distance travelled between sprinting footsteps." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerFootstepCrouchStrideDistance_MetaData[] = {
		{ "Category", "Player Avatar|Footsteps|Cadence" },
		{ "ClampMax", "500.0" },
		{ "ClampMin", "25.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Approximate distance travelled between crouched footsteps. */" },
#endif
		{ "EditCondition", "bEnablePlayerFootsteps" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Approximate distance travelled between crouched footsteps." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerFootstepVolumeMultiplier_MetaData[] = {
		{ "Category", "Player Avatar|Footsteps|Presentation" },
		{ "ClampMax", "4.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Global gain applied after any volume/randomization authored inside the assigned Sound Cue. */" },
#endif
		{ "EditCondition", "bEnablePlayerFootsteps" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global gain applied after any volume/randomization authored inside the assigned Sound Cue." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerFootstepPitchMultiplier_MetaData[] = {
		{ "Category", "Player Avatar|Footsteps|Presentation" },
		{ "ClampMax", "4.0" },
		{ "ClampMin", "0.25" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Global pitch multiplier applied after any pitch/randomization authored inside the assigned Sound Cue. */" },
#endif
		{ "EditCondition", "bEnablePlayerFootsteps" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global pitch multiplier applied after any pitch/randomization authored inside the assigned Sound Cue." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableFrameworkMusic_MetaData[] = {
		{ "Category", "Audio|Music" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for the automatic local music-state system. Music is presentation-only and never replicated. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for the automatic local music-state system. Music is presentation-only and never replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrontendMusic_MetaData[] = {
		{ "Category", "Audio|Music|Tracks" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Music used while the configured FrontendMap is active. Author the cue/wave to loop, or leave automatic replay enabled below. */" },
#endif
		{ "DisplayName", "Frontend / Main Menu Music" },
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Music used while the configured FrontendMap is active. Author the cue/wave to loop, or leave automatic replay enabled below." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenWorldMusic_MetaData[] = {
		{ "Category", "Audio|Music|Tracks" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default exploration music used in the configured OpenWorldMap whenever the local partner is not in combat. */" },
#endif
		{ "DisplayName", "Open World Music" },
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default exploration music used in the configured OpenWorldMap whenever the local partner is not in combat." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleMusic_MetaData[] = {
		{ "Category", "Audio|Music|Tracks" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Combat music used while the local active partner is in replicated combat. Falls back to Open World Music when unassigned. */" },
#endif
		{ "DisplayName", "Battle Music" },
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Combat music used while the local active partner is in replicated combat. Falls back to Open World Music when unassigned." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MusicMasterVolume_MetaData[] = {
		{ "Category", "Audio|Music|Mix" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Global music gain applied before the per-state volume multipliers below. */" },
#endif
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global music gain applied before the per-state volume multipliers below." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrontendMusicVolume_MetaData[] = {
		{ "Category", "Audio|Music|Mix" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenWorldMusicVolume_MetaData[] = {
		{ "Category", "Audio|Music|Mix" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleMusicVolume_MetaData[] = {
		{ "Category", "Audio|Music|Mix" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MusicCrossfadeSeconds_MetaData[] = {
		{ "Category", "Audio|Music|Transitions" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Symmetric crossfade used when switching Frontend/Open World/Battle music. Set to zero for an immediate cut. */" },
#endif
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Symmetric crossfade used when switching Frontend/Open World/Battle music. Set to zero for an immediate cut." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleMusicReleaseDelaySeconds_MetaData[] = {
		{ "Category", "Audio|Music|Transitions" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keeps Battle music active briefly after replicated combat ends so short state gaps do not cause soundtrack chatter. */" },
#endif
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keeps Battle music active briefly after replicated combat ends so short state gaps do not cause soundtrack chatter." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutomaticallyLoopMusic_MetaData[] = {
		{ "Category", "Audio|Music|Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If a configured track reaches its natural end, restart it automatically. Internally-looped Sound Cues work normally too. */" },
#endif
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If a configured track reaches its natural end, restart it automatically. Internally-looped Sound Cues work normally too." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MusicStateEvaluationInterval_MetaData[] = {
		{ "Category", "Audio|Music|Performance" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.05" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local presentation polling interval. Combat truth still comes from the existing replicated partner CombatComponent. */" },
#endif
		{ "EditCondition", "bEnableFrameworkMusic" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local presentation polling interval. Combat truth still comes from the existing replicated partner CombatComponent." },
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy pre-v0.12 active-collection capacity retained for config compatibility. Party capacity is controlled below. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy pre-v0.12 active-collection capacity retained for config compatibility. Party capacity is controlled below." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxPartyDigimon_MetaData[] = {
		{ "Category", "Party & Bank|Party" },
		{ "ClampMax", "6" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Active field roster size. Six matches the classic creature-party convention and the native Party UI. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Active field roster size. Six matches the classic creature-party convention and the native Party UI." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDigimonBankStorage_MetaData[] = {
		{ "Category", "Party & Bank|Bank" },
		{ "ClampMax", "5000" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum persistent Digimon stored in the account Bank/Boxes. Existing oversized saves are never truncated. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum persistent Digimon stored in the account Bank/Boxes. Existing oversized saves are never truncated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonBankSlotsPerPage_MetaData[] = {
		{ "Category", "Party & Bank|Bank" },
		{ "ClampMax", "60" },
		{ "ClampMin", "6" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of visible Bank slots per native Box page. The polished fallback uses a 6-column grid. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of visible Bank slots per native Box page. The polished fallback uses a 6-column grid." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowPartySwitchingDuringCombat_MetaData[] = {
		{ "Category", "Party & Bank|Rules" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default safety policy. Disable only if the project intentionally supports mid-combat partner/Bank swaps. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default safety policy. Disable only if the project intentionally supports mid-combat partner/Bank swaps." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartnerSpawnOffset_MetaData[] = {
		{ "Category", "Partner" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatQuickBarWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartyQuickBarWidgetClass_MetaData[] = {
		{ "Category", "UI|Party Quick Access" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Persistent six-slot Party HUD. Assign a Blueprint child to reskin it without replacing Party authority. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Persistent six-slot Party HUD. Assign a Blueprint child to reskin it without replacing Party authority." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowNativePartyQuickBar_MetaData[] = {
		{ "Category", "UI|Party Quick Access" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for the persistent native Party quick-access HUD. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for the persistent native Party quick-access HUD." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDefaultPartyQuickAccessInput_MetaData[] = {
		{ "Category", "UI|Party Quick Access" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ready-to-use Tab interaction toggle. Disable when Enhanced Input/project UI owns the Party cursor mode. */" },
#endif
		{ "EditCondition", "bShowNativePartyQuickBar" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ready-to-use Tab interaction toggle. Disable when Enhanced Input/project UI owns the Party cursor mode." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartyQuickBarBottomSafeOffset_MetaData[] = {
		{ "Category", "UI|Party Quick Access|Presentation" },
		{ "ClampMax", "1000.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Bottom safe-lane offset so Party Quick Access sits above the centered combat quickbar by default. */" },
#endif
		{ "EditCondition", "bShowNativePartyQuickBar" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bottom safe-lane offset so Party Quick Access sits above the centered combat quickbar by default." },
#endif
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDigiDex_MetaData[] = {
		{ "Category", "UI|DigiDex" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for the read-only native DigiDex encyclopedia tab. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for the read-only native DigiDex encyclopedia tab." },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableWorldChat_MetaData[] = {
		{ "Category", "UI|World Chat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for the native server-authoritative MMO world chat system. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for the native server-authoritative MMO world chat system." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDefaultWorldChatInput_MetaData[] = {
		{ "Category", "UI|World Chat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ready-to-use Enter-key chat focus. Disable when the project owns its own chat input routing. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ready-to-use Enter-key chat focus. Disable when the project owns its own chat input routing." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldChatWidgetClass_MetaData[] = {
		{ "Category", "UI|World Chat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native fallback is supplied; assign a Blueprint child to reskin chat without replacing validation/networking. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native fallback is supplied; assign a Blueprint child to reskin chat without replacing validation/networking." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldChatMaxMessageLength_MetaData[] = {
		{ "Category", "UI|World Chat|Safety" },
		{ "ClampMax", "1000" },
		{ "ClampMin", "32" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum accepted player message length after server sanitation. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum accepted player message length after server sanitation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldChatClientHistoryLimit_MetaData[] = {
		{ "Category", "UI|World Chat|History" },
		{ "ClampMax", "500" },
		{ "ClampMin", "10" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local client-side visible history cap. This is presentation state and is not continuously replicated. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local client-side visible history cap. This is presentation state and is not continuously replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldChatServerHistoryLimit_MetaData[] = {
		{ "Category", "UI|World Chat|History" },
		{ "ClampMax", "250" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Session history retained by the authoritative GameMode and sent once to late joiners. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Session history retained by the authoritative GameMode and sent once to late joiners." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldChatMinimumSendInterval_MetaData[] = {
		{ "Category", "UI|World Chat|Safety" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimum authoritative interval between accepted messages from one player. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum authoritative interval between accepted messages from one player." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldChatBurstWindowSeconds_MetaData[] = {
		{ "Category", "UI|World Chat|Safety" },
		{ "ClampMax", "60.0" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sliding server window used by the burst limiter. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sliding server window used by the burst limiter." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldChatMaxMessagesPerBurst_MetaData[] = {
		{ "Category", "UI|World Chat|Safety" },
		{ "ClampMax", "60" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum accepted messages from one player inside the configured burst window. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum accepted messages from one player inside the configured burst window." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowWorldChatTimestamps_MetaData[] = {
		{ "Category", "UI|World Chat|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional compact UTC HH:MM prefix. Disabled by default for the cleanest WoW-style presentation. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional compact UTC HH:MM prefix. Disabled by default for the cleanest WoW-style presentation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldChatBottomSafeOffset_MetaData[] = {
		{ "Category", "UI|World Chat|Presentation" },
		{ "ClampMax", "600.0" },
		{ "ClampMin", "30.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Bottom safe-zone used by the native WORLD chat so it clears the centered combat quick-access HUD. */" },
#endif
		{ "EditCondition", "bEnableWorldChat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bottom safe-zone used by the native WORLD chat so it clears the centered combat quick-access HUD." },
#endif
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDigivolutionSystem_MetaData[] = {
		{ "Category", "Digivolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for persistent server-authoritative Digivolution. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for persistent server-authoritative Digivolution." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowBankDigivolution_MetaData[] = {
		{ "Category", "Digivolution|Rules" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Allows stored Bank/Box Digimon to Digivolve from the world-accessible Digimon Menu. */" },
#endif
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allows stored Bank/Box Digimon to Digivolve from the world-accessible Digimon Menu." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBlockDigivolutionDuringCombat_MetaData[] = {
		{ "Category", "Digivolution|Rules" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Active summoned partners must be idle before a Digivolution sequence can begin. */" },
#endif
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Active summoned partners must be idle before a Digivolution sequence can begin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHideUIForSummonedDigivolution_MetaData[] = {
		{ "Category", "Digivolution|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hide modal/HUD UI while a summoned partner performs its in-world transformation presentation. */" },
#endif
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hide modal/HUD UI while a summoned partner performs its in-world transformation presentation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionPresentationDurationSeconds_MetaData[] = {
		{ "Category", "Digivolution|Presentation" },
		{ "ClampMax", "20.0" },
		{ "ClampMin", "0.25" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default duration before an active world partner is replaced by the target form. A path may override this. */" },
#endif
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default duration before an active world partner is replaced by the target form. A path may override this." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDigivolutionNiagaraSystem_MetaData[] = {
		{ "Category", "Digivolution|Presentation|VFX" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Preferred global transformation VFX. Individual evolution paths can override this. */" },
#endif
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Preferred global transformation VFX. Individual evolution paths can override this." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDigivolutionCascadeParticle_MetaData[] = {
		{ "Category", "Digivolution|Presentation|VFX" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cascade fallback when no path/global Niagara system is assigned or Niagara preference is disabled. */" },
#endif
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cascade fallback when no path/global Niagara system is assigned or Niagara preference is disabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreferNiagaraDigivolutionVFX_MetaData[] = {
		{ "Category", "Digivolution|Presentation|VFX" },
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDigivolutionSound_MetaData[] = {
		{ "Category", "Digivolution|Presentation|Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Global transformation Sound Cue/Wave. Individual paths can override it. */" },
#endif
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global transformation Sound Cue/Wave. Individual paths can override it." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionSoundVolumeMultiplier_MetaData[] = {
		{ "Category", "Digivolution|Presentation|Audio" },
		{ "ClampMax", "4.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionSoundPitchMultiplier_MetaData[] = {
		{ "Category", "Digivolution|Presentation|Audio" },
		{ "ClampMax", "4.0" },
		{ "ClampMin", "0.25" },
		{ "EditCondition", "bEnableDigivolutionSystem" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowNativeCombatQuickBar_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableCombatTargetingVisuals_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for local owner-only active-partner and enemy-target selection presentation. No targeting visuals are replicated. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for local owner-only active-partner and enemy-target selection presentation. No targeting visuals are replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowActivePartnerTargetingRing_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Active Partner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows the project's blue selection-ring PaperSprite under this local player's currently summoned active partner only. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows the project's blue selection-ring PaperSprite under this local player's currently summoned active partner only." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivePartnerTargetingRingSprite_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Active Partner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blue PaperSprite used beneath the owning player's active partner. Assign CircleRing_T_Sprite (or equivalent) here. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowActivePartnerTargetingRing" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blue PaperSprite used beneath the owning player's active partner. Assign CircleRing_T_Sprite (or equivalent) here." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivePartnerTargetingRingScale_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Active Partner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Additional local-space sprite scale before optional capsule-size adaptation. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowActivePartnerTargetingRing" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Additional local-space sprite scale before optional capsule-size adaptation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivePartnerTargetingRingGroundOffset_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Active Partner" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "-50.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Height above the Digimon capsule bottom, useful for preventing translucent z-fighting with the floor. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowActivePartnerTargetingRing" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height above the Digimon capsule bottom, useful for preventing translucent z-fighting with the floor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivePartnerTargetingRingRotationDegreesPerSecond_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Active Partner" },
		{ "ClampMax", "720.0" },
		{ "ClampMin", "-720.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Continuous world-Z spin speed. Positive and negative values rotate in opposite directions. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowActivePartnerTargetingRing" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Continuous world-Z spin speed. Positive and negative values rotate in opposite directions." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowEnemyTargetingRing_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Target" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows the project's hostile/selected target PaperSprite beneath only this local player's current command target. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows the project's hostile/selected target PaperSprite beneath only this local player's current command target." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetingRingSprite_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Target" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enemy-target PaperSprite used beneath the currently selected hostile Digimon. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetingRing" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enemy-target PaperSprite used beneath the currently selected hostile Digimon." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetingRingScale_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Target" },
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetingRing" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetingRingGroundOffset_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Target" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "-50.0" },
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetingRing" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetingRingRotationDegreesPerSecond_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Target" },
		{ "ClampMax", "720.0" },
		{ "ClampMin", "-720.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default rotates opposite/faster than the active-partner ring for stronger visual separation. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetingRing" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default rotates opposite/faster than the active-partner ring for stronger visual separation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingRingSpriteRelativeRotation_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Rings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** PaperSprite assets normally face the X/Z plane; Roll=90 lays them flat while a parent pivot performs clean world-Z rotation. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PaperSprite assets normally face the X/Z plane; Roll=90 lays them flat while a parent pivot performs clean world-Z rotation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bScaleTargetingRingsToDigimonCapsule_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Rings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Automatically adapts both ring sizes to very small/large Digimon capsule radii. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatically adapts both ring sizes to very small/large Digimon capsule radii." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingRingReferenceCapsuleRadius_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Rings" },
		{ "ClampMax", "500.0" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bEnableCombatTargetingVisuals && bScaleTargetingRingsToDigimonCapsule" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingRingMinimumAutoScale_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Rings" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bEnableCombatTargetingVisuals && bScaleTargetingRingsToDigimonCapsule" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingRingMaximumAutoScale_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Rings" },
		{ "ClampMax", "20.0" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bEnableCombatTargetingVisuals && bScaleTargetingRingsToDigimonCapsule" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingVisualTranslucentSortPriority_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Rings" },
		{ "ClampMax", "100" },
		{ "ClampMin", "-100" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Slate/render priority for translucent PaperSprite rings. Enemy ring uses this value + 1. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Slate/render priority for translucent PaperSprite rings. Enemy ring uses this value + 1." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowEnemyTargetArrow_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Arrow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows the hovering down-arrow effect over the current local command target. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows the hovering down-arrow effect over the current local command target." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreferNiagaraEnemyTargetArrow_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Arrow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Niagara is preferred when both Niagara and Cascade assets are supplied. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetArrow" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Niagara is preferred when both Niagara and Cascade assets are supplied." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetArrowNiagaraSystem_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Arrow" },
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetArrow" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetArrowCascadeSystem_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Arrow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy/fallback particle system used when Niagara is unassigned or not preferred. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetArrow" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy/fallback particle system used when Niagara is unassigned or not preferred." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetArrowHeightOffset_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Arrow" },
		{ "ClampMax", "1000.0" },
		{ "ClampMin", "-200.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Additional distance above the top of the target capsule. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetArrow" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Additional distance above the top of the target capsule." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetArrowScale_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Arrow" },
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetArrow" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetArrowRotation_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Arrow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rotation correction for arrow VFX authored in a different local axis. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetArrow" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rotation correction for arrow VFX authored in a different local axis." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetArrowBobAmplitude_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Arrow" },
		{ "ClampMax", "200.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native vertical hovering amplitude. Set to zero if the Niagara/Cascade system already performs its own bob animation. */" },
#endif
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetArrow" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native vertical hovering amplitude. Set to zero if the Niagara/Cascade system already performs its own bob animation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetArrowBobFrequencyHz_MetaData[] = {
		{ "Category", "Combat|Targeting Visuals|Enemy Arrow" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableCombatTargetingVisuals && bShowEnemyTargetArrow" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerPublicAddress_MetaData[] = {
		{ "Category", "Networking|Server Endpoint" },
		{ "DisplayName", "Server Public Address / Hostname" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Public IPv4 address or DNS hostname players use to reach the admin listen host. Enter only the host name/address; configure the port separately below." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GamePort_MetaData[] = {
		{ "Category", "Networking|Server Endpoint" },
		{ "ClampMax", "65535" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Connection port appended to Server Public Address for Join Game. It must match the port exposed/forwarded by the host deployment. */" },
#endif
		{ "DisplayName", "Game Port" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Connection port appended to Server Public Address for Join Game. It must match the port exposed/forwarded by the host deployment." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdminHostingPasswordInput_MetaData[] = {
		{ "Category", "Networking|Admin Hosting" },
		{ "DisplayName", "Set Admin Hosting Password" },
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
		{ "PasswordField", "true" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enter a new 4-128 character password for the Admin Host & Play gate. The framework stores only its one-way digest and clears this field after the Project Settings change is applied." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdminHostingPasswordDigest_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** One-way digest used by the local Admin frontend gate. Hidden from normal Project Settings editing. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/DMFFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One-way digest used by the local Admin frontend gate. Hidden from normal Project Settings editing." },
#endif
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
	static void NewProp_bEnablePlayerCameraZoom_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnablePlayerCameraZoom = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnablePlayerCameraZoom;
	static void NewProp_bEnableDefaultPlayerCameraZoomInput_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDefaultPlayerCameraZoomInput = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDefaultPlayerCameraZoomInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerCameraDefaultBoomLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerCameraMinimumBoomLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerCameraMaximumBoomLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerCameraMouseWheelZoomStep;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerCameraZoomInterpolationSpeed;
	static void NewProp_bIgnorePlayersAndDigimonForCameraCollision_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bIgnorePlayersAndDigimonForCameraCollision = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnorePlayersAndDigimonForCameraCollision;
	static void NewProp_bEnablePlayerFootsteps_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnablePlayerFootsteps = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnablePlayerFootsteps;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_PlayerFootstepSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerFootstepMinimumSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerFootstepWalkStrideDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerFootstepSprintStrideDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerFootstepCrouchStrideDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerFootstepVolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerFootstepPitchMultiplier;
	static void NewProp_bEnableFrameworkMusic_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableFrameworkMusic = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableFrameworkMusic;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_FrontendMusic;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_OpenWorldMusic;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_BattleMusic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MusicMasterVolume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FrontendMusicVolume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenWorldMusicVolume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BattleMusicVolume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MusicCrossfadeSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BattleMusicReleaseDelaySeconds;
	static void NewProp_bAutomaticallyLoopMusic_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bAutomaticallyLoopMusic = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutomaticallyLoopMusic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MusicStateEvaluationInterval;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AccountSaveSlot;
	static void NewProp_bAutoRegisterUnknownAccounts_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bAutoRegisterUnknownAccounts = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoRegisterUnknownAccounts;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxActiveDigimonInventory;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxPartyDigimon;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDigimonBankStorage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigimonBankSlotsPerPage;
	static void NewProp_bAllowPartySwitchingDuringCombat_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bAllowPartySwitchingDuringCombat = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowPartySwitchingDuringCombat;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PartnerSpawnOffset;
	static const UECodeGen_Private::FClassPropertyParams NewProp_CombatQuickBarWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PartyQuickBarWidgetClass;
	static void NewProp_bShowNativePartyQuickBar_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowNativePartyQuickBar = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowNativePartyQuickBar;
	static void NewProp_bEnableDefaultPartyQuickAccessInput_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDefaultPartyQuickAccessInput = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDefaultPartyQuickAccessInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PartyQuickBarBottomSafeOffset;
	static const UECodeGen_Private::FClassPropertyParams NewProp_DigimonInventoryWidgetClass;
	static void NewProp_bEnableDigiDex_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDigiDex = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDigiDex;
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
	static void NewProp_bEnableWorldChat_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableWorldChat = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableWorldChat;
	static void NewProp_bEnableDefaultWorldChatInput_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDefaultWorldChatInput = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDefaultWorldChatInput;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WorldChatWidgetClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WorldChatMaxMessageLength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WorldChatClientHistoryLimit;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WorldChatServerHistoryLimit;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldChatMinimumSendInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldChatBurstWindowSeconds;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WorldChatMaxMessagesPerBurst;
	static void NewProp_bShowWorldChatTimestamps_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowWorldChatTimestamps = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowWorldChatTimestamps;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldChatBottomSafeOffset;
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
	static void NewProp_bEnableDigivolutionSystem_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableDigivolutionSystem = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDigivolutionSystem;
	static void NewProp_bAllowBankDigivolution_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bAllowBankDigivolution = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowBankDigivolution;
	static void NewProp_bBlockDigivolutionDuringCombat_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bBlockDigivolutionDuringCombat = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBlockDigivolutionDuringCombat;
	static void NewProp_bHideUIForSummonedDigivolution_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bHideUIForSummonedDigivolution = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHideUIForSummonedDigivolution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DigivolutionPresentationDurationSeconds;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultDigivolutionNiagaraSystem;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultDigivolutionCascadeParticle;
	static void NewProp_bPreferNiagaraDigivolutionVFX_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bPreferNiagaraDigivolutionVFX = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreferNiagaraDigivolutionVFX;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultDigivolutionSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DigivolutionSoundVolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DigivolutionSoundPitchMultiplier;
	static void NewProp_bShowNativeCombatQuickBar_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowNativeCombatQuickBar = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowNativeCombatQuickBar;
	static void NewProp_bEnableCombatTargetingVisuals_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bEnableCombatTargetingVisuals = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableCombatTargetingVisuals;
	static void NewProp_bShowActivePartnerTargetingRing_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowActivePartnerTargetingRing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowActivePartnerTargetingRing;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ActivePartnerTargetingRingSprite;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActivePartnerTargetingRingScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActivePartnerTargetingRingGroundOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActivePartnerTargetingRingRotationDegreesPerSecond;
	static void NewProp_bShowEnemyTargetingRing_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowEnemyTargetingRing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowEnemyTargetingRing;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_EnemyTargetingRingSprite;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EnemyTargetingRingScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnemyTargetingRingGroundOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnemyTargetingRingRotationDegreesPerSecond;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetingRingSpriteRelativeRotation;
	static void NewProp_bScaleTargetingRingsToDigimonCapsule_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bScaleTargetingRingsToDigimonCapsule = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bScaleTargetingRingsToDigimonCapsule;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetingRingReferenceCapsuleRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetingRingMinimumAutoScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetingRingMaximumAutoScale;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TargetingVisualTranslucentSortPriority;
	static void NewProp_bShowEnemyTargetArrow_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bShowEnemyTargetArrow = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowEnemyTargetArrow;
	static void NewProp_bPreferNiagaraEnemyTargetArrow_SetBit(void* Obj)
	{
		((UDMFFrameworkSettings*)Obj)->bPreferNiagaraEnemyTargetArrow = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreferNiagaraEnemyTargetArrow;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_EnemyTargetArrowNiagaraSystem;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_EnemyTargetArrowCascadeSystem;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnemyTargetArrowHeightOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EnemyTargetArrowScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EnemyTargetArrowRotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnemyTargetArrowBobAmplitude;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnemyTargetArrowBobFrequencyHz;
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
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerPublicAddress;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GamePort;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdminHostingPasswordInput;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdminHostingPasswordDigest;
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
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnablePlayerCameraZoom = { "bEnablePlayerCameraZoom", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnablePlayerCameraZoom_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnablePlayerCameraZoom_MetaData), NewProp_bEnablePlayerCameraZoom_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDefaultPlayerCameraZoomInput = { "bEnableDefaultPlayerCameraZoomInput", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDefaultPlayerCameraZoomInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDefaultPlayerCameraZoomInput_MetaData), NewProp_bEnableDefaultPlayerCameraZoomInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerCameraDefaultBoomLength = { "PlayerCameraDefaultBoomLength", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerCameraDefaultBoomLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCameraDefaultBoomLength_MetaData), NewProp_PlayerCameraDefaultBoomLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerCameraMinimumBoomLength = { "PlayerCameraMinimumBoomLength", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerCameraMinimumBoomLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCameraMinimumBoomLength_MetaData), NewProp_PlayerCameraMinimumBoomLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerCameraMaximumBoomLength = { "PlayerCameraMaximumBoomLength", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerCameraMaximumBoomLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCameraMaximumBoomLength_MetaData), NewProp_PlayerCameraMaximumBoomLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerCameraMouseWheelZoomStep = { "PlayerCameraMouseWheelZoomStep", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerCameraMouseWheelZoomStep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCameraMouseWheelZoomStep_MetaData), NewProp_PlayerCameraMouseWheelZoomStep_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerCameraZoomInterpolationSpeed = { "PlayerCameraZoomInterpolationSpeed", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerCameraZoomInterpolationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCameraZoomInterpolationSpeed_MetaData), NewProp_PlayerCameraZoomInterpolationSpeed_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIgnorePlayersAndDigimonForCameraCollision = { "bIgnorePlayersAndDigimonForCameraCollision", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bIgnorePlayersAndDigimonForCameraCollision_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIgnorePlayersAndDigimonForCameraCollision_MetaData), NewProp_bIgnorePlayersAndDigimonForCameraCollision_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnablePlayerFootsteps = { "bEnablePlayerFootsteps", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnablePlayerFootsteps_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnablePlayerFootsteps_MetaData), NewProp_bEnablePlayerFootsteps_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_PlayerFootstepSound = { "PlayerFootstepSound", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerFootstepSound), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerFootstepSound_MetaData), NewProp_PlayerFootstepSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerFootstepMinimumSpeed = { "PlayerFootstepMinimumSpeed", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerFootstepMinimumSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerFootstepMinimumSpeed_MetaData), NewProp_PlayerFootstepMinimumSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerFootstepWalkStrideDistance = { "PlayerFootstepWalkStrideDistance", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerFootstepWalkStrideDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerFootstepWalkStrideDistance_MetaData), NewProp_PlayerFootstepWalkStrideDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerFootstepSprintStrideDistance = { "PlayerFootstepSprintStrideDistance", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerFootstepSprintStrideDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerFootstepSprintStrideDistance_MetaData), NewProp_PlayerFootstepSprintStrideDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerFootstepCrouchStrideDistance = { "PlayerFootstepCrouchStrideDistance", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerFootstepCrouchStrideDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerFootstepCrouchStrideDistance_MetaData), NewProp_PlayerFootstepCrouchStrideDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerFootstepVolumeMultiplier = { "PlayerFootstepVolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerFootstepVolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerFootstepVolumeMultiplier_MetaData), NewProp_PlayerFootstepVolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerFootstepPitchMultiplier = { "PlayerFootstepPitchMultiplier", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PlayerFootstepPitchMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerFootstepPitchMultiplier_MetaData), NewProp_PlayerFootstepPitchMultiplier_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableFrameworkMusic = { "bEnableFrameworkMusic", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableFrameworkMusic_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableFrameworkMusic_MetaData), NewProp_bEnableFrameworkMusic_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_FrontendMusic = { "FrontendMusic", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, FrontendMusic), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrontendMusic_MetaData), NewProp_FrontendMusic_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_OpenWorldMusic = { "OpenWorldMusic", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, OpenWorldMusic), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenWorldMusic_MetaData), NewProp_OpenWorldMusic_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_BattleMusic = { "BattleMusic", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, BattleMusic), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleMusic_MetaData), NewProp_BattleMusic_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MusicMasterVolume = { "MusicMasterVolume", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, MusicMasterVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MusicMasterVolume_MetaData), NewProp_MusicMasterVolume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FrontendMusicVolume = { "FrontendMusicVolume", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, FrontendMusicVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrontendMusicVolume_MetaData), NewProp_FrontendMusicVolume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_OpenWorldMusicVolume = { "OpenWorldMusicVolume", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, OpenWorldMusicVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenWorldMusicVolume_MetaData), NewProp_OpenWorldMusicVolume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BattleMusicVolume = { "BattleMusicVolume", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, BattleMusicVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleMusicVolume_MetaData), NewProp_BattleMusicVolume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MusicCrossfadeSeconds = { "MusicCrossfadeSeconds", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, MusicCrossfadeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MusicCrossfadeSeconds_MetaData), NewProp_MusicCrossfadeSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BattleMusicReleaseDelaySeconds = { "BattleMusicReleaseDelaySeconds", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, BattleMusicReleaseDelaySeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleMusicReleaseDelaySeconds_MetaData), NewProp_BattleMusicReleaseDelaySeconds_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAutomaticallyLoopMusic = { "bAutomaticallyLoopMusic", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bAutomaticallyLoopMusic_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutomaticallyLoopMusic_MetaData), NewProp_bAutomaticallyLoopMusic_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MusicStateEvaluationInterval = { "MusicStateEvaluationInterval", nullptr, (EPropertyFlags)0x0010040000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, MusicStateEvaluationInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MusicStateEvaluationInterval_MetaData), NewProp_MusicStateEvaluationInterval_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_AccountSaveSlot = { "AccountSaveSlot", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, AccountSaveSlot), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccountSaveSlot_MetaData), NewProp_AccountSaveSlot_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAutoRegisterUnknownAccounts = { "bAutoRegisterUnknownAccounts", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bAutoRegisterUnknownAccounts_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoRegisterUnknownAccounts_MetaData), NewProp_bAutoRegisterUnknownAccounts_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxActiveDigimonInventory = { "MaxActiveDigimonInventory", nullptr, (EPropertyFlags)0x0010040000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, MaxActiveDigimonInventory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxActiveDigimonInventory_MetaData), NewProp_MaxActiveDigimonInventory_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxPartyDigimon = { "MaxPartyDigimon", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, MaxPartyDigimon), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxPartyDigimon_MetaData), NewProp_MaxPartyDigimon_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxDigimonBankStorage = { "MaxDigimonBankStorage", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, MaxDigimonBankStorage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDigimonBankStorage_MetaData), NewProp_MaxDigimonBankStorage_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigimonBankSlotsPerPage = { "DigimonBankSlotsPerPage", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DigimonBankSlotsPerPage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonBankSlotsPerPage_MetaData), NewProp_DigimonBankSlotsPerPage_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowPartySwitchingDuringCombat = { "bAllowPartySwitchingDuringCombat", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bAllowPartySwitchingDuringCombat_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowPartySwitchingDuringCombat_MetaData), NewProp_bAllowPartySwitchingDuringCombat_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PartnerSpawnOffset = { "PartnerSpawnOffset", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PartnerSpawnOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartnerSpawnOffset_MetaData), NewProp_PartnerSpawnOffset_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_CombatQuickBarWidgetClass = { "CombatQuickBarWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, CombatQuickBarWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFCombatQuickBarWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatQuickBarWidgetClass_MetaData), NewProp_CombatQuickBarWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_PartyQuickBarWidgetClass = { "PartyQuickBarWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PartyQuickBarWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFPartyQuickBarWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartyQuickBarWidgetClass_MetaData), NewProp_PartyQuickBarWidgetClass_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowNativePartyQuickBar = { "bShowNativePartyQuickBar", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowNativePartyQuickBar_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowNativePartyQuickBar_MetaData), NewProp_bShowNativePartyQuickBar_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDefaultPartyQuickAccessInput = { "bEnableDefaultPartyQuickAccessInput", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDefaultPartyQuickAccessInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDefaultPartyQuickAccessInput_MetaData), NewProp_bEnableDefaultPartyQuickAccessInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PartyQuickBarBottomSafeOffset = { "PartyQuickBarBottomSafeOffset", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, PartyQuickBarBottomSafeOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartyQuickBarBottomSafeOffset_MetaData), NewProp_PartyQuickBarBottomSafeOffset_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_DigimonInventoryWidgetClass = { "DigimonInventoryWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DigimonInventoryWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFDigimonInventoryWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonInventoryWidgetClass_MetaData), NewProp_DigimonInventoryWidgetClass_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDigiDex = { "bEnableDigiDex", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDigiDex_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDigiDex_MetaData), NewProp_bEnableDigiDex_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDefaultDigimonInventoryMenuInput = { "bEnableDefaultDigimonInventoryMenuInput", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDefaultDigimonInventoryMenuInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDefaultDigimonInventoryMenuInput_MetaData), NewProp_bEnableDefaultDigimonInventoryMenuInput_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_ScanNotificationWidgetClass = { "ScanNotificationWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, ScanNotificationWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFScanNotificationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanNotificationWidgetClass_MetaData), NewProp_ScanNotificationWidgetClass_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowNativeScanNotifications = { "bShowNativeScanNotifications", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowNativeScanNotifications_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowNativeScanNotifications_MetaData), NewProp_bShowNativeScanNotifications_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableWorldChat = { "bEnableWorldChat", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableWorldChat_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableWorldChat_MetaData), NewProp_bEnableWorldChat_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDefaultWorldChatInput = { "bEnableDefaultWorldChatInput", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDefaultWorldChatInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDefaultWorldChatInput_MetaData), NewProp_bEnableDefaultWorldChatInput_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_WorldChatWidgetClass = { "WorldChatWidgetClass", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, WorldChatWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFWorldChatWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatWidgetClass_MetaData), NewProp_WorldChatWidgetClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_WorldChatMaxMessageLength = { "WorldChatMaxMessageLength", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, WorldChatMaxMessageLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatMaxMessageLength_MetaData), NewProp_WorldChatMaxMessageLength_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_WorldChatClientHistoryLimit = { "WorldChatClientHistoryLimit", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, WorldChatClientHistoryLimit), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatClientHistoryLimit_MetaData), NewProp_WorldChatClientHistoryLimit_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_WorldChatServerHistoryLimit = { "WorldChatServerHistoryLimit", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, WorldChatServerHistoryLimit), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatServerHistoryLimit_MetaData), NewProp_WorldChatServerHistoryLimit_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_WorldChatMinimumSendInterval = { "WorldChatMinimumSendInterval", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, WorldChatMinimumSendInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatMinimumSendInterval_MetaData), NewProp_WorldChatMinimumSendInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_WorldChatBurstWindowSeconds = { "WorldChatBurstWindowSeconds", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, WorldChatBurstWindowSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatBurstWindowSeconds_MetaData), NewProp_WorldChatBurstWindowSeconds_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_WorldChatMaxMessagesPerBurst = { "WorldChatMaxMessagesPerBurst", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, WorldChatMaxMessagesPerBurst), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatMaxMessagesPerBurst_MetaData), NewProp_WorldChatMaxMessagesPerBurst_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowWorldChatTimestamps = { "bShowWorldChatTimestamps", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowWorldChatTimestamps_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowWorldChatTimestamps_MetaData), NewProp_bShowWorldChatTimestamps_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_WorldChatBottomSafeOffset = { "WorldChatBottomSafeOffset", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, WorldChatBottomSafeOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatBottomSafeOffset_MetaData), NewProp_WorldChatBottomSafeOffset_MetaData) };
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
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDigivolutionSystem = { "bEnableDigivolutionSystem", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableDigivolutionSystem_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDigivolutionSystem_MetaData), NewProp_bEnableDigivolutionSystem_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowBankDigivolution = { "bAllowBankDigivolution", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bAllowBankDigivolution_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowBankDigivolution_MetaData), NewProp_bAllowBankDigivolution_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bBlockDigivolutionDuringCombat = { "bBlockDigivolutionDuringCombat", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bBlockDigivolutionDuringCombat_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBlockDigivolutionDuringCombat_MetaData), NewProp_bBlockDigivolutionDuringCombat_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bHideUIForSummonedDigivolution = { "bHideUIForSummonedDigivolution", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bHideUIForSummonedDigivolution_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHideUIForSummonedDigivolution_MetaData), NewProp_bHideUIForSummonedDigivolution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DigivolutionPresentationDurationSeconds = { "DigivolutionPresentationDurationSeconds", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DigivolutionPresentationDurationSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionPresentationDurationSeconds_MetaData), NewProp_DigivolutionPresentationDurationSeconds_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_DefaultDigivolutionNiagaraSystem = { "DefaultDigivolutionNiagaraSystem", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DefaultDigivolutionNiagaraSystem), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDigivolutionNiagaraSystem_MetaData), NewProp_DefaultDigivolutionNiagaraSystem_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_DefaultDigivolutionCascadeParticle = { "DefaultDigivolutionCascadeParticle", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DefaultDigivolutionCascadeParticle), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDigivolutionCascadeParticle_MetaData), NewProp_DefaultDigivolutionCascadeParticle_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPreferNiagaraDigivolutionVFX = { "bPreferNiagaraDigivolutionVFX", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bPreferNiagaraDigivolutionVFX_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreferNiagaraDigivolutionVFX_MetaData), NewProp_bPreferNiagaraDigivolutionVFX_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_DefaultDigivolutionSound = { "DefaultDigivolutionSound", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DefaultDigivolutionSound), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDigivolutionSound_MetaData), NewProp_DefaultDigivolutionSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DigivolutionSoundVolumeMultiplier = { "DigivolutionSoundVolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DigivolutionSoundVolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionSoundVolumeMultiplier_MetaData), NewProp_DigivolutionSoundVolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DigivolutionSoundPitchMultiplier = { "DigivolutionSoundPitchMultiplier", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, DigivolutionSoundPitchMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionSoundPitchMultiplier_MetaData), NewProp_DigivolutionSoundPitchMultiplier_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowNativeCombatQuickBar = { "bShowNativeCombatQuickBar", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowNativeCombatQuickBar_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowNativeCombatQuickBar_MetaData), NewProp_bShowNativeCombatQuickBar_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableCombatTargetingVisuals = { "bEnableCombatTargetingVisuals", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bEnableCombatTargetingVisuals_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableCombatTargetingVisuals_MetaData), NewProp_bEnableCombatTargetingVisuals_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowActivePartnerTargetingRing = { "bShowActivePartnerTargetingRing", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowActivePartnerTargetingRing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowActivePartnerTargetingRing_MetaData), NewProp_bShowActivePartnerTargetingRing_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_ActivePartnerTargetingRingSprite = { "ActivePartnerTargetingRingSprite", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, ActivePartnerTargetingRingSprite), Z_Construct_UClass_UPaperSprite, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivePartnerTargetingRingSprite_MetaData), NewProp_ActivePartnerTargetingRingSprite_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ActivePartnerTargetingRingScale = { "ActivePartnerTargetingRingScale", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, ActivePartnerTargetingRingScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivePartnerTargetingRingScale_MetaData), NewProp_ActivePartnerTargetingRingScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ActivePartnerTargetingRingGroundOffset = { "ActivePartnerTargetingRingGroundOffset", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, ActivePartnerTargetingRingGroundOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivePartnerTargetingRingGroundOffset_MetaData), NewProp_ActivePartnerTargetingRingGroundOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ActivePartnerTargetingRingRotationDegreesPerSecond = { "ActivePartnerTargetingRingRotationDegreesPerSecond", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, ActivePartnerTargetingRingRotationDegreesPerSecond), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivePartnerTargetingRingRotationDegreesPerSecond_MetaData), NewProp_ActivePartnerTargetingRingRotationDegreesPerSecond_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowEnemyTargetingRing = { "bShowEnemyTargetingRing", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowEnemyTargetingRing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowEnemyTargetingRing_MetaData), NewProp_bShowEnemyTargetingRing_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_EnemyTargetingRingSprite = { "EnemyTargetingRingSprite", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetingRingSprite), Z_Construct_UClass_UPaperSprite, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetingRingSprite_MetaData), NewProp_EnemyTargetingRingSprite_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_EnemyTargetingRingScale = { "EnemyTargetingRingScale", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetingRingScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetingRingScale_MetaData), NewProp_EnemyTargetingRingScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_EnemyTargetingRingGroundOffset = { "EnemyTargetingRingGroundOffset", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetingRingGroundOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetingRingGroundOffset_MetaData), NewProp_EnemyTargetingRingGroundOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_EnemyTargetingRingRotationDegreesPerSecond = { "EnemyTargetingRingRotationDegreesPerSecond", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetingRingRotationDegreesPerSecond), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetingRingRotationDegreesPerSecond_MetaData), NewProp_EnemyTargetingRingRotationDegreesPerSecond_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_TargetingRingSpriteRelativeRotation = { "TargetingRingSpriteRelativeRotation", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, TargetingRingSpriteRelativeRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingRingSpriteRelativeRotation_MetaData), NewProp_TargetingRingSpriteRelativeRotation_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bScaleTargetingRingsToDigimonCapsule = { "bScaleTargetingRingsToDigimonCapsule", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bScaleTargetingRingsToDigimonCapsule_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bScaleTargetingRingsToDigimonCapsule_MetaData), NewProp_bScaleTargetingRingsToDigimonCapsule_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TargetingRingReferenceCapsuleRadius = { "TargetingRingReferenceCapsuleRadius", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, TargetingRingReferenceCapsuleRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingRingReferenceCapsuleRadius_MetaData), NewProp_TargetingRingReferenceCapsuleRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TargetingRingMinimumAutoScale = { "TargetingRingMinimumAutoScale", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, TargetingRingMinimumAutoScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingRingMinimumAutoScale_MetaData), NewProp_TargetingRingMinimumAutoScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TargetingRingMaximumAutoScale = { "TargetingRingMaximumAutoScale", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, TargetingRingMaximumAutoScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingRingMaximumAutoScale_MetaData), NewProp_TargetingRingMaximumAutoScale_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_TargetingVisualTranslucentSortPriority = { "TargetingVisualTranslucentSortPriority", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, TargetingVisualTranslucentSortPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingVisualTranslucentSortPriority_MetaData), NewProp_TargetingVisualTranslucentSortPriority_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowEnemyTargetArrow = { "bShowEnemyTargetArrow", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bShowEnemyTargetArrow_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowEnemyTargetArrow_MetaData), NewProp_bShowEnemyTargetArrow_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPreferNiagaraEnemyTargetArrow = { "bPreferNiagaraEnemyTargetArrow", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFFrameworkSettings), &UHT_STATICS::NewProp_bPreferNiagaraEnemyTargetArrow_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreferNiagaraEnemyTargetArrow_MetaData), NewProp_bPreferNiagaraEnemyTargetArrow_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_EnemyTargetArrowNiagaraSystem = { "EnemyTargetArrowNiagaraSystem", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetArrowNiagaraSystem), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetArrowNiagaraSystem_MetaData), NewProp_EnemyTargetArrowNiagaraSystem_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_EnemyTargetArrowCascadeSystem = { "EnemyTargetArrowCascadeSystem", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetArrowCascadeSystem), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetArrowCascadeSystem_MetaData), NewProp_EnemyTargetArrowCascadeSystem_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_EnemyTargetArrowHeightOffset = { "EnemyTargetArrowHeightOffset", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetArrowHeightOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetArrowHeightOffset_MetaData), NewProp_EnemyTargetArrowHeightOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_EnemyTargetArrowScale = { "EnemyTargetArrowScale", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetArrowScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetArrowScale_MetaData), NewProp_EnemyTargetArrowScale_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_EnemyTargetArrowRotation = { "EnemyTargetArrowRotation", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetArrowRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetArrowRotation_MetaData), NewProp_EnemyTargetArrowRotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_EnemyTargetArrowBobAmplitude = { "EnemyTargetArrowBobAmplitude", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetArrowBobAmplitude), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetArrowBobAmplitude_MetaData), NewProp_EnemyTargetArrowBobAmplitude_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_EnemyTargetArrowBobFrequencyHz = { "EnemyTargetArrowBobFrequencyHz", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, EnemyTargetArrowBobFrequencyHz), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetArrowBobFrequencyHz_MetaData), NewProp_EnemyTargetArrowBobFrequencyHz_MetaData) };
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
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ServerPublicAddress = { "ServerPublicAddress", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, ServerPublicAddress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerPublicAddress_MetaData), NewProp_ServerPublicAddress_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_GamePort = { "GamePort", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, GamePort), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GamePort_MetaData), NewProp_GamePort_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_AdminHostingPasswordInput = { "AdminHostingPasswordInput", nullptr, (EPropertyFlags)0x0010000000002001, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, AdminHostingPasswordInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdminHostingPasswordInput_MetaData), NewProp_AdminHostingPasswordInput_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_AdminHostingPasswordDigest = { "AdminHostingPasswordDigest", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFrameworkSettings, AdminHostingPasswordDigest), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdminHostingPasswordDigest_MetaData), NewProp_AdminHostingPasswordDigest_MetaData) };
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
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnablePlayerCameraZoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDefaultPlayerCameraZoomInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerCameraDefaultBoomLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerCameraMinimumBoomLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerCameraMaximumBoomLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerCameraMouseWheelZoomStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerCameraZoomInterpolationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIgnorePlayersAndDigimonForCameraCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnablePlayerFootsteps,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerFootstepSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerFootstepMinimumSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerFootstepWalkStrideDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerFootstepSprintStrideDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerFootstepCrouchStrideDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerFootstepVolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerFootstepPitchMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableFrameworkMusic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FrontendMusic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OpenWorldMusic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BattleMusic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MusicMasterVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FrontendMusicVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OpenWorldMusicVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BattleMusicVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MusicCrossfadeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BattleMusicReleaseDelaySeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAutomaticallyLoopMusic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MusicStateEvaluationInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AccountSaveSlot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAutoRegisterUnknownAccounts,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxActiveDigimonInventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxPartyDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxDigimonBankStorage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonBankSlotsPerPage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAllowPartySwitchingDuringCombat,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartnerSpawnOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatQuickBarWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartyQuickBarWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowNativePartyQuickBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDefaultPartyQuickAccessInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartyQuickBarBottomSafeOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInventoryWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDigiDex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDefaultDigimonInventoryMenuInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanNotificationWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowNativeScanNotifications,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableWorldChat,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDefaultWorldChatInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatMaxMessageLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatClientHistoryLimit,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatServerHistoryLimit,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatMinimumSendInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatBurstWindowSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatMaxMessagesPerBurst,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowWorldChatTimestamps,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatBottomSafeOffset,
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
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDigivolutionSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAllowBankDigivolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bBlockDigivolutionDuringCombat,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bHideUIForSummonedDigivolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionPresentationDurationSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultDigivolutionNiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultDigivolutionCascadeParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPreferNiagaraDigivolutionVFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultDigivolutionSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionSoundVolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionSoundPitchMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowNativeCombatQuickBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableCombatTargetingVisuals,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowActivePartnerTargetingRing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActivePartnerTargetingRingSprite,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActivePartnerTargetingRingScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActivePartnerTargetingRingGroundOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActivePartnerTargetingRingRotationDegreesPerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowEnemyTargetingRing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetingRingSprite,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetingRingScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetingRingGroundOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetingRingRotationDegreesPerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetingRingSpriteRelativeRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bScaleTargetingRingsToDigimonCapsule,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetingRingReferenceCapsuleRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetingRingMinimumAutoScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetingRingMaximumAutoScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetingVisualTranslucentSortPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowEnemyTargetArrow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPreferNiagaraEnemyTargetArrow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetArrowNiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetArrowCascadeSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetArrowHeightOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetArrowScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetArrowRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetArrowBobAmplitude,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetArrowBobFrequencyHz,
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
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ServerPublicAddress,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GamePort,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AdminHostingPasswordInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AdminHostingPasswordDigest,
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
		{ Z_Construct_UClass_UDMFFrameworkSettings, TEXT("UDMFFrameworkSettings"), &Z_Registration_Info_UClass_UDMFFrameworkSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFFrameworkSettings), 2885438718U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Settings_DMFFrameworkSettings_h__Script_DigimonMMOFramework_5073b29574e3884a6d80f427f6f05f73e24fa809{
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
