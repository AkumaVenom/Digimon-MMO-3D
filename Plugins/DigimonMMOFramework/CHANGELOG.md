# Changelog

## 0.18.2-alpha — Authenticated Reconnect Persistent Account Authority Fix

### Fixed — remote client reconnect could replace a good persisted account with stale inactive PlayerState state
- Root-caused the remaining Shipping/internet reconnect loop: v0.18.1 was already committing the remote account to the host save database, but `AGameMode` could duplicate the disconnecting `PlayerState` into `InactivePlayerArray` and later reassociate that stale in-memory state when the same client rejoined the still-running host. Restarting the host cleared that engine cache, explaining why the same disk save then loaded correctly.
- DMF now overrides `AddInactivePlayer` and intentionally does not create an inactive PlayerState duplicate. The authenticated account database, not Unreal's reconnect cache, is the sole reconnect authority.
- DMF overrides `FindInactivePlayer` to always return false, preventing `PostLogin` from replacing the newly authenticated/initialized PlayerState with stale teardown state.
- Added a post-login integrity rehydrate check: if the active DMF PlayerState somehow reaches PostLogin without an initialized authoritative Digimon account state, the server reloads Party/Bank/avatar state from the authenticated persistent account rather than accepting empty defaults.
- Retains v0.18.1's idempotent save-before-teardown transaction, initialization guard, guarded fallback retry and explicit summoned-partner cleanup.

### Compatibility / persistence
- Account SaveGame schema remains **v7**; no account reset or migration is required.
- RPC count remains **49**; no client-authored persistence or reconnect payload was added.
- Vendor economy, swimming, underwater presentation, Day/Night, Digivolution, ABI, Party/Bank and world-location persistence contracts are unchanged.

## 0.18.1-alpha — Disconnect-Safe Account Persistence & Partner Cleanup Fix

### Fixed — remote client logout/reconnect account loss
- Reworked authenticated disconnect handling into one idempotent **pre-teardown session finalization** transaction. `ADMFMMOGameMode::Logout` now commits the account before `Super::Logout` can detach/inactivate the PlayerState or Pawn.
- The final snapshot explicitly synchronizes the summoned partner's live authoritative HP/SP, then merges Party, Bank, active-partner GUID, starter state, Bits, scan data, avatar skin and the current valid player-world transform into the existing account record.
- Added an authoritative-account-initialized guard. A default/partially initialized `UDMFPlayerDigimonComponent` is no longer permitted to overwrite an established persistent account with empty arrays during network teardown.
- Removed the destructive double-save window: after the canonical disconnect snapshot succeeds, component `EndPlay` is marked persistence-finalized and cannot issue a second teardown-time account write. A failed primary save deliberately keeps one guarded `EndPlay` retry available.
- Added an idempotent authority-side `DMFMMOPlayerController::EndPlay` fallback so abnormal/abrupt net-driver teardown still attempts session finalization when the authoritative GameMode remains available.

### Fixed — orphaned player partner after disconnect
- Disconnect finalization now removes the partner combat-vitals delegate, force-disengages its encounter, destroys the transient summoned partner actor and clears Care presentation props without invalidating the persistent active-partner GUID.
- This applies even when Unreal temporarily retains an inactive PlayerState, preventing logged-out players from leaving combat-capable Digimon behind in the shared world.

### Compatibility / persistence
- Account SaveGame schema remains **v7**; no migration or reset is required.
- Vendor economy, lifetime battle EXP, spent Attribute Points, Digivolution/ABI provenance, Party/Bank, avatar skin and player-location fields are unchanged.
- RPC count remains **49**; no client-authored persistence or logout RPC was added.

## 0.18.0-alpha — Replicated Digimon Vendor Economy & Rotating Stock UI

### Fixed — UE5.8 native vendor widget compile
- Fixed `DMFDigimonVendorWidget.h` deriving `UDMFDigimonVendorEntryButton` from a forward-declared/incomplete `UButton`. The public header now includes `Components/Button.h` before the generated header, resolving UE5.8 `C2504` / `C2027` and the cascading `OnClicked`, `StyleButton`, `AddChild` and `AddChildToVerticalBox` conversion errors.
- Updated the new `DMFDigimonVendorActor` constructor to use `SetNetUpdateFrequency()` / `SetMinNetUpdateFrequency()` rather than introducing additional deprecated direct `AActor` network-frequency member access.
- No vendor economy behavior, replicated stock format, transaction RPC, SaveGame schema, progression valuation or existing baseline contract changed.

### Added — Blueprint-derivable replicated Digimon vendor NPC
- Added zero-tick `DMFDigimonVendorActor` with an exposed skeletal presentation component, interaction collision/prompt/range, per-NPC identity, Buy/Sell policies and per-NPC native-widget subclass override. The player interaction dispatcher recognizes vendors without Blueprint casts.
- Added server-owned weighted species pools, configurable stock-slot count, duplicate policy, immediate-refill policy and independent randomized min/max stock-rotation scheduler. Stock snapshots, generation serial and next-rotation server timestamp replicate to nearby clients; the actor uses a sparse timer rather than Tick.
- Added randomized stock generation for level, current-level EXP, ABI, CAM, spent Attribute Points, unspent Attribute Points and resulting HP/SP/STR/INT/DEF/SPD. Vendors/species overrides also expose independent min/max **natural HP, SP and combat-stat bonus rolls**, so same-species/same-level offers can still have meaningful natural variation before trained Attribute Points are applied. Species-specific generation ranges preserve each Species Data Asset's normal level growth and ability setup.
- Added authority Blueprint calls for vendor enablement, Buy/Sell enablement, pricing replacement, manual stock refresh and rotation restart, plus stock/config/trade Blueprint events.

### Added — automatic persistent individual valuation
- Added `FDMFDigimonVendorPricingSettings` and `FDMFDigimonVendorValueBreakdown`. Market value automatically considers stage, level, lifetime battle EXP, MaxHP/MaxSP, STR/INT/DEF/SPD, ABI, CAM, exact committed Attribute Points, unspent Attribute Points and unique Digivolution forms visited. ABI has a deliberately strong default weight to reward Digivolution/De-Digivolution progression.
- Vendor purchase price applies a configurable markup; player resale applies a configurable payout multiplier. Per-stock species multipliers can modify offers while an automatic anti-arbitrage floor prevents a generated offer from being cheaper than that same vendor's immediate resale quote.
- Added persistent `LifetimeBattleExperience` and `TotalAttributePointsSpent` to `FDMFDigimonInstance`. Positive authoritative EXP rewards accumulate lifetime EXP even at level cap, and every committed +1 Attribute Point increments the exact spend counter. These fields survive Digivolution/De-Digivolution because the individual instance identity remains unchanged.
- Account SaveGame schema advances **v6 → v7**. Legacy individuals conservatively infer lifetime progression EXP and spent points at authoritative load; the account then stamps `DigimonEconomyProvenanceVersion = 1`, making migration explicitly one-way so legitimate modern high-level/zero-spend Digimon are never re-inferred on later reconnects. Existing Digimon, stats, ABI, history, Party/Bank ownership and world location remain intact.

### Added — native BUY / SELL market UI and server transaction path
- Added polished native `DMFDigimonVendorWidget` with BUY/SELL tabs, Bits balance, replicated stock countdown, scrollable stock/collection rows, portrait/stage/attribute presentation, complete stat/progression detail, automatic value breakdown and two-step Buy/Sell confirmation. A vendor Blueprint can override the widget class without replacing transaction authority.
- Purchases atomically **reserve/remove the shared StockId before account-side mutation/delegates**, then deduct Bits, place the exact generated individual into Party/Bank, persist immediately and either commit the reservation or restore the exact immutable offer if the account mutation fails. This closes Blueprint/delegate re-entry and same-offer concurrency windows. Sales remove the exact owned individual, safely reconcile an active partner when necessary, credit Bits and persist immediately. Starter-sale protection and keep-one-Party-member policy are enabled by default.
- Added `ServerRequestDigimonVendorTransaction` and owner-only `ClientDigimonVendorTransactionResult`. Clients submit only vendor + Buy/Sell + GUID; the server revalidates range, vendor policy, stock/ownership, price, money, Party/Bank capacity and mutation locks. A small server transaction throttle protects against request spam. RPC count is **47 → 49**.
- Vendor UI is owner-local and modal; inventory/quick bars/ability input cannot race the market UI. Shared vendor stock is public only through ordinary actor relevance, while private Party/Bank/Money remain owner-only.

### Compatibility / regression contracts
- v0.17.3 network-smoothing-compatible swimming, v0.17.2 underwater reload reconstruction, v0.17.1 underwater post-process/fog, Day/Night, combat, Digivolution, Party/Bank and existing persistence contracts are preserved.
- Existing serialized enum numeric values are unchanged; `DigimonVendor` is appended after `Unhandled` in `EDMFPlayerInteractionType`, and the new vendor transaction enum is additive.
- Added `Docs/SETUP_DIGIMON_VENDOR.md` and updated architecture, networking, interaction, roadmap, test and validation documentation.

## 0.17.3-alpha — Network-Smoothing-Compatible Replicated Swim Presentation Fix

### Fixed — remote swim fallback now composes with CharacterMovement network smoothing
- Fixed remote swimmers appearing upright to other clients/listen-host observers even though replicated movement and water state were correct. The previous unaccepted direct-proxy mesh write was intentionally discarded because it competed with Unreal's remote mesh network smoothing and could introduce visible shake.
- Added one compact replicated `EDMFPlayerSwimState` presentation property (`None`, `Surface`, `Underwater`). It changes only at swim-state boundaries; skeletal-mesh transforms themselves are **not** replicated.
- Non-local rendered avatars now apply the native fallback through `ACharacter::CacheInitialMeshOffset`, changing the base location/rotation CharacterMovement smooths toward instead of calling `SetRelativeTransform` against the same mesh every frame. This covers both simulated proxies on clients and listen-server smoothing of remote autonomous clients.
- When a replicated swim-state transition occurs while the remote pawn is stationary, the CharacterMovement smoothing path is explicitly woken so the new mesh-base target is consumed without waiting for another movement correction.
- Remote underwater travel pitch still derives from already replicated/simulated CharacterMovement velocity; the owner retains immediate local prediction.
- Hardened base-mesh capture so a transient network-smoothing offset cannot be accidentally recaptured as the skin's authored rest transform. Runtime skin application also refreshes ACharacter's cached mesh base.

### Compatibility / networking
- New swimming RPCs: **0**. Existing RPC count remains **47**.
- No SaveGame schema change; account persistence remains v6 and v0.17.2 water reload reconstruction is unchanged.
- No serialized enum layout changed. The existing `EDMFPlayerSwimState` enum is reused exactly as-is.
- Water actors remain zero-tick. No per-frame replicated mesh rotation or transform traffic is introduced.


## 0.17.2-alpha — Persistent Water Reload State Reconstruction Fix

### Fixed — save/load restoration inside swimmable water
- Fixed returning players who saved at the surface or underwater being restored into the water transform while `CharacterMovement` remained in normal falling/walking logic. The authoritative initial-location handoff now performs a one-shot geometric water reconciliation immediately after the saved transform is applied, before partner restoration and before another movement frame can apply gravity.
- Water reconstruction no longer depends on a post-teleport `BeginOverlap` callback. `DMFPlayerAvatarCharacter::RebuildSwimmingStateFromWorld` scans the authored `DMFSwimmableWater` bounds at the avatar's current transform, resolves the same priority/surface winner, reapplies the existing replicated swimming movement contract, resolves Surface/Underwater immediately, and optionally clears stale movement velocity for teleport/load paths.
- Hardened `RegisterSwimmableWaterOverlap` so a geometrically-contained avatar is accepted even when Unreal's component overlap cache has not caught up after teleport. Ordinary overlap validation remains intact for players that are not actually inside the water bounds.

### Fixed — replicated owner presentation after underwater restore
- Hardened owner correction when `ActiveSwimmableWater` and the replicated underwater boolean arrive in either order. The local predicted water/underwater state now mirrors the latest authoritative pair immediately, preventing a restored underwater player from presenting as Surface for an avoidable frame.
- Reconstructed local water state immediately refreshes the existing swim fallback pose and underwater post-process/distance-fog path. No camera state is replicated; the local camera still independently determines whether the view is physically below the waterline.

### Teleport / persistence / compatibility
- Initial login restoration now reconciles water state for both saved and normal spawn transforms. Return Home performs the same one-shot reconciliation after teleport so stale swimming/fog cannot survive a teleport out of water, while a deliberately water-placed Home spawn is also handled correctly.
- Added Blueprint-callable `Rebuild Swimming State From World` for project-authored authoritative teleport systems. This is an explicit refresh operation, not a per-frame scan; water actors remain zero-tick.
- No swimming state was added to SaveGame. Account schema remains v6, world-time schema is unchanged, CharacterMovement remains the movement transport, and no new RPC is introduced.

## 0.17.1-alpha — Polished Underwater Post-Process + Distance Fog Presentation

### Added — per-water underwater visual profile
- Added replicated `FDMFUnderwaterPostProcessSettings` to `DMFSwimmableWater`. Every derived water Blueprint can author its own underwater color tint/strength, saturation, contrast, gamma, exposure compensation, vignette, subtle chromatic aberration, waterline hysteresis, depth-response strength, blend speeds, post-process priority and optional custom Post Process material. Runtime profile replacement/enabled/material helpers are authority-gated and replicate as sparse configuration changes.
- Added a dedicated local `UnderwaterPostProcessComponent` to `DMFPlayerAvatarCharacter`. It is enabled only for the locally controlled player and never becomes gameplay/network authority; remote avatar copies do not perform per-frame post-process work.

### Added — camera-correct waterline, depth response and real visibility falloff
- Underwater rendering is determined from the **actual third-person camera location** against the active water body's replicated surface/bounds, not merely the avatar-origin underwater flag. A swimmer can therefore remain visually clear while the camera is above the waterline and transition only when the camera itself submerges.
- Added camera enter-depth / exit-height hysteresis to stop waterline flicker, exponential blend-in/out, a configurable shallow-water starting weight and a full-strength camera depth. The effect becomes richer as the camera descends without a hard visual pop.
- Built-in native grading works without any project material: tint/gain, saturation, contrast, gamma, exposure, vignette and restrained chromatic aberration are composed into one local post-process profile.
- Added a native **local exponential underwater distance-fog** component driven by the same camera/depth blend. Per-water settings expose fog enablement, color, density, height falloff, start distance, maximum opacity and blend exponent. This produces actual scene-distance extinction instead of relying on color grading to fake haze; distant terrain now fades into water color while nearby character readability is preserved. Optional project Post Process materials remain available for caustics/refraction/digital distortion rather than being required for basic underwater fog.

### Blueprint / multiplayer / performance
- Added player Blueprint queries `Is Local Camera Underwater`, `Get Underwater Post Process Blend Weight`, `Refresh Underwater Post Process Presentation`, plus local camera-waterline delegate/event hooks for bubbles/audio/custom presentation. These values are intentionally local presentation, not replicated gameplay state.
- Water actors remain zero-tick. The local post-process/fog update reuses the existing player Tick only on the locally controlled avatar; dedicated servers render nothing and remote proxies keep both presentation components disabled. Stable fog settings are cached so render-state setters are not redundantly called every frame. No new RPC, movement authority, SaveGame field or account/world-time schema was added.
- Added `Docs/SETUP_UNDERWATER_POST_PROCESS.md` and updated swimming, architecture, networking, roadmap, test and validation documentation.

## 0.17.0-alpha — Replicated Swimmable Water & Underwater Locomotion

### Added — Blueprint-derivable swimmable water actor
- Added zero-tick replicated `ADMFSwimmableWater` with a visible plane mesh plus automatically matched query-only Pawn `SwimmingBounds`. `WaterSurfaceSize`, depth, above-surface overlap allowance, surface Z offset, priority, enabled state and movement tuning are exposed; runtime authority size/depth/enabled changes replicate and rebuild client geometry.
- The native Engine Plane is supplied as a ready-to-use fallback. Projects may assign any flat water mesh and exposed `WaterMaterial`; automatic mesh scaling derives from the assigned mesh bounds so plane and collision remain matched.
- Added Blueprint helpers for surface/bottom Z, depth below surface, point-in-water testing, geometry refresh, material changes and water overlap events.

