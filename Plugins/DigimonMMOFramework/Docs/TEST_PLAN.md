# UE5.8 Validation Plan — 0.10.1-alpha

Run these tests after the plugin compiles in the target UE5.8.1 project. v0.10.1 retains the polished server-authoritative WORLD chat and adds the HUD-safe native chat/quickbar layout on top of the user-accepted v0.9.1 nameplate baseline while retaining all Care/CustomDepth, Scan/Materialization, combat, possession, UI, wild spawning and persistence regression contracts.

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

1. Enter an unused username/password and press **Login**.
2. Open **Admin**, enter the configured admin passphrase, and unlock.
3. Press **Host & Play**.
4. Confirm the open-world map is running as `NM_ListenServer`, never `NM_Standalone`.
5. For the new host account, confirm starter selection appears.
6. Select a starter and confirm it spawns as a 3D replicated partner.

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
