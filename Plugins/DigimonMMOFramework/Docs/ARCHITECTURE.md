# Architecture

## v0.16 shared Day/Night world-time architecture

`ADMFDayNightSky` is one replicated map actor and the authority boundary for world time. The server/host owns either the authority PC clock or the accelerated simulated anchor. Clients receive only compact time-source/hour/day/server-timestamp/day-phase state and interpolate presentation locally from `AGameStateBase::GetServerWorldTimeSeconds()`. Sun/moon transforms and material parameter updates are local presentation; they are not replicated component-by-component.

Simulated time persists in `UDMFWorldStateSaveGame`, keyed by map + stable `PersistenceId`, instead of being copied into every `FDMFAccountRecord`. This keeps shared-world persistence separate from private account persistence and leaves account schema v6 untouched.

Time-aware `ADMFWildDigimonSpawner` instances read the authoritative sky phase on the server. Their active Day/Night table is selected before the existing server-only rarity/species/level/spawn pipeline. Old-phase record ownership is tracked server-side so transition retirement cannot schedule the wrong population, and engaged old-phase actors may finish combat without counting against new-phase population capacity. Only the resulting actors and small spawner runtime phase/count state replicate.


## Return Home / persistent spawn architecture (v0.15.2)

The Party Quick Access `HOME` button is an owner-local presentation surface over an authoritative GameMode service. `ADMFMMOPlayerController` owns the request/result RPC pair and server-only request cooldown; `ADMFMMOGameMode` owns destination selection, collision-aware avatar teleport, partner encounter cleanup/repositioning and immediate v6 world-location checkpointing. The destination is always selected through the existing `ChooseNewPlayerSpawnPoint`/`DMFNewPlayerStart` path introduced in v0.15.1.

`UDMFHomeTeleportNotificationWidget` is presentation only. It receives an already-committed result and can be replaced by a Blueprint child. `UDMFDigimonCombatComponent::ForceAuthoritativeDisengage` is a reusable authority-only cleanup primitive that clears target/queue/recovery/encounter movement without restoring vitals or clearing cooldowns, allowing world-transition convenience features to end combat cleanly without becoming a heal/reset exploit.


## Persistent Digivolution architecture (v0.13.0)

`UDMFPlayerDigimonComponent` is the sole durable Digivolution authority for owned Digimon. A path is authored as `FDMFDigivolutionRequirement` on the current `UDMFDigimonSpeciesData`; it references a target species plus progression/Care/economy requirements and mutation/presentation policies. The client may evaluate this data for UI, but the server always resolves the current owned instance and revalidates the path before mutation.

Digivolution preserves the owned individual rather than deleting/recreating its account record. `FDMFDigimonInstance::SpeciesId` changes while the instance GUID, nickname, Level/EXP, ABI/CAM, Care state and other individual progression remain associated with the same persistent record. Save schema v5 adds `OriginSpeciesId` and `DigivolutionHistory`; legacy records are normalized on authoritative hydration.

For a stored/unsummoned Party or Bank individual, the server applies the mutation directly to the correct owner-only Fast Array item, marks that item/array dirty, persists immediately and returns the owner result. For the currently summoned active partner, the mutation is intentionally deferred behind a short server-owned world presentation. The existing actor reliably multicasts VFX/audio, the owner controller may hide modal HUD, and conflicting partner/storage/Care/combat commands remain locked. At completion the server revalidates the same path, commits persistence, then `SpawnOrRefreshActivePartner` destroys the old public actor and spawns the destination species `WorldActorClass` with the same active instance GUID. Normal actor replication—not private Party/Bank replication—publishes the transformed world form to observers.

Species resolution remains Primary Asset Manager-first. v0.13 also walks Digivolution links reachable from configured starter species as a convenience fallback, but production/package configuration should continue scanning all `DMFDigimonSpeciesData` recursively as Primary Assets so evolved/materialized forms are directly resolvable and cooked.

The native `UDMFDigimonInventoryWidget` extends the existing shared shell with `DIGIVOLUTION`. It reads Party+Bank owner state, displays path evaluations and invokes the same server API; no UMG object owns species, stat, cost or persistence authority.


## Owned Digimon level progression architecture (v0.14.8)

