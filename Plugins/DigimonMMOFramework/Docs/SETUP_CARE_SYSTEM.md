# Virtual-Pet Care Setup — v0.8.1-alpha

This system is designed for an MMO authority boundary: **clients request care actions; the server owns Hunger, feeding progression, digestion scheduling, world waste spawning and persistence**. Replicated meshes, Montages, sounds and UI are presentation only.

## 1. Global project settings

Open **Project Settings → Digimon MMO Framework → Care**.

Recommended first-test values:
- `Enable Care System = true`
- `Care Server Tick Interval = 10`
- `Care Presentation Lead In Seconds = 0.35`
- `Care Inter Serving Pause Seconds = 0.20`
- `Care Fallback Montage Duration Seconds = 1.0`
- `Default DigiMeat Mesh` = your DigiMeat static mesh
- `Default Poo Mesh` = your poo static mesh
- `Care Prop Actor Class` = native `DMFDigimonCarePropActor` or a Blueprint child

The two default meshes are global fallbacks. A species can override either mesh.

When `Enable Care System` is false, the framework freezes Hunger/offline Care progression as well as feeding/waste actions. Re-enabling resumes from the last authoritative Care timestamp rather than mutating Care invisibly while the feature is disabled.

## 2. Configure each `DMFDigimonSpeciesData`

Under **Care**:
- `Care Enabled`: enables Hunger/feeding/waste for the species.
- `Starting Hunger Percent`: initial Hunger for newly created Digimon (`100 = full`).
- `Hunger Decay Percent Per Hour`: real-time server UTC decay, including offline time.

Under **Care → Feeding**:
- `DigiMeat Hunger Percent Per Serving`: Hunger gained only after a complete serving presentation.
- `Feeding Montage Plays Per Serving`: default `2`; the framework plays the Montage twice sequentially, not simultaneously.
- `Feeding Montage Play Rate`: presentation rate.
- `DigiMeat Hand Socket Name`: **text-writable** skeletal socket/bone name. Enter the exact socket used by that Digimon skeleton, e.g. `hand_r`.
- `DigiMeat Mesh`: optional species override.
- `DigiMeat Relative Transform`: socket-relative position, rotation **and scale**. Use this to compensate for large skeleton/socket scale differences between Digimon.
- `Feeding Voice Sounds`: optional list; the server chooses the index so all viewers receive the same cue.

The existing species **Animation → Feeding Montage** must also be assigned. Feeding is rejected safely when the Montage, DigiMeat mesh or named hand socket cannot be resolved.

**Fast PIE test tip:** set `Starting Hunger Percent` to `50` before creating/materializing a fresh test Digimon. Existing saved Digimon intentionally keep their persisted Hunger, so changing this starting value does not rewrite established partners.

## 3. Configure poop / digestion

Under **Care → Waste**:
- `Waste Enabled`
- `Minimum Waste Delay Seconds`
- `Maximum Waste Delay Seconds`
- `Poo Mesh`: optional species override.
- `Poo World Scale`: independent per-species world scale.
- `Poo Ground Offset`: small offset along the traced ground normal.
- `Poo Lifetime Seconds`: automatic cleanup lifetime.

Under **Care → Audio**:
- `Waste Fart Sounds`: optional list of funny fart sounds. The server picks an index and multicasts it when waste is produced.

Waste uses a downward Visibility trace from the Digimon's current world position. `DMFDigimonCarePropActor` then forces actor/mesh collision off, ignores every collision channel, disables overlap generation and does not affect navigation. Projects can subclass the actor for materials/VFX, but should preserve those invariants.

### Cel-shading / CustomDepth

`ADMFDigimonCarePropActor` now treats Custom Depth as a framework invariant for **both DigiMeat and poo**. `Render CustomDepth Pass` is forced on for every mesh component on the prop during construction, BeginPlay and replicated presentation refresh. This means the attached DigiMeat and spawned waste participate in the same post-process cel-shading path as framework Digimon and player avatars.

- `CustomDepthStencilValue` is Blueprint-editable on the Care prop actor (`0-255`, default `0`).
- `RefreshFrameworkCustomDepth()` is Blueprint-callable if a Blueprint child creates/replaces extra mesh components dynamically.
- Unreal project-level **Custom Depth-Stencil Pass** must still be enabled under **Project Settings → Rendering** for the project's cel-shading material to sample CustomDepth.
- This rendering state is local presentation only and is not replicated gameplay data. The replicated actor/species/type still determines which Care prop viewers see.


## 4. Feeding flow

The default native flow is:

`I → CARE → FEED DIGIMEAT UNTIL FULL`

