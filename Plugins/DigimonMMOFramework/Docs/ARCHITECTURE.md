# Architecture

## Global music presentation director (v0.11.0)

`UDMFMusicSubsystem` is a GameInstance-lifetime, local presentation subsystem that resolves one semantic state: `Frontend`, `OpenWorld`, `Battle` or `None`. It survives normal frontend/gameplay travel and owns persistent 2D AudioComponents so state changes can crossfade rather than hard-cut.

Map context comes from the configured `FrontendMap` / `OpenWorldMap` with framework GameMode/PlayerController fallbacks. Battle context comes only from the local active partner's existing replicated `UDMFDigimonCombatComponent::CombatState`; `Chasing`, `Attacking` and `Recovering` are active battle states. A selected target alone is not. A short local release delay de-bounces the return to exploration music.

The subsystem never authors combat state and adds no replicated music variable/RPC. Every client derives its own soundtrack from already replicated gameplay truth, allowing nearby players to be in different soundtrack states while preserving one server-authoritative combat simulation. Dedicated servers do not render AudioComponents.

## Authority model

`ADMFMMOGameMode` is the server authority for authenticated entry. `ADMFPlayerState` owns both replicated player-facing state components: `UDMFPlayerAvatarComponent` for the human avatar skin and `UDMFPlayerDigimonComponent` for Digimon collection/partner state. Keeping both on PlayerState preserves ownership across pawn replacement and gives client requests a connection-owned RPC route.

`ADMFPlayerAvatarCharacter` is the ready-to-use replicated third-person gameplay pawn. Character skins are visual Primary Data Assets (`UDMFPlayerSkinData`), not alternate pawn classes. A skin change therefore cannot replace possession, collision authority, inventory ownership or movement code.

## Player footstep presentation architecture

`ADMFPlayerAvatarCharacter` owns the v0.10.4 player-only footstep presentation. It accumulates **grounded horizontal distance travelled** from `CharacterMovement` rather than depending on AnimBP notifies, so all framework player skins and custom/Enhanced Input movement stacks inherit the feature automatically. Walk, sprint and crouch stride distances are project settings; the audio source is placed at the capsule base to avoid skeleton-specific socket assumptions.

A remote owning client predicts only its own local audio for responsiveness. The server performs the same movement-derived cadence independently and sends an Unreliable NetMulticast cosmetic event to observers. The owning remote client ignores that returned multicast, so it never hears a doubled step. This event is presentation-only: movement replication remains Unreal CharacterMovement authority and no durable footstep property or account state is introduced. Digimon classes do not execute this path.

`UDMFPlayerDigimonComponent` owns the active Digimon inventory and active partner state. Inventory replication uses `FFastArraySerializer` with `COND_OwnerOnly` to avoid broadcasting private collection data to every connected player.

The server performs starter validation, constructs the unique Digimon instance, persists it, and spawns the authoritative 3D partner actor. The client never supplies trusted stats or an arbitrary actor class. Partner species resolution prefers UE Asset Manager registration and falls back to the configured starter roster for onboarding.

## World chat architecture

`UDMFWorldChatWidget` is a local presentation surface owned by the local `ADMFMMOPlayerController`. Pressing Enter changes only local input focus; it does not create a client-authoritative chat stream. The client submits raw text to its owned controller Server RPC.

The server controller sanitizes and rate-limits the request, then `ADMFMMOGameMode` resolves the sender's public PlayerState name, stamps server UTC metadata, appends the accepted payload to a bounded in-memory session history, and sends that payload to each framework PlayerController using an owner-targeted Client RPC. This avoids a permanently replicated global transcript and keeps future moderation/channel/backend integrations at an authoritative server boundary.

A late joiner requests history once after local gameplay controller initialization. Client widgets maintain their own bounded display history. No chat data is written into `FDMFAccountRecord`, so chat cannot accidentally become account-save state.

## Manual ability command lifecycle

`UDMFDigimonCombatComponent` owns the authoritative quick-slot lifecycle. A client-owned request reaches the server through `UDMFPlayerDigimonComponent`, then resolves the equipped ability and validates target, leash and current SP. If the move cannot execute immediately because the Digimon is attacking/recovering, the ability is cooling down, the target is out of range, or target-facing is incomplete, the **latest valid command remains buffered on the server**. Automation revalidates the buffer until execution becomes legal or a bounded timeout/permanent invalidation clears it. SP and cooldown mutation happen only inside the successful authoritative execution path. Expired cooldown records are pruned instead of accumulating indefinitely.

