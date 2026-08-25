#include "Game/DMFDigimonCarePropActor.h"

#include "Components/MeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Engine/AssetManager.h"
#include "Engine/StaticMesh.h"
#include "Net/UnrealNetwork.h"
#include "Settings/DMFFrameworkSettings.h"

ADMFDigimonCarePropActor::ADMFDigimonCarePropActor()
{
    bReplicates = true;
    SetReplicateMovement(true);
    SetActorEnableCollision(false);
    NetUpdateFrequency = 10.0f;
    MinNetUpdateFrequency = 2.0f;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarePropMesh"));
    SetRootComponent(MeshComponent);
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
    MeshComponent->SetGenerateOverlapEvents(false);
    MeshComponent->SetCanEverAffectNavigation(false);
    MeshComponent->SetCastShadow(true);
    MeshComponent->SetRenderCustomDepth(true);
    MeshComponent->SetCustomDepthStencilValue(0);
}

void ADMFDigimonCarePropActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    RefreshFrameworkCustomDepth();
}

void ADMFDigimonCarePropActor::BeginPlay()
{
    Super::BeginPlay();
    RefreshFrameworkCustomDepth();
}

void ADMFDigimonCarePropActor::RefreshFrameworkCustomDepth()
{
    TArray<UMeshComponent*> MeshComponents;
    GetComponents<UMeshComponent>(MeshComponents);

    const int32 StencilValue = FMath::Clamp(CustomDepthStencilValue, 0, 255);
    for (UMeshComponent* CareMeshComponent : MeshComponents)
    {
        if (!IsValid(CareMeshComponent))
        {
            continue;
        }

        CareMeshComponent->SetRenderCustomDepth(true);
        CareMeshComponent->SetCustomDepthStencilValue(StencilValue);
    }
}

void ADMFDigimonCarePropActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFDigimonCarePropActor, SpeciesId);
    DOREPLIFETIME(ADMFDigimonCarePropActor, PropType);
}

void ADMFDigimonCarePropActor::InitializeCareProp(const FPrimaryAssetId InSpeciesId, const EDMFCarePropType InPropType)
{
    if (!HasAuthority())
    {
        return;
    }

    SpeciesId = InSpeciesId;
    PropType = InPropType;
    ApplyPresentation();
    ForceNetUpdate();
}

void ADMFDigimonCarePropActor::OnRep_Presentation()
{
    ApplyPresentation();
}

void ADMFDigimonCarePropActor::ApplyPresentation()
{
    if (!MeshComponent)
    {
        return;
    }

    UDMFDigimonSpeciesData* Species = nullptr;
    if (SpeciesId.IsValid())
    {
        UAssetManager& AssetManager = UAssetManager::Get();
        Species = AssetManager.GetPrimaryAssetObject<UDMFDigimonSpeciesData>(SpeciesId);
        if (!Species)
        {
            const FSoftObjectPath SpeciesPath = AssetManager.GetPrimaryAssetPath(SpeciesId);
            if (SpeciesPath.IsValid())
            {
                Species = Cast<UDMFDigimonSpeciesData>(SpeciesPath.TryLoad());
            }
        }
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UStaticMesh* PresentationMesh = nullptr;
    if (PropType == EDMFCarePropType::DigiMeat)
    {
        PresentationMesh = Species && !Species->DigiMeatMesh.IsNull()
            ? Species->DigiMeatMesh.LoadSynchronous()
            : (Settings ? Settings->DefaultDigiMeatMesh.LoadSynchronous() : nullptr);
    }
    else
    {
        PresentationMesh = Species && !Species->PooMesh.IsNull()
            ? Species->PooMesh.LoadSynchronous()
            : (Settings ? Settings->DefaultPooMesh.LoadSynchronous() : nullptr);
    }

    MeshComponent->SetStaticMesh(PresentationMesh);
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
    MeshComponent->SetGenerateOverlapEvents(false);
    MeshComponent->SetCanEverAffectNavigation(false);
    SetActorEnableCollision(false);

    BP_OnCarePropPresentationReady(SpeciesId, PropType);
    // Reassert after the Blueprint presentation hook as well so any mesh components
    // created/replaced there join the same framework cel-shading contract.
    RefreshFrameworkCustomDepth();
}
