# Underwater Post-Process, Color & Distance Fog Presentation — v0.17.1-alpha

This layer sits on top of the accepted v0.17.0 replicated swimming system. Gameplay state remains server authoritative; underwater rendering is a private local-camera concern.

## 1. Where to configure it

Open a Blueprint derived from **`DMFSwimmableWater`** and expand:

**Digimon MMO -> Swimming Water -> Underwater Post Process**

The `Underwater Post Process Settings` profile is authored per water body, so an ocean, digital lake and sewer pool can use different looks while sharing the same movement/networking architecture.

Default profile:

- **Enabled** — true
- **Color Tint** — soft blue/cyan multiplicative tint
- **Color Tint Strength** — `0.60`
- **Saturation** — `0.78`
- **Contrast** — `1.05`
- **Gamma** — `0.96`
- **Exposure Compensation** — `-0.35`
- **Vignette Intensity** — `0.24`
- **Chromatic Aberration Intensity** — `0.35`
- **Enable Distance Fog** — true
- **Distance Fog Color** — deep blue/cyan
- **Distance Fog Density** — `0.075`
- **Distance Fog Height Falloff** — `0.001`
- **Distance Fog Start Distance** — `50 cm`
- **Distance Fog Max Opacity** — `0.94`
- **Distance Fog Blend Exponent** — `0.65`
- **Camera Enter Depth** — `8 cm`
- **Camera Exit Height** — `4 cm`
- **Shallow Water Blend Weight** — `0.72`
- **Full Strength Depth** — `180 cm`
- **Blend In Speed** — `5`
- **Blend Out Speed** — `7`
- **Priority** — `1000`
- **Post Process Material** — optional
- **Post Process Material Weight** — `1.0`

These defaults provide a clearly underwater MMO-style presentation without requiring a custom material. Color grading supplies the tone; native distance fog supplies the missing visibility falloff so distant terrain no longer remains perfectly sharp.

## 2. Camera-correct waterline behavior

The framework does not turn the effect on simply because `Is Swimming Underwater` is true. It evaluates the **local FollowCamera world location** against the current `DMFSwimmableWater` bounds/surface.

This matters with a third-person spring arm: the avatar can be below the surface while the camera is still physically above it. In that situation the view stays normal. The underwater profile engages only when the camera crosses below the water surface.

`Camera Enter Depth` and `Camera Exit Height` provide waterline hysteresis. With defaults, the camera must be 8 cm below the surface to enter the visual state, then rise 4 cm above the surface before leaving it. Small spring-arm corrections/waves therefore do not rapidly flash the post process on/off.

## 3. Depth response

Once the camera is underwater, the post-process target weight begins at `Shallow Water Blend Weight` and ramps toward `1.0` by `Full Strength Depth`.

For example with defaults:

- just below the waterline -> approximately 72% profile strength
- progressively deeper -> smoothly stronger
- 180 cm or deeper -> full profile strength

The final blend itself is then smoothed using the independent Blend In / Blend Out speeds. This gives both a polished waterline transition and a stronger sense of depth without replicating camera data.

## 4. Native underwater distance fog

Color grading affects every visible pixel but cannot make distant geometry disappear into the water. v0.17.1 therefore includes a local `UExponentialHeightFogComponent` on the player presentation path. It is disabled by default on every avatar copy and is enabled only for the locally controlled camera while submerged.

The important authoring controls are:

- **Distance Fog Density** — primary visibility-distance control. Raise this for murkier/deeper water; lower it for clear tropical water.
- **Distance Fog Start Distance** — keeps a readable clear pocket around the camera/character before haze begins.
- **Distance Fog Max Opacity** — caps how completely distant scenery can disappear.
- **Distance Fog Color** — the color distant terrain converges toward.
- **Distance Fog Height Falloff** — intentionally tiny by default so the effect behaves mostly like underwater distance haze instead of atmospheric world-height fog.
- **Distance Fog Blend Exponent** — controls how quickly fog reaches useful density during the existing smooth waterline/depth blend. Values below 1 make the water look convincingly hazy soon after the camera submerges.

