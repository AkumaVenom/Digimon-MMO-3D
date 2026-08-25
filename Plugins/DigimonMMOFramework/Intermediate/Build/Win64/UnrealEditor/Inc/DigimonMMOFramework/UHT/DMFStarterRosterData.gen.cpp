// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/DMFStarterRosterData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFStarterRosterData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterRosterData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFStarterRosterEntry(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterRosterData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FDMFStarterRosterEntry ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFStarterRosterEntry_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFStarterRosterEntry>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFStarterRosterEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/DMFStarterRosterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Species_MetaData[] = {
		{ "Category", "Starter" },
		{ "ModuleRelativePath", "Public/Data/DMFStarterRosterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Starter" },
		{ "ModuleRelativePath", "Public/Data/DMFStarterRosterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayOrder_MetaData[] = {
		{ "Category", "Starter" },
		{ "ModuleRelativePath", "Public/Data/DMFStarterRosterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectionBlurb_MetaData[] = {
		{ "Category", "Starter" },
		{ "ModuleRelativePath", "Public/Data/DMFStarterRosterData.h" },
		{ "MultiLine", "TRUE" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFStarterRosterEntry constinit property declarations ************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Species;
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((FDMFStarterRosterEntry*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DisplayOrder;
	static const UECodeGen_Private::FTextPropertyParams NewProp_SelectionBlurb;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFStarterRosterEntry constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFStarterRosterEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFStarterRosterEntry Property Definitions ***********************
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Species = { "Species", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFStarterRosterEntry, Species), Z_Construct_UClass_UDMFDigimonSpeciesData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Species_MetaData), NewProp_Species_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFStarterRosterEntry), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DisplayOrder = { "DisplayOrder", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFStarterRosterEntry, DisplayOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayOrder_MetaData), NewProp_DisplayOrder_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_SelectionBlurb = { "SelectionBlurb", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFStarterRosterEntry, SelectionBlurb), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectionBlurb_MetaData), NewProp_SelectionBlurb_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Species,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DisplayOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectionBlurb,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFStarterRosterEntry Property Definitions *************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFStarterRosterEntry",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFStarterRosterEntry>(),
	alignof(FDMFStarterRosterEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFStarterRosterEntry;
UScriptStruct* Z_Construct_UScriptStruct_FDMFStarterRosterEntry(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFStarterRosterEntry.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFStarterRosterEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFStarterRosterEntry, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFStarterRosterEntry"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFStarterRosterEntry.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFStarterRosterEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFStarterRosterEntry.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFStarterRosterEntry.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFStarterRosterEntry **********************************************

// ********** Begin Class UDMFStarterRosterData ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFStarterRosterData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/DMFStarterRosterData.h" },
		{ "ModuleRelativePath", "Public/Data/DMFStarterRosterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "Category", "Starter" },
		{ "ModuleRelativePath", "Public/Data/DMFStarterRosterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Starters_MetaData[] = {
		{ "Category", "Starter" },
		{ "ModuleRelativePath", "Public/Data/DMFStarterRosterData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFStarterRosterData constinit property declarations ********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Title;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Starters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Starters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFStarterRosterData constinit property declarations **********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFStarterRosterData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFStarterRosterData Property Definitions *******************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterRosterData, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Starters_Inner = { "Starters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFStarterRosterEntry, METADATA_PARAMS(0, nullptr) }; // 92e6ab9472091def37c889b95e55395a2ee9b274
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Starters = { "Starters", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFStarterRosterData, Starters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Starters_MetaData), NewProp_Starters_MetaData) }; // 92e6ab9472091def37c889b95e55395a2ee9b274
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Starters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Starters,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFStarterRosterData Property Definitions *********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UPrimaryDataAsset,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFStarterRosterData,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFStarterRosterData;
UClass* Z_Construct_UClass_UDMFStarterRosterData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFStarterRosterData;
		if (!Z_Registration_Info_UClass_UDMFStarterRosterData.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFStarterRosterData"),
				Z_Registration_Info_UClass_UDMFStarterRosterData.InnerSingleton,
				nullptr,
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
		return Z_Registration_Info_UClass_UDMFStarterRosterData.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFStarterRosterData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFStarterRosterData.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFStarterRosterData.OuterSingleton;
}
#undef UHT_STATICS
UDMFStarterRosterData::UDMFStarterRosterData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFStarterRosterData);
UDMFStarterRosterData::~UDMFStarterRosterData() {}
// ********** End Class UDMFStarterRosterData ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFStarterRosterData_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDMFStarterRosterEntry, Z_Construct_UScriptStruct_FDMFStarterRosterEntry_Statics::NewStructOps, TEXT("DMFStarterRosterEntry"),&Z_Registration_Info_UScriptStruct_FDMFStarterRosterEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFStarterRosterEntry), 2464590740U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFStarterRosterData, TEXT("UDMFStarterRosterData"), &Z_Registration_Info_UClass_UDMFStarterRosterData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFStarterRosterData), 2685439930U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFStarterRosterData_h__Script_DigimonMMOFramework_0e4e937c1e4fefe25ecae3d2da5df0c1ad39f2a6{
	TEXT("/Script/DigimonMMOFramework"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
