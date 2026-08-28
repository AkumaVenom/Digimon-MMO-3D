# Replicated 12-Hour World Clock HUD — Setup

The v0.16.1 clock is a **local presentation of the authoritative `DMFDayNightSky` clock**. It does not query the client PC and does not replicate a widget/time string.

## Native quick-access presentation

The native `DMFCombatQuickBarWidget` places a compact clock in the header between:

`PARTNER • HP/SP`  |  `12:34 PM • DAY`  |  `TARGET • ...`

The time is always formatted as a 12-hour clock:

- `00:00` world time -> `12:00 AM`
- `09:05` -> `9:05 AM`
- `12:00` -> `12:00 PM`
- `18:30` -> `6:30 PM`

The optional phase label is **DAY** (gold) or **NIGHT** (cyan) and comes from the same replicated Day/Night phase used by the sky/spawners.

While the local client has not yet resolved a valid `DMFDayNightSky`, the native card displays `--:-- --` and `SYNC`. The widget weak-caches the first valid world sky and only retries actor discovery once per second while unresolved.

## Project Settings

Open:

`Project Settings -> Digimon MMO Framework -> UI -> Combat Quick Access -> World Clock`

Settings:

- `Show Combat Quick Bar World Clock` — default **true**.
- `Show Combat Quick Bar World Clock Phase` — default **true**.

Disabling the phase keeps the 12-hour time card but removes the DAY/NIGHT label. Disabling the clock collapses the entire clock card and returns the header space to the existing quickbar layout.

## Blueprint / custom UMG

`DMFDayNightSky` exposes:

- `Get Formatted Time 12 Hour` — canonical `h:mm AM/PM`; pass `Include Seconds=true` for `h:mm:ss AM/PM`.
- `Get Time Of Day Hours` — smooth 0-24 time reconstructed from the replicated server anchor.
- `Get Day Night Phase`, `Is Day`, `Is Night`.

A Blueprint child of `DMFCombatQuickBarWidget` may optionally bind `UTextBlock`s named:

- `WorldClockText`
- `WorldClockPhaseText`

The native widget refresh logic will populate them. A completely custom HUD can instead resolve `DMFDayNightSky` and use the Blueprint-pure calls directly.

## Multiplayer contract

- **Server/host owns world time.**
- Host-PC mode displays the server/host machine's clock through the replicated sky anchor; remote client PC clocks are ignored.
- Simulated mode displays the same persistent accelerated world time used by sky lighting and Day/Night spawner population selection.
- No new clock RPCs or replicated UMG properties are used.
- UI refresh is local-only and reuses the combat quickbar's existing 0.15-second timer.

## Acceptance test

1. Place exactly one valid `DMFDayNightSky` in the gameplay map.
2. Use Simulated mode and temporarily set a short day (for example 60 seconds).
3. Launch listen host + remote client.
4. Confirm both quickbars show the same 12-hour time and transition AM/PM correctly.
5. Confirm the phase label changes at the configured Day/Night boundaries.
6. Confirm the visible sky/light and Day/Night spawner population agree with the HUD phase.
7. Switch to Host-PC mode and confirm the remote client follows the host/server time rather than its own system clock.
8. Disable the phase label, then the entire clock, in Project Settings and confirm the quickbar layout collapses cleanly.
