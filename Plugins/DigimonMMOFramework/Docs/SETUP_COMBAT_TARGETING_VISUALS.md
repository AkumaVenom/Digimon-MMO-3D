# Polished Owner-Only Combat Targeting Visuals — Setup

**Introduced:** v0.14.2-alpha  
**Runtime visibility fix:** v0.14.3-alpha

The framework now supplies a native local-player targeting presentation layer for the player's active partner and currently selected hostile Digimon. These effects are deliberately **not replicated cosmetic actors/state**: each owning client reconstructs its own rings/arrow from the already owner-only `ActivePartnerActor` and `CommandTarget` references.

## Presentation contract

- **Active partner:** optional blue rotating `PaperSprite` ring beneath the locally owning player's summoned active partner.
- **Current enemy target:** optional hostile/selection `PaperSprite` ring beneath the local player's selected command target.
- **Enemy arrow:** Niagara-preferred, Cascade-fallback effect above the local command target.
- **Privacy:** Player A cannot see Player B's targeting rings/arrow. Each player sees only their own active-partner/target presentation.
- **Authority:** markers never choose targets, apply damage, or bypass server validation. They visualize state already accepted by the existing server-authoritative combat/command-target path.
- **Cleanup:** clearing/defeating/replacing the command target immediately hides/deactivates the target ring and arrow. Recalling/replacing the active partner hides/repositions the partner ring.

## Required project assets

The screenshot assets can be used directly:

- Blue active-partner ring: `CircleRing_T_Sprite`
- Hostile target ring: `CircleRing_T1_Sprite` (red ring in the supplied example)
- Hover arrow Niagara: `NS_Icon2D_Arrow`
- Optional legacy Cascade arrow equivalent

No new Blueprint actor is required for the default path.

## Project Settings

Open:

**Project Settings → Game → Digimon MMO Framework → Combat → Targeting Visuals**

### Global

- **Enable Combat Targeting Visuals** — master local presentation switch.

### Active Partner

- **Show Active Partner Targeting Ring** — enabled by default.
- **Active Partner Targeting Ring Sprite** — assign the blue PaperSprite.
- **Active Partner Targeting Ring Scale** — global art scale before automatic Digimon-size adaptation.
- **Active Partner Targeting Ring Ground Offset** — default `3` units above capsule bottom to avoid z-fighting.
- **Active Partner Targeting Ring Rotation Degrees Per Second** — default `+28`.

### Enemy Target

- **Show Enemy Targeting Ring** — enabled by default.
- **Enemy Targeting Ring Sprite** — assign the hostile/red PaperSprite.
- **Enemy Targeting Ring Scale** — global art scale.
- **Enemy Targeting Ring Ground Offset** — default `4`.
- **Enemy Targeting Ring Rotation Degrees Per Second** — default `-42`, deliberately opposite/faster than the partner ring.

### Ring Geometry

- **Targeting Ring Sprite Relative Rotation** — default `Roll 90`, which lays normal Paper2D sprite geometry flat on the world floor while a separate parent pivot performs the clean world-Z spin.
- **Scale Targeting Rings To Digimon Capsule** — enabled by default.
- **Targeting Ring Reference Capsule Radius** — default `42`.
- **Targeting Ring Minimum Auto Scale** — default `0.65`.
- **Targeting Ring Maximum Auto Scale** — default `3.0`.
- **Targeting Visual Translucent Sort Priority** — default `10`; enemy ring uses `+1` internally.

The automatic capsule scaling is useful for a roster containing tiny Fresh Digimon and very large Mega/Ultra forms. Disable it if the project authors a separate exact-size sprite per species instead.

### Enemy Arrow

