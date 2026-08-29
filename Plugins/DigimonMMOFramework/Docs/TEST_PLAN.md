# UE5.8 Validation Plan — 0.18.5-alpha

## S0 — v0.18.5 replicated world-chat presence acceptance

1. Open **Project Settings → Game → Digimon MMO Framework → UI → World Chat → Presence** and confirm **Announce Player Join / Leave** and **Play Player Join / Leave Sounds** default enabled. Assign clearly different Sound Cues/Waves to **Player Joined Server Sound** and **Player Left Server Sound**.
2. Start Host & Play with an established account. Confirm the host receives exactly one green-name `Username has joined the server.` row and one join cue. The username must match the authenticated account, not an arbitrary client-submitted string.
3. Join from a second account. Confirm host and remote each receive exactly one live join row and each plays the join cue once. Ordinary player chat must remain cyan username + white message.
4. Disconnect the remote client. Confirm the host receives exactly one leave row; username and `has left the server.` body are red and the leave cue plays once. Confirm the server still commits disconnect persistence and removes the transient summoned partner before normal teardown.
5. Reconnect the same remote account to the still-running host. Confirm v0.18.2 account state restores correctly and the reconnect emits exactly one new join announcement/sound on both peers. Repeat at least three disconnect/relogin cycles and verify no duplicated presence events.
6. Send text such as `PlayerX has joined the server.` manually. It must remain an ordinary player message and never acquire `PlayerJoined`/`PlayerLeft` authority, special native styling or presence sound.
7. Generate several join/leave events, then connect a late third client with `WorldChatServerHistoryLimit > 0`. The retained presence rows may appear in history, but historical presence entries must be silent. Only the late client's own live join event may play the join cue.
8. Disable **Play Player Join / Leave Sounds** and repeat one join/leave. Presence rows/colors must still replicate, with no audio. Re-enable sounds, leave the join asset unassigned and verify only the configured leave cue plays.
9. Disable **Announce Player Join / Leave** while leaving WORLD chat enabled. Join/leave must produce neither presence text nor presence audio, while ordinary world chat continues normally.
10. Disable **Enable World Chat** entirely. Confirm no native chat/presence presentation is generated and normal chat submissions remain disabled as before.
11. Blueprint-skin regression: bind/inspect `FDMFWorldChatMessage.MessageType` and verify `PlayerJoined` / `PlayerLeft` arrive through existing `OnWorldChatMessageReceived`, `BP_OnWorldChatMessageAdded`, and GameMode `BP_OnWorldChatMessageAccepted` hooks without a new network endpoint.
12. Re-run v0.18.4 capacity=2 admission, v0.18.3 vendor BUY/SELL, v0.18.2 same-host reconnect, abrupt disconnect persistence, Party/Bank privacy, world-location restore, Return Home, swimming/underwater, Day/Night, combat, DigiDex, Digivolution and Care. Account schema must remain v7 and RPC count 49.

## S0 — v0.18.4 global maximum-player capacity acceptance

1. Open **Project Settings → Game → Digimon MMO Framework → Networking → Server Capacity** and confirm **Global Maximum Players** exists and defaults to `100`. Confirm the setting is config-backed and Blueprint-readable through the developer settings class.
2. Temporarily set **Global Maximum Players = 2**. Start **Host & Play** and confirm the status indicates a two-player authoritative host. The listen host consumes slot 1.
3. Join from one separate packaged client/account. It must authenticate, load its persistent account and enter gameplay normally as slot 2.
4. Attempt to join from a second remote packaged client/account while both slots are occupied. The server must reject the new connection as full. The existing host/client must remain connected and their Party/Bank/partner state must be untouched.
5. Disconnect the first remote client and immediately retry the previously rejected client. It must now join successfully, proving the slot is released through normal disconnect/GameSession lifecycle.
6. With the cap still at 2, manually connect a client using a URL that attempts `?MaxPlayers=9999` (or equivalent custom travel options). The authoritative server must still enforce 2 because DMF reasserts Project Settings before `Super::PreLogin`.
7. While two players are connected in PIE, lower the editor Project Settings cap to 1. Existing players must **not** be kicked. A new connection must be denied until occupancy falls below the new cap. Restore the setting afterward.
8. Restore **Global Maximum Players = 100**, restart the host and confirm `Host & Play` uses 100 again. Regression-test v0.18.3 BUY/SELL vendor UI, authenticated same-host reconnect, disconnect-save/partner cleanup, world-location restore, Return Home, swimming/underwater, Day/Night, combat, Party/Bank, DigiDex, Digivolution, Care and world chat.

## S0 — v0.18.3 polished native Digimon vendor UI acceptance

1. At 1920x1080, open the native Digimon Exchange BUY tab with a stock Digimon that has nonzero level, Lifetime Battle EXP, ABI/CAM, spent/unspent Attribute Points and Digivolution history. Confirm **COMBAT & PROGRESSION** and **MARKET VALUATION** render as separate cards with no overlapping lines, clipped text, button collision or text painting through adjacent widgets.
2. Select enough/high-progression data to exceed the visible detail body. Confirm only the detail-information region scrolls; portrait/name/meta remain fixed above it and BUY/CONFIRM BUY plus CLOSE remain fixed below it. Mouse-wheel scrolling must reveal every statistic/value line.
3. Verify BUY list rows maintain stable height and readable spacing for long species names and 4-6 digit prices. Confirm `BUY PRICE` and the Bits amount are visually separated and no price text collides with species metadata.
4. Switch to SELL with Party and Bank Digimon present. Confirm `SELL QUOTE`, `+N BITS`, and `PARTY` / `BANK` are separate lines/roles; no storage label is concatenated into the price line and no row content overlaps.
5. Select Party and Bank Digimon with different progression. Confirm the right panel updates cleanly on every selection, the sell quote matches the server-derived value, starter/final-Party protection messages remain readable, and the transaction button disables/enables exactly as before.
6. Exercise the full two-step BUY and SELL confirmation paths. Confirm the UI polish changes do not alter the server-authoritative payload: client still submits only vendor + transaction direction + GUID, and price/ownership/range/storage are still revalidated by authority.
7. Test 2560x1440, 1920x1080 and a viewport small enough to trigger ScaleToFit. Confirm the whole vendor window remains on-screen, text is readable, both scroll regions work, and pinned controls remain accessible.
8. Listen host + remote client: open the same vendor simultaneously, rotate stock, buy one offer, sell one owned Digimon and reconnect. Confirm replicated stock/countdown, Bits, Party/Bank persistence and v0.18.2 authenticated reconnect behavior are unchanged. SaveGame schema must remain v7 and RPC count must remain 49.

---

# UE5.8 Validation Plan — 0.18.2-alpha

## S0 — v0.18.2 same-host remote reconnect persistence acceptance

1. Package a Shipping listen-server build and remote Shipping client on separate PCs. Keep the host process running for the entire first test. Use an established remote account with selected avatar, Party/Bank Digimon, active partner, Bits and obvious saved progression.
2. Join the host, make an unmistakable authoritative change, then disconnect the remote client. Confirm its summoned partner is destroyed on the host.
3. **Without closing/restarting the host**, immediately reconnect the exact same remote account. Confirm avatar selection does not reopen, starter selection does not reopen, Party/Bank are intact, Bits/progression are intact and the active partner reconstructs normally.
4. Repeat disconnect/reconnect at least five times while the host remains continuously running. Every reconnect must load the same evolving account; no cycle may become an empty/fresh PlayerState.
5. After those cycles, restart the host once and reconnect. The result must be identical to the same-host reconnect result; host restart must no longer change whether account data is visible.
6. Repeat with abrupt client process termination/network loss. After the server detects the disconnect, reconnect without restarting host and verify identical restoration.
7. During one disconnect, observe that no orphan Digimon remains in world and no stale inactive DMF PlayerState is reused on reconnect.
8. Regression-check schema-v7 vendor purchases/sales, swimming/underwater reload, Day/Night, world location and host account persistence. RPC count must remain 49.

## S0.1 — v0.18.1 disconnect-finalization regression

1. Package a Shipping listen-server build and Shipping client build on separate PCs. Use an existing client account with a selected player avatar, at least one Party Digimon, at least one Bank Digimon if available, a summoned active partner, non-default Bits and known ABI/stats.
2. Make a fresh authoritative change on the remote client account (earn EXP/Bits, spend an Attribute Point, change active partner or move to an unmistakable location). Disconnect/close the client **before** `AccountAutosaveInterval` expires.
3. On the host, confirm the disconnected player's summoned partner is destroyed when logout is processed. No orphan partner may remain targetable, moving or fighting in the world.
4. Reconnect with exactly the same username/password. Confirm the account is not treated as fresh: avatar selection must not reopen, starter selection must not reopen, Party/Bank must be restored, the active partner must resolve correctly and the latest committed values must remain.
5. Repeat step 2 using an abrupt process close / network loss rather than a clean frontend path. Reconnect after the server detects the disconnect and verify identical restoration.
6. Run three rapid disconnect/reconnect cycles. Confirm the idempotent GameMode Logout + PlayerController EndPlay paths do not double-save, clear Party/Bank, reset avatar selection or duplicate/destroy persistent Digimon.
7. Force/inspect an initialization-failure path if practical. Confirm the server logs that it refuses a disconnect save from an uninitialized account component and preserves the previous persistent record rather than overwriting it with defaults.
8. Regression-check schema-v7 vendor persistence, vendor purchase/sale, lifetime battle EXP, spent Attribute Points, ABI/Digivolution history, saved world location, swimming reload reconstruction and host account persistence. RPC count must remain 49.

# UE5.8 Validation Plan — 0.18.0-alpha

## S0 — v0.18.0 replicated Digimon vendor economy acceptance

### Native vendor / stock generation
1. From the accepted v0.17.3 project, create `BP_DigimonVendor_Test` derived from `DMFDigimonVendorActor`, assign an obvious NPC mesh, add Agumon and Gabumon Species Data Assets to `Species Pool`, set `Stock Slots=4`, Level `1-10`, ABI `0-50`, Spent Attribute Points `0-20`, and temporarily set stock rotation to `30-45 seconds`.
2. Place exactly one vendor and interact using the normal player interaction call/trace. Confirm the native modal opens without Blueprint casts, shows the configured vendor name/subtitle, BUY/SELL tabs, Bits, countdown and four stock rows. Close/reopen repeatedly and confirm normal quickbars/input restore cleanly.
3. Inspect every generated offer. Confirm level, current-level EXP, ABI, CAM and stat training vary inside the authored ranges; HP/SP/STR/INT/DEF/SPD include normal species level growth, the explicit min/max natural stat rolls and then rolled spent Attribute Points. With a narrow fixed level and spent-points range, confirm same-species offers can still differ through the natural HP/SP/combat-stat ranges, and confirm those natural rolls do **not** inflate `TotalAttributePointsSpent`. Confirm the server does not generate invalid GUID/species entries.
4. Let the timer expire twice. Confirm each rotation changes stock on authority, both peers converge on exactly the same StockIds/offers/prices, the countdown restarts from synchronized server time and the vendor actor never requires Tick.

### Buying / concurrency / persistence
5. Give both test accounts sufficient Bits. On the remote client select one stock Digimon and click BUY once: verify only the confirmation state is armed and no money/stock changes. Click CONFIRM BUY: verify the server deducts the exact offer price once, adds the exact generated individual to Party/Bank, removes the shared offer and saves immediately.
6. Reconnect the buyer. Confirm the purchased Digimon retains its generated InstanceId/species/level/EXP/stats/ABI/CAM/training values and remains in the correct Party/Bank storage.
7. Have host and client select the same remaining StockId, then confirm as nearly simultaneously as possible. Exactly one purchase may succeed; the other must receive the stock-gone rejection. No duplicated Digimon, negative Bits or double stock removal is allowed. Also bind a test vendor Blueprint callback to the successful trade/account-change path and attempt immediate same-StockId re-entry; the reserved offer must already be unavailable.
8. Fill both Party and Bank, attempt another purchase and confirm server rejection. Test `Prefer Purchased Digimon To Bank` with room in both, then with preferred storage full and alternate storage available.
9. Start Care, Digivolution or active combat under the existing Party-mutation policy and attempt a purchase. Confirm the server reuses the established mutation lock and does not partially deduct money.

