// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/DMFDigimonVendorWidget.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFDigimonVendorWidget_generated_h
#error "DMFDigimonVendorWidget.generated.h already included, missing '#pragma once' in DMFDigimonVendorWidget.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFDigimonVendorWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ADMFDigimonVendorActor;
enum class EDMFDigimonVendorTransactionType : uint8;
struct FGuid;

// ********** Begin Class UDMFDigimonVendorEntryButton *********************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandlePressed); \
	DECLARE_FUNCTION(execInitializeVendorEntry);


struct Z_Construct_UClass_UDMFDigimonVendorEntryButton_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonVendorEntryButton(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_21_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFDigimonVendorEntryButton_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFDigimonVendorEntryButton(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFDigimonVendorEntryButton, UButton, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFDigimonVendorEntryButton) \
	DECLARE_SERIALIZER(UDMFDigimonVendorEntryButton)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFDigimonVendorEntryButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFDigimonVendorEntryButton(UDMFDigimonVendorEntryButton&&) = delete; \
	UDMFDigimonVendorEntryButton(const UDMFDigimonVendorEntryButton&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFDigimonVendorEntryButton); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFDigimonVendorEntryButton); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFDigimonVendorEntryButton) \
	NO_API virtual ~UDMFDigimonVendorEntryButton();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_18_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_21_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFDigimonVendorEntryButton;

// ********** End Class UDMFDigimonVendorEntryButton ***********************************************

// ********** Begin Class UDMFDigimonVendorWidget **************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_39_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleHeaderTimer); \
	DECLARE_FUNCTION(execHandleVendorTransactionResult); \
	DECLARE_FUNCTION(execHandleMoneyChanged); \
	DECLARE_FUNCTION(execHandleBankChanged); \
	DECLARE_FUNCTION(execHandlePartyChanged); \
	DECLARE_FUNCTION(execHandleVendorConfigurationChanged); \
	DECLARE_FUNCTION(execHandleVendorEnabledChanged); \
	DECLARE_FUNCTION(execHandleVendorStockChanged); \
	DECLARE_FUNCTION(execHandleCloseClicked); \
	DECLARE_FUNCTION(execHandleTransactionClicked); \
	DECLARE_FUNCTION(execHandleEntryPressed); \
	DECLARE_FUNCTION(execHandleSellTabClicked); \
	DECLARE_FUNCTION(execHandleBuyTabClicked); \
	DECLARE_FUNCTION(execGetVendorTab); \
	DECLARE_FUNCTION(execGetVendor); \
	DECLARE_FUNCTION(execSetVendorTab); \
	DECLARE_FUNCTION(execRefreshVendorUI); \
	DECLARE_FUNCTION(execInitializeVendor);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_39_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDMFDigimonVendorWidget_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonVendorWidget(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_39_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFDigimonVendorWidget_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFDigimonVendorWidget(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFDigimonVendorWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFDigimonVendorWidget) \
	DECLARE_SERIALIZER(UDMFDigimonVendorWidget)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_39_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFDigimonVendorWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFDigimonVendorWidget(UDMFDigimonVendorWidget&&) = delete; \
	UDMFDigimonVendorWidget(const UDMFDigimonVendorWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFDigimonVendorWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFDigimonVendorWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFDigimonVendorWidget) \
	NO_API virtual ~UDMFDigimonVendorWidget();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_36_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_39_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_39_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_39_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_39_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h_39_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFDigimonVendorWidget;

// ********** End Class UDMFDigimonVendorWidget ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonVendorWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
