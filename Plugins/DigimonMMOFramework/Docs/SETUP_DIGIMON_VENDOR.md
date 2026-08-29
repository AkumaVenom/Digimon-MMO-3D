# Digimon Vendor Economy Setup — v0.18.0-alpha

`DMFDigimonVendorActor` is the framework's placeable, Blueprint-derivable Digimon market NPC. It generates randomized server-owned stock, rotates that stock on its own schedule, sells persistent Digimon individuals to players, buys owned Digimon back for automatic progression-aware prices, and opens the native owner-local BUY / SELL market UI through the existing player interaction system.

## 1. Create the vendor Blueprint

1. Create a Blueprint Class derived from **`DMFDigimonVendorActor`**.
2. Name it, for example, `BP_DigimonVendor_City01`.
3. Assign an NPC skeletal mesh to the inherited **Vendor Mesh** component, or add project presentation components in the Blueprint.
4. Place the Blueprint in the gameplay world.
5. Give each independently configured vendor a stable **Vendor Id** such as `FileIslandExchange` or `ServerCityRookieMarket`.

The native actor is replicated and zero-tick. Its interaction sphere automatically blocks the same configurable trace channel used by the framework player interaction trace. The default interaction prompt is **Open Digimon Vendor**.

## 2. Configure stock for each placed NPC

Under **Digimon MMO | Vendor | Stock**:

- **Stock Slots** — number of simultaneous offers. Default: `6`.
- **Allow Duplicate Species In Stock** — when false, a species can occupy at most one slot per rotation.
- **Refill Sold Slots Immediately** — when false, a purchased offer remains sold out until the next rotation; when true, the server generates a replacement immediately.
- **Species Pool** — weighted list of Species Data Assets this vendor is allowed to offer.
- **Default Generation Range** — randomized progression envelope used by every pool entry without an override.

Each **Species Pool** entry exposes:

- Species Data Asset
- Selection Weight
- Purchase Price Multiplier
- optional per-species Generation Range override

The species weight affects only server stock selection. It does not trust or require any client roll.

### Random generated Digimon values

A generation range exposes:

- Minimum / Maximum Level
- Minimum / Maximum **Natural HP Bonus**
- Minimum / Maximum **Natural SP Bonus**
- Minimum / Maximum **Natural Combat Stat Bonus** (rolled independently for STR/INT/DEF/SPD)
- Minimum / Maximum Spent Attribute Points
- Minimum / Maximum Unspent Attribute Points
- Minimum / Maximum ABI
- Minimum / Maximum CAM
- Minimum / Maximum current-level EXP percentage

The server begins from that species' authored Base Stats, applies its normal per-level HP/SP/STR/INT/DEF/SPD growth to the rolled level, then rolls independent natural stock variance and finally distributes the rolled **spent Attribute Points** across the six trainable stats. Natural variation is intentionally kept separate from `TotalAttributePointsSpent`: it changes the Digimon's real stats/value without falsely claiming the player/vendor invested Attribute Points. This means two offers of the same species and level can still have meaningfully different stat quality.

Generated Digimon are real `FDMFDigimonInstance` records with their own GUID, species, current stats, level/EXP, ABI/CAM, training counters, abilities, care state, origin and Digivolution history seed. Buying an offer transfers that individual into the player's persistent Party/Bank rather than materializing a generic species template later.

## 3. Configure the stock swapper / rotation scheduler

Under **Digimon MMO | Vendor | Stock Rotation**:

- **Rotate Stock Automatically** — default `true`.
- **Minimum Stock Rotation Seconds** — default `900` (15 minutes).
- **Maximum Stock Rotation Seconds** — default `1200` (20 minutes).
- **Initial Stock Rotation Delay Seconds** — optional explicit delay before the first scheduled swap; `0` uses the normal randomized interval after initial stock generation.

Every vendor owns its own server timer and schedule. No vendor Tick is used.

The server replicates:

- the current stock snapshots,
- stock generation serial,
- next rotation server-time endpoint.

The native UI reconstructs the countdown from synchronized server world time. When the timer expires the server replaces the entire stock and clients receive the new offers automatically.

Blueprint authority helpers:

- `Refresh Stock Now`
- `Restart Stock Rotation Schedule`
- `Set Vendor Enabled`
- `Set Buying Enabled`
- `Set Selling Enabled`
- `Set Pricing Settings`

`Set Pricing Settings` refreshes stock so existing immutable purchase offers cannot display a stale price model.

## 4. Automatic market valuation

Every vendor has a fully exposed **Pricing** struct. A price is never supplied by the client.

The automatic market value considers:

- species stage multiplier,
- current Level,
- **Lifetime Battle Experience**,
- MaxHP,
- MaxSP,
- STR,
- INT,
- DEF,
- SPD,
- **ABI**,
- CAM,
- exact **Total Attribute Points Spent**,
- Unspent Attribute Points,
- unique Digivolution forms visited.

ABI has a high default contribution on purpose. A Digimon trained through repeated Digivolution / De-Digivolution progression and ABI growth can therefore become substantially more valuable than a low-level, low-ABI, minimally trained Digimon of the same current species.

The value flow is:

`automatic market value -> vendor Buy markup -> player purchase price`

and:

`automatic market value -> player Sell payout multiplier -> vendor resale quote`

Per-species stock entries can apply a **Purchase Price Multiplier** for scarcity/special offers. Generated stock also enforces a small anti-arbitrage floor so an offer cannot be purchased from that vendor for less than the same pricing profile would immediately pay to buy it back.

Blueprint quote calls:

- `Calculate Digimon Value`
- `Get Player Sell Price`

`Calculate Digimon Value` returns `FDMFDigimonVendorValueBreakdown`, including market value and each progression/value contribution.

## 5. Lifetime battle EXP and exact Attribute Point investment

v0.18.0 advances account persistence from schema **v6 to v7** with two additive `FDMFDigimonInstance` fields:

- `LifetimeBattleExperience`
- `TotalAttributePointsSpent`

Every positive authoritative EXP reward contributes to lifetime battle EXP, including rewards earned after reaching the configured level cap. Every successful +1 Attribute Point spend increments the exact training counter.

Both values belong to the persistent individual and survive Digivolution / De-Digivolution alongside the existing instance GUID, ABI, CAM, current level/EXP and Digivolution provenance.

Older v6 accounts migrate automatically. The server conservatively reconstructs historical EXP from the individual's current level/current EXP and estimates already-spent Attribute Points from level-earned points minus currently unspent points. The account then records `DigimonEconomyProvenanceVersion = 1`, so this legacy inference is one-way and can never be re-applied to a new high-level Digimon that legitimately has zero spent Attribute Points. No existing Digimon or stats are discarded.

## 6. Buying behavior

The native BUY tab displays the replicated shared stock.

When the player confirms a purchase, the client submits only:

- vendor actor,
- transaction type = Buy,
- server-created Stock GUID.

The server then revalidates:

- vendor validity/enabled state,
- buying enabled,
- interaction range,
- stock still exists,
- current authoritative price,
- player's authoritative Bits,
- Party/Bank capacity,
- Party mutation locks such as Care/Digivolution/combat policy.

If accepted, the server:

1. reserves/removes the globally shared Stock GUID before any account-side delegate can re-enter the transaction,
2. revalidates and deducts authoritative Bits,
3. copies the exact generated persistent individual,
4. places it in Party or Bank,
5. persists the account immediately,
6. restores the same immutable offer if the account commit fails, otherwise optionally refills the sold slot,
7. replicates the resulting stock and owner-private account changes.

**Prefer Purchased Digimon To Bank** controls the preferred destination. If that destination is full but the other has room, the server safely falls back to the available storage.

## 7. Selling behavior

The SELL tab combines the owning player's Party and Bank and calculates a live quote for each individual.

