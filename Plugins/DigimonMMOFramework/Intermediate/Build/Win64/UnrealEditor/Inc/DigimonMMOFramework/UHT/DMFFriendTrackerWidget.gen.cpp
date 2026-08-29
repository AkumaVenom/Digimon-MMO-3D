// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFFriendTrackerWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFFriendTrackerWidget() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UBorder(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFFriendTrackerWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFFriendTrackerWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFFriendTrackerWidget Function BP_OnFriendTrackerRefreshed *************
struct DMFFriendTrackerWidget_eventBP_OnFriendTrackerRefreshed_Parms
{
	ADMFPlayerAvatarCharacter* FriendAvatar;
	int32 DistanceMeters;
};
static FName NAME_UDMFFriendTrackerWidget_BP_OnFriendTrackerRefreshed = FName(TEXT("BP_OnFriendTrackerRefreshed"));
void UDMFFriendTrackerWidget::BP_OnFriendTrackerRefreshed(ADMFPlayerAvatarCharacter* FriendAvatar, int32 DistanceMeters)
{
	DMFFriendTrackerWidget_eventBP_OnFriendTrackerRefreshed_Parms Parms;
	Parms.FriendAvatar=FriendAvatar;
	Parms.DistanceMeters=DistanceMeters;
	UFunction* Func = FindFunctionChecked(NAME_UDMFFriendTrackerWidget_BP_OnFriendTrackerRefreshed);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFFriendTrackerWidget_BP_OnFriendTrackerRefreshed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friend Tracking" },
		{ "ModuleRelativePath", "Public/UI/DMFFriendTrackerWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnFriendTrackerRefreshed constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FriendAvatar;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DistanceMeters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnFriendTrackerRefreshed constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnFriendTrackerRefreshed Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FriendAvatar = { "FriendAvatar", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFFriendTrackerWidget_eventBP_OnFriendTrackerRefreshed_Parms, FriendAvatar), Z_Construct_UClass_ADMFPlayerAvatarCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DistanceMeters = { "DistanceMeters", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFFriendTrackerWidget_eventBP_OnFriendTrackerRefreshed_Parms, DistanceMeters), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FriendAvatar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistanceMeters,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnFriendTrackerRefreshed Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFFriendTrackerWidget, nullptr, "BP_OnFriendTrackerRefreshed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFFriendTrackerWidget_eventBP_OnFriendTrackerRefreshed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFFriendTrackerWidget_eventBP_OnFriendTrackerRefreshed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFFriendTrackerWidget_BP_OnFriendTrackerRefreshed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFFriendTrackerWidget Function BP_OnFriendTrackerRefreshed ***************

// ********** Begin Class UDMFFriendTrackerWidget Function GetObservedFriend ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFFriendTrackerWidget_GetObservedFriend_Statics
struct UHT_STATICS
{
	struct DMFFriendTrackerWidget_eventGetObservedFriend_Parms
	{
		ADMFPlayerAvatarCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friend Tracking" },
		{ "ModuleRelativePath", "Public/UI/DMFFriendTrackerWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObservedFriend constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObservedFriend constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObservedFriend Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFFriendTrackerWidget_eventGetObservedFriend_Parms, ReturnValue), Z_Construct_UClass_ADMFPlayerAvatarCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetObservedFriend Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFFriendTrackerWidget, nullptr, "GetObservedFriend", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFFriendTrackerWidget_eventGetObservedFriend_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFFriendTrackerWidget_eventGetObservedFriend_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFFriendTrackerWidget_GetObservedFriend(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFFriendTrackerWidget::execGetObservedFriend)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFPlayerAvatarCharacter**)Z_Param__Result=P_THIS->GetObservedFriend();
	P_NATIVE_END;
}
// ********** End Class UDMFFriendTrackerWidget Function GetObservedFriend *************************

// ********** Begin Class UDMFFriendTrackerWidget Function SetObservedFriend ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFFriendTrackerWidget_SetObservedFriend_Statics
struct UHT_STATICS
{
	struct DMFFriendTrackerWidget_eventSetObservedFriend_Parms
	{
		ADMFPlayerAvatarCharacter* InFriendAvatar;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Social|Friend Tracking" },
		{ "ModuleRelativePath", "Public/UI/DMFFriendTrackerWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetObservedFriend constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InFriendAvatar;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetObservedFriend constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetObservedFriend Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InFriendAvatar = { "InFriendAvatar", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFFriendTrackerWidget_eventSetObservedFriend_Parms, InFriendAvatar), Z_Construct_UClass_ADMFPlayerAvatarCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InFriendAvatar,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetObservedFriend Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFFriendTrackerWidget, nullptr, "SetObservedFriend", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFFriendTrackerWidget_eventSetObservedFriend_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFFriendTrackerWidget_eventSetObservedFriend_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFFriendTrackerWidget_SetObservedFriend(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFFriendTrackerWidget::execSetObservedFriend)
{
	P_GET_OBJECT(ADMFPlayerAvatarCharacter,Z_Param_InFriendAvatar);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetObservedFriend(Z_Param_InFriendAvatar);
	P_NATIVE_END;
}
// ********** End Class UDMFFriendTrackerWidget Function SetObservedFriend *************************

// ********** Begin Class UDMFFriendTrackerWidget **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFFriendTrackerWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Owner-local world-space friend marker. It reads already replicated avatar transforms and therefore\n * requires no distance RPC/tick replication. The persistent toggle lives in the authenticated account.\n */" },
#endif
		{ "IncludePath", "UI/DMFFriendTrackerWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFFriendTrackerWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owner-local world-space friend marker. It reads already replicated avatar transforms and therefore\nrequires no distance RPC/tick replication. The persistent toggle lives in the authenticated account." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackerPanel_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFFriendTrackerWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFFriendTrackerWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFFriendTrackerWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFFriendTrackerWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFFriendTrackerWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFFriendTrackerWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFFriendTrackerWidget constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TrackerPanel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FriendNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFFriendTrackerWidget constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetObservedFriend"), .Pointer = &UDMFFriendTrackerWidget::execGetObservedFriend },
		{ .NameUTF8 = UTF8TEXT("SetObservedFriend"), .Pointer = &UDMFFriendTrackerWidget::execSetObservedFriend },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFFriendTrackerWidget_BP_OnFriendTrackerRefreshed, "BP_OnFriendTrackerRefreshed" }, // b0d0f2ae88689f49ae8113feb454d618aad93573
		{ &Z_Construct_UFunction_UDMFFriendTrackerWidget_GetObservedFriend, "GetObservedFriend" }, // e099bda2a0b0afd19987872c1b510b44fccfad31
		{ &Z_Construct_UFunction_UDMFFriendTrackerWidget_SetObservedFriend, "SetObservedFriend" }, // d622b03aed594282ac89f9121ee05e563ce9d0b0
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFFriendTrackerWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFFriendTrackerWidget Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TrackerPanel = { "TrackerPanel", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFriendTrackerWidget, TrackerPanel), Z_Construct_UClass_UBorder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackerPanel_MetaData), NewProp_TrackerPanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_FriendNameText = { "FriendNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFriendTrackerWidget, FriendNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendNameText_MetaData), NewProp_FriendNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DistanceText = { "DistanceText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFFriendTrackerWidget, DistanceText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceText_MetaData), NewProp_DistanceText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TrackerPanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FriendNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DistanceText,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFFriendTrackerWidget Property Definitions *******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFFriendTrackerWidget,
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
static void UDMFFriendTrackerWidget_StaticRegisterNativesUDMFFriendTrackerWidget()
{
	UClass* Class = UDMFFriendTrackerWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFFriendTrackerWidget;
UClass* Z_Construct_UClass_UDMFFriendTrackerWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFFriendTrackerWidget;
		if (!Z_Registration_Info_UClass_UDMFFriendTrackerWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFFriendTrackerWidget"),
				Z_Registration_Info_UClass_UDMFFriendTrackerWidget.InnerSingleton,
				UDMFFriendTrackerWidget_StaticRegisterNativesUDMFFriendTrackerWidget,
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
		return Z_Registration_Info_UClass_UDMFFriendTrackerWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFFriendTrackerWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFFriendTrackerWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFFriendTrackerWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFFriendTrackerWidget::UDMFFriendTrackerWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFFriendTrackerWidget);
UDMFFriendTrackerWidget::~UDMFFriendTrackerWidget() {}
// ********** End Class UDMFFriendTrackerWidget ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFFriendTrackerWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFFriendTrackerWidget, TEXT("UDMFFriendTrackerWidget"), &Z_Registration_Info_UClass_UDMFFriendTrackerWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFFriendTrackerWidget), 1299653820U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFFriendTrackerWidget_h__Script_DigimonMMOFramework_2c2619f819af216ebb3f6bda56798730b40311a4{
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