`UDMFPlayerDigimonComponent` is the sole durable authority for owned-Digimon EXP and Level. `HandleAuthoritativeBattleVictory` resolves the defeated species reward on the server, finds the active partner's owner-only Fast Array entry and passes that entry through one `ApplyExperienceReward` boundary. Clients never submit EXP, Level, stat-growth or Attribute Point values.

Threshold resolution is species-owned and numeric. The current `DMFDigimonSpeciesData` supplies `BaseExperienceRequired` and `ExperienceGrowthMultiplierPerLevel`; the shared deterministic formula is `Base * Multiplier^(CurrentLevel - 1)`. No CurveFloat asset or global EXP fallback is required. The loop subtracts each crossed threshold, supports multiple levels from one reward, and applies the species' existing HP/SP/STR/INT/DEF/SPD Per Level plus `AttributePointsPerLevel` exactly once per gained level.

The persistent Digimon record remains the durable truth. Level, current-level EXP, grown stats and unspent Attribute Points already existed in `FDMFDigimonInstance`, so v0.14.8 does not add a SaveGame schema field. During authoritative account hydration, legacy accumulated EXP is normalized through the same level-up function so pre-v0.14.8 accounts receive levels they had already earned rather than losing stored rewards.

For a summoned partner, `ADMFDigimonCharacter::RefreshProgressionFromInstance` updates public `ReplicatedStats` and clamps/refreshed combat vitals through the dedicated progression path. It intentionally does **not** call the normal combat initialization/reset path: target, cooldowns, recovery, active encounter state and combat intent survive a level-up. Normal actor/property replication publishes the new public Level/stats to observers while Party/Bank contents remain owner-only.

`FDMFDigimonExperienceProgression` is an immutable owner-facing result snapshot used only for presentation. One owner-targeted `ClientDigimonExperienceProgressed` RPC broadcasts the local Blueprint delegate and feeds `UDMFExperienceNotificationWidget`; it grants no authority and is robust to Fast Array/RPC arrival order because the snapshot already contains the committed before/after result. The native Party/Bank panels independently read replicated durable state and the same requirement rules for their EXP bars.

See `SETUP_LEVEL_PROGRESSION.md` for authoring and acceptance tests.

## Party + Bank / Boxes architecture (v0.12.0)

`UDMFPlayerDigimonComponent` now owns two explicit account-storage tiers while retaining historical field/API names for compatibility:

- **Party** — `ReplicatedInventory` / serialized `DigimonInventory`, now the active field roster and capped to `MaxPartyDigimon` (six by default).
- **Bank / Boxes** — `ReplicatedBank` / serialized `DigimonBank`, persistent account storage with configurable capacity and native paging.

Both replicated containers use Fast Array replication with `COND_OwnerOnly`; another player never receives a peer's complete Party or Bank contents. The public replicated world representation remains the currently spawned Digimon actor and its combat/nameplate state.

All durable storage mutations enter through the owning PlayerState component's reliable Server RPCs. Authority validates source membership, instance GUIDs, Party/Bank capacities, destination indices, Care sequence state and the default combat-switch lock before committing a transfer. Full-Party Bank withdrawals use one atomic server transaction: the selected Bank instance replaces the chosen Party slot and the outgoing Party instance is returned to Bank. The final Party member cannot be deposited.

The active partner GUID is reconciled inside the same authoritative mutation. Swapping the active slot promotes the incoming instance and refreshes the spawned partner safely; normal world replication then presents that actor change to observers. Materialization uses the same storage contract: Party first, Bank overflow, reject only when both tiers have no legal capacity.

Save schema v4 migrates legacy pre-v0.12 `DigimonInventory` collections without intentional ownership loss: the previous active partner is promoted first, remaining legacy entries fill Party in order, overflow is merged into `DigimonBank`, and instance GUIDs are de-duplicated. Existing oversized legacy Bank data is preserved rather than truncated.

`UDMFPartyQuickBarWidget` is local owner presentation over the same Party Fast Array. Normal mode is hit-test transparent; Tab interaction mode changes only the local PlayerController input/cursor state. Clicking a Party member still calls the authoritative partner-selection RPC. The quick bar therefore adds no parallel inventory authority or replicated HUD state.

## Player camera boom architecture (v0.11.1)

`ADMFPlayerAvatarCharacter` owns the framework camera boom and the local requested zoom distance. The default mouse-wheel bindings only update that local requested distance; `Tick` interpolates `USpringArmComponent::TargetArmLength` toward it after clamping against the Project Settings minimum/maximum. No camera distance, zoom input or interpolation state enters replication or persistence.

