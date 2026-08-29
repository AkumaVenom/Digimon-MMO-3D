# Networking / Host Deployment

## World chat authenticated presence events (v0.18.5)

Player presence is a server-owned chat event, not a client RPC command. `ADMFMMOGameMode::PostLogin` emits `PlayerJoined` only after authenticated account initialization/rehydration; `Logout` performs the existing disconnect persistence/partner cleanup transaction and then emits `PlayerLeft` before `Super::Logout` tears down the PlayerState. The username comes from the authenticated server account value.

Both event types reuse the established reliable `ClientReceiveWorldChatMessage` fan-out and the bounded GameMode session history, so v0.18.5 adds **no RPC** and no replicated chat array. Each receiving local PlayerController may play the globally configured 2D join/leave cue. History transfer uses `ClientReceiveWorldChatHistory` and deliberately does not invoke presence audio, preventing old events from replaying sounds for late joiners.

## Day / Night world-time authority (v0.16.0)

World time is never client-authored. `ADMFDayNightSky` reads either the authority machine's local system clock or its persistent simulated clock, then replicates sparse time anchors. Clients interpolate between anchors using synchronized GameState server world time. There is no client time RPC and no per-frame light/material replication. `bIsDay` / `bIsNight` are presentation conveniences derived from the replicated authoritative phase.

Simulated time is stored in the server-only `DMF_ServerWorldState` (configurable) save. It is not replicated as private account data and does not change the account schema. Host-system-time mode always re-resolves from the authority PC clock and does not trust a saved/client clock.

Day/night wild populations remain server-only decisions. Spawners select the active phase table, rarity tier, species, level, placement, retirement and replacement on authority. `ReplicatedPopulationPhase` is informational/presentation state only. A client cannot request Day/Night, choose a table, submit a species, or influence random selection.


## Return Home authority (v0.15.2)

`HOME` is a UI action, not a client teleport. The owning `ADMFMMOPlayerController` sends `ServerRequestReturnHome()` with **no location/rotation parameters**. Authority rechecks the project enable switch and a server-only cooldown, resolves the authenticated framework avatar, then asks `ADMFMMOGameMode::ReturnAuthenticatedPlayerHome` to select the enabled `DMFNewPlayerStart`. Only after an authoritative collision-safe teleport does the server checkpoint the v6 account location.

The server also ends encounter state around the summoned partner, disengages authoritative Digimon targeting it and destroys in-flight framework projectiles whose replicated target is that partner before moving the partner beside the owner. `ClientReturnHomeResult` carries only success/failure presentation text back to the owning connection; it cannot author gameplay. Other clients learn the player's/partner's resulting transform through normal actor/CharacterMovement replication and never receive the owner's saved location record or Home toast.


## v0.13.0 Digivolution networking contract

- Party/Bank Digivolution is private durable account state. The client sends only `InstanceId + TargetSpeciesId` through reliable `ServerDigivolveOwnedDigimon`; it never sends authoritative target stats, cost, abilities, Care values, World Actor Class or completion timing.
- The server resolves the current owned record/location, source species and authored path, then validates master settings, Bank permission, current HP, Care lock, configured active-combat restriction, Level/ABI/CAM/stat/Care gates and money.
- Stored/unsummoned Digivolution mutates only the appropriate owner-only Party/Bank Fast Array item and immediately persists it. No public world actor or broadcast roster is created for a Bank-only change.
- A summoned active partner uses compact owner sequence state plus a **Reliable NetMulticast cosmetic cue** on the existing Digimon actor. The multicast carries only the target species ID used to choose presentation assets; it cannot commit the form change.
- The server revalidates the path again when the world presentation timer finishes, deducts money exactly once on successful commit, persists, then replaces the active actor with the destination species `WorldActorClass`. Standard replicated actor/state presentation informs other players of the final form.
- `bDigivolutionSequenceActive` locks conflicting set-active/recall/Party-Bank/Care/target/ability/healer actions for that owner until the sequence completes.
- `OriginSpeciesId` / `DigivolutionHistory` are account SaveGame data inside the owner-only Digimon instance. Save schema v5 migration occurs on the authoritative host, not on clients.
- The owner-only UI hide/reopen state is local presentation and adds no authority. Other clients need only the public multicast cue and replacement actor.

## v0.12.0 Party / Bank networking contract

- Party and Bank are **private account progression** and each use owner-only Fast Array replication. Complete roster/storage contents are never broadcast to unrelated clients.
- `ServerMoveBankDigimonToParty`, `ServerMovePartyDigimonToBank` and `ServerSwapPartySlots` are reliable durable-state requests on the connection-owned `UDMFPlayerDigimonComponent`.
- The server validates instance ownership/source location, destination index, Party/Bank capacity, Care state and the configured combat-switch policy before mutation. Clients never submit trusted stats or an arbitrary Digimon object.
- A full-Party Bank withdrawal is an atomic authoritative swap; there is no intermediate frame where a Digimon is duplicated or lost between containers.
- Active-partner reconciliation is server-owned. Observer clients learn the result through the normal replicated partner world actor, not by receiving the owner's private Party/Bank arrays.
- Materialization is storage-aware on authority: Party first, then Bank. Owned-species counts include both tiers.
- The Party Quick Access HUD and Tab cursor mode are local presentation/input state only. Clicking a slot routes through the existing authoritative partner-selection path; no HUD state is replicated.
- Save schema v4 is host-side persistence. Legacy collection-to-Party/Bank migration and GUID de-duplication occur on authoritative account hydration, never independently on clients.

