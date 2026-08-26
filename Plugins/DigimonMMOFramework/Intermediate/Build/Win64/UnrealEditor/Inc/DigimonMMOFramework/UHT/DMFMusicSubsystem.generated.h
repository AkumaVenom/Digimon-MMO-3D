// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/DMFMusicSubsystem.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFMusicSubsystem_generated_h
#error "DMFMusicSubsystem.generated.h already included, missing '#pragma once' in DMFMusicSubsystem.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFMusicSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EDMFMusicState : uint8;

// ********** Begin Class UDMFMusicSubsystem *******************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsMusicSuppressed); \
	DECLARE_FUNCTION(execSetMusicSuppressed); \
	DECLARE_FUNCTION(execRefreshMusicState); \
	DECLARE_FUNCTION(execGetCurrentMusicState);


struct Z_Construct_UClass_UDMFMusicSubsystem_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFMusicSubsystem(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h_25_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFMusicSubsystem_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFMusicSubsystem(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFMusicSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFMusicSubsystem) \
	DECLARE_SERIALIZER(UDMFMusicSubsystem)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFMusicSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFMusicSubsystem(UDMFMusicSubsystem&&) = delete; \
	UDMFMusicSubsystem(const UDMFMusicSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFMusicSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFMusicSubsystem); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFMusicSubsystem) \
	NO_API virtual ~UDMFMusicSubsystem();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h_22_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h_25_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFMusicSubsystem;

// ********** End Class UDMFMusicSubsystem *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
