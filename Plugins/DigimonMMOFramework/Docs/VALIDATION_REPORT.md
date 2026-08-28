# v0.14.8-alpha validation summary

## Owned Digimon Level progression / EXP UI source validation
- Built directly on the user-runtime-validated v0.14.7 `FullWildAbilityMovesetRotationFix` baseline. v0.14.8 still requires a clean UE5.8.1 compile plus listen-host/remote-client runtime acceptance before promotion.
- Root progression gap confirmed: authoritative Battle victory previously appended `BattleExperienceReward` to `Stats.Experience` but had no threshold consumption, Level increment, stat growth, Attribute Point grant, active-actor stat refresh or level-up presentation.
- `UDMFPlayerDigimonComponent` now owns one server-only EXP mutation path. It clamps legacy values, resolves the current species-owned numeric requirement, subtracts every crossed threshold, supports multiple level-ups in one reward, applies existing HP/SP/STR/INT/DEF/SPD Per Level growth and grants existing `AttributePointsPerLevel`.
- Current HP/SP preserve the amount already missing/spent as MaxHP/MaxSP grow; defeated Digimon remain defeated. `RefreshProgressionFromInstance` / `RefreshRuntimeVitalsAfterProgression` update the summoned partner without calling the combat initialization/reset path, so target, cooldowns, recovery and the durable battle-encounter latch are not reset by progression.
- Existing stored pre-v0.14.8 EXP is normalized on authoritative account hydration. No SaveGame migration field is needed: schema remains **v5**, and the existing persisted Level/Experience/stats/UnspentAttributePoints fields remain the durable ledger.
- `DMFDigimonSpeciesData` adds `BaseExperienceRequired`, `ExperienceGrowthMultiplierPerLevel` and optional `MaxLevelOverride`. Requirement math is shared by server mutation and owner-local UI: `Base * Multiplier^(Level-1)`. Project Settings keeps the master leveling switch and global default max level; no CurveFloat asset or global EXP fallback is required.
- Native Party and Bank selected-details now display `EXP current / required`, progress bars, `MAX` at cap and unspent Attribute Points. Four Blueprint-pure progression queries expose the same display calculations without mutation authority.
- Added Blueprintable `UDMFExperienceNotificationWidget`: owner-local queued `+EXP` progress animation, multi-level threshold traversal, a distinct LEVEL UP state revealed at the first animated threshold crossing plus the Attribute Point result. Project Settings exposes widget replacement, enable, animation/hold times and HUD-safe bottom offset.
- Added exactly one network RPC, `ClientDigimonExperienceProgressed(FDMFDigimonExperienceProgression)`. It is a reliable owner Client presentation snapshot only; Party/Bank durable data remains owner-only Fast Array state and the active world partner's public `ReplicatedStats` continues through ordinary property replication.

## Baseline compatibility / static gate
- Baseline v0.14.7: **116 files**, **80 source/header/build files**, **24,054 source/build lines**, **42 UCLASS**, **15 UENUM**, **16 USTRUCT**, **423 UFUNCTION**, **770 UPROPERTY**, **42 reflected RPC declarations**.
- Revised v0.14.8 candidate: **120 files**, **83 source/header/build files**, **24,972 source/build lines**, **43 UCLASS**, **15 UENUM**, **17 USTRUCT**, **434 UFUNCTION**, **802 UPROPERTY**, **43 reflected RPC declarations**.
- Added files only: `Docs/SETUP_LEVEL_PROGRESSION.md`, `Public/UI/DMFExperienceNotificationWidget.h`, `Private/UI/DMFExperienceNotificationWidget.cpp`, and private shared progression helper `Private/Progression/DMFLevelProgressionMath.h`. **Zero baseline files removed.**
- **Zero existing reflected UFUNCTION names removed**, **zero existing UPROPERTY names removed**, **zero existing RPC names removed**. The only RPC addition is `ClientDigimonExperienceProgressed`; all 43 reflected Server/Client/NetMulticast declarations have matching `_Implementation` bodies.
- Added reflected functions are limited to the four progression queries, the owner Client result RPC/delegate handler, the two progression-safe actor/combat refresh APIs, the notification entry point and two Blueprint presentation hooks.
- All 15 UENUM declarations retain identical value/order definitions to v0.14.7. Save schema remains v5. No serialized enum migration or account-database migration step is introduced.
- Generated-header include ordering passes for all headers; changed C++ delimiter counts are balanced; changed runtime source has no TODO/FIXME markers; plugin JSON parses successfully.
- Unreal Engine/UnrealBuildTool is not installed in this assembly environment, so only static/source validation is claimed here. Runtime truth remains the user's UE5.8.1 compile + multiplayer test.

## Required v0.14.8 runtime acceptance
Run `TEST_PLAN.md` section **L0**. In particular validate species-authored 25-EXP progression to Level 2, Party/Bank required-EXP bars, native queued EXP toast + LEVEL UP state, species-specific numeric EXP requirements, multi-level rewards, exact per-level stat/Attribute Point gains, combat-state continuity, max-level behavior, old banked-EXP normalization, reconnect persistence, and remote-client ownership privacy/public partner Level replication.

---

# v0.14.6-alpha validation summary

## Attack VFX / enemy marker CustomDepth enforcement
- Direct attack Niagara/Cascade spawn paths force `SetRenderCustomDepth(true)` immediately after component creation.
- Projectile-impact Niagara/Cascade spawn paths force the same flag on every impact component.
- Replicated moving projectile Niagara/Cascade components enable CustomDepth at construction and reassert it on every presentation refresh.
- Owner-local enemy target-arrow Niagara/Cascade components enable CustomDepth at construction, runtime asset refresh and activation.
- No stencil value is overwritten by this release.
- No RPC, replicated gameplay state, SaveGame schema or serialized enum changes are required.

## Prior validated baseline carried forward
The implementation is based on the user-runtime-validated v0.14.5-alpha rarity-weight normalization baseline. v0.14.6 requires UE5.8 host/client runtime validation before being marked accepted.

---

- Built directly on the runtime-accepted v0.14.4 `PersistentBattleMusicEncounterStateFix` baseline.
- Root cause isolated to `ADMFWildDigimonSpawner::SelectWeightedSpawnEntryIndex()`: the old one-pass table gave every individual entry `RarityWeight * EntryMultiplier`, so the same rarity base weight was counted repeatedly when a tier contained many species.
- Replaced that roll with a two-stage authority-only algorithm: build currently eligible rarity buckets, roll each eligible rarity weight exactly once, then roll an entry inside the selected bucket from its non-negative `SelectionWeightMultiplier`.
- Entry enable state, valid species/class, positive rarity weight, positive entry weight and `MaxAliveFromEntry` capacity are all evaluated before either roll.
- `ComputeConfiguredPopulationCapacity()` now uses the same explicit positive rarity/entry eligibility semantics rather than relying on a multiplied weight solely as a boolean check.
- No RPC, replicated property, SaveGame field, UENUM ordering or Blueprint property was added/removed. Existing spawner Blueprint data remains source-compatible.
- Wild species/rarity/level decisions remain server-only; clients continue to receive the replicated result rather than rolling locally.
- v0.14.4 persistent Battle music behavior is unchanged.

## Inherited v0.14.4 validation baseline

- Built directly on the user-provided v0.14.3 `LocalTargetingVisibilityRuntimeFix` working baseline.
- Root cause isolated to music using transient `CombatState` action phases as the lifetime of an encounter; manual recovery legitimately returned to `Idle`, allowing the old release-delay countdown to expire mid-battle.
- Added one replicated server-authoritative `bBattleEncounterActive` boolean to `UDMFDigimonCombatComponent` plus Blueprint-pure `IsBattleEncounterActive()`. Clients have no setter/RPC path for this state.
- Encounter activation is tied to valid hostile `Chasing`/`Attacking`/`Recovering` activity and deliberately survives `Idle` between manual commands. Victory, self defeat, target clear/disengage, combat reset/healer teardown, and authoritative invalid-target cleanup clear the latch.
- `UDMFMusicSubsystem` now prefers the durable encounter latch and retains the transient active-state check only as a replication-ordering safety path for immediate Battle entry. Target selection alone still does not start Battle music.
- Music remains local-only presentation. No music/audio RPC, playback replication, crossfade replication or shared AudioComponent state was added.
- SaveGame schema is unchanged. v0.14.3 targeting visuals, v0.14.1 projectiles/VFX, DigiDex, Digivolution, Party/Bank, Scan/Materialization, Care/healer, chat/nameplates, camera/footsteps and account persistence remain additive regression contracts.
- Final static gate: **80 source/header/build files, 23,790 source/build lines, 42 UCLASS, 15 UENUM, 16 USTRUCT, 423 UFUNCTION and 770 UPROPERTY declarations**.
- All **42 Server/Client/NetMulticast RPC declarations** retain matching `_Implementation` bodies; v0.14.4 adds no RPCs.
- Comparison against v0.14.3 finds **zero baseline files removed**, **zero existing reflected UFUNCTION names removed**, and exactly one new reflected query (`IsBattleEncounterActive`).
- Generated-header ordering, changed-source delimiter balance, runtime TODO/FIXME scan and direct encounter-state mutation checks pass.
- Unreal Engine/UnrealBuildTool is not installed in this assembly environment, so UE5.8 compile plus listen-host/remote-client runtime validation remain the authoritative acceptance gates.

# v0.14.3-alpha validation summary

- Built directly on v0.14.2 targeting-visual source, itself additive over the user-runtime-accepted v0.14.1 projectile baseline.
- Fixed the local rendering contract by removing redundant `OnlyOwnerSee`/owner-view filtering from the non-replicated targeting presentation components.
- Targeting privacy remains structural: `ADMFTargetingPresentationActor::bReplicates=false` and is spawned only by a local `DMFMMOPlayerController`; no marker state is added to replication.
- Added lazy Project Settings asset refresh during PIE and made presentation-actor creation independent of the master enable switch so enable/asset changes can recover without a level restart.
- No SaveGame schema, combat authority, target-selection RPC, projectile authority, Party/Bank, DigiDex, Digivolution, Care/healer or account persistence behavior changed.
- Final static gate: **80 source/header/build files, 23,711 source/build lines, 42 UCLASS, 15 UENUM, 16 USTRUCT, 422 UFUNCTION and 769 UPROPERTY declarations**.
- All **42 Server/Client/NetMulticast RPC declarations** retain matching `_Implementation` bodies; v0.14.3 adds no RPCs.
- Comparison against v0.14.2 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**.
- Generated-header ordering, changed-source delimiter balance, runtime TODO/FIXME scan and targeting-render-owner regression checks pass.
- Archive integrity/hash is verified during packaging.

# v0.14.1-alpha validation summary

- Built directly on the accepted/runtime-validated v0.14.0 DigiDex baseline.
- Final static gate: **78 source/header/build files, 23,051 source/build lines, 41 UCLASS, 15 UENUM, 16 USTRUCT, 417 UFUNCTION and 735 UPROPERTY declarations**.
- All **42 Server/Client/NetMulticast RPC declarations** have matching `_Implementation` bodies; v0.14.1 adds only `MulticastPlayProjectileImpactCue` for transient impact presentation.
- Comparison against v0.14.0 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**.
- Added native Blueprintable `ADMFAbilityProjectileActor` plus opt-in `EDMFAbilityExecutionMode::Projectile`; all existing ability assets remain Timed Impact by default.
- Projectile launch/direction/homing/arrival/damage are authority-owned. Clients receive replicated projectile movement and cosmetic impact presentation only.
- Timed/instant and impact Niagara/Cascade cues have forced lifetime cleanup; projectile-attached visuals are removed with the replicated projectile actor on impact/invalid state/lifetime expiry.
- Generated-header include ordering, changed-source delimiter balance, runtime TODO/FIXME scan and UE5.8 local `Slot` shadowing regression checks pass.
- SaveGame schema, DigiDex, Digivolution, Party/Bank, Scan/Materialization, Care/healer and all previous account/network authority contracts are unchanged.

