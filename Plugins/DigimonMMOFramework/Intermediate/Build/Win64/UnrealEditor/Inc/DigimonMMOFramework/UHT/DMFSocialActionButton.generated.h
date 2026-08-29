// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/DMFSocialActionButton.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFSocialActionButton_generated_h
#error "DMFSocialActionButton.generated.h already included, missing '#pragma once' in DMFSocialActionButton.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFSocialActionButton_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDMFSocialActionButton;

// ********** Begin Class UDMFSocialActionButton ***************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleClicked);


struct Z_Construct_UClass_UDMFSocialActionButton_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFSocialActionButton(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h_36_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFSocialActionButton_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFSocialActionButton(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFSocialActionButton, UButton, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFSocialActionButton) \
	DECLARE_SERIALIZER(UDMFSocialActionButton)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h_36_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMFSocialActionButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFSocialActionButton(UDMFSocialActionButton&&) = delete; \
	UDMFSocialActionButton(const UDMFSocialActionButton&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFSocialActionButton); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFSocialActionButton); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMFSocialActionButton) \
	NO_API virtual ~UDMFSocialActionButton();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h_33_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h_36_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFSocialActionButton;

// ********** End Class UDMFSocialActionButton *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_UI_DMFSocialActionButton_h

// ********** Begin Enum EDMFSocialUIAction ********************************************************
#define FOREACH_ENUM_EDMFSOCIALUIACTION(op) \
	op(EDMFSocialUIAction::FriendAccept) \
	op(EDMFSocialUIAction::FriendDecline) \
	op(EDMFSocialUIAction::FriendCancel) \
	op(EDMFSocialUIAction::FriendRemove) \
	op(EDMFSocialUIAction::FriendTrackToggle) \
	op(EDMFSocialUIAction::IgnoreRemove) \
	op(EDMFSocialUIAction::GuildInviteAccept) \
	op(EDMFSocialUIAction::GuildInviteDecline) \
	op(EDMFSocialUIAction::GuildApply) \
	op(EDMFSocialUIAction::GuildApplicationAccept) \
	op(EDMFSocialUIAction::GuildApplicationDecline) \
	op(EDMFSocialUIAction::GuildRemoveMember) \
	op(EDMFSocialUIAction::FriendAdd) \
	op(EDMFSocialUIAction::IgnoreAdd) 

enum class EDMFSocialUIAction : uint8;
template<> struct TIsUEnumClass<EDMFSocialUIAction> { enum { Value = true }; };
template<> UE_NODEBUG DIGIMONMMOFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDMFSocialUIAction>();
// ********** End Enum EDMFSocialUIAction **********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
