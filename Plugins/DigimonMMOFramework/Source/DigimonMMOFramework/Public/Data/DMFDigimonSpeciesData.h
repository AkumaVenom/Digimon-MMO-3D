#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DMFTypes.h"
#include "DMFDigimonSpeciesData.generated.h"

class ADMFDigimonCharacter;
class USkeletalMesh;
class UStaticMesh;
class UAnimMontage;
class UParticleSystem;
class UNiagaraSystem;
class USoundBase;
class UTexture2D;
class UDMFDigimonAbilityData;

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigivolutionRequirement
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Evolution")
    TSoftObjectPtr<class UDMFDigimonSpeciesData> TargetSpecies;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Evolution", meta=(ClampMin="1"))
    int32 RequiredLevel = 1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Evolution")
    bool bRequireStats = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Evolution", meta=(EditCondition="bRequireStats", ClampMin="0"))
    int32 MinimumStrength = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Evolution", meta=(EditCondition="bRequireStats", ClampMin="0"))
    int32 MinimumIntelligence = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Evolution", meta=(EditCondition="bRequireStats", ClampMin="0"))
    int32 MinimumDefense = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Evolution", meta=(EditCondition="bRequireStats", ClampMin="0"))
    int32 MinimumSpeed = 0;
};

UCLASS(BlueprintType)
class DIGIMONMMOFRAMEWORK_API UDMFDigimonSpeciesData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FName SpeciesKey;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity", meta=(MultiLine=true))
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    EDMFDigimonStage Stage = EDMFDigimonStage::Rookie;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    EDMFDigimonAttribute Attribute = EDMFDigimonAttribute::Unknown;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    EDMFDigimonElement Element = EDMFDigimonElement::Neutral;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Progression", meta=(ClampMin="1"))
    int32 StartingLevel = 1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Progression")
    FDMFDigimonStats BaseStats;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Progression", meta=(ClampMin="0"))
    int32 AttributePointsPerLevel = 3;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Abilities")
    TArray<FName> StartingAbilityIds;

    /** Preferred Blueprint-first ability references. IDs are still persisted per instance. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Abilities")
    TArray<TSoftObjectPtr<UDMFDigimonAbilityData>> StartingAbilities;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Abilities")
    TSoftObjectPtr<UDMFDigimonAbilityData> BasicAutoAttack;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Battle Rewards", meta=(ClampMin="0"))
    int64 BattleExperienceReward = 25;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Battle Rewards", meta=(ClampMin="0"))
    int64 BattleMoneyReward = 10;

    /** Whether victories against this species can add account-owned Scan Data. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scan & Materialization")
    bool bScanDataEnabled = true;

    /** Scan percentage awarded by one eligible authoritative victory. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scan & Materialization", meta=(EditCondition="bScanDataEnabled", ClampMin="0.0", ClampMax="999.0"))
    float BattleScanPercentReward = 20.0f;

    /** Maximum Scan Data that may be stored for this species. Set above the requirement to bank multiple materializations. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scan & Materialization", meta=(EditCondition="bScanDataEnabled", ClampMin="1.0", ClampMax="999.0"))
    float ScanPercentCap = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scan & Materialization")
    bool bMaterializationEnabled = true;

    /** Amount consumed when this species is materialized into a permanent owned Digimon. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scan & Materialization", meta=(EditCondition="bMaterializationEnabled", ClampMin="1.0", ClampMax="999.0"))
    float MaterializationRequiredScanPercent = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Wild Scaling", meta=(ClampMin="0"))
    int32 HPPerLevel = 8;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Wild Scaling", meta=(ClampMin="0"))
    int32 SPPerLevel = 3;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Wild Scaling", meta=(ClampMin="0"))
    int32 StrengthPerLevel = 2;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Wild Scaling", meta=(ClampMin="0"))
    int32 IntelligencePerLevel = 2;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Wild Scaling", meta=(ClampMin="0"))
    int32 DefensePerLevel = 2;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Wild Scaling", meta=(ClampMin="0"))
    int32 SpeedPerLevel = 1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Evolution")
    TArray<FDMFDigivolutionRequirement> Digivolutions;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="3D Presentation")
    TSoftClassPtr<ADMFDigimonCharacter> WorldActorClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="3D Presentation")
    TSoftObjectPtr<USkeletalMesh> PreviewMesh;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="3D Presentation")
    TSoftObjectPtr<UTexture2D> Portrait;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
    TSoftObjectPtr<UAnimMontage> Attack1Montage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
    TSoftObjectPtr<UAnimMontage> Attack2Montage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
    TSoftObjectPtr<UAnimMontage> DeathMontage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
    TSoftObjectPtr<UAnimMontage> FeedingMontage;

    // -------------------- Virtual Pet Care --------------------

    /** Master per-species care switch. Hunger, feeding and waste are ignored when disabled. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care")
    bool bCareEnabled = true;

    /** New Digimon begin at this Hunger percentage. In this framework, 100 means fully fed. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Hunger", meta=(EditCondition="bCareEnabled", ClampMin="0.0", ClampMax="100.0"))
    float StartingHungerPercent = 100.0f;

    /** Real-time Hunger loss per hour, applied by the server and across offline time. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Hunger", meta=(EditCondition="bCareEnabled", ClampMin="0.0", ClampMax="100.0"))
    float HungerDecayPercentPerHour = 4.0f;

    /** Hunger restored after one complete DigiMeat serving presentation. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Feeding", meta=(EditCondition="bCareEnabled", ClampMin="0.1", ClampMax="100.0"))
    float DigiMeatHungerPercentPerServing = 25.0f;

    /** The feeding Montage is replayed this many times consecutively for each serving. Default is exactly two. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Feeding", meta=(EditCondition="bCareEnabled", ClampMin="1", ClampMax="8"))
    int32 FeedingMontagePlaysPerServing = 2;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Feeding", meta=(EditCondition="bCareEnabled", ClampMin="0.05", ClampMax="4.0"))
    float FeedingMontagePlayRate = 1.0f;

    /** Text-writable skeletal socket/bone name used to attach DigiMeat to this species' hand. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Feeding", meta=(EditCondition="bCareEnabled"))
    FName DigiMeatHandSocketName = TEXT("hand_r");

    /** Optional species override. If empty, the framework Default DigiMeat Mesh is used. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Feeding", meta=(EditCondition="bCareEnabled"))
    TSoftObjectPtr<UStaticMesh> DigiMeatMesh;

    /** Per-species socket offset/rotation/scale. Scale is intentionally exposed because Digimon skeleton socket scales vary heavily. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Feeding", meta=(EditCondition="bCareEnabled"))
    FTransform DigiMeatRelativeTransform = FTransform::Identity;

    /** Dedicated eating voices. One deterministic index is chosen by the server per serving and multicast to viewers. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Audio", meta=(EditCondition="bCareEnabled"))
    TArray<TSoftObjectPtr<USoundBase>> FeedingVoiceSounds;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Waste", meta=(EditCondition="bCareEnabled"))
    bool bWasteEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Waste", meta=(EditCondition="bCareEnabled && bWasteEnabled", ClampMin="1.0"))
    float MinimumWasteDelaySeconds = 120.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Waste", meta=(EditCondition="bCareEnabled && bWasteEnabled", ClampMin="1.0"))
    float MaximumWasteDelaySeconds = 180.0f;

    /** Optional species override. If empty, the framework Default Poo Mesh is used. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Waste", meta=(EditCondition="bCareEnabled && bWasteEnabled"))
    TSoftObjectPtr<UStaticMesh> PooMesh;

    /** World scale for the spawned poo actor. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Waste", meta=(EditCondition="bCareEnabled && bWasteEnabled"))
    FVector PooWorldScale = FVector(1.0f);

    /** Small offset along the traced ground normal to avoid z-fighting. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Waste", meta=(EditCondition="bCareEnabled && bWasteEnabled", ClampMin="0.0", ClampMax="50.0"))
    float PooGroundOffset = 1.5f;

    /** Automatic server-side cleanup lifetime for replicated poo. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Waste", meta=(EditCondition="bCareEnabled && bWasteEnabled", ClampMin="1.0"))
    float PooLifetimeSeconds = 180.0f;

    /** Optional funny fart cues played for all relevant clients when this Digimon poops. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Care|Audio", meta=(EditCondition="bCareEnabled && bWasteEnabled"))
    TArray<TSoftObjectPtr<USoundBase>> WasteFartSounds;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
    TSoftObjectPtr<UAnimMontage> InteractMontage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
    TSoftObjectPtr<UAnimMontage> WinMontage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VFX|Cascade")
    TSoftObjectPtr<UParticleSystem> Attack1CascadeParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VFX|Cascade")
    TSoftObjectPtr<UParticleSystem> Attack2CascadeParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VFX|Niagara")
    TSoftObjectPtr<UNiagaraSystem> Attack1NiagaraParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VFX|Niagara")
    TSoftObjectPtr<UNiagaraSystem> Attack2NiagaraParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio")
    TArray<TSoftObjectPtr<USoundBase>> IdleVoiceSounds;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        const FName EffectiveName = SpeciesKey.IsNone() ? GetFName() : SpeciesKey;
        return FPrimaryAssetId(TEXT("DMFDigimonSpecies"), EffectiveName);
    }
};
