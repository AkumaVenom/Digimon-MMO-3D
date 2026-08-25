// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFSessionSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFSessionSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFFrontendStatusChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFSessionSubsystem(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFSessionSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFFrontendStatusChanged *********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFFrontendStatusChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFFrontendStatusChanged_Parms
	{
		FText Status;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Status_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFFrontendStatusChanged constinit property declarations *************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Status;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFFrontendStatusChanged constinit property declarations ***************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFFrontendStatusChanged Property Definitions ************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Status = { "Status", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFFrontendStatusChanged_Parms, Status), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Status_MetaData), NewProp_Status_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Status,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFFrontendStatusChanged Property Definitions **************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFFrontendStatusChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFFrontendStatusChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFFrontendStatusChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFFrontendStatusChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFFrontendStatusChanged ***********************************************

// ********** Begin Class UDMFSessionSubsystem Function GetLastStatus ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSessionSubsystem_GetLastStatus_Statics
struct UHT_STATICS
{
	struct DMFSessionSubsystem_eventGetLastStatus_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLastStatus constinit property declarations *************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLastStatus constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLastStatus Property Definitions ************************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSessionSubsystem_eventGetLastStatus_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetLastStatus Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSessionSubsystem, nullptr, "GetLastStatus", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSessionSubsystem_eventGetLastStatus_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSessionSubsystem_eventGetLastStatus_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFSessionSubsystem_GetLastStatus(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSessionSubsystem::execGetLastStatus)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetLastStatus();
	P_NATIVE_END;
}
// ********** End Class UDMFSessionSubsystem Function GetLastStatus ********************************

// ********** Begin Class UDMFSessionSubsystem Function GetStagedUsername **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSessionSubsystem_GetStagedUsername_Statics
struct UHT_STATICS
{
	struct DMFSessionSubsystem_eventGetStagedUsername_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetStagedUsername constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetStagedUsername constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetStagedUsername Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSessionSubsystem_eventGetStagedUsername_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetStagedUsername Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSessionSubsystem, nullptr, "GetStagedUsername", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSessionSubsystem_eventGetStagedUsername_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSessionSubsystem_eventGetStagedUsername_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFSessionSubsystem_GetStagedUsername(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSessionSubsystem::execGetStagedUsername)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetStagedUsername();
	P_NATIVE_END;
}
// ********** End Class UDMFSessionSubsystem Function GetStagedUsername ****************************

