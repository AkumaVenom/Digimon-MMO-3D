# Combat Target Facing — v0.6.2-alpha

## Goal
Both player-owned and wild Digimon should face the Digimon they are attacking. The framework performs the turn on the authoritative server and lets normal Character movement replication carry yaw to clients.

## Default setup
No Blueprint graph is required. Every `DMFDigimonCharacter` child inherits the feature.

Open `BP_Digimon_<Species>` and `BP_Wild_<Species>` -> **Class Defaults** -> **Digimon MMO | Combat | Facing**. Recommended defaults:

- **Enable Combat Facing** = true
- **Require Facing Before Attack** = true
- **Combat Facing Turn Rate Degrees Per Second** = 720
- **Attack Facing Tolerance Degrees** = 8
- **Combat Facing Update Interval** = 0.033 seconds

Use a lower turn rate for very large/heavy Digimon and a higher rate for small/agile Digimon. Avoid disabling the facing requirement unless a species intentionally has omnidirectional attacks.

## Runtime behavior
1. A commanded/retaliating/aggressive Digimon chases normally while out of ability range.
2. Once in range, the authoritative AI stops movement.
3. The framework temporarily disables movement-driven yaw and turns the actor toward the target.
4. If `Require Facing Before Attack` is enabled, ability execution waits until yaw error is within tolerance. SP/cooldown are not consumed during this brief alignment.
5. The attack Montage/VFX/damage pipeline executes normally.
6. Facing remains active through recovery so a moving target is tracked.
7. Recovery ends and the previous CharacterMovement rotation policy is restored.

## Blueprint API
All framework Digimon expose:
- `Start Combat Facing Target` (Authority only)
- `Stop Combat Facing Target` (Authority only)
- `Is Facing Actor`
- `Get Combat Facing Target`

Normal combat does not require calling these manually. They are provided for bosses/custom encounters.

## Multiplayer acceptance test
Run two PIE clients or host + remote client. Have Player A command its partner to attack a wild Digimon with passive retaliation enabled. Confirm:
- Partner turns to face the wild target before its Montage starts.
- Wild Digimon turns to face the attacking partner before retaliating.
- Host and remote client observe the same actor yaw.
- Neither actor snaps back to movement orientation during the attack.
- After recovery/leash return, following/roaming orientation behaves normally.
- No extra local/client-side attack rotation Blueprint is required.