### Added — replicated surface/underwater player swimming
- `DMFPlayerAvatarCharacter` now resolves overlapping water bodies deterministically by priority and uses a replicated authority-owned active-water reference plus replicated underwater threshold state. Owning clients predict local overlap for responsive entry while the server remains authoritative. No custom swimming RPC was added.
- Swimming uses CharacterMovement's mature replicated 3D movement path with water-specific speed/acceleration/braking. Forward input follows the camera; surface upward motion is constrained, camera-down Forward intentionally dives, underwater Forward includes camera pitch, Space ascends, C descends and sprint uses the water body's sprint speed.
- Added configurable surface buoyancy/ride-depth assist and separate Underwater Enter/Exit depths for hysteresis, preventing noisy Surface/Underwater toggling.
- Added Blueprint-pure `Is Swimming In Water`, `Is Swimming Underwater`, `Get Player Swim State`, `Get Active Swimmable Water`, `Add Swim Vertical Input`, state delegates and Blueprint events for AnimBP/audio/post-process integration.

### Added — animation-free swim presentation fallback
- The authoritative collision capsule remains upright. When no swim animation exists, the framework smoothly rotates only the player skeletal mesh into a horizontal face-forward fallback pose, compensating around the imported mesh bounds center instead of the usual foot/root pivot and optionally pitching with underwater travel direction. Rotation, location correction and interpolation speed are exposed on the avatar Blueprint.
- Real swim-animation projects can disable the fallback and consume the same replicated swimming state/events without replacing movement/networking. Skin changes preserve a clean base relative mesh transform so entering/exiting water does not permanently corrupt authored skin offsets.

### Persistence / performance / compatibility
- Water actors do not Tick. Swimming reuses the existing player Tick and Unreal CharacterMovement prediction/replication. Replicated water configuration changes are sparse property updates, not per-frame traffic.
- Existing account SaveGame remains schema v6. Swimming state is derived from world overlap after the already-persisted player transform restores, so no account migration is required. Return Home naturally exits water and checkpoints Home using the existing location system.
- Added `Docs/SETUP_SWIMMABLE_WATER.md`; updated architecture, networking, roadmap, test plan and validation documentation.

## 0.16.1-alpha — Replicated World Clock Quick-Access HUD

### Added — polished 12-hour world clock in the ability quick-access bar
- Added a compact native **12-hour digital world clock** to the combat/ability quick-access header. The default presentation is `h:mm AM/PM` plus a small color-coded `DAY` / `NIGHT` phase label, positioned between partner vitals and target state so it adds useful world information without creating another floating HUD panel.
- The HUD reads only `ADMFDayNightSky::GetTimeOfDayHours()` / replicated phase state. In Host-PC mode clients therefore display the host/server clock anchor rather than their own computer time; in Simulated mode they display the same smooth locally-interpolated persistent MMO world clock already used by the sky and spawners. No clock RPC, replicated UMG state, or client clock authority was added.
- Added Blueprint-pure `Get Formatted Time 12 Hour` on `DMFDayNightSky` so project-authored UMG can reuse the exact canonical `12:00 AM` / `12:00 PM` formatting, optionally including seconds.
- Added optional `WorldClockText` and `WorldClockPhaseText` bindings to `DMFCombatQuickBarWidget` for Blueprint reskins. The native fallback displays `--:-- -- / SYNC` until a local replicated sky actor resolves, then updates from the cached actor; a bounded one-second retry prevents an absent/mid-stream sky from causing an actor search every HUD refresh.
- Added Project Settings toggles under **UI -> Combat Quick Access -> World Clock** for showing the clock and showing the DAY/NIGHT phase label.

### Performance / multiplayer contract
- Reuses the combat quickbar's existing local 0.15-second refresh timer; no additional per-frame widget tick, network timer, RPC, SaveGame field, or replicated property is introduced.
- The sky actor is resolved once and weak-cached. Actor discovery retries at most once per second only while no valid sky exists.
- Existing v0.16.0 Day/Night authority, persistence, solar presentation, day/night wild population swapping and all v0.15.x systems remain unchanged.

## 0.16.0-alpha — Replicated Persistent Day/Night World & Population System

### Runtime/editor sky presentation correction
- Fixed outer-sky **visible sun-disc desynchronization** for conventional Unreal/marketplace sky-sphere materials. The framework now pushes the same canonical solar solution into configurable `Light direction` (light-ray vector) and `Sun height` (solar elevation) compatibility parameters on the outer Sky Dome MID every local visual update, so a material-authored sun disc moves with the authoritative Directional Light instead of remaining fixed. This does not rotate the sky mesh or digital layer and adds no replication/bandwidth cost.
- Added `Drive Sky Dome Solar Visual Parameters`, `Sky Dome Light Direction Parameter Name` and `Sky Dome Sun Height Parameter Name` under the sky actor's Solar Visual Compatibility settings. Defaults match the conventional Unreal sky-sphere parameter contract and may be renamed per project material.
- Fixed the native solar rotation sign: midday now places the authoritative/native Sun above the horizon (Directional Light pitch -90 at 12:00) instead of below it. The previous inversion could make a valid daytime clock look permanently night/sunset.
- `DMFDayNightSky` now previews automatically in the Unreal Editor. In Simulated mode the placed actor/derived Blueprint previews `Initial Simulated Time Hours`; Host PC mode previews the editor machine's current local time. Changing the authored hour immediately rebuilds sun/moon, phase values, dynamic sky materials and the digital inner layer without PIE.
- Added `Preview Sky In Editor` and made `Refresh Sky Presentation` a **Call In Editor** button for explicit rebuilds after material/mesh changes.
- Runtime presentation is now created only after the authoritative clock anchor/persisted simulated time has initialized, preventing the native SkyLight/material presentation from being built against a stale default/night anchor during BeginPlay.
- Added phase-boundary-only native SkyLight recapture (configurable) plus one-shot recapture on explicit/editor presentation refresh. This keeps ambient capture coherent while avoiding any per-tick recapture cost.
- `DMF_SunDirection` now represents the world-to-sun direction expected by sky materials, while the Directional Light itself keeps the correct ray-travel rotation.

- Added Blueprint-derivable `ADMFDayNightSky` as the shared authoritative world clock/sky actor.
- Added selectable `Host PC System Time` and persistent `Simulated / GTA Style` clock modes.
- Added sparse replicated time anchors with local client interpolation based on synchronized GameState server world time; no per-frame time RPCs.
- Added Blueprint runtime values/calls/events for current time, normalized time, day index, Day/Night phase, `IsDay`, `IsNight`, phase changes and time synchronization.
- Added separate server-owned `UDMFWorldStateSaveGame` (`SchemaVersion=1`) and configurable `WorldStateSaveSlot` so shared simulated world time is not duplicated into per-account saves. Account save schema remains v6.
- Added optional native movable Sun/Moon, SkyLight, SkyAtmosphere and outer SkyDome presentation components.
- Added an always-visible `DigitalInnerSkyLayerComponent` with project-selected mesh/material/texture, opacity/tint/UV controls and MID parameters (`DMF_InnerLayerTexture`, alpha-friendly opacity, UV scale/offset, time/day/sun values).
- Digital inner-layer UV panning is driven from synchronized server-world time so host and remote clients stay phase-aligned without replicating material parameters.
- Added `EDMFWildPopulationScheduleMode` and independent Day/Night rarity weights + spawn-entry arrays to `DMFWildDigimonSpawner`. Legacy `SpawnEntries` behavior remains the default.
- Day/Night spawners preserve the v0.14.5 two-stage rarity normalization inside each active population set.
- Added polished phase swapping: previous ambient population retires via existing ground despawn; old-phase Digimon already in combat may finish before retirement; new-phase population is cap-checked and staggered through the existing queue.
- Added replicated `ReplicatedPopulationPhase`, `GetPopulationPhase` and `BP_OnPopulationPhaseChanged` for presentation/debugging only.
- Added a one-shot server setup warning when a Day/Night spawner cannot resolve a `DMFDayNightSky`; the spawner safely uses its configured missing-sky fallback instead of failing or log-spamming.
- Added `Docs/SETUP_DAY_NIGHT_SKY.md` and expanded spawner/networking/architecture/test/config documentation.

## 0.15.3-alpha — Canonical Species Stage Presentation Fix

### Fixed — species-authored evolution stage labels
- Fixed framework-native runtime UI being able to expose the legacy serialized enum identifiers `BabyI` / `BabyII` instead of the canonical Digimon labels **Fresh** / **In-Training**.
- `DMFDigimonSpeciesData::Stage` remains the authoritative per-species source. World nameplates, Starter Selection, Party/Bank, Scan & Materialize, Care, DigiDex, DigiDex stage search/filter labels and Digivolution source/target/path presentation now all resolve that value through one shared canonical formatter.
- Added Blueprint-pure `Get Digimon Stage Display Text` in `UDMFDigimonPresentationLibrary` so custom UI can use the exact same runtime-safe label contract.

### Compatibility / networking
- The serialized `EDMFDigimonStage` enum identifiers, numeric ordering and species asset values are **not renamed or reordered**. Existing assets that store `BabyI`/`BabyII` continue loading exactly as before; only their displayed text is canonicalized to Fresh/In-Training.
- Presentation-only release: no RPC, replicated gameplay property, SaveGame schema, Digivolution requirement, combat, persistence or authority change.

## 0.15.2-alpha — Native Return Home HUD & Authoritative Home Teleport

### UE5.8 compile fix
- Fixed `C4458` in `UDMFHomeTeleportNotificationWidget::BuildNativeFallbackUI` by renaming the local overlay-slot variable so it no longer shadows inherited `UWidget::Slot`. UE5.8 promotes this shadow warning to a build-stopping error under the project warning policy. No runtime, networking, persistence or UI behavior changed.

### Added — Party Quick Access Home action
- Added a native **HOME** action to the existing Party Quick Access interaction row. It remains out of the way during normal gameplay and becomes clickable only when the local player presses **Tab** to enter the existing mouse/cursor interaction mode.
- `ADMFMMOPlayerController::RequestReturnHome` is Blueprint-callable for custom HUDs. The request contains **no destination transform**; the owned controller sends only a reliable action request and the server resolves the configured `DMFNewPlayerStart`.
- Added Project Settings under **UI -> Party Quick Access -> Home** for the master Home action switch, server anti-spam cooldown, owner notification widget class, notification visibility and toast hold time.

### Added — server-authoritative Return Home lifecycle
- `ADMFMMOGameMode::ReturnAuthenticatedPlayerHome` validates the authenticated framework avatar, resolves the same enabled/highest-priority `DMFNewPlayerStart` contract introduced in v0.15.1, stops residual player movement, performs a collision-aware authoritative teleport and aligns controller facing to the Home transform. Missing/blocked Home spawn points fail cleanly with owner feedback rather than accepting client coordinates or forcing an unsafe transform.
- A successful Home action immediately checkpoints the resulting v6 `PlayerWorldLocation`, so reconnecting after the teleport restores the Home position even if the process exits before the next 30-second autosave. No SaveGame schema change is required.
- If the active partner is summoned, its command target and battle encounter are cleanly disengaged without restoring HP/SP or clearing ability cooldowns. Digimon targeting that partner are disengaged, already-launched framework projectiles targeting **or launched by** it are destroyed, and the partner is moved beside the authoritative player using the existing `PartnerSpawnOffset`. This prevents delayed combat/projectiles from following a Home teleport across the map. Return Home is server-rejected while a Care or Digivolution sequence is active so those authoritative transactions cannot be interrupted.

### Added — owner-only Home result notification
- Added `UDMFHomeTeleportNotificationWidget`, a native top-center transient toast with separate success/failure states (`HOME • ARRIVED` / `HOME • UNAVAILABLE`). Assign a Blueprint child in Project Settings to fully reskin it while keeping teleport authority in C++.
- Added owner-only `ClientReturnHomeResult` plus `OnHomeTeleportResult` for deterministic UI acknowledgement. On success the Tab interaction mode closes automatically, normal gameplay input/cursor state is restored and the Party/combat HUDs refresh.

### Multiplayer / regression contract
- Adds one client->server request RPC and one owner-targeted result RPC. The client never submits location, rotation, spawn actor, account record or persistence data. The server owns destination selection, collision validation, combat teardown, teleport and immediate persistence.
- Save schema remains **v6**. Existing v0.15.1 saved locations, frontend layering, Party/Bank, EXP/levels, Attribute Points, Digivolution, Care, world chat, music, targeting and combat authority remain compatible.

### Documentation
- Added `SETUP_RETURN_HOME_HUD.md` and updated README, Party Quick Access setup, player-location setup, architecture, networking, config template, roadmap, test plan and validation report.


## 0.15.1-alpha — Persistent Player World Location & First-Login Spawn

### Added — dedicated first-login gameplay spawn point
- Added placeable `ADMFNewPlayerStart` (`DMFNewPlayerStart`) for accounts that do not yet have a persisted gameplay location. Designers place it directly in the Open World map; no tag/string convention is required.
- Multiple enabled points are supported: highest `SpawnPriority` wins, with deterministic actor-name tie-breaking. `ADMFMMOGameMode::ChooseNewPlayerSpawnPoint` is a BlueprintNativeEvent for projects that want custom shard/zone spawn selection later.
- If no enabled `DMFNewPlayerStart` exists, brand-new/legacy accounts safely fall back to Unreal's normal `PlayerStart` and that resulting location becomes their first checkpoint.

### Added — server-authoritative per-account world-location persistence
- Save schema **v6** adds `FDMFPlayerWorldLocationState` to each `FDMFAccountRecord`: saved-map name, player location, player rotation, server UTC checkpoint time and an explicit valid-location flag. Older accounts migrate with `bHasSavedLocation=false`; established pre-v0.15.1 accounts use the normal PlayerStart once and checkpoint there rather than being misclassified as brand-new players. No existing Digimon/account field is discarded.
- The existing account autosave transaction now captures the authoritative `DMFPlayerAvatarCharacter` transform alongside Party/Bank/Care/avatar state. Logout also captures the latest transform. New accounts commit their first spawn checkpoint immediately so a crash/disconnect before the first periodic autosave does not make them appear new again.
- Returning players restore their saved transform before active-partner spawning. The saved map must match the current gameplay level and all coordinates must be finite; stale/mismatched/invalid data falls back to Unreal's collision-safe normal `PlayerStart` rather than forcing a bad teleport.
- Restore is performed once per authenticated controller login, before partner restoration and remote-client `ClientRestart` resynchronization. Movement remains normal server-authoritative CharacterMovement after spawn; no client location is trusted.

### Blueprint / Project Settings
- Added `Enable Player World Location Persistence` and `Use Dedicated New Player Spawn` under **Project Settings -> Digimon MMO Framework -> Persistence -> Player World Location**. Both default to enabled.
- Added `SaveAuthenticatedPlayerWorldLocationNow` for server/admin Blueprint checkpoints plus `BP_OnInitialPlayerWorldLocationApplied` for presentation/analytics only.
- Added `ApplyCurrentWorldLocationToAccountRecord` on the server-authoritative player-avatar component for framework/custom persistence transactions.

### Multiplayer / regression contract
- Adds **zero RPCs** and no client-authored transform mutation. Every persisted position comes from the authoritative server pawn. Each account stores its own private location in the host-side account database; players never replicate saved coordinates to peers.
- Existing frontend, authentication, Party/Bank, progression, Attribute Points, Digivolution, Care, combat, world chat, music, spawners and active-partner replication remain unchanged.

### Documentation
- Added `SETUP_PLAYER_WORLD_LOCATION.md` and updated README, architecture, networking, config template, roadmap, test plan and validation report.


