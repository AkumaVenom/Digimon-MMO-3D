# Networking / Host Deployment

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

## v0.11.0 global music networking contract

- Frontend/Open World/Battle music is **local presentation only** and adds no music RPC, replicated property or persistent account field.
- The local `UDMFMusicSubsystem` reads the active partner's already-replicated authoritative `CombatState`; it never predicts or changes combat authority.
- Battle music activates only from replicated `Chasing`, `Attacking` or `Recovering`, so merely selecting a command target does not create a false battle transition.
- Each player's music state is independent. One client entering combat cannot force unrelated clients to switch soundtrack.
- Persistent-across-travel 2D AudioComponents and crossfades are local AudioMixer/presentation behavior only. Dedicated servers do not render them.
- Music settings/assets are deployment/content configuration and do not consume runtime network bandwidth.

## v0.10.4 replicated player-footstep contract

- Footsteps exist only on `ADMFPlayerAvatarCharacter`; no Digimon actor receives this system.
- Grounded movement cadence is derived independently from authoritative server CharacterMovement state. When a stride threshold is reached, authority calls `MulticastPlayPlayerFootstep` as an **Unreliable NetMulticast** cosmetic RPC.
- Unreliable delivery is deliberate: footsteps are transient presentation, so a lost packet should disappear rather than queue and play late. No HP, inventory, persistence or movement authority depends on the event.
- A remote owning client separately predicts its own local footstep for immediate responsiveness. When the authoritative multicast returns to that owner, it is suppressed to avoid double playback; other relevant clients hear the server event.
- Listen hosts hear the authoritative event directly. Dedicated servers never render audio locally but still originate observer multicast events.
- The assigned Sound Cue/USoundBase and cadence controls are project configuration, not replicated runtime state. Projects should author attenuation in the Sound Cue so ordinary Unreal spatial audio limits audible range.

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

- The blank frontend/menu map may run locally before connection.
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


## Wild spawner authority

`DMFWildDigimonSpawner` performs proximity counting, target-population selection, rarity/species roll, level roll, ground/nav placement, respawn scheduling and destruction only on the authoritative server. The spawner replicates only small runtime state (`active`, `alive count`, `target population`); spawned Digimon are normal replicated actors.

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

## v0.6.0 UI authority note

The polished native UI pass does not move authority into UMG. Inventory slots, selected stats, active/summoned/defeated badges and combat HUD state are views of replicated/owner-owned framework data. Summon/recall, starter selection, player skin application, ability commands and healer use continue through their existing server-authoritative paths.

Portrait textures and ability icons are presentation assets resolved locally from Primary Asset data; they are not client-authored network state. Frontend `Logout` clears only locally staged connection credentials/admin unlock.


## v0.6.2 combat-facing replication contract
Combat facing is server-authoritative. Only the authority rotates the Digimon actor toward its attack target. The existing replicated Character movement carries yaw to clients; no client may independently decide or RPC arbitrary combat facing. Ability execution can wait for the authoritative yaw tolerance before SP/cooldown consumption and attack presentation begin.


## v0.6.4 ability authority / reach
Positive-SP and zero-SP abilities remain server-authoritative. Clients submit the slot/target request only. The server owns SP affordability, cooldown, capsule-aware range, facing, damage and impact revalidation. SP is deducted only after the execution gates succeed, and authoritative CurrentSP replication updates the owning HUD/clients.

## Scan & Materialization replication
Scan Data lives on the owning `UDMFPlayerDigimonComponent` and replicates owner-only. Rewards are calculated only on authority from the defeated species data. The client reward RPC exists for presentation; it does not carry permission to mutate Scan Data. Materialization requests send only a species ID, after which the server independently validates global/species settings, threshold, Collection capacity and partner class before creating the new owned Digimon. Persistence is written immediately after successful materialization and at the normal account save boundaries.


## Care replication and RPC contract

Care follows the same MMO trust boundary as combat and materialization:

`Owner CARE UI -> ServerFeedActivePartnerUntilFull -> server ownership/summon/health/idle/species/Montage/mesh/socket validation -> server care lock -> owner ClientCareSequenceStarted -> replicated DigiMeat + character multicast presentation -> server Hunger mutation/persistence -> repeat until full -> ClientCareSequenceFinished`

Clients never submit Hunger gain, decay, waste timing, mesh scale authority, sound index, completion timing or world spawn transforms. Species and project settings are resolved on authority. The owner-only `ReplicatedInventory` carries the persistent Care struct; other players do not receive another account's private Hunger ledger through that array. They see the normal replicated partner actor and the replicated care prop/cosmetic multicast required for shared-world presentation.

Waste uses persisted server UTC scheduling. At due time, authority traces beneath the currently spawned active partner and creates a replicated `ADMFDigimonCarePropActor`. `SpeciesId` and `PropType` replicate to resolve presentation for current/late viewers; actor movement/attachment or world transform is server-owned. The actor disables collision/overlaps/navigation and server lifespan performs cleanup. DigiMeat/poo CustomDepth and stencil application are local rendering state reasserted by the Care prop on each peer; they add no network payload or client authority.

During `bCareSequenceActive`, the owner component rejects conflicting set-active, recall, auto-battle, target and ability RPCs. The server also disables the partner's combat automation/target and stops AI movement before feeding, then restores the previously allowed auto-battle state on completion.

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
