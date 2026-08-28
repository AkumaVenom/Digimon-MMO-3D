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
