// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFHomeTeleportNotificationWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFHomeTeleportNotificationWidget() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFHomeTeleportNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFHomeTeleportNotificationWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFHomeTeleportNotificationWidget Function BP_OnHomeTeleportResultPresented 
struct DMFHomeTeleportNotificationWidget_eventBP_OnHomeTeleportResultPresented_Parms
{
	bool bSuccess;
	FText Message;
};
static FName NAME_UDMFHomeTeleportNotificationWidget_BP_OnHomeTeleportResultPresented = FName(TEXT("BP_OnHomeTeleportResultPresented"));
void UDMFHomeTeleportNotificationWidget::BP_OnHomeTeleportResultPresented(bool bSuccess, FText const& Message)
{
	DMFHomeTeleportNotificationWidget_eventBP_OnHomeTeleportResultPresented_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Message=Message;
	UFunction* Func = FindFunctionChecked(NAME_UDMFHomeTeleportNotificationWidget_BP_OnHomeTeleportResultPresented);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFHomeTeleportNotificationWidget_BP_OnHomeTeleportResultPresented_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access|Home" },
		{ "ModuleRelativePath", "Public/UI/DMFHomeTeleportNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnHomeTeleportResultPresented constinit property declarations ******
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFHomeTeleportNotificationWidget_eventBP_OnHomeTeleportResultPresented_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnHomeTeleportResultPresented constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnHomeTeleportResultPresented Property Definitions *****************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFHomeTeleportNotificationWidget_eventBP_OnHomeTeleportResultPresented_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHomeTeleportNotificationWidget_eventBP_OnHomeTeleportResultPresented_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnHomeTeleportResultPresented Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFHomeTeleportNotificationWidget, nullptr, "BP_OnHomeTeleportResultPresented", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFHomeTeleportNotificationWidget_eventBP_OnHomeTeleportResultPresented_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFHomeTeleportNotificationWidget_eventBP_OnHomeTeleportResultPresented_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFHomeTeleportNotificationWidget_BP_OnHomeTeleportResultPresented(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFHomeTeleportNotificationWidget Function BP_OnHomeTeleportResultPresented 

// ********** Begin Class UDMFHomeTeleportNotificationWidget Function ShowHomeTeleportResult *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFHomeTeleportNotificationWidget_ShowHomeTeleportResult_Statics
struct UHT_STATICS
{
	struct DMFHomeTeleportNotificationWidget_eventShowHomeTeleportResult_Parms
	{
		bool bSuccess;
		FText Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access|Home" },
		{ "ModuleRelativePath", "Public/UI/DMFHomeTeleportNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ShowHomeTeleportResult constinit property declarations ****************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFHomeTeleportNotificationWidget_eventShowHomeTeleportResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ShowHomeTeleportResult constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ShowHomeTeleportResult Property Definitions ***************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFHomeTeleportNotificationWidget_eventShowHomeTeleportResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFHomeTeleportNotificationWidget_eventShowHomeTeleportResult_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ShowHomeTeleportResult Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFHomeTeleportNotificationWidget, nullptr, "ShowHomeTeleportResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFHomeTeleportNotificationWidget_eventShowHomeTeleportResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFHomeTeleportNotificationWidget_eventShowHomeTeleportResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFHomeTeleportNotificationWidget_ShowHomeTeleportResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFHomeTeleportNotificationWidget::execShowHomeTeleportResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowHomeTeleportResult(Z_Param_bSuccess,Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class UDMFHomeTeleportNotificationWidget Function ShowHomeTeleportResult *********

// ********** Begin Class UDMFHomeTeleportNotificationWidget ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFHomeTeleportNotificationWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Owner-only transient result toast for the server-authoritative Return Home action. */" },
#endif
		{ "IncludePath", "UI/DMFHomeTeleportNotificationWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFHomeTeleportNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owner-only transient result toast for the server-authoritative Return Home action." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HomeTitleText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFHomeTeleportNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFHomeTeleportNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HomeMessageText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFHomeTeleportNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFHomeTeleportNotificationWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFHomeTeleportNotificationWidget constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HomeTitleText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HomeMessageText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFHomeTeleportNotificationWidget constinit property declarations *********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ShowHomeTeleportResult"), .Pointer = &UDMFHomeTeleportNotificationWidget::execShowHomeTeleportResult },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFHomeTeleportNotificationWidget_BP_OnHomeTeleportResultPresented, "BP_OnHomeTeleportResultPresented" }, // ef89917ebf40597a5d6ec6e8556d2039ded9c0e4
		{ &Z_Construct_UFunction_UDMFHomeTeleportNotificationWidget_ShowHomeTeleportResult, "ShowHomeTeleportResult" }, // cc323038e85905c3934f0bb87f5e132b1c59d99f
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFHomeTeleportNotificationWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFHomeTeleportNotificationWidget Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HomeTitleText = { "HomeTitleText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFHomeTeleportNotificationWidget, HomeTitleText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HomeTitleText_MetaData), NewProp_HomeTitleText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HomeMessageText = { "HomeMessageText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFHomeTeleportNotificationWidget, HomeMessageText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HomeMessageText_MetaData), NewProp_HomeMessageText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HomeTitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HomeMessageText,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFHomeTeleportNotificationWidget Property Definitions ********************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFHomeTeleportNotificationWidget,
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
static void UDMFHomeTeleportNotificationWidget_StaticRegisterNativesUDMFHomeTeleportNotificationWidget()
{
	UClass* Class = UDMFHomeTeleportNotificationWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFHomeTeleportNotificationWidget;
UClass* Z_Construct_UClass_UDMFHomeTeleportNotificationWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFHomeTeleportNotificationWidget;
		if (!Z_Registration_Info_UClass_UDMFHomeTeleportNotificationWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFHomeTeleportNotificationWidget"),
				Z_Registration_Info_UClass_UDMFHomeTeleportNotificationWidget.InnerSingleton,
				UDMFHomeTeleportNotificationWidget_StaticRegisterNativesUDMFHomeTeleportNotificationWidget,
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
		return Z_Registration_Info_UClass_UDMFHomeTeleportNotificationWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFHomeTeleportNotificationWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFHomeTeleportNotificationWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFHomeTeleportNotificationWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFHomeTeleportNotificationWidget::UDMFHomeTeleportNotificationWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFHomeTeleportNotificationWidget);
UDMFHomeTeleportNotificationWidget::~UDMFHomeTeleportNotificationWidget() {}
// ********** End Class UDMFHomeTeleportNotificationWidget *****************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFHomeTeleportNotificationWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFHomeTeleportNotificationWidget, TEXT("UDMFHomeTeleportNotificationWidget"), &Z_Registration_Info_UClass_UDMFHomeTeleportNotificationWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFHomeTeleportNotificationWidget), 1316826249U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFHomeTeleportNotificationWidget_h__Script_DigimonMMOFramework_988cb68cb154060d8c23c3f0ad5ccef7b7476229{
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
