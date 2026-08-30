// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Engine/HitResult.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFPlayerAvatarCharacter() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_ACharacter(ETypeConstructPhase);
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel(ETypeConstructPhase);
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UExponentialHeightFogComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UPostProcessComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USoundBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UWidgetComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFLocalCameraUnderwaterChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerInteractionResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSwimmingStateChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerUnderwaterStateChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerInteractionType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerSwimState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFSwimmableWater(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFPlayerInteractionResult *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerInteractionResult__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFPlayerInteractionResult_Parms
	{
		bool bSuccess;
		AActor* TargetActor;
		EDMFPlayerInteractionType InteractionType;
		FText Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFPlayerInteractionResult constinit property declarations ***********
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFPlayerInteractionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InteractionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InteractionType;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFPlayerInteractionResult constinit property declarations *************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFPlayerInteractionResult Property Definitions **********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFPlayerInteractionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFPlayerInteractionResult_Parms, TargetActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InteractionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InteractionType = { "InteractionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFPlayerInteractionResult_Parms, InteractionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerInteractionType, METADATA_PARAMS(0, nullptr) }; // be35e38c06806ec55a48f2c67527ce3cb1a0c51e
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFPlayerInteractionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFPlayerInteractionResult Property Definitions ************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFPlayerInteractionResult__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerInteractionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerInteractionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerInteractionResult__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFPlayerInteractionResult *********************************************

// ********** Begin Delegate FDMFPlayerSwimmingStateChanged ****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSwimmingStateChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFPlayerSwimmingStateChanged_Parms
	{
		bool bSwimming;
		bool bUnderwater;
		ADMFSwimmableWater* WaterBody;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFPlayerSwimmingStateChanged constinit property declarations ********
	static void NewProp_bSwimming_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFPlayerSwimmingStateChanged_Parms*)Obj)->bSwimming = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSwimming;
	static void NewProp_bUnderwater_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFPlayerSwimmingStateChanged_Parms*)Obj)->bUnderwater = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUnderwater;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaterBody;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFPlayerSwimmingStateChanged constinit property declarations **********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFPlayerSwimmingStateChanged Property Definitions *******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSwimming = { "bSwimming", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFPlayerSwimmingStateChanged_Parms), &UHT_STATICS::NewProp_bSwimming_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUnderwater = { "bUnderwater", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFPlayerSwimmingStateChanged_Parms), &UHT_STATICS::NewProp_bUnderwater_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WaterBody = { "WaterBody", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFPlayerSwimmingStateChanged_Parms, WaterBody), Z_Construct_UClass_ADMFSwimmableWater, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSwimming,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUnderwater,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterBody,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFPlayerSwimmingStateChanged Property Definitions *********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFPlayerSwimmingStateChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSwimmingStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSwimmingStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSwimmingStateChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFPlayerSwimmingStateChanged ******************************************

// ********** Begin Delegate FDMFPlayerUnderwaterStateChanged **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerUnderwaterStateChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFPlayerUnderwaterStateChanged_Parms
	{
		bool bUnderwater;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFPlayerUnderwaterStateChanged constinit property declarations ******
	static void NewProp_bUnderwater_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFPlayerUnderwaterStateChanged_Parms*)Obj)->bUnderwater = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUnderwater;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFPlayerUnderwaterStateChanged constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFPlayerUnderwaterStateChanged Property Definitions *****************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUnderwater = { "bUnderwater", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFPlayerUnderwaterStateChanged_Parms), &UHT_STATICS::NewProp_bUnderwater_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUnderwater,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFPlayerUnderwaterStateChanged Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFPlayerUnderwaterStateChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerUnderwaterStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerUnderwaterStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerUnderwaterStateChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFPlayerUnderwaterStateChanged ****************************************

