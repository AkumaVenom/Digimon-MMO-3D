#include "Components/DMFPlayerDigimonComponent.h"
#include "Components/DMFPlayerAvatarComponent.h"
#include "Data/DMFDigimonSpeciesData.h"
#include "Data/DMFItemData.h"
#include "Data/DMFStarterRosterData.h"
#include "Game/DMFDigimonCharacter.h"
#include "Game/DMFDigimonCarePropActor.h"
#include "Game/DMFWildDigimonCharacter.h"
#include "Components/DMFDigimonCombatComponent.h"
#include "Data/DMFDigimonAbilityData.h"
#include "Game/DMFMMOGameMode.h"
#include "Game/DMFPlayerState.h"
#include "Persistence/DMFAccountPersistenceSubsystem.h"
#include "Settings/DMFFrameworkSettings.h"
#include "DigimonMMOFramework.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "Engine/StaticMesh.h"
#include "Engine/AssetManager.h"
#include "Progression/DMFLevelProgressionMath.h"
#include "TimerManager.h"
#include "AIController.h"
#include "Animation/AnimMontage.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"

UDMFPlayerDigimonComponent::UDMFPlayerDigimonComponent()
{
    SetIsReplicatedByDefault(true);
}

void UDMFPlayerDigimonComponent::BeginPlay()
{
    Super::BeginPlay();
    if (GetOwner() && GetOwner()->HasAuthority())
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        const float Interval = Settings ? FMath::Max(5.0f, Settings->AccountAutosaveInterval) : 30.0f;
        GetWorld()->GetTimerManager().SetTimer(AutosaveTimer, this, &UDMFPlayerDigimonComponent::PersistOwningPlayer, Interval, true, Interval);

        const float CareInterval = Settings ? FMath::Clamp(Settings->CareServerTickInterval, 1.0f, 60.0f) : 10.0f;
        GetWorld()->GetTimerManager().SetTimer(CareTickTimer, this, &UDMFPlayerDigimonComponent::CareTick, CareInterval, true, CareInterval);
    }
}

void UDMFPlayerDigimonComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (GetOwner() && GetOwner()->HasAuthority())
    {
        // GameMode::Logout performs the canonical save while Controller/PlayerState/Pawn are all still valid.
        // Never issue a second teardown-time write after that transaction succeeds: on network disconnect the
        // owning pawn/controller can already be partially detached, and serializing component defaults at this
        // stage can destructively replace a perfectly good account record. If Logout could not commit, retain
        // this guarded fallback while the component's authoritative arrays are still available.
        if (!bDisconnectPersistenceFinalized && bAuthoritativeAccountStateInitialized)
        {
            SynchronizeActivePartnerRuntimeForPersistence();
            PersistOwningPlayer();
        }

        // Partner actors are transient session presentation/gameplay actors. They must never survive their owner
        // leaving the server, even when the PlayerState is retained temporarily by AGameMode's inactive-player path.
        FinalizeForOwnerDisconnect(bDisconnectPersistenceFinalized);
    }
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(AutosaveTimer);
        World->GetTimerManager().ClearTimer(CareTickTimer);
        World->GetTimerManager().ClearTimer(CareSequenceTimer);
        World->GetTimerManager().ClearTimer(DigivolutionSequenceTimer);
    }
    DestroyActiveCareMeat();
    Super::EndPlay(EndPlayReason);
}

void UDMFPlayerDigimonComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ReplicatedInventory, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ReplicatedBank, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ReplicatedItemInventory, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ActivePartnerInstanceId, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, bStarterSelectionRequired, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ActivePartnerActor, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, CommandTarget, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, Money, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, ReplicatedScanData, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, bCareSequenceActive, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, CareSequenceInstanceId, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, bDigivolutionSequenceActive, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, DigivolutionSequenceInstanceId, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(UDMFPlayerDigimonComponent, DigivolutionSequenceTargetSpeciesId, COND_OwnerOnly);
}

TArray<FDMFDigimonInstance> UDMFPlayerDigimonComponent::GetDigimonInventory() const
{
    return GetPartyDigimon();
}

TArray<FDMFDigimonInstance> UDMFPlayerDigimonComponent::GetPartyDigimon() const
{
    TArray<FDMFDigimonInstance> Result;
    Result.Reserve(ReplicatedInventory.Items.Num());
    for (const FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        if (Entry.Digimon.IsValid())
        {
            Result.Add(Entry.Digimon);
        }
    }
    return Result;
}

TArray<FDMFDigimonInstance> UDMFPlayerDigimonComponent::GetBankDigimon() const
{
    TArray<FDMFDigimonInstance> Result;
    Result.Reserve(ReplicatedBank.Items.Num());
    for (const FDMFReplicatedDigimonEntry& Entry : ReplicatedBank.Items)
    {
        if (Entry.Digimon.IsValid())
        {
            Result.Add(Entry.Digimon);
        }
    }
    return Result;
}

int32 UDMFPlayerDigimonComponent::GetPartyCapacity() const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    return FMath::Clamp(Settings ? Settings->MaxPartyDigimon : 6, 1, 6);
}

int32 UDMFPlayerDigimonComponent::GetBankCapacity() const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    return FMath::Max(1, Settings ? Settings->MaxDigimonBankStorage : 200);
}

bool UDMFPlayerDigimonComponent::IsActivePartnerSummoned() const
{
    return IsValid(ActivePartnerActor.Get());
}

bool UDMFPlayerDigimonComponent::GetDigimonByInstanceId(const FGuid InstanceId, FDMFDigimonInstance& OutDigimon) const
{
    if (const FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(InstanceId))
    {
        OutDigimon = Entry->Digimon;
        return true;
    }
    return false;
}

bool UDMFPlayerDigimonComponent::GetOwnedDigimonByInstanceId(const FGuid InstanceId, FDMFDigimonInstance& OutDigimon, EDMFDigimonStorageLocation& OutLocation) const
{
    if (const FDMFReplicatedDigimonEntry* PartyEntry = FindInventoryEntry(InstanceId))
    {
        OutDigimon = PartyEntry->Digimon;
        OutLocation = EDMFDigimonStorageLocation::Party;
        return true;
    }
    if (const FDMFReplicatedDigimonEntry* BankEntry = FindBankEntry(InstanceId))
    {
        OutDigimon = BankEntry->Digimon;
        OutLocation = EDMFDigimonStorageLocation::Bank;
        return true;
    }
    return false;
}

bool UDMFPlayerDigimonComponent::AuthorityPurchaseVendorDigimon(const FDMFDigimonInstance& OfferedDigimon, const int64 PurchasePrice, const bool bPreferBank, FGuid& OutNewInstanceId, EDMFDigimonStorageLocation& OutDestination, FText& OutFailureReason)
{
    OutNewInstanceId.Invalidate();
    OutDestination = EDMFDigimonStorageLocation::Party;
    OutFailureReason = FText::GetEmpty();

    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        OutFailureReason = NSLOCTEXT("DMF", "VendorPurchaseAuthorityRequired", "Vendor purchases must be committed by the server.");
        return false;
    }
    if (!OfferedDigimon.IsValid())
    {
        OutFailureReason = NSLOCTEXT("DMF", "VendorPurchaseInvalidDigimon", "The vendor offer is no longer valid.");
        return false;
    }

    FText MutationFailure;
    if (!IsPartyMutationAllowed(MutationFailure))
    {
        OutFailureReason = MutationFailure;
        return false;
    }

    const int64 SafePrice = FMath::Max<int64>(0, PurchasePrice);
    if (Money < SafePrice)
    {
        OutFailureReason = NSLOCTEXT("DMF", "VendorPurchaseInsufficientMoney", "You do not have enough Bits for this Digimon.");
        return false;
    }

    const bool bPartyHasRoom = ReplicatedInventory.Items.Num() < GetPartyCapacity();
    const bool bBankHasRoom = ReplicatedBank.Items.Num() < GetBankCapacity();
    if (!bPartyHasRoom && !bBankHasRoom)
    {
        OutFailureReason = NSLOCTEXT("DMF", "VendorPurchaseStorageFull", "Your Party and Digimon Bank are both full.");
        return false;
    }

    FDMFDigimonInstance Purchased = OfferedDigimon;
    FDMFDigimonInstance Existing;
    EDMFDigimonStorageLocation ExistingLocation = EDMFDigimonStorageLocation::Party;
    if (!Purchased.InstanceId.IsValid() || GetOwnedDigimonByInstanceId(Purchased.InstanceId, Existing, ExistingLocation))
    {
        Purchased.InstanceId = FGuid::NewGuid();
    }
    Purchased.bStarterPartner = false;
    NormalizeDigivolutionProvenance(Purchased);
    Purchased.CurrentHP = FMath::Clamp(Purchased.CurrentHP, 0, FMath::Max(1, Purchased.Stats.MaxHP));
    Purchased.CurrentSP = FMath::Clamp(Purchased.CurrentSP, 0, FMath::Max(0, Purchased.Stats.MaxSP));

    const bool bSendToBank = bPreferBank ? bBankHasRoom : !bPartyHasRoom;
    if (bSendToBank)
    {
        FDMFReplicatedDigimonEntry& NewEntry = ReplicatedBank.Items.AddDefaulted_GetRef();
        NewEntry.Digimon = Purchased;
        ReplicatedBank.MarkItemDirty(NewEntry);
        ReplicatedBank.MarkArrayDirty();
        OutDestination = EDMFDigimonStorageLocation::Bank;
        OnDigimonBankChanged.Broadcast();
    }
    else
    {
        FDMFReplicatedDigimonEntry& NewEntry = ReplicatedInventory.Items.AddDefaulted_GetRef();
        NewEntry.Digimon = Purchased;
        ReplicatedInventory.MarkItemDirty(NewEntry);
        ReplicatedInventory.MarkArrayDirty();
        OutDestination = EDMFDigimonStorageLocation::Party;
        OnDigimonInventoryChanged.Broadcast();

        if (!ActivePartnerInstanceId.IsValid())
        {
            ActivePartnerInstanceId = Purchased.InstanceId;
            bStarterSelectionRequired = false;
        }
    }

    Money = FMath::Max<int64>(0, Money - SafePrice);
    OutNewInstanceId = Purchased.InstanceId;
    OnMoneyChanged.Broadcast(Money);
    PersistOwningPlayer();
    if (GetOwner()) GetOwner()->ForceNetUpdate();

    OutFailureReason = OutDestination == EDMFDigimonStorageLocation::Party
        ? NSLOCTEXT("DMF", "VendorPurchaseSuccessParty", "Purchase complete. The Digimon was added to your Party and saved.")
        : NSLOCTEXT("DMF", "VendorPurchaseSuccessBank", "Purchase complete. The Digimon was sent to your Bank and saved.");
    return true;
}

bool UDMFPlayerDigimonComponent::AuthoritySellDigimonToVendor(const FGuid DigimonInstanceId, const int64 SalePrice, const bool bAllowStarterSale, const bool bRequireAtLeastOnePartyDigimon, FDMFDigimonInstance& OutSoldDigimon, FText& OutFailureReason)
{
    OutSoldDigimon = FDMFDigimonInstance();
    OutFailureReason = FText::GetEmpty();
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        OutFailureReason = NSLOCTEXT("DMF", "VendorSaleAuthorityRequired", "Vendor sales must be committed by the server.");
        return false;
    }

    FText MutationFailure;
    if (!IsPartyMutationAllowed(MutationFailure))
    {
        OutFailureReason = MutationFailure;
        return false;
    }

    const int32 PartyIndex = ReplicatedInventory.Items.IndexOfByPredicate([&](const FDMFReplicatedDigimonEntry& Entry) { return Entry.Digimon.InstanceId == DigimonInstanceId; });
    const int32 BankIndex = ReplicatedBank.Items.IndexOfByPredicate([&](const FDMFReplicatedDigimonEntry& Entry) { return Entry.Digimon.InstanceId == DigimonInstanceId; });
    const bool bFromParty = PartyIndex != INDEX_NONE;
    if (!bFromParty && BankIndex == INDEX_NONE)
    {
        OutFailureReason = NSLOCTEXT("DMF", "VendorSaleMissingDigimon", "That Digimon is no longer owned by your account.");
        return false;
    }

    const FDMFDigimonInstance& Candidate = bFromParty ? ReplicatedInventory.Items[PartyIndex].Digimon : ReplicatedBank.Items[BankIndex].Digimon;
    if (Candidate.bStarterPartner && !bAllowStarterSale)
    {
        OutFailureReason = NSLOCTEXT("DMF", "VendorSaleStarterProtected", "This vendor protects starter partners from being sold.");
        return false;
    }
    if (bFromParty && bRequireAtLeastOnePartyDigimon && ReplicatedInventory.Items.Num() <= 1)
    {
        OutFailureReason = NSLOCTEXT("DMF", "VendorSaleLastPartyMember", "You must keep at least one Digimon in your Party.");
        return false;
    }

    const FGuid PreviousActivePartnerId = ActivePartnerInstanceId;
    const bool bWasSummoned = IsValid(ActivePartnerActor);
    OutSoldDigimon = Candidate;

    if (bFromParty)
    {
        ReplicatedInventory.Items.RemoveAt(PartyIndex);
        ReplicatedInventory.MarkArrayDirty();
        OnDigimonInventoryChanged.Broadcast();
        if (PreviousActivePartnerId == DigimonInstanceId)
        {
            ActivePartnerInstanceId.Invalidate();
        }
        ReconcileActivePartnerAfterPartyMutation(PreviousActivePartnerId, bWasSummoned);
    }
    else
    {
        ReplicatedBank.Items.RemoveAt(BankIndex);
        ReplicatedBank.MarkArrayDirty();
        OnDigimonBankChanged.Broadcast();
    }

    const int64 SafeSalePrice = FMath::Max<int64>(0, SalePrice);
    Money = SafeSalePrice > MAX_int64 - Money ? MAX_int64 : Money + SafeSalePrice;
    OnMoneyChanged.Broadcast(Money);
    PersistOwningPlayer();
    if (GetOwner()) GetOwner()->ForceNetUpdate();

    OutFailureReason = FText::Format(NSLOCTEXT("DMF", "VendorSaleSuccess", "Sale complete. {0} Bits were added to your account and saved."), FText::AsNumber(SafeSalePrice));
    return true;
}


bool UDMFPlayerDigimonComponent::AuthorityPurchaseVendorItem(const FPrimaryAssetId ItemAssetId, const int32 Quantity, const int64 TotalPrice, FText& OutFailureReason)
{
    OutFailureReason = FText::GetEmpty();
    ADMFPlayerState* PlayerState = Cast<ADMFPlayerState>(GetOwner());
    if (!PlayerState || !PlayerState->HasAuthority() || !bAuthoritativeAccountStateInitialized)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorPurchaseAuthority", "Item purchases must be committed by the authoritative server after account initialization.");
        return false;
    }
    if (Quantity <= 0 || Quantity > 999999)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorPurchaseQuantity", "Choose a valid purchase quantity.");
        return false;
    }

    UDMFItemData* Item = ResolveItemData(ItemAssetId);
    if (!Item)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorPurchaseMissingItem", "The server could not resolve that item definition.");
        return false;
    }

    const int64 SafePrice = FMath::Max<int64>(0, TotalPrice);
    if (SafePrice <= 0)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorPurchaseInvalidPrice", "That vendor offer has an invalid price.");
        return false;
    }
    if (Money < SafePrice)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorPurchaseInsufficientBits", "You do not have enough BITS for that quantity.");
        return false;
    }
    if (!CanStoreItemQuantity(ItemAssetId, Quantity))
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorPurchaseInventoryFull", "Your item inventory does not have enough stack capacity for that quantity.");
        return false;
    }

    const int32 MaxStack = FMath::Max(1, Item->MaxStackSize);
    int32 Remaining = Quantity;
    for (FDMFReplicatedItemEntry& Entry : ReplicatedItemInventory.Items)
    {
        if (Remaining <= 0) break;
        if (Entry.Stack.ItemAssetId != ItemAssetId || Entry.Stack.Quantity >= MaxStack) continue;
        const int32 AddQuantity = FMath::Min(Remaining, MaxStack - Entry.Stack.Quantity);
        Entry.Stack.Quantity += AddQuantity;
        Remaining -= AddQuantity;
        ReplicatedItemInventory.MarkItemDirty(Entry);
    }
    while (Remaining > 0 && ReplicatedItemInventory.Items.Num() < GetItemInventoryCapacity())
    {
        FDMFReplicatedItemEntry& NewEntry = ReplicatedItemInventory.Items.AddDefaulted_GetRef();
        NewEntry.Stack.StackId = FGuid::NewGuid();
        NewEntry.Stack.ItemAssetId = ItemAssetId;
        NewEntry.Stack.Quantity = FMath::Min(Remaining, MaxStack);
        Remaining -= NewEntry.Stack.Quantity;
        ReplicatedItemInventory.MarkItemDirty(NewEntry);
    }

    // Capacity was preflighted on this authoritative game-thread transaction; failure here would indicate
    // internal corruption, so do not charge the account if the full requested quantity was not staged.
    if (Remaining != 0)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorPurchaseInternalCapacity", "The item inventory changed before the purchase could be committed. Please try again.");
        return false;
    }

    ReplicatedItemInventory.MarkArrayDirty();
    Money = FMath::Max<int64>(0, Money - SafePrice);
    OnItemInventoryChanged.Broadcast();
    OnMoneyChanged.Broadcast(Money);
    PersistOwningPlayer();
    if (GetOwner()) GetOwner()->ForceNetUpdate();

    OutFailureReason = FText::Format(NSLOCTEXT("DMF", "ItemVendorPurchaseSuccess", "Purchase complete. {0} item(s) were added to your inventory and saved."), FText::AsNumber(Quantity));
    return true;
}

bool UDMFPlayerDigimonComponent::AuthoritySellItemToVendor(const FPrimaryAssetId ItemAssetId, const int32 Quantity, const int64 TotalPrice, FText& OutFailureReason)
{
    OutFailureReason = FText::GetEmpty();
    ADMFPlayerState* PlayerState = Cast<ADMFPlayerState>(GetOwner());
    if (!PlayerState || !PlayerState->HasAuthority() || !bAuthoritativeAccountStateInitialized)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorSaleAuthority", "Item sales must be committed by the authoritative server after account initialization.");
        return false;
    }
    if (Quantity <= 0 || Quantity > 999999)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorSaleQuantity", "Choose a valid sale quantity.");
        return false;
    }

    UDMFItemData* Item = ResolveItemData(ItemAssetId);
    if (!Item)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorSaleMissingItem", "The server could not resolve that item definition.");
        return false;
    }
    if (Item->Category == EDMFItemCategory::KeyItem)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorSaleKeyProtected", "Key Items are protected and cannot be sold.");
        return false;
    }
    if (Item->Category == EDMFItemCategory::Quest)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorSaleQuestProtected", "Quest Items are protected and cannot be sold.");
        return false;
    }
    if (GetTotalItemQuantity(ItemAssetId) < Quantity)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorSaleInsufficientQuantity", "You no longer own that many of this item.");
        return false;
    }

    const int64 SafePrice = FMath::Max<int64>(0, TotalPrice);
    if (SafePrice <= 0)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorSaleInvalidPrice", "That item has an invalid vendor payout.");
        return false;
    }

    int32 Remaining = Quantity;
    for (int32 Index = ReplicatedItemInventory.Items.Num() - 1; Index >= 0 && Remaining > 0; --Index)
    {
        FDMFReplicatedItemEntry& Entry = ReplicatedItemInventory.Items[Index];
        if (Entry.Stack.ItemAssetId != ItemAssetId) continue;
        const int32 RemoveQuantity = FMath::Min(Remaining, Entry.Stack.Quantity);
        Entry.Stack.Quantity -= RemoveQuantity;
        Remaining -= RemoveQuantity;
        if (Entry.Stack.Quantity <= 0)
        {
            ReplicatedItemInventory.Items.RemoveAt(Index);
            ReplicatedItemInventory.MarkArrayDirty();
        }
        else
        {
            ReplicatedItemInventory.MarkItemDirty(Entry);
        }
    }

    if (Remaining != 0)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemVendorSaleInternalQuantity", "The item inventory changed before the sale could be committed. Please try again.");
        return false;
    }

    Money = SafePrice > MAX_int64 - Money ? MAX_int64 : Money + SafePrice;
    OnItemInventoryChanged.Broadcast();
    OnMoneyChanged.Broadcast(Money);
    PersistOwningPlayer();
    if (GetOwner()) GetOwner()->ForceNetUpdate();

    OutFailureReason = FText::Format(NSLOCTEXT("DMF", "ItemVendorSaleSuccess", "Sale complete. {0} BITS were added to your account and saved."), FText::AsNumber(SafePrice));
    return true;
}

int64 UDMFPlayerDigimonComponent::ResolveExperienceRequirement(const UDMFDigimonSpeciesData& Species, const int32 CurrentLevel) const
{
    return DMFLevelProgressionMath::GetExperienceRequiredForLevel(Species, CurrentLevel);
}

int32 UDMFPlayerDigimonComponent::ResolveMaximumLevel(const UDMFDigimonSpeciesData& Species) const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const int32 GlobalMaximum = Settings ? FMath::Clamp(Settings->DefaultMaxDigimonLevel, 1, 999) : 99;
    return Species.MaxLevelOverride > 0 ? FMath::Clamp(Species.MaxLevelOverride, 1, 999) : GlobalMaximum;
}

