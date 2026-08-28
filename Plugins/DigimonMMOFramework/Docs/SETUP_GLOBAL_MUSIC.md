# Global Music Director Setup — v0.11.0-alpha

**Persistent battle-lifecycle fix:** v0.14.4-alpha

## Goal

The framework provides a ready-to-use **Frontend → Open World → Battle → Open World** soundtrack flow without requiring Blueprint state machines, Level Blueprint audio switching or replicated music RPCs.

Music is local presentation for each player. The authoritative gameplay systems already replicate the active partner's combat state; the local music subsystem reads that replicated truth and chooses the appropriate track.

## 1. Configure the three global music assets

Open:

**Project Settings → Game → Digimon MMO Framework → Audio → Music → Tracks**

Assign:

- **Frontend / Main Menu Music** — plays while the configured `FrontendMap` is active.
- **Open World Music** — plays during normal exploration in the configured `OpenWorldMap`.
- **Battle Music** — plays when the local player's active partner enters real combat.

The fields accept `USoundBase` assets. A **Sound Cue** is recommended when you want authored randomization, layers or other Cue logic. A normal Sound Wave is also supported.

If **Battle Music** is empty, entering combat deliberately falls back to/keeps **Open World Music** rather than forcing silence.

## 2. Map requirements

The automatic state director uses the framework's existing map settings:

- `FrontendMap`
- `OpenWorldMap`

Keep those assigned to the maps already used by the frontend/hosting flow. PIE world prefixes are handled automatically, so the same configuration works in editor and packaged builds.

Compatible framework GameMode/PlayerController fallbacks are also present for projects that subclass the normal DMF gameplay classes.

## 3. What counts as Battle

Battle music is intentionally driven by the local active partner's **server-authoritative replicated `UDMFDigimonCombatComponent` encounter state**.

A real combat action (`Chasing`, `Attacking` or `Recovering`) against a valid hostile target starts the component's durable `bBattleEncounterActive` latch. Simply selecting a Digimon as the command target does **not** start the latch, so inspecting/targeting an enemy without attacking still leaves Open World music playing.

The important v0.14.4 behavior is that **returning to `Idle` after an attack does not end the battle encounter**. Manual combat is allowed to sit Idle for as long as the player wants between ability presses while the same hostile encounter remains active, and Battle music stays on for that entire period. The short action-state transitions are no longer used as the lifetime of the soundtrack.

The authoritative encounter is cleared by actual combat teardown, including:

- victory against the current opponent;
- defeat of the local active partner;
- authoritative target clear/disengage (including leash/automation teardown);
- healer/full combat reset and other framework paths that intentionally clear combat intent.

Only after that durable encounter ends does **Battle Music Release Delay Seconds** begin counting down, after which the subsystem crossfades back to Open World music. The release delay remains useful for a clean victory/defeat transition, but it can no longer expire merely because the player waited between attacks.

Blueprint projects can query `Is Battle Encounter Active` on the Digimon Combat Component when they need the same durable battle-lifecycle truth for UI or presentation.

## 4. Crossfade and volume controls

Open:

**Project Settings → Game → Digimon MMO Framework → Audio → Music**

Useful controls:

- **Enable Framework Music** — master enable/disable switch.
- **Music Master Volume** — global multiplier for all framework music.
- **Frontend Music Volume** — per-state multiplier.
- **Open World Music Volume** — per-state multiplier.
- **Battle Music Volume** — per-state multiplier.
- **Music Crossfade Seconds** — default `1.25`; set `0` for an immediate cut.
- **Battle Music Release Delay Seconds** — default `1.5`.
- **Automatically Loop Music** — default enabled.
- **Music State Evaluation Interval** — advanced local presentation polling rate, default `0.20` seconds.

The subsystem uses persistent 2D AudioComponents. This allows Frontend music to remain alive through the map-travel boundary and crossfade into Open World music when gameplay initializes instead of cutting abruptly during travel.

## 5. Looping behavior

There are two valid authoring approaches:

1. Author the Sound Cue/Wave to loop normally. Its AudioComponent remains playing and the framework leaves it alone.
2. Use a non-looping track with **Automatically Loop Music** enabled. When the asset naturally finishes, the subsystem restarts it from the beginning.

This makes simple music assets functional out of the box while still supporting richer internally-looped Cue authoring.

## 6. Multiplayer / MMO contract

Music is **never replicated**.

Each local client independently chooses music from gameplay state that already came from the server:

`Server-authoritative battle encounter state -> normal replication -> local DMFMusicSubsystem -> local AudioComponent`

Therefore:

- Host can be in Battle music while Client remains in Open World music.
- Client can enter a separate battle without changing Host music.
- Two players fighting at the same time each hear their own local Battle track.
- No track reference, playback position, volume, crossfade or music-state RPC consumes MMO network bandwidth.
- Dedicated servers create no music playback.

This is the intended authority boundary: combat remains server-owned; soundtrack choice remains client presentation.

## 7. Blueprint access

For advanced projects, get **DMF Music Subsystem** from the normal **Get Game Instance Subsystem** Blueprint node.

Exposed API:

- **Get Current Music State** — returns `None`, `Frontend`, `OpenWorld` or `Battle`.
- **Refresh Music State** — immediately re-evaluates the automatic state.
- **Set Music Suppressed** — temporarily fades framework music out/in for cinematics or project-owned presentation without altering Project Settings.
- **Is Music Suppressed**.
- **On Music State Changed** — local presentation delegate.

Normal projects do not need to call any of these functions; they are extension hooks.

## 8. Packaged-build asset note

The three music fields are soft project settings. Ensure the assigned music assets are cooked in packaged builds. If they are not already referenced by a cooked map/Data Asset, add their content folder under:

**Project Settings → Packaging → Additional Asset Directories to Cook**

or include them through the project's normal Asset Manager/cook rules.

## 9. Acceptance test

Run `TEST_PLAN.md` section **M0** on a listen host and remote client. At minimum verify:

- Frontend music plays before connection.
- Open World music takes over after entering gameplay.
- Target selection alone does not start Battle music.
- A real chase/attack switches only the fighting local player to Battle music.
- Stop pressing abilities after one attack while the enemy remains alive. Battle music must remain active indefinitely through the partner's `Idle` gap.
- Resume attacking and verify the same Battle track/state continues without an Open World round-trip.
- Victory or local-partner defeat ends the encounter and returns to Open World only after the release delay.
- returning to the frontend restores Frontend music.
- disabling the master switch produces no framework music.
