#include "Subsystems/DMFMusicSubsystem.h"

#include "Components/AudioComponent.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFFrontendGameMode.h"
#include "Game/DMFMMOGameMode.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Settings/DMFFrameworkSettings.h"
#include "Sound/SoundBase.h"

void UDMFMusicSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    CurrentMusicState = EDMFMusicState::None;
    EvaluationTimeRemaining = 0.0f;
    BattleReleaseTimeRemaining = 0.0f;
    FadingCleanupTimeRemaining = 0.0f;
    bBattleCurrentlyObserved = false;
    bMusicSuppressed = false;
    bInitialized = true;
}

void UDMFMusicSubsystem::Deinitialize()
{
    bInitialized = false;
    StopAllMusic();
    Super::Deinitialize();
}

void UDMFMusicSubsystem::Tick(const float DeltaTime)
{
    if (IsValid(FadingAudioComponent))
    {
        FadingCleanupTimeRemaining -= DeltaTime;
        if (FadingCleanupTimeRemaining <= 0.0f || !FadingAudioComponent->IsPlaying())
        {
            CleanupFadingComponent(true);
        }
    }

    if (!bBattleCurrentlyObserved && BattleReleaseTimeRemaining > 0.0f)
    {
        BattleReleaseTimeRemaining = FMath::Max(0.0f, BattleReleaseTimeRemaining - DeltaTime);
    }

    EvaluationTimeRemaining -= DeltaTime;
    if (EvaluationTimeRemaining <= 0.0f)
    {
        RefreshMusicState();

        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        EvaluationTimeRemaining = Settings
            ? FMath::Clamp(Settings->MusicStateEvaluationInterval, 0.05f, 1.0f)
            : 0.20f;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings
        && Settings->bEnableFrameworkMusic
        && Settings->bAutomaticallyLoopMusic
        && !bMusicSuppressed
        && CurrentMusicState != EDMFMusicState::None
        && IsValid(CurrentAudioComponent)
        && IsValid(CurrentSound)
        && !CurrentAudioComponent->IsPlaying())
    {
        // This also makes a plain, non-looping Sound Wave/Cue safe for framework use. Internally-looped
        // Sound Cues never enter this branch because their AudioComponent remains playing.
        CurrentAudioComponent->Play(0.0f);
    }
}

TStatId UDMFMusicSubsystem::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(UDMFMusicSubsystem, STATGROUP_Tickables);
}

bool UDMFMusicSubsystem::IsTickable() const
{
    return bInitialized && !IsTemplate() && GetGameInstance() != nullptr;
}

UWorld* UDMFMusicSubsystem::GetTickableGameObjectWorld() const
{
    return GetGameInstance() ? GetGameInstance()->GetWorld() : nullptr;
}

void UDMFMusicSubsystem::RefreshMusicState()
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UWorld* World = GetTickableGameObjectWorld();

    if (!Settings || !Settings->bEnableFrameworkMusic || bMusicSuppressed)
    {
        bBattleCurrentlyObserved = false;
        BattleReleaseTimeRemaining = 0.0f;
        TransitionToState(EDMFMusicState::None);
        return;
    }

    if (!World)
    {
        // A GameInstance can briefly have no active world during travel. Keep the persistent current
        // track alive until the destination world exists, then resolve/crossfade its proper state.
        return;
    }

    if (World->GetNetMode() == NM_DedicatedServer)
    {
        bBattleCurrentlyObserved = false;
        BattleReleaseTimeRemaining = 0.0f;
        TransitionToState(EDMFMusicState::None);
        return;
    }

    const EDMFMusicState BaseState = ResolveBaseWorldState();
    if (BaseState != EDMFMusicState::OpenWorld)
    {
        bBattleCurrentlyObserved = false;
        BattleReleaseTimeRemaining = 0.0f;
        TransitionToState(BaseState);
        return;
    }

    bBattleCurrentlyObserved = IsLocalPlayerInBattle();
    if (bBattleCurrentlyObserved)
    {
        BattleReleaseTimeRemaining = FMath::Max(0.0f, Settings->BattleMusicReleaseDelaySeconds);
        TransitionToState(EDMFMusicState::Battle);
        return;
    }

    if (CurrentMusicState == EDMFMusicState::Battle && BattleReleaseTimeRemaining > 0.0f)
    {
        // Hold the battle mix briefly through tiny replicated combat-state gaps and the final recovery beat.
        TransitionToState(EDMFMusicState::Battle);
        return;
    }

    TransitionToState(EDMFMusicState::OpenWorld);
}

