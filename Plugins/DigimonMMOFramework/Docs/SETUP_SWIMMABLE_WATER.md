# Swimmable Water Setup

v0.17.0 adds a replicated, Blueprint-derivable water body plus native player swimming support. v0.17.3 hardens remote fallback-pose replication against CharacterMovement network smoothing, while v0.17.2 hardens persistence/teleport re-entry so a saved transform restored directly inside water reconstructs swimming before gravity can take over. The water actor is deliberately simple to author: one visible plane, one automatically matched Pawn overlap volume, and exposed movement/presentation tuning. The authoritative server owns water occupancy while Unreal `ACharacter` movement replication carries actual player movement.

## 1. Create the water Blueprint

1. In Content Browser choose **Blueprint Class**.
2. Search for **DMFSwimmableWater**.
3. Create a child such as `BP_DMFWater_Lake`.
4. Assign **Water Material** to the project's water material.
5. Leave **Water Surface Mesh** on the native Engine Plane or replace it with a flat project mesh.
6. Keep **Auto Size Surface Mesh To Bounds** enabled for the normal one-plane workflow.

`DMFSwimmableWater` is placeable directly, but a Blueprint child is recommended so the project's preferred material, dimensions and swim tuning become reusable defaults.

## 2. Size the surface and collision together

The actor origin/`Water Surface Z Offset` defines the visible surface elevation.

- **Water Surface Size X/Y** controls the visible plane and overlap width/length.
- **Water Depth** extends swimming collision downward from the surface.
- **Surface Overlap Height** extends the overlap slightly above the plane so a surface swimmer's capsule can breach the water without constantly leaving/re-entering the volume.
- **Water Surface Z Offset** moves both the visible surface reference and swimming volume vertically relative to the actor.

The native plane has collision disabled. `SwimmingBounds` is a query-only Pawn overlap and automatically follows the same surface size.

Use **Refresh Water Geometry** in the Details panel after unusual Blueprint/editor changes. Normal property edits call the same rebuild path automatically through construction.

## 3. Default native controls

With `DMFPlayerAvatarCharacter` native third-person input enabled:

- **W / S** — swim forward/backward using camera direction.
- **A / D** — strafe using camera orientation.
- **Mouse / right stick** — aim swimming direction.
- **Space** — ascend while underwater.
- **C** — descend/dive vertically.
- **Left Shift** — use the water body's sprint swim speed.

At the surface, forward movement follows camera yaw and permits a camera-down forward input to dive. Looking upward cannot drive the capsule out through the surface. Underwater, Forward uses the full camera-forward vector including Z, giving WoW/modern third-person style camera-directed 3D swimming.

Enhanced Input projects can disable the native movement bindings and continue calling the existing `Move Forward` / `Move Right` functions. Use `Add Swim Vertical Input` for custom ascend/descend actions.

## 4. Surface and underwater states

Each water body exposes:

- `Surface Swim Speed`
- `Underwater Swim Speed`
- `Sprint Swim Speed`
- `Swim Acceleration`
- `Swim Braking Deceleration`
- `Enable Surface Assist`
- `Surface Ride Depth`
- `Surface Assist Strength`
- `Maximum Surface Assist Speed`
- `Dive Camera Forward Z Threshold`
- `Underwater Enter Depth`
- `Underwater Exit Depth`

The separate enter/exit depths provide hysteresis so tiny wave/correction motion does not rapidly toggle Surface/Underwater state.

The player exposes:

- `Is Swimming In Water`
- `Is Swimming Underwater`
- `Get Player Swim State`
- `Get Active Swimmable Water`
- `On Swimming State Changed`
- `On Underwater State Changed`
- `BP On Swimming State Changed`
- `BP On Underwater State Changed`

These are the intended animation, audio, camera, underwater-post-process and gameplay integration points.

## 5. Underwater post-process / color presentation (v0.17.1)

Each water actor now exposes a replicated **Underwater Post Process Settings** profile. The locally controlled player's dedicated post-process component reads that profile only when its actual third-person camera crosses below the active water surface. This avoids the common third-person defect where the screen turns underwater while the camera is visibly still above the waterline.

The default profile provides blue/cyan grading plus a native local exponential distance-fog layer. Waterline enter/exit hysteresis prevents flicker, Shallow Water Blend Weight -> Full Strength Depth makes the presentation increase smoothly with camera depth, and the fog removes unrealistic long-range clarity without requiring a custom material. An optional project-authored Post Process material can still add caustics, refraction or stylized distortion.

Use `Is Local Camera Underwater` / `Get Underwater Post Process Blend Weight` only for local presentation. Continue using `Is Swimming Underwater` for replicated gameplay decisions. See `Docs/SETUP_UNDERWATER_POST_PROCESS.md`.

## 6. No-animation fallback pose

The framework does not require a dedicated swim Animation Blueprint.

`DMFPlayerAvatarCharacter` keeps its replicated collision capsule upright and rotates **only the skeletal mesh presentation** into a horizontal forward-swimming pose. This means an existing running locomotion animation can continue while the visual body lies flat rather than forcing the capsule sideways. The native fallback compensates around the imported skeletal-mesh bounds center instead of rotating around a typical foot/root component pivot, which keeps the body centered much more naturally at the water surface.

