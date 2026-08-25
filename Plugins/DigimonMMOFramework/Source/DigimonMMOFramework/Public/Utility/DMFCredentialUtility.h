#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DMFCredentialUtility.generated.h"

UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFCredentialUtility : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="Digimon MMO|Security")
    static FString HashCredential(const FString& PlainText);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Security")
    static bool IsValidUsername(const FString& Username);
};
