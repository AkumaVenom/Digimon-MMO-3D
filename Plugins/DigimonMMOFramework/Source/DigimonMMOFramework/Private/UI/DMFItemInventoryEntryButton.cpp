#include "UI/DMFItemInventoryEntryButton.h"

void UDMFItemInventoryEntryButton::InitializeItemEntry(const FGuid InStackId)
{
    StackId = InStackId;
    OnClicked.RemoveDynamic(this, &UDMFItemInventoryEntryButton::HandlePressed);
    OnClicked.AddDynamic(this, &UDMFItemInventoryEntryButton::HandlePressed);
}

void UDMFItemInventoryEntryButton::HandlePressed()
{
    OnItemStackPressed.Broadcast(StackId);
}
