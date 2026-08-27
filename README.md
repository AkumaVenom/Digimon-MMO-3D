# Digimon MMO 3D Framework — UE5.8

### Explore the Digital World. Raise your partner. Build your collection. Fight together.

**Digimon MMO 3D** is an ambitious
multiplayer 3D Digimon fan project focused on creating the feeling of
living inside a persistent Digimon World alongside your own Digimon
partners.

Explore, battle wild Digimon, collect Scan Data,
materialize new partners, grow your collection, explore the DigiDex, care for your Digimon,
Digivolve them through persistent branching evolution paths, and adventure alongside other players in a shared multiplayer experience.

The project is currently in active development and is
being built system-by-system with a strong focus on multiplayer
gameplay, persistence, progression, and the bond between the player and
their Digimon.

<img width="1707" height="724" alt="Splash- RaGEZONE" src="https://github.com/user-attachments/assets/b668489e-45ca-46d3-ace3-7e4b4754172f" />

---

# 🧪 Current Accepted Development Baseline

The current accepted development baseline is:

**v0.14.0-alpha_PolishedNativeDigiDex**

This baseline establishes the polished **native DigiDex** as a working in-game system while retaining the complete **persistent, server-authoritative and replicated Digivolution system** introduced in v0.13.0 and polished in v0.13.1, alongside the previously established multiplayer, account, collection, Scan Data, partner, native UI, care and healer foundations.

The project remains in active Alpha development, but this build is the current reference point for ongoing Digimon MMO 3D development.

Key inherited progression milestones include **v0.13.0-alpha_PolishedReplicatedDigivolution**, which established the complete persistent replicated Digivolution layer, and **v0.13.1-alpha_DigivolutionOwnedRosterAspectFix**, which polished the native Digivolution owned-roster presentation before v0.14.0 added the DigiDex.

---

## 🌐 Welcome to the Digital World

Digimon MMO 3D is designed around one simple idea:

**Your Digimon should feel like a real partner — not just another character in your inventory.**

Your journey begins by creating your account and choosing your first Digimon partner.

From there, you can enter the Digital World, encounter
other Digimon, battle them, collect their Scan Data, build your Digimon
Collection, choose which Digimon accompanies you, raise their progression, and Digivolve them into new forms as your journey continues.

The game is being developed as a true multiplayer
experience, allowing players to host and join worlds while maintaining
their own account and Digimon progression.

<img width="1920" height="1080" alt="MainScreen" src="https://github.com/user-attachments/assets/b44dadc3-24c4-4202-a84f-15b5f98cfa2b" />

<img width="1920" height="1080" alt="1" src="https://github.com/user-attachments/assets/e58d5764-777e-43a7-8d57-d02529b9b188" />

---

# 🎮 The Core Gameplay Loop

Your adventure revolves around exploring, battling, collecting and raising Digimon.

### Explore

Travel through the 3D Digital World with your active Digimon partner by your side.

Discover wild Digimon, future locations, activities, progression opportunities and other players throughout the world.

### Battle

Encounter wild Digimon and enter real-time battles.

Your Digimon can actively participate in combat while you influence the battle using abilities and commands.

Combat is being designed around the feeling of fighting **alongside your Digimon**, rather than simply controlling it as another player character.

### Collect Scan Data

Defeating and encountering Digimon can contribute **Scan Data** toward that Digimon species.

Scan Data represents your growing understanding of that Digimon.

Reach the required materialization threshold and you can create a Digimon of that species for your own collection.

### Materialize Digimon

Once enough Scan Data has been obtained, that Digimon can be **Materialized**.

The newly materialized Digimon becomes a real individual
member of your Digimon Collection rather than simply unlocking the
species.

You can then select it as one of your partners and summon it into the world.

### Raise Your Partners

Digimon are intended to become companions that you look after and develop over time.

Their individual progression can include Level, ABI, CAM, stats and Care values that can feed directly into authored Digivolution requirements.

### Digivolve

Owned Digimon can follow fully data-driven Digivolution paths into new forms when their configured requirements are met.

Paths can branch into multiple possible forms, can include deliberately authored reverse or de-Digivolution routes, and can use progression, stat, Care and money requirements rather than forcing every species into one hard-coded linear chain.

