# Digimon MMO Framework — UE5.8

**Version:** `0.21.0-alpha — Polished Replicated Item Vendor Exchange`

A source-first Unreal Engine 5.8 runtime plugin foundation for a multiplayer-only, server-authoritative, Blueprint-first Digimon MMORPG.

## New in v0.21.0-alpha — Polished Replicated Item Vendor Exchange

The framework now includes **`ADMFItemVendorActor`**, a placeable Blueprint-derivable item shop built in the same architectural style as the established Digimon Exchange. Each placed vendor owns a weighted item pool, randomized shared stock quantities, per-vendor pricing multipliers, BUY/SELL policy, interaction range and a server-owned stock-rotation schedule. The native **ITEM EXCHANGE** uses the same dark/navy, cyan and gold visual language as the Digimon vendor, with BUY/SELL tabs, item icons and descriptions, current BITS, synchronized stock countdown, owned/available quantities, explicit quantity controls (`-10 / -1 / +1 / +10 / MAX`) and two-step transaction confirmation. Blueprint subclasses can replace the mesh/presentation or widget class without taking gameplay authority away from C++.

**Stock is shared replicated world state.** The server alone selects items, rolls quantities, decrements purchased stock and performs timed rotations. `ReplicatedStock`, generation serial and next server rotation timestamp replicate through the vendor actor, so all relevant clients converge on the same StockIds, items, unit prices and remaining quantities. The actor has no Tick; only the server timer mutates stock, while the UI's one-second local header timer formats the replicated countdown. A purchase reserves shared stock before account mutation to prevent re-entrant/double purchases, and successful quantity changes are forced out through normal actor replication.

Item purchases are atomic against the existing v0.20 private bag: authority validates the selected stock GUID, requested quantity, BITS balance and **complete** stack capacity before committing. Matching partial stacks fill first and quantities larger than one stack automatically spill into new server-GUID stacks. If the whole requested quantity cannot fit, nothing is bought and no BITS are charged. Selling aggregates the player's owner-only stacks by item ID, removes the chosen quantity across stacks, credits BITS and persists once. **Key Items and Quest items are protected in both the vendor and player-component authority layers and can never be sold.** Prices come from the existing `UDMFItemData::SuggestedBuyPrice` / `SuggestedSellPrice` plus vendor tuning.

Only one additional reliable request/result pair is added (**55 → 57 RPC declarations**). The client never sends a trusted price, stock quantity, BITS value, stack mutation or sell payout. Account SaveGame remains **schema v9** because the vendor reuses the accepted v0.20 bag/economy format. See `Docs/SETUP_ITEM_VENDOR.md` for the complete editor setup and `Docs/TEST_PLAN.md` for v0.21.0 multiplayer acceptance.

## New in v0.20.0-alpha — Polished Player Item Inventory & Recovery Capsules

The shared native **DIGIMON MENU** now has a complete **ITEMS** page for each authenticated player. The left side is a persistent item-bag grid with authored icons, names and stack quantities; the right side presents the selected item's effect and a compact **ACTIVE PARTY** target selector with live HP/SP. The page follows the existing dark/navy, cyan and gold native UI language and remains Blueprint-reskinnable through optional bindings/events. `ADMFMMOPlayerController::OpenItemsUI()` can open the common menu directly on this page.

Items are authored as `UDMFItemData` Primary Assets rather than hard-coded capsule classes. The initial native effects are **Restore HP** and **Restore SP**, so the requested six recovery items are created entirely in content: Small / Medium / Large HP Capsule and Small / Medium / Large SP Capsule, each with its own icon, description, stack size and `RestoreAmount`. This same definition already carries category, sorting and optional suggested buy/sell pricing for later item shops. Authority-side `GrantItem`, `RemoveItem` and quantity queries provide clean hooks for future vendors, drops, quests, rewards, crafting or other Digimon systems.

The bag is durable private account state. `FDMFItemStack` entries are carried by one owner-only Fast Array on `UDMFPlayerDigimonComponent`, and account persistence advances **schema v8 → v9** with a backward-compatible empty bag for existing accounts. Using an item sends only the stack GUID and owned Digimon GUID. The server re-resolves the item definition/effect, validates ownership and current HP/SP, rejects full/illegal targets without consumption, consumes exactly one stack unit on success, updates Party/Bank state, persists immediately and synchronizes a summoned partner through its normal replicated combat vitals without resetting battle state. This adds two reliable RPC declarations (**53 → 55**) and no per-frame inventory networking.

See `Docs/SETUP_PLAYER_ITEM_INVENTORY.md` for the exact six-capsule Data Asset setup, Asset Manager scan rule, test grant workflow, native/Blueprint UI surface and future vendor integration notes.

## New in v0.19.3-alpha — Polished Combat Quickbar BITS HUD

The persistent native **combat ability quick-access HUD** now shows the owning player's current **BITS** balance in a compact gold account-currency capsule beside the world clock and target header. The presentation intentionally matches the Digimon Exchange terminology and number formatting (`BITS  1,234`) while preserving the existing four ability cards, partner HP/SP, target state and world-clock lane. The BITS readout remains available when no partner is summoned because currency belongs to the authenticated player account rather than the active Digimon.

The HUD reads the already-existing owner-only replicated `UDMFPlayerDigimonComponent::Money` through `GetMoney()`. Purchases, sales, battle rewards and other authoritative economy mutations therefore flow into the HUD automatically without a duplicate balance, client-authored currency, new RPC, or new replicated property. Project Settings → **UI → Combat Quick Access → Economy → Show Combat Quick Bar Bits** can hide only the native/optional BITS presentation; economy authority remains unchanged. Blueprint quickbar skins can bind the new optional `BitsText` field. The framework remains at **53 RPCs** and account persistence remains schema **v8**. See `Docs/SETUP_COMBAT_QUICK_BAR_BITS.md`.

## New in v0.19.2-alpha — Nearby Player Ignore Action Polish

Social → **FRIENDS & IGNORE → NEARBY PLAYERS** now provides the complete Friends/Ignore workflow without requiring a clickable world nameplate. Every non-ignored nearby player keeps the appropriate relationship action (**ADD FRIEND**, **ACCEPT**, **CANCEL**, or disabled **FRIEND**) and now also exposes a dedicated red **IGNORE** action in the same compact native row. Already ignored nearby players expose **UNIGNORE** directly.

Ignore/Unignore still uses the existing server-authoritative Social mutation and schema-v8 persistence path. Ignored players remain fully visible and replicated in the game world, while their authored WORLD-chat messages are filtered for the ignoring account and incompatible friendship/request state is cleaned using the established v0.19.0 transaction rules. No new RPCs, replicated proximity state or client-authored Ignore state were added: the framework remains at **53 RPCs**. v0.19.1 nearest-first discovery/radius behavior and the runtime-accepted Guild system are unchanged. See `Docs/SETUP_SOCIAL_SYSTEM.md`.

## New in v0.19.1-alpha — Nearby Player Friend Discovery

Social → **FRIENDS & IGNORE** now includes a dedicated **NEARBY PLAYERS** column so friendship discovery no longer depends on clicking a world nameplate. The owning client gathers already-replicated `ADMFPlayerAvatarCharacter` actors inside the globally configured radius, deduplicates by authenticated public player name, sorts the result by precise distance nearest-first, and refreshes the panel while it is open. Players automatically appear when they enter range and disappear when they leave it.

Each row shows the public username, rounded integer distance in metres and current relationship state. Available players expose **ADD FRIEND**; incoming requests expose **ACCEPT**; outgoing requests expose **CANCEL**; established friends and ignored accounts render stable non-action states. Sending/accepting/cancelling still uses the existing v0.19.0 server-authoritative Social mutation path and rollback-safe persistence—nearby discovery itself creates no new RPC or replicated state.

Project Settings → **UI → Social → Nearby Players** exposes **Nearby Player Friend Discovery Radius** (default **50 m**) and **Nearby Player List Refresh Interval** (default **0.5 s**). The list refresh is owner-local and reads normal replicated transforms, so changing its cadence does not create network polling. Existing nameplate actions remain available for projects that want them, while the native Social menu now provides a reliable mouse-driven discovery path even when nameplate hit testing is unavailable. Guild behavior, schema-v8 Social persistence and the **53-RPC** network contract are unchanged. See `Docs/SETUP_SOCIAL_SYSTEM.md`.

## New in v0.19.0-alpha — Persistent Social Friends, Ignore & Guilds

The shared native **DIGIMON MENU** now includes a polished **SOCIAL** top-level tab with its own extensible nested tab shell. **FRIENDS & IGNORE** is the default page on first open and **GUILD** is the second module. The complete feature is authenticated-account persistent and server-authoritative: clients request actions, while `ADMFMMOGameMode` resolves the acting identity from the authenticated PlayerState and commits cross-account/guild mutations through one rollback-safe SaveGame transaction. Account schema advances from **v7 → v8** with backward-compatible empty defaults for existing accounts.

Friends are added from the exact replicated player nameplate through a native WoW-style **PLAYER ACTIONS** menu. Requests queue in Social rather than spawning disruptive modal dialogs; incoming Accept/Decline and outgoing Cancel state persists coherently across relogs, friend removal is symmetric, and every accepted friend can independently enable an owner-local world tracker showing an integer distance in metres. The marker consumes already replicated actor transforms—there is no distance RPC or per-tick network traffic. The same nameplate menu provides Ignore/Unignore and, for guild owners, Invite to Guild.

Ignore is deliberately presentation-scoped: the ignored player remains fully visible and replicated in the world, while that sender's authored `Player` WORLD-chat messages are filtered from both live reliable delivery and session-history hydration for the ignoring account. Guilds provide persistent create/rename/disband, owner-controlled member removal, queued invitations, normal-member leave, a searchable server guild directory, and persistent join applications that can be reviewed after the owner comes back online. Project Settings exposes the Social master switch, nameplate context, reskinnable context/tracker widget classes, tracker offsets/reconciliation, action/snapshot throttling, friend/ignore/guild limits and bounded pending guild invite/application queues. Public guild-directory identity/member-count changes are pushed to authenticated online players as freshly built owner-specific snapshots so an already-open Guild page remains coherent. See `Docs/SETUP_SOCIAL_SYSTEM.md`.

Networking remains compact: four Social RPC declarations are added (**49 → 53**): owner snapshot request, one generic validated mutation transport, owner snapshot delivery and owner action result. Strongly named Blueprint wrappers keep game/UI code readable while preventing a large RPC surface. All v0.18.5 WORLD presence/audio, v0.18.4 server capacity, v0.18.3 vendor UI and v0.18.2 reconnect/persistence authority contracts remain intact.

## New in v0.18.5-alpha — Replicated World Chat Presence Announcements

The native **WORLD chat** now publishes authenticated player presence automatically. Every successful login or same-host relog emits `Username has joined the server.` from `ADMFMMOGameMode::PostLogin`; every authoritative logout emits `Username has left the server.` before Unreal removes the authenticated PlayerState. These are server-authored message types rather than client chat text, so a client cannot spoof another account joining/leaving. They use the existing reliable per-owner world-chat delivery and bounded session history, preserving the established no-replicated-array chat architecture.

The native chat gives presence events their own visual language: **joined usernames are bold green**, while a departure username and its `has left the server.` statement are **red**. `PlayerJoined` / `PlayerLeft` were appended to `EDMFWorldChatMessageType`, preserving the existing `Player` and `System` values and giving Blueprint chat skins an explicit event type.

Project Settings now exposes **UI → World Chat → Presence** controls, including an announcement master switch plus globally assigned **Player Joined Server Sound** and **Player Left Server Sound** assets, audio enable, volume and pitch. Live presence events play the configured 2D cue once on every connected recipient through the existing reliable client delivery. Historical messages never replay presence audio when a late client requests chat history. No new RPCs are required: the framework remains at **49 RPCs**, account SaveGame remains schema **v7**, and v0.18.4 server capacity plus all reconnect/persistence/gameplay authority is preserved. See `Docs/SETUP_WORLD_CHAT.md`.

## New in v0.18.4-alpha — Global Max Players Server Capacity

v0.18.4 adds a fully server-enforced **Global Maximum Players** deployment setting under **Project Settings → Game → Digimon MMO Framework → Networking → Server Capacity**. The default is **100** simultaneous gameplay players. On a listen server the host consumes one slot, so the default permits the host plus up to 99 remote players.

