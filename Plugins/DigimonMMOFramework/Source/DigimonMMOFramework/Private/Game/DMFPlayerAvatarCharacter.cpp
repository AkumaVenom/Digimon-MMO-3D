#include "Game/DMFPlayerAvatarCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Components/InputComponent.h"
#include "Components/MeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Data/DMFPlayerSkinData.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Game/DMFPlayerState.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFDigimonVendorActor.h"
#include "Game/DMFHealerActor.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFSwimmableWater.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/LocalPlayer.h"
#include "EngineUtils.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInterface.h"
#include "DrawDebugHelpers.h"
#include "Net/UnrealNetwork.h"
#include "Settings/DMFFrameworkSettings.h"
#include "Sound/SoundBase.h"
#include "UI/DMFWorldNameplateWidget.h"

ADMFPlayerAvatarCharacter::ADMFPlayerAvatarCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;
    SetReplicateMovement(true);

    GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    UCharacterMovementComponent* Movement = GetCharacterMovement();
    Movement->bOrientRotationToMovement = true;
    Movement->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
    Movement->JumpZVelocity = 700.0f;
    Movement->AirControl = 0.35f;
    Movement->MaxWalkSpeed = WalkSpeed;
    Movement->GetNavAgentPropertiesRef().bCanCrouch = true;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 400.0f;
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->bEnableCameraLag = true;
    CameraBoom->CameraLagSpeed = 12.0f;
    // Keep world obstruction handling, but framework Players/Digimon can be globally forced to ignore ECC_Camera.
    CameraBoom->bDoCollisionTest = true;
    CameraBoom->ProbeChannel = ECC_Camera;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    UnderwaterPostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("UnderwaterPostProcess"));
    UnderwaterPostProcessComponent->SetupAttachment(FollowCamera);
    UnderwaterPostProcessComponent->bUnbound = true;
    UnderwaterPostProcessComponent->Priority = 1000.0f;
    UnderwaterPostProcessComponent->BlendWeight = 0.0f;
    UnderwaterPostProcessComponent->bEnabled = false;

    // A native exponential fog layer supplies the distance extinction that color grading alone cannot create.
    // It follows the local swimmer so the tiny height falloff remains effectively camera-relative, and starts
    // invisible/zero-density so remote proxies and normal gameplay contribute no fog presentation.
    UnderwaterDistanceFogComponent = CreateDefaultSubobject<UExponentialHeightFogComponent>(TEXT("UnderwaterDistanceFog"));
    UnderwaterDistanceFogComponent->SetMobility(EComponentMobility::Movable);
    UnderwaterDistanceFogComponent->SetupAttachment(RootComponent);
    UnderwaterDistanceFogComponent->SetFogDensity(0.0f);
    UnderwaterDistanceFogComponent->SetFogHeightFalloff(0.001f);
    UnderwaterDistanceFogComponent->SetFogMaxOpacity(0.0f);
    UnderwaterDistanceFogComponent->SetStartDistance(0.0f);
    UnderwaterDistanceFogComponent->SetVisibility(false, true);

    NameplateWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("PlayerNameplateWidget"));
    NameplateWidgetComponent->SetupAttachment(RootComponent);
    NameplateWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
    NameplateWidgetComponent->SetDrawAtDesiredSize(true);
    NameplateWidgetComponent->SetPivot(FVector2D(0.5f, 1.0f));
    NameplateWidgetComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    NameplateWidgetComponent->SetGenerateOverlapEvents(false);
    NameplateWidgetComponent->SetWidgetClass(UDMFWorldNameplateWidget::StaticClass());

    GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FRotator(0.0f, -90.0f, 0.0f));
    GetMesh()->SetRenderCustomDepth(true);
}

void ADMFPlayerAvatarCharacter::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    RefreshFrameworkCustomDepth();
    RefreshCameraCollisionPolicy();
}

void ADMFPlayerAvatarCharacter::BeginPlay()
{
    Super::BeginPlay();
    ApplyMovementSpeed();
    RefreshFrameworkCustomDepth();
    RefreshCameraCollisionPolicy();
    RefreshSkinFromPlayerState();
    CaptureBasePlayerMeshRelativeTransform();
    RefreshWorldNameplate();

    if (UnderwaterPostProcessComponent)
    {
        UnderwaterPostProcessComponent->BlendWeight = 0.0f;
        UnderwaterPostProcessComponent->bEnabled = false;
    }
    if (UnderwaterDistanceFogComponent)
    {
        UnderwaterDistanceFogComponent->SetFogDensity(0.0f);
        UnderwaterDistanceFogComponent->SetVisibility(false, true);
        AppliedUnderwaterDistanceFogDensity = 0.0f;
        bUnderwaterDistanceFogVisible = false;
    }

    // Warm the configured footstep asset on rendering clients so the first actual step does not incur a synchronous-load hitch.
    if (GetNetMode() != NM_DedicatedServer)
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        if (Settings && Settings->bEnablePlayerFootsteps && !Settings->PlayerFootstepSound.IsNull())
        {
            CachedPlayerFootstepSound = Settings->PlayerFootstepSound.LoadSynchronous();
        }
    }
}

void ADMFPlayerAvatarCharacter::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    // Camera zoom is entirely local presentation. It does not replicate camera distance or generate network traffic.
    UpdateCameraZoom(DeltaSeconds);

    // Footsteps are independent of the framework's legacy input bindings so Enhanced Input/custom movement projects
    // still receive automatic footsteps from actual replicated CharacterMovement velocity. Swimming naturally suppresses
    // them because CharacterMovement is no longer grounded while a DMFSwimmableWater body owns movement.
    UpdateAutomaticPlayerFootsteps(DeltaSeconds);

    if (IsLocallyControlled() && bEnableNativeThirdPersonInput)
    {
        const float ForwardValue = (bForwardPressed ? 1.0f : 0.0f) - (bBackwardPressed ? 1.0f : 0.0f);
        const float RightValue = (bRightPressed ? 1.0f : 0.0f) - (bLeftPressed ? 1.0f : 0.0f);
        MoveForward(ForwardValue);
        MoveRight(RightValue);
        if (IsSwimmingInWater())
        {
            const float VerticalValue = (bSwimAscendPressed ? 1.0f : 0.0f) - (bSwimDescendPressed ? 1.0f : 0.0f);
            AddSwimVerticalInput(VerticalValue);
        }
    }

    UpdateSwimmingState(DeltaSeconds);

    // Underwater color/PP is private local camera presentation. The server still owns swimming state, but no camera
    // transform, blend weight or render setting is replicated. Remote avatar copies never spend per-frame PP work.
    if (IsLocallyControlled() || UnderwaterPostProcessBlendWeight > KINDA_SMALL_NUMBER)
    {
        UpdateUnderwaterPostProcessPresentation(DeltaSeconds);
    }
}

void ADMFPlayerAvatarCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    if (!PlayerInputComponent)
    {
        return;
    }

    if (bEnableNativeThirdPersonInput)
    {
        PlayerInputComponent->BindKey(EKeys::W, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleForwardPressed);
        PlayerInputComponent->BindKey(EKeys::W, IE_Released, this, &ADMFPlayerAvatarCharacter::HandleForwardReleased);
        PlayerInputComponent->BindKey(EKeys::S, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleBackwardPressed);
        PlayerInputComponent->BindKey(EKeys::S, IE_Released, this, &ADMFPlayerAvatarCharacter::HandleBackwardReleased);
        PlayerInputComponent->BindKey(EKeys::A, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleLeftPressed);
        PlayerInputComponent->BindKey(EKeys::A, IE_Released, this, &ADMFPlayerAvatarCharacter::HandleLeftReleased);
        PlayerInputComponent->BindKey(EKeys::D, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleRightPressed);
        PlayerInputComponent->BindKey(EKeys::D, IE_Released, this, &ADMFPlayerAvatarCharacter::HandleRightReleased);
        PlayerInputComponent->BindKey(EKeys::SpaceBar, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleJumpPressed);
        PlayerInputComponent->BindKey(EKeys::SpaceBar, IE_Released, this, &ADMFPlayerAvatarCharacter::HandleJumpReleased);
        PlayerInputComponent->BindKey(EKeys::LeftShift, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleSprintPressed);
        PlayerInputComponent->BindKey(EKeys::LeftShift, IE_Released, this, &ADMFPlayerAvatarCharacter::HandleSprintReleased);
        PlayerInputComponent->BindKey(EKeys::C, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleCrouchPressed);
        PlayerInputComponent->BindKey(EKeys::C, IE_Released, this, &ADMFPlayerAvatarCharacter::HandleCrouchReleased);

        PlayerInputComponent->BindAxisKey(EKeys::MouseX, this, &ADMFPlayerAvatarCharacter::HandleMouseX);
        PlayerInputComponent->BindAxisKey(EKeys::MouseY, this, &ADMFPlayerAvatarCharacter::HandleMouseY);
        PlayerInputComponent->BindAxisKey(EKeys::Gamepad_LeftY, this, &ADMFPlayerAvatarCharacter::HandleGamepadMoveForward);
        PlayerInputComponent->BindAxisKey(EKeys::Gamepad_LeftX, this, &ADMFPlayerAvatarCharacter::HandleGamepadMoveRight);
        PlayerInputComponent->BindAxisKey(EKeys::Gamepad_RightX, this, &ADMFPlayerAvatarCharacter::HandleGamepadLookYaw);
        PlayerInputComponent->BindAxisKey(EKeys::Gamepad_RightY, this, &ADMFPlayerAvatarCharacter::HandleGamepadLookPitch);
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Settings && Settings->bEnablePlayerCameraZoom && Settings->bEnableDefaultPlayerCameraZoomInput)
    {
        PlayerInputComponent->BindKey(EKeys::MouseScrollUp, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleCameraZoomIn);
        PlayerInputComponent->BindKey(EKeys::MouseScrollDown, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleCameraZoomOut);
    }

    if (bEnableNativeInteractionInput)
    {
        PlayerInputComponent->BindKey(EKeys::E, IE_Pressed, this, &ADMFPlayerAvatarCharacter::HandleInteractionPressed);
    }
}

void ADMFPlayerAvatarCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    RefreshSkinFromPlayerState();
    RefreshWorldNameplate();
}

void ADMFPlayerAvatarCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();
    RefreshSkinFromPlayerState();
    RefreshWorldNameplate();
}

