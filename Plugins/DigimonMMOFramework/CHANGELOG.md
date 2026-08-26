# Changelog

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
