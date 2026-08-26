// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/DMFMusicSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFMusicSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USoundBase(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFMusicStateChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFMusicSubsystem(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFMusicSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFMusicStateChanged *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFMusicStateChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFMusicStateChanged_Parms
	{
		EDMFMusicState PreviousState;
		EDMFMusicState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFMusicStateChanged constinit property declarations *****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_PreviousState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PreviousState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFMusicStateChanged constinit property declarations *******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFMusicStateChanged Property Definitions ****************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_PreviousState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_PreviousState = { "PreviousState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFMusicStateChanged_Parms, PreviousState), Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState, METADATA_PARAMS(0, nullptr) }; // f928cf2bd60af13412523522975620b687e260f0
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFMusicStateChanged_Parms, NewState), Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState, METADATA_PARAMS(0, nullptr) }; // f928cf2bd60af13412523522975620b687e260f0
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousState,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFMusicStateChanged Property Definitions ******************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFMusicStateChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFMusicStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFMusicStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFMusicStateChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFMusicStateChanged ***************************************************

// ********** Begin Class UDMFMusicSubsystem Function GetCurrentMusicState *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFMusicSubsystem_GetCurrentMusicState_Statics
struct UHT_STATICS
{
	struct DMFMusicSubsystem_eventGetCurrentMusicState_Parms
	{
		EDMFMusicState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Audio|Music" },
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentMusicState constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentMusicState constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentMusicState Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMusicSubsystem_eventGetCurrentMusicState_Parms, ReturnValue), Z_Construct_UEnum_DigimonMMOFramework_EDMFMusicState, METADATA_PARAMS(0, nullptr) }; // f928cf2bd60af13412523522975620b687e260f0
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentMusicState Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFMusicSubsystem, nullptr, "GetCurrentMusicState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMusicSubsystem_eventGetCurrentMusicState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMusicSubsystem_eventGetCurrentMusicState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFMusicSubsystem_GetCurrentMusicState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFMusicSubsystem::execGetCurrentMusicState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDMFMusicState*)Z_Param__Result=P_THIS->GetCurrentMusicState();
	P_NATIVE_END;
}
// ********** End Class UDMFMusicSubsystem Function GetCurrentMusicState ***************************

// ********** Begin Class UDMFMusicSubsystem Function IsMusicSuppressed ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFMusicSubsystem_IsMusicSuppressed_Statics
struct UHT_STATICS
{
	struct DMFMusicSubsystem_eventIsMusicSuppressed_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Audio|Music" },
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsMusicSuppressed constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMusicSubsystem_eventIsMusicSuppressed_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsMusicSuppressed constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsMusicSuppressed Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMusicSubsystem_eventIsMusicSuppressed_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsMusicSuppressed Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFMusicSubsystem, nullptr, "IsMusicSuppressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMusicSubsystem_eventIsMusicSuppressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMusicSubsystem_eventIsMusicSuppressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFMusicSubsystem_IsMusicSuppressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFMusicSubsystem::execIsMusicSuppressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsMusicSuppressed();
	P_NATIVE_END;
}
// ********** End Class UDMFMusicSubsystem Function IsMusicSuppressed ******************************

// ********** Begin Class UDMFMusicSubsystem Function RefreshMusicState ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFMusicSubsystem_RefreshMusicState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Audio|Music" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-evaluates the current map/combat context immediately instead of waiting for the short presentation poll. */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-evaluates the current map/combat context immediately instead of waiting for the short presentation poll." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshMusicState constinit property declarations *********************
// ********** End Function RefreshMusicState constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFMusicSubsystem, nullptr, "RefreshMusicState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFMusicSubsystem_RefreshMusicState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFMusicSubsystem::execRefreshMusicState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshMusicState();
	P_NATIVE_END;
}
// ********** End Class UDMFMusicSubsystem Function RefreshMusicState ******************************

