// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/DMFPlayerAvatarComponent.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFPlayerAvatarComponent_generated_h
#error "DMFPlayerAvatarComponent.generated.h already included, missing '#pragma once' in DMFPlayerAvatarComponent.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFPlayerAvatarComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDMFPlayerSkinData;
struct FDMFAccountRecord;
struct FPrimaryAssetId;

// ********** Begin Class UDMFPlayerAvatarComponent ************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientPlayerSkinSelectionResult_Implementation(bool bSuccess, FText const& Message, FPrimaryAssetId SkinId); \
	virtual void ServerSetPlayerSkin_Implementation(FPrimaryAssetId SkinId); \
	DECLARE_FUNCTION(execOnRep_PlayerSkinSelectionRequired); \
	DECLARE_FUNCTION(execOnRep_SelectedPlayerSkinId); \
	DECLARE_FUNCTION(execResetPlayerSkinSelection); \
	DECLARE_FUNCTION(execApplySelectedSkinToCurrentPawn); \
	DECLARE_FUNCTION(execApplyCurrentWorldLocationToAccountRecord); \
	DECLARE_FUNCTION(execApplyToAccountRecord); \
	DECLARE_FUNCTION(execInitializeFromAccountRecord); \
	DECLARE_FUNCTION(execClientPlayerSkinSelectionResult); \
	DECLARE_FUNCTION(execServerSetPlayerSkin); \
	DECLARE_FUNCTION(execGetAvailablePlayerSkins); \
	DECLARE_FUNCTION(execResolvePlayerSkin); \
	DECLARE_FUNCTION(execResolveSelectedPlayerSkin); \
	DECLARE_FUNCTION(execIsPlayerSkinSelectionRequired); \
	DECLARE_FUNCTION(execGetSelectedPlayerSkinId);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_23_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDMFPlayerAvatarComponent_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerAvatarComponent(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_23_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFPlayerAvatarComponent_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFPlayerAvatarComponent(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFPlayerAvatarComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFPlayerAvatarComponent) \
	DECLARE_SERIALIZER(UDMFPlayerAvatarComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		SelectedPlayerSkinId=NETFIELD_REP_START, \
		bPlayerSkinSelectionRequired, \
		NETFIELD_REP_END=bPlayerSkinSelectionRequired	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_23_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFPlayerAvatarComponent(UDMFPlayerAvatarComponent&&) = delete; \
	UDMFPlayerAvatarComponent(const UDMFPlayerAvatarComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFPlayerAvatarComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFPlayerAvatarComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDMFPlayerAvatarComponent) \
	NO_API virtual ~UDMFPlayerAvatarComponent();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_20_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_23_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_23_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFPlayerAvatarComponent;

// ********** End Class UDMFPlayerAvatarComponent **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerAvatarComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
