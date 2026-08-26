# Polished Native UI Setup — v0.12.1-alpha

v0.6.0 rebuilds the framework's native fallback presentation. You do **not** need Widget Blueprints to get a usable polished frontend, Digimon collection, starter selector, character selector, or combat bar. Blueprint children remain supported when a project wants a completely custom skin.


## v0.12.1 responsive layout hardening

The native fallback Digimon Menu now uses a larger 1240x820 design canvas inside its existing **Scale To Fit / Down Only** wrapper. On normal desktop viewports it therefore has enough vertical room for Party/Bank/Scan/Care content without forcing the profile footer into body text; on smaller viewports the complete menu still scales down as one unit.

Party and Scan descriptions, Bank detail guidance and Care rules are clipped/scrollable regions. Action buttons remain outside those regions, so authored species descriptions or longer localized strings cannot draw through the buttons. The Bank six-column card grid is itself scrollable, which preserves fixed card dimensions even when `DigimonBankSlotsPerPage` is increased.

Dense Party/Bank/Party-destination and HUD cards use compact internal button padding. The Party Quick Access bar stacks each portrait over a two-line state/name/level label, and the combat quickbar collapses a missing ability-icon frame instead of reserving an empty square. These changes are native fallback presentation only and do not alter the Blueprint replacement classes or server authority.

## 1. Native widget classes

In **Project Settings -> Game -> Digimon MMO Framework -> UI**, the default classes should be:

- `Login Widget Class` -> `DMFLoginMainMenuWidget`
- `Starter Selection Widget Class` -> `DMFStarterSelectionWidget`
- `Player Skin Selection Widget Class` -> `DMFPlayerSkinSelectionWidget`
- `Digimon Inventory Widget Class` -> `DMFDigimonInventoryWidget`
- `Combat Quick Bar Widget Class` -> `DMFCombatQuickBarWidget`
- `Party Quick Bar Widget Class` -> `DMFPartyQuickBarWidget`
- `World Chat Widget Class` -> `DMFWorldChatWidget`

Leave these native defaults assigned to use the current framework presentation. A Blueprint child may still replace any individual presentation while retaining the underlying framework APIs.

## Player footstep presentation — v0.10.4

Player footsteps are configured globally under **Project Settings → Game → Digimon MMO Framework → Player Avatar → Footsteps**. Assign **Player Footstep Sound (Sound Cue Recommended)** and leave the native system enabled for automatic replicated player-avatar footsteps. A Sound Cue can provide random sample selection/pitch and attenuation; the framework supplies the movement cadence and networking. No Widget Blueprint, Anim Notify or Digimon configuration is required. See `SETUP_PLAYER_FOOTSTEPS.md`.

## World chat extension — v0.10.1

The native gameplay HUD also creates `DMFWorldChatWidget` when **Enable World Chat** is true. It uses a dedicated lower-left WORLD-chat lane while the partner combat quickbar remains centered at the bottom. In v0.10.1 the native chat reserves a `176`-unit bottom safe offset by default, keeping the two persistent HUD surfaces visually separated even in smaller PIE windows. Press **Enter** to focus its input; sending/canceling restores gameplay focus.

The default chat widget is assigned under **UI → World Chat → World Chat Widget Class**. **World Chat Bottom Safe Offset** can be tuned if a project changes the quickbar's size. A Blueprint child can reskin chat without replacing server sanitation, rate limiting, public username stamping, session history or broadcast authority. See `SETUP_WORLD_CHAT.md` for the full optional binding surface and multiplayer acceptance test.

## 2. Digimon portraits — Party, Bank, quick access + starter menu

Open each `DMFDigimonSpeciesData`, for example:

`DA_Species_Agumon -> 3D Presentation -> Portrait`

Assign a square or near-square `Texture2D` portrait/icon. The same existing field is used by:

- the PARTY roster and active-partner profile;
- BANK / BOXES storage cards and selection details;
- the persistent Party Quick Access HUD;
- the starter-selection presentation.


If Portrait is empty, the native UI deliberately displays `PORTRAIT NOT SET` / `ASSIGN PORTRAIT` rather than silently producing an apparently broken blank slot.

Recommended source art: square 512x512 or 1024x1024. The framework does not require that resolution; it is simply a practical UI asset guideline.

## 3. Player skin portraits

Open each `DMFPlayerSkinData`, for example `DA_Skin_Tai`, then assign:

`UI -> Portrait`

That texture is used automatically for the native skin card and selected-character preview. Each skin can still use a completely different Skeletal Mesh, Skeleton and AnimBP.

## 4. Ability icons

Open each `DMFDigimonAbilityData` and assign:

`Identity -> Icon`

The native combat quick bar uses the icon automatically. Missing icons do not affect gameplay; v0.12.1 collapses the unused icon frame automatically so the ability name/SP/cooldown text receives the full card width.

## 5. Digimon Party + Bank / Boxes UI — v0.12

Default input remains:

`I -> Toggle Digimon Menu UI`

The shared native menu now opens with four first-class tabs in visual order: **PARTY**, **BANK / BOXES**, **SCAN & MATERIALIZE**, **CARE**.

**PARTY** renders the active field roster (`MaxPartyDigimon`, six by default) with portrait, species/nickname, level, Active/Summoned/KO state and the existing selected-Digimon profile. `SET ACTIVE / SUMMON`, `RECALL ACTIVE PARTNER`, and `MOVE TO BANK` route through server-owned state. The final Party member cannot be deposited.

