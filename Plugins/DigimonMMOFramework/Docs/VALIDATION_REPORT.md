# v0.19.3-alpha validation summary

Candidate: **Polished Combat Quickbar BITS HUD**  
Baseline: runtime-accepted **v0.19.2-alpha_PolishedNearbyPlayerIgnoreAction**. The accepted Social/Guild/Friends/Ignore, chat presence, player capacity, vendor, reconnect/persistence and gameplay contracts are preserved.

## BITS HUD validation

- The native `UDMFCombatQuickBarWidget` adds one compact fixed-footprint **BITS** capsule in the existing header lane, using the same gold economy language and locale-aware `FText::AsNumber` formatting as the Digimon Exchange.
- The display reads only `UDMFPlayerDigimonComponent::GetMoney()`. Backing `Money` is unchanged and remains `ReplicatedUsing=OnRep_Money` with `COND_OwnerOnly`, so another client never receives this account balance through the new HUD.
- BITS refresh occurs through the quickbar's existing 0.15-second local presentation timer and is independent of `ActivePartnerActor`; recalling/not summoning a partner does not blank the account currency. No additional Tick or server polling loop was introduced.
- The fixed 150×28 native capsule uses a down-only `UScaleBox`, preventing unusually large integer balances from growing into the adjacent clock or target header. The four ability-card lane is unchanged.
- Blueprint children can bind optional `BitsText`. `bShowCombatQuickBarBits=True` is config-backed/Blueprint-readable under **UI → Combat Quick Access → Economy** and only controls presentation.

## Authority / networking / persistence validation

- **0 new RPCs**: the current RPC declaration set is byte-for-byte equivalent by name to v0.19.2 and remains **53** total. All 53 declarations have matching `_Implementation` functions.
- **0 new replicated properties** are required by this feature. The existing authoritative `Money` property is reused directly.
- Account SaveGame remains **schema v8**; no migration, currency conversion or persistent HUD state is added.
- `DMFMMOGameMode.cpp` and `DMFAccountPersistenceSubsystem.cpp` are byte-for-byte unchanged from the runtime-accepted v0.19.2 baseline.
- Vendor purchase/sale authority and battle-money reward authority remain unchanged; the HUD only observes the already committed owner balance.

## Static validation

- Plugin descriptor parses as valid JSON and reports `0.19.3-alpha` / integer version `1930`.
- Candidate tree contains **154 files**, including **104 source/header/build files**. The only new path is `Docs/SETUP_COMBAT_QUICK_BAR_BITS.md`; no v0.19.2 path was removed.
- Reflected totals: **55 UCLASS / 24 UENUM / 33 USTRUCT / 631 UFUNCTION / 1230 UPROPERTY**.
- Public generated-header include ordering passes.
- All **53 RPC** declarations have matching `_Implementation` functions, and the RPC name set is unchanged from v0.19.2.
- Full framework `.h/.cpp` comment/string-aware `()[]{}` delimiter validation passes.
- No merge-conflict markers are present.

## Runtime acceptance still required

Run `TEST_PLAN.md` **v0.19.3-alpha — Combat Quick Bar BITS HUD acceptance**. Critical acceptance is owner-isolated balance display on host/client, automatic change after an authoritative purchase/sale or battle-money reward, visibility while the partner is recalled, clean header layout at practical balances, and no regression to the accepted v0.19.2 Social/Guild/Ignore or existing vendor/economy systems.

---

# v0.19.2-alpha validation summary

Candidate: **Nearby Player Ignore Action Polish**  
Baseline: runtime-accepted **v0.19.1-alpha_PolishedNearbyPlayerFriendDiscovery**. Guilds and nearby Friends discovery are already runtime-confirmed; this revision completes the Nearby Players interaction surface with direct Ignore/Unignore.

## Nearby-player discovery validation

