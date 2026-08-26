# Player Footsteps Setup — v0.10.4-alpha

## Goal

The framework provides automatic, replicated **player-avatar-only** footstep audio without requiring animation notifies, per-skeleton foot sockets or Blueprint timing logic. Digimon do not use this system.

## 1. Create the footstep Sound Cue

Create a normal Unreal **Sound Cue** for player footsteps. A good production cue typically contains several compatible footstep samples behind a Random node, subtle pitch/volume variation, and an attenuation asset/settings appropriate for nearby MMO players.

The framework accepts any `USoundBase`, but a Sound Cue is recommended because sample randomization and attenuation remain content-authored while the plugin owns movement cadence/network delivery.

## 2. Assign it globally

Open:

**Project Settings → Game → Digimon MMO Framework → Player Avatar → Footsteps**

Set:

- **Enable Player Footsteps** — global master switch.
- **Player Footstep Sound (Sound Cue Recommended)** — assign the Sound Cue created above.

No player Blueprint, AnimBP or Anim Notify setup is required. Every framework-derived `DMFPlayerAvatarCharacter` automatically uses the configured sound.

## 3. Cadence controls

The system accumulates actual grounded horizontal distance travelled from CharacterMovement. This makes timing independent from frame rate and from the framework's optional legacy WASD bindings.

Defaults:

- **Minimum Speed:** `35`
- **Walk Stride Distance:** `150`
- **Sprint Stride Distance:** `175`
- **Crouch Stride Distance:** `120`

Smaller stride values produce more frequent steps; larger values produce less frequent steps. Tune these against the visual gait of the project's player animation set.

The framework starts a new movement sequence at a partial stride so movement does not begin with a long silent delay, while also avoiding an artificial step on the exact first movement frame. Airborne/idle movement resets the cadence. A frame hitch can emit at most one step in that frame, preventing stale audio bursts.

## 4. Presentation controls

- **Volume Multiplier** defaults to `1.0`.
- **Pitch Multiplier** defaults to `1.0`.

These are global post-Cue multipliers. Prefer authoring per-sample variation and spatial attenuation inside the Sound Cue itself.

The audio origin is calculated from the bottom of the player's collision capsule. This is intentionally skeleton-independent so skins with different rigs/socket names do not require extra setup.

## 5. Multiplayer contract

Footsteps are cosmetic but properly networked:

1. The server independently evaluates grounded movement cadence for every authoritative player avatar.
2. When a stride is reached, it calls an **Unreliable NetMulticast** footstep presentation event.
3. Other relevant clients play the configured spatial sound at that replicated player's capsule base.
4. A remote owning client predicts only its own local step immediately for responsiveness.
5. That owning client suppresses the returned server multicast echo, so it never hears the same step twice.
6. Listen hosts hear their authoritative event directly. Dedicated servers originate observer events but render no audio locally.

Unreliable RPC delivery is intentional for footsteps: a lost transient step is preferable to a reliable queue playing old footstep sounds late. Movement state itself remains Unreal CharacterMovement replication and is never derived from audio events.

## 6. Player-only boundary

The implementation lives only in `ADMFPlayerAvatarCharacter`. It does not modify `ADMFDigimonCharacter`, owned partners or Wild Digimon. Digimon voice/combat/Care audio remains on its existing presentation paths.

## 7. Blueprint/custom movement compatibility

The automatic cadence reads actual `GetVelocity()` plus `CharacterMovement::IsMovingOnGround()`. Therefore it still works when:

- the native framework WASD bindings are disabled;
- the project uses Enhanced Input;
- a Blueprint child changes movement input routing;
- a different player skin/AnimBP is applied.

`Play Player Footstep Local` is exposed as a presentation helper for advanced project-specific hooks. Calling it directly does not send a network event or mutate gameplay state; normal gameplay should use the automatic system.

## 8. Packaged-build asset note

Because the global audio field is a soft project setting, make sure the chosen Sound Cue is included in the packaged build. If it is not already referenced by a cooked map/Data Asset, add its content folder under **Project Settings → Packaging → Additional Asset Directories to Cook** (or include it through the project's normal Asset Manager/cook rules). This prevents a development-only asset from disappearing in a packaged client.

## 9. Acceptance test

Run the complete `F0` host + remote-client checklist in `TEST_PLAN.md`. At minimum, verify both players hear each other spatially, the remote owner has no doubled audio, jumping/idle movement produces no steps, sprint/crouch cadence differs correctly, and Digimon never inherit the player footstep Cue.
