# Real-Time Combat Setup — v0.14.8-alpha

## v0.5.0 owned-partner control defaults

Player-owned partners now default to **manual combat**. In Project Settings → Digimon MMO Framework → Combat → Player Partner, leave `Player Partner Auto Battle` disabled unless you intentionally want autonomous owned-partner attacks. The partner still follows the player. Left Mouse selects a target and keys 1–4 issue attacks; Blueprint interaction systems can call `CommandPartnerTargetAndAttack(Target, SlotIndex)` directly.

Default player-partner battle tuning is 1.50x outgoing and 0.50x incoming damage. Ordinary Wild Digimon Blueprint classes remain 1.0/1.0. See `SETUP_MANUAL_COMBAT_HEALER_INVENTORY.md` for the complete workflow.


## 1. Create ability Data Assets
Create `DMFDigimonAbilityData` assets under `/Game/DigimonData`. For each ability configure:
- Ability ID / display name / icon.
- SP cost, cooldown, impact delay and recovery.
- Max range.
- Base power, STR or INT scaling, and defense scaling.
- Whether it is eligible for auto battle. In v0.14.7, every equipped ability with `bEligibleForAutoBattle=true` participates in autonomous full-moveset selection; disable it only for moves the AI must never choose.
- Montage, Cascade particle, optional Niagara particle and attack sound.
- `Execution Mode`: keep **Timed / Instant Impact** for direct attacks, or choose **Replicated Projectile** for fireballs/bolts/rockets that must physically travel to the enemy.
- Projectile mode exposes launch socket/offset, moving Niagara/Cascade/mesh, speed, homing, visual rotation correction, impact radius, hard lifetime cleanup, impact VFX/audio and an optional custom projectile Blueprint class.
- Timed presentation VFX now have a forced `Presentation VFX Lifetime Seconds` cleanup guard, so looping Niagara/Cascade systems cannot accumulate indefinitely.

The server owns damage, SP costs, cooldowns, target validation, projectile arrival and defeat state. Multicast cues remain presentation only. See `SETUP_ABILITY_PROJECTILES.md` for the full projectile workflow.

## 2. Configure species
On each `DMFDigimonSpeciesData`:
- Add ability assets to `StartingAbilities` (the legacy `StartingAbilityIds` field remains supported).
- Set `BasicAutoAttack`.
- Set battle EXP and money rewards. Battle EXP now drives the server-authoritative owned-Digimon leveling system.
- Author the existing HP/SP/STR/INT/DEF/SPD Per Level and Attribute Points Per Level values used whenever this species gains a level.
- Set this species' `Base Experience Required` and `Experience Growth Multiplier Per Level`; optionally set `Max Level Override`. No CurveFloat asset is required.
- Keep Attack1 / Attack2 montage and Cascade fields if you want species-level presentation overrides for quick slots 1 and 2.

## 3. Navigation requirement
Place a `NavMeshBoundsVolume` over every combat/exploration area where Digimon should chase or follow. The framework uses the authoritative AI controller for movement, so navigation must be valid on the server.

## 4. Wild/NPC Digimon
Create a Blueprint derived from `ADMFWildDigimonCharacter` and configure:
- Species
- Level
- WildCombatTeamId
- Auto Battle
- Aggro Range
- Leash Range

Actors with the same non-empty `CombatTeamId` are friendly by default. Different teams are hostile and eligible for autonomous targeting.

## 5. Player partner commands
`ADMFDigimonCharacter` includes a replicated `DMFDigimonCombatComponent`. Player-owned commands are deliberately routed through `UDMFPlayerDigimonComponent` on the owning PlayerState:
- `Server Set Command Target`
- `Server Command Active Partner Ability Slot`

This prevents a client from directly authoring damage/cooldown/SP state on the spawned partner.

By default, `ADMFMMOPlayerController` binds **Left Mouse Button** to target selection (actual cursor when visible, screen centre when the cursor is hidden) and number keys **1–4** to the four quick slots. Disable `bEnableDefaultCombatInputBindings` if your project wants to own those bindings through Enhanced Input. The native quick bar is also clickable and can be replaced with a Blueprint subclass in Project Settings.