## 0.15.0-alpha — Project-Selectable Frontend Background Layering & Bootstrap Polish

### Added — framework-owned background widget class
- Added **Frontend Background Widget Class** under Project Settings -> Digimon MMO Framework -> UI -> Frontend. Assign any project Widget Blueprint derived from `UUserWidget`; no Level Blueprint `Create Widget` path is required.
- `ADMFFrontendHUD` now resolves the local PlayerController first, creates the selected background widget, adds it to the same game viewport layer used by the login widget, and only then schedules the login/main-menu bootstrap.
- The background is automatically placed exactly **100 Z-order units below** `Frontend Login/Menu Viewport Z Order`. This relationship is framework-owned, so a full-screen/opaque background cannot cover the framework login card because of an accidental project Z-order.
- Background and login are now both inserted with `AddToViewport` so they share one Slate viewport layer. This fixes the case where a project `AddToViewport` background could visually outrank the framework login even when the old login `AddToPlayerScreen` call used a numerically higher Z-order.
- `Frontend UI Startup Delay Seconds` now starts **after the selected background has been initialized**, making the setting a true background-to-login presentation delay rather than a race against map BeginPlay.
- If the optional background class fails to instantiate or add to screen, the framework logs the presentation failure and still continues into the login flow so a decorative asset can never lock the user out.

### Fixed / polished — native fullscreen background ownership
- The native `UDMFLoginMainMenuWidget` dark full-screen `FrontendBackdrop` remains disabled by default. Projects using the new Background Widget Class therefore receive their authored background un-tinted.
- `Show Native Frontend Fullscreen Backdrop` plus `Native Frontend Backdrop Opacity` remain available for an optional dim treatment.
- The native root and optional decorative backdrop remain `SelfHitTestInvisible`; the login card stays interactive while empty foreground space does not unnecessarily consume hits.
- Frontend background and login widgets are both removed by the HUD on frontend EndPlay/map travel.

### Multiplayer / authority contract
- This release changes local frontend presentation only. It adds no RPC, replicated property, SaveGame field or trusted client gameplay mutation.
- Login credential staging, endpoint validation, Admin unlock, Host & Play listen-server startup, server `PreLogin` authentication, account persistence and gameplay travel are unchanged.
- Background widgets are local presentation only and never become an authentication/hosting authority surface.

### Documentation
- Revised `SETUP_FRONTEND_BACKGROUND_PRESENTATION.md` around the one-setting Background Widget Class workflow and updated README, native-UI setup, architecture, networking, config template, roadmap, test plan and validation report.

## 0.14.9-alpha — Attribute Point Spending & Native Digimon Menu Layout Polish

### Added — server-authoritative Attribute Point spending
- Added `EDMFDigimonAttributeStat` for the six spendable persistent battle stats: Max HP, Max SP, Strength, Intelligence, Defense and Speed. ABI/CAM remain non-spendable progression/care values.
- Added Blueprint-pure `CanSpendDigimonAttributePoint` plus reliable server `ServerSpendDigimonAttributePoint`. Every request revalidates account ownership, unspent points, stat eligibility, integer safety and active Digivolution state on the server before mutation.
- Each successful request spends exactly one `UnspentAttributePoints` and adds exactly one point to the selected stat. MaxHP/MaxSP preserve the current missing/spent amount by increasing current HP/SP by the same +1 capacity delta; defeated Digimon remain defeated.
- Party and Bank Digimon use the same persistent mutation path. Party/Bank owner Fast Arrays are dirtied, the account is persisted immediately, and a currently summoned active partner refreshes public replicated stats/vitals without respawn, heal reset, target reset, cooldown reset or battle-state reset.
- Added owner-only `OnAttributePointSpendResult`/`ClientAttributePointSpendResult` for deterministic UI acknowledgement only; clients never author the resulting value or remaining-point count.

### Added — native `+` controls
- Party and Bank selected-Digimon stat cards now expose compact `+ HP`, `+ SP`, `+ STR`, `+ INT`, `+ DEF`, `+ SPD` controls under the current Attribute Point total. Buttons disable when the selection cannot legally spend.
- Custom Blueprint UI can use the same enum, eligibility query and authoritative server RPC without relying on the native fallback widget.

### Fixed / polished — Digimon Menu containment
- Increased the native design canvas from 1240x820 to **1240x900**, still inside the existing `ScaleToFit / DownOnly` wrapper, to accommodate the mature Party/Bank/Scan/DigiDex/Digivolution/Care feature set.
- Added hard window clipping as a final layout safety contract and reduced several oversized portrait viewports/minimum description height so footer/action controls stay inside the modal window instead of bleeding below it on short/DPI-scaled viewports. Existing internal scroll regions remain intact.
- **Revised candidate:** the Party selected-Digimon panel now keeps its identity/portrait header fixed and places stats, EXP, Attribute Point controls, description, `SET ACTIVE / SUMMON`, `RECALL ACTIVE PARTNER` and `MOVE TO BANK` inside one bounded vertical `ScrollBox`. This fixes the final short-viewport case where Party actions were clipped below the modal even though the other tabs already scrolled correctly.
- Removed the old nested Party-description scroll lane so wheel/gamepad scrolling follows one deterministic detail-body path instead of becoming trapped inside a small inner region.
- This is presentation/layout only; no tab enum values, storage rules or gameplay authority changed.

### Multiplayer / persistence contract
- Attribute spending is server-authoritative, immediately persisted and owner-only in private Party/Bank storage state; a summoned Digimon's resulting public stats continue through normal actor replication.
- No SaveGame schema bump is required because stats and `UnspentAttributePoints` were already persistent. No existing RPC, reflected function or serialized enum value was removed/reordered.

### Documentation
- Added `SETUP_ATTRIBUTE_POINTS.md` and updated README, leveling/native-UI setup, architecture, networking, roadmap, test plan and validation report.

## 0.14.8-alpha — Owned Digimon Level Progression & Native XP UI

### Added — authoritative EXP thresholds and persistent level growth
- Battle EXP no longer accumulates as an inert number. `UDMFPlayerDigimonComponent` now consumes the active partner's stored EXP through server-owned level thresholds and supports multiple level-ups from one reward.
- Every gained level applies the current species' existing `HPPerLevel`, `SPPerLevel`, `StrengthPerLevel`, `IntelligencePerLevel`, `DefensePerLevel` and `SpeedPerLevel` growth values and grants `AttributePointsPerLevel` into the already-persistent `UnspentAttributePoints` field.
- Increased MaxHP/MaxSP also increase current HP/SP by the same capacity delta so level growth is immediately useful without erasing damage/SP already spent. A defeated Digimon remains defeated.
- The summoned partner refreshes its public replicated `ReplicatedStats` plus authoritative HP/SP through a progression-specific refresh path that deliberately does not reset combat state, target, encounter latch, cooldowns or recovery.
- Existing stored EXP is normalized on authoritative account hydration, allowing v0.14.7 accounts with accumulated EXP to catch up automatically. Existing levels are never reduced if a project later lowers a configured cap.

### Added — species-owned numeric EXP requirements
- `DMFDigimonSpeciesData` now owns `BaseExperienceRequired`, `ExperienceGrowthMultiplierPerLevel` and optional `MaxLevelOverride`; there is no CurveFloat asset dependency in the leveling workflow.
- Requirement formula is deterministic and shared by authority + native UI: `BaseExperienceRequired * pow(ExperienceGrowthMultiplierPerLevel, CurrentLevel - 1)`. `1.0` is flat, `1.10` adds 10% per level, `1.20` adds 20% per level. Each species therefore controls its own EXP economy directly from its Data Asset.
- Project Settings keeps only the master leveling switch and `DefaultMaxDigimonLevel`; EXP pacing itself belongs to the species.
- Added Blueprint-pure queries for requirement-at-level, effective species max level, owned-Digimon next requirement and normalized current-level progress.
- No SaveGame schema version bump is required: `Stats.Experience`, `Stats.Level`, existing stats and `UnspentAttributePoints` remain the durable fields.

### Added — polished native EXP / LEVEL UP presentation
- Added `UDMFExperienceNotificationWidget`, a native owner-only queued toast with portrait/species identity, gained EXP, animated current-level progress and a distinct gold level-up result revealed when the animated bar crosses its first earned threshold. Large rewards can visually cross multiple level segments.
- Level-up presentation reports old/new level and Attribute Points gained; max-level completion is explicitly labeled. Rapid rewards are bounded/queued instead of overwriting one another.
- Added `ExperienceNotificationWidgetClass`, native-notification enable, progress animation time, normal/level-up hold times and bottom-safe offset under Project Settings. Blueprint child widgets can fully reskin presentation.
- Party selected-details and Bank selected-details now show `EXP current / required`, native progress bars and unspent Attribute Points. Max-level Digimon show `MAX`.
- Added owner-only `OnDigimonExperienceProgressed` plus a dedicated reliable client result RPC carrying immutable old/new progression state. The existing `OnBattleRewardGranted` contract remains unchanged for backward compatibility.

### Multiplayer / regression contract
- EXP award, threshold consumption, level/stat growth, Attribute Point grant, max-level handling and persistence are server authoritative. Clients cannot submit level/EXP/stat mutations.
- Party/Bank progression remains owner-only Fast Array state. The currently summoned Digimon's public Level/stats continue through normal actor replication so other players/nameplates observe the correct level.
- The new client RPC is presentation data only and cannot author gameplay. Native XP animation is entirely local.
- Save schema remains v5; no serialized enum reorder or existing RPC signature was changed. v0.14.7 combat AI, v0.14.6 CustomDepth, v0.14.5 spawning and v0.14.4 battle-music behavior are preserved.

### Documentation
- Added `SETUP_LEVEL_PROGRESSION.md` and updated README, combat/native-UI setup, architecture, networking, roadmap, Project Settings config template, test plan and validation report.

## 0.14.7-alpha — Wild / Auto-Battle Full Moveset Rotation Fix

### Fixed — autonomous Digimon now use their complete eligible ability moveset
- Fixed wild Digimon and other autonomous combatants repeatedly using only `BasicAutoAttack` even when multiple equipped/starting abilities were available.
- Root cause: `UDMFDigimonCombatComponent::AutomationTick` explicitly resolved `BasicAutoAttack` and executed that single ID every attack decision; the rest of `ReplicatedAbilityIds` were never considered by autonomous combat.
- Auto battle and wild retaliation now select from the complete runtime equipped moveset (`ReplicatedAbilityIds`) plus the Basic Auto Attack compatibility fallback. Only abilities with `bEligibleForAutoBattle=true` participate.
- Selection respects authoritative SP availability, per-ability cooldowns, hostile target validity and the existing leash contract before a move is considered ready.
- Added server-only least-recently-used fairness history. Among currently usable abilities, never/least-recently-used moves are preferred first, with randomization only between equally old candidates. This prevents slot-order bias and makes all usable moves surface before already-used moves are preferred again.
- Added a server-only pending autonomous ability intent. When the selected move is out of range, AI keeps that same move while chasing into its authored capsule-aware range instead of changing move/range every automation tick. This allows mixed melee/ranged movesets to work reliably without movement thrashing.
- Rotation history resets when the authoritative combat target changes, combat is reset, the Digimon is defeated, or victory tears down the target.

### Multiplayer / regression contract
- Ability choice, chase intent, SP/cooldown checks and execution remain authority-only. The new selection history/pending intent are transient server-only members and are not replicated or saved.
- No RPCs, replicated properties, SaveGame fields, serialized enums or existing Blueprint APIs were added/reordered. Existing `bEligibleForAutoBattle` remains the designer opt-in/opt-out switch per ability.
- Player manual quick-slot commands are unchanged and continue to take priority through the existing server command queue. Player-owned partner auto battle remains disabled by default; if deliberately enabled, it benefits from the same full-moveset selector.
- v0.14.6 CustomDepth VFX/marker behavior, v0.14.5 rarity weighting and v0.14.4 persistent battle music are unchanged.

### Documentation
- Updated README, combat setup, wild-spawner guidance, architecture, networking, roadmap, test plan and validation notes for full-moveset autonomous combat.

## 0.14.6-alpha — Attack VFX / Enemy Marker CustomDepth Enforcement

### Fixed — attack particles now always render into CustomDepth
- Direct ability Niagara and Cascade components spawned by `UDMFDigimonCombatComponent` now force `Render CustomDepth Pass = true` immediately after each runtime spawn.
- Projectile-impact Niagara and Cascade components follow the same rule on every impact spawn.
- Replicated moving ability-projectile Niagara/Cascade components enable CustomDepth in their constructor and reassert it every time projectile presentation is refreshed before activation.
- The owner-local enemy target arrow above the selected Digimon now forces CustomDepth for both Niagara and Cascade, including constructor setup, runtime asset refresh and every activation path.
- The framework does not modify CustomDepth stencil values here; project-authored stencil configuration remains available while the render-pass participation flag is guaranteed on.

### Multiplayer / regression contract
- Presentation-only fix: no combat authority, targeting validation, damage, projectile movement/impact, selection privacy or replication ownership changed.
- No RPCs, replicated properties, SaveGame fields or serialized enums were added or reordered.
- Targeting presentation remains local-only/non-replicated; projectile gameplay remains server-authoritative and replicated exactly as before.
- v0.14.5 normalized rarity spawning and v0.14.4 persistent battle music behavior are unchanged.

### Documentation
- Updated README, combat-targeting setup, ability-projectile setup, architecture, networking, test plan and validation notes with the enforced CustomDepth presentation contract.

## 0.14.5-alpha — Rarity-Weighted Spawn Selection Normalization Fix

### Fixed — rarity tiers are no longer biased by species-count
- Fixed `ADMFWildDigimonSpawner` favoring a rarity/category simply because more spawn entries were authored inside it.
- Root cause: the old one-pass roll assigned `Rarity Base Weight * Selection Weight Multiplier` to every entry, effectively adding the same rarity base weight to the pool once per species. A tier containing many Rookie entries could therefore overwhelm a smaller In-Training pool despite lower intended weighting.
- Spawn selection is now two-stage and authority-only: the server first rolls one currently eligible rarity tier from `RarityWeights`, then rolls one eligible entry inside that tier from `SelectionWeightMultiplier`.
- `SelectionWeightMultiplier` is now explicitly a **within-rarity-tier relative species weight**. A value of `2.0` is twice as likely as `1.0` among eligible entries in the same selected tier; `0.0` disables the entry without deleting it.
- Disabled/invalid entries, zero-weight tiers/entries, and entries that reached `MaxAliveFromEntry` are removed before selection, so capped entries cannot distort either roll.

### Multiplayer / regression contract
- Rarity/species rolls remain server-authoritative. Clients do not roll or influence spawn selection.
- No RPCs, replicated properties, SaveGame fields or serialized enums were added or reordered.
- Existing spawn-table assets require no migration; the same fields now produce normalized tier behavior independent of how many species are authored per tier.
- Wild replication, population activation/deactivation, level rolls, placement/NavMesh grounding, emergence/despawn, roaming, combat, respawn and per-entry live caps are unchanged.

### Documentation
- Updated README, wild-spawner setup, architecture, networking, roadmap, test plan and validation notes with the corrected two-stage weighting contract.

## 0.14.4-alpha — Persistent Battle Music Encounter State Fix

### Fixed — Battle music no longer expires between manual attacks
- Fixed Battle music returning to Open World shortly after an attack when the player paused between ability-button presses while the hostile Digimon was still alive.
- Root cause: `UDMFMusicSubsystem` treated only transient `Chasing`, `Attacking` and `Recovering` action states as Battle. Manual combat legitimately returns to `Idle` after recovery, so the old `BattleMusicReleaseDelaySeconds` countdown could expire during an ongoing encounter.
- Added `bBattleEncounterActive`, a server-authoritative replicated encounter latch on `UDMFDigimonCombatComponent`. Real chase/attack/recovery against a valid hostile target starts the latch; `Idle` action gaps do not clear it.
- Victory, local Digimon defeat, authoritative target clear/disengage and combat reset/healer teardown clear the encounter latch. The existing release delay now begins only after the durable encounter ends.
- `UDMFMusicSubsystem` uses the replicated encounter latch first, with the active combat-state check retained only as replication-ordering safety for immediate Battle entry.
- Added Blueprint-pure `IsBattleEncounterActive()` so custom UI/presentation can query the same durable server-authored encounter truth without inferring battle lifetime from animation/action states.

