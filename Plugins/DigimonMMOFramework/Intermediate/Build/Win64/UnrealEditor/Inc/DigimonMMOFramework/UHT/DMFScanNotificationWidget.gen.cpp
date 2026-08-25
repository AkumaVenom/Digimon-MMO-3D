// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFScanNotificationWidget.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFScanNotificationWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UProgressBar(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFScanNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFScanNotificationWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFScanNotificationWidget Function BP_OnScanRewardPresented *************
struct DMFScanNotificationWidget_eventBP_OnScanRewardPresented_Parms
{
	FPrimaryAssetId SpeciesId;
	float AddedPercent;
	float NewPercent;
	bool bMaterializationReady;
};
static FName NAME_UDMFScanNotificationWidget_BP_OnScanRewardPresented = FName(TEXT("BP_OnScanRewardPresented"));
void UDMFScanNotificationWidget::BP_OnScanRewardPresented(FPrimaryAssetId SpeciesId, float AddedPercent, float NewPercent, bool bMaterializationReady)
{
	DMFScanNotificationWidget_eventBP_OnScanRewardPresented_Parms Parms;
	Parms.SpeciesId=SpeciesId;
	Parms.AddedPercent=AddedPercent;
	Parms.NewPercent=NewPercent;
	Parms.bMaterializationReady=bMaterializationReady ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_UDMFScanNotificationWidget_BP_OnScanRewardPresented);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFScanNotificationWidget_BP_OnScanRewardPresented_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Scan & Materialization" },
		{ "ModuleRelativePath", "Public/UI/DMFScanNotificationWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnScanRewardPresented constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AddedPercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewPercent;
	static void NewProp_bMaterializationReady_SetBit(void* Obj)
	{
		((DMFScanNotificationWidget_eventBP_OnScanRewardPresented_Parms*)Obj)->bMaterializationReady = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMaterializationReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnScanRewardPresented constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnScanRewardPresented Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFScanNotificationWidget_eventBP_OnScanRewardPresented_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AddedPercent = { "AddedPercent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFScanNotificationWidget_eventBP_OnScanRewardPresented_Parms, AddedPercent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NewPercent = { "NewPercent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFScanNotificationWidget_eventBP_OnScanRewardPresented_Parms, NewPercent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bMaterializationReady = { "bMaterializationReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFScanNotificationWidget_eventBP_OnScanRewardPresented_Parms), &UHT_STATICS::NewProp_bMaterializationReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AddedPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bMaterializationReady,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnScanRewardPresented Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFScanNotificationWidget, nullptr, "BP_OnScanRewardPresented", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFScanNotificationWidget_eventBP_OnScanRewardPresented_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFScanNotificationWidget_eventBP_OnScanRewardPresented_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFScanNotificationWidget_BP_OnScanRewardPresented(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFScanNotificationWidget Function BP_OnScanRewardPresented ***************

// ********** Begin Class UDMFScanNotificationWidget Function ShowScanReward ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFScanNotificationWidget_ShowScanReward_Statics
struct UHT_STATICS
{
	struct DMFScanNotificationWidget_eventShowScanReward_Parms
	{
		FPrimaryAssetId SpeciesId;
		float AddedPercent;
		float NewPercent;
		bool bMaterializationReady;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Scan & Materialization" },
		{ "ModuleRelativePath", "Public/UI/DMFScanNotificationWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ShowScanReward constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AddedPercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewPercent;
	static void NewProp_bMaterializationReady_SetBit(void* Obj)
	{
		((DMFScanNotificationWidget_eventShowScanReward_Parms*)Obj)->bMaterializationReady = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMaterializationReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ShowScanReward constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ShowScanReward Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFScanNotificationWidget_eventShowScanReward_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AddedPercent = { "AddedPercent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFScanNotificationWidget_eventShowScanReward_Parms, AddedPercent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NewPercent = { "NewPercent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFScanNotificationWidget_eventShowScanReward_Parms, NewPercent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bMaterializationReady = { "bMaterializationReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFScanNotificationWidget_eventShowScanReward_Parms), &UHT_STATICS::NewProp_bMaterializationReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AddedPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bMaterializationReady,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ShowScanReward Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFScanNotificationWidget, nullptr, "ShowScanReward", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFScanNotificationWidget_eventShowScanReward_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFScanNotificationWidget_eventShowScanReward_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFScanNotificationWidget_ShowScanReward(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFScanNotificationWidget::execShowScanReward)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SpeciesId);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AddedPercent);
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewPercent);
	P_GET_UBOOL(Z_Param_bMaterializationReady);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowScanReward(Z_Param_SpeciesId,Z_Param_AddedPercent,Z_Param_NewPercent,Z_Param_bMaterializationReady);
	P_NATIVE_END;
}
// ********** End Class UDMFScanNotificationWidget Function ShowScanReward *************************

// ********** Begin Class UDMFScanNotificationWidget ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFScanNotificationWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Polished transient Scan Data reward toast shown to the owning player only. */" },
#endif
		{ "IncludePath", "UI/DMFScanNotificationWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFScanNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Polished transient Scan Data reward toast shown to the owning player only." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesPortraitImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFScanNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFScanNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFScanNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFScanNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RewardText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFScanNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFScanNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReadyText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFScanNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFScanNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanProgressBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFScanNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFScanNotificationWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFScanNotificationWidget constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesPortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RewardText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReadyText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanProgressBar;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFScanNotificationWidget constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ShowScanReward"), .Pointer = &UDMFScanNotificationWidget::execShowScanReward },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFScanNotificationWidget_BP_OnScanRewardPresented, "BP_OnScanRewardPresented" }, // c118ebbe1ea358fd8d39ba8d27c7ac3cdf0d301e
		{ &Z_Construct_UFunction_UDMFScanNotificationWidget_ShowScanReward, "ShowScanReward" }, // 5d27a974b23253afaef19bfe8abf639c170748ac
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFScanNotificationWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFScanNotificationWidget Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpeciesPortraitImage = { "SpeciesPortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFScanNotificationWidget, SpeciesPortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesPortraitImage_MetaData), NewProp_SpeciesPortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpeciesNameText = { "SpeciesNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFScanNotificationWidget, SpeciesNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesNameText_MetaData), NewProp_SpeciesNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RewardText = { "RewardText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFScanNotificationWidget, RewardText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RewardText_MetaData), NewProp_RewardText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReadyText = { "ReadyText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFScanNotificationWidget, ReadyText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReadyText_MetaData), NewProp_ReadyText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanProgressBar = { "ScanProgressBar", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFScanNotificationWidget, ScanProgressBar), Z_Construct_UClass_UProgressBar, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanProgressBar_MetaData), NewProp_ScanProgressBar_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesPortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RewardText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReadyText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanProgressBar,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFScanNotificationWidget Property Definitions ****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFScanNotificationWidget,
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
static void UDMFScanNotificationWidget_StaticRegisterNativesUDMFScanNotificationWidget()
{
	UClass* Class = UDMFScanNotificationWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFScanNotificationWidget;
UClass* Z_Construct_UClass_UDMFScanNotificationWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFScanNotificationWidget;
		if (!Z_Registration_Info_UClass_UDMFScanNotificationWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFScanNotificationWidget"),
				Z_Registration_Info_UClass_UDMFScanNotificationWidget.InnerSingleton,
				UDMFScanNotificationWidget_StaticRegisterNativesUDMFScanNotificationWidget,
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
		return Z_Registration_Info_UClass_UDMFScanNotificationWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFScanNotificationWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFScanNotificationWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFScanNotificationWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFScanNotificationWidget::UDMFScanNotificationWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFScanNotificationWidget);
UDMFScanNotificationWidget::~UDMFScanNotificationWidget() {}
// ********** End Class UDMFScanNotificationWidget *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFScanNotificationWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFScanNotificationWidget, TEXT("UDMFScanNotificationWidget"), &Z_Registration_Info_UClass_UDMFScanNotificationWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFScanNotificationWidget), 757728382U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFScanNotificationWidget_h__Script_DigimonMMOFramework_a1b451644ffc863b0e21492b8f47aa114edb6c11{
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
