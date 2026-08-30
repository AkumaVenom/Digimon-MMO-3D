// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFItemVendorWidget.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFItemVendorWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UVerticalBox(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemVendorEntryButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorEntryPressed__DelegateSignature(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemVendorWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFItemVendorActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemVendorEntryButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemVendorWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FDMFItemVendorEntryPressed ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorEntryPressed__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_DigimonMMOFramework_eventDMFItemVendorEntryPressed_Parms
	{
		EDMFItemVendorTransactionType TransactionType;
		FGuid StockId;
		FPrimaryAssetId ItemAssetId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDMFItemVendorEntryPressed constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StockId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDMFItemVendorEntryPressed constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDMFItemVendorEntryPressed Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorEntryPressed_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StockId = { "StockId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorEntryPressed_Parms, StockId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DigimonMMOFramework_eventDMFItemVendorEntryPressed_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FDMFItemVendorEntryPressed Property Definitions *************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework, nullptr, "DMFItemVendorEntryPressed__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemVendorEntryPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_DigimonMMOFramework_eventDMFItemVendorEntryPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorEntryPressed__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FDMFItemVendorEntryPressed **********************************************

// ********** Begin Class UDMFItemVendorEntryButton Function HandlePressed *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorEntryButton_HandlePressed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePressed constinit property declarations *************************
// ********** End Function HandlePressed constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorEntryButton, nullptr, "HandlePressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorEntryButton_HandlePressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorEntryButton::execHandlePressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePressed();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorEntryButton Function HandlePressed ***************************

// ********** Begin Class UDMFItemVendorEntryButton Function InitializeItemVendorEntry *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorEntryButton_InitializeItemVendorEntry_Statics
struct UHT_STATICS
{
	struct DMFItemVendorEntryButton_eventInitializeItemVendorEntry_Parms
	{
		EDMFItemVendorTransactionType InTransactionType;
		FGuid InStockId;
		FPrimaryAssetId InItemAssetId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeItemVendorEntry constinit property declarations *************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InTransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InTransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InStockId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InItemAssetId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeItemVendorEntry constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeItemVendorEntry Property Definitions ************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_InTransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_InTransactionType = { "InTransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorEntryButton_eventInitializeItemVendorEntry_Parms, InTransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InStockId = { "InStockId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorEntryButton_eventInitializeItemVendorEntry_Parms, InStockId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_InItemAssetId = { "InItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorEntryButton_eventInitializeItemVendorEntry_Parms, InItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InTransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InTransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InStockId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InItemAssetId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeItemVendorEntry Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorEntryButton, nullptr, "InitializeItemVendorEntry", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorEntryButton_eventInitializeItemVendorEntry_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorEntryButton_eventInitializeItemVendorEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorEntryButton_InitializeItemVendorEntry(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorEntryButton::execInitializeItemVendorEntry)
{
	P_GET_ENUM(EDMFItemVendorTransactionType,Z_Param_InTransactionType);
	P_GET_STRUCT(FGuid,Z_Param_InStockId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_InItemAssetId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeItemVendorEntry(EDMFItemVendorTransactionType(Z_Param_InTransactionType),Z_Param_InStockId,Z_Param_InItemAssetId);
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorEntryButton Function InitializeItemVendorEntry ***************

// ********** Begin Class UDMFItemVendorEntryButton ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFItemVendorEntryButton_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native list button carrying only selection identity; prices and quantities are never trusted from this widget. */" },
#endif
		{ "IncludePath", "UI/DMFItemVendorWidget.h" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native list button carrying only selection identity; prices and quantities are never trusted from this widget." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnItemVendorEntryPressed_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransactionType_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StockId_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemAssetId_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFItemVendorEntryButton constinit property declarations ****************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemVendorEntryPressed;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StockId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFItemVendorEntryButton constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandlePressed"), .Pointer = &UDMFItemVendorEntryButton::execHandlePressed },
		{ .NameUTF8 = UTF8TEXT("InitializeItemVendorEntry"), .Pointer = &UDMFItemVendorEntryButton::execInitializeItemVendorEntry },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFItemVendorEntryButton_HandlePressed, "HandlePressed" }, // 80432dfa8fdc4f2d813174fd6f1cd655326c34e8
		{ &Z_Construct_UFunction_UDMFItemVendorEntryButton_InitializeItemVendorEntry, "InitializeItemVendorEntry" }, // 366bcf7242cf89378e99e39a5614500082b67115
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFItemVendorEntryButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFItemVendorEntryButton Property Definitions ***************************
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnItemVendorEntryPressed = { "OnItemVendorEntryPressed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorEntryButton, OnItemVendorEntryPressed), Z_Construct_UDelegateFunction_DigimonMMOFramework_DMFItemVendorEntryPressed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnItemVendorEntryPressed_MetaData), NewProp_OnItemVendorEntryPressed_MetaData) }; // 899afd002b0cba19f522965a97985bfb04b49231
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorEntryButton, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransactionType_MetaData), NewProp_TransactionType_MetaData) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StockId = { "StockId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorEntryButton, StockId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StockId_MetaData), NewProp_StockId_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorEntryButton, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemAssetId_MetaData), NewProp_ItemAssetId_MetaData) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnItemVendorEntryPressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFItemVendorEntryButton Property Definitions *****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UButton,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFItemVendorEntryButton,
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
static void UDMFItemVendorEntryButton_StaticRegisterNativesUDMFItemVendorEntryButton()
{
	UClass* Class = UDMFItemVendorEntryButton::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFItemVendorEntryButton;
UClass* Z_Construct_UClass_UDMFItemVendorEntryButton(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFItemVendorEntryButton;
		if (!Z_Registration_Info_UClass_UDMFItemVendorEntryButton.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFItemVendorEntryButton"),
				Z_Registration_Info_UClass_UDMFItemVendorEntryButton.InnerSingleton,
				UDMFItemVendorEntryButton_StaticRegisterNativesUDMFItemVendorEntryButton,
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
		return Z_Registration_Info_UClass_UDMFItemVendorEntryButton.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFItemVendorEntryButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFItemVendorEntryButton.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFItemVendorEntryButton.OuterSingleton;
}
#undef UHT_STATICS
UDMFItemVendorEntryButton::UDMFItemVendorEntryButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFItemVendorEntryButton);
UDMFItemVendorEntryButton::~UDMFItemVendorEntryButton() {}
// ********** End Class UDMFItemVendorEntryButton **************************************************

// ********** Begin Class UDMFItemVendorWidget Function BP_OnVendorQuantityChanged *****************
struct DMFItemVendorWidget_eventBP_OnVendorQuantityChanged_Parms
{
	int32 Quantity;
};
static FName NAME_UDMFItemVendorWidget_BP_OnVendorQuantityChanged = FName(TEXT("BP_OnVendorQuantityChanged"));
void UDMFItemVendorWidget::BP_OnVendorQuantityChanged(int32 Quantity)
{
	DMFItemVendorWidget_eventBP_OnVendorQuantityChanged_Parms Parms;
	Parms.Quantity=Quantity;
	UFunction* Func = FindFunctionChecked(NAME_UDMFItemVendorWidget_BP_OnVendorQuantityChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_BP_OnVendorQuantityChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVendorQuantityChanged constinit property declarations ************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnVendorQuantityChanged constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnVendorQuantityChanged Property Definitions ***********************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventBP_OnVendorQuantityChanged_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Quantity,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnVendorQuantityChanged Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "BP_OnVendorQuantityChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFItemVendorWidget_eventBP_OnVendorQuantityChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFItemVendorWidget_eventBP_OnVendorQuantityChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_BP_OnVendorQuantityChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFItemVendorWidget Function BP_OnVendorQuantityChanged *******************

// ********** Begin Class UDMFItemVendorWidget Function BP_OnVendorRefreshed ***********************
static FName NAME_UDMFItemVendorWidget_BP_OnVendorRefreshed = FName(TEXT("BP_OnVendorRefreshed"));
void UDMFItemVendorWidget::BP_OnVendorRefreshed()
{
	UFunction* Func = FindFunctionChecked(NAME_UDMFItemVendorWidget_BP_OnVendorRefreshed);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_BP_OnVendorRefreshed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVendorRefreshed constinit property declarations ******************
// ********** End Function BP_OnVendorRefreshed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "BP_OnVendorRefreshed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_BP_OnVendorRefreshed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFItemVendorWidget Function BP_OnVendorRefreshed *************************

// ********** Begin Class UDMFItemVendorWidget Function BP_OnVendorSelectionChanged ****************
struct DMFItemVendorWidget_eventBP_OnVendorSelectionChanged_Parms
{
	EDMFItemVendorTransactionType TransactionType;
	FGuid StockId;
	FPrimaryAssetId ItemAssetId;
};
static FName NAME_UDMFItemVendorWidget_BP_OnVendorSelectionChanged = FName(TEXT("BP_OnVendorSelectionChanged"));
void UDMFItemVendorWidget::BP_OnVendorSelectionChanged(EDMFItemVendorTransactionType TransactionType, FGuid StockId, FPrimaryAssetId ItemAssetId)
{
	DMFItemVendorWidget_eventBP_OnVendorSelectionChanged_Parms Parms;
	Parms.TransactionType=TransactionType;
	Parms.StockId=StockId;
	Parms.ItemAssetId=ItemAssetId;
	UFunction* Func = FindFunctionChecked(NAME_UDMFItemVendorWidget_BP_OnVendorSelectionChanged);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_BP_OnVendorSelectionChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnVendorSelectionChanged constinit property declarations ***********
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StockId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnVendorSelectionChanged constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnVendorSelectionChanged Property Definitions **********************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventBP_OnVendorSelectionChanged_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StockId = { "StockId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventBP_OnVendorSelectionChanged_Parms, StockId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventBP_OnVendorSelectionChanged_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnVendorSelectionChanged Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "BP_OnVendorSelectionChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFItemVendorWidget_eventBP_OnVendorSelectionChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFItemVendorWidget_eventBP_OnVendorSelectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_BP_OnVendorSelectionChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFItemVendorWidget Function BP_OnVendorSelectionChanged ******************

// ********** Begin Class UDMFItemVendorWidget Function GetSelectedQuantity ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_GetSelectedQuantity_Statics
struct UHT_STATICS
{
	struct DMFItemVendorWidget_eventGetSelectedQuantity_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedQuantity constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedQuantity constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedQuantity Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventGetSelectedQuantity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSelectedQuantity Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "GetSelectedQuantity", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorWidget_eventGetSelectedQuantity_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorWidget_eventGetSelectedQuantity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_GetSelectedQuantity(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execGetSelectedQuantity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetSelectedQuantity();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function GetSelectedQuantity **************************

// ********** Begin Class UDMFItemVendorWidget Function GetVendor **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_GetVendor_Statics
struct UHT_STATICS
{
	struct DMFItemVendorWidget_eventGetVendor_Parms
	{
		ADMFItemVendorActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetVendor constinit property declarations *****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVendor constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVendor Property Definitions ****************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventGetVendor_Parms, ReturnValue), Z_Construct_UClass_ADMFItemVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetVendor Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "GetVendor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorWidget_eventGetVendor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorWidget_eventGetVendor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_GetVendor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execGetVendor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFItemVendorActor**)Z_Param__Result=P_THIS->GetVendor();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function GetVendor ************************************

// ********** Begin Class UDMFItemVendorWidget Function GetVendorTab *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_GetVendorTab_Statics
struct UHT_STATICS
{
	struct DMFItemVendorWidget_eventGetVendorTab_Parms
	{
		EDMFItemVendorTransactionType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
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
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventGetVendorTab_Parms, ReturnValue), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetVendorTab Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "GetVendorTab", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorWidget_eventGetVendorTab_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorWidget_eventGetVendorTab_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_GetVendorTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execGetVendorTab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDMFItemVendorTransactionType*)Z_Param__Result=P_THIS->GetVendorTab();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function GetVendorTab *********************************

// ********** Begin Class UDMFItemVendorWidget Function HandleBuyTabClicked ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleBuyTabClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBuyTabClicked constinit property declarations *******************
// ********** End Function HandleBuyTabClicked constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleBuyTabClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleBuyTabClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleBuyTabClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBuyTabClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleBuyTabClicked **************************

// ********** Begin Class UDMFItemVendorWidget Function HandleCloseClicked *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleCloseClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCloseClicked constinit property declarations ********************
// ********** End Function HandleCloseClicked constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleCloseClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleCloseClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleCloseClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCloseClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleCloseClicked ***************************

// ********** Begin Class UDMFItemVendorWidget Function HandleEntryPressed *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleEntryPressed_Statics
struct UHT_STATICS
{
	struct DMFItemVendorWidget_eventHandleEntryPressed_Parms
	{
		EDMFItemVendorTransactionType TransactionType;
		FGuid StockId;
		FPrimaryAssetId ItemAssetId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleEntryPressed constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StockId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAssetId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleEntryPressed constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleEntryPressed Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleEntryPressed_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StockId = { "StockId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleEntryPressed_Parms, StockId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleEntryPressed_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StockId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ItemAssetId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleEntryPressed Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleEntryPressed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorWidget_eventHandleEntryPressed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorWidget_eventHandleEntryPressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleEntryPressed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleEntryPressed)
{
	P_GET_ENUM(EDMFItemVendorTransactionType,Z_Param_TransactionType);
	P_GET_STRUCT(FGuid,Z_Param_StockId);
	P_GET_STRUCT(FPrimaryAssetId,Z_Param_ItemAssetId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleEntryPressed(EDMFItemVendorTransactionType(Z_Param_TransactionType),Z_Param_StockId,Z_Param_ItemAssetId);
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleEntryPressed ***************************

// ********** Begin Class UDMFItemVendorWidget Function HandleHeaderTimer **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleHeaderTimer_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleHeaderTimer constinit property declarations *********************
// ********** End Function HandleHeaderTimer constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleHeaderTimer", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleHeaderTimer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleHeaderTimer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleHeaderTimer();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleHeaderTimer ****************************

// ********** Begin Class UDMFItemVendorWidget Function HandleItemInventoryChanged *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleItemInventoryChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleItemInventoryChanged constinit property declarations ************
// ********** End Function HandleItemInventoryChanged constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleItemInventoryChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleItemInventoryChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleItemInventoryChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleItemInventoryChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleItemInventoryChanged *******************

// ********** Begin Class UDMFItemVendorWidget Function HandleMoneyChanged *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleMoneyChanged_Statics
struct UHT_STATICS
{
	struct DMFItemVendorWidget_eventHandleMoneyChanged_Parms
	{
		int64 NewMoney;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleMoneyChanged constinit property declarations ********************
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NewMoney;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleMoneyChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleMoneyChanged Property Definitions *******************************
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NewMoney = { "NewMoney", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleMoneyChanged_Parms, NewMoney), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewMoney,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleMoneyChanged Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleMoneyChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorWidget_eventHandleMoneyChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorWidget_eventHandleMoneyChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleMoneyChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleMoneyChanged)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_NewMoney);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMoneyChanged(Z_Param_NewMoney);
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleMoneyChanged ***************************

// ********** Begin Class UDMFItemVendorWidget Function HandleQuantityMax **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityMax_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleQuantityMax constinit property declarations *********************
// ********** End Function HandleQuantityMax constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleQuantityMax", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityMax(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleQuantityMax)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleQuantityMax();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleQuantityMax ****************************

// ********** Begin Class UDMFItemVendorWidget Function HandleQuantityMinusOne *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityMinusOne_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleQuantityMinusOne constinit property declarations ****************
// ********** End Function HandleQuantityMinusOne constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleQuantityMinusOne", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityMinusOne(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleQuantityMinusOne)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleQuantityMinusOne();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleQuantityMinusOne ***********************

// ********** Begin Class UDMFItemVendorWidget Function HandleQuantityMinusTen *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityMinusTen_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleQuantityMinusTen constinit property declarations ****************
// ********** End Function HandleQuantityMinusTen constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleQuantityMinusTen", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityMinusTen(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleQuantityMinusTen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleQuantityMinusTen();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleQuantityMinusTen ***********************

// ********** Begin Class UDMFItemVendorWidget Function HandleQuantityPlusOne **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityPlusOne_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleQuantityPlusOne constinit property declarations *****************
// ********** End Function HandleQuantityPlusOne constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleQuantityPlusOne", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityPlusOne(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleQuantityPlusOne)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleQuantityPlusOne();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleQuantityPlusOne ************************

// ********** Begin Class UDMFItemVendorWidget Function HandleQuantityPlusTen **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityPlusTen_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleQuantityPlusTen constinit property declarations *****************
// ********** End Function HandleQuantityPlusTen constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleQuantityPlusTen", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityPlusTen(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleQuantityPlusTen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleQuantityPlusTen();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleQuantityPlusTen ************************

// ********** Begin Class UDMFItemVendorWidget Function HandleSellTabClicked ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleSellTabClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSellTabClicked constinit property declarations ******************
// ********** End Function HandleSellTabClicked constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleSellTabClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleSellTabClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleSellTabClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSellTabClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleSellTabClicked *************************

// ********** Begin Class UDMFItemVendorWidget Function HandleTransactionClicked *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleTransactionClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleTransactionClicked constinit property declarations **************
// ********** End Function HandleTransactionClicked constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleTransactionClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleTransactionClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleTransactionClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleTransactionClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleTransactionClicked *********************

// ********** Begin Class UDMFItemVendorWidget Function HandleVendorConfigurationChanged ***********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorConfigurationChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleVendorConfigurationChanged constinit property declarations ******
// ********** End Function HandleVendorConfigurationChanged constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleVendorConfigurationChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorConfigurationChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleVendorConfigurationChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleVendorConfigurationChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleVendorConfigurationChanged *************

// ********** Begin Class UDMFItemVendorWidget Function HandleVendorEnabledChanged *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorEnabledChanged_Statics
struct UHT_STATICS
{
	struct DMFItemVendorWidget_eventHandleVendorEnabledChanged_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleVendorEnabledChanged constinit property declarations ************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFItemVendorWidget_eventHandleVendorEnabledChanged_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleVendorEnabledChanged constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleVendorEnabledChanged Property Definitions ***********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFItemVendorWidget_eventHandleVendorEnabledChanged_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleVendorEnabledChanged Property Definitions *************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleVendorEnabledChanged", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorWidget_eventHandleVendorEnabledChanged_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorWidget_eventHandleVendorEnabledChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorEnabledChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleVendorEnabledChanged)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleVendorEnabledChanged(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleVendorEnabledChanged *******************

// ********** Begin Class UDMFItemVendorWidget Function HandleVendorStockChanged *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorStockChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleVendorStockChanged constinit property declarations **************
// ********** End Function HandleVendorStockChanged constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleVendorStockChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorStockChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleVendorStockChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleVendorStockChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleVendorStockChanged *********************

// ********** Begin Class UDMFItemVendorWidget Function HandleVendorTransactionResult **************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorTransactionResult_Statics
struct UHT_STATICS
{
	struct DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms
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
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleVendorTransactionResult constinit property declarations *********
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms*)Obj)->bSuccess = 1;
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
// ********** End Function HandleVendorTransactionResult constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleVendorTransactionResult Property Definitions ********************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms, TransactionType), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ItemAssetId = { "ItemAssetId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms, ItemAssetId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(0, nullptr) }; // 51539104367397b403249c27cab9a0578cde1246
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_TotalPrice = { "TotalPrice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms, TotalPrice), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams UHT_STATICS::NewProp_NewMoney = { "NewMoney", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms, NewMoney), METADATA_PARAMS(0, nullptr) };
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
// ********** End Function HandleVendorTransactionResult Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "HandleVendorTransactionResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorWidget_eventHandleVendorTransactionResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorTransactionResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execHandleVendorTransactionResult)
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
	P_THIS->HandleVendorTransactionResult(Z_Param_bSuccess,Z_Param_Message,EDMFItemVendorTransactionType(Z_Param_TransactionType),Z_Param_ItemAssetId,Z_Param_Quantity,Z_Param_TotalPrice,Z_Param_NewMoney);
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function HandleVendorTransactionResult ****************

// ********** Begin Class UDMFItemVendorWidget Function InitializeVendor ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_InitializeVendor_Statics
struct UHT_STATICS
{
	struct DMFItemVendorWidget_eventInitializeVendor_Parms
	{
		ADMFItemVendorActor* InVendor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeVendor constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InVendor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeVendor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeVendor Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_InVendor = { "InVendor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventInitializeVendor_Parms, InVendor), Z_Construct_UClass_ADMFItemVendorActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InVendor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeVendor Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "InitializeVendor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorWidget_eventInitializeVendor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorWidget_eventInitializeVendor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_InitializeVendor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execInitializeVendor)
{
	P_GET_OBJECT(ADMFItemVendorActor,Z_Param_InVendor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeVendor(Z_Param_InVendor);
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function InitializeVendor *****************************

// ********** Begin Class UDMFItemVendorWidget Function RefreshVendorUI ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_RefreshVendorUI_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshVendorUI constinit property declarations ***********************
// ********** End Function RefreshVendorUI constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "RefreshVendorUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_RefreshVendorUI(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execRefreshVendorUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshVendorUI();
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function RefreshVendorUI ******************************

// ********** Begin Class UDMFItemVendorWidget Function SetVendorTab *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFItemVendorWidget_SetVendorTab_Statics
struct UHT_STATICS
{
	struct DMFItemVendorWidget_eventSetVendorTab_Parms
	{
		EDMFItemVendorTransactionType NewTab;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Item Vendor" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
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
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewTab = { "NewTab", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFItemVendorWidget_eventSetVendorTab_Parms, NewTab), Z_Construct_UEnum_DigimonMMOFramework_EDMFItemVendorTransactionType, METADATA_PARAMS(0, nullptr) }; // c24cde81311435e364e323f4915388cd515e4db7
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTab_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewTab,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetVendorTab Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFItemVendorWidget, nullptr, "SetVendorTab", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFItemVendorWidget_eventSetVendorTab_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFItemVendorWidget_eventSetVendorTab_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFItemVendorWidget_SetVendorTab(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFItemVendorWidget::execSetVendorTab)
{
	P_GET_ENUM(EDMFItemVendorTransactionType,Z_Param_NewTab);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVendorTab(EDMFItemVendorTransactionType(Z_Param_NewTab));
	P_NATIVE_END;
}
// ********** End Class UDMFItemVendorWidget Function SetVendorTab *********************************

// ********** Begin Class UDMFItemVendorWidget *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFItemVendorWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Polished native BUY/SELL item exchange with shared stock and quantity-aware atomic transactions. */" },
#endif
		{ "IncludePath", "UI/DMFItemVendorWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Polished native BUY/SELL item exchange with shared stock and quantity-aware atomic transactions." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorSubtitleText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoneyText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuyTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SellTabButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryListBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailIcon_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailMetaText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailDescriptionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailInventoryText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetailPriceText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityMinusTenButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityMinusOneButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityPlusOneButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityPlusTenButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityMaxButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorStatusText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransactionButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransactionButtonText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFItemVendorWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFItemVendorWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFItemVendorWidget constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorSubtitleText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoneyText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RotationText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BuyTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SellTabButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EntryListBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailIcon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailMetaText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailDescriptionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailInventoryText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DetailPriceText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityMinusTenButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityMinusOneButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityPlusOneButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityPlusTenButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityMaxButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VendorStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TransactionButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TransactionButtonText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFItemVendorWidget constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSelectedQuantity"), .Pointer = &UDMFItemVendorWidget::execGetSelectedQuantity },
		{ .NameUTF8 = UTF8TEXT("GetVendor"), .Pointer = &UDMFItemVendorWidget::execGetVendor },
		{ .NameUTF8 = UTF8TEXT("GetVendorTab"), .Pointer = &UDMFItemVendorWidget::execGetVendorTab },
		{ .NameUTF8 = UTF8TEXT("HandleBuyTabClicked"), .Pointer = &UDMFItemVendorWidget::execHandleBuyTabClicked },
		{ .NameUTF8 = UTF8TEXT("HandleCloseClicked"), .Pointer = &UDMFItemVendorWidget::execHandleCloseClicked },
		{ .NameUTF8 = UTF8TEXT("HandleEntryPressed"), .Pointer = &UDMFItemVendorWidget::execHandleEntryPressed },
		{ .NameUTF8 = UTF8TEXT("HandleHeaderTimer"), .Pointer = &UDMFItemVendorWidget::execHandleHeaderTimer },
		{ .NameUTF8 = UTF8TEXT("HandleItemInventoryChanged"), .Pointer = &UDMFItemVendorWidget::execHandleItemInventoryChanged },
		{ .NameUTF8 = UTF8TEXT("HandleMoneyChanged"), .Pointer = &UDMFItemVendorWidget::execHandleMoneyChanged },
		{ .NameUTF8 = UTF8TEXT("HandleQuantityMax"), .Pointer = &UDMFItemVendorWidget::execHandleQuantityMax },
		{ .NameUTF8 = UTF8TEXT("HandleQuantityMinusOne"), .Pointer = &UDMFItemVendorWidget::execHandleQuantityMinusOne },
		{ .NameUTF8 = UTF8TEXT("HandleQuantityMinusTen"), .Pointer = &UDMFItemVendorWidget::execHandleQuantityMinusTen },
		{ .NameUTF8 = UTF8TEXT("HandleQuantityPlusOne"), .Pointer = &UDMFItemVendorWidget::execHandleQuantityPlusOne },
		{ .NameUTF8 = UTF8TEXT("HandleQuantityPlusTen"), .Pointer = &UDMFItemVendorWidget::execHandleQuantityPlusTen },
		{ .NameUTF8 = UTF8TEXT("HandleSellTabClicked"), .Pointer = &UDMFItemVendorWidget::execHandleSellTabClicked },
		{ .NameUTF8 = UTF8TEXT("HandleTransactionClicked"), .Pointer = &UDMFItemVendorWidget::execHandleTransactionClicked },
		{ .NameUTF8 = UTF8TEXT("HandleVendorConfigurationChanged"), .Pointer = &UDMFItemVendorWidget::execHandleVendorConfigurationChanged },
		{ .NameUTF8 = UTF8TEXT("HandleVendorEnabledChanged"), .Pointer = &UDMFItemVendorWidget::execHandleVendorEnabledChanged },
		{ .NameUTF8 = UTF8TEXT("HandleVendorStockChanged"), .Pointer = &UDMFItemVendorWidget::execHandleVendorStockChanged },
		{ .NameUTF8 = UTF8TEXT("HandleVendorTransactionResult"), .Pointer = &UDMFItemVendorWidget::execHandleVendorTransactionResult },
		{ .NameUTF8 = UTF8TEXT("InitializeVendor"), .Pointer = &UDMFItemVendorWidget::execInitializeVendor },
		{ .NameUTF8 = UTF8TEXT("RefreshVendorUI"), .Pointer = &UDMFItemVendorWidget::execRefreshVendorUI },
		{ .NameUTF8 = UTF8TEXT("SetVendorTab"), .Pointer = &UDMFItemVendorWidget::execSetVendorTab },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_BP_OnVendorQuantityChanged, "BP_OnVendorQuantityChanged" }, // fb4490343e5d824264f3287590cfe8e42c7c1bf0
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_BP_OnVendorRefreshed, "BP_OnVendorRefreshed" }, // e9b97c79e1b42542bb762dc9d03c56df2665d1b1
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_BP_OnVendorSelectionChanged, "BP_OnVendorSelectionChanged" }, // 8822f2832026dbff88b975066c960f2a6db7daae
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_GetSelectedQuantity, "GetSelectedQuantity" }, // 2d7c4035c9dfb322298ab2a030a8b4191ea003dc
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_GetVendor, "GetVendor" }, // b98721759659fc0625bf6394a1e91cd4f4f11432
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_GetVendorTab, "GetVendorTab" }, // 08996a3521b1b611e76fccef12e344d8917caa8f
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleBuyTabClicked, "HandleBuyTabClicked" }, // 7642aa4f5aef8877dea9a11325fdffb2a205dda8
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleCloseClicked, "HandleCloseClicked" }, // 9e759bd3da6cf290a638d2990699042ca372e1b1
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleEntryPressed, "HandleEntryPressed" }, // 3b06153be599c6833e21e4ec3e95faf576f87556
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleHeaderTimer, "HandleHeaderTimer" }, // c1d7077094b90c0f0b7af149c80186c939359e36
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleItemInventoryChanged, "HandleItemInventoryChanged" }, // 27a7fb3ee56faa1df7102560c85f188bf5a11056
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleMoneyChanged, "HandleMoneyChanged" }, // cf4bc08994309dec57f017b7f42d900cec86c45a
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityMax, "HandleQuantityMax" }, // f11881db38e16e4d3eeade2523a7ab0124844a0a
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityMinusOne, "HandleQuantityMinusOne" }, // aaaf387c5d634d7d79494c49f5b048618b726244
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityMinusTen, "HandleQuantityMinusTen" }, // d0672e24060600ddb55191ceac31cb90c115631b
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityPlusOne, "HandleQuantityPlusOne" }, // d578480b72730d600667b4d82cbcef8129828023
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleQuantityPlusTen, "HandleQuantityPlusTen" }, // d55fab3212a3bf3bbfc94e932180be3d886b5093
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleSellTabClicked, "HandleSellTabClicked" }, // 4a6967a3e08669a8a101a80d5fd1460c2dad1ca4
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleTransactionClicked, "HandleTransactionClicked" }, // 4b0ac9c460f0f1ca18c6ad8fcfec9813dbf84e51
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorConfigurationChanged, "HandleVendorConfigurationChanged" }, // a24cace236dd68935f92efe56233d8aebae94b18
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorEnabledChanged, "HandleVendorEnabledChanged" }, // 0626d23688f7ad858d66f83f9b74cbb3db742a83
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorStockChanged, "HandleVendorStockChanged" }, // 7fb17e26635cf31b7090459376c8aec868dc7e77
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_HandleVendorTransactionResult, "HandleVendorTransactionResult" }, // 0f89411a09a196ae49a418f356fe0d66ede8f1fd
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_InitializeVendor, "InitializeVendor" }, // a055b32a5286db94f52eadc3f70688ec76ed42fa
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_RefreshVendorUI, "RefreshVendorUI" }, // 851f37aae7b1505bb29981aff29889a38ce4cf8e
		{ &Z_Construct_UFunction_UDMFItemVendorWidget_SetVendorTab, "SetVendorTab" }, // fc16b794f3ac4c602ae19c5e49d1044f7fe00374
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFItemVendorWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFItemVendorWidget Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorNameText = { "VendorNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, VendorNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorNameText_MetaData), NewProp_VendorNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorSubtitleText = { "VendorSubtitleText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, VendorSubtitleText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorSubtitleText_MetaData), NewProp_VendorSubtitleText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MoneyText = { "MoneyText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, MoneyText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoneyText_MetaData), NewProp_MoneyText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RotationText = { "RotationText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, RotationText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationText_MetaData), NewProp_RotationText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BuyTabButton = { "BuyTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, BuyTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuyTabButton_MetaData), NewProp_BuyTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SellTabButton = { "SellTabButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, SellTabButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SellTabButton_MetaData), NewProp_SellTabButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_EntryListBox = { "EntryListBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, EntryListBox), Z_Construct_UClass_UVerticalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryListBox_MetaData), NewProp_EntryListBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailIcon = { "DetailIcon", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, DetailIcon), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailIcon_MetaData), NewProp_DetailIcon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailNameText = { "DetailNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, DetailNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailNameText_MetaData), NewProp_DetailNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailMetaText = { "DetailMetaText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, DetailMetaText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailMetaText_MetaData), NewProp_DetailMetaText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailDescriptionText = { "DetailDescriptionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, DetailDescriptionText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailDescriptionText_MetaData), NewProp_DetailDescriptionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailInventoryText = { "DetailInventoryText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, DetailInventoryText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailInventoryText_MetaData), NewProp_DetailInventoryText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_DetailPriceText = { "DetailPriceText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, DetailPriceText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetailPriceText_MetaData), NewProp_DetailPriceText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_QuantityText = { "QuantityText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, QuantityText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityText_MetaData), NewProp_QuantityText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_QuantityMinusTenButton = { "QuantityMinusTenButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, QuantityMinusTenButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityMinusTenButton_MetaData), NewProp_QuantityMinusTenButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_QuantityMinusOneButton = { "QuantityMinusOneButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, QuantityMinusOneButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityMinusOneButton_MetaData), NewProp_QuantityMinusOneButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_QuantityPlusOneButton = { "QuantityPlusOneButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, QuantityPlusOneButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityPlusOneButton_MetaData), NewProp_QuantityPlusOneButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_QuantityPlusTenButton = { "QuantityPlusTenButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, QuantityPlusTenButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityPlusTenButton_MetaData), NewProp_QuantityPlusTenButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_QuantityMaxButton = { "QuantityMaxButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, QuantityMaxButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityMaxButton_MetaData), NewProp_QuantityMaxButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VendorStatusText = { "VendorStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, VendorStatusText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorStatusText_MetaData), NewProp_VendorStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TransactionButton = { "TransactionButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, TransactionButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransactionButton_MetaData), NewProp_TransactionButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TransactionButtonText = { "TransactionButtonText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, TransactionButtonText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransactionButtonText_MetaData), NewProp_TransactionButtonText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_CloseButton = { "CloseButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFItemVendorWidget, CloseButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButton_MetaData), NewProp_CloseButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorSubtitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MoneyText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RotationText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BuyTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SellTabButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EntryListBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailMetaText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailDescriptionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailInventoryText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DetailPriceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_QuantityText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_QuantityMinusTenButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_QuantityMinusOneButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_QuantityPlusOneButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_QuantityPlusTenButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_QuantityMaxButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VendorStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TransactionButtonText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CloseButton,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFItemVendorWidget Property Definitions **********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFItemVendorWidget,
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
static void UDMFItemVendorWidget_StaticRegisterNativesUDMFItemVendorWidget()
{
	UClass* Class = UDMFItemVendorWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFItemVendorWidget;
UClass* Z_Construct_UClass_UDMFItemVendorWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFItemVendorWidget;
		if (!Z_Registration_Info_UClass_UDMFItemVendorWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFItemVendorWidget"),
				Z_Registration_Info_UClass_UDMFItemVendorWidget.InnerSingleton,
				UDMFItemVendorWidget_StaticRegisterNativesUDMFItemVendorWidget,
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
		return Z_Registration_Info_UClass_UDMFItemVendorWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFItemVendorWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFItemVendorWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFItemVendorWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFItemVendorWidget::UDMFItemVendorWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFItemVendorWidget);
UDMFItemVendorWidget::~UDMFItemVendorWidget() {}
// ********** End Class UDMFItemVendorWidget *******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFItemVendorEntryButton, TEXT("UDMFItemVendorEntryButton"), &Z_Registration_Info_UClass_UDMFItemVendorEntryButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFItemVendorEntryButton), 2904481804U) },
		{ Z_Construct_UClass_UDMFItemVendorWidget, TEXT("UDMFItemVendorWidget"), &Z_Registration_Info_UClass_UDMFItemVendorWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFItemVendorWidget), 3590944157U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h__Script_DigimonMMOFramework_63b6e94d19e45f5643e2171c8175b657c2c15441{
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
