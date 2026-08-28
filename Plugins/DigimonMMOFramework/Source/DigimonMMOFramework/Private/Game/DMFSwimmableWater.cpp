#include "Game/DMFSwimmableWater.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "Materials/MaterialInterface.h"
#include "Net/UnrealNetwork.h"
#include "UObject/ConstructorHelpers.h"

ADMFSwimmableWater::ADMFSwimmableWater()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    SetReplicateMovement(true);
    // A very large lake may overlap a player while its actor origin is far outside ordinary distance relevancy.
    // Keeping this zero-tick, low-frequency configuration actor relevant guarantees the active-water NetGUID and
    // runtime dimensions are available wherever the player actually swims.
    bAlwaysRelevant = true;
    NetUpdateFrequency = 2.0f;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    WaterSurfaceMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WaterSurfaceMesh"));
    WaterSurfaceMeshComponent->SetupAttachment(SceneRoot);
    WaterSurfaceMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    WaterSurfaceMeshComponent->SetGenerateOverlapEvents(false);
    WaterSurfaceMeshComponent->SetCastShadow(false);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultPlane(TEXT("/Engine/BasicShapes/Plane.Plane"));
    if (DefaultPlane.Succeeded())
    {
        WaterSurfaceMesh = DefaultPlane.Object;
        WaterSurfaceMeshComponent->SetStaticMesh(DefaultPlane.Object);
    }

    SwimmingBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("SwimmingBounds"));
    SwimmingBounds->SetupAttachment(SceneRoot);
    SwimmingBounds->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    SwimmingBounds->SetCollisionObjectType(ECC_WorldDynamic);
    SwimmingBounds->SetCollisionResponseToAllChannels(ECR_Ignore);
    SwimmingBounds->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    SwimmingBounds->SetGenerateOverlapEvents(true);
    SwimmingBounds->SetCanEverAffectNavigation(false);
    SwimmingBounds->OnComponentBeginOverlap.AddDynamic(this, &ADMFSwimmableWater::HandleSwimmingBoundsBeginOverlap);
    SwimmingBounds->OnComponentEndOverlap.AddDynamic(this, &ADMFSwimmableWater::HandleSwimmingBoundsEndOverlap);

    RefreshWaterGeometry();
}

void ADMFSwimmableWater::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    SanitizeUnderwaterPostProcessSettings();
    RefreshWaterGeometry();
}

void ADMFSwimmableWater::BeginPlay()
{
    Super::BeginPlay();
    SanitizeUnderwaterPostProcessSettings();
    RefreshWaterGeometry();
}

void ADMFSwimmableWater::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFSwimmableWater, WaterSurfaceSize);
    DOREPLIFETIME(ADMFSwimmableWater, WaterDepth);
    DOREPLIFETIME(ADMFSwimmableWater, SurfaceOverlapHeight);
    DOREPLIFETIME(ADMFSwimmableWater, WaterSurfaceZOffset);
    DOREPLIFETIME(ADMFSwimmableWater, bSwimmingEnabled);
    DOREPLIFETIME(ADMFSwimmableWater, WaterPriority);
    DOREPLIFETIME(ADMFSwimmableWater, SurfaceSwimSpeed);
    DOREPLIFETIME(ADMFSwimmableWater, UnderwaterSwimSpeed);
    DOREPLIFETIME(ADMFSwimmableWater, SprintSwimSpeed);
    DOREPLIFETIME(ADMFSwimmableWater, SwimAcceleration);
    DOREPLIFETIME(ADMFSwimmableWater, SwimBrakingDeceleration);
    DOREPLIFETIME(ADMFSwimmableWater, bEnableSurfaceAssist);
    DOREPLIFETIME(ADMFSwimmableWater, SurfaceRideDepth);
    DOREPLIFETIME(ADMFSwimmableWater, SurfaceAssistStrength);
    DOREPLIFETIME(ADMFSwimmableWater, MaximumSurfaceAssistSpeed);
    DOREPLIFETIME(ADMFSwimmableWater, DiveCameraForwardZThreshold);
    DOREPLIFETIME(ADMFSwimmableWater, UnderwaterEnterDepth);
    DOREPLIFETIME(ADMFSwimmableWater, UnderwaterExitDepth);
    DOREPLIFETIME(ADMFSwimmableWater, UnderwaterPostProcessSettings);
}

float ADMFSwimmableWater::GetWaterSurfaceWorldZ() const
{
    return GetActorLocation().Z + WaterSurfaceZOffset;
}

float ADMFSwimmableWater::GetWaterBottomWorldZ() const
{
    return GetWaterSurfaceWorldZ() - FMath::Max(10.0f, WaterDepth);
}

