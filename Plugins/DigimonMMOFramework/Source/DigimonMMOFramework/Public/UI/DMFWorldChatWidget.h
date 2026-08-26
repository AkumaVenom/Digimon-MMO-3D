#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Input/Events.h"
#include "Input/Reply.h"
#include "Types/SlateEnums.h"
#include "DMFTypes.h"
#include "DMFWorldChatWidget.generated.h"

class UBorder;
class UEditableTextBox;
class UScrollBox;
class UTextBlock;
class UVerticalBox;

/**
 * Polished native MMO world-chat presentation.
 *
 * Authority remains in ADMFMMOPlayerController/ADMFMMOGameMode. This widget owns only local
 * presentation, bounded client history and text-entry focus. Blueprint children may replace the
 * visual tree while keeping the same validated server message route.
 */
UCLASS(Blueprintable)
class DIGIMONMMOFRAMEWORK_API UDMFWorldChatWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void NativeConstruct() override;
    virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI|World Chat")
    void AddChatMessage(const FDMFWorldChatMessage& ChatMessage);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI|World Chat")
    void SetChatHistory(const TArray<FDMFWorldChatMessage>& ChatMessages);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI|World Chat")
    void AddLocalSystemMessage(const FText& Message);

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI|World Chat")
    void ClearChatHistory();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI|World Chat")
    void OpenChatInput();

    UFUNCTION(BlueprintCallable, Category="Digimon MMO|UI|World Chat")
    void CloseChatInput();

    UFUNCTION(BlueprintPure, Category="Digimon MMO|UI|World Chat")
    bool IsChatInputOpen() const { return bChatInputOpen; }

    UFUNCTION(BlueprintPure, Category="Digimon MMO|UI|World Chat")
    int32 GetVisibleMessageCount() const { return LocalMessageHistory.Num(); }

    /** Fired after a message enters the local bounded history, including history delivered on join. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|UI|World Chat")
    void BP_OnWorldChatMessageAdded(const FDMFWorldChatMessage& ChatMessage);

    /** Lets Blueprint skins react to native Enter/Escape chat focus without taking over authority. */
    UFUNCTION(BlueprintImplementableEvent, Category="Digimon MMO|UI|World Chat")
    void BP_OnWorldChatInputStateChanged(bool bInputOpen);

protected:
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UBorder> ChatPanel;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UScrollBox> MessageScrollBox;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UVerticalBox> MessageList;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UBorder> InputPanel;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UEditableTextBox> MessageInput;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> InputHintText;

private:
    UPROPERTY(Transient)
    TArray<FDMFWorldChatMessage> LocalMessageHistory;

    bool bChatInputOpen = false;

    void BuildNativeFallbackUI();
    void AddNativeMessageRow(const FDMFWorldChatMessage& ChatMessage);
    void RefreshInputPresentation();
    void TrimLocalHistoryToLimit();

    UFUNCTION()
    void HandleMessageCommitted(const FText& Text, ETextCommit::Type CommitMethod);
};
