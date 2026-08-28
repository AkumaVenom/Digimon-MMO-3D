// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/DMFExperienceNotificationWidget.h"
#include "DMFTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFExperienceNotificationWidget() {}

// ********** Begin Cross Module References ********************************************************
UMG_API UClass* Z_Construct_UClass_UUserWidget(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UImage(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UProgressBar(ETypeConstructPhase);
UMG_API UClass* Z_Construct_UClass_UTextBlock(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFExperienceNotificationWidget(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFExperienceNotificationWidget(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UDMFExperienceNotificationWidget Function BP_OnExperienceProgressPresented 
struct DMFExperienceNotificationWidget_eventBP_OnExperienceProgressPresented_Parms
{
	FDMFDigimonExperienceProgression Progression;
};
static FName NAME_UDMFExperienceNotificationWidget_BP_OnExperienceProgressPresented = FName(TEXT("BP_OnExperienceProgressPresented"));
void UDMFExperienceNotificationWidget::BP_OnExperienceProgressPresented(FDMFDigimonExperienceProgression Progression)
{
	DMFExperienceNotificationWidget_eventBP_OnExperienceProgressPresented_Parms Parms;
	Parms.Progression=Progression;
	UFunction* Func = FindFunctionChecked(NAME_UDMFExperienceNotificationWidget_BP_OnExperienceProgressPresented);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFExperienceNotificationWidget_BP_OnExperienceProgressPresented_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Progression" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint reskin hook fired when a queued progression result begins presentation. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint reskin hook fired when a queued progression result begins presentation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnExperienceProgressPresented constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_Progression;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnExperienceProgressPresented constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnExperienceProgressPresented Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Progression = { "Progression", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFExperienceNotificationWidget_eventBP_OnExperienceProgressPresented_Parms, Progression), Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression, METADATA_PARAMS(0, nullptr) }; // 94e02e0ef96f238d9bf716a73264a6be31a7ed80
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Progression,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnExperienceProgressPresented Property Definitions *******************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFExperienceNotificationWidget, nullptr, "BP_OnExperienceProgressPresented", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFExperienceNotificationWidget_eventBP_OnExperienceProgressPresented_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFExperienceNotificationWidget_eventBP_OnExperienceProgressPresented_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFExperienceNotificationWidget_BP_OnExperienceProgressPresented(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFExperienceNotificationWidget Function BP_OnExperienceProgressPresented *

// ********** Begin Class UDMFExperienceNotificationWidget Function BP_OnLevelUpPresented **********
struct DMFExperienceNotificationWidget_eventBP_OnLevelUpPresented_Parms
{
	FDMFDigimonExperienceProgression Progression;
};
static FName NAME_UDMFExperienceNotificationWidget_BP_OnLevelUpPresented = FName(TEXT("BP_OnLevelUpPresented"));
void UDMFExperienceNotificationWidget::BP_OnLevelUpPresented(FDMFDigimonExperienceProgression Progression)
{
	DMFExperienceNotificationWidget_eventBP_OnLevelUpPresented_Parms Parms;
	Parms.Progression=Progression;
	UFunction* Func = FindFunctionChecked(NAME_UDMFExperienceNotificationWidget_BP_OnLevelUpPresented);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFExperienceNotificationWidget_BP_OnLevelUpPresented_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Progression" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Separate hook for projects that want a larger level-up burst/animation. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Separate hook for projects that want a larger level-up burst/animation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnLevelUpPresented constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Progression;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnLevelUpPresented constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnLevelUpPresented Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Progression = { "Progression", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFExperienceNotificationWidget_eventBP_OnLevelUpPresented_Parms, Progression), Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression, METADATA_PARAMS(0, nullptr) }; // 94e02e0ef96f238d9bf716a73264a6be31a7ed80
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Progression,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnLevelUpPresented Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFExperienceNotificationWidget, nullptr, "BP_OnLevelUpPresented", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFExperienceNotificationWidget_eventBP_OnLevelUpPresented_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFExperienceNotificationWidget_eventBP_OnLevelUpPresented_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFExperienceNotificationWidget_BP_OnLevelUpPresented(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UDMFExperienceNotificationWidget Function BP_OnLevelUpPresented ************

// ********** Begin Class UDMFExperienceNotificationWidget Function ShowExperienceProgress *********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UDMFExperienceNotificationWidget_ShowExperienceProgress_Statics
struct UHT_STATICS
{
	struct DMFExperienceNotificationWidget_eventShowExperienceProgress_Parms
	{
		FDMFDigimonExperienceProgression Progression;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Progression" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Queues one authoritative EXP result. Rapid rewards are serialized so no level-up toast is lost. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Queues one authoritative EXP result. Rapid rewards are serialized so no level-up toast is lost." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Progression_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ShowExperienceProgress constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Progression;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ShowExperienceProgress constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ShowExperienceProgress Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Progression = { "Progression", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(DMFExperienceNotificationWidget_eventShowExperienceProgress_Parms, Progression), Z_Construct_UScriptStruct_FDMFDigimonExperienceProgression, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Progression_MetaData), NewProp_Progression_MetaData) }; // 94e02e0ef96f238d9bf716a73264a6be31a7ed80
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Progression,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ShowExperienceProgress Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UDMFExperienceNotificationWidget, nullptr, "ShowExperienceProgress", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFExperienceNotificationWidget_eventShowExperienceProgress_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFExperienceNotificationWidget_eventShowExperienceProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMFExperienceNotificationWidget_ShowExperienceProgress(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UDMFExperienceNotificationWidget::execShowExperienceProgress)
{
	P_GET_STRUCT_REF(FDMFDigimonExperienceProgression,Z_Param_Out_Progression);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowExperienceProgress(Z_Param_Out_Progression);
	P_NATIVE_END;
}
// ********** End Class UDMFExperienceNotificationWidget Function ShowExperienceProgress ***********

// ********** Begin Class UDMFExperienceNotificationWidget *****************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UDMFExperienceNotificationWidget_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Owner-only transient EXP/level-up presentation. The server supplies an immutable progression\n * snapshot; this widget only animates that already-authoritative result locally.\n */" },
#endif
		{ "IncludePath", "UI/DMFExperienceNotificationWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Owner-only transient EXP/level-up presentation. The server supplies an immutable progression\nsnapshot; this widget only animates that already-authoritative result locally." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesPortraitImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFExperienceNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFExperienceNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperienceGainText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFExperienceNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFExperienceNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperienceProgressText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFExperienceNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperienceProgressBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFExperienceNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelUpText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "DMFExperienceNotificationWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/DMFExperienceNotificationWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDMFExperienceNotificationWidget constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesPortraitImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExperienceGainText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LevelText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExperienceProgressText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExperienceProgressBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LevelUpText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDMFExperienceNotificationWidget constinit property declarations ***********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ShowExperienceProgress"), .Pointer = &UDMFExperienceNotificationWidget::execShowExperienceProgress },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMFExperienceNotificationWidget_BP_OnExperienceProgressPresented, "BP_OnExperienceProgressPresented" }, // 8c54e4994ed659999a7b85688bdb23e0cf6d52b0
		{ &Z_Construct_UFunction_UDMFExperienceNotificationWidget_BP_OnLevelUpPresented, "BP_OnLevelUpPresented" }, // 6e8b8a023ffd7af2680b5bca195dd2b226a08642
		{ &Z_Construct_UFunction_UDMFExperienceNotificationWidget_ShowExperienceProgress, "ShowExperienceProgress" }, // 384b489f5dfaf7ff8417e0d34efa9f438e28e230
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMFExperienceNotificationWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UDMFExperienceNotificationWidget Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpeciesPortraitImage = { "SpeciesPortraitImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFExperienceNotificationWidget, SpeciesPortraitImage), Z_Construct_UClass_UImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesPortraitImage_MetaData), NewProp_SpeciesPortraitImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_SpeciesNameText = { "SpeciesNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFExperienceNotificationWidget, SpeciesNameText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesNameText_MetaData), NewProp_SpeciesNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ExperienceGainText = { "ExperienceGainText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFExperienceNotificationWidget, ExperienceGainText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperienceGainText_MetaData), NewProp_ExperienceGainText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_LevelText = { "LevelText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFExperienceNotificationWidget, LevelText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelText_MetaData), NewProp_LevelText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ExperienceProgressText = { "ExperienceProgressText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFExperienceNotificationWidget, ExperienceProgressText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperienceProgressText_MetaData), NewProp_ExperienceProgressText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ExperienceProgressBar = { "ExperienceProgressBar", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFExperienceNotificationWidget, ExperienceProgressBar), Z_Construct_UClass_UProgressBar, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperienceProgressBar_MetaData), NewProp_ExperienceProgressBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_LevelUpText = { "LevelUpText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UDMFExperienceNotificationWidget, LevelUpText), Z_Construct_UClass_UTextBlock, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelUpText_MetaData), NewProp_LevelUpText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesPortraitImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SpeciesNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExperienceGainText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LevelText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExperienceProgressText,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExperienceProgressBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LevelUpText,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UDMFExperienceNotificationWidget Property Definitions **********************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UUserWidget,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UDMFExperienceNotificationWidget,
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
static void UDMFExperienceNotificationWidget_StaticRegisterNativesUDMFExperienceNotificationWidget()
{
	UClass* Class = UDMFExperienceNotificationWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMFExperienceNotificationWidget;
UClass* Z_Construct_UClass_UDMFExperienceNotificationWidget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UDMFExperienceNotificationWidget;
		if (!Z_Registration_Info_UClass_UDMFExperienceNotificationWidget.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFExperienceNotificationWidget"),
				Z_Registration_Info_UClass_UDMFExperienceNotificationWidget.InnerSingleton,
				UDMFExperienceNotificationWidget_StaticRegisterNativesUDMFExperienceNotificationWidget,
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
		return Z_Registration_Info_UClass_UDMFExperienceNotificationWidget.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UDMFExperienceNotificationWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMFExperienceNotificationWidget.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMFExperienceNotificationWidget.OuterSingleton;
}
#undef UHT_STATICS
UDMFExperienceNotificationWidget::UDMFExperienceNotificationWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDMFExperienceNotificationWidget);
UDMFExperienceNotificationWidget::~UDMFExperienceNotificationWidget() {}
// ********** End Class UDMFExperienceNotificationWidget *******************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFExperienceNotificationWidget_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMFExperienceNotificationWidget, TEXT("UDMFExperienceNotificationWidget"), &Z_Registration_Info_UClass_UDMFExperienceNotificationWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMFExperienceNotificationWidget), 683978178U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFExperienceNotificationWidget_h__Script_DigimonMMOFramework_2702dd6d20e3510ed54bd5d05928666e7a7efea2{
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