- `ADMFMMOPlayerController::GetNearbySocialPlayers()` is owner-local and reads only already-replicated `ADMFPlayerAvatarCharacter` actors plus the controller's existing owner-only Social snapshot. It excludes the local pawn, rejects invalid/no-name actors, clamps the global radius, deduplicates reconnect-transition duplicate avatars by canonical public username and keeps the nearest instance.
- Results remain sorted by precise local distance before presentation. Native rows show rounded integer metres and relationship state. Non-ignored rows retain `ADD FRIEND`, `ACCEPT`, `CANCEL`, or disabled `FRIEND` relationship actions and add a dedicated `IGNORE` control; ignored rows expose `UNIGNORE` directly.
- The Friends page now contains four coherent columns: **NEARBY PLAYERS**, **FRIENDS**, **FRIEND REQUESTS**, and **IGNORE LIST**. Existing Guild layout/code paths were not replaced.
- Nearby refresh uses a configurable owner-local timer only while Social/Friends is active. It computes a presentation hash and rebuilds dynamic UMG rows only when visible username/order/integer-distance/relationship/radius state changes, avoiding unnecessary widget churn with larger player counts.
- Project Settings exposes **Nearby Player Friend Discovery Radius** (default `50 m`) and **Nearby Player List Refresh Interval** (default `0.5 s`) under `UI|Social|Nearby Players`; runtime reads are defensively clamped.
- Blueprint-reskinned Social UIs can consume `FDMFNearbySocialPlayerEntry`, `GetNearbySocialPlayers()` and `RefreshNearbyPlayersData()` without replacing server authority.

## Authority / networking / persistence validation

- Nearby discovery adds **zero network RPCs** and no replicated Social/distance property. Framework RPC total remains **53**.
- `IgnoreAdd` is appended after the v0.19.1 `FriendAdd` UI action, preserving all previous enum ordinals. The action routes to existing `RequestIgnorePlayer()`; nearby `UNIGNORE` reuses existing `IgnoreRemove` / `RequestRemoveIgnoredPlayer()`. Both therefore use the existing reliable `ServerExecuteSocialAction` validation/persistence transaction.
- Add/accept/cancel/ignore/unignore from Nearby Players all reuse existing Social server actions. A nearby row never mutates friendship or Ignore state locally.
- Account SaveGame remains **schema v8**. No Social/Guild/account migration is introduced.
- Existing v0.19.0 Guild authority, Friends/Ignore persistence, owner-local friend tracking and Ignore chat filtering remain structurally intact. v0.18.5 presence/audio, v0.18.4 capacity, v0.18.3 vendor UI/economy and v0.18.2 reconnect/disconnect persistence contracts are unchanged.

## Static validation

- Plugin descriptor parses as valid JSON and reports `0.19.2-alpha` / integer version `1920`.
- Package tree contains **153 files**, including **104 source/header/build files**; no v0.19.0 file path was removed.
- Reflected totals: **55 UCLASS / 24 UENUM / 33 USTRUCT / 631 UFUNCTION / 1228 UPROPERTY**.
- Public generated-header include ordering passes.
- All **53 RPC** declarations have matching `_Implementation` functions; there are no duplicate RPC declaration names.
- `EDMFSocialUIAction` preserves all previous values in original order; v0.19.1 `FriendAdd` remains in place and v0.19.2 appends only `IgnoreAdd`.
- No merge-conflict markers are present. The full framework `.h/.cpp` set passes a comment/string-aware `()[]{}` delimiter-balance scan.
- Final packaged ZIP integrity is validated with `unzip -t`; every archived file reports OK.

## Runtime acceptance still required

Run `TEST_PLAN.md` **S0 — v0.19.2 nearby-player Friends + Ignore discovery / persistent Social / Guild regression**. The critical new acceptance is that every eligible nearby row exposes direct IGNORE, ignored rows expose UNIGNORE, Ignore still leaves the player/world actor visible while filtering authored WORLD chat and cleaning incompatible Social state, and all v0.19.1 nearest-first/radius/Friends plus v0.19.0 Guild behavior remains unchanged.

---

# v0.18.5-alpha validation summary

Candidate: **Replicated World Chat Presence Announcements**  
Baseline: runtime-accepted **v0.18.4-alpha_GlobalMaxPlayersServerCapacity**

## Presence / authority validation

