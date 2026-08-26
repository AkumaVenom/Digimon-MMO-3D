#include "Game/DMFHealerActor.h"

#include "Components/AudioComponent.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "Net/UnrealNetwork.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"

ADMFHealerActor::ADMFHealerActor()
{
    bReplicates = true;
    SetReplicateMovement(false);
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = false;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    InteractionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionCollision"));
    InteractionCollision->SetupAttachment(SceneRoot);
    InteractionCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    InteractionCollision->SetCollisionObjectType(ECC_WorldDynamic);
    InteractionCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
    InteractionCollision->SetGenerateOverlapEvents(false);

    HealingPresentationAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("HealingPresentationAnchor"));
    HealingPresentationAnchor->SetupAttachment(SceneRoot);

    HealingLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("HealingLight"));
    HealingLight->SetupAttachment(HealingPresentationAnchor);
    HealingLight->SetIntensity(0.0f);
    HealingLight->SetCastShadows(false);
    HealingLight->SetVisibility(true);

    HealingNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("HealingNiagara"));
    HealingNiagaraComponent->SetupAttachment(HealingPresentationAnchor);
    HealingNiagaraComponent->SetAutoActivate(false);

    HealingCascadeComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("HealingCascadeFallback"));
    HealingCascadeComponent->SetupAttachment(HealingPresentationAnchor);
    HealingCascadeComponent->SetAutoActivate(false);

    HealingAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("HealingAudio"));
    HealingAudioComponent->SetupAttachment(HealingPresentationAnchor);
    HealingAudioComponent->SetAutoActivate(false);

    InteractionPrompt = NSLOCTEXT("DMF", "DefaultHealerPrompt", "Heal Digimon");
    SuccessMessage = NSLOCTEXT("DMF", "DefaultHealerSuccess", "All Party and Bank Digimon have been fully restored.");
    AlreadyHealthyMessage = NSLOCTEXT("DMF", "DefaultHealerAlreadyHealthy", "Your Digimon are already fully restored.");
    DisabledMessage = NSLOCTEXT("DMF", "DefaultHealerDisabled", "This healer is currently unavailable.");
    TooFarMessage = NSLOCTEXT("DMF", "DefaultHealerTooFar", "Move closer to the healer.");
    BusyMessage = NSLOCTEXT("DMF", "DefaultHealerBusy", "This healer is currently treating another player. Please wait a moment.");
}

void ADMFHealerActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    RefreshInteractionCollision();
    RefreshHealingPresentation();
}

void ADMFHealerActor::BeginPlay()
{
    Super::BeginPlay();
    RefreshInteractionCollision();
    RefreshHealingPresentation();
    ApplyReplicatedHealingPresentation();
}

void ADMFHealerActor::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (GetNetMode() == NM_DedicatedServer)
    {
        SetActorTickEnabled(false);
        return;
    }

    const float TargetBlend = bLocalHealingPresentationActive ? 1.0f : 0.0f;
    const float BlendSeconds = bLocalHealingPresentationActive
        ? FMath::Max(0.0f, HealingLightFadeInSeconds)
        : FMath::Max(0.0f, HealingLightFadeOutSeconds);

    if (BlendSeconds <= KINDA_SMALL_NUMBER)
    {
        LocalHealingLightBlend = TargetBlend;
    }
    else
    {
        LocalHealingLightBlend = FMath::FInterpConstantTo(LocalHealingLightBlend, TargetBlend, DeltaSeconds, 1.0f / BlendSeconds);
    }

    if (bLocalHealingPresentationActive)
    {
        LocalHealingPresentationElapsed += DeltaSeconds;
    }

    if (HealingLight)
    {
        float PulseMultiplier = 1.0f;
        if (bLocalHealingPresentationActive && HealingLightPulseAmount > 0.0f && HealingLightPulseFrequencyHz > 0.0f)
        {
            const float Phase = LocalHealingPresentationElapsed * HealingLightPulseFrequencyHz * 2.0f * PI;
            PulseMultiplier += FMath::Clamp(HealingLightPulseAmount, 0.0f, 1.0f) * FMath::Sin(Phase);
        }

        const float FinalIntensity = bEnableHealingLight
            ? FMath::Max(0.0f, HealingLightIntensity) * FMath::Clamp(LocalHealingLightBlend, 0.0f, 1.0f) * FMath::Max(0.0f, PulseMultiplier)
            : 0.0f;
        HealingLight->SetIntensity(FinalIntensity);
    }

    if (!bLocalHealingPresentationActive && LocalHealingLightBlend <= KINDA_SMALL_NUMBER)
    {
        LocalHealingLightBlend = 0.0f;
        if (HealingLight)
        {
            HealingLight->SetIntensity(0.0f);
        }
        SetActorTickEnabled(false);
    }
}

