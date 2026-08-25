// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/DMFMMOGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeDMFMMOGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameMode(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_APlayerController(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_DigimonMMOFramework(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOGameMode(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOGameMode(ETypeConstructPhase);
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFPlayerAvatarCharacter(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ADMFMMOGameMode Function BP_OnFrameworkPlayerAvatarRecovered *************
struct DMFMMOGameMode_eventBP_OnFrameworkPlayerAvatarRecovered_Parms
{
	APlayerController* PlayerController;
	ADMFPlayerAvatarCharacter* AvatarPawn;
};
static FName NAME_ADMFMMOGameMode_BP_OnFrameworkPlayerAvatarRecovered = FName(TEXT("BP_OnFrameworkPlayerAvatarRecovered"));
void ADMFMMOGameMode::BP_OnFrameworkPlayerAvatarRecovered(APlayerController* PlayerController, ADMFPlayerAvatarCharacter* AvatarPawn)
{
	DMFMMOGameMode_eventBP_OnFrameworkPlayerAvatarRecovered_Parms Parms;
	Parms.PlayerController=PlayerController;
	Parms.AvatarPawn=AvatarPawn;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOGameMode_BP_OnFrameworkPlayerAvatarRecovered);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOGameMode_BP_OnFrameworkPlayerAvatarRecovered_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Networking|Player Spawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Presentation/diagnostic hook fired after an invalid or missing pawn was recovered. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Presentation/diagnostic hook fired after an invalid or missing pawn was recovered." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnFrameworkPlayerAvatarRecovered constinit property declarations ***
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AvatarPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnFrameworkPlayerAvatarRecovered constinit property declarations *****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnFrameworkPlayerAvatarRecovered Property Definitions **************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOGameMode_eventBP_OnFrameworkPlayerAvatarRecovered_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AvatarPawn = { "AvatarPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOGameMode_eventBP_OnFrameworkPlayerAvatarRecovered_Parms, AvatarPawn), Z_Construct_UClass_ADMFPlayerAvatarCharacter, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AvatarPawn,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnFrameworkPlayerAvatarRecovered Property Definitions ****************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOGameMode, nullptr, "BP_OnFrameworkPlayerAvatarRecovered", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOGameMode_eventBP_OnFrameworkPlayerAvatarRecovered_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOGameMode_eventBP_OnFrameworkPlayerAvatarRecovered_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOGameMode_BP_OnFrameworkPlayerAvatarRecovered(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFMMOGameMode Function BP_OnFrameworkPlayerAvatarRecovered ***************

// ********** Begin Class ADMFMMOGameMode Function BP_OnPlayerAccountLoaded ************************
struct DMFMMOGameMode_eventBP_OnPlayerAccountLoaded_Parms
{
	APlayerController* PlayerController;
	FString Username;
	bool bNewAccount;
};
static FName NAME_ADMFMMOGameMode_BP_OnPlayerAccountLoaded = FName(TEXT("BP_OnPlayerAccountLoaded"));
void ADMFMMOGameMode::BP_OnPlayerAccountLoaded(APlayerController* PlayerController, const FString& Username, bool bNewAccount)
{
	DMFMMOGameMode_eventBP_OnPlayerAccountLoaded_Parms Parms;
	Parms.PlayerController=PlayerController;
	Parms.Username=Username;
	Parms.bNewAccount=bNewAccount ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ADMFMMOGameMode_BP_OnPlayerAccountLoaded);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOGameMode_BP_OnPlayerAccountLoaded_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Account" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Username_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnPlayerAccountLoaded constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Username;
	static void NewProp_bNewAccount_SetBit(void* Obj)
	{
		((DMFMMOGameMode_eventBP_OnPlayerAccountLoaded_Parms*)Obj)->bNewAccount = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewAccount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnPlayerAccountLoaded constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnPlayerAccountLoaded Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOGameMode_eventBP_OnPlayerAccountLoaded_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Username = { "Username", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOGameMode_eventBP_OnPlayerAccountLoaded_Parms, Username), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Username_MetaData), NewProp_Username_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bNewAccount = { "bNewAccount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOGameMode_eventBP_OnPlayerAccountLoaded_Parms), &UHT_STATICS::NewProp_bNewAccount_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Username,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bNewAccount,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BP_OnPlayerAccountLoaded Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOGameMode, nullptr, "BP_OnPlayerAccountLoaded", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<DMFMMOGameMode_eventBP_OnPlayerAccountLoaded_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(DMFMMOGameMode_eventBP_OnPlayerAccountLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOGameMode_BP_OnPlayerAccountLoaded(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class ADMFMMOGameMode Function BP_OnPlayerAccountLoaded **************************

// ********** Begin Class ADMFMMOGameMode Function EnsureFrameworkPlayerAvatar *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOGameMode_EnsureFrameworkPlayerAvatar_Statics
struct UHT_STATICS
{
	struct DMFMMOGameMode_eventEnsureFrameworkPlayerAvatar_Parms
	{
		APlayerController* PlayerController;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Networking|Player Spawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Server-authoritative recovery/validation hook for late-joining players. Ensures the controller owns\n     * a DMF player-avatar pawn, force-resynchronizes possession to the owning client, reapplies the\n     * account skin, and restores the active partner when onboarding allows it.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-authoritative recovery/validation hook for late-joining players. Ensures the controller owns\na DMF player-avatar pawn, force-resynchronizes possession to the owning client, reapplies the\naccount skin, and restores the active partner when onboarding allows it." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function EnsureFrameworkPlayerAvatar constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOGameMode_eventEnsureFrameworkPlayerAvatar_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EnsureFrameworkPlayerAvatar constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EnsureFrameworkPlayerAvatar Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOGameMode_eventEnsureFrameworkPlayerAvatar_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOGameMode_eventEnsureFrameworkPlayerAvatar_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function EnsureFrameworkPlayerAvatar Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOGameMode, nullptr, "EnsureFrameworkPlayerAvatar", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOGameMode_eventEnsureFrameworkPlayerAvatar_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020405, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOGameMode_eventEnsureFrameworkPlayerAvatar_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOGameMode_EnsureFrameworkPlayerAvatar(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOGameMode::execEnsureFrameworkPlayerAvatar)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->EnsureFrameworkPlayerAvatar(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOGameMode Function EnsureFrameworkPlayerAvatar ***********************

// ********** Begin Class ADMFMMOGameMode Function HasFrameworkPlayerAvatar ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ADMFMMOGameMode_HasFrameworkPlayerAvatar_Statics
struct UHT_STATICS
{
	struct DMFMMOGameMode_eventHasFrameworkPlayerAvatar_Parms
	{
		APlayerController* PlayerController;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Digimon MMO|Networking|Player Spawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns true when the controller currently owns a valid framework player-avatar pawn. */" },
#endif
		{ "ModuleRelativePath", "Public/Game/DMFMMOGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true when the controller currently owns a valid framework player-avatar pawn." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HasFrameworkPlayerAvatar constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DMFMMOGameMode_eventHasFrameworkPlayerAvatar_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasFrameworkPlayerAvatar constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasFrameworkPlayerAvatar Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(DMFMMOGameMode_eventHasFrameworkPlayerAvatar_Parms, PlayerController), Z_Construct_UClass_APlayerController, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(DMFMMOGameMode_eventHasFrameworkPlayerAvatar_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HasFrameworkPlayerAvatar Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ADMFMMOGameMode, nullptr, "HasFrameworkPlayerAvatar", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::DMFMMOGameMode_eventHasFrameworkPlayerAvatar_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::DMFMMOGameMode_eventHasFrameworkPlayerAvatar_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMFMMOGameMode_HasFrameworkPlayerAvatar(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ADMFMMOGameMode::execHasFrameworkPlayerAvatar)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasFrameworkPlayerAvatar(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class ADMFMMOGameMode Function HasFrameworkPlayerAvatar **************************

// ********** Begin Class ADMFMMOGameMode **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ADMFMMOGameMode_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Game/DMFMMOGameMode.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Game/DMFMMOGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA

// ********** Begin Class ADMFMMOGameMode constinit property declarations **************************
// ********** End Class ADMFMMOGameMode constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("EnsureFrameworkPlayerAvatar"), .Pointer = &ADMFMMOGameMode::execEnsureFrameworkPlayerAvatar },
		{ .NameUTF8 = UTF8TEXT("HasFrameworkPlayerAvatar"), .Pointer = &ADMFMMOGameMode::execHasFrameworkPlayerAvatar },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMFMMOGameMode_BP_OnFrameworkPlayerAvatarRecovered, "BP_OnFrameworkPlayerAvatarRecovered" }, // 6f0ea1ae4023958db8fa133b8be0b1c83968dc61
		{ &Z_Construct_UFunction_ADMFMMOGameMode_BP_OnPlayerAccountLoaded, "BP_OnPlayerAccountLoaded" }, // f02a391e4384c986783ae67a84e773493f474b6f
		{ &Z_Construct_UFunction_ADMFMMOGameMode_EnsureFrameworkPlayerAvatar, "EnsureFrameworkPlayerAvatar" }, // 7ccb9f3f91f51e0daedd94afae698fc94df920fa
		{ &Z_Construct_UFunction_ADMFMMOGameMode_HasFrameworkPlayerAvatar, "HasFrameworkPlayerAvatar" }, // 8494791abd92585c160a0fb97479552e9dc7af1c
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMFMMOGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AGameMode,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_DigimonMMOFramework,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ADMFMMOGameMode,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void ADMFMMOGameMode_StaticRegisterNativesADMFMMOGameMode()
{
	UClass* Class = ADMFMMOGameMode::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMFMMOGameMode;
UClass* Z_Construct_UClass_ADMFMMOGameMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ADMFMMOGameMode;
		if (!Z_Registration_Info_UClass_ADMFMMOGameMode.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("DMFMMOGameMode"),
				Z_Registration_Info_UClass_ADMFMMOGameMode.InnerSingleton,
				ADMFMMOGameMode_StaticRegisterNativesADMFMMOGameMode,
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
		return Z_Registration_Info_UClass_ADMFMMOGameMode.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ADMFMMOGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMFMMOGameMode.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMFMMOGameMode.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ADMFMMOGameMode);
ADMFMMOGameMode::~ADMFMMOGameMode() {}
// ********** End Class ADMFMMOGameMode ************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOGameMode_h__Script_DigimonMMOFramework_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMFMMOGameMode, TEXT("ADMFMMOGameMode"), &Z_Registration_Info_UClass_ADMFMMOGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMFMMOGameMode), 759395495U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOGameMode_h__Script_DigimonMMOFramework_e3c1b2515b84716c5f930940782a0bead018cdfe{
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