`Host & Play` seeds Unreal's native GameSession with the configured capacity when the gameplay world is created, and `ADMFMMOGameMode::PreLogin` reasserts the server-owned Project Settings value before every normal GameSession approval. Connections beyond the cap are therefore refused by Unreal's authoritative login path; a client cannot increase capacity with its own travel URL. Lowering the cap never ejects established players—it blocks new joins until occupancy falls below the configured limit. SaveGame schema remains v7 and the framework remains at **49 RPCs**. See `Docs/SETUP_SERVER_CAPACITY.md`.

## New in v0.18.3-alpha — Polished Digimon Vendor Native UI Layout Hardening

v0.18.3 is a presentation-focused hardening pass for the native **Digimon Exchange**. The BUY and SELL detail panels no longer compress the complete combat/progression and market-value readout into the remaining vertical space. The information area now has its own scroll region, natural-height text cards and pinned transaction controls, so long/high-progression Digimon remain clean and readable instead of overlapping the Buy/Sell button or Close control.

The stock/collection rows are also more deliberate: portraits preserve aspect ratio, rows have a stable minimum height, prices occupy a dedicated quote column, and SELL entries separate the `PARTY` / `BANK` source from the actual sale quote. The authored native window is roomier at 1280x780 but still scales down as one complete surface on smaller displays. This release is UI-only: vendor economy authority, stock/pricing, atomic purchases/sales, schema-v7 persistence and all **49 RPCs** are unchanged. See `Docs/SETUP_DIGIMON_VENDOR.md`.

## New in v0.18.2-alpha — Authenticated Reconnect Persistent Account Authority Fix

v0.18.2 fixes the remaining same-host-session reconnect regression for remote clients. The authoritative account record was already being written correctly to disk by v0.18.1, but `AGameMode` could retain a duplicated inactive `PlayerState` after disconnect and reassociate that stale in-memory object when the same client rejoined. That explained the observed loop: reconnecting while the host stayed open could show empty Party/Bank and reopen avatar onboarding, while restarting the host cleared Unreal's inactive-player cache and the exact same persisted account loaded correctly.

DMF now deliberately disables `AGameMode` inactive-PlayerState caching/reassociation for authenticated MMO players. `AddInactivePlayer` no longer duplicates a disconnected DMF PlayerState, `FindInactivePlayer` never substitutes engine-cached state, and reconnect always uses the authenticated `UDMFAccountPersistenceSubsystem` record initialized during `InitNewPlayer`. A post-login integrity check rehydrates from the same persistent account if the expected authoritative component initialization is ever absent. The v0.18.1 save-before-teardown transaction and orphan-partner cleanup are retained, so disconnect first commits the account, destroys the transient summoned partner, then reconnect reconstructs Party/Bank/avatar/partner from persistent server data. Schema remains v7 and RPC count remains 49.

## New in v0.18.1-alpha — Disconnect-Safe Account Persistence & Partner Cleanup Fix

v0.18.1 fixes a critical remote-client reconnect regression discovered in packaged internet play: an authenticated client could leave the server, leave its summoned partner actor behind, then reconnect to an account that appeared fresh (no Party/Bank and player-avatar selection required again). The disconnect path is now an explicit **save-once session finalization transaction** performed before Unreal tears down or inactivates the PlayerController/PlayerState/Pawn. The server synchronizes the live partner HP/SP into the persistent instance, merges Digimon + avatar + valid world-location state into the existing account record, saves synchronously, marks that session persistence-finalized, then disengages and destroys the transient summoned partner actor.

The Digimon component no longer blindly writes from `EndPlay` after a successful logout save. A new authoritative-initialization guard prevents a default or partially initialized PlayerState from ever overwriting an established account with empty runtime arrays. If the primary logout save fails, one guarded teardown retry remains available; if initialization was never completed, the framework preserves the last known persistent record rather than performing a destructive save. `DMFMMOPlayerController::EndPlay` also provides an idempotent authority-side fallback for unusual abrupt net-driver teardown ordering. No account data layout changes are required: schema remains **v7**, vendor economy data is preserved, and no new RPC is added.

## New in v0.18.0-alpha — Replicated Digimon Vendor Economy & Rotating Stock UI

> **UE5.8 compile-fix revision:** `DMFDigimonVendorWidget.h` now includes the complete `UButton` definition before declaring the native vendor-entry button subclass. This fixes the UE5.8 `C2504/C2027` base-class failure and its cascading `OnClicked` / `AddChild` / widget-conversion errors. The new vendor actor also uses the UE5.8 setter APIs for network update frequency instead of direct deprecated member access. No gameplay, RPC, persistence, pricing, stock-generation or transaction contract changed.

v0.18.0 adds a placeable, Blueprint-derivable **`DMFDigimonVendorActor`** for a real multiplayer Digimon economy. Each vendor owns its own weighted species pool, number of stock slots, per-species generation overrides, randomized min/max level, independent min/max natural HP/SP/combat-stat rolls, randomized Attribute Point investment, unspent points, ABI, CAM and current-level EXP, plus an independent min/max stock-rotation schedule. Stock is generated only on the server and replicated as immutable offer snapshots, so every nearby player sees the same globally available Digimon and concurrent purchases are resolved atomically by authority. Vendor actors remain zero-tick; rotation uses one sparse server timer and stock changes use ordinary replicated property updates.

Buying and selling use the existing persistent individual `FDMFDigimonInstance`, not disposable species records. Automatic market value rewards **level, lifetime server-authored battle EXP, HP/SP/combat stats, ABI, CAM, exact Attribute Points spent, unspent points and unique Digivolution forms visited**, with configurable stage multipliers, buy markup and sell payout. ABI is deliberately highly weighted so long-term Digivolution/De-Digivolution training can materially increase a collection Digimon's resale value. Account schema **v7** adds `LifetimeBattleExperience` and `TotalAttributePointsSpent`; older v6 individuals are conservatively reconstructed from their current progression during authoritative load, with a one-way per-account provenance marker preventing that legacy inference from ever being re-applied to newly generated high-level Digimon that legitimately have zero spent points. Purchases/sales persist immediately.

Interaction with a vendor opens a polished native **BUY / SELL tabbed market UI** showing Bits, stock-rotation countdown, portrait, stage/attribute, level, complete stats, ABI/CAM, battle EXP, Attribute Point training, Digivolution history, automatic market-value breakdown and the exact server offer/quote. Destructive/financial actions use a local two-step confirmation. Clients submit only vendor + transaction direction + server/owned GUID; **price, stock stats, ownership, money, range and storage are revalidated on the server**. The update adds one Server transaction RPC and one owner-only Client result RPC, taking the framework from 47 to 49 RPCs without client-authored economy state. See `Docs/SETUP_DIGIMON_VENDOR.md`.

## New in v0.17.3-alpha — Network-Smoothing-Compatible Replicated Swim Presentation Fix

v0.17.3 fixes the final multiplayer presentation defect in the native no-animation swim fallback: remote players could move through water correctly yet appear upright to other peers, and the first unaccepted direct-mesh proxy attempt could visibly shake on a listen server. The root cause is Unreal CharacterMovement **network smoothing owning the remote character mesh relative transform**. Writing a fallback rotation directly to that same `USkeletalMeshComponent` competes with `SmoothClientPosition`, so the engine repeatedly restores its cached mesh offset.

The framework now replicates only one compact server-authored `None / Surface / Underwater` presentation state and integrates the remote fallback with `ACharacter::CacheInitialMeshOffset`, the engine-supported runtime mesh-offset target used by CharacterMovement smoothing. Non-owning client proxies and listen-server views of remote autonomous clients therefore let CharacterMovement perform its normal interpolation **toward the horizontal swim offset** instead of fighting a second transform writer. The owning player keeps immediate overlap/depth prediction and the existing local fallback. No skeletal-mesh transform RPC, per-frame rotation replication, SaveGame field or movement-authority change is added; all 47 existing RPCs remain unchanged.

## New in v0.17.2-alpha — Persistent Water Reload State Reconstruction Fix

v0.17.2 closes the save/load edge case where an authenticated player could restore at a valid surface/underwater location but never re-enter the framework swimming state. The root cause was lifecycle timing: `TeleportTo` could place the pawn directly inside `DMFSwimmableWater` before Unreal delivered a usable `BeginOverlap`, leaving CharacterMovement in Falling and leaving the local underwater post-process/fog without an active water reference.

The server now performs an explicit **one-shot water-state reconstruction immediately after initial world-location restore**. It geometrically checks the current avatar transform against all enabled DMF water bounds, resolves the same priority rules used during ordinary overlaps, switches back into the established replicated 3D swimming movement path before the next gravity frame, resolves Surface/Underwater immediately, and clears stale movement velocity for restored underwater teleports. The authoritative water pointer/underwater state then replicate normally; owner-side correction is hardened for either property-arrival order, so the swim pose and local camera post-process/distance fog recover cleanly. No transient swimming flag or water actor pointer is serialized: account SaveGame remains schema v6. `Rebuild Swimming State From World` is Blueprint-callable for custom server teleport systems and is never run as a per-frame scan.

## New in v0.17.1-alpha — Polished Underwater Post-Process + Distance Fog Presentation

v0.17.1 adds the visual layer that completes the accepted v0.17.0 swimming system. Every **`DMFSwimmableWater`** now owns a replicated, Blueprint-authored underwater presentation profile: color tint/strength, saturation, contrast, gamma, exposure, vignette, subtle chromatic aberration, camera-waterline hysteresis, depth-response weight, blend speeds, a built-in **native exponential distance-fog layer**, priority and an optional project Post Process material. Different lakes/oceans can therefore have different underwater looks without changing the player class or requiring a global level PostProcessVolume.

The effect is driven by the **actual local third-person camera crossing the replicated water surface**, not simply by the character-origin underwater boolean. Near the surface the camera can remain above water while the avatar swims below it; the view stays clear until the camera itself submerges. Once underwater, the profile blends smoothly from a configurable shallow-water weight toward full strength as camera depth increases, then fades cleanly back out above the waterline. Built-in grading shapes the image while the new local exponential fog supplies real scene-distance extinction so distant terrain fades into the authored water color. An optional Post Process material can still add caustics/refraction/stylized distortion. Rendering remains local-only and adds no RPC, SaveGame state or client gameplay authority. See `Docs/SETUP_UNDERWATER_POST_PROCESS.md`.

## New in v0.17.0-alpha — Replicated Swimmable Water & Underwater Locomotion

v0.17.0 adds a ready-to-place **`DMFSwimmableWater`** actor: Blueprint-derivable, replicated, zero-tick, sized from one exposed X/Y surface value plus depth, with an automatically matched Pawn overlap volume and project-selectable water plane mesh/material. Authority owns the active water body while the owning client predicts the same local overlap for responsive entry; actual movement continues through Unreal `ACharacter`/CharacterMovement prediction and replication rather than a bespoke per-frame swim RPC.

`DMFPlayerAvatarCharacter` now supports **surface swimming and full underwater camera-directed swimming**. Forward input uses camera direction, camera-down Forward dives from the surface, underwater Forward follows pitch, Space ascends, C descends and Shift uses the water body's sprint-swim speed. A tunable surface assist keeps ordinary swimmers near the plane without fighting an intentional dive. Surface/Underwater uses replicated hysteresis state and exposes Blueprint calls/events for animation, audio, camera and post-process integration.

Projects without swim animations get a polished native fallback: the collision capsule remains upright/stable while **only the skeletal mesh** smoothly rotates flat/face-forward, so existing run locomotion can visually read as swimming. Rotation/location offsets and interpolation are Blueprint exposed and the fallback can be disabled when a real swim AnimBP is supplied. See `Docs/SETUP_SWIMMABLE_WATER.md`.

## New in v0.16.1-alpha — Replicated World Clock Quick-Access HUD

v0.16.1 completes the player-facing side of the accepted Day/Night world clock by integrating a compact **12-hour digital clock directly into the ability quick-access bar**. The native fallback displays `h:mm AM/PM` between the partner vitals and target state, with a small color-coded `DAY` / `NIGHT` status. It reads the same smooth `DMFDayNightSky` time reconstructed from the replicated server anchor, so a listen-server client sees the host's world time and Simulated-mode clients see the same accelerated persistent clock driving the sun and wild populations. No local PC clock is read by the HUD and no extra clock RPC is used.

`DMFDayNightSky` now exposes Blueprint-pure **`Get Formatted Time 12 Hour`** (optional seconds), while custom `DMFCombatQuickBarWidget` Blueprint children can bind optional `WorldClockText` and `WorldClockPhaseText` fields. Project Settings can independently hide the entire clock or only the Day/Night phase label. The native quickbar weak-caches the sky actor and reuses its existing 0.15-second local presentation timer, so the feature adds no per-frame UMG tick and no new replicated state. See `Docs/SETUP_WORLD_CLOCK_HUD.md`.