int64 UDMFPlayerDigimonComponent::GetExperienceRequiredForLevel(const FPrimaryAssetId SpeciesId, const int32 CurrentLevel) const
{
    if (UDMFDigimonSpeciesData* Species = ResolveSpeciesById(SpeciesId))
    {
        if (FMath::Max(1, CurrentLevel) >= ResolveMaximumLevel(*Species))
        {
            return 0;
        }
        return ResolveExperienceRequirement(*Species, CurrentLevel);
    }
    return 0;
}

int32 UDMFPlayerDigimonComponent::GetMaximumLevelForSpecies(const FPrimaryAssetId SpeciesId) const
{
    if (UDMFDigimonSpeciesData* Species = ResolveSpeciesById(SpeciesId))
    {
        return ResolveMaximumLevel(*Species);
    }
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    return Settings ? FMath::Clamp(Settings->DefaultMaxDigimonLevel, 1, 999) : 99;
}

int64 UDMFPlayerDigimonComponent::GetExperienceRequiredForNextLevel(const FGuid InstanceId) const
{
    FDMFDigimonInstance Digimon;
    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Party;
    if (!GetOwnedDigimonByInstanceId(InstanceId, Digimon, Location))
    {
        return 0;
    }
    return GetExperienceRequiredForLevel(Digimon.SpeciesId, Digimon.Stats.Level);
}

float UDMFPlayerDigimonComponent::GetExperienceProgressNormalized(const FGuid InstanceId) const
{
    FDMFDigimonInstance Digimon;
    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Party;
    if (!GetOwnedDigimonByInstanceId(InstanceId, Digimon, Location))
    {
        return 0.0f;
    }

    const int64 Required = GetExperienceRequiredForLevel(Digimon.SpeciesId, Digimon.Stats.Level);
    if (Required <= 0)
    {
        return 1.0f;
    }
    return FMath::Clamp(static_cast<float>(static_cast<double>(FMath::Max<int64>(0, Digimon.Stats.Experience)) / static_cast<double>(Required)), 0.0f, 1.0f);
}

bool UDMFPlayerDigimonComponent::CanSpendDigimonAttributePoint(const FGuid InstanceId, const EDMFDigimonAttributeStat Stat, FText& OutFailureReason) const
{
    OutFailureReason = FText::GetEmpty();
    if (!InstanceId.IsValid())
    {
        OutFailureReason = NSLOCTEXT("DMF", "AttributeSpendInvalidInstance", "Select an owned Digimon first.");
        return false;
    }

    FDMFDigimonInstance Digimon;
    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Party;
    if (!GetOwnedDigimonByInstanceId(InstanceId, Digimon, Location))
    {
        OutFailureReason = NSLOCTEXT("DMF", "AttributeSpendNotOwned", "That Digimon is not owned by this account.");
        return false;
    }
    if (Digimon.UnspentAttributePoints <= 0)
    {
        OutFailureReason = NSLOCTEXT("DMF", "AttributeSpendNoPoints", "This Digimon has no unspent Attribute Points.");
        return false;
    }
    if (bDigivolutionSequenceActive && DigivolutionSequenceInstanceId == InstanceId)
    {
        OutFailureReason = NSLOCTEXT("DMF", "AttributeSpendDuringDigivolution", "Wait for the current Digivolution sequence to finish before spending Attribute Points.");
        return false;
    }

    int32 CurrentValue = MAX_int32;
    switch (Stat)
    {
        case EDMFDigimonAttributeStat::MaxHP: CurrentValue = Digimon.Stats.MaxHP; break;
        case EDMFDigimonAttributeStat::MaxSP: CurrentValue = Digimon.Stats.MaxSP; break;
        case EDMFDigimonAttributeStat::Strength: CurrentValue = Digimon.Stats.Strength; break;
        case EDMFDigimonAttributeStat::Intelligence: CurrentValue = Digimon.Stats.Intelligence; break;
        case EDMFDigimonAttributeStat::Defense: CurrentValue = Digimon.Stats.Defense; break;
        case EDMFDigimonAttributeStat::Speed: CurrentValue = Digimon.Stats.Speed; break;
        default:
            OutFailureReason = NSLOCTEXT("DMF", "AttributeSpendInvalidStat", "That stat cannot receive Attribute Points.");
            return false;
    }

    if (CurrentValue >= MAX_int32)
    {
        OutFailureReason = NSLOCTEXT("DMF", "AttributeSpendStatAtLimit", "That stat has reached the framework integer limit.");
        return false;
    }
    return true;
}

void UDMFPlayerDigimonComponent::ServerSpendDigimonAttributePoint_Implementation(const FGuid InstanceId, const EDMFDigimonAttributeStat Stat)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    FText Failure;
    if (!CanSpendDigimonAttributePoint(InstanceId, Stat, Failure))
    {
        ClientAttributePointSpendResult(false, Failure, InstanceId, Stat, 0, 0);
        return;
    }

    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(InstanceId);
    const bool bPartyEntry = Entry != nullptr;
    if (!Entry)
    {
        Entry = FindBankEntry(InstanceId);
    }
    if (!Entry || Entry->Digimon.UnspentAttributePoints <= 0)
    {
        ClientAttributePointSpendResult(false, NSLOCTEXT("DMF", "AttributeSpendStateChanged", "The Digimon's progression state changed before the request could be applied."), InstanceId, Stat, 0, 0);
        return;
    }

    FDMFDigimonInstance& Digimon = Entry->Digimon;
    int32 NewStatValue = 0;
    switch (Stat)
    {
        case EDMFDigimonAttributeStat::MaxHP:
        {
            ++Digimon.Stats.MaxHP;
            if (Digimon.CurrentHP > 0)
            {
                Digimon.CurrentHP = FMath::Min(Digimon.Stats.MaxHP, Digimon.CurrentHP + 1);
            }
            NewStatValue = Digimon.Stats.MaxHP;
            break;
        }
        case EDMFDigimonAttributeStat::MaxSP:
        {
            ++Digimon.Stats.MaxSP;
            Digimon.CurrentSP = FMath::Min(Digimon.Stats.MaxSP, Digimon.CurrentSP + 1);
            NewStatValue = Digimon.Stats.MaxSP;
            break;
        }
        case EDMFDigimonAttributeStat::Strength: NewStatValue = ++Digimon.Stats.Strength; break;
        case EDMFDigimonAttributeStat::Intelligence: NewStatValue = ++Digimon.Stats.Intelligence; break;
        case EDMFDigimonAttributeStat::Defense: NewStatValue = ++Digimon.Stats.Defense; break;
        case EDMFDigimonAttributeStat::Speed: NewStatValue = ++Digimon.Stats.Speed; break;
        default:
            ClientAttributePointSpendResult(false, NSLOCTEXT("DMF", "AttributeSpendInvalidStatServer", "That stat cannot receive Attribute Points."), InstanceId, Stat, 0, Digimon.UnspentAttributePoints);
            return;
    }

    Digimon.UnspentAttributePoints = FMath::Max(0, Digimon.UnspentAttributePoints - 1);
    Digimon.TotalAttributePointsSpent = FMath::Min(MAX_int32, FMath::Max(0, Digimon.TotalAttributePointsSpent) + 1);
    if (bPartyEntry)
    {
        ReplicatedInventory.MarkItemDirty(*Entry);
        OnDigimonInventoryChanged.Broadcast();
        if (InstanceId == ActivePartnerInstanceId && IsValid(ActivePartnerActor) && ActivePartnerActor->DigimonInstanceId == InstanceId)
        {
            // Public partner stats/vitals follow the committed owner record without respawning or resetting combat.
            ActivePartnerActor->RefreshProgressionFromInstance(Digimon);
        }
    }
    else
    {
        ReplicatedBank.MarkItemDirty(*Entry);
        OnDigimonBankChanged.Broadcast();
    }

    PersistOwningPlayer();
    const UEnum* EnumType = StaticEnum<EDMFDigimonAttributeStat>();
    const FText StatName = EnumType ? EnumType->GetDisplayNameTextByValue(static_cast<int64>(Stat)) : NSLOCTEXT("DMF", "AttributeSpendStatFallback", "Stat");
    const FText SuccessMessage = FText::Format(
        NSLOCTEXT("DMF", "AttributeSpendSuccess", "{0} increased to {1}. {2} Attribute Points remaining."),
        StatName,
        FText::AsNumber(NewStatValue),
        FText::AsNumber(Digimon.UnspentAttributePoints));
    ClientAttributePointSpendResult(true, SuccessMessage, InstanceId, Stat, NewStatValue, Digimon.UnspentAttributePoints);
}

void UDMFPlayerDigimonComponent::ClientAttributePointSpendResult_Implementation(const bool bSuccess, const FText& Message, const FGuid DigimonInstanceId, const EDMFDigimonAttributeStat Stat, const int32 NewStatValue, const int32 RemainingPoints)
{
    OnAttributePointSpendResult.Broadcast(bSuccess, Message, DigimonInstanceId, Stat, NewStatValue, RemainingPoints);
}

void UDMFPlayerDigimonComponent::ApplyLevelGrowth(FDMFDigimonInstance& Digimon, const UDMFDigimonSpeciesData& Species, const int32 LevelsGained, int32& OutAttributePointsGained) const
{
    OutAttributePointsGained = 0;
    if (LevelsGained <= 0)
    {
        return;
    }

    auto AddGrowth = [LevelsGained](const int32 CurrentValue, const int32 PerLevel, const int32 MinimumValue)
    {
        const int64 Added = static_cast<int64>(FMath::Max(0, PerLevel)) * static_cast<int64>(LevelsGained);
        return static_cast<int32>(FMath::Clamp<int64>(static_cast<int64>(CurrentValue) + Added, MinimumValue, MAX_int32));
    };

    const int32 PreviousMaxHP = Digimon.Stats.MaxHP;
    const int32 PreviousMaxSP = Digimon.Stats.MaxSP;
    Digimon.Stats.MaxHP = AddGrowth(Digimon.Stats.MaxHP, Species.HPPerLevel, 1);
    Digimon.Stats.MaxSP = AddGrowth(Digimon.Stats.MaxSP, Species.SPPerLevel, 0);
    Digimon.Stats.Strength = AddGrowth(Digimon.Stats.Strength, Species.StrengthPerLevel, 0);
    Digimon.Stats.Intelligence = AddGrowth(Digimon.Stats.Intelligence, Species.IntelligencePerLevel, 0);
    Digimon.Stats.Defense = AddGrowth(Digimon.Stats.Defense, Species.DefensePerLevel, 0);
    Digimon.Stats.Speed = AddGrowth(Digimon.Stats.Speed, Species.SpeedPerLevel, 0);

    // Preserve damage/SP spent while making the new capacity immediately useful. A defeated Digimon stays defeated.
    if (Digimon.CurrentHP > 0)
    {
        const int64 GrownHP = static_cast<int64>(Digimon.CurrentHP) + static_cast<int64>(Digimon.Stats.MaxHP - PreviousMaxHP);
        Digimon.CurrentHP = static_cast<int32>(FMath::Clamp<int64>(GrownHP, 1, Digimon.Stats.MaxHP));
    }
    const int64 GrownSP = static_cast<int64>(Digimon.CurrentSP) + static_cast<int64>(Digimon.Stats.MaxSP - PreviousMaxSP);
    Digimon.CurrentSP = static_cast<int32>(FMath::Clamp<int64>(GrownSP, 0, Digimon.Stats.MaxSP));

    const int64 AttributeGain64 = static_cast<int64>(FMath::Max(0, Species.AttributePointsPerLevel)) * static_cast<int64>(LevelsGained);
    OutAttributePointsGained = static_cast<int32>(FMath::Clamp<int64>(AttributeGain64, 0, MAX_int32));
    Digimon.UnspentAttributePoints = static_cast<int32>(FMath::Clamp<int64>(static_cast<int64>(Digimon.UnspentAttributePoints) + AttributeGain64, 0, MAX_int32));
}

bool UDMFPlayerDigimonComponent::ApplyExperienceReward(FDMFReplicatedDigimonEntry& Entry, const int64 ExperienceReward, FDMFDigimonExperienceProgression& OutProgression) const
{
    FDMFDigimonInstance& Digimon = Entry.Digimon;
    OutProgression = FDMFDigimonExperienceProgression();
    OutProgression.DigimonInstanceId = Digimon.InstanceId;
    OutProgression.SpeciesId = Digimon.SpeciesId;
    OutProgression.PreviousLevel = FMath::Max(1, Digimon.Stats.Level);
    OutProgression.PreviousExperience = FMath::Max<int64>(0, Digimon.Stats.Experience);

    UDMFDigimonSpeciesData* Species = ResolveSpeciesById(Digimon.SpeciesId);
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bLevelingEnabled = !Settings || Settings->bEnableOwnedDigimonLeveling;
    const int64 SafeReward = FMath::Max<int64>(0, ExperienceReward);
    if (SafeReward > 0)
    {
        Digimon.LifetimeBattleExperience = SafeReward > MAX_int64 - FMath::Max<int64>(0, Digimon.LifetimeBattleExperience)
            ? MAX_int64
            : FMath::Max<int64>(0, Digimon.LifetimeBattleExperience) + SafeReward;
    }

    Digimon.Stats.Level = FMath::Max(1, Digimon.Stats.Level);
    Digimon.Stats.Experience = FMath::Max<int64>(0, Digimon.Stats.Experience);

    if (!Species || !bLevelingEnabled)
    {
        if (SafeReward > 0)
        {
            const int64 Capacity = MAX_int64 - Digimon.Stats.Experience;
            const int64 Applied = FMath::Min(SafeReward, Capacity);
            Digimon.Stats.Experience += Applied;
            OutProgression.ExperienceGained = Applied;
        }
        OutProgression.NewLevel = Digimon.Stats.Level;
        OutProgression.NewExperience = Digimon.Stats.Experience;
        return SafeReward > 0 || OutProgression.ExperienceGained > 0;
    }

    const int32 MaxLevel = ResolveMaximumLevel(*Species);
    if (Digimon.Stats.Level >= MaxLevel)
    {
        // Never de-level a persistent Digimon if a project later lowers its configured cap.
        const bool bNormalized = Digimon.Stats.Experience != 0;
        Digimon.Stats.Experience = 0;
        OutProgression.NewLevel = Digimon.Stats.Level;
        OutProgression.NewExperience = 0;
        OutProgression.bReachedMaxLevel = true;
        return bNormalized || SafeReward > 0;
    }

    if (SafeReward > 0)
    {
        const int64 Capacity = MAX_int64 - Digimon.Stats.Experience;
        const int64 Applied = FMath::Min(SafeReward, Capacity);
        Digimon.Stats.Experience += Applied;
        OutProgression.ExperienceGained = Applied;
    }

    int32 LevelsGained = 0;
    while (Digimon.Stats.Level < MaxLevel)
    {
        const int64 Required = ResolveExperienceRequirement(*Species, Digimon.Stats.Level);
        if (Digimon.Stats.Experience < Required)
        {
            break;
        }
        Digimon.Stats.Experience -= Required;
        ++Digimon.Stats.Level;
        ++LevelsGained;
    }

    int32 AttributePointsGained = 0;
    ApplyLevelGrowth(Digimon, *Species, LevelsGained, AttributePointsGained);
    if (Digimon.Stats.Level >= MaxLevel)
    {
        Digimon.Stats.Experience = 0;
        OutProgression.bReachedMaxLevel = true;
    }

    OutProgression.LevelsGained = LevelsGained;
    OutProgression.AttributePointsGained = AttributePointsGained;
    OutProgression.NewLevel = Digimon.Stats.Level;
    OutProgression.NewExperience = Digimon.Stats.Experience;
    return OutProgression.ExperienceGained > 0 || LevelsGained > 0 || OutProgression.PreviousExperience != OutProgression.NewExperience;
}

bool UDMFPlayerDigimonComponent::NormalizeStoredExperienceForLeveling(FDMFDigimonInstance& Digimon) const
{
    FDMFReplicatedDigimonEntry TempEntry;
    TempEntry.Digimon = Digimon;
    FDMFDigimonExperienceProgression Progression;
    const bool bChanged = ApplyExperienceReward(TempEntry, 0, Progression);
    Digimon = TempEntry.Digimon;
    return bChanged;
}

