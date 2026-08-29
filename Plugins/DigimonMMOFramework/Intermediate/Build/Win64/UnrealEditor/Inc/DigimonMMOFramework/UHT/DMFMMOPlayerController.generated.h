// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/DMFMMOPlayerController.h"

#ifdef DIGIMONMMOFRAMEWORK_DMFMMOPlayerController_generated_h
#error "DMFMMOPlayerController.generated.h already included, missing '#pragma once' in DMFMMOPlayerController.h"
#endif
#define DIGIMONMMOFRAMEWORK_DMFMMOPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ADMFDigimonCharacter;
class ADMFDigimonVendorActor;
class ADMFHealerActor;
class ADMFPlayerAvatarCharacter;
class ADMFTargetingPresentationActor;
class UDMFWorldChatWidget;
enum class EDMFDigimonVendorTransactionType : uint8;
enum class EDMFSocialActionType : uint8;
struct FDMFDigimonExperienceProgression;
struct FDMFNearbySocialPlayerEntry;
struct FDMFSocialSnapshot;
struct FDMFWorldChatMessage;
struct FGuid;
struct FPrimaryAssetId;

// ********** Begin Class ADMFMMOPlayerController **************************************************
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientDigimonVendorTransactionResult_Implementation(bool bSuccess, FText const& Message, EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier, int64 Price, int64 NewMoney); \
	virtual void ServerRequestDigimonVendorTransaction_Implementation(ADMFDigimonVendorActor* Vendor, EDMFDigimonVendorTransactionType TransactionType, FGuid Identifier); \
	virtual void ClientSocialActionResult_Implementation(bool bSuccess, FText const& Message); \
	virtual void ClientReceiveSocialSnapshot_Implementation(FDMFSocialSnapshot const& SocialSnapshot); \
	virtual void ServerExecuteSocialAction_Implementation(EDMFSocialActionType ActionType, const FString& SubjectUsername, FGuid GuildId, const FString& TextValue, bool bValue); \
	virtual void ServerRequestSocialSnapshot_Implementation(); \
	virtual void ClientWorldChatSendRejected_Implementation(FText const& Reason); \
	virtual void ClientReceiveWorldChatHistory_Implementation(TArray<FDMFWorldChatMessage> const& ChatMessages); \
	virtual void ClientReceiveWorldChatMessage_Implementation(FDMFWorldChatMessage const& ChatMessage); \
	virtual void ServerRequestWorldChatHistory_Implementation(); \
	virtual void ServerSendWorldChatMessage_Implementation(const FString& Message); \
	virtual void ClientReturnHomeResult_Implementation(bool bSuccess, FText const& Message); \
	virtual void ServerRequestReturnHome_Implementation(); \
	virtual void ClientHealerInteractionResult_Implementation(bool bSuccess, FText const& Message, int32 DigimonHealed); \
	virtual void ServerRequestUseHealer_Implementation(ADMFHealerActor* Healer); \
	virtual void ServerEnsureFrameworkPlayerAvatar_Implementation(); \
	DECLARE_FUNCTION(execHandlePlayerSkinRequirementChanged); \
	DECLARE_FUNCTION(execHandleDigivolutionResult); \
	DECLARE_FUNCTION(execHandleDigivolutionSequenceStarted); \
	DECLARE_FUNCTION(execHandleCareSequenceFinished); \
	DECLARE_FUNCTION(execHandleCareSequenceStarted); \
	DECLARE_FUNCTION(execHandleDigimonExperienceProgressed); \
	DECLARE_FUNCTION(execHandleScanDataRewardGranted); \
	DECLARE_FUNCTION(execHandleStarterRequirementChanged); \
	DECLARE_FUNCTION(execClientDigimonVendorTransactionResult); \
	DECLARE_FUNCTION(execServerRequestDigimonVendorTransaction); \
	DECLARE_FUNCTION(execRequestDigimonVendorTransaction); \
	DECLARE_FUNCTION(execGetActiveDigimonVendor); \
	DECLARE_FUNCTION(execIsDigimonVendorUIOpen); \
	DECLARE_FUNCTION(execRefreshDigimonVendorUI); \
	DECLARE_FUNCTION(execCloseDigimonVendorUI); \
	DECLARE_FUNCTION(execOpenDigimonVendorUI); \
	DECLARE_FUNCTION(execClientSocialActionResult); \
	DECLARE_FUNCTION(execClientReceiveSocialSnapshot); \
	DECLARE_FUNCTION(execServerExecuteSocialAction); \
	DECLARE_FUNCTION(execServerRequestSocialSnapshot); \
	DECLARE_FUNCTION(execRefreshFriendTrackingPresentation); \
	DECLARE_FUNCTION(execClosePlayerSocialContextUI); \
	DECLARE_FUNCTION(execOpenPlayerSocialContext); \
	DECLARE_FUNCTION(execRequestDisbandGuild); \
	DECLARE_FUNCTION(execRequestLeaveGuild); \
	DECLARE_FUNCTION(execRequestRemoveGuildMember); \
	DECLARE_FUNCTION(execRespondToGuildApplication); \
	DECLARE_FUNCTION(execRequestApplyToGuild); \
	DECLARE_FUNCTION(execRespondToGuildInvite); \
	DECLARE_FUNCTION(execRequestInvitePlayerToGuild); \
	DECLARE_FUNCTION(execRequestRenameGuild); \
	DECLARE_FUNCTION(execRequestCreateGuild); \
	DECLARE_FUNCTION(execRequestRemoveIgnoredPlayer); \
	DECLARE_FUNCTION(execRequestIgnorePlayer); \
	DECLARE_FUNCTION(execGetNearbySocialPlayers); \
	DECLARE_FUNCTION(execRequestSetFriendTracking); \
	DECLARE_FUNCTION(execRequestRemoveFriend); \
	DECLARE_FUNCTION(execRequestCancelFriendRequest); \
	DECLARE_FUNCTION(execRespondToFriendRequest); \
	DECLARE_FUNCTION(execRequestAddFriend); \
	DECLARE_FUNCTION(execGetCachedSocialSnapshot); \
	DECLARE_FUNCTION(execRequestSocialSnapshot); \
	DECLARE_FUNCTION(execClientWorldChatSendRejected); \
	DECLARE_FUNCTION(execClientReceiveWorldChatHistory); \
	DECLARE_FUNCTION(execClientReceiveWorldChatMessage); \
	DECLARE_FUNCTION(execServerRequestWorldChatHistory); \
	DECLARE_FUNCTION(execServerSendWorldChatMessage); \
	DECLARE_FUNCTION(execSendWorldChatMessage); \
	DECLARE_FUNCTION(execGetWorldChatWidget); \
	DECLARE_FUNCTION(execIsWorldChatInputActive); \
	DECLARE_FUNCTION(execToggleWorldChatInput); \
	DECLARE_FUNCTION(execCloseWorldChatInput); \
	DECLARE_FUNCTION(execOpenWorldChatInput); \
	DECLARE_FUNCTION(execRefreshWorldChatUI); \
	DECLARE_FUNCTION(execClientReturnHomeResult); \
	DECLARE_FUNCTION(execServerRequestReturnHome); \
	DECLARE_FUNCTION(execRequestReturnHome); \
	DECLARE_FUNCTION(execIsPartyQuickAccessInteractionActive); \
	DECLARE_FUNCTION(execTogglePartyQuickAccessInteraction); \
	DECLARE_FUNCTION(execClosePartyQuickAccessInteraction); \
	DECLARE_FUNCTION(execOpenPartyQuickAccessInteraction); \
	DECLARE_FUNCTION(execRefreshPartyQuickBar); \
	DECLARE_FUNCTION(execRefreshCombatQuickBar); \
	DECLARE_FUNCTION(execClientHealerInteractionResult); \
	DECLARE_FUNCTION(execServerRequestUseHealer); \
	DECLARE_FUNCTION(execRequestUseHealer); \
	DECLARE_FUNCTION(execGetTargetingPresentationActor); \
	DECLARE_FUNCTION(execRefreshTargetingVisuals); \
	DECLARE_FUNCTION(execCommandActivePartnerAbilitySlot); \
	DECLARE_FUNCTION(execCommandPartnerTargetAndAttack); \
	DECLARE_FUNCTION(execSelectDigimonCommandTargetUnderCursor); \
	DECLARE_FUNCTION(execSetDigimonCommandTarget); \
	DECLARE_FUNCTION(execIsDigimonMenuUIOpen); \
	DECLARE_FUNCTION(execToggleDigimonMenuUI); \
	DECLARE_FUNCTION(execCloseDigimonMenuUI); \
	DECLARE_FUNCTION(execOpenDigimonMenuUI); \
	DECLARE_FUNCTION(execIsDigimonInventoryUIOpen); \
	DECLARE_FUNCTION(execIsDigivolutionPresentationActive); \
	DECLARE_FUNCTION(execIsCarePresentationActive); \
	DECLARE_FUNCTION(execOpenSocialUI); \
	DECLARE_FUNCTION(execOpenDigivolutionUI); \
	DECLARE_FUNCTION(execOpenCareUI); \
	DECLARE_FUNCTION(execOpenScanMaterializeUI); \
	DECLARE_FUNCTION(execOpenBankUI); \
	DECLARE_FUNCTION(execOpenPartyUI); \
	DECLARE_FUNCTION(execRefreshDigimonInventoryUI); \
	DECLARE_FUNCTION(execToggleDigimonInventoryUI); \
	DECLARE_FUNCTION(execCloseDigimonInventoryUI); \
	DECLARE_FUNCTION(execOpenDigimonInventoryUI); \
	DECLARE_FUNCTION(execIsPlayerSkinSelectionUIOpen); \
	DECLARE_FUNCTION(execRefreshPlayerSkinSelectionUI); \
	DECLARE_FUNCTION(execTogglePlayerSkinSelectionUI); \
	DECLARE_FUNCTION(execClosePlayerSkinSelectionUI); \
	DECLARE_FUNCTION(execOpenPlayerSkinSelectionUI); \
	DECLARE_FUNCTION(execRefreshStarterSelectionUI); \
	DECLARE_FUNCTION(execIsFrameworkPlayerAvatarPossessed); \
	DECLARE_FUNCTION(execServerEnsureFrameworkPlayerAvatar);


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_41_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ADMFMMOPlayerController_Statics;
DIGIMONMMOFRAMEWORK_API UClass* Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase);

#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_41_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ADMFMMOPlayerController_Statics; \
	friend DIGIMONMMOFRAMEWORK_API UClass* ::Z_Construct_UClass_ADMFMMOPlayerController(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ADMFMMOPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DigimonMMOFramework"), Z_Construct_UClass_ADMFMMOPlayerController) \
	DECLARE_SERIALIZER(ADMFMMOPlayerController)


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_41_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADMFMMOPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMFMMOPlayerController(ADMFMMOPlayerController&&) = delete; \
	ADMFMMOPlayerController(const ADMFMMOPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMFMMOPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMFMMOPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADMFMMOPlayerController) \
	NO_API virtual ~ADMFMMOPlayerController();


#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_38_PROLOG
#define FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_41_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_41_CALLBACK_WRAPPERS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_41_INCLASS_NO_PURE_DECLS \
	FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h_41_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMFMMOPlayerController;

// ********** End Class ADMFMMOPlayerController ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Leen_Documents_Unreal_Projects_Digimon_MMO_3D_Plugins_DigimonMMOFramework_Source_DigimonMMOFramework_Public_Game_DMFMMOPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