The spring arm keeps `bDoCollisionTest=true` and `ProbeChannel=ECC_Camera`, preserving normal wall/world obstruction behavior. Separately, `RefreshCameraCollisionPolicy` applies the global character-safe rule to every primitive component owned by framework player avatars and Digimon: `ECC_Camera = Ignore`. This deliberately changes only the camera channel, leaving Pawn/Visibility/combat/interaction collision semantics untouched. Blueprint-added primitive components are included so cosmetic/collision additions cannot accidentally reintroduce third-person camera popping.

Projects using Enhanced Input can disable the framework mouse-wheel binding while retaining the same local zoom implementation through the Blueprint callable zoom API.

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

`UDMFPlayerDigimonComponent` owns Party, Bank and active-partner state. Both private storage tiers use `FFastArraySerializer` with `COND_OwnerOnly`; see the v0.12 Party/Bank contract above.

The server performs starter validation, constructs the unique Digimon instance, persists it, and spawns the authoritative 3D partner actor. The client never supplies trusted stats or an arbitrary actor class. Partner species resolution prefers UE Asset Manager registration and falls back to the configured starter roster for onboarding.

## World chat architecture

`UDMFWorldChatWidget` is a local presentation surface owned by the local `ADMFMMOPlayerController`. Pressing Enter changes only local input focus; it does not create a client-authoritative chat stream. The client submits raw text to its owned controller Server RPC.

The server controller sanitizes and rate-limits the request, then `ADMFMMOGameMode` resolves the sender's public PlayerState name, stamps server UTC metadata, appends the accepted payload to a bounded in-memory session history, and sends that payload to each framework PlayerController using an owner-targeted Client RPC. This avoids a permanently replicated global transcript and keeps future moderation/channel/backend integrations at an authoritative server boundary.

A late joiner requests history once after local gameplay controller initialization. Client widgets maintain their own bounded display history. No chat data is written into `FDMFAccountRecord`, so chat cannot accidentally become account-save state.

## Manual ability command lifecycle

`UDMFDigimonCombatComponent` owns the authoritative quick-slot lifecycle. A client-owned request reaches the server through `UDMFPlayerDigimonComponent`, then resolves the equipped ability and validates target, leash and current SP. If the move cannot execute immediately because the Digimon is attacking/recovering, the ability is cooling down, the target is out of range, or target-facing is incomplete, the **latest valid command remains buffered on the server**. Automation revalidates the buffer until execution becomes legal or a bounded timeout/permanent invalidation clears it. SP and cooldown mutation happen only inside the successful authoritative execution path. Expired cooldown records are pruned instead of accumulating indefinitely.

## Replicated ability projectile architecture (v0.14.1)

`UDMFDigimonCombatComponent` now supports two execution models from the same authoritative ability Data Asset. **Timed Impact** preserves the original delayed-damage path. **Projectile** uses the same accepted cast validation/SP/cooldown/facing path but replaces the delayed damage callback with a delayed authoritative projectile launch.

`ADMFAbilityProjectileActor` is a replicated, Blueprintable cosmetic carrier whose movement is authored only by the server. The actor stores only the ability identity, source/target Digimon references and travel direction needed to reconstruct presentation. The server rotates/moves it toward the target (with optional bounded homing), detects arrival by segment-to-target distance, then calls back into the source combat component. Damage math and defeat/reward handling therefore stay in the same combat authority instead of moving into a client-visible projectile Blueprint.

Projectile visual orientation is decoupled from travel orientation through a child `VisualRoot`; designers can rotate/scale a fireball asset without changing the direction used for authoritative movement. Niagara is preferred, Cascade is fallback, and an optional Static Mesh may be carried by the same actor. Actor destruction on impact/invalid target/max lifetime guarantees cleanup of all attached projectile visuals. Optional impact VFX/audio are reconstructed from a lightweight multicast after authority accepts the arrival.

The legacy timed-impact presentation path now creates explicitly bounded transient VFX. Niagara/Cascade cues receive a forced cleanup timer even when the assigned effect loops forever. This prevents attack-socket particle accumulation without changing gameplay state or introducing replicated cosmetic components.

## Persistent identity

