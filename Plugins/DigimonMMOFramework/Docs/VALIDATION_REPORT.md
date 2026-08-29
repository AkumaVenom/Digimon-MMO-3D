# v0.18.2-alpha validation summary

Candidate: **Authenticated Reconnect Persistent Account Authority Fix**  
Baseline: accepted **v0.18.0-alpha_ReplicatedDigimonVendorEconomyRotatingStockUI_UE58CompileFix**, with the v0.18.1 disconnect-save/partner-cleanup corrections retained and hardened.

## Root cause addressed

The observed Shipping behavior — remote account empty only when reconnecting to the still-running host, but correct after host restart — proves the durable save record survives. The remaining failure is transient `AGameMode` inactive-PlayerState reassociation. v0.18.2 disables that transient cache for DMF and makes authenticated server persistence the sole reconnect authority.

## Static validation performed

- `ADMFMMOGameMode` overrides both `AddInactivePlayer` and `FindInactivePlayer`; neither path can substitute a cached disconnected PlayerState.
- `PostLogin` preserves normal engine login flow and performs a DMF account-initialization integrity check afterward.
- Existing v0.18.1 disconnect finalization still saves before `Super::Logout` and destroys the transient summoned partner.
- SaveGame schema remains v7 and RPC count remains 49.
- No serialized enum values are changed.
- Vendor, swimming, underwater, Day/Night and progression gameplay source is unchanged by the reconnect authority fix.
- Package contains **145 files** versus **144** in accepted v0.18.0; the only added file is the dedicated disconnect/reconnect setup document.
- Source/header/build file count remains **98**.
- Reflected totals remain **52 UCLASS / 21 UENUM / 26 USTRUCT / 576 UFUNCTION / 1113 UPROPERTY**.

## Runtime acceptance still required

The critical acceptance case is repeated **disconnect → reconnect while the same Shipping host process remains running**. The result must match reconnecting after a host restart, with Party/Bank/avatar/active partner/progression preserved on every cycle.

---

# v0.18.1-alpha validation summary

Candidate: **Disconnect-Safe Account Persistence & Partner Cleanup Fix**  
Baseline: runtime-accepted **v0.18.0-alpha_ReplicatedDigimonVendorEconomyRotatingStockUI_UE58CompileFix**

## Root-cause / lifecycle hardening

- Replaced the previous logout + unconditional component-EndPlay double-write window with one idempotent pre-teardown session finalizer in `ADMFMMOGameMode`.
- The finalizer runs before `Super::Logout`, synchronizes the live summoned partner HP/SP, applies Digimon + avatar + valid world-location state to the existing account record, performs the synchronous account save, and only then finalizes transient session presentation.
- Added a non-serialized authoritative account-initialization guard. A PlayerState component that has not completed `InitializeFromAccountRecord` cannot save empty/default Party/Bank state over an established account.
- Successful disconnect persistence marks the component finalized so later `EndPlay` does not save again. Failed primary persistence keeps one guarded EndPlay retry.
- Added an authority-side PlayerController `EndPlay` fallback into the same idempotent GameMode finalizer for abrupt net-driver teardown ordering.
- Disconnect cleanup now unbinds partner vitals, force-disengages combat and destroys the summoned partner actor while preserving the persistent active-partner GUID.

## Compatibility

- Account SaveGame schema remains **v7**; no migration/reset added.
- Vendor economy and progression provenance fields are unchanged.
- Existing serialized enums are unchanged.
- RPC count remains **49**; no logout/save RPC or client-authored persistence state was added.
- Accepted v0.17.3 swim presentation, v0.17.2 water reload reconstruction, v0.17.1 underwater presentation and v0.18.0 vendor behavior remain structurally intact.

## Static validation performed

- Plugin descriptor reports `0.18.1-alpha` / integer version `1810`.
- Generated-header ordering and changed C++ delimiter balance pass.
- All RPC declarations retain matching `_Implementation` functions.
- No baseline serialized enum body changed and no existing reflected API was intentionally removed.
- New disconnect lifecycle helpers are native internal calls rather than extra network endpoints.
- Archive integrity is validated after packaging.

## Runtime acceptance still required

