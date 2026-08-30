#include "Game/DMFItemVendorActor.h"

#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/AssetManager.h"
#include "Engine/World.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"
#include "UI/DMFItemVendorWidget.h"


ADMFItemVendorActor::ADMFItemVendorActor()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    SetReplicateMovement(false);
    SetNetUpdateFrequency(2.0f);
    SetMinNetUpdateFrequency(0.5f);

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    VendorMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VendorMesh"));
    VendorMesh->SetupAttachment(SceneRoot);
    VendorMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    InteractionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionCollision"));
    InteractionCollision->SetupAttachment(SceneRoot);
    InteractionCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    InteractionCollision->SetCollisionObjectType(ECC_WorldDynamic);
    InteractionCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
    InteractionCollision->SetGenerateOverlapEvents(false);
    InteractionCollision->SetHiddenInGame(true);

    VendorWidgetClass = UDMFItemVendorWidget::StaticClass();
}

void ADMFItemVendorActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    RefreshInteractionCollision();
}

void ADMFItemVendorActor::BeginPlay()
{
    Super::BeginPlay();
    RefreshInteractionCollision();

    if (HasAuthority())
    {
        RuntimeStockSeedSalt = static_cast<uint32>(FPlatformTime::Cycles());
        if (ReplicatedStock.IsEmpty())
        {
            RefreshStockNow();
        }
        ScheduleNextStockRotation(true);
    }
}

void ADMFItemVendorActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().ClearTimer(StockRotationTimer);
    }
    Super::EndPlay(EndPlayReason);
}

void ADMFItemVendorActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFItemVendorActor, bVendorEnabled);
    DOREPLIFETIME(ADMFItemVendorActor, bAllowBuying);
    DOREPLIFETIME(ADMFItemVendorActor, bAllowSelling);
    DOREPLIFETIME(ADMFItemVendorActor, bRequireItemInStockPoolToSell);
    DOREPLIFETIME(ADMFItemVendorActor, Pricing);
    DOREPLIFETIME(ADMFItemVendorActor, ReplicatedStock);
    DOREPLIFETIME(ADMFItemVendorActor, StockGenerationSerial);
    DOREPLIFETIME(ADMFItemVendorActor, NextStockRotationServerTimeSeconds);
}

void ADMFItemVendorActor::RefreshInteractionCollision()
{
    if (!InteractionCollision)
    {
        return;
    }
    InteractionCollision->SetSphereRadius(FMath::Max(1.0f, InteractionCollisionRadius), true);
    InteractionCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
    InteractionCollision->SetCollisionResponseToChannel(static_cast<ECollisionChannel>(InteractionTraceChannel.GetValue()), ECR_Block);
}

int64 ADMFItemVendorActor::ClampPriceFromDouble(const double Value)
{
    if (!FMath::IsFinite(Value) || Value <= 0.0)
    {
        return 0;
    }
    return Value >= static_cast<double>(MAX_int64) ? MAX_int64 : static_cast<int64>(FMath::RoundToDouble(Value));
}

int64 ADMFItemVendorActor::SafeMultiplyPrice(const int64 UnitPrice, const int32 Quantity)
{
    const int64 SafeUnit = FMath::Max<int64>(0, UnitPrice);
    const int64 SafeQuantity = FMath::Max<int64>(0, Quantity);
    if (SafeUnit == 0 || SafeQuantity == 0)
    {
        return 0;
    }
    return SafeUnit > MAX_int64 / SafeQuantity ? MAX_int64 : SafeUnit * SafeQuantity;
}

bool ADMFItemVendorActor::IsPlayerWithinTradeRange(APlayerController* PlayerController) const
{
    const APawn* Pawn = PlayerController ? PlayerController->GetPawn() : nullptr;
    if (!Pawn)
    {
        return false;
    }
    const float Radius = FMath::Max(0.0f, InteractionRadius);
    return FVector::DistSquared(Pawn->GetActorLocation(), GetActorLocation()) <= FMath::Square(Radius);
}

