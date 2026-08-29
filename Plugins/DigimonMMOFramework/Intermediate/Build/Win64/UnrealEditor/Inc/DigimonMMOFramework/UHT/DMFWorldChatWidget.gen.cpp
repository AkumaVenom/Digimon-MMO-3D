// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFWorldChatWidget.h"
#include "DMFTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFWorldChatWidget() {}

// ********** Begin Cross Module References ********************************************************
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UBorder(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UEditableTextBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UScrollBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UVerticalBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFWorldChatMessage(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldChatWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldChatWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFWorldChatWidget Function AddChatMessage ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_AddChatMessage_Statics
struct UHT_STATICS
{
	struct DMFWorldChatWidget_eventAddChatMessage_Parms
	{
		FDMFWorldChatMessage ChatMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChatMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddChatMessage constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChatMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddChatMessage constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddChatMessage Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ChatMessage = { "ChatMessage", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldChatWidget_eventAddChatMessage_Parms, ChatMessage), Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChatMessage_MetaData), NewProp_ChatMessage_MetaData) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChatMessage,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddChatMessage Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "AddChatMessage", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWorldChatWidget_eventAddChatMessage_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWorldChatWidget_eventAddChatMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_AddChatMessage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldChatWidget::execAddChatMessage)
{
	P_GET_STRUCT_REF(FDMFWorldChatMessage,Z_Param_Out_ChatMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddChatMessage(Z_Param_Out_ChatMessage);
	P_NATIVE_END;
}
// ********** End Class UDMFWorldChatWidget Function AddChatMessage ********************************

// ********** Begin Class UDMFWorldChatWidget Function AddLocalSystemMessage ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_AddLocalSystemMessage_Statics
struct UHT_STATICS
{
	struct DMFWorldChatWidget_eventAddLocalSystemMessage_Parms
	{
		FText Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddLocalSystemMessage constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddLocalSystemMessage constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddLocalSystemMessage Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldChatWidget_eventAddLocalSystemMessage_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddLocalSystemMessage Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "AddLocalSystemMessage", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWorldChatWidget_eventAddLocalSystemMessage_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWorldChatWidget_eventAddLocalSystemMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_AddLocalSystemMessage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldChatWidget::execAddLocalSystemMessage)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddLocalSystemMessage(Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class UDMFWorldChatWidget Function AddLocalSystemMessage *************************

// ********** Begin Class UDMFWorldChatWidget Function BP_OnWorldChatInputStateChanged *************
struct DMFWorldChatWidget_eventBP_OnWorldChatInputStateChanged_Parms
{
	bool bInputOpen;
};
static FName NAME_UDMFWorldChatWidget_BP_OnWorldChatInputStateChanged = FName(TEXT("BP_OnWorldChatInputStateChanged"));
void UDMFWorldChatWidget::BP_OnWorldChatInputStateChanged(bool bInputOpen)
{
	DMFWorldChatWidget_eventBP_OnWorldChatInputStateChanged_Parms Parms;
	Parms.bInputOpen=bInputOpen ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_UDMFWorldChatWidget_BP_OnWorldChatInputStateChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_BP_OnWorldChatInputStateChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lets Blueprint skins react to native Enter/Escape chat focus without taking over authority. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lets Blueprint skins react to native Enter/Escape chat focus without taking over authority." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnWorldChatInputStateChanged constinit property declarations *******
	static void NewProp_bInputOpen_SetBit(void* Obj)
	{
		((DMFWorldChatWidget_eventBP_OnWorldChatInputStateChanged_Parms*)Obj)->bInputOpen = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInputOpen;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnWorldChatInputStateChanged constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnWorldChatInputStateChanged Property Definitions ******************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bInputOpen = { "bInputOpen", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWorldChatWidget_eventBP_OnWorldChatInputStateChanged_Parms), &UHT_STATICS::NewProp_bInputOpen_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bInputOpen,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnWorldChatInputStateChanged Property Definitions ********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "BP_OnWorldChatInputStateChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFWorldChatWidget_eventBP_OnWorldChatInputStateChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFWorldChatWidget_eventBP_OnWorldChatInputStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_BP_OnWorldChatInputStateChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFWorldChatWidget Function BP_OnWorldChatInputStateChanged ***************

// ********** Begin Class UDMFWorldChatWidget Function BP_OnWorldChatMessageAdded ******************
struct DMFWorldChatWidget_eventBP_OnWorldChatMessageAdded_Parms
{
	FDMFWorldChatMessage ChatMessage;
};
static FName NAME_UDMFWorldChatWidget_BP_OnWorldChatMessageAdded = FName(TEXT("BP_OnWorldChatMessageAdded"));
void UDMFWorldChatWidget::BP_OnWorldChatMessageAdded(FDMFWorldChatMessage const& ChatMessage)
{
	DMFWorldChatWidget_eventBP_OnWorldChatMessageAdded_Parms Parms;
	Parms.ChatMessage=ChatMessage;
	UFunction* Func = FindFunctionChecked(NAME_UDMFWorldChatWidget_BP_OnWorldChatMessageAdded);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_BP_OnWorldChatMessageAdded_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired after a message enters the local bounded history, including history delivered on join. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired after a message enters the local bounded history, including history delivered on join." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChatMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnWorldChatMessageAdded constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChatMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnWorldChatMessageAdded constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnWorldChatMessageAdded Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ChatMessage = { "ChatMessage", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldChatWidget_eventBP_OnWorldChatMessageAdded_Parms, ChatMessage), Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChatMessage_MetaData), NewProp_ChatMessage_MetaData) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChatMessage,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnWorldChatMessageAdded Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "BP_OnWorldChatMessageAdded", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFWorldChatWidget_eventBP_OnWorldChatMessageAdded_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFWorldChatWidget_eventBP_OnWorldChatMessageAdded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_BP_OnWorldChatMessageAdded(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFWorldChatWidget Function BP_OnWorldChatMessageAdded ********************

// ********** Begin Class UDMFWorldChatWidget Function ClearChatHistory ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_ClearChatHistory_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearChatHistory constinit property declarations **********************
// ********** End Function ClearChatHistory constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "ClearChatHistory", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_ClearChatHistory(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldChatWidget::execClearChatHistory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearChatHistory();
	P_NATIVE_END;
}
// ********** End Class UDMFWorldChatWidget Function ClearChatHistory ******************************

// ********** Begin Class UDMFWorldChatWidget Function CloseChatInput ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_CloseChatInput_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseChatInput constinit property declarations ************************
// ********** End Function CloseChatInput constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "CloseChatInput", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_CloseChatInput(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldChatWidget::execCloseChatInput)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseChatInput();
	P_NATIVE_END;
}
// ********** End Class UDMFWorldChatWidget Function CloseChatInput ********************************

// ********** Begin Class UDMFWorldChatWidget Function GetVisibleMessageCount **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_GetVisibleMessageCount_Statics
struct UHT_STATICS
{
	struct DMFWorldChatWidget_eventGetVisibleMessageCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetVisibleMessageCount constinit property declarations ****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVisibleMessageCount constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVisibleMessageCount Property Definitions ***************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldChatWidget_eventGetVisibleMessageCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetVisibleMessageCount Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "GetVisibleMessageCount", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWorldChatWidget_eventGetVisibleMessageCount_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWorldChatWidget_eventGetVisibleMessageCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_GetVisibleMessageCount(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldChatWidget::execGetVisibleMessageCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetVisibleMessageCount();
	P_NATIVE_END;
}
// ********** End Class UDMFWorldChatWidget Function GetVisibleMessageCount ************************

// ********** Begin Class UDMFWorldChatWidget Function HandleMessageCommitted **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_HandleMessageCommitted_Statics
struct UHT_STATICS
{
	struct DMFWorldChatWidget_eventHandleMessageCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleMessageCommitted constinit property declarations ****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleMessageCommitted constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleMessageCommitted Property Definitions ***************************
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldChatWidget_eventHandleMessageCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldChatWidget_eventHandleMessageCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 8323d5849e62ec5be16727bbd18b698ac3ecdec4
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleMessageCommitted Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "HandleMessageCommitted", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWorldChatWidget_eventHandleMessageCommitted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWorldChatWidget_eventHandleMessageCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_HandleMessageCommitted(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldChatWidget::execHandleMessageCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMessageCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UDMFWorldChatWidget Function HandleMessageCommitted ************************

// ********** Begin Class UDMFWorldChatWidget Function IsChatInputOpen *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_IsChatInputOpen_Statics
struct UHT_STATICS
{
	struct DMFWorldChatWidget_eventIsChatInputOpen_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsChatInputOpen constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFWorldChatWidget_eventIsChatInputOpen_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsChatInputOpen constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsChatInputOpen Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFWorldChatWidget_eventIsChatInputOpen_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsChatInputOpen Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "IsChatInputOpen", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWorldChatWidget_eventIsChatInputOpen_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWorldChatWidget_eventIsChatInputOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_IsChatInputOpen(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldChatWidget::execIsChatInputOpen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsChatInputOpen();
	P_NATIVE_END;
}
// ********** End Class UDMFWorldChatWidget Function IsChatInputOpen *******************************

// ********** Begin Class UDMFWorldChatWidget Function OpenChatInput *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_OpenChatInput_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenChatInput constinit property declarations *************************
// ********** End Function OpenChatInput constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "OpenChatInput", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_OpenChatInput(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldChatWidget::execOpenChatInput)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenChatInput();
	P_NATIVE_END;
}
// ********** End Class UDMFWorldChatWidget Function OpenChatInput *********************************

// ********** Begin Class UDMFWorldChatWidget Function SetChatHistory ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFWorldChatWidget_SetChatHistory_Statics
struct UHT_STATICS
{
	struct DMFWorldChatWidget_eventSetChatHistory_Parms
	{
		TArray<FDMFWorldChatMessage> ChatMessages;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|UI|World Chat" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChatMessages_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetChatHistory constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChatMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ChatMessages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetChatHistory constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetChatHistory Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ChatMessages_Inner = { "ChatMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(0, nullptr) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_ChatMessages = { "ChatMessages", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(DMFWorldChatWidget_eventSetChatHistory_Parms, ChatMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChatMessages_MetaData), NewProp_ChatMessages_MetaData) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChatMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChatMessages,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetChatHistory Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFWorldChatWidget, nullptr, "SetChatHistory", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFWorldChatWidget_eventSetChatHistory_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFWorldChatWidget_eventSetChatHistory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFWorldChatWidget_SetChatHistory(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFWorldChatWidget::execSetChatHistory)
{
	P_GET_TARRAY_REF(FDMFWorldChatMessage,Z_Param_Out_ChatMessages);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetChatHistory(Z_Param_Out_ChatMessages);
	P_NATIVE_END;
}
// ********** End Class UDMFWorldChatWidget Function SetChatHistory ********************************

// ********** Begin Class UDMFWorldChatWidget ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFWorldChatWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Polished native MMO world-chat presentation.\n *\n * Authority remains in ADMFMMOPlayerController/ADMFMMOGameMode. This widget owns only local\n * presentation, bounded client history and text-entry focus. Blueprint children may replace the\n * visual tree while keeping the same validated server message route.\n */" },
#endif
		{ "IncludePath", "UI/DMFWorldChatWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Polished native MMO world-chat presentation.\n\nAuthority remains in ADMFMMOPlayerController/ADMFMMOGameMode. This widget owns only local\npresentation, bounded client history and text-entry focus. Blueprint children may replace the\nvisual tree while keeping the same validated server message route." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChatPanel_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldChatWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MessageScrollBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldChatWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MessageList_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldChatWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputPanel_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldChatWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MessageInput_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldChatWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputHintText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFWorldChatWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocalMessageHistory_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFWorldChatWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFWorldChatWidget constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChatPanel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MessageScrollBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MessageList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputPanel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MessageInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputHintText;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LocalMessageHistory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LocalMessageHistory;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFWorldChatWidget constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddChatMessage"), .Pointer = &UDMFWorldChatWidget::execAddChatMessage },
		{ .NameUTF8 = UTF8TEXT("AddLocalSystemMessage"), .Pointer = &UDMFWorldChatWidget::execAddLocalSystemMessage },
		{ .NameUTF8 = UTF8TEXT("ClearChatHistory"), .Pointer = &UDMFWorldChatWidget::execClearChatHistory },
		{ .NameUTF8 = UTF8TEXT("CloseChatInput"), .Pointer = &UDMFWorldChatWidget::execCloseChatInput },
		{ .NameUTF8 = UTF8TEXT("GetVisibleMessageCount"), .Pointer = &UDMFWorldChatWidget::execGetVisibleMessageCount },
		{ .NameUTF8 = UTF8TEXT("HandleMessageCommitted"), .Pointer = &UDMFWorldChatWidget::execHandleMessageCommitted },
		{ .NameUTF8 = UTF8TEXT("IsChatInputOpen"), .Pointer = &UDMFWorldChatWidget::execIsChatInputOpen },
		{ .NameUTF8 = UTF8TEXT("OpenChatInput"), .Pointer = &UDMFWorldChatWidget::execOpenChatInput },
		{ .NameUTF8 = UTF8TEXT("SetChatHistory"), .Pointer = &UDMFWorldChatWidget::execSetChatHistory },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_AddChatMessage, "AddChatMessage" }, // 330f77387d56fa2cd9f1e9de17736fd04953952c
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_AddLocalSystemMessage, "AddLocalSystemMessage" }, // 8999ddec4ffc75d9f9212ffc1b844ee124d7ac3a
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_BP_OnWorldChatInputStateChanged, "BP_OnWorldChatInputStateChanged" }, // e6ff0f8de76085d563d6a385515514e5437f0237
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_BP_OnWorldChatMessageAdded, "BP_OnWorldChatMessageAdded" }, // c3a33895abc251a0cdb89d25017437dbb3b6761c
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_ClearChatHistory, "ClearChatHistory" }, // f2bf5482b94402f8959d25505f4cd67e7517cdc3
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_CloseChatInput, "CloseChatInput" }, // 960123d46e6eff9474a81cbc96de360bec2d8d16
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_GetVisibleMessageCount, "GetVisibleMessageCount" }, // 644630848d3d38b267f21f20a75f0043723ad0fd
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_HandleMessageCommitted, "HandleMessageCommitted" }, // a7e9ff84ab1ab5b1543a6100267ddbcb3e21bab1
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_IsChatInputOpen, "IsChatInputOpen" }, // cc265a6f799923e7bdcfc8f1e36442689801aaa9
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_OpenChatInput, "OpenChatInput" }, // 2f703685681dfc911d5cc4c9c3d8f1d471494893
		{ &Z_Construct_UFunction_UDMFWorldChatWidget_SetChatHistory, "SetChatHistory" }, // e2359a3dff6bb1a6085cc9bbbaf80146ba2786f3
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFWorldChatWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFWorldChatWidget Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ChatPanel = { "ChatPanel", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldChatWidget, ChatPanel), Z_Construct_UClass_UBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChatPanel_MetaData), NewProp_ChatPanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MessageScrollBox = { "MessageScrollBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldChatWidget, MessageScrollBox), Z_Construct_UClass_UScrollBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MessageScrollBox_MetaData), NewProp_MessageScrollBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MessageList = { "MessageList", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldChatWidget, MessageList), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MessageList_MetaData), NewProp_MessageList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InputPanel = { "InputPanel", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldChatWidget, InputPanel), Z_Construct_UClass_UBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputPanel_MetaData), NewProp_InputPanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MessageInput = { "MessageInput", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldChatWidget, MessageInput), Z_Construct_UClass_UEditableTextBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MessageInput_MetaData), NewProp_MessageInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InputHintText = { "InputHintText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldChatWidget, InputHintText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputHintText_MetaData), NewProp_InputHintText_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_LocalMessageHistory_Inner = { "LocalMessageHistory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDMFWorldChatMessage, METADATA_PARAMS(0, nullptr) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_LocalMessageHistory = { "LocalMessageHistory", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFWorldChatWidget, LocalMessageHistory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocalMessageHistory_MetaData), NewProp_LocalMessageHistory_MetaData) }; // b82f86f3fb3e358f6bcad1cb30404f77a3b069cd
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ChatPanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MessageScrollBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MessageList,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InputPanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MessageInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InputHintText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LocalMessageHistory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LocalMessageHistory,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFWorldChatWidget Property Definitions ***********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFWorldChatWidget,
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
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UDMFWorldChatWidget_StaticRegisterNativesUDMFWorldChatWidget()
{
	UClass* Class = UDMFWorldChatWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFWorldChatWidget;
UClass* Z_Construct_UClass_UDMFWorldChatWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFWorldChatWidget;
		if (!Z_Registration_Info_UClass_UDMFWorldChatWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFWorldChatWidget"),
				Z_Registration_Info_UClass_UDMFWorldChatWidget.InnerSingleton,
				UDMFWorldChatWidget_StaticRegisterNativesUDMFWorldChatWidget,
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
		return Z_Registration_Info_UClass_UDMFWorldChatWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFWorldChatWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFWorldChatWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFWorldChatWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFWorldChatWidget::UDMFWorldChatWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFWorldChatWidget);
UDMFWorldChatWidget::~UDMFWorldChatWidget() {}
// ********** End Class UDMFWorldChatWidget ********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFWorldChatWidget, TEXT("UDMFWorldChatWidget"), &Z_Registration_Info_UClass_UDMFWorldChatWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFWorldChatWidget), 1115142032U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h__Script_DigimonMMOFramework_fc3f682a6b268f84a3f536edd8f28866d6bc2889{
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
