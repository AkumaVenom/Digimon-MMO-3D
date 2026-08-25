// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFDigimonInventoryWidget.h"
#include "DMFTypes.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDigimonInventoryWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UHorizontalBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UProgressBar(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUniformGridPanel(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UVerticalBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonInstance(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerDigimonComponent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFDigimonInventoryWidget Function BP_OnDigimonPreviewChanged ***********
struct DMFDigimonInventoryWidget_eventBP_OnDigimonPreviewChanged_Parms
{
	FDMFDigimonInstance Digimon;
	UDMFDigimonSpeciesData* Species;
};
static FName NAME_UDMFDigimonInventoryWidget_BP_OnDigimonPreviewChanged = FName(TEXT("BP_OnDigimonPreviewChanged"));
void UDMFDigimonInventoryWidget::BP_OnDigimonPreviewChanged(FDMFDigimonInstance Digimon, UDMFDigimonSpeciesData* Species)
{
	DMFDigimonInventoryWidget_eventBP_OnDigimonPreviewChanged_Parms Parms;
	Parms.Digimon=Digimon;
	Parms.Species=Species;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonInventoryWidget_BP_OnDigimonPreviewChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnDigimonPreviewChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Inventory" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnDigimonPreviewChanged constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Digimon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Species;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnDigimonPreviewChanged constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnDigimonPreviewChanged Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Digimon = { "Digimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventBP_OnDigimonPreviewChanged_Parms, Digimon), Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(0, nullptr) }; // e6e75c2fbf4c76aeacffc5124dd1e08c71077ffa
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Species = { "Species", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventBP_OnDigimonPreviewChanged_Parms, Species), Z_Construct_UClass_UDMFDigimonSpeciesData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Species,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnDigimonPreviewChanged Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "BP_OnDigimonPreviewChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonInventoryWidget_eventBP_OnDigimonPreviewChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonInventoryWidget_eventBP_OnDigimonPreviewChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnDigimonPreviewChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFDigimonInventoryWidget Function BP_OnDigimonPreviewChanged *************

// ********** Begin Class UDMFDigimonInventoryWidget Function BP_OnPartnerActionResult *************
struct DMFDigimonInventoryWidget_eventBP_OnPartnerActionResult_Parms
{
	bool bSuccess;
	FText Message;
	FGuid PartnerInstanceId;
};
static FName NAME_UDMFDigimonInventoryWidget_BP_OnPartnerActionResult = FName(TEXT("BP_OnPartnerActionResult"));
void UDMFDigimonInventoryWidget::BP_OnPartnerActionResult(bool bSuccess, FText const& Message, FGuid PartnerInstanceId)
{
	DMFDigimonInventoryWidget_eventBP_OnPartnerActionResult_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Message=Message;
	Parms.PartnerInstanceId=PartnerInstanceId;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonInventoryWidget_BP_OnPartnerActionResult);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnPartnerActionResult_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Inventory" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPartnerActionResult constinit property declarations **************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFDigimonInventoryWidget_eventBP_OnPartnerActionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PartnerInstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnPartnerActionResult constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnPartnerActionResult Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonInventoryWidget_eventBP_OnPartnerActionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventBP_OnPartnerActionResult_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PartnerInstanceId = { "PartnerInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventBP_OnPartnerActionResult_Parms, PartnerInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartnerInstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnPartnerActionResult Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "BP_OnPartnerActionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonInventoryWidget_eventBP_OnPartnerActionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C20800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonInventoryWidget_eventBP_OnPartnerActionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnPartnerActionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFDigimonInventoryWidget Function BP_OnPartnerActionResult ***************

// ********** Begin Class UDMFDigimonInventoryWidget Function GetActiveMenuTab *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetActiveMenuTab_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventGetActiveMenuTab_Parms
	{
		EDMFDigimonMenuTab ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveMenuTab constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveMenuTab constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveMenuTab Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventGetActiveMenuTab_Parms, ReturnValue), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab, METADATA_PARAMS(0, nullptr) }; // 8352733895b0a4c8cf6e87d2cf597f35f4d232a7
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetActiveMenuTab Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "GetActiveMenuTab", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventGetActiveMenuTab_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventGetActiveMenuTab_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetActiveMenuTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execGetActiveMenuTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDMFDigimonMenuTab*)Z_Param__Result=P_THIS->GetActiveMenuTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function GetActiveMenuTab ***********************

