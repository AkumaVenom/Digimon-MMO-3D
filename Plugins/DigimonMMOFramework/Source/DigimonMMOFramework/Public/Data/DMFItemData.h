#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DMFTypes.h"
#include "DMFItemData.generated.h"

class UTexture2D;

/** High-level inventory grouping used by native UI and future item-shop filtering. */
UENUM(BlueprintType)
enum class EDMFItemCategory : uint8
{
    Consumable,
    Material,
    KeyItem UMETA(DisplayName="Key Item"),
    Quest,
    Miscellaneous
};

/** Native server-authoritative effects currently supplied by the framework. */
UENUM(BlueprintType)
enum class EDMFItemUseEffect : uint8
{
    None,
    RestoreHP UMETA(DisplayName="Restore HP"),
    RestoreSP UMETA(DisplayName="Restore SP")
};

/**
 * Data-driven player item definition. Clients may read presentation fields, but gameplay effect values are
 * always resolved again on authority when an item is consumed. This makes the same asset suitable for
 * inventory UI, future shops/rewards, and authoritative gameplay without trusting client-authored values.
 */
UCLASS(BlueprintType)
class DIGIMONMMOFRAMEWORK_API UDMFItemData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FName ItemId;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity", meta=(MultiLine=true))
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    TSoftObjectPtr<UTexture2D> Icon;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Inventory")
    EDMFItemCategory Category = EDMFItemCategory::Consumable;

    /** Maximum quantity stored in one persistent replicated stack. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Inventory", meta=(ClampMin="1", ClampMax="999999"))
    int32 MaxStackSize = 99;

    /** Canonical item-economy values used by the replicated item vendor unless a placed vendor applies multipliers. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Economy", meta=(ClampMin="0"))
    int64 SuggestedBuyPrice = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Economy", meta=(ClampMin="0"))
    int64 SuggestedSellPrice = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Use")
    bool bConsumable = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Use")
    EDMFItemUseEffect UseEffect = EDMFItemUseEffect::None;

    /** HP/SP restored by one consumed item. Ignored for UseEffect=None. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Use", meta=(ClampMin="0", EditCondition="UseEffect != EDMFItemUseEffect::None"))
    int32 RestoreAmount = 0;

    /** Default capsule policy: defeated Digimon require the Healer/another explicit revival mechanic. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Use", meta=(EditCondition="UseEffect == EDMFItemUseEffect::RestoreHP"))
    bool bCanRestoreDefeatedDigimon = false;

    /** Prevents normal recovery capsules from being used on a defeated target. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Use", meta=(EditCondition="UseEffect != EDMFItemUseEffect::None"))
    bool bRequiresLivingDigimon = true;

    /** Optional stable sort hint for native inventory/shop lists. Lower values appear first. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    int32 SortPriority = 0;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        const FName EffectiveName = ItemId.IsNone() ? GetFName() : ItemId;
        return FPrimaryAssetId(TEXT("DMFItem"), EffectiveName);
    }
};