The consuming UE5.8 Shipping host/client must pass `TEST_PLAN.md` **S0 — v0.18.1 remote disconnect persistence acceptance**, especially remote close-before-autosave, orphan-partner cleanup and same-account reconnect restoration.

---

# v0.18.0-alpha validation summary

Candidate: **Replicated Digimon Vendor Economy & Rotating Stock UI**  
Baseline: runtime-accepted **v0.17.3-alpha_NetworkSmoothingCompatibleReplicatedSwimPresentationFix**

## Feature / authority validation

- Added Blueprint-derivable, replicated, zero-tick `DMFDigimonVendorActor` with per-NPC identity, interaction, species pool, randomized generation range, stock-slot policy, stock rotation scheduler, pricing configuration and widget override.
- Stock generation is authority-only. The server rolls species, level, current-level EXP, ABI, CAM, natural HP/SP/combat-stat variation, spent/unspent Attribute Points and derived stats, then replicates immutable offer snapshots plus the next rotation endpoint.
- Added automatic market valuation for stage, level, lifetime battle EXP, HP/SP/combat stats, ABI, CAM, Attribute Point investment and Digivolution history. Vendor Buy markup and player Sell payout are independently tunable.
- Added schema-v7 persistent `LifetimeBattleExperience` and `TotalAttributePointsSpent`. Legacy accounts migrate conservatively during authoritative load and stamp a one-way `DigimonEconomyProvenanceVersion = 1` marker; current Digimon identity/stats/ABI/history and v6 world-location state are preserved.
- Added atomic server purchase/sale helpers on `UDMFPlayerDigimonComponent`. Purchases reserve the shared StockId before account-side mutation/delegates, roll the reservation back on commit failure, and only then refill/broadcast; successful account mutations update Bits + Party/Bank and persist immediately. Active-partner sale uses the existing Party reconciliation path.
- Added native owner-local BUY/SELL widget with synchronized stock countdown, detailed progression/value inspection and two-step transaction confirmation.
- Client transaction payload is limited to vendor actor + Buy/Sell enum + GUID. Price, offered Digimon, sell quote, ownership, range, money, mutation locks and storage are resolved/revalidated by authority.
- Added one Server RPC and one owner Client result RPC. Candidate RPC count is **49** versus baseline **47**, with every declaration matched by `_Implementation`.

## Compatibility / serialization

- Baseline packaged files: **139**. Candidate before archive: **144**. Added only the four vendor runtime source/header files plus `Docs/SETUP_DIGIMON_VENDOR.md`; no baseline file is removed.
- Source/header/build files: **94 -> 98**.
- `UCLASS`: **49 -> 52**.
- `UENUM`: **20 -> 21**. The only new enum is `EDMFDigimonVendorTransactionType`; `EDMFPlayerInteractionType` only appends `DigimonVendor` after existing `Unhandled`, preserving every prior numeric value. All other existing enum bodies are unchanged.
- `USTRUCT`: **20 -> 26**.
- `UFUNCTION`: **525 -> 576**; no baseline reflected function name is removed.
- `UPROPERTY`: **991 -> 1113**.
- Account database schema intentionally advances **v6 -> v7** for the two additive per-Digimon valuation provenance fields. Shared Day/Night world-state schema is unchanged.
- Accepted v0.17.3 swimming/network smoothing, v0.17.2 water reload reconstruction and v0.17.1 underwater presentation code are not replaced by the vendor architecture.

## Static validation performed

- Plugin descriptor parses as valid JSON and reports `0.18.0-alpha` / integer version `1800`.
- Generated-header include ordering passes across public headers.
- Changed C++ source/header delimiter checks pass.
- All 49 RPC declarations have matching `_Implementation` functions.
- Baseline reflected-function set is a subset of the candidate reflected-function set.
- No baseline file is removed.
- Server transaction RPC accepts no price, money, generated Digimon struct or storage destination.
- Vendor actors have Tick disabled; stock rotation uses a server timer and sparse replicated property changes.
- Final ZIP archive passes `unzip -t` with no compressed-data errors; the archive retains the expected `DigimonMMOFramework/` root and plugin descriptor.

## Runtime acceptance still required

