# Digimon MMO Framework — UE5.8

**Version:** `0.13.1-alpha — Digivolution Owned-Roster UI Layout Fix`

A source-first Unreal Engine 5.8 runtime plugin foundation for a multiplayer-only, server-authoritative, Blueprint-first Digimon MMORPG.

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

The owned-Digimon progression layer is now a complete **Party + Bank/Box system**. The shared `I` Digimon Menu exposes `PARTY`, `BANK / BOXES`, `SCAN & MATERIALIZE` and `CARE`. Party is a six-Digimon active field roster by default, while the persistent Bank holds 200 Digimon by default and can be opened **anywhere in the gameplay world**—no physical terminal is required.

The Bank uses paged six-column Box storage with compact portrait/level cards, KO presentation, full selected-Digimon stats and a live six-slot Party destination strip. If Party has room, a Bank Digimon moves into the first free slot. If Party is full, select an occupied Party slot and the server performs an **atomic swap**, returning the outgoing Party Digimon to Bank. Deposits, swaps and active-partner changes are server-authoritative, owner-only replicated, persisted immediately, and blocked during active combat by default.

The HUD also gains a persistent native **Party Quick Access** bar. Press **Tab** to enter interaction mode: gameplay look/movement is temporarily released, the mouse cursor appears, healthy Party slots become clickable, and `RECALL`, `OPEN PARTY` and `OPEN BANK` actions expand below the roster. Tab again or Escape returns cleanly to gameplay. The bar remains owner-only presentation and all actual switching still goes through the normal server RPC path.

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
- When the local player's active partner enters the existing replicated authoritative `Chasing`, `Attacking` or `Recovering` combat states, the local soundtrack crossfades to **Battle Music**. Merely selecting a target does not start battle music.
- After combat ends, a configurable release delay prevents rapid soundtrack chatter before the music crossfades back to **Open World Music**.
- Frontend, Open World and Battle volume multipliers plus a global master volume and crossfade duration are exposed in Project Settings.
- Framework music can automatically replay a track that naturally ends, so both looping Sound Cues and ordinary non-looping `USoundBase` assets are supported.
- Battle music gracefully falls back to Open World music if no dedicated Battle asset is assigned.
- The music director lives in a `GameInstanceSubsystem`, so Frontend audio can persist naturally through map travel and transition cleanly into gameplay music.
- Music is **client-local presentation only**. No audio track, playback time or music RPC is replicated; each player reacts to their own replicated partner combat state, which is the correct MMO behavior when different players are fighting different encounters. Dedicated servers render no music.

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

The Digimon menu began as a tabbed shell in v0.7; in current builds its roster page is the six-slot `PARTY`, with `BANK / BOXES`, `SCAN & MATERIALIZE`, `DIGIVOLUTION` and `CARE` implemented alongside it. The Scan page uses species portraits, progress cards, readiness badges, a large selected-species terminal, collection-capacity checks and a server-backed Materialize action. Battle rewards also produce a native owner-only Scan toast with `+X%`, total progress and `MATERIALIZATION READY`.

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
- At least one valid `PlayerStart`.

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
- Battle EXP and money rewards persisted on authoritative victory.
- Blueprint hooks for ability presentation, defeat presentation, target changes, combat state, vitals and battle rewards.

## Foundation retained from v0.1.0

