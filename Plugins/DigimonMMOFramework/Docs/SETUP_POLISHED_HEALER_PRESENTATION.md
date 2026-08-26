# Polished Replicated Healer Treatment Presentation — v0.12.2-alpha

This release turns the existing server-authoritative `DMFHealerActor` into a complete static-prop healing station presentation suitable for a futuristic medical capsule. Gameplay restoration remains authoritative and one accepted use can restore the complete six-Digimon Party plus every persistent Bank/Box record.

## 1. Create the healer Blueprint

1. Create/keep a Blueprint derived from `DMFHealerActor`, for example `BP_DigimonHealer`.
2. Add the project's healer Static Mesh as a cosmetic child of the framework root. The native `InteractionCollision` sphere already handles the standard player interaction trace, so the Fab mesh does not need Visibility collision just to be usable.
3. Select `HealingPresentationAnchor`, or edit **Healing Presentation Relative Transform**, and position it inside the chamber where the treatment glow/pluses should originate. One anchor moves the light, VFX and sound together.

## 2. Treatment sequence / exclusivity

`Healing Sequence Duration` defaults to **3 seconds**. After the server accepts a real restore, that healer actor becomes busy for the sequence duration.

- Only **one player can own one healer actor at a time**.
- A second player using the same actor receives `Busy Message`.
- Other healer actors remain independent and may treat other players simultaneously.
- The health/SP mutation is still performed only by the authoritative server.
- `Include Bank Storage=true` restores every Party slot and every Bank/Box entry, not only the currently visible Box page.
- Successful changes persist immediately through the existing account persistence subsystem.

## 3. Built-in green treatment light

Under **Digimon MMO → Healer → Presentation → Light** configure:

- `Enable Healing Light`
- `Healing Light Color` — defaults to bright healing green.
- `Healing Light Intensity`
- `Healing Light Attenuation Radius`
- `Healing Light Pulse Amount`
- `Healing Light Pulse Frequency Hz`
- `Healing Light Fade In Seconds`
- `Healing Light Fade Out Seconds`

The native light is useful even when no particle asset is ready. It fades in, pulses while the replicated station is active, and fades back to zero after treatment. It casts no shadows by default to keep a short-lived interior effect inexpensive.

## 4. Niagara + Cascade fallback

Under **Presentation → VFX** assign:

- `Healing Niagara System` — recommended primary effect.
- `Healing Cascade System` — legacy fallback.
- `Prefer Niagara Healing VFX` — enabled by default.

Recommended content: upward-floating or orbiting **green healing plus (+) sprites/meshes**, soft emissive bloom, low spawn count, and a looping system long enough to remain active until the framework deactivates it.

Selection logic:

- Prefer Niagara ON: Niagara if assigned, otherwise Cascade.
- Prefer Niagara OFF: Cascade if assigned, otherwise Niagara.
- Neither assigned: no particle component is activated; the green light/audio/Blueprint hooks continue safely.

The framework does not distribute the third-party healer mesh or a copyrighted particle asset. Supply your own Niagara/Cascade content in the project and drag the references into the healer Blueprint defaults.

## 5. Healing audio

Under **Presentation → Audio** assign `Healing Sound`. A Sound Cue is recommended so the project can author attenuation, randomized sweeteners, looping machinery and pitch/sample variation inside the cue.

The actor exposes volume, pitch and fade-out multipliers. Audio is attached to the same presentation anchor, so other nearby players hear it spatially when the Sound Cue has attenuation.

## 6. Blueprint animation workaround for a static healer mesh

The native components provide the complete out-of-box treatment read. For extra motion on a static medical capsule, implement these optional events in the healer Blueprint:

- `BP On Healing Sequence Started`
- `BP On Healing Sequence Finished`

Good uses include:

- animate a door/panel with a Timeline;
- drive a Dynamic Material Instance emissive parameter from dark to green;
- rotate fans/rings;
- show a holographic cross;
- trigger an additional local-only cosmetic animation.

Do **not** put HP/SP restoration in those events. They execute as presentation hooks on rendering machines.

`BP On Heal Presentation` remains available for backward compatibility with older healer Blueprints.

## 7. Replication model

The server replicates only compact durable treatment state:

- `bHealingInProgress`
- `ActiveHealingPlayerState`
- `ActiveHealingDigimonCount`

Every client drives the point light, selected VFX component and audio locally from that state. This avoids per-frame cosmetic replication and means a client that becomes relevant while the station is active can reconstruct the current presentation. Dedicated servers skip rendering/audio work.

The interaction route remains:

`Player Interact → owning DMFMMOPlayerController server RPC → healer validates enabled/busy/range/reuse → HealAllOwnedDigimon → persistence → replicated treatment state`

## 8. Recommended Fab medical-capsule setup

For the selected futuristic capsule prop:

1. Add its Static Mesh to `BP_DigimonHealer`.
2. Keep the framework `InteractionCollision` query sphere separate from physical mesh collision.
3. Move `HealingPresentationAnchor` to the center of the glass/interior chamber.
4. Tune attenuation so the green light stays mostly inside/around the machine.
5. Assign the green-plus Niagara effect and a soft electronic healing Sound Cue.
6. If the model has separate material slots/pieces, use the start/finish Blueprint events to pulse emissive materials during treatment.

## 9. Multiplayer acceptance test

Use a listen host plus a second client. Damage Digimon in Party and Bank first.

1. Client A uses the healer; host and Client B see the same green treatment state and hear the spatial sound.
2. Confirm all changed Party/Bank HP/SP values restore for Client A only.
3. While active, Client B uses the same station and is rejected as busy.
4. After the sequence ends, Client B can use it normally.
5. Test Niagara, then remove Niagara to verify Cascade fallback.
6. Reconnect Client A and verify restored persistent vitals remain saved.
7. Confirm no client can submit heal amount/count values or directly authoritatively toggle healer busy state.
