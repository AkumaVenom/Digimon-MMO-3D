# Scan Data & Materialization Setup — v0.7.1-alpha

## Goal
The native framework now supports the complete account-persistent loop: **defeat eligible Wild Digimon -> earn species Scan Data -> reach threshold -> materialize a unique permanent Digimon -> place it into Party or Bank -> manage/summon it from the Digimon Menu**. All mutations are server-authoritative.

## 1. Global project settings
Open **Project Settings -> Digimon MMO Framework -> Scan & Materialization**. Recommended defaults:

- `Enable Scan And Materialization = true`
- `Award Scan Data From Wild Victories Only = true`

Under **UI**:

- `Show Native Scan Notifications = true`
- `Scan Notification Widget Class = DMFScanNotificationWidget` (native fallback is automatic)

The existing `I` key opens the shared Digimon menu. For a custom button/key call `Open Scan Materialize UI` on `DMFMMOPlayerController`.

## 2. Configure every scannable Species Data Asset
For `DA_Species_Gabumon` (and each species), open **Scan & Materialization** and set:

- `Scan Data Enabled = true`
- `Battle Scan Percent Reward = 20`
- `Scan Percent Cap = 100`
- `Materialization Enabled = true`
- `Materialization Required Scan Percent = 100`

That produces five eligible victories: 20 -> 40 -> 60 -> 80 -> 100.

You may use different values per species. Examples: Rare = 10%, Legendary = 5%, special boss = 2%. A cap above the requirement banks multiple captures; e.g. cap 200 / requirement 100 allows two materializations.

## 3. Partner World Actor Class is mandatory
`DMFDigimonSpeciesData -> 3D Presentation -> World Actor Class` must reference the **partner** Blueprint, for example `BP_Digimon_Gabumon`, derived from `DMFDigimonCharacter`. Do not assign `BP_Wild_Gabumon` / `DMFWildDigimonCharacter`. The server rejects a Wild class during materialization.

## 4. Portraits
`DMFDigimonSpeciesData -> Portrait` drives:

- Scan Database card icon
- selected Materialization Terminal portrait
- Scan reward toast portrait
- Party/Bank portrait cards (current v0.12 behavior; evolved from the v0.6 Collection UI)

## 5. Runtime flow
1. Target and defeat an eligible Wild Digimon.
2. Server awards the configured Scan percentage to the owning account.
3. A native Scan toast appears with the species, `+X%`, new total and progress bar.
4. At threshold it displays `MATERIALIZATION READY`.
5. Press `I`, choose `SCAN & MATERIALIZE`.
6. Select the species card.
7. Review progress, cap, reward, owned count and current Party/Bank capacity.
8. Press `MATERIALIZE DIGIMON`.
9. Server validates the request, creates a unique owned Digimon, consumes the configured requirement and saves immediately.
10. If Party has room the new Digimon is placed into Party; otherwise it is routed to Bank automatically. Materialization rejects only when neither storage tier has legal capacity.
11. Use the PARTY / BANK / BOXES UI to select, move or summon it normally.

## 6. Persistence and multiplayer
Scan Data is copied to/from `FDMFAccountRecord::ScanData`, replicated `COND_OwnerOnly`, and saved with the same account persistence path as Party/Bank/Money. One player cannot see or materialize another player's scan progress. The server performs every reward and materialization mutation.

## 7. Blueprint API
`DMFPlayerDigimonComponent` exposes:

- `Get Scan Data Entries`
- `Get Scan Percent`
- `Is Species Ready To Materialize`
- `Get Owned Species Count`
- `Server Materialize Digimon`
- `On Scan Data Changed`
- `On Scan Data Reward Granted`
- `On Materialization Result`

`DMFDigimonInventoryWidget` exposes:

- `Refresh Inventory`
- `Refresh Scan Data`
- `Set Active Menu Tab`
- `Get Active Menu Tab`

`DMFMMOPlayerController` exposes:

- `Open Scan Materialize UI`
- `Open Digimon Menu UI`
- `Close Digimon Menu UI`
- `Toggle Digimon Menu UI`

## 8. Acceptance test
Use one Wild Gabumon with reward 20 / cap 100 / requirement 100. Defeat five separate eligible Gabumon and verify the owner sees 20, 40, 60, 80, 100. Materialize once and verify Scan returns to 0, the Gabumon remains listed in the Scan Database, one new unique Gabumon appears in Party when space exists and can be summoned normally. Then fill Party, materialize again, and verify the new instance routes to Bank. Reconnect and verify both the 0% scan record and materialized Digimon persist. Then repeat with host + remote client and confirm only the player whose partner earned the victory receives Scan Data.