## Persistent identity

Species are immutable definitions (`UDMFDigimonSpeciesData`). Captured/materialized/starter Digimon are mutable instances (`FDMFDigimonInstance`) with a unique `FGuid`.

This separation is mandatory for:
- individual level/EXP/stat growth;
- attribute-point spending;
- current HP/SP;
- hunger/care state;
- learned/equipped abilities;
- active inventory vs bank storage;
- evolution history and later individuality systems.

## Account storage

`UDMFAccountPersistenceSubsystem` owns the host-side `UDMFAccountDatabaseSaveGame`. The first alpha uses one SaveGame database for ease of installation. A later database/backend provider can replace storage while retaining the `FDMFAccountRecord` contract.

## Frontend/network flow

1. Blank frontend map runs `ADMFFrontendGameMode`.
2. `ADMFFrontendHUD` creates the native `UDMFLoginMainMenuWidget`.
3. Login locally stages username + credential digest.
4. **Join Game** validates `Server Public Address / Hostname` + `Game Port` from Project Settings, then travels to that configured MMO endpoint with authentication options.
5. Server `PreLogin` validates credentials or auto-registers the account.
6. `InitNewPlayer` hydrates `ADMFPlayerState`, avatar state and Digimon state.
7. If the account requires a player skin, `UDMFPlayerSkinSelectionWidget` appears first and the server validates the selected `DMFPlayerSkin`.
8. Once avatar onboarding is complete, a new account requiring a Starter Digimon automatically sees `UDMFStarterSelectionWidget`.
9. Starter selection is sent as a Server RPC and validated against the configured starter roster.
10. Server creates/persists/spawns the partner; returning players skip completed onboarding stages.

Admin flow uses the same frontend but requires the additional admin unlock before `Host & Play` can start the open-world map with `listen`. v0.10.2 preflights the project-configured player-facing endpoint, and v0.10.3 also moves the Admin hosting password into Project Settings using a transient editor setter that persists only a one-way digest. Endpoint and Admin-host deployment configuration are therefore centralized without moving gameplay authority into UI.

## Expansion points already reserved

The account record contains Digimon bank storage, scan progress, money, ranked points and F→S+ tier. These are deliberately part of the initial schema so later components can extend the existing record instead of inventing parallel saves.

## Primary Asset discovery and packaged builds

`DMFDigimonSpeciesData`, `DMFStarterRosterData`, `DMFDigimonAbilityData` and `DMFPlayerSkinData` return explicit Primary Asset IDs. The consuming project should scan `/Game/DigimonData` for these types and cook them with `AlwaysCook`; a merge-ready `ConfigTemplates/DMF_Project_DefaultGame.ini.snippet` is included. The template intentionally appends entries and never clears the project's existing Asset Manager configuration.

Framework scalar defaults (port, capacities, spawn offset, save slot) live in C++ and can be overridden through **Project Settings → Game → Digimon MMO Framework**.


## Real-time combat layer

`ADMFDigimonCharacter` owns a static replicated `UDMFDigimonCombatComponent`. This component is the single battle runtime for owned partners, wild encounters, NPC teams and future ranked teams.

The server alone mutates HP/SP, cooldowns, targets and defeat state. Player ability requests enter through the owning `ADMFPlayerState -> UDMFPlayerDigimonComponent` connection and are revalidated against the current active partner, target hostility, ability slot, range, SP and cooldown.

Transient animation/VFX/audio are emitted as multicast cosmetic cues. Replicated combat properties remain the durable truth, so a dropped cosmetic packet cannot corrupt gameplay.

Autonomous target acquisition uses a bounded pawn overlap at a configurable interval instead of scanning every actor every frame. Partners use the player's pawn as their follow/leash anchor; wild/NPC Digimon use their spawn location as home.
## Rendering / cel-shading contract

Player-avatar and Digimon presentation bases enforce an always-on Custom Depth contract across their owned `UMeshComponent`s. This is intentionally presentation-local rather than replicated gameplay state. `ADMFPlayerAvatarCharacter` reapplies the contract after every data-driven skin swap; `ADMFDigimonCharacter` reapplies it at construction/BeginPlay and instance/state refresh boundaries. This keeps post-process cel shading deterministic across listen host, remote clients and packaged builds without storing redundant render flags in account saves or network state.



