// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/DMFDigimonAbilityData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDigimonAbilityData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UParticleSystem(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USoundBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonAbilityData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDamageScaling(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonAbilityData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFDigimonAbilityData ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFDigimonAbilityData_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server-authoritative combat ability definition.\n * Gameplay fields are consumed only by the authority. Presentation fields are used by the\n * replicated cosmetic cue so Blueprint projects can replace visuals without changing combat math.\n */" },
#endif
		{ "IncludePath", "Data/DMFDigimonAbilityData.h" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-authoritative combat ability definition.\nGameplay fields are consumed only by the authority. Presentation fields are used by the\nreplicated cosmetic cue so Blueprint projects can replace visuals without changing combat math." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityId_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SPCost_MetaData[] = {
		{ "Category", "Cost" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownSeconds_MetaData[] = {
		{ "Category", "Timing" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactDelaySeconds_MetaData[] = {
		{ "Category", "Timing" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecoverySeconds_MetaData[] = {
		{ "Category", "Timing" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRange_MetaData[] = {
		{ "Category", "Targeting" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequiresTarget_MetaData[] = {
		{ "Category", "Targeting" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BasePower_MetaData[] = {
		{ "Category", "Damage" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScalingStat_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatScaling_MetaData[] = {
		{ "Category", "Damage" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefenseScaling_MetaData[] = {
		{ "Category", "Damage" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEligibleForAutoBattle_MetaData[] = {
		{ "Category", "Automation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Montage_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CascadeParticle_MetaData[] = {
		{ "Category", "Presentation|Cascade" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraParticle_MetaData[] = {
		{ "Category", "Presentation|Niagara" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackSound_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VFXSocketName_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSpawnVFXAtTarget_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFDigimonAbilityData constinit property declarations *******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SPCost;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ImpactDelaySeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RecoverySeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRange;
	static void NewProp_bRequiresTarget_SetBit(void* Obj)
	{
		((UDMFDigimonAbilityData*)Obj)->bRequiresTarget = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequiresTarget;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BasePower;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ScalingStat_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ScalingStat;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StatScaling;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefenseScaling;
	static void NewProp_bEligibleForAutoBattle_SetBit(void* Obj)
	{
		((UDMFDigimonAbilityData*)Obj)->bEligibleForAutoBattle = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEligibleForAutoBattle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Montage;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_CascadeParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_NiagaraParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_AttackSound;
	static const UECodeGen_Private::FNamePropertyParams NewProp_VFXSocketName;
	static void NewProp_bSpawnVFXAtTarget_SetBit(void* Obj)
	{
		((UDMFDigimonAbilityData*)Obj)->bSpawnVFXAtTarget = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSpawnVFXAtTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFDigimonAbilityData constinit property declarations *********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFDigimonAbilityData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFDigimonAbilityData Property Definitions ******************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, AbilityId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityId_MetaData), NewProp_AbilityId_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, Icon), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SPCost = { "SPCost", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, SPCost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SPCost_MetaData), NewProp_SPCost_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CooldownSeconds = { "CooldownSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, CooldownSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownSeconds_MetaData), NewProp_CooldownSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ImpactDelaySeconds = { "ImpactDelaySeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ImpactDelaySeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactDelaySeconds_MetaData), NewProp_ImpactDelaySeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_RecoverySeconds = { "RecoverySeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, RecoverySeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecoverySeconds_MetaData), NewProp_RecoverySeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaxRange = { "MaxRange", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, MaxRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRange_MetaData), NewProp_MaxRange_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequiresTarget = { "bRequiresTarget", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonAbilityData), &UHT_STATICS::NewProp_bRequiresTarget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequiresTarget_MetaData), NewProp_bRequiresTarget_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BasePower = { "BasePower", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, BasePower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BasePower_MetaData), NewProp_BasePower_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ScalingStat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ScalingStat = { "ScalingStat", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ScalingStat), Z_Construct_UEnum_DigimonMMOFramework_EDMFDamageScaling, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScalingStat_MetaData), NewProp_ScalingStat_MetaData) }; // 3e497c0b3bff1d5634b765510c09e623b283b411
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_StatScaling = { "StatScaling", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, StatScaling), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatScaling_MetaData), NewProp_StatScaling_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DefenseScaling = { "DefenseScaling", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, DefenseScaling), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefenseScaling_MetaData), NewProp_DefenseScaling_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEligibleForAutoBattle = { "bEligibleForAutoBattle", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonAbilityData), &UHT_STATICS::NewProp_bEligibleForAutoBattle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEligibleForAutoBattle_MetaData), NewProp_bEligibleForAutoBattle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, Montage), Z_Construct_UClass_UAnimMontage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Montage_MetaData), NewProp_Montage_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_CascadeParticle = { "CascadeParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, CascadeParticle), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CascadeParticle_MetaData), NewProp_CascadeParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_NiagaraParticle = { "NiagaraParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, NiagaraParticle), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraParticle_MetaData), NewProp_NiagaraParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_AttackSound = { "AttackSound", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, AttackSound), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackSound_MetaData), NewProp_AttackSound_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_VFXSocketName = { "VFXSocketName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, VFXSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VFXSocketName_MetaData), NewProp_VFXSocketName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSpawnVFXAtTarget = { "bSpawnVFXAtTarget", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonAbilityData), &UHT_STATICS::NewProp_bSpawnVFXAtTarget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSpawnVFXAtTarget_MetaData), NewProp_bSpawnVFXAtTarget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SPCost,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CooldownSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ImpactDelaySeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RecoverySeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequiresTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BasePower,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScalingStat_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScalingStat,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StatScaling,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefenseScaling,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEligibleForAutoBattle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CascadeParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NiagaraParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AttackSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VFXSocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSpawnVFXAtTarget,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFDigimonAbilityData Property Definitions ********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UPrimaryDataAsset,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFDigimonAbilityData,
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
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFDigimonAbilityData;
UClass* Z_Construct_UClass_UDMFDigimonAbilityData(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFDigimonAbilityData;
		if (!Z_Registration_Info_UClass_UDMFDigimonAbilityData.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonAbilityData"),
				Z_Registration_Info_UClass_UDMFDigimonAbilityData.InnerSingleton,
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
		return Z_Registration_Info_UClass_UDMFDigimonAbilityData.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFDigimonAbilityData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFDigimonAbilityData.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFDigimonAbilityData.OuterSingleton;
}
#undef UHT_STATICS
UDMFDigimonAbilityData::UDMFDigimonAbilityData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFDigimonAbilityData);
UDMFDigimonAbilityData::~UDMFDigimonAbilityData() {}
// ********** End Class UDMFDigimonAbilityData *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFDigimonAbilityData_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFDigimonAbilityData, TEXT("UDMFDigimonAbilityData"), &Z_Registration_Info_UClass_UDMFDigimonAbilityData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFDigimonAbilityData), 1139486800U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFDigimonAbilityData_h__Script_DigimonMMOFramework_8aaec5bdbb204e2030f03e70789e6e1bfcb70626{
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
