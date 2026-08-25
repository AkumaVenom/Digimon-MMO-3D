#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "DMFTypes.h"
#include "DMFWildDigimonSpawner.generated.h"

class ADMFDigimonCharacter;
class ADMFWildDigimonCharacter;
class UDMFDigimonSpeciesData;
class USceneComponent;
class USphereComponent;

/** Tunable rarity weights used by one wild-Digimon spawner. Values are relative weights, not percentages. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFWildSpawnRarityWeights
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rarity", meta=(ClampMin="0.0"))
    float Common = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rarity", meta=(ClampMin="0.0"))
    float Uncommon = 35.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rarity", meta=(ClampMin="0.0"))
    float Rare = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rarity", meta=(ClampMin="0.0"))
    float Epic = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rarity", meta=(ClampMin="0.0"))
    float Legendary = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rarity", meta=(ClampMin="0.0"))
    float Mythic = 0.25f;

    float GetWeight(EDMFWildSpawnRarity Rarity) const;
};

/** One species/class candidate in a proximity wild-spawn table. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFWildSpawnEntry
{
    GENERATED_BODY()

    /** Stable designer-facing identifier used by Blueprint events and debug output. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry")
    FName EntryId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry")
    bool bEnabled = true;

    /** Species data used to initialize authoritative stats, abilities and rewards. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry")
    TSoftObjectPtr<UDMFDigimonSpeciesData> Species;

    /** Usually a BP_Wild_<Species> class derived from DMFWildDigimonCharacter with the correct mesh/AnimBP. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry")
    TSubclassOf<ADMFWildDigimonCharacter> WildCharacterClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|Rarity")
    EDMFWildSpawnRarity Rarity = EDMFWildSpawnRarity::Common;

    /** Multiplies the selected rarity tier's base weight. 0 disables selection without removing the entry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|Rarity", meta=(ClampMin="0.0"))
    float SelectionWeightMultiplier = 1.0f;

    /** 0 = unlimited within this spawner's total population. Useful for one-at-a-time rare/legendary species. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|Population", meta=(ClampMin="0"))
    int32 MaxAliveFromEntry = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|Level", meta=(ClampMin="1"))
    int32 MinimumLevel = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|Level", meta=(ClampMin="1"))
    int32 MaximumLevel = 1;

    /**
     * Optional per-entry auto-battle override. When false, the selected Wild Character Blueprint's
     * own bAutoBattle class default is respected. The spawner's Allow Proactive Auto Battle setting remains
     * a master gate and can disable autonomous combat for the entire encounter.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|AI")
    bool bOverrideAutoBattle = false;

    /** Used only when Override Auto Battle is enabled for this entry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|AI", meta=(EditCondition="bOverrideAutoBattle"))
    bool bAutoBattleOverride = false;

    /** Optional per-species emergence tuning for very small/large Digimon meshes. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|Presentation")
    bool bOverrideGroundEmergence = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|Presentation", meta=(EditCondition="bOverrideGroundEmergence", ClampMin="0.0"))
    float GroundEmergenceDepthOverride = 140.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Entry|Presentation", meta=(EditCondition="bOverrideGroundEmergence", ClampMin="0.05"))
    float GroundEmergenceDurationOverride = 1.0f;
};

/**
 * Server-authoritative, Blueprint-derivable proximity spawner for MMO wild Digimon populations.
 *
 * The server alone activates/deactivates the spawner, rolls population, rarity/species and level,
 * finds navigable ground, spawns replicated wild actors and schedules replacements after defeat.
 * Clients receive the replicated wild actors plus synchronized ground-emergence presentation.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFWildDigimonSpawner : public AActor
{
    GENERATED_BODY()

public:
    ADMFWildDigimonSpawner();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild Spawner")
    TObjectPtr<USceneComponent> SceneRoot;

    /** Editor-only style radius preview; collision is disabled and it is hidden during play. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Wild Spawner")
    TObjectPtr<USphereComponent> SpawnAreaPreview;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Activation")
    bool bSpawnerEnabled = true;

    /** At least this many player pawns must be within Activation Radius before population is created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Activation", meta=(ClampMin="1"))
    int32 MinimumNearbyPlayers = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Activation", meta=(ClampMin="0.0"))
    float ActivationRadius = 5000.0f;

    /** Hysteresis radius. Should be >= ActivationRadius so edge movement does not constantly spawn/despawn. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Activation", meta=(ClampMin="0.0"))
    float DeactivationRadius = 6500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Activation", meta=(ClampMin="0.1"))
    float ProximityCheckInterval = 1.0f;

    /** Players must remain outside Deactivation Radius for this long before the population unloads. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Activation", meta=(ClampMin="0.0"))
    float DeactivationGracePeriod = 5.0f;

    /** Uses XY distance for streaming-style proximity, avoiding cliffs/floors changing activation unexpectedly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Activation")
    bool bUse2DPlayerDistance = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Population", meta=(ClampMin="0"))
    int32 MinimumSpawnCount = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Population", meta=(ClampMin="0"))
    int32 MaximumSpawnCount = 6;

    /** Staggers initial/replacement actor creation instead of spawning a large population in one frame. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Population", meta=(ClampMin="0.05"))
    float PopulationSpawnInterval = 0.25f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Population", meta=(ClampMin="0.0"))
    float MinimumRespawnDelay = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Population", meta=(ClampMin="0.0"))
    float MaximumRespawnDelay = 15.0f;

    /** Time a defeated Digimon remains for death presentation before being destroyed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Population", meta=(ClampMin="0.0"))
    float DefeatedDespawnDelay = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Spawn Area", meta=(ClampMin="0.0"))
    float SpawnRadius = 1800.0f;

    /** Prevents a new Digimon emerging directly underneath a nearby player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Spawn Area", meta=(ClampMin="0.0"))
    float MinimumSpawnDistanceFromPlayers = 450.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Spawn Area", meta=(ClampMin="1"))
    int32 MaxPlacementAttemptsPerSpawn = 12;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Grounding", meta=(ClampMin="0.0"))
    float GroundTraceHeight = 2000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Grounding", meta=(ClampMin="0.0"))
    float GroundTraceDepth = 5000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Grounding")
    TEnumAsByte<ECollisionChannel> GroundTraceChannel = ECC_Visibility;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Grounding")
    bool bRequireNavigableSpawn = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Grounding", meta=(EditCondition="bRequireNavigableSpawn"))
    FVector NavigationProjectionExtent = FVector(250.0f, 250.0f, 500.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Grounding")
    float SpawnGroundOffset = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Emergence")
    bool bUseGroundEmergence = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Emergence", meta=(EditCondition="bUseGroundEmergence", ClampMin="0.0"))
    float GroundEmergenceDepth = 140.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Emergence", meta=(EditCondition="bUseGroundEmergence", ClampMin="0.05"))
    float GroundEmergenceDuration = 1.0f;

    /** Optional polished unload: the replicated mesh sinks before the server destroys the actor. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Emergence")
    bool bUseGroundDespawnWhenInactive = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Emergence", meta=(EditCondition="bUseGroundDespawnWhenInactive", ClampMin="0.05"))
    float GroundDespawnDuration = 0.65f;

    /**
     * Master gate for PROACTIVE autonomous combat. False means spawned wild Digimon will not scan for
     * or initiate combat with nearby Digimon. Retaliation after being attacked is controlled separately.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|AI", meta=(DisplayName="Allow Proactive Auto Battle"))
    bool bEnableAutoBattle = false;

    /**
     * Master gate for defensive retaliation. Recommended MMO default is true: wild Digimon remain
     * peaceful until attacked, then fight the aggressor within their leash.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|AI", meta=(DisplayName="Allow Retaliation When Attacked"))
    bool bEnableRetaliation = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|AI", meta=(ClampMin="0.0"))
    float AggroRange = 1000.0f;

    /** Hard combat/home leash around each Digimon's individual spawn point. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|AI", meta=(ClampMin="0.0"))
    float LeashRadius = 1800.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|AI")
    FName WildCombatTeamId = TEXT("Wild");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Roaming")
    bool bEnableFreeRoaming = true;

    /** Idle roaming stays inside this radius around the individual Digimon's spawn point. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Roaming", meta=(EditCondition="bEnableFreeRoaming", ClampMin="0.0"))
    float RoamRadius = 850.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Roaming", meta=(EditCondition="bEnableFreeRoaming", ClampMin="0.05"))
    float MinimumRoamDelay = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Roaming", meta=(EditCondition="bEnableFreeRoaming", ClampMin="0.05"))
    float MaximumRoamDelay = 5.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Roaming", meta=(EditCondition="bEnableFreeRoaming", ClampMin="0.0"))
    float RoamAcceptanceRadius = 75.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Rarity")
    FDMFWildSpawnRarityWeights RarityWeights;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Wild Spawner|Spawn Table")
    TArray<FDMFWildSpawnEntry> SpawnEntries;

    UPROPERTY(ReplicatedUsing=OnRep_SpawnerState, BlueprintReadOnly, Category="Digimon MMO|Wild Spawner|Runtime")
    bool bSpawnerActive = false;

    UPROPERTY(ReplicatedUsing=OnRep_SpawnerState, BlueprintReadOnly, Category="Digimon MMO|Wild Spawner|Runtime")
    int32 ReplicatedAliveCount = 0;

    UPROPERTY(ReplicatedUsing=OnRep_SpawnerState, BlueprintReadOnly, Category="Digimon MMO|Wild Spawner|Runtime")
    int32 ReplicatedTargetPopulation = 0;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Wild Spawner")
    bool IsSpawnerActive() const { return bSpawnerActive; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Wild Spawner")
    int32 GetAliveSpawnCount() const { return ReplicatedAliveCount; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Wild Spawner")
    int32 GetTargetPopulation() const { return ReplicatedTargetPopulation; }

    /** Re-runs proximity logic immediately on the authority. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild Spawner")
    void RefreshSpawnerNow();

    /** Forces activation/population without waiting for proximity. Useful for scripted encounters and testing. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild Spawner")
    void ForceActivateSpawner();

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild Spawner")
    void ForceDeactivateSpawner();

    /** Immediately attempts one authoritative weighted spawn if population/caps allow it. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Wild Spawner")
    ADMFWildDigimonCharacter* SpawnOneWildDigimon();

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Wild Spawner|Events")
    void BP_OnSpawnerStateChanged(bool bIsActive, int32 AliveCount, int32 TargetPopulation);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Wild Spawner|Events")
    void BP_OnWildDigimonSpawned(ADMFWildDigimonCharacter* SpawnedDigimon, FName SpawnEntryId, EDMFWildSpawnRarity Rarity);

protected:
    UFUNCTION()
    void OnRep_SpawnerState();

    UFUNCTION()
    void HandleManagedWildDestroyed(AActor* DestroyedActor);

    UFUNCTION()
    void HandleManagedWildDefeated(ADMFDigimonCharacter* DefeatedDigimon, ADMFDigimonCharacter* Killer);

private:
    struct FManagedWildRecord
    {
        TWeakObjectPtr<ADMFWildDigimonCharacter> Actor;
        int32 EntryIndex = INDEX_NONE;
        bool bDefeated = false;
        bool bPendingSpawnerDespawn = false;
        bool bSuppressRespawn = false;
    };

    TArray<FManagedWildRecord> ManagedWild;
    TArray<double> PendingRespawnReadyTimes;
    int32 PendingInitialSpawns = 0;
    double PlayersOutsideSinceTime = -1.0;
    FTimerHandle ProximityTimer;
    FTimerHandle PopulationTimer;
    bool bLastNotifiedActive = false;
    int32 LastNotifiedAliveCount = INDEX_NONE;
    int32 LastNotifiedTargetPopulation = INDEX_NONE;

    void EvaluatePlayerProximity();
    int32 CountNearbyPlayers(float Radius) const;
    bool IsSpawnLocationTooCloseToPlayer(const FVector& Location) const;
    void ActivateSpawnerInternal();
    void DeactivateSpawnerInternal();
    void SchedulePopulationProcessing(float DelaySeconds);
    void ProcessPopulationQueue();
    void QueueReplacementSpawn();
    void UpdateReplicatedRuntimeState();
    int32 CountAliveManagedWild() const;
    int32 CountAliveForEntry(int32 EntryIndex) const;
    int32 FindManagedRecordIndex(const ADMFWildDigimonCharacter* Wild) const;
    void CleanupInvalidManagedWild();
    int32 SelectWeightedSpawnEntryIndex() const;
    int32 ComputeConfiguredPopulationCapacity() const;
    bool FindSpawnTransform(int32 EntryIndex, FTransform& OutTransform) const;
    float GetSpawnCapsuleHalfHeight(int32 EntryIndex) const;
    ADMFWildDigimonCharacter* SpawnEntryAtTransform(int32 EntryIndex, const FTransform& SpawnTransform);
    double GetServerTimeSeconds() const;
};
