// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "DMFTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDigimonSpeciesData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UParticleSystem(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USoundBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonStats(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigivolutionRequirement(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttribute(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonElement(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonAbilityData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FDMFDigivolutionRequirement ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFDigivolutionRequirement_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFDigivolutionRequirement>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFDigivolutionRequirement); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSpecies_MetaData[] = {
		{ "Category", "Digivolution|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Destination form for this one-way Digivolution path. Cycles are supported only when deliberately authored. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Destination form for this one-way Digivolution path. Cycles are supported only when deliberately authored." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredLevel_MetaData[] = {
		{ "Category", "Digivolution|Requirements" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumABI_MetaData[] = {
		{ "Category", "Digivolution|Requirements" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumCAM_MetaData[] = {
		{ "Category", "Digivolution|Requirements" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireStats_MetaData[] = {
		{ "Category", "Digivolution|Requirements" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumStrength_MetaData[] = {
		{ "Category", "Digivolution|Requirements" },
		{ "ClampMin", "0" },
		{ "EditCondition", "bRequireStats" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumIntelligence_MetaData[] = {
		{ "Category", "Digivolution|Requirements" },
		{ "ClampMin", "0" },
		{ "EditCondition", "bRequireStats" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumDefense_MetaData[] = {
		{ "Category", "Digivolution|Requirements" },
		{ "ClampMin", "0" },
		{ "EditCondition", "bRequireStats" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumSpeed_MetaData[] = {
		{ "Category", "Digivolution|Requirements" },
		{ "ClampMin", "0" },
		{ "EditCondition", "bRequireStats" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireCare_MetaData[] = {
		{ "Category", "Digivolution|Requirements|Care" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional persistent Care gate for virtual-pet style evolution branches. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional persistent Care gate for virtual-pet style evolution branches." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumHappiness_MetaData[] = {
		{ "Category", "Digivolution|Requirements|Care" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bRequireCare" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumDiscipline_MetaData[] = {
		{ "Category", "Digivolution|Requirements|Care" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bRequireCare" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumCareMistakes_MetaData[] = {
		{ "Category", "Digivolution|Requirements|Care" },
		{ "ClampMin", "-1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** -1 disables the care-mistake ceiling. */" },
#endif
		{ "EditCondition", "bRequireCare" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "-1 disables the care-mistake ceiling." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoneyCost_MetaData[] = {
		{ "Category", "Digivolution|Requirements" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional account-money sink. Zero means no monetary requirement/cost. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional account-money sink. Zero means no monetary requirement/cost." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowFromBank_MetaData[] = {
		{ "Category", "Digivolution|Rules" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Allows this path to be executed while the individual is stored in Bank/Boxes. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allows this path to be executed while the individual is stored in Bank/Boxes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreserveStatInvestments_MetaData[] = {
		{ "Category", "Digivolution|Rules" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Preserve stat investment above the source species BaseStats and apply it to the destination BaseStats. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Preserve stat investment above the source species BaseStats and apply it to the destination BaseStats." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bReplaceEquippedAbilities_MetaData[] = {
		{ "Category", "Digivolution|Rules" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replace the four/equipped move list with target defaults. Disable to retain old moves and add target defaults. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replace the four/equipped move list with target defaults. Disable to retain old moves and add target defaults." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFullyRestoreVitals_MetaData[] = {
		{ "Category", "Digivolution|Rules" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Full HP/SP restoration on successful Digivolution. Disable to preserve the old HP/SP percentage. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Full HP/SP restoration on successful Digivolution. Disable to preserve the old HP/SP percentage." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraSystem_MetaData[] = {
		{ "Category", "Digivolution|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional path-specific presentation overrides; blank fields use the global Project Settings defaults. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional path-specific presentation overrides; blank fields use the global Project Settings defaults." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CascadeParticle_MetaData[] = {
		{ "Category", "Digivolution|Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[] = {
		{ "Category", "Digivolution|Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresentationDurationSeconds_MetaData[] = {
		{ "Category", "Digivolution|Presentation" },
		{ "ClampMax", "20.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Zero uses the global Digivolution Presentation Duration. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Zero uses the global Digivolution Presentation Duration." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFDigivolutionRequirement constinit property declarations *******
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_TargetSpecies;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequiredLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumABI;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumCAM;
	static void NewProp_bRequireStats_SetBit(void* Obj)
	{
		((FDMFDigivolutionRequirement*)Obj)->bRequireStats = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireStats;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumStrength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumIntelligence;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumDefense;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumSpeed;
	static void NewProp_bRequireCare_SetBit(void* Obj)
	{
		((FDMFDigivolutionRequirement*)Obj)->bRequireCare = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireCare;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumHappiness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumDiscipline;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumCareMistakes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_MoneyCost;
	static void NewProp_bAllowFromBank_SetBit(void* Obj)
	{
		((FDMFDigivolutionRequirement*)Obj)->bAllowFromBank = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowFromBank;
	static void NewProp_bPreserveStatInvestments_SetBit(void* Obj)
	{
		((FDMFDigivolutionRequirement*)Obj)->bPreserveStatInvestments = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreserveStatInvestments;
	static void NewProp_bReplaceEquippedAbilities_SetBit(void* Obj)
	{
		((FDMFDigivolutionRequirement*)Obj)->bReplaceEquippedAbilities = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bReplaceEquippedAbilities;
	static void NewProp_bFullyRestoreVitals_SetBit(void* Obj)
	{
		((FDMFDigivolutionRequirement*)Obj)->bFullyRestoreVitals = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFullyRestoreVitals;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_NiagaraSystem;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_CascadeParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Sound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PresentationDurationSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFDigivolutionRequirement constinit property declarations *********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFDigivolutionRequirement>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFDigivolutionRequirement Property Definitions ******************
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_TargetSpecies = { "TargetSpecies", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, TargetSpecies), Z_Construct_UClass_UDMFDigimonSpeciesData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSpecies_MetaData), NewProp_TargetSpecies_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_RequiredLevel = { "RequiredLevel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, RequiredLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredLevel_MetaData), NewProp_RequiredLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumABI = { "MinimumABI", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MinimumABI), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumABI_MetaData), NewProp_MinimumABI_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumCAM = { "MinimumCAM", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MinimumCAM), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumCAM_MetaData), NewProp_MinimumCAM_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequireStats = { "bRequireStats", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigivolutionRequirement), &UHT_STATICS::NewProp_bRequireStats_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireStats_MetaData), NewProp_bRequireStats_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumStrength = { "MinimumStrength", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MinimumStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumStrength_MetaData), NewProp_MinimumStrength_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumIntelligence = { "MinimumIntelligence", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MinimumIntelligence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumIntelligence_MetaData), NewProp_MinimumIntelligence_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumDefense = { "MinimumDefense", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MinimumDefense), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumDefense_MetaData), NewProp_MinimumDefense_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinimumSpeed = { "MinimumSpeed", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MinimumSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumSpeed_MetaData), NewProp_MinimumSpeed_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequireCare = { "bRequireCare", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigivolutionRequirement), &UHT_STATICS::NewProp_bRequireCare_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireCare_MetaData), NewProp_bRequireCare_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumHappiness = { "MinimumHappiness", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MinimumHappiness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumHappiness_MetaData), NewProp_MinimumHappiness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumDiscipline = { "MinimumDiscipline", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MinimumDiscipline), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumDiscipline_MetaData), NewProp_MinimumDiscipline_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaximumCareMistakes = { "MaximumCareMistakes", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MaximumCareMistakes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumCareMistakes_MetaData), NewProp_MaximumCareMistakes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_MoneyCost = { "MoneyCost", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, MoneyCost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoneyCost_MetaData), NewProp_MoneyCost_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAllowFromBank = { "bAllowFromBank", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigivolutionRequirement), &UHT_STATICS::NewProp_bAllowFromBank_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowFromBank_MetaData), NewProp_bAllowFromBank_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPreserveStatInvestments = { "bPreserveStatInvestments", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigivolutionRequirement), &UHT_STATICS::NewProp_bPreserveStatInvestments_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreserveStatInvestments_MetaData), NewProp_bPreserveStatInvestments_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bReplaceEquippedAbilities = { "bReplaceEquippedAbilities", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigivolutionRequirement), &UHT_STATICS::NewProp_bReplaceEquippedAbilities_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bReplaceEquippedAbilities_MetaData), NewProp_bReplaceEquippedAbilities_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bFullyRestoreVitals = { "bFullyRestoreVitals", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFDigivolutionRequirement), &UHT_STATICS::NewProp_bFullyRestoreVitals_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFullyRestoreVitals_MetaData), NewProp_bFullyRestoreVitals_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_NiagaraSystem = { "NiagaraSystem", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, NiagaraSystem), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraSystem_MetaData), NewProp_NiagaraSystem_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_CascadeParticle = { "CascadeParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, CascadeParticle), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CascadeParticle_MetaData), NewProp_CascadeParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, Sound), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sound_MetaData), NewProp_Sound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PresentationDurationSeconds = { "PresentationDurationSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFDigivolutionRequirement, PresentationDurationSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresentationDurationSeconds_MetaData), NewProp_PresentationDurationSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetSpecies,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RequiredLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumABI,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumCAM,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequireStats,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumIntelligence,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumDefense,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequireCare,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumHappiness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumDiscipline,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumCareMistakes,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MoneyCost,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAllowFromBank,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPreserveStatInvestments,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bReplaceEquippedAbilities,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bFullyRestoreVitals,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CascadeParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Sound,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresentationDurationSeconds,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFDigivolutionRequirement Property Definitions ********************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFDigivolutionRequirement",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFDigivolutionRequirement>(),
	alignof(FDMFDigivolutionRequirement),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFDigivolutionRequirement;
UScriptStruct* Z_Construct_UScriptStruct_FDMFDigivolutionRequirement(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFDigivolutionRequirement.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFDigivolutionRequirement.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFDigivolutionRequirement, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFDigivolutionRequirement"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFDigivolutionRequirement.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFDigivolutionRequirement.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFDigivolutionRequirement.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFDigivolutionRequirement.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFDigivolutionRequirement *****************************************

// ********** Begin Class UDMFDigimonSpeciesData ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFDigimonSpeciesData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/DMFDigimonSpeciesData.h" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesKey_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stage_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attribute_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Element_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowInDigiDex_MetaData[] = {
		{ "Category", "DigiDex" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Included in the read-only DigiDex registry by default. Disable only for internal/test species assets. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Included in the read-only DigiDex registry by default. Disable only for internal/test species assets." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiDexNumber_MetaData[] = {
		{ "Category", "DigiDex" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional stable project-authored DigiDex number. Zero uses the framework's deterministic fallback ordering. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional stable project-authored DigiDex number. Zero uses the framework's deterministic fallback ordering." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingLevel_MetaData[] = {
		{ "Category", "Progression" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseStats_MetaData[] = {
		{ "Category", "Progression" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributePointsPerLevel_MetaData[] = {
		{ "Category", "Progression" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingAbilityIds_MetaData[] = {
		{ "Category", "Abilities" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingAbilities_MetaData[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Preferred Blueprint-first ability references. IDs are still persisted per instance. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Preferred Blueprint-first ability references. IDs are still persisted per instance." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BasicAutoAttack_MetaData[] = {
		{ "Category", "Abilities" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleExperienceReward_MetaData[] = {
		{ "Category", "Battle Rewards" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleMoneyReward_MetaData[] = {
		{ "Category", "Battle Rewards" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bScanDataEnabled_MetaData[] = {
		{ "Category", "Scan & Materialization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether victories against this species can add account-owned Scan Data. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether victories against this species can add account-owned Scan Data." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleScanPercentReward_MetaData[] = {
		{ "Category", "Scan & Materialization" },
		{ "ClampMax", "999.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scan percentage awarded by one eligible authoritative victory. */" },
#endif
		{ "EditCondition", "bScanDataEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scan percentage awarded by one eligible authoritative victory." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanPercentCap_MetaData[] = {
		{ "Category", "Scan & Materialization" },
		{ "ClampMax", "999.0" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum Scan Data that may be stored for this species. Set above the requirement to bank multiple materializations. */" },
#endif
		{ "EditCondition", "bScanDataEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum Scan Data that may be stored for this species. Set above the requirement to bank multiple materializations." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bMaterializationEnabled_MetaData[] = {
		{ "Category", "Scan & Materialization" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterializationRequiredScanPercent_MetaData[] = {
		{ "Category", "Scan & Materialization" },
		{ "ClampMax", "999.0" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Amount consumed when this species is materialized into a permanent owned Digimon. */" },
#endif
		{ "EditCondition", "bMaterializationEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Amount consumed when this species is materialized into a permanent owned Digimon." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HPPerLevel_MetaData[] = {
		{ "Category", "Wild Scaling" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SPPerLevel_MetaData[] = {
		{ "Category", "Wild Scaling" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StrengthPerLevel_MetaData[] = {
		{ "Category", "Wild Scaling" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntelligencePerLevel_MetaData[] = {
		{ "Category", "Wild Scaling" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefensePerLevel_MetaData[] = {
		{ "Category", "Wild Scaling" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeedPerLevel_MetaData[] = {
		{ "Category", "Wild Scaling" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Digivolutions_MetaData[] = {
		{ "Category", "Digivolution" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldActorClass_MetaData[] = {
		{ "Category", "3D Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMesh_MetaData[] = {
		{ "Category", "3D Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Portrait_MetaData[] = {
		{ "Category", "3D Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack1Montage_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack2Montage_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeathMontage_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FeedingMontage_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCareEnabled_MetaData[] = {
		{ "Category", "Care" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master per-species care switch. Hunger, feeding and waste are ignored when disabled. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master per-species care switch. Hunger, feeding and waste are ignored when disabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingHungerPercent_MetaData[] = {
		{ "Category", "Care|Hunger" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** New Digimon begin at this Hunger percentage. In this framework, 100 means fully fed. */" },
#endif
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "New Digimon begin at this Hunger percentage. In this framework, 100 means fully fed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HungerDecayPercentPerHour_MetaData[] = {
		{ "Category", "Care|Hunger" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Real-time Hunger loss per hour, applied by the server and across offline time. */" },
#endif
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Real-time Hunger loss per hour, applied by the server and across offline time." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiMeatHungerPercentPerServing_MetaData[] = {
		{ "Category", "Care|Feeding" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hunger restored after one complete DigiMeat serving presentation. */" },
#endif
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hunger restored after one complete DigiMeat serving presentation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FeedingMontagePlaysPerServing_MetaData[] = {
		{ "Category", "Care|Feeding" },
		{ "ClampMax", "8" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The feeding Montage is replayed this many times consecutively for each serving. Default is exactly two. */" },
#endif
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The feeding Montage is replayed this many times consecutively for each serving. Default is exactly two." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FeedingMontagePlayRate_MetaData[] = {
		{ "Category", "Care|Feeding" },
		{ "ClampMax", "4.0" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiMeatHandSocketName_MetaData[] = {
		{ "Category", "Care|Feeding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text-writable skeletal socket/bone name used to attach DigiMeat to this species' hand. */" },
#endif
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text-writable skeletal socket/bone name used to attach DigiMeat to this species' hand." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiMeatMesh_MetaData[] = {
		{ "Category", "Care|Feeding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional species override. If empty, the framework Default DigiMeat Mesh is used. */" },
#endif
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional species override. If empty, the framework Default DigiMeat Mesh is used." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigiMeatRelativeTransform_MetaData[] = {
		{ "Category", "Care|Feeding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Per-species socket offset/rotation/scale. Scale is intentionally exposed because Digimon skeleton socket scales vary heavily. */" },
#endif
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-species socket offset/rotation/scale. Scale is intentionally exposed because Digimon skeleton socket scales vary heavily." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FeedingVoiceSounds_MetaData[] = {
		{ "Category", "Care|Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Dedicated eating voices. One deterministic index is chosen by the server per serving and multicast to viewers. */" },
#endif
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dedicated eating voices. One deterministic index is chosen by the server per serving and multicast to viewers." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWasteEnabled_MetaData[] = {
		{ "Category", "Care|Waste" },
		{ "EditCondition", "bCareEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumWasteDelaySeconds_MetaData[] = {
		{ "Category", "Care|Waste" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bCareEnabled && bWasteEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumWasteDelaySeconds_MetaData[] = {
		{ "Category", "Care|Waste" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bCareEnabled && bWasteEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PooMesh_MetaData[] = {
		{ "Category", "Care|Waste" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional species override. If empty, the framework Default Poo Mesh is used. */" },
#endif
		{ "EditCondition", "bCareEnabled && bWasteEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional species override. If empty, the framework Default Poo Mesh is used." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PooWorldScale_MetaData[] = {
		{ "Category", "Care|Waste" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World scale for the spawned poo actor. */" },
#endif
		{ "EditCondition", "bCareEnabled && bWasteEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World scale for the spawned poo actor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PooGroundOffset_MetaData[] = {
		{ "Category", "Care|Waste" },
		{ "ClampMax", "50.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Small offset along the traced ground normal to avoid z-fighting. */" },
#endif
		{ "EditCondition", "bCareEnabled && bWasteEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Small offset along the traced ground normal to avoid z-fighting." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PooLifetimeSeconds_MetaData[] = {
		{ "Category", "Care|Waste" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Automatic server-side cleanup lifetime for replicated poo. */" },
#endif
		{ "EditCondition", "bCareEnabled && bWasteEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatic server-side cleanup lifetime for replicated poo." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WasteFartSounds_MetaData[] = {
		{ "Category", "Care|Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional funny fart cues played for all relevant clients when this Digimon poops. */" },
#endif
		{ "EditCondition", "bCareEnabled && bWasteEnabled" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional funny fart cues played for all relevant clients when this Digimon poops." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractMontage_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WinMontage_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack1CascadeParticle_MetaData[] = {
		{ "Category", "VFX|Cascade" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack2CascadeParticle_MetaData[] = {
		{ "Category", "VFX|Cascade" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack1NiagaraParticle_MetaData[] = {
		{ "Category", "VFX|Niagara" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack2NiagaraParticle_MetaData[] = {
		{ "Category", "VFX|Niagara" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IdleVoiceSounds_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonSpeciesData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFDigimonSpeciesData constinit property declarations *******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_SpeciesKey;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Stage_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Stage;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Attribute_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Attribute;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Element_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Element;
	static void NewProp_bShowInDigiDex_SetBit(void* Obj)
	{
		((UDMFDigimonSpeciesData*)Obj)->bShowInDigiDex = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowInDigiDex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigiDexNumber;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartingLevel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BaseStats;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttributePointsPerLevel;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StartingAbilityIds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StartingAbilityIds;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_StartingAbilities_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StartingAbilities;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_BasicAutoAttack;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_BattleExperienceReward;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_BattleMoneyReward;
	static void NewProp_bScanDataEnabled_SetBit(void* Obj)
	{
		((UDMFDigimonSpeciesData*)Obj)->bScanDataEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bScanDataEnabled;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BattleScanPercentReward;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScanPercentCap;
	static void NewProp_bMaterializationEnabled_SetBit(void* Obj)
	{
		((UDMFDigimonSpeciesData*)Obj)->bMaterializationEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMaterializationEnabled;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaterializationRequiredScanPercent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_HPPerLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SPPerLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StrengthPerLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_IntelligencePerLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DefensePerLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SpeedPerLevel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Digivolutions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Digivolutions;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_WorldActorClass;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_PreviewMesh;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Portrait;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Attack1Montage;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Attack2Montage;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DeathMontage;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_FeedingMontage;
	static void NewProp_bCareEnabled_SetBit(void* Obj)
	{
		((UDMFDigimonSpeciesData*)Obj)->bCareEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCareEnabled;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartingHungerPercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HungerDecayPercentPerHour;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DigiMeatHungerPercentPerServing;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FeedingMontagePlaysPerServing;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FeedingMontagePlayRate;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DigiMeatHandSocketName;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DigiMeatMesh;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigiMeatRelativeTransform;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_FeedingVoiceSounds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FeedingVoiceSounds;
	static void NewProp_bWasteEnabled_SetBit(void* Obj)
	{
		((UDMFDigimonSpeciesData*)Obj)->bWasteEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasteEnabled;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumWasteDelaySeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumWasteDelaySeconds;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_PooMesh;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PooWorldScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PooGroundOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PooLifetimeSeconds;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_WasteFartSounds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_WasteFartSounds;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_InteractMontage;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_WinMontage;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Attack1CascadeParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Attack2CascadeParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Attack1NiagaraParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Attack2NiagaraParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_IdleVoiceSounds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_IdleVoiceSounds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFDigimonSpeciesData constinit property declarations *********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFDigimonSpeciesData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFDigimonSpeciesData Property Definitions ******************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_SpeciesKey = { "SpeciesKey", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, SpeciesKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesKey_MetaData), NewProp_SpeciesKey_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Stage_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Stage = { "Stage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Stage), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stage_MetaData), NewProp_Stage_MetaData) }; // e1b1442ac800f3afd36c160831786178fb89aaf0
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Attribute_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Attribute), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonAttribute, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attribute_MetaData), NewProp_Attribute_MetaData) }; // 9d973b8aedacba9214374b88283b5650f5088c09
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Element_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Element = { "Element", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Element), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonElement, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Element_MetaData), NewProp_Element_MetaData) }; // 8769cd2143b061114ef8acd938a8b19bb44c96aa
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShowInDigiDex = { "bShowInDigiDex", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonSpeciesData), &UHT_STATICS::NewProp_bShowInDigiDex_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowInDigiDex_MetaData), NewProp_bShowInDigiDex_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigiDexNumber = { "DigiDexNumber", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, DigiDexNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiDexNumber_MetaData), NewProp_DigiDexNumber_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_StartingLevel = { "StartingLevel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, StartingLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingLevel_MetaData), NewProp_StartingLevel_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_BaseStats = { "BaseStats", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, BaseStats), Z_Construct_UScriptStruct_FDMFDigimonStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseStats_MetaData), NewProp_BaseStats_MetaData) }; // 520b7c977c816e4f689d80785fbab8bbe48405a6
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_AttributePointsPerLevel = { "AttributePointsPerLevel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, AttributePointsPerLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributePointsPerLevel_MetaData), NewProp_AttributePointsPerLevel_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_StartingAbilityIds_Inner = { "StartingAbilityIds", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_StartingAbilityIds = { "StartingAbilityIds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, StartingAbilityIds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingAbilityIds_MetaData), NewProp_StartingAbilityIds_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_StartingAbilities_Inner = { "StartingAbilities", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMFDigimonAbilityData, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_StartingAbilities = { "StartingAbilities", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, StartingAbilities), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingAbilities_MetaData), NewProp_StartingAbilities_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_BasicAutoAttack = { "BasicAutoAttack", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, BasicAutoAttack), Z_Construct_UClass_UDMFDigimonAbilityData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BasicAutoAttack_MetaData), NewProp_BasicAutoAttack_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_BattleExperienceReward = { "BattleExperienceReward", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, BattleExperienceReward), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleExperienceReward_MetaData), NewProp_BattleExperienceReward_MetaData) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_BattleMoneyReward = { "BattleMoneyReward", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, BattleMoneyReward), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleMoneyReward_MetaData), NewProp_BattleMoneyReward_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bScanDataEnabled = { "bScanDataEnabled", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonSpeciesData), &UHT_STATICS::NewProp_bScanDataEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bScanDataEnabled_MetaData), NewProp_bScanDataEnabled_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BattleScanPercentReward = { "BattleScanPercentReward", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, BattleScanPercentReward), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleScanPercentReward_MetaData), NewProp_BattleScanPercentReward_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ScanPercentCap = { "ScanPercentCap", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, ScanPercentCap), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanPercentCap_MetaData), NewProp_ScanPercentCap_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bMaterializationEnabled = { "bMaterializationEnabled", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonSpeciesData), &UHT_STATICS::NewProp_bMaterializationEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bMaterializationEnabled_MetaData), NewProp_bMaterializationEnabled_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaterializationRequiredScanPercent = { "MaterializationRequiredScanPercent", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, MaterializationRequiredScanPercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterializationRequiredScanPercent_MetaData), NewProp_MaterializationRequiredScanPercent_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_HPPerLevel = { "HPPerLevel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, HPPerLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HPPerLevel_MetaData), NewProp_HPPerLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SPPerLevel = { "SPPerLevel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, SPPerLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SPPerLevel_MetaData), NewProp_SPPerLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_StrengthPerLevel = { "StrengthPerLevel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, StrengthPerLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StrengthPerLevel_MetaData), NewProp_StrengthPerLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_IntelligencePerLevel = { "IntelligencePerLevel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, IntelligencePerLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntelligencePerLevel_MetaData), NewProp_IntelligencePerLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DefensePerLevel = { "DefensePerLevel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, DefensePerLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefensePerLevel_MetaData), NewProp_DefensePerLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SpeedPerLevel = { "SpeedPerLevel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, SpeedPerLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeedPerLevel_MetaData), NewProp_SpeedPerLevel_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Digivolutions_Inner = { "Digivolutions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFDigivolutionRequirement, METADATA_PARAMS(0, nullptr) }; // 24ac0c23b01f89b5a251337a766dab2c270713d9
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Digivolutions = { "Digivolutions", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Digivolutions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Digivolutions_MetaData), NewProp_Digivolutions_MetaData) }; // 24ac0c23b01f89b5a251337a766dab2c270713d9
const UECodeGen_Private::FSoftClassPropertyParams UHT_STATICS::NewProp_WorldActorClass = { "WorldActorClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftClass, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, WorldActorClass), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldActorClass_MetaData), NewProp_WorldActorClass_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_PreviewMesh = { "PreviewMesh", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, PreviewMesh), Z_Construct_UClass_USkeletalMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMesh_MetaData), NewProp_PreviewMesh_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Portrait = { "Portrait", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Portrait), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Portrait_MetaData), NewProp_Portrait_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Attack1Montage = { "Attack1Montage", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Attack1Montage), Z_Construct_UClass_UAnimMontage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack1Montage_MetaData), NewProp_Attack1Montage_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Attack2Montage = { "Attack2Montage", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Attack2Montage), Z_Construct_UClass_UAnimMontage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack2Montage_MetaData), NewProp_Attack2Montage_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_DeathMontage = { "DeathMontage", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, DeathMontage), Z_Construct_UClass_UAnimMontage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeathMontage_MetaData), NewProp_DeathMontage_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_FeedingMontage = { "FeedingMontage", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, FeedingMontage), Z_Construct_UClass_UAnimMontage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FeedingMontage_MetaData), NewProp_FeedingMontage_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCareEnabled = { "bCareEnabled", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonSpeciesData), &UHT_STATICS::NewProp_bCareEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCareEnabled_MetaData), NewProp_bCareEnabled_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_StartingHungerPercent = { "StartingHungerPercent", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, StartingHungerPercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingHungerPercent_MetaData), NewProp_StartingHungerPercent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_HungerDecayPercentPerHour = { "HungerDecayPercentPerHour", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, HungerDecayPercentPerHour), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HungerDecayPercentPerHour_MetaData), NewProp_HungerDecayPercentPerHour_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DigiMeatHungerPercentPerServing = { "DigiMeatHungerPercentPerServing", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, DigiMeatHungerPercentPerServing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiMeatHungerPercentPerServing_MetaData), NewProp_DigiMeatHungerPercentPerServing_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_FeedingMontagePlaysPerServing = { "FeedingMontagePlaysPerServing", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, FeedingMontagePlaysPerServing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FeedingMontagePlaysPerServing_MetaData), NewProp_FeedingMontagePlaysPerServing_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FeedingMontagePlayRate = { "FeedingMontagePlayRate", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, FeedingMontagePlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FeedingMontagePlayRate_MetaData), NewProp_FeedingMontagePlayRate_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_DigiMeatHandSocketName = { "DigiMeatHandSocketName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, DigiMeatHandSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiMeatHandSocketName_MetaData), NewProp_DigiMeatHandSocketName_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_DigiMeatMesh = { "DigiMeatMesh", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, DigiMeatMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiMeatMesh_MetaData), NewProp_DigiMeatMesh_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigiMeatRelativeTransform = { "DigiMeatRelativeTransform", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, DigiMeatRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigiMeatRelativeTransform_MetaData), NewProp_DigiMeatRelativeTransform_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_FeedingVoiceSounds_Inner = { "FeedingVoiceSounds", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, 0, Z_Construct_UClass_USoundBase, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_FeedingVoiceSounds = { "FeedingVoiceSounds", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, FeedingVoiceSounds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FeedingVoiceSounds_MetaData), NewProp_FeedingVoiceSounds_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bWasteEnabled = { "bWasteEnabled", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonSpeciesData), &UHT_STATICS::NewProp_bWasteEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWasteEnabled_MetaData), NewProp_bWasteEnabled_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumWasteDelaySeconds = { "MinimumWasteDelaySeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, MinimumWasteDelaySeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumWasteDelaySeconds_MetaData), NewProp_MinimumWasteDelaySeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumWasteDelaySeconds = { "MaximumWasteDelaySeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, MaximumWasteDelaySeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumWasteDelaySeconds_MetaData), NewProp_MaximumWasteDelaySeconds_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_PooMesh = { "PooMesh", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, PooMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PooMesh_MetaData), NewProp_PooMesh_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PooWorldScale = { "PooWorldScale", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, PooWorldScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PooWorldScale_MetaData), NewProp_PooWorldScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PooGroundOffset = { "PooGroundOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, PooGroundOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PooGroundOffset_MetaData), NewProp_PooGroundOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PooLifetimeSeconds = { "PooLifetimeSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, PooLifetimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PooLifetimeSeconds_MetaData), NewProp_PooLifetimeSeconds_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_WasteFartSounds_Inner = { "WasteFartSounds", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, 0, Z_Construct_UClass_USoundBase, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_WasteFartSounds = { "WasteFartSounds", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, WasteFartSounds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WasteFartSounds_MetaData), NewProp_WasteFartSounds_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_InteractMontage = { "InteractMontage", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, InteractMontage), Z_Construct_UClass_UAnimMontage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractMontage_MetaData), NewProp_InteractMontage_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_WinMontage = { "WinMontage", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, WinMontage), Z_Construct_UClass_UAnimMontage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WinMontage_MetaData), NewProp_WinMontage_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Attack1CascadeParticle = { "Attack1CascadeParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Attack1CascadeParticle), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack1CascadeParticle_MetaData), NewProp_Attack1CascadeParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Attack2CascadeParticle = { "Attack2CascadeParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Attack2CascadeParticle), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack2CascadeParticle_MetaData), NewProp_Attack2CascadeParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Attack1NiagaraParticle = { "Attack1NiagaraParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Attack1NiagaraParticle), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack1NiagaraParticle_MetaData), NewProp_Attack1NiagaraParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Attack2NiagaraParticle = { "Attack2NiagaraParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, Attack2NiagaraParticle), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack2NiagaraParticle_MetaData), NewProp_Attack2NiagaraParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_IdleVoiceSounds_Inner = { "IdleVoiceSounds", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, 0, Z_Construct_UClass_USoundBase, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_IdleVoiceSounds = { "IdleVoiceSounds", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonSpeciesData, IdleVoiceSounds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IdleVoiceSounds_MetaData), NewProp_IdleVoiceSounds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Stage_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Stage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Attribute_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Attribute,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Element_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Element,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShowInDigiDex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiDexNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartingLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BaseStats,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AttributePointsPerLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartingAbilityIds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartingAbilityIds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartingAbilities_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartingAbilities,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BasicAutoAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BattleExperienceReward,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BattleMoneyReward,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bScanDataEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BattleScanPercentReward,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanPercentCap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bMaterializationEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterializationRequiredScanPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HPPerLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SPPerLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StrengthPerLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_IntelligencePerLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefensePerLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeedPerLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digivolutions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Digivolutions,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviewMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Portrait,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Attack1Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Attack2Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DeathMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FeedingMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCareEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartingHungerPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HungerDecayPercentPerHour,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiMeatHungerPercentPerServing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FeedingMontagePlaysPerServing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FeedingMontagePlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiMeatHandSocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiMeatMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigiMeatRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FeedingVoiceSounds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FeedingVoiceSounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bWasteEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumWasteDelaySeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumWasteDelaySeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PooMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PooWorldScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PooGroundOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PooLifetimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WasteFartSounds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WasteFartSounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InteractMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WinMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Attack1CascadeParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Attack2CascadeParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Attack1NiagaraParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Attack2NiagaraParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_IdleVoiceSounds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_IdleVoiceSounds,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFDigimonSpeciesData Property Definitions ********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UPrimaryDataAsset,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFDigimonSpeciesData,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFDigimonSpeciesData;
UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFDigimonSpeciesData;
		if (!Z_Registration_Info_UClass_UDMFDigimonSpeciesData.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonSpeciesData"),
				Z_Registration_Info_UClass_UDMFDigimonSpeciesData.InnerSingleton,
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
		return Z_Registration_Info_UClass_UDMFDigimonSpeciesData.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFDigimonSpeciesData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFDigimonSpeciesData.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFDigimonSpeciesData.OuterSingleton;
}
#undef UHT_STATICS
UDMFDigimonSpeciesData::UDMFDigimonSpeciesData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFDigimonSpeciesData);
UDMFDigimonSpeciesData::~UDMFDigimonSpeciesData() {}
// ********** End Class UDMFDigimonSpeciesData *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFDigimonSpeciesData_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDMFDigivolutionRequirement, Z_Construct_UScriptStruct_FDMFDigivolutionRequirement_Statics::NewStructOps, TEXT("DMFDigivolutionRequirement"),&Z_Registration_Info_UScriptStruct_FDMFDigivolutionRequirement, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFDigivolutionRequirement), 615255075U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFDigimonSpeciesData, TEXT("UDMFDigimonSpeciesData"), &Z_Registration_Info_UClass_UDMFDigimonSpeciesData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFDigimonSpeciesData), 3059787566U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFDigimonSpeciesData_h__Script_DigimonMMOFramework_200c1745f1eb221fc3d67b75cde800aa27dbaa37{
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