void ADMFPlayerAvatarCharacter::RefreshWorldNameplate()
{
    if (!NameplateWidgetComponent)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bEnabled = Settings
        && Settings->bEnableWorldNameplates
        && Settings->bEnablePlayerNameplates
        && GetNetMode() != NM_DedicatedServer
        && (Settings->bShowLocalPlayerNameplate || !IsLocallyControlled());

    NameplateWidgetComponent->SetVisibility(bEnabled, true);
    if (!bEnabled)
    {
        return;
    }

    const float CapsuleHalfHeight = GetCapsuleComponent() ? GetCapsuleComponent()->GetScaledCapsuleHalfHeight() : 96.0f;
    NameplateWidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, CapsuleHalfHeight + FMath::Max(0.0f, Settings->PlayerNameplateHeightOffset)));
    NameplateWidgetComponent->SetCullDistance(FMath::Max(0.0f, Settings->PlayerNameplateMaxDrawDistance));
    NameplateWidgetComponent->SetRedrawTime(FMath::Clamp(Settings->WorldNameplateRefreshInterval, 0.05f, 1.0f));
    NameplateWidgetComponent->SetTickWhenOffscreen(false);

    // Screen-space widgets must be associated with the local viewport to receive deterministic mouse hit testing.
    if (UWorld* World = GetWorld())
    {
        if (APlayerController* LocalController = World->GetFirstPlayerController())
        {
            if (ULocalPlayer* LocalPlayer = LocalController->GetLocalPlayer())
            {
                NameplateWidgetComponent->SetOwnerPlayer(LocalPlayer);
            }
        }
    }

    TSubclassOf<UDMFWorldNameplateWidget> DesiredClass = Settings->PlayerNameplateWidgetClass;
    if (!DesiredClass)
    {
        DesiredClass = UDMFWorldNameplateWidget::StaticClass();
    }
    if (NameplateWidgetComponent->GetWidgetClass() != DesiredClass)
    {
        NameplateWidgetComponent->SetWidgetClass(DesiredClass);
    }

    NameplateWidgetComponent->InitWidget();
    if (UDMFWorldNameplateWidget* NameplateWidget = Cast<UDMFWorldNameplateWidget>(NameplateWidgetComponent->GetUserWidgetObject()))
    {
        NameplateWidget->SetObservedActor(this);
    }
}

void ADMFPlayerAvatarCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFPlayerAvatarCharacter, bIsSprinting);
    DOREPLIFETIME(ADMFPlayerAvatarCharacter, ActiveSwimmableWater);
    DOREPLIFETIME(ADMFPlayerAvatarCharacter, bIsUnderwaterSwimming);
    DOREPLIFETIME(ADMFPlayerAvatarCharacter, ReplicatedSwimPresentationState);
}

void ADMFPlayerAvatarCharacter::MoveForward(const float Value)
{
    if (!Controller || FMath::IsNearlyZero(Value))
    {
        return;
    }

    if (ADMFSwimmableWater* WaterBody = ResolveEffectiveSwimmableWater())
    {
        const FRotator ControlRotation = Controller->GetControlRotation();
        FVector SwimDirection = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::X);

        // At the surface, looking upward cannot drive the collision capsule out of the water. Looking downward remains
        // fully three-dimensional so pressing Forward naturally dives exactly like a modern third-person MMO.
        if (!IsSwimmingUnderwater() && SwimDirection.Z > 0.0f)
        {
            SwimDirection.Z = 0.0f;
            SwimDirection = SwimDirection.GetSafeNormal();
        }

        LastSwimForwardInput = Value;
        LastSwimForwardInputWorldSeconds = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
        AddMovementInput(SwimDirection, Value);
        return;
    }

    const FRotator ControlRotation = Controller->GetControlRotation();
    const FRotator YawRotation(0.0f, ControlRotation.Yaw, 0.0f);
    AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Value);
}

void ADMFPlayerAvatarCharacter::MoveRight(const float Value)
{
    if (!Controller || FMath::IsNearlyZero(Value))
    {
        return;
    }

    if (ResolveEffectiveSwimmableWater())
    {
        const FRotator ControlRotation = Controller->GetControlRotation();
        AddMovementInput(FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::Y), Value);
        return;
    }

    const FRotator ControlRotation = Controller->GetControlRotation();
    const FRotator YawRotation(0.0f, ControlRotation.Yaw, 0.0f);
    AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y), Value);
}

void ADMFPlayerAvatarCharacter::LookYaw(const float Value)
{
    if (!FMath::IsNearlyZero(Value))
    {
        AddControllerYawInput(Value);
    }
}

void ADMFPlayerAvatarCharacter::LookPitch(const float Value)
{
    if (!FMath::IsNearlyZero(Value))
    {
        AddControllerPitchInput(Value);
    }
}

void ADMFPlayerAvatarCharacter::InitializeCameraZoom()
{
    if (bCameraZoomInitialized || !CameraBoom || !IsLocallyControlled())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnablePlayerCameraZoom)
    {
        DesiredCameraBoomLength = CameraBoom->TargetArmLength;
        bCameraZoomInitialized = true;
        return;
    }

    const float MinimumBoom = FMath::Max(0.0f, FMath::Min(Settings->PlayerCameraMinimumBoomLength, Settings->PlayerCameraMaximumBoomLength));
    const float MaximumBoom = FMath::Max(MinimumBoom, FMath::Max(Settings->PlayerCameraMinimumBoomLength, Settings->PlayerCameraMaximumBoomLength));
    DesiredCameraBoomLength = FMath::Clamp(Settings->PlayerCameraDefaultBoomLength, MinimumBoom, MaximumBoom);
    CameraBoom->TargetArmLength = DesiredCameraBoomLength;
    bCameraZoomInitialized = true;
}

void ADMFPlayerAvatarCharacter::UpdateCameraZoom(const float DeltaSeconds)
{
    if (!CameraBoom || !IsLocallyControlled())
    {
        return;
    }

    InitializeCameraZoom();

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnablePlayerCameraZoom)
    {
        return;
    }

    const float MinimumBoom = FMath::Max(0.0f, FMath::Min(Settings->PlayerCameraMinimumBoomLength, Settings->PlayerCameraMaximumBoomLength));
    const float MaximumBoom = FMath::Max(MinimumBoom, FMath::Max(Settings->PlayerCameraMinimumBoomLength, Settings->PlayerCameraMaximumBoomLength));
    DesiredCameraBoomLength = FMath::Clamp(DesiredCameraBoomLength, MinimumBoom, MaximumBoom);

    const float InterpSpeed = FMath::Max(0.0f, Settings->PlayerCameraZoomInterpolationSpeed);
    CameraBoom->TargetArmLength = InterpSpeed <= KINDA_SMALL_NUMBER
        ? DesiredCameraBoomLength
        : FMath::FInterpTo(CameraBoom->TargetArmLength, DesiredCameraBoomLength, FMath::Max(0.0f, DeltaSeconds), InterpSpeed);
}

void ADMFPlayerAvatarCharacter::AddCameraZoomInput(const float Value)
{
    if (!CameraBoom || !IsLocallyControlled() || FMath::IsNearlyZero(Value))
    {
        return;
    }

    InitializeCameraZoom();
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnablePlayerCameraZoom)
    {
        return;
    }

    const float MinimumBoom = FMath::Max(0.0f, FMath::Min(Settings->PlayerCameraMinimumBoomLength, Settings->PlayerCameraMaximumBoomLength));
    const float MaximumBoom = FMath::Max(MinimumBoom, FMath::Max(Settings->PlayerCameraMinimumBoomLength, Settings->PlayerCameraMaximumBoomLength));
    const float Step = FMath::Max(1.0f, Settings->PlayerCameraMouseWheelZoomStep);
    DesiredCameraBoomLength = FMath::Clamp(DesiredCameraBoomLength - (Value * Step), MinimumBoom, MaximumBoom);
}

void ADMFPlayerAvatarCharacter::SetCameraZoomDistance(const float NewDistance, const bool bInstant)
{
    if (!CameraBoom || !IsLocallyControlled())
    {
        return;
    }

    InitializeCameraZoom();
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnablePlayerCameraZoom)
    {
        return;
    }

    const float MinimumBoom = FMath::Max(0.0f, FMath::Min(Settings->PlayerCameraMinimumBoomLength, Settings->PlayerCameraMaximumBoomLength));
    const float MaximumBoom = FMath::Max(MinimumBoom, FMath::Max(Settings->PlayerCameraMinimumBoomLength, Settings->PlayerCameraMaximumBoomLength));
    DesiredCameraBoomLength = FMath::Clamp(NewDistance, MinimumBoom, MaximumBoom);
    if (bInstant)
    {
        CameraBoom->TargetArmLength = DesiredCameraBoomLength;
    }
}

void ADMFPlayerAvatarCharacter::ResetCameraZoom(const bool bInstant)
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings)
    {
        return;
    }
    SetCameraZoomDistance(Settings->PlayerCameraDefaultBoomLength, bInstant);
}

void ADMFPlayerAvatarCharacter::RefreshCameraCollisionPolicy()
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bIgnorePlayersAndDigimonForCameraCollision)
    {
        return;
    }

    // Apply to every primitive owned by the avatar, including Blueprint-added cosmetic/collision components.
    // This changes only ECC_Camera; Pawn/Visibility/combat/interaction responses are untouched.
    TArray<UPrimitiveComponent*> PrimitiveComponents;
    GetComponents<UPrimitiveComponent>(PrimitiveComponents);
    for (UPrimitiveComponent* PrimitiveComponent : PrimitiveComponents)
    {
        if (PrimitiveComponent)
        {
            PrimitiveComponent->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
        }
    }
}

void ADMFPlayerAvatarCharacter::StartSprinting()
{
    bIsSprinting = true;
    ApplyMovementSpeed();
    if (!HasAuthority())
    {
        ServerSetSprinting(true);
    }
}

void ADMFPlayerAvatarCharacter::StopSprinting()
{
    bIsSprinting = false;
    ApplyMovementSpeed();
    if (!HasAuthority())
    {
        ServerSetSprinting(false);
    }
}

void ADMFPlayerAvatarCharacter::ResetNativeInputState()
{
    bForwardPressed = false;
    bBackwardPressed = false;
    bLeftPressed = false;
    bRightPressed = false;
    bSwimAscendPressed = false;
    bSwimDescendPressed = false;
    StopSprinting();
}

void ADMFPlayerAvatarCharacter::UpdateAutomaticPlayerFootsteps(const float DeltaSeconds)
{
    // Authority generates observer presentation. A remote owning client also predicts its own footsteps locally
    // for immediate response, then suppresses the server multicast echo in MulticastPlayPlayerFootstep_Implementation().
    const bool bShouldGenerate = HasAuthority() || (!HasAuthority() && IsLocallyControlled());
    if (!bShouldGenerate || DeltaSeconds <= 0.0f)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const UCharacterMovementComponent* Movement = GetCharacterMovement();
    const bool bConfigured = Settings
        && Settings->bEnablePlayerFootsteps
        && !Settings->PlayerFootstepSound.IsNull()
        && Movement;

    const float HorizontalSpeed = GetVelocity().Size2D();
    const bool bGroundedMovement = bConfigured
        && Movement->IsMovingOnGround()
        && HorizontalSpeed >= FMath::Max(0.0f, Settings->PlayerFootstepMinimumSpeed);

    if (!bGroundedMovement)
    {
        PlayerFootstepDistanceAccumulator = 0.0f;
        bWasGeneratingPlayerFootsteps = false;
        return;
    }

    const float StrideDistance = ResolvePlayerFootstepStrideDistance();
    if (StrideDistance <= KINDA_SMALL_NUMBER)
    {
        return;
    }

    // Starting from a partial stride prevents a long silent delay when movement begins without producing an
    // unrealistic instantaneous step on the exact first movement frame.
    if (!bWasGeneratingPlayerFootsteps)
    {
        PlayerFootstepDistanceAccumulator = StrideDistance * 0.45f;
        bWasGeneratingPlayerFootsteps = true;
    }

    // Distance-based cadence naturally follows walk/sprint/crouch speed and remains animation-blueprint agnostic.
    // Cap one event per frame so a hitch never dumps a burst of stale footsteps.
    PlayerFootstepDistanceAccumulator += HorizontalSpeed * DeltaSeconds;
    if (PlayerFootstepDistanceAccumulator < StrideDistance)
    {
        return;
    }

    PlayerFootstepDistanceAccumulator = FMath::Fmod(PlayerFootstepDistanceAccumulator, StrideDistance);

    if (HasAuthority())
    {
        MulticastPlayPlayerFootstep();
    }
    else
    {
        PlayPlayerFootstepLocal();
    }
}

