// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "DMFTypes.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFPlayerAvatarComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UActorComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFAccountRecord(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerAvatarComponent(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinRequirementChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinSelectionResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerAvatarComponent(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFPlayerSkinChanged *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFPlayerSkinChanged_Parms
	{
		FPrimaryAssetId SkinId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFPlayerSkinChanged constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFPlayerSkinChanged constinit property declarations *******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFPlayerSkinChanged Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFPlayerSkinChanged_Parms, SkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFPlayerSkinChanged Property Definitions ******************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFPlayerSkinChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSkinChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSkinChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFPlayerSkinChanged ***************************************************

// ********** Begin Delegate FDMFPlayerSkinRequirementChanged **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinRequirementChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFPlayerSkinRequirementChanged_Parms
	{
		bool bSelectionRequired;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFPlayerSkinRequirementChanged constinit property declarations ******
	static void NewProp_bSelectionRequired_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFPlayerSkinRequirementChanged_Parms*)Obj)->bSelectionRequired = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSelectionRequired;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFPlayerSkinRequirementChanged constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFPlayerSkinRequirementChanged Property Definitions *****************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSelectionRequired = { "bSelectionRequired", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFPlayerSkinRequirementChanged_Parms), &UHT_STATICS::NewProp_bSelectionRequired_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSelectionRequired,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFPlayerSkinRequirementChanged Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFPlayerSkinRequirementChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSkinRequirementChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSkinRequirementChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinRequirementChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFPlayerSkinRequirementChanged ****************************************

