# Player Camera Boom Zoom & Character Camera Collision Setup — v0.11.1-alpha

## Purpose

v0.11.1 adds a polished local third-person camera boom zoom system to `ADMFPlayerAvatarCharacter` and a framework-wide camera-collision policy for player avatars and Digimon.

The default framework behavior is immediately usable:

- **Mouse Wheel Up** zooms the local player's third-person camera inward.
- **Mouse Wheel Down** zooms outward.
- Zoom is clamped to project-wide minimum and maximum boom lengths.
- Boom distance interpolates smoothly instead of snapping between wheel notches.
- Player avatars and Digimon ignore `ECC_Camera`, preventing another character from forcing a spring arm inward when they pass between the camera and the controlled player.
- The spring arm still collision-tests against the world using `ECC_Camera`, so walls and level geometry continue to protect the camera normally.

Camera distance is local presentation only and is never replicated or persisted into account data.

## Project Settings

Open:

**Project Settings → Game → Digimon MMO Framework → Camera**

### Camera → Zoom

- **Enable Player Camera Zoom** — master switch for framework boom zoom.
- **Enable Default Player Camera Zoom Input** — binds Mouse Wheel Up/Down automatically. Disable this when a project supplies its own Enhanced Input action.
- **Player Camera Default Boom Length** — initial/reset zoom distance. Default: `400`.
- **Player Camera Minimum Boom Length** — closest allowed requested camera distance. Default: `220`.
- **Player Camera Maximum Boom Length** — farthest allowed requested camera distance. Default: `850`.
- **Player Camera Mouse Wheel Zoom Step** — requested distance change per wheel notch. Default: `75`.
- **Player Camera Zoom Interpolation Speed** — smoothing speed toward the requested boom length. Default: `14`; set `0` for instant zoom.

If minimum and maximum are accidentally entered in reverse order, runtime clamping sanitizes the range instead of producing an invalid camera state. The configured default is also clamped into the resolved range.

### Camera → Collision

- **Ignore Players And Digimon For Camera Collision** — enabled by default.

When enabled, every primitive component owned by a framework player avatar or framework Digimon is forced to **Ignore `ECC_Camera`** during construction and BeginPlay. This includes Blueprint-added primitive components, while leaving their Pawn, Visibility, combat and interaction collision responses untouched.

The player's spring arm continues using `ECC_Camera` collision testing. The result is the desired third-person behavior:

- walls / world geometry can still retract the boom;
- another player standing behind or walking past the controlled avatar does not retract it;
- an owned or wild Digimon walking between the player and camera does not retract it.

## Blueprint / Enhanced Input integration

Projects using their own Enhanced Input stack can disable **Enable Default Player Camera Zoom Input** and call the player avatar functions directly:

- `Add Camera Zoom Input` — positive values zoom in; negative values zoom out.
- `Set Camera Zoom Distance` — requests an absolute globally clamped boom length; optionally applies it instantly.
- `Get Camera Zoom Distance` — returns the requested boom length.
- `Reset Camera Zoom` — returns to the global default.
- `Refresh Camera Collision Policy` — reapplies the global `ECC_Camera` ignore rule after project-specific collision edits.

`ADMFDigimonCharacter` also exposes `Refresh Camera Collision Policy` for projects that deliberately alter Digimon collision at runtime.

## Multiplayer contract

Camera zoom introduces **no RPC, replicated property or SaveGame field**. Every owning client controls only its own requested boom distance.

The character `ECC_Camera` response is deterministic presentation/collision configuration applied on each local actor instance. It does not change movement authority, combat collision, target traces, damage, navigation, possession or account state.

## Acceptance test

1. Compile the plugin in UE5.8.1.
2. Start a listen-host + second-client PIE session.
3. On each window, scroll up repeatedly and confirm zoom stops at the configured minimum.
4. Scroll down repeatedly and confirm zoom stops at the configured maximum.
5. Confirm wheel notches transition smoothly rather than snapping when interpolation speed is non-zero.
6. Move the second player between the first player's camera and avatar. The first camera must not be pushed inward.
7. Move an owned or wild Digimon between the camera and player. The camera must not be pushed inward.
8. Back the camera into a wall/level obstacle. The spring arm must still retract for world collision.
9. Verify player-player collision, Digimon targeting, interaction traces, combat and movement remain unchanged.
10. Verify each client can choose a different zoom distance with no network coupling.
