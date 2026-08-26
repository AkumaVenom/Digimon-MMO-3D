# Production Roadmap

The plugin is intentionally being built in dependency order rather than as isolated feature demos.

## Phase 1 — Foundation (complete in v0.1.0)
- Frontend login / fixed-host join / admin host flow.
- Server account persistence.
- Digimon species and unique-instance data model.
- Owner-only replicated Digimon inventory.
- Starter partner onboarding.
- 3D active partner spawning.

## Player avatar foundation extension (implemented in v0.3.0-alpha)
- Ready-to-use replicated third-person player pawn.
- Data-asset-driven human character skins.
- Automatic Asset Manager skin discovery.
- First-time character appearance onboarding.
- Persistent server-authoritative skin switching at runtime.
- Native reskinnable character selection/wardrobe UI.

## Player camera presentation polish — boom zoom & character-safe collision (implemented in v0.11.1-alpha)
- Automatic Mouse Wheel Up/Down local spring-arm zoom with project-wide default/min/max distances, wheel step and smoothing.
- Blueprint/Enhanced Input callable zoom API without adding camera replication or account persistence.
- Player avatars and Digimon globally ignore `ECC_Camera` so characters cannot shove another player's spring-arm camera inward.
- World/level camera obstruction remains active through the spring arm's normal `ECC_Camera` collision test.

## Player avatar presentation polish — footsteps (implemented in v0.10.4-alpha)
- Automatic grounded player-only footsteps with no animation-notify requirement.
- Project Settings Sound Cue/USoundBase assignment with global enable, cadence, volume and pitch controls.
- Distance-based walk/sprint/crouch cadence and skeleton-independent capsule-base audio origin.
- Immediate local-owner prediction plus server-authored Unreliable multicast presentation for other relevant players.

## World audio presentation polish — global music director (implemented in v0.11.0-alpha)
- Project Settings-driven Frontend/Main Menu, Open World and Battle music assets with a master enable switch.
- Automatic map-context switching plus replicated active-partner combat-state detection.
- Polished configurable crossfades, per-state/master volumes, battle-exit de-bounce and automatic replay for non-looping tracks.
- Local-per-player MMO presentation: no music RPCs or replicated soundtrack state; dedicated servers render no music.
- Blueprint GameInstanceSubsystem hooks for current state, state changes, immediate refresh and temporary cinematic suppression.

## Phase 2 — Real-time battle core (implemented in v0.2.0-alpha)
- Server-authoritative combat state machine.
- Wild/NPC/owned Digimon combatants.
- Wild/NPC autonomous basic attacks plus player command queue; owned partners default to manual commands (v0.5.0).
- Quick-access ability slots.
- Attack targeting, cooldowns, SP costs and damage formulas, including v0.6.4 repeat-safe buffered quick-slot input.
- Attack 1/2 montage + Cascade/Niagara execution and replicated cues.
- Death/win handling and battle rewards.

## Phase 3 — Capture progression (implemented in v0.7.0-alpha)
- Species scan-data ledger.
- Battle victory scan rewards.
- 100% materialization eligibility.
- Server-authoritative materialization; v0.12 routes new Digimon to Party first and Bank automatically when Party is full.
- Duplicate materialization rules and configurable scan caps.

## MMO presentation layer — world nameplates (implemented in v0.9.0-alpha)
- Automatic remote-player username plates using the public replicated PlayerState display-name channel.
- Automatic owned/wild Digimon plates with compact name, level, stage, attribute and replicated HP.
- Master + per-category global settings, draw-distance culling, capsule-relative height and native/Blueprint-reskinnable UI.
- Presentation remains client-side and does not introduce a second gameplay-authority path.