float ADMFItemVendorActor::GetSecondsUntilStockRotation() const
{
    if (!bRotateStockAutomatically || NextStockRotationServerTimeSeconds <= 0.0 || !GetWorld())
    {
        return -1.0f;
    }
    const AGameStateBase* GameState = GetWorld()->GetGameState();
    const double ServerTime = GameState ? GameState->GetServerWorldTimeSeconds() : GetWorld()->GetTimeSeconds();
    return static_cast<float>(FMath::Max(0.0, NextStockRotationServerTimeSeconds - ServerTime));
}

void ADMFItemVendorActor::SetVendorEnabled(const bool bEnabled)
{
    if (!HasAuthority() || bVendorEnabled == bEnabled)
    {
        return;
    }
    bVendorEnabled = bEnabled;
    OnVendorEnabledChanged.Broadcast(bVendorEnabled);
    BP_OnVendorEnabledChanged(bVendorEnabled);
    ForceNetUpdate();
}

void ADMFItemVendorActor::SetBuyingEnabled(const bool bEnabled)
{
    if (!HasAuthority() || bAllowBuying == bEnabled) return;
    bAllowBuying = bEnabled;
    OnVendorConfigurationChanged.Broadcast();
    ForceNetUpdate();
}

void ADMFItemVendorActor::SetSellingEnabled(const bool bEnabled)
{
    if (!HasAuthority() || bAllowSelling == bEnabled) return;
    bAllowSelling = bEnabled;
    OnVendorConfigurationChanged.Broadcast();
    ForceNetUpdate();
}

void ADMFItemVendorActor::SetPricingSettings(const FDMFItemVendorPricingSettings& NewPricing)
{
    if (!HasAuthority()) return;
    Pricing = NewPricing;
    OnVendorConfigurationChanged.Broadcast();
    ForceNetUpdate();
}

int32 ADMFItemVendorActor::BuildGenerationSeed() const
{
    uint32 Seed = GetTypeHash(VendorId);
    Seed = HashCombineFast(Seed, GetTypeHash(StockGenerationSerial));
    Seed = HashCombineFast(Seed, RuntimeStockSeedSalt);
    return static_cast<int32>(Seed & 0x7fffffffU);
}

const FDMFItemVendorPoolEntry* ADMFItemVendorActor::SelectWeightedPoolEntry(FRandomStream& RandomStream, const TSet<FPrimaryAssetId>& ExcludedItems) const
{
    TArray<const FDMFItemVendorPoolEntry*> Candidates;
    double TotalWeight = 0.0;

    for (const FDMFItemVendorPoolEntry& PoolEntry : StockPool)
    {
        UDMFItemData* Item = PoolEntry.Item.LoadSynchronous();
        if (!Item || PoolEntry.SelectionWeight <= 0.0f || Item->SuggestedBuyPrice <= 0)
        {
            continue;
        }
        const FPrimaryAssetId ItemId = Item->GetPrimaryAssetId();
        if (!ItemId.IsValid() || (!bAllowDuplicateItemsInStock && ExcludedItems.Contains(ItemId)))
        {
            continue;
        }
        Candidates.Add(&PoolEntry);
        TotalWeight += static_cast<double>(PoolEntry.SelectionWeight);
    }

    if (Candidates.IsEmpty() || TotalWeight <= 0.0)
    {
        return nullptr;
    }

    double Roll = static_cast<double>(RandomStream.FRand()) * TotalWeight;
    for (const FDMFItemVendorPoolEntry* Candidate : Candidates)
    {
        Roll -= static_cast<double>(Candidate->SelectionWeight);
        if (Roll <= 0.0)
        {
            return Candidate;
        }
    }
    return Candidates.Last();
}

