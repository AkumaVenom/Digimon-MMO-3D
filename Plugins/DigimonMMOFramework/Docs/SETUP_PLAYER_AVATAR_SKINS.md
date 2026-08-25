# Player Avatar / Character Skin Setup — UE5.8

## What v0.3.0 provides

The framework now supplies a ready-to-use replicated third-person MMO pawn: `ADMFPlayerAvatarCharacter`.

It is deliberately separated into two concepts:

- **Authoritative pawn/gameplay:** `ADMFPlayerAvatarCharacter` (movement, camera, collision, possession, replication).
- **Visual skin:** `UDMFPlayerSkinData` (skeletal mesh, AnimBP, mesh transform, materials, portrait/display metadata).

Changing a skin never replaces the authoritative pawn class. That avoids possession churn, replicated inventory ownership problems and skin-specific gameplay exploits.

`UDMFPlayerAvatarComponent` lives on `ADMFPlayerState`, validates skin requests on the server, persists the selected `FPrimaryAssetId`, replicates it to every client and asks the current avatar pawn to apply the corresponding visual Data Asset.

## Ready-to-use third-person controls

`ADMFPlayerAvatarCharacter` has native fallback input so a Blueprint child is playable without creating Input Actions first:

- `W/A/S/D` — movement
- Mouse X/Y — third-person camera look
- `Space` — jump
- `Left Shift` — replicated sprint
- `C` — crouch
- Gamepad left stick — movement
- Gamepad right stick — look

Set `bEnableNativeThirdPersonInput=false` on your Blueprint child if the project replaces this with Enhanced Input.

The framework MMO PlayerController also provides:

- `F6` — open/close the character skin menu after onboarding
- `OpenPlayerSkinSelectionUI`
- `ClosePlayerSkinSelectionUI`
- `TogglePlayerSkinSelectionUI`
- `RefreshPlayerSkinSelectionUI`

Disable `bEnableDefaultPlayerSkinMenuInput` in Project Settings if your own HUD/button opens the wardrobe instead.

## Recommended Blueprint pawn

1. Content Browser → **Add → Blueprint Class → All Classes**.
2. Search for `DMFPlayerAvatarCharacter`.
3. Create `BP_DMFPlayerAvatarCharacter`.
4. Use this Blueprint as the `Default Pawn Class` of your Blueprint derived from `DMFMMOGameMode`.
5. Do not hard-assign one of the selectable character meshes to the Blueprint unless you specifically want a fallback visual. The selected skin Data Asset will drive the inherited Character mesh.
6. Camera boom, follow camera, movement speeds and native-input toggle are exposed in Class Defaults.

The C++ `DMFMMOGameMode` already defaults to `ADMFPlayerAvatarCharacter`, so the framework remains functional even before you create the Blueprint child.

## Asset Manager setup

Merge the current `ConfigTemplates/DMF_Project_DefaultGame.ini.snippet` into your project config, or add the equivalent entry in **Project Settings → Game → Asset Manager**:

- Primary Asset Type: `DMFPlayerSkin`
- Base Class: `DMFPlayerSkinData`
- Directory: `/Game/DigimonData`
- Has Blueprint Classes: false
- Editor Only: false
- Cook Rule: `Always Cook`

Recommended directory:

`/Game/DigimonData/PlayerSkins`

The selector does not need a separate roster asset. It asks `UAssetManager` for every registered `DMFPlayerSkin`, loads enabled definitions, sorts by `DisplayOrder`, and builds the menu automatically.

## Your seven Digimon character skins

The supplied project screenshot shows these seven player folders under `/Game/MAIN/VPET/3D/Player`:

1. Izzy
2. Joe
3. Matt
4. Mimi
5. Sora
6. Tai
7. TK

Create these Data Assets under `/Game/DigimonData/PlayerSkins`:

- `DA_PlayerSkin_Izzy`
- `DA_PlayerSkin_Joe`
- `DA_PlayerSkin_Matt`
- `DA_PlayerSkin_Mimi`
- `DA_PlayerSkin_Sora`
- `DA_PlayerSkin_Tai`
- `DA_PlayerSkin_TK`

For each asset choose **Miscellaneous → Data Asset → DMFPlayerSkinData** and configure:

### Identity

- `Skin Id`: stable key such as `Tai`
- `Display Name`: `Tai`
- `Description`: optional UI text

### Availability