float ADMFPlayerAvatarCharacter::ResolvePlayerFootstepStrideDistance() const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings)
    {
        return 0.0f;
    }

    if (bIsCrouched)
    {
        return FMath::Max(25.0f, Settings->PlayerFootstepCrouchStrideDistance);
    }

    if (bIsSprinting)
    {
        return FMath::Max(25.0f, Settings->PlayerFootstepSprintStrideDistance);
    }

    return FMath::Max(25.0f, Settings->PlayerFootstepWalkStrideDistance);
}

FVector ADMFPlayerAvatarCharacter::GetPlayerFootstepAudioLocation() const
{
    const UCapsuleComponent* Capsule = GetCapsuleComponent();
    const float CapsuleHalfHeight = Capsule ? Capsule->GetScaledCapsuleHalfHeight() : 0.0f;

    // Use the capsule base instead of skeleton-specific foot sockets so every player skin works out of the box.
    return GetActorLocation() - FVector(0.0f, 0.0f, FMath::Max(0.0f, CapsuleHalfHeight - 4.0f));
}

void ADMFPlayerAvatarCharacter::PlayPlayerFootstepLocal()
{
    if (GetNetMode() == NM_DedicatedServer)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnablePlayerFootsteps || Settings->PlayerFootstepSound.IsNull())
    {
        return;
    }

    USoundBase* FootstepSound = CachedPlayerFootstepSound.Get();
    if (!FootstepSound)
    {
        FootstepSound = Settings->PlayerFootstepSound.Get();
        if (!FootstepSound)
        {
            FootstepSound = Settings->PlayerFootstepSound.LoadSynchronous();
        }
        CachedPlayerFootstepSound = FootstepSound;
    }

    if (!FootstepSound)
    {
        return;
    }

    UGameplayStatics::PlaySoundAtLocation(
        this,
        FootstepSound,
        GetPlayerFootstepAudioLocation(),
        FRotator::ZeroRotator,
        FMath::Max(0.0f, Settings->PlayerFootstepVolumeMultiplier),
        FMath::Clamp(Settings->PlayerFootstepPitchMultiplier, 0.25f, 4.0f));
}

void ADMFPlayerAvatarCharacter::MulticastPlayPlayerFootstep_Implementation()
{
    // Remote owners already predict the exact same local-only footstep for responsiveness.
    // Suppressing the returned multicast avoids a doubled sound while observers still hear the server event.
    if (!HasAuthority() && IsLocallyControlled())
    {
        return;
    }

    PlayPlayerFootstepLocal();
}

bool ADMFPlayerAvatarCharacter::Interact()
{
    if (!IsLocallyControlled())
    {
        ReportInteractionResult(false, nullptr, EDMFPlayerInteractionType::None, NSLOCTEXT("DMF", "InteractionLocalOnly", "Interaction must be called by the locally controlled player."));
        return false;
    }

    FHitResult Hit;
    AActor* TargetActor = FindInteractionTarget(Hit);
    if (!IsValid(TargetActor))
    {
        LastInteractionActor = nullptr;
        ReportInteractionResult(false, nullptr, EDMFPlayerInteractionType::None, NSLOCTEXT("DMF", "InteractionNoTarget", "Nothing interactable is in range."));
        return false;
    }

    return InteractWithActor(TargetActor);
}

bool ADMFPlayerAvatarCharacter::InteractWithActor(AActor* TargetActor)
{
    if (!IsLocallyControlled() || !IsValid(TargetActor) || TargetActor == this)
    {
        ReportInteractionResult(false, TargetActor, EDMFPlayerInteractionType::None, NSLOCTEXT("DMF", "InteractionInvalidActor", "That actor cannot be interacted with."));
        return false;
    }

    LastInteractionActor = TargetActor;

    if (Cast<ADMFDigimonCharacter>(TargetActor))
    {
        return bAttackOnDigimonInteract
            ? TargetAndAttackDigimonFromActor(TargetActor, DigimonInteractAttackSlotIndex)
            : TargetDigimonFromActor(TargetActor);
    }

    if (Cast<ADMFHealerActor>(TargetActor))
    {
        return InteractWithHealer(TargetActor);
    }

    if (Cast<ADMFDigimonVendorActor>(TargetActor))
    {
        return InteractWithDigimonVendor(TargetActor);
    }

    BP_OnUnhandledInteraction(TargetActor);
    ReportInteractionResult(false, TargetActor, EDMFPlayerInteractionType::Unhandled, NSLOCTEXT("DMF", "InteractionUnhandled", "This actor has no native Digimon MMO interaction."));
    return false;
}

bool ADMFPlayerAvatarCharacter::TargetDigimonFromActor(AActor* TargetActor)
{
    ADMFDigimonCharacter* Digimon = Cast<ADMFDigimonCharacter>(TargetActor);
    ADMFMMOPlayerController* DMFController = ResolveDMFPlayerController();
    if (!IsValid(Digimon) || !DMFController)
    {
        BP_OnDigimonInteracted(Digimon, false, false);
        ReportInteractionResult(false, TargetActor, EDMFPlayerInteractionType::DigimonTarget, NSLOCTEXT("DMF", "InteractionInvalidDigimonTarget", "That actor is not a valid Digimon target."));
        return false;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    UDMFPlayerDigimonComponent* DigimonComponent = DMFPlayerState ? DMFPlayerState->DigimonComponent.Get() : nullptr;
    ADMFDigimonCharacter* ActivePartner = DigimonComponent ? DigimonComponent->ActivePartnerActor.Get() : nullptr;
    if (!IsValid(ActivePartner) || !ActivePartner->CombatComponent || !ActivePartner->CombatComponent->CanAttackTarget(Digimon))
    {
        BP_OnDigimonInteracted(Digimon, false, false);
        ReportInteractionResult(false, TargetActor, EDMFPlayerInteractionType::DigimonTarget, NSLOCTEXT("DMF", "InteractionDigimonNotHostile", "That Digimon cannot be targeted by the active partner."));
        return false;
    }

    LastInteractionActor = Digimon;
    DMFController->SetDigimonCommandTarget(Digimon);
    BP_OnDigimonInteracted(Digimon, true, false);
    ReportInteractionResult(true, Digimon, EDMFPlayerInteractionType::DigimonTarget, NSLOCTEXT("DMF", "InteractionDigimonTargeted", "Digimon targeted."));
    return true;
}

bool ADMFPlayerAvatarCharacter::InteractWithDigimon(AActor* DigimonActor)
{
    return TargetDigimonFromActor(DigimonActor);
}

bool ADMFPlayerAvatarCharacter::TargetAndAttackDigimonFromActor(AActor* TargetActor, const int32 SlotIndex)
{
    ADMFDigimonCharacter* Digimon = Cast<ADMFDigimonCharacter>(TargetActor);
    ADMFMMOPlayerController* DMFController = ResolveDMFPlayerController();
    if (!IsValid(Digimon) || !DMFController || SlotIndex < 0 || SlotIndex > 3)
    {
        BP_OnDigimonInteracted(Digimon, false, false);
        ReportInteractionResult(false, TargetActor, EDMFPlayerInteractionType::DigimonTargetAndAttack, NSLOCTEXT("DMF", "InteractionInvalidDigimonAttack", "The Digimon target or ability slot is invalid."));
        return false;
    }

    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    UDMFPlayerDigimonComponent* DigimonComponent = DMFPlayerState ? DMFPlayerState->DigimonComponent.Get() : nullptr;
    ADMFDigimonCharacter* ActivePartner = DigimonComponent ? DigimonComponent->ActivePartnerActor.Get() : nullptr;
    if (!IsValid(ActivePartner) || !ActivePartner->CombatComponent || !ActivePartner->CombatComponent->CanAttackTarget(Digimon))
    {
        BP_OnDigimonInteracted(Digimon, false, false);
        ReportInteractionResult(false, TargetActor, EDMFPlayerInteractionType::DigimonTargetAndAttack, NSLOCTEXT("DMF", "InteractionDigimonAttackRejected", "That Digimon cannot be attacked by the active partner."));
        return false;
    }

    LastInteractionActor = Digimon;
    DMFController->CommandPartnerTargetAndAttack(Digimon, SlotIndex);
    BP_OnDigimonInteracted(Digimon, true, true);
    ReportInteractionResult(true, Digimon, EDMFPlayerInteractionType::DigimonTargetAndAttack, NSLOCTEXT("DMF", "InteractionDigimonAttackCommanded", "Digimon targeted and attack command sent."));
    return true;
}

bool ADMFPlayerAvatarCharacter::InteractWithDigimonAndAttack(AActor* DigimonActor, const int32 SlotIndex)
{
    return TargetAndAttackDigimonFromActor(DigimonActor, SlotIndex);
}

bool ADMFPlayerAvatarCharacter::InteractWithHealer(AActor* HealerActor)
{
    ADMFHealerActor* Healer = Cast<ADMFHealerActor>(HealerActor);
    ADMFMMOPlayerController* DMFController = ResolveDMFPlayerController();
    if (!IsLocallyControlled() || !IsValid(Healer) || !DMFController)
    {
        ReportInteractionResult(false, HealerActor, EDMFPlayerInteractionType::Healer, NSLOCTEXT("DMF", "InteractionInvalidHealerActor", "That actor is not a valid healer."));
        return false;
    }

    LastInteractionActor = Healer;
    DMFController->RequestUseHealer(Healer);
    ReportInteractionResult(true, Healer, EDMFPlayerInteractionType::Healer, NSLOCTEXT("DMF", "InteractionHealerRequestedDirect", "Healing request sent."));
    return true;
}

bool ADMFPlayerAvatarCharacter::InteractWithDigimonVendor(AActor* VendorActor)
{
    ADMFDigimonVendorActor* Vendor = Cast<ADMFDigimonVendorActor>(VendorActor);
    ADMFMMOPlayerController* DMFController = ResolveDMFPlayerController();
    if (!IsLocallyControlled() || !IsValid(Vendor) || !DMFController || !Vendor->IsVendorEnabled()
        || !Vendor->IsPlayerWithinTradeRange(DMFController))
    {
        ReportInteractionResult(false, VendorActor, EDMFPlayerInteractionType::DigimonVendor, NSLOCTEXT("DMF", "InteractionInvalidDigimonVendor", "That Digimon vendor is unavailable or out of range."));
        return false;
    }

    LastInteractionActor = Vendor;
    DMFController->OpenDigimonVendorUI(Vendor);
    const bool bOpened = DMFController->IsDigimonVendorUIOpen();
    ReportInteractionResult(bOpened, Vendor, EDMFPlayerInteractionType::DigimonVendor,
        bOpened ? NSLOCTEXT("DMF", "InteractionVendorOpened", "Digimon vendor opened.")
                : NSLOCTEXT("DMF", "InteractionVendorOpenFailed", "The Digimon vendor could not be opened."));
    return bOpened;
}

void ADMFPlayerAvatarCharacter::ClearDigimonTarget()
{
    if (ADMFMMOPlayerController* DMFController = ResolveDMFPlayerController())
    {
        DMFController->SetDigimonCommandTarget(nullptr);
    }
}

void ADMFPlayerAvatarCharacter::CommandDigimonAbilitySlot(const int32 SlotIndex)
{
    if (SlotIndex < 0 || SlotIndex > 3)
    {
        return;
    }

    if (ADMFMMOPlayerController* DMFController = ResolveDMFPlayerController())
    {
        DMFController->CommandActivePartnerAbilitySlot(SlotIndex);
    }
}

AActor* ADMFPlayerAvatarCharacter::FindInteractionTarget(FHitResult& OutHit) const
{
    OutHit = FHitResult();

    const UWorld* World = GetWorld();
    if (!World || !IsLocallyControlled())
    {
        return nullptr;
    }

    FVector Start = GetActorLocation();
    FRotator ViewRotation = GetActorRotation();
    if (FollowCamera)
    {
        Start = FollowCamera->GetComponentLocation();
        ViewRotation = FollowCamera->GetComponentRotation();
    }
    else
    {
        GetActorEyesViewPoint(Start, ViewRotation);
    }

    const FVector End = Start + ViewRotation.Vector() * FMath::Max(1.0f, InteractionDistance);

    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(DMFPlayerInteraction), bInteractionTraceComplex, this);
    QueryParams.AddIgnoredActor(this);

    if (bIgnoreActivePartnerDuringInteractionTrace)
    {
        const ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
        const UDMFPlayerDigimonComponent* DigimonComponent = DMFPlayerState ? DMFPlayerState->DigimonComponent.Get() : nullptr;
        if (DigimonComponent && IsValid(DigimonComponent->ActivePartnerActor.Get()))
        {
            QueryParams.AddIgnoredActor(DigimonComponent->ActivePartnerActor.Get());
        }
    }

    const ECollisionChannel TraceChannel = static_cast<ECollisionChannel>(InteractionTraceChannel.GetValue());
    bool bHit = false;
    if (InteractionSweepRadius > KINDA_SMALL_NUMBER)
    {
        bHit = GetWorld()->SweepSingleByChannel(
            OutHit,
            Start,
            End,
            FQuat::Identity,
            TraceChannel,
            FCollisionShape::MakeSphere(InteractionSweepRadius),
            QueryParams);
    }
    else
    {
        bHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, TraceChannel, QueryParams);
    }

