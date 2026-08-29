#include "Game/DMFDigimonVendorActor.h"

#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Data/DMFDigimonAbilityData.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Engine/AssetManager.h"
#include "Engine/World.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"
#include "UI/DMFDigimonVendorWidget.h"

namespace
{
    int64 DMFClampPriceFromDouble(const double Value)
    {
        if (!FMath::IsFinite(Value) || Value <= 0.0)
        {
            return 0;
        }
        return static_cast<int64>(FMath::Min<double>(Value, static_cast<double>(MAX_int64)));
    }

    int64 DMFExperienceRequiredForVendorLevel(const UDMFDigimonSpeciesData& Species, const int32 CurrentLevel)
    {
        const int32 SafeLevel = FMath::Max(1, CurrentLevel);
        const double Base = static_cast<double>(FMath::Max<int64>(1, Species.BaseExperienceRequired));
        const double Growth = static_cast<double>(FMath::Max(1.0f, Species.ExperienceGrowthMultiplierPerLevel));
        const double Raw = Base * FMath::Pow(Growth, static_cast<double>(SafeLevel - 1));
        if (!FMath::IsFinite(Raw) || Raw >= static_cast<double>(MAX_int64))
        {
            return MAX_int64;
        }
        return FMath::Max<int64>(1, static_cast<int64>(FMath::RoundToDouble(Raw)));
    }

    void DMFApplyOneVendorAttributePoint(FDMFDigimonInstance& Digimon, const int32 StatIndex)
    {
        switch (StatIndex)
        {
            case 0: ++Digimon.Stats.MaxHP; break;
            case 1: ++Digimon.Stats.MaxSP; break;
            case 2: ++Digimon.Stats.Strength; break;
            case 3: ++Digimon.Stats.Intelligence; break;
            case 4: ++Digimon.Stats.Defense; break;
            default: ++Digimon.Stats.Speed; break;
        }
    }
}

ADMFDigimonVendorActor::ADMFDigimonVendorActor()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    SetReplicateMovement(false);
    SetNetUpdateFrequency(2.0f);
    SetMinNetUpdateFrequency(0.2f);

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

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

    VendorWidgetClass = UDMFDigimonVendorWidget::StaticClass();
}

void ADMFDigimonVendorActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    if (InteractionCollision)
    {
        InteractionCollision->SetSphereRadius(FMath::Max(1.0f, InteractionCollisionRadius), false);
        InteractionCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
        InteractionCollision->SetCollisionResponseToChannel(static_cast<ECollisionChannel>(InteractionTraceChannel.GetValue()), ECR_Block);
    }
}

void ADMFDigimonVendorActor::BeginPlay()
{
    Super::BeginPlay();
    OnConstruction(GetActorTransform());

    if (HasAuthority())
    {
        RuntimeStockSeedSalt = GetTypeHash(FGuid::NewGuid());
        RefreshStockNow();
        ScheduleNextStockRotation(true);
    }
}

void ADMFDigimonVendorActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(StockRotationTimer);
    }
    Super::EndPlay(EndPlayReason);
}

void ADMFDigimonVendorActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFDigimonVendorActor, bVendorEnabled);
    DOREPLIFETIME(ADMFDigimonVendorActor, bAllowBuying);
    DOREPLIFETIME(ADMFDigimonVendorActor, bAllowSelling);
    DOREPLIFETIME(ADMFDigimonVendorActor, bAllowSellingStarterDigimon);
    DOREPLIFETIME(ADMFDigimonVendorActor, bRequireAtLeastOnePartyDigimon);
    DOREPLIFETIME(ADMFDigimonVendorActor, Pricing);
    DOREPLIFETIME(ADMFDigimonVendorActor, ReplicatedStock);
    DOREPLIFETIME(ADMFDigimonVendorActor, StockGenerationSerial);
    DOREPLIFETIME(ADMFDigimonVendorActor, NextStockRotationServerTimeSeconds);
}

int64 ADMFDigimonVendorActor::SafeAddInt64(const int64 A, const int64 B)
{
    if (B > 0 && A > MAX_int64 - B) return MAX_int64;
    if (B < 0 && A < MIN_int64 - B) return MIN_int64;
    return A + B;
}

