#include "Components/DMFDigimonCombatComponent.h"
#include "Data/DMFDigimonAbilityData.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFAbilityProjectileActor.h"
#include "Game/DMFPlayerState.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Settings/DMFFrameworkSettings.h"
#include "Net/UnrealNetwork.h"
#include "Engine/AssetManager.h"
#include "Engine/World.h"
#include "Engine/OverlapResult.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/GameStateBase.h"
#include "AIController.h"
#include "Animation/AnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"

UDMFDigimonCombatComponent::UDMFDigimonCombatComponent()
{
    SetIsReplicatedByDefault(true);
    PrimaryComponentTick.bCanEverTick = false;
}

void UDMFDigimonCombatComponent::BeginPlay()
{
    Super::BeginPlay();
    HomeLocation = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;

    if (GetOwner() && GetOwner()->HasAuthority())
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        const float Interval = Settings ? FMath::Max(0.1f, Settings->CombatAutomationInterval) : 0.25f;
        GetWorld()->GetTimerManager().SetTimer(AutomationTimer, this, &UDMFDigimonCombatComponent::AutomationTick, Interval, true, Interval);
    }
}

void UDMFDigimonCombatComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(AutomationTimer);
        World->GetTimerManager().ClearTimer(RecoveryTimer);
    }
    Super::EndPlay(EndPlayReason);
}

void UDMFDigimonCombatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UDMFDigimonCombatComponent, CurrentHP);
    DOREPLIFETIME(UDMFDigimonCombatComponent, CurrentSP);
    DOREPLIFETIME(UDMFDigimonCombatComponent, CombatState);
    DOREPLIFETIME(UDMFDigimonCombatComponent, CurrentTarget);
    DOREPLIFETIME(UDMFDigimonCombatComponent, bBattleEncounterActive);
    DOREPLIFETIME(UDMFDigimonCombatComponent, ReplicatedCooldowns);
}

void UDMFDigimonCombatComponent::InitializeRuntimeVitals(const int32 InCurrentHP, const int32 InCurrentSP)
{
    ADMFDigimonCharacter* Digimon = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Digimon || !Digimon->HasAuthority())
    {
        return;
    }

    CurrentHP = FMath::Clamp(InCurrentHP, 0, FMath::Max(1, Digimon->ReplicatedStats.MaxHP));
    CurrentSP = FMath::Clamp(InCurrentSP, 0, FMath::Max(0, Digimon->ReplicatedStats.MaxSP));
    SetBattleEncounterActive(false);
    SetCombatState(CurrentHP > 0 ? EDMFCombatState::Idle : EDMFCombatState::Defeated);
    OnVitalsChanged.Broadcast(CurrentHP, CurrentSP);
}

void UDMFDigimonCombatComponent::ApplyAuthoritativeRuntimeVitals(const int32 InCurrentHP, const int32 InCurrentSP)
{
    ADMFDigimonCharacter* Digimon = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Digimon || !Digimon->HasAuthority())
    {
        return;
    }

    const int32 NewHP = FMath::Clamp(InCurrentHP, 0, FMath::Max(1, Digimon->ReplicatedStats.MaxHP));
    const int32 NewSP = FMath::Clamp(InCurrentSP, 0, FMath::Max(0, Digimon->ReplicatedStats.MaxSP));
    if (NewHP == CurrentHP && NewSP == CurrentSP)
    {
        return;
    }

    CurrentHP = NewHP;
    CurrentSP = NewSP;
    OnVitalsChanged.Broadcast(CurrentHP, CurrentSP);
}

void UDMFDigimonCombatComponent::RefreshRuntimeVitalsAfterProgression(const int32 InCurrentHP, const int32 InCurrentSP)
{
    ApplyAuthoritativeRuntimeVitals(InCurrentHP, InCurrentSP);
}

void UDMFDigimonCombatComponent::ConfigureAutomation(const bool bInAutoBattleEnabled, const float InAggroRange, const float InLeashRange, AActor* InFollowAnchor)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    const bool bWasAutoBattleEnabled = bAutoBattleEnabled;
    bAutoBattleEnabled = bInAutoBattleEnabled;
    AggroRange = FMath::Max(0.0f, InAggroRange);
    LeashRange = FMath::Max(AggroRange, InLeashRange);
    FollowAnchor = InFollowAnchor;
    HomeLocation = GetOwner()->GetActorLocation();

    // Turning proactive auto battle off must cancel a proactively acquired chase, but it must NOT
    // cancel a legitimate reactive fight created after this Digimon was attacked.
    if (bWasAutoBattleEnabled && !bAutoBattleEnabled && !bRetaliationCombatActive)
    {
        SetAuthoritativeTarget(nullptr);
        if (const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner()))
        {
            if (AAIController* AI = Cast<AAIController>(Self->GetController()))
            {
                AI->StopMovement();
            }
        }
    }
}

void UDMFDigimonCombatComponent::ConfigureRetaliation(const bool bInRetaliateWhenAttacked)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    bRetaliateWhenAttacked = bInRetaliateWhenAttacked;
    if (!bRetaliateWhenAttacked && bRetaliationCombatActive)
    {
        EndRetaliation();
    }
}

void UDMFDigimonCombatComponent::ConfigureDamageTuning(const float InOutgoingDamageMultiplier, const float InIncomingDamageMultiplier)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    OutgoingDamageMultiplier = FMath::Max(0.0f, InOutgoingDamageMultiplier);
    IncomingDamageMultiplier = FMath::Max(0.0f, InIncomingDamageMultiplier);
}

void UDMFDigimonCombatComponent::SetAuthoritativeTarget(ADMFDigimonCharacter* NewTarget)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || IsDefeated())
    {
        return;
    }

    if (NewTarget && !CanAttackTarget(NewTarget))
    {
        return;
    }

    if (CurrentTarget != NewTarget)
    {
        if (ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner()))
        {
            Self->StopCombatFacingTarget();
        }
        ResetAutoBattleAbilityRotation();
        CurrentTarget = NewTarget;
        if (!CurrentTarget)
        {
            bRetaliationCombatActive = false;
            SetBattleEncounterActive(false);
        }
        OnTargetChanged.Broadcast(CurrentTarget);
        GetOwner()->ForceNetUpdate();
    }
    else if (!NewTarget)
    {
        bRetaliationCombatActive = false;
        SetBattleEncounterActive(false);
    }
}


void UDMFDigimonCombatComponent::ForceAuthoritativeDisengage()
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(RecoveryTimer);
    }

    if (ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner()))
    {
        Self->StopCombatFacingTarget();
        if (AAIController* AI = Cast<AAIController>(Self->GetController()))
        {
            AI->StopMovement();
        }
    }

    const bool bTargetChanged = CurrentTarget != nullptr;
    CurrentTarget = nullptr;
    bRetaliationCombatActive = false;
    ClearQueuedCommand();
    ResetAutoBattleAbilityRotation();
    SetBattleEncounterActive(false);
    SetCombatState(EDMFCombatState::Idle);

    if (bTargetChanged)
    {
        OnTargetChanged.Broadcast(nullptr);
    }
    GetOwner()->ForceNetUpdate();
}

bool UDMFDigimonCombatComponent::CanAttackTarget(const ADMFDigimonCharacter* Candidate) const
{
    const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Candidate || Candidate == Self || Candidate->IsActorBeingDestroyed())
    {
        return false;
    }

    const UDMFDigimonCombatComponent* OtherCombat = Candidate->CombatComponent;
    if (!OtherCombat || OtherCombat->IsDefeated() || !Candidate->bCombatTargetable)
    {
        return false;
    }

    if (!Self->CombatTeamId.IsNone() && Self->CombatTeamId == Candidate->CombatTeamId)
    {
        return false;
    }

    return true;
}

float UDMFDigimonCombatComponent::GetRemainingCooldown(const FName AbilityId) const
{
    if (AbilityId.IsNone() || !GetWorld())
    {
        return 0.0f;
    }

    AGameStateBase* GameState = GetWorld()->GetGameState();
    // Authority uses its local world clock directly. Clients use GameState's synchronized server
    // clock for HUD presentation. Both represent the same server-world-time domain, but avoiding a
    // server-side replicated-time delta removes another possible source of stale cooldown gating.
    const bool bAuthority = GetOwner() && GetOwner()->HasAuthority();
    const double NetworkNow = bAuthority
        ? static_cast<double>(GetWorld()->GetTimeSeconds())
        : (GameState ? GameState->GetServerWorldTimeSeconds() : static_cast<double>(GetWorld()->GetTimeSeconds()));
    for (const FDMFAbilityCooldownState& Cooldown : ReplicatedCooldowns)
    {
        if (Cooldown.AbilityId == AbilityId)
        {
            return static_cast<float>(FMath::Max(0.0, Cooldown.EndServerTimeSeconds - NetworkNow));
        }
    }
    return 0.0f;
}