## Wild population / rarity spawning (v0.4.0)

`ADMFWildDigimonSpawner` is an authority-only decision maker wrapped in a replicated world actor. Clients never create wild populations or roll rarity/level. The server periodically counts real player pawns around the spawner, activates with a smaller radius, and unloads only after every required player has exceeded the larger deactivation radius for the configured grace period.

Activation chooses a target population within the designer min/max range. Initial actor creation is staggered. Each spawn selects from currently eligible entries using `rarity base weight * entry multiplier`; finite per-entry live caps are respected, and a fully capped table clamps the target population to the table's theoretical capacity.

Placement samples uniformly over the spawner disk, traces terrain, optionally projects onto NavMesh, rejects points too close to players, then uses collision-aware deferred spawning so Species/Level/rarity/AI/roam/emergence values exist before `BeginPlay`.

Spawner-managed `ADMFWildDigimonCharacter` actors replicate `SpawnRarity`, `SpawnHomeLocation` and ground-transition timing state. Idle roam requests are server-only and timer-driven. Combat automation's existing home/leash snapshot is the same individual spawn position, so roaming and combat share one bounded spatial contract.

Ground emergence is cosmetic-state replication rather than per-frame transform replication: the actor/capsule exists at the valid authoritative ground point while the inherited skeletal mesh interpolates from a negative relative-Z offset using synchronized server time. Combat, movement and collision are gated during the transition. The same mechanism supports optional ground-sink unload before actor destruction.

Defeat marks a managed actor dead immediately for population accounting, retains it for the configured death-presentation time, and creates one delayed replacement token. This separates corpse lifetime from respawn cadence and prevents instant pop-in replacement.


## Native player interaction / targeting (v0.5.2)

`ADMFPlayerAvatarCharacter` now owns the normal interaction entry surface. `Interact()` performs a local camera-forward Visibility trace/sphere sweep, ignores the player and optionally the player's active partner, then internally dispatches supported framework actors. This keeps the project-facing Blueprint contract at the pawn level instead of requiring every project to reconstruct the same controller/PlayerState casts.

A Digimon hit does not create new authority. The player wrapper resolves the local `ADMFMMOPlayerController` and forwards target-only or target+attack intent through the existing owner-routed `UDMFPlayerDigimonComponent` server RPCs. Local prevalidation checks that an active partner exists and that its combat component considers the Digimon hostile/targetable; server validation remains authoritative.

A healer hit is forwarded through the same client-owned PlayerController ingress already used by v0.5.0. `ADMFHealerActor` now owns a native query-only `USphereComponent` interaction volume sized from its separate `InteractionCollisionRadius`, which makes the default player trace usable without depending on cosmetic mesh collision.

The interaction layer exposes generic Actor-taking wrappers (`InteractWithActor`, `InteractWithDigimon`, `InteractWithHealer`, etc.) so Blueprint overlap/UI systems can remain cast-free. `BP_OnUnhandledInteraction` is intentionally non-authoritative extensibility for project-specific actor types.

## Manual owned-partner combat and role balance (v0.5.0)

Owned partners and wild Digimon now share the same combat runtime but no longer share the same automation policy. `UDMFPlayerDigimonComponent::SpawnOrRefreshActivePartner` configures owned partners from framework settings with autonomous battle disabled by default, while `ADMFWildDigimonCharacter` retains its own `bAutoBattle` behavior. The automation tick always maintains follow-anchor locomotion independently of auto battle, so disabling autonomous attacks does not turn the partner into a stationary actor.

Player commands still enter through the owner-routed PlayerState component. `CommandPartnerTargetAndAttack` is an atomic convenience call at the controller layer; the server still performs the existing target, slot, SP, cooldown, leash and impact validations.

Combat role tuning is stored only in the server combat component (`OutgoingDamageMultiplier` / `IncomingDamageMultiplier`). Owned partners receive the project-level values when spawned; Wild Blueprint classes configure their own neutral/default values. The persistent `FDMFDigimonStats` record is not rewritten to achieve battle pacing.

## Digimon roster / summon UI (v0.5.0)

