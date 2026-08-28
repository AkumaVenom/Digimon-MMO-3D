#include "Game/DMFDayNightSky.h"

#include "Components/DirectionalLightComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkyAtmosphereComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DigimonMMOFramework.h"
#include "Engine/StaticMesh.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "GameFramework/GameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "Misc/Timespan.h"
#include "Net/UnrealNetwork.h"
#include "Persistence/DMFWorldStateSaveGame.h"
#include "Settings/DMFFrameworkSettings.h"
#include "TimerManager.h"

namespace
{
    constexpr float DMFHoursPerDay = 24.0f;
}

ADMFDayNightSky::ADMFDayNightSky()
{
    bReplicates = true;
    bAlwaysRelevant = true;
    SetReplicateMovement(false);
    NetUpdateFrequency = 2.0f;
    MinNetUpdateFrequency = 0.5f;
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickInterval = VisualUpdateIntervalSeconds;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    SunLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("SunLight"));
    SunLightComponent->SetupAttachment(SceneRoot);
    SunLightComponent->SetMobility(EComponentMobility::Movable);
    SunLightComponent->SetAtmosphereSunLight(true);
    SunLightComponent->SetAtmosphereSunLightIndex(0);

    MoonLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("MoonLight"));
    MoonLightComponent->SetupAttachment(SceneRoot);
    MoonLightComponent->SetMobility(EComponentMobility::Movable);
    MoonLightComponent->SetAtmosphereSunLight(true);
    MoonLightComponent->SetAtmosphereSunLightIndex(1);

    SkyLightComponent = CreateDefaultSubobject<USkyLightComponent>(TEXT("SkyLight"));
    SkyLightComponent->SetupAttachment(SceneRoot);
    SkyLightComponent->SetMobility(EComponentMobility::Movable);

    SkyAtmosphereComponent = CreateDefaultSubobject<USkyAtmosphereComponent>(TEXT("SkyAtmosphere"));
    SkyAtmosphereComponent->SetupAttachment(SceneRoot);

    SkyDomeComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SkyDome"));
    SkyDomeComponent->SetupAttachment(SceneRoot);
    SkyDomeComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SkyDomeComponent->SetGenerateOverlapEvents(false);
    SkyDomeComponent->SetCanEverAffectNavigation(false);
    SkyDomeComponent->SetCastShadow(false);

    DigitalInnerSkyLayerComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DigitalInnerSkyLayer"));
    DigitalInnerSkyLayerComponent->SetupAttachment(SceneRoot);
    DigitalInnerSkyLayerComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    DigitalInnerSkyLayerComponent->SetGenerateOverlapEvents(false);
    DigitalInnerSkyLayerComponent->SetCanEverAffectNavigation(false);
    DigitalInnerSkyLayerComponent->SetCastShadow(false);
    DigitalInnerSkyLayerComponent->SetTranslucentSortPriority(1);
}

void ADMFDayNightSky::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    InitialSimulatedTimeHours = WrapHours(InitialSimulatedTimeHours);
    DayStartHour = WrapHours(DayStartHour);
    NightStartHour = WrapHours(NightStartHour);
    SimulatedDayLengthSeconds = FMath::Max(10.0f, SimulatedDayLengthSeconds);
    TimeReplicationIntervalSeconds = FMath::Max(0.25f, TimeReplicationIntervalSeconds);
    VisualUpdateIntervalSeconds = FMath::Clamp(VisualUpdateIntervalSeconds, 0.016f, 1.0f);
    PersistenceAutosaveIntervalSeconds = FMath::Max(5.0f, PersistenceAutosaveIntervalSeconds);
    DigitalInnerLayerScaleMultiplier = FMath::Clamp(DigitalInnerLayerScaleMultiplier, 0.01f, 1.0f);

    if (SunLightComponent)
    {
        SunLightComponent->SetVisibility(bDriveNativeDirectionalLights, true);
    }
    if (MoonLightComponent)
    {
        MoonLightComponent->SetVisibility(bDriveNativeDirectionalLights, true);
    }
    if (SkyLightComponent)
    {
        SkyLightComponent->SetVisibility(bEnableNativeSkyLight, true);
    }
    if (SkyAtmosphereComponent)
    {
        SkyAtmosphereComponent->SetVisibility(bEnableNativeSkyAtmosphere, true);
    }

    if (SkyDomeComponent)
    {
        SkyDomeComponent->SetStaticMesh(SkyDomeMesh);
        SkyDomeComponent->SetRelativeScale3D(SkyDomeScale);
        if (SkyDomeMaterial)
        {
            SkyDomeComponent->SetMaterial(0, SkyDomeMaterial);
        }
    }

    if (DigitalInnerSkyLayerComponent)
    {
        UStaticMesh* EffectiveInnerMesh = DigitalInnerLayerMesh ? DigitalInnerLayerMesh.Get() : SkyDomeMesh.Get();
        DigitalInnerSkyLayerComponent->SetStaticMesh(EffectiveInnerMesh);
        DigitalInnerSkyLayerComponent->SetRelativeScale3D(SkyDomeScale * DigitalInnerLayerScaleMultiplier);
        DigitalInnerSkyLayerComponent->SetVisibility(bEnableDigitalInnerLayer, true);
        if (DigitalInnerLayerMaterial)
        {
            DigitalInnerSkyLayerComponent->SetMaterial(0, DigitalInnerLayerMaterial);
        }
    }

    PrimaryActorTick.TickInterval = VisualUpdateIntervalSeconds;

    // Construction-time/editor preview uses the authored clock directly. It deliberately does not touch
    // persistent world-state saves or network authority, so designers can scrub InitialSimulatedTimeHours
    // and immediately see the same canonical sun/moon/material result that runtime will use.
    if (bPreviewSkyInEditor && IsEditorPreviewWorld())
    {
        RefreshSkyPresentation();
    }
}