### Multiplayer / regression contract
- Music remains completely client-local presentation: **no music RPCs, playback replication or shared AudioComponents** were added.
- The combat component adds one replicated authority-owned boolean; clients cannot set encounter state. Host and remote clients therefore continue to resolve Battle/Open World music independently from their own active partner.
- Target selection alone still does not start Battle music. Existing crossfade, volume, looping, Battle-music fallback and suppression controls are unchanged.
- v0.14.3 targeting visuals, v0.14.1 projectiles/VFX, DigiDex, Digivolution, Party/Bank, Scan/Materialization, Care/healer, chat/nameplates, camera/footsteps, accounts and SaveGame schema remain unchanged.

### Documentation
- Updated global-music setup, README, architecture, networking, roadmap, test plan, validation report and config-template commentary for the persistent encounter contract.

## 0.14.3-alpha — Local Targeting Visibility Runtime Fix

### Fixed — local targeting markers could be culled for their owning player
- Fixed the v0.14.2 blue active-partner ring, hostile target ring and Niagara/Cascade arrow all remaining invisible even with valid Project Settings assets and a valid selected target.
- Root cause: the presentation actor is already local-only/non-replicated, but its visual components redundantly enabled Unreal's `Only Owner See` render filter. The active camera/view-owner chain can differ from the PlayerController owner chain, causing those local components to fail the owner-visibility test.
- Targeting sprite/VFX components now render normally inside the local-only presentation actor (`OnlyOwnerSee=false`, `OwnerNoSee=false`) while retaining zero replication and zero shared marker state. Other players therefore still cannot see another player's markers.
- Added runtime asset self-healing: if a targeting sprite/Niagara/Cascade asset is assigned after PIE has started, the local presentation actor detects the previously missing asset and reloads Project Settings automatically.
- The tiny local presentation actor is now created regardless of the master targeting-visual switch; while disabled it simply hides its components. This lets the global switch be enabled during PIE without requiring a level restart.

### Regression contract
- No combat targeting authority or RPC behavior changed. `CommandTarget` remains owner-only replicated and server validated.
- Projectile execution/homing/impact, DigiDex, Digivolution, Party/Bank, Care/healer, chat/nameplates, camera/music/footsteps, account persistence and SaveGame schema are unchanged.

## 0.14.2-alpha — Polished Owner-Only Combat Targeting Visuals

### Added — local MMO targeting presentation
- Added native local-only `ADMFTargetingPresentationActor`, spawned only for a locally controlled framework PlayerController and never replicated.
- Added a configurable blue active-partner PaperSprite ring that is visible only to the owning player and automatically follows the summoned active partner at capsule-bottom height.
- Added a separate configurable enemy-target PaperSprite ring plus Niagara-preferred/Cascade-fallback hovering down-arrow for the owner's current authoritative command target.
- Partner and enemy rings use separate world-Z pivot rotation with different default speeds/directions (`+28°/s` and `-42°/s`) and optional capsule-radius scaling for tiny/large Digimon forms.
- Added Project Settings controls for ring assets, scale, ground offsets, sprite orientation, auto-size bounds, sort priority, arrow VFX selection, height, scale, rotation and native hover bob.
- Added `RefreshTargetingVisuals` / `GetTargetingPresentationActor` controller APIs and local presentation refresh/inspection hooks.

### Networking / compatibility
- Targeting visuals add **no RPC, no replicated marker state and no SaveGame fields**. They consume the already owner-only `ActivePartnerActor` and `CommandTarget`, so other players cannot see another client's selection markers.
- Existing server-authoritative target validation, ability commands, projectile execution/homing/impact, Party/Bank, DigiDex, Digivolution, Care/healer and all previous network contracts remain unchanged.
- Added the Paper2D runtime dependency because the requested selection-ring assets are native `PaperSprite` assets.

### Documentation
- Added `Docs/SETUP_COMBAT_TARGETING_VISUALS.md` and updated README, architecture, networking, roadmap, test plan, validation report and config template.

## 0.14.1-alpha — Replicated Ability Projectiles & VFX Lifecycle Hardening

### Added — real server-authoritative projectile execution
- Added `EDMFAbilityExecutionMode` with backward-compatible **Timed / Instant Impact** and opt-in **Replicated Projectile** modes on every `DMFDigimonAbilityData`. Existing ability assets default to Timed Impact and therefore do not silently change behavior when upgrading.
- Added the native Blueprintable replicated `ADMFAbilityProjectileActor`. Authority launches it from the authored projectile socket (falling back to the existing VFX socket), rotates travel toward the validated target, optionally homes with a bounded turn rate, replicates world movement to observers, and owns a hard lifetime cleanup guard.
- Projectile-mode damage is applied only when the authoritative projectile reaches the still-valid hostile target. Initial cast range/SP/cooldown/facing/leash remain server-validated through the existing combat path; clients cannot submit damage, hit position, arrival time or projectile class authority.
- Added Data Asset controls for optional projectile Blueprint class, Niagara/Cascade/Static Mesh visuals, local visual rotation/scale correction, launch offset, speed, homing, turn rate, target offset, impact radius, max lifetime and optional impact Niagara/Cascade/Sound.
- Ability Niagara/Cascade and legacy species Attack1/Attack2 particles remain projectile-visual fallbacks, allowing existing fireball content to opt into Projectile mode without duplicating assets.
- Added an unreliable replicated projectile-impact presentation cue; durable gameplay damage is committed by authority before the cue.

### Fixed — attack VFX rotation and cleanup
- Projectile travel direction is derived from launch point → authoritative target instead of inheriting arbitrary skeleton socket rotation. `Projectile Visual Rotation Offset` corrects assets authored along a different local axis without corrupting travel direction.
- Projectile actor destruction now guarantees cleanup of attached Niagara/Cascade/mesh presentation after impact, invalid source/target or max-lifetime expiry.
- Timed/instant Niagara and Cascade cues now use a forced `Presentation VFX Lifetime Seconds` cleanup timer so looping attack systems cannot remain permanently at the attack socket or accumulate over long play sessions.
- Timed socket-origin VFX are aimed toward the selected target and expose presentation rotation/scale offsets.

### Documentation / regression contract
- Added `Docs/SETUP_ABILITY_PROJECTILES.md` and updated combat setup, README, architecture, networking, roadmap, test plan and validation report.
- v0.14.0 DigiDex, v0.13 Digivolution, Party/Bank, Scan/Materialization, Care/healer, chat/nameplates, camera, music, footsteps, accounts and frontend authority contracts remain additive and unchanged.

## 0.14.0-alpha — Polished Native DigiDex Species Encyclopedia

### Added — read-only implemented-species encyclopedia
- Added a first-class **DIGIDEX** tab to the shared native Digimon Menu without shifting any previously serialized tab enum value. Visual order is now **PARTY → BANK / BOXES → SCAN & MATERIALIZE → DIGIDEX → DIGIVOLUTION → CARE**.
- DigiDex enumerates every registered `DMFDigimonSpecies` Primary Asset with `Show In DigiDex` enabled (default), so newly implemented species appear automatically when their `DMFDigimonSpeciesData` asset is placed under the recursively scanned species directory. Species may optionally author a stable `DigiDex Number`; zero uses deterministic Stage/name fallback ordering.
- Added a polished four-column species browser with fixed aspect-safe portrait cards, deterministic Stage/name ordering, registry numbers, OWNED / SCANNED / UNSCANNED badges, live result counts, text search, Stage filtering and Attribute filtering.
- Added a read-only selected-species dossier with portrait, Stage/Attribute/Element, ownership + Scan status, base stats, starting level, battle rewards, Scan/Materialization values, starting move references, species description, and authored previous/next Digivolution-family links.
- DigiDex intentionally exposes **no summon, recall, Party, Bank, Care, Materialization, Digivolution, or other mutation action**. It is encyclopedia presentation only.
- Discovery status is derived from existing owner-only Scan Data and Party/Bank ownership; no duplicate discovery persistence or replication channel was introduced.
- Added Blueprint-facing `RefreshDigiDexData`, `GetDigiDexSpeciesIds`, `GetSelectedDigiDexSpeciesId`, and `BP_OnDigiDexSelectionChanged` hooks for custom reskins.
- Added `UI|DigiDex -> Enable DigiDex` Project Setting.

### Performance / compatibility
- Species enumeration uses the existing Asset Manager `DMFDigimonSpecies` registry and falls back to starter/evolution graph traversal for editor compatibility when the project scan config has not yet been copied. Packaged builds should continue scanning `/Game/DigimonData` recursively as supplied in the framework config template.
- DigiDex is fully local/read-only UI. It adds **no RPCs, no replicated properties and no SaveGame schema change**.
- v0.13.1 Digivolution, Party/Bank, Scan/Materialization, Care, healer, combat and all existing authority contracts remain unchanged.

### Documentation
- Added `Docs/SETUP_DIGIDEX.md` and updated README, architecture, networking, native UI guide, Party/Bank/Digivolution cross-references, roadmap, test plan, validation report and config template.

## 0.13.1-alpha — Digivolution Owned-Roster Aspect / Card Layout Fix

### Fixed — Digivolution Party/Bank cards no longer stretch portraits
- Fixed the native **DIGIVOLUTION → OWNED DIGIMON • PARTY + BANK** grid stretching one- and two-card rows across the full left panel. The root cause was `UUniformGridSlot` fill alignment overriding the intended fixed `USizeBox` footprint.
- Digivolution owned cards now use a fixed **132 × 166** Slate-unit footprint and are centered inside their grid cells, so sparse rows remain compact instead of becoming giant horizontal cards.
- Reworked the Digivolution owned roster to a polished **three-column** layout sized for the 500-unit left panel. Six Party Digimon therefore remain readable as two clean rows, while Bank entries continue vertically through the existing scroll region.
- Added a dedicated **104 × 104 square portrait viewport** with `ScaleBox / ScaleToFit / DownOnly`, guaranteeing portrait aspect ratio is preserved even if parent cells or viewport scaling change.
- Moved location/name metadata into a separate footer below the portrait rather than overlaying it on a stretchable image region. ACTIVE/KO badges remain pinned to the portrait viewport.

### Preserved / regression contract
- Digivolution authority, requirements, persistence schema v5, transformation VFX/audio, Party/Bank state, Care, healer, Scan/Materialization, combat and all network contracts are unchanged from v0.13.0.
- No baseline source file or existing reflected function was removed.

### Documentation
- Updated README, Digivolution setup, polished native UI guide, roadmap, test plan and validation report for the v0.13.1 layout correction.

## 0.13.0-alpha — Polished Replicated Digivolution

### Added — persistent branching Digivolution
- Expanded each `DMFDigimonSpeciesData::Digivolutions` path into a fully data-driven progression contract with destination species, Level, ABI, CAM, optional STR/INT/DEF/SPD requirements, optional Happiness/Discipline/Care-Mistake gates, optional money cost, Bank permission, stat/ability/vital carry-over policies and path-specific presentation overrides.
- Added owner-facing Digivolution evaluation APIs and a reliable `ServerDigivolveOwnedDigimon` request. Clients submit only owned instance GUID + target species ID; the server resolves the current source form/path and revalidates every requirement before mutation.
- Party and Bank are both supported. Stored Digimon evolve directly in Bank when globally/path-allowed; active Party Digimon retain the same instance identity and Party slot.
- Successful mutation preserves persistent GUID, nickname, Level/EXP, ABI/CAM, Care state and unspent attribute points. Configured positive stat investment can carry to target BaseStats; target abilities/vital restoration are path-controlled.

### Added — replicated active-partner transformation
- A summoned active partner enters a server-owned Digivolution sequence rather than changing species instantly.
- Combat targeting/automation and conflicting partner/storage/Care/ability commands are locked for the sequence.
- `DMFDigimonCharacter::MulticastPlayDigivolutionCue` reliably presents Niagara-preferred/Cascade-fallback VFX and path/global Sound Cue to relevant peers, with `BP_OnDigivolutionCue` available for project cosmetic extensions.
- After the authoritative presentation duration the server revalidates, commits/persists once, deducts money once, then replaces the old partner with the target species `WorldActorClass`. Normal actor replication publishes the transformed form.
- Owner UI can hide during the world transformation and automatically return to the DIGIVOLUTION page afterward.

### Added — polished native Digivolution UI
- Added `DIGIVOLUTION` to the existing Digimon Menu without shifting earlier serialized enum values. Visual order is now **PARTY → BANK / BOXES → SCAN & MATERIALIZE → DIGIVOLUTION → CARE**.
- Added Party+Bank owned browser, current-form profile, scrollable branching path cards, READY/LOCKED requirements, target-form preview and authoritative Digivolve action.
- Fresh/In-Training stage display names now appear cleanly in reflected UI while retaining the existing enum values.

### Persistence / configuration
- Advanced account SaveGame schema to **v5** with persistent `OriginSpeciesId` and unique `DigivolutionHistory`; older instances seed provenance from their current species during authoritative account hydration.
- Added Project Settings Digivolution master/rule/presentation controls and global Niagara/Cascade/Sound defaults with per-path overrides.
- Added recursive Digivolution-graph species resolution fallback in addition to Asset Manager resolution, while the supplied Asset Manager template continues to recommend scanning all species recursively for packaged builds.

### Documentation / regression contract
- Added `Docs/SETUP_DIGIVOLUTION.md` and updated README, architecture, networking, roadmap, native UI guide, test plan, validation report and project config template.
- Existing Party/Bank, healer, Care, Scan/Materialization, combat, chat/nameplates, camera, music, footsteps, account and frontend systems remain additive regression contracts.

## 0.12.2-alpha — Polished Replicated Healer Treatment Presentation

### Added / changed
- Upgraded `ADMFHealerActor` with a native Blueprint-positionable treatment rig: `HealingPresentationAnchor`, pulsing green `UPointLightComponent`, Niagara component, Cascade fallback component and attached healing audio component.
- Added Details-exposed Niagara/Cascade/Sound assets, VFX preference, presentation transform, green-light color/intensity/radius/pulse/fade tuning, audio volume/pitch/fade-out and configurable treatment duration/busy message.
- Added replicated `bHealingInProgress`, active healing PlayerState and healed-Digimon count. Clients reconstruct the light/VFX/audio locally from that compact durable state; no per-frame cosmetic replication is introduced.
- One healer actor is exclusive to one accepted player for its treatment duration. Concurrent requests to the same station are server-rejected with the Busy Message. Different healer actors remain independently usable.
- The accepted heal still restores the complete authoritative Party and, when enabled, every persistent Bank/Box record in one transaction, including defeated revival, immediate persistence and optional active-partner re-summon.
- Added `IsHealing`, `GetActiveHealingPlayerState`, `RefreshHealingPresentation`, `BP_OnHealingSequenceStarted` and `BP_OnHealingSequenceFinished`. The original `BP_OnHealPresentation` multicast hook is preserved for existing healer Blueprints.
- Disabling a healer during an active treatment ends the presentation cleanly. Dedicated servers never render light/VFX/audio.

### Documentation
- Added `Docs/SETUP_POLISHED_HEALER_PRESENTATION.md` and updated README, healer setup, architecture, networking, roadmap, test plan and validation report.

## 0.12.1-alpha — Polished Native UI Layout Hardening

