// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFDigimonVendorActor.h"
#include "DMFTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDigimonVendorActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
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
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonInstance(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonVendorActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorConfigurationChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorEnabledChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorGenerationRange(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorPricingSettings(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorStageMultipliers(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorStockChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorStockItem(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorTradeCompleted__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorValueBreakdown(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonVendorActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonVendorWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FDMFDigimonVendorGenerationRange **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonVendorGenerationRange_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonVendorGenerationRange>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonVendorGenerationRange); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Randomized generation envelope used when a vendor builds one stock Digimon. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Randomized generation envelope used when a vendor builds one stock Digimon." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumLevel_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "999" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumLevel_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "999" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumSpentAttributePoints_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of real +1 Attribute Point investments distributed across HP/SP/STR/INT/DEF/SPD. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of real +1 Attribute Point investments distributed across HP/SP/STR/INT/DEF/SPD." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumSpentAttributePoints_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumRandomHPBonus_MetaData[] = {
		{ "Category", "Generation|Natural Stat Variation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Independent natural stock variation applied after level growth and before trained Attribute Points. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Independent natural stock variation applied after level growth and before trained Attribute Points." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumRandomHPBonus_MetaData[] = {
		{ "Category", "Generation|Natural Stat Variation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumRandomSPBonus_MetaData[] = {
		{ "Category", "Generation|Natural Stat Variation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumRandomSPBonus_MetaData[] = {
		{ "Category", "Generation|Natural Stat Variation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumRandomCombatStatBonus_MetaData[] = {
		{ "Category", "Generation|Natural Stat Variation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rolled independently for STR, INT, DEF and SPD. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rolled independently for STR, INT, DEF and SPD." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumRandomCombatStatBonus_MetaData[] = {
		{ "Category", "Generation|Natural Stat Variation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumUnspentAttributePoints_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional unused points supplied with the purchased Digimon. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional unused points supplied with the purchased Digimon." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumUnspentAttributePoints_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumABI_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "9999" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumABI_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "9999" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumCAM_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "100" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumCAM_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "100" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumLevelExperiencePercent_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "0.999" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current-level EXP bank as a fraction of the next-level requirement. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current-level EXP bank as a fraction of the next-level requirement." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumLevelExperiencePercent_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "0.999" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonVendorGenerationRange constinit property declarations **
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumSpentAttributePoints;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumSpentAttributePoints;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumRandomHPBonus;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumRandomHPBonus;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumRandomSPBonus;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumRandomSPBonus;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumRandomCombatStatBonus;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumRandomCombatStatBonus;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumUnspentAttributePoints;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumUnspentAttributePoints;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumABI;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumABI;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumCAM;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumCAM;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumLevelExperiencePercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumLevelExperiencePercent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonVendorGenerationRange constinit property declarations ****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonVendorGenerationRange>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonVendorGenerationRange Property Definitions *************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumLevel = { "MinimumLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MinimumLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumLevel_MetaData), NewProp_MinimumLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumLevel = { "MaximumLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MaximumLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumLevel_MetaData), NewProp_MaximumLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumSpentAttributePoints = { "MinimumSpentAttributePoints", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MinimumSpentAttributePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumSpentAttributePoints_MetaData), NewProp_MinimumSpentAttributePoints_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumSpentAttributePoints = { "MaximumSpentAttributePoints", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MaximumSpentAttributePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumSpentAttributePoints_MetaData), NewProp_MaximumSpentAttributePoints_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumRandomHPBonus = { "MinimumRandomHPBonus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MinimumRandomHPBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumRandomHPBonus_MetaData), NewProp_MinimumRandomHPBonus_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumRandomHPBonus = { "MaximumRandomHPBonus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MaximumRandomHPBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumRandomHPBonus_MetaData), NewProp_MaximumRandomHPBonus_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumRandomSPBonus = { "MinimumRandomSPBonus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MinimumRandomSPBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumRandomSPBonus_MetaData), NewProp_MinimumRandomSPBonus_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumRandomSPBonus = { "MaximumRandomSPBonus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MaximumRandomSPBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumRandomSPBonus_MetaData), NewProp_MaximumRandomSPBonus_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumRandomCombatStatBonus = { "MinimumRandomCombatStatBonus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MinimumRandomCombatStatBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumRandomCombatStatBonus_MetaData), NewProp_MinimumRandomCombatStatBonus_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumRandomCombatStatBonus = { "MaximumRandomCombatStatBonus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MaximumRandomCombatStatBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumRandomCombatStatBonus_MetaData), NewProp_MaximumRandomCombatStatBonus_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumUnspentAttributePoints = { "MinimumUnspentAttributePoints", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MinimumUnspentAttributePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumUnspentAttributePoints_MetaData), NewProp_MinimumUnspentAttributePoints_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumUnspentAttributePoints = { "MaximumUnspentAttributePoints", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MaximumUnspentAttributePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumUnspentAttributePoints_MetaData), NewProp_MaximumUnspentAttributePoints_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumABI = { "MinimumABI", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MinimumABI), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumABI_MetaData), NewProp_MinimumABI_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumABI = { "MaximumABI", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MaximumABI), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumABI_MetaData), NewProp_MaximumABI_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumCAM = { "MinimumCAM", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MinimumCAM), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumCAM_MetaData), NewProp_MinimumCAM_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumCAM = { "MaximumCAM", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MaximumCAM), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumCAM_MetaData), NewProp_MaximumCAM_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumLevelExperiencePercent = { "MinimumLevelExperiencePercent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MinimumLevelExperiencePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumLevelExperiencePercent_MetaData), NewProp_MinimumLevelExperiencePercent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumLevelExperiencePercent = { "MaximumLevelExperiencePercent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorGenerationRange, MaximumLevelExperiencePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumLevelExperiencePercent_MetaData), NewProp_MaximumLevelExperiencePercent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumSpentAttributePoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumSpentAttributePoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumRandomHPBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumRandomHPBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumRandomSPBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumRandomSPBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumRandomCombatStatBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumRandomCombatStatBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumUnspentAttributePoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumUnspentAttributePoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumABI,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumABI,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumCAM,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumCAM,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumLevelExperiencePercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumLevelExperiencePercent,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonVendorGenerationRange Property Definitions ***************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonVendorGenerationRange",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonVendorGenerationRange>(),
	alignof(FDMFDigimonVendorGenerationRange),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonVendorGenerationRange;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorGenerationRange(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorGenerationRange.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonVendorGenerationRange.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonVendorGenerationRange, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonVendorGenerationRange"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonVendorGenerationRange.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorGenerationRange.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorGenerationRange.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorGenerationRange.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonVendorGenerationRange ************************************

// ********** Begin ScriptStruct FDMFDigimonVendorSpeciesPoolEntry *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonVendorSpeciesPoolEntry>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonVendorSpeciesPoolEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** One species candidate in a placed vendor's stock pool. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One species candidate in a placed vendor's stock pool." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Species_MetaData[] = {
		{ "Category", "Species" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectionWeight_MetaData[] = {
		{ "Category", "Species" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PurchasePriceMultiplier_MetaData[] = {
		{ "Category", "Species" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.01" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional market rarity/scarcity adjustment after automatic valuation. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional market rarity/scarcity adjustment after automatic valuation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideGenerationRange_MetaData[] = {
		{ "Category", "Generation" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationRangeOverride_MetaData[] = {
		{ "Category", "Generation" },
		{ "EditCondition", "bOverrideGenerationRange" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonVendorSpeciesPoolEntry constinit property declarations *
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Species;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SelectionWeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PurchasePriceMultiplier;
	static void NewProp_bOverrideGenerationRange_SetBit(void* Obj)
	{
		((FDMFDigimonVendorSpeciesPoolEntry*)Obj)->bOverrideGenerationRange = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideGenerationRange;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GenerationRangeOverride;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonVendorSpeciesPoolEntry constinit property declarations ***
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonVendorSpeciesPoolEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonVendorSpeciesPoolEntry Property Definitions ************
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Species = { "Species", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorSpeciesPoolEntry, Species), Z_Construct_UClass_UDMFDigimonSpeciesData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Species_MetaData), NewProp_Species_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SelectionWeight = { "SelectionWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorSpeciesPoolEntry, SelectionWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectionWeight_MetaData), NewProp_SelectionWeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PurchasePriceMultiplier = { "PurchasePriceMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorSpeciesPoolEntry, PurchasePriceMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PurchasePriceMultiplier_MetaData), NewProp_PurchasePriceMultiplier_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bOverrideGenerationRange = { "bOverrideGenerationRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigimonVendorSpeciesPoolEntry), &UHT_STATICS::NewProp_bOverrideGenerationRange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideGenerationRange_MetaData), NewProp_bOverrideGenerationRange_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_GenerationRangeOverride = { "GenerationRangeOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorSpeciesPoolEntry, GenerationRangeOverride), Z_Construct_UScriptStruct_FDMFDigimonVendorGenerationRange, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationRangeOverride_MetaData), NewProp_GenerationRangeOverride_MetaData) }; // ee160f106308908b84487bbb1cb40a8be755d195
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Species,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectionWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PurchasePriceMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bOverrideGenerationRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GenerationRangeOverride,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonVendorSpeciesPoolEntry Property Definitions **************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonVendorSpeciesPoolEntry",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonVendorSpeciesPoolEntry>(),
	alignof(FDMFDigimonVendorSpeciesPoolEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonVendorSpeciesPoolEntry"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonVendorSpeciesPoolEntry ***********************************

// ********** Begin ScriptStruct FDMFDigimonVendorStageMultipliers *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonVendorStageMultipliers_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonVendorStageMultipliers>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonVendorStageMultipliers); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Per-stage automatic market multipliers. Existing species Data Assets require no vendor-price field. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-stage automatic market multipliers. Existing species Data Assets require no vendor-price field." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fresh_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTraining_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rookie_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Champion_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ultimate_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mega_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ultra_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Armor_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hybrid_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Unknown_MetaData[] = {
		{ "Category", "Stage Multipliers" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonVendorStageMultipliers constinit property declarations *
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Fresh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InTraining;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rookie;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Champion;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Ultimate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Mega;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Ultra;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Armor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Hybrid;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Unknown;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonVendorStageMultipliers constinit property declarations ***
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonVendorStageMultipliers>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonVendorStageMultipliers Property Definitions ************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Fresh = { "Fresh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, Fresh), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fresh_MetaData), NewProp_Fresh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InTraining = { "InTraining", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, InTraining), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTraining_MetaData), NewProp_InTraining_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Rookie = { "Rookie", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, Rookie), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rookie_MetaData), NewProp_Rookie_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Champion = { "Champion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, Champion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Champion_MetaData), NewProp_Champion_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Ultimate = { "Ultimate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, Ultimate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ultimate_MetaData), NewProp_Ultimate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Mega = { "Mega", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, Mega), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mega_MetaData), NewProp_Mega_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Ultra = { "Ultra", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, Ultra), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ultra_MetaData), NewProp_Ultra_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Armor = { "Armor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, Armor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Armor_MetaData), NewProp_Armor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Hybrid = { "Hybrid", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, Hybrid), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hybrid_MetaData), NewProp_Hybrid_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Unknown = { "Unknown", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStageMultipliers, Unknown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Unknown_MetaData), NewProp_Unknown_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Fresh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InTraining,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rookie,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Champion,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Ultimate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mega,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Ultra,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Armor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Hybrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Unknown,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonVendorStageMultipliers Property Definitions **************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonVendorStageMultipliers",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonVendorStageMultipliers>(),
	alignof(FDMFDigimonVendorStageMultipliers),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStageMultipliers;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorStageMultipliers(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStageMultipliers.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStageMultipliers.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonVendorStageMultipliers, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonVendorStageMultipliers"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStageMultipliers.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStageMultipliers.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStageMultipliers.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStageMultipliers.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonVendorStageMultipliers ***********************************

// ********** Begin ScriptStruct FDMFDigimonVendorPricingSettings **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonVendorPricingSettings_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonVendorPricingSettings>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonVendorPricingSettings); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tunable automatic valuation model shared by vendor purchases and player resale quotes. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tunable automatic valuation model shared by vendor purchases and player resale quotes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseSpeciesValue_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePerLevel_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePer100LifetimeExperience_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePerMaxHPPoint_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePerMaxSPPoint_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePerCombatStatPoint_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePerABIPoint_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePerCAMPoint_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePerSpentAttributePoint_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePerUnspentAttributePoint_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValuePerVisitedDigivolutionForm_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StageMultipliers_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorBuyMarkup_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.01" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** What a player pays relative to the fully calculated market value. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What a player pays relative to the fully calculated market value." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSellPayoutMultiplier_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** What the vendor pays a player relative to the fully calculated market value. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What the vendor pays a player relative to the fully calculated market value." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumTransactionPrice_MetaData[] = {
		{ "Category", "Pricing" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonVendorPricingSettings constinit property declarations **
	static const UECodeGen_Private::FInt64PropertyParams NewProp_BaseSpeciesValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePerLevel;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePer100LifetimeExperience;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePerMaxHPPoint;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePerMaxSPPoint;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePerCombatStatPoint;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePerABIPoint;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePerCAMPoint;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePerSpentAttributePoint;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePerUnspentAttributePoint;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ValuePerVisitedDigivolutionForm;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StageMultipliers;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VendorBuyMarkup;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerSellPayoutMultiplier;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_MinimumTransactionPrice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonVendorPricingSettings constinit property declarations ****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonVendorPricingSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonVendorPricingSettings Property Definitions *************
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_BaseSpeciesValue = { "BaseSpeciesValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, BaseSpeciesValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseSpeciesValue_MetaData), NewProp_BaseSpeciesValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePerLevel = { "ValuePerLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePerLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePerLevel_MetaData), NewProp_ValuePerLevel_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePer100LifetimeExperience = { "ValuePer100LifetimeExperience", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePer100LifetimeExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePer100LifetimeExperience_MetaData), NewProp_ValuePer100LifetimeExperience_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePerMaxHPPoint = { "ValuePerMaxHPPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePerMaxHPPoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePerMaxHPPoint_MetaData), NewProp_ValuePerMaxHPPoint_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePerMaxSPPoint = { "ValuePerMaxSPPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePerMaxSPPoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePerMaxSPPoint_MetaData), NewProp_ValuePerMaxSPPoint_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePerCombatStatPoint = { "ValuePerCombatStatPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePerCombatStatPoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePerCombatStatPoint_MetaData), NewProp_ValuePerCombatStatPoint_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePerABIPoint = { "ValuePerABIPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePerABIPoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePerABIPoint_MetaData), NewProp_ValuePerABIPoint_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePerCAMPoint = { "ValuePerCAMPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePerCAMPoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePerCAMPoint_MetaData), NewProp_ValuePerCAMPoint_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePerSpentAttributePoint = { "ValuePerSpentAttributePoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePerSpentAttributePoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePerSpentAttributePoint_MetaData), NewProp_ValuePerSpentAttributePoint_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePerUnspentAttributePoint = { "ValuePerUnspentAttributePoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePerUnspentAttributePoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePerUnspentAttributePoint_MetaData), NewProp_ValuePerUnspentAttributePoint_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ValuePerVisitedDigivolutionForm = { "ValuePerVisitedDigivolutionForm", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, ValuePerVisitedDigivolutionForm), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValuePerVisitedDigivolutionForm_MetaData), NewProp_ValuePerVisitedDigivolutionForm_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StageMultipliers = { "StageMultipliers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, StageMultipliers), Z_Construct_UScriptStruct_FDMFDigimonVendorStageMultipliers, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StageMultipliers_MetaData), NewProp_StageMultipliers_MetaData) }; // 0aaf843bcdd2742b35c80332c1f90993c9c08dee
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_VendorBuyMarkup = { "VendorBuyMarkup", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, VendorBuyMarkup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorBuyMarkup_MetaData), NewProp_VendorBuyMarkup_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PlayerSellPayoutMultiplier = { "PlayerSellPayoutMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, PlayerSellPayoutMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSellPayoutMultiplier_MetaData), NewProp_PlayerSellPayoutMultiplier_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_MinimumTransactionPrice = { "MinimumTransactionPrice", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorPricingSettings, MinimumTransactionPrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumTransactionPrice_MetaData), NewProp_MinimumTransactionPrice_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BaseSpeciesValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePerLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePer100LifetimeExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePerMaxHPPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePerMaxSPPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePerCombatStatPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePerABIPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePerCAMPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePerSpentAttributePoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePerUnspentAttributePoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ValuePerVisitedDigivolutionForm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StageMultipliers,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorBuyMarkup,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSellPayoutMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumTransactionPrice,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonVendorPricingSettings Property Definitions ***************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonVendorPricingSettings",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonVendorPricingSettings>(),
	alignof(FDMFDigimonVendorPricingSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonVendorPricingSettings;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorPricingSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorPricingSettings.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonVendorPricingSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonVendorPricingSettings, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonVendorPricingSettings"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonVendorPricingSettings.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorPricingSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorPricingSettings.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorPricingSettings.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonVendorPricingSettings ************************************

// ********** Begin ScriptStruct FDMFDigimonVendorValueBreakdown ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonVendorValueBreakdown_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonVendorValueBreakdown>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonVendorValueBreakdown); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint/UI-facing explanation of an automatic valuation. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint/UI-facing explanation of an automatic valuation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesAndStageValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperienceValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatsValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ABIValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CAMValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeTrainingValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionHistoryValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MarketValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorPurchasePrice_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSellPrice_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonVendorValueBreakdown constinit property declarations ***
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SpeciesAndStageValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_LevelValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ExperienceValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_StatsValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ABIValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_CAMValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_AttributeTrainingValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_DigivolutionHistoryValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_MarketValue;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_VendorPurchasePrice;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PlayerSellPrice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonVendorValueBreakdown constinit property declarations *****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonVendorValueBreakdown>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonVendorValueBreakdown Property Definitions **************
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_SpeciesAndStageValue = { "SpeciesAndStageValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, SpeciesAndStageValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesAndStageValue_MetaData), NewProp_SpeciesAndStageValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_LevelValue = { "LevelValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, LevelValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelValue_MetaData), NewProp_LevelValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ExperienceValue = { "ExperienceValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, ExperienceValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperienceValue_MetaData), NewProp_ExperienceValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_StatsValue = { "StatsValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, StatsValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatsValue_MetaData), NewProp_StatsValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ABIValue = { "ABIValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, ABIValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ABIValue_MetaData), NewProp_ABIValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_CAMValue = { "CAMValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, CAMValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CAMValue_MetaData), NewProp_CAMValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_AttributeTrainingValue = { "AttributeTrainingValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, AttributeTrainingValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeTrainingValue_MetaData), NewProp_AttributeTrainingValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_DigivolutionHistoryValue = { "DigivolutionHistoryValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, DigivolutionHistoryValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionHistoryValue_MetaData), NewProp_DigivolutionHistoryValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_MarketValue = { "MarketValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, MarketValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MarketValue_MetaData), NewProp_MarketValue_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_VendorPurchasePrice = { "VendorPurchasePrice", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, VendorPurchasePrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorPurchasePrice_MetaData), NewProp_VendorPurchasePrice_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_PlayerSellPrice = { "PlayerSellPrice", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorValueBreakdown, PlayerSellPrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSellPrice_MetaData), NewProp_PlayerSellPrice_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesAndStageValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LevelValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExperienceValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StatsValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ABIValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CAMValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AttributeTrainingValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionHistoryValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MarketValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorPurchasePrice,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSellPrice,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonVendorValueBreakdown Property Definitions ****************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonVendorValueBreakdown",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonVendorValueBreakdown>(),
	alignof(FDMFDigimonVendorValueBreakdown),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonVendorValueBreakdown;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorValueBreakdown(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorValueBreakdown.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonVendorValueBreakdown.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonVendorValueBreakdown, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonVendorValueBreakdown"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonVendorValueBreakdown.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorValueBreakdown.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorValueBreakdown.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorValueBreakdown.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonVendorValueBreakdown *************************************

// ********** Begin ScriptStruct FDMFDigimonVendorStockItem ****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonVendorStockItem_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonVendorStockItem>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonVendorStockItem); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replicated immutable offer snapshot generated by the server for one stock slot. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated immutable offer snapshot generated by the server for one stock slot." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StockId_MetaData[] = {
		{ "Category", "Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Digimon_MetaData[] = {
		{ "Category", "Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PurchasePrice_MetaData[] = {
		{ "Category", "Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationSerial_MetaData[] = {
		{ "Category", "Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonVendorStockItem constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_StockId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Digimon;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PurchasePrice;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GenerationSerial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonVendorStockItem constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonVendorStockItem>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonVendorStockItem Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StockId = { "StockId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStockItem, StockId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StockId_MetaData), NewProp_StockId_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Digimon = { "Digimon", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStockItem, Digimon), Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Digimon_MetaData), NewProp_Digimon_MetaData) }; // 4e507a01c7f3f7d9482109ce7a0bc560288acac2
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_PurchasePrice = { "PurchasePrice", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStockItem, PurchasePrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PurchasePrice_MetaData), NewProp_PurchasePrice_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_GenerationSerial = { "GenerationSerial", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonVendorStockItem, GenerationSerial), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationSerial_MetaData), NewProp_GenerationSerial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PurchasePrice,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GenerationSerial,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonVendorStockItem Property Definitions *********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonVendorStockItem",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonVendorStockItem>(),
	alignof(FDMFDigimonVendorStockItem),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStockItem;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonVendorStockItem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStockItem.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStockItem.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonVendorStockItem, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonVendorStockItem"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStockItem.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStockItem.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStockItem.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStockItem.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonVendorStockItem ******************************************

// ********** Begin Delegate FDMFDigimonVendorStockChanged *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorStockChanged__DelegateSignature_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFDigimonVendorStockChanged constinit property declarations *********
// ********** End Delegate FDMFDigimonVendorStockChanged constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFDigimonVendorStockChanged__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorStockChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFDigimonVendorStockChanged *******************************************

// ********** Begin Delegate FDMFDigimonVendorEnabledChanged ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorEnabledChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFDigimonVendorEnabledChanged_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFDigimonVendorEnabledChanged constinit property declarations *******
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFDigimonVendorEnabledChanged_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFDigimonVendorEnabledChanged constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFDigimonVendorEnabledChanged Property Definitions ******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFDigimonVendorEnabledChanged_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFDigimonVendorEnabledChanged Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFDigimonVendorEnabledChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonVendorEnabledChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonVendorEnabledChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorEnabledChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFDigimonVendorEnabledChanged *****************************************

// ********** Begin Delegate FDMFDigimonVendorConfigurationChanged *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorConfigurationChanged__DelegateSignature_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFDigimonVendorConfigurationChanged constinit property declarations *
// ********** End Delegate FDMFDigimonVendorConfigurationChanged constinit property declarations ***
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFDigimonVendorConfigurationChanged__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorConfigurationChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFDigimonVendorConfigurationChanged ***********************************

// ********** Begin Delegate FDMFDigimonVendorTradeCompleted ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorTradeCompleted__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFDigimonVendorTradeCompleted_Parms
	{
		ADMFMMOPlayerController* PlayerController;
		EDMFDigimonVendorTransactionType TransactionType;
		FDMFDigimonInstance Digimon;
		int64 Price;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFDigimonVendorTradeCompleted constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Digimon;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Price;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFDigimonVendorTradeCompleted constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFDigimonVendorTradeCompleted Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorTradeCompleted_Parms, PlayerController), Z_Construct_UClass_ADMFMMOPlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorTradeCompleted_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Digimon = { "Digimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorTradeCompleted_Parms, Digimon), Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(0, nullptr) }; // 4e507a01c7f3f7d9482109ce7a0bc560288acac2
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_Price = { "Price", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorTradeCompleted_Parms, Price), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Price,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFDigimonVendorTradeCompleted Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFDigimonVendorTradeCompleted__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonVendorTradeCompleted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonVendorTradeCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorTradeCompleted__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFDigimonVendorTradeCompleted *****************************************

// ********** Begin Class ADMFDigimonVendorActor Function BP_OnStockRefreshed **********************
static FName NAME_ADMFDigimonVendorActor_BP_OnStockRefreshed = FName(TEXT("BP_OnStockRefreshed"));
void ADMFDigimonVendorActor::BP_OnStockRefreshed()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFDigimonVendorActor_BP_OnStockRefreshed);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_BP_OnStockRefreshed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnStockRefreshed constinit property declarations *******************
// ********** End Function BP_OnStockRefreshed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "BP_OnStockRefreshed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_BP_OnStockRefreshed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFDigimonVendorActor Function BP_OnStockRefreshed ************************

// ********** Begin Class ADMFDigimonVendorActor Function BP_OnVendorEnabledChanged ****************
struct DMFDigimonVendorActor_eventBP_OnVendorEnabledChanged_Parms
{
	bool bEnabled;
};
static FName NAME_ADMFDigimonVendorActor_BP_OnVendorEnabledChanged = FName(TEXT("BP_OnVendorEnabledChanged"));
void ADMFDigimonVendorActor::BP_OnVendorEnabledChanged(bool bEnabled)
{
	DMFDigimonVendorActor_eventBP_OnVendorEnabledChanged_Parms Parms;
	Parms.bEnabled=bEnabled ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ADMFDigimonVendorActor_BP_OnVendorEnabledChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_BP_OnVendorEnabledChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVendorEnabledChanged constinit property declarations *************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFDigimonVendorActor_eventBP_OnVendorEnabledChanged_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnVendorEnabledChanged constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnVendorEnabledChanged Property Definitions ************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonVendorActor_eventBP_OnVendorEnabledChanged_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnVendorEnabledChanged Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "BP_OnVendorEnabledChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonVendorActor_eventBP_OnVendorEnabledChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonVendorActor_eventBP_OnVendorEnabledChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_BP_OnVendorEnabledChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFDigimonVendorActor Function BP_OnVendorEnabledChanged ******************

// ********** Begin Class ADMFDigimonVendorActor Function BP_OnVendorTradeCompleted ****************
struct DMFDigimonVendorActor_eventBP_OnVendorTradeCompleted_Parms
{
	ADMFMMOPlayerController* PlayerController;
	EDMFDigimonVendorTransactionType TransactionType;
	FDMFDigimonInstance Digimon;
	int64 Price;
};
static FName NAME_ADMFDigimonVendorActor_BP_OnVendorTradeCompleted = FName(TEXT("BP_OnVendorTradeCompleted"));
void ADMFDigimonVendorActor::BP_OnVendorTradeCompleted(ADMFMMOPlayerController* PlayerController, EDMFDigimonVendorTransactionType TransactionType, FDMFDigimonInstance Digimon, int64 Price)
{
	DMFDigimonVendorActor_eventBP_OnVendorTradeCompleted_Parms Parms;
	Parms.PlayerController=PlayerController;
	Parms.TransactionType=TransactionType;
	Parms.Digimon=Digimon;
	Parms.Price=Price;
	UFunction* Func = FindFunctionChecked(NAME_ADMFDigimonVendorActor_BP_OnVendorTradeCompleted);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_BP_OnVendorTradeCompleted_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVendorTradeCompleted constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Digimon;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Price;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnVendorTradeCompleted constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnVendorTradeCompleted Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventBP_OnVendorTradeCompleted_Parms, PlayerController), Z_Construct_UClass_ADMFMMOPlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventBP_OnVendorTradeCompleted_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Digimon = { "Digimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventBP_OnVendorTradeCompleted_Parms, Digimon), Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(0, nullptr) }; // 4e507a01c7f3f7d9482109ce7a0bc560288acac2
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_Price = { "Price", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventBP_OnVendorTradeCompleted_Parms, Price), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Price,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnVendorTradeCompleted Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "BP_OnVendorTradeCompleted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonVendorActor_eventBP_OnVendorTradeCompleted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonVendorActor_eventBP_OnVendorTradeCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_BP_OnVendorTradeCompleted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFDigimonVendorActor Function BP_OnVendorTradeCompleted ******************

// ********** Begin Class ADMFDigimonVendorActor Function CalculateDigimonValue ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_CalculateDigimonValue_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventCalculateDigimonValue_Parms
	{
		FDMFDigimonInstance Digimon;
		FDMFDigimonVendorValueBreakdown ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Pricing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Digimon_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CalculateDigimonValue constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Digimon;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CalculateDigimonValue constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CalculateDigimonValue Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Digimon = { "Digimon", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventCalculateDigimonValue_Parms, Digimon), Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Digimon_MetaData), NewProp_Digimon_MetaData) }; // 4e507a01c7f3f7d9482109ce7a0bc560288acac2
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventCalculateDigimonValue_Parms, ReturnValue), Z_Construct_UScriptStruct_FDMFDigimonVendorValueBreakdown, METADATA_PARAMS(0, nullptr) }; // 8112ea5907d21bba74dd4de0365d08aee84f749c
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CalculateDigimonValue Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "CalculateDigimonValue", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventCalculateDigimonValue_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventCalculateDigimonValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_CalculateDigimonValue(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execCalculateDigimonValue)
{
	P_GET_STRUCT_REF(FDMFDigimonInstance,Z_Param_Out_Digimon);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FDMFDigimonVendorValueBreakdown*)Z_Param__Result=P_THIS->CalculateDigimonValue(Z_Param_Out_Digimon);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function CalculateDigimonValue **********************

// ********** Begin Class ADMFDigimonVendorActor Function GetPlayerSellPrice ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_GetPlayerSellPrice_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventGetPlayerSellPrice_Parms
	{
		FDMFDigimonInstance Digimon;
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Pricing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Digimon_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerSellPrice constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Digimon;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerSellPrice constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerSellPrice Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Digimon = { "Digimon", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventGetPlayerSellPrice_Parms, Digimon), Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Digimon_MetaData), NewProp_Digimon_MetaData) }; // 4e507a01c7f3f7d9482109ce7a0bc560288acac2
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventGetPlayerSellPrice_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetPlayerSellPrice Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "GetPlayerSellPrice", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventGetPlayerSellPrice_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventGetPlayerSellPrice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_GetPlayerSellPrice(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execGetPlayerSellPrice)
{
	P_GET_STRUCT_REF(FDMFDigimonInstance,Z_Param_Out_Digimon);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=P_THIS->GetPlayerSellPrice(Z_Param_Out_Digimon);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function GetPlayerSellPrice *************************

// ********** Begin Class ADMFDigimonVendorActor Function GetSecondsUntilStockRotation *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_GetSecondsUntilStockRotation_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventGetSecondsUntilStockRotation_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSecondsUntilStockRotation constinit property declarations **********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSecondsUntilStockRotation constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSecondsUntilStockRotation Property Definitions *********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventGetSecondsUntilStockRotation_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSecondsUntilStockRotation Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "GetSecondsUntilStockRotation", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventGetSecondsUntilStockRotation_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventGetSecondsUntilStockRotation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_GetSecondsUntilStockRotation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execGetSecondsUntilStockRotation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetSecondsUntilStockRotation();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function GetSecondsUntilStockRotation ***************

// ********** Begin Class ADMFDigimonVendorActor Function GetVendorStock ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_GetVendorStock_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventGetVendorStock_Parms
	{
		TArray<FDMFDigimonVendorStockItem> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
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
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFDigimonVendorStockItem, METADATA_PARAMS(0, nullptr) }; // 9cea3b80b98a6bce28df6a536f071c40438e9986
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventGetVendorStock_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 9cea3b80b98a6bce28df6a536f071c40438e9986
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetVendorStock Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "GetVendorStock", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventGetVendorStock_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventGetVendorStock_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_GetVendorStock(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execGetVendorStock)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FDMFDigimonVendorStockItem>*)Z_Param__Result=P_THIS->GetVendorStock();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function GetVendorStock *****************************

// ********** Begin Class ADMFDigimonVendorActor Function IsPlayerWithinTradeRange *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_IsPlayerWithinTradeRange_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventIsPlayerWithinTradeRange_Parms
	{
		APlayerController* PlayerController;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Interaction" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPlayerWithinTradeRange constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonVendorActor_eventIsPlayerWithinTradeRange_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPlayerWithinTradeRange constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPlayerWithinTradeRange Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventIsPlayerWithinTradeRange_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonVendorActor_eventIsPlayerWithinTradeRange_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsPlayerWithinTradeRange Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "IsPlayerWithinTradeRange", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventIsPlayerWithinTradeRange_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventIsPlayerWithinTradeRange_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_IsPlayerWithinTradeRange(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execIsPlayerWithinTradeRange)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayerWithinTradeRange(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function IsPlayerWithinTradeRange *******************

// ********** Begin Class ADMFDigimonVendorActor Function IsVendorEnabled **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_IsVendorEnabled_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventIsVendorEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsVendorEnabled constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFDigimonVendorActor_eventIsVendorEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsVendorEnabled constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsVendorEnabled Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonVendorActor_eventIsVendorEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsVendorEnabled Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "IsVendorEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventIsVendorEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventIsVendorEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_IsVendorEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execIsVendorEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsVendorEnabled();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function IsVendorEnabled ****************************

// ********** Begin Class ADMFDigimonVendorActor Function OnRep_Configuration **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_OnRep_Configuration_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_Configuration constinit property declarations *******************
// ********** End Function OnRep_Configuration constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "OnRep_Configuration", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_OnRep_Configuration(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execOnRep_Configuration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Configuration();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function OnRep_Configuration ************************

// ********** Begin Class ADMFDigimonVendorActor Function OnRep_Stock ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_OnRep_Stock_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_Stock constinit property declarations ***************************
// ********** End Function OnRep_Stock constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "OnRep_Stock", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_OnRep_Stock(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execOnRep_Stock)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Stock();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function OnRep_Stock ********************************

// ********** Begin Class ADMFDigimonVendorActor Function OnRep_VendorEnabled **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_OnRep_VendorEnabled_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_VendorEnabled constinit property declarations *******************
// ********** End Function OnRep_VendorEnabled constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "OnRep_VendorEnabled", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_OnRep_VendorEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execOnRep_VendorEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_VendorEnabled();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function OnRep_VendorEnabled ************************

// ********** Begin Class ADMFDigimonVendorActor Function RefreshStockNow **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_RefreshStockNow_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshStockNow constinit property declarations ***********************
// ********** End Function RefreshStockNow constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "RefreshStockNow", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_RefreshStockNow(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execRefreshStockNow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshStockNow();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function RefreshStockNow ****************************

// ********** Begin Class ADMFDigimonVendorActor Function RestartStockRotationSchedule *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_RestartStockRotationSchedule_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock Rotation" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestartStockRotationSchedule constinit property declarations **********
// ********** End Function RestartStockRotationSchedule constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "RestartStockRotationSchedule", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_RestartStockRotationSchedule(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execRestartStockRotationSchedule)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RestartStockRotationSchedule();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function RestartStockRotationSchedule ***************

// ********** Begin Class ADMFDigimonVendorActor Function SetBuyingEnabled *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_SetBuyingEnabled_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventSetBuyingEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBuyingEnabled constinit property declarations **********************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFDigimonVendorActor_eventSetBuyingEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBuyingEnabled constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBuyingEnabled Property Definitions *********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonVendorActor_eventSetBuyingEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetBuyingEnabled Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "SetBuyingEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventSetBuyingEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventSetBuyingEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_SetBuyingEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execSetBuyingEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBuyingEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function SetBuyingEnabled ***************************

// ********** Begin Class ADMFDigimonVendorActor Function SetPricingSettings ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_SetPricingSettings_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventSetPricingSettings_Parms
	{
		FDMFDigimonVendorPricingSettings NewPricing;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Pricing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
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
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NewPricing = { "NewPricing", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorActor_eventSetPricingSettings_Parms, NewPricing), Z_Construct_UScriptStruct_FDMFDigimonVendorPricingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewPricing_MetaData), NewProp_NewPricing_MetaData) }; // 1281fa943adc14215a62afdb40d48437a02e0ba5
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPricing,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetPricingSettings Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "SetPricingSettings", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventSetPricingSettings_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventSetPricingSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_SetPricingSettings(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execSetPricingSettings)
{
	P_GET_STRUCT_REF(FDMFDigimonVendorPricingSettings,Z_Param_Out_NewPricing);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPricingSettings(Z_Param_Out_NewPricing);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function SetPricingSettings *************************

// ********** Begin Class ADMFDigimonVendorActor Function SetSellingEnabled ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_SetSellingEnabled_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventSetSellingEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSellingEnabled constinit property declarations *********************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFDigimonVendorActor_eventSetSellingEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSellingEnabled constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSellingEnabled Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonVendorActor_eventSetSellingEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetSellingEnabled Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "SetSellingEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventSetSellingEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventSetSellingEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_SetSellingEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execSetSellingEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSellingEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function SetSellingEnabled **************************

// ********** Begin Class ADMFDigimonVendorActor Function SetVendorEnabled *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonVendorActor_SetVendorEnabled_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorActor_eventSetVendorEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVendorEnabled constinit property declarations **********************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFDigimonVendorActor_eventSetVendorEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVendorEnabled constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVendorEnabled Property Definitions *********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonVendorActor_eventSetVendorEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetVendorEnabled Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonVendorActor, nullptr, "SetVendorEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorActor_eventSetVendorEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorActor_eventSetVendorEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonVendorActor_SetVendorEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonVendorActor::execSetVendorEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVendorEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonVendorActor Function SetVendorEnabled ***************************

// ********** Begin Class ADMFDigimonVendorActor ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFDigimonVendorActor_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Blueprint-derivable, server-authoritative Digimon market NPC.\n * Stock generation, rotation, pricing and transactions are authority-owned; the native UI is owner-local presentation.\n */" },
#endif
		{ "IncludePath", "Game/DMFDigimonVendorActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint-derivable, server-authoritative Digimon market NPC.\nStock generation, rotation, pricing and transactions are authority-owned; the native UI is owner-local presentation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorMesh_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Presentation" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionCollision_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Interaction" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorId_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Identity" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorDisplayName_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Identity" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorSubtitle_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Identity" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionPrompt_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Interaction" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVendorEnabled_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowBuying_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowSelling_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowSellingStarterDigimon_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Selling" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireAtLeastOnePartyDigimon_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Selling" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreferPurchasedDigimonToBank_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Buying" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Interaction" },
		{ "ClampMin", "50.0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionCollisionRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Interaction" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionTraceChannel_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Interaction" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StockSlots_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ClampMax", "64" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowDuplicateSpeciesInStock_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRefillSoldSlotsImmediately_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesPool_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultGenerationRange_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRotateStockAutomatically_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock Rotation" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumStockRotationSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock Rotation" },
		{ "ClampMin", "5.0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumStockRotationSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock Rotation" },
		{ "ClampMin", "5.0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialStockRotationDelaySeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock Rotation" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pricing_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Pricing" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorWidgetClass_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Per-NPC UI override. Leave blank to use the framework's native tabbed Digimon vendor UI. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-NPC UI override. Leave blank to use the framework's native tabbed Digimon vendor UI." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedStock_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StockGenerationSerial_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextStockRotationServerTimeSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|Stock" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVendorStockChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVendorEnabledChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVendorConfigurationChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVendorTradeCompleted_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonVendorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFDigimonVendorActor constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractionCollision;
	static const UECodeGen_Private::FNamePropertyParams NewProp_VendorId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_VendorDisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_VendorSubtitle;
	static const UECodeGen_Private::FTextPropertyParams NewProp_InteractionPrompt;
	static void NewProp_bVendorEnabled_SetBit(void* Obj)
	{
		((ADMFDigimonVendorActor*)Obj)->bVendorEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVendorEnabled;
	static void NewProp_bAllowBuying_SetBit(void* Obj)
	{
		((ADMFDigimonVendorActor*)Obj)->bAllowBuying = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowBuying;
	static void NewProp_bAllowSelling_SetBit(void* Obj)
	{
		((ADMFDigimonVendorActor*)Obj)->bAllowSelling = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowSelling;
	static void NewProp_bAllowSellingStarterDigimon_SetBit(void* Obj)
	{
		((ADMFDigimonVendorActor*)Obj)->bAllowSellingStarterDigimon = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowSellingStarterDigimon;
	static void NewProp_bRequireAtLeastOnePartyDigimon_SetBit(void* Obj)
	{
		((ADMFDigimonVendorActor*)Obj)->bRequireAtLeastOnePartyDigimon = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireAtLeastOnePartyDigimon;
	static void NewProp_bPreferPurchasedDigimonToBank_SetBit(void* Obj)
	{
		((ADMFDigimonVendorActor*)Obj)->bPreferPurchasedDigimonToBank = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreferPurchasedDigimonToBank;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionCollisionRadius;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InteractionTraceChannel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StockSlots;
	static void NewProp_bAllowDuplicateSpeciesInStock_SetBit(void* Obj)
	{
		((ADMFDigimonVendorActor*)Obj)->bAllowDuplicateSpeciesInStock = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowDuplicateSpeciesInStock;
	static void NewProp_bRefillSoldSlotsImmediately_SetBit(void* Obj)
	{
		((ADMFDigimonVendorActor*)Obj)->bRefillSoldSlotsImmediately = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRefillSoldSlotsImmediately;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesPool_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpeciesPool;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultGenerationRange;
	static void NewProp_bRotateStockAutomatically_SetBit(void* Obj)
	{
		((ADMFDigimonVendorActor*)Obj)->bRotateStockAutomatically = 1;
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
// ********** End Class ADMFDigimonVendorActor constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CalculateDigimonValue"), .Pointer = &ADMFDigimonVendorActor::execCalculateDigimonValue },
		{ .NameUTF8 = UTF8TEXT("GetPlayerSellPrice"), .Pointer = &ADMFDigimonVendorActor::execGetPlayerSellPrice },
		{ .NameUTF8 = UTF8TEXT("GetSecondsUntilStockRotation"), .Pointer = &ADMFDigimonVendorActor::execGetSecondsUntilStockRotation },
		{ .NameUTF8 = UTF8TEXT("GetVendorStock"), .Pointer = &ADMFDigimonVendorActor::execGetVendorStock },
		{ .NameUTF8 = UTF8TEXT("IsPlayerWithinTradeRange"), .Pointer = &ADMFDigimonVendorActor::execIsPlayerWithinTradeRange },
		{ .NameUTF8 = UTF8TEXT("IsVendorEnabled"), .Pointer = &ADMFDigimonVendorActor::execIsVendorEnabled },
		{ .NameUTF8 = UTF8TEXT("OnRep_Configuration"), .Pointer = &ADMFDigimonVendorActor::execOnRep_Configuration },
		{ .NameUTF8 = UTF8TEXT("OnRep_Stock"), .Pointer = &ADMFDigimonVendorActor::execOnRep_Stock },
		{ .NameUTF8 = UTF8TEXT("OnRep_VendorEnabled"), .Pointer = &ADMFDigimonVendorActor::execOnRep_VendorEnabled },
		{ .NameUTF8 = UTF8TEXT("RefreshStockNow"), .Pointer = &ADMFDigimonVendorActor::execRefreshStockNow },
		{ .NameUTF8 = UTF8TEXT("RestartStockRotationSchedule"), .Pointer = &ADMFDigimonVendorActor::execRestartStockRotationSchedule },
		{ .NameUTF8 = UTF8TEXT("SetBuyingEnabled"), .Pointer = &ADMFDigimonVendorActor::execSetBuyingEnabled },
		{ .NameUTF8 = UTF8TEXT("SetPricingSettings"), .Pointer = &ADMFDigimonVendorActor::execSetPricingSettings },
		{ .NameUTF8 = UTF8TEXT("SetSellingEnabled"), .Pointer = &ADMFDigimonVendorActor::execSetSellingEnabled },
		{ .NameUTF8 = UTF8TEXT("SetVendorEnabled"), .Pointer = &ADMFDigimonVendorActor::execSetVendorEnabled },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_BP_OnStockRefreshed, "BP_OnStockRefreshed" }, // f6070b99c53379941955758017dece78e2923c49
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_BP_OnVendorEnabledChanged, "BP_OnVendorEnabledChanged" }, // 3c7f4fa5d2848b224ef0e02a4e62e9735a630121
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_BP_OnVendorTradeCompleted, "BP_OnVendorTradeCompleted" }, // 4998fbe8cc56dc94d7b2da3fdca3de387386044a
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_CalculateDigimonValue, "CalculateDigimonValue" }, // cd4d12bcfbdec7f07627fcb6e5c48a6abb8fbcab
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_GetPlayerSellPrice, "GetPlayerSellPrice" }, // 924bfb7a06388956526f97f1be88bfd3db0ba102
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_GetSecondsUntilStockRotation, "GetSecondsUntilStockRotation" }, // e7fa07d66f48e5e244418a0acbcaf703eb08f122
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_GetVendorStock, "GetVendorStock" }, // 14c706e1dbffd077dff07575c9b60a56aef807b7
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_IsPlayerWithinTradeRange, "IsPlayerWithinTradeRange" }, // 5da791c8382d659f37c2c6d7b468ed1be2907f9d
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_IsVendorEnabled, "IsVendorEnabled" }, // 06ba0ddce422bc89b695f7244e1185aa89cd63e6
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_OnRep_Configuration, "OnRep_Configuration" }, // 8ba02175486cd846754b4d4fd28e497e9e50f7d9
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_OnRep_Stock, "OnRep_Stock" }, // 78cc8e82ea17b32fbbfafbc8dc41c77eb41fbd9e
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_OnRep_VendorEnabled, "OnRep_VendorEnabled" }, // 2a2585ed9defede8320abbf6262e084ded94c71d
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_RefreshStockNow, "RefreshStockNow" }, // 806c7f80960a76a4cd0cccd9f678c614e317f138
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_RestartStockRotationSchedule, "RestartStockRotationSchedule" }, // c1f65ab381ba5ed5470e79e3139a9e3d8e4f8c10
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_SetBuyingEnabled, "SetBuyingEnabled" }, // 7b9f907062b01b1c1a47e6532f880511dadb9ddd
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_SetPricingSettings, "SetPricingSettings" }, // 668d42e7b1f52910fc95dd2607a48ac02c0833be
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_SetSellingEnabled, "SetSellingEnabled" }, // 7a05f39e7e29ac741c6c92efc7a2ce57298cec46
		{ &Z_Construct_UFunction_ADMFDigimonVendorActor_SetVendorEnabled, "SetVendorEnabled" }, // 8bd2b9fd2cd2174015d60d53249af6d1c0195933
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFDigimonVendorActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFDigimonVendorActor Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, SceneRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorMesh = { "VendorMesh", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, VendorMesh), Z_Construct_UClass_USkeletalMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorMesh_MetaData), NewProp_VendorMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InteractionCollision = { "InteractionCollision", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, InteractionCollision), Z_Construct_UClass_USphereComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionCollision_MetaData), NewProp_InteractionCollision_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_VendorId = { "VendorId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, VendorId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorId_MetaData), NewProp_VendorId_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_VendorDisplayName = { "VendorDisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, VendorDisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorDisplayName_MetaData), NewProp_VendorDisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_VendorSubtitle = { "VendorSubtitle", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, VendorSubtitle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorSubtitle_MetaData), NewProp_VendorSubtitle_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_InteractionPrompt = { "InteractionPrompt", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, InteractionPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionPrompt_MetaData), NewProp_InteractionPrompt_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bVendorEnabled = { "bVendorEnabled", "OnRep_VendorEnabled", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonVendorActor), &UHT_STATICS::NewProp_bVendorEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVendorEnabled_MetaData), NewProp_bVendorEnabled_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowBuying = { "bAllowBuying", "OnRep_Configuration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonVendorActor), &UHT_STATICS::NewProp_bAllowBuying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowBuying_MetaData), NewProp_bAllowBuying_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowSelling = { "bAllowSelling", "OnRep_Configuration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonVendorActor), &UHT_STATICS::NewProp_bAllowSelling_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowSelling_MetaData), NewProp_bAllowSelling_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowSellingStarterDigimon = { "bAllowSellingStarterDigimon", "OnRep_Configuration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonVendorActor), &UHT_STATICS::NewProp_bAllowSellingStarterDigimon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowSellingStarterDigimon_MetaData), NewProp_bAllowSellingStarterDigimon_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequireAtLeastOnePartyDigimon = { "bRequireAtLeastOnePartyDigimon", "OnRep_Configuration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonVendorActor), &UHT_STATICS::NewProp_bRequireAtLeastOnePartyDigimon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireAtLeastOnePartyDigimon_MetaData), NewProp_bRequireAtLeastOnePartyDigimon_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPreferPurchasedDigimonToBank = { "bPreferPurchasedDigimonToBank", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonVendorActor), &UHT_STATICS::NewProp_bPreferPurchasedDigimonToBank_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreferPurchasedDigimonToBank_MetaData), NewProp_bPreferPurchasedDigimonToBank_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InteractionRadius = { "InteractionRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, InteractionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionRadius_MetaData), NewProp_InteractionRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InteractionCollisionRadius = { "InteractionCollisionRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, InteractionCollisionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionCollisionRadius_MetaData), NewProp_InteractionCollisionRadius_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InteractionTraceChannel = { "InteractionTraceChannel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, InteractionTraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionTraceChannel_MetaData), NewProp_InteractionTraceChannel_MetaData) }; // 3aff698625c18cc2ccaa87a587b2eac8c50cdec7
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_StockSlots = { "StockSlots", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, StockSlots), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StockSlots_MetaData), NewProp_StockSlots_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowDuplicateSpeciesInStock = { "bAllowDuplicateSpeciesInStock", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonVendorActor), &UHT_STATICS::NewProp_bAllowDuplicateSpeciesInStock_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowDuplicateSpeciesInStock_MetaData), NewProp_bAllowDuplicateSpeciesInStock_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRefillSoldSlotsImmediately = { "bRefillSoldSlotsImmediately", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonVendorActor), &UHT_STATICS::NewProp_bRefillSoldSlotsImmediately_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRefillSoldSlotsImmediately_MetaData), NewProp_bRefillSoldSlotsImmediately_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesPool_Inner = { "SpeciesPool", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry, METADATA_PARAMS(0, nullptr) }; // da2d9614af7ccafa3ff5792e15daf2c8c9d89cb8
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_SpeciesPool = { "SpeciesPool", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, SpeciesPool), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesPool_MetaData), NewProp_SpeciesPool_MetaData) }; // da2d9614af7ccafa3ff5792e15daf2c8c9d89cb8
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DefaultGenerationRange = { "DefaultGenerationRange", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, DefaultGenerationRange), Z_Construct_UScriptStruct_FDMFDigimonVendorGenerationRange, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultGenerationRange_MetaData), NewProp_DefaultGenerationRange_MetaData) }; // ee160f106308908b84487bbb1cb40a8be755d195
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRotateStockAutomatically = { "bRotateStockAutomatically", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFDigimonVendorActor), &UHT_STATICS::NewProp_bRotateStockAutomatically_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRotateStockAutomatically_MetaData), NewProp_bRotateStockAutomatically_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumStockRotationSeconds = { "MinimumStockRotationSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, MinimumStockRotationSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumStockRotationSeconds_MetaData), NewProp_MinimumStockRotationSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumStockRotationSeconds = { "MaximumStockRotationSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, MaximumStockRotationSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumStockRotationSeconds_MetaData), NewProp_MaximumStockRotationSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InitialStockRotationDelaySeconds = { "InitialStockRotationDelaySeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, InitialStockRotationDelaySeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialStockRotationDelaySeconds_MetaData), NewProp_InitialStockRotationDelaySeconds_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Pricing = { "Pricing", "OnRep_Configuration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, Pricing), Z_Construct_UScriptStruct_FDMFDigimonVendorPricingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pricing_MetaData), NewProp_Pricing_MetaData) }; // 1281fa943adc14215a62afdb40d48437a02e0ba5
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_VendorWidgetClass = { "VendorWidgetClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, VendorWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMFDigimonVendorWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorWidgetClass_MetaData), NewProp_VendorWidgetClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReplicatedStock_Inner = { "ReplicatedStock", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFDigimonVendorStockItem, METADATA_PARAMS(0, nullptr) }; // 9cea3b80b98a6bce28df6a536f071c40438e9986
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReplicatedStock = { "ReplicatedStock", "OnRep_Stock", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, ReplicatedStock), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedStock_MetaData), NewProp_ReplicatedStock_MetaData) }; // 9cea3b80b98a6bce28df6a536f071c40438e9986
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_StockGenerationSerial = { "StockGenerationSerial", "OnRep_Stock", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, StockGenerationSerial), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StockGenerationSerial_MetaData), NewProp_StockGenerationSerial_MetaData) };
const UECodeGen_Private::FDoublePropertyParams UHT_STATICS::NewProp_NextStockRotationServerTimeSeconds = { "NextStockRotationServerTimeSeconds", "OnRep_Stock", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Double, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, NextStockRotationServerTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextStockRotationServerTimeSeconds_MetaData), NewProp_NextStockRotationServerTimeSeconds_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVendorStockChanged = { "OnVendorStockChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, OnVendorStockChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorStockChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVendorStockChanged_MetaData), NewProp_OnVendorStockChanged_MetaData) }; // c36d70e5d2b51b5569ae22d269151973a71e063d
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVendorEnabledChanged = { "OnVendorEnabledChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, OnVendorEnabledChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorEnabledChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVendorEnabledChanged_MetaData), NewProp_OnVendorEnabledChanged_MetaData) }; // 72c7d5d0878704374651827bf624f63f20be4d7a
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVendorConfigurationChanged = { "OnVendorConfigurationChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, OnVendorConfigurationChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorConfigurationChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVendorConfigurationChanged_MetaData), NewProp_OnVendorConfigurationChanged_MetaData) }; // a864b0193b884c6c019c0d9bebdee8f0669fcf68
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVendorTradeCompleted = { "OnVendorTradeCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonVendorActor, OnVendorTradeCompleted), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorTradeCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVendorTradeCompleted_MetaData), NewProp_OnVendorTradeCompleted_MetaData) }; // 1c2716d3dbf5d0cb8123754f163564149676cab7
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
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAllowSellingStarterDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequireAtLeastOnePartyDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPreferPurchasedDigimonToBank,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionCollisionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractionTraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockSlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAllowDuplicateSpeciesInStock,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRefillSoldSlotsImmediately,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesPool_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesPool,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultGenerationRange,
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
// ********** End Class ADMFDigimonVendorActor Property Definitions ********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFDigimonVendorActor,
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
static void ADMFDigimonVendorActor_StaticRegisterNativesADMFDigimonVendorActor()
{
	UClass* Class = ADMFDigimonVendorActor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFDigimonVendorActor;
UClass* Z_Construct_UClass_ADMFDigimonVendorActor(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFDigimonVendorActor;
		if (!Z_Registration_Info_UClass_ADMFDigimonVendorActor.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonVendorActor"),
				Z_Registration_Info_UClass_ADMFDigimonVendorActor.InnerSingleton,
				ADMFDigimonVendorActor_StaticRegisterNativesADMFDigimonVendorActor,
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
		return Z_Registration_Info_UClass_ADMFDigimonVendorActor.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFDigimonVendorActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFDigimonVendorActor.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFDigimonVendorActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFDigimonVendorActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_bVendorEnabled(TEXT("bVendorEnabled"));
	static FName Name_bAllowBuying(TEXT("bAllowBuying"));
	static FName Name_bAllowSelling(TEXT("bAllowSelling"));
	static FName Name_bAllowSellingStarterDigimon(TEXT("bAllowSellingStarterDigimon"));
	static FName Name_bRequireAtLeastOnePartyDigimon(TEXT("bRequireAtLeastOnePartyDigimon"));
	static FName Name_Pricing(TEXT("Pricing"));
	static FName Name_ReplicatedStock(TEXT("ReplicatedStock"));
	static FName Name_StockGenerationSerial(TEXT("StockGenerationSerial"));
	static FName Name_NextStockRotationServerTimeSeconds(TEXT("NextStockRotationServerTimeSeconds"));
	const bool bIsValid = true
		&& Name_bVendorEnabled == ClassReps[(int32)ENetFields_Private::bVendorEnabled].Property->GetFName()
		&& Name_bAllowBuying == ClassReps[(int32)ENetFields_Private::bAllowBuying].Property->GetFName()
		&& Name_bAllowSelling == ClassReps[(int32)ENetFields_Private::bAllowSelling].Property->GetFName()
		&& Name_bAllowSellingStarterDigimon == ClassReps[(int32)ENetFields_Private::bAllowSellingStarterDigimon].Property->GetFName()
		&& Name_bRequireAtLeastOnePartyDigimon == ClassReps[(int32)ENetFields_Private::bRequireAtLeastOnePartyDigimon].Property->GetFName()
		&& Name_Pricing == ClassReps[(int32)ENetFields_Private::Pricing].Property->GetFName()
		&& Name_ReplicatedStock == ClassReps[(int32)ENetFields_Private::ReplicatedStock].Property->GetFName()
		&& Name_StockGenerationSerial == ClassReps[(int32)ENetFields_Private::StockGenerationSerial].Property->GetFName()
		&& Name_NextStockRotationServerTimeSeconds == ClassReps[(int32)ENetFields_Private::NextStockRotationServerTimeSeconds].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFDigimonVendorActor"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFDigimonVendorActor);
ADMFDigimonVendorActor::~ADMFDigimonVendorActor() {}
// ********** End Class ADMFDigimonVendorActor *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonVendorActor_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDMFDigimonVendorGenerationRange, Z_Construct_UScriptStruct_FDMFDigimonVendorGenerationRange_Statics::NewStructOps, TEXT("DMFDigimonVendorGenerationRange"),&Z_Registration_Info_UScriptStruct_FDMFDigimonVendorGenerationRange, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonVendorGenerationRange), 3994423056U) },
		{ Z_Construct_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry, Z_Construct_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry_Statics::NewStructOps, TEXT("DMFDigimonVendorSpeciesPoolEntry"),&Z_Registration_Info_UScriptStruct_FDMFDigimonVendorSpeciesPoolEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonVendorSpeciesPoolEntry), 3660420628U) },
		{ Z_Construct_UScriptStruct_FDMFDigimonVendorStageMultipliers, Z_Construct_UScriptStruct_FDMFDigimonVendorStageMultipliers_Statics::NewStructOps, TEXT("DMFDigimonVendorStageMultipliers"),&Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStageMultipliers, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonVendorStageMultipliers), 179274811U) },
		{ Z_Construct_UScriptStruct_FDMFDigimonVendorPricingSettings, Z_Construct_UScriptStruct_FDMFDigimonVendorPricingSettings_Statics::NewStructOps, TEXT("DMFDigimonVendorPricingSettings"),&Z_Registration_Info_UScriptStruct_FDMFDigimonVendorPricingSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonVendorPricingSettings), 310508180U) },
		{ Z_Construct_UScriptStruct_FDMFDigimonVendorValueBreakdown, Z_Construct_UScriptStruct_FDMFDigimonVendorValueBreakdown_Statics::NewStructOps, TEXT("DMFDigimonVendorValueBreakdown"),&Z_Registration_Info_UScriptStruct_FDMFDigimonVendorValueBreakdown, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonVendorValueBreakdown), 2165500505U) },
		{ Z_Construct_UScriptStruct_FDMFDigimonVendorStockItem, Z_Construct_UScriptStruct_FDMFDigimonVendorStockItem_Statics::NewStructOps, TEXT("DMFDigimonVendorStockItem"),&Z_Registration_Info_UScriptStruct_FDMFDigimonVendorStockItem, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonVendorStockItem), 2632596352U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFDigimonVendorActor, TEXT("ADMFDigimonVendorActor"), &Z_Registration_Info_UClass_ADMFDigimonVendorActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFDigimonVendorActor), 1524512441U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonVendorActor_h__Script_DigimonMMOFramework_54b0b8f4b477f19a303bc01d4a98a82fd61705e9{
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
