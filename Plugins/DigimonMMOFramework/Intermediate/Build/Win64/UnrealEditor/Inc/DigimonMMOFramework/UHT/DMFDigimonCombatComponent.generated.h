// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/DMFDigimonCombatComponent.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFDigimonCombatComponent_generated_h
#error "DMFDigimonCombatComponent.generated.h already included, missing '#pragma once' in DMFDigimonCombatComponent.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFDigimonCombatComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ADMFDigimonCharacter;
class UDMFDigimonAbilityData;
enum class EDMFCombatState : uint8;

// ********** Begin Class UDMFDigimonCombatComponent ***********************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void MulticastVictoryCue_Implementation(ADMFDigimonCharacter* DefeatedDigimon); \
	virtual void MulticastDefeatedCue_Implementation(ADMFDigimonCharacter* Killer); \
	virtual void MulticastPlayAbilityCue_Implementation(FName AbilityId, ADMFDigimonCharacter* Target); \
	DECLARE_FUNCTION(execMulticastVictoryCue); \
	DECLARE_FUNCTION(execMulticastDefeatedCue); \
	DECLARE_FUNCTION(execMulticastPlayAbilityCue); \
	DECLARE_FUNCTION(execOnRep_CombatState); \
	DECLARE_FUNCTION(execOnRep_CurrentTarget); \
	DECLARE_FUNCTION(execOnRep_Vitals); \
	DECLARE_FUNCTION(execResolveAbilityData); \
	DECLARE_FUNCTION(execNotifyAuthoritativeVictory); \
	DECLARE_FUNCTION(execRestoreVitals); \
	DECLARE_FUNCTION(execRestoreVitalsToMaximum); \
	DECLARE_FUNCTION(execApplyAuthoritativeDamage); \
	DECLARE_FUNCTION(execQueueOrExecuteAbilitySlot); \
	DECLARE_FUNCTION(execTryExecuteAbilitySlot); \
	DECLARE_FUNCTION(execTryExecuteAbilityById); \
	DECLARE_FUNCTION(execSetAuthoritativeTarget); \
	DECLARE_FUNCTION(execIsAutoBattleEnabled); \
	DECLARE_FUNCTION(execGetIncomingDamageMultiplier); \
	DECLARE_FUNCTION(execGetOutgoingDamageMultiplier); \
	DECLARE_FUNCTION(execConfigureDamageTuning); \
	DECLARE_FUNCTION(execIsRetaliating); \
	DECLARE_FUNCTION(execIsRetaliationEnabled); \
	DECLARE_FUNCTION(execConfigureRetaliation); \
	DECLARE_FUNCTION(execConfigureAutomation); \
	DECLARE_FUNCTION(execInitializeRuntimeVitals); \
	DECLARE_FUNCTION(execCanAttackTarget); \
	DECLARE_FUNCTION(execGetRemainingCooldown); \
	DECLARE_FUNCTION(execIsDefeated); \
	DECLARE_FUNCTION(execGetCurrentTarget); \
	DECLARE_FUNCTION(execGetCombatState); \
	DECLARE_FUNCTION(execGetCurrentSP); \
	DECLARE_FUNCTION(execGetCurrentHP);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_25_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDMFDigimonCombatComponent_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonCombatComponent(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_25_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFDigimonCombatComponent_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFDigimonCombatComponent(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFDigimonCombatComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFDigimonCombatComponent) \
	DECLARE_SERIALIZER(UDMFDigimonCombatComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentHP=NETFIELD_REP_START, \
		CurrentSP, \
		CombatState, \
		CurrentTarget, \
		ReplicatedCooldowns, \
		NETFIELD_REP_END=ReplicatedCooldowns	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFDigimonCombatComponent(UDMFDigimonCombatComponent&&) = delete; \
	UDMFDigimonCombatComponent(const UDMFDigimonCombatComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFDigimonCombatComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFDigimonCombatComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDMFDigimonCombatComponent) \
	NO_API virtual ~UDMFDigimonCombatComponent();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_22_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_25_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_25_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFDigimonCombatComponent;

// ********** End Class UDMFDigimonCombatComponent *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
