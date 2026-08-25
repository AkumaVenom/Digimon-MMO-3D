# Networking / Host Deployment

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

## Intended topology

This baseline is intentionally **multiplayer gameplay only**:

- The blank frontend/menu map may run locally before connection.
- A normal player can only use the framework's regular **Join Game** path, which connects to the compiled fixed endpoint.
- An administrator who passes the extra Admin gate can choose **Host & Play**, causing the configured open-world map to open as an authoritative Unreal listen server.
- `ADMFMMOGameMode` rejects the concept of standalone gameplay and returns to the configured frontend when loaded without networking.

## Internet reachability

`Host & Play` starts an Unreal listen server; it does not configure the router, firewall, NAT or DNS automatically. For internet players to reach the host:

1. The configured game port (default `7777/UDP`) must be allowed through the host firewall.
2. NAT/router forwarding must send the public game port to the admin host PC when required.
3. The project's fixed DNS name must resolve to the public address that reaches the admin host.
4. The packaged client and host must use compatible cooked content/build versions.

## Replication policy

Private collection state is replicated owner-only. World partner actors are ordinary replicated actors so other players can see them. Gameplay-changing client requests are expected to use server RPCs and be validated server-side.


Player avatar skin selection follows the same authority boundary:

`Owning client UI -> PlayerState AvatarComponent server RPC -> registered Primary Asset / enabled / mesh validation -> persistent SelectedPlayerSkinId -> replication to all clients -> each client applies presentation to the same authoritative pawn`

Only the skin Primary Asset ID is accepted from the client. Skeletal mesh paths, Animation Blueprint classes and material overrides are resolved from server-cooked Data Assets. Skin switching never changes pawn ownership, possession, transform or Digimon state.

The starter grant demonstrates the persistent transaction pattern:

`Client UI request -> Server RPC -> server roster/capacity/eligibility validation -> authoritative mutation -> persistence -> replicated result`

Real-time combat follows the same authority boundary:

`Owned client command -> PlayerState server RPC -> active-partner/slot/target/rate validation -> optional leash-limited chase queue -> SP/cooldown/range revalidation -> authoritative impact/damage -> replicated state + cosmetic multicast cue`

Cooldown UI uses synchronized server world time rather than the local client's clock. Durable combat truth is replicated HP/SP/state/target/cooldown data; multicast attack/win/death cues are presentation only.

Inventory drag/drop, materialization, stat-spend, evolution and ranked-reward operations should continue to follow the same narrow validated-request contract.

## Authentication boundary

The alpha's built-in account gate is appropriate for private development and packaged multiplayer testing, but it is not a replacement for a production identity service. The credential digest in travel options is a bearer-equivalent value and can be replayed if intercepted.

For a public service, keep the PlayerState/account interfaces and replace the transport with a TLS authentication endpoint that issues short-lived signed session tickets. The game server should validate the ticket before accepting the connection.


## Wild spawner authority

`DMFWildDigimonSpawner` performs proximity counting, target-population selection, rarity/species roll, level roll, ground/nav placement, respawn scheduling and destruction only on the authoritative server. The spawner replicates only small runtime state (`active`, `alive count`, `target population`); spawned Digimon are normal replicated actors.

Wild `SpawnRarity`, `SpawnHomeLocation` and the compact ground-transition timing struct replicate with the actor. Emergence/sink mesh motion is reconstructed independently on every machine using synchronized server world time, avoiding reliable per-frame cosmetic transform traffic. AI roaming and combat movement remain server-driven through the existing replicated Character movement path.


## Manual partner commands / healer / roster authority (v0.5.0)

Owned partners do not need autonomous combat to remain network-correct. Manual target/ability requests use the existing owner-controlled route: `client DMFMMOPlayerController -> PlayerState DigimonComponent Server RPC -> authoritative partner CombatComponent`. `CommandPartnerTargetAndAttack` sends the requested target with the slot command so target selection and attack intent do not depend on two client RPCs arriving in separate frames.

Roster Set Active/Summon and Recall are owner-only server RPCs. The client supplies only an instance GUID; the server confirms the GUID belongs to that account inventory before changing active-partner state or spawning an actor.

Healer interaction uses the client-owned PlayerController as the RPC ingress because placed healer actors are not owned by arbitrary clients. The server revalidates healer reference, distance, enabled state and reuse delay, then performs the heal and persistence mutation. No healing amount, HP, SP or currency value is trusted from the client. The healer's multicast event is presentation-only.

## Native player interaction authority (v0.5.2)

The new player `Interact` function is intentionally a local discovery/input layer, not a gameplay-authority layer. The local pawn traces from its view and classifies the hit actor, but all supported gameplay mutations continue through existing server entry points.

Digimon target-only flow:

`Local DMFPlayerAvatarCharacter::Interact -> local Digimon classification -> DMFMMOPlayerController -> PlayerState DigimonComponent ServerSetCommandTarget -> server hostility/active-partner validation -> replicated CommandTarget`

Digimon target+attack flow:

`Local Interact/InteractWithDigimonAndAttack -> DMFMMOPlayerController -> PlayerState DigimonComponent ServerCommandActivePartnerAbilitySlot -> server target/slot/rate/SP/cooldown/leash/range validation -> authoritative combat`

Healer flow:

`Local Interact -> local healer classification -> DMFMMOPlayerController ServerRequestUseHealer -> healer authoritative enabled/range/reuse validation -> HealAllOwnedDigimon -> persistence`

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
