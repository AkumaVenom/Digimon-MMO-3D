// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/DMFPartyQuickBarWidget.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFPartyQuickBarWidget_generated_h
#error "DMFPartyQuickBarWidget.generated.h already included, missing '#pragma once' in DMFPartyQuickBarWidget.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFPartyQuickBarWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EDMFDigimonStorageLocation : uint8;
struct FGuid;

// ********** Begin Class UDMFPartyQuickSlotButton *************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleClicked);


struct Z_Construct_UClass_UDMFPartyQuickSlotButton_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPartyQuickSlotButton(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_18_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFPartyQuickSlotButton_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFPartyQuickSlotButton(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFPartyQuickSlotButton, UButton, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFPartyQuickSlotButton) \
	DECLARE_SERIALIZER(UDMFPartyQuickSlotButton)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFPartyQuickSlotButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFPartyQuickSlotButton(UDMFPartyQuickSlotButton&&) = delete; \
	UDMFPartyQuickSlotButton(const UDMFPartyQuickSlotButton&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFPartyQuickSlotButton); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFPartyQuickSlotButton); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFPartyQuickSlotButton) \
	NO_API virtual ~UDMFPartyQuickSlotButton();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_15_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFPartyQuickSlotButton;

// ********** End Class UDMFPartyQuickSlotButton ***************************************************

// ********** Begin Class UDMFPartyQuickBarWidget **************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleOpenBankClicked); \
	DECLARE_FUNCTION(execHandleOpenPartyClicked); \
	DECLARE_FUNCTION(execHandleRecallClicked); \
	DECLARE_FUNCTION(execHandleStorageResult); \
	DECLARE_FUNCTION(execHandlePartyChanged); \
	DECLARE_FUNCTION(execExecutePartySlot); \
	DECLARE_FUNCTION(execIsInteractionMode); \
	DECLARE_FUNCTION(execSetInteractionMode); \
	DECLARE_FUNCTION(execRefreshParty);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_38_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDMFPartyQuickBarWidget_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPartyQuickBarWidget(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_38_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFPartyQuickBarWidget_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFPartyQuickBarWidget(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFPartyQuickBarWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFPartyQuickBarWidget) \
	DECLARE_SERIALIZER(UDMFPartyQuickBarWidget)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFPartyQuickBarWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFPartyQuickBarWidget(UDMFPartyQuickBarWidget&&) = delete; \
	UDMFPartyQuickBarWidget(const UDMFPartyQuickBarWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFPartyQuickBarWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFPartyQuickBarWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFPartyQuickBarWidget) \
	NO_API virtual ~UDMFPartyQuickBarWidget();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_35_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_38_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_38_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFPartyQuickBarWidget;

// ********** End Class UDMFPartyQuickBarWidget ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFPartyQuickBarWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
