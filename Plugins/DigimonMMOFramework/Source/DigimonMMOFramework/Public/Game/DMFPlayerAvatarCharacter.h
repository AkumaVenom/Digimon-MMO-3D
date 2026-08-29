#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DMFTypes.h"
#include "Game/DMFSwimmableWater.h"
#include "DMFPlayerAvatarCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UPostProcessComponent;
class UExponentialHeightFogComponent;
class UWidgetComponent;
class UDMFPlayerSkinData;
class ADMFDigimonCharacter;
class ADMFMMOPlayerController;
class AActor;
class USoundBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FDMFPlayerInteractionResult, bool, bSuccess, AActor*, TargetActor, EDMFPlayerInteractionType, InteractionType, FText, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFPlayerSwimmingStateChanged, bool, bSwimming, bool, bUnderwater, ADMFSwimmableWater*, WaterBody);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFPlayerUnderwaterStateChanged, bool, bUnderwater);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFLocalCameraUnderwaterChanged, bool, bCameraUnderwater, ADMFSwimmableWater*, WaterBody);

/**
 * Ready-to-use replicated third-person player character for Digimon MMO Framework.
 *
 * Derive a Blueprint from this class, then customize movement/camera/animation as desired.
 * Player appearance is supplied by UDMFPlayerSkinData rather than swapping authoritative pawn classes.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFPlayerAvatarCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ADMFPlayerAvatarCharacter();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    virtual void PossessedBy(AController* NewController) override;
    virtual void OnRep_PlayerState() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Player Avatar|Camera")
    TObjectPtr<USpringArmComponent> CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Player Avatar|Camera")
    TObjectPtr<UCameraComponent> FollowCamera;

    /**
     * Dedicated local-only underwater presentation component. It is unbound so it affects only this viewport when
     * enabled, and framework code keeps every non-local avatar's copy disabled to avoid cross-player contamination.
     */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Player Avatar|Swimming|Underwater Post Process")
    TObjectPtr<UPostProcessComponent> UnderwaterPostProcessComponent;

    /**
     * Local-only exponential underwater fog used for real scene-distance visibility falloff. Remote avatar copies
     * keep this disabled; the owning camera alone drives density from the active water body's replicated profile.
     */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Player Avatar|Swimming|Underwater Post Process")
    TObjectPtr<UExponentialHeightFogComponent> UnderwaterDistanceFogComponent;

    /** Automatic client-side MMO username plate. It reads the replicated APlayerState display name and adds no custom RPC traffic. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|UI|World Nameplates")
    TObjectPtr<UWidgetComponent> NameplateWidgetComponent;

    /** Re-applies global nameplate enablement, widget class, height and cull distance. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI|World Nameplates")
    void RefreshWorldNameplate();

    /** Disable this in a Blueprint child when the project supplies its own Enhanced Input stack. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Input")
    bool bEnableNativeThirdPersonInput = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Movement", meta=(ClampMin="0.0"))
    float WalkSpeed = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Movement", meta=(ClampMin="0.0"))
    float SprintSpeed = 750.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Camera", meta=(ClampMin="0.0"))
    float MouseYawScale = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Camera", meta=(ClampMin="0.0"))
    float MousePitchScale = 1.0f;

    /**
     * Ready-to-use E-key interaction. Disable this when the project uses Enhanced Input, then call Interact() directly.
     * This setting is independent of bEnableNativeThirdPersonInput.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Interaction|Input")
    bool bEnableNativeInteractionInput = true;

    /** Maximum local trace distance used by Interact()/FindInteractionTarget(). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Interaction|Trace", meta=(ClampMin="1.0"))
    float InteractionDistance = 1200.0f;

    /** Sphere-sweep radius. Set to 0 for a strict line trace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Interaction|Trace", meta=(ClampMin="0.0"))
    float InteractionSweepRadius = 30.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Interaction|Trace")
    TEnumAsByte<ECollisionChannel> InteractionTraceChannel = ECC_Visibility;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Interaction|Trace")
    bool bInteractionTraceComplex = false;

    /** Prevent the player's own summoned partner from consuming the interaction trace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Interaction|Trace")
    bool bIgnoreActivePartnerDuringInteractionTrace = true;

    /** Development-only visualization of the local interaction trace/sweep. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Interaction|Debug")
    bool bDrawDebugInteractionTrace = false;

    /**
     * Default Digimon interaction is target-only. Enable this only if one interaction press should also execute an ability.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Interaction|Digimon")
    bool bAttackOnDigimonInteract = false;

    /** Zero-based quick slot used when bAttackOnDigimonInteract is enabled (0 = UI slot 1). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Interaction|Digimon", meta=(ClampMin="0", ClampMax="3"))
    int32 DigimonInteractAttackSlotIndex = 0;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Movement")
    void MoveForward(float Value);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Movement")
    void MoveRight(float Value);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Camera")
    void LookYaw(float Value);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Camera")
    void LookPitch(float Value);

    /** Adds local third-person camera zoom input. Positive values zoom in; negative values zoom out. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Camera|Zoom")
    void AddCameraZoomInput(float Value);

    /** Requests an absolute local boom distance, clamped to the global Project Settings min/max range. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Camera|Zoom")
    void SetCameraZoomDistance(float NewDistance, bool bInstant = false);

    /** Returns the locally requested boom distance (not the temporary collision-compressed spring-arm result). */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|Camera|Zoom")
    float GetCameraZoomDistance() const { return DesiredCameraBoomLength; }

    /** Restores the globally configured default camera boom distance. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Camera|Zoom")
    void ResetCameraZoom(bool bInstant = false);

    /** Reasserts the global rule that player collision must not block the spring-arm camera channel. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Camera|Collision")
    void RefreshCameraCollisionPolicy();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Movement")
    void StartSprinting();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Movement")
    void StopSprinting();

    /** Clears held native WASD/sprint state before modal UI takes input focus. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Input")
    void ResetNativeInputState();

    /**
     * Plays one local footstep presentation using the globally configured player footstep sound.
     * Normal gameplay uses the automatic distance-based replicated cadence; this helper exists for project-specific presentation hooks.
     */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Footsteps")
    void PlayPlayerFootstepLocal();

    /**
     * One-call project interaction entry point. Traces from the local player view and automatically:
     * - targets hostile Digimon (or target+attacks when configured),
     * - uses DMFHealerActor,
     * - reports unsupported actors to Blueprint without requiring casts.
     */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction")
    bool Interact();

    /** Same dispatch as Interact(), but for an actor already found by project UI/overlap/trace logic. No cast is required in Blueprint. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction")
    bool InteractWithActor(AActor* TargetActor);

    /** Accepts any Actor reference and internally validates/casts it as a Digimon before selecting it. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction|Digimon")
    bool TargetDigimonFromActor(AActor* TargetActor);

    /** Discoverable no-cast alias for target-only Digimon interaction. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction|Digimon")
    bool InteractWithDigimon(AActor* DigimonActor);

    /** Accepts any Actor reference and atomically targets + commands the selected quick slot. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction|Digimon")
    bool TargetAndAttackDigimonFromActor(AActor* TargetActor, int32 SlotIndex = 0);

    /** Discoverable no-cast alias for Digimon interaction that also sends an attack command. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction|Digimon")
    bool InteractWithDigimonAndAttack(AActor* DigimonActor, int32 SlotIndex = 0);

    /** Uses a healer from a generic Actor reference; no Blueprint cast is required. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction|Healer")
    bool InteractWithHealer(AActor* HealerActor);

    /** Opens a nearby Digimon vendor from a generic Actor reference; no Blueprint cast is required. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction|Vendor")
    bool InteractWithDigimonVendor(AActor* VendorActor);

    /** Clears the current partner command target without requiring PlayerController/PlayerState casts. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction|Digimon")
    void ClearDigimonTarget();

    /** Executes/queues an active-partner ability against the already selected target. Zero-based: 0 = slot 1. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction|Digimon")
    void CommandDigimonAbilitySlot(int32 SlotIndex);

    /** Performs only the local trace/sweep and returns the best hit actor; it does not interact. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Interaction|Trace")
    AActor* FindInteractionTarget(FHitResult& OutHit) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Interaction")
    AActor* GetLastInteractionActor() const { return LastInteractionActor; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Interaction|Digimon")
    ADMFDigimonCharacter* GetCurrentDigimonTarget() const;

    /** Native prompt helper for framework actors; custom/unhandled actors return empty text. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Interaction")
    FText GetInteractionPromptForActor(AActor* TargetActor) const;

    /** Single Blueprint event/delegate source for UI feedback, tutorials and interaction presentation. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Interaction")
    FDMFPlayerInteractionResult OnInteractionResult;

    /** Fires for every Digimon interaction attempt; the Digimon reference is already typed for Blueprint. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Interaction|Digimon")
    void BP_OnDigimonInteracted(ADMFDigimonCharacter* Digimon, bool bTargeted, bool bAttackCommandSent);

    /** Extension point for project-specific actors not natively handled by the framework. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Interaction")
    void BP_OnUnhandledInteraction(AActor* TargetActor);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|Movement")
    bool IsSprinting() const { return bIsSprinting; }

    // ---- Replicated swimming -------------------------------------------------------------

    /** True when the authoritative/predicted avatar is currently inside a DMFSwimmableWater body. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|Swimming")
    bool IsSwimmingInWater() const;

    /** True once the avatar has crossed the active water body's underwater depth threshold. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|Swimming")
    bool IsSwimmingUnderwater() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|Swimming")
    ADMFSwimmableWater* GetActiveSwimmableWater() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|Swimming")
    EDMFPlayerSwimState GetPlayerSwimState() const;

    /** Adds explicit vertical swim input. Positive ascends, negative descends. Useful for Enhanced Input projects. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Swimming|Input")
    void AddSwimVerticalInput(float Value);

    /**
     * Water-volume integration point used by DMFSwimmableWater. Custom Blueprint water implementations may call
     * this on overlap too; clients only gain local prediction while authority still owns the replicated state.
     */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Swimming")
    void RegisterSwimmableWaterOverlap(ADMFSwimmableWater* WaterBody, bool bEntered);

    /**
     * Rebuilds water occupancy from the avatar's current world transform instead of relying on BeginOverlap timing.
     * Use this after server-authoritative teleports/load restores into or out of water. Authority rebuilds replicated
     * water state; the owning client may also use it for safe local prediction. Optional movement reset prevents a
     * restored underwater avatar from carrying a stale Falling velocity before swimming physics is re-established.
     */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Swimming")
    void RebuildSwimmingStateFromWorld(bool bStopMovementIfSwimming = false);

    /** Re-applies the current no-animation swim fallback pose immediately. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Swimming|Presentation")
    void RefreshSwimmingPresentation();

    /** True only for the locally controlled player's camera while it is physically below the active water surface. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|Swimming|Underwater Post Process")
    bool IsLocalCameraUnderwater() const { return bLocalCameraUnderwater; }

    /** Current local blend weight (0-1) of the water body's underwater post-process profile. */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|Swimming|Underwater Post Process")
    float GetUnderwaterPostProcessBlendWeight() const { return UnderwaterPostProcessBlendWeight; }

    /** Rebuilds the local camera profile from the current water body without changing replicated swimming state. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Swimming|Underwater Post Process")
    void RefreshUnderwaterPostProcessPresentation();

    /** Keeps the collision capsule upright while rotating only the skeletal mesh into a horizontal swim fallback. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Swimming|Presentation")
    bool bUseNativeSwimFallbackPose = true;

    /** Actor-space rotation added to the normal skin-relative mesh transform while swimming. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Swimming|Presentation", meta=(EditCondition="bUseNativeSwimFallbackPose"))
    FRotator SwimFallbackMeshRotationOffset = FRotator(-90.0f, 0.0f, 0.0f);

    /** Optional skin-specific positional correction applied while the native fallback pose is active. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Swimming|Presentation", meta=(EditCondition="bUseNativeSwimFallbackPose"))
    FVector SwimFallbackMeshLocationOffset = FVector::ZeroVector;

    /** Smooth local transition speed into/out of the fallback swim pose. Set to zero for instant changes. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Swimming|Presentation", meta=(EditCondition="bUseNativeSwimFallbackPose", ClampMin="0.0", ClampMax="100.0"))
    float SwimFallbackPoseInterpolationSpeed = 10.0f;

    /** Underwater only: visually pitches the flattened mesh with vertical travel while leaving the capsule upright. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Swimming|Presentation", meta=(EditCondition="bUseNativeSwimFallbackPose"))
    bool bPitchSwimFallbackWithTravelDirection = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Player Avatar|Swimming|Presentation", meta=(EditCondition="bUseNativeSwimFallbackPose && bPitchSwimFallbackWithTravelDirection", ClampMin="0.0", ClampMax="89.0"))
    float MaximumSwimFallbackTravelPitch = 45.0f;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Player Avatar|Swimming|Events")
    FDMFPlayerSwimmingStateChanged OnSwimmingStateChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Player Avatar|Swimming|Events")
    FDMFPlayerUnderwaterStateChanged OnUnderwaterStateChanged;

    /** Local presentation event; never replicated and never used as gameplay authority. */
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Player Avatar|Swimming|Underwater Post Process|Events")
    FDMFLocalCameraUnderwaterChanged OnLocalCameraUnderwaterChanged;

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Player Avatar|Swimming|Events")
    void BP_OnSwimmingStateChanged(bool bSwimming, bool bUnderwater, ADMFSwimmableWater* WaterBody);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Player Avatar|Swimming|Events")
    void BP_OnUnderwaterStateChanged(bool bUnderwater);

    /** Local-only camera waterline event for project-authored bubbles/audio/material presentation. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Player Avatar|Swimming|Underwater Post Process|Events")
    void BP_OnLocalCameraUnderwaterChanged(bool bCameraUnderwater, ADMFSwimmableWater* WaterBody);

    /** Applies presentation only. Authoritative selection must go through UDMFPlayerAvatarComponent::ServerSetPlayerSkin. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar|Skin")
    bool ApplyPlayerSkinData(UDMFPlayerSkinData* SkinData);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar|Skin")
    FPrimaryAssetId GetAppliedPlayerSkinId() const { return AppliedPlayerSkinId; }

    /**
     * Reasserts the framework cel-shading contract on every mesh component owned by this avatar.
     * Render CustomDepth Pass is always forced on; the stencil value remains Blueprint-tunable.
     */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Rendering|Cel Shading")
    void RefreshFrameworkCustomDepth();

    /** Stencil value written by all avatar mesh components while Custom Depth rendering is enabled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Rendering|Cel Shading", meta=(ClampMin="0", ClampMax="255"))
    int32 CustomDepthStencilValue = 0;

    /** Blueprint presentation extension point called after native mesh/anim/material application. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Player Avatar|Skin")
    void BP_OnPlayerSkinApplied(UDMFPlayerSkinData* SkinData);

    /** Blueprint hook fired after the framework locates PlayerState/avatar state and requests a visual refresh. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Player Avatar|Skin")
    void BP_OnPlayerSkinRefreshRequested();

private:
    bool bForwardPressed = false;
    bool bBackwardPressed = false;
    bool bLeftPressed = false;
    bool bRightPressed = false;
    bool bSwimAscendPressed = false;
    bool bSwimDescendPressed = false;

    UPROPERTY(ReplicatedUsing=OnRep_Sprinting)
    bool bIsSprinting = false;

    UPROPERTY(ReplicatedUsing=OnRep_ActiveSwimmableWater)
    TObjectPtr<ADMFSwimmableWater> ActiveSwimmableWater;

    UPROPERTY(ReplicatedUsing=OnRep_UnderwaterSwimming)
    bool bIsUnderwaterSwimming = false;

    /**
     * Compact server-authored swim presentation state for remote observers. The owning client still predicts
     * immediately, while non-owning copies use this state without depending on water-actor reference ordering.
     * Remote mesh rotation itself is never replicated.
     */
    UPROPERTY(ReplicatedUsing=OnRep_ReplicatedSwimPresentationState)
    EDMFPlayerSwimState ReplicatedSwimPresentationState = EDMFPlayerSwimState::None;

    UPROPERTY(Transient)
    FPrimaryAssetId AppliedPlayerSkinId;


    UPROPERTY(Transient)
    TObjectPtr<AActor> LastInteractionActor;

    UPROPERTY(Transient)
    TObjectPtr<USoundBase> CachedPlayerFootstepSound;

    float PlayerFootstepDistanceAccumulator = 0.0f;
    bool bWasGeneratingPlayerFootsteps = false;

    TArray<TWeakObjectPtr<ADMFSwimmableWater>> OverlappingSwimmableWaters;
    TWeakObjectPtr<ADMFSwimmableWater> LocalPredictedSwimmableWater;
    bool bLocalWaterOverlapPredictionInitialized = false;
    bool bLocalPredictedUnderwater = false;
    bool bSwimmingMovementModeApplied = false;
    bool bSwimmingPresentationApplied = false;
    bool bLocalCameraUnderwater = false;
    float UnderwaterPostProcessBlendWeight = 0.0f;
    float AppliedUnderwaterDistanceFogDensity = 0.0f;
    bool bUnderwaterDistanceFogVisible = false;
    TWeakObjectPtr<ADMFSwimmableWater> UnderwaterPostProcessConfiguredWater;
    TWeakObjectPtr<ADMFSwimmableWater> LocalCameraUnderwaterWater;
    float LastSwimForwardInput = 0.0f;
    double LastSwimForwardInputWorldSeconds = -1000.0;
    float LastExplicitVerticalSwimInput = 0.0f;
    double LastExplicitVerticalSwimInputWorldSeconds = -1000.0;

    EMovementMode PreSwimmingMovementMode = MOVE_Walking;
    uint8 PreSwimmingCustomMovementMode = 0;
    float PreSwimmingGravityScale = 1.0f;
    float PreSwimmingMaxFlySpeed = 600.0f;
    float PreSwimmingMaxAcceleration = 2048.0f;
    float PreSwimmingBrakingDecelerationFlying = 0.0f;
    bool bPreSwimmingOrientRotationToMovement = true;
    bool bPreSwimmingUseControllerRotationYaw = false;

    FTransform BasePlayerMeshRelativeTransform = FTransform::Identity;
    bool bBasePlayerMeshRelativeTransformCaptured = false;

    float DesiredCameraBoomLength = 400.0f;
    bool bCameraZoomInitialized = false;

    void RefreshSkinFromPlayerState();
    void ApplyMovementSpeed();
    void InitializeCameraZoom();
    void UpdateCameraZoom(float DeltaSeconds);
    void UpdateAutomaticPlayerFootsteps(float DeltaSeconds);
    float ResolvePlayerFootstepStrideDistance() const;
    FVector GetPlayerFootstepAudioLocation() const;
    ADMFSwimmableWater* ResolveEffectiveSwimmableWater() const;
    ADMFSwimmableWater* SelectBestOverlappingSwimmableWater() const;
    void ReevaluateSwimmingWaterSelection();
    void ApplySwimmingMovementMode(ADMFSwimmableWater* WaterBody);
    void RestoreNonSwimmingMovementMode();
    void UpdateSwimmingState(float DeltaSeconds);
    void UpdateSwimmingPresentationInternal(float DeltaSeconds, bool bInstant = false);
    void UpdateUnderwaterPostProcessPresentation(float DeltaSeconds, bool bInstant = false);
    void ConfigureUnderwaterPostProcessFromWater(ADMFSwimmableWater* WaterBody);
    void UpdateSurfaceAssist(float DeltaSeconds, ADMFSwimmableWater* WaterBody);
    void CaptureBasePlayerMeshRelativeTransform();
    bool UsesNetworkSmoothingSwimPresentation() const;
    void ApplyNetworkSmoothingSwimPresentation(const FTransform& DesiredTransform, float DeltaSeconds, bool bInstant);
    void NotifySwimmingStateChanged();
    void SetAuthoritativeUnderwaterState(bool bNewUnderwater);
    void RefreshAuthoritativeSwimPresentationState();

    UFUNCTION(NetMulticast, Unreliable)
    void MulticastPlayPlayerFootstep();

    UFUNCTION(Server, Reliable)
    void ServerSetSprinting(bool bNewSprinting);

    UFUNCTION()
    void OnRep_Sprinting();

    UFUNCTION()
    void OnRep_ActiveSwimmableWater();

    UFUNCTION()
    void OnRep_UnderwaterSwimming();

    UFUNCTION()
    void OnRep_ReplicatedSwimPresentationState();

    void HandleForwardPressed();
    void HandleForwardReleased();
    void HandleBackwardPressed();
    void HandleBackwardReleased();
    void HandleLeftPressed();
    void HandleLeftReleased();
    void HandleRightPressed();
    void HandleRightReleased();
    void HandleJumpPressed();
    void HandleJumpReleased();
    void HandleSprintPressed();
    void HandleSprintReleased();
    void HandleCrouchPressed();
    void HandleCrouchReleased();
    void HandleInteractionPressed();
    void HandleMouseX(float Value);
    void HandleMouseY(float Value);
    void HandleCameraZoomIn();
    void HandleCameraZoomOut();
    void HandleGamepadMoveForward(float Value);
    void HandleGamepadMoveRight(float Value);
    void HandleGamepadLookYaw(float Value);
    void HandleGamepadLookPitch(float Value);

    ADMFMMOPlayerController* ResolveDMFPlayerController() const;
    void ReportInteractionResult(bool bSuccess, AActor* TargetActor, EDMFPlayerInteractionType InteractionType, const FText& Message);
};