# Validation Report

## v0.13.1-alpha — Digivolution owned-roster UI layout source validation

- Root cause isolated to `DigivolutionOwnedGrid` card slots using horizontal `Fill`, which allowed sparse UniformGrid rows to stretch fixed cards and their `UImage` portraits.
- Cards now use fixed 132 × 166 SizeBoxes with centered UniformGrid alignment.
- Roster uses three columns within the 500-unit left panel.
- Portraits use a dedicated 104 × 104 square `UScaleBox` (`ScaleToFit`, `DownOnly`) viewport before the `UImage`, preventing parent-cell distortion.
- PARTY/BANK + name/level metadata moved into a separate footer; ACTIVE/KO badges remain isolated in the portrait overlay.
- No Digivolution RPC/persistence/requirement logic changed.
- Final static gate: **76 source/header/build files, 21,515 source/build lines, 40 UCLASS, 14 UENUM, 16 USTRUCT, 401 UFUNCTION and 685 UPROPERTY declarations**.
- All **41 Server/Client/NetMulticast RPC declarations** retain matching `_Implementation` bodies.
- Comparison against v0.13.0 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**.
- Generated-header ordering, changed-source delimiter balance, runtime TODO/FIXME scan and native-UI `Slot` shadow checks pass.


## v0.13.0-alpha — polished replicated Digivolution source validation

Static/source validation was performed against the user-runtime-accepted v0.12.2 replicated-healer baseline. Unreal Engine/UnrealBuildTool is not installed in the assembly environment, so a clean UE5.8.1 compile plus listen-host/remote-client runtime validation remain the authoritative acceptance gates.

Validated contracts:
- Digivolution is authored as one-way data-driven paths on `DMFDigimonSpeciesData`, with target species, Level, ABI, CAM, optional STR/INT/DEF/SPD gates, optional Happiness/Discipline/Care-Mistake gates, optional money cost, Bank permission, stat/ability/vital carry-over policy and per-path presentation overrides.
- The owning client submits only persistent instance GUID + requested target species ID through `ServerDigivolveOwnedDigimon`. The server resolves the current source species/path and revalidates ownership, storage location, requirements, money, Care state and active-combat policy before any durable mutation. A summoned transformation is revalidated again before commit.
- Party and Bank remain the single ownership authority and continue using owner-only Fast Arrays. Party Digimon evolve in place; allowed Bank Digimon evolve directly in storage without spawning a temporary world actor.
- SaveGame schema advances to **v5** with `OriginSpeciesId` and unique `DigivolutionHistory`. Existing GUID, Party/Bank placement, active partner, nickname, Level/EXP, ABI/CAM, Care state, vitals, abilities and progression are preserved during migration and successful form changes according to the authored carry-over policy.
- A summoned active partner uses a server-owned presentation lock, clears combat intent, reliably multicasts Niagara-preferred/Cascade-fallback VFX + Sound Cue from the old actor, then commits/persists and replaces that actor with the target species `WorldActorClass`. Normal actor replication publishes the resulting public form.
- Conflicting partner switch/recall, Party/Bank mutation, Care, healer, targeting and ability requests reject while an active world Digivolution sequence is in progress. Active combat blocks transformation by default through Project Settings.
- The native Digimon Menu adds **DIGIVOLUTION** without shifting the serialized numeric values of existing menu-tab entries. Visual order in v0.14 is **PARTY → BANK / BOXES → SCAN & MATERIALIZE → DIGIDEX → DIGIVOLUTION → CARE** and follows the v0.12.1 hardened scroll/footer layout rules.
- Fresh/In-Training stage display names were corrected at reflection/display level without changing the underlying stage enum values.
- Comparison against v0.12.2 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**. The only newly added file is `Docs/SETUP_DIGIVOLUTION.md`; all runtime changes are extensions of existing source files.
- Final static regression gate covers **76 source/header/build files and 21,447 source/build lines**, with **40 UCLASS**, **14 UENUM**, **16 USTRUCT**, **401 UFUNCTION** and **685 UPROPERTY** declarations. All **41 reflected Server/Client/NetMulticast RPC declarations** have matching `_Implementation` bodies.
- Generated-header include ordering, changed C++ delimiter balance and runtime TODO/FIXME checks pass. The only rough `Slot` identifier matches are the unchanged persistence SaveGame-slot locals that already existed in v0.12.2; no new native UI `UWidget::Slot` shadowing candidate was introduced.

Required runtime acceptance: clean UE5.8.1 compile, then run `TEST_PLAN.md` section **G0** on listen host + remote client. Validate active summoned evolution, Bank in-place evolution, READY/LOCKED requirements, one-time money deduction, combat/Care/healer/storage locks, Niagara and Cascade fallback presentation, persistence after reconnect, and the existing Party/Bank/Scan/Care/healer/combat/UI regressions.

## v0.12.2-alpha — polished replicated healer treatment source validation

- Built directly over the accepted v0.12.1 Party/Bank/native-UI baseline. No baseline source file or existing reflected UFUNCTION is removed.
- `ADMFHealerActor` adds a native presentation anchor, pulsing green point light, Niagara component, Cascade fallback component and attached audio component. All asset/placement/light/audio tuning is Blueprint/Details exposed.
- Durable healer state is server-owned and replicated: `bHealingInProgress`, `ActiveHealingPlayerState` and `ActiveHealingDigimonCount`. Rendering clients reconstruct cosmetic presentation locally; there is no replicated per-frame light/VFX transform data.
- One healer actor rejects concurrent treatment requests while its accepted sequence is active. The existing client-owned PlayerController remains the RPC ingress and the server still validates enabled state, range, reuse timing and Digimon ownership before mutation.
- `HealAllOwnedDigimon` remains the gameplay mutation and continues to restore the complete Party plus all replicated/persistent Bank/Box entries when Bank inclusion is enabled, then persists account state.
- Existing `BP_OnHealPresentation` and its multicast RPC remain intact. New `BP_OnHealingSequenceStarted/Finished`, `IsHealing`, `GetActiveHealingPlayerState` and `RefreshHealingPresentation` extend presentation only.
- Dedicated servers skip local light/VFX/audio presentation. Disabling the station during treatment terminates its local/replicated presentation cleanly.
- Final static counts for this package: **76 source/header/build files, 20,023 source/build lines, 40 UCLASS, 14 UENUM, 15 USTRUCT, 382 UFUNCTION and 636 UPROPERTY declarations**. All **37 Server/Client/NetMulticast RPC declarations** have matching `_Implementation` bodies.


## v0.12.1-alpha — polished native UI layout-hardening source validation

Static/source validation was performed against the user-runtime-validated v0.12.0 Party/Bank/Boxes baseline. Unreal Engine/UnrealBuildTool is not installed in the assembly environment, so a clean UE5.8.1 compile plus visual/runtime acceptance remain authoritative.

Validated contracts:
- The Digimon Menu fallback design canvas is rebalanced to 1240x900 while retaining the existing Down-Only ScaleBox wrapper for smaller viewports. Party/Bank/Scan/Care left/right lanes were widened without changing any gameplay widget class or RPC path.
- Party and Scan description bodies are clipped by dedicated ScrollBoxes above fixed action footers; Bank stats/destination guidance use a scroll body above **MOVE / SWAP TO PARTY**; Care rules use the same protected pattern. Long authored/localized text therefore cannot draw through the action controls.
- Bank Box cards retain explicit fixed size inside a dedicated grid ScrollBox. Page sizes above the default 30 add scrollable rows instead of compressing the six-column card grid, while the Party Destination strip remains outside/pinned below the grid.
- Dense tile/HUD buttons use a compact native style with reduced internal padding. Party Quick Access now gives each portrait and two-line identity/state label the full card width. The combat quickbar collapses the icon container when an ability has no icon, eliminating the empty-square width penalty visible in v0.12.0.
- This is presentation-only: comparison against v0.12.0 finds **zero files removed**, **zero files added**, **zero reflected UFUNCTION names removed**, and **zero reflected UFUNCTION names added**. Party/Bank persistence, SaveGame v4, Materialization routing, combat, Care, chat, nameplates, camera and audio code paths remain intact.
- Final static regression gate covers **76 source/header/build files and 19,532 source/build lines**, with **40 UCLASS**, **14 UENUM**, **15 USTRUCT**, **376 UFUNCTION** and **610 UPROPERTY** declarations. All **37** reflected Server/Client/NetMulticast RPC declarations still have matching `_Implementation` bodies.
- Generated-header ordering, changed-source delimiter balance, runtime TODO/FIXME checks and the v0.12.0 reflected API preservation audit pass.

Required runtime acceptance: clean UE5.8.1 compile, then run `TEST_PLAN.md` section **U0** at 1920x1080 and a smaller PIE viewport, followed by the existing **P0** Party/Bank/Materialization/storage regression suite.

## v0.12.0-alpha — Party, Digimon Bank / Boxes & Party Quick Access source validation

Static/source validation was performed against the user-runtime-accepted v0.11.1 camera baseline. Unreal Engine/UnrealBuildTool is not installed in the assembly environment, so a clean UE5.8.1 compile plus listen-host/remote-client runtime test remain the authoritative acceptance gates.

Validated contracts:
- The historical `ReplicatedInventory` / `DigimonInventory` path is preserved as the active **Party** for API/save compatibility; a second owner-only `ReplicatedBank` Fast Array mirrors persistent `DigimonBank` storage. Both use `COND_OwnerOnly`.
- Project Settings exposes Party capacity (six maximum), Bank capacity/page size, default combat mutation lock, Party Quick Access widget/default input/master visibility and safe-layout offset.
- Durable Party/Bank mutations use three reliable Server RPCs plus one owner Client result RPC. The server validates source membership, capacities, destination slots, Care state and combat policy; all **37** total Server/Client/NetMulticast RPC declarations in the complete framework have matching `_Implementation` bodies.
- Full-Party Bank withdrawal uses one authoritative atomic swap. Party-to-Bank deposit cannot remove the final Party member. Active-slot swaps reconcile the active GUID and refresh the summoned authoritative partner when required.
- Materialization fills Party first, routes to Bank when Party is full, and rejects only when both storage tiers lack legal capacity. Owned-species counts cover both tiers.
- Save schema is v4. Legacy collection migration de-duplicates instance GUIDs, preserves current six-slot Party order on subsequent loads, and only promotes the previous active partner when an oversized legacy collection would otherwise push it outside Party. Existing oversized Bank data is never truncated.
- The Digimon Menu enum preserves the pre-v0.12 serialized order/value of `Collection`, `ScanAndMaterialize`, and `Care`; `Bank` is appended rather than inserted. The native visual tab row still deliberately renders **PARTY → BANK / BOXES → SCAN & MATERIALIZE → CARE**.
- `UDMFPartyQuickBarWidget` is owner-local presentation. Tab cursor/input mode is not replicated; clicking a Party slot routes through the existing authoritative active-partner request. Care/modal UI hide and restore the quick bar instead of creating parallel gameplay state.
- The first Materialization/storage UI refresh does not guess placement from an RPC arrival order; it resolves the returned instance GUID against replicated Party/Bank state so Fast Array versus Client-RPC ordering cannot select the wrong tab/page.
- UE5.8 `UWidget::Slot` shadowing was explicitly audited in the changed native UI. New action-slot locals use descriptive names and no local `Slot` declaration remains.
- Final static regression gate covers **76 source/header/build files and 19,463 source/build lines**, with **40 UCLASS**, **14 UENUM**, **15 USTRUCT**, **376 UFUNCTION** and **610 UPROPERTY** declarations.
- Comparison against v0.11.1 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**. Added runtime source is limited to the Party Quick Access and Party destination-button source pairs; `Docs/SETUP_PARTY_BANK_STORAGE.md` is the only new documentation file.
- Generated-header ordering, changed-source delimiter balance, runtime TODO/FIXME checks and the reflected RPC implementation audit pass.

