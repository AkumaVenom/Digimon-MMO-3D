# Party, Digimon Bank / Boxes & Party Quick Access

**Introduced:** v0.12.0-alpha  
**UI layout hardening:** v0.12.1-alpha  
**Runtime model:** server-authoritative, owner-only replicated, account-persistent

## Overview

v0.12 formalizes the framework's owned Digimon roster into two storage tiers:

- **Party** — the active field roster, six Digimon by default and never more than six.
- **Digimon Bank / Boxes** — persistent account storage, 200 slots by default, accessible from the Digimon Menu anywhere in the gameplay world.

As of v0.13, the shared native Digimon Menu exposes **PARTY**, **BANK / BOXES**, **SCAN & MATERIALIZE**, **DIGIVOLUTION**, and **CARE** as first-class tabs. The Bank follows the same convenience goal as modern creature-box systems: players can open it from the world without travelling to a physical terminal, inspect stored Digimon, and move/swap them with Party.

All ownership and storage mutations are validated by the authoritative server. The client UI never directly edits the Party or Bank arrays.

## Project Settings

Open:

`Project Settings -> Game -> Digimon MMO Framework`

### Party & Bank -> Party

- **Max Party Digimon** — default `6`, clamped to `1-6`.

### Party & Bank -> Bank

- **Max Digimon Bank Storage** — default `200`.
- **Digimon Bank Slots Per Page** — default `30`; the native Bank renders six columns and pages through the account storage.

Existing saves larger than a newly configured capacity are **not truncated**. Capacity limits prevent new deposits/materializations until the account is back inside the configured limit.

### Party & Bank -> Rules

- **Allow Party Switching During Combat** — default `false`.

With the default policy, server-side Party/Bank transfers and selecting a different active Party partner are rejected while the active partner is Chasing, Attacking, or Recovering. This prevents storage UI from becoming a combat-state exploit. Projects intentionally designed around mid-battle switching may enable the setting.

## Native Party tab

The Party page shows the active six-slot field roster with:

- portrait and level cards;
- ACTIVE / SUMMONED / KO state badges;
- selected Digimon identity, Stage, Attribute, HP/SP and core stats;
- **SET ACTIVE / SUMMON**;
- **RECALL ACTIVE PARTNER**;
- **MOVE TO BANK**.

The final Party member cannot be deposited. This maintains a valid field roster and preserves the starter/account flow.

## Native Bank / Boxes tab

> **v0.12.1 layout note:** the six-column Box grid now lives inside a dedicated scroll region while every card retains its fixed native size. Increasing `DigimonBankSlotsPerPage` therefore adds scrollable rows instead of vertically squashing the cards. The Party Destination strip stays pinned below the Box grid, and selected-Digimon guidance scrolls above the fixed action footer.

The Bank page contains:

- paged Box navigation;
- compact portrait cards with level and KO presentation;
- Bank used/capacity count;
- selected Digimon identity and stats;
- a live six-slot **Party Destination** strip;
- **MOVE / SWAP TO PARTY**.

When Party has free capacity, a Bank Digimon can be appended automatically without selecting a destination. When Party is full, the player selects one of the six Party destination slots. The server performs an **atomic swap**: the selected Bank Digimon enters Party and the outgoing Party Digimon returns to Bank in the same authoritative transaction.

If the outgoing slot is the active partner, the incoming Digimon becomes the active partner. A currently summoned active partner is refreshed safely to match the new authoritative active instance.

## Materialization integration

Scan & Materialization now understands both storage tiers:

1. If Party has room, the newly materialized Digimon enters Party.
2. If Party is full but Bank has room, it is sent automatically to Bank.
3. Materialization is rejected only when **both Party and Bank are full**.

Owned-species counts include both Party and Bank.

## Save migration from v0.11 and earlier

Save schema is now **v4**.

Older accounts used `DigimonInventory` as the complete active collection. On authoritative account initialization, v0.12 migrates safely:

1. the previous active partner is guaranteed to remain in Party; it is promoted only when an oversized legacy collection would otherwise place it outside the new Party capacity;
2. current six-slot Party saves preserve their saved order, while remaining legacy collection Digimon fill Party in their previous order up to the configured Party capacity;
3. overflow moves into the existing persistent `DigimonBank` storage;
4. existing Bank entries are preserved and de-duplicated by instance GUID;
5. no valid owned Digimon is intentionally discarded.

`DigimonInventory` remains the serialized field name for compatibility, but from schema v4 onward its runtime meaning is the active **Party**.

## Party Quick Access HUD

