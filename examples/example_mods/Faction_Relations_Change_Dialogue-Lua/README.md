# Faction Relations Change Dialogue (KenshiLua Dialogue Action Plugin)

An example mod demonstrating how to use KenshiLua to dynamically modify faction relationship levels through dialogue choices in Kenshi's Forgotten Construction Set (FCS).

## Location & Gameplay

The mod spawns a character named **Lua** in the Bar inside **The Hub**. Interacting with Lua provides three distinct dialogue choices to manipulate faction relationships in real-time.

## Dialogue Options & Scripts

When speaking with Lua, each dialogue option executes one of the Lua scripts stored in `./scripts/dialogue/`:

### 1. Maximize Relations (`dialogue/faction_relation_change_max_dialogue.lua`)
- **Action**: Sets mutual relations between the **Starving Bandits** and **Dust Bandits** to maximum alliance (+100.0).
- **Logic**:
  - Accesses the active dialogue via `currentDialogue`.
  - Queries `GameWorld.factionMgr` for the target factions ("Starving Bandits" and "Dust Bandits").
  - Logs the relation shift to the console via `KenshiLua.log()`.
  - Applies `+100.0` relation bidirectionally using `relations:setRelation(targetFaction, newRel)`.
  - Closes the dialogue context cleanly using `dialogue:endDialogue(true)`.

### 2. Minimize Relations (`dialogue/faction_relation_change_min_dialogue.lua`)
- **Action**: Sets mutual relations between the **Starving Bandits** and **Dust Bandits** to maximum hostility (-100.0).
- **Logic**:
  - Accesses the active dialogue via `currentDialogue`.
  - Queries `GameWorld.factionMgr` for the target factions ("Starving Bandits" and "Dust Bandits").
  - Logs the relation shift to the console via `KenshiLua.log()`.
  - Applies `-100.0` relation bidirectionally using `relations:setRelation(targetFaction, newRel)`.
  - Closes the dialogue context cleanly using `dialogue:endDialogue(true)`.

### 3. Reset Relations (`dialogue/faction_relation_change_reset_dialogue.lua`)
- **Action**: Resets mutual relations between the **Starving Bandits** and **Dust Bandits** to neutral (0.0).
- **Logic**:
  - Accesses the active dialogue via `currentDialogue`.
  - Queries `GameWorld.factionMgr` for the target factions ("Starving Bandits" and "Dust Bandits").
  - Logs the relation shift to the console via `KenshiLua.log()`.
  - Applies `0.0` relation bidirectionally using `relations:setRelation(targetFaction, newRel)`.
  - Closes the dialogue context cleanly using `dialogue:endDialogue(true)`.

## How It Works

### Mod File Setup
In the FCS, `LUA_SCRIPT` entries are assigned as "run script" action references on individual dialogue options. When selected in-game, KenshiLua intercepts the option and executes the designated script file.

### Dialogue Context & Global Helpers
- **`currentDialogue`**: Passed into the script context by KenshiLua during hook execution.
- **`GameWorld` / `getGameWorld()`**: Exposes `factionMgr` to look up factions by name (`getFactionByName`).
- **`FactionRelations`**: Provides methods `getFactionRelation(targetFaction)` and `setRelation(targetFaction, value)` to read and update faction standing dynamically.
