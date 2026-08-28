# Native Return Home HUD — v0.15.2

## Goal

Return Home is a server-authoritative convenience built on the v0.15.1 `DMFNewPlayerStart` and persistent world-location system. It deliberately lives inside **Party Quick Access** so normal gameplay gets no extra permanent button.

## Required world setup

1. Keep the Open World GameMode derived from `DMFMMOGameMode`.
2. Place at least one enabled **`DMFNewPlayerStart`** at the desired Home/new-player destination.
3. If several exist, the existing highest `Spawn Priority` + deterministic tie-break rule selects the destination.
4. Keep the spawn transform clear enough for the framework player capsule and nearby partner placement.

## Project Settings

Open **Project Settings -> Game -> Digimon MMO Framework -> UI -> Party Quick Access -> Home**.

Recommended defaults:

- **Enable Party Quick Access Home Button = true**
- **Home Teleport Request Cooldown Seconds = 4.0**
- **Home Teleport Notification Widget Class = DMFHomeTeleportNotificationWidget** (or a Blueprint child)
- **Show Native Home Teleport Notifications = true**
- **Home Teleport Notification Hold Seconds = 3.0**

The existing **Show Native Party Quick Bar** and **Enable Default Party Quick Access Input** must remain enabled for the ready-to-use Tab workflow. Custom HUD/input projects can disable those and call `RequestReturnHome` themselves.

## Native player flow

1. Press **Tab**.
2. The existing Party Quick Access interaction mode releases look/movement and shows the mouse.
3. `HOME` appears in the action row beside `RECALL`, `OPEN PARTY`, and `OPEN BANK`.
4. Click **HOME**. The button enters a short pending state (`RETURNING HOME...`) and cannot be spam-clicked while awaiting the server result.
5. The server resolves `DMFNewPlayerStart`; the client does **not** send coordinates.
6. On success the player teleports, the partner is cleanly disengaged/repositioned, the new location is saved immediately, the Tab mode closes, gameplay input returns, and an owner-only **HOME • ARRIVED** toast appears.
7. Missing/blocked Home configuration or cooldown rejection produces **HOME • UNAVAILABLE** feedback and leaves the player in place.

## Combat/partner contract

Return Home is an explicit encounter boundary:

- current partner command target is cleared;
- current partner combat target, queued command, movement, recovery timer and durable battle-encounter latch are cleared;
- HP/SP and existing ability cooldowns are **not** restored/reset;
- hostile Digimon whose authoritative current target is the player's partner are disengaged;
- already-launched framework `DMFAbilityProjectileActor` instances targeting **or sourced from** that partner are destroyed;
- a summoned partner is moved beside the player using the normal `PartnerSpawnOffset`.

This prevents battle music/AI/projectiles from following the player across a long-distance Home teleport while avoiding a free heal or cooldown reset. The server also rejects Return Home while an authoritative Care or Digivolution sequence is active, so those presentation/commit transactions cannot be interrupted by teleporting.

## Persistence contract

The destination is checkpointed immediately through the existing v6 `PlayerWorldLocation` record. No new SaveGame field/schema is introduced. Normal autosave/logout continues to overwrite this checkpoint later as the player moves through the world.

## Blueprint customization

Custom HUDs can use:

- `ADMFMMOPlayerController::RequestReturnHome()` — action request only.
- `ADMFMMOPlayerController::OnHomeTeleportResult` — owner-local deterministic result delegate.
- `UDMFHomeTeleportNotificationWidget::BP_OnHomeTeleportResultPresented` — cosmetic presentation hook.
- `ADMFMMOGameMode::ReturnAuthenticatedPlayerHome(...)` — authority-only server/admin helper.

Do not build a client-side teleport around these hooks. The trusted destination remains `ChooseNewPlayerSpawnPoint` on the authoritative GameMode.

## Multiplayer acceptance

Test listen host + one remote client with separate accounts. Place them at different locations, press Tab/Home independently, verify each authoritative pawn returns to the same `DMFNewPlayerStart`, each owner alone sees their toast, both partners follow their own owner, and reconnecting restores each account's most recently persisted location.
