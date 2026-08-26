#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMFHealerActor.generated.h"

class USceneComponent;
class USphereComponent;
class APlayerController;
class ADMFPlayerState;

/**
 * Server-authoritative, free Digimon healer station/NPC interaction endpoint.
 * Derive this actor in Blueprint and add any mesh/widget/NPC presentation you want. v0.5.2 supplies a
 * native interaction sphere; ADMFPlayerAvatarCharacter::Interact routes healer use through the owning
 * PlayerController to the server. RequestHeal remains available as a lower-level Blueprint API.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFHealerActor : public AActor
{
    GENERATED_BODY()

public:
    ADMFHealerActor();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer")
    TObjectPtr<USceneComponent> SceneRoot;

    /** Native query-only interaction volume so the framework Interact() trace works without project collision setup. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer")
    TObjectPtr<USphereComponent> InteractionCollision;

    /** Runtime master switch. Replicated so Blueprint presentation can reflect server availability. */
    UPROPERTY(ReplicatedUsing=OnRep_Enabled, EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer")
    bool bEnabled = true;

    /** Maximum authoritative distance from player pawn to healer actor. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer", meta=(ClampMin="0.0"))
    float InteractionRadius = 350.0f;

    /** Query-only trace hit volume; intentionally separate from authoritative use distance. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Interaction", meta=(ClampMin="1.0"))
    float InteractionCollisionRadius = 100.0f;

    /** Channel blocked by the native interaction hit volume. Match the player interaction trace channel when customizing it. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Interaction")
    TEnumAsByte<ECollisionChannel> InteractionTraceChannel = ECC_Visibility;

    /** Minimum server-side reuse interval per player to prevent interaction RPC spam. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer", meta=(ClampMin="0.0"))
    float ReuseDelay = 0.5f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bHealHP = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bHealSP = true;

    /** If true, HP restoration revives defeated owned Digimon. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bRestoreDefeatedDigimon = true;

    /** Heals server-side bank records as well as the replicated Party. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bIncludeBankStorage = true;

    /** If the selected active partner is currently recalled/missing, summon it after a successful restore. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Restore")
    bool bSummonActivePartnerAfterHeal = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText InteractionPrompt;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText SuccessMessage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText AlreadyHealthyMessage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText DisabledMessage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Digimon MMO|Healer|Text")
    FText TooFarMessage;

    /** Lower-level API for custom systems. Normal v0.5.2 player setup uses ADMFPlayerAvatarCharacter::Interact. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Healer")
    void RequestHeal(APlayerController* PlayerController);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Healer")
    bool IsPlayerWithinInteractionRange(const APlayerController* PlayerController) const;

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Healer")
    bool TryHealPlayerAuthoritative(APlayerController* PlayerController, UPARAM(ref) int32& OutDigimonHealed, UPARAM(ref) FText& OutMessage);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Healer")
    void SetHealerEnabled(bool bNewEnabled);

    /** Server-side gameplay hook after an accepted use. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Healer")
    void BP_OnPlayerHealed(APlayerController* PlayerController, int32 DigimonHealed);

    /** Cosmetic hook multicast to all relevant clients; useful for glow/audio/NPC animation. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Healer|Presentation")
    void BP_OnHealPresentation(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Healer|Presentation")
    void BP_OnEnabledStateChanged(bool bIsEnabled);

private:
    TMap<TWeakObjectPtr<APlayerController>, double> LastUseServerTimeByPlayer;

    void RefreshInteractionCollision();

    UFUNCTION()
    void OnRep_Enabled();

    UFUNCTION(NetMulticast, Unreliable)
    void MulticastHealPresentation(ADMFPlayerState* HealedPlayerState, int32 DigimonHealed);
};