Species are immutable definitions (`UDMFDigimonSpeciesData`). Captured/materialized/starter Digimon are mutable instances (`FDMFDigimonInstance`) with a unique `FGuid`.

This separation is mandatory for:
- owned-Digimon Level/EXP/stat growth is now implemented in v0.14.8;
- Attribute Point grants are implemented in v0.14.8, while dedicated attribute-point spending remains future expansion;
- current HP/SP;
- hunger/care state;
- learned/equipped abilities;
- Party/Bank storage location and active-partner identity;
- evolution history and later individuality systems.

## Account storage

`UDMFAccountPersistenceSubsystem` owns the host-side `UDMFAccountDatabaseSaveGame`. The first alpha uses one SaveGame database for ease of installation. A later database/backend provider can replace storage while retaining the `FDMFAccountRecord` contract.

## Frontend/network flow

1. Frontend map runs `ADMFFrontendGameMode`; `ADMFFrontendHUD` resolves a valid local PlayerController through a short retry loop if necessary.
2. If `FrontendBackgroundWidgetClass` is assigned, the HUD creates that project-authored background locally and adds it to the game viewport exactly 100 Z-order units below `FrontendUIViewportZOrder`. The project does not manually create this same widget.
3. After the background is initialized (or immediately when no background class is assigned), the HUD waits `FrontendUIStartupDelaySeconds` and creates `UDMFLoginMainMenuWidget` at `FrontendUIViewportZOrder`. Background creation failure is non-fatal and cannot block login.
4. The native fallback does not paint a full-screen dark backdrop by default; its root passes hit tests through empty space while the centered login card remains interactive. An optional decorative backdrop can be enabled in Project Settings.
5. Login locally stages username + credential digest.
6. **Join Game** validates `Server Public Address / Hostname` + `Game Port` from Project Settings, then travels to that configured MMO endpoint with authentication options.
7. Server `PreLogin` validates credentials or auto-registers the account.
8. `InitNewPlayer` hydrates `ADMFPlayerState`, avatar state and Digimon state.
9. If the account requires a player skin, `UDMFPlayerSkinSelectionWidget` appears first and the server validates the selected `DMFPlayerSkin`.
10. Once avatar onboarding is complete, a new account requiring a Starter Digimon automatically sees `UDMFStarterSelectionWidget`.
11. Starter selection is sent as a Server RPC and validated against the configured starter roster.
12. Server creates/persists/spawns the partner; returning players skip completed onboarding stages.

Admin flow uses the same frontend but requires the additional admin unlock before `Host & Play` can start the open-world map with `listen`. v0.10.2 preflights the project-configured player-facing endpoint, and v0.10.3 also moves the Admin hosting password into Project Settings using a transient editor setter that persists only a one-way digest. Endpoint and Admin-host deployment configuration are therefore centralized without moving gameplay authority into UI.

## Expansion points already reserved

The account record now actively uses Digimon Bank storage alongside Party state and Scan progress, while money, ranked points and F→S+ tier remain reserved expansion fields. Keeping these systems in the same account schema lets later components extend the authoritative record instead of inventing parallel saves.

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

Activation chooses a target population within the designer min/max range. Initial actor creation is staggered. As of v0.14.5, each spawn uses normalized two-stage selection: the server first rolls among currently eligible rarity tiers using each tier's single `RarityWeights` value, then rolls an entry inside the selected tier using `SelectionWeightMultiplier`. A tier's probability is therefore independent of how many species are authored inside it. Finite per-entry live caps are applied before selection, and a fully capped table clamps the target population to the table's theoretical capacity.

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

The native fallback is usable immediately and can be replaced by a Blueprint child through framework settings. v0.12 adds authoritative Party/Bank move and atomic-swap transactions plus the persistent Party Quick Access HUD; future work may layer drag/drop gestures, sorting and filtering over the same transaction API.

## Healer authority (v0.5.0)

`ADMFHealerActor` is a replicated world interaction endpoint. Because a placed healer is not client-owned, clients do not send a Server RPC directly to it. `RequestHeal` routes through the owning `ADMFMMOPlayerController`; the server controller then asks the healer to validate distance, enable state, exclusive-busy state and reuse timing. The healer invokes `UDMFPlayerDigimonComponent::HealAllOwnedDigimon`, which updates the complete Party, optional all Bank/Box storage, the live partner combat component and account persistence.