### Fixed / polished
- Hardened the native Digimon Menu against text/button overlap and out-of-bounds presentation at normal PIE/game viewport sizes. The fallback window is taller/wider with rebalanced Party/Bank/Scan/Care content lanes and more room for the right-side profile/action panels.
- Party and Scan species descriptions now live in clipped scroll regions so long descriptions can never draw through the pinned action buttons. Bank stats/destination guidance use a dedicated scroll body above the fixed **MOVE / SWAP TO PARTY** footer; Care safety rules use the same protected layout pattern.
- Bank/Box storage now places the fixed-size six-column card grid inside its own scroll region. Configured page sizes no longer compress the card rows; the Party Destination strip remains pinned and readable below the Box grid.
- Added a compact native button style for dense Party/Bank/Party-destination/quickbar cards, removing wasted inner padding that previously squeezed portraits and labels.
- Reworked the six-slot Party Quick Access cards so portraits and two-line identity/state text use the full slot width rather than competing side-by-side.
- Polished the combat quickbar with wider/taller ability cards, compact card padding and automatic collapse of unassigned icon frames. Ability names/SP/READY text therefore receives the full card width when an ability has no icon.
- Increased fixed Party/Bank card and destination-slot sizing, enabled safe wrapping on detail identities/action labels, and retained ScaleBox down-scaling for genuinely small viewports.

### Preserved
- No Party, Bank, Materialization, Care, combat, chat, nameplate, camera, audio, persistence or networking authority behavior changed. No existing reflected UFUNCTION was removed and all existing RPC contracts remain intact.

### Documentation
- Updated README, Party/Bank setup, polished native UI setup, roadmap, test plan and validation report with the v0.12.1 layout-hardening acceptance checks.

## 0.12.0-alpha — Polished Party, Digimon Bank / Boxes & Party Quick Access

### Added / changed
- Formalized the account-owned roster into a server-authoritative **Party + Digimon Bank** model. Party is six Digimon by default; Bank/Box storage is 200 slots by default and remains accessible from the shared Digimon Menu anywhere in the gameplay world.
- Added owner-only replicated Bank FastArray state plus `GetPartyDigimon`, `GetBankDigimon`, combined ownership lookup/capacity APIs, Bank change/result delegates, and reliable server RPCs for Party→Bank deposit, Bank→Party move/atomic swap and Party-slot reorder.
- Added a polished native **BANK / BOXES** page with paged six-column storage, portraits/levels/KO state, selected Digimon stats, Party destination strip and atomic full-Party swaps. The existing Collection page is now presented as **PARTY** while the legacy enum/API name remains compatible. `Bank` is appended to the menu enum so existing serialized Scan/Care enum values are not shifted.
- Added a persistent polished six-slot **Party Quick Access** HUD. Press **Tab** to reveal the mouse and click Party slots/actions; Tab/Escape returns to gameplay. RECALL, OPEN PARTY and OPEN BANK are available directly from the interaction row.
- Added global Project Settings for Party capacity, Bank capacity, Bank page size, combat-switch policy, Party Quick Access widget/default input/master visibility and HUD safe offset.
- Party/Bank mutations are server-validated and locked during active partner combat by default. Selecting a different active partner follows the same policy; projects can explicitly allow mid-combat switching.
- Scan & Materialization is storage-aware: new Digimon fill Party first and automatically go to Bank when Party is full; only a completely full Party+Bank rejects materialization. Owned-species counts include both tiers.

### Persistence / migration
- Advanced account SaveGame schema to **v4**. Older active collections migrate without truncation: the previous active partner is retained/promoted when needed, remaining legacy Digimon fill Party up to capacity, and overflow is moved into persistent Bank storage with GUID de-duplication. Current six-slot Party order is preserved on subsequent loads and existing Bank contents remain intact.
- Party and Bank remain private account state and use owner-only replication. Other players see only normal public world presentation such as the summoned partner actor.

### Documentation
- Added `Docs/SETUP_PARTY_BANK_STORAGE.md` and updated README, architecture, networking, roadmap, native UI setup, test plan, validation report and project config template.

## 0.11.1-alpha — Polished Player Camera Boom Zoom & Character-Safe Camera Collision

### Added / changed
- Added automatic local player camera boom zoom with **Mouse Wheel Up = zoom in** and **Mouse Wheel Down = zoom out** default bindings.
- Added Project Settings camera controls for master enable, default input, default/min/max boom length, wheel step and interpolation speed.
- Added Blueprint camera APIs on `ADMFPlayerAvatarCharacter`: `AddCameraZoomInput`, `SetCameraZoomDistance`, `GetCameraZoomDistance`, `ResetCameraZoom` and `RefreshCameraCollisionPolicy`.
- Added the global **Ignore Players And Digimon For Camera Collision** policy. Player and Digimon primitive components ignore only `ECC_Camera`, preventing characters from retracting a third-person spring arm while preserving Pawn, Visibility, combat and interaction collision.
- The framework spring arm continues collision-testing against `ECC_Camera`, so walls/level geometry still retract the camera normally.
- Camera distance remains entirely client-local and creates no RPC, replicated property or SaveGame state.

### Documentation
- Added `Docs/SETUP_PLAYER_CAMERA_ZOOM.md` and updated README, architecture, networking, roadmap, test plan, validation report and project config template.

## 0.11.0-alpha — Polished Global Music Director

### Added
- Added `UDMFMusicSubsystem`, an automatic GameInstance-lifetime music director for Frontend/Main Menu, Open World exploration and local Battle presentation.
- Added Project Settings → `Audio → Music` with a global enable switch, Frontend/Open World/Battle `USoundBase` assets, master/per-state volume controls, crossfade duration, battle release delay, automatic replay and a throttled state-evaluation interval.
- Music assets are normal `USoundBase` references, so projects may assign Sound Cues, MetaSounds exposed as compatible sound assets, or Sound Waves according to their content pipeline.
- Added Blueprint-accessible current music state, local state-change delegate, immediate refresh and temporary runtime suppression for cinematics/project-owned presentation.

### Automatic state flow / polish
- The configured `FrontendMap` resolves to Frontend music; `OpenWorldMap` resolves to exploration music, with framework GameMode/PlayerController fallbacks for compatible custom map setups.
- Battle music is driven from the local active partner's **existing replicated authoritative CombatComponent state** and activates only for `Chasing`, `Attacking` or `Recovering`; simply selecting a command target does not trigger battle music.
- A configurable battle-release delay keeps the battle mix stable through short replicated state gaps and the final recovery beat before returning to Open World music.
- State changes crossfade through persistent 2D AudioComponents. Frontend music can therefore remain alive across the map-load boundary and transition into Open World music rather than cutting abruptly.
- If Battle music is unassigned, the system gracefully keeps/falls back to Open World music instead of forcing silence.
- `Automatically Loop Music` restarts a configured track at its natural end; internally looping Sound Cues remain continuously playing and require no special handling.

### Networking / preserved systems
- Music is presentation-only and **adds no RPCs or replicated properties**. Each player chooses their own soundtrack locally from replicated gameplay truth; one player's battle does not force every other client into Battle music.
- Dedicated servers do not create/render music AudioComponents.
- v0.10.4 player footsteps, configurable hosting, WORLD chat, nameplates, Care, Scan/Materialization, combat, player skins and persistence are preserved.
- Added `Docs/SETUP_GLOBAL_MUSIC.md` and updated README, architecture, networking contract, roadmap, test plan, validation report and project config template.

## 0.10.4-alpha — Automatic Replicated Player Footsteps

### Added
- Added automatic **player-avatar-only** footsteps to `ADMFPlayerAvatarCharacter`; Digimon actors are intentionally untouched.
- Added Project Settings → `Player Avatar → Footsteps` with a master enable switch, global footstep audio asset, walk/sprint/crouch stride distances, minimum movement speed, volume and pitch controls.
- The single audio asset accepts `USoundBase`; a Sound Cue is recommended for sample randomization, pitch variation and authored attenuation.
- Footstep cadence is accumulated from grounded horizontal distance travelled rather than animation notifies, keeping the system compatible with different player skins, AnimBPs and custom/Enhanced Input movement.
- Footstep audio is emitted from the player capsule base, avoiding skeleton-specific foot-socket setup.

### Networking / presentation
- Authority independently generates observer footsteps and sends them through an **Unreliable NetMulticast** cosmetic event on the replicated player pawn.
- A remote owning client predicts its own local step for responsiveness and suppresses the returned multicast echo, preventing doubled audio.
- Dedicated servers generate observer events but do not render audio locally.
- No footstep state is persisted or replicated as durable gameplay data; a dropped cosmetic packet cannot affect movement, accounts or combat.

### Preserved / documentation
- World chat, nameplates, Care, Scan/Materialization, combat, frontend endpoint/Admin configuration, player skins and account persistence are unchanged.
- Added `Docs/SETUP_PLAYER_FOOTSTEPS.md` and updated README, architecture, networking contract, roadmap, native UI/setup notes, test plan, validation report and project config template.

## 0.10.3-alpha — Project-Configurable Admin Hosting Password

### Added / changed
- Added **Project Settings → Digimon MMO Framework → Networking → Admin Hosting → Set Admin Hosting Password** so projects can replace the Admin `Host & Play` passphrase without editing plugin C++.
- The Project Settings field is an editor-only password setter: entering a new 4-128 character value immediately hashes it, clears the plaintext field and persists only `AdminHostingPasswordDigest` to `DefaultGame.ini`.
- The previous one-way Admin digest remains the default value for upgrade compatibility, so existing v0.10.2 projects keep their current Admin unlock behavior until the developer deliberately sets a replacement password.
- `UDMFSessionSubsystem::UnlockAdmin` now reads the configured digest from `UDMFFrameworkSettings`; the candidate password is hashed locally and compared against that digest. The raw configured password never enters session state, network travel options, account persistence or replicated data.

### Safety / deployment notes
- The Admin password remains a **local frontend hosting gate**, not remote server authentication. It controls access to `Host & Play`; server account validation and Unreal network authority remain separate systems.
- The persisted digest is intentionally hidden from normal Project Settings editing. A malformed digest fails closed with a configuration guidance message instead of silently bypassing the gate.
- Server endpoint configuration, world chat, nameplates, Care, Scan/Materialization, combat, accounts and persistence are unchanged.

### Documentation
- Added `Docs/SETUP_ADMIN_HOSTING.md` and updated README, server-endpoint setup, architecture, networking, polished native UI notes, roadmap, test plan, validation report and config template.

## 0.10.2-alpha — Project-Configurable Server Endpoint

### Added / changed
- Replaced the source-encoded regular-player hostname with **Project Settings → Digimon MMO Framework → Networking → Server Endpoint → Server Public Address / Hostname**.
- Preserved the previous `DigimonMMO3D.custom-gaming.net` value as the default so existing deployments retain their connection target after upgrade.
- `Join Game` now builds `host:GamePort` from project configuration; creators can switch LAN IP, public IPv4 address or DNS hostname without touching plugin C++.
- `Host & Play` performs the same endpoint preflight after the Admin gate and reports the configured player endpoint in local frontend status. The actual Unreal listen-server authority model is unchanged.

### Safety / validation
- Added strict endpoint sanitation: empty/oversized values and strings containing URL schemes, paths, embedded ports, spaces or Unreal travel-option characters are rejected before network travel.
- The endpoint field accepts only host/IP characters (letters, numbers, `.`, `-`, `_`); `GamePort` remains the separately clamped port setting.
- The setting does not alter credentials, Admin authorization, PlayerState identity, world chat, nameplates, Care, Scan/Materialization, combat or persistence.

### Documentation
- Added `Docs/SETUP_SERVER_ENDPOINT.md` and updated README, architecture, networking, polished native UI notes, roadmap, test plan, validation report and config template.

## 0.10.1-alpha — World Chat HUD Safe-Layout Fix

- Fixed the native WORLD chat overlapping the centered partner ability quick-access UI at normal PIE/game viewport sizes.
- Native chat now reserves a dedicated lower-left HUD lane above the combat quickbar (`176` Slate units by default), with a deliberate visual gutter between the two panels.
- Added Project Settings → `UI | World Chat | Presentation` → **World Chat Bottom Safe Offset** for projects that resize or replace the combat quickbar.
- If the native combat quickbar is disabled, the native chat automatically returns to the original compact `30`-unit bottom inset.
- No chat RPC, authority, history, anti-spam, account, combat, Care, Scan/Materialization or nameplate behavior was changed.

## 0.10.0-alpha — Polished Native MMO World Chat

### Added
- Added `UDMFWorldChatWidget`, a polished native lower-left WORLD chat HUD with compact bounded history, username-colored message rows, optional timestamps, an Enter-to-chat input row and Blueprint-reskinnable optional bindings/events.
- Added the default Enter input route plus Blueprint `Open/Close/Toggle World Chat Input`, `Send World Chat Message`, widget access, message-received delegate and local system-feedback path.
- Added bounded server session history so late joiners receive recent accepted chat without continuously replicating a global chat array.
- Added global world-chat enable/input/widget/history/presentation settings plus authoritative message-length, interval and burst-rate controls.

### Networking / authority
- Clients submit text only through their owned `DMFMMOPlayerController`; they cannot supply sender identity, timestamp or message type.
- The server sanitizes/clamps text, rate-limits each controller, stamps the public `APlayerState::PlayerName`, stores bounded history in `DMFMMOGameMode`, and delivers accepted payloads to connected owning controllers.
- Private `AuthenticatedUsername` remains owner-only and credential digests remain server-only; neither is exposed as replicated chat data.
- Chat history is session-only and does not alter account SaveGame schema or persistence.

### UI / integration
- Chat input temporarily owns keyboard focus and blocks movement/look/combat commands so typing cannot accidentally move the avatar or execute partner abilities.
- Care eating presentation closes active chat input and temporarily hides the chat panel with the HUD, restoring it afterward with history intact.
- Added `Docs/SETUP_WORLD_CHAT.md` and updated README, architecture, networking, roadmap, native UI setup, test plan, validation report and project-config template.

### Preserved
- v0.9.1 world nameplates, v0.8.1 Care/CustomDepth, Scan/Materialization, combat, avatar skins, persistence and existing MMO replication paths are additive and unchanged.
- UE5.8.1 compile plus host/remote-client PIE remains the authoritative runtime gate.

## 0.9.1-alpha — UE5.8 World Nameplate Widget-Class Compile Fix

### Fixed — UE5.8.1/MSVC nameplate fallback compilation
- Fixed the two UE5.8.1/MSVC `C2445` errors reported by the first v0.9.0 editor build in `DMFPlayerAvatarCharacter.cpp` and `DMFDigimonCharacter.cpp`.
- Removed the ambiguous conditional expressions that mixed `TSubclassOf<UDMFWorldNameplateWidget>` and raw `UClass*` fallback values. The configured subclass is now copied first and the native `UDMFWorldNameplateWidget::StaticClass()` fallback is assigned explicitly only when the configured class is empty.
- This is a compile-compatibility correction only; player/Digimon nameplate behavior, authority, replication, distance culling, styling and Blueprint replacement hooks are unchanged.

### Fixed — UE5.8 Care-prop network API deprecations
- Replaced direct writes to deprecated `AActor::NetUpdateFrequency` and `MinNetUpdateFrequency` with `SetNetUpdateFrequency()` / `SetMinNetUpdateFrequency()` in `DMFDigimonCarePropActor`.
- No Care replication frequency values or runtime behavior changed.

### Preserved / validation contract
- No existing source file, reflected function, RPC, Care feature, Scan/Materialization feature, combat feature or persistence path was removed.
- Clean UE5.8.1 Editor compilation remains the authoritative acceptance gate for this corrected source package.

## 0.9.0-alpha — Polished MMO Player & Digimon World Nameplates

### Added — automatic player username plates
- Added a native `DMFWorldNameplateWidget` and automatic Screen-space Widget Component to every `DMFPlayerAvatarCharacter`.
- The authoritative login path now mirrors the authenticated username into Unreal's normal public replicated `APlayerState::PlayerName`; the framework's `AuthenticatedUsername` remains owner-only and credential digests remain server-only.
- Remote players therefore see each other's usernames automatically without any custom nameplate RPC. The local player's own plate is hidden by default.

