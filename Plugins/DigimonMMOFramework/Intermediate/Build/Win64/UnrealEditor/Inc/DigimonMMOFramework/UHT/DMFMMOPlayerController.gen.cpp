// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFMMOPlayerController.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFMMOPlayerController() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_APlayerController(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHealerInteractionResult__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFCombatQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFHealerActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSkinSelectionWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFScanNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFStarterSelectionWidget(ETypeConstructPhase);
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarterWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatQuickBarWidget_MetaData[] = {
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
#endif // WITH_METADATA

// ********** Begin Class ADMFMMOPlayerController constinit property declarations ******************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHealerInteractionResult;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StarterWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CombatQuickBarWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerSkinWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DigimonInventoryWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanNotificationWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFMMOPlayerController constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ClientHealerInteractionResult"), .Pointer = &ADMFMMOPlayerController::execClientHealerInteractionResult },
		{ .NameUTF8 = UTF8TEXT("CloseDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execCloseDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("CloseDigimonMenuUI"), .Pointer = &ADMFMMOPlayerController::execCloseDigimonMenuUI },
		{ .NameUTF8 = UTF8TEXT("ClosePlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execClosePlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("CommandActivePartnerAbilitySlot"), .Pointer = &ADMFMMOPlayerController::execCommandActivePartnerAbilitySlot },
		{ .NameUTF8 = UTF8TEXT("CommandPartnerTargetAndAttack"), .Pointer = &ADMFMMOPlayerController::execCommandPartnerTargetAndAttack },
		{ .NameUTF8 = UTF8TEXT("HandlePlayerSkinRequirementChanged"), .Pointer = &ADMFMMOPlayerController::execHandlePlayerSkinRequirementChanged },
		{ .NameUTF8 = UTF8TEXT("HandleScanDataRewardGranted"), .Pointer = &ADMFMMOPlayerController::execHandleScanDataRewardGranted },
		{ .NameUTF8 = UTF8TEXT("HandleStarterRequirementChanged"), .Pointer = &ADMFMMOPlayerController::execHandleStarterRequirementChanged },
		{ .NameUTF8 = UTF8TEXT("IsDigimonInventoryUIOpen"), .Pointer = &ADMFMMOPlayerController::execIsDigimonInventoryUIOpen },
		{ .NameUTF8 = UTF8TEXT("IsDigimonMenuUIOpen"), .Pointer = &ADMFMMOPlayerController::execIsDigimonMenuUIOpen },
		{ .NameUTF8 = UTF8TEXT("IsFrameworkPlayerAvatarPossessed"), .Pointer = &ADMFMMOPlayerController::execIsFrameworkPlayerAvatarPossessed },
		{ .NameUTF8 = UTF8TEXT("IsPlayerSkinSelectionUIOpen"), .Pointer = &ADMFMMOPlayerController::execIsPlayerSkinSelectionUIOpen },
		{ .NameUTF8 = UTF8TEXT("OpenDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execOpenDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("OpenDigimonMenuUI"), .Pointer = &ADMFMMOPlayerController::execOpenDigimonMenuUI },
		{ .NameUTF8 = UTF8TEXT("OpenPlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execOpenPlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("OpenScanMaterializeUI"), .Pointer = &ADMFMMOPlayerController::execOpenScanMaterializeUI },
		{ .NameUTF8 = UTF8TEXT("RefreshCombatQuickBar"), .Pointer = &ADMFMMOPlayerController::execRefreshCombatQuickBar },
		{ .NameUTF8 = UTF8TEXT("RefreshDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execRefreshDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("RefreshPlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execRefreshPlayerSkinSelectionUI },
		{ .NameUTF8 = UTF8TEXT("RefreshStarterSelectionUI"), .Pointer = &ADMFMMOPlayerController::execRefreshStarterSelectionUI },
		{ .NameUTF8 = UTF8TEXT("RequestUseHealer"), .Pointer = &ADMFMMOPlayerController::execRequestUseHealer },
		{ .NameUTF8 = UTF8TEXT("SelectDigimonCommandTargetUnderCursor"), .Pointer = &ADMFMMOPlayerController::execSelectDigimonCommandTargetUnderCursor },
		{ .NameUTF8 = UTF8TEXT("ServerEnsureFrameworkPlayerAvatar"), .Pointer = &ADMFMMOPlayerController::execServerEnsureFrameworkPlayerAvatar },
		{ .NameUTF8 = UTF8TEXT("ServerRequestUseHealer"), .Pointer = &ADMFMMOPlayerController::execServerRequestUseHealer },
		{ .NameUTF8 = UTF8TEXT("SetDigimonCommandTarget"), .Pointer = &ADMFMMOPlayerController::execSetDigimonCommandTarget },
		{ .NameUTF8 = UTF8TEXT("ToggleDigimonInventoryUI"), .Pointer = &ADMFMMOPlayerController::execToggleDigimonInventoryUI },
		{ .NameUTF8 = UTF8TEXT("ToggleDigimonMenuUI"), .Pointer = &ADMFMMOPlayerController::execToggleDigimonMenuUI },
		{ .NameUTF8 = UTF8TEXT("TogglePlayerSkinSelectionUI"), .Pointer = &ADMFMMOPlayerController::execTogglePlayerSkinSelectionUI },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClientHealerInteractionResult, "ClientHealerInteractionResult" }, // fd0bd79f47752d4aeb3d61f8889502552ad8dfd2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonInventoryUI, "CloseDigimonInventoryUI" }, // 9bdf8979d95ee2d0690ca274ebd92aeebb491e59
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CloseDigimonMenuUI, "CloseDigimonMenuUI" }, // 2d4c0431c81fb1351a38ec9b84d9cdca2104fc31
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ClosePlayerSkinSelectionUI, "ClosePlayerSkinSelectionUI" }, // aea3717f1069c904491fb40ceb6a641c4744099b
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CommandActivePartnerAbilitySlot, "CommandActivePartnerAbilitySlot" }, // 23e8ffa3a886714910a4020728670525fc575c67
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_CommandPartnerTargetAndAttack, "CommandPartnerTargetAndAttack" }, // 29f86ad7ebe90c83566ec078666ff7b3fed62be5
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandlePlayerSkinRequirementChanged, "HandlePlayerSkinRequirementChanged" }, // 68dd8a3d5479a2f4ce30a20dc045bdf5faad3e0c
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandleScanDataRewardGranted, "HandleScanDataRewardGranted" }, // 8a6ca3842df5e4f71d9dedf3b2f8ae845361dc80
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_HandleStarterRequirementChanged, "HandleStarterRequirementChanged" }, // 234f1c30a81b8146dc2439518b9346db300f0300
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonInventoryUIOpen, "IsDigimonInventoryUIOpen" }, // 30dca46d49345b134256374d71d946aaaaf02902
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsDigimonMenuUIOpen, "IsDigimonMenuUIOpen" }, // 28782c7ad6876aac2319228f063dafa4993ac8ce
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsFrameworkPlayerAvatarPossessed, "IsFrameworkPlayerAvatarPossessed" }, // 137e1d5c5a9b74264ed1d4818e7daa146901353f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_IsPlayerSkinSelectionUIOpen, "IsPlayerSkinSelectionUIOpen" }, // 1dff57173550fa8c99970326a60d43d1f9750f57
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonInventoryUI, "OpenDigimonInventoryUI" }, // 3947e5ecc7643b8a10541f4dc0cb64fdc929fe37
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenDigimonMenuUI, "OpenDigimonMenuUI" }, // 787480e966b131e71ec312ab075f06312bab1600
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenPlayerSkinSelectionUI, "OpenPlayerSkinSelectionUI" }, // d2bef495faf2ebf66a36702e48fbd948f57318c2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_OpenScanMaterializeUI, "OpenScanMaterializeUI" }, // 76471492722ae85e4c2db7c6646ad7c0c4ae5980
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshCombatQuickBar, "RefreshCombatQuickBar" }, // 55dfa403a03ba1802f9cdfed6954fe8855a9a3c9
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshDigimonInventoryUI, "RefreshDigimonInventoryUI" }, // 2eb6bbbfb19e039f95fba79d2ad9df2b035f7d97
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshPlayerSkinSelectionUI, "RefreshPlayerSkinSelectionUI" }, // 63c4b16d73d5d5b889759ffda68ec30442000bb2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RefreshStarterSelectionUI, "RefreshStarterSelectionUI" }, // d7dbaa478809f0e8e263917c1869d4d1e4c66543
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_RequestUseHealer, "RequestUseHealer" }, // 8b7c978fd62e9a2fccc659796cd3dcecd42dd1c2
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_SelectDigimonCommandTargetUnderCursor, "SelectDigimonCommandTargetUnderCursor" }, // b31362fed008ea36285bb10bd1c1e764c00c95d5
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerEnsureFrameworkPlayerAvatar, "ServerEnsureFrameworkPlayerAvatar" }, // 5547590643a8cd2b864d0724cf9d4aa59fd1d83f
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ServerRequestUseHealer, "ServerRequestUseHealer" }, // 6a423e4241ab2b3633c55f745a05341f15f81895
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_SetDigimonCommandTarget, "SetDigimonCommandTarget" }, // e0e3f11fd4a59ce242ae4fac227e26c71cc4db0d
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ToggleDigimonInventoryUI, "ToggleDigimonInventoryUI" }, // 1893494b5ab3226eb58563a9dbb3d33d79a25fa8
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_ToggleDigimonMenuUI, "ToggleDigimonMenuUI" }, // cf7e83b5f6bd46871bb374f8b3bb2c379433b0de
		{ &Z_Construct_UFunction_ADMFMMOPlayerController_TogglePlayerSkinSelectionUI, "TogglePlayerSkinSelectionUI" }, // 3abbb90440e9197880dc01d7101f3abee696245b
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFMMOPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFMMOPlayerController Property Definitions *****************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnHealerInteractionResult = { "OnHealerInteractionResult", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, OnHealerInteractionResult), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFHealerInteractionResult__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHealerInteractionResult_MetaData), NewProp_OnHealerInteractionResult_MetaData) }; // 9ba86616cb8239af890236ec23f5944e3890a6ae
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_StarterWidget = { "StarterWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, StarterWidget), Z_Construct_UClass_UDMFStarterSelectionWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarterWidget_MetaData), NewProp_StarterWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CombatQuickBarWidget = { "CombatQuickBarWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, CombatQuickBarWidget), Z_Construct_UClass_UDMFCombatQuickBarWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatQuickBarWidget_MetaData), NewProp_CombatQuickBarWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerSkinWidget = { "PlayerSkinWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, PlayerSkinWidget), Z_Construct_UClass_UDMFPlayerSkinSelectionWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSkinWidget_MetaData), NewProp_PlayerSkinWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DigimonInventoryWidget = { "DigimonInventoryWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, DigimonInventoryWidget), Z_Construct_UClass_UDMFDigimonInventoryWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DigimonInventoryWidget_MetaData), NewProp_DigimonInventoryWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ScanNotificationWidget = { "ScanNotificationWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFMMOPlayerController, ScanNotificationWidget), Z_Construct_UClass_UDMFScanNotificationWidget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanNotificationWidget_MetaData), NewProp_ScanNotificationWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnHealerInteractionResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StarterWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CombatQuickBarWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerSkinWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInventoryWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ScanNotificationWidget,
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
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFMMOPlayerController, TEXT("ADMFMMOPlayerController"), &Z_Registration_Info_UClass_ADMFMMOPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFMMOPlayerController), 404420283U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h__Script_DigimonMMOFramework_a68d25f8b542b6beadb0e7e63399d5793a7a2dec{
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
