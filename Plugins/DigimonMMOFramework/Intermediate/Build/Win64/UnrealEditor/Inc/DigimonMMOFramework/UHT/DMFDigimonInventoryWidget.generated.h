// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/DMFDigimonInventoryWidget.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFDigimonInventoryWidget_generated_h
#error "DMFDigimonInventoryWidget.generated.h already included, missing '#pragma once' in DMFDigimonInventoryWidget.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFDigimonInventoryWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDMFDigimonSpeciesData;
enum class EDMFDigimonMenuTab : uint8;
struct FDMFDigimonInstance;
struct FGuid;
struct FPrimaryAssetId;

// ********** Begin Class UDMFDigimonInventoryWidget ***********************************************
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandlePartnerActionResult); \
	DECLARE_FUNCTION(execHandleClose); \
	DECLARE_FUNCTION(execHandleRecallPartner); \
	DECLARE_FUNCTION(execHandleSummonSelected); \
	DECLARE_FUNCTION(execHandleDigimonPressed); \
	DECLARE_FUNCTION(execHandleMaterializeSelected); \
	DECLARE_FUNCTION(execHandleScanSpeciesPressed); \
	DECLARE_FUNCTION(execHandleScanMaterializeTab); \
	DECLARE_FUNCTION(execHandleCollectionTab); \
	DECLARE_FUNCTION(execHandleMaterializationResult); \
	DECLARE_FUNCTION(execHandleScanDataChanged); \
	DECLARE_FUNCTION(execHandleInventoryChanged); \
	DECLARE_FUNCTION(execGetSelectedDigimonInstanceId); \
	DECLARE_FUNCTION(execGetActiveMenuTab); \
	DECLARE_FUNCTION(execSetActiveMenuTab); \
	DECLARE_FUNCTION(execRefreshScanData); \
	DECLARE_FUNCTION(execRefreshInventory);


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_27_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDMFDigimonInventoryWidget_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_27_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFDigimonInventoryWidget_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFDigimonInventoryWidget(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFDigimonInventoryWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFDigimonInventoryWidget) \
	DECLARE_SERIALIZER(UDMFDigimonInventoryWidget)


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFDigimonInventoryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFDigimonInventoryWidget(UDMFDigimonInventoryWidget&&) = delete; \
	UDMFDigimonInventoryWidget(const UDMFDigimonInventoryWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFDigimonInventoryWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFDigimonInventoryWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFDigimonInventoryWidget) \
	NO_API virtual ~UDMFDigimonInventoryWidget();


#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_24_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_27_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_27_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFDigimonInventoryWidget;

// ********** End Class UDMFDigimonInventoryWidget *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_DigimonMMO3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFDigimonInventoryWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
