// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFPlayerAvatarCharacter.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFPlayerAvatarCharacter_generated_h
#error "DMFPlayerAvatarCharacter.generated.h already included, missing '#pragma once' in DMFPlayerAvatarCharacter.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFPlayerAvatarCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ADMFDigimonCharacter;
class UDMFPlayerSkinData;
enum class EDMFPlayerInteractionType : uint8;
struct FHitResult;
struct FPrimaryAssetId;

// ********** Begin Class ADMFPlayerAvatarCharacter ************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ServerSetSprinting_Implementation(bool bNewSprinting); \
	virtual void MulticastPlayPlayerFootstep_Implementation(); \
	DECLARE_FUNCTION(execOnRep_Sprinting); \
	DECLARE_FUNCTION(execServerSetSprinting); \
	DECLARE_FUNCTION(execMulticastPlayPlayerFootstep); \
	DECLARE_FUNCTION(execRefreshFrameworkCustomDepth); \
	DECLARE_FUNCTION(execGetAppliedPlayerSkinId); \
	DECLARE_FUNCTION(execApplyPlayerSkinData); \
	DECLARE_FUNCTION(execIsSprinting); \
	DECLARE_FUNCTION(execGetInteractionPromptForActor); \
	DECLARE_FUNCTION(execGetCurrentDigimonTarget); \
	DECLARE_FUNCTION(execGetLastInteractionActor); \
	DECLARE_FUNCTION(execFindInteractionTarget); \
	DECLARE_FUNCTION(execCommandDigimonAbilitySlot); \
	DECLARE_FUNCTION(execClearDigimonTarget); \
	DECLARE_FUNCTION(execInteractWithHealer); \
	DECLARE_FUNCTION(execInteractWithDigimonAndAttack); \
	DECLARE_FUNCTION(execTargetAndAttackDigimonFromActor); \
	DECLARE_FUNCTION(execInteractWithDigimon); \
	DECLARE_FUNCTION(execTargetDigimonFromActor); \
	DECLARE_FUNCTION(execInteractWithActor); \
	DECLARE_FUNCTION(execInteract); \
	DECLARE_FUNCTION(execPlayPlayerFootstepLocal); \
	DECLARE_FUNCTION(execResetNativeInputState); \
	DECLARE_FUNCTION(execStopSprinting); \
	DECLARE_FUNCTION(execStartSprinting); \
	DECLARE_FUNCTION(execRefreshCameraCollisionPolicy); \
	DECLARE_FUNCTION(execResetCameraZoom); \
	DECLARE_FUNCTION(execGetCameraZoomDistance); \
	DECLARE_FUNCTION(execSetCameraZoomDistance); \
	DECLARE_FUNCTION(execAddCameraZoomInput); \
	DECLARE_FUNCTION(execLookPitch); \
	DECLARE_FUNCTION(execLookYaw); \
	DECLARE_FUNCTION(execMoveRight); \
	DECLARE_FUNCTION(execMoveForward); \
	DECLARE_FUNCTION(execRefreshWorldNameplate);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_29_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFPlayerAvatarCharacter_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_29_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFPlayerAvatarCharacter_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFPlayerAvatarCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFPlayerAvatarCharacter) \
	DECLARE_SERIALIZER(ADMFPlayerAvatarCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsSprinting=NETFIELD_REP_START, \
		NETFIELD_REP_END=bIsSprinting	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_29_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFPlayerAvatarCharacter(ADMFPlayerAvatarCharacter&&) = delete; \
	ADMFPlayerAvatarCharacter(const ADMFPlayerAvatarCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFPlayerAvatarCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFPlayerAvatarCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFPlayerAvatarCharacter) \
	NO_API virtual ~ADMFPlayerAvatarCharacter();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_26_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_29_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_29_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFPlayerAvatarCharacter;

// ********** End Class ADMFPlayerAvatarCharacter **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
