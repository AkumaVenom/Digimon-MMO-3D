# Native Player Interaction / Digimon Targeting — v0.5.2-alpha

This release removes the requirement to build a project-side trace/cast chain just to target a wild Digimon or use a healer. The normal gameplay entry point now lives directly on `ADMFPlayerAvatarCharacter`.

## Core rule

For the standard framework player Blueprint, the intended graph is simply:

`Input Action / Key -> Interact`

No cast to `DMFDigimonCharacter`, `DMFWildDigimonCharacter`, `DMFMMOPlayerController`, `DMFPlayerState` or `DMFHealerActor` is required.

The player character performs the local interaction trace, identifies the framework actor type internally, and forwards the actual gameplay request through the existing server-authoritative controller / PlayerState path.

## 1. Player Blueprint setup

Open the Blueprint derived from `DMFPlayerAvatarCharacter`, for example:

`BP_DMFPlayerAvatarCharacter`

Under **Class Defaults -> Digimon MMO -> Interaction** configure:

### Input

- `Enable Native Interaction Input = true`
  - Binds `E` directly through the framework.
  - This is independent of `Enable Native Third Person Input`.
  - If the project uses Enhanced Input, set this to `false` and call `Interact` from the project's Input Action instead.

### Trace

Recommended initial values:

- `Interaction Distance = 1200`
- `Interaction Sweep Radius = 30`
- `Interaction Trace Channel = Visibility`
- `Interaction Trace Complex = false`
- `Ignore Active Partner During Interaction Trace = true`
- `Draw Debug Interaction Trace = false`

`Interaction Sweep Radius` makes targeting more forgiving than a one-pixel line trace. Set it to `0` for a strict line trace.

The trace begins at the framework follow camera and travels forward. The player pawn is always ignored; the currently summoned owned partner can also be ignored so it does not block attempts to target a wild Digimon standing beyond it.

### Digimon

Recommended manual-combat values:

- `Attack On Digimon Interact = false`
- `Digimon Interact Attack Slot Index = 0`

With the default `false`, interaction only selects the hostile Digimon. It does **not** attack automatically.

The zero-based slot convention is:

- `0` = visible quick slot 1
- `1` = visible quick slot 2
- `2` = visible quick slot 3
- `3` = visible quick slot 4

## 2. Simplest setup — native E key

If `Enable Native Interaction Input` is true, no Blueprint graph is required for the interaction key.

At runtime:

1. Look at a hostile wild Digimon.
2. Press `E`.
3. The player trace identifies the Digimon.
4. The player's active partner command target is set through the server route.
5. The partner does not attack until an ability command is sent.

Then use the existing `1`–`4` quick-slot input, or call `Command Digimon Ability Slot` on the player Blueprint. In v0.5.2 Project Settings, legacy Left-Mouse target selection defaults off while the native 1–4 ability bindings remain enabled.

## 3. Enhanced Input / custom input

If the project uses its own input stack:

1. Set `Enable Native Interaction Input = false`.
2. In `BP_DMFPlayerAvatarCharacter`, handle the desired Input Action.
3. Call the inherited node:

`Interact`

That is the entire standard graph.

No `Get Controller` and no Cast nodes are needed.

## 4. What Interact handles automatically

### Hostile Digimon

`Interact` internally identifies any actor derived from `DMFDigimonCharacter`.

With `Attack On Digimon Interact = false`:

- the active partner must exist;
- the Digimon must be a valid hostile/targetable combat target;
- the command target is sent through `DMFMMOPlayerController -> DMFPlayerDigimonComponent -> ServerSetCommandTarget`;
- no attack is started.

With `Attack On Digimon Interact = true`:

- the same target validation occurs;
- the configured quick slot is sent through the existing target+attack server command route;
- out-of-range valid attacks continue to use the framework chase/queue behavior.

### Healer

If the trace hits `DMFHealerActor`, `Interact` automatically requests use of that healer through the owning PlayerController. In v0.12.2 the same server path also enforces the healer's exclusive treatment/busy state; accepted real restores drive the replicated green-light/VFX/audio presentation described in `SETUP_POLISHED_HEALER_PRESENTATION.md`.

The healer still validates on the server:

- enabled state;
- player pawn/state validity;
- authoritative distance to the healer;
- reuse delay;
- Digimon state.

The client never directly edits HP/SP or persistence.

### Other actors

Unsupported actors fire:

`BP On Unhandled Interaction`

This gives a project a clean extension point for future NPCs, quest actors, terminals, doors or other project-specific interaction types without changing the core Digimon/healer behavior.

## 5. No-cast Blueprint API on the player character

All of these nodes are inherited directly by `BP_DMFPlayerAvatarCharacter`:

### General

- `Interact`
- `Interact With Actor`
- `Find Interaction Target`
- `Get Last Interaction Actor`
- `Get Interaction Prompt For Actor`

### Digimon

