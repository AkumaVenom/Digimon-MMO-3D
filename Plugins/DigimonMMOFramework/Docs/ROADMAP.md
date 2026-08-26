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
- Server-authoritative materialization into the active Digimon inventory.
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

## Phase 4 — Digimon collection UX
- Functional native roster/select/summon/recall menu implemented in v0.5.0.
- Native drag/drop active Digimon inventory UI.
- Quick-access party/summon slots.
- Native Digimon Bank storage UI.
- Server-validated inventory ↔ bank drag/drop transactions.
- Sorting/filtering/inspection/stat-spend UI.

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
- Care-state digivolution requirements/hooks remain Phase 7 integration work.

## Phase 7 — Growth and digivolution
- EXP curves and level-up rewards.
- Attribute point grants/spending.
- Level + optional stat/care/ABI digivolution requirements.
- Server-authoritative digivolution with persistent species transition.

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

Future UI work can build on this presentation layer for full drag/drop party slots, bank storage, item inventory, Digivolution screens, scan/materialization, care and ranked-battle interfaces.

## Completed in v0.6.1–v0.6.2 — multiplayer possession and combat-facing polish

- v0.6.1 hardens late-join remote-client avatar recovery/possession and reapplies the account-selected player skin/active partner after authoritative recovery.
- v0.6.2 adds shared server-authoritative target-facing so partner and wild Digimon turn toward their current enemy before attack execution, with Blueprint-exposed turn rate/tolerance and no client-side combat-rotation authority.


### Completed polish: v0.6.4 ability execution reliability
- Capsule-aware melee/short-range reach across manual, reactive and automatic combat.
- Unified positive/zero-SP execution gate and authoritative cost deduction.
- AI controller yaw hardening for target-facing.

- Scan & Materialization — IMPLEMENTED in v0.7.0-alpha
- Future shared Digimon menu tabs: Bank, Party, Digivolution