int64 ADMFDigimonVendorActor::SafeMultiplyInt64(const int64 Value, const int64 Multiplier)
{
    if (Value <= 0 || Multiplier <= 0) return 0;
    if (Value > MAX_int64 / Multiplier) return MAX_int64;
    return Value * Multiplier;
}

float ADMFDigimonVendorActor::GetStageMultiplier(const EDMFDigimonStage Stage) const
{
    switch (Stage)
    {
        case EDMFDigimonStage::BabyI: return Pricing.StageMultipliers.Fresh;
        case EDMFDigimonStage::BabyII: return Pricing.StageMultipliers.InTraining;
        case EDMFDigimonStage::Rookie: return Pricing.StageMultipliers.Rookie;
        case EDMFDigimonStage::Champion: return Pricing.StageMultipliers.Champion;
        case EDMFDigimonStage::Ultimate: return Pricing.StageMultipliers.Ultimate;
        case EDMFDigimonStage::Mega: return Pricing.StageMultipliers.Mega;
        case EDMFDigimonStage::Ultra: return Pricing.StageMultipliers.Ultra;
        case EDMFDigimonStage::Armor: return Pricing.StageMultipliers.Armor;
        case EDMFDigimonStage::Hybrid: return Pricing.StageMultipliers.Hybrid;
        default: return Pricing.StageMultipliers.Unknown;
    }
}

FDMFDigimonVendorValueBreakdown ADMFDigimonVendorActor::CalculateDigimonValue(const FDMFDigimonInstance& Digimon) const
{
    FDMFDigimonVendorValueBreakdown Result;
    if (!Digimon.IsValid())
    {
        return Result;
    }

    UDMFDigimonSpeciesData* Species = nullptr;
    if (UAssetManager::IsInitialized())
    {
        UAssetManager& AssetManager = UAssetManager::Get();
        Species = Cast<UDMFDigimonSpeciesData>(AssetManager.GetPrimaryAssetObject(Digimon.SpeciesId));
        if (!Species)
        {
            const FSoftObjectPath Path = AssetManager.GetPrimaryAssetPath(Digimon.SpeciesId);
            Species = Path.IsValid() ? Cast<UDMFDigimonSpeciesData>(Path.TryLoad()) : nullptr;
        }
    }

    const float StageMultiplier = Species ? FMath::Max(0.01f, GetStageMultiplier(Species->Stage)) : 1.0f;
    Result.SpeciesAndStageValue = DMFClampPriceFromDouble(static_cast<double>(FMath::Max<int64>(0, Pricing.BaseSpeciesValue)) * static_cast<double>(StageMultiplier));
    Result.LevelValue = SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePerLevel), FMath::Max<int64>(1, Digimon.Stats.Level));
    Result.ExperienceValue = SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePer100LifetimeExperience), FMath::Max<int64>(0, Digimon.LifetimeBattleExperience) / 100);

    int64 StatsValue = SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePerMaxHPPoint), FMath::Max<int64>(0, Digimon.Stats.MaxHP));
    StatsValue = SafeAddInt64(StatsValue, SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePerMaxSPPoint), FMath::Max<int64>(0, Digimon.Stats.MaxSP)));
    const int64 CombatStatTotal = static_cast<int64>(FMath::Max(0, Digimon.Stats.Strength))
        + static_cast<int64>(FMath::Max(0, Digimon.Stats.Intelligence))
        + static_cast<int64>(FMath::Max(0, Digimon.Stats.Defense))
        + static_cast<int64>(FMath::Max(0, Digimon.Stats.Speed));
    StatsValue = SafeAddInt64(StatsValue, SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePerCombatStatPoint), CombatStatTotal));
    Result.StatsValue = StatsValue;

    Result.ABIValue = SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePerABIPoint), FMath::Max<int64>(0, Digimon.Stats.ABI));
    Result.CAMValue = SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePerCAMPoint), FMath::Max<int64>(0, Digimon.Stats.CAM));
    Result.AttributeTrainingValue = SafeAddInt64(
        SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePerSpentAttributePoint), FMath::Max<int64>(0, Digimon.TotalAttributePointsSpent)),
        SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePerUnspentAttributePoint), FMath::Max<int64>(0, Digimon.UnspentAttributePoints)));
    Result.DigivolutionHistoryValue = SafeMultiplyInt64(FMath::Max<int64>(0, Pricing.ValuePerVisitedDigivolutionForm), FMath::Max<int64>(1, Digimon.DigivolutionHistory.Num()));

    Result.MarketValue = Result.SpeciesAndStageValue;
    Result.MarketValue = SafeAddInt64(Result.MarketValue, Result.LevelValue);
    Result.MarketValue = SafeAddInt64(Result.MarketValue, Result.ExperienceValue);
    Result.MarketValue = SafeAddInt64(Result.MarketValue, Result.StatsValue);
    Result.MarketValue = SafeAddInt64(Result.MarketValue, Result.ABIValue);
    Result.MarketValue = SafeAddInt64(Result.MarketValue, Result.CAMValue);
    Result.MarketValue = SafeAddInt64(Result.MarketValue, Result.AttributeTrainingValue);
    Result.MarketValue = SafeAddInt64(Result.MarketValue, Result.DigivolutionHistoryValue);

    const int64 Minimum = FMath::Max<int64>(0, Pricing.MinimumTransactionPrice);
    Result.VendorPurchasePrice = FMath::Max(Minimum, DMFClampPriceFromDouble(static_cast<double>(Result.MarketValue) * FMath::Max(0.01f, Pricing.VendorBuyMarkup)));
    Result.PlayerSellPrice = FMath::Max(Minimum, DMFClampPriceFromDouble(static_cast<double>(Result.MarketValue) * FMath::Max(0.0f, Pricing.PlayerSellPayoutMultiplier)));
    return Result;
}