// ********** Begin Class UDMFMusicSubsystem Function SetMusicSuppressed ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFMusicSubsystem_SetMusicSuppressed_Statics
struct UHT_STATICS
{
	struct DMFMusicSubsystem_eventSetMusicSuppressed_Parms
	{
		bool bSuppressed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Audio|Music" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Local runtime suppression intended for cinematics or project-owned temporary audio states.\n     * This never edits Project Settings and never replicates to other players.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local runtime suppression intended for cinematics or project-owned temporary audio states.\nThis never edits Project Settings and never replicates to other players." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMusicSuppressed constinit property declarations ********************
	static void NewProp_bSuppressed_SetBit(void* Obj)
	{
		((DMFMusicSubsystem_eventSetMusicSuppressed_Parms*)Obj)->bSuppressed = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuppressed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMusicSuppressed constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMusicSuppressed Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuppressed = { "bSuppressed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMusicSubsystem_eventSetMusicSuppressed_Parms), &UHT_STATICS::NewProp_bSuppressed_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuppressed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetMusicSuppressed Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFMusicSubsystem, nullptr, "SetMusicSuppressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMusicSubsystem_eventSetMusicSuppressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMusicSubsystem_eventSetMusicSuppressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFMusicSubsystem_SetMusicSuppressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFMusicSubsystem::execSetMusicSuppressed)
{
	P_GET_UBOOL(Z_Param_bSuppressed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMusicSuppressed(Z_Param_bSuppressed);
	P_NATIVE_END;
}
// ********** End Class UDMFMusicSubsystem Function SetMusicSuppressed *****************************

// ********** Begin Class UDMFMusicSubsystem *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFMusicSubsystem_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Local presentation-only music director for the framework.\n *\n * The subsystem survives map travel with the GameInstance, automatically chooses Frontend/OpenWorld/Battle\n * music, and crossfades persistent 2D audio components. Battle truth is read from the existing replicated\n * active-partner CombatComponent; no music state or audio event is replicated.\n */" },
#endif
		{ "IncludePath", "Subsystems/DMFMusicSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local presentation-only music director for the framework.\n\nThe subsystem survives map travel with the GameInstance, automatically chooses Frontend/OpenWorld/Battle\nmusic, and crossfades persistent 2D audio components. Battle truth is read from the existing replicated\nactive-partner CombatComponent; no music state or audio event is replicated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMusicStateChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Audio|Music" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired locally whenever the semantic music state changes. */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired locally whenever the semantic music state changes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAudioComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FadingAudioComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSound_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/DMFMusicSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFMusicSubsystem constinit property declarations ***********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMusicStateChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentAudioComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FadingAudioComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFMusicSubsystem constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetCurrentMusicState"), .Pointer = &UDMFMusicSubsystem::execGetCurrentMusicState },
		{ .NameUTF8 = UTF8TEXT("IsMusicSuppressed"), .Pointer = &UDMFMusicSubsystem::execIsMusicSuppressed },
		{ .NameUTF8 = UTF8TEXT("RefreshMusicState"), .Pointer = &UDMFMusicSubsystem::execRefreshMusicState },
		{ .NameUTF8 = UTF8TEXT("SetMusicSuppressed"), .Pointer = &UDMFMusicSubsystem::execSetMusicSuppressed },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFMusicSubsystem_GetCurrentMusicState, "GetCurrentMusicState" }, // 2855e417b5759f6fd764bd260a24c9de5c293553
		{ &Z_Construct_UFunction_UDMFMusicSubsystem_IsMusicSuppressed, "IsMusicSuppressed" }, // 7ab4c9d1dc1ab9fbe35c6188df84220a44d27f90
		{ &Z_Construct_UFunction_UDMFMusicSubsystem_RefreshMusicState, "RefreshMusicState" }, // 754e3c1deb63e81bf64e1981cb8457e605280118
		{ &Z_Construct_UFunction_UDMFMusicSubsystem_SetMusicSuppressed, "SetMusicSuppressed" }, // d99258de93f2bdedc31544748a80c40ee72948f9
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFMusicSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFMusicSubsystem Property Definitions **********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnMusicStateChanged = { "OnMusicStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFMusicSubsystem, OnMusicStateChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFMusicStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMusicStateChanged_MetaData), NewProp_OnMusicStateChanged_MetaData) }; // 921f66c5cef3ec83c24d15bdc01855bf7a201344
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CurrentAudioComponent = { "CurrentAudioComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFMusicSubsystem, CurrentAudioComponent), Z_Construct_UClass_UAudioComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAudioComponent_MetaData), NewProp_CurrentAudioComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FadingAudioComponent = { "FadingAudioComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFMusicSubsystem, FadingAudioComponent), Z_Construct_UClass_UAudioComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FadingAudioComponent_MetaData), NewProp_FadingAudioComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CurrentSound = { "CurrentSound", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFMusicSubsystem, CurrentSound), Z_Construct_UClass_USoundBase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSound_MetaData), NewProp_CurrentSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnMusicStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurrentAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FadingAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurrentSound,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFMusicSubsystem Property Definitions ************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UGameInstanceSubsystem,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFMusicSubsystem,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UDMFMusicSubsystem_StaticRegisterNativesUDMFMusicSubsystem()
{
	UClass* Class = UDMFMusicSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFMusicSubsystem;
UClass* Z_Construct_UClass_UDMFMusicSubsystem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFMusicSubsystem;
		if (!Z_Registration_Info_UClass_UDMFMusicSubsystem.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFMusicSubsystem"),
				Z_Registration_Info_UClass_UDMFMusicSubsystem.InnerSingleton,
				UDMFMusicSubsystem_StaticRegisterNativesUDMFMusicSubsystem,
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
		return Z_Registration_Info_UClass_UDMFMusicSubsystem.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFMusicSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFMusicSubsystem.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFMusicSubsystem.OuterSingleton;
}
#undef UHT_STATICS
UDMFMusicSubsystem::UDMFMusicSubsystem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFMusicSubsystem);
UDMFMusicSubsystem::~UDMFMusicSubsystem() {}
// ********** End Class UDMFMusicSubsystem *********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFMusicSubsystem, TEXT("UDMFMusicSubsystem"), &Z_Registration_Info_UClass_UDMFMusicSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFMusicSubsystem), 372593590U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Subsystems_DMFMusicSubsystem_h__Script_DigimonMMOFramework_f040c8e086d2f18022a5d6bf62e9cd701504ead1{
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
