# Replicated Persistent Day / Night Sky — Setup

`ADMFDayNightSky` is the framework's shared MMO world clock and optional native sky presentation actor. It is **Blueprint-derivable, authority-owned, replicated and persistent**.

The server/host owns time. Clients never submit clock values. They receive sparse time anchors and interpolate locally, so the sun/material presentation remains smooth without per-frame network traffic.

## 1. Create the project sky Blueprint

1. Create a Blueprint class derived from **`DMFDayNightSky`** (recommended name: `BP_DMFDayNightSky`).
2. Place **one** instance in the gameplay/Open World map.
3. Keep the actor replicated; the native class already enables replication and always-relevancy.
4. Either use the supplied Sun/Moon/SkyLight/SkyAtmosphere/SkyDome components or add project-specific presentation components in the Blueprint.

The Blueprint can read:

- `Get Time Of Day Hours` — smooth local 0-24 clock reconstructed from server time anchors.
- `Get Time Of Day Normalized` — 0-1 day fraction.
- `Get Current Day Index`.
- `Get Day Night Phase`.
- `Is Day` / `Is Night`.
- exposed runtime values `bIsDay` / `bIsNight`.
- `On Day Night Phase Changed`.
- `On Time Synchronized`.
- `BP On Sky Visual Update` for custom local presentation.

### Editor preview (no PIE required)

`Preview Sky In Editor` defaults to **true**. The native actor now runs the same canonical sky presentation path during construction/property edits:

- **Simulated / GTA Style** previews `Initial Simulated Time Hours`.
- **Host PC System Time** previews the editor machine's current local clock whenever the actor is reconstructed/refreshed.
- `DayNightPhase`, `bIsDay` and `bIsNight` are updated for the editor preview as well.
- Sun/Moon rotation and intensity, outer/digital dynamic-material parameters and the optional native SkyLight update immediately.

This editor preview never reads or writes the persistent world-state SaveGame and never creates network authority. It is presentation-only. If a material/mesh asset was changed without causing a property reconstruction, press the actor's **Refresh Sky Presentation** Call-In-Editor button.

At 12:00 the native Sun is overhead; at 06:00/18:00 it is on the horizon; at 00:00 it is below the horizon. This same solar orientation is used in runtime.

## 2. Choose the authoritative clock mode

### Host PC System Time

Set:

`Time Source = Host PC System Time`

The authority machine's **local PC clock** drives the world. On a listen server this is the host player's computer time. On a dedicated server it is the dedicated server machine's local time.

Clients do **not** read their own system clocks. The server publishes a time anchor, and every client interpolates from that same authoritative clock.

The saved simulated clock is intentionally ignored while this mode is active because the authority PC clock is the source of truth.

### Simulated / GTA Style

Set:

`Time Source = Simulated / GTA Style`

Important fields:

- `Initial Simulated Time Hours` — used only when no saved clock exists.
- `Simulated Day Length Seconds` — real seconds for one complete 24-hour game day.
- default `2880` = **48 real minutes per in-game day**, suitable as a GTA-style starting point.
- `Day Start Hour` — default `06:00`.
- `Night Start Hour` — default `18:00`.

The server saves the simulated clock and resumes it after restart/map reload. Offline time does **not** silently advance the simulated clock; it resumes from the last authoritative checkpoint.

For fast editor testing, temporarily use `Simulated Day Length Seconds = 60`.

## 3. Shared world-time persistence

Project Settings exposes:

`Digimon MMO Framework -> Persistence -> World State -> World State Save Slot`

Default:

`DMF_ServerWorldState`

Each sky stores under:

`CurrentMapName | PersistenceId`

so multiple maps can keep independent clocks inside the same server world-state save.

`Persistence Id` defaults to `WorldSky`. Keep it stable after a live world has begun using it.

The sky autosaves in Simulated mode using `Persistence Autosave Interval Seconds` (default `30`) and also checkpoints during EndPlay/map shutdown when possible.

Authority-only Blueprint helpers are available:

- `Save Day Night State Now`
- `Reload Day Night State`
- `Set Simulated Time Of Day`
- `Advance Simulated Time By Hours`
- `Set Authoritative Time Source`

The existing per-account SaveGame schema remains unchanged. Shared world time is deliberately stored in its own server-only world-state save instead of being duplicated into every player account.

## 4. Native sun / moon