Required runtime acceptance: clean UE5.8.1 compile, then run `TEST_PLAN.md` section **P0** on listen host + remote client and packaged two-PC host/client, followed by the v0.11.1 camera and existing music/footsteps/WORLD chat/nameplate/Care/Scan/combat regressions.

## v0.11.1-alpha — polished player camera boom zoom & character-safe collision source validation

Static/source validation was performed against the user-accepted v0.11.0 global-music baseline. Unreal Engine/UnrealBuildTool is not installed in the assembly environment, so a clean UE5.8.1 compile plus listen-host/remote-client runtime test remain the authoritative acceptance gates.

Validated contracts:
- `ADMFPlayerAvatarCharacter` owns the requested boom distance locally; mouse-wheel input and interpolation do not create a replicated property, RPC or SaveGame field.
- Project Settings exposes the camera master switch, default Mouse Wheel input toggle, default/min/max boom distances, wheel step and interpolation speed. Runtime sanitization handles reversed min/max values and clamps the default/requested distance into the resolved range.
- Mouse Wheel Up routes to positive zoom input (closer camera); Mouse Wheel Down routes to negative zoom input (farther camera). Enhanced Input projects can disable only the default binding and call the Blueprint zoom API directly.
- `USpringArmComponent` explicitly retains `bDoCollisionTest=true` with `ECC_Camera`, preserving wall/world obstruction behavior.
- The global character-safe policy applies `ECC_Camera=Ignore` to every primitive component on framework player avatars and Digimon during construction/BeginPlay, including Blueprint-added primitive components. No Pawn, Visibility, combat, interaction or navigation response is modified.
- `RefreshCameraCollisionPolicy` is exposed on both player and Digimon classes for projects that deliberately alter component collision later at runtime.
- Final static regression gate covers **72 source/header/build files and 17,447 source/build lines**, with **37 UCLASS**, **13 UENUM**, **15 USTRUCT**, **336 UFUNCTION** and **574 UPROPERTY** declarations. All **33 reflected Server/Client/NetMulticast RPC declarations** still have matching `_Implementation` bodies.
- Comparison against v0.11.0 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**. The only added file is `Docs/SETUP_PLAYER_CAMERA_ZOOM.md`.
- Generated-header ordering, changed-source delimiter balance and runtime TODO/FIXME checks pass.

Required runtime acceptance: clean UE5.8.1 compile, then run `TEST_PLAN.md` section **C0** with listen host + remote client, followed by the v0.11.0 music, v0.10.4 footsteps and existing WORLD chat/nameplate/Care/Scan/combat regressions.

## v0.11.0-alpha — polished global music director source validation

> Historical note: the original v0.11 battle-lifetime rule below was superseded by the durable replicated encounter latch in v0.14.4. The remainder records the v0.11 source gate as it existed at release.

Static/source validation was performed against the user-runtime-validated v0.10.4 automatic player-footstep baseline. Unreal Engine/UnrealBuildTool is not installed in the assembly environment, so a clean UE5.8.1 compile plus Frontend/Open World/listen-host/remote-client runtime test remain the authoritative acceptance gates.

Validated contracts:
- Added `UDMFMusicSubsystem` as a GameInstance-lifetime local presentation director with semantic `None`, `Frontend`, `OpenWorld` and `Battle` states.
- `FrontendMap` / `OpenWorldMap` drive the normal map context, with framework GameMode/PlayerController fallbacks for compatible custom map setups and PIE-prefix-safe world-name matching.
- Battle state is derived only from the local active partner's existing replicated authoritative CombatComponent state (`Chasing`, `Attacking`, `Recovering`). A command target by itself does not trigger Battle music.
- The configurable Battle release delay de-bounces return-to-exploration transitions; a defeated/no-partner state cannot hold Battle music forever.
- Frontend/Open World/Battle tracks, master/per-state volumes, crossfade, release delay, automatic replay and evaluation interval are Project Settings exposed. Missing Battle audio gracefully falls back to Open World audio.
- Music uses persistent 2D AudioComponents with manual lifetime management and crossfades; automatic replay supports non-looping assets while internally-looped Sound Cues remain uninterrupted.
- Music is client-local presentation only: **zero RPCs and zero replicated properties** were added for music. Dedicated servers transition to `None` and create no local music playback.
- Blueprint extension surface adds only `GetCurrentMusicState`, `RefreshMusicState`, `SetMusicSuppressed`, `IsMusicSuppressed` and the local `OnMusicStateChanged` delegate.
- Final static regression gate covers **72 source/header/build files and 17,218 source/build lines**, with **37 UCLASS**, **13 UENUM**, **15 USTRUCT**, **330 UFUNCTION** and **566 UPROPERTY** declarations. All **33 reflected Server/Client/NetMulticast RPC declarations** still have matching `_Implementation` bodies.
- Comparison against v0.10.4 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**. Added files are the music subsystem source pair plus `Docs/SETUP_GLOBAL_MUSIC.md`.
- Generated-header ordering, changed-source delimiter balance and runtime TODO/FIXME checks pass.

Required runtime acceptance: clean UE5.8.1 compile, then run `TEST_PLAN.md` section **M0** with listen host + remote client, followed by v0.10.4 footsteps and the existing WORLD chat/nameplate/Care/Scan/combat regressions.

## v0.10.4-alpha — automatic replicated player-footstep source validation

Static/source validation was performed against the v0.10.3 configurable Admin-hosting baseline. Unreal Engine/UnrealBuildTool is not installed in the assembly environment, so a clean UE5.8.1 compile plus listen-host/remote-client runtime test remain the authoritative acceptance gates.

Validated contracts:
- Footstep runtime changes are confined to `ADMFPlayerAvatarCharacter` plus global `UDMFFrameworkSettings`; `ADMFDigimonCharacter` and Wild Digimon code are unchanged, enforcing the player-only boundary.
- Automatic cadence reads grounded horizontal `CharacterMovement` velocity and distance travelled rather than AnimBP notifies or the optional native WASD input state.
- Walk, sprint and crouch stride distances, minimum movement speed, global enable, Sound Cue/USoundBase, volume and pitch are Project Settings exposed.
- Audio originates from the capsule base, avoiding a per-skeleton socket dependency for player skins.
- Remote owning clients predict their own local sound for responsiveness; authority independently produces observer presentation through `MulticastPlayPlayerFootstep` as an **Unreliable NetMulticast**. The remote owner suppresses the returned multicast echo.
- Dedicated servers do not play audio locally; no durable footstep state enters account persistence, replicated properties, combat or movement authority.
- The configured sound is warmed on rendering clients during BeginPlay to avoid a first-step synchronous-load hitch, with safe lazy fallback if needed.
- Final static regression gate covers **70 source/header/build files and 16,655 source/build lines**, with **36 UCLASS**, **12 UENUM**, **15 USTRUCT**, **326 UFUNCTION** and **550 UPROPERTY** declarations. All **33 reflected Server/Client/NetMulticast RPC declarations** have matching `_Implementation` bodies.
- Comparison against v0.10.3 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**; the only added file is `Docs/SETUP_PLAYER_FOOTSTEPS.md`.
- Generated-header ordering, changed-source delimiter balance and runtime TODO/FIXME checks pass.

Required runtime acceptance: clean UE5.8.1 compile, then run `TEST_PLAN.md` section **F0** on listen host + remote client, followed by existing world-chat/nameplate/Care/Scan/combat regressions.

## v0.10.3-alpha — project-configurable Admin hosting password source validation

The Admin `Host & Play` gate no longer requires a source digest edit. `UDMFFrameworkSettings` now exposes a transient, masked **Set Admin Hosting Password** field under **Networking → Admin Hosting**. On editor change, the plaintext setter is hashed through the existing credential utility, cleared immediately, and only `AdminHostingPasswordDigest` is persisted to the project's default Game config.

Validated contracts:
- `UDMFSessionSubsystem::UnlockAdmin` hashes the locally entered candidate and compares it only against `UDMFFrameworkSettings::AdminHostingPasswordDigest`.
- Raw Admin password text is not retained in session state, network travel options, RPC payloads, replicated properties or account SaveGame data.
- The setter accepts 4-128 characters; invalid setter length preserves the existing digest and clears the temporary plaintext field.
- A malformed runtime digest fails closed with Project Settings guidance.
- The prior digest remains the C++ default solely for upgrade compatibility, so v0.10.2 projects do not lose their working Admin unlock until a replacement password is deliberately set.
- Server endpoint, world chat, nameplates, Care, Scan/Materialization, combat, account and persistence behavior is unchanged.
- Final static regression gate covers **70 source/header/build files and 16,440 source/build lines**, with **36 UCLASS**, **12 UENUM**, **15 USTRUCT**, **324 UFUNCTION** and **541 UPROPERTY** declarations. All **32 reflected Server/Client/NetMulticast RPC declarations** still have matching `_Implementation` bodies. Comparison against v0.10.2 finds **zero baseline files removed**, **zero existing reflected UFUNCTION names removed**, and only `Docs/SETUP_ADMIN_HOSTING.md` added.

Required runtime acceptance: clean UE5.8.1 compile, Project Settings password change + editor restart persistence check, wrong/correct Admin unlock tests, listen-host start, second-client Join Game, then the existing world-chat/nameplate/Care/Scan/combat regression suite.

## v0.10.2-alpha — project-configurable server endpoint source validation

The regular-player endpoint has been moved from a lightly encoded source constant into `UDMFFrameworkSettings::ServerPublicAddress`, exposed under **Networking → Server Endpoint**, while retaining the previous deployment hostname as the default. `UDMFSessionSubsystem` now constructs the player destination exclusively from validated project settings.

Validated contracts:
- `Join Game` consumes the configured host + `GamePort`; no runtime username/password/admin input can alter the destination.
- Endpoint validation rejects empty/oversized values and characters used by URL schemes, paths, embedded ports and Unreal travel-option injection before `ClientTravel`.
- `Host & Play` remains behind the existing local Admin unlock and performs the same endpoint preflight before opening the authoritative listen world.
- No account schema, RPC payload, PlayerState ownership, world-chat, nameplate, Care, Scan/Materialization, combat or persistence authority path is changed.
- The public endpoint remains deployment metadata rather than secret data; router/NAT/firewall/DNS setup remains external to the plugin.
- Final static regression gate covers **70 source/header/build files and 16,375 source/build lines**, with **36 UCLASS**, **12 UENUM**, **15 USTRUCT**, **324 UFUNCTION** and **539 UPROPERTY** declarations. All **32 reflected Server/Client/NetMulticast RPC declarations** still have matching `_Implementation` bodies. Comparison against v0.10.1 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**; only the new endpoint setup document is added.

Required runtime acceptance: clean UE5.8.1 compile, admin listen-host start, second-client join using a configured LAN/public address, invalid-endpoint rejection, then the existing multiplayer regression suite.

## v0.10.1-alpha — world-chat HUD safe-layout source validation

This patch is presentation-only over the runtime-working v0.10.0 world chat reported by the user. The native WORLD chat no longer shares the combat quickbar's bottom HUD lane: when `bShowNativeCombatQuickBar` is enabled, the chat bottom inset is driven by the new configurable `WorldChatBottomSafeOffset` (`176` by default); when the native quickbar is disabled, chat returns to its original `30`-unit inset.

Validated contracts:
- Chat authority, RPC payloads, server sanitation/rate limiting, session history, usernames and input focus are unchanged.
- Combat quickbar dimensions/positioning and combat execution logic are unchanged.
- The new setting is presentation-only and creates no replicated state or RPC.
- Previous Care, Scan/Materialization, nameplate, account/persistence and combat systems remain additive and untouched by the layout fix.
- Final static gate covers **70 source/header/build files and 16,324 source/build lines**, with **36 UCLASS**, **12 UENUM**, **15 USTRUCT**, **324 UFUNCTION** and **538 UPROPERTY** declarations. All **32 reflected Server/Client/NetMulticast RPC declarations** still have matching `_Implementation` bodies; comparison against v0.10.0 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**.

