#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFPlayerState.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Net/UnrealNetwork.h"
#include "Engine/AssetManager.h"
#include "AIController.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Components/CapsuleComponent.h"
#include "Components/MeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"

ADMFDigimonCharacter::ADMFDigimonCharacter()
{
    bReplicates = true;
    SetReplicateMovement(true);
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass();
    if (UCapsuleComponent* Capsule = GetCapsuleComponent())
    {
        // The default native target-selection helper uses a visibility trace. Make the framework
        // Digimon capsule explicitly targetable without requiring a project-specific collision preset.
        Capsule->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    }
    CombatComponent = CreateDefaultSubobject<UDMFDigimonCombatComponent>(TEXT("CombatComponent"));

    // Make the inherited skeletal mesh cel-shading-ready even on the CDO/Blueprint defaults.
    GetMesh()->SetRenderCustomDepth(true);
}

void ADMFDigimonCharacter::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    RefreshFrameworkCustomDepth();
}

void ADMFDigimonCharacter::BeginPlay()
{
    Super::BeginPlay();
    RefreshFrameworkCustomDepth();

    // Combat state replication is the durable source of truth for defeated presentation.
    // This also covers actors that begin play already defeated in a future gameplay mode.
    if (CombatComponent && CombatComponent->IsDefeated())
    {
        ApplyDefeatedPresentation();
    }
}

void ADMFDigimonCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(DefeatedPoseHoldTimer);
        World->GetTimerManager().ClearTimer(CombatFacingTimer);
    }
    Super::EndPlay(EndPlayReason);
}

void ADMFDigimonCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFDigimonCharacter, DigimonInstanceId);
    DOREPLIFETIME(ADMFDigimonCharacter, SpeciesId);
    DOREPLIFETIME(ADMFDigimonCharacter, ReplicatedStats);
    DOREPLIFETIME(ADMFDigimonCharacter, ReplicatedAbilityIds);
    DOREPLIFETIME(ADMFDigimonCharacter, OwningPlayerState);
    DOREPLIFETIME(ADMFDigimonCharacter, CombatTeamId);
}

void ADMFDigimonCharacter::InitializeFromInstance(const FDMFDigimonInstance& Instance, ADMFPlayerState* InOwningPlayerState)
{
    if (!HasAuthority())
    {
        return;
    }

    DigimonInstanceId = Instance.InstanceId;
    SpeciesId = Instance.SpeciesId;
    ReplicatedStats = Instance.Stats;
    ReplicatedAbilityIds = Instance.EquippedAbilityIds;
    OwningPlayerState = InOwningPlayerState;
    if (CombatComponent)
    {
        CombatComponent->InitializeRuntimeVitals(Instance.CurrentHP, Instance.CurrentSP);
    }
    ForceNetUpdate();
    RefreshFrameworkCustomDepth();
    BP_OnDigimonStateReady();
}

void ADMFDigimonCharacter::StartCombatFacingTarget(AActor* TargetActor)
{
    if (!HasAuthority() || !bEnableCombatFacing || !IsValid(TargetActor) || TargetActor == this)
    {
        return;
    }

    CombatFacingTarget = TargetActor;

    if (UCharacterMovementComponent* Movement = GetCharacterMovement())
    {
        if (!bCombatFacingRotationPolicyCached)
        {
            bCachedOrientRotationToMovement = Movement->bOrientRotationToMovement;
            bCachedUseControllerDesiredRotation = Movement->bUseControllerDesiredRotation;
            bCachedUseControllerRotationYaw = bUseControllerRotationYaw;
            bCombatFacingRotationPolicyCached = true;
        }

        // Combat-facing happens only once the combat component has stopped/chosen not to chase.
        // Temporarily disable movement/controller-driven yaw so neither CharacterMovement nor an AI
        // controller can immediately overwrite the authoritative turn-in-place rotation.
        Movement->bOrientRotationToMovement = false;
        Movement->bUseControllerDesiredRotation = false;
        bUseControllerRotationYaw = false;
    }

    UpdateCombatFacing();

    if (UWorld* World = GetWorld())
    {
        const float Interval = FMath::Clamp(CombatFacingUpdateInterval, 0.016f, 0.10f);
        if (!World->GetTimerManager().IsTimerActive(CombatFacingTimer))
        {
            World->GetTimerManager().SetTimer(CombatFacingTimer, this, &ADMFDigimonCharacter::UpdateCombatFacing, Interval, true, Interval);
        }
    }
}

void ADMFDigimonCharacter::StopCombatFacingTarget()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(CombatFacingTimer);
    }

    CombatFacingTarget.Reset();
    RestoreMovementRotationPolicyAfterCombatFacing();
}

