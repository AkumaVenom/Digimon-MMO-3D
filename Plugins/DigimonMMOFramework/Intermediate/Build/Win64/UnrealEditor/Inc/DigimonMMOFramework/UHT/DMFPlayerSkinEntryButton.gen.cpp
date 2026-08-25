// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFPlayerSkinEntryButton.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFPlayerSkinEntryButton() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinEntryButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinEntryPressed__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinEntryButton(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFPlayerSkinEntryPressed ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinEntryPressed__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFPlayerSkinEntryPressed_Parms
	{
		FPrimaryAssetId SkinId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinEntryButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFPlayerSkinEntryPressed constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFPlayerSkinEntryPressed constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFPlayerSkinEntryPressed Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFPlayerSkinEntryPressed_Parms, SkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFPlayerSkinEntryPressed Property Definitions *************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFPlayerSkinEntryPressed__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSkinEntryPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFPlayerSkinEntryPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinEntryPressed__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFPlayerSkinEntryPressed **********************************************

// ********** Begin Class UDMFPlayerSkinEntryButton Function HandlePressed *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinEntryButton_HandlePressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinEntryButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePressed constinit property declarations *************************
// ********** End Function HandlePressed constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinEntryButton, nullptr, "HandlePressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerSkinEntryButton_HandlePressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSkinEntryButton::execHandlePressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePressed();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSkinEntryButton Function HandlePressed ***************************

// ********** Begin Class UDMFPlayerSkinEntryButton Function InitializePlayerSkinChoice ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSkinEntryButton_InitializePlayerSkinChoice_Statics
struct UHT_STATICS
{
	struct DMFPlayerSkinEntryButton_eventInitializePlayerSkinChoice_Parms
	{
		FPrimaryAssetId InSkinId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinEntryButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializePlayerSkinChoice constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSkinId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializePlayerSkinChoice constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializePlayerSkinChoice Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InSkinId = { "InSkinId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSkinEntryButton_eventInitializePlayerSkinChoice_Parms, InSkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InSkinId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializePlayerSkinChoice Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSkinEntryButton, nullptr, "InitializePlayerSkinChoice", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerSkinEntryButton_eventInitializePlayerSkinChoice_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerSkinEntryButton_eventInitializePlayerSkinChoice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerSkinEntryButton_InitializePlayerSkinChoice(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSkinEntryButton::execInitializePlayerSkinChoice)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_InSkinId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializePlayerSkinChoice(Z_Param_InSkinId);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSkinEntryButton Function InitializePlayerSkinChoice **************

// ********** Begin Class UDMFPlayerSkinEntryButton ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFPlayerSkinEntryButton_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/DMFPlayerSkinEntryButton.h" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinEntryButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPlayerSkinPressed_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinEntryButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkinId_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSkinEntryButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFPlayerSkinEntryButton constinit property declarations ****************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlayerSkinPressed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFPlayerSkinEntryButton constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandlePressed"), .Pointer = &UDMFPlayerSkinEntryButton::execHandlePressed },
		{ .NameUTF8 = UTF8TEXT("InitializePlayerSkinChoice"), .Pointer = &UDMFPlayerSkinEntryButton::execInitializePlayerSkinChoice },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFPlayerSkinEntryButton_HandlePressed, "HandlePressed" }, // e0de862f75ef5ed043e1d38bfb2cbc854f66f6f6
		{ &Z_Construct_UFunction_UDMFPlayerSkinEntryButton_InitializePlayerSkinChoice, "InitializePlayerSkinChoice" }, // 1bb285c66bcf3f92b3691912e37a78f5051a4c7f
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFPlayerSkinEntryButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFPlayerSkinEntryButton Property Definitions ***************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnPlayerSkinPressed = { "OnPlayerSkinPressed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinEntryButton, OnPlayerSkinPressed), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFPlayerSkinEntryPressed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPlayerSkinPressed_MetaData), NewProp_OnPlayerSkinPressed_MetaData) }; // 4e5488d11e7fe2ffe273dc67fb39547ce1657712
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinEntryButton, SkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkinId_MetaData), NewProp_SkinId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnPlayerSkinPressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFPlayerSkinEntryButton Property Definitions *****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UButton,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFPlayerSkinEntryButton,
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
static void UDMFPlayerSkinEntryButton_StaticRegisterNativesUDMFPlayerSkinEntryButton()
{
	UClass* Class = UDMFPlayerSkinEntryButton::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFPlayerSkinEntryButton;
UClass* Z_Construct_UClass_UDMFPlayerSkinEntryButton(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFPlayerSkinEntryButton;
		if (!Z_Registration_Info_UClass_UDMFPlayerSkinEntryButton.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFPlayerSkinEntryButton"),
				Z_Registration_Info_UClass_UDMFPlayerSkinEntryButton.InnerSingleton,
				UDMFPlayerSkinEntryButton_StaticRegisterNativesUDMFPlayerSkinEntryButton,
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
		return Z_Registration_Info_UClass_UDMFPlayerSkinEntryButton.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFPlayerSkinEntryButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFPlayerSkinEntryButton.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFPlayerSkinEntryButton.OuterSingleton;
}
#undef UHT_STATICS
UDMFPlayerSkinEntryButton::UDMFPlayerSkinEntryButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFPlayerSkinEntryButton);
UDMFPlayerSkinEntryButton::~UDMFPlayerSkinEntryButton() {}
// ********** End Class UDMFPlayerSkinEntryButton **************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPlayerSkinEntryButton_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFPlayerSkinEntryButton, TEXT("UDMFPlayerSkinEntryButton"), &Z_Registration_Info_UClass_UDMFPlayerSkinEntryButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFPlayerSkinEntryButton), 1425917027U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPlayerSkinEntryButton_h__Script_DigimonMMOFramework_df2f86781d652e446b2719b2bc50e99c6738bc35{
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
