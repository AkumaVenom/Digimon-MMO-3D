# Polished Native World Chat & Presence — v0.18.5-alpha

The framework includes a ready-to-use **session-wide WORLD chat** designed for the existing multiplayer-only MMO flow. It is native C++/UMG by default, automatically created for each local gameplay client, Blueprint-reskinnable, and keeps message authority on the server.

## 1. Default player experience

With the default settings:

1. The WORLD chat panel appears in the lower-left gameplay HUD.
2. Press **Enter** to focus the message field.
3. While typing, movement/look/combat input is temporarily blocked so gameplay keys cannot fire abilities or move the avatar.
4. Press **Enter** again to submit the message.
5. The input field closes and gameplay focus returns immediately.
6. Press **Escape** while editing to cancel without sending.
7. Accepted player messages appear on the host and every connected client as `Username: message`.
8. A successful authenticated login/relog automatically adds `Username has joined the server.`; the username is bold green in the native widget.
9. An authoritative logout automatically adds `Username has left the server.`; the username and departure statement are red in the native widget.
10. If global presence sounds are assigned, each live join/leave event plays its matching cue once for every connected recipient.

The native layout deliberately stays compact and uses the framework navy/cyan/gold presentation language. The chat is persistent on the HUD but does not occupy a modal screen.

## 2. Server-authoritative message contract

A client submits **only raw message text** through its owned `ADMFMMOPlayerController`.

The server then:

- checks the global world-chat enable setting;
- removes line breaks/tabs and trims surrounding whitespace;
- clamps the accepted message to the configured maximum length;
- enforces a per-player minimum send interval;
- enforces a sliding-window burst limit;
- resolves the sender from the authoritative `ADMFPlayerState`;
- uses public replicated `APlayerState::PlayerName` as the display username;
- stamps the accepted message with server UTC ticks;
- stores only a bounded session history;
- delivers the accepted payload to each owning framework PlayerController.

Presence events use a separate server-only path on the same transport:

- successful `PostLogin` emits `EDMFWorldChatMessageType::PlayerJoined` only after authenticated account integrity/rehydration;
- `Logout` finalizes persistent account/partner teardown first, then emits `EDMFWorldChatMessageType::PlayerLeft` while the authenticated PlayerState is still available;
- the server obtains the presence username from `GetAuthenticatedUsername()` (with public PlayerName only as a defensive fallback);
- the client never supplies presence message text, username or presence type;
- join/leave events enter the same bounded session history as normal WORLD chat;
- live delivery may play the configured local cue, but history replay is intentionally silent.

The client cannot choose another player's username, timestamp or message type. Credentials and the private owner-only authenticated account field are never placed into chat payloads.

## 3. Project Settings

Open:

**Project Settings → Game → Digimon MMO Framework → UI → World Chat**

### Core

- **Enable World Chat** — master global switch. When false, no native chat widget is created and the server rejects chat submission.
- **Enable Default World Chat Input** — enables the built-in **Enter** binding. Disable this if your project routes input itself and call `OpenWorldChatInput()` from Blueprint.
- **World Chat Widget Class** — defaults to `DMFWorldChatWidget`. Assign a Blueprint child to completely reskin the presentation while retaining framework networking/validation.

### Presence

- **Announce Player Join / Leave** — default `true`. Publishes authenticated login/relog/logout events into WORLD chat.
- **Play Player Join / Leave Sounds** — default `true`. Controls only presence audio; chat presence text remains available when audio is disabled.
- **Player Joined Server Sound** — global 2D Sound Cue/Wave used for live join/relog events. Leave unassigned for silent joins.
- **Player Left Server Sound** — independent global 2D Sound Cue/Wave used for live departure events. Leave unassigned for silent departures.
- **Presence Sound Volume Multiplier** — default `1.0`, applied after any volume authored inside the cue.
- **Presence Sound Pitch Multiplier** — default `1.0`, applied after any pitch authored inside the cue.

A **Sound Cue is recommended** when the project wants layered samples, randomization or additional mix behavior. The framework treats these cues as non-spatial UI/session notifications and plays them only on local recipient controllers. A dedicated server has no local controller and therefore performs no audible presentation work.

### Safety

- **World Chat Max Message Length** — default `220` characters.
- **World Chat Minimum Send Interval** — default `0.65` seconds between accepted messages from one player.
- **World Chat Burst Window Seconds** — default `10` seconds.
- **World Chat Max Messages Per Burst** — default `8` accepted messages inside that window.

Rejected spam/rate-limit attempts are returned only to the sender as a local `SYSTEM` line; they are not broadcast.

### History / presentation

- **World Chat Client History Limit** — default `100` lines retained locally by the widget.
- **World Chat Server History Limit** — default `50` accepted session messages retained by GameMode and delivered once to a late joiner. Set to `0` to disable server history.
- **Show World Chat Timestamps** — optional compact server-UTC `HH:MM` prefix; disabled by default for the cleanest presentation.
- **World Chat Bottom Safe Offset** — native fallback bottom clearance while the framework combat quickbar is enabled; default `176`. This reserves the lower-left chat lane above the centered ability HUD. If the native combat quickbar is disabled, chat uses its compact `30`-unit bottom inset.