## MMO communication layer — world chat (implemented in v0.10.0-alpha)
- Native compact lower-left WORLD chat with Enter-to-chat / Enter-to-send / Escape-to-cancel input flow.
- Server-authored public usernames, sanitation/length validation and per-player anti-spam rate limits.
- Bounded server session history for late joiners without continuously replicating a global message array.
- Blueprint-reskinnable widget/events plus a master global enable switch and configurable history/safety limits.
- v0.10.1 native HUD safe-layout keeps WORLD chat above/clear of the centered partner quick-access bar with a configurable bottom offset.
- v0.10.2 centralizes the admin-host/player-join public endpoint in Project Settings; v0.10.3 also makes the Admin Host & Play password Project Settings-configurable with digest-only persistence, removing the remaining source edit from frontend deployment setup while preserving the authoritative listen-server flow.
- Future channel/guild/private-message/backend routing can extend the accepted-message hook without moving authority into UI.

## Phase 4 — Digimon Party & collection UX (major storage milestone implemented in v0.12.0-alpha)
- Functional native roster/select/summon/recall foundation — IMPLEMENTED in v0.5.0.
- Six-Digimon server-authoritative Party with account persistence — IMPLEMENTED in v0.12.0.
- Anywhere-access persistent Digimon Bank / paged Boxes — IMPLEMENTED in v0.12.0.
- Server-validated Party ↔ Bank moves plus full-Party atomic swaps — IMPLEMENTED in v0.12.0.
- Persistent six-slot Party Quick Access HUD with Tab mouse-interaction mode — IMPLEMENTED in v0.12.0.
- Materialization Party-first / Bank-overflow integration and schema-v4 legacy migration — IMPLEMENTED in v0.12.0.
- Direct drag/drop gestures, advanced sorting/filtering and stat-spend UX remain future presentation extensions over the authoritative storage API.
- Native Party/Bank/Scan/Care and Party/combat quickbar layout hardening — IMPLEMENTED in v0.12.1 (scroll-clipped detail bodies, fixed Bank card sizing, compact HUD cards).
- Polished replicated healer treatment presentation — IMPLEMENTED in v0.12.2 (exclusive one-player station lock, pulsing green interior light, Niagara-preferred/Cascade fallback VFX, spatial heal audio, Party + all Bank/Boxes restoration, Blueprint start/finish hooks).

## Phase 5 — Player item inventory
- Data-asset item definitions.
- Replicated stack inventory.
- Native drag/drop item UI and quick slots.
- Feed items integrated with Digimon care.

## Phase 6 — Virtual-pet care (core implemented in v0.8.0-alpha)
- Persistent Hunger/fullness with server UTC online/offline decay — IMPLEMENTED.
- Unlimited DigiMeat feeding with per-species hand socket, transform/scale, sequential eating Montages and voice cues — IMPLEMENTED.
- Feeding presentation hides the Digimon Menu/quickbar, then returns directly to CARE — IMPLEMENTED.
- Persistent server time-based waste scheduling — IMPLEMENTED.
- Replicated, scalable, no-collision world poo actor placed on traced ground at the Digimon's standing location — IMPLEMENTED.
- DigiMeat and poo automatically participate in framework CustomDepth/cel-shading presentation with Blueprint-tunable stencil value — IMPLEMENTED in v0.8.1-alpha.
- Fart presentation + automatic waste cleanup lifetime — IMPLEMENTED.
- Happiness, Discipline and Care Mistakes are persistent/exposed foundations; gameplay rules that mutate them remain future care expansion.
- Care-state Happiness/Discipline/Care-Mistake Digivolution requirements are integrated in v0.13.0; future Care work can add richer ways to mutate those values.

## Phase 7 — Growth and digivolution (Digivolution core implemented in v0.13.0-alpha)