Required runtime acceptance: compile in UE5.8.1 and verify on listen host + remote client that WORLD chat remains clear of the centered ability quickbar at the normal viewport and after resizing PIE windows.

## v0.10.0-alpha — polished native world-chat source validation

Static/source validation was performed against the user-accepted v0.9.1 world-nameplate baseline. Unreal Engine/UnrealBuildTool is not available in the assembly environment, so UE5.8.1 compile and host + remote-client PIE remain the authoritative acceptance gates.

Validated contracts:
- Added only the `UDMFWorldChatWidget` source pair; no v0.9.1 baseline file was removed.
- World chat uses an owned PlayerController Server RPC for text submission and owner-targeted Client RPCs for accepted message/history/rejection delivery.
- Client payloads do not contain sender identity or trusted timestamps. Server `APlayerState::PlayerName` supplies public identity.
- Server sanitation, maximum length, minimum interval and burst-window limits execute before `ADMFMMOGameMode` broadcast/history insertion.
- Session history is bounded in GameMode and transferred to a late joiner on request rather than continuously replicated.
- Chat is absent from account persistence and does not change the SaveGame schema.
- Chat typing locally locks gameplay movement/look and blocks combat/menu hotkeys; Care presentation closes/hides chat without discarding history.
- Master global enable/input/widget/history/safety/timestamp settings are exposed through `UDMFFrameworkSettings`.
- Generated-header include ordering, delimiter balance and TODO/FIXME checks pass; all reflected Server/Client/NetMulticast declarations have matching `_Implementation` bodies.
- Final static gate covers **70 source/header/build files and 16,311 source/build lines**, with **36 UCLASS**, **12 UENUM**, **15 USTRUCT**, **324 UFUNCTION** and **537 UPROPERTY** declarations.
- All **32 reflected Server/Client/NetMulticast RPC declarations** have matching `_Implementation` bodies; comparison against v0.9.1 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**.

Required runtime acceptance: execute the v0.10.0 world-chat section in `TEST_PLAN.md` on listen host + remote client, then the existing nameplate/Care/Scan/combat regression passes.

## v0.9.1-alpha — UE5.8 nameplate compile-fix validation

The user's UE5.8.1/MSVC build log identified exactly two hard compiler errors in the v0.9.0 nameplate implementation: `C2445` at the player-avatar and Digimon fallback-widget-class conditional expressions. Both expressions mixed `TSubclassOf<UDMFWorldNameplateWidget>` with `UClass*` from `StaticClass()`, allowing multiple common conversions.

Corrective validation:
- Player and Digimon nameplate fallback selection now uses explicit `TSubclassOf<UDMFWorldNameplateWidget>` assignment followed by an `if (!DesiredClass)` native-class fallback; no mixed-type conditional expression remains.
- The same build log also exposed two UE5.8 deprecation warnings in the Care prop. Direct network-frequency member writes were replaced with `SetNetUpdateFrequency(10.0f)` and `SetMinNetUpdateFrequency(2.0f)` without changing values.
- Source audit confirms the two reported `C2445` patterns and the deprecated direct member writes are absent from the corrected tree.
- Final static gate covers **68 source/header/build files and 15,324 source/build lines**.
- Reflected surface remains **35 UCLASS**, **298 UFUNCTION** and **513 UPROPERTY** declarations; comparison against v0.9.0 finds **zero existing reflected UFUNCTION names removed**.
- All **27 reflected Server/Client/NetMulticast RPC declarations** still have matching `_Implementation` bodies.
- Generated-header include ordering passes, no runtime `TODO`/`FIXME` placeholders are present, and the corrected tree removes no baseline file.
- A clean UE5.8.1 Editor build is still required to promote this source package to runtime acceptance.


## v0.9.0-alpha — World Nameplates source validation

- Added the native `UDMFWorldNameplateWidget` source pair and automatic Player/Digimon Widget Components.
- Added project-wide and per-category enable gates, cull distances, capsule-relative offsets, refresh throttling and Blueprint widget overrides.
- Player public identity uses `APlayerState::PlayerName`; private `AuthenticatedUsername` remains owner-only and credential digest remains server-only.
- Digimon HP reads the existing replicated combat vitals; `ReplicatedNickname` is the only new Digimon presentation replication field.
- No nameplate Server/Client/Multicast RPCs were added.
- Existing Care, Scan/Materialization, combat, possession, persistence and CustomDepth systems were preserved.
- Unreal Engine/UnrealBuildTool is not installed in the source-assembly environment; a UE5.8.1 compile and host + remote-client PIE test remain the authoritative release gate.

## v0.8.1-alpha — Care Prop CustomDepth Cel-Shading source validation

This patch is intentionally presentation-only over the user-runtime-validated v0.8.0 Care build. Unreal Engine/UnrealBuildTool is not installed in this environment, so the authoritative acceptance gate remains a clean UE5.8.1 compile plus host/remote-client PIE.

Validated source contracts include:
- Final static gate covers **66 C++/header/build source files and 14,768 source/build lines**.
- The existing **27 reflected Server/Client/NetMulticast RPC declarations** still all have matching `_Implementation` bodies; this rendering patch adds no RPCs.
- `ADMFDigimonCarePropActor` forces CustomDepth in its native mesh constructor and reasserts it through `OnConstruction`, `BeginPlay` and `ApplyPresentation`.
- `RefreshFrameworkCustomDepth()` enumerates all owned `UMeshComponent` instances, so Blueprint-added Care presentation meshes can be reasserted as well.
- `CustomDepthStencilValue` is clamped to Unreal's `0-255` stencil range and defaults to `0`, matching the existing framework character contract.
- CustomDepth/stencil state is not replicated and does not alter server authority, RPC count, owner-only Care persistence, feeding timing, DigiMeat attachment, waste placement, collision or cleanup.
- Existing v0.8.0 Care and v0.7.1 Scan/Materialization source remains additive; no feature-removal migration is introduced by this patch.

Required runtime acceptance: verify attached DigiMeat and spawned poo are affected by the existing project cel-shading post process on both host and remote client, while poo remains fully non-colliding and self-cleaning.

## v0.8.0-alpha — Virtual-Pet Care source validation

Static/source validation was performed against the user-runtime-validated v0.7.1 Scan & Materialization baseline. Unreal Engine/UnrealBuildTool is not installed in this environment; therefore no claim of UE5.8.1 compilation or PIE runtime acceptance is made for v0.8.0 until the project is compiled/tested by the user.

Validated source contracts include:
- Final static gate covers **66 C++/header/build source files and 14,718 source/build lines**.
- **27 reflected Server/Client/NetMulticast RPC declarations** have matching `_Implementation` bodies.
- Generated-header include ordering passes for every modified header; modified source delimiters balance; no runtime `TODO`/`FIXME` placeholders or UE5.8 `UWidget::Slot` shadow candidates were introduced.
- Care state remains inside `FDMFDigimonInstance` and therefore follows existing owner-only Fast Array replication/account persistence instead of creating a client-owned parallel ledger.
- New/materialized instances initialize species-driven Hunger; v0.7.x dormant care defaults receive a compatibility migration.
- Account SaveGame schema is bumped to v3; earlier v2 player-skin persistence is preserved and legacy Care semantics are migrated at authoritative account initialization.
- Server UTC time owns online/offline Hunger decay and persisted waste due times.
- The global Care master switch freezes Care progression consistently across live ticks, partner selection and autosave normalization; disabling the feature cannot decay Hunger behind the disabled UI.
- `ServerFeedActivePartnerUntilFull` independently validates the summoned owned partner, health, idle combat, species care enablement, Feeding Montage, DigiMeat mesh and configured hand socket.
- Feeding creates a replicated care prop, attaches it to the species socket using an exposed relative transform/scale, plays the server-controlled Montage count sequentially, awards Hunger only after a complete serving and persists each serving.
- Owner menu/quickbar hiding is presentation-only and occurs before a configurable server lead-in; completion returns the menu to CARE.
- Conflicting partner/combat RPCs are rejected while care is active and combat automation is disabled during feeding.
- Waste is server scheduled/spawned, uses a ground trace at the partner location, replicates presentation, forces collision/overlap/navigation off and self-cleans through actor lifespan.
- Feeding/fart audio indices are selected on authority and sent through existing replicated character presentation.
- CARE is integrated into the existing tabbed native menu rather than a disconnected UI.
- README, changelog, Care setup, architecture, networking, roadmap, native UI setup, test plan, validation report and config template are updated for this milestone.

Required authoritative acceptance: clean UE5.8.1 compile, then the full host + remote-client Care checklist in `TEST_PLAN.md`, followed by existing Scan/Materialization and combat regression tests.

## v0.7.1-alpha — UE5.8 Scan Toast Slot Shadow Compile Fix

### Compiler feedback addressed
- User UE5.8.1 build log reaches UnrealHeaderTool successfully and reports one C++ compiler error: `DMFScanNotificationWidget.cpp(33,23): error C4458: declaration of 'Slot' hides class member`.
- The inherited member is `UWidget::Slot`; the new scan toast had introduced `UOverlaySlot* Slot` in `BuildNativeFallbackUI()`.
- Corrected the local identifier to `ToastOverlaySlot`. No behavior or layout logic changed.

### Static regression checks
- No remaining `U*Slot* Slot`, `auto Slot`, or equivalent local `Slot` declaration exists in the runtime UI source.
- Plugin descriptor reports `0.7.1-alpha` / version integer `701`.
- v0.7.0 Scan/Materialization runtime, account persistence, materialization authority, tabbed menu, combat, wild spawning and multiplayer possession source remains otherwise unchanged.
- Generated-header ordering, delimiter balance, RPC declaration/implementation pairing and TODO/FIXME source checks remain required in the release script.
- Actual UE5.8.1 recompilation is still the authoritative final compile acceptance gate.

## v0.7.0-alpha — Scan Data, Materialization & Tabbed Digimon Menu

Static/source validation was performed against the v0.6.4 repeat-safe combat baseline. Unreal Engine/UnrealBuildTool are not installed in this environment, so a clean UE5.8.1 compile plus host/remote-client runtime testing remain required before calling this release Editor-accepted.

Validated contracts:
- Final gate covers **64 C++/header/build source files and 13,433 source/build lines**.
- Plugin descriptor parses as `0.7.0-alpha`.
- Added three network calls (`ServerMaterializeDigimon`, `ClientScanDataRewardGranted`, `ClientMaterializationResult`); all **18 reflected Server/Client declarations found by the release validator have matching `_Implementation` bodies**.
- Scan Data is copied from `FDMFAccountRecord::ScanData` during account initialization and copied back during persistence; the runtime array replicates `COND_OwnerOnly`.
- Eligible Scan rewards originate only inside the existing authoritative `HandleAuthoritativeBattleVictory` path. With `bAwardScanDataFromWildVictoriesOnly=true`, non-`DMFWildDigimonCharacter` defeats do not award scan progress.
- Species reward/cap/threshold values are read from authoritative `UDMFDigimonSpeciesData`; clients do not submit reward percentages.
- Materialization validates system/species enable state, threshold, active Collection capacity and a partner-compatible `WorldActorClass` before adding an inventory entry or consuming Scan Data. A `DMFWildDigimonCharacter` class is rejected.
- Materialization creates a unique GUID and reuses the existing starter-instance construction path for Base Stats, Starting Level, full HP/SP and starting abilities, then clears the starter flag.
- Scan consumption subtracts the configured requirement, preserving excess progress when the cap is greater than the threshold.
- Scan Database cards remain visible at 0% after first discovery/materialization because the persistent species record is retained.
- The native Digimon menu now has Collection and Scan/Materialize content rows with explicit tab presentation, portrait cards, readiness badges, selected-species progress/details and a server-backed Materialize action.
- Native Scan reward toast is owner-client presentation only and does not mutate gameplay state.
- Protected runtime files for ability execution, target-facing, wild behavior/spawner, MMO GameMode and account persistence subsystem were byte-compared against v0.6.4 and are unchanged.
- Generated-header include ordering passes across all framework headers. Lightweight delimiter checks pass, no TODO/FIXME runtime placeholders exist, and no exact local `USkeletalMeshComponent* Mesh` declaration was reintroduced.

