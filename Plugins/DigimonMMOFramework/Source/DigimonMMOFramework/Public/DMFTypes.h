#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "DMFTypes.generated.h"

UENUM(BlueprintType)
enum class EDMFDigimonStage : uint8
{
    BabyI UMETA(DisplayName="Fresh"),
    BabyII UMETA(DisplayName="In-Training"),
    Rookie,
    Champion,
    Ultimate,
    Mega,
    Ultra,
    Armor,
    Hybrid,
    Unknown
};

UENUM(BlueprintType)
enum class EDMFDigimonAttribute : uint8
{
    Vaccine,
    Virus,
    Data,
    Free,
    Variable,
    Unknown
};

UENUM(BlueprintType)
enum class EDMFDigimonElement : uint8
{
    Neutral,
    Fire,
    Water,
    Plant,
    Earth,
    Wind,
    Electric,
    Light,
    Dark,
    Steel,
    Ice,
    Unknown
};

/** Generic MMO rarity tier assigned by authoritative wild spawners. */
UENUM(BlueprintType)
enum class EDMFWildSpawnRarity : uint8
{
    Common,
    Uncommon,
    Rare,
    Epic,
    Legendary,
    Mythic
};

/** Result category for the framework-native player interaction layer. */
UENUM(BlueprintType)
enum class EDMFPlayerInteractionType : uint8
{
    None,
    DigimonTarget,
    DigimonTargetAndAttack,
    Healer,
    Unhandled
};

UENUM(BlueprintType)
enum class EDMFRankedTier : uint8
{
    F,
    E,
    D,
    C,
    B,
    A,
    S,
    SPlus UMETA(DisplayName="S+")
};

/** Presentation category for the native session world-chat stream. */
UENUM(BlueprintType)
enum class EDMFWorldChatMessageType : uint8
{
    Player,
    System
};

/**
 * Server-stamped world-chat payload delivered to owning PlayerControllers.
 * Clients submit only raw text; sender identity and timestamp are always authored by the server.
 */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFWorldChatMessage
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="World Chat")
    FString SenderName;

    UPROPERTY(BlueprintReadOnly, Category="World Chat")
    FString Message;

    UPROPERTY(BlueprintReadOnly, Category="World Chat")
    int64 SentUtcTicks = 0;

    UPROPERTY(BlueprintReadOnly, Category="World Chat")
    EDMFWorldChatMessageType MessageType = EDMFWorldChatMessageType::Player;
};

/** Current pages in the polished Digimon menu shell. Additional systems can extend this enum later. */
UENUM(BlueprintType)
enum class EDMFDigimonMenuTab : uint8
{
    /** Backward-compatible API name/value for the active six-Digimon Party page. */
    Collection UMETA(DisplayName="Party"),

    /** Existing serialized values remain in their pre-v0.12 order for Blueprint/save compatibility. */
    ScanAndMaterialize UMETA(DisplayName="Scan & Materialize"),
    Care,

    /** Appended in v0.12 so earlier enum values are never shifted. */
    Bank UMETA(DisplayName="Bank / Boxes"),

    /** Appended in v0.13. Existing serialized tab values remain stable. */
    Digivolution UMETA(DisplayName="Digivolution")
};

/** Authoritative owner-storage location used by Party/Bank transfer APIs. */
UENUM(BlueprintType)
enum class EDMFDigimonStorageLocation : uint8
{
    Party,
    Bank
};



