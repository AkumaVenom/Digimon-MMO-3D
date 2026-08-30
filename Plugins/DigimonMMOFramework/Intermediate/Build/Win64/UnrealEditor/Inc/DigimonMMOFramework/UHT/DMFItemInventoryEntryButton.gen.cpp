// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFItemInventoryEntryButton.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFItemInventoryEntryButton() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemInventoryEntryButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemInventoryEntryPressed__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemInventoryEntryButton(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFItemInventoryEntryPressed *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemInventoryEntryPressed__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFItemInventoryEntryPressed_Parms
	{
		FGuid StackId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemInventoryEntryButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFItemInventoryEntryPressed constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_StackId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFItemInventoryEntryPressed constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFItemInventoryEntryPressed Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StackId = { "StackId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemInventoryEntryPressed_Parms, StackId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StackId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFItemInventoryEntryPressed Property Definitions **********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFItemInventoryEntryPressed__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemInventoryEntryPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemInventoryEntryPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemInventoryEntryPressed__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFItemInventoryEntryPressed *******************************************

// ********** Begin Class UDMFItemInventoryEntryButton Function HandlePressed **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemInventoryEntryButton_HandlePressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemInventoryEntryButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePressed constinit property declarations *************************
// ********** End Function HandlePressed constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemInventoryEntryButton, nullptr, "HandlePressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemInventoryEntryButton_HandlePressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemInventoryEntryButton::execHandlePressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePressed();
	P_NATIVE_END;
}
// ********** End Class UDMFItemInventoryEntryButton Function HandlePressed ************************

// ********** Begin Class UDMFItemInventoryEntryButton Function InitializeItemEntry ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemInventoryEntryButton_InitializeItemEntry_Statics
struct UHT_STATICS
{
	struct DMFItemInventoryEntryButton_eventInitializeItemEntry_Parms
	{
		FGuid InStackId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Items" },
		{ "ModuleRelativePath", "Public/UI/DMFItemInventoryEntryButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeItemEntry constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InStackId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeItemEntry constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeItemEntry Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InStackId = { "InStackId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemInventoryEntryButton_eventInitializeItemEntry_Parms, InStackId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InStackId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeItemEntry Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemInventoryEntryButton, nullptr, "InitializeItemEntry", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemInventoryEntryButton_eventInitializeItemEntry_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemInventoryEntryButton_eventInitializeItemEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemInventoryEntryButton_InitializeItemEntry(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemInventoryEntryButton::execInitializeItemEntry)
{
	P_GET_STRUCT(FGuid,Z_Param_InStackId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeItemEntry(Z_Param_InStackId);
	P_NATIVE_END;
}
// ********** End Class UDMFItemInventoryEntryButton Function InitializeItemEntry ******************

// ********** Begin Class UDMFItemInventoryEntryButton *********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFItemInventoryEntryButton_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native stack button used by the polished ITEMS page. Stack identity never contains gameplay effect values. */" },
#endif
		{ "IncludePath", "UI/DMFItemInventoryEntryButton.h" },
		{ "ModuleRelativePath", "Public/UI/DMFItemInventoryEntryButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native stack button used by the polished ITEMS page. Stack identity never contains gameplay effect values." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnItemStackPressed_MetaData[] = {
		{ "Category", "Digimon MMO|Items" },
		{ "ModuleRelativePath", "Public/UI/DMFItemInventoryEntryButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StackId_MetaData[] = {
		{ "Category", "Digimon MMO|Items" },
		{ "ModuleRelativePath", "Public/UI/DMFItemInventoryEntryButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFItemInventoryEntryButton constinit property declarations *************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemStackPressed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StackId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFItemInventoryEntryButton constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandlePressed"), .Pointer = &UDMFItemInventoryEntryButton::execHandlePressed },
		{ .NameUTF8 = UTF8TEXT("InitializeItemEntry"), .Pointer = &UDMFItemInventoryEntryButton::execInitializeItemEntry },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFItemInventoryEntryButton_HandlePressed, "HandlePressed" }, // f413e394f6c29c9fb5a52b0b0125185da22d3107
		{ &Z_Construct_UFunction_UDMFItemInventoryEntryButton_InitializeItemEntry, "InitializeItemEntry" }, // 42cce5b6eb24a5a23971adf2cddd92d54ab62b99
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFItemInventoryEntryButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFItemInventoryEntryButton Property Definitions ************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnItemStackPressed = { "OnItemStackPressed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemInventoryEntryButton, OnItemStackPressed), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemInventoryEntryPressed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnItemStackPressed_MetaData), NewProp_OnItemStackPressed_MetaData) }; // 66b2b6f8008e4539397c46006c19880dc2d03a0f
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StackId = { "StackId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemInventoryEntryButton, StackId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StackId_MetaData), NewProp_StackId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnItemStackPressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StackId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFItemInventoryEntryButton Property Definitions **************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UButton,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFItemInventoryEntryButton,
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
	0x00B000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UDMFItemInventoryEntryButton_StaticRegisterNativesUDMFItemInventoryEntryButton()
{
	UClass* Class = UDMFItemInventoryEntryButton::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFItemInventoryEntryButton;
UClass* Z_Construct_UClass_UDMFItemInventoryEntryButton(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFItemInventoryEntryButton;
		if (!Z_Registration_Info_UClass_UDMFItemInventoryEntryButton.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFItemInventoryEntryButton"),
				Z_Registration_Info_UClass_UDMFItemInventoryEntryButton.InnerSingleton,
				UDMFItemInventoryEntryButton_StaticRegisterNativesUDMFItemInventoryEntryButton,
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
		return Z_Registration_Info_UClass_UDMFItemInventoryEntryButton.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFItemInventoryEntryButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFItemInventoryEntryButton.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFItemInventoryEntryButton.OuterSingleton;
}
#undef UHT_STATICS
UDMFItemInventoryEntryButton::UDMFItemInventoryEntryButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFItemInventoryEntryButton);
UDMFItemInventoryEntryButton::~UDMFItemInventoryEntryButton() {}
// ********** End Class UDMFItemInventoryEntryButton ***********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemInventoryEntryButton_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFItemInventoryEntryButton, TEXT("UDMFItemInventoryEntryButton"), &Z_Registration_Info_UClass_UDMFItemInventoryEntryButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFItemInventoryEntryButton), 2398022268U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemInventoryEntryButton_h__Script_DigimonMMOFramework_723aabfe73ae9d1049a5e44f3b6fc6234dc04c4b{
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