Chat history is **session state**, not account persistence. It is intentionally not written to SaveGame.

## 4. Blueprint APIs

`ADMFMMOPlayerController` exposes:

- `Refresh World Chat UI`
- `Open World Chat Input`
- `Close World Chat Input`
- `Toggle World Chat Input`
- `Is World Chat Input Active`
- `Get World Chat Widget`
- `Send World Chat Message`
- `On World Chat Message Received`

`UDMFWorldChatWidget` exposes:

- `Add Chat Message`
- `Set Chat History`
- `Add Local System Message`
- `Clear Chat History`
- `Open Chat Input`
- `Close Chat Input`
- `Is Chat Input Open`
- `Get Visible Message Count`
- `BP_OnWorldChatMessageAdded`
- `BP_OnWorldChatInputStateChanged`

`ADMFMMOGameMode::BroadcastWorldChatPresenceEvent` is also Blueprint-callable on authority for server-owned integrations that need to publish one of the two explicit presence types. Automatic framework login/logout already calls it; clients cannot call it as an owning Server RPC.

`ADMFMMOGameMode::BP_OnWorldChatMessageAccepted` is the server-side extension hook for logging, analytics, guild/channel routing or backend integration. It receives player and presence messages through the same committed server stream.

## 5. Reskinning safely

Create a Widget Blueprint deriving from `DMFWorldChatWidget` and assign it to **World Chat Widget Class**.

The native class has optional bindings for:

- `ChatPanel`
- `MessageScrollBox`
- `MessageList`
- `InputPanel`
- `MessageInput`
- `InputHintText`

A custom Blueprint does not need to implement server RPCs. Keep authority in `ADMFMMOPlayerController`/`ADMFMMOGameMode`; use the widget events only for presentation.

## 6. Care and modal UI interaction

The chat entry cannot open while the character-skin selector, Starter selector, Digimon Menu or Care eating presentation owns focus.

If Care feeding begins while chat is active, chat input closes cleanly and the whole chat panel temporarily hides with the combat HUD so the eating animation remains unobstructed. The chat panel returns afterward with its existing local history intact.

## 7. Host + remote-client acceptance

Run the normal listen host + remote-client test with **two established accounts** and assign obviously different join/leave Sound Cues first:

1. Start Host & Play. Confirm the host receives exactly one `HostUsername has joined the server.` presence row. Its username must be green and the configured join cue must play once locally.
2. Join from the remote account. Confirm **both** host and remote receive exactly one `RemoteUsername has joined the server.` live row and each hears the join cue once.
3. Confirm neither peer can forge a join/leave event by sending chat text; normal text still renders as cyan `Username:` + white body and stays subject to rate limiting.
4. Remote sends `hello from client`; confirm both peers receive one ordinary player message with the server-authored public username.
5. Disconnect the remote client. Confirm the host receives exactly one `RemoteUsername has left the server.` row with red username/red departure text and hears the leave cue once.
6. Reconnect the same account without restarting the host. Confirm the normal v0.18.2 persistent account is restored and both peers receive a fresh green join/relog event exactly once.
7. Disconnect/reconnect several times. Each completed login must produce one join event and each processed logout one leave event; there must be no duplicate announcements from the idempotent persistence fallback.
8. With server history enabled, create several presence/chat rows, then join a late third client. Confirm history includes the retained presence rows but **no historical join/leave sound is replayed**. The late client's own live join may play its join cue once.
9. Toggle **Play Player Join / Leave Sounds** off and repeat. Presence text/color must continue replicating while no presence cue plays. Re-enable audio and clear one sound asset; only the still-assigned event sound should play.
10. Toggle **Announce Player Join / Leave** off and repeat a join/leave. No presence row or presence sound should be generated; ordinary WORLD chat must continue to function.
11. Verify input focus: Enter opens chat, gameplay input is blocked while typing, Escape cancels, rate limiting/sanitation remain server-enforced.
12. Join a third/late client and confirm the configured bounded history arrives once without duplicated final visible rows.
13. Verify WORLD chat remains visually clear of the partner combat quickbar on host/client and at a smaller PIE viewport.
14. Perform Care feeding and confirm chat temporarily hides/restores with its local history intact.
15. Regression-test v0.18.4 player capacity (temporarily cap at 2), v0.18.3 vendor BUY/SELL, same-host reconnect persistence, disconnect partner cleanup, player world-location restore, Return Home, world nameplates, combat, Party/Bank and Digivolution.

## 8. MMO scaling note

This release is appropriate for the framework's current listen-server/session architecture. It deliberately avoids a replicated chat array: each accepted message is one server-to-owner delivery per connected player, while history is transferred only on request/join. A future dedicated-service/backend phase can replace the GameMode fan-out with regional/sharded chat infrastructure without changing the native widget contract.
