// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFItemVendorActor.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFItemVendorActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_APlayerController(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USceneComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USphereComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFItemVendorActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorConfigurationChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorEnabledChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorStockChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFItemVendorStockItem(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorTradeCompleted__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFItemVendorActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemVendorWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FDMFItemVendorPoolEntry *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFItemVendorPoolEntry>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFItemVendorPoolEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** One weighted item candidate that a placed item vendor may roll into shared stock. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One weighted item candidate that a placed item vendor may roll into shared stock." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Item_MetaData[] = {
		{ "Category", "Item" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectionWeight_MetaData[] = {
		{ "Category", "Item" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PurchasePriceMultiplier_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.01" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Multiplies the Data Asset SuggestedBuyPrice for this vendor's rolled offer. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Multiplies the Data Asset SuggestedBuyPrice for this vendor's rolled offer." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumStockQuantity_MetaData[] = {
		{ "Category", "Stock Quantity" },
		{ "ClampMax", "999999" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shared server stock quantity rolled when this offer is generated. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shared server stock quantity rolled when this offer is generated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumStockQuantity_MetaData[] = {
		{ "Category", "Stock Quantity" },
		{ "ClampMax", "999999" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFItemVendorPoolEntry constinit property declarations ***********
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Item;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SelectionWeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PurchasePriceMultiplier;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumStockQuantity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumStockQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFItemVendorPoolEntry constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFItemVendorPoolEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFItemVendorPoolEntry Property Definitions **********************
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorPoolEntry, Item), Z_Construct_UClass_UDMFItemData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Item_MetaData), NewProp_Item_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SelectionWeight = { "SelectionWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorPoolEntry, SelectionWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectionWeight_MetaData), NewProp_SelectionWeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PurchasePriceMultiplier = { "PurchasePriceMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorPoolEntry, PurchasePriceMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PurchasePriceMultiplier_MetaData), NewProp_PurchasePriceMultiplier_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumStockQuantity = { "MinimumStockQuantity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorPoolEntry, MinimumStockQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumStockQuantity_MetaData), NewProp_MinimumStockQuantity_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumStockQuantity = { "MaximumStockQuantity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorPoolEntry, MaximumStockQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumStockQuantity_MetaData), NewProp_MaximumStockQuantity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Item,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectionWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PurchasePriceMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumStockQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumStockQuantity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFItemVendorPoolEntry Property Definitions ************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFItemVendorPoolEntry",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFItemVendorPoolEntry>(),
	alignof(FDMFItemVendorPoolEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFItemVendorPoolEntry;
UScriptStruct* Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFItemVendorPoolEntry.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFItemVendorPoolEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFItemVendorPoolEntry"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFItemVendorPoolEntry.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFItemVendorPoolEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFItemVendorPoolEntry.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFItemVendorPoolEntry.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFItemVendorPoolEntry *********************************************

// ********** Begin ScriptStruct FDMFItemVendorPricingSettings *************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFItemVendorPricingSettings>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFItemVendorPricingSettings); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Global item-vendor price tuning layered over each UDMFItemData economy definition. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global item-vendor price tuning layered over each UDMFItemData economy definition." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerBuyPriceMultiplier_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.01" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Player BUY unit price = SuggestedBuyPrice * this value * pool-entry multiplier. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player BUY unit price = SuggestedBuyPrice * this value * pool-entry multiplier." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSellPayoutMultiplier_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Player SELL unit payout = SuggestedSellPrice * this value. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player SELL unit payout = SuggestedSellPrice * this value." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumUnitPrice_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Positive transactions are never quoted below this per-item amount. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Positive transactions are never quoted below this per-item amount." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFItemVendorPricingSettings constinit property declarations *****
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerBuyPriceMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerSellPayoutMultiplier;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_MinimumUnitPrice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFItemVendorPricingSettings constinit property declarations *******
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFItemVendorPricingSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFItemVendorPricingSettings Property Definitions ****************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerBuyPriceMultiplier = { "PlayerBuyPriceMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorPricingSettings, PlayerBuyPriceMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerBuyPriceMultiplier_MetaData), NewProp_PlayerBuyPriceMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerSellPayoutMultiplier = { "PlayerSellPayoutMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorPricingSettings, PlayerSellPayoutMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSellPayoutMultiplier_MetaData), NewProp_PlayerSellPayoutMultiplier_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_MinimumUnitPrice = { "MinimumUnitPrice", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorPricingSettings, MinimumUnitPrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumUnitPrice_MetaData), NewProp_MinimumUnitPrice_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerBuyPriceMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSellPayoutMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumUnitPrice,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFItemVendorPricingSettings Property Definitions ******************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFItemVendorPricingSettings",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFItemVendorPricingSettings>(),
	alignof(FDMFItemVendorPricingSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFItemVendorPricingSettings;
UScriptStruct* Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFItemVendorPricingSettings.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFItemVendorPricingSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFItemVendorPricingSettings"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFItemVendorPricingSettings.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFItemVendorPricingSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFItemVendorPricingSettings.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFItemVendorPricingSettings.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFItemVendorPricingSettings ***************************************

// ********** Begin ScriptStruct FDMFItemVendorStockItem *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFItemVendorStockItem_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFItemVendorStockItem>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFItemVendorStockItem); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replicated shared offer. Every connection sees the same StockId, item, price and remaining quantity. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated shared offer. Every connection sees the same StockId, item, price and remaining quantity." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StockId_MetaData[] = {
		{ "Category", "Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemAssetId_MetaData[] = {
		{ "Category", "Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitBuyPrice_MetaData[] = {
		{ "Category", "Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvailableQuantity_MetaData[] = {
		{ "Category", "Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationSerial_MetaData[] = {
		{ "Category", "Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFItemVendorStockItem constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_StockId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_UnitBuyPrice;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AvailableQuantity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GenerationSerial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFItemVendorStockItem constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFItemVendorStockItem>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFItemVendorStockItem Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StockId = { "StockId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorStockItem, StockId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StockId_MetaData), NewProp_StockId_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorStockItem, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemAssetId_MetaData), NewProp_ItemAssetId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_UnitBuyPrice = { "UnitBuyPrice", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorStockItem, UnitBuyPrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitBuyPrice_MetaData), NewProp_UnitBuyPrice_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_AvailableQuantity = { "AvailableQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorStockItem, AvailableQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvailableQuantity_MetaData), NewProp_AvailableQuantity_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_GenerationSerial = { "GenerationSerial", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFItemVendorStockItem, GenerationSerial), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationSerial_MetaData), NewProp_GenerationSerial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UnitBuyPrice,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AvailableQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GenerationSerial,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFItemVendorStockItem Property Definitions ************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFItemVendorStockItem",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFItemVendorStockItem>(),
	alignof(FDMFItemVendorStockItem),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFItemVendorStockItem;
UScriptStruct* Z_Construct_UScriptStruct_FDMFItemVendorStockItem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFItemVendorStockItem.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFItemVendorStockItem.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFItemVendorStockItem, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFItemVendorStockItem"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFItemVendorStockItem.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFItemVendorStockItem.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFItemVendorStockItem.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFItemVendorStockItem.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFItemVendorStockItem *********************************************

// ********** Begin Delegate FDMFItemVendorStockChanged ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorStockChanged__DelegateSignature_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFItemVendorStockChanged constinit property declarations ************
// ********** End Delegate FDMFItemVendorStockChanged constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFItemVendorStockChanged__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorStockChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFItemVendorStockChanged **********************************************

// ********** Begin Delegate FDMFItemVendorEnabledChanged ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorEnabledChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFItemVendorEnabledChanged_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFItemVendorEnabledChanged constinit property declarations **********
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFItemVendorEnabledChanged_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFItemVendorEnabledChanged constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFItemVendorEnabledChanged Property Definitions *********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFItemVendorEnabledChanged_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFItemVendorEnabledChanged Property Definitions ***********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFItemVendorEnabledChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemVendorEnabledChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemVendorEnabledChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorEnabledChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFItemVendorEnabledChanged ********************************************

// ********** Begin Delegate FDMFItemVendorConfigurationChanged ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorConfigurationChanged__DelegateSignature_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFItemVendorConfigurationChanged constinit property declarations ****
// ********** End Delegate FDMFItemVendorConfigurationChanged constinit property declarations ******
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFItemVendorConfigurationChanged__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorConfigurationChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFItemVendorConfigurationChanged **************************************

// ********** Begin Delegate FDMFItemVendorTradeCompleted ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorTradeCompleted__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFItemVendorTradeCompleted_Parms
	{
		ADMFMMOPlayerController* PlayerController;
		EDMFItemVendorTransactionType TransactionType;
		FPrimaryAssetId ItemAssetId;
		int32 Quantity;
		int64 TotalPrice;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFItemVendorTradeCompleted constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalPrice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFItemVendorTradeCompleted constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFItemVendorTradeCompleted Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTradeCompleted_Parms, PlayerController), Z_Construct_UClass_ADMFMMOPlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTradeCompleted_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTradeCompleted_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTradeCompleted_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_TotalPrice = { "TotalPrice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTradeCompleted_Parms, TotalPrice), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TotalPrice,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFItemVendorTradeCompleted Property Definitions ***********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFItemVendorTradeCompleted__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemVendorTradeCompleted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemVendorTradeCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorTradeCompleted__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFItemVendorTradeCompleted ********************************************

// ********** Begin Class ADMFItemVendorActor Function BP_OnStockRefreshed *************************
static FName NAME_ADMFItemVendorActor_BP_OnStockRefreshed = FName(TEXT("BP_OnStockRefreshed"));
void ADMFItemVendorActor::BP_OnStockRefreshed()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFItemVendorActor_BP_OnStockRefreshed);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_BP_OnStockRefreshed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnStockRefreshed constinit property declarations *******************
// ********** End Function BP_OnStockRefreshed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "BP_OnStockRefreshed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_BP_OnStockRefreshed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFItemVendorActor Function BP_OnStockRefreshed ***************************

// ********** Begin Class ADMFItemVendorActor Function BP_OnVendorEnabledChanged *******************
struct DMFItemVendorActor_eventBP_OnVendorEnabledChanged_Parms
{
	bool bEnabled;
};
static FName NAME_ADMFItemVendorActor_BP_OnVendorEnabledChanged = FName(TEXT("BP_OnVendorEnabledChanged"));
void ADMFItemVendorActor::BP_OnVendorEnabledChanged(bool bEnabled)
{
	DMFItemVendorActor_eventBP_OnVendorEnabledChanged_Parms Parms;
	Parms.bEnabled=bEnabled ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ADMFItemVendorActor_BP_OnVendorEnabledChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_BP_OnVendorEnabledChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVendorEnabledChanged constinit property declarations *************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFItemVendorActor_eventBP_OnVendorEnabledChanged_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnVendorEnabledChanged constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnVendorEnabledChanged Property Definitions ************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFItemVendorActor_eventBP_OnVendorEnabledChanged_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnVendorEnabledChanged Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "BP_OnVendorEnabledChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFItemVendorActor_eventBP_OnVendorEnabledChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFItemVendorActor_eventBP_OnVendorEnabledChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_BP_OnVendorEnabledChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFItemVendorActor Function BP_OnVendorEnabledChanged *********************

// ********** Begin Class ADMFItemVendorActor Function BP_OnVendorTradeCompleted *******************
struct DMFItemVendorActor_eventBP_OnVendorTradeCompleted_Parms
{
	ADMFMMOPlayerController* PlayerController;
	EDMFItemVendorTransactionType TransactionType;
	FPrimaryAssetId ItemAssetId;
	int32 Quantity;
	int64 TotalPrice;
};
static FName NAME_ADMFItemVendorActor_BP_OnVendorTradeCompleted = FName(TEXT("BP_OnVendorTradeCompleted"));
void ADMFItemVendorActor::BP_OnVendorTradeCompleted(ADMFMMOPlayerController* PlayerController, EDMFItemVendorTransactionType TransactionType, FPrimaryAssetId ItemAssetId, int32 Quantity, int64 TotalPrice)
{
	DMFItemVendorActor_eventBP_OnVendorTradeCompleted_Parms Parms;
	Parms.PlayerController=PlayerController;
	Parms.TransactionType=TransactionType;
	Parms.ItemAssetId=ItemAssetId;
	Parms.Quantity=Quantity;
	Parms.TotalPrice=TotalPrice;
	UFunction* Func = FindFunctionChecked(NAME_ADMFItemVendorActor_BP_OnVendorTradeCompleted);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_BP_OnVendorTradeCompleted_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVendorTradeCompleted constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalPrice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnVendorTradeCompleted constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnVendorTradeCompleted Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventBP_OnVendorTradeCompleted_Parms, PlayerController), Z_Construct_UClass_ADMFMMOPlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventBP_OnVendorTradeCompleted_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventBP_OnVendorTradeCompleted_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventBP_OnVendorTradeCompleted_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_TotalPrice = { "TotalPrice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventBP_OnVendorTradeCompleted_Parms, TotalPrice), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TotalPrice,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnVendorTradeCompleted Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "BP_OnVendorTradeCompleted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFItemVendorActor_eventBP_OnVendorTradeCompleted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFItemVendorActor_eventBP_OnVendorTradeCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_BP_OnVendorTradeCompleted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFItemVendorActor Function BP_OnVendorTradeCompleted *********************

// ********** Begin Class ADMFItemVendorActor Function GetPlayerSellUnitPrice **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_GetPlayerSellUnitPrice_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventGetPlayerSellUnitPrice_Parms
	{
		FPrimaryAssetId ItemAssetId;
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Pricing" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerSellUnitPrice constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerSellUnitPrice constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerSellUnitPrice Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventGetPlayerSellUnitPrice_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventGetPlayerSellUnitPrice_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetPlayerSellUnitPrice Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "GetPlayerSellUnitPrice", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventGetPlayerSellUnitPrice_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventGetPlayerSellUnitPrice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_GetPlayerSellUnitPrice(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execGetPlayerSellUnitPrice)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_ItemAssetId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=P_THIS->GetPlayerSellUnitPrice(Z_Param_ItemAssetId);
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function GetPlayerSellUnitPrice ************************

// ********** Begin Class ADMFItemVendorActor Function GetSecondsUntilStockRotation ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_GetSecondsUntilStockRotation_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventGetSecondsUntilStockRotation_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSecondsUntilStockRotation constinit property declarations **********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSecondsUntilStockRotation constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSecondsUntilStockRotation Property Definitions *********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventGetSecondsUntilStockRotation_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSecondsUntilStockRotation Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "GetSecondsUntilStockRotation", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventGetSecondsUntilStockRotation_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventGetSecondsUntilStockRotation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_GetSecondsUntilStockRotation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execGetSecondsUntilStockRotation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetSecondsUntilStockRotation();
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function GetSecondsUntilStockRotation ******************

// ********** Begin Class ADMFItemVendorActor Function GetVendorStock ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_GetVendorStock_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventGetVendorStock_Parms
	{
		TArray<FDMFItemVendorStockItem> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetVendorStock constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVendorStock constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVendorStock Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFItemVendorStockItem, METADATA_PARAMS(0, nullptr) }; // 307378684efd1eb244603410df5c821c6b708dc0
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventGetVendorStock_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 307378684efd1eb244603410df5c821c6b708dc0
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetVendorStock Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "GetVendorStock", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventGetVendorStock_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventGetVendorStock_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_GetVendorStock(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execGetVendorStock)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FDMFItemVendorStockItem>*)Z_Param__Result=P_THIS->GetVendorStock();
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function GetVendorStock ********************************

// ********** Begin Class ADMFItemVendorActor Function IsItemSellable ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_IsItemSellable_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventIsItemSellable_Parms
	{
		FPrimaryAssetId ItemAssetId;
		FText OutBlockReason;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Selling" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsItemSellable constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutBlockReason;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFItemVendorActor_eventIsItemSellable_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsItemSellable constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsItemSellable Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventIsItemSellable_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_OutBlockReason = { "OutBlockReason", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventIsItemSellable_Parms, OutBlockReason), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFItemVendorActor_eventIsItemSellable_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutBlockReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsItemSellable Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "IsItemSellable", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventIsItemSellable_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventIsItemSellable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_IsItemSellable(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execIsItemSellable)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_ItemAssetId);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_OutBlockReason);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsItemSellable(Z_Param_ItemAssetId,Z_Param_Out_OutBlockReason);
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function IsItemSellable ********************************

// ********** Begin Class ADMFItemVendorActor Function IsPlayerWithinTradeRange ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_IsPlayerWithinTradeRange_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventIsPlayerWithinTradeRange_Parms
	{
		APlayerController* PlayerController;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Interaction" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPlayerWithinTradeRange constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFItemVendorActor_eventIsPlayerWithinTradeRange_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPlayerWithinTradeRange constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPlayerWithinTradeRange Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventIsPlayerWithinTradeRange_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFItemVendorActor_eventIsPlayerWithinTradeRange_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsPlayerWithinTradeRange Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "IsPlayerWithinTradeRange", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventIsPlayerWithinTradeRange_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventIsPlayerWithinTradeRange_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_IsPlayerWithinTradeRange(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execIsPlayerWithinTradeRange)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayerWithinTradeRange(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function IsPlayerWithinTradeRange **********************

// ********** Begin Class ADMFItemVendorActor Function IsVendorEnabled *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_IsVendorEnabled_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventIsVendorEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsVendorEnabled constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFItemVendorActor_eventIsVendorEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsVendorEnabled constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsVendorEnabled Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFItemVendorActor_eventIsVendorEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsVendorEnabled Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "IsVendorEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventIsVendorEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventIsVendorEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_IsVendorEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execIsVendorEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsVendorEnabled();
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function IsVendorEnabled *******************************

// ********** Begin Class ADMFItemVendorActor Function OnRep_Configuration *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_OnRep_Configuration_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_Configuration constinit property declarations *******************
// ********** End Function OnRep_Configuration constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "OnRep_Configuration", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_OnRep_Configuration(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execOnRep_Configuration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Configuration();
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function OnRep_Configuration ***************************

// ********** Begin Class ADMFItemVendorActor Function OnRep_Stock *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_OnRep_Stock_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_Stock constinit property declarations ***************************
// ********** End Function OnRep_Stock constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "OnRep_Stock", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_OnRep_Stock(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execOnRep_Stock)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Stock();
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function OnRep_Stock ***********************************

// ********** Begin Class ADMFItemVendorActor Function OnRep_VendorEnabled *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_OnRep_VendorEnabled_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_VendorEnabled constinit property declarations *******************
// ********** End Function OnRep_VendorEnabled constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "OnRep_VendorEnabled", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_OnRep_VendorEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execOnRep_VendorEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_VendorEnabled();
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function OnRep_VendorEnabled ***************************

// ********** Begin Class ADMFItemVendorActor Function RefreshStockNow *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_RefreshStockNow_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Digimon MMO|Item Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshStockNow constinit property declarations ***********************
// ********** End Function RefreshStockNow constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "RefreshStockNow", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_RefreshStockNow(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execRefreshStockNow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshStockNow();
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function RefreshStockNow *******************************

// ********** Begin Class ADMFItemVendorActor Function RestartStockRotationSchedule ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_RestartStockRotationSchedule_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock Rotation" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestartStockRotationSchedule constinit property declarations **********
// ********** End Function RestartStockRotationSchedule constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "RestartStockRotationSchedule", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_RestartStockRotationSchedule(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execRestartStockRotationSchedule)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RestartStockRotationSchedule();
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function RestartStockRotationSchedule ******************

// ********** Begin Class ADMFItemVendorActor Function SetBuyingEnabled ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_SetBuyingEnabled_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventSetBuyingEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBuyingEnabled constinit property declarations **********************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFItemVendorActor_eventSetBuyingEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBuyingEnabled constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBuyingEnabled Property Definitions *********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFItemVendorActor_eventSetBuyingEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetBuyingEnabled Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "SetBuyingEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventSetBuyingEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventSetBuyingEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_SetBuyingEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execSetBuyingEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBuyingEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function SetBuyingEnabled ******************************

// ********** Begin Class ADMFItemVendorActor Function SetPricingSettings **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_SetPricingSettings_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventSetPricingSettings_Parms
	{
		FDMFItemVendorPricingSettings NewPricing;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Pricing" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewPricing_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPricingSettings constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewPricing;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPricingSettings constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPricingSettings Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NewPricing = { "NewPricing", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorActor_eventSetPricingSettings_Parms, NewPricing), Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewPricing_MetaData), NewProp_NewPricing_MetaData) }; // 9a8114ca756a3ca6443ded59af6d9f8d2efa234e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPricing,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetPricingSettings Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "SetPricingSettings", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventSetPricingSettings_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventSetPricingSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_SetPricingSettings(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execSetPricingSettings)
{
	P_GET_STRUCT_REF(FDMFItemVendorPricingSettings,Z_Param_Out_NewPricing);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPricingSettings(Z_Param_Out_NewPricing);
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function SetPricingSettings ****************************

// ********** Begin Class ADMFItemVendorActor Function SetSellingEnabled ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_SetSellingEnabled_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventSetSellingEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSellingEnabled constinit property declarations *********************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFItemVendorActor_eventSetSellingEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSellingEnabled constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSellingEnabled Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFItemVendorActor_eventSetSellingEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetSellingEnabled Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "SetSellingEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventSetSellingEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventSetSellingEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_SetSellingEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execSetSellingEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSellingEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function SetSellingEnabled *****************************

// ********** Begin Class ADMFItemVendorActor Function SetVendorEnabled ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFItemVendorActor_SetVendorEnabled_Statics
struct UHT_STATICS
{
	struct DMFItemVendorActor_eventSetVendorEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVendorEnabled constinit property declarations **********************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFItemVendorActor_eventSetVendorEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVendorEnabled constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVendorEnabled Property Definitions *********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFItemVendorActor_eventSetVendorEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetVendorEnabled Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFItemVendorActor, nullptr, "SetVendorEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorActor_eventSetVendorEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorActor_eventSetVendorEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFItemVendorActor_SetVendorEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFItemVendorActor::execSetVendorEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVendorEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFItemVendorActor Function SetVendorEnabled ******************************

// ********** Begin Class ADMFItemVendorActor ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFItemVendorActor_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Blueprint-derivable, server-authoritative shared item exchange.\n * The server alone rolls/rotates/decrements stock. ReplicatedStock is intentionally public shared state,\n * while each player's bag and BITS balance remain owner-only on UDMFPlayerDigimonComponent.\n */" },
#endif
		{ "IncludePath", "Game/DMFItemVendorActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint-derivable, server-authoritative shared item exchange.\nThe server alone rolls/rotates/decrements stock. ReplicatedStock is intentionally public shared state,\nwhile each player's bag and BITS balance remain owner-only on UDMFPlayerDigimonComponent." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorMesh_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Presentation" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionCollision_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Interaction" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorId_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Identity" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorDisplayName_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Identity" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorSubtitle_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Identity" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionPrompt_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Interaction" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVendorEnabled_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowBuying_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowSelling_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireItemInStockPoolToSell_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Selling" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If enabled, only items present in this vendor's StockPool may be sold here. Key/Quest items remain protected regardless. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If enabled, only items present in this vendor's StockPool may be sold here. Key/Quest items remain protected regardless." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Interaction" },
		{ "ClampMin", "50.0" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionCollisionRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Interaction" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionTraceChannel_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Interaction" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StockSlots_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock" },
		{ "ClampMax", "64" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowDuplicateItemsInStock_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRefillDepletedSlotsImmediately_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StockPool_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRotateStockAutomatically_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock Rotation" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumStockRotationSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock Rotation" },
		{ "ClampMin", "5.0" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumStockRotationSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock Rotation" },
		{ "ClampMin", "5.0" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialStockRotationDelaySeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock Rotation" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pricing_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Pricing" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorWidgetClass_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Per-NPC UI override. Leave blank to use the polished framework-native BUY/SELL item exchange. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-NPC UI override. Leave blank to use the polished framework-native BUY/SELL item exchange." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedStock_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shared stock is replicated to every relevant connection. Purchases update remaining quantity for all players. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shared stock is replicated to every relevant connection. Purchases update remaining quantity for all players." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StockGenerationSerial_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextStockRotationServerTimeSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVendorStockChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVendorEnabledChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVendorConfigurationChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVendorTradeCompleted_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFItemVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFItemVendorActor constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractionCollision;
	static const UECodeGen_Private::FNamePropertyParams NewProp_VendorId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_VendorDisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_VendorSubtitle;
	static const UECodeGen_Private::FTextPropertyParams NewProp_InteractionPrompt;
	static void NewProp_bVendorEnabled_SetBit(void* Obj)
	{
		((ADMFItemVendorActor*)Obj)->bVendorEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVendorEnabled;
	static void NewProp_bAllowBuying_SetBit(void* Obj)
	{
		((ADMFItemVendorActor*)Obj)->bAllowBuying = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowBuying;
	static void NewProp_bAllowSelling_SetBit(void* Obj)
	{
		((ADMFItemVendorActor*)Obj)->bAllowSelling = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowSelling;
	static void NewProp_bRequireItemInStockPoolToSell_SetBit(void* Obj)
	{
		((ADMFItemVendorActor*)Obj)->bRequireItemInStockPoolToSell = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireItemInStockPoolToSell;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionCollisionRadius;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InteractionTraceChannel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StockSlots;
	static void NewProp_bAllowDuplicateItemsInStock_SetBit(void* Obj)
	{
		((ADMFItemVendorActor*)Obj)->bAllowDuplicateItemsInStock = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowDuplicateItemsInStock;
	static void NewProp_bRefillDepletedSlotsImmediately_SetBit(void* Obj)
	{
		((ADMFItemVendorActor*)Obj)->bRefillDepletedSlotsImmediately = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRefillDepletedSlotsImmediately;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StockPool_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StockPool;
	static void NewProp_bRotateStockAutomatically_SetBit(void* Obj)
	{
		((ADMFItemVendorActor*)Obj)->bRotateStockAutomatically = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRotateStockAutomatically;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumStockRotationSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumStockRotationSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InitialStockRotationDelaySeconds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Pricing;
	static const UECodeGen_Private::FClassPropertyParams NewProp_VendorWidgetClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReplicatedStock_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReplicatedStock;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StockGenerationSerial;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_NextStockRotationServerTimeSeconds;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnVendorStockChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnVendorEnabledChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnVendorConfigurationChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnVendorTradeCompleted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFItemVendorActor constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetPlayerSellUnitPrice"), .Pointer = &ADMFItemVendorActor::execGetPlayerSellUnitPrice },
		{ .NameUTF8 = UTF8TEXT("GetSecondsUntilStockRotation"), .Pointer = &ADMFItemVendorActor::execGetSecondsUntilStockRotation },
		{ .NameUTF8 = UTF8TEXT("GetVendorStock"), .Pointer = &ADMFItemVendorActor::execGetVendorStock },
		{ .NameUTF8 = UTF8TEXT("IsItemSellable"), .Pointer = &ADMFItemVendorActor::execIsItemSellable },
		{ .NameUTF8 = UTF8TEXT("IsPlayerWithinTradeRange"), .Pointer = &ADMFItemVendorActor::execIsPlayerWithinTradeRange },
		{ .NameUTF8 = UTF8TEXT("IsVendorEnabled"), .Pointer = &ADMFItemVendorActor::execIsVendorEnabled },
		{ .NameUTF8 = UTF8TEXT("OnRep_Configuration"), .Pointer = &ADMFItemVendorActor::execOnRep_Configuration },
		{ .NameUTF8 = UTF8TEXT("OnRep_Stock"), .Pointer = &ADMFItemVendorActor::execOnRep_Stock },
		{ .NameUTF8 = UTF8TEXT("OnRep_VendorEnabled"), .Pointer = &ADMFItemVendorActor::execOnRep_VendorEnabled },
		{ .NameUTF8 = UTF8TEXT("RefreshStockNow"), .Pointer = &ADMFItemVendorActor::execRefreshStockNow },
		{ .NameUTF8 = UTF8TEXT("RestartStockRotationSchedule"), .Pointer = &ADMFItemVendorActor::execRestartStockRotationSchedule },
		{ .NameUTF8 = UTF8TEXT("SetBuyingEnabled"), .Pointer = &ADMFItemVendorActor::execSetBuyingEnabled },
		{ .NameUTF8 = UTF8TEXT("SetPricingSettings"), .Pointer = &ADMFItemVendorActor::execSetPricingSettings },
		{ .NameUTF8 = UTF8TEXT("SetSellingEnabled"), .Pointer = &ADMFItemVendorActor::execSetSellingEnabled },
		{ .NameUTF8 = UTF8TEXT("SetVendorEnabled"), .Pointer = &ADMFItemVendorActor::execSetVendorEnabled },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFItemVendorActor_BP_OnStockRefreshed, "BP_OnStockRefreshed" }, // 876d78180aaab0c0bd842d399c3429ed0a6235f0
		{ &Z_Construct_UFunction_ADMFItemVendorActor_BP_OnVendorEnabledChanged, "BP_OnVendorEnabledChanged" }, // bf9fa496cc8d2c8d7861f2e0a929e3c603f4b3f9
		{ &Z_Construct_UFunction_ADMFItemVendorActor_BP_OnVendorTradeCompleted, "BP_OnVendorTradeCompleted" }, // 5913f74b4d13696ac0027478ffdba7d98b8fe7c7
		{ &Z_Construct_UFunction_ADMFItemVendorActor_GetPlayerSellUnitPrice, "GetPlayerSellUnitPrice" }, // 6a4f1758d1647dc227743b61a4cd2c8882dba05d
		{ &Z_Construct_UFunction_ADMFItemVendorActor_GetSecondsUntilStockRotation, "GetSecondsUntilStockRotation" }, // 61e2eed714cca444d5b597f7616a902393ff87eb
		{ &Z_Construct_UFunction_ADMFItemVendorActor_GetVendorStock, "GetVendorStock" }, // 1730ae7002014c24836a8fe88f05b20ab245f006
		{ &Z_Construct_UFunction_ADMFItemVendorActor_IsItemSellable, "IsItemSellable" }, // 3d41477bf1c8cdfb881a82a7524546807e0711e8
		{ &Z_Construct_UFunction_ADMFItemVendorActor_IsPlayerWithinTradeRange, "IsPlayerWithinTradeRange" }, // 33d9a5e431a884e5898e40ab6af9e51421ee5664
		{ &Z_Construct_UFunction_ADMFItemVendorActor_IsVendorEnabled, "IsVendorEnabled" }, // 95b457fa377858d92363863d506625b0f044d7ab
		{ &Z_Construct_UFunction_ADMFItemVendorActor_OnRep_Configuration, "OnRep_Configuration" }, // 6380908b2344001be1bd17d33bf250a0519c9b6b
		{ &Z_Construct_UFunction_ADMFItemVendorActor_OnRep_Stock, "OnRep_Stock" }, // 383748bb0d876cd89a7be285d4bbacef45025c66
		{ &Z_Construct_UFunction_ADMFItemVendorActor_OnRep_VendorEnabled, "OnRep_VendorEnabled" }, // 8bc61e22dc8446840ba3efb2b0c8faf0aec3e142
		{ &Z_Construct_UFunction_ADMFItemVendorActor_RefreshStockNow, "RefreshStockNow" }, // 36462ac0dcb1c738083d5037fa1877bd3c0d597c
		{ &Z_Construct_UFunction_ADMFItemVendorActor_RestartStockRotationSchedule, "RestartStockRotationSchedule" }, // 0ab46ac0e52bfd7cd37833aa9c59933cdac18ab9
		{ &Z_Construct_UFunction_ADMFItemVendorActor_SetBuyingEnabled, "SetBuyingEnabled" }, // 02a7eb7a0ca779007985eb722ac0bb4f3e6469fe
		{ &Z_Construct_UFunction_ADMFItemVendorActor_SetPricingSettings, "SetPricingSettings" }, // 5da2543f9c0c573cd5ce3f44be2d589d50e5eb10
		{ &Z_Construct_UFunction_ADMFItemVendorActor_SetSellingEnabled, "SetSellingEnabled" }, // 36eaf0c0379e71926be925fc78cd28010333c0fb
		{ &Z_Construct_UFunction_ADMFItemVendorActor_SetVendorEnabled, "SetVendorEnabled" }, // 1df9112c90b9f807859d38bf325291f3dd8fabbd
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFItemVendorActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFItemVendorActor Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, SceneRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorMesh = { "VendorMesh", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, VendorMesh), Z_Construct_UClass_USkeletalMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorMesh_MetaData), NewProp_VendorMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InteractionCollision = { "InteractionCollision", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, InteractionCollision), Z_Construct_UClass_USphereComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionCollision_MetaData), NewProp_InteractionCollision_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_VendorId = { "VendorId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, VendorId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorId_MetaData), NewProp_VendorId_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_VendorDisplayName = { "VendorDisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, VendorDisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorDisplayName_MetaData), NewProp_VendorDisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_VendorSubtitle = { "VendorSubtitle", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, VendorSubtitle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorSubtitle_MetaData), NewProp_VendorSubtitle_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_InteractionPrompt = { "InteractionPrompt", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, InteractionPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionPrompt_MetaData), NewProp_InteractionPrompt_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bVendorEnabled = { "bVendorEnabled", "OnRep_VendorEnabled", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFItemVendorActor), &UHT_STATICS::NewProp_bVendorEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVendorEnabled_MetaData), NewProp_bVendorEnabled_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowBuying = { "bAllowBuying", "OnRep_Configuration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFItemVendorActor), &UHT_STATICS::NewProp_bAllowBuying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowBuying_MetaData), NewProp_bAllowBuying_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowSelling = { "bAllowSelling", "OnRep_Configuration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFItemVendorActor), &UHT_STATICS::NewProp_bAllowSelling_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowSelling_MetaData), NewProp_bAllowSelling_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequireItemInStockPoolToSell = { "bRequireItemInStockPoolToSell", "OnRep_Configuration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFItemVendorActor), &UHT_STATICS::NewProp_bRequireItemInStockPoolToSell_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireItemInStockPoolToSell_MetaData), NewProp_bRequireItemInStockPoolToSell_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InteractionRadius = { "InteractionRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, InteractionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionRadius_MetaData), NewProp_InteractionRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InteractionCollisionRadius = { "InteractionCollisionRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, InteractionCollisionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionCollisionRadius_MetaData), NewProp_InteractionCollisionRadius_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InteractionTraceChannel = { "InteractionTraceChannel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, InteractionTraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionTraceChannel_MetaData), NewProp_InteractionTraceChannel_MetaData) }; // 3aff698625c18cc2ccaa87a587b2eac8c50cdec7
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_StockSlots = { "StockSlots", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, StockSlots), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StockSlots_MetaData), NewProp_StockSlots_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowDuplicateItemsInStock = { "bAllowDuplicateItemsInStock", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFItemVendorActor), &UHT_STATICS::NewProp_bAllowDuplicateItemsInStock_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowDuplicateItemsInStock_MetaData), NewProp_bAllowDuplicateItemsInStock_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRefillDepletedSlotsImmediately = { "bRefillDepletedSlotsImmediately", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFItemVendorActor), &UHT_STATICS::NewProp_bRefillDepletedSlotsImmediately_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRefillDepletedSlotsImmediately_MetaData), NewProp_bRefillDepletedSlotsImmediately_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StockPool_Inner = { "StockPool", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry, METADATA_PARAMS(0, nullptr) }; // 19eec3540081bb9d52402885b07a11c197116cea
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_StockPool = { "StockPool", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, StockPool), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StockPool_MetaData), NewProp_StockPool_MetaData) }; // 19eec3540081bb9d52402885b07a11c197116cea
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRotateStockAutomatically = { "bRotateStockAutomatically", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFItemVendorActor), &UHT_STATICS::NewProp_bRotateStockAutomatically_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRotateStockAutomatically_MetaData), NewProp_bRotateStockAutomatically_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumStockRotationSeconds = { "MinimumStockRotationSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, MinimumStockRotationSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumStockRotationSeconds_MetaData), NewProp_MinimumStockRotationSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumStockRotationSeconds = { "MaximumStockRotationSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, MaximumStockRotationSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumStockRotationSeconds_MetaData), NewProp_MaximumStockRotationSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InitialStockRotationDelaySeconds = { "InitialStockRotationDelaySeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, InitialStockRotationDelaySeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialStockRotationDelaySeconds_MetaData), NewProp_InitialStockRotationDelaySeconds_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Pricing = { "Pricing", "OnRep_Configuration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, Pricing), Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pricing_MetaData), NewProp_Pricing_MetaData) }; // 9a8114ca756a3ca6443ded59af6d9f8d2efa234e
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_VendorWidgetClass = { "VendorWidgetClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, VendorWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFItemVendorWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorWidgetClass_MetaData), NewProp_VendorWidgetClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReplicatedStock_Inner = { "ReplicatedStock", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFItemVendorStockItem, METADATA_PARAMS(0, nullptr) }; // 307378684efd1eb244603410df5c821c6b708dc0
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReplicatedStock = { "ReplicatedStock", "OnRep_Stock", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, ReplicatedStock), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedStock_MetaData), NewProp_ReplicatedStock_MetaData) }; // 307378684efd1eb244603410df5c821c6b708dc0
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_StockGenerationSerial = { "StockGenerationSerial", "OnRep_Stock", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, StockGenerationSerial), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StockGenerationSerial_MetaData), NewProp_StockGenerationSerial_MetaData) };
const UECodeGen_Private::FDoublePropertyParams UHT_STATICS::NewProp_NextStockRotationServerTimeSeconds = { "NextStockRotationServerTimeSeconds", "OnRep_Stock", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Double, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, NextStockRotationServerTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextStockRotationServerTimeSeconds_MetaData), NewProp_NextStockRotationServerTimeSeconds_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVendorStockChanged = { "OnVendorStockChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, OnVendorStockChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorStockChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVendorStockChanged_MetaData), NewProp_OnVendorStockChanged_MetaData) }; // 1733a7b2b92c7645ef646758bfda6d6f102aa5ba
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVendorEnabledChanged = { "OnVendorEnabledChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, OnVendorEnabledChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorEnabledChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVendorEnabledChanged_MetaData), NewProp_OnVendorEnabledChanged_MetaData) }; // 868c03ae2f35fef8b0c18ba67e68c577b7dbffb2
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVendorConfigurationChanged = { "OnVendorConfigurationChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, OnVendorConfigurationChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorConfigurationChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVendorConfigurationChanged_MetaData), NewProp_OnVendorConfigurationChanged_MetaData) }; // 0739e4e75199872438c75d966c21f78c7fb86b76
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVendorTradeCompleted = { "OnVendorTradeCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFItemVendorActor, OnVendorTradeCompleted), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorTradeCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVendorTradeCompleted_MetaData), NewProp_OnVendorTradeCompleted_MetaData) }; // 8771ab5d0bdd2af1ae108110add5334cbed4e74e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorDisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorSubtitle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bVendorEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAllowBuying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAllowSelling,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequireItemInStockPoolToSell,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionCollisionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionTraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockSlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAllowDuplicateItemsInStock,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRefillDepletedSlotsImmediately,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockPool_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockPool,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRotateStockAutomatically,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumStockRotationSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumStockRotationSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InitialStockRotationDelaySeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Pricing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedStock_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedStock,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockGenerationSerial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NextStockRotationServerTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnVendorStockChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnVendorEnabledChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnVendorConfigurationChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnVendorTradeCompleted,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFItemVendorActor Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFItemVendorActor,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void ADMFItemVendorActor_StaticRegisterNativesADMFItemVendorActor()
{
	UClass* Class = ADMFItemVendorActor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFItemVendorActor;
UClass* Z_Construct_UClass_ADMFItemVendorActor(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFItemVendorActor;
		if (!Z_Registration_Info_UClass_ADMFItemVendorActor.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFItemVendorActor"),
				Z_Registration_Info_UClass_ADMFItemVendorActor.InnerSingleton,
				ADMFItemVendorActor_StaticRegisterNativesADMFItemVendorActor,
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
		return Z_Registration_Info_UClass_ADMFItemVendorActor.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFItemVendorActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFItemVendorActor.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFItemVendorActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFItemVendorActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_bVendorEnabled(TEXT("bVendorEnabled"));
	static FName Name_bAllowBuying(TEXT("bAllowBuying"));
	static FName Name_bAllowSelling(TEXT("bAllowSelling"));
	static FName Name_bRequireItemInStockPoolToSell(TEXT("bRequireItemInStockPoolToSell"));
	static FName Name_Pricing(TEXT("Pricing"));
	static FName Name_ReplicatedStock(TEXT("ReplicatedStock"));
	static FName Name_StockGenerationSerial(TEXT("StockGenerationSerial"));
	static FName Name_NextStockRotationServerTimeSeconds(TEXT("NextStockRotationServerTimeSeconds"));
	const bool bIsValid = true
		&& Name_bVendorEnabled == ClassReps[(int32)ENetFields_Private::bVendorEnabled].Property->GetFName()
		&& Name_bAllowBuying == ClassReps[(int32)ENetFields_Private::bAllowBuying].Property->GetFName()
		&& Name_bAllowSelling == ClassReps[(int32)ENetFields_Private::bAllowSelling].Property->GetFName()
		&& Name_bRequireItemInStockPoolToSell == ClassReps[(int32)ENetFields_Private::bRequireItemInStockPoolToSell].Property->GetFName()
		&& Name_Pricing == ClassReps[(int32)ENetFields_Private::Pricing].Property->GetFName()
		&& Name_ReplicatedStock == ClassReps[(int32)ENetFields_Private::ReplicatedStock].Property->GetFName()
		&& Name_StockGenerationSerial == ClassReps[(int32)ENetFields_Private::StockGenerationSerial].Property->GetFName()
		&& Name_NextStockRotationServerTimeSeconds == ClassReps[(int32)ENetFields_Private::NextStockRotationServerTimeSeconds].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFItemVendorActor"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFItemVendorActor);
ADMFItemVendorActor::~ADMFItemVendorActor() {}
// ********** End Class ADMFItemVendorActor ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry, Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry_Statics::NewStructOps, TEXT("DMFItemVendorPoolEntry"),&Z_Registration_Info_UScriptStruct_FDMFItemVendorPoolEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFItemVendorPoolEntry), 435077972U) },
		{ Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings, Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings_Statics::NewStructOps, TEXT("DMFItemVendorPricingSettings"),&Z_Registration_Info_UScriptStruct_FDMFItemVendorPricingSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFItemVendorPricingSettings), 2592150730U) },
		{ Z_Construct_UScriptStruct_FDMFItemVendorStockItem, Z_Construct_UScriptStruct_FDMFItemVendorStockItem_Statics::NewStructOps, TEXT("DMFItemVendorStockItem"),&Z_Registration_Info_UScriptStruct_FDMFItemVendorStockItem, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFItemVendorStockItem), 812873832U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFItemVendorActor, TEXT("ADMFItemVendorActor"), &Z_Registration_Info_UClass_ADMFItemVendorActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFItemVendorActor), 1963808368U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h__Script_DigimonMMOFramework_e3ae49e9fa070b2d94c0460ca80e561f0221f5ed{
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