void UDMFPlayerDigimonComponent::InitializeFromAccountRecord(const FDMFAccountRecord& Record)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    // A PlayerState can pass through Unreal's inactive/reconnect lifecycle. Treat every authoritative account
    // initialization as a new session and do not permit persistence until all account-owned arrays/state below
    // have been reconstructed. This prevents a half-initialized PlayerState from saving empty defaults.
    bAuthoritativeAccountStateInitialized = false;
    bDisconnectPersistenceFinalized = false;

    ReplicatedInventory.Items.Reset();
    ReplicatedBank.Items.Reset();
    ReplicatedItemInventory.Items.Reset();

    const int32 PartyCapacity = GetPartyCapacity();
    const int64 NowUtcTicks = FDateTime::UtcNow().GetTicks();
    const UDMFFrameworkSettings* CareSettings = GetDefault<UDMFFrameworkSettings>();

    // v0.12 migration: DigimonInventory was historically the entire active collection. It is now the Party.
    // Preserve saved Party order; only promote the previous active partner when a legacy collection would otherwise overflow it into Bank.
    TArray<FDMFDigimonInstance> LegacyParty = Record.DigimonInventory;
    TArray<FDMFDigimonInstance> DesiredParty;
    TArray<FDMFDigimonInstance> DesiredBank;
    TSet<FGuid> SeenIds;

    auto AddUniqueValid = [&SeenIds](TArray<FDMFDigimonInstance>& Target, const FDMFDigimonInstance& Digimon)
    {
        if (Digimon.IsValid() && !SeenIds.Contains(Digimon.InstanceId))
        {
            SeenIds.Add(Digimon.InstanceId);
            Target.Add(Digimon);
        }
    };

    // Preserve saved Party order on all current v0.12+ records. Promotion is needed only for a legacy
    // collection where the active partner would otherwise fall outside the new Party capacity (or was
    // already present only in the dormant Bank field). This keeps the migration one-way in semantics
    // without reordering a player's six-slot Party every time the account is loaded.
    const int32 LegacyActiveIndex = LegacyParty.IndexOfByPredicate([&](const FDMFDigimonInstance& D)
    {
        return D.InstanceId == Record.ActivePartnerInstanceId;
    });
    const bool bActiveWouldOverflowLegacyParty = Record.ActivePartnerInstanceId.IsValid()
        && LegacyActiveIndex != INDEX_NONE
        && LegacyActiveIndex >= PartyCapacity;
    const bool bActiveExistsOnlyInLegacyBank = Record.ActivePartnerInstanceId.IsValid()
        && LegacyActiveIndex == INDEX_NONE
        && Record.DigimonBank.ContainsByPredicate([&](const FDMFDigimonInstance& D)
        {
            return D.InstanceId == Record.ActivePartnerInstanceId;
        });

    if (bActiveWouldOverflowLegacyParty || bActiveExistsOnlyInLegacyBank)
    {
        const FDMFDigimonInstance* Active = LegacyActiveIndex != INDEX_NONE
            ? &LegacyParty[LegacyActiveIndex]
            : Record.DigimonBank.FindByPredicate([&](const FDMFDigimonInstance& D)
            {
                return D.InstanceId == Record.ActivePartnerInstanceId;
            });
        if (Active)
        {
            AddUniqueValid(DesiredParty, *Active);
        }
    }

    for (const FDMFDigimonInstance& Digimon : LegacyParty)
    {
        if (DesiredParty.Num() < PartyCapacity)
        {
            AddUniqueValid(DesiredParty, Digimon);
        }
        else
        {
            AddUniqueValid(DesiredBank, Digimon);
        }
    }
    for (const FDMFDigimonInstance& Digimon : Record.DigimonBank)
    {
        AddUniqueValid(DesiredBank, Digimon);
    }

    auto NormalizeForLoad = [&](FDMFDigimonInstance& Digimon)
    {
        NormalizeDigivolutionProvenance(Digimon);
        NormalizeStoredExperienceForLeveling(Digimon);

        // v0.18/schema-v7 migration: reconstruct conservative valuation provenance only for accounts
        // that predate the economy provenance marker. Current records may legitimately contain a
        // high-level Digimon with exactly zero spent Attribute Points, so value==0 is not a migration sentinel.
        if (Record.DigimonEconomyProvenanceVersion < 1)
        {
            if (UDMFDigimonSpeciesData* ProgressionSpecies = ResolveSpeciesById(Digimon.SpeciesId))
            {
                if (Digimon.LifetimeBattleExperience <= 0 && (Digimon.Stats.Level > 1 || Digimon.Stats.Experience > 0))
                {
                    int64 InferredLifetimeExperience = 0;
                    for (int32 Level = FMath::Max(1, ProgressionSpecies->StartingLevel); Level < FMath::Max(1, Digimon.Stats.Level); ++Level)
                    {
                        const int64 Required = ResolveExperienceRequirement(*ProgressionSpecies, Level);
                        if (Required > MAX_int64 - InferredLifetimeExperience)
                        {
                            InferredLifetimeExperience = MAX_int64;
                            break;
                        }
                        InferredLifetimeExperience += Required;
                    }
                    if (InferredLifetimeExperience < MAX_int64)
                    {
                        InferredLifetimeExperience = Digimon.Stats.Experience > MAX_int64 - InferredLifetimeExperience
                            ? MAX_int64
                            : InferredLifetimeExperience + FMath::Max<int64>(0, Digimon.Stats.Experience);
                    }
                    Digimon.LifetimeBattleExperience = InferredLifetimeExperience;
                }

                if (Digimon.TotalAttributePointsSpent <= 0)
                {
                    const int32 EarnedLevels = FMath::Max(0, Digimon.Stats.Level - FMath::Max(1, ProgressionSpecies->StartingLevel));
                    const int64 EarnedPoints = static_cast<int64>(EarnedLevels) * FMath::Max(0, ProgressionSpecies->AttributePointsPerLevel);
                    Digimon.TotalAttributePointsSpent = static_cast<int32>(FMath::Clamp<int64>(EarnedPoints - FMath::Max(0, Digimon.UnspentAttributePoints), 0, MAX_int32));
                }
            }
        }

        if (CareSettings && CareSettings->bEnableCareSystem)
        {
            if (UDMFDigimonSpeciesData* Species = ResolveSpeciesById(Digimon.SpeciesId))
            {
                FDMFReplicatedDigimonEntry Temp;
                Temp.Digimon = Digimon;
                NormalizeAndApplyCareDecay(Temp, *Species, NowUtcTicks);
                Digimon = Temp.Digimon;
            }
        }
    };

    for (FDMFDigimonInstance& Digimon : DesiredParty)
    {
        NormalizeForLoad(Digimon);
        FDMFReplicatedDigimonEntry& NewEntry = ReplicatedInventory.Items.AddDefaulted_GetRef();
        NewEntry.Digimon = Digimon;
        ReplicatedInventory.MarkItemDirty(NewEntry);
    }
    for (FDMFDigimonInstance& Digimon : DesiredBank)
    {
        NormalizeForLoad(Digimon);
        FDMFReplicatedDigimonEntry& NewEntry = ReplicatedBank.Items.AddDefaulted_GetRef();
        NewEntry.Digimon = Digimon;
        ReplicatedBank.MarkItemDirty(NewEntry);
    }
    ReplicatedInventory.MarkArrayDirty();
    ReplicatedBank.MarkArrayDirty();

    // v0.20.0/schema-v9: item stacks are private account state. Never truncate an existing oversized bag
    // during migration, and never discard a valid persisted item merely because an Asset Manager rule is
    // temporarily missing. Invalid/duplicate stack GUIDs are repaired so mutation requests stay unambiguous.
    TSet<FGuid> LoadedItemStackIds;
    for (FDMFItemStack Stack : Record.ItemInventory)
    {
        if (!Stack.ItemAssetId.IsValid() || Stack.Quantity <= 0)
        {
            continue;
        }
        if (!Stack.StackId.IsValid() || LoadedItemStackIds.Contains(Stack.StackId))
        {
            do
            {
                Stack.StackId = FGuid::NewGuid();
            }
            while (LoadedItemStackIds.Contains(Stack.StackId));
        }
        LoadedItemStackIds.Add(Stack.StackId);
        FDMFReplicatedItemEntry& NewItemEntry = ReplicatedItemInventory.Items.AddDefaulted_GetRef();
        NewItemEntry.Stack = Stack;
        ReplicatedItemInventory.MarkItemDirty(NewItemEntry);
    }
    ReplicatedItemInventory.MarkArrayDirty();

    ActivePartnerInstanceId = Record.ActivePartnerInstanceId;
    if (!FindInventoryEntry(ActivePartnerInstanceId))
    {
        ActivePartnerInstanceId = ReplicatedInventory.Items.IsEmpty() ? FGuid() : ReplicatedInventory.Items[0].Digimon.InstanceId;
    }

    Money = Record.Money;
    ReplicatedScanData = Record.ScanData;
    bCareSequenceActive = false;
    CareSequenceInstanceId.Invalidate();
    bDigivolutionSequenceActive = false;
    DigivolutionSequenceInstanceId.Invalidate();
    DigivolutionSequenceTargetSpeciesId = FPrimaryAssetId();
    bStarterSelectionRequired = !Record.bStarterSelected || !ActivePartnerInstanceId.IsValid();

    OnDigimonInventoryChanged.Broadcast();
    OnDigimonBankChanged.Broadcast();
    OnItemInventoryChanged.Broadcast();
    OnStarterRequirementChanged.Broadcast(bStarterSelectionRequired);
    for (const FDMFScanDataEntry& ScanEntry : ReplicatedScanData)
    {
        BroadcastScanState(ScanEntry.SpeciesId);
    }
    if (const FDMFReplicatedDigimonEntry* ActiveEntry = FindInventoryEntry(ActivePartnerInstanceId))
    {
        BroadcastCareState(*ActiveEntry);
    }

    // Only after the complete Party/Bank/partner/money/scan state is reconstructed may autosave/logout
    // serialize this component back over the persistent account record.
    bAuthoritativeAccountStateInitialized = true;
}

void UDMFPlayerDigimonComponent::ApplyToAccountRecord(FDMFAccountRecord& Record) const
{
    Record.DigimonInventory = GetPartyDigimon();
    Record.DigimonBank = GetBankDigimon();
    Record.ActivePartnerInstanceId = ActivePartnerInstanceId;
    Record.bStarterSelected = !bStarterSelectionRequired && ActivePartnerInstanceId.IsValid();
    Record.Money = Money;
    Record.ItemInventory = GetItemInventory();
    Record.DigimonEconomyProvenanceVersion = 1;
    Record.ScanData = ReplicatedScanData;
}


TArray<FDMFItemStack> UDMFPlayerDigimonComponent::GetItemInventory() const
{
    TArray<FDMFItemStack> Result;
    Result.Reserve(ReplicatedItemInventory.Items.Num());
    for (const FDMFReplicatedItemEntry& Entry : ReplicatedItemInventory.Items)
    {
        if (Entry.Stack.IsValid())
        {
            Result.Add(Entry.Stack);
        }
    }
    return Result;
}

int32 UDMFPlayerDigimonComponent::GetItemInventoryCapacity() const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    return Settings ? FMath::Max(1, Settings->MaxPlayerItemStacks) : 60;
}

int32 UDMFPlayerDigimonComponent::GetTotalItemQuantity(const FPrimaryAssetId ItemAssetId) const
{
    int64 Total = 0;
    for (const FDMFReplicatedItemEntry& Entry : ReplicatedItemInventory.Items)
    {
        if (Entry.Stack.ItemAssetId == ItemAssetId)
        {
            Total += FMath::Max(0, Entry.Stack.Quantity);
        }
    }
    return static_cast<int32>(FMath::Min<int64>(Total, MAX_int32));
}

int32 UDMFPlayerDigimonComponent::GetAvailableItemCapacity(const FPrimaryAssetId ItemAssetId) const
{
    UDMFItemData* Item = ResolveItemData(ItemAssetId);
    if (!Item)
    {
        return 0;
    }

    const int32 MaxStack = FMath::Max(1, Item->MaxStackSize);
    int64 Available = static_cast<int64>(FMath::Max(0, GetItemInventoryCapacity() - ReplicatedItemInventory.Items.Num())) * static_cast<int64>(MaxStack);
    for (const FDMFReplicatedItemEntry& Entry : ReplicatedItemInventory.Items)
    {
        if (Entry.Stack.ItemAssetId == ItemAssetId)
        {
            Available += FMath::Max(0, MaxStack - Entry.Stack.Quantity);
        }
    }
    return static_cast<int32>(FMath::Min<int64>(Available, MAX_int32));
}

bool UDMFPlayerDigimonComponent::CanStoreItemQuantity(const FPrimaryAssetId ItemAssetId, const int32 Quantity) const
{
    return Quantity > 0 && GetAvailableItemCapacity(ItemAssetId) >= Quantity;
}

UDMFItemData* UDMFPlayerDigimonComponent::ResolveItemData(const FPrimaryAssetId ItemAssetId) const
{
    if (!ItemAssetId.IsValid() || ItemAssetId.PrimaryAssetType != FPrimaryAssetType(TEXT("DMFItem")))
    {
        return nullptr;
    }

    UAssetManager& AssetManager = UAssetManager::Get();
    if (UDMFItemData* Loaded = AssetManager.GetPrimaryAssetObject<UDMFItemData>(ItemAssetId))
    {
        return Loaded;
    }
    const FSoftObjectPath Path = AssetManager.GetPrimaryAssetPath(ItemAssetId);
    return Path.IsValid() ? Cast<UDMFItemData>(Path.TryLoad()) : nullptr;
}

FDMFReplicatedItemEntry* UDMFPlayerDigimonComponent::FindItemStack(const FGuid StackId)
{
    return ReplicatedItemInventory.Items.FindByPredicate([&](const FDMFReplicatedItemEntry& Entry){ return Entry.Stack.StackId == StackId; });
}

const FDMFReplicatedItemEntry* UDMFPlayerDigimonComponent::FindItemStack(const FGuid StackId) const
{
    return ReplicatedItemInventory.Items.FindByPredicate([&](const FDMFReplicatedItemEntry& Entry){ return Entry.Stack.StackId == StackId; });
}

bool UDMFPlayerDigimonComponent::GrantItem(const FPrimaryAssetId ItemAssetId, const int32 Quantity, int32& OutGrantedQuantity, FText& OutFailureReason)
{
    OutGrantedQuantity = 0;
    OutFailureReason = FText::GetEmpty();
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    if (!PS || !PS->HasAuthority() || !bAuthoritativeAccountStateInitialized)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemGrantAuthority", "Item inventory is not ready for authoritative mutation.");
        return false;
    }
    if (Quantity <= 0)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemGrantQuantity", "Item quantity must be greater than zero.");
        return false;
    }

    UDMFItemData* Item = ResolveItemData(ItemAssetId);
    if (!Item)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemGrantMissingData", "The item definition could not be resolved by the server.");
        return false;
    }

    const int32 MaxStack = FMath::Max(1, Item->MaxStackSize);
    int64 AvailableCapacity = static_cast<int64>(FMath::Max(0, GetItemInventoryCapacity() - ReplicatedItemInventory.Items.Num())) * MaxStack;
    for (const FDMFReplicatedItemEntry& Entry : ReplicatedItemInventory.Items)
    {
        if (Entry.Stack.ItemAssetId == ItemAssetId)
        {
            AvailableCapacity += FMath::Max(0, MaxStack - Entry.Stack.Quantity);
        }
    }
    if (AvailableCapacity < Quantity)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemBagInsufficientCapacity", "Your item inventory does not have enough stack capacity for that quantity.");
        return false;
    }

    int32 Remaining = Quantity;
    for (FDMFReplicatedItemEntry& Entry : ReplicatedItemInventory.Items)
    {
        if (Remaining <= 0) break;
        if (Entry.Stack.ItemAssetId != ItemAssetId || Entry.Stack.Quantity >= MaxStack) continue;
        const int32 Add = FMath::Min(Remaining, MaxStack - Entry.Stack.Quantity);
        Entry.Stack.Quantity += Add;
        Remaining -= Add;
        OutGrantedQuantity += Add;
        ReplicatedItemInventory.MarkItemDirty(Entry);
    }

    while (Remaining > 0 && ReplicatedItemInventory.Items.Num() < GetItemInventoryCapacity())
    {
        FDMFReplicatedItemEntry& Entry = ReplicatedItemInventory.Items.AddDefaulted_GetRef();
        Entry.Stack.StackId = FGuid::NewGuid();
        Entry.Stack.ItemAssetId = ItemAssetId;
        Entry.Stack.Quantity = FMath::Min(Remaining, MaxStack);
        Remaining -= Entry.Stack.Quantity;
        OutGrantedQuantity += Entry.Stack.Quantity;
        ReplicatedItemInventory.MarkItemDirty(Entry);
    }

    ReplicatedItemInventory.MarkArrayDirty();
    OnItemInventoryChanged.Broadcast();
    PersistOwningPlayer();
    return Remaining == 0 && OutGrantedQuantity == Quantity;
}

bool UDMFPlayerDigimonComponent::RemoveItem(const FPrimaryAssetId ItemAssetId, const int32 Quantity, FText& OutFailureReason)
{
    OutFailureReason = FText::GetEmpty();
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    if (!PS || !PS->HasAuthority() || !bAuthoritativeAccountStateInitialized || Quantity <= 0)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemRemoveInvalid", "Item removal request is invalid or inventory is not ready.");
        return false;
    }
    if (GetTotalItemQuantity(ItemAssetId) < Quantity)
    {
        OutFailureReason = NSLOCTEXT("DMF", "ItemRemoveInsufficient", "Not enough of that item is available.");
        return false;
    }

    int32 Remaining = Quantity;
    for (int32 Index = ReplicatedItemInventory.Items.Num() - 1; Index >= 0 && Remaining > 0; --Index)
    {
        FDMFReplicatedItemEntry& Entry = ReplicatedItemInventory.Items[Index];
        if (Entry.Stack.ItemAssetId != ItemAssetId) continue;
        const int32 Remove = FMath::Min(Remaining, Entry.Stack.Quantity);
        Entry.Stack.Quantity -= Remove;
        Remaining -= Remove;
        if (Entry.Stack.Quantity <= 0)
        {
            ReplicatedItemInventory.Items.RemoveAt(Index);
            ReplicatedItemInventory.MarkArrayDirty();
        }
        else
        {
            ReplicatedItemInventory.MarkItemDirty(Entry);
        }
    }
    OnItemInventoryChanged.Broadcast();
    PersistOwningPlayer();
    return true;
}

bool UDMFPlayerDigimonComponent::ConsumeItemStackQuantity(FDMFReplicatedItemEntry& Entry, const int32 Quantity)
{
    if (Quantity <= 0 || Entry.Stack.Quantity < Quantity)
    {
        return false;
    }
    Entry.Stack.Quantity -= Quantity;
    if (Entry.Stack.Quantity <= 0)
    {
        const FGuid StackId = Entry.Stack.StackId;
        const int32 Index = ReplicatedItemInventory.Items.IndexOfByPredicate([&](const FDMFReplicatedItemEntry& Candidate){ return Candidate.Stack.StackId == StackId; });
        if (Index != INDEX_NONE)
        {
            ReplicatedItemInventory.Items.RemoveAt(Index);
            ReplicatedItemInventory.MarkArrayDirty();
        }
    }
    else
    {
        ReplicatedItemInventory.MarkItemDirty(Entry);
    }
    return true;
}

void UDMFPlayerDigimonComponent::ServerUseItem_Implementation(const FGuid StackId, const FGuid TargetDigimonInstanceId)
{
    auto Reject = [&](const FText& Message, const FPrimaryAssetId ItemId = FPrimaryAssetId(), const int32 Remaining = 0)
    {
        ClientItemUseResult(false, Message, StackId, ItemId, TargetDigimonInstanceId, Remaining, 0);
    };

    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    if (!PS || !PS->HasAuthority() || !bAuthoritativeAccountStateInitialized)
    {
        Reject(NSLOCTEXT("DMF", "ItemUseNotReady", "Your item inventory is not ready yet."));
        return;
    }
    if (bCareSequenceActive || bDigivolutionSequenceActive)
    {
        Reject(NSLOCTEXT("DMF", "ItemUseSequenceLocked", "Items cannot be used while a Care or Digivolution sequence is active."));
        return;
    }

    FDMFReplicatedItemEntry* ItemEntry = FindItemStack(StackId);
    if (!ItemEntry || !ItemEntry->Stack.IsValid())
    {
        Reject(NSLOCTEXT("DMF", "ItemUseMissingStack", "That item stack is no longer available."));
        return;
    }
    const FPrimaryAssetId ItemAssetId = ItemEntry->Stack.ItemAssetId;
    UDMFItemData* Item = ResolveItemData(ItemAssetId);
    if (!Item || !Item->bConsumable || Item->UseEffect == EDMFItemUseEffect::None || Item->RestoreAmount <= 0)
    {
        Reject(NSLOCTEXT("DMF", "ItemUseNotUsable", "That item cannot be used from the inventory."), ItemAssetId, ItemEntry->Stack.Quantity);
        return;
    }

    // If the target is the summoned partner, commit its latest live replicated combat vitals back into the
    // persistent Party instance before calculating a capsule restore. This prevents stale menu data from healing
    // from an earlier value while combat is active.
    if (TargetDigimonInstanceId == ActivePartnerInstanceId && IsValid(ActivePartnerActor) && ActivePartnerActor->CombatComponent)
    {
        SynchronizeActivePartnerRuntimeForPersistence();
    }

    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Party;
    FDMFReplicatedDigimonEntry* TargetEntry = FindInventoryEntry(TargetDigimonInstanceId);
    if (!TargetEntry)
    {
        TargetEntry = FindBankEntry(TargetDigimonInstanceId);
        Location = EDMFDigimonStorageLocation::Bank;
    }
    if (!TargetEntry)
    {
        Reject(NSLOCTEXT("DMF", "ItemUseInvalidTarget", "Choose a Digimon owned by this account."), ItemAssetId, ItemEntry->Stack.Quantity);
        return;
    }

    FDMFDigimonInstance& Digimon = TargetEntry->Digimon;
    const bool bDefeated = Digimon.CurrentHP <= 0;
    if (Item->bRequiresLivingDigimon && bDefeated && !(Item->UseEffect == EDMFItemUseEffect::RestoreHP && Item->bCanRestoreDefeatedDigimon))
    {
        Reject(NSLOCTEXT("DMF", "ItemUseDefeatedTarget", "That Digimon is defeated and cannot use this capsule."), ItemAssetId, ItemEntry->Stack.Quantity);
        return;
    }

    int32 RestoredAmount = 0;
    int32 NewHP = Digimon.CurrentHP;
    int32 NewSP = Digimon.CurrentSP;
    if (Item->UseEffect == EDMFItemUseEffect::RestoreHP)
    {
        const int32 MaxHP = FMath::Max(1, Digimon.Stats.MaxHP);
        const int32 OldHP = FMath::Clamp(Digimon.CurrentHP, 0, MaxHP);
        if (OldHP >= MaxHP)
        {
            Reject(NSLOCTEXT("DMF", "ItemUseHPFull", "That Digimon already has full HP."), ItemAssetId, ItemEntry->Stack.Quantity);
            return;
        }
        const int32 MinHP = (OldHP <= 0 && Item->bCanRestoreDefeatedDigimon) ? 1 : 0;
        const int64 CandidateHP = static_cast<int64>(OldHP) + static_cast<int64>(Item->RestoreAmount);
        NewHP = static_cast<int32>(FMath::Clamp<int64>(CandidateHP, static_cast<int64>(MinHP), static_cast<int64>(MaxHP)));
        RestoredAmount = NewHP - OldHP;
    }
    else if (Item->UseEffect == EDMFItemUseEffect::RestoreSP)
    {
        const int32 MaxSP = FMath::Max(0, Digimon.Stats.MaxSP);
        const int32 OldSP = FMath::Clamp(Digimon.CurrentSP, 0, MaxSP);
        if (OldSP >= MaxSP)
        {
            Reject(NSLOCTEXT("DMF", "ItemUseSPFull", "That Digimon already has full SP."), ItemAssetId, ItemEntry->Stack.Quantity);
            return;
        }
        const int64 CandidateSP = static_cast<int64>(OldSP) + static_cast<int64>(Item->RestoreAmount);
        NewSP = static_cast<int32>(FMath::Clamp<int64>(CandidateSP, static_cast<int64>(0), static_cast<int64>(MaxSP)));
        RestoredAmount = NewSP - OldSP;
    }

    // Calculate first, consume second, commit vitals last. This keeps the use transaction side-effect free if
    // the stack mutation ever fails validation and guarantees a rejected/full-stat use cannot heal for free.
    if (RestoredAmount <= 0 || !ConsumeItemStackQuantity(*ItemEntry, 1))
    {
        const FDMFReplicatedItemEntry* RemainingEntry = FindItemStack(StackId);
        Reject(NSLOCTEXT("DMF", "ItemUseNoEffect", "The item could not be consumed."), ItemAssetId, RemainingEntry ? RemainingEntry->Stack.Quantity : 0);
        return;
    }
    Digimon.CurrentHP = NewHP;
    Digimon.CurrentSP = NewSP;

    if (Location == EDMFDigimonStorageLocation::Party)
    {
        ReplicatedInventory.MarkItemDirty(*TargetEntry);
        OnDigimonInventoryChanged.Broadcast();
    }
    else
    {
        ReplicatedBank.MarkItemDirty(*TargetEntry);
        OnDigimonBankChanged.Broadcast();
    }

    if (TargetDigimonInstanceId == ActivePartnerInstanceId && IsValid(ActivePartnerActor) && ActivePartnerActor->CombatComponent)
    {
        if (bDefeated && Digimon.CurrentHP > 0)
        {
            // Explicit revival-capable HP items use the established combat initialization semantics so a
            // defeated live actor returns to Idle instead of retaining a Defeated state with positive HP.
            ActivePartnerActor->CombatComponent->InitializeRuntimeVitals(Digimon.CurrentHP, Digimon.CurrentSP);
        }
        else
        {
            ActivePartnerActor->CombatComponent->ApplyAuthoritativeRuntimeVitals(Digimon.CurrentHP, Digimon.CurrentSP);
        }
    }

    OnItemInventoryChanged.Broadcast();
    PersistOwningPlayer();
    const FDMFReplicatedItemEntry* RemainingEntry = FindItemStack(StackId);
    const int32 RemainingQuantity = RemainingEntry ? RemainingEntry->Stack.Quantity : 0;
    const FText Message = Item->UseEffect == EDMFItemUseEffect::RestoreHP
        ? FText::Format(NSLOCTEXT("DMF", "ItemUseHPSuccess", "Restored {0} HP."), FText::AsNumber(RestoredAmount))
        : FText::Format(NSLOCTEXT("DMF", "ItemUseSPSuccess", "Restored {0} SP."), FText::AsNumber(RestoredAmount));
    ClientItemUseResult(true, Message, StackId, ItemAssetId, TargetDigimonInstanceId, RemainingQuantity, RestoredAmount);
}

