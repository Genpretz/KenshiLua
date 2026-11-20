#include "pch.h"
#include "Lua/LuaLock.h"
#include "WorldStateScriptBridge.h"
#include <kenshi/GameWorld.h>
#include <kenshi/GameData.h>
#include <kenshi/Globals.h>
#include <kenshi/Enums.h>
#include <kenshi/WorldEventStateQuery.h>
#include "Logger.h"
#include "Plugin.h"
#include "Lua/LuaState.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryBinding.h"
#include "ScriptLoader.h"

#include <string>
#include <vector>

namespace KenshiLua
{
    namespace
    {
        const int LUA_SCRIPT_ITEM_TYPE = 322; // enum itemType {LUA_SCRIPT = 322} in fcs.def

        enum WorldStateScriptMode
        {
            RUN_WHEN_TRUE = 0,
            RUN_WHEN_TRUE_OR_LOADED_TRUE = 1,
            RUN_WHEN_FALSE = 2
        };

        struct WorldStateScript
        {
            WorldStateScript(const std::string& scriptFilename, int scriptMode)
                : filename(scriptFilename), mode(scriptMode)
            {
            }

            std::string filename;
            int mode;
        };

        struct WatchedWorldState
        {
            GameData* data;
            // Owned by the engine's WorldEventStateQuery::statesData cache, which
            // is only cleared at process exit.
            WorldEventStateQuery* query;
            std::vector<WorldStateScript> scripts;
            bool wasTrue;
        };

        std::vector<WatchedWorldState> s_watched;

        // Set at startup and by GameWorld::resetGame, which may run on any thread.
        volatile LONG s_needsBaseline = 1;

        void collectScripts(GameData* gd, std::vector<WorldStateScript>& out)
        {
            const Ogre::vector<GameDataReference>::type* refList = gd->getReferenceListIfExists("run lua script");
            if (!refList || !gd->sourceContainer)
                return;

            for (auto it = refList->begin(); it != refList->end(); ++it)
            {
                GameData* scriptData = it->getPtr(gd->sourceContainer);
                if (!scriptData || scriptData->type != LUA_SCRIPT_ITEM_TYPE)
                    continue;

                auto fileIt = scriptData->filesdata.find("file");
                if (fileIt == scriptData->filesdata.end() || fileIt->second.empty())
                    continue;

                int mode = it->values.value[0];
                if (mode < RUN_WHEN_TRUE || mode > RUN_WHEN_FALSE)
                {
                    logToFileError("WorldStateScriptBridge: invalid run mode "
                        + std::to_string((long long)mode) + " for Lua script '" + fileIt->second
                        + "' on world state " + gd->stringID + "; expected 0, 1, or 2");
                    continue;
                }

                out.push_back(WorldStateScript(fileIt->second, mode));
            }
        }

        void runScripts(lua_State* L, const WatchedWorldState& state, int mode, const char* reason)
        {
            for (size_t i = 0; i < state.scripts.size(); ++i)
            {
                const WorldStateScript& script = state.scripts[i];
                if (script.mode != mode)
                    continue;

                std::string absolutePath = ScriptLoader::get().resolveScriptPath(script.filename);
                if (absolutePath.empty())
                {
                    logToFileError("WorldStateScriptBridge: could not resolve Lua script '" + script.filename
                        + "' for world state " + state.data->stringID);
                    continue;
                }

                logToFile("WorldStateScriptBridge: world state " + state.data->stringID
                    + " " + reason + "; running Lua script: " + script.filename);

                pushObject<GameData>(L, state.data, GameDataBinding::getMetatableName());
                lua_setglobal(L, "currentWorldEventState");

                pushObject<WorldEventStateQuery>(L, state.query, WorldEventStateQueryBinding::getMetatableName());
                lua_setglobal(L, "currentWorldEventStateQuery");

                ScriptLoader::get().runScriptSandboxed(L, absolutePath, "@" + script.filename);

                lua_pushnil(L);
                lua_setglobal(L, "currentWorldEventState");

                lua_pushnil(L);
                lua_setglobal(L, "currentWorldEventStateQuery");

                if (s_needsBaseline)
                    return;
            }
        }

        // Rebuilds the watch list and records each state's current value.
        void takeBaseline(lua_State* L)
        {
            s_watched.clear();

            const auto& mainList = ::ou->gamedata.mainList;
            for (auto it = mainList.begin(); it != mainList.end(); ++it)
            {
                GameData* gd = *it;
                if (!gd || gd->type != WORLD_EVENT_STATE)
                    continue;

                WatchedWorldState state;
                collectScripts(gd, state.scripts);
                if (state.scripts.empty())
                    continue;

                state.data = gd;
                state.query = WorldEventStateQuery::getFromData(gd);
                if (!state.query)
                    continue;
                state.wasTrue = state.query->isTrue();
                s_watched.push_back(state);
            }

            logToFileDebugf("WorldStateScriptBridge: watching %u world state(s) with Lua scripts.", (unsigned)s_watched.size());

            for (size_t i = 0; i < s_watched.size(); ++i)
            {
                const WatchedWorldState& state = s_watched[i];
                if (state.wasTrue)
                    runScripts(L, state, RUN_WHEN_TRUE_OR_LOADED_TRUE, "was true after load");

                // A script that starts a load or new game invalidates the remaining states.
                if (s_needsBaseline)
                    return;
            }
        }
    }

    void WorldStateScriptBridgeReset()
    {
        InterlockedExchange(&s_needsBaseline, 1);
    }

    void WorldStateScriptBridgeUpdate()
    {
        if (!Plugin::get().isInitialized() || !Plugin::get().isLuaThread() || !::ou)
            return;
        KenshiLua::ScopedLuaLock luaLock;

        // World states can read as false while a save is still loading.
        if (::ou->isLoadingFromASaveGame())
        {
            WorldStateScriptBridgeReset();
            return;
        }

        lua_State* L = g_luaState ? g_luaState->getState() : NULL;
        if (!L)
            return;

        if (InterlockedExchange(&s_needsBaseline, 0) != 0)
        {
            takeBaseline(L);
            return;
        }

        for (size_t i = 0; i < s_watched.size(); ++i)
        {
            WatchedWorldState& state = s_watched[i];
            bool isTrue = state.query->isTrue();
            bool becameTrue = isTrue && !state.wasTrue;
            bool becameFalse = !isTrue && state.wasTrue;
            state.wasTrue = isTrue;

            if (becameTrue)
            {
                runScripts(L, state, RUN_WHEN_TRUE, "became true");
                if (s_needsBaseline)
                    return;
                runScripts(L, state, RUN_WHEN_TRUE_OR_LOADED_TRUE, "became true");
            }
            else if (becameFalse)
            {
                runScripts(L, state, RUN_WHEN_FALSE, "became false");
            }

            // A script that starts a load or new game invalidates the remaining states.
            if (s_needsBaseline)
                return;
        }
    }
}
