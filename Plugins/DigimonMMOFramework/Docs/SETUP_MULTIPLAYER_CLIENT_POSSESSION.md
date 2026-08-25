# Multiplayer Client Avatar Possession — v0.6.1-alpha

## Purpose

v0.6.1 hardens the remote-join path so an authenticated client cannot remain in Unreal's fallback `DefaultPawn` after choosing a character skin. The gameplay server owns the spawn/possession decision; the UI only chooses persistent presentation data.

## Required OpenWorld setup

1. Open the gameplay/OpenWorld map.
2. World Settings -> GameMode Override must be `DMFMMOGameMode` or a Blueprint child.
3. In that GameMode, Default Pawn Class should be your `BP_DMFPlayerAvatarCharacter` (parent `DMFPlayerAvatarCharacter`).
4. Preserve `DMFMMOPlayerController` and `DMFPlayerState` or compatible Blueprint children.
5. Place at least one `PlayerStart` in a valid walkable location.

The framework now guards against an accidental bad Default Pawn Class, but the correct project setting is still recommended so the project's avatar Blueprint-specific defaults are used.

## Automatic authority flow

```text
Remote client joins server
        -> server authenticates account
        -> server initializes PlayerState/avatar/digimon data
        -> normal Unreal HandleStartingNewPlayer / RestartPlayer
        -> DMF validates possessed pawn
             -> correct DMF avatar: keep it
             -> missing/default/spectator/wrong pawn: recover it
        -> remote ClientRestart reasserts authoritative possession
        -> selected account skin applies to possessed avatar
        -> active partner is restored when starter onboarding is complete
```

A remote local controller also retries the validation for a short bounded period until it observes a `DMFPlayerAvatarCharacter`. This covers travel/replication ordering without permanent polling.

## Skin selection checkpoint

When a new client chooses Tai/Matt/etc., `ServerSetPlayerSkin` now verifies that the PlayerState owns a valid framework avatar. If not, the GameMode recovers it before applying the selected skin. The player should therefore leave character selection as the selected multiplayer character, not as `DefaultPawn`.

## Blueprint recovery calls

Normally no project Blueprint call is required. For diagnostics/admin recovery only:

- `DMFMMOGameMode -> Ensure Framework Player Avatar(PlayerController)` — server-authoritative repair.
- `DMFMMOGameMode -> Has Framework Player Avatar(PlayerController)` — inspect server possession.
- `DMFMMOPlayerController -> Server Ensure Framework Player Avatar()` — owning-client request to server.
- `DMFMMOPlayerController -> Is Framework Player Avatar Possessed()` — local possession check.
- GameMode event `BP On Framework Player Avatar Recovered` — optional logging/VFX/project hook.

Do not manually spawn or possess the player pawn from the skin-selection widget. Character skin selection is presentation/persistence; GameMode owns gameplay spawning and possession.

## Two-machine acceptance test

1. Host PC: login -> Admin -> Host & Play. Confirm host remains correct.
2. Client PC: login -> Join Game.
3. On a fresh client account, select a player skin.
4. Confirm the client immediately controls the third-person DMF avatar, not a flying DefaultPawn.
5. Confirm the selected skin is visible on host and client.
6. Complete starter selection. Confirm the partner spawns beside the client's avatar, not at a stale/default pawn location.
7. Move/jump/sprint on the client and verify host sees replicated movement.
8. Disconnect/rejoin the same account. Confirm saved skin and active partner restore while the client is again possessed as the DMF avatar.
9. Repeat with another joining client if available.

## Troubleshooting

If recovery logs say the configured DefaultPawnClass is not a `DMFPlayerAvatarCharacter`, fix the OpenWorld GameMode Default Pawn Class. If recovery cannot create an avatar at all, verify the gameplay map actually uses the DMF MMO GameMode and contains a valid PlayerStart.
