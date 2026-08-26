// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/DMFWorldChatWidget.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFWorldChatWidget_generated_h
#error "DMFWorldChatWidget.generated.h already included, missing '#pragma once' in DMFWorldChatWidget.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFWorldChatWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FDMFWorldChatMessage;

// ********** Begin Class UDMFWorldChatWidget ******************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleMessageCommitted); \
	DECLARE_FUNCTION(execGetVisibleMessageCount); \
	DECLARE_FUNCTION(execIsChatInputOpen); \
	DECLARE_FUNCTION(execCloseChatInput); \
	DECLARE_FUNCTION(execOpenChatInput); \
	DECLARE_FUNCTION(execClearChatHistory); \
	DECLARE_FUNCTION(execAddLocalSystemMessage); \
	DECLARE_FUNCTION(execSetChatHistory); \
	DECLARE_FUNCTION(execAddChatMessage);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_27_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDMFWorldChatWidget_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFWorldChatWidget(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_27_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFWorldChatWidget_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFWorldChatWidget(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFWorldChatWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFWorldChatWidget) \
	DECLARE_SERIALIZER(UDMFWorldChatWidget)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFWorldChatWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFWorldChatWidget(UDMFWorldChatWidget&&) = delete; \
	UDMFWorldChatWidget(const UDMFWorldChatWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFWorldChatWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFWorldChatWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFWorldChatWidget) \
	NO_API virtual ~UDMFWorldChatWidget();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_24_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_27_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_27_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFWorldChatWidget;

// ********** End Class UDMFWorldChatWidget ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFWorldChatWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