- Appended `PlayerJoined` and `PlayerLeft` to `EDMFWorldChatMessageType`; existing `Player` and `System` values remain first/in the same order. No client RPC accepts a presence type or username.
- Successful `ADMFMMOGameMode::PostLogin` emits the join event only after authenticated account initialization/integrity rehydrate, so ordinary joins and same-host relogs announce the durable account username.
- `ADMFMMOGameMode::Logout` retains the v0.18.2 save-before-`Super::Logout` contract: the account/partner session is finalized first, then the leave event is authored while the authenticated PlayerState still exists.
- Player chat and presence events share one internal GameMode dispatch path for bounded history + reliable owner-client fan-out. No replicated chat array or separate presence transport was introduced.
- Presence history remains transient session state. Late-join history hydration never invokes `PlayWorldChatPresenceSound`, so historical events cannot replay old audio.
- Native presentation branches only on the server-authored message type: joined username = `DMFNativeUI::Success`; departure username/body = `DMFNativeUI::Danger`; ordinary player/System styling is preserved.

## Project Settings / audio validation

- Added `Announce Player Join / Leave` and `Play Player Join / Leave Sounds` under `UI|World Chat|Presence`.
- Added independent soft `USoundBase` settings for **Player Joined Server Sound** and **Player Left Server Sound**, plus shared `0-4` volume and `0.25-4` pitch multipliers.
- Live audio is recipient-local via `UGameplayStatics::PlaySound2D` after the reliable chat event arrives. Dedicated servers have no local controller and perform no audio presentation work. Unassigned sound assets fail silently without affecting chat text.

## Compatibility

- Account SaveGame schema remains **v7**; no migration/reset is required.
- RPC count remains **49** and all declarations retain matching `_Implementation` functions.
- Reflected totals are **52 UCLASS / 21 UENUM / 26 USTRUCT / 577 UFUNCTION / 1120 UPROPERTY**. The UFUNCTION increase is the authority-only Blueprint presence broadcaster; the six new UPROPERTY entries are Project Settings controls/assets.
- Package file set is unchanged from v0.18.4: **146 files**, including **98 source/header/build files**. No baseline file was removed.
- v0.18.4 server capacity, v0.18.3 vendor layout, v0.18.2 reconnect authority, disconnect persistence/partner cleanup, Party/Bank privacy, vendor economy, world location, Return Home, Day/Night, swimming/underwater, combat, DigiDex, Digivolution and Care source contracts remain intact.

## Static validation performed

- Plugin descriptor parses as valid JSON and reports `0.18.5-alpha` / integer version `1850`.
- Public generated-header include ordering passes.
- All **49 RPC** declarations have matching `_Implementation` functions.
- C++ delimiter balance passes across framework `.h/.cpp` files.
- Baseline v0.18.4 file paths are a complete subset of the candidate; no file removal or unexpected package expansion occurred.
- Final ZIP archive integrity is validated after packaging.

## Runtime acceptance still required

Run `TEST_PLAN.md` **S0 — v0.18.5 replicated world-chat presence acceptance** on listen host + remote packaged client. Critical acceptance is exactly one green join event/sound per successful login/relog, exactly one red leave event/sound per processed logout, silent history replay, and unchanged same-host reconnect persistence.

---

# v0.18.4-alpha validation summary

Candidate: **Global Max Players Server Capacity**  
Baseline: runtime-accepted **v0.18.3-alpha_PolishedDigimonVendorNativeUILayout**

## Capacity / authority validation

- Added one config-backed `UDMFFrameworkSettings::GlobalMaxPlayers` Project Setting under `Networking|Server Capacity`, default **100**, clamped to `1-10000`; the listen host consumes one normal player slot.
- `UDMFSessionSubsystem::HostAndPlay` seeds Unreal's gameplay world with `?MaxPlayers=<configured>` during listen-server creation.
- `ADMFMMOGameMode::PreLogin` calls `ApplyConfiguredPlayerCapacity()` before `Super::PreLogin`, so `AGameSession` evaluates the server-owned cap during its native approval path.
- The cap is reapplied from server Project Settings for every connection. Client-authored travel options cannot increase it.
- Existing players are not forcibly removed if the setting is lowered below live occupancy; admission resumes when occupancy is again below the configured value.