Required authoritative acceptance:
1. Clean compile in UE5.8.1.
2. Configure Gabumon at reward 20%, cap 100%, requirement 100%, valid partner WorldActorClass.
3. Defeat five Wild Gabumon and verify owner-only 20/40/60/80/100 progression plus Scan reward toast / READY state.
4. Confirm the other connected account gains no Scan Data from those victories.
5. Open `I -> SCAN & MATERIALIZE`, verify portrait/progress/details, and materialize once.
6. Confirm exactly one new unique Gabumon appears in Collection, current Scan becomes 0%, and the species remains present in Scan Database.
7. Summon the materialized Digimon and re-run manual attacks, target-facing and wild retaliation.
8. Reconnect both accounts and verify Scan Data/materialized ownership persists separately.
9. Fill Collection to capacity and verify materialization fails without consuming progress.
10. Deliberately assign a Wild class as WorldActorClass and verify server rejection without progress loss.

## v0.6.4-alpha — Repeat-Safe Ability Input Buffer & Cooldown Recovery

Static/source validation was performed against the v0.6.3 ability-execution baseline. Unreal Engine/UnrealBuildTool are not installed in this environment, so a clean UE5.8.1 compile and host/client runtime test remain required.

Validated source contracts:
- Final gate covers **60 C++/header/build source files and 12,562 source/build lines**.
- Runtime code changes are restricted to `DMFDigimonCombatComponent.h/.cpp`; GameMode, PlayerController, wild character/spawner and polished UI runtime files are byte-identical to v0.6.3.
- Manual quick-slot input now buffers the latest valid ability command while combat state is Attacking/Recovering, cooldown is active, the Digimon is chasing into range, or combat-facing is still aligning.
- `ProcessQueuedCommand()` retains commands during transient recovery/cooldown instead of clearing them.
- `FinishRecovery()` immediately services buffered input after returning to Idle; if cooldown remains, the command remains buffered for the automation tick.
- The pending command is cleared only after successful `TryExecuteAbilityById()` or a permanent invalidation such as target loss, leash violation, timeout or insufficient SP.
- Positive-SP and zero-SP moves continue through the same authoritative execution function; SP deduction occurs exactly once when the move enters Attacking.
- Expired cooldown records are removed authoritatively and replicated away.
- Server cooldown validation/set/prune use server `World->GetTimeSeconds()` directly; remote HUD countdown uses synchronized `GameState->GetServerWorldTimeSeconds()`.
- v0.6.3 capsule edge-to-edge ability range and v0.6.2 facing gates remain present.
- 19 reflected RPC declarations still have matching `_Implementation` bodies.
- Generated-header include ordering passes and no TODO/FIXME runtime placeholders were added.

Required authoritative acceptance:
1. Clean compile in UE5.8.1.
2. With at least 20 SP, press slot 1 (5 SP) and confirm one execution lowers SP by exactly 5.
3. Press slot 1 again during the first move's recovery/cooldown; without another key press it must execute automatically once ready.
4. Repeat slot 1 several times against a durable target until SP is below 5; every successful use deducts exactly 5.
5. Confirm a 0-SP slot still works and can replace a currently buffered command (latest input wins).
6. Restore SP and confirm slot 1 becomes available again.
7. Repeat on host and remote client and verify matching SP/cooldown/montage/damage state.

## v0.6.2-alpha — Replicated Combat Target Facing

Static/source validation was performed against the user-confirmed working v0.6.1 late-join possession baseline. Unreal Engine/UnrealBuildTool are not installed in this environment, so a clean UE5.8.1 compile and host/remote-client runtime test remain required.

Validated source contracts:
- Final gate covers **60 C++/header/build source files and 12,409 source/build lines**.
- The only runtime C++ files changed from v0.6.1 are `DMFDigimonCharacter.h/.cpp` and `DMFDigimonCombatComponent.cpp`; the polished UI, late-join possession GameMode/PlayerController, wild spawner, persistence and healer source are unchanged.
- Shared target-facing API lives on `ADMFDigimonCharacter`, so partner and wild subclasses inherit the same implementation.
- Facing start/update is authority-gated; no client combat-rotation authority or additional rotation RPC was introduced.
- Actor yaw is distributed through existing replicated Character movement.
- `bRequireFacingBeforeAttack` is evaluated before SP/cooldown mutation and before attack presentation.
- Manual queued commands remain queued while the server turns in place; the command timeout still bounds the wait.
- Auto battle and passive retaliation use the same in-range facing gate.
- Chase/follow paths stop combat-facing before navigation movement so movement-driven yaw remains natural.
- CharacterMovement orientation flags are cached before target-facing and restored when facing stops/recovery ends.
- Defeat immediately clears combat-facing before the existing deterministic death-pose path.
- Generated-header ordering and lightweight source delimiter checks pass across all headers/sources.
- No new `USkeletalMeshComponent* Mesh` shadowing was introduced, preserving the UE5.8 C4458 correction.
- No `TODO`/`FIXME` runtime placeholders were added.

Required authoritative acceptance:
1. Clean compile in UE5.8.1.
2. Partner attacks from side/back: turn-in-place occurs before Montage starts.
3. Passive wild retaliation: wild Digimon turns toward the actual attacking partner before retaliating.
4. Host and remote client observe matching attack direction/yaw.
5. SP/cooldown remain unchanged while waiting for the facing tolerance.
6. Chase, follow, roaming, leash return, death-pose and v0.6.1 late-join possession regressions pass.

## v0.6.0-alpha — Polished Native MMO UI Suite

- Source baseline: v0.5.5-alpha Deterministic Death Pose + Passive Wild Retaliation.
- Critical combat/death/wild-spawner source files were byte-compared against v0.5.5 during packaging and remain unchanged.
- Native UMG API usage was checked against UE5.8 API surfaces for `UUniformGridPanel`, `UEditableTextBox`, `UScaleBox`, `UButton`, `UBorder` and `FSlateChildSize`.
- Generated-header include ordering, delimiter balance, version metadata, known UE5.8 warning-as-error shadowing patterns and archive integrity are checked by the release script.
- `UDMFSessionSubsystem::Logout()` changes local staged frontend state only; no server account persistence mutation was added.
- UE5.8.1 UnrealBuildTool compile and PIE/packaged multiplayer runtime remain the authoritative acceptance gates.
- Final v0.6.0 static gate covers **60 C++/header/build source files and 11,882 source/build lines**; 18 reflected network RPC declarations have matching `_Implementation` bodies.

## v0.5.5-alpha — deterministic defeat + passive-retaliation static validation

Built directly on the v0.5.4 compile-fixed baseline. Unreal Engine/UnrealBuildTool are not available in this environment, so a fresh UE5.8.1 compile and host/client PIE runtime test remain the authoritative acceptance gate.

Static/architecture checks for this layer verify:
- Death presentation binds both Montage blend-out and Montage-ended callbacks and retains the normalized-time fallback.
- The defeated lock pauses the active Death Montage, pauses skeletal animation evaluation and sets `GlobalAnimRateScale=0`; revive restores cached animation state.
- `MulticastDefeatedCue` no longer starts the durable death animation, eliminating the multicast-before-property replication race. Authority `SetCombatState` and client `OnRep_CombatState` are the sole durable animation triggers.
- `bAutoBattleEnabled` controls proactive `AcquireNearestHostile` behavior only. The passive branch never calls nearest-hostile acquisition.
- `ApplyAuthoritativeDamage` starts reactive combat only after nonlethal authoritative damage and only when retaliation is enabled. The concrete attacking Digimon becomes the retaliation target.
- Retaliation reuses existing target hostility/targetability, range, cooldown, basic-attack and leash validation; it ends when the target dies/becomes invalid or leaves the leash.
- Player-partner manual combat remains unaffected because retaliation defaults disabled in the shared combat component and is enabled by `ADMFWildDigimonCharacter`.
- Wild defaults are `Proactive Auto Battle=false` and `Retaliate When Attacked=true`. Spawner defaults independently mirror those policies.
- `bAutoBattle` and `bRetaliateWhenAttacked` are replicated on wild actors for consistent Blueprint/UI inspection, but combat decisions remain server-authoritative.
- No local `USkeletalMeshComponent* Mesh` declaration was reintroduced, preserving the v0.5.4 UE5.8 `C4458` fix.
- Generated-header include ordering, simple source delimiter balance and absence of TODO/FIXME runtime placeholders were rechecked.
- Release contains 59 C++/header/build source files and 10,373 source/build lines.

## v0.5.4-alpha — UE5.8 death-pose C4458 compiler-feedback validation

The supplied UE5.8.1 build log reaches and completes UnrealHeaderTool, then reports exactly three C++ diagnostics. All three are `C4458` in `DMFDigimonCharacter.cpp` where v0.5.3 introduced local variables named `Mesh`, hiding the inherited `ACharacter::Mesh` member.

Corrections verified statically:
- The three affected locals in defeated-presentation apply/hold/clear code are now named `DigimonMesh`; no local declaration named `Mesh` remains in `DMFDigimonCharacter.cpp`.
- No v0.5.3 defeated-state logic, montage timing, cached movement/collision restoration, replication hook, or wild corpse/despawn behavior was removed.
- A source-wide scan finds no remaining local `USkeletalMeshComponent* Mesh` declaration in the plugin.
- v0.5.1's incomplete-type `IsValid` correction remains present.
- A fresh UE5.8.1 compile remains required because UnrealBuildTool/UnrealEditor are not available in this environment.

## v0.5.3-alpha — Persistent defeated-partner presentation static validation

Built directly on v0.5.2. This environment does not contain Unreal Engine 5.8/UnrealBuildTool, so a fresh UE5.8.1 compile plus listen-host/remote-client runtime test remains the authoritative acceptance gate.

Static/architecture checks for this feature layer verify:
- `UDMFDigimonCombatComponent::SetCombatState` enters/clears the `ADMFDigimonCharacter` defeated presentation on the server, while `OnRep_CombatState` reconstructs the same state on clients.
- Reliable defeat multicast now calls the same idempotent presentation path instead of owning a separate one-shot montage implementation.
- The species `DeathMontage` is played once and the mesh is held near the configurable final normalized pose, preventing the AnimBP from returning a 0-HP partner to idle.
- `OnRep_DigimonState` retries defeated presentation if SpeciesId arrives after CombatState, covering late relevancy/join ordering without per-frame animation replication.
- Revive/reset clears the held montage state and restores cached movement mode/capsule collision. Recall still destroys the spawned partner actor normally.
- Wild spawner source is byte-identical to v0.5.2; its defeated corpse timer/despawn behavior is not changed by this release.
- Release contains 59 C++/header/build source files and 10,041 source/build lines.
- `ADMFPlayerAvatarCharacter` exposes the native `Interact` entry point plus generic Actor-taking Digimon/healer convenience wrappers, so normal Blueprint targeting/healing does not require project casts.
- The ready-to-use `E` interaction binding is independent from `bEnableNativeThirdPersonInput`; projects using Enhanced Input can disable only the native interaction binding and call the same `Interact` implementation.
- Interaction distance, sweep radius, trace channel, complex trace, active-partner ignore, debug trace, optional attack-on-interact and attack slot are Blueprint-editable on the player class.
- `FindInteractionTarget` ignores the player pawn and can ignore the summoned active partner; it traces from the framework follow camera and supports line trace (`SweepRadius=0`) or sphere sweep.
- Digimon target-only and target+attack wrappers perform local actor/type/partner/hostility prechecks but still route through `DMFMMOPlayerController` and the existing server RPC path; they do not apply damage locally.
- Default Digimon interaction remains target-only (`bAttackOnDigimonInteract=false`), preserving the v0.5.0 manual-partner-combat requirement.
- Healer interaction still routes through the client-owned PlayerController and server-side healer validation.
- `ADMFHealerActor` now owns a query-only `USphereComponent` with Blueprint-exposed collision radius and trace channel, separate from the authoritative use radius; this removes project collision setup as a prerequisite without creating a large mandatory Visibility blocker.
- Legacy click-target and 1–4 ability input are now independently exposed; click target defaults off and ability-slot keys default on, matching the new `E` target + 1–4 attack control contract.
- `EDMFPlayerInteractionType`, `OnInteractionResult`, `BP_OnDigimonInteracted` and `BP_OnUnhandledInteraction` are presentation/extension hooks and do not mutate authoritative combat or persistence state.
- The v0.5.1 incomplete-type `IsValid` correction remains in place; `IsActivePartnerSummoned()` remains declaration-only in the header with its implementation in the `.cpp`.
- The v0.4.1 wild-spawner source/placement fix, rarity, roaming/leash, ground transition and v0.3.3 Custom Depth contracts remain present.

