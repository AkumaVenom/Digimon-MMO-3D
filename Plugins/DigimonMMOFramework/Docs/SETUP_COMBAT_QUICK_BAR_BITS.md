# Combat Quick Bar BITS HUD — UE5.8

## Purpose

v0.19.3-alpha adds the authenticated player's current **BITS** balance to the persistent native combat ability quick-access HUD. It is a presentation extension of the existing economy state, not a new currency system.

The native header reads:

`BITS  1,234`

using the same **BITS** terminology and locale-aware integer formatting as the Digimon Exchange.

## Default behavior

No gameplay setup is required. The feature is enabled by default.

Open:

**Project Settings → Game → Digimon MMO Framework → UI → Combat Quick Access → Economy**

and leave:

**Show Combat Quick Bar Bits = True**

Disable that setting only if the project supplies its own currency presentation. Disabling the HUD text does not disable, reset or otherwise alter the economy.

## Authority and replication

The displayed value comes directly from:

`UDMFPlayerDigimonComponent::GetMoney()`

`Money` is already replicated with `COND_OwnerOnly`. The server remains authoritative for every mutation that changes it, including vendor purchases/sales and battle rewards. The quickbar therefore does not:

- send a currency RPC;
- replicate a second balance;
- accept a client-authored amount;
- change account SaveGame data;
- expose one player's private balance to other clients.

The existing combat quickbar local presentation refresh updates the text from that owner-only replicated state, so vendor/economy changes appear automatically. The balance is account information and remains visible even when the active partner is not summoned.

## Native layout

The BITS readout is a compact 150×28 header capsule using the framework's existing dark-blue panel surface and gold economy text. It sits after the flexible partner-vitals lane and before the world-clock/target cluster, leaving the four ability cards untouched. A down-only `ScaleBox` protects the fixed capsule from pathological very-large balances without enlarging or overlapping the header.

## Blueprint reskinning

`UDMFCombatQuickBarWidget` now exposes an optional `BindWidgetOptional` field:

`BitsText`

A Blueprint child can bind a `TextBlock` with that exact name. The framework writes the canonical formatted BITS text into it during refresh. If the Project Settings visibility toggle is disabled, the optional bound text is collapsed.

Projects may fully reskin the widget while retaining the same owner-only economy authority.

## Multiplayer acceptance test

1. Start a listen server and one remote client with separate authenticated accounts.
2. Confirm each quickbar shows only that account's own BITS balance.
3. Recall the active Digimon and confirm BITS remains visible while partner vitals change to `NOT SUMMONED`.
4. On one account, perform a server-authoritative economy mutation (for example a Digimon Exchange purchase/sale or battle reward).
5. Confirm that account's HUD updates to the new BITS value.
6. Confirm the other client does not receive or display the first account's balance.
7. Open Project Settings, disable **Show Combat Quick Bar Bits**, rerun PIE and confirm only the BITS presentation is hidden while economy operations still work.
8. Re-enable the setting for the standard framework presentation.

## Regression contract

This feature adds no RPCs and no SaveGame schema changes. v0.19.2 Social/Ignore, v0.19.1 nearby-player discovery/Guilds, v0.18.5 presence chat, v0.18.4 capacity, v0.18.3 vendor UI, v0.18.2 reconnect/persistence, Party/Bank privacy, combat, Day/Night and all other accepted runtime contracts remain unchanged.