// ********** Begin Class UDMFDigimonInventoryWidget Function GetSelectedDigimonInstanceId *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetSelectedDigimonInstanceId_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventGetSelectedDigimonInstanceId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Inventory" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedDigimonInstanceId constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedDigimonInstanceId constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedDigimonInstanceId Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventGetSelectedDigimonInstanceId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSelectedDigimonInstanceId Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "GetSelectedDigimonInstanceId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventGetSelectedDigimonInstanceId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventGetSelectedDigimonInstanceId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetSelectedDigimonInstanceId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execGetSelectedDigimonInstanceId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetSelectedDigimonInstanceId();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function GetSelectedDigimonInstanceId ***********

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleClose **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleClose_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleClose constinit property declarations ***************************
// ********** End Function HandleClose constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleClose", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleClose(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleClose)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleClose();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleClose ****************************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleCollectionTab ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCollectionTab_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCollectionTab constinit property declarations *******************
// ********** End Function HandleCollectionTab constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleCollectionTab", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCollectionTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleCollectionTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCollectionTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleCollectionTab ********************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigimonPressed *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigimonPressed_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleDigimonPressed_Parms
	{
		FGuid InstanceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigimonPressed constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDigimonPressed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDigimonPressed Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleDigimonPressed_Parms, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleDigimonPressed Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigimonPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigimonPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigimonPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigimonPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigimonPressed)
{
	P_GET_STRUCT(FGuid,Z_Param_InstanceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigimonPressed(Z_Param_InstanceId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigimonPressed *******************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleInventoryChanged ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleInventoryChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleInventoryChanged constinit property declarations ****************
// ********** End Function HandleInventoryChanged constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleInventoryChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleInventoryChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleInventoryChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleInventoryChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleInventoryChanged *****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleMaterializationResult **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMaterializationResult_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleMaterializationResult_Parms
	{
		bool bSuccess;
		FText Message;
		FPrimaryAssetId SpeciesId;
		FGuid NewDigimonInstanceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleMaterializationResult constinit property declarations ***********
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFDigimonInventoryWidget_eventHandleMaterializationResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewDigimonInstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleMaterializationResult constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleMaterializationResult Property Definitions **********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonInventoryWidget_eventHandleMaterializationResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleMaterializationResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleMaterializationResult_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NewDigimonInstanceId = { "NewDigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleMaterializationResult_Parms, NewDigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewDigimonInstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleMaterializationResult Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleMaterializationResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleMaterializationResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleMaterializationResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMaterializationResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleMaterializationResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SpeciesId);
	P_GET_STRUCT(FGuid,Z_Param_NewDigimonInstanceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMaterializationResult(Z_Param_bSuccess,Z_Param_Message,Z_Param_SpeciesId,Z_Param_NewDigimonInstanceId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleMaterializationResult ************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleMaterializeSelected ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMaterializeSelected_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleMaterializeSelected constinit property declarations *************
// ********** End Function HandleMaterializeSelected constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleMaterializeSelected", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMaterializeSelected(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleMaterializeSelected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMaterializeSelected();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleMaterializeSelected **************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandlePartnerActionResult ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandlePartnerActionResult_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandlePartnerActionResult_Parms
	{
		bool bSuccess;
		FText Message;
		FGuid PartnerInstanceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePartnerActionResult constinit property declarations *************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFDigimonInventoryWidget_eventHandlePartnerActionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PartnerInstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandlePartnerActionResult constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandlePartnerActionResult Property Definitions ************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonInventoryWidget_eventHandlePartnerActionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandlePartnerActionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PartnerInstanceId = { "PartnerInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandlePartnerActionResult_Parms, PartnerInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartnerInstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandlePartnerActionResult Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandlePartnerActionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandlePartnerActionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandlePartnerActionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandlePartnerActionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandlePartnerActionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FGuid,Z_Param_PartnerInstanceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePartnerActionResult(Z_Param_bSuccess,Z_Param_Message,Z_Param_PartnerInstanceId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandlePartnerActionResult **************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleRecallPartner ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleRecallPartner_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleRecallPartner constinit property declarations *******************
// ********** End Function HandleRecallPartner constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleRecallPartner", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleRecallPartner(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleRecallPartner)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleRecallPartner();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleRecallPartner ********************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleScanDataChanged ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanDataChanged_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleScanDataChanged_Parms
	{
		FPrimaryAssetId SpeciesId;
		float ScanPercent;
		bool bMaterializationReady;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleScanDataChanged constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScanPercent;
	static void NewProp_bMaterializationReady_SetBit(void* Obj)
	{
		((DMFDigimonInventoryWidget_eventHandleScanDataChanged_Parms*)Obj)->bMaterializationReady = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMaterializationReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleScanDataChanged constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleScanDataChanged Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleScanDataChanged_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ScanPercent = { "ScanPercent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleScanDataChanged_Parms, ScanPercent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bMaterializationReady = { "bMaterializationReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonInventoryWidget_eventHandleScanDataChanged_Parms), &UHT_STATICS::NewProp_bMaterializationReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bMaterializationReady,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleScanDataChanged Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleScanDataChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleScanDataChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleScanDataChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanDataChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleScanDataChanged)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SpeciesId);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ScanPercent);
	P_GET_UBOOL(Z_Param_bMaterializationReady);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleScanDataChanged(Z_Param_SpeciesId,Z_Param_ScanPercent,Z_Param_bMaterializationReady);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleScanDataChanged ******************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleScanMaterializeTab *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanMaterializeTab_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleScanMaterializeTab constinit property declarations **************
// ********** End Function HandleScanMaterializeTab constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleScanMaterializeTab", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanMaterializeTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleScanMaterializeTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleScanMaterializeTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleScanMaterializeTab ***************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleScanSpeciesPressed *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanSpeciesPressed_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleScanSpeciesPressed_Parms
	{
		FPrimaryAssetId SpeciesId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleScanSpeciesPressed constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleScanSpeciesPressed constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleScanSpeciesPressed Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleScanSpeciesPressed_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleScanSpeciesPressed Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleScanSpeciesPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleScanSpeciesPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleScanSpeciesPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanSpeciesPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleScanSpeciesPressed)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SpeciesId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleScanSpeciesPressed(Z_Param_SpeciesId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleScanSpeciesPressed ***************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSummonSelected *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSummonSelected_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSummonSelected constinit property declarations ******************
// ********** End Function HandleSummonSelected constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSummonSelected", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSummonSelected(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSummonSelected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSummonSelected();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSummonSelected *******************

// ********** Begin Class UDMFDigimonInventoryWidget Function RefreshInventory *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshInventory_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Inventory" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshInventory constinit property declarations **********************
// ********** End Function RefreshInventory constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "RefreshInventory", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshInventory(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execRefreshInventory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshInventory();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function RefreshInventory ***********************

// ********** Begin Class UDMFDigimonInventoryWidget Function RefreshScanData **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshScanData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Scan & Materialization" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshScanData constinit property declarations ***********************
// ********** End Function RefreshScanData constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "RefreshScanData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshScanData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execRefreshScanData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshScanData();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function RefreshScanData ************************

// ********** Begin Class UDMFDigimonInventoryWidget Function SetActiveMenuTab *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_SetActiveMenuTab_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventSetActiveMenuTab_Parms
	{
		EDMFDigimonMenuTab NewTab;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetActiveMenuTab constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewTab_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewTab;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetActiveMenuTab constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetActiveMenuTab Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewTab_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewTab = { "NewTab", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventSetActiveMenuTab_Parms, NewTab), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab, METADATA_PARAMS(0, nullptr) }; // 8352733895b0a4c8cf6e87d2cf597f35f4d232a7
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTab_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTab,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetActiveMenuTab Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "SetActiveMenuTab", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventSetActiveMenuTab_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventSetActiveMenuTab_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_SetActiveMenuTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execSetActiveMenuTab)
{
	P_GET_ENUM(EDMFDigimonMenuTab,Z_Param_NewTab);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetActiveMenuTab(EDMFDigimonMenuTab(Z_Param_NewTab));
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function SetActiveMenuTab ***********************

// ********** Begin Class UDMFDigimonInventoryWidget ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFDigimonInventoryWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Polished native Digimon roster/partner menu.\n * The framework fallback is a portrait-slot grid with a selected Digimon inspection panel,\n * summon/recall actions, status badges and account-owned replicated data. Blueprint children\n * may replace the presentation without replacing server authority.\n */" },
#endif
		{ "IncludePath", "UI/DMFDigimonInventoryWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Polished native Digimon roster/partner menu.\nThe framework fallback is a portrait-slot grid with a selected Digimon inspection panel,\nsummon/recall actions, status badges and account-owned replicated data. Blueprint children\nmay replace the presentation without replacing server authority." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonChoicesBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy/custom Blueprint list binding. Native fallback uses DigimonGrid. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy/custom Blueprint list binding. Native fallback uses DigimonGrid." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonGrid_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonDetailsText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonStatusText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryCountText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedStageText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedStateText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedDescriptionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedPortraitImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SummonDigimonButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecallDigimonButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseDigimonInventoryButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollectionTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanMaterializeTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanSpeciesGrid_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanDatabaseCountText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanSelectedPortraitImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanSelectedNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanSelectedMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanSelectedProgressText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanSelectedProgressBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanSelectedDetailsText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanSelectedDescriptionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterializeDigimonButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundDigimonComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryContentRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanContentRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFDigimonInventoryWidget constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonChoicesBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonDetailsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryCountText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedStageText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedStateText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedDescriptionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedPortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SummonDigimonButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RecallDigimonButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseDigimonInventoryButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollectionTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanMaterializeTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanSpeciesGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanDatabaseCountText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanSelectedPortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanSelectedNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanSelectedMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanSelectedProgressText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanSelectedProgressBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanSelectedDetailsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanSelectedDescriptionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterializeDigimonButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundDigimonComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryContentRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanContentRow;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFDigimonInventoryWidget constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetActiveMenuTab"), .Pointer = &UDMFDigimonInventoryWidget::execGetActiveMenuTab },
		{ .NameUTF8 = UTF8TEXT("GetSelectedDigimonInstanceId"), .Pointer = &UDMFDigimonInventoryWidget::execGetSelectedDigimonInstanceId },
		{ .NameUTF8 = UTF8TEXT("HandleClose"), .Pointer = &UDMFDigimonInventoryWidget::execHandleClose },
		{ .NameUTF8 = UTF8TEXT("HandleCollectionTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleCollectionTab },
		{ .NameUTF8 = UTF8TEXT("HandleDigimonPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigimonPressed },
		{ .NameUTF8 = UTF8TEXT("HandleInventoryChanged"), .Pointer = &UDMFDigimonInventoryWidget::execHandleInventoryChanged },
		{ .NameUTF8 = UTF8TEXT("HandleMaterializationResult"), .Pointer = &UDMFDigimonInventoryWidget::execHandleMaterializationResult },
		{ .NameUTF8 = UTF8TEXT("HandleMaterializeSelected"), .Pointer = &UDMFDigimonInventoryWidget::execHandleMaterializeSelected },
		{ .NameUTF8 = UTF8TEXT("HandlePartnerActionResult"), .Pointer = &UDMFDigimonInventoryWidget::execHandlePartnerActionResult },
		{ .NameUTF8 = UTF8TEXT("HandleRecallPartner"), .Pointer = &UDMFDigimonInventoryWidget::execHandleRecallPartner },
		{ .NameUTF8 = UTF8TEXT("HandleScanDataChanged"), .Pointer = &UDMFDigimonInventoryWidget::execHandleScanDataChanged },
		{ .NameUTF8 = UTF8TEXT("HandleScanMaterializeTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleScanMaterializeTab },
		{ .NameUTF8 = UTF8TEXT("HandleScanSpeciesPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleScanSpeciesPressed },
		{ .NameUTF8 = UTF8TEXT("HandleSummonSelected"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSummonSelected },
		{ .NameUTF8 = UTF8TEXT("RefreshInventory"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshInventory },
		{ .NameUTF8 = UTF8TEXT("RefreshScanData"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshScanData },
		{ .NameUTF8 = UTF8TEXT("SetActiveMenuTab"), .Pointer = &UDMFDigimonInventoryWidget::execSetActiveMenuTab },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnDigimonPreviewChanged, "BP_OnDigimonPreviewChanged" }, // 2726f2c651f6cb071caef5d2e3abe6df80c2efb2
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnPartnerActionResult, "BP_OnPartnerActionResult" }, // 53795b8dddaa4fd76ff5279e629c6e336fc6fcc3
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetActiveMenuTab, "GetActiveMenuTab" }, // a9a9fb2f21ffb765191ab635c18d7a74fd6cb163
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetSelectedDigimonInstanceId, "GetSelectedDigimonInstanceId" }, // 14399957d0996c285444e28d739eb535c4f017d5
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleClose, "HandleClose" }, // 477c2cacd8bfff5ad8241a06bd3f74da94bf4e55
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCollectionTab, "HandleCollectionTab" }, // 622846a94537b4bc0bfa7db654f3435d8ad78097
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigimonPressed, "HandleDigimonPressed" }, // 927395f5d6971893b8c92bbbc45214bbcb46f415
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleInventoryChanged, "HandleInventoryChanged" }, // 47863412eb4064cb03b7006c9243f38bd14a55c9
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMaterializationResult, "HandleMaterializationResult" }, // a5d7360d613759370ae18d7d0419fb287eb7cfdf
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMaterializeSelected, "HandleMaterializeSelected" }, // 1563989724bf7ad8e90d861bcace62b74f73c888
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandlePartnerActionResult, "HandlePartnerActionResult" }, // 0efd23cd585f884ca5e8dd298ad5e3d0c00c14d2
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleRecallPartner, "HandleRecallPartner" }, // f859e2899dd9c2a359bb1c0943389bbbb430ec37
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanDataChanged, "HandleScanDataChanged" }, // cbfd164ed6547fdd9fd7e1724f1538877399a940
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanMaterializeTab, "HandleScanMaterializeTab" }, // 6f3f6687566a6bad859cdaac7c69535b64fb9ffa
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanSpeciesPressed, "HandleScanSpeciesPressed" }, // 9513951e9f84b4f85b6d0e96f949d819d5fddc84
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSummonSelected, "HandleSummonSelected" }, // 40cb7ef02b2bcae9bfa80dd86b418c1a716bcd21
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshInventory, "RefreshInventory" }, // 8a93754174372b52bfea8109b1c82af35e69dc4b
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshScanData, "RefreshScanData" }, // bd4d62282ee4dfeeb547d4063c5d339c485984b3
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_SetActiveMenuTab, "SetActiveMenuTab" }, // 4bb2615c722935122ea66305a0af109f8cc41163
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFDigimonInventoryWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFDigimonInventoryWidget Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonChoicesBox = { "DigimonChoicesBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigimonChoicesBox), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonChoicesBox_MetaData), NewProp_DigimonChoicesBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonGrid = { "DigimonGrid", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigimonGrid), Z_Construct_UClass_UUniformGridPanel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonGrid_MetaData), NewProp_DigimonGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonDetailsText = { "DigimonDetailsText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigimonDetailsText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonDetailsText_MetaData), NewProp_DigimonDetailsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonStatusText = { "DigimonStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigimonStatusText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonStatusText_MetaData), NewProp_DigimonStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InventoryCountText = { "InventoryCountText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, InventoryCountText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryCountText_MetaData), NewProp_InventoryCountText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedNameText = { "SelectedNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedNameText_MetaData), NewProp_SelectedNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedStageText = { "SelectedStageText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedStageText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedStageText_MetaData), NewProp_SelectedStageText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedStateText = { "SelectedStateText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedStateText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedStateText_MetaData), NewProp_SelectedStateText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedDescriptionText = { "SelectedDescriptionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedDescriptionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedDescriptionText_MetaData), NewProp_SelectedDescriptionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedPortraitImage = { "SelectedPortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedPortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedPortraitImage_MetaData), NewProp_SelectedPortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SummonDigimonButton = { "SummonDigimonButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SummonDigimonButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SummonDigimonButton_MetaData), NewProp_SummonDigimonButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RecallDigimonButton = { "RecallDigimonButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, RecallDigimonButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecallDigimonButton_MetaData), NewProp_RecallDigimonButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CloseDigimonInventoryButton = { "CloseDigimonInventoryButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CloseDigimonInventoryButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseDigimonInventoryButton_MetaData), NewProp_CloseDigimonInventoryButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CollectionTabButton = { "CollectionTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CollectionTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollectionTabButton_MetaData), NewProp_CollectionTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanMaterializeTabButton = { "ScanMaterializeTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanMaterializeTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanMaterializeTabButton_MetaData), NewProp_ScanMaterializeTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanSpeciesGrid = { "ScanSpeciesGrid", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanSpeciesGrid), Z_Construct_UClass_UUniformGridPanel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanSpeciesGrid_MetaData), NewProp_ScanSpeciesGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanDatabaseCountText = { "ScanDatabaseCountText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanDatabaseCountText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanDatabaseCountText_MetaData), NewProp_ScanDatabaseCountText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanSelectedPortraitImage = { "ScanSelectedPortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanSelectedPortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanSelectedPortraitImage_MetaData), NewProp_ScanSelectedPortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanSelectedNameText = { "ScanSelectedNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanSelectedNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanSelectedNameText_MetaData), NewProp_ScanSelectedNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanSelectedMetaText = { "ScanSelectedMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanSelectedMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanSelectedMetaText_MetaData), NewProp_ScanSelectedMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanSelectedProgressText = { "ScanSelectedProgressText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanSelectedProgressText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanSelectedProgressText_MetaData), NewProp_ScanSelectedProgressText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanSelectedProgressBar = { "ScanSelectedProgressBar", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanSelectedProgressBar), Z_Construct_UClass_UProgressBar, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanSelectedProgressBar_MetaData), NewProp_ScanSelectedProgressBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanSelectedDetailsText = { "ScanSelectedDetailsText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanSelectedDetailsText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanSelectedDetailsText_MetaData), NewProp_ScanSelectedDetailsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanSelectedDescriptionText = { "ScanSelectedDescriptionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanSelectedDescriptionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanSelectedDescriptionText_MetaData), NewProp_ScanSelectedDescriptionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MaterializeDigimonButton = { "MaterializeDigimonButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, MaterializeDigimonButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterializeDigimonButton_MetaData), NewProp_MaterializeDigimonButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BoundDigimonComponent = { "BoundDigimonComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BoundDigimonComponent), Z_Construct_UClass_UDMFPlayerDigimonComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundDigimonComponent_MetaData), NewProp_BoundDigimonComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InventoryContentRow = { "InventoryContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, InventoryContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryContentRow_MetaData), NewProp_InventoryContentRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanContentRow = { "ScanContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanContentRow_MetaData), NewProp_ScanContentRow_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonChoicesBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonDetailsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InventoryCountText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedStageText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedStateText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedDescriptionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedPortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SummonDigimonButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RecallDigimonButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CloseDigimonInventoryButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CollectionTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanMaterializeTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanSpeciesGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanDatabaseCountText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanSelectedPortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanSelectedNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanSelectedMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanSelectedProgressText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanSelectedProgressBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanSelectedDetailsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanSelectedDescriptionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterializeDigimonButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BoundDigimonComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InventoryContentRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanContentRow,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFDigimonInventoryWidget Property Definitions ****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFDigimonInventoryWidget,
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
static void UDMFDigimonInventoryWidget_StaticRegisterNativesUDMFDigimonInventoryWidget()
{
	UClass* Class = UDMFDigimonInventoryWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFDigimonInventoryWidget;
UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFDigimonInventoryWidget;
		if (!Z_Registration_Info_UClass_UDMFDigimonInventoryWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonInventoryWidget"),
				Z_Registration_Info_UClass_UDMFDigimonInventoryWidget.InnerSingleton,
				UDMFDigimonInventoryWidget_StaticRegisterNativesUDMFDigimonInventoryWidget,
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
		return Z_Registration_Info_UClass_UDMFDigimonInventoryWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFDigimonInventoryWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFDigimonInventoryWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFDigimonInventoryWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFDigimonInventoryWidget::UDMFDigimonInventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFDigimonInventoryWidget);
UDMFDigimonInventoryWidget::~UDMFDigimonInventoryWidget() {}
// ********** End Class UDMFDigimonInventoryWidget *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFDigimonInventoryWidget, TEXT("UDMFDigimonInventoryWidget"), &Z_Registration_Info_UClass_UDMFDigimonInventoryWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFDigimonInventoryWidget), 3060463525U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h__Script_DigimonMMOFramework_13151a94ad5543ff5b7542b76c32cb50f58f13a3{
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
