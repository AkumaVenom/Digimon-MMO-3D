// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFHealerActor.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFHealerActor_generated_h
#error "DMFHealerActor.generated.h already included, missing '#pragma once' in DMFHealerActor.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFHealerActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ADMFPlayerState;
class APlayerController;

// ********** Begin Class ADMFHealerActor **********************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void MulticastHealPresentation_Implementation(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed); \
	DECLARE_FUNCTION(execMulticastHealPresentation); \
	DECLARE_FUNCTION(execOnRep_Enabled); \
	DECLARE_FUNCTION(execSetHealerEnabled); \
	DECLARE_FUNCTION(execTryHealPlayerAuthoritative); \
	DECLARE_FUNCTION(execIsPlayerWithinInteractionRange); \
	DECLARE_FUNCTION(execRequestHeal);


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_21_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFHealerActor_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFHealerActor(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_21_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFHealerActor_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFHealerActor(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFHealerActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFHealerActor) \
	DECLARE_SERIALIZER(ADMFHealerActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bEnabled=NETFIELD_REP_START, \
		NETFIELD_REP_END=bEnabled	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_21_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFHealerActor(ADMFHealerActor&&) = delete; \
	ADMFHealerActor(const ADMFHealerActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFHealerActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFHealerActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFHealerActor) \
	NO_API virtual ~ADMFHealerActor();


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_18_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_21_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_21_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFHealerActor;

// ********** End Class ADMFHealerActor ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