int64 ADMFDigimonVendorActor::GetPlayerSellPrice(const FDMFDigimonInstance& Digimon) const
{
    return CalculateDigimonValue(Digimon).PlayerSellPrice;
}

bool ADMFDigimonVendorActor::IsPlayerWithinTradeRange(APlayerController* PlayerController) const
{
    const APawn* Pawn = PlayerController ? PlayerController->GetPawn() : nullptr;
    if (!Pawn)
    {
        return false;
    }
    const float MaxDistance = FMath::Max(50.0f, InteractionRadius);
    return FVector::DistSquared(Pawn->GetActorLocation(), GetActorLocation()) <= FMath::Square(MaxDistance);
}

float ADMFDigimonVendorActor::GetSecondsUntilStockRotation() const
{
    if (!bRotateStockAutomatically || NextStockRotationServerTimeSeconds <= 0.0 || !GetWorld())
    {
        return -1.0f;
    }
    const AGameStateBase* GameState = GetWorld()->GetGameState();
    const double ServerTime = GameState ? GameState->GetServerWorldTimeSeconds() : GetWorld()->GetTimeSeconds();
    return static_cast<float>(FMath::Max(0.0, NextStockRotationServerTimeSeconds - ServerTime));
}

void ADMFDigimonVendorActor::SetVendorEnabled(const bool bEnabled)
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

void ADMFDigimonVendorActor::SetBuyingEnabled(const bool bEnabled)
{
    if (!HasAuthority() || bAllowBuying == bEnabled) return;
    bAllowBuying = bEnabled;
    OnVendorConfigurationChanged.Broadcast();
    ForceNetUpdate();
}

void ADMFDigimonVendorActor::SetSellingEnabled(const bool bEnabled)
{
    if (!HasAuthority() || bAllowSelling == bEnabled) return;
    bAllowSelling = bEnabled;
    OnVendorConfigurationChanged.Broadcast();
    ForceNetUpdate();
}

void ADMFDigimonVendorActor::SetPricingSettings(const FDMFDigimonVendorPricingSettings& NewPricing)
{
    if (!HasAuthority()) return;
    Pricing = NewPricing;
    OnVendorConfigurationChanged.Broadcast();
    RefreshStockNow();
}