/** Local/owner-only evaluation row for one configured Digivolution path. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigivolutionEvaluation
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Digivolution")
    FPrimaryAssetId TargetSpeciesId;

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Digivolution")
    bool bEligible = false;

    /** Compact human-readable requirement summary suitable for native/Blueprint UI. */
    UPROPERTY(BlueprintReadOnly, Category="Digimon|Digivolution")
    FText RequirementSummary;

    /** Empty when eligible; otherwise the first authoritative requirement that is not currently met. */
    UPROPERTY(BlueprintReadOnly, Category="Digimon|Digivolution")
    FText FailureReason;
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonStats
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Progression")
    int32 Level = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Progression")
    int64 Experience = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 MaxHP = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 MaxSP = 50;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 Strength = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 Intelligence = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 Defense = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 Speed = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 ABI = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 CAM = 0;
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonCareState
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Care", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Hunger = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Care", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Fullness = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Care", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Happiness = 50.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Care", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Discipline = 50.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Care")
    int32 CareMistakes = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Care")
    int64 LastFedUtcTicks = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Care")
    int64 NextWasteUtcTicks = 0;

    /** Server UTC timestamp used to apply deterministic online/offline Hunger decay. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Care")
    int64 LastCareUpdateUtcTicks = 0;
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonInstance
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Digimon|Identity")
    FGuid InstanceId;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Digimon|Identity")
    FPrimaryAssetId SpeciesId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Identity")
    FString Nickname;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    FDMFDigimonStats Stats;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 CurrentHP = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Stats")
    int32 CurrentSP = 50;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Progression")
    int32 UnspentAttributePoints = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Abilities")
    TArray<FName> EquippedAbilityIds;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Care")
    FDMFDigimonCareState Care;

    /** First materialized/starter species for this persistent individual. Added in SaveGame schema v5. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Digivolution")
    FPrimaryAssetId OriginSpeciesId;

    /** Ordered unique list of species forms reached by this individual. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Digivolution")
    TArray<FPrimaryAssetId> DigivolutionHistory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Meta")
    bool bStarterPartner = false;

    bool IsValid() const
    {
        return InstanceId.IsValid() && SpeciesId.IsValid();
    }
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFScanDataEntry
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
    FPrimaryAssetId SpeciesId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, meta=(ClampMin="0.0", ClampMax="999.0"))
    float ScanPercent = 0.0f;
};


UENUM(BlueprintType)
enum class EDMFMusicState : uint8
{
    None,
    Frontend,
    OpenWorld,
    Battle
};

UENUM(BlueprintType)
enum class EDMFCombatState : uint8
{
    Idle,
    Chasing,
    Attacking,
    Recovering,
    Defeated
};

UENUM(BlueprintType)
enum class EDMFDamageScaling : uint8
{
    Strength,
    Intelligence
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFAbilityCooldownState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Combat")
    FName AbilityId;

    /** Synchronized server world time at which the ability becomes ready. */
    UPROPERTY(BlueprintReadOnly, Category="Digimon|Combat")
    double EndServerTimeSeconds = 0.0;
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFBattleReward
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon|Battle")
    int64 Experience = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Digimon|Battle")
    int64 Money = 0;
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFAccountRecord
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Account")
    FString Username;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Account")
    FString CredentialDigest;

    /** Persistent visual avatar selection. Presentation-only; gameplay pawn class remains authoritative. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Player Avatar")
    FPrimaryAssetId SelectedPlayerSkinId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon")
    TArray<FDMFDigimonInstance> DigimonInventory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon")
    TArray<FDMFDigimonInstance> DigimonBank;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon")
    FGuid ActivePartnerInstanceId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon")
    bool bStarterSelected = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Progression")
    TArray<FDMFScanDataEntry> ScanData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Economy")
    int64 Money = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Ranked")
    int32 RankedBattlePoints = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Ranked")
    EDMFRankedTier RankedTier = EDMFRankedTier::F;
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFReplicatedDigimonEntry : public FFastArraySerializerItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FDMFDigimonInstance Digimon;
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFReplicatedDigimonList : public FFastArraySerializer
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<FDMFReplicatedDigimonEntry> Items;

    bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParams)
    {
        return FFastArraySerializer::FastArrayDeltaSerialize<FDMFReplicatedDigimonEntry, FDMFReplicatedDigimonList>(Items, DeltaParams, *this);
    }
};

template<>
struct TStructOpsTypeTraits<FDMFReplicatedDigimonList> : public TStructOpsTypeTraitsBase2<FDMFReplicatedDigimonList>
{
    enum
    {
        WithNetDeltaSerializer = true,
    };
};
