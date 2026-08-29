# Disconnect-Safe Account Persistence & Reconnect Authority — v0.18.2-alpha

## Same-host reconnect authority

The server account database is the only persistent reconnect source. DMF intentionally disables `AGameMode` inactive-PlayerState duplication/reassociation because those engine objects are transient session caches and do not own the framework's durable Party/Bank/avatar account contract. A remote player reconnecting while the host stays online must receive the account loaded during authentication exactly as a reconnect after a full host restart would.

Expected sequence:

1. disconnect finalizer commits the current account and destroys the transient partner;
2. Unreal continues controller/player teardown without creating a DMF inactive PlayerState duplicate;
3. reconnect authenticates username/password;
4. `InitNewPlayer` loads the persisted account into the newly created DMF PlayerState;
5. `FindInactivePlayer` is deliberately bypassed;
6. PostLogin validates that the authoritative account component remains initialized;
7. normal avatar/Party/Bank/partner reconstruction continues.


## Purpose

v0.18.1 hardens the authoritative account lifecycle for remote packaged/internet clients. A disconnect is treated as one server transaction:

1. keep the authenticated `ADMFPlayerState` and possessed avatar intact,
2. synchronize live partner HP/SP into the persistent Party entry,
3. merge Party, Bank, active partner, starter state, Bits, scan data, selected player skin and valid current world transform into the existing `FDMFAccountRecord`,
4. synchronously save the account database,
5. mark this login session persistence-finalized,
6. disengage and destroy the transient summoned partner actor,
7. allow Unreal to continue PlayerController/PlayerState teardown.

The order is intentional. Persistent state is committed **before** `Super::Logout` can detach or retain gameplay objects through Unreal's inactive-player lifecycle.

## No client save authority

There is no logout/save RPC and the client never supplies inventory, Digimon stats, Bits, avatar skin, saved coordinates or account data. The server owns the complete snapshot from its current authoritative runtime state.

`DMFMMOPlayerController::EndPlay` is only an authority-side lifecycle fallback. It calls the same idempotent GameMode finalizer if unusual net-driver teardown bypasses the normal timing. It does not accept client state.

## Teardown overwrite protection

`UDMFPlayerDigimonComponent` now tracks whether `InitializeFromAccountRecord` has completed for the current login. Until that guard is true, disconnect/autosave code refuses to serialize component defaults over the account database.

After the canonical disconnect save succeeds, the component is marked persistence-finalized. Its later `EndPlay` therefore cannot perform a second destructive write from partially torn-down state.

If the primary save fails, the finalized flag remains false and component teardown retains one guarded retry. If authoritative account initialization never completed, the existing persistent account is preserved instead of being replaced with an empty Party/Bank/default avatar state.

## Partner actor cleanup

A summoned partner actor is transient session state, not the persistent Digimon itself. Disconnect finalization:

- removes the combat-vitals delegate,
- force-disengages the partner,
- destroys the world actor,
- clears Care presentation props,
- preserves `ActivePartnerInstanceId` in the account.

The next login reconstructs the partner from the saved persistent Digimon instance as normal.

## Save schema

No new serialized field is required. Account schema remains **v7**.

## Required packaged multiplayer acceptance test

Use a listen/dedicated host and a real remote Shipping client:

1. Log in with an established remote account that has a selected avatar, Party/Bank Digimon and a summoned active partner.
2. Change at least one persistent value (move location, earn EXP/Bits or spend an Attribute Point).
3. Close/disconnect the remote client before the next normal autosave.
4. On the host, verify the remote player's partner actor disappears immediately after the server processes disconnect.
5. Reconnect with the exact same username/password.
6. Confirm the saved avatar skin is restored without opening first-time avatar selection.
7. Confirm Party, Bank, active partner, stats, ABI, Digivolution history, Bits and latest valid location are restored.
8. Repeat with an abrupt process close / network loss.
9. Repeat several fast disconnect/reconnect cycles and confirm no account ever returns as fresh and no orphan partner remains.