## v0.11.1 player camera networking contract

Player camera zoom is **client-local presentation only**. Mouse-wheel input, desired boom length, interpolation and spring-arm compression are not replicated and do not enter PlayerState/account persistence. Two players can therefore use different camera distances while sharing the same authoritative world simulation.

The new character camera-collision policy is deterministic actor configuration rather than network gameplay state. Framework player and Digimon primitive components ignore only `ECC_Camera`; movement, Pawn collision, targeting/Visibility traces, combat authority, interaction and navigation are unchanged. No new camera RPCs or replicated properties are introduced.

## v0.11.0 global music networking contract (v0.14.4 lifecycle semantics)

- Frontend/Open World/Battle music is **local presentation only** and adds no music RPC or persistent account field.
- The local `UDMFMusicSubsystem` reads the active partner's replicated server-authoritative battle-encounter state; it never predicts or changes combat authority.
- A real replicated `Chasing`, `Attacking` or `Recovering` phase establishes the encounter. The encounter then remains active through manual `Idle` gaps until authority ends it. Merely selecting a command target still does not create a false battle transition.
- v0.14.4 adds one replicated combat boolean (`bBattleEncounterActive`) to carry this durable gameplay truth; track assets, playback position, crossfades, volumes and AudioComponents remain entirely local.
- Each player's music state is independent. One client entering combat cannot force unrelated clients to switch soundtrack.
- Persistent-across-travel 2D AudioComponents and crossfades are local AudioMixer/presentation behavior only. Dedicated servers do not render them.
- Music settings/assets are deployment/content configuration and do not consume music-specific runtime network bandwidth.

## v0.10.4 replicated player-footstep contract

- Footsteps exist only on `ADMFPlayerAvatarCharacter`; no Digimon actor receives this system.
- Grounded movement cadence is derived independently from authoritative server CharacterMovement state. When a stride threshold is reached, authority calls `MulticastPlayPlayerFootstep` as an **Unreliable NetMulticast** cosmetic RPC.
- Unreliable delivery is deliberate: footsteps are transient presentation, so a lost packet should disappear rather than queue and play late. No HP, inventory, persistence or movement authority depends on the event.
- A remote owning client separately predicts its own local footstep for immediate responsiveness. When the authoritative multicast returns to that owner, it is suppressed to avoid double playback; other relevant clients hear the server event.
- Listen hosts hear the authoritative event directly. Dedicated servers never render audio locally but still originate observer multicast events.
- The assigned Sound Cue/USoundBase and cadence controls are project configuration, not replicated runtime state. Projects should author attenuation in the Sound Cue so ordinary Unreal spatial audio limits audible range.

## v0.18.4 global server-capacity contract

- **Global Maximum Players** is server deployment configuration under `Networking → Server Capacity` and defaults to **100** total connected gameplay players. A listen host consumes one slot.
- `Host & Play` includes the configured capacity as Unreal's native `MaxPlayers` world-travel option when creating the listen server.
- `ADMFMMOGameMode::PreLogin` reasserts the authoritative `UDMFFrameworkSettings::GlobalMaxPlayers` value onto `AGameSession::MaxPlayers` **before** calling `Super::PreLogin`; native GameSession approval therefore owns the actual full-server rejection.
- The repeated authority-side assignment is intentional defense in depth: a joining client may place arbitrary options in its own travel URL, but cannot change the server's configured capacity.
- Capacity controls connection admission only. Reducing the configured value below current occupancy never kicks authenticated players; subsequent joins are refused until enough slots are free.
- The feature introduces no capacity RPC, replicated player-count property or persistent account field. Normal `GameState`/GameSession player tracking remains the source used by Unreal for admission.

## v0.10.3 configurable Admin-host gate

- The local `Host & Play` Admin passphrase is now configured under `Networking → Admin Hosting` instead of requiring a source digest edit.
- Project Settings accepts a temporary plaintext setter value only in the editor, hashes it immediately, clears it, and persists only `AdminHostingPasswordDigest` to the project Game config.
- `UnlockAdmin` hashes the locally entered candidate and compares it with the configured digest. Raw Admin password text is never part of login travel options, RPC payloads, replicated state or account persistence.
- The Admin gate is a local hosting-control gate, **not** server-side identity/role authorization. Existing PreLogin account validation and authoritative gameplay networking remain independent.
- A malformed configured digest fails closed. The v0.10.2 digest is retained as the class default for upgrade compatibility until the project deliberately replaces it.

## v0.10.2 configurable server-endpoint contract

- **Server Public Address / Hostname** is project deployment configuration under `Networking → Server Endpoint`; the regular-player destination is no longer encoded in plugin C++.
- `Join Game` reads the configured host and `GamePort`, validates that the host contains only safe hostname/IPv4 characters, then constructs `host:port` before appending the existing authenticated travel options.
- Clients still cannot supply or mutate the destination through the native frontend UI. Changing the deployment endpoint requires changing project configuration and rebuilding/redeploying (or an intentional config override by the consuming project).
- `Host & Play` remains Admin-gated and starts the same authoritative Unreal listen server. It validates the configured player-facing endpoint as a deployment preflight; the public address is not an RPC and is not replicated gameplay state.
- The address is the endpoint **players use to reach the host**. It does not configure router port forwarding, NAT, DNS or firewall rules, and it does not replace Unreal's normal NetDriver socket binding.
- The prior default `DigimonMMO3D.custom-gaming.net` is retained to avoid upgrade-time behavior changes.

