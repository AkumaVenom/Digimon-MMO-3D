// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFDayNightSky.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDayNightSky() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UDirectionalLightComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USceneComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USkyAtmosphereComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USkyLightComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDayNightPhaseChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDayNightSky(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDayNightTimeSynchronized__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightPhase(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightTimeSource(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDayNightSky(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFDayNightPhaseChanged **********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDayNightPhaseChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFDayNightPhaseChanged_Parms
	{
		EDMFDayNightPhase NewPhase;
		EDMFDayNightPhase PreviousPhase;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFDayNightPhaseChanged constinit property declarations **************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewPhase;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PreviousPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PreviousPhase;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFDayNightPhaseChanged constinit property declarations ****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFDayNightPhaseChanged Property Definitions *************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewPhase = { "NewPhase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDayNightPhaseChanged_Parms, NewPhase), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightPhase, METADATA_PARAMS(0, nullptr) }; // 78bba6eb7608900637e4f59c3fc53f23bdfcfc40
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_PreviousPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_PreviousPhase = { "PreviousPhase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDayNightPhaseChanged_Parms, PreviousPhase), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightPhase, METADATA_PARAMS(0, nullptr) }; // 78bba6eb7608900637e4f59c3fc53f23bdfcfc40
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPhase,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousPhase,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFDayNightPhaseChanged Property Definitions ***************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFDayNightPhaseChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDayNightPhaseChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDayNightPhaseChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDayNightPhaseChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFDayNightPhaseChanged ************************************************

// ********** Begin Delegate FDMFDayNightTimeSynchronized ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDayNightTimeSynchronized__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFDayNightTimeSynchronized_Parms
	{
		float TimeOfDayHours;
		int32 DayIndex;
		EDMFDayNightTimeSource TimeSource;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFDayNightTimeSynchronized constinit property declarations **********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeOfDayHours;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DayIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TimeSource_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TimeSource;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFDayNightTimeSynchronized constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFDayNightTimeSynchronized Property Definitions *********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TimeOfDayHours = { "TimeOfDayHours", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDayNightTimeSynchronized_Parms, TimeOfDayHours), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DayIndex = { "DayIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDayNightTimeSynchronized_Parms, DayIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TimeSource_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TimeSource = { "TimeSource", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDayNightTimeSynchronized_Parms, TimeSource), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightTimeSource, METADATA_PARAMS(0, nullptr) }; // 9a11f543f9779874be680cad288a70fc2e0ef3a7
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeOfDayHours,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DayIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeSource_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeSource,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFDayNightTimeSynchronized Property Definitions ***********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFDayNightTimeSynchronized__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDayNightTimeSynchronized_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDayNightTimeSynchronized_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDayNightTimeSynchronized__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFDayNightTimeSynchronized ********************************************

// ********** Begin Class ADMFDayNightSky Function AdvanceSimulatedTimeByHours *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_AdvanceSimulatedTimeByHours_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventAdvanceSimulatedTimeByHours_Parms
	{
		float DeltaHours;
		bool bSaveImmediately;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Authority" },
		{ "CPP_Default_bSaveImmediately", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdvanceSimulatedTimeByHours constinit property declarations ***********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaHours;
	static void NewProp_bSaveImmediately_SetBit(void* Obj)
	{
		((DMFDayNightSky_eventAdvanceSimulatedTimeByHours_Parms*)Obj)->bSaveImmediately = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveImmediately;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AdvanceSimulatedTimeByHours constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AdvanceSimulatedTimeByHours Property Definitions **********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DeltaHours = { "DeltaHours", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventAdvanceSimulatedTimeByHours_Parms, DeltaHours), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSaveImmediately = { "bSaveImmediately", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDayNightSky_eventAdvanceSimulatedTimeByHours_Parms), &UHT_STATICS::NewProp_bSaveImmediately_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DeltaHours,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSaveImmediately,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AdvanceSimulatedTimeByHours Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "AdvanceSimulatedTimeByHours", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventAdvanceSimulatedTimeByHours_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventAdvanceSimulatedTimeByHours_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_AdvanceSimulatedTimeByHours(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execAdvanceSimulatedTimeByHours)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaHours);
	P_GET_UBOOL(Z_Param_bSaveImmediately);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AdvanceSimulatedTimeByHours(Z_Param_DeltaHours,Z_Param_bSaveImmediately);
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function AdvanceSimulatedTimeByHours ***********************

// ********** Begin Class ADMFDayNightSky Function BP_OnDayNightPhaseChanged ***********************
struct DMFDayNightSky_eventBP_OnDayNightPhaseChanged_Parms
{
	EDMFDayNightPhase NewPhase;
	EDMFDayNightPhase PreviousPhase;
};
static FName NAME_ADMFDayNightSky_BP_OnDayNightPhaseChanged = FName(TEXT("BP_OnDayNightPhaseChanged"));
void ADMFDayNightSky::BP_OnDayNightPhaseChanged(EDMFDayNightPhase NewPhase, EDMFDayNightPhase PreviousPhase)
{
	DMFDayNightSky_eventBP_OnDayNightPhaseChanged_Parms Parms;
	Parms.NewPhase=NewPhase;
	Parms.PreviousPhase=PreviousPhase;
	UFunction* Func = FindFunctionChecked(NAME_ADMFDayNightSky_BP_OnDayNightPhaseChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_BP_OnDayNightPhaseChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnDayNightPhaseChanged constinit property declarations *************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewPhase;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PreviousPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PreviousPhase;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnDayNightPhaseChanged constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnDayNightPhaseChanged Property Definitions ************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewPhase = { "NewPhase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventBP_OnDayNightPhaseChanged_Parms, NewPhase), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightPhase, METADATA_PARAMS(0, nullptr) }; // 78bba6eb7608900637e4f59c3fc53f23bdfcfc40
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_PreviousPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_PreviousPhase = { "PreviousPhase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventBP_OnDayNightPhaseChanged_Parms, PreviousPhase), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightPhase, METADATA_PARAMS(0, nullptr) }; // 78bba6eb7608900637e4f59c3fc53f23bdfcfc40
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPhase,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousPhase,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnDayNightPhaseChanged Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "BP_OnDayNightPhaseChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDayNightSky_eventBP_OnDayNightPhaseChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDayNightSky_eventBP_OnDayNightPhaseChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_BP_OnDayNightPhaseChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFDayNightSky Function BP_OnDayNightPhaseChanged *************************

// ********** Begin Class ADMFDayNightSky Function BP_OnSkyVisualUpdate ****************************
struct DMFDayNightSky_eventBP_OnSkyVisualUpdate_Parms
{
	float TimeOfDayHours;
	float TimeOfDayNormalized;
	float DayVisualAlpha;
};
static FName NAME_ADMFDayNightSky_BP_OnSkyVisualUpdate = FName(TEXT("BP_OnSkyVisualUpdate"));
void ADMFDayNightSky::BP_OnSkyVisualUpdate(float TimeOfDayHours, float TimeOfDayNormalized, float DayVisualAlpha)
{
	DMFDayNightSky_eventBP_OnSkyVisualUpdate_Parms Parms;
	Parms.TimeOfDayHours=TimeOfDayHours;
	Parms.TimeOfDayNormalized=TimeOfDayNormalized;
	Parms.DayVisualAlpha=DayVisualAlpha;
	UFunction* Func = FindFunctionChecked(NAME_ADMFDayNightSky_BP_OnSkyVisualUpdate);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_BP_OnSkyVisualUpdate_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local presentation callback at VisualUpdateIntervalSeconds; contains interpolated replicated time only, never authority. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local presentation callback at VisualUpdateIntervalSeconds; contains interpolated replicated time only, never authority." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnSkyVisualUpdate constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeOfDayHours;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeOfDayNormalized;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DayVisualAlpha;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnSkyVisualUpdate constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnSkyVisualUpdate Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TimeOfDayHours = { "TimeOfDayHours", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventBP_OnSkyVisualUpdate_Parms, TimeOfDayHours), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TimeOfDayNormalized = { "TimeOfDayNormalized", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventBP_OnSkyVisualUpdate_Parms, TimeOfDayNormalized), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DayVisualAlpha = { "DayVisualAlpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventBP_OnSkyVisualUpdate_Parms, DayVisualAlpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeOfDayHours,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeOfDayNormalized,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DayVisualAlpha,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnSkyVisualUpdate Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "BP_OnSkyVisualUpdate", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDayNightSky_eventBP_OnSkyVisualUpdate_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDayNightSky_eventBP_OnSkyVisualUpdate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_BP_OnSkyVisualUpdate(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFDayNightSky Function BP_OnSkyVisualUpdate ******************************

// ********** Begin Class ADMFDayNightSky Function GetCurrentDayIndex ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_GetCurrentDayIndex_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventGetCurrentDayIndex_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentDayIndex constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentDayIndex constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentDayIndex Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventGetCurrentDayIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentDayIndex Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "GetCurrentDayIndex", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventGetCurrentDayIndex_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventGetCurrentDayIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_GetCurrentDayIndex(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execGetCurrentDayIndex)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetCurrentDayIndex();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function GetCurrentDayIndex ********************************

// ********** Begin Class ADMFDayNightSky Function GetDayNightPhase ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_GetDayNightPhase_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventGetDayNightPhase_Parms
	{
		EDMFDayNightPhase ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDayNightPhase constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDayNightPhase constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDayNightPhase Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventGetDayNightPhase_Parms, ReturnValue), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightPhase, METADATA_PARAMS(0, nullptr) }; // 78bba6eb7608900637e4f59c3fc53f23bdfcfc40
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetDayNightPhase Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "GetDayNightPhase", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventGetDayNightPhase_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventGetDayNightPhase_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_GetDayNightPhase(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execGetDayNightPhase)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDMFDayNightPhase*)Z_Param__Result=P_THIS->GetDayNightPhase();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function GetDayNightPhase **********************************

// ********** Begin Class ADMFDayNightSky Function GetFormattedTime12Hour **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_GetFormattedTime12Hour_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventGetFormattedTime12Hour_Parms
	{
		bool bIncludeSeconds;
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Canonical smooth 12-hour world-clock text derived from the replicated/interpolated sky time (for example 9:42 PM). */" },
#endif
		{ "CPP_Default_bIncludeSeconds", "false" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Canonical smooth 12-hour world-clock text derived from the replicated/interpolated sky time (for example 9:42 PM)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetFormattedTime12Hour constinit property declarations ****************
	static void NewProp_bIncludeSeconds_SetBit(void* Obj)
	{
		((DMFDayNightSky_eventGetFormattedTime12Hour_Parms*)Obj)->bIncludeSeconds = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeSeconds;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFormattedTime12Hour constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFormattedTime12Hour Property Definitions ***************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIncludeSeconds = { "bIncludeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDayNightSky_eventGetFormattedTime12Hour_Parms), &UHT_STATICS::NewProp_bIncludeSeconds_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventGetFormattedTime12Hour_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIncludeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetFormattedTime12Hour Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "GetFormattedTime12Hour", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventGetFormattedTime12Hour_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventGetFormattedTime12Hour_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_GetFormattedTime12Hour(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execGetFormattedTime12Hour)
{
	P_GET_UBOOL(Z_Param_bIncludeSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetFormattedTime12Hour(Z_Param_bIncludeSeconds);
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function GetFormattedTime12Hour ****************************

// ********** Begin Class ADMFDayNightSky Function GetTimeOfDayHours *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_GetTimeOfDayHours_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventGetTimeOfDayHours_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTimeOfDayHours constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTimeOfDayHours constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTimeOfDayHours Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventGetTimeOfDayHours_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetTimeOfDayHours Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "GetTimeOfDayHours", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventGetTimeOfDayHours_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventGetTimeOfDayHours_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_GetTimeOfDayHours(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execGetTimeOfDayHours)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetTimeOfDayHours();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function GetTimeOfDayHours *********************************

// ********** Begin Class ADMFDayNightSky Function GetTimeOfDayNormalized **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_GetTimeOfDayNormalized_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventGetTimeOfDayNormalized_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTimeOfDayNormalized constinit property declarations ****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTimeOfDayNormalized constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTimeOfDayNormalized Property Definitions ***************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventGetTimeOfDayNormalized_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetTimeOfDayNormalized Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "GetTimeOfDayNormalized", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventGetTimeOfDayNormalized_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventGetTimeOfDayNormalized_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_GetTimeOfDayNormalized(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execGetTimeOfDayNormalized)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetTimeOfDayNormalized();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function GetTimeOfDayNormalized ****************************

// ********** Begin Class ADMFDayNightSky Function IsDay *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_IsDay_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventIsDay_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDay constinit property declarations *********************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDayNightSky_eventIsDay_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDay constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDay Property Definitions ********************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDayNightSky_eventIsDay_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsDay Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "IsDay", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventIsDay_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventIsDay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_IsDay(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execIsDay)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDay();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function IsDay *********************************************

// ********** Begin Class ADMFDayNightSky Function IsNight *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_IsNight_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventIsNight_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsNight constinit property declarations *******************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDayNightSky_eventIsNight_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsNight constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsNight Property Definitions ******************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDayNightSky_eventIsNight_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsNight Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "IsNight", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventIsNight_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventIsNight_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_IsNight(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execIsNight)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsNight();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function IsNight *******************************************

// ********** Begin Class ADMFDayNightSky Function OnRep_DayNightPhase *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_OnRep_DayNightPhase_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventOnRep_DayNightPhase_Parms
	{
		EDMFDayNightPhase PreviousPhase;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_DayNightPhase constinit property declarations *******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_PreviousPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PreviousPhase;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnRep_DayNightPhase constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnRep_DayNightPhase Property Definitions ******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_PreviousPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_PreviousPhase = { "PreviousPhase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventOnRep_DayNightPhase_Parms, PreviousPhase), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightPhase, METADATA_PARAMS(0, nullptr) }; // 78bba6eb7608900637e4f59c3fc53f23bdfcfc40
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousPhase,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnRep_DayNightPhase Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "OnRep_DayNightPhase", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventOnRep_DayNightPhase_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventOnRep_DayNightPhase_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_OnRep_DayNightPhase(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execOnRep_DayNightPhase)
{
	P_GET_ENUM(EDMFDayNightPhase,Z_Param_PreviousPhase);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_DayNightPhase(EDMFDayNightPhase(Z_Param_PreviousPhase));
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function OnRep_DayNightPhase *******************************

// ********** Begin Class ADMFDayNightSky Function OnRep_TimeAnchor ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_OnRep_TimeAnchor_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_TimeAnchor constinit property declarations **********************
// ********** End Function OnRep_TimeAnchor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "OnRep_TimeAnchor", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDayNightSky_OnRep_TimeAnchor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execOnRep_TimeAnchor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_TimeAnchor();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function OnRep_TimeAnchor **********************************

// ********** Begin Class ADMFDayNightSky Function RefreshSkyPresentation **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_RefreshSkyPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Digimon MMO|Day Night|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rebuilds dynamic materials and reapplies the current texture/material parameters. Safe after Blueprint runtime asset changes. Also exposed as an editor button. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rebuilds dynamic materials and reapplies the current texture/material parameters. Safe after Blueprint runtime asset changes. Also exposed as an editor button." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshSkyPresentation constinit property declarations ****************
// ********** End Function RefreshSkyPresentation constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "RefreshSkyPresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDayNightSky_RefreshSkyPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execRefreshSkyPresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshSkyPresentation();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function RefreshSkyPresentation ****************************

// ********** Begin Class ADMFDayNightSky Function ReloadDayNightState *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_ReloadDayNightState_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventReloadDayNightState_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Persistence" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ReloadDayNightState constinit property declarations *******************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDayNightSky_eventReloadDayNightState_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ReloadDayNightState constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ReloadDayNightState Property Definitions ******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDayNightSky_eventReloadDayNightState_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ReloadDayNightState Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "ReloadDayNightState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventReloadDayNightState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventReloadDayNightState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_ReloadDayNightState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execReloadDayNightState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ReloadDayNightState();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function ReloadDayNightState *******************************

// ********** Begin Class ADMFDayNightSky Function SaveDayNightStateNow ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_SaveDayNightStateNow_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventSaveDayNightStateNow_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Persistence" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SaveDayNightStateNow constinit property declarations ******************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDayNightSky_eventSaveDayNightStateNow_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveDayNightStateNow constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveDayNightStateNow Property Definitions *****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDayNightSky_eventSaveDayNightStateNow_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SaveDayNightStateNow Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "SaveDayNightStateNow", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventSaveDayNightStateNow_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventSaveDayNightStateNow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_SaveDayNightStateNow(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execSaveDayNightStateNow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SaveDayNightStateNow();
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function SaveDayNightStateNow ******************************

// ********** Begin Class ADMFDayNightSky Function SetAuthoritativeTimeSource **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_SetAuthoritativeTimeSource_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventSetAuthoritativeTimeSource_Parms
	{
		EDMFDayNightTimeSource NewTimeSource;
		bool bSaveImmediately;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Authority" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Runtime server-only mode switch. HostSystemTime immediately snaps to the authority PC clock. */" },
#endif
		{ "CPP_Default_bSaveImmediately", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime server-only mode switch. HostSystemTime immediately snaps to the authority PC clock." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetAuthoritativeTimeSource constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewTimeSource_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewTimeSource;
	static void NewProp_bSaveImmediately_SetBit(void* Obj)
	{
		((DMFDayNightSky_eventSetAuthoritativeTimeSource_Parms*)Obj)->bSaveImmediately = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveImmediately;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAuthoritativeTimeSource constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAuthoritativeTimeSource Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewTimeSource_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewTimeSource = { "NewTimeSource", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventSetAuthoritativeTimeSource_Parms, NewTimeSource), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightTimeSource, METADATA_PARAMS(0, nullptr) }; // 9a11f543f9779874be680cad288a70fc2e0ef3a7
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSaveImmediately = { "bSaveImmediately", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDayNightSky_eventSetAuthoritativeTimeSource_Parms), &UHT_STATICS::NewProp_bSaveImmediately_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTimeSource_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTimeSource,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSaveImmediately,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetAuthoritativeTimeSource Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "SetAuthoritativeTimeSource", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventSetAuthoritativeTimeSource_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventSetAuthoritativeTimeSource_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_SetAuthoritativeTimeSource(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execSetAuthoritativeTimeSource)
{
	P_GET_ENUM(EDMFDayNightTimeSource,Z_Param_NewTimeSource);
	P_GET_UBOOL(Z_Param_bSaveImmediately);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAuthoritativeTimeSource(EDMFDayNightTimeSource(Z_Param_NewTimeSource),Z_Param_bSaveImmediately);
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function SetAuthoritativeTimeSource ************************

// ********** Begin Class ADMFDayNightSky Function SetSimulatedTimeOfDay ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDayNightSky_SetSimulatedTimeOfDay_Statics
struct UHT_STATICS
{
	struct DMFDayNightSky_eventSetSimulatedTimeOfDay_Parms
	{
		float NewTimeOfDayHours;
		int32 NewDayIndex;
		bool bSaveImmediately;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Authority" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the persistent simulated clock. Does nothing while HostSystemTime is active. */" },
#endif
		{ "CPP_Default_bSaveImmediately", "true" },
		{ "CPP_Default_NewDayIndex", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the persistent simulated clock. Does nothing while HostSystemTime is active." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSimulatedTimeOfDay constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewTimeOfDayHours;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewDayIndex;
	static void NewProp_bSaveImmediately_SetBit(void* Obj)
	{
		((DMFDayNightSky_eventSetSimulatedTimeOfDay_Parms*)Obj)->bSaveImmediately = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveImmediately;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSimulatedTimeOfDay constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSimulatedTimeOfDay Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NewTimeOfDayHours = { "NewTimeOfDayHours", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventSetSimulatedTimeOfDay_Parms, NewTimeOfDayHours), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NewDayIndex = { "NewDayIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDayNightSky_eventSetSimulatedTimeOfDay_Parms, NewDayIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSaveImmediately = { "bSaveImmediately", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDayNightSky_eventSetSimulatedTimeOfDay_Parms), &UHT_STATICS::NewProp_bSaveImmediately_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTimeOfDayHours,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewDayIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSaveImmediately,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetSimulatedTimeOfDay Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDayNightSky, nullptr, "SetSimulatedTimeOfDay", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDayNightSky_eventSetSimulatedTimeOfDay_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDayNightSky_eventSetSimulatedTimeOfDay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDayNightSky_SetSimulatedTimeOfDay(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDayNightSky::execSetSimulatedTimeOfDay)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewTimeOfDayHours);
	P_GET_PROPERTY(FIntProperty,Z_Param_NewDayIndex);
	P_GET_UBOOL(Z_Param_bSaveImmediately);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSimulatedTimeOfDay(Z_Param_NewTimeOfDayHours,Z_Param_NewDayIndex,Z_Param_bSaveImmediately);
	P_NATIVE_END;
}
// ********** End Class ADMFDayNightSky Function SetSimulatedTimeOfDay *****************************

// ********** Begin Class ADMFDayNightSky **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFDayNightSky_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Replicated, persistent, Blueprint-derivable MMO world clock and sky presentation actor.\n *\n * Authority owns the clock. Clients receive sparse time anchors and interpolate locally for smooth sky motion;\n * no per-frame time RPCs are used. HostSystemTime reads only the authority machine's local PC clock, while\n * Simulated mode advances an accelerated persistent game clock. The native visual components are optional:\n * projects may use them directly or derive a Blueprint and drive their own sky from the exposed runtime values/events.\n */" },
#endif
		{ "IncludePath", "Game/DMFDayNightSky.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated, persistent, Blueprint-derivable MMO world clock and sky presentation actor.\n\nAuthority owns the clock. Clients receive sparse time anchors and interpolate locally for smooth sky motion;\nno per-frame time RPCs are used. HostSystemTime reads only the authority machine's local PC clock, while\nSimulated mode advances an accelerated persistent game clock. The native visual components are optional:\nprojects may use them directly or derive a Blueprint and drive their own sky from the exposed runtime values/events." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SunLightComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional native sun. Derived Blueprints may hide/replace this and use the replicated time values instead. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional native sun. Derived Blueprints may hide/replace this and use the replicated time values instead." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonLightComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional native moon light kept exactly opposite the sun. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional native moon light kept exactly opposite the sun." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyLightComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional native skylight. Expensive recapture is intentionally not performed every update. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional native skylight. Expensive recapture is intentionally not performed every update." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyAtmosphereComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional native SkyAtmosphere component. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional native SkyAtmosphere component." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyDomeComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional project-supplied outer sky dome mesh/material. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional project-supplied outer sky dome mesh/material." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerSkyLayerComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Dedicated always-visible inner digital texture layer. Use a translucent/unlit two-sided material whose\n     * texture parameter consumes alpha; the layer stays enabled during both Day and Night so the real sky remains\n     * visible behind transparent texels.\n     */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dedicated always-visible inner digital texture layer. Use a translucent/unlit two-sided material whose\ntexture parameter consumes alpha; the layer stays enabled during both Day and Night so the real sky remains\nvisible behind transparent texels." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeSource_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Time" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---- Time source / clock ---------------------------------------------------------------\n" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---- Time source / clock ---------------------------------------------------------------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialSimulatedTimeHours_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Time" },
		{ "ClampMax", "23.999" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Initial simulated time only when no saved state exists. */" },
#endif
		{ "EditCondition", "TimeSource==EDMFDayNightTimeSource::Simulated" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initial simulated time only when no saved state exists." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimulatedDayLengthSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Time" },
		{ "ClampMin", "10.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Real seconds required for one complete simulated 24-hour day. 2880 seconds = a 48-minute GTA-style day. */" },
#endif
		{ "EditCondition", "TimeSource==EDMFDayNightTimeSource::Simulated" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Real seconds required for one complete simulated 24-hour day. 2880 seconds = a 48-minute GTA-style day." },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DayStartHour_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Phase" },
		{ "ClampMax", "23.999" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Inclusive start of Day. Supports wrap-around schedules when DayStartHour > NightStartHour. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inclusive start of Day. Supports wrap-around schedules when DayStartHour > NightStartHour." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NightStartHour_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Phase" },
		{ "ClampMax", "23.999" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Exclusive end of Day / start of Night. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exclusive end of Day / start of Night." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeReplicationIntervalSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Networking" },
		{ "ClampMax", "30.0" },
		{ "ClampMin", "0.25" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sparse authoritative time-anchor replication interval. Clients interpolate smoothly between anchors. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sparse authoritative time-anchor replication interval. Clients interpolate smoothly between anchors." },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualUpdateIntervalSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Performance" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.016" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local-only sky presentation update interval. 0.05 = 20 Hz and is normally more than enough for slow celestial motion. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local-only sky presentation update interval. 0.05 = 20 Hz and is normally more than enough for slow celestial motion." },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreviewSkyInEditor_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Editor Preview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Updates the native sky presentation while editing the map/Blueprint, without requiring PIE.\n     * Simulated mode previews InitialSimulatedTimeHours; Host PC mode previews the editor machine's local clock.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates the native sky presentation while editing the map/Blueprint, without requiring PIE.\nSimulated mode previews InitialSimulatedTimeHours; Host PC mode previews the editor machine's local clock." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PersistenceId_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stable identifier combined with the gameplay map name in the server world-state save. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stable identifier combined with the gameplay map name in the server world-state save." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSaveAndLoadSimulatedTime_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Simulated time resumes from its server-saved clock after restart/map reload. Host PC time always follows the authority PC clock. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simulated time resumes from its server-saved clock after restart/map reload. Host PC time always follows the authority PC clock." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PersistenceAutosaveIntervalSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Persistence" },
		{ "ClampMin", "5.0" },
		{ "EditCondition", "bSaveAndLoadSimulatedTime" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableNativeSkyAtmosphere_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Disable when a derived Blueprint/project supplies its own SkyAtmosphere component. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Disable when a derived Blueprint/project supplies its own SkyAtmosphere component." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableNativeSkyLight_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Disable when a project supplies its own skylight/capture solution. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Disable when a project supplies its own skylight/capture solution." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRecaptureNativeSkyLightOnPhaseChange_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Recaptures the optional native SkyLight only when Day/Night phase changes (plus editor preview refresh), never every visual tick. */" },
#endif
		{ "EditCondition", "bEnableNativeSkyLight" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Recaptures the optional native SkyLight only when Day/Night phase changes (plus editor preview refresh), never every visual tick." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDriveNativeDirectionalLights_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SunYawDegrees_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
		{ "EditCondition", "bDriveNativeDirectionalLights" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SunPitchOffsetDegrees_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
		{ "EditCondition", "bDriveNativeDirectionalLights" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumSunIntensity_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bDriveNativeDirectionalLights" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumMoonIntensity_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bDriveNativeDirectionalLights" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SunLightColor_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
		{ "EditCondition", "bDriveNativeDirectionalLights" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonLightColor_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Lighting" },
		{ "EditCondition", "bDriveNativeDirectionalLights" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyDomeMesh_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Sky Dome" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---- Sky dome / digital inner layer --------------------------------------------------\n" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---- Sky dome / digital inner layer --------------------------------------------------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyDomeMaterial_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Sky Dome" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyDomeScale_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Sky Dome" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale for a conventional engine sphere. Projects using a pre-scaled sky mesh may set this to 1. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale for a conventional engine sphere. Projects using a pre-scaled sky mesh may set this to 1." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDigitalInnerLayer_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master gate for the persistent alpha-blended digital layer. It never toggles just because Day/Night changes. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master gate for the persistent alpha-blended digital layer. It never toggles just because Day/Night changes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerMesh_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional dedicated mesh. When unset, SkyDomeMesh is reused. */" },
#endif
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional dedicated mesh. When unset, SkyDomeMesh is reused." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerMaterial_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Translucent/unlit two-sided material recommended. Texture alpha should feed material Opacity. */" },
#endif
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Translucent/unlit two-sided material recommended. Texture alpha should feed material Opacity." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerTexture_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Digital texture supplied to DigitalInnerLayerTextureParameterName at runtime. Alpha remains authored by the texture/material. */" },
#endif
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Digital texture supplied to DigitalInnerLayerTextureParameterName at runtime. Alpha remains authored by the texture/material." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerOpacity_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerTint_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer" },
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerUVScale_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer" },
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerPanSpeed_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UV units per real second. Zero leaves the texture fixed. */" },
#endif
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UV units per real second. Zero leaves the texture fixed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerScaleMultiplier_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.01" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Slightly smaller than the outer dome to avoid z-fighting and place this texture visually in front of it from inside the sphere. */" },
#endif
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Slightly smaller than the outer dome to avoid z-fighting and place this texture visually in front of it from inside the sphere." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerTextureParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer|Material Parameters" },
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerOpacityParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer|Material Parameters" },
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerTintParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer|Material Parameters" },
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerUVScaleParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer|Material Parameters" },
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerUVOffsetParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Digital Inner Layer|Material Parameters" },
		{ "EditCondition", "bEnableDigitalInnerLayer" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeOfDayNormalizedParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Sky Dome|Material Parameters" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shared optional material parameter names pushed to outer and inner dynamic materials. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shared optional material parameter names pushed to outer and inner dynamic materials." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DayVisualAlphaParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Sky Dome|Material Parameters" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SunDirectionParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Sky Dome|Material Parameters" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDriveSkyDomeSolarVisualParameters_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Sky Dome|Solar Visual Compatibility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Compatibility bridge for conventional Unreal sky-sphere materials whose visible solar disc is authored\n     * from legacy Light direction / Sun height parameters instead of the framework DMF_* contract. Keeping this\n     * enabled makes the painted/material sun follow the exact same solar path as the native Directional Light.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compatibility bridge for conventional Unreal sky-sphere materials whose visible solar disc is authored\nfrom legacy Light direction / Sun height parameters instead of the framework DMF_* contract. Keeping this\nenabled makes the painted/material sun follow the exact same solar path as the native Directional Light." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyDomeLightDirectionParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Sky Dome|Solar Visual Compatibility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Vector parameter used by many Unreal sky-sphere materials for the visible solar-disc direction. The value\n     * supplied is the Directional Light ray-travel/forward vector (sun -> world), matching the conventional sky-sphere contract.\n     * Set to None when the assigned material does not use this compatibility parameter.\n     */" },
#endif
		{ "EditCondition", "bDriveSkyDomeSolarVisualParameters" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Vector parameter used by many Unreal sky-sphere materials for the visible solar-disc direction. The value\nsupplied is the Directional Light ray-travel/forward vector (sun -> world), matching the conventional sky-sphere contract.\nSet to None when the assigned material does not use this compatibility parameter." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyDomeSunHeightParameterName_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Sky Dome|Solar Visual Compatibility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Scalar parameter used by many Unreal sky-sphere materials for solar elevation. -1 = below at midnight,\n     * 0 = horizon, +1 = overhead at noon. Set to None when the assigned material does not use this parameter.\n     */" },
#endif
		{ "EditCondition", "bDriveSkyDomeSolarVisualParameters" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scalar parameter used by many Unreal sky-sphere materials for solar elevation. -1 = below at midnight,\n0 = horizon, +1 = overhead at noon. Set to None when the assigned material does not use this parameter." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedTimeOfDayHours_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Last server-authored time anchor. Use GetTimeOfDayHours for smooth interpolated time between network anchors. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Last server-authored time anchor. Use GetTimeOfDayHours for smooth interpolated time between network anchors." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedDayIndex_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Runtime" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedTimeSource_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Runtime" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedTimeAnchorServerSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server-world-time timestamp paired with ReplicatedTimeOfDayHours. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-world-time timestamp paired with ReplicatedTimeOfDayHours." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedSimulatedDayLengthSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replicated so a runtime server-side simulated-day-length change still interpolates correctly on clients. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated so a runtime server-side simulated-day-length change still interpolates correctly on clients." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DayNightPhase_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Runtime" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsDay_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Convenience values derived from replicated DayNightPhase and exposed directly for Blueprint branching/binding. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convenience values derived from replicated DayNightPhase and exposed directly for Blueprint branching/binding." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsNight_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Runtime" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDayNightPhaseChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTimeSynchronized_MetaData[] = {
		{ "Category", "Digimon MMO|Day Night|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkyDomeMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigitalInnerLayerMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDayNightSky.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFDayNightSky constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SunLightComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoonLightComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkyLightComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkyAtmosphereComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkyDomeComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigitalInnerSkyLayerComponent;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TimeSource_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TimeSource;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InitialSimulatedTimeHours;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SimulatedDayLengthSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DayStartHour;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NightStartHour;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeReplicationIntervalSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VisualUpdateIntervalSeconds;
	static void NewProp_bPreviewSkyInEditor_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bPreviewSkyInEditor = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreviewSkyInEditor;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PersistenceId;
	static void NewProp_bSaveAndLoadSimulatedTime_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bSaveAndLoadSimulatedTime = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveAndLoadSimulatedTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PersistenceAutosaveIntervalSeconds;
	static void NewProp_bEnableNativeSkyAtmosphere_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bEnableNativeSkyAtmosphere = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableNativeSkyAtmosphere;
	static void NewProp_bEnableNativeSkyLight_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bEnableNativeSkyLight = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableNativeSkyLight;
	static void NewProp_bRecaptureNativeSkyLightOnPhaseChange_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bRecaptureNativeSkyLightOnPhaseChange = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRecaptureNativeSkyLightOnPhaseChange;
	static void NewProp_bDriveNativeDirectionalLights_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bDriveNativeDirectionalLights = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDriveNativeDirectionalLights;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SunYawDegrees;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SunPitchOffsetDegrees;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumSunIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumMoonIntensity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SunLightColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MoonLightColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkyDomeMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkyDomeMaterial;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkyDomeScale;
	static void NewProp_bEnableDigitalInnerLayer_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bEnableDigitalInnerLayer = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDigitalInnerLayer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigitalInnerLayerMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigitalInnerLayerMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigitalInnerLayerTexture;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DigitalInnerLayerOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigitalInnerLayerTint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigitalInnerLayerUVScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigitalInnerLayerPanSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DigitalInnerLayerScaleMultiplier;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DigitalInnerLayerTextureParameterName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DigitalInnerLayerOpacityParameterName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DigitalInnerLayerTintParameterName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DigitalInnerLayerUVScaleParameterName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DigitalInnerLayerUVOffsetParameterName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_TimeOfDayNormalizedParameterName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DayVisualAlphaParameterName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SunDirectionParameterName;
	static void NewProp_bDriveSkyDomeSolarVisualParameters_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bDriveSkyDomeSolarVisualParameters = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDriveSkyDomeSolarVisualParameters;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SkyDomeLightDirectionParameterName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SkyDomeSunHeightParameterName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReplicatedTimeOfDayHours;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReplicatedDayIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReplicatedTimeSource_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReplicatedTimeSource;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ReplicatedTimeAnchorServerSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReplicatedSimulatedDayLengthSeconds;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DayNightPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DayNightPhase;
	static void NewProp_bIsDay_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bIsDay = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsDay;
	static void NewProp_bIsNight_SetBit(void* Obj)
	{
		((ADMFDayNightSky*)Obj)->bIsNight = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsNight;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDayNightPhaseChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTimeSynchronized;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkyDomeMID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigitalInnerLayerMID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFDayNightSky constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AdvanceSimulatedTimeByHours"), .Pointer = &ADMFDayNightSky::execAdvanceSimulatedTimeByHours },
		{ .NameUTF8 = UTF8TEXT("GetCurrentDayIndex"), .Pointer = &ADMFDayNightSky::execGetCurrentDayIndex },
		{ .NameUTF8 = UTF8TEXT("GetDayNightPhase"), .Pointer = &ADMFDayNightSky::execGetDayNightPhase },
		{ .NameUTF8 = UTF8TEXT("GetFormattedTime12Hour"), .Pointer = &ADMFDayNightSky::execGetFormattedTime12Hour },
		{ .NameUTF8 = UTF8TEXT("GetTimeOfDayHours"), .Pointer = &ADMFDayNightSky::execGetTimeOfDayHours },
		{ .NameUTF8 = UTF8TEXT("GetTimeOfDayNormalized"), .Pointer = &ADMFDayNightSky::execGetTimeOfDayNormalized },
		{ .NameUTF8 = UTF8TEXT("IsDay"), .Pointer = &ADMFDayNightSky::execIsDay },
		{ .NameUTF8 = UTF8TEXT("IsNight"), .Pointer = &ADMFDayNightSky::execIsNight },
		{ .NameUTF8 = UTF8TEXT("OnRep_DayNightPhase"), .Pointer = &ADMFDayNightSky::execOnRep_DayNightPhase },
		{ .NameUTF8 = UTF8TEXT("OnRep_TimeAnchor"), .Pointer = &ADMFDayNightSky::execOnRep_TimeAnchor },
		{ .NameUTF8 = UTF8TEXT("RefreshSkyPresentation"), .Pointer = &ADMFDayNightSky::execRefreshSkyPresentation },
		{ .NameUTF8 = UTF8TEXT("ReloadDayNightState"), .Pointer = &ADMFDayNightSky::execReloadDayNightState },
		{ .NameUTF8 = UTF8TEXT("SaveDayNightStateNow"), .Pointer = &ADMFDayNightSky::execSaveDayNightStateNow },
		{ .NameUTF8 = UTF8TEXT("SetAuthoritativeTimeSource"), .Pointer = &ADMFDayNightSky::execSetAuthoritativeTimeSource },
		{ .NameUTF8 = UTF8TEXT("SetSimulatedTimeOfDay"), .Pointer = &ADMFDayNightSky::execSetSimulatedTimeOfDay },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFDayNightSky_AdvanceSimulatedTimeByHours, "AdvanceSimulatedTimeByHours" }, // 6cd4d23c52cfe16b406e21ceb3704f68c750786c
		{ &Z_Construct_UFunction_ADMFDayNightSky_BP_OnDayNightPhaseChanged, "BP_OnDayNightPhaseChanged" }, // 528d516677316884242270c86a50f27ec8f7b92e
		{ &Z_Construct_UFunction_ADMFDayNightSky_BP_OnSkyVisualUpdate, "BP_OnSkyVisualUpdate" }, // 777e1d7901d448f8ba4c58c2119c6520cb99644b
		{ &Z_Construct_UFunction_ADMFDayNightSky_GetCurrentDayIndex, "GetCurrentDayIndex" }, // 4a2a0eb32b49aa524914eed57872938f6ac6c5c8
		{ &Z_Construct_UFunction_ADMFDayNightSky_GetDayNightPhase, "GetDayNightPhase" }, // 49064fb138f389eec8e3c20fa725a451beb3c377
		{ &Z_Construct_UFunction_ADMFDayNightSky_GetFormattedTime12Hour, "GetFormattedTime12Hour" }, // 058549b922e18bfb1310f23858f24fd5f1b2078c
		{ &Z_Construct_UFunction_ADMFDayNightSky_GetTimeOfDayHours, "GetTimeOfDayHours" }, // de9c467b29f2fa9794a3d4253749af1409a6d47a
		{ &Z_Construct_UFunction_ADMFDayNightSky_GetTimeOfDayNormalized, "GetTimeOfDayNormalized" }, // ca8d234644d7e6d17c3205a485b615b315e76733
		{ &Z_Construct_UFunction_ADMFDayNightSky_IsDay, "IsDay" }, // 681034c398fab31b87f410359c85477fc92ebcd0
		{ &Z_Construct_UFunction_ADMFDayNightSky_IsNight, "IsNight" }, // ecd615620ece91f13012794805d63565860d3488
		{ &Z_Construct_UFunction_ADMFDayNightSky_OnRep_DayNightPhase, "OnRep_DayNightPhase" }, // 3fc26986fd7d2403daa776493c7e1e875244701b
		{ &Z_Construct_UFunction_ADMFDayNightSky_OnRep_TimeAnchor, "OnRep_TimeAnchor" }, // a1bb68b617dd6900484f453716b152d58450e7e0
		{ &Z_Construct_UFunction_ADMFDayNightSky_RefreshSkyPresentation, "RefreshSkyPresentation" }, // 43d9200dad7d69d1ba3c01e58fe709574867f114
		{ &Z_Construct_UFunction_ADMFDayNightSky_ReloadDayNightState, "ReloadDayNightState" }, // 29f9539fa71e0d96760b205633d5bed463b6b950
		{ &Z_Construct_UFunction_ADMFDayNightSky_SaveDayNightStateNow, "SaveDayNightStateNow" }, // 0e5eec18ce65022a6b1a55ac770e19bcb9cb0a56
		{ &Z_Construct_UFunction_ADMFDayNightSky_SetAuthoritativeTimeSource, "SetAuthoritativeTimeSource" }, // 024708ec2c425de77727f91a3f5b18518b1dbeb7
		{ &Z_Construct_UFunction_ADMFDayNightSky_SetSimulatedTimeOfDay, "SetSimulatedTimeOfDay" }, // c10f10943737fc6d455534a667356b98df90e5aa
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFDayNightSky>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFDayNightSky Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SceneRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SunLightComponent = { "SunLightComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SunLightComponent), Z_Construct_UClass_UDirectionalLightComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SunLightComponent_MetaData), NewProp_SunLightComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MoonLightComponent = { "MoonLightComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, MoonLightComponent), Z_Construct_UClass_UDirectionalLightComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonLightComponent_MetaData), NewProp_MoonLightComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkyLightComponent = { "SkyLightComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SkyLightComponent), Z_Construct_UClass_USkyLightComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyLightComponent_MetaData), NewProp_SkyLightComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkyAtmosphereComponent = { "SkyAtmosphereComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SkyAtmosphereComponent), Z_Construct_UClass_USkyAtmosphereComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyAtmosphereComponent_MetaData), NewProp_SkyAtmosphereComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkyDomeComponent = { "SkyDomeComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SkyDomeComponent), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyDomeComponent_MetaData), NewProp_SkyDomeComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigitalInnerSkyLayerComponent = { "DigitalInnerSkyLayerComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerSkyLayerComponent), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerSkyLayerComponent_MetaData), NewProp_DigitalInnerSkyLayerComponent_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TimeSource_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TimeSource = { "TimeSource", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, TimeSource), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightTimeSource, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeSource_MetaData), NewProp_TimeSource_MetaData) }; // 9a11f543f9779874be680cad288a70fc2e0ef3a7
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InitialSimulatedTimeHours = { "InitialSimulatedTimeHours", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, InitialSimulatedTimeHours), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialSimulatedTimeHours_MetaData), NewProp_InitialSimulatedTimeHours_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SimulatedDayLengthSeconds = { "SimulatedDayLengthSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SimulatedDayLengthSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimulatedDayLengthSeconds_MetaData), NewProp_SimulatedDayLengthSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DayStartHour = { "DayStartHour", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DayStartHour), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DayStartHour_MetaData), NewProp_DayStartHour_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NightStartHour = { "NightStartHour", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, NightStartHour), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NightStartHour_MetaData), NewProp_NightStartHour_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TimeReplicationIntervalSeconds = { "TimeReplicationIntervalSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, TimeReplicationIntervalSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeReplicationIntervalSeconds_MetaData), NewProp_TimeReplicationIntervalSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_VisualUpdateIntervalSeconds = { "VisualUpdateIntervalSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, VisualUpdateIntervalSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualUpdateIntervalSeconds_MetaData), NewProp_VisualUpdateIntervalSeconds_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPreviewSkyInEditor = { "bPreviewSkyInEditor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bPreviewSkyInEditor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreviewSkyInEditor_MetaData), NewProp_bPreviewSkyInEditor_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_PersistenceId = { "PersistenceId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, PersistenceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PersistenceId_MetaData), NewProp_PersistenceId_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSaveAndLoadSimulatedTime = { "bSaveAndLoadSimulatedTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bSaveAndLoadSimulatedTime_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSaveAndLoadSimulatedTime_MetaData), NewProp_bSaveAndLoadSimulatedTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PersistenceAutosaveIntervalSeconds = { "PersistenceAutosaveIntervalSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, PersistenceAutosaveIntervalSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PersistenceAutosaveIntervalSeconds_MetaData), NewProp_PersistenceAutosaveIntervalSeconds_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableNativeSkyAtmosphere = { "bEnableNativeSkyAtmosphere", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bEnableNativeSkyAtmosphere_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableNativeSkyAtmosphere_MetaData), NewProp_bEnableNativeSkyAtmosphere_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableNativeSkyLight = { "bEnableNativeSkyLight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bEnableNativeSkyLight_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableNativeSkyLight_MetaData), NewProp_bEnableNativeSkyLight_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRecaptureNativeSkyLightOnPhaseChange = { "bRecaptureNativeSkyLightOnPhaseChange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bRecaptureNativeSkyLightOnPhaseChange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRecaptureNativeSkyLightOnPhaseChange_MetaData), NewProp_bRecaptureNativeSkyLightOnPhaseChange_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDriveNativeDirectionalLights = { "bDriveNativeDirectionalLights", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bDriveNativeDirectionalLights_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDriveNativeDirectionalLights_MetaData), NewProp_bDriveNativeDirectionalLights_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SunYawDegrees = { "SunYawDegrees", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SunYawDegrees), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SunYawDegrees_MetaData), NewProp_SunYawDegrees_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SunPitchOffsetDegrees = { "SunPitchOffsetDegrees", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SunPitchOffsetDegrees), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SunPitchOffsetDegrees_MetaData), NewProp_SunPitchOffsetDegrees_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumSunIntensity = { "MaximumSunIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, MaximumSunIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumSunIntensity_MetaData), NewProp_MaximumSunIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumMoonIntensity = { "MaximumMoonIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, MaximumMoonIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumMoonIntensity_MetaData), NewProp_MaximumMoonIntensity_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SunLightColor = { "SunLightColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SunLightColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SunLightColor_MetaData), NewProp_SunLightColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_MoonLightColor = { "MoonLightColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, MoonLightColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonLightColor_MetaData), NewProp_MoonLightColor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkyDomeMesh = { "SkyDomeMesh", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SkyDomeMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyDomeMesh_MetaData), NewProp_SkyDomeMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkyDomeMaterial = { "SkyDomeMaterial", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SkyDomeMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyDomeMaterial_MetaData), NewProp_SkyDomeMaterial_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkyDomeScale = { "SkyDomeScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SkyDomeScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyDomeScale_MetaData), NewProp_SkyDomeScale_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDigitalInnerLayer = { "bEnableDigitalInnerLayer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bEnableDigitalInnerLayer_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDigitalInnerLayer_MetaData), NewProp_bEnableDigitalInnerLayer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigitalInnerLayerMesh = { "DigitalInnerLayerMesh", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerMesh_MetaData), NewProp_DigitalInnerLayerMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigitalInnerLayerMaterial = { "DigitalInnerLayerMaterial", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerMaterial_MetaData), NewProp_DigitalInnerLayerMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigitalInnerLayerTexture = { "DigitalInnerLayerTexture", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerTexture), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerTexture_MetaData), NewProp_DigitalInnerLayerTexture_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DigitalInnerLayerOpacity = { "DigitalInnerLayerOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerOpacity_MetaData), NewProp_DigitalInnerLayerOpacity_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigitalInnerLayerTint = { "DigitalInnerLayerTint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerTint), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerTint_MetaData), NewProp_DigitalInnerLayerTint_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigitalInnerLayerUVScale = { "DigitalInnerLayerUVScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerUVScale), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerUVScale_MetaData), NewProp_DigitalInnerLayerUVScale_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigitalInnerLayerPanSpeed = { "DigitalInnerLayerPanSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerPanSpeed), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerPanSpeed_MetaData), NewProp_DigitalInnerLayerPanSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DigitalInnerLayerScaleMultiplier = { "DigitalInnerLayerScaleMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerScaleMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerScaleMultiplier_MetaData), NewProp_DigitalInnerLayerScaleMultiplier_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_DigitalInnerLayerTextureParameterName = { "DigitalInnerLayerTextureParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerTextureParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerTextureParameterName_MetaData), NewProp_DigitalInnerLayerTextureParameterName_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_DigitalInnerLayerOpacityParameterName = { "DigitalInnerLayerOpacityParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerOpacityParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerOpacityParameterName_MetaData), NewProp_DigitalInnerLayerOpacityParameterName_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_DigitalInnerLayerTintParameterName = { "DigitalInnerLayerTintParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerTintParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerTintParameterName_MetaData), NewProp_DigitalInnerLayerTintParameterName_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_DigitalInnerLayerUVScaleParameterName = { "DigitalInnerLayerUVScaleParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerUVScaleParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerUVScaleParameterName_MetaData), NewProp_DigitalInnerLayerUVScaleParameterName_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_DigitalInnerLayerUVOffsetParameterName = { "DigitalInnerLayerUVOffsetParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerUVOffsetParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerUVOffsetParameterName_MetaData), NewProp_DigitalInnerLayerUVOffsetParameterName_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_TimeOfDayNormalizedParameterName = { "TimeOfDayNormalizedParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, TimeOfDayNormalizedParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeOfDayNormalizedParameterName_MetaData), NewProp_TimeOfDayNormalizedParameterName_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_DayVisualAlphaParameterName = { "DayVisualAlphaParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DayVisualAlphaParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DayVisualAlphaParameterName_MetaData), NewProp_DayVisualAlphaParameterName_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_SunDirectionParameterName = { "SunDirectionParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SunDirectionParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SunDirectionParameterName_MetaData), NewProp_SunDirectionParameterName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDriveSkyDomeSolarVisualParameters = { "bDriveSkyDomeSolarVisualParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bDriveSkyDomeSolarVisualParameters_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDriveSkyDomeSolarVisualParameters_MetaData), NewProp_bDriveSkyDomeSolarVisualParameters_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_SkyDomeLightDirectionParameterName = { "SkyDomeLightDirectionParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SkyDomeLightDirectionParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyDomeLightDirectionParameterName_MetaData), NewProp_SkyDomeLightDirectionParameterName_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_SkyDomeSunHeightParameterName = { "SkyDomeSunHeightParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SkyDomeSunHeightParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyDomeSunHeightParameterName_MetaData), NewProp_SkyDomeSunHeightParameterName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReplicatedTimeOfDayHours = { "ReplicatedTimeOfDayHours", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, ReplicatedTimeOfDayHours), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedTimeOfDayHours_MetaData), NewProp_ReplicatedTimeOfDayHours_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReplicatedDayIndex = { "ReplicatedDayIndex", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, ReplicatedDayIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedDayIndex_MetaData), NewProp_ReplicatedDayIndex_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReplicatedTimeSource_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReplicatedTimeSource = { "ReplicatedTimeSource", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, ReplicatedTimeSource), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightTimeSource, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedTimeSource_MetaData), NewProp_ReplicatedTimeSource_MetaData) }; // 9a11f543f9779874be680cad288a70fc2e0ef3a7
const UECodeGen_Private::FDoublePropertyParams UHT_STATICS::NewProp_ReplicatedTimeAnchorServerSeconds = { "ReplicatedTimeAnchorServerSeconds", "OnRep_TimeAnchor", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Double, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, ReplicatedTimeAnchorServerSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedTimeAnchorServerSeconds_MetaData), NewProp_ReplicatedTimeAnchorServerSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReplicatedSimulatedDayLengthSeconds = { "ReplicatedSimulatedDayLengthSeconds", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, ReplicatedSimulatedDayLengthSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedSimulatedDayLengthSeconds_MetaData), NewProp_ReplicatedSimulatedDayLengthSeconds_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_DayNightPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_DayNightPhase = { "DayNightPhase", "OnRep_DayNightPhase", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DayNightPhase), Z_Construct_UEnum_DigimonMMOFramework_EDMFDayNightPhase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DayNightPhase_MetaData), NewProp_DayNightPhase_MetaData) }; // 78bba6eb7608900637e4f59c3fc53f23bdfcfc40
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsDay = { "bIsDay", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bIsDay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsDay_MetaData), NewProp_bIsDay_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsNight = { "bIsNight", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDayNightSky), &UHT_STATICS::NewProp_bIsNight_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsNight_MetaData), NewProp_bIsNight_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnDayNightPhaseChanged = { "OnDayNightPhaseChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, OnDayNightPhaseChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDayNightPhaseChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDayNightPhaseChanged_MetaData), NewProp_OnDayNightPhaseChanged_MetaData) }; // 7066bc32b0aaef965b541aa8cf15353915fffdac
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnTimeSynchronized = { "OnTimeSynchronized", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, OnTimeSynchronized), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDayNightTimeSynchronized__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTimeSynchronized_MetaData), NewProp_OnTimeSynchronized_MetaData) }; // 9599a212fab9248ebffcfec255f68199b691ee6f
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkyDomeMID = { "SkyDomeMID", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, SkyDomeMID), Z_Construct_UClass_UMaterialInstanceDynamic, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkyDomeMID_MetaData), NewProp_SkyDomeMID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigitalInnerLayerMID = { "DigitalInnerLayerMID", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDayNightSky, DigitalInnerLayerMID), Z_Construct_UClass_UMaterialInstanceDynamic, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigitalInnerLayerMID_MetaData), NewProp_DigitalInnerLayerMID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SunLightComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MoonLightComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyLightComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyAtmosphereComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyDomeComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerSkyLayerComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeSource_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeSource,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InitialSimulatedTimeHours,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SimulatedDayLengthSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DayStartHour,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NightStartHour,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeReplicationIntervalSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VisualUpdateIntervalSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPreviewSkyInEditor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PersistenceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSaveAndLoadSimulatedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PersistenceAutosaveIntervalSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableNativeSkyAtmosphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableNativeSkyLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRecaptureNativeSkyLightOnPhaseChange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDriveNativeDirectionalLights,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SunYawDegrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SunPitchOffsetDegrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumSunIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumMoonIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SunLightColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MoonLightColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyDomeMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyDomeMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyDomeScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDigitalInnerLayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerTint,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerUVScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerPanSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerScaleMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerTextureParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerOpacityParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerTintParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerUVScaleParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerUVOffsetParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeOfDayNormalizedParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DayVisualAlphaParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SunDirectionParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDriveSkyDomeSolarVisualParameters,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyDomeLightDirectionParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyDomeSunHeightParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedTimeOfDayHours,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedDayIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedTimeSource_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedTimeSource,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedTimeAnchorServerSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedSimulatedDayLengthSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DayNightPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DayNightPhase,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsDay,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsNight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnDayNightPhaseChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnTimeSynchronized,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkyDomeMID,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigitalInnerLayerMID,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFDayNightSky Property Definitions ***************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFDayNightSky,
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
static void ADMFDayNightSky_StaticRegisterNativesADMFDayNightSky()
{
	UClass* Class = ADMFDayNightSky::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFDayNightSky;
UClass* Z_Construct_UClass_ADMFDayNightSky(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFDayNightSky;
		if (!Z_Registration_Info_UClass_ADMFDayNightSky.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDayNightSky"),
				Z_Registration_Info_UClass_ADMFDayNightSky.InnerSingleton,
				ADMFDayNightSky_StaticRegisterNativesADMFDayNightSky,
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
		return Z_Registration_Info_UClass_ADMFDayNightSky.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFDayNightSky.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFDayNightSky.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFDayNightSky.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFDayNightSky::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_ReplicatedTimeOfDayHours(TEXT("ReplicatedTimeOfDayHours"));
	static FName Name_ReplicatedDayIndex(TEXT("ReplicatedDayIndex"));
	static FName Name_ReplicatedTimeSource(TEXT("ReplicatedTimeSource"));
	static FName Name_ReplicatedTimeAnchorServerSeconds(TEXT("ReplicatedTimeAnchorServerSeconds"));
	static FName Name_ReplicatedSimulatedDayLengthSeconds(TEXT("ReplicatedSimulatedDayLengthSeconds"));
	static FName Name_DayNightPhase(TEXT("DayNightPhase"));
	const bool bIsValid = true
		&& Name_ReplicatedTimeOfDayHours == ClassReps[(int32)ENetFields_Private::ReplicatedTimeOfDayHours].Property->GetFName()
		&& Name_ReplicatedDayIndex == ClassReps[(int32)ENetFields_Private::ReplicatedDayIndex].Property->GetFName()
		&& Name_ReplicatedTimeSource == ClassReps[(int32)ENetFields_Private::ReplicatedTimeSource].Property->GetFName()
		&& Name_ReplicatedTimeAnchorServerSeconds == ClassReps[(int32)ENetFields_Private::ReplicatedTimeAnchorServerSeconds].Property->GetFName()
		&& Name_ReplicatedSimulatedDayLengthSeconds == ClassReps[(int32)ENetFields_Private::ReplicatedSimulatedDayLengthSeconds].Property->GetFName()
		&& Name_DayNightPhase == ClassReps[(int32)ENetFields_Private::DayNightPhase].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFDayNightSky"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFDayNightSky);
ADMFDayNightSky::~ADMFDayNightSky() {}
// ********** End Class ADMFDayNightSky ************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFDayNightSky, TEXT("ADMFDayNightSky"), &Z_Registration_Info_UClass_ADMFDayNightSky, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFDayNightSky), 1040839707U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDayNightSky_h__Script_DigimonMMOFramework_b2a568f50a089a4a9f1e373d49d6d870c3c561ae{
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
