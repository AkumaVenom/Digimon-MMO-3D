// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFAbilityProjectileActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFAbilityProjectileActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USceneComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent(ETypeConstructPhase);
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFAbilityProjectileActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFAbilityProjectileActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ADMFAbilityProjectileActor Function BP_OnProjectilePresentationReady *****
static FName NAME_ADMFAbilityProjectileActor_BP_OnProjectilePresentationReady = FName(TEXT("BP_OnProjectilePresentationReady"));
void ADMFAbilityProjectileActor::BP_OnProjectilePresentationReady()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFAbilityProjectileActor_BP_OnProjectilePresentationReady);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFAbilityProjectileActor_BP_OnProjectilePresentationReady_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Projectile|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnProjectilePresentationReady constinit property declarations ******
// ********** End Function BP_OnProjectilePresentationReady constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFAbilityProjectileActor, nullptr, "BP_OnProjectilePresentationReady", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFAbilityProjectileActor_BP_OnProjectilePresentationReady(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFAbilityProjectileActor Function BP_OnProjectilePresentationReady *******

// ********** Begin Class ADMFAbilityProjectileActor Function GetAbilityId *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFAbilityProjectileActor_GetAbilityId_Statics
struct UHT_STATICS
{
	struct DMFAbilityProjectileActor_eventGetAbilityId_Parms
	{
		FName ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Projectile" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAbilityId constinit property declarations **************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAbilityId constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAbilityId Property Definitions *************************************
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAbilityProjectileActor_eventGetAbilityId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAbilityId Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFAbilityProjectileActor, nullptr, "GetAbilityId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFAbilityProjectileActor_eventGetAbilityId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFAbilityProjectileActor_eventGetAbilityId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFAbilityProjectileActor_GetAbilityId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFAbilityProjectileActor::execGetAbilityId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FName*)Z_Param__Result=P_THIS->GetAbilityId();
	P_NATIVE_END;
}
// ********** End Class ADMFAbilityProjectileActor Function GetAbilityId ***************************

// ********** Begin Class ADMFAbilityProjectileActor Function GetSourceDigimon *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFAbilityProjectileActor_GetSourceDigimon_Statics
struct UHT_STATICS
{
	struct DMFAbilityProjectileActor_eventGetSourceDigimon_Parms
	{
		ADMFDigimonCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Projectile" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSourceDigimon constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSourceDigimon constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSourceDigimon Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAbilityProjectileActor_eventGetSourceDigimon_Parms, ReturnValue), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSourceDigimon Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFAbilityProjectileActor, nullptr, "GetSourceDigimon", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFAbilityProjectileActor_eventGetSourceDigimon_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFAbilityProjectileActor_eventGetSourceDigimon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFAbilityProjectileActor_GetSourceDigimon(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFAbilityProjectileActor::execGetSourceDigimon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFDigimonCharacter**)Z_Param__Result=P_THIS->GetSourceDigimon();
	P_NATIVE_END;
}
// ********** End Class ADMFAbilityProjectileActor Function GetSourceDigimon ***********************

// ********** Begin Class ADMFAbilityProjectileActor Function GetTargetDigimon *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFAbilityProjectileActor_GetTargetDigimon_Statics
struct UHT_STATICS
{
	struct DMFAbilityProjectileActor_eventGetTargetDigimon_Parms
	{
		ADMFDigimonCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Projectile" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTargetDigimon constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTargetDigimon constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTargetDigimon Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAbilityProjectileActor_eventGetTargetDigimon_Parms, ReturnValue), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetTargetDigimon Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFAbilityProjectileActor, nullptr, "GetTargetDigimon", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFAbilityProjectileActor_eventGetTargetDigimon_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFAbilityProjectileActor_eventGetTargetDigimon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFAbilityProjectileActor_GetTargetDigimon(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFAbilityProjectileActor::execGetTargetDigimon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFDigimonCharacter**)Z_Param__Result=P_THIS->GetTargetDigimon();
	P_NATIVE_END;
}
// ********** End Class ADMFAbilityProjectileActor Function GetTargetDigimon ***********************

// ********** Begin Class ADMFAbilityProjectileActor Function OnRep_ProjectileDefinition ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFAbilityProjectileActor_OnRep_ProjectileDefinition_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_ProjectileDefinition constinit property declarations ************
// ********** End Function OnRep_ProjectileDefinition constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFAbilityProjectileActor, nullptr, "OnRep_ProjectileDefinition", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFAbilityProjectileActor_OnRep_ProjectileDefinition(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFAbilityProjectileActor::execOnRep_ProjectileDefinition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_ProjectileDefinition();
	P_NATIVE_END;
}
// ********** End Class ADMFAbilityProjectileActor Function OnRep_ProjectileDefinition *************

// ********** Begin Class ADMFAbilityProjectileActor Function RefreshProjectilePresentation ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFAbilityProjectileActor_RefreshProjectilePresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Projectile|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-resolves the Data Asset and reapplies mesh/Niagara/Cascade/relative visual tuning. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-resolves the Data Asset and reapplies mesh/Niagara/Cascade/relative visual tuning." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshProjectilePresentation constinit property declarations *********
// ********** End Function RefreshProjectilePresentation constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFAbilityProjectileActor, nullptr, "RefreshProjectilePresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFAbilityProjectileActor_RefreshProjectilePresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFAbilityProjectileActor::execRefreshProjectilePresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshProjectilePresentation();
	P_NATIVE_END;
}
// ********** End Class ADMFAbilityProjectileActor Function RefreshProjectilePresentation **********

// ********** Begin Class ADMFAbilityProjectileActor ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFAbilityProjectileActor_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Native replicated projectile used by DMFDigimonAbilityData Projectile execution.\n *\n * The server alone advances authoritative flight and decides arrival/damage. Replicated actor\n * movement gives every relevant client the same visible projectile. All VFX/mesh components are\n * cosmetic children of the actor and are destroyed with it on impact or the hard lifetime guard.\n * Projects may subclass this actor in Blueprint for additional cosmetic presentation without\n * moving damage or target authority out of the combat component.\n */" },
#endif
		{ "IncludePath", "Game/DMFAbilityProjectileActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native replicated projectile used by DMFDigimonAbilityData Projectile execution.\n\nThe server alone advances authoritative flight and decides arrival/damage. Replicated actor\nmovement gives every relevant client the same visible projectile. All VFX/mesh components are\ncosmetic children of the actor and are destroyed with it on impact or the hard lifetime guard.\nProjects may subclass this actor in Blueprint for additional cosmetic presentation without\nmoving damage or target authority out of the combat component." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileRoot_MetaData[] = {
		{ "Category", "Digimon MMO|Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualRoot_MetaData[] = {
		{ "Category", "Digimon MMO|Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rotated/scaled independently so particle assets authored on a non-X forward axis are easy to correct. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rotated/scaled independently so particle assets authored on a non-X forward axis are easy to correct." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMeshComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileNiagaraComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileCascadeComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityId_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceDigimon_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetDigimon_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TravelDirection_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Initial/non-homing direction. Server updates actor rotation during homing flight. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFAbilityProjectileActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initial/non-homing direction. Server updates actor rotation during homing flight." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFAbilityProjectileActor constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VisualRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileNiagaraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileCascadeComponent;
	static const UECodeGen_Private::FNamePropertyParams NewProp_AbilityId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceDigimon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetDigimon;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TravelDirection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFAbilityProjectileActor constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetAbilityId"), .Pointer = &ADMFAbilityProjectileActor::execGetAbilityId },
		{ .NameUTF8 = UTF8TEXT("GetSourceDigimon"), .Pointer = &ADMFAbilityProjectileActor::execGetSourceDigimon },
		{ .NameUTF8 = UTF8TEXT("GetTargetDigimon"), .Pointer = &ADMFAbilityProjectileActor::execGetTargetDigimon },
		{ .NameUTF8 = UTF8TEXT("OnRep_ProjectileDefinition"), .Pointer = &ADMFAbilityProjectileActor::execOnRep_ProjectileDefinition },
		{ .NameUTF8 = UTF8TEXT("RefreshProjectilePresentation"), .Pointer = &ADMFAbilityProjectileActor::execRefreshProjectilePresentation },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFAbilityProjectileActor_BP_OnProjectilePresentationReady, "BP_OnProjectilePresentationReady" }, // ab797a100d1a0cc61a99523151a2d3b4513bb544
		{ &Z_Construct_UFunction_ADMFAbilityProjectileActor_GetAbilityId, "GetAbilityId" }, // ea970549b0f1fb258c8760f13f1620fa2a9604df
		{ &Z_Construct_UFunction_ADMFAbilityProjectileActor_GetSourceDigimon, "GetSourceDigimon" }, // 18d96663498efad94765e238293714065c5d6488
		{ &Z_Construct_UFunction_ADMFAbilityProjectileActor_GetTargetDigimon, "GetTargetDigimon" }, // beeed3ce213a9fc6f752f8a84dd0db12136db5ba
		{ &Z_Construct_UFunction_ADMFAbilityProjectileActor_OnRep_ProjectileDefinition, "OnRep_ProjectileDefinition" }, // 16cfc9f403a4adce4e11f6dff49ce64bf6647159
		{ &Z_Construct_UFunction_ADMFAbilityProjectileActor_RefreshProjectilePresentation, "RefreshProjectilePresentation" }, // 55e6578530d44690dbc56672eaac38714e494432
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFAbilityProjectileActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFAbilityProjectileActor Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ProjectileRoot = { "ProjectileRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFAbilityProjectileActor, ProjectileRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileRoot_MetaData), NewProp_ProjectileRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VisualRoot = { "VisualRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFAbilityProjectileActor, VisualRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualRoot_MetaData), NewProp_VisualRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ProjectileMeshComponent = { "ProjectileMeshComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFAbilityProjectileActor, ProjectileMeshComponent), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileMeshComponent_MetaData), NewProp_ProjectileMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ProjectileNiagaraComponent = { "ProjectileNiagaraComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFAbilityProjectileActor, ProjectileNiagaraComponent), Z_Construct_UClass_UNiagaraComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileNiagaraComponent_MetaData), NewProp_ProjectileNiagaraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ProjectileCascadeComponent = { "ProjectileCascadeComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFAbilityProjectileActor, ProjectileCascadeComponent), Z_Construct_UClass_UParticleSystemComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileCascadeComponent_MetaData), NewProp_ProjectileCascadeComponent_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_AbilityId = { "AbilityId", "OnRep_ProjectileDefinition", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFAbilityProjectileActor, AbilityId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityId_MetaData), NewProp_AbilityId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SourceDigimon = { "SourceDigimon", "OnRep_ProjectileDefinition", (EPropertyFlags)0x0124080100000020, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFAbilityProjectileActor, SourceDigimon), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceDigimon_MetaData), NewProp_SourceDigimon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetDigimon = { "TargetDigimon", "OnRep_ProjectileDefinition", (EPropertyFlags)0x0124080100000020, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFAbilityProjectileActor, TargetDigimon), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetDigimon_MetaData), NewProp_TargetDigimon_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_TravelDirection = { "TravelDirection", nullptr, (EPropertyFlags)0x0020080000000020, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFAbilityProjectileActor, TravelDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TravelDirection_MetaData), NewProp_TravelDirection_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VisualRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileNiagaraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectileCascadeComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SourceDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetDigimon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TravelDirection,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFAbilityProjectileActor Property Definitions ****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFAbilityProjectileActor,
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
static void ADMFAbilityProjectileActor_StaticRegisterNativesADMFAbilityProjectileActor()
{
	UClass* Class = ADMFAbilityProjectileActor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFAbilityProjectileActor;
UClass* Z_Construct_UClass_ADMFAbilityProjectileActor(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFAbilityProjectileActor;
		if (!Z_Registration_Info_UClass_ADMFAbilityProjectileActor.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFAbilityProjectileActor"),
				Z_Registration_Info_UClass_ADMFAbilityProjectileActor.InnerSingleton,
				ADMFAbilityProjectileActor_StaticRegisterNativesADMFAbilityProjectileActor,
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
		return Z_Registration_Info_UClass_ADMFAbilityProjectileActor.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFAbilityProjectileActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFAbilityProjectileActor.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFAbilityProjectileActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFAbilityProjectileActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_AbilityId(TEXT("AbilityId"));
	static FName Name_SourceDigimon(TEXT("SourceDigimon"));
	static FName Name_TargetDigimon(TEXT("TargetDigimon"));
	static FName Name_TravelDirection(TEXT("TravelDirection"));
	const bool bIsValid = true
		&& Name_AbilityId == ClassReps[(int32)ENetFields_Private::AbilityId].Property->GetFName()
		&& Name_SourceDigimon == ClassReps[(int32)ENetFields_Private::SourceDigimon].Property->GetFName()
		&& Name_TargetDigimon == ClassReps[(int32)ENetFields_Private::TargetDigimon].Property->GetFName()
		&& Name_TravelDirection == ClassReps[(int32)ENetFields_Private::TravelDirection].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFAbilityProjectileActor"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFAbilityProjectileActor);
ADMFAbilityProjectileActor::~ADMFAbilityProjectileActor() {}
// ********** End Class ADMFAbilityProjectileActor *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFAbilityProjectileActor, TEXT("ADMFAbilityProjectileActor"), &Z_Registration_Info_UClass_ADMFAbilityProjectileActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFAbilityProjectileActor), 929788037U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFAbilityProjectileActor_h__Script_DigimonMMOFramework_800ce2edcfe13b5fcc46da67238b7d4b647db869{
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
