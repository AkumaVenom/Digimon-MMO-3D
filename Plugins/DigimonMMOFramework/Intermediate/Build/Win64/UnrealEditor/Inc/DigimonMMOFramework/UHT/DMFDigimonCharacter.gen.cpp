// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFDigimonCharacter.h"
#include "DMFTypes.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDigimonCharacter() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_ACharacter(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonInstance(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonStats(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonCombatComponent(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerState(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ADMFDigimonCharacter Function ApplyDefeatedPresentation ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_ApplyDefeatedPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Applies the persistent defeated presentation used by both player partners and wild Digimon.\n     * The species Death Montage plays once and, by default, freezes near its final pose until the\n     * Digimon is revived or the actor is recalled/destroyed. Safe to call repeatedly.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Applies the persistent defeated presentation used by both player partners and wild Digimon.\nThe species Death Montage plays once and, by default, freezes near its final pose until the\nDigimon is revived or the actor is recalled/destroyed. Safe to call repeatedly." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyDefeatedPresentation constinit property declarations *************
// ********** End Function ApplyDefeatedPresentation constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "ApplyDefeatedPresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_ApplyDefeatedPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execApplyDefeatedPresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyDefeatedPresentation();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function ApplyDefeatedPresentation ********************

// ********** Begin Class ADMFDigimonCharacter Function BP_OnDefeatedPresentationCleared ***********
static FName NAME_ADMFDigimonCharacter_BP_OnDefeatedPresentationCleared = FName(TEXT("BP_OnDefeatedPresentationCleared"));
void ADMFDigimonCharacter::BP_OnDefeatedPresentationCleared()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFDigimonCharacter_BP_OnDefeatedPresentationCleared);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_BP_OnDefeatedPresentationCleared_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnDefeatedPresentationCleared constinit property declarations ******
// ********** End Function BP_OnDefeatedPresentationCleared constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "BP_OnDefeatedPresentationCleared", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_BP_OnDefeatedPresentationCleared(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFDigimonCharacter Function BP_OnDefeatedPresentationCleared *************

// ********** Begin Class ADMFDigimonCharacter Function BP_OnDefeatedPresentationStarted ***********
static FName NAME_ADMFDigimonCharacter_BP_OnDefeatedPresentationStarted = FName(TEXT("BP_OnDefeatedPresentationStarted"));
void ADMFDigimonCharacter::BP_OnDefeatedPresentationStarted()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFDigimonCharacter_BP_OnDefeatedPresentationStarted);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_BP_OnDefeatedPresentationStarted_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnDefeatedPresentationStarted constinit property declarations ******
// ********** End Function BP_OnDefeatedPresentationStarted constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "BP_OnDefeatedPresentationStarted", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_BP_OnDefeatedPresentationStarted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFDigimonCharacter Function BP_OnDefeatedPresentationStarted *************

// ********** Begin Class ADMFDigimonCharacter Function BP_OnDigimonStateReady *********************
static FName NAME_ADMFDigimonCharacter_BP_OnDigimonStateReady = FName(TEXT("BP_OnDigimonStateReady"));
void ADMFDigimonCharacter::BP_OnDigimonStateReady()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFDigimonCharacter_BP_OnDigimonStateReady);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_BP_OnDigimonStateReady_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Digimon" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnDigimonStateReady constinit property declarations ****************
// ********** End Function BP_OnDigimonStateReady constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "BP_OnDigimonStateReady", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_BP_OnDigimonStateReady(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFDigimonCharacter Function BP_OnDigimonStateReady ***********************

// ********** Begin Class ADMFDigimonCharacter Function ClearDefeatedPresentation ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_ClearDefeatedPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Clears the persistent defeated presentation after an authoritative revive/reset. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clears the persistent defeated presentation after an authoritative revive/reset." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ClearDefeatedPresentation constinit property declarations *************
// ********** End Function ClearDefeatedPresentation constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "ClearDefeatedPresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_ClearDefeatedPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execClearDefeatedPresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearDefeatedPresentation();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function ClearDefeatedPresentation ********************