#if ENABLE_DRAW_DEBUG
    if (bDrawDebugInteractionTrace)
    {
        const FColor DebugColor = bHit ? FColor::Green : FColor::Red;
        DrawDebugLine(GetWorld(), Start, bHit ? OutHit.ImpactPoint : End, DebugColor, false, 1.0f, 0, 1.5f);
        if (InteractionSweepRadius > KINDA_SMALL_NUMBER)
        {
            DrawDebugSphere(GetWorld(), bHit ? OutHit.ImpactPoint : End, InteractionSweepRadius, 12, DebugColor, false, 1.0f);
        }
    }
#endif

    if (!bHit || !IsValid(OutHit.GetActor()))
    {
        return nullptr;
    }

    return OutHit.GetActor();
}

ADMFDigimonCharacter* ADMFPlayerAvatarCharacter::GetCurrentDigimonTarget() const
{
    const ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    return DMFPlayerState && DMFPlayerState->DigimonComponent ? DMFPlayerState->DigimonComponent->GetCommandTarget() : nullptr;
}

FText ADMFPlayerAvatarCharacter::GetInteractionPromptForActor(AActor* TargetActor) const
{
    if (const ADMFDigimonCharacter* Digimon = Cast<ADMFDigimonCharacter>(TargetActor))
    {
        if (const UDMFDigimonSpeciesData* Species = Digimon->ResolveSpeciesData())
        {
            return bAttackOnDigimonInteract
                ? FText::Format(NSLOCTEXT("DMF", "InteractionPromptAttackNamedDigimon", "Attack {0}"), Species->DisplayName)
                : FText::Format(NSLOCTEXT("DMF", "InteractionPromptTargetNamedDigimon", "Target {0}"), Species->DisplayName);
        }
        return bAttackOnDigimonInteract
            ? NSLOCTEXT("DMF", "InteractionPromptAttackDigimon", "Attack Digimon")
            : NSLOCTEXT("DMF", "InteractionPromptTargetDigimon", "Target Digimon");
    }

    if (const ADMFHealerActor* Healer = Cast<ADMFHealerActor>(TargetActor))
    {
        return Healer->InteractionPrompt.IsEmpty() ? NSLOCTEXT("DMF", "InteractionPromptHealer", "Heal Digimon") : Healer->InteractionPrompt;
    }

    if (const ADMFDigimonVendorActor* Vendor = Cast<ADMFDigimonVendorActor>(TargetActor))
    {
        return Vendor->InteractionPrompt.IsEmpty() ? NSLOCTEXT("DMF", "InteractionPromptDigimonVendor", "Open Digimon Vendor") : Vendor->InteractionPrompt;
    }

    return FText::GetEmpty();
}

ADMFMMOPlayerController* ADMFPlayerAvatarCharacter::ResolveDMFPlayerController() const
{
    return Cast<ADMFMMOPlayerController>(GetController());
}

void ADMFPlayerAvatarCharacter::ReportInteractionResult(const bool bSuccess, AActor* TargetActor, const EDMFPlayerInteractionType InteractionType, const FText& Message)
{
    OnInteractionResult.Broadcast(bSuccess, TargetActor, InteractionType, Message);
}

bool ADMFPlayerAvatarCharacter::IsSwimmingInWater() const
{
    if (IsLocallyControlled() && bLocalWaterOverlapPredictionInitialized)
    {
        return LocalPredictedSwimmableWater.IsValid();
    }

    // Remote observers consume one compact authoritative state. This remains valid even if the replicated
    // water-actor reference is temporarily unresolved/reordered on that connection.
    if (!HasAuthority())
    {
        return ReplicatedSwimPresentationState != EDMFPlayerSwimState::None;
    }

    return ActiveSwimmableWater != nullptr;
}

bool ADMFPlayerAvatarCharacter::IsSwimmingUnderwater() const
{
    if (IsLocallyControlled() && bLocalWaterOverlapPredictionInitialized)
    {
        return LocalPredictedSwimmableWater.IsValid() && bLocalPredictedUnderwater;
    }

    if (!HasAuthority())
    {
        return ReplicatedSwimPresentationState == EDMFPlayerSwimState::Underwater;
    }

    return ActiveSwimmableWater != nullptr && bIsUnderwaterSwimming;
}

ADMFSwimmableWater* ADMFPlayerAvatarCharacter::GetActiveSwimmableWater() const
{
    return ResolveEffectiveSwimmableWater();
}

EDMFPlayerSwimState ADMFPlayerAvatarCharacter::GetPlayerSwimState() const
{
    if (IsLocallyControlled() && bLocalWaterOverlapPredictionInitialized)
    {
        if (!LocalPredictedSwimmableWater.IsValid())
        {
            return EDMFPlayerSwimState::None;
        }
        return bLocalPredictedUnderwater ? EDMFPlayerSwimState::Underwater : EDMFPlayerSwimState::Surface;
    }

    if (!HasAuthority())
    {
        return ReplicatedSwimPresentationState;
    }

    if (!ActiveSwimmableWater)
    {
        return EDMFPlayerSwimState::None;
    }
    return bIsUnderwaterSwimming ? EDMFPlayerSwimState::Underwater : EDMFPlayerSwimState::Surface;
}

void ADMFPlayerAvatarCharacter::AddSwimVerticalInput(const float Value)
{
    ADMFSwimmableWater* WaterBody = ResolveEffectiveSwimmableWater();
    if (!WaterBody || FMath::IsNearlyZero(Value))
    {
        return;
    }

    LastExplicitVerticalSwimInput = FMath::Clamp(Value, -1.0f, 1.0f);
    LastExplicitVerticalSwimInputWorldSeconds = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;

    // Surface swimmers may always descend. Ascending beyond the water plane is intentionally suppressed;
    // walking/jumping resumes naturally after the overlap volume is actually exited at a shore/edge.
    if (Value > 0.0f && !IsSwimmingUnderwater())
    {
        const float Depth = WaterBody->GetDepthBelowSurface(GetActorLocation());
        if (Depth <= WaterBody->SurfaceRideDepth + 25.0f)
        {
            return;
        }
    }

    AddMovementInput(FVector::UpVector, Value);
}

void ADMFPlayerAvatarCharacter::RegisterSwimmableWaterOverlap(ADMFSwimmableWater* WaterBody, const bool bEntered)
{
    if (!IsValid(WaterBody))
    {
        return;
    }

    OverlappingSwimmableWaters.RemoveAll([](const TWeakObjectPtr<ADMFSwimmableWater>& Candidate)
    {
        return !Candidate.IsValid();
    });

    // A custom Blueprint may call this integration point, but even owner-side prediction must correspond to real
    // water containment. Teleport/load restoration can place a pawn inside a volume before Unreal has emitted its
    // BeginOverlap callback, so geometric containment is an intentional fallback to overlap-cache state.
    const bool bOverlapCacheContainsAvatar = WaterBody->SwimmingBounds && WaterBody->SwimmingBounds->IsOverlappingActor(this);
    const bool bGeometricallyInsideWater = WaterBody->IsWorldLocationInsideSwimmingBounds(GetActorLocation());
    if (bEntered && !bOverlapCacheContainsAvatar && !bGeometricallyInsideWater)
    {
        return;
    }

    if (bEntered && WaterBody->IsSwimmingEnabled())
    {
        OverlappingSwimmableWaters.AddUnique(TWeakObjectPtr<ADMFSwimmableWater>(WaterBody));
    }
    else
    {
        OverlappingSwimmableWaters.RemoveAll([WaterBody](const TWeakObjectPtr<ADMFSwimmableWater>& Candidate)
        {
            return Candidate.Get() == WaterBody;
        });
    }

    if (IsLocallyControlled())
    {
        bLocalWaterOverlapPredictionInitialized = true;
    }

    ReevaluateSwimmingWaterSelection();
}