### Added — compact Digimon identity / combat plates
- Every `DMFDigimonCharacter`, including owned partners and Wild Digimon, automatically receives the compact native plate.
- Digimon presentation shows nickname/species name, level, stage, attribute, a slim HP bar and optional numeric HP.
- Added replicated `ReplicatedNickname` presentation state so future/custom Digimon nicknames can be visible to other players while wild Digimon naturally fall back to species DisplayName.
- HP is sourced from the already replicated combat vitals; no parallel health authority or gameplay RPC was introduced.

### Added — global configuration / reskinning
- Added `Enable World Nameplates` master control plus independent Player and Digimon enable switches.
- Added local-player visibility, player/Digimon max draw distances, capsule-relative height offsets, optional numeric Digimon HP and a throttled native refresh interval.
- Added separate Blueprint-replaceable Player and Digimon nameplate widget-class settings, both defaulting to the polished native fallback.
- Added Blueprint-callable `RefreshWorldNameplate()` to Player Avatar and Digimon actors and a `BP_OnNameplateRefreshed` presentation hook on the widget.
- Dedicated servers skip nameplate rendering.

### Documentation / regression contract
- Added `Docs/SETUP_WORLD_NAMEPLATES.md` and updated README, architecture, networking, roadmap, UI setup, test plan, validation report and config template.
- v0.8.1 Care/CustomDepth, v0.7 Scan/Materialization, combat, possession, skins, persistence and wild-spawner behavior remain additive regression contracts.

## 0.8.1-alpha — Care Prop CustomDepth Cel-Shading Integration

### Added / Fixed — Care presentation rendering
- `ADMFDigimonCarePropActor` now forces **Render CustomDepth Pass = true** for DigiMeat and replicated world poo, bringing both Care meshes under the same cel-shading/post-process contract already used by Digimon and player avatars.
- Added Blueprint-editable `CustomDepthStencilValue` (`0-255`, default `0`) and Blueprint-callable `RefreshFrameworkCustomDepth()` to the Care prop base.
- The CustomDepth invariant is reasserted during native construction, Actor construction, BeginPlay and every replicated Care presentation refresh, so species/global mesh resolution cannot disable cel shading.
- Blueprint children that add additional `UMeshComponent` presentation pieces are included by the refresh pass.
- CustomDepth remains strictly cosmetic/local presentation: no new replicated fields, RPCs, ownership rules, Hunger state, feeding timing or waste authority were added.
- Poo remains no-collision/no-overlap/no-navigation and server-lifespan cleaned exactly as in v0.8.0.

### Documentation / regression contract
- Updated README, Care setup, architecture, networking, roadmap, test plan and validation report for the Care-prop cel-shading contract.
- v0.8.0 server-authoritative Care behavior and all v0.7.1 Scan/Materialization regression contracts remain intact.

## 0.8.0-alpha — Virtual-Pet Care, DigiMeat Feeding & Replicated World Waste

### Added — persistent Care state
- Activated `FDMFDigimonCareState` as a server-maintained part of every owned Digimon instance, with Hunger, Happiness, Discipline, Care Mistakes, last-fed time, next-waste time and a UTC care-update timestamp.
- Hunger semantics are `0 = empty`, `100 = full`; new/materialized Digimon use the species `StartingHungerPercent`.
- Added deterministic real-time/offline Hunger decay using server UTC deltas and per-species `HungerDecayPercentPerHour`.
- Added a compatibility migration for untouched v0.7.x dormant care defaults so established saves begin full instead of being interpreted as newly starving.
- The project-level `Enable Care System` switch now freezes all Hunger/offline Care progression as well as UI/actions; autosave and partner-selection paths cannot decay Hunger behind a disabled Care system.
- Bumped the account SaveGame schema to **v3** to formally version persistent Care data while preserving v2 player-skin and earlier account fields.