- Digivolution Owned Digimon Party/Bank card aspect-ratio and sparse-row layout hardening — **FIXED in v0.13.1-alpha**.
- EXP curves and level-up rewards — future expansion.
- Attribute point grants/spending — future expansion.
- Level + ABI/CAM + optional stat/Care/economy Digivolution requirements — **IMPLEMENTED in v0.13.0-alpha**.
- Server-authoritative persistent species transition for Party + Bank — **IMPLEMENTED in v0.13.0-alpha**.
- Replicated active-partner transformation presentation and target-form actor replacement — **IMPLEMENTED in v0.13.0-alpha**.
- Persistent Origin Species + Digivolution History schema-v5 provenance — **IMPLEMENTED in v0.13.0-alpha**.
- More advanced EXP curves, attribute-spend UX and project-specific de-Digivolution rules remain future growth work.

## Phase 8 — Ranked NPC arena
- Data-driven ranked teams.
- F → S+ progression ladder.
- Arena challenge flow.
- Money and ranked battle-point rewards.
- Native ladder/team/reward UI.

## Phase 9 — MMO hardening
- Auth-provider abstraction with TLS session tickets.
- Database provider interface and transactional persistence.
- reconnect/session recovery;
- anti-duplication transaction IDs;
- rate limits and RPC abuse protection;
- scale testing, relevancy/dormancy tuning and profiling.


## Completed foundation additions

- Wild proximity / rarity spawner: server-authoritative activation/unload, weighted rarity entries, min/max population, roaming/leashing, NavMesh-grounded placement, delayed respawn and synchronized ground emergence/despawn presentation (v0.4.1-alpha; v0.4.0 feature foundation, v0.4.1 capsule-placement fix).

- Manual owned-partner combat controls, player/wild role balance, free server-authoritative healer actor, and native Digimon roster/summon/recall UI implemented in v0.5.0-alpha.

- Native no-cast player interaction/targeting implemented in v0.5.2-alpha: one player `Interact` call handles Digimon target selection and healer use, with exposed trace settings, optional target+attack behavior, native `E` input and Blueprint extension hooks while preserving server authority.

- Deterministic defeated-pose locking and passive-until-attacked wild retaliation implemented in v0.5.5-alpha. Wild proactive aggression and defensive retaliation are separate server-authoritative policies; ordinary wild Digimon default to peaceful roaming until damaged.

## Completed in v0.6.0 — native UI presentation pass

- Polished frontend login/play/admin state.
- Portrait-card starter selector.
- Portrait-card player skin selector.
- 6-column Digimon collection/summon grid with selected stats.
- Icon-capable bottom-center combat quick bar.
- Shared native visual language and backward-compatible optional widget bindings.

v0.12 builds Party, Bank/Boxes and Party Quick Access on this presentation layer; v0.13 adds persistent branching Digivolution into the same shell. Future UI work can add direct drag/drop gestures, sorting/filtering, item inventory, stat-spend and ranked-battle interfaces without replacing the authoritative storage/evolution model.

## Completed in v0.6.1–v0.6.2 — multiplayer possession and combat-facing polish

- v0.6.1 hardens late-join remote-client avatar recovery/possession and reapplies the account-selected player skin/active partner after authoritative recovery.
- v0.6.2 adds shared server-authoritative target-facing so partner and wild Digimon turn toward their current enemy before attack execution, with Blueprint-exposed turn rate/tolerance and no client-side combat-rotation authority.


### Completed polish: v0.6.4 ability execution reliability
- Capsule-aware melee/short-range reach across manual, reactive and automatic combat.
- Unified positive/zero-SP execution gate and authoritative cost deduction.
- AI controller yaw hardening for target-facing.

- Scan & Materialization — IMPLEMENTED in v0.7.0-alpha
- Shared Digimon menu Party + Bank/Boxes tabs — IMPLEMENTED in v0.12.0-alpha.
- Persistent Party/Bank Digivolution with native tab and replicated active-partner transformation — IMPLEMENTED in v0.13.0-alpha.

## Completed — v0.14 DigiDex Species Encyclopedia
- Read-only Asset-Manager-backed implemented-species registry.
- Search + Stage/Attribute filters, discovery badges, base profile, Scan/ownership status, evolution-family links and species descriptions.
- No new replication or persistence channel; designed to scale as the project begins mass species population.