### Selling / automatic progression valuation
10. In SELL, compare two same-species individuals where one is clearly higher level/EXP/stats/ABI. Confirm the stronger/trained individual receives the higher automatic quote. Verify the detail panel explicitly shows Lifetime Battle EXP, ABI/CAM, spent/unspent Attribute Points, forms visited and the value contributions.
11. Spend one Attribute Point on an owned Digimon, reopen/refresh SELL and confirm `TotalAttributePointsSpent` increases by exactly one and its market/sell value responds to the configured training weight. Gain battle EXP and confirm `LifetimeBattleExperience` increases and affects price even if the Digimon is already at max level.
12. Digivolve and De-Digivolve a persistent individual using the normal system, increasing ABI through the existing progression rules. Confirm the same InstanceId retains lifetime EXP/training provenance and that the higher ABI materially raises its vendor value.
13. Select a nonstarter owned Digimon and click SELL once: no mutation. Click CONFIRM SELL: the server recalculates the quote, removes that exact instance, credits Bits once and saves immediately. Reconnect and confirm both collection and money persist.
14. Attempt to sell a protected starter with default vendor settings and confirm rejection. Attempt to sell the final Party member with `Require At Least One Party Digimon=true` and confirm rejection with no partial mutation.
15. Sell the active nonstarter partner while another Party member exists. Confirm the old actor is removed/reconciled through the existing Party contract, replacement active partner state is valid, the sale persists, and no stale command target remains.

### Security / per-vendor configuration / regression
16. Move/teleport the player outside the vendor's trade radius and attempt a stale transaction request. Confirm server rejection regardless of what the local UI displayed. Rapidly spam transaction requests and confirm the server throttle plus stock/ownership validation prevents duplicate money or Digimon.
17. Place a second vendor with a different Species Pool, level/ABI range, pricing, rotation interval and Buy/Sell policy. Confirm each placed NPC maintains its own independent stock/scheduler/UI identity and server validation.
18. Authority-call `Set Buying Enabled`, `Set Selling Enabled`, `Set Pricing Settings`, `Set Vendor Enabled`, `Refresh Stock Now` and `Restart Stock Rotation Schedule`; confirm relevant public config/stock updates reach the remote client and the server remains final authority.
19. Load a pre-v0.18/v6 account. Confirm migration to schema v7 preserves Party, Bank, active partner, stats, ABI, Digivolution history, Bits and saved world location while conservatively initializing Lifetime Battle EXP / Total Attribute Points Spent and setting `DigimonEconomyProvenanceVersion = 1`. Save/reconnect again and confirm the v7 values remain stable rather than being re-inferred. Separately purchase/generate a high-level Digimon with exactly 0 spent Attribute Points and reconnect; it must remain exactly 0 rather than being mistaken for a legacy individual.
20. Regression test accepted v0.17.3 host/client swimming presentation (including no shake), underwater save/reload/fog, Day/Night clock/spawner populations, combat/abilities, healer, DigiDex, Digivolution, Party/Bank, world chat, Return Home and frontend login.

## v0.16.0 Day / Night sky + population acceptance

1. Place one Blueprint derived from `DMFDayNightSky` in Open World. **Before PIE**, keep `Preview Sky In Editor=true` and scrub `Initial Simulated Time Hours`: verify 00:00 is night, 06:00 horizon/dawn, 12:00 is full day with the native Sun overhead, 18:00 horizon/dusk, and `bIsDay`/`bIsNight` match the configured phase bounds. The editor must update without Play/Simulate.
2. Run listen-server PIE plus one remote client. With persistence temporarily disabled/cleared for this initialization test, set `Initial Simulated Time Hours=12.0` and verify both peers start in Day (not the old inverted night/sunset presentation). Then use a 60-second day and confirm host/client time, sun/material motion and Day/Night phase remain synchronized through multiple transitions.
3. Stop/restart the session and confirm simulated time restores from the shared world-state save.
4. Host-PC mode: confirm the server follows the host machine local clock and the remote client follows that server-authored time rather than its own PC clock.
5. Verify `Is Day`, `Is Night`, `Get Time Of Day Hours`, `Get Current Day Index` and phase events on both peers.
6. Assign a translucent digital inner-layer material/texture with obvious alpha holes. Confirm the texture remains enabled in Day and Night and the outer sky remains visible behind transparent texels.
7. Configure one wild spawner for Day/Night with clearly different species arrays and rarity weights. Confirm only the correct table produces new Digimon for each phase.
8. Cross a phase boundary with no combat: old ambient population should ground-despawn and the new population should stagger in.
9. Cross a boundary while fighting an old-phase Digimon: with the default safety setting, that encounter must remain intact until combat ends, then retire without scheduling an old-phase replacement.
10. Verify the spawner's normalized rarity behavior still matches v0.14.5 within both Day and Night tables.
11. Verify no client can change time or choose population entries and that spawned actors remain normally replicated.


## S0 — v0.15.3 canonical species-stage presentation acceptance

1. Set a Botamon/Fresh Species Data Asset to **Stage = Fresh** (the editor dropdown display for the preserved first-stage enum value). Spawn it as a wild Digimon and confirm its world nameplate reads **Fresh**, never `BabyI` / `Baby I`.
2. Set an In-Training species to **Stage = In-Training** and confirm the world nameplate reads **In-Training**, never `BabyII` / `Baby II`.
3. Verify one species for every configured stage used by the project. World nameplates must exactly follow that species asset's Stage value.
4. Open Starter Selection, Party, Bank / Boxes, Scan & Materialize, Care, DigiDex and Digivolution. Confirm the same species reports the same canonical stage in every native surface.
5. In DigiDex, search for `Fresh` and cycle the stage filter to Fresh; verify Fresh species match. Legacy words `BabyI`/`BabyII` must not be required for search/presentation.
6. Call Blueprint **Get Digimon Stage Display Text** for every `EDMFDigimonStage` value and verify: Fresh, In-Training, Rookie, Champion, Ultimate, Mega, Ultra, Armor, Hybrid, Unknown.
7. Load existing Species Data Assets authored before v0.15.3 and confirm their saved stage values are unchanged; no asset migration, save wipe or Blueprint enum remapping should be needed.
8. Listen host + remote client: observe the same wild/partner species from both peers and confirm stage text is consistent while all existing combat/nameplate replication remains unchanged.


## Native Return Home HUD acceptance (v0.15.2)

1. Use the runtime-validated v0.15.1 world setup with one enabled `DMFNewPlayerStart`; set `Enable Party Quick Access Home Button=true`.
2. In gameplay verify no standalone permanent Home widget clutters the screen. Press **Tab** and confirm the Party Quick Access action row exposes **HOME** beside Recall/Party/Bank.
3. Move the player far from the Home spawn, click HOME and confirm the row shows a pending state, then the authoritative player appears at `DMFNewPlayerStart` and Tab interaction closes automatically.
4. Confirm an owner-only **HOME • ARRIVED** toast appears and normal movement/look/mouse state returns.
5. With a summoned partner, start a real battle and launch/receive a projectile, then Home. Confirm battle music can release, partner/enemy target state does not remain latched, targeted framework projectiles do not arrive at Home, partner appears beside the player, HP/SP remain unchanged and existing ability cooldowns are not reset.
6. Immediately spam Home again and confirm the server cooldown rejects it with **HOME • UNAVAILABLE** feedback rather than accepting another teleport.
7. Wait for cooldown and repeat; then disconnect/reconnect before the normal autosave interval and verify the immediate Home checkpoint restores the Home position.
8. Disable/remove every `DMFNewPlayerStart` and confirm Home fails safely without moving the player. Re-enable a start but obstruct it and confirm the collision failure reports cleanly.
9. Listen host + remote client: place both accounts in different areas, invoke Home separately, confirm each server pawn/partner teleports independently, only the owning player sees each result toast, and normal replication shows the moved actors to the peer.
10. Regression-check Party slot switching, Recall/Open Party/Open Bank, v0.15.1 normal autosave/returning-player restore, Attribute Point saving, combat, world chat, music and frontend travel.


## Persistent player world location / first-login spawn acceptance (v0.15.1)

1. Place one normal `PlayerStart` and one `DMFNewPlayerStart` far apart in the Open World. Keep both persistence settings enabled.
2. Create a fresh account. Confirm the authoritative player avatar appears at `DMFNewPlayerStart`, not the normal PlayerStart. Complete onboarding as needed and confirm the active partner spawns relative to the final player position.
3. Move the player to a clearly different location/rotation. Wait longer than `AccountAutosaveInterval` or disconnect normally. Reconnect the same account and confirm it restores that saved location instead of the new-player start.
4. Move again, disconnect before the next periodic autosave, and confirm Logout captured the latest position.
5. Fresh-account crash-safety check: enter with a new account, then disconnect immediately after spawn. Rejoin and confirm the first spawn checkpoint prevents the account from being treated as new again.
6. Two-account PIE/packaged test: host Account A and remote Account B, move them to different areas, save/disconnect, reconnect independently, and confirm each account restores only its own coordinates.
7. Disable/remove every `DMFNewPlayerStart`, use another fresh account, and confirm normal PlayerStart fallback succeeds and becomes the first saved checkpoint.
8. Obstruction safety: save a location, then place blocking geometry over it before reconnect. Confirm the framework does not force the avatar into invalid geometry and safely keeps the normal PlayerStart result.
9. Map-safety: alter the saved/current map identity through a test copy or map rename and confirm mismatched saved coordinates are not applied to the wrong level.
10. Regression: verify player skin, starter/active partner, Party/Bank, Attribute Points, EXP progression, combat, chat/nameplates, music and frontend login still load normally.

# UE5.8 Validation Plan — 0.14.8-alpha

Run these tests after the plugin compiles in the target UE5.8.1 project. v0.14.8 adds server-authoritative owned-Digimon level progression and owner-only EXP/LEVEL UP presentation over the runtime-accepted v0.14.7 combat baseline. Do not promote v0.14.8 to runtime-accepted until the progression tests below pass on listen host + remote client.



## L0 — v0.14.8 owned-Digimon Level / EXP progression acceptance

### Baseline threshold + native UI
1. On the active partner's `DMFDigimonSpeciesData`, set `Base Experience Required=100`, `Experience Growth Multiplier Per Level=1.20`, and leave `Default Max Digimon Level=99`. Use a Level 1 active partner at `0 EXP`.
2. Give one wild species `Battle Experience Reward=25` and defeat it once. Confirm the owner Party detail and popup report Level 1, `25 / 100`; no other player's private Party/Bank UI changes.
3. Defeat the same reward source three more times. Confirm progression is `50 / 100`, `75 / 100`, then **Level 2 / 0 / 120**. The fourth reward must show the distinct LEVEL UP state.
4. Verify every reward shows the queued owner-only `+EXP` popup with a smooth progress animation and that the normal combat/Party quickbars remain usable beneath its safe-lane offset.
5. Open **I -> PARTY** and **BANK / BOXES** and inspect Digimon in both storage tiers. Each selected profile must show current Level, `EXP current / required`, a matching progress bar and unspent Attribute Points; max-level Digimon must show `MAX`.

### Growth / combat continuity
6. Author unmistakable per-level values on the active species (for example HP +10, SP +5, STR/INT/DEF/SPD +2, Attribute Points +3), cross one threshold and confirm each persistent value increases exactly once.
7. Before the winning reward, damage the partner and spend SP. After level-up, confirm the missing HP/SP amount is preserved relative to the newly increased capacity; the reward must not perform a full heal.
8. Confirm level-up does not clear the active target prematurely, reset cooldowns, cancel recovery, reset the battle-encounter latch or reinitialize automation/combat state. Battle victory teardown should otherwise behave normally.
9. With the partner summoned, observe it from the other peer. Confirm public replicated Level/stats/nameplate refresh without respawning the actor solely for progression.

