#include "UI/DMFPartyDestinationButton.h"

void UDMFPartyDestinationButton::InitializePartyDestination(const int32 InPartySlotIndex)
{
    PartySlotIndex = InPartySlotIndex;
    OnClicked.RemoveDynamic(this, &UDMFPartyDestinationButton::HandlePressed);
    OnClicked.AddDynamic(this, &UDMFPartyDestinationButton::HandlePressed);
}

void UDMFPartyDestinationButton::HandlePressed()
{
    OnPartyDestinationPressed.Broadcast(PartySlotIndex);
}
