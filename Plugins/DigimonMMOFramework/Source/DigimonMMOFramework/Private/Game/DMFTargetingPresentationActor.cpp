#include "Game/DMFTargetingPresentationActor.h"

#include "Components/CapsuleComponent.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Settings/DMFFrameworkSettings.h"

ADMFTargetingPresentationActor::ADMFTargetingPresentationActor()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
    bReplicates = false;
    SetReplicateMovement(false);
    SetActorEnableCollision(false);

    PresentationRoot = CreateDefaultSubobject<USceneComponent>(TEXT("TargetingPresentationRoot"));
    SetRootComponent(PresentationRoot);

    ActivePartnerRingPivot = CreateDefaultSubobject<USceneComponent>(TEXT("ActivePartnerRingPivot"));
    ActivePartnerRingPivot->SetupAttachment(PresentationRoot);

    ActivePartnerRingSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ActivePartnerRingSprite"));
    ActivePartnerRingSprite->SetupAttachment(ActivePartnerRingPivot);
    ActivePartnerRingSprite->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    ActivePartnerRingSprite->SetGenerateOverlapEvents(false);
    ActivePartnerRingSprite->SetCastShadow(false);
    // This actor itself is spawned only in the owning local player's world and never replicates.
    // Do NOT apply OnlyOwnerSee here: the renderer can evaluate the active camera/view target rather
    // than the PlayerController as the view owner, which can incorrectly cull this local-only marker.
    ActivePartnerRingSprite->SetOnlyOwnerSee(false);
    ActivePartnerRingSprite->SetOwnerNoSee(false);
    ActivePartnerRingSprite->SetHiddenInGame(false);
    ActivePartnerRingSprite->SetVisibility(false, true);

    EnemyTargetRingPivot = CreateDefaultSubobject<USceneComponent>(TEXT("EnemyTargetRingPivot"));
    EnemyTargetRingPivot->SetupAttachment(PresentationRoot);

    EnemyTargetRingSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("EnemyTargetRingSprite"));
    EnemyTargetRingSprite->SetupAttachment(EnemyTargetRingPivot);
    EnemyTargetRingSprite->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    EnemyTargetRingSprite->SetGenerateOverlapEvents(false);
    EnemyTargetRingSprite->SetCastShadow(false);
    EnemyTargetRingSprite->SetOnlyOwnerSee(false);
    EnemyTargetRingSprite->SetOwnerNoSee(false);
    EnemyTargetRingSprite->SetHiddenInGame(false);
    EnemyTargetRingSprite->SetVisibility(false, true);

    EnemyTargetArrowNiagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("EnemyTargetArrowNiagara"));
    EnemyTargetArrowNiagara->SetupAttachment(PresentationRoot);
    EnemyTargetArrowNiagara->SetAutoActivate(false);
    // The overhead enemy marker is framework presentation and is always forced through CustomDepth.
    EnemyTargetArrowNiagara->SetRenderCustomDepth(true);
    EnemyTargetArrowNiagara->SetOnlyOwnerSee(false);
    EnemyTargetArrowNiagara->SetOwnerNoSee(false);
    EnemyTargetArrowNiagara->SetHiddenInGame(false);
    EnemyTargetArrowNiagara->SetVisibility(false, true);

    EnemyTargetArrowCascade = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EnemyTargetArrowCascade"));
    EnemyTargetArrowCascade->SetupAttachment(PresentationRoot);
    EnemyTargetArrowCascade->bAutoActivate = false;
    EnemyTargetArrowCascade->SetRenderCustomDepth(true);
    EnemyTargetArrowCascade->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    EnemyTargetArrowCascade->SetGenerateOverlapEvents(false);
    EnemyTargetArrowCascade->SetCastShadow(false);
    EnemyTargetArrowCascade->SetOnlyOwnerSee(false);
    EnemyTargetArrowCascade->SetOwnerNoSee(false);
    EnemyTargetArrowCascade->SetHiddenInGame(false);
    EnemyTargetArrowCascade->SetVisibility(false, true);
}

