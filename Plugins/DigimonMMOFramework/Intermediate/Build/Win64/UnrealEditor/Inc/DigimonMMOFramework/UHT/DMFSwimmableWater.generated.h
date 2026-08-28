// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFSwimmableWater.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFSwimmableWater_generated_h
#error "DMFSwimmableWater.generated.h already included, missing '#pragma once' in DMFSwimmableWater.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFSwimmableWater_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ADMFPlayerAvatarCharacter;
class UMaterialInterface;
class UPrimitiveComponent;
struct FDMFUnderwaterPostProcessSettings;
struct FHitResult;

// ********** Begin ScriptStruct FDMFUnderwaterPostProcessSettings *********************************
struct Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings_Statics;
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_30_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings(ETypeConstructPhase::Inner); }


struct FDMFUnderwaterPostProcessSettings;
// ********** End ScriptStruct FDMFUnderwaterPostProcessSettings ***********************************

// ********** Begin Class ADMFSwimmableWater *******************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_142_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_UnderwaterPostProcessSettings); \
	DECLARE_FUNCTION(execOnRep_WaterConfiguration); \
	DECLARE_FUNCTION(execHandleSwimmingBoundsEndOverlap); \
	DECLARE_FUNCTION(execHandleSwimmingBoundsBeginOverlap); \
	DECLARE_FUNCTION(execRefreshWaterGeometry); \
	DECLARE_FUNCTION(execRefreshUnderwaterPostProcessPresentation); \
	DECLARE_FUNCTION(execSetUnderwaterPostProcessMaterial); \
	DECLARE_FUNCTION(execSetUnderwaterPostProcessEnabled); \
	DECLARE_FUNCTION(execSetUnderwaterPostProcessSettings); \
	DECLARE_FUNCTION(execGetUnderwaterPostProcessSettings); \
	DECLARE_FUNCTION(execSetWaterMaterial); \
	DECLARE_FUNCTION(execSetWaterPriority); \
	DECLARE_FUNCTION(execSetWaterSurfaceZOffset); \
	DECLARE_FUNCTION(execSetSurfaceOverlapHeight); \
	DECLARE_FUNCTION(execSetWaterDepth); \
	DECLARE_FUNCTION(execSetWaterSurfaceSize); \
	DECLARE_FUNCTION(execSetSwimmingEnabled); \
	DECLARE_FUNCTION(execIsSwimmingEnabled); \
	DECLARE_FUNCTION(execIsWorldLocationInsideSwimmingBounds); \
	DECLARE_FUNCTION(execGetDepthBelowSurface); \
	DECLARE_FUNCTION(execGetWaterBottomWorldZ); \
	DECLARE_FUNCTION(execGetWaterSurfaceWorldZ);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_142_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFSwimmableWater_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFSwimmableWater(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_142_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFSwimmableWater_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFSwimmableWater(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFSwimmableWater, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFSwimmableWater) \
	DECLARE_SERIALIZER(ADMFSwimmableWater) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		WaterSurfaceSize=NETFIELD_REP_START, \
		WaterDepth, \
		SurfaceOverlapHeight, \
		WaterSurfaceZOffset, \
		bSwimmingEnabled, \
		WaterPriority, \
		SurfaceSwimSpeed, \
		UnderwaterSwimSpeed, \
		SprintSwimSpeed, \
		SwimAcceleration, \
		SwimBrakingDeceleration, \
		bEnableSurfaceAssist, \
		SurfaceRideDepth, \
		SurfaceAssistStrength, \
		MaximumSurfaceAssistSpeed, \
		DiveCameraForwardZThreshold, \
		UnderwaterEnterDepth, \
		UnderwaterExitDepth, \
		UnderwaterPostProcessSettings, \
		NETFIELD_REP_END=UnderwaterPostProcessSettings	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_142_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFSwimmableWater(ADMFSwimmableWater&&) = delete; \
	ADMFSwimmableWater(const ADMFSwimmableWater&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFSwimmableWater); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFSwimmableWater); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFSwimmableWater) \
	NO_API virtual ~ADMFSwimmableWater();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_139_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_142_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_142_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_142_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_142_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h_142_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFSwimmableWater;

// ********** End Class ADMFSwimmableWater *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h

// ********** Begin Enum EDMFPlayerSwimState *******************************************************
#define FOREACH_ENUM_EDMFPLAYERSWIMSTATE(op) \
	op(EDMFPlayerSwimState::None) \
	op(EDMFPlayerSwimState::Surface) \
	op(EDMFPlayerSwimState::Underwater) 

enum class EDMFPlayerSwimState : uint8;
template<> struct TIsUEnumClass<EDMFPlayerSwimState> { enum { Value = true }; };
template<> UE_NODEBUG DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFPlayerSwimState>();
// ********** End Enum EDMFPlayerSwimState *********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
