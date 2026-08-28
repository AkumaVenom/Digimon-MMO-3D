// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Utility/DMFDigimonPresentationLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDigimonPresentationLibrary() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonPresentationLibrary(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonPresentationLibrary(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFDigimonPresentationLibrary Function GetDigimonStageDisplayText *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonPresentationLibrary_GetDigimonStageDisplayText_Statics
struct UHT_STATICS
{
	struct DMFDigimonPresentationLibrary_eventGetDigimonStageDisplayText_Parms
	{
		EDMFDigimonStage Stage;
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Presentation" },
		{ "DisplayName", "Get Digimon Stage Display Text" },
		{ "ModuleRelativePath", "Public/Utility/DMFDigimonPresentationLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDigimonStageDisplayText constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Stage_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Stage;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDigimonStageDisplayText constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDigimonStageDisplayText Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Stage_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Stage = { "Stage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonPresentationLibrary_eventGetDigimonStageDisplayText_Parms, Stage), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage, METADATA_PARAMS(0, nullptr) }; // e1b1442ac800f3afd36c160831786178fb89aaf0
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonPresentationLibrary_eventGetDigimonStageDisplayText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Stage_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Stage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetDigimonStageDisplayText Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonPresentationLibrary, nullptr, "GetDigimonStageDisplayText", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonPresentationLibrary_eventGetDigimonStageDisplayText_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonPresentationLibrary_eventGetDigimonStageDisplayText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonPresentationLibrary_GetDigimonStageDisplayText(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonPresentationLibrary::execGetDigimonStageDisplayText)
{
	P_GET_ENUM(EDMFDigimonStage,Z_Param_Stage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText(EDMFDigimonStage(Z_Param_Stage));
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonPresentationLibrary Function GetDigimonStageDisplayText *********

// ********** Begin Class UDMFDigimonPresentationLibrary *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFDigimonPresentationLibrary_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Canonical runtime presentation helpers for Digimon-authored data.\n *\n * Important: EDMFDigimonStage keeps its original serialized enum identifiers\n * (BabyI/BabyII) for backward compatibility with existing assets and saves.\n * Presentation must go through this library so cooked/runtime UI always shows\n * the canonical Digimon stage names (Fresh, In-Training, etc.).\n */" },
#endif
		{ "IncludePath", "Utility/DMFDigimonPresentationLibrary.h" },
		{ "ModuleRelativePath", "Public/Utility/DMFDigimonPresentationLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Canonical runtime presentation helpers for Digimon-authored data.\n\nImportant: EDMFDigimonStage keeps its original serialized enum identifiers\n(BabyI/BabyII) for backward compatibility with existing assets and saves.\nPresentation must go through this library so cooked/runtime UI always shows\nthe canonical Digimon stage names (Fresh, In-Training, etc.)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFDigimonPresentationLibrary constinit property declarations ***********
// ********** End Class UDMFDigimonPresentationLibrary constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetDigimonStageDisplayText"), .Pointer = &UDMFDigimonPresentationLibrary::execGetDigimonStageDisplayText },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFDigimonPresentationLibrary_GetDigimonStageDisplayText, "GetDigimonStageDisplayText" }, // 9dce5aeb5db50871e5867f3922f6a233ed6a5f02
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFDigimonPresentationLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UBlueprintFunctionLibrary,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFDigimonPresentationLibrary,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UDMFDigimonPresentationLibrary_StaticRegisterNativesUDMFDigimonPresentationLibrary()
{
	UClass* Class = UDMFDigimonPresentationLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFDigimonPresentationLibrary;
UClass* Z_Construct_UClass_UDMFDigimonPresentationLibrary(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFDigimonPresentationLibrary;
		if (!Z_Registration_Info_UClass_UDMFDigimonPresentationLibrary.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonPresentationLibrary"),
				Z_Registration_Info_UClass_UDMFDigimonPresentationLibrary.InnerSingleton,
				UDMFDigimonPresentationLibrary_StaticRegisterNativesUDMFDigimonPresentationLibrary,
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
		return Z_Registration_Info_UClass_UDMFDigimonPresentationLibrary.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFDigimonPresentationLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFDigimonPresentationLibrary.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFDigimonPresentationLibrary.OuterSingleton;
}
#undef UHT_STATICS
UDMFDigimonPresentationLibrary::UDMFDigimonPresentationLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFDigimonPresentationLibrary);
UDMFDigimonPresentationLibrary::~UDMFDigimonPresentationLibrary() {}
// ********** End Class UDMFDigimonPresentationLibrary *********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Utility_DMFDigimonPresentationLibrary_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFDigimonPresentationLibrary, TEXT("UDMFDigimonPresentationLibrary"), &Z_Registration_Info_UClass_UDMFDigimonPresentationLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFDigimonPresentationLibrary), 2897388802U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Utility_DMFDigimonPresentationLibrary_h__Script_DigimonMMOFramework_76d084e7e29fb44987d34f545c7c02844b340941{
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
