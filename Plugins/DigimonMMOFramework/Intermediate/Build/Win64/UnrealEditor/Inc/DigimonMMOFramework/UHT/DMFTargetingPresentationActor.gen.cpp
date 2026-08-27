// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFTargetingPresentationActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFTargetingPresentationActor() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USceneComponent(ETypeConstructPhase);
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent(ETypeConstructPhase);
PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFTargetingPresentationActor(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFDigimonCharacter(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFTargetingPresentationActor(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ADMFTargetingPresentationActor Function GetPresentedActivePartner ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFTargetingPresentationActor_GetPresentedActivePartner_Statics
struct UHT_STATICS
{
	struct DMFTargetingPresentationActor_eventGetPresentedActivePartner_Parms
	{
		ADMFDigimonCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPresentedActivePartner constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPresentedActivePartner constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPresentedActivePartner Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFTargetingPresentationActor_eventGetPresentedActivePartner_Parms, ReturnValue), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetPresentedActivePartner Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFTargetingPresentationActor, nullptr, "GetPresentedActivePartner", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFTargetingPresentationActor_eventGetPresentedActivePartner_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFTargetingPresentationActor_eventGetPresentedActivePartner_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFTargetingPresentationActor_GetPresentedActivePartner(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFTargetingPresentationActor::execGetPresentedActivePartner)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFDigimonCharacter**)Z_Param__Result=P_THIS->GetPresentedActivePartner();
	P_NATIVE_END;
}
// ********** End Class ADMFTargetingPresentationActor Function GetPresentedActivePartner **********

// ********** Begin Class ADMFTargetingPresentationActor Function GetPresentedCommandTarget ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFTargetingPresentationActor_GetPresentedCommandTarget_Statics
struct UHT_STATICS
{
	struct DMFTargetingPresentationActor_eventGetPresentedCommandTarget_Parms
	{
		ADMFDigimonCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPresentedCommandTarget constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPresentedCommandTarget constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPresentedCommandTarget Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFTargetingPresentationActor_eventGetPresentedCommandTarget_Parms, ReturnValue), Z_Construct_UClass_ADMFDigimonCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetPresentedCommandTarget Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFTargetingPresentationActor, nullptr, "GetPresentedCommandTarget", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFTargetingPresentationActor_eventGetPresentedCommandTarget_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFTargetingPresentationActor_eventGetPresentedCommandTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFTargetingPresentationActor_GetPresentedCommandTarget(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFTargetingPresentationActor::execGetPresentedCommandTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ADMFDigimonCharacter**)Z_Param__Result=P_THIS->GetPresentedCommandTarget();
	P_NATIVE_END;
}
// ********** End Class ADMFTargetingPresentationActor Function GetPresentedCommandTarget **********

// ********** Begin Class ADMFTargetingPresentationActor Function RefreshPresentationAssets ********
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFTargetingPresentationActor_RefreshPresentationAssets_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-reads Project Settings assets/tuning and reapplies the local presentation. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-reads Project Settings assets/tuning and reapplies the local presentation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshPresentationAssets constinit property declarations *************
// ********** End Function RefreshPresentationAssets constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFTargetingPresentationActor, nullptr, "RefreshPresentationAssets", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ADMFTargetingPresentationActor_RefreshPresentationAssets(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFTargetingPresentationActor::execRefreshPresentationAssets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshPresentationAssets();
	P_NATIVE_END;
}
// ********** End Class ADMFTargetingPresentationActor Function RefreshPresentationAssets **********

// ********** Begin Class ADMFTargetingPresentationActor *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFTargetingPresentationActor_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Local-only combat-selection presentation owned by one local player controller.\n *\n * This actor intentionally does not replicate. It reconstructs presentation from the owning player's\n * already owner-only ActivePartnerActor / CommandTarget state, so one MMO client never sees another\n * player's blue partner ring, red target ring, or target arrow.\n */" },
#endif
		{ "IncludePath", "Game/DMFTargetingPresentationActor.h" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local-only combat-selection presentation owned by one local player controller.\n\nThis actor intentionally does not replicate. It reconstructs presentation from the owning player's\nalready owner-only ActivePartnerActor / CommandTarget state, so one MMO client never sees another\nplayer's blue partner ring, red target ring, or target arrow." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresentationRoot_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivePartnerRingPivot_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivePartnerRingSprite_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetRingPivot_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetRingSprite_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetArrowNiagara_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTargetArrowCascade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Digimon MMO|Combat|Targeting Visuals" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFTargetingPresentationActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFTargetingPresentationActor constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PresentationRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActivePartnerRingPivot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActivePartnerRingSprite;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyTargetRingPivot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyTargetRingSprite;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyTargetArrowNiagara;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyTargetArrowCascade;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ADMFTargetingPresentationActor constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetPresentedActivePartner"), .Pointer = &ADMFTargetingPresentationActor::execGetPresentedActivePartner },
		{ .NameUTF8 = UTF8TEXT("GetPresentedCommandTarget"), .Pointer = &ADMFTargetingPresentationActor::execGetPresentedCommandTarget },
		{ .NameUTF8 = UTF8TEXT("RefreshPresentationAssets"), .Pointer = &ADMFTargetingPresentationActor::execRefreshPresentationAssets },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFTargetingPresentationActor_GetPresentedActivePartner, "GetPresentedActivePartner" }, // db626296d3cdf313d6c69009cba397d6b34b2664
		{ &Z_Construct_UFunction_ADMFTargetingPresentationActor_GetPresentedCommandTarget, "GetPresentedCommandTarget" }, // 501d76db374738985b778499ffbe085064776986
		{ &Z_Construct_UFunction_ADMFTargetingPresentationActor_RefreshPresentationAssets, "RefreshPresentationAssets" }, // f110b096cf08715f07ea3c774eb3a74703367181
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFTargetingPresentationActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ADMFTargetingPresentationActor Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PresentationRoot = { "PresentationRoot", nullptr, (EPropertyFlags)0x01440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFTargetingPresentationActor, PresentationRoot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresentationRoot_MetaData), NewProp_PresentationRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActivePartnerRingPivot = { "ActivePartnerRingPivot", nullptr, (EPropertyFlags)0x01440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFTargetingPresentationActor, ActivePartnerRingPivot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivePartnerRingPivot_MetaData), NewProp_ActivePartnerRingPivot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ActivePartnerRingSprite = { "ActivePartnerRingSprite", nullptr, (EPropertyFlags)0x01440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFTargetingPresentationActor, ActivePartnerRingSprite), Z_Construct_UClass_UPaperSpriteComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivePartnerRingSprite_MetaData), NewProp_ActivePartnerRingSprite_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_EnemyTargetRingPivot = { "EnemyTargetRingPivot", nullptr, (EPropertyFlags)0x01440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFTargetingPresentationActor, EnemyTargetRingPivot), Z_Construct_UClass_USceneComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetRingPivot_MetaData), NewProp_EnemyTargetRingPivot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_EnemyTargetRingSprite = { "EnemyTargetRingSprite", nullptr, (EPropertyFlags)0x01440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFTargetingPresentationActor, EnemyTargetRingSprite), Z_Construct_UClass_UPaperSpriteComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetRingSprite_MetaData), NewProp_EnemyTargetRingSprite_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_EnemyTargetArrowNiagara = { "EnemyTargetArrowNiagara", nullptr, (EPropertyFlags)0x01440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFTargetingPresentationActor, EnemyTargetArrowNiagara), Z_Construct_UClass_UNiagaraComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetArrowNiagara_MetaData), NewProp_EnemyTargetArrowNiagara_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_EnemyTargetArrowCascade = { "EnemyTargetArrowCascade", nullptr, (EPropertyFlags)0x01440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ADMFTargetingPresentationActor, EnemyTargetArrowCascade), Z_Construct_UClass_UParticleSystemComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTargetArrowCascade_MetaData), NewProp_EnemyTargetArrowCascade_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PresentationRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActivePartnerRingPivot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActivePartnerRingSprite,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetRingPivot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetRingSprite,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetArrowNiagara,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EnemyTargetArrowCascade,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ADMFTargetingPresentationActor Property Definitions ************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFTargetingPresentationActor,
	"Engine",
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
static void ADMFTargetingPresentationActor_StaticRegisterNativesADMFTargetingPresentationActor()
{
	UClass* Class = ADMFTargetingPresentationActor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFTargetingPresentationActor;
UClass* Z_Construct_UClass_ADMFTargetingPresentationActor(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFTargetingPresentationActor;
		if (!Z_Registration_Info_UClass_ADMFTargetingPresentationActor.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFTargetingPresentationActor"),
				Z_Registration_Info_UClass_ADMFTargetingPresentationActor.InnerSingleton,
				ADMFTargetingPresentationActor_StaticRegisterNativesADMFTargetingPresentationActor,
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
		return Z_Registration_Info_UClass_ADMFTargetingPresentationActor.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFTargetingPresentationActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFTargetingPresentationActor.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFTargetingPresentationActor.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFTargetingPresentationActor);
ADMFTargetingPresentationActor::~ADMFTargetingPresentationActor() {}
// ********** End Class ADMFTargetingPresentationActor *********************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFTargetingPresentationActor_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFTargetingPresentationActor, TEXT("ADMFTargetingPresentationActor"), &Z_Registration_Info_UClass_ADMFTargetingPresentationActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFTargetingPresentationActor), 3757768612U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFTargetingPresentationActor_h__Script_DigimonMMOFramework_4053a5b5ba8f444b07247185a01d372dc35ad0ee{
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