#if WITH_EDITOR
void ADMFDayNightSky::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    if (!IsTemplate() && bPreviewSkyInEditor && IsEditorPreviewWorld())
    {
        RefreshSkyPresentation();
    }
}
#endif

void ADMFDayNightSky::BeginPlay()
{
    Super::BeginPlay();

    PrimaryActorTick.TickInterval = FMath::Clamp(VisualUpdateIntervalSeconds, 0.016f, 1.0f);
    const bool bDedicatedServer = GetNetMode() == NM_DedicatedServer;
    if (bDedicatedServer)
    {
        SetActorTickEnabled(false);
    }

    if (HasAuthority())
    {
        ReplicatedTimeSource = TimeSource;
        ReplicatedSimulatedDayLengthSeconds = FMath::Max(10.0f, SimulatedDayLengthSeconds);

        bool bLoaded = false;
        if (ReplicatedTimeSource == EDMFDayNightTimeSource::Simulated && bSaveAndLoadSimulatedTime)
        {
            bLoaded = LoadPersistedSimulatedTime();
        }
        if (!bLoaded)
        {
            ResetAuthorityAnchor(InitialSimulatedTimeHours, 0);
        }

        SynchronizeAuthorityTime(true);

        if (UWorld* World = GetWorld())
        {
            World->GetTimerManager().SetTimer(
                AuthoritySyncTimer,
                this,
                &ADMFDayNightSky::HandleAuthoritySyncTimer,
                FMath::Max(0.25f, TimeReplicationIntervalSeconds),
                true,
                FMath::Max(0.25f, TimeReplicationIntervalSeconds));

            if (ReplicatedTimeSource == EDMFDayNightTimeSource::Simulated && bSaveAndLoadSimulatedTime)
            {
                World->GetTimerManager().SetTimer(
                    PersistenceTimer,
                    this,
                    &ADMFDayNightSky::HandlePersistenceTimer,
                    FMath::Max(5.0f, PersistenceAutosaveIntervalSeconds),
                    true,
                    FMath::Max(5.0f, PersistenceAutosaveIntervalSeconds));
            }
        }
    }
    else
    {
        ApplyPhase(DayNightPhase, false);
    }

    // Build the visual presentation only after the authoritative/client clock state above has been initialized.
    // The previous order built the sky against default anchors first, which could capture the wrong phase on startup.
    if (!bDedicatedServer)
    {
        RefreshSkyPresentation();
    }
}

void ADMFDayNightSky::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (HasAuthority() && ReplicatedTimeSource == EDMFDayNightTimeSource::Simulated && bSaveAndLoadSimulatedTime)
    {
        SaveDayNightStateNow();
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(AuthoritySyncTimer);
        World->GetTimerManager().ClearTimer(PersistenceTimer);
    }

    Super::EndPlay(EndPlayReason);
}

void ADMFDayNightSky::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    ApplySkyVisuals(GetTimeOfDayHours());
}

void ADMFDayNightSky::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFDayNightSky, ReplicatedTimeOfDayHours);
    DOREPLIFETIME(ADMFDayNightSky, ReplicatedDayIndex);
    DOREPLIFETIME(ADMFDayNightSky, ReplicatedTimeSource);
    DOREPLIFETIME(ADMFDayNightSky, ReplicatedTimeAnchorServerSeconds);
    DOREPLIFETIME(ADMFDayNightSky, ReplicatedSimulatedDayLengthSeconds);
    DOREPLIFETIME(ADMFDayNightSky, DayNightPhase);
}

