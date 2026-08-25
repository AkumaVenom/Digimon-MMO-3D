#include "Components/DMFPlayerAvatarComponent.h"

#include "Data/DMFPlayerSkinData.h"
#include "DMFTypes.h"
#include "Game/DMFPlayerAvatarCharacter.h"
#include "Game/DMFMMOGameMode.h"
#include "Game/DMFPlayerState.h"
#include "Persistence/DMFAccountPersistenceSubsystem.h"
#include "Settings/DMFFrameworkSettings.h"
#include "DigimonMMOFramework.h"
#include "Engine/AssetManager.h"
#include "GameFramework/PlayerController.h"
#include "Net/UnrealNetwork.h"

UDMFPlayerAvatarComponent::UDMFPlayerAvatarComponent()
{
    SetIsReplicatedByDefault(true);
}

void UDMFPlayerAvatarComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UDMFPlayerAvatarComponent, SelectedPlayerSkinId);
    DOREPLIFETIME_CONDITION(UDMFPlayerAvatarComponent, bPlayerSkinSelectionRequired, COND_OwnerOnly);
}

UDMFPlayerSkinData* UDMFPlayerAvatarComponent::ResolveSkinData(const FPrimaryAssetId SkinId) const
{
    if (!SkinId.IsValid() || SkinId.PrimaryAssetType != FPrimaryAssetType(TEXT("DMFPlayerSkin")))
    {
        return nullptr;
    }

    UAssetManager& AssetManager = UAssetManager::Get();
    if (UObject* LoadedObject = AssetManager.GetPrimaryAssetObject(SkinId))
    {
        return Cast<UDMFPlayerSkinData>(LoadedObject);
    }

    const FSoftObjectPath AssetPath = AssetManager.GetPrimaryAssetPath(SkinId);
    return AssetPath.IsValid() ? Cast<UDMFPlayerSkinData>(AssetPath.TryLoad()) : nullptr;
}

UDMFPlayerSkinData* UDMFPlayerAvatarComponent::ResolveSelectedPlayerSkin() const
{
    return ResolveSkinData(SelectedPlayerSkinId);
}

UDMFPlayerSkinData* UDMFPlayerAvatarComponent::ResolvePlayerSkin(const FPrimaryAssetId SkinId) const
{
    return ResolveSkinData(SkinId);
}

TArray<UDMFPlayerSkinData*> UDMFPlayerAvatarComponent::GetAvailablePlayerSkins() const
{
    TArray<FPrimaryAssetId> SkinIds;
    UAssetManager::Get().GetPrimaryAssetIdList(FPrimaryAssetType(TEXT("DMFPlayerSkin")), SkinIds, EAssetManagerFilter::Default);

    TArray<UDMFPlayerSkinData*> Result;
    for (const FPrimaryAssetId SkinId : SkinIds)
    {
        UDMFPlayerSkinData* SkinData = ResolveSkinData(SkinId);
        if (SkinData && SkinData->bEnabled)
        {
            Result.Add(SkinData);
        }
    }

    Result.Sort([](const UDMFPlayerSkinData& A, const UDMFPlayerSkinData& B)
    {
        if (A.DisplayOrder != B.DisplayOrder)
        {
            return A.DisplayOrder < B.DisplayOrder;
        }
        return A.DisplayName.ToString() < B.DisplayName.ToString();
    });
    return Result;
}

void UDMFPlayerAvatarComponent::InitializeFromAccountRecord(const FDMFAccountRecord& Record)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    SelectedPlayerSkinId = Record.SelectedPlayerSkinId;

    UDMFPlayerSkinData* SelectedData = ResolveSkinData(SelectedPlayerSkinId);
    if (!SelectedData || !SelectedData->bEnabled || SelectedData->SkeletalMesh.IsNull())
    {
        SelectedPlayerSkinId = FPrimaryAssetId();
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    bool bAssignedDefaultSkin = false;
    if (!SelectedPlayerSkinId.IsValid() && Settings && !Settings->bRequirePlayerSkinSelection && !Settings->DefaultPlayerSkin.IsNull())
    {
        UDMFPlayerSkinData* DefaultSkin = Settings->DefaultPlayerSkin.LoadSynchronous();
        if (DefaultSkin && DefaultSkin->bEnabled && !DefaultSkin->SkeletalMesh.IsNull())
        {
            SelectedPlayerSkinId = DefaultSkin->GetPrimaryAssetId();
            bAssignedDefaultSkin = true;
        }
    }

    bPlayerSkinSelectionRequired = (Settings ? Settings->bRequirePlayerSkinSelection : true) && !SelectedPlayerSkinId.IsValid();
    OnPlayerSkinChanged.Broadcast(SelectedPlayerSkinId);
    OnPlayerSkinRequirementChanged.Broadcast(bPlayerSkinSelectionRequired);

    if (bAssignedDefaultSkin)
    {
        PersistOwningPlayer();
    }
}

void UDMFPlayerAvatarComponent::ApplyToAccountRecord(FDMFAccountRecord& Record) const
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    Record.SelectedPlayerSkinId = SelectedPlayerSkinId;
}

