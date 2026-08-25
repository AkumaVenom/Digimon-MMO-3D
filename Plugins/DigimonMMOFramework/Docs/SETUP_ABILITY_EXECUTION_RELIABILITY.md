# Ability Execution Reliability — v0.6.4-alpha

## Purpose
This release makes manual, queued, wild-retaliation, and proactive attacks use one authoritative range/cost contract.

## Range contract
`DMFDigimonAbilityData.MaxRange` is treated as usable combat reach **after the two collision capsule radii are removed from horizontal center distance**. This prevents a melee Digimon from physically touching its target while still being numerically considered out of range.

Do not inflate every melee ability range to compensate for capsule size. Configure the gameplay reach you actually want.

## SP contract
- `SPCost` is clamped to a non-negative effective cost at runtime.
- The server checks Current SP before accepting the command.
- SP is not consumed while chasing or turning.
- SP is consumed exactly once when the server actually starts the ability.
- Zero-SP and positive-SP abilities follow the same target/range/facing/cooldown path.

## Recommended first test
1. Summon a full-SP partner.
2. Target a wild Digimon with `E`.
3. Stand with the partner outside melee range and press slot 1 (for example, a 5-SP Claw Fist).
4. Verify the partner chases, turns to face, plays the attack, deals damage, and loses exactly the configured SP once.
5. Press the 0-SP slot 2 and verify it continues to work normally.
6. Repeat as a remote client against the host's server.

## MMO authority
All range, SP, cooldown, target validity, and impact validation remains server-authoritative. No client-side damage or SP spending was introduced.