---

# 🐣 Choose Your Starter Digimon

Every new journey needs a beginning.

New players are introduced to the world by selecting their first **Starter Digimon**.

Your starter becomes your first true partner and the beginning of your Digimon Collection.

Starter selection is tied directly to your player account,
allowing your adventure and partner progression to remain associated
with your character as the game continues to grow.

---

# 🔍 Scan Data & Materialization

One of the major collection systems in Digimon MMO 3D is the **Scan Data System**.

Instead of simply capturing every Digimon you encounter, you gradually gather data about different Digimon species.

Your Scan Data progresses toward the required materialization amount.

Once the threshold has been reached:

**Scan Data → Materialization → New Digimon → Your Collection**

The materialized Digimon becomes part of your personal collection and can be selected as a partner.

This system is inspired by the concept of Digimon being
composed of digital information and makes building your collection part
of the wider progression experience.

<img width="1920" height="1080" alt="2- RaGEZONE" src="https://github.com/user-attachments/assets/9b041c5e-ceb0-4cce-a726-fe19576779bd" />

---

# 📖 Native DigiDex

The **v0.14.0-alpha_PolishedNativeDigiDex** baseline introduces a polished native **DigiDex** directly into the shared Digimon Menu.

The DigiDex is a read-only encyclopedia and discovery interface. It presents registered species without becoming a second gameplay authority or bypassing the existing ownership, Materialization or Digivolution systems.

The native DigiDex can present species information including:

- Portrait and species identity
- Stage, Attribute and Element
- Ownership and Scan status
- Base stats and starting level
- Battle reward information
- Scan / Materialization values
- Starting move references
- Species description
- Authored previous and next Digivolution-family links

Those Digivolution-family links are sourced from the same authored Digivolution graph used by the real progression system, allowing the DigiDex to show family context while keeping actual eligibility checks and form changes server-authoritative.

The DigiDex intentionally does **not** directly summon, recall, move, materialize, care for or Digivolve a Digimon. It provides polished encyclopedia presentation while the authoritative systems continue to own gameplay mutation.

<img width="3805" height="2063" alt="1" src="https://github.com/user-attachments/assets/19e9647d-2bac-4519-a653-b9f8f68f6b2c" />

---

# 📚 Your Digimon Collection

Every Digimon you obtain is stored as part of your own **Digimon Collection**.

Your collection is designed around persistent individual Digimon rather than treating every member of the same species as identical.

Digivolution changes the current form of that same individual rather than replacing its identity. Core progression and provenance remain attached to the persistent Digimon as it moves through authored forms.

From your collection you can manage your available Digimon
and decide which partner you want accompanying you in the Digital
World.

---

# 🧭 Native Digimon Management Interface

Digimon MMO 3D now has a growing set of polished native interfaces for managing your partners and progression directly in-game.

The established native interface foundation includes:

- Party management
- Digimon Bank / Boxes
- Scan & Materialize
- Native DigiDex
- Native Digivolution
- Care
- Party Quick Access
- Combat quickbar

The main Digimon Menu now follows the polished order **PARTY → BANK / BOXES → SCAN & MATERIALIZE → DIGIDEX → DIGIVOLUTION → CARE**, keeping collection, discovery, evolution and care inside one connected interface.

---

# 🐲 Partner Digimon

Choose a Digimon from your collection and make it your active partner.

Your selected Digimon can be summoned into the world where it travels and fights alongside you.

Partner selection and summoning are synchronized correctly
across multiplayer sessions, allowing other players to see and interact
with the Digimon accompanying you.

Your partner is intended to become the center of your adventure.

---

# 🔄 Persistent Replicated Digivolution

Digivolution is already a major working system in Digimon MMO 3D.

Introduced in **v0.13.0-alpha_PolishedReplicatedDigivolution** and retained by the current v0.14.0 baseline, the system adds persistent, server-authoritative evolution directly to owned Digimon.

Digivolution is **data-driven rather than hard-coded to a single linear chain**. Species can expose zero, one or many outgoing paths, allowing branching families such as one Rookie Digimon progressing toward different Champion forms. Reverse or de-Digivolution paths can also be deliberately authored when desired.

The framework supports the project's normal Digimon stages:

