// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFSocialActionButton.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFSocialActionButton() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFSocialActionButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialActionButtonPressed__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialUIAction(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFSocialActionButton(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EDMFSocialUIAction ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialUIAction_Statics
template<> DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFSocialUIAction>()
{
	return Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialUIAction(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "FriendAccept.Name", "EDMFSocialUIAction::FriendAccept" },
		{ "FriendAdd.Comment", "/** Appended for v0.19.1 nearby-player discovery; existing UI action ordinals remain unchanged. */" },
		{ "FriendAdd.Name", "EDMFSocialUIAction::FriendAdd" },
		{ "FriendAdd.ToolTip", "Appended for v0.19.1 nearby-player discovery; existing UI action ordinals remain unchanged." },
		{ "FriendCancel.Name", "EDMFSocialUIAction::FriendCancel" },
		{ "FriendDecline.Name", "EDMFSocialUIAction::FriendDecline" },
		{ "FriendRemove.Name", "EDMFSocialUIAction::FriendRemove" },
		{ "FriendTrackToggle.Name", "EDMFSocialUIAction::FriendTrackToggle" },
		{ "GuildApplicationAccept.Name", "EDMFSocialUIAction::GuildApplicationAccept" },
		{ "GuildApplicationDecline.Name", "EDMFSocialUIAction::GuildApplicationDecline" },
		{ "GuildApply.Name", "EDMFSocialUIAction::GuildApply" },
		{ "GuildInviteAccept.Name", "EDMFSocialUIAction::GuildInviteAccept" },
		{ "GuildInviteDecline.Name", "EDMFSocialUIAction::GuildInviteDecline" },
		{ "GuildRemoveMember.Name", "EDMFSocialUIAction::GuildRemoveMember" },
		{ "IgnoreAdd.Comment", "/** Appended for v0.19.2 nearby-player Ignore action; all prior UI action ordinals remain unchanged. */" },
		{ "IgnoreAdd.Name", "EDMFSocialUIAction::IgnoreAdd" },
		{ "IgnoreAdd.ToolTip", "Appended for v0.19.2 nearby-player Ignore action; all prior UI action ordinals remain unchanged." },
		{ "IgnoreRemove.Name", "EDMFSocialUIAction::IgnoreRemove" },
		{ "ModuleRelativePath", "Public/UI/DMFSocialActionButton.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDMFSocialUIAction::FriendAccept", (int64)EDMFSocialUIAction::FriendAccept },
		{ "EDMFSocialUIAction::FriendDecline", (int64)EDMFSocialUIAction::FriendDecline },
		{ "EDMFSocialUIAction::FriendCancel", (int64)EDMFSocialUIAction::FriendCancel },
		{ "EDMFSocialUIAction::FriendRemove", (int64)EDMFSocialUIAction::FriendRemove },
		{ "EDMFSocialUIAction::FriendTrackToggle", (int64)EDMFSocialUIAction::FriendTrackToggle },
		{ "EDMFSocialUIAction::IgnoreRemove", (int64)EDMFSocialUIAction::IgnoreRemove },
		{ "EDMFSocialUIAction::GuildInviteAccept", (int64)EDMFSocialUIAction::GuildInviteAccept },
		{ "EDMFSocialUIAction::GuildInviteDecline", (int64)EDMFSocialUIAction::GuildInviteDecline },
		{ "EDMFSocialUIAction::GuildApply", (int64)EDMFSocialUIAction::GuildApply },
		{ "EDMFSocialUIAction::GuildApplicationAccept", (int64)EDMFSocialUIAction::GuildApplicationAccept },
		{ "EDMFSocialUIAction::GuildApplicationDecline", (int64)EDMFSocialUIAction::GuildApplicationDecline },
		{ "EDMFSocialUIAction::GuildRemoveMember", (int64)EDMFSocialUIAction::GuildRemoveMember },
		{ "EDMFSocialUIAction::FriendAdd", (int64)EDMFSocialUIAction::FriendAdd },
		{ "EDMFSocialUIAction::IgnoreAdd", (int64)EDMFSocialUIAction::IgnoreAdd },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
	nullptr,
	"EDMFSocialUIAction",
	"EDMFSocialUIAction",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EDMFSocialUIAction;
UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialUIAction(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EDMFSocialUIAction.OuterSingleton)
		{
			ZRIE_EDMFSocialUIAction.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialUIAction, (UObject*)Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase::Outer), TEXT("EDMFSocialUIAction"));
		}
		return ZRIE_EDMFSocialUIAction.OuterSingleton;
	}
	if (!ZRIE_EDMFSocialUIAction.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EDMFSocialUIAction.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EDMFSocialUIAction.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EDMFSocialUIAction **********************************************************

// ********** Begin Delegate FDMFSocialActionButtonPressed *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialActionButtonPressed__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFSocialActionButtonPressed_Parms
	{
		UDMFSocialActionButton* Button;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFSocialActionButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Button_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFSocialActionButtonPressed constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Button;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFSocialActionButtonPressed constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFSocialActionButtonPressed Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Button = { "Button", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFSocialActionButtonPressed_Parms, Button), Z_Construct_UClass_UDMFSocialActionButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Button_MetaData), NewProp_Button_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Button,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFSocialActionButtonPressed Property Definitions **********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFSocialActionButtonPressed__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFSocialActionButtonPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFSocialActionButtonPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialActionButtonPressed__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFSocialActionButtonPressed *******************************************

// ********** Begin Class UDMFSocialActionButton Function HandleClicked ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFSocialActionButton_HandleClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFSocialActionButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleClicked constinit property declarations *************************
// ********** End Function HandleClicked constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFSocialActionButton, nullptr, "HandleClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFSocialActionButton_HandleClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFSocialActionButton::execHandleClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFSocialActionButton Function HandleClicked ******************************

// ********** Begin Class UDMFSocialActionButton ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFSocialActionButton_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tiny native payload button used by dynamic Social lists without storing authority inside the UI. */" },
#endif
		{ "IncludePath", "UI/DMFSocialActionButton.h" },
		{ "ModuleRelativePath", "Public/UI/DMFSocialActionButton.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tiny native payload button used by dynamic Social lists without storing authority inside the UI." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocialAction_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
		{ "ModuleRelativePath", "Public/UI/DMFSocialActionButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubjectUsername_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
		{ "ModuleRelativePath", "Public/UI/DMFSocialActionButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubjectGuildId_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
		{ "ModuleRelativePath", "Public/UI/DMFSocialActionButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bValue_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
		{ "ModuleRelativePath", "Public/UI/DMFSocialActionButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSocialActionPressed_MetaData[] = {
		{ "Category", "Digimon MMO|Social" },
		{ "ModuleRelativePath", "Public/UI/DMFSocialActionButton.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFSocialActionButton constinit property declarations *******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_SocialAction_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SocialAction;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SubjectUsername;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SubjectGuildId;
	static void NewProp_bValue_SetBit(void* Obj)
	{
		((UDMFSocialActionButton*)Obj)->bValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSocialActionPressed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFSocialActionButton constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleClicked"), .Pointer = &UDMFSocialActionButton::execHandleClicked },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFSocialActionButton_HandleClicked, "HandleClicked" }, // 5f15efe0c54c85c952de1ff0fbb181675d9e03e8
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFSocialActionButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFSocialActionButton Property Definitions ******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_SocialAction_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_SocialAction = { "SocialAction", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFSocialActionButton, SocialAction), Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialUIAction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocialAction_MetaData), NewProp_SocialAction_MetaData) }; // 4f14832e647bb4b997329624ab54c8a7dc019dd2
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SubjectUsername = { "SubjectUsername", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFSocialActionButton, SubjectUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubjectUsername_MetaData), NewProp_SubjectUsername_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_SubjectGuildId = { "SubjectGuildId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFSocialActionButton, SubjectGuildId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubjectGuildId_MetaData), NewProp_SubjectGuildId_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMFSocialActionButton), &UHT_STATICS::NewProp_bValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bValue_MetaData), NewProp_bValue_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnSocialActionPressed = { "OnSocialActionPressed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFSocialActionButton, OnSocialActionPressed), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFSocialActionButtonPressed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSocialActionPressed_MetaData), NewProp_OnSocialActionPressed_MetaData) }; // 4bd17c669a6223d0f1f1e679dfc4e14998976c84
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialAction_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SocialAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SubjectUsername,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SubjectGuildId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnSocialActionPressed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFSocialActionButton Property Definitions ********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UButton,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFSocialActionButton,
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
	0x00B000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UDMFSocialActionButton_StaticRegisterNativesUDMFSocialActionButton()
{
	UClass* Class = UDMFSocialActionButton::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFSocialActionButton;
UClass* Z_Construct_UClass_UDMFSocialActionButton(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFSocialActionButton;
		if (!Z_Registration_Info_UClass_UDMFSocialActionButton.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFSocialActionButton"),
				Z_Registration_Info_UClass_UDMFSocialActionButton.InnerSingleton,
				UDMFSocialActionButton_StaticRegisterNativesUDMFSocialActionButton,
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
		return Z_Registration_Info_UClass_UDMFSocialActionButton.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFSocialActionButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFSocialActionButton.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFSocialActionButton.OuterSingleton;
}
#undef UHT_STATICS
UDMFSocialActionButton::UDMFSocialActionButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFSocialActionButton);
UDMFSocialActionButton::~UDMFSocialActionButton() {}
// ********** End Class UDMFSocialActionButton *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_DigimonMMOFramework_EDMFSocialUIAction, TEXT("EDMFSocialUIAction"), &ZRIE_EDMFSocialUIAction, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1326744366U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFSocialActionButton, TEXT("UDMFSocialActionButton"), &Z_Registration_Info_UClass_UDMFSocialActionButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFSocialActionButton), 3823657234U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h__Script_DigimonMMOFramework_892e3d951e9147355fbeb9f68c8d6cd0b37c5fde{
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