- Multiplayer-only MMO gameplay GameMode (`ADMFMMOGameMode`).
- Frontend GameMode/HUD with a fully functional native UMG fallback login/main-menu UI.
- Username/password credential staging with server-side validation during connection.
- Optional first-login auto-registration on the host's server-side account database.
- Project-configurable regular-player server endpoint under `Networking → Server Endpoint`; no plugin C++ edit is required to change the host/IP used by **Join Game**.
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
6. Create `/Game/DigimonData` for framework Data Assets. Merge `ConfigTemplates/DMF_Project_DefaultGame.ini.snippet` into your project's `Config/DefaultGame.ini` so species/roster/ability/player-skin Primary Assets are discovered and always cooked.
7. Create a Blueprint derived from `DMFPlayerAvatarCharacter` if you want project-specific camera/movement defaults, and assign it as your MMO GameMode Default Pawn Class. The native class is already the C++ default.
8. Create one `DMFPlayerSkinData` asset per selectable character under `/Game/DigimonData` and assign each existing skeletal mesh/AnimBP. The skin UI discovers enabled assets automatically.
9. In **Project Settings → Game → Digimon MMO Framework**, assign:
   - `Frontend Map`
   - `Open World Map`
   - `Starter Roster`
   - `Networking → Server Endpoint → Server Public Address / Hostname`
   - `Networking → Server Endpoint → Game Port`
   - `Networking → Admin Hosting → Set Admin Hosting Password` (enter a project-specific password; the setter clears after hashing)
   - `Player Avatar → Footsteps → Player Footstep Sound` (assign a spatial Sound Cue; optional cadence/gain controls are alongside it)
   - optional `Default Player Skin` when skin selection is not mandatory
10. Create `DMFDigimonAbilityData` assets under `/Game/DigimonData` for the basic attack and quick-slot abilities you want to test. Configure SP cost, cooldown, timing, range, damage scaling and presentation assets.
11. Create one `DMFDigimonSpeciesData` asset per species under `/Game/DigimonData`; assign `BasicAutoAttack`, `StartingAbilities`, battle rewards and the species presentation assets.
12. Every playable/summonable species should provide a `WorldActorClass` derived from `ADMFDigimonCharacter`.
13. Create a `DMFStarterRosterData` asset under `/Game/DigimonData` and add the desired starter species.
14. Cover the combat/exploration area with a valid `NavMeshBoundsVolume` so authoritative Digimon AI can follow, chase and return to its leash anchor.
15. For MMO population streaming, create a Blueprint child of `DMFWildDigimonSpawner`, add rarity-weighted spawn entries and place it inside valid NavMesh. See `Docs/SETUP_WILD_DIGIMON_SPAWNER.md`.
16. Place standalone `ADMFWildDigimonCharacter` Blueprints only for fixed/scripted encounters if desired.
17. Package normally. The admin can log in, unlock Admin and choose **Host & Play**. Regular users log in and choose **Join Game**.

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

See `Docs/ARCHITECTURE.md`, `Docs/SETUP_PLAYER_CAMERA_ZOOM.md`, `Docs/SETUP_GLOBAL_MUSIC.md`, `Docs/SETUP_PLAYER_AVATAR_SKINS.md`, `Docs/SETUP_PLAYER_FOOTSTEPS.md`, `Docs/SETUP_STARTER_SYSTEM.md`, `Docs/SETUP_COMBAT_SYSTEM.md`, `Docs/SETUP_PLAYER_INTERACTION_SYSTEM.md`, `Docs/SETUP_WILD_DIGIMON_SPAWNER.md`, `Docs/SETUP_MANUAL_COMBAT_HEALER_INVENTORY.md`, `Docs/SETUP_WORLD_NAMEPLATES.md`, `Docs/SETUP_WORLD_CHAT.md`, `Docs/SETUP_SERVER_ENDPOINT.md`, `Docs/SETUP_ADMIN_HOSTING.md`, `Docs/SETUP_SCAN_MATERIALIZATION.md`, `Docs/SETUP_CARE_SYSTEM.md`, `Docs/NETWORKING.md`, `Docs/TEST_PLAN.md`, `Docs/ROADMAP.md` and `CHANGELOG.md`.


## Native frontend UI bootstrap (0.3.2)

The native login, player-skin, starter and combat widgets are functional C++ fallbacks and do not require Widget Blueprint assets. Their fallback `WidgetTree` is constructed during `RebuildWidget()` so it exists before the underlying Slate widget is built. `DMFFrontendHUD` also retries briefly if the local PlayerController is not ready on its first `BeginPlay` frame. A correctly configured blank MainMenu using `DMFFrontendGameMode` should therefore show the native login UI rather than an empty black viewport.
