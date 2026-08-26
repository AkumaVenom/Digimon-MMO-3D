#include "Game/DMFPlayerAvatarCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Components/InputComponent.h"
#include "Components/MeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Data/DMFPlayerSkinData.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Game/DMFPlayerState.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFHealerActor.h"
#include "Game/DMFMMOPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
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
    RefreshWorldNameplate();

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
    // still receive automatic footsteps from actual replicated CharacterMovement velocity.
    UpdateAutomaticPlayerFootsteps(DeltaSeconds);

    if (!IsLocallyControlled() || !bEnableNativeThirdPersonInput)
    {
        return;
    }

    const float ForwardValue = (bForwardPressed ? 1.0f : 0.0f) - (bBackwardPressed ? 1.0f : 0.0f);
    const float RightValue = (bRightPressed ? 1.0f : 0.0f) - (bLeftPressed ? 1.0f : 0.0f);
    MoveForward(ForwardValue);
    MoveRight(RightValue);
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
}

void ADMFPlayerAvatarCharacter::MoveForward(const float Value)
{
    if (!Controller || FMath::IsNearlyZero(Value))
    {
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
void ADMFPlayerAvatarCharacter::HandleJumpPressed() { Jump(); }
void ADMFPlayerAvatarCharacter::HandleJumpReleased() { StopJumping(); }
void ADMFPlayerAvatarCharacter::HandleSprintPressed() { StartSprinting(); }
void ADMFPlayerAvatarCharacter::HandleSprintReleased() { StopSprinting(); }
void ADMFPlayerAvatarCharacter::HandleCrouchPressed() { Crouch(); }
void ADMFPlayerAvatarCharacter::HandleCrouchReleased() { UnCrouch(); }
void ADMFPlayerAvatarCharacter::HandleInteractionPressed() { Interact(); }
void ADMFPlayerAvatarCharacter::HandleMouseX(const float Value) { LookYaw(Value * MouseYawScale); }
void ADMFPlayerAvatarCharacter::HandleMouseY(const float Value) { LookPitch(-Value * MousePitchScale); }
void ADMFPlayerAvatarCharacter::HandleCameraZoomIn() { AddCameraZoomInput(1.0f); }
void ADMFPlayerAvatarCharacter::HandleCameraZoomOut() { AddCameraZoomInput(-1.0f); }
void ADMFPlayerAvatarCharacter::HandleGamepadMoveForward(const float Value) { MoveForward(Value); }
void ADMFPlayerAvatarCharacter::HandleGamepadMoveRight(const float Value) { MoveRight(Value); }
void ADMFPlayerAvatarCharacter::HandleGamepadLookYaw(const float Value) { LookYaw(Value); }
void ADMFPlayerAvatarCharacter::HandleGamepadLookPitch(const float Value) { LookPitch(Value); }