`DMFDayNightSky` includes optional movable native:

- `Sun Light`
- `Moon Light`
- `Sky Light`
- `Sky Atmosphere`

Use these presentation gates depending on how much of the native sky you want:

- `Enable Native Sky Atmosphere` — disable when the Blueprint/project supplies its own atmosphere.
- `Enable Native Sky Light` — disable when the Blueprint/project supplies its own skylight/capture solution.
- `Drive Native Directional Lights` — rotate and cross-fade the native sun/moon automatically.

Useful values:

- `Sun Yaw Degrees`
- `Sun Pitch Offset Degrees`
- `Maximum Sun Intensity`
- `Maximum Moon Intensity`
- `Sun Light Color`
- `Moon Light Color`

SkyLight recapture is intentionally **not** forced every visual update. `Recapture Native Sky Light On Phase Change` defaults to true and recaptures only when the authoritative Day/Night phase crosses a boundary; explicit/editor `Refresh Sky Presentation` also performs one one-shot recapture. Continually calling `RecaptureSky` at the 20 Hz visual rate would be expensive. Projects that provide their own real-time/capture solution may disable this option.

## 5. Outer sky dome

The native actor provides an optional `Sky Dome` Static Mesh Component.

Assign:

- `Sky Dome Mesh`
- `Sky Dome Material`
- `Sky Dome Scale`

At runtime the framework creates a Material Instance Dynamic and, when matching parameters exist, updates:

- `DMF_TimeOfDayNormalized` — scalar 0-1
- `DMF_DayVisualAlpha` — scalar twilight-smoothed visual day strength
- `DMF_SunDirection` — vector

The parameter names are exposed and may be renamed to match an existing project material.

### Visible sun-disc compatibility

Many existing Unreal/marketplace sky-sphere materials draw their own visible sun disc instead of relying on the native `SkyAtmosphere` solar disc. Those materials commonly expect the legacy parameters:

- `Light direction` — Directional Light ray-travel/forward vector (sun -> world)
- `Sun height` — solar elevation, where `-1` is midnight/below the world, `0` is the horizon and `+1` is noon/overhead

`Drive Sky Dome Solar Visual Parameters` is enabled by default. Every local sky presentation update pushes the same authoritative/interpolated solar solution used by the native Sun Light into those two parameters on the outer Sky Dome MID. This keeps the **visible material sun**, actual light, editor preview and remote clients synchronized without rotating the sky mesh or spending network bandwidth on material state.

If an existing sky material uses different parameter names, change `Sky Dome Light Direction Parameter Name` and/or `Sky Dome Sun Height Parameter Name` on the placed/derived `DMFDayNightSky`. Set either name to `None` when that parameter is not used. If the sun is literally baked into an opaque texture with no directional/elevation parameter, that baked artwork cannot be repositioned independently; use the native SkyAtmosphere disc or expose one of these material parameters for the solar disc.

The component is optional. A derived Blueprint can ignore it and use the exposed clock to drive Ultra Dynamic Sky, a custom material, volumetric clouds, or another presentation solution while retaining the framework authority/persistence contract.

## 6. Always-visible digital inner sky texture layer

The actor includes a dedicated `Digital Inner Sky Layer` Static Mesh Component. It is designed specifically for a persistent Digimon/digital-world texture overlay that remains visible during **both Day and Night**.

Recommended setup:

1. Reuse `Sky Dome Mesh` or assign `Digital Inner Layer Mesh`.
2. Create a **Translucent, Unlit, Two Sided** material.
3. Add a Texture Sample Parameter 2D named `DMF_InnerLayerTexture`.
4. Multiply its RGB by a Vector Parameter named `DMF_InnerLayerTint` and feed the result to Emissive Color.
5. Multiply the texture **Alpha** by Scalar Parameter `DMF_InnerLayerOpacity` and feed the result to Opacity.
6. Optionally use `DMF_InnerLayerUVScale` and `DMF_InnerLayerUVOffset` to build UV scaling/panning.
7. Assign the material to `Digital Inner Layer Material`.
8. Assign the actual digital texture to `Digital Inner Layer Texture`.

The framework pushes these runtime parameters:

- `DMF_InnerLayerTexture`
- `DMF_InnerLayerOpacity`
- `DMF_InnerLayerTint`
- `DMF_InnerLayerUVScale`
- `DMF_InnerLayerUVOffset`
- plus the shared time/day/sun parameters above.