This environment cannot execute the consuming UE5.8 Editor/UnrealBuildTool. v0.18.0 remains a candidate until the project passes `TEST_PLAN.md` section **S0 — v0.18.0 replicated Digimon vendor economy acceptance** on listen host + remote client, including concurrent purchase, save/reload and v6 -> v7 migration tests.

---

# v0.17.3-alpha validation summary

Candidate: **Network-Smoothing-Compatible Replicated Swim Presentation Fix**  
Baseline: accepted **v0.17.2-alpha_PersistentWaterReloadStateReconstructionFix**

## Root-cause correction

- The failed/unaccepted direct-proxy pose candidate was discarded. Its direct `USkeletalMeshComponent::SetRelativeTransform` path competed with Unreal CharacterMovement network smoothing, explaining the reported upright remote swimmer plus listen-host shake.
- Added one compact server-authored replicated `ReplicatedSwimPresentationState` using the already-existing `EDMFPlayerSwimState` enum. No mesh transform is replicated.
- Non-local rendered player avatars use `ACharacter::CacheInitialMeshOffset` so CharacterMovement's own smoothing target contains the DMF horizontal swim fallback. `SmoothClientPosition` remains the final remote mesh writer.
- The same path covers simulated proxies on clients and listen-server rendering of remote autonomous clients.
- A stationary replicated state transition explicitly marks network smoothing incomplete so the new mesh-base target is consumed even if no new movement correction would otherwise wake smoothing.
- Owning players keep the accepted immediate local prediction/presentation path. Remote underwater travel pitch derives from already replicated/simulated velocity.
- Runtime skin/base transform capture is hardened against accidentally baking a transient smoothed proxy offset into the authored rest pose.

## Authority / persistence / compatibility

- New swimming RPCs: **0**.
- RPC declarations: **47**, unchanged from accepted v0.17.2; every declaration has a matching `_Implementation`.
- Account SaveGame remains **schema v6**; v0.17.2 world-position/water reconstruction is untouched.
- Day/Night shared-world persistence schema is unchanged.
- Existing `EDMFPlayerSwimState` serialized enum body is unchanged; no enum migration is required.
- Water actors remain **zero-tick**; no per-frame transform replication was introduced.

## Static validation

- Packaged files before archive: **139 -> 139**; no baseline file removed or added.
- Source/header/build files: **94 -> 94**.
- `UCLASS`: **49**, unchanged.
- `UENUM`: **20**, unchanged.
- `USTRUCT`: **20**, unchanged.
- `UFUNCTION`: **524 -> 525**; the only reflected addition is the internal `OnRep_ReplicatedSwimPresentationState` callback. No accepted reflected function was removed.
- `UPROPERTY`: **990 -> 991**; the only addition is the compact replicated swim presentation state.
- RPC declarations: **47**, unchanged, all with matching `_Implementation`.
- Plugin descriptor reports `0.17.3-alpha` / version integer `1730`.
- Generated-header include ordering, C++ delimiter balance and plugin JSON validation pass.
- No accepted serialized enum body or SaveGame schema changed.

## Runtime acceptance still required

This environment cannot run the consuming UE5.8 Editor/UnrealBuildTool. The candidate must pass `TEST_PLAN.md` section **v0.17.3 — replicated swim presentation / network smoothing acceptance**, especially client-swims/host-observes while stationary and moving, before it becomes the authoritative baseline.

## UE5.8 compile-fix revision

- User UE5.8.2 build log identified one root compile defect: `UDMFDigimonVendorEntryButton` inherited from `UButton` while the public header only forward declared `UButton`. The complete `Components/Button.h` definition is now included before `DMFDigimonVendorWidget.generated.h`.
- The resulting `C2504`, `C2027`, `C2440`, `C2065`, `C2664` and `C2039` vendor-widget errors are one compile cascade and are addressed at the root declaration.
- New vendor actor network-frequency setup now uses UE5.8 setter APIs. Existing accepted Day/Night/water deprecation warnings are outside this v0.18.0 compile-fix scope and remain behaviorally unchanged.
- Post-fix static validation confirms generated-header ordering, complete vendor button base-class visibility, unchanged RPC declarations/count, unchanged serialized enum values, unchanged v7 persistence schema and archive integrity.

