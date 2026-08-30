// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFItemVendorActor.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFItemVendorActor_generated_h
#error "DMFItemVendorActor.generated.h already included, missing '#pragma once' in DMFItemVendorActor.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFItemVendorActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ADMFMMOPlayerController;
class APlayerController;
enum class EDMFItemVendorTransactionType : uint8;
struct FDMFItemVendorPricingSettings;
struct FDMFItemVendorStockItem;
struct FPrimaryAssetId;

// ********** Begin ScriptStruct FDMFItemVendorPoolEntry *******************************************
struct Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry_Statics;
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_19_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FDMFItemVendorPoolEntry(ETypeConstructPhase::Inner); }


struct FDMFItemVendorPoolEntry;
// ********** End ScriptStruct FDMFItemVendorPoolEntry *********************************************

// ********** Begin ScriptStruct FDMFItemVendorPricingSettings *************************************
struct Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings_Statics;
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_43_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FDMFItemVendorPricingSettings(ETypeConstructPhase::Inner); }


struct FDMFItemVendorPricingSettings;
// ********** End ScriptStruct FDMFItemVendorPricingSettings ***************************************

// ********** Begin ScriptStruct FDMFItemVendorStockItem *******************************************
struct Z_Construct_UScriptStruct_FDMFItemVendorStockItem_Statics;
DIGIMONMMOFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDMFItemVendorStockItem(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_62_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDMFItemVendorStockItem_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FDMFItemVendorStockItem(ETypeConstructPhase::Inner); }


struct FDMFItemVendorStockItem;
// ********** End ScriptStruct FDMFItemVendorStockItem *********************************************

// ********** Begin Class ADMFItemVendorActor ******************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_89_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_Configuration); \
	DECLARE_FUNCTION(execOnRep_VendorEnabled); \
	DECLARE_FUNCTION(execOnRep_Stock); \
	DECLARE_FUNCTION(execRestartStockRotationSchedule); \
	DECLARE_FUNCTION(execRefreshStockNow); \
	DECLARE_FUNCTION(execSetPricingSettings); \
	DECLARE_FUNCTION(execSetSellingEnabled); \
	DECLARE_FUNCTION(execSetBuyingEnabled); \
	DECLARE_FUNCTION(execSetVendorEnabled); \
	DECLARE_FUNCTION(execIsPlayerWithinTradeRange); \
	DECLARE_FUNCTION(execIsItemSellable); \
	DECLARE_FUNCTION(execGetPlayerSellUnitPrice); \
	DECLARE_FUNCTION(execGetSecondsUntilStockRotation); \
	DECLARE_FUNCTION(execIsVendorEnabled); \
	DECLARE_FUNCTION(execGetVendorStock);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_89_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFItemVendorActor_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFItemVendorActor(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_89_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFItemVendorActor_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFItemVendorActor(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFItemVendorActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFItemVendorActor) \
	DECLARE_SERIALIZER(ADMFItemVendorActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bVendorEnabled=NETFIELD_REP_START, \
		bAllowBuying, \
		bAllowSelling, \
		bRequireItemInStockPoolToSell, \
		Pricing, \
		ReplicatedStock, \
		StockGenerationSerial, \
		NextStockRotationServerTimeSeconds, \
		NETFIELD_REP_END=NextStockRotationServerTimeSeconds	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_89_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFItemVendorActor(ADMFItemVendorActor&&) = delete; \
	ADMFItemVendorActor(const ADMFItemVendorActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFItemVendorActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFItemVendorActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADMFItemVendorActor) \
	NO_API virtual ~ADMFItemVendorActor();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_86_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_89_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_89_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_89_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_89_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h_89_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFItemVendorActor;

// ********** End Class ADMFItemVendorActor ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFItemVendorActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