void ADMFHealerActor::RefreshInteractionCollision()
{
    if (InteractionCollision)
    {
        InteractionCollision->SetSphereRadius(FMath::Max(1.0f, InteractionCollisionRadius), true);
        InteractionCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
        InteractionCollision->SetCollisionResponseToChannel(static_cast<ECollisionChannel>(InteractionTraceChannel.GetValue()), ECR_Block);
    }
}

void ADMFHealerActor::RefreshHealingPresentation()
{
    if (HealingPresentationAnchor)
    {
        HealingPresentationAnchor->SetRelativeTransform(HealingPresentationRelativeTransform);
    }

    // Dedicated servers retain authoritative healer state but never load/render cosmetic treatment assets.
    if (GetNetMode() == NM_DedicatedServer)
    {
        return;
    }

    if (HealingLight)
    {
        HealingLight->SetLightColor(HealingLightColor);
        HealingLight->SetAttenuationRadius(FMath::Max(1.0f, HealingLightAttenuationRadius));
        if (!bLocalHealingPresentationActive)
        {
            HealingLight->SetIntensity(0.0f);
        }
    }

    if (HealingNiagaraComponent)
    {
        UNiagaraSystem* NiagaraAsset = HealingNiagaraSystem.IsNull() ? nullptr : HealingNiagaraSystem.LoadSynchronous();
        HealingNiagaraComponent->SetAsset(NiagaraAsset);
        if (!bLocalHealingPresentationActive)
        {
            HealingNiagaraComponent->DeactivateImmediate();
        }
    }

    if (HealingCascadeComponent)
    {
        UParticleSystem* CascadeAsset = HealingCascadeSystem.IsNull() ? nullptr : HealingCascadeSystem.LoadSynchronous();
        HealingCascadeComponent->SetTemplate(CascadeAsset);
        if (!bLocalHealingPresentationActive)
        {
            HealingCascadeComponent->DeactivateSystem();
        }
    }

    if (HealingAudioComponent)
    {
        USoundBase* SoundAsset = HealingSound.IsNull() ? nullptr : HealingSound.LoadSynchronous();
        HealingAudioComponent->SetSound(SoundAsset);
        HealingAudioComponent->SetVolumeMultiplier(FMath::Max(0.0f, HealingSoundVolumeMultiplier));
        HealingAudioComponent->SetPitchMultiplier(FMath::Max(0.25f, HealingSoundPitchMultiplier));
        if (!bLocalHealingPresentationActive)
        {
            HealingAudioComponent->Stop();
        }
    }
}

void ADMFHealerActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFHealerActor, bEnabled);
    DOREPLIFETIME(ADMFHealerActor, bHealingInProgress);
    DOREPLIFETIME(ADMFHealerActor, ActiveHealingPlayerState);
    DOREPLIFETIME(ADMFHealerActor, ActiveHealingDigimonCount);
}

void ADMFHealerActor::RequestHeal(APlayerController* PlayerController)
{
    ADMFMMOPlayerController* DMFController = Cast<ADMFMMOPlayerController>(PlayerController);
    if (!DMFController)
    {
        return;
    }

    if (HasAuthority() && DMFController->HasAuthority())
    {
        int32 DigimonHealed = 0;
        FText Message;
        const bool bSuccess = TryHealPlayerAuthoritative(DMFController, DigimonHealed, Message);
        DMFController->ClientHealerInteractionResult(bSuccess, Message, DigimonHealed);
        return;
    }

    DMFController->RequestUseHealer(this);
}

bool ADMFHealerActor::IsPlayerWithinInteractionRange(const APlayerController* PlayerController) const
{
    const APawn* Pawn = PlayerController ? PlayerController->GetPawn() : nullptr;
    if (!Pawn)
    {
        return false;
    }

    const float Radius = FMath::Max(0.0f, InteractionRadius);
    return FVector::DistSquared(Pawn->GetActorLocation(), GetActorLocation()) <= FMath::Square(Radius);
}