Required runtime acceptance is documented in `TEST_PLAN.md`, `SETUP_PLAYER_INTERACTION_SYSTEM.md`, and `SETUP_DEFEATED_PARTNER_PRESENTATION.md`.

## v0.5.1-alpha — UE5.8 compiler-feedback maintenance validation

The supplied UE5.8.1 build log reaches UnrealHeaderTool successfully and then reports eight `C2664` failures. Every reported compiler error points to the same inline expression in `DMFPlayerDigimonComponent.h`: `IsValid(ActivePartnerActor.Get())`. At that public-header point `ADMFDigimonCharacter` is forward-declared, so MSVC cannot perform the incomplete derived-pointer to `UObject*` conversion required by `IsValid`.

Corrections verified statically:
- `IsActivePartnerSummoned()` is declaration-only in the public header.
- Its definition lives in `DMFPlayerDigimonComponent.cpp` after `Game/DMFDigimonCharacter.h` is included, so the class inheritance is complete before calling Unreal `IsValid()`.
- The fix preserves pending-kill / invalid-UObject semantics rather than reducing the check to raw pointer non-nullness.
- No v0.5.0 gameplay, replication, persistence, UI, healer, balance, manual combat or v0.4.1 spawner behavior is intentionally altered.
- A fresh UE5.8.1 compile is required to expose any next compiler-feedback layer that may have been masked by this shared-header failure.

## v0.5.0-alpha — Manual partner combat, battle tuning, healer and roster UI static validation

Built directly on the user-tested v0.4.1 wild-spawner baseline. This environment does not contain Unreal Engine 5.8/UnrealBuildTool, so the user's clean UE5.8.1 compile and multiplayer runtime test remain the authoritative acceptance gate.

Static/architecture checks for this feature layer verify:
- Release contains 59 C++/header/build source files and 9,294 source lines.
- Owned partner auto battle is disabled by default through `bPlayerPartnerAutoBattle=false`; manual command processing remains server-authoritative and manual partners continue following their player while autonomous target acquisition is disabled.
- `CommandPartnerTargetAndAttack` routes target + zero-based ability slot through the existing owning-PlayerState server command path, preserving hostility, range, SP, cooldown, queue-timeout and leash validation.
- Player-partner battle-role multipliers are configured server-side at spawn (default outgoing 1.50, incoming 0.50) without rewriting saved Species/Instance stats. Ordinary wild Digimon expose independent Blueprint-editable outgoing/incoming multipliers defaulting to 1.0/1.0.
- Damage tuning is applied only inside the authoritative damage calculation; no client-supplied damage value is trusted.
- `UDMFDigimonInventoryWidget` follows the v0.3.2-corrected native UMG lifecycle by building its fallback tree in `RebuildWidget()`, and is reskinnable through a Blueprint child plus optional BindWidget names.
- The native roster exposes owner-only replicated active-inventory data and server-routed set-active/summon/recall actions. Defeated Digimon are blocked from summoning until restored.
- `ADMFMMOPlayerController` exposes Open/Close/Toggle/Refresh roster UI calls and an optional default `I` binding; mandatory skin/starter onboarding retains priority over the roster menu.
- `ADMFHealerActor` is Blueprintable, replicated and fully Details-tunable for range, reuse, HP/SP restore, defeated revival, bank inclusion, active-partner resummon and UI text.
- Healer interaction enters through the owning PlayerController RPC and is revalidated by the server for actor validity, enabled state, player pawn, distance and reuse timing. The healer never trusts a client HP/SP mutation.
- Healing can restore the active replicated roster plus persistent bank records, updates the live partner combat component, clears stale combat targeting, persists immediately and exposes server/cosmetic Blueprint hooks. No currency deduction exists; the healer is free by design.
- Active-partner actor replication now refreshes the roster UI so summon/recall state is not dependent on replication order.
- Existing v0.4.1 wild-spawner source is unchanged by this release; proximity spawning, rarity, capsule-aware placement, roaming/leash and ground emergence/despawn remain intact.
- Existing Custom Depth enforcement, login/authentication, player skins, starter onboarding and account persistence contracts were not intentionally weakened.
- Generated-header include ordering, lightweight delimiter balance, RPC `_Implementation` coverage, obsolete PrimaryAsset include regression, and source TODO/FIXME scans are included in the release gate.

Required Editor/runtime acceptance tests are documented in `TEST_PLAN.md` and `SETUP_MANUAL_COMBAT_HEALER_INVENTORY.md`.

## v0.4.1-alpha — Wild spawner placement fix static validation

Built directly on the user's UE5.8.1-compiled v0.3.3 lineage. This environment does not contain UnrealBuildTool/UnrealEditor, so a fresh UE5.8.1 compile and multiplayer runtime test remain required before promoting v0.4.1 to the authoritative accepted baseline.

Static/architecture checks for this feature layer verify:
- New `ADMFWildDigimonSpawner` is Blueprintable and all spawn/activation/population/rarity/placement/emergence/AI/roam tuning is exposed through Details/Blueprint properties.
- Proximity, population, species/rarity/level selection, spawn placement, respawn scheduling and despawn execute only under `HasAuthority()`.
- Spawner replication is limited to compact runtime state; the spawned wild Characters remain the normal replicated gameplay actors.
- Weighted rarity tiers plus per-entry multipliers and live caps are evaluated only on the authority, and finite table capacity clamps impossible population targets.
- Spawn placement uses uniform disk sampling, bounded attempts, terrain trace, optional NavigationSystem projection, player separation and collision-aware deferred spawn.
- Deferred spawn parameters are assigned before Blueprint construction/BeginPlay, preventing a transient wrong Species/Level/AI configuration.
- Wild free roaming is timer-driven, uses reachable NavMesh points, and is bounded by the individual SpawnHomeLocation/RoamRadius. Existing combat automation retains the individual spawn location as its authoritative leash home.
- Ground emergence/despawn is synchronized from a compact replicated timing struct and server world time rather than per-frame replicated mesh transforms.
- Wild movement, targetability and capsule collision are suppressed during the ground transition and restored after emergence.
- Ground transition carries a rarity snapshot to prevent replication-order races in Blueprint cosmetic hooks.
- Managed defeat immediately removes the actor from alive population accounting, leaves configurable corpse presentation time, and creates a delayed replacement token.
- Deactivation clears replacement work and marks actors suppress-respawn before optional synchronized ground-sink destruction.
- Deactivation does not mutate the managed-record array while iterating it; actor destruction is performed in a second pass because `OnDestroyed` callbacks can run synchronously.
- Existing manually placed `ADMFWildDigimonCharacter` behavior is preserved by keeping free roaming opt-in unless configured by the spawner.
- Existing login/account/player-skin/starter/persistence/combat/native UI/Custom Depth contracts were not intentionally changed.
- `NavigationSystem` is declared as a runtime module dependency.

Required acceptance gates are documented in `TEST_PLAN.md` and `SETUP_WILD_DIGIMON_SPAWNER.md`.

## v0.3.3-alpha — Always-on Custom Depth static validation

Built directly on the user's runtime-tested v0.3.2 UI baseline. This environment still has no Unreal Engine 5.8/UnrealBuildTool, so a clean UE5.8.1 compile and runtime test remain the authoritative acceptance gate.

Static checks verify:
- `ADMFPlayerAvatarCharacter` forces Custom Depth on the inherited mesh at construction defaults and reasserts it during OnConstruction, BeginPlay and every data-driven skin application.
- `ADMFDigimonCharacter` forces Custom Depth on the inherited mesh and reasserts it during OnConstruction, BeginPlay, server instance initialization and client replicated-state refresh.
- Both bases scan all owned `UMeshComponent` instances, covering skeletal and static mesh components added by derived Blueprints.
- Both bases expose `RefreshFrameworkCustomDepth()` for runtime-created/replaced mesh components and a clamped Blueprint-editable stencil value.
- No replicated property or save-schema field was added for Custom Depth; render state remains local presentation with no additional network bandwidth.
- No authentication, account, skin authority, starter, inventory, combat or persistence contracts were intentionally modified.

## v0.3.1-alpha — UE5.8 compiler-feedback maintenance validation

The supplied UE5.8.1 build successfully passes UnrealHeaderTool and compiles the new avatar/skin source far enough to expose two root compatibility issues: seven `C4458` local-name collisions in `ADMFMMOPlayerController`, plus a UHT-normalized BlueprintImplementableEvent signature mismatch for `BP_OnPlayerSkinSelectionResult`. The generated `C2511`/`C2352` diagnostics are downstream of the latter.

### Corrections verified statically

- No local declaration matching `ADMFPlayerState* PlayerState = GetPlayerState<ADMFPlayerState>()` remains in `DMFMMOPlayerController.cpp`.
- All seven affected controller paths now use `DMFPlayerState` while preserving the same component accesses and RPC calls.
- `BP_OnPlayerSkinSelectionResult` is declared as `bool, const FText&, UDMFPlayerSkinData*`, matching the UE5.8 UHT-generated signature shown in the user's build log.
- Previous v0.2.1 Primary Asset include and v0.2.2 `TObjectPtr`/starter-RPC corrections remain intact.
- No gameplay/replication/persistence behavior was intentionally altered.

### Required acceptance gate

Replace v0.3.0 with v0.3.1, delete plugin `Binaries` + `Intermediate` (and project `Intermediate` if practical), regenerate project files, and perform a clean UE5.8.1 Editor compile. Any newly exposed diagnostics should be treated as the next compiler-feedback layer rather than inferred from this build.

## v0.3.0-alpha — Player avatar / character skin framework static validation

The v0.2.2 baseline was confirmed by the user to compile successfully in UE5.8.1. v0.3.0 extends that accepted source with the player-avatar/skin system and therefore requires a new UE5.8.1 compile before this release can be called Editor-accepted. UnrealBuildTool/UnrealEditor are still unavailable in this build environment.

### Static / architecture checks completed