void ADMFTargetingPresentationActor::BeginPlay()
{
    Super::BeginPlay();

    if (GetNetMode() == NM_DedicatedServer)
    {
        SetActorTickEnabled(false);
        HideAllPresentation();
        return;
    }

    ResolveOwningController();
    RefreshPresentationAssets();
}

void ADMFTargetingPresentationActor::ResolveOwningController()
{
    if (OwningFrameworkController.IsValid())
    {
        return;
    }

    OwningFrameworkController = Cast<ADMFMMOPlayerController>(GetOwner());
}

void ADMFTargetingPresentationActor::RefreshPresentationAssets()
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings)
    {
        HideAllPresentation();
        return;
    }

    UPaperSprite* ActiveSprite = Settings->ActivePartnerTargetingRingSprite.IsNull()
        ? nullptr
        : Settings->ActivePartnerTargetingRingSprite.LoadSynchronous();
    ActivePartnerRingSprite->SetOnlyOwnerSee(false);
    ActivePartnerRingSprite->SetOwnerNoSee(false);
    ActivePartnerRingSprite->SetHiddenInGame(false);
    ActivePartnerRingSprite->SetSprite(ActiveSprite);
    ActivePartnerRingSprite->SetRelativeRotation(Settings->TargetingRingSpriteRelativeRotation);
    ActivePartnerRingSprite->SetTranslucentSortPriority(Settings->TargetingVisualTranslucentSortPriority);

    UPaperSprite* EnemySprite = Settings->EnemyTargetingRingSprite.IsNull()
        ? nullptr
        : Settings->EnemyTargetingRingSprite.LoadSynchronous();
    EnemyTargetRingSprite->SetOnlyOwnerSee(false);
    EnemyTargetRingSprite->SetOwnerNoSee(false);
    EnemyTargetRingSprite->SetHiddenInGame(false);
    EnemyTargetRingSprite->SetSprite(EnemySprite);
    EnemyTargetRingSprite->SetRelativeRotation(Settings->TargetingRingSpriteRelativeRotation);
    EnemyTargetRingSprite->SetTranslucentSortPriority(Settings->TargetingVisualTranslucentSortPriority + 1);

    UNiagaraSystem* NiagaraSystem = Settings->EnemyTargetArrowNiagaraSystem.IsNull()
        ? nullptr
        : Settings->EnemyTargetArrowNiagaraSystem.LoadSynchronous();
    UParticleSystem* CascadeSystem = Settings->EnemyTargetArrowCascadeSystem.IsNull()
        ? nullptr
        : Settings->EnemyTargetArrowCascadeSystem.LoadSynchronous();

    // The overhead enemy marker is framework presentation and is always forced through CustomDepth.
    // Reapply this whenever Project Settings assets are refreshed during PIE/runtime.
    EnemyTargetArrowNiagara->SetRenderCustomDepth(true);
    EnemyTargetArrowNiagara->SetOnlyOwnerSee(false);
    EnemyTargetArrowNiagara->SetOwnerNoSee(false);
    EnemyTargetArrowNiagara->SetHiddenInGame(false);
    EnemyTargetArrowNiagara->DeactivateImmediate();
    EnemyTargetArrowNiagara->SetAsset(NiagaraSystem);
    EnemyTargetArrowNiagara->SetVisibility(false, true);

    EnemyTargetArrowCascade->SetRenderCustomDepth(true);
    EnemyTargetArrowCascade->SetOnlyOwnerSee(false);
    EnemyTargetArrowCascade->SetOwnerNoSee(false);
    EnemyTargetArrowCascade->SetHiddenInGame(false);
    EnemyTargetArrowCascade->DeactivateSystem();
    EnemyTargetArrowCascade->SetTemplate(CascadeSystem);
    EnemyTargetArrowCascade->SetVisibility(false, true);

    bHasNiagaraArrowAsset = NiagaraSystem != nullptr;
    bHasCascadeArrowAsset = CascadeSystem != nullptr;

    if (Settings->bPreferNiagaraEnemyTargetArrow)
    {
        bUseNiagaraArrow = bHasNiagaraArrowAsset || !bHasCascadeArrowAsset;
    }
    else
    {
        bUseNiagaraArrow = !bHasCascadeArrowAsset && bHasNiagaraArrowAsset;
    }

    bArrowPresentationActive = false;
}

