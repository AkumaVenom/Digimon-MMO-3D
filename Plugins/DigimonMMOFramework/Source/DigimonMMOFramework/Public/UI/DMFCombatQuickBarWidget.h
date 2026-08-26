#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "DMFCombatQuickBarWidget.generated.h"

class UHorizontalBox;
class UTextBlock;
class UImage;
class USizeBox;
class UDMFCombatQuickSlotButton;
class UDMFPlayerDigimonComponent;
class ADMFDigimonCharacter;

UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFCombatQuickSlotButton : public UButton
{
    GENERATED_BODY()

public:
    int32 SlotIndex = INDEX_NONE;
    TWeakObjectPtr<class UDMFCombatQuickBarWidget> OwnerBar;

    void ConfigureSlot(int32 InSlotIndex, class UDMFCombatQuickBarWidget* InOwnerBar);

protected:
    virtual void SynchronizeProperties() override;

private:
    UFUNCTION()
    void HandleClicked();
};

/** Native fallback quick-access ability bar. Blueprint subclasses can completely reskin it. */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFCombatQuickBarWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Combat UI")
    void RefreshFromPartner();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Combat UI")
    void ExecuteAbilitySlot(int32 SlotIndex);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Combat UI")
    void BP_OnQuickBarRefreshed();

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UHorizontalBox> AbilityBox;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> TargetText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> VitalsText;

private:
    UPROPERTY(Transient)
    TObjectPtr<UDMFPlayerDigimonComponent> BoundDigimonComponent;

    UPROPERTY(Transient)
    TArray<TObjectPtr<UTextBlock>> NativeSlotLabels;

    UPROPERTY(Transient)
    TArray<TObjectPtr<UImage>> NativeSlotIcons;

    TArray<TWeakObjectPtr<USizeBox>> NativeSlotIconContainers;

    FTimerHandle RefreshTimer;

    void BuildNativeFallback();
    UDMFPlayerDigimonComponent* ResolveDigimonComponent() const;
};