## v0.10.1 HUD-layout note

The v0.10.1 chat/quickbar separation fix is **presentation-only**. `WorldChatBottomSafeOffset` affects only the native local widget inset and adds no replicated property, RPC, server validation path or chat-history change.

## v0.10.0 world-chat authority contract

- The owning client sends **message text only** through `ServerSendWorldChatMessage`. Sender name, timestamp and message type are never trusted client parameters.
- The server sanitizes CR/LF/tab characters, trims whitespace and clamps length using `WorldChatMaxMessageLength`.
- Per-controller authoritative anti-spam uses both `WorldChatMinimumSendInterval` and a sliding `WorldChatBurstWindowSeconds` / `WorldChatMaxMessagesPerBurst` limit. Rejections return only to the sender.
- Accepted messages are stamped from public `APlayerState::PlayerName`, which is already the safe public username channel used by world nameplates. Private owner-only `AuthenticatedUsername` and server-only credential digests are not sent in chat payloads.
- `ADMFMMOGameMode` keeps only the configured bounded session history and fans accepted messages out through owner-targeted Client RPCs. There is no continuously replicated chat Fast Array or global replicated transcript.
- Late joiners explicitly request the recent bounded session history once. Chat is not account-persistent and does not change the SaveGame schema.
- The widget is presentation-only. Blueprint skins may replace layout/events but do not gain authority to stamp or broadcast messages.

## v0.6.1 late-join player possession contract

- `ADMFMMOGameMode` remains server-only authority for gameplay pawn creation and possession.
- Every joining PlayerController is validated after Unreal's normal start/restart path. A missing or non-`DMFPlayerAvatarCharacter` pawn is recovered server-side.
- Remote clients receive a `ClientRestart` reassertion for the authoritative avatar so frontend/default-pawn state cannot survive the network-travel handoff.
- The owning remote `DMFMMOPlayerController` runs a bounded acknowledgement/retry request until its local pawn is the replicated DMF avatar; it does not permanently poll.
- Skin selection never grants spawn authority to the client. `ServerSetPlayerSkin` may invoke server-side avatar recovery, then applies the selected skin to the authoritative pawn.
- Starter confirmation similarly ensures a valid player avatar before the active partner is spawned/refreshed.
- If a project misconfigures `DefaultPawnClass`, the GameMode refuses to use an incompatible fallback pawn and uses the native DMF avatar as a safety fallback.


## v0.6.4 manual ability authority

- Quick-slot input remains a client request only; the server owns target validation, SP, cooldown, range, facing, chase and damage.
- A valid request that arrives during a transient block (attack/recovery/cooldown/chase/facing) is buffered server-side rather than discarded.
- The buffer is latest-command-wins and does not replicate as gameplay authority to clients.
- SP is deducted once only when the server starts the ability.
- Cooldown end times replicate for HUD presentation; the authority validates/prunes against its own world clock while clients display remaining time using synchronized GameState server time.

## v0.14.1 projectile ability networking contract

- Projectile ability input is still only an owning-client request routed through `UDMFPlayerDigimonComponent`; the existing server validates target, SP, cooldown, initial range, leash and combat-facing before accepting the cast.
- `ImpactDelaySeconds` becomes launch timing for Projectile mode. The server spawns the replicated `ADMFAbilityProjectileActor`; clients never spawn authoritative projectiles or provide the projectile class/damage/arrival position.
- The projectile actor replicates its world transform and minimal definition state. Server Tick owns homing/travel and target-arrival testing. Projectile cosmetic components are local children reconstructed from the same cooked ability/species data.
- Damage is applied by `UDMFDigimonCombatComponent::HandleAuthoritativeProjectileImpact` only after server arrival. The old second cast-range check is intentionally not used for projectile impact; the visible projectile reaching the still-valid hostile target is the hit condition.
- Optional impact VFX/audio uses one **Unreliable NetMulticast** cosmetic cue after authority accepts the arrival. Missing a transient impact effect under packet loss is preferable to queuing stale visual effects.
- Projectile actor destruction (impact, invalid source/target, lifetime expiry) removes its attached VFX on every client. Timed-impact VFX cleanup is local presentation and adds no replicated state.
- Dedicated servers skip projectile/timed cosmetic asset presentation while retaining projectile authority and damage.

## Intended topology

This baseline is intentionally **multiplayer gameplay only**:

- The frontend/menu map may run locally before connection. `FrontendBackgroundWidgetClass` is created locally by the frontend HUD below the login layer and is never replicated or authoritative. Its v0.15.0 project-selected background presentation, startup delay, native-backdrop toggle and UI Z-order are **local presentation only**; they add no replication/RPC channel and do not alter authentication or travel authority.
- A normal player can only use the framework's regular **Join Game** path, which connects to the project-configured server endpoint.
- An administrator who passes the extra Admin gate can choose **Host & Play**, causing the configured open-world map to open as an authoritative Unreal listen server.
- `ADMFMMOGameMode` rejects the concept of standalone gameplay and returns to the configured frontend when loaded without networking.

