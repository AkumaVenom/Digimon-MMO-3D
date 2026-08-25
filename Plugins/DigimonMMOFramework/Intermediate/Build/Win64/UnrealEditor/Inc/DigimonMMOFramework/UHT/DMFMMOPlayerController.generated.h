// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFMMOPlayerController.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFMMOPlayerController_generated_h
#error "DMFMMOPlayerController.generated.h already included, missing '#pragma once' in DMFMMOPlayerController.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFMMOPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ADMFDigimonCharacter;
class ADMFHealerActor;
struct FGuid;
struct FPrimaryAssetId;

// ********** Begin Class ADMFMMOPlayerController **************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientHealerInteractionResult_Implementation(bool bSuccess, FText const& Message, int32 DigimonHealed); \
	virtual void ServerRequestUseHealer_Implementation(ADMFHealerActor* Healer); \
	virtual void ServerEnsureFrameworkPlayerAvatar_Implementation(); \
	DECLARE_FUNCTION(execHandlePlayerSkinRequirementChanged); \
	DECLARE_FUNCTION(execHandleCareSequenceFinished); \
	DECLARE_FUNCTION(execHandleCareSequenceStarted); \
	DECLARE_FUNCTION(execHandleScanDataRewardGranted); \
	DECLARE_FUNCTION(execHandleStarterRequirementChanged); \
	DECLARE_FUNCTION(execRefreshCombatQuickBar); \
	DECLARE_FUNCTION(execClientHealerInteractionResult); \
	DECLARE_FUNCTION(execServerRequestUseHealer); \
	DECLARE_FUNCTION(execRequestUseHealer); \
	DECLARE_FUNCTION(execCommandActivePartnerAbilitySlot); \
	DECLARE_FUNCTION(execCommandPartnerTargetAndAttack); \
	DECLARE_FUNCTION(execSelectDigimonCommandTargetUnderCursor); \
	DECLARE_FUNCTION(execSetDigimonCommandTarget); \
	DECLARE_FUNCTION(execIsDigimonMenuUIOpen); \
	DECLARE_FUNCTION(execToggleDigimonMenuUI); \
	DECLARE_FUNCTION(execCloseDigimonMenuUI); \
	DECLARE_FUNCTION(execOpenDigimonMenuUI); \
	DECLARE_FUNCTION(execIsDigimonInventoryUIOpen); \
	DECLARE_FUNCTION(execIsCarePresentationActive); \
	DECLARE_FUNCTION(execOpenCareUI); \
	DECLARE_FUNCTION(execOpenScanMaterializeUI); \
	DECLARE_FUNCTION(execRefreshDigimonInventoryUI); \
	DECLARE_FUNCTION(execToggleDigimonInventoryUI); \
	DECLARE_FUNCTION(execCloseDigimonInventoryUI); \
	DECLARE_FUNCTION(execOpenDigimonInventoryUI); \
	DECLARE_FUNCTION(execIsPlayerSkinSelectionUIOpen); \
	DECLARE_FUNCTION(execRefreshPlayerSkinSelectionUI); \
	DECLARE_FUNCTION(execTogglePlayerSkinSelectionUI); \
	DECLARE_FUNCTION(execClosePlayerSkinSelectionUI); \
	DECLARE_FUNCTION(execOpenPlayerSkinSelectionUI); \
	DECLARE_FUNCTION(execRefreshStarterSelectionUI); \
	DECLARE_FUNCTION(execIsFrameworkPlayerAvatarPossessed); \
	DECLARE_FUNCTION(execServerEnsureFrameworkPlayerAvatar);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_24_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFMMOPlayerController_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_24_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFMMOPlayerController_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFMMOPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFMMOPlayerController) \
	DECLARE_SERIALIZER(ADMFMMOPlayerController)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADMFMMOPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFMMOPlayerController(ADMFMMOPlayerController&&) = delete; \
	ADMFMMOPlayerController(const ADMFMMOPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFMMOPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFMMOPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADMFMMOPlayerController) \
	NO_API virtual ~ADMFMMOPlayerController();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_21_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_24_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_24_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFMMOPlayerController;

// ********** End Class ADMFMMOPlayerController ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
