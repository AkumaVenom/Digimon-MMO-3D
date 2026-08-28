#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMFSwimmableWater.generated.h"

class ADMFPlayerAvatarCharacter;
class UBoxComponent;
class UMaterialInterface;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMesh;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EDMFPlayerSwimState : uint8
{
    None UMETA(DisplayName="Not Swimming"),
    Surface UMETA(DisplayName="Surface Swimming"),
    Underwater UMETA(DisplayName="Underwater Swimming")
};

/**
 * Per-water-body local underwater presentation profile. The water actor replicates this sparse configuration,
 * while only the locally controlled player's camera consumes it. No camera/post-process state is network authored.
 */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFUnderwaterPostProcessSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process")
    bool bEnabled = true;

    /** Multiplicative color-grading target. Values above 1 are allowed for a stronger blue/cyan channel. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process", meta=(HideAlphaChannel))
    FLinearColor ColorTint = FLinearColor(0.55f, 0.88f, 1.15f, 1.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process", meta=(ClampMin="0.0", ClampMax="1.0"))
    float ColorTintStrength = 0.60f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process", meta=(ClampMin="0.0", ClampMax="2.0"))
    float Saturation = 0.78f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process", meta=(ClampMin="0.1", ClampMax="3.0"))
    float Contrast = 1.05f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process", meta=(ClampMin="0.1", ClampMax="3.0"))
    float Gamma = 0.96f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process", meta=(ClampMin="-10.0", ClampMax="10.0"))
    float ExposureCompensation = -0.35f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process", meta=(ClampMin="0.0", ClampMax="1.0"))
    float VignetteIntensity = 0.24f;

    /** Subtle edge color separation. Keep low for a clean MMO look. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process", meta=(ClampMin="0.0", ClampMax="5.0"))
    float ChromaticAberrationIntensity = 0.35f;

    /**
     * Enables the native local underwater distance-fog layer. Unlike color grading, this actually removes distant
     * scene clarity so terrain/objects fade naturally into the water color. It is rendered only for the owning
     * local camera and does not change replicated gameplay or the water actor's zero-tick contract.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Distance Fog")
    bool bEnableDistanceFog = true;

    /** Inscattering color used by the native underwater distance fog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Distance Fog", meta=(HideAlphaChannel))
    FLinearColor DistanceFogColor = FLinearColor(0.025f, 0.16f, 0.23f, 1.0f);

    /** Full-strength exponential fog density. Higher values shorten underwater visibility distance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Distance Fog", meta=(ClampMin="0.0", ClampMax="2.0"))
    float DistanceFogDensity = 0.075f;

    /** Kept very low by default so underwater fog behaves primarily as distance haze rather than world-height fog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Distance Fog", meta=(ClampMin="0.001", ClampMax="2.0"))
    float DistanceFogHeightFalloff = 0.001f;

    /** Distance from the camera before the native underwater fog begins affecting scene geometry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Distance Fog", meta=(ClampMin="0.0", Units="cm"))
    float DistanceFogStartDistance = 50.0f;

    /** Upper opacity limit for the native underwater distance fog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Distance Fog", meta=(ClampMin="0.0", ClampMax="1.0"))
    float DistanceFogMaxOpacity = 0.94f;

    /**
     * Shapes how quickly fog density reaches full strength as the existing underwater blend rises. Values below 1
     * give convincing visibility loss immediately below the surface while preserving the smooth waterline fade.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Distance Fog", meta=(ClampMin="0.1", ClampMax="4.0"))
    float DistanceFogBlendExponent = 0.65f;

    /** Camera must be this far below the surface before the local underwater presentation engages. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Waterline", meta=(ClampMin="0.0", Units="cm"))
    float CameraEnterDepth = 8.0f;

    /** Once engaged, the camera must rise this far above the surface before the presentation disengages. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Waterline", meta=(ClampMin="0.0", Units="cm"))
    float CameraExitHeight = 4.0f;

    /** Effect strength immediately after the camera enters the water; deeper water then ramps toward full strength. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Depth Response", meta=(ClampMin="0.0", ClampMax="1.0"))
    float ShallowWaterBlendWeight = 0.72f;

    /** Camera depth at which the profile reaches full post-process weight. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Depth Response", meta=(ClampMin="1.0", Units="cm"))
    float FullStrengthDepth = 180.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Blend", meta=(ClampMin="0.0", ClampMax="100.0"))
    float BlendInSpeed = 5.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Blend", meta=(ClampMin="0.0", ClampMax="100.0"))
    float BlendOutSpeed = 7.0f;

    /** Priority of the local unbound post-process component while this water body supplies the active profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Advanced")
    float Priority = 1000.0f;

    /** Optional project-authored Post Process material for refraction, caustics, SceneDepth haze, particles, etc. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Advanced")
    TObjectPtr<UMaterialInterface> PostProcessMaterial = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Underwater Post Process|Advanced", meta=(ClampMin="0.0", ClampMax="1.0"))
    float PostProcessMaterialWeight = 1.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDMFWaterPlayerOverlapChanged, ADMFPlayerAvatarCharacter*, PlayerAvatar, bool, bEnteredWater);

/**
 * Replicated, Blueprint-derivable swimmable water body for Digimon MMO Framework.
 *
 * The actor owns a visible plane mesh plus a matching overlap volume extending downward from that surface.
 * It does not teleport or author client transforms. The authoritative server decides which water body a player
 * occupies; normal ACharacter movement replication carries the resulting swimming motion to other peers.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFSwimmableWater : public AActor
{
    GENERATED_BODY()

public:
    ADMFSwimmableWater();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Swimming Water|Components")
    TObjectPtr<USceneComponent> SceneRoot;

    /** Visible water surface. Collision is intentionally disabled; SwimmingBounds owns Pawn overlap. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Swimming Water|Components")
    TObjectPtr<UStaticMeshComponent> WaterSurfaceMeshComponent;

    /** Query-only Pawn overlap volume automatically sized to the surface plane and configured depth. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Swimming Water|Components")
    TObjectPtr<UBoxComponent> SwimmingBounds;

    // ---- Geometry / presentation ---------------------------------------------------------

    /** Width (X) and length (Y) of both the visible plane and swimming collision bounds in Unreal units. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_WaterConfiguration, Category="Digimon MMO|Swimming Water|Geometry", meta=(ClampMin="100.0"))
    FVector2D WaterSurfaceSize = FVector2D(5000.0f, 5000.0f);

    /** Swimmable depth below the visible surface plane. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_WaterConfiguration, Category="Digimon MMO|Swimming Water|Geometry", meta=(ClampMin="10.0", Units="cm"))
    float WaterDepth = 1200.0f;

    /** Extra overlap height above the plane keeps a surface swimmer registered while their capsule/head breaches the water. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_WaterConfiguration, Category="Digimon MMO|Swimming Water|Geometry", meta=(ClampMin="0.0", Units="cm"))
    float SurfaceOverlapHeight = 140.0f;

    /** Local Z offset of the visible water surface from the actor origin. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_WaterConfiguration, Category="Digimon MMO|Swimming Water|Geometry", meta=(Units="cm"))
    float WaterSurfaceZOffset = 0.0f;

    /** Mesh used for the visible surface. Defaults to Engine/BasicShapes/Plane. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Presentation")
    TObjectPtr<UStaticMesh> WaterSurfaceMesh;

    /** Project water material. Translucent/SingleLayerWater/custom materials are all supported. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Presentation")
    TObjectPtr<UMaterialInterface> WaterMaterial;

    /** Automatically scales WaterSurfaceMesh to WaterSurfaceSize using the mesh asset bounds. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Presentation")
    bool bAutoSizeSurfaceMeshToBounds = true;

    // ---- Runtime availability ------------------------------------------------------------

    /** Authority-owned master switch. Disabled water does not register players as swimming. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_WaterConfiguration, Category="Digimon MMO|Swimming Water|Runtime")
    bool bSwimmingEnabled = true;

    /** Higher priority wins if multiple water bodies overlap the same player. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="Digimon MMO|Swimming Water|Runtime")
    int32 WaterPriority = 0;

    // ---- Swimming movement ---------------------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Movement", Replicated, meta=(ClampMin="0.0"))
    float SurfaceSwimSpeed = 420.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Movement", Replicated, meta=(ClampMin="0.0"))
    float UnderwaterSwimSpeed = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Movement", Replicated, meta=(ClampMin="0.0"))
    float SprintSwimSpeed = 650.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Movement", Replicated, meta=(ClampMin="0.0"))
    float SwimAcceleration = 1600.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Movement", Replicated, meta=(ClampMin="0.0"))
    float SwimBrakingDeceleration = 700.0f;

    /** Keeps an idle/surface swimmer close to the surface without preventing an intentional camera-down dive. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Digimon MMO|Swimming Water|Surface Assist")
    bool bEnableSurfaceAssist = true;

    /** Desired actor-origin depth below the water plane while surface swimming. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Surface Assist", Replicated, meta=(EditCondition="bEnableSurfaceAssist", ClampMin="0.0", Units="cm"))
    float SurfaceRideDepth = 45.0f;

    /** Vertical correction strength used to settle a surface swimmer onto SurfaceRideDepth. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Surface Assist", Replicated, meta=(EditCondition="bEnableSurfaceAssist", ClampMin="0.0"))
    float SurfaceAssistStrength = 5.0f;

    /** Maximum vertical speed injected by surface assist. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Surface Assist", Replicated, meta=(EditCondition="bEnableSurfaceAssist", ClampMin="0.0"))
    float MaximumSurfaceAssistSpeed = 220.0f;

    /** Camera forward Z at or below this value counts as an intentional forward-input dive from the surface. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Surface Assist", Replicated, meta=(EditCondition="bEnableSurfaceAssist", ClampMin="-1.0", ClampMax="0.0"))
    float DiveCameraForwardZThreshold = -0.18f;

    /** Depth below the plane where Surface changes to Underwater. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Underwater", Replicated, meta=(ClampMin="0.0", Units="cm"))
    float UnderwaterEnterDepth = 135.0f;

    /** Shallower hysteresis point where Underwater changes back to Surface. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Swimming Water|Underwater", Replicated, meta=(ClampMin="0.0", Units="cm"))
    float UnderwaterExitDepth = 85.0f;

    // ---- Underwater post-process presentation -------------------------------------------

    /**
     * Replicated authoring profile consumed only by the locally controlled camera. This lets different water bodies
     * have different underwater color/PP looks while keeping rendering client-local and gameplay authority unchanged.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_UnderwaterPostProcessSettings, Category="Digimon MMO|Swimming Water|Underwater Post Process", meta=(ShowOnlyInnerProperties))
    FDMFUnderwaterPostProcessSettings UnderwaterPostProcessSettings;

    // ---- Blueprint API -------------------------------------------------------------------

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Swimming Water")
    float GetWaterSurfaceWorldZ() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Swimming Water")
    float GetWaterBottomWorldZ() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Swimming Water")
    float GetDepthBelowSurface(const FVector& WorldLocation) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Swimming Water")
    bool IsWorldLocationInsideSwimmingBounds(const FVector& WorldLocation) const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Swimming Water")
    bool IsSwimmingEnabled() const { return bSwimmingEnabled; }

    /** Authority-only at runtime; editor/default authoring remains available through Details panel. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Authority")
    bool SetSwimmingEnabled(bool bNewEnabled);

    /** Authority-only at runtime. Replicates the new size and rebuilds plane/collision on clients. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Authority")
    bool SetWaterSurfaceSize(FVector2D NewSurfaceSize);

    /** Authority-only at runtime. Replicates the new depth and rebuilds collision on clients. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Authority")
    bool SetWaterDepth(float NewDepth);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Authority")
    bool SetSurfaceOverlapHeight(float NewOverlapHeight);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Authority")
    bool SetWaterSurfaceZOffset(float NewSurfaceZOffset);

    /** Authority-only at runtime. Useful when overlapping lakes/volumes need an explicit controlling-water order. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Authority")
    bool SetWaterPriority(int32 NewPriority);

    /** Presentation helper. Material assets are authored content and are not gameplay authority. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Presentation")
    void SetWaterMaterial(UMaterialInterface* NewMaterial);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Swimming Water|Underwater Post Process")
    FDMFUnderwaterPostProcessSettings GetUnderwaterPostProcessSettings() const { return UnderwaterPostProcessSettings; }

    /** Authority-only at runtime. Replaces and replicates the complete local-camera underwater presentation profile. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Underwater Post Process|Authority")
    bool SetUnderwaterPostProcessSettings(const FDMFUnderwaterPostProcessSettings& NewSettings);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Underwater Post Process|Authority")
    bool SetUnderwaterPostProcessEnabled(bool bNewEnabled);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Swimming Water|Underwater Post Process|Authority")
    bool SetUnderwaterPostProcessMaterial(UMaterialInterface* NewMaterial, float MaterialWeight = 1.0f);

    /** Re-applies the active local swimmer's post-process profile without changing gameplay state. */
    UFUNCTION(BlueprintCallable, CallInEditor, Category="Digimon MMO|Swimming Water|Underwater Post Process")
    void RefreshUnderwaterPostProcessPresentation();

    /** Re-applies plane mesh/material scale and overlap bounds from the exposed values. */
    UFUNCTION(BlueprintCallable, CallInEditor, Category="Digimon MMO|Swimming Water")
    void RefreshWaterGeometry();

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Swimming Water|Events")
    FDMFWaterPlayerOverlapChanged OnPlayerWaterOverlapChanged;

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Swimming Water|Events")
    void BP_OnPlayerEnteredWater(ADMFPlayerAvatarCharacter* PlayerAvatar);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Swimming Water|Events")
    void BP_OnPlayerExitedWater(ADMFPlayerAvatarCharacter* PlayerAvatar);

private:
    UFUNCTION()
    void HandleSwimmingBoundsBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void HandleSwimmingBoundsEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);

    UFUNCTION()
    void OnRep_WaterConfiguration();

    UFUNCTION()
    void OnRep_UnderwaterPostProcessSettings();

    void NotifyExistingOverlapsDisabled();
    void RefreshOverlappingPlayerSelections();
    void SanitizeUnderwaterPostProcessSettings();
};