## Internet reachability

`Host & Play` starts an Unreal listen server; it does not configure the router, firewall, NAT or DNS automatically. For internet players to reach the host:

1. The configured game port (default `7777/UDP`) must be allowed through the host firewall.
2. NAT/router forwarding must send the public game port to the admin host PC when required.
3. The project's fixed DNS name must resolve to the public address that reaches the admin host.
4. The packaged client and host must use compatible cooked content/build versions.

## Replication policy

Private Party and Bank state is replicated owner-only. World partner actors are ordinary replicated actors so other players can see the currently presented partner. Gameplay-changing client requests use server RPCs and are validated server-side.


Player avatar skin selection follows the same authority boundary:

`Owning client UI -> PlayerState AvatarComponent server RPC -> registered Primary Asset / enabled / mesh validation -> persistent SelectedPlayerSkinId -> replication to all clients -> each client applies presentation to the same authoritative pawn`

Only the skin Primary Asset ID is accepted from the client. Skeletal mesh paths, Animation Blueprint classes and material overrides are resolved from server-cooked Data Assets. Skin switching never changes pawn ownership, possession, transform or Digimon state.

The starter grant demonstrates the persistent transaction pattern:

`Client UI request -> Server RPC -> server roster/capacity/eligibility validation -> authoritative mutation -> persistence -> replicated result`

Real-time combat follows the same authority boundary:

`Owned client command -> PlayerState server RPC -> active-partner/slot/target/rate validation -> optional leash-limited chase queue -> SP/cooldown/range revalidation -> authoritative impact/damage -> replicated state + cosmetic multicast cue`

Cooldown UI uses synchronized server world time rather than the local client's clock. Durable combat truth is replicated HP/SP/state/target/cooldown data; multicast attack/win/death cues are presentation only.

Inventory drag/drop, materialization, stat-spend, evolution and ranked-reward operations should continue to follow the same narrow validated-request contract.

## v0.9.0 world-nameplate replication contract

World nameplates are **local presentation reconstructed from normal replicated actor state**. The Widget Components and `UDMFWorldNameplateWidget` do not replicate and send no gameplay RPCs. Dedicated servers do not render them.

Player identity uses Unreal's standard public `APlayerState::PlayerName`. On successful authoritative account authentication, the server sets PlayerName to the authenticated username. The framework's `AuthenticatedUsername` field remains owner-only and `CredentialDigestServerOnly` remains server-only; only the public username required for MMO identity presentation is exposed to other players.

Digimon identity/health uses `SpeciesId`, `ReplicatedStats`, the new public presentation-only `ReplicatedNickname`, and the already replicated Combat Component HP. Clients may display these values but cannot author them. Damage, level/stats and nickname persistence continue to originate from the existing authoritative gameplay/persistence paths.

The nameplate refresh interval and max draw distances affect only local presentation/performance; changing them does not alter network relevancy, combat replication or ownership.

## Authentication boundary

The alpha's built-in account gate is appropriate for private development and packaged multiplayer testing, but it is not a replacement for a production identity service. The credential digest in travel options is a bearer-equivalent value and can be replayed if intercepted.

For a public service, keep the PlayerState/account interfaces and replace the transport with a TLS authentication endpoint that issues short-lived signed session tickets. The game server should validate the ticket before accepting the connection.



## Player world-location persistence (v0.15.1)

Player world position is **server-authored private account persistence**, not a client replication protocol. The server reads the possessed `DMFPlayerAvatarCharacter` transform during the normal account autosave/logout transaction and stores it in `FDMFAccountRecord::PlayerWorldLocation`. Clients never submit a saved location/rotation value.

On login, `ADMFMMOGameMode` decides initial placement on authority only. Accounts without a checkpoint can use `ADMFNewPlayerStart`; returning accounts restore a finite saved transform only when its saved map matches the current gameplay level. The transform is applied once before partner restoration. Other peers learn the player's final world pose only through standard replicated pawn movement.

This release adds no Server/Client/NetMulticast RPC. The saved map/location/rotation is not replicated owner-only or globally; it remains host-side account data. Host and remote clients therefore persist independent coordinates keyed by authenticated account, with no cross-account location sharing.

## Wild spawner authority

`DMFWildDigimonSpawner` performs proximity counting, target-population selection, rarity/species roll, level roll, ground/nav placement, respawn scheduling and destruction only on the authoritative server. The spawner replicates only small runtime state (`active`, `alive count`, `target population`); spawned Digimon are normal replicated actors.

v0.14.5 keeps that authority boundary unchanged while correcting probability semantics: rarity and species are rolled in two server-only stages. Only currently eligible rarity tiers participate in the first roll, each tier contributes its configured rarity weight once, and the selected tier's eligible entries then use their per-entry multipliers. Clients receive only the resulting replicated wild actor/state and cannot influence either random roll.

Wild `SpawnRarity`, `SpawnHomeLocation` and the compact ground-transition timing struct replicate with the actor. Emergence/sink mesh motion is reconstructed independently on every machine using synchronized server world time, avoiding reliable per-frame cosmetic transform traffic. AI roaming and combat movement remain server-driven through the existing replicated Character movement path.


