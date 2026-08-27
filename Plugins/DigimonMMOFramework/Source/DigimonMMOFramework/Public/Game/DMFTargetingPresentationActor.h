#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMFTargetingPresentationActor.generated.h"

class ADMFDigimonCharacter;
class ADMFMMOPlayerController;
class UNiagaraComponent;
class UParticleSystemComponent;
class UPaperSpriteComponent;
class USceneComponent;

/**
 * Local-only combat-selection presentation owned by one local player controller.
 *
 * This actor intentionally does not replicate. It reconstructs presentation from the owning player's
 * already owner-only ActivePartnerActor / CommandTarget state, so one MMO client never sees another
 * player's blue partner ring, red target ring, or target arrow.
 */
UCLASS(BlueprintType, NotPlaceable)
class DIGIMONMMOFRAMEWORK_API ADMFTargetingPresentationActor : public AActor
{
    GENERATED_BODY()

public:
    ADMFTargetingPresentationActor();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    /** Re-reads Project Settings assets/tuning and reapplies the local presentation. */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Combat|Targeting Visuals")
    void RefreshPresentationAssets();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Targeting Visuals")
    ADMFDigimonCharacter* GetPresentedActivePartner() const { return PresentedActivePartner.Get(); }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Combat|Targeting Visuals")
    ADMFDigimonCharacter* GetPresentedCommandTarget() const { return PresentedCommandTarget.Get(); }

private:
    UPROPERTY(VisibleAnywhere, Category="Digimon MMO|Combat|Targeting Visuals", meta=(AllowPrivateAccess="true"))
    TObjectPtr<USceneComponent> PresentationRoot;

    UPROPERTY(VisibleAnywhere, Category="Digimon MMO|Combat|Targeting Visuals", meta=(AllowPrivateAccess="true"))
    TObjectPtr<USceneComponent> ActivePartnerRingPivot;

    UPROPERTY(VisibleAnywhere, Category="Digimon MMO|Combat|Targeting Visuals", meta=(AllowPrivateAccess="true"))
    TObjectPtr<UPaperSpriteComponent> ActivePartnerRingSprite;

    UPROPERTY(VisibleAnywhere, Category="Digimon MMO|Combat|Targeting Visuals", meta=(AllowPrivateAccess="true"))
    TObjectPtr<USceneComponent> EnemyTargetRingPivot;

    UPROPERTY(VisibleAnywhere, Category="Digimon MMO|Combat|Targeting Visuals", meta=(AllowPrivateAccess="true"))
    TObjectPtr<UPaperSpriteComponent> EnemyTargetRingSprite;

    UPROPERTY(VisibleAnywhere, Category="Digimon MMO|Combat|Targeting Visuals", meta=(AllowPrivateAccess="true"))
    TObjectPtr<UNiagaraComponent> EnemyTargetArrowNiagara;

    UPROPERTY(VisibleAnywhere, Category="Digimon MMO|Combat|Targeting Visuals", meta=(AllowPrivateAccess="true"))
    TObjectPtr<UParticleSystemComponent> EnemyTargetArrowCascade;

    TWeakObjectPtr<ADMFMMOPlayerController> OwningFrameworkController;
    TWeakObjectPtr<ADMFDigimonCharacter> PresentedActivePartner;
    TWeakObjectPtr<ADMFDigimonCharacter> PresentedCommandTarget;

    float ActivePartnerRingYaw = 0.0f;
    float EnemyTargetRingYaw = 0.0f;
    float LocalPresentationTime = 0.0f;
    bool bUseNiagaraArrow = false;
    bool bHasNiagaraArrowAsset = false;
    bool bHasCascadeArrowAsset = false;
    bool bArrowPresentationActive = false;

    void ResolveOwningController();
    void HideAllPresentation();
    void UpdateActivePartnerPresentation(ADMFDigimonCharacter* ActivePartner, float DeltaSeconds);
    void UpdateCommandTargetPresentation(ADMFDigimonCharacter* CommandTarget, float DeltaSeconds);
    void UpdateArrowActivation(bool bShouldBeActive, bool bTargetChanged);
    FVector ResolveGroundMarkerLocation(const ADMFDigimonCharacter& Digimon, float GroundOffset) const;
    FVector ResolveArrowLocation(const ADMFDigimonCharacter& Digimon, float HeightOffset, float BobOffset) const;
    float ResolveCapsuleScaleMultiplier(const ADMFDigimonCharacter& Digimon) const;
};
