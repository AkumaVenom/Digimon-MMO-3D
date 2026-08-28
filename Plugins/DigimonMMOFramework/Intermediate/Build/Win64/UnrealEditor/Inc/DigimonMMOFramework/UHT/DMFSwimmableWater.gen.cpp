// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFSwimmableWater.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFSwimmableWater() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USceneComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFSwimmableWater(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWaterPlayerOverlapChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerSwimState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFSwimmableWater(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EDMFPlayerSwimState *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerSwimState_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFPlayerSwimState>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerSwimState(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
		{ "None.DisplayName", "Not Swimming" },
		{ "None.Name", "EDMFPlayerSwimState::None" },
		{ "Surface.DisplayName", "Surface Swimming" },
		{ "Surface.Name", "EDMFPlayerSwimState::Surface" },
		{ "Underwater.DisplayName", "Underwater Swimming" },
		{ "Underwater.Name", "EDMFPlayerSwimState::Underwater" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFPlayerSwimState::None", (int64)EDMFPlayerSwimState::None },
		{ "EDMFPlayerSwimState::Surface", (int64)EDMFPlayerSwimState::Surface },
		{ "EDMFPlayerSwimState::Underwater", (int64)EDMFPlayerSwimState::Underwater },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFPlayerSwimState",
	"EDMFPlayerSwimState",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFPlayerSwimState;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerSwimState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFPlayerSwimState.OuterSingleton)
		{
			ZRIE_EDMFPlayerSwimState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerSwimState, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFPlayerSwimState"));
		}
		return ZRIE_EDMFPlayerSwimState.OuterSingleton;
	}
	if (!ZRIE_EDMFPlayerSwimState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFPlayerSwimState.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFPlayerSwimState.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFPlayerSwimState *********************************************************

// ********** Begin ScriptStruct FDMFUnderwaterPostProcessSettings *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFUnderwaterPostProcessSettings>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFUnderwaterPostProcessSettings); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Per-water-body local underwater presentation profile. The water actor replicates this sparse configuration,\n * while only the locally controlled player's camera consumes it. No camera/post-process state is network authored.\n */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-water-body local underwater presentation profile. The water actor replicates this sparse configuration,\nwhile only the locally controlled player's camera consumes it. No camera/post-process state is network authored." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Underwater Post Process" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ColorTint_MetaData[] = {
		{ "Category", "Underwater Post Process" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Multiplicative color-grading target. Values above 1 are allowed for a stronger blue/cyan channel. */" },
#endif
		{ "HideAlphaChannel", "" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Multiplicative color-grading target. Values above 1 are allowed for a stronger blue/cyan channel." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ColorTintStrength_MetaData[] = {
		{ "Category", "Underwater Post Process" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Saturation_MetaData[] = {
		{ "Category", "Underwater Post Process" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Contrast_MetaData[] = {
		{ "Category", "Underwater Post Process" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gamma_MetaData[] = {
		{ "Category", "Underwater Post Process" },
		{ "ClampMax", "3.0" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExposureCompensation_MetaData[] = {
		{ "Category", "Underwater Post Process" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "-10.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VignetteIntensity_MetaData[] = {
		{ "Category", "Underwater Post Process" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChromaticAberrationIntensity_MetaData[] = {
		{ "Category", "Underwater Post Process" },
		{ "ClampMax", "5.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Subtle edge color separation. Keep low for a clean MMO look. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Subtle edge color separation. Keep low for a clean MMO look." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDistanceFog_MetaData[] = {
		{ "Category", "Underwater Post Process|Distance Fog" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Enables the native local underwater distance-fog layer. Unlike color grading, this actually removes distant\n     * scene clarity so terrain/objects fade naturally into the water color. It is rendered only for the owning\n     * local camera and does not change replicated gameplay or the water actor's zero-tick contract.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables the native local underwater distance-fog layer. Unlike color grading, this actually removes distant\nscene clarity so terrain/objects fade naturally into the water color. It is rendered only for the owning\nlocal camera and does not change replicated gameplay or the water actor's zero-tick contract." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceFogColor_MetaData[] = {
		{ "Category", "Underwater Post Process|Distance Fog" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Inscattering color used by the native underwater distance fog. */" },
#endif
		{ "HideAlphaChannel", "" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inscattering color used by the native underwater distance fog." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceFogDensity_MetaData[] = {
		{ "Category", "Underwater Post Process|Distance Fog" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Full-strength exponential fog density. Higher values shorten underwater visibility distance. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Full-strength exponential fog density. Higher values shorten underwater visibility distance." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceFogHeightFalloff_MetaData[] = {
		{ "Category", "Underwater Post Process|Distance Fog" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.001" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Kept very low by default so underwater fog behaves primarily as distance haze rather than world-height fog. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Kept very low by default so underwater fog behaves primarily as distance haze rather than world-height fog." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceFogStartDistance_MetaData[] = {
		{ "Category", "Underwater Post Process|Distance Fog" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Distance from the camera before the native underwater fog begins affecting scene geometry. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance from the camera before the native underwater fog begins affecting scene geometry." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceFogMaxOpacity_MetaData[] = {
		{ "Category", "Underwater Post Process|Distance Fog" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Upper opacity limit for the native underwater distance fog. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Upper opacity limit for the native underwater distance fog." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceFogBlendExponent_MetaData[] = {
		{ "Category", "Underwater Post Process|Distance Fog" },
		{ "ClampMax", "4.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Shapes how quickly fog density reaches full strength as the existing underwater blend rises. Values below 1\n     * give convincing visibility loss immediately below the surface while preserving the smooth waterline fade.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shapes how quickly fog density reaches full strength as the existing underwater blend rises. Values below 1\ngive convincing visibility loss immediately below the surface while preserving the smooth waterline fade." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraEnterDepth_MetaData[] = {
		{ "Category", "Underwater Post Process|Waterline" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera must be this far below the surface before the local underwater presentation engages. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera must be this far below the surface before the local underwater presentation engages." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraExitHeight_MetaData[] = {
		{ "Category", "Underwater Post Process|Waterline" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Once engaged, the camera must rise this far above the surface before the presentation disengages. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Once engaged, the camera must rise this far above the surface before the presentation disengages." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShallowWaterBlendWeight_MetaData[] = {
		{ "Category", "Underwater Post Process|Depth Response" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Effect strength immediately after the camera enters the water; deeper water then ramps toward full strength. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Effect strength immediately after the camera enters the water; deeper water then ramps toward full strength." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FullStrengthDepth_MetaData[] = {
		{ "Category", "Underwater Post Process|Depth Response" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera depth at which the profile reaches full post-process weight. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera depth at which the profile reaches full post-process weight." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlendInSpeed_MetaData[] = {
		{ "Category", "Underwater Post Process|Blend" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlendOutSpeed_MetaData[] = {
		{ "Category", "Underwater Post Process|Blend" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Priority_MetaData[] = {
		{ "Category", "Underwater Post Process|Advanced" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Priority of the local unbound post-process component while this water body supplies the active profile. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Priority of the local unbound post-process component while this water body supplies the active profile." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessMaterial_MetaData[] = {
		{ "Category", "Underwater Post Process|Advanced" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional project-authored Post Process material for refraction, caustics, SceneDepth haze, particles, etc. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional project-authored Post Process material for refraction, caustics, SceneDepth haze, particles, etc." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessMaterialWeight_MetaData[] = {
		{ "Category", "Underwater Post Process|Advanced" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFUnderwaterPostProcessSettings constinit property declarations *
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((FDMFUnderwaterPostProcessSettings*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ColorTint;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ColorTintStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Saturation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Contrast;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Gamma;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExposureCompensation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VignetteIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChromaticAberrationIntensity;
	static void NewProp_bEnableDistanceFog_SetBit(void* Obj)
	{
		((FDMFUnderwaterPostProcessSettings*)Obj)->bEnableDistanceFog = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDistanceFog;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DistanceFogColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceFogDensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceFogHeightFalloff;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceFogStartDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceFogMaxOpacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceFogBlendExponent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraEnterDepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraExitHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShallowWaterBlendWeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FullStrengthDepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlendInSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlendOutSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Priority;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PostProcessMaterial;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PostProcessMaterialWeight;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFUnderwaterPostProcessSettings constinit property declarations ***
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFUnderwaterPostProcessSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFUnderwaterPostProcessSettings Property Definitions ************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFUnderwaterPostProcessSettings), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ColorTint = { "ColorTint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, ColorTint), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ColorTint_MetaData), NewProp_ColorTint_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ColorTintStrength = { "ColorTintStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, ColorTintStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ColorTintStrength_MetaData), NewProp_ColorTintStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Saturation = { "Saturation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, Saturation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Saturation_MetaData), NewProp_Saturation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Contrast = { "Contrast", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, Contrast), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Contrast_MetaData), NewProp_Contrast_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Gamma = { "Gamma", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, Gamma), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gamma_MetaData), NewProp_Gamma_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ExposureCompensation = { "ExposureCompensation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, ExposureCompensation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExposureCompensation_MetaData), NewProp_ExposureCompensation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_VignetteIntensity = { "VignetteIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, VignetteIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VignetteIntensity_MetaData), NewProp_VignetteIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ChromaticAberrationIntensity = { "ChromaticAberrationIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, ChromaticAberrationIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChromaticAberrationIntensity_MetaData), NewProp_ChromaticAberrationIntensity_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableDistanceFog = { "bEnableDistanceFog", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(FDMFUnderwaterPostProcessSettings), &UHT_STATICS::NewProp_bEnableDistanceFog_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDistanceFog_MetaData), NewProp_bEnableDistanceFog_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DistanceFogColor = { "DistanceFogColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, DistanceFogColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceFogColor_MetaData), NewProp_DistanceFogColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DistanceFogDensity = { "DistanceFogDensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, DistanceFogDensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceFogDensity_MetaData), NewProp_DistanceFogDensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DistanceFogHeightFalloff = { "DistanceFogHeightFalloff", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, DistanceFogHeightFalloff), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceFogHeightFalloff_MetaData), NewProp_DistanceFogHeightFalloff_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DistanceFogStartDistance = { "DistanceFogStartDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, DistanceFogStartDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceFogStartDistance_MetaData), NewProp_DistanceFogStartDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DistanceFogMaxOpacity = { "DistanceFogMaxOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, DistanceFogMaxOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceFogMaxOpacity_MetaData), NewProp_DistanceFogMaxOpacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DistanceFogBlendExponent = { "DistanceFogBlendExponent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, DistanceFogBlendExponent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceFogBlendExponent_MetaData), NewProp_DistanceFogBlendExponent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CameraEnterDepth = { "CameraEnterDepth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, CameraEnterDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraEnterDepth_MetaData), NewProp_CameraEnterDepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CameraExitHeight = { "CameraExitHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, CameraExitHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraExitHeight_MetaData), NewProp_CameraExitHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ShallowWaterBlendWeight = { "ShallowWaterBlendWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, ShallowWaterBlendWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShallowWaterBlendWeight_MetaData), NewProp_ShallowWaterBlendWeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FullStrengthDepth = { "FullStrengthDepth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, FullStrengthDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FullStrengthDepth_MetaData), NewProp_FullStrengthDepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BlendInSpeed = { "BlendInSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, BlendInSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlendInSpeed_MetaData), NewProp_BlendInSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BlendOutSpeed = { "BlendOutSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, BlendOutSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlendOutSpeed_MetaData), NewProp_BlendOutSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Priority = { "Priority", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, Priority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Priority_MetaData), NewProp_Priority_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PostProcessMaterial = { "PostProcessMaterial", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, PostProcessMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PostProcessMaterial_MetaData), NewProp_PostProcessMaterial_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_PostProcessMaterialWeight = { "PostProcessMaterialWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFUnderwaterPostProcessSettings, PostProcessMaterialWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PostProcessMaterialWeight_MetaData), NewProp_PostProcessMaterialWeight_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ColorTint,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ColorTintStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Saturation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Contrast,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Gamma,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExposureCompensation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VignetteIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChromaticAberrationIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableDistanceFog,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistanceFogColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistanceFogDensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistanceFogHeightFalloff,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistanceFogStartDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistanceFogMaxOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistanceFogBlendExponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CameraEnterDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CameraExitHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ShallowWaterBlendWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FullStrengthDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlendInSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BlendOutSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Priority,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PostProcessMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PostProcessMaterialWeight,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFUnderwaterPostProcessSettings Property Definitions **************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFUnderwaterPostProcessSettings",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFUnderwaterPostProcessSettings>(),
	alignof(FDMFUnderwaterPostProcessSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFUnderwaterPostProcessSettings;
UScriptStruct* Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFUnderwaterPostProcessSettings.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFUnderwaterPostProcessSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFUnderwaterPostProcessSettings"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFUnderwaterPostProcessSettings.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFUnderwaterPostProcessSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFUnderwaterPostProcessSettings.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFUnderwaterPostProcessSettings.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFUnderwaterPostProcessSettings ***********************************

// ********** Begin Delegate FDMFWaterPlayerOverlapChanged *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWaterPlayerOverlapChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFWaterPlayerOverlapChanged_Parms
	{
		ADMFPlayerAvatarCharacter* PlayerAvatar;
		bool bEnteredWater;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFWaterPlayerOverlapChanged constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerAvatar;
	static void NewProp_bEnteredWater_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFWaterPlayerOverlapChanged_Parms*)Obj)->bEnteredWater = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnteredWater;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFWaterPlayerOverlapChanged constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFWaterPlayerOverlapChanged Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerAvatar = { "PlayerAvatar", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFWaterPlayerOverlapChanged_Parms, PlayerAvatar), Z_Construct_UClass_ADMFPlayerAvatarCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnteredWater = { "bEnteredWater", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFWaterPlayerOverlapChanged_Parms), &UHT_STATICS::NewProp_bEnteredWater_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerAvatar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnteredWater,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFWaterPlayerOverlapChanged Property Definitions **********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFWaterPlayerOverlapChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFWaterPlayerOverlapChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFWaterPlayerOverlapChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWaterPlayerOverlapChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFWaterPlayerOverlapChanged *******************************************

// ********** Begin Class ADMFSwimmableWater Function BP_OnPlayerEnteredWater **********************
struct DMFSwimmableWater_eventBP_OnPlayerEnteredWater_Parms
{
	ADMFPlayerAvatarCharacter* PlayerAvatar;
};
static FName NAME_ADMFSwimmableWater_BP_OnPlayerEnteredWater = FName(TEXT("BP_OnPlayerEnteredWater"));
void ADMFSwimmableWater::BP_OnPlayerEnteredWater(ADMFPlayerAvatarCharacter* PlayerAvatar)
{
	DMFSwimmableWater_eventBP_OnPlayerEnteredWater_Parms Parms;
	Parms.PlayerAvatar=PlayerAvatar;
	UFunction* Func = FindFunctionChecked(NAME_ADMFSwimmableWater_BP_OnPlayerEnteredWater);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_BP_OnPlayerEnteredWater_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPlayerEnteredWater constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerAvatar;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnPlayerEnteredWater constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnPlayerEnteredWater Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerAvatar = { "PlayerAvatar", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventBP_OnPlayerEnteredWater_Parms, PlayerAvatar), Z_Construct_UClass_ADMFPlayerAvatarCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerAvatar,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnPlayerEnteredWater Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "BP_OnPlayerEnteredWater", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFSwimmableWater_eventBP_OnPlayerEnteredWater_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFSwimmableWater_eventBP_OnPlayerEnteredWater_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_BP_OnPlayerEnteredWater(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFSwimmableWater Function BP_OnPlayerEnteredWater ************************

// ********** Begin Class ADMFSwimmableWater Function BP_OnPlayerExitedWater ***********************
struct DMFSwimmableWater_eventBP_OnPlayerExitedWater_Parms
{
	ADMFPlayerAvatarCharacter* PlayerAvatar;
};
static FName NAME_ADMFSwimmableWater_BP_OnPlayerExitedWater = FName(TEXT("BP_OnPlayerExitedWater"));
void ADMFSwimmableWater::BP_OnPlayerExitedWater(ADMFPlayerAvatarCharacter* PlayerAvatar)
{
	DMFSwimmableWater_eventBP_OnPlayerExitedWater_Parms Parms;
	Parms.PlayerAvatar=PlayerAvatar;
	UFunction* Func = FindFunctionChecked(NAME_ADMFSwimmableWater_BP_OnPlayerExitedWater);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_BP_OnPlayerExitedWater_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPlayerExitedWater constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerAvatar;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnPlayerExitedWater constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnPlayerExitedWater Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerAvatar = { "PlayerAvatar", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventBP_OnPlayerExitedWater_Parms, PlayerAvatar), Z_Construct_UClass_ADMFPlayerAvatarCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerAvatar,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnPlayerExitedWater Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "BP_OnPlayerExitedWater", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFSwimmableWater_eventBP_OnPlayerExitedWater_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFSwimmableWater_eventBP_OnPlayerExitedWater_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_BP_OnPlayerExitedWater(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFSwimmableWater Function BP_OnPlayerExitedWater *************************

// ********** Begin Class ADMFSwimmableWater Function GetDepthBelowSurface *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_GetDepthBelowSurface_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventGetDepthBelowSurface_Parms
	{
		FVector WorldLocation;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDepthBelowSurface constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDepthBelowSurface constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDepthBelowSurface Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventGetDepthBelowSurface_Parms, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldLocation_MetaData), NewProp_WorldLocation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventGetDepthBelowSurface_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetDepthBelowSurface Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "GetDepthBelowSurface", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventGetDepthBelowSurface_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventGetDepthBelowSurface_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_GetDepthBelowSurface(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execGetDepthBelowSurface)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetDepthBelowSurface(Z_Param_Out_WorldLocation);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function GetDepthBelowSurface ***************************

// ********** Begin Class ADMFSwimmableWater Function GetUnderwaterPostProcessSettings *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_GetUnderwaterPostProcessSettings_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventGetUnderwaterPostProcessSettings_Parms
	{
		FDMFUnderwaterPostProcessSettings ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Underwater Post Process" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetUnderwaterPostProcessSettings constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetUnderwaterPostProcessSettings constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetUnderwaterPostProcessSettings Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventGetUnderwaterPostProcessSettings_Parms, ReturnValue), Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings, METADATA_PARAMS(0, nullptr) }; // 89941e8cb391b29bbd1f13ec7d77bc6e706c3728
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetUnderwaterPostProcessSettings Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "GetUnderwaterPostProcessSettings", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventGetUnderwaterPostProcessSettings_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventGetUnderwaterPostProcessSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_GetUnderwaterPostProcessSettings(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execGetUnderwaterPostProcessSettings)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FDMFUnderwaterPostProcessSettings*)Z_Param__Result=P_THIS->GetUnderwaterPostProcessSettings();
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function GetUnderwaterPostProcessSettings ***************

// ********** Begin Class ADMFSwimmableWater Function GetWaterBottomWorldZ *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_GetWaterBottomWorldZ_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventGetWaterBottomWorldZ_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetWaterBottomWorldZ constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWaterBottomWorldZ constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWaterBottomWorldZ Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventGetWaterBottomWorldZ_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetWaterBottomWorldZ Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "GetWaterBottomWorldZ", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventGetWaterBottomWorldZ_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventGetWaterBottomWorldZ_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_GetWaterBottomWorldZ(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execGetWaterBottomWorldZ)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetWaterBottomWorldZ();
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function GetWaterBottomWorldZ ***************************

// ********** Begin Class ADMFSwimmableWater Function GetWaterSurfaceWorldZ ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_GetWaterSurfaceWorldZ_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventGetWaterSurfaceWorldZ_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---- Blueprint API -------------------------------------------------------------------\n" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---- Blueprint API -------------------------------------------------------------------" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetWaterSurfaceWorldZ constinit property declarations *****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWaterSurfaceWorldZ constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWaterSurfaceWorldZ Property Definitions ****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventGetWaterSurfaceWorldZ_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetWaterSurfaceWorldZ Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "GetWaterSurfaceWorldZ", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventGetWaterSurfaceWorldZ_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventGetWaterSurfaceWorldZ_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_GetWaterSurfaceWorldZ(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execGetWaterSurfaceWorldZ)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetWaterSurfaceWorldZ();
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function GetWaterSurfaceWorldZ **************************

// ********** Begin Class ADMFSwimmableWater Function HandleSwimmingBoundsBeginOverlap *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_HandleSwimmingBoundsBeginOverlap_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComponent;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSwimmingBoundsBeginOverlap constinit property declarations ******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComponent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms*)Obj)->bFromSweep = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleSwimmingBoundsBeginOverlap constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleSwimmingBoundsBeginOverlap Property Definitions *****************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OtherComponent = { "OtherComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms, OtherComponent), Z_Construct_UClass_UPrimitiveComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComponent_MetaData), NewProp_OtherComponent_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms), &UHT_STATICS::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // e0ec7b349cc3b29366a6161006ad7fa74de2944e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OtherComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleSwimmingBoundsBeginOverlap Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "HandleSwimmingBoundsBeginOverlap", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventHandleSwimmingBoundsBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_HandleSwimmingBoundsBeginOverlap(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execHandleSwimmingBoundsBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSwimmingBoundsBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function HandleSwimmingBoundsBeginOverlap ***************

// ********** Begin Class ADMFSwimmableWater Function HandleSwimmingBoundsEndOverlap ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_HandleSwimmingBoundsEndOverlap_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventHandleSwimmingBoundsEndOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComponent;
		int32 OtherBodyIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSwimmingBoundsEndOverlap constinit property declarations ********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComponent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleSwimmingBoundsEndOverlap constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleSwimmingBoundsEndOverlap Property Definitions *******************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventHandleSwimmingBoundsEndOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventHandleSwimmingBoundsEndOverlap_Parms, OtherActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OtherComponent = { "OtherComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventHandleSwimmingBoundsEndOverlap_Parms, OtherComponent), Z_Construct_UClass_UPrimitiveComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComponent_MetaData), NewProp_OtherComponent_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventHandleSwimmingBoundsEndOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OtherComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OtherBodyIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleSwimmingBoundsEndOverlap Property Definitions *********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "HandleSwimmingBoundsEndOverlap", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventHandleSwimmingBoundsEndOverlap_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventHandleSwimmingBoundsEndOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_HandleSwimmingBoundsEndOverlap(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execHandleSwimmingBoundsEndOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSwimmingBoundsEndOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_OtherBodyIndex);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function HandleSwimmingBoundsEndOverlap *****************

// ********** Begin Class ADMFSwimmableWater Function IsSwimmingEnabled ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_IsSwimmingEnabled_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventIsSwimmingEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsSwimmingEnabled constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventIsSwimmingEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSwimmingEnabled constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSwimmingEnabled Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventIsSwimmingEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsSwimmingEnabled Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "IsSwimmingEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventIsSwimmingEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventIsSwimmingEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_IsSwimmingEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execIsSwimmingEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSwimmingEnabled();
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function IsSwimmingEnabled ******************************

// ********** Begin Class ADMFSwimmableWater Function IsWorldLocationInsideSwimmingBounds **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_IsWorldLocationInsideSwimmingBounds_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventIsWorldLocationInsideSwimmingBounds_Parms
	{
		FVector WorldLocation;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsWorldLocationInsideSwimmingBounds constinit property declarations ***
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventIsWorldLocationInsideSwimmingBounds_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsWorldLocationInsideSwimmingBounds constinit property declarations *****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsWorldLocationInsideSwimmingBounds Property Definitions **************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventIsWorldLocationInsideSwimmingBounds_Parms, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldLocation_MetaData), NewProp_WorldLocation_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventIsWorldLocationInsideSwimmingBounds_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsWorldLocationInsideSwimmingBounds Property Definitions ****************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "IsWorldLocationInsideSwimmingBounds", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventIsWorldLocationInsideSwimmingBounds_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventIsWorldLocationInsideSwimmingBounds_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_IsWorldLocationInsideSwimmingBounds(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execIsWorldLocationInsideSwimmingBounds)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsWorldLocationInsideSwimmingBounds(Z_Param_Out_WorldLocation);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function IsWorldLocationInsideSwimmingBounds ************

// ********** Begin Class ADMFSwimmableWater Function OnRep_UnderwaterPostProcessSettings **********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_OnRep_UnderwaterPostProcessSettings_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_UnderwaterPostProcessSettings constinit property declarations ***
// ********** End Function OnRep_UnderwaterPostProcessSettings constinit property declarations *****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "OnRep_UnderwaterPostProcessSettings", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_OnRep_UnderwaterPostProcessSettings(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execOnRep_UnderwaterPostProcessSettings)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_UnderwaterPostProcessSettings();
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function OnRep_UnderwaterPostProcessSettings ************

// ********** Begin Class ADMFSwimmableWater Function OnRep_WaterConfiguration *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_OnRep_WaterConfiguration_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_WaterConfiguration constinit property declarations **************
// ********** End Function OnRep_WaterConfiguration constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "OnRep_WaterConfiguration", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_OnRep_WaterConfiguration(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execOnRep_WaterConfiguration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_WaterConfiguration();
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function OnRep_WaterConfiguration ***********************

// ********** Begin Class ADMFSwimmableWater Function RefreshUnderwaterPostProcessPresentation *****
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_RefreshUnderwaterPostProcessPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Digimon MMO|Swimming Water|Underwater Post Process" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-applies the active local swimmer's post-process profile without changing gameplay state. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-applies the active local swimmer's post-process profile without changing gameplay state." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshUnderwaterPostProcessPresentation constinit property declarations 
// ********** End Function RefreshUnderwaterPostProcessPresentation constinit property declarations 
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "RefreshUnderwaterPostProcessPresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_RefreshUnderwaterPostProcessPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execRefreshUnderwaterPostProcessPresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshUnderwaterPostProcessPresentation();
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function RefreshUnderwaterPostProcessPresentation *******

// ********** Begin Class ADMFSwimmableWater Function RefreshWaterGeometry *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_RefreshWaterGeometry_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Digimon MMO|Swimming Water" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-applies plane mesh/material scale and overlap bounds from the exposed values. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-applies plane mesh/material scale and overlap bounds from the exposed values." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshWaterGeometry constinit property declarations ******************
// ********** End Function RefreshWaterGeometry constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "RefreshWaterGeometry", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_RefreshWaterGeometry(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execRefreshWaterGeometry)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshWaterGeometry();
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function RefreshWaterGeometry ***************************

// ********** Begin Class ADMFSwimmableWater Function SetSurfaceOverlapHeight **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetSurfaceOverlapHeight_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetSurfaceOverlapHeight_Parms
	{
		float NewOverlapHeight;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Authority" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSurfaceOverlapHeight constinit property declarations ***************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewOverlapHeight;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetSurfaceOverlapHeight_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSurfaceOverlapHeight constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSurfaceOverlapHeight Property Definitions **************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NewOverlapHeight = { "NewOverlapHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventSetSurfaceOverlapHeight_Parms, NewOverlapHeight), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetSurfaceOverlapHeight_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewOverlapHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetSurfaceOverlapHeight Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetSurfaceOverlapHeight", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetSurfaceOverlapHeight_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetSurfaceOverlapHeight_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetSurfaceOverlapHeight(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetSurfaceOverlapHeight)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewOverlapHeight);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetSurfaceOverlapHeight(Z_Param_NewOverlapHeight);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetSurfaceOverlapHeight ************************

// ********** Begin Class ADMFSwimmableWater Function SetSwimmingEnabled ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetSwimmingEnabled_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetSwimmingEnabled_Parms
	{
		bool bNewEnabled;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Authority" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authority-only at runtime; editor/default authoring remains available through Details panel. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authority-only at runtime; editor/default authoring remains available through Details panel." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSwimmingEnabled constinit property declarations ********************
	static void NewProp_bNewEnabled_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetSwimmingEnabled_Parms*)Obj)->bNewEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewEnabled;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetSwimmingEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSwimmingEnabled constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSwimmingEnabled Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bNewEnabled = { "bNewEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetSwimmingEnabled_Parms), &UHT_STATICS::NewProp_bNewEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetSwimmingEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bNewEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetSwimmingEnabled Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetSwimmingEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetSwimmingEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetSwimmingEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetSwimmingEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetSwimmingEnabled)
{
	P_GET_UBOOL(Z_Param_bNewEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetSwimmingEnabled(Z_Param_bNewEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetSwimmingEnabled *****************************

// ********** Begin Class ADMFSwimmableWater Function SetUnderwaterPostProcessEnabled **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetUnderwaterPostProcessEnabled_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetUnderwaterPostProcessEnabled_Parms
	{
		bool bNewEnabled;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Underwater Post Process|Authority" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetUnderwaterPostProcessEnabled constinit property declarations *******
	static void NewProp_bNewEnabled_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetUnderwaterPostProcessEnabled_Parms*)Obj)->bNewEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewEnabled;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetUnderwaterPostProcessEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetUnderwaterPostProcessEnabled constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetUnderwaterPostProcessEnabled Property Definitions ******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bNewEnabled = { "bNewEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetUnderwaterPostProcessEnabled_Parms), &UHT_STATICS::NewProp_bNewEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetUnderwaterPostProcessEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bNewEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetUnderwaterPostProcessEnabled Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetUnderwaterPostProcessEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetUnderwaterPostProcessEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetUnderwaterPostProcessEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetUnderwaterPostProcessEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetUnderwaterPostProcessEnabled)
{
	P_GET_UBOOL(Z_Param_bNewEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetUnderwaterPostProcessEnabled(Z_Param_bNewEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetUnderwaterPostProcessEnabled ****************

// ********** Begin Class ADMFSwimmableWater Function SetUnderwaterPostProcessMaterial *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetUnderwaterPostProcessMaterial_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetUnderwaterPostProcessMaterial_Parms
	{
		UMaterialInterface* NewMaterial;
		float MaterialWeight;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Underwater Post Process|Authority" },
		{ "CPP_Default_MaterialWeight", "1.000000" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetUnderwaterPostProcessMaterial constinit property declarations ******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewMaterial;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaterialWeight;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetUnderwaterPostProcessMaterial_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetUnderwaterPostProcessMaterial constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetUnderwaterPostProcessMaterial Property Definitions *****************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NewMaterial = { "NewMaterial", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventSetUnderwaterPostProcessMaterial_Parms, NewMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaterialWeight = { "MaterialWeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventSetUnderwaterPostProcessMaterial_Parms, MaterialWeight), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetUnderwaterPostProcessMaterial_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetUnderwaterPostProcessMaterial Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetUnderwaterPostProcessMaterial", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetUnderwaterPostProcessMaterial_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetUnderwaterPostProcessMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetUnderwaterPostProcessMaterial(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetUnderwaterPostProcessMaterial)
{
	P_GET_OBJECT(UMaterialInterface,Z_Param_NewMaterial);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaterialWeight);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetUnderwaterPostProcessMaterial(Z_Param_NewMaterial,Z_Param_MaterialWeight);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetUnderwaterPostProcessMaterial ***************

// ********** Begin Class ADMFSwimmableWater Function SetUnderwaterPostProcessSettings *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetUnderwaterPostProcessSettings_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetUnderwaterPostProcessSettings_Parms
	{
		FDMFUnderwaterPostProcessSettings NewSettings;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Underwater Post Process|Authority" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authority-only at runtime. Replaces and replicates the complete local-camera underwater presentation profile. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authority-only at runtime. Replaces and replicates the complete local-camera underwater presentation profile." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetUnderwaterPostProcessSettings constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewSettings;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetUnderwaterPostProcessSettings_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetUnderwaterPostProcessSettings constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetUnderwaterPostProcessSettings Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NewSettings = { "NewSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventSetUnderwaterPostProcessSettings_Parms, NewSettings), Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewSettings_MetaData), NewProp_NewSettings_MetaData) }; // 89941e8cb391b29bbd1f13ec7d77bc6e706c3728
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetUnderwaterPostProcessSettings_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetUnderwaterPostProcessSettings Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetUnderwaterPostProcessSettings", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetUnderwaterPostProcessSettings_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetUnderwaterPostProcessSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetUnderwaterPostProcessSettings(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetUnderwaterPostProcessSettings)
{
	P_GET_STRUCT_REF(FDMFUnderwaterPostProcessSettings,Z_Param_Out_NewSettings);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetUnderwaterPostProcessSettings(Z_Param_Out_NewSettings);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetUnderwaterPostProcessSettings ***************

// ********** Begin Class ADMFSwimmableWater Function SetWaterDepth ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetWaterDepth_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetWaterDepth_Parms
	{
		float NewDepth;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Authority" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authority-only at runtime. Replicates the new depth and rebuilds collision on clients. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authority-only at runtime. Replicates the new depth and rebuilds collision on clients." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetWaterDepth constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewDepth;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetWaterDepth_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWaterDepth constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWaterDepth Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NewDepth = { "NewDepth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventSetWaterDepth_Parms, NewDepth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetWaterDepth_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetWaterDepth Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetWaterDepth", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetWaterDepth_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetWaterDepth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetWaterDepth(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetWaterDepth)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewDepth);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetWaterDepth(Z_Param_NewDepth);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetWaterDepth **********************************

// ********** Begin Class ADMFSwimmableWater Function SetWaterMaterial *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetWaterMaterial_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetWaterMaterial_Parms
	{
		UMaterialInterface* NewMaterial;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Presentation helper. Material assets are authored content and are not gameplay authority. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Presentation helper. Material assets are authored content and are not gameplay authority." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetWaterMaterial constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewMaterial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWaterMaterial constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWaterMaterial Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NewMaterial = { "NewMaterial", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventSetWaterMaterial_Parms, NewMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewMaterial,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetWaterMaterial Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetWaterMaterial", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetWaterMaterial_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetWaterMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetWaterMaterial(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetWaterMaterial)
{
	P_GET_OBJECT(UMaterialInterface,Z_Param_NewMaterial);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWaterMaterial(Z_Param_NewMaterial);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetWaterMaterial *******************************

// ********** Begin Class ADMFSwimmableWater Function SetWaterPriority *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetWaterPriority_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetWaterPriority_Parms
	{
		int32 NewPriority;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Authority" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authority-only at runtime. Useful when overlapping lakes/volumes need an explicit controlling-water order. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authority-only at runtime. Useful when overlapping lakes/volumes need an explicit controlling-water order." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetWaterPriority constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewPriority;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetWaterPriority_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWaterPriority constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWaterPriority Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NewPriority = { "NewPriority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventSetWaterPriority_Parms, NewPriority), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetWaterPriority_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetWaterPriority Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetWaterPriority", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetWaterPriority_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetWaterPriority_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetWaterPriority(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetWaterPriority)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NewPriority);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetWaterPriority(Z_Param_NewPriority);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetWaterPriority *******************************

// ********** Begin Class ADMFSwimmableWater Function SetWaterSurfaceSize **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetWaterSurfaceSize_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetWaterSurfaceSize_Parms
	{
		FVector2D NewSurfaceSize;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Authority" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authority-only at runtime. Replicates the new size and rebuilds plane/collision on clients. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authority-only at runtime. Replicates the new size and rebuilds plane/collision on clients." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetWaterSurfaceSize constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewSurfaceSize;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetWaterSurfaceSize_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWaterSurfaceSize constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWaterSurfaceSize Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NewSurfaceSize = { "NewSurfaceSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventSetWaterSurfaceSize_Parms, NewSurfaceSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetWaterSurfaceSize_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewSurfaceSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetWaterSurfaceSize Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetWaterSurfaceSize", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetWaterSurfaceSize_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetWaterSurfaceSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetWaterSurfaceSize(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetWaterSurfaceSize)
{
	P_GET_STRUCT(FVector2D,Z_Param_NewSurfaceSize);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetWaterSurfaceSize(Z_Param_NewSurfaceSize);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetWaterSurfaceSize ****************************

// ********** Begin Class ADMFSwimmableWater Function SetWaterSurfaceZOffset ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFSwimmableWater_SetWaterSurfaceZOffset_Statics
struct UHT_STATICS
{
	struct DMFSwimmableWater_eventSetWaterSurfaceZOffset_Parms
	{
		float NewSurfaceZOffset;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Authority" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetWaterSurfaceZOffset constinit property declarations ****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewSurfaceZOffset;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSwimmableWater_eventSetWaterSurfaceZOffset_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWaterSurfaceZOffset constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWaterSurfaceZOffset Property Definitions ***************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NewSurfaceZOffset = { "NewSurfaceZOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSwimmableWater_eventSetWaterSurfaceZOffset_Parms, NewSurfaceZOffset), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSwimmableWater_eventSetWaterSurfaceZOffset_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewSurfaceZOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetWaterSurfaceZOffset Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFSwimmableWater, nullptr, "SetWaterSurfaceZOffset", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSwimmableWater_eventSetWaterSurfaceZOffset_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSwimmableWater_eventSetWaterSurfaceZOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFSwimmableWater_SetWaterSurfaceZOffset(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFSwimmableWater::execSetWaterSurfaceZOffset)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewSurfaceZOffset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetWaterSurfaceZOffset(Z_Param_NewSurfaceZOffset);
	P_NATIVE_END;
}
// ********** End Class ADMFSwimmableWater Function SetWaterSurfaceZOffset *************************

// ********** Begin Class ADMFSwimmableWater *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFSwimmableWater_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Replicated, Blueprint-derivable swimmable water body for Digimon MMO Framework.\n *\n * The actor owns a visible plane mesh plus a matching overlap volume extending downward from that surface.\n * It does not teleport or author client transforms. The authoritative server decides which water body a player\n * occupies; normal ACharacter movement replication carries the resulting swimming motion to other peers.\n */" },
#endif
		{ "IncludePath", "Game/DMFSwimmableWater.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated, Blueprint-derivable swimmable water body for Digimon MMO Framework.\n\nThe actor owns a visible plane mesh plus a matching overlap volume extending downward from that surface.\nIt does not teleport or author client transforms. The authoritative server decides which water body a player\noccupies; normal ACharacter movement replication carries the resulting swimming motion to other peers." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaterSurfaceMeshComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Visible water surface. Collision is intentionally disabled; SwimmingBounds owns Pawn overlap. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visible water surface. Collision is intentionally disabled; SwimmingBounds owns Pawn overlap." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwimmingBounds_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Query-only Pawn overlap volume automatically sized to the surface plane and configured depth. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Query-only Pawn overlap volume automatically sized to the surface plane and configured depth." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaterSurfaceSize_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Geometry" },
		{ "ClampMin", "100.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Width (X) and length (Y) of both the visible plane and swimming collision bounds in Unreal units. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Width (X) and length (Y) of both the visible plane and swimming collision bounds in Unreal units." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaterDepth_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Geometry" },
		{ "ClampMin", "10.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Swimmable depth below the visible surface plane. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Swimmable depth below the visible surface plane." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceOverlapHeight_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Geometry" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extra overlap height above the plane keeps a surface swimmer registered while their capsule/head breaches the water. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extra overlap height above the plane keeps a surface swimmer registered while their capsule/head breaches the water." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaterSurfaceZOffset_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Geometry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local Z offset of the visible water surface from the actor origin. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local Z offset of the visible water surface from the actor origin." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaterSurfaceMesh_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mesh used for the visible surface. Defaults to Engine/BasicShapes/Plane. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mesh used for the visible surface. Defaults to Engine/BasicShapes/Plane." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaterMaterial_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Project water material. Translucent/SingleLayerWater/custom materials are all supported. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Project water material. Translucent/SingleLayerWater/custom materials are all supported." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoSizeSurfaceMeshToBounds_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Automatically scales WaterSurfaceMesh to WaterSurfaceSize using the mesh asset bounds. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatically scales WaterSurfaceMesh to WaterSurfaceSize using the mesh asset bounds." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSwimmingEnabled_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Authority-owned master switch. Disabled water does not register players as swimming. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Authority-owned master switch. Disabled water does not register players as swimming." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaterPriority_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Higher priority wins if multiple water bodies overlap the same player. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Higher priority wins if multiple water bodies overlap the same player." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceSwimSpeed_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Movement" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---- Swimming movement ---------------------------------------------------------------\n" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---- Swimming movement ---------------------------------------------------------------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnderwaterSwimSpeed_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Movement" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSwimSpeed_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Movement" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwimAcceleration_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Movement" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwimBrakingDeceleration_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Movement" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableSurfaceAssist_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Surface Assist" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keeps an idle/surface swimmer close to the surface without preventing an intentional camera-down dive. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keeps an idle/surface swimmer close to the surface without preventing an intentional camera-down dive." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceRideDepth_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Surface Assist" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Desired actor-origin depth below the water plane while surface swimming. */" },
#endif
		{ "EditCondition", "bEnableSurfaceAssist" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Desired actor-origin depth below the water plane while surface swimming." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceAssistStrength_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Surface Assist" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Vertical correction strength used to settle a surface swimmer onto SurfaceRideDepth. */" },
#endif
		{ "EditCondition", "bEnableSurfaceAssist" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Vertical correction strength used to settle a surface swimmer onto SurfaceRideDepth." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumSurfaceAssistSpeed_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Surface Assist" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum vertical speed injected by surface assist. */" },
#endif
		{ "EditCondition", "bEnableSurfaceAssist" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum vertical speed injected by surface assist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiveCameraForwardZThreshold_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Surface Assist" },
		{ "ClampMax", "0.0" },
		{ "ClampMin", "-1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera forward Z at or below this value counts as an intentional forward-input dive from the surface. */" },
#endif
		{ "EditCondition", "bEnableSurfaceAssist" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera forward Z at or below this value counts as an intentional forward-input dive from the surface." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnderwaterEnterDepth_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Underwater" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Depth below the plane where Surface changes to Underwater. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Depth below the plane where Surface changes to Underwater." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnderwaterExitDepth_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Underwater" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shallower hysteresis point where Underwater changes back to Surface. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shallower hysteresis point where Underwater changes back to Surface." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnderwaterPostProcessSettings_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Underwater Post Process" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Replicated authoring profile consumed only by the locally controlled camera. This lets different water bodies\n     * have different underwater color/PP looks while keeping rendering client-local and gameplay authority unchanged.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
		{ "ShowOnlyInnerProperties", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated authoring profile consumed only by the locally controlled camera. This lets different water bodies\nhave different underwater color/PP looks while keeping rendering client-local and gameplay authority unchanged." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPlayerWaterOverlapChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Swimming Water|Events" },
		{ "ModuleRelativePath", "Public/Game/DMFSwimmableWater.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFSwimmableWater constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaterSurfaceMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SwimmingBounds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WaterSurfaceSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WaterDepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SurfaceOverlapHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WaterSurfaceZOffset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaterSurfaceMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaterMaterial;
	static void NewProp_bAutoSizeSurfaceMeshToBounds_SetBit(void* Obj)
	{
		((ADMFSwimmableWater*)Obj)->bAutoSizeSurfaceMeshToBounds = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoSizeSurfaceMeshToBounds;
	static void NewProp_bSwimmingEnabled_SetBit(void* Obj)
	{
		((ADMFSwimmableWater*)Obj)->bSwimmingEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSwimmingEnabled;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WaterPriority;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SurfaceSwimSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UnderwaterSwimSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSwimSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SwimAcceleration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SwimBrakingDeceleration;
	static void NewProp_bEnableSurfaceAssist_SetBit(void* Obj)
	{
		((ADMFSwimmableWater*)Obj)->bEnableSurfaceAssist = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableSurfaceAssist;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SurfaceRideDepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SurfaceAssistStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumSurfaceAssistSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DiveCameraForwardZThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UnderwaterEnterDepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UnderwaterExitDepth;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UnderwaterPostProcessSettings;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlayerWaterOverlapChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFSwimmableWater constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetDepthBelowSurface"), .Pointer = &ADMFSwimmableWater::execGetDepthBelowSurface },
		{ .NameUTF8 = UTF8TEXT("GetUnderwaterPostProcessSettings"), .Pointer = &ADMFSwimmableWater::execGetUnderwaterPostProcessSettings },
		{ .NameUTF8 = UTF8TEXT("GetWaterBottomWorldZ"), .Pointer = &ADMFSwimmableWater::execGetWaterBottomWorldZ },
		{ .NameUTF8 = UTF8TEXT("GetWaterSurfaceWorldZ"), .Pointer = &ADMFSwimmableWater::execGetWaterSurfaceWorldZ },
		{ .NameUTF8 = UTF8TEXT("HandleSwimmingBoundsBeginOverlap"), .Pointer = &ADMFSwimmableWater::execHandleSwimmingBoundsBeginOverlap },
		{ .NameUTF8 = UTF8TEXT("HandleSwimmingBoundsEndOverlap"), .Pointer = &ADMFSwimmableWater::execHandleSwimmingBoundsEndOverlap },
		{ .NameUTF8 = UTF8TEXT("IsSwimmingEnabled"), .Pointer = &ADMFSwimmableWater::execIsSwimmingEnabled },
		{ .NameUTF8 = UTF8TEXT("IsWorldLocationInsideSwimmingBounds"), .Pointer = &ADMFSwimmableWater::execIsWorldLocationInsideSwimmingBounds },
		{ .NameUTF8 = UTF8TEXT("OnRep_UnderwaterPostProcessSettings"), .Pointer = &ADMFSwimmableWater::execOnRep_UnderwaterPostProcessSettings },
		{ .NameUTF8 = UTF8TEXT("OnRep_WaterConfiguration"), .Pointer = &ADMFSwimmableWater::execOnRep_WaterConfiguration },
		{ .NameUTF8 = UTF8TEXT("RefreshUnderwaterPostProcessPresentation"), .Pointer = &ADMFSwimmableWater::execRefreshUnderwaterPostProcessPresentation },
		{ .NameUTF8 = UTF8TEXT("RefreshWaterGeometry"), .Pointer = &ADMFSwimmableWater::execRefreshWaterGeometry },
		{ .NameUTF8 = UTF8TEXT("SetSurfaceOverlapHeight"), .Pointer = &ADMFSwimmableWater::execSetSurfaceOverlapHeight },
		{ .NameUTF8 = UTF8TEXT("SetSwimmingEnabled"), .Pointer = &ADMFSwimmableWater::execSetSwimmingEnabled },
		{ .NameUTF8 = UTF8TEXT("SetUnderwaterPostProcessEnabled"), .Pointer = &ADMFSwimmableWater::execSetUnderwaterPostProcessEnabled },
		{ .NameUTF8 = UTF8TEXT("SetUnderwaterPostProcessMaterial"), .Pointer = &ADMFSwimmableWater::execSetUnderwaterPostProcessMaterial },
		{ .NameUTF8 = UTF8TEXT("SetUnderwaterPostProcessSettings"), .Pointer = &ADMFSwimmableWater::execSetUnderwaterPostProcessSettings },
		{ .NameUTF8 = UTF8TEXT("SetWaterDepth"), .Pointer = &ADMFSwimmableWater::execSetWaterDepth },
		{ .NameUTF8 = UTF8TEXT("SetWaterMaterial"), .Pointer = &ADMFSwimmableWater::execSetWaterMaterial },
		{ .NameUTF8 = UTF8TEXT("SetWaterPriority"), .Pointer = &ADMFSwimmableWater::execSetWaterPriority },
		{ .NameUTF8 = UTF8TEXT("SetWaterSurfaceSize"), .Pointer = &ADMFSwimmableWater::execSetWaterSurfaceSize },
		{ .NameUTF8 = UTF8TEXT("SetWaterSurfaceZOffset"), .Pointer = &ADMFSwimmableWater::execSetWaterSurfaceZOffset },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFSwimmableWater_BP_OnPlayerEnteredWater, "BP_OnPlayerEnteredWater" }, // bd5f02104e0530538aff89f2aa05a59968f1a856
		{ &Z_Construct_UFunction_ADMFSwimmableWater_BP_OnPlayerExitedWater, "BP_OnPlayerExitedWater" }, // 01fccfd5a2f0cd1efe9e7883700c550796bbb6e4
		{ &Z_Construct_UFunction_ADMFSwimmableWater_GetDepthBelowSurface, "GetDepthBelowSurface" }, // 967f2318e61e569b1b47044d7e998747f48a9248
		{ &Z_Construct_UFunction_ADMFSwimmableWater_GetUnderwaterPostProcessSettings, "GetUnderwaterPostProcessSettings" }, // 086a74d9bcf3134c4cc4824ab7b47e8bb6023527
		{ &Z_Construct_UFunction_ADMFSwimmableWater_GetWaterBottomWorldZ, "GetWaterBottomWorldZ" }, // 475a9a8c12c45adbcb5fd3eae096a6c6e0ec7eb8
		{ &Z_Construct_UFunction_ADMFSwimmableWater_GetWaterSurfaceWorldZ, "GetWaterSurfaceWorldZ" }, // 15140470501c96ff647db9f15affd6d5d3874c29
		{ &Z_Construct_UFunction_ADMFSwimmableWater_HandleSwimmingBoundsBeginOverlap, "HandleSwimmingBoundsBeginOverlap" }, // 7584f6c334657613a11a5bbb4cf3945df7785349
		{ &Z_Construct_UFunction_ADMFSwimmableWater_HandleSwimmingBoundsEndOverlap, "HandleSwimmingBoundsEndOverlap" }, // e1dde6e3ce9c0e10f179a3bad1a7de0483ffdc56
		{ &Z_Construct_UFunction_ADMFSwimmableWater_IsSwimmingEnabled, "IsSwimmingEnabled" }, // b15ea9570271c870254b74be0b6583aae81bda8b
		{ &Z_Construct_UFunction_ADMFSwimmableWater_IsWorldLocationInsideSwimmingBounds, "IsWorldLocationInsideSwimmingBounds" }, // 01db5d6d16484bd5afb4e60324672f07486ccfe0
		{ &Z_Construct_UFunction_ADMFSwimmableWater_OnRep_UnderwaterPostProcessSettings, "OnRep_UnderwaterPostProcessSettings" }, // f5f7fa621b2bc3eb1193925e003b67876b7519fa
		{ &Z_Construct_UFunction_ADMFSwimmableWater_OnRep_WaterConfiguration, "OnRep_WaterConfiguration" }, // 38e541d13c96221529b3a990e4ec4cc17ec0b0ec
		{ &Z_Construct_UFunction_ADMFSwimmableWater_RefreshUnderwaterPostProcessPresentation, "RefreshUnderwaterPostProcessPresentation" }, // 3a50ee9a71e9ed07fd38654b79d38052ce923e55
		{ &Z_Construct_UFunction_ADMFSwimmableWater_RefreshWaterGeometry, "RefreshWaterGeometry" }, // 71b2b2eeae83467d4c8f1cf75a293ee3c8dffb70
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetSurfaceOverlapHeight, "SetSurfaceOverlapHeight" }, // cba794abcded837bf0a22d7095fc69c89e583108
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetSwimmingEnabled, "SetSwimmingEnabled" }, // 9bafdfd0c3975a12fcf58bb4ea12b5018bd3cb56
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetUnderwaterPostProcessEnabled, "SetUnderwaterPostProcessEnabled" }, // c7a86cc538e6befd7d972d60a68a617283a0e797
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetUnderwaterPostProcessMaterial, "SetUnderwaterPostProcessMaterial" }, // 752e6d40f5c18c1796f73dd7e7fe325090a26ef1
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetUnderwaterPostProcessSettings, "SetUnderwaterPostProcessSettings" }, // e7cc7e5346c60735419326c4836707b9a0055d3e
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetWaterDepth, "SetWaterDepth" }, // fab443cf2f9df39735f060e888ef3ff5b19ab2e3
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetWaterMaterial, "SetWaterMaterial" }, // 9b5ae2da3467581602e2524bca61ad4e8aed8ece
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetWaterPriority, "SetWaterPriority" }, // fd0ba24b8b3c513623d159cc046b26bfb1121c98
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetWaterSurfaceSize, "SetWaterSurfaceSize" }, // 18d2c17d5b623e7268b0e3f9b3832337059ee04a
		{ &Z_Construct_UFunction_ADMFSwimmableWater_SetWaterSurfaceZOffset, "SetWaterSurfaceZOffset" }, // 7acb19c178dad67b35135dbfaa5db99727a60736
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFSwimmableWater>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFSwimmableWater Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, SceneRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WaterSurfaceMeshComponent = { "WaterSurfaceMeshComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, WaterSurfaceMeshComponent), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaterSurfaceMeshComponent_MetaData), NewProp_WaterSurfaceMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SwimmingBounds = { "SwimmingBounds", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, SwimmingBounds), Z_Construct_UClass_UBoxComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwimmingBounds_MetaData), NewProp_SwimmingBounds_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_WaterSurfaceSize = { "WaterSurfaceSize", "OnRep_WaterConfiguration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, WaterSurfaceSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaterSurfaceSize_MetaData), NewProp_WaterSurfaceSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_WaterDepth = { "WaterDepth", "OnRep_WaterConfiguration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, WaterDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaterDepth_MetaData), NewProp_WaterDepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SurfaceOverlapHeight = { "SurfaceOverlapHeight", "OnRep_WaterConfiguration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, SurfaceOverlapHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceOverlapHeight_MetaData), NewProp_SurfaceOverlapHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_WaterSurfaceZOffset = { "WaterSurfaceZOffset", "OnRep_WaterConfiguration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, WaterSurfaceZOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaterSurfaceZOffset_MetaData), NewProp_WaterSurfaceZOffset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WaterSurfaceMesh = { "WaterSurfaceMesh", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, WaterSurfaceMesh), Z_Construct_UClass_UStaticMesh, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaterSurfaceMesh_MetaData), NewProp_WaterSurfaceMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WaterMaterial = { "WaterMaterial", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, WaterMaterial), Z_Construct_UClass_UMaterialInterface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaterMaterial_MetaData), NewProp_WaterMaterial_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAutoSizeSurfaceMeshToBounds = { "bAutoSizeSurfaceMeshToBounds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFSwimmableWater), &UHT_STATICS::NewProp_bAutoSizeSurfaceMeshToBounds_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoSizeSurfaceMeshToBounds_MetaData), NewProp_bAutoSizeSurfaceMeshToBounds_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSwimmingEnabled = { "bSwimmingEnabled", "OnRep_WaterConfiguration", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFSwimmableWater), &UHT_STATICS::NewProp_bSwimmingEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSwimmingEnabled_MetaData), NewProp_bSwimmingEnabled_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_WaterPriority = { "WaterPriority", nullptr, (EPropertyFlags)0x0010000000000035, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, WaterPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaterPriority_MetaData), NewProp_WaterPriority_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SurfaceSwimSpeed = { "SurfaceSwimSpeed", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, SurfaceSwimSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceSwimSpeed_MetaData), NewProp_SurfaceSwimSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_UnderwaterSwimSpeed = { "UnderwaterSwimSpeed", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, UnderwaterSwimSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnderwaterSwimSpeed_MetaData), NewProp_UnderwaterSwimSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SprintSwimSpeed = { "SprintSwimSpeed", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, SprintSwimSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSwimSpeed_MetaData), NewProp_SprintSwimSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SwimAcceleration = { "SwimAcceleration", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, SwimAcceleration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwimAcceleration_MetaData), NewProp_SwimAcceleration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SwimBrakingDeceleration = { "SwimBrakingDeceleration", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, SwimBrakingDeceleration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwimBrakingDeceleration_MetaData), NewProp_SwimBrakingDeceleration_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableSurfaceAssist = { "bEnableSurfaceAssist", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFSwimmableWater), &UHT_STATICS::NewProp_bEnableSurfaceAssist_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableSurfaceAssist_MetaData), NewProp_bEnableSurfaceAssist_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SurfaceRideDepth = { "SurfaceRideDepth", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, SurfaceRideDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceRideDepth_MetaData), NewProp_SurfaceRideDepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SurfaceAssistStrength = { "SurfaceAssistStrength", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, SurfaceAssistStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceAssistStrength_MetaData), NewProp_SurfaceAssistStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumSurfaceAssistSpeed = { "MaximumSurfaceAssistSpeed", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, MaximumSurfaceAssistSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumSurfaceAssistSpeed_MetaData), NewProp_MaximumSurfaceAssistSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DiveCameraForwardZThreshold = { "DiveCameraForwardZThreshold", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, DiveCameraForwardZThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiveCameraForwardZThreshold_MetaData), NewProp_DiveCameraForwardZThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_UnderwaterEnterDepth = { "UnderwaterEnterDepth", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, UnderwaterEnterDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnderwaterEnterDepth_MetaData), NewProp_UnderwaterEnterDepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_UnderwaterExitDepth = { "UnderwaterExitDepth", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, UnderwaterExitDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnderwaterExitDepth_MetaData), NewProp_UnderwaterExitDepth_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_UnderwaterPostProcessSettings = { "UnderwaterPostProcessSettings", "OnRep_UnderwaterPostProcessSettings", (EPropertyFlags)0x0010000100000035, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, UnderwaterPostProcessSettings), Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnderwaterPostProcessSettings_MetaData), NewProp_UnderwaterPostProcessSettings_MetaData) }; // 89941e8cb391b29bbd1f13ec7d77bc6e706c3728
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnPlayerWaterOverlapChanged = { "OnPlayerWaterOverlapChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFSwimmableWater, OnPlayerWaterOverlapChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWaterPlayerOverlapChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPlayerWaterOverlapChanged_MetaData), NewProp_OnPlayerWaterOverlapChanged_MetaData) }; // 38c43d73d7e0ff46bae5b5b80559564f7cfe15a0
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterSurfaceMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SwimmingBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterSurfaceSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SurfaceOverlapHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterSurfaceZOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterSurfaceMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAutoSizeSurfaceMeshToBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSwimmingEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WaterPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SurfaceSwimSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UnderwaterSwimSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SprintSwimSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SwimAcceleration,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SwimBrakingDeceleration,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableSurfaceAssist,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SurfaceRideDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SurfaceAssistStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumSurfaceAssistSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DiveCameraForwardZThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UnderwaterEnterDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UnderwaterExitDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UnderwaterPostProcessSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnPlayerWaterOverlapChanged,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFSwimmableWater Property Definitions ************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFSwimmableWater,
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
static void ADMFSwimmableWater_StaticRegisterNativesADMFSwimmableWater()
{
	UClass* Class = ADMFSwimmableWater::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFSwimmableWater;
UClass* Z_Construct_UClass_ADMFSwimmableWater(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFSwimmableWater;
		if (!Z_Registration_Info_UClass_ADMFSwimmableWater.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFSwimmableWater"),
				Z_Registration_Info_UClass_ADMFSwimmableWater.InnerSingleton,
				ADMFSwimmableWater_StaticRegisterNativesADMFSwimmableWater,
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
		return Z_Registration_Info_UClass_ADMFSwimmableWater.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFSwimmableWater.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFSwimmableWater.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFSwimmableWater.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFSwimmableWater::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_WaterSurfaceSize(TEXT("WaterSurfaceSize"));
	static FName Name_WaterDepth(TEXT("WaterDepth"));
	static FName Name_SurfaceOverlapHeight(TEXT("SurfaceOverlapHeight"));
	static FName Name_WaterSurfaceZOffset(TEXT("WaterSurfaceZOffset"));
	static FName Name_bSwimmingEnabled(TEXT("bSwimmingEnabled"));
	static FName Name_WaterPriority(TEXT("WaterPriority"));
	static FName Name_SurfaceSwimSpeed(TEXT("SurfaceSwimSpeed"));
	static FName Name_UnderwaterSwimSpeed(TEXT("UnderwaterSwimSpeed"));
	static FName Name_SprintSwimSpeed(TEXT("SprintSwimSpeed"));
	static FName Name_SwimAcceleration(TEXT("SwimAcceleration"));
	static FName Name_SwimBrakingDeceleration(TEXT("SwimBrakingDeceleration"));
	static FName Name_bEnableSurfaceAssist(TEXT("bEnableSurfaceAssist"));
	static FName Name_SurfaceRideDepth(TEXT("SurfaceRideDepth"));
	static FName Name_SurfaceAssistStrength(TEXT("SurfaceAssistStrength"));
	static FName Name_MaximumSurfaceAssistSpeed(TEXT("MaximumSurfaceAssistSpeed"));
	static FName Name_DiveCameraForwardZThreshold(TEXT("DiveCameraForwardZThreshold"));
	static FName Name_UnderwaterEnterDepth(TEXT("UnderwaterEnterDepth"));
	static FName Name_UnderwaterExitDepth(TEXT("UnderwaterExitDepth"));
	static FName Name_UnderwaterPostProcessSettings(TEXT("UnderwaterPostProcessSettings"));
	const bool bIsValid = true
		&& Name_WaterSurfaceSize == ClassReps[(int32)ENetFields_Private::WaterSurfaceSize].Property->GetFName()
		&& Name_WaterDepth == ClassReps[(int32)ENetFields_Private::WaterDepth].Property->GetFName()
		&& Name_SurfaceOverlapHeight == ClassReps[(int32)ENetFields_Private::SurfaceOverlapHeight].Property->GetFName()
		&& Name_WaterSurfaceZOffset == ClassReps[(int32)ENetFields_Private::WaterSurfaceZOffset].Property->GetFName()
		&& Name_bSwimmingEnabled == ClassReps[(int32)ENetFields_Private::bSwimmingEnabled].Property->GetFName()
		&& Name_WaterPriority == ClassReps[(int32)ENetFields_Private::WaterPriority].Property->GetFName()
		&& Name_SurfaceSwimSpeed == ClassReps[(int32)ENetFields_Private::SurfaceSwimSpeed].Property->GetFName()
		&& Name_UnderwaterSwimSpeed == ClassReps[(int32)ENetFields_Private::UnderwaterSwimSpeed].Property->GetFName()
		&& Name_SprintSwimSpeed == ClassReps[(int32)ENetFields_Private::SprintSwimSpeed].Property->GetFName()
		&& Name_SwimAcceleration == ClassReps[(int32)ENetFields_Private::SwimAcceleration].Property->GetFName()
		&& Name_SwimBrakingDeceleration == ClassReps[(int32)ENetFields_Private::SwimBrakingDeceleration].Property->GetFName()
		&& Name_bEnableSurfaceAssist == ClassReps[(int32)ENetFields_Private::bEnableSurfaceAssist].Property->GetFName()
		&& Name_SurfaceRideDepth == ClassReps[(int32)ENetFields_Private::SurfaceRideDepth].Property->GetFName()
		&& Name_SurfaceAssistStrength == ClassReps[(int32)ENetFields_Private::SurfaceAssistStrength].Property->GetFName()
		&& Name_MaximumSurfaceAssistSpeed == ClassReps[(int32)ENetFields_Private::MaximumSurfaceAssistSpeed].Property->GetFName()
		&& Name_DiveCameraForwardZThreshold == ClassReps[(int32)ENetFields_Private::DiveCameraForwardZThreshold].Property->GetFName()
		&& Name_UnderwaterEnterDepth == ClassReps[(int32)ENetFields_Private::UnderwaterEnterDepth].Property->GetFName()
		&& Name_UnderwaterExitDepth == ClassReps[(int32)ENetFields_Private::UnderwaterExitDepth].Property->GetFName()
		&& Name_UnderwaterPostProcessSettings == ClassReps[(int32)ENetFields_Private::UnderwaterPostProcessSettings].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFSwimmableWater"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFSwimmableWater);
ADMFSwimmableWater::~ADMFSwimmableWater() {}
// ********** End Class ADMFSwimmableWater *********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFPlayerSwimState, TEXT("EDMFPlayerSwimState"), &ZRIE_EDMFPlayerSwimState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 173748440U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings, Z_Construct_UScriptStruct_FDMFUnderwaterPostProcessSettings_Statics::NewStructOps, TEXT("DMFUnderwaterPostProcessSettings"),&Z_Registration_Info_UScriptStruct_FDMFUnderwaterPostProcessSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFUnderwaterPostProcessSettings), 2308185740U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFSwimmableWater, TEXT("ADMFSwimmableWater"), &Z_Registration_Info_UClass_ADMFSwimmableWater, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFSwimmableWater), 161505777U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSwimmableWater_h__Script_DigimonMMOFramework_b2ffc14a3d6bacbe9d4cd05992c62b8bbec2c9f5{
	TEXT("/Script/DigimonMMOFramework"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