void ADMFPlayerAvatarCharacter::RebuildSwimmingStateFromWorld(const bool bStopMovementIfSwimming)
{
    UWorld* World = GetWorld();
    if (!World || (!HasAuthority() && !IsLocallyControlled()))
    {
        return;
    }

    // Do not trust overlap event history here. A persisted transform/TeleportTo can put the avatar directly inside
    // water before BeginOverlap has populated either the component cache or this array. Reconstruct from the actual
    // authored water bounds in one bounded, event-independent pass. This is called only for explicit refresh/teleport
    // paths, never every frame.
    OverlappingSwimmableWaters.Reset();
    for (TActorIterator<ADMFSwimmableWater> It(World); It; ++It)
    {
        ADMFSwimmableWater* WaterBody = *It;
        if (!IsValid(WaterBody) || !WaterBody->IsSwimmingEnabled())
        {
            continue;
        }

        const bool bOverlapCacheContainsAvatar = WaterBody->SwimmingBounds && WaterBody->SwimmingBounds->IsOverlappingActor(this);
        const bool bGeometricallyInsideWater = WaterBody->IsWorldLocationInsideSwimmingBounds(GetActorLocation());
        if (bOverlapCacheContainsAvatar || bGeometricallyInsideWater)
        {
            OverlappingSwimmableWaters.AddUnique(TWeakObjectPtr<ADMFSwimmableWater>(WaterBody));
        }
    }

    if (IsLocallyControlled())
    {
        bLocalWaterOverlapPredictionInitialized = true;
        LocalPredictedSwimmableWater.Reset();
        bLocalPredictedUnderwater = false;
    }

    ReevaluateSwimmingWaterSelection();

    ADMFSwimmableWater* EffectiveWater = ResolveEffectiveSwimmableWater();
    if (bStopMovementIfSwimming && IsValid(EffectiveWater))
    {
        if (UCharacterMovementComponent* Movement = GetCharacterMovement())
        {
            Movement->StopMovementImmediately();
        }
    }

    // Resolve Surface/Underwater immediately instead of waiting for the next actor Tick. This is what prevents a
    // restored submerged pawn spending a frame in Falling and sinking to the floor before MOVE_Flying is reinstated.
    UpdateSwimmingState(0.0f);

    if (IsLocallyControlled())
    {
        // Teleport/load paths should not leave the previous view profile alive or wait for an arbitrary overlap event.
        // Reconfigure from the reconstructed water and snap only this one initial refresh to the correct camera state.
        UnderwaterPostProcessConfiguredWater.Reset();
        UpdateUnderwaterPostProcessPresentation(0.0f, true);
    }

    ForceNetUpdate();
}

void ADMFPlayerAvatarCharacter::RefreshSwimmingPresentation()
{
    // Never recapture a simulated/listen-server proxy's live smoothed mesh transform as its authored base.
    // CharacterMovement deliberately offsets that mesh during interpolation; capturing it would bake a transient
    // smoothing correction into the fallback pose and is one source of visible proxy shake.
    if (!IsSwimmingInWater() && !bSwimmingPresentationApplied
        && (!UsesNetworkSmoothingSwimPresentation() || !bBasePlayerMeshRelativeTransformCaptured))
    {
        CaptureBasePlayerMeshRelativeTransform();
    }
    UpdateSwimmingPresentationInternal(0.0f, true);
}

void ADMFPlayerAvatarCharacter::RefreshUnderwaterPostProcessPresentation()
{
    // Force a profile rebuild on the next/local update while preserving the current blend weight for a smooth
    // transition. This is safe to call from replicated water OnRep callbacks on every peer; only the locally
    // controlled avatar can enable the render component.
    UnderwaterPostProcessConfiguredWater.Reset();
    UpdateUnderwaterPostProcessPresentation(0.0f, false);
}

ADMFSwimmableWater* ADMFPlayerAvatarCharacter::ResolveEffectiveSwimmableWater() const
{
    if (IsLocallyControlled() && bLocalWaterOverlapPredictionInitialized)
    {
        return LocalPredictedSwimmableWater.Get();
    }
    return ActiveSwimmableWater.Get();
}

ADMFSwimmableWater* ADMFPlayerAvatarCharacter::SelectBestOverlappingSwimmableWater() const
{
    ADMFSwimmableWater* BestWater = nullptr;
    for (const TWeakObjectPtr<ADMFSwimmableWater>& CandidatePtr : OverlappingSwimmableWaters)
    {
        ADMFSwimmableWater* Candidate = CandidatePtr.Get();
        if (!IsValid(Candidate) || !Candidate->IsSwimmingEnabled())
        {
            continue;
        }

        if (!BestWater
            || Candidate->WaterPriority > BestWater->WaterPriority
            || (Candidate->WaterPriority == BestWater->WaterPriority && Candidate->GetWaterSurfaceWorldZ() > BestWater->GetWaterSurfaceWorldZ()))
        {
            BestWater = Candidate;
        }
    }
    return BestWater;
}

void ADMFPlayerAvatarCharacter::ReevaluateSwimmingWaterSelection()
{
    ADMFSwimmableWater* BestWater = SelectBestOverlappingSwimmableWater();

    // Owning-client prediction is resolved first so listen-host Blueprint events see the same effective water
    // that gameplay input will use in this frame.
    ADMFSwimmableWater* PreviousPredictedWater = nullptr;
    if (IsLocallyControlled())
    {
        PreviousPredictedWater = LocalPredictedSwimmableWater.Get();
        LocalPredictedSwimmableWater = BestWater;
        if (!BestWater)
        {
            bLocalPredictedUnderwater = false;
        }
    }

    if (HasAuthority())
    {
        const bool bChanged = ActiveSwimmableWater != BestWater;
        if (bChanged)
        {
            ActiveSwimmableWater = BestWater;
            if (!ActiveSwimmableWater)
            {
                SetAuthoritativeUnderwaterState(false);
            }
            RefreshAuthoritativeSwimPresentationState();
            ForceNetUpdate();
            NotifySwimmingStateChanged();
        }
    }
    else if (IsLocallyControlled() && PreviousPredictedWater != BestWater)
    {
        NotifySwimmingStateChanged();
    }

    if (ADMFSwimmableWater* EffectiveWater = ResolveEffectiveSwimmableWater())
    {
        ApplySwimmingMovementMode(EffectiveWater);
    }
    else
    {
        RestoreNonSwimmingMovementMode();
    }
}

void ADMFPlayerAvatarCharacter::ApplySwimmingMovementMode(ADMFSwimmableWater* WaterBody)
{
    if (!WaterBody || (!HasAuthority() && !IsLocallyControlled()))
    {
        return;
    }

    UCharacterMovementComponent* Movement = GetCharacterMovement();
    if (!Movement)
    {
        return;
    }

    if (!bSwimmingMovementModeApplied)
    {
        PreSwimmingMovementMode = Movement->MovementMode;
        PreSwimmingCustomMovementMode = Movement->CustomMovementMode;
        PreSwimmingGravityScale = Movement->GravityScale;
        PreSwimmingMaxFlySpeed = Movement->MaxFlySpeed;
        PreSwimmingMaxAcceleration = Movement->MaxAcceleration;
        PreSwimmingBrakingDecelerationFlying = Movement->BrakingDecelerationFlying;
        bPreSwimmingOrientRotationToMovement = Movement->bOrientRotationToMovement;
        bPreSwimmingUseControllerRotationYaw = bUseControllerRotationYaw;
        bSwimmingMovementModeApplied = true;
    }

    if (bIsCrouched)
    {
        UnCrouch();
    }

    // MOVE_Flying gives CharacterMovement's mature replicated 3D prediction/correction path without requiring an
    // engine PhysicsVolume/brush. The water actor remains a scalable Blueprint-friendly Box + plane implementation.
    Movement->GravityScale = 0.0f;
    Movement->MaxAcceleration = FMath::Max(0.0f, WaterBody->SwimAcceleration);
    Movement->BrakingDecelerationFlying = FMath::Max(0.0f, WaterBody->SwimBrakingDeceleration);
    Movement->bOrientRotationToMovement = false;
    bUseControllerRotationYaw = true;

    if (Movement->MovementMode != MOVE_Flying)
    {
        Movement->SetMovementMode(MOVE_Flying);
    }

    ApplyMovementSpeed();
}

void ADMFPlayerAvatarCharacter::RestoreNonSwimmingMovementMode()
{
    if (!bSwimmingMovementModeApplied || (!HasAuthority() && !IsLocallyControlled()))
    {
        return;
    }

    if (UCharacterMovementComponent* Movement = GetCharacterMovement())
    {
        Movement->GravityScale = PreSwimmingGravityScale;
        Movement->MaxFlySpeed = PreSwimmingMaxFlySpeed;
        Movement->MaxAcceleration = PreSwimmingMaxAcceleration;
        Movement->BrakingDecelerationFlying = PreSwimmingBrakingDecelerationFlying;
        Movement->bOrientRotationToMovement = bPreSwimmingOrientRotationToMovement;
        bUseControllerRotationYaw = bPreSwimmingUseControllerRotationYaw;

        EMovementMode RestoreMode = PreSwimmingMovementMode;
        uint8 RestoreCustomMode = PreSwimmingCustomMovementMode;
        if (RestoreMode == MOVE_Walking || RestoreMode == MOVE_NavWalking || RestoreMode == MOVE_Swimming || RestoreMode == MOVE_Flying)
        {
            // Let normal gravity/floor detection reacquire land cleanly after leaving a shore/volume instead of
            // forcing a walking mode while the capsule may still be above the floor.
            RestoreMode = MOVE_Falling;
            RestoreCustomMode = 0;
        }
        Movement->SetMovementMode(RestoreMode, RestoreCustomMode);
    }

    bSwimmingMovementModeApplied = false;
    ApplyMovementSpeed();
}

void ADMFPlayerAvatarCharacter::UpdateSwimmingState(const float DeltaSeconds)
{
    ADMFSwimmableWater* WaterBody = ResolveEffectiveSwimmableWater();
    if (!IsValid(WaterBody) || !WaterBody->IsSwimmingEnabled())
    {
        if (HasAuthority() && (ActiveSwimmableWater || bIsUnderwaterSwimming || ReplicatedSwimPresentationState != EDMFPlayerSwimState::None))
        {
            ActiveSwimmableWater = nullptr;
            SetAuthoritativeUnderwaterState(false);
            RefreshAuthoritativeSwimPresentationState();
            ForceNetUpdate();
            NotifySwimmingStateChanged();
        }
        if (IsLocallyControlled())
        {
            LocalPredictedSwimmableWater.Reset();
            bLocalPredictedUnderwater = false;
        }
        RestoreNonSwimmingMovementMode();
        UpdateSwimmingPresentationInternal(DeltaSeconds);
        return;
    }

    ApplySwimmingMovementMode(WaterBody);

    const float Depth = WaterBody->GetDepthBelowSurface(GetActorLocation());
    const float EnterDepth = FMath::Max(WaterBody->UnderwaterExitDepth, WaterBody->UnderwaterEnterDepth);
    const float ExitDepth = FMath::Min(WaterBody->UnderwaterExitDepth, EnterDepth);

    if (IsLocallyControlled())
    {
        const bool bPreviousPredictedUnderwater = bLocalPredictedUnderwater;
        bLocalPredictedUnderwater = bLocalPredictedUnderwater ? Depth > ExitDepth : Depth >= EnterDepth;
        if (!HasAuthority() && bPreviousPredictedUnderwater != bLocalPredictedUnderwater)
        {
            OnUnderwaterStateChanged.Broadcast(bLocalPredictedUnderwater);
            BP_OnUnderwaterStateChanged(bLocalPredictedUnderwater);
            NotifySwimmingStateChanged();
        }
    }

    if (HasAuthority())
    {
        const bool bShouldBeUnderwater = bIsUnderwaterSwimming ? Depth > ExitDepth : Depth >= EnterDepth;
        SetAuthoritativeUnderwaterState(bShouldBeUnderwater);
    }

    ApplyMovementSpeed();
    UpdateSurfaceAssist(DeltaSeconds, WaterBody);
    UpdateSwimmingPresentationInternal(DeltaSeconds);
}