### Species scaling / multi-level / caps
10. Set one species to `Base Experience Required=80`, `Experience Growth Multiplier Per Level=1.50`; confirm authority and native UI both resolve approximately `80 -> 120 -> 180 -> 270` for Levels 1-4. No CurveFloat asset should be needed anywhere.
11. Give another species a different base/multiplier (for example `150` / `1.10`) and confirm its required EXP is independent of the first species. Set multiplier to `1.0` and confirm that species has a flat per-level requirement.
12. Grant one large Battle EXP reward that crosses at least three levels. Confirm all thresholds are subtracted, all per-level stat/Attribute Point growth is multiplied by levels gained, remainder EXP lands in the final level, and the popup animates through the crossed segments.
13. Set a low `Max Level Override`, reach it, and confirm stored progress becomes `0`, the UI displays `MAX`, further Battle EXP cannot raise Level beyond the cap, and a later lower configured cap never de-levels an already higher persistent Digimon.

### Persistence / migration / networking
14. Load an account created on v0.14.7 with enough previously banked EXP to cross thresholds. Confirm authority normalizes it once into the earned Level/stat/Attribute Point result without deleting the owned Digimon or changing GUID/Party/Bank placement.
15. Save/reconnect after normal and multi-level gains. Confirm Level, current-level EXP, grown stats and unspent Attribute Points persist exactly.
16. Repeat reward + level-up with the **remote client as owner**. Listen host should see the remote partner's public Level/stat result but must not receive that owner's EXP popup or private Party/Bank EXP ledger.
17. Attempt to spoof progression from client/Blueprint UI. There must be no client RPC that accepts reward amount, new Level, threshold, grown stats, Attribute Points or max-level state.
18. Bind a Blueprint child to `Experience Notification Widget Class`; verify `BP On Experience Progress Presented` and `BP On Level Up Presented` receive the committed snapshot while changing it locally has no gameplay effect. Disable `Show Native Experience Notifications` and confirm gameplay leveling still works with no native toast.
19. Regression: after a progression reward, re-run wild full-moveset combat, projectile/VFX CustomDepth, persistent Battle music, rarity-weight spawning, DigiDex, Digivolution, Party/Bank, Scan/Materialization, Care/healer, chat/nameplates, camera/footsteps and account login/reconnect.

## G0 — v0.13.1 Digivolution owned-roster layout acceptance

1. Open `I → DIGIVOLUTION` with exactly **one** Party Digimon. Confirm its card remains compact and centered; it must not fill the complete Owned Digimon panel width.
2. Add a second Party Digimon. Confirm both cards remain the same fixed size and both portraits preserve their original aspect ratio.
3. Fill all six Party slots. Confirm the roster forms **two clean rows of three** without portrait squashing, footer overlap or badge overlap.
4. Add Bank Digimon and scroll the Owned Digimon browser. Confirm Bank cards use the identical card/portrait geometry and scrolling does not compress rows.
5. Test at 1920×1080 and a smaller PIE window. The outer menu may down-scale, but individual portraits must remain proportional.
6. Select Party and Bank entries and confirm selection, target path evaluation and Digivolution actions behave exactly as v0.13.0.

## G1 — v0.13.0 Digivolution gameplay acceptance

Run these after a clean UE5.8.1 Editor compile and before promoting the source package to runtime-accepted baseline.

### Data / UI
1. Configure Agumon with at least two target paths; confirm both appear in **I → DIGIVOLUTION** with correct target portrait/stage/attribute and READY/LOCKED requirement summaries.
2. Verify Party and Bank Digimon both appear in the Owned Digimon browser and selecting either never changes Party/Bank placement by itself.
3. Resize PIE to the normal smaller test window and verify owned cards, path cards, requirement text and action button remain within the hardened v0.12.1 layout.
4. Disable the Digivolution master setting and confirm authoritative attempts are rejected cleanly.

### Authority / persistence
5. Attempt a path below Required Level, ABI, CAM, stat, Care and money gates; each must remain server-rejected even if the client UI/request is manipulated.
6. Perform a successful unsummoned Party evolution and confirm GUID, nickname, Level/EXP, ABI/CAM, Care and Party slot persist while species changes.
7. Perform a successful Bank evolution with Bank allowed; confirm Bank slot remains owned, no world actor spawns, and only the owning account sees the private storage update.
8. Disable global Bank Digivolution or path `Allow From Bank`; confirm the same Bank request is rejected.
9. Verify Money Cost is deducted exactly once on successful commit and not on rejection/interruption.
10. Reconnect and confirm species, Origin Species, Digivolution History, Party/Bank placement and active partner persist under SaveGame schema v5.

### Summoned world transformation — host + remote client
11. Host summons an eligible partner and Digivolves it. Both host and remote client must see/hear the transformation cue; only the owner UI hides/reopens.
12. At commit, old actor is replaced by the target species World Actor Class and is correct on both peers.
13. Repeat with the remote client as owner; listen host must see the same public transformation/result while remaining unable to view the remote client's private Party/Bank arrays.
14. Confirm active combat blocks the active partner when configured. During an active transformation, attempt Recall, Set Active, Party/Bank move, Care feed, healer use, target change and ability command; all conflicting server actions must remain locked.
15. Verify Niagara primary, Niagara-missing Cascade fallback, path-specific override and global fallback Sound Cue behavior.
16. With `Hide UI For Summoned Digivolution` disabled, confirm the transformation still commits/replicates and the menu remains usable as presentation only.

### Regression
17. Materialize a new Digimon after evolution; Party-first/Bank-overflow routing remains correct.
18. Heal evolved Party+Bank Digimon; v0.12.2 healer and persistence remain correct.
19. Feed/care for evolved active partner; species-specific Care data and existing persistent Care state remain coherent.
20. Run combat, world chat, nameplate, camera zoom, music, footsteps, Party Quick Access and account reconnect regressions.

## H0. v0.12.2 polished healer treatment acceptance

1. Derive/place `BP_DigimonHealer` from `DMFHealerActor` and add the project's medical-capsule mesh under the actor root. Move `Healing Presentation Anchor` (or set `Healing Presentation Relative Transform`) so the rig sits inside the chamber.
2. Assign a looping green-plus `Healing Niagara System`. Optionally assign a Cascade equivalent and a spatial/attenuated healing Sound Cue. Confirm `Prefer Niagara Healing VFX=true`.
3. Damage Party Digimon and at least one Digimon stored in a non-current Bank/Box page. Defeat one Party member if revival is enabled.
4. Use the healer as host. Confirm one authoritative interaction restores HP/SP for every changed Party and Bank/Box Digimon, revives configured defeated Digimon, persists immediately and optionally re-summons the active partner.
5. While the treatment is active, verify the interior point light fades/pulses green, Niagara activates, the heal sound plays, and the effects stop/fade after `Healing Sequence Duration`.
6. Repeat with Niagara unassigned and Cascade assigned. Confirm the Cascade fallback activates. Reverse `Prefer Niagara Healing VFX` with both assigned and confirm Cascade is preferred.
7. During an active treatment, have a second client use the **same healer actor**. The server must reject it with Busy Message. A separate healer actor should remain independently usable.
8. Observe the treatment from host and remote client. Both must see/hear the same active station. No client may directly alter healer busy state or heal values.
9. Join/possess a client while the healer is already active. Replicated durable state should cause the late viewer to reconstruct the treatment presentation for the remaining active period/state rather than requiring a one-shot multicast to have been received.
10. Disable the healer on authority during treatment. Confirm the replicated sequence stops cleanly and new requests fail with Disabled Message. Re-enable and retest.
11. Leave Niagara/Cascade/Sound unassigned. Confirm the built-in green light still presents a valid healing state and no null-asset error occurs.
12. Verify dedicated-server/headless execution does not create audible/rendered presentation work; gameplay healing and persistence remain authoritative.

## U0. v0.12.1 native UI layout-hardening acceptance

1. Run 1920x1080 and a smaller PIE viewport (for example ~1600x900). Open PARTY, BANK / BOXES, SCAN & MATERIALIZE, DIGIDEX, DIGIVOLUTION and CARE and verify no text draws outside its panel or through an action button.
2. Select Digimon with long species descriptions. Verify Party/Scan description regions scroll/clip inside the right panel while **SET ACTIVE / SUMMON**, **RECALL**, **MOVE TO BANK** and **MATERIALIZE DIGIMON** remain fully visible.
3. Open BANK / BOXES with 30 slots per page. Verify all six columns keep uniform card dimensions; resize to a shorter viewport and confirm the Box grid scrolls rather than vertically compressing rows.
4. Temporarily raise `DigimonBankSlotsPerPage` above 30 and verify additional rows remain accessible through the Bank grid scroll region without moving the Party Destination strip out of bounds.
5. Select a Bank Digimon and exercise no-destination, free-Party-slot and full-Party destination messages. Verify the guidance stays inside the scroll body and **MOVE / SWAP TO PARTY** remains pinned below it.
6. Inspect the persistent Party Quick Access HUD. Verify every slot has a readable portrait plus two-line state/name/level layout and HP bar; no `ACTIVE`, Digimon name or level text is squeezed beside the portrait.
7. Inspect the combat quickbar with abilities that have no icon assigned. Verify the empty icon square is collapsed and the ability name/SP/READY text uses the full card width. Assign an icon to one ability and verify only that card restores its icon frame.
8. Press Tab and confirm the Party action row remains clean/readable, then perform a partner switch and confirm authority/replication is unchanged.
9. Repeat v0.12.0 section **P0** storage/materialization/persistence tests to prove this patch did not alter gameplay state.

## P0. v0.12.0 Party + Bank / Boxes + Party Quick Access acceptance

1. Open Project Settings and confirm **Party & Bank** exposes Max Party Digimon, Max Digimon Bank Storage, Bank Slots Per Page and the combat-switch rule; confirm **UI → Party Quick Access** exposes widget class, native visibility, default Tab input and bottom safe offset.
2. Compile in UE5.8.1, then run a listen host + remote client with different accounts. Confirm each peer sees only its own Party/Bank contents.
3. Open `I` from the world and confirm visual tab order is **PARTY → BANK / BOXES → SCAN & MATERIALIZE → DIGIDEX → DIGIVOLUTION → CARE** with the existing polished style intact.
4. Deposit a non-active Party member into Bank. Verify Party and Bank update once, account persistence occurs, and the final Party member cannot be deposited.
5. Withdraw a Bank Digimon while Party has free capacity. Verify it enters Party and the Bank entry disappears exactly once.
6. Fill Party to six, choose a Bank Digimon and an occupied Party destination, then execute **MOVE / SWAP TO PARTY**. Verify the two instances exchange storage atomically with no duplicate/lost GUID.
7. Repeat the swap against the active/summoned Party slot. Verify the incoming instance becomes active and the authoritative world partner refreshes for host and remote observer.
8. Enter Chasing/Attacking/Recovering combat with the default combat lock. Verify Party/Bank transfer and changing active partner are rejected. End combat and verify they work again.
9. Materialize with Party space and verify the new instance enters Party. Fill Party, materialize with Bank space and verify it routes to Bank. Confirm owned-species count includes both tiers.
10. Press **Tab** independently on host/client. Only that local viewport should show cursor/release movement+look; the other client must remain in normal gameplay input.
11. In Party Quick Access mode click a healthy Party slot and verify the authoritative partner switch. Test **RECALL**, **OPEN PARTY** and **OPEN BANK**, then Tab/Escape back to gameplay.
12. Confirm Party Quick Access remains visible in normal gameplay, does not overlap the combat quickbar, and hides/restores correctly around modal Digimon UI and Care feeding presentation.
13. Load a copied pre-v0.12 account containing more than six legacy `DigimonInventory` entries. Verify previous active partner is in Party, remaining Party positions retain order, overflow appears in Bank, existing Bank entries are preserved/de-duplicated, and no valid instance GUID is intentionally lost.
14. Restart/relogin both accounts and verify Party order, Bank contents, active partner, Care/Scan data and all earlier progression persist.
15. Run packaged host + second PC and repeat transfer, active-slot swap and Tab Quick Access tests before accepting the milestone.