The layer's mesh is scaled slightly inside the outer dome (`Digital Inner Layer Scale Multiplier`, default `0.995`) to avoid z-fighting. Its component is **not toggled by Day/Night**, so transparent texels continuously reveal the sky behind it exactly as authored by the texture alpha/material.

`Digital Inner Layer Pan Speed` can provide very cheap UV motion without a Blueprint Tick. The offset uses synchronized server-world time so the pattern remains phase-aligned on host and remote clients.

If you change the sky/digital materials or textures at runtime, call `Refresh Sky Presentation`.

## 7. Day / Night wild Digimon population swapping

Every `DMFWildDigimonSpawner` keeps its original population behavior by default:

`Population Schedule Mode = Always / Legacy Spawn Table`

To use time populations, set:

`Population Schedule Mode = Day / Night Population Sets`

Then author:

### Day

- `Day Rarity Weights`
- `Day Spawn Entries`

### Night

- `Night Rarity Weights`
- `Night Spawn Entries`

Both arrays use the **same `FDMFWildSpawnEntry` structure and the same normalized two-stage rarity selection** as the original spawner: choose rarity tier first, then species inside that tier from `Selection Weight Multiplier`.

The server reads the authoritative `DMFDayNightSky` phase. The client never chooses a table or species.

`Day Night Sky Override` may point at a specific placed sky. Leave it unset to auto-discover the world sky. If Day/Night mode is enabled and no sky can be resolved, the server logs one non-spamming setup warning and temporarily uses the configured missing-sky fallback phase.

### Safe phase transitions

When Day becomes Night (or vice versa):

1. old-phase entries stop consuming the new population capacity;
2. old-phase entries stop scheduling replacements;
3. non-engaged old-phase Digimon use the normal polished ground-despawn path;
4. old-phase Digimon already in a battle may finish the encounter when `Keep Engaged Wild Until Combat Ends` is enabled (default);
5. the new phase's target population is rolled/cap-checked and staggered in through the normal population queue.

This avoids abruptly deleting an enemy during a player's active encounter while still swapping the ambient world population promptly.

If a Day or Night array is empty, `Fallback To Legacy Population When Phase Table Empty` defaults to true so the old `Always / Legacy Spawn Entries` table remains a safe fallback.

The active spawner phase is replicated as `Replicated Population Phase` and exposed through `Get Population Phase` plus `BP On Population Phase Changed`.

## 8. Networking/performance contract

- Time source: **server/host authority only**.
- Clock replication: sparse anchor state (default every 2 seconds), not per-frame RPCs.
- Client smoothness: clients interpolate with synchronized `GameState` server world time.
- Sky visual update: local only (default 20 Hz) and does not replicate component transforms/material parameters.
- Simulated clock persistence: server-only world-state SaveGame.
- Host-system clock: server PC only; client system clocks are irrelevant.
- Wild table selection / rarity / species / level / transition: server only.
- Spawned wild Digimon remain ordinary replicated actors.
- No new client-authoritative time or spawn RPC path exists.

## 9. Recommended multiplayer acceptance test

1. Place one `BP_DMFDayNightSky` in Open World.
2. Set Simulated mode and temporarily set `Simulated Day Length Seconds = 60`.
3. Run listen-server PIE + one client.
4. Confirm both windows show the same sun/time and switch Day/Night together.
5. Set one spawner to Day/Night populations with obviously different species arrays.
6. Confirm Day species retire and Night species stagger in at the phase boundary; repeat Night -> Day.
7. Start fighting an old-phase Digimon before the boundary; confirm it remains until combat finishes, then retires.
8. Stop/restart the session and confirm simulated time restores from the world-state save.
9. Switch the sky to Host PC System Time and confirm both host/client follow the host machine clock, not their individual local clocks.
10. Assign a translucent digital inner-layer texture with alpha and confirm the texture remains visible through Day and Night while transparent texels reveal the sky behind it.

## World clock HUD integration (v0.16.1)

The native combat/ability quick-access bar can now display the same authoritative clock as a compact **12-hour digital time** with optional DAY/NIGHT status. It calls the sky's smooth replicated/interpolated time locally; it does not read a client PC clock or add a network timer.

See `SETUP_WORLD_CLOCK_HUD.md` for Project Settings, custom Blueprint bindings and the multiplayer acceptance test.