void ADMFTargetingPresentationActor::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    ResolveOwningController();
    ADMFMMOPlayerController* PC = OwningFrameworkController.Get();
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!PC || !PC->IsLocalController())
    {
        HideAllPresentation();
        Destroy();
        return;
    }
    if (!Settings || !Settings->bEnableCombatTargetingVisuals)
    {
        HideAllPresentation();
        return;
    }

    // Project Settings may be edited while PIE is already running. If the presentation actor was
    // created before an asset was assigned, lazily pick it up here instead of requiring a world restart.
    const bool bNeedsRuntimeAssetRefresh =
        (Settings->bShowActivePartnerTargetingRing && !Settings->ActivePartnerTargetingRingSprite.IsNull() && !ActivePartnerRingSprite->GetSprite())
        || (Settings->bShowEnemyTargetingRing && !Settings->EnemyTargetingRingSprite.IsNull() && !EnemyTargetRingSprite->GetSprite())
        || (Settings->bShowEnemyTargetArrow
            && ((!Settings->EnemyTargetArrowNiagaraSystem.IsNull() && !bHasNiagaraArrowAsset)
                || (!Settings->EnemyTargetArrowCascadeSystem.IsNull() && !bHasCascadeArrowAsset)));
    if (bNeedsRuntimeAssetRefresh)
    {
        RefreshPresentationAssets();
    }

    ADMFPlayerState* PS = PC->GetPlayerState<ADMFPlayerState>();
    UDMFPlayerDigimonComponent* DigimonComponent = PS ? PS->DigimonComponent : nullptr;
    if (!DigimonComponent)
    {
        HideAllPresentation();
        return;
    }

    LocalPresentationTime += FMath::Max(0.0f, DeltaSeconds);

    ADMFDigimonCharacter* ActivePartner = DigimonComponent->ActivePartnerActor;
    ADMFDigimonCharacter* CommandTarget = DigimonComponent->GetCommandTarget();
    if (CommandTarget && CommandTarget == ActivePartner)
    {
        CommandTarget = nullptr;
    }
    if (CommandTarget && CommandTarget->CombatComponent && CommandTarget->CombatComponent->IsDefeated())
    {
        CommandTarget = nullptr;
    }

    UpdateActivePartnerPresentation(ActivePartner, DeltaSeconds);
    UpdateCommandTargetPresentation(CommandTarget, DeltaSeconds);
}

void ADMFTargetingPresentationActor::UpdateActivePartnerPresentation(ADMFDigimonCharacter* ActivePartner, const float DeltaSeconds)
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bCanShow = Settings
        && Settings->bShowActivePartnerTargetingRing
        && IsValid(ActivePartner)
        && ActivePartnerRingSprite
        && ActivePartnerRingSprite->GetSprite();

    PresentedActivePartner = ActivePartner;
    ActivePartnerRingSprite->SetVisibility(bCanShow, true);
    if (!bCanShow)
    {
        return;
    }

    ActivePartnerRingYaw = FMath::Fmod(
        ActivePartnerRingYaw + (Settings->ActivePartnerTargetingRingRotationDegreesPerSecond * DeltaSeconds),
        360.0f);

    ActivePartnerRingPivot->SetWorldLocation(ResolveGroundMarkerLocation(*ActivePartner, Settings->ActivePartnerTargetingRingGroundOffset));
    ActivePartnerRingPivot->SetWorldRotation(FRotator(0.0f, ActivePartnerRingYaw, 0.0f));

    const float CapsuleScale = ResolveCapsuleScaleMultiplier(*ActivePartner);
    ActivePartnerRingSprite->SetRelativeScale3D(Settings->ActivePartnerTargetingRingScale * CapsuleScale);
}