UDMFDigimonAbilityData* UDMFDigimonCombatComponent::ResolveAbilityData(const FName AbilityId) const
{
    if (AbilityId.IsNone())
    {
        return nullptr;
    }

    UAssetManager& AssetManager = UAssetManager::Get();
    const FPrimaryAssetId AssetId(TEXT("DMFDigimonAbility"), AbilityId);
    if (UDMFDigimonAbilityData* Loaded = AssetManager.GetPrimaryAssetObject<UDMFDigimonAbilityData>(AssetId))
    {
        return Loaded;
    }

    const FSoftObjectPath Path = AssetManager.GetPrimaryAssetPath(AssetId);
    if (Path.IsValid())
    {
        if (UDMFDigimonAbilityData* Loaded = Cast<UDMFDigimonAbilityData>(Path.TryLoad()))
        {
            return Loaded;
        }
    }

    const ADMFDigimonCharacter* Digimon = Cast<ADMFDigimonCharacter>(GetOwner());
    UDMFDigimonSpeciesData* Species = Digimon ? Digimon->ResolveSpeciesData() : nullptr;
    if (Species)
    {
        if (UDMFDigimonAbilityData* Basic = Species->BasicAutoAttack.LoadSynchronous())
        {
            if (Basic->GetPrimaryAssetId().PrimaryAssetName == AbilityId || Basic->AbilityId == AbilityId)
            {
                return Basic;
            }
        }
        for (const TSoftObjectPtr<UDMFDigimonAbilityData>& SoftAbility : Species->StartingAbilities)
        {
            UDMFDigimonAbilityData* Candidate = SoftAbility.LoadSynchronous();
            if (Candidate && (Candidate->AbilityId == AbilityId || Candidate->GetPrimaryAssetId().PrimaryAssetName == AbilityId))
            {
                return Candidate;
            }
        }
    }

    return nullptr;
}

float UDMFDigimonCombatComponent::GetTargetEdgeDistance2D(const ADMFDigimonCharacter* Target) const
{
    const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Target)
    {
        return TNumericLimits<float>::Max();
    }

    const float CenterDistance = FVector::Dist2D(Self->GetActorLocation(), Target->GetActorLocation());
    const UCapsuleComponent* SelfCapsule = Self->GetCapsuleComponent();
    const UCapsuleComponent* TargetCapsule = Target->GetCapsuleComponent();
    const float SelfRadius = SelfCapsule ? SelfCapsule->GetScaledCapsuleRadius() : 0.0f;
    const float TargetRadius = TargetCapsule ? TargetCapsule->GetScaledCapsuleRadius() : 0.0f;
    return FMath::Max(0.0f, CenterDistance - SelfRadius - TargetRadius);
}

bool UDMFDigimonCombatComponent::IsTargetWithinAbilityRange(const ADMFDigimonCharacter* Target, const float AbilityRange) const
{
    return Target && GetTargetEdgeDistance2D(Target) <= FMath::Max(0.0f, AbilityRange);
}

float UDMFDigimonCombatComponent::GetAbilityMoveAcceptanceRadius(const ADMFDigimonCharacter* Target, const float AbilityRange) const
{
    const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Target)
    {
        return FMath::Max(5.0f, AbilityRange * 0.75f);
    }

    const UCapsuleComponent* SelfCapsule = Self->GetCapsuleComponent();
    const UCapsuleComponent* TargetCapsule = Target->GetCapsuleComponent();
    const float SelfRadius = SelfCapsule ? SelfCapsule->GetScaledCapsuleRadius() : 0.0f;
    const float TargetRadius = TargetCapsule ? TargetCapsule->GetScaledCapsuleRadius() : 0.0f;

    // Stop comfortably inside the legal edge-to-edge ability range. bStopOnOverlap is disabled at
    // the MoveToActor call sites so UE path following does not add another agent radius on top.
    return FMath::Max(5.0f, SelfRadius + TargetRadius + FMath::Max(0.0f, AbilityRange) * 0.75f);
}

int32 UDMFDigimonCombatComponent::GetEffectiveSPCost(const UDMFDigimonAbilityData& Ability) const
{
    return FMath::Max(0, Ability.SPCost);
}

bool UDMFDigimonCombatComponent::ValidateAbilityUse(const UDMFDigimonAbilityData& Ability, ADMFDigimonCharacter* Target, FText* OutFailure) const
{
    const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || IsDefeated())
    {
        return false;
    }

    if (CombatState == EDMFCombatState::Attacking || CombatState == EDMFCombatState::Recovering)
    {
        return false;
    }

    if (CurrentSP < GetEffectiveSPCost(Ability) || GetRemainingCooldown(Ability.AbilityId.IsNone() ? Ability.GetPrimaryAssetId().PrimaryAssetName : Ability.AbilityId) > 0.0f)
    {
        return false;
    }

    if (Ability.bRequiresTarget)
    {
        if (!Target || Target->IsActorBeingDestroyed() || !Target->CombatComponent || Target->CombatComponent->IsDefeated())
        {
            return false;
        }

        if (!CanAttackTarget(Target))
        {
            return false;
        }

        if (!IsTargetWithinAbilityRange(Target, Ability.MaxRange))
        {
            return false;
        }
    }

    return true;
}

bool UDMFDigimonCombatComponent::TryExecuteAbilitySlot(const int32 SlotIndex, ADMFDigimonCharacter* RequestedTarget)
{
    ADMFDigimonCharacter* Digimon = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Digimon || !Digimon->HasAuthority() || !Digimon->ReplicatedAbilityIds.IsValidIndex(SlotIndex))
    {
        return false;
    }
    // Slot commands use the same queue/facing contract as player-issued and automation commands so
    // Blueprint callers cannot accidentally bypass target alignment and fire sideways.
    return QueueOrExecuteAbilitySlot(SlotIndex, RequestedTarget);
}

