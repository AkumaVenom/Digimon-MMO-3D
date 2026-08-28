#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMFTypes.h"
#include "DMFDayNightSky.generated.h"

class UDirectionalLightComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USceneComponent;
class USkyLightComponent;
class USkyAtmosphereComponent;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture2D;

#if WITH_EDITOR
struct FPropertyChangedEvent;
#endif

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFDayNightPhaseChanged, EDMFDayNightPhase, NewPhase, EDMFDayNightPhase, PreviousPhase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFDayNightTimeSynchronized, float, TimeOfDayHours, int32, DayIndex, EDMFDayNightTimeSource, TimeSource);

/**
 * Replicated, persistent, Blueprint-derivable MMO world clock and sky presentation actor.
 *
 * Authority owns the clock. Clients receive sparse time anchors and interpolate locally for smooth sky motion;
 * no per-frame time RPCs are used. HostSystemTime reads only the authority machine's local PC clock, while
 * Simulated mode advances an accelerated persistent game clock. The native visual components are optional:
 * projects may use them directly or derive a Blueprint and drive their own sky from the exposed runtime values/events.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFDayNightSky : public AActor
{
    GENERATED_BODY()

public:
    ADMFDayNightSky();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Components")
    TObjectPtr<USceneComponent> SceneRoot;

    /** Optional native sun. Derived Blueprints may hide/replace this and use the replicated time values instead. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Components")
    TObjectPtr<UDirectionalLightComponent> SunLightComponent;

    /** Optional native moon light kept exactly opposite the sun. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Components")
    TObjectPtr<UDirectionalLightComponent> MoonLightComponent;

    /** Optional native skylight. Expensive recapture is intentionally not performed every update. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Components")
    TObjectPtr<USkyLightComponent> SkyLightComponent;

    /** Optional native SkyAtmosphere component. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Components")
    TObjectPtr<USkyAtmosphereComponent> SkyAtmosphereComponent;

    /** Optional project-supplied outer sky dome mesh/material. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Components")
    TObjectPtr<UStaticMeshComponent> SkyDomeComponent;

    /**
     * Dedicated always-visible inner digital texture layer. Use a translucent/unlit two-sided material whose
     * texture parameter consumes alpha; the layer stays enabled during both Day and Night so the real sky remains
     * visible behind transparent texels.
     */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Components")
    TObjectPtr<UStaticMeshComponent> DigitalInnerSkyLayerComponent;

    // ---- Time source / clock ---------------------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Time")
    EDMFDayNightTimeSource TimeSource = EDMFDayNightTimeSource::Simulated;

    /** Initial simulated time only when no saved state exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Time", meta=(EditCondition="TimeSource==EDMFDayNightTimeSource::Simulated", ClampMin="0.0", ClampMax="23.999"))
    float InitialSimulatedTimeHours = 8.0f;

    /** Real seconds required for one complete simulated 24-hour day. 2880 seconds = a 48-minute GTA-style day. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Time", meta=(EditCondition="TimeSource==EDMFDayNightTimeSource::Simulated", ClampMin="10.0", Units="s"))
    float SimulatedDayLengthSeconds = 2880.0f;

    /** Inclusive start of Day. Supports wrap-around schedules when DayStartHour > NightStartHour. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Phase", meta=(ClampMin="0.0", ClampMax="23.999"))
    float DayStartHour = 6.0f;

    /** Exclusive end of Day / start of Night. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Phase", meta=(ClampMin="0.0", ClampMax="23.999"))
    float NightStartHour = 18.0f;

    /** Sparse authoritative time-anchor replication interval. Clients interpolate smoothly between anchors. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Networking", meta=(ClampMin="0.25", ClampMax="30.0", Units="s"))
    float TimeReplicationIntervalSeconds = 2.0f;

    /** Local-only sky presentation update interval. 0.05 = 20 Hz and is normally more than enough for slow celestial motion. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Performance", meta=(ClampMin="0.016", ClampMax="1.0", Units="s"))
    float VisualUpdateIntervalSeconds = 0.05f;

    /**
     * Updates the native sky presentation while editing the map/Blueprint, without requiring PIE.
     * Simulated mode previews InitialSimulatedTimeHours; Host PC mode previews the editor machine's local clock.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Editor Preview")
    bool bPreviewSkyInEditor = true;

    // ---- Persistence ----------------------------------------------------------------------

    /** Stable identifier combined with the gameplay map name in the server world-state save. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Persistence")
    FName PersistenceId = TEXT("WorldSky");

    /** Simulated time resumes from its server-saved clock after restart/map reload. Host PC time always follows the authority PC clock. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Persistence")
    bool bSaveAndLoadSimulatedTime = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Persistence", meta=(EditCondition="bSaveAndLoadSimulatedTime", ClampMin="5.0", Units="s"))
    float PersistenceAutosaveIntervalSeconds = 30.0f;

    // ---- Native lighting -----------------------------------------------------------------

    /** Disable when a derived Blueprint/project supplies its own SkyAtmosphere component. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting")
    bool bEnableNativeSkyAtmosphere = true;

    /** Disable when a project supplies its own skylight/capture solution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting")
    bool bEnableNativeSkyLight = true;

    /** Recaptures the optional native SkyLight only when Day/Night phase changes (plus editor preview refresh), never every visual tick. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting", meta=(EditCondition="bEnableNativeSkyLight"))
    bool bRecaptureNativeSkyLightOnPhaseChange = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting")
    bool bDriveNativeDirectionalLights = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting", meta=(EditCondition="bDriveNativeDirectionalLights"))
    float SunYawDegrees = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting", meta=(EditCondition="bDriveNativeDirectionalLights"))
    float SunPitchOffsetDegrees = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting", meta=(EditCondition="bDriveNativeDirectionalLights", ClampMin="0.0"))
    float MaximumSunIntensity = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting", meta=(EditCondition="bDriveNativeDirectionalLights", ClampMin="0.0"))
    float MaximumMoonIntensity = 0.25f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting", meta=(EditCondition="bDriveNativeDirectionalLights"))
    FLinearColor SunLightColor = FLinearColor(1.0f, 0.92f, 0.78f, 1.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Lighting", meta=(EditCondition="bDriveNativeDirectionalLights"))
    FLinearColor MoonLightColor = FLinearColor(0.42f, 0.55f, 1.0f, 1.0f);

    // ---- Sky dome / digital inner layer --------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Sky Dome")
    TObjectPtr<UStaticMesh> SkyDomeMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Sky Dome")
    TObjectPtr<UMaterialInterface> SkyDomeMaterial;

    /** Scale for a conventional engine sphere. Projects using a pre-scaled sky mesh may set this to 1. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Sky Dome")
    FVector SkyDomeScale = FVector(10000.0f);

    /** Master gate for the persistent alpha-blended digital layer. It never toggles just because Day/Night changes. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer")
    bool bEnableDigitalInnerLayer = true;

    /** Optional dedicated mesh. When unset, SkyDomeMesh is reused. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer", meta=(EditCondition="bEnableDigitalInnerLayer"))
    TObjectPtr<UStaticMesh> DigitalInnerLayerMesh;

    /** Translucent/unlit two-sided material recommended. Texture alpha should feed material Opacity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer", meta=(EditCondition="bEnableDigitalInnerLayer"))
    TObjectPtr<UMaterialInterface> DigitalInnerLayerMaterial;

    /** Digital texture supplied to DigitalInnerLayerTextureParameterName at runtime. Alpha remains authored by the texture/material. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer", meta=(EditCondition="bEnableDigitalInnerLayer"))
    TObjectPtr<UTexture2D> DigitalInnerLayerTexture;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer", meta=(EditCondition="bEnableDigitalInnerLayer", ClampMin="0.0", ClampMax="1.0"))
    float DigitalInnerLayerOpacity = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer", meta=(EditCondition="bEnableDigitalInnerLayer"))
    FLinearColor DigitalInnerLayerTint = FLinearColor::White;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer", meta=(EditCondition="bEnableDigitalInnerLayer"))
    FVector2D DigitalInnerLayerUVScale = FVector2D(1.0f, 1.0f);

    /** UV units per real second. Zero leaves the texture fixed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer", meta=(EditCondition="bEnableDigitalInnerLayer"))
    FVector2D DigitalInnerLayerPanSpeed = FVector2D::ZeroVector;

    /** Slightly smaller than the outer dome to avoid z-fighting and place this texture visually in front of it from inside the sphere. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer", meta=(EditCondition="bEnableDigitalInnerLayer", ClampMin="0.01", ClampMax="1.0"))
    float DigitalInnerLayerScaleMultiplier = 0.995f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer|Material Parameters", meta=(EditCondition="bEnableDigitalInnerLayer"))
    FName DigitalInnerLayerTextureParameterName = TEXT("DMF_InnerLayerTexture");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer|Material Parameters", meta=(EditCondition="bEnableDigitalInnerLayer"))
    FName DigitalInnerLayerOpacityParameterName = TEXT("DMF_InnerLayerOpacity");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer|Material Parameters", meta=(EditCondition="bEnableDigitalInnerLayer"))
    FName DigitalInnerLayerTintParameterName = TEXT("DMF_InnerLayerTint");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer|Material Parameters", meta=(EditCondition="bEnableDigitalInnerLayer"))
    FName DigitalInnerLayerUVScaleParameterName = TEXT("DMF_InnerLayerUVScale");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Digital Inner Layer|Material Parameters", meta=(EditCondition="bEnableDigitalInnerLayer"))
    FName DigitalInnerLayerUVOffsetParameterName = TEXT("DMF_InnerLayerUVOffset");

    /** Shared optional material parameter names pushed to outer and inner dynamic materials. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Sky Dome|Material Parameters")
    FName TimeOfDayNormalizedParameterName = TEXT("DMF_TimeOfDayNormalized");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Sky Dome|Material Parameters")
    FName DayVisualAlphaParameterName = TEXT("DMF_DayVisualAlpha");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Sky Dome|Material Parameters")
    FName SunDirectionParameterName = TEXT("DMF_SunDirection");

    /**
     * Compatibility bridge for conventional Unreal sky-sphere materials whose visible solar disc is authored
     * from legacy Light direction / Sun height parameters instead of the framework DMF_* contract. Keeping this
     * enabled makes the painted/material sun follow the exact same solar path as the native Directional Light.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Sky Dome|Solar Visual Compatibility")
    bool bDriveSkyDomeSolarVisualParameters = true;

    /**
     * Vector parameter used by many Unreal sky-sphere materials for the visible solar-disc direction. The value
     * supplied is the Directional Light ray-travel/forward vector (sun -> world), matching the conventional sky-sphere contract.
     * Set to None when the assigned material does not use this compatibility parameter.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Sky Dome|Solar Visual Compatibility", meta=(EditCondition="bDriveSkyDomeSolarVisualParameters"))
    FName SkyDomeLightDirectionParameterName = TEXT("Light direction");

    /**
     * Scalar parameter used by many Unreal sky-sphere materials for solar elevation. -1 = below at midnight,
     * 0 = horizon, +1 = overhead at noon. Set to None when the assigned material does not use this parameter.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Day Night|Sky Dome|Solar Visual Compatibility", meta=(EditCondition="bDriveSkyDomeSolarVisualParameters"))
    FName SkyDomeSunHeightParameterName = TEXT("Sun height");

    // ---- Replicated/runtime values ---------------------------------------------------------

    /** Last server-authored time anchor. Use GetTimeOfDayHours for smooth interpolated time between network anchors. */
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Digimon MMO|Day Night|Runtime")
    float ReplicatedTimeOfDayHours = 8.0f;

    UPROPERTY(Replicated, BlueprintReadOnly, Category="Digimon MMO|Day Night|Runtime")
    int32 ReplicatedDayIndex = 0;

    UPROPERTY(Replicated, BlueprintReadOnly, Category="Digimon MMO|Day Night|Runtime")
    EDMFDayNightTimeSource ReplicatedTimeSource = EDMFDayNightTimeSource::Simulated;

    /** Server-world-time timestamp paired with ReplicatedTimeOfDayHours. */
    UPROPERTY(ReplicatedUsing=OnRep_TimeAnchor, BlueprintReadOnly, Category="Digimon MMO|Day Night|Runtime")
    double ReplicatedTimeAnchorServerSeconds = 0.0;

    /** Replicated so a runtime server-side simulated-day-length change still interpolates correctly on clients. */
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Digimon MMO|Day Night|Runtime")
    float ReplicatedSimulatedDayLengthSeconds = 2880.0f;

    UPROPERTY(ReplicatedUsing=OnRep_DayNightPhase, BlueprintReadOnly, Category="Digimon MMO|Day Night|Runtime")
    EDMFDayNightPhase DayNightPhase = EDMFDayNightPhase::Day;

    /** Convenience values derived from replicated DayNightPhase and exposed directly for Blueprint branching/binding. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Runtime")
    bool bIsDay = true;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Day Night|Runtime")
    bool bIsNight = false;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Day Night|Events")
    FDMFDayNightPhaseChanged OnDayNightPhaseChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Day Night|Events")
    FDMFDayNightTimeSynchronized OnTimeSynchronized;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Day Night")
    float GetTimeOfDayHours() const;

    /** Canonical smooth 12-hour world-clock text derived from the replicated/interpolated sky time (for example 9:42 PM). */
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Day Night|Presentation")
    FText GetFormattedTime12Hour(bool bIncludeSeconds = false) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Day Night")
    float GetTimeOfDayNormalized() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Day Night")
    int32 GetCurrentDayIndex() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Day Night")
    EDMFDayNightPhase GetDayNightPhase() const { return DayNightPhase; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Day Night")
    bool IsDay() const { return bIsDay; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Day Night")
    bool IsNight() const { return bIsNight; }

    /** Runtime server-only mode switch. HostSystemTime immediately snaps to the authority PC clock. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Day Night|Authority")
    void SetAuthoritativeTimeSource(EDMFDayNightTimeSource NewTimeSource, bool bSaveImmediately = true);

    /** Sets the persistent simulated clock. Does nothing while HostSystemTime is active. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Day Night|Authority")
    void SetSimulatedTimeOfDay(float NewTimeOfDayHours, int32 NewDayIndex = 0, bool bSaveImmediately = true);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Day Night|Authority")
    void AdvanceSimulatedTimeByHours(float DeltaHours, bool bSaveImmediately = true);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Day Night|Persistence")
    bool SaveDayNightStateNow();

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Day Night|Persistence")
    bool ReloadDayNightState();

    /** Rebuilds dynamic materials and reapplies the current texture/material parameters. Safe after Blueprint runtime asset changes. Also exposed as an editor button. */
    UFUNCTION(BlueprintCallable, CallInEditor, Category="Digimon MMO|Day Night|Presentation")
    void RefreshSkyPresentation();

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Day Night|Presentation")
    void BP_OnDayNightPhaseChanged(EDMFDayNightPhase NewPhase, EDMFDayNightPhase PreviousPhase);

    /** Local presentation callback at VisualUpdateIntervalSeconds; contains interpolated replicated time only, never authority. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Day Night|Presentation")
    void BP_OnSkyVisualUpdate(float TimeOfDayHours, float TimeOfDayNormalized, float DayVisualAlpha);

protected:
    UFUNCTION()
    void OnRep_TimeAnchor();

    UFUNCTION()
    void OnRep_DayNightPhase(EDMFDayNightPhase PreviousPhase);

private:
    FTimerHandle AuthoritySyncTimer;
    FTimerHandle PersistenceTimer;
    double AuthorityAnchorServerSeconds = 0.0;
    float AuthorityAnchorTimeHours = 8.0f;
    int32 AuthorityAnchorDayIndex = 0;
    bool bPendingNativeSkyLightRecapture = false;

    UPROPERTY(Transient)
    TObjectPtr<UMaterialInstanceDynamic> SkyDomeMID;

    UPROPERTY(Transient)
    TObjectPtr<UMaterialInstanceDynamic> DigitalInnerLayerMID;

    void SynchronizeAuthorityTime(bool bForceNetUpdate);
    void CalculateAuthorityTime(float& OutTimeHours, int32& OutDayIndex) const;
    double GetSynchronizedServerWorldSeconds() const;
    bool EvaluateIsDay(float TimeHours) const;
    void ApplyPhase(EDMFDayNightPhase NewPhase, bool bBroadcast);
    void ApplySkyVisuals(float TimeHours, bool bCallBlueprintPresentationEvent = true);
    float CalculateDayVisualAlpha(float TimeHours) const;
    float ResolvePresentationTimeHours() const;
    bool IsEditorPreviewWorld() const;
    FString BuildPersistenceKey() const;
    bool LoadPersistedSimulatedTime();
    void ResetAuthorityAnchor(float TimeHours, int32 DayIndex);
    void HandleAuthoritySyncTimer();
    void HandlePersistenceTimer();
    static float WrapHours(float Hours);
};