float ADMFSwimmableWater::GetDepthBelowSurface(const FVector& WorldLocation) const
{
    return GetWaterSurfaceWorldZ() - WorldLocation.Z;
}

bool ADMFSwimmableWater::IsWorldLocationInsideSwimmingBounds(const FVector& WorldLocation) const
{
    if (!bSwimmingEnabled || !SwimmingBounds)
    {
        return false;
    }

    const FTransform BoundsTransform = SwimmingBounds->GetComponentTransform();
    const FVector Local = BoundsTransform.InverseTransformPosition(WorldLocation);
    const FVector Extent = SwimmingBounds->GetUnscaledBoxExtent();
    return FMath::Abs(Local.X) <= Extent.X
        && FMath::Abs(Local.Y) <= Extent.Y
        && FMath::Abs(Local.Z) <= Extent.Z;
}

bool ADMFSwimmableWater::SetSwimmingEnabled(const bool bNewEnabled)
{
    if (GetWorld() && GetWorld()->IsGameWorld() && !HasAuthority())
    {
        return false;
    }

    if (bSwimmingEnabled == bNewEnabled)
    {
        return true;
    }

    if (!bNewEnabled)
    {
        NotifyExistingOverlapsDisabled();
    }

    bSwimmingEnabled = bNewEnabled;
    RefreshWaterGeometry();
    if (bSwimmingEnabled)
    {
        RefreshOverlappingPlayerSelections();
    }
    ForceNetUpdate();
    return true;
}

bool ADMFSwimmableWater::SetWaterSurfaceSize(const FVector2D NewSurfaceSize)
{
    if (GetWorld() && GetWorld()->IsGameWorld() && !HasAuthority())
    {
        return false;
    }

    WaterSurfaceSize.X = FMath::Max(100.0f, NewSurfaceSize.X);
    WaterSurfaceSize.Y = FMath::Max(100.0f, NewSurfaceSize.Y);
    RefreshWaterGeometry();
    RefreshOverlappingPlayerSelections();
    ForceNetUpdate();
    return true;
}

bool ADMFSwimmableWater::SetWaterDepth(const float NewDepth)
{
    if (GetWorld() && GetWorld()->IsGameWorld() && !HasAuthority())
    {
        return false;
    }

    WaterDepth = FMath::Max(10.0f, NewDepth);
    RefreshWaterGeometry();
    RefreshOverlappingPlayerSelections();
    ForceNetUpdate();
    return true;
}

bool ADMFSwimmableWater::SetSurfaceOverlapHeight(const float NewOverlapHeight)
{
    if (GetWorld() && GetWorld()->IsGameWorld() && !HasAuthority())
    {
        return false;
    }

    SurfaceOverlapHeight = FMath::Max(0.0f, NewOverlapHeight);
    RefreshWaterGeometry();
    RefreshOverlappingPlayerSelections();
    ForceNetUpdate();
    return true;
}

bool ADMFSwimmableWater::SetWaterSurfaceZOffset(const float NewSurfaceZOffset)
{
    if (GetWorld() && GetWorld()->IsGameWorld() && !HasAuthority())
    {
        return false;
    }

    WaterSurfaceZOffset = NewSurfaceZOffset;
    RefreshWaterGeometry();
    RefreshOverlappingPlayerSelections();
    ForceNetUpdate();
    return true;
}

bool ADMFSwimmableWater::SetWaterPriority(const int32 NewPriority)
{
    if (GetWorld() && GetWorld()->IsGameWorld() && !HasAuthority())
    {
        return false;
    }

    WaterPriority = NewPriority;
    RefreshOverlappingPlayerSelections();
    ForceNetUpdate();
    return true;
}

void ADMFSwimmableWater::SetWaterMaterial(UMaterialInterface* NewMaterial)
{
    WaterMaterial = NewMaterial;
    if (WaterSurfaceMeshComponent)
    {
        WaterSurfaceMeshComponent->SetMaterial(0, WaterMaterial);
    }
}

bool ADMFSwimmableWater::SetUnderwaterPostProcessSettings(const FDMFUnderwaterPostProcessSettings& NewSettings)
{
    if (GetWorld() && GetWorld()->IsGameWorld() && !HasAuthority())
    {
        return false;
    }

    UnderwaterPostProcessSettings = NewSettings;
    SanitizeUnderwaterPostProcessSettings();
    RefreshUnderwaterPostProcessPresentation();
    ForceNetUpdate();
    return true;
}