void UDMFPlayerDigimonComponent::ClientItemUseResult_Implementation(const bool bSuccess, const FText& Message, const FGuid StackId, const FPrimaryAssetId ItemAssetId, const FGuid DigimonInstanceId, const int32 RemainingQuantity, const int32 RestoredAmount)
{
    OnItemUseResult.Broadcast(bSuccess, Message, StackId, ItemAssetId, DigimonInstanceId, RemainingQuantity, RestoredAmount);
}

bool UDMFPlayerDigimonComponent::ResolveStarterSpecies(const FPrimaryAssetId StarterSpeciesId, UDMFDigimonSpeciesData*& OutSpecies) const
{
    OutSpecies = nullptr;
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UDMFStarterRosterData* Roster = Settings ? Settings->StarterRoster.LoadSynchronous() : nullptr;
    if (!Roster)
    {
        return false;
    }

    for (const FDMFStarterRosterEntry& Entry : Roster->Starters)
    {
        if (!Entry.bEnabled)
        {
            continue;
        }

        UDMFDigimonSpeciesData* Species = Entry.Species.LoadSynchronous();
        if (Species && Species->GetPrimaryAssetId() == StarterSpeciesId)
        {
            OutSpecies = Species;
            return true;
        }
    }

    return false;
}

UDMFDigimonSpeciesData* UDMFPlayerDigimonComponent::ResolveSpeciesById(const FPrimaryAssetId SpeciesId) const
{
    if (!SpeciesId.IsValid())
    {
        return nullptr;
    }

    // Primary Asset Manager remains the fastest resolver when the project scans all species data assets.
    UAssetManager& AssetManager = UAssetManager::Get();
    if (UDMFDigimonSpeciesData* Loaded = AssetManager.GetPrimaryAssetObject<UDMFDigimonSpeciesData>(SpeciesId))
    {
        return Loaded;
    }
    const FSoftObjectPath AssetPath = AssetManager.GetPrimaryAssetPath(SpeciesId);
    if (AssetPath.IsValid())
    {
        if (UDMFDigimonSpeciesData* Loaded = Cast<UDMFDigimonSpeciesData>(AssetPath.TryLoad()))
        {
            return Loaded;
        }
    }

    // Production-friendly fallback: walk the Digivolution graph reachable from configured starter species.
    // This means a project can author Champion/Ultimate/Mega assets in stage folders and link them from the
    // Rookie data assets without having to put every evolved form directly into the Starter Roster.
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    UDMFStarterRosterData* Roster = Settings ? Settings->StarterRoster.LoadSynchronous() : nullptr;
    if (!Roster)
    {
        return nullptr;
    }

    TArray<UDMFDigimonSpeciesData*> Queue;
    TSet<FPrimaryAssetId> Visited;
    for (const FDMFStarterRosterEntry& Entry : Roster->Starters)
    {
        if (UDMFDigimonSpeciesData* Candidate = Entry.Species.LoadSynchronous())
        {
            Queue.Add(Candidate);
        }
    }

    constexpr int32 MaxGraphNodes = 512;
    int32 Processed = 0;
    while (!Queue.IsEmpty() && Processed++ < MaxGraphNodes)
    {
        UDMFDigimonSpeciesData* Candidate = Queue[0];
        Queue.RemoveAt(0, 1, EAllowShrinking::No);
        if (!Candidate)
        {
            continue;
        }

        const FPrimaryAssetId CandidateId = Candidate->GetPrimaryAssetId();
        if (Visited.Contains(CandidateId))
        {
            continue;
        }
        Visited.Add(CandidateId);
        if (CandidateId == SpeciesId)
        {
            return Candidate;
        }

        for (const FDMFDigivolutionRequirement& Path : Candidate->Digivolutions)
        {
            if (UDMFDigimonSpeciesData* Target = Path.TargetSpecies.LoadSynchronous())
            {
                if (Target->GetPrimaryAssetId() == SpeciesId)
                {
                    return Target;
                }
                if (!Visited.Contains(Target->GetPrimaryAssetId()))
                {
                    Queue.Add(Target);
                }
            }
        }
    }

    return nullptr;
}

UDMFDigimonSpeciesData* UDMFPlayerDigimonComponent::ResolveDigimonSpecies(const FPrimaryAssetId SpeciesId) const
{
    return ResolveSpeciesById(SpeciesId);
}

void UDMFPlayerDigimonComponent::NormalizeDigivolutionProvenance(FDMFDigimonInstance& Digimon) const
{
    if (!Digimon.SpeciesId.IsValid())
    {
        return;
    }
    if (!Digimon.OriginSpeciesId.IsValid())
    {
        Digimon.OriginSpeciesId = Digimon.SpeciesId;
    }
    if (Digimon.DigivolutionHistory.IsEmpty())
    {
        Digimon.DigivolutionHistory.Add(Digimon.OriginSpeciesId);
    }
    Digimon.DigivolutionHistory.AddUnique(Digimon.SpeciesId);
}

const FDMFDigivolutionRequirement* UDMFPlayerDigimonComponent::FindDigivolutionPath(const UDMFDigimonSpeciesData& SourceSpecies, const FPrimaryAssetId TargetSpeciesId, UDMFDigimonSpeciesData*& OutTargetSpecies) const
{
    OutTargetSpecies = nullptr;
    for (const FDMFDigivolutionRequirement& Requirement : SourceSpecies.Digivolutions)
    {
        UDMFDigimonSpeciesData* Target = Requirement.TargetSpecies.LoadSynchronous();
        if (Target && Target->GetPrimaryAssetId() == TargetSpeciesId)
        {
            OutTargetSpecies = Target;
            return &Requirement;
        }
    }
    return nullptr;
}

bool UDMFPlayerDigimonComponent::EvaluateDigivolutionRequirement(
    const FDMFDigimonInstance& Digimon,
    const EDMFDigimonStorageLocation Location,
    const FDMFDigivolutionRequirement& Requirement,
    const UDMFDigimonSpeciesData& SourceSpecies,
    const UDMFDigimonSpeciesData& TargetSpecies,
    FText& OutFailure,
    FText* OutSummary) const
{
    OutFailure = FText::GetEmpty();
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableDigivolutionSystem)
    {
        OutFailure = NSLOCTEXT("DMF", "DigivolutionDisabled", "Digivolution is disabled by the project settings.");
        return false;
    }
    if (!Digimon.IsValid() || SourceSpecies.GetPrimaryAssetId() != Digimon.SpeciesId || TargetSpecies.GetPrimaryAssetId() == Digimon.SpeciesId)
    {
        OutFailure = NSLOCTEXT("DMF", "DigivolutionInvalidPath", "That Digivolution path is not valid for this Digimon's current form.");
        return false;
    }
    if (Location == EDMFDigimonStorageLocation::Bank && (!Settings->bAllowBankDigivolution || !Requirement.bAllowFromBank))
    {
        OutFailure = NSLOCTEXT("DMF", "DigivolutionBankDisabled", "This Digivolution path requires the Digimon to be in your Party.");
        return false;
    }
    if (Digimon.CurrentHP <= 0)
    {
        OutFailure = NSLOCTEXT("DMF", "DigivolutionDefeated", "Heal this Digimon before Digivolving it.");
        return false;
    }
    if (bCareSequenceActive)
    {
        OutFailure = NSLOCTEXT("DMF", "DigivolutionCareBusy", "Finish the active Care sequence before Digivolving.");
        return false;
    }

    TArray<FString> SummaryParts;
    SummaryParts.Add(FString::Printf(TEXT("Lv.%d"), FMath::Max(1, Requirement.RequiredLevel)));
    if (Digimon.Stats.Level < FMath::Max(1, Requirement.RequiredLevel))
    {
        OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsLevel", "Requires Level {0}."), FText::AsNumber(FMath::Max(1, Requirement.RequiredLevel)));
    }

    if (Requirement.MinimumABI > 0)
    {
        SummaryParts.Add(FString::Printf(TEXT("ABI %d"), Requirement.MinimumABI));
        if (OutFailure.IsEmpty() && Digimon.Stats.ABI < Requirement.MinimumABI)
        {
            OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsABI", "Requires ABI {0}."), FText::AsNumber(Requirement.MinimumABI));
        }
    }
    if (Requirement.MinimumCAM > 0)
    {
        SummaryParts.Add(FString::Printf(TEXT("CAM %d"), Requirement.MinimumCAM));
        if (OutFailure.IsEmpty() && Digimon.Stats.CAM < Requirement.MinimumCAM)
        {
            OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsCAM", "Requires CAM {0}."), FText::AsNumber(Requirement.MinimumCAM));
        }
    }
    if (Requirement.bRequireStats)
    {
        if (Requirement.MinimumStrength > 0) SummaryParts.Add(FString::Printf(TEXT("STR %d"), Requirement.MinimumStrength));
        if (Requirement.MinimumIntelligence > 0) SummaryParts.Add(FString::Printf(TEXT("INT %d"), Requirement.MinimumIntelligence));
        if (Requirement.MinimumDefense > 0) SummaryParts.Add(FString::Printf(TEXT("DEF %d"), Requirement.MinimumDefense));
        if (Requirement.MinimumSpeed > 0) SummaryParts.Add(FString::Printf(TEXT("SPD %d"), Requirement.MinimumSpeed));
        if (OutFailure.IsEmpty() && Digimon.Stats.Strength < Requirement.MinimumStrength) OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsSTR", "Requires STR {0}."), FText::AsNumber(Requirement.MinimumStrength));
        if (OutFailure.IsEmpty() && Digimon.Stats.Intelligence < Requirement.MinimumIntelligence) OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsINT", "Requires INT {0}."), FText::AsNumber(Requirement.MinimumIntelligence));
        if (OutFailure.IsEmpty() && Digimon.Stats.Defense < Requirement.MinimumDefense) OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsDEF", "Requires DEF {0}."), FText::AsNumber(Requirement.MinimumDefense));
        if (OutFailure.IsEmpty() && Digimon.Stats.Speed < Requirement.MinimumSpeed) OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsSPD", "Requires SPD {0}."), FText::AsNumber(Requirement.MinimumSpeed));
    }
    if (Requirement.bRequireCare)
    {
        if (Requirement.MinimumHappiness > 0.0f) SummaryParts.Add(FString::Printf(TEXT("Happiness %.0f%%"), Requirement.MinimumHappiness));
        if (Requirement.MinimumDiscipline > 0.0f) SummaryParts.Add(FString::Printf(TEXT("Discipline %.0f%%"), Requirement.MinimumDiscipline));
        if (Requirement.MaximumCareMistakes >= 0) SummaryParts.Add(FString::Printf(TEXT("Mistakes <= %d"), Requirement.MaximumCareMistakes));
        if (OutFailure.IsEmpty() && Digimon.Care.Happiness + KINDA_SMALL_NUMBER < Requirement.MinimumHappiness) OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsHappiness", "Requires Happiness {0}%."), FText::AsNumber(FMath::RoundToInt(Requirement.MinimumHappiness)));
        if (OutFailure.IsEmpty() && Digimon.Care.Discipline + KINDA_SMALL_NUMBER < Requirement.MinimumDiscipline) OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsDiscipline", "Requires Discipline {0}%."), FText::AsNumber(FMath::RoundToInt(Requirement.MinimumDiscipline)));
        if (OutFailure.IsEmpty() && Requirement.MaximumCareMistakes >= 0 && Digimon.Care.CareMistakes > Requirement.MaximumCareMistakes) OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionTooManyMistakes", "Requires no more than {0} Care Mistakes."), FText::AsNumber(Requirement.MaximumCareMistakes));
    }
    if (Requirement.MoneyCost > 0)
    {
        SummaryParts.Add(FString::Printf(TEXT("Money %lld"), static_cast<long long>(Requirement.MoneyCost)));
        if (OutFailure.IsEmpty() && Money < Requirement.MoneyCost)
        {
            OutFailure = FText::Format(NSLOCTEXT("DMF", "DigivolutionNeedsMoney", "Requires {0} money."), FText::AsNumber(Requirement.MoneyCost));
        }
    }

    if (OutSummary)
    {
        *OutSummary = FText::FromString(FString::Join(SummaryParts, TEXT("  •  ")));
    }
    return OutFailure.IsEmpty();
}

TArray<FDMFDigivolutionEvaluation> UDMFPlayerDigimonComponent::GetDigivolutionOptions(const FGuid InstanceId) const
{
    TArray<FDMFDigivolutionEvaluation> Result;
    FDMFDigimonInstance Digimon;
    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Party;
    if (!GetOwnedDigimonByInstanceId(InstanceId, Digimon, Location))
    {
        return Result;
    }

    UDMFDigimonSpeciesData* SourceSpecies = ResolveSpeciesById(Digimon.SpeciesId);
    if (!SourceSpecies)
    {
        return Result;
    }

    Result.Reserve(SourceSpecies->Digivolutions.Num());
    for (const FDMFDigivolutionRequirement& Requirement : SourceSpecies->Digivolutions)
    {
        UDMFDigimonSpeciesData* Target = Requirement.TargetSpecies.LoadSynchronous();
        if (!Target)
        {
            continue;
        }
        FDMFDigivolutionEvaluation& Evaluation = Result.AddDefaulted_GetRef();
        Evaluation.TargetSpeciesId = Target->GetPrimaryAssetId();
        Evaluation.bEligible = EvaluateDigivolutionRequirement(Digimon, Location, Requirement, *SourceSpecies, *Target, Evaluation.FailureReason, &Evaluation.RequirementSummary);
    }
    return Result;
}

bool UDMFPlayerDigimonComponent::CanDigivolveOwnedDigimonTo(const FGuid InstanceId, const FPrimaryAssetId TargetSpeciesId, FText& OutFailureReason) const
{
    FDMFDigimonInstance Digimon;
    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Party;
    if (!GetOwnedDigimonByInstanceId(InstanceId, Digimon, Location))
    {
        OutFailureReason = NSLOCTEXT("DMF", "DigivolutionNotOwned", "That Digimon is not owned by this account.");
        return false;
    }
    UDMFDigimonSpeciesData* Source = ResolveSpeciesById(Digimon.SpeciesId);
    UDMFDigimonSpeciesData* Target = nullptr;
    const FDMFDigivolutionRequirement* Requirement = Source ? FindDigivolutionPath(*Source, TargetSpeciesId, Target) : nullptr;
    if (!Source || !Requirement || !Target)
    {
        OutFailureReason = NSLOCTEXT("DMF", "DigivolutionPathMissing", "That target form is not configured as a Digivolution path for this species.");
        return false;
    }
    if (bDigivolutionSequenceActive)
    {
        OutFailureReason = NSLOCTEXT("DMF", "DigivolutionAlreadyActive", "A Digivolution sequence is already in progress.");
        return false;
    }
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (Location == EDMFDigimonStorageLocation::Party && InstanceId == ActivePartnerInstanceId && IsValid(ActivePartnerActor) && Settings && Settings->bBlockDigivolutionDuringCombat)
    {
        if (ActivePartnerActor->CombatComponent && ActivePartnerActor->CombatComponent->GetCombatState() != EDMFCombatState::Idle)
        {
            OutFailureReason = NSLOCTEXT("DMF", "DigivolutionCombatBlocked", "Finish the current battle before Digivolving your active partner.");
            return false;
        }
    }
    return EvaluateDigivolutionRequirement(Digimon, Location, *Requirement, *Source, *Target, OutFailureReason, nullptr);
}

bool UDMFPlayerDigimonComponent::ApplyDigivolutionMutation(FDMFReplicatedDigimonEntry& Entry, const UDMFDigimonSpeciesData& SourceSpecies, const UDMFDigimonSpeciesData& TargetSpecies, const FDMFDigivolutionRequirement& Requirement)
{
    FDMFDigimonInstance& Digimon = Entry.Digimon;
    if (!Digimon.IsValid())
    {
        return false;
    }

    NormalizeDigivolutionProvenance(Digimon);
    const FDMFDigimonStats OldStats = Digimon.Stats;
    const int32 OldCurrentHP = Digimon.CurrentHP;
    const int32 OldCurrentSP = Digimon.CurrentSP;
    const float OldHPRatio = OldStats.MaxHP > 0 ? FMath::Clamp(static_cast<float>(OldCurrentHP) / static_cast<float>(OldStats.MaxHP), 0.0f, 1.0f) : 1.0f;
    const float OldSPRatio = OldStats.MaxSP > 0 ? FMath::Clamp(static_cast<float>(OldCurrentSP) / static_cast<float>(OldStats.MaxSP), 0.0f, 1.0f) : 1.0f;

    FDMFDigimonStats NewStats = TargetSpecies.BaseStats;
    NewStats.Level = FMath::Max(1, OldStats.Level);
    NewStats.Experience = FMath::Max<int64>(0, OldStats.Experience);
    NewStats.ABI = FMath::Max(0, OldStats.ABI);
    NewStats.CAM = FMath::Max(0, OldStats.CAM);

    if (Requirement.bPreserveStatInvestments)
    {
        NewStats.MaxHP = FMath::Max(1, TargetSpecies.BaseStats.MaxHP + FMath::Max(0, OldStats.MaxHP - SourceSpecies.BaseStats.MaxHP));
        NewStats.MaxSP = FMath::Max(0, TargetSpecies.BaseStats.MaxSP + FMath::Max(0, OldStats.MaxSP - SourceSpecies.BaseStats.MaxSP));
        NewStats.Strength = FMath::Max(0, TargetSpecies.BaseStats.Strength + FMath::Max(0, OldStats.Strength - SourceSpecies.BaseStats.Strength));
        NewStats.Intelligence = FMath::Max(0, TargetSpecies.BaseStats.Intelligence + FMath::Max(0, OldStats.Intelligence - SourceSpecies.BaseStats.Intelligence));
        NewStats.Defense = FMath::Max(0, TargetSpecies.BaseStats.Defense + FMath::Max(0, OldStats.Defense - SourceSpecies.BaseStats.Defense));
        NewStats.Speed = FMath::Max(0, TargetSpecies.BaseStats.Speed + FMath::Max(0, OldStats.Speed - SourceSpecies.BaseStats.Speed));
    }

    Digimon.DigivolutionHistory.AddUnique(SourceSpecies.GetPrimaryAssetId());
    Digimon.SpeciesId = TargetSpecies.GetPrimaryAssetId();
    Digimon.DigivolutionHistory.AddUnique(Digimon.SpeciesId);
    Digimon.Stats = NewStats;

    if (Requirement.bFullyRestoreVitals)
    {
        Digimon.CurrentHP = FMath::Max(1, NewStats.MaxHP);
        Digimon.CurrentSP = FMath::Max(0, NewStats.MaxSP);
    }
    else
    {
        Digimon.CurrentHP = OldCurrentHP > 0 ? FMath::Clamp(FMath::RoundToInt(static_cast<float>(NewStats.MaxHP) * OldHPRatio), 1, FMath::Max(1, NewStats.MaxHP)) : 0;
        Digimon.CurrentSP = FMath::Clamp(FMath::RoundToInt(static_cast<float>(NewStats.MaxSP) * OldSPRatio), 0, FMath::Max(0, NewStats.MaxSP));
    }

    if (Requirement.bReplaceEquippedAbilities)
    {
        Digimon.EquippedAbilityIds.Reset();
    }
    for (const FName AbilityId : TargetSpecies.StartingAbilityIds)
    {
        if (!AbilityId.IsNone()) Digimon.EquippedAbilityIds.AddUnique(AbilityId);
    }
    for (const TSoftObjectPtr<UDMFDigimonAbilityData>& SoftAbility : TargetSpecies.StartingAbilities)
    {
        if (UDMFDigimonAbilityData* Ability = SoftAbility.LoadSynchronous())
        {
            const FName Id = Ability->AbilityId.IsNone() ? Ability->GetPrimaryAssetId().PrimaryAssetName : Ability->AbilityId;
            Digimon.EquippedAbilityIds.AddUnique(Id);
        }
    }
    if (UDMFDigimonAbilityData* Basic = TargetSpecies.BasicAutoAttack.LoadSynchronous())
    {
        const FName Id = Basic->AbilityId.IsNone() ? Basic->GetPrimaryAssetId().PrimaryAssetName : Basic->AbilityId;
        Digimon.EquippedAbilityIds.AddUnique(Id);
    }
    return true;
}