bool ADMFHealerActor::TryHealPlayerAuthoritative(APlayerController* PlayerController, int32& OutDigimonHealed, FText& OutMessage)
{
    OutDigimonHealed = 0;
    OutMessage = FText::GetEmpty();

    if (!HasAuthority() || !IsValid(PlayerController))
    {
        OutMessage = NSLOCTEXT("DMF", "HealerInvalidAuthority", "The healer request could not be validated.");
        return false;
    }
    if (!bEnabled)
    {
        OutMessage = DisabledMessage;
        return false;
    }
    if (bHealingInProgress)
    {
        OutMessage = BusyMessage;
        return false;
    }
    if (!IsPlayerWithinInteractionRange(PlayerController))
    {
        OutMessage = TooFarMessage;
        return false;
    }

    const double Now = GetWorld() ? static_cast<double>(GetWorld()->GetTimeSeconds()) : 0.0;
    const TWeakObjectPtr<APlayerController> PlayerKey(PlayerController);
    if (const double* LastUseTime = LastUseServerTimeByPlayer.Find(PlayerKey))
    {
        if (Now - *LastUseTime < FMath::Max(0.0, static_cast<double>(ReuseDelay)))
        {
            OutMessage = NSLOCTEXT("DMF", "HealerReuseWait", "Please wait a moment before using the healer again.");
            return false;
        }
    }

    ADMFPlayerState* PS = PlayerController->GetPlayerState<ADMFPlayerState>();
    UDMFPlayerDigimonComponent* DigimonComponent = PS ? PS->DigimonComponent : nullptr;
    if (!DigimonComponent)
    {
        OutMessage = NSLOCTEXT("DMF", "HealerNoDigimonComponent", "Your Digimon data is not ready yet.");
        return false;
    }
    if (DigimonComponent->IsDigivolutionSequenceActive())
    {
        OutMessage = NSLOCTEXT("DMF", "HealerDigivolutionBusy", "Wait for the active Digivolution sequence to finish before using the healer.");
        return false;
    }

    const TArray<FDMFDigimonInstance> Before = DigimonComponent->GetDigimonInventory();
    if (Before.IsEmpty() && !bIncludeBankStorage)
    {
        OutMessage = NSLOCTEXT("DMF", "HealerNoDigimon", "You do not have any Digimon to heal.");
        return false;
    }

    OutDigimonHealed = DigimonComponent->HealAllOwnedDigimon(
        bHealHP,
        bHealSP,
        bRestoreDefeatedDigimon,
        bIncludeBankStorage);

    LastUseServerTimeByPlayer.Add(PlayerKey, Now);

    if (bSummonActivePartnerAfterHeal
        && !DigimonComponent->IsActivePartnerSummoned()
        && DigimonComponent->GetActivePartnerInstanceId().IsValid()
        && PlayerController->GetPawn())
    {
        DigimonComponent->SpawnOrRefreshActivePartner(PlayerController->GetPawn());
    }

    OutMessage = OutDigimonHealed > 0 ? SuccessMessage : AlreadyHealthyMessage;
    BP_OnPlayerHealed(PlayerController, OutDigimonHealed);

    // Preserve the original cosmetic hook contract for existing healer Blueprints.
    MulticastHealPresentation(PS, OutDigimonHealed);

    // Only a real restoration owns the station and runs the polished treatment presentation.
    if (OutDigimonHealed > 0)
    {
        BeginHealingSequenceAuthoritative(PS, OutDigimonHealed);
    }

    return true;
}

void ADMFHealerActor::BeginHealingSequenceAuthoritative(ADMFPlayerState* HealedPlayerState, const int32 DigimonHealed)
{
    if (!HasAuthority() || bHealingInProgress || DigimonHealed <= 0)
    {
        return;
    }

    bHealingInProgress = true;
    ActiveHealingPlayerState = HealedPlayerState;
    ActiveHealingDigimonCount = DigimonHealed;

    // Listen-server/local presentation does not receive OnRep, so apply it explicitly on authority too.
    ApplyReplicatedHealingPresentation();
    ForceNetUpdate();

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(HealingSequenceTimerHandle);
        World->GetTimerManager().SetTimer(
            HealingSequenceTimerHandle,
            this,
            &ADMFHealerActor::EndHealingSequenceAuthoritative,
            FMath::Max(0.1f, HealingSequenceDuration),
            false);
    }
}

void ADMFHealerActor::EndHealingSequenceAuthoritative()
{
    if (!HasAuthority() || !bHealingInProgress)
    {
        return;
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(HealingSequenceTimerHandle);
    }

    bHealingInProgress = false;
    ApplyReplicatedHealingPresentation();

    ActiveHealingPlayerState = nullptr;
    ActiveHealingDigimonCount = 0;
    ForceNetUpdate();
}

void ADMFHealerActor::ApplyReplicatedHealingPresentation()
{
    if (bHealingInProgress)
    {
        StartLocalHealingPresentation();
    }
    else
    {
        StopLocalHealingPresentation();
    }
}

