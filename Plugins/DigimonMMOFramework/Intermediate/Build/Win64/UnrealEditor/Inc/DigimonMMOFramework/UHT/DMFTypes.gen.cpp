// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DMFTypes.h"
#include "Net/Serialization/FastArraySerializerImplementation.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
NETCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFastArraySerializer(ETypeConstructPhase);
NETCORE_API UScriptStruct* Z_Construct_UScriptStruct_FFastArraySerializerItem(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFAbilityCooldownState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFAccountRecord(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFBattleReward(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonCareState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonInstance(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonStats(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigivolutionEvaluation(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFPlayerWorldLocationState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFReplicatedDigimonEntry(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFReplicatedDigimonList(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFScanDataEntry(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWorldChatMessage(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDamageScaling(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttribute(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttributeStat(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonElement(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerInteractionType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFRankedTier(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFWorldChatMessageType(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EDMFDigimonStage **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFDigimonStage>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Armor.Name", "EDMFDigimonStage::Armor" },
		{ "BabyI.DisplayName", "Fresh" },
		{ "BabyI.Name", "EDMFDigimonStage::BabyI" },
		{ "BabyII.DisplayName", "In-Training" },
		{ "BabyII.Name", "EDMFDigimonStage::BabyII" },
		{ "BlueprintType", "true" },
		{ "Champion.Name", "EDMFDigimonStage::Champion" },
		{ "Hybrid.Name", "EDMFDigimonStage::Hybrid" },
		{ "Mega.Name", "EDMFDigimonStage::Mega" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "Rookie.Name", "EDMFDigimonStage::Rookie" },
		{ "Ultimate.Name", "EDMFDigimonStage::Ultimate" },
		{ "Ultra.Name", "EDMFDigimonStage::Ultra" },
		{ "Unknown.Name", "EDMFDigimonStage::Unknown" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFDigimonStage::BabyI", (int64)EDMFDigimonStage::BabyI },
		{ "EDMFDigimonStage::BabyII", (int64)EDMFDigimonStage::BabyII },
		{ "EDMFDigimonStage::Rookie", (int64)EDMFDigimonStage::Rookie },
		{ "EDMFDigimonStage::Champion", (int64)EDMFDigimonStage::Champion },
		{ "EDMFDigimonStage::Ultimate", (int64)EDMFDigimonStage::Ultimate },
		{ "EDMFDigimonStage::Mega", (int64)EDMFDigimonStage::Mega },
		{ "EDMFDigimonStage::Ultra", (int64)EDMFDigimonStage::Ultra },
		{ "EDMFDigimonStage::Armor", (int64)EDMFDigimonStage::Armor },
		{ "EDMFDigimonStage::Hybrid", (int64)EDMFDigimonStage::Hybrid },
		{ "EDMFDigimonStage::Unknown", (int64)EDMFDigimonStage::Unknown },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFDigimonStage",
	"EDMFDigimonStage",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFDigimonStage;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFDigimonStage.OuterSingleton)
		{
			ZRIE_EDMFDigimonStage.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFDigimonStage"));
		}
		return ZRIE_EDMFDigimonStage.OuterSingleton;
	}
	if (!ZRIE_EDMFDigimonStage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFDigimonStage.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFDigimonStage.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFDigimonStage ************************************************************

// ********** Begin Enum EDMFDigimonAttribute ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttribute_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFDigimonAttribute>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttribute(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Data.Name", "EDMFDigimonAttribute::Data" },
		{ "Free.Name", "EDMFDigimonAttribute::Free" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "Unknown.Name", "EDMFDigimonAttribute::Unknown" },
		{ "Vaccine.Name", "EDMFDigimonAttribute::Vaccine" },
		{ "Variable.Name", "EDMFDigimonAttribute::Variable" },
		{ "Virus.Name", "EDMFDigimonAttribute::Virus" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFDigimonAttribute::Vaccine", (int64)EDMFDigimonAttribute::Vaccine },
		{ "EDMFDigimonAttribute::Virus", (int64)EDMFDigimonAttribute::Virus },
		{ "EDMFDigimonAttribute::Data", (int64)EDMFDigimonAttribute::Data },
		{ "EDMFDigimonAttribute::Free", (int64)EDMFDigimonAttribute::Free },
		{ "EDMFDigimonAttribute::Variable", (int64)EDMFDigimonAttribute::Variable },
		{ "EDMFDigimonAttribute::Unknown", (int64)EDMFDigimonAttribute::Unknown },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFDigimonAttribute",
	"EDMFDigimonAttribute",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFDigimonAttribute;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttribute(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFDigimonAttribute.OuterSingleton)
		{
			ZRIE_EDMFDigimonAttribute.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttribute, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFDigimonAttribute"));
		}
		return ZRIE_EDMFDigimonAttribute.OuterSingleton;
	}
	if (!ZRIE_EDMFDigimonAttribute.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFDigimonAttribute.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFDigimonAttribute.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFDigimonAttribute ********************************************************

// ********** Begin Enum EDMFDigimonElement ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonElement_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFDigimonElement>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonElement(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Dark.Name", "EDMFDigimonElement::Dark" },
		{ "Earth.Name", "EDMFDigimonElement::Earth" },
		{ "Electric.Name", "EDMFDigimonElement::Electric" },
		{ "Fire.Name", "EDMFDigimonElement::Fire" },
		{ "Ice.Name", "EDMFDigimonElement::Ice" },
		{ "Light.Name", "EDMFDigimonElement::Light" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "Neutral.Name", "EDMFDigimonElement::Neutral" },
		{ "Plant.Name", "EDMFDigimonElement::Plant" },
		{ "Steel.Name", "EDMFDigimonElement::Steel" },
		{ "Unknown.Name", "EDMFDigimonElement::Unknown" },
		{ "Water.Name", "EDMFDigimonElement::Water" },
		{ "Wind.Name", "EDMFDigimonElement::Wind" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFDigimonElement::Neutral", (int64)EDMFDigimonElement::Neutral },
		{ "EDMFDigimonElement::Fire", (int64)EDMFDigimonElement::Fire },
		{ "EDMFDigimonElement::Water", (int64)EDMFDigimonElement::Water },
		{ "EDMFDigimonElement::Plant", (int64)EDMFDigimonElement::Plant },
		{ "EDMFDigimonElement::Earth", (int64)EDMFDigimonElement::Earth },
		{ "EDMFDigimonElement::Wind", (int64)EDMFDigimonElement::Wind },
		{ "EDMFDigimonElement::Electric", (int64)EDMFDigimonElement::Electric },
		{ "EDMFDigimonElement::Light", (int64)EDMFDigimonElement::Light },
		{ "EDMFDigimonElement::Dark", (int64)EDMFDigimonElement::Dark },
		{ "EDMFDigimonElement::Steel", (int64)EDMFDigimonElement::Steel },
		{ "EDMFDigimonElement::Ice", (int64)EDMFDigimonElement::Ice },
		{ "EDMFDigimonElement::Unknown", (int64)EDMFDigimonElement::Unknown },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFDigimonElement",
	"EDMFDigimonElement",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFDigimonElement;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonElement(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFDigimonElement.OuterSingleton)
		{
			ZRIE_EDMFDigimonElement.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonElement, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFDigimonElement"));
		}
		return ZRIE_EDMFDigimonElement.OuterSingleton;
	}
	if (!ZRIE_EDMFDigimonElement.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFDigimonElement.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFDigimonElement.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFDigimonElement **********************************************************

// ********** Begin Enum EDMFWildSpawnRarity *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFWildSpawnRarity>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Generic MMO rarity tier assigned by authoritative wild spawners. */" },
#endif
		{ "Common.Name", "EDMFWildSpawnRarity::Common" },
		{ "Epic.Name", "EDMFWildSpawnRarity::Epic" },
		{ "Legendary.Name", "EDMFWildSpawnRarity::Legendary" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "Mythic.Name", "EDMFWildSpawnRarity::Mythic" },
		{ "Rare.Name", "EDMFWildSpawnRarity::Rare" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generic MMO rarity tier assigned by authoritative wild spawners." },
#endif
		{ "Uncommon.Name", "EDMFWildSpawnRarity::Uncommon" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFWildSpawnRarity::Common", (int64)EDMFWildSpawnRarity::Common },
		{ "EDMFWildSpawnRarity::Uncommon", (int64)EDMFWildSpawnRarity::Uncommon },
		{ "EDMFWildSpawnRarity::Rare", (int64)EDMFWildSpawnRarity::Rare },
		{ "EDMFWildSpawnRarity::Epic", (int64)EDMFWildSpawnRarity::Epic },
		{ "EDMFWildSpawnRarity::Legendary", (int64)EDMFWildSpawnRarity::Legendary },
		{ "EDMFWildSpawnRarity::Mythic", (int64)EDMFWildSpawnRarity::Mythic },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFWildSpawnRarity",
	"EDMFWildSpawnRarity",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFWildSpawnRarity;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFWildSpawnRarity.OuterSingleton)
		{
			ZRIE_EDMFWildSpawnRarity.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFWildSpawnRarity"));
		}
		return ZRIE_EDMFWildSpawnRarity.OuterSingleton;
	}
	if (!ZRIE_EDMFWildSpawnRarity.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFWildSpawnRarity.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFWildSpawnRarity.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFWildSpawnRarity *********************************************************

// ********** Begin Enum EDMFPlayerInteractionType *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerInteractionType_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFPlayerInteractionType>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerInteractionType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Result category for the framework-native player interaction layer. */" },
#endif
		{ "DigimonTarget.Name", "EDMFPlayerInteractionType::DigimonTarget" },
		{ "DigimonTargetAndAttack.Name", "EDMFPlayerInteractionType::DigimonTargetAndAttack" },
		{ "Healer.Name", "EDMFPlayerInteractionType::Healer" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "None.Name", "EDMFPlayerInteractionType::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Result category for the framework-native player interaction layer." },
#endif
		{ "Unhandled.Name", "EDMFPlayerInteractionType::Unhandled" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFPlayerInteractionType::None", (int64)EDMFPlayerInteractionType::None },
		{ "EDMFPlayerInteractionType::DigimonTarget", (int64)EDMFPlayerInteractionType::DigimonTarget },
		{ "EDMFPlayerInteractionType::DigimonTargetAndAttack", (int64)EDMFPlayerInteractionType::DigimonTargetAndAttack },
		{ "EDMFPlayerInteractionType::Healer", (int64)EDMFPlayerInteractionType::Healer },
		{ "EDMFPlayerInteractionType::Unhandled", (int64)EDMFPlayerInteractionType::Unhandled },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFPlayerInteractionType",
	"EDMFPlayerInteractionType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFPlayerInteractionType;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerInteractionType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFPlayerInteractionType.OuterSingleton)
		{
			ZRIE_EDMFPlayerInteractionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerInteractionType, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFPlayerInteractionType"));
		}
		return ZRIE_EDMFPlayerInteractionType.OuterSingleton;
	}
	if (!ZRIE_EDMFPlayerInteractionType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFPlayerInteractionType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFPlayerInteractionType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFPlayerInteractionType ***************************************************

// ********** Begin Enum EDMFRankedTier ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFRankedTier_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFRankedTier>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFRankedTier(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "A.Name", "EDMFRankedTier::A" },
		{ "B.Name", "EDMFRankedTier::B" },
		{ "BlueprintType", "true" },
		{ "C.Name", "EDMFRankedTier::C" },
		{ "D.Name", "EDMFRankedTier::D" },
		{ "E.Name", "EDMFRankedTier::E" },
		{ "F.Name", "EDMFRankedTier::F" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "S.Name", "EDMFRankedTier::S" },
		{ "SPlus.DisplayName", "S+" },
		{ "SPlus.Name", "EDMFRankedTier::SPlus" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFRankedTier::F", (int64)EDMFRankedTier::F },
		{ "EDMFRankedTier::E", (int64)EDMFRankedTier::E },
		{ "EDMFRankedTier::D", (int64)EDMFRankedTier::D },
		{ "EDMFRankedTier::C", (int64)EDMFRankedTier::C },
		{ "EDMFRankedTier::B", (int64)EDMFRankedTier::B },
		{ "EDMFRankedTier::A", (int64)EDMFRankedTier::A },
		{ "EDMFRankedTier::S", (int64)EDMFRankedTier::S },
		{ "EDMFRankedTier::SPlus", (int64)EDMFRankedTier::SPlus },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFRankedTier",
	"EDMFRankedTier",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFRankedTier;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFRankedTier(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFRankedTier.OuterSingleton)
		{
			ZRIE_EDMFRankedTier.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFRankedTier, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFRankedTier"));
		}
		return ZRIE_EDMFRankedTier.OuterSingleton;
	}
	if (!ZRIE_EDMFRankedTier.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFRankedTier.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFRankedTier.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFRankedTier **************************************************************

// ********** Begin Enum EDMFWorldChatMessageType **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFWorldChatMessageType_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFWorldChatMessageType>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFWorldChatMessageType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Presentation category for the native session world-chat stream. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "Player.Name", "EDMFWorldChatMessageType::Player" },
		{ "System.Name", "EDMFWorldChatMessageType::System" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Presentation category for the native session world-chat stream." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFWorldChatMessageType::Player", (int64)EDMFWorldChatMessageType::Player },
		{ "EDMFWorldChatMessageType::System", (int64)EDMFWorldChatMessageType::System },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFWorldChatMessageType",
	"EDMFWorldChatMessageType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFWorldChatMessageType;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFWorldChatMessageType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFWorldChatMessageType.OuterSingleton)
		{
			ZRIE_EDMFWorldChatMessageType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFWorldChatMessageType, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFWorldChatMessageType"));
		}
		return ZRIE_EDMFWorldChatMessageType.OuterSingleton;
	}
	if (!ZRIE_EDMFWorldChatMessageType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFWorldChatMessageType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFWorldChatMessageType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFWorldChatMessageType ****************************************************

// ********** Begin ScriptStruct FDMFWorldChatMessage **********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFWorldChatMessage_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFWorldChatMessage>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFWorldChatMessage); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server-stamped world-chat payload delivered to owning PlayerControllers.\n * Clients submit only raw text; sender identity and timestamp are always authored by the server.\n */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-stamped world-chat payload delivered to owning PlayerControllers.\nClients submit only raw text; sender identity and timestamp are always authored by the server." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SenderName_MetaData[] = {
		{ "Category", "World Chat" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "World Chat" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SentUtcTicks_MetaData[] = {
		{ "Category", "World Chat" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MessageType_MetaData[] = {
		{ "Category", "World Chat" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFWorldChatMessage constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SenderName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SentUtcTicks;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MessageType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MessageType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFWorldChatMessage constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFWorldChatMessage>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFWorldChatMessage Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SenderName = { "SenderName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWorldChatMessage, SenderName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SenderName_MetaData), NewProp_SenderName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWorldChatMessage, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_SentUtcTicks = { "SentUtcTicks", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWorldChatMessage, SentUtcTicks), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SentUtcTicks_MetaData), NewProp_SentUtcTicks_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_MessageType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_MessageType = { "MessageType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWorldChatMessage, MessageType), Z_Construct_UEnum_DigimonMMOFramework_EDMFWorldChatMessageType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MessageType_MetaData), NewProp_MessageType_MetaData) }; // 3759a77e9dcf3050423a6677743d478033f8c3d4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SenderName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SentUtcTicks,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MessageType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MessageType,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFWorldChatMessage Property Definitions ***************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFWorldChatMessage",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFWorldChatMessage>(),
	alignof(FDMFWorldChatMessage),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFWorldChatMessage;
UScriptStruct* Z_Construct_UScriptStruct_FDMFWorldChatMessage(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFWorldChatMessage.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFWorldChatMessage.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFWorldChatMessage, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFWorldChatMessage"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFWorldChatMessage.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFWorldChatMessage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFWorldChatMessage.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFWorldChatMessage.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFWorldChatMessage ************************************************

// ********** Begin Enum EDMFDigimonMenuTab ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFDigimonMenuTab>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Bank.Comment", "/** Appended in v0.12 so earlier enum values are never shifted. */" },
		{ "Bank.DisplayName", "Bank / Boxes" },
		{ "Bank.Name", "EDMFDigimonMenuTab::Bank" },
		{ "Bank.ToolTip", "Appended in v0.12 so earlier enum values are never shifted." },
		{ "BlueprintType", "true" },
		{ "Care.Name", "EDMFDigimonMenuTab::Care" },
		{ "Collection.Comment", "/** Backward-compatible API name/value for the active six-Digimon Party page. */" },
		{ "Collection.DisplayName", "Party" },
		{ "Collection.Name", "EDMFDigimonMenuTab::Collection" },
		{ "Collection.ToolTip", "Backward-compatible API name/value for the active six-Digimon Party page." },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current pages in the polished Digimon menu shell. Additional systems can extend this enum later. */" },
#endif
		{ "DigiDex.Comment", "/** Appended in v0.14. Read-only encyclopedia; earlier serialized tab values remain stable. */" },
		{ "DigiDex.DisplayName", "DigiDex" },
		{ "DigiDex.Name", "EDMFDigimonMenuTab::DigiDex" },
		{ "DigiDex.ToolTip", "Appended in v0.14. Read-only encyclopedia; earlier serialized tab values remain stable." },
		{ "Digivolution.Comment", "/** Appended in v0.13. Existing serialized tab values remain stable. */" },
		{ "Digivolution.DisplayName", "Digivolution" },
		{ "Digivolution.Name", "EDMFDigimonMenuTab::Digivolution" },
		{ "Digivolution.ToolTip", "Appended in v0.13. Existing serialized tab values remain stable." },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "ScanAndMaterialize.Comment", "/** Existing serialized values remain in their pre-v0.12 order for Blueprint/save compatibility. */" },
		{ "ScanAndMaterialize.DisplayName", "Scan & Materialize" },
		{ "ScanAndMaterialize.Name", "EDMFDigimonMenuTab::ScanAndMaterialize" },
		{ "ScanAndMaterialize.ToolTip", "Existing serialized values remain in their pre-v0.12 order for Blueprint/save compatibility." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current pages in the polished Digimon menu shell. Additional systems can extend this enum later." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFDigimonMenuTab::Collection", (int64)EDMFDigimonMenuTab::Collection },
		{ "EDMFDigimonMenuTab::ScanAndMaterialize", (int64)EDMFDigimonMenuTab::ScanAndMaterialize },
		{ "EDMFDigimonMenuTab::Care", (int64)EDMFDigimonMenuTab::Care },
		{ "EDMFDigimonMenuTab::Bank", (int64)EDMFDigimonMenuTab::Bank },
		{ "EDMFDigimonMenuTab::Digivolution", (int64)EDMFDigimonMenuTab::Digivolution },
		{ "EDMFDigimonMenuTab::DigiDex", (int64)EDMFDigimonMenuTab::DigiDex },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFDigimonMenuTab",
	"EDMFDigimonMenuTab",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFDigimonMenuTab;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFDigimonMenuTab.OuterSingleton)
		{
			ZRIE_EDMFDigimonMenuTab.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFDigimonMenuTab"));
		}
		return ZRIE_EDMFDigimonMenuTab.OuterSingleton;
	}
	if (!ZRIE_EDMFDigimonMenuTab.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFDigimonMenuTab.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFDigimonMenuTab.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFDigimonMenuTab **********************************************************

// ********** Begin Enum EDMFDigimonStorageLocation ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFDigimonStorageLocation>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Bank.Name", "EDMFDigimonStorageLocation::Bank" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authoritative owner-storage location used by Party/Bank transfer APIs. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "Party.Name", "EDMFDigimonStorageLocation::Party" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authoritative owner-storage location used by Party/Bank transfer APIs." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFDigimonStorageLocation::Party", (int64)EDMFDigimonStorageLocation::Party },
		{ "EDMFDigimonStorageLocation::Bank", (int64)EDMFDigimonStorageLocation::Bank },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFDigimonStorageLocation",
	"EDMFDigimonStorageLocation",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFDigimonStorageLocation;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFDigimonStorageLocation.OuterSingleton)
		{
			ZRIE_EDMFDigimonStorageLocation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFDigimonStorageLocation"));
		}
		return ZRIE_EDMFDigimonStorageLocation.OuterSingleton;
	}
	if (!ZRIE_EDMFDigimonStorageLocation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFDigimonStorageLocation.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFDigimonStorageLocation.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFDigimonStorageLocation **************************************************

// ********** Begin Enum EDMFDigimonAttributeStat **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttributeStat_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFDigimonAttributeStat>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttributeStat(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Core persistent stats that may be increased by spending earned Attribute Points. ABI/CAM remain progression/care values and are intentionally not spendable here. */" },
#endif
		{ "Defense.DisplayName", "Defense" },
		{ "Defense.Name", "EDMFDigimonAttributeStat::Defense" },
		{ "Intelligence.DisplayName", "Intelligence" },
		{ "Intelligence.Name", "EDMFDigimonAttributeStat::Intelligence" },
		{ "MaxHP.DisplayName", "Max HP" },
		{ "MaxHP.Name", "EDMFDigimonAttributeStat::MaxHP" },
		{ "MaxSP.DisplayName", "Max SP" },
		{ "MaxSP.Name", "EDMFDigimonAttributeStat::MaxSP" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "Speed.DisplayName", "Speed" },
		{ "Speed.Name", "EDMFDigimonAttributeStat::Speed" },
		{ "Strength.DisplayName", "Strength" },
		{ "Strength.Name", "EDMFDigimonAttributeStat::Strength" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core persistent stats that may be increased by spending earned Attribute Points. ABI/CAM remain progression/care values and are intentionally not spendable here." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFDigimonAttributeStat::MaxHP", (int64)EDMFDigimonAttributeStat::MaxHP },
		{ "EDMFDigimonAttributeStat::MaxSP", (int64)EDMFDigimonAttributeStat::MaxSP },
		{ "EDMFDigimonAttributeStat::Strength", (int64)EDMFDigimonAttributeStat::Strength },
		{ "EDMFDigimonAttributeStat::Intelligence", (int64)EDMFDigimonAttributeStat::Intelligence },
		{ "EDMFDigimonAttributeStat::Defense", (int64)EDMFDigimonAttributeStat::Defense },
		{ "EDMFDigimonAttributeStat::Speed", (int64)EDMFDigimonAttributeStat::Speed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFDigimonAttributeStat",
	"EDMFDigimonAttributeStat",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFDigimonAttributeStat;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttributeStat(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFDigimonAttributeStat.OuterSingleton)
		{
			ZRIE_EDMFDigimonAttributeStat.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttributeStat, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFDigimonAttributeStat"));
		}
		return ZRIE_EDMFDigimonAttributeStat.OuterSingleton;
	}
	if (!ZRIE_EDMFDigimonAttributeStat.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFDigimonAttributeStat.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFDigimonAttributeStat.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFDigimonAttributeStat ****************************************************

// ********** Begin ScriptStruct FDMFDigivolutionEvaluation ****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigivolutionEvaluation_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigivolutionEvaluation>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigivolutionEvaluation); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local/owner-only evaluation row for one configured Digivolution path. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local/owner-only evaluation row for one configured Digivolution path." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSpeciesId_MetaData[] = {
		{ "Category", "Digimon|Digivolution" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEligible_MetaData[] = {
		{ "Category", "Digimon|Digivolution" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequirementSummary_MetaData[] = {
		{ "Category", "Digimon|Digivolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Compact human-readable requirement summary suitable for native/Blueprint UI. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compact human-readable requirement summary suitable for native/Blueprint UI." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureReason_MetaData[] = {
		{ "Category", "Digimon|Digivolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Empty when eligible; otherwise the first authoritative requirement that is not currently met. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Empty when eligible; otherwise the first authoritative requirement that is not currently met." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigivolutionEvaluation constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetSpeciesId;
	static void NewProp_bEligible_SetBit(void* Obj)
	{
		((FDMFDigivolutionEvaluation*)Obj)->bEligible = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEligible;
	static const UECodeGen_Private::FTextPropertyParams NewProp_RequirementSummary;
	static const UECodeGen_Private::FTextPropertyParams NewProp_FailureReason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigivolutionEvaluation constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigivolutionEvaluation>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigivolutionEvaluation Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_TargetSpeciesId = { "TargetSpeciesId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionEvaluation, TargetSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSpeciesId_MetaData), NewProp_TargetSpeciesId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEligible = { "bEligible", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigivolutionEvaluation), &UHT_STATICS::NewProp_bEligible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEligible_MetaData), NewProp_bEligible_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_RequirementSummary = { "RequirementSummary", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionEvaluation, RequirementSummary), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequirementSummary_MetaData), NewProp_RequirementSummary_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_FailureReason = { "FailureReason", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionEvaluation, FailureReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureReason_MetaData), NewProp_FailureReason_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetSpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEligible,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RequirementSummary,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FailureReason,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigivolutionEvaluation Property Definitions *********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigivolutionEvaluation",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigivolutionEvaluation>(),
	alignof(FDMFDigivolutionEvaluation),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigivolutionEvaluation;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigivolutionEvaluation(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigivolutionEvaluation.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigivolutionEvaluation.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigivolutionEvaluation, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigivolutionEvaluation"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigivolutionEvaluation.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigivolutionEvaluation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigivolutionEvaluation.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigivolutionEvaluation.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigivolutionEvaluation ******************************************

// ********** Begin ScriptStruct FDMFDigimonStats **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonStats_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonStats>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonStats); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Experience_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHP_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSP_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Strength_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Intelligence_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Defense_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ABI_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CAM_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonStats constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Experience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxHP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxSP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Strength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Intelligence;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Defense;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Speed;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ABI;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CAM;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonStats constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonStats>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonStats Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, Level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Level_MetaData), NewProp_Level_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_Experience = { "Experience", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, Experience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Experience_MetaData), NewProp_Experience_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxHP = { "MaxHP", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, MaxHP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHP_MetaData), NewProp_MaxHP_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxSP = { "MaxSP", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, MaxSP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSP_MetaData), NewProp_MaxSP_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Strength = { "Strength", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, Strength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Strength_MetaData), NewProp_Strength_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Intelligence = { "Intelligence", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, Intelligence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Intelligence_MetaData), NewProp_Intelligence_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Defense = { "Defense", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, Defense), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Defense_MetaData), NewProp_Defense_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, Speed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Speed_MetaData), NewProp_Speed_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ABI = { "ABI", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, ABI), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ABI_MetaData), NewProp_ABI_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CAM = { "CAM", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonStats, CAM), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CAM_MetaData), NewProp_CAM_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Level,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Experience,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxSP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Strength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Intelligence,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Defense,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Speed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ABI,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CAM,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonStats Property Definitions *******************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonStats",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonStats>(),
	alignof(FDMFDigimonStats),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonStats;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonStats(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonStats.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonStats.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonStats, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonStats"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonStats.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonStats.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonStats.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonStats.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonStats ****************************************************

// ********** Begin ScriptStruct FDMFDigimonCareState **********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonCareState_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonCareState>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonCareState); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hunger_MetaData[] = {
		{ "Category", "Digimon|Care" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fullness_MetaData[] = {
		{ "Category", "Digimon|Care" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Happiness_MetaData[] = {
		{ "Category", "Digimon|Care" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Discipline_MetaData[] = {
		{ "Category", "Digimon|Care" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CareMistakes_MetaData[] = {
		{ "Category", "Digimon|Care" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastFedUtcTicks_MetaData[] = {
		{ "Category", "Digimon|Care" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextWasteUtcTicks_MetaData[] = {
		{ "Category", "Digimon|Care" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastCareUpdateUtcTicks_MetaData[] = {
		{ "Category", "Digimon|Care" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server UTC timestamp used to apply deterministic online/offline Hunger decay. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server UTC timestamp used to apply deterministic online/offline Hunger decay." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonCareState constinit property declarations **************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Hunger;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Fullness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Happiness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Discipline;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CareMistakes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_LastFedUtcTicks;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NextWasteUtcTicks;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_LastCareUpdateUtcTicks;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonCareState constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonCareState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonCareState Property Definitions *************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Hunger = { "Hunger", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonCareState, Hunger), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hunger_MetaData), NewProp_Hunger_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Fullness = { "Fullness", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonCareState, Fullness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fullness_MetaData), NewProp_Fullness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Happiness = { "Happiness", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonCareState, Happiness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Happiness_MetaData), NewProp_Happiness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Discipline = { "Discipline", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonCareState, Discipline), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Discipline_MetaData), NewProp_Discipline_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CareMistakes = { "CareMistakes", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonCareState, CareMistakes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CareMistakes_MetaData), NewProp_CareMistakes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_LastFedUtcTicks = { "LastFedUtcTicks", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonCareState, LastFedUtcTicks), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastFedUtcTicks_MetaData), NewProp_LastFedUtcTicks_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NextWasteUtcTicks = { "NextWasteUtcTicks", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonCareState, NextWasteUtcTicks), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextWasteUtcTicks_MetaData), NewProp_NextWasteUtcTicks_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_LastCareUpdateUtcTicks = { "LastCareUpdateUtcTicks", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonCareState, LastCareUpdateUtcTicks), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastCareUpdateUtcTicks_MetaData), NewProp_LastCareUpdateUtcTicks_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Hunger,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Fullness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Happiness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Discipline,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CareMistakes,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastFedUtcTicks,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NextWasteUtcTicks,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LastCareUpdateUtcTicks,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonCareState Property Definitions ***************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonCareState",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonCareState>(),
	alignof(FDMFDigimonCareState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonCareState;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonCareState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonCareState.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonCareState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonCareState, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonCareState"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonCareState.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonCareState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonCareState.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonCareState.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonCareState ************************************************

// ********** Begin ScriptStruct FDMFDigimonInstance ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonInstance_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonInstance>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonInstance); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Digimon|Identity" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesId_MetaData[] = {
		{ "Category", "Digimon|Identity" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Nickname_MetaData[] = {
		{ "Category", "Digimon|Identity" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stats_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHP_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSP_MetaData[] = {
		{ "Category", "Digimon|Stats" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnspentAttributePoints_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EquippedAbilityIds_MetaData[] = {
		{ "Category", "Digimon|Abilities" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Care_MetaData[] = {
		{ "Category", "Digimon|Care" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OriginSpeciesId_MetaData[] = {
		{ "Category", "Digimon|Digivolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** First materialized/starter species for this persistent individual. Added in SaveGame schema v5. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "First materialized/starter species for this persistent individual. Added in SaveGame schema v5." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigivolutionHistory_MetaData[] = {
		{ "Category", "Digimon|Digivolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ordered unique list of species forms reached by this individual. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ordered unique list of species forms reached by this individual." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStarterPartner_MetaData[] = {
		{ "Category", "Digimon|Meta" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonInstance constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Nickname;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stats;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentHP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentSP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_UnspentAttributePoints;
	static const UECodeGen_Private::FNamePropertyParams NewProp_EquippedAbilityIds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_EquippedAbilityIds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Care;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OriginSpeciesId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigivolutionHistory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DigivolutionHistory;
	static void NewProp_bStarterPartner_SetBit(void* Obj)
	{
		((FDMFDigimonInstance*)Obj)->bStarterPartner = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStarterPartner;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonInstance constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonInstance>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonInstance Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000001000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000001000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesId_MetaData), NewProp_SpeciesId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Nickname = { "Nickname", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, Nickname), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Nickname_MetaData), NewProp_Nickname_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Stats = { "Stats", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, Stats), Z_Construct_UScriptStruct_FDMFDigimonStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stats_MetaData), NewProp_Stats_MetaData) }; // 520b7c977c816e4f689d80785fbab8bbe48405a6
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CurrentHP = { "CurrentHP", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, CurrentHP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHP_MetaData), NewProp_CurrentHP_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CurrentSP = { "CurrentSP", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, CurrentSP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSP_MetaData), NewProp_CurrentSP_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_UnspentAttributePoints = { "UnspentAttributePoints", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, UnspentAttributePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnspentAttributePoints_MetaData), NewProp_UnspentAttributePoints_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_EquippedAbilityIds_Inner = { "EquippedAbilityIds", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_EquippedAbilityIds = { "EquippedAbilityIds", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, EquippedAbilityIds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EquippedAbilityIds_MetaData), NewProp_EquippedAbilityIds_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Care = { "Care", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, Care), Z_Construct_UScriptStruct_FDMFDigimonCareState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Care_MetaData), NewProp_Care_MetaData) }; // 424313712cc83304aba267fa4dfab31c9d6ce242
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OriginSpeciesId = { "OriginSpeciesId", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, OriginSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OriginSpeciesId_MetaData), NewProp_OriginSpeciesId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigivolutionHistory_Inner = { "DigivolutionHistory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_DigivolutionHistory = { "DigivolutionHistory", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonInstance, DigivolutionHistory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigivolutionHistory_MetaData), NewProp_DigivolutionHistory_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bStarterPartner = { "bStarterPartner", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigimonInstance), &UHT_STATICS::NewProp_bStarterPartner_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStarterPartner_MetaData), NewProp_bStarterPartner_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Nickname,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Stats,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurrentHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurrentSP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UnspentAttributePoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EquippedAbilityIds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EquippedAbilityIds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Care,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OriginSpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionHistory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigivolutionHistory,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bStarterPartner,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonInstance Property Definitions ****************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonInstance",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonInstance>(),
	alignof(FDMFDigimonInstance),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonInstance;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonInstance(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonInstance.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonInstance.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonInstance, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonInstance"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonInstance.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonInstance.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonInstance.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonInstance.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonInstance *************************************************

// ********** Begin ScriptStruct FDMFScanDataEntry *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFScanDataEntry_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFScanDataEntry>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFScanDataEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesId_MetaData[] = {
		{ "Category", "DMFScanDataEntry" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanPercent_MetaData[] = {
		{ "Category", "DMFScanDataEntry" },
		{ "ClampMax", "999.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFScanDataEntry constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScanPercent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFScanDataEntry constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFScanDataEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFScanDataEntry Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFScanDataEntry, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesId_MetaData), NewProp_SpeciesId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ScanPercent = { "ScanPercent", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFScanDataEntry, ScanPercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanPercent_MetaData), NewProp_ScanPercent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanPercent,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFScanDataEntry Property Definitions ******************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFScanDataEntry",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFScanDataEntry>(),
	alignof(FDMFScanDataEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFScanDataEntry;
UScriptStruct* Z_Construct_UScriptStruct_FDMFScanDataEntry(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFScanDataEntry.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFScanDataEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFScanDataEntry, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFScanDataEntry"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFScanDataEntry.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFScanDataEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFScanDataEntry.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFScanDataEntry.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFScanDataEntry ***************************************************

// ********** Begin Enum EDMFMusicState ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFMusicState>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Battle.Name", "EDMFMusicState::Battle" },
		{ "BlueprintType", "true" },
		{ "Frontend.Name", "EDMFMusicState::Frontend" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "None.Name", "EDMFMusicState::None" },
		{ "OpenWorld.Name", "EDMFMusicState::OpenWorld" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFMusicState::None", (int64)EDMFMusicState::None },
		{ "EDMFMusicState::Frontend", (int64)EDMFMusicState::Frontend },
		{ "EDMFMusicState::OpenWorld", (int64)EDMFMusicState::OpenWorld },
		{ "EDMFMusicState::Battle", (int64)EDMFMusicState::Battle },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFMusicState",
	"EDMFMusicState",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFMusicState;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFMusicState.OuterSingleton)
		{
			ZRIE_EDMFMusicState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFMusicState"));
		}
		return ZRIE_EDMFMusicState.OuterSingleton;
	}
	if (!ZRIE_EDMFMusicState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFMusicState.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFMusicState.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFMusicState **************************************************************

// ********** Begin Enum EDMFCombatState ***********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFCombatState>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Attacking.Name", "EDMFCombatState::Attacking" },
		{ "BlueprintType", "true" },
		{ "Chasing.Name", "EDMFCombatState::Chasing" },
		{ "Defeated.Name", "EDMFCombatState::Defeated" },
		{ "Idle.Name", "EDMFCombatState::Idle" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "Recovering.Name", "EDMFCombatState::Recovering" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFCombatState::Idle", (int64)EDMFCombatState::Idle },
		{ "EDMFCombatState::Chasing", (int64)EDMFCombatState::Chasing },
		{ "EDMFCombatState::Attacking", (int64)EDMFCombatState::Attacking },
		{ "EDMFCombatState::Recovering", (int64)EDMFCombatState::Recovering },
		{ "EDMFCombatState::Defeated", (int64)EDMFCombatState::Defeated },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFCombatState",
	"EDMFCombatState",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFCombatState;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFCombatState.OuterSingleton)
		{
			ZRIE_EDMFCombatState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFCombatState"));
		}
		return ZRIE_EDMFCombatState.OuterSingleton;
	}
	if (!ZRIE_EDMFCombatState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFCombatState.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFCombatState.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFCombatState *************************************************************

// ********** Begin Enum EDMFDamageScaling *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFDamageScaling_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFDamageScaling>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFDamageScaling(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Intelligence.Name", "EDMFDamageScaling::Intelligence" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
		{ "Strength.Name", "EDMFDamageScaling::Strength" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFDamageScaling::Strength", (int64)EDMFDamageScaling::Strength },
		{ "EDMFDamageScaling::Intelligence", (int64)EDMFDamageScaling::Intelligence },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFDamageScaling",
	"EDMFDamageScaling",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFDamageScaling;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDamageScaling(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFDamageScaling.OuterSingleton)
		{
			ZRIE_EDMFDamageScaling.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFDamageScaling, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFDamageScaling"));
		}
		return ZRIE_EDMFDamageScaling.OuterSingleton;
	}
	if (!ZRIE_EDMFDamageScaling.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFDamageScaling.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFDamageScaling.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFDamageScaling ***********************************************************

// ********** Begin ScriptStruct FDMFAbilityCooldownState ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFAbilityCooldownState_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFAbilityCooldownState>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFAbilityCooldownState); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityId_MetaData[] = {
		{ "Category", "Digimon|Combat" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndServerTimeSeconds_MetaData[] = {
		{ "Category", "Digimon|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Synchronized server world time at which the ability becomes ready. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Synchronized server world time at which the ability becomes ready." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFAbilityCooldownState constinit property declarations **********
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_EndServerTimeSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFAbilityCooldownState constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFAbilityCooldownState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFAbilityCooldownState Property Definitions *********************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAbilityCooldownState, AbilityId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityId_MetaData), NewProp_AbilityId_MetaData) };
const UECodeGen_Private::FDoublePropertyParams UHT_STATICS::NewProp_EndServerTimeSeconds = { "EndServerTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Double, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAbilityCooldownState, EndServerTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndServerTimeSeconds_MetaData), NewProp_EndServerTimeSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EndServerTimeSeconds,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFAbilityCooldownState Property Definitions ***********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFAbilityCooldownState",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFAbilityCooldownState>(),
	alignof(FDMFAbilityCooldownState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFAbilityCooldownState;
UScriptStruct* Z_Construct_UScriptStruct_FDMFAbilityCooldownState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFAbilityCooldownState.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFAbilityCooldownState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFAbilityCooldownState, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFAbilityCooldownState"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFAbilityCooldownState.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFAbilityCooldownState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFAbilityCooldownState.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFAbilityCooldownState.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFAbilityCooldownState ********************************************

// ********** Begin ScriptStruct FDMFBattleReward **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFBattleReward_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFBattleReward>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFBattleReward); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Experience_MetaData[] = {
		{ "Category", "Digimon|Battle" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Money_MetaData[] = {
		{ "Category", "Digimon|Battle" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFBattleReward constinit property declarations ******************
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Experience;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Money;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFBattleReward constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFBattleReward>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFBattleReward Property Definitions *****************************
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_Experience = { "Experience", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFBattleReward, Experience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Experience_MetaData), NewProp_Experience_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_Money = { "Money", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFBattleReward, Money), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Money_MetaData), NewProp_Money_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Experience,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Money,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFBattleReward Property Definitions *******************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFBattleReward",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFBattleReward>(),
	alignof(FDMFBattleReward),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFBattleReward;
UScriptStruct* Z_Construct_UScriptStruct_FDMFBattleReward(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFBattleReward.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFBattleReward.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFBattleReward, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFBattleReward"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFBattleReward.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFBattleReward.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFBattleReward.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFBattleReward.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFBattleReward ****************************************************

// ********** Begin ScriptStruct FDMFDigimonExperienceProgression **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigimonExperienceProgression>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigimonExperienceProgression); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Owner-facing snapshot of one authoritative EXP mutation. Durable progression remains in FDMFDigimonInstance. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owner-facing snapshot of one authoritative EXP mutation. Durable progression remains in FDMFDigimonInstance." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonInstanceId_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesId_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperienceGained_MetaData[] = {
		{ "Category", "Digimon|Progression" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** EXP actually applied to this Digimon by the authoritative mutation. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EXP actually applied to this Digimon by the authoritative mutation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousLevel_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewLevel_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousExperience_MetaData[] = {
		{ "Category", "Digimon|Progression" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** EXP bank toward PreviousLevel + 1 before this reward. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EXP bank toward PreviousLevel + 1 before this reward." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewExperience_MetaData[] = {
		{ "Category", "Digimon|Progression" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Remaining EXP bank toward NewLevel + 1 after consuming every completed level threshold. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remaining EXP bank toward NewLevel + 1 after consuming every completed level threshold." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelsGained_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributePointsGained_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bReachedMaxLevel_MetaData[] = {
		{ "Category", "Digimon|Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigimonExperienceProgression constinit property declarations **
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ExperienceGained;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PreviousLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewLevel;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PreviousExperience;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NewExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LevelsGained;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttributePointsGained;
	static void NewProp_bReachedMaxLevel_SetBit(void* Obj)
	{
		((FDMFDigimonExperienceProgression*)Obj)->bReachedMaxLevel = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bReachedMaxLevel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigimonExperienceProgression constinit property declarations ****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigimonExperienceProgression>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigimonExperienceProgression Property Definitions *************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonExperienceProgression, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonInstanceId_MetaData), NewProp_DigimonInstanceId_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonExperienceProgression, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesId_MetaData), NewProp_SpeciesId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_ExperienceGained = { "ExperienceGained", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonExperienceProgression, ExperienceGained), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperienceGained_MetaData), NewProp_ExperienceGained_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_PreviousLevel = { "PreviousLevel", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonExperienceProgression, PreviousLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousLevel_MetaData), NewProp_PreviousLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NewLevel = { "NewLevel", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonExperienceProgression, NewLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewLevel_MetaData), NewProp_NewLevel_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_PreviousExperience = { "PreviousExperience", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonExperienceProgression, PreviousExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousExperience_MetaData), NewProp_PreviousExperience_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NewExperience = { "NewExperience", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonExperienceProgression, NewExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewExperience_MetaData), NewProp_NewExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_LevelsGained = { "LevelsGained", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonExperienceProgression, LevelsGained), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelsGained_MetaData), NewProp_LevelsGained_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_AttributePointsGained = { "AttributePointsGained", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigimonExperienceProgression, AttributePointsGained), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributePointsGained_MetaData), NewProp_AttributePointsGained_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bReachedMaxLevel = { "bReachedMaxLevel", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigimonExperienceProgression), &UHT_STATICS::NewProp_bReachedMaxLevel_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bReachedMaxLevel_MetaData), NewProp_bReachedMaxLevel_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExperienceGained,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LevelsGained,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AttributePointsGained,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bReachedMaxLevel,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigimonExperienceProgression Property Definitions ***************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigimonExperienceProgression",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigimonExperienceProgression>(),
	alignof(FDMFDigimonExperienceProgression),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigimonExperienceProgression;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigimonExperienceProgression.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigimonExperienceProgression.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigimonExperienceProgression"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigimonExperienceProgression.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigimonExperienceProgression.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigimonExperienceProgression.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigimonExperienceProgression.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigimonExperienceProgression ************************************

// ********** Begin ScriptStruct FDMFPlayerWorldLocationState **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFPlayerWorldLocationState_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFPlayerWorldLocationState>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFPlayerWorldLocationState); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Persisted server-authored gameplay transform for one account. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Persisted server-authored gameplay transform for one account." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasSavedLocation_MetaData[] = {
		{ "Category", "Player World Location" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** False until the framework has committed the account's first gameplay spawn checkpoint. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "False until the framework has committed the account's first gameplay spawn checkpoint." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MapName_MetaData[] = {
		{ "Category", "Player World Location" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** PIE-prefix-free level name used to avoid applying coordinates to the wrong gameplay map. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PIE-prefix-free level name used to avoid applying coordinates to the wrong gameplay map." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Player World Location" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "Category", "Player World Location" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedUtcTicks_MetaData[] = {
		{ "Category", "Player World Location" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server UTC timestamp of the most recent committed position checkpoint. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server UTC timestamp of the most recent committed position checkpoint." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFPlayerWorldLocationState constinit property declarations ******
	static void NewProp_bHasSavedLocation_SetBit(void* Obj)
	{
		((FDMFPlayerWorldLocationState*)Obj)->bHasSavedLocation = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasSavedLocation;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MapName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SavedUtcTicks;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFPlayerWorldLocationState constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFPlayerWorldLocationState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFPlayerWorldLocationState Property Definitions *****************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bHasSavedLocation = { "bHasSavedLocation", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFPlayerWorldLocationState), &UHT_STATICS::NewProp_bHasSavedLocation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasSavedLocation_MetaData), NewProp_bHasSavedLocation_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_MapName = { "MapName", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFPlayerWorldLocationState, MapName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MapName_MetaData), NewProp_MapName_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFPlayerWorldLocationState, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFPlayerWorldLocationState, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_SavedUtcTicks = { "SavedUtcTicks", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFPlayerWorldLocationState, SavedUtcTicks), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedUtcTicks_MetaData), NewProp_SavedUtcTicks_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bHasSavedLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MapName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SavedUtcTicks,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFPlayerWorldLocationState Property Definitions *******************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFPlayerWorldLocationState",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFPlayerWorldLocationState>(),
	alignof(FDMFPlayerWorldLocationState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFPlayerWorldLocationState;
UScriptStruct* Z_Construct_UScriptStruct_FDMFPlayerWorldLocationState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFPlayerWorldLocationState.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFPlayerWorldLocationState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFPlayerWorldLocationState, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFPlayerWorldLocationState"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFPlayerWorldLocationState.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFPlayerWorldLocationState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFPlayerWorldLocationState.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFPlayerWorldLocationState.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFPlayerWorldLocationState ****************************************

// ********** Begin ScriptStruct FDMFAccountRecord *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFAccountRecord_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFAccountRecord>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFAccountRecord); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Username_MetaData[] = {
		{ "Category", "Account" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CredentialDigest_MetaData[] = {
		{ "Category", "Account" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedPlayerSkinId_MetaData[] = {
		{ "Category", "Player Avatar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Persistent visual avatar selection. Presentation-only; gameplay pawn class remains authoritative. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Persistent visual avatar selection. Presentation-only; gameplay pawn class remains authoritative." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerWorldLocation_MetaData[] = {
		{ "Category", "Player World Location" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server-authored gameplay location used for first-spawn vs returning-player restore. Added in SaveGame schema v6. */" },
#endif
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-authored gameplay location used for first-spawn vs returning-player restore. Added in SaveGame schema v6." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonInventory_MetaData[] = {
		{ "Category", "Digimon" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonBank_MetaData[] = {
		{ "Category", "Digimon" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivePartnerInstanceId_MetaData[] = {
		{ "Category", "Digimon" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStarterSelected_MetaData[] = {
		{ "Category", "Digimon" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanData_MetaData[] = {
		{ "Category", "Progression" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Money_MetaData[] = {
		{ "Category", "Economy" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RankedBattlePoints_MetaData[] = {
		{ "Category", "Ranked" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RankedTier_MetaData[] = {
		{ "Category", "Ranked" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFAccountRecord constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Username;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CredentialDigest;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectedPlayerSkinId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerWorldLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInventory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DigimonInventory;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonBank_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DigimonBank;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActivePartnerInstanceId;
	static void NewProp_bStarterSelected_SetBit(void* Obj)
	{
		((FDMFAccountRecord*)Obj)->bStarterSelected = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStarterSelected;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ScanData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ScanData;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Money;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RankedBattlePoints;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RankedTier_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RankedTier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFAccountRecord constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFAccountRecord>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFAccountRecord Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Username = { "Username", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, Username), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Username_MetaData), NewProp_Username_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_CredentialDigest = { "CredentialDigest", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, CredentialDigest), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CredentialDigest_MetaData), NewProp_CredentialDigest_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SelectedPlayerSkinId = { "SelectedPlayerSkinId", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, SelectedPlayerSkinId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedPlayerSkinId_MetaData), NewProp_SelectedPlayerSkinId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PlayerWorldLocation = { "PlayerWorldLocation", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, PlayerWorldLocation), Z_Construct_UScriptStruct_FDMFPlayerWorldLocationState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerWorldLocation_MetaData), NewProp_PlayerWorldLocation_MetaData) }; // 3da1182c33c10c46f30ec4281e56989e564deb66
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInventory_Inner = { "DigimonInventory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(0, nullptr) }; // 90e3d7b8644ae8290e535284f655b83595374193
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_DigimonInventory = { "DigimonInventory", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, DigimonInventory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonInventory_MetaData), NewProp_DigimonInventory_MetaData) }; // 90e3d7b8644ae8290e535284f655b83595374193
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonBank_Inner = { "DigimonBank", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(0, nullptr) }; // 90e3d7b8644ae8290e535284f655b83595374193
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_DigimonBank = { "DigimonBank", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, DigimonBank), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonBank_MetaData), NewProp_DigimonBank_MetaData) }; // 90e3d7b8644ae8290e535284f655b83595374193
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ActivePartnerInstanceId = { "ActivePartnerInstanceId", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, ActivePartnerInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivePartnerInstanceId_MetaData), NewProp_ActivePartnerInstanceId_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bStarterSelected = { "bStarterSelected", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFAccountRecord), &UHT_STATICS::NewProp_bStarterSelected_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStarterSelected_MetaData), NewProp_bStarterSelected_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ScanData_Inner = { "ScanData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFScanDataEntry, METADATA_PARAMS(0, nullptr) }; // 59f4009213044f4b0a6d66fb70c1172b5bb2c761
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ScanData = { "ScanData", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, ScanData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanData_MetaData), NewProp_ScanData_MetaData) }; // 59f4009213044f4b0a6d66fb70c1172b5bb2c761
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_Money = { "Money", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, Money), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Money_MetaData), NewProp_Money_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_RankedBattlePoints = { "RankedBattlePoints", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, RankedBattlePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RankedBattlePoints_MetaData), NewProp_RankedBattlePoints_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_RankedTier_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_RankedTier = { "RankedTier", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFAccountRecord, RankedTier), Z_Construct_UEnum_DigimonMMOFramework_EDMFRankedTier, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RankedTier_MetaData), NewProp_RankedTier_MetaData) }; // 4d9e64bdb2b39496009abe633f2187584c439425
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Username,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CredentialDigest,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SelectedPlayerSkinId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerWorldLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInventory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonBank_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonBank,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActivePartnerInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bStarterSelected,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanData,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Money,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RankedBattlePoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RankedTier_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RankedTier,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFAccountRecord Property Definitions ******************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFAccountRecord",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFAccountRecord>(),
	alignof(FDMFAccountRecord),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFAccountRecord;
UScriptStruct* Z_Construct_UScriptStruct_FDMFAccountRecord(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFAccountRecord.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFAccountRecord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFAccountRecord, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFAccountRecord"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFAccountRecord.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFAccountRecord.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFAccountRecord.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFAccountRecord.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFAccountRecord ***************************************************

// ********** Begin ScriptStruct FDMFReplicatedDigimonEntry ****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFReplicatedDigimonEntry_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFReplicatedDigimonEntry>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFReplicatedDigimonEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Digimon_MetaData[] = {
		{ "Category", "DMFReplicatedDigimonEntry" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFReplicatedDigimonEntry constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Digimon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFReplicatedDigimonEntry constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFReplicatedDigimonEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS
static_assert(std::is_polymorphic<FDMFReplicatedDigimonEntry>() == std::is_polymorphic<FFastArraySerializerItem>(), "USTRUCT FDMFReplicatedDigimonEntry cannot be polymorphic unless super FFastArraySerializerItem is polymorphic");

// ********** Begin ScriptStruct FDMFReplicatedDigimonEntry Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Digimon = { "Digimon", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFReplicatedDigimonEntry, Digimon), Z_Construct_UScriptStruct_FDMFDigimonInstance, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Digimon_MetaData), NewProp_Digimon_MetaData) }; // 90e3d7b8644ae8290e535284f655b83595374193
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digimon,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFReplicatedDigimonEntry Property Definitions *********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	Z_Construct_UScriptStruct_FFastArraySerializerItem,
	&NewStructOps,
	"DMFReplicatedDigimonEntry",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFReplicatedDigimonEntry>(),
	alignof(FDMFReplicatedDigimonEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonEntry;
UScriptStruct* Z_Construct_UScriptStruct_FDMFReplicatedDigimonEntry(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonEntry.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFReplicatedDigimonEntry, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFReplicatedDigimonEntry"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonEntry.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonEntry.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonEntry.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFReplicatedDigimonEntry ******************************************

// ********** Begin ScriptStruct FDMFReplicatedDigimonList *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFReplicatedDigimonList_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFReplicatedDigimonList>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFReplicatedDigimonList); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "Category", "DMFReplicatedDigimonList" },
		{ "ModuleRelativePath", "Public/DMFTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFReplicatedDigimonList constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Items;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFReplicatedDigimonList constinit property declarations ***********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFReplicatedDigimonList>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS
static_assert(std::is_polymorphic<FDMFReplicatedDigimonList>() == std::is_polymorphic<FFastArraySerializer>(), "USTRUCT FDMFReplicatedDigimonList cannot be polymorphic unless super FFastArraySerializer is polymorphic");
#if defined(UE_NET_HAS_IRIS_FASTARRAY_BINDING) && UE_NET_HAS_IRIS_FASTARRAY_BINDING
UE_NET_IMPLEMENT_FASTARRAY(FDMFReplicatedDigimonList);
#else
UE_NET_IMPLEMENT_FASTARRAY_STUB(FDMFReplicatedDigimonList);
#endif

// ********** Begin ScriptStruct FDMFReplicatedDigimonList Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Items_Inner = { "Items", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFReplicatedDigimonEntry, METADATA_PARAMS(0, nullptr) }; // ef55f46d00d1b3f8c04f7159cd42027c54cad14a
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFReplicatedDigimonList, Items), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // ef55f46d00d1b3f8c04f7159cd42027c54cad14a
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Items_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Items,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFReplicatedDigimonList Property Definitions **********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	Z_Construct_UScriptStruct_FFastArraySerializer,
	&NewStructOps,
	"DMFReplicatedDigimonList",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFReplicatedDigimonList>(),
	alignof(FDMFReplicatedDigimonList),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonList;
UScriptStruct* Z_Construct_UScriptStruct_FDMFReplicatedDigimonList(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonList.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonList.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFReplicatedDigimonList, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFReplicatedDigimonList"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonList.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonList.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonList.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonList.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFReplicatedDigimonList *******************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_DMFTypes_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage, TEXT("EDMFDigimonStage"), &ZRIE_EDMFDigimonStage, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3786490922U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttribute, TEXT("EDMFDigimonAttribute"), &ZRIE_EDMFDigimonAttribute, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2643934090U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonElement, TEXT("EDMFDigimonElement"), &ZRIE_EDMFDigimonElement, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2271857953U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity, TEXT("EDMFWildSpawnRarity"), &ZRIE_EDMFWildSpawnRarity, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2039231156U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerInteractionType, TEXT("EDMFPlayerInteractionType"), &ZRIE_EDMFPlayerInteractionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 785946822U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFRankedTier, TEXT("EDMFRankedTier"), &ZRIE_EDMFRankedTier, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1302226109U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFWorldChatMessageType, TEXT("EDMFWorldChatMessageType"), &ZRIE_EDMFWorldChatMessageType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 928622462U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonMenuTab, TEXT("EDMFDigimonMenuTab"), &ZRIE_EDMFDigimonMenuTab, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1155505937U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation, TEXT("EDMFDigimonStorageLocation"), &ZRIE_EDMFDigimonStorageLocation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2383950102U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttributeStat, TEXT("EDMFDigimonAttributeStat"), &ZRIE_EDMFDigimonAttributeStat, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1166099646U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState, TEXT("EDMFMusicState"), &ZRIE_EDMFMusicState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4180201259U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFCombatState, TEXT("EDMFCombatState"), &ZRIE_EDMFCombatState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4086388659U) },
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFDamageScaling, TEXT("EDMFDamageScaling"), &ZRIE_EDMFDamageScaling, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1045003275U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDMFWorldChatMessage, Z_Construct_UScriptStruct_FDMFWorldChatMessage_Statics::NewStructOps, TEXT("DMFWorldChatMessage"),&Z_Registration_Info_UScriptStruct_FDMFWorldChatMessage, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFWorldChatMessage), 3165701840U) },
		{ Z_Construct_UScriptStruct_FDMFDigivolutionEvaluation, Z_Construct_UScriptStruct_FDMFDigivolutionEvaluation_Statics::NewStructOps, TEXT("DMFDigivolutionEvaluation"),&Z_Registration_Info_UScriptStruct_FDMFDigivolutionEvaluation, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigivolutionEvaluation), 3554612414U) },
		{ Z_Construct_UScriptStruct_FDMFDigimonStats, Z_Construct_UScriptStruct_FDMFDigimonStats_Statics::NewStructOps, TEXT("DMFDigimonStats"),&Z_Registration_Info_UScriptStruct_FDMFDigimonStats, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonStats), 1376484503U) },
		{ Z_Construct_UScriptStruct_FDMFDigimonCareState, Z_Construct_UScriptStruct_FDMFDigimonCareState_Statics::NewStructOps, TEXT("DMFDigimonCareState"),&Z_Registration_Info_UScriptStruct_FDMFDigimonCareState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonCareState), 1111692145U) },
		{ Z_Construct_UScriptStruct_FDMFDigimonInstance, Z_Construct_UScriptStruct_FDMFDigimonInstance_Statics::NewStructOps, TEXT("DMFDigimonInstance"),&Z_Registration_Info_UScriptStruct_FDMFDigimonInstance, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonInstance), 2430851000U) },
		{ Z_Construct_UScriptStruct_FDMFScanDataEntry, Z_Construct_UScriptStruct_FDMFScanDataEntry_Statics::NewStructOps, TEXT("DMFScanDataEntry"),&Z_Registration_Info_UScriptStruct_FDMFScanDataEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFScanDataEntry), 1509163154U) },
		{ Z_Construct_UScriptStruct_FDMFAbilityCooldownState, Z_Construct_UScriptStruct_FDMFAbilityCooldownState_Statics::NewStructOps, TEXT("DMFAbilityCooldownState"),&Z_Registration_Info_UScriptStruct_FDMFAbilityCooldownState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFAbilityCooldownState), 758764662U) },
		{ Z_Construct_UScriptStruct_FDMFBattleReward, Z_Construct_UScriptStruct_FDMFBattleReward_Statics::NewStructOps, TEXT("DMFBattleReward"),&Z_Registration_Info_UScriptStruct_FDMFBattleReward, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFBattleReward), 2382040011U) },
		{ Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression, Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression_Statics::NewStructOps, TEXT("DMFDigimonExperienceProgression"),&Z_Registration_Info_UScriptStruct_FDMFDigimonExperienceProgression, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigimonExperienceProgression), 2497719822U) },
		{ Z_Construct_UScriptStruct_FDMFPlayerWorldLocationState, Z_Construct_UScriptStruct_FDMFPlayerWorldLocationState_Statics::NewStructOps, TEXT("DMFPlayerWorldLocationState"),&Z_Registration_Info_UScriptStruct_FDMFPlayerWorldLocationState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFPlayerWorldLocationState), 1033967660U) },
		{ Z_Construct_UScriptStruct_FDMFAccountRecord, Z_Construct_UScriptStruct_FDMFAccountRecord_Statics::NewStructOps, TEXT("DMFAccountRecord"),&Z_Registration_Info_UScriptStruct_FDMFAccountRecord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFAccountRecord), 3938075674U) },
		{ Z_Construct_UScriptStruct_FDMFReplicatedDigimonEntry, Z_Construct_UScriptStruct_FDMFReplicatedDigimonEntry_Statics::NewStructOps, TEXT("DMFReplicatedDigimonEntry"),&Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFReplicatedDigimonEntry), 4015387757U) },
		{ Z_Construct_UScriptStruct_FDMFReplicatedDigimonList, Z_Construct_UScriptStruct_FDMFReplicatedDigimonList_Statics::NewStructOps, TEXT("DMFReplicatedDigimonList"),&Z_Registration_Info_UScriptStruct_FDMFReplicatedDigimonList, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFReplicatedDigimonList), 1241286755U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_DMFTypes_h__Script_DigimonMMOFramework_ee6e618c5c2a474f965913f31ce68271789124d3{
	TEXT("/Script/DigimonMMOFramework"),
	nullptr, 0,
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
