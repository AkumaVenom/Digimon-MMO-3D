#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DMFTypes.h"
#include "DMFDigimonCharacter.generated.h"

class ADMFPlayerState;
class UDMFDigimonCombatComponent;
class UDMFDigimonSpeciesData;
class UAnimMontage;
class AActor;

UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFDigimonCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ADMFDigimonCharacter();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Digimon")
    void InitializeFromInstance(const FDMFDigimonInstance& Instance, ADMFPlayerState* InOwningPlayerState);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    void SetCombatTeamId(FName NewTeamId);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat")
    void ConfigureCombatAutomation(bool bEnableAutoBattle, float AggroRange, float LeashRange, AActor* FollowAnchor);

    /**
     * Starts a bounded server-side turn-in-place loop toward a combat target. Actor rotation is carried
     * to clients by normal Character replicated movement; no cosmetic rotation RPC or client authority is used.
     */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat|Facing")
    void StartCombatFacingTarget(AActor* TargetActor);

    /** Stops combat-facing and restores the CharacterMovement rotation policy that was active beforehand. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Combat|Facing")
    void StopCombatFacingTarget();

    /** True when this Digimon is within AttackFacingToleranceDegrees of the supplied actor on yaw. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Facing")
    bool IsFacingActor(AActor* TargetActor) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Facing")
    AActor* GetCombatFacingTarget() const { return CombatFacingTarget.Get(); }

    /** Master switch for automatic target-facing before/during attacks. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Combat|Facing")
    bool bEnableCombatFacing = true;

    /** If true, an attack cannot begin until the server has turned within the configured yaw tolerance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Combat|Facing", meta=(EditCondition="bEnableCombatFacing"))
    bool bRequireFacingBeforeAttack = true;

    /** Yaw turn speed while aligning to the current combat target. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Combat|Facing", meta=(EditCondition="bEnableCombatFacing", ClampMin="1.0", UIMin="90.0", UIMax="1440.0"))
    float CombatFacingTurnRateDegreesPerSecond = 720.0f;

    /** Maximum yaw error accepted before an attack may start. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Combat|Facing", meta=(EditCondition="bEnableCombatFacing", ClampMin="0.1", ClampMax="90.0", UIMin="1.0", UIMax="45.0"))
    float AttackFacingToleranceDegrees = 8.0f;

    /** Server update interval used only while a Digimon is actively turning to attack. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Digimon MMO|Combat|Facing", meta=(EditCondition="bEnableCombatFacing", ClampMin="0.016", ClampMax="0.10", UIMin="0.016", UIMax="0.10"))
    float CombatFacingUpdateInterval = 0.033f;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Digimon")
    UDMFDigimonSpeciesData* ResolveSpeciesData() const;

    /**
     * Applies the persistent defeated presentation used by both player partners and wild Digimon.
     * The species Death Montage plays once and, by default, freezes near its final pose until the
     * Digimon is revived or the actor is recalled/destroyed. Safe to call repeatedly.
     */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Defeat Presentation")
    void ApplyDefeatedPresentation();

    /** Clears the persistent defeated presentation after an authoritative revive/reset. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Defeat Presentation")
    void ClearDefeatedPresentation();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Defeat Presentation")
    bool IsDefeatedPresentationActive() const { return bDefeatedPresentationActive; }

    /**
     * Legacy compatibility setting retained for existing Blueprints. Defeated-pose holding is now a
     * framework invariant in v0.5.5+: a valid Death Montage is always locked before blend-out can
     * return the mesh to locomotion.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Digimon MMO|Defeat Presentation")
    bool bHoldDefeatedPoseUntilRevivedOrDismissed = true;

    /**
     * Failsafe normalized hold point used only if a Montage never reaches its normal blend-out callback
     * (for example, an unusual looping Montage). Normal death Montages lock at blend-out start.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Defeat Presentation", meta=(ClampMin="0.50", ClampMax="0.999", UIMin="0.50", UIMax="0.999"))
    float DefeatedPoseHoldNormalizedTime = 0.97f;

    /** Playback rate used for the species Death Montage. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Defeat Presentation", meta=(ClampMin="0.05", UIMin="0.05"))
    float DefeatedMontagePlayRate = 1.0f;

    /** Stops CharacterMovement while defeated. The previous movement mode is restored on revive. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Defeat Presentation")
    bool bDisableMovementWhenDefeated = true;

    /** Makes a defeated Digimon non-blocking while its body remains visible in the world. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Defeat Presentation")
    bool bDisableCapsuleCollisionWhenDefeated = true;

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Defeat Presentation")
    void BP_OnDefeatedPresentationStarted();

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Defeat Presentation")
    void BP_OnDefeatedPresentationCleared();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Combat")
    TObjectPtr<UDMFDigimonCombatComponent> CombatComponent;

    UPROPERTY(ReplicatedUsing=OnRep_DigimonState, BlueprintReadOnly, Category="Digimon")
    FGuid DigimonInstanceId;

    UPROPERTY(ReplicatedUsing=OnRep_DigimonState, BlueprintReadOnly, Category="Digimon")
    FPrimaryAssetId SpeciesId;

    UPROPERTY(ReplicatedUsing=OnRep_DigimonState, BlueprintReadOnly, Category="Digimon")
    FDMFDigimonStats ReplicatedStats;

    UPROPERTY(ReplicatedUsing=OnRep_DigimonState, BlueprintReadOnly, Category="Digimon|Abilities")
    TArray<FName> ReplicatedAbilityIds;

    UPROPERTY(Replicated, BlueprintReadOnly, Category="Digimon")
    TObjectPtr<ADMFPlayerState> OwningPlayerState;

    UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Combat")
    FName CombatTeamId = TEXT("Wild");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Combat")
    bool bCombatTargetable = true;

    /**
     * Reasserts the framework cel-shading contract on every mesh component owned by this Digimon.
     * Render CustomDepth Pass is always forced on for owned, wild, NPC and ranked Digimon actors.
     */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Rendering|Cel Shading")
    void RefreshFrameworkCustomDepth();

    /** Stencil value written by all Digimon mesh components while Custom Depth rendering is enabled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Rendering|Cel Shading", meta=(ClampMin="0", ClampMax="255"))
    int32 CustomDepthStencilValue = 0;

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Digimon")
    void BP_OnDigimonStateReady();


protected:
    UFUNCTION()
    void OnRep_DigimonState();

    void HoldDefeatedPose();
    void LockDefeatedPose();
    void HandleDeathMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);
    void HandleDeathMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    void UpdateCombatFacing();
    void RestoreMovementRotationPolicyAfterCombatFacing();

    bool bDefeatedPresentationActive = false;
    bool bDefeatedPoseLocked = false;
    bool bDefeatedPresentationStateCached = false;
    TEnumAsByte<ECollisionEnabled::Type> CachedCapsuleCollisionEnabled = ECollisionEnabled::QueryAndPhysics;
    TEnumAsByte<EMovementMode> CachedMovementMode = MOVE_Walking;
    uint8 CachedCustomMovementMode = 0;
    bool bCachedMeshPauseAnims = false;
    float CachedMeshGlobalAnimRateScale = 1.0f;
    UPROPERTY(Transient)
    TObjectPtr<UAnimMontage> ActiveDeathMontage = nullptr;
    FTimerHandle DefeatedPoseHoldTimer;

    TWeakObjectPtr<AActor> CombatFacingTarget;
    FTimerHandle CombatFacingTimer;
    bool bCombatFacingRotationPolicyCached = false;
    bool bCachedOrientRotationToMovement = true;
    bool bCachedUseControllerDesiredRotation = false;
    bool bCachedUseControllerRotationYaw = false;
};