void UDMFPlayerDigimonComponent::ServerDigivolveOwnedDigimon_Implementation(const FGuid InstanceId, const FPrimaryAssetId TargetSpeciesId)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    FDMFDigimonInstance Digimon;
    EDMFDigimonStorageLocation Location = EDMFDigimonStorageLocation::Party;
    if (!GetOwnedDigimonByInstanceId(InstanceId, Digimon, Location))
    {
        ClientDigivolutionResult(false, NSLOCTEXT("DMF", "DigivolutionNotOwnedServer", "That Digimon is not owned by this account."), InstanceId, FPrimaryAssetId(), TargetSpeciesId);
        return;
    }

    const FPrimaryAssetId PreviousSpeciesId = Digimon.SpeciesId;
    FText Failure;
    if (!CanDigivolveOwnedDigimonTo(InstanceId, TargetSpeciesId, Failure))
    {
        ClientDigivolutionResult(false, Failure, InstanceId, PreviousSpeciesId, TargetSpeciesId);
        return;
    }

    UDMFDigimonSpeciesData* Source = ResolveSpeciesById(PreviousSpeciesId);
    UDMFDigimonSpeciesData* Target = nullptr;
    const FDMFDigivolutionRequirement* Requirement = Source ? FindDigivolutionPath(*Source, TargetSpeciesId, Target) : nullptr;
    if (!Source || !Target || !Requirement)
    {
        ClientDigivolutionResult(false, NSLOCTEXT("DMF", "DigivolutionPathLost", "The configured Digivolution path could not be resolved."), InstanceId, PreviousSpeciesId, TargetSpeciesId);
        return;
    }

    const bool bWorldPresentation = Location == EDMFDigimonStorageLocation::Party && InstanceId == ActivePartnerInstanceId && IsValid(ActivePartnerActor);
    if (bWorldPresentation)
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        bDigivolutionSequenceActive = true;
        DigivolutionSequenceInstanceId = InstanceId;
        DigivolutionSequenceTargetSpeciesId = TargetSpeciesId;
        if (CommandTarget)
        {
            CommandTarget = nullptr;
            OnCommandTargetChanged.Broadcast(nullptr);
        }
        if (ActivePartnerActor->CombatComponent)
        {
            ActivePartnerActor->CombatComponent->SetAuthoritativeTarget(nullptr);
            ActivePartnerActor->ConfigureCombatAutomation(false, 0.0f, 0.0f, nullptr);
        }
        ClientDigivolutionSequenceStarted(InstanceId, PreviousSpeciesId, TargetSpeciesId);
        ActivePartnerActor->MulticastPlayDigivolutionCue(TargetSpeciesId);
        const float Duration = Requirement->PresentationDurationSeconds > KINDA_SMALL_NUMBER
            ? Requirement->PresentationDurationSeconds
            : (Settings ? Settings->DigivolutionPresentationDurationSeconds : 3.0f);
        GetOwner()->ForceNetUpdate();
        GetWorld()->GetTimerManager().SetTimer(DigivolutionSequenceTimer, this, &UDMFPlayerDigimonComponent::CompleteDigivolutionSequence, FMath::Max(0.25f, Duration), false);
        return;
    }

    FDMFReplicatedDigimonEntry* Entry = Location == EDMFDigimonStorageLocation::Party ? FindInventoryEntry(InstanceId) : FindBankEntry(InstanceId);
    if (!Entry || !ApplyDigivolutionMutation(*Entry, *Source, *Target, *Requirement))
    {
        ClientDigivolutionResult(false, NSLOCTEXT("DMF", "DigivolutionMutationFailed", "The Digivolution could not be applied."), InstanceId, PreviousSpeciesId, TargetSpeciesId);
        return;
    }
    Money = FMath::Max<int64>(0, Money - FMath::Max<int64>(0, Requirement->MoneyCost));
    if (Location == EDMFDigimonStorageLocation::Party)
    {
        ReplicatedInventory.MarkItemDirty(*Entry);
        ReplicatedInventory.MarkArrayDirty();
        OnDigimonInventoryChanged.Broadcast();
    }
    else
    {
        ReplicatedBank.MarkItemDirty(*Entry);
        ReplicatedBank.MarkArrayDirty();
        OnDigimonBankChanged.Broadcast();
    }
    OnMoneyChanged.Broadcast(Money);
    PersistOwningPlayer();
    ClientDigivolutionResult(true, NSLOCTEXT("DMF", "DigivolutionCompleteStored", "Digivolution complete. The evolved form has been saved to your account."), InstanceId, PreviousSpeciesId, TargetSpeciesId);
}

void UDMFPlayerDigimonComponent::CompleteDigivolutionSequence()
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !bDigivolutionSequenceActive)
    {
        return;
    }

    const FGuid InstanceId = DigivolutionSequenceInstanceId;
    const FPrimaryAssetId TargetSpeciesId = DigivolutionSequenceTargetSpeciesId;
    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(InstanceId);
    const FPrimaryAssetId PreviousSpeciesId = Entry ? Entry->Digimon.SpeciesId : FPrimaryAssetId();
    UDMFDigimonSpeciesData* Source = Entry ? ResolveSpeciesById(Entry->Digimon.SpeciesId) : nullptr;
    UDMFDigimonSpeciesData* Target = nullptr;
    const FDMFDigivolutionRequirement* Requirement = Source ? FindDigivolutionPath(*Source, TargetSpeciesId, Target) : nullptr;
    FText Failure;
    const bool bStillEligible = Entry && Source && Target && Requirement
        && EvaluateDigivolutionRequirement(Entry->Digimon, EDMFDigimonStorageLocation::Party, *Requirement, *Source, *Target, Failure, nullptr);

    bool bSuccess = false;
    if (bStillEligible && ApplyDigivolutionMutation(*Entry, *Source, *Target, *Requirement))
    {
        Money = FMath::Max<int64>(0, Money - FMath::Max<int64>(0, Requirement->MoneyCost));
        ReplicatedInventory.MarkItemDirty(*Entry);
        ReplicatedInventory.MarkArrayDirty();
        OnDigimonInventoryChanged.Broadcast();
        OnMoneyChanged.Broadcast(Money);
        PersistOwningPlayer();
        bSuccess = true;
    }

    bDigivolutionSequenceActive = false;
    DigivolutionSequenceInstanceId.Invalidate();
    DigivolutionSequenceTargetSpeciesId = FPrimaryAssetId();
    GetWorld()->GetTimerManager().ClearTimer(DigivolutionSequenceTimer);
    if (GetOwner()) GetOwner()->ForceNetUpdate();

    if (bSuccess)
    {
        ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
        APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
        if (PC && PC->GetPawn())
        {
            SpawnOrRefreshActivePartner(PC->GetPawn());
        }
        ClientDigivolutionResult(true, NSLOCTEXT("DMF", "DigivolutionCompleteWorld", "Digivolution complete. Your active partner has transformed."), InstanceId, PreviousSpeciesId, TargetSpeciesId);
    }
    else
    {
        ClientDigivolutionResult(false, Failure.IsEmpty() ? NSLOCTEXT("DMF", "DigivolutionInterrupted", "Digivolution was interrupted before the transformation could be committed.") : Failure, InstanceId, PreviousSpeciesId, TargetSpeciesId);
    }
}

void UDMFPlayerDigimonComponent::ClientDigivolutionSequenceStarted_Implementation(const FGuid DigimonInstanceId, const FPrimaryAssetId PreviousSpeciesId, const FPrimaryAssetId TargetSpeciesId)
{
    OnDigivolutionSequenceStarted.Broadcast(DigimonInstanceId, PreviousSpeciesId, TargetSpeciesId);
}

void UDMFPlayerDigimonComponent::ClientDigivolutionResult_Implementation(const bool bSuccess, const FText& Message, const FGuid DigimonInstanceId, const FPrimaryAssetId PreviousSpeciesId, const FPrimaryAssetId NewSpeciesId)
{
    OnDigivolutionResult.Broadcast(bSuccess, Message, DigimonInstanceId, PreviousSpeciesId, NewSpeciesId);
}

FDMFDigimonInstance UDMFPlayerDigimonComponent::BuildStarterInstance(const UDMFDigimonSpeciesData& Species) const
{
    FDMFDigimonInstance Result;
    Result.InstanceId = FGuid::NewGuid();
    Result.SpeciesId = Species.GetPrimaryAssetId();
    Result.Stats = Species.BaseStats;
    Result.Stats.Level = FMath::Max(1, Species.StartingLevel);
    Result.CurrentHP = Result.Stats.MaxHP;
    Result.CurrentSP = Result.Stats.MaxSP;
    Result.EquippedAbilityIds = Species.StartingAbilityIds;
    for (const TSoftObjectPtr<UDMFDigimonAbilityData>& SoftAbility : Species.StartingAbilities)
    {
        if (UDMFDigimonAbilityData* Ability = SoftAbility.LoadSynchronous())
        {
            const FName Id = Ability->AbilityId.IsNone() ? Ability->GetPrimaryAssetId().PrimaryAssetName : Ability->AbilityId;
            Result.EquippedAbilityIds.AddUnique(Id);
        }
    }
    if (UDMFDigimonAbilityData* Basic = Species.BasicAutoAttack.LoadSynchronous())
    {
        const FName BasicId = Basic->AbilityId.IsNone() ? Basic->GetPrimaryAssetId().PrimaryAssetName : Basic->AbilityId;
        Result.EquippedAbilityIds.AddUnique(BasicId);
    }
    Result.UnspentAttributePoints = 0;
    Result.Care.Hunger = FMath::Clamp(Species.StartingHungerPercent, 0.0f, 100.0f);
    Result.Care.Fullness = Result.Care.Hunger;
    Result.Care.LastCareUpdateUtcTicks = FDateTime::UtcNow().GetTicks();
    Result.OriginSpeciesId = Result.SpeciesId;
    Result.DigivolutionHistory.AddUnique(Result.SpeciesId);
    Result.bStarterPartner = true;
    return Result;
}

FDMFDigimonInstance UDMFPlayerDigimonComponent::BuildMaterializedInstance(const UDMFDigimonSpeciesData& Species) const
{
    FDMFDigimonInstance Result = BuildStarterInstance(Species);
    Result.bStarterPartner = false;
    return Result;
}

float UDMFPlayerDigimonComponent::GetScanPercent(const FPrimaryAssetId SpeciesId) const
{
    for (const FDMFScanDataEntry& Entry : ReplicatedScanData)
    {
        if (Entry.SpeciesId == SpeciesId)
        {
            return FMath::Max(0.0f, Entry.ScanPercent);
        }
    }
    return 0.0f;
}

bool UDMFPlayerDigimonComponent::IsSpeciesReadyToMaterialize(const FPrimaryAssetId SpeciesId) const
{
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableScanAndMaterialization)
    {
        return false;
    }

    const UDMFDigimonSpeciesData* Species = ResolveSpeciesById(SpeciesId);
    if (!Species || !Species->bMaterializationEnabled)
    {
        return false;
    }

    return GetScanPercent(SpeciesId) + KINDA_SMALL_NUMBER >= FMath::Max(1.0f, Species->MaterializationRequiredScanPercent);
}

int32 UDMFPlayerDigimonComponent::GetOwnedSpeciesCount(const FPrimaryAssetId SpeciesId) const
{
    int32 Count = 0;
    for (const FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        Count += Entry.Digimon.SpeciesId == SpeciesId ? 1 : 0;
    }
    for (const FDMFReplicatedDigimonEntry& Entry : ReplicatedBank.Items)
    {
        Count += Entry.Digimon.SpeciesId == SpeciesId ? 1 : 0;
    }
    return Count;
}

void UDMFPlayerDigimonComponent::BroadcastScanState(const FPrimaryAssetId SpeciesId)
{
    OnScanDataChanged.Broadcast(SpeciesId, GetScanPercent(SpeciesId), IsSpeciesReadyToMaterialize(SpeciesId));
}

bool UDMFPlayerDigimonComponent::AwardScanDataForVictory(const UDMFDigimonSpeciesData& Species, float& OutAddedPercent, float& OutNewPercent, bool& bOutReady)
{
    OutAddedPercent = 0.0f;
    OutNewPercent = GetScanPercent(Species.GetPrimaryAssetId());
    bOutReady = false;

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableScanAndMaterialization || !Species.bScanDataEnabled)
    {
        return false;
    }

    const float Reward = FMath::Max(0.0f, Species.BattleScanPercentReward);
    if (Reward <= KINDA_SMALL_NUMBER)
    {
        return false;
    }

    const FPrimaryAssetId SpeciesId = Species.GetPrimaryAssetId();
    const float Cap = FMath::Max(1.0f, Species.ScanPercentCap);
    FDMFScanDataEntry* ExistingEntry = ReplicatedScanData.FindByPredicate([&](const FDMFScanDataEntry& Entry)
    {
        return Entry.SpeciesId == SpeciesId;
    });

    const float OldPercent = ExistingEntry ? FMath::Clamp(ExistingEntry->ScanPercent, 0.0f, Cap) : 0.0f;
    const float NewPercent = FMath::Clamp(OldPercent + Reward, 0.0f, Cap);
    OutAddedPercent = FMath::Max(0.0f, NewPercent - OldPercent);
    OutNewPercent = NewPercent;

    if (OutAddedPercent <= KINDA_SMALL_NUMBER)
    {
        bOutReady = IsSpeciesReadyToMaterialize(SpeciesId);
        return false;
    }

    if (!ExistingEntry)
    {
        FDMFScanDataEntry& NewEntry = ReplicatedScanData.AddDefaulted_GetRef();
        NewEntry.SpeciesId = SpeciesId;
        NewEntry.ScanPercent = NewPercent;
    }
    else
    {
        ExistingEntry->ScanPercent = NewPercent;
    }

    bOutReady = NewPercent + KINDA_SMALL_NUMBER >= FMath::Max(1.0f, Species.MaterializationRequiredScanPercent);
    BroadcastScanState(SpeciesId);
    return true;
}

void UDMFPlayerDigimonComponent::ServerMaterializeDigimon_Implementation(const FPrimaryAssetId SpeciesId)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableScanAndMaterialization)
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "MaterializationSystemDisabled", "Scan & Materialization is disabled."), SpeciesId, FGuid());
        return;
    }

    UDMFDigimonSpeciesData* Species = ResolveSpeciesById(SpeciesId);
    if (!Species || !Species->bScanDataEnabled || !Species->bMaterializationEnabled)
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "SpeciesCannotMaterialize", "This species cannot be materialized."), SpeciesId, FGuid());
        return;
    }

    const float Required = FMath::Max(1.0f, Species->MaterializationRequiredScanPercent);
    if (GetScanPercent(SpeciesId) + KINDA_SMALL_NUMBER < Required)
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "NotEnoughScanData", "Not enough Scan Data has been collected yet."), SpeciesId, FGuid());
        return;
    }

    const bool bPartyHasRoom = ReplicatedInventory.Items.Num() < GetPartyCapacity();
    const bool bBankHasRoom = ReplicatedBank.Items.Num() < GetBankCapacity();
    if (!bPartyHasRoom && !bBankHasRoom)
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "MaterializationStorageFull", "Your Party and Digimon Bank are both full. Free a storage slot before materializing."), SpeciesId, FGuid());
        return;
    }

    UClass* PartnerClass = Species->WorldActorClass.LoadSynchronous();
    if (!PartnerClass || !PartnerClass->IsChildOf(ADMFDigimonCharacter::StaticClass()) || PartnerClass->IsChildOf(ADMFWildDigimonCharacter::StaticClass()))
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "MaterializationInvalidPartnerClass", "Species World Actor Class must be a partner DMFDigimonCharacter Blueprint, not a Wild Digimon class."), SpeciesId, FGuid());
        return;
    }

    FDMFScanDataEntry* ScanEntry = ReplicatedScanData.FindByPredicate([&](const FDMFScanDataEntry& Entry)
    {
        return Entry.SpeciesId == SpeciesId;
    });
    if (!ScanEntry)
    {
        ClientMaterializationResult(false, NSLOCTEXT("DMF", "MaterializationScanRecordMissing", "Scan Data record is unavailable."), SpeciesId, FGuid());
        return;
    }

    const FDMFDigimonInstance NewDigimon = BuildMaterializedInstance(*Species);
    if (bPartyHasRoom)
    {
        FDMFReplicatedDigimonEntry& NewPartyEntry = ReplicatedInventory.Items.AddDefaulted_GetRef();
        NewPartyEntry.Digimon = NewDigimon;
        ReplicatedInventory.MarkItemDirty(NewPartyEntry);
        ReplicatedInventory.MarkArrayDirty();
        OnDigimonInventoryChanged.Broadcast();
    }
    else
    {
        FDMFReplicatedDigimonEntry& NewBankEntry = ReplicatedBank.Items.AddDefaulted_GetRef();
        NewBankEntry.Digimon = NewDigimon;
        ReplicatedBank.MarkItemDirty(NewBankEntry);
        ReplicatedBank.MarkArrayDirty();
        OnDigimonBankChanged.Broadcast();
    }

    ScanEntry->ScanPercent = FMath::Max(0.0f, ScanEntry->ScanPercent - Required);
    BroadcastScanState(SpeciesId);
    PersistOwningPlayer();
    ClientMaterializationResult(true,
        bPartyHasRoom ? NSLOCTEXT("DMF", "MaterializationSucceededParty", "Materialization complete. The new Digimon has been added to your Party.")
                      : NSLOCTEXT("DMF", "MaterializationSucceededBank", "Materialization complete. Your Party was full, so the new Digimon was sent to the Digimon Bank."),
        SpeciesId, NewDigimon.InstanceId);
}

void UDMFPlayerDigimonComponent::ClientScanDataRewardGranted_Implementation(const FPrimaryAssetId SpeciesId, const float AddedPercent, const float NewPercent, const bool bMaterializationReady)
{
    OnScanDataRewardGranted.Broadcast(SpeciesId, AddedPercent, NewPercent, bMaterializationReady);
    OnScanDataChanged.Broadcast(SpeciesId, NewPercent, bMaterializationReady);
}

void UDMFPlayerDigimonComponent::ClientMaterializationResult_Implementation(const bool bSuccess, const FText& Message, const FPrimaryAssetId SpeciesId, const FGuid NewDigimonInstanceId)
{
    OnMaterializationResult.Broadcast(bSuccess, Message, SpeciesId, NewDigimonInstanceId);
}

void UDMFPlayerDigimonComponent::ServerSelectStarter_Implementation(const FPrimaryAssetId StarterSpeciesId)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    if (!bStarterSelectionRequired)
    {
        ClientStarterSelectionResult(false, NSLOCTEXT("DMF", "StarterAlreadySelected", "Starter selection has already been completed for this account."), ActivePartnerInstanceId);
        return;
    }

    if (ReplicatedInventory.Items.Num() >= GetPartyCapacity())
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Starter selection rejected: Party is full."));
        ClientStarterSelectionResult(false, NSLOCTEXT("DMF", "StarterPartyFull", "Starter selection failed because the Party is full."), FGuid());
        return;
    }

    UDMFDigimonSpeciesData* Species = nullptr;
    if (!ResolveStarterSpecies(StarterSpeciesId, Species) || !Species)
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Starter selection rejected: species is not in the configured starter roster."));
        ClientStarterSelectionResult(false, NSLOCTEXT("DMF", "StarterInvalidSpecies", "That Digimon is not an enabled starter choice."), FGuid());
        return;
    }

    const FDMFDigimonInstance NewStarter = BuildStarterInstance(*Species);
    FDMFReplicatedDigimonEntry& NewEntry = ReplicatedInventory.Items.AddDefaulted_GetRef();
    NewEntry.Digimon = NewStarter;
    ReplicatedInventory.MarkItemDirty(NewEntry);

    ActivePartnerInstanceId = NewStarter.InstanceId;
    bStarterSelectionRequired = false;

    PersistOwningPlayer();

    if (ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner()))
    {
        if (APlayerController* PC = Cast<APlayerController>(PS->GetOwner()))
        {
            if (ADMFMMOGameMode* MMOGameMode = GetWorld() ? GetWorld()->GetAuthGameMode<ADMFMMOGameMode>() : nullptr)
            {
                MMOGameMode->EnsureFrameworkPlayerAvatar(PC);
            }
            SpawnOrRefreshActivePartner(PC->GetPawn());
        }
    }

    OnDigimonInventoryChanged.Broadcast();
    OnStarterRequirementChanged.Broadcast(false);
    OnStarterSelectionFinished.Broadcast(NewStarter.InstanceId);
    ClientStarterSelectionResult(true, NSLOCTEXT("DMF", "StarterGranted", "Partner Digimon confirmed and saved."), NewStarter.InstanceId);
}

void UDMFPlayerDigimonComponent::ClientStarterSelectionResult_Implementation(bool bSuccess, const FText& Message, FGuid PartnerInstanceId)
{
    OnStarterSelectionResult.Broadcast(bSuccess, Message, PartnerInstanceId);
}

