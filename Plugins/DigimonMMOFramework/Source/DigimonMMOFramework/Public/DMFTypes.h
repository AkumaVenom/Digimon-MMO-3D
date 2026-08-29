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

/** Authoritative world-time source used by DMFDayNightSky. */
UENUM(BlueprintType)
enum class EDMFDayNightTimeSource : uint8
{
    /** The authority machine's local PC clock drives world time. Listen servers therefore follow the host PC clock. */
    HostSystemTime UMETA(DisplayName="Host PC System Time"),

    /** A persistent accelerated game clock. Default tuning can emulate a GTA-style compressed day. */
    Simulated UMETA(DisplayName="Simulated / GTA Style")
};

/** Canonical replicated day/night phase shared by the sky and time-aware wild spawners. */
UENUM(BlueprintType)
enum class EDMFDayNightPhase : uint8
{
    Day,
    Night
};

/** Population policy for a wild spawner. Existing Always behavior remains the compatibility default. */
UENUM(BlueprintType)
enum class EDMFWildPopulationScheduleMode : uint8
{
    Always UMETA(DisplayName="Always / Legacy Spawn Table"),
    DayNight UMETA(DisplayName="Day / Night Population Sets")
};

/** Result category for the framework-native player interaction layer. */
UENUM(BlueprintType)
enum class EDMFPlayerInteractionType : uint8
{
    None,
    DigimonTarget,
    DigimonTargetAndAttack,
    Healer,
    Unhandled,

    /** Appended in v0.18.0; existing serialized interaction values remain stable. */
    DigimonVendor UMETA(DisplayName="Digimon Vendor")
};

/** Transaction direction for the server-authoritative Digimon vendor economy. */
UENUM(BlueprintType)
enum class EDMFDigimonVendorTransactionType : uint8
{
    Buy,
    Sell
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
    System,

    /** Server-authored authenticated presence event. Appended to preserve Player/System serialized values. */
    PlayerJoined UMETA(DisplayName="Player Joined"),

    /** Server-authored authenticated departure event. Appended to preserve Player/System serialized values. */
    PlayerLeft UMETA(DisplayName="Player Left")
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
    Digivolution UMETA(DisplayName="Digivolution"),

    /** Appended in v0.14. Read-only encyclopedia; earlier serialized tab values remain stable. */
    DigiDex UMETA(DisplayName="DigiDex"),

    /** Appended in v0.19. Persistent friends/ignore/guild social hub. */
    Social UMETA(DisplayName="Social")
};

/** Nested pages inside the extensible Social tab. */
UENUM(BlueprintType)
enum class EDMFSocialMenuTab : uint8
{
    Friends,
    Guild
};

/** Server-side action discriminator used by the single validated social mutation RPC. */
UENUM(BlueprintType)
enum class EDMFSocialActionType : uint8
{
    SendFriendRequest,
    RespondFriendRequest,
    RemoveFriend,
    SetFriendTracking,
    IgnorePlayer,
    RemoveIgnoredPlayer,
    CreateGuild,
    RenameGuild,
    InvitePlayerToGuild,
    RespondGuildInvite,
    ApplyToGuild,
    RespondGuildApplication,
    RemoveGuildMember,
    LeaveGuild,
    DisbandGuild,
    CancelFriendRequest
};

/** Authoritative owner-storage location used by Party/Bank transfer APIs. */
UENUM(BlueprintType)
enum class EDMFDigimonStorageLocation : uint8
{
    Party,
    Bank
};

/** Core persistent stats that may be increased by spending earned Attribute Points. ABI/CAM remain progression/care values and are intentionally not spendable here. */
UENUM(BlueprintType)
enum class EDMFDigimonAttributeStat : uint8
{
    MaxHP UMETA(DisplayName="Max HP"),
    MaxSP UMETA(DisplayName="Max SP"),
    Strength UMETA(DisplayName="Strength"),
    Intelligence UMETA(DisplayName="Intelligence"),
    Defense UMETA(DisplayName="Defense"),
    Speed UMETA(DisplayName="Speed")
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