### Added — unlimited DigiMeat feeding
- Added `ServerFeedActivePartnerUntilFull`; clients request only the action while the server validates ownership, summoned/healthy partner state, idle combat, species care enablement, Feeding Montage, DigiMeat mesh and configured skeletal hand socket.
- Added per-species DigiMeat mesh override, text-writable socket name, relative location/rotation/**scale**, Hunger-per-serving, montage play count/rate and feeding voice array.
- A replicated `DMFDigimonCarePropActor` attaches DigiMeat to the Digimon hand. The default serving plays the Feeding Montage **two complete times in sequence**, then applies Hunger, then repeats servings until 100%.
- The server temporarily disables partner combat automation/targeting while eating and restores the prior allowed auto-battle state when care ends. Combat/partner RPCs reject conflicting commands during a care sequence.

### Added — feeding presentation flow
- The owning PlayerController receives a reliable care-start event before the first Montage. It removes the Digimon Menu and quickbar, releases modal UI input, and lets the player watch the in-world eating sequence.
- A configurable presentation lead-in protects remote clients from seeing the first Montage behind the closing UI.
- When feeding finishes, the owning menu is recreated directly on `CARE` with refreshed replicated state.

### Added — digestion and world poop
- Successful feeding schedules a persistent server UTC waste time using species min/max delay.
- When due and the active partner is spawned, the server traces directly beneath the Digimon and creates a replicated world poo actor at the ground impact.
- Poo has species-configurable mesh/world scale/ground offset/lifetime and optional fart sounds. Collision, overlap generation and navigation influence are forcibly disabled, so players can walk through/stand in it.
- Poo actors self-clean with server lifespan; overdue waste remains pending while a partner is recalled/offline and resolves once it safely exists in-world.

### Added — polished CARE UI
- Added `CARE` as a first-class tab in the existing native Digimon Menu shell.
- Added active-partner portrait/meta, large Hunger meter, Happiness/Discipline meters, care-stat summary, unlimited DigiMeat rules, digestion/waste state and `FEED DIGIMEAT UNTIL FULL`.
- The UI is still Blueprintable/reskinnable and never owns gameplay authority.

### Blueprint/data exposure
- Added global Care settings for tick cadence, presentation lead-in/inter-serving timing, fallback presentation duration, default DigiMeat/Poo meshes and a Blueprint-replaceable replicated Care Prop Actor class.
- Added character `BP_OnCareFeedingCue` / `BP_OnCareWasteCue` presentation events plus care delegates/functions on the player Digimon component and `OpenCareUI` on the MMO PlayerController.

### Documentation / validation
- Added `Docs/SETUP_CARE_SYSTEM.md` and updated README, architecture, networking, roadmap, native UI setup, test plan, validation report and DefaultGame integration template.
- Unreal Engine/UnrealBuildTool is not present in the build environment used to assemble this source release; a clean UE5.8.1 compile and host + remote-client runtime test remain the authoritative acceptance gates.

## 0.7.1-alpha — UE5.8 Scan Toast Slot Shadow Compile Fix

### Fixed
- Fixed the UE5.8.1/MSVC `C4458` error in `DMFScanNotificationWidget.cpp`: the native Scan reward toast declared a local `UOverlaySlot* Slot`, which hides inherited `UWidget::Slot` when warnings are treated as errors.
- Renamed the local variable to `ToastOverlaySlot`; no runtime Scan/Materialization behavior or UI layout was changed.
- Audited the complete runtime source for additional local `Slot` declarations that could shadow `UWidget::Slot`; no other UI candidates remain.

### Preserved
- v0.7.0 Scan Data persistence, materialization, tabbed Digimon Menu, scan reward HUD, v0.6.4 combat, multiplayer possession, wild spawning/retaliation and the polished native UI remain intact.
- UE5.8.1 compile remains the authoritative acceptance gate.

## 0.7.0-alpha — Scan Data, Materialization & Tabbed Digimon Menu

### Added — persistent Scan Data loop
- Added server-authoritative species Scan Data rewards at the existing battle-victory boundary. By default only victories against `DMFWildDigimonCharacter` award Scan Data.
- Added per-species data-driven settings: `Scan Data Enabled`, `Battle Scan Percent Reward`, `Scan Percent Cap`, `Materialization Enabled`, and `Materialization Required Scan Percent`. Defaults are 20% per eligible victory, 100% cap, 100% requirement.
- Activated account persistence for the existing `FDMFAccountRecord::ScanData` field and added owner-only replication to `UDMFPlayerDigimonComponent`. Scan progress is private per account and survives logout/reconnect.
- Added Blueprint APIs/events for reading scan entries, querying progress/readiness/owned count, materializing, scan changes, reward presentation, and materialization results.

### Added — authoritative materialization
- Added `Server Materialize Digimon`. The server validates global/species enable state, required Scan Data, active Collection capacity, and a valid partner `WorldActorClass`. Wild actor classes are explicitly rejected as materialized partner classes.
- Successful materialization creates a new unique persistent `FDMFDigimonInstance` using species Base Stats, Starting Level, HP/SP and Starting Abilities/Basic Auto Attack, adds it to the Collection, subtracts the configured scan requirement, persists immediately, and returns the new instance GUID.
- Scan consumption is subtractive rather than hard-reset. A species with 200% cap and 100% requirement can therefore bank two materializations.

### Added — AAA-style native Scan/Materialize presentation
- Reworked the polished Digimon Collection into a shared **DIGIMON MENU** shell with `COLLECTION` and `SCAN & MATERIALIZE` tabs, leaving the presentation architecture ready for future Bank, Party, Digivolution and Care tabs.
- Added a portrait-card Scan Database with progress readouts, selection states and `READY` badges. Species remain in the database after materialization even when their current Scan Data returns to 0%.
- Added a selected-species Materialization Terminal with portrait, Stage/Attribute/starting level, progress bar, scan cap, threshold, per-victory reward, owned count, Collection occupancy, description and server-backed Materialize button.
- Added a polished owner-only native Scan reward toast showing species portrait, `+X%`, new total, progress bar and `MATERIALIZATION READY` callout.
- Added `Open Scan Materialize UI` plus future-facing `Open/Close/Toggle Digimon Menu UI` Blueprint aliases while preserving the existing Inventory UI calls and default `I` key.

### Preserved
- v0.6.4 repeat-safe buffered ability execution, v0.6.3 capsule-aware melee reach, v0.6.2 replicated target-facing, v0.6.1 multiplayer possession recovery, v0.6.0 polished native UI, v0.5.5 passive retaliation/death-pose behavior, wild spawning, healer, player skins and account authority remain intact.
- UE5.8.1 compile and multiplayer runtime testing remain the authoritative acceptance gates.

## 0.6.4-alpha — Repeat-Safe Ability Input Buffer & Cooldown Recovery

### Fixed
- Fixed the manual ability lifecycle where a quick-slot press made while the previous attack was still `Attacking`, `Recovering`, or cooling down was silently discarded. This was most visible on slot 1/SP-cost attacks as “works once, then stops responding.”
- Added a server-authoritative latest-command input buffer. A valid ability press is retained while the partner is recovering, cooling down, chasing, or turning and executes automatically once every authoritative gate is legal.
- Queued commands are no longer deleted merely because cooldown is still active; cooldown is a transient wait state, not a command failure.
- `FinishRecovery()` now immediately services a buffered command instead of always waiting for another automation interval.
- Ability execution no longer clears the pending command before `TryExecuteAbilityById()` succeeds, preventing transient facing/state races from losing input.
- Expired cooldown entries are pruned authoritatively and replicated away, preventing stale cooldown state from accumulating.
- Server cooldown validation now uses the authoritative world clock directly; clients continue using synchronized GameState server time for HUD countdown presentation.
- Preserved capsule edge-to-edge reach from v0.6.3, so short-range melee and SP-cost reliability are fixed together rather than by weakening ability data.

### Preserved
- SP is deducted exactly once and only when an ability actually starts. Insufficient-SP commands are rejected rather than queued because the current framework has no automatic SP regeneration.
- Latest input wins: issuing another valid slot command while one is buffered intentionally replaces the previous buffered command.
- v0.6.3 capsule-aware melee reach, v0.6.2 target-facing, v0.6.1 multiplayer possession, v0.6.0 polished native UI, and v0.5.5 passive retaliation/death-pose behavior remain intact.
- UE5.8.1 compile/runtime testing remains the authoritative acceptance gate.

## 0.6.3-alpha — Reliable Ability Execution & Melee Reach

### Fixed
- Corrected a combat-range deadlock where short-range abilities could never reach the server execution gate even though longer-range abilities worked.
- Replaced center-to-center ability range checks with capsule edge-to-edge horizontal range checks across validation, queued commands, auto/retaliation attacks, and impact-time validation.
- Reworked AI ability move acceptance to account for both Digimon capsule radii and disabled `StopOnOverlap` double-radius behavior.
- Normalized SP cost validation/deduction through one non-negative server helper; paid and free abilities now use the same path and SP is only deducted after all execution gates pass.
- Hardened combat-facing against AI controller yaw fighting server turn-in-place rotation.

### Preserved
- v0.6.2 replicated target-facing and queued command behavior.
- v0.6.1 late-join avatar possession recovery.
- v0.6.0 polished native UI.
- v0.5.5 passive-until-attacked retaliation and deterministic defeated-pose contract.

## 0.6.2-alpha — Replicated Combat Target Facing

### Added / polished
- Added shared combat target-facing to `DMFDigimonCharacter`, automatically covering player partners, wild Digimon and future framework Digimon subclasses.
- In-range attackers now stop movement and turn smoothly toward their authoritative combat target before attack execution. By default an attack waits until yaw error is within 8 degrees, so attack Montages no longer fire while the actor is facing sideways or backwards.
- Facing continues through the attack/recovery window so moving targets remain visually tracked, then the previous CharacterMovement rotation policy is restored. Chasing, following and wild roaming therefore retain their normal movement-driven orientation.
- Added Blueprint-exposed `Enable Combat Facing`, `Require Facing Before Attack`, `Combat Facing Turn Rate Degrees Per Second`, `Attack Facing Tolerance Degrees`, and advanced `Combat Facing Update Interval` settings.
- Added `Start Combat Facing Target`, `Stop Combat Facing Target`, `Is Facing Actor`, and `Get Combat Facing Target` Blueprint functions.
- Manual queued commands now remain queued while the server completes a short turn-in-place; SP and cooldown are not consumed until the facing gate passes.
- Proactive/retaliation auto combat uses the same gate, so both wild and partner attack presentation follows the same orientation contract.
- Actor yaw remains server-authoritative and uses normal Character movement replication instead of per-client combat rotation authority.

### Preserved
- v0.6.1 remote-client possession recovery, v0.6.0 polished UI, v0.5.5 passive retaliation/death pose behavior, spawner, persistence, healer and manual interaction paths remain intact.
- UE5.8.1 compile and host/client runtime testing remain the authoritative acceptance gate.

## 0.6.1-alpha — Late-Join Client Avatar Possession Recovery

### Fixed — remote clients no longer remain in DefaultPawn after character selection
- Fixed the multiplayer late-join path where a remote client could successfully select/save a character skin but remain locally controlling Unreal's fallback `DefaultPawn` instead of the configured `DMFPlayerAvatarCharacter` / Blueprint child.
- `ADMFMMOGameMode` now validates every started player after Unreal's normal restart path. A missing, spectator, DefaultPawn, or other non-framework pawn is authoritatively replaced with the configured DMF avatar class.
- `GetDefaultPawnClassForController` now enforces a DMF-compatible player pawn. If the OpenWorld GameMode's `DefaultPawnClass` is not derived from `DMFPlayerAvatarCharacter`, the framework logs the configuration error and falls back to the native DMF player avatar rather than allowing a remote player to stay in a flying DefaultPawn.
- Added a defensive explicit-spawn fallback if a project Blueprint overrides Unreal's pawn-class event and causes `RestartPlayer` to create the wrong pawn anyway. The recovered pawn is possessed by the authoritative PlayerController and uses the PlayerStart transform/collision-safe spawn path.
- Remote clients receive an explicit `ClientRestart` reassertion for the authoritative avatar even when the server already owns the correct pawn. This repairs stale client-side possession after frontend -> server network travel. The listen-host path is intentionally not forced through this remote-only reassertion.
- Remote `DMFMMOPlayerController` now runs a bounded late-join possession acknowledgement/retry safety net. It requests server validation until the local controller actually sees a `DMFPlayerAvatarCharacter`, then stops polling.
- Successful skin selection is now also an authoritative possession checkpoint. If `ApplySelectedSkinToCurrentPawn()` has no valid DMF avatar, the server recovers/possesses the avatar first and then reapplies the selected account skin.
- Starter confirmation also validates the player avatar before spawning the starter partner, preventing a partner from being anchored to an incorrect fallback pawn.

### Blueprint / diagnostics
- Added `Ensure Framework Player Avatar` and `Has Framework Player Avatar` on `DMFMMOGameMode`.
- Added `Server Ensure Framework Player Avatar` and `Is Framework Player Avatar Possessed` on `DMFMMOPlayerController`.
- Added `BP On Framework Player Avatar Recovered` to the GameMode for project diagnostics/presentation.

### Preserved
- v0.6.0 polished native UI is unchanged.
- v0.5.5 death-pose locking/passive retaliation, wild spawner, manual combat, healer, inventory, starter persistence, skin data and Custom Depth behavior are preserved.
- UE5.8.1 compile plus host/remote-client packaged testing remains the authoritative acceptance gate.

## 0.6.0-alpha — Polished Native MMO UI Suite

### Rebuilt native presentation
- Rebuilt every framework-native gameplay/frontend widget around one consistent dark MMO presentation language instead of the previous flat debug-style vertical lists. The native defaults now use centered/scaled panels, hierarchy, padding, accent states, status messaging, selection states and responsive down-scaling. Blueprint subclasses remain optional and may still replace presentation without replacing gameplay authority.
- Added a private shared native style layer (`DMFNativeUIStyle`) so login, roster, starter, player-skin and combat widgets use the same colors, text hierarchy, input treatment and button states.

### Digimon inventory / summon menu
- Replaced the text-list fallback with a real **6-column portrait slot grid**. Capacity follows `MaxActiveDigimonInventory` (30 by default), and unused capacity is rendered as explicit empty slots instead of disappearing.
- Occupied slots load `DMFDigimonSpeciesData::Portrait`, show species name + level, selectable highlighting, `SUMMONED` / `ACTIVE` / `KO` badges, and a grayscale defeated portrait treatment. Missing portraits use a clear `PORTRAIT NOT SET` fallback so data setup failures are obvious.
- Added a selected-Digimon profile panel with large portrait, species name, Stage/Attribute, persistent state, Level/EXP, HP/SP, STR/INT/DEF/SPD, ABI/CAM, species description, `SET ACTIVE / SUMMON`, and `RECALL ACTIVE PARTNER`. Existing server-authoritative summon/recall rules are unchanged.
- Existing Blueprint widget bindings remain optional for backward compatibility. The native grid uses new optional bindings while legacy `DigimonChoicesBox` remains supported.

### Starter selector
- Replaced the plain starter-name list with portrait cards showing Digimon name and Stage, selected-card highlighting, a large portrait/details panel, Stage/Attribute/Level metadata, starting stats and roster blurb/description.
- Confirm remains server-authoritative and preserves the existing one-time starter grant/persistence path.

### Character skin selector
- Replaced the full-width text rows with a portrait card grid and selected-character profile panel. `DMFPlayerSkinData::Portrait` now drives the native card/preview image automatically.
- Apply/close validation and persistent server-authoritative skin selection remain unchanged.

### Frontend login / main menu
- Rebuilt the frontend into a centered panel inspired by the project's polished menu references: title/subtitle hierarchy, styled credential fields, dedicated logged-in Play view, collapsible Admin hosting card, status panel, Join, Host & Play, Logout and Quit controls.
- Added `UDMFSessionSubsystem::Logout()` to clear staged local credentials/admin unlock cleanly and return the same native widget to login state. The hidden regular-player server target and admin authority/security model are unchanged.
- Preserved compatibility with older Blueprint children that still bind the pre-v0.6 join/admin controls without the new native section widgets.

### Combat quick bar
- Rebuilt the native combat HUD as a bottom-center translucent bar with partner vitals, highlighted command target, four framed ability cards, keyboard slot numbers, SP/cooldown state and `DMFDigimonAbilityData::Icon` support.

### Data / setup
- No new required asset type was introduced. Digimon inventory/starter icons use the existing `DMFDigimonSpeciesData::Portrait`; player skin cards use `DMFPlayerSkinData::Portrait`; ability cards use `DMFDigimonAbilityData::Icon`.
- Added `Docs/SETUP_POLISHED_NATIVE_UI.md` with exact portrait/icon setup and acceptance checks.

### Preserved / regression contract
- v0.5.5 deterministic defeated-pose and passive-until-attacked retaliation source is unchanged.
- Wild spawner, combat authority/damage, interaction/targeting, healer, account persistence, starter grant, player-skin application and Custom Depth gameplay paths are intentionally unchanged.
- UE5.8.1 compile/runtime verification remains the authoritative acceptance gate.

## 0.5.5-alpha — Deterministic Death Pose + Passive Wild Retaliation

### Fixed
- Replaced the v0.5.3/v0.5.4 timer-only defeated-pose hold with a deterministic Montage lifecycle lock. The framework now binds to the species Death Montage blend-out callback and freezes the skeletal evaluator **before** the AnimBP can blend back to Idle.
- Both player-owned and wild Digimon use the same `ADMFDigimonCharacter` defeat presentation, so both remain on the presented death pose while `CombatState == Defeated`; player partners remain until recall/revive and wild actors remain until their spawner corpse timer removes them.
- Added Montage-ended and normalized-time fallbacks for unusual/looping Death Montage assets. The lock pauses the Montage, pauses skeletal evaluation and sets mesh animation rate to zero; revive restores the pre-defeat animation state.
- Removed a client replication race from defeated animation startup: the reliable defeat multicast no longer starts the durable Death Montage before `CombatState=Defeated` may have replicated. `SetCombatState`/`OnRep_CombatState` are now the sole durable animation trigger, while the multicast remains cosmetic-only.
- Corrected wild combat semantics: `Auto Battle` now means **proactive aggression only**. Disabling it no longer makes a wild Digimon unable to defend itself.
- Added server-authoritative retaliation. With `Proactive Auto Battle (Aggressive)=false` and `Retaliate When Attacked=true`, a wild Digimon does not scan for or initiate combat, but immediately targets the hostile Digimon that actually damaged it and fights back using its normal basic auto attack.
- Retaliation obeys hostility validation, targetability, death state, cooldowns, range and the same spawn-home combat leash. If the aggressor dies, becomes invalid, or leaves the leash, retaliation ends and the wild Digimon returns to idle/free roaming.
- Spawner-managed wild Digimon now resolve proactive aggression and retaliation separately. `Allow Proactive Auto Battle` defaults false; `Allow Retaliation When Attacked` defaults true.
- Added replicated wild AI policy state plus server-authoritative `Set Wild Auto Battle Enabled` and `Set Wild Retaliation Enabled` Blueprint calls.

### Recommended MMO default
- `BP_Wild_<Species> -> Proactive Auto Battle (Aggressive) = false`
- `BP_Wild_<Species> -> Retaliate When Attacked = true`
- `DMFWildDigimonSpawner -> Allow Proactive Auto Battle = false`
- `DMFWildDigimonSpawner -> Allow Retaliation When Attacked = true`

### Compatibility
- Existing spawn-table rarity, level, population, roaming, leash, ground emergence and corpse-despawn behavior are preserved.
- `Hold Defeated Pose Until Revived Or Dismissed` remains serialized for existing Blueprints, but defeated pose holding is now a framework invariant when a valid species Death Montage exists.
- No intentional changes to player manual targeting/ability commands, healer behavior, Digimon inventory/summoning, persistence, player skins, combat damage balance or Custom Depth.
- UE5.8.1 compile/runtime verification remains the authoritative acceptance gate.

## 0.5.4-alpha — UE5.8 Death-Pose C4458 Compile Fix

### Fixed
- Fixed all three UE5.8.1 `C4458` diagnostics reported in `DMFDigimonCharacter.cpp` by renaming local `Mesh` variables to `DigimonMesh`; the local name had been hiding `ACharacter::Mesh` and the project treats that warning as a compile error.
- The affected functions are the v0.5.3 defeated-presentation apply, held-pose, and clear/revive paths. No death-presentation logic or authority behavior was removed.

### Preserved
- v0.5.3 persistent defeated-partner pose behavior remains unchanged: player partners stay defeated until recall/dismiss or authoritative revive; wild spawner corpse/despawn timing remains separate.
- v0.5.2 native no-cast interaction, v0.5.1 incomplete-type compiler fix, v0.5.0 manual combat/balance/healer/roster systems, v0.4.1 wild spawning, account persistence, player skins and Custom Depth remain intact.
- This is a compiler-feedback maintenance release; a fresh UE5.8.1 compile is the authoritative acceptance gate.

## 0.5.3-alpha — Persistent Defeated Partner Death-Pose Fix

### Fixed
- Fixed player-owned Digimon playing their species `DeathMontage` once and then blending back to the AnimBP locomotion/reference pose while still at `0 HP`.
- Defeated Digimon now enter a durable defeated presentation driven by replicated combat state. The Death Montage plays once, is frozen near its final pose, and remains visible until the actor is explicitly recalled/dismissed or the Digimon is revived.
- Defeat presentation is idempotent and is reapplied for late-joining/relevancy clients if `CombatState` and `SpeciesId` arrive in either replication order.
- Reviving through the healer/runtime vitals path clears the frozen pose, resumes skeletal animation, restores the cached movement mode/capsule collision state, and returns combat state to Idle.

### Added
- Added Blueprint-exposed defeated-presentation tuning on every `ADMFDigimonCharacter`: `Hold Defeated Pose Until Revived Or Dismissed`, `Defeated Pose Hold Normalized Time`, `Defeated Montage Play Rate`, `Disable Movement When Defeated`, and `Disable Capsule Collision When Defeated`.
- Added Blueprint-callable `Apply Defeated Presentation`, `Clear Defeated Presentation`, `Is Defeated Presentation Active`, plus `BP On Defeated Presentation Started/Cleared` cosmetic hooks.
- Added `Docs/SETUP_DEFEATED_PARTNER_PRESENTATION.md` with exact Death Montage, AnimBP Slot and runtime acceptance checks.

### Preserved
- Wild Digimon still use the spawner's existing defeated corpse/despawn timer; this release does not change rarity, proximity spawning, roaming, leash or ground emergence.
- v0.5.2 native interaction/targeting, v0.5.1 compiler fix, manual player combat, healer, roster/summon UI, persistence and Custom Depth behavior are preserved.

## 0.5.2-alpha — Native No-Cast Player Interaction / Digimon Targeting

### Added
- Added a framework-native interaction layer directly to `ADMFPlayerAvatarCharacter`. A Blueprint derived from the framework player can now call a single inherited `Interact` node; no `Get Controller`, `PlayerState`, Digimon, Wild Digimon or Healer cast chain is required.
- Added an optional ready-to-use native `E` binding (`bEnableNativeInteractionInput`, default `true`) that is independent from the legacy/native movement-input toggle. Projects using Enhanced Input can disable the native key and call the same `Interact` function from an Input Action.
- Added camera-forward line/sphere-sweep targeting with Blueprint-exposed interaction distance, sweep radius, trace channel, trace-complex flag, active-partner ignore and debug drawing.
- Added cast-free Actor-taking Blueprint wrappers: `InteractWithActor`, `InteractWithDigimon`, `InteractWithDigimonAndAttack`, `TargetDigimonFromActor`, `TargetAndAttackDigimonFromActor`, `InteractWithHealer`, `ClearDigimonTarget`, `CommandDigimonAbilitySlot`, `FindInteractionTarget`, `GetCurrentDigimonTarget` and prompt/result helpers.
- Added `EDMFPlayerInteractionType`, `OnInteractionResult`, `BP_OnDigimonInteracted` and `BP_OnUnhandledInteraction` for reskinnable UI feedback and project-specific interaction extensions without granting gameplay authority.
- Added a native query-only `InteractionCollision` sphere to `ADMFHealerActor`, with exposed collision radius and trace channel, so the standard player interaction trace can use a basic healer Blueprint even when its cosmetic mesh has no collision. The authoritative healer use radius remains a separate server-side check.
- Split legacy controller combat input toggles: Left-Mouse target selection now has its own setting and defaults off, while number-key ability slots can remain enabled. This makes the intended default flow `E / Interact -> select target`, then `1-4 -> command ability`.

### Behavior / authority
- Digimon interaction defaults to **target only** (`bAttackOnDigimonInteract=false`). It never re-enables autonomous player-partner combat. Optional target+attack mode can be enabled per player Blueprint or called explicitly with a zero-based quick-slot index.
- Local interaction performs discovery/presentation only. Digimon target and attack requests still enter through the owning `DMFMMOPlayerController` / `DMFPlayerDigimonComponent` server RPC path; healer requests still use the owning PlayerController and are revalidated for enabled state, distance and reuse delay on the server.
- Existing v0.5.1 compiler fix, v0.5.0 balance/manual-combat/healer/roster systems, v0.4.1 spawner placement fix, rarity/roaming/emergence, account persistence, player skins and Custom Depth behavior are preserved.

### Documentation
- Added `Docs/SETUP_PLAYER_INTERACTION_SYSTEM.md` with the exact no-cast Editor/Blueprint workflow and multiplayer acceptance sequence.


## 0.5.1-alpha — UE5.8 Incomplete-Type `IsValid` Compile Fix

### Fixed
- Fixed the UE5.8.1 `C2664` compiler failure in `UDMFPlayerDigimonComponent::IsActivePartnerSummoned`. The inline public-header implementation called `IsValid(ActivePartnerActor.Get())` while `ADMFDigimonCharacter` was only forward-declared, so MSVC could not establish the incomplete type's `UObject` inheritance at that point.
- Moved the function body into `DMFPlayerDigimonComponent.cpp`, where `Game/DMFDigimonCharacter.h` is fully included, preserving Unreal `IsValid()` semantics without adding a heavy public-header dependency or replacing the check with a weaker raw-null test.
- The eight compile failures reported across combat UI, inventory UI, healer, GameMode, PlayerController, PlayerState, starter UI and the Digimon component are all downstream appearances of this single header defect.

### Compatibility
- Compile-only maintenance release over v0.5.0. No intentional changes to partner combat balance, manual targeting/attack commands, healer behavior, Digimon roster/summon/recall UI, account persistence, wild spawning, rarity, roaming/leash, Custom Depth, login, player skins or starter onboarding.
- UE5.8.1 UHT already completed successfully in the supplied build log; a fresh UE5.8.1 compile remains the authoritative acceptance gate for this corrected source.

## 0.5.0-alpha — Manual Partner Combat / JRPG Battle Tuning / Healer / Roster UI

### Changed
- Player-owned partners now default to manual combat: no autonomous hostile acquisition or basic attacks unless `bPlayerPartnerAutoBattle` is explicitly enabled. Companion follow remains active while auto battle is disabled.
- Added global player-partner battle tuning (`PlayerPartnerOutgoingDamageMultiplier=1.50`, `PlayerPartnerIncomingDamageMultiplier=0.50`) without mutating persistent species stats.
- Wild Digimon expose per-class outgoing/incoming combat multipliers, defaulting to neutral `1.0`.

### Added
- Blueprint-callable manual command surface on `ADMFMMOPlayerController`, including atomic target+attack command routing through the owner-controlled server RPC path.
- `ADMFHealerActor`: replicated Blueprintable free healer with server range/reuse/availability validation, configurable HP/SP/defeated/bank restore policy, optional active-partner resummon, text fields and multicast cosmetic hook.
- Authoritative all-owned-Digimon heal operation with immediate account persistence.
- `UDMFDigimonInventoryWidget` native fallback plus `UDMFDigimonInventoryEntryButton`; custom Blueprint widgets can reskin the same authority path.
- Default `I` roster/menu toggle and Blueprint Open/Close/Toggle/Refresh controller calls.
- Server-authoritative Set Active/Summon and Recall operations. Recalling does not invalidate the selected persistent active-partner ID.
- Defeated partners are blocked from summoning until healed, with explicit owner feedback.

### Compatibility / architecture
- Built directly on v0.4.1 and preserves the fixed capsule-ground spawn transform, rarity selection, roaming/leash, synchronized ground emergence/despawn and Custom Depth behavior.
- No save-schema fields were removed or repurposed. Existing account records remain readable.
- Full drag/drop party/bank inventory UX remains a later phase; v0.5.0 provides the functional native roster/select/summon/recall surface needed for gameplay now.
- A fresh UE5.8.1 compile and host/client runtime test remain the authoritative acceptance gate.

## 0.4.1-alpha — Wild Spawner Capsule Placement / Runtime Diagnostics Fix

### Fixed
- Fixed the v0.4.0 wild-spawner placement bug that used the ground surface as the spawned `ACharacter` origin, which could bury the capsule in terrain and make collision-aware deferred spawning reject the actor.
- Spawn transforms now account for the selected Wild Blueprint class's actual scaled capsule half-height, so the capsule bottom is placed on the ground/NavMesh surface.

### Diagnostics
- Added authority-side activation logs with target population and configured-entry count.
- Added warnings for empty/ineligible weighted spawn pools.
- Promoted bounded placement failure to a visible warning with ground collision/NavMesh/minimum-player-distance guidance.
- Added successful-spawn logs containing actor, entry, location, level and rarity.

### Compatibility
- Preserves the v0.4.0 rarity/population/roaming/leash/emergence architecture and the v0.3.3 Custom Depth contract.
- No intentional changes to account persistence, frontend/login, player skins, starter selection or combat authority.

## 0.4.0-alpha — Server-Authoritative Proximity / Rarity Wild Digimon Spawner

### Added
- Added `ADMFWildDigimonSpawner`, a Blueprintable/replicated MMO population actor whose activation, spawn rolls, level rolls, respawn and despawn are authority-only.
- Added proximity activation/deactivation hysteresis, minimum nearby-player count, configurable timer cadence and unload grace period.
- Added random inclusive min/max target population and staggered spawn processing.
- Added `EDMFWildSpawnRarity` (`Common` through `Mythic`) with configurable per-spawner rarity base weights, per-entry multipliers and per-entry live caps.
- Added replicated wild `SpawnRarity`, `SpawnHomeLocation` and spawner-managed state for future UI/loot/scan/presentation integrations.
- Added species/class spawn entries with independent min/max level ranges and optional per-entry ground-emergence overrides.
- Added uniform circular placement, terrain tracing, optional NavMesh projection, minimum player separation, bounded placement retries and collision-aware deferred spawning.
- Added timer-driven idle free roaming using reachable NavMesh points around each Digimon's individual spawn home.
- Added synchronized replicated ground emergence and optional ground-sink unload presentation using server world time.
- Added transition safety: wild Digimon are non-targetable, movement-disabled and collision-suppressed while emerging/sinking; normal combat/roam resumes only after emergence completes.
- Added defeat-aware corpse lifetime and randomized replacement queue; replacement does not happen immediately on defeat.
- Added Blueprint spawner controls/events and wild ground-transition cosmetic hooks.
- Added `NavigationSystem` runtime module dependency.
- Added `Docs/SETUP_WILD_DIGIMON_SPAWNER.md`.

### Preserved
- Existing account/login/host/join, player-skin, starter, partner, persistence, combat, native UI and Custom Depth contracts are intentionally unchanged.
- Existing manually placed `DMFWildDigimonCharacter` actors remain supported; free roaming is opt-in for them and enabled by the new spawner at runtime.


## 0.3.3-alpha — Always-On Custom Depth / Cel-Shading Rendering Contract

### Added
- Framework-wide cel-shading rendering contract for all `ADMFPlayerAvatarCharacter` and `ADMFDigimonCharacter` mesh components. `Render CustomDepth Pass` is now automatically forced on rather than relying on per-Blueprint manual setup.
- Player avatars reassert Custom Depth during construction, BeginPlay and every skin application, so changing Tai/Matt/Mimi/etc. cannot silently drop the post-process cel-shading mask.
- Digimon reassert Custom Depth during construction, BeginPlay, authoritative instance initialization and replicated state refresh, covering owned partners, wild Digimon, NPC-derived Digimon and future ranked-combat derivatives.
- The enforcement scans every `UMeshComponent` owned by the framework actor, so Blueprint-added skeletal/static mesh accessories are included automatically at normal construction/BeginPlay time.
- Blueprint-callable `RefreshFrameworkCustomDepth()` is exposed on both player-avatar and Digimon bases for runtime-created/replaced mesh components.
- Blueprint-exposed `CustomDepthStencilValue` (0-255) is available on both framework character bases while Custom Depth rendering itself remains mandatory.

### Compatibility / architecture
- No account, host/join, player-skin selection, starter, Digimon inventory, combat authority, persistence, movement or UI behavior was intentionally changed.
- Custom Depth is a local render-state property and is applied independently on server/listen host and clients when their actor/skin presentation is constructed or refreshed; no extra replication bandwidth is required.
- Projects must still have Unreal's project-level Custom Depth pass enabled for a post-process material to sample it.
- Based directly on the user's validated v0.3.2 native-UI runtime test and requirement that all player skins and Digimon always participate in cel shading.

## 0.3.2-alpha — Native UI Bootstrap / Black MainMenu Fix

### Fixed
- Fixed the native frontend login/main-menu rendering as a pure C++ fallback. The framework previously constructed its `WidgetTree` from `NativeConstruct()`, which runs after the underlying Slate widget has already been constructed; the first rendered widget therefore had no native root and could produce a completely black MainMenu viewport.
- Native fallback UI trees are now created during `RebuildWidget()` before `Super::RebuildWidget()` consumes the tree.
- Applied the same lifecycle correction to the native Starter Selection, Player Skin Selection and Combat Quick Bar widgets so those screens do not inherit the same latent blank-UI defect.
- Hardened `ADMFFrontendHUD` startup with local-player resolution fallbacks, a short retry timer when the PlayerController is not ready on the first HUD frame, idempotent viewport insertion, explicit UI input focus/mouse cursor setup, teardown cleanup, and framework log diagnostics.

### Compatibility / architecture
- No authentication rules, host/join endpoint behavior, account persistence, player-skin authority, starter granting, Digimon inventory, combat math, replication ownership or save schema were intentionally changed.
- Existing Blueprint widget subclasses with a designer root continue to use their Blueprint widget tree; the native fallback is only synthesized when the widget has no root tree to render.
- Based directly on the user's runtime symptom after the v0.3.1 UE5.8.1 compile succeeded.

## 0.3.1-alpha — UE5.8 PlayerController Shadowing & Skin Blueprint Event Compile Fix

### Fixed
- Renamed all seven local `PlayerState` variables in `ADMFMMOPlayerController` to `DMFPlayerState`, resolving UE5.8.1/MSVC `C4458` diagnostics where the locals hid the inherited `AController::PlayerState` member under the project's warnings-as-errors policy.
- Normalized `UDMFPlayerSkinSelectionWidget::BP_OnPlayerSkinSelectionResult` to `bool, const FText&, UDMFPlayerSkinData*`, matching the signature emitted by UE5.8 UnrealHeaderTool for the BlueprintImplementableEvent.
- Resolves the downstream generated `C2511` / `C2352` errors in `DMFPlayerSkinSelectionWidget.gen.cpp` caused by the event declaration mismatch.

### Compatibility / architecture
- No avatar movement, skin authority, replication, account persistence, starter onboarding, Digimon inventory, partner spawning, combat, or UI flow semantics were intentionally changed.
- This is a compiler-feedback maintenance release based directly on the supplied UE5.8.1 UnrealBuildTool log.
- A fresh clean UE5.8.1 compile remains the authoritative acceptance gate.

## 0.3.0-alpha — Replicated Third-Person Player Avatar & Skin Framework

### Added
- Ready-to-use `ADMFPlayerAvatarCharacter` as the default MMO pawn: replicated Character movement, third-person spring-arm camera, follow camera, WASD/mouse/gamepad fallback controls, jump, crouch and server-synchronized sprint state.
- Blueprint-callable movement/look/sprint functions and exposed camera/movement tuning for derived Blueprint player characters.
- `UDMFPlayerSkinData` Primary Data Assets containing stable persistent IDs, display metadata, skeletal mesh, Animation Blueprint class, mesh transform, material overrides and optional portrait.
- Replicated `UDMFPlayerAvatarComponent` on `ADMFPlayerState` for server-authoritative skin selection, persistence, all-client visual replication and admin reset support.
- `UDMFPlayerSkinSelectionWidget` plus native entry buttons and a complete native fallback UI.
- Automatic Asset Manager discovery of every enabled `DMFPlayerSkin`; no separate hard-coded player-skin roster is required.
- First-time avatar selection is configurable and, when required, takes UI priority before Starter Digimon selection.
- Gameplay wardrobe access through default `F6` plus Blueprint-callable Open/Close/Toggle/Refresh controller functions.
- Persistent `SelectedPlayerSkinId` in the account record and SaveGame schema v2 migration behavior.
- Player skin Asset Manager `AlwaysCook` project-config template entry.
- Dedicated `SETUP_PLAYER_AVATAR_SKINS.md` using the project's seven visible character folders (Izzy, Joe, Matt, Mimi, Sora, Tai, TK) as the setup example.

### Authority / multiplayer contract
- Skin changes never replace/repossess the authoritative pawn. The client only requests a registered Primary Asset ID; the server resolves and validates enabled state + assigned mesh, persists the accepted ID, and replicates it to all clients.
- Existing Digimon inventory, active partner, location, controller and combat ownership remain intact while appearance changes.
- Existing v0.2.x account data remains compatible; accounts without the new field follow the configured skin-onboarding policy.

## 0.2.2-alpha — UE5.8 TObjectPtr / RPC Signature Compile Fix

### Fixed
- Resolved UE5.8/MSVC `C2445` ambiguity where raw `ADMFDigimonCharacter*` request parameters were combined with replicated `TObjectPtr<ADMFDigimonCharacter>` targets in conditional expressions. The three affected fallback paths now explicitly unwrap the `TObjectPtr` with `.Get()`.
- Corrected the owner-client starter result RPC declaration and implementation to the UE5.8 UHT-normalized signature: `bool`, `const FText&`, `FGuid`.
- Resolves the follow-on generated `C2511`/`C2352` errors emitted from `DMFPlayerDigimonComponent.gen.cpp` by the mismatched RPC declaration.

### Compatibility / architecture
- No gameplay rules, replication ownership, persistence schema, combat math, command queue behavior, starter eligibility, or Blueprint-facing system intent was changed.
- This is a compile-compatibility maintenance release based directly on the supplied UE5.8.1 compiler output.
- A fresh UE5.8 rebuild is still required to expose any additional diagnostics that were previously masked by these errors.

## 0.2.1-alpha — UE5.8 Primary Asset Include Compatibility Fix

### Fixed
- Corrected all framework references from the obsolete `Engine/PrimaryAssetId.h` include path to UE5.8's `UObject/PrimaryAssetId.h`.
- Fix applied centrally to `DMFTypes.h` and both starter-selection UI headers that directly referenced `FPrimaryAssetId`.
- Resolves every `fatal error C1083` reported in the supplied UE5.8.1 build log.

### Compatibility / architecture
- No gameplay behavior, replicated state layout, persistence schema, starter onboarding contract, combat authority model, or Blueprint API was intentionally changed.
- UE5.8.1 UnrealHeaderTool had already completed successfully in the supplied build; this release targets the subsequent C++ include failure.
- A new Editor rebuild remains required because the missing include prevented the compiler from reaching later translation-unit diagnostics.


## 0.2.0-alpha — Server-Authoritative Real-Time Combat Foundation

### Added
- `UDMFDigimonAbilityData` Primary Data Asset with SP cost, cooldown, timing, range, damage scaling and presentation inputs.
- Replicated `UDMFDigimonCombatComponent` shared by owned, wild and NPC Digimon.
- Server-side target/range/SP/cooldown/damage validation and defeat processing.
- Auto acquisition, AI chase, basic auto attacks and player-partner follow behavior.
- Server-authoritative queued player abilities that chase out-of-range targets and revalidate before execution.
- Configurable server command-rate guard for quick-slot RPC bursts.
- Configurable queued-command timeout plus self/target leash enforcement for commanded chases.
- `ADMFWildDigimonCharacter` for ready-to-place 3D real-time encounters.
- Four-slot native `UDMFCombatQuickBarWidget`, replicated cooldown feedback and cursor target-selection helper.
- Optional out-of-box Left Mouse target selection plus 1–4 quick-slot input bindings.
- Framework Digimon capsules explicitly support Visibility target traces so the native target helper does not depend on project collision-preset luck.
- Owner-routed combat command RPCs through `UDMFPlayerDigimonComponent`.
- Change-aware persistent battle HP/SP mirroring, periodic account autosave, and immediate persistence on active-partner defeat.
- Authoritative EXP/money victory rewards with a single owning-client reward notification path (including listen-host duplicate-event protection).
- Replicated winner and defeated presentation cues, including configured Win/Death montages.
- Combat delegates and Blueprint presentation hooks.
- Asset Manager cook rule for `DMFDigimonAbility`.

### Compatibility / architecture
- Preserves v0.1.0 account, starter, inventory and partner persistence contracts.
- Existing species Attack1/Attack2 montage + Cascade/Niagara fields remain usable as slot presentation fallbacks.
- Gameplay state is server authoritative; multicast RPCs are cosmetic only.


## 0.1.0-alpha — Starter Replication Foundation

### Added
- UE5.8 runtime plugin skeleton and module.
- Multiplayer-only MMO gameplay GameMode.
- Native frontend login/main-menu UI and frontend HUD/GameMode.
- Native network/travel failure reporting back into the frontend status UI, with last-status retention across frontend widget reconstruction.
- Login/admin plaintext entry fields are cleared immediately after credential hashing/validation attempts.
- Fixed regular-user host routing and admin-only listen-host flow.
- Server-side account validation/auto-registration and SaveGame-backed account persistence.
- Server-only credential copy in PlayerState; credential digest is never replicated to clients.
- Data-asset-driven Digimon species model.
- Persistent unique Digimon instance model.
- Cyber Sleuth-style core stat vocabulary and distributable attribute-point storage.
- Digivolution rule data with level and optional stat gates.
- Attack/Death/Feeding/Interact/Win montage asset inputs.
- Attack 1/2 Cascade VFX inputs and optional Niagara counterparts.
- Voice sound inputs.
- Owner-only replicated Fast Array Digimon inventory.
- Active partner state and replicated 3D partner actor base.
- Starter roster Primary Data Asset.
- Native starter choice UI and Blueprint preview hook.
- Server-authoritative one-time starter selection validation.
- Immediate starter persistence and partner spawning.
- Returning-account partner spawning moved to `HandleStartingNewPlayer_Implementation` after the normal player-start flow for more deterministic pawn availability.
- General Primary Asset Manager species resolution with starter-roster fallback.
- Packaged-build Asset Manager/cook integration template for `DMFDigimonSpecies` and `DMFStarterRoster`.
- Corrected new-account onboarding event semantics after `PreLogin` auto-registration.
- Added authoritative starter success/rejection feedback to the owning client so native/custom selection UIs recover cleanly from validation failures.
- Added a server-only Blueprint starter-onboarding reset hook for administration/support testing.
- Persistence schema placeholders for banked Digimon, scan data, currency and F→S+ ranked battle progression.

### Architecture contract
- Gameplay mutations originate on the server.
- Clients request actions through narrow RPCs; authoritative state is replicated back.
- Persistent per-Digimon state is instance-based and keyed by GUID.
- Content tuning lives in Primary Data Assets rather than hard-coded species branches.
- Native UI is functional by default and may be reskinned/subclassed without replacing gameplay authority.