bool UDMFPlayerDigimonComponent::ResetStarterOnboarding(const bool bRemoveStarterDigimon)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return false;
    }

    bool bChangedInventory = false;
    bool bChangedBank = false;
    if (bRemoveStarterDigimon)
    {
        for (int32 Index = ReplicatedInventory.Items.Num() - 1; Index >= 0; --Index)
        {
            if (ReplicatedInventory.Items[Index].Digimon.bStarterPartner)
            {
                ReplicatedInventory.Items.RemoveAt(Index);
                bChangedInventory = true;
            }
        }

        for (int32 Index = ReplicatedBank.Items.Num() - 1; Index >= 0; --Index)
        {
            if (ReplicatedBank.Items[Index].Digimon.bStarterPartner)
            {
                ReplicatedBank.Items.RemoveAt(Index);
                bChangedBank = true;
            }
        }

        if (bChangedInventory)
        {
            ReplicatedInventory.MarkArrayDirty();
        }
        if (bChangedBank)
        {
            ReplicatedBank.MarkArrayDirty();
        }
    }

    if (IsValid(ActivePartnerActor))
    {
        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
    }

    ActivePartnerInstanceId.Invalidate();
    CommandTarget = nullptr;
    OnCommandTargetChanged.Broadcast(nullptr);
    bStarterSelectionRequired = true;
    PersistOwningPlayer();

    if (bChangedInventory)
    {
        OnDigimonInventoryChanged.Broadcast();
    }
    if (bChangedBank)
    {
        OnDigimonBankChanged.Broadcast();
    }
    OnStarterRequirementChanged.Broadcast(true);
    return true;
}

void UDMFPlayerDigimonComponent::SynchronizeActivePartnerRuntimeForPersistence()
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !ActivePartnerInstanceId.IsValid())
    {
        return;
    }

    ADMFDigimonCharacter* Partner = ActivePartnerActor.Get();
    if (!IsValid(Partner) || !Partner->CombatComponent)
    {
        return;
    }

    if (FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(ActivePartnerInstanceId))
    {
        const int32 LiveHP = Partner->CombatComponent->GetCurrentHP();
        const int32 LiveSP = Partner->CombatComponent->GetCurrentSP();
        if (Entry->Digimon.CurrentHP != LiveHP || Entry->Digimon.CurrentSP != LiveSP)
        {
            Entry->Digimon.CurrentHP = LiveHP;
            Entry->Digimon.CurrentSP = LiveSP;
            ReplicatedInventory.MarkItemDirty(*Entry);
        }
    }
}

void UDMFPlayerDigimonComponent::FinalizeForOwnerDisconnect(const bool bPersistenceCommitted)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }

    // Once the canonical pre-teardown account transaction succeeds, block every later EndPlay/autosave path
    // from writing over it. If it failed, leave the flag false so EndPlay gets one final guarded retry.
    if (bPersistenceCommitted)
    {
        bDisconnectPersistenceFinalized = true;
    }

    CommandTarget = nullptr;

    if (IsValid(ActivePartnerActor))
    {
        if (ActivePartnerActor->CombatComponent)
        {
            ActivePartnerActor->CombatComponent->OnVitalsChanged.RemoveDynamic(this, &UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged);
            ActivePartnerActor->CombatComponent->ForceAuthoritativeDisengage();
        }

        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
    }

    // A feeding prop is also owned by the player session rather than the persistent Digimon record.
    DestroyActiveCareMeat();
}

void UDMFPlayerDigimonComponent::PersistOwningPlayer()
{
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    if (!PS || !PS->HasAuthority() || !bAuthoritativeAccountStateInitialized || bDisconnectPersistenceFinalized)
    {
        return;
    }

    UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    if (!Persistence)
    {
        return;
    }

    FDMFAccountRecord Record;
    if (!Persistence->GetAccount(PS->GetAuthenticatedUsername(), Record))
    {
        return;
    }

    // Keep the complete owned collection authoritative in server UTC without turning every inactive
    // Digimon into a periodic replication source. Inactive Care values are advanced when the normal
    // account autosave runs; only the active partner is pushed to the owner immediately for live UI.
    // The project-level master switch freezes all Care progression, including offline/UTC decay.
    const UDMFFrameworkSettings* CareSettings = GetDefault<UDMFFrameworkSettings>();
    if (CareSettings && CareSettings->bEnableCareSystem)
    {
        const int64 NowUtcTicks = FDateTime::UtcNow().GetTicks();
        for (FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
        {
            UDMFDigimonSpeciesData* Species = ResolveSpeciesById(Entry.Digimon.SpeciesId);
            if (!Species || !Species->bCareEnabled)
            {
                continue;
            }

            const int64 PreviousCareTicks = Entry.Digimon.Care.LastCareUpdateUtcTicks;
            const bool bCareChanged = NormalizeAndApplyCareDecay(Entry, *Species, NowUtcTicks);
            if (Entry.Digimon.InstanceId == ActivePartnerInstanceId && (bCareChanged || PreviousCareTicks <= 0))
            {
                ReplicatedInventory.MarkItemDirty(Entry);
                BroadcastCareState(Entry);
            }
        }
        for (FDMFReplicatedDigimonEntry& Entry : ReplicatedBank.Items)
        {
            if (UDMFDigimonSpeciesData* Species = ResolveSpeciesById(Entry.Digimon.SpeciesId))
            {
                if (Species->bCareEnabled)
                {
                    NormalizeAndApplyCareDecay(Entry, *Species, NowUtcTicks);
                }
            }
        }
    }

    ApplyToAccountRecord(Record);
    if (PS->AvatarComponent)
    {
        // The existing account autosave is the single authoritative checkpoint transaction for both
        // private Digimon state and the server-owned player world transform.
        PS->AvatarComponent->ApplyToAccountRecord(Record);
        PS->AvatarComponent->ApplyCurrentWorldLocationToAccountRecord(Record);
    }
    FString Error;
    if (!Persistence->SaveAccount(Record, Error))
    {
        UE_LOG(LogDigimonMMOFramework, Error, TEXT("Failed to persist player '%s': %s"), *PS->GetAuthenticatedUsername(), *Error);
    }
}

ADMFDigimonCharacter* UDMFPlayerDigimonComponent::SpawnOrRefreshActivePartner(APawn* PlayerPawn)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !PlayerPawn || !ActivePartnerInstanceId.IsValid())
    {
        return nullptr;
    }

    FDMFDigimonInstance Instance;
    if (!GetDigimonByInstanceId(ActivePartnerInstanceId, Instance))
    {
        return nullptr;
    }

    if (Instance.CurrentHP <= 0)
    {
        UE_LOG(LogDigimonMMOFramework, Log, TEXT("Partner '%s' is defeated and will not be summoned until healed."), *ActivePartnerInstanceId.ToString());
        return nullptr;
    }

    UDMFDigimonSpeciesData* Species = ResolveSpeciesById(Instance.SpeciesId);
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();

    if (!Species)
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Cannot spawn partner: species asset '%s' is not currently resolvable."), *Instance.SpeciesId.ToString());
        return nullptr;
    }

    UClass* SpawnClass = Species->WorldActorClass.LoadSynchronous();
    if (!SpawnClass || !SpawnClass->IsChildOf(ADMFDigimonCharacter::StaticClass()))
    {
        UE_LOG(LogDigimonMMOFramework, Warning, TEXT("Cannot spawn partner '%s': WorldActorClass must derive from ADMFDigimonCharacter."), *Species->GetName());
        return nullptr;
    }

    if (IsValid(ActivePartnerActor))
    {
        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
    }

    const FVector Offset = Settings ? Settings->PartnerSpawnOffset : FVector(150.0, 120.0, 0.0);
    const FVector SpawnLocation = PlayerPawn->GetActorTransform().TransformPosition(Offset);
    const FRotator SpawnRotation = PlayerPawn->GetActorRotation();

    FActorSpawnParameters Params;
    Params.Owner = GetOwner();
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    ActivePartnerActor = GetWorld()->SpawnActor<ADMFDigimonCharacter>(SpawnClass, SpawnLocation, SpawnRotation, Params);
    if (ActivePartnerActor)
    {
        ActivePartnerActor->InitializeFromInstance(Instance, Cast<ADMFPlayerState>(GetOwner()));
        const FName PlayerTeamId = Settings ? Settings->PlayerCombatTeamId : FName(TEXT("Players"));
        ActivePartnerActor->SetCombatTeamId(PlayerTeamId);
        ActivePartnerActor->ConfigureCombatAutomation(
            Settings ? Settings->bPlayerPartnerAutoBattle : false,
            Settings ? Settings->PartnerAggroRange : 1200.0f,
            Settings ? Settings->PartnerLeashRange : 2500.0f,
            PlayerPawn);
        if (ActivePartnerActor->CombatComponent)
        {
            ActivePartnerActor->CombatComponent->ConfigureDamageTuning(
                Settings ? Settings->PlayerPartnerOutgoingDamageMultiplier : 1.50f,
                Settings ? Settings->PlayerPartnerIncomingDamageMultiplier : 0.50f);
            ActivePartnerActor->CombatComponent->OnVitalsChanged.AddDynamic(this, &UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged);
        }
    }

    // A Digimon whose persisted waste timer expired while recalled/offline poops as soon as it is safely back in the world.
    CareTick();
    return ActivePartnerActor;
}

void UDMFPlayerDigimonComponent::ServerSetActivePartner_Implementation(const FGuid InstanceId, const bool bSummonNow)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !InstanceId.IsValid() || bCareSequenceActive || bDigivolutionSequenceActive)
    {
        return;
    }

    FDMFDigimonInstance Instance;
    if (!GetDigimonByInstanceId(InstanceId, Instance) || !Instance.IsValid())
    {
        ClientPartnerActionResult(false, NSLOCTEXT("DMF", "PartnerNotOwned", "That Digimon is not available in your Party."), InstanceId);
        return;
    }

    if (bSummonNow && Instance.CurrentHP <= 0)
    {
        ClientPartnerActionResult(false, NSLOCTEXT("DMF", "PartnerDefeated", "That Digimon is defeated. Heal it before summoning."), InstanceId);
        return;
    }

    if (InstanceId != ActivePartnerInstanceId)
    {
        FText PartyFailure;
        if (!IsPartyMutationAllowed(PartyFailure))
        {
            ClientPartnerActionResult(false, PartyFailure, InstanceId);
            return;
        }
    }

    ActivePartnerInstanceId = InstanceId;

    // Inactive Digimon do not generate periodic owner replication. Bring the newly selected partner
    // fully current before it becomes the Care UI source, then replicate that one authoritative item.
    // When the global Care switch is disabled, selection must not advance Hunger behind the disabled UI.
    const UDMFFrameworkSettings* CareSettings = GetDefault<UDMFFrameworkSettings>();
    if (CareSettings && CareSettings->bEnableCareSystem)
    {
        if (FDMFReplicatedDigimonEntry* SelectedEntry = FindInventoryEntry(InstanceId))
        {
            if (UDMFDigimonSpeciesData* SelectedSpecies = ResolveSpeciesById(SelectedEntry->Digimon.SpeciesId))
            {
                const int64 PreviousCareTicks = SelectedEntry->Digimon.Care.LastCareUpdateUtcTicks;
                const bool bCareChanged = NormalizeAndApplyCareDecay(*SelectedEntry, *SelectedSpecies, FDateTime::UtcNow().GetTicks());
                if (bCareChanged || PreviousCareTicks <= 0)
                {
                    ReplicatedInventory.MarkItemDirty(*SelectedEntry);
                }
                BroadcastCareState(*SelectedEntry);
            }
        }
    }

    CommandTarget = nullptr;
    OnCommandTargetChanged.Broadcast(nullptr);
    PersistOwningPlayer();
    OnDigimonInventoryChanged.Broadcast();

    ADMFDigimonCharacter* Spawned = ActivePartnerActor.Get();
    if (!bSummonNow && IsValid(ActivePartnerActor))
    {
        if (ActivePartnerActor->CombatComponent)
        {
            ActivePartnerActor->CombatComponent->OnVitalsChanged.RemoveDynamic(this, &UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged);
        }
        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
        Spawned = nullptr;
    }
    if (bSummonNow)
    {
        ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
        APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
        Spawned = PC ? SpawnOrRefreshActivePartner(PC->GetPawn()) : nullptr;
        if (!Spawned)
        {
            ClientPartnerActionResult(false, NSLOCTEXT("DMF", "PartnerSpawnFailed", "The partner could not be summoned at the current location."), InstanceId);
            return;
        }
    }

    ClientPartnerActionResult(true,
        bSummonNow ? NSLOCTEXT("DMF", "PartnerSummoned", "Partner Digimon summoned.") : NSLOCTEXT("DMF", "PartnerSelected", "Active partner selected."),
        InstanceId);
}

void UDMFPlayerDigimonComponent::ServerRecallActivePartner_Implementation()
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || bCareSequenceActive || bDigivolutionSequenceActive)
    {
        return;
    }

    if (IsValid(ActivePartnerActor))
    {
        if (ActivePartnerActor->CombatComponent)
        {
            ActivePartnerActor->CombatComponent->OnVitalsChanged.RemoveDynamic(this, &UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged);
        }
        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
    }

    CommandTarget = nullptr;
    OnCommandTargetChanged.Broadcast(nullptr);
    OnDigimonInventoryChanged.Broadcast();
    ClientPartnerActionResult(true, NSLOCTEXT("DMF", "PartnerRecalled", "Partner Digimon recalled."), ActivePartnerInstanceId);
}

void UDMFPlayerDigimonComponent::ServerSetActivePartnerAutoBattle_Implementation(const bool bEnabled)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !ActivePartnerActor || bCareSequenceActive || bDigivolutionSequenceActive)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bProjectAllowsAutoBattle = Settings && Settings->bPlayerPartnerAutoBattle;
    const bool bEffectiveEnabled = bEnabled && bProjectAllowsAutoBattle;
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
    ActivePartnerActor->ConfigureCombatAutomation(
        bEffectiveEnabled,
        Settings ? Settings->PartnerAggroRange : 1200.0f,
        Settings ? Settings->PartnerLeashRange : 2500.0f,
        PC ? PC->GetPawn() : nullptr);
}

void UDMFPlayerDigimonComponent::ClientPartnerActionResult_Implementation(const bool bSuccess, const FText& Message, const FGuid PartnerInstanceId)
{
    OnPartnerActionResult.Broadcast(bSuccess, Message, PartnerInstanceId);
}

void UDMFPlayerDigimonComponent::ClientDigimonStorageActionResult_Implementation(const bool bSuccess, const FText& Message, const FGuid DigimonInstanceId, const EDMFDigimonStorageLocation NewLocation)
{
    OnDigimonStorageActionResult.Broadcast(bSuccess, Message, DigimonInstanceId, NewLocation);
}

bool UDMFPlayerDigimonComponent::IsPartyMutationAllowed(FText& OutFailure) const
{
    OutFailure = FText::GetEmpty();
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        OutFailure = NSLOCTEXT("DMF", "PartyBankAuthorityRequired", "Party and Bank changes must be validated by the server.");
        return false;
    }
    if (bCareSequenceActive)
    {
        OutFailure = NSLOCTEXT("DMF", "PartyBankCareBusy", "Wait for the current Care sequence to finish before changing the Party.");
        return false;
    }
    if (bDigivolutionSequenceActive)
    {
        OutFailure = NSLOCTEXT("DMF", "PartyBankDigivolutionBusy", "Wait for the active Digivolution sequence to finish before changing the Party.");
        return false;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if ((!Settings || !Settings->bAllowPartySwitchingDuringCombat) && IsValid(ActivePartnerActor) && ActivePartnerActor->CombatComponent)
    {
        const EDMFCombatState State = ActivePartnerActor->CombatComponent->GetCombatState();
        if (State == EDMFCombatState::Chasing || State == EDMFCombatState::Attacking || State == EDMFCombatState::Recovering)
        {
            OutFailure = NSLOCTEXT("DMF", "PartyBankCombatLocked", "Party and Bank changes are locked while your active partner is in combat.");
            return false;
        }
    }
    return true;
}

void UDMFPlayerDigimonComponent::MarkPartyAndBankChanged(const bool bPartyChanged, const bool bBankChanged)
{
    if (bPartyChanged)
    {
        ReplicatedInventory.MarkArrayDirty();
        OnDigimonInventoryChanged.Broadcast();
    }
    if (bBankChanged)
    {
        ReplicatedBank.MarkArrayDirty();
        OnDigimonBankChanged.Broadcast();
    }
}

