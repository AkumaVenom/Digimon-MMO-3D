#include "Game/DMFHealerActor.h"

#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Game/DMFMMOPlayerController.h"
#include "Game/DMFPlayerState.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"

ADMFHealerActor::ADMFHealerActor()
{
    bReplicates = true;
    SetReplicateMovement(false);
    PrimaryActorTick.bCanEverTick = false;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    InteractionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionCollision"));
    InteractionCollision->SetupAttachment(SceneRoot);
    InteractionCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    InteractionCollision->SetCollisionObjectType(ECC_WorldDynamic);
    InteractionCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
    InteractionCollision->SetGenerateOverlapEvents(false);

    InteractionPrompt = NSLOCTEXT("DMF", "DefaultHealerPrompt", "Heal Digimon");
    SuccessMessage = NSLOCTEXT("DMF", "DefaultHealerSuccess", "All Digimon have been fully restored.");
    AlreadyHealthyMessage = NSLOCTEXT("DMF", "DefaultHealerAlreadyHealthy", "Your Digimon are already fully restored.");
    DisabledMessage = NSLOCTEXT("DMF", "DefaultHealerDisabled", "This healer is currently unavailable.");
    TooFarMessage = NSLOCTEXT("DMF", "DefaultHealerTooFar", "Move closer to the healer.");
}

void ADMFHealerActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    RefreshInteractionCollision();
}

void ADMFHealerActor::BeginPlay()
{
    Super::BeginPlay();
    RefreshInteractionCollision();
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

void ADMFHealerActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADMFHealerActor, bEnabled);
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
    MulticastHealPresentation(PS, OutDigimonHealed);
    return true;
}

void ADMFHealerActor::SetHealerEnabled(const bool bNewEnabled)
{
    if (!HasAuthority() || bEnabled == bNewEnabled)
    {
        return;
    }

    bEnabled = bNewEnabled;
    BP_OnEnabledStateChanged(bEnabled);
    ForceNetUpdate();
}

void ADMFHealerActor::OnRep_Enabled()
{
    BP_OnEnabledStateChanged(bEnabled);
}

void ADMFHealerActor::MulticastHealPresentation_Implementation(ADMFPlayerState* HealedPlayerState, const int32 DigimonHealed)
{
    BP_OnHealPresentation(HealedPlayerState, DigimonHealed);
}
