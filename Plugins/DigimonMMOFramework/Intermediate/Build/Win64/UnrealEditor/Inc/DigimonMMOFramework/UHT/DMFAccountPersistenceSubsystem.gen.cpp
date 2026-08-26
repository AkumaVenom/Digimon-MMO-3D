// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Persistence/DMFAccountPersistenceSubsystem.h"
#include "DMFTypes.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFAccountPersistenceSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFAccountPersistenceSubsystem(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFAccountRecord(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFAccountDatabaseSaveGame(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFAccountPersistenceSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFAccountPersistenceSubsystem Function Flush ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_Flush_Statics
struct UHT_STATICS
{
	struct DMFAccountPersistenceSubsystem_eventFlush_Parms
	{
		FString OutError;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Accounts" },
		{ "ModuleRelativePath", "Public/Persistence/DMFAccountPersistenceSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Flush constinit property declarations *********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutError;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFAccountPersistenceSubsystem_eventFlush_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Flush constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Flush Property Definitions ********************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_OutError = { "OutError", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAccountPersistenceSubsystem_eventFlush_Parms, OutError), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFAccountPersistenceSubsystem_eventFlush_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutError,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Flush Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFAccountPersistenceSubsystem, nullptr, "Flush", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFAccountPersistenceSubsystem_eventFlush_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFAccountPersistenceSubsystem_eventFlush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_Flush(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFAccountPersistenceSubsystem::execFlush)
{
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutError);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Flush(Z_Param_Out_OutError);
	P_NATIVE_END;
}
// ********** End Class UDMFAccountPersistenceSubsystem Function Flush *****************************

// ********** Begin Class UDMFAccountPersistenceSubsystem Function GetAccount **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_GetAccount_Statics
struct UHT_STATICS
{
	struct DMFAccountPersistenceSubsystem_eventGetAccount_Parms
	{
		FString Username;
		FDMFAccountRecord OutRecord;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Accounts" },
		{ "ModuleRelativePath", "Public/Persistence/DMFAccountPersistenceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Username_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAccount constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Username;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutRecord;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFAccountPersistenceSubsystem_eventGetAccount_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAccount constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAccount Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Username = { "Username", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAccountPersistenceSubsystem_eventGetAccount_Parms, Username), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Username_MetaData), NewProp_Username_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OutRecord = { "OutRecord", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAccountPersistenceSubsystem_eventGetAccount_Parms, OutRecord), Z_Construct_UScriptStruct_FDMFAccountRecord, METADATA_PARAMS(0, nullptr) }; // 28822b57efe3c389ac57482c3c90a5526bb2cf28
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFAccountPersistenceSubsystem_eventGetAccount_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Username,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutRecord,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetAccount Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFAccountPersistenceSubsystem, nullptr, "GetAccount", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFAccountPersistenceSubsystem_eventGetAccount_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFAccountPersistenceSubsystem_eventGetAccount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_GetAccount(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFAccountPersistenceSubsystem::execGetAccount)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Username);
	P_GET_STRUCT_REF(FDMFAccountRecord,Z_Param_Out_OutRecord);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetAccount(Z_Param_Username,Z_Param_Out_OutRecord);
	P_NATIVE_END;
}
// ********** End Class UDMFAccountPersistenceSubsystem Function GetAccount ************************

// ********** Begin Class UDMFAccountPersistenceSubsystem Function SaveAccount *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_SaveAccount_Statics
struct UHT_STATICS
{
	struct DMFAccountPersistenceSubsystem_eventSaveAccount_Parms
	{
		FDMFAccountRecord Record;
		FString OutError;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Accounts" },
		{ "ModuleRelativePath", "Public/Persistence/DMFAccountPersistenceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Record_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SaveAccount constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Record;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutError;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFAccountPersistenceSubsystem_eventSaveAccount_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveAccount constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveAccount Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Record = { "Record", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAccountPersistenceSubsystem_eventSaveAccount_Parms, Record), Z_Construct_UScriptStruct_FDMFAccountRecord, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Record_MetaData), NewProp_Record_MetaData) }; // 28822b57efe3c389ac57482c3c90a5526bb2cf28
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_OutError = { "OutError", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAccountPersistenceSubsystem_eventSaveAccount_Parms, OutError), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFAccountPersistenceSubsystem_eventSaveAccount_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Record,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutError,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SaveAccount Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFAccountPersistenceSubsystem, nullptr, "SaveAccount", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFAccountPersistenceSubsystem_eventSaveAccount_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFAccountPersistenceSubsystem_eventSaveAccount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_SaveAccount(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFAccountPersistenceSubsystem::execSaveAccount)
{
	P_GET_STRUCT_REF(FDMFAccountRecord,Z_Param_Out_Record);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutError);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SaveAccount(Z_Param_Out_Record,Z_Param_Out_OutError);
	P_NATIVE_END;
}
// ********** End Class UDMFAccountPersistenceSubsystem Function SaveAccount ***********************

// ********** Begin Class UDMFAccountPersistenceSubsystem Function ValidateOrRegisterAccount *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_ValidateOrRegisterAccount_Statics
struct UHT_STATICS
{
	struct DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms
	{
		FString Username;
		FString CredentialDigest;
		bool bOutCreatedNewAccount;
		FString OutError;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Accounts" },
		{ "ModuleRelativePath", "Public/Persistence/DMFAccountPersistenceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Username_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CredentialDigest_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ValidateOrRegisterAccount constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Username;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CredentialDigest;
	static void NewProp_bOutCreatedNewAccount_SetBit(void* Obj)
	{
		((DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms*)Obj)->bOutCreatedNewAccount = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOutCreatedNewAccount;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutError;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ValidateOrRegisterAccount constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ValidateOrRegisterAccount Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Username = { "Username", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms, Username), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Username_MetaData), NewProp_Username_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_CredentialDigest = { "CredentialDigest", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms, CredentialDigest), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CredentialDigest_MetaData), NewProp_CredentialDigest_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bOutCreatedNewAccount = { "bOutCreatedNewAccount", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms), &UHT_STATICS::NewProp_bOutCreatedNewAccount_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_OutError = { "OutError", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms, OutError), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Username,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CredentialDigest,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bOutCreatedNewAccount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutError,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ValidateOrRegisterAccount Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFAccountPersistenceSubsystem, nullptr, "ValidateOrRegisterAccount", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFAccountPersistenceSubsystem_eventValidateOrRegisterAccount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_ValidateOrRegisterAccount(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFAccountPersistenceSubsystem::execValidateOrRegisterAccount)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Username);
	P_GET_PROPERTY(FStrProperty,Z_Param_CredentialDigest);
	P_GET_UBOOL_REF(Z_Param_Out_bOutCreatedNewAccount);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutError);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateOrRegisterAccount(Z_Param_Username,Z_Param_CredentialDigest,Z_Param_Out_bOutCreatedNewAccount,Z_Param_Out_OutError);
	P_NATIVE_END;
}
// ********** End Class UDMFAccountPersistenceSubsystem Function ValidateOrRegisterAccount *********

// ********** Begin Class UDMFAccountPersistenceSubsystem ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFAccountPersistenceSubsystem_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Persistence/DMFAccountPersistenceSubsystem.h" },
		{ "ModuleRelativePath", "Public/Persistence/DMFAccountPersistenceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Database_MetaData[] = {
		{ "ModuleRelativePath", "Public/Persistence/DMFAccountPersistenceSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFAccountPersistenceSubsystem constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Database;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFAccountPersistenceSubsystem constinit property declarations ************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Flush"), .Pointer = &UDMFAccountPersistenceSubsystem::execFlush },
		{ .NameUTF8 = UTF8TEXT("GetAccount"), .Pointer = &UDMFAccountPersistenceSubsystem::execGetAccount },
		{ .NameUTF8 = UTF8TEXT("SaveAccount"), .Pointer = &UDMFAccountPersistenceSubsystem::execSaveAccount },
		{ .NameUTF8 = UTF8TEXT("ValidateOrRegisterAccount"), .Pointer = &UDMFAccountPersistenceSubsystem::execValidateOrRegisterAccount },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_Flush, "Flush" }, // a8abd4b68e1ca1426824ec92b004d9d473f02bdd
		{ &Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_GetAccount, "GetAccount" }, // 087f43196eeb00e141b9fae5fe9ab7e7a8ea174f
		{ &Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_SaveAccount, "SaveAccount" }, // 902bcb13f8c2deaab063ebe6de5f88ef786b483a
		{ &Z_Construct_UFunction_UDMFAccountPersistenceSubsystem_ValidateOrRegisterAccount, "ValidateOrRegisterAccount" }, // 4b7ae0373963af29d49499801a0f240bffa583f7
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFAccountPersistenceSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFAccountPersistenceSubsystem Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Database = { "Database", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFAccountPersistenceSubsystem, Database), Z_Construct_UClass_UDMFAccountDatabaseSaveGame, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Database_MetaData), NewProp_Database_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Database,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFAccountPersistenceSubsystem Property Definitions ***********************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UGameInstanceSubsystem,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFAccountPersistenceSubsystem,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UDMFAccountPersistenceSubsystem_StaticRegisterNativesUDMFAccountPersistenceSubsystem()
{
	UClass* Class = UDMFAccountPersistenceSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFAccountPersistenceSubsystem;
UClass* Z_Construct_UClass_UDMFAccountPersistenceSubsystem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFAccountPersistenceSubsystem;
		if (!Z_Registration_Info_UClass_UDMFAccountPersistenceSubsystem.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFAccountPersistenceSubsystem"),
				Z_Registration_Info_UClass_UDMFAccountPersistenceSubsystem.InnerSingleton,
				UDMFAccountPersistenceSubsystem_StaticRegisterNativesUDMFAccountPersistenceSubsystem,
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
		return Z_Registration_Info_UClass_UDMFAccountPersistenceSubsystem.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFAccountPersistenceSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFAccountPersistenceSubsystem.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFAccountPersistenceSubsystem.OuterSingleton;
}
#undef UHT_STATICS
UDMFAccountPersistenceSubsystem::UDMFAccountPersistenceSubsystem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFAccountPersistenceSubsystem);
UDMFAccountPersistenceSubsystem::~UDMFAccountPersistenceSubsystem() {}
// ********** End Class UDMFAccountPersistenceSubsystem ********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFAccountPersistenceSubsystem, TEXT("UDMFAccountPersistenceSubsystem"), &Z_Registration_Info_UClass_UDMFAccountPersistenceSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFAccountPersistenceSubsystem), 2017143963U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Persistence_DMFAccountPersistenceSubsystem_h__Script_DigimonMMOFramework_ed8b9db7e0e62bd1658b1f42fe6361d24219162b{
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
