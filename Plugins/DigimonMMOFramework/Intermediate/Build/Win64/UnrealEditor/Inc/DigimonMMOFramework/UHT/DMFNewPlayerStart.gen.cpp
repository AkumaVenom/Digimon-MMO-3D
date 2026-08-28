// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFNewPlayerStart.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFNewPlayerStart() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerStart(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFNewPlayerStart(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFNewPlayerStart(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ADMFNewPlayerStart *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFNewPlayerStart_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Dedicated first-login gameplay spawn point for accounts that do not yet have a persisted world location.\n *\n * Place one (or more) in the configured Open World map. The authoritative MMO GameMode selects the enabled\n * point with the highest Spawn Priority. Returning players with a valid persisted location do not use this actor.\n */" },
#endif
		{ "HideCategories", "Collision Lighting LightColor Force" },
		{ "IncludePath", "Game/DMFNewPlayerStart.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFNewPlayerStart.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dedicated first-login gameplay spawn point for accounts that do not yet have a persisted world location.\n\nPlace one (or more) in the configured Open World map. The authoritative MMO GameMode selects the enabled\npoint with the highest Spawn Priority. Returning players with a valid persisted location do not use this actor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Digimon MMO|New Player Spawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Disabled points are ignored by the framework without needing to remove them from the level. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFNewPlayerStart.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Disabled points are ignored by the framework without needing to remove them from the level." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnPriority_MetaData[] = {
		{ "Category", "Digimon MMO|New Player Spawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Highest enabled priority wins. Multiple equal-priority points are resolved deterministically by actor name. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFNewPlayerStart.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Highest enabled priority wins. Multiple equal-priority points are resolved deterministically by actor name." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFNewPlayerStart constinit property declarations ***********************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((ADMFNewPlayerStart*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SpawnPriority;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFNewPlayerStart constinit property declarations *************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFNewPlayerStart>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFNewPlayerStart Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFNewPlayerStart), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SpawnPriority = { "SpawnPriority", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFNewPlayerStart, SpawnPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnPriority_MetaData), NewProp_SpawnPriority_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnPriority,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFNewPlayerStart Property Definitions ************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_APlayerStart,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFNewPlayerStart,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFNewPlayerStart;
UClass* Z_Construct_UClass_ADMFNewPlayerStart(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFNewPlayerStart;
		if (!Z_Registration_Info_UClass_ADMFNewPlayerStart.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFNewPlayerStart"),
				Z_Registration_Info_UClass_ADMFNewPlayerStart.InnerSingleton,
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
		return Z_Registration_Info_UClass_ADMFNewPlayerStart.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFNewPlayerStart.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFNewPlayerStart.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFNewPlayerStart.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFNewPlayerStart);
ADMFNewPlayerStart::~ADMFNewPlayerStart() {}
// ********** End Class ADMFNewPlayerStart *********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFNewPlayerStart_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFNewPlayerStart, TEXT("ADMFNewPlayerStart"), &Z_Registration_Info_UClass_ADMFNewPlayerStart, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFNewPlayerStart), 1428225552U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFNewPlayerStart_h__Script_DigimonMMOFramework_110139df164ea5e379db0235f3558ea4dca17cf4{
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