int32 ADMFDigimonVendorActor::BuildGenerationSeed() const
{
    uint32 Seed = GetTypeHash(VendorId);
    const FVector Location = GetActorLocation();
    Seed = HashCombine(Seed, GetTypeHash(FMath::RoundToInt(Location.X)));
    Seed = HashCombine(Seed, GetTypeHash(FMath::RoundToInt(Location.Y)));
    Seed = HashCombine(Seed, GetTypeHash(FMath::RoundToInt(Location.Z)));
    Seed = HashCombine(Seed, GetTypeHash(StockGenerationSerial));
    Seed = HashCombine(Seed, RuntimeStockSeedSalt);
    return static_cast<int32>(Seed);
}

const FDMFDigimonVendorSpeciesPoolEntry* ADMFDigimonVendorActor::SelectWeightedPoolEntry(FRandomStream& RandomStream, const TSet<FPrimaryAssetId>& ExcludedSpecies) const
{
    float TotalWeight = 0.0f;
    TArray<const FDMFDigimonVendorSpeciesPoolEntry*> Candidates;
    TArray<float> Weights;

    for (const FDMFDigimonVendorSpeciesPoolEntry& Entry : SpeciesPool)
    {
        UDMFDigimonSpeciesData* Species = Entry.Species.LoadSynchronous();
        if (!Species || Entry.SelectionWeight <= 0.0f)
        {
            continue;
        }
        const FPrimaryAssetId SpeciesId = Species->GetPrimaryAssetId();
        if (!bAllowDuplicateSpeciesInStock && ExcludedSpecies.Contains(SpeciesId))
        {
            continue;
        }
        Candidates.Add(&Entry);
        const float Weight = FMath::Max(0.0f, Entry.SelectionWeight);
        Weights.Add(Weight);
        TotalWeight += Weight;
    }

    if (Candidates.IsEmpty() || TotalWeight <= KINDA_SMALL_NUMBER)
    {
        return nullptr;
    }

    float Roll = RandomStream.FRandRange(0.0f, TotalWeight);
    for (int32 Index = 0; Index < Candidates.Num(); ++Index)
    {
        Roll -= Weights[Index];
        if (Roll <= 0.0f)
        {
            return Candidates[Index];
        }
    }
    return Candidates.Last();
}