By default:

- starter partners cannot be sold,
- the player must keep at least one Party Digimon,
- normal Party mutation locks still apply.

A sale request contains only the owned Digimon's Instance GUID. The server resolves that individual again, recalculates its current value, validates the sale policy, removes the exact individual, credits Bits and persists immediately.

If the sold Digimon was the active partner, the existing Party reconciliation contract safely removes/replaces the active partner and re-establishes the correct summoned state.

The vendor does **not** automatically add player-sold Digimon to its curated rotating stock. This keeps each placed NPC's configured species pool deterministic and avoids leaking private collection data into public vendor inventory.

## 8. Native BUY / SELL UI

Interacting with the vendor opens `DMFDigimonVendorWidget` by default. It is a native fallback UI and can be replaced per vendor through **Vendor Widget Class**.

The native window includes:

- vendor display name and subtitle,
- current Bits,
- synchronized next-stock countdown,
- BUY / SELL tabs,
- scrollable offers / Party + Bank collection,
- portrait,
- level,
- stage,
- attribute,
- HP/SP/STR/INT/DEF/SPD,
- ABI / CAM,
- spent and unspent Attribute Points,
- Lifetime Battle EXP,
- Digivolution forms visited,
- market-value breakdown,
- exact Buy/Sell price,
- status/rejection feedback,
- two-step financial/destructive confirmation,
- close action.

The vendor UI is owner-local and modal. Combat ability input, Party Quick Access and normal quick bars cannot compete with it.

## 9. Blueprint presentation hooks

Use these events on a derived vendor Blueprint for project presentation:

- `BP On Stock Refreshed`
- `BP On Vendor Enabled Changed`
- `BP On Vendor Trade Completed`

`BP On Vendor Trade Completed` receives the authoritative player controller, Buy/Sell direction, exact Digimon instance snapshot and committed price. This is the recommended hook for vendor voice lines, animations, sounds or replicated project VFX.

Native delegates also expose stock/configuration/enabled/trade changes.

## 10. Multiplayer authority contract

Public/shared:

- vendor actor presence,
- enabled/trade-policy state,
- relevant pricing configuration,
- current stock,
- next rotation endpoint.

Owner-private:

- Party,
- Bank,
- Money/Bits,
- transaction result UI.

Server-only decisions:

- stock generation/randomization,
- stock rotation,
- final Buy/Sell validation,
- price calculation,
- money mutation,
- ownership mutation,
- persistence.

The client never submits a price, generated Digimon stats, money value, storage result or sale payout. v0.18.0 adds exactly one Server transaction RPC and one owner-only Client result RPC.

## 11. Recommended first runtime test

For a fast PIE acceptance test:

1. Create `BP_DigimonVendor_Test` derived from `DMFDigimonVendorActor`.
2. Add Agumon and Gabumon Species Data Assets to **Species Pool**.
3. Set **Stock Slots = 4**.
4. Set Level range to `1-10`.
5. Set ABI range to something obvious such as `0-50`.
6. Set Spent Attribute Points to `0-20`.
7. Temporarily set rotation to `30-45 seconds`.
8. Place the NPC near the test spawn.
9. Give the account enough Bits using the project's normal admin/test path.
10. Run listen server + remote client.

Verify:

- both peers see the same stock,
- entries vary in level/stats/ABI,
- stock swaps on the server schedule,
- one player buying an offer removes it for the other,
- purchase price comes from the offer and Bits decrease once,
- the purchased individual appears in Party/Bank and survives reconnect,
- a trained high-level/high-ABI Digimon sells for visibly more than a weak low-level one,
- starter/last-Party protection rejects safely,
- selling an active partner reconciles the active Party correctly,
- host/client cannot transact out of range,
- spam/double-click requests cannot duplicate stock or money,
- all account changes survive reconnect.

Until that UE5.8 host/client runtime test succeeds, v0.18.0 should be treated as a candidate rather than the accepted baseline.