void ADMFPlayerAvatarCharacter::UpdateSurfaceAssist(const float DeltaSeconds, ADMFSwimmableWater* WaterBody)
{
    if (!WaterBody || !WaterBody->bEnableSurfaceAssist || IsSwimmingUnderwater() || (!HasAuthority() && !IsLocallyControlled()))
    {
        return;
    }

    UCharacterMovementComponent* Movement = GetCharacterMovement();
    if (!Movement)
    {
        return;
    }

    const double Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
    const bool bRecentVerticalInput = (Now - LastExplicitVerticalSwimInputWorldSeconds) <= 0.20;
    const bool bExplicitDive = bRecentVerticalInput && LastExplicitVerticalSwimInput < -KINDA_SMALL_NUMBER;

    bool bCameraDive = false;
    const bool bRecentForwardInput = (Now - LastSwimForwardInputWorldSeconds) <= 0.20 && FMath::Abs(LastSwimForwardInput) > KINDA_SMALL_NUMBER;
    if (bRecentForwardInput && Controller)
    {
        const FVector CameraForward = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::X);
        bCameraDive = LastSwimForwardInput > 0.0f && CameraForward.Z <= WaterBody->DiveCameraForwardZThreshold;
    }

    // For remote autonomous proxies, the server receives the client's three-dimensional acceleration through
    // CharacterMovement even though it does not run that client's local key handlers. Respecting downward
    // acceleration here keeps authoritative surface assist from fighting Space/C/custom Enhanced Input dives.
    const bool bMovementDive = Movement->GetCurrentAcceleration().Z < -KINDA_SMALL_NUMBER;
    if (bExplicitDive || bCameraDive || bMovementDive)
    {
        return;
    }

    const float TargetZ = WaterBody->GetWaterSurfaceWorldZ() - FMath::Max(0.0f, WaterBody->SurfaceRideDepth);
    const float Error = TargetZ - GetActorLocation().Z;
    const float DesiredVerticalSpeed = FMath::Clamp(
        Error * FMath::Max(0.0f, WaterBody->SurfaceAssistStrength),
        -FMath::Max(0.0f, WaterBody->MaximumSurfaceAssistSpeed),
        FMath::Max(0.0f, WaterBody->MaximumSurfaceAssistSpeed));

    const float InterpSpeed = FMath::Max(0.0f, WaterBody->SurfaceAssistStrength);
    Movement->Velocity.Z = InterpSpeed <= KINDA_SMALL_NUMBER
        ? DesiredVerticalSpeed
        : FMath::FInterpTo(Movement->Velocity.Z, DesiredVerticalSpeed, FMath::Max(0.0f, DeltaSeconds), InterpSpeed);
}

void ADMFPlayerAvatarCharacter::CaptureBasePlayerMeshRelativeTransform()
{
    if (USkeletalMeshComponent* MeshComponent = GetMesh())
    {
        BasePlayerMeshRelativeTransform = MeshComponent->GetRelativeTransform();
        bBasePlayerMeshRelativeTransformCaptured = true;

        // Keep ACharacter's own network-smoothing base aligned with runtime skin/Blueprint mesh offsets. Unreal's
        // CharacterMovement smoothing uses this cached location/rotation as its visual target on remote proxies.
        CacheInitialMeshOffset(BasePlayerMeshRelativeTransform.GetLocation(), BasePlayerMeshRelativeTransform.Rotator());
    }
}

bool ADMFPlayerAvatarCharacter::UsesNetworkSmoothingSwimPresentation() const
{
    // Non-local characters rendered on a client are simulated proxies. A listen server also performs mesh smoothing
    // for its view of remote autonomous clients. In both cases CharacterMovement owns the mesh relative transform,
    // so the swim fallback must alter ACharacter's cached smoothing base instead of writing the mesh transform itself.
    return !IsLocallyControlled() && GetNetMode() != NM_DedicatedServer;
}

void ADMFPlayerAvatarCharacter::ApplyNetworkSmoothingSwimPresentation(const FTransform& DesiredTransform, const float DeltaSeconds, const bool bInstant)
{
    USkeletalMeshComponent* MeshComponent = GetMesh();
    if (!MeshComponent)
    {
        return;
    }

    const float InterpSpeed = FMath::Max(0.0f, SwimFallbackPoseInterpolationSpeed);
    FVector NewBaseLocation = DesiredTransform.GetLocation();
    FQuat NewBaseRotation = DesiredTransform.GetRotation().GetNormalized();

    if (!bInstant && InterpSpeed > KINDA_SMALL_NUMBER)
    {
        const float Alpha = 1.0f - FMath::Exp(-InterpSpeed * FMath::Max(0.0f, DeltaSeconds));
        NewBaseLocation = FMath::Lerp(GetBaseTranslationOffset(), DesiredTransform.GetLocation(), Alpha);
        NewBaseRotation = FQuat::Slerp(GetBaseRotationOffset(), DesiredTransform.GetRotation(), Alpha).GetNormalized();
    }

    // This is the engine-supported runtime path for changing the mesh offset CharacterMovement smooths toward.
    // It avoids competing SetRelativeTransform writes between DMF presentation and SmoothClientPosition. Only
    // invalidate smoothing when the base actually changed, so a stationary swimmer adds no needless proxy work.
    const bool bBaseLocationChanged = !GetBaseTranslationOffset().Equals(NewBaseLocation, 0.01f);
    const bool bBaseRotationChanged = GetBaseRotationOffset().AngularDistance(NewBaseRotation) > FMath::DegreesToRadians(0.01f);
    if (bBaseLocationChanged || bBaseRotationChanged)
    {
        CacheInitialMeshOffset(NewBaseLocation, NewBaseRotation.Rotator());
        if (UCharacterMovementComponent* Movement = GetCharacterMovement())
        {
            // SmoothClientPosition normally stops once the previous target is complete. A replicated swim-state
            // change may happen while the remote pawn is stationary, so explicitly wake visual smoothing for the
            // new base offset instead of waiting for another movement correction packet.
            Movement->bNetworkSmoothingComplete = false;
        }
    }

    // Scale is not part of Character's smoothing-base API. DMF never changes scale for swimming, but preserve a
    // skin-authored scale in case a Blueprint skin uses one.
    if (!MeshComponent->GetRelativeScale3D().Equals(BasePlayerMeshRelativeTransform.GetScale3D(), 0.001f))
    {
        MeshComponent->SetRelativeScale3D(BasePlayerMeshRelativeTransform.GetScale3D());
    }
}

void ADMFPlayerAvatarCharacter::UpdateSwimmingPresentationInternal(const float DeltaSeconds, const bool bInstant)
{
    USkeletalMeshComponent* MeshComponent = GetMesh();
    if (!MeshComponent)
    {
        return;
    }

    if (!bBasePlayerMeshRelativeTransformCaptured)
    {
        CaptureBasePlayerMeshRelativeTransform();
    }

    const bool bSwimming = IsSwimmingInWater();
    if (!bSwimming && !bSwimmingPresentationApplied)
    {
        return;
    }

    FTransform DesiredTransform = BasePlayerMeshRelativeTransform;
    if (bSwimming && bUseNativeSwimFallbackPose)
    {
        FRotator SwimOffset = SwimFallbackMeshRotationOffset;
        if (bPitchSwimFallbackWithTravelDirection && IsSwimmingUnderwater())
        {
            const FVector VelocityDirection = GetVelocity().GetSafeNormal();
            if (!VelocityDirection.IsNearlyZero())
            {
                const float TravelPitch = FMath::RadiansToDegrees(FMath::Asin(FMath::Clamp(VelocityDirection.Z, -1.0f, 1.0f)));
                SwimOffset.Pitch += FMath::Clamp(TravelPitch, -MaximumSwimFallbackTravelPitch, MaximumSwimFallbackTravelPitch);
            }
        }

        const FQuat DesiredRotation = (FQuat(SwimOffset) * BasePlayerMeshRelativeTransform.GetRotation()).GetNormalized();
        DesiredTransform.SetRotation(DesiredRotation);

        // Rotate around the imported mesh-bounds center rather than the component origin (commonly located at
        // the character's feet). This keeps a horizontal fallback body centered near its original visual position.
        FVector DesiredLocation = BasePlayerMeshRelativeTransform.GetLocation() + SwimFallbackMeshLocationOffset;
        if (const USkeletalMesh* SkeletalMeshAsset = MeshComponent->GetSkeletalMeshAsset())
        {
            const FVector LocalVisualPivot = SkeletalMeshAsset->GetImportedBounds().Origin;
            const FVector BaseVisualPivot = BasePlayerMeshRelativeTransform.TransformPosition(LocalVisualPivot);
            const FVector ScaledLocalPivot = LocalVisualPivot * BasePlayerMeshRelativeTransform.GetScale3D();
            DesiredLocation = BaseVisualPivot + SwimFallbackMeshLocationOffset - DesiredRotation.RotateVector(ScaledLocalPivot);
        }
        DesiredTransform.SetLocation(DesiredLocation);
        bSwimmingPresentationApplied = true;
    }

    if (!bUseNativeSwimFallbackPose && bSwimming)
    {
        // Animation-driven Blueprint children still receive the replicated state/events without native mesh rotation.
        return;
    }

    if (UsesNetworkSmoothingSwimPresentation())
    {
        // Critical multiplayer path: never fight CharacterMovement's SmoothClientPosition by directly rotating a
        // remote mesh. Move the smoothing base itself, so normal network interpolation and the swim pose compose.
        ApplyNetworkSmoothingSwimPresentation(DesiredTransform, DeltaSeconds, bInstant);

        if (!bSwimming)
        {
            const bool bLocationDone = GetBaseTranslationOffset().Equals(BasePlayerMeshRelativeTransform.GetLocation(), 0.1f);
            const bool bRotationDone = GetBaseRotationOffset().AngularDistance(BasePlayerMeshRelativeTransform.GetRotation()) <= FMath::DegreesToRadians(0.25f);
            if (bInstant || (bLocationDone && bRotationDone))
            {
                CacheInitialMeshOffset(BasePlayerMeshRelativeTransform.GetLocation(), BasePlayerMeshRelativeTransform.Rotator());
                bSwimmingPresentationApplied = false;
            }
        }
        return;
    }

    const float InterpSpeed = FMath::Max(0.0f, SwimFallbackPoseInterpolationSpeed);
    if (bInstant || InterpSpeed <= KINDA_SMALL_NUMBER)
    {
        MeshComponent->SetRelativeTransform(DesiredTransform);
    }
    else
    {
        const FTransform CurrentTransform = MeshComponent->GetRelativeTransform();
        const float Alpha = 1.0f - FMath::Exp(-InterpSpeed * FMath::Max(0.0f, DeltaSeconds));
        const FVector NewLocation = FMath::Lerp(CurrentTransform.GetLocation(), DesiredTransform.GetLocation(), Alpha);
        const FVector NewScale = FMath::Lerp(CurrentTransform.GetScale3D(), DesiredTransform.GetScale3D(), Alpha);
        const FQuat NewRotation = FQuat::Slerp(CurrentTransform.GetRotation(), DesiredTransform.GetRotation(), Alpha).GetNormalized();
        MeshComponent->SetRelativeTransform(FTransform(NewRotation, NewLocation, NewScale));
    }

    if (!bSwimming)
    {
        const FTransform CurrentTransform = MeshComponent->GetRelativeTransform();
        const bool bLocationDone = CurrentTransform.GetLocation().Equals(BasePlayerMeshRelativeTransform.GetLocation(), 0.1f);
        const bool bScaleDone = CurrentTransform.GetScale3D().Equals(BasePlayerMeshRelativeTransform.GetScale3D(), 0.001f);
        const bool bRotationDone = CurrentTransform.GetRotation().AngularDistance(BasePlayerMeshRelativeTransform.GetRotation()) <= FMath::DegreesToRadians(0.25f);
        if (bInstant || (bLocationDone && bScaleDone && bRotationDone))
        {
            MeshComponent->SetRelativeTransform(BasePlayerMeshRelativeTransform);
            bSwimmingPresentationApplied = false;
        }
    }
}

