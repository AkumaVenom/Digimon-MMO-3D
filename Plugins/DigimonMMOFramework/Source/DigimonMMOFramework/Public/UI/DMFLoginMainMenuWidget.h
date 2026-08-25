#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMFLoginMainMenuWidget.generated.h"

class UEditableTextBox;
class UButton;
class UTextBlock;
class UVerticalBox;

/** Polished native frontend for login, join and protected host controls. */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFLoginMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Frontend")
    void BP_OnLoginAccepted();

    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|Frontend")
    void BP_OnAdminUnlocked();

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UEditableTextBox> UsernameInput;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UEditableTextBox> PasswordInput;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> LoginButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> JoinButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> AdminButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UEditableTextBox> AdminPasswordInput;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> UnlockAdminButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> HostButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> LogoutButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UButton> QuitButton;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> StatusText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> LoggedInUserText;

private:
    UPROPERTY(Transient)
    TObjectPtr<UVerticalBox> LoginSection;

    UPROPERTY(Transient)
    TObjectPtr<UVerticalBox> PlaySection;

    UPROPERTY(Transient)
    TObjectPtr<UVerticalBox> AdminSection;

    UFUNCTION()
    void HandleLogin();

    UFUNCTION()
    void HandleJoin();

    UFUNCTION()
    void HandleAdminToggle();

    UFUNCTION()
    void HandleUnlockAdmin();

    UFUNCTION()
    void HandleHost();

    UFUNCTION()
    void HandleLogout();

    UFUNCTION()
    void HandleQuit();

    UFUNCTION()
    void HandleExternalStatus(const FText& Message);

    void BuildNativeFallbackUI();
    void UpdateStatus(const FText& Message, bool bError = false);
    void ApplyFrontendState();
};
