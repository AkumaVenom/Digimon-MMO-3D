# Replicated Item Vendor Exchange Setup — v0.21.0-alpha

## 1. What v0.21.0 provides

`ADMFItemVendorActor` is the Blueprint-derivable item-shop counterpart to the existing Digimon Vendor. A placed vendor exposes one server-owned rotating stock pool, a polished native **BUY / SELL** exchange, quantity selection, BITS pricing, complete inventory-capacity checks and immediate account persistence.

The vendor is intentionally MMO-first:

- stock generation, rotation, depletion, price calculation and transaction validation happen only on authority;
- `ReplicatedStock` is shared replicated vendor state, so all clients relevant to the same vendor converge on the same offer IDs, items, unit prices and remaining quantities;
- a client never rolls its own stock and never submits a trusted price, restore amount, stack size or BITS delta;
- each player's item bag and BITS remain the existing owner-only account state;
- the actor has **no Tick**. Rotation uses one sparse server timer; the native countdown uses a one-second local presentation timer only while the shop UI is open.

Account SaveGame remains **schema v9**. The framework RPC declaration count becomes **57**: the accepted v0.20.0 set plus one reliable item-vendor Server request and one owner Client result RPC.

## 2. Author item economy values

Open each `DMFItemData` that should participate in item commerce and set its existing **Economy** values:

- **Suggested Buy Price** — canonical base price used when this item is rolled into vendor stock. A value `<= 0` keeps the item out of BUY stock.
- **Suggested Sell Price** — canonical base payout used when a player sells the item. A value `<= 0` makes the item non-sellable even when it is otherwise eligible.

`KeyItem` and `Quest` categories are always protected from selling. This is enforced both by the vendor and again by the authoritative player-inventory transaction, so a stale/custom client cannot bypass the rule.

Example starting values for the six recovery capsules may be tuned to your economy rather than hard-coded in C++:

| Item | Suggested Buy | Suggested Sell |
| --- | ---: | ---: |
| Small HP Capsule | 100 | 50 |
| Medium HP Capsule | 400 | 200 |
| Large HP Capsule | 1200 | 600 |
| Small SP Capsule | 100 | 50 |
| Medium SP Capsule | 400 | 200 |
| Large SP Capsule | 1200 | 600 |

These are only a tuning example. The authoritative shop reads the Data Assets at runtime.

## 3. Create a Blueprint vendor

In the Content Browser:

1. Choose **Blueprint Class**.
2. Expand **All Classes**.
3. Select **DMFItemVendorActor**.
4. Name it, for example, `BP_ItemVendor_Supplies`.
5. Open the Blueprint and configure the inherited Details panel.

Recommended identity/presentation fields:

- **Vendor Id** — stable designer-facing identifier, e.g. `SuppliesVendor`.
- **Vendor Display Name** — e.g. `SUPPLY EXCHANGE`.
- **Vendor Subtitle** — descriptive text shown by the native shop.
- **Interaction Prompt** — e.g. `Open Supply Vendor`.
- **Vendor Mesh** — assign the skeletal mesh/presentation used by your shop NPC.
- **Interaction Radius** — authoritative maximum transaction range.
- **Interaction Collision Radius / Trace Channel** — local interaction targeting shell.

Leave **Vendor Widget Class** blank/default to use the framework's polished native item-exchange widget. A Blueprint child of `DMFItemVendorWidget` may be assigned later for a project-specific skin without replacing transaction authority.

## 4. Build the rotating Stock Pool

Under **Item Vendor → Stock**, add entries to **Stock Pool**. Each entry contains:

- **Item** — soft reference to a `DMFItemData` Primary Asset;
- **Selection Weight** — relative chance for that item to be chosen;
- **Purchase Price Multiplier** — per-vendor/per-entry adjustment over the Data Asset buy price;
- **Minimum Stock Quantity / Maximum Stock Quantity** — shared quantity rolled for that offer.

For the first test, add all six HP/SP capsule Data Assets.

Useful vendor-level options:

- **Stock Slots** — how many offers are generated, `1–64`;
- **Allow Duplicate Items In Stock** — normally leave disabled so one item does not occupy several shop rows;
- **Refill Depleted Slots Immediately** — when enabled, a sold-out slot is replaced immediately; otherwise it stays absent until the next full rotation.

If `Stock Slots` exceeds the number of valid unique weighted pool items while duplicates are disabled, the server simply produces as many unique valid offers as possible.

## 5. Configure synchronized stock rotation

Under **Item Vendor → Stock Rotation**:

- enable **Rotate Stock Automatically**;
- set **Minimum Stock Rotation Seconds**;
- set **Maximum Stock Rotation Seconds**;
- optionally set **Initial Stock Rotation Delay Seconds**.

At runtime the server chooses the rotation interval and publishes **Next Stock Rotation Server Time Seconds**. The UI derives the countdown from replicated GameState server time.

### Shared multiplayer contract

The server is the only machine that calls the stock generator. `ReplicatedStock`, `StockGenerationSerial` and `NextStockRotationServerTimeSeconds` replicate from that vendor actor. Therefore:

- host and clients see the same rolled item list;
- the same `StockId` identifies each live offer on every connection;
- if one player buys five units, the server subtracts five from the shared offer and that new quantity replicates to everyone;
- if the offer reaches zero, it disappears for everyone (or the server refills it when configured);
- when the timer rotates stock, all clients receive the new authoritative list;
- late joiners / newly relevant clients receive the vendor's current stock instead of generating their own roll.