bool UDMFDigimonCombatComponent::QueueOrExecuteAbilitySlot(const int32 SlotIndex, ADMFDigimonCharacter* RequestedTarget)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Self->HasAuthority() || IsDefeated() || !Self->ReplicatedAbilityIds.IsValidIndex(SlotIndex))
    {
        return false;
    }

    const FName AbilityId = Self->ReplicatedAbilityIds[SlotIndex];
    UDMFDigimonAbilityData* Ability = ResolveAbilityData(AbilityId);
    if (!Ability)
    {
        return false;
    }

    ADMFDigimonCharacter* EffectiveTarget = RequestedTarget ? RequestedTarget : CurrentTarget.Get();
    if (Ability->bRequiresTarget && (!EffectiveTarget || !CanAttackTarget(EffectiveTarget)))
    {
        return false;
    }

    if (Ability->bRequiresTarget && EffectiveTarget)
    {
        const FVector AnchorLocation = FollowAnchor.IsValid() ? FollowAnchor->GetActorLocation() : HomeLocation;
        if (FVector::DistSquared(EffectiveTarget->GetActorLocation(), AnchorLocation) > FMath::Square(FMath::Max(0.0f, LeashRange)))
        {
            return false;
        }
    }

    const FName EffectiveAbilityId = Ability->AbilityId.IsNone() ? Ability->GetPrimaryAssetId().PrimaryAssetName : Ability->AbilityId;
    const int32 EffectiveSPCost = GetEffectiveSPCost(*Ability);
    if (CurrentSP < EffectiveSPCost)
    {
        // SP does not currently regenerate automatically, so this is a permanent rejection rather
        // than a useful buffered command. Importantly, SP is never deducted merely for queuing.
        return false;
    }

    PruneExpiredCooldowns();
    const float RemainingCooldown = GetRemainingCooldown(EffectiveAbilityId);
    const bool bBusy = CombatState == EDMFCombatState::Attacking || CombatState == EDMFCombatState::Recovering;

    // A button press during attack recovery/cooldown is still player intent. Buffer the latest
    // command rather than silently discarding it. This is especially important for SP-cost moves,
    // which otherwise look like they work once and then become unresponsive.
    if (bBusy || RemainingCooldown > KINDA_SMALL_NUMBER)
    {
        if (Ability->bRequiresTarget && EffectiveTarget)
        {
            SetAuthoritativeTarget(EffectiveTarget);
        }
        const float TimingWait = FMath::Max(
            RemainingCooldown,
            FMath::Max(0.0f, Ability->ImpactDelaySeconds) + FMath::Max(0.0f, Ability->RecoverySeconds));
        QueueAbilityCommand(EffectiveAbilityId, EffectiveTarget, *Ability, TimingWait);
        return true;
    }

    const bool bInAbilityRange = !Ability->bRequiresTarget
        || IsTargetWithinAbilityRange(EffectiveTarget, Ability->MaxRange);

    if (bInAbilityRange)
    {
        if (Ability->bRequiresTarget && EffectiveTarget && Self->bEnableCombatFacing)
        {
            SetAuthoritativeTarget(EffectiveTarget);
            if (AAIController* AI = Cast<AAIController>(Self->GetController()))
            {
                AI->StopMovement();
            }
            Self->StartCombatFacingTarget(EffectiveTarget);
            if (Self->bRequireFacingBeforeAttack && !Self->IsFacingActor(EffectiveTarget))
            {
                QueueAbilityCommand(EffectiveAbilityId, EffectiveTarget, *Ability);
                return true;
            }
        }

        // Do not destroy the current command until execution has actually succeeded. If a transient
        // state changes between validation and execution, retain it for the automation retry.
        const bool bExecuted = TryExecuteAbilityById(EffectiveAbilityId, EffectiveTarget);
        if (bExecuted)
        {
            ClearQueuedCommand();
            return true;
        }

        QueueAbilityCommand(EffectiveAbilityId, EffectiveTarget, *Ability);
        return true;
    }

    Self->StopCombatFacingTarget();
    QueueAbilityCommand(EffectiveAbilityId, EffectiveTarget, *Ability);
    SetAuthoritativeTarget(EffectiveTarget);
    SetCombatState(EDMFCombatState::Chasing);
    if (AAIController* AI = Cast<AAIController>(Self->GetController()))
    {
        AI->MoveToActor(EffectiveTarget, GetAbilityMoveAcceptanceRadius(EffectiveTarget, Ability->MaxRange), true, true, true, nullptr, false);
    }
    return true;
}

bool UDMFDigimonCombatComponent::TryExecuteAbilityById(const FName AbilityId, ADMFDigimonCharacter* RequestedTarget)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Self->HasAuthority())
    {
        return false;
    }

    UDMFDigimonAbilityData* Ability = ResolveAbilityData(AbilityId);
    if (!Ability)
    {
        return false;
    }

    ADMFDigimonCharacter* EffectiveTarget = RequestedTarget ? RequestedTarget : CurrentTarget.Get();
    if (!ValidateAbilityUse(*Ability, EffectiveTarget))
    {
        return false;
    }

    if (Ability->bRequiresTarget && EffectiveTarget)
    {
        SetAuthoritativeTarget(EffectiveTarget);
    }

    if (Ability->bRequiresTarget && EffectiveTarget && Self->bEnableCombatFacing)
    {
        Self->StartCombatFacingTarget(EffectiveTarget);
        if (Self->bRequireFacingBeforeAttack && !Self->IsFacingActor(EffectiveTarget))
        {
            // Direct callers are prevented from firing sideways. QueueOrExecute/automation will retry
            // after the bounded server-facing loop reaches tolerance.
            return false;
        }
    }

    const FName EffectiveAbilityId = Ability->AbilityId.IsNone() ? Ability->GetPrimaryAssetId().PrimaryAssetName : Ability->AbilityId;
    CurrentSP = FMath::Clamp(CurrentSP - GetEffectiveSPCost(*Ability), 0, FMath::Max(0, Self->ReplicatedStats.MaxSP));
    const double NetworkNow = static_cast<double>(GetWorld()->GetTimeSeconds());
    FDMFAbilityCooldownState* Cooldown = ReplicatedCooldowns.FindByPredicate([EffectiveAbilityId](const FDMFAbilityCooldownState& Entry)
    {
        return Entry.AbilityId == EffectiveAbilityId;
    });
    if (!Cooldown)
    {
        Cooldown = &ReplicatedCooldowns.AddDefaulted_GetRef();
        Cooldown->AbilityId = EffectiveAbilityId;
    }
    Cooldown->EndServerTimeSeconds = NetworkNow + FMath::Max(0.0f, Ability->CooldownSeconds);
    SetCombatState(EDMFCombatState::Attacking);
    OnVitalsChanged.Broadcast(CurrentHP, CurrentSP);
    OnAbilityExecuted.Broadcast(EffectiveAbilityId, EffectiveTarget);
    MulticastPlayAbilityCue(EffectiveAbilityId, EffectiveTarget);

    const float ImpactDelay = FMath::Max(0.0f, Ability->ImpactDelaySeconds);
    const bool bProjectileExecution = Ability->ExecutionMode == EDMFAbilityExecutionMode::Projectile;
    if (ImpactDelay <= KINDA_SMALL_NUMBER)
    {
        if (bProjectileExecution)
        {
            SpawnAuthoritativeProjectile(EffectiveAbilityId, EffectiveTarget);
        }
        else
        {
            ApplyAbilityImpact(EffectiveAbilityId, EffectiveTarget);
        }
    }
    else
    {
        TWeakObjectPtr<UDMFDigimonCombatComponent> WeakThis(this);
        TWeakObjectPtr<ADMFDigimonCharacter> WeakTarget(EffectiveTarget);
        FTimerHandle OneShot;
        GetWorld()->GetTimerManager().SetTimer(OneShot, FTimerDelegate::CreateLambda([WeakThis, WeakTarget, EffectiveAbilityId, bProjectileExecution]()
        {
            if (WeakThis.IsValid())
            {
                if (bProjectileExecution)
                {
                    WeakThis->SpawnAuthoritativeProjectile(EffectiveAbilityId, WeakTarget);
                }
                else
                {
                    WeakThis->ApplyAbilityImpact(EffectiveAbilityId, WeakTarget);
                }
            }
        }), ImpactDelay, false);
    }

    // Recovery is the caster's animation/action lock. Projectile flight continues independently after launch.
    const float RecoveryDelay = FMath::Max(0.01f, ImpactDelay + FMath::Max(0.0f, Ability->RecoverySeconds));
    GetWorld()->GetTimerManager().SetTimer(RecoveryTimer, this, &UDMFDigimonCombatComponent::FinishRecovery, RecoveryDelay, false);
    Self->ForceNetUpdate();
    return true;
}

int32 UDMFDigimonCombatComponent::CalculateDamage(const UDMFDigimonAbilityData& Ability, const ADMFDigimonCharacter& Target) const
{
    const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self)
    {
        return 0;
    }

    const float AttackStat = Ability.ScalingStat == EDMFDamageScaling::Intelligence
        ? static_cast<float>(Self->ReplicatedStats.Intelligence)
        : static_cast<float>(Self->ReplicatedStats.Strength);
    const float RawDamage = FMath::Max(0.0f, Ability.BasePower + AttackStat * Ability.StatScaling);
    const float Defense = FMath::Max(0.0f, static_cast<float>(Target.ReplicatedStats.Defense) * Ability.DefenseScaling);
    const float MitigationMultiplier = 100.0f / (100.0f + Defense);
    const float TargetIncomingMultiplier = Target.CombatComponent
        ? FMath::Max(0.0f, Target.CombatComponent->GetIncomingDamageMultiplier())
        : 1.0f;
    const float TunedDamage = RawDamage * MitigationMultiplier
        * FMath::Max(0.0f, OutgoingDamageMultiplier)
        * TargetIncomingMultiplier;
    return FMath::Max(1, FMath::RoundToInt(TunedDamage));
}

