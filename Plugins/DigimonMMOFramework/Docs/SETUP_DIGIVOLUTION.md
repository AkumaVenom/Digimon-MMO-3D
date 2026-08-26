# Polished Replicated Digivolution — v0.13.1-alpha

v0.13.0 adds a complete persistent, server-authoritative Digivolution layer to the existing owned-Digimon model. Digivolution paths are authored on each `DMFDigimonSpeciesData` asset, evaluated against the persistent individual, and committed only by the owning server `UDMFPlayerDigimonComponent`.

> **v0.13.1 UI hardening:** the Owned Digimon Party/Bank browser now uses fixed centered three-column cards with square aspect-safe portrait viewports. One- and two-Digimon rows no longer stretch portraits across the panel. This does not change any Digivolution gameplay or authority behavior.

The system is designed for the normal Digimon progression folders/stages used by the project — **Fresh, In-Training, Rookie, Champion, Ultimate, Mega, Ultra and Armor** — but it does not hard-code a linear chain. A species can expose zero, one or many outgoing paths, including deliberate reverse/de-Digivolution paths when the project authors them.

## 1. Required project setup

1. Keep every Digimon form as its own `DMFDigimonSpeciesData` Primary Data Asset.
2. Ensure the project Asset Manager scans the directory containing **all** species forms, not only starter/Rookie data. The supplied `ConfigTemplates/DMF_Project_DefaultGame.ini.snippet` scans `/Game/DigimonData` recursively as `DMFDigimonSpecies` and marks it `AlwaysCook`.
3. Every form that can appear in the world must assign a valid `World Actor Class` derived from `DMFDigimonCharacter`.
4. Assign a Portrait to each form for the native Digivolution UI.
5. For an active-partner transformation, the target form's World Actor Class should already be configured exactly as a normal summonable partner class (mesh, AnimBP, collision, nameplate, combat presentation, CustomDepth policy, etc.).

## 2. Author a Digivolution path

Open the **source/current form** species asset, for example `DA_Species_Agumon`, then expand:

**Digivolution → Digivolutions**

Add an array element. That element is one authoritative one-way path.

Set **Target Species** to the destination form, for example Greymon.

### Progression requirements

Each path can independently require:

- `Required Level`
- `Minimum ABI`
- `Minimum CAM`
- optional stat gates through `Require Stats`:
  - Strength
  - Intelligence
  - Defense
  - Speed
- optional Care gates through `Require Care`:
  - Minimum Happiness
  - Minimum Discipline
  - Maximum Care Mistakes (`-1` disables the ceiling)
- optional `Money Cost`

The native UI presents the configured requirement summary and a live **READY / LOCKED** result. This client-side evaluation is display-only; the server re-resolves the current instance and revalidates every requirement when the button is pressed and again before a summoned transformation commits.

## 3. Path rules

Each path also exposes:

- **Allow From Bank** — whether a Digimon stored in Bank/Boxes can use this path. The project-wide `Allow Bank Digivolution` setting must also be enabled.
- **Preserve Stat Investments** — carries positive stat investment above the source species BaseStats into the target species BaseStats.
- **Replace Equipped Abilities** — replaces the individual's current ability list with the target form defaults. Disable this to keep previous abilities and add target defaults.
- **Fully Restore Vitals** — restores to the new Max HP/SP. Disable this to preserve HP/SP percentage across the form change.

Level, Experience, ABI, CAM, nickname, instance GUID, Care state and unspent attribute points remain attached to the same persistent individual.

## 4. Branching and reverse paths

Digivolution is data-driven rather than stage-hard-coded.

Example:

`Agumon -> Greymon`

`Agumon -> Tyrannomon`

`Greymon -> MetalGreymon`

Each arrow is an element on the source species' `Digivolutions` array.

If the project wants de-Digivolution, author the reverse relationship explicitly on the evolved form, e.g. `Greymon -> Agumon`. Because it is an ordinary path, it can have its own requirements/cost/preservation policy.

Avoid accidental self-links. Cycles are supported only when deliberately authored.

## 5. Global Digivolution settings

Open:

**Project Settings → Game → Digimon MMO Framework → Digivolution**

Available controls include:

- `Enable Digivolution System`
- `Allow Bank Digivolution`
- `Block Digivolution During Combat`
- `Hide UI For Summoned Digivolution`
- `Digivolution Presentation Duration Seconds`
- `Default Digivolution Niagara System`
- `Default Digivolution Cascade Particle`
- `Prefer Niagara Digivolution VFX`
- `Default Digivolution Sound`
- Digivolution sound volume/pitch multipliers

A path may override the global Niagara, Cascade, Sound and presentation duration. Blank path overrides use the global values.

## 6. Native Digivolution UI

The shared Digimon Menu now presents:

**PARTY → BANK / BOXES → SCAN & MATERIALIZE → DIGIVOLUTION → CARE**

The DIGIVOLUTION page contains:

- an **Owned Digimon** browser combining Party + Bank;
- current-form portrait, stage, attribute, level, storage location, HP, ABI and CAM;
- a scrollable list of all configured outgoing paths;
- READY/LOCKED status and requirement summary for every path;
- destination portrait, stage, attribute and World Actor Class readiness;
- a protected requirement/status panel;
- **DIGIVOLVE TO SELECTED FORM** action.

