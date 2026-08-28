#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "DMFTypes.h"
#include "DMFPartyQuickBarWidget.generated.h"

class UDMFPlayerDigimonComponent;
class UHorizontalBox;
class UTextBlock;
class UImage;
class UProgressBar;

UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFPartyQuickSlotButton : public UButton
{
    GENERATED_BODY()

public:
    void ConfigurePartySlot(int32 InSlotIndex, class UDMFPartyQuickBarWidget* InOwnerBar);

private:
    int32 SlotIndex = INDEX_NONE;
    TWeakObjectPtr<class UDMFPartyQuickBarWidget> OwnerBar;

    UFUNCTION()
    void HandleClicked();
};

/**
 * Persistent six-slot native Party HUD. The bar is informational during normal gameplay and becomes
 * clickable when the owning controller enters Tab Party interaction mode.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFPartyQuickBarWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party Quick Access")
    void RefreshParty();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party Quick Access")
    void SetInteractionMode(bool bEnabled);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Party Quick Access")
    bool IsInteractionMode() const { return bInteractionMode; }

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Party Quick Access")
    void ExecutePartySlot(int32 SlotIndex);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Party Quick Access")
    void BP_OnPartyQuickBarRefreshed();

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UHorizontalBox> PartySlotsBox;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> PartyStatusText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UHorizontalBox> PartyActionRow;

    /** Optional Blueprint/native Home button. Native fallback places it in the Tab interaction action row. */
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> ReturnHomeButton;

private:
    UPROPERTY(Transient)
    TObjectPtr<UDMFPlayerDigimonComponent> BoundDigimonComponent;

    UPROPERTY(Transient)
    TArray<TObjectPtr<UImage>> NativePortraits;

    UPROPERTY(Transient)
    TArray<TObjectPtr<UTextBlock>> NativeLabels;

    UPROPERTY(Transient)
    TArray<TObjectPtr<UProgressBar>> NativeHealthBars;

    UPROPERTY(Transient)
    TArray<TObjectPtr<UDMFPartyQuickSlotButton>> NativeSlotButtons;

    bool bInteractionMode = false;
    bool bHomeTeleportRequestPending = false;

    void BuildNativeFallback();
    void BindDigimonComponent();

    UFUNCTION()
    void HandlePartyChanged();

    UFUNCTION()
    void HandleStorageResult(bool bSuccess, FText Message, FGuid DigimonInstanceId, EDMFDigimonStorageLocation NewLocation);

    UFUNCTION()
    void HandleRecallClicked();

    UFUNCTION()
    void HandleReturnHomeClicked();

    UFUNCTION()
    void HandleHomeTeleportResult(bool bSuccess, FText Message);

    UFUNCTION()
    void HandleOpenPartyClicked();

    UFUNCTION()
    void HandleOpenBankClicked();
};