void UDMFDigimonCombatComponent::ApplyAbilityImpact(const FName AbilityId, TWeakObjectPtr<ADMFDigimonCharacter> Target)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    ADMFDigimonCharacter* TargetDigimon = Target.Get();
    if (!Self || !Self->HasAuthority() || IsDefeated())
    {
        return;
    }

    UDMFDigimonAbilityData* Ability = ResolveAbilityData(AbilityId);
    if (!Ability)
    {
        SetCombatState(EDMFCombatState::Recovering);
        return;
    }

    if (Ability->bRequiresTarget)
    {
        if (!TargetDigimon || !CanAttackTarget(TargetDigimon))
        {
            SetCombatState(EDMFCombatState::Recovering);
            return;
        }

        // Recheck range at authoritative impact time. A target that escaped is not hit.
        if (!IsTargetWithinAbilityRange(TargetDigimon, Ability->MaxRange))
        {
            SetCombatState(EDMFCombatState::Recovering);
            return;
        }

        const int32 Damage = CalculateDamage(*Ability, *TargetDigimon);
        TargetDigimon->CombatComponent->ApplyAuthoritativeDamage(Damage, Self);
    }

    if (!IsDefeated())
    {
        SetCombatState(EDMFCombatState::Recovering);
    }
}


void UDMFDigimonCombatComponent::SpawnAuthoritativeProjectile(const FName AbilityId, TWeakObjectPtr<ADMFDigimonCharacter> Target)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    ADMFDigimonCharacter* TargetDigimon = Target.Get();
    UWorld* World = GetWorld();
    if (!Self || !Self->HasAuthority() || !World || IsDefeated())
    {
        return;
    }

    UDMFDigimonAbilityData* Ability = ResolveAbilityData(AbilityId);
    if (!Ability || Ability->ExecutionMode != EDMFAbilityExecutionMode::Projectile)
    {
        return;
    }

    if (Ability->bRequiresTarget && (!TargetDigimon || !CanAttackTarget(TargetDigimon)))
    {
        return;
    }

    const FName LaunchSocket = !Ability->ProjectileSpawnSocketName.IsNone()
        ? Ability->ProjectileSpawnSocketName
        : Ability->VFXSocketName;

    FTransform LaunchTransform = Self->GetActorTransform();
    if (!LaunchSocket.IsNone() && Self->GetMesh() && Self->GetMesh()->DoesSocketExist(LaunchSocket))
    {
        LaunchTransform = Self->GetMesh()->GetSocketTransform(LaunchSocket, RTS_World);
    }

    const FVector SpawnLocation = LaunchTransform.TransformPosition(Ability->ProjectileSpawnOffset);
    const FVector AimPoint = TargetDigimon
        ? TargetDigimon->GetActorLocation() + Ability->ProjectileTargetOffset
        : SpawnLocation + Self->GetActorForwardVector() * FMath::Max(100.0f, Ability->MaxRange);
    FVector InitialDirection = (AimPoint - SpawnLocation).GetSafeNormal();
    if (InitialDirection.IsNearlyZero())
    {
        InitialDirection = Self->GetActorForwardVector().GetSafeNormal();
    }

    TSubclassOf<ADMFAbilityProjectileActor> ProjectileClass = ADMFAbilityProjectileActor::StaticClass();
    if (UClass* AuthoredClass = Ability->ProjectileClass.LoadSynchronous())
    {
        if (AuthoredClass->IsChildOf(ADMFAbilityProjectileActor::StaticClass()))
        {
            ProjectileClass = AuthoredClass;
        }
    }

    const FTransform SpawnTransform(InitialDirection.Rotation(), SpawnLocation);
    ADMFAbilityProjectileActor* Projectile = World->SpawnActorDeferred<ADMFAbilityProjectileActor>(
        ProjectileClass, SpawnTransform, Self, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
    if (!Projectile)
    {
        return;
    }

    Projectile->InitializeProjectile(AbilityId, Self, TargetDigimon, InitialDirection);
    UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);
}

void UDMFDigimonCombatComponent::HandleAuthoritativeProjectileImpact(const FName AbilityId, ADMFDigimonCharacter* Target, const FVector& ImpactLocation)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Self->HasAuthority() || IsDefeated())
    {
        return;
    }

    UDMFDigimonAbilityData* Ability = ResolveAbilityData(AbilityId);
    if (!Ability || Ability->ExecutionMode != EDMFAbilityExecutionMode::Projectile)
    {
        return;
    }

    // Range was validated when the cast was accepted. Projectile damage is now gated by actual
    // authoritative arrival instead of a second cast-range check, so a moving target can be hit by
    // a projectile that visibly reaches it.
    if (Ability->bRequiresTarget)
    {
        if (!Target || !CanAttackTarget(Target) || !Target->CombatComponent)
        {
            return;
        }

        const int32 Damage = CalculateDamage(*Ability, *Target);
        Target->CombatComponent->ApplyAuthoritativeDamage(Damage, Self);
    }

    MulticastPlayProjectileImpactCue(AbilityId, ImpactLocation);
}

void UDMFDigimonCombatComponent::SpawnTransientAbilityVFX(const UDMFDigimonAbilityData& Ability, ADMFDigimonCharacter* Target)
{
    if (GetNetMode() == NM_DedicatedServer)
    {
        return;
    }
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    UWorld* World = GetWorld();
    if (!Self || !World)
    {
        return;
    }

    UParticleSystem* Cascade = Ability.CascadeParticle.LoadSynchronous();
    UNiagaraSystem* Niagara = Ability.NiagaraParticle.LoadSynchronous();

    // Preserve the original species Attack1/Attack2 presentation fallback for legacy content.
    if ((!Cascade || !Niagara) && Self->ResolveSpeciesData())
    {
        UDMFDigimonSpeciesData* Species = Self->ResolveSpeciesData();
        const FName EffectiveId = Ability.AbilityId.IsNone() ? Ability.GetPrimaryAssetId().PrimaryAssetName : Ability.AbilityId;
        const int32 SlotIndex = Self->ReplicatedAbilityIds.IndexOfByKey(EffectiveId);
        if (SlotIndex == 0)
        {
            if (!Cascade) Cascade = Species->Attack1CascadeParticle.LoadSynchronous();
            if (!Niagara) Niagara = Species->Attack1NiagaraParticle.LoadSynchronous();
        }
        else if (SlotIndex == 1)
        {
            if (!Cascade) Cascade = Species->Attack2CascadeParticle.LoadSynchronous();
            if (!Niagara) Niagara = Species->Attack2NiagaraParticle.LoadSynchronous();
        }
    }

    if (!Cascade && !Niagara)
    {
        return;
    }

    FVector FXLocation = Ability.bSpawnVFXAtTarget && Target ? Target->GetActorLocation() : Self->GetActorLocation();
    FRotator FXRotation = Self->GetActorRotation();
    if (!Ability.bSpawnVFXAtTarget && !Ability.VFXSocketName.IsNone() && Self->GetMesh() && Self->GetMesh()->DoesSocketExist(Ability.VFXSocketName))
    {
        const FTransform SocketTransform = Self->GetMesh()->GetSocketTransform(Ability.VFXSocketName, RTS_World);
        FXLocation = SocketTransform.GetLocation();
        FXRotation = SocketTransform.Rotator();
    }

    if (Target)
    {
        const FVector ToTarget = (Target->GetActorLocation() - FXLocation).GetSafeNormal();
        if (!ToTarget.IsNearlyZero())
        {
            FXRotation = ToTarget.Rotation();
        }
    }
    FXRotation = (FXRotation.Quaternion() * Ability.PresentationVFXRotationOffset.Quaternion()).Rotator();

    const float Lifetime = FMath::Clamp(Ability.PresentationVFXLifetimeSeconds, 0.05f, 30.0f);

    if (Niagara)
    {
        if (UNiagaraComponent* Component = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            this, Niagara, FXLocation, FXRotation, Ability.PresentationVFXScale, true, true, ENCPoolMethod::None, true))
        {
            // Framework-owned attack VFX must always participate in CustomDepth so project post-process
            // materials can render combat particles consistently regardless of the authored Niagara asset.
            Component->SetRenderCustomDepth(true);

            TWeakObjectPtr<UNiagaraComponent> WeakComponent(Component);
            FTimerHandle CleanupTimer;
            World->GetTimerManager().SetTimer(CleanupTimer, FTimerDelegate::CreateLambda([WeakComponent]()
            {
                if (WeakComponent.IsValid())
                {
                    WeakComponent->Deactivate();
                    WeakComponent->DestroyComponent();
                }
            }), Lifetime, false);
        }
    }
    else if (Cascade)
    {
        if (UParticleSystemComponent* Component = UGameplayStatics::SpawnEmitterAtLocation(
            this, Cascade, FXLocation, FXRotation, Ability.PresentationVFXScale, true, EPSCPoolMethod::None, true))
        {
            // Cascade fallback follows the same invariant as Niagara: every runtime attack particle
            // component is forced into the CustomDepth pass immediately after it is spawned.
            Component->SetRenderCustomDepth(true);

            TWeakObjectPtr<UParticleSystemComponent> WeakComponent(Component);
            FTimerHandle CleanupTimer;
            World->GetTimerManager().SetTimer(CleanupTimer, FTimerDelegate::CreateLambda([WeakComponent]()
            {
                if (WeakComponent.IsValid())
                {
                    WeakComponent->DeactivateSystem();
                    WeakComponent->DestroyComponent();
                }
            }), Lifetime, false);
        }
    }
}