float ADMFDayNightSky::WrapHours(const float Hours)
{
    float Wrapped = FMath::Fmod(Hours, DMFHoursPerDay);
    if (Wrapped < 0.0f)
    {
        Wrapped += DMFHoursPerDay;
    }
    return Wrapped;
}

double ADMFDayNightSky::GetSynchronizedServerWorldSeconds() const
{
    if (const UWorld* World = GetWorld())
    {
        if (const AGameStateBase* GameState = World->GetGameState())
        {
            return static_cast<double>(GameState->GetServerWorldTimeSeconds());
        }
        return static_cast<double>(World->GetTimeSeconds());
    }
    return 0.0;
}

void ADMFDayNightSky::CalculateAuthorityTime(float& OutTimeHours, int32& OutDayIndex) const
{
    if (ReplicatedTimeSource == EDMFDayNightTimeSource::HostSystemTime)
    {
        const FDateTime LocalNow = FDateTime::Now();
        OutTimeHours = static_cast<float>(LocalNow.GetHour())
            + (static_cast<float>(LocalNow.GetMinute()) / 60.0f)
            + (static_cast<float>(LocalNow.GetSecond()) / 3600.0f)
            + (static_cast<float>(LocalNow.GetMillisecond()) / 3600000.0f);
        // Gregorian whole-day key that advances at local midnight (Julian Day changes at noon, so it is
        // deliberately not used here). This keeps the exposed day index and cross-midnight client
        // interpolation aligned with the host machine's actual local calendar day.
        const int64 TicksPerDay = FTimespan::FromDays(1.0).GetTicks();
        OutDayIndex = TicksPerDay > 0 ? static_cast<int32>(LocalNow.GetDate().GetTicks() / TicksPerDay) : 0;
        return;
    }

    const double ElapsedSeconds = FMath::Max(0.0, GetSynchronizedServerWorldSeconds() - AuthorityAnchorServerSeconds);
    const double DayLength = FMath::Max(10.0, static_cast<double>(SimulatedDayLengthSeconds));
    const double TotalHours = static_cast<double>(AuthorityAnchorTimeHours) + ((ElapsedSeconds / DayLength) * static_cast<double>(DMFHoursPerDay));
    const int32 AddedDays = FMath::FloorToInt(TotalHours / static_cast<double>(DMFHoursPerDay));
    OutTimeHours = WrapHours(static_cast<float>(TotalHours));
    OutDayIndex = AuthorityAnchorDayIndex + AddedDays;
}

float ADMFDayNightSky::GetTimeOfDayHours() const
{
    if (HasAuthority())
    {
        float AuthorityHours = ReplicatedTimeOfDayHours;
        int32 AuthorityDay = ReplicatedDayIndex;
        CalculateAuthorityTime(AuthorityHours, AuthorityDay);
        return AuthorityHours;
    }

    const double ElapsedSeconds = FMath::Max(0.0, GetSynchronizedServerWorldSeconds() - ReplicatedTimeAnchorServerSeconds);
    const double HoursPerSecond = ReplicatedTimeSource == EDMFDayNightTimeSource::HostSystemTime
        ? (1.0 / 3600.0)
        : (static_cast<double>(DMFHoursPerDay) / FMath::Max(10.0, static_cast<double>(ReplicatedSimulatedDayLengthSeconds)));
    return WrapHours(ReplicatedTimeOfDayHours + static_cast<float>(ElapsedSeconds * HoursPerSecond));
}

FText ADMFDayNightSky::GetFormattedTime12Hour(const bool bIncludeSeconds) const
{
    const float WrappedHours = WrapHours(GetTimeOfDayHours());
    const int32 TotalSeconds = FMath::FloorToInt(WrappedHours * 3600.0f + KINDA_SMALL_NUMBER) % (24 * 60 * 60);
    const int32 Hour24 = TotalSeconds / 3600;
    const int32 Minute = (TotalSeconds / 60) % 60;
    const int32 Second = TotalSeconds % 60;
    const int32 Hour12 = Hour24 % 12 == 0 ? 12 : Hour24 % 12;
    const TCHAR* Meridiem = Hour24 >= 12 ? TEXT("PM") : TEXT("AM");

    return bIncludeSeconds
        ? FText::FromString(FString::Printf(TEXT("%d:%02d:%02d %s"), Hour12, Minute, Second, Meridiem))
        : FText::FromString(FString::Printf(TEXT("%d:%02d %s"), Hour12, Minute, Meridiem));
}

float ADMFDayNightSky::GetTimeOfDayNormalized() const
{
    return GetTimeOfDayHours() / DMFHoursPerDay;
}

