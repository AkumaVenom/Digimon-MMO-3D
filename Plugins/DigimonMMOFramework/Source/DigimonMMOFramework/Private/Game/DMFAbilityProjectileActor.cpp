#include "Game/DMFAbilityProjectileActor.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Data/DMFDigimonAbilityData.h"
#include "Game/DMFDigimonCharacter.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

ADMFAbilityProjectileActor::ADMFAbilityProjectileActor()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;

    bReplicates = true;
    SetReplicateMovement(true);
    SetNetUpdateFrequency(30.0f);
    SetMinNetUpdateFrequency(15.0f);
    SetActorEnableCollision(false);

    ProjectileRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileRoot"));
    SetRootComponent(ProjectileRoot);

    VisualRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VisualRoot"));
    VisualRoot->SetupAttachment(ProjectileRoot);

    ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
    ProjectileMeshComponent->SetupAttachment(VisualRoot);
    ProjectileMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    ProjectileMeshComponent->SetGenerateOverlapEvents(false);
    ProjectileMeshComponent->SetCanEverAffectNavigation(false);
    ProjectileMeshComponent->SetVisibility(false, true);

    ProjectileNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ProjectileNiagara"));
    ProjectileNiagaraComponent->SetupAttachment(VisualRoot);
    ProjectileNiagaraComponent->SetAutoActivate(false);

    ProjectileCascadeComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ProjectileCascade"));
    ProjectileCascadeComponent->SetupAttachment(VisualRoot);
    ProjectileCascadeComponent->SetAutoActivate(false);
}

void ADMFAbilityProjectileActor::BeginPlay()
{
    Super::BeginPlay();
    SetActorEnableCollision(false);
    RefreshProjectilePresentation();
}

void ADMFAbilityProjectileActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (ProjectileNiagaraComponent)
    {
        ProjectileNiagaraComponent->Deactivate();
    }
    if (ProjectileCascadeComponent)
    {
        ProjectileCascadeComponent->DeactivateSystem();
    }
    Super::EndPlay(EndPlayReason);
}

void ADMFAbilityProjectileActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFAbilityProjectileActor, AbilityId);
    DOREPLIFETIME(ADMFAbilityProjectileActor, SourceDigimon);
    DOREPLIFETIME(ADMFAbilityProjectileActor, TargetDigimon);
    DOREPLIFETIME(ADMFAbilityProjectileActor, TravelDirection);
}

void ADMFAbilityProjectileActor::InitializeProjectile(const FName InAbilityId, ADMFDigimonCharacter* InSource, ADMFDigimonCharacter* InTarget, const FVector& InInitialDirection)
{
    if (!HasAuthority())
    {
        return;
    }

    AbilityId = InAbilityId;
    SourceDigimon = InSource;
    TargetDigimon = InTarget;
    TravelDirection = InInitialDirection.GetSafeNormal();
    if (TravelDirection.IsNearlyZero())
    {
        TravelDirection = GetActorForwardVector().GetSafeNormal();
    }

    if (UDMFDigimonAbilityData* Ability = ResolveAbilityData())
    {
        SetLifeSpan(FMath::Max(0.1f, Ability->ProjectileMaxLifetimeSeconds));
        VisualRoot->SetRelativeRotation(Ability->ProjectileVisualRotationOffset);
        VisualRoot->SetRelativeScale3D(Ability->ProjectileVisualScale);
    }

    ForceNetUpdate();
}

void ADMFAbilityProjectileActor::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    // Clients consume replicated movement only. Authority alone owns target pursuit and impact.
    if (!HasAuthority() || bAuthoritativeImpactConsumed || DeltaSeconds <= 0.0f)
    {
        return;
    }

    UDMFDigimonAbilityData* Ability = ResolveAbilityData();
    if (!Ability || !SourceDigimon || SourceDigimon->IsActorBeingDestroyed()
        || !SourceDigimon->CombatComponent || SourceDigimon->CombatComponent->IsDefeated())
    {
        Destroy();
        return;
    }

    if (Ability->bRequiresTarget
        && (!TargetDigimon || TargetDigimon->IsActorBeingDestroyed()
            || !SourceDigimon->CombatComponent || !SourceDigimon->CombatComponent->CanAttackTarget(TargetDigimon)))
    {
        Destroy();
        return;
    }

    const FVector OldLocation = GetActorLocation();
    FVector DesiredDirection = TravelDirection.GetSafeNormal();

    if (TargetDigimon)
    {
        const FVector AimPoint = GetTargetAimPoint(*Ability);
        const FVector ToTarget = (AimPoint - OldLocation).GetSafeNormal();
        if (!ToTarget.IsNearlyZero())
        {
            if (Ability->bProjectileHoming)
            {
                const FRotator DesiredRotation = ToTarget.Rotation();
                const FRotator NewRotation = FMath::RInterpConstantTo(
                    GetActorRotation(), DesiredRotation, DeltaSeconds, FMath::Max(0.0f, Ability->ProjectileHomingTurnRateDegrees));
                DesiredDirection = NewRotation.Vector().GetSafeNormal();
            }
            else if (DesiredDirection.IsNearlyZero())
            {
                DesiredDirection = ToTarget;
            }
        }
    }

    if (DesiredDirection.IsNearlyZero())
    {
        DesiredDirection = GetActorForwardVector().GetSafeNormal();
    }

    TravelDirection = DesiredDirection;
    const FRotator TravelRotation = DesiredDirection.Rotation();
    const FVector NewLocation = OldLocation + DesiredDirection * FMath::Max(1.0f, Ability->ProjectileSpeed) * DeltaSeconds;
    SetActorLocationAndRotation(NewLocation, TravelRotation, false, nullptr, ETeleportType::None);

    if (TargetDigimon)
    {
        const FVector AimPoint = GetTargetAimPoint(*Ability);
        const FVector Closest = FMath::ClosestPointOnSegment(AimPoint, OldLocation, NewLocation);
        if (FVector::DistSquared(Closest, AimPoint) <= FMath::Square(FMath::Max(1.0f, Ability->ProjectileImpactRadius)))
        {
            HandleAuthoritativeArrival(AimPoint);
            return;
        }
    }

}

