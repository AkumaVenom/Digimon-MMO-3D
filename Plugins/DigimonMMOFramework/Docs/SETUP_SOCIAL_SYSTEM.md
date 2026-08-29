# Persistent Social Hub — Friends, Ignore, Nearby Players & Guilds — v0.19.2-alpha

The v0.19.2 Social system is a server-authoritative, persistence-backed multiplayer service integrated into the existing native **DIGIMON MENU**. It is intentionally built as an extensible nested Social shell: **FRIENDS & IGNORE** is the default page the first time Social is opened, **GUILD** is the second page, and future social modules can be added without changing the top-level Digimon menu contract.

## Authority model

Social state is not client-authored PlayerState data. The authenticated account database is the durable source of truth.

- Friends, reciprocal inbound/outbound friend-request bookkeeping, ignore entries, per-friend tracker preferences, guild membership and inbound guild invitations are stored on `FDMFAccountRecord`.
- Guild identity, owner, members and pending applications are stored in the server-owned global `FDMFGuildRecord` registry.
- `UDMFAccountDatabaseSaveGame` schema is **v8**. Existing v7 accounts deserialize with empty social collections and no guild; Party/Bank, Digimon, skin, money, world location and all prior account data are preserved.
- Cross-account operations use `UDMFAccountPersistenceSubsystem::SaveSocialTransaction()`, which applies all related account/guild changes to one SaveGame write and restores the in-memory maps if the disk commit fails. This prevents half-friendships and half-completed guild joins/removals.
- The client submits only an action plus a target username/guild id/text where required. `ADMFMMOGameMode` resolves the acting identity from the authenticated PlayerState and revalidates every relationship, limit and guild role on authority.
- One compact reliable mutation RPC is used behind strongly named Blueprint wrappers. Social snapshots are returned only to the owning player through a reliable Client RPC. Explicit snapshot reads are separately throttled on authority; event-driven server pushes are not delayed.

## Native Social menu

Open the regular **DIGIMON MENU** and select **SOCIAL**. The native shell matches the framework's existing cyan/navy/gold presentation and uses `ScaleToFit / DownOnly` for smaller resolutions.

### FRIENDS & IGNORE

The page contains four clean lists:

**Nearby Players** is the primary discovery surface for adding people without relying on world-nameplate hit testing. The owner-local controller scans already-replicated player avatar actors inside **Nearby Player Friend Discovery Radius** (default `50 m`), excludes the local pawn, deduplicates by public username, and sorts exact distance nearest-to-farthest. The native row displays a rounded integer metre distance and automatically disappears after the player moves outside the configured radius. The panel refreshes at **Nearby Player List Refresh Interval** (default `0.5 s`) only while the Friends Social page is active. This performs no network polling; it reads transforms that Unreal is already replicating for normal gameplay.

Available nearby players expose **ADD FRIEND** plus a dedicated **IGNORE** action. A player who already sent you a request exposes **ACCEPT** plus **IGNORE**; an outgoing request exposes **CANCEL** plus **IGNORE**; accepted friends show disabled **FRIEND** plus **IGNORE**. Already ignored accounts remain physically visible in the nearby list but expose **UNIGNORE** directly. These buttons route through the existing validated server Social mutation endpoint, so the nearby list never becomes an authority source. Ignoring still applies the established persistent relationship cleanup and owner-specific WORLD-chat filtering. Blueprint skins can call `ADMFMMOPlayerController::GetNearbySocialPlayers()` and receive `FDMFNearbySocialPlayerEntry` rows using the same relationship and distance contract.

**Friends** shows accepted persistent friends, their live online/offline state and two actions. **TRACK** enables an owner-local world marker for that individual friend; **HIDE TRACKER** disables it. Removing a friend updates both accounts atomically and removes any tracker preference on both sides.

**Friend Requests** contains persistent inbound requests with **ACCEPT** / **DECLINE** plus outgoing requests with **CANCEL**. Both sides of a pending request are committed atomically, so the nameplate context can show a coherent `CANCEL REQUEST` state instead of letting the sender accidentally submit duplicates. Requests never open modal popups, so combat/exploration is not interrupted and an offline player can review them after reconnecting.

