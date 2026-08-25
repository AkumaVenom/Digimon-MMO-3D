// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFSessionSubsystem.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFSessionSubsystem_generated_h
#error "DMFSessionSubsystem.generated.h already included, missing '#pragma once' in DMFSessionSubsystem.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFSessionSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDMFSessionSubsystem *****************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetLastStatus); \
	DECLARE_FUNCTION(execGetStagedUsername); \
	DECLARE_FUNCTION(execIsAdminUnlocked); \
	DECLARE_FUNCTION(execIsLoggedInLocally); \
	DECLARE_FUNCTION(execHostAndPlay); \
	DECLARE_FUNCTION(execJoinGame); \
	DECLARE_FUNCTION(execUnlockAdmin); \
	DECLARE_FUNCTION(execLogout); \
	DECLARE_FUNCTION(execLogin);


struct Z_Construct_UClass_UDMFSessionSubsystem_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFSessionSubsystem(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h_16_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFSessionSubsystem_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFSessionSubsystem(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFSessionSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFSessionSubsystem) \
	DECLARE_SERIALIZER(UDMFSessionSubsystem)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFSessionSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFSessionSubsystem(UDMFSessionSubsystem&&) = delete; \
	UDMFSessionSubsystem(const UDMFSessionSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFSessionSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFSessionSubsystem); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFSessionSubsystem) \
	NO_API virtual ~UDMFSessionSubsystem();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h_13_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFSessionSubsystem;

// ********** End Class UDMFSessionSubsystem *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