- **Show Enemy Target Arrow** — enabled by default.
- **Prefer Niagara Enemy Target Arrow** — enabled by default.
- **Enemy Target Arrow Niagara System** — assign `NS_Icon2D_Arrow` or equivalent.
- **Enemy Target Arrow Cascade System** — optional fallback.
- **Enemy Target Arrow Height Offset** — default `60` units above capsule top.
- **Enemy Target Arrow Scale** — art scale.
- **Enemy Target Arrow Rotation** — orientation correction if the authored arrow axis is different.
- **Enemy Target Arrow Bob Amplitude** — default `10`.
- **Enemy Target Arrow Bob Frequency Hz** — default `1.5`.

When both particle systems are assigned, Niagara is used by default. If Niagara is absent, Cascade is activated automatically. Set the bob amplitude to `0` if the Niagara/Cascade system already implements its own vertical hover motion.


## v0.14.3 runtime visibility hardening

The presentation actor is already spawned **only in the owning local player world** and is never replicated. v0.14.3 therefore intentionally does **not** use component-level `Only Owner See` flags on its sprites or particle components. Those flags are unnecessary for privacy here and can be evaluated against a camera/view-owner chain that does not match the local PlayerController, which can hide every marker from the intended player.

Privacy is provided structurally instead: Player A owns a non-replicated presentation actor that exists only in Player A's local world; Player B has a separate local actor reading Player B's owner-only target state. No targeting-marker actor/component/state is sent over the network.

The presentation also self-refreshes missing soft assets during PIE. You may assign or change the ring/arrow assets in Project Settings while PIE is running and the actor will pick them up without needing to respawn the level.

## Runtime behavior

The local targeting-presentation actor is spawned automatically for the locally controlled `DMFMMOPlayerController`. It does not exist on dedicated servers and `bReplicates` is false.

Every local frame it reads:

1. the owner-only active-partner actor;
2. the owner-only authoritative command target;
3. the target/partner capsule dimensions;
4. the global Project Settings tuning.

The PaperSprite rings are moved to the capsule bottom and independently rotated around world Z. The target arrow is placed above the capsule top and receives the optional native hover offset.

A defeated command target is treated as no target for presentation even before the normal server-side victory cleanup finishes propagating.

## Blueprint extension

`ADMFMMOPlayerController` exposes:

- `Refresh Targeting Visuals`
- `Get Targeting Presentation Actor`

The local `DMFTargetingPresentationActor` exposes:

- `Refresh Presentation Assets`
- `Get Presented Active Partner`
- `Get Presented Command Target`

These hooks are presentation-only. Continue using the existing combat/interaction APIs to actually select or attack targets.

## Multiplayer acceptance test

Run listen host + at least two remote clients:

1. Give each player a different active partner.
2. Confirm each window shows a blue ring only under **its own** active partner.
3. Have Player A select Wild Digimon A and Player B select Wild Digimon B.
4. Player A must see only its own red target ring + arrow on A.
5. Player B must see only its own red target ring + arrow on B.
6. The host must not see either remote client's local markers unless the host independently selects the same target.
7. Confirm the two rings rotate continuously at visibly different speeds/directions.
8. Move small and large Digimon forms through the test and confirm ring sizing follows capsule radius without becoming enormous or microscopic.
9. Kill/clear the target and verify the red ring + arrow disappear immediately.
10. Recall/switch active partners and verify the blue ring disappears/reappears under the newly active summoned partner.
11. Repeat projectile combat and confirm v0.14.1 projectile travel/homing/impact/cleanup remains unchanged.

## Packaging note

The targeting assets are soft references stored in Project Settings. Ensure assigned sprite/VFX assets are cooked in packaged builds. Assets living under an always-cooked project directory or referenced by another cooked asset are sufficient; otherwise add their directory to the project's cook rules.

## v0.14.6 CustomDepth contract — enemy overhead marker

The framework-owned enemy target arrow component is always forced to **Render CustomDepth Pass = true** for both Niagara and Cascade presentation. The flag is applied when the local presentation actor is constructed, whenever targeting assets are refreshed from Project Settings, and again immediately before the active marker is started. This is intentional framework behavior so post-process outlines/masks can reliably include the overhead enemy marker even if the assigned effect asset was authored without a matching component default. The marker remains local-only and does not replicate.

