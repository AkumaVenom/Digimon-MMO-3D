#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMFTypes.h"
#include "DMFDigimonVendorActor.generated.h"

class USceneComponent;
class USphereComponent;
class USkeletalMeshComponent;
class UDMFDigimonSpeciesData;
class UDMFDigimonVendorWidget;
class ADMFMMOPlayerController;

/** Randomized generation envelope used when a vendor builds one stock Digimon. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonVendorGenerationRange
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="1", ClampMax="999"))
    int32 MinimumLevel = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="1", ClampMax="999"))
    int32 MaximumLevel = 10;

    /** Number of real +1 Attribute Point investments distributed across HP/SP/STR/INT/DEF/SPD. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MinimumSpentAttributePoints = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MaximumSpentAttributePoints = 12;

    /** Independent natural stock variation applied after level growth and before trained Attribute Points. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Natural Stat Variation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MinimumRandomHPBonus = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Natural Stat Variation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MaximumRandomHPBonus = 25;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Natural Stat Variation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MinimumRandomSPBonus = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Natural Stat Variation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MaximumRandomSPBonus = 10;

    /** Rolled independently for STR, INT, DEF and SPD. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Natural Stat Variation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MinimumRandomCombatStatBonus = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Natural Stat Variation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MaximumRandomCombatStatBonus = 3;

    /** Optional unused points supplied with the purchased Digimon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MinimumUnspentAttributePoints = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0", ClampMax="100000"))
    int32 MaximumUnspentAttributePoints = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0", ClampMax="9999"))
    int32 MinimumABI = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0", ClampMax="9999"))
    int32 MaximumABI = 20;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0", ClampMax="100"))
    int32 MinimumCAM = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0", ClampMax="100"))
    int32 MaximumCAM = 25;

    /** Current-level EXP bank as a fraction of the next-level requirement. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0.0", ClampMax="0.999"))
    float MinimumLevelExperiencePercent = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(ClampMin="0.0", ClampMax="0.999"))
    float MaximumLevelExperiencePercent = 0.75f;
};

/** One species candidate in a placed vendor's stock pool. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonVendorSpeciesPoolEntry
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Species")
    TSoftObjectPtr<UDMFDigimonSpeciesData> Species;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Species", meta=(ClampMin="0.0"))
    float SelectionWeight = 1.0f;

    /** Optional market rarity/scarcity adjustment after automatic valuation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Species", meta=(ClampMin="0.01", ClampMax="100.0"))
    float PurchasePriceMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation")
    bool bOverrideGenerationRange = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation", meta=(EditCondition="bOverrideGenerationRange"))
    FDMFDigimonVendorGenerationRange GenerationRangeOverride;
};

/** Per-stage automatic market multipliers. Existing species Data Assets require no vendor-price field. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonVendorStageMultipliers
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float Fresh = 0.60f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float InTraining = 0.75f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float Rookie = 1.00f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float Champion = 1.45f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float Ultimate = 2.10f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float Mega = 3.00f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float Ultra = 3.75f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float Armor = 1.90f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float Hybrid = 2.30f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stage Multipliers", meta=(ClampMin="0.01")) float Unknown = 1.00f;
};

/** Tunable automatic valuation model shared by vendor purchases and player resale quotes. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonVendorPricingSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 BaseSpeciesValue = 250;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePerLevel = 75;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePer100LifetimeExperience = 3;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePerMaxHPPoint = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePerMaxSPPoint = 2;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePerCombatStatPoint = 6;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePerABIPoint = 125;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePerCAMPoint = 4;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePerSpentAttributePoint = 35;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePerUnspentAttributePoint = 20;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0")) int64 ValuePerVisitedDigivolutionForm = 175;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing") FDMFDigimonVendorStageMultipliers StageMultipliers;

    /** What a player pays relative to the fully calculated market value. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0.01", ClampMax="100.0"))
    float VendorBuyMarkup = 1.20f;

    /** What the vendor pays a player relative to the fully calculated market value. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0.0", ClampMax="10.0"))
    float PlayerSellPayoutMultiplier = 0.62f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pricing", meta=(ClampMin="0"))
    int64 MinimumTransactionPrice = 10;
};

/** Blueprint/UI-facing explanation of an automatic valuation. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonVendorValueBreakdown
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Value") int64 SpeciesAndStageValue = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 LevelValue = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 ExperienceValue = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 StatsValue = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 ABIValue = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 CAMValue = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 AttributeTrainingValue = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 DigivolutionHistoryValue = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 MarketValue = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 VendorPurchasePrice = 0;
    UPROPERTY(BlueprintReadOnly, Category="Value") int64 PlayerSellPrice = 0;
};

/** Replicated immutable offer snapshot generated by the server for one stock slot. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonVendorStockItem
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Stock") FGuid StockId;
    UPROPERTY(BlueprintReadOnly, Category="Stock") FDMFDigimonInstance Digimon;
    UPROPERTY(BlueprintReadOnly, Category="Stock") int64 PurchasePrice = 0;
    UPROPERTY(BlueprintReadOnly, Category="Stock") int32 GenerationSerial = 0;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDMFDigimonVendorStockChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFDigimonVendorEnabledChanged, bool, bEnabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDMFDigimonVendorConfigurationChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FDMFDigimonVendorTradeCompleted, ADMFMMOPlayerController*, PlayerController, EDMFDigimonVendorTransactionType, TransactionType, FDMFDigimonInstance, Digimon, int64, Price);

/**
 * Blueprint-derivable, server-authoritative Digimon market NPC.
 * Stock generation, rotation, pricing and transactions are authority-owned; the native UI is owner-local presentation.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFDigimonVendorActor : public AActor
{
    GENERATED_BODY()

public:
    ADMFDigimonVendorActor();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor") TObjectPtr<USceneComponent> SceneRoot;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Presentation") TObjectPtr<USkeletalMeshComponent> VendorMesh;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Interaction") TObjectPtr<USphereComponent> InteractionCollision;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Identity") FName VendorId = TEXT("DigimonVendor");
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Identity") FText VendorDisplayName = NSLOCTEXT("DMF", "DefaultDigimonVendorName", "DIGIMON EXCHANGE");
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Identity", meta=(MultiLine=true)) FText VendorSubtitle = NSLOCTEXT("DMF", "DefaultDigimonVendorSubtitle", "Buy rotating partners or trade trained Digimon for Bits.");
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Interaction") FText InteractionPrompt = NSLOCTEXT("DMF", "DefaultDigimonVendorPrompt", "Open Digimon Vendor");

    UPROPERTY(ReplicatedUsing=OnRep_VendorEnabled, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor") bool bVendorEnabled = true;
    UPROPERTY(ReplicatedUsing=OnRep_Configuration, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor") bool bAllowBuying = true;
    UPROPERTY(ReplicatedUsing=OnRep_Configuration, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor") bool bAllowSelling = true;
    UPROPERTY(ReplicatedUsing=OnRep_Configuration, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Selling") bool bAllowSellingStarterDigimon = false;
    UPROPERTY(ReplicatedUsing=OnRep_Configuration, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Selling") bool bRequireAtLeastOnePartyDigimon = true;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Buying") bool bPreferPurchasedDigimonToBank = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Interaction", meta=(ClampMin="50.0")) float InteractionRadius = 375.0f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Interaction", meta=(ClampMin="1.0")) float InteractionCollisionRadius = 110.0f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Interaction") TEnumAsByte<ECollisionChannel> InteractionTraceChannel = ECC_Visibility;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock", meta=(ClampMin="1", ClampMax="64")) int32 StockSlots = 6;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock") bool bAllowDuplicateSpeciesInStock = false;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock") bool bRefillSoldSlotsImmediately = false;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock") TArray<FDMFDigimonVendorSpeciesPoolEntry> SpeciesPool;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock") FDMFDigimonVendorGenerationRange DefaultGenerationRange;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock Rotation") bool bRotateStockAutomatically = true;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock Rotation", meta=(ClampMin="5.0")) float MinimumStockRotationSeconds = 900.0f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock Rotation", meta=(ClampMin="5.0")) float MaximumStockRotationSeconds = 1200.0f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock Rotation", meta=(ClampMin="0.0")) float InitialStockRotationDelaySeconds = 0.0f;

    UPROPERTY(ReplicatedUsing=OnRep_Configuration, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|Pricing") FDMFDigimonVendorPricingSettings Pricing;

    /** Per-NPC UI override. Leave blank to use the framework's native tabbed Digimon vendor UI. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Vendor|UI") TSubclassOf<UDMFDigimonVendorWidget> VendorWidgetClass;

    UPROPERTY(ReplicatedUsing=OnRep_Stock, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock") TArray<FDMFDigimonVendorStockItem> ReplicatedStock;
    UPROPERTY(ReplicatedUsing=OnRep_Stock, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock") int32 StockGenerationSerial = 0;
    UPROPERTY(ReplicatedUsing=OnRep_Stock, BlueprintReadOnly, Category="Digimon MMO|Vendor|Stock") double NextStockRotationServerTimeSeconds = 0.0;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Vendor") FDMFDigimonVendorStockChanged OnVendorStockChanged;
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Vendor") FDMFDigimonVendorEnabledChanged OnVendorEnabledChanged;
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Vendor") FDMFDigimonVendorConfigurationChanged OnVendorConfigurationChanged;
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Vendor") FDMFDigimonVendorTradeCompleted OnVendorTradeCompleted;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor") TArray<FDMFDigimonVendorStockItem> GetVendorStock() const { return ReplicatedStock; }
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor") bool IsVendorEnabled() const { return bVendorEnabled; }
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor|Stock") float GetSecondsUntilStockRotation() const;
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor|Pricing") FDMFDigimonVendorValueBreakdown CalculateDigimonValue(const FDMFDigimonInstance& Digimon) const;
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor|Pricing") int64 GetPlayerSellPrice(const FDMFDigimonInstance& Digimon) const;
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Vendor|Interaction") bool IsPlayerWithinTradeRange(APlayerController* PlayerController) const;

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Vendor") void SetVendorEnabled(bool bEnabled);
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Vendor") void SetBuyingEnabled(bool bEnabled);
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Vendor") void SetSellingEnabled(bool bEnabled);
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Vendor|Pricing") void SetPricingSettings(const FDMFDigimonVendorPricingSettings& NewPricing);
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, CallInEditor, Category="Digimon MMO|Vendor|Stock") void RefreshStockNow();
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Vendor|Stock Rotation") void RestartStockRotationSchedule();

    bool TryPurchaseStockAuthoritative(ADMFMMOPlayerController* Buyer, FGuid StockId, FGuid& OutDigimonInstanceId, int64& OutPrice, FText& OutMessage);
    bool TrySellDigimonAuthoritative(ADMFMMOPlayerController* Seller, FGuid DigimonInstanceId, int64& OutPrice, FText& OutMessage);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Vendor") void BP_OnStockRefreshed();
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Vendor") void BP_OnVendorEnabledChanged(bool bEnabled);
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Vendor") void BP_OnVendorTradeCompleted(ADMFMMOPlayerController* PlayerController, EDMFDigimonVendorTransactionType TransactionType, FDMFDigimonInstance Digimon, int64 Price);

private:
    FTimerHandle StockRotationTimer;
    uint32 RuntimeStockSeedSalt = 0;

    UFUNCTION() void OnRep_Stock();
    UFUNCTION() void OnRep_VendorEnabled();
    UFUNCTION() void OnRep_Configuration();

    void ScheduleNextStockRotation(bool bUseInitialDelay);
    void HandleStockRotationTimer();
    void FillStockToTarget();
    bool GenerateStockItem(const FDMFDigimonVendorSpeciesPoolEntry& PoolEntry, FRandomStream& RandomStream, FDMFDigimonVendorStockItem& OutItem) const;
    const FDMFDigimonVendorSpeciesPoolEntry* SelectWeightedPoolEntry(FRandomStream& RandomStream, const TSet<FPrimaryAssetId>& ExcludedSpecies) const;
    int32 BuildGenerationSeed() const;
    float GetStageMultiplier(EDMFDigimonStage Stage) const;
    static int64 SafeAddInt64(int64 A, int64 B);
    static int64 SafeMultiplyInt64(int64 Value, int64 Multiplier);
};
