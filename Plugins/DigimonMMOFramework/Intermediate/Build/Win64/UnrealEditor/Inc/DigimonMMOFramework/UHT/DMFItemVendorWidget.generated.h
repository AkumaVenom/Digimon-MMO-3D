// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/DMFItemVendorWidget.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFItemVendorWidget_generated_h
#error "DMFItemVendorWidget.generated.h already included, missing '#pragma once' in DMFItemVendorWidget.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFItemVendorWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ADMFItemVendorActor;
enum class EDMFItemVendorTransactionType : uint8;
struct FGuid;
struct FPrimaryAssetId;

// ********** Begin Class UDMFItemVendorEntryButton ************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandlePressed); \
	DECLARE_FUNCTION(execInitializeItemVendorEntry);


struct Z_Construct_UClass_UDMFItemVendorEntryButton_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemVendorEntryButton(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_22_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFItemVendorEntryButton_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFItemVendorEntryButton(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFItemVendorEntryButton, UButton, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFItemVendorEntryButton) \
	DECLARE_SERIALIZER(UDMFItemVendorEntryButton)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFItemVendorEntryButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFItemVendorEntryButton(UDMFItemVendorEntryButton&&) = delete; \
	UDMFItemVendorEntryButton(const UDMFItemVendorEntryButton&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFItemVendorEntryButton); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFItemVendorEntryButton); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFItemVendorEntryButton) \
	NO_API virtual ~UDMFItemVendorEntryButton();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_19_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_22_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFItemVendorEntryButton;

// ********** End Class UDMFItemVendorEntryButton **************************************************

// ********** Begin Class UDMFItemVendorWidget *****************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleHeaderTimer); \
	DECLARE_FUNCTION(execHandleVendorTransactionResult); \
	DECLARE_FUNCTION(execHandleMoneyChanged); \
	DECLARE_FUNCTION(execHandleItemInventoryChanged); \
	DECLARE_FUNCTION(execHandleVendorConfigurationChanged); \
	DECLARE_FUNCTION(execHandleVendorEnabledChanged); \
	DECLARE_FUNCTION(execHandleVendorStockChanged); \
	DECLARE_FUNCTION(execHandleCloseClicked); \
	DECLARE_FUNCTION(execHandleTransactionClicked); \
	DECLARE_FUNCTION(execHandleQuantityMax); \
	DECLARE_FUNCTION(execHandleQuantityPlusTen); \
	DECLARE_FUNCTION(execHandleQuantityPlusOne); \
	DECLARE_FUNCTION(execHandleQuantityMinusOne); \
	DECLARE_FUNCTION(execHandleQuantityMinusTen); \
	DECLARE_FUNCTION(execHandleEntryPressed); \
	DECLARE_FUNCTION(execHandleSellTabClicked); \
	DECLARE_FUNCTION(execHandleBuyTabClicked); \
	DECLARE_FUNCTION(execGetSelectedQuantity); \
	DECLARE_FUNCTION(execGetVendorTab); \
	DECLARE_FUNCTION(execGetVendor); \
	DECLARE_FUNCTION(execSetVendorTab); \
	DECLARE_FUNCTION(execRefreshVendorUI); \
	DECLARE_FUNCTION(execInitializeVendor);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_41_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDMFItemVendorWidget_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFItemVendorWidget(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_41_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFItemVendorWidget_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFItemVendorWidget(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFItemVendorWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFItemVendorWidget) \
	DECLARE_SERIALIZER(UDMFItemVendorWidget)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_41_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFItemVendorWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFItemVendorWidget(UDMFItemVendorWidget&&) = delete; \
	UDMFItemVendorWidget(const UDMFItemVendorWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFItemVendorWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFItemVendorWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFItemVendorWidget) \
	NO_API virtual ~UDMFItemVendorWidget();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_38_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_41_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_41_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_41_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h_41_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFItemVendorWidget;

// ********** End Class UDMFItemVendorWidget *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFItemVendorWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
