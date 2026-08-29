// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Persistence/DMFAccountDatabaseSaveGame.h"
#include "DMFTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFAccountDatabaseSaveGame() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_USaveGame(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFAccountDatabaseSaveGame(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFAccountRecord(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFAccountDatabaseSaveGame(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFAccountDatabaseSaveGame **********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFAccountDatabaseSaveGame_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Persistence/DMFAccountDatabaseSaveGame.h" },
		{ "ModuleRelativePath", "Public/Persistence/DMFAccountDatabaseSaveGame.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SchemaVersion_MetaData[] = {
		{ "ModuleRelativePath", "Public/Persistence/DMFAccountDatabaseSaveGame.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Accounts_MetaData[] = {
		{ "ModuleRelativePath", "Public/Persistence/DMFAccountDatabaseSaveGame.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFAccountDatabaseSaveGame constinit property declarations **************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SchemaVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Accounts_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Accounts_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Accounts;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFAccountDatabaseSaveGame constinit property declarations ****************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFAccountDatabaseSaveGame>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFAccountDatabaseSaveGame Property Definitions *************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SchemaVersion = { "SchemaVersion", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFAccountDatabaseSaveGame, SchemaVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SchemaVersion_MetaData), NewProp_SchemaVersion_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Accounts_ValueProp = { "Accounts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FDMFAccountRecord, METADATA_PARAMS(0, nullptr) }; // 2f856c422aaed141d21fa44341bcd0445e707cc8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Accounts_Key_KeyProp = { "Accounts_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams UHT_STATICS::NewProp_Accounts = { "Accounts", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Map, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFAccountDatabaseSaveGame, Accounts), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Accounts_MetaData), NewProp_Accounts_MetaData) }; // 2f856c422aaed141d21fa44341bcd0445e707cc8
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SchemaVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Accounts_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Accounts_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Accounts,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFAccountDatabaseSaveGame Property Definitions ***************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_USaveGame,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFAccountDatabaseSaveGame,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFAccountDatabaseSaveGame;
UClass* Z_Construct_UClass_UDMFAccountDatabaseSaveGame(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFAccountDatabaseSaveGame;
		if (!Z_Registration_Info_UClass_UDMFAccountDatabaseSaveGame.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFAccountDatabaseSaveGame"),
				Z_Registration_Info_UClass_UDMFAccountDatabaseSaveGame.InnerSingleton,
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
		return Z_Registration_Info_UClass_UDMFAccountDatabaseSaveGame.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFAccountDatabaseSaveGame.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFAccountDatabaseSaveGame.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFAccountDatabaseSaveGame.OuterSingleton;
}
#undef UHT_STATICS
UDMFAccountDatabaseSaveGame::UDMFAccountDatabaseSaveGame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFAccountDatabaseSaveGame);
UDMFAccountDatabaseSaveGame::~UDMFAccountDatabaseSaveGame() {}
// ********** End Class UDMFAccountDatabaseSaveGame ************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountDatabaseSaveGame_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFAccountDatabaseSaveGame, TEXT("UDMFAccountDatabaseSaveGame"), &Z_Registration_Info_UClass_UDMFAccountDatabaseSaveGame, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFAccountDatabaseSaveGame), 3765126651U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountDatabaseSaveGame_h__Script_DigimonMMOFramework_83b2c069d0f2df737d79adda808494bd2274248c{
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