bool ADMFHealerActor::ActivatePreferredHealingVFX()
{
    const bool bHasNiagara = HealingNiagaraComponent && !HealingNiagaraSystem.IsNull() && HealingNiagaraSystem.Get() != nullptr;
    const bool bHasCascade = HealingCascadeComponent && !HealingCascadeSystem.IsNull() && HealingCascadeSystem.Get() != nullptr;

    if (HealingNiagaraComponent)
    {
        HealingNiagaraComponent->DeactivateImmediate();
    }
    if (HealingCascadeComponent)
    {
        HealingCascadeComponent->DeactivateSystem();
    }

    if (bPreferNiagaraHealingVFX)
    {
        if (bHasNiagara)
        {
            HealingNiagaraComponent->Activate(true);
            return true;
        }
        if (bHasCascade)
        {
            HealingCascadeComponent->ActivateSystem(true);
            return true;
        }
    }
    else
    {
        if (bHasCascade)
        {
            HealingCascadeComponent->ActivateSystem(true);
            return true;
        }
        if (bHasNiagara)
        {
            HealingNiagaraComponent->Activate(true);
            return true;
        }
    }

    return false;
}

void ADMFHealerActor::StartLocalHealingPresentation()
{
    if (GetNetMode() == NM_DedicatedServer)
    {
        return;
    }

    if (bLocalHealingPresentationActive)
    {
        if (IsValid(ActiveHealingPlayerState))
        {
            LocalHealingPlayerState = ActiveHealingPlayerState;
        }
        LocalHealingDigimonCount = ActiveHealingDigimonCount;
        return;
    }

    RefreshHealingPresentation();

    bLocalHealingPresentationActive = true;
    LocalHealingPresentationElapsed = 0.0f;
    LocalHealingPlayerState = ActiveHealingPlayerState;
    LocalHealingDigimonCount = ActiveHealingDigimonCount;
    SetActorTickEnabled(true);

    ActivatePreferredHealingVFX();

    if (HealingAudioComponent && !HealingSound.IsNull() && HealingSound.Get() != nullptr)
    {
        HealingAudioComponent->Stop();
        HealingAudioComponent->SetVolumeMultiplier(FMath::Max(0.0f, HealingSoundVolumeMultiplier));
        HealingAudioComponent->SetPitchMultiplier(FMath::Max(0.25f, HealingSoundPitchMultiplier));
        HealingAudioComponent->Play();
    }

    BP_OnHealingSequenceStarted(ActiveHealingPlayerState, ActiveHealingDigimonCount);
}

void ADMFHealerActor::StopLocalHealingPresentation()
{
    if (GetNetMode() == NM_DedicatedServer || !bLocalHealingPresentationActive)
    {
        return;
    }

    bLocalHealingPresentationActive = false;
    SetActorTickEnabled(true); // Keep ticking only long enough to fade the green light back to zero.

    if (HealingNiagaraComponent)
    {
        HealingNiagaraComponent->Deactivate();
    }
    if (HealingCascadeComponent)
    {
        HealingCascadeComponent->DeactivateSystem();
    }
    if (HealingAudioComponent && HealingAudioComponent->IsPlaying())
    {
        if (HealingSoundFadeOutSeconds > KINDA_SMALL_NUMBER)
        {
            HealingAudioComponent->FadeOut(HealingSoundFadeOutSeconds, 0.0f);
        }
        else
        {
            HealingAudioComponent->Stop();
        }
    }

    BP_OnHealingSequenceFinished(LocalHealingPlayerState.Get(), LocalHealingDigimonCount);
    LocalHealingPlayerState.Reset();
    LocalHealingDigimonCount = 0;
}

void ADMFHealerActor::SetHealerEnabled(const bool bNewEnabled)
{
    if (!HasAuthority() || bEnabled == bNewEnabled)
    {
        return;
    }

    bEnabled = bNewEnabled;
    if (!bEnabled && bHealingInProgress)
    {
        EndHealingSequenceAuthoritative();
    }

    BP_OnEnabledStateChanged(bEnabled);
    ForceNetUpdate();
}

void ADMFHealerActor::OnRep_Enabled()
{
    BP_OnEnabledStateChanged(bEnabled);
    if (!bEnabled && bLocalHealingPresentationActive)
    {
        StopLocalHealingPresentation();
    }
}

void ADMFHealerActor::OnRep_HealingPresentationState()
{
    ApplyReplicatedHealingPresentation();
}

void ADMFHealerActor::MulticastHealPresentation_Implementation(ADMFPlayerState* HealedPlayerState, const int32 DigimonHealed)
{
    BP_OnHealPresentation(HealedPlayerState, DigimonHealed);
}
