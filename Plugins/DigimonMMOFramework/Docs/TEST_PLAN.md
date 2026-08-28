# UE5.8 Validation Plan — 0.13.1-alpha

Run these tests after the plugin compiles in the target UE5.8.1 project. v0.13.1 is a presentation-only hardening patch over the compiling v0.13.0 persistent server-authoritative Digivolution milestone; all gameplay/network authority contracts remain unchanged.


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

## Frontend native UI bootstrap acceptance (0.3.2)
1. Open the blank MainMenu map and confirm its World Settings GameMode Override is `DMFFrontendGameMode`.
2. Leave `LoginWidgetClass` unset/default so the pure-native fallback path is exercised.
3. Press Play/Standalone from MainMenu.
4. Confirm the native login UI is visible immediately over the blank map, the mouse cursor is visible, and username/password fields accept input.
5. Confirm the Output Log contains `Frontend login/main-menu widget initialized` and contains no frontend widget creation error.
6. Complete Login -> Admin/Join flow, then verify the native Player Skin Selection, Starter Selection and Combat Quick Bar each render when their respective conditions are met.
7. Repeat with a Blueprint subclass assigned to each widget-class setting to verify custom designer roots are not overwritten by the native fallback.
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
7. Assign a looping projectile Niagara/Cascade system, set a short `Projectile Max Lifetime Seconds`, deliberately miss, and verify no projectile/VFX remains after the hard lifetime.
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