1. Client asks its owner component to feed.
2. Server validates account-owned active instance, summoned actor, health, idle combat state, care configuration, Montage, mesh and socket.
3. Server locks conflicting care/combat/partner commands and tells the owner that presentation is beginning.
4. Owner hides the Digimon Menu and combat quickbar and restores the world view.
5. After the lead-in, the server spawns a replicated DigiMeat actor and attaches it to the configured hand socket using the species relative transform/scale.
6. The feeding Montage plays sequentially `Feeding Montage Plays Per Serving` times (default: **2**). The first loop can play the selected feeding voice.
7. Only after the full serving presentation completes does the server add Hunger and persist it.
8. If Hunger is below 100, another serving begins automatically. If full, feeding ends.
9. The owner's Digimon Menu reopens directly on **CARE** with the refreshed owner-only state.

## 5. Hunger and persistence

The account SaveGame schema is **v3** for this milestone. Existing v2 and earlier account fields are preserved; the Care migration is additive and runs when authoritative Digimon instances are initialized.

Hunger is stored in the existing persistent `FDMFDigimonInstance::Care` structure. The server stores a UTC care-update timestamp and integrates `HungerDecayPercentPerHour` from elapsed real time, so logging out does not freeze Hunger.

v0.8.0 contains a one-time compatibility rule for untouched v0.7.x care defaults (`Hunger=0`, `Fullness=100`, no care timestamps): those entries migrate to full Hunger rather than becoming hungry immediately after upgrade. `Fullness` remains mirrored to Hunger for backward-compatible Blueprint/save consumers.

## 6. Waste scheduling and cleanup

A completed serving schedules `NextWasteUtcTicks` if waste is enabled and none is already pending. The selected delay is server-only and persisted. When the timer is due:
- if the Digimon is summoned, the server places waste on traced ground immediately;
- if recalled/offline, the due time stays pending and resolves when that partner is next spawned;
- a fart cue can be multicast;
- the poo actor is replicated and non-colliding;
- `Poo Lifetime Seconds` removes it automatically.

## 7. Blueprint extension points

Useful Blueprint-facing surfaces include:
- `UDMFPlayerDigimonComponent::GetActivePartnerCareState`
- `UDMFPlayerDigimonComponent::GetSecondsUntilActivePartnerWaste`
- `UDMFPlayerDigimonComponent::ServerFeedActivePartnerUntilFull`
- `OnCareStateChanged`, `OnCareSequenceStarted`, `OnCareSequenceFinished`
- `ADMFMMOPlayerController::OpenCareUI`
- `ADMFDigimonCharacter::BP_OnCareFeedingCue`
- `ADMFDigimonCharacter::BP_OnCareWasteCue`
- Blueprint child of `ADMFDigimonCarePropActor` for presentation-only mesh/VFX customization

Do not duplicate Hunger awards, waste creation or timing in client Blueprints.

## 8. Required multiplayer acceptance test

Run PIE with one listen host + one remote client, then repeat in packaged builds when ready.

1. Give both accounts a summoned partner with `Hunger < 100`.
2. On the host, open `I → CARE`; confirm portrait, Hunger, Happiness, Discipline and digestion state match that host account only.
3. Press **Feed DigiMeat Until Full**. Confirm menu/quickbar disappear before animation starts.
4. On **both viewers**, confirm DigiMeat attaches to the correct hand at the configured per-species scale, is included by the project's CustomDepth cel shader, and the Digimon performs exactly two full eating Montage plays per serving.
5. Confirm one feeding voice per serving (when configured), Hunger increases only after the pair completes, and servings repeat until exactly 100%.
6. Confirm conflicting attacks, target changes, recall/summon changes and auto-battle toggles do not interrupt authoritative feeding.
7. Confirm the host menu automatically returns to CARE after completion.
8. Repeat the entire flow from the remote client; confirm the host sees that client's partner/food/audio presentation while only the remote owner's private Hunger UI/state changes.
9. Temporarily set waste delay to 10–20 seconds. Confirm the correct Digimon eventually emits its fart cue and a poo mesh appears on the ground beneath its standing location for both peers, with the poo also included by the CustomDepth cel shader.
10. Walk through/stand in the poo and verify **no collision or overlap blocking**.
11. Wait past `Poo Lifetime Seconds`; verify it is automatically destroyed for both peers.
12. Feed, log out before waste is due, wait, reconnect and summon. Confirm overdue persisted waste resolves in-world.
13. Reconnect both accounts again and verify Hunger/care state remains account-separated.

After testing, restore production waste-delay/lifetime values.

## v0.13 Digivolution integration

Care state is now a first-class optional Digivolution requirement. An authored path can require minimum **Happiness**, minimum **Discipline**, and a maximum **Care Mistakes** value. These values are evaluated from the same persistent individual stored in Party/Bank and are revalidated by the authoritative server at commit time.

A Digimon cannot begin Digivolution while its account is inside an active feeding/Care presentation, and new Care mutations are blocked during an active summoned-partner Digivolution sequence. This keeps Hunger/digestion/presentation state from racing the species mutation.

Digivolution preserves the persistent `FDMFDigimonCareState`; changing form therefore does not silently reset Hunger, Happiness, Discipline, Care Mistakes or scheduled Care state. See `SETUP_DIGIVOLUTION.md` for the complete progression contract.