void UDMFDigimonCombatComponent::SpawnTransientProjectileImpactVFX(const UDMFDigimonAbilityData& Ability, const FVector& ImpactLocation)
{
    if (GetNetMode() == NM_DedicatedServer)
    {
        return;
    }
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    UNiagaraSystem* Niagara = Ability.ProjectileImpactNiagaraSystem.LoadSynchronous();
    UParticleSystem* Cascade = Ability.ProjectileImpactCascadeParticle.LoadSynchronous();
    const float Lifetime = FMath::Clamp(Ability.ProjectileImpactVFXLifetimeSeconds, 0.05f, 30.0f);

    if (Niagara)
    {
        if (UNiagaraComponent* Component = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            this, Niagara, ImpactLocation, FRotator::ZeroRotator, FVector::OneVector, true, true, ENCPoolMethod::None, true))
        {
            // Framework-owned attack VFX must always participate in CustomDepth so project post-process
            // materials can render combat particles consistently regardless of the authored Niagara asset.
            Component->SetRenderCustomDepth(true);

            TWeakObjectPtr<UNiagaraComponent> WeakComponent(Component);
            FTimerHandle CleanupTimer;
            World->GetTimerManager().SetTimer(CleanupTimer, FTimerDelegate::CreateLambda([WeakComponent]()
            {
                if (WeakComponent.IsValid())
                {
                    WeakComponent->Deactivate();
                    WeakComponent->DestroyComponent();
                }
            }), Lifetime, false);
        }
    }
    else if (Cascade)
    {
        if (UParticleSystemComponent* Component = UGameplayStatics::SpawnEmitterAtLocation(
            this, Cascade, ImpactLocation, FRotator::ZeroRotator, FVector::OneVector, true, EPSCPoolMethod::None, true))
        {
            // Cascade fallback follows the same invariant as Niagara: every runtime attack particle
            // component is forced into the CustomDepth pass immediately after it is spawned.
            Component->SetRenderCustomDepth(true);

            TWeakObjectPtr<UParticleSystemComponent> WeakComponent(Component);
            FTimerHandle CleanupTimer;
            World->GetTimerManager().SetTimer(CleanupTimer, FTimerDelegate::CreateLambda([WeakComponent]()
            {
                if (WeakComponent.IsValid())
                {
                    WeakComponent->DeactivateSystem();
                    WeakComponent->DestroyComponent();
                }
            }), Lifetime, false);
        }
    }

    if (USoundBase* ImpactSound = Ability.ProjectileImpactSound.LoadSynchronous())
    {
        UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, ImpactLocation);
    }
}

int32 UDMFDigimonCombatComponent::ApplyAuthoritativeDamage(const int32 Damage, ADMFDigimonCharacter* InstigatorDigimon)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Self->HasAuthority() || IsDefeated() || Damage <= 0)
    {
        return 0;
    }

    const int32 OldHP = CurrentHP;
    CurrentHP = FMath::Clamp(CurrentHP - Damage, 0, FMath::Max(1, Self->ReplicatedStats.MaxHP));
    const int32 AppliedDamage = OldHP - CurrentHP;
    OnVitalsChanged.Broadcast(CurrentHP, CurrentSP);

    if (CurrentHP <= 0)
    {
        ClearQueuedCommand();
        ResetAutoBattleAbilityRotation();
        Self->StopCombatFacingTarget();
        bRetaliationCombatActive = false;
        SetBattleEncounterActive(false);
        SetCombatState(EDMFCombatState::Defeated);
        CurrentTarget = nullptr;
        if (AAIController* AI = Cast<AAIController>(Self->GetController()))
        {
            AI->StopMovement();
        }
        OnDefeated.Broadcast(Self, InstigatorDigimon);
        MulticastDefeatedCue(InstigatorDigimon);

        if (InstigatorDigimon && InstigatorDigimon->CombatComponent)
        {
            InstigatorDigimon->CombatComponent->NotifyAuthoritativeVictory(Self);
        }
        if (InstigatorDigimon && InstigatorDigimon->OwningPlayerState && InstigatorDigimon->OwningPlayerState->DigimonComponent)
        {
            InstigatorDigimon->OwningPlayerState->DigimonComponent->HandleAuthoritativeBattleVictory(Self);
        }
    }
    else if (AppliedDamage > 0 && bRetaliateWhenAttacked)
    {
        // Reactive combat is intentionally independent of proactive auto battle. A passive wild
        // Digimon does not scan for enemies, but once a valid hostile Digimon damages it the server
        // makes that aggressor the retaliation target and the normal automation loop handles chase,
        // per-move range, cooldown, full eligible moveset selection and leash enforcement.
        BeginRetaliation(InstigatorDigimon);
    }

    Self->ForceNetUpdate();
    return AppliedDamage;
}

void UDMFDigimonCombatComponent::NotifyAuthoritativeVictory(ADMFDigimonCharacter* DefeatedDigimon)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || IsDefeated())
    {
        return;
    }
    if (CurrentTarget == DefeatedDigimon)
    {
        bRetaliationCombatActive = false;
        SetBattleEncounterActive(false);
        CurrentTarget = nullptr;
        ResetAutoBattleAbilityRotation();
        OnTargetChanged.Broadcast(nullptr);
    }
    MulticastVictoryCue(DefeatedDigimon);
}

void UDMFDigimonCombatComponent::RestoreVitalsToMaximum()
{
    RestoreVitals(true, true, true);
}

void UDMFDigimonCombatComponent::RestoreVitals(const bool bRestoreHP, const bool bRestoreSP, const bool bResetCombat)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Self->HasAuthority())
    {
        return;
    }

    if (bRestoreHP)
    {
        CurrentHP = FMath::Max(1, Self->ReplicatedStats.MaxHP);
    }
    if (bRestoreSP)
    {
        CurrentSP = FMath::Max(0, Self->ReplicatedStats.MaxSP);
    }

    if (bResetCombat)
    {
        Self->StopCombatFacingTarget();
        bRetaliationCombatActive = false;
        SetBattleEncounterActive(false);
        CurrentTarget = nullptr;
        ResetAutoBattleAbilityRotation();
        ClearQueuedCommand();
        ReplicatedCooldowns.Reset();
        if (AAIController* AI = Cast<AAIController>(Self->GetController()))
        {
            AI->StopMovement();
        }
        SetCombatState(CurrentHP > 0 ? EDMFCombatState::Idle : EDMFCombatState::Defeated);
        OnTargetChanged.Broadcast(nullptr);
    }
    else if (CurrentHP > 0 && CombatState == EDMFCombatState::Defeated)
    {
        SetCombatState(EDMFCombatState::Idle);
    }

    OnVitalsChanged.Broadcast(CurrentHP, CurrentSP);
    Self->ForceNetUpdate();
}

void UDMFDigimonCombatComponent::QueueAbilityCommand(const FName AbilityId, ADMFDigimonCharacter* Target, const UDMFDigimonAbilityData& Ability, const float MinimumWaitSeconds)
{
    if (!GetWorld() || AbilityId.IsNone())
    {
        return;
    }

    QueuedAbilityId = AbilityId;
    QueuedTarget = Target;

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const double BaseTimeout = Settings ? FMath::Max(0.5, static_cast<double>(Settings->CombatCommandQueueTimeout)) : 8.0;
    const double AbilityTiming = static_cast<double>(FMath::Max(0.0f, Ability.ImpactDelaySeconds) + FMath::Max(0.0f, Ability.RecoverySeconds));
    const double RequiredLifetime = static_cast<double>(FMath::Max(0.0f, MinimumWaitSeconds)) + AbilityTiming + 0.5;
    QueuedCommandExpireTime = static_cast<double>(GetWorld()->GetTimeSeconds()) + FMath::Max(BaseTimeout, RequiredLifetime);
}

