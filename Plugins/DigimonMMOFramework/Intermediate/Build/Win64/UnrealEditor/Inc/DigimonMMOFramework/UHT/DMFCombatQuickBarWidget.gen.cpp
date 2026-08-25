// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFCombatQuickBarWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFCombatQuickBarWidget() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UButton(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UHorizontalBox(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFCombatQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFCombatQuickSlotButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFCombatQuickBarWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFCombatQuickSlotButton(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerDigimonComponent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFCombatQuickSlotButton Function HandleClicked *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFCombatQuickSlotButton_HandleClicked_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleClicked constinit property declarations *************************
// ********** End Function HandleClicked constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFCombatQuickSlotButton, nullptr, "HandleClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFCombatQuickSlotButton_HandleClicked(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFCombatQuickSlotButton::execHandleClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleClicked();
	P_NATIVE_END;
}
// ********** End Class UDMFCombatQuickSlotButton Function HandleClicked ***************************

// ********** Begin Class UDMFCombatQuickSlotButton ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFCombatQuickSlotButton_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "UI/DMFCombatQuickBarWidget.h" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFCombatQuickSlotButton constinit property declarations ****************
// ********** End Class UDMFCombatQuickSlotButton constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleClicked"), .Pointer = &UDMFCombatQuickSlotButton::execHandleClicked },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFCombatQuickSlotButton_HandleClicked, "HandleClicked" }, // 4cc323e641d9e503fcfb1d169eaf180db93c8023
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFCombatQuickSlotButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UButton,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFCombatQuickSlotButton,
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
static void UDMFCombatQuickSlotButton_StaticRegisterNativesUDMFCombatQuickSlotButton()
{
	UClass* Class = UDMFCombatQuickSlotButton::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFCombatQuickSlotButton;
UClass* Z_Construct_UClass_UDMFCombatQuickSlotButton(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFCombatQuickSlotButton;
		if (!Z_Registration_Info_UClass_UDMFCombatQuickSlotButton.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFCombatQuickSlotButton"),
				Z_Registration_Info_UClass_UDMFCombatQuickSlotButton.InnerSingleton,
				UDMFCombatQuickSlotButton_StaticRegisterNativesUDMFCombatQuickSlotButton,
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
		return Z_Registration_Info_UClass_UDMFCombatQuickSlotButton.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFCombatQuickSlotButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFCombatQuickSlotButton.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFCombatQuickSlotButton.OuterSingleton;
}
#undef UHT_STATICS
UDMFCombatQuickSlotButton::UDMFCombatQuickSlotButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFCombatQuickSlotButton);
UDMFCombatQuickSlotButton::~UDMFCombatQuickSlotButton() {}
// ********** End Class UDMFCombatQuickSlotButton **************************************************

// ********** Begin Class UDMFCombatQuickBarWidget Function BP_OnQuickBarRefreshed *****************
static FName NAME_UDMFCombatQuickBarWidget_BP_OnQuickBarRefreshed = FName(TEXT("BP_OnQuickBarRefreshed"));
void UDMFCombatQuickBarWidget::BP_OnQuickBarRefreshed()
{
	UFunction* Func = FindFunctionChecked(NAME_UDMFCombatQuickBarWidget_BP_OnQuickBarRefreshed);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFCombatQuickBarWidget_BP_OnQuickBarRefreshed_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat UI" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnQuickBarRefreshed constinit property declarations ****************
// ********** End Function BP_OnQuickBarRefreshed constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFCombatQuickBarWidget, nullptr, "BP_OnQuickBarRefreshed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFCombatQuickBarWidget_BP_OnQuickBarRefreshed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFCombatQuickBarWidget Function BP_OnQuickBarRefreshed *******************

// ********** Begin Class UDMFCombatQuickBarWidget Function ExecuteAbilitySlot *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFCombatQuickBarWidget_ExecuteAbilitySlot_Statics
struct UHT_STATICS
{
	struct DMFCombatQuickBarWidget_eventExecuteAbilitySlot_Parms
	{
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat UI" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteAbilitySlot constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteAbilitySlot constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteAbilitySlot Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(DMFCombatQuickBarWidget_eventExecuteAbilitySlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ExecuteAbilitySlot Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFCombatQuickBarWidget, nullptr, "ExecuteAbilitySlot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFCombatQuickBarWidget_eventExecuteAbilitySlot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFCombatQuickBarWidget_eventExecuteAbilitySlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFCombatQuickBarWidget_ExecuteAbilitySlot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFCombatQuickBarWidget::execExecuteAbilitySlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExecuteAbilitySlot(Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UDMFCombatQuickBarWidget Function ExecuteAbilitySlot ***********************

// ********** Begin Class UDMFCombatQuickBarWidget Function RefreshFromPartner *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFCombatQuickBarWidget_RefreshFromPartner_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat UI" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshFromPartner constinit property declarations ********************
// ********** End Function RefreshFromPartner constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFCombatQuickBarWidget, nullptr, "RefreshFromPartner", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UDMFCombatQuickBarWidget_RefreshFromPartner(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFCombatQuickBarWidget::execRefreshFromPartner)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshFromPartner();
	P_NATIVE_END;
}
// ********** End Class UDMFCombatQuickBarWidget Function RefreshFromPartner ***********************

// ********** Begin Class UDMFCombatQuickBarWidget *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFCombatQuickBarWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Native fallback quick-access ability bar. Blueprint subclasses can completely reskin it. */" },
#endif
		{ "IncludePath", "UI/DMFCombatQuickBarWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native fallback quick-access ability bar. Blueprint subclasses can completely reskin it." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFCombatQuickBarWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFCombatQuickBarWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VitalsText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFCombatQuickBarWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundDigimonComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeSlotLabels_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeSlotIcons_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFCombatQuickBarWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFCombatQuickBarWidget constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilityBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VitalsText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundDigimonComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NativeSlotLabels_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NativeSlotLabels;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NativeSlotIcons_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NativeSlotIcons;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFCombatQuickBarWidget constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ExecuteAbilitySlot"), .Pointer = &UDMFCombatQuickBarWidget::execExecuteAbilitySlot },
		{ .NameUTF8 = UTF8TEXT("RefreshFromPartner"), .Pointer = &UDMFCombatQuickBarWidget::execRefreshFromPartner },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFCombatQuickBarWidget_BP_OnQuickBarRefreshed, "BP_OnQuickBarRefreshed" }, // df17361216aff15ae3ede946e229ae3f56ba303c
		{ &Z_Construct_UFunction_UDMFCombatQuickBarWidget_ExecuteAbilitySlot, "ExecuteAbilitySlot" }, // 2f61dedb5ceb36c5920e267a7f8aa3c223208f28
		{ &Z_Construct_UFunction_UDMFCombatQuickBarWidget_RefreshFromPartner, "RefreshFromPartner" }, // b552c7055f5879ec7db22c8c802bfca6b1d081dc
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFCombatQuickBarWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFCombatQuickBarWidget Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AbilityBox = { "AbilityBox", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFCombatQuickBarWidget, AbilityBox), Z_Construct_UClass_UHorizontalBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityBox_MetaData), NewProp_AbilityBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_TargetText = { "TargetText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFCombatQuickBarWidget, TargetText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetText_MetaData), NewProp_TargetText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VitalsText = { "VitalsText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFCombatQuickBarWidget, VitalsText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VitalsText_MetaData), NewProp_VitalsText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BoundDigimonComponent = { "BoundDigimonComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFCombatQuickBarWidget, BoundDigimonComponent), Z_Construct_UClass_UDMFPlayerDigimonComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundDigimonComponent_MetaData), NewProp_BoundDigimonComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NativeSlotLabels_Inner = { "NativeSlotLabels", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTextBlock, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_NativeSlotLabels = { "NativeSlotLabels", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFCombatQuickBarWidget, NativeSlotLabels), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeSlotLabels_MetaData), NewProp_NativeSlotLabels_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NativeSlotIcons_Inner = { "NativeSlotIcons", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, 0, Z_Construct_UClass_UImage, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_NativeSlotIcons = { "NativeSlotIcons", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFCombatQuickBarWidget, NativeSlotIcons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeSlotIcons_MetaData), NewProp_NativeSlotIcons_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AbilityBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VitalsText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BoundDigimonComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeSlotLabels_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeSlotLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeSlotIcons_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NativeSlotIcons,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFCombatQuickBarWidget Property Definitions ******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFCombatQuickBarWidget,
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
static void UDMFCombatQuickBarWidget_StaticRegisterNativesUDMFCombatQuickBarWidget()
{
	UClass* Class = UDMFCombatQuickBarWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFCombatQuickBarWidget;
UClass* Z_Construct_UClass_UDMFCombatQuickBarWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFCombatQuickBarWidget;
		if (!Z_Registration_Info_UClass_UDMFCombatQuickBarWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFCombatQuickBarWidget"),
				Z_Registration_Info_UClass_UDMFCombatQuickBarWidget.InnerSingleton,
				UDMFCombatQuickBarWidget_StaticRegisterNativesUDMFCombatQuickBarWidget,
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
		return Z_Registration_Info_UClass_UDMFCombatQuickBarWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFCombatQuickBarWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFCombatQuickBarWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFCombatQuickBarWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFCombatQuickBarWidget::UDMFCombatQuickBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFCombatQuickBarWidget);
UDMFCombatQuickBarWidget::~UDMFCombatQuickBarWidget() {}
// ********** End Class UDMFCombatQuickBarWidget ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFCombatQuickBarWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFCombatQuickSlotButton, TEXT("UDMFCombatQuickSlotButton"), &Z_Registration_Info_UClass_UDMFCombatQuickSlotButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFCombatQuickSlotButton), 1639362280U) },
		{ Z_Construct_UClass_UDMFCombatQuickBarWidget, TEXT("UDMFCombatQuickBarWidget"), &Z_Registration_Info_UClass_UDMFCombatQuickBarWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFCombatQuickBarWidget), 3141615348U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFCombatQuickBarWidget_h__Script_DigimonMMOFramework_cb13ef3d6c15d2143222e76a56b6f48a7505491a{
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