## Manual partner commands / healer / roster authority (v0.5.0)

Owned partners do not need autonomous combat to remain network-correct. Manual target/ability requests use the existing owner-controlled route: `client DMFMMOPlayerController -> PlayerState DigimonComponent Server RPC -> authoritative partner CombatComponent`. `CommandPartnerTargetAndAttack` sends the requested target with the slot command so target selection and attack intent do not depend on two client RPCs arriving in separate frames.

Roster Set Active/Summon and Recall are owner-only server RPCs. The client supplies only an instance GUID; the server confirms the GUID belongs to that account inventory before changing active-partner state or spawning an actor.

Healer interaction uses the client-owned PlayerController as the RPC ingress because placed healer actors are not owned by arbitrary clients. The server revalidates healer reference, distance, enabled state, **exclusive treatment availability** and reuse delay, then performs the Party/Bank heal and persistence mutation. No healing amount, HP, SP or currency value is trusted from the client. v0.12.2 replicates only compact healer presentation state (`bHealingInProgress`, active PlayerState and healed count); each rendering machine locally drives the green light, Niagara/Cascade and audio. The original healer multicast event remains presentation-only and backward-compatible.

## Native player interaction authority (v0.5.2)

The new player `Interact` function is intentionally a local discovery/input layer, not a gameplay-authority layer. The local pawn traces from its view and classifies the hit actor, but all supported gameplay mutations continue through existing server entry points.

Digimon target-only flow:

`Local DMFPlayerAvatarCharacter::Interact -> local Digimon classification -> DMFMMOPlayerController -> PlayerState DigimonComponent ServerSetCommandTarget -> server hostility/active-partner validation -> replicated CommandTarget`

Digimon target+attack flow:

`Local Interact/InteractWithDigimonAndAttack -> DMFMMOPlayerController -> PlayerState DigimonComponent ServerCommandActivePartnerAbilitySlot -> server target/slot/rate/SP/cooldown/leash/range validation -> authoritative combat`

Healer flow:

`Local Interact -> local healer classification -> DMFMMOPlayerController ServerRequestUseHealer -> healer authoritative enabled/range/busy/reuse validation -> HealAllOwnedDigimon(Party + optional all Bank/Boxes) -> persistence -> replicated exclusive treatment presentation`

The interaction trace result itself is never replicated as trusted state. A malicious client can request an actor reference only through the same validated RPC paths that existed before v0.5.2. `OnInteractionResult`, `BP_OnDigimonInteracted` and `BP_OnUnhandledInteraction` are presentation/project-extension surfaces and do not bypass server validation.


### Defeated Digimon replication (v0.5.3)
The server alone decides defeat by authoritative HP and replicates `CombatState=Defeated`. A reliable defeat multicast is cosmetic-only; it does not start the durable Death Montage. `SetCombatState` on authority and `OnRep_CombatState` on clients are the sole durable defeated-animation trigger, avoiding a multicast/property ordering race. Clients never decide revival. The held death pose is local presentation reconstructed from replicated combat state/species data and does not replicate skeletal transforms each frame.


## Wild proactive/retaliation authority

Wild aggression policy is server-owned. `Proactive Auto Battle` controls nearest-hostile acquisition; `Retaliate When Attacked` controls whether authoritative damage from a valid hostile Digimon establishes a reactive combat target. Retaliation does not run on clients and does not enable proximity aggression.

The retaliation target is the authoritative attacking Digimon passed through the damage pipeline. Normal replicated `CurrentTarget`, `CombatState` and character movement then synchronize the response. Leash, target validity, cooldown, range and defeat rules are revalidated server-side.

As of v0.14.7, the server also owns **which autonomous ability is chosen**. Wild retaliation/proactive auto battle evaluates the complete equipped `ReplicatedAbilityIds` moveset, filters by `bEligibleForAutoBattle`, SP/cooldown/target validity, and uses transient least-recently-used history plus a pending chase intent. Neither history nor pending intent is replicated or persisted; clients learn the chosen move only through the same existing authoritative ability execution/cosmetic replication they already receive. No new combat RPC is introduced.

## v0.6.0 UI authority note

The polished native UI pass does not move authority into UMG. Inventory slots, selected stats, active/summoned/defeated badges and combat HUD state are views of replicated/owner-owned framework data. Summon/recall, starter selection, player skin application, ability commands and healer use continue through their existing server-authoritative paths.

Portrait textures and ability icons are presentation assets resolved locally from Primary Asset data; they are not client-authored network state. Frontend `Logout` clears only locally staged connection credentials/admin unlock.


## v0.6.2 combat-facing replication contract
Combat facing is server-authoritative. Only the authority rotates the Digimon actor toward its attack target. The existing replicated Character movement carries yaw to clients; no client may independently decide or RPC arbitrary combat facing. Ability execution can wait for the authoritative yaw tolerance before SP/cooldown consumption and attack presentation begin.


## v0.6.4 ability authority / reach
Positive-SP and zero-SP abilities remain server-authoritative. Clients submit the slot/target request only. The server owns SP affordability, cooldown, capsule-aware range, facing, damage and impact revalidation. SP is deducted only after the execution gates succeed, and authoritative CurrentSP replication updates the owning HUD/clients.


## v0.14.8 owned-Digimon EXP / level progression network contract