// ********** Begin Delegate FDMFPlayerSkinSelectionResult *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinSelectionResult__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFPlayerSkinSelectionResult_Parms
	{
		bool bSuccess;
		FText Message;
		FPrimaryAssetId SkinId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFPlayerSkinSelectionResult constinit property declarations *********
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFPlayerSkinSelectionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFPlayerSkinSelectionResult constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFPlayerSkinSelectionResult Property Definitions ********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFPlayerSkinSelectionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFPlayerSkinSelectionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFPlayerSkinSelectionResult_Parms, SkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFPlayerSkinSelectionResult Property Definitions **********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFPlayerSkinSelectionResult__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSkinSelectionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSkinSelectionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinSelectionResult__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFPlayerSkinSelectionResult *******************************************

// ********** Begin Class UDMFPlayerAvatarComponent Function ApplyCurrentWorldLocationToAccountRecord 
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_ApplyCurrentWorldLocationToAccountRecord_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventApplyCurrentWorldLocationToAccountRecord_Parms
	{
		FDMFAccountRecord Record;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Captures the currently possessed framework avatar's authoritative map/location/rotation into the supplied account.\n     * Returns false when no valid gameplay avatar exists or location persistence is disabled.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Captures the currently possessed framework avatar's authoritative map/location/rotation into the supplied account.\nReturns false when no valid gameplay avatar exists or location persistence is disabled." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyCurrentWorldLocationToAccountRecord constinit property declarations 
	static const UECodeGen_Private::FStructPropertyParams NewProp_Record;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarComponent_eventApplyCurrentWorldLocationToAccountRecord_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyCurrentWorldLocationToAccountRecord constinit property declarations 
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyCurrentWorldLocationToAccountRecord Property Definitions *********
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Record = { "Record", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventApplyCurrentWorldLocationToAccountRecord_Parms, Record), Z_Construct_UScriptStruct_FDMFAccountRecord, METADATA_PARAMS(0, nullptr) }; // 2f856c422aaed141d21fa44341bcd0445e707cc8
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarComponent_eventApplyCurrentWorldLocationToAccountRecord_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Record,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplyCurrentWorldLocationToAccountRecord Property Definitions ***********
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "ApplyCurrentWorldLocationToAccountRecord", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventApplyCurrentWorldLocationToAccountRecord_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventApplyCurrentWorldLocationToAccountRecord_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_ApplyCurrentWorldLocationToAccountRecord(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execApplyCurrentWorldLocationToAccountRecord)
{
	P_GET_STRUCT_REF(FDMFAccountRecord,Z_Param_Out_Record);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ApplyCurrentWorldLocationToAccountRecord(Z_Param_Out_Record);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function ApplyCurrentWorldLocationToAccountRecord 

// ********** Begin Class UDMFPlayerAvatarComponent Function ApplySelectedSkinToCurrentPawn ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_ApplySelectedSkinToCurrentPawn_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventApplySelectedSkinToCurrentPawn_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-applies the replicated selected skin to the currently possessed framework avatar pawn. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-applies the replicated selected skin to the currently possessed framework avatar pawn." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ApplySelectedSkinToCurrentPawn constinit property declarations ********
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarComponent_eventApplySelectedSkinToCurrentPawn_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplySelectedSkinToCurrentPawn constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplySelectedSkinToCurrentPawn Property Definitions *******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarComponent_eventApplySelectedSkinToCurrentPawn_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplySelectedSkinToCurrentPawn Property Definitions *********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "ApplySelectedSkinToCurrentPawn", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventApplySelectedSkinToCurrentPawn_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventApplySelectedSkinToCurrentPawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_ApplySelectedSkinToCurrentPawn(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execApplySelectedSkinToCurrentPawn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ApplySelectedSkinToCurrentPawn();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function ApplySelectedSkinToCurrentPawn **********

// ********** Begin Class UDMFPlayerAvatarComponent Function ApplyToAccountRecord ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_ApplyToAccountRecord_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventApplyToAccountRecord_Parms
	{
		FDMFAccountRecord Record;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Persistence" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyToAccountRecord constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Record;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyToAccountRecord constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyToAccountRecord Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Record = { "Record", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventApplyToAccountRecord_Parms, Record), Z_Construct_UScriptStruct_FDMFAccountRecord, METADATA_PARAMS(0, nullptr) }; // 2f856c422aaed141d21fa44341bcd0445e707cc8
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Record,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplyToAccountRecord Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "ApplyToAccountRecord", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventApplyToAccountRecord_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventApplyToAccountRecord_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_ApplyToAccountRecord(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execApplyToAccountRecord)
{
	P_GET_STRUCT_REF(FDMFAccountRecord,Z_Param_Out_Record);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyToAccountRecord(Z_Param_Out_Record);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function ApplyToAccountRecord ********************

// ********** Begin Class UDMFPlayerAvatarComponent Function ClientPlayerSkinSelectionResult *******
struct DMFPlayerAvatarComponent_eventClientPlayerSkinSelectionResult_Parms
{
	bool bSuccess;
	FText Message;
	FPrimaryAssetId SkinId;
};
static FName NAME_UDMFPlayerAvatarComponent_ClientPlayerSkinSelectionResult = FName(TEXT("ClientPlayerSkinSelectionResult"));
void UDMFPlayerAvatarComponent::ClientPlayerSkinSelectionResult(bool bSuccess, FText const& Message, FPrimaryAssetId SkinId)
{
	DMFPlayerAvatarComponent_eventClientPlayerSkinSelectionResult_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Message=Message;
	Parms.SkinId=SkinId;
	UFunction* Func = FindFunctionChecked(NAME_UDMFPlayerAvatarComponent_ClientPlayerSkinSelectionResult);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_ClientPlayerSkinSelectionResult_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClientPlayerSkinSelectionResult constinit property declarations *******
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFPlayerAvatarComponent_eventClientPlayerSkinSelectionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientPlayerSkinSelectionResult constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientPlayerSkinSelectionResult Property Definitions ******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarComponent_eventClientPlayerSkinSelectionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventClientPlayerSkinSelectionResult_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventClientPlayerSkinSelectionResult_Parms, SkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientPlayerSkinSelectionResult Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "ClientPlayerSkinSelectionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerAvatarComponent_eventClientPlayerSkinSelectionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerAvatarComponent_eventClientPlayerSkinSelectionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_ClientPlayerSkinSelectionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execClientPlayerSkinSelectionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SkinId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientPlayerSkinSelectionResult_Implementation(Z_Param_bSuccess,Z_Param_Message,Z_Param_SkinId);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function ClientPlayerSkinSelectionResult *********

// ********** Begin Class UDMFPlayerAvatarComponent Function GetAvailablePlayerSkins ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_GetAvailablePlayerSkins_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventGetAvailablePlayerSkins_Parms
	{
		TArray<UDMFPlayerSkinData*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns all enabled registered player-skin Data Assets sorted by DisplayOrder/name. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns all enabled registered player-skin Data Assets sorted by DisplayOrder/name." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAvailablePlayerSkins constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAvailablePlayerSkins constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAvailablePlayerSkins Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMFPlayerSkinData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventGetAvailablePlayerSkins_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAvailablePlayerSkins Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "GetAvailablePlayerSkins", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventGetAvailablePlayerSkins_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventGetAvailablePlayerSkins_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_GetAvailablePlayerSkins(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execGetAvailablePlayerSkins)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UDMFPlayerSkinData*>*)Z_Param__Result=P_THIS->GetAvailablePlayerSkins();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function GetAvailablePlayerSkins *****************

// ********** Begin Class UDMFPlayerAvatarComponent Function GetSelectedPlayerSkinId ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_GetSelectedPlayerSkinId_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventGetSelectedPlayerSkinId_Parms
	{
		FPrimaryAssetId ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedPlayerSkinId constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedPlayerSkinId constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedPlayerSkinId Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventGetSelectedPlayerSkinId_Parms, ReturnValue), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSelectedPlayerSkinId Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "GetSelectedPlayerSkinId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventGetSelectedPlayerSkinId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventGetSelectedPlayerSkinId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_GetSelectedPlayerSkinId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execGetSelectedPlayerSkinId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPrimaryAssetId*)Z_Param__Result=P_THIS->GetSelectedPlayerSkinId();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function GetSelectedPlayerSkinId *****************

// ********** Begin Class UDMFPlayerAvatarComponent Function InitializeFromAccountRecord ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_InitializeFromAccountRecord_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventInitializeFromAccountRecord_Parms
	{
		FDMFAccountRecord Record;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Persistence" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Record_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeFromAccountRecord constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Record;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeFromAccountRecord constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeFromAccountRecord Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Record = { "Record", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventInitializeFromAccountRecord_Parms, Record), Z_Construct_UScriptStruct_FDMFAccountRecord, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Record_MetaData), NewProp_Record_MetaData) }; // 2f856c422aaed141d21fa44341bcd0445e707cc8
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Record,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeFromAccountRecord Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "InitializeFromAccountRecord", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventInitializeFromAccountRecord_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventInitializeFromAccountRecord_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_InitializeFromAccountRecord(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execInitializeFromAccountRecord)
{
	P_GET_STRUCT_REF(FDMFAccountRecord,Z_Param_Out_Record);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeFromAccountRecord(Z_Param_Out_Record);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function InitializeFromAccountRecord *************

// ********** Begin Class UDMFPlayerAvatarComponent Function IsPlayerSkinSelectionRequired *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_IsPlayerSkinSelectionRequired_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventIsPlayerSkinSelectionRequired_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPlayerSkinSelectionRequired constinit property declarations *********
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarComponent_eventIsPlayerSkinSelectionRequired_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPlayerSkinSelectionRequired constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPlayerSkinSelectionRequired Property Definitions ********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarComponent_eventIsPlayerSkinSelectionRequired_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsPlayerSkinSelectionRequired Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "IsPlayerSkinSelectionRequired", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventIsPlayerSkinSelectionRequired_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventIsPlayerSkinSelectionRequired_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_IsPlayerSkinSelectionRequired(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execIsPlayerSkinSelectionRequired)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayerSkinSelectionRequired();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function IsPlayerSkinSelectionRequired ***********

// ********** Begin Class UDMFPlayerAvatarComponent Function OnRep_PlayerSkinSelectionRequired *****
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_OnRep_PlayerSkinSelectionRequired_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_PlayerSkinSelectionRequired constinit property declarations *****
// ********** End Function OnRep_PlayerSkinSelectionRequired constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "OnRep_PlayerSkinSelectionRequired", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_OnRep_PlayerSkinSelectionRequired(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execOnRep_PlayerSkinSelectionRequired)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_PlayerSkinSelectionRequired();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function OnRep_PlayerSkinSelectionRequired *******

// ********** Begin Class UDMFPlayerAvatarComponent Function OnRep_SelectedPlayerSkinId ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_OnRep_SelectedPlayerSkinId_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_SelectedPlayerSkinId constinit property declarations ************
// ********** End Function OnRep_SelectedPlayerSkinId constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "OnRep_SelectedPlayerSkinId", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_OnRep_SelectedPlayerSkinId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execOnRep_SelectedPlayerSkinId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_SelectedPlayerSkinId();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function OnRep_SelectedPlayerSkinId **************

// ********** Begin Class UDMFPlayerAvatarComponent Function ResetPlayerSkinSelection **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_ResetPlayerSkinSelection_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventResetPlayerSkinSelection_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|Admin" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server/admin recovery hook. If cleared, the owning player is required to select again. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server/admin recovery hook. If cleared, the owning player is required to select again." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ResetPlayerSkinSelection constinit property declarations **************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPlayerAvatarComponent_eventResetPlayerSkinSelection_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetPlayerSkinSelection constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetPlayerSkinSelection Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerAvatarComponent_eventResetPlayerSkinSelection_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ResetPlayerSkinSelection Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "ResetPlayerSkinSelection", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventResetPlayerSkinSelection_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventResetPlayerSkinSelection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_ResetPlayerSkinSelection(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execResetPlayerSkinSelection)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ResetPlayerSkinSelection();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function ResetPlayerSkinSelection ****************

// ********** Begin Class UDMFPlayerAvatarComponent Function ResolvePlayerSkin *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_ResolvePlayerSkin_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventResolvePlayerSkin_Parms
	{
		FPrimaryAssetId SkinId;
		UDMFPlayerSkinData* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResolvePlayerSkin constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResolvePlayerSkin constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResolvePlayerSkin Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventResolvePlayerSkin_Parms, SkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventResolvePlayerSkin_Parms, ReturnValue), Z_Construct_UClass_UDMFPlayerSkinData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ResolvePlayerSkin Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "ResolvePlayerSkin", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventResolvePlayerSkin_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventResolvePlayerSkin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_ResolvePlayerSkin(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execResolvePlayerSkin)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SkinId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDMFPlayerSkinData**)Z_Param__Result=P_THIS->ResolvePlayerSkin(Z_Param_SkinId);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function ResolvePlayerSkin ***********************

// ********** Begin Class UDMFPlayerAvatarComponent Function ResolveSelectedPlayerSkin *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_ResolveSelectedPlayerSkin_Statics
struct UHT_STATICS
{
	struct DMFPlayerAvatarComponent_eventResolveSelectedPlayerSkin_Parms
	{
		UDMFPlayerSkinData* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResolveSelectedPlayerSkin constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResolveSelectedPlayerSkin constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResolveSelectedPlayerSkin Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventResolveSelectedPlayerSkin_Parms, ReturnValue), Z_Construct_UClass_UDMFPlayerSkinData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ResolveSelectedPlayerSkin Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "ResolveSelectedPlayerSkin", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerAvatarComponent_eventResolveSelectedPlayerSkin_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerAvatarComponent_eventResolveSelectedPlayerSkin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_ResolveSelectedPlayerSkin(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execResolveSelectedPlayerSkin)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDMFPlayerSkinData**)Z_Param__Result=P_THIS->ResolveSelectedPlayerSkin();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function ResolveSelectedPlayerSkin ***************

// ********** Begin Class UDMFPlayerAvatarComponent Function ServerSetPlayerSkin *******************
struct DMFPlayerAvatarComponent_eventServerSetPlayerSkin_Parms
{
	FPrimaryAssetId SkinId;
};
static FName NAME_UDMFPlayerAvatarComponent_ServerSetPlayerSkin = FName(TEXT("ServerSetPlayerSkin"));
void UDMFPlayerAvatarComponent::ServerSetPlayerSkin(FPrimaryAssetId SkinId)
{
	DMFPlayerAvatarComponent_eventServerSetPlayerSkin_Parms Parms;
	Parms.SkinId=SkinId;
	UFunction* Func = FindFunctionChecked(NAME_UDMFPlayerAvatarComponent_ServerSetPlayerSkin);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerAvatarComponent_ServerSetPlayerSkin_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Client request. Server validates that the requested Primary Data Asset exists and is enabled. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client request. Server validates that the requested Primary Data Asset exists and is enabled." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ServerSetPlayerSkin constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ServerSetPlayerSkin constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ServerSetPlayerSkin Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerAvatarComponent_eventServerSetPlayerSkin_Parms, SkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ServerSetPlayerSkin Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerAvatarComponent, nullptr, "ServerSetPlayerSkin", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerAvatarComponent_eventServerSetPlayerSkin_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerAvatarComponent_eventServerSetPlayerSkin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerAvatarComponent_ServerSetPlayerSkin(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerAvatarComponent::execServerSetPlayerSkin)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SkinId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSetPlayerSkin_Implementation(Z_Param_SkinId);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerAvatarComponent Function ServerSetPlayerSkin *********************

// ********** Begin Class UDMFPlayerAvatarComponent ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFPlayerAvatarComponent_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "DigimonMMO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Owner-routed, server-authoritative player-avatar selection component.\n * Lives on ADMFPlayerState so skin RPCs originate from an actor the owning client controls.\n */" },
#endif
		{ "IncludePath", "Components/DMFPlayerAvatarComponent.h" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owner-routed, server-authoritative player-avatar selection component.\nLives on ADMFPlayerState so skin RPCs originate from an actor the owning client controls." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPlayerSkinChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPlayerSkinRequirementChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPlayerSkinSelectionResult_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedPlayerSkinId_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPlayerSkinSelectionRequired_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/DMFPlayerAvatarComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFPlayerAvatarComponent constinit property declarations ****************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlayerSkinChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlayerSkinRequirementChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlayerSkinSelectionResult;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectedPlayerSkinId;
	static void NewProp_bPlayerSkinSelectionRequired_SetBit(void* Obj)
	{
		((UDMFPlayerAvatarComponent*)Obj)->bPlayerSkinSelectionRequired = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlayerSkinSelectionRequired;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFPlayerAvatarComponent constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyCurrentWorldLocationToAccountRecord"), .Pointer = &UDMFPlayerAvatarComponent::execApplyCurrentWorldLocationToAccountRecord },
		{ .NameUTF8 = UTF8TEXT("ApplySelectedSkinToCurrentPawn"), .Pointer = &UDMFPlayerAvatarComponent::execApplySelectedSkinToCurrentPawn },
		{ .NameUTF8 = UTF8TEXT("ApplyToAccountRecord"), .Pointer = &UDMFPlayerAvatarComponent::execApplyToAccountRecord },
		{ .NameUTF8 = UTF8TEXT("ClientPlayerSkinSelectionResult"), .Pointer = &UDMFPlayerAvatarComponent::execClientPlayerSkinSelectionResult },
		{ .NameUTF8 = UTF8TEXT("GetAvailablePlayerSkins"), .Pointer = &UDMFPlayerAvatarComponent::execGetAvailablePlayerSkins },
		{ .NameUTF8 = UTF8TEXT("GetSelectedPlayerSkinId"), .Pointer = &UDMFPlayerAvatarComponent::execGetSelectedPlayerSkinId },
		{ .NameUTF8 = UTF8TEXT("InitializeFromAccountRecord"), .Pointer = &UDMFPlayerAvatarComponent::execInitializeFromAccountRecord },
		{ .NameUTF8 = UTF8TEXT("IsPlayerSkinSelectionRequired"), .Pointer = &UDMFPlayerAvatarComponent::execIsPlayerSkinSelectionRequired },
		{ .NameUTF8 = UTF8TEXT("OnRep_PlayerSkinSelectionRequired"), .Pointer = &UDMFPlayerAvatarComponent::execOnRep_PlayerSkinSelectionRequired },
		{ .NameUTF8 = UTF8TEXT("OnRep_SelectedPlayerSkinId"), .Pointer = &UDMFPlayerAvatarComponent::execOnRep_SelectedPlayerSkinId },
		{ .NameUTF8 = UTF8TEXT("ResetPlayerSkinSelection"), .Pointer = &UDMFPlayerAvatarComponent::execResetPlayerSkinSelection },
		{ .NameUTF8 = UTF8TEXT("ResolvePlayerSkin"), .Pointer = &UDMFPlayerAvatarComponent::execResolvePlayerSkin },
		{ .NameUTF8 = UTF8TEXT("ResolveSelectedPlayerSkin"), .Pointer = &UDMFPlayerAvatarComponent::execResolveSelectedPlayerSkin },
		{ .NameUTF8 = UTF8TEXT("ServerSetPlayerSkin"), .Pointer = &UDMFPlayerAvatarComponent::execServerSetPlayerSkin },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_ApplyCurrentWorldLocationToAccountRecord, "ApplyCurrentWorldLocationToAccountRecord" }, // 6b5ceb5307d880e66e542ae2e3d2547182908188
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_ApplySelectedSkinToCurrentPawn, "ApplySelectedSkinToCurrentPawn" }, // 975e6acdeb0bf4a10fc4c0d4b2a60e6299d7be7b
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_ApplyToAccountRecord, "ApplyToAccountRecord" }, // 86411b5aad1b25acd7dc7b195d4ee738ca973d9e
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_ClientPlayerSkinSelectionResult, "ClientPlayerSkinSelectionResult" }, // c0d1a190fa5ad11332038ff7d730e65d9fe94072
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_GetAvailablePlayerSkins, "GetAvailablePlayerSkins" }, // 92eaa4761b26d497ac27f7d19aa41d57f8a3aace
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_GetSelectedPlayerSkinId, "GetSelectedPlayerSkinId" }, // fc890e6e9ac99610f35575232980f00179ba52e3
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_InitializeFromAccountRecord, "InitializeFromAccountRecord" }, // 8ea82444fa4edfd82ab6e900e7b87ce5cb7ee61a
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_IsPlayerSkinSelectionRequired, "IsPlayerSkinSelectionRequired" }, // cb6ac56765d2a3eecc99a87d69caabb93ccd94db
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_OnRep_PlayerSkinSelectionRequired, "OnRep_PlayerSkinSelectionRequired" }, // 483b007a6e8e991cadad9baa3db05e1c0cd82128
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_OnRep_SelectedPlayerSkinId, "OnRep_SelectedPlayerSkinId" }, // 2073d62c0b15c1221515eec83790d34fa1d6cf28
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_ResetPlayerSkinSelection, "ResetPlayerSkinSelection" }, // 1bc236925f20ff19e95fc04863e09542898ceb29
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_ResolvePlayerSkin, "ResolvePlayerSkin" }, // b9afb0e1786b2d2c133c624530a011c30f22698d
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_ResolveSelectedPlayerSkin, "ResolveSelectedPlayerSkin" }, // 1c4909b4284df877715c5cc546a5a675d5a4e9a7
		{ &Z_Construct_UFunction_UDMFPlayerAvatarComponent_ServerSetPlayerSkin, "ServerSetPlayerSkin" }, // 5a06a8a1d56c2785bf2c79cc48fb3543a7ab1e46
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFPlayerAvatarComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFPlayerAvatarComponent Property Definitions ***************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnPlayerSkinChanged = { "OnPlayerSkinChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerAvatarComponent, OnPlayerSkinChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPlayerSkinChanged_MetaData), NewProp_OnPlayerSkinChanged_MetaData) }; // 1c0687a517bf37ba001fd843fec0257e027de126
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnPlayerSkinRequirementChanged = { "OnPlayerSkinRequirementChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerAvatarComponent, OnPlayerSkinRequirementChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinRequirementChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPlayerSkinRequirementChanged_MetaData), NewProp_OnPlayerSkinRequirementChanged_MetaData) }; // 0d48815df5745ebaf3860514732c4f89d592cbf7
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnPlayerSkinSelectionResult = { "OnPlayerSkinSelectionResult", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerAvatarComponent, OnPlayerSkinSelectionResult), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinSelectionResult__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPlayerSkinSelectionResult_MetaData), NewProp_OnPlayerSkinSelectionResult_MetaData) }; // 21857bc6649b4364478407487cadbb31cbf76a6f
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SelectedPlayerSkinId = { "SelectedPlayerSkinId", "OnRep_SelectedPlayerSkinId", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerAvatarComponent, SelectedPlayerSkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedPlayerSkinId_MetaData), NewProp_SelectedPlayerSkinId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPlayerSkinSelectionRequired = { "bPlayerSkinSelectionRequired", "OnRep_PlayerSkinSelectionRequired", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFPlayerAvatarComponent), &UHT_STATICS::NewProp_bPlayerSkinSelectionRequired_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPlayerSkinSelectionRequired_MetaData), NewProp_bPlayerSkinSelectionRequired_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnPlayerSkinChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnPlayerSkinRequirementChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnPlayerSkinSelectionResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedPlayerSkinId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPlayerSkinSelectionRequired,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFPlayerAvatarComponent Property Definitions *****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UActorComponent,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFPlayerAvatarComponent,
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
static void UDMFPlayerAvatarComponent_StaticRegisterNativesUDMFPlayerAvatarComponent()
{
	UClass* Class = UDMFPlayerAvatarComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFPlayerAvatarComponent;
UClass* Z_Construct_UClass_UDMFPlayerAvatarComponent(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFPlayerAvatarComponent;
		if (!Z_Registration_Info_UClass_UDMFPlayerAvatarComponent.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFPlayerAvatarComponent"),
				Z_Registration_Info_UClass_UDMFPlayerAvatarComponent.InnerSingleton,
				UDMFPlayerAvatarComponent_StaticRegisterNativesUDMFPlayerAvatarComponent,
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
		return Z_Registration_Info_UClass_UDMFPlayerAvatarComponent.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFPlayerAvatarComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFPlayerAvatarComponent.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFPlayerAvatarComponent.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UDMFPlayerAvatarComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_SelectedPlayerSkinId(TEXT("SelectedPlayerSkinId"));
	static FName Name_bPlayerSkinSelectionRequired(TEXT("bPlayerSkinSelectionRequired"));
	const bool bIsValid = true
		&& Name_SelectedPlayerSkinId == ClassReps[(int32)ENetFields_Private::SelectedPlayerSkinId].Property->GetFName()
		&& Name_bPlayerSkinSelectionRequired == ClassReps[(int32)ENetFields_Private::bPlayerSkinSelectionRequired].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UDMFPlayerAvatarComponent"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFPlayerAvatarComponent);
UDMFPlayerAvatarComponent::~UDMFPlayerAvatarComponent() {}
// ********** End Class UDMFPlayerAvatarComponent **************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFPlayerAvatarComponent, TEXT("UDMFPlayerAvatarComponent"), &Z_Registration_Info_UClass_UDMFPlayerAvatarComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFPlayerAvatarComponent), 1116004832U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h__Script_DigimonMMOFramework_4de10bb23ae3c9f296c90bf03e4fa4db872eb2f9{
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
