# Frontend Background & Bootstrap Presentation

v0.15.0 gives the framework one deterministic owner for the local frontend stack: `ADMFFrontendHUD`. The consuming project selects a background Widget Blueprint in Project Settings; the framework creates that background first and then creates the Digimon MMO login/main-menu layer above it.

This is presentation sequencing only. Login, Join Game, Admin unlock, Host & Play, server authentication, travel validation and persistence remain unchanged.

## Recommended setup

1. Create a Widget Blueprint for the frontend background, for example `WBP_MainMenuBackground`. It may contain images, animated materials, media, particles implemented in UMG, logos, animations, or any other local presentation.
2. Open **Project Settings -> Game -> Digimon MMO Framework -> UI -> Frontend**.
3. Set **Frontend Background Widget Class** to `WBP_MainMenuBackground`.
4. Keep **Show Native Frontend Fullscreen Backdrop** disabled unless a deliberate dim layer is desired.
5. Set **Frontend UI Startup Delay Seconds** to the presentation gap you want between background initialization and login-card appearance. `0.25` is the default; `1.0` is useful while testing.
6. Leave the framework to create both layers. **Remove any old Level Blueprint `Create Widget -> Add To Viewport` path for this same background widget.** Creating it twice defeats the deterministic layer contract.

No Blueprint Z-order is required. The framework owns that relationship automatically.

## Project Settings

### Frontend Background Widget Class

Default: unset

Optional project-authored `UUserWidget` class created locally by `ADMFFrontendHUD` before the login/main-menu widget. If unset, the map/world remains the background and the framework proceeds normally.

The background uses the same game viewport layer as the login widget and is always inserted **100 Z-order units below** the login/main-menu layer. This prevents a full-screen background from covering the login card.
Both layers deliberately use `AddToViewport`. Do not mix a separately-created `AddToPlayerScreen`/`AddToViewport` copy of the same background into the stack; the framework owns the two-layer ordering.

The background class is presentation-only. It must not be used to decide credentials, Admin authorization, hosting permission, account ownership, or any other trusted gameplay state.

### Frontend UI Startup Delay Seconds

Default: `0.25`

Time between successful background initialization and creation of the framework login/main-menu layer. If no Background Widget Class is assigned, the delay begins as soon as the local frontend PlayerController becomes available.

Use `0` for immediate overlay, `0.15`-`0.50` for a quick polished reveal, or a larger authored value when the background has an intro animation.

### Show Native Frontend Fullscreen Backdrop

Default: `False`

The native fallback previously painted a dark full-screen tint behind the login card. It stays disabled by default so the selected background remains visually untouched. Enabling this option restores an optional dim layer.

### Native Frontend Backdrop Opacity

Default: `0.34`

Used only when the optional native backdrop is enabled.

### Frontend Login/Menu Viewport Z Order

Default: `1000`

Z-order of the framework login/main-menu widget. The background Z-order is calculated automatically as:

`Background Z-order = Login/Menu Z-order - 100`

Do not manually add the selected background elsewhere at another Z-order.

## Deterministic bootstrap order

The local frontend sequence is:

1. `ADMFFrontendHUD::BeginPlay`
2. Resolve a valid local PlayerController (0.10 s reliability retry if needed)
3. Create `Frontend Background Widget Class` if assigned
4. Add background to game viewport below the login layer
5. Start `Frontend UI Startup Delay Seconds`
6. Create the configured `LoginWidgetClass`
7. Add login/main-menu above the background
8. Focus the login widget and enable the mouse cursor

The startup delay and PlayerController reliability retry are separate timers. A delayed controller cannot consume or repeatedly restart the authored presentation delay.

## Failure safety

A project background is decorative. If its class cannot be created or added to screen, the HUD logs the problem and still continues to the login/main-menu layer. A broken optional background can therefore never make the frontend unusable.

Both frontend widgets and all bootstrap timers are cleaned up on `EndPlay`, including travel away from the frontend map.

## Native fallback layering contract

The pure-native `UDMFLoginMainMenuWidget` remains an overlay card rather than a forced full-screen paint layer:

- central Digimon MMO login/play/admin card keeps its styled panel;
- native dark fullscreen backdrop is absent by default;
- native root is `SelfHitTestInvisible`;
- optional decorative backdrop is `SelfHitTestInvisible`;
- interactive login-card descendants remain hit-testable.

## Blueprint LoginWidgetClass

A Blueprint subclass assigned to `LoginWidgetClass` still receives the same framework-owned foreground Z-order and startup sequencing. If that custom login widget contains its own full-screen opaque Designer background, that is part of the foreground widget and can cover the selected background by design; remove such a full-screen paint layer if you want the project background visible around the card.

## Multiplayer / authority

Frontend background presentation is local-only and adds no replication or RPC. The new class setting does not change:

- credential staging;
- Join Game endpoint validation;
- Admin unlock;
- Host & Play listen-server creation;
- server `PreLogin` authentication;
- account persistence;
- gameplay travel.

## Acceptance test

1. Remove the old Main Menu Level Blueprint path that manually creates the same background widget.
2. Assign `WBP_MainMenuBackground` to **Frontend Background Widget Class**.
3. Set `Frontend UI Startup Delay Seconds = 1.0` temporarily.
4. Keep **Show Native Frontend Fullscreen Backdrop = False**.
5. Start PIE/Standalone.
6. Confirm exactly one background widget appears first.
7. After roughly one second, confirm the Digimon MMO login card appears visibly above the full-screen background.
8. Confirm username/password, Login, Join Game, Admin, Logout and Quit still work.
9. Confirm travel away from the Frontend Map removes both background and login widgets.
10. Set the final delay, commonly `0.15`-`0.50`, and repeat in a packaged build.