`UDMFDigimonInventoryWidget` is an owner-only presentation surface over the existing Fast Array inventory. It never owns collection authority. Selecting/summoning/recalling calls server RPCs on `UDMFPlayerDigimonComponent`; the server validates that the GUID exists in that player's replicated inventory. Recall destroys only the world actor and deliberately retains `ActivePartnerInstanceId`.

The native fallback is usable immediately and can be replaced by a Blueprint child through framework settings. Full drag/drop party/bank transactions remain separate future work.

## Healer authority (v0.5.0)

`ADMFHealerActor` is a replicated world interaction endpoint. Because a placed healer is not client-owned, clients do not send a Server RPC directly to it. `RequestHeal` routes through the owning `ADMFMMOPlayerController`; the server controller then asks the healer to validate distance, enable state and reuse timing. The healer invokes `UDMFPlayerDigimonComponent::HealAllOwnedDigimon`, which updates active inventory, optional bank storage, the live partner combat component and account persistence. Healer multicast events are cosmetic only.

### v0.5.3 defeated presentation
`UDMFDigimonCombatComponent::CombatState` is the replicated durable authority for defeated presentation. `ADMFDigimonCharacter` owns local montage/final-pose holding, movement/collision presentation and revive cleanup. This separates authoritative HP/state from cosmetic animation while still reconstructing correctly for late relevancy.


## v0.5.5 defeated-pose and wild reactive-combat contracts

Defeat presentation is owned by `ADMFDigimonCharacter`: a valid species Death Montage plays, then the character locks skeletal evaluation at Montage blend-out so both partner and wild subclasses share the same persistent defeated pose contract. Lifecycle owners decide removal/revival separately.

`UDMFDigimonCombatComponent` deliberately separates proactive acquisition (`bAutoBattleEnabled`) from reactive defense (`bRetaliateWhenAttacked` / transient retaliation state). Damage reception can establish a retaliation target without enabling nearest-hostile scans. This allows ordinary wild Digimon to be neutral until attacked while still defending themselves server-authoritatively.

`ADMFWildDigimonCharacter` exposes the designer policy and the spawner resolves it before deferred spawn completion. The recommended default is proactive aggression off and retaliation on.

## v0.6.0 native UI presentation layer

The native UMG fallbacks are now treated as a presentation layer over existing replicated/server-authoritative state rather than debug controls. `DMFNativeUIStyle` is private to the runtime module and provides the common visual language used by frontend, roster, starter, player-skin and combat widgets.

Portrait/icon ownership remains data driven: species portraits live on `DMFDigimonSpeciesData`, player portraits on `DMFPlayerSkinData`, and ability icons on `DMFDigimonAbilityData`. No image reference is replicated as a new gameplay transaction; UI resolves the already-configured Primary Asset locally from replicated IDs.

`UDMFDigimonInventoryWidget` renders the owner-only active Digimon Fast Array as a slot grid and invokes the same `UDMFPlayerDigimonComponent` server RPCs for summon/recall. `UDMFStarterSelectionWidget` and `UDMFPlayerSkinSelectionWidget` retain their existing authoritative selection components. `UDMFCombatQuickBarWidget` remains a local presentation/control surface for server commands.

The frontend adds `UDMFSessionSubsystem::Logout()` only for local staged credential/admin state. It does not delete or mutate the server account database.


## v0.6.1 player spawn / possession recovery layer

`ADMFMMOGameMode` now owns an explicit invariant: every gameplay PlayerController must possess `ADMFPlayerAvatarCharacter` or a derived project Blueprint. `HandleStartingNewPlayer` preserves Unreal's standard restart flow, then validates that invariant. Wrong/missing pawns are replaced authoritatively, and remote clients receive a `ClientRestart` reassertion. The PlayerController adds only a bounded owner-side acknowledgement/retry request; it never spawns a pawn locally. Skin/starter server transactions call back into the same invariant rather than duplicating spawn logic.


## v0.6.2 combat-facing layer
`ADMFDigimonCharacter` owns the shared turn-in-place presentation contract. `UDMFDigimonCombatComponent` decides when a target is in attack range and asks the character to face it before consuming resources/starting an ability. The facing loop is a bounded server timer active only while needed. Character replicated movement distributes yaw; target-facing is not client-authoritative. Movement-driven orientation is cached/restored around the attack so partner following, wild roaming and path chasing remain independent.