bool ADMFSwimmableWater::SetUnderwaterPostProcessEnabled(const bool bNewEnabled)
{
    if (GetWorld() && GetWorld()->IsGameWorld() && !HasAuthority())
    {
        return false;
    }

    UnderwaterPostProcessSettings.bEnabled = bNewEnabled;
    RefreshUnderwaterPostProcessPresentation();
    ForceNetUpdate();
    return true;
}

bool ADMFSwimmableWater::SetUnderwaterPostProcessMaterial(UMaterialInterface* NewMaterial, const float MaterialWeight)
{
    if (GetWorld() && GetWorld()->IsGameWorld() && !HasAuthority())
    {
        return false;
    }

    UnderwaterPostProcessSettings.PostProcessMaterial = NewMaterial;
    UnderwaterPostProcessSettings.PostProcessMaterialWeight = FMath::Clamp(MaterialWeight, 0.0f, 1.0f);
    RefreshUnderwaterPostProcessPresentation();
    ForceNetUpdate();
    return true;
}

void ADMFSwimmableWater::RefreshUnderwaterPostProcessPresentation()
{
    SanitizeUnderwaterPostProcessSettings();

    if (!SwimmingBounds)
    {
        return;
    }

    TArray<AActor*> OverlappingActors;
    SwimmingBounds->GetOverlappingActors(OverlappingActors, ADMFPlayerAvatarCharacter::StaticClass());
    for (AActor* Actor : OverlappingActors)
    {
        if (ADMFPlayerAvatarCharacter* PlayerAvatar = Cast<ADMFPlayerAvatarCharacter>(Actor))
        {
            PlayerAvatar->RefreshUnderwaterPostProcessPresentation();
        }
    }
}

void ADMFSwimmableWater::RefreshWaterGeometry()
{
    WaterSurfaceSize.X = FMath::Max(100.0f, WaterSurfaceSize.X);
    WaterSurfaceSize.Y = FMath::Max(100.0f, WaterSurfaceSize.Y);
    WaterDepth = FMath::Max(10.0f, WaterDepth);
    SurfaceOverlapHeight = FMath::Max(0.0f, SurfaceOverlapHeight);

    if (WaterSurfaceMeshComponent)
    {
        if (WaterSurfaceMesh)
        {
            WaterSurfaceMeshComponent->SetStaticMesh(WaterSurfaceMesh);
        }
        WaterSurfaceMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, WaterSurfaceZOffset));
        WaterSurfaceMeshComponent->SetMaterial(0, WaterMaterial);
        WaterSurfaceMeshComponent->SetVisibility(true, true);

        if (bAutoSizeSurfaceMeshToBounds && WaterSurfaceMeshComponent->GetStaticMesh())
        {
            const FBoxSphereBounds MeshBounds = WaterSurfaceMeshComponent->GetStaticMesh()->GetBounds();
            const float BaseX = FMath::Max(1.0f, MeshBounds.BoxExtent.X * 2.0f);
            const float BaseY = FMath::Max(1.0f, MeshBounds.BoxExtent.Y * 2.0f);
            WaterSurfaceMeshComponent->SetRelativeScale3D(FVector(WaterSurfaceSize.X / BaseX, WaterSurfaceSize.Y / BaseY, 1.0f));
        }
    }

    if (SwimmingBounds)
    {
        const float TotalHeight = WaterDepth + SurfaceOverlapHeight;
        SwimmingBounds->SetBoxExtent(FVector(WaterSurfaceSize.X * 0.5f, WaterSurfaceSize.Y * 0.5f, TotalHeight * 0.5f), true);
        SwimmingBounds->SetRelativeLocation(FVector(0.0f, 0.0f, WaterSurfaceZOffset + ((SurfaceOverlapHeight - WaterDepth) * 0.5f)));
        SwimmingBounds->SetCollisionEnabled(bSwimmingEnabled ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
        SwimmingBounds->SetGenerateOverlapEvents(bSwimmingEnabled);
    }
}

void ADMFSwimmableWater::HandleSwimmingBoundsBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (!bSwimmingEnabled)
    {
        return;
    }

    ADMFPlayerAvatarCharacter* PlayerAvatar = Cast<ADMFPlayerAvatarCharacter>(OtherActor);
    if (!PlayerAvatar)
    {
        return;
    }

    PlayerAvatar->RegisterSwimmableWaterOverlap(this, true);
    OnPlayerWaterOverlapChanged.Broadcast(PlayerAvatar, true);
    BP_OnPlayerEnteredWater(PlayerAvatar);
}

