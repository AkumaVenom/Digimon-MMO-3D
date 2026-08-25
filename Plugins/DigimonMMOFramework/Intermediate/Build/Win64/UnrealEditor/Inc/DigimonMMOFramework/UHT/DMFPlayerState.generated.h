// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFPlayerState.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFPlayerState_generated_h
#error "DMFPlayerState.generated.h already included, missing '#pragma once' in DMFPlayerState.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFPlayerState_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ADMFPlayerState **********************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerState_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetAuthenticatedAccount); \
	DECLARE_FUNCTION(execGetAuthenticatedUsername);


struct Z_Construct_UClass_ADMFPlayerState_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerState(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerState_h_13_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFPlayerState_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFPlayerState(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFPlayerState, APlayerState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFPlayerState) \
	DECLARE_SERIALIZER(ADMFPlayerState) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		AuthenticatedUsername=NETFIELD_REP_START, \
		NETFIELD_REP_END=AuthenticatedUsername	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerState_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFPlayerState(ADMFPlayerState&&) = delete; \
	ADMFPlayerState(const ADMFPlayerState&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFPlayerState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFPlayerState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFPlayerState) \
	NO_API virtual ~ADMFPlayerState();


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerState_h_10_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerState_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerState_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerState_h_13_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerState_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFPlayerState;

// ********** End Class ADMFPlayerState ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerState_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
