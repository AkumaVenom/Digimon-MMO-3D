// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFDigimonCarePropActor.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDigimonCarePropActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCarePropActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFCarePropType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCarePropActor(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EDMFCarePropType **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFCarePropType_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFCarePropType>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFCarePropType(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "DigiMeat.Name", "EDMFCarePropType::DigiMeat" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
		{ "Waste.Name", "EDMFCarePropType::Waste" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFCarePropType::DigiMeat", (int64)EDMFCarePropType::DigiMeat },
		{ "EDMFCarePropType::Waste", (int64)EDMFCarePropType::Waste },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFCarePropType",
	"EDMFCarePropType",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFCarePropType;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFCarePropType(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFCarePropType.OuterSingleton)
		{
			ZRIE_EDMFCarePropType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFCarePropType, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFCarePropType"));
		}
		return ZRIE_EDMFCarePropType.OuterSingleton;
	}
	if (!ZRIE_EDMFCarePropType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFCarePropType.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFCarePropType.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFCarePropType ************************************************************

// ********** Begin Class ADMFDigimonCarePropActor Function BP_OnCarePropPresentationReady *********
struct DMFDigimonCarePropActor_eventBP_OnCarePropPresentationReady_Parms
{
	FPrimaryAssetId InSpeciesId;
	EDMFCarePropType InPropType;
};
static FName NAME_ADMFDigimonCarePropActor_BP_OnCarePropPresentationReady = FName(TEXT("BP_OnCarePropPresentationReady"));
void ADMFDigimonCarePropActor::BP_OnCarePropPresentationReady(FPrimaryAssetId InSpeciesId, EDMFCarePropType InPropType)
{
	DMFDigimonCarePropActor_eventBP_OnCarePropPresentationReady_Parms Parms;
	Parms.InSpeciesId=InSpeciesId;
	Parms.InPropType=InPropType;
	UFunction* Func = FindFunctionChecked(NAME_ADMFDigimonCarePropActor_BP_OnCarePropPresentationReady);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCarePropActor_BP_OnCarePropPresentationReady_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Care|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnCarePropPresentationReady constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSpeciesId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InPropType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InPropType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnCarePropPresentationReady constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnCarePropPresentationReady Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InSpeciesId = { "InSpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCarePropActor_eventBP_OnCarePropPresentationReady_Parms, InSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InPropType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InPropType = { "InPropType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCarePropActor_eventBP_OnCarePropPresentationReady_Parms, InPropType), Z_Construct_UEnum_DigimonMMOFramework_EDMFCarePropType, METADATA_PARAMS(0, nullptr) }; // 8c0e4482e3b89ac70e243607b0a8d2c071b30a64
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InSpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InPropType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InPropType,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnCarePropPresentationReady Property Definitions *********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCarePropActor, nullptr, "BP_OnCarePropPresentationReady", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonCarePropActor_eventBP_OnCarePropPresentationReady_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonCarePropActor_eventBP_OnCarePropPresentationReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCarePropActor_BP_OnCarePropPresentationReady(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFDigimonCarePropActor Function BP_OnCarePropPresentationReady ***********

// ********** Begin Class ADMFDigimonCarePropActor Function InitializeCareProp *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCarePropActor_InitializeCareProp_Statics
struct UHT_STATICS
{
	struct DMFDigimonCarePropActor_eventInitializeCareProp_Parms
	{
		FPrimaryAssetId InSpeciesId;
		EDMFCarePropType InPropType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Care|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Initializes the replicated species/type payload. Transform and attachment remain server-owned actor state. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initializes the replicated species/type payload. Transform and attachment remain server-owned actor state." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeCareProp constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSpeciesId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InPropType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InPropType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeCareProp constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeCareProp Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InSpeciesId = { "InSpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCarePropActor_eventInitializeCareProp_Parms, InSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InPropType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InPropType = { "InPropType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonCarePropActor_eventInitializeCareProp_Parms, InPropType), Z_Construct_UEnum_DigimonMMOFramework_EDMFCarePropType, METADATA_PARAMS(0, nullptr) }; // 8c0e4482e3b89ac70e243607b0a8d2c071b30a64
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InSpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InPropType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InPropType,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeCareProp Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCarePropActor, nullptr, "InitializeCareProp", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonCarePropActor_eventInitializeCareProp_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonCarePropActor_eventInitializeCareProp_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFDigimonCarePropActor_InitializeCareProp(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCarePropActor::execInitializeCareProp)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_InSpeciesId);
	P_GET_ENUM(EDMFCarePropType,Z_Param_InPropType);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeCareProp(Z_Param_InSpeciesId,EDMFCarePropType(Z_Param_InPropType));
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCarePropActor Function InitializeCareProp ***********************

// ********** Begin Class ADMFDigimonCarePropActor Function OnRep_Presentation *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCarePropActor_OnRep_Presentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_Presentation constinit property declarations ********************
// ********** End Function OnRep_Presentation constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCarePropActor, nullptr, "OnRep_Presentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCarePropActor_OnRep_Presentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCarePropActor::execOnRep_Presentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_Presentation();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCarePropActor Function OnRep_Presentation ***********************

// ********** Begin Class ADMFDigimonCarePropActor Function RefreshFrameworkCustomDepth ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFDigimonCarePropActor_RefreshFrameworkCustomDepth_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Rendering|Cel Shading" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Reasserts the framework cel-shading contract on every mesh component owned by this Care prop.\n     * DigiMeat and Waste always render into CustomDepth; only the stencil value is project-tunable.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reasserts the framework cel-shading contract on every mesh component owned by this Care prop.\nDigiMeat and Waste always render into CustomDepth; only the stencil value is project-tunable." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshFrameworkCustomDepth constinit property declarations ***********
// ********** End Function RefreshFrameworkCustomDepth constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCarePropActor, nullptr, "RefreshFrameworkCustomDepth", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFDigimonCarePropActor_RefreshFrameworkCustomDepth(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFDigimonCarePropActor::execRefreshFrameworkCustomDepth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshFrameworkCustomDepth();
	P_NATIVE_END;
}
// ********** End Class ADMFDigimonCarePropActor Function RefreshFrameworkCustomDepth **************

// ********** Begin Class ADMFDigimonCarePropActor *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFDigimonCarePropActor_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Lightweight replicated care prop used by the native virtual-pet system.\n * DigiMeat is attached to the Digimon's configured hand socket; Waste is placed on traced ground.\n * Collision, overlap generation and navigation influence are always disabled by the framework.\n */" },
#endif
		{ "IncludePath", "Game/DMFDigimonCarePropActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lightweight replicated care prop used by the native virtual-pet system.\nDigiMeat is attached to the Digimon's configured hand socket; Waste is placed on traced ground.\nCollision, overlap generation and navigation influence are always disabled by the framework." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomDepthStencilValue_MetaData[] = {
		{ "Category", "Digimon MMO|Rendering|Cel Shading" },
		{ "ClampMax", "255" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stencil value written by all Care-prop mesh components while Custom Depth rendering is enabled. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stencil value written by all Care-prop mesh components while Custom Depth rendering is enabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[] = {
		{ "Category", "Digimon MMO|Care|Presentation" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesId_MetaData[] = {
		{ "Category", "Digimon MMO|Care|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropType_MetaData[] = {
		{ "Category", "Digimon MMO|Care|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFDigimonCarePropActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFDigimonCarePropActor constinit property declarations *****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_CustomDepthStencilValue;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PropType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PropType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFDigimonCarePropActor constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("InitializeCareProp"), .Pointer = &ADMFDigimonCarePropActor::execInitializeCareProp },
		{ .NameUTF8 = UTF8TEXT("OnRep_Presentation"), .Pointer = &ADMFDigimonCarePropActor::execOnRep_Presentation },
		{ .NameUTF8 = UTF8TEXT("RefreshFrameworkCustomDepth"), .Pointer = &ADMFDigimonCarePropActor::execRefreshFrameworkCustomDepth },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFDigimonCarePropActor_BP_OnCarePropPresentationReady, "BP_OnCarePropPresentationReady" }, // b1f9bdd61819a3b71a76a258730877169c509f87
		{ &Z_Construct_UFunction_ADMFDigimonCarePropActor_InitializeCareProp, "InitializeCareProp" }, // ee7f6a319a4387331d84e828ff755ec19ee76335
		{ &Z_Construct_UFunction_ADMFDigimonCarePropActor_OnRep_Presentation, "OnRep_Presentation" }, // 8e01f0c3cb7808881cd16d22b681a76d5fe499e4
		{ &Z_Construct_UFunction_ADMFDigimonCarePropActor_RefreshFrameworkCustomDepth, "RefreshFrameworkCustomDepth" }, // 4d3ffb3538f7a2249ee4d6a565ddf2cb80995720
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFDigimonCarePropActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFDigimonCarePropActor Property Definitions ****************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_CustomDepthStencilValue = { "CustomDepthStencilValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCarePropActor, CustomDepthStencilValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomDepthStencilValue_MetaData), NewProp_CustomDepthStencilValue_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCarePropActor, MeshComponent), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComponent_MetaData), NewProp_MeshComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", "OnRep_Presentation", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCarePropActor, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesId_MetaData), NewProp_SpeciesId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_PropType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_PropType = { "PropType", "OnRep_Presentation", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFDigimonCarePropActor, PropType), Z_Construct_UEnum_DigimonMMOFramework_EDMFCarePropType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropType_MetaData), NewProp_PropType_MetaData) }; // 8c0e4482e3b89ac70e243607b0a8d2c071b30a64
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CustomDepthStencilValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PropType,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFDigimonCarePropActor Property Definitions ******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFDigimonCarePropActor,
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
static void ADMFDigimonCarePropActor_StaticRegisterNativesADMFDigimonCarePropActor()
{
	UClass* Class = ADMFDigimonCarePropActor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFDigimonCarePropActor;
UClass* Z_Construct_UClass_ADMFDigimonCarePropActor(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFDigimonCarePropActor;
		if (!Z_Registration_Info_UClass_ADMFDigimonCarePropActor.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonCarePropActor"),
				Z_Registration_Info_UClass_ADMFDigimonCarePropActor.InnerSingleton,
				ADMFDigimonCarePropActor_StaticRegisterNativesADMFDigimonCarePropActor,
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
		return Z_Registration_Info_UClass_ADMFDigimonCarePropActor.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFDigimonCarePropActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFDigimonCarePropActor.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFDigimonCarePropActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFDigimonCarePropActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_SpeciesId(TEXT("SpeciesId"));
	static FName Name_PropType(TEXT("PropType"));
	const bool bIsValid = true
		&& Name_SpeciesId == ClassReps[(int32)ENetFields_Private::SpeciesId].Property->GetFName()
		&& Name_PropType == ClassReps[(int32)ENetFields_Private::PropType].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFDigimonCarePropActor"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFDigimonCarePropActor);
ADMFDigimonCarePropActor::~ADMFDigimonCarePropActor() {}
// ********** End Class ADMFDigimonCarePropActor ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFCarePropType, TEXT("EDMFCarePropType"), &ZRIE_EDMFCarePropType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2349745282U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFDigimonCarePropActor, TEXT("ADMFDigimonCarePropActor"), &Z_Registration_Info_UClass_ADMFDigimonCarePropActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFDigimonCarePropActor), 2340567733U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFDigimonCarePropActor_h__Script_DigimonMMOFramework_32dfd079fba51ab23213379a5ce800610fe56259{
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