void UDMFMusicSubsystem::SetMusicSuppressed(const bool bSuppressed)
{
    if (bMusicSuppressed == bSuppressed)
    {
        return;
    }

    bMusicSuppressed = bSuppressed;
    EvaluationTimeRemaining = 0.0f;
    RefreshMusicState();
}

EDMFMusicState UDMFMusicSubsystem::ResolveBaseWorldState() const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UWorld* World = GetTickableGameObjectWorld();
    if (!Settings || !World)
    {
        return EDMFMusicState::None;
    }

    if (DoesWorldMatchMap(World, Settings->FrontendMap))
    {
        return EDMFMusicState::Frontend;
    }

    if (DoesWorldMatchMap(World, Settings->OpenWorldMap))
    {
        return EDMFMusicState::OpenWorld;
    }

    // GameMode is available on standalone/listen authority and makes custom map aliases work even when
    // a project has not updated its map soft reference yet. Remote clients use the configured map name
    // above or the framework PlayerController fallback below.
    if (World->GetAuthGameMode<ADMFFrontendGameMode>())
    {
        return EDMFMusicState::Frontend;
    }

    if (World->GetAuthGameMode<ADMFMMOGameMode>())
    {
        return EDMFMusicState::OpenWorld;
    }

    const UGameInstance* GameInstance = GetGameInstance();
    if (GameInstance && Cast<ADMFMMOPlayerController>(GameInstance->GetFirstLocalPlayerController(World)))
    {
        return EDMFMusicState::OpenWorld;
    }

    return EDMFMusicState::None;
}

bool UDMFMusicSubsystem::IsLocalPlayerInBattle() const
{
    UWorld* World = GetTickableGameObjectWorld();
    if (!World)
    {
        return false;
    }

    const UGameInstance* GameInstance = GetGameInstance();
    const ADMFMMOPlayerController* PlayerController = GameInstance
        ? Cast<ADMFMMOPlayerController>(GameInstance->GetFirstLocalPlayerController(World))
        : nullptr;
    const ADMFPlayerState* PlayerState = PlayerController ? PlayerController->GetPlayerState<ADMFPlayerState>() : nullptr;
    const UDMFPlayerDigimonComponent* DigimonComponent = PlayerState ? PlayerState->DigimonComponent : nullptr;
    const ADMFDigimonCharacter* Partner = DigimonComponent ? DigimonComponent->ActivePartnerActor : nullptr;
    const UDMFDigimonCombatComponent* Combat = Partner ? Partner->CombatComponent : nullptr;

    if (!Combat || Combat->IsDefeated())
    {
        return false;
    }

    const EDMFCombatState CombatState = Combat->GetCombatState();
    // Merely selecting a command target is not a battle. The soundtrack changes only after the
    // authoritative CombatComponent enters an active chase/attack/recovery state.
    return CombatState == EDMFCombatState::Chasing
        || CombatState == EDMFCombatState::Attacking
        || CombatState == EDMFCombatState::Recovering;
}

USoundBase* UDMFMusicSubsystem::ResolveSoundForState(const EDMFMusicState State) const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings)
    {
        return nullptr;
    }

    const TSoftObjectPtr<USoundBase>* SelectedMusic = nullptr;
    switch (State)
    {
        case EDMFMusicState::Frontend:
            SelectedMusic = &Settings->FrontendMusic;
            break;
        case EDMFMusicState::OpenWorld:
            SelectedMusic = &Settings->OpenWorldMusic;
            break;
        case EDMFMusicState::Battle:
            // A missing Battle cue intentionally degrades to exploration music instead of producing silence.
            SelectedMusic = Settings->BattleMusic.IsNull() ? &Settings->OpenWorldMusic : &Settings->BattleMusic;
            break;
        default:
            break;
    }

    return SelectedMusic && !SelectedMusic->IsNull() ? SelectedMusic->LoadSynchronous() : nullptr;
}

float UDMFMusicSubsystem::ResolveVolumeForState(const EDMFMusicState State) const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings)
    {
        return 1.0f;
    }

    float StateVolume = 1.0f;
    switch (State)
    {
        case EDMFMusicState::Frontend:
            StateVolume = Settings->FrontendMusicVolume;
            break;
        case EDMFMusicState::OpenWorld:
            StateVolume = Settings->OpenWorldMusicVolume;
            break;
        case EDMFMusicState::Battle:
            StateVolume = Settings->BattleMusicVolume;
            break;
        default:
            StateVolume = 0.0f;
            break;
    }

    return FMath::Max(0.0f, Settings->MusicMasterVolume) * FMath::Max(0.0f, StateVolume);
}