    /** Lifetime server-authored EXP earned by this persistent individual. Added in account schema v7 for economy/progression valuation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Progression")
    int64 LifetimeBattleExperience = 0;

    /** Exact count of committed +1 core-stat Attribute Point spends. Added in account schema v7. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Digimon|Progression")
    int32 TotalAttributePointsSpent = 0;

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

/** Owner-facing snapshot of one authoritative EXP mutation. Durable progression remains in FDMFDigimonInstance. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDigimonExperienceProgression
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    FGuid DigimonInstanceId;

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    FPrimaryAssetId SpeciesId;

    /** EXP actually applied to this Digimon by the authoritative mutation. */
    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    int64 ExperienceGained = 0;

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    int32 PreviousLevel = 1;

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    int32 NewLevel = 1;

    /** EXP bank toward PreviousLevel + 1 before this reward. */
    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    int64 PreviousExperience = 0;

    /** Remaining EXP bank toward NewLevel + 1 after consuming every completed level threshold. */
    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    int64 NewExperience = 0;

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    int32 LevelsGained = 0;

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    int32 AttributePointsGained = 0;

    UPROPERTY(BlueprintReadOnly, Category="Digimon|Progression")
    bool bReachedMaxLevel = false;
};


/** Persisted authority-owned state for one DMFDayNightSky simulated clock. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFDayNightPersistentState
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Day Night")
    bool bHasSavedState = false;

    /** Saved 0-24 game clock. Host-system-time mode ignores this as an authority source. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Day Night")
    float TimeOfDayHours = 8.0f;

    /** Persistent simulated day counter. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Day Night")
    int32 DayIndex = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Day Night")
    int64 SavedUtcTicks = 0;
};

/** Persisted server-authored gameplay transform for one account. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFPlayerWorldLocationState
{
    GENERATED_BODY()

    /** False until the framework has committed the account's first gameplay spawn checkpoint. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Player World Location")
    bool bHasSavedLocation = false;

    /** PIE-prefix-free level name used to avoid applying coordinates to the wrong gameplay map. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Player World Location")
    FString MapName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Player World Location")
    FVector Location = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Player World Location")
    FRotator Rotation = FRotator::ZeroRotator;

    /** Server UTC timestamp of the most recent committed position checkpoint. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Player World Location")
    int64 SavedUtcTicks = 0;
};

/** Compact owner-only friend row. Online state is live session state; tracking preference is persistent. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFSocialFriendEntry
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Social|Friends")
    FString Username;

    UPROPERTY(BlueprintReadOnly, Category="Social|Friends")
    bool bOnline = false;

    UPROPERTY(BlueprintReadOnly, Category="Social|Friends")
    bool bTrackingEnabled = false;
};

/** Owner-local discovery row derived from already-replicated player avatars. No authority is stored here. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFNearbySocialPlayerEntry
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Social|Nearby Players")
    FString Username;

    /** Precise local distance used for nearest-first ordering. Native UI presents a rounded integer metre value. */
    UPROPERTY(BlueprintReadOnly, Category="Social|Nearby Players")
    float DistanceMeters = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="Social|Nearby Players")
    bool bIsFriend = false;

    UPROPERTY(BlueprintReadOnly, Category="Social|Nearby Players")
    bool bHasIncomingFriendRequest = false;

    UPROPERTY(BlueprintReadOnly, Category="Social|Nearby Players")
    bool bHasOutgoingFriendRequest = false;

    UPROPERTY(BlueprintReadOnly, Category="Social|Nearby Players")
    bool bIsIgnored = false;
};