## C0. v0.11.1 camera boom zoom & collision acceptance

1. In Project Settings → Digimon MMO Framework → Camera → Zoom, confirm the master switch, default input, default/min/max boom distances, wheel step and interpolation speed are exposed.
2. Confirm Camera → Collision exposes **Ignore Players And Digimon For Camera Collision** and it defaults enabled.
3. Run listen host + remote client PIE. On each window independently, Mouse Wheel Up must zoom in and Mouse Wheel Down must zoom out.
4. Repeated scroll input must stop exactly at the configured minimum/maximum requested boom lengths.
5. With interpolation speed above zero, zoom transitions must be smooth; setting it to zero must permit immediate changes.
6. Put the second player between the first player and camera. The first spring arm must not retract because of that player. Repeat in the opposite direction.
7. Walk/summon an owned Digimon and place a Wild Digimon between camera and player. Neither may retract the boom.
8. Back the camera toward a wall or other level geometry that blocks `ECC_Camera`; normal spring-arm collision retraction must still work.
9. Verify Player/Digimon Visibility targeting, player-player collision, movement, combat, footsteps, nameplates and interaction remain unchanged.
10. Set host and remote client to different zoom distances and confirm there is no cross-client coupling or new network traffic requirement.

## M0. v0.11.0 global music director acceptance

1. Open **Project Settings → Game → Digimon MMO Framework → Audio → Music**. Assign three clearly distinguishable test Sound Cues to **Frontend / Main Menu Music**, **Open World Music**, and **Battle Music**. Keep **Enable Framework Music** and **Automatically Loop Music** enabled.
2. Compile in UE5.8.1 and launch the normal Frontend. Confirm exactly one Frontend music stream plays; opening login/admin/menu panels must not restart or layer duplicate music.
3. Host & Play into the configured Open World. Confirm Frontend music survives the travel boundary only long enough to crossfade cleanly into Open World music, with no doubled persistent track afterward.
4. Join from a remote client. Confirm that client independently transitions from its Frontend music to Open World music and does not inherit the host's AudioComponent/playback position.
5. Select/Interact with a hostile Digimon as a command target but do **not** attack. Music must remain Open World.
6. Issue an ability so the active partner enters `Chasing`, `Attacking` or `Recovering`. The fighting local player must crossfade to Battle music and `Is Battle Encounter Active` must become true from replicated authority.
7. **v0.14.4 regression:** after that attack finishes, press no combat button for at least 15 seconds (well beyond the default 1.5-second release delay) while the enemy remains alive. The partner may sit in `Idle`, but Battle music must continue without interruption and the encounter query must remain true.
8. Resume attacking the same enemy. There must be no Open World -> Battle restart because the same battle never ended.
9. While Host fights, leave Client out of combat. Client must stay on Open World music. Repeat with Client fighting while Host remains idle. This proves encounter truth replicates normally while music remains local presentation rather than global multicast state.
10. Win the battle. The encounter query must clear, Battle music must remain stable only for the configured **Battle Music Release Delay Seconds**, then crossfade back to Open World exactly once.
11. Repeat and allow the local active partner to be defeated. The encounter must clear and return to Open World after the release delay; Battle music must not become stuck.
12. Exercise an authoritative target-clear/disengage/reset path (for example healer/reset or auto-battle leash teardown) and verify it also clears the durable encounter safely.
13. Select a second hostile target without attacking it. The encounter must remain false and music must stay Open World.
14. Clear the **Battle Music** asset and repeat a fight. The state may report Battle, but audible playback must gracefully remain/fall back to Open World music instead of becoming silent. Restore the Battle asset afterward.
15. Use a non-looping test music asset and wait for it to finish. With **Automatically Loop Music** enabled it must restart cleanly. Disable automatic looping and verify the framework does not restart it.
16. Set **Music Crossfade Seconds** to `0` and verify immediate state cuts; restore the preferred production fade. Test master/per-state volume controls.
17. Disable **Enable Framework Music** and restart PIE. No framework music should play on Frontend or Open World. Re-enable it.
18. If using a cinematic, call **Set Music Suppressed(true)** from the Game Instance Subsystem and verify the current track fades/stops; set false and verify automatic state music resumes.
19. Return to the configured Frontend map and verify Frontend/Main Menu music is restored.
20. Package host/client and verify all three soft-referenced music assets are cooked and transitions behave the same on two machines.
21. Run the v0.10.4 footstep section plus WORLD chat, nameplate, Care, Scan/Materialization and combat regressions.


## F0. v0.10.4 automatic replicated player-footstep acceptance

1. Open **Project Settings → Game → Digimon MMO Framework → Player Avatar → Footsteps** and assign a spatial Sound Cue to **Player Footstep Sound (Sound Cue Recommended)**. Keep **Enable Player Footsteps** enabled.
2. Compile in UE5.8.1 and launch listen host + remote client with two player avatars. Confirm there are no footstep-related UHT/C++ warnings or errors.
3. Walk the host avatar. The host must hear one correctly paced local footstep stream; the remote client must hear the host footsteps spatially with no doubled events.
4. Walk the remote-client avatar. That client must hear immediate local footsteps, while the host hears the replicated remote footsteps. Confirm the owning client does **not** hear a second multicast echo.
5. Sprint and crouch. Verify cadence naturally changes using the configured sprint/crouch stride distances rather than remaining fixed-time.
6. Stop moving and stand still. Footsteps must stop immediately after cadence state resets. Jump/fall and verify no airborne footsteps are generated; resume on grounded movement.
7. Test diagonal movement, controller/custom Enhanced Input movement (if used) and player-skin swaps. Footsteps must continue because cadence reads actual CharacterMovement velocity rather than framework WASD state or animation notifies.
8. Disable **Enable Player Footsteps** and restart PIE. Neither host nor remote client should generate player footstep audio. Re-enable it afterward.
9. Confirm owned and Wild Digimon do not receive the player footstep Sound Cue from this system.
10. Re-run WORLD chat, nameplate, Care, Scan/Materialization, combat and Admin host/join regression sections.


## A0. v0.10.3 configurable Admin-host password acceptance

1. Open **Project Settings → Game → Digimon MMO Framework → Networking → Admin Hosting** and confirm **Set Admin Hosting Password** is editable without opening C++.
2. Enter a new 4-128 character password. Confirm the setter is masked while typing and clears after the setting is applied.
3. Restart the editor, login, open **Admin**, enter the previous password and confirm unlock fails.
4. Enter the new password and confirm Admin unlock succeeds and exposes **Host & Play**.
5. Confirm no plaintext Admin password is present in the framework's project config; only `AdminHostingPasswordDigest` is persisted.
6. Confirm a malformed/empty manually damaged digest fails closed with configuration guidance rather than unlocking Admin. Restore the correct Project Settings password afterward.
7. Run Host & Play and the second-client Join Game test below to confirm this local gate change does not alter network authority.

## E0. v0.10.2 configurable server-endpoint acceptance

1. Open **Project Settings → Game → Digimon MMO Framework → Networking → Server Endpoint** and confirm **Server Public Address / Hostname** and **Game Port** are editable without opening C++.
2. For same-machine PIE/testing, set the address to `127.0.0.1` and keep the port aligned with the active Unreal listen-server port/configuration.
3. Login as the admin account, unlock Admin and press **Host & Play**. Confirm hosting succeeds and the local status reports the configured player endpoint.
4. On the second client, login and press **Join Game**. Confirm its travel target uses the configured address/port and the existing account authentication/possession flow succeeds.
5. Change the address to the real LAN/public IPv4 address or DNS hostname used by the packaged host, rebuild/redeploy configuration as appropriate, and repeat on two machines.
6. Set the address blank and confirm both Host & Play preflight and Join Game fail cleanly with a Project Settings guidance message instead of attempting malformed travel.
7. Enter an invalid value such as `http://127.0.0.1` or `127.0.0.1?listen`; confirm it is rejected before travel.
8. Restore the production endpoint and run the WORLD chat, world-nameplate, Care, Scan/Materialization and combat regression sections below.

## W0. v0.10.1 polished world-chat multiplayer + HUD-layout acceptance

0. On both listen host and remote client, verify the lower-left WORLD chat panel sits fully above/clear of the centered partner ability quickbar. Resize each PIE window and confirm neither persistent HUD panel overlaps.

1. Compile against UE5.8.1 with no chat-related UHT/C++ errors or warnings promoted to errors.
2. Launch listen host + remote client with two authenticated accounts. Confirm both show the compact lower-left WORLD chat panel.
3. Host presses Enter, types a message and presses Enter again. Both peers must receive exactly one line carrying the host's public username and text.
4. Repeat from the remote client; both peers must receive exactly one line carrying the client's public username and text.
5. While the input field owns focus, press WASD/mouse-look/1-4/I/F6 and verify movement, look, abilities and modal menu toggles do not execute from typed/gameplay keys.
6. Press Escape during an unsent draft; verify no message is broadcast and normal gameplay input resumes.
7. Send two messages faster than the configured minimum interval. The second must be rejected server-side and only the sender sees the local SYSTEM feedback.
8. Exceed the sliding burst limit. Excess texts must never appear on other peers.
9. Send text containing newlines/tabs and text beyond the configured maximum. Verify one sanitized/clamped line is broadcast.
10. Connect a late third client after several accepted messages. Verify it receives at most `WorldChatServerHistoryLimit` recent session entries once, in order.
11. Set `WorldChatServerHistoryLimit=0`; verify late joiners do not receive prior chat while new broadcasts still work.
12. Disable the global **Enable World Chat** setting and restart. Verify no native chat widget/input route is active and the server will not accept chat.
13. Trigger Care feeding while chat is visible. Verify active chat input closes, the chat panel hides during eating, then returns with local history intact.
14. Repeat existing world-nameplate, Care, Scan/Materialization, combat and possession regressions to confirm no framework feature was removed or rerouted.

## C0. v0.9.1 compile-fix acceptance

1. Replace the previous v0.9.0 plugin with v0.9.1 and perform a UE5.8.1 Editor Development build.
2. Verify `DMFPlayerAvatarCharacter.cpp` and `DMFDigimonCharacter.cpp` no longer report `C2445` at the nameplate widget-class fallback.
3. Verify `DMFDigimonCarePropActor.cpp` no longer emits the v0.9.0 direct-access deprecation warnings for `NetUpdateFrequency` / `MinNetUpdateFrequency`.
4. Continue into the full world-nameplate and earlier regression suites below.

## N0. v0.9.0 world-nameplate multiplayer acceptance

1. Launch host + remote client PIE and authenticate with two different usernames.
2. Host must see Client username above the remote avatar; Client must see Host username above the remote avatar.
3. Each locally controlled avatar must hide its own plate by default; enable `Show Local Player Nameplate` and verify the optional local plate.
4. Owned Digimon and Wild Digimon must automatically display a compact name, level, stage, attribute and HP.
5. Damage a Digimon and verify host/client health-bar and numeric HP update from replicated combat vitals.
6. Verify owned Digimon with a persisted nickname display that nickname; empty nickname falls back to species DisplayName.
7. Verify Player and Digimon max draw distances independently cull the corresponding plates.
8. Verify the master and per-category global switches disable the expected layers without affecting actors/combat.
9. Verify a dedicated-server target performs no widget rendering while clients still render nameplates from replicated state.
10. Run the v0.8.1 Care acceptance and earlier combat/Scan/possession regression sections after nameplate validation.

## A0. v0.8.1 Care / CustomDepth / feeding / waste multiplayer acceptance

