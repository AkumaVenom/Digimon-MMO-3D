// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFDigimonCarePropActor.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFDigimonCarePropActor_generated_h
#error "DMFDigimonCarePropActor.generated.h already included, missing '#pragma once' in DMFDigimonCarePropActor.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFDigimonCarePropActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EDMFCarePropType : uint8;
struct FPrimaryAssetId;

// ********** Begin Class ADMFDigimonCarePropActor *************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_Presentation); \
	DECLARE_FUNCTION(execInitializeCareProp); \
	DECLARE_FUNCTION(execRefreshFrameworkCustomDepth);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_25_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFDigimonCarePropActor_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCarePropActor(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_25_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFDigimonCarePropActor_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFDigimonCarePropActor(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFDigimonCarePropActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFDigimonCarePropActor) \
	DECLARE_SERIALIZER(ADMFDigimonCarePropActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		SpeciesId=NETFIELD_REP_START, \
		PropType, \
		NETFIELD_REP_END=PropType	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFDigimonCarePropActor(ADMFDigimonCarePropActor&&) = delete; \
	ADMFDigimonCarePropActor(const ADMFDigimonCarePropActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFDigimonCarePropActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFDigimonCarePropActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFDigimonCarePropActor) \
	NO_API virtual ~ADMFDigimonCarePropActor();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_22_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_25_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_25_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFDigimonCarePropActor;

// ********** End Class ADMFDigimonCarePropActor ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h

// ********** Begin Enum EDMFCarePropType **********************************************************
#define FOREACH_ENUM_EDMFCAREPROPTYPE(op) \
	op(EDMFCarePropType::DigiMeat) \
	op(EDMFCarePropType::Waste) 

enum class EDMFCarePropType : uint8;
template<> struct TIsUEnumClass<EDMFCarePropType> { enum { Value = true }; };
template<> UE_NODEBUG DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFCarePropType>();
// ********** End Enum EDMFCarePropType ************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
