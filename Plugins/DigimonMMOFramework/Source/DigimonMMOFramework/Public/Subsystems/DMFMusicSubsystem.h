#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"
#include "DMFTypes.h"
#include "DMFMusicSubsystem.generated.h"

class UAudioComponent;
class USoundBase;
class UWorld;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFMusicStateChanged, EDMFMusicState, PreviousState, EDMFMusicState, NewState);

/**
 * Local presentation-only music director for the framework.
 *
 * The subsystem survives map travel with the GameInstance, automatically chooses Frontend/OpenWorld/Battle
 * music, and crossfades persistent 2D audio components. Battle truth is read from the replicated
 * active-partner CombatComponent encounter latch; no music state or audio event is replicated.
 */
UCLASS(BlueprintType)
class DIGIMONMMOFRAMEWORK_API UDMFMusicSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    virtual void Tick(float DeltaTime) override;
    virtual TStatId GetStatId() const override;
    virtual bool IsTickable() const override;
    virtual bool IsTickableWhenPaused() const override { return true; }
    virtual UWorld* GetTickableGameObjectWorld() const override;

    /** Fired locally whenever the semantic music state changes. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Audio|Music")
    FDMFMusicStateChanged OnMusicStateChanged;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Audio|Music")
    EDMFMusicState GetCurrentMusicState() const { return CurrentMusicState; }

    /** Re-evaluates the current map/combat context immediately instead of waiting for the short presentation poll. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Audio|Music")
    void RefreshMusicState();

    /**
     * Local runtime suppression intended for cinematics or project-owned temporary audio states.
     * This never edits Project Settings and never replicates to other players.
     */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Audio|Music")
    void SetMusicSuppressed(bool bSuppressed);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Audio|Music")
    bool IsMusicSuppressed() const { return bMusicSuppressed; }

private:
    UPROPERTY(Transient)
    TObjectPtr<UAudioComponent> CurrentAudioComponent;

    UPROPERTY(Transient)
    TObjectPtr<UAudioComponent> FadingAudioComponent;

    UPROPERTY(Transient)
    TObjectPtr<USoundBase> CurrentSound;

    EDMFMusicState CurrentMusicState = EDMFMusicState::None;
    float EvaluationTimeRemaining = 0.0f;
    float BattleReleaseTimeRemaining = 0.0f;
    float FadingCleanupTimeRemaining = 0.0f;
    bool bBattleCurrentlyObserved = false;
    bool bMusicSuppressed = false;
    bool bInitialized = false;

    EDMFMusicState ResolveBaseWorldState() const;
    bool IsLocalPlayerInBattle() const;
    USoundBase* ResolveSoundForState(EDMFMusicState State) const;
    float ResolveVolumeForState(EDMFMusicState State) const;
    void TransitionToState(EDMFMusicState NewState);
    void CleanupFadingComponent(bool bForce = false);
    void StopAllMusic();
    static bool DoesWorldMatchMap(const UWorld* World, const TSoftObjectPtr<UWorld>& MapAsset);
};
