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
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UClass(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UParticleSystem(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USoundBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonAbilityData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFAbilityExecutionMode(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDamageScaling(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFAbilityProjectileActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonAbilityData(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EDMFAbilityExecutionMode **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFAbilityExecutionMode_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFAbilityExecutionMode>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFAbilityExecutionMode(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Determines how an authoritative ability reaches its target.\n * TimedImpact preserves the original v0.x behavior. Projectile launches a replicated world actor\n * whose arrival owns the authoritative damage timing.\n */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
		{ "Projectile.DisplayName", "Replicated Projectile" },
		{ "Projectile.Name", "EDMFAbilityExecutionMode::Projectile" },
		{ "TimedImpact.DisplayName", "Timed / Instant Impact" },
		{ "TimedImpact.Name", "EDMFAbilityExecutionMode::TimedImpact" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Determines how an authoritative ability reaches its target.\nTimedImpact preserves the original v0.x behavior. Projectile launches a replicated world actor\nwhose arrival owns the authoritative damage timing." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFAbilityExecutionMode::TimedImpact", (int64)EDMFAbilityExecutionMode::TimedImpact },
		{ "EDMFAbilityExecutionMode::Projectile", (int64)EDMFAbilityExecutionMode::Projectile },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFAbilityExecutionMode",
	"EDMFAbilityExecutionMode",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFAbilityExecutionMode;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFAbilityExecutionMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFAbilityExecutionMode.OuterSingleton)
		{
			ZRIE_EDMFAbilityExecutionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFAbilityExecutionMode, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFAbilityExecutionMode"));
		}
		return ZRIE_EDMFAbilityExecutionMode.OuterSingleton;
	}
	if (!ZRIE_EDMFAbilityExecutionMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFAbilityExecutionMode.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFAbilityExecutionMode.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFAbilityExecutionMode ****************************************************

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
		{ "Comment", "/**\n * Server-authoritative combat ability definition.\n * Gameplay fields are consumed only by the authority. Presentation fields are used by replicated\n * cosmetic cues or the replicated projectile actor so Blueprint projects can replace visuals\n * without changing combat math.\n */" },
#endif
		{ "IncludePath", "Data/DMFDigimonAbilityData.h" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-authoritative combat ability definition.\nGameplay fields are consumed only by the authority. Presentation fields are used by replicated\ncosmetic cues or the replicated projectile actor so Blueprint projects can replace visuals\nwithout changing combat math." },
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Timed Impact: delay before authoritative damage.\n     * Replicated Projectile: delay before the server launches the projectile from its spawn socket.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Timed Impact: delay before authoritative damage.\nReplicated Projectile: delay before the server launches the projectile from its spawn socket." },
#endif
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecutionMode_MetaData[] = {
		{ "Category", "Execution" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Montage_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CascadeParticle_MetaData[] = {
		{ "Category", "Presentation|Cascade" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Timed-impact VFX. In Projectile mode these become the projectile visual fallback when the dedicated projectile VFX fields are empty. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Timed-impact VFX. In Projectile mode these become the projectile visual fallback when the dedicated projectile VFX fields are empty." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraParticle_MetaData[] = {
		{ "Category", "Presentation|Niagara" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Timed-impact VFX. In Projectile mode this becomes the projectile visual fallback when Projectile Niagara System is empty. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Timed-impact VFX. In Projectile mode this becomes the projectile visual fallback when Projectile Niagara System is empty." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackSound_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VFXSocketName_MetaData[] = {
		{ "Category", "Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Socket for timed presentation VFX and the default projectile launch origin. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Socket for timed presentation VFX and the default projectile launch origin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSpawnVFXAtTarget_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresentationVFXLifetimeSeconds_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ClampMax", "30.0" },
		{ "ClampMin", "0.05" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Forced lifetime for transient non-projectile Niagara/Cascade cues, including looping systems. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Forced lifetime for transient non-projectile Niagara/Cascade cues, including looping systems." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresentationVFXRotationOffset_MetaData[] = {
		{ "Category", "Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Applied to transient timed-impact VFX after the framework rotates the cue toward the target. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Applied to transient timed-impact VFX after the framework rotates the cue toward the target." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresentationVFXScale_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Projectile|Class" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional Blueprint subclass. Empty uses the native DMF Ability Projectile Actor. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional Blueprint subclass. Empty uses the native DMF Ability Projectile Actor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileNiagaraSystem_MetaData[] = {
		{ "Category", "Projectile|Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Dedicated moving Niagara visual. Empty falls back to Niagara Particle above. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dedicated moving Niagara visual. Empty falls back to Niagara Particle above." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileCascadeParticle_MetaData[] = {
		{ "Category", "Projectile|Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Dedicated moving Cascade visual. Used when Niagara is unavailable. Empty falls back to Cascade Particle above. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dedicated moving Cascade visual. Used when Niagara is unavailable. Empty falls back to Cascade Particle above." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileStaticMesh_MetaData[] = {
		{ "Category", "Projectile|Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional mesh carried by the projectile in addition to Niagara/Cascade. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional mesh carried by the projectile in addition to Niagara/Cascade." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileVisualRotationOffset_MetaData[] = {
		{ "Category", "Projectile|Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Corrects assets authored along a local axis other than Unreal forward (+X). */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Corrects assets authored along a local axis other than Unreal forward (+X)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileVisualScale_MetaData[] = {
		{ "Category", "Projectile|Visual" },
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileSpawnSocketName_MetaData[] = {
		{ "Category", "Projectile|Launch" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional projectile-only spawn socket. NAME_None falls back to VFX Socket Name, then the Digimon actor origin. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional projectile-only spawn socket. NAME_None falls back to VFX Socket Name, then the Digimon actor origin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileSpawnOffset_MetaData[] = {
		{ "Category", "Projectile|Launch" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local-space offset from the selected launch socket/actor transform. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local-space offset from the selected launch socket/actor transform." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileSpeed_MetaData[] = {
		{ "Category", "Projectile|Movement" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bProjectileHoming_MetaData[] = {
		{ "Category", "Projectile|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When true the authoritative projectile turns toward the moving target during flight. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When true the authoritative projectile turns toward the moving target during flight." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileHomingTurnRateDegrees_MetaData[] = {
		{ "Category", "Projectile|Movement" },
		{ "ClampMax", "10000.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum homing turn rate in degrees per second. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum homing turn rate in degrees per second." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileTargetOffset_MetaData[] = {
		{ "Category", "Projectile|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Offset applied to the target actor location when calculating projectile aim. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Offset applied to the target actor location when calculating projectile aim." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileImpactRadius_MetaData[] = {
		{ "Category", "Projectile|Impact" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Radius around the target aim point that counts as an authoritative projectile arrival. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Radius around the target aim point that counts as an authoritative projectile arrival." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMaxLifetimeSeconds_MetaData[] = {
		{ "Category", "Projectile|Impact" },
		{ "ClampMax", "60.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hard cleanup guard. Projectile actor and all attached VFX are destroyed after this many seconds even if no impact occurs. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hard cleanup guard. Projectile actor and all attached VFX are destroyed after this many seconds even if no impact occurs." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileImpactNiagaraSystem_MetaData[] = {
		{ "Category", "Projectile|Impact" },
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileImpactCascadeParticle_MetaData[] = {
		{ "Category", "Projectile|Impact" },
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileImpactSound_MetaData[] = {
		{ "Category", "Projectile|Impact" },
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileImpactVFXLifetimeSeconds_MetaData[] = {
		{ "Category", "Projectile|Impact" },
		{ "ClampMax", "30.0" },
		{ "ClampMin", "0.05" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Forced cleanup lifetime for impact Niagara/Cascade, including accidentally looping systems. */" },
#endif
		{ "EditCondition", "ExecutionMode == EDMFAbilityExecutionMode::Projectile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Data/DMFDigimonAbilityData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Forced cleanup lifetime for impact Niagara/Cascade, including accidentally looping systems." },
#endif
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
	static const UECodeGen_Private::FBytePropertyParams NewProp_ExecutionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ExecutionMode;
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
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PresentationVFXLifetimeSeconds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PresentationVFXRotationOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PresentationVFXScale;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ProjectileClass;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ProjectileNiagaraSystem;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ProjectileCascadeParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ProjectileStaticMesh;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectileVisualRotationOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectileVisualScale;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ProjectileSpawnSocketName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectileSpawnOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileSpeed;
	static void NewProp_bProjectileHoming_SetBit(void* Obj)
	{
		((UDMFDigimonAbilityData*)Obj)->bProjectileHoming = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bProjectileHoming;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileHomingTurnRateDegrees;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectileTargetOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileImpactRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileMaxLifetimeSeconds;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ProjectileImpactNiagaraSystem;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ProjectileImpactCascadeParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ProjectileImpactSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileImpactVFXLifetimeSeconds;
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
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ExecutionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ExecutionMode = { "ExecutionMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ExecutionMode), Z_Construct_UEnum_DigimonMMOFramework_EDMFAbilityExecutionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecutionMode_MetaData), NewProp_ExecutionMode_MetaData) }; // 240851f45ce9333e4fae37a4d84795e5a98cb6db
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, Montage), Z_Construct_UClass_UAnimMontage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Montage_MetaData), NewProp_Montage_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_CascadeParticle = { "CascadeParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, CascadeParticle), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CascadeParticle_MetaData), NewProp_CascadeParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_NiagaraParticle = { "NiagaraParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, NiagaraParticle), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraParticle_MetaData), NewProp_NiagaraParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_AttackSound = { "AttackSound", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, AttackSound), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackSound_MetaData), NewProp_AttackSound_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_VFXSocketName = { "VFXSocketName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, VFXSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VFXSocketName_MetaData), NewProp_VFXSocketName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSpawnVFXAtTarget = { "bSpawnVFXAtTarget", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonAbilityData), &UHT_STATICS::NewProp_bSpawnVFXAtTarget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSpawnVFXAtTarget_MetaData), NewProp_bSpawnVFXAtTarget_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PresentationVFXLifetimeSeconds = { "PresentationVFXLifetimeSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, PresentationVFXLifetimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresentationVFXLifetimeSeconds_MetaData), NewProp_PresentationVFXLifetimeSeconds_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PresentationVFXRotationOffset = { "PresentationVFXRotationOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, PresentationVFXRotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresentationVFXRotationOffset_MetaData), NewProp_PresentationVFXRotationOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PresentationVFXScale = { "PresentationVFXScale", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, PresentationVFXScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresentationVFXScale_MetaData), NewProp_PresentationVFXScale_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams UHT_STATICS::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftClass, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileClass), Z_Construct_UClass_ADMFAbilityProjectileActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileClass_MetaData), NewProp_ProjectileClass_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_ProjectileNiagaraSystem = { "ProjectileNiagaraSystem", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileNiagaraSystem), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileNiagaraSystem_MetaData), NewProp_ProjectileNiagaraSystem_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_ProjectileCascadeParticle = { "ProjectileCascadeParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileCascadeParticle), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileCascadeParticle_MetaData), NewProp_ProjectileCascadeParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_ProjectileStaticMesh = { "ProjectileStaticMesh", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileStaticMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileStaticMesh_MetaData), NewProp_ProjectileStaticMesh_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ProjectileVisualRotationOffset = { "ProjectileVisualRotationOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileVisualRotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileVisualRotationOffset_MetaData), NewProp_ProjectileVisualRotationOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ProjectileVisualScale = { "ProjectileVisualScale", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileVisualScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileVisualScale_MetaData), NewProp_ProjectileVisualScale_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_ProjectileSpawnSocketName = { "ProjectileSpawnSocketName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileSpawnSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileSpawnSocketName_MetaData), NewProp_ProjectileSpawnSocketName_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ProjectileSpawnOffset = { "ProjectileSpawnOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileSpawnOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileSpawnOffset_MetaData), NewProp_ProjectileSpawnOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ProjectileSpeed = { "ProjectileSpeed", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileSpeed_MetaData), NewProp_ProjectileSpeed_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bProjectileHoming = { "bProjectileHoming", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFDigimonAbilityData), &UHT_STATICS::NewProp_bProjectileHoming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bProjectileHoming_MetaData), NewProp_bProjectileHoming_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ProjectileHomingTurnRateDegrees = { "ProjectileHomingTurnRateDegrees", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileHomingTurnRateDegrees), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileHomingTurnRateDegrees_MetaData), NewProp_ProjectileHomingTurnRateDegrees_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ProjectileTargetOffset = { "ProjectileTargetOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileTargetOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileTargetOffset_MetaData), NewProp_ProjectileTargetOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ProjectileImpactRadius = { "ProjectileImpactRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileImpactRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileImpactRadius_MetaData), NewProp_ProjectileImpactRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ProjectileMaxLifetimeSeconds = { "ProjectileMaxLifetimeSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileMaxLifetimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileMaxLifetimeSeconds_MetaData), NewProp_ProjectileMaxLifetimeSeconds_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_ProjectileImpactNiagaraSystem = { "ProjectileImpactNiagaraSystem", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileImpactNiagaraSystem), Z_Construct_UClass_UNiagaraSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileImpactNiagaraSystem_MetaData), NewProp_ProjectileImpactNiagaraSystem_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_ProjectileImpactCascadeParticle = { "ProjectileImpactCascadeParticle", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileImpactCascadeParticle), Z_Construct_UClass_UParticleSystem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileImpactCascadeParticle_MetaData), NewProp_ProjectileImpactCascadeParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_ProjectileImpactSound = { "ProjectileImpactSound", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileImpactSound), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileImpactSound_MetaData), NewProp_ProjectileImpactSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ProjectileImpactVFXLifetimeSeconds = { "ProjectileImpactVFXLifetimeSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonAbilityData, ProjectileImpactVFXLifetimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileImpactVFXLifetimeSeconds_MetaData), NewProp_ProjectileImpactVFXLifetimeSeconds_MetaData) };
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
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExecutionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExecutionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CascadeParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NiagaraParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AttackSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VFXSocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSpawnVFXAtTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresentationVFXLifetimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresentationVFXRotationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresentationVFXScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileNiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileCascadeParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileStaticMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileVisualRotationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileVisualScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileSpawnSocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileSpawnOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bProjectileHoming,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileHomingTurnRateDegrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileTargetOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileImpactRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileMaxLifetimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileImpactNiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileImpactCascadeParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileImpactSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileImpactVFXLifetimeSeconds,
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
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFAbilityExecutionMode, TEXT("EDMFAbilityExecutionMode"), &ZRIE_EDMFAbilityExecutionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 604525044U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFDigimonAbilityData, TEXT("UDMFDigimonAbilityData"), &Z_Registration_Info_UClass_UDMFDigimonAbilityData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFDigimonAbilityData), 4163631760U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Data_DMFDigimonAbilityData_h__Script_DigimonMMOFramework_76f09a99323a9bb10d0337f5f4cee19f71814dfd{
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