bool ADMFDigimonCharacter::IsFacingActor(AActor* TargetActor) const
{
    if (!TargetActor)
    {
        return false;
    }

    FVector ToTarget = TargetActor->GetActorLocation() - GetActorLocation();
    ToTarget.Z = 0.0f;
    if (ToTarget.SizeSquared() <= KINDA_SMALL_NUMBER)
    {
        return true;
    }

    const float DesiredYaw = ToTarget.Rotation().Yaw;
    const float DeltaYaw = FMath::Abs(FMath::FindDeltaAngleDegrees(GetActorRotation().Yaw, DesiredYaw));
    return DeltaYaw <= FMath::Clamp(AttackFacingToleranceDegrees, 0.1f, 90.0f);
}

void ADMFDigimonCharacter::UpdateCombatFacing()
{
    AActor* TargetActor = CombatFacingTarget.Get();
    if (!HasAuthority() || !bEnableCombatFacing || !IsValid(TargetActor) || IsActorBeingDestroyed()
        || (CombatComponent && CombatComponent->IsDefeated()))
    {
        StopCombatFacingTarget();
        return;
    }

    FVector ToTarget = TargetActor->GetActorLocation() - GetActorLocation();
    ToTarget.Z = 0.0f;
    if (ToTarget.SizeSquared() <= KINDA_SMALL_NUMBER)
    {
        return;
    }

    const FRotator CurrentRotation = GetActorRotation();
    const float DesiredYaw = ToTarget.Rotation().Yaw;
    const float Interval = FMath::Clamp(CombatFacingUpdateInterval, 0.016f, 0.10f);
    const float MaxYawStep = FMath::Max(1.0f, CombatFacingTurnRateDegreesPerSecond) * Interval;
    const float NewYaw = FMath::FixedTurn(CurrentRotation.Yaw, DesiredYaw, MaxYawStep);

    const FRotator NewRotation(CurrentRotation.Pitch, NewYaw, CurrentRotation.Roll);
    SetActorRotation(NewRotation);

    // Keep the AI controller's desired yaw synchronized with the authoritative actor yaw. Without
    // this, controller rotation can reassert an older heading between facing updates on some AI setups.
    if (AController* DigimonController = GetController())
    {
        FRotator DesiredControlRotation = DigimonController->GetControlRotation();
        DesiredControlRotation.Yaw = NewYaw;
        DigimonController->SetControlRotation(DesiredControlRotation);
    }

    // Push the final aligned rotation promptly so the attack cue cannot visually outrun replicated yaw.
    if (FMath::Abs(FMath::FindDeltaAngleDegrees(NewYaw, DesiredYaw)) <= FMath::Clamp(AttackFacingToleranceDegrees, 0.1f, 90.0f))
    {
        ForceNetUpdate();
    }
}

void ADMFDigimonCharacter::RestoreMovementRotationPolicyAfterCombatFacing()
{
    if (!bCombatFacingRotationPolicyCached)
    {
        return;
    }

    if (UCharacterMovementComponent* Movement = GetCharacterMovement())
    {
        Movement->bOrientRotationToMovement = bCachedOrientRotationToMovement;
        Movement->bUseControllerDesiredRotation = bCachedUseControllerDesiredRotation;
    }
    bUseControllerRotationYaw = bCachedUseControllerRotationYaw;
    bCombatFacingRotationPolicyCached = false;
}


