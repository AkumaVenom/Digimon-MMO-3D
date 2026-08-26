// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFDigimonCharacter.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFDigimonCharacter_generated_h
#error "DMFDigimonCharacter.generated.h already included, missing '#pragma once' in DMFDigimonCharacter.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFDigimonCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ADMFPlayerState;
class UDMFDigimonSpeciesData;
struct FDMFDigimonInstance;

// ********** Begin Class ADMFDigimonCharacter *****************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void MulticastPlayCareWasteCue_Implementation(int32 FartSoundIndex); \
	virtual void MulticastPlayCareFeedingCue_Implementation(int32 FeedingVoiceIndex); \
	DECLARE_FUNCTION(execOnRep_DigimonState); \
	DECLARE_FUNCTION(execRefreshCameraCollisionPolicy); \
	DECLARE_FUNCTION(execRefreshFrameworkCustomDepth); \
	DECLARE_FUNCTION(execRefreshWorldNameplate); \
	DECLARE_FUNCTION(execIsDefeatedPresentationActive); \
	DECLARE_FUNCTION(execClearDefeatedPresentation); \
	DECLARE_FUNCTION(execApplyDefeatedPresentation); \
	DECLARE_FUNCTION(execMulticastPlayCareWasteCue); \
	DECLARE_FUNCTION(execMulticastPlayCareFeedingCue); \
	DECLARE_FUNCTION(execResolveSpeciesData); \
	DECLARE_FUNCTION(execGetCombatFacingTarget); \
	DECLARE_FUNCTION(execIsFacingActor); \
	DECLARE_FUNCTION(execStopCombatFacingTarget); \
	DECLARE_FUNCTION(execStartCombatFacingTarget); \
	DECLARE_FUNCTION(execConfigureCombatAutomation); \
	DECLARE_FUNCTION(execSetCombatTeamId); \
	DECLARE_FUNCTION(execInitializeFromInstance);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_18_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFDigimonCharacter_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_18_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFDigimonCharacter_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFDigimonCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFDigimonCharacter) \
	DECLARE_SERIALIZER(ADMFDigimonCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		DigimonInstanceId=NETFIELD_REP_START, \
		SpeciesId, \
		ReplicatedNickname, \
		ReplicatedStats, \
		ReplicatedAbilityIds, \
		OwningPlayerState, \
		CombatTeamId, \
		NETFIELD_REP_END=CombatTeamId	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFDigimonCharacter(ADMFDigimonCharacter&&) = delete; \
	ADMFDigimonCharacter(const ADMFDigimonCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFDigimonCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFDigimonCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFDigimonCharacter) \
	NO_API virtual ~ADMFDigimonCharacter();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_15_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_18_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFDigimonCharacter;

// ********** End Class ADMFDigimonCharacter *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
