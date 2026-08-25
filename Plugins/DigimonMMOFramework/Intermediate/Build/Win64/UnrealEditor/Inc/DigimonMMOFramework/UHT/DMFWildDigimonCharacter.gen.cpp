// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFWildDigimonCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFWildDigimonCharacter() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFWildDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWildGroundTransitionState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFWildGroundTransitionMode(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonSpeciesData(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFWildDigimonCharacter(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EDMFWildGroundTransitionMode **********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFWildGroundTransitionMode_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFWildGroundTransitionMode>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFWildGroundTransitionMode(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Despawning.Name", "EDMFWildGroundTransitionMode::Despawning" },
		{ "Emerging.Name", "EDMFWildGroundTransitionMode::Emerging" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
		{ "None.Name", "EDMFWildGroundTransitionMode::None" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFWildGroundTransitionMode::None", (int64)EDMFWildGroundTransitionMode::None },
		{ "EDMFWildGroundTransitionMode::Emerging", (int64)EDMFWildGroundTransitionMode::Emerging },
		{ "EDMFWildGroundTransitionMode::Despawning", (int64)EDMFWildGroundTransitionMode::Despawning },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFWildGroundTransitionMode",
	"EDMFWildGroundTransitionMode",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFWildGroundTransitionMode;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFWildGroundTransitionMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFWildGroundTransitionMode.OuterSingleton)
		{
			ZRIE_EDMFWildGroundTransitionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFWildGroundTransitionMode, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFWildGroundTransitionMode"));
		}
		return ZRIE_EDMFWildGroundTransitionMode.OuterSingleton;
	}
	if (!ZRIE_EDMFWildGroundTransitionMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFWildGroundTransitionMode.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFWildGroundTransitionMode.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFWildGroundTransitionMode ************************************************

// ********** Begin ScriptStruct FDMFWildGroundTransitionState *************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FDMFWildGroundTransitionState_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FDMFWildGroundTransitionState>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDMFWildGroundTransitionState); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replicated timing state for synchronized rise/sink presentation without replicating cosmetic mesh movement every frame. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated timing state for synchronized rise/sink presentation without replicating cosmetic mesh movement every frame." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mode_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Depth_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartServerTimeSeconds_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Serial_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Incremented for every new transition so repeated transitions replicate even with identical settings. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Incremented for every new transition so repeated transitions replicate even with identical settings." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rarity_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Snapshot avoids ordering races between the separate SpawnRarity and transition replication fields. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Snapshot avoids ordering races between the separate SpawnRarity and transition replication fields." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDMFWildGroundTransitionState constinit property declarations *****
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_StartServerTimeSeconds;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Serial;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Rarity_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Rarity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDMFWildGroundTransitionState constinit property declarations *******
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDMFWildGroundTransitionState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FDMFWildGroundTransitionState Property Definitions ****************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildGroundTransitionState, Mode), Z_Construct_UEnum_DigimonMMOFramework_EDMFWildGroundTransitionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mode_MetaData), NewProp_Mode_MetaData) }; // 1e877bf241836eb68ef97d35c070e63f859cbc16
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildGroundTransitionState, Depth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Depth_MetaData), NewProp_Depth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildGroundTransitionState, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
const UECodeGen_Private::FDoublePropertyParams UHT_STATICS::NewProp_StartServerTimeSeconds = { "StartServerTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Double, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildGroundTransitionState, StartServerTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartServerTimeSeconds_MetaData), NewProp_StartServerTimeSeconds_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Serial = { "Serial", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildGroundTransitionState, Serial), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Serial_MetaData), NewProp_Serial_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Rarity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Rarity = { "Rarity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FDMFWildGroundTransitionState, Rarity), Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rarity_MetaData), NewProp_Rarity_MetaData) }; // 798c32b425717dfa74b06e356544317cdfe76fdd
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Depth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartServerTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Serial,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rarity_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rarity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FDMFWildGroundTransitionState Property Definitions ******************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	&NewStructOps,
	"DMFWildGroundTransitionState",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FDMFWildGroundTransitionState>(),
	alignof(FDMFWildGroundTransitionState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDMFWildGroundTransitionState;
UScriptStruct* Z_Construct_UScriptStruct_FDMFWildGroundTransitionState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FDMFWildGroundTransitionState.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FDMFWildGroundTransitionState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDMFWildGroundTransitionState, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("DMFWildGroundTransitionState"));
		}
		return Z_Registration_Info_UScriptStruct_FDMFWildGroundTransitionState.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FDMFWildGroundTransitionState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDMFWildGroundTransitionState.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDMFWildGroundTransitionState.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FDMFWildGroundTransitionState ***************************************

