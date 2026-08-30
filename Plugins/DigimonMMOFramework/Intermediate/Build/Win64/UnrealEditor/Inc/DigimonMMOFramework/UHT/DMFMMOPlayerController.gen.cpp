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
UMG_API UClass* Z_Construct_UClass_UWidgetComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorTransactionResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHealerInteractionResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHomeTeleportResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorTransactionResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFNearbySocialPlayerEntry(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialActionResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFSocialSnapshot(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialSnapshotChanged__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWorldChatMessage(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWorldChatMessageReceived__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialActionType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFCombatQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonVendorActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonVendorWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFExperienceNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFHealerActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFHomeTeleportNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFItemVendorActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemVendorWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPartyQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSocialContextWidget(ETypeConstructPhase);
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
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ChatMessage = { "ChatMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFWorldChatMessageReceived_Parms, ChatMessage), Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(0, nullptr) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
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

// ********** Begin Delegate FDMFSocialSnapshotChanged *********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialSnapshotChanged__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFSocialSnapshotChanged_Parms
	{
		FDMFSocialSnapshot SocialSnapshot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFSocialSnapshotChanged constinit property declarations *************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SocialSnapshot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFSocialSnapshotChanged constinit property declarations ***************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFSocialSnapshotChanged Property Definitions ************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SocialSnapshot = { "SocialSnapshot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFSocialSnapshotChanged_Parms, SocialSnapshot), Z_Construct_UScriptStruct_FDMFSocialSnapshot, METADATA_PARAMS(0, nullptr) }; // af2ade89cc42d87d03c8fc281787c2464eeda2af
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialSnapshot,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFSocialSnapshotChanged Property Definitions **************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFSocialSnapshotChanged__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFSocialSnapshotChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFSocialSnapshotChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialSnapshotChanged__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFSocialSnapshotChanged ***********************************************

// ********** Begin Delegate FDMFSocialActionResult ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialActionResult__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFSocialActionResult_Parms
	{
		bool bSuccess;
		FText Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFSocialActionResult constinit property declarations ****************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFSocialActionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFSocialActionResult constinit property declarations ******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFSocialActionResult Property Definitions ***************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFSocialActionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFSocialActionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFSocialActionResult Property Definitions *****************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFSocialActionResult__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFSocialActionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFSocialActionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialActionResult__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFSocialActionResult **************************************************

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

// ********** Begin Delegate FDMFDigimonVendorTransactionResult ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorTransactionResult__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms
	{
		bool bSuccess;
		FText Message;
		EDMFDigimonVendorTransactionType TransactionType;
		FGuid Identifier;
		int64 Price;
		int64 NewMoney;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFDigimonVendorTransactionResult constinit property declarations ****
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Identifier;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Price;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NewMoney;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFDigimonVendorTransactionResult constinit property declarations ******
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFDigimonVendorTransactionResult Property Definitions ***************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms, Identifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_Price = { "Price", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms, Price), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NewMoney = { "NewMoney", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms, NewMoney), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Identifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Price,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewMoney,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFDigimonVendorTransactionResult Property Definitions *****************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFDigimonVendorTransactionResult__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonVendorTransactionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorTransactionResult__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFDigimonVendorTransactionResult **************************************

// ********** Begin Delegate FDMFItemVendorTransactionResult ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorTransactionResult__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms
	{
		bool bSuccess;
		FText Message;
		EDMFItemVendorTransactionType TransactionType;
		FPrimaryAssetId ItemAssetId;
		int32 Quantity;
		int64 TotalPrice;
		int64 NewMoney;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFItemVendorTransactionResult constinit property declarations *******
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalPrice;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NewMoney;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFItemVendorTransactionResult constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFItemVendorTransactionResult Property Definitions ******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_TotalPrice = { "TotalPrice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms, TotalPrice), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NewMoney = { "NewMoney", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms, NewMoney), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TotalPrice,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewMoney,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFItemVendorTransactionResult Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFItemVendorTransactionResult__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemVendorTransactionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorTransactionResult__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFItemVendorTransactionResult *****************************************

// ********** Begin Class ADMFMMOPlayerController Function ClientDigimonVendorTransactionResult ****
struct DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms
{
	bool bSuccess;
	FText Message;
	EDMFDigimonVendorTransactionType TransactionType;
	FGuid Identifier;
	int64 Price;
	int64 NewMoney;
};
static FName NAME_ADMFMMOPlayerController_ClientDigimonVendorTransactionResult = FName(TEXT("ClientDigimonVendorTransactionResult"));
void ADMFMMOPlayerController::ClientDigimonVendorTransactionResult(bool bSuccess, FText const& Message, EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier, int64 Price, int64 NewMoney)
{
	DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Message=Message;
	Parms.TransactionType=TransactionType;
	Parms.Identifier=Identifier;
	Parms.Price=Price;
	Parms.NewMoney=NewMoney;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ClientDigimonVendorTransactionResult);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClientDigimonVendorTransactionResult_Statics
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

// ********** Begin Function ClientDigimonVendorTransactionResult constinit property declarations **
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Identifier;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Price;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NewMoney;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientDigimonVendorTransactionResult constinit property declarations ****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientDigimonVendorTransactionResult Property Definitions *************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms, Identifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_Price = { "Price", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms, Price), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NewMoney = { "NewMoney", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms, NewMoney), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Identifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Price,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewMoney,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientDigimonVendorTransactionResult Property Definitions ***************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClientDigimonVendorTransactionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01820CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventClientDigimonVendorTransactionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClientDigimonVendorTransactionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClientDigimonVendorTransactionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_ENUM(EDMFDigimonVendorTransactionType,Z_Param_TransactionType);
	P_GET_STRUCT(FGuid,Z_Param_Identifier);
	P_GET_PROPERTY(FInt64Property,Z_Param_Price);
	P_GET_PROPERTY(FInt64Property,Z_Param_NewMoney);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientDigimonVendorTransactionResult_Implementation(Z_Param_bSuccess,Z_Param_Message,EDMFDigimonVendorTransactionType(Z_Param_TransactionType),Z_Param_Identifier,Z_Param_Price,Z_Param_NewMoney);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClientDigimonVendorTransactionResult ******

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

// ********** Begin Class ADMFMMOPlayerController Function ClientItemVendorTransactionResult *******
struct DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms
{
	bool bSuccess;
	FText Message;
	EDMFItemVendorTransactionType TransactionType;
	FPrimaryAssetId ItemAssetId;
	int32 Quantity;
	int64 TotalPrice;
	int64 NewMoney;
};
static FName NAME_ADMFMMOPlayerController_ClientItemVendorTransactionResult = FName(TEXT("ClientItemVendorTransactionResult"));
void ADMFMMOPlayerController::ClientItemVendorTransactionResult(bool bSuccess, FText const& Message, EDMFItemVendorTransactionType TransactionType, FPrimaryAssetId ItemAssetId, int32 Quantity, int64 TotalPrice, int64 NewMoney)
{
	DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Message=Message;
	Parms.TransactionType=TransactionType;
	Parms.ItemAssetId=ItemAssetId;
	Parms.Quantity=Quantity;
	Parms.TotalPrice=TotalPrice;
	Parms.NewMoney=NewMoney;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ClientItemVendorTransactionResult);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClientItemVendorTransactionResult_Statics
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

// ********** Begin Function ClientItemVendorTransactionResult constinit property declarations *****
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalPrice;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NewMoney;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientItemVendorTransactionResult constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientItemVendorTransactionResult Property Definitions ****************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_TotalPrice = { "TotalPrice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms, TotalPrice), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NewMoney = { "NewMoney", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms, NewMoney), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TotalPrice,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewMoney,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientItemVendorTransactionResult Property Definitions ******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClientItemVendorTransactionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventClientItemVendorTransactionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClientItemVendorTransactionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClientItemVendorTransactionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_ENUM(EDMFItemVendorTransactionType,Z_Param_TransactionType);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_ItemAssetId);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_GET_PROPERTY(FInt64Property,Z_Param_TotalPrice);
	P_GET_PROPERTY(FInt64Property,Z_Param_NewMoney);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientItemVendorTransactionResult_Implementation(Z_Param_bSuccess,Z_Param_Message,EDMFItemVendorTransactionType(Z_Param_TransactionType),Z_Param_ItemAssetId,Z_Param_Quantity,Z_Param_TotalPrice,Z_Param_NewMoney);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClientItemVendorTransactionResult *********

// ********** Begin Class ADMFMMOPlayerController Function ClientReceiveSocialSnapshot *************
struct DMFMMOPlayerController_eventClientReceiveSocialSnapshot_Parms
{
	FDMFSocialSnapshot SocialSnapshot;
};
static FName NAME_ADMFMMOPlayerController_ClientReceiveSocialSnapshot = FName(TEXT("ClientReceiveSocialSnapshot"));
void ADMFMMOPlayerController::ClientReceiveSocialSnapshot(FDMFSocialSnapshot const& SocialSnapshot)
{
	DMFMMOPlayerController_eventClientReceiveSocialSnapshot_Parms Parms;
	Parms.SocialSnapshot=SocialSnapshot;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ClientReceiveSocialSnapshot);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveSocialSnapshot_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialSnapshot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClientReceiveSocialSnapshot constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_SocialSnapshot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientReceiveSocialSnapshot constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientReceiveSocialSnapshot Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SocialSnapshot = { "SocialSnapshot", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientReceiveSocialSnapshot_Parms, SocialSnapshot), Z_Construct_UScriptStruct_FDMFSocialSnapshot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialSnapshot_MetaData), NewProp_SocialSnapshot_MetaData) }; // af2ade89cc42d87d03c8fc281787c2464eeda2af
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialSnapshot,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientReceiveSocialSnapshot Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClientReceiveSocialSnapshot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventClientReceiveSocialSnapshot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventClientReceiveSocialSnapshot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveSocialSnapshot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClientReceiveSocialSnapshot)
{
	P_GET_STRUCT(FDMFSocialSnapshot,Z_Param_SocialSnapshot);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientReceiveSocialSnapshot_Implementation(Z_Param_SocialSnapshot);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClientReceiveSocialSnapshot ***************

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
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ChatMessages_Inner = { "ChatMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(0, nullptr) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ChatMessages = { "ChatMessages", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientReceiveWorldChatHistory_Parms, ChatMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChatMessages_MetaData), NewProp_ChatMessages_MetaData) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
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
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ChatMessage = { "ChatMessage", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientReceiveWorldChatMessage_Parms, ChatMessage), Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChatMessage_MetaData), NewProp_ChatMessage_MetaData) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
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

// ********** Begin Class ADMFMMOPlayerController Function ClientSocialActionResult ****************
struct DMFMMOPlayerController_eventClientSocialActionResult_Parms
{
	bool bSuccess;
	FText Message;
};
static FName NAME_ADMFMMOPlayerController_ClientSocialActionResult = FName(TEXT("ClientSocialActionResult"));
void ADMFMMOPlayerController::ClientSocialActionResult(bool bSuccess, FText const& Message)
{
	DMFMMOPlayerController_eventClientSocialActionResult_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Message=Message;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ClientSocialActionResult);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClientSocialActionResult_Statics
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

// ********** Begin Function ClientSocialActionResult constinit property declarations **************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventClientSocialActionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClientSocialActionResult constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClientSocialActionResult Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventClientSocialActionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventClientSocialActionResult_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ClientSocialActionResult Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClientSocialActionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventClientSocialActionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventClientSocialActionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClientSocialActionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClientSocialActionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientSocialActionResult_Implementation(Z_Param_bSuccess,Z_Param_Message);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClientSocialActionResult ******************

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

// ********** Begin Class ADMFMMOPlayerController Function CloseDigimonVendorUI ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonVendorUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseDigimonVendorUI constinit property declarations ******************
// ********** End Function CloseDigimonVendorUI constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "CloseDigimonVendorUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonVendorUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execCloseDigimonVendorUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseDigimonVendorUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function CloseDigimonVendorUI **********************

// ********** Begin Class ADMFMMOPlayerController Function CloseItemVendorUI ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_CloseItemVendorUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseItemVendorUI constinit property declarations *********************
// ********** End Function CloseItemVendorUI constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "CloseItemVendorUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_CloseItemVendorUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execCloseItemVendorUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseItemVendorUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function CloseItemVendorUI *************************

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

// ********** Begin Class ADMFMMOPlayerController Function ClosePlayerSocialContextUI **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ClosePlayerSocialContextUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Nameplate Context" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClosePlayerSocialContextUI constinit property declarations ************
// ********** End Function ClosePlayerSocialContextUI constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ClosePlayerSocialContextUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ClosePlayerSocialContextUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execClosePlayerSocialContextUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClosePlayerSocialContextUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ClosePlayerSocialContextUI ****************

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

// ********** Begin Class ADMFMMOPlayerController Function GetActiveDigimonVendor ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_GetActiveDigimonVendor_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventGetActiveDigimonVendor_Parms
	{
		ADMFDigimonVendorActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveDigimonVendor constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveDigimonVendor constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveDigimonVendor Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventGetActiveDigimonVendor_Parms, ReturnValue), Z_Construct_UClass_ADMFDigimonVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetActiveDigimonVendor Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "GetActiveDigimonVendor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventGetActiveDigimonVendor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventGetActiveDigimonVendor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_GetActiveDigimonVendor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execGetActiveDigimonVendor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFDigimonVendorActor**)Z_Param__Result=P_THIS->GetActiveDigimonVendor();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function GetActiveDigimonVendor ********************

// ********** Begin Class ADMFMMOPlayerController Function GetActiveItemVendor *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_GetActiveItemVendor_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventGetActiveItemVendor_Parms
	{
		ADMFItemVendorActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveItemVendor constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveItemVendor constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveItemVendor Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventGetActiveItemVendor_Parms, ReturnValue), Z_Construct_UClass_ADMFItemVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetActiveItemVendor Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "GetActiveItemVendor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventGetActiveItemVendor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventGetActiveItemVendor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_GetActiveItemVendor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execGetActiveItemVendor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFItemVendorActor**)Z_Param__Result=P_THIS->GetActiveItemVendor();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function GetActiveItemVendor ***********************

// ********** Begin Class ADMFMMOPlayerController Function GetCachedSocialSnapshot *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_GetCachedSocialSnapshot_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventGetCachedSocialSnapshot_Parms
	{
		FDMFSocialSnapshot ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Last owner-only snapshot received from authority; never replicated through PlayerState/world actors. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Last owner-only snapshot received from authority; never replicated through PlayerState/world actors." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCachedSocialSnapshot constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCachedSocialSnapshot constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCachedSocialSnapshot Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventGetCachedSocialSnapshot_Parms, ReturnValue), Z_Construct_UScriptStruct_FDMFSocialSnapshot, METADATA_PARAMS(0, nullptr) }; // af2ade89cc42d87d03c8fc281787c2464eeda2af
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCachedSocialSnapshot Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "GetCachedSocialSnapshot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventGetCachedSocialSnapshot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventGetCachedSocialSnapshot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_GetCachedSocialSnapshot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execGetCachedSocialSnapshot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FDMFSocialSnapshot*)Z_Param__Result=P_THIS->GetCachedSocialSnapshot();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function GetCachedSocialSnapshot *******************

// ********** Begin Class ADMFMMOPlayerController Function GetNearbySocialPlayers ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_GetNearbySocialPlayers_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventGetNearbySocialPlayers_Parms
	{
		TArray<FDMFNearbySocialPlayerEntry> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friends|Nearby Players" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Returns nearby replicated player avatars inside the global Project Settings radius, nearest first.\n     * This is owner-local discovery/presentation only; friend mutations remain server-authoritative.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns nearby replicated player avatars inside the global Project Settings radius, nearest first.\nThis is owner-local discovery/presentation only; friend mutations remain server-authoritative." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetNearbySocialPlayers constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNearbySocialPlayers constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNearbySocialPlayers Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFNearbySocialPlayerEntry, METADATA_PARAMS(0, nullptr) }; // a9236a2a28d960e914bc7c9a98a8d8851b455b78
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventGetNearbySocialPlayers_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // a9236a2a28d960e914bc7c9a98a8d8851b455b78
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetNearbySocialPlayers Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "GetNearbySocialPlayers", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventGetNearbySocialPlayers_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventGetNearbySocialPlayers_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_GetNearbySocialPlayers(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execGetNearbySocialPlayers)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FDMFNearbySocialPlayerEntry>*)Z_Param__Result=P_THIS->GetNearbySocialPlayers();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function GetNearbySocialPlayers ********************

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

// ********** Begin Class ADMFMMOPlayerController Function IsDigimonVendorUIOpen *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonVendorUIOpen_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsDigimonVendorUIOpen_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDigimonVendorUIOpen constinit property declarations *****************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsDigimonVendorUIOpen_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDigimonVendorUIOpen constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDigimonVendorUIOpen Property Definitions ****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsDigimonVendorUIOpen_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsDigimonVendorUIOpen Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsDigimonVendorUIOpen", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsDigimonVendorUIOpen_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsDigimonVendorUIOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonVendorUIOpen(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsDigimonVendorUIOpen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDigimonVendorUIOpen();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsDigimonVendorUIOpen *********************

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

// ********** Begin Class ADMFMMOPlayerController Function IsItemVendorUIOpen **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_IsItemVendorUIOpen_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventIsItemVendorUIOpen_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsItemVendorUIOpen constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventIsItemVendorUIOpen_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsItemVendorUIOpen constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsItemVendorUIOpen Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventIsItemVendorUIOpen_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsItemVendorUIOpen Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "IsItemVendorUIOpen", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventIsItemVendorUIOpen_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventIsItemVendorUIOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_IsItemVendorUIOpen(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execIsItemVendorUIOpen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsItemVendorUIOpen();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function IsItemVendorUIOpen ************************

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

// ********** Begin Class ADMFMMOPlayerController Function OpenDigimonVendorUI *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonVendorUI_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventOpenDigimonVendorUI_Parms
	{
		ADMFDigimonVendorActor* Vendor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the owner-local native BUY / SELL market UI for a nearby replicated vendor. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the owner-local native BUY / SELL market UI for a nearby replicated vendor." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenDigimonVendorUI constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Vendor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenDigimonVendorUI constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenDigimonVendorUI Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Vendor = { "Vendor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventOpenDigimonVendorUI_Parms, Vendor), Z_Construct_UClass_ADMFDigimonVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Vendor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OpenDigimonVendorUI Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenDigimonVendorUI", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventOpenDigimonVendorUI_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventOpenDigimonVendorUI_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonVendorUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenDigimonVendorUI)
{
	P_GET_OBJECT(ADMFDigimonVendorActor,Z_Param_Vendor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenDigimonVendorUI(Z_Param_Vendor);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenDigimonVendorUI ***********************

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

// ********** Begin Class ADMFMMOPlayerController Function OpenItemsUI *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenItemsUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Items|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the shared Digimon menu directly on the private persistent player item bag. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the shared Digimon menu directly on the private persistent player item bag." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenItemsUI constinit property declarations ***************************
// ********** End Function OpenItemsUI constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenItemsUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenItemsUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenItemsUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenItemsUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenItemsUI *******************************

// ********** Begin Class ADMFMMOPlayerController Function OpenItemVendorUI ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenItemVendorUI_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventOpenItemVendorUI_Parms
	{
		ADMFItemVendorActor* Vendor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the owner-local native BUY / SELL item exchange for a nearby replicated item vendor. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the owner-local native BUY / SELL item exchange for a nearby replicated item vendor." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenItemVendorUI constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Vendor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenItemVendorUI constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenItemVendorUI Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Vendor = { "Vendor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventOpenItemVendorUI_Parms, Vendor), Z_Construct_UClass_ADMFItemVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Vendor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OpenItemVendorUI Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenItemVendorUI", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventOpenItemVendorUI_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventOpenItemVendorUI_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenItemVendorUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenItemVendorUI)
{
	P_GET_OBJECT(ADMFItemVendorActor,Z_Param_Vendor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenItemVendorUI(Z_Param_Vendor);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenItemVendorUI **************************

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

// ********** Begin Class ADMFMMOPlayerController Function OpenPlayerSocialContext *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenPlayerSocialContext_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventOpenPlayerSocialContext_Parms
	{
		ADMFPlayerAvatarCharacter* TargetPlayer;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Nameplate Context" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the owner-local dropdown next to the mouse cursor for an exact replicated player nameplate. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the owner-local dropdown next to the mouse cursor for an exact replicated player nameplate." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenPlayerSocialContext constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetPlayer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenPlayerSocialContext constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenPlayerSocialContext Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetPlayer = { "TargetPlayer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventOpenPlayerSocialContext_Parms, TargetPlayer), Z_Construct_UClass_ADMFPlayerAvatarCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetPlayer,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OpenPlayerSocialContext Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenPlayerSocialContext", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventOpenPlayerSocialContext_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventOpenPlayerSocialContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenPlayerSocialContext(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenPlayerSocialContext)
{
	P_GET_OBJECT(ADMFPlayerAvatarCharacter,Z_Param_TargetPlayer);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenPlayerSocialContext(Z_Param_TargetPlayer);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenPlayerSocialContext *******************

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

// ********** Begin Class ADMFMMOPlayerController Function OpenSocialUI ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_OpenSocialUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Opens the shared Digimon menu directly on the persistent Social hub. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Opens the shared Digimon menu directly on the persistent Social hub." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenSocialUI constinit property declarations **************************
// ********** End Function OpenSocialUI constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "OpenSocialUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_OpenSocialUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execOpenSocialUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenSocialUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function OpenSocialUI ******************************

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

// ********** Begin Class ADMFMMOPlayerController Function RefreshDigimonVendorUI ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshDigimonVendorUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshDigimonVendorUI constinit property declarations ****************
// ********** End Function RefreshDigimonVendorUI constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshDigimonVendorUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshDigimonVendorUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshDigimonVendorUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshDigimonVendorUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshDigimonVendorUI ********************

// ********** Begin Class ADMFMMOPlayerController Function RefreshFriendTrackingPresentation *******
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshFriendTrackingPresentation_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friend Tracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reconciles local-only tracked-friend WidgetComponents against replicated online player avatars. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reconciles local-only tracked-friend WidgetComponents against replicated online player avatars." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshFriendTrackingPresentation constinit property declarations *****
// ********** End Function RefreshFriendTrackingPresentation constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshFriendTrackingPresentation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshFriendTrackingPresentation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshFriendTrackingPresentation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshFriendTrackingPresentation();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshFriendTrackingPresentation *********

// ********** Begin Class ADMFMMOPlayerController Function RefreshItemVendorUI *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RefreshItemVendorUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor|UI" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshItemVendorUI constinit property declarations *******************
// ********** End Function RefreshItemVendorUI constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RefreshItemVendorUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RefreshItemVendorUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRefreshItemVendorUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshItemVendorUI();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RefreshItemVendorUI ***********************

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

// ********** Begin Class ADMFMMOPlayerController Function RequestAddFriend ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestAddFriend_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestAddFriend_Parms
	{
		FString TargetUsername;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friends" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestAddFriend constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetUsername;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestAddFriend constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestAddFriend Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetUsername = { "TargetUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestAddFriend_Parms, TargetUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetUsername_MetaData), NewProp_TargetUsername_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetUsername,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestAddFriend Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestAddFriend", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestAddFriend_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestAddFriend_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestAddFriend(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestAddFriend)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetUsername);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestAddFriend(Z_Param_TargetUsername);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestAddFriend **************************

// ********** Begin Class ADMFMMOPlayerController Function RequestApplyToGuild *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestApplyToGuild_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestApplyToGuild_Parms
	{
		FGuid GuildId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Guild" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestApplyToGuild constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_GuildId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestApplyToGuild constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestApplyToGuild Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_GuildId = { "GuildId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestApplyToGuild_Parms, GuildId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GuildId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestApplyToGuild Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestApplyToGuild", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestApplyToGuild_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestApplyToGuild_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestApplyToGuild(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestApplyToGuild)
{
	P_GET_STRUCT(FGuid,Z_Param_GuildId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestApplyToGuild(Z_Param_GuildId);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestApplyToGuild ***********************

// ********** Begin Class ADMFMMOPlayerController Function RequestCancelFriendRequest **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestCancelFriendRequest_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestCancelFriendRequest_Parms
	{
		FString TargetUsername;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friends" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestCancelFriendRequest constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetUsername;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestCancelFriendRequest constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestCancelFriendRequest Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetUsername = { "TargetUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestCancelFriendRequest_Parms, TargetUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetUsername_MetaData), NewProp_TargetUsername_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetUsername,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestCancelFriendRequest Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestCancelFriendRequest", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestCancelFriendRequest_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestCancelFriendRequest_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestCancelFriendRequest(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestCancelFriendRequest)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetUsername);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestCancelFriendRequest(Z_Param_TargetUsername);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestCancelFriendRequest ****************

// ********** Begin Class ADMFMMOPlayerController Function RequestCreateGuild **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestCreateGuild_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestCreateGuild_Parms
	{
		FString GuildName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Guild" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuildName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestCreateGuild constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_GuildName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestCreateGuild constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestCreateGuild Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_GuildName = { "GuildName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestCreateGuild_Parms, GuildName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuildName_MetaData), NewProp_GuildName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GuildName,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestCreateGuild Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestCreateGuild", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestCreateGuild_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestCreateGuild_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestCreateGuild(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestCreateGuild)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_GuildName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestCreateGuild(Z_Param_GuildName);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestCreateGuild ************************

// ********** Begin Class ADMFMMOPlayerController Function RequestDigimonVendorTransaction *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestDigimonVendorTransaction_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestDigimonVendorTransaction_Parms
	{
		ADMFDigimonVendorActor* Vendor;
		EDMFDigimonVendorTransactionType TransactionType;
		FGuid Identifier;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Client-facing request. Price/stats/money are intentionally never accepted from the caller. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client-facing request. Price/stats/money are intentionally never accepted from the caller." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestDigimonVendorTransaction constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Vendor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Identifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestDigimonVendorTransaction constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestDigimonVendorTransaction Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Vendor = { "Vendor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestDigimonVendorTransaction_Parms, Vendor), Z_Construct_UClass_ADMFDigimonVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestDigimonVendorTransaction_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestDigimonVendorTransaction_Parms, Identifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Vendor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Identifier,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestDigimonVendorTransaction Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestDigimonVendorTransaction", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestDigimonVendorTransaction_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestDigimonVendorTransaction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestDigimonVendorTransaction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestDigimonVendorTransaction)
{
	P_GET_OBJECT(ADMFDigimonVendorActor,Z_Param_Vendor);
	P_GET_ENUM(EDMFDigimonVendorTransactionType,Z_Param_TransactionType);
	P_GET_STRUCT(FGuid,Z_Param_Identifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestDigimonVendorTransaction(Z_Param_Vendor,EDMFDigimonVendorTransactionType(Z_Param_TransactionType),Z_Param_Identifier);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestDigimonVendorTransaction ***********

// ********** Begin Class ADMFMMOPlayerController Function RequestDisbandGuild *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestDisbandGuild_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Guild" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestDisbandGuild constinit property declarations *******************
// ********** End Function RequestDisbandGuild constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestDisbandGuild", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestDisbandGuild(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestDisbandGuild)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestDisbandGuild();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestDisbandGuild ***********************

// ********** Begin Class ADMFMMOPlayerController Function RequestIgnorePlayer *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestIgnorePlayer_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestIgnorePlayer_Parms
	{
		FString TargetUsername;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Ignore" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestIgnorePlayer constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetUsername;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestIgnorePlayer constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestIgnorePlayer Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetUsername = { "TargetUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestIgnorePlayer_Parms, TargetUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetUsername_MetaData), NewProp_TargetUsername_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetUsername,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestIgnorePlayer Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestIgnorePlayer", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestIgnorePlayer_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestIgnorePlayer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestIgnorePlayer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestIgnorePlayer)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetUsername);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestIgnorePlayer(Z_Param_TargetUsername);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestIgnorePlayer ***********************

// ********** Begin Class ADMFMMOPlayerController Function RequestInvitePlayerToGuild **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestInvitePlayerToGuild_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestInvitePlayerToGuild_Parms
	{
		FString TargetUsername;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Guild" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestInvitePlayerToGuild constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetUsername;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestInvitePlayerToGuild constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestInvitePlayerToGuild Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetUsername = { "TargetUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestInvitePlayerToGuild_Parms, TargetUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetUsername_MetaData), NewProp_TargetUsername_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetUsername,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestInvitePlayerToGuild Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestInvitePlayerToGuild", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestInvitePlayerToGuild_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestInvitePlayerToGuild_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestInvitePlayerToGuild(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestInvitePlayerToGuild)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetUsername);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestInvitePlayerToGuild(Z_Param_TargetUsername);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestInvitePlayerToGuild ****************

// ********** Begin Class ADMFMMOPlayerController Function RequestItemVendorTransaction ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestItemVendorTransaction_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestItemVendorTransaction_Parms
	{
		ADMFItemVendorActor* Vendor;
		EDMFItemVendorTransactionType TransactionType;
		FGuid StockId;
		FPrimaryAssetId ItemAssetId;
		int32 Quantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Client submits only selection identity + quantity. Stock, prices, BITS and inventory capacity are server-resolved. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client submits only selection identity + quantity. Stock, prices, BITS and inventory capacity are server-resolved." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestItemVendorTransaction constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Vendor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StockId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestItemVendorTransaction constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestItemVendorTransaction Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Vendor = { "Vendor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestItemVendorTransaction_Parms, Vendor), Z_Construct_UClass_ADMFItemVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestItemVendorTransaction_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StockId = { "StockId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestItemVendorTransaction_Parms, StockId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestItemVendorTransaction_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestItemVendorTransaction_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Vendor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Quantity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestItemVendorTransaction Property Definitions ***********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestItemVendorTransaction", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestItemVendorTransaction_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestItemVendorTransaction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestItemVendorTransaction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestItemVendorTransaction)
{
	P_GET_OBJECT(ADMFItemVendorActor,Z_Param_Vendor);
	P_GET_ENUM(EDMFItemVendorTransactionType,Z_Param_TransactionType);
	P_GET_STRUCT(FGuid,Z_Param_StockId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_ItemAssetId);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestItemVendorTransaction(Z_Param_Vendor,EDMFItemVendorTransactionType(Z_Param_TransactionType),Z_Param_StockId,Z_Param_ItemAssetId,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestItemVendorTransaction **************

// ********** Begin Class ADMFMMOPlayerController Function RequestLeaveGuild ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestLeaveGuild_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Guild" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestLeaveGuild constinit property declarations *********************
// ********** End Function RequestLeaveGuild constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestLeaveGuild", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestLeaveGuild(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestLeaveGuild)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestLeaveGuild();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestLeaveGuild *************************

// ********** Begin Class ADMFMMOPlayerController Function RequestRemoveFriend *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestRemoveFriend_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestRemoveFriend_Parms
	{
		FString FriendUsername;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friends" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestRemoveFriend constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FriendUsername;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestRemoveFriend constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestRemoveFriend Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FriendUsername = { "FriendUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestRemoveFriend_Parms, FriendUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendUsername_MetaData), NewProp_FriendUsername_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FriendUsername,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestRemoveFriend Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestRemoveFriend", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestRemoveFriend_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestRemoveFriend_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestRemoveFriend(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestRemoveFriend)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FriendUsername);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestRemoveFriend(Z_Param_FriendUsername);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestRemoveFriend ***********************

// ********** Begin Class ADMFMMOPlayerController Function RequestRemoveGuildMember ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestRemoveGuildMember_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestRemoveGuildMember_Parms
	{
		FString MemberUsername;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Guild" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MemberUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestRemoveGuildMember constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_MemberUsername;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestRemoveGuildMember constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestRemoveGuildMember Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_MemberUsername = { "MemberUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestRemoveGuildMember_Parms, MemberUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MemberUsername_MetaData), NewProp_MemberUsername_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MemberUsername,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestRemoveGuildMember Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestRemoveGuildMember", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestRemoveGuildMember_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestRemoveGuildMember_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestRemoveGuildMember(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestRemoveGuildMember)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_MemberUsername);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestRemoveGuildMember(Z_Param_MemberUsername);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestRemoveGuildMember ******************

// ********** Begin Class ADMFMMOPlayerController Function RequestRemoveIgnoredPlayer **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestRemoveIgnoredPlayer_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestRemoveIgnoredPlayer_Parms
	{
		FString TargetUsername;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Ignore" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestRemoveIgnoredPlayer constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetUsername;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestRemoveIgnoredPlayer constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestRemoveIgnoredPlayer Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetUsername = { "TargetUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestRemoveIgnoredPlayer_Parms, TargetUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetUsername_MetaData), NewProp_TargetUsername_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetUsername,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestRemoveIgnoredPlayer Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestRemoveIgnoredPlayer", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestRemoveIgnoredPlayer_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestRemoveIgnoredPlayer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestRemoveIgnoredPlayer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestRemoveIgnoredPlayer)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetUsername);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestRemoveIgnoredPlayer(Z_Param_TargetUsername);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestRemoveIgnoredPlayer ****************

// ********** Begin Class ADMFMMOPlayerController Function RequestRenameGuild **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestRenameGuild_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestRenameGuild_Parms
	{
		FString GuildName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Guild" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuildName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestRenameGuild constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_GuildName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestRenameGuild constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestRenameGuild Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_GuildName = { "GuildName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestRenameGuild_Parms, GuildName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuildName_MetaData), NewProp_GuildName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GuildName,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestRenameGuild Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestRenameGuild", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestRenameGuild_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestRenameGuild_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestRenameGuild(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestRenameGuild)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_GuildName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestRenameGuild(Z_Param_GuildName);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestRenameGuild ************************

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

// ********** Begin Class ADMFMMOPlayerController Function RequestSetFriendTracking ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestSetFriendTracking_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRequestSetFriendTracking_Parms
	{
		FString FriendUsername;
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friends" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestSetFriendTracking constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FriendUsername;
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventRequestSetFriendTracking_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestSetFriendTracking constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestSetFriendTracking Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FriendUsername = { "FriendUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRequestSetFriendTracking_Parms, FriendUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendUsername_MetaData), NewProp_FriendUsername_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventRequestSetFriendTracking_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FriendUsername,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestSetFriendTracking Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestSetFriendTracking", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRequestSetFriendTracking_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRequestSetFriendTracking_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestSetFriendTracking(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestSetFriendTracking)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FriendUsername);
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestSetFriendTracking(Z_Param_FriendUsername,Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestSetFriendTracking ******************

// ********** Begin Class ADMFMMOPlayerController Function RequestSocialSnapshot *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RequestSocialSnapshot_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Requests the authoritative owner-only Social snapshot. Safe to call when opening/reskinning the Social tab. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Requests the authoritative owner-only Social snapshot. Safe to call when opening/reskinning the Social tab." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestSocialSnapshot constinit property declarations *****************
// ********** End Function RequestSocialSnapshot constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RequestSocialSnapshot", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RequestSocialSnapshot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRequestSocialSnapshot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestSocialSnapshot();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RequestSocialSnapshot *********************

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

// ********** Begin Class ADMFMMOPlayerController Function RespondToFriendRequest ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RespondToFriendRequest_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRespondToFriendRequest_Parms
	{
		FString RequesterUsername;
		bool bAccept;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friends" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequesterUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RespondToFriendRequest constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RequesterUsername;
	static void NewProp_bAccept_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventRespondToFriendRequest_Parms*)Obj)->bAccept = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAccept;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RespondToFriendRequest constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RespondToFriendRequest Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_RequesterUsername = { "RequesterUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRespondToFriendRequest_Parms, RequesterUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequesterUsername_MetaData), NewProp_RequesterUsername_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAccept = { "bAccept", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventRespondToFriendRequest_Parms), &UHT_STATICS::NewProp_bAccept_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RequesterUsername,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAccept,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RespondToFriendRequest Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RespondToFriendRequest", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRespondToFriendRequest_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRespondToFriendRequest_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RespondToFriendRequest(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRespondToFriendRequest)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_RequesterUsername);
	P_GET_UBOOL(Z_Param_bAccept);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RespondToFriendRequest(Z_Param_RequesterUsername,Z_Param_bAccept);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RespondToFriendRequest ********************

// ********** Begin Class ADMFMMOPlayerController Function RespondToGuildApplication ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RespondToGuildApplication_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRespondToGuildApplication_Parms
	{
		FString ApplicantUsername;
		bool bAccept;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Guild" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplicantUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RespondToGuildApplication constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ApplicantUsername;
	static void NewProp_bAccept_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventRespondToGuildApplication_Parms*)Obj)->bAccept = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAccept;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RespondToGuildApplication constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RespondToGuildApplication Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ApplicantUsername = { "ApplicantUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRespondToGuildApplication_Parms, ApplicantUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplicantUsername_MetaData), NewProp_ApplicantUsername_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAccept = { "bAccept", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventRespondToGuildApplication_Parms), &UHT_STATICS::NewProp_bAccept_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ApplicantUsername,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAccept,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RespondToGuildApplication Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RespondToGuildApplication", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRespondToGuildApplication_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRespondToGuildApplication_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RespondToGuildApplication(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRespondToGuildApplication)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ApplicantUsername);
	P_GET_UBOOL(Z_Param_bAccept);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RespondToGuildApplication(Z_Param_ApplicantUsername,Z_Param_bAccept);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RespondToGuildApplication *****************

// ********** Begin Class ADMFMMOPlayerController Function RespondToGuildInvite ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_RespondToGuildInvite_Statics
struct UHT_STATICS
{
	struct DMFMMOPlayerController_eventRespondToGuildInvite_Parms
	{
		FGuid GuildId;
		bool bAccept;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Guild" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RespondToGuildInvite constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_GuildId;
	static void NewProp_bAccept_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventRespondToGuildInvite_Parms*)Obj)->bAccept = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAccept;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RespondToGuildInvite constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RespondToGuildInvite Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_GuildId = { "GuildId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventRespondToGuildInvite_Parms, GuildId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bAccept = { "bAccept", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventRespondToGuildInvite_Parms), &UHT_STATICS::NewProp_bAccept_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GuildId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bAccept,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RespondToGuildInvite Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "RespondToGuildInvite", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOPlayerController_eventRespondToGuildInvite_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOPlayerController_eventRespondToGuildInvite_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_RespondToGuildInvite(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execRespondToGuildInvite)
{
	P_GET_STRUCT(FGuid,Z_Param_GuildId);
	P_GET_UBOOL(Z_Param_bAccept);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RespondToGuildInvite(Z_Param_GuildId,Z_Param_bAccept);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function RespondToGuildInvite **********************

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

// ********** Begin Class ADMFMMOPlayerController Function ServerExecuteSocialAction ***************
struct DMFMMOPlayerController_eventServerExecuteSocialAction_Parms
{
	EDMFSocialActionType ActionType;
	FString SubjectUsername;
	FGuid GuildId;
	FString TextValue;
	bool bValue;
};
static FName NAME_ADMFMMOPlayerController_ServerExecuteSocialAction = FName(TEXT("ServerExecuteSocialAction"));
void ADMFMMOPlayerController::ServerExecuteSocialAction(EDMFSocialActionType ActionType, const FString& SubjectUsername, FGuid GuildId, const FString& TextValue, bool bValue)
{
	DMFMMOPlayerController_eventServerExecuteSocialAction_Parms Parms;
	Parms.ActionType=ActionType;
	Parms.SubjectUsername=SubjectUsername;
	Parms.GuildId=GuildId;
	Parms.TextValue=TextValue;
	Parms.bValue=bValue ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ServerExecuteSocialAction);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ServerExecuteSocialAction_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** One validated transport RPC keeps the Social mutation surface compact while public wrappers remain strongly named. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "One validated transport RPC keeps the Social mutation surface compact while public wrappers remain strongly named." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubjectUsername_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerExecuteSocialAction constinit property declarations *************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ActionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ActionType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SubjectUsername;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GuildId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TextValue;
	static void NewProp_bValue_SetBit(void* Obj)
	{
		((DMFMMOPlayerController_eventServerExecuteSocialAction_Parms*)Obj)->bValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ServerExecuteSocialAction constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ServerExecuteSocialAction Property Definitions ************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ActionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ActionType = { "ActionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerExecuteSocialAction_Parms, ActionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialActionType, METADATA_PARAMS(0, nullptr) }; // 78d1b7a1f2f66e4fa9da9380e56013f59d156bb3
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SubjectUsername = { "SubjectUsername", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerExecuteSocialAction_Parms, SubjectUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubjectUsername_MetaData), NewProp_SubjectUsername_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_GuildId = { "GuildId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerExecuteSocialAction_Parms, GuildId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TextValue = { "TextValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerExecuteSocialAction_Parms, TextValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextValue_MetaData), NewProp_TextValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOPlayerController_eventServerExecuteSocialAction_Parms), &UHT_STATICS::NewProp_bValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SubjectUsername,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GuildId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TextValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ServerExecuteSocialAction Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ServerExecuteSocialAction", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventServerExecuteSocialAction_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A20CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventServerExecuteSocialAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ServerExecuteSocialAction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execServerExecuteSocialAction)
{
	P_GET_ENUM(EDMFSocialActionType,Z_Param_ActionType);
	P_GET_PROPERTY(FStrProperty,Z_Param_SubjectUsername);
	P_GET_STRUCT(FGuid,Z_Param_GuildId);
	P_GET_PROPERTY(FStrProperty,Z_Param_TextValue);
	P_GET_UBOOL(Z_Param_bValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerExecuteSocialAction_Implementation(EDMFSocialActionType(Z_Param_ActionType),Z_Param_SubjectUsername,Z_Param_GuildId,Z_Param_TextValue,Z_Param_bValue);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ServerExecuteSocialAction *****************

// ********** Begin Class ADMFMMOPlayerController Function ServerRequestDigimonVendorTransaction ***
struct DMFMMOPlayerController_eventServerRequestDigimonVendorTransaction_Parms
{
	ADMFDigimonVendorActor* Vendor;
	EDMFDigimonVendorTransactionType TransactionType;
	FGuid Identifier;
};
static FName NAME_ADMFMMOPlayerController_ServerRequestDigimonVendorTransaction = FName(TEXT("ServerRequestDigimonVendorTransaction"));
void ADMFMMOPlayerController::ServerRequestDigimonVendorTransaction(ADMFDigimonVendorActor* Vendor, EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier)
{
	DMFMMOPlayerController_eventServerRequestDigimonVendorTransaction_Parms Parms;
	Parms.Vendor=Vendor;
	Parms.TransactionType=TransactionType;
	Parms.Identifier=Identifier;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ServerRequestDigimonVendorTransaction);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestDigimonVendorTransaction_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerRequestDigimonVendorTransaction constinit property declarations *
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Vendor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Identifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ServerRequestDigimonVendorTransaction constinit property declarations ***
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ServerRequestDigimonVendorTransaction Property Definitions ************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Vendor = { "Vendor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerRequestDigimonVendorTransaction_Parms, Vendor), Z_Construct_UClass_ADMFDigimonVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerRequestDigimonVendorTransaction_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerRequestDigimonVendorTransaction_Parms, Identifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Vendor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Identifier,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ServerRequestDigimonVendorTransaction Property Definitions **************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ServerRequestDigimonVendorTransaction", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventServerRequestDigimonVendorTransaction_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A20CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventServerRequestDigimonVendorTransaction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestDigimonVendorTransaction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execServerRequestDigimonVendorTransaction)
{
	P_GET_OBJECT(ADMFDigimonVendorActor,Z_Param_Vendor);
	P_GET_ENUM(EDMFDigimonVendorTransactionType,Z_Param_TransactionType);
	P_GET_STRUCT(FGuid,Z_Param_Identifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRequestDigimonVendorTransaction_Implementation(Z_Param_Vendor,EDMFDigimonVendorTransactionType(Z_Param_TransactionType),Z_Param_Identifier);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ServerRequestDigimonVendorTransaction *****

// ********** Begin Class ADMFMMOPlayerController Function ServerRequestItemVendorTransaction ******
struct DMFMMOPlayerController_eventServerRequestItemVendorTransaction_Parms
{
	ADMFItemVendorActor* Vendor;
	EDMFItemVendorTransactionType TransactionType;
	FGuid StockId;
	FPrimaryAssetId ItemAssetId;
	int32 Quantity;
};
static FName NAME_ADMFMMOPlayerController_ServerRequestItemVendorTransaction = FName(TEXT("ServerRequestItemVendorTransaction"));
void ADMFMMOPlayerController::ServerRequestItemVendorTransaction(ADMFItemVendorActor* Vendor, EDMFItemVendorTransactionType TransactionType, FGuid StockId, FPrimaryAssetId ItemAssetId, int32 Quantity)
{
	DMFMMOPlayerController_eventServerRequestItemVendorTransaction_Parms Parms;
	Parms.Vendor=Vendor;
	Parms.TransactionType=TransactionType;
	Parms.StockId=StockId;
	Parms.ItemAssetId=ItemAssetId;
	Parms.Quantity=Quantity;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ServerRequestItemVendorTransaction);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestItemVendorTransaction_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerRequestItemVendorTransaction constinit property declarations ****
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Vendor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StockId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ServerRequestItemVendorTransaction constinit property declarations ******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ServerRequestItemVendorTransaction Property Definitions ***************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Vendor = { "Vendor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerRequestItemVendorTransaction_Parms, Vendor), Z_Construct_UClass_ADMFItemVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerRequestItemVendorTransaction_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StockId = { "StockId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerRequestItemVendorTransaction_Parms, StockId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerRequestItemVendorTransaction_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOPlayerController_eventServerRequestItemVendorTransaction_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Vendor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Quantity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ServerRequestItemVendorTransaction Property Definitions *****************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ServerRequestItemVendorTransaction", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOPlayerController_eventServerRequestItemVendorTransaction_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A20CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOPlayerController_eventServerRequestItemVendorTransaction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestItemVendorTransaction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execServerRequestItemVendorTransaction)
{
	P_GET_OBJECT(ADMFItemVendorActor,Z_Param_Vendor);
	P_GET_ENUM(EDMFItemVendorTransactionType,Z_Param_TransactionType);
	P_GET_STRUCT(FGuid,Z_Param_StockId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_ItemAssetId);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRequestItemVendorTransaction_Implementation(Z_Param_Vendor,EDMFItemVendorTransactionType(Z_Param_TransactionType),Z_Param_StockId,Z_Param_ItemAssetId,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ServerRequestItemVendorTransaction ********

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

// ********** Begin Class ADMFMMOPlayerController Function ServerRequestSocialSnapshot *************
static FName NAME_ADMFMMOPlayerController_ServerRequestSocialSnapshot = FName(TEXT("ServerRequestSocialSnapshot"));
void ADMFMMOPlayerController::ServerRequestSocialSnapshot()
{
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOPlayerController_ServerRequestSocialSnapshot);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestSocialSnapshot_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerRequestSocialSnapshot constinit property declarations ***********
// ********** End Function ServerRequestSocialSnapshot constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOPlayerController, nullptr, "ServerRequestSocialSnapshot", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestSocialSnapshot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOPlayerController::execServerRequestSocialSnapshot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRequestSocialSnapshot_Implementation();
	P_NATIVE_END;
}
// ********** End Class ADMFMMOPlayerController Function ServerRequestSocialSnapshot ***************

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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSocialSnapshotChanged_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSocialActionResult_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDigimonVendorTransactionResult_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnItemVendorTransactionResult_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DigimonVendorWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveDigimonVendor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemVendorWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveItemVendor_MetaData[] = {
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSocialContextWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedSocialSnapshot_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Last owner-only server snapshot. Social state is intentionally not public PlayerState replication. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Last owner-only server snapshot. Social state is intentionally not public PlayerState replication." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendTrackerComponents_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Client-only components attached to currently online tracked friends; keys are lowercase usernames. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client-only components attached to currently online tracked friends; keys are lowercase usernames." },
#endif
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
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSocialSnapshotChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSocialActionResult;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDigimonVendorTransactionResult;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemVendorTransactionResult;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StarterWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CombatQuickBarWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PartyQuickBarWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerSkinWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonInventoryWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonVendorWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveDigimonVendor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemVendorWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveItemVendor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanNotificationWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExperienceNotificationWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HomeTeleportNotificationWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldChatWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerSocialContextWidget;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedSocialSnapshot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FriendTrackerComponents_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FriendTrackerComponents_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_FriendTrackerComponents;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetingPresentationActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFMMOPlayerController constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ClientDigimonVendorTransactionResult"), .Pointer = &ADMFMMOPlayerController::execClientDigimonVendorTransactionResult },
		{ .NameUTF8 = UTF8TEXT("ClientHealerInteractionResult"), .Pointer = &ADMFMMOPlayerController::execClientHealerInteractionResult },
		{ .NameUTF8 = UTF8TEXT("ClientItemVendorTransactionResult"), .Pointer = &ADMFMMOPlayerController::execClientItemVendorTransactionResult },
		{ .NameUTF8 = UTF8TEXT("ClientReceiveSocialSnapshot"), .Pointer = &ADMFMMOPlayerController::execClientReceiveSocialSnapshot },
		{ .NameUTF8 = UTF8TEXT("ClientReceiveWorldChatHistory"), .Pointer = &ADMFMMOPlayerController::execClientReceiveWorldChatHistory },
		{ .NameUTF8 = UTF8TEXT("ClientReceiveWorldChatMessage"), .Pointer = &ADMFMMOPlayerController::execClientReceiveWorldChatMessage },
		{ .NameUTF8 = UTF8TEXT("ClientReturnHomeResult"), .Pointer = &ADMFMMOPlayerController::execClientReturnHomeResult },
		{ .NameUTF8 = UTF8TEXT("ClientSocialActionResult"), .Pointer = &ADMFMMOPlayerController::execClientSocialActionResult },
		{ .NameUTF8 = UTF8TEXT("ClientWorldChatSendRejected"), .Pointer = &ADMFMMOPlayerController::execClientWorldChatSendRejected },
		{ .NameUTF8 = UTF8TEXT("CloseDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execCloseDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("CloseDigimonMenuUI"), .Pointer = &ADMFMMOPlayerController::execCloseDigimonMenuUI },
		{ .NameUTF8 = UTF8TEXT("CloseDigimonVendorUI"), .Pointer = &ADMFMMOPlayerController::execCloseDigimonVendorUI },
		{ .NameUTF8 = UTF8TEXT("CloseItemVendorUI"), .Pointer = &ADMFMMOPlayerController::execCloseItemVendorUI },
		{ .NameUTF8 = UTF8TEXT("ClosePartyQuickAccessInteraction"), .Pointer = &ADMFMMOPlayerController::execClosePartyQuickAccessInteraction },
		{ .NameUTF8 = UTF8TEXT("ClosePlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execClosePlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("ClosePlayerSocialContextUI"), .Pointer = &ADMFMMOPlayerController::execClosePlayerSocialContextUI },
		{ .NameUTF8 = UTF8TEXT("CloseWorldChatInput"), .Pointer = &ADMFMMOPlayerController::execCloseWorldChatInput },
		{ .NameUTF8 = UTF8TEXT("CommandActivePartnerAbilitySlot"), .Pointer = &ADMFMMOPlayerController::execCommandActivePartnerAbilitySlot },
		{ .NameUTF8 = UTF8TEXT("CommandPartnerTargetAndAttack"), .Pointer = &ADMFMMOPlayerController::execCommandPartnerTargetAndAttack },
		{ .NameUTF8 = UTF8TEXT("GetActiveDigimonVendor"), .Pointer = &ADMFMMOPlayerController::execGetActiveDigimonVendor },
		{ .NameUTF8 = UTF8TEXT("GetActiveItemVendor"), .Pointer = &ADMFMMOPlayerController::execGetActiveItemVendor },
		{ .NameUTF8 = UTF8TEXT("GetCachedSocialSnapshot"), .Pointer = &ADMFMMOPlayerController::execGetCachedSocialSnapshot },
		{ .NameUTF8 = UTF8TEXT("GetNearbySocialPlayers"), .Pointer = &ADMFMMOPlayerController::execGetNearbySocialPlayers },
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
		{ .NameUTF8 = UTF8TEXT("IsDigimonVendorUIOpen"), .Pointer = &ADMFMMOPlayerController::execIsDigimonVendorUIOpen },
		{ .NameUTF8 = UTF8TEXT("IsDigivolutionPresentationActive"), .Pointer = &ADMFMMOPlayerController::execIsDigivolutionPresentationActive },
		{ .NameUTF8 = UTF8TEXT("IsFrameworkPlayerAvatarPossessed"), .Pointer = &ADMFMMOPlayerController::execIsFrameworkPlayerAvatarPossessed },
		{ .NameUTF8 = UTF8TEXT("IsItemVendorUIOpen"), .Pointer = &ADMFMMOPlayerController::execIsItemVendorUIOpen },
		{ .NameUTF8 = UTF8TEXT("IsPartyQuickAccessInteractionActive"), .Pointer = &ADMFMMOPlayerController::execIsPartyQuickAccessInteractionActive },
		{ .NameUTF8 = UTF8TEXT("IsPlayerSkinSelectionUIOpen"), .Pointer = &ADMFMMOPlayerController::execIsPlayerSkinSelectionUIOpen },
		{ .NameUTF8 = UTF8TEXT("IsWorldChatInputActive"), .Pointer = &ADMFMMOPlayerController::execIsWorldChatInputActive },
		{ .NameUTF8 = UTF8TEXT("OpenBankUI"), .Pointer = &ADMFMMOPlayerController::execOpenBankUI },
		{ .NameUTF8 = UTF8TEXT("OpenCareUI"), .Pointer = &ADMFMMOPlayerController::execOpenCareUI },
		{ .NameUTF8 = UTF8TEXT("OpenDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execOpenDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("OpenDigimonMenuUI"), .Pointer = &ADMFMMOPlayerController::execOpenDigimonMenuUI },
		{ .NameUTF8 = UTF8TEXT("OpenDigimonVendorUI"), .Pointer = &ADMFMMOPlayerController::execOpenDigimonVendorUI },
		{ .NameUTF8 = UTF8TEXT("OpenDigivolutionUI"), .Pointer = &ADMFMMOPlayerController::execOpenDigivolutionUI },
		{ .NameUTF8 = UTF8TEXT("OpenItemsUI"), .Pointer = &ADMFMMOPlayerController::execOpenItemsUI },
		{ .NameUTF8 = UTF8TEXT("OpenItemVendorUI"), .Pointer = &ADMFMMOPlayerController::execOpenItemVendorUI },
		{ .NameUTF8 = UTF8TEXT("OpenPartyQuickAccessInteraction"), .Pointer = &ADMFMMOPlayerController::execOpenPartyQuickAccessInteraction },
		{ .NameUTF8 = UTF8TEXT("OpenPartyUI"), .Pointer = &ADMFMMOPlayerController::execOpenPartyUI },
		{ .NameUTF8 = UTF8TEXT("OpenPlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execOpenPlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("OpenPlayerSocialContext"), .Pointer = &ADMFMMOPlayerController::execOpenPlayerSocialContext },
		{ .NameUTF8 = UTF8TEXT("OpenScanMaterializeUI"), .Pointer = &ADMFMMOPlayerController::execOpenScanMaterializeUI },
		{ .NameUTF8 = UTF8TEXT("OpenSocialUI"), .Pointer = &ADMFMMOPlayerController::execOpenSocialUI },
		{ .NameUTF8 = UTF8TEXT("OpenWorldChatInput"), .Pointer = &ADMFMMOPlayerController::execOpenWorldChatInput },
		{ .NameUTF8 = UTF8TEXT("RefreshCombatQuickBar"), .Pointer = &ADMFMMOPlayerController::execRefreshCombatQuickBar },
		{ .NameUTF8 = UTF8TEXT("RefreshDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execRefreshDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("RefreshDigimonVendorUI"), .Pointer = &ADMFMMOPlayerController::execRefreshDigimonVendorUI },
		{ .NameUTF8 = UTF8TEXT("RefreshFriendTrackingPresentation"), .Pointer = &ADMFMMOPlayerController::execRefreshFriendTrackingPresentation },
		{ .NameUTF8 = UTF8TEXT("RefreshItemVendorUI"), .Pointer = &ADMFMMOPlayerController::execRefreshItemVendorUI },
		{ .NameUTF8 = UTF8TEXT("RefreshPartyQuickBar"), .Pointer = &ADMFMMOPlayerController::execRefreshPartyQuickBar },
		{ .NameUTF8 = UTF8TEXT("RefreshPlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execRefreshPlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("RefreshStarterSelectionUI"), .Pointer = &ADMFMMOPlayerController::execRefreshStarterSelectionUI },
		{ .NameUTF8 = UTF8TEXT("RefreshTargetingVisuals"), .Pointer = &ADMFMMOPlayerController::execRefreshTargetingVisuals },
		{ .NameUTF8 = UTF8TEXT("RefreshWorldChatUI"), .Pointer = &ADMFMMOPlayerController::execRefreshWorldChatUI },
		{ .NameUTF8 = UTF8TEXT("RequestAddFriend"), .Pointer = &ADMFMMOPlayerController::execRequestAddFriend },
		{ .NameUTF8 = UTF8TEXT("RequestApplyToGuild"), .Pointer = &ADMFMMOPlayerController::execRequestApplyToGuild },
		{ .NameUTF8 = UTF8TEXT("RequestCancelFriendRequest"), .Pointer = &ADMFMMOPlayerController::execRequestCancelFriendRequest },
		{ .NameUTF8 = UTF8TEXT("RequestCreateGuild"), .Pointer = &ADMFMMOPlayerController::execRequestCreateGuild },
		{ .NameUTF8 = UTF8TEXT("RequestDigimonVendorTransaction"), .Pointer = &ADMFMMOPlayerController::execRequestDigimonVendorTransaction },
		{ .NameUTF8 = UTF8TEXT("RequestDisbandGuild"), .Pointer = &ADMFMMOPlayerController::execRequestDisbandGuild },
		{ .NameUTF8 = UTF8TEXT("RequestIgnorePlayer"), .Pointer = &ADMFMMOPlayerController::execRequestIgnorePlayer },
		{ .NameUTF8 = UTF8TEXT("RequestInvitePlayerToGuild"), .Pointer = &ADMFMMOPlayerController::execRequestInvitePlayerToGuild },
		{ .NameUTF8 = UTF8TEXT("RequestItemVendorTransaction"), .Pointer = &ADMFMMOPlayerController::execRequestItemVendorTransaction },
		{ .NameUTF8 = UTF8TEXT("RequestLeaveGuild"), .Pointer = &ADMFMMOPlayerController::execRequestLeaveGuild },
		{ .NameUTF8 = UTF8TEXT("RequestRemoveFriend"), .Pointer = &ADMFMMOPlayerController::execRequestRemoveFriend },
		{ .NameUTF8 = UTF8TEXT("RequestRemoveGuildMember"), .Pointer = &ADMFMMOPlayerController::execRequestRemoveGuildMember },
		{ .NameUTF8 = UTF8TEXT("RequestRemoveIgnoredPlayer"), .Pointer = &ADMFMMOPlayerController::execRequestRemoveIgnoredPlayer },
		{ .NameUTF8 = UTF8TEXT("RequestRenameGuild"), .Pointer = &ADMFMMOPlayerController::execRequestRenameGuild },
		{ .NameUTF8 = UTF8TEXT("RequestReturnHome"), .Pointer = &ADMFMMOPlayerController::execRequestReturnHome },
		{ .NameUTF8 = UTF8TEXT("RequestSetFriendTracking"), .Pointer = &ADMFMMOPlayerController::execRequestSetFriendTracking },
		{ .NameUTF8 = UTF8TEXT("RequestSocialSnapshot"), .Pointer = &ADMFMMOPlayerController::execRequestSocialSnapshot },
		{ .NameUTF8 = UTF8TEXT("RequestUseHealer"), .Pointer = &ADMFMMOPlayerController::execRequestUseHealer },
		{ .NameUTF8 = UTF8TEXT("RespondToFriendRequest"), .Pointer = &ADMFMMOPlayerController::execRespondToFriendRequest },
		{ .NameUTF8 = UTF8TEXT("RespondToGuildApplication"), .Pointer = &ADMFMMOPlayerController::execRespondToGuildApplication },
		{ .NameUTF8 = UTF8TEXT("RespondToGuildInvite"), .Pointer = &ADMFMMOPlayerController::execRespondToGuildInvite },
		{ .NameUTF8 = UTF8TEXT("SelectDigimonCommandTargetUnderCursor"), .Pointer = &ADMFMMOPlayerController::execSelectDigimonCommandTargetUnderCursor },
		{ .NameUTF8 = UTF8TEXT("SendWorldChatMessage"), .Pointer = &ADMFMMOPlayerController::execSendWorldChatMessage },
		{ .NameUTF8 = UTF8TEXT("ServerEnsureFrameworkPlayerAvatar"), .Pointer = &ADMFMMOPlayerController::execServerEnsureFrameworkPlayerAvatar },
		{ .NameUTF8 = UTF8TEXT("ServerExecuteSocialAction"), .Pointer = &ADMFMMOPlayerController::execServerExecuteSocialAction },
		{ .NameUTF8 = UTF8TEXT("ServerRequestDigimonVendorTransaction"), .Pointer = &ADMFMMOPlayerController::execServerRequestDigimonVendorTransaction },
		{ .NameUTF8 = UTF8TEXT("ServerRequestItemVendorTransaction"), .Pointer = &ADMFMMOPlayerController::execServerRequestItemVendorTransaction },
		{ .NameUTF8 = UTF8TEXT("ServerRequestReturnHome"), .Pointer = &ADMFMMOPlayerController::execServerRequestReturnHome },
		{ .NameUTF8 = UTF8TEXT("ServerRequestSocialSnapshot"), .Pointer = &ADMFMMOPlayerController::execServerRequestSocialSnapshot },
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
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientDigimonVendorTransactionResult, "ClientDigimonVendorTransactionResult" }, // 8d96dbfef83e61721b7003b7c3a5dadfb6073fb4
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientHealerInteractionResult, "ClientHealerInteractionResult" }, // fd0bd79f47752d4aeb3d61f8889502552ad8dfd2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientItemVendorTransactionResult, "ClientItemVendorTransactionResult" }, // 5e65f0dde6aa9cedafae4718e268cc8374f2cfe2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveSocialSnapshot, "ClientReceiveSocialSnapshot" }, // 30456564dcc5b64ee7d1023c7e0f41ea221359b6
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveWorldChatHistory, "ClientReceiveWorldChatHistory" }, // 481adb314c36a01ef2bbe7987b5fd35b3633744d
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientReceiveWorldChatMessage, "ClientReceiveWorldChatMessage" }, // e5dc158b8d2dc5069fd5cf31d0673ae4754ddec7
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientReturnHomeResult, "ClientReturnHomeResult" }, // 912c5177039d04dd476918dbeb5b7bbe1765a362
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientSocialActionResult, "ClientSocialActionResult" }, // 8ad695d4cad30d6398d87b10bc44fb82e208e107
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientWorldChatSendRejected, "ClientWorldChatSendRejected" }, // fe92f9e1dfd43bc01b0516e4be75a84702aa5424
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonInventoryUI, "CloseDigimonInventoryUI" }, // 9bdf8979d95ee2d0690ca274ebd92aeebb491e59
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonMenuUI, "CloseDigimonMenuUI" }, // 2d4c0431c81fb1351a38ec9b84d9cdca2104fc31
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonVendorUI, "CloseDigimonVendorUI" }, // 2855f54d733dbc574136309c074d2819ff71446f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseItemVendorUI, "CloseItemVendorUI" }, // b2fccca584f85c89f02f417c6b1a1639c7046b0d
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClosePartyQuickAccessInteraction, "ClosePartyQuickAccessInteraction" }, // 7e9ac10edacaeb3e4890cd5d0ab7eecc582d7532
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClosePlayerSkinSelectionUI, "ClosePlayerSkinSelectionUI" }, // aea3717f1069c904491fb40ceb6a641c4744099b
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClosePlayerSocialContextUI, "ClosePlayerSocialContextUI" }, // 798ec9fe13bbec7e18ae995e334ed838d33fb92d
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseWorldChatInput, "CloseWorldChatInput" }, // adcedc494f95685c5079b99a417855a026a22121
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CommandActivePartnerAbilitySlot, "CommandActivePartnerAbilitySlot" }, // 23e8ffa3a886714910a4020728670525fc575c67
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CommandPartnerTargetAndAttack, "CommandPartnerTargetAndAttack" }, // 29f86ad7ebe90c83566ec078666ff7b3fed62be5
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_GetActiveDigimonVendor, "GetActiveDigimonVendor" }, // 40f3556486198bd29b4fac15990c2e92125e4a73
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_GetActiveItemVendor, "GetActiveItemVendor" }, // 35fd0f248e978d1e66f4a281a9e500e533588e2c
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_GetCachedSocialSnapshot, "GetCachedSocialSnapshot" }, // 48a6ae22a383730c1461885b6e39df8eb879a3fe
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_GetNearbySocialPlayers, "GetNearbySocialPlayers" }, // 467e77bcb25daefbe8501cffa6c554f1d7dc529a
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
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonVendorUIOpen, "IsDigimonVendorUIOpen" }, // 3b1e77e95099bcd609fb46f0120fd1ad60a08db7
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsDigivolutionPresentationActive, "IsDigivolutionPresentationActive" }, // caf79b441580fa1797a22e49fa278d4b26b1d5e1
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsFrameworkPlayerAvatarPossessed, "IsFrameworkPlayerAvatarPossessed" }, // 137e1d5c5a9b74264ed1d4818e7daa146901353f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsItemVendorUIOpen, "IsItemVendorUIOpen" }, // 0c7eeba92896710fbaf457f8e14b0c298cacb9f3
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsPartyQuickAccessInteractionActive, "IsPartyQuickAccessInteractionActive" }, // bdaee1622d563d8bf327794fc948c4307f5eb54f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsPlayerSkinSelectionUIOpen, "IsPlayerSkinSelectionUIOpen" }, // 1dff57173550fa8c99970326a60d43d1f9750f57
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsWorldChatInputActive, "IsWorldChatInputActive" }, // 18b449baf58622a8bfb58d9b7d2c6bea168c2d7b
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenBankUI, "OpenBankUI" }, // 44a801ff5192e40ab547959e8bcf6bad7b49a6c2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenCareUI, "OpenCareUI" }, // 4dbc31bd7c13010e3254b6d69f91cd5480fb52f2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonInventoryUI, "OpenDigimonInventoryUI" }, // 3947e5ecc7643b8a10541f4dc0cb64fdc929fe37
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonMenuUI, "OpenDigimonMenuUI" }, // 787480e966b131e71ec312ab075f06312bab1600
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonVendorUI, "OpenDigimonVendorUI" }, // 5655705e1faf5427451aeab2d046847e92d1ea05
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigivolutionUI, "OpenDigivolutionUI" }, // 6411f92a2d004bb4eea0ffdb9a5eca1db9b210fe
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenItemsUI, "OpenItemsUI" }, // b795ad32cf2485e0d6b58f0251b17cfac93fd15c
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenItemVendorUI, "OpenItemVendorUI" }, // dee70c20e466f2d680bcc636d82bc584d05b9113
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenPartyQuickAccessInteraction, "OpenPartyQuickAccessInteraction" }, // 4fa78b4a8cc9ecb28451bd69f43c6fe9dac2a7e0
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenPartyUI, "OpenPartyUI" }, // b78a5dde0f669370c4a793d5dc3199c7bf16f888
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenPlayerSkinSelectionUI, "OpenPlayerSkinSelectionUI" }, // d2bef495faf2ebf66a36702e48fbd948f57318c2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenPlayerSocialContext, "OpenPlayerSocialContext" }, // b2bc99a01010ed61698675fce9c263d1e6a28e1f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenScanMaterializeUI, "OpenScanMaterializeUI" }, // 76471492722ae85e4c2db7c6646ad7c0c4ae5980
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenSocialUI, "OpenSocialUI" }, // bb7e59a4c1c1e8ebd0fe2232c24f117abd851a14
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenWorldChatInput, "OpenWorldChatInput" }, // 7233eb813566faabfa52b52afa89630fe4ccb76d
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshCombatQuickBar, "RefreshCombatQuickBar" }, // 55dfa403a03ba1802f9cdfed6954fe8855a9a3c9
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshDigimonInventoryUI, "RefreshDigimonInventoryUI" }, // 2eb6bbbfb19e039f95fba79d2ad9df2b035f7d97
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshDigimonVendorUI, "RefreshDigimonVendorUI" }, // 8c964c9d0c2552b3f3e32337247b5728175153ce
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshFriendTrackingPresentation, "RefreshFriendTrackingPresentation" }, // 017e2a161ffc4219a6ad751aa90b5ec3682787b0
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshItemVendorUI, "RefreshItemVendorUI" }, // 73a4afb39a32501a06670d9ab5156fc31836ceaf
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshPartyQuickBar, "RefreshPartyQuickBar" }, // 26d49dc08a1e05ec8c762195c40ad5fe60d7fa72
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshPlayerSkinSelectionUI, "RefreshPlayerSkinSelectionUI" }, // 63c4b16d73d5d5b889759ffda68ec30442000bb2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshStarterSelectionUI, "RefreshStarterSelectionUI" }, // d7dbaa478809f0e8e263917c1869d4d1e4c66543
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshTargetingVisuals, "RefreshTargetingVisuals" }, // 0fb1a439a67c7035c806b41797a56c12ebcc01bb
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshWorldChatUI, "RefreshWorldChatUI" }, // c7bea9fe9f25e72e3aee0396d97947d4a2f4b521
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestAddFriend, "RequestAddFriend" }, // d2703795fb37a9ef196b0f38fb4c39fca3578ba5
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestApplyToGuild, "RequestApplyToGuild" }, // f4c522a0a3e3ebf81b5e75051ccbd369166e35a4
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestCancelFriendRequest, "RequestCancelFriendRequest" }, // 717f41eef8c4811d6a134c1e45a68358f83b5511
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestCreateGuild, "RequestCreateGuild" }, // ca7f8aab54f9ac9a2eca98cb943dc5dbd90c23cd
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestDigimonVendorTransaction, "RequestDigimonVendorTransaction" }, // 22bc23b38eb34a7b8ac7cc9ee4081766588e6cf0
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestDisbandGuild, "RequestDisbandGuild" }, // 1b96a2d3f6ac6ab9935b022c1434c14e36db4f8b
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestIgnorePlayer, "RequestIgnorePlayer" }, // 3cf624cc56157bdae93999ac51fb5c3c268fcd9a
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestInvitePlayerToGuild, "RequestInvitePlayerToGuild" }, // 7846d3fe43cad713b9878647f1e96a522b3ffa90
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestItemVendorTransaction, "RequestItemVendorTransaction" }, // be89f435333e5f34164ae3289c64786db5677e58
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestLeaveGuild, "RequestLeaveGuild" }, // 36dcce527addd5f79a8646a74dea85c1f2151c17
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestRemoveFriend, "RequestRemoveFriend" }, // 14d7397733bc9e0cea32a4c0ff48887d4056414f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestRemoveGuildMember, "RequestRemoveGuildMember" }, // 824f8d25bbf26aedd8083fab9ee1b419e86af65a
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestRemoveIgnoredPlayer, "RequestRemoveIgnoredPlayer" }, // 8d3b0267d0bc2a915159a2508a807de724d441c6
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestRenameGuild, "RequestRenameGuild" }, // db9460aab39b9c4027f28288c28295c3f8e76859
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestReturnHome, "RequestReturnHome" }, // 86d0e6ede7aa21feee2e8c6cba2dc0d9b6d03016
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestSetFriendTracking, "RequestSetFriendTracking" }, // b86dea6c0f3518617b96a8849e05d0114e8bbb41
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestSocialSnapshot, "RequestSocialSnapshot" }, // 6cfae4ecd4e691fd476a4649e1ba8e5424f2d26f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestUseHealer, "RequestUseHealer" }, // 8b7c978fd62e9a2fccc659796cd3dcecd42dd1c2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RespondToFriendRequest, "RespondToFriendRequest" }, // 3c1c7a1d9bc67b7721554af9d0d6a4d8ec58a5c2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RespondToGuildApplication, "RespondToGuildApplication" }, // 2e7981bc90d738e2ea682407e2dbefea0950f96d
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RespondToGuildInvite, "RespondToGuildInvite" }, // 0a3c1f4613e6864b64ea119d93cb3f8cff0d7849
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_SelectDigimonCommandTargetUnderCursor, "SelectDigimonCommandTargetUnderCursor" }, // b31362fed008ea36285bb10bd1c1e764c00c95d5
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_SendWorldChatMessage, "SendWorldChatMessage" }, // 19fa6a3f4e69b7ed2c5fc12f23b28dbf24932862
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerEnsureFrameworkPlayerAvatar, "ServerEnsureFrameworkPlayerAvatar" }, // 5547590643a8cd2b864d0724cf9d4aa59fd1d83f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerExecuteSocialAction, "ServerExecuteSocialAction" }, // 3b27ea155943feaac6ecc8a186c9ef3ca4ad6a9b
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestDigimonVendorTransaction, "ServerRequestDigimonVendorTransaction" }, // 6516f3adeae73bb2b7e36dd6de9699f0e865f7e0
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestItemVendorTransaction, "ServerRequestItemVendorTransaction" }, // 71996f69d37a2d4c76298f32b2d79c5420c1abe1
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestReturnHome, "ServerRequestReturnHome" }, // ac64724c915a6560e24a80c8a99a26f2b2aeb590
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestSocialSnapshot, "ServerRequestSocialSnapshot" }, // b2fb38f7679a187bf43a286de2071595cac7a2fc
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
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnWorldChatMessageReceived = { "OnWorldChatMessageReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, OnWorldChatMessageReceived), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFWorldChatMessageReceived__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnWorldChatMessageReceived_MetaData), NewProp_OnWorldChatMessageReceived_MetaData) }; // 8eb9e70b56806831351d4abdd77ddd37008344d8
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnSocialSnapshotChanged = { "OnSocialSnapshotChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, OnSocialSnapshotChanged), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialSnapshotChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSocialSnapshotChanged_MetaData), NewProp_OnSocialSnapshotChanged_MetaData) }; // be1ab12343856c2bceced01e013a45e87c803f3d
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnSocialActionResult = { "OnSocialActionResult", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, OnSocialActionResult), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialActionResult__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSocialActionResult_MetaData), NewProp_OnSocialActionResult_MetaData) }; // 6a36bac53dac065955957a295dbb1586edced3f4
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnDigimonVendorTransactionResult = { "OnDigimonVendorTransactionResult", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, OnDigimonVendorTransactionResult), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorTransactionResult__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDigimonVendorTransactionResult_MetaData), NewProp_OnDigimonVendorTransactionResult_MetaData) }; // a15751fae7c91e1b0be6573a26643bec28dea23d
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnItemVendorTransactionResult = { "OnItemVendorTransactionResult", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, OnItemVendorTransactionResult), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorTransactionResult__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnItemVendorTransactionResult_MetaData), NewProp_OnItemVendorTransactionResult_MetaData) }; // d512d5b5dbd33bcdfeb8e2ed65932ef5ea763560
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_StarterWidget = { "StarterWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, StarterWidget), Z_Construct_UClass_UDMFStarterSelectionWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarterWidget_MetaData), NewProp_StarterWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CombatQuickBarWidget = { "CombatQuickBarWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, CombatQuickBarWidget), Z_Construct_UClass_UDMFCombatQuickBarWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatQuickBarWidget_MetaData), NewProp_CombatQuickBarWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PartyQuickBarWidget = { "PartyQuickBarWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, PartyQuickBarWidget), Z_Construct_UClass_UDMFPartyQuickBarWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartyQuickBarWidget_MetaData), NewProp_PartyQuickBarWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerSkinWidget = { "PlayerSkinWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, PlayerSkinWidget), Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSkinWidget_MetaData), NewProp_PlayerSkinWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonInventoryWidget = { "DigimonInventoryWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, DigimonInventoryWidget), Z_Construct_UClass_UDMFDigimonInventoryWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonInventoryWidget_MetaData), NewProp_DigimonInventoryWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonVendorWidget = { "DigimonVendorWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, DigimonVendorWidget), Z_Construct_UClass_UDMFDigimonVendorWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonVendorWidget_MetaData), NewProp_DigimonVendorWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActiveDigimonVendor = { "ActiveDigimonVendor", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, ActiveDigimonVendor), Z_Construct_UClass_ADMFDigimonVendorActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveDigimonVendor_MetaData), NewProp_ActiveDigimonVendor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ItemVendorWidget = { "ItemVendorWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, ItemVendorWidget), Z_Construct_UClass_UDMFItemVendorWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemVendorWidget_MetaData), NewProp_ItemVendorWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActiveItemVendor = { "ActiveItemVendor", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, ActiveItemVendor), Z_Construct_UClass_ADMFItemVendorActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveItemVendor_MetaData), NewProp_ActiveItemVendor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanNotificationWidget = { "ScanNotificationWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, ScanNotificationWidget), Z_Construct_UClass_UDMFScanNotificationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanNotificationWidget_MetaData), NewProp_ScanNotificationWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ExperienceNotificationWidget = { "ExperienceNotificationWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, ExperienceNotificationWidget), Z_Construct_UClass_UDMFExperienceNotificationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperienceNotificationWidget_MetaData), NewProp_ExperienceNotificationWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_HomeTeleportNotificationWidget = { "HomeTeleportNotificationWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, HomeTeleportNotificationWidget), Z_Construct_UClass_UDMFHomeTeleportNotificationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HomeTeleportNotificationWidget_MetaData), NewProp_HomeTeleportNotificationWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WorldChatWidget = { "WorldChatWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, WorldChatWidget), Z_Construct_UClass_UDMFWorldChatWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldChatWidget_MetaData), NewProp_WorldChatWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerSocialContextWidget = { "PlayerSocialContextWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, PlayerSocialContextWidget), Z_Construct_UClass_UDMFPlayerSocialContextWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSocialContextWidget_MetaData), NewProp_PlayerSocialContextWidget_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_CachedSocialSnapshot = { "CachedSocialSnapshot", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, CachedSocialSnapshot), Z_Construct_UScriptStruct_FDMFSocialSnapshot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedSocialSnapshot_MetaData), NewProp_CachedSocialSnapshot_MetaData) }; // af2ade89cc42d87d03c8fc281787c2464eeda2af
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FriendTrackerComponents_ValueProp = { "FriendTrackerComponents", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 1, Z_Construct_UClass_UWidgetComponent, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FriendTrackerComponents_Key_KeyProp = { "FriendTrackerComponents_Key", nullptr, (EPropertyFlags)0x0100000000080008, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams UHT_STATICS::NewProp_FriendTrackerComponents = { "FriendTrackerComponents", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Map, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, FriendTrackerComponents), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendTrackerComponents_MetaData), NewProp_FriendTrackerComponents_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetingPresentationActor = { "TargetingPresentationActor", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, TargetingPresentationActor), Z_Construct_UClass_ADMFTargetingPresentationActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingPresentationActor_MetaData), NewProp_TargetingPresentationActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnHealerInteractionResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnHomeTeleportResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnWorldChatMessageReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnSocialSnapshotChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnSocialActionResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnDigimonVendorTransactionResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnItemVendorTransactionResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StarterWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatQuickBarWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartyQuickBarWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSkinWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInventoryWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonVendorWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActiveDigimonVendor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemVendorWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActiveItemVendor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanNotificationWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExperienceNotificationWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_HomeTeleportNotificationWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldChatWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSocialContextWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CachedSocialSnapshot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FriendTrackerComponents_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FriendTrackerComponents_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FriendTrackerComponents,
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
		{ Z_Construct_UClass_ADMFMMOPlayerController, TEXT("ADMFMMOPlayerController"), &Z_Registration_Info_UClass_ADMFMMOPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFMMOPlayerController), 931692889U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h__Script_DigimonMMOFramework_b9afdf42ac42c7408939d7881d41b2988959ecaa{
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
