# World Nameplates Setup — v0.9.1-alpha

The v0.9.0 world-nameplate layer (compile-hardened for UE5.8.1/MSVC in v0.9.1) is a native, automatic MMO presentation system for replicated player avatars and Digimon. No per-Blueprint Widget Component setup is required when the project derives its avatars from `ADMFPlayerAvatarCharacter` and its Digimon from `ADMFDigimonCharacter`.

## Presentation goals

- Player avatars display a compact authenticated username above the character.
- The locally controlled player's own username plate is hidden by default to reduce screen clutter.
- Digimon display a compact identity line, `Level • Stage • Attribute`, and a slim replicated HP bar/readout.
- Nameplates use Screen-space Widget Components so text remains camera-facing and readable while the actors move normally through the 3D world.
- The native fallback follows the same dark navy / cyan / gold presentation language as the framework's main Digimon Menu and combat HUD.
- The system is presentation-only. It reads normal replicated state and creates no per-nameplate gameplay RPC traffic.

## Global project settings

Open **Project Settings → Game → Digimon MMO Framework → UI → World Nameplates**.

### Master

- `Enable World Nameplates` — master switch for the complete overhead UI layer.
- `World Nameplate Refresh Interval` — throttles native text/HP presentation refresh. Default: `0.15 s`.

### Players

- `Enable Player Nameplates` — independently enables/disables username plates.
- `Show Local Player Nameplate` — off by default; enable only when the local player's own plate is desired.
- `Player Nameplate Max Draw Distance` — default `6000 uu`; set `0` to disable distance culling.
- `Player Nameplate Height Offset` — additional height above the avatar capsule, default `34 uu`.
- `Player Nameplate Widget Class` — optional Blueprint child of `DMFWorldNameplateWidget` for complete visual reskinning.

### Digimon

- `Enable Digimon Nameplates` — independently enables/disables Digimon plates.
- `Digimon Nameplate Max Draw Distance` — default `4500 uu`; set `0` to disable distance culling.
- `Digimon Nameplate Height Offset` — additional height above each Digimon capsule, default `24 uu`. Because the base capsule height is included automatically, differently sized species remain much easier to align.
- `Show Digimon Numeric Health On Nameplates` — disable this for an even smaller HP-bar-only plate.
- `Digimon Nameplate Widget Class` — optional Blueprint child of `DMFWorldNameplateWidget`.

## Player username replication contract

`AuthenticatedUsername` remains owner-only account state. v0.9.0 mirrors only the authenticated username into Unreal's normal public `APlayerState::PlayerName` display-name channel on the authoritative server. Other clients therefore receive the one value required for MMO identity presentation without receiving credentials, credential digests, private inventory, Care state or Scan Data.

A remote avatar's native plate reads `PlayerState->GetPlayerName()`. If that state has not arrived yet during join replication, the plate safely refreshes until the replicated display name is available.

## Digimon data displayed

The native Digimon plate reads:

- `ReplicatedNickname` when an owned instance has a nickname; otherwise species `DisplayName`.
- `ReplicatedStats.Level`.
- species `Stage`.
- species `Attribute`.
- authoritative/replicated Combat Component `CurrentHP` against `ReplicatedStats.MaxHP`.

Health color is intentionally glanceable without becoming a large raid-frame UI: healthy is green, mid-health is gold and critical health is red.

## Blueprint reskinning

`UDMFWorldNameplateWidget` is Blueprintable. Assign a Blueprint child through the Player or Digimon global widget-class setting rather than replacing the actor-side logic.

Optional native bindings are:

- `NameplatePanel`
- `NameText`
- `MetaText`
- `DigimonVitalsBox`
- `HealthProgressBar`
- `HealthText`

The widget also exposes:

- `SetObservedActor`
- `RefreshPresentation`
- `GetObservedActor`
- `BP_OnNameplateRefreshed`

`ADMFPlayerAvatarCharacter` and `ADMFDigimonCharacter` both expose `RefreshWorldNameplate()` for projects that change runtime settings or presentation after BeginPlay.

## MMO test checklist

1. Start a two-player PIE session using the same host + remote-client flow used for the framework's previous multiplayer acceptance tests.
2. Confirm Host sees Client's authenticated username above Client's avatar.
3. Confirm Client sees Host's authenticated username above Host's avatar.
4. Confirm each local player does **not** see their own username unless `Show Local Player Nameplate` is enabled.
5. Confirm both owned partners show name, level, stage, attribute and HP.
6. Damage a Digimon and confirm its health bar/readout changes on both host and remote client from replicated combat vitals.
7. Confirm wild Digimon receive the same compact Digimon plate automatically.
8. Walk beyond the configured max-draw distances and confirm the nameplates cull.
9. Toggle `Enable Player Nameplates`, `Enable Digimon Nameplates`, and the master `Enable World Nameplates` between PIE sessions to validate each global gate.
10. Re-run Scan/Materialization, Care feeding/poop, targeting and quick-slot combat to confirm no regression.

## Dedicated-server note

Widget presentation is disabled on dedicated-server instances. The server still owns authentication, Digimon state and combat normally; connected clients construct their own local nameplate presentation from replicated state.

## Canonical Digivolution stage labels (v0.15.3)

Digimon world nameplates read the stage directly from the resolved `DMFDigimonSpeciesData::Stage`. Native presentation then passes that value through `Get Digimon Stage Display Text`, so runtime/cooked builds always show canonical labels (`Fresh`, `In-Training`, `Rookie`, `Champion`, `Ultimate`, `Mega`, `Ultra`, `Armor`, `Hybrid`, `Unknown`) rather than serialized enum identifiers such as `BabyI`. Configure the **Stage** on each Species Data Asset; do not duplicate stage text in a nameplate Blueprint.

## v0.19.1 Nearby Players fallback

Friend discovery no longer depends on nameplate hit testing. **DIGIMON MENU → SOCIAL → FRIENDS & IGNORE → NEARBY PLAYERS** lists replicated players inside the globally configured radius nearest-first and routes ADD/ACCEPT/CANCEL through the same server-authoritative Social actions. Nameplate context remains an optional shortcut when a project wants clickable world labels.

## v0.19.0 player Social context

When **Enable Social System** and **Enable Player Nameplate Social Context** are enabled, remote player nameplates become mouse-hit-testable owner-local presentation. Left- or right-clicking the exact nameplate opens `DMFPlayerSocialContextWidget` near the cursor with relationship-aware Friend, Ignore and guild-owner Invite actions. The context widget routes requests through the owning `DMFMMOPlayerController`; the world widget does not own social authority.

Tracked-friend distance markers are separate non-replicated screen-space Widget Components placed above the normal player nameplate. They use the remote avatar's already replicated transform and can be independently toggled from **SOCIAL → FRIENDS & IGNORE**. See `SETUP_SOCIAL_SYSTEM.md`.
