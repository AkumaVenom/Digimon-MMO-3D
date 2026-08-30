# Player Item Inventory + Recovery Capsules Setup — v0.20.0-alpha

## 1. What v0.20.0 provides

The framework now provides a persistent per-account item bag, owner-only Fast Array replication, native **DIGIMON MENU → ITEMS** UI and server-authoritative item use. The first built-in effects are HP and SP restoration. Item behavior is authored through `UDMFItemData`, so the six capsule sizes are content assets rather than six C++ classes.

The client never decides how much a capsule heals. It selects an owned stack and an owned Digimon; authority resolves the item asset and all gameplay values again before committing anything.

## 2. Asset Manager rule

Merge the following line into the project's existing `[/Script/Engine.AssetManagerSettings]` section (the plugin ConfigTemplates snippet already includes it):

```ini
+PrimaryAssetTypesToScan=(PrimaryAssetType="DMFItem",AssetBaseClass="/Script/DigimonMMOFramework.DMFItemData",bHasBlueprintClasses=False,bIsEditorOnly=False,Directories=((Path="/Game/DigimonData")),SpecificAssets=,Rules=(Priority=-1,ChunkId=-1,bApplyRecursively=True,CookRule=AlwaysCook))
```

Keep item assets under `/Game/DigimonData` or deliberately change the scan directory in the project rule. Packaged server and client builds must cook the same gameplay item definitions.

## 3. Create the six capsule Data Assets

In the Content Browser: **Add → Miscellaneous → Data Asset → DMFItemData**. Create these six assets. The restore values below are sensible initial tuning examples only; change them to match your final progression curve.

| Suggested asset | Item Id | Effect | Suggested Restore Amount | Max Stack | Defeated target |
|---|---|---:|---:|---:|---|
| `DA_Item_HP_Capsule_Small` | `Item_HP_Capsule_Small` | Restore HP | 100 | 99 | No |
| `DA_Item_HP_Capsule_Medium` | `Item_HP_Capsule_Medium` | Restore HP | 500 | 99 | No |
| `DA_Item_HP_Capsule_Large` | `Item_HP_Capsule_Large` | Restore HP | 2000 | 99 | No |
| `DA_Item_SP_Capsule_Small` | `Item_SP_Capsule_Small` | Restore SP | 50 | 99 | No |
| `DA_Item_SP_Capsule_Medium` | `Item_SP_Capsule_Medium` | Restore SP | 250 | 99 | No |
| `DA_Item_SP_Capsule_Large` | `Item_SP_Capsule_Large` | Restore SP | 1000 | 99 | No |

For each asset set:

- **Identity → Item Id**: unique and stable; do not reuse an ID for a different item.
- **Identity → Display Name / Description / Icon**: presentation used by the native ITEMS page and future shops.
- **Inventory → Category**: `Consumable`.
- **Inventory → Max Stack Size**: for example `99`.
- **Use → Consumable**: enabled.
- **Use → Use Effect**: `Restore HP` or `Restore SP`.
- **Use → Restore Amount**: the amount restored by one capsule.
- **Use → Requires Living Digimon**: enabled for normal recovery capsules.
- **Use → Can Restore Defeated Digimon**: disabled for normal HP capsules so revival remains a separate mechanic.
- **Economy → Suggested Buy Price / Suggested Sell Price**: used by the v0.21.0 replicated Item Vendor Exchange as canonical base economy values. The vendor still derives and validates every actual transaction on the server; see `SETUP_ITEM_VENDOR.md`.
- **Presentation → Sort Priority**: lower values appear first. A simple convention is HP Small/Medium/Large `100/110/120`, SP Small/Medium/Large `200/210/220`.

## 4. Inventory capacity

Project Settings → **Game → Digimon MMO Framework → Items → Inventory → Max Player Item Stacks** defaults to **60**. This counts stacks, not total individual items. Existing saved bags are never destructively truncated if a server later lowers the configured capacity; new grants simply cannot create additional stacks until capacity is available.

## 5. Giving an item to a player

`UDMFPlayerDigimonComponent::GrantItem` is intentionally `BlueprintAuthorityOnly`. Use it from a server-owned gameplay path such as a quest/reward actor, authoritative loot pickup, GameMode service, future item vendor or admin/test actor. Pass the item's `GetPrimaryAssetId()` and quantity.

