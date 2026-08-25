// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFWildDigimonSpawner.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFWildDigimonSpawner() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USceneComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USphereComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFWildDigimonSpawner(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWildSpawnEntry(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFWildDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFWildDigimonSpawner(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FDMFWildSpawnRarityWeights ****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFWildSpawnRarityWeights>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFWildSpawnRarityWeights); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tunable rarity weights used by one wild-Digimon spawner. Values are relative weights, not percentages. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tunable rarity weights used by one wild-Digimon spawner. Values are relative weights, not percentages." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Common_MetaData[] = {
		{ "Category", "Rarity" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Uncommon_MetaData[] = {
		{ "Category", "Rarity" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rare_MetaData[] = {
		{ "Category", "Rarity" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Epic_MetaData[] = {
		{ "Category", "Rarity" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Legendary_MetaData[] = {
		{ "Category", "Rarity" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mythic_MetaData[] = {
		{ "Category", "Rarity" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFWildSpawnRarityWeights constinit property declarations ********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Common;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Uncommon;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rare;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Epic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Legendary;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Mythic;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFWildSpawnRarityWeights constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFWildSpawnRarityWeights>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFWildSpawnRarityWeights Property Definitions *******************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Common = { "Common", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnRarityWeights, Common), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Common_MetaData), NewProp_Common_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Uncommon = { "Uncommon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnRarityWeights, Uncommon), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Uncommon_MetaData), NewProp_Uncommon_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Rare = { "Rare", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnRarityWeights, Rare), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rare_MetaData), NewProp_Rare_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Epic = { "Epic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnRarityWeights, Epic), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Epic_MetaData), NewProp_Epic_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Legendary = { "Legendary", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnRarityWeights, Legendary), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Legendary_MetaData), NewProp_Legendary_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Mythic = { "Mythic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnRarityWeights, Mythic), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mythic_MetaData), NewProp_Mythic_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Common,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Uncommon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rare,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Epic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Legendary,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mythic,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFWildSpawnRarityWeights Property Definitions *********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFWildSpawnRarityWeights",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFWildSpawnRarityWeights>(),
	alignof(FDMFWildSpawnRarityWeights),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFWildSpawnRarityWeights;
UScriptStruct* Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFWildSpawnRarityWeights.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFWildSpawnRarityWeights.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFWildSpawnRarityWeights"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFWildSpawnRarityWeights.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFWildSpawnRarityWeights.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFWildSpawnRarityWeights.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFWildSpawnRarityWeights.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFWildSpawnRarityWeights ******************************************

// ********** Begin ScriptStruct FDMFWildSpawnEntry ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFWildSpawnEntry_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFWildSpawnEntry>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFWildSpawnEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** One species/class candidate in a proximity wild-spawn table. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One species/class candidate in a proximity wild-spawn table." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryId_MetaData[] = {
		{ "Category", "Spawn Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stable designer-facing identifier used by Blueprint events and debug output. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stable designer-facing identifier used by Blueprint events and debug output." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Spawn Entry" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Species_MetaData[] = {
		{ "Category", "Spawn Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Species data used to initialize authoritative stats, abilities and rewards. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Species data used to initialize authoritative stats, abilities and rewards." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WildCharacterClass_MetaData[] = {
		{ "Category", "Spawn Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Usually a BP_Wild_<Species> class derived from DMFWildDigimonCharacter with the correct mesh/AnimBP. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Usually a BP_Wild_<Species> class derived from DMFWildDigimonCharacter with the correct mesh/AnimBP." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rarity_MetaData[] = {
		{ "Category", "Spawn Entry|Rarity" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectionWeightMultiplier_MetaData[] = {
		{ "Category", "Spawn Entry|Rarity" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Multiplies the selected rarity tier's base weight. 0 disables selection without removing the entry. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Multiplies the selected rarity tier's base weight. 0 disables selection without removing the entry." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAliveFromEntry_MetaData[] = {
		{ "Category", "Spawn Entry|Population" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** 0 = unlimited within this spawner's total population. Useful for one-at-a-time rare/legendary species. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "0 = unlimited within this spawner's total population. Useful for one-at-a-time rare/legendary species." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumLevel_MetaData[] = {
		{ "Category", "Spawn Entry|Level" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumLevel_MetaData[] = {
		{ "Category", "Spawn Entry|Level" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideAutoBattle_MetaData[] = {
		{ "Category", "Spawn Entry|AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Optional per-entry auto-battle override. When false, the selected Wild Character Blueprint's\n     * own bAutoBattle class default is respected. The spawner's Allow Proactive Auto Battle setting remains\n     * a master gate and can disable autonomous combat for the entire encounter.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional per-entry auto-battle override. When false, the selected Wild Character Blueprint's\nown bAutoBattle class default is respected. The spawner's Allow Proactive Auto Battle setting remains\na master gate and can disable autonomous combat for the entire encounter." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoBattleOverride_MetaData[] = {
		{ "Category", "Spawn Entry|AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Used only when Override Auto Battle is enabled for this entry. */" },
#endif
		{ "EditCondition", "bOverrideAutoBattle" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Used only when Override Auto Battle is enabled for this entry." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideGroundEmergence_MetaData[] = {
		{ "Category", "Spawn Entry|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional per-species emergence tuning for very small/large Digimon meshes. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional per-species emergence tuning for very small/large Digimon meshes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundEmergenceDepthOverride_MetaData[] = {
		{ "Category", "Spawn Entry|Presentation" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bOverrideGroundEmergence" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundEmergenceDurationOverride_MetaData[] = {
		{ "Category", "Spawn Entry|Presentation" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bOverrideGroundEmergence" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFWildSpawnEntry constinit property declarations ****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_EntryId;
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((FDMFWildSpawnEntry*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Species;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WildCharacterClass;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Rarity_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Rarity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SelectionWeightMultiplier;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAliveFromEntry;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumLevel;
	static void NewProp_bOverrideAutoBattle_SetBit(void* Obj)
	{
		((FDMFWildSpawnEntry*)Obj)->bOverrideAutoBattle = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideAutoBattle;
	static void NewProp_bAutoBattleOverride_SetBit(void* Obj)
	{
		((FDMFWildSpawnEntry*)Obj)->bAutoBattleOverride = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoBattleOverride;
	static void NewProp_bOverrideGroundEmergence_SetBit(void* Obj)
	{
		((FDMFWildSpawnEntry*)Obj)->bOverrideGroundEmergence = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideGroundEmergence;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundEmergenceDepthOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundEmergenceDurationOverride;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFWildSpawnEntry constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFWildSpawnEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFWildSpawnEntry Property Definitions ***************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_EntryId = { "EntryId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, EntryId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryId_MetaData), NewProp_EntryId_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFWildSpawnEntry), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Species = { "Species", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, Species), Z_Construct_UClass_UDMFDigimonSpeciesData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Species_MetaData), NewProp_Species_MetaData) };
const UECodeGen_Private::FClassPropertyParams UHT_STATICS::NewProp_WildCharacterClass = { "WildCharacterClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, WildCharacterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ADMFWildDigimonCharacter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WildCharacterClass_MetaData), NewProp_WildCharacterClass_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Rarity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Rarity = { "Rarity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, Rarity), Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rarity_MetaData), NewProp_Rarity_MetaData) }; // 798c32b425717dfa74b06e356544317cdfe76fdd
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SelectionWeightMultiplier = { "SelectionWeightMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, SelectionWeightMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectionWeightMultiplier_MetaData), NewProp_SelectionWeightMultiplier_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxAliveFromEntry = { "MaxAliveFromEntry", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, MaxAliveFromEntry), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAliveFromEntry_MetaData), NewProp_MaxAliveFromEntry_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumLevel = { "MinimumLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, MinimumLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumLevel_MetaData), NewProp_MinimumLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumLevel = { "MaximumLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, MaximumLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumLevel_MetaData), NewProp_MaximumLevel_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bOverrideAutoBattle = { "bOverrideAutoBattle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFWildSpawnEntry), &UHT_STATICS::NewProp_bOverrideAutoBattle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideAutoBattle_MetaData), NewProp_bOverrideAutoBattle_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAutoBattleOverride = { "bAutoBattleOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFWildSpawnEntry), &UHT_STATICS::NewProp_bAutoBattleOverride_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoBattleOverride_MetaData), NewProp_bAutoBattleOverride_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bOverrideGroundEmergence = { "bOverrideGroundEmergence", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFWildSpawnEntry), &UHT_STATICS::NewProp_bOverrideGroundEmergence_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideGroundEmergence_MetaData), NewProp_bOverrideGroundEmergence_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GroundEmergenceDepthOverride = { "GroundEmergenceDepthOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, GroundEmergenceDepthOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundEmergenceDepthOverride_MetaData), NewProp_GroundEmergenceDepthOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GroundEmergenceDurationOverride = { "GroundEmergenceDurationOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildSpawnEntry, GroundEmergenceDurationOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundEmergenceDurationOverride_MetaData), NewProp_GroundEmergenceDurationOverride_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EntryId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Species,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WildCharacterClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rarity_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rarity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectionWeightMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxAliveFromEntry,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bOverrideAutoBattle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAutoBattleOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bOverrideGroundEmergence,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundEmergenceDepthOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundEmergenceDurationOverride,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFWildSpawnEntry Property Definitions *****************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFWildSpawnEntry",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFWildSpawnEntry>(),
	alignof(FDMFWildSpawnEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFWildSpawnEntry;
UScriptStruct* Z_Construct_UScriptStruct_FDMFWildSpawnEntry(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFWildSpawnEntry.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFWildSpawnEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFWildSpawnEntry, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFWildSpawnEntry"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFWildSpawnEntry.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFWildSpawnEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFWildSpawnEntry.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFWildSpawnEntry.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFWildSpawnEntry **************************************************

// ********** Begin Class ADMFWildDigimonSpawner Function BP_OnSpawnerStateChanged *****************
struct DMFWildDigimonSpawner_eventBP_OnSpawnerStateChanged_Parms
{
	bool bIsActive;
	int32 AliveCount;
	int32 TargetPopulation;
};
static FName NAME_ADMFWildDigimonSpawner_BP_OnSpawnerStateChanged = FName(TEXT("BP_OnSpawnerStateChanged"));
void ADMFWildDigimonSpawner::BP_OnSpawnerStateChanged(bool bIsActive, int32 AliveCount, int32 TargetPopulation)
{
	DMFWildDigimonSpawner_eventBP_OnSpawnerStateChanged_Parms Parms;
	Parms.bIsActive=bIsActive ? true : false;
	Parms.AliveCount=AliveCount;
	Parms.TargetPopulation=TargetPopulation;
	UFunction* Func = FindFunctionChecked(NAME_ADMFWildDigimonSpawner_BP_OnSpawnerStateChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_BP_OnSpawnerStateChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnSpawnerStateChanged constinit property declarations **************
	static void NewProp_bIsActive_SetBit(void* Obj)
	{
		((DMFWildDigimonSpawner_eventBP_OnSpawnerStateChanged_Parms*)Obj)->bIsActive = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActive;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AliveCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TargetPopulation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnSpawnerStateChanged constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnSpawnerStateChanged Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsActive = { "bIsActive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWildDigimonSpawner_eventBP_OnSpawnerStateChanged_Parms), &UHT_STATICS::NewProp_bIsActive_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_AliveCount = { "AliveCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventBP_OnSpawnerStateChanged_Parms, AliveCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_TargetPopulation = { "TargetPopulation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventBP_OnSpawnerStateChanged_Parms, TargetPopulation), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsActive,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AliveCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetPopulation,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnSpawnerStateChanged Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "BP_OnSpawnerStateChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFWildDigimonSpawner_eventBP_OnSpawnerStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFWildDigimonSpawner_eventBP_OnSpawnerStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_BP_OnSpawnerStateChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFWildDigimonSpawner Function BP_OnSpawnerStateChanged *******************

// ********** Begin Class ADMFWildDigimonSpawner Function BP_OnWildDigimonSpawned ******************
struct DMFWildDigimonSpawner_eventBP_OnWildDigimonSpawned_Parms
{
	ADMFWildDigimonCharacter* SpawnedDigimon;
	FName SpawnEntryId;
	EDMFWildSpawnRarity Rarity;
};
static FName NAME_ADMFWildDigimonSpawner_BP_OnWildDigimonSpawned = FName(TEXT("BP_OnWildDigimonSpawned"));
void ADMFWildDigimonSpawner::BP_OnWildDigimonSpawned(ADMFWildDigimonCharacter* SpawnedDigimon, FName SpawnEntryId, EDMFWildSpawnRarity Rarity)
{
	DMFWildDigimonSpawner_eventBP_OnWildDigimonSpawned_Parms Parms;
	Parms.SpawnedDigimon=SpawnedDigimon;
	Parms.SpawnEntryId=SpawnEntryId;
	Parms.Rarity=Rarity;
	UFunction* Func = FindFunctionChecked(NAME_ADMFWildDigimonSpawner_BP_OnWildDigimonSpawned);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_BP_OnWildDigimonSpawned_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnWildDigimonSpawned constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedDigimon;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SpawnEntryId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Rarity_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Rarity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnWildDigimonSpawned constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnWildDigimonSpawned Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpawnedDigimon = { "SpawnedDigimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventBP_OnWildDigimonSpawned_Parms, SpawnedDigimon), Z_Construct_UClass_ADMFWildDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_SpawnEntryId = { "SpawnEntryId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventBP_OnWildDigimonSpawned_Parms, SpawnEntryId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Rarity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Rarity = { "Rarity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventBP_OnWildDigimonSpawned_Parms, Rarity), Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity, METADATA_PARAMS(0, nullptr) }; // 798c32b425717dfa74b06e356544317cdfe76fdd
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnedDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnEntryId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rarity_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rarity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnWildDigimonSpawned Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "BP_OnWildDigimonSpawned", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFWildDigimonSpawner_eventBP_OnWildDigimonSpawned_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFWildDigimonSpawner_eventBP_OnWildDigimonSpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_BP_OnWildDigimonSpawned(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFWildDigimonSpawner Function BP_OnWildDigimonSpawned ********************

// ********** Begin Class ADMFWildDigimonSpawner Function ForceActivateSpawner *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_ForceActivateSpawner_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Forces activation/population without waiting for proximity. Useful for scripted encounters and testing. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Forces activation/population without waiting for proximity. Useful for scripted encounters and testing." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ForceActivateSpawner constinit property declarations ******************
// ********** End Function ForceActivateSpawner constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "ForceActivateSpawner", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_ForceActivateSpawner(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execForceActivateSpawner)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ForceActivateSpawner();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function ForceActivateSpawner ***********************

// ********** Begin Class ADMFWildDigimonSpawner Function ForceDeactivateSpawner *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_ForceDeactivateSpawner_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ForceDeactivateSpawner constinit property declarations ****************
// ********** End Function ForceDeactivateSpawner constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "ForceDeactivateSpawner", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_ForceDeactivateSpawner(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execForceDeactivateSpawner)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ForceDeactivateSpawner();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function ForceDeactivateSpawner *********************

// ********** Begin Class ADMFWildDigimonSpawner Function GetAliveSpawnCount ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_GetAliveSpawnCount_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonSpawner_eventGetAliveSpawnCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAliveSpawnCount constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAliveSpawnCount constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAliveSpawnCount Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventGetAliveSpawnCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAliveSpawnCount Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "GetAliveSpawnCount", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonSpawner_eventGetAliveSpawnCount_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonSpawner_eventGetAliveSpawnCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_GetAliveSpawnCount(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execGetAliveSpawnCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetAliveSpawnCount();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function GetAliveSpawnCount *************************

// ********** Begin Class ADMFWildDigimonSpawner Function GetTargetPopulation **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_GetTargetPopulation_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonSpawner_eventGetTargetPopulation_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTargetPopulation constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTargetPopulation constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTargetPopulation Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventGetTargetPopulation_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetTargetPopulation Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "GetTargetPopulation", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonSpawner_eventGetTargetPopulation_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonSpawner_eventGetTargetPopulation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_GetTargetPopulation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execGetTargetPopulation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetTargetPopulation();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function GetTargetPopulation ************************

// ********** Begin Class ADMFWildDigimonSpawner Function HandleManagedWildDefeated ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_HandleManagedWildDefeated_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonSpawner_eventHandleManagedWildDefeated_Parms
	{
		ADMFDigimonCharacter* DefeatedDigimon;
		ADMFDigimonCharacter* Killer;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleManagedWildDefeated constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefeatedDigimon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Killer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleManagedWildDefeated constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleManagedWildDefeated Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DefeatedDigimon = { "DefeatedDigimon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventHandleManagedWildDefeated_Parms, DefeatedDigimon), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Killer = { "Killer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventHandleManagedWildDefeated_Parms, Killer), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefeatedDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Killer,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleManagedWildDefeated Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "HandleManagedWildDefeated", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonSpawner_eventHandleManagedWildDefeated_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonSpawner_eventHandleManagedWildDefeated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_HandleManagedWildDefeated(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execHandleManagedWildDefeated)
{
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_DefeatedDigimon);
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_Killer);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleManagedWildDefeated(Z_Param_DefeatedDigimon,Z_Param_Killer);
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function HandleManagedWildDefeated ******************

// ********** Begin Class ADMFWildDigimonSpawner Function HandleManagedWildDestroyed ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_HandleManagedWildDestroyed_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonSpawner_eventHandleManagedWildDestroyed_Parms
	{
		AActor* DestroyedActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleManagedWildDestroyed constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DestroyedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleManagedWildDestroyed constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleManagedWildDestroyed Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DestroyedActor = { "DestroyedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventHandleManagedWildDestroyed_Parms, DestroyedActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DestroyedActor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleManagedWildDestroyed Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "HandleManagedWildDestroyed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonSpawner_eventHandleManagedWildDestroyed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonSpawner_eventHandleManagedWildDestroyed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_HandleManagedWildDestroyed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execHandleManagedWildDestroyed)
{
	P_GET_OBJECT(AActor,Z_Param_DestroyedActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleManagedWildDestroyed(Z_Param_DestroyedActor);
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function HandleManagedWildDestroyed *****************

// ********** Begin Class ADMFWildDigimonSpawner Function IsSpawnerActive **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_IsSpawnerActive_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonSpawner_eventIsSpawnerActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsSpawnerActive constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFWildDigimonSpawner_eventIsSpawnerActive_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSpawnerActive constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSpawnerActive Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWildDigimonSpawner_eventIsSpawnerActive_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsSpawnerActive Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "IsSpawnerActive", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonSpawner_eventIsSpawnerActive_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonSpawner_eventIsSpawnerActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_IsSpawnerActive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execIsSpawnerActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSpawnerActive();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function IsSpawnerActive ****************************

// ********** Begin Class ADMFWildDigimonSpawner Function OnRep_SpawnerState ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_OnRep_SpawnerState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_SpawnerState constinit property declarations ********************
// ********** End Function OnRep_SpawnerState constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "OnRep_SpawnerState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_OnRep_SpawnerState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execOnRep_SpawnerState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_SpawnerState();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function OnRep_SpawnerState *************************

// ********** Begin Class ADMFWildDigimonSpawner Function RefreshSpawnerNow ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_RefreshSpawnerNow_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-runs proximity logic immediately on the authority. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-runs proximity logic immediately on the authority." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshSpawnerNow constinit property declarations *********************
// ********** End Function RefreshSpawnerNow constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "RefreshSpawnerNow", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_RefreshSpawnerNow(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execRefreshSpawnerNow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshSpawnerNow();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function RefreshSpawnerNow **************************

// ********** Begin Class ADMFWildDigimonSpawner Function SpawnOneWildDigimon **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonSpawner_SpawnOneWildDigimon_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonSpawner_eventSpawnOneWildDigimon_Parms
	{
		ADMFWildDigimonCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Immediately attempts one authoritative weighted spawn if population/caps allow it. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Immediately attempts one authoritative weighted spawn if population/caps allow it." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SpawnOneWildDigimon constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SpawnOneWildDigimon constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SpawnOneWildDigimon Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonSpawner_eventSpawnOneWildDigimon_Parms, ReturnValue), Z_Construct_UClass_ADMFWildDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SpawnOneWildDigimon Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonSpawner, nullptr, "SpawnOneWildDigimon", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonSpawner_eventSpawnOneWildDigimon_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonSpawner_eventSpawnOneWildDigimon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonSpawner_SpawnOneWildDigimon(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonSpawner::execSpawnOneWildDigimon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFWildDigimonCharacter**)Z_Param__Result=P_THIS->SpawnOneWildDigimon();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonSpawner Function SpawnOneWildDigimon ************************

// ********** Begin Class ADMFWildDigimonSpawner ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFWildDigimonSpawner_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server-authoritative, Blueprint-derivable proximity spawner for MMO wild Digimon populations.\n *\n * The server alone activates/deactivates the spawner, rolls population, rarity/species and level,\n * finds navigable ground, spawns replicated wild actors and schedules replacements after defeat.\n * Clients receive the replicated wild actors plus synchronized ground-emergence presentation.\n */" },
#endif
		{ "IncludePath", "Game/DMFWildDigimonSpawner.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-authoritative, Blueprint-derivable proximity spawner for MMO wild Digimon populations.\n\nThe server alone activates/deactivates the spawner, rolls population, rarity/species and level,\nfinds navigable ground, spawns replicated wild actors and schedules replacements after defeat.\nClients receive the replicated wild actors plus synchronized ground-emergence presentation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnAreaPreview_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Editor-only style radius preview; collision is disabled and it is hidden during play. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editor-only style radius preview; collision is disabled and it is hidden during play." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSpawnerEnabled_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Activation" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumNearbyPlayers_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Activation" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** At least this many player pawns must be within Activation Radius before population is created. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "At least this many player pawns must be within Activation Radius before population is created." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Activation" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeactivationRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Activation" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hysteresis radius. Should be >= ActivationRadius so edge movement does not constantly spawn/despawn. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hysteresis radius. Should be >= ActivationRadius so edge movement does not constantly spawn/despawn." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProximityCheckInterval_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Activation" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeactivationGracePeriod_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Activation" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Players must remain outside Deactivation Radius for this long before the population unloads. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Players must remain outside Deactivation Radius for this long before the population unloads." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUse2DPlayerDistance_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Activation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Uses XY distance for streaming-style proximity, avoiding cliffs/floors changing activation unexpectedly. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Uses XY distance for streaming-style proximity, avoiding cliffs/floors changing activation unexpectedly." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumSpawnCount_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Population" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumSpawnCount_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Population" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PopulationSpawnInterval_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Population" },
		{ "ClampMin", "0.05" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Staggers initial/replacement actor creation instead of spawning a large population in one frame. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Staggers initial/replacement actor creation instead of spawning a large population in one frame." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumRespawnDelay_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Population" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumRespawnDelay_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Population" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefeatedDespawnDelay_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Population" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time a defeated Digimon remains for death presentation before being destroyed. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time a defeated Digimon remains for death presentation before being destroyed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Spawn Area" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumSpawnDistanceFromPlayers_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Spawn Area" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Prevents a new Digimon emerging directly underneath a nearby player. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Prevents a new Digimon emerging directly underneath a nearby player." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxPlacementAttemptsPerSpawn_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Spawn Area" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundTraceHeight_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Grounding" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundTraceDepth_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Grounding" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundTraceChannel_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Grounding" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireNavigableSpawn_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Grounding" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NavigationProjectionExtent_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Grounding" },
		{ "EditCondition", "bRequireNavigableSpawn" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroundOffset_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Grounding" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseGroundEmergence_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Emergence" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundEmergenceDepth_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Emergence" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bUseGroundEmergence" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundEmergenceDuration_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Emergence" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bUseGroundEmergence" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseGroundDespawnWhenInactive_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Emergence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional polished unload: the replicated mesh sinks before the server destroys the actor. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional polished unload: the replicated mesh sinks before the server destroys the actor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundDespawnDuration_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Emergence" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bUseGroundDespawnWhenInactive" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableAutoBattle_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Master gate for PROACTIVE autonomous combat. False means spawned wild Digimon will not scan for\n     * or initiate combat with nearby Digimon. Retaliation after being attacked is controlled separately.\n     */" },
#endif
		{ "DisplayName", "Allow Proactive Auto Battle" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master gate for PROACTIVE autonomous combat. False means spawned wild Digimon will not scan for\nor initiate combat with nearby Digimon. Retaliation after being attacked is controlled separately." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableRetaliation_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Master gate for defensive retaliation. Recommended MMO default is true: wild Digimon remain\n     * peaceful until attacked, then fight the aggressor within their leash.\n     */" },
#endif
		{ "DisplayName", "Allow Retaliation When Attacked" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master gate for defensive retaliation. Recommended MMO default is true: wild Digimon remain\npeaceful until attacked, then fight the aggressor within their leash." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AggroRange_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|AI" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeashRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|AI" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hard combat/home leash around each Digimon's individual spawn point. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hard combat/home leash around each Digimon's individual spawn point." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WildCombatTeamId_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|AI" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableFreeRoaming_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Roaming" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoamRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Roaming" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Idle roaming stays inside this radius around the individual Digimon's spawn point. */" },
#endif
		{ "EditCondition", "bEnableFreeRoaming" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Idle roaming stays inside this radius around the individual Digimon's spawn point." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumRoamDelay_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Roaming" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bEnableFreeRoaming" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumRoamDelay_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Roaming" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bEnableFreeRoaming" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoamAcceptanceRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Roaming" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableFreeRoaming" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RarityWeights_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Rarity" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnEntries_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Spawn Table" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSpawnerActive_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Runtime" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedAliveCount_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Runtime" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedTargetPopulation_MetaData[] = {
		{ "Category", "Digimon MMO|Wild Spawner|Runtime" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonSpawner.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFWildDigimonSpawner constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnAreaPreview;
	static void NewProp_bSpawnerEnabled_SetBit(void* Obj)
	{
		((ADMFWildDigimonSpawner*)Obj)->bSpawnerEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSpawnerEnabled;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumNearbyPlayers;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActivationRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeactivationRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProximityCheckInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeactivationGracePeriod;
	static void NewProp_bUse2DPlayerDistance_SetBit(void* Obj)
	{
		((ADMFWildDigimonSpawner*)Obj)->bUse2DPlayerDistance = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUse2DPlayerDistance;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumSpawnCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumSpawnCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PopulationSpawnInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumRespawnDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumRespawnDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefeatedDespawnDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumSpawnDistanceFromPlayers;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxPlacementAttemptsPerSpawn;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundTraceHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundTraceDepth;
	static const UECodeGen_Private::FBytePropertyParams NewProp_GroundTraceChannel;
	static void NewProp_bRequireNavigableSpawn_SetBit(void* Obj)
	{
		((ADMFWildDigimonSpawner*)Obj)->bRequireNavigableSpawn = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireNavigableSpawn;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NavigationProjectionExtent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnGroundOffset;
	static void NewProp_bUseGroundEmergence_SetBit(void* Obj)
	{
		((ADMFWildDigimonSpawner*)Obj)->bUseGroundEmergence = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseGroundEmergence;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundEmergenceDepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundEmergenceDuration;
	static void NewProp_bUseGroundDespawnWhenInactive_SetBit(void* Obj)
	{
		((ADMFWildDigimonSpawner*)Obj)->bUseGroundDespawnWhenInactive = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseGroundDespawnWhenInactive;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundDespawnDuration;
	static void NewProp_bEnableAutoBattle_SetBit(void* Obj)
	{
		((ADMFWildDigimonSpawner*)Obj)->bEnableAutoBattle = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableAutoBattle;
	static void NewProp_bEnableRetaliation_SetBit(void* Obj)
	{
		((ADMFWildDigimonSpawner*)Obj)->bEnableRetaliation = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableRetaliation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AggroRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LeashRadius;
	static const UECodeGen_Private::FNamePropertyParams NewProp_WildCombatTeamId;
	static void NewProp_bEnableFreeRoaming_SetBit(void* Obj)
	{
		((ADMFWildDigimonSpawner*)Obj)->bEnableFreeRoaming = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableFreeRoaming;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RoamRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumRoamDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumRoamDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RoamAcceptanceRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RarityWeights;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnEntries_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpawnEntries;
	static void NewProp_bSpawnerActive_SetBit(void* Obj)
	{
		((ADMFWildDigimonSpawner*)Obj)->bSpawnerActive = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSpawnerActive;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReplicatedAliveCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReplicatedTargetPopulation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFWildDigimonSpawner constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ForceActivateSpawner"), .Pointer = &ADMFWildDigimonSpawner::execForceActivateSpawner },
		{ .NameUTF8 = UTF8TEXT("ForceDeactivateSpawner"), .Pointer = &ADMFWildDigimonSpawner::execForceDeactivateSpawner },
		{ .NameUTF8 = UTF8TEXT("GetAliveSpawnCount"), .Pointer = &ADMFWildDigimonSpawner::execGetAliveSpawnCount },
		{ .NameUTF8 = UTF8TEXT("GetTargetPopulation"), .Pointer = &ADMFWildDigimonSpawner::execGetTargetPopulation },
		{ .NameUTF8 = UTF8TEXT("HandleManagedWildDefeated"), .Pointer = &ADMFWildDigimonSpawner::execHandleManagedWildDefeated },
		{ .NameUTF8 = UTF8TEXT("HandleManagedWildDestroyed"), .Pointer = &ADMFWildDigimonSpawner::execHandleManagedWildDestroyed },
		{ .NameUTF8 = UTF8TEXT("IsSpawnerActive"), .Pointer = &ADMFWildDigimonSpawner::execIsSpawnerActive },
		{ .NameUTF8 = UTF8TEXT("OnRep_SpawnerState"), .Pointer = &ADMFWildDigimonSpawner::execOnRep_SpawnerState },
		{ .NameUTF8 = UTF8TEXT("RefreshSpawnerNow"), .Pointer = &ADMFWildDigimonSpawner::execRefreshSpawnerNow },
		{ .NameUTF8 = UTF8TEXT("SpawnOneWildDigimon"), .Pointer = &ADMFWildDigimonSpawner::execSpawnOneWildDigimon },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_BP_OnSpawnerStateChanged, "BP_OnSpawnerStateChanged" }, // 4024cc4ca3778ff36819129425724cd7397fca5d
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_BP_OnWildDigimonSpawned, "BP_OnWildDigimonSpawned" }, // 12314f5f4c223c4c7f7dc6eda50d6479c66d890e
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_ForceActivateSpawner, "ForceActivateSpawner" }, // 2c476f42827977eac48ae3a5b174b913990d7152
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_ForceDeactivateSpawner, "ForceDeactivateSpawner" }, // 0e846015ccf26b30edaf8f2bb8b3408b9fda0e18
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_GetAliveSpawnCount, "GetAliveSpawnCount" }, // f0a22c7cff2a6f6849ef5b8f61b8597c44ad453d
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_GetTargetPopulation, "GetTargetPopulation" }, // 00b51d3e94c818b7b4a1c418b9f082be4eb2df65
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_HandleManagedWildDefeated, "HandleManagedWildDefeated" }, // 0131d7ae236f1f58815ec933d98286c7e1befdca
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_HandleManagedWildDestroyed, "HandleManagedWildDestroyed" }, // 5dc8cb302df02eb9be5ccd7ebba837a5691149c7
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_IsSpawnerActive, "IsSpawnerActive" }, // da07ed55daff3d375230f8e5b530f16c9ae71597
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_OnRep_SpawnerState, "OnRep_SpawnerState" }, // 37e8c0b15fc53deb76520bbc7b90249971077adc
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_RefreshSpawnerNow, "RefreshSpawnerNow" }, // cd417045b7da7b58cb46013408b50c18996354fe
		{ &Z_Construct_UFunction_ADMFWildDigimonSpawner_SpawnOneWildDigimon, "SpawnOneWildDigimon" }, // d4fc8204b87c1e19aa7f43ddc2fda5daaa888576
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFWildDigimonSpawner>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFWildDigimonSpawner Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, SceneRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpawnAreaPreview = { "SpawnAreaPreview", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, SpawnAreaPreview), Z_Construct_UClass_USphereComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnAreaPreview_MetaData), NewProp_SpawnAreaPreview_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSpawnerEnabled = { "bSpawnerEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonSpawner), &UHT_STATICS::NewProp_bSpawnerEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSpawnerEnabled_MetaData), NewProp_bSpawnerEnabled_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumNearbyPlayers = { "MinimumNearbyPlayers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, MinimumNearbyPlayers), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumNearbyPlayers_MetaData), NewProp_MinimumNearbyPlayers_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ActivationRadius = { "ActivationRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, ActivationRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationRadius_MetaData), NewProp_ActivationRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DeactivationRadius = { "DeactivationRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, DeactivationRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeactivationRadius_MetaData), NewProp_DeactivationRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ProximityCheckInterval = { "ProximityCheckInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, ProximityCheckInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProximityCheckInterval_MetaData), NewProp_ProximityCheckInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DeactivationGracePeriod = { "DeactivationGracePeriod", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, DeactivationGracePeriod), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeactivationGracePeriod_MetaData), NewProp_DeactivationGracePeriod_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUse2DPlayerDistance = { "bUse2DPlayerDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonSpawner), &UHT_STATICS::NewProp_bUse2DPlayerDistance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUse2DPlayerDistance_MetaData), NewProp_bUse2DPlayerDistance_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumSpawnCount = { "MinimumSpawnCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, MinimumSpawnCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumSpawnCount_MetaData), NewProp_MinimumSpawnCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumSpawnCount = { "MaximumSpawnCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, MaximumSpawnCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumSpawnCount_MetaData), NewProp_MaximumSpawnCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PopulationSpawnInterval = { "PopulationSpawnInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, PopulationSpawnInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PopulationSpawnInterval_MetaData), NewProp_PopulationSpawnInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumRespawnDelay = { "MinimumRespawnDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, MinimumRespawnDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumRespawnDelay_MetaData), NewProp_MinimumRespawnDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumRespawnDelay = { "MaximumRespawnDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, MaximumRespawnDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumRespawnDelay_MetaData), NewProp_MaximumRespawnDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DefeatedDespawnDelay = { "DefeatedDespawnDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, DefeatedDespawnDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefeatedDespawnDelay_MetaData), NewProp_DefeatedDespawnDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SpawnRadius = { "SpawnRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, SpawnRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnRadius_MetaData), NewProp_SpawnRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumSpawnDistanceFromPlayers = { "MinimumSpawnDistanceFromPlayers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, MinimumSpawnDistanceFromPlayers), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumSpawnDistanceFromPlayers_MetaData), NewProp_MinimumSpawnDistanceFromPlayers_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxPlacementAttemptsPerSpawn = { "MaxPlacementAttemptsPerSpawn", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, MaxPlacementAttemptsPerSpawn), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxPlacementAttemptsPerSpawn_MetaData), NewProp_MaxPlacementAttemptsPerSpawn_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GroundTraceHeight = { "GroundTraceHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, GroundTraceHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundTraceHeight_MetaData), NewProp_GroundTraceHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GroundTraceDepth = { "GroundTraceDepth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, GroundTraceDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundTraceDepth_MetaData), NewProp_GroundTraceDepth_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_GroundTraceChannel = { "GroundTraceChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, GroundTraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundTraceChannel_MetaData), NewProp_GroundTraceChannel_MetaData) }; // 3aff698625c18cc2ccaa87a587b2eac8c50cdec7
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequireNavigableSpawn = { "bRequireNavigableSpawn", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonSpawner), &UHT_STATICS::NewProp_bRequireNavigableSpawn_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireNavigableSpawn_MetaData), NewProp_bRequireNavigableSpawn_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NavigationProjectionExtent = { "NavigationProjectionExtent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, NavigationProjectionExtent), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NavigationProjectionExtent_MetaData), NewProp_NavigationProjectionExtent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SpawnGroundOffset = { "SpawnGroundOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, SpawnGroundOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroundOffset_MetaData), NewProp_SpawnGroundOffset_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUseGroundEmergence = { "bUseGroundEmergence", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonSpawner), &UHT_STATICS::NewProp_bUseGroundEmergence_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseGroundEmergence_MetaData), NewProp_bUseGroundEmergence_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GroundEmergenceDepth = { "GroundEmergenceDepth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, GroundEmergenceDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundEmergenceDepth_MetaData), NewProp_GroundEmergenceDepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GroundEmergenceDuration = { "GroundEmergenceDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, GroundEmergenceDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundEmergenceDuration_MetaData), NewProp_GroundEmergenceDuration_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUseGroundDespawnWhenInactive = { "bUseGroundDespawnWhenInactive", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonSpawner), &UHT_STATICS::NewProp_bUseGroundDespawnWhenInactive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseGroundDespawnWhenInactive_MetaData), NewProp_bUseGroundDespawnWhenInactive_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GroundDespawnDuration = { "GroundDespawnDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, GroundDespawnDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundDespawnDuration_MetaData), NewProp_GroundDespawnDuration_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableAutoBattle = { "bEnableAutoBattle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonSpawner), &UHT_STATICS::NewProp_bEnableAutoBattle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableAutoBattle_MetaData), NewProp_bEnableAutoBattle_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableRetaliation = { "bEnableRetaliation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonSpawner), &UHT_STATICS::NewProp_bEnableRetaliation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableRetaliation_MetaData), NewProp_bEnableRetaliation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AggroRange = { "AggroRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, AggroRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AggroRange_MetaData), NewProp_AggroRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LeashRadius = { "LeashRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, LeashRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeashRadius_MetaData), NewProp_LeashRadius_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_WildCombatTeamId = { "WildCombatTeamId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, WildCombatTeamId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WildCombatTeamId_MetaData), NewProp_WildCombatTeamId_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableFreeRoaming = { "bEnableFreeRoaming", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonSpawner), &UHT_STATICS::NewProp_bEnableFreeRoaming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableFreeRoaming_MetaData), NewProp_bEnableFreeRoaming_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_RoamRadius = { "RoamRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, RoamRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoamRadius_MetaData), NewProp_RoamRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumRoamDelay = { "MinimumRoamDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, MinimumRoamDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumRoamDelay_MetaData), NewProp_MinimumRoamDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumRoamDelay = { "MaximumRoamDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, MaximumRoamDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumRoamDelay_MetaData), NewProp_MaximumRoamDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_RoamAcceptanceRadius = { "RoamAcceptanceRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, RoamAcceptanceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoamAcceptanceRadius_MetaData), NewProp_RoamAcceptanceRadius_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_RarityWeights = { "RarityWeights", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, RarityWeights), Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RarityWeights_MetaData), NewProp_RarityWeights_MetaData) }; // a4502800758d998119469d6bc5cba1cee4834028
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpawnEntries_Inner = { "SpawnEntries", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFWildSpawnEntry, METADATA_PARAMS(0, nullptr) }; // 1630f3cac08d5f9ff38fca246a8bb26c91c85c1f
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_SpawnEntries = { "SpawnEntries", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, SpawnEntries), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnEntries_MetaData), NewProp_SpawnEntries_MetaData) }; // 1630f3cac08d5f9ff38fca246a8bb26c91c85c1f
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSpawnerActive = { "bSpawnerActive", "OnRep_SpawnerState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonSpawner), &UHT_STATICS::NewProp_bSpawnerActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSpawnerActive_MetaData), NewProp_bSpawnerActive_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReplicatedAliveCount = { "ReplicatedAliveCount", "OnRep_SpawnerState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, ReplicatedAliveCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedAliveCount_MetaData), NewProp_ReplicatedAliveCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReplicatedTargetPopulation = { "ReplicatedTargetPopulation", "OnRep_SpawnerState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonSpawner, ReplicatedTargetPopulation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedTargetPopulation_MetaData), NewProp_ReplicatedTargetPopulation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnAreaPreview,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSpawnerEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumNearbyPlayers,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActivationRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DeactivationRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProximityCheckInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DeactivationGracePeriod,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUse2DPlayerDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumSpawnCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumSpawnCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PopulationSpawnInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumRespawnDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumRespawnDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefeatedDespawnDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumSpawnDistanceFromPlayers,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxPlacementAttemptsPerSpawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundTraceHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundTraceDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundTraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequireNavigableSpawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NavigationProjectionExtent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnGroundOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUseGroundEmergence,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundEmergenceDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundEmergenceDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUseGroundDespawnWhenInactive,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundDespawnDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableAutoBattle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableRetaliation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AggroRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LeashRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WildCombatTeamId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableFreeRoaming,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RoamRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumRoamDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumRoamDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RoamAcceptanceRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RarityWeights,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnEntries_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnEntries,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSpawnerActive,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedAliveCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReplicatedTargetPopulation,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFWildDigimonSpawner Property Definitions ********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFWildDigimonSpawner,
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
static void ADMFWildDigimonSpawner_StaticRegisterNativesADMFWildDigimonSpawner()
{
	UClass* Class = ADMFWildDigimonSpawner::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFWildDigimonSpawner;
UClass* Z_Construct_UClass_ADMFWildDigimonSpawner(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFWildDigimonSpawner;
		if (!Z_Registration_Info_UClass_ADMFWildDigimonSpawner.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFWildDigimonSpawner"),
				Z_Registration_Info_UClass_ADMFWildDigimonSpawner.InnerSingleton,
				ADMFWildDigimonSpawner_StaticRegisterNativesADMFWildDigimonSpawner,
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
		return Z_Registration_Info_UClass_ADMFWildDigimonSpawner.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFWildDigimonSpawner.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFWildDigimonSpawner.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFWildDigimonSpawner.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFWildDigimonSpawner::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_bSpawnerActive(TEXT("bSpawnerActive"));
	static FName Name_ReplicatedAliveCount(TEXT("ReplicatedAliveCount"));
	static FName Name_ReplicatedTargetPopulation(TEXT("ReplicatedTargetPopulation"));
	const bool bIsValid = true
		&& Name_bSpawnerActive == ClassReps[(int32)ENetFields_Private::bSpawnerActive].Property->GetFName()
		&& Name_ReplicatedAliveCount == ClassReps[(int32)ENetFields_Private::ReplicatedAliveCount].Property->GetFName()
		&& Name_ReplicatedTargetPopulation == ClassReps[(int32)ENetFields_Private::ReplicatedTargetPopulation].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFWildDigimonSpawner"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFWildDigimonSpawner);
ADMFWildDigimonSpawner::~ADMFWildDigimonSpawner() {}
// ********** End Class ADMFWildDigimonSpawner *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights, Z_Construct_UScriptStruct_FDMFWildSpawnRarityWeights_Statics::NewStructOps, TEXT("DMFWildSpawnRarityWeights"),&Z_Registration_Info_UScriptStruct_FDMFWildSpawnRarityWeights, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFWildSpawnRarityWeights), 2756716544U) },
		{ Z_Construct_UScriptStruct_FDMFWildSpawnEntry, Z_Construct_UScriptStruct_FDMFWildSpawnEntry_Statics::NewStructOps, TEXT("DMFWildSpawnEntry"),&Z_Registration_Info_UScriptStruct_FDMFWildSpawnEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFWildSpawnEntry), 372306890U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFWildDigimonSpawner, TEXT("ADMFWildDigimonSpawner"), &Z_Registration_Info_UClass_ADMFWildDigimonSpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFWildDigimonSpawner), 2911576359U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonSpawner_h__Script_DigimonMMOFramework_52a1bc8dc13caad14a446b52c2c46226526d7996{
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
