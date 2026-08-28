# Replicated Ability Projectiles & VFX Cleanup — v0.14.1-alpha

This guide configures projectile attacks such as fireballs, energy bolts, rockets, poison shots and other visible attacks that must physically travel from a Digimon toward its combat target.

The v0.14.1 projectile path is deliberately separate from the original timed-impact cosmetic path:

- **Timed / Instant Impact** keeps the original server-timed damage model and spawns a transient Niagara/Cascade presentation cue.
- **Replicated Projectile** launches a real replicated `ADMFAbilityProjectileActor`. The server owns flight, target pursuit, arrival and damage. Clients only render the replicated projectile and cosmetic impact presentation.

## 1. Open the ability Data Asset

Open the `DMFDigimonAbilityData` used by the attack, for example `DA_Ability_PepperBreath` or a Fireball ability.

Under **Execution** set:

`Execution Mode = Replicated Projectile`

Existing abilities remain `Timed / Instant Impact` by default, so upgrading the plugin does not silently change previously authored attacks.

## 2. Configure launch timing

`Impact Delay Seconds` changes meaning slightly for projectile execution. It is the **server-authoritative launch delay** after the ability begins, not the damage delay.

Use it to align projectile release with the attack montage. For example, if the Digimon releases the fireball 0.35 seconds into its attack montage:

`Impact Delay Seconds = 0.35`

The projectile is spawned by the server at that point. Damage occurs only when the projectile actually reaches its valid target.

`Recovery Seconds` remains the caster's post-launch action lock. Projectile flight can continue after the caster has entered its normal recovery/idle flow.

## 3. Choose the launch socket

Under **Projectile → Launch**:

- `Projectile Spawn Socket Name` is the preferred projectile launch socket.
- If it is empty, the framework falls back to the existing `VFX Socket Name`.
- If neither socket exists, the projectile safely falls back to the Digimon actor transform.
- `Projectile Spawn Offset` is a local-space offset from that socket/transform.

For a mouth attack, use the mouth/head attack socket. For a hand fireball, use the authored hand/attack socket.

The server calculates the initial projectile rotation from the launch point **toward the authoritative target**. It does not inherit an arbitrary socket rotation as its travel direction.

## 4. Assign the moving visual

Under **Projectile → Visual** assign one or more of:

- `Projectile Niagara System` — preferred modern moving VFX.
- `Projectile Cascade Particle` — fallback when Niagara is unassigned.
- `Projectile Static Mesh` — optional mesh carried by the projectile.

For migration convenience, if both dedicated projectile VFX fields are empty, projectile mode falls back to the ability's existing `Niagara Particle` / `Cascade Particle`. The old species Attack1/Attack2 particle overrides are also retained as a final compatibility fallback.

### Niagara authoring note

For a coherent fireball/orb that should move as one object with the projectile actor, author the Niagara emitter in **Local Space**. World-space particles deliberately remain where they were emitted and therefore behave like a trail. A projectile may intentionally combine a local-space core with world-space trailing particles.

## 5. Correct asset orientation

The projectile actor always treats Unreal **+X** as forward and rotates the actor toward its actual travel direction.

If the fireball/mesh asset itself was authored facing another local axis, do **not** rotate the spawn socket to compensate. Instead set:

`Projectile Visual Rotation Offset`

This rotates only the visual child while preserving the correct authoritative travel direction.

`Projectile Visual Scale` provides per-ability scale correction.

## 6. Configure movement

Under **Projectile → Movement**:

- `Projectile Speed` — world units per second. Default: `1400`.
- `Projectile Homing` — when enabled, server flight continually turns toward the moving target.
- `Projectile Homing Turn Rate Degrees` — maximum turn rate per second. Default: `720`.
- `Projectile Target Offset` — aim-point offset relative to the target actor location.

For ordinary fireballs, start with homing enabled. For straight ballistic-looking attacks, disable homing; the projectile keeps its launch direction and can miss a target that moves out of the path.

## 7. Configure arrival and cleanup

Under **Projectile → Impact**:

- `Projectile Impact Radius` — arrival tolerance around the current target aim point.
- `Projectile Max Lifetime Seconds` — hard cleanup guard. Default: `6` seconds.
- `Projectile Impact Niagara System` — optional impact burst.
- `Projectile Impact Cascade Particle` — optional fallback.
- `Projectile Impact Sound` — optional spatial impact audio.
- `Projectile Impact VFX Lifetime Seconds` — forced cleanup lifetime for impact VFX.