The function is all-or-nothing: it first checks existing partial stacks plus free stack slots. If the complete requested quantity cannot fit, it returns false and changes nothing. On success it fills matching partial stacks first, creates server GUIDs for new stacks, owner-replicates the delta and checkpoints persistence.

For a temporary PIE test, a server-authoritative Blueprint actor can resolve the desired `DMFItemData`, obtain the target player's `DMFPlayerDigimonComponent`, and call **Grant Item** after that player's authenticated account has initialized. Do not create an unrestricted client-facing debug grant RPC.

`RemoveItem` is the corresponding authority-only integration hook. `GetTotalItemQuantity`, `GetItemInventory` and `ResolveItemData` are safe read/query surfaces.

## 6. Using capsules in the native menu

Open the normal Digimon Menu (`I` by default) and select **ITEMS**, or call `ADMFMMOPlayerController::OpenItemsUI()`.

1. Select an item stack on the left.
2. Select one active-Party Digimon on the right. The panel shows current/max HP and SP.
3. Press **USE ON SELECTED DIGIMON**.
4. Authority validates the stack, asset, target ownership, defeated policy and relevant current/max stat.
5. On success exactly one item is consumed, only the missing HP/SP is restored, Party state is updated and the account is saved.

The native selector intentionally targets the active Party because recovery items are field-use consumables. The server implementation can safely resolve an owned Bank target as well, which leaves room for project-specific Blueprint UI or later storage/shop workflows without changing the authority contract.

Full HP/full SP, invalid/stale stacks, invalid targets, non-consumables and defeated targets disallowed by the item definition are rejected without consuming anything.

Item use is also rejected while the owning account is inside an active **Care** or **Digivolution** sequence. Those systems already act as persistent mutation transactions, so v0.20.0 does not allow an item use to interleave with them. Normal combat is intentionally not a blanket lock: recovery capsules may be used during battle when the target/effect is otherwise legal.

## 7. Summoned partner behavior

When the selected Digimon is the currently summoned partner, its persistent Party vitals are kept synchronized with the live combat component. After a valid capsule transaction the server pushes the committed HP/SP back into that combat component through `ApplyAuthoritativeRuntimeVitals`. This does **not** respawn the partner or reset its target, encounter latch, cooldowns, queued combat intent, automation or movement. Normal existing combat replication publishes the resulting live vitals.

## 8. Blueprint-reskinned ITEMS page

`UDMFDigimonInventoryWidget` remains the common UI authority-neutral shell. Custom Blueprint children may optionally bind:

- `ItemsTabButton`
- `ItemInventoryGrid`
- `ItemInventoryCountText`
- `ItemSelectedIcon`
- `ItemSelectedNameText`
- `ItemSelectedMetaText`
- `ItemSelectedDescriptionText`
- `ItemUseStatusText`
- `ItemTargetGrid`
- `UseSelectedItemButton`

Useful events are `BP_OnItemSelectionChanged` and `BP_OnItemUseResult`. `RefreshItemInventoryData()` is callable for custom presentation refresh. These are UI hooks only; custom widgets should still use `ServerUseItem` rather than locally editing quantities or Digimon vitals.

## 9. Item shops and other systems

The v0.20.0 foundation is deliberately reusable:

- **Item vendors:** server can resolve stock/price, validate BITS and then use the same stack format. When implemented, prefer one vendor-owned atomic transaction that combines BITS mutation + inventory capacity check + item grant + persistence rather than trusting the client or chaining unrelated client operations.
- **Drops / loot:** grant a Primary Asset ID + quantity from server-owned loot authority.
- **Quests / achievements / login rewards:** grant through the same component API.
- **Crafting:** query/remove ingredients on authority and grant outputs only after the complete recipe transaction validates.
- **Digimon items:** extend `EDMFItemUseEffect` and the server switch for new native effect families while keeping effect magnitudes in server-resolved `UDMFItemData`.

Do not replicate full item definitions per player. Primary Asset IDs are the durable reference; the private Fast Array should remain compact account state.

## 10. Required multiplayer acceptance

Run `TEST_PLAN.md` **S0 — v0.20.0 player item inventory + HP/SP capsule acceptance** before treating this candidate as the next authoritative baseline. In particular verify host/client owner isolation, schema-v9 relog, full-stat no-consume behavior, defeated-target policy and a capsule used on an actively summoned Digimon during combat.