void UDMFDigimonCombatComponent::ClearQueuedCommand()
{
    QueuedAbilityId = NAME_None;
    QueuedTarget.Reset();
    QueuedCommandExpireTime = 0.0;
}

void UDMFDigimonCombatComponent::PruneExpiredCooldowns()
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Self->HasAuthority() || !GetWorld() || ReplicatedCooldowns.IsEmpty())
    {
        return;
    }

    const double NetworkNow = static_cast<double>(GetWorld()->GetTimeSeconds());
    const int32 Removed = ReplicatedCooldowns.RemoveAll([NetworkNow](const FDMFAbilityCooldownState& Entry)
    {
        return Entry.AbilityId.IsNone() || Entry.EndServerTimeSeconds <= NetworkNow;
    });

    if (Removed > 0)
    {
        Self->ForceNetUpdate();
    }
}

bool UDMFDigimonCombatComponent::ProcessQueuedCommand()
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || QueuedAbilityId.IsNone())
    {
        return false;
    }

    if (GetWorld()->GetTimeSeconds() > QueuedCommandExpireTime)
    {
        Self->StopCombatFacingTarget();
        ClearQueuedCommand();
        return false;
    }

    ADMFDigimonCharacter* Target = QueuedTarget.Get();
    UDMFDigimonAbilityData* Ability = ResolveAbilityData(QueuedAbilityId);
    if (!Ability || (Ability->bRequiresTarget && (!Target || !CanAttackTarget(Target))))
    {
        Self->StopCombatFacingTarget();
        ClearQueuedCommand();
        return false;
    }

    const FVector AnchorLocation = FollowAnchor.IsValid() ? FollowAnchor->GetActorLocation() : HomeLocation;
    if (FVector::DistSquared(Self->GetActorLocation(), AnchorLocation) > FMath::Square(FMath::Max(0.0f, LeashRange))
        || (Target && FVector::DistSquared(Target->GetActorLocation(), AnchorLocation) > FMath::Square(FMath::Max(0.0f, LeashRange))))
    {
        Self->StopCombatFacingTarget();
        ClearQueuedCommand();
        return false;
    }

    // Never lose a buffered input simply because the previous move is still finishing.
    if (CombatState == EDMFCombatState::Attacking || CombatState == EDMFCombatState::Recovering)
    {
        return true;
    }

    if (CurrentSP < GetEffectiveSPCost(*Ability))
    {
        Self->StopCombatFacingTarget();
        ClearQueuedCommand();
        return false;
    }

    PruneExpiredCooldowns();
    if (GetRemainingCooldown(QueuedAbilityId) > KINDA_SMALL_NUMBER)
    {
        // Cooldown is transient. Keep the command buffered until it reaches zero instead of deleting
        // the player's press, which was the one-shot/repeatability defect in v0.6.3.
        return true;
    }

    if (Ability->bRequiresTarget && !IsTargetWithinAbilityRange(Target, Ability->MaxRange))
    {
        Self->StopCombatFacingTarget();
        SetAuthoritativeTarget(Target);
        SetCombatState(EDMFCombatState::Chasing);
        if (AAIController* AI = Cast<AAIController>(Self->GetController()))
        {
            AI->MoveToActor(Target, GetAbilityMoveAcceptanceRadius(Target, Ability->MaxRange), true, true, true, nullptr, false);
        }
        return true;
    }

    if (AAIController* AI = Cast<AAIController>(Self->GetController()))
    {
        AI->StopMovement();
    }
    if (Ability->bRequiresTarget && Target && Self->bEnableCombatFacing)
    {
        Self->StartCombatFacingTarget(Target);
        if (Self->bRequireFacingBeforeAttack && !Self->IsFacingActor(Target))
        {
            return true;
        }
    }

    const FName AbilityToExecute = QueuedAbilityId;
    ADMFDigimonCharacter* TargetToUse = Target;
    const bool bExecuted = TryExecuteAbilityById(AbilityToExecute, TargetToUse);
    if (bExecuted)
    {
        ClearQueuedCommand();
        return true;
    }

    // A transient execution race should retain the command for the next authoritative automation
    // tick. Permanent invalid target/SP cases are handled above and clear explicitly.
    return true;
}

void UDMFDigimonCombatComponent::AutomationTick()
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Self->HasAuthority() || IsDefeated())
    {
        return;
    }

    PruneExpiredCooldowns();

    if (bBattleEncounterActive && !CanAttackTarget(CurrentTarget))
    {
        // The opponent may have been defeated/destroyed by another authoritative participant. Do not
        // leave durable encounter consumers (music/UI) latched merely because this Digimon was not
        // the actor that received the victory callback.
        SetBattleEncounterActive(false);
    }

    if (ProcessQueuedCommand())
    {
        return;
    }

    const FVector AnchorLocation = FollowAnchor.IsValid() ? FollowAnchor->GetActorLocation() : HomeLocation;
    if (FVector::DistSquared(Self->GetActorLocation(), AnchorLocation) > FMath::Square(FMath::Max(0.0f, LeashRange)))
    {
        bRetaliationCombatActive = false;
        Self->StopCombatFacingTarget();
        SetAuthoritativeTarget(nullptr);
        SetCombatState(EDMFCombatState::Idle);
        if (AAIController* AI = Cast<AAIController>(Self->GetController()))
        {
            if (FollowAnchor.IsValid())
            {
                AI->MoveToActor(FollowAnchor.Get(), 175.0f, true, true, true, nullptr, true);
            }
            else
            {
                AI->MoveToLocation(HomeLocation, 75.0f, true, true, true, false, nullptr, true);
            }
        }
        return;
    }

    // Reactive combat and proactive auto battle are deliberately separate. A passive wild Digimon
    // with retaliation enabled may continue fighting only the hostile Digimon that attacked it. It
    // never calls AcquireNearestHostile unless proactive auto battle is also enabled.
    if (bRetaliationCombatActive)
    {
        if (!CanAttackTarget(CurrentTarget)
            || FVector::DistSquared(CurrentTarget->GetActorLocation(), AnchorLocation) > FMath::Square(FMath::Max(0.0f, LeashRange)))
        {
            EndRetaliation();
        }
    }

    if (!bAutoBattleEnabled && !bRetaliationCombatActive)
    {
        // Manual-command partners still follow their player. Passive wild Digimon have no follow
        // anchor, so they simply remain idle/free-roaming until actually attacked.
        if (FollowAnchor.IsValid()
            && CombatState != EDMFCombatState::Attacking
            && CombatState != EDMFCombatState::Recovering
            && FVector::DistSquared(Self->GetActorLocation(), FollowAnchor->GetActorLocation()) > FMath::Square(300.0f))
        {
            Self->StopCombatFacingTarget();
            if (AAIController* AI = Cast<AAIController>(Self->GetController()))
            {
                AI->MoveToActor(FollowAnchor.Get(), 175.0f, true, true, true, nullptr, true);
            }
        }
        if (CombatState != EDMFCombatState::Attacking && CombatState != EDMFCombatState::Recovering)
        {
            SetCombatState(EDMFCombatState::Idle);
        }
        return;
    }

    if (bAutoBattleEnabled && !CanAttackTarget(CurrentTarget))
    {
        bRetaliationCombatActive = false;
        SetAuthoritativeTarget(AcquireNearestHostile());
    }

    // A selected/retaliation target may move beyond the permitted combat area. Drop it before
    // issuing another move so neither aggressive nor reactive combat can pull a Digimon forever.
    if (CurrentTarget && FVector::DistSquared(CurrentTarget->GetActorLocation(), AnchorLocation) > FMath::Square(FMath::Max(0.0f, LeashRange)))
    {
        bRetaliationCombatActive = false;
        SetAuthoritativeTarget(nullptr);
    }

    if (!CurrentTarget)
    {
        Self->StopCombatFacingTarget();
        if (FollowAnchor.IsValid() && FVector::DistSquared(Self->GetActorLocation(), FollowAnchor->GetActorLocation()) > FMath::Square(300.0f))
        {
            Self->StopCombatFacingTarget();
            if (AAIController* AI = Cast<AAIController>(Self->GetController()))
            {
                AI->MoveToActor(FollowAnchor.Get(), 175.0f, true, true, true, nullptr, true);
            }
        }
        SetCombatState(EDMFCombatState::Idle);
        return;
    }

    // Do not make a new autonomous decision while the previous move is still in its action lock.
    // FinishRecovery will return us to Idle and the next authority tick selects the next move.
    if (CombatState == EDMFCombatState::Attacking || CombatState == EDMFCombatState::Recovering)
    {
        return;
    }

    // Keep one selected move stable while closing distance. Without this pending intent, an AI with
    // mixed melee/ranged moves could choose a different range every 0.25s and oscillate instead of
    // ever reaching the move it intended to perform.
    if (!PendingAutoBattleAbilityId.IsNone()
        && !IsAutoBattleAbilityReady(PendingAutoBattleAbilityId, CurrentTarget))
    {
        PendingAutoBattleAbilityId = NAME_None;
    }

    if (PendingAutoBattleAbilityId.IsNone())
    {
        PendingAutoBattleAbilityId = SelectAutoBattleAbility(CurrentTarget);
    }

    UDMFDigimonAbilityData* SelectedAbility = ResolveAbilityData(PendingAutoBattleAbilityId);
    if (!SelectedAbility)
    {
        PendingAutoBattleAbilityId = NAME_None;
        SetCombatState(EDMFCombatState::Idle);
        return;
    }

    if (SelectedAbility->bRequiresTarget && !IsTargetWithinAbilityRange(CurrentTarget, SelectedAbility->MaxRange))
    {
        Self->StopCombatFacingTarget();
        SetCombatState(EDMFCombatState::Chasing);
        if (AAIController* AI = Cast<AAIController>(Self->GetController()))
        {
            AI->MoveToActor(CurrentTarget, GetAbilityMoveAcceptanceRadius(CurrentTarget, SelectedAbility->MaxRange), true, true, true, nullptr, false);
        }
        return;
    }

    if (AAIController* AI = Cast<AAIController>(Self->GetController()))
    {
        AI->StopMovement();
    }
    if (Self->bEnableCombatFacing)
    {
        Self->StartCombatFacingTarget(CurrentTarget);
        if (Self->bRequireFacingBeforeAttack && !Self->IsFacingActor(CurrentTarget))
        {
            return;
        }
    }
    const FName AbilityToExecute = PendingAutoBattleAbilityId;
    if (TryExecuteAbilityById(AbilityToExecute, CurrentTarget))
    {
        RecordAutoBattleAbilityUse(AbilityToExecute);
        PendingAutoBattleAbilityId = NAME_None;
    }
}

