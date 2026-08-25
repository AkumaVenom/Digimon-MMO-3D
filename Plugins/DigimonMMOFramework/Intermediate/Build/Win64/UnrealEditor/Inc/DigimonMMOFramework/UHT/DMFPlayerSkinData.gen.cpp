// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/DMFPlayerSkinData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFPlayerSkinData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFPlayerSkinData *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFPlayerSkinData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Data-driven visual definition for a playable MMO avatar skin.\n *\n * Player skins intentionally contain presentation only. Gameplay collision, movement,\n * ownership and network authority remain on ADMFPlayerAvatarCharacter so changing a skin\n * cannot silently replace the authoritative pawn or grant different gameplay capabilities.\n */" },
#endif
		{ "IncludePath", "Data/DMFPlayerSkinData.h" },
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Data-driven visual definition for a playable MMO avatar skin.\n\nPlayer skins intentionally contain presentation only. Gameplay collision, movement,\nownership and network authority remain on ADMFPlayerAvatarCharacter so changing a skin\ncannot silently replace the authoritative pawn or grant different gameplay capabilities." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkinId_MetaData[] = {
		{ "Category", "Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stable persistent key. If None, the asset name is used. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stable persistent key. If None, the asset name is used." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Availability" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Disabled skins stay discoverable as assets but are rejected by the authoritative server. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Disabled skins stay discoverable as assets but are rejected by the authoritative server." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayOrder_MetaData[] = {
		{ "Category", "Availability" },
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMesh_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimClass_MetaData[] = {
		{ "Category", "Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional Animation Blueprint class for this skin. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional Animation Blueprint class for this skin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshRelativeTransform_MetaData[] = {
		{ "Category", "Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Relative transform applied to the inherited Character mesh component. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Relative transform applied to the inherited Character mesh component." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialOverrides_MetaData[] = {
		{ "Category", "Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional per-index material overrides. Null entries leave the skeletal mesh default material in place. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional per-index material overrides. Null entries leave the skeletal mesh default material in place." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Portrait_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional portrait used by native/custom selection UIs. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFPlayerSkinData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional portrait used by native/custom selection UIs." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFPlayerSkinData constinit property declarations ***********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_SkinId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((UDMFPlayerSkinData*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DisplayOrder;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SkeletalMesh;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_AnimClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MeshRelativeTransform;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_MaterialOverrides_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MaterialOverrides;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Portrait;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFPlayerSkinData constinit property declarations *************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFPlayerSkinData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFPlayerSkinData Property Definitions **********************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_SkinId = { "SkinId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinData, SkinId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkinId_MetaData), NewProp_SkinId_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinData, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFPlayerSkinData), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DisplayOrder = { "DisplayOrder", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinData, DisplayOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayOrder_MetaData), NewProp_DisplayOrder_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_SkeletalMesh = { "SkeletalMesh", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinData, SkeletalMesh), Z_Construct_UClass_USkeletalMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkeletalMesh_MetaData), NewProp_SkeletalMesh_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams UHT_STATICS::NewProp_AnimClass = { "AnimClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftClass, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinData, AnimClass), Z_Construct_UClass_UAnimInstance, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimClass_MetaData), NewProp_AnimClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_MeshRelativeTransform = { "MeshRelativeTransform", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinData, MeshRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshRelativeTransform_MetaData), NewProp_MeshRelativeTransform_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_MaterialOverrides_Inner = { "MaterialOverrides", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_MaterialOverrides = { "MaterialOverrides", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinData, MaterialOverrides), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialOverrides_MetaData), NewProp_MaterialOverrides_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Portrait = { "Portrait", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSkinData, Portrait), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Portrait_MetaData), NewProp_Portrait_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkinId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DisplayOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkeletalMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AnimClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MeshRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialOverrides_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialOverrides,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Portrait,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFPlayerSkinData Property Definitions ************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UPrimaryDataAsset,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFPlayerSkinData,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFPlayerSkinData;
UClass* Z_Construct_UClass_UDMFPlayerSkinData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFPlayerSkinData;
		if (!Z_Registration_Info_UClass_UDMFPlayerSkinData.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFPlayerSkinData"),
				Z_Registration_Info_UClass_UDMFPlayerSkinData.InnerSingleton,
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
		return Z_Registration_Info_UClass_UDMFPlayerSkinData.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFPlayerSkinData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFPlayerSkinData.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFPlayerSkinData.OuterSingleton;
}
#undef UHT_STATICS
UDMFPlayerSkinData::UDMFPlayerSkinData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFPlayerSkinData);
UDMFPlayerSkinData::~UDMFPlayerSkinData() {}
// ********** End Class UDMFPlayerSkinData *********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFPlayerSkinData_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFPlayerSkinData, TEXT("UDMFPlayerSkinData"), &Z_Registration_Info_UClass_UDMFPlayerSkinData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFPlayerSkinData), 914546680U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFPlayerSkinData_h__Script_DigimonMMOFramework_74a8ab1d77817c64ef61ec20da17a9738a757e7d{
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