**Ignore List** contains ignored accounts with **UNIGNORE**. Ignoring another account does not hide or destroy their replicated player avatar. It filters that sender's authored `Player` WORLD-chat messages from both live delivery and late-join/session-history hydration for the ignoring player. Ignore also atomically removes friendship/tracking/cross friend requests, outstanding direct guild invitations between those two accounts, and owner-facing join applications between them; future guild invitations/applications are rejected while either account ignores the other. Server-authored join/leave presence is not treated as authored player chat.

## Player-nameplate context menu

The Nearby Players panel is the reliable native discovery path. As an additional optional shortcut, when Social and Player Nameplate Social Context are enabled, clicking an exact remote player nameplate with the left or right mouse button opens an owner-local **PLAYER ACTIONS** menu near the cursor.

Depending on current relationship state it exposes:

- **ADD FRIEND** / **ACCEPT FRIEND** / **CANCEL REQUEST** / **REMOVE FRIEND**, depending on the current relationship/request state
- **IGNORE PLAYER** / **REMOVE IGNORE**
- **INVITE TO GUILD** when the local account owns a guild and the target is not already in that guild

The nameplate menu never mutates state locally. Every action routes through the owning `DMFMMOPlayerController` to server authority. Player nameplate widgets remain normal local presentation built over replicated public `PlayerName`; private authenticated/social account state is never exposed through world replication.

## Friend distance tracking

Each accepted friend can be tracked independently from the Friends page.

The persistent toggle lives on the authenticated account, but the actual tracker is deliberately **client-only**. The owning client attaches a non-replicated screen-space `UDMFFriendTrackerWidget` to the already replicated friend avatar and computes:

`distance metres = round(distance in Unreal centimetres / 100)`

The distance label refreshes locally from replicated actor transforms. There is no distance RPC, no replicated waypoint tick and no server bandwidth cost proportional to tracker refresh rate. If a tracked friend disconnects the component is removed; if they return, the persistent preference recreates the marker automatically after the authoritative Social presence refresh.

Project Settings controls the tracker widget class, vertical offset and sparse reconciliation interval. **UI → Social → Nearby Players** separately controls the global discovery radius and owner-local list refresh interval.

## GUILD

The Guild nested page is persistence-backed and split into three areas: **Your Guild**, **Guild Invites / Join Applications**, and the **Guild Directory**.

### Create / rename / disband

An account with no guild can enter a name and select **CREATE GUILD**. Names are normalized and server validated for configured length, allowed characters and case-insensitive uniqueness. The creator becomes the owner and first member.

The owner can edit the same name field and choose **RENAME**. Guild members cannot rename it. The owner cannot silently leave an ownerless guild; the native action is **DISBAND**, which atomically clears membership from affected accounts and invalidates invitations to the removed guild.

### Invite another player

The guild owner can click a remote player's world nameplate and choose **INVITE TO GUILD**. The invitation is persisted on the target account. It appears in **GUILD INVITES** after the target opens Social or reconnects, where it can be accepted or declined without a popup.

Acceptance revalidates that the guild still exists, has capacity and that the target has not already joined another guild, then commits account membership and the guild roster together.

### Guild directory / applications

The directory lists the persistent guild registry with guild name, owner and current member count. The local search field filters by guild or owner name without generating server RPC traffic. Public directory identity/member-count mutations (create, rename, accepted membership changes, leave/remove and disband) push freshly built owner-specific Social snapshots to all currently authenticated players, and switching nested Social pages also requests a throttled fresh snapshot. This keeps an already-open Guild directory coherent without exposing another account's private Social data.

A player who is not currently in a guild can select **APPLY**. The application is stored on the guild record, so the owner can be offline when it is submitted. On the owner's next login/relog the request is available in the **JOIN APPLICATIONS** list for **ACCEPT** or **DECLINE**.

The owner can remove non-owner members from the member roster. Normal members can **LEAVE GUILD**. Every mutation is revalidated against the latest server record at execution time.

## Project Settings

Open **Project Settings → Game → Digimon MMO Framework**.

Under **UI → Social**:

- **Enable Social System** — master switch, default `true`.
- **Enable Player Nameplate Social Context** — enables click-to-open player actions, default `true`.
- **Player Social Context Widget Class** — Blueprint-reskinnable native dropdown class.
- **Friend Tracker Widget Class** — Blueprint-reskinnable owner-local tracker class.
- **Friend Tracker Height Offset** — extra height above the normal player nameplate, default `64 uu`.
- **Friend Tracker Reconcile Interval** — default `0.75 s`; this only reconciles tracked friend components, not distance networking.