**BANK / BOXES** renders persistent account storage in a paged six-column grid (`DigimonBankSlotsPerPage`, 30 by default). Selecting a stored Digimon shows its profile and a live six-slot Party destination strip. If Party has space the server moves it into Party; if Party is full, select an occupied Party destination and **MOVE / SWAP TO PARTY** performs an atomic authoritative swap.

A defeated (`HP <= 0`) Digimon is marked `KO` and cannot be summoned until authoritative healing/revival. Bank access is available anywhere in the gameplay world; no physical storage terminal is required by the framework. See `SETUP_PARTY_BANK_STORAGE.md`.

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

The regular-player destination remains absent from the runtime login UI, but v0.10.2 makes it safely editable by developers under **Project Settings → Digimon MMO Framework → Networking → Server Endpoint**. v0.10.3 likewise exposes **Networking → Admin Hosting → Set Admin Hosting Password**; the editor hashes and clears the setter value so plaintext is not retained in project config. Server authentication remains handled by the existing gated frontend/server flow.

## 9. Party Quick Access HUD — v0.12

The gameplay HUD now includes a compact persistent six-slot Party strip when **Show Native Party Quick Bar** is enabled. It displays Party portraits, names/levels, HP state and the active-partner highlight while remaining hit-test transparent during ordinary gameplay.

Press **Tab** with the default input enabled to enter Party interaction mode. The local cursor appears and gameplay movement/look are temporarily released; healthy Party slots become clickable and the expanded controls provide **RECALL**, **OPEN PARTY** and **OPEN BANK**. Tab again or Escape returns to normal gameplay. All partner changes still use the server-authoritative Party component.

The bar occupies its own configurable HUD safe lane through `Party Quick Bar Bottom Safe Offset` and automatically hides during framework modal UI/Care presentation. Blueprint children can replace `DMFPartyQuickBarWidget` without replacing storage authority.

## 10. Combat quick bar

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

## 11. Blueprint reskinning remains supported

All major native widgets remain `Blueprintable`. You can assign a Blueprint child in Project Settings and replace the visual hierarchy while calling the same server-backed functions/events.

The v0.6 native layout adds new **optional** bindings. Legacy optional bindings remain so existing project Widget Blueprints are not intentionally broken by the polish pass.

## 12. First acceptance test

1. Compile the plugin in UE5.8.1.
2. Open MainMenu and press Play.
3. Confirm the login appears as a centered dark card instead of full-width gray bars.
4. Login and confirm the Play/Admin view replaces the credential form.
5. Complete skin selection and verify assigned skin portraits render.
6. Complete starter selection and verify assigned Digimon portraits render.
7. In gameplay press `I`.
8. Confirm the PARTY page shows the six-slot roster and select a Digimon to inspect its full profile.
9. Open BANK / BOXES and confirm paged account storage plus the Party destination strip render correctly.
10. Move one Digimon Party → Bank → Party, then test a full-Party atomic swap.
11. Close the menu and confirm the Party Quick Access strip and bottom-center combat bar both render without overlap.
12. Press Tab, click a healthy Party slot, then Tab/Escape back to gameplay; repeat in a two-client test and confirm only the owning player sees their private roster/storage while the spawned partner change replicates normally.

## Shared Digimon menu shell — current v0.12 state
The original v0.6 Collection page evolved into the active **PARTY** page while preserving the historical `Collection` enum/API identity for Blueprint compatibility. The native shell now presents **PARTY**, **BANK / BOXES**, **SCAN & MATERIALIZE** and **CARE**. Projects using Blueprint children can mirror the same architecture and drive it with `Set Active Menu Tab`, `Refresh Inventory`, `Refresh Bank Data`, `Refresh Scan Data` and `Refresh Care Data`. Digivolution should extend this same shell later rather than creating a disconnected full-screen menu.


## v0.8.0 CARE page

The native fallback now provides a third first-class page, **CARE**, using the same 1180×720 menu shell, dark raised panels, cyan accent hierarchy and gold secondary emphasis as Collection and Scan. The page shows the active partner portrait/meta, a large Hunger meter, Happiness and Discipline meters, Care Mistakes, unlimited DigiMeat rules, waste/digestion status and the server-backed `FEED DIGIMEAT UNTIL FULL` action.

When feeding is accepted, the widget is intentionally removed rather than left translucent over the world. `ADMFMMOPlayerController` also removes the combat quickbar and restores game input before the first eating Montage. At server completion it recreates the menu and selects `EDMFDigimonMenuTab::Care`, so the player sees the updated Hunger state immediately after watching the animation.

Blueprint children may replace the layout while retaining `RefreshCareData`, `SetActiveMenuTab(Care)` and the owner component care delegates/RPC. Keep gameplay mutation on `UDMFPlayerDigimonComponent`; do not award Hunger from widget Blueprint logic.


## v0.9.0 automatic world nameplates

The polished native UI language now extends into the 3D world through automatic Player and Digimon nameplates. No manual Widget Component is required on framework-derived actors. Configure the master/per-category switches, distance culling and Blueprint widget overrides under **Project Settings → Digimon MMO Framework → UI → World Nameplates**. See `SETUP_WORLD_NAMEPLATES.md` for the complete contract.
