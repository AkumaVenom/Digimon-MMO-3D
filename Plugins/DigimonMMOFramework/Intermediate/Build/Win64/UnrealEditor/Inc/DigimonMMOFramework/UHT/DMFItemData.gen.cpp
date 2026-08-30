// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/DMFItemData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFItemData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFItemCategory(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFItemUseEffect(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EDMFItemCategory **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFItemCategory_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFItemCategory>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFItemCategory(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** High-level inventory grouping used by native UI and future item-shop filtering. */" },
#endif
		{ "Consumable.Name", "EDMFItemCategory::Consumable" },
		{ "KeyItem.DisplayName", "Key Item" },
		{ "KeyItem.Name", "EDMFItemCategory::KeyItem" },
		{ "Material.Name", "EDMFItemCategory::Material" },
		{ "Miscellaneous.Name", "EDMFItemCategory::Miscellaneous" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
		{ "Quest.Name", "EDMFItemCategory::Quest" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "High-level inventory grouping used by native UI and future item-shop filtering." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFItemCategory::Consumable", (int64)EDMFItemCategory::Consumable },
		{ "EDMFItemCategory::Material", (int64)EDMFItemCategory::Material },
		{ "EDMFItemCategory::KeyItem", (int64)EDMFItemCategory::KeyItem },
		{ "EDMFItemCategory::Quest", (int64)EDMFItemCategory::Quest },
		{ "EDMFItemCategory::Miscellaneous", (int64)EDMFItemCategory::Miscellaneous },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFItemCategory",
	"EDMFItemCategory",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFItemCategory;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFItemCategory(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFItemCategory.OuterSingleton)
		{
			ZRIE_EDMFItemCategory.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFItemCategory, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFItemCategory"));
		}
		return ZRIE_EDMFItemCategory.OuterSingleton;
	}
	if (!ZRIE_EDMFItemCategory.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFItemCategory.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFItemCategory.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFItemCategory ************************************************************

// ********** Begin Enum EDMFItemUseEffect *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFItemUseEffect_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFItemUseEffect>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFItemUseEffect(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native server-authoritative effects currently supplied by the framework. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
		{ "None.Name", "EDMFItemUseEffect::None" },
		{ "RestoreHP.DisplayName", "Restore HP" },
		{ "RestoreHP.Name", "EDMFItemUseEffect::RestoreHP" },
		{ "RestoreSP.DisplayName", "Restore SP" },
		{ "RestoreSP.Name", "EDMFItemUseEffect::RestoreSP" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native server-authoritative effects currently supplied by the framework." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFItemUseEffect::None", (int64)EDMFItemUseEffect::None },
		{ "EDMFItemUseEffect::RestoreHP", (int64)EDMFItemUseEffect::RestoreHP },
		{ "EDMFItemUseEffect::RestoreSP", (int64)EDMFItemUseEffect::RestoreSP },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFItemUseEffect",
	"EDMFItemUseEffect",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFItemUseEffect;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFItemUseEffect(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFItemUseEffect.OuterSingleton)
		{
			ZRIE_EDMFItemUseEffect.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFItemUseEffect, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFItemUseEffect"));
		}
		return ZRIE_EDMFItemUseEffect.OuterSingleton;
	}
	if (!ZRIE_EDMFItemUseEffect.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFItemUseEffect.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFItemUseEffect.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFItemUseEffect ***********************************************************

// ********** Begin Class UDMFItemData *************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFItemData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Data-driven player item definition. Clients may read presentation fields, but gameplay effect values are\n * always resolved again on authority when an item is consumed. This makes the same asset suitable for\n * inventory UI, future shops/rewards, and authoritative gameplay without trusting client-authored values.\n */" },
#endif
		{ "IncludePath", "Data/DMFItemData.h" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Data-driven player item definition. Clients may read presentation fields, but gameplay effect values are\nalways resolved again on authority when an item is consumed. This makes the same asset suitable for\ninventory UI, future shops/rewards, and authoritative gameplay without trusting client-authored values." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStackSize_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ClampMax", "999999" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum quantity stored in one persistent replicated stack. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum quantity stored in one persistent replicated stack." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SuggestedBuyPrice_MetaData[] = {
		{ "Category", "Economy" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Canonical item-economy values used by the replicated item vendor unless a placed vendor applies multipliers. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Canonical item-economy values used by the replicated item vendor unless a placed vendor applies multipliers." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SuggestedSellPrice_MetaData[] = {
		{ "Category", "Economy" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bConsumable_MetaData[] = {
		{ "Category", "Use" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UseEffect_MetaData[] = {
		{ "Category", "Use" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RestoreAmount_MetaData[] = {
		{ "Category", "Use" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** HP/SP restored by one consumed item. Ignored for UseEffect=None. */" },
#endif
		{ "EditCondition", "UseEffect != EDMFItemUseEffect::None" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HP/SP restored by one consumed item. Ignored for UseEffect=None." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanRestoreDefeatedDigimon_MetaData[] = {
		{ "Category", "Use" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default capsule policy: defeated Digimon require the Healer/another explicit revival mechanic. */" },
#endif
		{ "EditCondition", "UseEffect == EDMFItemUseEffect::RestoreHP" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default capsule policy: defeated Digimon require the Healer/another explicit revival mechanic." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequiresLivingDigimon_MetaData[] = {
		{ "Category", "Use" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Prevents normal recovery capsules from being used on a defeated target. */" },
#endif
		{ "EditCondition", "UseEffect != EDMFItemUseEffect::None" },
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Prevents normal recovery capsules from being used on a defeated target." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SortPriority_MetaData[] = {
		{ "Category", "Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional stable sort hint for native inventory/shop lists. Lower values appear first. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFItemData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional stable sort hint for native inventory/shop lists. Lower values appear first." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFItemData constinit property declarations *****************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Category_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Category;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStackSize;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SuggestedBuyPrice;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SuggestedSellPrice;
	static void NewProp_bConsumable_SetBit(void* Obj)
	{
		((UDMFItemData*)Obj)->bConsumable = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConsumable;
	static const UECodeGen_Private::FBytePropertyParams NewProp_UseEffect_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_UseEffect;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RestoreAmount;
	static void NewProp_bCanRestoreDefeatedDigimon_SetBit(void* Obj)
	{
		((UDMFItemData*)Obj)->bCanRestoreDefeatedDigimon = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanRestoreDefeatedDigimon;
	static void NewProp_bRequiresLivingDigimon_SetBit(void* Obj)
	{
		((UDMFItemData*)Obj)->bRequiresLivingDigimon = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequiresLivingDigimon;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SortPriority;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFItemData constinit property declarations *******************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFItemData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFItemData Property Definitions ****************************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, Icon), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Category_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, Category), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemCategory, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Category_MetaData), NewProp_Category_MetaData) }; // 80ce5e23d43731fe2665f5a001059c7f086bfec0
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxStackSize = { "MaxStackSize", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, MaxStackSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStackSize_MetaData), NewProp_MaxStackSize_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_SuggestedBuyPrice = { "SuggestedBuyPrice", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, SuggestedBuyPrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SuggestedBuyPrice_MetaData), NewProp_SuggestedBuyPrice_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_SuggestedSellPrice = { "SuggestedSellPrice", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, SuggestedSellPrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SuggestedSellPrice_MetaData), NewProp_SuggestedSellPrice_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bConsumable = { "bConsumable", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFItemData), &UHT_STATICS::NewProp_bConsumable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bConsumable_MetaData), NewProp_bConsumable_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_UseEffect_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_UseEffect = { "UseEffect", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, UseEffect), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemUseEffect, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UseEffect_MetaData), NewProp_UseEffect_MetaData) }; // 07c5cd83d07ea376dd2291612fdd130cf0971240
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_RestoreAmount = { "RestoreAmount", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, RestoreAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RestoreAmount_MetaData), NewProp_RestoreAmount_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCanRestoreDefeatedDigimon = { "bCanRestoreDefeatedDigimon", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFItemData), &UHT_STATICS::NewProp_bCanRestoreDefeatedDigimon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanRestoreDefeatedDigimon_MetaData), NewProp_bCanRestoreDefeatedDigimon_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequiresLivingDigimon = { "bRequiresLivingDigimon", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFItemData), &UHT_STATICS::NewProp_bRequiresLivingDigimon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequiresLivingDigimon_MetaData), NewProp_bRequiresLivingDigimon_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SortPriority = { "SortPriority", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemData, SortPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SortPriority_MetaData), NewProp_SortPriority_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Category_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Category,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxStackSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SuggestedBuyPrice,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SuggestedSellPrice,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bConsumable,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UseEffect_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UseEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RestoreAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCanRestoreDefeatedDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequiresLivingDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SortPriority,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFItemData Property Definitions ******************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UPrimaryDataAsset,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFItemData,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFItemData;
UClass* Z_Construct_UClass_UDMFItemData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFItemData;
		if (!Z_Registration_Info_UClass_UDMFItemData.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFItemData"),
				Z_Registration_Info_UClass_UDMFItemData.InnerSingleton,
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
		return Z_Registration_Info_UClass_UDMFItemData.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFItemData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFItemData.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFItemData.OuterSingleton;
}
#undef UHT_STATICS
UDMFItemData::UDMFItemData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFItemData);
UDMFItemData::~UDMFItemData() {}
// ********** End Class UDMFItemData ***************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFItemData_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFItemCategory, TEXT("EDMFItemCategory"), &ZRIE_EDMFItemCategory, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2161008163U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFItemUseEffect, TEXT("EDMFItemUseEffect"), &ZRIE_EDMFItemUseEffect, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 130403715U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFItemData, TEXT("UDMFItemData"), &Z_Registration_Info_UClass_UDMFItemData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFItemData), 2591613971U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFItemData_h__Script_DigimonMMOFramework_023ed8da351700c6e6241fa69303b7dca0586211{
	TEXT("/Script/DigimonMMOFramework"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