The projectile actor is always destroyed on successful arrival, invalid target/source, or hard lifetime expiry. All projectile-attached Niagara/Cascade/mesh components therefore disappear with it even when the authored particle system loops forever.

Impact VFX spawned separately at the hit location are also forcibly deactivated/destroyed after `Projectile Impact VFX Lifetime Seconds`.

## 8. Damage and replication contract

Projectile attacks remain fully server-authoritative:

1. Client requests an ability through the existing owned PlayerState command route.
2. Server validates target, SP, cooldown, range, leash and combat-facing.
3. Server deducts SP and starts cooldown only after accepting the attack.
4. Server launches the replicated projectile after `Impact Delay Seconds`.
5. Server alone advances authoritative projectile pursuit/arrival.
6. Damage is applied only when the projectile reaches the still-valid hostile target.
7. A lightweight unreliable multicast plays optional impact VFX/audio.

The client never supplies projectile damage, final target position, arrival time or hit result.

The initial `Max Range` is still validated when the ability begins. Projectile arrival does **not** perform the old second cast-range test; a target that moves while the projectile is flying can still be hit if the visible projectile actually reaches it.

## 9. Optional custom projectile Blueprint

`Projectile Class` may be left empty. The framework then uses the native `DMFAbilityProjectileActor` automatically.

For additional presentation, create a Blueprint derived from `DMFAbilityProjectileActor` and assign it to `Projectile Class`.

Useful inherited components:

- `Projectile Root`
- `Visual Root`
- `Projectile Mesh`
- `Projectile Niagara`
- `Projectile Cascade`

Useful Blueprint hook:

`BP On Projectile Presentation Ready`

Keep damage, SP, target authority and impact decisions in the native combat path. A custom projectile Blueprint should be cosmetic only.

## 10. Non-projectile VFX cleanup

Timed/instant abilities now expose:

`Presentation VFX Lifetime Seconds`

All native transient Niagara/Cascade cues are forcibly deactivated and destroyed after that lifetime, even if a designer accidentally assigns a looping particle system.

The framework also rotates socket-origin timed VFX toward the selected target and exposes:

- `Presentation VFX Rotation Offset`
- `Presentation VFX Scale`

This fixes the old permanent socket-particle accumulation while preserving compatibility with existing timed-impact abilities.

## Recommended fireball starting values

```text
Execution Mode                    Replicated Projectile
Impact Delay Seconds              0.25 - 0.40 (match montage)
Projectile Spawn Socket Name      your mouth/hand attack socket
Projectile Niagara System         your fireball Niagara system
Projectile Speed                  1400
Projectile Homing                 true
Projectile Homing Turn Rate       720
Projectile Impact Radius          55
Projectile Max Lifetime Seconds   6
Projectile Visual Rotation Offset tune only if the asset faces the wrong local axis
Projectile Impact VFX Lifetime    2
```

## Multiplayer acceptance test

Use host + at least one remote PIE client:

1. Put the same attack on a player partner and, if appropriate, a Wild Digimon.
2. Attack from the host. Both windows must see one projectile leave the correct socket and travel toward the target.
3. Attack from the remote client. Host and client must see the same replicated flight.
4. Move the target during flight with homing enabled; projectile should turn toward it.
5. Disable homing and repeat; projectile should keep its original launch direction.
6. Verify damage occurs on visible projectile arrival, not at cast time.
7. Verify projectile disappears after impact.
8. Deliberately use a looping projectile Niagara system and let it miss; the entire actor/VFX must disappear at `Projectile Max Lifetime Seconds`.
9. Test a normal timed-impact looping Niagara/Cascade cue; it must disappear at `Presentation VFX Lifetime Seconds`.
10. Repeat attacks for several minutes and verify no orphan attack particles remain in the world.

## v0.14.6 CustomDepth contract — attack VFX

All framework-owned runtime attack particle components force **Render CustomDepth Pass = true**. This includes transient direct-ability Niagara/Cascade effects, projectile-impact Niagara/Cascade effects, and the Niagara/Cascade components on replicated moving projectile actors. Moving projectile components reassert the flag every time their presentation is refreshed before activation, including replication-driven definition refreshes. This changes presentation only; projectile travel, homing, impact authority and replicated lifecycle are unchanged.