// ********** Begin Class ADMFWildDigimonCharacter Function BeginGroundDespawn *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_BeginGroundDespawn_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonCharacter_eventBeginGroundDespawn_Parms
	{
		float Depth;
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Starts a synchronized cosmetic sink and destroys this wild actor on the server when complete. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Starts a synchronized cosmetic sink and destroys this wild actor on the server when complete." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BeginGroundDespawn constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginGroundDespawn constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginGroundDespawn Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonCharacter_eventBeginGroundDespawn_Parms, Depth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonCharacter_eventBeginGroundDespawn_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Depth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BeginGroundDespawn Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "BeginGroundDespawn", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonCharacter_eventBeginGroundDespawn_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonCharacter_eventBeginGroundDespawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_BeginGroundDespawn(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execBeginGroundDespawn)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Depth);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BeginGroundDespawn(Z_Param_Depth,Z_Param_Duration);
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function BeginGroundDespawn ***********************

// ********** Begin Class ADMFWildDigimonCharacter Function BeginGroundEmergence *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_BeginGroundEmergence_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonCharacter_eventBeginGroundEmergence_Parms
	{
		float Depth;
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Starts a synchronized cosmetic rise from below ground. Combat/movement stay disabled until complete. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Starts a synchronized cosmetic rise from below ground. Combat/movement stay disabled until complete." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BeginGroundEmergence constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginGroundEmergence constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginGroundEmergence Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonCharacter_eventBeginGroundEmergence_Parms, Depth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonCharacter_eventBeginGroundEmergence_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Depth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BeginGroundEmergence Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "BeginGroundEmergence", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonCharacter_eventBeginGroundEmergence_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonCharacter_eventBeginGroundEmergence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_BeginGroundEmergence(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execBeginGroundEmergence)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Depth);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BeginGroundEmergence(Z_Param_Depth,Z_Param_Duration);
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function BeginGroundEmergence *********************

// ********** Begin Class ADMFWildDigimonCharacter Function BP_OnGroundTransitionFinished **********
struct DMFWildDigimonCharacter_eventBP_OnGroundTransitionFinished_Parms
{
	EDMFWildGroundTransitionMode CompletedMode;
};
static FName NAME_ADMFWildDigimonCharacter_BP_OnGroundTransitionFinished = FName(TEXT("BP_OnGroundTransitionFinished"));
void ADMFWildDigimonCharacter::BP_OnGroundTransitionFinished(EDMFWildGroundTransitionMode CompletedMode)
{
	DMFWildDigimonCharacter_eventBP_OnGroundTransitionFinished_Parms Parms;
	Parms.CompletedMode=CompletedMode;
	UFunction* Func = FindFunctionChecked(NAME_ADMFWildDigimonCharacter_BP_OnGroundTransitionFinished);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_BP_OnGroundTransitionFinished_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnGroundTransitionFinished constinit property declarations *********
	static const UECodeGen_Private::FBytePropertyParams NewProp_CompletedMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CompletedMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnGroundTransitionFinished constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnGroundTransitionFinished Property Definitions ********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CompletedMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_CompletedMode = { "CompletedMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonCharacter_eventBP_OnGroundTransitionFinished_Parms, CompletedMode), Z_Construct_UEnum_DigimonMMOFramework_EDMFWildGroundTransitionMode, METADATA_PARAMS(0, nullptr) }; // 1e877bf241836eb68ef97d35c070e63f859cbc16
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CompletedMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CompletedMode,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnGroundTransitionFinished Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "BP_OnGroundTransitionFinished", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFWildDigimonCharacter_eventBP_OnGroundTransitionFinished_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFWildDigimonCharacter_eventBP_OnGroundTransitionFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_BP_OnGroundTransitionFinished(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFWildDigimonCharacter Function BP_OnGroundTransitionFinished ************

// ********** Begin Class ADMFWildDigimonCharacter Function BP_OnGroundTransitionStarted ***********
struct DMFWildDigimonCharacter_eventBP_OnGroundTransitionStarted_Parms
{
	EDMFWildGroundTransitionMode Mode;
	EDMFWildSpawnRarity Rarity;
};
static FName NAME_ADMFWildDigimonCharacter_BP_OnGroundTransitionStarted = FName(TEXT("BP_OnGroundTransitionStarted"));
void ADMFWildDigimonCharacter::BP_OnGroundTransitionStarted(EDMFWildGroundTransitionMode Mode, EDMFWildSpawnRarity Rarity)
{
	DMFWildDigimonCharacter_eventBP_OnGroundTransitionStarted_Parms Parms;
	Parms.Mode=Mode;
	Parms.Rarity=Rarity;
	UFunction* Func = FindFunctionChecked(NAME_ADMFWildDigimonCharacter_BP_OnGroundTransitionStarted);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_BP_OnGroundTransitionStarted_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cosmetic hooks run on every machine when replicated emergence/despawn presentation begins/updates. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cosmetic hooks run on every machine when replicated emergence/despawn presentation begins/updates." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnGroundTransitionStarted constinit property declarations **********
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Rarity_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Rarity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnGroundTransitionStarted constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnGroundTransitionStarted Property Definitions *********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonCharacter_eventBP_OnGroundTransitionStarted_Parms, Mode), Z_Construct_UEnum_DigimonMMOFramework_EDMFWildGroundTransitionMode, METADATA_PARAMS(0, nullptr) }; // 1e877bf241836eb68ef97d35c070e63f859cbc16
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Rarity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Rarity = { "Rarity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWildDigimonCharacter_eventBP_OnGroundTransitionStarted_Parms, Rarity), Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity, METADATA_PARAMS(0, nullptr) }; // 798c32b425717dfa74b06e356544317cdfe76fdd
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rarity_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rarity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnGroundTransitionStarted Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "BP_OnGroundTransitionStarted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFWildDigimonCharacter_eventBP_OnGroundTransitionStarted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFWildDigimonCharacter_eventBP_OnGroundTransitionStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_BP_OnGroundTransitionStarted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFWildDigimonCharacter Function BP_OnGroundTransitionStarted *************

// ********** Begin Class ADMFWildDigimonCharacter Function InitializeWildDigimon ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_InitializeWildDigimon_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonCharacter_eventInitializeWildDigimon_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeWildDigimon constinit property declarations *****************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFWildDigimonCharacter_eventInitializeWildDigimon_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeWildDigimon constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeWildDigimon Property Definitions ****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWildDigimonCharacter_eventInitializeWildDigimon_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeWildDigimon Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "InitializeWildDigimon", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonCharacter_eventInitializeWildDigimon_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonCharacter_eventInitializeWildDigimon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_InitializeWildDigimon(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execInitializeWildDigimon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InitializeWildDigimon();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function InitializeWildDigimon ********************

// ********** Begin Class ADMFWildDigimonCharacter Function IsGroundTransitionActive ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_IsGroundTransitionActive_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonCharacter_eventIsGroundTransitionActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsGroundTransitionActive constinit property declarations **************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFWildDigimonCharacter_eventIsGroundTransitionActive_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsGroundTransitionActive constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsGroundTransitionActive Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWildDigimonCharacter_eventIsGroundTransitionActive_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsGroundTransitionActive Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "IsGroundTransitionActive", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonCharacter_eventIsGroundTransitionActive_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonCharacter_eventIsGroundTransitionActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_IsGroundTransitionActive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execIsGroundTransitionActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsGroundTransitionActive();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function IsGroundTransitionActive *****************

// ********** Begin Class ADMFWildDigimonCharacter Function IsWildAutoBattleEnabled ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_IsWildAutoBattleEnabled_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonCharacter_eventIsWildAutoBattleEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|AI" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsWildAutoBattleEnabled constinit property declarations ***************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFWildDigimonCharacter_eventIsWildAutoBattleEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsWildAutoBattleEnabled constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsWildAutoBattleEnabled Property Definitions **************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWildDigimonCharacter_eventIsWildAutoBattleEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsWildAutoBattleEnabled Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "IsWildAutoBattleEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonCharacter_eventIsWildAutoBattleEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonCharacter_eventIsWildAutoBattleEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_IsWildAutoBattleEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execIsWildAutoBattleEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsWildAutoBattleEnabled();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function IsWildAutoBattleEnabled ******************

// ********** Begin Class ADMFWildDigimonCharacter Function IsWildRetaliationEnabled ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_IsWildRetaliationEnabled_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonCharacter_eventIsWildRetaliationEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|AI" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsWildRetaliationEnabled constinit property declarations **************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFWildDigimonCharacter_eventIsWildRetaliationEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsWildRetaliationEnabled constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsWildRetaliationEnabled Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWildDigimonCharacter_eventIsWildRetaliationEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsWildRetaliationEnabled Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "IsWildRetaliationEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonCharacter_eventIsWildRetaliationEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonCharacter_eventIsWildRetaliationEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_IsWildRetaliationEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execIsWildRetaliationEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsWildRetaliationEnabled();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function IsWildRetaliationEnabled *****************

// ********** Begin Class ADMFWildDigimonCharacter Function OnRep_GroundTransitionState ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_OnRep_GroundTransitionState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_GroundTransitionState constinit property declarations ***********
// ********** End Function OnRep_GroundTransitionState constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "OnRep_GroundTransitionState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_OnRep_GroundTransitionState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execOnRep_GroundTransitionState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_GroundTransitionState();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function OnRep_GroundTransitionState **************

// ********** Begin Class ADMFWildDigimonCharacter Function RefreshWildHomeAndAutomation ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_RefreshWildHomeAndAutomation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Spawner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reconfigures the authoritative combat home to the current spawn location after deferred spawning. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reconfigures the authoritative combat home to the current spawn location after deferred spawning." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshWildHomeAndAutomation constinit property declarations **********
// ********** End Function RefreshWildHomeAndAutomation constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "RefreshWildHomeAndAutomation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_RefreshWildHomeAndAutomation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execRefreshWildHomeAndAutomation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshWildHomeAndAutomation();
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function RefreshWildHomeAndAutomation *************

// ********** Begin Class ADMFWildDigimonCharacter Function SetWildAutoBattleEnabled ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_SetWildAutoBattleEnabled_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonCharacter_eventSetWildAutoBattleEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server-authoritative runtime toggle for proactive target acquisition. Retaliation is separate. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-authoritative runtime toggle for proactive target acquisition. Retaliation is separate." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetWildAutoBattleEnabled constinit property declarations **************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFWildDigimonCharacter_eventSetWildAutoBattleEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWildAutoBattleEnabled constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWildAutoBattleEnabled Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWildDigimonCharacter_eventSetWildAutoBattleEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetWildAutoBattleEnabled Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "SetWildAutoBattleEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonCharacter_eventSetWildAutoBattleEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonCharacter_eventSetWildAutoBattleEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_SetWildAutoBattleEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execSetWildAutoBattleEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWildAutoBattleEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function SetWildAutoBattleEnabled *****************

// ********** Begin Class ADMFWildDigimonCharacter Function SetWildRetaliationEnabled **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFWildDigimonCharacter_SetWildRetaliationEnabled_Statics
struct UHT_STATICS
{
	struct DMFWildDigimonCharacter_eventSetWildRetaliationEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server-authoritative runtime toggle for passive-until-attacked defensive behavior. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-authoritative runtime toggle for passive-until-attacked defensive behavior." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetWildRetaliationEnabled constinit property declarations *************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFWildDigimonCharacter_eventSetWildRetaliationEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWildRetaliationEnabled constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWildRetaliationEnabled Property Definitions ************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWildDigimonCharacter_eventSetWildRetaliationEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetWildRetaliationEnabled Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFWildDigimonCharacter, nullptr, "SetWildRetaliationEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWildDigimonCharacter_eventSetWildRetaliationEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWildDigimonCharacter_eventSetWildRetaliationEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFWildDigimonCharacter_SetWildRetaliationEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFWildDigimonCharacter::execSetWildRetaliationEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWildRetaliationEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFWildDigimonCharacter Function SetWildRetaliationEnabled ****************

// ********** Begin Class ADMFWildDigimonCharacter *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFWildDigimonCharacter_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ready-to-place/server-spawn wild or NPC combatant using the same combat component as partners. */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Game/DMFWildDigimonCharacter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ready-to-place/server-spawn wild or NPC combatant using the same combat component as partners." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Species_MetaData[] = {
		{ "Category", "Digimon MMO|Wild" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[] = {
		{ "Category", "Digimon MMO|Wild" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WildCombatTeamId_MetaData[] = {
		{ "Category", "Digimon MMO|Wild" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoBattle_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Class-default autonomous combat preference. Placed wild actors use this directly. Spawner-managed\n     * actors respect this unless a spawn-entry override is configured; the spawner master gate can\n     * always disable autonomous combat for the whole encounter.\n     */" },
#endif
		{ "DisplayName", "Proactive Auto Battle (Aggressive)" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Class-default autonomous combat preference. Placed wild actors use this directly. Spawner-managed\nactors respect this unless a spawn-entry override is configured; the spawner master gate can\nalways disable autonomous combat for the whole encounter." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRetaliateWhenAttacked_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Recommended MMO default. When true, this wild Digimon remains peaceful until a hostile Digimon\n     * actually damages it, then fights only that aggressor until victory, invalid target, or leash break.\n     * This works even when Proactive Auto Battle is disabled.\n     */" },
#endif
		{ "DisplayName", "Retaliate When Attacked" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Recommended MMO default. When true, this wild Digimon remains peaceful until a hostile Digimon\nactually damages it, then fights only that aggressor until victory, invalid target, or leash break.\nThis works even when Proactive Auto Battle is disabled." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AggroRange_MetaData[] = {
		{ "Category", "Digimon MMO|Wild" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeashRange_MetaData[] = {
		{ "Category", "Digimon MMO|Wild" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutgoingDamageMultiplier_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Balance" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Per-wild-class combat tuning. Keep at 1.0 for normal wild encounters; bosses can override in Blueprint defaults. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-wild-class combat tuning. Keep at 1.0 for normal wild encounters; bosses can override in Blueprint defaults." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IncomingDamageMultiplier_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Balance" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableFreeRoaming_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Roaming" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spawner-managed wild Digimon can idle-roam without escaping their individual spawn home. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spawner-managed wild Digimon can idle-roam without escaping their individual spawn home." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoamRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Roaming" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableFreeRoaming" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumRoamDelay_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Roaming" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bEnableFreeRoaming" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumRoamDelay_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Roaming" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bEnableFreeRoaming" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoamAcceptanceRadius_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Roaming" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableFreeRoaming" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSpawnerManaged_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Spawner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Set by DMFWildDigimonSpawner before BeginPlay. Placed wild actors can leave this false. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set by DMFWildDigimonSpawner before BeginPlay. Placed wild actors can leave this false." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnRarity_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Spawner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replicated rarity roll chosen by the authoritative spawner. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated rarity roll chosen by the authoritative spawner." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnHomeLocation_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Spawner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Individual home point used by free roaming and the combat leash. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Individual home point used by free roaming and the combat leash." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStartWithGroundEmergence_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spawner may enable this before BeginPlay to make the visual mesh rise out of the ground. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spawner may enable this before BeginPlay to make the visual mesh rise out of the ground." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundEmergenceDepth_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bStartWithGroundEmergence" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundEmergenceDuration_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
		{ "ClampMin", "0.05" },
		{ "EditCondition", "bStartWithGroundEmergence" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundTransitionState_MetaData[] = {
		{ "Category", "Digimon MMO|Wild|Presentation" },
		{ "ModuleRelativePath", "Public/Game/DMFWildDigimonCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFWildDigimonCharacter constinit property declarations *****************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Species;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static const UECodeGen_Private::FNamePropertyParams NewProp_WildCombatTeamId;
	static void NewProp_bAutoBattle_SetBit(void* Obj)
	{
		((ADMFWildDigimonCharacter*)Obj)->bAutoBattle = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoBattle;
	static void NewProp_bRetaliateWhenAttacked_SetBit(void* Obj)
	{
		((ADMFWildDigimonCharacter*)Obj)->bRetaliateWhenAttacked = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRetaliateWhenAttacked;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AggroRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LeashRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutgoingDamageMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IncomingDamageMultiplier;
	static void NewProp_bEnableFreeRoaming_SetBit(void* Obj)
	{
		((ADMFWildDigimonCharacter*)Obj)->bEnableFreeRoaming = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableFreeRoaming;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RoamRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumRoamDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumRoamDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RoamAcceptanceRadius;
	static void NewProp_bSpawnerManaged_SetBit(void* Obj)
	{
		((ADMFWildDigimonCharacter*)Obj)->bSpawnerManaged = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSpawnerManaged;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SpawnRarity_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SpawnRarity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnHomeLocation;
	static void NewProp_bStartWithGroundEmergence_SetBit(void* Obj)
	{
		((ADMFWildDigimonCharacter*)Obj)->bStartWithGroundEmergence = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStartWithGroundEmergence;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundEmergenceDepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundEmergenceDuration;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GroundTransitionState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFWildDigimonCharacter constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BeginGroundDespawn"), .Pointer = &ADMFWildDigimonCharacter::execBeginGroundDespawn },
		{ .NameUTF8 = UTF8TEXT("BeginGroundEmergence"), .Pointer = &ADMFWildDigimonCharacter::execBeginGroundEmergence },
		{ .NameUTF8 = UTF8TEXT("InitializeWildDigimon"), .Pointer = &ADMFWildDigimonCharacter::execInitializeWildDigimon },
		{ .NameUTF8 = UTF8TEXT("IsGroundTransitionActive"), .Pointer = &ADMFWildDigimonCharacter::execIsGroundTransitionActive },
		{ .NameUTF8 = UTF8TEXT("IsWildAutoBattleEnabled"), .Pointer = &ADMFWildDigimonCharacter::execIsWildAutoBattleEnabled },
		{ .NameUTF8 = UTF8TEXT("IsWildRetaliationEnabled"), .Pointer = &ADMFWildDigimonCharacter::execIsWildRetaliationEnabled },
		{ .NameUTF8 = UTF8TEXT("OnRep_GroundTransitionState"), .Pointer = &ADMFWildDigimonCharacter::execOnRep_GroundTransitionState },
		{ .NameUTF8 = UTF8TEXT("RefreshWildHomeAndAutomation"), .Pointer = &ADMFWildDigimonCharacter::execRefreshWildHomeAndAutomation },
		{ .NameUTF8 = UTF8TEXT("SetWildAutoBattleEnabled"), .Pointer = &ADMFWildDigimonCharacter::execSetWildAutoBattleEnabled },
		{ .NameUTF8 = UTF8TEXT("SetWildRetaliationEnabled"), .Pointer = &ADMFWildDigimonCharacter::execSetWildRetaliationEnabled },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_BeginGroundDespawn, "BeginGroundDespawn" }, // 888e0855d96e9861f3b07113330bbde58aa3b247
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_BeginGroundEmergence, "BeginGroundEmergence" }, // f3a5fdb6f8eb58d16cc7827b2920ffc17daf36d4
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_BP_OnGroundTransitionFinished, "BP_OnGroundTransitionFinished" }, // a7dacef9b1b97306f26b837e7199c07fb6652a89
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_BP_OnGroundTransitionStarted, "BP_OnGroundTransitionStarted" }, // 2b5667de447df13ce508590bc66b343b133f2a59
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_InitializeWildDigimon, "InitializeWildDigimon" }, // f7e5202451256876fb3ed588a85e8f443c0884b5
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_IsGroundTransitionActive, "IsGroundTransitionActive" }, // 62feea28d353183283799835596efa3ab380a5df
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_IsWildAutoBattleEnabled, "IsWildAutoBattleEnabled" }, // 0efde4b2b04e118cf94c625e18c8136623924fdc
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_IsWildRetaliationEnabled, "IsWildRetaliationEnabled" }, // 6b7fba2e7319c311bd502bf0918651243783bbef
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_OnRep_GroundTransitionState, "OnRep_GroundTransitionState" }, // 10c8b4067707db08717888c23be15b0ab07bf04f
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_RefreshWildHomeAndAutomation, "RefreshWildHomeAndAutomation" }, // 6bd036b8dede3bf8a4a9748648a80ddbb8162162
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_SetWildAutoBattleEnabled, "SetWildAutoBattleEnabled" }, // 99d47d199d6a6430a21279d294af39c5b51d9c0d
		{ &Z_Construct_UFunction_ADMFWildDigimonCharacter_SetWildRetaliationEnabled, "SetWildRetaliationEnabled" }, // 4667fb626a63d5a37ea2c5774da7cd1c7ffec58d
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFWildDigimonCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFWildDigimonCharacter Property Definitions ****************************
const UECodeGen_Private::FSoftObjectPropertyParams UHT_STATICS::NewProp_Species = { "Species", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, Species), Z_Construct_UClass_UDMFDigimonSpeciesData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Species_MetaData), NewProp_Species_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, Level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Level_MetaData), NewProp_Level_MetaData) };
const UECodeGen_Private::FNamePropertyParams UHT_STATICS::NewProp_WildCombatTeamId = { "WildCombatTeamId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, WildCombatTeamId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WildCombatTeamId_MetaData), NewProp_WildCombatTeamId_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAutoBattle = { "bAutoBattle", nullptr, (EPropertyFlags)0x0010000000000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonCharacter), &UHT_STATICS::NewProp_bAutoBattle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoBattle_MetaData), NewProp_bAutoBattle_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRetaliateWhenAttacked = { "bRetaliateWhenAttacked", nullptr, (EPropertyFlags)0x0010000000000035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonCharacter), &UHT_STATICS::NewProp_bRetaliateWhenAttacked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRetaliateWhenAttacked_MetaData), NewProp_bRetaliateWhenAttacked_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AggroRange = { "AggroRange", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, AggroRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AggroRange_MetaData), NewProp_AggroRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LeashRange = { "LeashRange", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, LeashRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeashRange_MetaData), NewProp_LeashRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_OutgoingDamageMultiplier = { "OutgoingDamageMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, OutgoingDamageMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutgoingDamageMultiplier_MetaData), NewProp_OutgoingDamageMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_IncomingDamageMultiplier = { "IncomingDamageMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, IncomingDamageMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IncomingDamageMultiplier_MetaData), NewProp_IncomingDamageMultiplier_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableFreeRoaming = { "bEnableFreeRoaming", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonCharacter), &UHT_STATICS::NewProp_bEnableFreeRoaming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableFreeRoaming_MetaData), NewProp_bEnableFreeRoaming_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_RoamRadius = { "RoamRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, RoamRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoamRadius_MetaData), NewProp_RoamRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinimumRoamDelay = { "MinimumRoamDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, MinimumRoamDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumRoamDelay_MetaData), NewProp_MinimumRoamDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaximumRoamDelay = { "MaximumRoamDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, MaximumRoamDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumRoamDelay_MetaData), NewProp_MaximumRoamDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_RoamAcceptanceRadius = { "RoamAcceptanceRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, RoamAcceptanceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoamAcceptanceRadius_MetaData), NewProp_RoamAcceptanceRadius_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSpawnerManaged = { "bSpawnerManaged", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonCharacter), &UHT_STATICS::NewProp_bSpawnerManaged_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSpawnerManaged_MetaData), NewProp_bSpawnerManaged_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_SpawnRarity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_SpawnRarity = { "SpawnRarity", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, SpawnRarity), Z_Construct_UEnum_DigimonMMOFramework_EDMFWildSpawnRarity, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnRarity_MetaData), NewProp_SpawnRarity_MetaData) }; // 798c32b425717dfa74b06e356544317cdfe76fdd
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpawnHomeLocation = { "SpawnHomeLocation", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, SpawnHomeLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnHomeLocation_MetaData), NewProp_SpawnHomeLocation_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bStartWithGroundEmergence = { "bStartWithGroundEmergence", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ADMFWildDigimonCharacter), &UHT_STATICS::NewProp_bStartWithGroundEmergence_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStartWithGroundEmergence_MetaData), NewProp_bStartWithGroundEmergence_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GroundEmergenceDepth = { "GroundEmergenceDepth", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, GroundEmergenceDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundEmergenceDepth_MetaData), NewProp_GroundEmergenceDepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_GroundEmergenceDuration = { "GroundEmergenceDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, GroundEmergenceDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundEmergenceDuration_MetaData), NewProp_GroundEmergenceDuration_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_GroundTransitionState = { "GroundTransitionState", "OnRep_GroundTransitionState", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFWildDigimonCharacter, GroundTransitionState), Z_Construct_UScriptStruct_FDMFWildGroundTransitionState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundTransitionState_MetaData), NewProp_GroundTransitionState_MetaData) }; // eb7fc614bb236fdc7e90a392b17d4f0fc90d3d84
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Species,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Level,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WildCombatTeamId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAutoBattle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRetaliateWhenAttacked,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AggroRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LeashRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutgoingDamageMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_IncomingDamageMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableFreeRoaming,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RoamRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinimumRoamDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaximumRoamDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RoamAcceptanceRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSpawnerManaged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnRarity_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnRarity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpawnHomeLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bStartWithGroundEmergence,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundEmergenceDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundEmergenceDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GroundTransitionState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFWildDigimonCharacter Property Definitions ******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_ADMFDigimonCharacter,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFWildDigimonCharacter,
	"Game",
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
static void ADMFWildDigimonCharacter_StaticRegisterNativesADMFWildDigimonCharacter()
{
	UClass* Class = ADMFWildDigimonCharacter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFWildDigimonCharacter;
UClass* Z_Construct_UClass_ADMFWildDigimonCharacter(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFWildDigimonCharacter;
		if (!Z_Registration_Info_UClass_ADMFWildDigimonCharacter.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFWildDigimonCharacter"),
				Z_Registration_Info_UClass_ADMFWildDigimonCharacter.InnerSingleton,
				ADMFWildDigimonCharacter_StaticRegisterNativesADMFWildDigimonCharacter,
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
		return Z_Registration_Info_UClass_ADMFWildDigimonCharacter.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFWildDigimonCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFWildDigimonCharacter.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFWildDigimonCharacter.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ADMFWildDigimonCharacter::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_bAutoBattle(TEXT("bAutoBattle"));
	static FName Name_bRetaliateWhenAttacked(TEXT("bRetaliateWhenAttacked"));
	static FName Name_bSpawnerManaged(TEXT("bSpawnerManaged"));
	static FName Name_SpawnRarity(TEXT("SpawnRarity"));
	static FName Name_SpawnHomeLocation(TEXT("SpawnHomeLocation"));
	static FName Name_GroundTransitionState(TEXT("GroundTransitionState"));
	const bool bIsValid = true
		&& Name_bAutoBattle == ClassReps[(int32)ENetFields_Private::bAutoBattle].Property->GetFName()
		&& Name_bRetaliateWhenAttacked == ClassReps[(int32)ENetFields_Private::bRetaliateWhenAttacked].Property->GetFName()
		&& Name_bSpawnerManaged == ClassReps[(int32)ENetFields_Private::bSpawnerManaged].Property->GetFName()
		&& Name_SpawnRarity == ClassReps[(int32)ENetFields_Private::SpawnRarity].Property->GetFName()
		&& Name_SpawnHomeLocation == ClassReps[(int32)ENetFields_Private::SpawnHomeLocation].Property->GetFName()
		&& Name_GroundTransitionState == ClassReps[(int32)ENetFields_Private::GroundTransitionState].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ADMFWildDigimonCharacter"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFWildDigimonCharacter);
ADMFWildDigimonCharacter::~ADMFWildDigimonCharacter() {}
// ********** End Class ADMFWildDigimonCharacter ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFWildGroundTransitionMode, TEXT("EDMFWildGroundTransitionMode"), &ZRIE_EDMFWildGroundTransitionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 512195570U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FDMFWildGroundTransitionState, Z_Construct_UScriptStruct_FDMFWildGroundTransitionState_Statics::NewStructOps, TEXT("DMFWildGroundTransitionState"),&Z_Registration_Info_UScriptStruct_FDMFWildGroundTransitionState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDMFWildGroundTransitionState), 3951019540U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFWildDigimonCharacter, TEXT("ADMFWildDigimonCharacter"), &Z_Registration_Info_UClass_ADMFWildDigimonCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFWildDigimonCharacter), 3042341812U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFWildDigimonCharacter_h__Script_DigimonMMOFramework_2bc73602dee7e556793b830c913f351229bebaee{
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