void ADMFPlayerAvatarCharacter::ConfigureUnderwaterPostProcessFromWater(ADMFSwimmableWater* WaterBody)
{
    if (!UnderwaterPostProcessComponent || !IsValid(WaterBody))
    {
        return;
    }

    const FDMFUnderwaterPostProcessSettings& Profile = WaterBody->UnderwaterPostProcessSettings;

    FPostProcessSettings Settings;
    Settings.bOverride_ColorSaturation = true;
    Settings.ColorSaturation = FVector4(Profile.Saturation, Profile.Saturation, Profile.Saturation, 1.0f);

    Settings.bOverride_ColorContrast = true;
    Settings.ColorContrast = FVector4(Profile.Contrast, Profile.Contrast, Profile.Contrast, 1.0f);

    Settings.bOverride_ColorGamma = true;
    Settings.ColorGamma = FVector4(Profile.Gamma, Profile.Gamma, Profile.Gamma, 1.0f);

    const FLinearColor Tint = FMath::Lerp(FLinearColor::White, Profile.ColorTint, FMath::Clamp(Profile.ColorTintStrength, 0.0f, 1.0f));
    Settings.bOverride_ColorGain = true;
    Settings.ColorGain = FVector4(Tint.R, Tint.G, Tint.B, 1.0f);

    Settings.bOverride_AutoExposureBias = true;
    Settings.AutoExposureBias = Profile.ExposureCompensation;

    Settings.bOverride_VignetteIntensity = true;
    Settings.VignetteIntensity = Profile.VignetteIntensity;

    Settings.bOverride_SceneFringeIntensity = true;
    Settings.SceneFringeIntensity = Profile.ChromaticAberrationIntensity;

    if (Profile.PostProcessMaterial && Profile.PostProcessMaterialWeight > KINDA_SMALL_NUMBER)
    {
        FWeightedBlendable Blendable;
        Blendable.Weight = FMath::Clamp(Profile.PostProcessMaterialWeight, 0.0f, 1.0f);
        Blendable.Object = Profile.PostProcessMaterial.Get();
        Settings.WeightedBlendables.Array.Add(Blendable);
    }

    UnderwaterPostProcessComponent->Settings = Settings;
    UnderwaterPostProcessComponent->Priority = Profile.Priority;

    if (UnderwaterDistanceFogComponent)
    {
        UnderwaterDistanceFogComponent->SetFogInscatteringColor(Profile.DistanceFogColor);
        UnderwaterDistanceFogComponent->SetFogHeightFalloff(FMath::Max(0.001f, Profile.DistanceFogHeightFalloff));
        UnderwaterDistanceFogComponent->SetStartDistance(FMath::Max(0.0f, Profile.DistanceFogStartDistance));
        UnderwaterDistanceFogComponent->SetFogMaxOpacity(FMath::Clamp(Profile.DistanceFogMaxOpacity, 0.0f, 1.0f));
    }

    UnderwaterPostProcessConfiguredWater = WaterBody;
}

void ADMFPlayerAvatarCharacter::UpdateUnderwaterPostProcessPresentation(const float DeltaSeconds, const bool bInstant)
{
    if (!UnderwaterPostProcessComponent)
    {
        return;
    }

    const bool bCanRenderLocalPresentation = IsLocallyControlled() && GetNetMode() != NM_DedicatedServer;
    if (!bCanRenderLocalPresentation)
    {
        UnderwaterPostProcessComponent->BlendWeight = 0.0f;
        UnderwaterPostProcessComponent->bEnabled = false;
        if (UnderwaterDistanceFogComponent)
        {
            if (AppliedUnderwaterDistanceFogDensity > KINDA_SMALL_NUMBER)
            {
                UnderwaterDistanceFogComponent->SetFogDensity(0.0f);
                AppliedUnderwaterDistanceFogDensity = 0.0f;
            }
            if (bUnderwaterDistanceFogVisible)
            {
                UnderwaterDistanceFogComponent->SetVisibility(false, true);
                bUnderwaterDistanceFogVisible = false;
            }
        }
        UnderwaterPostProcessBlendWeight = 0.0f;
        bLocalCameraUnderwater = false;
        LocalCameraUnderwaterWater.Reset();
        return;
    }

    ADMFSwimmableWater* WaterBody = ResolveEffectiveSwimmableWater();
    const bool bValidWater = IsValid(WaterBody) && WaterBody->IsSwimmingEnabled();
    const bool bProfileEnabled = bValidWater && WaterBody->UnderwaterPostProcessSettings.bEnabled;

    if (bProfileEnabled && UnderwaterPostProcessConfiguredWater.Get() != WaterBody)
    {
        ConfigureUnderwaterPostProcessFromWater(WaterBody);
    }

    bool bCameraShouldBeUnderwater = false;
    float CameraUnderwaterTargetWeight = 0.0f;
    if (bProfileEnabled && FollowCamera)
    {
        const FVector CameraLocation = FollowCamera->GetComponentLocation();
        const bool bCameraInsideWaterBounds = WaterBody->IsWorldLocationInsideSwimmingBounds(CameraLocation);
        if (bCameraInsideWaterBounds)
        {
            const FDMFUnderwaterPostProcessSettings& Profile = WaterBody->UnderwaterPostProcessSettings;
            const float CameraDepth = WaterBody->GetDepthBelowSurface(CameraLocation);
            const bool bSameWaterWasUnderwater = bLocalCameraUnderwater && LocalCameraUnderwaterWater.Get() == WaterBody;
            bCameraShouldBeUnderwater = bSameWaterWasUnderwater
                ? CameraDepth > -FMath::Max(0.0f, Profile.CameraExitHeight)
                : CameraDepth >= FMath::Max(0.0f, Profile.CameraEnterDepth);

            if (bCameraShouldBeUnderwater)
            {
                const float ShallowWeight = FMath::Clamp(Profile.ShallowWaterBlendWeight, 0.0f, 1.0f);
                const float FullDepth = FMath::Max(Profile.CameraEnterDepth + 1.0f, Profile.FullStrengthDepth);
                const float DepthAlpha = FMath::Clamp((CameraDepth - Profile.CameraEnterDepth) / (FullDepth - Profile.CameraEnterDepth), 0.0f, 1.0f);
                CameraUnderwaterTargetWeight = FMath::Lerp(ShallowWeight, 1.0f, DepthAlpha);
            }
        }
    }

    ADMFSwimmableWater* NewCameraWater = bCameraShouldBeUnderwater ? WaterBody : nullptr;
    if (bLocalCameraUnderwater != bCameraShouldBeUnderwater || LocalCameraUnderwaterWater.Get() != NewCameraWater)
    {
        bLocalCameraUnderwater = bCameraShouldBeUnderwater;
        LocalCameraUnderwaterWater = NewCameraWater;
        OnLocalCameraUnderwaterChanged.Broadcast(bLocalCameraUnderwater, NewCameraWater);
        BP_OnLocalCameraUnderwaterChanged(bLocalCameraUnderwater, NewCameraWater);
    }

    const float TargetWeight = bCameraShouldBeUnderwater ? CameraUnderwaterTargetWeight : 0.0f;
    const ADMFSwimmableWater* BlendProfileWater = bValidWater ? WaterBody : UnderwaterPostProcessConfiguredWater.Get();
    const FDMFUnderwaterPostProcessSettings* BlendProfile = BlendProfileWater ? &BlendProfileWater->UnderwaterPostProcessSettings : nullptr;
    const float BlendSpeed = TargetWeight > UnderwaterPostProcessBlendWeight
        ? (BlendProfile ? FMath::Max(0.0f, BlendProfile->BlendInSpeed) : 5.0f)
        : (BlendProfile ? FMath::Max(0.0f, BlendProfile->BlendOutSpeed) : 7.0f);

    if (bInstant || BlendSpeed <= KINDA_SMALL_NUMBER)
    {
        UnderwaterPostProcessBlendWeight = TargetWeight;
    }
    else
    {
        const float Alpha = 1.0f - FMath::Exp(-BlendSpeed * FMath::Max(0.0f, DeltaSeconds));
        UnderwaterPostProcessBlendWeight = FMath::Lerp(UnderwaterPostProcessBlendWeight, TargetWeight, Alpha);
        if (FMath::IsNearlyEqual(UnderwaterPostProcessBlendWeight, TargetWeight, 0.001f))
        {
            UnderwaterPostProcessBlendWeight = TargetWeight;
        }
    }

    UnderwaterPostProcessBlendWeight = FMath::Clamp(UnderwaterPostProcessBlendWeight, 0.0f, 1.0f);
    UnderwaterPostProcessComponent->BlendWeight = UnderwaterPostProcessBlendWeight;
    UnderwaterPostProcessComponent->bEnabled = UnderwaterPostProcessBlendWeight > KINDA_SMALL_NUMBER || TargetWeight > KINDA_SMALL_NUMBER;

    // Color grading cannot hide distant terrain by itself. Blend a local exponential fog from the exact same
    // camera-waterline/depth weight so visibility falls off naturally without a level-global PostProcessVolume or
    // project-authored material. The exponent lets shallow water become convincingly hazy before full PP strength.
    if (UnderwaterDistanceFogComponent)
    {
        const bool bUseDistanceFog = BlendProfile
            && BlendProfile->bEnabled
            && BlendProfile->bEnableDistanceFog
            && UnderwaterPostProcessBlendWeight > KINDA_SMALL_NUMBER;

        if (bUseDistanceFog)
        {
            const float FogBlend = FMath::Pow(UnderwaterPostProcessBlendWeight, FMath::Clamp(BlendProfile->DistanceFogBlendExponent, 0.1f, 4.0f));
            const float FogDensity = FMath::Max(0.0f, BlendProfile->DistanceFogDensity) * FogBlend;
            if (!FMath::IsNearlyEqual(AppliedUnderwaterDistanceFogDensity, FogDensity, 0.0005f))
            {
                UnderwaterDistanceFogComponent->SetFogDensity(FogDensity);
                AppliedUnderwaterDistanceFogDensity = FogDensity;
            }
            if (!bUnderwaterDistanceFogVisible)
            {
                UnderwaterDistanceFogComponent->SetVisibility(true, true);
                bUnderwaterDistanceFogVisible = true;
            }
        }
        else
        {
            if (AppliedUnderwaterDistanceFogDensity > KINDA_SMALL_NUMBER)
            {
                UnderwaterDistanceFogComponent->SetFogDensity(0.0f);
                AppliedUnderwaterDistanceFogDensity = 0.0f;
            }
            if (bUnderwaterDistanceFogVisible)
            {
                UnderwaterDistanceFogComponent->SetVisibility(false, true);
                bUnderwaterDistanceFogVisible = false;
            }
        }
    }

    if (UnderwaterPostProcessBlendWeight <= KINDA_SMALL_NUMBER && !bValidWater)
    {
        UnderwaterPostProcessConfiguredWater.Reset();
    }
}