void ADMFDigimonCharacter::ApplyDefeatedPresentation()
{
    if (bDefeatedPresentationActive)
    {
        return;
    }

    bDefeatedPresentationActive = true;
    StopCombatFacingTarget();

    if (!bDefeatedPresentationStateCached)
    {
        if (UCapsuleComponent* Capsule = GetCapsuleComponent())
        {
            CachedCapsuleCollisionEnabled = Capsule->GetCollisionEnabled();
        }
        if (UCharacterMovementComponent* Movement = GetCharacterMovement())
        {
            CachedMovementMode = Movement->MovementMode;
            CachedCustomMovementMode = Movement->CustomMovementMode;
        }
        if (USkeletalMeshComponent* DigimonMesh = GetMesh())
        {
            bCachedMeshPauseAnims = DigimonMesh->bPauseAnims;
            CachedMeshGlobalAnimRateScale = DigimonMesh->GlobalAnimRateScale;
        }
        bDefeatedPresentationStateCached = true;
    }

    if (bDisableMovementWhenDefeated)
    {
        if (UCharacterMovementComponent* Movement = GetCharacterMovement())
        {
            Movement->StopMovementImmediately();
            Movement->DisableMovement();
        }
        if (HasAuthority())
        {
            if (AAIController* AI = Cast<AAIController>(GetController()))
            {
                AI->StopMovement();
            }
        }
    }

    if (bDisableCapsuleCollisionWhenDefeated)
    {
        if (UCapsuleComponent* Capsule = GetCapsuleComponent())
        {
            Capsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        }
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(DefeatedPoseHoldTimer);
    }

    ActiveDeathMontage = nullptr;
    bDefeatedPoseLocked = false;
    if (USkeletalMeshComponent* DigimonMesh = GetMesh())
    {
        // A previous defeated/revive cycle may have frozen the skeletal evaluator. The death Montage
        // must begin from a live animation evaluator, then v0.5.5 locks it at blend-out start.
        DigimonMesh->bPauseAnims = false;
        DigimonMesh->GlobalAnimRateScale = 1.0f;

        if (UDMFDigimonSpeciesData* Species = ResolveSpeciesData())
        {
            if (UAnimMontage* DeathMontage = Species->DeathMontage.LoadSynchronous())
            {
                if (UAnimInstance* AnimInstance = DigimonMesh->GetAnimInstance())
                {
                    // Stop any attack/victory Montage before assigning the new death Montage as the
                    // active presentation. This avoids a stale Montage callback ever being mistaken
                    // for the new defeated-pose lifecycle.
                    AnimInstance->Montage_Stop(0.05f);
                    ActiveDeathMontage = DeathMontage;
                    const float PlayRate = FMath::Max(0.05f, DefeatedMontagePlayRate);

                    const float PlayedDuration = AnimInstance->Montage_Play(DeathMontage, PlayRate);
                    if (PlayedDuration > 0.0f)
                    {
                        // The old implementation waited for a timer near Montage end. That can be too
                        // late because Unreal starts Montage blend-out before GetPlayLength() ends.
                        // Freeze at the actual blend-out boundary instead, while the death pose still
                        // owns the skeletal output.
                        FOnMontageBlendingOutStarted BlendOutDelegate;
                        BlendOutDelegate.BindUObject(this, &ADMFDigimonCharacter::HandleDeathMontageBlendingOut);
                        AnimInstance->Montage_SetBlendingOutDelegate(BlendOutDelegate, DeathMontage);

                        FOnMontageEnded EndDelegate;
                        EndDelegate.BindUObject(this, &ADMFDigimonCharacter::HandleDeathMontageEnded);
                        AnimInstance->Montage_SetEndDelegate(EndDelegate, DeathMontage);

                        if (GetWorld())
                        {
                            // Failsafe only. Normal non-looping death Montages are locked by the
                            // blend-out delegate first. This covers looping/atypical Montage assets.
                            const float NormalizedHold = FMath::Clamp(DefeatedPoseHoldNormalizedTime, 0.50f, 0.999f);
                            const float HoldDelay = FMath::Max(0.01f, (DeathMontage->GetPlayLength() * NormalizedHold) / PlayRate);
                            GetWorld()->GetTimerManager().SetTimer(
                                DefeatedPoseHoldTimer,
                                this,
                                &ADMFDigimonCharacter::HoldDefeatedPose,
                                HoldDelay,
                                false);
                        }
                    }
                }
            }
        }
    }

    BP_OnDefeatedPresentationStarted();
}

void ADMFDigimonCharacter::HoldDefeatedPose()
{
    // Failsafe for looping/unusual death Montages that never enter normal blend-out.
    LockDefeatedPose();
}

void ADMFDigimonCharacter::HandleDeathMontageBlendingOut(UAnimMontage* Montage, const bool bInterrupted)
{
    if (!bDefeatedPresentationActive || bDefeatedPoseLocked || Montage != ActiveDeathMontage.Get())
    {
        return;
    }

    // A genuine external interruption should not let locomotion reclaim a defeated Digimon either.
    // The replicated Defeated combat state remains authoritative, so lock whatever final death pose
    // is currently being presented.
    LockDefeatedPose();
}

void ADMFDigimonCharacter::HandleDeathMontageEnded(UAnimMontage* Montage, const bool bInterrupted)
{
    if (!bDefeatedPresentationActive || bDefeatedPoseLocked || Montage != ActiveDeathMontage.Get())
    {
        return;
    }

    // Defensive fallback. Normally HandleDeathMontageBlendingOut executes first.
    LockDefeatedPose();
}

void ADMFDigimonCharacter::LockDefeatedPose()
{
    if (bDefeatedPoseLocked || !bDefeatedPresentationActive || !CombatComponent || !CombatComponent->IsDefeated())
    {
        return;
    }

    USkeletalMeshComponent* DigimonMesh = GetMesh();
    UAnimMontage* DeathMontage = ActiveDeathMontage.Get();
    UAnimInstance* AnimInstance = DigimonMesh ? DigimonMesh->GetAnimInstance() : nullptr;
    if (!DigimonMesh || !DeathMontage || !AnimInstance)
    {
        return;
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(DefeatedPoseHoldTimer);
    }

    // Freeze the Montage instance first so its slot cannot progress into locomotion blend-out, then
    // freeze skeletal animation evaluation itself. GlobalAnimRateScale=0 is intentional redundancy:
    // it prevents a project AnimBP from advancing even if it changes bPauseAnims later in the frame.
    AnimInstance->Montage_SetPlayRate(DeathMontage, 0.0f);
    AnimInstance->Montage_Pause(DeathMontage);
    DigimonMesh->GlobalAnimRateScale = 0.0f;
    DigimonMesh->bPauseAnims = true;
    bDefeatedPoseLocked = true;
}

