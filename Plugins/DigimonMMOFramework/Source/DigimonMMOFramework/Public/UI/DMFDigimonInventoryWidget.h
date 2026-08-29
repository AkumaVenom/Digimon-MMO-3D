#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMFTypes.h"
#include "TimerManager.h"
#include "DMFDigimonInventoryWidget.generated.h"

class UVerticalBox;
class UUniformGridPanel;
class UTextBlock;
class UButton;
class UImage;
class UHorizontalBox;
class UProgressBar;
class UEditableTextBox;
class UDMFPlayerDigimonComponent;
class UDMFDigimonSpeciesData;
class UDMFPartyDestinationButton;
class UDMFSocialActionButton;
enum class EDMFSocialUIAction : uint8;

/**
 * Polished native Digimon roster/partner menu.
 * The framework fallback is a portrait-slot grid with a selected Digimon inspection panel,
 * summon/recall actions, status badges and account-owned replicated data. Blueprint children
 * may replace the presentation without replacing server authority.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFDigimonInventoryWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Inventory")
    void RefreshInventory();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Bank")
    void RefreshBankData();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Scan & Materialization")
    void RefreshScanData();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Care")
    void RefreshCareData();

    /** Refreshes the owner-only persistent Social presentation from the controller's last authoritative snapshot. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social")
    void RefreshSocialData();

    /** Refreshes the owner-local nearest-first player discovery panel from already-replicated avatar transforms. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social|Friends|Nearby Players")
    void RefreshNearbyPlayersData();

    /** Owner-local non-modal feedback hook used by reliable Social action results. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social")
    void HandleSocialActionFeedback(bool bSuccess, const FText& Message);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Social")
    void SetActiveSocialTab(EDMFSocialMenuTab NewTab);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Social")
    EDMFSocialMenuTab GetActiveSocialTab() const { return ActiveSocialTab; }

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Digivolution")
    void RefreshDigivolutionData();

    /** Refreshes the read-only encyclopedia of every registered DMFDigimonSpecies primary asset. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|DigiDex")
    void RefreshDigiDexData();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|DigiDex")
    TArray<FPrimaryAssetId> GetDigiDexSpeciesIds() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|DigiDex")
    FPrimaryAssetId GetSelectedDigiDexSpeciesId() const { return SelectedDigiDexSpeciesId; }

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|DigiDex")
    void BP_OnDigiDexSelectionChanged(FPrimaryAssetId SpeciesId, UDMFDigimonSpeciesData* Species);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI")
    void SetActiveMenuTab(EDMFDigimonMenuTab NewTab);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|UI")
    EDMFDigimonMenuTab GetActiveMenuTab() const { return ActiveMenuTab; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Inventory")
    FGuid GetSelectedDigimonInstanceId() const { return SelectedInstanceId; }

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Inventory")
    void BP_OnDigimonPreviewChanged(FDMFDigimonInstance Digimon, UDMFDigimonSpeciesData* Species);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Inventory")
    void BP_OnPartnerActionResult(bool bSuccess, const FText& Message, FGuid PartnerInstanceId);

protected:
    /** Legacy/custom Blueprint list binding. Native fallback uses DigimonGrid. */
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UVerticalBox> DigimonChoicesBox;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> DigimonGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigimonDetailsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> SelectedExperienceProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigimonStatusText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> InventoryCountText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedStageText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedStateText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> SelectedDescriptionText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> SelectedPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> SummonDigimonButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> RecallDigimonButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> MoveSelectedToBankButton;

    /** Native fallback Attribute Point spend controls. Custom Blueprint UI may call ServerSpendDigimonAttributePoint directly. */
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendPartyHPButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendPartySPButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendPartyStrengthButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendPartyIntelligenceButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendPartyDefenseButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendPartySpeedButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> CloseDigimonInventoryButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> CollectionTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> BankTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> ScanMaterializeTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> CareTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> DigivolutionTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> DigiDexTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> SocialTabButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> BankDigimonGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankCountText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankPageText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankSelectionText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> BankSelectedPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankSelectedNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankSelectedMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> BankSelectedStatsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> BankExperienceProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> BankPartyDestinationGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> BankPreviousPageButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> BankNextPageButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> MoveSelectedBankToPartyButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendBankHPButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendBankSPButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendBankStrengthButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendBankIntelligenceButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendBankDefenseButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SpendBankSpeedButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> ScanSpeciesGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanDatabaseCountText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> ScanSelectedPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedProgressText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> ScanSelectedProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedDetailsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> ScanSelectedDescriptionText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> MaterializeDigimonButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> CarePortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareHungerText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> CareHungerProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> CareHappinessProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UProgressBar> CareDisciplineProgressBar;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareStatisticsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareWasteStatusText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> CareFeedingRulesText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> FeedDigiMeatButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> DigiDexSpeciesGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UEditableTextBox> DigiDexSearchBox;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> DigiDexStageFilterButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> DigiDexAttributeFilterButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigiDexStageFilterText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigiDexAttributeFilterText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigiDexCountText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> DigiDexSelectedPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigiDexSelectedNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigiDexSelectedMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigiDexSelectedStatusText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigiDexSelectedStatsText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigiDexSelectedEvolutionText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigiDexSelectedDescriptionText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> DigivolutionOwnedGrid;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UVerticalBox> DigivolutionPathList;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> DigivolutionCurrentPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigivolutionCurrentNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigivolutionCurrentMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UImage> DigivolutionTargetPortraitImage;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigivolutionTargetNameText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigivolutionTargetMetaText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> DigivolutionRequirementText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> DigivolveButton;

    // Social shell. Friends is the default nested page the first time Social is opened.
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SocialFriendsTabButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SocialGuildTabButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> SocialNearbyPlayersList;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> SocialFriendsList;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> SocialFriendRequestsList;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> SocialIgnoreList;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> SocialGuildIdentityText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UTextBlock> SocialGuildMetaText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> SocialGuildMembersList;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> SocialGuildInvitesList;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> SocialGuildApplicationsList;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UVerticalBox> SocialGuildSearchList;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UEditableTextBox> SocialGuildNameInput;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UEditableTextBox> SocialGuildSearchInput;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SocialGuildCreateButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SocialGuildRenameButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SocialGuildLeaveButton;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional)) TObjectPtr<UButton> SocialGuildDisbandButton;