Avatar Blueprint settings:

- **Use Native Swim Fallback Pose**
- **Swim Fallback Mesh Rotation Offset** — default `Pitch -90`.
- **Swim Fallback Mesh Location Offset** — optional per-skin positional correction.
- **Swim Fallback Pose Interpolation Speed**
- **Pitch Swim Fallback With Travel Direction**
- **Maximum Swim Fallback Travel Pitch**

Different imported skeletons may use different mesh-forward axes. If a specific skin faces sideways/upward, tune only the Blueprint's rotation/location offsets; no C++ or collision change is required.

When a real swimming AnimBP is available, disable **Use Native Swim Fallback Pose** and drive animation from the replicated Blueprint state calls/events above. The networking/movement system remains unchanged.

### Multiplayer presentation note (v0.17.3)

The horizontal fallback is now visible correctly from **all peer viewpoints**. Owning players apply it immediately from local predicted water state. Remote simulated proxies and a listen host's view of remote clients use the server-authored `None / Surface / Underwater` state, but they do not replicate or directly fight over skeletal-mesh transforms. Instead, the framework updates ACharacter's network-smoothing mesh base and lets CharacterMovement perform the final visual interpolation. This is important for smooth remote movement and avoids the shake produced by competing direct mesh writes.

## 7. Runtime Blueprint API on the water actor

Read-only helpers:

- `Get Water Surface World Z`
- `Get Water Bottom World Z`
- `Get Depth Below Surface`
- `Is World Location Inside Swimming Bounds`
- `Is Swimming Enabled`

Authority-oriented runtime changes:

- `Set Swimming Enabled`
- `Set Water Surface Size`
- `Set Water Depth`
- `Set Surface Overlap Height`
- `Set Water Surface Z Offset`
- `Set Water Priority`

Presentation helpers:

- `Set Water Material`
- `Refresh Water Geometry`
- `Get Underwater Post Process Settings`
- `Set Underwater Post Process Settings` (authority at runtime)
- `Set Underwater Post Process Enabled` (authority at runtime)
- `Set Underwater Post Process Material` (authority at runtime)
- `Refresh Underwater Post Process Presentation`

At runtime, gameplay geometry and replicated underwater-profile setters reject non-authority calls. Replicated geometry/configuration updates rebuild client geometry/presentation automatically.

## 8. Multiplayer contract

- `DMFSwimmableWater` is a replicated actor.
- The server independently receives the same Pawn overlap and owns the replicated active-water pointer on each player.
- The owning client may predict the same overlap locally for immediate response, but cannot author the server's replicated swimming state.
- Underwater state is server-owned and replicates only when crossing the configured thresholds.
- Swim movement uses Unreal's normal CharacterMovement prediction/correction and replicated actor movement. No custom per-frame movement RPC was added.
- Runtime water geometry/movement values are ordinary replicated properties and update only when changed.
- Water actors do not Tick.

## 9. Persistence / Return Home

Swimming state itself is intentionally not written to account SaveGame. v0.15.1+ already persists the player's world transform. In v0.17.2, after that transform is restored the server calls the same explicit world-reconciliation path used by custom teleports: it checks the avatar's actual position against enabled `DMFSwimmableWater` bounds, resolves the controlling water, restores swim movement before the next gravity frame and resolves Surface/Underwater immediately. This does **not** depend on a BeginOverlap event firing after `TeleportTo`.

`DMFPlayerAvatarCharacter` also exposes **Rebuild Swimming State From World** for project-authored server teleports. Enable **Stop Movement If Swimming** when restoring/teleporting a stationary player so a stale Falling velocity cannot carry into the reconstructed swim state. Do not call this every frame; it is a deliberate one-shot lifecycle repair/teleport integration point.

Return Home remains server authoritative and now performs the same reconciliation after teleport. Teleporting from water to land therefore clears stale swimming/fog even if an EndOverlap callback is delayed; a deliberately water-placed Home destination also enters swimming correctly. The Home position is then checkpointed through the existing v6 player-location persistence.

## 10. Acceptance test

For a first test create a large water plane with at least 800-1200 cm depth.

1. Listen host walks into the water and confirms the mesh smoothly lays forward while the capsule remains upright.
2. Confirm idle/forward surface movement settles near the plane rather than sinking indefinitely.
3. Look down and hold Forward; confirm the character dives and `Is Swimming Underwater` changes true.
4. Underwater, pitch the camera up/down and hold Forward; confirm movement follows the camera in 3D.
5. Hold Space to ascend and C to descend.
6. Hold Shift and verify `Sprint Swim Speed` is used.
7. Exit at a shore/edge and confirm ordinary gravity/walking, mesh transform and footsteps return.
8. Repeat on a remote client and observe the swimming pose/movement from the host and another client.
9. Disconnect after autosave while surface swimming, reconnect, and verify the saved position restores with Surface swimming already active before the avatar can fall. Repeat while fully underwater and confirm Underwater state, horizontal pose, movement, post process and distance fog all recover.
10. Use Return Home from water and verify swimming clears cleanly and the Home location persists.