bool ADMFDigimonVendorActor::GenerateStockItem(const FDMFDigimonVendorSpeciesPoolEntry& PoolEntry, FRandomStream& RandomStream, FDMFDigimonVendorStockItem& OutItem) const
{
    UDMFDigimonSpeciesData* Species = PoolEntry.Species.LoadSynchronous();
    if (!Species)
    {
        return false;
    }

    const FDMFDigimonVendorGenerationRange& Range = PoolEntry.bOverrideGenerationRange ? PoolEntry.GenerationRangeOverride : DefaultGenerationRange;
    const int32 MinLevel = FMath::Max(1, FMath::Min(Range.MinimumLevel, Range.MaximumLevel));
    const int32 MaxLevelRequested = FMath::Max(MinLevel, FMath::Max(Range.MinimumLevel, Range.MaximumLevel));
    const int32 SpeciesMaxLevel = Species->MaxLevelOverride > 0 ? Species->MaxLevelOverride : MaxLevelRequested;
    const int32 MaxLevel = FMath::Max(MinLevel, FMath::Min(MaxLevelRequested, SpeciesMaxLevel));
    const int32 Level = RandomStream.RandRange(MinLevel, MaxLevel);

    FDMFDigimonInstance Digimon;
    Digimon.InstanceId = FGuid(RandomStream.GetUnsignedInt(), RandomStream.GetUnsignedInt(), RandomStream.GetUnsignedInt(), RandomStream.GetUnsignedInt());
    if (!Digimon.InstanceId.IsValid()) Digimon.InstanceId = FGuid::NewGuid();
    Digimon.SpeciesId = Species->GetPrimaryAssetId();
    Digimon.OriginSpeciesId = Digimon.SpeciesId;
    Digimon.DigivolutionHistory.AddUnique(Digimon.SpeciesId);
    Digimon.bStarterPartner = false;
    Digimon.Stats = Species->BaseStats;
    Digimon.Stats.Level = Level;

    const int32 GrowthLevels = FMath::Max(0, Level - FMath::Max(1, Species->StartingLevel));
    auto AddGrowth = [GrowthLevels](const int32 Base, const int32 PerLevel, const int32 Minimum)
    {
        const int64 Value = static_cast<int64>(Base) + static_cast<int64>(FMath::Max(0, PerLevel)) * GrowthLevels;
        return static_cast<int32>(FMath::Clamp<int64>(Value, Minimum, MAX_int32));
    };
    Digimon.Stats.MaxHP = AddGrowth(Digimon.Stats.MaxHP, Species->HPPerLevel, 1);
    Digimon.Stats.MaxSP = AddGrowth(Digimon.Stats.MaxSP, Species->SPPerLevel, 0);
    Digimon.Stats.Strength = AddGrowth(Digimon.Stats.Strength, Species->StrengthPerLevel, 0);
    Digimon.Stats.Intelligence = AddGrowth(Digimon.Stats.Intelligence, Species->IntelligencePerLevel, 0);
    Digimon.Stats.Defense = AddGrowth(Digimon.Stats.Defense, Species->DefensePerLevel, 0);
    Digimon.Stats.Speed = AddGrowth(Digimon.Stats.Speed, Species->SpeedPerLevel, 0);

    // Natural stock variance is separate from trained Attribute Points. This lets two vendor offers at
    // the same level/species have genuinely different base stat rolls without falsely inflating the
    // persistent Attribute Point spend counter used by resale valuation.
    auto RollBonus = [&RandomStream](const int32 A, const int32 B)
    {
        const int32 Minimum = FMath::Max(0, FMath::Min(A, B));
        const int32 Maximum = FMath::Max(Minimum, FMath::Max(A, B));
        return RandomStream.RandRange(Minimum, Maximum);
    };
    auto SafeAddStat = [](const int32 Value, const int32 Bonus, const int32 Minimum)
    {
        return static_cast<int32>(FMath::Clamp<int64>(static_cast<int64>(Value) + FMath::Max(0, Bonus), Minimum, MAX_int32));
    };
    Digimon.Stats.MaxHP = SafeAddStat(Digimon.Stats.MaxHP, RollBonus(Range.MinimumRandomHPBonus, Range.MaximumRandomHPBonus), 1);
    Digimon.Stats.MaxSP = SafeAddStat(Digimon.Stats.MaxSP, RollBonus(Range.MinimumRandomSPBonus, Range.MaximumRandomSPBonus), 0);
    Digimon.Stats.Strength = SafeAddStat(Digimon.Stats.Strength, RollBonus(Range.MinimumRandomCombatStatBonus, Range.MaximumRandomCombatStatBonus), 0);
    Digimon.Stats.Intelligence = SafeAddStat(Digimon.Stats.Intelligence, RollBonus(Range.MinimumRandomCombatStatBonus, Range.MaximumRandomCombatStatBonus), 0);
    Digimon.Stats.Defense = SafeAddStat(Digimon.Stats.Defense, RollBonus(Range.MinimumRandomCombatStatBonus, Range.MaximumRandomCombatStatBonus), 0);
    Digimon.Stats.Speed = SafeAddStat(Digimon.Stats.Speed, RollBonus(Range.MinimumRandomCombatStatBonus, Range.MaximumRandomCombatStatBonus), 0);

    const int32 MinSpent = FMath::Max(0, FMath::Min(Range.MinimumSpentAttributePoints, Range.MaximumSpentAttributePoints));
    const int32 MaxSpent = FMath::Max(MinSpent, FMath::Max(Range.MinimumSpentAttributePoints, Range.MaximumSpentAttributePoints));
    const int32 SpentPoints = RandomStream.RandRange(MinSpent, MaxSpent);
    for (int32 Point = 0; Point < SpentPoints; ++Point)
    {
        DMFApplyOneVendorAttributePoint(Digimon, RandomStream.RandRange(0, 5));
    }
    Digimon.TotalAttributePointsSpent = SpentPoints;

    const int32 MinUnspent = FMath::Max(0, FMath::Min(Range.MinimumUnspentAttributePoints, Range.MaximumUnspentAttributePoints));
    const int32 MaxUnspent = FMath::Max(MinUnspent, FMath::Max(Range.MinimumUnspentAttributePoints, Range.MaximumUnspentAttributePoints));
    Digimon.UnspentAttributePoints = RandomStream.RandRange(MinUnspent, MaxUnspent);

    const int32 MinABI = FMath::Max(0, FMath::Min(Range.MinimumABI, Range.MaximumABI));
    const int32 MaxABI = FMath::Max(MinABI, FMath::Max(Range.MinimumABI, Range.MaximumABI));
    Digimon.Stats.ABI = RandomStream.RandRange(MinABI, MaxABI);
    const int32 MinCAM = FMath::Clamp(FMath::Min(Range.MinimumCAM, Range.MaximumCAM), 0, 100);
    const int32 MaxCAM = FMath::Clamp(FMath::Max(Range.MinimumCAM, Range.MaximumCAM), MinCAM, 100);
    Digimon.Stats.CAM = RandomStream.RandRange(MinCAM, MaxCAM);

    int64 LifetimeExperience = 0;
    for (int32 ProgressLevel = FMath::Max(1, Species->StartingLevel); ProgressLevel < Level; ++ProgressLevel)
    {
        const int64 Required = DMFExperienceRequiredForVendorLevel(*Species, ProgressLevel);
        if (LifetimeExperience > MAX_int64 - Required)
        {
            LifetimeExperience = MAX_int64;
            break;
        }
        LifetimeExperience += Required;
    }
    const int64 CurrentRequirement = DMFExperienceRequiredForVendorLevel(*Species, Level);
    const float MinXPPercent = FMath::Clamp(FMath::Min(Range.MinimumLevelExperiencePercent, Range.MaximumLevelExperiencePercent), 0.0f, 0.999f);
    const float MaxXPPercent = FMath::Clamp(FMath::Max(Range.MinimumLevelExperiencePercent, Range.MaximumLevelExperiencePercent), MinXPPercent, 0.999f);
    Digimon.Stats.Experience = static_cast<int64>(FMath::FloorToDouble(static_cast<double>(CurrentRequirement) * RandomStream.FRandRange(MinXPPercent, MaxXPPercent)));
    Digimon.LifetimeBattleExperience = LifetimeExperience > MAX_int64 - Digimon.Stats.Experience ? MAX_int64 : LifetimeExperience + Digimon.Stats.Experience;

    Digimon.CurrentHP = Digimon.Stats.MaxHP;
    Digimon.CurrentSP = Digimon.Stats.MaxSP;
    Digimon.Care.Hunger = FMath::Clamp(Species->StartingHungerPercent, 0.0f, 100.0f);
    Digimon.Care.Fullness = Digimon.Care.Hunger;
    Digimon.Care.LastCareUpdateUtcTicks = FDateTime::UtcNow().GetTicks();
    Digimon.EquippedAbilityIds = Species->StartingAbilityIds;
    for (const TSoftObjectPtr<UDMFDigimonAbilityData>& SoftAbility : Species->StartingAbilities)
    {
        if (UDMFDigimonAbilityData* Ability = SoftAbility.LoadSynchronous())
        {
            const FName Id = Ability->AbilityId.IsNone() ? Ability->GetPrimaryAssetId().PrimaryAssetName : Ability->AbilityId;
            Digimon.EquippedAbilityIds.AddUnique(Id);
        }
    }
    if (UDMFDigimonAbilityData* Basic = Species->BasicAutoAttack.LoadSynchronous())
    {
        const FName BasicId = Basic->AbilityId.IsNone() ? Basic->GetPrimaryAssetId().PrimaryAssetName : Basic->AbilityId;
        Digimon.EquippedAbilityIds.AddUnique(BasicId);
    }

    OutItem.StockId = FGuid(RandomStream.GetUnsignedInt(), RandomStream.GetUnsignedInt(), RandomStream.GetUnsignedInt(), RandomStream.GetUnsignedInt());
    if (!OutItem.StockId.IsValid()) OutItem.StockId = FGuid::NewGuid();
    OutItem.Digimon = Digimon;
    OutItem.GenerationSerial = StockGenerationSerial;
    const FDMFDigimonVendorValueBreakdown Breakdown = CalculateDigimonValue(Digimon);
    const int64 DiscountedPurchasePrice = DMFClampPriceFromDouble(static_cast<double>(Breakdown.VendorPurchasePrice) * FMath::Max(0.01f, PoolEntry.PurchasePriceMultiplier));
    const int64 AntiArbitrageFloor = Breakdown.PlayerSellPrice >= MAX_int64 ? MAX_int64 : Breakdown.PlayerSellPrice + 1;
    OutItem.PurchasePrice = FMath::Max<int64>(FMath::Max<int64>(Pricing.MinimumTransactionPrice, AntiArbitrageFloor), DiscountedPurchasePrice);
    return true;
}

