#include "UI/DMFStarterEntryButton.h"

void UDMFStarterEntryButton::InitializeStarterChoice(const FPrimaryAssetId InSpeciesId)
{
    SpeciesId = InSpeciesId;
    OnClicked.RemoveDynamic(this, &UDMFStarterEntryButton::HandlePressed);
    OnClicked.AddDynamic(this, &UDMFStarterEntryButton::HandlePressed);
}

void UDMFStarterEntryButton::HandlePressed()
{
    OnStarterPressed.Broadcast(SpeciesId);
}
