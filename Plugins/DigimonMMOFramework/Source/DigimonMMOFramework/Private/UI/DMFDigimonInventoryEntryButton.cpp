#include "UI/DMFDigimonInventoryEntryButton.h"

void UDMFDigimonInventoryEntryButton::InitializeDigimonEntry(const FGuid InInstanceId)
{
    InstanceId = InInstanceId;
    OnClicked.RemoveDynamic(this, &UDMFDigimonInventoryEntryButton::HandlePressed);
    OnClicked.AddDynamic(this, &UDMFDigimonInventoryEntryButton::HandlePressed);
}

void UDMFDigimonInventoryEntryButton::HandlePressed()
{
    OnDigimonPressed.Broadcast(InstanceId);
}
