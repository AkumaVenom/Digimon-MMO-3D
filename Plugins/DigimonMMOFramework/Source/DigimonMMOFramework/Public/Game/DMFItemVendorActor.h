#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMFTypes.h"
#include "Data/DMFItemData.h"
#include "DMFItemVendorActor.generated.h"

class USceneComponent;
class USphereComponent;
class USkeletalMeshComponent;
class UDMFItemVendorWidget;
class ADMFMMOPlayerController;

/** One weighted item candidate that a placed item vendor may roll into shared stock. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFItemVendorPoolEntry
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
    TSoftObjectPtr<UDMFItemData> Item;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item", meta=(ClampMin="0.0"))
    float SelectionWeight = 1.0f;

    /** Multiplies the Data Asset SuggestedBuyPrice for this vendor's rolled offer. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0.01", ClampMax="100.0"))
    float PurchasePriceMultiplier = 1.0f;

    /** Shared server stock quantity rolled when this offer is generated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stock Quantity", meta=(ClampMin="1", ClampMax="999999"))
    int32 MinimumStockQuantity = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stock Quantity", meta=(ClampMin="1", ClampMax="999999"))
    int32 MaximumStockQuantity = 20;
};

/** Global item-vendor price tuning layered over each UDMFItemData economy definition. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFItemVendorPricingSettings
{
    GENERATED_BODY()

    /** Player BUY unit price = SuggestedBuyPrice * this value * pool-entry multiplier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0.01", ClampMax="100.0"))
    float PlayerBuyPriceMultiplier = 1.0f;

    /** Player SELL unit payout = SuggestedSellPrice * this value. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0.0", ClampMax="100.0"))
    float PlayerSellPayoutMultiplier = 1.0f;

    /** Positive transactions are never quoted below this per-item amount. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="1"))
    int64 MinimumUnitPrice = 1;
};

/** Replicated shared offer. Every connection sees the same StockId, item, price and remaining quantity. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFItemVendorStockItem
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Stock") FGuid StockId;
    UPROPERTY(BlueprintReadOnly, Category="Stock") FPrimaryAssetId ItemAssetId;
    UPROPERTY(BlueprintReadOnly, Category="Stock") int64 UnitBuyPrice = 0;
    UPROPERTY(BlueprintReadOnly, Category="Stock") int32 AvailableQuantity = 0;
    UPROPERTY(BlueprintReadOnly, Category="Stock") int32 GenerationSerial = 0;

    bool IsValid() const
    {
        return StockId.IsValid() && ItemAssetId.IsValid() && UnitBuyPrice > 0 && AvailableQuantity > 0;
    }
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDMFItemVendorStockChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFItemVendorEnabledChanged, bool, bEnabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDMFItemVendorConfigurationChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FDMFItemVendorTradeCompleted, ADMFMMOPlayerController*, PlayerController, EDMFItemVendorTransactionType, TransactionType, FPrimaryAssetId, ItemAssetId, int32, Quantity, int64, TotalPrice);

/**
 * Blueprint-derivable, server-authoritative shared item exchange.
 * The server alone rolls/rotates/decrements stock. ReplicatedStock is intentionally public shared state,
 * while each player's bag and BITS balance remain owner-only on UDMFPlayerDigimonComponent.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFItemVendorActor : public AActor
{
    GENERATED_BODY()

public:
    ADMFItemVendorActor();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor") TObjectPtr<USceneComponent> SceneRoot;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Presentation") TObjectPtr<USkeletalMeshComponent> VendorMesh;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Interaction") TObjectPtr<USphereComponent> InteractionCollision;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Identity") FName VendorId = TEXT("ItemVendor");
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Identity") FText VendorDisplayName = NSLOCTEXT("DMF", "DefaultItemVendorName", "ITEM EXCHANGE");
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Identity", meta=(MultiLine=true)) FText VendorSubtitle = NSLOCTEXT("DMF", "DefaultItemVendorSubtitle", "Buy rotating supplies or sell eligible inventory items for BITS.");
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Interaction") FText InteractionPrompt = NSLOCTEXT("DMF", "DefaultItemVendorPrompt", "Open Item Vendor");

    UPROPERTY(ReplicatedUsing=OnRep_VendorEnabled, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor") bool bVendorEnabled = true;
    UPROPERTY(ReplicatedUsing=OnRep_Configuration, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor") bool bAllowBuying = true;
    UPROPERTY(ReplicatedUsing=OnRep_Configuration, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor") bool bAllowSelling = true;

    /** If enabled, only items present in this vendor's StockPool may be sold here. Key/Quest items remain protected regardless. */
    UPROPERTY(ReplicatedUsing=OnRep_Configuration, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Selling") bool bRequireItemInStockPoolToSell = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Interaction", meta=(ClampMin="50.0")) float InteractionRadius = 375.0f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Interaction", meta=(ClampMin="1.0")) float InteractionCollisionRadius = 110.0f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Interaction") TEnumAsByte<ECollisionChannel> InteractionTraceChannel = ECC_Visibility;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock", meta=(ClampMin="1", ClampMax="64")) int32 StockSlots = 6;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock") bool bAllowDuplicateItemsInStock = false;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock") bool bRefillDepletedSlotsImmediately = false;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock") TArray<FDMFItemVendorPoolEntry> StockPool;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock Rotation") bool bRotateStockAutomatically = true;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock Rotation", meta=(ClampMin="5.0")) float MinimumStockRotationSeconds = 900.0f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock Rotation", meta=(ClampMin="5.0")) float MaximumStockRotationSeconds = 1200.0f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock Rotation", meta=(ClampMin="0.0")) float InitialStockRotationDelaySeconds = 0.0f;

    UPROPERTY(ReplicatedUsing=OnRep_Configuration, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Pricing") FDMFItemVendorPricingSettings Pricing;

    /** Per-NPC UI override. Leave blank to use the polished framework-native BUY/SELL item exchange. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|UI") TSubclassOf<UDMFItemVendorWidget> VendorWidgetClass;

    /** Shared stock is replicated to every relevant connection. Purchases update remaining quantity for all players. */
    UPROPERTY(ReplicatedUsing=OnRep_Stock, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock") TArray<FDMFItemVendorStockItem> ReplicatedStock;
    UPROPERTY(ReplicatedUsing=OnRep_Stock, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock") int32 StockGenerationSerial = 0;
    UPROPERTY(ReplicatedUsing=OnRep_Stock, BlueprintReadOnly, Category="Digimon MMO|Item Vendor|Stock") double NextStockRotationServerTimeSeconds = 0.0;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Item Vendor") FDMFItemVendorStockChanged OnVendorStockChanged;
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Item Vendor") FDMFItemVendorEnabledChanged OnVendorEnabledChanged;
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Item Vendor") FDMFItemVendorConfigurationChanged OnVendorConfigurationChanged;
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Item Vendor") FDMFItemVendorTradeCompleted OnVendorTradeCompleted;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Item Vendor") TArray<FDMFItemVendorStockItem> GetVendorStock() const { return ReplicatedStock; }
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Item Vendor") bool IsVendorEnabled() const { return bVendorEnabled; }
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Item Vendor|Stock") float GetSecondsUntilStockRotation() const;
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Item Vendor|Pricing") int64 GetPlayerSellUnitPrice(FPrimaryAssetId ItemAssetId) const;
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Item Vendor|Selling") bool IsItemSellable(FPrimaryAssetId ItemAssetId, FText& OutBlockReason) const;
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Item Vendor|Interaction") bool IsPlayerWithinTradeRange(APlayerController* PlayerController) const;

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Item Vendor") void SetVendorEnabled(bool bEnabled);
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Item Vendor") void SetBuyingEnabled(bool bEnabled);
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Item Vendor") void SetSellingEnabled(bool bEnabled);
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Item Vendor|Pricing") void SetPricingSettings(const FDMFItemVendorPricingSettings& NewPricing);
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, CallInEditor, Category="Digimon MMO|Item Vendor|Stock") void RefreshStockNow();
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Item Vendor|Stock Rotation") void RestartStockRotationSchedule();

    bool TryPurchaseStockAuthoritative(ADMFMMOPlayerController* Buyer, FGuid StockId, int32 Quantity, FPrimaryAssetId& OutItemAssetId, int64& OutTotalPrice, FText& OutMessage);
    bool TrySellItemAuthoritative(ADMFMMOPlayerController* Seller, FPrimaryAssetId ItemAssetId, int32 Quantity, int64& OutTotalPrice, FText& OutMessage);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Item Vendor") void BP_OnStockRefreshed();
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Item Vendor") void BP_OnVendorEnabledChanged(bool bEnabled);
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Item Vendor") void BP_OnVendorTradeCompleted(ADMFMMOPlayerController* PlayerController, EDMFItemVendorTransactionType TransactionType, FPrimaryAssetId ItemAssetId, int32 Quantity, int64 TotalPrice);

private:
    FTimerHandle StockRotationTimer;
    uint32 RuntimeStockSeedSalt = 0;

    UFUNCTION() void OnRep_Stock();
    UFUNCTION() void OnRep_VendorEnabled();
    UFUNCTION() void OnRep_Configuration();

    void RefreshInteractionCollision();
    void ScheduleNextStockRotation(bool bUseInitialDelay);
    void HandleStockRotationTimer();
    void FillStockToTarget();
    bool GenerateStockItem(const FDMFItemVendorPoolEntry& PoolEntry, FRandomStream& RandomStream, FDMFItemVendorStockItem& OutItem) const;
    const FDMFItemVendorPoolEntry* SelectWeightedPoolEntry(FRandomStream& RandomStream, const TSet<FPrimaryAssetId>& ExcludedItems) const;
    bool IsItemInStockPool(FPrimaryAssetId ItemAssetId) const;
    int32 BuildGenerationSeed() const;
    static int64 ClampPriceFromDouble(double Value);
    static int64 SafeMultiplyPrice(int64 UnitPrice, int32 Quantity);
};