void UDMFPlayerDigimonComponent::ReconcileActivePartnerAfterPartyMutation(const FGuid PreviousActivePartnerId, const bool bWasSummoned)
{
    const bool bActiveChanged = PreviousActivePartnerId != ActivePartnerInstanceId;
    if (!FindInventoryEntry(ActivePartnerInstanceId))
    {
        ActivePartnerInstanceId.Invalidate();
        for (const FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
        {
            if (Entry.Digimon.IsValid() && Entry.Digimon.CurrentHP > 0)
            {
                ActivePartnerInstanceId = Entry.Digimon.InstanceId;
                break;
            }
        }
        if (!ActivePartnerInstanceId.IsValid() && !ReplicatedInventory.Items.IsEmpty())
        {
            ActivePartnerInstanceId = ReplicatedInventory.Items[0].Digimon.InstanceId;
        }
    }

    const bool bNeedsActorRefresh = bActiveChanged || (IsValid(ActivePartnerActor) && ActivePartnerActor->DigimonInstanceId != ActivePartnerInstanceId);
    if (bNeedsActorRefresh && IsValid(ActivePartnerActor))
    {
        if (ActivePartnerActor->CombatComponent)
        {
            ActivePartnerActor->CombatComponent->OnVitalsChanged.RemoveDynamic(this, &UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged);
        }
        ActivePartnerActor->Destroy();
        ActivePartnerActor = nullptr;
    }

    CommandTarget = nullptr;
    OnCommandTargetChanged.Broadcast(nullptr);

    if (bWasSummoned && ActivePartnerInstanceId.IsValid() && (!IsValid(ActivePartnerActor) || bNeedsActorRefresh))
    {
        ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
        APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
        if (PC)
        {
            SpawnOrRefreshActivePartner(PC->GetPawn());
        }
    }
}

void UDMFPlayerDigimonComponent::ServerMovePartyDigimonToBank_Implementation(const FGuid InstanceId)
{
    FText Failure;
    if (!InstanceId.IsValid() || !IsPartyMutationAllowed(Failure))
    {
        ClientDigimonStorageActionResult(false, Failure.IsEmpty() ? NSLOCTEXT("DMF", "PartyBankInvalidMove", "That Party move is invalid.") : Failure, InstanceId, EDMFDigimonStorageLocation::Party);
        return;
    }

    const int32 PartyIndex = ReplicatedInventory.Items.IndexOfByPredicate([&](const FDMFReplicatedDigimonEntry& Entry)
    {
        return Entry.Digimon.InstanceId == InstanceId;
    });
    if (PartyIndex == INDEX_NONE)
    {
        ClientDigimonStorageActionResult(false, NSLOCTEXT("DMF", "PartyBankNotInParty", "That Digimon is not currently in your Party."), InstanceId, EDMFDigimonStorageLocation::Party);
        return;
    }
    if (ReplicatedInventory.Items.Num() <= 1)
    {
        ClientDigimonStorageActionResult(false, NSLOCTEXT("DMF", "PartyBankKeepOne", "Your Party must keep at least one Digimon."), InstanceId, EDMFDigimonStorageLocation::Party);
        return;
    }
    if (ReplicatedBank.Items.Num() >= GetBankCapacity())
    {
        ClientDigimonStorageActionResult(false, NSLOCTEXT("DMF", "PartyBankBankFull", "The Digimon Bank is full."), InstanceId, EDMFDigimonStorageLocation::Party);
        return;
    }

    const FGuid PreviousActive = ActivePartnerInstanceId;
    const bool bWasSummoned = IsActivePartnerSummoned();
    const FDMFDigimonInstance Moving = ReplicatedInventory.Items[PartyIndex].Digimon;
    ReplicatedInventory.Items.RemoveAt(PartyIndex);
    FDMFReplicatedDigimonEntry& BankEntry = ReplicatedBank.Items.AddDefaulted_GetRef();
    BankEntry.Digimon = Moving;
    ReplicatedBank.MarkItemDirty(BankEntry);

    if (Moving.InstanceId == PreviousActive)
    {
        ActivePartnerInstanceId.Invalidate();
    }
    ReconcileActivePartnerAfterPartyMutation(PreviousActive, bWasSummoned);
    MarkPartyAndBankChanged(true, true);
    PersistOwningPlayer();
    ClientDigimonStorageActionResult(true, NSLOCTEXT("DMF", "PartyBankMovedToBank", "Digimon moved from Party to Bank."), InstanceId, EDMFDigimonStorageLocation::Bank);
}

void UDMFPlayerDigimonComponent::ServerMoveBankDigimonToParty_Implementation(const FGuid InstanceId, const int32 PartySlotIndex, const bool bSummonIfBecomesActive)
{
    FText Failure;
    if (!InstanceId.IsValid() || !IsPartyMutationAllowed(Failure))
    {
        ClientDigimonStorageActionResult(false, Failure.IsEmpty() ? NSLOCTEXT("DMF", "PartyBankInvalidBankMove", "That Bank move is invalid.") : Failure, InstanceId, EDMFDigimonStorageLocation::Bank);
        return;
    }

    const int32 BankIndex = ReplicatedBank.Items.IndexOfByPredicate([&](const FDMFReplicatedDigimonEntry& Entry)
    {
        return Entry.Digimon.InstanceId == InstanceId;
    });
    if (BankIndex == INDEX_NONE)
    {
        ClientDigimonStorageActionResult(false, NSLOCTEXT("DMF", "PartyBankNotInBank", "That Digimon is not currently in your Bank."), InstanceId, EDMFDigimonStorageLocation::Bank);
        return;
    }

    const int32 PartyCapacity = GetPartyCapacity();
    int32 DestinationIndex = PartySlotIndex;
    if (DestinationIndex == INDEX_NONE)
    {
        DestinationIndex = ReplicatedInventory.Items.Num() < PartyCapacity ? ReplicatedInventory.Items.Num() : INDEX_NONE;
    }
    if (DestinationIndex < 0 || DestinationIndex >= PartyCapacity)
    {
        ClientDigimonStorageActionResult(false, NSLOCTEXT("DMF", "PartyBankSelectPartySlot", "Your Party is full. Select a Party destination slot to swap with."), InstanceId, EDMFDigimonStorageLocation::Bank);
        return;
    }

    const FGuid PreviousActive = ActivePartnerInstanceId;
    const bool bWasSummoned = IsActivePartnerSummoned();
    const FDMFDigimonInstance Incoming = ReplicatedBank.Items[BankIndex].Digimon;
    ReplicatedBank.Items.RemoveAt(BankIndex);

    bool bSwapped = false;
    if (DestinationIndex < ReplicatedInventory.Items.Num())
    {
        const FDMFDigimonInstance Outgoing = ReplicatedInventory.Items[DestinationIndex].Digimon;
        ReplicatedInventory.Items[DestinationIndex].Digimon = Incoming;
        ReplicatedInventory.MarkItemDirty(ReplicatedInventory.Items[DestinationIndex]);

        FDMFReplicatedDigimonEntry& NewBankEntry = ReplicatedBank.Items.AddDefaulted_GetRef();
        NewBankEntry.Digimon = Outgoing;
        ReplicatedBank.MarkItemDirty(NewBankEntry);
        bSwapped = true;

        if (Outgoing.InstanceId == PreviousActive)
        {
            ActivePartnerInstanceId = Incoming.InstanceId;
        }
    }
    else
    {
        FDMFReplicatedDigimonEntry& NewPartyEntry = ReplicatedInventory.Items.AddDefaulted_GetRef();
        NewPartyEntry.Digimon = Incoming;
        ReplicatedInventory.MarkItemDirty(NewPartyEntry);
    }

    ReconcileActivePartnerAfterPartyMutation(PreviousActive, bWasSummoned && (bSummonIfBecomesActive || PreviousActive == ActivePartnerInstanceId));
    MarkPartyAndBankChanged(true, true);
    PersistOwningPlayer();
    ClientDigimonStorageActionResult(true,
        bSwapped ? NSLOCTEXT("DMF", "PartyBankSwapped", "Party and Bank Digimon swapped successfully.")
                 : NSLOCTEXT("DMF", "PartyBankMovedToParty", "Digimon moved from Bank to Party."),
        InstanceId, EDMFDigimonStorageLocation::Party);
}

void UDMFPlayerDigimonComponent::ServerSwapPartySlots_Implementation(const int32 FirstPartySlotIndex, const int32 SecondPartySlotIndex)
{
    FText Failure;
    if (!IsPartyMutationAllowed(Failure))
    {
        ClientDigimonStorageActionResult(false, Failure, FGuid(), EDMFDigimonStorageLocation::Party);
        return;
    }
    if (!ReplicatedInventory.Items.IsValidIndex(FirstPartySlotIndex) || !ReplicatedInventory.Items.IsValidIndex(SecondPartySlotIndex) || FirstPartySlotIndex == SecondPartySlotIndex)
    {
        ClientDigimonStorageActionResult(false, NSLOCTEXT("DMF", "PartyBankInvalidPartySwap", "Choose two occupied Party slots to reorder."), FGuid(), EDMFDigimonStorageLocation::Party);
        return;
    }

    ReplicatedInventory.Items.Swap(FirstPartySlotIndex, SecondPartySlotIndex);
    MarkPartyAndBankChanged(true, false);
    PersistOwningPlayer();
    ClientDigimonStorageActionResult(true, NSLOCTEXT("DMF", "PartyBankPartyReordered", "Party slots reordered."), FGuid(), EDMFDigimonStorageLocation::Party);
}

int32 UDMFPlayerDigimonComponent::HealAllOwnedDigimon(const bool bHealHP, const bool bHealSP, const bool bRestoreDefeated, const bool bIncludeBankStorage)
{
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    if (!PS || !PS->HasAuthority() || (!bHealHP && !bHealSP))
    {
        return 0;
    }

    int32 HealedCount = 0;
    for (FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        FDMFDigimonInstance& Digimon = Entry.Digimon;
        const bool bDefeated = Digimon.CurrentHP <= 0;
        bool bChanged = false;

        if (bHealHP && (!bDefeated || bRestoreDefeated))
        {
            const int32 NewHP = FMath::Max(1, Digimon.Stats.MaxHP);
            bChanged |= Digimon.CurrentHP != NewHP;
            Digimon.CurrentHP = NewHP;
        }
        if (bHealSP)
        {
            const int32 NewSP = FMath::Max(0, Digimon.Stats.MaxSP);
            bChanged |= Digimon.CurrentSP != NewSP;
            Digimon.CurrentSP = NewSP;
        }

        if (bChanged)
        {
            ReplicatedInventory.MarkItemDirty(Entry);
            ++HealedCount;
        }
    }

    UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
    UDMFAccountPersistenceSubsystem* Persistence = GI ? GI->GetSubsystem<UDMFAccountPersistenceSubsystem>() : nullptr;
    FDMFAccountRecord Record;
    const bool bHaveRecord = Persistence && Persistence->GetAccount(PS->GetAuthenticatedUsername(), Record);

    bool bBankHealed = false;
    if (bIncludeBankStorage)
    {
        for (FDMFReplicatedDigimonEntry& Entry : ReplicatedBank.Items)
        {
            FDMFDigimonInstance& Digimon = Entry.Digimon;
            const bool bDefeated = Digimon.CurrentHP <= 0;
            bool bChanged = false;
            if (bHealHP && (!bDefeated || bRestoreDefeated))
            {
                const int32 NewHP = FMath::Max(1, Digimon.Stats.MaxHP);
                bChanged |= Digimon.CurrentHP != NewHP;
                Digimon.CurrentHP = NewHP;
            }
            if (bHealSP)
            {
                const int32 NewSP = FMath::Max(0, Digimon.Stats.MaxSP);
                bChanged |= Digimon.CurrentSP != NewSP;
                Digimon.CurrentSP = NewSP;
            }
            if (bChanged)
            {
                ReplicatedBank.MarkItemDirty(Entry);
                bBankHealed = true;
                ++HealedCount;
            }
        }
        if (bBankHealed)
        {
            ReplicatedBank.MarkArrayDirty();
            OnDigimonBankChanged.Broadcast();
        }
    }

    if (IsValid(ActivePartnerActor) && ActivePartnerActor->CombatComponent)
    {
        FDMFDigimonInstance ActiveInstance;
        if (GetDigimonByInstanceId(ActivePartnerInstanceId, ActiveInstance))
        {
            ActivePartnerActor->CombatComponent->InitializeRuntimeVitals(ActiveInstance.CurrentHP, ActiveInstance.CurrentSP);
            if (ActiveInstance.CurrentHP > 0)
            {
                ActivePartnerActor->CombatComponent->RestoreVitals(bHealHP, bHealSP, true);
            }
        }
    }

    if (HealedCount > 0)
    {
        CommandTarget = nullptr;
        OnCommandTargetChanged.Broadcast(nullptr);
        ReplicatedInventory.MarkArrayDirty();
        OnDigimonInventoryChanged.Broadcast();
        OnPartyHealed.Broadcast(HealedCount);
    }

    if (bHaveRecord)
    {
        ApplyToAccountRecord(Record);
        FString Error;
        if (!Persistence->SaveAccount(Record, Error))
        {
            UE_LOG(LogDigimonMMOFramework, Error, TEXT("Healer persistence failed for '%s': %s"), *PS->GetAuthenticatedUsername(), *Error);
        }
    }
    else if (HealedCount > 0)
    {
        PersistOwningPlayer();
    }

    return HealedCount;
}

void UDMFPlayerDigimonComponent::ServerSetCommandTarget_Implementation(ADMFDigimonCharacter* NewTarget)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || bCareSequenceActive || bDigivolutionSequenceActive)
    {
        return;
    }

    if (NewTarget && (!ActivePartnerActor || !ActivePartnerActor->CombatComponent || !ActivePartnerActor->CombatComponent->CanAttackTarget(NewTarget)))
    {
        return;
    }

    CommandTarget = NewTarget;
    if (ActivePartnerActor && ActivePartnerActor->CombatComponent)
    {
        ActivePartnerActor->CombatComponent->SetAuthoritativeTarget(NewTarget);
    }
    OnCommandTargetChanged.Broadcast(CommandTarget);
}

void UDMFPlayerDigimonComponent::ServerCommandActivePartnerAbilitySlot_Implementation(const int32 SlotIndex, ADMFDigimonCharacter* RequestedTarget)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !ActivePartnerActor || !ActivePartnerActor->CombatComponent || bCareSequenceActive || bDigivolutionSequenceActive)
    {
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const double Now = GetWorld() ? static_cast<double>(GetWorld()->GetTimeSeconds()) : 0.0;
    const double MinimumInterval = Settings ? FMath::Max(0.0, static_cast<double>(Settings->MinimumCombatCommandInterval)) : 0.05;
    if (Now - LastAbilityCommandServerTime < MinimumInterval)
    {
        return;
    }
    LastAbilityCommandServerTime = Now;

    ADMFDigimonCharacter* EffectiveTarget = RequestedTarget ? RequestedTarget : CommandTarget.Get();
    if (EffectiveTarget && !ActivePartnerActor->CombatComponent->CanAttackTarget(EffectiveTarget))
    {
        if (CommandTarget == EffectiveTarget)
        {
            CommandTarget = nullptr;
            OnCommandTargetChanged.Broadcast(nullptr);
        }
        EffectiveTarget = ActivePartnerActor->CombatComponent->GetCurrentTarget();
        if (EffectiveTarget && !ActivePartnerActor->CombatComponent->CanAttackTarget(EffectiveTarget))
        {
            EffectiveTarget = nullptr;
        }
    }

    if (EffectiveTarget)
    {
        const bool bTargetChanged = CommandTarget != EffectiveTarget;
        CommandTarget = EffectiveTarget;
        ActivePartnerActor->CombatComponent->SetAuthoritativeTarget(EffectiveTarget);
        if (bTargetChanged)
        {
            OnCommandTargetChanged.Broadcast(CommandTarget);
        }
    }
    ActivePartnerActor->CombatComponent->QueueOrExecuteAbilitySlot(SlotIndex, EffectiveTarget);
}

void UDMFPlayerDigimonComponent::HandleActivePartnerVitalsChanged(const int32 InCurrentHP, const int32 InCurrentSP)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !ActivePartnerInstanceId.IsValid())
    {
        return;
    }

    for (FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        if (Entry.Digimon.InstanceId == ActivePartnerInstanceId)
        {
            const bool bChanged = Entry.Digimon.CurrentHP != InCurrentHP || Entry.Digimon.CurrentSP != InCurrentSP;
            if (bChanged)
            {
                Entry.Digimon.CurrentHP = InCurrentHP;
                Entry.Digimon.CurrentSP = InCurrentSP;
                ReplicatedInventory.MarkItemDirty(Entry);
                OnDigimonInventoryChanged.Broadcast();

                // A defeat is a high-value persistence boundary; do not wait for the periodic autosave.
                if (InCurrentHP <= 0)
                {
                    PersistOwningPlayer();
                }
            }
            break;
        }
    }
}

void UDMFPlayerDigimonComponent::HandleAuthoritativeBattleVictory(ADMFDigimonCharacter* DefeatedDigimon)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !DefeatedDigimon || !ActivePartnerActor || DefeatedDigimon == ActivePartnerActor)
    {
        return;
    }

    UDMFDigimonSpeciesData* DefeatedSpecies = DefeatedDigimon->ResolveSpeciesData();
    if (!DefeatedSpecies)
    {
        return;
    }

    const int64 ExpReward = FMath::Max<int64>(0, DefeatedSpecies->BattleExperienceReward);
    const int64 MoneyReward = FMath::Max<int64>(0, DefeatedSpecies->BattleMoneyReward);
    FDMFDigimonExperienceProgression ExperienceProgression;
    bool bHasExperienceProgression = false;
    for (FDMFReplicatedDigimonEntry& Entry : ReplicatedInventory.Items)
    {
        if (Entry.Digimon.InstanceId == ActivePartnerInstanceId)
        {
            bHasExperienceProgression = ApplyExperienceReward(Entry, ExpReward, ExperienceProgression);
            if (bHasExperienceProgression)
            {
                ReplicatedInventory.MarkItemDirty(Entry);
                if (IsValid(ActivePartnerActor) && ActivePartnerActor->DigimonInstanceId == Entry.Digimon.InstanceId)
                {
                    // Keep the public replicated partner Level/EXP/stats synchronized without resetting
                    // combat target/recovery/encounter state during the victory frame.
                    ActivePartnerActor->RefreshProgressionFromInstance(Entry.Digimon);
                }
            }
            break;
        }
    }

    Money = FMath::Max<int64>(0, Money + MoneyReward);
    if (CommandTarget == DefeatedDigimon)
    {
        CommandTarget = nullptr;
        OnCommandTargetChanged.Broadcast(nullptr);
    }
    OnDigimonInventoryChanged.Broadcast();
    OnMoneyChanged.Broadcast(Money);

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const bool bEligibleWildVictory = !Settings || !Settings->bAwardScanDataFromWildVictoriesOnly || DefeatedDigimon->IsA<ADMFWildDigimonCharacter>();
    float ScanAdded = 0.0f;
    float NewScanPercent = GetScanPercent(DefeatedSpecies->GetPrimaryAssetId());
    bool bMaterializationReady = IsSpeciesReadyToMaterialize(DefeatedSpecies->GetPrimaryAssetId());
    if (bEligibleWildVictory && AwardScanDataForVictory(*DefeatedSpecies, ScanAdded, NewScanPercent, bMaterializationReady))
    {
        ClientScanDataRewardGranted(DefeatedSpecies->GetPrimaryAssetId(), ScanAdded, NewScanPercent, bMaterializationReady);
    }

    // Reward presentation is emitted through owning-client RPCs. The generic battle-reward event remains
    // backward-compatible while the dedicated progression snapshot gives animated UI deterministic old/new state.
    ClientBattleRewardGranted(DefeatedDigimon->SpeciesId, ExpReward, MoneyReward);
    if (bHasExperienceProgression && (ExperienceProgression.ExperienceGained > 0 || ExperienceProgression.LevelsGained > 0))
    {
        ClientDigimonExperienceProgressed(ExperienceProgression);
    }
    PersistOwningPlayer();
}

void UDMFPlayerDigimonComponent::ClientBattleRewardGranted_Implementation(const FPrimaryAssetId DefeatedSpeciesId, const int64 Experience, const int64 MoneyReward)
{
    OnBattleRewardGranted.Broadcast(DefeatedSpeciesId, Experience, MoneyReward);
}

void UDMFPlayerDigimonComponent::ClientDigimonExperienceProgressed_Implementation(const FDMFDigimonExperienceProgression Progression)
{
    OnDigimonExperienceProgressed.Broadcast(Progression);
}

void UDMFPlayerDigimonComponent::OnRep_CommandTarget()
{
    OnCommandTargetChanged.Broadcast(CommandTarget);
}

void UDMFPlayerDigimonComponent::OnRep_Money()
{
    OnMoneyChanged.Broadcast(Money);
}

void UDMFPlayerDigimonComponent::OnRep_ScanData()
{
    for (const FDMFScanDataEntry& Entry : ReplicatedScanData)
    {
        BroadcastScanState(Entry.SpeciesId);
    }
}

void UDMFPlayerDigimonComponent::OnRep_Inventory()
{
    OnDigimonInventoryChanged.Broadcast();
    if (const FDMFReplicatedDigimonEntry* ActiveEntry = FindInventoryEntry(ActivePartnerInstanceId))
    {
        BroadcastCareState(*ActiveEntry);
    }
}

void UDMFPlayerDigimonComponent::OnRep_Bank()
{
    OnDigimonBankChanged.Broadcast();
}

void UDMFPlayerDigimonComponent::OnRep_ItemInventory()
{
    OnItemInventoryChanged.Broadcast();
}


bool UDMFPlayerDigimonComponent::GetActivePartnerCareState(FDMFDigimonCareState& OutCareState) const
{
    if (const FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(ActivePartnerInstanceId))
    {
        OutCareState = Entry->Digimon.Care;
        return true;
    }
    OutCareState = FDMFDigimonCareState();
    return false;
}

float UDMFPlayerDigimonComponent::GetSecondsUntilActivePartnerWaste() const
{
    const FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(ActivePartnerInstanceId);
    if (!Entry || Entry->Digimon.Care.NextWasteUtcTicks <= 0)
    {
        return -1.0f;
    }
    const FDateTime Due(Entry->Digimon.Care.NextWasteUtcTicks);
    const double Seconds = (Due - FDateTime::UtcNow()).GetTotalSeconds();
    return static_cast<float>(FMath::Max(0.0, Seconds));
}

FDMFReplicatedDigimonEntry* UDMFPlayerDigimonComponent::FindInventoryEntry(const FGuid InstanceId)
{
    return ReplicatedInventory.Items.FindByPredicate([&](const FDMFReplicatedDigimonEntry& Entry)
    {
        return Entry.Digimon.InstanceId == InstanceId;
    });
}

const FDMFReplicatedDigimonEntry* UDMFPlayerDigimonComponent::FindInventoryEntry(const FGuid InstanceId) const
{
    return ReplicatedInventory.Items.FindByPredicate([&](const FDMFReplicatedDigimonEntry& Entry)
    {
        return Entry.Digimon.InstanceId == InstanceId;
    });
}

FDMFReplicatedDigimonEntry* UDMFPlayerDigimonComponent::FindBankEntry(const FGuid InstanceId)
{
    return ReplicatedBank.Items.FindByPredicate([&](const FDMFReplicatedDigimonEntry& Entry)
    {
        return Entry.Digimon.InstanceId == InstanceId;
    });
}

const FDMFReplicatedDigimonEntry* UDMFPlayerDigimonComponent::FindBankEntry(const FGuid InstanceId) const
{
    return ReplicatedBank.Items.FindByPredicate([&](const FDMFReplicatedDigimonEntry& Entry)
    {
        return Entry.Digimon.InstanceId == InstanceId;
    });
}

bool UDMFPlayerDigimonComponent::NormalizeAndApplyCareDecay(FDMFReplicatedDigimonEntry& Entry, const UDMFDigimonSpeciesData& Species, const int64 NowUtcTicks)
{
    if (!Species.bCareEnabled)
    {
        return false;
    }

    FDMFDigimonCareState& Care = Entry.Digimon.Care;
    bool bChanged = false;

    // v0.7.x already serialized a dormant care struct whose legacy defaults were Hunger=0 / Fullness=100.
    // Detect that untouched shape once and migrate it to the new 0=empty,100=full Hunger semantics without
    // punishing existing accounts when they first load v0.8.0.
    const bool bLegacyDormantCare = Care.LastCareUpdateUtcTicks <= 0
        && Care.LastFedUtcTicks <= 0
        && Care.NextWasteUtcTicks <= 0
        && FMath::IsNearlyZero(Care.Hunger)
        && Care.Fullness >= 99.0f;
    if (bLegacyDormantCare)
    {
        Care.Hunger = FMath::Clamp(Care.Fullness, 0.0f, 100.0f);
        bChanged = true;
    }

    const float ClampedHunger = FMath::Clamp(Care.Hunger, 0.0f, 100.0f);
    bChanged |= ClampedHunger != Care.Hunger;
    Care.Hunger = ClampedHunger;
    const int64 EffectiveLastTicks = Care.LastCareUpdateUtcTicks > 0 && Care.LastCareUpdateUtcTicks <= NowUtcTicks
        ? Care.LastCareUpdateUtcTicks
        : NowUtcTicks;
    if (EffectiveLastTicks < NowUtcTicks && Species.HungerDecayPercentPerHour > 0.0f)
    {
        const FTimespan Elapsed = FDateTime(NowUtcTicks) - FDateTime(EffectiveLastTicks);
        const float Decay = static_cast<float>(Elapsed.GetTotalHours()) * FMath::Max(0.0f, Species.HungerDecayPercentPerHour);
        const float NewHunger = FMath::Clamp(Care.Hunger - Decay, 0.0f, 100.0f);
        bChanged |= NewHunger != Care.Hunger;
        Care.Hunger = NewHunger;
    }

    Care.LastCareUpdateUtcTicks = NowUtcTicks;
    if (!FMath::IsNearlyEqual(Care.Fullness, Care.Hunger, 0.001f))
    {
        Care.Fullness = Care.Hunger; // backwards-compatible mirror for existing Blueprint/save consumers
        bChanged = true;
    }
    const float ClampedHappiness = FMath::Clamp(Care.Happiness, 0.0f, 100.0f);
    const float ClampedDiscipline = FMath::Clamp(Care.Discipline, 0.0f, 100.0f);
    const int32 ClampedMistakes = FMath::Max(0, Care.CareMistakes);
    bChanged |= ClampedHappiness != Care.Happiness || ClampedDiscipline != Care.Discipline || ClampedMistakes != Care.CareMistakes;
    Care.Happiness = ClampedHappiness;
    Care.Discipline = ClampedDiscipline;
    Care.CareMistakes = ClampedMistakes;
    return bChanged;
}