- Battle EXP, threshold consumption, Level changes, per-level stat growth, Attribute Point grants and max-level handling execute only on the authoritative `UDMFPlayerDigimonComponent`. The client sends no progression mutation request.
- Party/Bank durable Level/EXP/stats remain inside the existing owner-only Fast Arrays and account persistence. v0.14.8 adds no replicated progression property and no SaveGame field.
- The active summoned Digimon's `ReplicatedStats` is refreshed on authority after progression so nearby peers receive the public Level/stat result through normal actor property replication. The progression refresh does not reset target, cooldown, recovery or battle-encounter state.
- `ClientDigimonExperienceProgressed(FDMFDigimonExperienceProgression)` is the one new reliable owner Client RPC. It carries an immutable presentation snapshot only; receiving or Blueprint-handling it cannot grant EXP, levels, stats or Attribute Points.
- The native EXP toast/progress animation is local-only. Another client can observe the partner's public new Level/nameplate but never receives the owner's private Party/Bank EXP ledger or EXP/LEVEL UP notification.
- Legacy stored EXP is normalized only during server account hydration; clients cannot trigger or supply migration results.

## Scan & Materialization replication
Scan Data lives on the owning `UDMFPlayerDigimonComponent` and replicates owner-only. Rewards are calculated only on authority from the defeated species data. The client reward RPC exists for presentation; it does not carry permission to mutate Scan Data. Materialization requests send only a species ID, after which the server independently validates global/species settings, threshold, Collection capacity and partner class before creating the new owned Digimon. Persistence is written immediately after successful materialization and at the normal account save boundaries.


## Care replication and RPC contract

Care follows the same MMO trust boundary as combat and materialization:

`Owner CARE UI -> ServerFeedActivePartnerUntilFull -> server ownership/summon/health/idle/species/Montage/mesh/socket validation -> server care lock -> owner ClientCareSequenceStarted -> replicated DigiMeat + character multicast presentation -> server Hunger mutation/persistence -> repeat until full -> ClientCareSequenceFinished`

Clients never submit Hunger gain, decay, waste timing, mesh scale authority, sound index, completion timing or world spawn transforms. Species and project settings are resolved on authority. The owner-only `ReplicatedInventory` carries the persistent Care struct; other players do not receive another account's private Hunger ledger through that array. They see the normal replicated partner actor and the replicated care prop/cosmetic multicast required for shared-world presentation.

Waste uses persisted server UTC scheduling. At due time, authority traces beneath the currently spawned active partner and creates a replicated `ADMFDigimonCarePropActor`. `SpeciesId` and `PropType` replicate to resolve presentation for current/late viewers; actor movement/attachment or world transform is server-owned. The actor disables collision/overlaps/navigation and server lifespan performs cleanup. DigiMeat/poo CustomDepth and stencil application are local rendering state reasserted by the Care prop on each peer; they add no network payload or client authority.

During `bCareSequenceActive`, the owner component rejects conflicting set-active, recall, auto-battle, target and ability RPCs. The server also disables the partner's combat automation/target and stops AI movement before feeding, then restores the previously allowed auto-battle state on completion.

## v0.14.4 persistent battle-encounter network contract

- `UDMFDigimonCombatComponent::bBattleEncounterActive` is a normal replicated **server-owned gameplay boolean**. It is never client-writable and introduces no RPC.
- Authority starts the encounter only after actual hostile combat activity and keeps it active through transient `CombatState=Idle` gaps between manual attacks.
- Authority clears it on victory, local Digimon defeat, authoritative target/disengage teardown and combat reset paths.
- `UDMFMusicSubsystem` runs locally and reads only the local player's active partner. Therefore the new replicated boolean does **not** replicate music, track assets, playback position, volume, crossfade state or audio events.
- Host and every remote client can be in different encounter/music states at the same time. Dedicated servers remain audio-free.
- Target selection remains owner-only and does not by itself set the encounter boolean.

## DigiDex networking contract (v0.14)

DigiDex introduces **no network RPCs and no replicated properties**. The species catalog is static cooked project content resolved from the Asset Manager. Per-account `OWNED`/`SCANNED` badges are computed locally from the existing owner-only Party, Bank and Scan replication already delivered to that owning client. DigiDex cannot request summon, storage, Care, Materialization or Digivolution mutations.

## v0.14.2 targeting-visual network contract

### v0.14.3 targeting visibility fix
The rendering fix does not change the network contract. Marker components no longer use `OnlyOwnerSee`, because the entire `ADMFTargetingPresentationActor` is already non-replicated and created only on the local controller. No remote machine receives that actor or its sprite/VFX components; `ActivePartnerActor` and `CommandTarget` remain owner-only authoritative inputs.

- Active-partner and enemy-target rings plus the hovering target arrow are **client-local presentation only**.
- `ADMFTargetingPresentationActor::bReplicates` is false and dedicated servers construct no visible targeting presentation.
- No targeting-visual RPC or replicated property is added. The local actor consumes the existing `COND_OwnerOnly` `ActivePartnerActor` and `CommandTarget` references.
- Consequently Player A does not receive Player B's marker selection state. If two players independently target the same enemy, both render their own local marker set.
- Target legality and target changes remain server-owned through `ServerSetCommandTarget` / existing combat validation. Marker visibility grants no combat authority.

