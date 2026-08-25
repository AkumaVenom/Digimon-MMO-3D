// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFWildDigimonCharacter.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFWildDigimonCharacter_generated_h
#error "DMFWildDigimonCharacter.generated.h already included, missing '#pragma once' in DMFWildDigimonCharacter.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFWildDigimonCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EDMFWildGroundTransitionMode : uint8;
enum class EDMFWildSpawnRarity : uint8;

// ********** Begin ScriptStruct FDMFWildGroundTransitionState *************************************
struct Z_Construct_UScriptStruct_FDMFWildGroundTransitionState_Statics;
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWildGroundTransitionState(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_22_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDMFWildGroundTransitionState_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FDMFWildGroundTransitionState(ETypeConstructPhase::Inner); }


struct FDMFWildGroundTransitionState;
// ********** End ScriptStruct FDMFWildGroundTransitionState ***************************************

// ********** Begin Class ADMFWildDigimonCharacter *************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_GroundTransitionState); \
	DECLARE_FUNCTION(execIsGroundTransitionActive); \
	DECLARE_FUNCTION(execBeginGroundDespawn); \
	DECLARE_FUNCTION(execBeginGroundEmergence); \
	DECLARE_FUNCTION(execRefreshWildHomeAndAutomation); \
	DECLARE_FUNCTION(execInitializeWildDigimon); \
	DECLARE_FUNCTION(execIsWildRetaliationEnabled); \
	DECLARE_FUNCTION(execSetWildRetaliationEnabled); \
	DECLARE_FUNCTION(execIsWildAutoBattleEnabled); \
	DECLARE_FUNCTION(execSetWildAutoBattleEnabled);


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_49_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFWildDigimonCharacter_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFWildDigimonCharacter(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_49_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFWildDigimonCharacter_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFWildDigimonCharacter(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFWildDigimonCharacter, ADMFDigimonCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFWildDigimonCharacter) \
	DECLARE_SERIALIZER(ADMFWildDigimonCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bAutoBattle=NETFIELD_REP_START, \
		bRetaliateWhenAttacked, \
		bSpawnerManaged, \
		SpawnRarity, \
		SpawnHomeLocation, \
		GroundTransitionState, \
		NETFIELD_REP_END=GroundTransitionState	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_49_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFWildDigimonCharacter(ADMFWildDigimonCharacter&&) = delete; \
	ADMFWildDigimonCharacter(const ADMFWildDigimonCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFWildDigimonCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFWildDigimonCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFWildDigimonCharacter) \
	NO_API virtual ~ADMFWildDigimonCharacter();


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_46_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_49_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_49_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_49_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h_49_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFWildDigimonCharacter;

// ********** End Class ADMFWildDigimonCharacter ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h

// ********** Begin Enum EDMFWildGroundTransitionMode **********************************************
#define FOREACH_ENUM_EDMFWILDGROUNDTRANSITIONMODE(op) \
	op(EDMFWildGroundTransitionMode::None) \
	op(EDMFWildGroundTransitionMode::Emerging) \
	op(EDMFWildGroundTransitionMode::Despawning) 

enum class EDMFWildGroundTransitionMode : uint8;
template<> struct TIsUEnumClass<EDMFWildGroundTransitionMode> { enum { Value = true }; };
template<> UE_NODEBUG DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFWildGroundTransitionMode>();
// ********** End Enum EDMFWildGroundTransitionMode ************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