void ADMFDigimonCharacter::ClearDefeatedPresentation()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(DefeatedPoseHoldTimer);
    }

    if (!bDefeatedPresentationActive)
    {
        return;
    }

    // Drop the defeated flag before stopping the Montage. Montage_Stop can synchronously invoke the
    // blend-out callback; the callback must see that this is a legitimate revive/clear operation and
    // must not re-lock the pose.
    bDefeatedPresentationActive = false;
    bDefeatedPoseLocked = false;

    if (USkeletalMeshComponent* DigimonMesh = GetMesh())
    {
        DigimonMesh->bPauseAnims = false;
        DigimonMesh->GlobalAnimRateScale = 1.0f;
        if (UAnimInstance* AnimInstance = DigimonMesh->GetAnimInstance())
        {
            if (ActiveDeathMontage)
            {
                AnimInstance->Montage_SetPlayRate(ActiveDeathMontage.Get(), 1.0f);
                AnimInstance->Montage_Stop(0.10f, ActiveDeathMontage.Get());
            }
        }

        if (bDefeatedPresentationStateCached)
        {
            DigimonMesh->bPauseAnims = bCachedMeshPauseAnims;
            DigimonMesh->GlobalAnimRateScale = CachedMeshGlobalAnimRateScale;
        }
    }
    ActiveDeathMontage = nullptr;

    if (bDefeatedPresentationStateCached)
    {
        if (UCapsuleComponent* Capsule = GetCapsuleComponent())
        {
            Capsule->SetCollisionEnabled(CachedCapsuleCollisionEnabled);
        }
        if (bDisableMovementWhenDefeated)
        {
            if (UCharacterMovementComponent* Movement = GetCharacterMovement())
            {
                Movement->SetMovementMode(CachedMovementMode, CachedCustomMovementMode);
            }
        }
    }

    bDefeatedPoseLocked = false;
    bDefeatedPresentationStateCached = false;
    BP_OnDefeatedPresentationCleared();
}

void ADMFDigimonCharacter::SetCombatTeamId(const FName NewTeamId)
{
    if (HasAuthority())
    {
        CombatTeamId = NewTeamId;
        ForceNetUpdate();
    }
}

void ADMFDigimonCharacter::ConfigureCombatAutomation(const bool bEnableAutoBattle, const float AggroRange, const float LeashRange, AActor* FollowAnchor)
{
    if (HasAuthority() && CombatComponent)
    {
        CombatComponent->ConfigureAutomation(bEnableAutoBattle, AggroRange, LeashRange, FollowAnchor);
    }
}

UDMFDigimonSpeciesData* ADMFDigimonCharacter::ResolveSpeciesData() const
{
    if (!SpeciesId.IsValid())
    {
        return nullptr;
    }

    UAssetManager& AssetManager = UAssetManager::Get();
    if (UDMFDigimonSpeciesData* Loaded = AssetManager.GetPrimaryAssetObject<UDMFDigimonSpeciesData>(SpeciesId))
    {
        return Loaded;
    }
    const FSoftObjectPath Path = AssetManager.GetPrimaryAssetPath(SpeciesId);
    return Path.IsValid() ? Cast<UDMFDigimonSpeciesData>(Path.TryLoad()) : nullptr;
}

void ADMFDigimonCharacter::RefreshFrameworkCustomDepth()
{
    TArray<UMeshComponent*> MeshComponents;
    GetComponents<UMeshComponent>(MeshComponents);

    const int32 StencilValue = FMath::Clamp(CustomDepthStencilValue, 0, 255);
    for (UMeshComponent* MeshComponent : MeshComponents)
    {
        if (!IsValid(MeshComponent))
        {
            continue;
        }

        MeshComponent->SetRenderCustomDepth(true);
        MeshComponent->SetCustomDepthStencilValue(StencilValue);
    }
}

void ADMFDigimonCharacter::OnRep_DigimonState()
{
    RefreshFrameworkCustomDepth();

    // SpeciesId can arrive after CombatState on a joining client. Re-applying here is idempotent
    // and guarantees a defeated actor can still resolve and display its species Death Montage.
    if (CombatComponent && CombatComponent->IsDefeated())
    {
        if (!bDefeatedPresentationActive || !ActiveDeathMontage)
        {
            if (bDefeatedPresentationActive)
            {
                ClearDefeatedPresentation();
            }
            ApplyDefeatedPresentation();
        }
    }

    BP_OnDigimonStateReady();
}