- `Enabled`: true
- `Display Order`: 0–6 in your preferred order

### Presentation

- `Skeletal Mesh`: select the correct mesh from that character's existing `/Game/MAIN/VPET/3D/Player/<Name>` folder
- `Anim Class`: the matching Animation Blueprint if that mesh needs one
- `Mesh Relative Transform`: correct any imported rotation/height/scale relative to the Character capsule
- `Material Overrides`: optional skin-specific material replacements

### UI

- `Portrait`: optional character portrait for a custom polished selector

Once saved, the native selector discovers it automatically. There is no `PlayerSkins` array to maintain.

## First-time onboarding order

With `bRequirePlayerSkinSelection=true` (default):

`Login -> Join/Host -> account load -> Character Skin Selection -> Starter Digimon Selection -> gameplay + combat UI`

The skin selector has modal priority over the Starter Digimon UI. A new account cannot close the character selector until the server accepts a valid enabled skin. After that, starter onboarding proceeds automatically.

Existing v0.2.x accounts have no player skin field in their old save data, so after upgrading to v0.3.0 they are asked to choose a skin once. Their Digimon inventory/starter data is not reset.

## Changing skin later

Press `F6` during normal gameplay, or call `OpenPlayerSkinSelectionUI` on `DMFMMOPlayerController` from any Blueprint HUD/menu button.

Flow:

`Local UI preview -> ServerSetPlayerSkin -> server Asset Manager validation -> enabled/mesh validation -> persistent account update -> SelectedPlayerSkinId replication -> every client applies the same mesh/AnimBP/material definition`

The player's location, controller, possession, inventory, active Digimon, combat ownership and pawn identity remain unchanged.

## Blueprint-first UI replacement

`UDMFPlayerSkinSelectionWidget` is Blueprintable. Assign your subclass to:

**Project Settings → Game → Digimon MMO Framework → Player Skin Selection Widget Class**

Optional bind-widget names:

- `PlayerSkinChoicesBox` (`VerticalBox`)
- `PlayerSkinDetailsText` (`TextBlock`)
- `ApplyPlayerSkinButton` (`Button`)
- `ClosePlayerSkinButton` (`Button`)

If you do not build a custom widget, the native fallback constructs a fully functional UI automatically.

Blueprint events:

- `BP_OnPlayerSkinPreviewChanged(SkinData)` — ideal for a rotating 3D preview actor/scene
- `BP_OnPlayerSkinSelectionResult(bSuccess, Message, SkinData)`
- `ADMFPlayerAvatarCharacter::BP_OnPlayerSkinApplied(SkinData)`
- `ADMFPlayerAvatarCharacter::BP_OnPlayerSkinRefreshRequested()`

## Server-authority rules

The client never sends a skeletal mesh/class/material path as trusted state. It only requests a `DMFPlayerSkin` Primary Asset ID.

The server rejects requests when:

- the ID is not a registered `DMFPlayerSkin`;
- the Data Asset cannot be resolved;
- the skin is disabled;
- no skeletal mesh is assigned.

Only the accepted stable Primary Asset ID is persisted and replicated.

## Multiplayer acceptance check

1. Host with account A and choose Tai.
2. Join from PC/client B and choose Mimi.
3. Confirm both machines see A as Tai and B as Mimi.
4. Press F6 on B and switch Mimi → Matt.
5. Confirm A sees B change to Matt without B respawning or losing the active partner.
6. Disconnect/reconnect B and confirm Matt loads automatically.
7. Restart host and reconnect both accounts; selections must still be Tai/Matt.
8. Disable Matt's `DMFPlayerSkinData`, reconnect/switch, and verify the server no longer accepts that skin.
## Cel-shading Custom Depth

`ADMFPlayerAvatarCharacter` now treats Custom Depth as a framework invariant. You do **not** need to enable **Render CustomDepth Pass** manually on Tai, Matt, Mimi, Sora, Izzy, Joe or TK. The framework forces it on for every avatar `UMeshComponent` during construction/BeginPlay and reasserts it after every skin swap.

- `CustomDepthStencilValue` is exposed on the avatar Blueprint (0-255; default 0).
- `RefreshFrameworkCustomDepth()` is Blueprint-callable if your project dynamically creates/replaces an additional mesh component after BeginPlay.
- The project-level Unreal **Custom Depth-Stencil Pass** rendering setting must still be enabled for your post-process cel shader to read CustomDepth.