- `Interact With Digimon`
- `Interact With Digimon And Attack`
- `Target Digimon From Actor`
- `Target And Attack Digimon From Actor`
- `Clear Digimon Target`
- `Command Digimon Ability Slot`
- `Get Current Digimon Target`

### Healer

- `Interact With Healer`

The `...From Actor` / `Interact With ...` functions accept a generic `Actor` reference and perform the framework cast internally. They are specifically provided so Blueprint logic that already has an overlap/hit actor does not need to cast it first.

## 6. Example: target only, then attack separately

Recommended player-controlled MMO flow:

`E / Interact -> target hostile Digimon only`

then:

- `1` -> ability slot 1
- `2` -> ability slot 2
- `3` -> ability slot 3
- `4` -> ability slot 4

If using project-owned ability input instead of the native number keys, call:

`Command Digimon Ability Slot`

with zero-based slot index `0`–`3`.

This keeps the partner from attacking every Digimon in sight and makes the player explicitly initiate combat.

## 7. Example: one button target + attack

If a specific game interaction should immediately attack:

- call `Interact With Digimon And Attack` with the generic Actor reference and slot index; or
- enable `Attack On Digimon Interact` and set `Digimon Interact Attack Slot Index`.

The project still does not gain damage authority. The server revalidates the requested combat command.

## 8. Interaction feedback / UI hooks

`ADMFPlayerAvatarCharacter` exposes:

`On Interaction Result`

Parameters:

- `Success`
- `Target Actor`
- `Interaction Type`
- `Message`

Interaction types are defined by `EDMFPlayerInteractionType`:

- `None`
- `Digimon Target`
- `Digimon Target And Attack`
- `Healer`
- `Unhandled`

The player also exposes:

- `BP On Digimon Interacted(Digimon, Targeted, Attack Command Sent)`
- `BP On Unhandled Interaction(Target Actor)`

These are presentation/extension hooks. They are not authority bypasses.

For a target name prompt, call:

`Get Interaction Prompt For Actor`

Framework Digimon return a prompt based on their Species display name (for example `Target Gabumon`). Healers return their configured `Interaction Prompt`.

## 9. Healer collision is now automatic

`DMFHealerActor` now contains:

`InteractionCollision`

It is a native query-only sphere with independent Details-panel settings:

- `Interaction Collision Radius = 100` by default;
- `Interaction Trace Channel = Visibility` by default;
- it ignores every other collision channel;
- it does not generate overlap events.

The collision radius is intentionally separate from `Interaction Radius = 350`, which remains the authoritative server-side maximum use distance. If you change the player interaction trace channel, set the healer interaction trace channel to the same value.

Therefore a basic Blueprint derived from `DMFHealerActor` can be placed in the world and detected by the native `Interact` call even if its cosmetic mesh has no useful collision.

You may still add your own mesh, Widget Component, NPC animation, VFX and other presentation components.

## 10. Collision requirements for Digimon

Framework Digimon characters use their Character capsule for gameplay collision. The capsule must block the selected player `Interaction Trace Channel` (Visibility by default).

If a project changes Digimon collision presets, preserve a blocking response on the channel configured in the player interaction settings or select a different interaction trace channel in the player Blueprint.

## 11. Multiplayer authority model

The interaction trace itself is a local input/presentation decision. It does not perform authoritative gameplay mutation.

Digimon flow:

`Local Player Interact -> local Digimon detection -> owner PlayerController -> PlayerState Digimon component server RPC -> combat validation`

Healer flow:

`Local Player Interact -> local healer detection -> owner PlayerController server RPC -> healer authoritative range/reuse validation -> Digimon restore -> persistence`

Clients cannot use `Interact` to directly set damage, HP, SP, inventory or SaveGame records.

## 12. Recommended acceptance test

1. Compile v0.5.2 in UE5.8.1.
2. Open `BP_DMFPlayerAvatarCharacter` Class Defaults.
3. Set `Enable Native Interaction Input = true`.
4. Set `Attack On Digimon Interact = false`.
5. Keep `Interaction Distance = 1200`, `Sweep Radius = 30`, channel `Visibility`.
6. Start through MainMenu -> Login -> Host & Play.
7. Confirm the owned partner follows but does not auto-attack.
8. Look directly at a wild Digimon and press `E`.
9. Confirm the command target changes but no attack begins.
10. Press `1`. Confirm the partner executes/queues ability slot 1 against the selected target.
11. Press `E` on another wild Digimon. Confirm the target changes cleanly.
12. Place a Blueprint derived from `DMFHealerActor` without adding custom collision.
13. Look at the healer while within `Interaction Radius` and press `E`.
14. Confirm the server restores Digimon according to healer policy.
15. Repeat as a remote client connected to the listen host.
16. Confirm the host and client agree on target/combat/healing state and that the client cannot bypass server validation.

## 13. Custom input recommendation

For the final game, Enhanced Input is still appropriate. The framework-native `E` binding exists as a ready-to-use fallback/test path. A production Input Action should simply call the same inherited `Interact` function, preserving the native interaction implementation while allowing the project to own key rebinding and input contexts.
