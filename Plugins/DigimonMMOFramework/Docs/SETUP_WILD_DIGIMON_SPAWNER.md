# Wild Digimon Proximity / Rarity Spawner Setup — current through v0.14.5-alpha


## v0.4.1 placement correction

The spawner treats a traced/NavMesh point as the **floor**, not as the Character actor origin. It automatically reads the selected `BP_Wild_<Species>` capsule half-height and raises the actor origin so the capsule bottom rests on the ground. Do not manually add capsule half-height to `Spawn Ground Offset`; that field should remain a small surface clearance such as `2.0`.

If a spawner activates but cannot create a Wild Digimon, inspect the server Output Log. v0.4.1 reports whether there is no eligible spawn entry or placement repeatedly failed due to ground collision, NavMesh coverage, minimum player distance, or blocking geometry.

`ADMFWildDigimonSpawner` is the framework's server-authoritative MMO population actor. Place/derive it in the open world; clients never roll species, rarity, level or population locally.

## 1. Prerequisites

For every spawnable species, create:

1. `DMFDigimonSpeciesData` (stats/abilities/rewards).
2. A Blueprint derived from `DMFWildDigimonCharacter`, e.g. `BP_Wild_Gabumon`.
3. On that Blueprint's inherited Mesh: assign Gabumon's Skeletal Mesh and Gabumon's compatible AnimBP.
4. Ensure the gameplay area is covered by `NavMeshBoundsVolume` if `Require Navigable Spawn` or free roaming is enabled.

The spawner uses deferred spawning so `Species`, `Level`, rarity, AI, roaming and emergence parameters are assigned before the wild Blueprint runs BeginPlay.

## 2. Create a Blueprint spawner

Create Blueprint Class -> All Classes -> `DMFWildDigimonSpawner`.

Recommended name:

`BP_WildSpawner_Forest01`

Place it near the centre of the intended encounter area. The `SpawnAreaPreview` sphere visualizes `Spawn Radius` in the editor and has no runtime collision.

## 3. Activation / streaming settings

Suggested first test:

- Spawner Enabled: true
- Minimum Nearby Players: 1
- Activation Radius: 5000
- Deactivation Radius: 6500
- Proximity Check Interval: 1.0 s
- Deactivation Grace Period: 5.0 s
- Use 2D Player Distance: true

The separate activation/deactivation radii provide hysteresis so a player standing near the edge does not constantly load/unload the population.

## 4. Population

Suggested first test:

- Minimum Spawn Count: 3
- Maximum Spawn Count: 6
- Population Spawn Interval: 0.25 s
- Minimum Respawn Delay: 8 s
- Maximum Respawn Delay: 15 s
- Defeated Despawn Delay: 3 s

On activation the authority chooses one target population in the inclusive min/max range. Initial spawns are staggered. A defeated managed wild is removed from the alive count immediately, its death presentation remains for `Defeated Despawn Delay`, and one replacement token becomes eligible after a random respawn delay.

## 5. Spawn area / grounding

Suggested first test:

- Spawn Radius: 1800
- Minimum Spawn Distance From Players: 450
- Max Placement Attempts Per Spawn: 12
- Ground Trace Height: 2000
- Ground Trace Depth: 5000
- Ground Trace Channel: Visibility
- Require Navigable Spawn: true
- Navigation Projection Extent: (250, 250, 500)
- Spawn Ground Offset: 2

Each spawn samples a uniform random point over the circular area (not edge-biased), traces for actual ground, optionally projects to navigation, rejects locations too close to a player, and uses collision-aware deferred actor creation.

## 6. Ground emergence / despawn

Suggested:

- Use Ground Emergence: true
- Ground Emergence Depth: 140
- Ground Emergence Duration: 1.0 s
- Use Ground Despawn When Inactive: true
- Ground Despawn Duration: 0.65 s

