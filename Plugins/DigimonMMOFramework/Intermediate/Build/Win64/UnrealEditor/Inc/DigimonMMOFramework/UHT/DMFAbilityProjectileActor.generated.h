// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFAbilityProjectileActor.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFAbilityProjectileActor_generated_h
#error "DMFAbilityProjectileActor.generated.h already included, missing '#pragma once' in DMFAbilityProjectileActor.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFAbilityProjectileActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ADMFDigimonCharacter;

// ********** Begin Class ADMFAbilityProjectileActor ***********************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_ProjectileDefinition); \
	DECLARE_FUNCTION(execRefreshProjectilePresentation); \
	DECLARE_FUNCTION(execGetTargetDigimon); \
	DECLARE_FUNCTION(execGetSourceDigimon); \
	DECLARE_FUNCTION(execGetAbilityId);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_26_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFAbilityProjectileActor_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFAbilityProjectileActor(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_26_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFAbilityProjectileActor_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFAbilityProjectileActor(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFAbilityProjectileActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFAbilityProjectileActor) \
	DECLARE_SERIALIZER(ADMFAbilityProjectileActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		AbilityId=NETFIELD_REP_START, \
		SourceDigimon, \
		TargetDigimon, \
		TravelDirection, \
		NETFIELD_REP_END=TravelDirection	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_26_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFAbilityProjectileActor(ADMFAbilityProjectileActor&&) = delete; \
	ADMFAbilityProjectileActor(const ADMFAbilityProjectileActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFAbilityProjectileActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFAbilityProjectileActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFAbilityProjectileActor) \
	NO_API virtual ~ADMFAbilityProjectileActor();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_23_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_26_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_26_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFAbilityProjectileActor;

// ********** End Class ADMFAbilityProjectileActor *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