void UDMFDigimonCombatComponent::BeginRetaliation(ADMFDigimonCharacter* Aggressor)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Self->HasAuthority() || !bRetaliateWhenAttacked || IsDefeated() || !CanAttackTarget(Aggressor))
    {
        return;
    }

    const FVector AnchorLocation = FollowAnchor.IsValid() ? FollowAnchor->GetActorLocation() : HomeLocation;
    if (FVector::DistSquared(Aggressor->GetActorLocation(), AnchorLocation) > FMath::Square(FMath::Max(0.0f, LeashRange)))
    {
        return;
    }

    bRetaliationCombatActive = true;
    Self->StopCombatFacingTarget();
    SetAuthoritativeTarget(Aggressor);

    // Cancel an idle roam immediately. AutomationTick will select from the complete eligible
    // moveset and choose chase versus attack using that selected move's authored range.
    if (AAIController* AI = Cast<AAIController>(Self->GetController()))
    {
        AI->StopMovement();
    }

    if (CombatState != EDMFCombatState::Attacking && CombatState != EDMFCombatState::Recovering)
    {
        SetCombatState(EDMFCombatState::Chasing);
    }
}

void UDMFDigimonCombatComponent::EndRetaliation()
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    bRetaliationCombatActive = false;
    if (ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner()))
    {
        Self->StopCombatFacingTarget();
    }
    SetAuthoritativeTarget(nullptr);
    ClearQueuedCommand();
    if (!IsDefeated() && CombatState != EDMFCombatState::Attacking && CombatState != EDMFCombatState::Recovering)
    {
        SetCombatState(EDMFCombatState::Idle);
    }
}

ADMFDigimonCharacter* UDMFDigimonCombatComponent::AcquireNearestHostile() const
{
    const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    UWorld* World = GetWorld();
    if (!Self || !World || AggroRange <= 0.0f)
    {
        return nullptr;
    }

    TArray<FOverlapResult> Results;
    FCollisionObjectQueryParams ObjectQuery;
    ObjectQuery.AddObjectTypesToQuery(ECC_Pawn);
    FCollisionQueryParams Params(SCENE_QUERY_STAT(DMFCombatAcquire), false, Self);
    const FCollisionShape Shape = FCollisionShape::MakeSphere(AggroRange);
    World->OverlapMultiByObjectType(Results, Self->GetActorLocation(), FQuat::Identity, ObjectQuery, Shape, Params);

    ADMFDigimonCharacter* Best = nullptr;
    float BestDistSq = TNumericLimits<float>::Max();
    for (const FOverlapResult& Result : Results)
    {
        ADMFDigimonCharacter* Candidate = Cast<ADMFDigimonCharacter>(Result.GetActor());
        if (!CanAttackTarget(Candidate))
        {
            continue;
        }

        const float DistSq = FVector::DistSquared(Self->GetActorLocation(), Candidate->GetActorLocation());
        if (DistSq < BestDistSq)
        {
            Best = Candidate;
            BestDistSq = DistSq;
        }
    }
    return Best;
}

FName UDMFDigimonCombatComponent::ResolveBasicAttackId() const
{
    const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    UDMFDigimonSpeciesData* Species = Self ? Self->ResolveSpeciesData() : nullptr;
    if (Species)
    {
        if (UDMFDigimonAbilityData* Basic = Species->BasicAutoAttack.LoadSynchronous())
        {
            return Basic->AbilityId.IsNone() ? Basic->GetPrimaryAssetId().PrimaryAssetName : Basic->AbilityId;
        }
    }

    return Self && Self->ReplicatedAbilityIds.Num() > 0 ? Self->ReplicatedAbilityIds[0] : NAME_None;
}

bool UDMFDigimonCombatComponent::IsAutoBattleAbilityReady(const FName AbilityId, ADMFDigimonCharacter* Target) const
{
    const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    UDMFDigimonAbilityData* Ability = ResolveAbilityData(AbilityId);
    if (!Self || !Target || !CanAttackTarget(Target) || !Ability || !Ability->bEligibleForAutoBattle)
    {
        return false;
    }

    if (CurrentSP < GetEffectiveSPCost(*Ability))
    {
        return false;
    }

    const FName EffectiveAbilityId = Ability->AbilityId.IsNone()
        ? Ability->GetPrimaryAssetId().PrimaryAssetName
        : Ability->AbilityId;
    return GetRemainingCooldown(EffectiveAbilityId) <= KINDA_SMALL_NUMBER;
}

FName UDMFDigimonCombatComponent::SelectAutoBattleAbility(ADMFDigimonCharacter* Target)
{
    const ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (!Self || !Self->HasAuthority() || !Target || !CanAttackTarget(Target))
    {
        return NAME_None;
    }

    TArray<FName> RuntimeAbilityIds = Self->ReplicatedAbilityIds;
    const FName BasicAttackId = ResolveBasicAttackId();
    if (!BasicAttackId.IsNone())
    {
        RuntimeAbilityIds.AddUnique(BasicAttackId);
    }

    uint64 OldestUseSerial = TNumericLimits<uint64>::Max();
    TArray<FName> LeastRecentlyUsedCandidates;
    TSet<FName> SeenEffectiveIds;

    for (const FName RuntimeAbilityId : RuntimeAbilityIds)
    {
        if (!IsAutoBattleAbilityReady(RuntimeAbilityId, Target))
        {
            continue;
        }

        UDMFDigimonAbilityData* Ability = ResolveAbilityData(RuntimeAbilityId);
        if (!Ability)
        {
            continue;
        }

        const FName EffectiveAbilityId = Ability->AbilityId.IsNone()
            ? Ability->GetPrimaryAssetId().PrimaryAssetName
            : Ability->AbilityId;
        if (EffectiveAbilityId.IsNone() || SeenEffectiveIds.Contains(EffectiveAbilityId))
        {
            continue;
        }
        SeenEffectiveIds.Add(EffectiveAbilityId);

        const uint64 UseSerial = AutoBattleAbilityUseSerials.FindRef(EffectiveAbilityId);
        if (UseSerial < OldestUseSerial)
        {
            OldestUseSerial = UseSerial;
            LeastRecentlyUsedCandidates.Reset();
            LeastRecentlyUsedCandidates.Add(RuntimeAbilityId);
        }
        else if (UseSerial == OldestUseSerial)
        {
            LeastRecentlyUsedCandidates.Add(RuntimeAbilityId);
        }
    }

    if (LeastRecentlyUsedCandidates.IsEmpty())
    {
        return NAME_None;
    }

    // Randomize only among equally old candidates. This avoids a rigid slot-order pattern while the
    // least-recently-used rule still guarantees that untouched usable moves are selected before
    // already-used moves are preferred again.
    return LeastRecentlyUsedCandidates[FMath::RandHelper(LeastRecentlyUsedCandidates.Num())];
}