bool ADMFItemVendorActor::GenerateStockItem(const FDMFItemVendorPoolEntry& PoolEntry, FRandomStream& RandomStream, FDMFItemVendorStockItem& OutItem) const
{
    UDMFItemData* Item = PoolEntry.Item.LoadSynchronous();
    if (!Item || Item->SuggestedBuyPrice <= 0)
    {
        return false;
    }

    const FPrimaryAssetId ItemAssetId = Item->GetPrimaryAssetId();
    if (!ItemAssetId.IsValid())
    {
        return false;
    }

    const int32 MinQuantity = FMath::Clamp(FMath::Min(PoolEntry.MinimumStockQuantity, PoolEntry.MaximumStockQuantity), 1, 999999);
    const int32 MaxQuantity = FMath::Clamp(FMath::Max(PoolEntry.MinimumStockQuantity, PoolEntry.MaximumStockQuantity), MinQuantity, 999999);
    const double PriceValue = static_cast<double>(Item->SuggestedBuyPrice)
        * static_cast<double>(FMath::Max(0.01f, Pricing.PlayerBuyPriceMultiplier))
        * static_cast<double>(FMath::Max(0.01f, PoolEntry.PurchasePriceMultiplier));
    const int64 UnitPrice = FMath::Max<int64>(FMath::Max<int64>(1, Pricing.MinimumUnitPrice), ClampPriceFromDouble(PriceValue));

    OutItem.StockId = FGuid(RandomStream.GetUnsignedInt(), RandomStream.GetUnsignedInt(), RandomStream.GetUnsignedInt(), RandomStream.GetUnsignedInt());
    if (!OutItem.StockId.IsValid()) OutItem.StockId = FGuid::NewGuid();
    OutItem.ItemAssetId = ItemAssetId;
    OutItem.UnitBuyPrice = UnitPrice;
    OutItem.AvailableQuantity = RandomStream.RandRange(MinQuantity, MaxQuantity);
    OutItem.GenerationSerial = StockGenerationSerial;
    return OutItem.IsValid();
}

void ADMFItemVendorActor::FillStockToTarget()
{
    if (!HasAuthority())
    {
        return;
    }

    FRandomStream RandomStream(BuildGenerationSeed() + ReplicatedStock.Num() * 47);
    TSet<FPrimaryAssetId> UsedItems;
    for (const FDMFItemVendorStockItem& Existing : ReplicatedStock)
    {
        if (Existing.ItemAssetId.IsValid()) UsedItems.Add(Existing.ItemAssetId);
    }

    const int32 TargetSlots = FMath::Clamp(StockSlots, 1, 64);
    int32 Safety = TargetSlots * 8 + 16;
    while (ReplicatedStock.Num() < TargetSlots && Safety-- > 0)
    {
        const FDMFItemVendorPoolEntry* PoolEntry = SelectWeightedPoolEntry(RandomStream, UsedItems);
        if (!PoolEntry)
        {
            break;
        }
        FDMFItemVendorStockItem NewOffer;
        if (GenerateStockItem(*PoolEntry, RandomStream, NewOffer))
        {
            ReplicatedStock.Add(NewOffer);
            if (!bAllowDuplicateItemsInStock) UsedItems.Add(NewOffer.ItemAssetId);
        }
    }
}

void ADMFItemVendorActor::RefreshStockNow()
{
    if (!HasAuthority())
    {
        return;
    }

    ReplicatedStock.Reset();
    ++StockGenerationSerial;
    FillStockToTarget();
    OnVendorStockChanged.Broadcast();
    BP_OnStockRefreshed();
    ForceNetUpdate();
}

void ADMFItemVendorActor::RestartStockRotationSchedule()
{
    if (!HasAuthority()) return;
    ScheduleNextStockRotation(false);
}