- Fresh
- In-Training
- Rookie
- Champion
- Ultimate
- Mega
- Ultra
- Armor

### Digivolution Requirements

Each authored path can independently require:

- Level
- ABI
- CAM
- Optional Strength, Intelligence, Defense and Speed gates
- Optional Happiness and Discipline gates
- Optional maximum Care Mistakes
- Optional money cost

The native Digivolution interface evaluates each path and shows **READY** or **LOCKED** with its requirement summary. The client display is informational; the server resolves the owned Digimon and revalidates the requirements before committing the transformation.

### Native Digivolution Interface

The **DIGIVOLUTION** page includes:

- A combined owned-Digimon browser for Party + Bank
- Current-form portrait and information
- Stage, Attribute, Level, storage location, HP, ABI and CAM
- A scrollable list of authored outgoing paths
- READY / LOCKED status
- Requirement summaries
- Destination portrait and form information
- A protected **DIGIVOLVE TO SELECTED FORM** action

The v0.13.1 polish pass also corrected the owned-roster presentation with fixed centered three-column cards and square aspect-safe portrait viewports so sparse Party/Bank rows remain clean and readable.

### Replicated Active-Partner Transformation

When the selected Digimon is the currently summoned active partner, Digivolution runs as a server-owned multiplayer sequence rather than an instant local species swap.

The server validates ownership, source form, path, progression requirements, money, Care state and combat restrictions; locks conflicting actions; plays the configured replicated transformation presentation; then revalidates before committing the new form.

The transformation can use Niagara-preferred VFX with Cascade fallback, Digivolution audio, configurable presentation duration and Blueprint cosmetic extension points. After the authoritative presentation completes, the old world actor is replaced by the target form while preserving the same persistent Digimon identity, and normal actor replication presents the evolved form to other players.

### Bank / Box Digivolution

Digimon stored in Bank / Boxes can also Digivolve when both the project-wide rule and the authored path allow it.

Bank Digivolution updates the authoritative persistent entry directly without unnecessarily moving it into Party or spawning a temporary world actor. Party ordering remains intact and the owning player's UI refreshes from the authoritative result.

### Persistent Evolution History

Digivolution is part of account persistence, not a temporary visual state.

The persistent owned Digimon stores its origin species and Digivolution history. Successful form changes preserve the same individual identity while progression such as Level, Experience, ABI, CAM, nickname, Care state and unspent attribute points remains attached to that Digimon. Authored path rules control how stat investments, equipped abilities and current vitals carry into the destination form.

<img width="3809" height="2067" alt="2" src="https://github.com/user-attachments/assets/d8e427af-a10d-4ca7-8449-e2b6d24bd459" />

---

# ⚔️ Real-Time Digimon Combat

Combat in Digimon MMO 3D is being designed for a living multiplayer world rather than traditional turn-based encounters.

Digimon can participate directly in battle while players use commands and abilities to influence the fight.

The wider combat system is being built around:

- Real-time Digimon encounters
- Player and Digimon cooperation
- Digimon versus Digimon combat
- Wild Digimon
- Multiplayer synchronization
- Player-issued combat abilities and commands
- Quick-access ability systems
- Progression rewards
- Scan Data rewards
- Future expansion into increasingly advanced battle mechanics

The goal is to make battles feel like you and your Digimon are fighting **together**.

---

# 🍖 Digimon Care System

Digimon MMO 3D expands beyond combat so that your Digimon also needs attention and care.

The Care System is being designed to make partners feel more like living creatures within the Digital World.

Players will be able to give their Digimon food such as DigiMeat to manage their partner's hunger.

When your Digimon begins eating, the game interface
temporarily gets out of the way so you can actually watch your partner
eat instead of having the moment hidden behind menus.

Once the eating sequence finishes, the Care interface returns and displays the Digimon's updated condition.

The wider Care System is planned to grow into additional needs, reactions and Digimon behaviours over time.

<img width="1920" height="1080" alt="4- RaGEZONE" src="https://github.com/user-attachments/assets/c2518cb3-6800-4372-aba4-3d084f89b5e5" />

---

# 🩺 Digimon Healing

The framework also includes a multiplayer-aware healer setup for restoring Digimon as part of the living Digital World.

