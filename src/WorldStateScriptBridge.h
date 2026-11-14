#pragma once

namespace KenshiLua
{
    // Runs the LUA_SCRIPT items in a WORLD_EVENT_STATE's "run lua script" list
    // according to each reference's configured transition mode. Called from
    // the GameWorld::charsUpdate hook, which does not run while the game is paused.
    void WorldStateScriptBridgeUpdate();

    // Called from the GameWorld::resetGame hook (load, import, new game). The
    // next update records each world state's current value. Only references
    // configured to run when loaded true execute during that baseline.
    void WorldStateScriptBridgeReset();
}
