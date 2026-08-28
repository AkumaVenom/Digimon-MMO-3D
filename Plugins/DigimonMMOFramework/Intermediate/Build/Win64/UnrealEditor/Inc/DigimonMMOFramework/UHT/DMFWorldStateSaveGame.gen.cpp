// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Persistence/DMFWorldStateSaveGame.h"
#include "DMFTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFWorldStateSaveGame() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_USaveGame(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDayNightPersistentState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldStateSaveGame(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldStateSaveGame(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFWorldStateSaveGame ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFWorldStateSaveGame_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server-owned persistent world state kept separate from per-account saves.\n * Day/night clock keys are map + stable sky persistence id so different worlds never overwrite one another.\n */" },
#endif
		{ "IncludePath", "Persistence/DMFWorldStateSaveGame.h" },
		{ "ModuleRelativePath", "Public/Persistence/DMFWorldStateSaveGame.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-owned persistent world state kept separate from per-account saves.\nDay/night clock keys are map + stable sky persistence id so different worlds never overwrite one another." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SchemaVersion_MetaData[] = {
		{ "ModuleRelativePath", "Public/Persistence/DMFWorldStateSaveGame.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DayNightStates_MetaData[] = {
		{ "ModuleRelativePath", "Public/Persistence/DMFWorldStateSaveGame.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFWorldStateSaveGame constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SchemaVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DayNightStates_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DayNightStates_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_DayNightStates;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFWorldStateSaveGame constinit property declarations *********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFWorldStateSaveGame>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFWorldStateSaveGame Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SchemaVersion = { "SchemaVersion", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldStateSaveGame, SchemaVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SchemaVersion_MetaData), NewProp_SchemaVersion_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DayNightStates_ValueProp = { "DayNightStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FDMFDayNightPersistentState, METADATA_PARAMS(0, nullptr) }; // 5a775ace2f593060bcd68c57171bb71218391834
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_DayNightStates_Key_KeyProp = { "DayNightStates_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams UHT_STATICS::NewProp_DayNightStates = { "DayNightStates", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Map, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldStateSaveGame, DayNightStates), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DayNightStates_MetaData), NewProp_DayNightStates_MetaData) }; // 5a775ace2f593060bcd68c57171bb71218391834
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SchemaVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DayNightStates_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DayNightStates_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DayNightStates,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFWorldStateSaveGame Property Definitions ********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_USaveGame,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFWorldStateSaveGame,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFWorldStateSaveGame;
UClass* Z_Construct_UClass_UDMFWorldStateSaveGame(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFWorldStateSaveGame;
		if (!Z_Registration_Info_UClass_UDMFWorldStateSaveGame.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFWorldStateSaveGame"),
				Z_Registration_Info_UClass_UDMFWorldStateSaveGame.InnerSingleton,
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
		return Z_Registration_Info_UClass_UDMFWorldStateSaveGame.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFWorldStateSaveGame.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFWorldStateSaveGame.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFWorldStateSaveGame.OuterSingleton;
}
#undef UHT_STATICS
UDMFWorldStateSaveGame::UDMFWorldStateSaveGame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFWorldStateSaveGame);
UDMFWorldStateSaveGame::~UDMFWorldStateSaveGame() {}
// ********** End Class UDMFWorldStateSaveGame *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFWorldStateSaveGame_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFWorldStateSaveGame, TEXT("UDMFWorldStateSaveGame"), &Z_Registration_Info_UClass_UDMFWorldStateSaveGame, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFWorldStateSaveGame), 2269408187U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFWorldStateSaveGame_h__Script_DigimonMMOFramework_f9778d926413f4dcb7e66bcf430a56b8610c62f8{
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
