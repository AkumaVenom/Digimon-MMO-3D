// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFPartyQuickBarWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFPartyQuickBarWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UHorizontalBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UProgressBar(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPartyQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPartyQuickSlotButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UEnum* Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPartyQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPartyQuickSlotButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerDigimonComponent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFPartyQuickSlotButton Function HandleClicked **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickSlotButton_HandleClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleClicked constinit property declarations *************************
// ********** End Function HandleClicked constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickSlotButton, nullptr, "HandleClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPartyQuickSlotButton_HandleClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickSlotButton::execHandleClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickSlotButton Function HandleClicked ****************************

// ********** Begin Class UDMFPartyQuickSlotButton *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFPartyQuickSlotButton_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/DMFPartyQuickBarWidget.h" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFPartyQuickSlotButton constinit property declarations *****************
// ********** End Class UDMFPartyQuickSlotButton constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleClicked"), .Pointer = &UDMFPartyQuickSlotButton::execHandleClicked },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFPartyQuickSlotButton_HandleClicked, "HandleClicked" }, // 9214ab47030d54e50228a759d16624a8544c4129
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFPartyQuickSlotButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UButton,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFPartyQuickSlotButton,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x00B000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UDMFPartyQuickSlotButton_StaticRegisterNativesUDMFPartyQuickSlotButton()
{
	UClass* Class = UDMFPartyQuickSlotButton::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFPartyQuickSlotButton;
UClass* Z_Construct_UClass_UDMFPartyQuickSlotButton(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFPartyQuickSlotButton;
		if (!Z_Registration_Info_UClass_UDMFPartyQuickSlotButton.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFPartyQuickSlotButton"),
				Z_Registration_Info_UClass_UDMFPartyQuickSlotButton.InnerSingleton,
				UDMFPartyQuickSlotButton_StaticRegisterNativesUDMFPartyQuickSlotButton,
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
		return Z_Registration_Info_UClass_UDMFPartyQuickSlotButton.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFPartyQuickSlotButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFPartyQuickSlotButton.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFPartyQuickSlotButton.OuterSingleton;
}
#undef UHT_STATICS
UDMFPartyQuickSlotButton::UDMFPartyQuickSlotButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFPartyQuickSlotButton);
UDMFPartyQuickSlotButton::~UDMFPartyQuickSlotButton() {}
// ********** End Class UDMFPartyQuickSlotButton ***************************************************

// ********** Begin Class UDMFPartyQuickBarWidget Function BP_OnPartyQuickBarRefreshed *************
static FName NAME_UDMFPartyQuickBarWidget_BP_OnPartyQuickBarRefreshed = FName(TEXT("BP_OnPartyQuickBarRefreshed"));
void UDMFPartyQuickBarWidget::BP_OnPartyQuickBarRefreshed()
{
	UFunction* Func = FindFunctionChecked(NAME_UDMFPartyQuickBarWidget_BP_OnPartyQuickBarRefreshed);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_BP_OnPartyQuickBarRefreshed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPartyQuickBarRefreshed constinit property declarations ***********
// ********** End Function BP_OnPartyQuickBarRefreshed constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "BP_OnPartyQuickBarRefreshed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_BP_OnPartyQuickBarRefreshed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFPartyQuickBarWidget Function BP_OnPartyQuickBarRefreshed ***************

// ********** Begin Class UDMFPartyQuickBarWidget Function ExecutePartySlot ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_ExecutePartySlot_Statics
struct UHT_STATICS
{
	struct DMFPartyQuickBarWidget_eventExecutePartySlot_Parms
	{
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecutePartySlot constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecutePartySlot constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecutePartySlot Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPartyQuickBarWidget_eventExecutePartySlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ExecutePartySlot Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "ExecutePartySlot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPartyQuickBarWidget_eventExecutePartySlot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPartyQuickBarWidget_eventExecutePartySlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_ExecutePartySlot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execExecutePartySlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExecutePartySlot(Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function ExecutePartySlot **************************

// ********** Begin Class UDMFPartyQuickBarWidget Function HandleHomeTeleportResult ****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleHomeTeleportResult_Statics
struct UHT_STATICS
{
	struct DMFPartyQuickBarWidget_eventHandleHomeTeleportResult_Parms
	{
		bool bSuccess;
		FText Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleHomeTeleportResult constinit property declarations **************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFPartyQuickBarWidget_eventHandleHomeTeleportResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleHomeTeleportResult constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleHomeTeleportResult Property Definitions *************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPartyQuickBarWidget_eventHandleHomeTeleportResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPartyQuickBarWidget_eventHandleHomeTeleportResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleHomeTeleportResult Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "HandleHomeTeleportResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPartyQuickBarWidget_eventHandleHomeTeleportResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPartyQuickBarWidget_eventHandleHomeTeleportResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleHomeTeleportResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execHandleHomeTeleportResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleHomeTeleportResult(Z_Param_bSuccess,Z_Param_Message);
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function HandleHomeTeleportResult ******************

// ********** Begin Class UDMFPartyQuickBarWidget Function HandleOpenBankClicked *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleOpenBankClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleOpenBankClicked constinit property declarations *****************
// ********** End Function HandleOpenBankClicked constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "HandleOpenBankClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleOpenBankClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execHandleOpenBankClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOpenBankClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function HandleOpenBankClicked *********************

// ********** Begin Class UDMFPartyQuickBarWidget Function HandleOpenPartyClicked ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleOpenPartyClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleOpenPartyClicked constinit property declarations ****************
// ********** End Function HandleOpenPartyClicked constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "HandleOpenPartyClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleOpenPartyClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execHandleOpenPartyClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOpenPartyClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function HandleOpenPartyClicked ********************

// ********** Begin Class UDMFPartyQuickBarWidget Function HandlePartyChanged **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandlePartyChanged_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePartyChanged constinit property declarations ********************
// ********** End Function HandlePartyChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "HandlePartyChanged", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandlePartyChanged(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execHandlePartyChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePartyChanged();
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function HandlePartyChanged ************************

// ********** Begin Class UDMFPartyQuickBarWidget Function HandleRecallClicked *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleRecallClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleRecallClicked constinit property declarations *******************
// ********** End Function HandleRecallClicked constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "HandleRecallClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleRecallClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execHandleRecallClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleRecallClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function HandleRecallClicked ***********************

// ********** Begin Class UDMFPartyQuickBarWidget Function HandleReturnHomeClicked *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleReturnHomeClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleReturnHomeClicked constinit property declarations ***************
// ********** End Function HandleReturnHomeClicked constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "HandleReturnHomeClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleReturnHomeClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execHandleReturnHomeClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleReturnHomeClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function HandleReturnHomeClicked *******************

// ********** Begin Class UDMFPartyQuickBarWidget Function HandleStorageResult *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleStorageResult_Statics
struct UHT_STATICS
{
	struct DMFPartyQuickBarWidget_eventHandleStorageResult_Parms
	{
		bool bSuccess;
		FText Message;
		FGuid DigimonInstanceId;
		EDMFDigimonStorageLocation NewLocation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleStorageResult constinit property declarations *******************
	static void NewProp_bSuccess_SetBit(void* Obj)
	{
		((DMFPartyQuickBarWidget_eventHandleStorageResult_Parms*)Obj)->bSuccess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DigimonInstanceId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewLocation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleStorageResult constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleStorageResult Property Definitions ******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPartyQuickBarWidget_eventHandleStorageResult_Parms), &UHT_STATICS::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPartyQuickBarWidget_eventHandleStorageResult_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_DigimonInstanceId = { "DigimonInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPartyQuickBarWidget_eventHandleStorageResult_Parms, DigimonInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_NewLocation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_NewLocation = { "NewLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(DMFPartyQuickBarWidget_eventHandleStorageResult_Parms, NewLocation), Z_Construct_UEnum_DigimonMMOFramework_EDMFDigimonStorageLocation, METADATA_PARAMS(0, nullptr) }; // 8e1831166ad9bffb34f8008359e4dfa18eac358f
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DigimonInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewLocation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewLocation,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleStorageResult Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "HandleStorageResult", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPartyQuickBarWidget_eventHandleStorageResult_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPartyQuickBarWidget_eventHandleStorageResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleStorageResult(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execHandleStorageResult)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_GET_PROPERTY(FTextProperty,Z_Param_Message);
	P_GET_STRUCT(FGuid,Z_Param_DigimonInstanceId);
	P_GET_ENUM(EDMFDigimonStorageLocation,Z_Param_NewLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStorageResult(Z_Param_bSuccess,Z_Param_Message,Z_Param_DigimonInstanceId,EDMFDigimonStorageLocation(Z_Param_NewLocation));
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function HandleStorageResult ***********************

// ********** Begin Class UDMFPartyQuickBarWidget Function IsInteractionMode ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_IsInteractionMode_Statics
struct UHT_STATICS
{
	struct DMFPartyQuickBarWidget_eventIsInteractionMode_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsInteractionMode constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFPartyQuickBarWidget_eventIsInteractionMode_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsInteractionMode constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsInteractionMode Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPartyQuickBarWidget_eventIsInteractionMode_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsInteractionMode Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "IsInteractionMode", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPartyQuickBarWidget_eventIsInteractionMode_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPartyQuickBarWidget_eventIsInteractionMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_IsInteractionMode(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execIsInteractionMode)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsInteractionMode();
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function IsInteractionMode *************************

// ********** Begin Class UDMFPartyQuickBarWidget Function RefreshParty ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_RefreshParty_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshParty constinit property declarations **************************
// ********** End Function RefreshParty constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "RefreshParty", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_RefreshParty(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execRefreshParty)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshParty();
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function RefreshParty ******************************

// ********** Begin Class UDMFPartyQuickBarWidget Function SetInteractionMode **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFPartyQuickBarWidget_SetInteractionMode_Statics
struct UHT_STATICS
{
	struct DMFPartyQuickBarWidget_eventSetInteractionMode_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Party Quick Access" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetInteractionMode constinit property declarations ********************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((DMFPartyQuickBarWidget_eventSetInteractionMode_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInteractionMode constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInteractionMode Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFPartyQuickBarWidget_eventSetInteractionMode_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetInteractionMode Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFPartyQuickBarWidget, nullptr, "SetInteractionMode", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFPartyQuickBarWidget_eventSetInteractionMode_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFPartyQuickBarWidget_eventSetInteractionMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFPartyQuickBarWidget_SetInteractionMode(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFPartyQuickBarWidget::execSetInteractionMode)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetInteractionMode(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UDMFPartyQuickBarWidget Function SetInteractionMode ************************

// ********** Begin Class UDMFPartyQuickBarWidget **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFPartyQuickBarWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Persistent six-slot native Party HUD. The bar is informational during normal gameplay and becomes\n * clickable when the owning controller enters Tab Party interaction mode.\n */" },
#endif
		{ "IncludePath", "UI/DMFPartyQuickBarWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Persistent six-slot native Party HUD. The bar is informational during normal gameplay and becomes\nclickable when the owning controller enters Tab Party interaction mode." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartySlotsBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPartyQuickBarWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartyStatusText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPartyQuickBarWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PartyActionRow_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPartyQuickBarWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnHomeButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFPartyQuickBarWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional Blueprint/native Home button. Native fallback places it in the Tab interaction action row. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional Blueprint/native Home button. Native fallback places it in the Tab interaction action row." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundDigimonComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativePortraits_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeLabels_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeHealthBars_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeSlotButtons_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFPartyQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFPartyQuickBarWidget constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PartySlotsBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PartyStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PartyActionRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnHomeButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundDigimonComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NativePortraits_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NativePortraits;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NativeLabels_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NativeLabels;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NativeHealthBars_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NativeHealthBars;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NativeSlotButtons_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NativeSlotButtons;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFPartyQuickBarWidget constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ExecutePartySlot"), .Pointer = &UDMFPartyQuickBarWidget::execExecutePartySlot },
		{ .NameUTF8 = UTF8TEXT("HandleHomeTeleportResult"), .Pointer = &UDMFPartyQuickBarWidget::execHandleHomeTeleportResult },
		{ .NameUTF8 = UTF8TEXT("HandleOpenBankClicked"), .Pointer = &UDMFPartyQuickBarWidget::execHandleOpenBankClicked },
		{ .NameUTF8 = UTF8TEXT("HandleOpenPartyClicked"), .Pointer = &UDMFPartyQuickBarWidget::execHandleOpenPartyClicked },
		{ .NameUTF8 = UTF8TEXT("HandlePartyChanged"), .Pointer = &UDMFPartyQuickBarWidget::execHandlePartyChanged },
		{ .NameUTF8 = UTF8TEXT("HandleRecallClicked"), .Pointer = &UDMFPartyQuickBarWidget::execHandleRecallClicked },
		{ .NameUTF8 = UTF8TEXT("HandleReturnHomeClicked"), .Pointer = &UDMFPartyQuickBarWidget::execHandleReturnHomeClicked },
		{ .NameUTF8 = UTF8TEXT("HandleStorageResult"), .Pointer = &UDMFPartyQuickBarWidget::execHandleStorageResult },
		{ .NameUTF8 = UTF8TEXT("IsInteractionMode"), .Pointer = &UDMFPartyQuickBarWidget::execIsInteractionMode },
		{ .NameUTF8 = UTF8TEXT("RefreshParty"), .Pointer = &UDMFPartyQuickBarWidget::execRefreshParty },
		{ .NameUTF8 = UTF8TEXT("SetInteractionMode"), .Pointer = &UDMFPartyQuickBarWidget::execSetInteractionMode },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_BP_OnPartyQuickBarRefreshed, "BP_OnPartyQuickBarRefreshed" }, // f0759f9e4a36f8b3bf5ad2bddc8624364ecc081c
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_ExecutePartySlot, "ExecutePartySlot" }, // 871dce920a53543911bd8e7285c7af9a8ea61671
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleHomeTeleportResult, "HandleHomeTeleportResult" }, // 54e41a294ef480397bc180285d5a4cc993ca1fd0
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleOpenBankClicked, "HandleOpenBankClicked" }, // 22efd7f99353b5a64b27e4c84dae8ae249b5c743
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleOpenPartyClicked, "HandleOpenPartyClicked" }, // 16d12aa4c245a5dbc561f39fb94ec6536d8b4385
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandlePartyChanged, "HandlePartyChanged" }, // c633a4240b2e45fbdcf6bf21ff019f6406cc3116
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleRecallClicked, "HandleRecallClicked" }, // 857cb586c8441b0d356e2061c3d92036ac31ebcf
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleReturnHomeClicked, "HandleReturnHomeClicked" }, // acee355b406b12852852507b843fe64608024201
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_HandleStorageResult, "HandleStorageResult" }, // 2ff39a0d458cc1a5cc1d74b4be29040542a10d81
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_IsInteractionMode, "IsInteractionMode" }, // bd84373e43f218241aaf0783784066e987d06fd7
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_RefreshParty, "RefreshParty" }, // b5c4f4d57d21464e8a5d9e79467153505b7b6e36
		{ &Z_Construct_UFunction_UDMFPartyQuickBarWidget_SetInteractionMode, "SetInteractionMode" }, // 757be712de03fe0effbd49c59bfea3cf4aed9106
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFPartyQuickBarWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFPartyQuickBarWidget Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PartySlotsBox = { "PartySlotsBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPartyQuickBarWidget, PartySlotsBox), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartySlotsBox_MetaData), NewProp_PartySlotsBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PartyStatusText = { "PartyStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPartyQuickBarWidget, PartyStatusText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartyStatusText_MetaData), NewProp_PartyStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PartyActionRow = { "PartyActionRow", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPartyQuickBarWidget, PartyActionRow), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PartyActionRow_MetaData), NewProp_PartyActionRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnHomeButton = { "ReturnHomeButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPartyQuickBarWidget, ReturnHomeButton), Z_Construct_UClass_UButton, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnHomeButton_MetaData), NewProp_ReturnHomeButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BoundDigimonComponent = { "BoundDigimonComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPartyQuickBarWidget, BoundDigimonComponent), Z_Construct_UClass_UDMFPlayerDigimonComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundDigimonComponent_MetaData), NewProp_BoundDigimonComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NativePortraits_Inner = { "NativePortraits", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_UImage, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_NativePortraits = { "NativePortraits", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPartyQuickBarWidget, NativePortraits), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativePortraits_MetaData), NewProp_NativePortraits_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NativeLabels_Inner = { "NativeLabels", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTextBlock, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_NativeLabels = { "NativeLabels", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPartyQuickBarWidget, NativeLabels), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeLabels_MetaData), NewProp_NativeLabels_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NativeHealthBars_Inner = { "NativeHealthBars", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_UProgressBar, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_NativeHealthBars = { "NativeHealthBars", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPartyQuickBarWidget, NativeHealthBars), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeHealthBars_MetaData), NewProp_NativeHealthBars_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NativeSlotButtons_Inner = { "NativeSlotButtons", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMFPartyQuickSlotButton, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_NativeSlotButtons = { "NativeSlotButtons", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFPartyQuickBarWidget, NativeSlotButtons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeSlotButtons_MetaData), NewProp_NativeSlotButtons_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartySlotsBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartyStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PartyActionRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnHomeButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BoundDigimonComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativePortraits_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativePortraits,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeLabels_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeHealthBars_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeHealthBars,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeSlotButtons_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeSlotButtons,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFPartyQuickBarWidget Property Definitions *******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFPartyQuickBarWidget,
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
static void UDMFPartyQuickBarWidget_StaticRegisterNativesUDMFPartyQuickBarWidget()
{
	UClass* Class = UDMFPartyQuickBarWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFPartyQuickBarWidget;
UClass* Z_Construct_UClass_UDMFPartyQuickBarWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFPartyQuickBarWidget;
		if (!Z_Registration_Info_UClass_UDMFPartyQuickBarWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFPartyQuickBarWidget"),
				Z_Registration_Info_UClass_UDMFPartyQuickBarWidget.InnerSingleton,
				UDMFPartyQuickBarWidget_StaticRegisterNativesUDMFPartyQuickBarWidget,
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
		return Z_Registration_Info_UClass_UDMFPartyQuickBarWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFPartyQuickBarWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFPartyQuickBarWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFPartyQuickBarWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFPartyQuickBarWidget::UDMFPartyQuickBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFPartyQuickBarWidget);
UDMFPartyQuickBarWidget::~UDMFPartyQuickBarWidget() {}
// ********** End Class UDMFPartyQuickBarWidget ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFPartyQuickSlotButton, TEXT("UDMFPartyQuickSlotButton"), &Z_Registration_Info_UClass_UDMFPartyQuickSlotButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFPartyQuickSlotButton), 3429024170U) },
		{ Z_Construct_UClass_UDMFPartyQuickBarWidget, TEXT("UDMFPartyQuickBarWidget"), &Z_Registration_Info_UClass_UDMFPartyQuickBarWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFPartyQuickBarWidget), 1004713328U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h__Script_DigimonMMOFramework_3af2c3161c5c833b9819b9798cd87b1164ba8492{
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