// ********** Begin Class UDMFSessionSubsystem Function HostAndPlay ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSessionSubsystem_HostAndPlay_Statics
struct UHT_STATICS
{
	struct DMFSessionSubsystem_eventHostAndPlay_Parms
	{
		FText OutMessage;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HostAndPlay constinit property declarations ***************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutMessage;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSessionSubsystem_eventHostAndPlay_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HostAndPlay constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HostAndPlay Property Definitions **************************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_OutMessage = { "OutMessage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSessionSubsystem_eventHostAndPlay_Parms, OutMessage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSessionSubsystem_eventHostAndPlay_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HostAndPlay Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSessionSubsystem, nullptr, "HostAndPlay", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSessionSubsystem_eventHostAndPlay_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSessionSubsystem_eventHostAndPlay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFSessionSubsystem_HostAndPlay(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSessionSubsystem::execHostAndPlay)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_OutMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HostAndPlay(Z_Param_Out_OutMessage);
	P_NATIVE_END;
}
// ********** End Class UDMFSessionSubsystem Function HostAndPlay **********************************

// ********** Begin Class UDMFSessionSubsystem Function IsAdminUnlocked ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSessionSubsystem_IsAdminUnlocked_Statics
struct UHT_STATICS
{
	struct DMFSessionSubsystem_eventIsAdminUnlocked_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsAdminUnlocked constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSessionSubsystem_eventIsAdminUnlocked_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsAdminUnlocked constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsAdminUnlocked Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSessionSubsystem_eventIsAdminUnlocked_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsAdminUnlocked Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSessionSubsystem, nullptr, "IsAdminUnlocked", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSessionSubsystem_eventIsAdminUnlocked_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSessionSubsystem_eventIsAdminUnlocked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFSessionSubsystem_IsAdminUnlocked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSessionSubsystem::execIsAdminUnlocked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsAdminUnlocked();
	P_NATIVE_END;
}
// ********** End Class UDMFSessionSubsystem Function IsAdminUnlocked ******************************

// ********** Begin Class UDMFSessionSubsystem Function IsLoggedInLocally **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSessionSubsystem_IsLoggedInLocally_Statics
struct UHT_STATICS
{
	struct DMFSessionSubsystem_eventIsLoggedInLocally_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsLoggedInLocally constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSessionSubsystem_eventIsLoggedInLocally_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsLoggedInLocally constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsLoggedInLocally Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSessionSubsystem_eventIsLoggedInLocally_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsLoggedInLocally Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSessionSubsystem, nullptr, "IsLoggedInLocally", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSessionSubsystem_eventIsLoggedInLocally_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSessionSubsystem_eventIsLoggedInLocally_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFSessionSubsystem_IsLoggedInLocally(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSessionSubsystem::execIsLoggedInLocally)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsLoggedInLocally();
	P_NATIVE_END;
}
// ********** End Class UDMFSessionSubsystem Function IsLoggedInLocally ****************************

// ********** Begin Class UDMFSessionSubsystem Function JoinGame ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSessionSubsystem_JoinGame_Statics
struct UHT_STATICS
{
	struct DMFSessionSubsystem_eventJoinGame_Parms
	{
		FText OutMessage;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function JoinGame constinit property declarations ******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutMessage;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSessionSubsystem_eventJoinGame_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function JoinGame constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function JoinGame Property Definitions *****************************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_OutMessage = { "OutMessage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSessionSubsystem_eventJoinGame_Parms, OutMessage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSessionSubsystem_eventJoinGame_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function JoinGame Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSessionSubsystem, nullptr, "JoinGame", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSessionSubsystem_eventJoinGame_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSessionSubsystem_eventJoinGame_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFSessionSubsystem_JoinGame(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSessionSubsystem::execJoinGame)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_OutMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->JoinGame(Z_Param_Out_OutMessage);
	P_NATIVE_END;
}
// ********** End Class UDMFSessionSubsystem Function JoinGame *************************************

// ********** Begin Class UDMFSessionSubsystem Function Login **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSessionSubsystem_Login_Statics
struct UHT_STATICS
{
	struct DMFSessionSubsystem_eventLogin_Parms
	{
		FString Username;
		FString Password;
		FText OutMessage;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Username_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Login constinit property declarations *********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Username;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutMessage;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSessionSubsystem_eventLogin_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Login constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Login Property Definitions ********************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Username = { "Username", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSessionSubsystem_eventLogin_Parms, Username), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Username_MetaData), NewProp_Username_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSessionSubsystem_eventLogin_Parms, Password), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Password_MetaData), NewProp_Password_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_OutMessage = { "OutMessage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSessionSubsystem_eventLogin_Parms, OutMessage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSessionSubsystem_eventLogin_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Username,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Password,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Login Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSessionSubsystem, nullptr, "Login", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSessionSubsystem_eventLogin_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSessionSubsystem_eventLogin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFSessionSubsystem_Login(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSessionSubsystem::execLogin)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Username);
	P_GET_PROPERTY(FStrProperty,Z_Param_Password);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_OutMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Login(Z_Param_Username,Z_Param_Password,Z_Param_Out_OutMessage);
	P_NATIVE_END;
}
// ********** End Class UDMFSessionSubsystem Function Login ****************************************

// ********** Begin Class UDMFSessionSubsystem Function Logout *************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSessionSubsystem_Logout_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Logout constinit property declarations ********************************
// ********** End Function Logout constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSessionSubsystem, nullptr, "Logout", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFSessionSubsystem_Logout(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSessionSubsystem::execLogout)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Logout();
	P_NATIVE_END;
}
// ********** End Class UDMFSessionSubsystem Function Logout ***************************************

// ********** Begin Class UDMFSessionSubsystem Function UnlockAdmin ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSessionSubsystem_UnlockAdmin_Statics
struct UHT_STATICS
{
	struct DMFSessionSubsystem_eventUnlockAdmin_Parms
	{
		FString AdminPassword;
		FText OutMessage;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdminPassword_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function UnlockAdmin constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdminPassword;
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutMessage;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFSessionSubsystem_eventUnlockAdmin_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnlockAdmin constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnlockAdmin Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_AdminPassword = { "AdminPassword", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSessionSubsystem_eventUnlockAdmin_Parms, AdminPassword), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdminPassword_MetaData), NewProp_AdminPassword_MetaData) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_OutMessage = { "OutMessage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFSessionSubsystem_eventUnlockAdmin_Parms, OutMessage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFSessionSubsystem_eventUnlockAdmin_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AdminPassword,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function UnlockAdmin Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSessionSubsystem, nullptr, "UnlockAdmin", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFSessionSubsystem_eventUnlockAdmin_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFSessionSubsystem_eventUnlockAdmin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFSessionSubsystem_UnlockAdmin(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSessionSubsystem::execUnlockAdmin)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AdminPassword);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_OutMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->UnlockAdmin(Z_Param_AdminPassword,Z_Param_Out_OutMessage);
	P_NATIVE_END;
}
// ********** End Class UDMFSessionSubsystem Function UnlockAdmin **********************************

// ********** Begin Class UDMFSessionSubsystem *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFSessionSubsystem_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Game/DMFSessionSubsystem.h" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStatusChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Frontend" },
		{ "ModuleRelativePath", "Public/Game/DMFSessionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFSessionSubsystem constinit property declarations *********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStatusChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFSessionSubsystem constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetLastStatus"), .Pointer = &UDMFSessionSubsystem::execGetLastStatus },
		{ .NameUTF8 = UTF8TEXT("GetStagedUsername"), .Pointer = &UDMFSessionSubsystem::execGetStagedUsername },
		{ .NameUTF8 = UTF8TEXT("HostAndPlay"), .Pointer = &UDMFSessionSubsystem::execHostAndPlay },
		{ .NameUTF8 = UTF8TEXT("IsAdminUnlocked"), .Pointer = &UDMFSessionSubsystem::execIsAdminUnlocked },
		{ .NameUTF8 = UTF8TEXT("IsLoggedInLocally"), .Pointer = &UDMFSessionSubsystem::execIsLoggedInLocally },
		{ .NameUTF8 = UTF8TEXT("JoinGame"), .Pointer = &UDMFSessionSubsystem::execJoinGame },
		{ .NameUTF8 = UTF8TEXT("Login"), .Pointer = &UDMFSessionSubsystem::execLogin },
		{ .NameUTF8 = UTF8TEXT("Logout"), .Pointer = &UDMFSessionSubsystem::execLogout },
		{ .NameUTF8 = UTF8TEXT("UnlockAdmin"), .Pointer = &UDMFSessionSubsystem::execUnlockAdmin },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFSessionSubsystem_GetLastStatus, "GetLastStatus" }, // 294650b4c39fc2491ae542c7cc42c6458e67ddae
		{ &Z_Construct_UFunction_UDMFSessionSubsystem_GetStagedUsername, "GetStagedUsername" }, // d618c632e742b69f2a41e8a4cb59028085da6259
		{ &Z_Construct_UFunction_UDMFSessionSubsystem_HostAndPlay, "HostAndPlay" }, // 7464e91a13a3cb7ab377f3cc75350d2f0434ff19
		{ &Z_Construct_UFunction_UDMFSessionSubsystem_IsAdminUnlocked, "IsAdminUnlocked" }, // 2eff2a2b73752c45e57aa47d00631543f0d8c436
		{ &Z_Construct_UFunction_UDMFSessionSubsystem_IsLoggedInLocally, "IsLoggedInLocally" }, // f4d741ae898ac6a351ae049e63260dd386a7a882
		{ &Z_Construct_UFunction_UDMFSessionSubsystem_JoinGame, "JoinGame" }, // 0634a6e536bc531827a18bf04d602de0c6e5a131
		{ &Z_Construct_UFunction_UDMFSessionSubsystem_Login, "Login" }, // f7adfff2205b594bd2654d80a9910abd717525d3
		{ &Z_Construct_UFunction_UDMFSessionSubsystem_Logout, "Logout" }, // 17eb4fb8f5551ec9c1b807d13983cdd046be5504
		{ &Z_Construct_UFunction_UDMFSessionSubsystem_UnlockAdmin, "UnlockAdmin" }, // 5b1a46f659ca90b5c09511a7038a71e4d4f63dac
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFSessionSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFSessionSubsystem Property Definitions ********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnStatusChanged = { "OnStatusChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFSessionSubsystem, OnStatusChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFFrontendStatusChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStatusChanged_MetaData), NewProp_OnStatusChanged_MetaData) }; // 73cde8e3ead89f503da69689e9d6d4f5a5eadc99
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnStatusChanged,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFSessionSubsystem Property Definitions **********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UGameInstanceSubsystem,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFSessionSubsystem,
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
static void UDMFSessionSubsystem_StaticRegisterNativesUDMFSessionSubsystem()
{
	UClass* Class = UDMFSessionSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFSessionSubsystem;
UClass* Z_Construct_UClass_UDMFSessionSubsystem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFSessionSubsystem;
		if (!Z_Registration_Info_UClass_UDMFSessionSubsystem.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFSessionSubsystem"),
				Z_Registration_Info_UClass_UDMFSessionSubsystem.InnerSingleton,
				UDMFSessionSubsystem_StaticRegisterNativesUDMFSessionSubsystem,
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
		return Z_Registration_Info_UClass_UDMFSessionSubsystem.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFSessionSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFSessionSubsystem.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFSessionSubsystem.OuterSingleton;
}
#undef UHT_STATICS
UDMFSessionSubsystem::UDMFSessionSubsystem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFSessionSubsystem);
UDMFSessionSubsystem::~UDMFSessionSubsystem() {}
// ********** End Class UDMFSessionSubsystem *******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFSessionSubsystem, TEXT("UDMFSessionSubsystem"), &Z_Registration_Info_UClass_UDMFSessionSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFSessionSubsystem), 4208794175U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFSessionSubsystem_h__Script_DigimonMMOFramework_f7b394bf42a2e681b96ba349df1eec74a6677fbb{
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
