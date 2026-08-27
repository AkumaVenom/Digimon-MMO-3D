// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "DMFTypes.h"
#include "Engine/NetSerialization.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDigimonCombatComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent(ETypeConstructPhase);
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FVector_NetQuantize(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFAbilityCooldownState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFAbilityExecuted__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatStateChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatTargetChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatVitalsChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonCombatComponent(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonDefeated__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonAbilityData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonCombatComponent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFCombatVitalsChanged ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatVitalsChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFCombatVitalsChanged_Parms
	{
		int32 CurrentHP;
		int32 CurrentSP;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFCombatVitalsChanged constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentHP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentSP;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFCombatVitalsChanged constinit property declarations *****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFCombatVitalsChanged Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CurrentHP = { "CurrentHP", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFCombatVitalsChanged_Parms, CurrentHP), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CurrentSP = { "CurrentSP", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFCombatVitalsChanged_Parms, CurrentSP), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurrentHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurrentSP,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFCombatVitalsChanged Property Definitions ****************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFCombatVitalsChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFCombatVitalsChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFCombatVitalsChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatVitalsChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFCombatVitalsChanged *************************************************

// ********** Begin Delegate FDMFCombatTargetChanged ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatTargetChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFCombatTargetChanged_Parms
	{
		ADMFDigimonCharacter* NewTarget;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFCombatTargetChanged constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFCombatTargetChanged constinit property declarations *****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFCombatTargetChanged Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NewTarget = { "NewTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFCombatTargetChanged_Parms, NewTarget), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTarget,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFCombatTargetChanged Property Definitions ****************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFCombatTargetChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFCombatTargetChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFCombatTargetChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatTargetChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFCombatTargetChanged *************************************************

// ********** Begin Delegate FDMFCombatStateChanged ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatStateChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFCombatStateChanged_Parms
	{
		EDMFCombatState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFCombatStateChanged constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFCombatStateChanged constinit property declarations ******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFCombatStateChanged Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFCombatStateChanged_Parms, NewState), Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState, METADATA_PARAMS(0, nullptr) }; // f39157b31587da9510a9e9d2d63daa8f797fe530
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFCombatStateChanged Property Definitions *****************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFCombatStateChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFCombatStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFCombatStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatStateChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFCombatStateChanged **************************************************

// ********** Begin Delegate FDMFDigimonDefeated ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonDefeated__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFDigimonDefeated_Parms
	{
		ADMFDigimonCharacter* DefeatedDigimon;
		ADMFDigimonCharacter* Killer;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFDigimonDefeated constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefeatedDigimon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Killer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFDigimonDefeated constinit property declarations *********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFDigimonDefeated Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DefeatedDigimon = { "DefeatedDigimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonDefeated_Parms, DefeatedDigimon), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Killer = { "Killer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonDefeated_Parms, Killer), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefeatedDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Killer,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFDigimonDefeated Property Definitions ********************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFDigimonDefeated__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonDefeated_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonDefeated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonDefeated__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFDigimonDefeated *****************************************************

// ********** Begin Delegate FDMFAbilityExecuted ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFAbilityExecuted__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFAbilityExecuted_Parms
	{
		FName AbilityId;
		ADMFDigimonCharacter* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFAbilityExecuted constinit property declarations *******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFAbilityExecuted constinit property declarations *********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFAbilityExecuted Property Definitions ******************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFAbilityExecuted_Parms, AbilityId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFAbilityExecuted_Parms, Target), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFAbilityExecuted Property Definitions ********************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFAbilityExecuted__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFAbilityExecuted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFAbilityExecuted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFAbilityExecuted__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFAbilityExecuted *****************************************************

// ********** Begin Class UDMFDigimonCombatComponent Function ApplyAuthoritativeDamage *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_ApplyAuthoritativeDamage_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventApplyAuthoritativeDamage_Parms
	{
		int32 Damage;
		ADMFDigimonCharacter* InstigatorDigimon;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyAuthoritativeDamage constinit property declarations **************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InstigatorDigimon;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyAuthoritativeDamage constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyAuthoritativeDamage Property Definitions *************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventApplyAuthoritativeDamage_Parms, Damage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InstigatorDigimon = { "InstigatorDigimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventApplyAuthoritativeDamage_Parms, InstigatorDigimon), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventApplyAuthoritativeDamage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InstigatorDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplyAuthoritativeDamage Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "ApplyAuthoritativeDamage", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventApplyAuthoritativeDamage_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventApplyAuthoritativeDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_ApplyAuthoritativeDamage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execApplyAuthoritativeDamage)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Damage);
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_InstigatorDigimon);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->ApplyAuthoritativeDamage(Z_Param_Damage,Z_Param_InstigatorDigimon);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function ApplyAuthoritativeDamage ***************

// ********** Begin Class UDMFDigimonCombatComponent Function BP_OnAbilityCosmeticCue **************
struct DMFDigimonCombatComponent_eventBP_OnAbilityCosmeticCue_Parms
{
	FName AbilityId;
	ADMFDigimonCharacter* Target;
};
static FName NAME_UDMFDigimonCombatComponent_BP_OnAbilityCosmeticCue = FName(TEXT("BP_OnAbilityCosmeticCue"));
void UDMFDigimonCombatComponent::BP_OnAbilityCosmeticCue(FName AbilityId, ADMFDigimonCharacter* Target)
{
	DMFDigimonCombatComponent_eventBP_OnAbilityCosmeticCue_Parms Parms;
	Parms.AbilityId=AbilityId;
	Parms.Target=Target;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonCombatComponent_BP_OnAbilityCosmeticCue);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_BP_OnAbilityCosmeticCue_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Presentation" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnAbilityCosmeticCue constinit property declarations ***************
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnAbilityCosmeticCue constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnAbilityCosmeticCue Property Definitions **************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventBP_OnAbilityCosmeticCue_Parms, AbilityId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventBP_OnAbilityCosmeticCue_Parms, Target), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnAbilityCosmeticCue Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "BP_OnAbilityCosmeticCue", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonCombatComponent_eventBP_OnAbilityCosmeticCue_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonCombatComponent_eventBP_OnAbilityCosmeticCue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_BP_OnAbilityCosmeticCue(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFDigimonCombatComponent Function BP_OnAbilityCosmeticCue ****************

// ********** Begin Class UDMFDigimonCombatComponent Function BP_OnDefeatedCosmetics ***************
struct DMFDigimonCombatComponent_eventBP_OnDefeatedCosmetics_Parms
{
	ADMFDigimonCharacter* Killer;
};
static FName NAME_UDMFDigimonCombatComponent_BP_OnDefeatedCosmetics = FName(TEXT("BP_OnDefeatedCosmetics"));
void UDMFDigimonCombatComponent::BP_OnDefeatedCosmetics(ADMFDigimonCharacter* Killer)
{
	DMFDigimonCombatComponent_eventBP_OnDefeatedCosmetics_Parms Parms;
	Parms.Killer=Killer;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonCombatComponent_BP_OnDefeatedCosmetics);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_BP_OnDefeatedCosmetics_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Presentation" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnDefeatedCosmetics constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Killer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnDefeatedCosmetics constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnDefeatedCosmetics Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Killer = { "Killer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventBP_OnDefeatedCosmetics_Parms, Killer), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Killer,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnDefeatedCosmetics Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "BP_OnDefeatedCosmetics", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonCombatComponent_eventBP_OnDefeatedCosmetics_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonCombatComponent_eventBP_OnDefeatedCosmetics_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_BP_OnDefeatedCosmetics(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFDigimonCombatComponent Function BP_OnDefeatedCosmetics *****************

// ********** Begin Class UDMFDigimonCombatComponent Function BP_OnVictoryCosmetics ****************
struct DMFDigimonCombatComponent_eventBP_OnVictoryCosmetics_Parms
{
	ADMFDigimonCharacter* DefeatedDigimon;
};
static FName NAME_UDMFDigimonCombatComponent_BP_OnVictoryCosmetics = FName(TEXT("BP_OnVictoryCosmetics"));
void UDMFDigimonCombatComponent::BP_OnVictoryCosmetics(ADMFDigimonCharacter* DefeatedDigimon)
{
	DMFDigimonCombatComponent_eventBP_OnVictoryCosmetics_Parms Parms;
	Parms.DefeatedDigimon=DefeatedDigimon;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonCombatComponent_BP_OnVictoryCosmetics);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_BP_OnVictoryCosmetics_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Presentation" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVictoryCosmetics constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefeatedDigimon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnVictoryCosmetics constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnVictoryCosmetics Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DefeatedDigimon = { "DefeatedDigimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventBP_OnVictoryCosmetics_Parms, DefeatedDigimon), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefeatedDigimon,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnVictoryCosmetics Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "BP_OnVictoryCosmetics", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonCombatComponent_eventBP_OnVictoryCosmetics_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonCombatComponent_eventBP_OnVictoryCosmetics_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_BP_OnVictoryCosmetics(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFDigimonCombatComponent Function BP_OnVictoryCosmetics ******************

// ********** Begin Class UDMFDigimonCombatComponent Function CanAttackTarget **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_CanAttackTarget_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventCanAttackTarget_Parms
	{
		const ADMFDigimonCharacter* Candidate;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Candidate_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanAttackTarget constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Candidate;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventCanAttackTarget_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanAttackTarget constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanAttackTarget Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Candidate = { "Candidate", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventCanAttackTarget_Parms, Candidate), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Candidate_MetaData), NewProp_Candidate_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventCanAttackTarget_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Candidate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CanAttackTarget Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "CanAttackTarget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventCanAttackTarget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventCanAttackTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_CanAttackTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execCanAttackTarget)
{
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_Candidate);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanAttackTarget(Z_Param_Candidate);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function CanAttackTarget ************************

// ********** Begin Class UDMFDigimonCombatComponent Function ConfigureAutomation ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_ConfigureAutomation_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventConfigureAutomation_Parms
	{
		bool bInAutoBattleEnabled;
		float InAggroRange;
		float InLeashRange;
		AActor* InFollowAnchor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConfigureAutomation constinit property declarations *******************
	static void NewProp_bInAutoBattleEnabled_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventConfigureAutomation_Parms*)Obj)->bInAutoBattleEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInAutoBattleEnabled;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InAggroRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InLeashRange;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InFollowAnchor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConfigureAutomation constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConfigureAutomation Property Definitions ******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInAutoBattleEnabled = { "bInAutoBattleEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventConfigureAutomation_Parms), &UHT_STATICS::NewProp_bInAutoBattleEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InAggroRange = { "InAggroRange", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventConfigureAutomation_Parms, InAggroRange), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InLeashRange = { "InLeashRange", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventConfigureAutomation_Parms, InLeashRange), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InFollowAnchor = { "InFollowAnchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventConfigureAutomation_Parms, InFollowAnchor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInAutoBattleEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InAggroRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InLeashRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InFollowAnchor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ConfigureAutomation Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "ConfigureAutomation", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventConfigureAutomation_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventConfigureAutomation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_ConfigureAutomation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execConfigureAutomation)
{
	P_GET_UBOOL(Z_Param_bInAutoBattleEnabled);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InAggroRange);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InLeashRange);
	P_GET_OBJECT(AActor,Z_Param_InFollowAnchor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConfigureAutomation(Z_Param_bInAutoBattleEnabled,Z_Param_InAggroRange,Z_Param_InLeashRange,Z_Param_InFollowAnchor);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function ConfigureAutomation ********************

// ********** Begin Class UDMFDigimonCombatComponent Function ConfigureDamageTuning ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_ConfigureDamageTuning_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventConfigureDamageTuning_Parms
	{
		float InOutgoingDamageMultiplier;
		float InIncomingDamageMultiplier;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Balance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Role-level balance tuning. Server-only and intentionally separate from persistent species stats. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Role-level balance tuning. Server-only and intentionally separate from persistent species stats." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ConfigureDamageTuning constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InOutgoingDamageMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InIncomingDamageMultiplier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConfigureDamageTuning constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConfigureDamageTuning Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InOutgoingDamageMultiplier = { "InOutgoingDamageMultiplier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventConfigureDamageTuning_Parms, InOutgoingDamageMultiplier), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InIncomingDamageMultiplier = { "InIncomingDamageMultiplier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventConfigureDamageTuning_Parms, InIncomingDamageMultiplier), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InOutgoingDamageMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InIncomingDamageMultiplier,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ConfigureDamageTuning Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "ConfigureDamageTuning", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventConfigureDamageTuning_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventConfigureDamageTuning_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_ConfigureDamageTuning(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execConfigureDamageTuning)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InOutgoingDamageMultiplier);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InIncomingDamageMultiplier);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConfigureDamageTuning(Z_Param_InOutgoingDamageMultiplier,Z_Param_InIncomingDamageMultiplier);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function ConfigureDamageTuning ******************

// ********** Begin Class UDMFDigimonCombatComponent Function ConfigureRetaliation *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_ConfigureRetaliation_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventConfigureRetaliation_Parms
	{
		bool bInRetaliateWhenAttacked;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Reactive" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Enables server-authoritative reactive combat independently from proactive auto battle.\n     * When enabled, this Digimon will defend itself against a valid hostile attacker without\n     * scanning for or initiating combat against nearby targets.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables server-authoritative reactive combat independently from proactive auto battle.\nWhen enabled, this Digimon will defend itself against a valid hostile attacker without\nscanning for or initiating combat against nearby targets." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ConfigureRetaliation constinit property declarations ******************
	static void NewProp_bInRetaliateWhenAttacked_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventConfigureRetaliation_Parms*)Obj)->bInRetaliateWhenAttacked = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInRetaliateWhenAttacked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConfigureRetaliation constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConfigureRetaliation Property Definitions *****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInRetaliateWhenAttacked = { "bInRetaliateWhenAttacked", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventConfigureRetaliation_Parms), &UHT_STATICS::NewProp_bInRetaliateWhenAttacked_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInRetaliateWhenAttacked,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ConfigureRetaliation Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "ConfigureRetaliation", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventConfigureRetaliation_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventConfigureRetaliation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_ConfigureRetaliation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execConfigureRetaliation)
{
	P_GET_UBOOL(Z_Param_bInRetaliateWhenAttacked);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConfigureRetaliation(Z_Param_bInRetaliateWhenAttacked);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function ConfigureRetaliation *******************

// ********** Begin Class UDMFDigimonCombatComponent Function GetCombatState ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCombatState_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventGetCombatState_Parms
	{
		EDMFCombatState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCombatState constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCombatState constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCombatState Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventGetCombatState_Parms, ReturnValue), Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState, METADATA_PARAMS(0, nullptr) }; // f39157b31587da9510a9e9d2d63daa8f797fe530
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCombatState Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "GetCombatState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventGetCombatState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventGetCombatState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCombatState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execGetCombatState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDMFCombatState*)Z_Param__Result=P_THIS->GetCombatState();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function GetCombatState *************************

// ********** Begin Class UDMFDigimonCombatComponent Function GetCurrentHP *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCurrentHP_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventGetCurrentHP_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentHP constinit property declarations **************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentHP constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentHP Property Definitions *************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventGetCurrentHP_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentHP Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "GetCurrentHP", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventGetCurrentHP_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventGetCurrentHP_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCurrentHP(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execGetCurrentHP)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetCurrentHP();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function GetCurrentHP ***************************

// ********** Begin Class UDMFDigimonCombatComponent Function GetCurrentSP *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCurrentSP_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventGetCurrentSP_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentSP constinit property declarations **************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentSP constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentSP Property Definitions *************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventGetCurrentSP_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentSP Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "GetCurrentSP", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventGetCurrentSP_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventGetCurrentSP_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCurrentSP(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execGetCurrentSP)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetCurrentSP();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function GetCurrentSP ***************************

// ********** Begin Class UDMFDigimonCombatComponent Function GetCurrentTarget *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCurrentTarget_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventGetCurrentTarget_Parms
	{
		ADMFDigimonCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentTarget constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentTarget constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentTarget Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventGetCurrentTarget_Parms, ReturnValue), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentTarget Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "GetCurrentTarget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventGetCurrentTarget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventGetCurrentTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCurrentTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execGetCurrentTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFDigimonCharacter**)Z_Param__Result=P_THIS->GetCurrentTarget();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function GetCurrentTarget ***********************

// ********** Begin Class UDMFDigimonCombatComponent Function GetIncomingDamageMultiplier **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_GetIncomingDamageMultiplier_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventGetIncomingDamageMultiplier_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Balance" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetIncomingDamageMultiplier constinit property declarations ***********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetIncomingDamageMultiplier constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetIncomingDamageMultiplier Property Definitions **********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventGetIncomingDamageMultiplier_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetIncomingDamageMultiplier Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "GetIncomingDamageMultiplier", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventGetIncomingDamageMultiplier_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventGetIncomingDamageMultiplier_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_GetIncomingDamageMultiplier(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execGetIncomingDamageMultiplier)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetIncomingDamageMultiplier();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function GetIncomingDamageMultiplier ************

// ********** Begin Class UDMFDigimonCombatComponent Function GetOutgoingDamageMultiplier **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_GetOutgoingDamageMultiplier_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventGetOutgoingDamageMultiplier_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Balance" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetOutgoingDamageMultiplier constinit property declarations ***********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOutgoingDamageMultiplier constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOutgoingDamageMultiplier Property Definitions **********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventGetOutgoingDamageMultiplier_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetOutgoingDamageMultiplier Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "GetOutgoingDamageMultiplier", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventGetOutgoingDamageMultiplier_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventGetOutgoingDamageMultiplier_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_GetOutgoingDamageMultiplier(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execGetOutgoingDamageMultiplier)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetOutgoingDamageMultiplier();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function GetOutgoingDamageMultiplier ************

// ********** Begin Class UDMFDigimonCombatComponent Function GetRemainingCooldown *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_GetRemainingCooldown_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventGetRemainingCooldown_Parms
	{
		FName AbilityId;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetRemainingCooldown constinit property declarations ******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetRemainingCooldown constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetRemainingCooldown Property Definitions *****************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventGetRemainingCooldown_Parms, AbilityId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventGetRemainingCooldown_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetRemainingCooldown Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "GetRemainingCooldown", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventGetRemainingCooldown_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventGetRemainingCooldown_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_GetRemainingCooldown(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execGetRemainingCooldown)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_AbilityId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetRemainingCooldown(Z_Param_AbilityId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function GetRemainingCooldown *******************

// ********** Begin Class UDMFDigimonCombatComponent Function InitializeRuntimeVitals **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_InitializeRuntimeVitals_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventInitializeRuntimeVitals_Parms
	{
		int32 InCurrentHP;
		int32 InCurrentSP;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeRuntimeVitals constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InCurrentHP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InCurrentSP;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeRuntimeVitals constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeRuntimeVitals Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_InCurrentHP = { "InCurrentHP", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventInitializeRuntimeVitals_Parms, InCurrentHP), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_InCurrentSP = { "InCurrentSP", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventInitializeRuntimeVitals_Parms, InCurrentSP), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InCurrentHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InCurrentSP,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeRuntimeVitals Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "InitializeRuntimeVitals", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventInitializeRuntimeVitals_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventInitializeRuntimeVitals_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_InitializeRuntimeVitals(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execInitializeRuntimeVitals)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InCurrentHP);
	P_GET_PROPERTY(FIntProperty,Z_Param_InCurrentSP);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeRuntimeVitals(Z_Param_InCurrentHP,Z_Param_InCurrentSP);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function InitializeRuntimeVitals ****************

// ********** Begin Class UDMFDigimonCombatComponent Function IsAutoBattleEnabled ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_IsAutoBattleEnabled_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventIsAutoBattleEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsAutoBattleEnabled constinit property declarations *******************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventIsAutoBattleEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsAutoBattleEnabled constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsAutoBattleEnabled Property Definitions ******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventIsAutoBattleEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsAutoBattleEnabled Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "IsAutoBattleEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventIsAutoBattleEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventIsAutoBattleEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_IsAutoBattleEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execIsAutoBattleEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsAutoBattleEnabled();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function IsAutoBattleEnabled ********************

// ********** Begin Class UDMFDigimonCombatComponent Function IsDefeated ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_IsDefeated_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventIsDefeated_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDefeated constinit property declarations ****************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventIsDefeated_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDefeated constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDefeated Property Definitions ***************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventIsDefeated_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsDefeated Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "IsDefeated", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventIsDefeated_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventIsDefeated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_IsDefeated(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execIsDefeated)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDefeated();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function IsDefeated *****************************

// ********** Begin Class UDMFDigimonCombatComponent Function IsRetaliating ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_IsRetaliating_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventIsRetaliating_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Reactive" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsRetaliating constinit property declarations *************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventIsRetaliating_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsRetaliating constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsRetaliating Property Definitions ************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventIsRetaliating_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsRetaliating Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "IsRetaliating", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventIsRetaliating_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventIsRetaliating_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_IsRetaliating(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execIsRetaliating)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsRetaliating();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function IsRetaliating **************************

// ********** Begin Class UDMFDigimonCombatComponent Function IsRetaliationEnabled *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_IsRetaliationEnabled_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventIsRetaliationEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Reactive" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsRetaliationEnabled constinit property declarations ******************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventIsRetaliationEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsRetaliationEnabled constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsRetaliationEnabled Property Definitions *****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventIsRetaliationEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsRetaliationEnabled Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "IsRetaliationEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventIsRetaliationEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventIsRetaliationEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_IsRetaliationEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execIsRetaliationEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsRetaliationEnabled();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function IsRetaliationEnabled *******************

// ********** Begin Class UDMFDigimonCombatComponent Function MulticastDefeatedCue *****************
struct DMFDigimonCombatComponent_eventMulticastDefeatedCue_Parms
{
	ADMFDigimonCharacter* Killer;
};
static FName NAME_UDMFDigimonCombatComponent_MulticastDefeatedCue = FName(TEXT("MulticastDefeatedCue"));
void UDMFDigimonCombatComponent::MulticastDefeatedCue(ADMFDigimonCharacter* Killer)
{
	DMFDigimonCombatComponent_eventMulticastDefeatedCue_Parms Parms;
	Parms.Killer=Killer;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonCombatComponent_MulticastDefeatedCue);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastDefeatedCue_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MulticastDefeatedCue constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Killer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MulticastDefeatedCue constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MulticastDefeatedCue Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Killer = { "Killer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventMulticastDefeatedCue_Parms, Killer), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Killer,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MulticastDefeatedCue Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "MulticastDefeatedCue", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonCombatComponent_eventMulticastDefeatedCue_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00044CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonCombatComponent_eventMulticastDefeatedCue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastDefeatedCue(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execMulticastDefeatedCue)
{
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_Killer);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MulticastDefeatedCue_Implementation(Z_Param_Killer);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function MulticastDefeatedCue *******************

// ********** Begin Class UDMFDigimonCombatComponent Function MulticastPlayAbilityCue **************
struct DMFDigimonCombatComponent_eventMulticastPlayAbilityCue_Parms
{
	FName AbilityId;
	ADMFDigimonCharacter* Target;
};
static FName NAME_UDMFDigimonCombatComponent_MulticastPlayAbilityCue = FName(TEXT("MulticastPlayAbilityCue"));
void UDMFDigimonCombatComponent::MulticastPlayAbilityCue(FName AbilityId, ADMFDigimonCharacter* Target)
{
	DMFDigimonCombatComponent_eventMulticastPlayAbilityCue_Parms Parms;
	Parms.AbilityId=AbilityId;
	Parms.Target=Target;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonCombatComponent_MulticastPlayAbilityCue);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastPlayAbilityCue_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MulticastPlayAbilityCue constinit property declarations ***************
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MulticastPlayAbilityCue constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MulticastPlayAbilityCue Property Definitions **************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventMulticastPlayAbilityCue_Parms, AbilityId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventMulticastPlayAbilityCue_Parms, Target), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MulticastPlayAbilityCue Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "MulticastPlayAbilityCue", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonCombatComponent_eventMulticastPlayAbilityCue_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00044C41, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonCombatComponent_eventMulticastPlayAbilityCue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastPlayAbilityCue(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execMulticastPlayAbilityCue)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_AbilityId);
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MulticastPlayAbilityCue_Implementation(Z_Param_AbilityId,Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function MulticastPlayAbilityCue ****************

// ********** Begin Class UDMFDigimonCombatComponent Function MulticastPlayProjectileImpactCue *****
struct DMFDigimonCombatComponent_eventMulticastPlayProjectileImpactCue_Parms
{
	FName AbilityId;
	FVector_NetQuantize ImpactLocation;
};
static FName NAME_UDMFDigimonCombatComponent_MulticastPlayProjectileImpactCue = FName(TEXT("MulticastPlayProjectileImpactCue"));
void UDMFDigimonCombatComponent::MulticastPlayProjectileImpactCue(FName AbilityId, FVector_NetQuantize ImpactLocation)
{
	DMFDigimonCombatComponent_eventMulticastPlayProjectileImpactCue_Parms Parms;
	Parms.AbilityId=AbilityId;
	Parms.ImpactLocation=ImpactLocation;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonCombatComponent_MulticastPlayProjectileImpactCue);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastPlayProjectileImpactCue_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Transient projectile impact presentation. Gameplay damage has already been accepted by authority before this cue. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Transient projectile impact presentation. Gameplay damage has already been accepted by authority before this cue." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function MulticastPlayProjectileImpactCue constinit property declarations ******
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImpactLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MulticastPlayProjectileImpactCue constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MulticastPlayProjectileImpactCue Property Definitions *****************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventMulticastPlayProjectileImpactCue_Parms, AbilityId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ImpactLocation = { "ImpactLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventMulticastPlayProjectileImpactCue_Parms, ImpactLocation), Z_Construct_UScriptStruct_FVector_NetQuantize, METADATA_PARAMS(0, nullptr) }; // 360b775a5cdccbf04648aaedc65b3c6a0a2c5ffc
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ImpactLocation,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MulticastPlayProjectileImpactCue Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "MulticastPlayProjectileImpactCue", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonCombatComponent_eventMulticastPlayProjectileImpactCue_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00044C41, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonCombatComponent_eventMulticastPlayProjectileImpactCue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastPlayProjectileImpactCue(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execMulticastPlayProjectileImpactCue)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_AbilityId);
	P_GET_STRUCT(FVector_NetQuantize,Z_Param_ImpactLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MulticastPlayProjectileImpactCue_Implementation(Z_Param_AbilityId,Z_Param_ImpactLocation);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function MulticastPlayProjectileImpactCue *******

// ********** Begin Class UDMFDigimonCombatComponent Function MulticastVictoryCue ******************
struct DMFDigimonCombatComponent_eventMulticastVictoryCue_Parms
{
	ADMFDigimonCharacter* DefeatedDigimon;
};
static FName NAME_UDMFDigimonCombatComponent_MulticastVictoryCue = FName(TEXT("MulticastVictoryCue"));
void UDMFDigimonCombatComponent::MulticastVictoryCue(ADMFDigimonCharacter* DefeatedDigimon)
{
	DMFDigimonCombatComponent_eventMulticastVictoryCue_Parms Parms;
	Parms.DefeatedDigimon=DefeatedDigimon;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonCombatComponent_MulticastVictoryCue);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastVictoryCue_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MulticastVictoryCue constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefeatedDigimon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MulticastVictoryCue constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MulticastVictoryCue Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DefeatedDigimon = { "DefeatedDigimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventMulticastVictoryCue_Parms, DefeatedDigimon), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefeatedDigimon,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MulticastVictoryCue Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "MulticastVictoryCue", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonCombatComponent_eventMulticastVictoryCue_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00044C41, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonCombatComponent_eventMulticastVictoryCue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastVictoryCue(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execMulticastVictoryCue)
{
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_DefeatedDigimon);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MulticastVictoryCue_Implementation(Z_Param_DefeatedDigimon);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function MulticastVictoryCue ********************

// ********** Begin Class UDMFDigimonCombatComponent Function NotifyAuthoritativeVictory ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_NotifyAuthoritativeVictory_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventNotifyAuthoritativeVictory_Parms
	{
		ADMFDigimonCharacter* DefeatedDigimon;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function NotifyAuthoritativeVictory constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefeatedDigimon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function NotifyAuthoritativeVictory constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function NotifyAuthoritativeVictory Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DefeatedDigimon = { "DefeatedDigimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventNotifyAuthoritativeVictory_Parms, DefeatedDigimon), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefeatedDigimon,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function NotifyAuthoritativeVictory Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "NotifyAuthoritativeVictory", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventNotifyAuthoritativeVictory_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventNotifyAuthoritativeVictory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_NotifyAuthoritativeVictory(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execNotifyAuthoritativeVictory)
{
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_DefeatedDigimon);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->NotifyAuthoritativeVictory(Z_Param_DefeatedDigimon);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function NotifyAuthoritativeVictory *************

// ********** Begin Class UDMFDigimonCombatComponent Function OnRep_CombatState ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_OnRep_CombatState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_CombatState constinit property declarations *********************
// ********** End Function OnRep_CombatState constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "OnRep_CombatState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_OnRep_CombatState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execOnRep_CombatState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CombatState();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function OnRep_CombatState **********************

// ********** Begin Class UDMFDigimonCombatComponent Function OnRep_CurrentTarget ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_OnRep_CurrentTarget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_CurrentTarget constinit property declarations *******************
// ********** End Function OnRep_CurrentTarget constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "OnRep_CurrentTarget", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_OnRep_CurrentTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execOnRep_CurrentTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentTarget();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function OnRep_CurrentTarget ********************

// ********** Begin Class UDMFDigimonCombatComponent Function OnRep_Vitals *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_OnRep_Vitals_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_Vitals constinit property declarations **************************
// ********** End Function OnRep_Vitals constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "OnRep_Vitals", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_OnRep_Vitals(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execOnRep_Vitals)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Vitals();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function OnRep_Vitals ***************************

// ********** Begin Class UDMFDigimonCombatComponent Function QueueOrExecuteAbilitySlot ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_QueueOrExecuteAbilitySlot_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventQueueOrExecuteAbilitySlot_Parms
	{
		int32 SlotIndex;
		ADMFDigimonCharacter* RequestedTarget;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Executes immediately when legal, otherwise chases and revalidates the queued command in range. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Executes immediately when legal, otherwise chases and revalidates the queued command in range." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function QueueOrExecuteAbilitySlot constinit property declarations *************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RequestedTarget;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventQueueOrExecuteAbilitySlot_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function QueueOrExecuteAbilitySlot constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function QueueOrExecuteAbilitySlot Property Definitions ************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventQueueOrExecuteAbilitySlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RequestedTarget = { "RequestedTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventQueueOrExecuteAbilitySlot_Parms, RequestedTarget), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventQueueOrExecuteAbilitySlot_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RequestedTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function QueueOrExecuteAbilitySlot Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "QueueOrExecuteAbilitySlot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventQueueOrExecuteAbilitySlot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventQueueOrExecuteAbilitySlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_QueueOrExecuteAbilitySlot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execQueueOrExecuteAbilitySlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_RequestedTarget);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->QueueOrExecuteAbilitySlot(Z_Param_SlotIndex,Z_Param_RequestedTarget);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function QueueOrExecuteAbilitySlot **************

// ********** Begin Class UDMFDigimonCombatComponent Function ResolveAbilityData *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_ResolveAbilityData_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventResolveAbilityData_Parms
	{
		FName AbilityId;
		UDMFDigimonAbilityData* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Abilities" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResolveAbilityData constinit property declarations ********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResolveAbilityData constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResolveAbilityData Property Definitions *******************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventResolveAbilityData_Parms, AbilityId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventResolveAbilityData_Parms, ReturnValue), Z_Construct_UClass_UDMFDigimonAbilityData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ResolveAbilityData Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "ResolveAbilityData", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventResolveAbilityData_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventResolveAbilityData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_ResolveAbilityData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execResolveAbilityData)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_AbilityId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDMFDigimonAbilityData**)Z_Param__Result=P_THIS->ResolveAbilityData(Z_Param_AbilityId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function ResolveAbilityData *********************

// ********** Begin Class UDMFDigimonCombatComponent Function RestoreVitals ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_RestoreVitals_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventRestoreVitals_Parms
	{
		bool bRestoreHP;
		bool bRestoreSP;
		bool bResetCombat;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Selective full restore used by healer actors. Restoring HP revives a defeated Digimon. */" },
#endif
		{ "CPP_Default_bResetCombat", "true" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Selective full restore used by healer actors. Restoring HP revives a defeated Digimon." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreVitals constinit property declarations *************************
	static void NewProp_bRestoreHP_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventRestoreVitals_Parms*)Obj)->bRestoreHP = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRestoreHP;
	static void NewProp_bRestoreSP_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventRestoreVitals_Parms*)Obj)->bRestoreSP = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRestoreSP;
	static void NewProp_bResetCombat_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventRestoreVitals_Parms*)Obj)->bResetCombat = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bResetCombat;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreVitals constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreVitals Property Definitions ************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRestoreHP = { "bRestoreHP", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventRestoreVitals_Parms), &UHT_STATICS::NewProp_bRestoreHP_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRestoreSP = { "bRestoreSP", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventRestoreVitals_Parms), &UHT_STATICS::NewProp_bRestoreSP_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bResetCombat = { "bResetCombat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventRestoreVitals_Parms), &UHT_STATICS::NewProp_bResetCombat_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRestoreHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRestoreSP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bResetCombat,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RestoreVitals Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "RestoreVitals", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventRestoreVitals_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventRestoreVitals_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_RestoreVitals(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execRestoreVitals)
{
	P_GET_UBOOL(Z_Param_bRestoreHP);
	P_GET_UBOOL(Z_Param_bRestoreSP);
	P_GET_UBOOL(Z_Param_bResetCombat);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RestoreVitals(Z_Param_bRestoreHP,Z_Param_bRestoreSP,Z_Param_bResetCombat);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function RestoreVitals **************************

// ********** Begin Class UDMFDigimonCombatComponent Function RestoreVitalsToMaximum ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_RestoreVitalsToMaximum_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreVitalsToMaximum constinit property declarations ****************
// ********** End Function RestoreVitalsToMaximum constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "RestoreVitalsToMaximum", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_RestoreVitalsToMaximum(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execRestoreVitalsToMaximum)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RestoreVitalsToMaximum();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function RestoreVitalsToMaximum *****************

// ********** Begin Class UDMFDigimonCombatComponent Function SetAuthoritativeTarget ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_SetAuthoritativeTarget_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventSetAuthoritativeTarget_Parms
	{
		ADMFDigimonCharacter* NewTarget;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAuthoritativeTarget constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAuthoritativeTarget constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAuthoritativeTarget Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NewTarget = { "NewTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventSetAuthoritativeTarget_Parms, NewTarget), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTarget,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetAuthoritativeTarget Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "SetAuthoritativeTarget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventSetAuthoritativeTarget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventSetAuthoritativeTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_SetAuthoritativeTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execSetAuthoritativeTarget)
{
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_NewTarget);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAuthoritativeTarget(Z_Param_NewTarget);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function SetAuthoritativeTarget *****************

// ********** Begin Class UDMFDigimonCombatComponent Function TryExecuteAbilityById ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_TryExecuteAbilityById_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventTryExecuteAbilityById_Parms
	{
		FName AbilityId;
		ADMFDigimonCharacter* RequestedTarget;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryExecuteAbilityById constinit property declarations *****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RequestedTarget;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventTryExecuteAbilityById_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryExecuteAbilityById constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryExecuteAbilityById Property Definitions ****************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventTryExecuteAbilityById_Parms, AbilityId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RequestedTarget = { "RequestedTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventTryExecuteAbilityById_Parms, RequestedTarget), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventTryExecuteAbilityById_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RequestedTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function TryExecuteAbilityById Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "TryExecuteAbilityById", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventTryExecuteAbilityById_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventTryExecuteAbilityById_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_TryExecuteAbilityById(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execTryExecuteAbilityById)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_AbilityId);
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_RequestedTarget);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->TryExecuteAbilityById(Z_Param_AbilityId,Z_Param_RequestedTarget);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function TryExecuteAbilityById ******************

// ********** Begin Class UDMFDigimonCombatComponent Function TryExecuteAbilitySlot ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonCombatComponent_TryExecuteAbilitySlot_Statics
struct UHT_STATICS
{
	struct DMFDigimonCombatComponent_eventTryExecuteAbilitySlot_Parms
	{
		int32 SlotIndex;
		ADMFDigimonCharacter* RequestedTarget;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryExecuteAbilitySlot constinit property declarations *****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RequestedTarget;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCombatComponent_eventTryExecuteAbilitySlot_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryExecuteAbilitySlot constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryExecuteAbilitySlot Property Definitions ****************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventTryExecuteAbilitySlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RequestedTarget = { "RequestedTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCombatComponent_eventTryExecuteAbilitySlot_Parms, RequestedTarget), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCombatComponent_eventTryExecuteAbilitySlot_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RequestedTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function TryExecuteAbilitySlot Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonCombatComponent, nullptr, "TryExecuteAbilitySlot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCombatComponent_eventTryExecuteAbilitySlot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCombatComponent_eventTryExecuteAbilitySlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonCombatComponent_TryExecuteAbilitySlot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonCombatComponent::execTryExecuteAbilitySlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_RequestedTarget);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->TryExecuteAbilitySlot(Z_Param_SlotIndex,Z_Param_RequestedTarget);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonCombatComponent Function TryExecuteAbilitySlot ******************

// ********** Begin Class UDMFDigimonCombatComponent ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFDigimonCombatComponent_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "DigimonMMO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Shared authoritative combat runtime for player partners, wild Digimon and NPC/ranked Digimon.\n * Clients request commands through an owning PlayerState component; all cost/range/cooldown/damage\n * validation happens here on the server.\n */" },
#endif
		{ "IncludePath", "Components/DMFDigimonCombatComponent.h" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shared authoritative combat runtime for player partners, wild Digimon and NPC/ranked Digimon.\nClients request commands through an owning PlayerState component; all cost/range/cooldown/damage\nvalidation happens here on the server." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVitalsChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTargetChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCombatStateChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDefeated_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAbilityExecuted_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHP_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSP_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatState_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTarget_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedCooldowns_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFDigimonCombatComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFDigimonCombatComponent constinit property declarations ***************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnVitalsChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTargetChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCombatStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDefeated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAbilityExecuted;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentHP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentSP;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CombatState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CombatState;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentTarget;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReplicatedCooldowns_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReplicatedCooldowns;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFDigimonCombatComponent constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyAuthoritativeDamage"), .Pointer = &UDMFDigimonCombatComponent::execApplyAuthoritativeDamage },
		{ .NameUTF8 = UTF8TEXT("CanAttackTarget"), .Pointer = &UDMFDigimonCombatComponent::execCanAttackTarget },
		{ .NameUTF8 = UTF8TEXT("ConfigureAutomation"), .Pointer = &UDMFDigimonCombatComponent::execConfigureAutomation },
		{ .NameUTF8 = UTF8TEXT("ConfigureDamageTuning"), .Pointer = &UDMFDigimonCombatComponent::execConfigureDamageTuning },
		{ .NameUTF8 = UTF8TEXT("ConfigureRetaliation"), .Pointer = &UDMFDigimonCombatComponent::execConfigureRetaliation },
		{ .NameUTF8 = UTF8TEXT("GetCombatState"), .Pointer = &UDMFDigimonCombatComponent::execGetCombatState },
		{ .NameUTF8 = UTF8TEXT("GetCurrentHP"), .Pointer = &UDMFDigimonCombatComponent::execGetCurrentHP },
		{ .NameUTF8 = UTF8TEXT("GetCurrentSP"), .Pointer = &UDMFDigimonCombatComponent::execGetCurrentSP },
		{ .NameUTF8 = UTF8TEXT("GetCurrentTarget"), .Pointer = &UDMFDigimonCombatComponent::execGetCurrentTarget },
		{ .NameUTF8 = UTF8TEXT("GetIncomingDamageMultiplier"), .Pointer = &UDMFDigimonCombatComponent::execGetIncomingDamageMultiplier },
		{ .NameUTF8 = UTF8TEXT("GetOutgoingDamageMultiplier"), .Pointer = &UDMFDigimonCombatComponent::execGetOutgoingDamageMultiplier },
		{ .NameUTF8 = UTF8TEXT("GetRemainingCooldown"), .Pointer = &UDMFDigimonCombatComponent::execGetRemainingCooldown },
		{ .NameUTF8 = UTF8TEXT("InitializeRuntimeVitals"), .Pointer = &UDMFDigimonCombatComponent::execInitializeRuntimeVitals },
		{ .NameUTF8 = UTF8TEXT("IsAutoBattleEnabled"), .Pointer = &UDMFDigimonCombatComponent::execIsAutoBattleEnabled },
		{ .NameUTF8 = UTF8TEXT("IsDefeated"), .Pointer = &UDMFDigimonCombatComponent::execIsDefeated },
		{ .NameUTF8 = UTF8TEXT("IsRetaliating"), .Pointer = &UDMFDigimonCombatComponent::execIsRetaliating },
		{ .NameUTF8 = UTF8TEXT("IsRetaliationEnabled"), .Pointer = &UDMFDigimonCombatComponent::execIsRetaliationEnabled },
		{ .NameUTF8 = UTF8TEXT("MulticastDefeatedCue"), .Pointer = &UDMFDigimonCombatComponent::execMulticastDefeatedCue },
		{ .NameUTF8 = UTF8TEXT("MulticastPlayAbilityCue"), .Pointer = &UDMFDigimonCombatComponent::execMulticastPlayAbilityCue },
		{ .NameUTF8 = UTF8TEXT("MulticastPlayProjectileImpactCue"), .Pointer = &UDMFDigimonCombatComponent::execMulticastPlayProjectileImpactCue },
		{ .NameUTF8 = UTF8TEXT("MulticastVictoryCue"), .Pointer = &UDMFDigimonCombatComponent::execMulticastVictoryCue },
		{ .NameUTF8 = UTF8TEXT("NotifyAuthoritativeVictory"), .Pointer = &UDMFDigimonCombatComponent::execNotifyAuthoritativeVictory },
		{ .NameUTF8 = UTF8TEXT("OnRep_CombatState"), .Pointer = &UDMFDigimonCombatComponent::execOnRep_CombatState },
		{ .NameUTF8 = UTF8TEXT("OnRep_CurrentTarget"), .Pointer = &UDMFDigimonCombatComponent::execOnRep_CurrentTarget },
		{ .NameUTF8 = UTF8TEXT("OnRep_Vitals"), .Pointer = &UDMFDigimonCombatComponent::execOnRep_Vitals },
		{ .NameUTF8 = UTF8TEXT("QueueOrExecuteAbilitySlot"), .Pointer = &UDMFDigimonCombatComponent::execQueueOrExecuteAbilitySlot },
		{ .NameUTF8 = UTF8TEXT("ResolveAbilityData"), .Pointer = &UDMFDigimonCombatComponent::execResolveAbilityData },
		{ .NameUTF8 = UTF8TEXT("RestoreVitals"), .Pointer = &UDMFDigimonCombatComponent::execRestoreVitals },
		{ .NameUTF8 = UTF8TEXT("RestoreVitalsToMaximum"), .Pointer = &UDMFDigimonCombatComponent::execRestoreVitalsToMaximum },
		{ .NameUTF8 = UTF8TEXT("SetAuthoritativeTarget"), .Pointer = &UDMFDigimonCombatComponent::execSetAuthoritativeTarget },
		{ .NameUTF8 = UTF8TEXT("TryExecuteAbilityById"), .Pointer = &UDMFDigimonCombatComponent::execTryExecuteAbilityById },
		{ .NameUTF8 = UTF8TEXT("TryExecuteAbilitySlot"), .Pointer = &UDMFDigimonCombatComponent::execTryExecuteAbilitySlot },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_ApplyAuthoritativeDamage, "ApplyAuthoritativeDamage" }, // afa8f5c02ac52a3c237b79b479ffd5db52e36d57
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_BP_OnAbilityCosmeticCue, "BP_OnAbilityCosmeticCue" }, // c1aaf605c07c3eafaf3c8d17cfe9f3d7275f5190
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_BP_OnDefeatedCosmetics, "BP_OnDefeatedCosmetics" }, // 5a4dd386466b695eb9bae9fc91202002a4d39685
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_BP_OnVictoryCosmetics, "BP_OnVictoryCosmetics" }, // 4164de6d6ce47a350e8ba5634810214ec0bed6d5
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_CanAttackTarget, "CanAttackTarget" }, // ec8c4fb4cb2d0121bf6fd5f5d448e109bc8452a9
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_ConfigureAutomation, "ConfigureAutomation" }, // 8b523ff0da1cceabf2e0038ebce3829278f0b715
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_ConfigureDamageTuning, "ConfigureDamageTuning" }, // fba829aa2d6a6715ae1d4028d8a702823098fba6
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_ConfigureRetaliation, "ConfigureRetaliation" }, // c05c2ec02cee66c3e73262c0dc87a825b6e3a0d3
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCombatState, "GetCombatState" }, // 9ead856ae7bec81a591300f052c6e491db8622b7
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCurrentHP, "GetCurrentHP" }, // 181bbe89dd63e7ff264791f0c36ca1a79b0b88c2
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCurrentSP, "GetCurrentSP" }, // 92349d46b009d84f750b0b46997eb954e3ccdf08
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_GetCurrentTarget, "GetCurrentTarget" }, // fa8695be403a2d705da12a4627471abc844eddf7
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_GetIncomingDamageMultiplier, "GetIncomingDamageMultiplier" }, // 6844336ebb3d04fa625be3fcf3bc21d69db933ac
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_GetOutgoingDamageMultiplier, "GetOutgoingDamageMultiplier" }, // b9284bd389d2af9045fbb7e6c88093f6a3a726d0
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_GetRemainingCooldown, "GetRemainingCooldown" }, // 291ddaefa9d54618649d25f1b312947401d2e2b9
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_InitializeRuntimeVitals, "InitializeRuntimeVitals" }, // 98ee9c65446b919fddf11e814e36ea78f480d548
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_IsAutoBattleEnabled, "IsAutoBattleEnabled" }, // 5d436875bc9d1738e1ecceda43fd2eae3fc20754
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_IsDefeated, "IsDefeated" }, // 334d981c28f7141751bc0b5c3608c19edff51da0
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_IsRetaliating, "IsRetaliating" }, // 48e9244c8b26fef2d4db98a8c661cb623bd82a96
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_IsRetaliationEnabled, "IsRetaliationEnabled" }, // b0b00a1382fdba32637b0bdac8735f26d2f3629e
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastDefeatedCue, "MulticastDefeatedCue" }, // 38aa6ae8c0b2bbfb8ce0a0ccbe5d589e45a3fa07
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastPlayAbilityCue, "MulticastPlayAbilityCue" }, // 31dff5f309c97de53d7d468ac81514d8c95b6205
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastPlayProjectileImpactCue, "MulticastPlayProjectileImpactCue" }, // cffc6a915184f68151e42235af7b10ecc6632377
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_MulticastVictoryCue, "MulticastVictoryCue" }, // 2666f5be7c4de65332a0ae8eb2d6a0d35f71bf58
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_NotifyAuthoritativeVictory, "NotifyAuthoritativeVictory" }, // 3f371bec592a342c0e4cae1ed64e6b7c61733601
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_OnRep_CombatState, "OnRep_CombatState" }, // 269737e2bc5f37e8dda31e32efff32194c6246d6
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_OnRep_CurrentTarget, "OnRep_CurrentTarget" }, // f78e02a9f82092e06c9088643713e9fcb80571a5
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_OnRep_Vitals, "OnRep_Vitals" }, // 52b689957dcf2feaac43d138e3d7b7157cdec8d4
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_QueueOrExecuteAbilitySlot, "QueueOrExecuteAbilitySlot" }, // aafec1bcd573c9cfb6d6b0a31b68d9f3b78a1e55
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_ResolveAbilityData, "ResolveAbilityData" }, // 4cd90dda9e6e2cb2e66df7babe5b7967a15dc1d6
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_RestoreVitals, "RestoreVitals" }, // 571e9c31e23fbaa16ea2a3f4a61df5925fc01e1c
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_RestoreVitalsToMaximum, "RestoreVitalsToMaximum" }, // 46bd194816e918eb39c8b941bd491d1a038c048a
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_SetAuthoritativeTarget, "SetAuthoritativeTarget" }, // f9e3624ab689270db79fb47087998d40c36ae608
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_TryExecuteAbilityById, "TryExecuteAbilityById" }, // 6ac6f60e64f4715ae5c568907c5bbfb1e6c82b24
		{ &Z_Construct_UFunction_UDMFDigimonCombatComponent_TryExecuteAbilitySlot, "TryExecuteAbilitySlot" }, // 249d84698e22a8406e185bf64db087cd1ef90d66
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFDigimonCombatComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFDigimonCombatComponent Property Definitions **************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVitalsChanged = { "OnVitalsChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, OnVitalsChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatVitalsChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVitalsChanged_MetaData), NewProp_OnVitalsChanged_MetaData) }; // a7d314a85fc1c0e6890896dcc21027fddaf98c36
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnTargetChanged = { "OnTargetChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, OnTargetChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatTargetChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTargetChanged_MetaData), NewProp_OnTargetChanged_MetaData) }; // cb1c5d047766e6fe4abd995818c907b11893f3ee
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnCombatStateChanged = { "OnCombatStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, OnCombatStateChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFCombatStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCombatStateChanged_MetaData), NewProp_OnCombatStateChanged_MetaData) }; // 5f42945dd404cf7b5887403710155b2fe6123c9a
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnDefeated = { "OnDefeated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, OnDefeated), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonDefeated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDefeated_MetaData), NewProp_OnDefeated_MetaData) }; // bd029a8962bc1d8d31be23a2828f9f3c64b38dc9
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnAbilityExecuted = { "OnAbilityExecuted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, OnAbilityExecuted), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFAbilityExecuted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAbilityExecuted_MetaData), NewProp_OnAbilityExecuted_MetaData) }; // be252b070101d623cb678f34d5862d0990030539
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CurrentHP = { "CurrentHP", "OnRep_Vitals", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, CurrentHP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHP_MetaData), NewProp_CurrentHP_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CurrentSP = { "CurrentSP", "OnRep_Vitals", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, CurrentSP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSP_MetaData), NewProp_CurrentSP_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CombatState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_CombatState = { "CombatState", "OnRep_CombatState", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, CombatState), Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatState_MetaData), NewProp_CombatState_MetaData) }; // f39157b31587da9510a9e9d2d63daa8f797fe530
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CurrentTarget = { "CurrentTarget", "OnRep_CurrentTarget", (EPropertyFlags)0x0144000100000020, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, CurrentTarget), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTarget_MetaData), NewProp_CurrentTarget_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReplicatedCooldowns_Inner = { "ReplicatedCooldowns", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFAbilityCooldownState, METADATA_PARAMS(0, nullptr) }; // 2d39d476e3f200b690e062988336f05167f5ae5b
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReplicatedCooldowns = { "ReplicatedCooldowns", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonCombatComponent, ReplicatedCooldowns), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedCooldowns_MetaData), NewProp_ReplicatedCooldowns_MetaData) }; // 2d39d476e3f200b690e062988336f05167f5ae5b
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnVitalsChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnTargetChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnCombatStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnDefeated,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnAbilityExecuted,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurrentHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurrentSP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurrentTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedCooldowns_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedCooldowns,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFDigimonCombatComponent Property Definitions ****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UActorComponent,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFDigimonCombatComponent,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UDMFDigimonCombatComponent_StaticRegisterNativesUDMFDigimonCombatComponent()
{
	UClass* Class = UDMFDigimonCombatComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFDigimonCombatComponent;
UClass* Z_Construct_UClass_UDMFDigimonCombatComponent(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFDigimonCombatComponent;
		if (!Z_Registration_Info_UClass_UDMFDigimonCombatComponent.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonCombatComponent"),
				Z_Registration_Info_UClass_UDMFDigimonCombatComponent.InnerSingleton,
				UDMFDigimonCombatComponent_StaticRegisterNativesUDMFDigimonCombatComponent,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UDMFDigimonCombatComponent.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFDigimonCombatComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFDigimonCombatComponent.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFDigimonCombatComponent.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UDMFDigimonCombatComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_CurrentHP(TEXT("CurrentHP"));
	static FName Name_CurrentSP(TEXT("CurrentSP"));
	static FName Name_CombatState(TEXT("CombatState"));
	static FName Name_CurrentTarget(TEXT("CurrentTarget"));
	static FName Name_ReplicatedCooldowns(TEXT("ReplicatedCooldowns"));
	const bool bIsValid = true
		&& Name_CurrentHP == ClassReps[(int32)ENetFields_Private::CurrentHP].Property->GetFName()
		&& Name_CurrentSP == ClassReps[(int32)ENetFields_Private::CurrentSP].Property->GetFName()
		&& Name_CombatState == ClassReps[(int32)ENetFields_Private::CombatState].Property->GetFName()
		&& Name_CurrentTarget == ClassReps[(int32)ENetFields_Private::CurrentTarget].Property->GetFName()
		&& Name_ReplicatedCooldowns == ClassReps[(int32)ENetFields_Private::ReplicatedCooldowns].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UDMFDigimonCombatComponent"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFDigimonCombatComponent);
UDMFDigimonCombatComponent::~UDMFDigimonCombatComponent() {}
// ********** End Class UDMFDigimonCombatComponent *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFDigimonCombatComponent, TEXT("UDMFDigimonCombatComponent"), &Z_Registration_Info_UClass_UDMFDigimonCombatComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFDigimonCombatComponent), 1098409119U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFDigimonCombatComponent_h__Script_DigimonMMOFramework_eb3ecd358b18bbaf2e490dbdd2999538c09f3c58{
	TEXT("/Script/DigimonMMOFramework"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