/** Persistent guild invitation stored on the invited account so it survives either player going offline. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFGuildInvite
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    FGuid GuildId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    FString GuildName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    FString InviterUsername;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    int64 SentUtcTicks = 0;
};

/** Persistent server-owned guild record. Membership and applications are never client-authored. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFGuildRecord
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    FGuid GuildId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    FString OwnerUsername;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    TArray<FString> MemberUsernames;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    TArray<FString> PendingApplications;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    int64 CreatedUtcTicks = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    int64 LastModifiedUtcTicks = 0;
};

/** Read-only search result sent to one player; member lists remain private to actual guild members. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFGuildSummary
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    FGuid GuildId;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    FString Name;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    FString OwnerUsername;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    int32 MemberCount = 0;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    bool bApplicationPending = false;
};

USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFGuildMemberEntry
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    FString Username;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    bool bOwner = false;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    bool bOnline = false;
};

/** Complete owner-only social view sent on demand and after authoritative social mutations. */
USTRUCT(BlueprintType)
struct DIGIMONMMOFRAMEWORK_API FDMFSocialSnapshot
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Social|Friends")
    TArray<FDMFSocialFriendEntry> Friends;

    UPROPERTY(BlueprintReadOnly, Category="Social|Friends")
    TArray<FString> PendingFriendRequests;

    /** Persistent outbound requests are returned separately so UI can show/cancel a sent request without guessing. */
    UPROPERTY(BlueprintReadOnly, Category="Social|Friends")
    TArray<FString> PendingOutgoingFriendRequests;

    UPROPERTY(BlueprintReadOnly, Category="Social|Ignore")
    TArray<FString> IgnoredPlayers;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    TArray<FDMFGuildInvite> PendingGuildInvites;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    FGuid GuildId;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    FString GuildName;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    FString GuildOwnerUsername;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    bool bIsGuildOwner = false;

    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    TArray<FDMFGuildMemberEntry> GuildMembers;

    /** Populated only for the guild owner. */
    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    TArray<FString> PendingGuildApplications;

    /** Public guild directory summaries; never contains private account data. */
    UPROPERTY(BlueprintReadOnly, Category="Social|Guild")
    TArray<FDMFGuildSummary> GuildSearchResults;
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

    /** Server-authored gameplay location used for first-spawn vs returning-player restore. Added in SaveGame schema v6. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Player World Location")
    FDMFPlayerWorldLocationState PlayerWorldLocation;

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

    /**
     * Per-account one-way marker for the v0.18 Digimon valuation provenance migration.
     * Legacy records deserialize as 0; current/new accounts are persisted as 1 so a legitimately
     * zero-spend high-level vendor Digimon is never reinterpreted as legacy on a later reconnect.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Economy")
    int32 DigimonEconomyProvenanceVersion = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Ranked")
    int32 RankedBattlePoints = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Ranked")
    EDMFRankedTier RankedTier = EDMFRankedTier::F;

    /** Persistent accepted friendships. Usernames are canonical account display names and comparisons are case-insensitive. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Friends")
    TArray<FString> FriendUsernames;

    /** Persistent inbound requests. No modal popup is required; the Social/Friends tab owns acceptance/decline presentation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Friends")
    TArray<FString> PendingFriendRequests;

    /** Persistent outbound requests. Stored reciprocally with the target's inbound request so send/cancel/response stays atomic. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Friends")
    TArray<FString> PendingOutgoingFriendRequests;

    /** Persistent per-account ignore list. Ignored players remain fully replicated in-world; only their authored chat is filtered. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Ignore")
    TArray<FString> IgnoredUsernames;

    /** Persistent subset of FriendUsernames whose local world-space distance tracker should be shown. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Friends")
    TArray<FString> TrackedFriendUsernames;

    /** Invalid when the account is not currently a guild member. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    FGuid GuildId;

    /** Persistent inbound guild invitations. Stale/disbanded guild entries are ignored by authoritative acceptance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Social|Guild")
    TArray<FDMFGuildInvite> PendingGuildInvites;
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