Its healing presentation is replicated so the recovery experience is represented correctly during multiplayer play rather than existing only for the local player.

The current presentation includes a dedicated green interior lighting and VFX treatment that clearly communicates the healer space while fitting the visual language of the world.

This system provides another foundation for future Digimon recovery, care and service-based gameplay.

---

# ❤️ Your Digimon Is More Than a Combat Unit

A major goal of Digimon MMO 3D is making the relationship between player and Digimon matter.

Your partner is intended to:

- Travel beside you
- Fight beside you
- React to your actions
- Need care and attention
- Develop over time
- Become part of your long-term progression
- Remain associated with your account and collection

The game will continue expanding these systems as development progresses.

---

# 🎒 Inventory & Player Progression

Digimon MMO 3D is being built with persistent player progression.

Your account can maintain important progression information between sessions instead of resetting every time you leave the game.

The wider progression framework is being designed to support systems such as:

- Digimon Collections
- Individual Digimon
- Active Partners
- Scan Data
- Materialized Digimon
- Player inventory
- Digimon management
- Native DigiDex and Digimon discovery
- Persistent current Digivolution form
- Digivolution origin and history
- ABI and CAM progression
- Care progression
- Future progression systems

More systems will be connected to persistent accounts as development continues.

---

# 🏦 Digimon Storage

As your Digimon Collection grows, management becomes increasingly important.

Digimon MMO 3D is being designed with dedicated Digimon
management and storage systems so that players can build much larger
collections without every Digimon needing to remain immediately active.

The goal is to give players the freedom to collect, organize and raise many different Digimon while maintaining a smaller active group of partners.

The established Digivolution system also supports eligible Bank / Box Digimon, allowing persistent stored Digimon to evolve without first being moved into the active Party when the configured rules permit it.

---

# 🌍 Multiplayer

Digimon MMO 3D is being developed from the ground up around multiplayer.

Players can host a game and allow other players to join the same Digital World.

Core gameplay information is synchronized between players
so important actions are represented consistently throughout the
session.

Multiplayer development currently includes support for systems such as:

- Hosting a multiplayer world
- Joining another player's world
- Player accounts
- Individual account progression
- Digimon Collections
- Scan Data
- Digimon Materialization
- Partner selection
- Partner summoning
- Server-authoritative Digivolution
- Replicated active-partner Digivolution presentation
- Persistent Digivolution form and history
- Persistent player information
- Multiplayer Digimon gameplay

The long-term objective is to keep expanding these foundations toward a much larger Digimon online experience.

---

# 👤 Player Accounts

Digimon MMO 3D includes its own account-based progression foundation.

Your account represents your individual journey through the Digital World.

Different players can maintain their own progression, allowing Digimon, collections, current Digivolution forms, Digivolution history and other supported persistent information to remain associated with the correct player.

This is an important part of the game's multiplayer
foundation and will continue to support additional persistent systems as
they are introduced.

---

# 🖥️ Starting a Game

From the game's frontend you can access the available multiplayer options.

### Hosting

Hosting is handled through the protected Admin Host & Play option on the frontend.

To host a multiplayer session:

1. Select **Admin** from the frontend.
2. Enter the configured **Admin Hosting Password**.
3. Unlock the protected hosting controls.
4. Select **Host & Play**.
5. The game starts a listen-server session and loads the host into the Digital World using their account and persistent progression.

The Admin hosting password can be changed without editing C++ from:

Project Settings → Game → Digimon MMO Framework → Networking → Admin Hosting

The password is securely converted into a stored credential digest rather than being saved as readable plaintext.

The multiplayer server address and port can also be configured from:

Project Settings → Game → Digimon MMO Framework → Networking → Server Endpoint

This allows developers to configure their hosting environment entirely through Project Settings.

### Joining

Players connect using the normal Join Game option on the frontend.

Unlike a traditional direct-IP menu, players do not need
to manually enter an address. The framework automatically uses the
server endpoint configured by the developer under:

Project Settings → Game → Digimon MMO Framework → Networking → Server Endpoint

The configurable endpoint includes:

- Server Public Address / Hostname
- Game Port

When Join Game is selected, the player connects to that
configured destination and enters the multiplayer Digital World using
their own account and supported persistent progression.

