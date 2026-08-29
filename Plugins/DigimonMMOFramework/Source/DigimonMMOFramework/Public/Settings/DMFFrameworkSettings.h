#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DMFFrameworkSettings.generated.h"

class UDMFStarterRosterData;
class UDMFLoginMainMenuWidget;
class UUserWidget;
class UDMFStarterSelectionWidget;
class UDMFCombatQuickBarWidget;
class UDMFPartyQuickBarWidget;
class UDMFDigimonInventoryWidget;
class UDMFScanNotificationWidget;
class UDMFExperienceNotificationWidget;
class UDMFHomeTeleportNotificationWidget;
class UDMFPlayerSkinSelectionWidget;
class UDMFWorldNameplateWidget;
class UDMFWorldChatWidget;
class UDMFPlayerSocialContextWidget;
class UDMFFriendTrackerWidget;
class UDMFPlayerSkinData;
class ADMFDigimonCarePropActor;
class UStaticMesh;
class USoundBase;
class UNiagaraSystem;
class UParticleSystem;
class UPaperSprite;
class UWorld;
struct FPropertyChangedEvent;

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Digimon MMO Framework"))
class DIGIMONMMOFRAMEWORK_API UDMFFrameworkSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UDMFFrameworkSettings();

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Frontend")
    TSoftObjectPtr<UWorld> FrontendMap;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="World")
    TSoftObjectPtr<UWorld> OpenWorldMap;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Onboarding")
    TSoftObjectPtr<UDMFStarterRosterData> StarterRoster;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFLoginMainMenuWidget> LoginWidgetClass;

    /**
     * Optional project-authored full-screen frontend background. The framework creates this first for the
     * local player and always places it below the login/main-menu layer. Leave unset to use only the map/world.
     * This is the recommended v0.15.0 path; consuming projects do not need to Create Widget in Level Blueprint.
     */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Frontend", meta=(DisplayName="Frontend Background Widget Class"))
    TSubclassOf<UUserWidget> FrontendBackgroundWidgetClass;

    /**
     * Delay after the selected Frontend Background Widget Class has been created and added to the game
     * viewport before the framework login/main-menu layer is created. Set to zero for immediate overlay.
     */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Frontend", meta=(ClampMin="0.0", ClampMax="30.0", Units="s", DisplayName="Frontend UI Startup Delay Seconds"))
    float FrontendUIStartupDelaySeconds = 0.25f;

    /**
     * Optional decorative full-screen dim layer behind the native C++ frontend card. Disabled by default
     * so consuming projects can provide their own world/UMG background without the framework tinting it.
     * Blueprint-authored LoginWidgetClass roots remain entirely project-owned.
     */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Frontend", DisplayName="Show Native Frontend Fullscreen Backdrop")
    bool bShowNativeFrontendFullscreenBackdrop = false;

    /** Opacity used only when the optional native full-screen frontend backdrop is enabled. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Frontend", meta=(EditCondition="bShowNativeFrontendFullscreenBackdrop", ClampMin="0.0", ClampMax="1.0", DisplayName="Native Frontend Backdrop Opacity"))
    float NativeFrontendBackdropOpacity = 0.34f;

    /**
     * Viewport Z-order used by the framework login/main-menu layer. The selected Frontend Background Widget
     * Class is automatically placed 100 Z-order units below this value; no Blueprint Z-order setup is needed.
     */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Frontend", meta=(ClampMin="-100000", ClampMax="100000", DisplayName="Frontend Login/Menu Viewport Z Order"))
    int32 FrontendUIViewportZOrder = 1000;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFStarterSelectionWidget> StarterSelectionWidgetClass;

    /** Native fallback is supplied; assign a Blueprint child to reskin without replacing authority logic. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFPlayerSkinSelectionWidget> PlayerSkinSelectionWidgetClass;

    /** If true, accounts without a saved skin must choose one before starter onboarding/gameplay UI proceeds. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar")
    bool bRequirePlayerSkinSelection = true;

    /** Optional automatic skin when bRequirePlayerSkinSelection is false. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar")
    TSoftObjectPtr<UDMFPlayerSkinData> DefaultPlayerSkin;

    /** Ready-to-use F6 menu toggle. Disable when the project wants to open the menu from its own UI/input. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar")
    bool bEnableDefaultPlayerSkinMenuInput = true;

    /** Master switch for the framework's local third-person camera boom zoom system. Camera distance is never replicated. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Camera|Zoom")
    bool bEnablePlayerCameraZoom = true;

    /** Ready-to-use Mouse Wheel Up/Down zoom binding. Disable when an Enhanced Input mapping supplies zoom instead. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Camera|Zoom", meta=(EditCondition="bEnablePlayerCameraZoom"))
    bool bEnableDefaultPlayerCameraZoomInput = true;

    /** Camera boom distance used when the locally controlled player first enters gameplay or resets zoom. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Camera|Zoom", meta=(EditCondition="bEnablePlayerCameraZoom", ClampMin="0.0", ClampMax="5000.0"))
    float PlayerCameraDefaultBoomLength = 400.0f;

    /** Closest permitted third-person camera distance. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Camera|Zoom", meta=(EditCondition="bEnablePlayerCameraZoom", ClampMin="0.0", ClampMax="5000.0"))
    float PlayerCameraMinimumBoomLength = 220.0f;

    /** Farthest permitted third-person camera distance. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Camera|Zoom", meta=(EditCondition="bEnablePlayerCameraZoom", ClampMin="0.0", ClampMax="10000.0"))
    float PlayerCameraMaximumBoomLength = 850.0f;

    /** Boom-length change requested by one mouse-wheel notch. Positive zoom input moves the camera closer. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Camera|Zoom", meta=(EditCondition="bEnablePlayerCameraZoom", ClampMin="1.0", ClampMax="1000.0"))
    float PlayerCameraMouseWheelZoomStep = 75.0f;

    /** Interpolation speed used when moving toward the requested boom distance. Set to zero for instant zoom. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Camera|Zoom", meta=(EditCondition="bEnablePlayerCameraZoom", ClampMin="0.0", ClampMax="100.0"))
    float PlayerCameraZoomInterpolationSpeed = 14.0f;

    /**
     * When enabled, framework player capsules/meshes and Digimon capsules/meshes ignore ECC_Camera.
     * The spring arm still collides with level/world geometry, but another character can no longer shove the camera inward.
     */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Camera|Collision")
    bool bIgnorePlayersAndDigimonForCameraCollision = true;

    /** Master switch for automatic replicated player-avatar footsteps. Digimon are intentionally not affected. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar|Footsteps")
    bool bEnablePlayerFootsteps = true;

    /**
     * Global player footstep audio asset. A Sound Cue is recommended so projects can randomize samples/pitch
     * and configure spatial attenuation without changing framework code.
     */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar|Footsteps", meta=(EditCondition="bEnablePlayerFootsteps", DisplayName="Player Footstep Sound (Sound Cue Recommended)"))
    TSoftObjectPtr<USoundBase> PlayerFootstepSound;

    /** Minimum grounded horizontal movement speed required before footsteps accumulate. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar|Footsteps|Cadence", meta=(EditCondition="bEnablePlayerFootsteps", ClampMin="0.0", ClampMax="1000.0"))
    float PlayerFootstepMinimumSpeed = 35.0f;

    /** Approximate distance travelled between normal walking footsteps. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar|Footsteps|Cadence", meta=(EditCondition="bEnablePlayerFootsteps", ClampMin="25.0", ClampMax="500.0"))
    float PlayerFootstepWalkStrideDistance = 150.0f;

    /** Approximate distance travelled between sprinting footsteps. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar|Footsteps|Cadence", meta=(EditCondition="bEnablePlayerFootsteps", ClampMin="25.0", ClampMax="500.0"))
    float PlayerFootstepSprintStrideDistance = 175.0f;

    /** Approximate distance travelled between crouched footsteps. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar|Footsteps|Cadence", meta=(EditCondition="bEnablePlayerFootsteps", ClampMin="25.0", ClampMax="500.0"))
    float PlayerFootstepCrouchStrideDistance = 120.0f;

    /** Global gain applied after any volume/randomization authored inside the assigned Sound Cue. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar|Footsteps|Presentation", meta=(EditCondition="bEnablePlayerFootsteps", ClampMin="0.0", ClampMax="4.0"))
    float PlayerFootstepVolumeMultiplier = 1.0f;

    /** Global pitch multiplier applied after any pitch/randomization authored inside the assigned Sound Cue. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Player Avatar|Footsteps|Presentation", meta=(EditCondition="bEnablePlayerFootsteps", ClampMin="0.25", ClampMax="4.0"))
    float PlayerFootstepPitchMultiplier = 1.0f;

    /** Master switch for the automatic local music-state system. Music is presentation-only and never replicated. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music")
    bool bEnableFrameworkMusic = true;

    /** Music used while the configured FrontendMap is active. Author the cue/wave to loop, or leave automatic replay enabled below. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Tracks", meta=(EditCondition="bEnableFrameworkMusic", DisplayName="Frontend / Main Menu Music"))
    TSoftObjectPtr<USoundBase> FrontendMusic;

    /** Default exploration music used in the configured OpenWorldMap whenever the local partner is not in combat. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Tracks", meta=(EditCondition="bEnableFrameworkMusic", DisplayName="Open World Music"))
    TSoftObjectPtr<USoundBase> OpenWorldMusic;

    /** Combat music used while the local active partner is in replicated combat. Falls back to Open World Music when unassigned. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Tracks", meta=(EditCondition="bEnableFrameworkMusic", DisplayName="Battle Music"))
    TSoftObjectPtr<USoundBase> BattleMusic;

    /** Global music gain applied before the per-state volume multipliers below. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Mix", meta=(EditCondition="bEnableFrameworkMusic", ClampMin="0.0", ClampMax="2.0"))
    float MusicMasterVolume = 1.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Mix", meta=(EditCondition="bEnableFrameworkMusic", ClampMin="0.0", ClampMax="2.0"))
    float FrontendMusicVolume = 1.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Mix", meta=(EditCondition="bEnableFrameworkMusic", ClampMin="0.0", ClampMax="2.0"))
    float OpenWorldMusicVolume = 1.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Mix", meta=(EditCondition="bEnableFrameworkMusic", ClampMin="0.0", ClampMax="2.0"))
    float BattleMusicVolume = 1.0f;

    /** Symmetric crossfade used when switching Frontend/Open World/Battle music. Set to zero for an immediate cut. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Transitions", meta=(EditCondition="bEnableFrameworkMusic", ClampMin="0.0", ClampMax="10.0"))
    float MusicCrossfadeSeconds = 1.25f;

    /** Keeps Battle music active briefly after the authoritative battle encounter actually ends before returning to Open World. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Transitions", meta=(EditCondition="bEnableFrameworkMusic", ClampMin="0.0", ClampMax="10.0"))
    float BattleMusicReleaseDelaySeconds = 1.5f;

    /** If a configured track reaches its natural end, restart it automatically. Internally-looped Sound Cues work normally too. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Audio|Music|Playback", meta=(EditCondition="bEnableFrameworkMusic"))
    bool bAutomaticallyLoopMusic = true;

    /** Local presentation polling interval. Encounter truth still comes from the replicated partner CombatComponent. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Audio|Music|Performance", meta=(EditCondition="bEnableFrameworkMusic", ClampMin="0.05", ClampMax="1.0"))
    float MusicStateEvaluationInterval = 0.20f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Account")
    FString AccountSaveSlot = TEXT("DMF_ServerAccounts");

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Account")
    bool bAutoRegisterUnknownAccounts = true;

    /** Legacy pre-v0.12 active-collection capacity retained for config compatibility. Party capacity is controlled below. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Inventory", meta=(ClampMin="1"))
    int32 MaxActiveDigimonInventory = 30;

    /** Active field roster size. Six matches the classic creature-party convention and the native Party UI. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Party & Bank|Party", meta=(ClampMin="1", ClampMax="6"))
    int32 MaxPartyDigimon = 6;

    /** Maximum persistent Digimon stored in the account Bank/Boxes. Existing oversized saves are never truncated. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Party & Bank|Bank", meta=(ClampMin="1", ClampMax="5000"))
    int32 MaxDigimonBankStorage = 200;

    /** Number of visible Bank slots per native Box page. The polished fallback uses a 6-column grid. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Party & Bank|Bank", meta=(ClampMin="6", ClampMax="60"))
    int32 DigimonBankSlotsPerPage = 30;

    /** Default safety policy. Disable only if the project intentionally supports mid-combat partner/Bank swaps. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Party & Bank|Rules")
    bool bAllowPartySwitchingDuringCombat = false;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Partner")
    FVector PartnerSpawnOffset = FVector(150.0, 120.0, 0.0);

    /** Master switch for server-authoritative owned-Digimon EXP consumption and level growth. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Progression|Leveling")
    bool bEnableOwnedDigimonLeveling = true;

    /** Global level cap used when a species does not provide MaxLevelOverride. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Progression|Leveling", meta=(EditCondition="bEnableOwnedDigimonLeveling", ClampMin="1", ClampMax="999"))
    int32 DefaultMaxDigimonLevel = 99;

    /** Native Fortnite-style owner-only EXP progress/level-up presentation; assign a Blueprint child to fully reskin it. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Progression")
    TSubclassOf<UDMFExperienceNotificationWidget> ExperienceNotificationWidgetClass;

    /** Master switch for the native EXP gain and LEVEL UP presentation. Gameplay leveling remains authoritative when disabled. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Progression")
    bool bShowNativeExperienceNotifications = true;

    /** Time used to animate the current-level EXP bar toward the authoritative result. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Progression|Presentation", meta=(EditCondition="bShowNativeExperienceNotifications", ClampMin="0.05", ClampMax="5.0"))
    float ExperienceProgressAnimationSeconds = 1.10f;

    /** Hold time after the bar finishes when no level was gained. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Progression|Presentation", meta=(EditCondition="bShowNativeExperienceNotifications", ClampMin="0.1", ClampMax="10.0"))
    float ExperienceNotificationHoldSeconds = 2.20f;

    /** Longer hold time used when the reward produces one or more level-ups. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Progression|Presentation", meta=(EditCondition="bShowNativeExperienceNotifications", ClampMin="0.1", ClampMax="10.0"))
    float LevelUpNotificationHoldSeconds = 3.40f;

    /** Bottom safe-lane offset for the centered native EXP toast so it clears Party/combat quickbars. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Progression|Presentation", meta=(EditCondition="bShowNativeExperienceNotifications", ClampMin="0.0", ClampMax="1200.0"))
    float ExperienceNotificationBottomSafeOffset = 280.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFCombatQuickBarWidget> CombatQuickBarWidgetClass;

    /** Shows the replicated/interpolated Day/Night world clock inside the native combat ability quick-access header. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Combat Quick Access|World Clock")
    bool bShowCombatQuickBarWorldClock = true;

    /** Adds the compact DAY/NIGHT state beside the 12-hour digital time. The phase comes from DMFDayNightSky. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Combat Quick Access|World Clock", meta=(EditCondition="bShowCombatQuickBarWorldClock"))
    bool bShowCombatQuickBarWorldClockPhase = true;

    /** Persistent six-slot Party HUD. Assign a Blueprint child to reskin it without replacing Party authority. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Party Quick Access")
    TSubclassOf<UDMFPartyQuickBarWidget> PartyQuickBarWidgetClass;

    /** Master switch for the persistent native Party quick-access HUD. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Party Quick Access")
    bool bShowNativePartyQuickBar = true;

    /** Ready-to-use Tab interaction toggle. Disable when Enhanced Input/project UI owns the Party cursor mode. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Party Quick Access", meta=(EditCondition="bShowNativePartyQuickBar"))
    bool bEnableDefaultPartyQuickAccessInput = true;

    /** Bottom safe-lane offset so Party Quick Access sits above the centered combat quickbar by default. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Party Quick Access|Presentation", meta=(EditCondition="bShowNativePartyQuickBar", ClampMin="0.0", ClampMax="1000.0"))
    float PartyQuickBarBottomSafeOffset = 176.0f;


    /** Master switch for the native/Blueprint Return Home action exposed through Party Quick Access. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Party Quick Access|Home")
    bool bEnablePartyQuickAccessHomeButton = true;

    /** Server-side anti-spam cooldown. The client never supplies a destination or bypasses this timer. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Party Quick Access|Home", meta=(EditCondition="bEnablePartyQuickAccessHomeButton", ClampMin="0.0", ClampMax="300.0", Units="s"))
    float HomeTeleportRequestCooldownSeconds = 4.0f;

    /** Owner-only native Home result toast. Assign a Blueprint child to fully reskin the presentation. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Party Quick Access|Home")
    TSubclassOf<UDMFHomeTeleportNotificationWidget> HomeTeleportNotificationWidgetClass;

    /** Shows a transient owner-only success/failure toast after the authoritative Home request resolves. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Party Quick Access|Home")
    bool bShowNativeHomeTeleportNotifications = true;

    /** Hold time for the Home teleport result toast. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Party Quick Access|Home", meta=(EditCondition="bShowNativeHomeTeleportNotifications", ClampMin="0.25", ClampMax="15.0", Units="s"))
    float HomeTeleportNotificationHoldSeconds = 3.0f;

    /** Native roster/partner menu fallback; assign a Blueprint child to fully reskin it. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFDigimonInventoryWidget> DigimonInventoryWidgetClass;

    /** Master switch for the read-only native DigiDex encyclopedia tab. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|DigiDex")
    bool bEnableDigiDex = true;

    /** Ready-to-use I-key toggle for the tabbed Digimon menu. Disable for project-owned input. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    bool bEnableDefaultDigimonInventoryMenuInput = true;

    /** Master switch for persistent server-authoritative friends, ignore lists, guilds and friend tracking. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Social")
    bool bEnableSocialSystem = true;

    /** Allows the native player nameplate to open the social action menu while the local cursor is active. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Social|Nameplate Context", meta=(EditCondition="bEnableSocialSystem"))
    bool bEnablePlayerNameplateSocialContext = true;

    /** Native fallback is supplied; assign a Blueprint child to reskin player-nameplate social actions. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Social|Nameplate Context", meta=(EditCondition="bEnableSocialSystem && bEnablePlayerNameplateSocialContext"))
    TSubclassOf<UDMFPlayerSocialContextWidget> PlayerSocialContextWidgetClass;

    /** Native fallback is supplied; each enabled friend tracker is created only on the owning client. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Social|Friend Tracking", meta=(EditCondition="bEnableSocialSystem"))
    TSubclassOf<UDMFFriendTrackerWidget> FriendTrackerWidgetClass;

    /** Additional vertical offset above the normal player nameplate for the owner-local friend distance marker. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Social|Friend Tracking", meta=(EditCondition="bEnableSocialSystem", ClampMin="0.0", ClampMax="1000.0"))
    float FriendTrackerHeightOffset = 64.0f;

    /** Local-only tracker reconciliation cadence. Distance text itself refreshes independently inside the widget. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Social|Friend Tracking", meta=(EditCondition="bEnableSocialSystem", ClampMin="0.2", ClampMax="5.0", Units="s"))
    float FriendTrackerReconcileInterval = 0.75f;

    /** Global radius used by Social -> Friends & Ignore to discover replicated nearby players, nearest first. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Social|Nearby Players", meta=(EditCondition="bEnableSocialSystem", ClampMin="1.0", ClampMax="100000.0", UIMin="5.0", UIMax="5000.0", Units="m", DisplayName="Nearby Player Friend Discovery Radius"))
    float NearbyPlayerFriendDiscoveryRadiusMeters = 50.0f;

    /** Owner-local refresh cadence for the Nearby Players list. No network polling is performed. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|Social|Nearby Players", meta=(EditCondition="bEnableSocialSystem", ClampMin="0.1", ClampMax="5.0", Units="s", DisplayName="Nearby Player List Refresh Interval"))
    float NearbyPlayerFriendDiscoveryRefreshInterval = 0.5f;

    /** Minimum authority-side interval between Social mutations from one client. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Social|Limits", meta=(EditCondition="bEnableSocialSystem", ClampMin="0.05", ClampMax="5.0", Units="s"))
    float MinimumSocialActionInterval = 0.15f;

    /** Minimum interval between explicit owner Social snapshot requests; authoritative push refreshes are unaffected. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Social|Limits", meta=(EditCondition="bEnableSocialSystem", ClampMin="0.1", ClampMax="5.0", Units="s"))
    float MinimumSocialSnapshotRequestInterval = 0.35f;

    /** Persistent friend cap enforced by the server for both participants. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Social|Limits", meta=(EditCondition="bEnableSocialSystem", ClampMin="1", ClampMax="1000"))
    int32 MaximumFriendsPerAccount = 200;

    /** Persistent ignore-list cap enforced by the server. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Social|Limits", meta=(EditCondition="bEnableSocialSystem", ClampMin="1", ClampMax="1000"))
    int32 MaximumIgnoredPlayersPerAccount = 200;

    /** Maximum members in one guild, including the owner. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Social|Guild|Limits", meta=(EditCondition="bEnableSocialSystem", ClampMin="2", ClampMax="1000"))
    int32 MaximumGuildMembers = 100;

    /** Maximum pending guild invitations retained by one account. Prevents unbounded offline invite growth. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Social|Guild|Limits", meta=(EditCondition="bEnableSocialSystem", ClampMin="1", ClampMax="1000"))
    int32 MaximumPendingGuildInvitesPerAccount = 100;

    /** Maximum pending join applications retained by one guild. Prevents unbounded persistent request growth. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Social|Guild|Limits", meta=(EditCondition="bEnableSocialSystem", ClampMin="1", ClampMax="5000"))
    int32 MaximumPendingGuildApplicationsPerGuild = 500;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Social|Guild|Naming", meta=(EditCondition="bEnableSocialSystem", ClampMin="1", ClampMax="32"))
    int32 MinimumGuildNameLength = 3;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Social|Guild|Naming", meta=(EditCondition="bEnableSocialSystem", ClampMin="3", ClampMax="64"))
    int32 MaximumGuildNameLength = 32;

    /** Native scan reward toast fallback; assign a Blueprint child to fully reskin it. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    TSubclassOf<UDMFScanNotificationWidget> ScanNotificationWidgetClass;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
    bool bShowNativeScanNotifications = true;

    /** Master switch for the native server-authoritative MMO world chat system. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat")
    bool bEnableWorldChat = true;

    /** Ready-to-use Enter-key chat focus. Disable when the project owns its own chat input routing. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat", meta=(EditCondition="bEnableWorldChat"))
    bool bEnableDefaultWorldChatInput = true;

    /** Native fallback is supplied; assign a Blueprint child to reskin chat without replacing validation/networking. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat", meta=(EditCondition="bEnableWorldChat"))
    TSubclassOf<UDMFWorldChatWidget> WorldChatWidgetClass;

    /** Automatically publish authenticated join/relogin and leave events into WORLD chat from server login/logout authority. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Presence", meta=(EditCondition="bEnableWorldChat", DisplayName="Announce Player Join / Leave"))
    bool bEnableWorldChatPresenceAnnouncements = true;

    /** Play the configured join/leave cue locally when a live server presence event is received. History replay never triggers audio. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Presence|Audio", meta=(EditCondition="bEnableWorldChat && bEnableWorldChatPresenceAnnouncements", DisplayName="Play Player Join / Leave Sounds"))
    bool bEnableWorldChatPresenceSounds = true;

    /** Global 2D Sound Cue/Wave played once on every connected recipient when an authenticated player joins or relogs. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Presence|Audio", meta=(EditCondition="bEnableWorldChat && bEnableWorldChatPresenceAnnouncements && bEnableWorldChatPresenceSounds", DisplayName="Player Joined Server Sound"))
    TSoftObjectPtr<USoundBase> WorldChatPlayerJoinedSound;

    /** Global 2D Sound Cue/Wave played once on every remaining connected recipient when an authenticated player leaves. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Presence|Audio", meta=(EditCondition="bEnableWorldChat && bEnableWorldChatPresenceAnnouncements && bEnableWorldChatPresenceSounds", DisplayName="Player Left Server Sound"))
    TSoftObjectPtr<USoundBase> WorldChatPlayerLeftSound;

    /** Shared gain applied to both live world-chat presence sounds after any Sound Cue-authored volume. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Presence|Audio", meta=(EditCondition="bEnableWorldChat && bEnableWorldChatPresenceAnnouncements && bEnableWorldChatPresenceSounds", ClampMin="0.0", ClampMax="4.0", DisplayName="Presence Sound Volume Multiplier"))
    float WorldChatPresenceSoundVolumeMultiplier = 1.0f;

    /** Shared pitch multiplier applied to both live world-chat presence sounds after any Sound Cue-authored pitch. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Presence|Audio", meta=(EditCondition="bEnableWorldChat && bEnableWorldChatPresenceAnnouncements && bEnableWorldChatPresenceSounds", ClampMin="0.25", ClampMax="4.0", DisplayName="Presence Sound Pitch Multiplier"))
    float WorldChatPresenceSoundPitchMultiplier = 1.0f;

    /** Maximum accepted player message length after server sanitation. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Safety", meta=(EditCondition="bEnableWorldChat", ClampMin="32", ClampMax="1000"))
    int32 WorldChatMaxMessageLength = 220;

    /** Local client-side visible history cap. This is presentation state and is not continuously replicated. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|History", meta=(EditCondition="bEnableWorldChat", ClampMin="10", ClampMax="500"))
    int32 WorldChatClientHistoryLimit = 100;

    /** Session history retained by the authoritative GameMode and sent once to late joiners. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|History", meta=(EditCondition="bEnableWorldChat", ClampMin="0", ClampMax="250"))
    int32 WorldChatServerHistoryLimit = 50;

    /** Minimum authoritative interval between accepted messages from one player. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Safety", meta=(EditCondition="bEnableWorldChat", ClampMin="0.1", ClampMax="10.0"))
    float WorldChatMinimumSendInterval = 0.65f;

    /** Sliding server window used by the burst limiter. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Safety", meta=(EditCondition="bEnableWorldChat", ClampMin="1.0", ClampMax="60.0"))
    float WorldChatBurstWindowSeconds = 10.0f;

    /** Maximum accepted messages from one player inside the configured burst window. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Safety", meta=(EditCondition="bEnableWorldChat", ClampMin="1", ClampMax="60"))
    int32 WorldChatMaxMessagesPerBurst = 8;

    /** Optional compact UTC HH:MM prefix. Disabled by default for the cleanest WoW-style presentation. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Presentation", meta=(EditCondition="bEnableWorldChat"))
    bool bShowWorldChatTimestamps = false;

    /** Bottom safe-zone used by the native WORLD chat so it clears the centered combat quick-access HUD. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Chat|Presentation", meta=(EditCondition="bEnableWorldChat", ClampMin="30.0", ClampMax="600.0"))
    float WorldChatBottomSafeOffset = 176.0f;

    /** Master switch for all automatic world-space MMO nameplates. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates")
    bool bEnableWorldNameplates = true;

    /** Show authenticated player usernames above replicated player avatars. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Players", meta=(EditCondition="bEnableWorldNameplates"))
    bool bEnablePlayerNameplates = true;

    /** Local players normally do not need their own overhead username. Enable for debugging/specific MMO presentation. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Players", meta=(EditCondition="bEnableWorldNameplates && bEnablePlayerNameplates"))
    bool bShowLocalPlayerNameplate = false;

    /** Maximum camera distance at which player nameplates render. Zero disables distance culling. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Players", meta=(EditCondition="bEnableWorldNameplates && bEnablePlayerNameplates", ClampMin="0.0"))
    float PlayerNameplateMaxDrawDistance = 6000.0f;

    /** Additional height above the avatar collision capsule. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Players", meta=(EditCondition="bEnableWorldNameplates && bEnablePlayerNameplates", ClampMin="0.0", ClampMax="500.0"))
    float PlayerNameplateHeightOffset = 34.0f;

    /** Native fallback is supplied; assign a Blueprint child to reskin player plates without replacing actor/network logic. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Players", meta=(EditCondition="bEnableWorldNameplates && bEnablePlayerNameplates"))
    TSubclassOf<UDMFWorldNameplateWidget> PlayerNameplateWidgetClass;

    /** Show compact Digimon name/level/type/health plates above owned and wild Digimon. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Digimon", meta=(EditCondition="bEnableWorldNameplates"))
    bool bEnableDigimonNameplates = true;

    /** Maximum camera distance at which Digimon nameplates render. Zero disables distance culling. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Digimon", meta=(EditCondition="bEnableWorldNameplates && bEnableDigimonNameplates", ClampMin="0.0"))
    float DigimonNameplateMaxDrawDistance = 4500.0f;

    /** Additional height above each Digimon collision capsule, allowing differently sized species to position cleanly. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Digimon", meta=(EditCondition="bEnableWorldNameplates && bEnableDigimonNameplates", ClampMin="0.0", ClampMax="500.0"))
    float DigimonNameplateHeightOffset = 24.0f;

    /** Keep the health readout compact: disable this to show only the slim health bar. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Digimon", meta=(EditCondition="bEnableWorldNameplates && bEnableDigimonNameplates"))
    bool bShowDigimonNumericHealthOnNameplates = true;

    /** Native fallback is supplied; assign a Blueprint child to reskin Digimon plates without replacing combat/network logic. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Digimon", meta=(EditCondition="bEnableWorldNameplates && bEnableDigimonNameplates"))
    TSubclassOf<UDMFWorldNameplateWidget> DigimonNameplateWidgetClass;

    /** Throttled presentation refresh interval. Actor state itself continues to replicate at its normal framework cadence. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI|World Nameplates|Performance", meta=(EditCondition="bEnableWorldNameplates", ClampMin="0.05", ClampMax="1.0"))
    float WorldNameplateRefreshInterval = 0.15f;

    /** Master switch for the persistent Scan Data / Materialization system. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Scan & Materialization")
    bool bEnableScanAndMaterialization = true;

    /** Default MMO rule: only framework Wild Digimon victories award Scan Data. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Scan & Materialization")
    bool bAwardScanDataFromWildVictoriesOnly = true;

    /** Master switch for persistent virtual-pet care, feeding and world waste. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Care")
    bool bEnableCareSystem = true;

    /** Authoritative care maintenance cadence. Hunger decay uses UTC deltas, so this does not affect progression accuracy. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Care", meta=(ClampMin="1.0", ClampMax="60.0"))
    float CareServerTickInterval = 10.0f;

    /** Small delay after the owner UI is hidden before the first eating Montage begins. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Care|Feeding", meta=(ClampMin="0.0", ClampMax="5.0"))
    float CarePresentationLeadInSeconds = 0.35f;

    /** Pause between complete DigiMeat servings while Feed Until Full is looping. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Care|Feeding", meta=(ClampMin="0.0", ClampMax="5.0"))
    float CareInterServingPauseSeconds = 0.20f;

    /** Used only when a feeding Montage is assigned but returns an unusable duration. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Care|Feeding", meta=(ClampMin="0.1", ClampMax="10.0"))
    float CareFallbackMontageDurationSeconds = 1.0f;

    /** Global DigiMeat mesh. A species can override this while keeping its own socket transform/scale. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Care|Presentation")
    TSoftObjectPtr<UStaticMesh> DefaultDigiMeatMesh;

    /** Global poo mesh. A species can override this and always controls its own world scale. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Care|Presentation")
    TSoftObjectPtr<UStaticMesh> DefaultPooMesh;

    /** Blueprint-replaceable replicated prop actor used for both attached DigiMeat and no-collision world poo. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Care|Presentation")
    TSubclassOf<ADMFDigimonCarePropActor> CarePropActorClass;

    // -------------------- Digivolution --------------------

    /** Master switch for persistent server-authoritative Digivolution. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution")
    bool bEnableDigivolutionSystem = true;

    /** Allows stored Bank/Box Digimon to Digivolve from the world-accessible Digimon Menu. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Rules", meta=(EditCondition="bEnableDigivolutionSystem"))
    bool bAllowBankDigivolution = true;

    /** Active summoned partners must be idle before a Digivolution sequence can begin. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Rules", meta=(EditCondition="bEnableDigivolutionSystem"))
    bool bBlockDigivolutionDuringCombat = true;

    /** Hide modal/HUD UI while a summoned partner performs its in-world transformation presentation. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Presentation", meta=(EditCondition="bEnableDigivolutionSystem"))
    bool bHideUIForSummonedDigivolution = true;

    /** Default duration before an active world partner is replaced by the target form. A path may override this. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Presentation", meta=(EditCondition="bEnableDigivolutionSystem", ClampMin="0.25", ClampMax="20.0"))
    float DigivolutionPresentationDurationSeconds = 3.0f;

    /** Preferred global transformation VFX. Individual evolution paths can override this. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Presentation|VFX", meta=(EditCondition="bEnableDigivolutionSystem"))
    TSoftObjectPtr<UNiagaraSystem> DefaultDigivolutionNiagaraSystem;

    /** Cascade fallback when no path/global Niagara system is assigned or Niagara preference is disabled. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Presentation|VFX", meta=(EditCondition="bEnableDigivolutionSystem"))
    TSoftObjectPtr<UParticleSystem> DefaultDigivolutionCascadeParticle;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Presentation|VFX", meta=(EditCondition="bEnableDigivolutionSystem"))
    bool bPreferNiagaraDigivolutionVFX = true;

    /** Global transformation Sound Cue/Wave. Individual paths can override it. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Presentation|Audio", meta=(EditCondition="bEnableDigivolutionSystem"))
    TSoftObjectPtr<USoundBase> DefaultDigivolutionSound;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Presentation|Audio", meta=(EditCondition="bEnableDigivolutionSystem", ClampMin="0.0", ClampMax="4.0"))
    float DigivolutionSoundVolumeMultiplier = 1.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Digivolution|Presentation|Audio", meta=(EditCondition="bEnableDigivolutionSystem", ClampMin="0.25", ClampMax="4.0"))
    float DigivolutionSoundPitchMultiplier = 1.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat")
    bool bShowNativeCombatQuickBar = true;

    /** Master switch for local owner-only active-partner and enemy-target selection presentation. No targeting visuals are replicated. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals")
    bool bEnableCombatTargetingVisuals = true;

    /** Shows the project's blue selection-ring PaperSprite under this local player's currently summoned active partner only. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Active Partner", meta=(EditCondition="bEnableCombatTargetingVisuals"))
    bool bShowActivePartnerTargetingRing = true;

    /** Blue PaperSprite used beneath the owning player's active partner. Assign CircleRing_T_Sprite (or equivalent) here. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Active Partner", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowActivePartnerTargetingRing"))
    TSoftObjectPtr<UPaperSprite> ActivePartnerTargetingRingSprite;

    /** Additional local-space sprite scale before optional capsule-size adaptation. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Active Partner", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowActivePartnerTargetingRing"))
    FVector ActivePartnerTargetingRingScale = FVector(1.0f, 1.0f, 1.0f);

    /** Height above the Digimon capsule bottom, useful for preventing translucent z-fighting with the floor. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Active Partner", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowActivePartnerTargetingRing", ClampMin="-50.0", ClampMax="100.0"))
    float ActivePartnerTargetingRingGroundOffset = 3.0f;

    /** Continuous world-Z spin speed. Positive and negative values rotate in opposite directions. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Active Partner", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowActivePartnerTargetingRing", ClampMin="-720.0", ClampMax="720.0"))
    float ActivePartnerTargetingRingRotationDegreesPerSecond = 28.0f;

    /** Shows the project's hostile/selected target PaperSprite beneath only this local player's current command target. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Target", meta=(EditCondition="bEnableCombatTargetingVisuals"))
    bool bShowEnemyTargetingRing = true;

    /** Enemy-target PaperSprite used beneath the currently selected hostile Digimon. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Target", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetingRing"))
    TSoftObjectPtr<UPaperSprite> EnemyTargetingRingSprite;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Target", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetingRing"))
    FVector EnemyTargetingRingScale = FVector(1.0f, 1.0f, 1.0f);

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Target", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetingRing", ClampMin="-50.0", ClampMax="100.0"))
    float EnemyTargetingRingGroundOffset = 4.0f;

    /** Default rotates opposite/faster than the active-partner ring for stronger visual separation. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Target", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetingRing", ClampMin="-720.0", ClampMax="720.0"))
    float EnemyTargetingRingRotationDegreesPerSecond = -42.0f;

    /** PaperSprite assets normally face the X/Z plane; Roll=90 lays them flat while a parent pivot performs clean world-Z rotation. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Rings", meta=(EditCondition="bEnableCombatTargetingVisuals"))
    FRotator TargetingRingSpriteRelativeRotation = FRotator(0.0f, 0.0f, 90.0f);

    /** Automatically adapts both ring sizes to very small/large Digimon capsule radii. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Rings", meta=(EditCondition="bEnableCombatTargetingVisuals"))
    bool bScaleTargetingRingsToDigimonCapsule = true;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Rings", meta=(EditCondition="bEnableCombatTargetingVisuals && bScaleTargetingRingsToDigimonCapsule", ClampMin="1.0", ClampMax="500.0"))
    float TargetingRingReferenceCapsuleRadius = 42.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Rings", meta=(EditCondition="bEnableCombatTargetingVisuals && bScaleTargetingRingsToDigimonCapsule", ClampMin="0.05", ClampMax="10.0"))
    float TargetingRingMinimumAutoScale = 0.65f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Rings", meta=(EditCondition="bEnableCombatTargetingVisuals && bScaleTargetingRingsToDigimonCapsule", ClampMin="0.05", ClampMax="20.0"))
    float TargetingRingMaximumAutoScale = 3.0f;

    /** Slate/render priority for translucent PaperSprite rings. Enemy ring uses this value + 1. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Rings", meta=(EditCondition="bEnableCombatTargetingVisuals", ClampMin="-100", ClampMax="100"))
    int32 TargetingVisualTranslucentSortPriority = 10;

    /** Shows the hovering down-arrow effect over the current local command target. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Arrow", meta=(EditCondition="bEnableCombatTargetingVisuals"))
    bool bShowEnemyTargetArrow = true;

    /** Niagara is preferred when both Niagara and Cascade assets are supplied. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Arrow", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetArrow"))
    bool bPreferNiagaraEnemyTargetArrow = true;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Arrow", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetArrow"))
    TSoftObjectPtr<UNiagaraSystem> EnemyTargetArrowNiagaraSystem;

    /** Legacy/fallback particle system used when Niagara is unassigned or not preferred. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Arrow", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetArrow"))
    TSoftObjectPtr<UParticleSystem> EnemyTargetArrowCascadeSystem;

    /** Additional distance above the top of the target capsule. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Arrow", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetArrow", ClampMin="-200.0", ClampMax="1000.0"))
    float EnemyTargetArrowHeightOffset = 60.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Arrow", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetArrow"))
    FVector EnemyTargetArrowScale = FVector(1.0f, 1.0f, 1.0f);

    /** Rotation correction for arrow VFX authored in a different local axis. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Arrow", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetArrow"))
    FRotator EnemyTargetArrowRotation = FRotator::ZeroRotator;

    /** Native vertical hovering amplitude. Set to zero if the Niagara/Cascade system already performs its own bob animation. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Arrow", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetArrow", ClampMin="0.0", ClampMax="200.0"))
    float EnemyTargetArrowBobAmplitude = 10.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Targeting Visuals|Enemy Arrow", meta=(EditCondition="bEnableCombatTargetingVisuals && bShowEnemyTargetArrow", ClampMin="0.0", ClampMax="10.0"))
    float EnemyTargetArrowBobFrequencyHz = 1.5f;

    /** Master switch for the framework's legacy/default controller combat bindings. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Input")
    bool bEnableDefaultCombatInputBindings = true;

    /** Legacy Left-Mouse target selection. Disabled by default in v0.5.2 because player Interact/E is the preferred target flow. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Input")
    bool bEnableDefaultClickTargetInput = false;

    /** Ready-to-use number-key ability commands (1-4). Keep enabled when using E/Interact for target selection. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Input")
    bool bEnableDefaultAbilitySlotInput = true;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat")
    FName PlayerCombatTeamId = TEXT("Players");

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0.1"))
    float CombatAutomationInterval = 0.25f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0.0"))
    float MinimumCombatCommandInterval = 0.05f;

    /** Maximum time an out-of-range player ability command may remain queued while the partner chases. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0.5"))
    float CombatCommandQueueTimeout = 8.0f;

    /** Owned partners never auto-acquire/auto-attack by default. Manual Blueprint/quick-slot commands still chase and execute. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner")
    bool bPlayerPartnerAutoBattle = false;

    /** Used only when player-partner auto battle is deliberately enabled at runtime/project level. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner", meta=(ClampMin="0.0"))
    float PartnerAggroRange = 1200.0f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner", meta=(ClampMin="0.0"))
    float PartnerLeashRange = 2500.0f;

    /** Player-owned partner damage multiplier. 1.50 gives an intentional MMORPG/JRPG advantage over equal-level wild encounters. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner|Balance", meta=(ClampMin="0.0"))
    float PlayerPartnerOutgoingDamageMultiplier = 1.50f;

    /** Incoming combat damage multiplier for player-owned partners. 0.50 means they take half normal Digimon combat damage. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Combat|Player Partner|Balance", meta=(ClampMin="0.0"))
    float PlayerPartnerIncomingDamageMultiplier = 0.50f;

    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Persistence", meta=(ClampMin="5.0"))
    float AccountAutosaveInterval = 30.0f;

    /** Server-owned world-state slot used by persistent shared systems such as the simulated Day/Night clock. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Persistence|World State")
    FString WorldStateSaveSlot = TEXT("DMF_ServerWorldState");

    /**
     * Saves each authenticated player's authoritative gameplay location/rotation into their account and restores it
     * when they return to the same gameplay map. Uses the normal account autosave interval plus logout checkpoints.
     */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Persistence|Player World Location")
    bool bEnablePlayerWorldLocationPersistence = true;

    /**
     * Accounts with no saved world location are placed at an enabled DMFNewPlayerStart before their first checkpoint.
     * Disable only when a project wants Unreal's ordinary PlayerStart flow for brand-new accounts.
     */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Persistence|Player World Location")
    bool bUseDedicatedNewPlayerSpawn = true;

    /**
     * Public IPv4 address or DNS hostname that normal players use when Join Game is pressed.
     * The admin listen host must be reachable at this address through the project's normal router/firewall/NAT setup.
     * This is intentionally project-configurable so deployments never need to edit plugin C++ just to change endpoint.
     */
    UPROPERTY(Config, EditAnywhere, Category="Networking|Server Endpoint", meta=(DisplayName="Server Public Address / Hostname", ToolTip="Public IPv4 address or DNS hostname players use to reach the admin listen host. Enter only the host name/address; configure the port separately below."))
    FString ServerPublicAddress = TEXT("DigimonMMO3D.custom-gaming.net");

    /** Connection port appended to Server Public Address for Join Game. It must match the port exposed/forwarded by the host deployment. */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Networking|Server Endpoint", meta=(DisplayName="Game Port", ClampMin="1", ClampMax="65535"))
    int32 GamePort = 7777;

    /**
     * Global server-authoritative cap for simultaneously connected gameplay players.
     * The listen host consumes one slot. New connections are refused by GameSession once this limit is reached;
     * existing connected players are never kicked merely because an editor/runtime config change lowers the cap.
     */
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Networking|Server Capacity", meta=(DisplayName="Global Maximum Players", ClampMin="1", ClampMax="10000", UIMin="1", UIMax="1000", ToolTip="Maximum number of simultaneously connected gameplay players allowed on the authoritative server. The listen host counts as one player. Default: 100."))
    int32 GlobalMaxPlayers = 100;

    /**
     * Editor-only password setter for the local Admin Host & Play gate.
     * Entering a new value hashes it immediately into AdminHostingPasswordDigest and clears this field, so plaintext is not retained in project config.
     */
    UPROPERTY(EditAnywhere, Transient, Category="Networking|Admin Hosting", meta=(DisplayName="Set Admin Hosting Password", PasswordField="true", ToolTip="Enter a new 4-128 character password for the Admin Host & Play gate. The framework stores only its one-way digest and clears this field after the Project Settings change is applied."))
    FString AdminHostingPasswordInput;

    /** One-way digest used by the local Admin frontend gate. Hidden from normal Project Settings editing. */
    UPROPERTY(Config)
    FString AdminHostingPasswordDigest = TEXT("44d5c8be1c38b3c4b3030eab3666607d4db5983a");

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