void UDMFDigimonCombatComponent::RecordAutoBattleAbilityUse(const FName AbilityId)
{
    UDMFDigimonAbilityData* Ability = ResolveAbilityData(AbilityId);
    if (!Ability)
    {
        return;
    }

    const FName EffectiveAbilityId = Ability->AbilityId.IsNone()
        ? Ability->GetPrimaryAssetId().PrimaryAssetName
        : Ability->AbilityId;
    if (EffectiveAbilityId.IsNone())
    {
        return;
    }

    ++AutoBattleAbilityUseCounter;
    AutoBattleAbilityUseSerials.FindOrAdd(EffectiveAbilityId) = AutoBattleAbilityUseCounter;
}

void UDMFDigimonCombatComponent::ResetAutoBattleAbilityRotation()
{
    PendingAutoBattleAbilityId = NAME_None;
    AutoBattleAbilityUseSerials.Reset();
    AutoBattleAbilityUseCounter = 0;
}

void UDMFDigimonCombatComponent::FinishRecovery()
{
    if (ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner()))
    {
        Self->StopCombatFacingTarget();
    }
    if (!IsDefeated())
    {
        SetCombatState(EDMFCombatState::Idle);
        // Service buffered input immediately at recovery completion instead of waiting for another
        // full automation interval. If cooldown is still active ProcessQueuedCommand simply retains it.
        ProcessQueuedCommand();
    }
}

void UDMFDigimonCombatComponent::SetBattleEncounterActive(const bool bActive)
{
    if (bBattleEncounterActive == bActive)
    {
        return;
    }

    bBattleEncounterActive = bActive;
    if (GetOwner())
    {
        // Encounter truth is durable gameplay state consumed by owner-local presentation (music) and
        // Blueprint queries. Force an update so victory/defeat/disengage transitions do not wait for
        // an unrelated replication wake-up.
        GetOwner()->ForceNetUpdate();
    }
}

void UDMFDigimonCombatComponent::SetCombatState(const EDMFCombatState NewState)
{
    if (NewState == EDMFCombatState::Defeated)
    {
        SetBattleEncounterActive(false);
    }
    else if ((NewState == EDMFCombatState::Chasing
        || NewState == EDMFCombatState::Attacking
        || NewState == EDMFCombatState::Recovering)
        && CurrentTarget
        && CanAttackTarget(CurrentTarget))
    {
        // CombatState describes the current action phase. The encounter latch deliberately does not
        // clear when recovery returns to Idle, because manual combat can legitimately pause there
        // while the same living hostile target remains engaged.
        SetBattleEncounterActive(true);
    }

    if (CombatState != NewState)
    {
        const EDMFCombatState PreviousState = CombatState;
        CombatState = NewState;

        if (ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner()))
        {
            if (CombatState == EDMFCombatState::Defeated)
            {
                Self->ApplyDefeatedPresentation();
            }
            else if (PreviousState == EDMFCombatState::Defeated)
            {
                Self->ClearDefeatedPresentation();
            }
        }

        OnCombatStateChanged.Broadcast(CombatState);
        if (GetOwner())
        {
            GetOwner()->ForceNetUpdate();
        }
    }
}

void UDMFDigimonCombatComponent::OnRep_Vitals()
{
    OnVitalsChanged.Broadcast(CurrentHP, CurrentSP);
}

void UDMFDigimonCombatComponent::OnRep_CurrentTarget()
{
    OnTargetChanged.Broadcast(CurrentTarget);
}

void UDMFDigimonCombatComponent::OnRep_CombatState()
{
    if (ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner()))
    {
        if (CombatState == EDMFCombatState::Defeated)
        {
            Self->ApplyDefeatedPresentation();
        }
        else if (Self->IsDefeatedPresentationActive())
        {
            Self->ClearDefeatedPresentation();
        }
    }
    OnCombatStateChanged.Broadcast(CombatState);
}

void UDMFDigimonCombatComponent::MulticastPlayAbilityCue_Implementation(const FName AbilityId, ADMFDigimonCharacter* Target)
{
    PlayNativeAbilityPresentation(AbilityId, Target);
    BP_OnAbilityCosmeticCue(AbilityId, Target);
}

void UDMFDigimonCombatComponent::MulticastPlayProjectileImpactCue_Implementation(const FName AbilityId, const FVector_NetQuantize ImpactLocation)
{
    if (UDMFDigimonAbilityData* Ability = ResolveAbilityData(AbilityId))
    {
        SpawnTransientProjectileImpactVFX(*Ability, ImpactLocation);
    }
}

void UDMFDigimonCombatComponent::MulticastDefeatedCue_Implementation(ADMFDigimonCharacter* Killer)
{
    // IMPORTANT: do not start the durable Death Montage from this multicast. A multicast can arrive
    // on a client before its replicated CombatState property. Starting the Montage early created a
    // race where the end-pose lock could see a still-Idle state and refuse to freeze, after which the
    // AnimBP blended back to Idle. SetCombatState/OnRep_CombatState are now the sole durable animation
    // trigger; this multicast remains for immediate Blueprint-only cosmetic VFX/audio.
    BP_OnDefeatedCosmetics(Killer);
}

void UDMFDigimonCombatComponent::MulticastVictoryCue_Implementation(ADMFDigimonCharacter* DefeatedDigimon)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    if (Self)
    {
        if (UDMFDigimonSpeciesData* Species = Self->ResolveSpeciesData())
        {
            if (UAnimMontage* Montage = Species->WinMontage.LoadSynchronous())
            {
                if (UAnimInstance* AnimInstance = Self->GetMesh() ? Self->GetMesh()->GetAnimInstance() : nullptr)
                {
                    AnimInstance->Montage_Play(Montage);
                }
            }
        }
    }
    BP_OnVictoryCosmetics(DefeatedDigimon);
}

void UDMFDigimonCombatComponent::PlayNativeAbilityPresentation(const FName AbilityId, ADMFDigimonCharacter* Target)
{
    ADMFDigimonCharacter* Self = Cast<ADMFDigimonCharacter>(GetOwner());
    UDMFDigimonAbilityData* Ability = ResolveAbilityData(AbilityId);
    if (!Self || !Ability)
    {
        return;
    }

    UAnimMontage* Montage = Ability->Montage.LoadSynchronous();

    // Backward-compatible per-species Attack1/Attack2 montage override from the original framework.
    if (UDMFDigimonSpeciesData* Species = Self->ResolveSpeciesData())
    {
        const int32 SlotIndex = Self->ReplicatedAbilityIds.IndexOfByKey(AbilityId);
        if (SlotIndex == 0 && !Montage)
        {
            Montage = Species->Attack1Montage.LoadSynchronous();
        }
        else if (SlotIndex == 1 && !Montage)
        {
            Montage = Species->Attack2Montage.LoadSynchronous();
        }
    }

    if (Montage)
    {
        if (UAnimInstance* AnimInstance = Self->GetMesh() ? Self->GetMesh()->GetAnimInstance() : nullptr)
        {
            AnimInstance->Montage_Play(Montage);
        }
    }

    // Projectile execution owns the moving fireball/rocket/etc through a replicated projectile actor.
    // Do not also spawn the old Niagara/Cascade cue at the socket, which was the static VFX defect.
    if (Ability->ExecutionMode != EDMFAbilityExecutionMode::Projectile)
    {
        SpawnTransientAbilityVFX(*Ability, Target);
    }

    if (USoundBase* Sound = Ability->AttackSound.LoadSynchronous())
    {
        UGameplayStatics::PlaySoundAtLocation(this, Sound, Self->GetActorLocation());
    }
}