// ********** Begin Class ADMFDigimonCharacter Function ConfigureCombatAutomation ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_ConfigureCombatAutomation_Statics
struct UHT_STATICS
{
	struct DMFDigimonCharacter_eventConfigureCombatAutomation_Parms
	{
		bool bEnableAutoBattle;
		float AggroRange;
		float LeashRange;
		AActor* FollowAnchor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConfigureCombatAutomation constinit property declarations *************
	static void NewProp_bEnableAutoBattle_SetBit(void* Obj)
	{
		((DMFDigimonCharacter_eventConfigureCombatAutomation_Parms*)Obj)->bEnableAutoBattle = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableAutoBattle;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AggroRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LeashRange;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowAnchor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConfigureCombatAutomation constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConfigureCombatAutomation Property Definitions ************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableAutoBattle = { "bEnableAutoBattle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCharacter_eventConfigureCombatAutomation_Parms), &UHT_STATICS::NewProp_bEnableAutoBattle_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AggroRange = { "AggroRange", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventConfigureCombatAutomation_Parms, AggroRange), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LeashRange = { "LeashRange", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventConfigureCombatAutomation_Parms, LeashRange), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FollowAnchor = { "FollowAnchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventConfigureCombatAutomation_Parms, FollowAnchor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableAutoBattle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AggroRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LeashRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FollowAnchor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ConfigureCombatAutomation Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "ConfigureCombatAutomation", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCharacter_eventConfigureCombatAutomation_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCharacter_eventConfigureCombatAutomation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_ConfigureCombatAutomation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execConfigureCombatAutomation)
{
	P_GET_UBOOL(Z_Param_bEnableAutoBattle);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AggroRange);
	P_GET_PROPERTY(FFloatProperty,Z_Param_LeashRange);
	P_GET_OBJECT(AActor,Z_Param_FollowAnchor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConfigureCombatAutomation(Z_Param_bEnableAutoBattle,Z_Param_AggroRange,Z_Param_LeashRange,Z_Param_FollowAnchor);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function ConfigureCombatAutomation ********************

// ********** Begin Class ADMFDigimonCharacter Function GetCombatFacingTarget **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_GetCombatFacingTarget_Statics
struct UHT_STATICS
{
	struct DMFDigimonCharacter_eventGetCombatFacingTarget_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Facing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCombatFacingTarget constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCombatFacingTarget constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCombatFacingTarget Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventGetCombatFacingTarget_Parms, ReturnValue), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCombatFacingTarget Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "GetCombatFacingTarget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCharacter_eventGetCombatFacingTarget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCharacter_eventGetCombatFacingTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_GetCombatFacingTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execGetCombatFacingTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetCombatFacingTarget();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function GetCombatFacingTarget ************************

// ********** Begin Class ADMFDigimonCharacter Function InitializeFromInstance *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_InitializeFromInstance_Statics
struct UHT_STATICS
{
	struct DMFDigimonCharacter_eventInitializeFromInstance_Parms
	{
		FDMFDigimonInstance Instance;
		ADMFPlayerState* InOwningPlayerState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Digimon" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeFromInstance constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Instance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InOwningPlayerState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeFromInstance constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeFromInstance Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Instance = { "Instance", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventInitializeFromInstance_Parms, Instance), Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instance_MetaData), NewProp_Instance_MetaData) }; // e6e75c2fbf4c76aeacffc5124dd1e08c71077ffa
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InOwningPlayerState = { "InOwningPlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventInitializeFromInstance_Parms, InOwningPlayerState), Z_Construct_UClass_ADMFPlayerState, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Instance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InOwningPlayerState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeFromInstance Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "InitializeFromInstance", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCharacter_eventInitializeFromInstance_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCharacter_eventInitializeFromInstance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_InitializeFromInstance(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execInitializeFromInstance)
{
	P_GET_STRUCT_REF(FDMFDigimonInstance,Z_Param_Out_Instance);
	P_GET_OBJECT(ADMFPlayerState,Z_Param_InOwningPlayerState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeFromInstance(Z_Param_Out_Instance,Z_Param_InOwningPlayerState);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function InitializeFromInstance ***********************

// ********** Begin Class ADMFDigimonCharacter Function IsDefeatedPresentationActive ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_IsDefeatedPresentationActive_Statics
struct UHT_STATICS
{
	struct DMFDigimonCharacter_eventIsDefeatedPresentationActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDefeatedPresentationActive constinit property declarations **********
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCharacter_eventIsDefeatedPresentationActive_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDefeatedPresentationActive constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDefeatedPresentationActive Property Definitions *********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCharacter_eventIsDefeatedPresentationActive_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsDefeatedPresentationActive Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "IsDefeatedPresentationActive", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCharacter_eventIsDefeatedPresentationActive_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCharacter_eventIsDefeatedPresentationActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_IsDefeatedPresentationActive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execIsDefeatedPresentationActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDefeatedPresentationActive();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function IsDefeatedPresentationActive *****************

// ********** Begin Class ADMFDigimonCharacter Function IsFacingActor ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_IsFacingActor_Statics
struct UHT_STATICS
{
	struct DMFDigimonCharacter_eventIsFacingActor_Parms
	{
		AActor* TargetActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Facing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True when this Digimon is within AttackFacingToleranceDegrees of the supplied actor on yaw. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True when this Digimon is within AttackFacingToleranceDegrees of the supplied actor on yaw." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsFacingActor constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonCharacter_eventIsFacingActor_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsFacingActor constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsFacingActor Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventIsFacingActor_Parms, TargetActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonCharacter_eventIsFacingActor_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsFacingActor Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "IsFacingActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCharacter_eventIsFacingActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCharacter_eventIsFacingActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_IsFacingActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execIsFacingActor)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsFacingActor(Z_Param_TargetActor);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function IsFacingActor ********************************

// ********** Begin Class ADMFDigimonCharacter Function OnRep_DigimonState *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_OnRep_DigimonState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_DigimonState constinit property declarations ********************
// ********** End Function OnRep_DigimonState constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "OnRep_DigimonState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_OnRep_DigimonState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execOnRep_DigimonState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_DigimonState();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function OnRep_DigimonState ***************************

// ********** Begin Class ADMFDigimonCharacter Function RefreshFrameworkCustomDepth ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_RefreshFrameworkCustomDepth_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Rendering|Cel Shading" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Reasserts the framework cel-shading contract on every mesh component owned by this Digimon.\n     * Render CustomDepth Pass is always forced on for owned, wild, NPC and ranked Digimon actors.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reasserts the framework cel-shading contract on every mesh component owned by this Digimon.\nRender CustomDepth Pass is always forced on for owned, wild, NPC and ranked Digimon actors." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshFrameworkCustomDepth constinit property declarations ***********
// ********** End Function RefreshFrameworkCustomDepth constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "RefreshFrameworkCustomDepth", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_RefreshFrameworkCustomDepth(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execRefreshFrameworkCustomDepth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshFrameworkCustomDepth();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function RefreshFrameworkCustomDepth ******************

// ********** Begin Class ADMFDigimonCharacter Function ResolveSpeciesData *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_ResolveSpeciesData_Statics
struct UHT_STATICS
{
	struct DMFDigimonCharacter_eventResolveSpeciesData_Parms
	{
		UDMFDigimonSpeciesData* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Digimon" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResolveSpeciesData constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResolveSpeciesData constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResolveSpeciesData Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventResolveSpeciesData_Parms, ReturnValue), Z_Construct_UClass_UDMFDigimonSpeciesData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ResolveSpeciesData Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "ResolveSpeciesData", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCharacter_eventResolveSpeciesData_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCharacter_eventResolveSpeciesData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_ResolveSpeciesData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execResolveSpeciesData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDMFDigimonSpeciesData**)Z_Param__Result=P_THIS->ResolveSpeciesData();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function ResolveSpeciesData ***************************

// ********** Begin Class ADMFDigimonCharacter Function SetCombatTeamId ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_SetCombatTeamId_Statics
struct UHT_STATICS
{
	struct DMFDigimonCharacter_eventSetCombatTeamId_Parms
	{
		FName NewTeamId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCombatTeamId constinit property declarations ***********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_NewTeamId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCombatTeamId constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCombatTeamId Property Definitions **********************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_NewTeamId = { "NewTeamId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventSetCombatTeamId_Parms, NewTeamId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTeamId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetCombatTeamId Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "SetCombatTeamId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCharacter_eventSetCombatTeamId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCharacter_eventSetCombatTeamId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_SetCombatTeamId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execSetCombatTeamId)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_NewTeamId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCombatTeamId(Z_Param_NewTeamId);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function SetCombatTeamId ******************************

// ********** Begin Class ADMFDigimonCharacter Function StartCombatFacingTarget ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_StartCombatFacingTarget_Statics
struct UHT_STATICS
{
	struct DMFDigimonCharacter_eventStartCombatFacingTarget_Parms
	{
		AActor* TargetActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Facing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Starts a bounded server-side turn-in-place loop toward a combat target. Actor rotation is carried\n     * to clients by normal Character replicated movement; no cosmetic rotation RPC or client authority is used.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Starts a bounded server-side turn-in-place loop toward a combat target. Actor rotation is carried\nto clients by normal Character replicated movement; no cosmetic rotation RPC or client authority is used." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StartCombatFacingTarget constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartCombatFacingTarget constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartCombatFacingTarget Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCharacter_eventStartCombatFacingTarget_Parms, TargetActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetActor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function StartCombatFacingTarget Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "StartCombatFacingTarget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCharacter_eventStartCombatFacingTarget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCharacter_eventStartCombatFacingTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_StartCombatFacingTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execStartCombatFacingTarget)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartCombatFacingTarget(Z_Param_TargetActor);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function StartCombatFacingTarget **********************

// ********** Begin Class ADMFDigimonCharacter Function StopCombatFacingTarget *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCharacter_StopCombatFacingTarget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Facing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stops combat-facing and restores the CharacterMovement rotation policy that was active beforehand. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stops combat-facing and restores the CharacterMovement rotation policy that was active beforehand." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StopCombatFacingTarget constinit property declarations ****************
// ********** End Function StopCombatFacingTarget constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter, nullptr, "StopCombatFacingTarget", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCharacter_StopCombatFacingTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCharacter::execStopCombatFacingTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopCombatFacingTarget();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCharacter Function StopCombatFacingTarget ***********************

// ********** Begin Class ADMFDigimonCharacter *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFDigimonCharacter_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Game/DMFDigimonCharacter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableCombatFacing_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Facing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master switch for automatic target-facing before/during attacks. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master switch for automatic target-facing before/during attacks." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireFacingBeforeAttack_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Facing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, an attack cannot begin until the server has turned within the configured yaw tolerance. */" },
#endif
		{ "EditCondition", "bEnableCombatFacing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, an attack cannot begin until the server has turned within the configured yaw tolerance." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatFacingTurnRateDegreesPerSecond_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Facing" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Yaw turn speed while aligning to the current combat target. */" },
#endif
		{ "EditCondition", "bEnableCombatFacing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Yaw turn speed while aligning to the current combat target." },
#endif
		{ "UIMax", "1440.0" },
		{ "UIMin", "90.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackFacingToleranceDegrees_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Facing" },
		{ "ClampMax", "90.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum yaw error accepted before an attack may start. */" },
#endif
		{ "EditCondition", "bEnableCombatFacing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum yaw error accepted before an attack may start." },
#endif
		{ "UIMax", "45.0" },
		{ "UIMin", "1.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatFacingUpdateInterval_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Facing" },
		{ "ClampMax", "0.10" },
		{ "ClampMin", "0.016" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server update interval used only while a Digimon is actively turning to attack. */" },
#endif
		{ "EditCondition", "bEnableCombatFacing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server update interval used only while a Digimon is actively turning to attack." },
#endif
		{ "UIMax", "0.10" },
		{ "UIMin", "0.016" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHoldDefeatedPoseUntilRevivedOrDismissed_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Legacy compatibility setting retained for existing Blueprints. Defeated-pose holding is now a\n     * framework invariant in v0.5.5+: a valid Death Montage is always locked before blend-out can\n     * return the mesh to locomotion.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy compatibility setting retained for existing Blueprints. Defeated-pose holding is now a\nframework invariant in v0.5.5+: a valid Death Montage is always locked before blend-out can\nreturn the mesh to locomotion." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefeatedPoseHoldNormalizedTime_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
		{ "ClampMax", "0.999" },
		{ "ClampMin", "0.50" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Failsafe normalized hold point used only if a Montage never reaches its normal blend-out callback\n     * (for example, an unusual looping Montage). Normal death Montages lock at blend-out start.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Failsafe normalized hold point used only if a Montage never reaches its normal blend-out callback\n(for example, an unusual looping Montage). Normal death Montages lock at blend-out start." },
#endif
		{ "UIMax", "0.999" },
		{ "UIMin", "0.50" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefeatedMontagePlayRate_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
		{ "ClampMin", "0.05" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Playback rate used for the species Death Montage. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Playback rate used for the species Death Montage." },
#endif
		{ "UIMin", "0.05" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableMovementWhenDefeated_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stops CharacterMovement while defeated. The previous movement mode is restored on revive. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stops CharacterMovement while defeated. The previous movement mode is restored on revive." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableCapsuleCollisionWhenDefeated_MetaData[] = {
		{ "Category", "Digimon MMO|Defeat Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Makes a defeated Digimon non-blocking while its body remains visible in the world. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Makes a defeated Digimon non-blocking while its body remains visible in the world." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonInstanceId_MetaData[] = {
		{ "Category", "Digimon" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesId_MetaData[] = {
		{ "Category", "Digimon" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedStats_MetaData[] = {
		{ "Category", "Digimon" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedAbilityIds_MetaData[] = {
		{ "Category", "Digimon|Abilities" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwningPlayerState_MetaData[] = {
		{ "Category", "Digimon" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatTeamId_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCombatTargetable_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomDepthStencilValue_MetaData[] = {
		{ "Category", "Digimon MMO|Rendering|Cel Shading" },
		{ "ClampMax", "255" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stencil value written by all Digimon mesh components while Custom Depth rendering is enabled. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stencil value written by all Digimon mesh components while Custom Depth rendering is enabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveDeathMontage_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFDigimonCharacter constinit property declarations *********************
	static void NewProp_bEnableCombatFacing_SetBit(void* Obj)
	{
		((ADMFDigimonCharacter*)Obj)->bEnableCombatFacing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableCombatFacing;
	static void NewProp_bRequireFacingBeforeAttack_SetBit(void* Obj)
	{
		((ADMFDigimonCharacter*)Obj)->bRequireFacingBeforeAttack = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireFacingBeforeAttack;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CombatFacingTurnRateDegreesPerSecond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackFacingToleranceDegrees;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CombatFacingUpdateInterval;
	static void NewProp_bHoldDefeatedPoseUntilRevivedOrDismissed_SetBit(void* Obj)
	{
		((ADMFDigimonCharacter*)Obj)->bHoldDefeatedPoseUntilRevivedOrDismissed = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHoldDefeatedPoseUntilRevivedOrDismissed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefeatedPoseHoldNormalizedTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefeatedMontagePlayRate;
	static void NewProp_bDisableMovementWhenDefeated_SetBit(void* Obj)
	{
		((ADMFDigimonCharacter*)Obj)->bDisableMovementWhenDefeated = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableMovementWhenDefeated;
	static void NewProp_bDisableCapsuleCollisionWhenDefeated_SetBit(void* Obj)
	{
		((ADMFDigimonCharacter*)Obj)->bDisableCapsuleCollisionWhenDefeated = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableCapsuleCollisionWhenDefeated;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CombatComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReplicatedStats;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReplicatedAbilityIds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReplicatedAbilityIds;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwningPlayerState;
	static const UECodeGen_Private::FNamePropertyParams NewProp_CombatTeamId;
	static void NewProp_bCombatTargetable_SetBit(void* Obj)
	{
		((ADMFDigimonCharacter*)Obj)->bCombatTargetable = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCombatTargetable;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CustomDepthStencilValue;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveDeathMontage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFDigimonCharacter constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyDefeatedPresentation"), .Pointer = &ADMFDigimonCharacter::execApplyDefeatedPresentation },
		{ .NameUTF8 = UTF8TEXT("ClearDefeatedPresentation"), .Pointer = &ADMFDigimonCharacter::execClearDefeatedPresentation },
		{ .NameUTF8 = UTF8TEXT("ConfigureCombatAutomation"), .Pointer = &ADMFDigimonCharacter::execConfigureCombatAutomation },
		{ .NameUTF8 = UTF8TEXT("GetCombatFacingTarget"), .Pointer = &ADMFDigimonCharacter::execGetCombatFacingTarget },
		{ .NameUTF8 = UTF8TEXT("InitializeFromInstance"), .Pointer = &ADMFDigimonCharacter::execInitializeFromInstance },
		{ .NameUTF8 = UTF8TEXT("IsDefeatedPresentationActive"), .Pointer = &ADMFDigimonCharacter::execIsDefeatedPresentationActive },
		{ .NameUTF8 = UTF8TEXT("IsFacingActor"), .Pointer = &ADMFDigimonCharacter::execIsFacingActor },
		{ .NameUTF8 = UTF8TEXT("OnRep_DigimonState"), .Pointer = &ADMFDigimonCharacter::execOnRep_DigimonState },
		{ .NameUTF8 = UTF8TEXT("RefreshFrameworkCustomDepth"), .Pointer = &ADMFDigimonCharacter::execRefreshFrameworkCustomDepth },
		{ .NameUTF8 = UTF8TEXT("ResolveSpeciesData"), .Pointer = &ADMFDigimonCharacter::execResolveSpeciesData },
		{ .NameUTF8 = UTF8TEXT("SetCombatTeamId"), .Pointer = &ADMFDigimonCharacter::execSetCombatTeamId },
		{ .NameUTF8 = UTF8TEXT("StartCombatFacingTarget"), .Pointer = &ADMFDigimonCharacter::execStartCombatFacingTarget },
		{ .NameUTF8 = UTF8TEXT("StopCombatFacingTarget"), .Pointer = &ADMFDigimonCharacter::execStopCombatFacingTarget },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_ApplyDefeatedPresentation, "ApplyDefeatedPresentation" }, // b8440df8e9c35910b0402dd86b71b625bccf2b38
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_BP_OnDefeatedPresentationCleared, "BP_OnDefeatedPresentationCleared" }, // 386e581d68819559cfb5da9571fd30a088bb9f5a
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_BP_OnDefeatedPresentationStarted, "BP_OnDefeatedPresentationStarted" }, // 1920048099d724fb97a8fc1f5970b5bb8500c921
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_BP_OnDigimonStateReady, "BP_OnDigimonStateReady" }, // 473067256b97b7e00f27fdb0a97ee167fd77f1a1
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_ClearDefeatedPresentation, "ClearDefeatedPresentation" }, // b14c38225239b24d0a997c135d0859f12f75d5e9
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_ConfigureCombatAutomation, "ConfigureCombatAutomation" }, // 9d9c31dff8b2ca3b69dfcb03e31bd8de62e3d82b
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_GetCombatFacingTarget, "GetCombatFacingTarget" }, // 88fac54dc3269cdadfd3e0457f15e26072aef18c
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_InitializeFromInstance, "InitializeFromInstance" }, // d6bf0c286abaa8606a53a25f90a383f35e2175eb
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_IsDefeatedPresentationActive, "IsDefeatedPresentationActive" }, // c6f3ef436154295f09326cdd11f522bb80a74f73
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_IsFacingActor, "IsFacingActor" }, // 7668a789a94fa255d97d4f46cba6c0236f4e2153
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_OnRep_DigimonState, "OnRep_DigimonState" }, // b2f4e8bee6dd0ce8231489f594fa247c332ff9e3
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_RefreshFrameworkCustomDepth, "RefreshFrameworkCustomDepth" }, // 4e9969585bc503169e729bae41f2908af14f30db
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_ResolveSpeciesData, "ResolveSpeciesData" }, // ef9c63bfa88bbcf754437dd5749581017e42c278
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_SetCombatTeamId, "SetCombatTeamId" }, // c8e085c086216ee6ee1e0581032ffa1db9f74954
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_StartCombatFacingTarget, "StartCombatFacingTarget" }, // d8a99159017f69288be5eca9b79ced6736418d2c
		{ &Z_Construct_UFunction_ADMFDigimonCharacter_StopCombatFacingTarget, "StopCombatFacingTarget" }, // a1c3a427c8c83f88323e1e0b937e165fadeee75d
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFDigimonCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFDigimonCharacter Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableCombatFacing = { "bEnableCombatFacing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonCharacter), &UHT_STATICS::NewProp_bEnableCombatFacing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableCombatFacing_MetaData), NewProp_bEnableCombatFacing_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequireFacingBeforeAttack = { "bRequireFacingBeforeAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonCharacter), &UHT_STATICS::NewProp_bRequireFacingBeforeAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireFacingBeforeAttack_MetaData), NewProp_bRequireFacingBeforeAttack_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CombatFacingTurnRateDegreesPerSecond = { "CombatFacingTurnRateDegreesPerSecond", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, CombatFacingTurnRateDegreesPerSecond), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatFacingTurnRateDegreesPerSecond_MetaData), NewProp_CombatFacingTurnRateDegreesPerSecond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AttackFacingToleranceDegrees = { "AttackFacingToleranceDegrees", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, AttackFacingToleranceDegrees), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackFacingToleranceDegrees_MetaData), NewProp_AttackFacingToleranceDegrees_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CombatFacingUpdateInterval = { "CombatFacingUpdateInterval", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, CombatFacingUpdateInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatFacingUpdateInterval_MetaData), NewProp_CombatFacingUpdateInterval_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bHoldDefeatedPoseUntilRevivedOrDismissed = { "bHoldDefeatedPoseUntilRevivedOrDismissed", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonCharacter), &UHT_STATICS::NewProp_bHoldDefeatedPoseUntilRevivedOrDismissed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHoldDefeatedPoseUntilRevivedOrDismissed_MetaData), NewProp_bHoldDefeatedPoseUntilRevivedOrDismissed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DefeatedPoseHoldNormalizedTime = { "DefeatedPoseHoldNormalizedTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, DefeatedPoseHoldNormalizedTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefeatedPoseHoldNormalizedTime_MetaData), NewProp_DefeatedPoseHoldNormalizedTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DefeatedMontagePlayRate = { "DefeatedMontagePlayRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, DefeatedMontagePlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefeatedMontagePlayRate_MetaData), NewProp_DefeatedMontagePlayRate_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDisableMovementWhenDefeated = { "bDisableMovementWhenDefeated", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonCharacter), &UHT_STATICS::NewProp_bDisableMovementWhenDefeated_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableMovementWhenDefeated_MetaData), NewProp_bDisableMovementWhenDefeated_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDisableCapsuleCollisionWhenDefeated = { "bDisableCapsuleCollisionWhenDefeated", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonCharacter), &UHT_STATICS::NewProp_bDisableCapsuleCollisionWhenDefeated_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableCapsuleCollisionWhenDefeated_MetaData), NewProp_bDisableCapsuleCollisionWhenDefeated_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CombatComponent = { "CombatComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, CombatComponent), Z_Construct_UClass_UDMFDigimonCombatComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatComponent_MetaData), NewProp_CombatComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", "OnRep_DigimonState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonInstanceId_MetaData), NewProp_DigimonInstanceId_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", "OnRep_DigimonState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesId_MetaData), NewProp_SpeciesId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReplicatedStats = { "ReplicatedStats", "OnRep_DigimonState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, ReplicatedStats), Z_Construct_UScriptStruct_FDMFDigimonStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedStats_MetaData), NewProp_ReplicatedStats_MetaData) }; // 520b7c977c816e4f689d80785fbab8bbe48405a6
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_ReplicatedAbilityIds_Inner = { "ReplicatedAbilityIds", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReplicatedAbilityIds = { "ReplicatedAbilityIds", "OnRep_DigimonState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, ReplicatedAbilityIds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedAbilityIds_MetaData), NewProp_ReplicatedAbilityIds_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OwningPlayerState = { "OwningPlayerState", nullptr, (EPropertyFlags)0x0114000000000034, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, OwningPlayerState), Z_Construct_UClass_ADMFPlayerState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwningPlayerState_MetaData), NewProp_OwningPlayerState_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_CombatTeamId = { "CombatTeamId", nullptr, (EPropertyFlags)0x0010000000000035, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, CombatTeamId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatTeamId_MetaData), NewProp_CombatTeamId_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCombatTargetable = { "bCombatTargetable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonCharacter), &UHT_STATICS::NewProp_bCombatTargetable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCombatTargetable_MetaData), NewProp_bCombatTargetable_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CustomDepthStencilValue = { "CustomDepthStencilValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, CustomDepthStencilValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomDepthStencilValue_MetaData), NewProp_CustomDepthStencilValue_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActiveDeathMontage = { "ActiveDeathMontage", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCharacter, ActiveDeathMontage), Z_Construct_UClass_UAnimMontage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveDeathMontage_MetaData), NewProp_ActiveDeathMontage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableCombatFacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequireFacingBeforeAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatFacingTurnRateDegreesPerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AttackFacingToleranceDegrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatFacingUpdateInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bHoldDefeatedPoseUntilRevivedOrDismissed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefeatedPoseHoldNormalizedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefeatedMontagePlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDisableMovementWhenDefeated,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDisableCapsuleCollisionWhenDefeated,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedStats,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedAbilityIds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedAbilityIds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OwningPlayerState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatTeamId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCombatTargetable,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CustomDepthStencilValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActiveDeathMontage,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFDigimonCharacter Property Definitions **********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_ACharacter,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFDigimonCharacter,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void ADMFDigimonCharacter_StaticRegisterNativesADMFDigimonCharacter()
{
	UClass* Class = ADMFDigimonCharacter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFDigimonCharacter;
UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFDigimonCharacter;
		if (!Z_Registration_Info_UClass_ADMFDigimonCharacter.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonCharacter"),
				Z_Registration_Info_UClass_ADMFDigimonCharacter.InnerSingleton,
				ADMFDigimonCharacter_StaticRegisterNativesADMFDigimonCharacter,
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
		return Z_Registration_Info_UClass_ADMFDigimonCharacter.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFDigimonCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFDigimonCharacter.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFDigimonCharacter.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFDigimonCharacter::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_DigimonInstanceId(TEXT("DigimonInstanceId"));
	static FName Name_SpeciesId(TEXT("SpeciesId"));
	static FName Name_ReplicatedStats(TEXT("ReplicatedStats"));
	static FName Name_ReplicatedAbilityIds(TEXT("ReplicatedAbilityIds"));
	static FName Name_OwningPlayerState(TEXT("OwningPlayerState"));
	static FName Name_CombatTeamId(TEXT("CombatTeamId"));
	const bool bIsValid = true
		&& Name_DigimonInstanceId == ClassReps[(int32)ENetFields_Private::DigimonInstanceId].Property->GetFName()
		&& Name_SpeciesId == ClassReps[(int32)ENetFields_Private::SpeciesId].Property->GetFName()
		&& Name_ReplicatedStats == ClassReps[(int32)ENetFields_Private::ReplicatedStats].Property->GetFName()
		&& Name_ReplicatedAbilityIds == ClassReps[(int32)ENetFields_Private::ReplicatedAbilityIds].Property->GetFName()
		&& Name_OwningPlayerState == ClassReps[(int32)ENetFields_Private::OwningPlayerState].Property->GetFName()
		&& Name_CombatTeamId == ClassReps[(int32)ENetFields_Private::CombatTeamId].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFDigimonCharacter"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFDigimonCharacter);
ADMFDigimonCharacter::~ADMFDigimonCharacter() {}
// ********** End Class ADMFDigimonCharacter *******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFDigimonCharacter, TEXT("ADMFDigimonCharacter"), &Z_Registration_Info_UClass_ADMFDigimonCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFDigimonCharacter), 2559452473U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCharacter_h__Script_DigimonMMOFramework_1e7eb649a88fa08e99e75e57434d3f9513058f44{
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