## v0.6.4 combat reach contract
Ability range is evaluated by the authoritative combat component as horizontal capsule-edge distance rather than actor-center distance. The same helper is used for direct validation, queued manual commands, wild/auto attacks, and impact-time revalidation. AI chase acceptance is derived from the same capsule-aware reach so navigation cannot settle outside a short-range attack's legal distance.

## v0.7.0 Scan Data / Materialization authority

`UDMFPlayerDigimonComponent` owns the authoritative per-account `ReplicatedScanData` array (`COND_OwnerOnly`). `HandleAuthoritativeBattleVictory` is the single mutation boundary for scan rewards. Species tuning comes from `UDMFDigimonSpeciesData`; no client-supplied reward values are accepted. Materialization is a server RPC that resolves the species, re-checks progress and capacity, validates a partner WorldActorClass, builds a unique `FDMFDigimonInstance`, subtracts the requirement, marks Collection replication dirty and persists immediately.

The native `UDMFDigimonInventoryWidget` is now the tabbed Digimon menu shell. Collection, Scan/Materialize and Care are current tabs; future modules should add pages to this shell instead of creating unrelated full-screen menus. `UDMFScanNotificationWidget` is presentation-only and receives owner-client reward events after the server has mutated state.


## v0.8.0 virtual-pet Care authority

`UDMFPlayerDigimonComponent` is the authoritative Care state machine. `FDMFDigimonInstance::Care` remains part of the same owner-only replicated Fast Array and server account record as combat vitals/stats. Hunger decay is integrated from server UTC timestamps, feeding requests contain no client-provided reward/timing values, and successful serving/waste transitions persist through the existing account subsystem.

`UDMFDigimonSpeciesData` owns static tuning/presentation references: starting Hunger, decay rate, Hunger per serving, Feeding Montage play count/rate, text-writable hand socket, DigiMeat mesh/relative transform (including scale), feeding voices, waste delay range, poo mesh/world scale/ground offset/lifetime and fart sounds. Project-wide fallback DigiMeat/Poo meshes and timing values live in `UDMFFrameworkSettings`.

`ADMFDigimonCarePropActor` is a lightweight replicated presentation actor. The server creates/attaches DigiMeat or places waste on a ground trace, while every peer resolves the same species/global mesh from replicated `SpeciesId` + `PropType`. The actor forcibly disables collision, overlap generation and navigation influence. Waste lifespan is server-owned. As of v0.8.1, every Care-prop mesh also locally forces `Render CustomDepth Pass = true` and a Blueprint-tunable stencil value, matching the framework cel-shading invariant without adding replicated state.

Feeding deliberately crosses UI and world presentation layers: the server accepts/locks the care sequence, sends an owner-client start event, and waits a configurable lead-in before the first Montage. `ADMFMMOPlayerController` removes the Digimon Menu/quickbar and restores game input so the 3D animation is visible. Completion recreates the shared menu directly on `CARE`. This owner-side presentation never mutates Hunger.

`ADMFDigimonCharacter` provides reliable multicast cosmetic cues for feeding Montage/voice and waste/fart presentation. The server chooses audio indices. Care locks existing combat/partner command RPCs for the duration so clients cannot race feeding against target/ability/recall state.


## v0.9.0 World Nameplate presentation layer

`ADMFPlayerAvatarCharacter` and `ADMFDigimonCharacter` each own a non-authoritative `UWidgetComponent` configured for crisp Screen-space presentation. At BeginPlay/replication refresh the actor resolves the global framework settings, applies enable/cull/height rules, initializes the selected native or Blueprint widget class, and gives the widget an observed actor.

`UDMFWorldNameplateWidget` is deliberately shared so the framework has one compact presentation contract while still exposing separate project-level Player/Digimon widget-class overrides. The native fallback collapses Digimon-only metadata/HP when observing a player, and expands the same small panel for Digimon identity/type/health. It polls presentation at a throttled interval rather than inventing replicated UI state.

Player username display uses `APlayerState::PlayerName`, which is the public display-name channel. Private account fields do not change their ownership contract. Digimon HP remains owned by `UDMFDigimonCombatComponent`; the plate is only a view of replicated combat truth.