1. Configure one species with Care enabled, Hunger below 100, Feeding Montage, valid text-entered hand socket, DigiMeat mesh/relative scale, feeding voice, Poo mesh/world scale, fart sound, and temporary 10–20 second waste delay.
2. Run two-player PIE: listen host + remote client, with a summoned partner for each separate account.
3. Host opens `I -> CARE`; verify the panel shows only the host account's active partner and persistent care values.
4. Host presses **FEED DIGIMEAT UNTIL FULL**. Verify Digimon Menu and combat quickbar disappear **before** the first Montage and gameplay view/input return.
5. Verify both peers see the replicated DigiMeat attached to the configured hand socket at the species-specific scale **and affected by the project's CustomDepth cel shader**.
6. Verify exactly two complete eating Montage plays occur per serving by default, in sequence; voice plays from the server-selected species sound.
7. Verify Hunger changes only after the pair completes; servings repeat until 100%; no client can attack/change target/recall/swap/toggle auto-battle during the sequence.
8. Verify menu automatically reappears directly on CARE with refreshed 100% Hunger when feeding completes.
9. Repeat steps 3–8 from the remote client and confirm only that client's private care state changes while the host still sees shared 3D presentation.
10. Wait for waste. Verify both peers see the correct Digimon produce a fart cue and a scalable poo actor appears on traced ground beneath its standing location **and is affected by the project's CustomDepth cel shader**.
11. Walk through/stand in the poo; verify it has no collision/overlap blocking and does not affect navigation.
12. Verify the server lifespan removes the poo for both peers.
12a. If using a non-zero stencil convention, set `CustomDepthStencilValue` on a Blueprint child of `DMFDigimonCarePropActor`, repeat DigiMeat + poo presentation, and verify both meshes write the expected stencil locally on host and client.
13. Feed again, log out before waste is due, reconnect after due time and summon; verify overdue persistent waste resolves after the partner exists in-world.
14. Reconnect both accounts and verify Hunger/next-waste/care values remain account-separated.
15. Restore production waste delay/lifetime and run the existing Scan/Materialization + combat regression tests below.



## A1. v0.6.4 repeat-safe ability regression

1. Use a partner with at least 20 SP and a slot-1 ability costing 5 SP.
2. Target a durable wild Digimon with `E`.
3. Press `1`; confirm the attack executes once and SP decreases by exactly 5.
4. During the first attack/recovery/cooldown, press `1` exactly once more. Do **not** press another ability. Confirm slot 1 automatically executes again when legal.
5. Repeat slot 1 after each use and confirm it remains reusable until Current SP is below 5.
6. Confirm pressing slot 2 while slot 1 is buffered replaces the pending command (latest input wins) and does not duplicate SP deduction.
7. Confirm a 0-SP ability remains repeatable.
8. Move the target out of range and press slot 1; confirm chase -> face -> attack still uses capsule-aware reach.
9. Repeat on the remote client. The server and both peers must agree on SP, cooldown, montage, target and damage.
10. Restore SP with the healer and confirm the paid slot becomes usable again immediately after normal cooldown/recovery gates.

## A. Editor smoke test

1. Enable the plugin and restart the editor.
2. Verify **Project Settings → Digimon MMO Framework** appears.
3. Merge the supplied Asset Manager snippet into the project `DefaultGame.ini`, then restart the editor and verify `DMFDigimonSpecies`, `DMFStarterRoster`, `DMFDigimonAbility` and `DMFPlayerSkin` appear under **Game → Asset Manager → Primary Asset Types to Scan**.
4. Assign the frontend map, open-world map and starter roster.
5. Create at least two `DMFPlayerSkinData` assets and verify the native skin selector discovers both automatically.
6. Create/assign a Blueprint child of `DMFPlayerAvatarCharacter` as the MMO Default Pawn Class, or use the native class directly.
7. Verify every starter species has a `WorldActorClass` deriving from `ADMFDigimonCharacter`.
8. Open the frontend map and run PIE.
9. Confirm the native login UI appears automatically.

## A2. Native interaction / no-cast targeting smoke test

1. Open the project Blueprint derived from `DMFPlayerAvatarCharacter`.
2. Verify Class Defaults exposes **Digimon MMO -> Interaction** fields including native input, distance, sweep radius, trace channel, debug trace and attack-on-interact.
3. Verify inherited Blueprint nodes include `Interact`, `Interact With Actor`, `Interact With Digimon`, `Interact With Digimon And Attack`, `Interact With Healer`, `Clear Digimon Target`, `Command Digimon Ability Slot`, `Find Interaction Target`, `Get Current Digimon Target`, and `Get Interaction Prompt For Actor`.
4. Set `Enable Native Interaction Input=true`, `Attack On Digimon Interact=false`, distance `1200`, sweep radius `30`, channel `Visibility`. In Project Settings confirm `Enable Default Click Target Input=false` and `Enable Default Ability Slot Input=true`.
5. Start through MainMenu -> Login -> Host & Play with a summoned owned partner and a hostile wild Digimon.
6. Look at the wild Digimon and press `E`. Confirm the target changes while the partner does not auto-attack.
7. Press `1` or call `Command Digimon Ability Slot(0)`. Confirm the server executes/queues the first ability against the selected target.
8. Confirm looking at the owned partner and pressing `E` does not incorrectly target it when the active-partner ignore option is enabled.
9. Enable interaction debug trace temporarily and confirm the trace/sphere follows the player camera and reaches the configured distance. Disable debug after verification.
10. Place a `DMFHealerActor` Blueprint without adding custom collision. Confirm its native `InteractionCollision` sphere is present, `Interaction Collision Radius=100` (or your chosen value), its trace channel matches the player, and pressing `E` while looking at it routes the heal request.

## B. Admin listen-host test

1. In Project Settings → Digimon MMO Framework → Networking → Admin Hosting, set a new 4-128 character **Admin Hosting Password**. Confirm the setter field clears after applying the change.
2. Enter an unused username/password and press **Login**.
3. Open **Admin**, enter an incorrect Admin password and confirm the host controls remain locked.
4. Enter the newly configured Admin password and unlock.
5. Press **Host & Play**.
6. Confirm the open-world map is running as `NM_ListenServer`, never `NM_Standalone`.
7. For the new host account, confirm starter selection appears.
8. Select a starter and confirm it spawns as a 3D replicated partner.

## C. Two-client replication test

1. Start the admin listen host.
2. Start a second packaged client or second machine.
3. Log in with a different username/password and choose **Join Game**.
4. Confirm the second account is accepted/created on the host.
5. Confirm only that client sees its private starter/inventory UI.
6. Select a different starter.
7. Confirm both machines see both 3D partner actors.
8. Confirm each client only receives its own private Digimon inventory data.
9. On the remote client, use player `Interact` to select a wild Digimon. Confirm target state/combat outcome agree on host and client and no client-only damage occurs.
10. Use player `Interact` on a healer from the remote client. Confirm the host validates distance/reuse and the restored HP/SP replicates back to the owning client.

## D. Persistence test

1. Record each account's chosen starter and unique instance identity via Blueprint/debug display if desired.
2. Disconnect both clients cleanly.
3. Close the host.
4. Restart the packaged host and reconnect using the same credentials.
5. Confirm starter selection does **not** appear again.
6. Confirm the same species/instance data reloads and the active partner is respawned.
7. Confirm a wrong password for the existing username is rejected.

## E. Abuse / validation test

1. Attempt to invoke starter selection twice; the second request must not grant another starter.
2. Attempt to request a species not present/enabled in the starter roster; it must be rejected.
3. Fill the active Digimon inventory to its configured capacity and confirm starter/materialization-style grants cannot exceed capacity.
4. Attempt to load the MMO gameplay map in standalone mode; confirm it returns to the frontend rather than allowing gameplay.
5. Disconnect the target host or use an invalid network environment and confirm a network/travel failure message reaches the frontend status UI.

## F. Packaged two-PC acceptance gate

The baseline should not be treated as networking-accepted until it passes a packaged Development/Shipping-style two-PC test with the actual DNS/port configuration, because PIE success alone does not validate NAT, firewall, DNS or packaged replication behavior.

## G. Cook/Asset Manager acceptance

1. Create the starter roster and species assets under `/Game/DigimonData`.
2. Package a clean build (not relying on editor-loaded assets).
3. Confirm the starter roster loads in the packaged client and all starter species can be previewed/selected.
4. Restart the host and verify a persisted partner species resolves and its configured `WorldActorClass` spawns without an Asset Manager warning.


## v0.2.0 combat acceptance

1. Compile the plugin against UE5.8 with no warnings promoted to errors.
2. Create at least two ability assets (Attack 1 and Attack 2), one partner species and one wild species.
3. Verify `DMFDigimonAbility` appears in Asset Manager and survives a packaged build.
4. Host with admin, join from a second client, select a starter and verify the partner spawns with the same ability list on host/client.
5. Place a wild Digimon on a different Combat Team ID.
6. Verify both partner and wild acquire/chase/auto-attack only on the server while movement/state replicates to clients.
7. Spam quick-slot RPC input and verify cooldown/SP/range validation prevents illegal extra damage.
8. Move the target out of range during ImpactDelay and verify the server rejects the impact.
9. Verify Attack1/Attack2 montage + Cascade/Niagara cues render on both machines without changing authoritative damage.
10. Defeat the wild Digimon and confirm defeated state, death presentation, EXP reward and money reward.
11. Disconnect/reconnect and verify partner HP/SP, EXP and money persisted.
12. Package Development/Shipping and repeat on two separate PCs over the configured host endpoint.


## v0.3.0 player avatar / skin acceptance

1. Create seven enabled `DMFPlayerSkinData` assets for Izzy, Joe, Matt, Mimi, Sora, Tai and TK and assign the appropriate existing skeletal meshes.
2. Confirm the selector shows all seven in `DisplayOrder` without editing a roster array.
3. New account: confirm Character Skin Selection appears before Starter Digimon selection and cannot be closed until a valid skin is accepted.
4. Confirm the selected mesh/AnimBP/mesh-relative transform is applied to the replicated third-person pawn.
5. Verify WASD, mouse look, jump, crouch and sprint; sprint must be accepted by the server and visible on a second client.
6. Host chooses Tai, client chooses Mimi; confirm both machines see the correct remote skins.
7. Client presses F6 and switches Mimi -> Matt. Confirm no pawn respawn/repossess occurs and the active Digimon partner remains owned/spawned.
8. Disconnect/reconnect and restart the host; confirm each account restores its selected skin.
9. Disable one skin Data Asset and confirm the server rejects a request for it.
10. Package and repeat the two-PC test, verifying `DMFPlayerSkin` assets are cooked/resolvable with no Asset Manager warnings.

## Frontend native UI bootstrap acceptance (0.3.2; framework-owned background layering v0.15.0)
1. Open the MainMenu/Frontend map and confirm its World Settings GameMode Override is `DMFFrontendGameMode`.
2. Leave `LoginWidgetClass` unset/default so the pure-native fallback path is exercised.
3. Create a test Widget Blueprint such as `WBP_MainMenuBackground` and assign it to **Frontend Background Widget Class** in Project Settings. Do **not** also create that widget from the Level Blueprint.
4. Temporarily set `Frontend UI Startup Delay Seconds = 1.0`, `Frontend Login/Menu Viewport Z Order = 1000` and `Show Native Frontend Fullscreen Backdrop = False`.
5. Press Play/Standalone. Confirm exactly one selected background appears first and is not tinted by a framework full-screen color.
6. After roughly one second, confirm the native login card appears visibly above the full-screen background, the mouse cursor is visible, and username/password fields accept input.
7. Confirm the Output Log reports both background initialization and `Frontend login/main-menu widget initialized`, with the background Z-order exactly 100 lower than the login/menu Z-order.
8. Confirm a fully opaque/hit-testable background still cannot visually cover or steal interaction from the higher login card.
9. Enable `Show Native Frontend Fullscreen Backdrop`, set opacity to `0.34`, restart and confirm the optional dim returns; disable it again for the normal project-background workflow.
10. Complete Login -> Admin/Join flow, then verify Player Skin Selection, Starter Selection and Combat Quick Bar render when their respective conditions are met.
11. Travel away from the frontend and confirm both background and login widgets are removed.
12. Repeat with a Blueprint subclass assigned to `LoginWidgetClass`: foreground Z-order/startup sequencing must still apply.
13. Restore the desired production delay (commonly `0.15`-`0.50`, or longer for an authored intro) and repeat in a packaged build.