void UDMFPlayerAvatarComponent::ServerSetPlayerSkin_Implementation(const FPrimaryAssetId SkinId)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    UDMFPlayerSkinData* SkinData = ResolveSkinData(SkinId);
    if (!SkinData)
    {
        ClientPlayerSkinSelectionResult(false, NSLOCTEXT("DMF", "PlayerSkinMissing", "That player skin is not registered with the Asset Manager."), SkinId);
        return;
    }

    if (!SkinData->bEnabled)
    {
        ClientPlayerSkinSelectionResult(false, NSLOCTEXT("DMF", "PlayerSkinDisabled", "That player skin is currently disabled."), SkinId);
        return;
    }

    if (SkinData->SkeletalMesh.IsNull())
    {
        ClientPlayerSkinSelectionResult(false, NSLOCTEXT("DMF", "PlayerSkinNoMesh", "That player skin has no skeletal mesh assigned."), SkinId);
        return;
    }

    SelectedPlayerSkinId = SkinData->GetPrimaryAssetId();
    bPlayerSkinSelectionRequired = false;

    // Skin selection is also an authoritative onboarding checkpoint. If a late-joining client is
    // unpossessed or still represented by Unreal's fallback DefaultPawn, recover/possess the proper
    // MMO avatar first, then apply this account's selected skin to that avatar.
    bool bSkinApplied = ApplySelectedSkinToCurrentPawn();
    if (!bSkinApplied)
    {
        ADMFPlayerState* DMFPlayerState = Cast<ADMFPlayerState>(GetOwner());
        APlayerController* OwningController = DMFPlayerState ? Cast<APlayerController>(DMFPlayerState->GetOwner()) : nullptr;
        ADMFMMOGameMode* MMOGameMode = GetWorld() ? GetWorld()->GetAuthGameMode<ADMFMMOGameMode>() : nullptr;
        if (MMOGameMode && OwningController)
        {
            MMOGameMode->EnsureFrameworkPlayerAvatar(OwningController);
            bSkinApplied = ApplySelectedSkinToCurrentPawn();
        }
    }

    if (!bSkinApplied)
    {
        ClientPlayerSkinSelectionResult(false, NSLOCTEXT("DMF", "PlayerSkinPawnRecoveryFailed", "The character skin was saved, but the gameplay avatar could not be possessed. The server is retrying player recovery."), SelectedPlayerSkinId);
    }

    PersistOwningPlayer();

    OnPlayerSkinChanged.Broadcast(SelectedPlayerSkinId);
    OnPlayerSkinRequirementChanged.Broadcast(false);
    if (bSkinApplied)
    {
        ClientPlayerSkinSelectionResult(true, NSLOCTEXT("DMF", "PlayerSkinApplied", "Character skin applied, possessed and saved."), SelectedPlayerSkinId);
    }

    if (AActor* OwnerActor = GetOwner())
    {
        OwnerActor->ForceNetUpdate();
    }
}

void UDMFPlayerAvatarComponent::ClientPlayerSkinSelectionResult_Implementation(bool bSuccess, const FText& Message, FPrimaryAssetId SkinId)
{
    OnPlayerSkinSelectionResult.Broadcast(bSuccess, Message, SkinId);
}

bool UDMFPlayerAvatarComponent::ApplySelectedSkinToCurrentPawn()
{
    ADMFPlayerState* PlayerState = Cast<ADMFPlayerState>(GetOwner());
    ADMFPlayerAvatarCharacter* Avatar = PlayerState ? PlayerState->GetPawn<ADMFPlayerAvatarCharacter>() : nullptr;
    UDMFPlayerSkinData* SkinData = ResolveSelectedPlayerSkin();

    if (!Avatar || !SkinData || !SkinData->bEnabled)
    {
        return false;
    }

    return Avatar->ApplyPlayerSkinData(SkinData);
}

bool UDMFPlayerAvatarComponent::ResetPlayerSkinSelection()
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return false;
    }

    SelectedPlayerSkinId = FPrimaryAssetId();
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    bPlayerSkinSelectionRequired = Settings ? Settings->bRequirePlayerSkinSelection : true;
    PersistOwningPlayer();
    OnPlayerSkinChanged.Broadcast(SelectedPlayerSkinId);
    OnPlayerSkinRequirementChanged.Broadcast(bPlayerSkinSelectionRequired);

    if (AActor* OwnerActor = GetOwner())
    {
        OwnerActor->ForceNetUpdate();
    }
    return true;
}

void UDMFPlayerAvatarComponent::OnRep_SelectedPlayerSkinId()
{
    ApplySelectedSkinToCurrentPawn();
    OnPlayerSkinChanged.Broadcast(SelectedPlayerSkinId);
}

void UDMFPlayerAvatarComponent::OnRep_PlayerSkinSelectionRequired()
{
    OnPlayerSkinRequirementChanged.Broadcast(bPlayerSkinSelectionRequired);
}

void UDMFPlayerAvatarComponent::PersistOwningPlayer()
{
    ADMFPlayerState* PlayerState = Cast<ADMFPlayerState>(GetOwner());
    if (!PlayerState || !PlayerState->HasAuthority() || PlayerState->GetAuthenticatedUsername().IsEmpty())
    {
        return;
    }

    UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
    UDMFAccountPersistenceSubsystem* Persistence = GameInstance ? GameInstance->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!Persistence)
    {
        return;
    }

    FDMFAccountRecord Record;
    if (!Persistence->GetAccount(PlayerState->GetAuthenticatedUsername(), Record))
    {
        return;
    }

    // Preserve every other account field exactly as loaded and mutate only the avatar field.
    // This keeps avatar persistence transactionally isolated from Digimon runtime initialization/autosave.
    ApplyToAccountRecord(Record);

    FString Error;
    if (!Persistence->SaveAccount(Record, Error))
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("Failed to persist player skin for '%s': %s"), *PlayerState->GetAuthenticatedUsername(), *Error);
    }
}