In v0.12.2 the station also owns a compact durable treatment state (`bHealingInProgress`, active healing PlayerState, healed count). One station accepts only one player during `HealingSequenceDuration`. Rendering machines reconstruct a native pulsing green point light, Niagara-preferred/Cascade-fallback VFX and attached Sound Cue locally from that state, so the healer gains synchronized presentation without per-frame replicated cosmetic transforms. Dedicated servers do not render the treatment rig. The legacy heal multicast remains cosmetic/backward-compatible.

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


## v0.14.7 autonomous full-moveset selection contract

`UDMFDigimonCombatComponent::AutomationTick` no longer maps autonomous combat to a single `BasicAutoAttack`. Authority selects from the complete runtime equipped `ReplicatedAbilityIds` set, retaining the species Basic Auto Attack only as a compatibility fallback. `bEligibleForAutoBattle`, current authoritative SP, per-ability cooldown readiness and target validity filter the pool before selection.

Fairness is server-only and transient. Each effective ability ID receives a monotonically increasing local use serial when automation successfully executes it. The next decision prefers the smallest/oldest serial, randomizing only ties. Therefore unused usable moves surface before already-used moves, but the framework does not replicate or persist AI history. A pending selected ability ID is held while chasing into that ability's own capsule-aware range, preventing mixed-range movesets from changing navigation goals every automation interval. Target changes, reset, defeat and victory clear the transient rotation state.

Manual commands remain independent and continue through the existing authoritative command queue. If a player-owned partner has auto battle explicitly enabled, the same selector applies only to autonomous decisions; manual input still uses the requested slot and server validation path.

## v0.7.0 Scan Data / Materialization authority

`UDMFPlayerDigimonComponent` owns the authoritative per-account `ReplicatedScanData` array (`COND_OwnerOnly`). `HandleAuthoritativeBattleVictory` is the single mutation boundary for scan rewards. Species tuning comes from `UDMFDigimonSpeciesData`; no client-supplied reward values are accepted. Materialization is a server RPC that resolves the species, re-checks progress and capacity, validates a partner WorldActorClass, builds a unique `FDMFDigimonInstance`, subtracts the requirement, marks Collection replication dirty and persists immediately.

The native `UDMFDigimonInventoryWidget` is the shared tabbed Digimon menu shell. Its current native pages are **Party**, **Bank / Boxes**, **Scan & Materialize**, **Digivolution** and **Care**; later modules should extend this shell instead of creating unrelated full-screen menus. `UDMFScanNotificationWidget` is presentation-only and receives owner-client reward events after the server has mutated state.


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

## v0.14.4 — durable server-authoritative battle encounter state

`UDMFDigimonCombatComponent::CombatState` remains the short-lived action-phase state machine (`Idle`, `Chasing`, `Attacking`, `Recovering`, `Defeated`). v0.14.4 deliberately does **not** redefine those values because combat movement, facing, animation and buffered-command behavior depend on their existing semantics.

Instead the combat component now also replicates a compact `bBattleEncounterActive` latch. Authority sets it when a valid hostile chase/attack/recovery establishes real combat and keeps it set when recovery naturally returns to `Idle`. It is cleared by victory, self defeat, authoritative target teardown/disengage and reset/healer paths. `IsBattleEncounterActive()` exposes this durable semantic state to Blueprint without granting mutation authority.

The music subsystem consumes the latch only as local presentation. It retains the transient active-state test as a replication-order safety net so a remote client can enter Battle immediately if `CombatState` arrives just before the latch. No audio state is replicated and no client can author the encounter flag.

This separation is intentional: **action phase** answers “what is the Digimon doing this instant?” while **battle encounter** answers “is this Digimon still engaged in this fight?” Systems whose lifetime must survive pauses between manual commands should use the latter.

## v0.14 DigiDex architecture

The native DigiDex is a **read-only local presentation layer** inside `UDMFDigimonInventoryWidget`. It enumerates `DMFDigimonSpecies` Primary Assets through `UAssetManager`, resolves the same `UDMFDigimonSpeciesData` records already used by combat/Scan/Digivolution, and derives discovery badges from the owning `UDMFPlayerDigimonComponent`'s existing Party, Bank and Scan state. No parallel species database, SaveGame field, server mutation path, or replicated DigiDex state exists.

