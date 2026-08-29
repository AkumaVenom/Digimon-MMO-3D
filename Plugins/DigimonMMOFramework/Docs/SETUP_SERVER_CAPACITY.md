# Global Server Player Capacity — v0.18.4-alpha

The Digimon MMO Framework now exposes one authoritative global player-cap setting for the gameplay server.

## Project Settings

Open:

**Project Settings → Game → Digimon MMO Framework → Networking → Server Capacity**

Set **Global Maximum Players**. The default is **100**.

The value means total simultaneously connected gameplay players on the authoritative server. For a listen server, the hosting player consumes one slot, so the default `100` permits the host plus up to `99` remote players. The minimum supported value is `1`.

## Authority / enforcement

This is not a frontend-only limit. The authoritative `DMFMMOGameMode` reapplies the configured value to Unreal's `AGameSession::MaxPlayers` immediately before every `PreLogin`, then Unreal's normal GameSession approval rejects connections when capacity is reached.

`Host & Play` also seeds the gameplay travel URL with the same `MaxPlayers` value when creating the listen server. This gives the native GameSession the correct capacity from world startup, while the `PreLogin` reassertion remains the final server-owned source of truth. A remote client cannot raise the server limit by adding or changing a `MaxPlayers` travel option.

Changing the setting affects **new connection admission only**. If an editor/runtime configuration change lowers the cap below the number of players already connected, the framework does not kick established authenticated players; it simply refuses additional joins until occupancy falls below the configured limit.

## Packaged deployment

The C++ default is `100`. For an explicit project deployment value, merge/update this entry in the consuming project's `Config/DefaultGame.ini`:

```ini
[/Script/DigimonMMOFramework.DMFFrameworkSettings]
GlobalMaxPlayers=100
```

The setting is server deployment configuration. Packaged clients may contain the same project default, but only the authoritative gameplay server's value controls admission.

## Recommended validation

For a practical low-count test, temporarily set **Global Maximum Players = 2**:

1. Start **Host & Play**. The host occupies slot 1.
2. Join with one remote client. It must succeed and occupy slot 2.
3. Attempt to join with a second remote client. Unreal must refuse the connection as full; the existing host and first client remain unaffected.
4. Disconnect the first remote client, then retry the rejected client. The new connection must now succeed.
5. Repeat with a manually crafted client URL containing a larger `MaxPlayers` option. The server must still enforce the Project Settings value of 2.
6. Restore **Global Maximum Players = 100** after the test.

No SaveGame schema, account record, Party/Bank state, Digimon state, vendor economy data or gameplay RPC is changed by this feature.
