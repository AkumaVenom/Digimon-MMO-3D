# Persistent Player World Location & New Player Spawn — v0.15.1

This release separates **first-login placement** from **returning-player restoration** while keeping both decisions server-authoritative.

## 1. Place the first-login spawn

1. Open the configured **Open World** gameplay map.
2. In Place Actors / Class search, find **DMFNewPlayerStart** (`ADMFNewPlayerStart`).
3. Place it where a brand-new account should first enter the MMO world.
4. Rotate it to the desired starting facing direction.
5. Keep at least one ordinary Unreal `PlayerStart` in the map as a collision/recovery fallback.

`DMFNewPlayerStart` exposes:
- **Enabled** — disabled points are ignored without deleting them from the map.
- **Spawn Priority** — highest enabled value wins. Equal priorities use deterministic actor-name order.

One point is enough for the normal project setup. Multiple points are supported for later region/shard logic. A Blueprint child of `DMFMMOGameMode` may override **Choose New Player Spawn Point** if a project needs custom selection.

## 2. Project Settings

Open **Project Settings -> Game -> Digimon MMO Framework -> Persistence -> Player World Location**.

Recommended defaults:
- **Enable Player World Location Persistence = true**
- **Use Dedicated New Player Spawn = true**

The normal **Account Autosave Interval** (default 30 seconds) remains the periodic checkpoint cadence. No second location-save timer is created.

## 3. First-login behavior

A genuinely fresh onboarding account whose `PlayerWorldLocation.bHasSavedLocation` is false uses the dedicated new-player path. The native freshness test matches onboarding: no starter selected, no active partner, and empty Party + Bank. An established pre-v0.15.1 account may also have no v6 location yet, but it is **not** treated as a new player; it uses the normal `PlayerStart` once and immediately creates its first location checkpoint.

For a fresh account, on entry:
1. Server authenticates and hydrates the account.
2. Unreal establishes the framework player avatar/possession.
3. `DMFMMOGameMode` selects the enabled `DMFNewPlayerStart` with the highest priority.
4. The server moves the authoritative avatar to that transform before active-partner restoration.
5. The framework immediately saves the resulting map/location/rotation as the first checkpoint.

That immediate checkpoint is deliberate: if the server/client disconnects before the first 30-second autosave, the next login is still a returning-location login rather than another first-login spawn.

If no enabled `DMFNewPlayerStart` exists, Unreal's normal `PlayerStart` result is retained and checkpointed. The framework logs a warning rather than blocking login.

## 4. Returning-player behavior

For an account with a saved location, the server restores:
- gameplay level name
- avatar world location
- avatar actor rotation
- checkpoint UTC timestamp (diagnostic/persistence metadata)

The restore is accepted only when:
- player world-location persistence is enabled,
- saved map name matches the current gameplay level (PIE prefixes are removed),
- location and rotation contain finite values,
- Unreal can place the avatar safely at the desired transform.

If any condition fails, the player remains at Unreal's normal collision-safe `PlayerStart` for that login. A later normal autosave can establish the new current-map checkpoint.

## 5. Saving

Position is captured from the **server-owned `DMFPlayerAvatarCharacter`**, never from a client-supplied vector.

Checkpoints occur:
- immediately after the first gameplay spawn,
- on the existing periodic account autosave,
- on GameMode logout/full account save,
- when server/admin Blueprint code explicitly calls **Save Authenticated Player World Location Now**.

The periodic Digimon account transaction also writes current avatar skin + world location into the same `FDMFAccountRecord`, avoiding competing save files or race-prone parallel persistence systems.

## 6. Save schema v6

`FDMFAccountRecord` now contains `FDMFPlayerWorldLocationState`:
- `bHasSavedLocation`
- `MapName`
- `Location`
- `Rotation`
- `SavedUtcTicks`

Schema v5 and older accounts migrate safely with `bHasSavedLocation=false`; existing Party, Bank, Digivolution, Care, Scan, money, avatar skin and progression data are preserved. Established legacy accounts use normal PlayerStart once to seed their first v6 checkpoint, while still-fresh onboarding accounts use `DMFNewPlayerStart`.

## 7. Multiplayer contract

- Spawn/restore selection is GameMode/server only.
- Saved location is private host-side account data and is not replicated as an owner/private array.
- Other players see the avatar only through normal Unreal replicated character movement after spawn.
- No new RPC is required.
- Each authenticated username persists its own position independently.
- Host and remote clients can reconnect to different prior coordinates without sharing/cross-loading transforms.

## 8. Acceptance test

### New account
1. Place `DMFNewPlayerStart` somewhere visibly different from the normal `PlayerStart`.
2. Create/login a brand-new account and enter gameplay.
3. Confirm the player appears at `DMFNewPlayerStart` and the active partner (after onboarding allows it) spawns relative to that player.

### Returning account
1. Move far away from the new-player spawn.
2. Wait longer than `Account Autosave Interval` **or** disconnect normally so Logout saves.
3. Rejoin the same account.
4. Confirm the player returns to the saved position/facing rather than `DMFNewPlayerStart`.

### Two-account multiplayer
1. Host with Account A and join with Account B.
2. Move A and B to clearly different locations.
3. Allow autosave/disconnect both.
4. Reconnect each account independently.
5. Confirm A returns only to A's location and B returns only to B's location.

### Fallback
Temporarily remove/disable every `DMFNewPlayerStart`, use a fresh test account, and confirm normal `PlayerStart` fallback succeeds and becomes the account's first checkpoint.

## Return Home integration (v0.15.2)

The same `DMFNewPlayerStart` is now the authoritative **Home** destination. Pressing Tab and clicking the Party Quick Access `HOME` button does not restore an arbitrary old checkpoint and does not trust a client transform; the server runs `ChooseNewPlayerSpawnPoint`, performs the teleport, then immediately writes the resulting transform through `SaveAuthenticatedPlayerWorldLocationNow`. The next login therefore restores Home if no later movement checkpoint supersedes it.

A missing or obstructed `DMFNewPlayerStart` rejects the request with owner feedback. The framework also ends the active partner encounter and removes framework projectiles already targeting that partner before repositioning it beside the player, preventing combat from following the long-distance teleport. See `SETUP_RETURN_HOME_HUD.md`.
## Swimmable-water restore integration (v0.17.2)

When the saved transform resolves inside an enabled `DMFSwimmableWater`, the server no longer waits for a post-teleport overlap callback. It immediately rebuilds water occupancy from world geometry, reinstates swimming movement and Surface/Underwater state, and then lets those existing replicated fields correct the owning client. Underwater post process/distance fog is still local-camera presentation and rebuilds from the restored active water. No swimming flag is added to the account record.

