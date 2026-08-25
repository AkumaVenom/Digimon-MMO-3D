#include "UI/DMFScanSpeciesEntryButton.h"

void UDMFScanSpeciesEntryButton::InitializeScanSpecies(const FPrimaryAssetId InSpeciesId)
{
    SpeciesId = InSpeciesId;
    OnClicked.RemoveDynamic(this, &UDMFScanSpeciesEntryButton::HandleClicked);
    OnClicked.AddDynamic(this, &UDMFScanSpeciesEntryButton::HandleClicked);
}

void UDMFScanSpeciesEntryButton::HandleClicked()
{
    OnSpeciesPressed.Broadcast(SpeciesId);
}