## Custom Depth / cel-shading acceptance

1. Open a Blueprint derived from `ADMFPlayerAvatarCharacter`; verify the inherited Character mesh reports **Render CustomDepth Pass** enabled after construction.
2. Run the skin selector and switch between at least two `DMFPlayerSkinData` assets; verify the applied mesh continues rendering into CustomDepth after every swap.
3. Place/spawn an `ADMFWildDigimonCharacter` Blueprint and verify its skeletal mesh renders into CustomDepth on host and client.
4. Verify a player-owned partner Digimon renders into CustomDepth after starter grant/reconnect.
5. If a Blueprint adds a secondary Skeletal/Static Mesh component, verify it receives CustomDepth at construction/BeginPlay. For a component created dynamically after BeginPlay, call `RefreshFrameworkCustomDepth()` and verify it is included.
6. With the project's Custom Depth-Stencil Pass enabled, verify the post-process cel-shading material affects all player skins and Digimon on both host and remote client.



## Wild proximity / rarity spawner acceptance (0.4.0)

1. Create a Blueprint child of `DMFWildDigimonSpawner` and place it inside a NavMesh-covered open-world area.
2. Set min/max population to 3/5 and add at least one Common and one Rare entry using valid `BP_Wild_*` classes and species assets.
3. Run listen host plus remote client. With every player outside Activation Radius, verify zero managed wild exist.
4. Move one player into Activation Radius. Confirm only the server chooses a target count and actors appear staggered, not all in one frame.
5. Verify both machines see the same species, level, replicated rarity and world transform.
6. Confirm every spawn rises through the ground smoothly on host and client, retains Custom Depth/cel shading, cannot be targeted during emergence and gains collision/combat only after emergence.
7. Wait idle and verify server AI sends random reachable roam moves inside Roam Radius around each individual SpawnHomeLocation.
8. Aggro one wild and move away; verify it cannot continue combat beyond Leash Radius and returns toward its home.
9. Defeat one managed wild. Confirm alive count drops immediately, death presentation remains for Defeated Despawn Delay, and replacement does not become eligible before its randomized respawn delay.
10. Set a Rare/Legendary entry Max Alive From Entry to 1 and verify the spawner never maintains two live copies of that entry.
11. Increase target population above the sum of finite entry caps and verify target population is clamped instead of retrying impossible spawns forever.
12. Move all players beyond Deactivation Radius. During the grace period the population remains; after it expires, remaining non-defeated wild sink and are destroyed with no replacement scheduling.
13. Re-enter Activation Radius and verify a fresh target population plus new rarity/level rolls.
14. Repeat in a packaged two-PC build.

## v0.4.1 wild-spawn placement regression

- Configure one `BP_Wild_<Species>` entry with a visibly non-default capsule size.
- Set `Minimum Spawn Count = Maximum Spawn Count = 1` and `Spawn Ground Offset = 2`.
- Enter Activation Radius and verify the actor spawns with the capsule bottom on the traced/NavMesh surface rather than with the actor origin on the surface.
- Confirm the server log reports spawner activation and a successful spawn line.
- Temporarily disable NavMesh coverage while `Require Navigable Spawn = true` and verify a visible placement warning is emitted rather than silent failure.
- Restore NavMesh and confirm spawning recovers without changing the Wild Blueprint.



## v0.14.5 rarity-weight normalization regression

1. Configure at least two eligible rarity tiers in one `DMFWildDigimonSpawner` and temporarily use easy-to-observe rarity weights such as `Common = 1.0`, `Uncommon = 0.5`, with all other tiers `0.0`.
2. Put a small number of entries in one tier and many entries in the other. Confirm adding entries to a tier changes species variety but does not multiply that tier's aggregate chance; with the example weights the long-run tier distribution should trend near 66.7% / 33.3%, not scale with entry count.
3. Inside one rarity tier, configure two entries with `Selection Weight Multiplier = 1.0` and `0.5`. Over repeated authoritative spawns, confirm the `1.0` entry trends approximately twice as often as the `0.5` entry when both remain eligible.
4. Set one entry multiplier to `0.0`; confirm it is never selected. Restore it and set `Max Alive From Entry = 1`; while one copy is alive, confirm the capped entry is removed from the within-tier roll and other eligible entries continue spawning normally.
5. Run listen host plus remote client and confirm both machines see the same resulting species and replicated `SpawnRarity`; the client must not perform an independent rarity/species roll.
6. Repeat the user's production Rookie/In-Training table and verify lower-weight Rookie tiers no longer dominate merely because more Rookie species are authored.

## v0.5.0 manual partner / balance acceptance

1. In Project Settings verify `Player Partner Auto Battle` defaults to false.
2. Spawn a healthy owned partner and at least one hostile wild Digimon.
3. Walk near the wild encounter without pressing target/ability input. Owned partner must continue following the player but must not autonomously acquire or attack.
4. Using the v0.5.0 controller target call (or enable the legacy Left-Mouse target binding), select the wild Digimon. Target state may change, but no attack should execute automatically.
5. Press quick slot 1. Server must execute immediately if in range or chase/queue and execute after revalidation.
6. Call `CommandPartnerTargetAndAttack(Target, 0)` from Blueprint interaction logic and verify the same authoritative behavior.
7. Verify an equal-level normal wild encounter is materially less punishing under the default player role tuning (1.50 outgoing, 0.50 incoming) while the persistent Species/Instance stat values remain unchanged.
8. Set a Wild Blueprint outgoing/incoming multiplier away from 1.0 and verify only that wild class's combat math changes.

## v0.5.0 Digimon roster UI acceptance

1. Complete onboarding or load an existing account with at least one Digimon.
2. Press `I`; native Digimon roster must appear and gameplay input must be modal-locked.
3. Verify entries show level, HP/SP, defeated state and active/summoned state.
4. Recall the active partner. World actor must be destroyed but `ActivePartnerInstanceId` must remain valid.
5. Select the same Digimon and use Set Active / Summon. Server must validate ownership and spawn the correct species actor.
6. Attempt to summon a Digimon with `CurrentHP <= 0`; server must reject it with explicit owner feedback.
7. Test Blueprint `Open/Close/Toggle/Refresh Digimon Inventory UI` calls with the default I binding disabled.
8. Reconnect a returning account and verify automatic active-partner spawn still runs; if the actor is missing/recalled the roster can summon it explicitly.

## v0.5.0 healer acceptance

1. Derive `BP_DigimonHealer` from `DMFHealerActor` and place it in the gameplay map.
2. Damage the active partner and at least one stored active-inventory Digimon; optionally prepare a defeated Digimon and a damaged bank record.
3. From inside Interaction Radius, call `RequestHeal` with the local DMFMMOPlayerController.
4. Server must restore configured HP/SP, revive defeated Digimon when enabled, update optional bank storage and persist immediately.
5. If the selected active partner is missing and auto-resummon is enabled, the healer should spawn it after restoring HP.
6. From outside Interaction Radius, request must fail and no HP/SP/account mutation may occur.
7. Spam requests faster than Reuse Delay; server must reject excess uses.
8. Disable the healer on the server; `bEnabled` must replicate and further requests must fail.
9. Verify `BP_OnHealPresentation` runs as cosmetic multicast and that gameplay truth remains server-owned.
10. Disconnect/reconnect and verify healed HP/SP values persisted.
11. Repeat with a remote client against a listen host.


## v0.5.2 native player interaction / no-cast targeting acceptance

1. Compile the plugin cleanly in UE5.8.1 with warnings-as-errors enabled.
2. Open the Blueprint derived from `DMFPlayerAvatarCharacter`; verify inherited nodes include `Interact`, `Interact With Actor`, `Interact With Digimon`, `Interact With Digimon And Attack`, `Interact With Healer`, `Clear Digimon Target` and `Command Digimon Ability Slot` without any project-side cast requirement.
3. In Class Defaults leave `Enable Native Interaction Input=true`, `Attack On Digimon Interact=false`, `Interaction Distance=1200`, `Interaction Sweep Radius=30`, and trace channel `Visibility`.
4. Load through MainMenu -> Login -> Host & Play. Confirm the owned partner follows but does not auto-acquire or auto-attack nearby wild Digimon.
5. Look at a hostile Wild Digimon and press `E`. Confirm the command target changes after the server path accepts it and no attack begins.
6. Press `1`; confirm the active partner executes/queues slot 1 against the selected target, including normal chase/range/leash/cooldown/SP validation.
7. Look at another hostile Digimon and press `E`; confirm target selection changes cleanly.
8. Enable `Attack On Digimon Interact` temporarily and verify `E` performs target+attack using the configured zero-based slot while combat truth remains server-authoritative.
9. Set `Enable Native Interaction Input=false`; wire an Enhanced Input action directly to the inherited `Interact` node and verify identical behavior.
10. Call `Interact With Digimon` and `Interact With Digimon And Attack` from a generic `Actor` reference and verify no Blueprint cast is required.
11. Place a Blueprint derived from `DMFHealerActor` with no custom collision. Confirm its native `InteractionCollision` sphere is hit by the player `Visibility` interaction trace.
12. Press `E` inside healer `Interaction Radius`; confirm healing succeeds and persists. Request from outside the authoritative radius; confirm the server rejects it even if a local trace/actor reference is supplied.
13. Enable `Draw Debug Interaction Trace` temporarily and confirm trace/sweep starts from the follow camera, ignores the player and (when enabled) ignores the active partner.
14. Change the interaction trace channel on both player and healer; verify detection follows the configured channel.
15. Repeat target-only, target+attack and healer interactions as a remote client connected to a listen host. Confirm host/client agree on replicated command target, movement/combat, HP/SP and healer results.
16. Regression: press `I` and confirm Digimon roster UI still opens; wild spawners still proximity-spawn/roam/emerge; player/Digimon Custom Depth remains enabled; login/skin/starter persistence remains intact.

## Regression gates retained from v0.4.1

- Wild spawner capsule-bottom placement remains correct for differently sized Wild Blueprint capsules.
- Rarity, min/max population, per-entry caps, free roaming, leash, emergence and ground-despawn remain server-authoritative.
- Player and Digimon Custom Depth remains forced on after spawn/skin changes.
- Login, account load, player-skin onboarding and starter onboarding remain functional.

## v0.5.3 defeated-partner regression
- Player-owned Digimon at 0 HP plays the species Death Montage and remains frozen in the configured defeated pose for at least 10 seconds.
- The defeated partner is not destroyed automatically; Recall removes it.
- Healer revival clears the held pose and restores normal animation/movement.
- Host and client see equivalent defeated state.
- Wild spawner corpse lifetime/despawn remains unchanged.

- Defeat regression: defeat both a player partner and a spawner-managed wild Digimon; each must play its species Death Montage and remain frozen on the death pose (never Idle) until respectively recall/revive or spawner corpse destruction.

- Passive-retaliation regression: set Wild BP `Proactive Auto Battle=false`, `Retaliate When Attacked=true`, spawner `Allow Proactive Auto Battle=false`, `Allow Retaliation When Attacked=true`. The wild Digimon must roam peacefully and must not acquire the player partner merely from proximity.
- Target-only regression: target/interact with the wild Digimon without damaging it; it must remain peaceful.
- Retaliation regression: land one authoritative damaging hit from the player partner; the wild Digimon must target that attacking partner and chase/attack back even though proactive auto battle is disabled.
- Leash regression: move the aggressor beyond the wild home leash; the wild Digimon must drop retaliation and return home/idle rather than chase forever.
- No-retaliation regression: set `Retaliate When Attacked=false`; the same damaging hit must not start combat.
- Aggressive regression: enable `Proactive Auto Battle`; the wild Digimon may acquire a nearby hostile without first taking damage.
- Death regression: while retaliating, defeat both wild and player Digimon cases and confirm the Death Montage remains frozen until spawner removal or recall/revive respectively.

## v0.6.0 polished native UI acceptance

