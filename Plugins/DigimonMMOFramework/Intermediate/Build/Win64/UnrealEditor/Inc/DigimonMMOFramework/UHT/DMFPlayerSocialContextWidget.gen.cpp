// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFPlayerSocialContextWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFPlayerSocialContextWidget() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSocialContextWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerSocialContextWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFPlayerSocialContextWidget Function GetTargetUsername *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSocialContextWidget_GetTargetUsername_Statics
struct UHT_STATICS
{
	struct DMFPlayerSocialContextWidget_eventGetTargetUsername_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Nameplate Context" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTargetUsername constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTargetUsername constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTargetUsername Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSocialContextWidget_eventGetTargetUsername_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetTargetUsername Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSocialContextWidget, nullptr, "GetTargetUsername", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerSocialContextWidget_eventGetTargetUsername_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerSocialContextWidget_eventGetTargetUsername_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerSocialContextWidget_GetTargetUsername(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSocialContextWidget::execGetTargetUsername)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetTargetUsername();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSocialContextWidget Function GetTargetUsername *******************

// ********** Begin Class UDMFPlayerSocialContextWidget Function HandleClose ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleClose_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleClose constinit property declarations ***************************
// ********** End Function HandleClose constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSocialContextWidget, nullptr, "HandleClose", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleClose(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSocialContextWidget::execHandleClose)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleClose();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSocialContextWidget Function HandleClose *************************

// ********** Begin Class UDMFPlayerSocialContextWidget Function HandleFriendAction ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleFriendAction_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleFriendAction constinit property declarations ********************
// ********** End Function HandleFriendAction constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSocialContextWidget, nullptr, "HandleFriendAction", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleFriendAction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSocialContextWidget::execHandleFriendAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleFriendAction();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSocialContextWidget Function HandleFriendAction ******************

// ********** Begin Class UDMFPlayerSocialContextWidget Function HandleGuildInvite *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleGuildInvite_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleGuildInvite constinit property declarations *********************
// ********** End Function HandleGuildInvite constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSocialContextWidget, nullptr, "HandleGuildInvite", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleGuildInvite(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSocialContextWidget::execHandleGuildInvite)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleGuildInvite();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSocialContextWidget Function HandleGuildInvite *******************

// ********** Begin Class UDMFPlayerSocialContextWidget Function HandleIgnoreAction ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleIgnoreAction_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleIgnoreAction constinit property declarations ********************
// ********** End Function HandleIgnoreAction constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSocialContextWidget, nullptr, "HandleIgnoreAction", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleIgnoreAction(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSocialContextWidget::execHandleIgnoreAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleIgnoreAction();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSocialContextWidget Function HandleIgnoreAction ******************

// ********** Begin Class UDMFPlayerSocialContextWidget Function RefreshActions ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSocialContextWidget_RefreshActions_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Nameplate Context" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshActions constinit property declarations ************************
// ********** End Function RefreshActions constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSocialContextWidget, nullptr, "RefreshActions", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPlayerSocialContextWidget_RefreshActions(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSocialContextWidget::execRefreshActions)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshActions();
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSocialContextWidget Function RefreshActions **********************

// ********** Begin Class UDMFPlayerSocialContextWidget Function SetTargetPlayer *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPlayerSocialContextWidget_SetTargetPlayer_Statics
struct UHT_STATICS
{
	struct DMFPlayerSocialContextWidget_eventSetTargetPlayer_Parms
	{
		ADMFPlayerAvatarCharacter* InTargetPlayer;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Nameplate Context" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTargetPlayer constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InTargetPlayer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTargetPlayer constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTargetPlayer Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InTargetPlayer = { "InTargetPlayer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPlayerSocialContextWidget_eventSetTargetPlayer_Parms, InTargetPlayer), Z_Construct_UClass_ADMFPlayerAvatarCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InTargetPlayer,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetTargetPlayer Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPlayerSocialContextWidget, nullptr, "SetTargetPlayer", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPlayerSocialContextWidget_eventSetTargetPlayer_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPlayerSocialContextWidget_eventSetTargetPlayer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPlayerSocialContextWidget_SetTargetPlayer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPlayerSocialContextWidget::execSetTargetPlayer)
{
	P_GET_OBJECT(ADMFPlayerAvatarCharacter,Z_Param_InTargetPlayer);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTargetPlayer(Z_Param_InTargetPlayer);
	P_NATIVE_END;
}
// ********** End Class UDMFPlayerSocialContextWidget Function SetTargetPlayer *********************

// ********** Begin Class UDMFPlayerSocialContextWidget ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFPlayerSocialContextWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Owner-local dropdown opened by clicking an exact replicated player nameplate. It never mutates social\n * state directly: each action is routed through the owning PlayerController's validated server RPC.\n */" },
#endif
		{ "IncludePath", "UI/DMFPlayerSocialContextWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owner-local dropdown opened by clicking an exact replicated player nameplate. It never mutates social\nstate directly: each action is routed through the owning PlayerController's validated server RPC." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSocialContextWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RelationshipText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSocialContextWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendActionButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSocialContextWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendActionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSocialContextWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IgnoreActionButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSocialContextWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IgnoreActionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSocialContextWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuildInviteButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSocialContextWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPlayerSocialContextWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPlayerSocialContextWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFPlayerSocialContextWidget constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RelationshipText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FriendActionButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FriendActionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IgnoreActionButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IgnoreActionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GuildInviteButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFPlayerSocialContextWidget constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetTargetUsername"), .Pointer = &UDMFPlayerSocialContextWidget::execGetTargetUsername },
		{ .NameUTF8 = UTF8TEXT("HandleClose"), .Pointer = &UDMFPlayerSocialContextWidget::execHandleClose },
		{ .NameUTF8 = UTF8TEXT("HandleFriendAction"), .Pointer = &UDMFPlayerSocialContextWidget::execHandleFriendAction },
		{ .NameUTF8 = UTF8TEXT("HandleGuildInvite"), .Pointer = &UDMFPlayerSocialContextWidget::execHandleGuildInvite },
		{ .NameUTF8 = UTF8TEXT("HandleIgnoreAction"), .Pointer = &UDMFPlayerSocialContextWidget::execHandleIgnoreAction },
		{ .NameUTF8 = UTF8TEXT("RefreshActions"), .Pointer = &UDMFPlayerSocialContextWidget::execRefreshActions },
		{ .NameUTF8 = UTF8TEXT("SetTargetPlayer"), .Pointer = &UDMFPlayerSocialContextWidget::execSetTargetPlayer },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFPlayerSocialContextWidget_GetTargetUsername, "GetTargetUsername" }, // 56d7d66855fdee705bfe3b6fb8486e1026349f43
		{ &Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleClose, "HandleClose" }, // 3bd3f849fe881381661f9ef8a42436c295a9e79a
		{ &Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleFriendAction, "HandleFriendAction" }, // 01ff625fc42f17599879ae6f41610433bc6b99b5
		{ &Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleGuildInvite, "HandleGuildInvite" }, // 04eb924c1c04092e1383fdddca1cb521448fdeb4
		{ &Z_Construct_UFunction_UDMFPlayerSocialContextWidget_HandleIgnoreAction, "HandleIgnoreAction" }, // 134778331b08d5900fea76fe5a9f3b311b06b41e
		{ &Z_Construct_UFunction_UDMFPlayerSocialContextWidget_RefreshActions, "RefreshActions" }, // 1f843b351d7cf7ce3ed77e3a179ac8072efab394
		{ &Z_Construct_UFunction_UDMFPlayerSocialContextWidget_SetTargetPlayer, "SetTargetPlayer" }, // 1902c815c4ba92be6ea8241a02719ee4077c2ca1
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFPlayerSocialContextWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFPlayerSocialContextWidget Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetNameText = { "TargetNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSocialContextWidget, TargetNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetNameText_MetaData), NewProp_TargetNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RelationshipText = { "RelationshipText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSocialContextWidget, RelationshipText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RelationshipText_MetaData), NewProp_RelationshipText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FriendActionButton = { "FriendActionButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSocialContextWidget, FriendActionButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendActionButton_MetaData), NewProp_FriendActionButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FriendActionText = { "FriendActionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSocialContextWidget, FriendActionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendActionText_MetaData), NewProp_FriendActionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_IgnoreActionButton = { "IgnoreActionButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSocialContextWidget, IgnoreActionButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IgnoreActionButton_MetaData), NewProp_IgnoreActionButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_IgnoreActionText = { "IgnoreActionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSocialContextWidget, IgnoreActionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IgnoreActionText_MetaData), NewProp_IgnoreActionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_GuildInviteButton = { "GuildInviteButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSocialContextWidget, GuildInviteButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuildInviteButton_MetaData), NewProp_GuildInviteButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CloseButton = { "CloseButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPlayerSocialContextWidget, CloseButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButton_MetaData), NewProp_CloseButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RelationshipText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FriendActionButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FriendActionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_IgnoreActionButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_IgnoreActionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_GuildInviteButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CloseButton,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFPlayerSocialContextWidget Property Definitions *************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFPlayerSocialContextWidget,
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
static void UDMFPlayerSocialContextWidget_StaticRegisterNativesUDMFPlayerSocialContextWidget()
{
	UClass* Class = UDMFPlayerSocialContextWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFPlayerSocialContextWidget;
UClass* Z_Construct_UClass_UDMFPlayerSocialContextWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFPlayerSocialContextWidget;
		if (!Z_Registration_Info_UClass_UDMFPlayerSocialContextWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFPlayerSocialContextWidget"),
				Z_Registration_Info_UClass_UDMFPlayerSocialContextWidget.InnerSingleton,
				UDMFPlayerSocialContextWidget_StaticRegisterNativesUDMFPlayerSocialContextWidget,
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
		return Z_Registration_Info_UClass_UDMFPlayerSocialContextWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFPlayerSocialContextWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFPlayerSocialContextWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFPlayerSocialContextWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFPlayerSocialContextWidget::UDMFPlayerSocialContextWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFPlayerSocialContextWidget);
UDMFPlayerSocialContextWidget::~UDMFPlayerSocialContextWidget() {}
// ********** End Class UDMFPlayerSocialContextWidget **********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPlayerSocialContextWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFPlayerSocialContextWidget, TEXT("UDMFPlayerSocialContextWidget"), &Z_Registration_Info_UClass_UDMFPlayerSocialContextWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFPlayerSocialContextWidget), 2723922164U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPlayerSocialContextWidget_h__Script_DigimonMMOFramework_d1f5780d08d5603121b093bffad49a73171f161f{
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
