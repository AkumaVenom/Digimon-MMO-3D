# DigiDex — Polished Native Species Encyclopedia

## Purpose

`v0.14.0-alpha` adds **DIGIDEX** to the shared Digimon Menu as a read-only encyclopedia of every Digimon species currently implemented in the project. It is intentionally separate from Party/Bank ownership actions: DigiDex can inspect a species but cannot summon, recall, transfer, feed, materialize, or Digivolve anything.

Native visual order:

**PARTY → BANK / BOXES → SCAN & MATERIALIZE → DIGIDEX → DIGIVOLUTION → CARE**

## 1. Register species once — DigiDex populates automatically

DigiDex reads Unreal's existing `DMFDigimonSpecies` Primary Asset registry. The supplied `DMF_Project_DefaultGame.ini.snippet` scans `/Game/DigimonData` recursively:

```ini
+PrimaryAssetTypesToScan=(PrimaryAssetType="DMFDigimonSpecies",AssetBaseClass="/Script/DigimonMMOFramework.DMFDigimonSpeciesData",bHasBlueprintClasses=False,bIsEditorOnly=False,Directories=((Path="/Game/DigimonData")),SpecificAssets=,Rules=(Priority=-1,ChunkId=-1,bApplyRecursively=True,CookRule=AlwaysCook))
```

Create one `DMFDigimonSpeciesData` per implemented form anywhere under that scanned directory. You do **not** create a separate DigiDex roster asset.

Recommended structure while populating the roster:

```text
/Game/DigimonData/Species/Fresh/...
/Game/DigimonData/Species/InTraining/...
/Game/DigimonData/Species/Rookie/...
/Game/DigimonData/Species/Champion/...
/Game/DigimonData/Species/Ultimate/...
/Game/DigimonData/Species/Mega/...
/Game/DigimonData/Species/Ultra/...
/Game/DigimonData/Species/Armor/...
```

## 2. Species fields used by DigiDex

For a high-quality entry, populate the normal species Data Asset fields rather than DigiDex-specific duplicates:

- `Identity -> Species Key`
- `Identity -> Display Name`
- `Identity -> Description`
- `Identity -> Stage`
- `Identity -> Attribute`
- `Identity -> Element`
- `DigiDex -> Show In DigiDex` (enabled by default)
- `DigiDex -> DigiDex Number` (optional stable number; `0` uses deterministic fallback ordering)
- `3D Presentation -> Portrait`
- `Progression -> Starting Level`
- `Progression -> Base Stats`
- `Progression -> Attribute Points Per Level`
- `Abilities -> Starting Ability IDs / Starting Abilities / Basic Auto Attack`
- `Battle Rewards`
- `Scan & Materialization` values
- `Digivolution -> Digivolutions`

DigiDex therefore always reflects the same authoritative authoring data used by combat, materialization and Digivolution.

## 3. Native page behavior

The left database browser provides:

- stable authored DigiDex-number sorting when `DigiDex Number > 0`, with deterministic Stage/name fallback for unnumbered entries;
- four fixed-width aspect-safe portrait cards;
- registry number;
- Stage + Attribute;
- **OWNED**, **SCANNED**, or **UNSCANNED** status;
- live implemented / shown / owned / scanned counts;
- text search across species name, Species Key, Stage, Attribute and Element;
- Stage filter;
- Attribute filter.

The right dossier provides:

- large aspect-safe portrait;
- registry number, Stage, Attribute and Element;
- live ownership count and Scan percentage;
- starting level and Base Stats;
- battle EXP/Money rewards;
- Scan reward and Materialization threshold;
- starting move references;
- authored incoming and outgoing Digivolution family links;
- species description.

The footer explicitly identifies the page as **ENCYCLOPEDIA ONLY**. No mutation/action button exists.

## 4. Discovery state

DigiDex does not create another persistent discovery database. Its badge is derived from systems already owned by the account:

1. **OWNED** — at least one instance exists in Party or Bank.
2. **SCANNED** — no owned instance, but account Scan Data for the species is above zero.
3. **UNSCANNED** — neither condition is true.

All implemented species remain visible by design so the page can serve as the project's complete species encyclopedia.

## 5. Project Setting

`Project Settings -> Game -> Digimon MMO Framework -> UI -> DigiDex -> Enable DigiDex`

Enabled by default. Disable it to hide the native DigiDex tab without altering species data or account state.

## 6. Blueprint reskin hooks

`DMFDigimonInventoryWidget` exposes:

- `Refresh DigiDex Data`
- `Get DigiDex Species Ids`
- `Get Selected DigiDex Species Id`
- `BP On DigiDex Selection Changed`

These are presentation helpers only. Custom Blueprint UI should still avoid adding ownership mutation actions to the DigiDex page.

## 7. Multiplayer / authority contract

DigiDex adds no RPC and no replicated property. Registered species data is static cooked content. OWNED/SCANNED badges read the existing owner-only Party, Bank and Scan replication already present on the owning client. Other players cannot inspect another account's private ownership through this page.

## 8. Acceptance test

1. Keep Agumon and Gabumon registered under `/Game/DigimonData`.
2. Compile and open the world with `I`.
3. Open **DIGIDEX** and confirm both species appear even if only one is currently owned.
4. Search `Agumon`; verify only Agumon remains. Clear the search.
5. Cycle Stage until `Rookie`; verify both Rookie entries remain.
6. Cycle Attribute and verify Vaccine/Data filters select the correct species.
7. Select each card and verify portrait aspect ratio, description, base profile, Scan state and evolution links.
8. Confirm there is no summon/recall/storage/materialize/digivolve action on DigiDex.
9. Run host + second client. Each client should see the same implemented species list but only their own OWNED/SCANNED status.
10. Add a third `DMFDigimonSpeciesData` beneath the scanned directory, restart PIE if needed for Asset Manager discovery, and confirm the entry appears without editing DigiDex code.