int32 ADMFDayNightSky::GetCurrentDayIndex() const
{
    if (HasAuthority())
    {
        float AuthorityHours = 0.0f;
        int32 AuthorityDay = 0;
        CalculateAuthorityTime(AuthorityHours, AuthorityDay);
        return AuthorityDay;
    }

    const double ElapsedSeconds = FMath::Max(0.0, GetSynchronizedServerWorldSeconds() - ReplicatedTimeAnchorServerSeconds);
    const double HoursPerSecond = ReplicatedTimeSource == EDMFDayNightTimeSource::HostSystemTime
        ? (1.0 / 3600.0)
        : (static_cast<double>(DMFHoursPerDay) / FMath::Max(10.0, static_cast<double>(ReplicatedSimulatedDayLengthSeconds)));
    const double TotalHours = static_cast<double>(ReplicatedTimeOfDayHours) + (ElapsedSeconds * HoursPerSecond);
    return ReplicatedDayIndex + FMath::FloorToInt(TotalHours / static_cast<double>(DMFHoursPerDay));
}

bool ADMFDayNightSky::EvaluateIsDay(const float TimeHours) const
{
    const float Hours = WrapHours(TimeHours);
    const float Start = WrapHours(DayStartHour);
    const float End = WrapHours(NightStartHour);
    if (FMath::IsNearlyEqual(Start, End))
    {
        return true; // Equal bounds deliberately mean a full-day schedule, not a zero-length day.
    }
    if (Start < End)
    {
        return Hours >= Start && Hours < End;
    }
    return Hours >= Start || Hours < End;
}

void ADMFDayNightSky::ApplyPhase(const EDMFDayNightPhase NewPhase, const bool bBroadcast)
{
    const EDMFDayNightPhase PreviousPhase = DayNightPhase;
    DayNightPhase = NewPhase;
    bIsDay = DayNightPhase == EDMFDayNightPhase::Day;
    bIsNight = !bIsDay;

    if (PreviousPhase != DayNightPhase
        && bEnableNativeSkyLight
        && bRecaptureNativeSkyLightOnPhaseChange
        && SkyLightComponent
        && GetNetMode() != NM_DedicatedServer)
    {
        // Defer until ApplySkyVisuals has moved the celestial lights/materials to the new phase.
        bPendingNativeSkyLightRecapture = true;
    }

    if (bBroadcast && PreviousPhase != DayNightPhase)
    {
        OnDayNightPhaseChanged.Broadcast(DayNightPhase, PreviousPhase);
        BP_OnDayNightPhaseChanged(DayNightPhase, PreviousPhase);
    }
}

void ADMFDayNightSky::SynchronizeAuthorityTime(const bool bForceNetUpdate)
{
    if (!HasAuthority())
    {
        return;
    }

    float CurrentHours = 0.0f;
    int32 CurrentDay = 0;
    CalculateAuthorityTime(CurrentHours, CurrentDay);

    ReplicatedTimeSource = TimeSource;
    ReplicatedTimeOfDayHours = CurrentHours;
    ReplicatedDayIndex = CurrentDay;
    ReplicatedTimeAnchorServerSeconds = GetSynchronizedServerWorldSeconds();
    ReplicatedSimulatedDayLengthSeconds = FMath::Max(10.0f, SimulatedDayLengthSeconds);

    ApplyPhase(EvaluateIsDay(CurrentHours) ? EDMFDayNightPhase::Day : EDMFDayNightPhase::Night, true);
    OnTimeSynchronized.Broadcast(ReplicatedTimeOfDayHours, ReplicatedDayIndex, ReplicatedTimeSource);

    if (bForceNetUpdate)
    {
        ForceNetUpdate();
    }
}

void ADMFDayNightSky::ResetAuthorityAnchor(const float TimeHours, const int32 DayIndex)
{
    AuthorityAnchorTimeHours = WrapHours(TimeHours);
    AuthorityAnchorDayIndex = DayIndex;
    AuthorityAnchorServerSeconds = GetSynchronizedServerWorldSeconds();
    ReplicatedTimeOfDayHours = AuthorityAnchorTimeHours;
    ReplicatedDayIndex = AuthorityAnchorDayIndex;
    ReplicatedTimeAnchorServerSeconds = AuthorityAnchorServerSeconds;
}

