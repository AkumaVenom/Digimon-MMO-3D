// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFPlayerSkinSelectionWidget.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFPlayerSkinSelectionWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUniformGridPanel(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UVerticalBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinSelectionWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFPlayerSkinSelectionWidget Function BP_OnPlayerSkinPreviewChanged *****
struct DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinPreviewChanged_Parms
{
	UDMFPlayerSkinData* SkinData;
};
static FName NAME_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinPreviewChanged = FName(TEXT("BP_OnPlayerSkinPreviewChanged"));
void UDMFPlayerSkinSelectionWidget::BP_OnPlayerSkinPreviewChanged(UDMFPlayerSkinData* SkinData)
{
	DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinPreviewChanged_Parms Parms;
	Parms.SkinData=SkinData;
	UFunction* Func = FindFunctionChecked(NAME_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinPreviewChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinPreviewChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPlayerSkinPreviewChanged constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkinData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnPlayerSkinPreviewChanged constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnPlayerSkinPreviewChanged Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkinData = { "SkinData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinPreviewChanged_Parms, SkinData), Z_Construct_UClass_UDMFPlayerSkinData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinData,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnPlayerSkinPreviewChanged Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, nullptr, "BP_OnPlayerSkinPreviewChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinPreviewChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinPreviewChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinPreviewChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFPlayerSkinSelectionWidget Function BP_OnPlayerSkinPreviewChanged *******

// ********** Begin Class UDMFPlayerSkinSelectionWidget Function BP_OnPlayerSkinSelectionResult ****
struct DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinSelectionResult_Parms
{
	bool bSuccess;
	FText Message;
	UDMFPlayerSkinData* SkinData;
};
static FName NAME_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinSelectionResult = FName(TEXT("BP_OnPlayerSkinSelectionResult"));
void UDMFPlayerSkinSelectionWidget::BP_OnPlayerSkinSelectionResult(bool bSuccess, FText const& Message, UDMFPlayerSkinData* SkinData)
{
	DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinSelectionResult_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Message=Message;
	Parms.SkinData=SkinData;
	UFunction* Func = FindFunctionChecked(NAME_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinSelectionResult);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinSelectionResult_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPlayerSkinSelectionResult constinit property declarations ********
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinSelectionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkinData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnPlayerSkinSelectionResult constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnPlayerSkinSelectionResult Property Definitions *******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinSelectionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinSelectionResult_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SkinData = { "SkinData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinSelectionResult_Parms, SkinData), Z_Construct_UClass_UDMFPlayerSkinData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinData,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnPlayerSkinSelectionResult Property Definitions *********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, nullptr, "BP_OnPlayerSkinSelectionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinSelectionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFPlayerSkinSelectionWidget_eventBP_OnPlayerSkinSelectionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinSelectionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFPlayerSkinSelectionWidget Function BP_OnPlayerSkinSelectionResult ******

// ********** Begin Class UDMFPlayerSkinSelectionWidget Function GetPreviewedPlayerSkinId **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_GetPreviewedPlayerSkinId_Statics
struct UHT_STATICS
{
	struct DMFPlayerSkinSelectionWidget_eventGetPreviewedPlayerSkinId_Parms
	{
		FPrimaryAssetId ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPreviewedPlayerSkinId constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPreviewedPlayerSkinId constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPreviewedPlayerSkinId Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSkinSelectionWidget_eventGetPreviewedPlayerSkinId_Parms, ReturnValue), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetPreviewedPlayerSkinId Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, nullptr, "GetPreviewedPlayerSkinId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerSkinSelectionWidget_eventGetPreviewedPlayerSkinId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerSkinSelectionWidget_eventGetPreviewedPlayerSkinId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_GetPreviewedPlayerSkinId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSkinSelectionWidget::execGetPreviewedPlayerSkinId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPrimaryAssetId*)Z_Param__Result=P_THIS->GetPreviewedPlayerSkinId();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSkinSelectionWidget Function GetPreviewedPlayerSkinId ************

// ********** Begin Class UDMFPlayerSkinSelectionWidget Function HandleApplyPlayerSkin *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandleApplyPlayerSkin_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleApplyPlayerSkin constinit property declarations *****************
// ********** End Function HandleApplyPlayerSkin constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, nullptr, "HandleApplyPlayerSkin", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandleApplyPlayerSkin(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSkinSelectionWidget::execHandleApplyPlayerSkin)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleApplyPlayerSkin();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSkinSelectionWidget Function HandleApplyPlayerSkin ***************

// ********** Begin Class UDMFPlayerSkinSelectionWidget Function HandleClosePlayerSkin *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandleClosePlayerSkin_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleClosePlayerSkin constinit property declarations *****************
// ********** End Function HandleClosePlayerSkin constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, nullptr, "HandleClosePlayerSkin", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandleClosePlayerSkin(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSkinSelectionWidget::execHandleClosePlayerSkin)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleClosePlayerSkin();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSkinSelectionWidget Function HandleClosePlayerSkin ***************

// ********** Begin Class UDMFPlayerSkinSelectionWidget Function HandlePlayerSkinPressed ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandlePlayerSkinPressed_Statics
struct UHT_STATICS
{
	struct DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinPressed_Parms
	{
		FPrimaryAssetId SkinId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePlayerSkinPressed constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandlePlayerSkinPressed constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandlePlayerSkinPressed Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinPressed_Parms, SkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandlePlayerSkinPressed Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, nullptr, "HandlePlayerSkinPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandlePlayerSkinPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSkinSelectionWidget::execHandlePlayerSkinPressed)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SkinId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePlayerSkinPressed(Z_Param_SkinId);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSkinSelectionWidget Function HandlePlayerSkinPressed *************

// ********** Begin Class UDMFPlayerSkinSelectionWidget Function HandlePlayerSkinSelectionResult ***
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandlePlayerSkinSelectionResult_Statics
struct UHT_STATICS
{
	struct DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinSelectionResult_Parms
	{
		bool bSuccess;
		FText Message;
		FPrimaryAssetId SkinId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePlayerSkinSelectionResult constinit property declarations *******
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinSelectionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandlePlayerSkinSelectionResult constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandlePlayerSkinSelectionResult Property Definitions ******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinSelectionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinSelectionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinSelectionResult_Parms, SkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandlePlayerSkinSelectionResult Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, nullptr, "HandlePlayerSkinSelectionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinSelectionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerSkinSelectionWidget_eventHandlePlayerSkinSelectionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandlePlayerSkinSelectionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSkinSelectionWidget::execHandlePlayerSkinSelectionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SkinId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePlayerSkinSelectionResult(Z_Param_bSuccess,Z_Param_Message,Z_Param_SkinId);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSkinSelectionWidget Function HandlePlayerSkinSelectionResult *****

// ********** Begin Class UDMFPlayerSkinSelectionWidget Function RefreshAvailablePlayerSkins *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_RefreshAvailablePlayerSkins_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshAvailablePlayerSkins constinit property declarations ***********
// ********** End Function RefreshAvailablePlayerSkins constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, nullptr, "RefreshAvailablePlayerSkins", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_RefreshAvailablePlayerSkins(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSkinSelectionWidget::execRefreshAvailablePlayerSkins)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshAvailablePlayerSkins();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSkinSelectionWidget Function RefreshAvailablePlayerSkins *********

// ********** Begin Class UDMFPlayerSkinSelectionWidget ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFPlayerSkinSelectionWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Polished native character-skin selector with portrait cards and selected-skin inspection. */" },
#endif
		{ "IncludePath", "UI/DMFPlayerSkinSelectionWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Polished native character-skin selector with portrait cards and selected-skin inspection." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSkinChoicesBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSkinSelectionWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy/custom Blueprint list binding. Native fallback uses PlayerSkinChoicesGrid. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy/custom Blueprint list binding. Native fallback uses PlayerSkinChoicesGrid." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSkinChoicesGrid_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSkinSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSkinDetailsText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSkinSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSkinStatusText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSkinSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewedSkinNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSkinSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewedSkinPortrait_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSkinSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplyPlayerSkinButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSkinSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClosePlayerSkinButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSkinSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFPlayerSkinSelectionWidget constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerSkinChoicesBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerSkinChoicesGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerSkinDetailsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerSkinStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewedSkinNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewedSkinPortrait;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ApplyPlayerSkinButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClosePlayerSkinButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFPlayerSkinSelectionWidget constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetPreviewedPlayerSkinId"), .Pointer = &UDMFPlayerSkinSelectionWidget::execGetPreviewedPlayerSkinId },
		{ .NameUTF8 = UTF8TEXT("HandleApplyPlayerSkin"), .Pointer = &UDMFPlayerSkinSelectionWidget::execHandleApplyPlayerSkin },
		{ .NameUTF8 = UTF8TEXT("HandleClosePlayerSkin"), .Pointer = &UDMFPlayerSkinSelectionWidget::execHandleClosePlayerSkin },
		{ .NameUTF8 = UTF8TEXT("HandlePlayerSkinPressed"), .Pointer = &UDMFPlayerSkinSelectionWidget::execHandlePlayerSkinPressed },
		{ .NameUTF8 = UTF8TEXT("HandlePlayerSkinSelectionResult"), .Pointer = &UDMFPlayerSkinSelectionWidget::execHandlePlayerSkinSelectionResult },
		{ .NameUTF8 = UTF8TEXT("RefreshAvailablePlayerSkins"), .Pointer = &UDMFPlayerSkinSelectionWidget::execRefreshAvailablePlayerSkins },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinPreviewChanged, "BP_OnPlayerSkinPreviewChanged" }, // 6296ba18791cbbce7591e9569e568e99cfa52d75
		{ &Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_BP_OnPlayerSkinSelectionResult, "BP_OnPlayerSkinSelectionResult" }, // 46f95a2dfdedaa8a81cd9d0b868510311918091a
		{ &Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_GetPreviewedPlayerSkinId, "GetPreviewedPlayerSkinId" }, // 530295157ca9d46eb4bac45cf570c948adddd956
		{ &Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandleApplyPlayerSkin, "HandleApplyPlayerSkin" }, // 8dc71fb50a479eb0345405c5ef5d2fe26218db27
		{ &Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandleClosePlayerSkin, "HandleClosePlayerSkin" }, // 5697b10395e374b603accea8c043ebf33310473e
		{ &Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandlePlayerSkinPressed, "HandlePlayerSkinPressed" }, // f9ab3feaec1639feba72b82055180aa239ead267
		{ &Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_HandlePlayerSkinSelectionResult, "HandlePlayerSkinSelectionResult" }, // 151b59ab3f59358a22b32e38d0892589662cc9b2
		{ &Z_Construct_UFunction_UDMFPlayerSkinSelectionWidget_RefreshAvailablePlayerSkins, "RefreshAvailablePlayerSkins" }, // a8775a8b30572e8fae4894f9541d991a3cf3e558
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFPlayerSkinSelectionWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFPlayerSkinSelectionWidget Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerSkinChoicesBox = { "PlayerSkinChoicesBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinSelectionWidget, PlayerSkinChoicesBox), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSkinChoicesBox_MetaData), NewProp_PlayerSkinChoicesBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerSkinChoicesGrid = { "PlayerSkinChoicesGrid", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinSelectionWidget, PlayerSkinChoicesGrid), Z_Construct_UClass_UUniformGridPanel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSkinChoicesGrid_MetaData), NewProp_PlayerSkinChoicesGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerSkinDetailsText = { "PlayerSkinDetailsText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinSelectionWidget, PlayerSkinDetailsText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSkinDetailsText_MetaData), NewProp_PlayerSkinDetailsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerSkinStatusText = { "PlayerSkinStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinSelectionWidget, PlayerSkinStatusText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSkinStatusText_MetaData), NewProp_PlayerSkinStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PreviewedSkinNameText = { "PreviewedSkinNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinSelectionWidget, PreviewedSkinNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewedSkinNameText_MetaData), NewProp_PreviewedSkinNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PreviewedSkinPortrait = { "PreviewedSkinPortrait", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinSelectionWidget, PreviewedSkinPortrait), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewedSkinPortrait_MetaData), NewProp_PreviewedSkinPortrait_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ApplyPlayerSkinButton = { "ApplyPlayerSkinButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinSelectionWidget, ApplyPlayerSkinButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplyPlayerSkinButton_MetaData), NewProp_ApplyPlayerSkinButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ClosePlayerSkinButton = { "ClosePlayerSkinButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinSelectionWidget, ClosePlayerSkinButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClosePlayerSkinButton_MetaData), NewProp_ClosePlayerSkinButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSkinChoicesBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSkinChoicesGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSkinDetailsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSkinStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviewedSkinNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviewedSkinPortrait,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ApplyPlayerSkinButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ClosePlayerSkinButton,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFPlayerSkinSelectionWidget Property Definitions *************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFPlayerSkinSelectionWidget,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UDMFPlayerSkinSelectionWidget_StaticRegisterNativesUDMFPlayerSkinSelectionWidget()
{
	UClass* Class = UDMFPlayerSkinSelectionWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFPlayerSkinSelectionWidget;
UClass* Z_Construct_UClass_UDMFPlayerSkinSelectionWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFPlayerSkinSelectionWidget;
		if (!Z_Registration_Info_UClass_UDMFPlayerSkinSelectionWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFPlayerSkinSelectionWidget"),
				Z_Registration_Info_UClass_UDMFPlayerSkinSelectionWidget.InnerSingleton,
				UDMFPlayerSkinSelectionWidget_StaticRegisterNativesUDMFPlayerSkinSelectionWidget,
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
		return Z_Registration_Info_UClass_UDMFPlayerSkinSelectionWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFPlayerSkinSelectionWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFPlayerSkinSelectionWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFPlayerSkinSelectionWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFPlayerSkinSelectionWidget::UDMFPlayerSkinSelectionWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFPlayerSkinSelectionWidget);
UDMFPlayerSkinSelectionWidget::~UDMFPlayerSkinSelectionWidget() {}
// ********** End Class UDMFPlayerSkinSelectionWidget **********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPlayerSkinSelectionWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, TEXT("UDMFPlayerSkinSelectionWidget"), &Z_Registration_Info_UClass_UDMFPlayerSkinSelectionWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFPlayerSkinSelectionWidget), 1179185842U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPlayerSkinSelectionWidget_h__Script_DigimonMMOFramework_f7dcd8955f1e96016fa607925add5fd93f47dabd{
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