void UDMFPlayerDigimonComponent::BroadcastCareState(const FDMFReplicatedDigimonEntry& Entry)
{
    OnCareStateChanged.Broadcast(Entry.Digimon.InstanceId, Entry.Digimon.Care);
}

void UDMFPlayerDigimonComponent::CareTick()
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableCareSystem || !ActivePartnerInstanceId.IsValid())
    {
        return;
    }

    // MMO scalability: only the currently active partner needs live Care replication. The rest of the
    // collection advances from its UTC timestamp during autosave/selection instead of generating a
    // per-player x per-slot network update every Care tick.
    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(ActivePartnerInstanceId);
    UDMFDigimonSpeciesData* Species = Entry ? ResolveSpeciesById(Entry->Digimon.SpeciesId) : nullptr;
    if (!Entry || !Species || !Species->bCareEnabled)
    {
        return;
    }

    const int64 NowUtcTicks = FDateTime::UtcNow().GetTicks();
    const int64 PreviousCareTicks = Entry->Digimon.Care.LastCareUpdateUtcTicks;
    const bool bCareChanged = NormalizeAndApplyCareDecay(*Entry, *Species, NowUtcTicks);
    if (bCareChanged || PreviousCareTicks <= 0)
    {
        ReplicatedInventory.MarkItemDirty(*Entry);
        BroadcastCareState(*Entry);
    }

    if (Entry->Digimon.Care.NextWasteUtcTicks > 0
        && Entry->Digimon.Care.NextWasteUtcTicks <= NowUtcTicks
        && !bCareSequenceActive
        && !bDigivolutionSequenceActive
        && IsValid(ActivePartnerActor)
        && SpawnScheduledWaste(*Entry, *Species))
    {
        ReplicatedInventory.MarkItemDirty(*Entry);
        BroadcastCareState(*Entry);
        PersistOwningPlayer(); // waste is an externally visible one-shot event; crash-safe it immediately
    }
}

bool UDMFPlayerDigimonComponent::ValidateCareFeedingRequest(FDMFReplicatedDigimonEntry*& OutEntry, UDMFDigimonSpeciesData*& OutSpecies, FText& OutFailure)
{
    OutEntry = nullptr;
    OutSpecies = nullptr;
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings || !Settings->bEnableCareSystem)
    {
        OutFailure = NSLOCTEXT("DMF", "CareDisabled", "Digimon Care is disabled for this project.");
        return false;
    }
    if (bCareSequenceActive)
    {
        OutFailure = NSLOCTEXT("DMF", "CareAlreadyActive", "This Digimon is already being cared for.");
        return false;
    }
    if (bDigivolutionSequenceActive)
    {
        OutFailure = NSLOCTEXT("DMF", "CareDigivolutionBusy", "Wait for the active Digivolution sequence to finish before starting Care.");
        return false;
    }
    if (!ActivePartnerInstanceId.IsValid() || !IsValid(ActivePartnerActor))
    {
        OutFailure = NSLOCTEXT("DMF", "CareNeedsSummonedPartner", "Summon your active partner before feeding DigiMeat.");
        return false;
    }

    OutEntry = FindInventoryEntry(ActivePartnerInstanceId);
    OutSpecies = OutEntry ? ResolveSpeciesById(OutEntry->Digimon.SpeciesId) : nullptr;
    if (!OutEntry || !OutSpecies || !OutSpecies->bCareEnabled)
    {
        OutFailure = NSLOCTEXT("DMF", "CareSpeciesUnavailable", "Care is not available for this Digimon species.");
        return false;
    }
    NormalizeAndApplyCareDecay(*OutEntry, *OutSpecies, FDateTime::UtcNow().GetTicks());
    if (OutEntry->Digimon.CurrentHP <= 0 || !ActivePartnerActor->CombatComponent || ActivePartnerActor->CombatComponent->IsDefeated())
    {
        OutFailure = NSLOCTEXT("DMF", "CarePartnerDefeated", "Heal this Digimon before feeding it.");
        return false;
    }
    if (OutEntry->Digimon.Care.Hunger >= 99.99f)
    {
        OutFailure = NSLOCTEXT("DMF", "CareAlreadyFull", "This Digimon is already full.");
        return false;
    }
    if (ActivePartnerActor->CombatComponent->GetCombatState() != EDMFCombatState::Idle || ActivePartnerActor->CombatComponent->GetCurrentTarget())
    {
        OutFailure = NSLOCTEXT("DMF", "CareInCombat", "Finish the current battle before feeding your Digimon.");
        return false;
    }
    if (OutSpecies->FeedingMontage.IsNull() || !OutSpecies->FeedingMontage.LoadSynchronous())
    {
        OutFailure = NSLOCTEXT("DMF", "CareMontageMissing", "This species needs a Feeding Montage before it can eat.");
        return false;
    }
    UStaticMesh* MeatMesh = !OutSpecies->DigiMeatMesh.IsNull() ? OutSpecies->DigiMeatMesh.LoadSynchronous() : Settings->DefaultDigiMeatMesh.LoadSynchronous();
    if (!MeatMesh)
    {
        OutFailure = NSLOCTEXT("DMF", "CareMeatMeshMissing", "Assign a DigiMeat mesh in the species or Digimon MMO Framework settings.");
        return false;
    }
    if (OutSpecies->DigiMeatHandSocketName.IsNone() || !ActivePartnerActor->GetMesh() || !ActivePartnerActor->GetMesh()->DoesSocketExist(OutSpecies->DigiMeatHandSocketName))
    {
        OutFailure = NSLOCTEXT("DMF", "CareSocketMissing", "The configured DigiMeat hand socket does not exist on this Digimon skeleton.");
        return false;
    }
    return true;
}

void UDMFPlayerDigimonComponent::ServerFeedActivePartnerUntilFull_Implementation()
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }
    FDMFReplicatedDigimonEntry* Entry = nullptr;
    UDMFDigimonSpeciesData* Species = nullptr;
    FText Failure;
    if (!ValidateCareFeedingRequest(Entry, Species, Failure))
    {
        ClientCareSequenceFinished(false, Failure, ActivePartnerInstanceId);
        return;
    }

    bCareSequenceActive = true;
    CareSequenceInstanceId = ActivePartnerInstanceId;
    bCareRestoreAutoBattle = ActivePartnerActor->CombatComponent->IsAutoBattleEnabled();
    bCareRestoreRetaliation = ActivePartnerActor->CombatComponent->IsRetaliationEnabled();
    ActivePartnerActor->CombatComponent->ConfigureRetaliation(false);
    ActivePartnerActor->CombatComponent->SetAuthoritativeTarget(nullptr);
    CommandTarget = nullptr;
    OnCommandTargetChanged.Broadcast(nullptr);

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
    APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
    ActivePartnerActor->ConfigureCombatAutomation(false,
        Settings ? Settings->PartnerAggroRange : 1200.0f,
        Settings ? Settings->PartnerLeashRange : 2500.0f,
        PC ? PC->GetPawn() : nullptr);
    if (AAIController* AI = Cast<AAIController>(ActivePartnerActor->GetController()))
    {
        AI->StopMovement();
    }
    ActivePartnerActor->StopCombatFacingTarget();
    if (GetOwner()) GetOwner()->ForceNetUpdate();
    ClientCareSequenceStarted(CareSequenceInstanceId);

    const float LeadIn = Settings ? FMath::Max(0.0f, Settings->CarePresentationLeadInSeconds) : 0.35f;
    if (LeadIn <= KINDA_SMALL_NUMBER)
    {
        BeginCareServing();
    }
    else
    {
        GetWorld()->GetTimerManager().SetTimer(CareSequenceTimer, this, &UDMFPlayerDigimonComponent::BeginCareServing, LeadIn, false);
    }
}

void UDMFPlayerDigimonComponent::ClientCareSequenceStarted_Implementation(const FGuid DigimonInstanceId)
{
    OnCareSequenceStarted.Broadcast(DigimonInstanceId);
}

void UDMFPlayerDigimonComponent::ClientCareSequenceFinished_Implementation(const bool bSuccess, const FText& Message, const FGuid DigimonInstanceId)
{
    OnCareSequenceFinished.Broadcast(bSuccess, Message, DigimonInstanceId);
}

void UDMFPlayerDigimonComponent::BeginCareServing()
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !bCareSequenceActive || !IsValid(ActivePartnerActor))
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CarePartnerLost", "Feeding stopped because the active partner is no longer available."));
        return;
    }
    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(CareSequenceInstanceId);
    UDMFDigimonSpeciesData* Species = Entry ? ResolveSpeciesById(Entry->Digimon.SpeciesId) : nullptr;
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Entry || !Species || !Settings)
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareDataLost", "Feeding stopped because the Digimon care data could not be resolved."));
        return;
    }
    if (Entry->Digimon.Care.Hunger >= 99.99f)
    {
        FinishCareSequence(true, NSLOCTEXT("DMF", "CareFeedComplete", "Your Digimon is full and happy with its meal."));
        return;
    }

    DestroyActiveCareMeat();
    UClass* PropClass = Settings->CarePropActorClass ? Settings->CarePropActorClass.Get() : ADMFDigimonCarePropActor::StaticClass();
    if (!PropClass || !PropClass->IsChildOf(ADMFDigimonCarePropActor::StaticClass())) PropClass = ADMFDigimonCarePropActor::StaticClass();
    FActorSpawnParameters Params;
    Params.Owner = GetOwner();
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ActiveCareDigiMeatActor = GetWorld()->SpawnActor<ADMFDigimonCarePropActor>(PropClass, ActivePartnerActor->GetActorTransform(), Params);
    if (!ActiveCareDigiMeatActor)
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareMeatSpawnFailed", "The DigiMeat presentation actor could not be created."));
        return;
    }
    ActiveCareDigiMeatActor->InitializeCareProp(Species->GetPrimaryAssetId(), EDMFCarePropType::DigiMeat);
    ActiveCareDigiMeatActor->AttachToComponent(ActivePartnerActor->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, Species->DigiMeatHandSocketName);
    ActiveCareDigiMeatActor->SetActorRelativeTransform(Species->DigiMeatRelativeTransform);

    CareMontagePlayIndex = 0;
    CareServingVoiceSoundIndex = Species->FeedingVoiceSounds.IsEmpty() ? INDEX_NONE : FMath::RandRange(0, Species->FeedingVoiceSounds.Num() - 1);
    PlayNextCareMontage();
}

void UDMFPlayerDigimonComponent::PlayNextCareMontage()
{
    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(CareSequenceInstanceId);
    UDMFDigimonSpeciesData* Species = Entry ? ResolveSpeciesById(Entry->Digimon.SpeciesId) : nullptr;
    if (!bCareSequenceActive || !Entry || !Species || !IsValid(ActivePartnerActor)
        || !ActivePartnerActor->CombatComponent || ActivePartnerActor->CombatComponent->IsDefeated())
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareInterrupted", "The feeding presentation was interrupted."));
        return;
    }

    const int32 Plays = FMath::Clamp(Species->FeedingMontagePlaysPerServing, 1, 8);
    if (CareMontagePlayIndex >= Plays)
    {
        CompleteCareServing();
        return;
    }

    UAnimMontage* FeedingMontage = Species->FeedingMontage.LoadSynchronous();
    if (!FeedingMontage)
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareMontageBecameInvalid", "The Feeding Montage is no longer available."));
        return;
    }

    const int32 VoiceIndex = CareMontagePlayIndex == 0 ? CareServingVoiceSoundIndex : INDEX_NONE;
    ActivePartnerActor->MulticastPlayCareFeedingCue(VoiceIndex);
    ++CareMontagePlayIndex;

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const float PlayRate = FMath::Max(0.05f, Species->FeedingMontagePlayRate);
    const float RawDuration = FeedingMontage->GetPlayLength() / PlayRate;
    const float Duration = RawDuration > KINDA_SMALL_NUMBER ? RawDuration : (Settings ? Settings->CareFallbackMontageDurationSeconds : 1.0f);
    GetWorld()->GetTimerManager().SetTimer(CareSequenceTimer, this, &UDMFPlayerDigimonComponent::PlayNextCareMontage, FMath::Max(0.05f, Duration), false);
}

void UDMFPlayerDigimonComponent::CompleteCareServing()
{
    DestroyActiveCareMeat();
    FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(CareSequenceInstanceId);
    UDMFDigimonSpeciesData* Species = Entry ? ResolveSpeciesById(Entry->Digimon.SpeciesId) : nullptr;
    if (!Entry || !Species)
    {
        FinishCareSequence(false, NSLOCTEXT("DMF", "CareCompleteDataLost", "Feeding stopped because its care data became unavailable."));
        return;
    }

    const FDateTime Now = FDateTime::UtcNow();
    FDMFDigimonCareState& Care = Entry->Digimon.Care;
    Care.Hunger = FMath::Clamp(Care.Hunger + FMath::Max(0.1f, Species->DigiMeatHungerPercentPerServing), 0.0f, 100.0f);
    Care.Fullness = Care.Hunger;
    Care.LastFedUtcTicks = Now.GetTicks();
    Care.LastCareUpdateUtcTicks = Now.GetTicks();
    if (Species->bWasteEnabled && Care.NextWasteUtcTicks <= 0)
    {
        const float MinDelay = FMath::Max(1.0f, Species->MinimumWasteDelaySeconds);
        const float MaxDelay = FMath::Max(MinDelay, Species->MaximumWasteDelaySeconds);
        Care.NextWasteUtcTicks = (Now + FTimespan::FromSeconds(FMath::FRandRange(MinDelay, MaxDelay))).GetTicks();
    }
    ReplicatedInventory.MarkItemDirty(*Entry);
    BroadcastCareState(*Entry);
    PersistOwningPlayer();

    if (Care.Hunger >= 99.99f)
    {
        FinishCareSequence(true, NSLOCTEXT("DMF", "CareFeedComplete", "Your Digimon is full and the care state has been saved."));
        return;
    }

    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    const float Pause = Settings ? FMath::Max(0.0f, Settings->CareInterServingPauseSeconds) : 0.20f;
    if (Pause <= KINDA_SMALL_NUMBER) BeginCareServing();
    else GetWorld()->GetTimerManager().SetTimer(CareSequenceTimer, this, &UDMFPlayerDigimonComponent::BeginCareServing, Pause, false);
}

void UDMFPlayerDigimonComponent::FinishCareSequence(const bool bSuccess, const FText& Message)
{
    if (UWorld* World = GetWorld()) World->GetTimerManager().ClearTimer(CareSequenceTimer);
    DestroyActiveCareMeat();
    const FGuid FinishedInstanceId = CareSequenceInstanceId;
    bCareSequenceActive = false;
    CareSequenceInstanceId.Invalidate();
    CareMontagePlayIndex = 0;
    CareServingVoiceSoundIndex = INDEX_NONE;

    if (IsValid(ActivePartnerActor) && ActivePartnerActor->CombatComponent)
    {
        const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
        ADMFPlayerState* PS = Cast<ADMFPlayerState>(GetOwner());
        APlayerController* PC = PS ? Cast<APlayerController>(PS->GetOwner()) : nullptr;
        ActivePartnerActor->ConfigureCombatAutomation(
            bCareRestoreAutoBattle && Settings && Settings->bPlayerPartnerAutoBattle,
            Settings ? Settings->PartnerAggroRange : 1200.0f,
            Settings ? Settings->PartnerLeashRange : 2500.0f,
            PC ? PC->GetPawn() : nullptr);
        ActivePartnerActor->CombatComponent->ConfigureRetaliation(bCareRestoreRetaliation);
    }
    bCareRestoreAutoBattle = false;
    bCareRestoreRetaliation = false;
    if (GetOwner()) GetOwner()->ForceNetUpdate();
    ClientCareSequenceFinished(bSuccess, Message, FinishedInstanceId);
    CareTick();
}

void UDMFPlayerDigimonComponent::DestroyActiveCareMeat()
{
    if (IsValid(ActiveCareDigiMeatActor)) ActiveCareDigiMeatActor->Destroy();
    ActiveCareDigiMeatActor = nullptr;
}

bool UDMFPlayerDigimonComponent::SpawnScheduledWaste(FDMFReplicatedDigimonEntry& Entry, UDMFDigimonSpeciesData& Species)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !GetWorld() || !IsValid(ActivePartnerActor) || !Species.bWasteEnabled)
    {
        return false;
    }
    const UDMFFrameworkSettings* Settings = GetDefault<UDMFFrameworkSettings>();
    if (!Settings) return false;

    UStaticMesh* WasteMesh = !Species.PooMesh.IsNull() ? Species.PooMesh.LoadSynchronous() : Settings->DefaultPooMesh.LoadSynchronous();
    if (!WasteMesh)
    {
        // Keep the timer overdue rather than silently consuming it; once a mesh is configured the next care tick succeeds.
        return false;
    }

    const FVector Origin = ActivePartnerActor->GetActorLocation();
    const FVector TraceStart = Origin + FVector(0.0, 0.0, 100.0);
    const FVector TraceEnd = Origin - FVector(0.0, 0.0, 750.0);
    FHitResult Hit;
    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(DMFCareWasteGroundTrace), false, ActivePartnerActor);
    ADMFPlayerState* OwnerPlayerState = Cast<ADMFPlayerState>(GetOwner());
    APlayerController* OwnerController = OwnerPlayerState ? Cast<APlayerController>(OwnerPlayerState->GetOwner()) : nullptr;
    if (APawn* OwnerPawn = OwnerController ? OwnerController->GetPawn() : nullptr)
    {
        QueryParams.AddIgnoredActor(OwnerPawn);
    }
    const bool bHitGround = GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, QueryParams);
    const FVector GroundNormal = bHitGround ? Hit.ImpactNormal.GetSafeNormal() : FVector::UpVector;
    const float CapsuleHalfHeight = ActivePartnerActor->GetCapsuleComponent() ? ActivePartnerActor->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() : 0.0f;
    const FVector FallbackGroundPoint = Origin - FVector(0.0, 0.0, CapsuleHalfHeight);
    const FVector SpawnLocation = (bHitGround ? Hit.ImpactPoint : FallbackGroundPoint) + GroundNormal * FMath::Max(0.0f, Species.PooGroundOffset);
    const FRotator SpawnRotation = FRotationMatrix::MakeFromZ(GroundNormal).Rotator();

    UClass* PropClass = Settings->CarePropActorClass ? Settings->CarePropActorClass.Get() : ADMFDigimonCarePropActor::StaticClass();
    if (!PropClass || !PropClass->IsChildOf(ADMFDigimonCarePropActor::StaticClass())) PropClass = ADMFDigimonCarePropActor::StaticClass();
    FActorSpawnParameters Params;
    Params.Owner = GetOwner();
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ADMFDigimonCarePropActor* WasteActor = GetWorld()->SpawnActor<ADMFDigimonCarePropActor>(PropClass, SpawnLocation, SpawnRotation, Params);
    if (!WasteActor) return false;

    WasteActor->InitializeCareProp(Species.GetPrimaryAssetId(), EDMFCarePropType::Waste);
    const FVector SafeScale(
        FMath::Max(0.01f, FMath::Abs(Species.PooWorldScale.X)),
        FMath::Max(0.01f, FMath::Abs(Species.PooWorldScale.Y)),
        FMath::Max(0.01f, FMath::Abs(Species.PooWorldScale.Z)));
    WasteActor->SetActorScale3D(SafeScale);
    WasteActor->SetLifeSpan(FMath::Max(1.0f, Species.PooLifetimeSeconds));

    const int32 FartIndex = Species.WasteFartSounds.IsEmpty() ? INDEX_NONE : FMath::RandRange(0, Species.WasteFartSounds.Num() - 1);
    ActivePartnerActor->MulticastPlayCareWasteCue(FartIndex);
    Entry.Digimon.Care.NextWasteUtcTicks = 0;
    return true;
}

void UDMFPlayerDigimonComponent::OnRep_CareSequenceActive()
{
    if (const FDMFReplicatedDigimonEntry* Entry = FindInventoryEntry(ActivePartnerInstanceId))
    {
        BroadcastCareState(*Entry);
    }
}

void UDMFPlayerDigimonComponent::OnRep_ActivePartnerInstanceId()
{
    OnDigimonInventoryChanged.Broadcast();
}

void UDMFPlayerDigimonComponent::OnRep_ActivePartnerActor()
{
    OnDigimonInventoryChanged.Broadcast();
}

void UDMFPlayerDigimonComponent::OnRep_StarterSelectionRequired()
{
    OnStarterRequirementChanged.Broadcast(bStarterSelectionRequired);
}