`EDMFDigimonMenuTab::DigiDex` is appended after the v0.13 values so historical enum serialization remains stable. The native visual row may present tabs in a different order than their serialized enum values.

## v0.14.2 — local owner-only targeting presentation

### v0.14.3 visibility hardening
The local targeting presentation actor remains non-replicated and local-controller-owned, but its render components deliberately avoid Unreal `OnlyOwnerSee` filtering. Privacy comes from actor locality and owner-only gameplay state, not renderer ownership heuristics. This avoids camera/view-target ownership mismatches that can cull a local player's own markers. Missing soft assets are also refreshed lazily at runtime.

`ADMFTargetingPresentationActor` is a deliberately non-replicated local presentation actor spawned by the locally controlled `ADMFMMOPlayerController`. It reads the owning `UDMFPlayerDigimonComponent`'s already owner-only `ActivePartnerActor` and `CommandTarget` and reconstructs active-partner/selected-enemy visuals locally.

PaperSprite rings are moved from capsule dimensions rather than species-authored sockets, and optional capsule-radius scaling supports widely different Digimon sizes. A Niagara-preferred/Cascade-fallback target-arrow component follows the target capsule top. Marker rotation/bob are local cosmetic ticks only.

This layer never selects a target, does not call damage APIs, and introduces no marker replication. Server-authoritative target validation and ability execution remain in `UDMFPlayerDigimonComponent` / `UDMFDigimonCombatComponent`.

### v0.14.6 combat-presentation CustomDepth invariant
Framework-owned attack Niagara/Cascade components and the owner-local enemy overhead target marker participate in the CustomDepth pass unconditionally. Transient attack/impact components are flagged immediately after spawn; reusable projectile and target-arrow components reassert the flag whenever their presentation is refreshed/activated. This is a local rendering invariant only and adds no gameplay authority or network state.


## v0.14.9 Attribute-point mutation contract

Attribute Point spending is an owned-Digimon persistence mutation on `UDMFPlayerDigimonComponent`. UI submits only `(InstanceId, EDMFDigimonAttributeStat)`; authority resolves Party/Bank ownership, validates an unspent point, mutates the persistent instance, marks the owner Fast Array item dirty, saves immediately, and refreshes an active world partner in place. The native menu is presentation only and its 1240x900/clipped shell is independent of gameplay authority.

## Persistent player world location / first-login spawn (v0.15.1)

`FDMFAccountRecord` schema v6 adds one private `FDMFPlayerWorldLocationState`. The server stores only the authenticated avatar's PIE-prefix-free map name, actor location, actor rotation and UTC checkpoint time. This data is not replicated as gameplay state; observers simply receive the resulting avatar transform through ordinary CharacterMovement/actor replication after spawn.

`ADMFMMOGameMode` resolves initial placement once per authenticated controller. A genuinely fresh onboarding account with no checkpoint may use `ADMFNewPlayerStart`; an established legacy account with no v6 checkpoint uses normal PlayerStart once; native selection chooses the enabled actor with the highest priority and exposes a BlueprintNativeEvent override for future project rules. An account with a valid checkpoint on the current gameplay map is restored before active-partner spawning and remote-client restart repair. Invalid/non-finite/mismatched saved data keeps Unreal's normal PlayerStart result.

The persistence path deliberately reuses the existing account transaction. `UDMFPlayerDigimonComponent`'s periodic authoritative autosave now also asks `UDMFPlayerAvatarComponent` to apply current avatar identity/world location to the same record. GameMode logout repeats the capture, while a first-login spawn commits immediately. There is no parallel location file, no client-supplied vector and no new network RPC.

## Canonical species presentation contract (v0.15.3)

`DMFDigimonSpeciesData` is the source of truth for species identity, including `Stage`. Presentation code must not infer evolution stage from a species name, evolution path, slot, or serialized enum identifier. `UDMFDigimonPresentationLibrary::GetDigimonStageDisplayText` is the canonical runtime formatter used by native UI and exposed Blueprint-pure for project UI. This preserves serialized enum compatibility while guaranteeing user-facing Fresh / In-Training / Rookie / Champion / Ultimate / Mega / Ultra / Armor / Hybrid terminology.

## v0.17.0 — replicated swimmable-water architecture

