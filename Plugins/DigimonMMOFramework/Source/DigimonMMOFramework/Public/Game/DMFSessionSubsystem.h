#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/EngineBaseTypes.h"
#include "Net/Core/Connection/NetEnums.h"
#include "DMFSessionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDMFFrontendStatusChanged, const FText&, Status);

class UNetDriver;

UCLASS()
class DIGIMONMMOFRAMEWORK_API UDMFSessionSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UPROPERTY(BlueprintAssignable, Category="Digimon MMO|Frontend")
    FDMFFrontendStatusChanged OnStatusChanged;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Frontend")
    bool Login(const FString& Username, const FString& Password, FText& OutMessage);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Frontend")
    void Logout();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Frontend")
    bool UnlockAdmin(const FString& AdminPassword, FText& OutMessage);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Frontend")
    bool JoinGame(FText& OutMessage);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|Frontend")
    bool HostAndPlay(FText& OutMessage);

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Frontend")
    bool IsLoggedInLocally() const { return bCredentialsStaged; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Frontend")
    bool IsAdminUnlocked() const { return bAdminUnlocked; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Frontend")
    FString GetStagedUsername() const { return StagedUsername; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|Frontend")
    FText GetLastStatus() const { return LastStatus; }

private:
    FString StagedUsername;
    FString StagedCredentialDigest;
    bool bCredentialsStaged = false;
    bool bAdminUnlocked = false;
    FText LastStatus;

    FDelegateHandle NetworkFailureHandle;
    FDelegateHandle TravelFailureHandle;

    void HandleNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString);
    void HandleTravelFailure(UWorld* World, ETravelFailure::Type FailureType, const FString& ErrorString);

    bool BuildConfiguredServerAddress(FString& OutAddress, FText& OutError) const;
    FString BuildTravelOptions(bool bHostAdmin) const;
    void BroadcastStatus(const FText& Message);
};
