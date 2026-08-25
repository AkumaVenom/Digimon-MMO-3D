#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/PrimaryAssetId.h"
#include "DMFDigimonCarePropActor.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EDMFCarePropType : uint8
{
    DigiMeat,
    Waste
};

/**
 * Lightweight replicated care prop used by the native virtual-pet system.
 * DigiMeat is attached to the Digimon's configured hand socket; Waste is placed on traced ground.
 * Collision, overlap generation and navigation influence are always disabled by the framework.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API ADMFDigimonCarePropActor : public AActor
{
    GENERATED_BODY()

public:
    ADMFDigimonCarePropActor();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void OnConstruction(const FTransform& Transform) override;

    /**
     * Reasserts the framework cel-shading contract on every mesh component owned by this Care prop.
     * DigiMeat and Waste always render into CustomDepth; only the stencil value is project-tunable.
     */
    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Rendering|Cel Shading")
    void RefreshFrameworkCustomDepth();

    /** Stencil value written by all Care-prop mesh components while Custom Depth rendering is enabled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon MMO|Rendering|Cel Shading", meta=(ClampMin="0", ClampMax="255"))
    int32 CustomDepthStencilValue = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Digimon MMO|Care|Presentation")
    TObjectPtr<UStaticMeshComponent> MeshComponent;

    UPROPERTY(ReplicatedUsing=OnRep_Presentation, BlueprintReadOnly, Category="Digimon MMO|Care|Presentation")
    FPrimaryAssetId SpeciesId;

    UPROPERTY(ReplicatedUsing=OnRep_Presentation, BlueprintReadOnly, Category="Digimon MMO|Care|Presentation")
    EDMFCarePropType PropType = EDMFCarePropType::DigiMeat;

    /** Initializes the replicated species/type payload. Transform and attachment remain server-owned actor state. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Digimon MMO|Care|Presentation")
    void InitializeCareProp(FPrimaryAssetId InSpeciesId, EDMFCarePropType InPropType);

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Care|Presentation")
    void BP_OnCarePropPresentationReady(FPrimaryAssetId InSpeciesId, EDMFCarePropType InPropType);

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnRep_Presentation();

    void ApplyPresentation();
};
