# Manual Partner Combat, Battle Balance, Healer and Digimon Roster UI — v0.5.2-alpha

This guide covers the v0.5.x gameplay-control layer added on top of the working v0.4.1 wild-spawner baseline. v0.5.2 adds the preferred native no-cast player interaction wrapper; see `SETUP_PLAYER_INTERACTION_SYSTEM.md` for the complete interaction API.

## 1. Player partner combat is manual by default

Open **Project Settings → Game → Digimon MMO Framework → Combat → Player Partner**.

Recommended defaults:

- `Player Partner Auto Battle = false`
- `Partner Aggro Range = 1200` (only used if auto battle is deliberately enabled)
- `Partner Leash Range = 2500`

With auto battle disabled, the owned partner still follows its player. It does not autonomously acquire every nearby hostile and does not repeatedly basic-attack without a player command.

The recommended v0.5.2 input flow is:

- `E`: native player `Interact` — target the hostile Digimon only by default.
- `1`–`4`: execute/queue the corresponding active-partner ability slot against the selected target.
- Legacy Left Mouse targeting defaults **off** (`Enable Default Click Target Input = false`) so it does not compete with the interaction flow. `Enable Default Ability Slot Input = true` keeps 1–4 active.

The player pawn itself now exposes `Interact`, so normal project setup requires no controller or Digimon casts. With `Attack On Digimon Interact = false` (default), `E` selects only and the partner remains idle until an ability command is sent.

For project-owned Enhanced Input, disable `Enable Native Interaction Input` on the player Blueprint and call the inherited `Interact` node from the project's Input Action.

Lower-level controller calls remain available for specialized systems:

- `Set Digimon Command Target(Target)`
- `Command Partner Target And Attack(Target, SlotIndex)`
- `Command Active Partner Ability Slot(SlotIndex)`

No-cast player-character wrappers are also available:

- `Interact With Actor`
- `Interact With Digimon`
- `Interact With Digimon And Attack`
- `Command Digimon Ability Slot`

`SlotIndex` is zero-based in Blueprint/C++ (`0` = quick slot 1, `1` = quick slot 2, etc.).

The client is not trusted with damage. The server still validates active partner, hostility, ability slot, SP, cooldown, leash and range; out-of-range valid commands use the existing server chase queue.

## 2. JRPG-oriented player/wild battle pacing

Open **Project Settings → Game → Digimon MMO Framework → Combat → Player Partner → Balance**.

v0.5.0 defaults:

- `Player Partner Outgoing Damage Multiplier = 1.50`
- `Player Partner Incoming Damage Multiplier = 0.50`

These are runtime combat-role modifiers. They do **not** rewrite or inflate the saved Species/Instance stats. This keeps persistent STR/INT/DEF/HP values truthful while allowing owned partners to have the intended Cyber-Sleuth-like advantage against ordinary equal-level wild encounters.

Every `BP_Wild_<Species>` derived from `DMFWildDigimonCharacter` also exposes:

- `Outgoing Damage Multiplier = 1.0`
- `Incoming Damage Multiplier = 1.0`

Keep ordinary wild Digimon at `1.0 / 1.0`. Bosses or special encounters can override those values per Blueprint without changing the species asset used elsewhere.

## 3. Native Digimon roster / summon menu

The framework now includes a native fallback `DMFDigimonInventoryWidget`.

Default input:

- Press `I` to open/close the Digimon menu.

Project setting:

- **Project Settings → Digimon MMO Framework → UI → Enable Default Digimon Inventory Menu Input**

Disable that setting if the project owns input and call the controller functions directly:

- `Open Digimon Inventory UI`
- `Close Digimon Inventory UI`
- `Toggle Digimon Inventory UI`
- `Refresh Digimon Inventory UI`
- `Is Digimon Inventory UI Open`

The native roster lists each replicated active-inventory Digimon with level, HP, SP, active/summoned state and defeated state.

Actions:

- **Set Active / Summon**: server validates ownership, makes the selected Digimon the persistent active partner and spawns it beside the player.
- **Recall Partner**: destroys the currently summoned partner actor but keeps the persistent active-partner selection, so it can be summoned again later.
- Defeated Digimon cannot be summoned until healed.

Returning accounts still attempt the normal automatic active-partner spawn during `HandleStartingNewPlayer`. The roster menu is also always available after onboarding, so a missing/recalled partner can be explicitly summoned again.

### Custom reskinned inventory widget

Create a Widget Blueprint child of `DMFDigimonInventoryWidget` and assign it in:

**Project Settings → Digimon MMO Framework → UI → Digimon Inventory Widget Class**.

Optional BindWidget names:

- `DigimonChoicesBox` (`VerticalBox`)
- `DigimonDetailsText` (`TextBlock`)
- `DigimonStatusText` (`TextBlock`)
- `SummonDigimonButton` (`Button`)
- `RecallDigimonButton` (`Button`)
- `CloseDigimonInventoryButton` (`Button`)

Blueprint presentation events:

- `BP On Digimon Preview Changed`
- `BP On Partner Action Result`

This v0.5.0 UI is the functional roster/select/summon/recall layer. Full drag/drop active inventory ↔ party ↔ bank management remains a later collection-UX phase.

## 4. Create a free Digimon healer

Create a Blueprint Class derived from:

`DMFHealerActor`

Example name:

`BP_DigimonHealer`

Add your own Skeletal Mesh, Static Mesh, Widget Component or NPC presentation in the Blueprint. v0.5.2 already supplies a native interaction collision sphere, so additional collision is optional and should be added only for the project's physical/presentation needs.

### Healer Class Defaults

Under **Digimon MMO → Healer**:

- `Enabled = true`
- `Interaction Radius = 350`
- `Reuse Delay = 0.5`

Under **Digimon MMO → Healer → Restore**:

- `Heal HP = true`
- `Heal SP = true`
- `Restore Defeated Digimon = true`
- `Include Bank Storage = true`
- `Summon Active Partner After Heal = true`

Under **Text**, customize:

- `Interaction Prompt`
- `Success Message`
- `Already Healthy Message`
- `Disabled Message`
- `Too Far Message`

There is intentionally no cost/money property: the healer is free.

## 5. Use the healer through the native player interaction system

In v0.5.2 the normal healer path requires no healer cast and no `Request Heal` wiring. Look at the healer and call the player pawn's:

`Interact`

The native interaction dispatcher detects `DMFHealerActor` and routes the request through the owning `DMFMMOPlayerController`. `DMFHealerActor` now also owns a query-only `InteractionCollision` sphere. Its exposed `Interaction Collision Radius` defaults to 100 and its `Interaction Trace Channel` defaults to Visibility; these are separate from the authoritative `Interaction Radius` (350 by default). The basic healer Blueprint is therefore traceable without adding project collision just for interaction.

If a project already has an Actor reference from some other UI/overlap system, call `Interact With Actor` or `Interact With Healer` on the player pawn; no cast is required.

Do not directly modify HP from the client Blueprint. The authoritative healer validates:

- healer is enabled;
- caller has a valid player pawn/state/component;
- player is inside `Interaction Radius`;
- reuse delay has elapsed;
- the account has Digimon to restore.

The server then restores configured HP/SP, optionally revives defeated Digimon, optionally updates bank records, persists immediately, and optionally re-summons the selected active partner.

Controller result event:

- `On Healer Interaction Result(Success, Message, DigimonHealed)`

Healer Blueprint hooks:

- `BP On Player Healed` — authoritative gameplay-side hook.
- `BP On Heal Presentation` — multicast cosmetic hook for healing VFX/audio/NPC animation on all clients.
- `BP On Enabled State Changed` — cosmetic/UI reaction when the replicated availability flag changes.

## 6. Recommended first acceptance test

1. Set the framework player-partner auto battle setting to `false`.
2. Start through MainMenu → Login → Host & Play.
3. Approach a level-1 wild Digimon with a level-1 starter.
4. Verify the owned partner follows but does not auto-target or auto-attack.
5. Look at the wild Digimon and press `E` / call `Interact`. Verify target changes but no attack begins by itself.
6. Press `1`. Verify one server-authoritative attack executes/queues.
7. Confirm the player partner's battle pacing is materially safer than v0.4.1 with the default 1.50 outgoing / 0.50 incoming tuning.
8. Press `I`. Verify the roster menu opens.
9. Recall the partner, then select it and use **Set Active / Summon**. Verify the replicated partner returns.
10. Let the partner take damage or be defeated.
11. Look at `BP_DigimonHealer` and press `E` / call player `Interact`. Verify HP/SP restore, defeated revival if enabled, immediate UI refresh and persistence.
12. Disconnect/reconnect. Verify restored HP/SP and selected active partner persist.
13. Repeat from a remote client against a listen host. Verify the client cannot heal or attack authoritatively without the server accepting the request.

## v0.6.0 inventory presentation update

The native Digimon inventory no longer uses a vertical text list. It now reads `DMFDigimonSpeciesData::Portrait` for a 6-column slot grid and shows a selected-Digimon profile with summon/recall controls. No gameplay setup changed: `I` still toggles the menu and summon/recall still use `UDMFPlayerDigimonComponent` server RPCs. Assign each species Portrait to get the intended icon presentation. See `SETUP_POLISHED_NATIVE_UI.md`.