## 6. Automatic partner behavior
When **Player Partner Auto Battle** is deliberately enabled, autonomous partners:
- follow their player outside combat;
- acquire hostile Digimon in `PartnerAggroRange`;
- choose fairly from the complete equipped `ReplicatedAbilityIds` moveset, limited to abilities whose `bEligibleForAutoBattle` flag is enabled;
- respect SP, per-move cooldowns and each selected move's own range;
- keep a selected move stable while chasing so mixed melee/ranged moves do not oscillate;
- accept server-validated player ability commands from the quick bar;
- queue out-of-range commanded abilities, chase to range, then revalidate and execute them;
- abandon queued commands after the configurable `CombatCommandQueueTimeout` or when target/self violates the leash.

## 7. Persistence and rewards
Combat HP/SP is mirrored back into the owner's Fast Array Digimon instance. Account state autosaves on a configurable interval, on battle reward grant, on starter grant, and on logout.

Defeating a Digimon grants its configured Battle Experience to the active partner and Battle Money to the account. As of v0.14.8, Battle EXP is consumed through authoritative level thresholds, can cross multiple levels in one reward, applies the species' existing per-level HP/SP/STR/INT/DEF/SPD growth, grants `Attribute Points Per Level`, refreshes the summoned partner's public replicated stats without resetting combat, and persists the owned instance.

The native Party/Bank panels show current EXP / required EXP and the owner receives the queued animated EXP / LEVEL UP presentation. Requirements come directly from each species' numeric base EXP and per-level growth multiplier. See `SETUP_LEVEL_PROGRESSION.md` for the full authoring, migration, UI and networking contract.
## Cel-shading Custom Depth

All actors derived from `ADMFDigimonCharacter` automatically force **Render CustomDepth Pass = true** on every owned mesh component. This applies to player partners, wild Digimon, NPC Digimon and future ranked-battle Digimon. The flag is reasserted at construction, BeginPlay, server instance initialization and client replicated-state refresh.

`CustomDepthStencilValue` is Blueprint-exposed (0-255, default 0), and `RefreshFrameworkCustomDepth()` can be called after dynamically adding/replacing a mesh component at runtime. No Custom Depth state is client-authored gameplay data; it is local presentation and costs no replication bandwidth.



## Wild proactive aggression vs retaliation (v0.5.5)

For ordinary wild Digimon use:

```text
Proactive Auto Battle (Aggressive) = False
Retaliate When Attacked = True
```

This means the wild Digimon will **not** acquire targets because they are nearby. When a hostile Digimon actually damages it, the authoritative damage pipeline establishes that attacker as the reactive target and the wild Digimon fights back using its complete currently usable auto-battle moveset. `BasicAutoAttack` remains part of that pool, but it is no longer the only move the automation loop can execute. Retaliation ends on victory, invalid target or leash break.

Player-owned partner Digimon are unaffected: their auto battle remains off by default and they continue to attack only through player commands.

## Attack VFX CustomDepth (v0.14.6)

Framework-owned attack particle presentation now always enables **Render CustomDepth Pass** at runtime. Direct ability VFX, replicated projectile Niagara/Cascade visuals and projectile impact VFX are covered. The framework intentionally does not overwrite a project's CustomDepth stencil value; it guarantees only that the relevant runtime particle component participates in the pass. The local enemy overhead target arrow uses the same invariant. See `SETUP_ABILITY_PROJECTILES.md` and `SETUP_COMBAT_TARGETING_VISUALS.md` for the detailed lifecycle.


## Full autonomous moveset selection (v0.14.7)

The authoritative automation loop no longer hard-wires `BasicAutoAttack`. It builds its candidates from the Digimon's runtime `ReplicatedAbilityIds` (with Basic Auto Attack retained as a compatibility fallback), filters out abilities that are not auto-battle eligible or cannot currently be paid/used, and selects by least-recently-used fairness. This means all currently usable moves receive turns before a recently used move becomes preferred again.

The selection history and pending move are **server-only transient AI state**. Clients do not choose abilities and no additional replicated property/RPC exists. The move itself still executes through `TryExecuteAbilityById`, so existing server SP deduction, cooldown creation, range/facing validation, projectile/timed-impact behavior, damage and defeat logic remain the single authoritative execution path.

For a wild Digimon intended to use four attacks, put all four ability assets in `StartingAbilities`/the runtime moveset and leave `bEligibleForAutoBattle=true` on each. If a move is support/manual-only, disable that flag and automation will never select it.
