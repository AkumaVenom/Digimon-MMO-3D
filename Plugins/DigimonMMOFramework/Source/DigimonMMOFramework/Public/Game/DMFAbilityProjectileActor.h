#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMFAbilityProjectileActor.generated.h"

class ADMFDigimonCharacter;
class UDMFDigimonAbilityData;
class UNiagaraComponent;
class UParticleSystemComponent;
class USceneComponent;
class UStaticMeshComponent;

/**
 * Native replicated projectile used by DMFDigimonAbilityData Projectile execution.
 *
 * The server alone advances authoritative flight and decides arrival/damage. Replicated actor
 * movement gives every relevant client the same visible projectile. All VFX/mesh components are
 * cosmetic children of the actor and are destroyed with it on impact or the hard lifetime guard.
 * Projects may subclass this actor in Blueprint for additional cosmetic presentation without
 * moving damage or target authority out of the combat component.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFAbilityProjectileActor : public AActor
{
    GENERATED_BODY()

public:
    ADMFAbilityProjectileActor();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Projectile")
    TObjectPtr<USceneComponent> ProjectileRoot;

    /** Rotated/scaled independently so particle assets authored on a non-X forward axis are easy to correct. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Projectile")
    TObjectPtr<USceneComponent> VisualRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Projectile")
    TObjectPtr<UStaticMeshComponent> ProjectileMeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Projectile")
    TObjectPtr<UNiagaraComponent> ProjectileNiagaraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Projectile")
    TObjectPtr<UParticleSystemComponent> ProjectileCascadeComponent;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Projectile")
    FName GetAbilityId() const { return AbilityId; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Projectile")
    ADMFDigimonCharacter* GetSourceDigimon() const { return SourceDigimon; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Projectile")
    ADMFDigimonCharacter* GetTargetDigimon() const { return TargetDigimon; }

    /** Re-resolves the Data Asset and reapplies mesh/Niagara/Cascade/relative visual tuning. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Combat|Projectile|Presentation")
    void RefreshProjectilePresentation();

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Combat|Projectile|Presentation")
    void BP_OnProjectilePresentationReady();

    /** Authority initialization performed before FinishSpawning so initial replication is coherent. */
    void InitializeProjectile(FName InAbilityId, ADMFDigimonCharacter* InSource, ADMFDigimonCharacter* InTarget, const FVector& InInitialDirection);

protected:
    UPROPERTY(ReplicatedUsing=OnRep_ProjectileDefinition)
    FName AbilityId = NAME_None;

    UPROPERTY(ReplicatedUsing=OnRep_ProjectileDefinition)
    TObjectPtr<ADMFDigimonCharacter> SourceDigimon;

    UPROPERTY(ReplicatedUsing=OnRep_ProjectileDefinition)
    TObjectPtr<ADMFDigimonCharacter> TargetDigimon;

    /** Initial/non-homing direction. Server updates actor rotation during homing flight. */
    UPROPERTY(Replicated)
    FVector TravelDirection = FVector::ForwardVector;

    UFUNCTION()
    void OnRep_ProjectileDefinition();

private:
    UDMFDigimonAbilityData* ResolveAbilityData() const;
    FVector GetTargetAimPoint(const UDMFDigimonAbilityData& Ability) const;
    void HandleAuthoritativeArrival(const FVector& ImpactLocation);
    bool bPresentationInitialized = false;
    bool bAuthoritativeImpactConsumed = false;
};
