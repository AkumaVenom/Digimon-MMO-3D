# Defeated Partner / Death Montage Presentation Setup

## Goal
A Digimon at `0 HP` must remain visibly defeated in the world instead of blending back to idle. Player partners stay in that state until Recall/Dismiss or an authoritative revive. Spawner-managed wild Digimon use the same death-pose presentation during their existing corpse lifetime and are then destroyed by the spawner.

## 1. Species Data Asset
Open `DA_Species_<Digimon>` and assign **Animation -> Death Montage** to a montage made for that species' own Skeleton, for example `AM_Agumon_Death`.

## 2. Animation Blueprint
The Digimon AnimBP must contain the same Slot used by the montage. The recommended minimum graph is:

`Locomotion (or Ref Pose) -> Slot(DefaultGroup.DefaultSlot) -> Output Pose`

The Death Montage must use `DefaultGroup.DefaultSlot` unless your AnimBP intentionally exposes another matching slot.

## 3. Character Blueprint tuning
Open `BP_Digimon_Agumon` (and optionally its wild equivalent) -> Class Defaults -> **Digimon MMO -> Defeat Presentation**. Defaults:

- Hold Defeated Pose Until Revived Or Dismissed = true
- Defeated Pose Hold Normalized Time = 0.97
- Defeated Montage Play Rate = 1.0
- Disable Movement When Defeated = true
- Disable Capsule Collision When Defeated = true

If a death animation's final useful pose occurs before the end, lower **Defeated Pose Hold Normalized Time** (for example `0.90`). The value is intentionally exposed per Blueprint because imported death clips can contain different amounts of trailing frames.

## 4. Runtime contract
At `0 HP` the server sets CombatState to Defeated. All peers apply the defeated presentation. The montage plays once and is paused/frozen near the configured final pose. AI movement is stopped. The body remains visible.

Recall/Dismiss destroys the currently spawned partner actor but keeps the persistent active-partner selection. A healer/revive restores HP, clears the defeated presentation, restores the cached movement/collision state and resumes the AnimBP.

## 5. Multiplayer acceptance test
1. Host and client see the same player-owned partner.
2. Reduce the partner to `0 HP`.
3. Both peers see the species Death Montage.
4. After the montage duration, the partner remains frozen in the defeated pose; it must not return to Idle/Walk.
5. Wait at least 10 seconds. The partner remains.
6. Recall Partner from the Digimon inventory. The defeated actor disappears.
7. Heal/revive a defeated spawned partner with the healer. The death pose clears and normal animation/movement returns.
8. Repeat with a wild Digimon. It holds the death pose only for the spawner's configured defeated corpse delay, then the spawner destroys/replaces it normally.

## v0.5.5 deterministic end-pose lock

The framework no longer relies on a timer firing near the end of a Death Montage. Unreal Montages can begin blend-out before `GetPlayLength()` has elapsed, which allowed the AnimBP to blend a defeated Digimon back to Idle. v0.5.5 binds to the Death Montage blend-out lifecycle and locks the current death pose at that boundary. It also pauses skeletal evaluation (`bPauseAnims`) and sets `GlobalAnimRateScale` to zero until revive/clear.

This applies identically to player-owned and wild Digimon. A wild Digimon may still be destroyed by the spawner's `Defeated Despawn Delay`, but it must remain on the locked death pose for that corpse lifetime.

For normal species setup, assign a valid species `Death Montage` using the same Skeleton/AnimBP slot as that Digimon. No Blueprint tick, animation notify, custom death state machine, or manual pause call is required.
