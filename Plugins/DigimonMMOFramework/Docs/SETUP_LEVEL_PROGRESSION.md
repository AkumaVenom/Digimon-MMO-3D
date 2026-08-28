# Owned Digimon Level Progression & Native EXP UI — v0.14.8-alpha

v0.14.8 turns the existing persistent `Level` / `Experience` fields into a complete owned-Digimon growth loop. Battle rewards, threshold consumption, level changes, stat growth, Attribute Point grants and persistence are server-authoritative. The client receives owner-only replicated results and presentation snapshots; UMG never decides a level or reward.

## 1. Species-owned EXP requirements — no CurveFloat asset

Every `DMFDigimonSpeciesData` owns its own leveling pace under **Progression -> Leveling**:

- `Base Experience Required` — EXP required for this species to advance from Level 1 to Level 2.
- `Experience Growth Multiplier Per Level` — multiplies the previous level requirement as Level increases.
- `Max Level Override` — optional species/form cap; `0` uses Project Settings -> `Default Max Digimon Level`.

The deterministic requirement formula is:

```text
EXP Required(CurrentLevel)
= Base Experience Required
  * (Experience Growth Multiplier Per Level ^ (CurrentLevel - 1))
```

The final result is rounded to the nearest whole EXP and safely clamped before use. Both the authoritative progression code and native UI use the same shared calculation.

Example:

```text
Base Experience Required = 100
Experience Growth Multiplier Per Level = 1.20

Level 1 -> 2 : 100 EXP
Level 2 -> 3 : 120 EXP
Level 3 -> 4 : 144 EXP
Level 4 -> 5 : 173 EXP
Level 5 -> 6 : 207 EXP
```

A species with `Base=180 / Multiplier=1.20` naturally levels more slowly than one with `Base=75 / Multiplier=1.10`. `Multiplier=1.0` creates a flat requirement at every level. No CurveFloat, Data Table or external progression asset is required.

`Stats.Experience` is **progress inside the current level**, not lifetime EXP. When a threshold is crossed the requirement is subtracted, Level increments, and the remainder carries into the next level. One large reward can cross multiple levels.

At the effective maximum level the instance keeps its Level and stores `0` progress-to-next-level EXP. Lowering a configured cap later never de-levels an already higher persistent Digimon.

## 2. Project Settings

Open:

**Project Settings -> Game -> Digimon MMO Framework -> Progression -> Leveling**

Configure:

- `Enable Owned Digimon Leveling` — master switch for automatic threshold/level processing.
- `Default Max Digimon Level` — global cap used only when a species leaves `Max Level Override` at `0`.

EXP pacing itself is deliberately **not global**. Each species owns its own base requirement and numeric growth multiplier so designers can tune In-Training, Rookie, Champion, Ultimate, Mega or individual species independently from their Data Assets.

## 3. Per-species authoring examples

### Fast early-growth species

```text
Base Experience Required = 75
Experience Growth Multiplier Per Level = 1.10
```

### Standard species

```text
Base Experience Required = 100
Experience Growth Multiplier Per Level = 1.20
```

### Slow-growth species

```text
Base Experience Required = 180
Experience Growth Multiplier Per Level = 1.25
```

These values are examples only; the project controls its economy entirely from the species assets.

### Digivolution note

Level and current EXP remain attached to the same persistent Digimon instance across Digivolution. The **current species/form** supplies the EXP base, growth multiplier, max-level override and per-level stat growth for future level gains. Digivolution does not create a second EXP ledger.

## 4. Stat growth on level-up

v0.14.8 reuses the growth fields already authored on each species:

- `HP Per Level`
- `SP Per Level`
- `Strength Per Level`
- `Intelligence Per Level`
- `Defense Per Level`
- `Speed Per Level`
- `Attribute Points Per Level`

For every level gained, authority applies those values to the owned instance. Multi-level rewards multiply the same authored per-level growth by the number of levels crossed.

Current HP/SP are handled without resetting combat:

- Max HP/SP increase by their authored growth.
- A living Digimon receives the same capacity delta to Current HP/SP, preserving the amount already missing/spent rather than performing a full heal.
- A defeated Digimon remains defeated; level growth never revives it.
- Target, cooldowns, recovery, active encounter state and AI/combat intent are not reset by the progression refresh.

The resulting public Level/stats on a summoned partner are refreshed on the authoritative world actor and continue through normal actor/property replication for nearby players and nameplates.

`UnspentAttributePoints` is persistent and receives `Attribute Points Per Level`. v0.14.9 completes the loop with server-authoritative spending on Max HP, Max SP, STR, INT, DEF and SPD through the native Party/Bank `+` buttons or Blueprint API. See `SETUP_ATTRIBUTE_POINTS.md`.

