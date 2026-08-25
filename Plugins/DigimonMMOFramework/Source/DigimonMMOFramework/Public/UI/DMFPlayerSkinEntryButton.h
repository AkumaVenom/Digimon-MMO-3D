#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UObject/PrimaryAssetId.h"
#include "DMFPlayerSkinEntryButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFPlayerSkinEntryPressed, FPrimaryAssetId, SkinId);

UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFPlayerSkinEntryButton : public UButton
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Player Avatar")
    FDMFPlayerSkinEntryPressed OnPlayerSkinPressed;

    UPROPERTY(BlueprintReadOnly, Category="Digimon MMO|Player Avatar")
    FPrimaryAssetId SkinId;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Player Avatar")
    void InitializePlayerSkinChoice(FPrimaryAssetId InSkinId);

private:
    UFUNCTION()
    void HandlePressed();
};