- Frontend: native login appears centered/scaled with styled inputs/status; successful local login switches to the Play view; Admin expands inside its own card; Host & Play is visible only after admin unlock; Logout returns to credential view; Quit exits PIE/game appropriately.
- Starter: enabled roster entries render portrait cards; selection highlight changes; selected portrait, Stage/Attribute/Level/stats and blurb populate; confirm still grants exactly one server-authoritative starter.
- Player skin: enabled Primary Assets render sorted portrait cards; selected profile updates; apply persists through the existing server call; mandatory onboarding cannot be bypassed through Close.
- Digimon collection: `I` opens a centered window; configured inventory capacity renders as slot cells; occupied cells use species Portrait and show level/state badge; empty cells remain visibly empty; selecting a Digimon updates the full detail panel; KO disables summon; summon/recall still round-trip through server state.
- Combat bar: bottom-center bar displays partner vitals, target, four slots, SP/cooldown and optional ability icons; slot clicks/1-4 still issue server commands rather than local damage.
- Compatibility: a Blueprint child using legacy optional `DigimonChoicesBox`, `ChoicesBox` or `PlayerSkinChoicesBox` continues to receive functional list population if it does not adopt the new grid bindings.
- Regression: v0.5.5 death-pose, passive retaliation and v0.4.x spawner source remain unchanged in this release.


## v0.6.1 late-join remote client avatar possession acceptance

1. Compile cleanly in UE5.8.1 after replacing plugin/Binaries/Intermediate.
2. Start a listen host through the normal frontend Admin -> Host & Play path. Confirm host pawn/skin/partner behavior is unchanged.
3. On a second machine/client instance, login and Join Game.
4. Fresh account: choose a character skin. The client must possess the configured `DMFPlayerAvatarCharacter` Blueprint child immediately after selection; flying `DefaultPawn`/spectator control is a failure.
5. Host must see the remote client's selected skin on the remote avatar.
6. Client completes starter selection. Partner must spawn relative to the recovered client avatar.
7. Client movement/jump/sprint must replicate to host and other clients.
8. Client opens inventory, recalls/summons partner, targets a wild Digimon and issues manual attacks. Confirm these systems operate from the recovered avatar.
9. Disconnect and reconnect the same account. Saved skin and active partner must restore with correct avatar possession without reopening character selection.
10. Deliberate misconfiguration test (optional): temporarily set MMO GameMode DefaultPawnClass to an incompatible pawn. Server should log the configuration error and recover using native `DMFPlayerAvatarCharacter` instead of leaving a remote client in DefaultPawn. Restore the correct Blueprint class afterward.


## v0.6.2 combat target-facing acceptance
1. Set partner and wild test Blueprints to Enable Combat Facing=true, Require Facing Before Attack=true, Turn Rate=720, Tolerance=8.
2. Approach a passive wild Digimon from behind/side and command partner slot 1. Confirm partner turns first, then attacks.
3. Confirm the damaged wild Digimon retaliates and turns to face the partner before its own attack.
4. Move around the target during attack/recovery and verify facing tracks without snapping back to idle orientation.
5. Force a chase beyond immediate range; verify movement orientation remains natural while chasing, then target-facing takes over only once in range.
6. Break the wild leash; verify combat-facing stops and roaming/return movement orientation restores.
7. Repeat host + remote client and confirm both machines observe matching facing/attack direction.
8. Verify no SP/cooldown is consumed while an attack is merely waiting for facing tolerance.


## v0.6.4 ability execution / melee reach acceptance

1. Partner current SP is greater than a positive-cost ability (for example 60 SP vs 5 SP).
2. Target a hostile wild Digimon and issue the positive-cost melee slot while out of range.
3. Partner must chase until capsule-aware range is valid, face the target, execute once, apply impact, and deduct exactly the configured SP once.
4. Repeat with a 0-SP ranged ability; both slots must work through the same command path.
5. Verify short-range attacks work between Digimon Blueprints with substantially different capsule radii.
6. Verify a target that escapes beyond legal edge-to-edge range before impact is not damaged.
7. Verify host and remote client see the same facing, attack cue, SP change, damage, and cooldown.
8. Verify wild retaliation uses the same range rule and remains passive until attacked when proactive auto battle is disabled.

## v0.7.0 Scan / Materialization regression
1. Configure one species at +20%, cap 100%, requirement 100%, with a valid partner WorldActorClass.
2. Defeat five framework Wild actors with the player's active partner and verify 20/40/60/80/100 owner-only progression and the READY toast.
3. Verify another connected player receives no scan progress from those victories.
4. Open `I -> SCAN & MATERIALIZE`; verify portrait, Stage/Attribute, progress, owned count and capacity.
5. Materialize at 100%; verify exactly one new GUID enters Collection, Scan becomes 0%, the species remains in Scan Database, and the new Digimon is not auto-summoned.
6. Summon the materialized Digimon through Collection and confirm existing combat/facing/manual ability behavior.
7. Reconnect both host and remote client; verify scan progress and materialized Collection ownership persist separately per account.
8. Fill Collection to capacity and verify materialization is rejected without consuming Scan Data.
9. Assign a Wild class to Species WorldActorClass and verify server rejection without consuming Scan Data.
10. Regression: target-facing, passive retaliation, death pose, late-join possession, polished menus, starter selection and healer still function.

## v0.14 DigiDex acceptance
1. Open the shared Digimon Menu and verify native visual order **PARTY → BANK / BOXES → SCAN & MATERIALIZE → DIGIDEX → DIGIVOLUTION → CARE**.
2. Verify every registered `DMFDigimonSpecies` Primary Asset appears in DigiDex with fixed, non-distorted portrait cards.
3. Verify search matches Display Name, Species Key, Stage, Attribute and Element; verify Stage and Attribute filter cycling.
4. Verify selected entry shows portrait, Stage/Attribute/Element, Base Stats, rewards, Scan/Materialization values, starting moves, description and previous/next authored Digivolution forms.
5. Verify OWNED/SCANNED/UNSCANNED status updates from the local account's existing Party/Bank/Scan state.
6. Confirm there are no summon, recall, storage, materialize, care or digivolve actions on DigiDex.
7. Host + remote client: implemented species list is identical, while private ownership/Scan badges reflect only each client's own account.
8. Disable `UI|DigiDex -> Enable DigiDex`; verify the native tab hides and no account/species data changes.
## v0.14.1 replicated projectile / VFX lifecycle acceptance
1. Create or duplicate a `DMFDigimonAbilityData`, set `Execution Mode = Replicated Projectile`, assign a valid attack/Projectile Spawn socket and a visible fireball Niagara system.
2. Host PIE: use the attack at a stationary hostile target. Verify exactly one projectile leaves the configured socket, faces/travels toward the target, damage occurs on visible arrival, and the projectile disappears.
3. Remote client PIE: issue the same attack. Verify host and remote client observe the same projectile flight and target arrival while SP/cooldown/damage remain authoritative.
4. Enable homing and move the target during flight. Verify authoritative flight turns toward the moving target without snapping the caster/socket VFX.
5. Disable homing and repeat. Verify the projectile retains launch direction and expires cleanly when it misses.
6. Change `Projectile Visual Rotation Offset` and confirm visual orientation changes without changing travel direction.
10. Assign a looping projectile Niagara/Cascade system, set a short `Projectile Max Lifetime Seconds`, deliberately miss, and verify no projectile/VFX remains after the hard lifetime.
8. Assign optional impact Niagara/Cascade/Sound and verify it plays once at arrival on host + remote client and cleans after `Projectile Impact VFX Lifetime Seconds`.
9. Keep another ability in Timed Impact mode, assign a deliberately looping Niagara/Cascade system, set `Presentation VFX Lifetime Seconds`, and verify the transient cue is forcibly removed.
10. Regression: repeat manual slots/auto battle, retaliation, combat facing, Party/Bank, DigiDex, Digivolution, Care, healer, world chat/nameplates and persistence tests; no pre-v0.14.1 gameplay authority path should change.


## T0 — v0.14.2 owner-only targeting visuals

### v0.14.3 visibility regression
- With a valid active-partner sprite, enemy-target sprite and Niagara arrow assigned, confirm all three can render on the owning listen host.
- Repeat on a remote client. The remote client must see its own markers even though the local camera view target is the possessed avatar rather than the PlayerController.
- Confirm another player does not see those local markers.
- During PIE, clear/reassign a ring or arrow asset in Project Settings and confirm the presentation recovers automatically without restarting the level.
- Disable then re-enable **Enable Combat Targeting Visuals** during PIE and confirm the already-local presentation actor hides/restores cleanly.

1. Assign blue partner ring PaperSprite, hostile target ring PaperSprite and Niagara arrow in Project Settings.
2. Run listen host + two clients and summon a different partner for each account.
3. Confirm each window shows the blue ring only under its own active partner.
4. Select different Wild Digimon on each client; each window must show only its own hostile ring + arrow.
5. Confirm the partner/enemy rings rotate continuously at different default speeds/directions.
6. Test small Fresh and large later-stage capsule sizes; verify auto-size remains clamped/readable.
7. Clear/defeat target and verify hostile ring/arrow deactivate. Recall/switch partner and verify blue ring follows owner state.
8. Unassign Niagara and assign Cascade fallback; repeat target selection. Then restore Niagara and verify Niagara is preferred.
9. Verify host/client target selection, abilities, v0.14.1 projectile homing/impact/cleanup and all combat damage remain server-authoritative and unchanged.
10. Package two clients and repeat privacy/cleanup checks.

## v0.14.6 attack VFX / enemy marker CustomDepth regression

1. In PIE, select a hostile Digimon and verify the overhead enemy Niagara or Cascade marker is visible and its runtime component reports **Render CustomDepth Pass = true**.
2. Execute a direct/non-projectile ability using Niagara, then Cascade fallback, and inspect the spawned component: CustomDepth must be enabled every spawn.
3. Execute a projectile ability and verify its moving Niagara/Cascade component has CustomDepth enabled on host and remote client presentation.
4. Verify projectile-impact Niagara/Cascade components also have CustomDepth enabled on every impact spawn.
5. Change/reassign the enemy target-arrow asset during PIE and confirm the refreshed marker still has CustomDepth enabled.
6. Regression-check projectile hit/damage, homing, cleanup, target privacy, v0.14.5 rarity weighting and v0.14.4 battle-music lifecycle.



## v0.14.7 wild / auto-battle full moveset regression

1. Create or use a wild species with at least four resolvable runtime abilities: `BasicAutoAttack` plus three `StartingAbilities`. Leave `bEligibleForAutoBattle=true` on all four and give the Digimon enough SP to use each repeatedly.
2. Set cooldowns low enough to observe repeated cycles, but give the moves visibly distinct montages/VFX/sounds so ability identity is obvious. Include at least one short-range/melee move and one longer-range/projectile move.
3. With `Proactive Auto Battle=false` and `Retaliate When Attacked=true`, attack the wild Digimon from a player partner. Confirm authority establishes retaliation and the wild executes **multiple different abilities**, not only Basic Auto Attack.
4. Observe a long enough fight to cover at least one complete currently-usable rotation. Confirm every auto-battle-eligible move executes before a recently used move becomes the preferred choice again, allowing for temporary cooldown/SP exclusion.
5. Confirm mixed ranges are stable: when a short-range ability is selected from farther away, the wild keeps chasing into that move's range and executes it rather than oscillating between ranged/melee acceptance radii each automation tick.
6. Put one ability on a visibly longer cooldown. Confirm other ready abilities continue executing; after the long cooldown expires, that older move naturally returns to selection.
7. Set one move's `bEligibleForAutoBattle=false`. Confirm it is never autonomously selected while the remaining enabled moves continue rotating.
8. Reduce SP so one costly move can no longer be paid. Confirm it leaves the autonomous candidate pool without blocking attacks that are still affordable.
9. Repeat with `Proactive Auto Battle=true` to verify nearest-hostile acquisition uses the same full-moveset execution path.
10. Optional owned-partner regression: explicitly enable Player Partner Auto Battle and confirm it also uses the complete eligible moveset; then disable it and confirm manual slot 1–4 commands remain unchanged and take priority.
11. Run listen host + remote client. Confirm ability selection/damage/cooldowns remain server-authored while the existing replicated/multicast presentation shows the same chosen attacks remotely.
12. Regression-check v0.14.6 CustomDepth attack VFX/marker enforcement, v0.14.5 rarity weighting, v0.14.4 persistent battle music, projectile homing/impact, combat facing, leash behavior, defeat/reward and Party/Bank persistence.