### Returning Players

Existing account information can be loaded so that supported persistent progression can continue between sessions.

> Digimon MMO 3D is still in active development, so the exact frontend flow and available options may change between builds.

---

# 🚧 Current Development Status

**Digimon MMO 3D is currently an Alpha project.**

The current accepted baseline is **v0.14.0-alpha_PolishedNativeDigiDex**.

A large amount of the game's underlying multiplayer and
progression technology is already functional, but the complete game is
still being developed.

Systems may be redesigned, expanded or replaced as development continues.

Current development is focused on building strong
foundations first and expanding them into a much larger game rather than
rushing individual features simply to increase the feature count.

---

# ✅ Major Systems Already Established

The project currently has working foundations for:

- Multiplayer gameplay
- Player accounts
- Persistent account progression
- Starter Digimon selection
- Individual Digimon ownership
- Digimon Collection management
- Active partner selection
- Digimon partner summoning
- Scan Data accumulation
- Scan Data persistence
- Digimon Materialization
- Persistent branching Digivolution
- Server-authoritative Digivolution validation
- Native Digivolution interface
- READY / LOCKED Digivolution requirement presentation
- Replicated active-partner Digivolution sequence
- Niagara / Cascade / audio Digivolution presentation
- Bank / Box Digivolution
- Persistent Digivolution origin and history
- Authored reverse / de-Digivolution paths
- Native DigiDex
- Native Party management interface
- Native Digimon Bank / Boxes interface
- Native Scan interface
- Native Party Quick Access
- Native combat quickbar
- Digimon Care System
- Multiplayer-aware replicated healer presentation
- Multiplayer Collection synchronization
- Multiplayer partner synchronization
- Digimon inventory and management foundations
- Real-time Digimon gameplay foundations

---

# 🔮 What Is Coming Next?

Digimon MMO 3D is intended to grow far beyond its current Alpha foundations.

Future development can continue expanding areas such as:

- Deeper Digimon Care
- Additional partner needs
- More Digimon behaviours
- Expanded real-time combat
- More abilities and battle commands
- Deeper Digimon progression
- Expanded DigiDex discovery and information
- More authored Digivolution branches and families
- More advanced Digivolution requirements and presentation
- Larger Digimon Collections
- Expanded storage and management
- More wild Digimon
- Exploration content
- Multiplayer activities
- World progression
- Additional persistent systems
- More reasons to interact with and care for your partners

Each major feature is being built so that it can become
part of the same connected Digimon experience rather than existing as an
isolated mechanic.

---

# 💾 Alpha Notice

Please remember that Digimon MMO 3D is under active development.

During Alpha development:

- Features may change.
- User interfaces may be redesigned.
- Balance is not final.
- Saved data formats may occasionally change between major development builds.
- Bugs and unfinished content should be expected.
- Some announced systems may still be under development.
- Content shown during development does not necessarily represent the final game.

Testing and feedback are extremely valuable during this stage of development.

---

# 🎯 The Vision

Digimon MMO 3D is ultimately about creating a Digital World where your Digimon feels like **your partner**.

Not simply a collectible.

Not simply a combat unit.

Not simply another inventory entry.

A companion you discovered, raised, fought beside and shared an adventure with.

The long-term vision combines:

**Exploration + Digimon Raising + Real-Time Combat + Collection + DigiDex Discovery + Digivolution + Progression + Multiplayer**

into one connected 3D Digimon experience.

---

# 💙 Thank You for Following Development

Digimon MMO 3D is an evolving passion project, and every new system brings the Digital World another step closer to life.

Whether you are interested in collecting Digimon, raising
your favourite partner, battling alongside friends, exploring the
Digital World, or simply watching the project grow, thank you for being
part of the journey.

### The Digital World is only just beginning.

---

## ⚠️ Disclaimer

**Digimon MMO 3D is an unofficial fan-made project.**

Digimon and all related names, characters, logos, designs
and trademarks are the property of their respective copyright and
trademark holders.

This project is not affiliated with, endorsed by,
sponsored by, or officially connected to Bandai, Bandai Namco
Entertainment, Toei Animation, or any other official Digimon rights
holder.

All original project code, systems and project-specific
content remain subject to their respective ownership and licensing
terms.