void ADMFDigimonVendorActor::FillStockToTarget()
{
    if (!HasAuthority())
    {
        return;
    }

    FRandomStream RandomStream(BuildGenerationSeed() + ReplicatedStock.Num() * 31);
    TSet<FPrimaryAssetId> UsedSpecies;
    for (const FDMFDigimonVendorStockItem& Existing : ReplicatedStock)
    {
        UsedSpecies.Add(Existing.Digimon.SpeciesId);
    }

    const int32 TargetSlots = FMath::Clamp(StockSlots, 1, 64);
    int32 Safety = TargetSlots * 8 + 16;
    while (ReplicatedStock.Num() < TargetSlots && Safety-- > 0)
    {
        const FDMFDigimonVendorSpeciesPoolEntry* PoolEntry = SelectWeightedPoolEntry(RandomStream, UsedSpecies);
        if (!PoolEntry)
        {
            break;
        }
        FDMFDigimonVendorStockItem NewItem;
        if (GenerateStockItem(*PoolEntry, RandomStream, NewItem))
        {
            ReplicatedStock.Add(NewItem);
            UsedSpecies.Add(NewItem.Digimon.SpeciesId);
        }
    }
}

void ADMFDigimonVendorActor::RefreshStockNow()
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

void ADMFDigimonVendorActor::RestartStockRotationSchedule()
{
    if (!HasAuthority())
    {
        return;
    }
    ScheduleNextStockRotation(false);
}