private:
    UPROPERTY(Transient)
    TObjectPtr<UDMFPlayerDigimonComponent> BoundDigimonComponent;

    FGuid SelectedInstanceId;
    FGuid SelectedBankInstanceId;
    FGuid PendingStorageSelectionId;
    FPrimaryAssetId SelectedScanSpeciesId;
    FGuid SelectedDigivolutionInstanceId;
    FPrimaryAssetId SelectedDigivolutionTargetSpeciesId;
    FPrimaryAssetId SelectedDigiDexSpeciesId;
    FString DigiDexSearchQuery;
    int32 DigiDexStageFilterIndex = INDEX_NONE;
    int32 DigiDexAttributeFilterIndex = INDEX_NONE;
    int32 BankPageIndex = 0;
    int32 SelectedBankPartyDestinationIndex = INDEX_NONE;
    EDMFDigimonMenuTab ActiveMenuTab = EDMFDigimonMenuTab::Collection;
    EDMFSocialMenuTab ActiveSocialTab = EDMFSocialMenuTab::Friends;
    bool bHasOpenedSocialTab = false;
    FString SocialGuildSearchQuery;
    FTimerHandle NearbyPlayersRefreshTimer;
    uint32 NearbyPlayersPresentationHash = 0;
    bool bNearbyPlayersPresentationInitialized = false;

    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> InventoryContentRow;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> BankContentRow;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> ScanContentRow;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> CareContentRow;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> DigivolutionContentRow;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> DigiDexContentRow;
    UPROPERTY(Transient) TObjectPtr<UVerticalBox> SocialContentRoot;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> SocialFriendsContentRow;
    UPROPERTY(Transient) TObjectPtr<UHorizontalBox> SocialGuildContentRow;

    void BuildNativeFallbackUI();
    void BindDigimonComponent();
    void RefreshSelectedDetails();
    void RefreshSelectedBankDetails();
    void RefreshSelectedScanDetails();
    void RefreshSelectedDigivolutionDetails();
    void RefreshSelectedDigiDexDetails();
    TArray<UDMFDigimonSpeciesData*> GatherRegisteredDigiDexSpecies() const;
    void RefreshTabPresentation();
    void RefreshSocialTabPresentation();
    void HandleNearbyPlayersRefreshTimer();
    UDMFSocialActionButton* MakeSocialActionButton(const FText& Label, EDMFSocialUIAction Action, const FString& Username = FString(), const FGuid& GuildId = FGuid(), bool bValue = false, bool bPrimary = false, bool bDanger = false);
    UDMFDigimonSpeciesData* ResolveSpecies(FPrimaryAssetId SpeciesId) const;
    void RequestAttributePointSpend(EDMFDigimonAttributeStat Stat, bool bUseBankSelection);
    void SetPartyAttributeSpendEnabled(bool bEnabled);
    void SetBankAttributeSpendEnabled(bool bEnabled);

    UFUNCTION()
    void HandleInventoryChanged();

    UFUNCTION()
    void HandleBankChanged();

    UFUNCTION()
    void HandleStorageActionResult(bool bSuccess, FText Message, FGuid DigimonInstanceId, EDMFDigimonStorageLocation NewLocation);

    UFUNCTION()
    void HandleAttributePointSpendResult(bool bSuccess, FText Message, FGuid DigimonInstanceId, EDMFDigimonAttributeStat Stat, int32 NewStatValue, int32 RemainingPoints);

    UFUNCTION()
    void HandleScanDataChanged(FPrimaryAssetId SpeciesId, float ScanPercent, bool bMaterializationReady);

    UFUNCTION()
    void HandleMaterializationResult(bool bSuccess, FText Message, FPrimaryAssetId SpeciesId, FGuid NewDigimonInstanceId);

    UFUNCTION()
    void HandleCollectionTab();

    UFUNCTION()
    void HandleBankTab();

    UFUNCTION()
    void HandleScanMaterializeTab();

    UFUNCTION()
    void HandleCareTab();

    UFUNCTION()
    void HandleDigivolutionTab();

    UFUNCTION()
    void HandleDigiDexTab();

    UFUNCTION()
    void HandleSocialTab();

    UFUNCTION()
    void HandleSocialFriendsTab();

    UFUNCTION()
    void HandleSocialGuildTab();

    UFUNCTION()
    void HandleSocialActionButtonPressed(UDMFSocialActionButton* Button);

    UFUNCTION()
    void HandleSocialGuildCreate();

    UFUNCTION()
    void HandleSocialGuildRename();

    UFUNCTION()
    void HandleSocialGuildLeave();

    UFUNCTION()
    void HandleSocialGuildDisband();

    UFUNCTION()
    void HandleSocialGuildSearchChanged(const FText& SearchText);

    UFUNCTION()
    void HandleDigiDexSpeciesPressed(FPrimaryAssetId SpeciesId);

    UFUNCTION()
    void HandleDigiDexSearchChanged(const FText& SearchText);

    UFUNCTION()
    void HandleDigiDexStageFilter();

    UFUNCTION()
    void HandleDigiDexAttributeFilter();

    UFUNCTION()
    void HandleFeedDigiMeat();

    UFUNCTION()
    void HandleCareStateChanged(FGuid DigimonInstanceId, FDMFDigimonCareState CareState);

    UFUNCTION()
    void HandleCareSequenceFinished(bool bSuccess, FText Message, FGuid DigimonInstanceId);

    UFUNCTION()
    void HandleScanSpeciesPressed(FPrimaryAssetId SpeciesId);

    UFUNCTION()
    void HandleDigivolutionOwnedPressed(FGuid InstanceId);

    UFUNCTION()
    void HandleDigivolutionTargetPressed(FPrimaryAssetId SpeciesId);

    UFUNCTION()
    void HandleDigivolveSelected();

    UFUNCTION()
    void HandleDigivolutionResult(bool bSuccess, FText Message, FGuid DigimonInstanceId, FPrimaryAssetId PreviousSpeciesId, FPrimaryAssetId NewSpeciesId);

    UFUNCTION()
    void HandleMaterializeSelected();

    UFUNCTION()
    void HandleBankDigimonPressed(FGuid InstanceId);

    UFUNCTION()
    void HandleBankPartyDestinationPressed(int32 PartySlotIndex);

    UFUNCTION()
    void HandleMoveSelectedToBank();

    UFUNCTION()
    void HandleMoveSelectedBankToParty();

    UFUNCTION()
    void HandleBankPreviousPage();

    UFUNCTION()
    void HandleBankNextPage();

    UFUNCTION()
    void HandleDigimonPressed(FGuid InstanceId);

    UFUNCTION()
    void HandleSummonSelected();

    UFUNCTION()
    void HandleRecallPartner();

    UFUNCTION() void HandleSpendPartyHP();
    UFUNCTION() void HandleSpendPartySP();
    UFUNCTION() void HandleSpendPartyStrength();
    UFUNCTION() void HandleSpendPartyIntelligence();
    UFUNCTION() void HandleSpendPartyDefense();
    UFUNCTION() void HandleSpendPartySpeed();
    UFUNCTION() void HandleSpendBankHP();
    UFUNCTION() void HandleSpendBankSP();
    UFUNCTION() void HandleSpendBankStrength();
    UFUNCTION() void HandleSpendBankIntelligence();
    UFUNCTION() void HandleSpendBankDefense();
    UFUNCTION() void HandleSpendBankSpeed();

    UFUNCTION()
    void HandleClose();

    UFUNCTION()
    void HandlePartnerActionResult(bool bSuccess, FText Message, FGuid PartnerInstanceId);
};