- Plugin descriptor parses as JSON and reports `0.3.0-alpha`.
- Release contains 51 C++/header/build source files and 6,114 source lines.
- Generated-header include ordering checked across every public header.
- Delimiter/brace balance checked across framework C++ source.
- No `TODO`/`FIXME` placeholders exist in runtime source.
- Obsolete `Engine/PrimaryAssetId.h` include remains absent.
- Historical v0.3.0 check: at that release point, the requested admin passphrase plaintext and then-fixed MMO hostname plaintext were absent from source/docs/config literals. **Superseded in v0.10.2/v0.10.3:** the server endpoint is intentionally project-configurable, and the Admin passphrase is now set through Project Settings while remaining digest-only at rest.
- `DMFPlayerSkin` Asset Manager registration is present beside species, starter roster and ability entries with `AlwaysCook`.
- `ADMFMMOGameMode` defaults to `ADMFPlayerAvatarCharacter` while still permitting a project Blueprint subclass as `DefaultPawnClass`.
- `ADMFPlayerState` owns both `UDMFPlayerAvatarComponent` and `UDMFPlayerDigimonComponent`; skin RPC authority does not depend on a client-owned arbitrary mesh actor.
- Skin client requests contain only a `FPrimaryAssetId`; server-side resolution verifies the registered `DMFPlayerSkin`, enabled state and assigned skeletal mesh before mutation.
- Accepted `SelectedPlayerSkinId` replicates to all clients; private onboarding-required state is owner-only.
- Runtime skin switching never respawns/repossesses the human pawn and therefore does not intentionally disturb location, controller, Digimon inventory, active partner or combat ownership.
- Skin persistence mutates only the avatar field on the loaded account record, avoiding accidental cross-component overwrites during account initialization.
- Existing account SaveGame schema is advanced to v2 in memory; old v0.2.x records naturally deserialize with an empty skin ID and follow the configured onboarding policy.
- Native modal UI input locking is stack-balanced so repeated refresh callbacks do not accumulate `SetIgnoreMoveInput`/`SetIgnoreLookInput` locks.
- Native third-person held-input state is cleared before modal character/starter UI takes focus, preventing stuck WASD/sprint state when UI mode consumes key-release events.
- Sprint state uses an authoritative reliable server RPC plus replicated state rather than trusting a client-only `MaxWalkSpeed` mutation.
- Skin selector discovers enabled `DMFPlayerSkinData` assets through Asset Manager rather than a manually maintained roster array.
- UE5.8 `GetPrimaryAssetIdList` calls pass `EAssetManagerFilter::Default` explicitly in both runtime skin discovery paths.

### Required UE5.8.1 acceptance gates

1. Replace v0.2.2 with v0.3.0 and perform a clean UnrealHeaderTool/C++ compile.
2. Verify `DMFPlayerSkin` appears in Asset Manager after merging the updated config snippet.
3. Create at least two skin Data Assets and verify first-time selection -> server acceptance -> replicated appearance.
4. Run host + second client and verify each player sees the other's selected skin and a runtime switch propagates without pawn replacement.
5. Verify reconnect/server restart restores the accepted skin.
6. Re-run the v0.2.2 login/starter/partner/combat regression tests.
7. Package on two PCs and confirm all skin Primary Assets, meshes and Animation Blueprints cook/resolve.

## v0.2.2-alpha — UE5.8 compiler-feedback maintenance pass

The supplied UE5.8.1 build advances beyond the v0.2.1 Primary Asset include correction and exposes the next compiler layer. The source errors are three `C2445` raw-pointer/`TObjectPtr<ADMFDigimonCharacter>` conditional ambiguities and one `ClientStarterSelectionResult` RPC signature mismatch. The generated `C2511`/`C2352` diagnostics are downstream of that RPC mismatch.

The three pointer fallbacks now explicitly call `.Get()` on replicated `TObjectPtr` targets. The RPC declaration and `_Implementation` are normalized to `bool`, `const FText&`, `FGuid`, matching the signature emitted by UE5.8 UHT. No gameplay authority, combat math, persistence schema or starter-selection semantics were intentionally changed.

This environment still does not contain UE5.8/UnrealBuildTool, so the authoritative next validation step remains a clean Editor rebuild in the consuming project.

## v0.2.0-alpha source/architecture validation scope

## Scope

This release candidate received source-level validation in the build workspace. An Unreal Engine 5.8 installation, UnrealBuildTool and UnrealEditor are not available in this environment, so this report does **not** claim a completed UE compile/package run.

## Static / architecture checks completed

- Historical v0.2.2 validation: plugin descriptor parsed as JSON and reported `0.2.2-alpha`.
- Static release audit covers 42 C++/header/build source files (4,643 source lines in this candidate).
- UE generated-header include ordering checked across framework public headers.
- Delimiter/brace balance checked across framework C++ headers/source.
- No TODO/FIXME placeholders were introduced in release source.
- Requested admin passphrase plaintext remains absent from persistent framework configuration; v0.10.3 persists only its one-way comparison digest after the editor password setter is used.
- Historical v0.2.x check: the fixed MMO hostname was reconstructed at runtime. **Superseded in v0.10.2:** the endpoint is intentionally exposed as validated project deployment configuration under `Networking → Server Endpoint`.
- Existing v0.1.0 account, starter, Fast Array inventory, active-partner and persistence contracts are preserved.
- `DMFDigimonAbility`, `DMFDigimonSpecies` and `DMFStarterRoster` all have project Asset Manager `AlwaysCook` scan entries.
- Combat component is a static replicated actor component owned by a replicated Digimon actor.
- Client combat commands enter through the owning PlayerState component; damage/SP/cooldowns are never accepted as client-authored values.
- Ability slot, target hostility, target validity, SP, cooldown and range are validated server-side.
- Out-of-range player commands are queued server-side, timeout/leash-limited, chased and revalidated before execution.
- Combat targets outside the configured leash are dropped before new AI chase orders are issued.
- Ability impact rechecks target/range at impact time to prevent delayed-hit range exploits.
- Combat cooldown end times replicate using synchronized `AGameStateBase::GetServerWorldTimeSeconds` semantics.
- Autonomous target search is interval-based and bounded by a pawn overlap, not an every-frame world actor scan.
- Attack/win/death animation/VFX/audio cues are cosmetic; replicated combat state remains authoritative.
- Active-partner HP/SP is mirrored back into the persistent Digimon instance only when values change, reducing avoidable owner-only Fast Array dirties; account autosave is interval based.
- Active-partner defeat persists immediately rather than waiting for the periodic autosave boundary.
- Defeat rewards are issued once from authoritative defeat transition and persisted immediately; listen-host reward presentation uses one owning-client event path to prevent duplicate UI callbacks.
- Wild/NPC and player-owned Digimon share the same combat component and team relation logic.
- Native fallback ability buttons bind explicitly after their slot/owner assignment, and framework Digimon capsules block Visibility traces for out-of-box target selection.

## Required UE5.8 acceptance gates

Run every section of `TEST_PLAN.md` after copying the plugin into the target project. This release should become the accepted baseline only after:

1. UnrealHeaderTool + C++ compilation succeeds with UE5.8.
2. v0.1.0 frontend/login/starter regression passes.
3. Two-client partner/wild combat replication passes.
4. Server command queue, chase, cooldown, SP and range anti-spam tests pass.
5. Attack1/Attack2 montage + Cascade/Niagara presentation is visible on host/client while damage stays authoritative.
6. Victory/death, EXP/money and reconnect persistence pass.
7. A clean packaged build resolves/cooks species, starter roster and ability Primary Assets.
8. Two separate PCs pass fixed-host networking and combat replication.

## Security / scale boundary

The current account gate remains suitable for private/development hosting, not public MMO authentication. Public deployment still requires a TLS-backed authentication/session-ticket service and transactional persistence provider.

Combat is structured for later scale hardening: bounded interval acquisition, actor relevancy, state replication and owner-routed commands. Large production shards will still require Replication Graph/Iris/relevancy profiling and encounter partitioning rather than globally relevant Digimon actors.

## v0.2.1-alpha — UE5.8.1 compiler-log correction

The supplied UE5.8.1 UnrealBuildTool log showed UnrealHeaderTool completing successfully before C++ compilation failed on the same obsolete include path across multiple translation units: `Engine/PrimaryAssetId.h`. UE5.8 documents `FPrimaryAssetId` in `UObject/PrimaryAssetId.h`.

This maintenance release replaces all three obsolete include occurrences in the framework source tree. Static archive validation confirms the old include path is absent and the documented UE5.8 include path is present. This environment still cannot execute UnrealBuildTool, so the next authoritative validation step is a clean UE5.8 Editor rebuild.

## 0.3.2 native UI bootstrap validation
- Moved all four native fallback UI tree creation paths from post-Slate `NativeConstruct()` timing to pre-Slate `RebuildWidget()` timing.
- Frontend HUD now retries until a local PlayerController is available and prevents duplicate widget insertion.
- Source scan confirms no DMF native fallback widget still invokes its fallback builder from `NativeConstruct()`.
- Runtime UE5.8.1 Editor verification is still required after installing this maintenance build.

### v0.4.1 focused checks
- `FindSpawnTransform` now receives the selected spawn-entry index.
- Selected Wild Blueprint class default capsule half-height is resolved before final Z placement.
- Ground/NavMesh point is converted to Character-origin Z by adding capsule half-height plus the designer's small `SpawnGroundOffset`.
- Spawn collision handling remains `AdjustIfPossibleButDontSpawnIfColliding`; the fix removes the systematic terrain overlap instead of weakening collision safety.
- Added authority-side diagnostic logs for activation, eligibility failure, placement failure and successful spawn.

## v0.5.3 static checks
- Persistent defeated presentation is driven from `SetCombatState` and `OnRep_CombatState`.
- Reliable defeat multicast calls the same idempotent presentation path.
- Species replication fallback re-applies presentation if the death montage was not resolvable on the first state notification.
- Revive path exits defeated presentation through the existing authoritative combat-state transition.
- Wild spawner source is unchanged by this release.

- v0.5.5 static check: death pose uses Montage blend-out/end delegates plus a fallback timer; lock pauses Montage and skeletal evaluation and restore path caches/restores prior mesh animation state.

- v0.5.5 proactive/retaliation static check: `bAutoBattleEnabled` controls nearest-hostile acquisition only; separate retaliation state is established only from authoritative applied damage when retaliation is enabled.
- Passive retaliation does not call `AcquireNearestHostile`; it only attacks the concrete hostile Digimon that damaged the wild actor and uses existing leash/range/cooldown validation.
- Spawner policy is independent: `Allow Proactive Auto Battle` defaults false and `Allow Retaliation When Attacked` defaults true.
- Runtime setters refresh server policy without changing player-partner manual combat behavior.

- Defeat replication-order check: `MulticastDefeatedCue` no longer calls `ApplyDefeatedPresentation`; durable death animation begins only from authoritative/replicated `CombatState=Defeated`, preventing pre-state client Montage lock rejection.


### v0.6.2 combat-facing static contract
- Shared target-facing API lives on `ADMFDigimonCharacter`, so partner/wild subclasses inherit one implementation.
- Authority guard is present on start/update facing paths.
- `bRequireFacingBeforeAttack` gates ability execution before SP/cooldown mutation.
- Queued manual commands remain pending while turning.
- Automation and retaliation use the same in-range facing gate.
- Movement orientation flags are cached/restored, and chase/follow paths stop combat-facing before issuing navigation moves.
- No new replicated property/RPC is required; actor rotation uses existing replicated movement.


## v0.6.4 ability execution reliability static contract

- Ability range helper is capsule edge-to-edge and 2D/horizontal.
- Queue, direct validation, impact validation, and automation use the same range helper.
- Ability chase acceptance includes both capsule radii and uses `bStopOnOverlap=false`.
- Positive and zero SP costs use the same normalized effective-cost helper.
- SP deduction remains after target/range/cooldown/facing gates.
- Combat-facing temporarily suppresses controller yaw and synchronizes AI control rotation with authoritative actor yaw.
- Existing server RPC ownership/authority model remains unchanged.


### v0.6.4 final static gate
- Source/build files checked: **60**
- Source/build lines checked: **12,474**
- Generated-header include ordering: clean.
- Changed C++ delimiter balance: clean.
- Capsule-aware range helper is used for validate, queue, impact and automation paths.
- Ability chase uses capsule-aware acceptance and `bStopOnOverlap=false`.
- Positive-SP deduction occurs only in the final authoritative execution path.
- No new combat RPCs were introduced; existing ownership/authority path is preserved.
- UE5.8.1 compilation and runtime host/client testing remain the authoritative acceptance gates.