`ADMFSwimmableWater` is a replicated, Blueprint-derivable world actor composed of a visible `UStaticMeshComponent` surface and a query-only `UBoxComponent` swimming volume. The actor is deliberately **zero-tick**. Surface dimensions, depth, above-surface overlap height and surface offset rebuild both components from one authored geometry contract; movement-relevant runtime values are replicated only when they change.

Player swimming remains inside the existing `ADMFPlayerAvatarCharacter` instead of introducing a second pawn class. Water overlap is evaluated on the server and on the owning client. Authority owns `ActiveSwimmableWater` and the hysteresis-based underwater boolean; the owner may predict the same local overlap for responsive entry, but a replicated authority correction always wins. Other peers reconstruct presentation from the replicated player/water state.

The character uses CharacterMovement's `MOVE_Flying` physics path **only while a DMF water body owns it**. This is intentional: it provides mature Unreal 3D movement prediction/correction for a Blueprint-friendly Box water actor without requiring a BSP/`APhysicsVolume` brush. The framework snapshots gravity, movement mode, acceleration, braking and orientation settings on entry, applies water-specific values, then restores the previous contract on exit (walking-like modes reacquire the floor through Falling first).

Surface assist is a bounded vertical velocity correction toward the water plane minus `SurfaceRideDepth`. A recent explicit downward input or camera-down Forward input disables the correction so intentional dives are never fought by buoyancy. Underwater Enter/Exit depths are separate to prevent threshold chatter.

The collision capsule never rotates for swimming. Native no-animation fallback presentation composes an exposed mesh-relative rotation/location offset onto the currently applied player-skin transform and interpolates only the `USkeletalMeshComponent`. This keeps collision/network prediction stable and lets a later AnimBP disable the fallback while continuing to consume the same `Is Swimming In Water`, `Is Swimming Underwater`, swim-state delegate and Blueprint event contract.

Player world-location persistence is unchanged. Swimming is reconstructed from the loaded pawn transform intersecting authoritative world water; no transient water actor pointer or swim mode is serialized into the account record.

### v0.17.2 persistence/teleport reconciliation

`TeleportTo` is not treated as a reliable source of immediate Begin/EndOverlap ordering for persistence. After the authoritative initial world transform is chosen/applied, `ADMFMMOGameMode` calls `ADMFPlayerAvatarCharacter::RebuildSwimmingStateFromWorld`. That one-shot function scans enabled DMF water actors, evaluates actual geometric containment from the current avatar transform, rebuilds the overlap candidate set, resolves the normal water priority contract, reapplies `MOVE_Flying` swimming before the next movement frame and resolves Surface/Underwater immediately. Saved-water restores request a movement stop first so a stale Falling velocity cannot continue to the lake floor. Return Home uses the same reconciliation after teleport.

This reconstruction is lifecycle-driven, not Tick-driven. The server continues to own `ActiveSwimmableWater` / `bIsUnderwaterSwimming`; the owning client only predicts and consumes the replicated correction. Owner-side OnRep handling mirrors the latest authoritative underwater flag regardless of property arrival order, after which the local camera independently rebuilds post process/fog.

### v0.17.3 network-smoothing-compatible remote swim presentation

Remote `ACharacter` rendering has an additional ownership rule: CharacterMovement's network smoothing writes the skeletal mesh relative transform to visually interpolate replicated capsule movement. A direct DMF `SetRelativeTransform` on the same remote mesh therefore creates two competing writers. v0.17.3 removes that conflict. Authority publishes one compact `EDMFPlayerSwimState` presentation property, while each non-owning rendered avatar converts that state into the same native fallback target used locally.

For simulated proxies and listen-server views of remote autonomous clients, DMF does **not** write the mesh transform. Instead it updates `ACharacter::CacheInitialMeshOffset`, which is the Character-owned base translation/rotation consumed by `SmoothClientPosition`. CharacterMovement remains the sole writer of the smoothed remote mesh, but its target now includes the horizontal swim pose and optional underwater travel pitch. The owning autonomous proxy is unchanged and keeps immediate local prediction/direct presentation. This keeps movement interpolation, skin offsets and swim presentation in one coherent visual chain without transform RPCs.

## v0.17.1 — underwater post-process + distance fog presentation architecture

Underwater visuals deliberately remain separate from swimming authority. `ADMFSwimmableWater` now owns one replicated `FDMFUnderwaterPostProcessSettings` profile containing the authored look and waterline/depth-response tuning. Those values are sparse world configuration: they replicate when authority changes them, but they never carry a player's camera transform or local render result.