The gameplay HUD includes a persistent six-slot Party strip when enabled. v0.12.1 gives every quick slot compact card padding and stacks the portrait above a two-line state/name/level label so the six cards remain readable instead of squeezing text beside the portrait.

Project Settings:

`UI -> Party Quick Access`

- **Party Quick Bar Widget Class** — Blueprint-replaceable presentation class.
- **Show Native Party Quick Bar** — master visibility switch.
- **Enable Default Party Quick Access Input** — enables the built-in Tab/Escape flow.
- **Party Quick Bar Bottom Safe Offset** — vertical HUD safe-lane offset.

### Default interaction

- During normal gameplay the Party bar is visible but hit-test transparent.
- Press **Tab** to enter Party interaction mode.
- The mouse cursor appears; camera look and movement are temporarily released from gameplay input.
- Click a healthy Party slot to make that Digimon active and summon it.
- Use **RECALL**, **OPEN PARTY**, or **OPEN BANK** directly from the expanded bar.
- Press **Tab** again or **Escape** to return to normal gameplay.

Partner switching still calls `ServerSetActivePartner`; the HUD does not bypass server authority.

The Party quick bar automatically hides during framework modal UI and Care eating presentation, then restores afterwards. It reads only the owning player's owner-only Party state.

## Blueprint API

`UDMFPlayerDigimonComponent` exposes:

- `GetPartyDigimon`
- `GetBankDigimon`
- `GetOwnedDigimonByInstanceId`
- `GetPartyCapacity`
- `GetBankCapacity`
- `ServerMoveBankDigimonToParty`
- `ServerMovePartyDigimonToBank`
- `ServerSwapPartySlots`
- `OnDigimonBankChanged`
- `OnDigimonStorageActionResult`

`GetDigimonInventory` remains as a backward-compatible alias for `GetPartyDigimon`.

`ADMFMMOPlayerController` exposes:

- `OpenPartyUI`
- `OpenBankUI`
- `RefreshPartyQuickBar`
- `OpenPartyQuickAccessInteraction`
- `ClosePartyQuickAccessInteraction`
- `TogglePartyQuickAccessInteraction`

## Multiplayer acceptance test

Use one listen host plus at least one remote client.

1. Log in with separate accounts.
2. Confirm each account sees only its own Party/Bank contents.
3. Open Bank from the world without interacting with a physical terminal.
4. Move a non-active Party Digimon to Bank; verify owner UI updates and persists after relog.
5. Move the Bank Digimon back while Party has a free slot.
6. Fill Party to six, select a Bank Digimon, choose an occupied Party destination, and perform a swap.
7. Repeat the swap using the currently active/summoned Party slot and confirm the partner actor refreshes to the incoming Digimon.
8. Enter combat and confirm Party/Bank mutation is rejected while the default combat lock is enabled.
9. Materialize with a non-full Party and verify Party placement.
10. Materialize with a full Party and free Bank and verify automatic Bank placement.
11. Press Tab on each client independently; confirm only that local player's cursor/input mode changes.
12. Click a Party slot in the Quick Access HUD and confirm the authoritative partner switch is reflected on the other client through the normal replicated partner actor.
13. Restart the host/account and confirm Party order, Bank contents, active partner and all pre-v0.12 persistent systems remain intact.

## Networking contract

Party and Bank contents are private account progression and replicate with `COND_OwnerOnly`. Other players learn only the public world state they need—such as the currently summoned replicated partner—not another account's complete storage roster.

Storage RPCs are reliable because they mutate durable account state. The server validates ownership, source location, capacities, combat/Care locks and destination indices before changing anything, then persists the account.

## v0.13 Digivolution integration

The Party/Bank storage model is also the ownership source used by Digivolution. The native **DIGIVOLUTION** page can select an owned Digimon from either Party or Bank without creating another inventory or moving the individual into a temporary container.

- Party Digimon evolve in place and retain their Party slot and persistent instance GUID.
- Bank Digimon evolve in place when both **Project Settings → Digivolution → Allow Bank Digivolution** and that species path's **Allow From Bank** rule permit it.
- A summoned active partner uses the replicated world transformation sequence; its Party instance is committed only by the server and the public world actor is then replaced with the target form.
- Party/Bank move/swap commands are rejected while that account has an active world Digivolution sequence, preventing concurrent durable mutations.
- SaveGame schema v5 preserves the v0.12 Party/Bank layout and adds per-instance Digivolution provenance/history; upgrading does not rebuild or flatten the storage tiers.

See `SETUP_DIGIVOLUTION.md` for path authoring, requirements, presentation and the multiplayer acceptance matrix.