void ADMFDayNightSky::SetAuthoritativeTimeSource(const EDMFDayNightTimeSource NewTimeSource, const bool bSaveImmediately)
{
    if (!HasAuthority())
    {
        return;
    }

    if (ReplicatedTimeSource == EDMFDayNightTimeSource::Simulated)
    {
        float CurrentHours = 0.0f;
        int32 CurrentDay = 0;
        CalculateAuthorityTime(CurrentHours, CurrentDay);
        ResetAuthorityAnchor(CurrentHours, CurrentDay);
    }

    TimeSource = NewTimeSource;
    ReplicatedTimeSource = NewTimeSource;
    if (NewTimeSource == EDMFDayNightTimeSource::Simulated)
    {
        ResetAuthorityAnchor(ReplicatedTimeOfDayHours, ReplicatedDayIndex);
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(PersistenceTimer);
        if (NewTimeSource == EDMFDayNightTimeSource::Simulated && bSaveAndLoadSimulatedTime)
        {
            World->GetTimerManager().SetTimer(
                PersistenceTimer,
                this,
                &ADMFDayNightSky::HandlePersistenceTimer,
                FMath::Max(5.0f, PersistenceAutosaveIntervalSeconds),
                true,
                FMath::Max(5.0f, PersistenceAutosaveIntervalSeconds));
        }
    }

    SynchronizeAuthorityTime(true);
    if (bSaveImmediately && NewTimeSource == EDMFDayNightTimeSource::Simulated && bSaveAndLoadSimulatedTime)
    {
        SaveDayNightStateNow();
    }
}

void ADMFDayNightSky::SetSimulatedTimeOfDay(const float NewTimeOfDayHours, const int32 NewDayIndex, const bool bSaveImmediately)
{
    if (!HasAuthority() || ReplicatedTimeSource != EDMFDayNightTimeSource::Simulated)
    {
        return;
    }

    ResetAuthorityAnchor(NewTimeOfDayHours, NewDayIndex);
    SynchronizeAuthorityTime(true);
    if (bSaveImmediately && bSaveAndLoadSimulatedTime)
    {
        SaveDayNightStateNow();
    }
}

void ADMFDayNightSky::AdvanceSimulatedTimeByHours(const float DeltaHours, const bool bSaveImmediately)
{
    if (!HasAuthority() || ReplicatedTimeSource != EDMFDayNightTimeSource::Simulated || !FMath::IsFinite(DeltaHours))
    {
        return;
    }

    float CurrentHours = 0.0f;
    int32 CurrentDay = 0;
    CalculateAuthorityTime(CurrentHours, CurrentDay);
    const double Total = static_cast<double>(CurrentHours) + static_cast<double>(DeltaHours);
    const int32 AddedDays = FMath::FloorToInt(Total / static_cast<double>(DMFHoursPerDay));
    ResetAuthorityAnchor(WrapHours(static_cast<float>(Total)), CurrentDay + AddedDays);
    SynchronizeAuthorityTime(true);
    if (bSaveImmediately && bSaveAndLoadSimulatedTime)
    {
        SaveDayNightStateNow();
    }
}

FString ADMFDayNightSky::BuildPersistenceKey() const
{
    const FString MapName = UGameplayStatics::GetCurrentLevelName(this, true);
    const FString StableId = PersistenceId.IsNone() ? TEXT("WorldSky") : PersistenceId.ToString();
    return FString::Printf(TEXT("%s|%s"), *MapName, *StableId);
}

bool ADMFDayNightSky::LoadPersistedSimulatedTime()
{
    if (!HasAuthority() || !bSaveAndLoadSimulatedTime)
    {
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const FString SlotName = Settings ? Settings->WorldStateSaveSlot : TEXT("DMF_ServerWorldState");
    if (!UGameplayStatics::DoesSaveGameExist(SlotName, 0))
    {
        return false;
    }

    UDMFWorldStateSaveGame* Save = Cast<UDMFWorldStateSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
    if (!Save)
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Day/night sky %s could not read world-state save slot %s."), *GetName(), *SlotName);
        return false;
    }

    const FDMFDayNightPersistentState* State = Save->DayNightStates.Find(BuildPersistenceKey());
    if (!State || !State->bHasSavedState || !FMath::IsFinite(State->TimeOfDayHours))
    {
        return false;
    }

    ResetAuthorityAnchor(State->TimeOfDayHours, State->DayIndex);
    UE_LOG(LogDigimonMMOFramework, Log, TEXT("Day/night sky %s restored simulated time %.2f hours (day %d)."), *GetName(), AuthorityAnchorTimeHours, AuthorityAnchorDayIndex);
    return true;
}

