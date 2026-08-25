#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "Engine/DataAsset.h"
#include "DMFPlayerSkinData.generated.h"

class USkeletalMesh;
class UAnimInstance;
class UTexture2D;
class UMaterialInterface;

/**
 * Data-driven visual definition for a playable MMO avatar skin.
 *
 * Player skins intentionally contain presentation only. Gameplay collision, movement,
 * ownership and network authority remain on ADMFPlayerAvatarCharacter so changing a skin
 * cannot silently replace the authoritative pawn or grant different gameplay capabilities.
 */
UCLASS(BlueprintType)
class DIGIMONMMOFRAMEWORK_API UDMFPlayerSkinData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    /** Stable persistent key. If None, the asset name is used. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FName SkinId;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity", meta=(MultiLine=true))
    FText Description;

    /** Disabled skins stay discoverable as assets but are rejected by the authoritative server. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Availability")
    bool bEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Availability")
    int32 DisplayOrder = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

    /** Optional Animation Blueprint class for this skin. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    TSoftClassPtr<UAnimInstance> AnimClass;

    /** Relative transform applied to the inherited Character mesh component. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    FTransform MeshRelativeTransform = FTransform(FRotator(0.0, -90.0, 0.0), FVector(0.0, 0.0, -90.0), FVector::OneVector);

    /** Optional per-index material overrides. Null entries leave the skeletal mesh default material in place. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Presentation")
    TArray<TSoftObjectPtr<UMaterialInterface>> MaterialOverrides;

    /** Optional portrait used by native/custom selection UIs. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
    TSoftObjectPtr<UTexture2D> Portrait;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        const FName EffectiveName = SkinId.IsNone() ? GetFName() : SkinId;
        return FPrimaryAssetId(TEXT("DMFPlayerSkin"), EffectiveName);
    }
};
