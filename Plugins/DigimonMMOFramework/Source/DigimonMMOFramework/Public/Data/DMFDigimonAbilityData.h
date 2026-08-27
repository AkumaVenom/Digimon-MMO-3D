#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DMFTypes.h"
#include "DMFDigimonAbilityData.generated.h"

class ADMFAbilityProjectileActor;
class UAnimMontage;
class UParticleSystem;
class UNiagaraSystem;
class USoundBase;
class UStaticMesh;
class UTexture2D;

/**
 * Determines how an authoritative ability reaches its target.
 * TimedImpact preserves the original v0.x behavior. Projectile launches a replicated world actor
 * whose arrival owns the authoritative damage timing.
 */
UENUM(BlueprintType)
enum class EDMFAbilityExecutionMode : uint8
{
    TimedImpact UMETA(DisplayName="Timed / Instant Impact"),
    Projectile UMETA(DisplayName="Replicated Projectile")
};

/**
 * Server-authoritative combat ability definition.
 * Gameplay fields are consumed only by the authority. Presentation fields are used by replicated
 * cosmetic cues or the replicated projectile actor so Blueprint projects can replace visuals
 * without changing combat math.
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

    /**
     * Timed Impact: delay before authoritative damage.
     * Replicated Projectile: delay before the server launches the projectile from its spawn socket.
     */
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

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Execution")
    EDMFAbilityExecutionMode ExecutionMode = EDMFAbilityExecutionMode::TimedImpact;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    TSoftObjectPtr<UAnimMontage> Montage;

    /** Timed-impact VFX. In Projectile mode these become the projectile visual fallback when the dedicated projectile VFX fields are empty. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation|Cascade")
    TSoftObjectPtr<UParticleSystem> CascadeParticle;

    /** Timed-impact VFX. In Projectile mode this becomes the projectile visual fallback when Projectile Niagara System is empty. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation|Niagara")
    TSoftObjectPtr<UNiagaraSystem> NiagaraParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    TSoftObjectPtr<USoundBase> AttackSound;

    /** Socket for timed presentation VFX and the default projectile launch origin. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    FName VFXSocketName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    bool bSpawnVFXAtTarget = true;

    /** Forced lifetime for transient non-projectile Niagara/Cascade cues, including looping systems. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation", meta=(ClampMin="0.05", ClampMax="30.0"))
    float PresentationVFXLifetimeSeconds = 2.0f;

    /** Applied to transient timed-impact VFX after the framework rotates the cue toward the target. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    FRotator PresentationVFXRotationOffset = FRotator::ZeroRotator;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    FVector PresentationVFXScale = FVector::OneVector;

    // ---- Replicated projectile execution ----

    /** Optional Blueprint subclass. Empty uses the native DMF Ability Projectile Actor. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Class", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    TSoftClassPtr<ADMFAbilityProjectileActor> ProjectileClass;

    /** Dedicated moving Niagara visual. Empty falls back to Niagara Particle above. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Visual", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    TSoftObjectPtr<UNiagaraSystem> ProjectileNiagaraSystem;

    /** Dedicated moving Cascade visual. Used when Niagara is unavailable. Empty falls back to Cascade Particle above. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Visual", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    TSoftObjectPtr<UParticleSystem> ProjectileCascadeParticle;

    /** Optional mesh carried by the projectile in addition to Niagara/Cascade. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Visual", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    TSoftObjectPtr<UStaticMesh> ProjectileStaticMesh;

    /** Corrects assets authored along a local axis other than Unreal forward (+X). */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Visual", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    FRotator ProjectileVisualRotationOffset = FRotator::ZeroRotator;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Visual", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    FVector ProjectileVisualScale = FVector::OneVector;

    /** Optional projectile-only spawn socket. NAME_None falls back to VFX Socket Name, then the Digimon actor origin. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Launch", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    FName ProjectileSpawnSocketName = NAME_None;

    /** Local-space offset from the selected launch socket/actor transform. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Launch", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    FVector ProjectileSpawnOffset = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Movement", meta=(ClampMin="1.0", EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    float ProjectileSpeed = 1400.0f;

    /** When true the authoritative projectile turns toward the moving target during flight. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Movement", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    bool bProjectileHoming = true;

    /** Maximum homing turn rate in degrees per second. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Movement", meta=(ClampMin="0.0", ClampMax="10000.0", EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    float ProjectileHomingTurnRateDegrees = 720.0f;

    /** Offset applied to the target actor location when calculating projectile aim. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Movement", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    FVector ProjectileTargetOffset = FVector::ZeroVector;

    /** Radius around the target aim point that counts as an authoritative projectile arrival. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Impact", meta=(ClampMin="1.0", EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    float ProjectileImpactRadius = 55.0f;

    /** Hard cleanup guard. Projectile actor and all attached VFX are destroyed after this many seconds even if no impact occurs. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Impact", meta=(ClampMin="0.1", ClampMax="60.0", EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    float ProjectileMaxLifetimeSeconds = 6.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Impact", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    TSoftObjectPtr<UNiagaraSystem> ProjectileImpactNiagaraSystem;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Impact", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    TSoftObjectPtr<UParticleSystem> ProjectileImpactCascadeParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Impact", meta=(EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    TSoftObjectPtr<USoundBase> ProjectileImpactSound;

    /** Forced cleanup lifetime for impact Niagara/Cascade, including accidentally looping systems. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile|Impact", meta=(ClampMin="0.05", ClampMax="30.0", EditCondition="ExecutionMode == EDMFAbilityExecutionMode::Projectile", EditConditionHides))
    float ProjectileImpactVFXLifetimeSeconds = 2.0f;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        const FName EffectiveName = AbilityId.IsNone() ? GetFName() : AbilityId;
        return FPrimaryAssetId(TEXT("DMFDigimonAbility"), EffectiveName);
    }
};
