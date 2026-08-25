# Repeat-Safe Ability Commands — v0.6.4-alpha

## Purpose

Player partner quick-slot input must never feel one-shot. A valid press of `1`–`4` is now buffered on the server when the partner cannot execute immediately because it is still attacking, recovering, cooling down, chasing into range, or rotating toward the target.

## Execution contract

1. Player selects a valid hostile Digimon.
2. Player presses an ability slot.
3. The server validates ownership, slot, target, leash, and current SP.
4. If immediately legal, the ability starts.
5. If temporarily blocked by attack/recovery/cooldown/range/facing, the latest command remains buffered.
6. Automation revalidates the buffered command until legal or until its bounded timeout expires.
7. SP is deducted exactly once only when the ability actually enters `Attacking`.
8. Cooldown begins exactly once at execution.
9. Expired cooldown records are pruned from the replicated array.

## Input behavior

The buffer is **latest-command wins**. Pressing slot 2 while slot 1 is waiting intentionally replaces the pending slot-1 command. This keeps manual MMO controls responsive rather than building an uncontrolled multi-action queue.

## First acceptance test

Use a partner with at least 20 SP and a slot-1 ability costing 5 SP. Target a durable wild Digimon, then:

- Press `1`; confirm the attack executes and SP falls by exactly 5.
- Immediately press `1` again during recovery/cooldown.
- Do not press another slot. The server should retain the command and execute slot 1 again as soon as it is ready.
- Repeat until SP is below 5; each successful attack must reduce SP by exactly 5.
- Once SP is below 5, slot 1 must correctly stop executing while a 0-SP slot can still work.
- Heal/restore SP and confirm slot 1 becomes usable again.

Also repeat host/client testing to confirm the server remains authoritative and both peers observe the same SP, cooldown, facing, montage, and damage results.