## Compatibility

- Account SaveGame schema remains **v7**.
- RPC count remains **49**; no capacity RPC, replicated capacity property or client-authored admission state is added.
- No existing serialized enum body changes.
- v0.18.3 vendor UI layout and v0.18.2 authenticated reconnect/disconnect-persistence contracts remain structurally intact.

## Static validation performed

- Plugin descriptor reports `0.18.4-alpha` / integer version `1840` and parses as valid JSON.
- Public generated-header include ordering passes.
- All 49 RPC declarations have matching `_Implementation` functions.
- C++ delimiter balance passes across all framework `.h/.cpp` files.
- Package file count: **146**; source/header/build file count: **98**.
- Reflected totals: **52 UCLASS / 21 UENUM / 26 USTRUCT / 576 UFUNCTION / 1114 UPROPERTY**.
- Final ZIP archive integrity is validated after packaging.

## Runtime acceptance still required

Run `TEST_PLAN.md` **S0 — v0.18.4 global maximum-player capacity acceptance** with a listen host and multiple separate clients. The critical acceptance case is cap `2`: host + one remote succeeds, a second remote is refused, disconnect frees a slot, and a client-supplied larger `MaxPlayers` option cannot bypass the server setting.

---

# v0.18.3-alpha validation summary

Candidate: **Polished Digimon Vendor Native UI Layout Hardening**  
Baseline: authoritative **v0.18.2-alpha_AuthenticatedReconnectPersistentAccountAuthorityFix**

## UI root cause / correction

- The v0.18.2 native vendor detail column placed `DetailStatsText` in a compressed Fill slot while valuation text and two action buttons retained Auto desired height. When the complete right-panel content exceeded the fixed 720px window, Slate could shrink the Fill geometry below the text's desired height; because the text itself was not clipped to that slot, it visibly painted through valuation/action widgets.
- v0.18.3 moves the variable-height information into a dedicated `UScrollBox`. The ScrollBox receives the remaining Fill space while its text/card children keep natural desired height, which removes the structural overlap condition rather than hiding it with smaller fonts.
- The authored window is now 1280x780 with ScaleToFit/DownOnly retained. Portrait height is reduced and wrapped in a ScaleBox, leaving more vertical budget for information while preserving image aspect.
- Stats and valuation are separate padded cards; transaction/Close controls are pinned outside the information scroller.
- BUY/SELL rows now have a minimum height, aspect-safe icon fitting and a fixed quote column. SELL storage is separated from the quote instead of being concatenated into the metadata/price line.

## Compatibility / authority validation

- Only `DMFDigimonVendorWidget.cpp`, release metadata and documentation are changed; vendor actor, player economy component, GameMode reconnect logic and RPC declarations are untouched.
- SaveGame schema remains **v7**.
- RPC count remains **49** and every declaration retains its existing `_Implementation`.
- No serialized enum body changes.
- No reflected `UCLASS`, `UENUM`, `USTRUCT`, `UFUNCTION` or `UPROPERTY` contract is added/removed by this UI pass.
- Authenticated persistent-account reconnect authority and disconnect-finalization behavior from v0.18.2 are preserved verbatim.

## Static validation performed

- Plugin descriptor reports `0.18.3-alpha` / integer version `1830` and parses as valid JSON.
- Public generated-header include ordering passes.
- All 49 RPC declarations have matching `_Implementation` functions.
- C++ delimiter balance passes for the modified vendor widget and all framework `.h/.cpp` files.
- Package file count remains **145** and source/header/build file count remains **98**.
- Final ZIP archive integrity is validated after packaging.

## Runtime acceptance still required

Run `TEST_PLAN.md` **S0 — v0.18.3 polished native Digimon vendor UI acceptance** in the consuming UE5.8 project. Primary acceptance is zero overlap/clipping on both BUY and SELL at 1080p and scaled smaller viewports while all v0.18.2 network/persistence behavior remains unchanged.

---

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