void ADMFTargetingPresentationActor::UpdateCommandTargetPresentation(ADMFDigimonCharacter* CommandTarget, const float DeltaSeconds)
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bTargetChanged = PresentedCommandTarget.Get() != CommandTarget;
    PresentedCommandTarget = CommandTarget;

    const bool bRingCanShow = Settings
        && Settings->bShowEnemyTargetingRing
        && IsValid(CommandTarget)
        && EnemyTargetRingSprite
        && EnemyTargetRingSprite->GetSprite();

    EnemyTargetRingSprite->SetVisibility(bRingCanShow, true);
    if (bRingCanShow)
    {
        EnemyTargetRingYaw = FMath::Fmod(
            EnemyTargetRingYaw + (Settings->EnemyTargetingRingRotationDegreesPerSecond * DeltaSeconds),
            360.0f);

        EnemyTargetRingPivot->SetWorldLocation(ResolveGroundMarkerLocation(*CommandTarget, Settings->EnemyTargetingRingGroundOffset));
        EnemyTargetRingPivot->SetWorldRotation(FRotator(0.0f, EnemyTargetRingYaw, 0.0f));

        const float CapsuleScale = ResolveCapsuleScaleMultiplier(*CommandTarget);
        EnemyTargetRingSprite->SetRelativeScale3D(Settings->EnemyTargetingRingScale * CapsuleScale);
    }

    const bool bArrowCanShow = Settings && Settings->bShowEnemyTargetArrow && IsValid(CommandTarget);
    UpdateArrowActivation(bArrowCanShow, bTargetChanged);
    if (!bArrowCanShow)
    {
        return;
    }

    const float BobOffset = Settings->EnemyTargetArrowBobAmplitude > 0.0f && Settings->EnemyTargetArrowBobFrequencyHz > 0.0f
        ? FMath::Sin(LocalPresentationTime * Settings->EnemyTargetArrowBobFrequencyHz * 2.0f * UE_PI) * Settings->EnemyTargetArrowBobAmplitude
        : 0.0f;

    const FVector ArrowLocation = ResolveArrowLocation(*CommandTarget, Settings->EnemyTargetArrowHeightOffset, BobOffset);
    if (bUseNiagaraArrow && bHasNiagaraArrowAsset)
    {
        EnemyTargetArrowNiagara->SetWorldLocation(ArrowLocation);
        EnemyTargetArrowNiagara->SetWorldRotation(Settings->EnemyTargetArrowRotation);
        EnemyTargetArrowNiagara->SetWorldScale3D(Settings->EnemyTargetArrowScale);
    }
    else if (bHasCascadeArrowAsset)
    {
        EnemyTargetArrowCascade->SetWorldLocation(ArrowLocation);
        EnemyTargetArrowCascade->SetWorldRotation(Settings->EnemyTargetArrowRotation);
        EnemyTargetArrowCascade->SetWorldScale3D(Settings->EnemyTargetArrowScale);
    }
}

void ADMFTargetingPresentationActor::UpdateArrowActivation(const bool bShouldBeActive, const bool bTargetChanged)
{
    const bool bPreviouslyActive = bArrowPresentationActive;
    bArrowPresentationActive = bShouldBeActive;

    if (!bShouldBeActive)
    {
        EnemyTargetArrowNiagara->DeactivateImmediate();
        EnemyTargetArrowNiagara->SetVisibility(false, true);
        EnemyTargetArrowCascade->DeactivateSystem();
        EnemyTargetArrowCascade->SetVisibility(false, true);
        return;
    }

    if (bUseNiagaraArrow && bHasNiagaraArrowAsset)
    {
        EnemyTargetArrowNiagara->SetRenderCustomDepth(true);
        EnemyTargetArrowCascade->DeactivateSystem();
        EnemyTargetArrowCascade->SetVisibility(false, true);
        EnemyTargetArrowNiagara->SetVisibility(true, true);
        if (!bPreviouslyActive || bTargetChanged || !EnemyTargetArrowNiagara->IsActive())
        {
            EnemyTargetArrowNiagara->Activate(true);
        }
        return;
    }

    if (bHasCascadeArrowAsset)
    {
        EnemyTargetArrowCascade->SetRenderCustomDepth(true);
        EnemyTargetArrowNiagara->DeactivateImmediate();
        EnemyTargetArrowNiagara->SetVisibility(false, true);
        EnemyTargetArrowCascade->SetVisibility(true, true);
        if (!bPreviouslyActive || bTargetChanged || !EnemyTargetArrowCascade->IsActive())
        {
            EnemyTargetArrowCascade->ActivateSystem(true);
        }
        return;
    }

    EnemyTargetArrowNiagara->SetVisibility(false, true);
    EnemyTargetArrowCascade->SetVisibility(false, true);
}