void ADMFDigimonVendorActor::ScheduleNextStockRotation(const bool bUseInitialDelay)
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
    GetWorld()->GetTimerManager().SetTimer(StockRotationTimer, this, &ADMFDigimonVendorActor::HandleStockRotationTimer, FMath::Max(0.05f, Delay), false);
    ForceNetUpdate();
}

void ADMFDigimonVendorActor::HandleStockRotationTimer()
{
    RefreshStockNow();
    ScheduleNextStockRotation(false);
}

bool ADMFDigimonVendorActor::TryPurchaseStockAuthoritative(ADMFMMOPlayerController* Buyer, const FGuid StockId, FGuid& OutDigimonInstanceId, int64& OutPrice, FText& OutMessage)
{
    OutDigimonInstanceId.Invalidate();
    OutPrice = 0;
    OutMessage = FText::GetEmpty();

    if (!HasAuthority() || !bVendorEnabled || !bAllowBuying)
    {
        OutMessage = NSLOCTEXT("DMF", "VendorBuyingUnavailable", "This vendor is not selling Digimon right now.");
        return false;
    }
    if (!Buyer || !IsPlayerWithinTradeRange(Buyer))
    {
        OutMessage = NSLOCTEXT("DMF", "VendorBuyerOutOfRange", "Move closer to the Digimon vendor before buying.");
        return false;
    }

    const int32 StockIndex = ReplicatedStock.IndexOfByPredicate([&](const FDMFDigimonVendorStockItem& Item) { return Item.StockId == StockId; });
    if (!ReplicatedStock.IsValidIndex(StockIndex))
    {
        OutMessage = NSLOCTEXT("DMF", "VendorStockAlreadyGone", "That Digimon is no longer available. The stock list has been refreshed.");
        return false;
    }

    ADMFPlayerState* PlayerState = Buyer->GetPlayerState<ADMFPlayerState>();
    UDMFPlayerDigimonComponent* DigimonComponent = PlayerState ? PlayerState->DigimonComponent.Get() : nullptr;
    if (!DigimonComponent)
    {
        OutMessage = NSLOCTEXT("DMF", "VendorBuyerStateUnavailable", "Your Digimon account state is unavailable.");
        return false;
    }

    const FDMFDigimonVendorStockItem Offer = ReplicatedStock[StockIndex];

    // Reserve/remove the shared offer before *any* account-side mutation/broadcast. The player component
    // broadcasts inventory/money changes as part of an otherwise atomic commit, and a server Blueprint may
    // react to those delegates. Removing first makes the StockId unavailable to all re-entrant/concurrent
    // purchase attempts. If the account commit fails, restore the exact immutable offer in-place.
    ReplicatedStock.RemoveAt(StockIndex);

    EDMFDigimonStorageLocation Destination = EDMFDigimonStorageLocation::Party;
    if (!DigimonComponent->AuthorityPurchaseVendorDigimon(Offer.Digimon, Offer.PurchasePrice, bPreferPurchasedDigimonToBank, OutDigimonInstanceId, Destination, OutMessage))
    {
        ReplicatedStock.Insert(Offer, FMath::Clamp(StockIndex, 0, ReplicatedStock.Num()));
        return false;
    }

    OutPrice = Offer.PurchasePrice;
    FDMFDigimonInstance PurchasedDigimon = Offer.Digimon;
    PurchasedDigimon.InstanceId = OutDigimonInstanceId;

    if (bRefillSoldSlotsImmediately)
    {
        FillStockToTarget();
    }
    OnVendorStockChanged.Broadcast();
    BP_OnStockRefreshed();
    ForceNetUpdate();

    OnVendorTradeCompleted.Broadcast(Buyer, EDMFDigimonVendorTransactionType::Buy, PurchasedDigimon, OutPrice);
    BP_OnVendorTradeCompleted(Buyer, EDMFDigimonVendorTransactionType::Buy, PurchasedDigimon, OutPrice);
    return true;
}

