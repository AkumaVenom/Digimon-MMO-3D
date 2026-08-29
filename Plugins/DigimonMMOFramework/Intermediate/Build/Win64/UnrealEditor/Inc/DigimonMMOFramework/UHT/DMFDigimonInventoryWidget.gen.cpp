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
UMG_API UClass* Z_Construct_UClass_UEditableTextBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UHorizontalBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UProgressBar(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUniformGridPanel(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UVerticalBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonCareState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonInstance(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttributeStat(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialMenuTab(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerDigimonComponent(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFSocialActionButton(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFDigimonInventoryWidget Function BP_OnDigiDexSelectionChanged *********
struct DMFDigimonInventoryWidget_eventBP_OnDigiDexSelectionChanged_Parms
{
	FPrimaryAssetId SpeciesId;
	UDMFDigimonSpeciesData* Species;
};
static FName NAME_UDMFDigimonInventoryWidget_BP_OnDigiDexSelectionChanged = FName(TEXT("BP_OnDigiDexSelectionChanged"));
void UDMFDigimonInventoryWidget::BP_OnDigiDexSelectionChanged(FPrimaryAssetId SpeciesId, UDMFDigimonSpeciesData* Species)
{
	DMFDigimonInventoryWidget_eventBP_OnDigiDexSelectionChanged_Parms Parms;
	Parms.SpeciesId=SpeciesId;
	Parms.Species=Species;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonInventoryWidget_BP_OnDigiDexSelectionChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnDigiDexSelectionChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|DigiDex" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnDigiDexSelectionChanged constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Species;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnDigiDexSelectionChanged constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnDigiDexSelectionChanged Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventBP_OnDigiDexSelectionChanged_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Species = { "Species", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventBP_OnDigiDexSelectionChanged_Parms, Species), Z_Construct_UClass_UDMFDigimonSpeciesData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Species,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnDigiDexSelectionChanged Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "BP_OnDigiDexSelectionChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonInventoryWidget_eventBP_OnDigiDexSelectionChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonInventoryWidget_eventBP_OnDigiDexSelectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnDigiDexSelectionChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFDigimonInventoryWidget Function BP_OnDigiDexSelectionChanged ***********

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
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Digimon = { "Digimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventBP_OnDigimonPreviewChanged_Parms, Digimon), Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(0, nullptr) }; // 4e507a01c7f3f7d9482109ce7a0bc560288acac2
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
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventGetActiveMenuTab_Parms, ReturnValue), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab, METADATA_PARAMS(0, nullptr) }; // 852449354d178a314ff17e0e8d18ca162511f67f
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

// ********** Begin Class UDMFDigimonInventoryWidget Function GetActiveSocialTab *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetActiveSocialTab_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventGetActiveSocialTab_Parms
	{
		EDMFSocialMenuTab ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveSocialTab constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveSocialTab constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveSocialTab Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventGetActiveSocialTab_Parms, ReturnValue), Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialMenuTab, METADATA_PARAMS(0, nullptr) }; // c2772bcfe79854528e4846d626dc8fb9d264a833
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetActiveSocialTab Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "GetActiveSocialTab", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventGetActiveSocialTab_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventGetActiveSocialTab_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetActiveSocialTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execGetActiveSocialTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDMFSocialMenuTab*)Z_Param__Result=P_THIS->GetActiveSocialTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function GetActiveSocialTab *********************

// ********** Begin Class UDMFDigimonInventoryWidget Function GetDigiDexSpeciesIds *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetDigiDexSpeciesIds_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventGetDigiDexSpeciesIds_Parms
	{
		TArray<FPrimaryAssetId> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|DigiDex" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDigiDexSpeciesIds constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDigiDexSpeciesIds constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDigiDexSpeciesIds Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventGetDigiDexSpeciesIds_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetDigiDexSpeciesIds Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "GetDigiDexSpeciesIds", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventGetDigiDexSpeciesIds_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventGetDigiDexSpeciesIds_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetDigiDexSpeciesIds(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execGetDigiDexSpeciesIds)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FPrimaryAssetId>*)Z_Param__Result=P_THIS->GetDigiDexSpeciesIds();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function GetDigiDexSpeciesIds *******************

// ********** Begin Class UDMFDigimonInventoryWidget Function GetSelectedDigiDexSpeciesId **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetSelectedDigiDexSpeciesId_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventGetSelectedDigiDexSpeciesId_Parms
	{
		FPrimaryAssetId ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|DigiDex" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedDigiDexSpeciesId constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedDigiDexSpeciesId constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedDigiDexSpeciesId Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventGetSelectedDigiDexSpeciesId_Parms, ReturnValue), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSelectedDigiDexSpeciesId Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "GetSelectedDigiDexSpeciesId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventGetSelectedDigiDexSpeciesId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventGetSelectedDigiDexSpeciesId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetSelectedDigiDexSpeciesId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execGetSelectedDigiDexSpeciesId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPrimaryAssetId*)Z_Param__Result=P_THIS->GetSelectedDigiDexSpeciesId();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function GetSelectedDigiDexSpeciesId ************

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

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleAttributePointSpendResult ******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleAttributePointSpendResult_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms
	{
		bool bSuccess;
		FText Message;
		FGuid DigimonInstanceId;
		EDMFDigimonAttributeStat Stat;
		int32 NewStatValue;
		int32 RemainingPoints;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleAttributePointSpendResult constinit property declarations *******
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Stat_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Stat;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewStatValue;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RemainingPoints;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleAttributePointSpendResult constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleAttributePointSpendResult Property Definitions ******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Stat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Stat = { "Stat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms, Stat), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttributeStat, METADATA_PARAMS(0, nullptr) }; // 458144be16776e500a9826fc6a0d4e1919785b75
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NewStatValue = { "NewStatValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms, NewStatValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_RemainingPoints = { "RemainingPoints", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms, RemainingPoints), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Stat_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Stat,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewStatValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RemainingPoints,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleAttributePointSpendResult Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleAttributePointSpendResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleAttributePointSpendResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleAttributePointSpendResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleAttributePointSpendResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_GET_ENUM(EDMFDigimonAttributeStat,Z_Param_Stat);
	P_GET_PROPERTY(FIntProperty,Z_Param_NewStatValue);
	P_GET_PROPERTY(FIntProperty,Z_Param_RemainingPoints);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleAttributePointSpendResult(Z_Param_bSuccess,Z_Param_Message,Z_Param_DigimonInstanceId,EDMFDigimonAttributeStat(Z_Param_Stat),Z_Param_NewStatValue,Z_Param_RemainingPoints);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleAttributePointSpendResult ********

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleBankChanged ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBankChanged constinit property declarations *********************
// ********** End Function HandleBankChanged constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleBankChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleBankChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBankChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleBankChanged **********************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleBankDigimonPressed *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankDigimonPressed_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleBankDigimonPressed_Parms
	{
		FGuid InstanceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBankDigimonPressed constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleBankDigimonPressed constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleBankDigimonPressed Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleBankDigimonPressed_Parms, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleBankDigimonPressed Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleBankDigimonPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleBankDigimonPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleBankDigimonPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankDigimonPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleBankDigimonPressed)
{
	P_GET_STRUCT(FGuid,Z_Param_InstanceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBankDigimonPressed(Z_Param_InstanceId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleBankDigimonPressed ***************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleBankNextPage *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankNextPage_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBankNextPage constinit property declarations ********************
// ********** End Function HandleBankNextPage constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleBankNextPage", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankNextPage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleBankNextPage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBankNextPage();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleBankNextPage *********************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleBankPartyDestinationPressed ****
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankPartyDestinationPressed_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleBankPartyDestinationPressed_Parms
	{
		int32 PartySlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBankPartyDestinationPressed constinit property declarations *****
	static const UECodeGen_Private::FIntPropertyParams NewProp_PartySlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleBankPartyDestinationPressed constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleBankPartyDestinationPressed Property Definitions ****************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_PartySlotIndex = { "PartySlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleBankPartyDestinationPressed_Parms, PartySlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartySlotIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleBankPartyDestinationPressed Property Definitions ******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleBankPartyDestinationPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleBankPartyDestinationPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleBankPartyDestinationPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankPartyDestinationPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleBankPartyDestinationPressed)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_PartySlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBankPartyDestinationPressed(Z_Param_PartySlotIndex);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleBankPartyDestinationPressed ******

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleBankPreviousPage ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankPreviousPage_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBankPreviousPage constinit property declarations ****************
// ********** End Function HandleBankPreviousPage constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleBankPreviousPage", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankPreviousPage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleBankPreviousPage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBankPreviousPage();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleBankPreviousPage *****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleBankTab ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankTab_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBankTab constinit property declarations *************************
// ********** End Function HandleBankTab constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleBankTab", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleBankTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBankTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleBankTab **************************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleCareSequenceFinished ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCareSequenceFinished_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleCareSequenceFinished_Parms
	{
		bool bSuccess;
		FText Message;
		FGuid DigimonInstanceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCareSequenceFinished constinit property declarations ************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFDigimonInventoryWidget_eventHandleCareSequenceFinished_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleCareSequenceFinished constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleCareSequenceFinished Property Definitions ***********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonInventoryWidget_eventHandleCareSequenceFinished_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleCareSequenceFinished_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleCareSequenceFinished_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleCareSequenceFinished Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleCareSequenceFinished", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleCareSequenceFinished_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleCareSequenceFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCareSequenceFinished(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleCareSequenceFinished)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCareSequenceFinished(Z_Param_bSuccess,Z_Param_Message,Z_Param_DigimonInstanceId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleCareSequenceFinished *************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleCareStateChanged ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCareStateChanged_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleCareStateChanged_Parms
	{
		FGuid DigimonInstanceId;
		FDMFDigimonCareState CareState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCareStateChanged constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CareState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleCareStateChanged constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleCareStateChanged Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleCareStateChanged_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_CareState = { "CareState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleCareStateChanged_Parms, CareState), Z_Construct_UScriptStruct_FDMFDigimonCareState, METADATA_PARAMS(0, nullptr) }; // 424313712cc83304aba267fa4dfab31c9d6ce242
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleCareStateChanged Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleCareStateChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleCareStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleCareStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCareStateChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleCareStateChanged)
{
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_GET_STRUCT(FDMFDigimonCareState,Z_Param_CareState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCareStateChanged(Z_Param_DigimonInstanceId,Z_Param_CareState);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleCareStateChanged *****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleCareTab ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCareTab_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCareTab constinit property declarations *************************
// ********** End Function HandleCareTab constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleCareTab", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCareTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleCareTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCareTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleCareTab **************************

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

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigiDexAttributeFilter *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexAttributeFilter_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigiDexAttributeFilter constinit property declarations **********
// ********** End Function HandleDigiDexAttributeFilter constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigiDexAttributeFilter", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexAttributeFilter(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigiDexAttributeFilter)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigiDexAttributeFilter();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigiDexAttributeFilter ***********

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigiDexSearchChanged ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexSearchChanged_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleDigiDexSearchChanged_Parms
	{
		FText SearchText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SearchText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigiDexSearchChanged constinit property declarations ************
	static const UECodeGen_Private::FTextPropertyParams NewProp_SearchText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDigiDexSearchChanged constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDigiDexSearchChanged Property Definitions ***********************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_SearchText = { "SearchText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleDigiDexSearchChanged_Parms, SearchText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SearchText_MetaData), NewProp_SearchText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SearchText,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleDigiDexSearchChanged Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigiDexSearchChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigiDexSearchChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigiDexSearchChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexSearchChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigiDexSearchChanged)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_SearchText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigiDexSearchChanged(Z_Param_Out_SearchText);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigiDexSearchChanged *************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigiDexSpeciesPressed **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexSpeciesPressed_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleDigiDexSpeciesPressed_Parms
	{
		FPrimaryAssetId SpeciesId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigiDexSpeciesPressed constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDigiDexSpeciesPressed constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDigiDexSpeciesPressed Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleDigiDexSpeciesPressed_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleDigiDexSpeciesPressed Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigiDexSpeciesPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigiDexSpeciesPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigiDexSpeciesPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexSpeciesPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigiDexSpeciesPressed)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SpeciesId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigiDexSpeciesPressed(Z_Param_SpeciesId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigiDexSpeciesPressed ************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigiDexStageFilter *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexStageFilter_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigiDexStageFilter constinit property declarations **************
// ********** End Function HandleDigiDexStageFilter constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigiDexStageFilter", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexStageFilter(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigiDexStageFilter)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigiDexStageFilter();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigiDexStageFilter ***************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigiDexTab *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexTab_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigiDexTab constinit property declarations **********************
// ********** End Function HandleDigiDexTab constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigiDexTab", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigiDexTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigiDexTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigiDexTab ***********************

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

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigivolutionOwnedPressed *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionOwnedPressed_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleDigivolutionOwnedPressed_Parms
	{
		FGuid InstanceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigivolutionOwnedPressed constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDigivolutionOwnedPressed constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDigivolutionOwnedPressed Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleDigivolutionOwnedPressed_Parms, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleDigivolutionOwnedPressed Property Definitions *********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigivolutionOwnedPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigivolutionOwnedPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigivolutionOwnedPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionOwnedPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigivolutionOwnedPressed)
{
	P_GET_STRUCT(FGuid,Z_Param_InstanceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigivolutionOwnedPressed(Z_Param_InstanceId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigivolutionOwnedPressed *********

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigivolutionResult *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionResult_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleDigivolutionResult_Parms
	{
		bool bSuccess;
		FText Message;
		FGuid DigimonInstanceId;
		FPrimaryAssetId PreviousSpeciesId;
		FPrimaryAssetId NewSpeciesId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigivolutionResult constinit property declarations **************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFDigimonInventoryWidget_eventHandleDigivolutionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousSpeciesId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewSpeciesId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDigivolutionResult constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDigivolutionResult Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonInventoryWidget_eventHandleDigivolutionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleDigivolutionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleDigivolutionResult_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PreviousSpeciesId = { "PreviousSpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleDigivolutionResult_Parms, PreviousSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NewSpeciesId = { "NewSpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleDigivolutionResult_Parms, NewSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousSpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewSpeciesId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleDigivolutionResult Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigivolutionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigivolutionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigivolutionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigivolutionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_PreviousSpeciesId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_NewSpeciesId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigivolutionResult(Z_Param_bSuccess,Z_Param_Message,Z_Param_DigimonInstanceId,Z_Param_PreviousSpeciesId,Z_Param_NewSpeciesId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigivolutionResult ***************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigivolutionTab ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionTab_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigivolutionTab constinit property declarations *****************
// ********** End Function HandleDigivolutionTab constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigivolutionTab", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigivolutionTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigivolutionTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigivolutionTab ******************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigivolutionTargetPressed ******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionTargetPressed_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleDigivolutionTargetPressed_Parms
	{
		FPrimaryAssetId SpeciesId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigivolutionTargetPressed constinit property declarations *******
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDigivolutionTargetPressed constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDigivolutionTargetPressed Property Definitions ******************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleDigivolutionTargetPressed_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleDigivolutionTargetPressed Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigivolutionTargetPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigivolutionTargetPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleDigivolutionTargetPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionTargetPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigivolutionTargetPressed)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SpeciesId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigivolutionTargetPressed(Z_Param_SpeciesId);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigivolutionTargetPressed ********

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleDigivolveSelected **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolveSelected_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigivolveSelected constinit property declarations ***************
// ********** End Function HandleDigivolveSelected constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleDigivolveSelected", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolveSelected(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleDigivolveSelected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigivolveSelected();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleDigivolveSelected ****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleFeedDigiMeat *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleFeedDigiMeat_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleFeedDigiMeat constinit property declarations ********************
// ********** End Function HandleFeedDigiMeat constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleFeedDigiMeat", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleFeedDigiMeat(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleFeedDigiMeat)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleFeedDigiMeat();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleFeedDigiMeat *********************

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

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleMoveSelectedBankToParty ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMoveSelectedBankToParty_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleMoveSelectedBankToParty constinit property declarations *********
// ********** End Function HandleMoveSelectedBankToParty constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleMoveSelectedBankToParty", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMoveSelectedBankToParty(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleMoveSelectedBankToParty)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMoveSelectedBankToParty();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleMoveSelectedBankToParty **********

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleMoveSelectedToBank *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMoveSelectedToBank_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleMoveSelectedToBank constinit property declarations **************
// ********** End Function HandleMoveSelectedToBank constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleMoveSelectedToBank", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMoveSelectedToBank(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleMoveSelectedToBank)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMoveSelectedToBank();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleMoveSelectedToBank ***************

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

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialActionButtonPressed ******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialActionButtonPressed_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleSocialActionButtonPressed_Parms
	{
		UDMFSocialActionButton* Button;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Button_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialActionButtonPressed constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Button;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleSocialActionButtonPressed constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleSocialActionButtonPressed Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Button = { "Button", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleSocialActionButtonPressed_Parms, Button), Z_Construct_UClass_UDMFSocialActionButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Button_MetaData), NewProp_Button_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Button,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleSocialActionButtonPressed Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialActionButtonPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleSocialActionButtonPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleSocialActionButtonPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialActionButtonPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialActionButtonPressed)
{
	P_GET_OBJECT(UDMFSocialActionButton,Z_Param_Button);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialActionButtonPressed(Z_Param_Button);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialActionButtonPressed ********

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialActionFeedback ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialActionFeedback_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleSocialActionFeedback_Parms
	{
		bool bSuccess;
		FText Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Owner-local non-modal feedback hook used by reliable Social action results. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owner-local non-modal feedback hook used by reliable Social action results." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialActionFeedback constinit property declarations ************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFDigimonInventoryWidget_eventHandleSocialActionFeedback_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleSocialActionFeedback constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleSocialActionFeedback Property Definitions ***********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonInventoryWidget_eventHandleSocialActionFeedback_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleSocialActionFeedback_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleSocialActionFeedback Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialActionFeedback", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleSocialActionFeedback_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleSocialActionFeedback_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialActionFeedback(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialActionFeedback)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialActionFeedback(Z_Param_bSuccess,Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialActionFeedback *************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialFriendsTab ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialFriendsTab_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialFriendsTab constinit property declarations ****************
// ********** End Function HandleSocialFriendsTab constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialFriendsTab", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialFriendsTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialFriendsTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialFriendsTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialFriendsTab *****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialGuildCreate **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildCreate_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialGuildCreate constinit property declarations ***************
// ********** End Function HandleSocialGuildCreate constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialGuildCreate", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildCreate(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialGuildCreate)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialGuildCreate();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialGuildCreate ****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialGuildDisband *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildDisband_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialGuildDisband constinit property declarations **************
// ********** End Function HandleSocialGuildDisband constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialGuildDisband", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildDisband(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialGuildDisband)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialGuildDisband();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialGuildDisband ***************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialGuildLeave ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildLeave_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialGuildLeave constinit property declarations ****************
// ********** End Function HandleSocialGuildLeave constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialGuildLeave", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildLeave(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialGuildLeave)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialGuildLeave();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialGuildLeave *****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialGuildRename **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildRename_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialGuildRename constinit property declarations ***************
// ********** End Function HandleSocialGuildRename constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialGuildRename", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildRename(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialGuildRename)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialGuildRename();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialGuildRename ****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialGuildSearchChanged *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildSearchChanged_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleSocialGuildSearchChanged_Parms
	{
		FText SearchText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SearchText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialGuildSearchChanged constinit property declarations ********
	static const UECodeGen_Private::FTextPropertyParams NewProp_SearchText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleSocialGuildSearchChanged constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleSocialGuildSearchChanged Property Definitions *******************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_SearchText = { "SearchText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleSocialGuildSearchChanged_Parms, SearchText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SearchText_MetaData), NewProp_SearchText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SearchText,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleSocialGuildSearchChanged Property Definitions *********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialGuildSearchChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleSocialGuildSearchChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleSocialGuildSearchChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildSearchChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialGuildSearchChanged)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_SearchText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialGuildSearchChanged(Z_Param_Out_SearchText);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialGuildSearchChanged *********

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialGuildTab *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildTab_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialGuildTab constinit property declarations ******************
// ********** End Function HandleSocialGuildTab constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialGuildTab", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialGuildTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialGuildTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialGuildTab *******************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSocialTab **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialTab_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSocialTab constinit property declarations ***********************
// ********** End Function HandleSocialTab constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSocialTab", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSocialTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSocialTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSocialTab ************************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendBankDefense ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankDefense_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendBankDefense constinit property declarations ****************
// ********** End Function HandleSpendBankDefense constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendBankDefense", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankDefense(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendBankDefense)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendBankDefense();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendBankDefense *****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendBankHP ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankHP_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendBankHP constinit property declarations *********************
// ********** End Function HandleSpendBankHP constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendBankHP", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankHP(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendBankHP)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendBankHP();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendBankHP **********************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendBankIntelligence **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankIntelligence_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendBankIntelligence constinit property declarations ***********
// ********** End Function HandleSpendBankIntelligence constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendBankIntelligence", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankIntelligence(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendBankIntelligence)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendBankIntelligence();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendBankIntelligence ************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendBankSP ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankSP_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendBankSP constinit property declarations *********************
// ********** End Function HandleSpendBankSP constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendBankSP", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankSP(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendBankSP)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendBankSP();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendBankSP **********************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendBankSpeed *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankSpeed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendBankSpeed constinit property declarations ******************
// ********** End Function HandleSpendBankSpeed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendBankSpeed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankSpeed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendBankSpeed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendBankSpeed();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendBankSpeed *******************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendBankStrength **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankStrength_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendBankStrength constinit property declarations ***************
// ********** End Function HandleSpendBankStrength constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendBankStrength", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankStrength(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendBankStrength)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendBankStrength();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendBankStrength ****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendPartyDefense **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyDefense_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendPartyDefense constinit property declarations ***************
// ********** End Function HandleSpendPartyDefense constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendPartyDefense", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyDefense(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendPartyDefense)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendPartyDefense();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendPartyDefense ****************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendPartyHP *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyHP_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendPartyHP constinit property declarations ********************
// ********** End Function HandleSpendPartyHP constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendPartyHP", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyHP(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendPartyHP)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendPartyHP();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendPartyHP *********************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendPartyIntelligence *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyIntelligence_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendPartyIntelligence constinit property declarations **********
// ********** End Function HandleSpendPartyIntelligence constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendPartyIntelligence", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyIntelligence(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendPartyIntelligence)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendPartyIntelligence();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendPartyIntelligence ***********

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendPartySP *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartySP_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendPartySP constinit property declarations ********************
// ********** End Function HandleSpendPartySP constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendPartySP", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartySP(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendPartySP)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendPartySP();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendPartySP *********************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendPartySpeed ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartySpeed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendPartySpeed constinit property declarations *****************
// ********** End Function HandleSpendPartySpeed constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendPartySpeed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartySpeed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendPartySpeed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendPartySpeed();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendPartySpeed ******************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleSpendPartyStrength *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyStrength_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSpendPartyStrength constinit property declarations **************
// ********** End Function HandleSpendPartyStrength constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleSpendPartyStrength", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyStrength(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleSpendPartyStrength)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSpendPartyStrength();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleSpendPartyStrength ***************

// ********** Begin Class UDMFDigimonInventoryWidget Function HandleStorageActionResult ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleStorageActionResult_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventHandleStorageActionResult_Parms
	{
		bool bSuccess;
		FText Message;
		FGuid DigimonInstanceId;
		EDMFDigimonStorageLocation NewLocation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleStorageActionResult constinit property declarations *************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFDigimonInventoryWidget_eventHandleStorageActionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewLocation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleStorageActionResult constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleStorageActionResult Property Definitions ************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonInventoryWidget_eventHandleStorageActionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleStorageActionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleStorageActionResult_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewLocation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewLocation = { "NewLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventHandleStorageActionResult_Parms, NewLocation), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation, METADATA_PARAMS(0, nullptr) }; // 8e1831166ad9bffb34f8008359e4dfa18eac358f
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewLocation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewLocation,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleStorageActionResult Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "HandleStorageActionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventHandleStorageActionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventHandleStorageActionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleStorageActionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execHandleStorageActionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_GET_ENUM(EDMFDigimonStorageLocation,Z_Param_NewLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStorageActionResult(Z_Param_bSuccess,Z_Param_Message,Z_Param_DigimonInstanceId,EDMFDigimonStorageLocation(Z_Param_NewLocation));
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function HandleStorageActionResult **************

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

// ********** Begin Class UDMFDigimonInventoryWidget Function RefreshBankData **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshBankData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Bank" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshBankData constinit property declarations ***********************
// ********** End Function RefreshBankData constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "RefreshBankData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshBankData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execRefreshBankData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshBankData();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function RefreshBankData ************************

// ********** Begin Class UDMFDigimonInventoryWidget Function RefreshCareData **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshCareData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Care" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshCareData constinit property declarations ***********************
// ********** End Function RefreshCareData constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "RefreshCareData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshCareData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execRefreshCareData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshCareData();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function RefreshCareData ************************

// ********** Begin Class UDMFDigimonInventoryWidget Function RefreshDigiDexData *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshDigiDexData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|DigiDex" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Refreshes the read-only encyclopedia of every registered DMFDigimonSpecies primary asset. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Refreshes the read-only encyclopedia of every registered DMFDigimonSpecies primary asset." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshDigiDexData constinit property declarations ********************
// ********** End Function RefreshDigiDexData constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "RefreshDigiDexData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshDigiDexData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execRefreshDigiDexData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshDigiDexData();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function RefreshDigiDexData *********************

// ********** Begin Class UDMFDigimonInventoryWidget Function RefreshDigivolutionData **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshDigivolutionData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Digivolution" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshDigivolutionData constinit property declarations ***************
// ********** End Function RefreshDigivolutionData constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "RefreshDigivolutionData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshDigivolutionData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execRefreshDigivolutionData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshDigivolutionData();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function RefreshDigivolutionData ****************

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

// ********** Begin Class UDMFDigimonInventoryWidget Function RefreshNearbyPlayersData *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshNearbyPlayersData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friends|Nearby Players" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Refreshes the owner-local nearest-first player discovery panel from already-replicated avatar transforms. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Refreshes the owner-local nearest-first player discovery panel from already-replicated avatar transforms." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshNearbyPlayersData constinit property declarations **************
// ********** End Function RefreshNearbyPlayersData constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "RefreshNearbyPlayersData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshNearbyPlayersData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execRefreshNearbyPlayersData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshNearbyPlayersData();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function RefreshNearbyPlayersData ***************

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

// ********** Begin Class UDMFDigimonInventoryWidget Function RefreshSocialData ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshSocialData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Refreshes the owner-only persistent Social presentation from the controller's last authoritative snapshot. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Refreshes the owner-only persistent Social presentation from the controller's last authoritative snapshot." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshSocialData constinit property declarations *********************
// ********** End Function RefreshSocialData constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "RefreshSocialData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshSocialData(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execRefreshSocialData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshSocialData();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function RefreshSocialData **********************

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
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewTab = { "NewTab", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventSetActiveMenuTab_Parms, NewTab), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab, METADATA_PARAMS(0, nullptr) }; // 852449354d178a314ff17e0e8d18ca162511f67f
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

// ********** Begin Class UDMFDigimonInventoryWidget Function SetActiveSocialTab *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonInventoryWidget_SetActiveSocialTab_Statics
struct UHT_STATICS
{
	struct DMFDigimonInventoryWidget_eventSetActiveSocialTab_Parms
	{
		EDMFSocialMenuTab NewTab;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetActiveSocialTab constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewTab_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewTab;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetActiveSocialTab constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetActiveSocialTab Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewTab_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewTab = { "NewTab", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonInventoryWidget_eventSetActiveSocialTab_Parms, NewTab), Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialMenuTab, METADATA_PARAMS(0, nullptr) }; // c2772bcfe79854528e4846d626dc8fb9d264a833
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTab_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTab,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetActiveSocialTab Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonInventoryWidget, nullptr, "SetActiveSocialTab", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonInventoryWidget_eventSetActiveSocialTab_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonInventoryWidget_eventSetActiveSocialTab_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonInventoryWidget_SetActiveSocialTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonInventoryWidget::execSetActiveSocialTab)
{
	P_GET_ENUM(EDMFSocialMenuTab,Z_Param_NewTab);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetActiveSocialTab(EDMFSocialMenuTab(Z_Param_NewTab));
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonInventoryWidget Function SetActiveSocialTab *********************

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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedExperienceProgressBar_MetaData[] = {
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveSelectedToBankButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendPartyHPButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native fallback Attribute Point spend controls. Custom Blueprint UI may call ServerSpendDigimonAttributePoint directly. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native fallback Attribute Point spend controls. Custom Blueprint UI may call ServerSpendDigimonAttributePoint directly." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendPartySPButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendPartyStrengthButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendPartyIntelligenceButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendPartyDefenseButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendPartySpeedButton_MetaData[] = {
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankTabButton_MetaData[] = {
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankDigimonGrid_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankCountText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankPageText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankSelectionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankSelectedPortraitImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankSelectedNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankSelectedMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankSelectedStatsText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankExperienceProgressBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankPartyDestinationGrid_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankPreviousPageButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankNextPageButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveSelectedBankToPartyButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendBankHPButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendBankSPButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendBankStrengthButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendBankIntelligenceButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendBankDefenseButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpendBankSpeedButton_MetaData[] = {
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CarePortraitImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareHungerText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareHungerProgressBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareHappinessProgressBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareDisciplineProgressBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareStatisticsText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareWasteStatusText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareFeedingRulesText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FeedDigiMeatButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexSpeciesGrid_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexSearchBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexStageFilterButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexAttributeFilterButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexStageFilterText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexAttributeFilterText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexCountText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexSelectedPortraitImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexSelectedNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexSelectedMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexSelectedStatusText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexSelectedStatsText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexSelectedEvolutionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexSelectedDescriptionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionOwnedGrid_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionPathList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionCurrentPortraitImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionCurrentNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionCurrentMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionTargetPortraitImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionTargetNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionTargetMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionRequirementText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolveButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialFriendsTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Social shell. Friends is the default nested page the first time Social is opened.\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Social shell. Friends is the default nested page the first time Social is opened." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialNearbyPlayersList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialFriendsList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialFriendRequestsList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialIgnoreList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildIdentityText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildMembersList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildInvitesList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildApplicationsList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildSearchList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildNameInput_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildSearchInput_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildCreateButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildRenameButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildLeaveButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonInventoryWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildDisbandButton_MetaData[] = {
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BankContentRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanContentRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareContentRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionContentRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexContentRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialContentRoot_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialFriendsContentRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialGuildContentRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonInventoryWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFDigimonInventoryWidget constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonChoicesBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonDetailsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedExperienceProgressBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryCountText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedStageText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedStateText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedDescriptionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedPortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SummonDigimonButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RecallDigimonButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveSelectedToBankButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendPartyHPButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendPartySPButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendPartyStrengthButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendPartyIntelligenceButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendPartyDefenseButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendPartySpeedButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseDigimonInventoryButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollectionTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanMaterializeTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankDigimonGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankCountText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankPageText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankSelectionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankSelectedPortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankSelectedNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankSelectedMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankSelectedStatsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankExperienceProgressBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankPartyDestinationGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankPreviousPageButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankNextPageButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveSelectedBankToPartyButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendBankHPButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendBankSPButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendBankStrengthButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendBankIntelligenceButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendBankDefenseButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpendBankSpeedButton;
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CarePortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareHungerText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareHungerProgressBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareHappinessProgressBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareDisciplineProgressBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareStatisticsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareWasteStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareFeedingRulesText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FeedDigiMeatButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexSpeciesGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexSearchBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexStageFilterButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexAttributeFilterButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexStageFilterText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexAttributeFilterText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexCountText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexSelectedPortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexSelectedNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexSelectedMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexSelectedStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexSelectedStatsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexSelectedEvolutionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexSelectedDescriptionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionOwnedGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionPathList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionCurrentPortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionCurrentNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionCurrentMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionTargetPortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionTargetNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionTargetMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionRequirementText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolveButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialFriendsTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialNearbyPlayersList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialFriendsList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialFriendRequestsList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialIgnoreList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildIdentityText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildMembersList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildInvitesList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildApplicationsList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildSearchList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildNameInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildSearchInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildCreateButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildRenameButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildLeaveButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildDisbandButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundDigimonComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryContentRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BankContentRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanContentRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CareContentRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigivolutionContentRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigiDexContentRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialContentRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialFriendsContentRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SocialGuildContentRow;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFDigimonInventoryWidget constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetActiveMenuTab"), .Pointer = &UDMFDigimonInventoryWidget::execGetActiveMenuTab },
		{ .NameUTF8 = UTF8TEXT("GetActiveSocialTab"), .Pointer = &UDMFDigimonInventoryWidget::execGetActiveSocialTab },
		{ .NameUTF8 = UTF8TEXT("GetDigiDexSpeciesIds"), .Pointer = &UDMFDigimonInventoryWidget::execGetDigiDexSpeciesIds },
		{ .NameUTF8 = UTF8TEXT("GetSelectedDigiDexSpeciesId"), .Pointer = &UDMFDigimonInventoryWidget::execGetSelectedDigiDexSpeciesId },
		{ .NameUTF8 = UTF8TEXT("GetSelectedDigimonInstanceId"), .Pointer = &UDMFDigimonInventoryWidget::execGetSelectedDigimonInstanceId },
		{ .NameUTF8 = UTF8TEXT("HandleAttributePointSpendResult"), .Pointer = &UDMFDigimonInventoryWidget::execHandleAttributePointSpendResult },
		{ .NameUTF8 = UTF8TEXT("HandleBankChanged"), .Pointer = &UDMFDigimonInventoryWidget::execHandleBankChanged },
		{ .NameUTF8 = UTF8TEXT("HandleBankDigimonPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleBankDigimonPressed },
		{ .NameUTF8 = UTF8TEXT("HandleBankNextPage"), .Pointer = &UDMFDigimonInventoryWidget::execHandleBankNextPage },
		{ .NameUTF8 = UTF8TEXT("HandleBankPartyDestinationPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleBankPartyDestinationPressed },
		{ .NameUTF8 = UTF8TEXT("HandleBankPreviousPage"), .Pointer = &UDMFDigimonInventoryWidget::execHandleBankPreviousPage },
		{ .NameUTF8 = UTF8TEXT("HandleBankTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleBankTab },
		{ .NameUTF8 = UTF8TEXT("HandleCareSequenceFinished"), .Pointer = &UDMFDigimonInventoryWidget::execHandleCareSequenceFinished },
		{ .NameUTF8 = UTF8TEXT("HandleCareStateChanged"), .Pointer = &UDMFDigimonInventoryWidget::execHandleCareStateChanged },
		{ .NameUTF8 = UTF8TEXT("HandleCareTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleCareTab },
		{ .NameUTF8 = UTF8TEXT("HandleClose"), .Pointer = &UDMFDigimonInventoryWidget::execHandleClose },
		{ .NameUTF8 = UTF8TEXT("HandleCollectionTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleCollectionTab },
		{ .NameUTF8 = UTF8TEXT("HandleDigiDexAttributeFilter"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigiDexAttributeFilter },
		{ .NameUTF8 = UTF8TEXT("HandleDigiDexSearchChanged"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigiDexSearchChanged },
		{ .NameUTF8 = UTF8TEXT("HandleDigiDexSpeciesPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigiDexSpeciesPressed },
		{ .NameUTF8 = UTF8TEXT("HandleDigiDexStageFilter"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigiDexStageFilter },
		{ .NameUTF8 = UTF8TEXT("HandleDigiDexTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigiDexTab },
		{ .NameUTF8 = UTF8TEXT("HandleDigimonPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigimonPressed },
		{ .NameUTF8 = UTF8TEXT("HandleDigivolutionOwnedPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigivolutionOwnedPressed },
		{ .NameUTF8 = UTF8TEXT("HandleDigivolutionResult"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigivolutionResult },
		{ .NameUTF8 = UTF8TEXT("HandleDigivolutionTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigivolutionTab },
		{ .NameUTF8 = UTF8TEXT("HandleDigivolutionTargetPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigivolutionTargetPressed },
		{ .NameUTF8 = UTF8TEXT("HandleDigivolveSelected"), .Pointer = &UDMFDigimonInventoryWidget::execHandleDigivolveSelected },
		{ .NameUTF8 = UTF8TEXT("HandleFeedDigiMeat"), .Pointer = &UDMFDigimonInventoryWidget::execHandleFeedDigiMeat },
		{ .NameUTF8 = UTF8TEXT("HandleInventoryChanged"), .Pointer = &UDMFDigimonInventoryWidget::execHandleInventoryChanged },
		{ .NameUTF8 = UTF8TEXT("HandleMaterializationResult"), .Pointer = &UDMFDigimonInventoryWidget::execHandleMaterializationResult },
		{ .NameUTF8 = UTF8TEXT("HandleMaterializeSelected"), .Pointer = &UDMFDigimonInventoryWidget::execHandleMaterializeSelected },
		{ .NameUTF8 = UTF8TEXT("HandleMoveSelectedBankToParty"), .Pointer = &UDMFDigimonInventoryWidget::execHandleMoveSelectedBankToParty },
		{ .NameUTF8 = UTF8TEXT("HandleMoveSelectedToBank"), .Pointer = &UDMFDigimonInventoryWidget::execHandleMoveSelectedToBank },
		{ .NameUTF8 = UTF8TEXT("HandlePartnerActionResult"), .Pointer = &UDMFDigimonInventoryWidget::execHandlePartnerActionResult },
		{ .NameUTF8 = UTF8TEXT("HandleRecallPartner"), .Pointer = &UDMFDigimonInventoryWidget::execHandleRecallPartner },
		{ .NameUTF8 = UTF8TEXT("HandleScanDataChanged"), .Pointer = &UDMFDigimonInventoryWidget::execHandleScanDataChanged },
		{ .NameUTF8 = UTF8TEXT("HandleScanMaterializeTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleScanMaterializeTab },
		{ .NameUTF8 = UTF8TEXT("HandleScanSpeciesPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleScanSpeciesPressed },
		{ .NameUTF8 = UTF8TEXT("HandleSocialActionButtonPressed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialActionButtonPressed },
		{ .NameUTF8 = UTF8TEXT("HandleSocialActionFeedback"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialActionFeedback },
		{ .NameUTF8 = UTF8TEXT("HandleSocialFriendsTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialFriendsTab },
		{ .NameUTF8 = UTF8TEXT("HandleSocialGuildCreate"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialGuildCreate },
		{ .NameUTF8 = UTF8TEXT("HandleSocialGuildDisband"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialGuildDisband },
		{ .NameUTF8 = UTF8TEXT("HandleSocialGuildLeave"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialGuildLeave },
		{ .NameUTF8 = UTF8TEXT("HandleSocialGuildRename"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialGuildRename },
		{ .NameUTF8 = UTF8TEXT("HandleSocialGuildSearchChanged"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialGuildSearchChanged },
		{ .NameUTF8 = UTF8TEXT("HandleSocialGuildTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialGuildTab },
		{ .NameUTF8 = UTF8TEXT("HandleSocialTab"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSocialTab },
		{ .NameUTF8 = UTF8TEXT("HandleSpendBankDefense"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendBankDefense },
		{ .NameUTF8 = UTF8TEXT("HandleSpendBankHP"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendBankHP },
		{ .NameUTF8 = UTF8TEXT("HandleSpendBankIntelligence"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendBankIntelligence },
		{ .NameUTF8 = UTF8TEXT("HandleSpendBankSP"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendBankSP },
		{ .NameUTF8 = UTF8TEXT("HandleSpendBankSpeed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendBankSpeed },
		{ .NameUTF8 = UTF8TEXT("HandleSpendBankStrength"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendBankStrength },
		{ .NameUTF8 = UTF8TEXT("HandleSpendPartyDefense"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendPartyDefense },
		{ .NameUTF8 = UTF8TEXT("HandleSpendPartyHP"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendPartyHP },
		{ .NameUTF8 = UTF8TEXT("HandleSpendPartyIntelligence"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendPartyIntelligence },
		{ .NameUTF8 = UTF8TEXT("HandleSpendPartySP"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendPartySP },
		{ .NameUTF8 = UTF8TEXT("HandleSpendPartySpeed"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendPartySpeed },
		{ .NameUTF8 = UTF8TEXT("HandleSpendPartyStrength"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSpendPartyStrength },
		{ .NameUTF8 = UTF8TEXT("HandleStorageActionResult"), .Pointer = &UDMFDigimonInventoryWidget::execHandleStorageActionResult },
		{ .NameUTF8 = UTF8TEXT("HandleSummonSelected"), .Pointer = &UDMFDigimonInventoryWidget::execHandleSummonSelected },
		{ .NameUTF8 = UTF8TEXT("RefreshBankData"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshBankData },
		{ .NameUTF8 = UTF8TEXT("RefreshCareData"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshCareData },
		{ .NameUTF8 = UTF8TEXT("RefreshDigiDexData"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshDigiDexData },
		{ .NameUTF8 = UTF8TEXT("RefreshDigivolutionData"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshDigivolutionData },
		{ .NameUTF8 = UTF8TEXT("RefreshInventory"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshInventory },
		{ .NameUTF8 = UTF8TEXT("RefreshNearbyPlayersData"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshNearbyPlayersData },
		{ .NameUTF8 = UTF8TEXT("RefreshScanData"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshScanData },
		{ .NameUTF8 = UTF8TEXT("RefreshSocialData"), .Pointer = &UDMFDigimonInventoryWidget::execRefreshSocialData },
		{ .NameUTF8 = UTF8TEXT("SetActiveMenuTab"), .Pointer = &UDMFDigimonInventoryWidget::execSetActiveMenuTab },
		{ .NameUTF8 = UTF8TEXT("SetActiveSocialTab"), .Pointer = &UDMFDigimonInventoryWidget::execSetActiveSocialTab },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnDigiDexSelectionChanged, "BP_OnDigiDexSelectionChanged" }, // 2f2747d4903c654022690ece805fba3cb5747851
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnDigimonPreviewChanged, "BP_OnDigimonPreviewChanged" }, // 622e0a91ea09846567561cb4fcb10f6ce6edb6ae
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_BP_OnPartnerActionResult, "BP_OnPartnerActionResult" }, // 53795b8dddaa4fd76ff5279e629c6e336fc6fcc3
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetActiveMenuTab, "GetActiveMenuTab" }, // a7815f40fcef9acde97eeab613960bbb01738671
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetActiveSocialTab, "GetActiveSocialTab" }, // f546d92d1caac42b2214386b3e7a6e642027e4d9
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetDigiDexSpeciesIds, "GetDigiDexSpeciesIds" }, // 32b0d89402b7f277591e84150783735571b7b866
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetSelectedDigiDexSpeciesId, "GetSelectedDigiDexSpeciesId" }, // 33a611e78f5091bbc9b30793a29724624a8ccd51
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_GetSelectedDigimonInstanceId, "GetSelectedDigimonInstanceId" }, // 14399957d0996c285444e28d739eb535c4f017d5
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleAttributePointSpendResult, "HandleAttributePointSpendResult" }, // b344dbef7f1e3b15890f83779d08dfd96405bb19
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankChanged, "HandleBankChanged" }, // 055cb0d6a464758fdcc09d831b69741658f7e821
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankDigimonPressed, "HandleBankDigimonPressed" }, // 83491ce8edb248d61fec40dd4d53d72c3139b987
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankNextPage, "HandleBankNextPage" }, // 71bee5309d83ad408a0f5423a949e4616a64f02d
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankPartyDestinationPressed, "HandleBankPartyDestinationPressed" }, // 7cd6822e92a30ec439f2afd8b10009ee16ee2537
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankPreviousPage, "HandleBankPreviousPage" }, // cacc2b2978e855c5c6532a0a7b21ddbe4614467a
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleBankTab, "HandleBankTab" }, // 2924892787dedbe62111483e614794e7ed42ec31
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCareSequenceFinished, "HandleCareSequenceFinished" }, // 4ffef4be4951ff7cf57b38cc881e1ffc749b706f
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCareStateChanged, "HandleCareStateChanged" }, // fa00c1e6a5ec452257bc42ad13a3e125e021447d
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCareTab, "HandleCareTab" }, // 61c68b8017cd34309a27c15c82b8aca609997b83
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleClose, "HandleClose" }, // 477c2cacd8bfff5ad8241a06bd3f74da94bf4e55
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleCollectionTab, "HandleCollectionTab" }, // 622846a94537b4bc0bfa7db654f3435d8ad78097
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexAttributeFilter, "HandleDigiDexAttributeFilter" }, // 455c262d2b1558ab80d9314243c96c7013ba7d0b
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexSearchChanged, "HandleDigiDexSearchChanged" }, // ab6e1a89af75ec3c0db8909871048d87e6f1d867
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexSpeciesPressed, "HandleDigiDexSpeciesPressed" }, // 5ad3f72bc4405487e0aabea1f01ce033b113f8c6
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexStageFilter, "HandleDigiDexStageFilter" }, // f1b5203e281d3d1b6a864f2858f1a8812b31b4e9
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigiDexTab, "HandleDigiDexTab" }, // 501e92720ec5520d110b5b3b78fa9c1213e08552
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigimonPressed, "HandleDigimonPressed" }, // 927395f5d6971893b8c92bbbc45214bbcb46f415
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionOwnedPressed, "HandleDigivolutionOwnedPressed" }, // f3bb9d472ac1407e84da3a7b82b39434a7f81fbc
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionResult, "HandleDigivolutionResult" }, // 260daa21a5540e658e84b831204732dbc539452c
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionTab, "HandleDigivolutionTab" }, // 0dda80f24aaf18ebd2ba1251b547d8e298790781
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolutionTargetPressed, "HandleDigivolutionTargetPressed" }, // f971911fdf667392bc9ba8aa4a6d89360053c554
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleDigivolveSelected, "HandleDigivolveSelected" }, // 521fe903adf3efa62ef40f58c8c38f1b43ce96eb
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleFeedDigiMeat, "HandleFeedDigiMeat" }, // 4fa91c05be1f21c9ccacf2201eb541915bcd8018
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleInventoryChanged, "HandleInventoryChanged" }, // 47863412eb4064cb03b7006c9243f38bd14a55c9
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMaterializationResult, "HandleMaterializationResult" }, // a5d7360d613759370ae18d7d0419fb287eb7cfdf
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMaterializeSelected, "HandleMaterializeSelected" }, // 1563989724bf7ad8e90d861bcace62b74f73c888
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMoveSelectedBankToParty, "HandleMoveSelectedBankToParty" }, // 1c24536727e62f6f6cf975b79a37430c4471ea0f
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleMoveSelectedToBank, "HandleMoveSelectedToBank" }, // 588ec1d5e1c830e6288dcd0a9f58aa32cf9c9341
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandlePartnerActionResult, "HandlePartnerActionResult" }, // 0efd23cd585f884ca5e8dd298ad5e3d0c00c14d2
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleRecallPartner, "HandleRecallPartner" }, // f859e2899dd9c2a359bb1c0943389bbbb430ec37
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanDataChanged, "HandleScanDataChanged" }, // cbfd164ed6547fdd9fd7e1724f1538877399a940
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanMaterializeTab, "HandleScanMaterializeTab" }, // 6f3f6687566a6bad859cdaac7c69535b64fb9ffa
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleScanSpeciesPressed, "HandleScanSpeciesPressed" }, // 9513951e9f84b4f85b6d0e96f949d819d5fddc84
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialActionButtonPressed, "HandleSocialActionButtonPressed" }, // 34667f3142239b4257d0286627123a43525ec4af
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialActionFeedback, "HandleSocialActionFeedback" }, // 80ef972c423462e043b2f39e3b859dd22f26d2a2
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialFriendsTab, "HandleSocialFriendsTab" }, // 4de362c0502c3a3491b02e78011d5fc1119ffcbb
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildCreate, "HandleSocialGuildCreate" }, // 7ad454cf6c48d600ff610533f6b7aae704731c54
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildDisband, "HandleSocialGuildDisband" }, // 1623a7da5bbf0bf5724ca0bfb83aa05252af8f4a
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildLeave, "HandleSocialGuildLeave" }, // d0c36fbd153353bde0333c144813608bea7bbf9c
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildRename, "HandleSocialGuildRename" }, // c3b6637077cdf65e21ca49d3d3b0fbb64f17bbff
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildSearchChanged, "HandleSocialGuildSearchChanged" }, // 32ec9e485181cfb1fd166c73890c3d5245671e5f
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialGuildTab, "HandleSocialGuildTab" }, // 6af007bbe7b7b7d8ede58c3c80e01a050c12ebfb
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSocialTab, "HandleSocialTab" }, // 31312c4d87cfb27c3d6a8e09b26f042da6a35bf6
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankDefense, "HandleSpendBankDefense" }, // 21e03bfb15b54fe302821e033ce9b0bc955e4d4f
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankHP, "HandleSpendBankHP" }, // fc99dc6904151881e54da171ba7f08ea1b6b8bfa
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankIntelligence, "HandleSpendBankIntelligence" }, // 1a493d548cefaee384ed49e7002415bfffe5cafe
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankSP, "HandleSpendBankSP" }, // dba1522a84a58578216c71b9dc433096024f6d64
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankSpeed, "HandleSpendBankSpeed" }, // f5b0a51a0b63c421d528be872135362ca640c6e6
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendBankStrength, "HandleSpendBankStrength" }, // 052081209df2e889a691e00742ffaba493b69716
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyDefense, "HandleSpendPartyDefense" }, // 864182e0ab5d4bd145c738826a411f5612ab7335
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyHP, "HandleSpendPartyHP" }, // 6a426eb2d263298d88d6d429a4fa6d30efc2553c
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyIntelligence, "HandleSpendPartyIntelligence" }, // 760c26faeed7801d52db785a7e29f3afcae634ec
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartySP, "HandleSpendPartySP" }, // b24835a58b884b7d81450818727eb1cc81f4ee05
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartySpeed, "HandleSpendPartySpeed" }, // 679ede419ee0da7c05f79362bb009c0972d9af91
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSpendPartyStrength, "HandleSpendPartyStrength" }, // 857e4c3dbd7ab8cb1505a431f03f06bc289a08c9
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleStorageActionResult, "HandleStorageActionResult" }, // c356cb4ee6e9fb64ff889e24f38d46dc513c5864
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_HandleSummonSelected, "HandleSummonSelected" }, // 40cb7ef02b2bcae9bfa80dd86b418c1a716bcd21
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshBankData, "RefreshBankData" }, // f6e1600b9b02af5cd9f1a0e9ddb334f17e9e30af
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshCareData, "RefreshCareData" }, // 37e7257c4acc6b5130c3c487290f2503640a8bc3
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshDigiDexData, "RefreshDigiDexData" }, // 428abc7bf23c3d7413185e6d15343e0ecf909f48
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshDigivolutionData, "RefreshDigivolutionData" }, // a884423172bd0a5ba4c07b379f6e668536b994ae
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshInventory, "RefreshInventory" }, // 8a93754174372b52bfea8109b1c82af35e69dc4b
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshNearbyPlayersData, "RefreshNearbyPlayersData" }, // d4d354734557ee915894382d9b13d0699990c43f
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshScanData, "RefreshScanData" }, // bd4d62282ee4dfeeb547d4063c5d339c485984b3
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_RefreshSocialData, "RefreshSocialData" }, // 9bee0bfa6b9ad68c2704ba1720423fc9695ffae0
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_SetActiveMenuTab, "SetActiveMenuTab" }, // 6364ae4856389c74e8d7573a092271e552106666
		{ &Z_Construct_UFunction_UDMFDigimonInventoryWidget_SetActiveSocialTab, "SetActiveSocialTab" }, // 455df2ecf1767d847c1af64f656b537e241cf36d
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
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedExperienceProgressBar = { "SelectedExperienceProgressBar", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedExperienceProgressBar), Z_Construct_UClass_UProgressBar, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedExperienceProgressBar_MetaData), NewProp_SelectedExperienceProgressBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonStatusText = { "DigimonStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigimonStatusText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonStatusText_MetaData), NewProp_DigimonStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InventoryCountText = { "InventoryCountText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, InventoryCountText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryCountText_MetaData), NewProp_InventoryCountText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedNameText = { "SelectedNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedNameText_MetaData), NewProp_SelectedNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedStageText = { "SelectedStageText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedStageText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedStageText_MetaData), NewProp_SelectedStageText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedStateText = { "SelectedStateText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedStateText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedStateText_MetaData), NewProp_SelectedStateText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedDescriptionText = { "SelectedDescriptionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedDescriptionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedDescriptionText_MetaData), NewProp_SelectedDescriptionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SelectedPortraitImage = { "SelectedPortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SelectedPortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedPortraitImage_MetaData), NewProp_SelectedPortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SummonDigimonButton = { "SummonDigimonButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SummonDigimonButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SummonDigimonButton_MetaData), NewProp_SummonDigimonButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RecallDigimonButton = { "RecallDigimonButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, RecallDigimonButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecallDigimonButton_MetaData), NewProp_RecallDigimonButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MoveSelectedToBankButton = { "MoveSelectedToBankButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, MoveSelectedToBankButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveSelectedToBankButton_MetaData), NewProp_MoveSelectedToBankButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendPartyHPButton = { "SpendPartyHPButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendPartyHPButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendPartyHPButton_MetaData), NewProp_SpendPartyHPButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendPartySPButton = { "SpendPartySPButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendPartySPButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendPartySPButton_MetaData), NewProp_SpendPartySPButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendPartyStrengthButton = { "SpendPartyStrengthButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendPartyStrengthButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendPartyStrengthButton_MetaData), NewProp_SpendPartyStrengthButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendPartyIntelligenceButton = { "SpendPartyIntelligenceButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendPartyIntelligenceButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendPartyIntelligenceButton_MetaData), NewProp_SpendPartyIntelligenceButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendPartyDefenseButton = { "SpendPartyDefenseButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendPartyDefenseButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendPartyDefenseButton_MetaData), NewProp_SpendPartyDefenseButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendPartySpeedButton = { "SpendPartySpeedButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendPartySpeedButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendPartySpeedButton_MetaData), NewProp_SpendPartySpeedButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CloseDigimonInventoryButton = { "CloseDigimonInventoryButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CloseDigimonInventoryButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseDigimonInventoryButton_MetaData), NewProp_CloseDigimonInventoryButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CollectionTabButton = { "CollectionTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CollectionTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollectionTabButton_MetaData), NewProp_CollectionTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankTabButton = { "BankTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankTabButton_MetaData), NewProp_BankTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanMaterializeTabButton = { "ScanMaterializeTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanMaterializeTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanMaterializeTabButton_MetaData), NewProp_ScanMaterializeTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareTabButton = { "CareTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareTabButton_MetaData), NewProp_CareTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionTabButton = { "DigivolutionTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionTabButton_MetaData), NewProp_DigivolutionTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexTabButton = { "DigiDexTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexTabButton_MetaData), NewProp_DigiDexTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialTabButton = { "SocialTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialTabButton_MetaData), NewProp_SocialTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankDigimonGrid = { "BankDigimonGrid", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankDigimonGrid), Z_Construct_UClass_UUniformGridPanel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankDigimonGrid_MetaData), NewProp_BankDigimonGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankCountText = { "BankCountText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankCountText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankCountText_MetaData), NewProp_BankCountText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankPageText = { "BankPageText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankPageText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankPageText_MetaData), NewProp_BankPageText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankSelectionText = { "BankSelectionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankSelectionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankSelectionText_MetaData), NewProp_BankSelectionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankSelectedPortraitImage = { "BankSelectedPortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankSelectedPortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankSelectedPortraitImage_MetaData), NewProp_BankSelectedPortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankSelectedNameText = { "BankSelectedNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankSelectedNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankSelectedNameText_MetaData), NewProp_BankSelectedNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankSelectedMetaText = { "BankSelectedMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankSelectedMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankSelectedMetaText_MetaData), NewProp_BankSelectedMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankSelectedStatsText = { "BankSelectedStatsText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankSelectedStatsText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankSelectedStatsText_MetaData), NewProp_BankSelectedStatsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankExperienceProgressBar = { "BankExperienceProgressBar", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankExperienceProgressBar), Z_Construct_UClass_UProgressBar, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankExperienceProgressBar_MetaData), NewProp_BankExperienceProgressBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankPartyDestinationGrid = { "BankPartyDestinationGrid", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankPartyDestinationGrid), Z_Construct_UClass_UUniformGridPanel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankPartyDestinationGrid_MetaData), NewProp_BankPartyDestinationGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankPreviousPageButton = { "BankPreviousPageButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankPreviousPageButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankPreviousPageButton_MetaData), NewProp_BankPreviousPageButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankNextPageButton = { "BankNextPageButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankNextPageButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankNextPageButton_MetaData), NewProp_BankNextPageButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MoveSelectedBankToPartyButton = { "MoveSelectedBankToPartyButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, MoveSelectedBankToPartyButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveSelectedBankToPartyButton_MetaData), NewProp_MoveSelectedBankToPartyButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendBankHPButton = { "SpendBankHPButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendBankHPButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendBankHPButton_MetaData), NewProp_SpendBankHPButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendBankSPButton = { "SpendBankSPButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendBankSPButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendBankSPButton_MetaData), NewProp_SpendBankSPButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendBankStrengthButton = { "SpendBankStrengthButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendBankStrengthButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendBankStrengthButton_MetaData), NewProp_SpendBankStrengthButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendBankIntelligenceButton = { "SpendBankIntelligenceButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendBankIntelligenceButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendBankIntelligenceButton_MetaData), NewProp_SpendBankIntelligenceButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendBankDefenseButton = { "SpendBankDefenseButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendBankDefenseButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendBankDefenseButton_MetaData), NewProp_SpendBankDefenseButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpendBankSpeedButton = { "SpendBankSpeedButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SpendBankSpeedButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpendBankSpeedButton_MetaData), NewProp_SpendBankSpeedButton_MetaData) };
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
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CarePortraitImage = { "CarePortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CarePortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CarePortraitImage_MetaData), NewProp_CarePortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareNameText = { "CareNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareNameText_MetaData), NewProp_CareNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareMetaText = { "CareMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareMetaText_MetaData), NewProp_CareMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareHungerText = { "CareHungerText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareHungerText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareHungerText_MetaData), NewProp_CareHungerText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareHungerProgressBar = { "CareHungerProgressBar", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareHungerProgressBar), Z_Construct_UClass_UProgressBar, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareHungerProgressBar_MetaData), NewProp_CareHungerProgressBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareHappinessProgressBar = { "CareHappinessProgressBar", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareHappinessProgressBar), Z_Construct_UClass_UProgressBar, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareHappinessProgressBar_MetaData), NewProp_CareHappinessProgressBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareDisciplineProgressBar = { "CareDisciplineProgressBar", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareDisciplineProgressBar), Z_Construct_UClass_UProgressBar, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareDisciplineProgressBar_MetaData), NewProp_CareDisciplineProgressBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareStatisticsText = { "CareStatisticsText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareStatisticsText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareStatisticsText_MetaData), NewProp_CareStatisticsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareWasteStatusText = { "CareWasteStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareWasteStatusText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareWasteStatusText_MetaData), NewProp_CareWasteStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareFeedingRulesText = { "CareFeedingRulesText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareFeedingRulesText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareFeedingRulesText_MetaData), NewProp_CareFeedingRulesText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FeedDigiMeatButton = { "FeedDigiMeatButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, FeedDigiMeatButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FeedDigiMeatButton_MetaData), NewProp_FeedDigiMeatButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexSpeciesGrid = { "DigiDexSpeciesGrid", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexSpeciesGrid), Z_Construct_UClass_UUniformGridPanel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexSpeciesGrid_MetaData), NewProp_DigiDexSpeciesGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexSearchBox = { "DigiDexSearchBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexSearchBox), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexSearchBox_MetaData), NewProp_DigiDexSearchBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexStageFilterButton = { "DigiDexStageFilterButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexStageFilterButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexStageFilterButton_MetaData), NewProp_DigiDexStageFilterButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexAttributeFilterButton = { "DigiDexAttributeFilterButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexAttributeFilterButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexAttributeFilterButton_MetaData), NewProp_DigiDexAttributeFilterButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexStageFilterText = { "DigiDexStageFilterText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexStageFilterText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexStageFilterText_MetaData), NewProp_DigiDexStageFilterText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexAttributeFilterText = { "DigiDexAttributeFilterText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexAttributeFilterText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexAttributeFilterText_MetaData), NewProp_DigiDexAttributeFilterText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexCountText = { "DigiDexCountText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexCountText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexCountText_MetaData), NewProp_DigiDexCountText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexSelectedPortraitImage = { "DigiDexSelectedPortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexSelectedPortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexSelectedPortraitImage_MetaData), NewProp_DigiDexSelectedPortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexSelectedNameText = { "DigiDexSelectedNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexSelectedNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexSelectedNameText_MetaData), NewProp_DigiDexSelectedNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexSelectedMetaText = { "DigiDexSelectedMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexSelectedMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexSelectedMetaText_MetaData), NewProp_DigiDexSelectedMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexSelectedStatusText = { "DigiDexSelectedStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexSelectedStatusText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexSelectedStatusText_MetaData), NewProp_DigiDexSelectedStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexSelectedStatsText = { "DigiDexSelectedStatsText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexSelectedStatsText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexSelectedStatsText_MetaData), NewProp_DigiDexSelectedStatsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexSelectedEvolutionText = { "DigiDexSelectedEvolutionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexSelectedEvolutionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexSelectedEvolutionText_MetaData), NewProp_DigiDexSelectedEvolutionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexSelectedDescriptionText = { "DigiDexSelectedDescriptionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexSelectedDescriptionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexSelectedDescriptionText_MetaData), NewProp_DigiDexSelectedDescriptionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionOwnedGrid = { "DigivolutionOwnedGrid", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionOwnedGrid), Z_Construct_UClass_UUniformGridPanel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionOwnedGrid_MetaData), NewProp_DigivolutionOwnedGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionPathList = { "DigivolutionPathList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionPathList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionPathList_MetaData), NewProp_DigivolutionPathList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionCurrentPortraitImage = { "DigivolutionCurrentPortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionCurrentPortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionCurrentPortraitImage_MetaData), NewProp_DigivolutionCurrentPortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionCurrentNameText = { "DigivolutionCurrentNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionCurrentNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionCurrentNameText_MetaData), NewProp_DigivolutionCurrentNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionCurrentMetaText = { "DigivolutionCurrentMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionCurrentMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionCurrentMetaText_MetaData), NewProp_DigivolutionCurrentMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionTargetPortraitImage = { "DigivolutionTargetPortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionTargetPortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionTargetPortraitImage_MetaData), NewProp_DigivolutionTargetPortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionTargetNameText = { "DigivolutionTargetNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionTargetNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionTargetNameText_MetaData), NewProp_DigivolutionTargetNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionTargetMetaText = { "DigivolutionTargetMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionTargetMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionTargetMetaText_MetaData), NewProp_DigivolutionTargetMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionRequirementText = { "DigivolutionRequirementText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionRequirementText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionRequirementText_MetaData), NewProp_DigivolutionRequirementText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolveButton = { "DigivolveButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolveButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolveButton_MetaData), NewProp_DigivolveButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialFriendsTabButton = { "SocialFriendsTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialFriendsTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialFriendsTabButton_MetaData), NewProp_SocialFriendsTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildTabButton = { "SocialGuildTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildTabButton_MetaData), NewProp_SocialGuildTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialNearbyPlayersList = { "SocialNearbyPlayersList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialNearbyPlayersList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialNearbyPlayersList_MetaData), NewProp_SocialNearbyPlayersList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialFriendsList = { "SocialFriendsList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialFriendsList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialFriendsList_MetaData), NewProp_SocialFriendsList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialFriendRequestsList = { "SocialFriendRequestsList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialFriendRequestsList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialFriendRequestsList_MetaData), NewProp_SocialFriendRequestsList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialIgnoreList = { "SocialIgnoreList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialIgnoreList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialIgnoreList_MetaData), NewProp_SocialIgnoreList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildIdentityText = { "SocialGuildIdentityText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildIdentityText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildIdentityText_MetaData), NewProp_SocialGuildIdentityText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildMetaText = { "SocialGuildMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildMetaText_MetaData), NewProp_SocialGuildMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildMembersList = { "SocialGuildMembersList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildMembersList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildMembersList_MetaData), NewProp_SocialGuildMembersList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildInvitesList = { "SocialGuildInvitesList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildInvitesList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildInvitesList_MetaData), NewProp_SocialGuildInvitesList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildApplicationsList = { "SocialGuildApplicationsList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildApplicationsList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildApplicationsList_MetaData), NewProp_SocialGuildApplicationsList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildSearchList = { "SocialGuildSearchList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildSearchList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildSearchList_MetaData), NewProp_SocialGuildSearchList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildNameInput = { "SocialGuildNameInput", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildNameInput), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildNameInput_MetaData), NewProp_SocialGuildNameInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildSearchInput = { "SocialGuildSearchInput", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildSearchInput), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildSearchInput_MetaData), NewProp_SocialGuildSearchInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildCreateButton = { "SocialGuildCreateButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildCreateButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildCreateButton_MetaData), NewProp_SocialGuildCreateButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildRenameButton = { "SocialGuildRenameButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildRenameButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildRenameButton_MetaData), NewProp_SocialGuildRenameButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildLeaveButton = { "SocialGuildLeaveButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildLeaveButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildLeaveButton_MetaData), NewProp_SocialGuildLeaveButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildDisbandButton = { "SocialGuildDisbandButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildDisbandButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildDisbandButton_MetaData), NewProp_SocialGuildDisbandButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BoundDigimonComponent = { "BoundDigimonComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BoundDigimonComponent), Z_Construct_UClass_UDMFPlayerDigimonComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundDigimonComponent_MetaData), NewProp_BoundDigimonComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InventoryContentRow = { "InventoryContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, InventoryContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryContentRow_MetaData), NewProp_InventoryContentRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BankContentRow = { "BankContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, BankContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BankContentRow_MetaData), NewProp_BankContentRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanContentRow = { "ScanContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, ScanContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanContentRow_MetaData), NewProp_ScanContentRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CareContentRow = { "CareContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, CareContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareContentRow_MetaData), NewProp_CareContentRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigivolutionContentRow = { "DigivolutionContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigivolutionContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionContentRow_MetaData), NewProp_DigivolutionContentRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigiDexContentRow = { "DigiDexContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, DigiDexContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexContentRow_MetaData), NewProp_DigiDexContentRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialContentRoot = { "SocialContentRoot", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialContentRoot), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialContentRoot_MetaData), NewProp_SocialContentRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialFriendsContentRow = { "SocialFriendsContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialFriendsContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialFriendsContentRow_MetaData), NewProp_SocialFriendsContentRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SocialGuildContentRow = { "SocialGuildContentRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonInventoryWidget, SocialGuildContentRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialGuildContentRow_MetaData), NewProp_SocialGuildContentRow_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonChoicesBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonDetailsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedExperienceProgressBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InventoryCountText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedStageText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedStateText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedDescriptionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedPortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SummonDigimonButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RecallDigimonButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MoveSelectedToBankButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendPartyHPButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendPartySPButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendPartyStrengthButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendPartyIntelligenceButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendPartyDefenseButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendPartySpeedButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CloseDigimonInventoryButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CollectionTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanMaterializeTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankDigimonGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankCountText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankPageText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankSelectionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankSelectedPortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankSelectedNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankSelectedMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankSelectedStatsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankExperienceProgressBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankPartyDestinationGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankPreviousPageButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankNextPageButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MoveSelectedBankToPartyButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendBankHPButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendBankSPButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendBankStrengthButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendBankIntelligenceButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendBankDefenseButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpendBankSpeedButton,
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
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CarePortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareHungerText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareHungerProgressBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareHappinessProgressBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareDisciplineProgressBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareStatisticsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareWasteStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareFeedingRulesText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FeedDigiMeatButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexSpeciesGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexSearchBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexStageFilterButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexAttributeFilterButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexStageFilterText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexAttributeFilterText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexCountText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexSelectedPortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexSelectedNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexSelectedMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexSelectedStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexSelectedStatsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexSelectedEvolutionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexSelectedDescriptionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionOwnedGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionPathList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionCurrentPortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionCurrentNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionCurrentMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionTargetPortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionTargetNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionTargetMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionRequirementText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolveButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialFriendsTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialNearbyPlayersList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialFriendsList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialFriendRequestsList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialIgnoreList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildIdentityText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildMembersList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildInvitesList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildApplicationsList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildSearchList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildNameInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildSearchInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildCreateButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildRenameButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildLeaveButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildDisbandButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BoundDigimonComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InventoryContentRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BankContentRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanContentRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareContentRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionContentRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexContentRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialContentRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialFriendsContentRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialGuildContentRow,
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
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFDigimonInventoryWidget, TEXT("UDMFDigimonInventoryWidget"), &Z_Registration_Info_UClass_UDMFDigimonInventoryWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFDigimonInventoryWidget), 115411615U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h__Script_DigimonMMOFramework_936b2b31232b5f58f203d718de34d1cdd610e16d{
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