Under **Social → Limits / Guild**:

- **Minimum Social Action Interval** — authority-side mutation throttle, default `0.15 s`.
- **Minimum Social Snapshot Request Interval** — throttles explicit client refresh requests without delaying server-pushed relationship/presence updates, default `0.35 s`.
- **Maximum Friends Per Account** — default `200`.
- **Maximum Ignored Players Per Account** — default `200`.
- **Maximum Guild Members** — default `100`, including the owner.
- **Maximum Pending Guild Invites Per Account** — default `100`; prevents unbounded persistent offline invite growth.
- **Maximum Pending Guild Applications Per Guild** — default `500`; prevents an unbounded persistent application queue.
- **Minimum Guild Name Length** — default `3`.
- **Maximum Guild Name Length** — default `32`.

## Blueprint API

`DMFMMOPlayerController` exposes strongly named wrappers so custom UI never needs to manually construct the generic RPC payload: `RequestSocialSnapshot`, `RequestAddFriend`, `RespondToFriendRequest`, `RequestCancelFriendRequest`, `RequestRemoveFriend`, `RequestSetFriendTracking`, `RequestIgnorePlayer`, `RequestRemoveIgnoredPlayer`, `RequestCreateGuild`, `RequestRenameGuild`, `RequestInvitePlayerToGuild`, `RespondToGuildInvite`, `RequestApplyToGuild`, `RespondToGuildApplication`, `RequestRemoveGuildMember`, `RequestLeaveGuild`, `RequestDisbandGuild`, `OpenPlayerSocialContext`, `ClosePlayerSocialContextUI`, `RefreshFriendTrackingPresentation`, and `OpenSocialUI`.

`GetCachedSocialSnapshot()` provides the latest owner-only view. `OnSocialSnapshotChanged` is broadcast after a new authoritative snapshot arrives and `OnSocialActionResult` reports the reliable mutation result. The native Digimon menu consumes the same API and can therefore be replaced by a Blueprint child without replacing authority.

## Runtime acceptance checklist

Use at least a listen host plus two distinct remote/account sessions where practical.

1. Open **I → SOCIAL** on a fresh account. Confirm **FRIENDS & IGNORE** is selected the first time and switching to/from GUILD does not affect Party/Bank/Care/etc.
2. Click another player's exact nameplate and send a friend request. Confirm no modal popup appears; the sender sees the outgoing request with CANCEL / `CANCEL REQUEST`, the target sees the incoming request with Accept/Decline, cancellation removes both sides, and acceptance updates both friend lists reliably.
3. Accept, reconnect one or both accounts, and confirm friendship persists. Remove the friend and confirm removal is symmetric after reconnect.
4. Toggle TRACK for an online friend. Confirm only the owning player sees the green friend marker and integer `m` distance, distance changes while either player moves, the peer does not see your tracker, and reconnect restores the preference.
5. Ignore a player. Confirm their avatar remains normally visible/replicated but their authored WORLD chat is absent live and absent from hydrated history for the ignoring account. Unignore and confirm new messages become visible again.
6. Create a guild; verify unique name validation and persistence. Rename it as owner; verify a normal member cannot rename.
7. Owner nameplate-invites another player. Confirm the invitation appears as a queued Social/Guild item, survives target relog, and accept/decline works without popup spam.
8. From a third account, find the guild in the directory and APPLY. Disconnect the guild owner before/after applying, reconnect owner, and confirm the persistent application is still listed for review.
9. Accept the application; verify both account GuildIds and the guild member roster persist after reconnect. Remove a member as owner, and test normal-member Leave.
10. Disband as owner; verify all affected account memberships and stale invitations are cleared and the guild disappears from directory search.
11. Spam Social actions faster than the configured action interval and confirm the server rejects the excess without corrupting state.
12. Regression test v0.18.5 WORLD presence/audio, v0.18.4 capacity, authenticated reconnect, disconnect persistence, Party/Bank, vendor economy/UI, world location, Return Home, combat, Day/Night, swimming/underwater, DigiDex, Digivolution and Care.
