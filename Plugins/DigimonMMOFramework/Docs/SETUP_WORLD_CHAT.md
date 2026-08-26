# Polished Native World Chat — v0.10.1-alpha

The framework includes a ready-to-use **session-wide WORLD chat** designed for the existing multiplayer-only MMO flow. It is native C++/UMG by default, automatically created for each local gameplay client, Blueprint-reskinnable, and keeps message authority on the server.

## 1. Default player experience

With the default settings:

1. The WORLD chat panel appears in the lower-left gameplay HUD.
2. Press **Enter** to focus the message field.
3. While typing, movement/look/combat input is temporarily blocked so gameplay keys cannot fire abilities or move the avatar.
4. Press **Enter** again to submit the message.
5. The input field closes and gameplay focus returns immediately.
6. Press **Escape** while editing to cancel without sending.
7. Accepted messages appear on the host and every connected client as `Username: message`.

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

The client cannot choose another player's username, timestamp or message type. Credentials and the private owner-only authenticated account field are never placed into chat payloads.

## 3. Project Settings

Open:

**Project Settings → Game → Digimon MMO Framework → UI → World Chat**

### Core

- **Enable World Chat** — master global switch. When false, no native chat widget is created and the server rejects chat submission.
- **Enable Default World Chat Input** — enables the built-in **Enter** binding. Disable this if your project routes input itself and call `OpenWorldChatInput()` from Blueprint.
- **World Chat Widget Class** — defaults to `DMFWorldChatWidget`. Assign a Blueprint child to completely reskin the presentation while retaining framework networking/validation.

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

`ADMFMMOGameMode::BP_OnWorldChatMessageAccepted` is the server-side extension hook for future logging, analytics, guild/channel routing or backend integration.

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

Run the normal two-player PIE test using **listen host + second client**:

1. Confirm both clients show the WORLD panel.
2. Host presses Enter, types `hello from host`, presses Enter again.
3. Confirm both host and client receive exactly one line stamped with the host's authenticated public username.
4. Client sends `hello from client`; confirm both peers receive exactly one line with the client's username.
5. While typing, press movement/look/ability keys and verify the avatar/partner does not execute gameplay commands.
6. Press Escape during a draft and confirm nothing is broadcast and gameplay input returns.
7. Send messages faster than `World Chat Minimum Send Interval`; confirm only the sender sees the rate-limit SYSTEM response.
8. Exceed the configured burst limit; confirm the server rejects excess messages and no other peer sees those rejected texts.
9. Send a message containing line breaks/tabs and a message longer than the maximum; confirm the server delivers one sanitized/clamped line.
10. Join a third/late client and confirm it receives the configured bounded recent session history once.
11. Verify WORLD chat is visually clear of the partner combat quickbar on both host and client; no part of either panel should overlap. Resize the PIE windows and repeat.
12. If the project uses a differently sized native quickbar, adjust **World Chat Bottom Safe Offset** and verify the clearance updates without networking changes.
13. Disable **Enable World Chat**, restart PIE, and confirm no chat UI/input path is active.
12. Re-enable chat, perform Care feeding, and confirm chat temporarily hides and returns afterward.
13. Regression-test world nameplates, Scan/Materialization, combat quick slots and partner replication after chat validation.

## 8. MMO scaling note

This release is appropriate for the framework's current listen-server/session architecture. It deliberately avoids a replicated chat array: each accepted message is one server-to-owner delivery per connected player, while history is transferred only on request/join. A future dedicated-service/backend phase can replace the GameMode fan-out with regional/sharded chat infrastructure without changing the native widget contract.
