#include "UI/DMFPlayerSkinEntryButton.h"

void UDMFPlayerSkinEntryButton::InitializePlayerSkinChoice(const FPrimaryAssetId InSkinId)
{
    SkinId = InSkinId;
    OnClicked.RemoveDynamic(this, &UDMFPlayerSkinEntryButton::HandlePressed);
    OnClicked.AddDynamic(this, &UDMFPlayerSkinEntryButton::HandlePressed);
}

void UDMFPlayerSkinEntryButton::HandlePressed()
{
    OnPlayerSkinPressed.Broadcast(SkinId);
}
