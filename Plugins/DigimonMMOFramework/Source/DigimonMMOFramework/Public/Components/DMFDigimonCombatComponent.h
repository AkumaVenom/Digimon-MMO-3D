#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DMFTypes.h"
#include "DMFDigimonCombatComponent.generated.h"

class ADMFDigimonCharacter;
class UDMFDigimonAbilityData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFCombatVitalsChanged, int32, CurrentHP, int32, CurrentSP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFCombatTargetChanged, ADMFDigimonCharacter*, NewTarget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFCombatStateChanged, EDMFCombatState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFDigimonDefeated, ADMFDigimonCharacter*, DefeatedDigimon, ADMFDigimonCharacter*, Killer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFAbilityExecuted, FName, AbilityId, ADMFDigimonCharacter*, Target);

/**
 * Shared authoritative combat runtime for player partners, wild Digimon and NPC/ranked Digimon.
 * Clients request commands through an owning PlayerState component; all cost/range/cooldown/damage
 * validation happens here on the server.
 */
UCLASS(ClassGroup=(DigimonMMO), meta=(BlueprintSpawnableComponent))
class DIGIMONMMOFRAMEWORK_API UDMFDigimonCombatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDMFDigimonCombatComponent();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Combat")
    FDMFCombatVitalsChanged OnVitalsChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Combat")
    FDMFCombatTargetChanged OnTargetChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Combat")
    FDMFCombatStateChanged OnCombatStateChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Combat")
    FDMFDigimonDefeated OnDefeated;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Combat")
    FDMFAbilityExecuted OnAbilityExecuted;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    int32 GetCurrentHP() const { return CurrentHP; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    int32 GetCurrentSP() const { return CurrentSP; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    EDMFCombatState GetCombatState() const { return CombatState; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    ADMFDigimonCharacter* GetCurrentTarget() const { return CurrentTarget; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    bool IsDefeated() const { return CombatState == EDMFCombatState::Defeated || CurrentHP <= 0; }

    /**
     * Server-authoritative encounter latch. Unlike CombatState, this remains true through intentional
     * Idle gaps between manual ability commands and clears only when the encounter actually ends.
     */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    bool IsBattleEncounterActive() const { return bBattleEncounterActive; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    float GetRemainingCooldown(FName AbilityId) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    bool CanAttackTarget(const ADMFDigimonCharacter* Candidate) const;

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    void InitializeRuntimeVitals(int32 InCurrentHP, int32 InCurrentSP);

    /** Updates HP/SP after persistent level growth without tearing down combat state, target, encounter, cooldowns or recovery. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat|Progression")
    void RefreshRuntimeVitalsAfterProgression(int32 InCurrentHP, int32 InCurrentSP);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    void ConfigureAutomation(bool bInAutoBattleEnabled, float InAggroRange, float InLeashRange, AActor* InFollowAnchor);

    /**
     * Enables server-authoritative reactive combat independently from proactive auto battle.
     * When enabled, this Digimon will defend itself against a valid hostile attacker without
     * scanning for or initiating combat against nearby targets.
     */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat|Reactive")
    void ConfigureRetaliation(bool bInRetaliateWhenAttacked);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Reactive")
    bool IsRetaliationEnabled() const { return bRetaliateWhenAttacked; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Reactive")
    bool IsRetaliating() const { return bRetaliationCombatActive; }

    /** Role-level balance tuning. Server-only and intentionally separate from persistent species stats. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat|Balance")
    void ConfigureDamageTuning(float InOutgoingDamageMultiplier, float InIncomingDamageMultiplier);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Balance")
    float GetOutgoingDamageMultiplier() const { return OutgoingDamageMultiplier; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Balance")
    float GetIncomingDamageMultiplier() const { return IncomingDamageMultiplier; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat")
    bool IsAutoBattleEnabled() const { return bAutoBattleEnabled; }

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    void SetAuthoritativeTarget(ADMFDigimonCharacter* NewTarget);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    bool TryExecuteAbilityById(FName AbilityId, ADMFDigimonCharacter* RequestedTarget);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    bool TryExecuteAbilitySlot(int32 SlotIndex, ADMFDigimonCharacter* RequestedTarget);

    /** Executes immediately when legal, otherwise chases and revalidates the queued command in range. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    bool QueueOrExecuteAbilitySlot(int32 SlotIndex, ADMFDigimonCharacter* RequestedTarget);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    int32 ApplyAuthoritativeDamage(int32 Damage, ADMFDigimonCharacter* InstigatorDigimon);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    void RestoreVitalsToMaximum();

    /** Selective full restore used by healer actors. Restoring HP revives a defeated Digimon. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    void RestoreVitals(bool bRestoreHP, bool bRestoreSP, bool bResetCombat = true);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    void NotifyAuthoritativeVictory(ADMFDigimonCharacter* DefeatedDigimon);

    /** Native projectile callback. Damage remains authority-only and is accepted only for the projectile's authored ability/target. */
    void HandleAuthoritativeProjectileImpact(FName AbilityId, ADMFDigimonCharacter* Target, const FVector& ImpactLocation);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Abilities")
    UDMFDigimonAbilityData* ResolveAbilityData(FName AbilityId) const;

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Combat|Presentation")
    void BP_OnAbilityCosmeticCue(FName AbilityId, ADMFDigimonCharacter* Target);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Combat|Presentation")
    void BP_OnDefeatedCosmetics(ADMFDigimonCharacter* Killer);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Combat|Presentation")
    void BP_OnVictoryCosmetics(ADMFDigimonCharacter* DefeatedDigimon);

private:
    UPROPERTY(ReplicatedUsing=OnRep_Vitals)
    int32 CurrentHP = 1;

    UPROPERTY(ReplicatedUsing=OnRep_Vitals)
    int32 CurrentSP = 0;

    UPROPERTY(ReplicatedUsing=OnRep_CombatState)
    EDMFCombatState CombatState = EDMFCombatState::Idle;

    UPROPERTY(ReplicatedUsing=OnRep_CurrentTarget)
    TObjectPtr<ADMFDigimonCharacter> CurrentTarget;

    /**
     * Durable server-owned encounter truth for systems that must outlive per-attack animation states.
     * It intentionally survives Chasing/Attacking/Recovering -> Idle gaps while a valid battle remains.
     */
    UPROPERTY(Replicated)
    bool bBattleEncounterActive = false;

    /** Proactive acquisition/attack behavior. False does not suppress configured retaliation. */
    bool bAutoBattleEnabled = false;
    /** Reactive combat is a separate policy so passive wild Digimon can still defend themselves. */
    bool bRetaliateWhenAttacked = false;
    /** Server-only transient state: current target was established by taking hostile damage. */
    bool bRetaliationCombatActive = false;
    float OutgoingDamageMultiplier = 1.0f;
    float IncomingDamageMultiplier = 1.0f;
    float AggroRange = 1200.0f;
    float LeashRange = 2200.0f;
    FVector HomeLocation = FVector::ZeroVector;
    TWeakObjectPtr<AActor> FollowAnchor;
    UPROPERTY(Replicated)
    TArray<FDMFAbilityCooldownState> ReplicatedCooldowns;
    FName QueuedAbilityId = NAME_None;
    TWeakObjectPtr<ADMFDigimonCharacter> QueuedTarget;
    double QueuedCommandExpireTime = 0.0;
    FTimerHandle AutomationTimer;
    FTimerHandle RecoveryTimer;
    /** Server-only AI intent. Kept stable while chasing so different ability ranges cannot thrash movement. */
    FName PendingAutoBattleAbilityId = NAME_None;
    /** Server-only least-recently-used history for fair use of the full eligible moveset. */
    TMap<FName, uint64> AutoBattleAbilityUseSerials;
    uint64 AutoBattleAbilityUseCounter = 0;

    UFUNCTION()
    void OnRep_Vitals();

    UFUNCTION()
    void OnRep_CurrentTarget();

    UFUNCTION()
    void OnRep_CombatState();

    UFUNCTION(NetMulticast, Unreliable)
    void MulticastPlayAbilityCue(FName AbilityId, ADMFDigimonCharacter* Target);

    /** Transient projectile impact presentation. Gameplay damage has already been accepted by authority before this cue. */
    UFUNCTION(NetMulticast, Unreliable)
    void MulticastPlayProjectileImpactCue(FName AbilityId, FVector_NetQuantize ImpactLocation);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastDefeatedCue(ADMFDigimonCharacter* Killer);

    UFUNCTION(NetMulticast, Unreliable)
    void MulticastVictoryCue(ADMFDigimonCharacter* DefeatedDigimon);

    void AutomationTick();
    void BeginRetaliation(ADMFDigimonCharacter* Aggressor);
    void EndRetaliation();
    bool ProcessQueuedCommand();
    void QueueAbilityCommand(FName AbilityId, ADMFDigimonCharacter* Target, const UDMFDigimonAbilityData& Ability, float MinimumWaitSeconds = 0.0f);
    void ClearQueuedCommand();
    void PruneExpiredCooldowns();
    ADMFDigimonCharacter* AcquireNearestHostile() const;
    FName ResolveBasicAttackId() const;
    /**
     * Chooses from the complete equipped moveset rather than hard-wiring BasicAutoAttack.
     * Range is intentionally not a readiness gate; automation can select a short-range move and
     * chase into that move's authored reach before executing it.
     */
    FName SelectAutoBattleAbility(ADMFDigimonCharacter* Target);
    bool IsAutoBattleAbilityReady(FName AbilityId, ADMFDigimonCharacter* Target) const;
    void RecordAutoBattleAbilityUse(FName AbilityId);
    void ResetAutoBattleAbilityRotation();
    bool ValidateAbilityUse(const UDMFDigimonAbilityData& Ability, ADMFDigimonCharacter* Target, FText* OutFailure = nullptr) const;
    /** Horizontal combat distance measured from collision-capsule edge to edge, not actor center to center. */
    float GetTargetEdgeDistance2D(const ADMFDigimonCharacter* Target) const;
    /** Uses capsule-aware edge distance so short-range attacks remain reachable for differently sized Digimon. */
    bool IsTargetWithinAbilityRange(const ADMFDigimonCharacter* Target, float AbilityRange) const;
    /** Path-following acceptance radius that guarantees the final position is inside the same capsule-aware ability range. */
    float GetAbilityMoveAcceptanceRadius(const ADMFDigimonCharacter* Target, float AbilityRange) const;
    int32 GetEffectiveSPCost(const UDMFDigimonAbilityData& Ability) const;
    int32 CalculateDamage(const UDMFDigimonAbilityData& Ability, const ADMFDigimonCharacter& Target) const;
    void ApplyAbilityImpact(FName AbilityId, TWeakObjectPtr<ADMFDigimonCharacter> Target);
    void SpawnAuthoritativeProjectile(FName AbilityId, TWeakObjectPtr<ADMFDigimonCharacter> Target);
    void SpawnTransientAbilityVFX(const UDMFDigimonAbilityData& Ability, ADMFDigimonCharacter* Target);
    void SpawnTransientProjectileImpactVFX(const UDMFDigimonAbilityData& Ability, const FVector& ImpactLocation);
    void FinishRecovery();
    void SetCombatState(EDMFCombatState NewState);
    void SetBattleEncounterActive(bool bActive);
    void PlayNativeAbilityPresentation(FName AbilityId, ADMFDigimonCharacter* Target);
};
