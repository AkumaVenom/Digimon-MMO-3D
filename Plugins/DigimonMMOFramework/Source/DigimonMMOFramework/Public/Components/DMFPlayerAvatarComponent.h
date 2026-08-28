#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/PrimaryAssetId.h"
#include "DMFPlayerAvatarComponent.generated.h"

struct FDMFAccountRecord;
class UDMFPlayerSkinData;
class ADMFPlayerAvatarCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFPlayerSkinChanged, FPrimaryAssetId, SkinId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFPlayerSkinRequirementChanged, bool, bSelectionRequired);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDMFPlayerSkinSelectionResult, bool, bSuccess, FText, Message, FPrimaryAssetId, SkinId);

/**
 * Owner-routed, server-authoritative player-avatar selection component.
 * Lives on ADMFPlayerState so skin RPCs originate from an actor the owning client controls.
 */
UCLASS(ClassGroup=(DigimonMMO), meta=(BlueprintSpawnableComponent))
class DIGIMONMMOFRAMEWORK_API UDMFPlayerAvatarComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDMFPlayerAvatarComponent();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Player Avatar")
    FDMFPlayerSkinChanged OnPlayerSkinChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Player Avatar")
    FDMFPlayerSkinRequirementChanged OnPlayerSkinRequirementChanged;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Player Avatar")
    FDMFPlayerSkinSelectionResult OnPlayerSkinSelectionResult;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar")
    FPrimaryAssetId GetSelectedPlayerSkinId() const { return SelectedPlayerSkinId; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar")
    bool IsPlayerSkinSelectionRequired() const { return bPlayerSkinSelectionRequired; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar")
    UDMFPlayerSkinData* ResolveSelectedPlayerSkin() const;

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Player Avatar")
    UDMFPlayerSkinData* ResolvePlayerSkin(FPrimaryAssetId SkinId) const;

    /** Returns all enabled registered player-skin Data Assets sorted by DisplayOrder/name. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar")
    TArray<UDMFPlayerSkinData*> GetAvailablePlayerSkins() const;

    /** Client request. Server validates that the requested Primary Data Asset exists and is enabled. */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category="Digimon MMO|Player Avatar")
    void ServerSetPlayerSkin(FPrimaryAssetId SkinId);

    UFUNCTION(Client, Reliable)
    void ClientPlayerSkinSelectionResult(bool bSuccess, const FText& Message, FPrimaryAssetId SkinId);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Player Avatar|Persistence")
    void InitializeFromAccountRecord(const FDMFAccountRecord& Record);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Player Avatar|Persistence")
    void ApplyToAccountRecord(UPARAM(ref) FDMFAccountRecord& Record) const;

    /**
     * Captures the currently possessed framework avatar's authoritative map/location/rotation into the supplied account.
     * Returns false when no valid gameplay avatar exists or location persistence is disabled.
     */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Player Avatar|Persistence")
    bool ApplyCurrentWorldLocationToAccountRecord(UPARAM(ref) FDMFAccountRecord& Record) const;

    /** Re-applies the replicated selected skin to the currently possessed framework avatar pawn. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar")
    bool ApplySelectedSkinToCurrentPawn();

    /** Server/admin recovery hook. If cleared, the owning player is required to select again. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Player Avatar|Admin")
    bool ResetPlayerSkinSelection();

private:
    UPROPERTY(ReplicatedUsing=OnRep_SelectedPlayerSkinId)
    FPrimaryAssetId SelectedPlayerSkinId;

    UPROPERTY(ReplicatedUsing=OnRep_PlayerSkinSelectionRequired)
    bool bPlayerSkinSelectionRequired = true;

    UFUNCTION()
    void OnRep_SelectedPlayerSkinId();

    UFUNCTION()
    void OnRep_PlayerSkinSelectionRequired();

    UDMFPlayerSkinData* ResolveSkinData(FPrimaryAssetId SkinId) const;
    void PersistOwningPlayer();
};