## v0.14.9 Attribute Point + menu regression

Test Party and Bank + buttons, exact one-point/one-stat mutation, zero-point disabled state, MaxHP/MaxSP missing-resource preservation, defeated HP remaining zero, active-partner replication without respawn/combat reset, persistence after reconnect, owner privacy in two-client PIE, and every Digimon Menu tab at 16:9/short-height/DPI scaling to confirm no child/action control renders below the modal border.

**Party detail scroll acceptance:** at a short viewport comparable to 1644x864, select one Party Digimon and confirm the right identity/portrait header remains stable while a single vertical scroll lane reaches Stats/EXP -> Attribute Point controls -> species description -> `SET ACTIVE / SUMMON` -> `RECALL ACTIVE PARTNER` -> `MOVE TO BANK`. Confirm mouse-wheel scrolling over the description continues the outer Party body rather than being trapped in a nested scroll box; click each reachable action and verify its existing server-authoritative behavior is unchanged.


### v0.16.0 outer sky solar visual regression
- With a sky material exposing conventional `Light direction` and `Sun height` parameters, accelerate the simulated clock and verify the visible sun disc follows the native Directional Light continuously in editor preview, listen host and remote client. Clouds/digital inner-layer UVs must not rotate as a side effect.

## v0.16.1 — 12-hour replicated world-clock HUD acceptance

1. Use the accepted v0.16.0 sky and set Simulated day length to 60 seconds for accelerated validation.
2. Run listen host + remote client and confirm both ability quickbars display the same `h:mm AM/PM` time.
3. Validate midnight (`12:00 AM`), noon (`12:00 PM`) and an afternoon value such as 18:30 (`6:30 PM`).
4. Confirm DAY/NIGHT label changes at the sky's authored phase boundaries and agrees with sky lighting and active wild population table.
5. Switch to Host-PC mode; confirm remote clients follow the host/server clock, not the remote machine's local clock.
6. Temporarily remove/disable the sky and confirm the HUD fails softly to `--:-- -- / SYNC` without log spam or gameplay failure, then restores automatically when a valid sky is available.
7. Disable `Show Combat Quick Bar World Clock Phase`, then `Show Combat Quick Bar World Clock`, and confirm the native layout collapses cleanly.
8. Regression-test ability clicks, cooldown presentation, partner HP/SP, target text, Party Quick Access, Home, world chat and Day/Night spawner swapping.


## v0.17.0 — replicated swimmable-water acceptance

1. Create `BP_DMFWater_Test` deriving from `DMFSwimmableWater`, assign a visible project water material, set Surface Size to at least 5000 x 5000 and Water Depth to at least 1000, then place it with the actor origin at the desired water surface.
2. In editor, change Surface Size and Water Depth and confirm the visible plane and `SwimmingBounds` remain aligned. Confirm the plane itself has no collision and the bounds overlap Pawn only.
3. Listen-host avatar walks into the surface. Confirm `Is Swimming In Water=true`, `Get Player Swim State=Surface`, ordinary footsteps stop and the skeletal mesh smoothly lays forward while the capsule remains upright.
4. Hold Forward while looking horizontally. Confirm camera-yaw surface swimming and stable Surface Ride Depth rather than free sinking.
5. Look down past the configured dive threshold and hold Forward. Confirm the player dives, replicated state becomes Underwater, and Forward now follows full camera pitch.
6. Underwater, look upward/downward while holding Forward and confirm true 3D camera-directed movement. Hold Space to ascend and C to descend. Hold Shift and confirm Sprint Swim Speed.
7. Observe the swimming player from a remote client. Confirm movement, facing, Surface/Underwater transitions and flattened fallback pose are coherent without a custom swim RPC.
8. Repeat entry/movement from the remote owning client while the listen host observes. Confirm responsive local entry and normal server correction with no permanent rubber-banding.
9. Exit the water at an edge/shore. Confirm gravity/floor acquisition, walking/sprint speeds, controller orientation, mesh-relative skin transform and automatic footsteps restore.
10. Disable `Use Native Swim Fallback Pose` on the avatar Blueprint. Confirm swimming movement/state remains functional and Blueprint swim events still fire, allowing a real AnimBP to own presentation.
11. Test two overlapping water actors with different `Water Priority`. Confirm the highest-priority overlapping water controls speed/surface parameters and leaving it falls back to the remaining water rather than leaving swimming entirely.
12. On authority, call `Set Water Surface Size`, `Set Water Depth` and `Set Swimming Enabled`. Confirm client geometry/config updates and players leave cleanly when water is disabled.
13. Disconnect while inside water after player-location autosave, reconnect, and confirm the saved world position restores inside the volume and v0.17.2 world reconciliation re-establishes swimming without a SaveGame schema change.
14. Invoke Return Home while swimming. Confirm water state clears, ordinary movement/mesh presentation restores, the partner/Home workflow still succeeds and the Home checkpoint persists.
15. Regression: combat/ability quickbar, v0.16.1 world clock, Day/Night sky/populations, Party/Bank, Digivolution, Care and player-location persistence remain functional on host + remote client.


## v0.17.3 — replicated swim presentation / network smoothing acceptance

1. Start 2-player PIE as listen host + remote client with normal CharacterMovement network smoothing enabled. Put the **client** into Surface swimming while the host watches. Confirm the host sees the remote client's skeletal mesh flattened forward and the capsule/movement remain smooth.
2. Keep the remote client stationary at the surface after entering water. Confirm the host still transitions to the flattened pose without requiring another movement packet and without oscillation/shake.
3. Dive the client underwater and swim upward/downward. Confirm the host sees `Underwater` presentation and optional travel-pitch changes while ordinary replicated movement remains smooth.
4. Exit water and stand still. Confirm the host sees the mesh return cleanly to the authored skin transform with no residual rotation/location offset.
5. Reverse roles: host swims while the remote client watches. Confirm the remote simulated proxy shows the same Surface/Underwater fallback states.
6. Add a third client if available and confirm both non-owning observers see the same swimmer presentation without any observer affecting another viewport.
7. Repeat after changing Player Skin / mesh-relative transform. Confirm the swim pose composes from the authored skin base and returns to that exact base after exit.
8. Test an underwater save/reload from accepted v0.17.2. Confirm reconstructed swimming immediately drives the remote fallback pose as well as the owner's post process/fog.
9. Disable **Use Native Swim Fallback Pose**. Confirm no native mesh rotation is applied on owner or remote proxies while replicated swim-state Blueprint/AnimBP data remains valid.
10. Regression: no visible remote shake during walking, swimming, shore transitions or network corrections; all 47 RPCs, v6 account persistence, Day/Night, clock, combat, Party/Bank and water PP/fog remain unchanged.

## v0.17.2 — persisted water restore / teleport reconstruction acceptance

1. Enable player world-location persistence and autosave. Surface-swim until the saved actor origin is clearly inside `DMFSwimmableWater`, wait for autosave, disconnect, reconnect and confirm the avatar starts in `Surface` swim state without dropping toward the floor.
2. Dive well below `Underwater Enter Depth`, wait for autosave, disconnect and reconnect. Before giving movement input, confirm `Is Swimming In Water=true`, `Is Swimming Underwater=true`, CharacterMovement is in the framework swim path, and the horizontal fallback pose is active.
3. On the same underwater restore, put the third-person camera below the surface and confirm the v0.17.1 color grading + distance fog return automatically. Raise only the camera above water and confirm local presentation clears while gameplay can remain underwater.
4. Repeat the underwater restore on a remote client connected to a listen host. Confirm the host sees the remote avatar remain at the restored depth rather than falling, and the remote client alone receives its underwater PP/fog.
5. Repeat with two overlapping water actors and confirm the normal highest `Water Priority` / highest-surface tiebreak selects the same controlling water immediately after restore.
6. Save near the water surface within the overlap allowance and reconnect repeatedly. Confirm there is no one-frame fall/sink, no Surface/Underwater replication-order flicker that persists, and movement responds immediately.
7. Save on land and reconnect. Confirm reconciliation resolves no active water and normal walking/falling behavior is unchanged.
8. While swimming, invoke Return Home. Confirm stale water state, horizontal pose, post process and fog clear even if the teleport bypasses a visible EndOverlap transition. If Home is intentionally placed inside a DMF water volume, confirm it enters the correct swim state instead.
9. From an authority Blueprint teleport, move a player directly from land to underwater, then call `Rebuild Swimming State From World(true)`. Confirm swimming/post-process recover without manually calling `Register Swimmable Water Overlap`. Teleport back to land and call the same function; confirm state clears.
10. Regression: ordinary walk-in/walk-out overlap swimming, camera-directed dive/ascend/descend, v0.17.1 fog, v0.16.1 clock, Day/Night, Party/Bank, combat, persistence and packaged host/client behavior remain unchanged.

## v0.17.1 — underwater post-process / distance-fog acceptance

1. Compile/package in UE5.8 and confirm `BP_DMFWater_Test` exposes the complete `Underwater Post Process Settings` profile, including the `Distance Fog` subsection, with defaults and no Blueprint asset breakage.
2. Surface-swim while keeping the third-person camera above the water plane. Confirm swimming may be Surface/Underwater as appropriate but `Is Local Camera Underwater=false` and the viewport remains ungraded/unfogged.
3. Lower the camera through the surface. Confirm presentation engages only after `Camera Enter Depth`, blends smoothly, and `On Local Camera Underwater Changed(true)` fires once.
4. Hover around the waterline. Confirm the separate `Camera Exit Height` prevents rapid on/off flicker.
5. Dive from shallow to deeper than `Full Strength Depth`; confirm `Get Underwater Post Process Blend Weight` ramps from approximately `Shallow Water Blend Weight` to 1.0.
6. With no custom Post Process material assigned, confirm native Distance Fog causes distant terrain/shore geometry to fade into `Distance Fog Color`; nearby avatar geometry must remain readable. Raise/lower `Distance Fog Density` and confirm visibility range responds.
7. Set `Distance Fog Start Distance` higher and confirm a larger clear pocket around the camera; set `Distance Fog Max Opacity` lower and confirm far scenery remains partially visible.
8. Disable only `Enable Distance Fog`; confirm color grading remains active but long-range extinction disappears.
9. Verify default color tint, saturation, contrast, gamma, exposure, vignette and chromatic-aberration values affect only the local camera and restore cleanly on exit.
10. Assign a valid Material Domain=Post Process material. Confirm it blends with the same profile weight; clear it and confirm built-in grading + native distance fog remain functional.
11. Disable `Underwater Post Process Settings.bEnabled`; confirm swimming movement, replicated Surface/Underwater state and fallback pose remain unchanged with no local underwater presentation.
12. Run listen host + remote client. Put only the remote player's camera underwater and confirm the host viewport is not affected. Repeat in reverse. Confirm both clients use the same authored profile.
13. On authority, call `Set Underwater Post Process Settings`, `Set Underwater Post Process Enabled` and `Set Underwater Post Process Material`; confirm sparse profile updates reach clients and active local swimmers refresh without an RPC or reconnect.
14. Test overlapping waters with different priority/profiles. Confirm the selected active water also supplies both color grading and distance fog, transitioning cleanly when control changes.
15. Dedicated-server/static check: no render dependency is required for authority simulation; no new RPC, account SaveGame field, world-time field, combat state or movement mode is introduced.
16. Regression: v0.17.0 swimming/shore exit, v0.16.1 clock, Day/Night sky/populations, combat, Party/Bank, Care, DigiDex, Digivolution and Return Home still work host + client.