Recommended tuning ranges:

- clear lake/ocean: density `0.035-0.055`, max opacity `0.80-0.90`
- default MMO water: density `0.065-0.10`, max opacity `0.90-0.96`
- murky swamp/digital corruption: density `0.12-0.25`, max opacity `0.96-1.0`

The fog is presentation only. It does not alter AI perception, targeting, combat ranges or server gameplay visibility.

## 5. Optional custom Post Process material

The built-in color-grading path needs no material. For higher-end effects, assign any material authored with **Material Domain = Post Process** to `Post Process Material`.

Good custom additions include:

- SceneDepth-driven distance haze / underwater fog
- animated caustic distortion
- subtle UV refraction
- digital-world scanline/noise treatment
- screen-edge particulate/bubble overlays

The framework places the material into the same local profile and multiplies it by `Post Process Material Weight` and the current waterline/depth blend. Do not implement gameplay or replicated state inside a Post Process material.

## 6. Blueprint runtime API

On `DMFSwimmableWater`:

- `Get Underwater Post Process Settings`
- `Set Underwater Post Process Settings` — authority-only at runtime
- `Set Underwater Post Process Enabled` — authority-only at runtime
- `Set Underwater Post Process Material` — authority-only at runtime
- `Refresh Underwater Post Process Presentation`

On `DMFPlayerAvatarCharacter`:

- `Is Local Camera Underwater`
- `Get Underwater Post Process Blend Weight`
- `Refresh Underwater Post Process Presentation`
- `On Local Camera Underwater Changed`
- `BP On Local Camera Underwater Changed`

The camera-waterline values/events are **local presentation only**. Use replicated `Is Swimming In Water` / `Is Swimming Underwater` for authoritative gameplay logic.

## 7. Multiplayer / performance contract

- The water profile is replicated as sparse actor configuration so all clients receive the same authored water look when runtime authority changes it.
- Camera location, local waterline boolean and blend weight are never sent to the server and never replicated to other players.
- Each avatar owns an `UnderwaterPostProcessComponent` plus `UnderwaterDistanceFogComponent`, but framework code enables them only on the locally controlled player. Remote proxies perform no per-frame underwater render update.
- Dedicated servers do not render the component.
- `DMFSwimmableWater` remains zero-tick. Fog density updates are skipped when the applied density has not materially changed, avoiding redundant render-state churn once a transition settles.
- No new RPC is added.
- No SaveGame schema is changed.

## 8. Recommended first test

1. Keep the default profile and enter the accepted v0.17.0 test water.
2. Surface-swim with the third-person camera above the plane; confirm the scene remains normal.
3. Aim/dive until the **camera** crosses underwater; confirm a smooth blue/cyan grading transition rather than a hard pop.
4. Confirm distant shoreline/terrain loses contrast and fades into the configured Distance Fog Color instead of remaining razor-sharp.
5. Dive deeper and confirm both grading and fog strengthen toward full weight.
6. Rise to the surface; confirm small waterline jitter does not flicker the effect and the view blends cleanly back to normal.
7. Repeat on a remote owning client; confirm its own camera receives the same water profile while the host's viewport is unaffected by that remote player's camera.
8. Assign a custom Post Process material and verify it blends in/out with the same waterline/depth weight.
9. Disable the water profile and confirm swimming/movement remains completely functional with no underwater grading.

## Save/load restoration note (v0.17.2)

Underwater presentation still remains local-camera-only, but it now has a guaranteed authoritative water-state source after position restore. When a saved player transform is loaded inside water, the server geometrically reconstructs `ActiveSwimmableWater` and Surface/Underwater state immediately instead of waiting for `BeginOverlap`. The owner then receives the normal replicated correction and the local camera independently rebuilds post process + distance fog from its actual position relative to the waterline. No camera transform, fog density or PP blend value is saved or replicated.