## v0.14.0-alpha DigiDex validation
- DigiDex tab enum was appended after all existing serialized menu values; no historical value was reordered.
- DigiDex species data comes from the existing `DMFDigimonSpecies` Asset Manager registry; no duplicate persistence model was introduced.
- DigiDex has no mutation button/API path and adds no RPC/replicated state. Owner discovery badges reuse existing owner-only Party/Bank/Scan data.
- Native portraits use fixed viewports with aspect-preserving ScaleBox presentation. Search and Stage/Attribute filters rebuild only local UI.
- Final source/API/archive counts are recorded at packaging time below.
## v0.14.1-alpha projectile / VFX lifecycle validation
- `EDMFAbilityExecutionMode` is additive and defaults to `TimedImpact`, preserving existing authored ability behavior.
- Projectile mode routes the accepted cast into `SpawnAuthoritativeProjectile`; no client RPC or Blueprint path can author damage, hit position or projectile target authority.
- `ADMFAbilityProjectileActor` is replicated with replicated movement and minimal definition state. Authority alone updates homing/travel and segment-based target arrival.
- Projectile launch rotation is derived from launch point to target; `ProjectileVisualRotationOffset` affects only the child visual root.
- Projectile arrival calls back into the existing combat component for authoritative damage math/defeat/reward handling.
- The old timed-impact range recheck remains for Timed Impact. Projectile arrival deliberately uses physical arrival instead of a second cast-range check.
- `ProjectileMaxLifetimeSeconds` destroys the actor and every attached projectile visual even when VFX loop indefinitely.
- Timed attack VFX and projectile impact VFX each use forced cleanup timers with weak component references; already-auto-destroyed effects are safely ignored.
- Niagara-preferred/Cascade-fallback behavior is retained; legacy species Attack1/Attack2 particles remain valid migration fallbacks.
- Dedicated servers skip the new cosmetic rendering paths while retaining projectile authority.
- Static baseline comparison: zero v0.14.0 files removed, zero existing reflected UFUNCTION names removed, and all 42 RPC declarations have matching implementations.
- UnrealBuildTool/PIE execution is not available in this environment; UE5.8.x Editor compile plus host/remote-client projectile tests remain the authoritative runtime gate.


## v0.14.2-alpha — polished owner-only combat targeting visuals source validation

Static/source validation was performed against the user-runtime-validated v0.14.1 replicated-projectile baseline. Unreal Engine/UnrealBuildTool is not installed in the assembly environment, so a clean UE5.8 compile plus listen-host/multi-client runtime test remain the authoritative acceptance gates.

Validated contracts:
- Added the local-only `ADMFTargetingPresentationActor` source pair. `bReplicates=false`; the actor is spawned only for the locally controlled framework PlayerController and renders no dedicated-server presentation.
- Active-partner presentation consumes the existing owner-only `ActivePartnerActor`; enemy selection presentation consumes the existing owner-only `CommandTarget`. No marker-selection replication channel was added.
- PaperSprite partner/enemy rings use separate scene pivots for clean world-Z rotation while the sprite receives a configurable flat-floor orientation. Default speeds are intentionally distinct/opposed at `+28` and `-42` degrees/second.
- Optional capsule-radius scaling is clamped by configurable min/max values so the same global art remains usable across small Fresh and large late-stage Digimon.
- Enemy arrow uses Niagara-preferred/Cascade-fallback selection, target-capsule-top placement, scale/rotation correction and optional native sinusoidal vertical hover.
- Ring/particle primitives use owner-only rendering hardening in addition to the non-replicated actor boundary, so network clients do not receive or render one another's marker actor/state.
- Defeated/cleared targets deactivate the hostile ring/arrow, and recalled/replaced partners remove/reposition the blue active-partner ring without modifying combat state.
- Project Settings exposes the complete targeting presentation asset/tuning surface; Paper2D is now an explicit runtime plugin/module dependency because the requested ring assets are native PaperSprite assets.
- Existing v0.14.1 projectile execution/homing/impact/cleanup, DigiDex, Digivolution, Party/Bank, Care/healer, nameplates/chat, camera/music/footsteps, accounts and frontend contracts remain additive and unchanged.
- Final static regression gate covers **80 source/header/build files and 23,752 source/build lines**, with **42 UCLASS**, **15 UENUM**, **16 USTRUCT**, **422 UFUNCTION** and **769 UPROPERTY** declarations.
- All **42 reflected Server/Client/NetMulticast RPC declarations** still have matching `_Implementation` bodies. Targeting visuals add **zero new RPCs**.
- Comparison against v0.14.1 finds **zero baseline files removed** and **zero existing reflected UFUNCTION names removed**. Added reflected APIs are limited to `RefreshTargetingVisuals`, `GetTargetingPresentationActor`, `RefreshPresentationAssets`, `GetPresentedActivePartner`, and `GetPresentedCommandTarget`.
- Generated-header ordering, changed-source delimiter balance and runtime TODO/FIXME checks pass.

Required runtime acceptance: clean UE5.8 compile, then run `TEST_PLAN.md` section **T0** with listen host + two remote clients and packaged clients, followed by the v0.14.1 projectile/homing regression and existing combat/Party/Care/Scan/Digivolution/DigiDex regressions.


## v0.14.7-alpha — wild / auto-battle full moveset source validation

Static/source validation was performed against the user-runtime-validated v0.14.6 CustomDepth baseline. Unreal Engine/UnrealBuildTool is not installed in the assembly environment, so a clean UE5.8 compile plus host/remote-client runtime test remains the authoritative acceptance gate.

Validated contracts:
- Root cause confirmed in `UDMFDigimonCombatComponent::AutomationTick`: autonomous combat resolved `ResolveBasicAttackId()` and executed only that one ability. Other runtime equipped ability IDs were not considered by the AI decision path.
- Autonomous selection now reads the complete runtime `ReplicatedAbilityIds` set and retains Basic Auto Attack only as a compatibility fallback.
- `bEligibleForAutoBattle=false`, insufficient SP, active cooldown or invalid hostile target remove an ability from the current candidate pool before selection.
- Least-recently-used server-only use serials prefer untouched/oldest usable moves, with randomization only between equal-age candidates. This removes fixed slot-order bias while ensuring current usable abilities are exercised before recently used moves are preferred again.
- A server-only pending ability ID remains stable while AI chases into that selected move's capsule-aware range; mixed melee/ranged moves therefore do not thrash `MoveToActor` acceptance radii every automation interval.
- Rotation state resets on authoritative target change, reset/heal combat teardown, defeat and victory. It is not a UPROPERTY, is not saved and is never client-authored.
- Actual execution still calls `TryExecuteAbilityById`, preserving the existing authoritative SP deduction, cooldown mutation, facing/range checks, timed/projectile impact, damage, defeat and replication/cosmetic cue contracts.
- Manual queued commands remain processed before autonomous decisions. Player-owned partner auto battle is still disabled by default.
- No RPC, replicated gameplay property, SaveGame field or serialized enum is added by this release.
- v0.14.6 CustomDepth presentation, v0.14.5 spawn rarity normalization and v0.14.4 battle encounter music logic are untouched.

Final static regression gate: **80 source/header/build files** and **24054 source/build lines** checked, with **42 UCLASS**, **15 UENUM**, **16 USTRUCT**, **423 UFUNCTION**, **770 UPROPERTY** and **42 reflected RPC declarations**. Comparison against v0.14.6 finds **zero baseline files removed**, **zero existing reflected UFUNCTION names removed**, and all reflected RPC declarations still have matching `_Implementation` bodies. Plugin JSON, generated-header include ordering and changed C++ delimiter balance pass.

## v0.14.9 candidate static validation

Candidate adds one new stat enum, one server spend RPC, one owner-only result RPC, one Blueprint-pure eligibility query and native Party/Bank button handlers. No existing serialized enum values are reordered, no persistent fields are added, SaveGame schema remains v5, and the menu layout change is presentation-only.

The revised Party layout fixes the final short-viewport overflow path identified during user runtime inspection: the Party identity/portrait header stays outside the scroll lane, while one bounded `PartyDetailsBodyScroll` contains stats, EXP, Attribute Point controls, description and all three Party action buttons. The prior inner description ScrollBox is removed, avoiding nested wheel/gamepad scroll capture. Bank/Scan/DigiDex/Digivolution/Care layout paths are unchanged.

Baseline-to-candidate static diff from accepted v0.14.8: **120 -> 121 files** (only `SETUP_ATTRIBUTE_POINTS.md` added), **83 source/header/build files preserved**, **434 -> 450 UFUNCTION declarations** with zero removals, **43 -> 45 RPCs** with zero removals and every RPC matched to an `_Implementation`, and **802 -> 815 UPROPERTY declarations** with no baseline property name removed. Changed C++ delimiter counts are balanced, generated-header include ordering is valid, plugin JSON parses, and no TODO/FIXME marker was introduced in the changed runtime files. Runtime UE5.8 host/client acceptance remains required.

## v0.15.0 candidate static validation — layered frontend background bootstrap

Source review against the runtime-accepted v0.14.9 Party-scroll/Attribute Point baseline confirms the frontend change is local presentation/bootstrap only. `ADMFFrontendHUD` now owns a one-shot configurable startup-delay timer separately from the existing PlayerController/widget retry timer, and uses the configured frontend viewport Z-order instead of a hardcoded value. `UDMFLoginMainMenuWidget` no longer creates the native full-screen backdrop unless explicitly enabled; the fallback root and optional decorative backdrop use `SelfHitTestInvisible`, preserving child login control input while allowing project-owned background presentation through empty screen space.

No RPC, replicated property, SaveGame field, serialized gameplay enum or trusted client mutation path is introduced. Login/session state, endpoint validation, Admin hosting gate, listen travel and server authentication code are untouched.

Final static regression gate against accepted v0.14.9: **121 -> 122 packaged files** (only `SETUP_FRONTEND_BACKGROUND_PRESENTATION.md` added), **83 source/header/build files preserved**, **25,435 source/build lines**, **43 UCLASS**, **16 UENUM**, **17 USTRUCT**, **450 UFUNCTION** and **815 -> 819 UPROPERTY** declarations. All **45 reflected RPC declarations** remain unchanged and have matching `_Implementation` bodies. Zero baseline files, reflected UFUNCTION names or RPCs were removed; generated-header ordering, changed C++ delimiter balance and plugin JSON validation pass. UE5.8 Editor compile plus PIE/Standalone/packaged frontend presentation testing remain the authoritative runtime acceptance gate.


## v0.15.0 revised candidate static validation — project-selectable frontend background layering

The earlier map/Level-Blueprint sequencing candidate is superseded by this revision. The framework now owns both local frontend layers. `FrontendBackgroundWidgetClass` is the only new project-facing class selector; `ADMFFrontendHUD` creates it first, inserts it into the **same game viewport layer** as the login widget, and derives its Z-order as `FrontendUIViewportZOrder - 100`. The login widget also uses `AddToViewport`, eliminating the cross-layer `AddToPlayerScreen` vs `AddToViewport` ordering ambiguity that allowed a fullscreen project background to cover the login card despite a higher numeric login Z-order.

The configured reveal delay starts only after background initialization. Local-PlayerController acquisition keeps its independent 0.10 s retry. Background creation/add failure is non-fatal and cannot block the login flow. Background + login widgets and all three bootstrap timers are cleaned on frontend EndPlay/travel.

Final static regression gate against the runtime-accepted v0.14.9 baseline: **121 -> 122 packaged files**, **83 source/header/build files preserved**, **25,339 -> 25,588 source/build lines**, **43 UCLASS**, **16 UENUM**, **17 USTRUCT**, **450 UFUNCTION** declarations, and **815 -> 821 UPROPERTY** declarations. The six-property delta consists of the five v0.15.0 local frontend presentation properties versus v0.14.9 plus the transient HUD-owned background widget reference; no persistent gameplay property was added. All **45 RPC declarations** are unchanged, no existing reflected UFUNCTION or RPC name was removed, generated-header include ordering passes, changed C++ braces/parentheses are balanced, and the plugin descriptor remains valid JSON.

No replicated property, RPC, SaveGame field, serialized gameplay enum, credential/authentication path, hosting permission path or gameplay authority contract is changed. UE5.8 Editor compile and PIE/Standalone/packaged frontend tests remain the authoritative runtime acceptance gate.