bool ADMFDayNightSky::SaveDayNightStateNow()
{
    if (!HasAuthority() || !bSaveAndLoadSimulatedTime || ReplicatedTimeSource != EDMFDayNightTimeSource::Simulated)
    {
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const FString SlotName = Settings ? Settings->WorldStateSaveSlot : TEXT("DMF_ServerWorldState");
    UDMFWorldStateSaveGame* Save = nullptr;
    if (UGameplayStatics::DoesSaveGameExist(SlotName, 0))
    {
        Save = Cast<UDMFWorldStateSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
    }
    if (!Save)
    {
        Save = Cast<UDMFWorldStateSaveGame>(UGameplayStatics::CreateSaveGameObject(UDMFWorldStateSaveGame::StaticClass()));
    }
    if (!Save)
    {
        return false;
    }

    float CurrentHours = 0.0f;
    int32 CurrentDay = 0;
    CalculateAuthorityTime(CurrentHours, CurrentDay);

    FDMFDayNightPersistentState& State = Save->DayNightStates.FindOrAdd(BuildPersistenceKey());
    State.bHasSavedState = true;
    State.TimeOfDayHours = CurrentHours;
    State.DayIndex = CurrentDay;
    State.SavedUtcTicks = FDateTime::UtcNow().GetTicks();

    const bool bSaved = UGameplayStatics::SaveGameToSlot(Save, SlotName, 0);
    if (!bSaved)
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Day/night sky %s failed to save world-state slot %s."), *GetName(), *SlotName);
    }
    return bSaved;
}

bool ADMFDayNightSky::ReloadDayNightState()
{
    if (!HasAuthority() || ReplicatedTimeSource != EDMFDayNightTimeSource::Simulated)
    {
        return false;
    }
    const bool bLoaded = LoadPersistedSimulatedTime();
    if (bLoaded)
    {
        SynchronizeAuthorityTime(true);
    }
    return bLoaded;
}

void ADMFDayNightSky::HandleAuthoritySyncTimer()
{
    SynchronizeAuthorityTime(true);
}

void ADMFDayNightSky::HandlePersistenceTimer()
{
    SaveDayNightStateNow();
}

float ADMFDayNightSky::CalculateDayVisualAlpha(const float TimeHours) const
{
    // Solar signal is -1 at midnight, 0 at 06:00/18:00, +1 at noon. A small band around the horizon
    // gives a gentle visual fade without changing the authoritative Day/Night phase thresholds.
    const float SolarRadians = ((WrapHours(TimeHours) - 6.0f) / DMFHoursPerDay) * (2.0f * PI);
    const float SolarSignal = FMath::Sin(SolarRadians);
    return FMath::Clamp((SolarSignal + 0.12f) / 0.24f, 0.0f, 1.0f);
}

