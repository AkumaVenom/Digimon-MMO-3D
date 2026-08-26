#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMFHealerActor.generated.h"

class USceneComponent;
class USphereComponent;
class UPointLightComponent;
class UNiagaraComponent;
class UParticleSystemComponent;
class UAudioComponent;
class UNiagaraSystem;
class UParticleSystem;
class USoundBase;
class APlayerController;
class ADMFPlayerState;

/**
 * Server-authoritative, free Digimon healer station/NPC interaction endpoint.
 *
 * The healer owns a replicated exclusive treatment state plus an optional native presentation rig:
 * a Blueprint-positionable anchor, pulsing green point light, Niagara-preferred/Cascade-fallback VFX
 * and healing audio. Gameplay restoration remains server-authoritative and can restore the complete
 * six-Digimon Party plus every persistent Bank/Box record in a single accepted use.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFHealerActor : public AActor
{
    GENERATED_BODY()

public:
    ADMFHealerActor();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer")
    TObjectPtr<USceneComponent> SceneRoot;

    /** Native query-only interaction volume so the framework Interact() trace works without project collision setup. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer")
    TObjectPtr<USphereComponent> InteractionCollision;

    /** Presentation origin intended to be moved into the center/interior of the project's healer mesh. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation")
    TObjectPtr<USceneComponent> HealingPresentationAnchor;

    /** Native green treatment light. Its intensity is animated locally from the replicated healer state. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation")
    TObjectPtr<UPointLightComponent> HealingLight;

    /** Preferred modern VFX component. Assign Healing Niagara System below; Cascade remains an automatic fallback. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation")
    TObjectPtr<UNiagaraComponent> HealingNiagaraComponent;

    /** Legacy Cascade fallback for projects that already own a Cascade healing-plus effect. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation")
    TObjectPtr<UParticleSystemComponent> HealingCascadeComponent;

    /** Attached spatial healing audio component. A Sound Cue with attenuation is recommended. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation")
    TObjectPtr<UAudioComponent> HealingAudioComponent;

    /** Runtime master switch. Replicated so Blueprint presentation can reflect server availability. */
    UPROPERTY(ReplicatedUsing=OnRep_Enabled, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer")
    bool bEnabled = true;

    /** True while this station is exclusively presenting one accepted player's treatment. */
    UPROPERTY(ReplicatedUsing=OnRep_HealingPresentationState, BlueprintReadOnly, Category="Digimon MMO|Healer|Sequence")
    bool bHealingInProgress = false;

    /** Public replicated PlayerState being presented by this station; null while idle. */
    UPROPERTY(ReplicatedUsing=OnRep_HealingPresentationState, BlueprintReadOnly, Category="Digimon MMO|Healer|Sequence")
    TObjectPtr<ADMFPlayerState> ActiveHealingPlayerState;

    /** Number of Party/Bank Digimon actually restored by the active treatment. */
    UPROPERTY(ReplicatedUsing=OnRep_HealingPresentationState, BlueprintReadOnly, Category="Digimon MMO|Healer|Sequence")
    int32 ActiveHealingDigimonCount = 0;

    /** Maximum authoritative distance from player pawn to healer actor. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer", meta=(ClampMin="0.0"))
    float InteractionRadius = 350.0f;

    /** Query-only trace hit volume; intentionally separate from authoritative use distance. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Interaction", meta=(ClampMin="1.0"))
    float InteractionCollisionRadius = 100.0f;

    /** Channel blocked by the native interaction hit volume. Match the player interaction trace channel when customizing it. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Interaction")
    TEnumAsByte<ECollisionChannel> InteractionTraceChannel = ECC_Visibility;

    /** Minimum server-side reuse interval per player to prevent interaction RPC spam. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer", meta=(ClampMin="0.0"))
    float ReuseDelay = 0.5f;

    /** Visual treatment duration. One station remains exclusive to the accepted player for this period. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Sequence", meta=(ClampMin="0.1", ClampMax="30.0"))
    float HealingSequenceDuration = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bHealHP = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bHealSP = true;

    /** If true, HP restoration revives defeated owned Digimon. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bRestoreDefeatedDigimon = true;

    /** Heals every server-side Bank/Box record as well as the replicated Party. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bIncludeBankStorage = true;

    /** If the selected active partner is currently recalled/missing, summon it after a successful restore. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bSummonActivePartnerAfterHeal = true;

    /** One relative transform moves the complete light/VFX/audio rig into the interior of any healer mesh. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Placement")
    FTransform HealingPresentationRelativeTransform = FTransform(FRotator::ZeroRotator, FVector(0.0, 0.0, 110.0), FVector::OneVector);

    /** Built-in green treatment glow. Disable if the project supplies all lighting from the healer Blueprint/material. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Light")
    bool bEnableHealingLight = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Light", meta=(EditCondition="bEnableHealingLight"))
    FLinearColor HealingLightColor = FLinearColor(0.08f, 1.0f, 0.18f, 1.0f);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Light", meta=(EditCondition="bEnableHealingLight", ClampMin="0.0", ClampMax="100000.0"))
    float HealingLightIntensity = 5000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Light", meta=(EditCondition="bEnableHealingLight", ClampMin="1.0", ClampMax="10000.0"))
    float HealingLightAttenuationRadius = 450.0f;

    /** Small pulse amount gives a machine-like animated glow without requiring an animated healer mesh. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Light", meta=(EditCondition="bEnableHealingLight", ClampMin="0.0", ClampMax="1.0"))
    float HealingLightPulseAmount = 0.18f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Light", meta=(EditCondition="bEnableHealingLight", ClampMin="0.0", ClampMax="20.0"))
    float HealingLightPulseFrequencyHz = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Light", meta=(EditCondition="bEnableHealingLight", ClampMin="0.0", ClampMax="5.0"))
    float HealingLightFadeInSeconds = 0.20f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Light", meta=(EditCondition="bEnableHealingLight", ClampMin="0.0", ClampMax="5.0"))
    float HealingLightFadeOutSeconds = 0.35f;

    /** Preferred healing VFX. Author green plus sprites/meshes in Niagara and make the system loop for the sequence duration. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|VFX")
    TSoftObjectPtr<UNiagaraSystem> HealingNiagaraSystem;

    /** Cascade fallback. Used automatically when Niagara is unassigned, or first when Prefer Niagara is disabled. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|VFX")
    TSoftObjectPtr<UParticleSystem> HealingCascadeSystem;

    /** When both systems are assigned, Niagara is used by default and Cascade remains the fallback. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|VFX")
    bool bPreferNiagaraHealingVFX = true;

    /** Spatial treatment sound. A looping/randomized Sound Cue with attenuation is recommended. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Audio")
    TSoftObjectPtr<USoundBase> HealingSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Audio", meta=(ClampMin="0.0", ClampMax="4.0"))
    float HealingSoundVolumeMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Audio", meta=(ClampMin="0.25", ClampMax="4.0"))
    float HealingSoundPitchMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Presentation|Audio", meta=(ClampMin="0.0", ClampMax="5.0"))
    float HealingSoundFadeOutSeconds = 0.25f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText InteractionPrompt;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText SuccessMessage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText AlreadyHealthyMessage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText DisabledMessage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText TooFarMessage;

    /** Returned while another accepted player's treatment presentation owns this station. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText BusyMessage;

    /** Lower-level API for custom systems. Normal player setup uses ADMFPlayerAvatarCharacter::Interact. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Healer")
    void RequestHeal(APlayerController* PlayerController);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Healer")
    bool IsPlayerWithinInteractionRange(const APlayerController* PlayerController) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Healer|Sequence")
    bool IsHealing() const { return bHealingInProgress; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Healer|Sequence")
    ADMFPlayerState* GetActiveHealingPlayerState() const { return ActiveHealingPlayerState; }

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Healer")
    bool TryHealPlayerAuthoritative(APlayerController* PlayerController, UPARAM(ref) int32& OutDigimonHealed, UPARAM(ref) FText& OutMessage);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Healer")
    void SetHealerEnabled(bool bNewEnabled);

    /** Reapply anchor transform, light tuning and assigned Niagara/Cascade/Sound assets after runtime customization. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Healer|Presentation")
    void RefreshHealingPresentation();

    /** Server-side gameplay hook after an accepted use. Preserved for existing healer Blueprints. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Healer")
    void BP_OnPlayerHealed(APlayerController* PlayerController, int32 DigimonHealed);

    /** Legacy cosmetic hook preserved for existing Blueprints; still multicasts on accepted healer use. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Healer|Presentation")
    void BP_OnHealPresentation(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed);

    /** Replicated presentation hook called once when the exclusive native treatment sequence starts locally. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Healer|Presentation")
    void BP_OnHealingSequenceStarted(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed);

    /** Replicated presentation hook called once when that native treatment sequence finishes locally. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Healer|Presentation")
    void BP_OnHealingSequenceFinished(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Healer|Presentation")
    void BP_OnEnabledStateChanged(bool bIsEnabled);

private:
    TMap<TWeakObjectPtr<APlayerController>, double> LastUseServerTimeByPlayer;
    FTimerHandle HealingSequenceTimerHandle;

    bool bLocalHealingPresentationActive = false;
    float LocalHealingLightBlend = 0.0f;
    float LocalHealingPresentationElapsed = 0.0f;
    TWeakObjectPtr<ADMFPlayerState> LocalHealingPlayerState;
    int32 LocalHealingDigimonCount = 0;

    void RefreshInteractionCollision();
    void BeginHealingSequenceAuthoritative(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed);
    void EndHealingSequenceAuthoritative();
    void ApplyReplicatedHealingPresentation();
    void StartLocalHealingPresentation();
    void StopLocalHealingPresentation();
    bool ActivatePreferredHealingVFX();

    UFUNCTION()
    void OnRep_Enabled();

    UFUNCTION()
    void OnRep_HealingPresentationState();

    UFUNCTION(NetMulticast, Unreliable)
    void MulticastHealPresentation(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed);
};