Party and Bank remain private owner-only account state; the UI does not create a second roster authority.

## 7. Active summoned partner transformation

When the selected Digimon is the currently summoned active partner:

1. Client presses **DIGIVOLVE TO SELECTED FORM**.
2. Owning component sends only `InstanceId + TargetSpeciesId` in the reliable server request.
3. Server validates ownership, current source form, path, progression requirements, money, Care lock and active-combat rule.
4. Server locks the Digivolution sequence and clears combat targeting/automation.
5. Owner receives a reliable presentation-start event. With `Hide UI For Summoned Digivolution=true`, the Digimon Menu, combat quickbar, Party quickbar and chat are hidden so the transformation is visible in-world.
6. Existing Digimon actor multicasts the configured transformation VFX/audio cue to relevant clients.
7. After the authoritative presentation duration, the server **revalidates the path**.
8. Server mutates the persistent individual, deducts money once, persists immediately, and replaces the old world actor with the target species' `WorldActorClass` using the same active instance GUID.
9. Normal actor replication shows the new form to other players.
10. Owner HUD returns and, when the sequence started from the Digimon Menu, reopens directly on **DIGIVOLUTION**.

The client never supplies a new stat block, cost, World Actor Class, final species object or completion time.

## 8. Bank / Box Digivolution

When the selected Digimon is stored in Bank and both the global and path-level Bank rules allow it, the server can evolve that persistent Bank entry directly without temporarily moving it into Party or spawning a world actor.

This is intentionally quieter than an active-partner transformation:

- no unnecessary world actor is spawned;
- Party ordering remains unchanged;
- Bank Fast Array item is dirtied owner-only;
- persistent individual identity/history is preserved;
- account persistence is written immediately;
- native Digivolution/Bank UI refreshes from the authoritative result.

## 9. Persistence / schema v5

v0.13.0 advances the account SaveGame schema to **v5**.

Each `FDMFDigimonInstance` now persists:

- `OriginSpeciesId`
- `DigivolutionHistory`

Older accounts are normalized safely on authoritative load:

- if Origin is absent, the individual's current species becomes the origin seed;
- history starts with origin/current form;
- existing GUID, Party/Bank placement, active partner, Care, vitals, stats, abilities and progression remain intact.

Every successful evolution appends the source and destination species IDs uniquely to the history.

## 10. Niagara / Cascade / sound presentation

For each path, optional presentation overrides live under **Digivolution → Presentation**.

Selection rules:

- Niagara-preferred ON: path Niagara → global Niagara → path/global Cascade fallback.
- Niagara-preferred OFF: path Cascade → global Cascade → path/global Niagara fallback.
- Sound: path Sound → global Default Digivolution Sound.

`BP On Digivolution Cue` on `DMFDigimonCharacter` is a cosmetic Blueprint extension point for species-specific material flashes, light animation or other visual treatment. Do not place the actual species/stat mutation in this event.

## 11. Server-authority / MMO contract

Durable private state:

- Party and Bank remain owner-only Fast Arrays.
- Digivolution provenance/history lives inside the persistent instance.
- Money remains owner-only authoritative account state.

Public world state:

- the currently summoned Digimon actor is the public representation;
- a reliable multicast carries only high-value transformation presentation;
- the authoritative replacement actor replicates normally after commit.

Conflicting commands are rejected while a world Digivolution sequence is active, including partner switch/recall, Party/Bank mutation, Care, healer use, targeting and ability execution.

## 12. Recommended first editor test

For a fast Agumon → Greymon test:

1. Create/configure Greymon species data and World Actor Class.
2. Open Agumon's species data.
3. Add one `Digivolutions` element targeting Greymon.
4. Temporarily set Required Level to `1`, ABI/CAM/stat/Care gates to `0/off`, and Money Cost to `0`.
5. Assign a global Digivolution Niagara effect and Sound in Project Settings.
6. PIE as host, open **I → DIGIVOLUTION**, select Agumon and Greymon, then Digivolve.
7. Verify UI hides, both peers see/hear the cue, the world actor is replaced by Greymon, and the menu returns with the new current form.
8. Recall/re-summon and reconnect the account; Greymon must remain the persistent form.

After the base flow passes, restore the intended production requirements.

## 13. Host + remote-client acceptance matrix

Run a listen host plus second client and verify:

1. Each account sees only its own Party/Bank Digivolution candidates.
2. Host evolves a summoned partner; both windows see the old actor's cue and then the replicated target-form actor.
3. Client evolves a summoned partner; client UI hides/returns correctly and host sees the target form.
4. A LOCKED path cannot be forced by clicking or RPC timing.
5. Money cost is deducted once only on successful commit.
6. Active combat blocks the active partner when the global setting is enabled.
7. Care feeding and healer interaction cannot race an active world transformation.
8. Bank Digivolution changes only the owning account and does not spawn a world actor.
9. Party/Bank moves are rejected during an active transformation.
10. Reconnect both accounts and confirm form/history/Party/Bank placement persist.
11. Test Niagara primary, then remove it and verify Cascade fallback.
12. Run existing Party/Bank, Scan/Materialization, Care, healer, combat, chat, nameplate, camera, music and footstep regressions.