FVector ADMFTargetingPresentationActor::ResolveGroundMarkerLocation(const ADMFDigimonCharacter& Digimon, const float GroundOffset) const
{
    FVector Result = Digimon.GetActorLocation();
    if (const UCapsuleComponent* Capsule = Digimon.GetCapsuleComponent())
    {
        Result.Z -= Capsule->GetScaledCapsuleHalfHeight();
    }
    else
    {
        FVector BoundsOrigin = FVector::ZeroVector;
        FVector BoundsExtent = FVector::ZeroVector;
        Digimon.GetActorBounds(true, BoundsOrigin, BoundsExtent, false);
        Result.Z = BoundsOrigin.Z - BoundsExtent.Z;
    }
    Result.Z += GroundOffset;
    return Result;
}

FVector ADMFTargetingPresentationActor::ResolveArrowLocation(const ADMFDigimonCharacter& Digimon, const float HeightOffset, const float BobOffset) const
{
    FVector Result = Digimon.GetActorLocation();
    if (const UCapsuleComponent* Capsule = Digimon.GetCapsuleComponent())
    {
        Result.Z += Capsule->GetScaledCapsuleHalfHeight();
    }
    else
    {
        FVector BoundsOrigin = FVector::ZeroVector;
        FVector BoundsExtent = FVector::ZeroVector;
        Digimon.GetActorBounds(true, BoundsOrigin, BoundsExtent, false);
        Result.Z = BoundsOrigin.Z + BoundsExtent.Z;
    }
    Result.Z += HeightOffset + BobOffset;
    return Result;
}

float ADMFTargetingPresentationActor::ResolveCapsuleScaleMultiplier(const ADMFDigimonCharacter& Digimon) const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bScaleTargetingRingsToDigimonCapsule)
    {
        return 1.0f;
    }

    const UCapsuleComponent* Capsule = Digimon.GetCapsuleComponent();
    if (!Capsule)
    {
        return 1.0f;
    }

    const float ReferenceRadius = FMath::Max(1.0f, Settings->TargetingRingReferenceCapsuleRadius);
    return FMath::Clamp(
        Capsule->GetScaledCapsuleRadius() / ReferenceRadius,
        Settings->TargetingRingMinimumAutoScale,
        Settings->TargetingRingMaximumAutoScale);
}

void ADMFTargetingPresentationActor::HideAllPresentation()
{
    PresentedActivePartner.Reset();
    PresentedCommandTarget.Reset();

    if (ActivePartnerRingSprite)
    {
        ActivePartnerRingSprite->SetVisibility(false, true);
    }
    if (EnemyTargetRingSprite)
    {
        EnemyTargetRingSprite->SetVisibility(false, true);
    }
    if (EnemyTargetArrowNiagara)
    {
        EnemyTargetArrowNiagara->DeactivateImmediate();
        EnemyTargetArrowNiagara->SetVisibility(false, true);
    }
    if (EnemyTargetArrowCascade)
    {
        EnemyTargetArrowCascade->DeactivateSystem();
        EnemyTargetArrowCascade->SetVisibility(false, true);
    }
    bArrowPresentationActive = false;
}
