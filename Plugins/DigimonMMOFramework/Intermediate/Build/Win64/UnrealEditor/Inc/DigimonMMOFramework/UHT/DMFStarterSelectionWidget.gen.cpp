// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFStarterSelectionWidget.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFStarterSelectionWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
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
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterSelectionWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFStarterSelectionWidget Function BP_OnStarterPreviewChanged ***********
struct DMFStarterSelectionWidget_eventBP_OnStarterPreviewChanged_Parms
{
	UDMFDigimonSpeciesData* Species;
};
static FName NAME_UDMFStarterSelectionWidget_BP_OnStarterPreviewChanged = FName(TEXT("BP_OnStarterPreviewChanged"));
void UDMFStarterSelectionWidget::BP_OnStarterPreviewChanged(UDMFDigimonSpeciesData* Species)
{
	DMFStarterSelectionWidget_eventBP_OnStarterPreviewChanged_Parms Parms;
	Parms.Species=Species;
	UFunction* Func = FindFunctionChecked(NAME_UDMFStarterSelectionWidget_BP_OnStarterPreviewChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFStarterSelectionWidget_BP_OnStarterPreviewChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Starter" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnStarterPreviewChanged constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Species;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnStarterPreviewChanged constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnStarterPreviewChanged Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Species = { "Species", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFStarterSelectionWidget_eventBP_OnStarterPreviewChanged_Parms, Species), Z_Construct_UClass_UDMFDigimonSpeciesData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Species,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnStarterPreviewChanged Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFStarterSelectionWidget, nullptr, "BP_OnStarterPreviewChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFStarterSelectionWidget_eventBP_OnStarterPreviewChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFStarterSelectionWidget_eventBP_OnStarterPreviewChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFStarterSelectionWidget_BP_OnStarterPreviewChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFStarterSelectionWidget Function BP_OnStarterPreviewChanged *************

// ********** Begin Class UDMFStarterSelectionWidget Function GetSelectedStarterSpeciesId **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFStarterSelectionWidget_GetSelectedStarterSpeciesId_Statics
struct UHT_STATICS
{
	struct DMFStarterSelectionWidget_eventGetSelectedStarterSpeciesId_Parms
	{
		FPrimaryAssetId ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Starter" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedStarterSpeciesId constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedStarterSpeciesId constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedStarterSpeciesId Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFStarterSelectionWidget_eventGetSelectedStarterSpeciesId_Parms, ReturnValue), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSelectedStarterSpeciesId Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFStarterSelectionWidget, nullptr, "GetSelectedStarterSpeciesId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFStarterSelectionWidget_eventGetSelectedStarterSpeciesId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFStarterSelectionWidget_eventGetSelectedStarterSpeciesId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFStarterSelectionWidget_GetSelectedStarterSpeciesId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFStarterSelectionWidget::execGetSelectedStarterSpeciesId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPrimaryAssetId*)Z_Param__Result=P_THIS->GetSelectedStarterSpeciesId();
	P_NATIVE_END;
}
// ********** End Class UDMFStarterSelectionWidget Function GetSelectedStarterSpeciesId ************

// ********** Begin Class UDMFStarterSelectionWidget Function HandleConfirm ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFStarterSelectionWidget_HandleConfirm_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleConfirm constinit property declarations *************************
// ********** End Function HandleConfirm constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFStarterSelectionWidget, nullptr, "HandleConfirm", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFStarterSelectionWidget_HandleConfirm(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFStarterSelectionWidget::execHandleConfirm)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleConfirm();
	P_NATIVE_END;
}
// ********** End Class UDMFStarterSelectionWidget Function HandleConfirm **************************

// ********** Begin Class UDMFStarterSelectionWidget Function HandleStarterPressed *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFStarterSelectionWidget_HandleStarterPressed_Statics
struct UHT_STATICS
{
	struct DMFStarterSelectionWidget_eventHandleStarterPressed_Parms
	{
		FPrimaryAssetId SpeciesId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleStarterPressed constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleStarterPressed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleStarterPressed Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFStarterSelectionWidget_eventHandleStarterPressed_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleStarterPressed Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFStarterSelectionWidget, nullptr, "HandleStarterPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFStarterSelectionWidget_eventHandleStarterPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFStarterSelectionWidget_eventHandleStarterPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFStarterSelectionWidget_HandleStarterPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFStarterSelectionWidget::execHandleStarterPressed)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SpeciesId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStarterPressed(Z_Param_SpeciesId);
	P_NATIVE_END;
}
// ********** End Class UDMFStarterSelectionWidget Function HandleStarterPressed *******************

// ********** Begin Class UDMFStarterSelectionWidget Function HandleStarterSelectionResult *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFStarterSelectionWidget_HandleStarterSelectionResult_Statics
struct UHT_STATICS
{
	struct DMFStarterSelectionWidget_eventHandleStarterSelectionResult_Parms
	{
		bool bSuccess;
		FText Message;
		FGuid PartnerInstanceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleStarterSelectionResult constinit property declarations **********
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFStarterSelectionWidget_eventHandleStarterSelectionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PartnerInstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleStarterSelectionResult constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleStarterSelectionResult Property Definitions *********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFStarterSelectionWidget_eventHandleStarterSelectionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFStarterSelectionWidget_eventHandleStarterSelectionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PartnerInstanceId = { "PartnerInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFStarterSelectionWidget_eventHandleStarterSelectionResult_Parms, PartnerInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartnerInstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleStarterSelectionResult Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFStarterSelectionWidget, nullptr, "HandleStarterSelectionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFStarterSelectionWidget_eventHandleStarterSelectionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFStarterSelectionWidget_eventHandleStarterSelectionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFStarterSelectionWidget_HandleStarterSelectionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFStarterSelectionWidget::execHandleStarterSelectionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FGuid,Z_Param_PartnerInstanceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStarterSelectionResult(Z_Param_bSuccess,Z_Param_Message,Z_Param_PartnerInstanceId);
	P_NATIVE_END;
}
// ********** End Class UDMFStarterSelectionWidget Function HandleStarterSelectionResult ***********

// ********** Begin Class UDMFStarterSelectionWidget ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFStarterSelectionWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Polished native starter selector with portrait cards and selected-species inspection. */" },
#endif
		{ "IncludePath", "UI/DMFStarterSelectionWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Polished native starter selector with portrait cards and selected-species inspection." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChoicesBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFStarterSelectionWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy/custom Blueprint list binding. Native fallback uses ChoicesGrid. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy/custom Blueprint list binding. Native fallback uses ChoicesGrid." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChoicesGrid_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFStarterSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailsText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFStarterSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedStarterNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFStarterSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedStarterMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFStarterSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarterStatusText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFStarterSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedStarterPortrait_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFStarterSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfirmButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFStarterSelectionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFStarterSelectionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFStarterSelectionWidget constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChoicesBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChoicesGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedStarterNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedStarterMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StarterStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedStarterPortrait;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ConfirmButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFStarterSelectionWidget constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSelectedStarterSpeciesId"), .Pointer = &UDMFStarterSelectionWidget::execGetSelectedStarterSpeciesId },
		{ .NameUTF8 = UTF8TEXT("HandleConfirm"), .Pointer = &UDMFStarterSelectionWidget::execHandleConfirm },
		{ .NameUTF8 = UTF8TEXT("HandleStarterPressed"), .Pointer = &UDMFStarterSelectionWidget::execHandleStarterPressed },
		{ .NameUTF8 = UTF8TEXT("HandleStarterSelectionResult"), .Pointer = &UDMFStarterSelectionWidget::execHandleStarterSelectionResult },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFStarterSelectionWidget_BP_OnStarterPreviewChanged, "BP_OnStarterPreviewChanged" }, // 77e0389de0d3918843247d84e9593966c05c6e16
		{ &Z_Construct_UFunction_UDMFStarterSelectionWidget_GetSelectedStarterSpeciesId, "GetSelectedStarterSpeciesId" }, // 1b71bb1a203116d8b1d07633d8c83a4c2b5962b6
		{ &Z_Construct_UFunction_UDMFStarterSelectionWidget_HandleConfirm, "HandleConfirm" }, // 761b599fa9726901a3bd79e4323568dc78ebac24
		{ &Z_Construct_UFunction_UDMFStarterSelectionWidget_HandleStarterPressed, "HandleStarterPressed" }, // 4dfcd2c7c0b9a0711a6945c858e9e134bfd94692
		{ &Z_Construct_UFunction_UDMFStarterSelectionWidget_HandleStarterSelectionResult, "HandleStarterSelectionResult" }, // b16823d0fa6cc71b50d2023db552a22520affc59
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFStarterSelectionWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFStarterSelectionWidget Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ChoicesBox = { "ChoicesBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterSelectionWidget, ChoicesBox), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChoicesBox_MetaData), NewProp_ChoicesBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ChoicesGrid = { "ChoicesGrid", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterSelectionWidget, ChoicesGrid), Z_Construct_UClass_UUniformGridPanel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChoicesGrid_MetaData), NewProp_ChoicesGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailsText = { "DetailsText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterSelectionWidget, DetailsText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailsText_MetaData), NewProp_DetailsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedStarterNameText = { "SelectedStarterNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterSelectionWidget, SelectedStarterNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedStarterNameText_MetaData), NewProp_SelectedStarterNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedStarterMetaText = { "SelectedStarterMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterSelectionWidget, SelectedStarterMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedStarterMetaText_MetaData), NewProp_SelectedStarterMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_StarterStatusText = { "StarterStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterSelectionWidget, StarterStatusText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarterStatusText_MetaData), NewProp_StarterStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedStarterPortrait = { "SelectedStarterPortrait", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterSelectionWidget, SelectedStarterPortrait), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedStarterPortrait_MetaData), NewProp_SelectedStarterPortrait_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ConfirmButton = { "ConfirmButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterSelectionWidget, ConfirmButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConfirmButton_MetaData), NewProp_ConfirmButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChoicesBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChoicesGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedStarterNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedStarterMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StarterStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedStarterPortrait,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ConfirmButton,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFStarterSelectionWidget Property Definitions ****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFStarterSelectionWidget,
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
static void UDMFStarterSelectionWidget_StaticRegisterNativesUDMFStarterSelectionWidget()
{
	UClass* Class = UDMFStarterSelectionWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFStarterSelectionWidget;
UClass* Z_Construct_UClass_UDMFStarterSelectionWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFStarterSelectionWidget;
		if (!Z_Registration_Info_UClass_UDMFStarterSelectionWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFStarterSelectionWidget"),
				Z_Registration_Info_UClass_UDMFStarterSelectionWidget.InnerSingleton,
				UDMFStarterSelectionWidget_StaticRegisterNativesUDMFStarterSelectionWidget,
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
		return Z_Registration_Info_UClass_UDMFStarterSelectionWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFStarterSelectionWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFStarterSelectionWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFStarterSelectionWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFStarterSelectionWidget::UDMFStarterSelectionWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFStarterSelectionWidget);
UDMFStarterSelectionWidget::~UDMFStarterSelectionWidget() {}
// ********** End Class UDMFStarterSelectionWidget *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFStarterSelectionWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFStarterSelectionWidget, TEXT("UDMFStarterSelectionWidget"), &Z_Registration_Info_UClass_UDMFStarterSelectionWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFStarterSelectionWidget), 1049947322U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFStarterSelectionWidget_h__Script_DigimonMMOFramework_5d62981b60d859ffa6275cba38bc93bf356b9aae{
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