### v0.14.6 CustomDepth presentation hardening
The attack-VFX and enemy-marker CustomDepth fix adds no network contract. The server still owns ability execution, projectile travel/impact and damage; clients reconstruct the same replicated/local presentation as before. `Render CustomDepth Pass` is enabled on each relevant local runtime component and is not replicated as new gameplay state. The enemy overhead target marker remains owner-local/non-replicated.


## v0.14.9 Attribute Point networking

`ServerSpendDigimonAttributePoint` is the only gameplay mutation entry point. Clients cannot submit a target value or remaining-point count. `ClientAttributePointSpendResult` is owner-only acknowledgement after the server has committed the result. Private Party/Bank stats remain owner-only; a summoned partner exposes the resulting public replicated stats through its existing actor replication. No SaveGame schema bump is required.

## Stage presentation note (v0.15.3)

Canonical Digivolution stage wording is presentation-only. The authoritative species asset already supplies `Stage`; v0.15.3 adds no RPC or replicated field. Peers resolve the same species-authored stage locally through the shared presentation helper, while existing species/actor replication contracts remain unchanged.

## v0.16.1 world-clock HUD

The 12-hour HUD clock is **presentation-only**. `DMFCombatQuickBarWidget` reads the local replicated `DMFDayNightSky` and formats its smooth interpolated world time. Host-PC mode therefore follows the authority machine via the existing v0.16.0 time anchor; Simulated mode follows the persistent authoritative simulated clock. No client system-time read, clock RPC, replicated widget text, or additional replicated property was added.


## v0.17.0 swimmable-water networking contract

- `ADMFSwimmableWater` is a replicated world actor, but it does not send per-frame water traffic and has no Tick. It is always network-relevant so a very large lake cannot lose its active-water actor reference merely because its origin is far from a swimmer; runtime dimensions/enabled/movement tuning are sparse replicated properties.
- `ADMFPlayerAvatarCharacter::ActiveSwimmableWater` and its underwater-state boolean are server-owned replicated state. Clients cannot submit a water actor, underwater flag or destination transform through a framework RPC.
- The owning client also consumes the local overlap for immediate movement prediction. `OnRep_ActiveSwimmableWater` is an explicit authority correction path and covers late join/save-location restoration where the local overlap event may predate possession.
- Actual swimming motion uses the existing CharacterMovement client prediction/server correction/replicated movement pipeline. **No new swimming RPC is introduced.**
- The no-animation flattened mesh pose is local presentation reconstructed from replicated swim state. The capsule remains upright and authoritative.
- Water material/mesh assets are authored cooked content. They do not grant gameplay authority. The plane itself has no collision; only the Pawn overlap volume participates in swim-state detection.
- Account SaveGame schema remains v6. Only player world transform is persisted; swim state is recovered from world overlap after restore.


## v0.17.3 remote swim presentation networking contract

- Authority publishes one replicated `EDMFPlayerSwimState` presentation value (`None`, `Surface`, `Underwater`) for observers. It is a sparse state-boundary update, not a per-frame transform stream.
- The owning autonomous client continues using local water/depth prediction for responsiveness. Non-owning client proxies consume the replicated state; the listen server uses the same authoritative state for its rendered copy of a remote client.
- Remote skeletal-mesh transforms are **not replicated** and are not driven by a custom RPC. DMF changes the Character network-smoothing base via `CacheInitialMeshOffset`, allowing `SmoothClientPosition` to remain the sole remote mesh interpolation writer.
- The first unaccepted direct-mesh proxy implementation is not part of this release because direct relative-transform writes can fight listen-server/simulated-proxy mesh smoothing.
- Existing movement authority, active-water selection, v0.17.2 persistence reconstruction, local underwater PP/fog and all 47 RPCs are unchanged.

## v0.17.1 underwater post-process + distance fog networking contract

- `FDMFUnderwaterPostProcessSettings` is replicated as sparse configuration on the already-replicated `DMFSwimmableWater` actor so runtime authority changes produce the same authored water profile on clients.
- The player's actual camera transform, camera-underwater boolean and current blend weight are **never replicated and never sent by RPC**. They are local presentation only.
- `Is Swimming In Water` / `Is Swimming Underwater` remain the authoritative gameplay-facing state. `Is Local Camera Underwater` must not be used for damage, abilities, breath/oxygen authority or persistence.
- Remote player proxies keep their `UnderwaterPostProcessComponent` disabled and skip the per-frame local PP path. A remote swimmer can therefore never tint another client's viewport.
- Dedicated servers perform no post-process rendering. Water actors remain zero-tick.
- Networking RPC declaration count is unchanged from v0.17.0. Account SaveGame remains schema v6 and shared Day/Night world-state persistence is unchanged.

- Underwater exponential fog is strictly local presentation. Fog visibility/density are never replicated and no camera transform is sent over the network. The active water profile replicates as existing sparse configuration only; each owning client derives its own local fog blend from its camera.

## v0.17.2 persisted-water restoration networking contract

