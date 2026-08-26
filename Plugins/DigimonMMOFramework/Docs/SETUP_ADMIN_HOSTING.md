# Admin Host & Play Password — v0.10.3-alpha

## Purpose

The framework keeps **Host & Play** behind a separate Admin unlock so a normal logged-in player cannot start the authoritative listen-host flow from the native frontend. v0.10.3 moves the Admin password configuration into Project Settings so consuming projects do not need to edit plugin C++.

## Configure the password

Open:

**Edit → Project Settings → Game → Digimon MMO Framework → Networking → Admin Hosting**

Use **Set Admin Hosting Password** and enter a project-specific value between **4 and 128 characters**.

The field is intentionally temporary. When the Project Settings change is applied, the framework:

1. hashes the entered password using the framework credential utility;
2. stores only the resulting `AdminHostingPasswordDigest` in `Config/DefaultGame.ini`;
3. clears the plaintext Project Settings field immediately.

The previous built-in Admin digest remains the class default only for upgrade compatibility. Existing projects therefore keep working after replacing v0.10.2 with v0.10.3, but new/public deployments should deliberately set their own password before packaging.

## Runtime flow

The native frontend remains:

`Login → Admin → enter Admin password → Unlock Admin → Host & Play`

`UnlockAdmin` hashes the locally entered candidate password and compares it with the configured digest. The raw Admin password is not stored in `UDMFSessionSubsystem`, is never appended to network travel options, is not replicated, and is not written into account SaveGame data.

If the configured digest is malformed, the gate fails closed and tells the developer to set the password again in Project Settings.

## Security boundary

This password protects the **local frontend hosting control**. It is not remote administrator authentication and should not be treated as a secret backend credential. A packaged client necessarily contains executable/configuration data that determined users can inspect. For an internet-scale production MMO, privileged operations should ultimately be authorized by a server/backend identity and permission service.

The framework's gameplay authority remains independent of this UI gate: server account validation, Server RPC validation, replicated gameplay state and Unreal listen-server authority continue to control gameplay.

## Multiplayer acceptance test

1. Set a new Admin Hosting Password in Project Settings. Confirm the setter field clears after the change is applied.
2. Compile and restart the editor once to confirm the setting persisted.
3. Login from the frontend, open **Admin**, enter an incorrect password and confirm **Host & Play** remains unavailable.
4. Enter the new configured password and confirm Admin unlock succeeds.
5. Start **Host & Play** and confirm the configured open-world map runs as `NM_ListenServer`.
6. Join from a second client using the configured Server Endpoint and confirm normal player joining/account progression is unchanged.
7. Re-run world chat, nameplate, Care, Scan/Materialization and combat smoke tests to confirm this configuration-only gate change introduced no gameplay regression.
