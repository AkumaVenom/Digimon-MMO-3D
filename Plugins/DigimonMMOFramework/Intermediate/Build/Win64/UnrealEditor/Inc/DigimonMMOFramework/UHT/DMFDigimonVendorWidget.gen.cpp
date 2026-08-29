// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFDigimonVendorWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFDigimonVendorWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UVerticalBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonVendorEntryButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorEntryPressed__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonVendorWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonVendorActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonVendorEntryButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonVendorWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFDigimonVendorEntryPressed *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorEntryPressed__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFDigimonVendorEntryPressed_Parms
	{
		EDMFDigimonVendorTransactionType TransactionType;
		FGuid Identifier;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFDigimonVendorEntryPressed constinit property declarations *********
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Identifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFDigimonVendorEntryPressed constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFDigimonVendorEntryPressed Property Definitions ********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorEntryPressed_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFDigimonVendorEntryPressed_Parms, Identifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Identifier,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFDigimonVendorEntryPressed Property Definitions **********************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFDigimonVendorEntryPressed__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonVendorEntryPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFDigimonVendorEntryPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorEntryPressed__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFDigimonVendorEntryPressed *******************************************

// ********** Begin Class UDMFDigimonVendorEntryButton Function HandlePressed **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorEntryButton_HandlePressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePressed constinit property declarations *************************
// ********** End Function HandlePressed constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorEntryButton, nullptr, "HandlePressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorEntryButton_HandlePressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorEntryButton::execHandlePressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePressed();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorEntryButton Function HandlePressed ************************

// ********** Begin Class UDMFDigimonVendorEntryButton Function InitializeVendorEntry **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorEntryButton_InitializeVendorEntry_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorEntryButton_eventInitializeVendorEntry_Parms
	{
		EDMFDigimonVendorTransactionType InTransactionType;
		FGuid InIdentifier;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeVendorEntry constinit property declarations *****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InTransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InTransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InIdentifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeVendorEntry constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeVendorEntry Property Definitions ****************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InTransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InTransactionType = { "InTransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorEntryButton_eventInitializeVendorEntry_Parms, InTransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InIdentifier = { "InIdentifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorEntryButton_eventInitializeVendorEntry_Parms, InIdentifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InTransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InTransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InIdentifier,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeVendorEntry Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorEntryButton, nullptr, "InitializeVendorEntry", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorEntryButton_eventInitializeVendorEntry_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorEntryButton_eventInitializeVendorEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorEntryButton_InitializeVendorEntry(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorEntryButton::execInitializeVendorEntry)
{
	P_GET_ENUM(EDMFDigimonVendorTransactionType,Z_Param_InTransactionType);
	P_GET_STRUCT(FGuid,Z_Param_InIdentifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeVendorEntry(EDMFDigimonVendorTransactionType(Z_Param_InTransactionType),Z_Param_InIdentifier);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorEntryButton Function InitializeVendorEntry ****************

// ********** Begin Class UDMFDigimonVendorEntryButton *********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFDigimonVendorEntryButton_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lightweight native list button carrying a server-owned stock GUID or owned Digimon GUID. */" },
#endif
		{ "IncludePath", "UI/DMFDigimonVendorWidget.h" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lightweight native list button carrying a server-owned stock GUID or owned Digimon GUID." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnVendorEntryPressed_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransactionType_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Identifier_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFDigimonVendorEntryButton constinit property declarations *************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnVendorEntryPressed;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Identifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFDigimonVendorEntryButton constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandlePressed"), .Pointer = &UDMFDigimonVendorEntryButton::execHandlePressed },
		{ .NameUTF8 = UTF8TEXT("InitializeVendorEntry"), .Pointer = &UDMFDigimonVendorEntryButton::execInitializeVendorEntry },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFDigimonVendorEntryButton_HandlePressed, "HandlePressed" }, // c894932eae776eed2e5dff5eac78d75e0eb769c7
		{ &Z_Construct_UFunction_UDMFDigimonVendorEntryButton_InitializeVendorEntry, "InitializeVendorEntry" }, // 0e924bd8a4c0f0e53007f5eec093002dd2862fde
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFDigimonVendorEntryButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFDigimonVendorEntryButton Property Definitions ************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnVendorEntryPressed = { "OnVendorEntryPressed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorEntryButton, OnVendorEntryPressed), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFDigimonVendorEntryPressed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnVendorEntryPressed_MetaData), NewProp_OnVendorEntryPressed_MetaData) }; // 59ab315b26c86f4fc1fba2c5c2071cbd423b6093
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorEntryButton, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransactionType_MetaData), NewProp_TransactionType_MetaData) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorEntryButton, Identifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Identifier_MetaData), NewProp_Identifier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnVendorEntryPressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Identifier,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFDigimonVendorEntryButton Property Definitions **************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UButton,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFDigimonVendorEntryButton,
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
static void UDMFDigimonVendorEntryButton_StaticRegisterNativesUDMFDigimonVendorEntryButton()
{
	UClass* Class = UDMFDigimonVendorEntryButton::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFDigimonVendorEntryButton;
UClass* Z_Construct_UClass_UDMFDigimonVendorEntryButton(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFDigimonVendorEntryButton;
		if (!Z_Registration_Info_UClass_UDMFDigimonVendorEntryButton.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonVendorEntryButton"),
				Z_Registration_Info_UClass_UDMFDigimonVendorEntryButton.InnerSingleton,
				UDMFDigimonVendorEntryButton_StaticRegisterNativesUDMFDigimonVendorEntryButton,
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
		return Z_Registration_Info_UClass_UDMFDigimonVendorEntryButton.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFDigimonVendorEntryButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFDigimonVendorEntryButton.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFDigimonVendorEntryButton.OuterSingleton;
}
#undef UHT_STATICS
UDMFDigimonVendorEntryButton::UDMFDigimonVendorEntryButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFDigimonVendorEntryButton);
UDMFDigimonVendorEntryButton::~UDMFDigimonVendorEntryButton() {}
// ********** End Class UDMFDigimonVendorEntryButton ***********************************************

// ********** Begin Class UDMFDigimonVendorWidget Function BP_OnVendorRefreshed ********************
static FName NAME_UDMFDigimonVendorWidget_BP_OnVendorRefreshed = FName(TEXT("BP_OnVendorRefreshed"));
void UDMFDigimonVendorWidget::BP_OnVendorRefreshed()
{
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonVendorWidget_BP_OnVendorRefreshed);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_BP_OnVendorRefreshed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVendorRefreshed constinit property declarations ******************
// ********** End Function BP_OnVendorRefreshed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "BP_OnVendorRefreshed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_BP_OnVendorRefreshed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFDigimonVendorWidget Function BP_OnVendorRefreshed **********************

// ********** Begin Class UDMFDigimonVendorWidget Function BP_OnVendorSelectionChanged *************
struct DMFDigimonVendorWidget_eventBP_OnVendorSelectionChanged_Parms
{
	EDMFDigimonVendorTransactionType TransactionType;
	FGuid Identifier;
};
static FName NAME_UDMFDigimonVendorWidget_BP_OnVendorSelectionChanged = FName(TEXT("BP_OnVendorSelectionChanged"));
void UDMFDigimonVendorWidget::BP_OnVendorSelectionChanged(EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier)
{
	DMFDigimonVendorWidget_eventBP_OnVendorSelectionChanged_Parms Parms;
	Parms.TransactionType=TransactionType;
	Parms.Identifier=Identifier;
	UFunction* Func = FindFunctionChecked(NAME_UDMFDigimonVendorWidget_BP_OnVendorSelectionChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_BP_OnVendorSelectionChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVendorSelectionChanged constinit property declarations ***********
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Identifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnVendorSelectionChanged constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnVendorSelectionChanged Property Definitions **********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventBP_OnVendorSelectionChanged_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventBP_OnVendorSelectionChanged_Parms, Identifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Identifier,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnVendorSelectionChanged Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "BP_OnVendorSelectionChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFDigimonVendorWidget_eventBP_OnVendorSelectionChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFDigimonVendorWidget_eventBP_OnVendorSelectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_BP_OnVendorSelectionChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFDigimonVendorWidget Function BP_OnVendorSelectionChanged ***************

// ********** Begin Class UDMFDigimonVendorWidget Function GetVendor *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_GetVendor_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorWidget_eventGetVendor_Parms
	{
		ADMFDigimonVendorActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetVendor constinit property declarations *****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVendor constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVendor Property Definitions ****************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventGetVendor_Parms, ReturnValue), Z_Construct_UClass_ADMFDigimonVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetVendor Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "GetVendor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorWidget_eventGetVendor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorWidget_eventGetVendor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_GetVendor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execGetVendor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFDigimonVendorActor**)Z_Param__Result=P_THIS->GetVendor();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function GetVendor *********************************

// ********** Begin Class UDMFDigimonVendorWidget Function GetVendorTab ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_GetVendorTab_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorWidget_eventGetVendorTab_Parms
	{
		EDMFDigimonVendorTransactionType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetVendorTab constinit property declarations **************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVendorTab constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVendorTab Property Definitions *************************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventGetVendorTab_Parms, ReturnValue), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetVendorTab Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "GetVendorTab", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorWidget_eventGetVendorTab_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorWidget_eventGetVendorTab_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_GetVendorTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execGetVendorTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDMFDigimonVendorTransactionType*)Z_Param__Result=P_THIS->GetVendorTab();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function GetVendorTab ******************************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleBankChanged ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleBankChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBankChanged constinit property declarations *********************
// ********** End Function HandleBankChanged constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleBankChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleBankChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleBankChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBankChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleBankChanged *************************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleBuyTabClicked *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleBuyTabClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBuyTabClicked constinit property declarations *******************
// ********** End Function HandleBuyTabClicked constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleBuyTabClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleBuyTabClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleBuyTabClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBuyTabClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleBuyTabClicked ***********************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleCloseClicked **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleCloseClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCloseClicked constinit property declarations ********************
// ********** End Function HandleCloseClicked constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleCloseClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleCloseClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleCloseClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCloseClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleCloseClicked ************************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleEntryPressed **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleEntryPressed_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorWidget_eventHandleEntryPressed_Parms
	{
		EDMFDigimonVendorTransactionType TransactionType;
		FGuid Identifier;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleEntryPressed constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Identifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleEntryPressed constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleEntryPressed Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventHandleEntryPressed_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventHandleEntryPressed_Parms, Identifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Identifier,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleEntryPressed Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleEntryPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorWidget_eventHandleEntryPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorWidget_eventHandleEntryPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleEntryPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleEntryPressed)
{
	P_GET_ENUM(EDMFDigimonVendorTransactionType,Z_Param_TransactionType);
	P_GET_STRUCT(FGuid,Z_Param_Identifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleEntryPressed(EDMFDigimonVendorTransactionType(Z_Param_TransactionType),Z_Param_Identifier);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleEntryPressed ************************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleHeaderTimer ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleHeaderTimer_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleHeaderTimer constinit property declarations *********************
// ********** End Function HandleHeaderTimer constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleHeaderTimer", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleHeaderTimer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleHeaderTimer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleHeaderTimer();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleHeaderTimer *************************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleMoneyChanged **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleMoneyChanged_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorWidget_eventHandleMoneyChanged_Parms
	{
		int64 NewMoney;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleMoneyChanged constinit property declarations ********************
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NewMoney;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleMoneyChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleMoneyChanged Property Definitions *******************************
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NewMoney = { "NewMoney", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventHandleMoneyChanged_Parms, NewMoney), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewMoney,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleMoneyChanged Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleMoneyChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorWidget_eventHandleMoneyChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorWidget_eventHandleMoneyChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleMoneyChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleMoneyChanged)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_NewMoney);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMoneyChanged(Z_Param_NewMoney);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleMoneyChanged ************************

// ********** Begin Class UDMFDigimonVendorWidget Function HandlePartyChanged **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandlePartyChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePartyChanged constinit property declarations ********************
// ********** End Function HandlePartyChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandlePartyChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandlePartyChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandlePartyChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePartyChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandlePartyChanged ************************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleSellTabClicked ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleSellTabClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSellTabClicked constinit property declarations ******************
// ********** End Function HandleSellTabClicked constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleSellTabClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleSellTabClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleSellTabClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSellTabClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleSellTabClicked **********************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleTransactionClicked ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleTransactionClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleTransactionClicked constinit property declarations **************
// ********** End Function HandleTransactionClicked constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleTransactionClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleTransactionClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleTransactionClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleTransactionClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleTransactionClicked ******************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleVendorConfigurationChanged ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorConfigurationChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleVendorConfigurationChanged constinit property declarations ******
// ********** End Function HandleVendorConfigurationChanged constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleVendorConfigurationChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorConfigurationChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleVendorConfigurationChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleVendorConfigurationChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleVendorConfigurationChanged **********

// ********** Begin Class UDMFDigimonVendorWidget Function HandleVendorEnabledChanged **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorEnabledChanged_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorWidget_eventHandleVendorEnabledChanged_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleVendorEnabledChanged constinit property declarations ************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFDigimonVendorWidget_eventHandleVendorEnabledChanged_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleVendorEnabledChanged constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleVendorEnabledChanged Property Definitions ***********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonVendorWidget_eventHandleVendorEnabledChanged_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleVendorEnabledChanged Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleVendorEnabledChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorWidget_eventHandleVendorEnabledChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorWidget_eventHandleVendorEnabledChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorEnabledChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleVendorEnabledChanged)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleVendorEnabledChanged(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleVendorEnabledChanged ****************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleVendorStockChanged ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorStockChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleVendorStockChanged constinit property declarations **************
// ********** End Function HandleVendorStockChanged constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleVendorStockChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorStockChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleVendorStockChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleVendorStockChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleVendorStockChanged ******************

// ********** Begin Class UDMFDigimonVendorWidget Function HandleVendorTransactionResult ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorTransactionResult_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms
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
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleVendorTransactionResult constinit property declarations *********
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Identifier;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Price;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NewMoney;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleVendorTransactionResult constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleVendorTransactionResult Property Definitions ********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Identifier = { "Identifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms, Identifier), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_Price = { "Price", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms, Price), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NewMoney = { "NewMoney", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms, NewMoney), METADATA_PARAMS(0, nullptr) };
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
// ********** End Function HandleVendorTransactionResult Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "HandleVendorTransactionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorWidget_eventHandleVendorTransactionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorTransactionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execHandleVendorTransactionResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_ENUM(EDMFDigimonVendorTransactionType,Z_Param_TransactionType);
	P_GET_STRUCT(FGuid,Z_Param_Identifier);
	P_GET_PROPERTY(FInt64Property,Z_Param_Price);
	P_GET_PROPERTY(FInt64Property,Z_Param_NewMoney);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleVendorTransactionResult(Z_Param_bSuccess,Z_Param_Message,EDMFDigimonVendorTransactionType(Z_Param_TransactionType),Z_Param_Identifier,Z_Param_Price,Z_Param_NewMoney);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function HandleVendorTransactionResult *************

// ********** Begin Class UDMFDigimonVendorWidget Function InitializeVendor ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_InitializeVendor_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorWidget_eventInitializeVendor_Parms
	{
		ADMFDigimonVendorActor* InVendor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeVendor constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InVendor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeVendor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeVendor Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InVendor = { "InVendor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventInitializeVendor_Parms, InVendor), Z_Construct_UClass_ADMFDigimonVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InVendor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeVendor Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "InitializeVendor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorWidget_eventInitializeVendor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorWidget_eventInitializeVendor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_InitializeVendor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execInitializeVendor)
{
	P_GET_OBJECT(ADMFDigimonVendorActor,Z_Param_InVendor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeVendor(Z_Param_InVendor);
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function InitializeVendor **************************

// ********** Begin Class UDMFDigimonVendorWidget Function RefreshVendorUI *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_RefreshVendorUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshVendorUI constinit property declarations ***********************
// ********** End Function RefreshVendorUI constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "RefreshVendorUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_RefreshVendorUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execRefreshVendorUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshVendorUI();
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function RefreshVendorUI ***************************

// ********** Begin Class UDMFDigimonVendorWidget Function SetVendorTab ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFDigimonVendorWidget_SetVendorTab_Statics
struct UHT_STATICS
{
	struct DMFDigimonVendorWidget_eventSetVendorTab_Parms
	{
		EDMFDigimonVendorTransactionType NewTab;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVendorTab constinit property declarations **************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewTab_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewTab;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVendorTab constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVendorTab Property Definitions *************************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewTab_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewTab = { "NewTab", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFDigimonVendorWidget_eventSetVendorTab_Parms, NewTab), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // 6676c757df95095b2e84331cef8acecfb8735f51
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTab_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTab,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetVendorTab Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFDigimonVendorWidget, nullptr, "SetVendorTab", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFDigimonVendorWidget_eventSetVendorTab_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFDigimonVendorWidget_eventSetVendorTab_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFDigimonVendorWidget_SetVendorTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFDigimonVendorWidget::execSetVendorTab)
{
	P_GET_ENUM(EDMFDigimonVendorTransactionType,Z_Param_NewTab);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVendorTab(EDMFDigimonVendorTransactionType(Z_Param_NewTab));
	P_NATIVE_END;
}
// ********** End Class UDMFDigimonVendorWidget Function SetVendorTab ******************************

// ********** Begin Class UDMFDigimonVendorWidget **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFDigimonVendorWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Polished native BUY/SELL Digimon vendor window. Blueprint subclasses may bind/replace the same public contract. */" },
#endif
		{ "IncludePath", "UI/DMFDigimonVendorWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Polished native BUY/SELL Digimon vendor window. Blueprint subclasses may bind/replace the same public contract." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorSubtitleText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoneyText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuyTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SellTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryListBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailPortrait_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailStatsText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailValueText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorStatusText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransactionButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransactionButtonText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFDigimonVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFDigimonVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFDigimonVendorWidget constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorSubtitleText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoneyText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RotationText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BuyTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SellTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EntryListBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailPortrait;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailStatsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailValueText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TransactionButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TransactionButtonText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFDigimonVendorWidget constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetVendor"), .Pointer = &UDMFDigimonVendorWidget::execGetVendor },
		{ .NameUTF8 = UTF8TEXT("GetVendorTab"), .Pointer = &UDMFDigimonVendorWidget::execGetVendorTab },
		{ .NameUTF8 = UTF8TEXT("HandleBankChanged"), .Pointer = &UDMFDigimonVendorWidget::execHandleBankChanged },
		{ .NameUTF8 = UTF8TEXT("HandleBuyTabClicked"), .Pointer = &UDMFDigimonVendorWidget::execHandleBuyTabClicked },
		{ .NameUTF8 = UTF8TEXT("HandleCloseClicked"), .Pointer = &UDMFDigimonVendorWidget::execHandleCloseClicked },
		{ .NameUTF8 = UTF8TEXT("HandleEntryPressed"), .Pointer = &UDMFDigimonVendorWidget::execHandleEntryPressed },
		{ .NameUTF8 = UTF8TEXT("HandleHeaderTimer"), .Pointer = &UDMFDigimonVendorWidget::execHandleHeaderTimer },
		{ .NameUTF8 = UTF8TEXT("HandleMoneyChanged"), .Pointer = &UDMFDigimonVendorWidget::execHandleMoneyChanged },
		{ .NameUTF8 = UTF8TEXT("HandlePartyChanged"), .Pointer = &UDMFDigimonVendorWidget::execHandlePartyChanged },
		{ .NameUTF8 = UTF8TEXT("HandleSellTabClicked"), .Pointer = &UDMFDigimonVendorWidget::execHandleSellTabClicked },
		{ .NameUTF8 = UTF8TEXT("HandleTransactionClicked"), .Pointer = &UDMFDigimonVendorWidget::execHandleTransactionClicked },
		{ .NameUTF8 = UTF8TEXT("HandleVendorConfigurationChanged"), .Pointer = &UDMFDigimonVendorWidget::execHandleVendorConfigurationChanged },
		{ .NameUTF8 = UTF8TEXT("HandleVendorEnabledChanged"), .Pointer = &UDMFDigimonVendorWidget::execHandleVendorEnabledChanged },
		{ .NameUTF8 = UTF8TEXT("HandleVendorStockChanged"), .Pointer = &UDMFDigimonVendorWidget::execHandleVendorStockChanged },
		{ .NameUTF8 = UTF8TEXT("HandleVendorTransactionResult"), .Pointer = &UDMFDigimonVendorWidget::execHandleVendorTransactionResult },
		{ .NameUTF8 = UTF8TEXT("InitializeVendor"), .Pointer = &UDMFDigimonVendorWidget::execInitializeVendor },
		{ .NameUTF8 = UTF8TEXT("RefreshVendorUI"), .Pointer = &UDMFDigimonVendorWidget::execRefreshVendorUI },
		{ .NameUTF8 = UTF8TEXT("SetVendorTab"), .Pointer = &UDMFDigimonVendorWidget::execSetVendorTab },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_BP_OnVendorRefreshed, "BP_OnVendorRefreshed" }, // 6228123b2d3fecc3cfe2cc79b5f27311b596814b
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_BP_OnVendorSelectionChanged, "BP_OnVendorSelectionChanged" }, // 92bb8814b456e2353da59f87ac03a950d43bcd1d
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_GetVendor, "GetVendor" }, // 09d7864f14e795e85a7315a56b04a158a662a264
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_GetVendorTab, "GetVendorTab" }, // c42f2c26b4a8d8c437d630b77f1a2f7f942f8120
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleBankChanged, "HandleBankChanged" }, // 6853d0872c7cbc2b7d39089677121ca3f9618e95
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleBuyTabClicked, "HandleBuyTabClicked" }, // c7b784eed9b31923071c794f37be4ba966360216
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleCloseClicked, "HandleCloseClicked" }, // a39fddcf0b90921692dc564a8ec5e89603722a11
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleEntryPressed, "HandleEntryPressed" }, // e3513040d1f89238dea24f2466f6020f659a8b15
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleHeaderTimer, "HandleHeaderTimer" }, // 34d3e18d356c268f0c5e2cc5f4274ca62632da89
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleMoneyChanged, "HandleMoneyChanged" }, // 4fb6f540e06547e60c58dc527abd370224816dc9
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandlePartyChanged, "HandlePartyChanged" }, // a90056aa489db9cfdf2ed26a52e1192ec8718e5c
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleSellTabClicked, "HandleSellTabClicked" }, // 549437069aa3df70d7f2acee5cb955edffcfe9fc
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleTransactionClicked, "HandleTransactionClicked" }, // f6f822d8ef4c59b0c5fe754f624fd7da4b6f7448
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorConfigurationChanged, "HandleVendorConfigurationChanged" }, // 449ce69b6507b014650a695928ab319c33c31e5a
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorEnabledChanged, "HandleVendorEnabledChanged" }, // 55f36fe934248a84eec70bdb0c1745292636b21a
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorStockChanged, "HandleVendorStockChanged" }, // 72134130ba05b8ebae07f7160795294c9ecd310e
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_HandleVendorTransactionResult, "HandleVendorTransactionResult" }, // 5c748344256c2d26cea23a23c28a672f5b03783d
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_InitializeVendor, "InitializeVendor" }, // 82110677d26c967f3334ce2b1ab5a7014bb80618
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_RefreshVendorUI, "RefreshVendorUI" }, // 64e8511af799bee2b8a5cb948ee24de012b71a91
		{ &Z_Construct_UFunction_UDMFDigimonVendorWidget_SetVendorTab, "SetVendorTab" }, // 4d79fd59ac0e8802aace76662980722187609061
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFDigimonVendorWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFDigimonVendorWidget Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorNameText = { "VendorNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, VendorNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorNameText_MetaData), NewProp_VendorNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorSubtitleText = { "VendorSubtitleText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, VendorSubtitleText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorSubtitleText_MetaData), NewProp_VendorSubtitleText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MoneyText = { "MoneyText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, MoneyText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoneyText_MetaData), NewProp_MoneyText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RotationText = { "RotationText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, RotationText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationText_MetaData), NewProp_RotationText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BuyTabButton = { "BuyTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, BuyTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuyTabButton_MetaData), NewProp_BuyTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SellTabButton = { "SellTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, SellTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SellTabButton_MetaData), NewProp_SellTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_EntryListBox = { "EntryListBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, EntryListBox), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryListBox_MetaData), NewProp_EntryListBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailPortrait = { "DetailPortrait", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, DetailPortrait), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailPortrait_MetaData), NewProp_DetailPortrait_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailNameText = { "DetailNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, DetailNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailNameText_MetaData), NewProp_DetailNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailMetaText = { "DetailMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, DetailMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailMetaText_MetaData), NewProp_DetailMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailStatsText = { "DetailStatsText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, DetailStatsText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailStatsText_MetaData), NewProp_DetailStatsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailValueText = { "DetailValueText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, DetailValueText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailValueText_MetaData), NewProp_DetailValueText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorStatusText = { "VendorStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, VendorStatusText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorStatusText_MetaData), NewProp_VendorStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TransactionButton = { "TransactionButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, TransactionButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransactionButton_MetaData), NewProp_TransactionButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TransactionButtonText = { "TransactionButtonText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, TransactionButtonText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransactionButtonText_MetaData), NewProp_TransactionButtonText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CloseButton = { "CloseButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFDigimonVendorWidget, CloseButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButton_MetaData), NewProp_CloseButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorSubtitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MoneyText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RotationText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BuyTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SellTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EntryListBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailPortrait,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailStatsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailValueText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionButtonText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CloseButton,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFDigimonVendorWidget Property Definitions *******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFDigimonVendorWidget,
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
static void UDMFDigimonVendorWidget_StaticRegisterNativesUDMFDigimonVendorWidget()
{
	UClass* Class = UDMFDigimonVendorWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFDigimonVendorWidget;
UClass* Z_Construct_UClass_UDMFDigimonVendorWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFDigimonVendorWidget;
		if (!Z_Registration_Info_UClass_UDMFDigimonVendorWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFDigimonVendorWidget"),
				Z_Registration_Info_UClass_UDMFDigimonVendorWidget.InnerSingleton,
				UDMFDigimonVendorWidget_StaticRegisterNativesUDMFDigimonVendorWidget,
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
		return Z_Registration_Info_UClass_UDMFDigimonVendorWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFDigimonVendorWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFDigimonVendorWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFDigimonVendorWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFDigimonVendorWidget::UDMFDigimonVendorWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFDigimonVendorWidget);
UDMFDigimonVendorWidget::~UDMFDigimonVendorWidget() {}
// ********** End Class UDMFDigimonVendorWidget ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFDigimonVendorEntryButton, TEXT("UDMFDigimonVendorEntryButton"), &Z_Registration_Info_UClass_UDMFDigimonVendorEntryButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFDigimonVendorEntryButton), 1772032443U) },
		{ Z_Construct_UClass_UDMFDigimonVendorWidget, TEXT("UDMFDigimonVendorWidget"), &Z_Registration_Info_UClass_UDMFDigimonVendorWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFDigimonVendorWidget), 929329392U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h__Script_DigimonMMOFramework_9f61d6ee6188a466e448bc89d14395e3d3c805f2{
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