void ADMFSwimmableWater::HandleSwimmingBoundsEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
    ADMFPlayerAvatarCharacter* PlayerAvatar = Cast<ADMFPlayerAvatarCharacter>(OtherActor);
    if (!PlayerAvatar)
    {
        return;
    }

    PlayerAvatar->RegisterSwimmableWaterOverlap(this, false);
    OnPlayerWaterOverlapChanged.Broadcast(PlayerAvatar, false);
    BP_OnPlayerExitedWater(PlayerAvatar);
}

void ADMFSwimmableWater::OnRep_WaterConfiguration()
{
    RefreshWaterGeometry();
    RefreshOverlappingPlayerSelections();
}

void ADMFSwimmableWater::OnRep_UnderwaterPostProcessSettings()
{
    SanitizeUnderwaterPostProcessSettings();
    RefreshUnderwaterPostProcessPresentation();
}

void ADMFSwimmableWater::SanitizeUnderwaterPostProcessSettings()
{
    FDMFUnderwaterPostProcessSettings& Settings = UnderwaterPostProcessSettings;
    Settings.ColorTintStrength = FMath::Clamp(Settings.ColorTintStrength, 0.0f, 1.0f);
    Settings.Saturation = FMath::Clamp(Settings.Saturation, 0.0f, 2.0f);
    Settings.Contrast = FMath::Clamp(Settings.Contrast, 0.1f, 3.0f);
    Settings.Gamma = FMath::Clamp(Settings.Gamma, 0.1f, 3.0f);
    Settings.ExposureCompensation = FMath::Clamp(Settings.ExposureCompensation, -10.0f, 10.0f);
    Settings.VignetteIntensity = FMath::Clamp(Settings.VignetteIntensity, 0.0f, 1.0f);
    Settings.ChromaticAberrationIntensity = FMath::Clamp(Settings.ChromaticAberrationIntensity, 0.0f, 5.0f);
    Settings.DistanceFogDensity = FMath::Clamp(Settings.DistanceFogDensity, 0.0f, 2.0f);
    Settings.DistanceFogHeightFalloff = FMath::Clamp(Settings.DistanceFogHeightFalloff, 0.001f, 2.0f);
    Settings.DistanceFogStartDistance = FMath::Max(0.0f, Settings.DistanceFogStartDistance);
    Settings.DistanceFogMaxOpacity = FMath::Clamp(Settings.DistanceFogMaxOpacity, 0.0f, 1.0f);
    Settings.DistanceFogBlendExponent = FMath::Clamp(Settings.DistanceFogBlendExponent, 0.1f, 4.0f);
    Settings.CameraEnterDepth = FMath::Max(0.0f, Settings.CameraEnterDepth);
    Settings.CameraExitHeight = FMath::Max(0.0f, Settings.CameraExitHeight);
    Settings.ShallowWaterBlendWeight = FMath::Clamp(Settings.ShallowWaterBlendWeight, 0.0f, 1.0f);
    Settings.FullStrengthDepth = FMath::Max(1.0f, Settings.FullStrengthDepth);
    Settings.BlendInSpeed = FMath::Max(0.0f, Settings.BlendInSpeed);
    Settings.BlendOutSpeed = FMath::Max(0.0f, Settings.BlendOutSpeed);
    Settings.PostProcessMaterialWeight = FMath::Clamp(Settings.PostProcessMaterialWeight, 0.0f, 1.0f);
}

void ADMFSwimmableWater::NotifyExistingOverlapsDisabled()
{
    if (!SwimmingBounds)
    {
        return;
    }

    TArray<AActor*> OverlappingActors;
    SwimmingBounds->GetOverlappingActors(OverlappingActors, ADMFPlayerAvatarCharacter::StaticClass());
    for (AActor* Actor : OverlappingActors)
    {
        if (ADMFPlayerAvatarCharacter* PlayerAvatar = Cast<ADMFPlayerAvatarCharacter>(Actor))
        {
            PlayerAvatar->RegisterSwimmableWaterOverlap(this, false);
            OnPlayerWaterOverlapChanged.Broadcast(PlayerAvatar, false);
            BP_OnPlayerExitedWater(PlayerAvatar);
        }
    }
}
void ADMFSwimmableWater::RefreshOverlappingPlayerSelections()
{
    if (!SwimmingBounds)
    {
        return;
    }

    TArray<AActor*> OverlappingActors;
    SwimmingBounds->GetOverlappingActors(OverlappingActors, ADMFPlayerAvatarCharacter::StaticClass());
    for (AActor* Actor : OverlappingActors)
    {
        if (ADMFPlayerAvatarCharacter* PlayerAvatar = Cast<ADMFPlayerAvatarCharacter>(Actor))
        {
            PlayerAvatar->RegisterSwimmableWaterOverlap(this, bSwimmingEnabled);
        }
    }
}

