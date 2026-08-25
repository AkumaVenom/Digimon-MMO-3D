// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFWorldNameplateWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFWorldNameplateWidget() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UBorder(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UProgressBar(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UVerticalBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldNameplateWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldNameplateWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFWorldNameplateWidget Function BP_OnNameplateRefreshed ****************
struct DMFWorldNameplateWidget_eventBP_OnNameplateRefreshed_Parms
{
	AActor* InObservedActor;
};
static FName NAME_UDMFWorldNameplateWidget_BP_OnNameplateRefreshed = FName(TEXT("BP_OnNameplateRefreshed"));
void UDMFWorldNameplateWidget::BP_OnNameplateRefreshed(AActor* InObservedActor)
{
	DMFWorldNameplateWidget_eventBP_OnNameplateRefreshed_Parms Parms;
	Parms.InObservedActor=InObservedActor;
	UFunction* Func = FindFunctionChecked(NAME_UDMFWorldNameplateWidget_BP_OnNameplateRefreshed);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldNameplateWidget_BP_OnNameplateRefreshed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Nameplates" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called after the native fallback has refreshed its presentation. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called after the native fallback has refreshed its presentation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnNameplateRefreshed constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InObservedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnNameplateRefreshed constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnNameplateRefreshed Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InObservedActor = { "InObservedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldNameplateWidget_eventBP_OnNameplateRefreshed_Parms, InObservedActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InObservedActor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnNameplateRefreshed Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldNameplateWidget, nullptr, "BP_OnNameplateRefreshed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFWorldNameplateWidget_eventBP_OnNameplateRefreshed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFWorldNameplateWidget_eventBP_OnNameplateRefreshed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldNameplateWidget_BP_OnNameplateRefreshed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFWorldNameplateWidget Function BP_OnNameplateRefreshed ******************

// ********** Begin Class UDMFWorldNameplateWidget Function GetObservedActor ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldNameplateWidget_GetObservedActor_Statics
struct UHT_STATICS
{
	struct DMFWorldNameplateWidget_eventGetObservedActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Nameplates" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObservedActor constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObservedActor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObservedActor Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldNameplateWidget_eventGetObservedActor_Parms, ReturnValue), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetObservedActor Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldNameplateWidget, nullptr, "GetObservedActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWorldNameplateWidget_eventGetObservedActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWorldNameplateWidget_eventGetObservedActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldNameplateWidget_GetObservedActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldNameplateWidget::execGetObservedActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetObservedActor();
	P_NATIVE_END;
}
// ********** End Class UDMFWorldNameplateWidget Function GetObservedActor *************************

// ********** Begin Class UDMFWorldNameplateWidget Function RefreshPresentation ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldNameplateWidget_RefreshPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Nameplates" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshPresentation constinit property declarations *******************
// ********** End Function RefreshPresentation constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldNameplateWidget, nullptr, "RefreshPresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFWorldNameplateWidget_RefreshPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldNameplateWidget::execRefreshPresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshPresentation();
	P_NATIVE_END;
}
// ********** End Class UDMFWorldNameplateWidget Function RefreshPresentation **********************

