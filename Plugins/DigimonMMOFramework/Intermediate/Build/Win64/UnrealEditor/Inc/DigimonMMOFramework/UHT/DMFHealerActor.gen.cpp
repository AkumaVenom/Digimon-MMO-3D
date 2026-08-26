// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFHealerActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFHealerActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UParticleSystem(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_APlayerController(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USceneComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USoundBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USphereComponent(ETypeConstructPhase);
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent(ETypeConstructPhase);
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFHealerActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFHealerActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerState(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ADMFHealerActor Function BP_OnEnabledStateChanged ************************
struct DMFHealerActor_eventBP_OnEnabledStateChanged_Parms
{
	bool bIsEnabled;
};
static FName NAME_ADMFHealerActor_BP_OnEnabledStateChanged = FName(TEXT("BP_OnEnabledStateChanged"));
void ADMFHealerActor::BP_OnEnabledStateChanged(bool bIsEnabled)
{
	DMFHealerActor_eventBP_OnEnabledStateChanged_Parms Parms;
	Parms.bIsEnabled=bIsEnabled ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ADMFHealerActor_BP_OnEnabledStateChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_BP_OnEnabledStateChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnEnabledStateChanged constinit property declarations **************
	static void NewProp_bIsEnabled_SetBit(void* Obj)
	{
		((DMFHealerActor_eventBP_OnEnabledStateChanged_Parms*)Obj)->bIsEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnEnabledStateChanged constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnEnabledStateChanged Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsEnabled = { "bIsEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFHealerActor_eventBP_OnEnabledStateChanged_Parms), &UHT_STATICS::NewProp_bIsEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnEnabledStateChanged Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "BP_OnEnabledStateChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFHealerActor_eventBP_OnEnabledStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFHealerActor_eventBP_OnEnabledStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_BP_OnEnabledStateChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFHealerActor Function BP_OnEnabledStateChanged **************************

// ********** Begin Class ADMFHealerActor Function BP_OnHealingSequenceFinished ********************
struct DMFHealerActor_eventBP_OnHealingSequenceFinished_Parms
{
	ADMFPlayerState* HealedPlayerState;
	int32 DigimonHealed;
};
static FName NAME_ADMFHealerActor_BP_OnHealingSequenceFinished = FName(TEXT("BP_OnHealingSequenceFinished"));
void ADMFHealerActor::BP_OnHealingSequenceFinished(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed)
{
	DMFHealerActor_eventBP_OnHealingSequenceFinished_Parms Parms;
	Parms.HealedPlayerState=HealedPlayerState;
	Parms.DigimonHealed=DigimonHealed;
	UFunction* Func = FindFunctionChecked(NAME_ADMFHealerActor_BP_OnHealingSequenceFinished);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_BP_OnHealingSequenceFinished_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replicated presentation hook called once when that native treatment sequence finishes locally. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated presentation hook called once when that native treatment sequence finishes locally." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnHealingSequenceFinished constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealedPlayerState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigimonHealed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnHealingSequenceFinished constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnHealingSequenceFinished Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealedPlayerState = { "HealedPlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventBP_OnHealingSequenceFinished_Parms, HealedPlayerState), Z_Construct_UClass_ADMFPlayerState, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigimonHealed = { "DigimonHealed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventBP_OnHealingSequenceFinished_Parms, DigimonHealed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealedPlayerState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonHealed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnHealingSequenceFinished Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "BP_OnHealingSequenceFinished", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFHealerActor_eventBP_OnHealingSequenceFinished_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFHealerActor_eventBP_OnHealingSequenceFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_BP_OnHealingSequenceFinished(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFHealerActor Function BP_OnHealingSequenceFinished **********************

// ********** Begin Class ADMFHealerActor Function BP_OnHealingSequenceStarted *********************
struct DMFHealerActor_eventBP_OnHealingSequenceStarted_Parms
{
	ADMFPlayerState* HealedPlayerState;
	int32 DigimonHealed;
};
static FName NAME_ADMFHealerActor_BP_OnHealingSequenceStarted = FName(TEXT("BP_OnHealingSequenceStarted"));
void ADMFHealerActor::BP_OnHealingSequenceStarted(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed)
{
	DMFHealerActor_eventBP_OnHealingSequenceStarted_Parms Parms;
	Parms.HealedPlayerState=HealedPlayerState;
	Parms.DigimonHealed=DigimonHealed;
	UFunction* Func = FindFunctionChecked(NAME_ADMFHealerActor_BP_OnHealingSequenceStarted);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_BP_OnHealingSequenceStarted_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replicated presentation hook called once when the exclusive native treatment sequence starts locally. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated presentation hook called once when the exclusive native treatment sequence starts locally." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnHealingSequenceStarted constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealedPlayerState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigimonHealed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnHealingSequenceStarted constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnHealingSequenceStarted Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealedPlayerState = { "HealedPlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventBP_OnHealingSequenceStarted_Parms, HealedPlayerState), Z_Construct_UClass_ADMFPlayerState, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigimonHealed = { "DigimonHealed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventBP_OnHealingSequenceStarted_Parms, DigimonHealed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealedPlayerState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonHealed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnHealingSequenceStarted Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "BP_OnHealingSequenceStarted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFHealerActor_eventBP_OnHealingSequenceStarted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFHealerActor_eventBP_OnHealingSequenceStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_BP_OnHealingSequenceStarted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFHealerActor Function BP_OnHealingSequenceStarted ***********************

// ********** Begin Class ADMFHealerActor Function BP_OnHealPresentation ***************************
struct DMFHealerActor_eventBP_OnHealPresentation_Parms
{
	ADMFPlayerState* HealedPlayerState;
	int32 DigimonHealed;
};
static FName NAME_ADMFHealerActor_BP_OnHealPresentation = FName(TEXT("BP_OnHealPresentation"));
void ADMFHealerActor::BP_OnHealPresentation(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed)
{
	DMFHealerActor_eventBP_OnHealPresentation_Parms Parms;
	Parms.HealedPlayerState=HealedPlayerState;
	Parms.DigimonHealed=DigimonHealed;
	UFunction* Func = FindFunctionChecked(NAME_ADMFHealerActor_BP_OnHealPresentation);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_BP_OnHealPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy cosmetic hook preserved for existing Blueprints; still multicasts on accepted healer use. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy cosmetic hook preserved for existing Blueprints; still multicasts on accepted healer use." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnHealPresentation constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealedPlayerState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigimonHealed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnHealPresentation constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnHealPresentation Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealedPlayerState = { "HealedPlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventBP_OnHealPresentation_Parms, HealedPlayerState), Z_Construct_UClass_ADMFPlayerState, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigimonHealed = { "DigimonHealed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventBP_OnHealPresentation_Parms, DigimonHealed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealedPlayerState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonHealed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnHealPresentation Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "BP_OnHealPresentation", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFHealerActor_eventBP_OnHealPresentation_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFHealerActor_eventBP_OnHealPresentation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_BP_OnHealPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFHealerActor Function BP_OnHealPresentation *****************************

// ********** Begin Class ADMFHealerActor Function BP_OnPlayerHealed *******************************
struct DMFHealerActor_eventBP_OnPlayerHealed_Parms
{
	APlayerController* PlayerController;
	int32 DigimonHealed;
};
static FName NAME_ADMFHealerActor_BP_OnPlayerHealed = FName(TEXT("BP_OnPlayerHealed"));
void ADMFHealerActor::BP_OnPlayerHealed(APlayerController* PlayerController, int32 DigimonHealed)
{
	DMFHealerActor_eventBP_OnPlayerHealed_Parms Parms;
	Parms.PlayerController=PlayerController;
	Parms.DigimonHealed=DigimonHealed;
	UFunction* Func = FindFunctionChecked(NAME_ADMFHealerActor_BP_OnPlayerHealed);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_BP_OnPlayerHealed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server-side gameplay hook after an accepted use. Preserved for existing healer Blueprints. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-side gameplay hook after an accepted use. Preserved for existing healer Blueprints." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPlayerHealed constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigimonHealed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnPlayerHealed constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnPlayerHealed Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventBP_OnPlayerHealed_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigimonHealed = { "DigimonHealed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventBP_OnPlayerHealed_Parms, DigimonHealed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonHealed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnPlayerHealed Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "BP_OnPlayerHealed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFHealerActor_eventBP_OnPlayerHealed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFHealerActor_eventBP_OnPlayerHealed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_BP_OnPlayerHealed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFHealerActor Function BP_OnPlayerHealed *********************************

// ********** Begin Class ADMFHealerActor Function GetActiveHealingPlayerState *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_GetActiveHealingPlayerState_Statics
struct UHT_STATICS
{
	struct DMFHealerActor_eventGetActiveHealingPlayerState_Parms
	{
		ADMFPlayerState* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Sequence" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveHealingPlayerState constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveHealingPlayerState constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveHealingPlayerState Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventGetActiveHealingPlayerState_Parms, ReturnValue), Z_Construct_UClass_ADMFPlayerState, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetActiveHealingPlayerState Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "GetActiveHealingPlayerState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFHealerActor_eventGetActiveHealingPlayerState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFHealerActor_eventGetActiveHealingPlayerState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_GetActiveHealingPlayerState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execGetActiveHealingPlayerState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFPlayerState**)Z_Param__Result=P_THIS->GetActiveHealingPlayerState();
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function GetActiveHealingPlayerState ***********************

// ********** Begin Class ADMFHealerActor Function IsHealing ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_IsHealing_Statics
struct UHT_STATICS
{
	struct DMFHealerActor_eventIsHealing_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Sequence" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsHealing constinit property declarations *****************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFHealerActor_eventIsHealing_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsHealing constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsHealing Property Definitions ****************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFHealerActor_eventIsHealing_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsHealing Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "IsHealing", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFHealerActor_eventIsHealing_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFHealerActor_eventIsHealing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_IsHealing(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execIsHealing)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsHealing();
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function IsHealing *****************************************

// ********** Begin Class ADMFHealerActor Function IsPlayerWithinInteractionRange ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_IsPlayerWithinInteractionRange_Statics
struct UHT_STATICS
{
	struct DMFHealerActor_eventIsPlayerWithinInteractionRange_Parms
	{
		const APlayerController* PlayerController;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerController_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPlayerWithinInteractionRange constinit property declarations ********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFHealerActor_eventIsPlayerWithinInteractionRange_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPlayerWithinInteractionRange constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPlayerWithinInteractionRange Property Definitions *******************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventIsPlayerWithinInteractionRange_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerController_MetaData), NewProp_PlayerController_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFHealerActor_eventIsPlayerWithinInteractionRange_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsPlayerWithinInteractionRange Property Definitions *********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "IsPlayerWithinInteractionRange", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFHealerActor_eventIsPlayerWithinInteractionRange_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFHealerActor_eventIsPlayerWithinInteractionRange_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_IsPlayerWithinInteractionRange(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execIsPlayerWithinInteractionRange)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayerWithinInteractionRange(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function IsPlayerWithinInteractionRange ********************

// ********** Begin Class ADMFHealerActor Function MulticastHealPresentation ***********************
struct DMFHealerActor_eventMulticastHealPresentation_Parms
{
	ADMFPlayerState* HealedPlayerState;
	int32 DigimonHealed;
};
static FName NAME_ADMFHealerActor_MulticastHealPresentation = FName(TEXT("MulticastHealPresentation"));
void ADMFHealerActor::MulticastHealPresentation(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed)
{
	DMFHealerActor_eventMulticastHealPresentation_Parms Parms;
	Parms.HealedPlayerState=HealedPlayerState;
	Parms.DigimonHealed=DigimonHealed;
	UFunction* Func = FindFunctionChecked(NAME_ADMFHealerActor_MulticastHealPresentation);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_MulticastHealPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MulticastHealPresentation constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealedPlayerState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigimonHealed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MulticastHealPresentation constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MulticastHealPresentation Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealedPlayerState = { "HealedPlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventMulticastHealPresentation_Parms, HealedPlayerState), Z_Construct_UClass_ADMFPlayerState, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigimonHealed = { "DigimonHealed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventMulticastHealPresentation_Parms, DigimonHealed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealedPlayerState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonHealed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MulticastHealPresentation Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "MulticastHealPresentation", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFHealerActor_eventMulticastHealPresentation_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00044C41, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFHealerActor_eventMulticastHealPresentation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_MulticastHealPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execMulticastHealPresentation)
{
	P_GET_OBJECT(ADMFPlayerState,Z_Param_HealedPlayerState);
	P_GET_PROPERTY(FIntProperty,Z_Param_DigimonHealed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MulticastHealPresentation_Implementation(Z_Param_HealedPlayerState,Z_Param_DigimonHealed);
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function MulticastHealPresentation *************************

// ********** Begin Class ADMFHealerActor Function OnRep_Enabled ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_OnRep_Enabled_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_Enabled constinit property declarations *************************
// ********** End Function OnRep_Enabled constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "OnRep_Enabled", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFHealerActor_OnRep_Enabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execOnRep_Enabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Enabled();
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function OnRep_Enabled *************************************

// ********** Begin Class ADMFHealerActor Function OnRep_HealingPresentationState ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_OnRep_HealingPresentationState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_HealingPresentationState constinit property declarations ********
// ********** End Function OnRep_HealingPresentationState constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "OnRep_HealingPresentationState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFHealerActor_OnRep_HealingPresentationState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execOnRep_HealingPresentationState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_HealingPresentationState();
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function OnRep_HealingPresentationState ********************

// ********** Begin Class ADMFHealerActor Function RefreshHealingPresentation **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_RefreshHealingPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reapply anchor transform, light tuning and assigned Niagara/Cascade/Sound assets after runtime customization. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reapply anchor transform, light tuning and assigned Niagara/Cascade/Sound assets after runtime customization." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshHealingPresentation constinit property declarations ************
// ********** End Function RefreshHealingPresentation constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "RefreshHealingPresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFHealerActor_RefreshHealingPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execRefreshHealingPresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshHealingPresentation();
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function RefreshHealingPresentation ************************

// ********** Begin Class ADMFHealerActor Function RequestHeal *************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_RequestHeal_Statics
struct UHT_STATICS
{
	struct DMFHealerActor_eventRequestHeal_Parms
	{
		APlayerController* PlayerController;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lower-level API for custom systems. Normal player setup uses ADMFPlayerAvatarCharacter::Interact. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lower-level API for custom systems. Normal player setup uses ADMFPlayerAvatarCharacter::Interact." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestHeal constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestHeal constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestHeal Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventRequestHeal_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestHeal Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "RequestHeal", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFHealerActor_eventRequestHeal_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFHealerActor_eventRequestHeal_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_RequestHeal(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execRequestHeal)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestHeal(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function RequestHeal ***************************************

// ********** Begin Class ADMFHealerActor Function SetHealerEnabled ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_SetHealerEnabled_Statics
struct UHT_STATICS
{
	struct DMFHealerActor_eventSetHealerEnabled_Parms
	{
		bool bNewEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetHealerEnabled constinit property declarations **********************
	static void NewProp_bNewEnabled_SetBit(void* Obj)
	{
		((DMFHealerActor_eventSetHealerEnabled_Parms*)Obj)->bNewEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetHealerEnabled constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetHealerEnabled Property Definitions *********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bNewEnabled = { "bNewEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFHealerActor_eventSetHealerEnabled_Parms), &UHT_STATICS::NewProp_bNewEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bNewEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetHealerEnabled Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "SetHealerEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFHealerActor_eventSetHealerEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFHealerActor_eventSetHealerEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_SetHealerEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execSetHealerEnabled)
{
	P_GET_UBOOL(Z_Param_bNewEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHealerEnabled(Z_Param_bNewEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function SetHealerEnabled **********************************

// ********** Begin Class ADMFHealerActor Function TryHealPlayerAuthoritative **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFHealerActor_TryHealPlayerAuthoritative_Statics
struct UHT_STATICS
{
	struct DMFHealerActor_eventTryHealPlayerAuthoritative_Parms
	{
		APlayerController* PlayerController;
		int32 OutDigimonHealed;
		FText OutMessage;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryHealPlayerAuthoritative constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutDigimonHealed;
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutMessage;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFHealerActor_eventTryHealPlayerAuthoritative_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryHealPlayerAuthoritative constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryHealPlayerAuthoritative Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventTryHealPlayerAuthoritative_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_OutDigimonHealed = { "OutDigimonHealed", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventTryHealPlayerAuthoritative_Parms, OutDigimonHealed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_OutMessage = { "OutMessage", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHealerActor_eventTryHealPlayerAuthoritative_Parms, OutMessage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFHealerActor_eventTryHealPlayerAuthoritative_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutDigimonHealed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function TryHealPlayerAuthoritative Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFHealerActor, nullptr, "TryHealPlayerAuthoritative", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFHealerActor_eventTryHealPlayerAuthoritative_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFHealerActor_eventTryHealPlayerAuthoritative_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFHealerActor_TryHealPlayerAuthoritative(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFHealerActor::execTryHealPlayerAuthoritative)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutDigimonHealed);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_OutMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->TryHealPlayerAuthoritative(Z_Param_PlayerController,Z_Param_Out_OutDigimonHealed,Z_Param_Out_OutMessage);
	P_NATIVE_END;
}
// ********** End Class ADMFHealerActor Function TryHealPlayerAuthoritative ************************

// ********** Begin Class ADMFHealerActor **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFHealerActor_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server-authoritative, free Digimon healer station/NPC interaction endpoint.\n *\n * The healer owns a replicated exclusive treatment state plus an optional native presentation rig:\n * a Blueprint-positionable anchor, pulsing green point light, Niagara-preferred/Cascade-fallback VFX\n * and healing audio. Gameplay restoration remains server-authoritative and can restore the complete\n * six-Digimon Party plus every persistent Bank/Box record in a single accepted use.\n */" },
#endif
		{ "IncludePath", "Game/DMFHealerActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-authoritative, free Digimon healer station/NPC interaction endpoint.\n\nThe healer owns a replicated exclusive treatment state plus an optional native presentation rig:\na Blueprint-positionable anchor, pulsing green point light, Niagara-preferred/Cascade-fallback VFX\nand healing audio. Gameplay restoration remains server-authoritative and can restore the complete\nsix-Digimon Party plus every persistent Bank/Box record in a single accepted use." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionCollision_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native query-only interaction volume so the framework Interact() trace works without project collision setup. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native query-only interaction volume so the framework Interact() trace works without project collision setup." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingPresentationAnchor_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Presentation origin intended to be moved into the center/interior of the project's healer mesh. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Presentation origin intended to be moved into the center/interior of the project's healer mesh." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingLight_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native green treatment light. Its intensity is animated locally from the replicated healer state. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native green treatment light. Its intensity is animated locally from the replicated healer state." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingNiagaraComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Preferred modern VFX component. Assign Healing Niagara System below; Cascade remains an automatic fallback. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Preferred modern VFX component. Assign Healing Niagara System below; Cascade remains an automatic fallback." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingCascadeComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy Cascade fallback for projects that already own a Cascade healing-plus effect. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy Cascade fallback for projects that already own a Cascade healing-plus effect." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingAudioComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Attached spatial healing audio component. A Sound Cue with attenuation is recommended. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attached spatial healing audio component. A Sound Cue with attenuation is recommended." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Runtime master switch. Replicated so Blueprint presentation can reflect server availability. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime master switch. Replicated so Blueprint presentation can reflect server availability." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHealingInProgress_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Sequence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True while this station is exclusively presenting one accepted player's treatment. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True while this station is exclusively presenting one accepted player's treatment." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveHealingPlayerState_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Sequence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Public replicated PlayerState being presented by this station; null while idle. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Public replicated PlayerState being presented by this station; null while idle." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveHealingDigimonCount_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Sequence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of Party/Bank Digimon actually restored by the active treatment. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of Party/Bank Digimon actually restored by the active treatment." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum authoritative distance from player pawn to healer actor. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum authoritative distance from player pawn to healer actor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionCollisionRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Interaction" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Query-only trace hit volume; intentionally separate from authoritative use distance. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Query-only trace hit volume; intentionally separate from authoritative use distance." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionTraceChannel_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Channel blocked by the native interaction hit volume. Match the player interaction trace channel when customizing it. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Channel blocked by the native interaction hit volume. Match the player interaction trace channel when customizing it." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReuseDelay_MetaData[] = {
		{ "Category", "Digimon MMO|Healer" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimum server-side reuse interval per player to prevent interaction RPC spam. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum server-side reuse interval per player to prevent interaction RPC spam." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingSequenceDuration_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Sequence" },
		{ "ClampMax", "30.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Visual treatment duration. One station remains exclusive to the accepted player for this period. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual treatment duration. One station remains exclusive to the accepted player for this period." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHealHP_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Restore" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHealSP_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Restore" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRestoreDefeatedDigimon_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Restore" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, HP restoration revives defeated owned Digimon. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, HP restoration revives defeated owned Digimon." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeBankStorage_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Restore" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Heals every server-side Bank/Box record as well as the replicated Party. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Heals every server-side Bank/Box record as well as the replicated Party." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSummonActivePartnerAfterHeal_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Restore" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If the selected active partner is currently recalled/missing, summon it after a successful restore. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If the selected active partner is currently recalled/missing, summon it after a successful restore." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingPresentationRelativeTransform_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Placement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** One relative transform moves the complete light/VFX/audio rig into the interior of any healer mesh. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One relative transform moves the complete light/VFX/audio rig into the interior of any healer mesh." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableHealingLight_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Light" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Built-in green treatment glow. Disable if the project supplies all lighting from the healer Blueprint/material. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Built-in green treatment glow. Disable if the project supplies all lighting from the healer Blueprint/material." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingLightColor_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Light" },
		{ "EditCondition", "bEnableHealingLight" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingLightIntensity_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Light" },
		{ "ClampMax", "100000.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableHealingLight" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingLightAttenuationRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Light" },
		{ "ClampMax", "10000.0" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bEnableHealingLight" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingLightPulseAmount_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Light" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Small pulse amount gives a machine-like animated glow without requiring an animated healer mesh. */" },
#endif
		{ "EditCondition", "bEnableHealingLight" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Small pulse amount gives a machine-like animated glow without requiring an animated healer mesh." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingLightPulseFrequencyHz_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Light" },
		{ "ClampMax", "20.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableHealingLight" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingLightFadeInSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Light" },
		{ "ClampMax", "5.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableHealingLight" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingLightFadeOutSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Light" },
		{ "ClampMax", "5.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableHealingLight" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingNiagaraSystem_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|VFX" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Preferred healing VFX. Author green plus sprites/meshes in Niagara and make the system loop for the sequence duration. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Preferred healing VFX. Author green plus sprites/meshes in Niagara and make the system loop for the sequence duration." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingCascadeSystem_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|VFX" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cascade fallback. Used automatically when Niagara is unassigned, or first when Prefer Niagara is disabled. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cascade fallback. Used automatically when Niagara is unassigned, or first when Prefer Niagara is disabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreferNiagaraHealingVFX_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|VFX" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When both systems are assigned, Niagara is used by default and Cascade remains the fallback. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When both systems are assigned, Niagara is used by default and Cascade remains the fallback." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingSound_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spatial treatment sound. A looping/randomized Sound Cue with attenuation is recommended. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spatial treatment sound. A looping/randomized Sound Cue with attenuation is recommended." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingSoundVolumeMultiplier_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Audio" },
		{ "ClampMax", "4.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingSoundPitchMultiplier_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Audio" },
		{ "ClampMax", "4.0" },
		{ "ClampMin", "0.25" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingSoundFadeOutSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Presentation|Audio" },
		{ "ClampMax", "5.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionPrompt_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Text" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SuccessMessage_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Text" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlreadyHealthyMessage_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Text" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisabledMessage_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Text" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TooFarMessage_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Text" },
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BusyMessage_MetaData[] = {
		{ "Category", "Digimon MMO|Healer|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returned while another accepted player's treatment presentation owns this station. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFHealerActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returned while another accepted player's treatment presentation owns this station." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFHealerActor constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractionCollision;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealingPresentationAnchor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealingLight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealingNiagaraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealingCascadeComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealingAudioComponent;
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((ADMFHealerActor*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static void NewProp_bHealingInProgress_SetBit(void* Obj)
	{
		((ADMFHealerActor*)Obj)->bHealingInProgress = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHealingInProgress;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveHealingPlayerState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ActiveHealingDigimonCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionCollisionRadius;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InteractionTraceChannel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReuseDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingSequenceDuration;
	static void NewProp_bHealHP_SetBit(void* Obj)
	{
		((ADMFHealerActor*)Obj)->bHealHP = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHealHP;
	static void NewProp_bHealSP_SetBit(void* Obj)
	{
		((ADMFHealerActor*)Obj)->bHealSP = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHealSP;
	static void NewProp_bRestoreDefeatedDigimon_SetBit(void* Obj)
	{
		((ADMFHealerActor*)Obj)->bRestoreDefeatedDigimon = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRestoreDefeatedDigimon;
	static void NewProp_bIncludeBankStorage_SetBit(void* Obj)
	{
		((ADMFHealerActor*)Obj)->bIncludeBankStorage = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeBankStorage;
	static void NewProp_bSummonActivePartnerAfterHeal_SetBit(void* Obj)
	{
		((ADMFHealerActor*)Obj)->bSummonActivePartnerAfterHeal = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSummonActivePartnerAfterHeal;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HealingPresentationRelativeTransform;
	static void NewProp_bEnableHealingLight_SetBit(void* Obj)
	{
		((ADMFHealerActor*)Obj)->bEnableHealingLight = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableHealingLight;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HealingLightColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingLightIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingLightAttenuationRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingLightPulseAmount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingLightPulseFrequencyHz;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingLightFadeInSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingLightFadeOutSeconds;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_HealingNiagaraSystem;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_HealingCascadeSystem;
	static void NewProp_bPreferNiagaraHealingVFX_SetBit(void* Obj)
	{
		((ADMFHealerActor*)Obj)->bPreferNiagaraHealingVFX = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreferNiagaraHealingVFX;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_HealingSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingSoundVolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingSoundPitchMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealingSoundFadeOutSeconds;
	static const UECodeGen_Private::FTextPropertyParams NewProp_InteractionPrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_SuccessMessage;
	static const UECodeGen_Private::FTextPropertyParams NewProp_AlreadyHealthyMessage;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisabledMessage;
	static const UECodeGen_Private::FTextPropertyParams NewProp_TooFarMessage;
	static const UECodeGen_Private::FTextPropertyParams NewProp_BusyMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFHealerActor constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetActiveHealingPlayerState"), .Pointer = &ADMFHealerActor::execGetActiveHealingPlayerState },
		{ .NameUTF8 = UTF8TEXT("IsHealing"), .Pointer = &ADMFHealerActor::execIsHealing },
		{ .NameUTF8 = UTF8TEXT("IsPlayerWithinInteractionRange"), .Pointer = &ADMFHealerActor::execIsPlayerWithinInteractionRange },
		{ .NameUTF8 = UTF8TEXT("MulticastHealPresentation"), .Pointer = &ADMFHealerActor::execMulticastHealPresentation },
		{ .NameUTF8 = UTF8TEXT("OnRep_Enabled"), .Pointer = &ADMFHealerActor::execOnRep_Enabled },
		{ .NameUTF8 = UTF8TEXT("OnRep_HealingPresentationState"), .Pointer = &ADMFHealerActor::execOnRep_HealingPresentationState },
		{ .NameUTF8 = UTF8TEXT("RefreshHealingPresentation"), .Pointer = &ADMFHealerActor::execRefreshHealingPresentation },
		{ .NameUTF8 = UTF8TEXT("RequestHeal"), .Pointer = &ADMFHealerActor::execRequestHeal },
		{ .NameUTF8 = UTF8TEXT("SetHealerEnabled"), .Pointer = &ADMFHealerActor::execSetHealerEnabled },
		{ .NameUTF8 = UTF8TEXT("TryHealPlayerAuthoritative"), .Pointer = &ADMFHealerActor::execTryHealPlayerAuthoritative },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFHealerActor_BP_OnEnabledStateChanged, "BP_OnEnabledStateChanged" }, // f1bb969e78d7e46c42879cbf5dbc9ff37b75b1be
		{ &Z_Construct_UFunction_ADMFHealerActor_BP_OnHealingSequenceFinished, "BP_OnHealingSequenceFinished" }, // 3f572ddc61d084ee87165744630a21216fcf5de0
		{ &Z_Construct_UFunction_ADMFHealerActor_BP_OnHealingSequenceStarted, "BP_OnHealingSequenceStarted" }, // 60cc7561a3ceb554cd15b70c34a64f26bdf82d01
		{ &Z_Construct_UFunction_ADMFHealerActor_BP_OnHealPresentation, "BP_OnHealPresentation" }, // 3375fc9b3041d7c278271197d614e72ae43c5194
		{ &Z_Construct_UFunction_ADMFHealerActor_BP_OnPlayerHealed, "BP_OnPlayerHealed" }, // 3c78d141ff4fae40e4bc3d6578d967578d6b2730
		{ &Z_Construct_UFunction_ADMFHealerActor_GetActiveHealingPlayerState, "GetActiveHealingPlayerState" }, // 46c40e95f4d260f37b60256ea9b9b843fdbfe4b0
		{ &Z_Construct_UFunction_ADMFHealerActor_IsHealing, "IsHealing" }, // 19d3f5f081f02e6b949291c5331114c640bcf862
		{ &Z_Construct_UFunction_ADMFHealerActor_IsPlayerWithinInteractionRange, "IsPlayerWithinInteractionRange" }, // bfa75c07ac23d28bba93d3298b90cb0ad453c7af
		{ &Z_Construct_UFunction_ADMFHealerActor_MulticastHealPresentation, "MulticastHealPresentation" }, // 7ee91393cee70f8d423abab606bee236282058df
		{ &Z_Construct_UFunction_ADMFHealerActor_OnRep_Enabled, "OnRep_Enabled" }, // 43ed4eb5e02049953d0634850c835cc331637d33
		{ &Z_Construct_UFunction_ADMFHealerActor_OnRep_HealingPresentationState, "OnRep_HealingPresentationState" }, // 1b1630768cd72528c0724b9154731f73f9409e43
		{ &Z_Construct_UFunction_ADMFHealerActor_RefreshHealingPresentation, "RefreshHealingPresentation" }, // 161c68b3af232cfcebb552a9da4eb88bd836f3e9
		{ &Z_Construct_UFunction_ADMFHealerActor_RequestHeal, "RequestHeal" }, // e6f9da78a8a4941aa846194ebc569c455b20d72a
		{ &Z_Construct_UFunction_ADMFHealerActor_SetHealerEnabled, "SetHealerEnabled" }, // 2e1781855a4c8aa4ec8f24cdb514e1fd849f3a4c
		{ &Z_Construct_UFunction_ADMFHealerActor_TryHealPlayerAuthoritative, "TryHealPlayerAuthoritative" }, // 8c8d4c863e4235c3e9f8ba920444dfe598dac8f5
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFHealerActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFHealerActor Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, SceneRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InteractionCollision = { "InteractionCollision", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, InteractionCollision), Z_Construct_UClass_USphereComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionCollision_MetaData), NewProp_InteractionCollision_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealingPresentationAnchor = { "HealingPresentationAnchor", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingPresentationAnchor), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingPresentationAnchor_MetaData), NewProp_HealingPresentationAnchor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealingLight = { "HealingLight", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingLight), Z_Construct_UClass_UPointLightComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingLight_MetaData), NewProp_HealingLight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealingNiagaraComponent = { "HealingNiagaraComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingNiagaraComponent), Z_Construct_UClass_UNiagaraComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingNiagaraComponent_MetaData), NewProp_HealingNiagaraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealingCascadeComponent = { "HealingCascadeComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingCascadeComponent), Z_Construct_UClass_UParticleSystemComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingCascadeComponent_MetaData), NewProp_HealingCascadeComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealingAudioComponent = { "HealingAudioComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingAudioComponent), Z_Construct_UClass_UAudioComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingAudioComponent_MetaData), NewProp_HealingAudioComponent_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", "OnRep_Enabled", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFHealerActor), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bHealingInProgress = { "bHealingInProgress", "OnRep_HealingPresentationState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFHealerActor), &UHT_STATICS::NewProp_bHealingInProgress_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHealingInProgress_MetaData), NewProp_bHealingInProgress_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActiveHealingPlayerState = { "ActiveHealingPlayerState", "OnRep_HealingPresentationState", (EPropertyFlags)0x0114000100000034, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, ActiveHealingPlayerState), Z_Construct_UClass_ADMFPlayerState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveHealingPlayerState_MetaData), NewProp_ActiveHealingPlayerState_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ActiveHealingDigimonCount = { "ActiveHealingDigimonCount", "OnRep_HealingPresentationState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, ActiveHealingDigimonCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveHealingDigimonCount_MetaData), NewProp_ActiveHealingDigimonCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InteractionRadius = { "InteractionRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, InteractionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionRadius_MetaData), NewProp_InteractionRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InteractionCollisionRadius = { "InteractionCollisionRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, InteractionCollisionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionCollisionRadius_MetaData), NewProp_InteractionCollisionRadius_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InteractionTraceChannel = { "InteractionTraceChannel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, InteractionTraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionTraceChannel_MetaData), NewProp_InteractionTraceChannel_MetaData) }; // 3aff698625c18cc2ccaa87a587b2eac8c50cdec7
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReuseDelay = { "ReuseDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, ReuseDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReuseDelay_MetaData), NewProp_ReuseDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingSequenceDuration = { "HealingSequenceDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingSequenceDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingSequenceDuration_MetaData), NewProp_HealingSequenceDuration_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bHealHP = { "bHealHP", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFHealerActor), &UHT_STATICS::NewProp_bHealHP_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHealHP_MetaData), NewProp_bHealHP_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bHealSP = { "bHealSP", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFHealerActor), &UHT_STATICS::NewProp_bHealSP_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHealSP_MetaData), NewProp_bHealSP_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRestoreDefeatedDigimon = { "bRestoreDefeatedDigimon", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFHealerActor), &UHT_STATICS::NewProp_bRestoreDefeatedDigimon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRestoreDefeatedDigimon_MetaData), NewProp_bRestoreDefeatedDigimon_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIncludeBankStorage = { "bIncludeBankStorage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFHealerActor), &UHT_STATICS::NewProp_bIncludeBankStorage_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIncludeBankStorage_MetaData), NewProp_bIncludeBankStorage_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSummonActivePartnerAfterHeal = { "bSummonActivePartnerAfterHeal", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFHealerActor), &UHT_STATICS::NewProp_bSummonActivePartnerAfterHeal_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSummonActivePartnerAfterHeal_MetaData), NewProp_bSummonActivePartnerAfterHeal_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_HealingPresentationRelativeTransform = { "HealingPresentationRelativeTransform", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingPresentationRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingPresentationRelativeTransform_MetaData), NewProp_HealingPresentationRelativeTransform_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableHealingLight = { "bEnableHealingLight", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFHealerActor), &UHT_STATICS::NewProp_bEnableHealingLight_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableHealingLight_MetaData), NewProp_bEnableHealingLight_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_HealingLightColor = { "HealingLightColor", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingLightColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingLightColor_MetaData), NewProp_HealingLightColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingLightIntensity = { "HealingLightIntensity", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingLightIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingLightIntensity_MetaData), NewProp_HealingLightIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingLightAttenuationRadius = { "HealingLightAttenuationRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingLightAttenuationRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingLightAttenuationRadius_MetaData), NewProp_HealingLightAttenuationRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingLightPulseAmount = { "HealingLightPulseAmount", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingLightPulseAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingLightPulseAmount_MetaData), NewProp_HealingLightPulseAmount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingLightPulseFrequencyHz = { "HealingLightPulseFrequencyHz", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingLightPulseFrequencyHz), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingLightPulseFrequencyHz_MetaData), NewProp_HealingLightPulseFrequencyHz_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingLightFadeInSeconds = { "HealingLightFadeInSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingLightFadeInSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingLightFadeInSeconds_MetaData), NewProp_HealingLightFadeInSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingLightFadeOutSeconds = { "HealingLightFadeOutSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingLightFadeOutSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingLightFadeOutSeconds_MetaData), NewProp_HealingLightFadeOutSeconds_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_HealingNiagaraSystem = { "HealingNiagaraSystem", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingNiagaraSystem), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingNiagaraSystem_MetaData), NewProp_HealingNiagaraSystem_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_HealingCascadeSystem = { "HealingCascadeSystem", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingCascadeSystem), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingCascadeSystem_MetaData), NewProp_HealingCascadeSystem_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPreferNiagaraHealingVFX = { "bPreferNiagaraHealingVFX", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFHealerActor), &UHT_STATICS::NewProp_bPreferNiagaraHealingVFX_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreferNiagaraHealingVFX_MetaData), NewProp_bPreferNiagaraHealingVFX_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_HealingSound = { "HealingSound", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingSound), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingSound_MetaData), NewProp_HealingSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingSoundVolumeMultiplier = { "HealingSoundVolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingSoundVolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingSoundVolumeMultiplier_MetaData), NewProp_HealingSoundVolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingSoundPitchMultiplier = { "HealingSoundPitchMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingSoundPitchMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingSoundPitchMultiplier_MetaData), NewProp_HealingSoundPitchMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HealingSoundFadeOutSeconds = { "HealingSoundFadeOutSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, HealingSoundFadeOutSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingSoundFadeOutSeconds_MetaData), NewProp_HealingSoundFadeOutSeconds_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_InteractionPrompt = { "InteractionPrompt", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, InteractionPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionPrompt_MetaData), NewProp_InteractionPrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_SuccessMessage = { "SuccessMessage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, SuccessMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SuccessMessage_MetaData), NewProp_SuccessMessage_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_AlreadyHealthyMessage = { "AlreadyHealthyMessage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, AlreadyHealthyMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlreadyHealthyMessage_MetaData), NewProp_AlreadyHealthyMessage_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_DisabledMessage = { "DisabledMessage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, DisabledMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisabledMessage_MetaData), NewProp_DisabledMessage_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_TooFarMessage = { "TooFarMessage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, TooFarMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TooFarMessage_MetaData), NewProp_TooFarMessage_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_BusyMessage = { "BusyMessage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFHealerActor, BusyMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BusyMessage_MetaData), NewProp_BusyMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingPresentationAnchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingNiagaraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingCascadeComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bHealingInProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActiveHealingPlayerState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActiveHealingDigimonCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionCollisionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionTraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReuseDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingSequenceDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bHealHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bHealSP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRestoreDefeatedDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIncludeBankStorage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSummonActivePartnerAfterHeal,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingPresentationRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableHealingLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingLightColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingLightIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingLightAttenuationRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingLightPulseAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingLightPulseFrequencyHz,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingLightFadeInSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingLightFadeOutSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingNiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingCascadeSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPreferNiagaraHealingVFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingSoundVolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingSoundPitchMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealingSoundFadeOutSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SuccessMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AlreadyHealthyMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DisabledMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TooFarMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BusyMessage,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFHealerActor Property Definitions ***************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFHealerActor,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void ADMFHealerActor_StaticRegisterNativesADMFHealerActor()
{
	UClass* Class = ADMFHealerActor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFHealerActor;
UClass* Z_Construct_UClass_ADMFHealerActor(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFHealerActor;
		if (!Z_Registration_Info_UClass_ADMFHealerActor.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFHealerActor"),
				Z_Registration_Info_UClass_ADMFHealerActor.InnerSingleton,
				ADMFHealerActor_StaticRegisterNativesADMFHealerActor,
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
		return Z_Registration_Info_UClass_ADMFHealerActor.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFHealerActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFHealerActor.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFHealerActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFHealerActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_bEnabled(TEXT("bEnabled"));
	static FName Name_bHealingInProgress(TEXT("bHealingInProgress"));
	static FName Name_ActiveHealingPlayerState(TEXT("ActiveHealingPlayerState"));
	static FName Name_ActiveHealingDigimonCount(TEXT("ActiveHealingDigimonCount"));
	const bool bIsValid = true
		&& Name_bEnabled == ClassReps[(int32)ENetFields_Private::bEnabled].Property->GetFName()
		&& Name_bHealingInProgress == ClassReps[(int32)ENetFields_Private::bHealingInProgress].Property->GetFName()
		&& Name_ActiveHealingPlayerState == ClassReps[(int32)ENetFields_Private::ActiveHealingPlayerState].Property->GetFName()
		&& Name_ActiveHealingDigimonCount == ClassReps[(int32)ENetFields_Private::ActiveHealingDigimonCount].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFHealerActor"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFHealerActor);
ADMFHealerActor::~ADMFHealerActor() {}
// ********** End Class ADMFHealerActor ************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFHealerActor, TEXT("ADMFHealerActor"), &Z_Registration_Info_UClass_ADMFHealerActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFHealerActor), 1347302476U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFHealerActor_h__Script_DigimonMMOFramework_118d5a58296a80fffb27908a9190d84b22beecc8{
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
