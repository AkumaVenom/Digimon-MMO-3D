#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DMFTypes.h"
#include "DMFDigimonAbilityData.generated.h"

class UAnimMontage;
class UParticleSystem;
class UNiagaraSystem;
class USoundBase;
class UTexture2D;

/**
 * Server-authoritative combat ability definition.
 * Gameplay fields are consumed only by the authority. Presentation fields are used by the
 * replicated cosmetic cue so Blueprint projects can replace visuals without changing combat math.
 */
UCLASS(BlueprintType)
class DIGIMONMMOFRAMEWORK_API UDMFDigimonAbilityData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FName AbilityId;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity", meta=(MultiLine=true))
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    TSoftObjectPtr<UTexture2D> Icon;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cost", meta=(ClampMin="0"))
    int32 SPCost = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Timing", meta=(ClampMin="0.0"))
    float CooldownSeconds = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Timing", meta=(ClampMin="0.0"))
    float ImpactDelaySeconds = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Timing", meta=(ClampMin="0.0"))
    float RecoverySeconds = 0.35f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Targeting", meta=(ClampMin="0.0"))
    float MaxRange = 250.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Targeting")
    bool bRequiresTarget = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage", meta=(ClampMin="0.0"))
    float BasePower = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage")
    EDMFDamageScaling ScalingStat = EDMFDamageScaling::Strength;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage", meta=(ClampMin="0.0"))
    float StatScaling = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage", meta=(ClampMin="0.0"))
    float DefenseScaling = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Automation")
    bool bEligibleForAutoBattle = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    TSoftObjectPtr<UAnimMontage> Montage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation|Cascade")
    TSoftObjectPtr<UParticleSystem> CascadeParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation|Niagara")
    TSoftObjectPtr<UNiagaraSystem> NiagaraParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    TSoftObjectPtr<USoundBase> AttackSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    FName VFXSocketName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    bool bSpawnVFXAtTarget = true;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        const FName EffectiveName = AbilityId.IsNone() ? GetFName() : AbilityId;
        return FPrimaryAssetId(TEXT("DMFDigimonAbility"), EffectiveName);
    }
};