// ********** Begin Delegate FDMFLocalCameraUnderwaterChanged **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFLocalCameraUnderwaterChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFLocalCameraUnderwaterChanged_Parms
	{
		bool bCameraUnderwater;
		ADMFSwimmableWater* WaterBody;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFLocalCameraUnderwaterChanged constinit property declarations ******
	static void NewProp_bCameraUnderwater_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFLocalCameraUnderwaterChanged_Parms*)Obj)->bCameraUnderwater = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCameraUnderwater;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaterBody;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFLocalCameraUnderwaterChanged constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFLocalCameraUnderwaterChanged Property Definitions *****************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCameraUnderwater = { "bCameraUnderwater", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFLocalCameraUnderwaterChanged_Parms), &UHT_STATICS::NewProp_bCameraUnderwater_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WaterBody = { "WaterBody", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFLocalCameraUnderwaterChanged_Parms, WaterBody), Z_Construct_UClass_ADMFSwimmableWater, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCameraUnderwater,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterBody,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFLocalCameraUnderwaterChanged Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFLocalCameraUnderwaterChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFLocalCameraUnderwaterChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFLocalCameraUnderwaterChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFLocalCameraUnderwaterChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFLocalCameraUnderwaterChanged ****************************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function AddCameraZoomInput ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_AddCameraZoomInput_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventAddCameraZoomInput_Parms
	{
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera|Zoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds local third-person camera zoom input. Positive values zoom in; negative values zoom out. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds local third-person camera zoom input. Positive values zoom in; negative values zoom out." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddCameraZoomInput constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddCameraZoomInput constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddCameraZoomInput Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventAddCameraZoomInput_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddCameraZoomInput Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "AddCameraZoomInput", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventAddCameraZoomInput_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventAddCameraZoomInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_AddCameraZoomInput(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execAddCameraZoomInput)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddCameraZoomInput(Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function AddCameraZoomInput **********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function AddSwimVerticalInput ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_AddSwimVerticalInput_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventAddSwimVerticalInput_Parms
	{
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds explicit vertical swim input. Positive ascends, negative descends. Useful for Enhanced Input projects. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds explicit vertical swim input. Positive ascends, negative descends. Useful for Enhanced Input projects." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddSwimVerticalInput constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddSwimVerticalInput constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddSwimVerticalInput Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventAddSwimVerticalInput_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddSwimVerticalInput Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "AddSwimVerticalInput", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventAddSwimVerticalInput_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventAddSwimVerticalInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_AddSwimVerticalInput(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execAddSwimVerticalInput)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddSwimVerticalInput(Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function AddSwimVerticalInput ********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function ApplyPlayerSkinData *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ApplyPlayerSkinData_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventApplyPlayerSkinData_Parms
	{
		UDMFPlayerSkinData* SkinData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Skin" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Applies presentation only. Authoritative selection must go through UDMFPlayerAvatarComponent::ServerSetPlayerSkin. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Applies presentation only. Authoritative selection must go through UDMFPlayerAvatarComponent::ServerSetPlayerSkin." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyPlayerSkinData constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkinData;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventApplyPlayerSkinData_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyPlayerSkinData constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyPlayerSkinData Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkinData = { "SkinData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventApplyPlayerSkinData_Parms, SkinData), Z_Construct_UClass_UDMFPlayerSkinData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventApplyPlayerSkinData_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplyPlayerSkinData Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "ApplyPlayerSkinData", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventApplyPlayerSkinData_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventApplyPlayerSkinData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ApplyPlayerSkinData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execApplyPlayerSkinData)
{
	P_GET_OBJECT(UDMFPlayerSkinData,Z_Param_SkinData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ApplyPlayerSkinData(Z_Param_SkinData);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function ApplyPlayerSkinData *********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function BP_OnDigimonInteracted ****************
struct DMFPlayerAvatarCharacter_eventBP_OnDigimonInteracted_Parms
{
	ADMFDigimonCharacter* Digimon;
	bool bTargeted;
	bool bAttackCommandSent;
};
static FName NAME_ADMFPlayerAvatarCharacter_BP_OnDigimonInteracted = FName(TEXT("BP_OnDigimonInteracted"));
void ADMFPlayerAvatarCharacter::BP_OnDigimonInteracted(ADMFDigimonCharacter* Digimon, bool bTargeted, bool bAttackCommandSent)
{
	DMFPlayerAvatarCharacter_eventBP_OnDigimonInteracted_Parms Parms;
	Parms.Digimon=Digimon;
	Parms.bTargeted=bTargeted ? true : false;
	Parms.bAttackCommandSent=bAttackCommandSent ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ADMFPlayerAvatarCharacter_BP_OnDigimonInteracted);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnDigimonInteracted_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fires for every Digimon interaction attempt; the Digimon reference is already typed for Blueprint. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fires for every Digimon interaction attempt; the Digimon reference is already typed for Blueprint." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnDigimonInteracted constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Digimon;
	static void NewProp_bTargeted_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventBP_OnDigimonInteracted_Parms*)Obj)->bTargeted = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTargeted;
	static void NewProp_bAttackCommandSent_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventBP_OnDigimonInteracted_Parms*)Obj)->bAttackCommandSent = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttackCommandSent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnDigimonInteracted constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnDigimonInteracted Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Digimon = { "Digimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventBP_OnDigimonInteracted_Parms, Digimon), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bTargeted = { "bTargeted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventBP_OnDigimonInteracted_Parms), &UHT_STATICS::NewProp_bTargeted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAttackCommandSent = { "bAttackCommandSent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventBP_OnDigimonInteracted_Parms), &UHT_STATICS::NewProp_bAttackCommandSent_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bTargeted,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAttackCommandSent,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnDigimonInteracted Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "BP_OnDigimonInteracted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerAvatarCharacter_eventBP_OnDigimonInteracted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerAvatarCharacter_eventBP_OnDigimonInteracted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnDigimonInteracted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFPlayerAvatarCharacter Function BP_OnDigimonInteracted ******************

// ********** Begin Class ADMFPlayerAvatarCharacter Function BP_OnLocalCameraUnderwaterChanged *****
struct DMFPlayerAvatarCharacter_eventBP_OnLocalCameraUnderwaterChanged_Parms
{
	bool bCameraUnderwater;
	ADMFSwimmableWater* WaterBody;
};
static FName NAME_ADMFPlayerAvatarCharacter_BP_OnLocalCameraUnderwaterChanged = FName(TEXT("BP_OnLocalCameraUnderwaterChanged"));
void ADMFPlayerAvatarCharacter::BP_OnLocalCameraUnderwaterChanged(bool bCameraUnderwater, ADMFSwimmableWater* WaterBody)
{
	DMFPlayerAvatarCharacter_eventBP_OnLocalCameraUnderwaterChanged_Parms Parms;
	Parms.bCameraUnderwater=bCameraUnderwater ? true : false;
	Parms.WaterBody=WaterBody;
	UFunction* Func = FindFunctionChecked(NAME_ADMFPlayerAvatarCharacter_BP_OnLocalCameraUnderwaterChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnLocalCameraUnderwaterChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Underwater Post Process|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local-only camera waterline event for project-authored bubbles/audio/material presentation. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local-only camera waterline event for project-authored bubbles/audio/material presentation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnLocalCameraUnderwaterChanged constinit property declarations *****
	static void NewProp_bCameraUnderwater_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventBP_OnLocalCameraUnderwaterChanged_Parms*)Obj)->bCameraUnderwater = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCameraUnderwater;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaterBody;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnLocalCameraUnderwaterChanged constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnLocalCameraUnderwaterChanged Property Definitions ****************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCameraUnderwater = { "bCameraUnderwater", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventBP_OnLocalCameraUnderwaterChanged_Parms), &UHT_STATICS::NewProp_bCameraUnderwater_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WaterBody = { "WaterBody", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventBP_OnLocalCameraUnderwaterChanged_Parms, WaterBody), Z_Construct_UClass_ADMFSwimmableWater, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCameraUnderwater,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterBody,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnLocalCameraUnderwaterChanged Property Definitions ******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "BP_OnLocalCameraUnderwaterChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerAvatarCharacter_eventBP_OnLocalCameraUnderwaterChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerAvatarCharacter_eventBP_OnLocalCameraUnderwaterChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnLocalCameraUnderwaterChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFPlayerAvatarCharacter Function BP_OnLocalCameraUnderwaterChanged *******

// ********** Begin Class ADMFPlayerAvatarCharacter Function BP_OnPlayerSkinApplied ****************
struct DMFPlayerAvatarCharacter_eventBP_OnPlayerSkinApplied_Parms
{
	UDMFPlayerSkinData* SkinData;
};
static FName NAME_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinApplied = FName(TEXT("BP_OnPlayerSkinApplied"));
void ADMFPlayerAvatarCharacter::BP_OnPlayerSkinApplied(UDMFPlayerSkinData* SkinData)
{
	DMFPlayerAvatarCharacter_eventBP_OnPlayerSkinApplied_Parms Parms;
	Parms.SkinData=SkinData;
	UFunction* Func = FindFunctionChecked(NAME_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinApplied);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinApplied_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Skin" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint presentation extension point called after native mesh/anim/material application. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint presentation extension point called after native mesh/anim/material application." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPlayerSkinApplied constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkinData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnPlayerSkinApplied constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnPlayerSkinApplied Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkinData = { "SkinData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventBP_OnPlayerSkinApplied_Parms, SkinData), Z_Construct_UClass_UDMFPlayerSkinData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinData,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnPlayerSkinApplied Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "BP_OnPlayerSkinApplied", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerAvatarCharacter_eventBP_OnPlayerSkinApplied_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerAvatarCharacter_eventBP_OnPlayerSkinApplied_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinApplied(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFPlayerAvatarCharacter Function BP_OnPlayerSkinApplied ******************

// ********** Begin Class ADMFPlayerAvatarCharacter Function BP_OnPlayerSkinRefreshRequested *******
static FName NAME_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinRefreshRequested = FName(TEXT("BP_OnPlayerSkinRefreshRequested"));
void ADMFPlayerAvatarCharacter::BP_OnPlayerSkinRefreshRequested()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinRefreshRequested);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinRefreshRequested_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Skin" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint hook fired after the framework locates PlayerState/avatar state and requests a visual refresh. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint hook fired after the framework locates PlayerState/avatar state and requests a visual refresh." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPlayerSkinRefreshRequested constinit property declarations *******
// ********** End Function BP_OnPlayerSkinRefreshRequested constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "BP_OnPlayerSkinRefreshRequested", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinRefreshRequested(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFPlayerAvatarCharacter Function BP_OnPlayerSkinRefreshRequested *********

// ********** Begin Class ADMFPlayerAvatarCharacter Function BP_OnSwimmingStateChanged *************
struct DMFPlayerAvatarCharacter_eventBP_OnSwimmingStateChanged_Parms
{
	bool bSwimming;
	bool bUnderwater;
	ADMFSwimmableWater* WaterBody;
};
static FName NAME_ADMFPlayerAvatarCharacter_BP_OnSwimmingStateChanged = FName(TEXT("BP_OnSwimmingStateChanged"));
void ADMFPlayerAvatarCharacter::BP_OnSwimmingStateChanged(bool bSwimming, bool bUnderwater, ADMFSwimmableWater* WaterBody)
{
	DMFPlayerAvatarCharacter_eventBP_OnSwimmingStateChanged_Parms Parms;
	Parms.bSwimming=bSwimming ? true : false;
	Parms.bUnderwater=bUnderwater ? true : false;
	Parms.WaterBody=WaterBody;
	UFunction* Func = FindFunctionChecked(NAME_ADMFPlayerAvatarCharacter_BP_OnSwimmingStateChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnSwimmingStateChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnSwimmingStateChanged constinit property declarations *************
	static void NewProp_bSwimming_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventBP_OnSwimmingStateChanged_Parms*)Obj)->bSwimming = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSwimming;
	static void NewProp_bUnderwater_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventBP_OnSwimmingStateChanged_Parms*)Obj)->bUnderwater = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUnderwater;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaterBody;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnSwimmingStateChanged constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnSwimmingStateChanged Property Definitions ************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSwimming = { "bSwimming", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventBP_OnSwimmingStateChanged_Parms), &UHT_STATICS::NewProp_bSwimming_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUnderwater = { "bUnderwater", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventBP_OnSwimmingStateChanged_Parms), &UHT_STATICS::NewProp_bUnderwater_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WaterBody = { "WaterBody", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventBP_OnSwimmingStateChanged_Parms, WaterBody), Z_Construct_UClass_ADMFSwimmableWater, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSwimming,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUnderwater,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterBody,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnSwimmingStateChanged Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "BP_OnSwimmingStateChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerAvatarCharacter_eventBP_OnSwimmingStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerAvatarCharacter_eventBP_OnSwimmingStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnSwimmingStateChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFPlayerAvatarCharacter Function BP_OnSwimmingStateChanged ***************

// ********** Begin Class ADMFPlayerAvatarCharacter Function BP_OnUnderwaterStateChanged ***********
struct DMFPlayerAvatarCharacter_eventBP_OnUnderwaterStateChanged_Parms
{
	bool bUnderwater;
};
static FName NAME_ADMFPlayerAvatarCharacter_BP_OnUnderwaterStateChanged = FName(TEXT("BP_OnUnderwaterStateChanged"));
void ADMFPlayerAvatarCharacter::BP_OnUnderwaterStateChanged(bool bUnderwater)
{
	DMFPlayerAvatarCharacter_eventBP_OnUnderwaterStateChanged_Parms Parms;
	Parms.bUnderwater=bUnderwater ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ADMFPlayerAvatarCharacter_BP_OnUnderwaterStateChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnUnderwaterStateChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnUnderwaterStateChanged constinit property declarations ***********
	static void NewProp_bUnderwater_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventBP_OnUnderwaterStateChanged_Parms*)Obj)->bUnderwater = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUnderwater;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnUnderwaterStateChanged constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnUnderwaterStateChanged Property Definitions **********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUnderwater = { "bUnderwater", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventBP_OnUnderwaterStateChanged_Parms), &UHT_STATICS::NewProp_bUnderwater_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUnderwater,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnUnderwaterStateChanged Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "BP_OnUnderwaterStateChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerAvatarCharacter_eventBP_OnUnderwaterStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerAvatarCharacter_eventBP_OnUnderwaterStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnUnderwaterStateChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFPlayerAvatarCharacter Function BP_OnUnderwaterStateChanged *************

// ********** Begin Class ADMFPlayerAvatarCharacter Function BP_OnUnhandledInteraction *************
struct DMFPlayerAvatarCharacter_eventBP_OnUnhandledInteraction_Parms
{
	AActor* TargetActor;
};
static FName NAME_ADMFPlayerAvatarCharacter_BP_OnUnhandledInteraction = FName(TEXT("BP_OnUnhandledInteraction"));
void ADMFPlayerAvatarCharacter::BP_OnUnhandledInteraction(AActor* TargetActor)
{
	DMFPlayerAvatarCharacter_eventBP_OnUnhandledInteraction_Parms Parms;
	Parms.TargetActor=TargetActor;
	UFunction* Func = FindFunctionChecked(NAME_ADMFPlayerAvatarCharacter_BP_OnUnhandledInteraction);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnUnhandledInteraction_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extension point for project-specific actors not natively handled by the framework. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extension point for project-specific actors not natively handled by the framework." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnUnhandledInteraction constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnUnhandledInteraction constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnUnhandledInteraction Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventBP_OnUnhandledInteraction_Parms, TargetActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetActor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnUnhandledInteraction Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "BP_OnUnhandledInteraction", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerAvatarCharacter_eventBP_OnUnhandledInteraction_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerAvatarCharacter_eventBP_OnUnhandledInteraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnUnhandledInteraction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFPlayerAvatarCharacter Function BP_OnUnhandledInteraction ***************

// ********** Begin Class ADMFPlayerAvatarCharacter Function ClearDigimonTarget ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ClearDigimonTarget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Clears the current partner command target without requiring PlayerController/PlayerState casts. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clears the current partner command target without requiring PlayerController/PlayerState casts." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ClearDigimonTarget constinit property declarations ********************
// ********** End Function ClearDigimonTarget constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "ClearDigimonTarget", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ClearDigimonTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execClearDigimonTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearDigimonTarget();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function ClearDigimonTarget **********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function CommandDigimonAbilitySlot *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_CommandDigimonAbilitySlot_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventCommandDigimonAbilitySlot_Parms
	{
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Executes/queues an active-partner ability against the already selected target. Zero-based: 0 = slot 1. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Executes/queues an active-partner ability against the already selected target. Zero-based: 0 = slot 1." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CommandDigimonAbilitySlot constinit property declarations *************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CommandDigimonAbilitySlot constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CommandDigimonAbilitySlot Property Definitions ************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventCommandDigimonAbilitySlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CommandDigimonAbilitySlot Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "CommandDigimonAbilitySlot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventCommandDigimonAbilitySlot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventCommandDigimonAbilitySlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_CommandDigimonAbilitySlot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execCommandDigimonAbilitySlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CommandDigimonAbilitySlot(Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function CommandDigimonAbilitySlot ***************

// ********** Begin Class ADMFPlayerAvatarCharacter Function FindInteractionTarget *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_FindInteractionTarget_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventFindInteractionTarget_Parms
	{
		FHitResult OutHit;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Trace" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Performs only the local trace/sweep and returns the best hit actor; it does not interact. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Performs only the local trace/sweep and returns the best hit actor; it does not interact." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FindInteractionTarget constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutHit;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindInteractionTarget constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindInteractionTarget Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OutHit = { "OutHit", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventFindInteractionTarget_Parms, OutHit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // e0ec7b349cc3b29366a6161006ad7fa74de2944e
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventFindInteractionTarget_Parms, ReturnValue), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutHit,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function FindInteractionTarget Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "FindInteractionTarget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventFindInteractionTarget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventFindInteractionTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_FindInteractionTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execFindInteractionTarget)
{
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_OutHit);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->FindInteractionTarget(Z_Param_Out_OutHit);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function FindInteractionTarget *******************

// ********** Begin Class ADMFPlayerAvatarCharacter Function GetActiveSwimmableWater ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetActiveSwimmableWater_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventGetActiveSwimmableWater_Parms
	{
		ADMFSwimmableWater* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveSwimmableWater constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveSwimmableWater constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveSwimmableWater Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventGetActiveSwimmableWater_Parms, ReturnValue), Z_Construct_UClass_ADMFSwimmableWater, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetActiveSwimmableWater Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "GetActiveSwimmableWater", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventGetActiveSwimmableWater_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventGetActiveSwimmableWater_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetActiveSwimmableWater(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execGetActiveSwimmableWater)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFSwimmableWater**)Z_Param__Result=P_THIS->GetActiveSwimmableWater();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function GetActiveSwimmableWater *****************

// ********** Begin Class ADMFPlayerAvatarCharacter Function GetAppliedPlayerSkinId ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetAppliedPlayerSkinId_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventGetAppliedPlayerSkinId_Parms
	{
		FPrimaryAssetId ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Skin" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAppliedPlayerSkinId constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAppliedPlayerSkinId constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAppliedPlayerSkinId Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventGetAppliedPlayerSkinId_Parms, ReturnValue), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAppliedPlayerSkinId Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "GetAppliedPlayerSkinId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventGetAppliedPlayerSkinId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventGetAppliedPlayerSkinId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetAppliedPlayerSkinId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execGetAppliedPlayerSkinId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPrimaryAssetId*)Z_Param__Result=P_THIS->GetAppliedPlayerSkinId();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function GetAppliedPlayerSkinId ******************

// ********** Begin Class ADMFPlayerAvatarCharacter Function GetCameraZoomDistance *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetCameraZoomDistance_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventGetCameraZoomDistance_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera|Zoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns the locally requested boom distance (not the temporary collision-compressed spring-arm result). */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the locally requested boom distance (not the temporary collision-compressed spring-arm result)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCameraZoomDistance constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCameraZoomDistance constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCameraZoomDistance Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventGetCameraZoomDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCameraZoomDistance Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "GetCameraZoomDistance", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventGetCameraZoomDistance_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventGetCameraZoomDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetCameraZoomDistance(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execGetCameraZoomDistance)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCameraZoomDistance();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function GetCameraZoomDistance *******************

// ********** Begin Class ADMFPlayerAvatarCharacter Function GetCurrentDigimonTarget ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetCurrentDigimonTarget_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventGetCurrentDigimonTarget_Parms
	{
		ADMFDigimonCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentDigimonTarget constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentDigimonTarget constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentDigimonTarget Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventGetCurrentDigimonTarget_Parms, ReturnValue), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentDigimonTarget Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "GetCurrentDigimonTarget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventGetCurrentDigimonTarget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventGetCurrentDigimonTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetCurrentDigimonTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execGetCurrentDigimonTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFDigimonCharacter**)Z_Param__Result=P_THIS->GetCurrentDigimonTarget();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function GetCurrentDigimonTarget *****************

// ********** Begin Class ADMFPlayerAvatarCharacter Function GetInteractionPromptForActor **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetInteractionPromptForActor_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventGetInteractionPromptForActor_Parms
	{
		AActor* TargetActor;
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native prompt helper for framework actors; custom/unhandled actors return empty text. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native prompt helper for framework actors; custom/unhandled actors return empty text." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteractionPromptForActor constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteractionPromptForActor constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteractionPromptForActor Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventGetInteractionPromptForActor_Parms, TargetActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventGetInteractionPromptForActor_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetInteractionPromptForActor Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "GetInteractionPromptForActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventGetInteractionPromptForActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventGetInteractionPromptForActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetInteractionPromptForActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execGetInteractionPromptForActor)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetInteractionPromptForActor(Z_Param_TargetActor);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function GetInteractionPromptForActor ************

// ********** Begin Class ADMFPlayerAvatarCharacter Function GetLastInteractionActor ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetLastInteractionActor_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventGetLastInteractionActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLastInteractionActor constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLastInteractionActor constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLastInteractionActor Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventGetLastInteractionActor_Parms, ReturnValue), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetLastInteractionActor Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "GetLastInteractionActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventGetLastInteractionActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventGetLastInteractionActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetLastInteractionActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execGetLastInteractionActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetLastInteractionActor();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function GetLastInteractionActor *****************

// ********** Begin Class ADMFPlayerAvatarCharacter Function GetPlayerSwimState ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetPlayerSwimState_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventGetPlayerSwimState_Parms
	{
		EDMFPlayerSwimState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerSwimState constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerSwimState constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerSwimState Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventGetPlayerSwimState_Parms, ReturnValue), Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerSwimState, METADATA_PARAMS(0, nullptr) }; // 0a5b30d859e51114bbcf929f592369a79b6c9afb
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetPlayerSwimState Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "GetPlayerSwimState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventGetPlayerSwimState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventGetPlayerSwimState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetPlayerSwimState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execGetPlayerSwimState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDMFPlayerSwimState*)Z_Param__Result=P_THIS->GetPlayerSwimState();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function GetPlayerSwimState **********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function GetUnderwaterPostProcessBlendWeight ***
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetUnderwaterPostProcessBlendWeight_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventGetUnderwaterPostProcessBlendWeight_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Underwater Post Process" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current local blend weight (0-1) of the water body's underwater post-process profile. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current local blend weight (0-1) of the water body's underwater post-process profile." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetUnderwaterPostProcessBlendWeight constinit property declarations ***
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetUnderwaterPostProcessBlendWeight constinit property declarations *****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetUnderwaterPostProcessBlendWeight Property Definitions **************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventGetUnderwaterPostProcessBlendWeight_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetUnderwaterPostProcessBlendWeight Property Definitions ****************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "GetUnderwaterPostProcessBlendWeight", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventGetUnderwaterPostProcessBlendWeight_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventGetUnderwaterPostProcessBlendWeight_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetUnderwaterPostProcessBlendWeight(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execGetUnderwaterPostProcessBlendWeight)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetUnderwaterPostProcessBlendWeight();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function GetUnderwaterPostProcessBlendWeight *****

// ********** Begin Class ADMFPlayerAvatarCharacter Function Interact ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_Interact_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventInteract_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * One-call project interaction entry point. Traces from the local player view and automatically:\n     * - targets hostile Digimon (or target+attacks when configured),\n     * - uses DMFHealerActor,\n     * - reports unsupported actors to Blueprint without requiring casts.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One-call project interaction entry point. Traces from the local player view and automatically:\n- targets hostile Digimon (or target+attacks when configured),\n- uses DMFHealerActor,\n- reports unsupported actors to Blueprint without requiring casts." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Interact constinit property declarations ******************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventInteract_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Interact constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Interact Property Definitions *****************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventInteract_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Interact Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "Interact", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventInteract_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_Interact(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execInteract)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Interact();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function Interact ********************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function InteractWithActor *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithActor_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventInteractWithActor_Parms
	{
		AActor* TargetActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Same dispatch as Interact(), but for an actor already found by project UI/overlap/trace logic. No cast is required in Blueprint. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Same dispatch as Interact(), but for an actor already found by project UI/overlap/trace logic. No cast is required in Blueprint." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function InteractWithActor constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventInteractWithActor_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InteractWithActor constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InteractWithActor Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventInteractWithActor_Parms, TargetActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventInteractWithActor_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InteractWithActor Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "InteractWithActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execInteractWithActor)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InteractWithActor(Z_Param_TargetActor);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function InteractWithActor ***********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function InteractWithDigimon *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithDigimon_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventInteractWithDigimon_Parms
	{
		AActor* DigimonActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Discoverable no-cast alias for target-only Digimon interaction. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Discoverable no-cast alias for target-only Digimon interaction." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function InteractWithDigimon constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonActor;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventInteractWithDigimon_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InteractWithDigimon constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InteractWithDigimon Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonActor = { "DigimonActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventInteractWithDigimon_Parms, DigimonActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventInteractWithDigimon_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InteractWithDigimon Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "InteractWithDigimon", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithDigimon_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithDigimon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithDigimon(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execInteractWithDigimon)
{
	P_GET_OBJECT(AActor,Z_Param_DigimonActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InteractWithDigimon(Z_Param_DigimonActor);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function InteractWithDigimon *********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function InteractWithDigimonAndAttack **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithDigimonAndAttack_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventInteractWithDigimonAndAttack_Parms
	{
		AActor* DigimonActor;
		int32 SlotIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Discoverable no-cast alias for Digimon interaction that also sends an attack command. */" },
#endif
		{ "CPP_Default_SlotIndex", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Discoverable no-cast alias for Digimon interaction that also sends an attack command." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function InteractWithDigimonAndAttack constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonActor;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventInteractWithDigimonAndAttack_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InteractWithDigimonAndAttack constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InteractWithDigimonAndAttack Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonActor = { "DigimonActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventInteractWithDigimonAndAttack_Parms, DigimonActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventInteractWithDigimonAndAttack_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventInteractWithDigimonAndAttack_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InteractWithDigimonAndAttack Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "InteractWithDigimonAndAttack", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithDigimonAndAttack_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithDigimonAndAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithDigimonAndAttack(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execInteractWithDigimonAndAttack)
{
	P_GET_OBJECT(AActor,Z_Param_DigimonActor);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InteractWithDigimonAndAttack(Z_Param_DigimonActor,Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function InteractWithDigimonAndAttack ************

// ********** Begin Class ADMFPlayerAvatarCharacter Function InteractWithDigimonVendor *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithDigimonVendor_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventInteractWithDigimonVendor_Parms
	{
		AActor* VendorActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Vendor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens a nearby Digimon vendor from a generic Actor reference; no Blueprint cast is required. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens a nearby Digimon vendor from a generic Actor reference; no Blueprint cast is required." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function InteractWithDigimonVendor constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorActor;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventInteractWithDigimonVendor_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InteractWithDigimonVendor constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InteractWithDigimonVendor Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorActor = { "VendorActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventInteractWithDigimonVendor_Parms, VendorActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventInteractWithDigimonVendor_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InteractWithDigimonVendor Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "InteractWithDigimonVendor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithDigimonVendor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithDigimonVendor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithDigimonVendor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execInteractWithDigimonVendor)
{
	P_GET_OBJECT(AActor,Z_Param_VendorActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InteractWithDigimonVendor(Z_Param_VendorActor);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function InteractWithDigimonVendor ***************

// ********** Begin Class ADMFPlayerAvatarCharacter Function InteractWithHealer ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithHealer_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventInteractWithHealer_Parms
	{
		AActor* HealerActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Healer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Uses a healer from a generic Actor reference; no Blueprint cast is required. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Uses a healer from a generic Actor reference; no Blueprint cast is required." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function InteractWithHealer constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealerActor;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventInteractWithHealer_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InteractWithHealer constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InteractWithHealer Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealerActor = { "HealerActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventInteractWithHealer_Parms, HealerActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventInteractWithHealer_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealerActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InteractWithHealer Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "InteractWithHealer", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithHealer_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithHealer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithHealer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execInteractWithHealer)
{
	P_GET_OBJECT(AActor,Z_Param_HealerActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InteractWithHealer(Z_Param_HealerActor);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function InteractWithHealer **********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function InteractWithItemVendor ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithItemVendor_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventInteractWithItemVendor_Parms
	{
		AActor* VendorActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Vendor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens a nearby item vendor from a generic Actor reference; no Blueprint cast is required. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens a nearby item vendor from a generic Actor reference; no Blueprint cast is required." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function InteractWithItemVendor constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorActor;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventInteractWithItemVendor_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InteractWithItemVendor constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InteractWithItemVendor Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorActor = { "VendorActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventInteractWithItemVendor_Parms, VendorActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventInteractWithItemVendor_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InteractWithItemVendor Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "InteractWithItemVendor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithItemVendor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventInteractWithItemVendor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithItemVendor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execInteractWithItemVendor)
{
	P_GET_OBJECT(AActor,Z_Param_VendorActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InteractWithItemVendor(Z_Param_VendorActor);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function InteractWithItemVendor ******************

// ********** Begin Class ADMFPlayerAvatarCharacter Function IsLocalCameraUnderwater ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsLocalCameraUnderwater_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventIsLocalCameraUnderwater_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Underwater Post Process" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True only for the locally controlled player's camera while it is physically below the active water surface. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True only for the locally controlled player's camera while it is physically below the active water surface." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsLocalCameraUnderwater constinit property declarations ***************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventIsLocalCameraUnderwater_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsLocalCameraUnderwater constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsLocalCameraUnderwater Property Definitions **************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventIsLocalCameraUnderwater_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsLocalCameraUnderwater Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "IsLocalCameraUnderwater", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventIsLocalCameraUnderwater_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventIsLocalCameraUnderwater_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsLocalCameraUnderwater(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execIsLocalCameraUnderwater)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsLocalCameraUnderwater();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function IsLocalCameraUnderwater *****************

// ********** Begin Class ADMFPlayerAvatarCharacter Function IsSprinting ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsSprinting_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventIsSprinting_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Movement" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsSprinting constinit property declarations ***************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventIsSprinting_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSprinting constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSprinting Property Definitions **************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventIsSprinting_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsSprinting Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "IsSprinting", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventIsSprinting_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventIsSprinting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsSprinting(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execIsSprinting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSprinting();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function IsSprinting *****************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function IsSwimmingInWater *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsSwimmingInWater_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventIsSwimmingInWater_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True when the authoritative/predicted avatar is currently inside a DMFSwimmableWater body. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True when the authoritative/predicted avatar is currently inside a DMFSwimmableWater body." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsSwimmingInWater constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventIsSwimmingInWater_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSwimmingInWater constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSwimmingInWater Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventIsSwimmingInWater_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsSwimmingInWater Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "IsSwimmingInWater", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventIsSwimmingInWater_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventIsSwimmingInWater_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsSwimmingInWater(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execIsSwimmingInWater)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSwimmingInWater();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function IsSwimmingInWater ***********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function IsSwimmingUnderwater ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsSwimmingUnderwater_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventIsSwimmingUnderwater_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True once the avatar has crossed the active water body's underwater depth threshold. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True once the avatar has crossed the active water body's underwater depth threshold." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsSwimmingUnderwater constinit property declarations ******************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventIsSwimmingUnderwater_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSwimmingUnderwater constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSwimmingUnderwater Property Definitions *****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventIsSwimmingUnderwater_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsSwimmingUnderwater Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "IsSwimmingUnderwater", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventIsSwimmingUnderwater_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventIsSwimmingUnderwater_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsSwimmingUnderwater(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execIsSwimmingUnderwater)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSwimmingUnderwater();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function IsSwimmingUnderwater ********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function LookPitch *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_LookPitch_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventLookPitch_Parms
	{
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function LookPitch constinit property declarations *****************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LookPitch constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LookPitch Property Definitions ****************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventLookPitch_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function LookPitch Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "LookPitch", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventLookPitch_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventLookPitch_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_LookPitch(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execLookPitch)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LookPitch(Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function LookPitch *******************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function LookYaw *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_LookYaw_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventLookYaw_Parms
	{
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function LookYaw constinit property declarations *******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LookYaw constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LookYaw Property Definitions ******************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventLookYaw_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function LookYaw Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "LookYaw", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventLookYaw_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventLookYaw_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_LookYaw(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execLookYaw)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LookYaw(Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function LookYaw *********************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function MoveForward ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_MoveForward_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventMoveForward_Parms
	{
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Movement" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MoveForward constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MoveForward constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MoveForward Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventMoveForward_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MoveForward Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "MoveForward", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventMoveForward_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventMoveForward_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_MoveForward(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execMoveForward)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MoveForward(Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function MoveForward *****************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function MoveRight *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_MoveRight_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventMoveRight_Parms
	{
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Movement" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MoveRight constinit property declarations *****************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MoveRight constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MoveRight Property Definitions ****************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventMoveRight_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MoveRight Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "MoveRight", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventMoveRight_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventMoveRight_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_MoveRight(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execMoveRight)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MoveRight(Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function MoveRight *******************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function MulticastPlayPlayerFootstep ***********
static FName NAME_ADMFPlayerAvatarCharacter_MulticastPlayPlayerFootstep = FName(TEXT("MulticastPlayPlayerFootstep"));
void ADMFPlayerAvatarCharacter::MulticastPlayPlayerFootstep()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFPlayerAvatarCharacter_MulticastPlayPlayerFootstep);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_MulticastPlayPlayerFootstep_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MulticastPlayPlayerFootstep constinit property declarations ***********
// ********** End Function MulticastPlayPlayerFootstep constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "MulticastPlayPlayerFootstep", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00044C41, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_MulticastPlayPlayerFootstep(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execMulticastPlayPlayerFootstep)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MulticastPlayPlayerFootstep_Implementation();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function MulticastPlayPlayerFootstep *************

// ********** Begin Class ADMFPlayerAvatarCharacter Function OnRep_ActiveSwimmableWater ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_ActiveSwimmableWater_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_ActiveSwimmableWater constinit property declarations ************
// ********** End Function OnRep_ActiveSwimmableWater constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "OnRep_ActiveSwimmableWater", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_ActiveSwimmableWater(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execOnRep_ActiveSwimmableWater)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_ActiveSwimmableWater();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function OnRep_ActiveSwimmableWater **************

// ********** Begin Class ADMFPlayerAvatarCharacter Function OnRep_ReplicatedSwimPresentationState *
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_ReplicatedSwimPresentationState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_ReplicatedSwimPresentationState constinit property declarations *
// ********** End Function OnRep_ReplicatedSwimPresentationState constinit property declarations ***
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "OnRep_ReplicatedSwimPresentationState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_ReplicatedSwimPresentationState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execOnRep_ReplicatedSwimPresentationState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_ReplicatedSwimPresentationState();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function OnRep_ReplicatedSwimPresentationState ***

// ********** Begin Class ADMFPlayerAvatarCharacter Function OnRep_Sprinting ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_Sprinting_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_Sprinting constinit property declarations ***********************
// ********** End Function OnRep_Sprinting constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "OnRep_Sprinting", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_Sprinting(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execOnRep_Sprinting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Sprinting();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function OnRep_Sprinting *************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function OnRep_UnderwaterSwimming **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_UnderwaterSwimming_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_UnderwaterSwimming constinit property declarations **************
// ********** End Function OnRep_UnderwaterSwimming constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "OnRep_UnderwaterSwimming", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_UnderwaterSwimming(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execOnRep_UnderwaterSwimming)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_UnderwaterSwimming();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function OnRep_UnderwaterSwimming ****************

// ********** Begin Class ADMFPlayerAvatarCharacter Function PlayPlayerFootstepLocal ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_PlayPlayerFootstepLocal_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Footsteps" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Plays one local footstep presentation using the globally configured player footstep sound.\n     * Normal gameplay uses the automatic distance-based replicated cadence; this helper exists for project-specific presentation hooks.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Plays one local footstep presentation using the globally configured player footstep sound.\nNormal gameplay uses the automatic distance-based replicated cadence; this helper exists for project-specific presentation hooks." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function PlayPlayerFootstepLocal constinit property declarations ***************
// ********** End Function PlayPlayerFootstepLocal constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "PlayPlayerFootstepLocal", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_PlayPlayerFootstepLocal(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execPlayPlayerFootstepLocal)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayPlayerFootstepLocal();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function PlayPlayerFootstepLocal *****************

// ********** Begin Class ADMFPlayerAvatarCharacter Function RebuildSwimmingStateFromWorld *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RebuildSwimmingStateFromWorld_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventRebuildSwimmingStateFromWorld_Parms
	{
		bool bStopMovementIfSwimming;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Rebuilds water occupancy from the avatar's current world transform instead of relying on BeginOverlap timing.\n     * Use this after server-authoritative teleports/load restores into or out of water. Authority rebuilds replicated\n     * water state; the owning client may also use it for safe local prediction. Optional movement reset prevents a\n     * restored underwater avatar from carrying a stale Falling velocity before swimming physics is re-established.\n     */" },
#endif
		{ "CPP_Default_bStopMovementIfSwimming", "false" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rebuilds water occupancy from the avatar's current world transform instead of relying on BeginOverlap timing.\nUse this after server-authoritative teleports/load restores into or out of water. Authority rebuilds replicated\nwater state; the owning client may also use it for safe local prediction. Optional movement reset prevents a\nrestored underwater avatar from carrying a stale Falling velocity before swimming physics is re-established." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RebuildSwimmingStateFromWorld constinit property declarations *********
	static void NewProp_bStopMovementIfSwimming_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventRebuildSwimmingStateFromWorld_Parms*)Obj)->bStopMovementIfSwimming = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopMovementIfSwimming;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RebuildSwimmingStateFromWorld constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RebuildSwimmingStateFromWorld Property Definitions ********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bStopMovementIfSwimming = { "bStopMovementIfSwimming", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventRebuildSwimmingStateFromWorld_Parms), &UHT_STATICS::NewProp_bStopMovementIfSwimming_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bStopMovementIfSwimming,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RebuildSwimmingStateFromWorld Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "RebuildSwimmingStateFromWorld", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventRebuildSwimmingStateFromWorld_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventRebuildSwimmingStateFromWorld_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RebuildSwimmingStateFromWorld(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execRebuildSwimmingStateFromWorld)
{
	P_GET_UBOOL(Z_Param_bStopMovementIfSwimming);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RebuildSwimmingStateFromWorld(Z_Param_bStopMovementIfSwimming);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function RebuildSwimmingStateFromWorld ***********

// ********** Begin Class ADMFPlayerAvatarCharacter Function RefreshCameraCollisionPolicy **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshCameraCollisionPolicy_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera|Collision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reasserts the global rule that player collision must not block the spring-arm camera channel. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reasserts the global rule that player collision must not block the spring-arm camera channel." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshCameraCollisionPolicy constinit property declarations **********
// ********** End Function RefreshCameraCollisionPolicy constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "RefreshCameraCollisionPolicy", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshCameraCollisionPolicy(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execRefreshCameraCollisionPolicy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshCameraCollisionPolicy();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function RefreshCameraCollisionPolicy ************

// ********** Begin Class ADMFPlayerAvatarCharacter Function RefreshFrameworkCustomDepth ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshFrameworkCustomDepth_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Rendering|Cel Shading" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Reasserts the framework cel-shading contract on every mesh component owned by this avatar.\n     * Render CustomDepth Pass is always forced on; the stencil value remains Blueprint-tunable.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reasserts the framework cel-shading contract on every mesh component owned by this avatar.\nRender CustomDepth Pass is always forced on; the stencil value remains Blueprint-tunable." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshFrameworkCustomDepth constinit property declarations ***********
// ********** End Function RefreshFrameworkCustomDepth constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "RefreshFrameworkCustomDepth", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshFrameworkCustomDepth(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execRefreshFrameworkCustomDepth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshFrameworkCustomDepth();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function RefreshFrameworkCustomDepth *************

// ********** Begin Class ADMFPlayerAvatarCharacter Function RefreshSwimmingPresentation ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshSwimmingPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-applies the current no-animation swim fallback pose immediately. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-applies the current no-animation swim fallback pose immediately." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshSwimmingPresentation constinit property declarations ***********
// ********** End Function RefreshSwimmingPresentation constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "RefreshSwimmingPresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshSwimmingPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execRefreshSwimmingPresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshSwimmingPresentation();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function RefreshSwimmingPresentation *************

// ********** Begin Class ADMFPlayerAvatarCharacter Function RefreshUnderwaterPostProcessPresentation 
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshUnderwaterPostProcessPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Underwater Post Process" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rebuilds the local camera profile from the current water body without changing replicated swimming state. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rebuilds the local camera profile from the current water body without changing replicated swimming state." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshUnderwaterPostProcessPresentation constinit property declarations 
// ********** End Function RefreshUnderwaterPostProcessPresentation constinit property declarations 
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "RefreshUnderwaterPostProcessPresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshUnderwaterPostProcessPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execRefreshUnderwaterPostProcessPresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshUnderwaterPostProcessPresentation();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function RefreshUnderwaterPostProcessPresentation 

// ********** Begin Class ADMFPlayerAvatarCharacter Function RefreshWorldNameplate *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshWorldNameplate_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Nameplates" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-applies global nameplate enablement, widget class, height and cull distance. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-applies global nameplate enablement, widget class, height and cull distance." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshWorldNameplate constinit property declarations *****************
// ********** End Function RefreshWorldNameplate constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "RefreshWorldNameplate", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshWorldNameplate(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execRefreshWorldNameplate)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshWorldNameplate();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function RefreshWorldNameplate *******************

// ********** Begin Class ADMFPlayerAvatarCharacter Function RegisterSwimmableWaterOverlap *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RegisterSwimmableWaterOverlap_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventRegisterSwimmableWaterOverlap_Parms
	{
		ADMFSwimmableWater* WaterBody;
		bool bEntered;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Water-volume integration point used by DMFSwimmableWater. Custom Blueprint water implementations may call\n     * this on overlap too; clients only gain local prediction while authority still owns the replicated state.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Water-volume integration point used by DMFSwimmableWater. Custom Blueprint water implementations may call\nthis on overlap too; clients only gain local prediction while authority still owns the replicated state." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterSwimmableWaterOverlap constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaterBody;
	static void NewProp_bEntered_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventRegisterSwimmableWaterOverlap_Parms*)Obj)->bEntered = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEntered;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterSwimmableWaterOverlap constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterSwimmableWaterOverlap Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WaterBody = { "WaterBody", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventRegisterSwimmableWaterOverlap_Parms, WaterBody), Z_Construct_UClass_ADMFSwimmableWater, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEntered = { "bEntered", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventRegisterSwimmableWaterOverlap_Parms), &UHT_STATICS::NewProp_bEntered_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterBody,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEntered,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RegisterSwimmableWaterOverlap Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "RegisterSwimmableWaterOverlap", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventRegisterSwimmableWaterOverlap_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventRegisterSwimmableWaterOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RegisterSwimmableWaterOverlap(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execRegisterSwimmableWaterOverlap)
{
	P_GET_OBJECT(ADMFSwimmableWater,Z_Param_WaterBody);
	P_GET_UBOOL(Z_Param_bEntered);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegisterSwimmableWaterOverlap(Z_Param_WaterBody,Z_Param_bEntered);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function RegisterSwimmableWaterOverlap ***********

// ********** Begin Class ADMFPlayerAvatarCharacter Function ResetCameraZoom ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ResetCameraZoom_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventResetCameraZoom_Parms
	{
		bool bInstant;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera|Zoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Restores the globally configured default camera boom distance. */" },
#endif
		{ "CPP_Default_bInstant", "false" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Restores the globally configured default camera boom distance." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ResetCameraZoom constinit property declarations ***********************
	static void NewProp_bInstant_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventResetCameraZoom_Parms*)Obj)->bInstant = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInstant;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetCameraZoom constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetCameraZoom Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInstant = { "bInstant", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventResetCameraZoom_Parms), &UHT_STATICS::NewProp_bInstant_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInstant,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ResetCameraZoom Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "ResetCameraZoom", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventResetCameraZoom_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventResetCameraZoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ResetCameraZoom(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execResetCameraZoom)
{
	P_GET_UBOOL(Z_Param_bInstant);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetCameraZoom(Z_Param_bInstant);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function ResetCameraZoom *************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function ResetNativeInputState *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ResetNativeInputState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Clears held native WASD/sprint state before modal UI takes input focus. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clears held native WASD/sprint state before modal UI takes input focus." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ResetNativeInputState constinit property declarations *****************
// ********** End Function ResetNativeInputState constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "ResetNativeInputState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ResetNativeInputState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execResetNativeInputState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetNativeInputState();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function ResetNativeInputState *******************

// ********** Begin Class ADMFPlayerAvatarCharacter Function ServerSetSprinting ********************
struct DMFPlayerAvatarCharacter_eventServerSetSprinting_Parms
{
	bool bNewSprinting;
};
static FName NAME_ADMFPlayerAvatarCharacter_ServerSetSprinting = FName(TEXT("ServerSetSprinting"));
void ADMFPlayerAvatarCharacter::ServerSetSprinting(bool bNewSprinting)
{
	DMFPlayerAvatarCharacter_eventServerSetSprinting_Parms Parms;
	Parms.bNewSprinting=bNewSprinting ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ADMFPlayerAvatarCharacter_ServerSetSprinting);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ServerSetSprinting_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerSetSprinting constinit property declarations ********************
	static void NewProp_bNewSprinting_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventServerSetSprinting_Parms*)Obj)->bNewSprinting = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewSprinting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ServerSetSprinting constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ServerSetSprinting Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bNewSprinting = { "bNewSprinting", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventServerSetSprinting_Parms), &UHT_STATICS::NewProp_bNewSprinting_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bNewSprinting,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ServerSetSprinting Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "ServerSetSprinting", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerAvatarCharacter_eventServerSetSprinting_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00240CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerAvatarCharacter_eventServerSetSprinting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ServerSetSprinting(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execServerSetSprinting)
{
	P_GET_UBOOL(Z_Param_bNewSprinting);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSetSprinting_Implementation(Z_Param_bNewSprinting);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function ServerSetSprinting **********************

// ********** Begin Class ADMFPlayerAvatarCharacter Function SetCameraZoomDistance *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_SetCameraZoomDistance_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventSetCameraZoomDistance_Parms
	{
		float NewDistance;
		bool bInstant;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera|Zoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Requests an absolute local boom distance, clamped to the global Project Settings min/max range. */" },
#endif
		{ "CPP_Default_bInstant", "false" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Requests an absolute local boom distance, clamped to the global Project Settings min/max range." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetCameraZoomDistance constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewDistance;
	static void NewProp_bInstant_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventSetCameraZoomDistance_Parms*)Obj)->bInstant = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInstant;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCameraZoomDistance constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCameraZoomDistance Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NewDistance = { "NewDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventSetCameraZoomDistance_Parms, NewDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInstant = { "bInstant", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventSetCameraZoomDistance_Parms), &UHT_STATICS::NewProp_bInstant_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInstant,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetCameraZoomDistance Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "SetCameraZoomDistance", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventSetCameraZoomDistance_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventSetCameraZoomDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_SetCameraZoomDistance(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execSetCameraZoomDistance)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewDistance);
	P_GET_UBOOL(Z_Param_bInstant);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCameraZoomDistance(Z_Param_NewDistance,Z_Param_bInstant);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function SetCameraZoomDistance *******************

// ********** Begin Class ADMFPlayerAvatarCharacter Function StartSprinting ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_StartSprinting_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Movement" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartSprinting constinit property declarations ************************
// ********** End Function StartSprinting constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "StartSprinting", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_StartSprinting(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execStartSprinting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartSprinting();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function StartSprinting **************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function StopSprinting *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_StopSprinting_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Movement" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopSprinting constinit property declarations *************************
// ********** End Function StopSprinting constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "StopSprinting", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_StopSprinting(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execStopSprinting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopSprinting();
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function StopSprinting ***************************

// ********** Begin Class ADMFPlayerAvatarCharacter Function TargetAndAttackDigimonFromActor *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_TargetAndAttackDigimonFromActor_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventTargetAndAttackDigimonFromActor_Parms
	{
		AActor* TargetActor;
		int32 SlotIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Accepts any Actor reference and atomically targets + commands the selected quick slot. */" },
#endif
		{ "CPP_Default_SlotIndex", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Accepts any Actor reference and atomically targets + commands the selected quick slot." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function TargetAndAttackDigimonFromActor constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventTargetAndAttackDigimonFromActor_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TargetAndAttackDigimonFromActor constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TargetAndAttackDigimonFromActor Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventTargetAndAttackDigimonFromActor_Parms, TargetActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventTargetAndAttackDigimonFromActor_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventTargetAndAttackDigimonFromActor_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function TargetAndAttackDigimonFromActor Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "TargetAndAttackDigimonFromActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventTargetAndAttackDigimonFromActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventTargetAndAttackDigimonFromActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_TargetAndAttackDigimonFromActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execTargetAndAttackDigimonFromActor)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->TargetAndAttackDigimonFromActor(Z_Param_TargetActor,Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function TargetAndAttackDigimonFromActor *********

// ********** Begin Class ADMFPlayerAvatarCharacter Function TargetDigimonFromActor ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFPlayerAvatarCharacter_TargetDigimonFromActor_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarCharacter_eventTargetDigimonFromActor_Parms
	{
		AActor* TargetActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Accepts any Actor reference and internally validates/casts it as a Digimon before selecting it. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Accepts any Actor reference and internally validates/casts it as a Digimon before selecting it." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function TargetDigimonFromActor constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarCharacter_eventTargetDigimonFromActor_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TargetDigimonFromActor constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TargetDigimonFromActor Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarCharacter_eventTargetDigimonFromActor_Parms, TargetActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarCharacter_eventTargetDigimonFromActor_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function TargetDigimonFromActor Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFPlayerAvatarCharacter, nullptr, "TargetDigimonFromActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarCharacter_eventTargetDigimonFromActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarCharacter_eventTargetDigimonFromActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFPlayerAvatarCharacter_TargetDigimonFromActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFPlayerAvatarCharacter::execTargetDigimonFromActor)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->TargetDigimonFromActor(Z_Param_TargetActor);
	P_NATIVE_END;
}
// ********** End Class ADMFPlayerAvatarCharacter Function TargetDigimonFromActor ******************

// ********** Begin Class ADMFPlayerAvatarCharacter ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFPlayerAvatarCharacter_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Ready-to-use replicated third-person player character for Digimon MMO Framework.\n *\n * Derive a Blueprint from this class, then customize movement/camera/animation as desired.\n * Player appearance is supplied by UDMFPlayerSkinData rather than swapping authoritative pawn classes.\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Game/DMFPlayerAvatarCharacter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ready-to-use replicated third-person player character for Digimon MMO Framework.\n\nDerive a Blueprint from this class, then customize movement/camera/animation as desired.\nPlayer appearance is supplied by UDMFPlayerSkinData rather than swapping authoritative pawn classes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnderwaterPostProcessComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Underwater Post Process" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Dedicated local-only underwater presentation component. It is unbound so it affects only this viewport when\n     * enabled, and framework code keeps every non-local avatar's copy disabled to avoid cross-player contamination.\n     */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dedicated local-only underwater presentation component. It is unbound so it affects only this viewport when\nenabled, and framework code keeps every non-local avatar's copy disabled to avoid cross-player contamination." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnderwaterDistanceFogComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Underwater Post Process" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Local-only exponential underwater fog used for real scene-distance visibility falloff. Remote avatar copies\n     * keep this disabled; the owning camera alone drives density from the active water body's replicated profile.\n     */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local-only exponential underwater fog used for real scene-distance visibility falloff. Remote avatar copies\nkeep this disabled; the owning camera alone drives density from the active water body's replicated profile." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NameplateWidgetComponent_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Nameplates" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Automatic client-side MMO username plate. It reads the replicated APlayerState display name and adds no custom RPC traffic. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatic client-side MMO username plate. It reads the replicated APlayerState display name and adds no custom RPC traffic." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableNativeThirdPersonInput_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Disable this in a Blueprint child when the project supplies its own Enhanced Input stack. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Disable this in a Blueprint child when the project supplies its own Enhanced Input stack." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Movement" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Movement" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseYawScale_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MousePitchScale_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Camera" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableNativeInteractionInput_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Ready-to-use E-key interaction. Disable this when the project uses Enhanced Input, then call Interact() directly.\n     * This setting is independent of bEnableNativeThirdPersonInput.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ready-to-use E-key interaction. Disable this when the project uses Enhanced Input, then call Interact() directly.\nThis setting is independent of bEnableNativeThirdPersonInput." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionDistance_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Trace" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum local trace distance used by Interact()/FindInteractionTarget(). */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum local trace distance used by Interact()/FindInteractionTarget()." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionSweepRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Trace" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sphere-sweep radius. Set to 0 for a strict line trace. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sphere-sweep radius. Set to 0 for a strict line trace." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionTraceChannel_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Trace" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInteractionTraceComplex_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Trace" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIgnoreActivePartnerDuringInteractionTrace_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Trace" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Prevent the player's own summoned partner from consuming the interaction trace. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Prevent the player's own summoned partner from consuming the interaction trace." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawDebugInteractionTrace_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Development-only visualization of the local interaction trace/sweep. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Development-only visualization of the local interaction trace/sweep." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAttackOnDigimonInteract_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Default Digimon interaction is target-only. Enable this only if one interaction press should also execute an ability.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default Digimon interaction is target-only. Enable this only if one interaction press should also execute an ability." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonInteractAttackSlotIndex_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction|Digimon" },
		{ "ClampMax", "3" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Zero-based quick slot used when bAttackOnDigimonInteract is enabled (0 = UI slot 1). */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Zero-based quick slot used when bAttackOnDigimonInteract is enabled (0 = UI slot 1)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInteractionResult_MetaData[] = {
		{ "Category", "Digimon MMO|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Single Blueprint event/delegate source for UI feedback, tutorials and interaction presentation. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Single Blueprint event/delegate source for UI feedback, tutorials and interaction presentation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseNativeSwimFallbackPose_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keeps the collision capsule upright while rotating only the skeletal mesh into a horizontal swim fallback. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keeps the collision capsule upright while rotating only the skeletal mesh into a horizontal swim fallback." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwimFallbackMeshRotationOffset_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Actor-space rotation added to the normal skin-relative mesh transform while swimming. */" },
#endif
		{ "EditCondition", "bUseNativeSwimFallbackPose" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Actor-space rotation added to the normal skin-relative mesh transform while swimming." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwimFallbackMeshLocationOffset_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional skin-specific positional correction applied while the native fallback pose is active. */" },
#endif
		{ "EditCondition", "bUseNativeSwimFallbackPose" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional skin-specific positional correction applied while the native fallback pose is active." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwimFallbackPoseInterpolationSpeed_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Presentation" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Smooth local transition speed into/out of the fallback swim pose. Set to zero for instant changes. */" },
#endif
		{ "EditCondition", "bUseNativeSwimFallbackPose" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Smooth local transition speed into/out of the fallback swim pose. Set to zero for instant changes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPitchSwimFallbackWithTravelDirection_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Underwater only: visually pitches the flattened mesh with vertical travel while leaving the capsule upright. */" },
#endif
		{ "EditCondition", "bUseNativeSwimFallbackPose" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Underwater only: visually pitches the flattened mesh with vertical travel while leaving the capsule upright." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumSwimFallbackTravelPitch_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Presentation" },
		{ "ClampMax", "89.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bUseNativeSwimFallbackPose && bPitchSwimFallbackWithTravelDirection" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSwimmingStateChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnUnderwaterStateChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLocalCameraUnderwaterChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Swimming|Underwater Post Process|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local presentation event; never replicated and never used as gameplay authority. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local presentation event; never replicated and never used as gameplay authority." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomDepthStencilValue_MetaData[] = {
		{ "Category", "Digimon MMO|Rendering|Cel Shading" },
		{ "ClampMax", "255" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stencil value written by all avatar mesh components while Custom Depth rendering is enabled. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stencil value written by all avatar mesh components while Custom Depth rendering is enabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSprinting_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveSwimmableWater_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsUnderwaterSwimming_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedSwimPresentationState_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Compact server-authored swim presentation state for remote observers. The owning client still predicts\n     * immediately, while non-owning copies use this state without depending on water-actor reference ordering.\n     * Remote mesh rotation itself is never replicated.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compact server-authored swim presentation state for remote observers. The owning client still predicts\nimmediately, while non-owning copies use this state without depending on water-actor reference ordering.\nRemote mesh rotation itself is never replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppliedPlayerSkinId_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastInteractionActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedPlayerFootstepSound_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFPlayerAvatarCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFPlayerAvatarCharacter constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnderwaterPostProcessComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnderwaterDistanceFogComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NameplateWidgetComponent;
	static void NewProp_bEnableNativeThirdPersonInput_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bEnableNativeThirdPersonInput = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableNativeThirdPersonInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MouseYawScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MousePitchScale;
	static void NewProp_bEnableNativeInteractionInput_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bEnableNativeInteractionInput = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableNativeInteractionInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionSweepRadius;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InteractionTraceChannel;
	static void NewProp_bInteractionTraceComplex_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bInteractionTraceComplex = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInteractionTraceComplex;
	static void NewProp_bIgnoreActivePartnerDuringInteractionTrace_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bIgnoreActivePartnerDuringInteractionTrace = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreActivePartnerDuringInteractionTrace;
	static void NewProp_bDrawDebugInteractionTrace_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bDrawDebugInteractionTrace = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawDebugInteractionTrace;
	static void NewProp_bAttackOnDigimonInteract_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bAttackOnDigimonInteract = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttackOnDigimonInteract;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigimonInteractAttackSlotIndex;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInteractionResult;
	static void NewProp_bUseNativeSwimFallbackPose_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bUseNativeSwimFallbackPose = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseNativeSwimFallbackPose;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SwimFallbackMeshRotationOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SwimFallbackMeshLocationOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SwimFallbackPoseInterpolationSpeed;
	static void NewProp_bPitchSwimFallbackWithTravelDirection_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bPitchSwimFallbackWithTravelDirection = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPitchSwimFallbackWithTravelDirection;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumSwimFallbackTravelPitch;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSwimmingStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnUnderwaterStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLocalCameraUnderwaterChanged;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CustomDepthStencilValue;
	static void NewProp_bIsSprinting_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bIsSprinting = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSprinting;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveSwimmableWater;
	static void NewProp_bIsUnderwaterSwimming_SetBit(void* Obj)
	{
		((ADMFPlayerAvatarCharacter*)Obj)->bIsUnderwaterSwimming = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsUnderwaterSwimming;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReplicatedSwimPresentationState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReplicatedSwimPresentationState;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AppliedPlayerSkinId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LastInteractionActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedPlayerFootstepSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFPlayerAvatarCharacter constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddCameraZoomInput"), .Pointer = &ADMFPlayerAvatarCharacter::execAddCameraZoomInput },
		{ .NameUTF8 = UTF8TEXT("AddSwimVerticalInput"), .Pointer = &ADMFPlayerAvatarCharacter::execAddSwimVerticalInput },
		{ .NameUTF8 = UTF8TEXT("ApplyPlayerSkinData"), .Pointer = &ADMFPlayerAvatarCharacter::execApplyPlayerSkinData },
		{ .NameUTF8 = UTF8TEXT("ClearDigimonTarget"), .Pointer = &ADMFPlayerAvatarCharacter::execClearDigimonTarget },
		{ .NameUTF8 = UTF8TEXT("CommandDigimonAbilitySlot"), .Pointer = &ADMFPlayerAvatarCharacter::execCommandDigimonAbilitySlot },
		{ .NameUTF8 = UTF8TEXT("FindInteractionTarget"), .Pointer = &ADMFPlayerAvatarCharacter::execFindInteractionTarget },
		{ .NameUTF8 = UTF8TEXT("GetActiveSwimmableWater"), .Pointer = &ADMFPlayerAvatarCharacter::execGetActiveSwimmableWater },
		{ .NameUTF8 = UTF8TEXT("GetAppliedPlayerSkinId"), .Pointer = &ADMFPlayerAvatarCharacter::execGetAppliedPlayerSkinId },
		{ .NameUTF8 = UTF8TEXT("GetCameraZoomDistance"), .Pointer = &ADMFPlayerAvatarCharacter::execGetCameraZoomDistance },
		{ .NameUTF8 = UTF8TEXT("GetCurrentDigimonTarget"), .Pointer = &ADMFPlayerAvatarCharacter::execGetCurrentDigimonTarget },
		{ .NameUTF8 = UTF8TEXT("GetInteractionPromptForActor"), .Pointer = &ADMFPlayerAvatarCharacter::execGetInteractionPromptForActor },
		{ .NameUTF8 = UTF8TEXT("GetLastInteractionActor"), .Pointer = &ADMFPlayerAvatarCharacter::execGetLastInteractionActor },
		{ .NameUTF8 = UTF8TEXT("GetPlayerSwimState"), .Pointer = &ADMFPlayerAvatarCharacter::execGetPlayerSwimState },
		{ .NameUTF8 = UTF8TEXT("GetUnderwaterPostProcessBlendWeight"), .Pointer = &ADMFPlayerAvatarCharacter::execGetUnderwaterPostProcessBlendWeight },
		{ .NameUTF8 = UTF8TEXT("Interact"), .Pointer = &ADMFPlayerAvatarCharacter::execInteract },
		{ .NameUTF8 = UTF8TEXT("InteractWithActor"), .Pointer = &ADMFPlayerAvatarCharacter::execInteractWithActor },
		{ .NameUTF8 = UTF8TEXT("InteractWithDigimon"), .Pointer = &ADMFPlayerAvatarCharacter::execInteractWithDigimon },
		{ .NameUTF8 = UTF8TEXT("InteractWithDigimonAndAttack"), .Pointer = &ADMFPlayerAvatarCharacter::execInteractWithDigimonAndAttack },
		{ .NameUTF8 = UTF8TEXT("InteractWithDigimonVendor"), .Pointer = &ADMFPlayerAvatarCharacter::execInteractWithDigimonVendor },
		{ .NameUTF8 = UTF8TEXT("InteractWithHealer"), .Pointer = &ADMFPlayerAvatarCharacter::execInteractWithHealer },
		{ .NameUTF8 = UTF8TEXT("InteractWithItemVendor"), .Pointer = &ADMFPlayerAvatarCharacter::execInteractWithItemVendor },
		{ .NameUTF8 = UTF8TEXT("IsLocalCameraUnderwater"), .Pointer = &ADMFPlayerAvatarCharacter::execIsLocalCameraUnderwater },
		{ .NameUTF8 = UTF8TEXT("IsSprinting"), .Pointer = &ADMFPlayerAvatarCharacter::execIsSprinting },
		{ .NameUTF8 = UTF8TEXT("IsSwimmingInWater"), .Pointer = &ADMFPlayerAvatarCharacter::execIsSwimmingInWater },
		{ .NameUTF8 = UTF8TEXT("IsSwimmingUnderwater"), .Pointer = &ADMFPlayerAvatarCharacter::execIsSwimmingUnderwater },
		{ .NameUTF8 = UTF8TEXT("LookPitch"), .Pointer = &ADMFPlayerAvatarCharacter::execLookPitch },
		{ .NameUTF8 = UTF8TEXT("LookYaw"), .Pointer = &ADMFPlayerAvatarCharacter::execLookYaw },
		{ .NameUTF8 = UTF8TEXT("MoveForward"), .Pointer = &ADMFPlayerAvatarCharacter::execMoveForward },
		{ .NameUTF8 = UTF8TEXT("MoveRight"), .Pointer = &ADMFPlayerAvatarCharacter::execMoveRight },
		{ .NameUTF8 = UTF8TEXT("MulticastPlayPlayerFootstep"), .Pointer = &ADMFPlayerAvatarCharacter::execMulticastPlayPlayerFootstep },
		{ .NameUTF8 = UTF8TEXT("OnRep_ActiveSwimmableWater"), .Pointer = &ADMFPlayerAvatarCharacter::execOnRep_ActiveSwimmableWater },
		{ .NameUTF8 = UTF8TEXT("OnRep_ReplicatedSwimPresentationState"), .Pointer = &ADMFPlayerAvatarCharacter::execOnRep_ReplicatedSwimPresentationState },
		{ .NameUTF8 = UTF8TEXT("OnRep_Sprinting"), .Pointer = &ADMFPlayerAvatarCharacter::execOnRep_Sprinting },
		{ .NameUTF8 = UTF8TEXT("OnRep_UnderwaterSwimming"), .Pointer = &ADMFPlayerAvatarCharacter::execOnRep_UnderwaterSwimming },
		{ .NameUTF8 = UTF8TEXT("PlayPlayerFootstepLocal"), .Pointer = &ADMFPlayerAvatarCharacter::execPlayPlayerFootstepLocal },
		{ .NameUTF8 = UTF8TEXT("RebuildSwimmingStateFromWorld"), .Pointer = &ADMFPlayerAvatarCharacter::execRebuildSwimmingStateFromWorld },
		{ .NameUTF8 = UTF8TEXT("RefreshCameraCollisionPolicy"), .Pointer = &ADMFPlayerAvatarCharacter::execRefreshCameraCollisionPolicy },
		{ .NameUTF8 = UTF8TEXT("RefreshFrameworkCustomDepth"), .Pointer = &ADMFPlayerAvatarCharacter::execRefreshFrameworkCustomDepth },
		{ .NameUTF8 = UTF8TEXT("RefreshSwimmingPresentation"), .Pointer = &ADMFPlayerAvatarCharacter::execRefreshSwimmingPresentation },
		{ .NameUTF8 = UTF8TEXT("RefreshUnderwaterPostProcessPresentation"), .Pointer = &ADMFPlayerAvatarCharacter::execRefreshUnderwaterPostProcessPresentation },
		{ .NameUTF8 = UTF8TEXT("RefreshWorldNameplate"), .Pointer = &ADMFPlayerAvatarCharacter::execRefreshWorldNameplate },
		{ .NameUTF8 = UTF8TEXT("RegisterSwimmableWaterOverlap"), .Pointer = &ADMFPlayerAvatarCharacter::execRegisterSwimmableWaterOverlap },
		{ .NameUTF8 = UTF8TEXT("ResetCameraZoom"), .Pointer = &ADMFPlayerAvatarCharacter::execResetCameraZoom },
		{ .NameUTF8 = UTF8TEXT("ResetNativeInputState"), .Pointer = &ADMFPlayerAvatarCharacter::execResetNativeInputState },
		{ .NameUTF8 = UTF8TEXT("ServerSetSprinting"), .Pointer = &ADMFPlayerAvatarCharacter::execServerSetSprinting },
		{ .NameUTF8 = UTF8TEXT("SetCameraZoomDistance"), .Pointer = &ADMFPlayerAvatarCharacter::execSetCameraZoomDistance },
		{ .NameUTF8 = UTF8TEXT("StartSprinting"), .Pointer = &ADMFPlayerAvatarCharacter::execStartSprinting },
		{ .NameUTF8 = UTF8TEXT("StopSprinting"), .Pointer = &ADMFPlayerAvatarCharacter::execStopSprinting },
		{ .NameUTF8 = UTF8TEXT("TargetAndAttackDigimonFromActor"), .Pointer = &ADMFPlayerAvatarCharacter::execTargetAndAttackDigimonFromActor },
		{ .NameUTF8 = UTF8TEXT("TargetDigimonFromActor"), .Pointer = &ADMFPlayerAvatarCharacter::execTargetDigimonFromActor },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_AddCameraZoomInput, "AddCameraZoomInput" }, // bfb6514da914f00193291d28eac501b5e7b1ac38
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_AddSwimVerticalInput, "AddSwimVerticalInput" }, // da6ec9d029d278e8b8f7fdbfbe64c9886613c7a6
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ApplyPlayerSkinData, "ApplyPlayerSkinData" }, // b156fffa16470599d7bb776cf154be9f84448931
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnDigimonInteracted, "BP_OnDigimonInteracted" }, // 6899616f8c0139696dd36604bfff3087621cf6ba
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnLocalCameraUnderwaterChanged, "BP_OnLocalCameraUnderwaterChanged" }, // 9c9e1321fd49cd7edb5a69ced5bcda80fb7aa9a5
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinApplied, "BP_OnPlayerSkinApplied" }, // f099fc8c9c726805a653fedc0730df5a216f0f5a
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnPlayerSkinRefreshRequested, "BP_OnPlayerSkinRefreshRequested" }, // b6c3b85b6d1ac41d1af62edd081924a6858c724a
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnSwimmingStateChanged, "BP_OnSwimmingStateChanged" }, // 24a14809cdcf87cac3d5a962f1dce5f61bd95ef5
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnUnderwaterStateChanged, "BP_OnUnderwaterStateChanged" }, // 028707d7b134a1b72669a689ae68e75d7f4b5a20
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_BP_OnUnhandledInteraction, "BP_OnUnhandledInteraction" }, // c2d3f5fc7f26461c47d3fd176f66888b697d2e2e
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ClearDigimonTarget, "ClearDigimonTarget" }, // ae2ae474883a4eea06f66390b2f3750b26e6016e
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_CommandDigimonAbilitySlot, "CommandDigimonAbilitySlot" }, // b1b8ba8eaa658c15fbe0ca8ddb92cea4cd231b26
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_FindInteractionTarget, "FindInteractionTarget" }, // 7cb778a18d8596f948c5ac968359bbf10c6e1261
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetActiveSwimmableWater, "GetActiveSwimmableWater" }, // fb3b70111f9941be367819f164e41b4286fdc7f2
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetAppliedPlayerSkinId, "GetAppliedPlayerSkinId" }, // 6a5b26f98a1d42b23c41f46163bd4440495eb15c
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetCameraZoomDistance, "GetCameraZoomDistance" }, // a8c2ce144978120dd4ad1b4175fa515c58a24104
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetCurrentDigimonTarget, "GetCurrentDigimonTarget" }, // 5091ad59213a2ce20af42a1feb3d5e2ecac24f9c
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetInteractionPromptForActor, "GetInteractionPromptForActor" }, // bf839a5483d6b9dfb26bdc0d939424f9c756ebeb
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetLastInteractionActor, "GetLastInteractionActor" }, // f0e91a3764b19ba511d16c335cef1fd87a8fed56
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetPlayerSwimState, "GetPlayerSwimState" }, // af9c06d1c89b17c91f5d679f755c2f2858d1040b
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_GetUnderwaterPostProcessBlendWeight, "GetUnderwaterPostProcessBlendWeight" }, // c8b09e7cbee27ee606a54a4aecb6c4fddb9db47d
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_Interact, "Interact" }, // 38140c6bb7cbf9de1e36f20d7c8fc5632b9e882b
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithActor, "InteractWithActor" }, // 5515eae62994f074bb56bfae169499a35856a713
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithDigimon, "InteractWithDigimon" }, // d14e7f3cac65393d8a6e31cdc048df6208f4193a
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithDigimonAndAttack, "InteractWithDigimonAndAttack" }, // 4deabc5bd74403005827807e1912cb22b0744087
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithDigimonVendor, "InteractWithDigimonVendor" }, // a7a69c40594c2c42faddffe31b34ad1895fee291
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithHealer, "InteractWithHealer" }, // d320eceb55596c6dd94ea24f57ad2e5ef052c780
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_InteractWithItemVendor, "InteractWithItemVendor" }, // e75a50c39a591db8ee7d1c2a09c38f132defeef7
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsLocalCameraUnderwater, "IsLocalCameraUnderwater" }, // c2ccf6e304b6ee8c501c738f193487975854de3c
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsSprinting, "IsSprinting" }, // ffad58daf6e8b34b9f32239f98200a2bf293c008
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsSwimmingInWater, "IsSwimmingInWater" }, // e23cbbb621af0d362eb5b5f0409199062370a0ad
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_IsSwimmingUnderwater, "IsSwimmingUnderwater" }, // 237c44f18c20a2c96e76957f4a41dd0df4d19410
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_LookPitch, "LookPitch" }, // 2411bd30c8f9a4954443bcdcc1edb1ef23ea34fe
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_LookYaw, "LookYaw" }, // 5d990d7670bf5227e56f63c4f6e92a2a484fc4a8
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_MoveForward, "MoveForward" }, // 4b28b6e0abb7ee103b68a72f0652af3e837210c9
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_MoveRight, "MoveRight" }, // 7ba866a1b9cffb870d488569b3da898d4d04a77d
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_MulticastPlayPlayerFootstep, "MulticastPlayPlayerFootstep" }, // ca6d25487b067e7963fa7ca33a031ed95f6b26cd
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_ActiveSwimmableWater, "OnRep_ActiveSwimmableWater" }, // bdb56a76cccdf85a8c8014147861bb6dc82267f4
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_ReplicatedSwimPresentationState, "OnRep_ReplicatedSwimPresentationState" }, // c44a9beeb8dc32931ba5229aa43cf540aa3de290
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_Sprinting, "OnRep_Sprinting" }, // 3276587a1c3ec52175887967c00c53dc0068cfe0
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_OnRep_UnderwaterSwimming, "OnRep_UnderwaterSwimming" }, // 29df454a9bac2d0303ec3008868722cabd2f132f
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_PlayPlayerFootstepLocal, "PlayPlayerFootstepLocal" }, // c525c73e9c46e553e7fc2f91e5040137bc3be649
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RebuildSwimmingStateFromWorld, "RebuildSwimmingStateFromWorld" }, // 7ce102228db143cf78fbeb05189b56f18301e89f
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshCameraCollisionPolicy, "RefreshCameraCollisionPolicy" }, // b15ed5db1902621ad5ad90c19214795cb9f374ee
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshFrameworkCustomDepth, "RefreshFrameworkCustomDepth" }, // 82ed465b5a8dc30a6b50f8fc50fc512aeb7b7eb2
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshSwimmingPresentation, "RefreshSwimmingPresentation" }, // 55ea5ca6ccc165aaae43dea91d34ffc8f3d1fe12
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshUnderwaterPostProcessPresentation, "RefreshUnderwaterPostProcessPresentation" }, // 985a100af68947e8947efc6564b5a0238132fc79
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RefreshWorldNameplate, "RefreshWorldNameplate" }, // cb47dc40b54e6bd40a047d5f62ea4b3e0c6dcb01
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_RegisterSwimmableWaterOverlap, "RegisterSwimmableWaterOverlap" }, // 984d2ab7917d9cc20da47f93895f6080ce9e85d6
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ResetCameraZoom, "ResetCameraZoom" }, // af8c7d9d9eba5f9e827fa83fdb81a76a89121721
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ResetNativeInputState, "ResetNativeInputState" }, // 3bae772d7a61997b6ab04490de3cc459cf8b7bb0
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_ServerSetSprinting, "ServerSetSprinting" }, // e35b8284bc15b0222ab1c719a7c631c9de2a5033
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_SetCameraZoomDistance, "SetCameraZoomDistance" }, // a0dc164736c319c9f5b148223a2258b209eafd6a
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_StartSprinting, "StartSprinting" }, // a4b131e002fc083c2ac26835c41f1a11f339df4b
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_StopSprinting, "StopSprinting" }, // 4da3110ff89b1452ad76545e23015a5d123c56d2
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_TargetAndAttackDigimonFromActor, "TargetAndAttackDigimonFromActor" }, // 34de0f17cbbfe6b0ae34e9e89a05dfc3122a0482
		{ &Z_Construct_UFunction_ADMFPlayerAvatarCharacter_TargetDigimonFromActor, "TargetDigimonFromActor" }, // 63ecc3774a973bacd4a02c88b63e0f32e8fa7280
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFPlayerAvatarCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFPlayerAvatarCharacter Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_UnderwaterPostProcessComponent = { "UnderwaterPostProcessComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, UnderwaterPostProcessComponent), Z_Construct_UClass_UPostProcessComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnderwaterPostProcessComponent_MetaData), NewProp_UnderwaterPostProcessComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_UnderwaterDistanceFogComponent = { "UnderwaterDistanceFogComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, UnderwaterDistanceFogComponent), Z_Construct_UClass_UExponentialHeightFogComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnderwaterDistanceFogComponent_MetaData), NewProp_UnderwaterDistanceFogComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NameplateWidgetComponent = { "NameplateWidgetComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, NameplateWidgetComponent), Z_Construct_UClass_UWidgetComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NameplateWidgetComponent_MetaData), NewProp_NameplateWidgetComponent_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableNativeThirdPersonInput = { "bEnableNativeThirdPersonInput", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bEnableNativeThirdPersonInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableNativeThirdPersonInput_MetaData), NewProp_bEnableNativeThirdPersonInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSpeed_MetaData), NewProp_SprintSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MouseYawScale = { "MouseYawScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, MouseYawScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseYawScale_MetaData), NewProp_MouseYawScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MousePitchScale = { "MousePitchScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, MousePitchScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MousePitchScale_MetaData), NewProp_MousePitchScale_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableNativeInteractionInput = { "bEnableNativeInteractionInput", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bEnableNativeInteractionInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableNativeInteractionInput_MetaData), NewProp_bEnableNativeInteractionInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InteractionDistance = { "InteractionDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, InteractionDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionDistance_MetaData), NewProp_InteractionDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InteractionSweepRadius = { "InteractionSweepRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, InteractionSweepRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionSweepRadius_MetaData), NewProp_InteractionSweepRadius_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InteractionTraceChannel = { "InteractionTraceChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, InteractionTraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionTraceChannel_MetaData), NewProp_InteractionTraceChannel_MetaData) }; // 3aff698625c18cc2ccaa87a587b2eac8c50cdec7
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInteractionTraceComplex = { "bInteractionTraceComplex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bInteractionTraceComplex_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInteractionTraceComplex_MetaData), NewProp_bInteractionTraceComplex_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIgnoreActivePartnerDuringInteractionTrace = { "bIgnoreActivePartnerDuringInteractionTrace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bIgnoreActivePartnerDuringInteractionTrace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIgnoreActivePartnerDuringInteractionTrace_MetaData), NewProp_bIgnoreActivePartnerDuringInteractionTrace_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDrawDebugInteractionTrace = { "bDrawDebugInteractionTrace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bDrawDebugInteractionTrace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawDebugInteractionTrace_MetaData), NewProp_bDrawDebugInteractionTrace_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAttackOnDigimonInteract = { "bAttackOnDigimonInteract", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bAttackOnDigimonInteract_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAttackOnDigimonInteract_MetaData), NewProp_bAttackOnDigimonInteract_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigimonInteractAttackSlotIndex = { "DigimonInteractAttackSlotIndex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, DigimonInteractAttackSlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonInteractAttackSlotIndex_MetaData), NewProp_DigimonInteractAttackSlotIndex_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnInteractionResult = { "OnInteractionResult", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, OnInteractionResult), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerInteractionResult__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInteractionResult_MetaData), NewProp_OnInteractionResult_MetaData) }; // f2c8b4adafdbd85d5b146c83ba6653b9c9a4efc4
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUseNativeSwimFallbackPose = { "bUseNativeSwimFallbackPose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bUseNativeSwimFallbackPose_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseNativeSwimFallbackPose_MetaData), NewProp_bUseNativeSwimFallbackPose_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SwimFallbackMeshRotationOffset = { "SwimFallbackMeshRotationOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, SwimFallbackMeshRotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwimFallbackMeshRotationOffset_MetaData), NewProp_SwimFallbackMeshRotationOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SwimFallbackMeshLocationOffset = { "SwimFallbackMeshLocationOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, SwimFallbackMeshLocationOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwimFallbackMeshLocationOffset_MetaData), NewProp_SwimFallbackMeshLocationOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SwimFallbackPoseInterpolationSpeed = { "SwimFallbackPoseInterpolationSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, SwimFallbackPoseInterpolationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwimFallbackPoseInterpolationSpeed_MetaData), NewProp_SwimFallbackPoseInterpolationSpeed_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPitchSwimFallbackWithTravelDirection = { "bPitchSwimFallbackWithTravelDirection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bPitchSwimFallbackWithTravelDirection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPitchSwimFallbackWithTravelDirection_MetaData), NewProp_bPitchSwimFallbackWithTravelDirection_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumSwimFallbackTravelPitch = { "MaximumSwimFallbackTravelPitch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, MaximumSwimFallbackTravelPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumSwimFallbackTravelPitch_MetaData), NewProp_MaximumSwimFallbackTravelPitch_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnSwimmingStateChanged = { "OnSwimmingStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, OnSwimmingStateChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSwimmingStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSwimmingStateChanged_MetaData), NewProp_OnSwimmingStateChanged_MetaData) }; // e03dcea6eecb8b0e301e4861aff2cc2581b2fc6d
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnUnderwaterStateChanged = { "OnUnderwaterStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, OnUnderwaterStateChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerUnderwaterStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnUnderwaterStateChanged_MetaData), NewProp_OnUnderwaterStateChanged_MetaData) }; // 852ac97d8d9fc8f790c530a007d8b51f8009a4e5
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnLocalCameraUnderwaterChanged = { "OnLocalCameraUnderwaterChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, OnLocalCameraUnderwaterChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFLocalCameraUnderwaterChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLocalCameraUnderwaterChanged_MetaData), NewProp_OnLocalCameraUnderwaterChanged_MetaData) }; // b6423ef4e633a71ebda2f0e1f75304d4634166ed
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CustomDepthStencilValue = { "CustomDepthStencilValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, CustomDepthStencilValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomDepthStencilValue_MetaData), NewProp_CustomDepthStencilValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsSprinting = { "bIsSprinting", "OnRep_Sprinting", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bIsSprinting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSprinting_MetaData), NewProp_bIsSprinting_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActiveSwimmableWater = { "ActiveSwimmableWater", "OnRep_ActiveSwimmableWater", (EPropertyFlags)0x0144000100000020, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, ActiveSwimmableWater), Z_Construct_UClass_ADMFSwimmableWater, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveSwimmableWater_MetaData), NewProp_ActiveSwimmableWater_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsUnderwaterSwimming = { "bIsUnderwaterSwimming", "OnRep_UnderwaterSwimming", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFPlayerAvatarCharacter), &UHT_STATICS::NewProp_bIsUnderwaterSwimming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsUnderwaterSwimming_MetaData), NewProp_bIsUnderwaterSwimming_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReplicatedSwimPresentationState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReplicatedSwimPresentationState = { "ReplicatedSwimPresentationState", "OnRep_ReplicatedSwimPresentationState", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, ReplicatedSwimPresentationState), Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerSwimState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedSwimPresentationState_MetaData), NewProp_ReplicatedSwimPresentationState_MetaData) }; // 0a5b30d859e51114bbcf929f592369a79b6c9afb
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_AppliedPlayerSkinId = { "AppliedPlayerSkinId", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, AppliedPlayerSkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppliedPlayerSkinId_MetaData), NewProp_AppliedPlayerSkinId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_LastInteractionActor = { "LastInteractionActor", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, LastInteractionActor), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastInteractionActor_MetaData), NewProp_LastInteractionActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CachedPlayerFootstepSound = { "CachedPlayerFootstepSound", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFPlayerAvatarCharacter, CachedPlayerFootstepSound), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedPlayerFootstepSound_MetaData), NewProp_CachedPlayerFootstepSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UnderwaterPostProcessComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UnderwaterDistanceFogComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NameplateWidgetComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableNativeThirdPersonInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SprintSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MouseYawScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MousePitchScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableNativeInteractionInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionSweepRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionTraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInteractionTraceComplex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIgnoreActivePartnerDuringInteractionTrace,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDrawDebugInteractionTrace,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAttackOnDigimonInteract,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInteractAttackSlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnInteractionResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUseNativeSwimFallbackPose,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SwimFallbackMeshRotationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SwimFallbackMeshLocationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SwimFallbackPoseInterpolationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPitchSwimFallbackWithTravelDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumSwimFallbackTravelPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnSwimmingStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnUnderwaterStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnLocalCameraUnderwaterChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CustomDepthStencilValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsSprinting,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActiveSwimmableWater,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsUnderwaterSwimming,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedSwimPresentationState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedSwimPresentationState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AppliedPlayerSkinId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastInteractionActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CachedPlayerFootstepSound,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFPlayerAvatarCharacter Property Definitions *****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_ACharacter,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFPlayerAvatarCharacter,
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
static void ADMFPlayerAvatarCharacter_StaticRegisterNativesADMFPlayerAvatarCharacter()
{
	UClass* Class = ADMFPlayerAvatarCharacter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFPlayerAvatarCharacter;
UClass* Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFPlayerAvatarCharacter;
		if (!Z_Registration_Info_UClass_ADMFPlayerAvatarCharacter.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFPlayerAvatarCharacter"),
				Z_Registration_Info_UClass_ADMFPlayerAvatarCharacter.InnerSingleton,
				ADMFPlayerAvatarCharacter_StaticRegisterNativesADMFPlayerAvatarCharacter,
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
		return Z_Registration_Info_UClass_ADMFPlayerAvatarCharacter.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFPlayerAvatarCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFPlayerAvatarCharacter.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFPlayerAvatarCharacter.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFPlayerAvatarCharacter::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_bIsSprinting(TEXT("bIsSprinting"));
	static FName Name_ActiveSwimmableWater(TEXT("ActiveSwimmableWater"));
	static FName Name_bIsUnderwaterSwimming(TEXT("bIsUnderwaterSwimming"));
	static FName Name_ReplicatedSwimPresentationState(TEXT("ReplicatedSwimPresentationState"));
	const bool bIsValid = true
		&& Name_bIsSprinting == ClassReps[(int32)ENetFields_Private::bIsSprinting].Property->GetFName()
		&& Name_ActiveSwimmableWater == ClassReps[(int32)ENetFields_Private::ActiveSwimmableWater].Property->GetFName()
		&& Name_bIsUnderwaterSwimming == ClassReps[(int32)ENetFields_Private::bIsUnderwaterSwimming].Property->GetFName()
		&& Name_ReplicatedSwimPresentationState == ClassReps[(int32)ENetFields_Private::ReplicatedSwimPresentationState].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFPlayerAvatarCharacter"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFPlayerAvatarCharacter);
ADMFPlayerAvatarCharacter::~ADMFPlayerAvatarCharacter() {}
// ********** End Class ADMFPlayerAvatarCharacter **************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFPlayerAvatarCharacter, TEXT("ADMFPlayerAvatarCharacter"), &Z_Registration_Info_UClass_ADMFPlayerAvatarCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFPlayerAvatarCharacter), 417926642U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFPlayerAvatarCharacter_h__Script_DigimonMMOFramework_59b6c8e8d382310186b472097bb5dc1607a7a520{
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
