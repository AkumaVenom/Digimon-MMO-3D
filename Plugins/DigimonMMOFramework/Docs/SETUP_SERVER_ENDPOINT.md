# Configurable Admin Host / Join Server Endpoint — v0.10.3-alpha

## Purpose

v0.10.2 removes the need to edit `DMFSessionSubsystem.cpp` whenever a project changes its multiplayer host address. The endpoint used by the normal **Join Game** flow is now project deployment configuration.

## Project Settings

Open:

**Edit → Project Settings → Game → Digimon MMO Framework → Networking → Server Endpoint**

Configure:

- **Server Public Address / Hostname** — public/LAN IPv4 address or DNS hostname players should use to reach the admin listen host.
- **Game Port** — port appended to that address by the Join Game flow. Default: `7777`.

The default hostname remains `DigimonMMO3D.custom-gaming.net`, preserving the previous baseline behavior until the consuming project deliberately changes it.

## Accepted address format

Enter the host only. Valid examples:

- `127.0.0.1` — same-machine packaged/standalone testing.
- `192.168.1.50` — LAN host testing.
- `203.0.113.25` — example public IPv4 deployment.
- `game.example.com` — DNS hostname.

Do **not** enter:

- `http://game.example.com`
- `game.example.com:7777`
- `/Game/Maps/OpenWorld`
- `127.0.0.1?listen`

The framework validates this before travel and rejects malformed values rather than allowing project config to inject extra Unreal URL options.

## Host & Play behavior

The Admin workflow remains:

`Login → Admin → unlock admin gate → Host & Play`

As of v0.10.3, the Admin passphrase itself is also configured without C++ under **Networking → Admin Hosting → Set Admin Hosting Password**. See `SETUP_ADMIN_HOSTING.md` for the digest-only persistence contract.

`Host & Play` still opens the configured Open World Map as an authoritative Unreal **listen server**. v0.10.2 additionally validates the project-configured player endpoint before hosting and reports that endpoint in the local frontend status.

**Important:** Server Public Address / Hostname is the address other players use to reach the host; it is not a socket-bind override and it does not configure the router. Unreal's normal NetDriver creates the listen socket. Port forwarding/NAT/firewall/DNS remain deployment responsibilities.

## Join Game behavior

The native Join button does not expose an editable runtime IP field to ordinary players. Instead:

1. the project reads **Server Public Address / Hostname**;
2. validates it;
3. appends **Game Port**;
4. appends the existing account authentication travel options;
5. performs `ClientTravel`.

This keeps players on the project's intended gated endpoint while making the endpoint easy for the game developer to change in Project Settings.

## Config file equivalent

The same deployment can be declared in the consuming project's `DefaultGame.ini`:

```ini
[/Script/DigimonMMOFramework.DMFFrameworkSettings]
ServerPublicAddress=game.example.com
GamePort=7777
```

The included `ConfigTemplates/DMF_Project_DefaultGame.ini.snippet` contains a merge-ready example.

## Multiplayer acceptance

1. Compile the plugin in UE5.8.1.
2. Set `Server Public Address / Hostname` to the endpoint appropriate for the test topology.
3. Start the admin host through the normal gated frontend.
4. Confirm frontend status shows the configured endpoint.
5. Join from a second client/account and verify normal authentication, avatar possession and partner replication.
6. Verify WORLD chat and player/Digimon nameplates still work between both peers.
7. Test a blank/invalid endpoint and confirm clean rejection before travel.
8. Restore the production endpoint and package normally.

## Security / deployment note

A server destination in a game client is not secret. v0.10.2 deliberately treats it as validated deployment configuration rather than source-code obscurity. The existing Admin host gate and server-side account validation remain separate authority controls. For public production deployment, use normal firewall/NAT/DNS hardening and eventually replace the alpha credential transport with a TLS-backed session-ticket service as described in `NETWORKING.md`.