The authoritative actor remains at its real ground/nav position while only the inherited visual mesh is offset below ground and interpolated upward. The transition timing state is replicated; every machine reconstructs the same smooth rise using synchronized server world time instead of replicating cosmetic mesh movement every frame.

During emergence/despawn:

- combat targetability is disabled on the authority;
- AI movement is stopped;
- capsule collision is locally suppressed during the transition;
- auto-battle is paused;
- after emergence, collision/movement/auto-battle are restored and roaming begins.

For unusually small or large species, enable `Override Ground Emergence` on that Spawn Entry and set its own depth/duration.

Blueprint cosmetic hooks on `DMFWildDigimonCharacter`:

- `BP_OnGroundTransitionStarted`
- `BP_OnGroundTransitionFinished`

Use these for dust, rings, sounds, etc.; the native mesh rise/sink already works without Blueprint logic.

## 7. AI / leash / free roaming

Suggested:

- Enable Auto Battle: true
- Aggro Range: 1000
- Leash Radius: 1800
- Wild Combat Team Id: Wild
- Enable Free Roaming: true
- Roam Radius: 850
- Minimum Roam Delay: 2.0
- Maximum Roam Delay: 5.5
- Roam Acceptance Radius: 75

Every spawned wild receives its own `SpawnHomeLocation`. Idle roaming selects random *reachable* NavMesh points inside `Roam Radius` around that home. Combat uses the same initial spawn point as its authoritative home and cannot chase beyond `Leash Radius`. The framework clamps roam radius to leash radius.

## 8. Rarity system

Spawner rarity base weights are relative, not literal percentages:

- Common: 100
- Uncommon: 35
- Rare: 10
- Epic: 3
- Legendary: 1
- Mythic: 0.25

As of v0.14.5, selection is deliberately **two-stage**:

1. The authoritative server rolls one currently eligible `Rarity` tier using the spawner's `Rarity Weights`.
2. Inside that selected tier, it rolls one eligible spawn entry using `Selection Weight Multiplier`.

This means the number of species inside a rarity tier **does not multiply that tier's chance**. Adding five more Uncommon species broadens which Uncommon Digimon can appear; it does not give the Uncommon tier five extra copies of its base rarity weight.

Each spawn entry has:

- `Rarity` — chooses which tier-level probability pool the entry belongs to.
- `Selection Weight Multiplier` — relative species weight **within that rarity tier**.
- `Max Alive From Entry` — removes a capped entry from the eligible within-tier pool until capacity becomes available again.

For entries inside the same selected rarity tier, a multiplier of `1.0` is twice as likely as `0.5`. A multiplier of `0.0` makes that entry ineligible without removing it from the table.

Example entries:

### Gabumon
- Entry Id: Gabumon
- Species: `DA_Species_Gabumon`
- Wild Character Class: `BP_Wild_Gabumon`
- Rarity: Common
- Selection Weight Multiplier: 1.0
- Max Alive From Entry: 0 (unlimited inside total population)
- Minimum Level: 2
- Maximum Level: 5

### Elecmon
- Rarity: Uncommon
- Multiplier: 1.0
- Max Alive: 2
- Level: 3-6

### BlackGabumon
- Rarity: Rare
- Multiplier: 1.0
- Max Alive: 1
- Level: 5-8

### Rare boss/example
- Rarity: Legendary
- Max Alive From Entry: 1

A cap of 1 ensures that entry cannot have multiple live copies from the same spawner, regardless of future rolls. If every enabled entry has a finite cap, target population is automatically clamped to the total possible capacity.

### v0.14.5 normalization example

If `Common = 1.0` and `Uncommon = 0.5`, and both tiers have at least one eligible entry, the tier roll is approximately **66.7% Common / 33.3% Uncommon** regardless of whether Common has 2 species and Uncommon has 2, 6, or 20 species. Once a tier wins, its own entry multipliers decide which species from that tier appears.

This is the important distinction from v0.14.4 and earlier: rarity controls the **tier chance**; entry multiplier controls the **species distribution inside that tier**.