`ADMFPlayerAvatarCharacter` owns a dedicated `UPostProcessComponent`. Every replicated avatar class instance has the component structurally, but framework code enables/updates it only on the locally controlled player and disables it on dedicated servers/remote proxies. The existing player Tick performs the local camera-waterline calculation, so water actors remain zero-tick and no new global subsystem/timer is required.

The visual state is camera-correct: `FollowCamera` must be inside the active water bounds and cross below the water plane. Separate camera enter-depth / exit-height values provide hysteresis. While submerged, the presentation target weight interpolates from a shallow-water strength to full strength based on camera depth, then an exponential blend smooths transitions. The same local blend drives both the unbound `UPostProcessComponent` and a local `UExponentialHeightFogComponent`. The latter supplies real scene-distance extinction that grading alone cannot provide. This is intentionally independent from the replicated actor-origin `bIsUnderwaterSwimming` gameplay state.

The native profile builds color saturation/contrast/gamma/gain, exposure, vignette and subtle scene-fringe settings. An optional authored Post Process material is added as a weighted blendable for project-specific SceneDepth haze/refraction/caustics. Because all rendering is local, these additions cannot influence movement/combat/server simulation.

The underwater fog component is present on avatar instances but constructor-disabled. Only the locally controlled rendering avatar may enable it. Its profile values come from the replicated active water actor; camera state and applied fog density stay local. Stable density is cached to avoid repeatedly dirtying the fog render state after a blend reaches equilibrium.

## v0.18.0 — Digimon vendor economy architecture

`ADMFDigimonVendorActor` is the authority-owned public market entity. It uses no Tick: a server timer rotates a small replicated array of immutable stock snapshots. Stock generation consumes only server-side per-vendor species/range configuration. `UDMFPlayerDigimonComponent` remains the owner-private source of truth for Party, Bank and Bits and provides server-only atomic purchase/sale commit helpers. `ADMFMMOPlayerController` transports only a vendor actor, Buy/Sell enum and GUID through the single vendor transaction Server RPC; the vendor/component resolve all price/stat/ownership/storage data again before mutation.

The market does not create a parallel Digimon record type. Stock and owned entries use `FDMFDigimonInstance`, preserving the framework's persistent-individual contract. Schema v7 adds lifetime battle EXP and exact Attribute Point spend provenance so the economy can value long-term training without inferring it every quote. Digivolution continues to mutate the current form on the same individual, naturally carrying economy provenance through Digivolution and De-Digivolution.

Presentation is split cleanly: `UDMFDigimonVendorWidget` is owner-local UMG, while stock/configuration are public replicated vendor state and Party/Bank/Money remain owner-only component state. Transaction confirmations are local presentation; transaction acceptance is never a UI decision.

## v0.18.2 authenticated reconnect authority

DMF treats persisted authenticated account data as the sole source of truth for reconnect. Because `AGameMode` normally supports short-lived reconnects by duplicating a disconnecting `PlayerState` and later substituting that inactive object into a rejoining controller, component-owned MMO state can be replaced by stale teardown memory even after a correct SaveGame commit. DMF therefore does not cache or reassociate inactive PlayerStates. Every successful reconnect starts with a newly authenticated PlayerState populated from `UDMFAccountPersistenceSubsystem`, followed by a PostLogin initialization-integrity check.

## v0.18.1 disconnect-safe account finalization

Remote logout is now a single pre-teardown authority transaction owned by `ADMFMMOGameMode::FinalizeAuthenticatedPlayerSession`. The GameMode snapshots the already-initialized `ADMFPlayerState` components before `Super::Logout`, synchronizes live partner vitals, writes the existing account record synchronously, then marks the Digimon component persistence-finalized and destroys the transient summoned partner. `UDMFPlayerDigimonComponent::EndPlay` is no longer an unconditional second writer after a successful logout save.

The component also carries a non-serialized `bAuthoritativeAccountStateInitialized` lifecycle guard. Persistence is refused until `InitializeFromAccountRecord` has rebuilt Party/Bank/partner/money/scan state, preventing a partially initialized or teardown-damaged PlayerState from replacing an established account with defaults. `ADMFMMOPlayerController::EndPlay` is an authority-only idempotent fallback into the same GameMode transaction for abnormal net-driver teardown. Account schema remains v7.