## New in v0.16.0-alpha — Replicated Persistent Day/Night World & Population System

**Latest presentation correction:** outer sky-dome materials now receive both the canonical `DMF_SunDirection` contract and conventional Unreal sky-sphere `Light direction` / `Sun height` solar parameters (configurable per actor). This keeps a material-authored visible sun disc moving with the authoritative native Sun Light in editor preview and runtime, without rotating the sky mesh/digital layer or adding network traffic.

v0.16.0 adds a Blueprint-derivable **`DMFDayNightSky`** that owns one authoritative MMO world clock and replicates sparse time anchors to every client. Designers can select **Host PC System Time** (listen servers follow the host machine's local clock; dedicated servers follow the server machine) or a **persistent accelerated Simulated / GTA-style clock**. Simulated time uses a separate server-only world-state save, resumes after restart/map reload, exposes `Is Day`, `Is Night`, current hours/day index and phase events to Blueprint, and never trusts a client clock. Clients locally interpolate between synchronized server-time anchors so celestial/material motion remains smooth without per-frame replication. The native sun uses the correct solar orientation (12:00 = sun overhead), and the placed actor previews automatically in the Unreal Editor: Simulated mode follows `Initial Simulated Time Hours` while Host-PC mode uses the editor machine clock, so day/night lighting and material parameters can be authored without entering PIE. The optional native sun/moon/SkyLight/SkyAtmosphere components and Blueprint presentation event make the actor useful out of the box while remaining replaceable by project sky logic. See `Docs/SETUP_DAY_NIGHT_SKY.md`.

The sky also includes a dedicated always-visible **Digital Inner Sky Layer** mesh/material contract for Digimon-style digital-world textures. Projects assign a translucent/unlit two-sided material plus `Digital Inner Layer Texture`; the framework pushes texture, opacity, tint, UV scale/pan, time, day-visual-alpha and sun-direction parameters into runtime MIDs. The texture layer stays enabled during Day and Night, and authored texture alpha reveals the sky behind it rather than replacing the background.

`DMFWildDigimonSpawner` can now remain on its exact legacy table or opt into **Day / Night Population Sets**. Day and Night each expose their own rarity weights and the same familiar spawn-entry array contract. The server reads the authoritative sky phase, retains the corrected two-stage rarity/species weighting, retires old-phase ambient Digimon through the existing ground-despawn presentation, lets already-engaged old-phase encounters finish by default, then staggers the new phase population through the existing queue. Empty phase tables can safely fall back to the legacy table. The current population phase itself replicates for Blueprint presentation/debugging, but clients never select time, rarity, species or level.

## New in v0.15.3-alpha — Canonical Species Stage Presentation Fix

v0.15.3 fixes evolution-stage text being able to fall back to internal serialized enum identifiers such as `BabyI` / `BabyII` in cooked/runtime UI. **`DMFDigimonSpeciesData::Stage` remains the single source of truth** for every species, but all framework-native presentation now routes that authored value through one canonical runtime formatter: `Fresh`, `In-Training`, `Rookie`, `Champion`, `Ultimate`, `Mega`, `Ultra`, `Armor`, `Hybrid`, or `Unknown`. This applies consistently to world nameplates, Starter Selection, Party/Bank details, Scan & Materialize, Care, DigiDex cards/search/filter labels, and Digivolution source/target/path metadata.

The underlying `EDMFDigimonStage` serialized value/order is intentionally unchanged, preserving all existing Species Data Assets, Blueprint pins and persisted data. The new Blueprint-pure `Get Digimon Stage Display Text` helper lets custom project UI use the same canonical stage terminology without depending on runtime enum metadata.

## New in v0.15.2-alpha — Native Return Home HUD & Authoritative Home Teleport

v0.15.2 extends the accepted v0.15.1 world-location system with a polished player-facing **HOME** action. The button is integrated directly into the persistent Party Quick Access bar, so it adds no permanent corner clutter: press **Tab**, the existing cursor/mouse interaction mode opens, and `HOME` appears beside `RECALL`, `OPEN PARTY` and `OPEN BANK`. Clicking it sends only an action request through the owned PlayerController; the client never supplies a transform. The server resolves the same enabled/highest-priority **`DMFNewPlayerStart`** used for first-login placement, collision-validates the teleport and immediately checkpoints the resulting v6 account location.

Return Home is treated as a clean encounter boundary. The player's movement is stopped, the summoned partner's command/combat target and durable battle latch are cleared without healing it or wiping cooldowns, hostile Digimon still targeting that partner are disengaged, and already-launched framework projectiles aimed at **or launched by** it are removed before the partner is repositioned beside the player using the normal `PartnerSpawnOffset`. A configurable server cooldown prevents request spam, and authority rejects the action during an active Care or Digivolution sequence so those transactions cannot be interrupted. On success the Tab interaction closes automatically and an owner-only native `DMFHomeTeleportNotificationWidget` displays **HOME • ARRIVED — Teleported to the Home spawn point**; failures such as a missing/blocked `DMFNewPlayerStart` show a clear `HOME • UNAVAILABLE` result. Custom HUDs can call `RequestReturnHome`, bind `OnHomeTeleportResult`, and assign a Blueprint child notification class without taking over destination or save authority. See `Docs/SETUP_RETURN_HOME_HUD.md`.

## New in v0.15.1-alpha — Persistent Player World Location & First-Login Spawn

v0.15.1 gives authenticated players a real MMO world-position lifecycle. Place a **`DMFNewPlayerStart`** in the Open World map: a genuinely new/onboarding account with no saved gameplay position uses that transform for its first login, while a returning account restores its own last server-saved location/rotation instead of starting over at the entry point. Multiple new-player starts may be authored with priorities, and the GameMode selection hook is Blueprint-overridable for future zone/shard rules.

Player position is part of the same server-authoritative account persistence transaction already used by the framework. The normal `Account Autosave Interval` checkpoints the possessed `DMFPlayerAvatarCharacter` transform, logout saves again, and the very first spawn is committed immediately so an early disconnect cannot repeat first-login placement. Save schema **v6** adds only the private `PlayerWorldLocation` record; clients never submit or replicate saved coordinates. Established pre-v0.15.1 accounts are not treated as new players: on their first v6 login they use the normal PlayerStart once, establish a checkpoint, and then restore normally on later logins. Returning-location restore happens before active-partner restoration, validates that the saved level matches the current gameplay map, rejects non-finite data, and falls back to Unreal's normal collision-safe `PlayerStart` if the old location cannot be used. See `Docs/SETUP_PLAYER_WORLD_LOCATION.md`.

## New in v0.15.0-alpha — Project-Selectable Frontend Background Layering & Bootstrap Polish

v0.15.0 now lets the framework own the **complete local frontend layer stack** instead of asking the Frontend Map Level Blueprint to race the login widget. Assign any project `UUserWidget` / Widget Blueprint under **Project Settings -> Digimon MMO Framework -> UI -> Frontend -> Frontend Background Widget Class**. `ADMFFrontendHUD` creates that background first for the local player, automatically places it **100 Z-order units below** the configured login/main-menu layer, then waits **Frontend UI Startup Delay Seconds** before creating the normal Digimon MMO login/play/admin widget above it. No Level Blueprint `Create Widget`, manual Z-order, or timing workaround is required.

The native fallback's old dark full-screen `FrontendBackdrop` remains **disabled by default**, so the selected project background is not tinted. The central Digimon MMO card keeps its existing navy/gold style, while authentication, Join Game, Admin unlock, Host & Play, travel and account authority are unchanged. Background creation is deliberately fail-safe: an invalid optional background can never block the trusted login flow. See `Docs/SETUP_FRONTEND_BACKGROUND_PRESENTATION.md`.

## New in v0.14.9-alpha — Attribute Point Spending & Digimon Menu Polish

v0.14.9 completes the Attribute Point loop introduced by leveling. Party and Bank Digimon can now spend earned points through compact native `+ HP / + SP / + STR / + INT / + DEF / + SPD` controls. Each click is only a request: the server revalidates ownership, remaining points and stat legality, spends exactly one persistent point, adds exactly +1 to the chosen stat, immediately saves the account, and refreshes a summoned partner's public replicated stats without respawn or combat reset. MaxHP/MaxSP preserve missing/spent resources; a defeated Digimon stays defeated. Custom Blueprint UI gets the same `EDMFDigimonAttributeStat`, eligibility query, server RPC and owner-only result delegate. See `Docs/SETUP_ATTRIBUTE_POINTS.md`.

The native Digimon Menu shell has also been rebalanced for the feature density now present across Party, Bank, Scan, DigiDex, Digivolution and Care. Its logical canvas is now **1240x900** under the existing ScaleToFit/DownOnly wrapper, oversized portrait/minimum-detail regions are tightened, and the modal window clips to its bounds as a final safety contract. The Party selected-Digimon column additionally uses one bounded detail-body `ScrollBox` below its fixed identity/portrait header, containing stats, EXP, Attribute Point controls, description and all Summon/Recall/Bank actions. Short or DPI-scaled viewports can therefore always scroll to every Party action instead of clipping the lower buttons below the modal, matching the robust scrolling behavior of the other tabs.

## New in v0.14.8-alpha — Owned Digimon Level Progression & Native XP UI

v0.14.8 turns the existing persisted Battle EXP field into a complete server-authoritative growth system. Battle victories still award EXP only through the authoritative active-partner reward path, but EXP is now consumed against real level thresholds instead of accumulating forever. One reward can cross multiple thresholds safely; each gained level applies the species' existing `HP/SP/STR/INT/DEF/SPD Per Level` growth, grants `Attribute Points Per Level`, preserves current damage/SP expenditure while increasing the new capacity, marks the owner-only Fast Array entry dirty, persists the result, and refreshes the summoned partner's public replicated Level/EXP/stats without resetting its combat target, cooldowns, recovery or encounter state.

Level requirements are species-owned and numeric—no CurveFloat asset is required. Every `DMFDigimonSpeciesData` directly exposes `Base Experience Required` and `Experience Growth Multiplier Per Level`. The requirement is `Base * Multiplier^(CurrentLevel - 1)`, so each species can have its own pacing with two simple Details-panel values (for example Base 100 / Multiplier 1.20 gives 100, 120, 144, 173...). `Max Level Override` remains optional, with Project Settings providing only the global default cap. Existing v0.14.7 accounts are normalized on authoritative hydration, so previously banked EXP can immediately produce the levels it had already earned; no SaveGame schema field is added or discarded.

The native Party and Bank inspection panels now show `EXP current / required` beside Level plus a real EXP progress bar (or `MAX` at cap) and the current unspent Attribute Point total. Battle EXP also drives a new owner-only, queued `DMFExperienceNotificationWidget`: a centered Fortnite-style animated EXP bar displays the exact gained EXP, advances through multi-level thresholds, and reveals a distinct gold `LEVEL UP! old → new` notification as the animated bar crosses its first earned threshold, with granted Attribute Points. The notification receives a dedicated immutable server-result snapshot, so animation is deterministic even when owner Fast Array replication and the client RPC arrive in either order. Blueprint children can reskin the widget and use separate EXP/Level-Up presentation events without gaining gameplay authority. See `Docs/SETUP_LEVEL_PROGRESSION.md`.

## New in v0.14.7-alpha — Wild / Auto-Battle Full Moveset Rotation Fix

v0.14.7 fixes autonomous enemy Digimon repeatedly using only one attack. The moves were already present in each Digimon's replicated runtime moveset, but the automation loop was hard-wired to resolve and execute only `BasicAutoAttack`, so `StartingAbilities` / the remaining `ReplicatedAbilityIds` were never selected by wild retaliation or proactive auto battle.

Autonomous combat now chooses from the **complete equipped ability moveset**. Every ability with `bEligibleForAutoBattle=true` can participate when the server confirms sufficient SP, cooldown readiness and a valid hostile target. Selection uses server-only **least-recently-used fairness**: untouched/oldest usable moves are preferred before already-used moves, while equally old candidates are randomized so the AI does not fall into a rigid slot-order script. As cooldowns expire, previously unavailable moves naturally return to the front of the rotation.

Mixed melee/ranged sets are handled deliberately. Once the server selects an ability, it keeps that move as a transient pending AI intent while the Digimon chases into **that move's own capsule-aware range**. It does not re-roll every automation tick, so short-range and long-range attacks can coexist without navigation thrashing. The pending intent/fairness history are server-only transient state: no RPC, replication, persistence or SaveGame schema was added. Manual player commands are unchanged and retain priority through the existing command queue.

## New in v0.14.6-alpha — Attack VFX / Enemy Marker CustomDepth Enforcement

v0.14.6 hardens combat presentation for projects that use CustomDepth-based post-process rendering. Every framework-owned runtime **attack particle component** is now forced to `Render CustomDepth Pass = true` as soon as it is created, covering direct ability Niagara/Cascade effects, projectile impact Niagara/Cascade effects, and the Niagara/Cascade visual components carried by replicated moving ability projectiles. Reusable projectile components reassert the flag whenever their replicated presentation definition is refreshed.

The owner-local **enemy target arrow above the selected Digimon's head** now follows the same rule for both Niagara and Cascade. CustomDepth is enabled on component construction, reapplied whenever Project Settings targeting assets are hot-refreshed, and reasserted immediately before marker activation. This is presentation-only: attack/damage authority, projectile replication, owner-only targeting privacy, marker visibility and network RPC contracts are unchanged.

## New in v0.14.5-alpha — Rarity-Weighted Spawn Selection Normalization Fix

v0.14.5 fixes a structural bias in `ADMFWildDigimonSpawner` rarity/species selection. Earlier builds calculated every eligible entry as `Rarity Base Weight * Selection Weight Multiplier` and rolled the entire table in one pass. That unintentionally counted the same rarity-tier base weight once **for every species in that tier**, so simply adding more Rookie or other species entries could make that tier dominate a smaller tier even when its configured rarity/entry weights were lower.

Selection is now a true two-stage server-authoritative roll. First, the spawner chooses one **currently eligible rarity tier** using `RarityWeights`; the number of species authored in that tier no longer changes the tier's probability. Second, it chooses one eligible species **inside the selected tier** using `Selection Weight Multiplier` as a relative within-tier weight. Disabled entries, zero-weight entries and entries at `Max Alive From Entry` remain excluded before both rolls.

This preserves all existing replicated wild actors, rarity values, population caps, respawn timing, placement, roaming and multiplayer authority. No RPCs, replicated properties or SaveGame fields are added. Existing Blueprint spawn tables require no migration; their `Rarity` and `Selection Weight Multiplier` fields now behave according to their intended tier/entry responsibilities. See `Docs/SETUP_WILD_DIGIMON_SPAWNER.md`.

## New in v0.14.4-alpha — Persistent Battle Music Encounter State Fix

v0.14.4 fixes Battle music dropping back to the Open World track during normal **manual combat pauses**. The original v0.11 music director correctly entered Battle when the active partner was `Chasing`, `Attacking` or `Recovering`, but those states describe the current action phase rather than the lifetime of the encounter. After an attack recovery finished, a manually commanded partner could legitimately return to `Idle` while the same hostile Digimon was still alive and targeted; after the short release delay the music therefore switched to exploration even though the battle had not ended.

`UDMFDigimonCombatComponent` now owns a dedicated **server-authoritative replicated battle-encounter latch**. A real chase/attack/recovery against a valid hostile target starts the encounter. Returning to `Idle` between ability-button presses deliberately does **not** clear it. Victory, local-partner defeat, authoritative target clear/disengage, healer/reset and other combat teardown paths clear it. `UDMFMusicSubsystem` reads this durable replicated encounter truth and keeps Battle music active until the encounter really ends, then applies the existing configurable release delay before crossfading back to Open World. Selecting a hostile target without ever entering combat still does not start Battle music.

Music itself remains client-local presentation: this adds **no music/audio RPCs**. The only new network state is one replicated combat boolean on each Digimon combat component, owned and mutated by authority, so Host and remote clients continue to hear their own independent encounter soundtrack. `Is Battle Encounter Active` is also Blueprint-readable for projects that need the same durable battle truth for presentation. See `Docs/SETUP_GLOBAL_MUSIC.md`.

## New in v0.14.3-alpha — Local Targeting Visibility Runtime Fix

v0.14.3 fixes the runtime visibility failure discovered during the first real targeting-marker setup test. The v0.14.2 presentation actor was already spawned only for the local framework PlayerController and never replicated, but its PaperSprite/Niagara/Cascade components also used Unreal's `Only Owner See` render filter. Depending on the active camera/view-owner chain, that redundant component-level filter could cull the local marker components for the same player who owned the presentation actor, resulting in the blue partner ring, hostile target ring and enemy arrow all being invisible even while target selection itself worked correctly.

The local targeting actor remains completely non-replicated and MMO-private, but its render components now use normal local-world visibility instead of `Only Owner See`. Because the actor exists only in that local player's world, another network player still cannot receive or render those markers. The presentation actor also now lazily reloads newly assigned targeting assets during PIE and is created even while the global targeting switch is disabled, allowing the Project Settings switch/assets to be changed during a running editor session without leaving the presentation permanently uninitialized.

No combat authority, command-target replication, projectile logic, Party/Bank state, SaveGame data or network RPC contract changed in this fix.

## New in v0.14.2-alpha — Polished Owner-Only Combat Targeting Visuals

Combat selection now has a first-class polished world presentation built specifically for MMO privacy. The locally owning player can see a configurable blue rotating `PaperSprite` ring beneath their own summoned active partner, a separate hostile/selected ring beneath their current command target, and a Niagara-preferred/Cascade-fallback down-arrow hovering above that target. Other players never see these markers unless they independently select the same Digimon through their own local combat state.

Both rings use independent world-Z rotation pivots so their source sprites stay flat on the floor while rotating cleanly. Defaults deliberately use different speeds/directions (`+28°/s` partner, `-42°/s` enemy), and optional capsule-radius adaptation keeps marker size sensible across tiny Fresh forms and very large Mega/Ultra Digimon. Ground offsets, sprite scales/orientation, translucent sort priority, arrow height/scale/rotation, Niagara/Cascade assets, and native hover bob are all exposed under **Project Settings → Combat → Targeting Visuals**.

The system adds no targeting RPC, replicated marker actor, or SaveGame state. A non-replicated `DMFTargetingPresentationActor` exists only for each local player controller and reads the existing owner-only `ActivePartnerActor` / `CommandTarget` state. Target selection, hostility validation, combat commands and damage authority therefore remain unchanged. See `Docs/SETUP_COMBAT_TARGETING_VISUALS.md` for exact setup using the supplied `CircleRing_T_Sprite`, hostile ring sprite and `NS_Icon2D_Arrow` assets.

## New in v0.14.1-alpha — Replicated Ability Projectiles & VFX Lifecycle Hardening

Combat abilities can now explicitly choose **Timed / Instant Impact** or **Replicated Projectile** execution. Projectile attacks such as fireballs, energy bolts and rockets no longer need to fake movement with a Niagara system spawned at an attack socket: the authoritative server launches a real replicated `DMFAbilityProjectileActor` from the configured socket, points its travel direction at the validated enemy, optionally homes toward a moving target, applies damage only when the projectile visibly reaches that target, then destroys the projectile and its attached VFX.

`DMFDigimonAbilityData` exposes projectile class, launch socket/offset, dedicated Niagara/Cascade/Static Mesh visuals, speed, homing + turn rate, target offset, impact radius, visual rotation/scale correction, hard maximum lifetime, impact Niagara/Cascade/Sound and impact-VFX cleanup lifetime. Leaving the projectile class empty uses the polished native projectile actor automatically; projects may assign a Blueprint subclass for additional cosmetic presentation without gaining damage authority. Existing ability Niagara/Cascade assets and the legacy species Attack1/Attack2 particle overrides remain valid fallbacks so current content can migrate without rebuilding every effect.

The original timed-impact path is also hardened: all native transient Niagara/Cascade attack cues now have a forced `Presentation VFX Lifetime Seconds` cleanup guard, including accidentally looping systems, and socket-origin cues are rotated toward the selected target with configurable visual rotation/scale offsets. Existing abilities remain Timed Impact by default, so v0.14.0 behavior is preserved until a designer opts an ability into Projectile execution. See `Docs/SETUP_ABILITY_PROJECTILES.md` for the full fireball/projectile workflow.

## New in v0.14.0-alpha — Polished Native DigiDex Species Encyclopedia

The shared `I` Digimon Menu now includes a full **DIGIDEX** encyclopedia for every `DMFDigimonSpeciesData` registered with Unreal's Asset Manager. It is designed as the permanent read-only species reference before large roster population begins: add a new species Data Asset under the recursively scanned `/Game/DigimonData` hierarchy and the species automatically becomes eligible to appear in DigiDex without hand-maintaining a second roster.

The native page uses the same navy/cyan/gold visual language as Party, Bank, Scan, Digivolution and Care. A fixed four-column browser presents aspect-safe portraits, registry numbering, Stage/Attribute, and live **OWNED / SCANNED / UNSCANNED** state. Each species can optionally author a stable `DigiDex Number` and can be excluded from the encyclopedia with `Show In DigiDex`; both are exposed directly on `DMFDigimonSpeciesData`, with safe automatic defaults. Players can search by species/stage/attribute/element and cycle Stage/Attribute filters. Selecting an entry opens a detailed dossier with Base Stats, starting level, battle rewards, Scan/Materialization values, starting moves, description, and authored previous/next Digivolution-family links.

DigiDex is intentionally **read-only**. There are no summon, recall, Party/Bank transfer, Care, Materialize or Digivolve buttons on this page, and the client never gains a new mutation path by opening it. Ownership/Scan badges reuse the existing owner-only replicated state; the species registry itself is static project content. No new RPCs, replicated properties or SaveGame fields are required.

The tab enum is appended rather than reordered, preserving all v0.13.1 serialized values. Native visual order is now **PARTY → BANK / BOXES → SCAN & MATERIALIZE → DIGIDEX → DIGIVOLUTION → CARE**. See `Docs/SETUP_DIGIDEX.md` for species-registration and authoring guidance.

## New in v0.13.1-alpha — Digivolution Owned-Roster UI Layout Fix

v0.13.1 is a focused presentation correction over the compiling v0.13.0 Digivolution milestone. The native **DIGIVOLUTION → OWNED DIGIMON • PARTY + BANK** browser no longer allows sparse `UniformGrid` rows to stretch fixed Party/Bank cards across the entire left panel. Cards are now centered at a consistent **132 × 166** footprint in a three-column roster, so one, two or six owned Digimon remain visually consistent.

Each Digivolution roster portrait now lives in its own **104 × 104 square viewport** behind a `ScaleBox` using `ScaleToFit` + `DownOnly`. Species artwork therefore preserves its source aspect ratio instead of being horizontally squashed when the grid has unused columns. PARTY/BANK identity and name/level presentation is separated into a fixed footer, while ACTIVE/KO badges remain attached to the portrait area. The roster stays inside the existing scroll region, so large Bank collections remain usable without compressing cards.

This patch changes **presentation only**. v0.13.0 Digivolution requirements, server authority, schema-v5 persistence, transformation presentation, Party/Bank ownership, Scan/Materialization, Care, healer, combat and networking behavior are unchanged.

## New in v0.13.0-alpha — Polished Replicated Digivolution

The framework now includes a complete persistent **Digivolution** system integrated directly into Party, Bank/Boxes, Care, combat, persistence and the shared native Digimon Menu. Every `DMFDigimonSpeciesData` can author one or more branching Digivolution paths to other species forms, with independent requirements for Level, ABI, CAM, STR/INT/DEF/SPD, Happiness, Discipline, Care Mistakes and optional account-money cost.

The new native **DIGIVOLUTION** tab browses the owner's Party + Bank, shows the selected current form and every configured outgoing path, presents each path as **READY** or **LOCKED** with its live requirement summary, previews the destination form, and routes confirmation through the owning server-authoritative Digimon component. Bank Digimon can evolve in-place when allowed; Party/Bank remain owner-only replicated and no client supplies trusted stats, cost or final form data.

A currently summoned active partner receives the full in-world treatment. The server locks conflicting combat/Care/storage commands, clears combat intent, sends an owner presentation-start event, and reliably multicasts a Niagara-preferred/Cascade-fallback transformation cue plus Sound Cue from the existing actor. With the default setting enabled the menu/HUD hides so the player can watch the transformation. At the end of the authoritative duration the server revalidates the path, commits the persistent form change, deducts any cost once, immediately saves the account, and replaces the partner actor using the destination species' `WorldActorClass`; normal replication shows the new form to other players.

Persistent Digimon identity is preserved across forms: instance GUID, nickname, Level/EXP, ABI/CAM, Care state and other individual progression remain attached to the same owned Digimon. Save schema is now **v5**, adding `OriginSpeciesId` and `DigivolutionHistory` with compatibility normalization for older accounts. Fresh/In-Training display names are also exposed cleanly in the existing Digimon stage enum. See `Docs/SETUP_DIGIVOLUTION.md` for authoring, presentation and host/client acceptance setup.

## New in v0.12.2-alpha — Polished Replicated Healer Treatment Presentation

The free server-authoritative `DMFHealerActor` now includes a complete native treatment presentation rig for static healer props such as futuristic medical capsules. A Blueprint-positionable **Healing Presentation Anchor** drives a pulsing green point light, a preferred Niagara healing VFX with automatic Cascade fallback, and attached spatial healing audio. All presentation is reconstructed from a replicated exclusive healer state, so host, remote clients and late viewers agree when a station is actively treating a player without replicating light/VFX transforms every frame.

A healer station is now **exclusive to one accepted player for the configured Healing Sequence Duration**. While that sequence is active, another player attempting to use the same actor receives the configurable Busy Message. The actual heal remains server-authoritative and still restores the player's complete Party plus every Bank/Box entry in one transaction when `Include Bank Storage` is enabled, persists immediately, revives defeated Digimon when configured, and can re-summon the active partner.

Projects can assign `Healing Niagara System`, `Healing Cascade System`, and `Healing Sound` directly on the healer Blueprint. Niagara is preferred by default; if it is unassigned the actor automatically activates Cascade instead. The built-in light works even when no particle asset is assigned. `BP On Healing Sequence Started/Finished` are available for Blueprint-only door movement, emissive-material animation or other cosmetic extensions, while the original `BP On Heal Presentation` multicast hook remains compatible. See `Docs/SETUP_POLISHED_HEALER_PRESENTATION.md`.

## New in v0.12.1-alpha — Polished Native UI Layout Hardening

v0.12.1 is a focused presentation hardening release over the runtime-validated v0.12 Party/Bank milestone. The native Digimon Menu has been rebalanced so Party, Bank/Boxes, Scan & Materialize and Care retain clean spacing at ordinary PIE/game viewport sizes: fixed-size Bank cards scroll instead of being compressed, long profile/description text is clipped into dedicated scroll regions, and right-side action buttons stay pinned below their content instead of being overdrawn.

The persistent Party Quick Access and combat ability quickbars were polished at the same time. Dense card buttons now use compact internal padding, Party cards stack the portrait above a readable two-line identity/state label, and the combat bar automatically collapses an unassigned ability-icon frame so the ability name/SP/READY text can use the full card width. No gameplay, storage, persistence, combat or network authority path was changed.

## New in v0.12.0-alpha — Polished Party, Digimon Bank / Boxes & Party Quick Access

The owned-Digimon progression layer is now a complete **Party + Bank/Box system**. The shared `I` Digimon Menu exposes `PARTY`, `BANK / BOXES`, `SCAN & MATERIALIZE`, `DIGIDEX`, `DIGIVOLUTION` and `CARE`. Party is a six-Digimon active field roster by default, while the persistent Bank holds 200 Digimon by default and can be opened **anywhere in the gameplay world**—no physical terminal is required.

The Bank uses paged six-column Box storage with compact portrait/level cards, KO presentation, full selected-Digimon stats and a live six-slot Party destination strip. If Party has room, a Bank Digimon moves into the first free slot. If Party is full, select an occupied Party slot and the server performs an **atomic swap**, returning the outgoing Party Digimon to Bank. Deposits, swaps and active-partner changes are server-authoritative, owner-only replicated, persisted immediately, and blocked during active combat by default.

The HUD also gains a persistent native **Party Quick Access** bar. Press **Tab** to enter interaction mode: gameplay look/movement is temporarily released, the mouse cursor appears, healthy Party slots become clickable, and `HOME`, `RECALL`, `OPEN PARTY` and `OPEN BANK` actions expand below the roster. Tab again or Escape returns cleanly to gameplay. The bar remains owner-only presentation and all actual switching still goes through the normal server RPC path.

Save schema is now **v4**. Existing pre-v0.12 accounts migrate without intentionally losing a collected Digimon: the previous active partner is guaranteed to remain in Party, older collection entries fill Party in stable order, and overflow spills into the existing Bank field with GUID de-duplication. Current six-slot Party order is preserved on later loads. Scan Materialization now fills Party first and automatically routes to Bank when Party is full. See `Docs/SETUP_PARTY_BANK_STORAGE.md`.

## New in v0.11.1-alpha — Polished Player Camera Boom Zoom & Character-Safe Camera Collision

Player avatars now have a ready-to-use **smooth third-person spring-arm zoom system** configured globally under **Project Settings → Game → Digimon MMO Framework → Camera → Zoom**. Mouse Wheel Up zooms in and Mouse Wheel Down zooms out by default, with global default/minimum/maximum boom distances, wheel step size, smoothing speed and a separate default-input toggle for Enhanced Input projects.

Zoom is deliberately **local presentation only**: every player can choose their own camera distance without RPCs, replicated camera state or account persistence. Blueprint projects can call `Add Camera Zoom Input`, `Set Camera Zoom Distance`, `Get Camera Zoom Distance` and `Reset Camera Zoom` directly while retaining the same global clamps.

This release also fixes a common third-person MMO camera annoyance. With **Camera → Collision → Ignore Players And Digimon For Camera Collision** enabled (default), framework player avatars and Digimon force their primitive components to ignore `ECC_Camera`. Other players, owned partners and Wild Digimon can therefore pass between the controlled player and spring arm without shoving the camera forward. The spring arm itself still tests `ECC_Camera`, so walls and normal level geometry continue retracting the boom correctly.

See `Docs/SETUP_PLAYER_CAMERA_ZOOM.md` for configuration, Enhanced Input integration and the host + remote-client acceptance checklist.

## New in v0.11.0-alpha — Polished Global Music Director

The framework now includes an automatic **local MMO music-state director** exposed entirely through **Project Settings → Game → Digimon MMO Framework → Audio → Music**. Assign a Frontend/Main Menu music asset, Open World music asset and Battle music asset once; the framework then owns the normal soundtrack flow without Blueprint or C++ switching logic.

- The configured **Frontend Map** automatically plays **Frontend / Main Menu Music**.
- Entering the configured **Open World Map** crossfades to **Open World Music**.
- When the local player's active partner actually enters combat, the replicated authoritative encounter latch starts and the local soundtrack crossfades to **Battle Music**. Merely selecting a target does not start battle music.
- The encounter latch survives normal `Idle` gaps between manual ability presses, so Battle music does not time out while the same enemy is still being fought.
- Victory, defeat or authoritative combat teardown ends the encounter; the configurable release delay then prevents soundtrack chatter before crossfading back to **Open World Music**.
- Frontend, Open World and Battle volume multipliers plus a global master volume and crossfade duration are exposed in Project Settings.
- Framework music can automatically replay a track that naturally ends, so both looping Sound Cues and ordinary non-looping `USoundBase` assets are supported.
- Battle music gracefully falls back to Open World music if no dedicated Battle asset is assigned.
- The music director lives in a `GameInstanceSubsystem`, so Frontend audio can persist naturally through map travel and transition cleanly into gameplay music.
- Music is **client-local presentation only**. No audio track, playback time or music RPC is replicated; each player reacts to their own server-authored replicated battle-encounter state, which is the correct MMO behavior when different players are fighting different encounters. Dedicated servers render no music.

Advanced Blueprint projects can access `DMFMusicSubsystem` through the normal Game Instance Subsystem node, inspect `Current Music State`, listen to `On Music State Changed`, force an immediate refresh, or temporarily suppress framework music for cinematics without modifying the global Project Settings. See `Docs/SETUP_GLOBAL_MUSIC.md`.

## New in v0.10.4-alpha — Automatic Replicated Player Footsteps

Player avatars now have a ready-to-use **automatic footstep audio system** that requires no animation notifies and does not add footstep logic to Digimon. Assign one global Sound Cue under **Project Settings → Game → Digimon MMO Framework → Player Avatar → Footsteps → Player Footstep Sound** and framework-derived player characters begin producing grounded movement footsteps automatically.

Cadence is distance-driven from actual `CharacterMovement` velocity, with independent walk, sprint and crouch stride distances plus minimum-speed, volume and pitch controls. This keeps footsteps stable across different player skins, animation Blueprints and movement-input implementations. The audio origin is the capsule base rather than a skeleton-specific foot socket, so differently rigged player skins work without per-skeleton setup. A Sound Cue is recommended because it can randomize multiple samples/pitch and provide its own spatial attenuation.

For multiplayer responsiveness, a remote owning client predicts only its **own local footstep sound**, while the server independently produces an **Unreliable NetMulticast** cosmetic footstep event for other relevant clients. The owner suppresses the returned multicast echo, preventing doubled audio. The server remains the observer-presentation authority; no gameplay state, account persistence or Digimon behavior is changed. See `Docs/SETUP_PLAYER_FOOTSTEPS.md`.

## New in v0.10.3-alpha — Project-Configurable Admin Hosting Password

The protected **Admin → Host & Play** passphrase is now configurable directly from **Project Settings → Game → Digimon MMO Framework → Networking → Admin Hosting → Set Admin Hosting Password**. Projects no longer need to modify a C++ digest to choose their own hosting password.

The settings field is deliberately a **setter**, not plaintext storage: enter a new 4-128 character password and the framework immediately converts it to the existing one-way credential digest, clears the visible password field, and persists only the digest to `DefaultGame.ini`. Existing v0.10.2 deployments retain the previous Admin digest until a project-specific replacement is entered, so upgrading does not unexpectedly break the current hosting workflow.

The Admin gate remains local frontend protection for **Host & Play**. It is not a substitute for server/account authentication, firewall/NAT security or a production backend authorization service. See `Docs/SETUP_ADMIN_HOSTING.md`.

## New in v0.10.2-alpha — Project-Configurable Admin Host / Join Endpoint

The framework no longer requires a C++ edit to change the regular-player MMO destination. **Project Settings → Game → Digimon MMO Framework → Networking → Server Endpoint** now exposes **Server Public Address / Hostname** plus the existing **Game Port**. The default address preserves the previous `DigimonMMO3D.custom-gaming.net` deployment, so upgrading does not silently change current connection behavior.

`Join Game` now builds its travel target from that project setting after strict host-only validation. The setting accepts an IPv4 address or DNS hostname only—no `http://`, paths, embedded ports or Unreal travel options—so deployment config cannot inject extra travel parameters. `Host & Play` performs the same endpoint preflight after the Admin gate and reports the configured player endpoint in the local frontend status while Unreal continues to create the authoritative listen server normally.

This setting is a **deployment endpoint**, not NAT automation: the host/router/firewall must still expose the configured game port to the machine running the listen host. See `Docs/SETUP_SERVER_ENDPOINT.md`.

## New in v0.10.1-alpha — World Chat HUD Safe-Layout Fix

The polished native **WORLD chat** now reserves a dedicated lower-left HUD lane above the centered partner ability quick-access bar. The default native layout uses a `176` Slate-unit bottom safe offset while the native combat quickbar is enabled, leaving a deliberate visual gutter instead of allowing the two persistent HUD panels to overlap. When the native combat quickbar is disabled, chat returns to its original `30`-unit lower-left inset.

Project Settings now exposes **World Chat Bottom Safe Offset** under `UI → World Chat → Presentation`, so projects with a rescaled/replaced quickbar can tune the native chat clearance without editing C++. Chat networking, rate limiting, history, usernames, input focus and all existing gameplay systems are unchanged.

## New in v0.10.0-alpha — Polished Native MMO World Chat

The gameplay HUD now includes a ready-to-use **WORLD chat box** in the lower-left corner. Press **Enter** to focus chat, type, and press Enter again to send; Escape cancels and gameplay focus returns. The native presentation matches the framework's established navy/cyan/gold UI and keeps a compact scrollable message history rather than opening a large modal screen.

Chat is server-authoritative. Clients submit text only; the server sanitizes/clamps it, applies per-player interval and burst rate limits, stamps the sender from the authoritative public PlayerState username, stores a bounded session history for late joiners, and delivers accepted messages to connected framework PlayerControllers. Account credentials/private owner-only account fields never enter the chat payload. The chat history itself stays local/session-scoped and is not persisted to account saves.

Project Settings provides a master **Enable World Chat** switch, default Enter-binding toggle, Blueprint-replaceable chat widget class, message-length/history controls, optional timestamps and server anti-spam tuning. Care feeding temporarily hides the chat with the HUD so the Digimon eating presentation remains unobstructed, then restores the existing chat history. See `Docs/SETUP_WORLD_CHAT.md` for setup, reskinning and the host + remote-client acceptance checklist.

## New in v0.9.1-alpha — UE5.8 nameplate compile hardening

- Corrects the two UE5.8.1/MSVC `C2445` nameplate fallback-class errors from the initial v0.9.0 build without changing the world-nameplate feature set.
- Replaces deprecated direct Care-prop network-frequency member access with the UE5.8 setter APIs.
- All v0.9.0 player/Digimon nameplates and the accepted v0.8.1 Care/CustomDepth, Scan/Materialization, combat, persistence and multiplayer contracts remain intact.

## New in v0.9.0-alpha — Polished MMO World Nameplates

Player avatars and Digimon now receive **automatic native overhead nameplates** with no per-Blueprint Widget Component setup. Remote player avatars show the authenticated username through Unreal's replicated `APlayerState::PlayerName` presentation channel, while the private framework account username/credential data remains protected by its existing ownership boundary. The local player's own plate is hidden by default to keep the viewport clean.

Digimon plates stay deliberately compact: display name/nickname, `Level • Stage • Attribute`, a slim replicated HP bar and optional numeric HP. Owned partners and Wild Digimon use the same native presentation layer, and HP changes are read from the existing replicated combat vitals rather than creating a separate health replication path.

Project Settings now provides a master world-nameplate switch plus independent Player/Digimon toggles, local-player visibility, max draw distances, automatic capsule-relative height offsets, numeric-HP control and Blueprint-replaceable widget classes. The native widget uses the same navy/cyan/gold visual language as the framework's existing polished UI. Presentation refresh is throttled and widget components distance-cull locally; dedicated servers do not render widgets.

See `Docs/SETUP_WORLD_NAMEPLATES.md` for setup, reskinning and the host + remote-client acceptance checklist.


## New in v0.8.1-alpha — DigiMeat & Poo CustomDepth Cel Shading

The replicated `ADMFDigimonCarePropActor` now follows the framework-wide cel-shading contract: **DigiMeat and world poo always render into Unreal CustomDepth** on host, remote clients and late viewers. The native mesh is enabled in the constructor and the invariant is reasserted during construction, BeginPlay and replicated presentation refresh, so species/global mesh swaps cannot silently drop out of the post-process cel shader.

`ADMFDigimonCarePropActor` also exposes `CustomDepthStencilValue` (`0-255`, default `0`) plus Blueprint-callable `RefreshFrameworkCustomDepth()`. Blueprint children that add extra mesh components are included by the refresh pass. This is presentation-only and adds **no replicated gameplay state or network bandwidth**; the existing server-authoritative feeding, Hunger, waste, collision and cleanup contracts are unchanged.

## New in v0.8.0-alpha — Virtual-Pet Care, DigiMeat Feeding & World Waste

The shared **DIGIMON MENU** now includes a polished `CARE` tab driven by the same owner-only persistent Digimon instance state used by Collection and Scan Data. Hunger uses `0 = empty / 100 = full`, decays from authoritative UTC time (including offline time), and existing v0.7.x dormant care saves are migrated without suddenly starving established Digimon.
The account SaveGame is now formally **schema v3** for persistent Care while preserving all earlier account, player-skin, Collection and Scan data.

Feeding is an MMO-safe server transaction. `FEED DIGIMEAT UNTIL FULL` validates the summoned partner, combat state, species care configuration, Feeding Montage, DigiMeat mesh and text-configurable hand socket. The owner menu and combat HUD are hidden before presentation begins so the player can watch the Digimon eat. A replicated DigiMeat actor attaches to the configured hand socket using a per-species relative transform/scale, the species Feeding Montage plays **twice in sequence per serving by default**, an optional feeding voice is multicast, Hunger is awarded only after the complete serving, and servings loop until full. The CARE page automatically returns when the sequence finishes.

Feeding schedules persistent digestion/waste. When due and the partner is in-world, the server traces the ground beneath the Digimon and spawns a replicated, scalable poo presentation actor at that location. It has **no collision, no overlaps and no navigation influence**, can play a server-selected funny fart cue for viewers, and destroys itself automatically after the configured lifetime. See `Docs/SETUP_CARE_SYSTEM.md` for the complete per-species setup and multiplayer acceptance checklist.

Blueprint projects can reskin/extend all presentation surfaces: care data remains server-owned; the shared menu, care prop actor and character cosmetic events are presentation layers.


## New in v0.7.1-alpha — UE5.8 Scan Toast Compile Fix

- Fixed the UE5.8.1/MSVC `C4458` build failure in `DMFScanNotificationWidget.cpp` where a local `UOverlaySlot* Slot` variable hid the inherited `UWidget::Slot` member.
- Renamed the local variable to `ToastOverlaySlot`; Scan Data, Materialization, the tabbed Digimon Menu, persistence, replication and combat behavior are otherwise unchanged from v0.7.0-alpha.
- Scanned the runtime source for other local `Slot` declarations that could collide with `UWidget::Slot`; no additional UI shadowing candidates remain.

## New in v0.7.0-alpha — Scan Data & Materialization

The framework now includes a persistent, server-authoritative Scan Data capture loop integrated directly into the polished native Digimon menu. Eligible wild victories award species-specific Scan Data, normally 20% per win. At the configured threshold (100% by default), the player can open `I -> SCAN & MATERIALIZE`, select the analyzed species and materialize a new permanent Digimon into Party first, or Bank automatically when Party is full.

The Digimon menu began as a tabbed shell in v0.7; in current builds its roster page is the six-slot `PARTY`, with `BANK / BOXES`, `SCAN & MATERIALIZE`, `DIGIDEX`, `DIGIVOLUTION` and `CARE` implemented alongside it. The Scan page uses species portraits, progress cards, readiness badges, a large selected-species terminal, collection-capacity checks and a server-backed Materialize action. Battle rewards also produce a native owner-only Scan toast with `+X%`, total progress and `MATERIALIZATION READY`.

Per species, configure `DMFDigimonSpeciesData -> Scan & Materialization`: `bScanDataEnabled`, `BattleScanPercentReward`, `ScanPercentCap`, `bMaterializationEnabled`, and `MaterializationRequiredScanPercent`. Materializable species must have `WorldActorClass` set to the normal partner Blueprint derived from `DMFDigimonCharacter`, never the `DMFWildDigimonCharacter` Blueprint. Scan Data is owner-only replicated and saved in the account record automatically. See `Docs/SETUP_SCAN_MATERIALIZATION.md`.





## New in v0.6.4-alpha — repeat-safe ability commands

Manual quick-slot commands now use a server-authoritative **latest-command input buffer**. Pressing `1`–`4` while the partner is still attacking, recovering, cooling down, chasing, or turning no longer loses the input. The queued ability remains pending and executes as soon as SP, cooldown, range, facing, target validity, and leash validation all pass. SP is deducted only when the attack actually begins. Expired cooldown entries are pruned, and authoritative cooldown validation uses the server world clock directly. This builds on v0.6.3 capsule-aware melee reach rather than replacing it.

## New in v0.6.3-alpha — reliable ability execution and capsule-aware melee reach

- Fixed short-range/manual abilities that could queue forever while a longer-range or 0-SP ability still worked.
- Ability range is now measured horizontally **capsule edge-to-edge**, not actor-center to actor-center. This keeps melee reach consistent across small and large Digimon collision capsules.
- AI chase acceptance now uses the same capsule-aware range contract and disables the extra `StopOnOverlap` radius that could leave a melee attacker just outside legal range.
- Authoritative impact-time range validation uses the same rule, so an attack that is allowed to start is not silently discarded by a different range formula at impact time.
- Positive SP-cost and zero-SP abilities now share one normalized cost path; SP is not consumed until range, target, cooldown, and facing validation have all succeeded.
- Combat target-facing now also synchronizes AI control yaw and temporarily suppresses controller-driven yaw while attacking, preventing a controller from fighting the turn-in-place gate.
- No changes to the polished v0.6.0 UI, v0.6.1 possession recovery, wild retaliation policy, spawner population/rarity, persistence, healer, or account systems.

## New in v0.6.2-alpha — replicated combat target facing

- Partner and wild Digimon now perform a smooth server-authoritative turn-in-place toward the Digimon they are about to attack.
- Attacks may be gated until the attacker is within an exposed yaw tolerance, preventing sideways/backwards attack Montages.
- The facing loop is active only while needed; normal movement orientation is restored after recovery/chase so roaming and following stay natural.
- Character replicated movement carries yaw to host/clients; clients do not author combat rotation.
- `DMFDigimonCharacter` exposes `Enable Combat Facing`, `Require Facing Before Attack`, `Combat Facing Turn Rate`, `Attack Facing Tolerance`, and an advanced update interval, plus Blueprint calls for explicit facing control/inspection.
- See `Docs/SETUP_COMBAT_TARGET_FACING.md`.

## Fixed in v0.6.1-alpha — remote-client avatar possession

The framework now enforces that late-joining clients enter gameplay possessing a `DMFPlayerAvatarCharacter` (or the project's Blueprint child) rather than remaining in Unreal's flying fallback `DefaultPawn`. The server validates the pawn after normal `HandleStartingNewPlayer`, repairs missing/wrong pawns, reasserts `ClientRestart` to remote clients, reapplies the account-selected skin, and restores the active partner once onboarding permits it.

The local remote PlayerController also performs a short bounded acknowledgement/retry check after joining. Skin selection and starter confirmation are additional authoritative recovery checkpoints, so a successful UI selection can no longer leave the client attached to the wrong pawn.

**Recommended OpenWorld configuration remains:**
- GameMode Override = your Blueprint child of `DMFMMOGameMode`.
- Default Pawn Class = your Blueprint child of `DMFPlayerAvatarCharacter`.
- Player Controller / Player State = framework defaults or compatible Blueprint children.
- At least one valid normal `PlayerStart` as a collision-safe fallback.
- Place a `DMFNewPlayerStart` at the intended first-login location for new accounts (v0.15.1).

See `Docs/SETUP_MULTIPLAYER_CLIENT_POSSESSION.md`.


## New in v0.6.0-alpha — polished native UI by default

The framework no longer ships programmer-style gray-list fallback menus. The native defaults are now a coordinated MMO UI suite: a centered login/main-menu/admin card, portrait-driven starter and character selectors, a real Digimon portrait-slot inventory with selected stats and summon/recall actions, and a bottom-center ability HUD with ability icons/cooldowns.

**Existing data assets drive the visuals automatically:**
- `DMFDigimonSpeciesData -> Portrait` = inventory slot, selected Digimon portrait and starter card/preview.
- `DMFPlayerSkinData -> Portrait` = character skin card/preview.
- `DMFDigimonAbilityData -> Icon` = combat quick-slot icon.

The current native Digimon Menu formalizes the owned roster as a six-slot **PARTY** (`MaxPartyDigimon`) plus persistent paged **BANK / BOXES** (`MaxDigimonBankStorage`). Party cards expose Active/Summoned/KO state and full selected stats; Bank cards use the same portrait/stat language with a live Party destination strip for authoritative move/swap operations. Summon/recall and every storage mutation remain server-authoritative.

All polished widgets remain Blueprintable/reskinnable. Existing Blueprint subclasses are not required to migrate to the native layout, and legacy optional binding names remain supported where practical. See `Docs/SETUP_POLISHED_NATIVE_UI.md`.





## Fixed in v0.5.5-alpha — deterministic death pose + passive-until-attacked wild combat

- Player-owned and wild Digimon now lock their Death Montage at blend-out start and pause skeletal animation evaluation so a defeated Digimon cannot return to Idle. Player partners remain frozen until recall/revive; wild Digimon remain frozen until the spawner removes them.
- Defeat animation startup is now driven only by authoritative/replicated `CombatState=Defeated`; the defeat multicast is cosmetic-only, removing the client ordering race that could let a Montage finish before the client knew it was defeated.
- Wild combat is now split into two clear policies: **Proactive Auto Battle** and **Retaliate When Attacked**. The recommended MMO default is proactive off + retaliation on. Wild Digimon peacefully roam until a hostile Digimon actually damages them, then the server makes that aggressor their combat target and they fight back inside their normal leash.
- Spawner defaults now match that behavior: `Allow Proactive Auto Battle=false`, `Allow Retaliation When Attacked=true`. Proactive aggression can still be enabled for intentionally hostile encounter zones.
- `DMFWildDigimonCharacter` exposes authoritative `Set Wild Auto Battle Enabled` and `Set Wild Retaliation Enabled` calls, with replicated policy state for Blueprint/UI inspection.

> **v0.5.5 defeated-pose contract:** when a Digimon reaches `Defeated`, its species Death Montage owns the mesh until the Montage starts blend-out; at that exact boundary the framework pauses the Montage and skeletal evaluator so neither player nor wild Digimon can return to Idle while defeated. Player partners remain frozen until recall/revive; wild Digimon remain frozen until their spawner corpse timer removes them.


## Fixed in v0.5.4-alpha — UE5.8.1 death-pose compiler feedback

- Corrected the three `C4458` errors introduced by v0.5.3 in `DMFDigimonCharacter.cpp`. Local variables named `Mesh` shadowed `ACharacter::Mesh`, and this project's UE5.8.1 warning policy promotes that diagnostic to an error.
- Renamed those locals to `DigimonMesh` in defeated-presentation apply/hold/clear paths. This is a naming-only compile correction: death montage playback, persistent defeated pose, revive/recall behavior, replication, interaction, healer, roster and wild-spawner behavior are unchanged.
- The supplied build log shows UHT completing successfully and all other plugin translation units compiling past this layer; the only reported C++ diagnostics are the three `C4458` occurrences in `DMFDigimonCharacter.cpp`.

## Persistent defeated partner presentation (v0.5.3)

A player-owned Digimon that reaches `0 HP` now remains physically present in its defeated pose until the player recalls/dismisses it or an authoritative healer revives it. The framework plays the species `DeathMontage`, stops AI/CharacterMovement, makes the capsule non-blocking by default, and freezes the montage near its final pose instead of allowing the AnimBP to return to idle. `CombatState` replication is the durable source of truth, so late-joining clients also reconstruct the defeated presentation.

Configure the species `DeathMontage` normally, then tune the partner/wild Blueprint under **Digimon MMO -> Defeat Presentation** if a particular animation needs a slightly earlier/later held frame. The default normalized hold time is `0.97`. See `Docs/SETUP_DEFEATED_PARTNER_PRESENTATION.md`.

## Added in v0.5.2-alpha — one-call player interaction / Digimon targeting

- `ADMFPlayerAvatarCharacter` now exposes a ready-to-use inherited `Interact` Blueprint node. The framework player performs the interaction trace and internally dispatches supported Digimon/healer actors, so the normal player Blueprint no longer needs controller, PlayerState, Digimon or healer casts.
- Native `E` interaction is enabled by default and is independently disableable for Enhanced Input projects. The same `Interact` function remains callable from any project Input Action.
- Interaction trace tuning is exposed on the player Blueprint: distance, line-vs-sphere sweep radius, trace channel, trace complexity, active-partner ignore and optional debug drawing.
- Digimon interaction defaults to **target only**. The intended manual-combat flow is `E -> target`, then `1-4 -> ability`. Optional target+attack interaction and explicit `Interact With Digimon And Attack` are also available.
- Cast-free helper nodes accept generic `Actor` references for projects that already have overlap/UI hit actors. `Clear Digimon Target`, `Command Digimon Ability Slot`, current-target and prompt/result helpers are exposed directly on the player.
- `DMFHealerActor` now includes a query-only native interaction sphere, so a basic healer Blueprint is immediately detectable by the player interaction trace while authoritative healer range/reuse validation remains server-side.
- Legacy Left-Mouse target selection now defaults off independently from the default `1-4` ability commands.
- See `Docs/SETUP_PLAYER_INTERACTION_SYSTEM.md` for the exact setup.


## Fixed in v0.5.1-alpha — UE5.8.1 compiler feedback

- Corrected the `C2664` failure in `UDMFPlayerDigimonComponent::IsActivePartnerSummoned()`. The function is no longer defined inline against a forward-declared `ADMFDigimonCharacter`; its implementation now lives in the `.cpp` after the complete Digimon character type is included.
- The supplied UE5.8.1 build log shows UHT completing successfully and eight C++ compile actions failing on the same header expression, so this maintenance release targets that single root compiler defect without changing v0.5.0 gameplay behavior.
- All v0.5.0 manual partner combat, JRPG balance, healer, Digimon roster/summon/recall features and the tested v0.4.1 wild-spawner behavior are preserved.



## Added in v0.5.0-alpha — player combat control, battle pacing, healer and Digimon roster UI

- Player-owned partners no longer auto-acquire or auto-attack by default. They still follow the player and execute explicit manual commands, including out-of-range chase/queue behavior.
- New `bPlayerPartnerAutoBattle` project setting defaults to `false`; wild Digimon retain their independent `bAutoBattle` setting.
- New Blueprint calls on `ADMFMMOPlayerController`: `SetDigimonCommandTarget`, `CommandPartnerTargetAndAttack`, and `CommandActivePartnerAbilitySlot`. These are intended to be called directly from a project interaction/targeting trace without granting combat authority to the client.
- Added non-persistent role-level combat tuning: player-owned partners default to `1.50x` outgoing damage and `0.50x` incoming Digimon-combat damage. Both values are exposed in Project Settings. Wild Blueprint classes also expose independent outgoing/incoming multipliers (default `1.0`). Persistent species/player stats are not silently rewritten.
- Added Blueprintable replicated `ADMFHealerActor`. Project interaction logic calls `RequestHeal`; the owning PlayerController routes the request to the server, which validates range/reuse/availability and restores owned Digimon for free. HP/SP, defeated restoration, bank inclusion, auto-resummon, interaction radius, messages and reuse delay are exposed.
- Healer use persists immediately, can restore defeated partners, and can automatically re-summon the selected active partner after healing. A cosmetic multicast Blueprint event is provided for healer VFX/audio/NPC animation.
- Added native/reskinnable `UDMFDigimonInventoryWidget` and entry buttons. Default `I` toggles the roster menu; Blueprint Open/Close/Toggle/Refresh calls are exposed on `ADMFMMOPlayerController`.
- The roster UI lists owned Digimon with level/HP/SP/active/defeated state and allows server-authoritative Set Active/Summon and Recall actions. A defeated Digimon cannot be summoned until healed.
- Added server RPCs on `UDMFPlayerDigimonComponent` for selecting/summoning, recalling and optionally toggling active-partner auto battle, plus authoritative `HealAllOwnedDigimon`.
- Existing account persistence, v0.4.1 wild-spawner capsule placement, rarity/roaming/emergence, native frontend bootstrap, player skins and Custom Depth contracts are preserved.
- See `Docs/SETUP_MANUAL_COMBAT_HEALER_INVENTORY.md`.

## Fixed in v0.4.1-alpha — Wild spawn placement

- Corrected a v0.4.0 spawn-placement defect where the terrain/NavMesh surface point was used directly as an `ACharacter` actor origin. Because a Character origin is at the center of its capsule, this could embed half the capsule in terrain and cause `AdjustIfPossibleButDontSpawnIfColliding` to reject every spawn.
- Spawn placement now reads the selected `BP_Wild_<Species>` class default capsule half-height and places the capsule bottom on the resolved ground/NavMesh surface plus `Spawn Ground Offset`. Different Digimon Blueprint capsule sizes are respected automatically.
- Added clear server Output Log messages for spawner activation, successful wild spawns, no eligible spawn-table entries, and bounded placement failure.
- No intentional changes to rarity selection, population, roaming/leash, emergence, combat, persistence, login, player skins, starter flow, or Custom Depth behavior.

## Added in v0.4.0-alpha — MMO wild Digimon proximity / rarity spawner

- `ADMFWildDigimonSpawner`: Blueprintable, replicated world population actor with server-only spawn decisions.
- Player-proximity activation plus larger deactivation radius and grace period for stable MMO streaming/hysteresis.
- Inclusive min/max active population roll per activation with staggered initial spawning.
- Weighted rarity tiers (`Common`, `Uncommon`, `Rare`, `Epic`, `Legendary`, `Mythic`) plus per-entry weight multipliers and per-entry live caps.
- Per-entry species, wild Blueprint class and min/max level range.
- Ground trace + optional NavMesh projection + player-distance rejection + collision-aware deferred spawning.
- Replicated `SpawnRarity` and individual `SpawnHomeLocation` on wild Digimon.
- Timer-driven free roaming around each individual home point using random reachable NavMesh locations.
- Existing combat automation uses the same individual spawn point as its hard leash home.
- Replicated synchronized ground emergence: the authoritative capsule stays on valid ground while the mesh rises smoothly from below ground; combat/movement/collision are suppressed until the transition completes.
- Optional synchronized ground sink when the last nearby player leaves and the spawner unloads.
- Per-entry emergence depth/duration override for differently sized Digimon.
- Defeat-aware replacement queue with randomized respawn delay and configurable corpse/death-presentation lifetime.
- Blueprint runtime calls/events for forced activation/deactivation, one-off spawn, state counts, spawn notification and ground-transition cosmetics.
- `NavigationSystem` runtime dependency added for placement and idle roaming.
- See `Docs/SETUP_WILD_DIGIMON_SPAWNER.md` for the complete Editor setup and multiplayer acceptance test.


This baseline preserves the authoritative account/onboarding and real-time combat foundations and adds a ready-to-use replicated third-person player character plus persistent, server-authoritative character-skin selection.


## v0.3.1-alpha compiler-feedback maintenance fix

This maintenance release preserves the complete v0.3.0 player-avatar/skin feature set while correcting the UE5.8.1 compiler diagnostics reported by the first real Editor build of that feature layer. `ADMFMMOPlayerController` no longer declares local variables named `PlayerState` (which hides `AController::PlayerState` under the project's warnings-as-errors build policy), and `BP_OnPlayerSkinSelectionResult` now uses UHT's canonical `const FText&` signature. No gameplay, replication, persistence, skin-selection authority, starter, or combat behavior is intentionally changed.

## Added in v0.3.0-alpha — Player avatar / character skin framework

- `ADMFPlayerAvatarCharacter`: ready-to-derive replicated third-person player pawn, now the default MMO pawn class.
- Native fallback controls: WASD, mouse look, jump, replicated sprint, crouch and gamepad sticks; projects can disable them and supply Enhanced Input.
- Camera boom + follow camera exposed for Blueprint tuning.
- `UDMFPlayerSkinData` Primary Data Asset: stable skin ID, display metadata, skeletal mesh, AnimBP class, relative mesh transform, material overrides and portrait.
- `UDMFPlayerAvatarComponent` on `ADMFPlayerState`: owner-routed server RPCs, persistent selected skin ID, replication to all clients and Blueprint delegates.
- Skin switching is presentation-only: the authoritative pawn/controller/position/inventory/partner are never replaced just to change appearance.
- Native `UDMFPlayerSkinSelectionWidget` with fully functional fallback UI and Blueprint preview/result events.
- Automatic skin discovery through Asset Manager: no hard-coded skin roster array. Add an enabled `DMFPlayerSkinData` asset and it appears automatically.
- First-time skin selection can be mandatory and is sequenced before Starter Digimon onboarding.
- `F6` opens the character skin menu during gameplay by default. Blueprint-callable Open/Close/Toggle/Refresh functions are exposed on `DMFMMOPlayerController`.
- Character selection persists immediately in the host account database and survives reconnect/server restart.
- Existing v0.2.x accounts migrate safely: they retain Digimon state and simply have no selected avatar skin until they choose one.


## Fixed in v0.2.2-alpha — UE5.8 compile compatibility

- Explicitly unwraps replicated `TObjectPtr<ADMFDigimonCharacter>` target fallbacks with `.Get()` where UE5.8/MSVC otherwise reports ambiguous conditional-expression result types.
- Normalizes `ClientStarterSelectionResult` to the UE5.8 UHT-generated RPC signature (`bool`, `const FText&`, `FGuid`) in both declaration and implementation.
- Eliminates the generated-code `C2511`/`C2352` cascade caused by the mismatched RPC signature.
- No gameplay, replication-authority, persistence, combat or onboarding behavior is intentionally changed by this maintenance release.


## Fixed in v0.2.1-alpha — UE5.8 compile compatibility

- Replaced the obsolete `#include "Engine/PrimaryAssetId.h"` path with UE5.8's documented `#include "UObject/PrimaryAssetId.h"`.
- Applied the fix consistently in `DMFTypes.h`, `DMFStarterEntryButton.h`, and `DMFStarterSelectionWidget.h`.
- No gameplay, replication, persistence, UI, combat, starter, or data-asset contracts were changed by this compatibility release.
- This patch directly addresses every compiler error present in the supplied UE5.8.1 UnrealBuildTool log; a fresh UE5.8 build is still required to expose any subsequent errors that were previously masked by the missing header.

## Added in v0.2.0-alpha — Real-time battle core

- `DMFDigimonAbilityData` Primary Data Assets for Blueprint-first ability authoring.
- Replicated `DMFDigimonCombatComponent` on every framework Digimon character.
- Server-authoritative HP, SP, cooldown, range, target, damage and defeat validation.
- JRPG-style STR/INT attack scaling with DEF mitigation.
- Autonomous hostile target acquisition, chasing and basic attacks.
- Automatic player-partner follow behavior outside combat.
- Shared team-ID hostility rules for player, wild, NPC and future ranked teams.
- Player commands routed through the owning PlayerState component rather than trusting the spawned partner actor.
- Server-side command queue: out-of-range quick-slot commands chase the selected target and execute in range after full revalidation.
- Server-side command-rate guard to reject abusive quick-slot RPC bursts before combat processing.
- Four-slot native quick-access combat bar with replicated cooldown feedback.
- Ready-to-use manual combat inputs: player `E / Interact` targets through the avatar interaction layer and number keys 1–4 command quick slots. Legacy Left-Mouse target selection remains available as an independently toggleable controller binding and defaults off in v0.5.2.
- Ready-to-bind cursor target selection on the MMO PlayerController.
- Replicated combat target/state/vitals with Blueprint delegates.
- Unreliable multicast cosmetic attack cues for montage/VFX/audio; gameplay results remain replicated authoritative state.
- Species-level Attack1/Attack2 Cascade/Niagara/montage fields remain supported as presentation fallbacks.
- Ready-to-place `ADMFWildDigimonCharacter` with species, level, team, aggro and leash settings.
- Wild level stat scaling from species Data Assets.
- Persistent active-partner HP/SP synchronization.
- Configurable account autosave interval.
- Battle EXP now drives persistent server-authoritative level progression, species stat growth, Attribute Point grants and owner-only animated EXP/LEVEL UP presentation; money rewards remain authoritative/persistent.
- Blueprint hooks for ability presentation, defeat presentation, target changes, combat state, vitals and battle rewards.

## Foundation retained from v0.1.0

- Multiplayer-only MMO gameplay GameMode (`ADMFMMOGameMode`).
- Frontend GameMode/HUD with a fully functional native UMG fallback login/main-menu UI.
- Username/password credential staging with server-side validation during connection.
- Optional first-login auto-registration on the host's server-side account database.
- Project-configurable regular-player server endpoint under `Networking → Server Endpoint`; no plugin C++ edit is required to change the host/IP used by **Join Game**.
- Server-authoritative global player capacity under `Networking → Server Capacity`, defaulting to 100 total connected gameplay players and enforced during Unreal GameSession login approval.
- Admin-only `Host & Play` flow protected by a Project Settings-configurable passphrase; the editor stores only its one-way digest rather than retaining plaintext.
- Single package flow: normal users join; an unlocked admin may start the authoritative listen host.
- Persistent account database through a host-side `USaveGame` database.
- Blueprint/data-asset driven Digimon species definitions.
- JRPG-style Digimon stat foundation: Level, EXP, HP, SP, STR, INT, DEF, SPD, ABI and CAM.
- Per-Digimon unique persistent instance IDs.
- Per-instance current HP/SP, care state, equipped abilities and unspent attribute points.
- Digivolution requirement definitions with level plus optional stat thresholds.
- Exposed animation inputs: Attack 1, Attack 2, Death, Feeding, Interact and Win montages.
- Exposed Cascade VFX inputs for Attack 1 / Attack 2 plus optional Niagara equivalents.
- Exposed Digimon idle/voice sound list.
- Owner-only Fast Array replication for the player's active Digimon inventory.
- Active partner identity replication.
- Starter roster `PrimaryDataAsset`.
- Native starter selection UI with selectable starter list and stat preview.
- Server-authoritative starter validation/grant with explicit owner-only success/failure result feedback.
- Server-side Blueprint admin/reset hook for starter onboarding support/testing.
- New starter is automatically assigned a unique instance ID, added to the player's replicated inventory, made active, persisted, and spawned as the player's 3D partner when a valid world actor class is configured.
- Returning players bypass starter selection and load their existing partner.
- Blueprint events/hooks for custom presentation and 3D starter preview implementations.
- Account schema already reserves Digimon Bank, scan-data, money, ranked battle points and F→S+ rank state so later systems extend the same persistence contract.

## Cel-shading / Custom Depth contract

All framework player-avatar skins, Digimon, and Care presentation props automatically force `Render CustomDepth Pass = true` on their owned mesh components. Skin swaps, Digimon initialization, replicated state refreshes and Care-prop presentation refreshes reassert the flag. `ADMFPlayerAvatarCharacter`, `ADMFDigimonCharacter` and `ADMFDigimonCarePropActor` expose `CustomDepthStencilValue` plus a Blueprint-callable `RefreshFrameworkCustomDepth()` for dynamically created mesh components. Unreal project-level Custom Depth must still be enabled under Rendering for post-process materials to sample it.

## Setup

1. Copy the `DigimonMMOFramework` folder into `<YourProject>/Plugins/`.
2. Regenerate project files and compile for UE5.8.
3. Enable **Digimon MMO Framework**.
4. Set your blank main-menu level to use `DMFFrontendGameMode`.
5. Set your open-world gameplay level to use `DMFMMOGameMode`.
6. Place a **`DMFNewPlayerStart`** in the Open World at the first-login/new-account spawn location. Keep at least one ordinary `PlayerStart` as a recovery fallback. Returning accounts with a saved location bypass the new-player start.
7. Create `/Game/DigimonData` for framework Data Assets. Merge `ConfigTemplates/DMF_Project_DefaultGame.ini.snippet` into your project's `Config/DefaultGame.ini` so species/roster/ability/player-skin Primary Assets are discovered and always cooked.
8. Create a Blueprint derived from `DMFPlayerAvatarCharacter` if you want project-specific camera/movement defaults, and assign it as your MMO GameMode Default Pawn Class. The native class is already the C++ default.
9. Create one `DMFPlayerSkinData` asset per selectable character under `/Game/DigimonData` and assign each existing skeletal mesh/AnimBP. The skin UI discovers enabled assets automatically.
10. In **Project Settings → Game → Digimon MMO Framework**, assign:
   - `Frontend Map`
   - `Open World Map`
   - `Starter Roster`
   - `Networking → Server Endpoint → Server Public Address / Hostname`
   - `Networking → Server Endpoint → Game Port`
   - `Networking → Server Capacity → Global Maximum Players` (default `100`; the listen host consumes one slot)
   - `Networking → Admin Hosting → Set Admin Hosting Password` (enter a project-specific password; the setter clears after hashing)
   - `Player Avatar → Footsteps → Player Footstep Sound` (assign a spatial Sound Cue; optional cadence/gain controls are alongside it)
   - optional `Default Player Skin` when skin selection is not mandatory
   - `Persistence -> Player World Location -> Enable Player World Location Persistence` = enabled (recommended)
   - `Persistence -> Player World Location -> Use Dedicated New Player Spawn` = enabled when using `DMFNewPlayerStart`
11. Create `DMFDigimonAbilityData` assets under `/Game/DigimonData` for the basic attack and quick-slot abilities you want to test. Configure SP cost, cooldown, timing, range, damage scaling and presentation assets. For fireballs/bolts/rockets that must visibly travel, set `Execution Mode = Replicated Projectile` and configure the projectile socket/VFX/speed/homing/cleanup fields described in `Docs/SETUP_ABILITY_PROJECTILES.md`.
12. Create one `DMFDigimonSpeciesData` asset per species under `/Game/DigimonData`; assign `BasicAutoAttack`, `StartingAbilities`, battle rewards and the species presentation assets.
13. Every playable/summonable species should provide a `WorldActorClass` derived from `ADMFDigimonCharacter`.
14. Create a `DMFStarterRosterData` asset under `/Game/DigimonData` and add the desired starter species.
15. Cover the combat/exploration area with a valid `NavMeshBoundsVolume` so authoritative Digimon AI can follow, chase and return to its leash anchor.
16. For MMO population streaming, create a Blueprint child of `DMFWildDigimonSpawner`, add rarity-weighted spawn entries and place it inside valid NavMesh. See `Docs/SETUP_WILD_DIGIMON_SPAWNER.md`.
17. Place standalone `ADMFWildDigimonCharacter` Blueprints only for fixed/scripted encounters if desired.
18. Package normally. The admin can log in, unlock Admin and choose **Host & Play**. Regular users log in and choose **Join Game**.

## UE5.8 packaging note

The framework defaults live in C++ and project-editable `UDeveloperSettings`. The included `ConfigTemplates/DMF_Project_DefaultGame.ini.snippet` is intentionally a **project config merge template**, not a plugin `DefaultGame.ini`. UE5.8 does not currently package plugin configuration files automatically, so required Asset Manager scan/cook rules belong in the consuming project's configuration.

The snippet does not clear or replace your existing Primary Asset types. It adds the four DMF Primary Asset types (`DMFDigimonSpecies`, `DMFStarterRoster`, `DMFDigimonAbility`, `DMFPlayerSkin`) and marks them `AlwaysCook`.

## Blueprint-first contract

All content-facing species fields, starter definitions and major runtime entry points are Blueprint visible. The supplied native widgets work without Blueprint assets, but they are intentionally subclassable so a project can replace the presentation while retaining authoritative framework behavior.

## Security note

The server destination is intentionally editable in **Project Settings** rather than embedded/obscured in plugin C++. It is deployment configuration, not a secret: packaged clients necessarily need the destination they connect to, and a determined user can inspect network destinations from a client binary or live connection. The framework therefore validates the configured hostname/IP for safe travel construction instead of pretending it is a cryptographic boundary.

Likewise, this alpha provides an out-of-the-box private-host login gate, not internet-grade account security. Credential digests carried in Unreal travel options can be replayed if traffic is captured. Before public production deployment, replace the credential transport with a TLS-backed authentication service that issues short-lived signed session tickets. The persistence and PlayerState interfaces are structured so that authentication can be swapped without rewriting Digimon inventory/onboarding logic.

## Source inspiration

The framework is being built around the feature direction of AkumaVenom's Digimon VPET World project: 3D exploration, real-time wild battles, scanning/materialization and virtual-pet care. This plugin is a new multiplayer architecture rather than a direct conversion of that project's Blueprint assets.

See `Docs/ARCHITECTURE.md`, `Docs/SETUP_DAY_NIGHT_SKY.md`, `Docs/SETUP_PLAYER_WORLD_LOCATION.md`, `Docs/SETUP_FRONTEND_BACKGROUND_PRESENTATION.md`, `Docs/SETUP_PLAYER_CAMERA_ZOOM.md`, `Docs/SETUP_GLOBAL_MUSIC.md`, `Docs/SETUP_PLAYER_AVATAR_SKINS.md`, `Docs/SETUP_PLAYER_FOOTSTEPS.md`, `Docs/SETUP_STARTER_SYSTEM.md`, `Docs/SETUP_COMBAT_SYSTEM.md`, `Docs/SETUP_PLAYER_INTERACTION_SYSTEM.md`, `Docs/SETUP_WILD_DIGIMON_SPAWNER.md`, `Docs/SETUP_MANUAL_COMBAT_HEALER_INVENTORY.md`, `Docs/SETUP_PLAYER_ITEM_INVENTORY.md`, `Docs/SETUP_WORLD_NAMEPLATES.md`, `Docs/SETUP_WORLD_CHAT.md`, `Docs/SETUP_SOCIAL_SYSTEM.md`, `Docs/SETUP_SERVER_ENDPOINT.md`, `Docs/SETUP_SERVER_CAPACITY.md`, `Docs/SETUP_ADMIN_HOSTING.md`, `Docs/SETUP_SCAN_MATERIALIZATION.md`, `Docs/SETUP_CARE_SYSTEM.md`, `Docs/NETWORKING.md`, `Docs/TEST_PLAN.md`, `Docs/ROADMAP.md` and `CHANGELOG.md`.


## Native frontend UI bootstrap (0.3.2; framework-owned background layering polished in v0.15.0)

The native login, player-skin, starter and combat widgets are functional C++ fallbacks and do not require Widget Blueprint assets. Their fallback `WidgetTree` is constructed during `RebuildWidget()` so it exists before the underlying Slate widget is built. `DMFFrontendHUD` now defers the frontend login layer by the configurable `FrontendUIStartupDelaySeconds`, then retains its existing brief retry loop if the local PlayerController is not ready. This lets the Frontend Map's Blueprint BeginPlay create a project-owned background first while preserving reliable native login bootstrap. The native full-screen dim backdrop is disabled by default; the centered login/play/admin card remains styled and interactive above the project's background.