bool ADMFDigimonVendorActor::TrySellDigimonAuthoritative(ADMFMMOPlayerController* Seller, const FGuid DigimonInstanceId, int64& OutPrice, FText& OutMessage)
{
    OutPrice = 0;
    OutMessage = FText::GetEmpty();
    if (!HasAuthority() || !bVendorEnabled || !bAllowSelling)
    {
        OutMessage = NSLOCTEXT("DMF", "VendorSellingUnavailable", "This vendor is not buying Digimon right now.");
        return false;
    }
    if (!Seller || !IsPlayerWithinTradeRange(Seller))
    {
        OutMessage = NSLOCTEXT("DMF", "VendorSellerOutOfRange", "Move closer to the Digimon vendor before selling.");
        return false;
    }

    ADMFPlayerState* PlayerState = Seller->GetPlayerState<ADMFPlayerState>();
    UDMFPlayerDigimonComponent* DigimonComponent = PlayerState ? PlayerState->DigimonComponent.Get() : nullptr;
    FDMFDigimonInstance Digimon;
    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Party;
    if (!DigimonComponent || !DigimonComponent->GetOwnedDigimonByInstanceId(DigimonInstanceId, Digimon, Location))
    {
        OutMessage = NSLOCTEXT("DMF", "VendorSellerDigimonMissing", "That Digimon is no longer owned by this account.");
        return false;
    }

    OutPrice = GetPlayerSellPrice(Digimon);
    FDMFDigimonInstance SoldDigimon;
    if (!DigimonComponent->AuthoritySellDigimonToVendor(DigimonInstanceId, OutPrice, bAllowSellingStarterDigimon, bRequireAtLeastOnePartyDigimon, SoldDigimon, OutMessage))
    {
        OutPrice = 0;
        return false;
    }
    OnVendorTradeCompleted.Broadcast(Seller, EDMFDigimonVendorTransactionType::Sell, SoldDigimon, OutPrice);
    BP_OnVendorTradeCompleted(Seller, EDMFDigimonVendorTransactionType::Sell, SoldDigimon, OutPrice);
    return true;
}

void ADMFDigimonVendorActor::OnRep_Stock()
{
    OnVendorStockChanged.Broadcast();
    BP_OnStockRefreshed();
}

void ADMFDigimonVendorActor::OnRep_VendorEnabled()
{
    OnVendorEnabledChanged.Broadcast(bVendorEnabled);
    BP_OnVendorEnabledChanged(bVendorEnabled);
}

void ADMFDigimonVendorActor::OnRep_Configuration()
{
    OnVendorConfigurationChanged.Broadcast();
}
