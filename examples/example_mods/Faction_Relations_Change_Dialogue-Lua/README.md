# Faction Relations Dialogue (Lua Example Mod)

An example mod demonstrating how to use KenshiLua to dynamically modify faction relationship standings through dialogue choices in Kenshi's Forgotten Construction Set (FCS).

## Gameplay & Location

The mod spawns an NPC named **Lua** in the Bar inside **The Hub**. Interacting with Lua provides three distinct dialogue choices to manipulate faction relationships in real-time.

## Dialogue Options & Scripts

Each dialogue choice executes one of the Lua scripts stored in `scripts/dialogue/`:

### Maximize Relations (`scripts/dialogue/faction_relation_change_max_dialogue.lua`)

- **Action**: Sets mutual relations between the **Starving Bandits** and **Dust Bandits** to maximum alliance (+100.0).
- **Logic**:
  - Accesses the active dialogue via `currentDialogue`.
  - Queries `getGameWorld().factionMgr` for the target factions ("Starving Bandits" and "Dust Bandits").
  - Logs the relation shift to the console via `KenshiLua.log()`.
  - Applies `+100.0` relation bidirectionally using `relations:setRelation(targetFaction, newRel)`.
  - Closes the dialogue context cleanly using `dialogue:endDialogue(true)`.

### Minimize Relations (`scripts/dialogue/faction_relation_change_min_dialogue.lua`)

- **Action**: Sets mutual relations between the **Starving Bandits** and **Dust Bandits** to maximum hostility (-100.0).
- **Logic**:
  - Accesses the active dialogue via `currentDialogue`.
  - Queries `getGameWorld().factionMgr` for the target factions ("Starving Bandits" and "Dust Bandits").
  - Logs the relation shift to the console via `KenshiLua.log()`.
  - Applies `-100.0` relation bidirectionally using `relations:setRelation(targetFaction, newRel)`.
  - Closes the dialogue context cleanly using `dialogue:endDialogue(true)`.

### Reset Relations (`scripts/dialogue/faction_relation_change_reset_dialogue.lua`)

- **Action**: Resets mutual relations between the **Starving Bandits** and **Dust Bandits** to neutral (0.0).
- **Logic**:
  - Accesses the active dialogue via `currentDialogue`.
  - Queries `getGameWorld().factionMgr` for the target factions ("Starving Bandits" and "Dust Bandits").
  - Logs the relation shift to the console via `KenshiLua.log()`.
  - Applies `0.0` relation bidirectionally using `relations:setRelation(targetFaction, newRel)`.
  - Closes the dialogue context cleanly using `dialogue:endDialogue(true)`.

## How It Works

### FCS Setup

In the FCS, `LUA_SCRIPT` entries are assigned as "run lua script" action references on individual dialogue options. When selected in-game, KenshiLua intercepts the option and executes the designated script file. For full setup instructions, see the [Dialogue Scripting Guide](../../../docs/DialogueScriptingBridge.md).

### Dialogue Context & Global Helpers

- **`currentDialogue`**: Passed into the script context by KenshiLua during hook execution.
- **`getGameWorld()`**: Exposes `factionMgr` to look up factions by name (`getFactionByName`).
- **`FactionRelations`**: Provides methods `getFactionRelation(targetFaction)` and `setRelation(targetFaction, value)` to read and update faction standings dynamically.

