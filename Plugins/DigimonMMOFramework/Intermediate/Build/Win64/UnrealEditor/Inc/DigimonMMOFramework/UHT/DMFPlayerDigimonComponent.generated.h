// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/DMFPlayerDigimonComponent.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFPlayerDigimonComponent_generated_h
#error "DMFPlayerDigimonComponent.generated.h already included, missing '#pragma once' in DMFPlayerDigimonComponent.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFPlayerDigimonComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ADMFDigimonCharacter;
class APawn;
struct FDMFAccountRecord;
struct FDMFDigimonCareState;
struct FDMFDigimonInstance;
struct FDMFScanDataEntry;
struct FGuid;
struct FPrimaryAssetId;

// ********** Begin Class UDMFPlayerDigimonComponent ***********************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientBattleRewardGranted_Implementation(FPrimaryAssetId DefeatedSpeciesId, int64 Experience, int64 MoneyReward); \
	virtual void ServerCommandActivePartnerAbilitySlot_Implementation(int32 SlotIndex, ADMFDigimonCharacter* RequestedTarget); \
	virtual void ServerSetCommandTarget_Implementation(ADMFDigimonCharacter* NewTarget); \
	virtual void ClientPartnerActionResult_Implementation(bool bSuccess, FText const& Message, FGuid PartnerInstanceId); \
	virtual void ServerSetActivePartnerAutoBattle_Implementation(bool bEnabled); \
	virtual void ServerRecallActivePartner_Implementation(); \
	virtual void ServerSetActivePartner_Implementation(FGuid InstanceId, bool bSummonNow); \
	virtual void ClientCareSequenceFinished_Implementation(bool bSuccess, FText const& Message, FGuid DigimonInstanceId); \
	virtual void ClientCareSequenceStarted_Implementation(FGuid DigimonInstanceId); \
	virtual void ServerFeedActivePartnerUntilFull_Implementation(); \
	virtual void ClientMaterializationResult_Implementation(bool bSuccess, FText const& Message, FPrimaryAssetId SpeciesId, FGuid NewDigimonInstanceId); \
	virtual void ClientScanDataRewardGranted_Implementation(FPrimaryAssetId SpeciesId, float AddedPercent, float NewPercent, bool bMaterializationReady); \
	virtual void ServerMaterializeDigimon_Implementation(FPrimaryAssetId SpeciesId); \
	virtual void ClientStarterSelectionResult_Implementation(bool bSuccess, FText const& Message, FGuid PartnerInstanceId); \
	virtual void ServerSelectStarter_Implementation(FPrimaryAssetId StarterSpeciesId); \
	DECLARE_FUNCTION(execOnRep_CareSequenceActive); \
	DECLARE_FUNCTION(execOnRep_StarterSelectionRequired); \
	DECLARE_FUNCTION(execOnRep_ActivePartnerActor); \
	DECLARE_FUNCTION(execOnRep_ActivePartnerInstanceId); \
	DECLARE_FUNCTION(execOnRep_Inventory); \
	DECLARE_FUNCTION(execHandleActivePartnerVitalsChanged); \
	DECLARE_FUNCTION(execOnRep_ScanData); \
	DECLARE_FUNCTION(execOnRep_Money); \
	DECLARE_FUNCTION(execOnRep_CommandTarget); \
	DECLARE_FUNCTION(execSpawnOrRefreshActivePartner); \
	DECLARE_FUNCTION(execApplyToAccountRecord); \
	DECLARE_FUNCTION(execInitializeFromAccountRecord); \
	DECLARE_FUNCTION(execResetStarterOnboarding); \
	DECLARE_FUNCTION(execClientBattleRewardGranted); \
	DECLARE_FUNCTION(execHandleAuthoritativeBattleVictory); \
	DECLARE_FUNCTION(execServerCommandActivePartnerAbilitySlot); \
	DECLARE_FUNCTION(execServerSetCommandTarget); \
	DECLARE_FUNCTION(execHealAllOwnedDigimon); \
	DECLARE_FUNCTION(execClientPartnerActionResult); \
	DECLARE_FUNCTION(execServerSetActivePartnerAutoBattle); \
	DECLARE_FUNCTION(execServerRecallActivePartner); \
	DECLARE_FUNCTION(execServerSetActivePartner); \
	DECLARE_FUNCTION(execClientCareSequenceFinished); \
	DECLARE_FUNCTION(execClientCareSequenceStarted); \
	DECLARE_FUNCTION(execServerFeedActivePartnerUntilFull); \
	DECLARE_FUNCTION(execGetSecondsUntilActivePartnerWaste); \
	DECLARE_FUNCTION(execIsCareSequenceActive); \
	DECLARE_FUNCTION(execGetActivePartnerCareState); \
	DECLARE_FUNCTION(execClientMaterializationResult); \
	DECLARE_FUNCTION(execClientScanDataRewardGranted); \
	DECLARE_FUNCTION(execServerMaterializeDigimon); \
	DECLARE_FUNCTION(execGetOwnedSpeciesCount); \
	DECLARE_FUNCTION(execIsSpeciesReadyToMaterialize); \
	DECLARE_FUNCTION(execGetScanPercent); \
	DECLARE_FUNCTION(execGetScanDataEntries); \
	DECLARE_FUNCTION(execGetMoney); \
	DECLARE_FUNCTION(execGetCommandTarget); \
	DECLARE_FUNCTION(execClientStarterSelectionResult); \
	DECLARE_FUNCTION(execServerSelectStarter); \
	DECLARE_FUNCTION(execIsStarterSelectionRequired); \
	DECLARE_FUNCTION(execIsActivePartnerSummoned); \
	DECLARE_FUNCTION(execGetActivePartnerInstanceId); \
	DECLARE_FUNCTION(execGetDigimonByInstanceId); \
	DECLARE_FUNCTION(execGetDigimonInventory);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_33_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDMFPlayerDigimonComponent_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_UDMFPlayerDigimonComponent(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_33_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UDMFPlayerDigimonComponent_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_UDMFPlayerDigimonComponent(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UDMFPlayerDigimonComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_UDMFPlayerDigimonComponent) \
	DECLARE_SERIALIZER(UDMFPlayerDigimonComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ActivePartnerActor=NETFIELD_REP_START, \
		ReplicatedInventory, \
		ActivePartnerInstanceId, \
		bStarterSelectionRequired, \
		CommandTarget, \
		Money, \
		ReplicatedScanData, \
		bCareSequenceActive, \
		CareSequenceInstanceId, \
		NETFIELD_REP_END=CareSequenceInstanceId	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_33_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMFPlayerDigimonComponent(UDMFPlayerDigimonComponent&&) = delete; \
	UDMFPlayerDigimonComponent(const UDMFPlayerDigimonComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMFPlayerDigimonComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMFPlayerDigimonComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDMFPlayerDigimonComponent) \
	NO_API virtual ~UDMFPlayerDigimonComponent();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_30_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_33_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_33_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMFPlayerDigimonComponent;

// ********** End Class UDMFPlayerDigimonComponent *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Components_DMFPlayerDigimonComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
