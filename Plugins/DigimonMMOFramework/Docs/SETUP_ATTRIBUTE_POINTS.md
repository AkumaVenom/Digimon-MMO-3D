# Attribute Point Spending — v0.14.9-alpha

Owned Digimon earn `UnspentAttributePoints` from the existing species `Attribute Points Per Level` value. v0.14.9 adds the authoritative spend side.

## Spendable stats

One point adds exactly **+1** to one of: **Max HP, Max SP, Strength, Intelligence, Defense, Speed**. ABI and CAM are intentionally not spendable through this system.

For Max HP / Max SP, the current value also increases by +1 so the new capacity is immediately usable without erasing damage or SP already spent. A Digimon at 0 HP remains defeated.

## Native UI

Open **Digimon Menu -> Party** or **Bank / Boxes**, select a Digimon, then use the compact `+ HP / + SP / + STR / + INT / + DEF / + SPD` controls under the stat card. Buttons disable when there are no points or the request is otherwise invalid.

The native window uses a 1240x900 logical design canvas inside `ScaleToFit / DownOnly` and clips to its modal bounds, preventing tab/footer content from drawing below the menu on short/DPI-scaled viewports.

## Blueprint API

- `Can Spend Digimon Attribute Point(InstanceId, Stat, FailureReason)` — read-only convenience for button state/tooltips.
- `Server Spend Digimon Attribute Point(InstanceId, Stat)` — authoritative mutation request.
- `On Attribute Point Spend Result` — owner-only acknowledgement with success, message, instance, stat, committed new stat value and remaining points.

Do not mutate `FDMFDigimonInstance::Stats` or `UnspentAttributePoints` on clients.

## Server validation / persistence

The server revalidates instance ownership across Party and Bank, remaining points, supported stat, integer headroom and active Digivolution conflicts. On success it decrements exactly one point, increments exactly one stat, marks the appropriate owner Fast Array item dirty and persists the account immediately.

If the Digimon is the currently summoned partner, `RefreshProgressionFromInstance` updates public replicated stats/vitals in place. The actor is not respawned and combat target/cooldowns/recovery/battle encounter state are not reset.

## Acceptance test

1. Level a Digimon until it has at least 3 Attribute Points.
2. In Party, press `+ STR`; confirm STR +1 and Attribute Points -1.
3. Press `+ HP`; confirm MaxHP +1 and, if alive, CurrentHP +1 while missing HP is preserved.
4. Spend the final point and confirm every `+` button disables at 0.
5. Repeat on a Bank Digimon.
6. Summon a partner, spend a stat, and confirm the public actor/nameplate/combat calculation sees the new stat without respawning.
7. Reconnect and confirm the spent stats and remaining points persist.
8. Two-client test: only the owning player can see/request private spending; the other client sees only the normal replicated public active-partner result.