void ADMFItemVendorActor::ScheduleNextStockRotation(const bool bUseInitialDelay)
{
    if (!HasAuthority() || !GetWorld())
    {
        return;
    }

    GetWorld()->GetTimerManager().ClearTimer(StockRotationTimer);
    if (!bRotateStockAutomatically)
    {
        NextStockRotationServerTimeSeconds = 0.0;
        ForceNetUpdate();
        return;
    }

    const float MinInterval = FMath::Max(5.0f, FMath::Min(MinimumStockRotationSeconds, MaximumStockRotationSeconds));
    const float MaxInterval = FMath::Max(MinInterval, FMath::Max(MinimumStockRotationSeconds, MaximumStockRotationSeconds));
    const float Delay = bUseInitialDelay && InitialStockRotationDelaySeconds > KINDA_SMALL_NUMBER
        ? InitialStockRotationDelaySeconds
        : FMath::FRandRange(MinInterval, MaxInterval);

    const AGameStateBase* GameState = GetWorld()->GetGameState();
    const double ServerTime = GameState ? GameState->GetServerWorldTimeSeconds() : GetWorld()->GetTimeSeconds();
    NextStockRotationServerTimeSeconds = ServerTime + FMath::Max(0.05f, Delay);
    GetWorld()->GetTimerManager().SetTimer(StockRotationTimer, this, &ADMFItemVendorActor::HandleStockRotationTimer, FMath::Max(0.05f, Delay), false);
    ForceNetUpdate();
}

void ADMFItemVendorActor::HandleStockRotationTimer()
{
    RefreshStockNow();
    ScheduleNextStockRotation(false);
}

bool ADMFItemVendorActor::IsItemInStockPool(const FPrimaryAssetId ItemAssetId) const
{
    if (!ItemAssetId.IsValid()) return false;
    for (const FDMFItemVendorPoolEntry& PoolEntry : StockPool)
    {
        if (UDMFItemData* Item = PoolEntry.Item.LoadSynchronous())
        {
            if (Item->GetPrimaryAssetId() == ItemAssetId) return true;
        }
    }
    return false;
}

bool ADMFItemVendorActor::IsItemSellable(const FPrimaryAssetId ItemAssetId, FText& OutBlockReason) const
{
    OutBlockReason = FText::GetEmpty();
    if (!ItemAssetId.IsValid())
    {
        OutBlockReason = NSLOCTEXT("DMF", "ItemVendorSellInvalidItem", "That item is not valid.");
        return false;
    }

    UDMFItemData* Item = nullptr;
    if (UAssetManager::IsInitialized())
    {
        UAssetManager& AssetManager = UAssetManager::Get();
        Item = AssetManager.GetPrimaryAssetObject<UDMFItemData>(ItemAssetId);
        if (!Item)
        {
            const FSoftObjectPath Path = AssetManager.GetPrimaryAssetPath(ItemAssetId);
            Item = Path.IsValid() ? Cast<UDMFItemData>(Path.TryLoad()) : nullptr;
        }
    }
    if (!Item)
    {
        OutBlockReason = NSLOCTEXT("DMF", "ItemVendorSellMissingDefinition", "The server could not resolve that item definition.");
        return false;
    }
    if (Item->Category == EDMFItemCategory::KeyItem)
    {
        OutBlockReason = NSLOCTEXT("DMF", "ItemVendorKeyItemProtected", "Key Items are protected and cannot be sold.");
        return false;
    }
    if (Item->Category == EDMFItemCategory::Quest)
    {
        OutBlockReason = NSLOCTEXT("DMF", "ItemVendorQuestItemProtected", "Quest Items are protected and cannot be sold.");
        return false;
    }
    if (Item->SuggestedSellPrice <= 0)
    {
        OutBlockReason = NSLOCTEXT("DMF", "ItemVendorNoSellValue", "This item has no vendor sell value.");
        return false;
    }
    if (bRequireItemInStockPoolToSell && !IsItemInStockPool(ItemAssetId))
    {
        OutBlockReason = NSLOCTEXT("DMF", "ItemVendorNotAccepted", "This vendor does not accept that item.");
        return false;
    }
    return true;
}