void ADMFDayNightSky::RefreshSkyPresentation()
{
    if (SunLightComponent)
    {
        SunLightComponent->SetVisibility(bDriveNativeDirectionalLights, true);
    }
    if (MoonLightComponent)
    {
        MoonLightComponent->SetVisibility(bDriveNativeDirectionalLights, true);
    }
    if (SkyLightComponent)
    {
        SkyLightComponent->SetVisibility(bEnableNativeSkyLight, true);
    }
    if (SkyAtmosphereComponent)
    {
        SkyAtmosphereComponent->SetVisibility(bEnableNativeSkyAtmosphere, true);
    }

    if (SkyDomeComponent)
    {
        SkyDomeComponent->SetStaticMesh(SkyDomeMesh);
        SkyDomeComponent->SetRelativeScale3D(SkyDomeScale);
        UMaterialInterface* BaseMaterial = SkyDomeMaterial ? SkyDomeMaterial.Get() : SkyDomeComponent->GetMaterial(0);
        SkyDomeMID = BaseMaterial ? UMaterialInstanceDynamic::Create(BaseMaterial, this) : nullptr;
        if (SkyDomeMID)
        {
            SkyDomeComponent->SetMaterial(0, SkyDomeMID);
        }
    }

    if (DigitalInnerSkyLayerComponent)
    {
        UStaticMesh* EffectiveInnerMesh = DigitalInnerLayerMesh ? DigitalInnerLayerMesh.Get() : SkyDomeMesh.Get();
        DigitalInnerSkyLayerComponent->SetStaticMesh(EffectiveInnerMesh);
        DigitalInnerSkyLayerComponent->SetRelativeScale3D(SkyDomeScale * FMath::Clamp(DigitalInnerLayerScaleMultiplier, 0.01f, 1.0f));
        DigitalInnerSkyLayerComponent->SetVisibility(bEnableDigitalInnerLayer, true);

        UMaterialInterface* BaseMaterial = DigitalInnerLayerMaterial ? DigitalInnerLayerMaterial.Get() : DigitalInnerSkyLayerComponent->GetMaterial(0);
        DigitalInnerLayerMID = (bEnableDigitalInnerLayer && BaseMaterial) ? UMaterialInstanceDynamic::Create(BaseMaterial, this) : nullptr;
        if (DigitalInnerLayerMID)
        {
            DigitalInnerSkyLayerComponent->SetMaterial(0, DigitalInnerLayerMID);
            if (DigitalInnerLayerTexture && !DigitalInnerLayerTextureParameterName.IsNone())
            {
                DigitalInnerLayerMID->SetTextureParameterValue(DigitalInnerLayerTextureParameterName, DigitalInnerLayerTexture);
            }
            if (!DigitalInnerLayerOpacityParameterName.IsNone())
            {
                DigitalInnerLayerMID->SetScalarParameterValue(DigitalInnerLayerOpacityParameterName, FMath::Clamp(DigitalInnerLayerOpacity, 0.0f, 1.0f));
            }
            if (!DigitalInnerLayerTintParameterName.IsNone())
            {
                DigitalInnerLayerMID->SetVectorParameterValue(DigitalInnerLayerTintParameterName, DigitalInnerLayerTint);
            }
            if (!DigitalInnerLayerUVScaleParameterName.IsNone())
            {
                DigitalInnerLayerMID->SetVectorParameterValue(DigitalInnerLayerUVScaleParameterName, FLinearColor(DigitalInnerLayerUVScale.X, DigitalInnerLayerUVScale.Y, 0.0f, 0.0f));
            }
        }
    }

    const float PresentationHours = ResolvePresentationTimeHours();
    if (IsEditorPreviewWorld())
    {
        ApplyPhase(EvaluateIsDay(PresentationHours) ? EDMFDayNightPhase::Day : EDMFDayNightPhase::Night, false);
    }

    // Refresh performs its own single recapture after all presentation values are applied, so consume any
    // phase-change request here to avoid doing the expensive capture twice during one rebuild.
    bPendingNativeSkyLightRecapture = false;
    ApplySkyVisuals(PresentationHours);

    if (bEnableNativeSkyLight && SkyLightComponent && GetNetMode() != NM_DedicatedServer)
    {
        // Refresh is intentionally a one-shot presentation rebuild, so a single recapture here is appropriate
        // (editor scrubbing, BeginPlay initialization, or an explicit runtime material/asset refresh).
        SkyLightComponent->RecaptureSky();
        bPendingNativeSkyLightRecapture = false;
    }
}

bool ADMFDayNightSky::IsEditorPreviewWorld() const
{
    const UWorld* World = GetWorld();
    return World != nullptr && !World->IsGameWorld();
}

float ADMFDayNightSky::ResolvePresentationTimeHours() const
{
    if (IsEditorPreviewWorld())
    {
        if (TimeSource == EDMFDayNightTimeSource::HostSystemTime)
        {
            const FDateTime LocalNow = FDateTime::Now();
            return WrapHours(
                static_cast<float>(LocalNow.GetHour())
                + (static_cast<float>(LocalNow.GetMinute()) / 60.0f)
                + (static_cast<float>(LocalNow.GetSecond()) / 3600.0f));
        }
        return WrapHours(InitialSimulatedTimeHours);
    }

    return GetTimeOfDayHours();
}