## 5. Existing account migration / banked EXP

No SaveGame schema field is added for v0.14.8: Level, Experience, stats and unspent Attribute Points already existed in the persistent Digimon instance.

During authoritative account hydration, stored EXP is normalized through the current species' numeric leveling requirements. This lets v0.14.7 and older accounts that accumulated Battle EXP without leveling receive the levels they had already earned. The server applies the levels/stat growth once and persists the normalized result at the next normal save boundary.

This migration is authority-only and never trusts a client-computed level.

## 6. Native Party / Bank EXP presentation

The native Digimon Menu presents progression for both Party and Bank selections:

```text
LEVEL 7
EXP 84 / 299
[=============-------]
ATTRIBUTE PTS 6
```

At the cap, the EXP row displays `MAX` and the progress bar is full. The native UI uses the exact same species-owned numeric requirement calculation as authority.

Blueprint projects may use:

- `Get Experience Required For Level(SpeciesId, CurrentLevel)`
- `Get Maximum Level For Species(SpeciesId)`
- `Get Experience Required For Next Level(InstanceId)`
- `Get Experience Progress Normalized(InstanceId)`

These are read-only progression helpers on `DMFPlayerDigimonComponent`.

## 7. Fortnite-style EXP gain notification

When authoritative Battle EXP is granted, the owning player receives a compact immutable `FDMFDigimonExperienceProgression` result snapshot. The default `DMFExperienceNotificationWidget` queues those results locally and presents:

- Digimon portrait/species name;
- exact `+ EXP` reward;
- current Level;
- animated progress-to-next-level bar;
- current / required EXP text;
- a distinct gold `LEVEL UP! old -> new` row revealed when the animated bar crosses the first earned threshold;
- Attribute Points granted by that level-up.

The animation can traverse multiple level segments from one large reward. Rapid scripted rewards are queued rather than replacing the active presentation. The notification is **owner-only presentation**.

### UI settings

Under **Project Settings -> Digimon MMO Framework -> UI -> Progression**:

- `Experience Notification Widget Class`
- `Show Native Experience Notifications`
- `Experience Progress Animation Seconds`
- `Experience Notification Hold Seconds`
- `Level Up Notification Hold Seconds`
- `Experience Notification Bottom Safe Offset`

Blueprint child widgets can use:

- `BP On Experience Progress Presented`
- `BP On Level Up Presented`

Those hooks are cosmetic only. The snapshot describes what authority already committed; it cannot request EXP or levels.

## 8. Networking contract

```text
Server combat defeat
 -> Resolve defeated species BattleExperienceReward
 -> Active owned Digimon Fast Array entry
 -> ApplyExperienceReward
 -> calculate current species numeric requirement
 -> consume thresholds / apply stat growth / grant attribute points
 -> mark owner-only Fast Array dirty
 -> refresh summoned partner public ReplicatedStats
 -> persist account
 -> owner ClientDigimonExperienceProgressed(snapshot)
 -> local queued EXP / LEVEL UP presentation
```

Clients do not submit reward values, new Level, requirements, stat-growth values, Attribute Points or max-level state. Durable truth remains the server-owned persistent instance plus its existing owner-only Fast Array replication.

## 9. Recommended acceptance test

1. Set the active species to `Base Experience Required=100`, `Experience Growth Multiplier Per Level=1.20`; use a Level 1 partner with `0 EXP`.
2. Set a wild Digimon reward to `25 EXP`; defeat it four times.
3. Confirm `0/100 -> 25/100 -> 50/100 -> 75/100 -> Level 2, 0/120`.
4. Confirm every reward creates the animated local EXP bar and the fourth produces the separate LEVEL UP state.
5. Confirm level-up applies the species' HP/SP/STR/INT/DEF/SPD growth and Attribute Point grant exactly once.
6. Damage/spend SP before the final victory and verify progression does not full-heal or reset combat.
7. Set a second species to a visibly different pair such as `Base=180`, `Multiplier=1.10`; confirm its Party/Bank required EXP differs from the first species at the same Level.
8. Give one enemy enough EXP to cross multiple thresholds and verify the animated segments and final authoritative result agree.
9. Repeat with a remote client owning the partner; the host should see the partner's replicated new Level/stats but not that client's private EXP toast or Party/Bank contents.
10. Reconnect and verify Level, current-level EXP, stats and Attribute Points persist.
11. Test `Max Level Override`, then repeat at the cap.

Do not promote the package to runtime-accepted until the UE5.8.1 compile and multiplayer tests pass.