int64 ADMFItemVendorActor::GetPlayerSellUnitPrice(const FPrimaryAssetId ItemAssetId) const
{
    FText BlockReason;
    if (!IsItemSellable(ItemAssetId, BlockReason) || !UAssetManager::IsInitialized())
    {
        return 0;
    }
    UAssetManager& AssetManager = UAssetManager::Get();
    UDMFItemData* Item = AssetManager.GetPrimaryAssetObject<UDMFItemData>(ItemAssetId);
    if (!Item)
    {
        const FSoftObjectPath Path = AssetManager.GetPrimaryAssetPath(ItemAssetId);
        Item = Path.IsValid() ? Cast<UDMFItemData>(Path.TryLoad()) : nullptr;
    }
    if (!Item) return 0;
    const double PriceValue = static_cast<double>(Item->SuggestedSellPrice) * static_cast<double>(FMath::Max(0.0f, Pricing.PlayerSellPayoutMultiplier));
    return FMath::Max<int64>(FMath::Max<int64>(1, Pricing.MinimumUnitPrice), ClampPriceFromDouble(PriceValue));
}

bool ADMFItemVendorActor::TryPurchaseStockAuthoritative(ADMFMMOPlayerController* Buyer, const FGuid StockId, const int32 Quantity, FPrimaryAssetId& OutItemAssetId, int64& OutTotalPrice, FText& OutMessage)
{
    OutItemAssetId = FPrimaryAssetId();
    OutTotalPrice = 0;
    OutMessage = FText::GetEmpty();

    if (!HasAuthority() || !bVendorEnabled || !bAllowBuying)
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorBuyingUnavailable", "This vendor is not selling items right now.");
        return false;
    }
    if (!Buyer || !IsPlayerWithinTradeRange(Buyer))
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorBuyerOutOfRange", "Move closer to the item vendor before buying.");
        return false;
    }
    if (Quantity <= 0 || Quantity > 999999)
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorInvalidBuyQuantity", "Choose a valid purchase quantity.");
        return false;
    }

    const int32 StockIndex = ReplicatedStock.IndexOfByPredicate([&](const FDMFItemVendorStockItem& Offer){ return Offer.StockId == StockId; });
    if (!ReplicatedStock.IsValidIndex(StockIndex))
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorOfferGone", "That item offer is no longer available. The shared stock has changed.");
        return false;
    }

    const FDMFItemVendorStockItem Offer = ReplicatedStock[StockIndex];
    if (!Offer.IsValid() || Quantity > Offer.AvailableQuantity)
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorInsufficientSharedStock", "The vendor no longer has that many in shared stock.");
        return false;
    }

    ADMFPlayerState* PlayerState = Buyer->GetPlayerState<ADMFPlayerState>();
    UDMFPlayerDigimonComponent* DigimonComponent = PlayerState ? PlayerState->DigimonComponent.Get() : nullptr;
    if (!DigimonComponent)
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorBuyerStateUnavailable", "Your item account state is unavailable.");
        return false;
    }

    const int64 TotalPrice = SafeMultiplyPrice(Offer.UnitBuyPrice, Quantity);
    if (TotalPrice <= 0)
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorInvalidBuyPrice", "That item offer has an invalid price.");
        return false;
    }

    // Reserve the shared replicated quantity before account mutation so re-entrant server logic cannot buy
    // the same final units twice. Restore the immutable offer if the authoritative account commit fails.
    ReplicatedStock[StockIndex].AvailableQuantity -= Quantity;
    const bool bDepleted = ReplicatedStock[StockIndex].AvailableQuantity <= 0;
    if (bDepleted)
    {
        ReplicatedStock.RemoveAt(StockIndex);
    }

    if (!DigimonComponent->AuthorityPurchaseVendorItem(Offer.ItemAssetId, Quantity, TotalPrice, OutMessage))
    {
        if (bDepleted)
        {
            ReplicatedStock.Insert(Offer, FMath::Clamp(StockIndex, 0, ReplicatedStock.Num()));
        }
        else if (ReplicatedStock.IsValidIndex(StockIndex) && ReplicatedStock[StockIndex].StockId == Offer.StockId)
        {
            ReplicatedStock[StockIndex] = Offer;
        }
        return false;
    }

    OutItemAssetId = Offer.ItemAssetId;
    OutTotalPrice = TotalPrice;
    if (bRefillDepletedSlotsImmediately)
    {
        FillStockToTarget();
    }

    OnVendorStockChanged.Broadcast();
    BP_OnStockRefreshed();
    ForceNetUpdate();
    OnVendorTradeCompleted.Broadcast(Buyer, EDMFItemVendorTransactionType::Buy, OutItemAssetId, Quantity, OutTotalPrice);
    BP_OnVendorTradeCompleted(Buyer, EDMFItemVendorTransactionType::Buy, OutItemAssetId, Quantity, OutTotalPrice);
    return true;
}