// ********** Begin Class UDMFWorldNameplateWidget Function SetObservedActor ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldNameplateWidget_SetObservedActor_Statics
struct UHT_STATICS
{
	struct DMFWorldNameplateWidget_eventSetObservedActor_Parms
	{
		AActor* InObservedActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Nameplates" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetObservedActor constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InObservedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetObservedActor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetObservedActor Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InObservedActor = { "InObservedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldNameplateWidget_eventSetObservedActor_Parms, InObservedActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InObservedActor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetObservedActor Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldNameplateWidget, nullptr, "SetObservedActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWorldNameplateWidget_eventSetObservedActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWorldNameplateWidget_eventSetObservedActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldNameplateWidget_SetObservedActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldNameplateWidget::execSetObservedActor)
{
	P_GET_OBJECT(AActor,Z_Param_InObservedActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetObservedActor(Z_Param_InObservedActor);
	P_NATIVE_END;
}
// ********** End Class UDMFWorldNameplateWidget Function SetObservedActor *************************

// ********** Begin Class UDMFWorldNameplateWidget *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFWorldNameplateWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Compact native world-space MMO nameplate used by both player avatars and Digimon.\n *\n * The widget is presentation-only. It reads already replicated actor/PlayerState/combat state and\n * never owns authority or sends network traffic. Blueprint children may completely reskin the\n * BindWidgetOptional surface while preserving the framework's actor-side attachment/visibility rules.\n */" },
#endif
		{ "IncludePath", "UI/DMFWorldNameplateWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compact native world-space MMO nameplate used by both player avatars and Digimon.\n\nThe widget is presentation-only. It reads already replicated actor/PlayerState/combat state and\nnever owns authority or sends network traffic. Blueprint children may completely reskin the\nBindWidgetOptional surface while preserving the framework's actor-side attachment/visibility rules." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NameplatePanel_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldNameplateWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldNameplateWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldNameplateWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonVitalsBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldNameplateWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthProgressBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldNameplateWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldNameplateWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObservedActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFWorldNameplateWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFWorldNameplateWidget constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NameplatePanel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonVitalsBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthProgressBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObservedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFWorldNameplateWidget constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetObservedActor"), .Pointer = &UDMFWorldNameplateWidget::execGetObservedActor },
		{ .NameUTF8 = UTF8TEXT("RefreshPresentation"), .Pointer = &UDMFWorldNameplateWidget::execRefreshPresentation },
		{ .NameUTF8 = UTF8TEXT("SetObservedActor"), .Pointer = &UDMFWorldNameplateWidget::execSetObservedActor },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFWorldNameplateWidget_BP_OnNameplateRefreshed, "BP_OnNameplateRefreshed" }, // 8c7d73f0946920493a809f243dc5fb63046f4797
		{ &Z_Construct_UFunction_UDMFWorldNameplateWidget_GetObservedActor, "GetObservedActor" }, // 36012550633cd0135f5c506460f28b261a584915
		{ &Z_Construct_UFunction_UDMFWorldNameplateWidget_RefreshPresentation, "RefreshPresentation" }, // 5f3175f3afd3795343069c88440eb18f4078dfa0
		{ &Z_Construct_UFunction_UDMFWorldNameplateWidget_SetObservedActor, "SetObservedActor" }, // 8353a30cab9c645330d940eb826e46352f938f21
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFWorldNameplateWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFWorldNameplateWidget Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NameplatePanel = { "NameplatePanel", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldNameplateWidget, NameplatePanel), Z_Construct_UClass_UBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NameplatePanel_MetaData), NewProp_NameplatePanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NameText = { "NameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldNameplateWidget, NameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NameText_MetaData), NewProp_NameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MetaText = { "MetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldNameplateWidget, MetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MetaText_MetaData), NewProp_MetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonVitalsBox = { "DigimonVitalsBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldNameplateWidget, DigimonVitalsBox), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonVitalsBox_MetaData), NewProp_DigimonVitalsBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealthProgressBar = { "HealthProgressBar", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldNameplateWidget, HealthProgressBar), Z_Construct_UClass_UProgressBar, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthProgressBar_MetaData), NewProp_HealthProgressBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HealthText = { "HealthText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldNameplateWidget, HealthText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthText_MetaData), NewProp_HealthText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ObservedActor = { "ObservedActor", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldNameplateWidget, ObservedActor), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObservedActor_MetaData), NewProp_ObservedActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NameplatePanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonVitalsBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealthProgressBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HealthText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ObservedActor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFWorldNameplateWidget Property Definitions ******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFWorldNameplateWidget,
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
static void UDMFWorldNameplateWidget_StaticRegisterNativesUDMFWorldNameplateWidget()
{
	UClass* Class = UDMFWorldNameplateWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFWorldNameplateWidget;
UClass* Z_Construct_UClass_UDMFWorldNameplateWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFWorldNameplateWidget;
		if (!Z_Registration_Info_UClass_UDMFWorldNameplateWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFWorldNameplateWidget"),
				Z_Registration_Info_UClass_UDMFWorldNameplateWidget.InnerSingleton,
				UDMFWorldNameplateWidget_StaticRegisterNativesUDMFWorldNameplateWidget,
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
		return Z_Registration_Info_UClass_UDMFWorldNameplateWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFWorldNameplateWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFWorldNameplateWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFWorldNameplateWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFWorldNameplateWidget::UDMFWorldNameplateWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFWorldNameplateWidget);
UDMFWorldNameplateWidget::~UDMFWorldNameplateWidget() {}
// ********** End Class UDMFWorldNameplateWidget ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldNameplateWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFWorldNameplateWidget, TEXT("UDMFWorldNameplateWidget"), &Z_Registration_Info_UClass_UDMFWorldNameplateWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFWorldNameplateWidget), 1919815475U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldNameplateWidget_h__Script_DigimonMMOFramework_bdd2e55dd09c92fd2eff2f2674052ea177c14db0{
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