void ADMFPlayerAvatarCharacter::NotifySwimmingStateChanged()
{
    ADMFSwimmableWater* WaterBody = ResolveEffectiveSwimmableWater();
    const bool bSwimming = WaterBody != nullptr;
    const bool bUnderwater = bSwimming && IsSwimmingUnderwater();
    OnSwimmingStateChanged.Broadcast(bSwimming, bUnderwater, WaterBody);
    BP_OnSwimmingStateChanged(bSwimming, bUnderwater, WaterBody);
}

void ADMFPlayerAvatarCharacter::SetAuthoritativeUnderwaterState(const bool bNewUnderwater)
{
    if (!HasAuthority() || bIsUnderwaterSwimming == bNewUnderwater)
    {
        return;
    }

    bIsUnderwaterSwimming = bNewUnderwater;
    RefreshAuthoritativeSwimPresentationState();
    ForceNetUpdate();
    OnUnderwaterStateChanged.Broadcast(bIsUnderwaterSwimming);
    BP_OnUnderwaterStateChanged(bIsUnderwaterSwimming);
    NotifySwimmingStateChanged();
}

void ADMFPlayerAvatarCharacter::RefreshAuthoritativeSwimPresentationState()
{
    if (!HasAuthority())
    {
        return;
    }

    const EDMFPlayerSwimState NewState = ActiveSwimmableWater
        ? (bIsUnderwaterSwimming ? EDMFPlayerSwimState::Underwater : EDMFPlayerSwimState::Surface)
        : EDMFPlayerSwimState::None;

    if (ReplicatedSwimPresentationState != NewState)
    {
        ReplicatedSwimPresentationState = NewState;
        ForceNetUpdate();
    }
}

void ADMFPlayerAvatarCharacter::OnRep_ActiveSwimmableWater()
{
    if (IsLocallyControlled())
    {
        // The owner normally predicts from local overlap, but a replicated authority correction also covers
        // save/load teleports and late joins where the local BeginOverlap may have occurred before possession.
        LocalPredictedSwimmableWater = ActiveSwimmableWater.Get();
        bLocalWaterOverlapPredictionInitialized = true;
        bLocalPredictedUnderwater = ActiveSwimmableWater != nullptr && bIsUnderwaterSwimming;
        if (ActiveSwimmableWater && ActiveSwimmableWater->SwimmingBounds && ActiveSwimmableWater->SwimmingBounds->IsOverlappingActor(this))
        {
            OverlappingSwimmableWaters.AddUnique(TWeakObjectPtr<ADMFSwimmableWater>(ActiveSwimmableWater.Get()));
        }
        else if (!ActiveSwimmableWater)
        {
            bLocalPredictedUnderwater = false;
        }
    }

    if (ResolveEffectiveSwimmableWater())
    {
        ApplySwimmingMovementMode(ResolveEffectiveSwimmableWater());
    }
    else
    {
        RestoreNonSwimmingMovementMode();
    }

    NotifySwimmingStateChanged();
    RefreshSwimmingPresentation();
}

void ADMFPlayerAvatarCharacter::OnRep_UnderwaterSwimming()
{
    if (IsLocallyControlled() && ActiveSwimmableWater)
    {
        // Replication ordering between the water pointer and underwater bool is not guaranteed. Mirror the latest
        // server correction into owner prediction immediately so save/load restoration cannot present Surface for a
        // frame merely because the underwater property arrived after ActiveSwimmableWater.
        LocalPredictedSwimmableWater = ActiveSwimmableWater.Get();
        bLocalWaterOverlapPredictionInitialized = true;
        bLocalPredictedUnderwater = bIsUnderwaterSwimming;
    }

    OnUnderwaterStateChanged.Broadcast(bIsUnderwaterSwimming);
    BP_OnUnderwaterStateChanged(bIsUnderwaterSwimming);
    NotifySwimmingStateChanged();
    ApplyMovementSpeed();
    RefreshSwimmingPresentation();
}

void ADMFPlayerAvatarCharacter::OnRep_ReplicatedSwimPresentationState()
{
    // The owning autonomous proxy keeps immediate local overlap/depth prediction. Remote viewers rebuild their
    // smoothing-compatible fallback pose from this tiny server-authored state, with no mesh-transform RPC.
    if (!IsLocallyControlled())
    {
        // Snap the cached smoothing target to the new authoritative state; CharacterMovement still performs the
        // visible interpolation, so this does not snap the rendered remote mesh.
        UpdateSwimmingPresentationInternal(0.0f, true);
    }
}

void ADMFPlayerAvatarCharacter::ServerSetSprinting_Implementation(const bool bNewSprinting)
{
    bIsSprinting = bNewSprinting;
    ApplyMovementSpeed();
}

void ADMFPlayerAvatarCharacter::OnRep_Sprinting()
{
    ApplyMovementSpeed();
}

void ADMFPlayerAvatarCharacter::ApplyMovementSpeed()
{
    if (UCharacterMovementComponent* Movement = GetCharacterMovement())
    {
        Movement->MaxWalkSpeed = bIsSprinting ? FMath::Max(WalkSpeed, SprintSpeed) : WalkSpeed;

        if (ADMFSwimmableWater* WaterBody = ResolveEffectiveSwimmableWater())
        {
            const float BaseSwimSpeed = IsSwimmingUnderwater() ? WaterBody->UnderwaterSwimSpeed : WaterBody->SurfaceSwimSpeed;
            Movement->MaxFlySpeed = bIsSprinting ? FMath::Max(BaseSwimSpeed, WaterBody->SprintSwimSpeed) : BaseSwimSpeed;
        }
    }
}

bool ADMFPlayerAvatarCharacter::ApplyPlayerSkinData(UDMFPlayerSkinData* SkinData)
{
    if (!SkinData || !SkinData->bEnabled || SkinData->SkeletalMesh.IsNull() || !GetMesh())
    {
        return false;
    }

    USkeletalMesh* NewMesh = SkinData->SkeletalMesh.LoadSynchronous();
    if (!NewMesh)
    {
        return false;
    }

    USkeletalMeshComponent* MeshComponent = GetMesh();
    MeshComponent->EmptyOverrideMaterials();
    MeshComponent->SetSkeletalMesh(NewMesh, true);
    MeshComponent->SetRelativeTransform(SkinData->MeshRelativeTransform);
    BasePlayerMeshRelativeTransform = SkinData->MeshRelativeTransform;
    bBasePlayerMeshRelativeTransformCaptured = true;

    UClass* NewAnimClass = SkinData->AnimClass.LoadSynchronous();
    MeshComponent->SetAnimationMode(EAnimationMode::AnimationBlueprint);
    MeshComponent->SetAnimInstanceClass(NewAnimClass);

    for (int32 MaterialIndex = 0; MaterialIndex < SkinData->MaterialOverrides.Num(); ++MaterialIndex)
    {
        UMaterialInterface* Material = SkinData->MaterialOverrides[MaterialIndex].LoadSynchronous();
        if (Material)
        {
            MeshComponent->SetMaterial(MaterialIndex, Material);
        }
    }

    // Skin swaps can replace mesh render state, so always reassert the framework-wide
    // Custom Depth contract after the new presentation has been applied.
    RefreshFrameworkCustomDepth();

    AppliedPlayerSkinId = SkinData->GetPrimaryAssetId();
    BP_OnPlayerSkinApplied(SkinData);
    // Blueprint skin presentation may apply an additional relative offset; preserve that authored result as the
    // non-swimming base before composing the native fallback pose.
    BasePlayerMeshRelativeTransform = MeshComponent->GetRelativeTransform();
    bBasePlayerMeshRelativeTransformCaptured = true;
    CacheInitialMeshOffset(BasePlayerMeshRelativeTransform.GetLocation(), BasePlayerMeshRelativeTransform.Rotator());
    RefreshSwimmingPresentation();
    return true;
}

void ADMFPlayerAvatarCharacter::RefreshFrameworkCustomDepth()
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

void ADMFPlayerAvatarCharacter::RefreshSkinFromPlayerState()
{
    ADMFPlayerState* DMFPlayerState = GetPlayerState<ADMFPlayerState>();
    if (DMFPlayerState && DMFPlayerState->AvatarComponent)
    {
        DMFPlayerState->AvatarComponent->ApplySelectedSkinToCurrentPawn();
    }
    BP_OnPlayerSkinRefreshRequested();
}

void ADMFPlayerAvatarCharacter::HandleForwardPressed() { bForwardPressed = true; }
void ADMFPlayerAvatarCharacter::HandleForwardReleased() { bForwardPressed = false; }
void ADMFPlayerAvatarCharacter::HandleBackwardPressed() { bBackwardPressed = true; }
void ADMFPlayerAvatarCharacter::HandleBackwardReleased() { bBackwardPressed = false; }
void ADMFPlayerAvatarCharacter::HandleLeftPressed() { bLeftPressed = true; }
void ADMFPlayerAvatarCharacter::HandleLeftReleased() { bLeftPressed = false; }
void ADMFPlayerAvatarCharacter::HandleRightPressed() { bRightPressed = true; }
void ADMFPlayerAvatarCharacter::HandleRightReleased() { bRightPressed = false; }
void ADMFPlayerAvatarCharacter::HandleJumpPressed() { if (IsSwimmingInWater()) bSwimAscendPressed = true; else Jump(); }
void ADMFPlayerAvatarCharacter::HandleJumpReleased() { bSwimAscendPressed = false; if (!IsSwimmingInWater()) StopJumping(); }
void ADMFPlayerAvatarCharacter::HandleSprintPressed() { StartSprinting(); }
void ADMFPlayerAvatarCharacter::HandleSprintReleased() { StopSprinting(); }
void ADMFPlayerAvatarCharacter::HandleCrouchPressed() { if (IsSwimmingInWater()) bSwimDescendPressed = true; else Crouch(); }
void ADMFPlayerAvatarCharacter::HandleCrouchReleased() { bSwimDescendPressed = false; if (!IsSwimmingInWater()) UnCrouch(); }
void ADMFPlayerAvatarCharacter::HandleInteractionPressed() { Interact(); }
void ADMFPlayerAvatarCharacter::HandleMouseX(const float Value) { LookYaw(Value * MouseYawScale); }
void ADMFPlayerAvatarCharacter::HandleMouseY(const float Value) { LookPitch(-Value * MousePitchScale); }
void ADMFPlayerAvatarCharacter::HandleCameraZoomIn() { AddCameraZoomInput(1.0f); }
void ADMFPlayerAvatarCharacter::HandleCameraZoomOut() { AddCameraZoomInput(-1.0f); }
void ADMFPlayerAvatarCharacter::HandleGamepadMoveForward(const float Value) { MoveForward(Value); }
void ADMFPlayerAvatarCharacter::HandleGamepadMoveRight(const float Value) { MoveRight(Value); }
void ADMFPlayerAvatarCharacter::HandleGamepadLookYaw(const float Value) { LookYaw(Value); }
void ADMFPlayerAvatarCharacter::HandleGamepadLookPitch(const float Value) { LookPitch(Value); }