void ADMFAbilityProjectileActor::RefreshProjectilePresentation()
{
    if (GetNetMode() == NM_DedicatedServer)
    {
        return;
    }

    UDMFDigimonAbilityData* Ability = ResolveAbilityData();
    if (!Ability || !VisualRoot)
    {
        return;
    }

    VisualRoot->SetRelativeRotation(Ability->ProjectileVisualRotationOffset);
    VisualRoot->SetRelativeScale3D(Ability->ProjectileVisualScale);

    if (ProjectileMeshComponent)
    {
        UStaticMesh* Mesh = Ability->ProjectileStaticMesh.LoadSynchronous();
        ProjectileMeshComponent->SetStaticMesh(Mesh);
        ProjectileMeshComponent->SetVisibility(Mesh != nullptr, true);
        ProjectileMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }

    UNiagaraSystem* Niagara = Ability->ProjectileNiagaraSystem.LoadSynchronous();
    if (!Niagara)
    {
        Niagara = Ability->NiagaraParticle.LoadSynchronous();
    }

    UParticleSystem* Cascade = Ability->ProjectileCascadeParticle.LoadSynchronous();
    if (!Cascade)
    {
        Cascade = Ability->CascadeParticle.LoadSynchronous();
    }

    // Legacy species Attack1/Attack2 particles remain valid projectile visuals when the Ability Data
    // Asset itself has no dedicated moving VFX configured.
    if ((!Niagara || !Cascade) && SourceDigimon)
    {
        if (UDMFDigimonSpeciesData* Species = SourceDigimon->ResolveSpeciesData())
        {
            const int32 SlotIndex = SourceDigimon->ReplicatedAbilityIds.IndexOfByKey(AbilityId);
            if (SlotIndex == 0)
            {
                if (!Niagara) Niagara = Species->Attack1NiagaraParticle.LoadSynchronous();
                if (!Cascade) Cascade = Species->Attack1CascadeParticle.LoadSynchronous();
            }
            else if (SlotIndex == 1)
            {
                if (!Niagara) Niagara = Species->Attack2NiagaraParticle.LoadSynchronous();
                if (!Cascade) Cascade = Species->Attack2CascadeParticle.LoadSynchronous();
            }
        }
    }

    if (ProjectileNiagaraComponent)
    {
        ProjectileNiagaraComponent->Deactivate();
        ProjectileNiagaraComponent->SetAsset(Niagara);
        if (Niagara)
        {
            ProjectileNiagaraComponent->Activate(true);
        }
    }

    if (ProjectileCascadeComponent)
    {
        ProjectileCascadeComponent->DeactivateSystem();
        ProjectileCascadeComponent->SetTemplate(Niagara ? nullptr : Cascade);
        if (!Niagara && Cascade)
        {
            ProjectileCascadeComponent->ActivateSystem(true);
        }
    }

    bPresentationInitialized = true;
    BP_OnProjectilePresentationReady();
}

UDMFDigimonAbilityData* ADMFAbilityProjectileActor::ResolveAbilityData() const
{
    return SourceDigimon && SourceDigimon->CombatComponent
        ? SourceDigimon->CombatComponent->ResolveAbilityData(AbilityId)
        : nullptr;
}

FVector ADMFAbilityProjectileActor::GetTargetAimPoint(const UDMFDigimonAbilityData& Ability) const
{
    return TargetDigimon ? TargetDigimon->GetActorLocation() + Ability.ProjectileTargetOffset : GetActorLocation() + GetActorForwardVector() * 100.0f;
}

void ADMFAbilityProjectileActor::HandleAuthoritativeArrival(const FVector& ImpactLocation)
{
    if (!HasAuthority() || bAuthoritativeImpactConsumed)
    {
        return;
    }

    bAuthoritativeImpactConsumed = true;
    if (SourceDigimon && SourceDigimon->CombatComponent)
    {
        SourceDigimon->CombatComponent->HandleAuthoritativeProjectileImpact(AbilityId, TargetDigimon, ImpactLocation);
    }
    Destroy();
}

void ADMFAbilityProjectileActor::OnRep_ProjectileDefinition()
{
    RefreshProjectilePresentation();
}
