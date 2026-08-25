// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Persistence/DMFAccountPersistenceSubsystem.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFAccountPersistenceSubsystem_generated_h
#error "DMFAccountPersistenceSubsystem.generated.h already included, missing '#pragma once' in DMFAccountPersistenceSubsystem.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFAccountPersistenceSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FDMFAccountRecord;

// ********** Begin Class UDMFAccountPersistenceSubsystem ******************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFlush); \
	DECLARE_FUNCTION(execSaveAccount); \
	DECLARE_FUNCTION(execGetAccount); \
	DECLARE_FUNCTION(execValidateOrRegisterAccount);


struct Z_Construct_UClass_UDMFAccountPersistenceSubsystem_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFAccountPersistenceSubsystem(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h_13_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFAccountPersistenceSubsystem_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFAccountPersistenceSubsystem(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFAccountPersistenceSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFAccountPersistenceSubsystem) \
	DECLARE_SERIALIZER(UDMFAccountPersistenceSubsystem)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFAccountPersistenceSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFAccountPersistenceSubsystem(UDMFAccountPersistenceSubsystem&&) = delete; \
	UDMFAccountPersistenceSubsystem(const UDMFAccountPersistenceSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFAccountPersistenceSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFAccountPersistenceSubsystem); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFAccountPersistenceSubsystem) \
	NO_API virtual ~UDMFAccountPersistenceSubsystem();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h_10_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h_13_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFAccountPersistenceSubsystem;

// ********** End Class UDMFAccountPersistenceSubsystem ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
