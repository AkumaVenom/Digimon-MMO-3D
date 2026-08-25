# Real-Time Combat Setup — v0.2.0-alpha

## v0.5.0 owned-partner control defaults

Player-owned partners now default to **manual combat**. In Project Settings → Digimon MMO Framework → Combat → Player Partner, leave `Player Partner Auto Battle` disabled unless you intentionally want autonomous owned-partner attacks. The partner still follows the player. Left Mouse selects a target and keys 1–4 issue attacks; Blueprint interaction systems can call `CommandPartnerTargetAndAttack(Target, SlotIndex)` directly.

Default player-partner battle tuning is 1.50x outgoing and 0.50x incoming damage. Ordinary Wild Digimon Blueprint classes remain 1.0/1.0. See `SETUP_MANUAL_COMBAT_HEALER_INVENTORY.md` for the complete workflow.


## 1. Create ability Data Assets
Create `DMFDigimonAbilityData` assets under `/Game/DigimonData`. For each ability configure:
- Ability ID / display name / icon.
- SP cost, cooldown, impact delay and recovery.
- Max range.
- Base power, STR or INT scaling, and defense scaling.
- Whether it is eligible for auto battle.
- Montage, Cascade particle, optional Niagara particle and attack sound.

The server owns damage, SP costs, cooldowns, target validation and defeat state. The multicast cue is presentation only.

## 2. Configure species
On each `DMFDigimonSpeciesData`:
- Add ability assets to `StartingAbilities` (the legacy `StartingAbilityIds` field remains supported).
- Set `BasicAutoAttack`.
- Set battle EXP and money rewards.
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
Player partners automatically:
- follow their player outside combat;
- acquire hostile Digimon in `PartnerAggroRange`;
- chase using the AI controller;
- use the configured Basic Auto Attack when in range;
- accept server-validated player ability commands from the quick bar;
- queue out-of-range commanded abilities, chase to range, then revalidate and execute them;
- abandon queued commands after the configurable `CombatCommandQueueTimeout` or when target/self violates the leash.

## 7. Persistence and rewards
Combat HP/SP is mirrored back into the owner's Fast Array Digimon instance. Account state autosaves on a configurable interval, on battle reward grant, on starter grant, and on logout.

Defeating a Digimon grants its configured Battle Experience to the active partner and Battle Money to the account. Level-up/stat-point logic remains Phase 7 so EXP can accumulate now without prematurely freezing the progression formula.
## Cel-shading Custom Depth

All actors derived from `ADMFDigimonCharacter` automatically force **Render CustomDepth Pass = true** on every owned mesh component. This applies to player partners, wild Digimon, NPC Digimon and future ranked-battle Digimon. The flag is reasserted at construction, BeginPlay, server instance initialization and client replicated-state refresh.

`CustomDepthStencilValue` is Blueprint-exposed (0-255, default 0), and `RefreshFrameworkCustomDepth()` can be called after dynamically adding/replacing a mesh component at runtime. No Custom Depth state is client-authored gameplay data; it is local presentation and costs no replication bandwidth.



## Wild proactive aggression vs retaliation (v0.5.5)

For ordinary wild Digimon use:

```text
Proactive Auto Battle (Aggressive) = False
Retaliate When Attacked = True
```

This means the wild Digimon will **not** acquire targets because they are nearby. When a hostile Digimon actually damages it, the authoritative damage pipeline establishes that attacker as the reactive target and the wild Digimon fights back using its Basic Auto Attack. Retaliation ends on victory, invalid target or leash break.

Player-owned partner Digimon are unaffected: their auto battle remains off by default and they continue to attack only through player commands.