void UDMFMusicSubsystem::TransitionToState(const EDMFMusicState NewState)
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UWorld* World = GetTickableGameObjectWorld();
    const float FadeSeconds = Settings ? FMath::Max(0.0f, Settings->MusicCrossfadeSeconds) : 0.0f;
    USoundBase* DesiredSound = NewState == EDMFMusicState::None ? nullptr : ResolveSoundForState(NewState);
    const float DesiredVolume = ResolveVolumeForState(NewState);

    const EDMFMusicState PreviousState = CurrentMusicState;
    const bool bSemanticStateChanged = PreviousState != NewState;
    const bool bSoundChanged = CurrentSound.Get() != DesiredSound || (DesiredSound && !IsValid(CurrentAudioComponent));

    CurrentMusicState = NewState;

    if (!bSoundChanged && IsValid(CurrentAudioComponent))
    {
        CurrentAudioComponent->SetVolumeMultiplier(DesiredVolume);
        if (DesiredSound && !CurrentAudioComponent->IsPlaying())
        {
            CurrentAudioComponent->Play(0.0f);
        }
    }
    else if (bSoundChanged)
    {
        CleanupFadingComponent(true);

        if (IsValid(CurrentAudioComponent))
        {
            if (FadeSeconds > 0.0f && CurrentAudioComponent->IsPlaying())
            {
                CurrentAudioComponent->FadeOut(FadeSeconds, 0.0f, EAudioFaderCurve::Linear);
                FadingAudioComponent = CurrentAudioComponent;
                FadingCleanupTimeRemaining = FadeSeconds + 0.10f;
            }
            else
            {
                CurrentAudioComponent->Stop();
                CurrentAudioComponent->DestroyComponent();
            }
        }

        CurrentAudioComponent = nullptr;
        CurrentSound = DesiredSound;

        if (DesiredSound && World)
        {
            // Persistent-across-travel audio lets Frontend music continue naturally through the loading boundary;
            // the next world evaluation then crossfades it into Open World music instead of cutting abruptly.
            CurrentAudioComponent = UGameplayStatics::CreateSound2D(
                World,
                DesiredSound,
                DesiredVolume,
                1.0f,
                0.0f,
                nullptr,
                true,
                false);

            if (IsValid(CurrentAudioComponent))
            {
                if (FadeSeconds > 0.0f)
                {
                    CurrentAudioComponent->FadeIn(FadeSeconds, 1.0f, 0.0f, EAudioFaderCurve::Linear);
                }
                else
                {
                    CurrentAudioComponent->Play(0.0f);
                }
            }
        }
    }
    else if (!DesiredSound && IsValid(CurrentAudioComponent))
    {
        // Defensive cleanup for a state with no configured track.
        CurrentAudioComponent->Stop();
        CurrentAudioComponent->DestroyComponent();
        CurrentAudioComponent = nullptr;
        CurrentSound = nullptr;
    }

    if (bSemanticStateChanged)
    {
        OnMusicStateChanged.Broadcast(PreviousState, NewState);
    }
}

void UDMFMusicSubsystem::CleanupFadingComponent(const bool bForce)
{
    if (!IsValid(FadingAudioComponent))
    {
        FadingAudioComponent = nullptr;
        FadingCleanupTimeRemaining = 0.0f;
        return;
    }

    if (bForce || FadingCleanupTimeRemaining <= 0.0f || !FadingAudioComponent->IsPlaying())
    {
        FadingAudioComponent->Stop();
        FadingAudioComponent->DestroyComponent();
        FadingAudioComponent = nullptr;
        FadingCleanupTimeRemaining = 0.0f;
    }
}

void UDMFMusicSubsystem::StopAllMusic()
{
    if (IsValid(CurrentAudioComponent))
    {
        CurrentAudioComponent->Stop();
        CurrentAudioComponent->DestroyComponent();
        CurrentAudioComponent = nullptr;
    }

    CleanupFadingComponent(true);
    CurrentSound = nullptr;
    CurrentMusicState = EDMFMusicState::None;
    BattleReleaseTimeRemaining = 0.0f;
    bBattleCurrentlyObserved = false;
}

bool UDMFMusicSubsystem::DoesWorldMatchMap(const UWorld* World, const TSoftObjectPtr<UWorld>& MapAsset)
{
    if (!World || MapAsset.IsNull())
    {
        return false;
    }

    const FString ConfiguredMapName = MapAsset.ToSoftObjectPath().GetAssetName();
    if (ConfiguredMapName.IsEmpty())
    {
        return false;
    }

    // PIE prefixes the runtime world name (for example UEDPIE_1_OpenWorld). EndsWith keeps the comparison
    // deterministic in editor, standalone and packaged builds without depending on editor-only helpers.
    return World->GetName().EndsWith(ConfiguredMapName, ESearchCase::IgnoreCase);
}