`SpawnRarity` is replicated on each `DMFWildDigimonCharacter`, ready for Blueprint nameplates, aura cosmetics, future loot/scan multipliers and other MMO presentation.

## 9. Blueprint runtime calls/events

Spawner calls:

- `Refresh Spawner Now`
- `Force Activate Spawner`
- `Force Deactivate Spawner`
- `Spawn One Wild Digimon` (authority only)
- `Is Spawner Active`
- `Get Alive Spawn Count`
- `Get Target Population`

Spawner events:

- `BP_OnSpawnerStateChanged`
- `BP_OnWildDigimonSpawned`

All gameplay-changing calls are authority-only.

## 10. Multiplayer acceptance test

1. Place one spawner inside valid NavMesh.
2. Set population 3-5 and add at least two rarity entries.
3. Start listen host with one remote client connected.
4. Keep both players outside Activation Radius: zero managed wild should exist.
5. Host enters radius: server chooses target population and spawns actors gradually.
6. Both machines see each Digimon rise through the ground at the same location/timing.
7. Verify all spawned meshes retain framework Custom Depth/cel shading.
8. Wait while idle: Digimon free-roam but remain around their individual home points.
9. Enter combat and drag a target: wild combat must abandon/return rather than exceed its leash.
10. Defeat one wild: death presentation remains, replacement appears only after respawn delay.
11. Verify rarity and level rolls match on host/client (`SpawnRarity` and replicated stats).
12. Move every player beyond Deactivation Radius for the grace period: remaining wild sink/despawn and the target population becomes zero.
13. Re-enter: a new target population and new rarity/level rolls are generated.

## Production notes

- Spawner population is intentionally ephemeral world state, not account persistence.
- Spawn/rarity/level decisions are never accepted from clients.
- Proximity checks run on a configurable timer, not Tick.
- Wild roaming is timer-driven and only performs NavMesh queries while idle.
- Initial and replacement spawns are staggered to avoid frame spikes.
- Large worlds should use multiple localized spawners rather than one huge spawn radius.


## v0.5.5 wild combat behavior — recommended MMO setup

Wild combat now separates **starting fights** from **defending itself**. You do not need to choose between “always hostile” and “never fights back.”

For the normal Digimon MMO behavior requested here, set each `BP_Wild_<Species>` to:

```text
Proactive Auto Battle (Aggressive) = False
Retaliate When Attacked = True
```

And set the spawner under **Digimon MMO -> Wild Spawner -> AI** to:

```text
Allow Proactive Auto Battle = False
Allow Retaliation When Attacked = True
```

The result is:

```text
Player approaches wild Digimon
    -> wild keeps roaming / does not attack

Player targets it but does not damage it
    -> wild still does not attack

Player partner lands a damaging hit
    -> server sets that attacking partner as the retaliation target
    -> wild chases if required
    -> wild uses its Basic Auto Attack
    -> fight continues normally

Attacker dies / becomes invalid / leaves wild leash
    -> retaliation ends
    -> wild returns to idle/free roaming
```

`Proactive Auto Battle (Aggressive)` is only for Digimon that should initiate combat merely because an enemy is within `Aggro Range`. `Retaliate When Attacked` is independent and continues to work when proactive auto battle is off.

The spawner's existing optional per-entry Auto Battle override only affects **proactive aggression**. It never disables retaliation. This keeps ordinary encounter setup simple while still allowing intentionally aggressive rare/boss entries when needed.


## v0.14.7 wild combat moveset note

Spawner combat policy still decides **whether** a wild Digimon may proactively acquire targets and/or retaliate. Once a wild Digimon is in an authoritative fight, v0.14.7 makes its combat component choose from the complete currently usable equipped moveset instead of repeating only `BasicAutoAttack`. Put the desired abilities on the species/runtime moveset and keep `bEligibleForAutoBattle=true` for moves the enemy AI is allowed to perform. Ability choice remains server-only and respects SP, cooldown, target validity, leash and each move's own capsule-aware range.
