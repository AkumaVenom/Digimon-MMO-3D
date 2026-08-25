// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFWildDigimonSpawner.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFWildDigimonSpawner_generated_h
#error "DMFWildDigimonSpawner.generated.h already included, missing '#pragma once' in DMFWildDigimonSpawner.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFWildDigimonSpawner_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ADMFDigimonCharacter;
class ADMFWildDigimonCharacter;
enum class EDMFWildSpawnRarity : uint8;

// ********** Begin ScriptStruct FDMFWildSpawnRarityWeights ****************************************
struct Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights_Statics;
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_19_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights(ETypeConstructPhase::Inner); }


struct FDMFWildSpawnRarityWeights;
// ********** End ScriptStruct FDMFWildSpawnRarityWeights ******************************************

// ********** Begin ScriptStruct FDMFWildSpawnEntry ************************************************
struct Z_Construct_UScriptStruct_FDMFWildSpawnEntry_Statics;
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWildSpawnEntry(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_46_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDMFWildSpawnEntry_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FDMFWildSpawnEntry(ETypeConstructPhase::Inner); }


struct FDMFWildSpawnEntry;
// ********** End ScriptStruct FDMFWildSpawnEntry **************************************************

// ********** Begin Class ADMFWildDigimonSpawner ***************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_113_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleManagedWildDefeated); \
	DECLARE_FUNCTION(execHandleManagedWildDestroyed); \
	DECLARE_FUNCTION(execOnRep_SpawnerState); \
	DECLARE_FUNCTION(execSpawnOneWildDigimon); \
	DECLARE_FUNCTION(execForceDeactivateSpawner); \
	DECLARE_FUNCTION(execForceActivateSpawner); \
	DECLARE_FUNCTION(execRefreshSpawnerNow); \
	DECLARE_FUNCTION(execGetTargetPopulation); \
	DECLARE_FUNCTION(execGetAliveSpawnCount); \
	DECLARE_FUNCTION(execIsSpawnerActive);


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_113_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFWildDigimonSpawner_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFWildDigimonSpawner(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_113_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFWildDigimonSpawner_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFWildDigimonSpawner(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFWildDigimonSpawner, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFWildDigimonSpawner) \
	DECLARE_SERIALIZER(ADMFWildDigimonSpawner) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bSpawnerActive=NETFIELD_REP_START, \
		ReplicatedAliveCount, \
		ReplicatedTargetPopulation, \
		NETFIELD_REP_END=ReplicatedTargetPopulation	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_113_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFWildDigimonSpawner(ADMFWildDigimonSpawner&&) = delete; \
	ADMFWildDigimonSpawner(const ADMFWildDigimonSpawner&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFWildDigimonSpawner); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFWildDigimonSpawner); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFWildDigimonSpawner) \
	NO_API virtual ~ADMFWildDigimonSpawner();


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_110_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_113_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_113_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_113_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_113_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h_113_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFWildDigimonSpawner;

// ********** End Class ADMFWildDigimonSpawner *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