void ADMFDayNightSky::ApplySkyVisuals(const float TimeHours, const bool bCallBlueprintPresentationEvent)
{
    const float Normalized = WrapHours(TimeHours) / DMFHoursPerDay;
    const float DayVisualAlpha = CalculateDayVisualAlpha(TimeHours);
    // UE directional-light forward is the light-ray travel direction. Noon therefore needs a -90 degree
    // pitch (rays travel downward from overhead), midnight +90, with dawn/dusk on the horizon. The previous
    // sign was inverted, placing the native sun below the horizon at noon and making daytime look like night.
    const float SunPitch = 90.0f - (Normalized * 360.0f) + SunPitchOffsetDegrees;
    const FRotator SunRotation(SunPitch, SunYawDegrees, 0.0f);

    if (bDriveNativeDirectionalLights)
    {
        if (SunLightComponent)
        {
            SunLightComponent->SetWorldRotation(SunRotation);
            SunLightComponent->SetIntensity(FMath::Max(0.0f, MaximumSunIntensity) * DayVisualAlpha);
            SunLightComponent->SetLightColor(SunLightColor);
        }
        if (MoonLightComponent)
        {
            MoonLightComponent->SetWorldRotation(FRotator(SunPitch + 180.0f, SunYawDegrees, 0.0f));
            MoonLightComponent->SetIntensity(FMath::Max(0.0f, MaximumMoonIntensity) * (1.0f - DayVisualAlpha));
            MoonLightComponent->SetLightColor(MoonLightColor);
        }
    }

    // Materials generally want a vector from the world toward the sun, which is opposite the directional
    // light's ray-travel/forward vector.
    const FVector SunDirection = -SunRotation.Vector();
    auto PushSharedMaterialParameters = [&](UMaterialInstanceDynamic* MID)
    {
        if (!MID)
        {
            return;
        }
        if (!TimeOfDayNormalizedParameterName.IsNone())
        {
            MID->SetScalarParameterValue(TimeOfDayNormalizedParameterName, Normalized);
        }
        if (!DayVisualAlphaParameterName.IsNone())
        {
            MID->SetScalarParameterValue(DayVisualAlphaParameterName, DayVisualAlpha);
        }
        if (!SunDirectionParameterName.IsNone())
        {
            MID->SetVectorParameterValue(SunDirectionParameterName, FLinearColor(SunDirection.X, SunDirection.Y, SunDirection.Z, 1.0f));
        }
    };

    PushSharedMaterialParameters(SkyDomeMID);
    PushSharedMaterialParameters(DigitalInnerLayerMID);

    // A large number of project/marketplace sky-sphere materials predate the framework and draw their visible
    // sun from the conventional Unreal `Light direction` + `Sun height` parameters. The authoritative light was
    // already rotating correctly, but a material using those legacy parameters would leave its painted sun disc
    // fixed in place. Push the same canonical solar solution into that compatibility contract every local visual
    // update. This moves only the material's sun calculation; the sky dome itself is never rotated, so cloud and
    // digital-layer UV presentation stays independent and no network bandwidth is added.
    if (SkyDomeMID && bDriveSkyDomeSolarVisualParameters)
    {
        const FVector LightRayDirection = SunRotation.Vector();
        if (!SkyDomeLightDirectionParameterName.IsNone())
        {
            SkyDomeMID->SetVectorParameterValue(
                SkyDomeLightDirectionParameterName,
                FLinearColor(LightRayDirection.X, LightRayDirection.Y, LightRayDirection.Z, 1.0f));
        }
        if (!SkyDomeSunHeightParameterName.IsNone())
        {
            SkyDomeMID->SetScalarParameterValue(
                SkyDomeSunHeightParameterName,
                FMath::Clamp(SunDirection.Z, -1.0f, 1.0f));
        }
    }

    if (DigitalInnerLayerMID && !DigitalInnerLayerUVOffsetParameterName.IsNone())
    {
        // Use synchronized server-world time so the cheap UV animation is phase-aligned on host and remote clients.
        const float SynchronizedSeconds = static_cast<float>(GetSynchronizedServerWorldSeconds());
        const float OffsetX = FMath::Frac(SynchronizedSeconds * DigitalInnerLayerPanSpeed.X);
        const float OffsetY = FMath::Frac(SynchronizedSeconds * DigitalInnerLayerPanSpeed.Y);
        DigitalInnerLayerMID->SetVectorParameterValue(DigitalInnerLayerUVOffsetParameterName, FLinearColor(OffsetX, OffsetY, 0.0f, 0.0f));
    }

    if (bPendingNativeSkyLightRecapture
        && bEnableNativeSkyLight
        && bRecaptureNativeSkyLightOnPhaseChange
        && SkyLightComponent
        && GetNetMode() != NM_DedicatedServer)
    {
        SkyLightComponent->RecaptureSky();
        bPendingNativeSkyLightRecapture = false;
    }

    if (bCallBlueprintPresentationEvent)
    {
        BP_OnSkyVisualUpdate(WrapHours(TimeHours), Normalized, DayVisualAlpha);
    }
}

void ADMFDayNightSky::OnRep_TimeAnchor()
{
    OnTimeSynchronized.Broadcast(ReplicatedTimeOfDayHours, ReplicatedDayIndex, ReplicatedTimeSource);
    ApplySkyVisuals(GetTimeOfDayHours());
}

void ADMFDayNightSky::OnRep_DayNightPhase(const EDMFDayNightPhase PreviousPhase)
{
    bIsDay = DayNightPhase == EDMFDayNightPhase::Day;
    bIsNight = !bIsDay;
    if (PreviousPhase != DayNightPhase
        && bEnableNativeSkyLight
        && bRecaptureNativeSkyLightOnPhaseChange
        && SkyLightComponent
        && GetNetMode() != NM_DedicatedServer)
    {
        bPendingNativeSkyLightRecapture = true;
    }
    if (PreviousPhase != DayNightPhase)
    {
        OnDayNightPhaseChanged.Broadcast(DayNightPhase, PreviousPhase);
        BP_OnDayNightPhaseChanged(DayNightPhase, PreviousPhase);
    }
}