bool ADMFItemVendorActor::TrySellItemAuthoritative(ADMFMMOPlayerController* Seller, const FPrimaryAssetId ItemAssetId, const int32 Quantity, int64& OutTotalPrice, FText& OutMessage)
{
    OutTotalPrice = 0;
    OutMessage = FText::GetEmpty();
    if (!HasAuthority() || !bVendorEnabled || !bAllowSelling)
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorSellingUnavailable", "This vendor is not buying items right now.");
        return false;
    }
    if (!Seller || !IsPlayerWithinTradeRange(Seller))
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorSellerOutOfRange", "Move closer to the item vendor before selling.");
        return false;
    }
    if (Quantity <= 0 || Quantity > 999999)
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorInvalidSellQuantity", "Choose a valid sale quantity.");
        return false;
    }

    FText BlockReason;
    if (!IsItemSellable(ItemAssetId, BlockReason))
    {
        OutMessage = BlockReason;
        return false;
    }

    const int64 UnitPrice = GetPlayerSellUnitPrice(ItemAssetId);
    const int64 TotalPrice = SafeMultiplyPrice(UnitPrice, Quantity);
    if (UnitPrice <= 0 || TotalPrice <= 0)
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorInvalidSellPrice", "That item has no valid vendor payout.");
        return false;
    }

    ADMFPlayerState* PlayerState = Seller->GetPlayerState<ADMFPlayerState>();
    UDMFPlayerDigimonComponent* DigimonComponent = PlayerState ? PlayerState->DigimonComponent.Get() : nullptr;
    if (!DigimonComponent)
    {
        OutMessage = NSLOCTEXT("DMF", "ItemVendorSellerStateUnavailable", "Your item account state is unavailable.");
        return false;
    }

    if (!DigimonComponent->AuthoritySellItemToVendor(ItemAssetId, Quantity, TotalPrice, OutMessage))
    {
        return false;
    }

    OutTotalPrice = TotalPrice;
    OnVendorTradeCompleted.Broadcast(Seller, EDMFItemVendorTransactionType::Sell, ItemAssetId, Quantity, OutTotalPrice);
    BP_OnVendorTradeCompleted(Seller, EDMFItemVendorTransactionType::Sell, ItemAssetId, Quantity, OutTotalPrice);
    return true;
}

void ADMFItemVendorActor::OnRep_Stock()
{
    OnVendorStockChanged.Broadcast();
    BP_OnStockRefreshed();
}

void ADMFItemVendorActor::OnRep_VendorEnabled()
{
    OnVendorEnabledChanged.Broadcast(bVendorEnabled);
    BP_OnVendorEnabledChanged(bVendorEnabled);
}

void ADMFItemVendorActor::OnRep_Configuration()
{
    OnVendorConfigurationChanged.Broadcast();
}
