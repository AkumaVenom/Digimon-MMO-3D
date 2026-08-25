# Polished Native UI Setup — v0.6.0-alpha

v0.6.0 rebuilds the framework's native fallback presentation. You do **not** need Widget Blueprints to get a usable polished frontend, Digimon collection, starter selector, character selector, or combat bar. Blueprint children remain supported when a project wants a completely custom skin.

## 1. Native widget classes

In **Project Settings -> Game -> Digimon MMO Framework -> UI**, the default classes should be:

- `Login Widget Class` -> `DMFLoginMainMenuWidget`
- `Starter Selection Widget Class` -> `DMFStarterSelectionWidget`
- `Player Skin Selection Widget Class` -> `DMFPlayerSkinSelectionWidget`
- `Digimon Inventory Widget Class` -> `DMFDigimonInventoryWidget`
- `Combat Quick Bar Widget Class` -> `DMFCombatQuickBarWidget`

Leave these native defaults assigned to use the v0.6 presentation. A Blueprint child may still replace any individual presentation while retaining the underlying framework APIs.

## 2. Digimon portraits — inventory + starter menu

Open each `DMFDigimonSpeciesData`, for example:

`DA_Species_Agumon -> 3D Presentation -> Portrait`

Assign a square or near-square `Texture2D` portrait/icon. The same existing field is used by:

- occupied Digimon inventory slots;
- the large selected-Digimon portrait;
- starter selection cards;
- starter selected-species preview.

If Portrait is empty, the native UI deliberately displays `PORTRAIT NOT SET` / `ASSIGN PORTRAIT` rather than silently producing an apparently broken blank slot.

Recommended source art: square 512x512 or 1024x1024. The framework does not require that resolution; it is simply a practical UI asset guideline.

## 3. Player skin portraits

Open each `DMFPlayerSkinData`, for example `DA_Skin_Tai`, then assign:

`UI -> Portrait`

That texture is used automatically for the native skin card and selected-character preview. Each skin can still use a completely different Skeletal Mesh, Skeleton and AnimBP.

## 4. Ability icons

Open each `DMFDigimonAbilityData` and assign:

`Identity -> Icon`

The native combat quick bar uses the icon automatically. Missing icons do not affect gameplay; the framed icon space remains empty while the ability name/SP/cooldown text still works.

## 5. Digimon collection / summon UI

Default input remains:

`I -> Toggle Digimon Inventory UI`

The native collection renders up to `MaxActiveDigimonInventory` slots (30 by default) in a 6-column grid. Occupied slots show portrait, species name, level and state badge. Empty capacity is shown as actual empty slots.

Select an occupied slot to inspect:

- portrait;
- species name;
- Stage + Attribute;
- Active / Summoned / Recalled / Defeated state;
- Level and EXP;
- current/max HP and SP;
- STR / INT / DEF / SPD;
- ABI / CAM;
- species description.

Actions remain:

- `SET ACTIVE / SUMMON` -> server validates ownership, defeated state, Species and WorldActorClass, then persists/spawns the active partner.
- `RECALL ACTIVE PARTNER` -> server recalls the world actor while retaining the active partner identity.
- `CLOSE [I]` -> closes the roster menu.

A defeated (`HP <= 0`) Digimon is marked `KO` and cannot be summoned until authoritative healing/revival.

## 6. Starter selection

The native starter selector reads the configured `DMFStarterRosterData` and creates portrait cards for enabled entries. Selecting a card displays its species portrait, Stage, Attribute, starting level/stats and `SelectionBlurb` (falling back to the species description).

`CONFIRM PARTNER` still calls the existing server-authoritative one-time starter grant. UI polish does not move starter ownership or persistence to the client.

## 7. Character skin selection

The skin selector automatically discovers enabled `DMFPlayerSkinData` Primary Assets, sorts by `DisplayOrder`, renders portrait cards, and shows the selected skin description. `APPLY CHARACTER` still routes through the authoritative player-avatar component and persists to the account.

