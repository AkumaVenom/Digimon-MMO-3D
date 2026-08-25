#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Game/DMFDigimonCharacter.h"
#include "DMFWildDigimonCharacter.generated.h"

class UDMFDigimonSpeciesData;

UENUM(BlueprintType)
enum class EDMFWildGroundTransitionMode : uint8
{
    None,
    Emerging,
    Despawning
};

/** Replicated timing state for synchronized rise/sink presentation without replicating cosmetic mesh movement every frame. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFWildGroundTransitionState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation")
    EDMFWildGroundTransitionMode Mode = EDMFWildGroundTransitionMode::None;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation")
    float Depth = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation")
    float Duration = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation")
    double StartServerTimeSeconds = 0.0;

    /** Incremented for every new transition so repeated transitions replicate even with identical settings. */
    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation")
    int32 Serial = 0;

    /** Snapshot avoids ordering races between the separate SpawnRarity and transition replication fields. */
    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation")
    EDMFWildSpawnRarity Rarity = EDMFWildSpawnRarity::Common;
};

/** Ready-to-place/server-spawn wild or NPC combatant using the same combat component as partners. */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFWildDigimonCharacter : public ADMFDigimonCharacter
{
    GENERATED_BODY()

public:
    ADMFWildDigimonCharacter();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild")
    TSoftObjectPtr<UDMFDigimonSpeciesData> Species;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild", meta=(ClampMin="1"))
    int32 Level = 1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild")
    FName WildCombatTeamId = TEXT("Wild");

    /**
     * Class-default autonomous combat preference. Placed wild actors use this directly. Spawner-managed
     * actors respect this unless a spawn-entry override is configured; the spawner master gate can
     * always disable autonomous combat for the whole encounter.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="Digimon MMO|Wild|AI", meta=(DisplayName="Proactive Auto Battle (Aggressive)"))
    bool bAutoBattle = false;

    /**
     * Recommended MMO default. When true, this wild Digimon remains peaceful until a hostile Digimon
     * actually damages it, then fights only that aggressor until victory, invalid target, or leash break.
     * This works even when Proactive Auto Battle is disabled.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="Digimon MMO|Wild|AI", meta=(DisplayName="Retaliate When Attacked"))
    bool bRetaliateWhenAttacked = true;

    /** Server-authoritative runtime toggle for proactive target acquisition. Retaliation is separate. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild|AI")
    void SetWildAutoBattleEnabled(bool bEnabled);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Wild|AI")
    bool IsWildAutoBattleEnabled() const { return bAutoBattle; }

    /** Server-authoritative runtime toggle for passive-until-attacked defensive behavior. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild|AI")
    void SetWildRetaliationEnabled(bool bEnabled);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Wild|AI")
    bool IsWildRetaliationEnabled() const { return bRetaliateWhenAttacked; }

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild", meta=(ClampMin="0.0"))
    float AggroRange = 1000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild", meta=(ClampMin="0.0"))
    float LeashRange = 1800.0f;

    /** Per-wild-class combat tuning. Keep at 1.0 for normal wild encounters; bosses can override in Blueprint defaults. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Balance", meta=(ClampMin="0.0"))
    float OutgoingDamageMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Balance", meta=(ClampMin="0.0"))
    float IncomingDamageMultiplier = 1.0f;

    /** Spawner-managed wild Digimon can idle-roam without escaping their individual spawn home. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Roaming")
    bool bEnableFreeRoaming = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Roaming", meta=(EditCondition="bEnableFreeRoaming", ClampMin="0.0"))
    float RoamRadius = 850.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Roaming", meta=(EditCondition="bEnableFreeRoaming", ClampMin="0.05"))
    float MinimumRoamDelay = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Roaming", meta=(EditCondition="bEnableFreeRoaming", ClampMin="0.05"))
    float MaximumRoamDelay = 5.5f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Roaming", meta=(EditCondition="bEnableFreeRoaming", ClampMin="0.0"))
    float RoamAcceptanceRadius = 75.0f;

    /** Set by DMFWildDigimonSpawner before BeginPlay. Placed wild actors can leave this false. */
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Digimon MMO|Wild|Spawner")
    bool bSpawnerManaged = false;

    /** Replicated rarity roll chosen by the authoritative spawner. */
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Digimon MMO|Wild|Spawner")
    EDMFWildSpawnRarity SpawnRarity = EDMFWildSpawnRarity::Common;

    /** Individual home point used by free roaming and the combat leash. */
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Digimon MMO|Wild|Spawner")
    FVector SpawnHomeLocation = FVector::ZeroVector;

    /** Spawner may enable this before BeginPlay to make the visual mesh rise out of the ground. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation")
    bool bStartWithGroundEmergence = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation", meta=(EditCondition="bStartWithGroundEmergence", ClampMin="0.0"))
    float GroundEmergenceDepth = 140.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation", meta=(EditCondition="bStartWithGroundEmergence", ClampMin="0.05"))
    float GroundEmergenceDuration = 1.0f;

    UPROPERTY(ReplicatedUsing=OnRep_GroundTransitionState, BlueprintReadOnly, Category="Digimon MMO|Wild|Presentation")
    FDMFWildGroundTransitionState GroundTransitionState;

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild")
    bool InitializeWildDigimon();

    /** Reconfigures the authoritative combat home to the current spawn location after deferred spawning. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild|Spawner")
    void RefreshWildHomeAndAutomation();

    /** Starts a synchronized cosmetic rise from below ground. Combat/movement stay disabled until complete. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild|Presentation")
    void BeginGroundEmergence(float Depth, float Duration);

    /** Starts a synchronized cosmetic sink and destroys this wild actor on the server when complete. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild|Presentation")
    void BeginGroundDespawn(float Depth, float Duration);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Wild|Presentation")
    bool IsGroundTransitionActive() const { return GroundTransitionState.Mode != EDMFWildGroundTransitionMode::None; }

    /** Cosmetic hooks run on every machine when replicated emergence/despawn presentation begins/updates. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Wild|Presentation")
    void BP_OnGroundTransitionStarted(EDMFWildGroundTransitionMode Mode, EDMFWildSpawnRarity Rarity);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Wild|Presentation")
    void BP_OnGroundTransitionFinished(EDMFWildGroundTransitionMode CompletedMode);

protected:
    UFUNCTION()
    void OnRep_GroundTransitionState();

private:
    FTimerHandle RoamTimer;
    FVector BaseMeshRelativeLocation = FVector::ZeroVector;
    bool bBaseMeshRelativeLocationCached = false;
    bool bCombatTargetableBeforeTransition = true;
    ECollisionEnabled::Type CapsuleCollisionBeforeTransition = ECollisionEnabled::QueryAndPhysics;
    bool bCapsuleCollisionCached = false;
    EDMFWildGroundTransitionMode LastObservedGroundTransitionMode = EDMFWildGroundTransitionMode::None;

    void ScheduleNextRoam();
    void TryBeginIdleRoam();
    void StartGroundTransition(EDMFWildGroundTransitionMode Mode, float Depth, float Duration);
    void ApplyGroundTransitionVisual();
    void FinishGroundTransitionIfAuthority();
    void CacheBaseMeshRelativeLocation();
    double GetSynchronizedServerTimeSeconds() const;
};
