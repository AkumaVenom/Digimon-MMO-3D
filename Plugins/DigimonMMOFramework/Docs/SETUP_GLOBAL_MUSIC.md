# Global Music Director Setup — v0.11.0-alpha

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

Battle music is intentionally driven by the local active partner's **replicated authoritative `UDMFDigimonCombatComponent` state**.

Battle begins when that component is in one of these states:

- `Chasing`
- `Attacking`
- `Recovering`

Simply selecting a Digimon as the command target does **not** trigger Battle music. This prevents exploration music from changing just because the player inspected/targeted something before issuing an attack.

When combat returns to Idle/ends, the framework waits for the configured **Battle Music Release Delay Seconds** and then crossfades back to Open World music. The short hold prevents soundtrack chatter during tiny state gaps and lets the final attack/recovery beat finish naturally.

A defeated local partner is not considered an active Battle state; the release delay returns the player to Open World music.

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

`Server-authoritative partner CombatState -> normal replication -> local DMFMusicSubsystem -> local AudioComponent`

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
- Battle completion returns to Open World music after the release delay.
- returning to the frontend restores Frontend music.
- disabling the master switch produces no framework music.