## 8. Frontend

The native frontend now has two clear states:

**Login**
- Username
- Password
- Login / Continue
- status panel

**Logged in**
- Join Game
- Admin toggle
- Admin password / Unlock Admin
- Host & Play after successful admin unlock
- Logout
- Quit

`Logout` clears only the locally staged frontend credentials/admin unlock and returns the same widget to login state. It does not alter the server account database.

The fixed regular-player destination and server authentication remain hidden from the UI.

## 9. Combat quick bar

The native quick bar is bottom-center and shows:

- partner current/max HP and SP;
- current commanded/combat target;
- four ability cards;
- ability key `[1]` through `[4]`;
- ability name;
- SP cost;
- READY or remaining cooldown;
- optional ability icon.

The bar is presentation only. Ability execution still routes through the existing owning-player/server command path.

## 10. Blueprint reskinning remains supported

All major native widgets remain `Blueprintable`. You can assign a Blueprint child in Project Settings and replace the visual hierarchy while calling the same server-backed functions/events.

The v0.6 native layout adds new **optional** bindings. Legacy optional bindings remain so existing project Widget Blueprints are not intentionally broken by the polish pass.

## 11. First acceptance test

1. Compile the plugin in UE5.8.1.
2. Open MainMenu and press Play.
3. Confirm the login appears as a centered dark card instead of full-width gray bars.
4. Login and confirm the Play/Admin view replaces the credential form.
5. Complete skin selection and verify assigned skin portraits render.
6. Complete starter selection and verify assigned Digimon portraits render.
7. In gameplay press `I`.
8. Confirm a 6-column Digimon slot grid appears with empty capacity slots.
9. Select Agumon and confirm portrait + full stats populate on the right.
10. Recall and summon from the action buttons.
11. Close the menu and confirm the bottom-center combat bar displays ability cards/icons.
12. Repeat in a two-client network test and confirm all UI reflects replicated/server-authoritative state rather than creating local gameplay state.

## v0.7.0 shared Digimon menu shell
The v0.6 Collection presentation is now page one of the shared **DIGIMON MENU**. The native fallback adds `COLLECTION`, `SCAN & MATERIALIZE` and `CARE` tabs without removing any existing Collection slot/detail bindings. Use `Species -> Portrait` for both pages. Projects using a Blueprint child can mirror the same tab architecture and drive it with `Set Active Menu Tab`, `Refresh Inventory`, `Refresh Scan Data`, and `Refresh Care Data`. Future Bank/Party/Digivolution work should extend this shell rather than creating disconnected full-screen menus.


## v0.8.0 CARE page

The native fallback now provides a third first-class page, **CARE**, using the same 1180×720 menu shell, dark raised panels, cyan accent hierarchy and gold secondary emphasis as Collection and Scan. The page shows the active partner portrait/meta, a large Hunger meter, Happiness and Discipline meters, Care Mistakes, unlimited DigiMeat rules, waste/digestion status and the server-backed `FEED DIGIMEAT UNTIL FULL` action.

When feeding is accepted, the widget is intentionally removed rather than left translucent over the world. `ADMFMMOPlayerController` also removes the combat quickbar and restores game input before the first eating Montage. At server completion it recreates the menu and selects `EDMFDigimonMenuTab::Care`, so the player sees the updated Hunger state immediately after watching the animation.

Blueprint children may replace the layout while retaining `RefreshCareData`, `SetActiveMenuTab(Care)` and the owner component care delegates/RPC. Keep gameplay mutation on `UDMFPlayerDigimonComponent`; do not award Hunger from widget Blueprint logic.


## v0.9.0 automatic world nameplates

The polished native UI language now extends into the 3D world through automatic Player and Digimon nameplates. No manual Widget Component is required on framework-derived actors. Configure the master/per-category switches, distance culling and Blueprint widget overrides under **Project Settings → Digimon MMO Framework → UI → World Nameplates**. See `SETUP_WORLD_NAMEPLATES.md` for the complete contract.
