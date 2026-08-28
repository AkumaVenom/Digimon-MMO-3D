// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFDayNightSky.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFDayNightSky_generated_h
#error "DMFDayNightSky.generated.h already included, missing '#pragma once' in DMFDayNightSky.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFDayNightSky_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EDMFDayNightPhase : uint8;
enum class EDMFDayNightTimeSource : uint8;

// ********** Begin Class ADMFDayNightSky **********************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_DayNightPhase); \
	DECLARE_FUNCTION(execOnRep_TimeAnchor); \
	DECLARE_FUNCTION(execRefreshSkyPresentation); \
	DECLARE_FUNCTION(execReloadDayNightState); \
	DECLARE_FUNCTION(execSaveDayNightStateNow); \
	DECLARE_FUNCTION(execAdvanceSimulatedTimeByHours); \
	DECLARE_FUNCTION(execSetSimulatedTimeOfDay); \
	DECLARE_FUNCTION(execSetAuthoritativeTimeSource); \
	DECLARE_FUNCTION(execIsNight); \
	DECLARE_FUNCTION(execIsDay); \
	DECLARE_FUNCTION(execGetDayNightPhase); \
	DECLARE_FUNCTION(execGetCurrentDayIndex); \
	DECLARE_FUNCTION(execGetTimeOfDayNormalized); \
	DECLARE_FUNCTION(execGetFormattedTime12Hour); \
	DECLARE_FUNCTION(execGetTimeOfDayHours);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_36_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFDayNightSky_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDayNightSky(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_36_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFDayNightSky_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFDayNightSky(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFDayNightSky, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFDayNightSky) \
	DECLARE_SERIALIZER(ADMFDayNightSky) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ReplicatedTimeOfDayHours=NETFIELD_REP_START, \
		ReplicatedDayIndex, \
		ReplicatedTimeSource, \
		ReplicatedTimeAnchorServerSeconds, \
		ReplicatedSimulatedDayLengthSeconds, \
		DayNightPhase, \
		NETFIELD_REP_END=DayNightPhase	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_36_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFDayNightSky(ADMFDayNightSky&&) = delete; \
	ADMFDayNightSky(const ADMFDayNightSky&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFDayNightSky); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFDayNightSky); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFDayNightSky) \
	NO_API virtual ~ADMFDayNightSky();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_33_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_36_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_36_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFDayNightSky;

// ********** End Class ADMFDayNightSky ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
