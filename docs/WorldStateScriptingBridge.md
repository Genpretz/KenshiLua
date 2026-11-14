# World State Scripting Guide

The **`WorldStateScriptBridge`** is a subsystem within KenshiLua that runs Lua scripts when a Forgotten Construction Set (FCS) `WORLD_EVENT_STATE` changes between true and false. A world state can carry one or more `run lua script` references, and each reference selects when its script runs.

World state scripts use the same `LUA_SCRIPT` items, mod `scripts/` folder, and sandbox as dialogue scripts. The [Dialogue Scripting Guide](DialogueScriptingBridge.md) covers the shared parts: FCS Extended setup, creating a `LUA_SCRIPT` item, and the mod directory layout.

---

## Overview & Architecture

Kenshi only evaluates a world state when a dialogue condition, campaign, or town asks for it. KenshiLua instead checks every `WORLD_EVENT_STATE` that has a `run lua script` reference after each unpaused game update, so a script does not depend on anything else referencing the world state.

```text
+------------------+     Unpaused game update     +-------------------------------+
| Kenshi Engine    | ---------------------------> | GameWorld::charsUpdate        |
+------------------+                              +-------------------------------+
                                                                  |
                                                            (Hooked Call)
                                                                  v
                                                  +-------------------------------+
                                                  | WorldStateScriptBridge        |
                                                  +-------------------------------+
                                                                  |
                                  WorldEventStateQuery::isTrue()  | for each watched state
                                                                  v
                                                  +-------------------------------+
                                                  | Result changed?               |
                                                  | Run scripts whose mode        |
                                                  | matches the change            |
                                                  +-------------------------------+
                                                                  |
                                            Resolves path & sets  | globals
                                                                  v
                                                  +-------------------------------+
                                                  | Executes .lua Script          |
                                                  | currentWorldEventState        |
                                                  | currentWorldEventStateQuery   |
                                                  +-------------------------------+
```

### Execution Steps
1. **Baseline**: On the first unpaused update after KenshiLua starts, and after every load, import, or new game (`GameWorld::resetGame`), the bridge collects each `WORLD_EVENT_STATE` with `run lua script` references and records whether its complete state is true.
2. **Update Check**: On each later unpaused `GameWorld::charsUpdate`, the bridge calls `WorldEventStateQuery::isTrue()` for every watched state and compares the result with the previous one.
3. **Script Item Resolution**: For each reference whose mode matches the change, the bridge resolves the target `GameData` item of type `322` (`LUA_SCRIPT`) and reads its `"file"` attribute.
4. **Path Resolution**: `ScriptLoader` resolves the relative file path to the mod's `scripts/` directory.
5. **Global Injections**: Sets two transient global variables in the Lua state:
   - `currentWorldEventState` (`GameData*`)
   - `currentWorldEventStateQuery` (`WorldEventStateQuery*`)
6. **Sandboxed Execution**: Executes the target `.lua` script in a sandboxed environment.
7. **Cleanup**: Resets both globals to `nil` after the script completes.

---

## FCS Setup

World state scripts need **FCS Extended** and KenshiLua's `fcs.def`, as described in [FCS Setup with FCS Extended](DialogueScriptingBridge.md#fcs-setup-with-fcs-extended).

### Attaching a Script to a World State
1. Create a `LUA_SCRIPT` item as described in [Creating a `LUA_SCRIPT` Entry](DialogueScriptingBridge.md#creating-a-lua_script-entry).
2. Open the target **WORLD_EVENT_STATE** in FCS Extended.
3. Add a reference to the `LUA_SCRIPT` item in its **`run lua script`** list and set its mode value to `0`, `1`, or `2` as described below.
4. Save your `.mod` file.

---

## When the Script Runs

Each `run lua script` reference uses its first numeric value as its mode:

| Mode | When the script runs |
| :--- | :--- |
| `0` | When the complete world state changes from false to true. It does not run on load. |
| `1` | As mode `0`, and also after loading, importing, or starting a new game when the complete world state is already true. |
| `2` | When the complete world state changes from true to false. It does not run on load. |

- A script runs once per matching change, not continuously while the state remains true or false. Multiple scripts on one world state can use different modes.
- When a state becomes true, its mode `0` scripts run before its mode `1` scripts.
- After loading a save, importing, or starting a new game, the first check records each state's current value. Only mode `1` runs during this initial check, and only when the complete state is true.
- The checks run only while the game is unpaused. A change that happens and reverts while the game is paused does not run a script.
- The result is for the complete world state. An individual requirement changing does not trigger a script unless that change also changes the complete result.
- Kenshi evaluates a world state from its `NPC is`, `NPC is NOT`, `player ally`, and `player enemy` lists. Kenshi v1.0.65 does not read the `town okay` or `player involvement` fields when it builds a `WorldEventStateQuery`, so those fields do not affect when the script runs.
- A reference with any other mode value is skipped, and KenshiLua logs an error naming the script and the world state.

---

## Runtime Environment

During the execution of a world state script, the following globals are made available:

| Global Variable | Type | Description |
| :--- | :--- | :--- |
| `currentWorldEventState` | [`GameData`](BindingsReference.md#gamedata) | The `WORLD_EVENT_STATE` item whose configured script trigger occurred. |
| `currentWorldEventStateQuery` | [`WorldEventStateQuery`](BindingsReference.md#worldeventstatequery) | Kenshi's cached query for that item, as returned by `WorldEventStateQuery.getFromData`. |

Both globals are set only while the script runs and are reset to `nil` afterward. Scripts run on KenshiLua's Lua owner thread in the same sandbox as dialogue scripts. Any path under the mod's `scripts/` directory works; `scripts/worldstate/` is a convention.

### Example Lua Script (`scripts/worldstate/bandit_leader_dead.lua`)

```lua
if not currentWorldEventState or not currentWorldEventStateQuery then
    return
end

print(string.format("[WorldState] %s is now %s",
    currentWorldEventState.name,
    tostring(currentWorldEventStateQuery:isTrue())))
```

---

## Diagnostics & Troubleshooting

`KenshiLua.checkLuaScriptReferences()` lists every `run lua script` reference, as described in [Diagnostics & Troubleshooting](DialogueScriptingBridge.md#diagnostics--troubleshooting). For a `WORLD_EVENT_STATE`, the report also prints each reference's run mode before the script file:

```text
- Item Type: 110 ("12-my_mod.mod" / "Bandit leader dead")
    Reference ID: "13-my_mod.mod"
      World state run mode: 0
      -> Lua script file: "worldstate/bandit_leader_dead.lua"
```

### Common Issues & Checklist
1. **Script Never Runs**: The game must be unpaused. Confirm that the complete world state actually changes, for example by calling `WorldEventStateQuery.getFromData(gameData):isTrue()` from the console.
2. **Script Did Not Run After Load**: Only mode `1` runs when the state is already true after loading. Mode `0` waits for a change from false to true.
3. **Invalid Mode**: A mode other than `0`, `1`, or `2` is skipped and logged as an error in `KenshiLua.log`.
4. **Nil Globals Outside the Script**: `currentWorldEventState` and `currentWorldEventStateQuery` are valid only during the synchronous execution of the world state script.
