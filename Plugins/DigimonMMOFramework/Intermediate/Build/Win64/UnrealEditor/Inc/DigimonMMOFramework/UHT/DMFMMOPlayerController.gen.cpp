// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFMMOPlayerController.h"
#include "DMFTypes.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFMMOPlayerController() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_APlayerController(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHealerInteractionResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHomeTeleportResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWorldChatMessage(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWorldChatMessageReceived__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFCombatQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFExperienceNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFHealerActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFHomeTeleportNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPartyQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFScanNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFTargetingPresentationActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldChatWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFHealerInteractionResult *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHealerInteractionResult__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFHealerInteractionResult_Parms
	{
		bool bSuccess;
		FText Message;
		int32 DigimonHealed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFHealerInteractionResult constinit property declarations ***********
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFHealerInteractionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigimonHealed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFHealerInteractionResult constinit property declarations *************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFHealerInteractionResult Property Definitions **********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFHealerInteractionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFHealerInteractionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigimonHealed = { "DigimonHealed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFHealerInteractionResult_Parms, DigimonHealed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonHealed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFHealerInteractionResult Property Definitions ************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFHealerInteractionResult__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFHealerInteractionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFHealerInteractionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHealerInteractionResult__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFHealerInteractionResult *********************************************

// ********** Begin Delegate FDMFWorldChatMessageReceived ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWorldChatMessageReceived__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFWorldChatMessageReceived_Parms
	{
		FDMFWorldChatMessage ChatMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFWorldChatMessageReceived constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChatMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFWorldChatMessageReceived constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFWorldChatMessageReceived Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ChatMessage = { "ChatMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFWorldChatMessageReceived_Parms, ChatMessage), Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(0, nullptr) }; // bcb0c6d062a83d58a8e86d31347a72e076749d4e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChatMessage,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFWorldChatMessageReceived Property Definitions ***********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFWorldChatMessageReceived__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFWorldChatMessageReceived_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFWorldChatMessageReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWorldChatMessageReceived__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFWorldChatMessageReceived ********************************************

// ********** Begin Delegate FDMFHomeTeleportResult ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHomeTeleportResult__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFHomeTeleportResult_Parms
	{
		bool bSuccess;
		FText Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFHomeTeleportResult constinit property declarations ****************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFHomeTeleportResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFHomeTeleportResult constinit property declarations ******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFHomeTeleportResult Property Definitions ***************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFHomeTeleportResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFHomeTeleportResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFHomeTeleportResult Property Definitions *****************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFHomeTeleportResult__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFHomeTeleportResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFHomeTeleportResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHomeTeleportResult__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFHomeTeleportResult **************************************************

// ********** Begin Class ADMFMMOPlayerController Function ClientHealerInteractionResult ***********
struct DMFMMOPlayerController_eventClientHealerInteractionResult_Parms
{
	bool bSuccess;
	FText Message;
	int32 DigimonHealed;
};
static FName NAME_ADMFMMOPlayerController_ClientHealerInteractionResult = FName(TEXT("ClientHealerInteractionResult"));
void ADMFMMOPlayerController::ClientHealerInteractionResult(bool bSuccess, FText const& Message, int32 DigimonHealed)
{
	DMFMMOPlayerController_eventClientHealerInteractionResult_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Message=Message;
	Parms.DigimonHealed=DigimonHealed;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ClientHealerInteractionResult);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClientHealerInteractionResult_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClientHealerInteractionResult constinit property declarations *********
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventClientHealerInteractionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DigimonHealed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientHealerInteractionResult constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientHealerInteractionResult Property Definitions ********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventClientHealerInteractionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientHealerInteractionResult_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DigimonHealed = { "DigimonHealed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientHealerInteractionResult_Parms, DigimonHealed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonHealed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientHealerInteractionResult Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClientHealerInteractionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventClientHealerInteractionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventClientHealerInteractionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClientHealerInteractionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClientHealerInteractionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_PROPERTY(FIntProperty,Z_Param_DigimonHealed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientHealerInteractionResult_Implementation(Z_Param_bSuccess,Z_Param_Message,Z_Param_DigimonHealed);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClientHealerInteractionResult *************

// ********** Begin Class ADMFMMOPlayerController Function ClientReceiveWorldChatHistory ***********
struct DMFMMOPlayerController_eventClientReceiveWorldChatHistory_Parms
{
	TArray<FDMFWorldChatMessage> ChatMessages;
};
static FName NAME_ADMFMMOPlayerController_ClientReceiveWorldChatHistory = FName(TEXT("ClientReceiveWorldChatHistory"));
void ADMFMMOPlayerController::ClientReceiveWorldChatHistory(TArray<FDMFWorldChatMessage> const& ChatMessages)
{
	DMFMMOPlayerController_eventClientReceiveWorldChatHistory_Parms Parms;
	Parms.ChatMessages=ChatMessages;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ClientReceiveWorldChatHistory);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveWorldChatHistory_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChatMessages_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClientReceiveWorldChatHistory constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChatMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ChatMessages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientReceiveWorldChatHistory constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientReceiveWorldChatHistory Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ChatMessages_Inner = { "ChatMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(0, nullptr) }; // bcb0c6d062a83d58a8e86d31347a72e076749d4e
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ChatMessages = { "ChatMessages", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientReceiveWorldChatHistory_Parms, ChatMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChatMessages_MetaData), NewProp_ChatMessages_MetaData) }; // bcb0c6d062a83d58a8e86d31347a72e076749d4e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChatMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChatMessages,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientReceiveWorldChatHistory Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClientReceiveWorldChatHistory", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventClientReceiveWorldChatHistory_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventClientReceiveWorldChatHistory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveWorldChatHistory(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClientReceiveWorldChatHistory)
{
	P_GET_TARRAY(FDMFWorldChatMessage,Z_Param_ChatMessages);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientReceiveWorldChatHistory_Implementation(Z_Param_ChatMessages);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClientReceiveWorldChatHistory *************

// ********** Begin Class ADMFMMOPlayerController Function ClientReceiveWorldChatMessage ***********
struct DMFMMOPlayerController_eventClientReceiveWorldChatMessage_Parms
{
	FDMFWorldChatMessage ChatMessage;
};
static FName NAME_ADMFMMOPlayerController_ClientReceiveWorldChatMessage = FName(TEXT("ClientReceiveWorldChatMessage"));
void ADMFMMOPlayerController::ClientReceiveWorldChatMessage(FDMFWorldChatMessage const& ChatMessage)
{
	DMFMMOPlayerController_eventClientReceiveWorldChatMessage_Parms Parms;
	Parms.ChatMessage=ChatMessage;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ClientReceiveWorldChatMessage);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveWorldChatMessage_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChatMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClientReceiveWorldChatMessage constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChatMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientReceiveWorldChatMessage constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientReceiveWorldChatMessage Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ChatMessage = { "ChatMessage", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientReceiveWorldChatMessage_Parms, ChatMessage), Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChatMessage_MetaData), NewProp_ChatMessage_MetaData) }; // bcb0c6d062a83d58a8e86d31347a72e076749d4e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChatMessage,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientReceiveWorldChatMessage Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClientReceiveWorldChatMessage", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventClientReceiveWorldChatMessage_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventClientReceiveWorldChatMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveWorldChatMessage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClientReceiveWorldChatMessage)
{
	P_GET_STRUCT(FDMFWorldChatMessage,Z_Param_ChatMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientReceiveWorldChatMessage_Implementation(Z_Param_ChatMessage);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClientReceiveWorldChatMessage *************

// ********** Begin Class ADMFMMOPlayerController Function ClientReturnHomeResult ******************
struct DMFMMOPlayerController_eventClientReturnHomeResult_Parms
{
	bool bSuccess;
	FText Message;
};
static FName NAME_ADMFMMOPlayerController_ClientReturnHomeResult = FName(TEXT("ClientReturnHomeResult"));
void ADMFMMOPlayerController::ClientReturnHomeResult(bool bSuccess, FText const& Message)
{
	DMFMMOPlayerController_eventClientReturnHomeResult_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Message=Message;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ClientReturnHomeResult);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClientReturnHomeResult_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClientReturnHomeResult constinit property declarations ****************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventClientReturnHomeResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientReturnHomeResult constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientReturnHomeResult Property Definitions ***************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventClientReturnHomeResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientReturnHomeResult_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientReturnHomeResult Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClientReturnHomeResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventClientReturnHomeResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventClientReturnHomeResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClientReturnHomeResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClientReturnHomeResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientReturnHomeResult_Implementation(Z_Param_bSuccess,Z_Param_Message);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClientReturnHomeResult ********************

// ********** Begin Class ADMFMMOPlayerController Function ClientWorldChatSendRejected *************
struct DMFMMOPlayerController_eventClientWorldChatSendRejected_Parms
{
	FText Reason;
};
static FName NAME_ADMFMMOPlayerController_ClientWorldChatSendRejected = FName(TEXT("ClientWorldChatSendRejected"));
void ADMFMMOPlayerController::ClientWorldChatSendRejected(FText const& Reason)
{
	DMFMMOPlayerController_eventClientWorldChatSendRejected_Parms Parms;
	Parms.Reason=Reason;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ClientWorldChatSendRejected);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClientWorldChatSendRejected_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Reason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClientWorldChatSendRejected constinit property declarations ***********
	static const UECodeGen_Private::FTextPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientWorldChatSendRejected constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientWorldChatSendRejected Property Definitions **********************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientWorldChatSendRejected_Parms, Reason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Reason_MetaData), NewProp_Reason_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientWorldChatSendRejected Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClientWorldChatSendRejected", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventClientWorldChatSendRejected_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventClientWorldChatSendRejected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClientWorldChatSendRejected(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClientWorldChatSendRejected)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_Reason);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientWorldChatSendRejected_Implementation(Z_Param_Reason);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClientWorldChatSendRejected ***************

// ********** Begin Class ADMFMMOPlayerController Function CloseDigimonInventoryUI *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonInventoryUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Inventory|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseDigimonInventoryUI constinit property declarations ***************
// ********** End Function CloseDigimonInventoryUI constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "CloseDigimonInventoryUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonInventoryUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execCloseDigimonInventoryUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseDigimonInventoryUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function CloseDigimonInventoryUI *******************

// ********** Begin Class ADMFMMOPlayerController Function CloseDigimonMenuUI **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonMenuUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseDigimonMenuUI constinit property declarations ********************
// ********** End Function CloseDigimonMenuUI constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "CloseDigimonMenuUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonMenuUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execCloseDigimonMenuUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseDigimonMenuUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function CloseDigimonMenuUI ************************

// ********** Begin Class ADMFMMOPlayerController Function ClosePartyQuickAccessInteraction ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClosePartyQuickAccessInteraction_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClosePartyQuickAccessInteraction constinit property declarations ******
// ********** End Function ClosePartyQuickAccessInteraction constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClosePartyQuickAccessInteraction", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClosePartyQuickAccessInteraction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClosePartyQuickAccessInteraction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClosePartyQuickAccessInteraction();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClosePartyQuickAccessInteraction **********

// ********** Begin Class ADMFMMOPlayerController Function ClosePlayerSkinSelectionUI **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClosePlayerSkinSelectionUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClosePlayerSkinSelectionUI constinit property declarations ************
// ********** End Function ClosePlayerSkinSelectionUI constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClosePlayerSkinSelectionUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClosePlayerSkinSelectionUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClosePlayerSkinSelectionUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClosePlayerSkinSelectionUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClosePlayerSkinSelectionUI ****************

// ********** Begin Class ADMFMMOPlayerController Function CloseWorldChatInput *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_CloseWorldChatInput_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|World Chat|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cancels text entry and returns keyboard/gameplay focus to the world. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cancels text entry and returns keyboard/gameplay focus to the world." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CloseWorldChatInput constinit property declarations *******************
// ********** End Function CloseWorldChatInput constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "CloseWorldChatInput", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_CloseWorldChatInput(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execCloseWorldChatInput)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseWorldChatInput();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function CloseWorldChatInput ***********************

// ********** Begin Class ADMFMMOPlayerController Function CommandActivePartnerAbilitySlot *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_CommandActivePartnerAbilitySlot_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventCommandActivePartnerAbilitySlot_Parms
	{
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Executes/queues a quick slot against the currently selected target. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Executes/queues a quick slot against the currently selected target." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CommandActivePartnerAbilitySlot constinit property declarations *******
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CommandActivePartnerAbilitySlot constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CommandActivePartnerAbilitySlot Property Definitions ******************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventCommandActivePartnerAbilitySlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CommandActivePartnerAbilitySlot Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "CommandActivePartnerAbilitySlot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventCommandActivePartnerAbilitySlot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventCommandActivePartnerAbilitySlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_CommandActivePartnerAbilitySlot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execCommandActivePartnerAbilitySlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CommandActivePartnerAbilitySlot(Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function CommandActivePartnerAbilitySlot ***********

// ********** Begin Class ADMFMMOPlayerController Function CommandPartnerTargetAndAttack ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_CommandPartnerTargetAndAttack_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventCommandPartnerTargetAndAttack_Parms
	{
		ADMFDigimonCharacter* Target;
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Manual MMO command: selects the supplied hostile target and executes/queues the requested quick slot. */" },
#endif
		{ "CPP_Default_SlotIndex", "0" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Manual MMO command: selects the supplied hostile target and executes/queues the requested quick slot." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CommandPartnerTargetAndAttack constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CommandPartnerTargetAndAttack constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CommandPartnerTargetAndAttack Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventCommandPartnerTargetAndAttack_Parms, Target), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventCommandPartnerTargetAndAttack_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CommandPartnerTargetAndAttack Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "CommandPartnerTargetAndAttack", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventCommandPartnerTargetAndAttack_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventCommandPartnerTargetAndAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_CommandPartnerTargetAndAttack(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execCommandPartnerTargetAndAttack)
{
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_Target);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CommandPartnerTargetAndAttack(Z_Param_Target,Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function CommandPartnerTargetAndAttack *************

// ********** Begin Class ADMFMMOPlayerController Function GetTargetingPresentationActor ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_GetTargetingPresentationActor_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventGetTargetingPresentationActor_Parms
	{
		ADMFTargetingPresentationActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTargetingPresentationActor constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTargetingPresentationActor constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTargetingPresentationActor Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventGetTargetingPresentationActor_Parms, ReturnValue), Z_Construct_UClass_ADMFTargetingPresentationActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetTargetingPresentationActor Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "GetTargetingPresentationActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventGetTargetingPresentationActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventGetTargetingPresentationActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_GetTargetingPresentationActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execGetTargetingPresentationActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFTargetingPresentationActor**)Z_Param__Result=P_THIS->GetTargetingPresentationActor();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function GetTargetingPresentationActor *************

// ********** Begin Class ADMFMMOPlayerController Function GetWorldChatWidget **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_GetWorldChatWidget_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventGetWorldChatWidget_Parms
	{
		UDMFWorldChatWidget* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|World Chat|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetWorldChatWidget constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWorldChatWidget constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWorldChatWidget Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventGetWorldChatWidget_Parms, ReturnValue), Z_Construct_UClass_UDMFWorldChatWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetWorldChatWidget Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "GetWorldChatWidget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventGetWorldChatWidget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventGetWorldChatWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_GetWorldChatWidget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execGetWorldChatWidget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDMFWorldChatWidget**)Z_Param__Result=P_THIS->GetWorldChatWidget();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function GetWorldChatWidget ************************

// ********** Begin Class ADMFMMOPlayerController Function HandleCareSequenceFinished **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_HandleCareSequenceFinished_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventHandleCareSequenceFinished_Parms
	{
		bool bSuccess;
		FText Message;
		FGuid DigimonInstanceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCareSequenceFinished constinit property declarations ************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventHandleCareSequenceFinished_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleCareSequenceFinished constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleCareSequenceFinished Property Definitions ***********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventHandleCareSequenceFinished_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleCareSequenceFinished_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleCareSequenceFinished_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleCareSequenceFinished Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "HandleCareSequenceFinished", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventHandleCareSequenceFinished_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventHandleCareSequenceFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_HandleCareSequenceFinished(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execHandleCareSequenceFinished)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCareSequenceFinished(Z_Param_bSuccess,Z_Param_Message,Z_Param_DigimonInstanceId);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function HandleCareSequenceFinished ****************

// ********** Begin Class ADMFMMOPlayerController Function HandleCareSequenceStarted ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_HandleCareSequenceStarted_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventHandleCareSequenceStarted_Parms
	{
		FGuid DigimonInstanceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCareSequenceStarted constinit property declarations *************
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleCareSequenceStarted constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleCareSequenceStarted Property Definitions ************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleCareSequenceStarted_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleCareSequenceStarted Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "HandleCareSequenceStarted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventHandleCareSequenceStarted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventHandleCareSequenceStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_HandleCareSequenceStarted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execHandleCareSequenceStarted)
{
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCareSequenceStarted(Z_Param_DigimonInstanceId);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function HandleCareSequenceStarted *****************

// ********** Begin Class ADMFMMOPlayerController Function HandleDigimonExperienceProgressed *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_HandleDigimonExperienceProgressed_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventHandleDigimonExperienceProgressed_Parms
	{
		FDMFDigimonExperienceProgression Progression;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigimonExperienceProgressed constinit property declarations *****
	static const UECodeGen_Private::FStructPropertyParams NewProp_Progression;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDigimonExperienceProgressed constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDigimonExperienceProgressed Property Definitions ****************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Progression = { "Progression", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleDigimonExperienceProgressed_Parms, Progression), Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression, METADATA_PARAMS(0, nullptr) }; // 94e02e0ef96f238d9bf716a73264a6be31a7ed80
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Progression,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleDigimonExperienceProgressed Property Definitions ******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "HandleDigimonExperienceProgressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventHandleDigimonExperienceProgressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventHandleDigimonExperienceProgressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_HandleDigimonExperienceProgressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execHandleDigimonExperienceProgressed)
{
	P_GET_STRUCT(FDMFDigimonExperienceProgression,Z_Param_Progression);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigimonExperienceProgressed(Z_Param_Progression);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function HandleDigimonExperienceProgressed *********

// ********** Begin Class ADMFMMOPlayerController Function HandleDigivolutionResult ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_HandleDigivolutionResult_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventHandleDigivolutionResult_Parms
	{
		bool bSuccess;
		FText Message;
		FGuid DigimonInstanceId;
		FPrimaryAssetId PreviousSpeciesId;
		FPrimaryAssetId NewSpeciesId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigivolutionResult constinit property declarations **************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventHandleDigivolutionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousSpeciesId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewSpeciesId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDigivolutionResult constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDigivolutionResult Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventHandleDigivolutionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleDigivolutionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleDigivolutionResult_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PreviousSpeciesId = { "PreviousSpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleDigivolutionResult_Parms, PreviousSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NewSpeciesId = { "NewSpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleDigivolutionResult_Parms, NewSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousSpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewSpeciesId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleDigivolutionResult Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "HandleDigivolutionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventHandleDigivolutionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventHandleDigivolutionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_HandleDigivolutionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execHandleDigivolutionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_PreviousSpeciesId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_NewSpeciesId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigivolutionResult(Z_Param_bSuccess,Z_Param_Message,Z_Param_DigimonInstanceId,Z_Param_PreviousSpeciesId,Z_Param_NewSpeciesId);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function HandleDigivolutionResult ******************

// ********** Begin Class ADMFMMOPlayerController Function HandleDigivolutionSequenceStarted *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_HandleDigivolutionSequenceStarted_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventHandleDigivolutionSequenceStarted_Parms
	{
		FGuid DigimonInstanceId;
		FPrimaryAssetId PreviousSpeciesId;
		FPrimaryAssetId TargetSpeciesId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDigivolutionSequenceStarted constinit property declarations *****
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousSpeciesId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetSpeciesId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDigivolutionSequenceStarted constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDigivolutionSequenceStarted Property Definitions ****************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleDigivolutionSequenceStarted_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PreviousSpeciesId = { "PreviousSpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleDigivolutionSequenceStarted_Parms, PreviousSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_TargetSpeciesId = { "TargetSpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleDigivolutionSequenceStarted_Parms, TargetSpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousSpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetSpeciesId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleDigivolutionSequenceStarted Property Definitions ******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "HandleDigivolutionSequenceStarted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventHandleDigivolutionSequenceStarted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventHandleDigivolutionSequenceStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_HandleDigivolutionSequenceStarted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execHandleDigivolutionSequenceStarted)
{
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_PreviousSpeciesId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_TargetSpeciesId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDigivolutionSequenceStarted(Z_Param_DigimonInstanceId,Z_Param_PreviousSpeciesId,Z_Param_TargetSpeciesId);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function HandleDigivolutionSequenceStarted *********

// ********** Begin Class ADMFMMOPlayerController Function HandlePlayerSkinRequirementChanged ******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_HandlePlayerSkinRequirementChanged_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventHandlePlayerSkinRequirementChanged_Parms
	{
		bool bRequired;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePlayerSkinRequirementChanged constinit property declarations ****
	static void NewProp_bRequired_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventHandlePlayerSkinRequirementChanged_Parms*)Obj)->bRequired = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequired;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandlePlayerSkinRequirementChanged constinit property declarations ******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandlePlayerSkinRequirementChanged Property Definitions ***************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequired = { "bRequired", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventHandlePlayerSkinRequirementChanged_Parms), &UHT_STATICS::NewProp_bRequired_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequired,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandlePlayerSkinRequirementChanged Property Definitions *****************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "HandlePlayerSkinRequirementChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventHandlePlayerSkinRequirementChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventHandlePlayerSkinRequirementChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_HandlePlayerSkinRequirementChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execHandlePlayerSkinRequirementChanged)
{
	P_GET_UBOOL(Z_Param_bRequired);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePlayerSkinRequirementChanged(Z_Param_bRequired);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function HandlePlayerSkinRequirementChanged ********

// ********** Begin Class ADMFMMOPlayerController Function HandleScanDataRewardGranted *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_HandleScanDataRewardGranted_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventHandleScanDataRewardGranted_Parms
	{
		FPrimaryAssetId SpeciesId;
		float AddedPercent;
		float NewPercent;
		bool bMaterializationReady;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleScanDataRewardGranted constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AddedPercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewPercent;
	static void NewProp_bMaterializationReady_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventHandleScanDataRewardGranted_Parms*)Obj)->bMaterializationReady = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMaterializationReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleScanDataRewardGranted constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleScanDataRewardGranted Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SpeciesId = { "SpeciesId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleScanDataRewardGranted_Parms, SpeciesId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AddedPercent = { "AddedPercent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleScanDataRewardGranted_Parms, AddedPercent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NewPercent = { "NewPercent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventHandleScanDataRewardGranted_Parms, NewPercent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bMaterializationReady = { "bMaterializationReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventHandleScanDataRewardGranted_Parms), &UHT_STATICS::NewProp_bMaterializationReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AddedPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bMaterializationReady,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleScanDataRewardGranted Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "HandleScanDataRewardGranted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventHandleScanDataRewardGranted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventHandleScanDataRewardGranted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_HandleScanDataRewardGranted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execHandleScanDataRewardGranted)
{
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_SpeciesId);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AddedPercent);
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewPercent);
	P_GET_UBOOL(Z_Param_bMaterializationReady);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleScanDataRewardGranted(Z_Param_SpeciesId,Z_Param_AddedPercent,Z_Param_NewPercent,Z_Param_bMaterializationReady);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function HandleScanDataRewardGranted ***************

// ********** Begin Class ADMFMMOPlayerController Function HandleStarterRequirementChanged *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_HandleStarterRequirementChanged_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventHandleStarterRequirementChanged_Parms
	{
		bool bRequired;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleStarterRequirementChanged constinit property declarations *******
	static void NewProp_bRequired_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventHandleStarterRequirementChanged_Parms*)Obj)->bRequired = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequired;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleStarterRequirementChanged constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleStarterRequirementChanged Property Definitions ******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bRequired = { "bRequired", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventHandleStarterRequirementChanged_Parms), &UHT_STATICS::NewProp_bRequired_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bRequired,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleStarterRequirementChanged Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "HandleStarterRequirementChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventHandleStarterRequirementChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventHandleStarterRequirementChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_HandleStarterRequirementChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execHandleStarterRequirementChanged)
{
	P_GET_UBOOL(Z_Param_bRequired);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStarterRequirementChanged(Z_Param_bRequired);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function HandleStarterRequirementChanged ***********

// ********** Begin Class ADMFMMOPlayerController Function IsCarePresentationActive ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsCarePresentationActive_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsCarePresentationActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Care|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsCarePresentationActive constinit property declarations **************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsCarePresentationActive_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsCarePresentationActive constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsCarePresentationActive Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsCarePresentationActive_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsCarePresentationActive Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsCarePresentationActive", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsCarePresentationActive_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsCarePresentationActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsCarePresentationActive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsCarePresentationActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsCarePresentationActive();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsCarePresentationActive ******************

// ********** Begin Class ADMFMMOPlayerController Function IsDigimonInventoryUIOpen ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonInventoryUIOpen_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsDigimonInventoryUIOpen_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Inventory|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDigimonInventoryUIOpen constinit property declarations **************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsDigimonInventoryUIOpen_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDigimonInventoryUIOpen constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDigimonInventoryUIOpen Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsDigimonInventoryUIOpen_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsDigimonInventoryUIOpen Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsDigimonInventoryUIOpen", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsDigimonInventoryUIOpen_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsDigimonInventoryUIOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonInventoryUIOpen(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsDigimonInventoryUIOpen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDigimonInventoryUIOpen();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsDigimonInventoryUIOpen ******************

// ********** Begin Class ADMFMMOPlayerController Function IsDigimonMenuUIOpen *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonMenuUIOpen_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsDigimonMenuUIOpen_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDigimonMenuUIOpen constinit property declarations *******************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsDigimonMenuUIOpen_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDigimonMenuUIOpen constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDigimonMenuUIOpen Property Definitions ******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsDigimonMenuUIOpen_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsDigimonMenuUIOpen Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsDigimonMenuUIOpen", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsDigimonMenuUIOpen_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsDigimonMenuUIOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonMenuUIOpen(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsDigimonMenuUIOpen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDigimonMenuUIOpen();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsDigimonMenuUIOpen ***********************

// ********** Begin Class ADMFMMOPlayerController Function IsDigivolutionPresentationActive ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsDigivolutionPresentationActive_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsDigivolutionPresentationActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Digivolution|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDigivolutionPresentationActive constinit property declarations ******
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsDigivolutionPresentationActive_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDigivolutionPresentationActive constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDigivolutionPresentationActive Property Definitions *****************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsDigivolutionPresentationActive_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsDigivolutionPresentationActive Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsDigivolutionPresentationActive", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsDigivolutionPresentationActive_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsDigivolutionPresentationActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsDigivolutionPresentationActive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsDigivolutionPresentationActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDigivolutionPresentationActive();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsDigivolutionPresentationActive **********

// ********** Begin Class ADMFMMOPlayerController Function IsFrameworkPlayerAvatarPossessed ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsFrameworkPlayerAvatarPossessed_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsFrameworkPlayerAvatarPossessed_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Networking|Player Spawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True only when this controller currently possesses a DMF player-avatar pawn. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True only when this controller currently possesses a DMF player-avatar pawn." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsFrameworkPlayerAvatarPossessed constinit property declarations ******
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsFrameworkPlayerAvatarPossessed_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsFrameworkPlayerAvatarPossessed constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsFrameworkPlayerAvatarPossessed Property Definitions *****************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsFrameworkPlayerAvatarPossessed_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsFrameworkPlayerAvatarPossessed Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsFrameworkPlayerAvatarPossessed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsFrameworkPlayerAvatarPossessed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsFrameworkPlayerAvatarPossessed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsFrameworkPlayerAvatarPossessed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsFrameworkPlayerAvatarPossessed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsFrameworkPlayerAvatarPossessed();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsFrameworkPlayerAvatarPossessed **********

// ********** Begin Class ADMFMMOPlayerController Function IsPartyQuickAccessInteractionActive *****
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsPartyQuickAccessInteractionActive_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsPartyQuickAccessInteractionActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPartyQuickAccessInteractionActive constinit property declarations ***
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsPartyQuickAccessInteractionActive_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPartyQuickAccessInteractionActive constinit property declarations *****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPartyQuickAccessInteractionActive Property Definitions **************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsPartyQuickAccessInteractionActive_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsPartyQuickAccessInteractionActive Property Definitions ****************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsPartyQuickAccessInteractionActive", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsPartyQuickAccessInteractionActive_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsPartyQuickAccessInteractionActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsPartyQuickAccessInteractionActive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsPartyQuickAccessInteractionActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPartyQuickAccessInteractionActive();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsPartyQuickAccessInteractionActive *******

// ********** Begin Class ADMFMMOPlayerController Function IsPlayerSkinSelectionUIOpen *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsPlayerSkinSelectionUIOpen_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsPlayerSkinSelectionUIOpen_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPlayerSkinSelectionUIOpen constinit property declarations ***********
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsPlayerSkinSelectionUIOpen_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPlayerSkinSelectionUIOpen constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPlayerSkinSelectionUIOpen Property Definitions **********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsPlayerSkinSelectionUIOpen_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsPlayerSkinSelectionUIOpen Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsPlayerSkinSelectionUIOpen", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsPlayerSkinSelectionUIOpen_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsPlayerSkinSelectionUIOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsPlayerSkinSelectionUIOpen(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsPlayerSkinSelectionUIOpen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayerSkinSelectionUIOpen();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsPlayerSkinSelectionUIOpen ***************

// ********** Begin Class ADMFMMOPlayerController Function IsWorldChatInputActive ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsWorldChatInputActive_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsWorldChatInputActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|World Chat|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsWorldChatInputActive constinit property declarations ****************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsWorldChatInputActive_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsWorldChatInputActive constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsWorldChatInputActive Property Definitions ***************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsWorldChatInputActive_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsWorldChatInputActive Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsWorldChatInputActive", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsWorldChatInputActive_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsWorldChatInputActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsWorldChatInputActive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsWorldChatInputActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsWorldChatInputActive();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsWorldChatInputActive ********************

// ********** Begin Class ADMFMMOPlayerController Function OpenBankUI ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenBankUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party & Bank|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the shared Digimon menu directly on world-accessible Bank/Box storage. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the shared Digimon menu directly on world-accessible Bank/Box storage." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenBankUI constinit property declarations ****************************
// ********** End Function OpenBankUI constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenBankUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenBankUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenBankUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenBankUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenBankUI ********************************

// ********** Begin Class ADMFMMOPlayerController Function OpenCareUI ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenCareUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Care|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the shared Digimon menu directly on the virtual-pet CARE tab. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the shared Digimon menu directly on the virtual-pet CARE tab." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenCareUI constinit property declarations ****************************
// ********** End Function OpenCareUI constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenCareUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenCareUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenCareUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenCareUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenCareUI ********************************

// ********** Begin Class ADMFMMOPlayerController Function OpenDigimonInventoryUI ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonInventoryUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Inventory|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenDigimonInventoryUI constinit property declarations ****************
// ********** End Function OpenDigimonInventoryUI constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenDigimonInventoryUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonInventoryUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenDigimonInventoryUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenDigimonInventoryUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenDigimonInventoryUI ********************

// ********** Begin Class ADMFMMOPlayerController Function OpenDigimonMenuUI ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonMenuUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Preferred future-facing aliases for the shared tabbed Digimon menu. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Preferred future-facing aliases for the shared tabbed Digimon menu." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenDigimonMenuUI constinit property declarations *********************
// ********** End Function OpenDigimonMenuUI constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenDigimonMenuUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonMenuUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenDigimonMenuUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenDigimonMenuUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenDigimonMenuUI *************************

// ********** Begin Class ADMFMMOPlayerController Function OpenDigivolutionUI **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigivolutionUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Digivolution|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the shared Digimon menu directly on the persistent Party/Bank Digivolution terminal. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the shared Digimon menu directly on the persistent Party/Bank Digivolution terminal." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenDigivolutionUI constinit property declarations ********************
// ********** End Function OpenDigivolutionUI constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenDigivolutionUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigivolutionUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenDigivolutionUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenDigivolutionUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenDigivolutionUI ************************

// ********** Begin Class ADMFMMOPlayerController Function OpenPartyQuickAccessInteraction *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenPartyQuickAccessInteraction_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenPartyQuickAccessInteraction constinit property declarations *******
// ********** End Function OpenPartyQuickAccessInteraction constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenPartyQuickAccessInteraction", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenPartyQuickAccessInteraction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenPartyQuickAccessInteraction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenPartyQuickAccessInteraction();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenPartyQuickAccessInteraction ***********

// ********** Begin Class ADMFMMOPlayerController Function OpenPartyUI *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenPartyUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party & Bank|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the shared Digimon menu directly on the six-slot Party page. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the shared Digimon menu directly on the six-slot Party page." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenPartyUI constinit property declarations ***************************
// ********** End Function OpenPartyUI constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenPartyUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenPartyUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenPartyUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenPartyUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenPartyUI *******************************

// ********** Begin Class ADMFMMOPlayerController Function OpenPlayerSkinSelectionUI ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenPlayerSkinSelectionUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenPlayerSkinSelectionUI constinit property declarations *************
// ********** End Function OpenPlayerSkinSelectionUI constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenPlayerSkinSelectionUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenPlayerSkinSelectionUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenPlayerSkinSelectionUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenPlayerSkinSelectionUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenPlayerSkinSelectionUI *****************

// ********** Begin Class ADMFMMOPlayerController Function OpenScanMaterializeUI *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenScanMaterializeUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Scan & Materialization|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the shared Digimon menu directly on Scan & Materialize. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the shared Digimon menu directly on Scan & Materialize." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenScanMaterializeUI constinit property declarations *****************
// ********** End Function OpenScanMaterializeUI constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenScanMaterializeUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenScanMaterializeUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenScanMaterializeUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenScanMaterializeUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenScanMaterializeUI *********************

// ********** Begin Class ADMFMMOPlayerController Function OpenWorldChatInput **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenWorldChatInput_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|World Chat|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Focuses the chat entry field. The default Enter binding calls this automatically. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Focuses the chat entry field. The default Enter binding calls this automatically." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenWorldChatInput constinit property declarations ********************
// ********** End Function OpenWorldChatInput constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenWorldChatInput", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenWorldChatInput(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenWorldChatInput)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenWorldChatInput();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenWorldChatInput ************************

// ********** Begin Class ADMFMMOPlayerController Function RefreshCombatQuickBar *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshCombatQuickBar_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshCombatQuickBar constinit property declarations *****************
// ********** End Function RefreshCombatQuickBar constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshCombatQuickBar", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshCombatQuickBar(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshCombatQuickBar)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshCombatQuickBar();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshCombatQuickBar *********************

// ********** Begin Class ADMFMMOPlayerController Function RefreshDigimonInventoryUI ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshDigimonInventoryUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Inventory|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshDigimonInventoryUI constinit property declarations *************
// ********** End Function RefreshDigimonInventoryUI constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshDigimonInventoryUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshDigimonInventoryUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshDigimonInventoryUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshDigimonInventoryUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshDigimonInventoryUI *****************

// ********** Begin Class ADMFMMOPlayerController Function RefreshPartyQuickBar ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshPartyQuickBar_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshPartyQuickBar constinit property declarations ******************
// ********** End Function RefreshPartyQuickBar constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshPartyQuickBar", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshPartyQuickBar(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshPartyQuickBar)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshPartyQuickBar();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshPartyQuickBar **********************

// ********** Begin Class ADMFMMOPlayerController Function RefreshPlayerSkinSelectionUI ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshPlayerSkinSelectionUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshPlayerSkinSelectionUI constinit property declarations **********
// ********** End Function RefreshPlayerSkinSelectionUI constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshPlayerSkinSelectionUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshPlayerSkinSelectionUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshPlayerSkinSelectionUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshPlayerSkinSelectionUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshPlayerSkinSelectionUI **************

// ********** Begin Class ADMFMMOPlayerController Function RefreshStarterSelectionUI ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshStarterSelectionUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshStarterSelectionUI constinit property declarations *************
// ********** End Function RefreshStarterSelectionUI constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshStarterSelectionUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshStarterSelectionUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshStarterSelectionUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshStarterSelectionUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshStarterSelectionUI *****************

// ********** Begin Class ADMFMMOPlayerController Function RefreshTargetingVisuals *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshTargetingVisuals_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Creates/reloads this client's non-replicated partner/target selection presentation from Project Settings. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates/reloads this client's non-replicated partner/target selection presentation from Project Settings." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshTargetingVisuals constinit property declarations ***************
// ********** End Function RefreshTargetingVisuals constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshTargetingVisuals", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshTargetingVisuals(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshTargetingVisuals)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshTargetingVisuals();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshTargetingVisuals *******************

// ********** Begin Class ADMFMMOPlayerController Function RefreshWorldChatUI **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshWorldChatUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|World Chat|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Creates/refreshes the native persistent world-chat HUD when globally enabled. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates/refreshes the native persistent world-chat HUD when globally enabled." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshWorldChatUI constinit property declarations ********************
// ********** End Function RefreshWorldChatUI constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshWorldChatUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshWorldChatUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshWorldChatUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshWorldChatUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshWorldChatUI ************************

// ********** Begin Class ADMFMMOPlayerController Function RequestReturnHome ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestReturnHome_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access|Home" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Requests a server-authoritative teleport to the configured DMFNewPlayerStart. No client transform is accepted. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Requests a server-authoritative teleport to the configured DMFNewPlayerStart. No client transform is accepted." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestReturnHome constinit property declarations *********************
// ********** End Function RequestReturnHome constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestReturnHome", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestReturnHome(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestReturnHome)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestReturnHome();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestReturnHome *************************

// ********** Begin Class ADMFMMOPlayerController Function RequestUseHealer ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestUseHealer_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestUseHealer_Parms
	{
		ADMFHealerActor* Healer;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Healing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called by ADMFHealerActor::RequestHeal; routes the interaction through this client-owned controller. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called by ADMFHealerActor::RequestHeal; routes the interaction through this client-owned controller." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestUseHealer constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Healer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestUseHealer constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestUseHealer Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Healer = { "Healer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestUseHealer_Parms, Healer), Z_Construct_UClass_ADMFHealerActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Healer,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestUseHealer Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestUseHealer", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestUseHealer_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestUseHealer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestUseHealer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestUseHealer)
{
	P_GET_OBJECT(ADMFHealerActor,Z_Param_Healer);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestUseHealer(Z_Param_Healer);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestUseHealer **************************

// ********** Begin Class ADMFMMOPlayerController Function SelectDigimonCommandTargetUnderCursor ***
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_SelectDigimonCommandTargetUnderCursor_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventSelectDigimonCommandTargetUnderCursor_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectDigimonCommandTargetUnderCursor constinit property declarations *
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventSelectDigimonCommandTargetUnderCursor_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SelectDigimonCommandTargetUnderCursor constinit property declarations ***
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SelectDigimonCommandTargetUnderCursor Property Definitions ************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventSelectDigimonCommandTargetUnderCursor_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SelectDigimonCommandTargetUnderCursor Property Definitions **************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "SelectDigimonCommandTargetUnderCursor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventSelectDigimonCommandTargetUnderCursor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventSelectDigimonCommandTargetUnderCursor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_SelectDigimonCommandTargetUnderCursor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execSelectDigimonCommandTargetUnderCursor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SelectDigimonCommandTargetUnderCursor();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function SelectDigimonCommandTargetUnderCursor *****

// ********** Begin Class ADMFMMOPlayerController Function SendWorldChatMessage ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_SendWorldChatMessage_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventSendWorldChatMessage_Parms
	{
		FString Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|World Chat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Client-facing entry point. Identity/timestamps are intentionally not accepted from the caller. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client-facing entry point. Identity/timestamps are intentionally not accepted from the caller." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SendWorldChatMessage constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SendWorldChatMessage constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SendWorldChatMessage Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventSendWorldChatMessage_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SendWorldChatMessage Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "SendWorldChatMessage", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventSendWorldChatMessage_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventSendWorldChatMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_SendWorldChatMessage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execSendWorldChatMessage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendWorldChatMessage(Z_Param_Message);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function SendWorldChatMessage **********************

// ********** Begin Class ADMFMMOPlayerController Function ServerEnsureFrameworkPlayerAvatar *******
static FName NAME_ADMFMMOPlayerController_ServerEnsureFrameworkPlayerAvatar = FName(TEXT("ServerEnsureFrameworkPlayerAvatar"));
void ADMFMMOPlayerController::ServerEnsureFrameworkPlayerAvatar()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ServerEnsureFrameworkPlayerAvatar);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ServerEnsureFrameworkPlayerAvatar_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Networking|Player Spawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Requests the authoritative GameMode to validate/recover this controller's MMO avatar possession. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Requests the authoritative GameMode to validate/recover this controller's MMO avatar possession." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ServerEnsureFrameworkPlayerAvatar constinit property declarations *****
// ********** End Function ServerEnsureFrameworkPlayerAvatar constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ServerEnsureFrameworkPlayerAvatar", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ServerEnsureFrameworkPlayerAvatar(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execServerEnsureFrameworkPlayerAvatar)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerEnsureFrameworkPlayerAvatar_Implementation();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ServerEnsureFrameworkPlayerAvatar *********

// ********** Begin Class ADMFMMOPlayerController Function ServerRequestReturnHome *****************
static FName NAME_ADMFMMOPlayerController_ServerRequestReturnHome = FName(TEXT("ServerRequestReturnHome"));
void ADMFMMOPlayerController::ServerRequestReturnHome()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ServerRequestReturnHome);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestReturnHome_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerRequestReturnHome constinit property declarations ***************
// ********** End Function ServerRequestReturnHome constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ServerRequestReturnHome", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestReturnHome(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execServerRequestReturnHome)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRequestReturnHome_Implementation();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ServerRequestReturnHome *******************

// ********** Begin Class ADMFMMOPlayerController Function ServerRequestUseHealer ******************
struct DMFMMOPlayerController_eventServerRequestUseHealer_Parms
{
	ADMFHealerActor* Healer;
};
static FName NAME_ADMFMMOPlayerController_ServerRequestUseHealer = FName(TEXT("ServerRequestUseHealer"));
void ADMFMMOPlayerController::ServerRequestUseHealer(ADMFHealerActor* Healer)
{
	DMFMMOPlayerController_eventServerRequestUseHealer_Parms Parms;
	Parms.Healer=Healer;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ServerRequestUseHealer);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestUseHealer_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerRequestUseHealer constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Healer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ServerRequestUseHealer constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ServerRequestUseHealer Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Healer = { "Healer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerRequestUseHealer_Parms, Healer), Z_Construct_UClass_ADMFHealerActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Healer,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ServerRequestUseHealer Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ServerRequestUseHealer", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventServerRequestUseHealer_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventServerRequestUseHealer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestUseHealer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execServerRequestUseHealer)
{
	P_GET_OBJECT(ADMFHealerActor,Z_Param_Healer);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRequestUseHealer_Implementation(Z_Param_Healer);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ServerRequestUseHealer ********************

// ********** Begin Class ADMFMMOPlayerController Function ServerRequestWorldChatHistory ***********
static FName NAME_ADMFMMOPlayerController_ServerRequestWorldChatHistory = FName(TEXT("ServerRequestWorldChatHistory"));
void ADMFMMOPlayerController::ServerRequestWorldChatHistory()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ServerRequestWorldChatHistory);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestWorldChatHistory_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerRequestWorldChatHistory constinit property declarations *********
// ********** End Function ServerRequestWorldChatHistory constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ServerRequestWorldChatHistory", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestWorldChatHistory(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execServerRequestWorldChatHistory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRequestWorldChatHistory_Implementation();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ServerRequestWorldChatHistory *************

// ********** Begin Class ADMFMMOPlayerController Function ServerSendWorldChatMessage **************
struct DMFMMOPlayerController_eventServerSendWorldChatMessage_Parms
{
	FString Message;
};
static FName NAME_ADMFMMOPlayerController_ServerSendWorldChatMessage = FName(TEXT("ServerSendWorldChatMessage"));
void ADMFMMOPlayerController::ServerSendWorldChatMessage(const FString& Message)
{
	DMFMMOPlayerController_eventServerSendWorldChatMessage_Parms Parms;
	Parms.Message=Message;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ServerSendWorldChatMessage);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ServerSendWorldChatMessage_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerSendWorldChatMessage constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ServerSendWorldChatMessage constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ServerSendWorldChatMessage Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerSendWorldChatMessage_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ServerSendWorldChatMessage Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ServerSendWorldChatMessage", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventServerSendWorldChatMessage_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventServerSendWorldChatMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ServerSendWorldChatMessage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execServerSendWorldChatMessage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSendWorldChatMessage_Implementation(Z_Param_Message);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ServerSendWorldChatMessage ****************

// ********** Begin Class ADMFMMOPlayerController Function SetDigimonCommandTarget *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_SetDigimonCommandTarget_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventSetDigimonCommandTarget_Parms
	{
		ADMFDigimonCharacter* NewTarget;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDigimonCommandTarget constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDigimonCommandTarget constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDigimonCommandTarget Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NewTarget = { "NewTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventSetDigimonCommandTarget_Parms, NewTarget), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTarget,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetDigimonCommandTarget Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "SetDigimonCommandTarget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventSetDigimonCommandTarget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventSetDigimonCommandTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_SetDigimonCommandTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execSetDigimonCommandTarget)
{
	P_GET_OBJECT(ADMFDigimonCharacter,Z_Param_NewTarget);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDigimonCommandTarget(Z_Param_NewTarget);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function SetDigimonCommandTarget *******************

// ********** Begin Class ADMFMMOPlayerController Function ToggleDigimonInventoryUI ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ToggleDigimonInventoryUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Inventory|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ToggleDigimonInventoryUI constinit property declarations **************
// ********** End Function ToggleDigimonInventoryUI constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ToggleDigimonInventoryUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ToggleDigimonInventoryUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execToggleDigimonInventoryUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleDigimonInventoryUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ToggleDigimonInventoryUI ******************

// ********** Begin Class ADMFMMOPlayerController Function ToggleDigimonMenuUI *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ToggleDigimonMenuUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ToggleDigimonMenuUI constinit property declarations *******************
// ********** End Function ToggleDigimonMenuUI constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ToggleDigimonMenuUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ToggleDigimonMenuUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execToggleDigimonMenuUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleDigimonMenuUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ToggleDigimonMenuUI ***********************

// ********** Begin Class ADMFMMOPlayerController Function TogglePartyQuickAccessInteraction *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_TogglePartyQuickAccessInteraction_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TogglePartyQuickAccessInteraction constinit property declarations *****
// ********** End Function TogglePartyQuickAccessInteraction constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "TogglePartyQuickAccessInteraction", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_TogglePartyQuickAccessInteraction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execTogglePartyQuickAccessInteraction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TogglePartyQuickAccessInteraction();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function TogglePartyQuickAccessInteraction *********

// ********** Begin Class ADMFMMOPlayerController Function TogglePlayerSkinSelectionUI *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_TogglePlayerSkinSelectionUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Player Avatar|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TogglePlayerSkinSelectionUI constinit property declarations ***********
// ********** End Function TogglePlayerSkinSelectionUI constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "TogglePlayerSkinSelectionUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_TogglePlayerSkinSelectionUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execTogglePlayerSkinSelectionUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TogglePlayerSkinSelectionUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function TogglePlayerSkinSelectionUI ***************

// ********** Begin Class ADMFMMOPlayerController Function ToggleWorldChatInput ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ToggleWorldChatInput_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|World Chat|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ToggleWorldChatInput constinit property declarations ******************
// ********** End Function ToggleWorldChatInput constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ToggleWorldChatInput", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ToggleWorldChatInput(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execToggleWorldChatInput)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleWorldChatInput();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ToggleWorldChatInput **********************

// ********** Begin Class ADMFMMOPlayerController **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFMMOPlayerController_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * MMO player controller with ready-to-use onboarding, avatar skin and Digimon combat UI routing.\n * Public menu/command functions are Blueprint-callable so projects can replace the default F6/I/combat bindings.\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Game/DMFMMOPlayerController.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MMO player controller with ready-to-use onboarding, avatar skin and Digimon combat UI routing.\nPublic menu/command functions are Blueprint-callable so projects can replace the default F6/I/combat bindings." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHealerInteractionResult_MetaData[] = {
		{ "Category", "Digimon MMO|Healing" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHomeTeleportResult_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access|Home" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Owner-local result/presentation hook for native or custom Blueprint HUDs. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owner-local result/presentation hook for native or custom Blueprint HUDs." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnWorldChatMessageReceived_MetaData[] = {
		{ "Category", "Digimon MMO|World Chat" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarterWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatQuickBarWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartyQuickBarWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSkinWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonInventoryWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanNotificationWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperienceNotificationWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HomeTeleportNotificationWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldChatWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingPresentationActor_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local-only presentation actor. It is never replicated and exists only for the owning local PlayerController. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local-only presentation actor. It is never replicated and exists only for the owning local PlayerController." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFMMOPlayerController constinit property declarations ******************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHealerInteractionResult;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHomeTeleportResult;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnWorldChatMessageReceived;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StarterWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CombatQuickBarWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PartyQuickBarWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerSkinWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonInventoryWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanNotificationWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExperienceNotificationWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HomeTeleportNotificationWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldChatWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetingPresentationActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFMMOPlayerController constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ClientHealerInteractionResult"), .Pointer = &ADMFMMOPlayerController::execClientHealerInteractionResult },
		{ .NameUTF8 = UTF8TEXT("ClientReceiveWorldChatHistory"), .Pointer = &ADMFMMOPlayerController::execClientReceiveWorldChatHistory },
		{ .NameUTF8 = UTF8TEXT("ClientReceiveWorldChatMessage"), .Pointer = &ADMFMMOPlayerController::execClientReceiveWorldChatMessage },
		{ .NameUTF8 = UTF8TEXT("ClientReturnHomeResult"), .Pointer = &ADMFMMOPlayerController::execClientReturnHomeResult },
		{ .NameUTF8 = UTF8TEXT("ClientWorldChatSendRejected"), .Pointer = &ADMFMMOPlayerController::execClientWorldChatSendRejected },
		{ .NameUTF8 = UTF8TEXT("CloseDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execCloseDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("CloseDigimonMenuUI"), .Pointer = &ADMFMMOPlayerController::execCloseDigimonMenuUI },
		{ .NameUTF8 = UTF8TEXT("ClosePartyQuickAccessInteraction"), .Pointer = &ADMFMMOPlayerController::execClosePartyQuickAccessInteraction },
		{ .NameUTF8 = UTF8TEXT("ClosePlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execClosePlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("CloseWorldChatInput"), .Pointer = &ADMFMMOPlayerController::execCloseWorldChatInput },
		{ .NameUTF8 = UTF8TEXT("CommandActivePartnerAbilitySlot"), .Pointer = &ADMFMMOPlayerController::execCommandActivePartnerAbilitySlot },
		{ .NameUTF8 = UTF8TEXT("CommandPartnerTargetAndAttack"), .Pointer = &ADMFMMOPlayerController::execCommandPartnerTargetAndAttack },
		{ .NameUTF8 = UTF8TEXT("GetTargetingPresentationActor"), .Pointer = &ADMFMMOPlayerController::execGetTargetingPresentationActor },
		{ .NameUTF8 = UTF8TEXT("GetWorldChatWidget"), .Pointer = &ADMFMMOPlayerController::execGetWorldChatWidget },
		{ .NameUTF8 = UTF8TEXT("HandleCareSequenceFinished"), .Pointer = &ADMFMMOPlayerController::execHandleCareSequenceFinished },
		{ .NameUTF8 = UTF8TEXT("HandleCareSequenceStarted"), .Pointer = &ADMFMMOPlayerController::execHandleCareSequenceStarted },
		{ .NameUTF8 = UTF8TEXT("HandleDigimonExperienceProgressed"), .Pointer = &ADMFMMOPlayerController::execHandleDigimonExperienceProgressed },
		{ .NameUTF8 = UTF8TEXT("HandleDigivolutionResult"), .Pointer = &ADMFMMOPlayerController::execHandleDigivolutionResult },
		{ .NameUTF8 = UTF8TEXT("HandleDigivolutionSequenceStarted"), .Pointer = &ADMFMMOPlayerController::execHandleDigivolutionSequenceStarted },
		{ .NameUTF8 = UTF8TEXT("HandlePlayerSkinRequirementChanged"), .Pointer = &ADMFMMOPlayerController::execHandlePlayerSkinRequirementChanged },
		{ .NameUTF8 = UTF8TEXT("HandleScanDataRewardGranted"), .Pointer = &ADMFMMOPlayerController::execHandleScanDataRewardGranted },
		{ .NameUTF8 = UTF8TEXT("HandleStarterRequirementChanged"), .Pointer = &ADMFMMOPlayerController::execHandleStarterRequirementChanged },
		{ .NameUTF8 = UTF8TEXT("IsCarePresentationActive"), .Pointer = &ADMFMMOPlayerController::execIsCarePresentationActive },
		{ .NameUTF8 = UTF8TEXT("IsDigimonInventoryUIOpen"), .Pointer = &ADMFMMOPlayerController::execIsDigimonInventoryUIOpen },
		{ .NameUTF8 = UTF8TEXT("IsDigimonMenuUIOpen"), .Pointer = &ADMFMMOPlayerController::execIsDigimonMenuUIOpen },
		{ .NameUTF8 = UTF8TEXT("IsDigivolutionPresentationActive"), .Pointer = &ADMFMMOPlayerController::execIsDigivolutionPresentationActive },
		{ .NameUTF8 = UTF8TEXT("IsFrameworkPlayerAvatarPossessed"), .Pointer = &ADMFMMOPlayerController::execIsFrameworkPlayerAvatarPossessed },
		{ .NameUTF8 = UTF8TEXT("IsPartyQuickAccessInteractionActive"), .Pointer = &ADMFMMOPlayerController::execIsPartyQuickAccessInteractionActive },
		{ .NameUTF8 = UTF8TEXT("IsPlayerSkinSelectionUIOpen"), .Pointer = &ADMFMMOPlayerController::execIsPlayerSkinSelectionUIOpen },
		{ .NameUTF8 = UTF8TEXT("IsWorldChatInputActive"), .Pointer = &ADMFMMOPlayerController::execIsWorldChatInputActive },
		{ .NameUTF8 = UTF8TEXT("OpenBankUI"), .Pointer = &ADMFMMOPlayerController::execOpenBankUI },
		{ .NameUTF8 = UTF8TEXT("OpenCareUI"), .Pointer = &ADMFMMOPlayerController::execOpenCareUI },
		{ .NameUTF8 = UTF8TEXT("OpenDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execOpenDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("OpenDigimonMenuUI"), .Pointer = &ADMFMMOPlayerController::execOpenDigimonMenuUI },
		{ .NameUTF8 = UTF8TEXT("OpenDigivolutionUI"), .Pointer = &ADMFMMOPlayerController::execOpenDigivolutionUI },
		{ .NameUTF8 = UTF8TEXT("OpenPartyQuickAccessInteraction"), .Pointer = &ADMFMMOPlayerController::execOpenPartyQuickAccessInteraction },
		{ .NameUTF8 = UTF8TEXT("OpenPartyUI"), .Pointer = &ADMFMMOPlayerController::execOpenPartyUI },
		{ .NameUTF8 = UTF8TEXT("OpenPlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execOpenPlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("OpenScanMaterializeUI"), .Pointer = &ADMFMMOPlayerController::execOpenScanMaterializeUI },
		{ .NameUTF8 = UTF8TEXT("OpenWorldChatInput"), .Pointer = &ADMFMMOPlayerController::execOpenWorldChatInput },
		{ .NameUTF8 = UTF8TEXT("RefreshCombatQuickBar"), .Pointer = &ADMFMMOPlayerController::execRefreshCombatQuickBar },
		{ .NameUTF8 = UTF8TEXT("RefreshDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execRefreshDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("RefreshPartyQuickBar"), .Pointer = &ADMFMMOPlayerController::execRefreshPartyQuickBar },
		{ .NameUTF8 = UTF8TEXT("RefreshPlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execRefreshPlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("RefreshStarterSelectionUI"), .Pointer = &ADMFMMOPlayerController::execRefreshStarterSelectionUI },
		{ .NameUTF8 = UTF8TEXT("RefreshTargetingVisuals"), .Pointer = &ADMFMMOPlayerController::execRefreshTargetingVisuals },
		{ .NameUTF8 = UTF8TEXT("RefreshWorldChatUI"), .Pointer = &ADMFMMOPlayerController::execRefreshWorldChatUI },
		{ .NameUTF8 = UTF8TEXT("RequestReturnHome"), .Pointer = &ADMFMMOPlayerController::execRequestReturnHome },
		{ .NameUTF8 = UTF8TEXT("RequestUseHealer"), .Pointer = &ADMFMMOPlayerController::execRequestUseHealer },
		{ .NameUTF8 = UTF8TEXT("SelectDigimonCommandTargetUnderCursor"), .Pointer = &ADMFMMOPlayerController::execSelectDigimonCommandTargetUnderCursor },
		{ .NameUTF8 = UTF8TEXT("SendWorldChatMessage"), .Pointer = &ADMFMMOPlayerController::execSendWorldChatMessage },
		{ .NameUTF8 = UTF8TEXT("ServerEnsureFrameworkPlayerAvatar"), .Pointer = &ADMFMMOPlayerController::execServerEnsureFrameworkPlayerAvatar },
		{ .NameUTF8 = UTF8TEXT("ServerRequestReturnHome"), .Pointer = &ADMFMMOPlayerController::execServerRequestReturnHome },
		{ .NameUTF8 = UTF8TEXT("ServerRequestUseHealer"), .Pointer = &ADMFMMOPlayerController::execServerRequestUseHealer },
		{ .NameUTF8 = UTF8TEXT("ServerRequestWorldChatHistory"), .Pointer = &ADMFMMOPlayerController::execServerRequestWorldChatHistory },
		{ .NameUTF8 = UTF8TEXT("ServerSendWorldChatMessage"), .Pointer = &ADMFMMOPlayerController::execServerSendWorldChatMessage },
		{ .NameUTF8 = UTF8TEXT("SetDigimonCommandTarget"), .Pointer = &ADMFMMOPlayerController::execSetDigimonCommandTarget },
		{ .NameUTF8 = UTF8TEXT("ToggleDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execToggleDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("ToggleDigimonMenuUI"), .Pointer = &ADMFMMOPlayerController::execToggleDigimonMenuUI },
		{ .NameUTF8 = UTF8TEXT("TogglePartyQuickAccessInteraction"), .Pointer = &ADMFMMOPlayerController::execTogglePartyQuickAccessInteraction },
		{ .NameUTF8 = UTF8TEXT("TogglePlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execTogglePlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("ToggleWorldChatInput"), .Pointer = &ADMFMMOPlayerController::execToggleWorldChatInput },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientHealerInteractionResult, "ClientHealerInteractionResult" }, // fd0bd79f47752d4aeb3d61f8889502552ad8dfd2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveWorldChatHistory, "ClientReceiveWorldChatHistory" }, // 6057cac47a039332944027e85681a915fce91bcc
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveWorldChatMessage, "ClientReceiveWorldChatMessage" }, // dd21e14e744731cdaa9eab03158211713f8a27c9
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientReturnHomeResult, "ClientReturnHomeResult" }, // 912c5177039d04dd476918dbeb5b7bbe1765a362
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientWorldChatSendRejected, "ClientWorldChatSendRejected" }, // fe92f9e1dfd43bc01b0516e4be75a84702aa5424
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonInventoryUI, "CloseDigimonInventoryUI" }, // 9bdf8979d95ee2d0690ca274ebd92aeebb491e59
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonMenuUI, "CloseDigimonMenuUI" }, // 2d4c0431c81fb1351a38ec9b84d9cdca2104fc31
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClosePartyQuickAccessInteraction, "ClosePartyQuickAccessInteraction" }, // 7e9ac10edacaeb3e4890cd5d0ab7eecc582d7532
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClosePlayerSkinSelectionUI, "ClosePlayerSkinSelectionUI" }, // aea3717f1069c904491fb40ceb6a641c4744099b
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseWorldChatInput, "CloseWorldChatInput" }, // adcedc494f95685c5079b99a417855a026a22121
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CommandActivePartnerAbilitySlot, "CommandActivePartnerAbilitySlot" }, // 23e8ffa3a886714910a4020728670525fc575c67
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CommandPartnerTargetAndAttack, "CommandPartnerTargetAndAttack" }, // 29f86ad7ebe90c83566ec078666ff7b3fed62be5
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_GetTargetingPresentationActor, "GetTargetingPresentationActor" }, // 3027e85cfd2b3dd27749040fe21eb38fedec6e86
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_GetWorldChatWidget, "GetWorldChatWidget" }, // b264e970e7dcdb0c062385db218646c865077e93
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandleCareSequenceFinished, "HandleCareSequenceFinished" }, // 19f516ba8872840b2c39243f2545fb5cb8c6d50f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandleCareSequenceStarted, "HandleCareSequenceStarted" }, // 12e99f63bcc79520007a4e4ccecb1a57ee3333e0
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandleDigimonExperienceProgressed, "HandleDigimonExperienceProgressed" }, // 9e100e0118da503fad6d4a5940536a79506b3f85
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandleDigivolutionResult, "HandleDigivolutionResult" }, // 0ec02101ff4cabb3fcb43b05b3c595b89525ea3d
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandleDigivolutionSequenceStarted, "HandleDigivolutionSequenceStarted" }, // 654fcda44a7eef3b89e04b48bd2035458459c585
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandlePlayerSkinRequirementChanged, "HandlePlayerSkinRequirementChanged" }, // 68dd8a3d5479a2f4ce30a20dc045bdf5faad3e0c
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandleScanDataRewardGranted, "HandleScanDataRewardGranted" }, // 8a6ca3842df5e4f71d9dedf3b2f8ae845361dc80
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandleStarterRequirementChanged, "HandleStarterRequirementChanged" }, // 234f1c30a81b8146dc2439518b9346db300f0300
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsCarePresentationActive, "IsCarePresentationActive" }, // 5a7fc4571c9e51c59d73d7457472045128624433
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonInventoryUIOpen, "IsDigimonInventoryUIOpen" }, // 30dca46d49345b134256374d71d946aaaaf02902
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonMenuUIOpen, "IsDigimonMenuUIOpen" }, // 28782c7ad6876aac2319228f063dafa4993ac8ce
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsDigivolutionPresentationActive, "IsDigivolutionPresentationActive" }, // caf79b441580fa1797a22e49fa278d4b26b1d5e1
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsFrameworkPlayerAvatarPossessed, "IsFrameworkPlayerAvatarPossessed" }, // 137e1d5c5a9b74264ed1d4818e7daa146901353f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsPartyQuickAccessInteractionActive, "IsPartyQuickAccessInteractionActive" }, // bdaee1622d563d8bf327794fc948c4307f5eb54f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsPlayerSkinSelectionUIOpen, "IsPlayerSkinSelectionUIOpen" }, // 1dff57173550fa8c99970326a60d43d1f9750f57
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsWorldChatInputActive, "IsWorldChatInputActive" }, // 18b449baf58622a8bfb58d9b7d2c6bea168c2d7b
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenBankUI, "OpenBankUI" }, // 44a801ff5192e40ab547959e8bcf6bad7b49a6c2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenCareUI, "OpenCareUI" }, // 4dbc31bd7c13010e3254b6d69f91cd5480fb52f2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonInventoryUI, "OpenDigimonInventoryUI" }, // 3947e5ecc7643b8a10541f4dc0cb64fdc929fe37
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonMenuUI, "OpenDigimonMenuUI" }, // 787480e966b131e71ec312ab075f06312bab1600
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigivolutionUI, "OpenDigivolutionUI" }, // 6411f92a2d004bb4eea0ffdb9a5eca1db9b210fe
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenPartyQuickAccessInteraction, "OpenPartyQuickAccessInteraction" }, // 4fa78b4a8cc9ecb28451bd69f43c6fe9dac2a7e0
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenPartyUI, "OpenPartyUI" }, // b78a5dde0f669370c4a793d5dc3199c7bf16f888
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenPlayerSkinSelectionUI, "OpenPlayerSkinSelectionUI" }, // d2bef495faf2ebf66a36702e48fbd948f57318c2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenScanMaterializeUI, "OpenScanMaterializeUI" }, // 76471492722ae85e4c2db7c6646ad7c0c4ae5980
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenWorldChatInput, "OpenWorldChatInput" }, // 7233eb813566faabfa52b52afa89630fe4ccb76d
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshCombatQuickBar, "RefreshCombatQuickBar" }, // 55dfa403a03ba1802f9cdfed6954fe8855a9a3c9
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshDigimonInventoryUI, "RefreshDigimonInventoryUI" }, // 2eb6bbbfb19e039f95fba79d2ad9df2b035f7d97
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshPartyQuickBar, "RefreshPartyQuickBar" }, // 26d49dc08a1e05ec8c762195c40ad5fe60d7fa72
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshPlayerSkinSelectionUI, "RefreshPlayerSkinSelectionUI" }, // 63c4b16d73d5d5b889759ffda68ec30442000bb2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshStarterSelectionUI, "RefreshStarterSelectionUI" }, // d7dbaa478809f0e8e263917c1869d4d1e4c66543
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshTargetingVisuals, "RefreshTargetingVisuals" }, // 0fb1a439a67c7035c806b41797a56c12ebcc01bb
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshWorldChatUI, "RefreshWorldChatUI" }, // c7bea9fe9f25e72e3aee0396d97947d4a2f4b521
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestReturnHome, "RequestReturnHome" }, // 86d0e6ede7aa21feee2e8c6cba2dc0d9b6d03016
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestUseHealer, "RequestUseHealer" }, // 8b7c978fd62e9a2fccc659796cd3dcecd42dd1c2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_SelectDigimonCommandTargetUnderCursor, "SelectDigimonCommandTargetUnderCursor" }, // b31362fed008ea36285bb10bd1c1e764c00c95d5
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_SendWorldChatMessage, "SendWorldChatMessage" }, // 19fa6a3f4e69b7ed2c5fc12f23b28dbf24932862
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerEnsureFrameworkPlayerAvatar, "ServerEnsureFrameworkPlayerAvatar" }, // 5547590643a8cd2b864d0724cf9d4aa59fd1d83f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestReturnHome, "ServerRequestReturnHome" }, // ac64724c915a6560e24a80c8a99a26f2b2aeb590
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestUseHealer, "ServerRequestUseHealer" }, // 6a423e4241ab2b3633c55f745a05341f15f81895
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestWorldChatHistory, "ServerRequestWorldChatHistory" }, // 904bcf51dac8e9f68a90984b458a469c443e5e5c
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerSendWorldChatMessage, "ServerSendWorldChatMessage" }, // 4d1524f1e57c1bbb3437ae014255ae5ad29a1fba
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_SetDigimonCommandTarget, "SetDigimonCommandTarget" }, // e0e3f11fd4a59ce242ae4fac227e26c71cc4db0d
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ToggleDigimonInventoryUI, "ToggleDigimonInventoryUI" }, // 1893494b5ab3226eb58563a9dbb3d33d79a25fa8
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ToggleDigimonMenuUI, "ToggleDigimonMenuUI" }, // cf7e83b5f6bd46871bb374f8b3bb2c379433b0de
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_TogglePartyQuickAccessInteraction, "TogglePartyQuickAccessInteraction" }, // 222071190aaf3e9e4e4101a2e9bb8f782e83f4d5
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_TogglePlayerSkinSelectionUI, "TogglePlayerSkinSelectionUI" }, // 3abbb90440e9197880dc01d7101f3abee696245b
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ToggleWorldChatInput, "ToggleWorldChatInput" }, // 91b16854e010f48ade3f494c125b431f65460318
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFMMOPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFMMOPlayerController Property Definitions *****************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnHealerInteractionResult = { "OnHealerInteractionResult", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, OnHealerInteractionResult), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHealerInteractionResult__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHealerInteractionResult_MetaData), NewProp_OnHealerInteractionResult_MetaData) }; // 9ba86616cb8239af890236ec23f5944e3890a6ae
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnHomeTeleportResult = { "OnHomeTeleportResult", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, OnHomeTeleportResult), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHomeTeleportResult__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHomeTeleportResult_MetaData), NewProp_OnHomeTeleportResult_MetaData) }; // d8221dc513c60c1c4398e8dba5368e7d9b57428e
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnWorldChatMessageReceived = { "OnWorldChatMessageReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, OnWorldChatMessageReceived), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWorldChatMessageReceived__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnWorldChatMessageReceived_MetaData), NewProp_OnWorldChatMessageReceived_MetaData) }; // 94761aafd38e174865aca0bf93f8a0402e5c870a
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_StarterWidget = { "StarterWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, StarterWidget), Z_Construct_UClass_UDMFStarterSelectionWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarterWidget_MetaData), NewProp_StarterWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CombatQuickBarWidget = { "CombatQuickBarWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, CombatQuickBarWidget), Z_Construct_UClass_UDMFCombatQuickBarWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatQuickBarWidget_MetaData), NewProp_CombatQuickBarWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PartyQuickBarWidget = { "PartyQuickBarWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, PartyQuickBarWidget), Z_Construct_UClass_UDMFPartyQuickBarWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartyQuickBarWidget_MetaData), NewProp_PartyQuickBarWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerSkinWidget = { "PlayerSkinWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, PlayerSkinWidget), Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSkinWidget_MetaData), NewProp_PlayerSkinWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonInventoryWidget = { "DigimonInventoryWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, DigimonInventoryWidget), Z_Construct_UClass_UDMFDigimonInventoryWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonInventoryWidget_MetaData), NewProp_DigimonInventoryWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanNotificationWidget = { "ScanNotificationWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, ScanNotificationWidget), Z_Construct_UClass_UDMFScanNotificationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanNotificationWidget_MetaData), NewProp_ScanNotificationWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ExperienceNotificationWidget = { "ExperienceNotificationWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, ExperienceNotificationWidget), Z_Construct_UClass_UDMFExperienceNotificationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperienceNotificationWidget_MetaData), NewProp_ExperienceNotificationWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HomeTeleportNotificationWidget = { "HomeTeleportNotificationWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, HomeTeleportNotificationWidget), Z_Construct_UClass_UDMFHomeTeleportNotificationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HomeTeleportNotificationWidget_MetaData), NewProp_HomeTeleportNotificationWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WorldChatWidget = { "WorldChatWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, WorldChatWidget), Z_Construct_UClass_UDMFWorldChatWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatWidget_MetaData), NewProp_WorldChatWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetingPresentationActor = { "TargetingPresentationActor", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, TargetingPresentationActor), Z_Construct_UClass_ADMFTargetingPresentationActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingPresentationActor_MetaData), NewProp_TargetingPresentationActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnHealerInteractionResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnHomeTeleportResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnWorldChatMessageReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StarterWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatQuickBarWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartyQuickBarWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSkinWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInventoryWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanNotificationWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExperienceNotificationWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HomeTeleportNotificationWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetingPresentationActor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFMMOPlayerController Property Definitions *******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_APlayerController,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFMMOPlayerController,
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
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void ADMFMMOPlayerController_StaticRegisterNativesADMFMMOPlayerController()
{
	UClass* Class = ADMFMMOPlayerController::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFMMOPlayerController;
UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFMMOPlayerController;
		if (!Z_Registration_Info_UClass_ADMFMMOPlayerController.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFMMOPlayerController"),
				Z_Registration_Info_UClass_ADMFMMOPlayerController.InnerSingleton,
				ADMFMMOPlayerController_StaticRegisterNativesADMFMMOPlayerController,
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
		return Z_Registration_Info_UClass_ADMFMMOPlayerController.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFMMOPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFMMOPlayerController.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFMMOPlayerController.OuterSingleton;
}
#undef UHT_STATICS
ADMFMMOPlayerController::ADMFMMOPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFMMOPlayerController);
ADMFMMOPlayerController::~ADMFMMOPlayerController() {}
// ********** End Class ADMFMMOPlayerController ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFMMOPlayerController, TEXT("ADMFMMOPlayerController"), &Z_Registration_Info_UClass_ADMFMMOPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFMMOPlayerController), 1890192112U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h__Script_DigimonMMOFramework_b9932aa8b9fec4426f01491790d9ec6f0aab1ccf{
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