- Save/load continues to persist only the authenticated player's authoritative map/location/rotation in account schema v6. No water pointer, swim mode, underwater flag, camera state or fog state is serialized.
- After the server applies the restored transform, it performs a one-shot world-geometry reconciliation and authors the existing replicated `ActiveSwimmableWater` / underwater state before normal gameplay proceeds. Clients still cannot submit a water actor or underwater state.
- `RebuildSwimmingStateFromWorld` is callable for custom teleport integration but does not add an RPC. On a client it can only rebuild local prediction from real water containment; authority remains the only writer of replicated water state.
- The owning client's OnRep path is hardened against property ordering, so the water pointer and underwater correction converge immediately. Post-process/fog stays local and is reconstructed from the local camera after that correction.
- Water actors remain zero-tick and no periodic world scan was added; the scan occurs only at explicit restore/teleport/Blueprint refresh boundaries.


## v0.18.0 — vendor economy networking contract

The Digimon vendor is server-authoritative. A client request contains only `Vendor`, `EDMFDigimonVendorTransactionType`, and one GUID (StockId for Buy, owned InstanceId for Sell). The server validates vendor enabled/policy, range, authoritative stock/ownership, current price, Bits, Party/Bank capacity and mutation locks before any change. Clients never submit Digimon stats, price, payout, money or destination storage.

Vendor stock/configuration and next-rotation endpoint are replicated public actor state subject to normal relevancy. Stock generation and rotation occur only on authority and vendor actors remain zero-tick. Party, Bank and Money continue using the established owner-private `UDMFPlayerDigimonComponent` replication. Successful transactions persist the authoritative account immediately.

v0.18.0 adds two RPCs: reliable Server `ServerRequestDigimonVendorTransaction` and reliable owner Client `ClientDigimonVendorTransactionResult`, increasing the framework RPC count from 47 to 49. A server-side minimum transaction interval limits request spam. Concurrent purchase attempts for the same StockId serialize on the server; the first successful mutation removes the offer and subsequent requests fail against the now-missing StockId.

## v0.18.2 reconnect PlayerState contract

- Authenticated reconnects never accept cached `AGameMode::InactivePlayerArray` state as authoritative.
- `AddInactivePlayer` is intentionally disabled for DMF PlayerStates and `FindInactivePlayer` returns false, so the engine cannot swap a stale disconnected PlayerState over the freshly authenticated one.
- The server account SaveGame/database remains authoritative for Party, Bank, active partner GUID, avatar, Bits, progression, ABI and world location.
- Reconnect does not add a client persistence payload or RPC; credentials identify the server-owned account record exactly as before.
- The post-login integrity check only reloads server-owned persistent state if the authoritative component was not initialized as expected.

## v0.18.1 disconnect persistence networking contract

- Disconnect persistence is server-owned. No client RPC submits account contents, saved transforms, Digimon state, Bits or logout-save payloads.
- `ADMFMMOGameMode::Logout` finalizes the authenticated session before `Super::Logout`; the owner PlayerController `EndPlay` path is only an idempotent authority-side fallback.
- The final save synchronizes live partner HP/SP from the server combat component and merges only server-resident Party/Bank/avatar/location state into the existing account record.
- Once the pre-teardown save commits, `UDMFPlayerDigimonComponent::EndPlay` cannot perform a second account write. A failed primary save retains one guarded retry. An uninitialized account component is never allowed to overwrite persistent data.
- Summoned partners are destroyed on disconnect after their persistent instance has been saved. The persistent active-partner GUID remains private account state and is reconstructed on reconnect.
- RPC count remains 49 and account schema remains v7.

## v0.19.1 Social networking contract

The Social system adds four reliable RPC declarations, bringing the framework total from 49 to **53**:

- `ServerRequestSocialSnapshot` — owner requests a fresh read-only view.
- `ServerExecuteSocialAction` — one compact generic transport for mutations; the server derives acting identity from the authenticated PlayerState and never accepts it from the payload.
- `ClientReceiveSocialSnapshot` — reliable owner-only social view.
- `ClientSocialActionResult` — reliable owner feedback; the native UI uses non-modal status/chat feedback.

Friend/guild mutations are low-frequency persistent transactions rather than replicated arrays. Server-side throttling limits mutation spam; incoming generic text payloads have defensive ceilings before persistence logic. Cross-account and guild changes are committed through one rollback-safe SaveGame transaction.

Friend trackers add **zero distance RPCs**. The owning client observes the already replicated `ADMFPlayerAvatarCharacter` transform and calculates distance locally. Tracker Widget Components are transient and non-replicated; the persistent account stores only which accepted friends are enabled for tracking.

v0.19.1 Nearby Players discovery likewise adds **zero RPCs**: `GetNearbySocialPlayers()` scans replicated player avatars on the owning client, filters them against the configured metre radius, deduplicates public usernames and sorts distance locally. The resulting row is presentation-only. Selecting ADD/ACCEPT/CANCEL invokes the existing `ServerExecuteSocialAction` contract, so clients cannot use the discovery list to author relationship state.

Ignore does not alter relevancy, actor visibility, collision, possession or player replication. `ADMFMMOGameMode::DispatchWorldChatMessage` and late-join history hydration consult the recipient's persistent Ignore list only for user-authored `Player` messages. Presence events remain server-authored `PlayerJoined` / `PlayerLeft` messages.

Guild invitations live on the target account and guild applications live on the guild record, so both workflows tolerate either side being offline. Login/relog uses the existing authenticated persistent account authority; there is no dependence on Unreal inactive PlayerState caching.