The vendor intentionally uses normal Unreal actor relevancy rather than `bAlwaysRelevant`, so vendors elsewhere in a large MMO world do not consume global bandwidth. Once the actor is relevant to a connection, that connection receives the same authoritative shared state.

## 6. Pricing controls

Under **Item Vendor → Pricing**:

- **Player Buy Price Multiplier** applies to every BUY offer at this vendor;
- **Player Sell Payout Multiplier** applies to eligible player sales;
- **Minimum Unit Price** provides the minimum positive quote.

BUY unit price:

`SuggestedBuyPrice × PlayerBuyPriceMultiplier × PoolEntry.PurchasePriceMultiplier`

SELL unit payout:

`SuggestedSellPrice × PlayerSellPayoutMultiplier`

The client displays replicated/server-resolved values, but final totals are always recalculated on the authoritative server using overflow-safe integer math.

## 7. BUY flow and stack handling

Interact with the placed actor to open **ITEM EXCHANGE → BUY**.

The native panel exposes:

- current BITS;
- synchronized stock-rotation countdown;
- item name/category/icon/description;
- shared stock remaining;
- owned quantity;
- max stack size and additional bag capacity;
- unit price and transaction total;
- quantity controls `-10 / -1 / +1 / +10 / MAX`;
- local two-step confirmation before the financial transaction is sent.

`MAX` is clamped to the smallest of:

1. shared vendor stock;
2. quantity affordable by current BITS;
3. the player's remaining capacity for that item.

A purchase is all-or-nothing. The server preflights the **entire** requested quantity before charging BITS. Existing partial stacks are filled first, then additional stacks are created automatically up to `DMFItemData::MaxStackSize`.

Example: an item has Max Stack Size `99`, the player owns `90`, and buys `120`. The authoritative result is `99 + 99 + 12` across stacks (assuming enough bag slots). The user does not need to buy one stack at a time.

If the complete quantity cannot fit, the purchase fails and no BITS are removed. A stale client can never force an over-capacity partial purchase.

## 8. Shared stock concurrency

BUY requests identify a replicated **StockId + quantity**, not a client-authored item or price. The server re-resolves the current offer and reserves/decrements its shared quantity before committing the player's account transaction.

This matters when two players attempt to buy the final units at nearly the same time: authority serializes both requests on the game thread. The first valid reservation wins; a later request that exceeds the now-current quantity is rejected rather than duplicating stock.

If the account transaction itself rejects (for example, insufficient BITS or capacity changed), the server restores the reserved offer before completing the failed request.

## 9. SELL flow

Open **ITEM EXCHANGE → SELL**. The native shop aggregates multiple stacks of the same item into one readable row and shows the player's total owned quantity.

Eligible items may be sold in any quantity up to the total owned amount. The authoritative transaction removes the requested quantity across matching stacks, credits BITS once and persists once.

Protection rules:

- `KeyItem` — never sellable;
- `Quest` — never sellable;
- `SuggestedSellPrice <= 0` — no vendor sell value;
- when **Require Item In Stock Pool To Sell** is enabled, only items contained in this vendor's authored pool are accepted.

Key/Quest items remain visible in the SELL list as **PROTECTED** so the player understands why they cannot transact; the server independently enforces the same denial.

## 10. Blueprint runtime controls and hooks

`DMFItemVendorActor` exposes authority-only Blueprint controls for live events/admin/world systems:

- `Set Vendor Enabled`;
- `Set Buying Enabled`;
- `Set Selling Enabled`;
- `Set Pricing Settings`;
- `Refresh Stock Now`;
- `Restart Stock Rotation Schedule`.

Useful events/delegates include stock refreshed, vendor enabled/configuration changed and successful trade completed. Use these for presentation, quest hooks or world-event orchestration; do not duplicate BITS/inventory mutation in Blueprint.

## 11. Required multiplayer acceptance

Before promoting v0.21.0-alpha, run at least a listen-server host + one client with two authenticated accounts:

1. Both players approach the **same** item vendor and confirm item IDs, prices and shared quantities match exactly.
2. Wait for an automatic rotation and confirm both UIs switch to the same new stock and countdown source.
3. Buy from one client and confirm remaining quantity changes for the other client without reopening the vendor.
4. Attempt to buy the final stock concurrently; total purchases must never exceed server stock.
5. Buy more than one `MaxStackSize` and confirm partial stacks fill then additional stacks are created correctly.
6. Fill the player's item inventory and confirm an over-capacity purchase is rejected with no BITS loss and no partial grant.
7. Sell quantities spanning multiple stacks and confirm exact removal, BITS payout and relog persistence.
8. Confirm Key Items and Quest Items cannot be sold, including through a stale/custom transaction request.
9. Confirm a player moved outside `InteractionRadius` cannot complete a transaction from an already-open/stale UI.
10. Confirm each player's bag and BITS remain owner-only while the vendor's shared stock remains visible/consistent to both players.
11. Reconnect and verify purchased/sold account inventory and BITS persist under existing schema v9.
12. Re-run the accepted v0.20.0 capsule, summoned-partner restoration and inventory-privacy regressions.

