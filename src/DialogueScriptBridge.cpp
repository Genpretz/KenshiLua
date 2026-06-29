#include "pch.h"
#include "DialogueScriptBridge.h"
#include <kenshi/GameWorld.h>
#include <kenshi/GameData.h>
#include <kenshi/Globals.h>
#include <kenshi/Dialogue.h>
#include "Logger.h"
#include "Lua/LuaState.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/DialogueBinding.h"
#include "ScriptLoader.h"
#include <core/Functions.h>

#include <sstream>
#include <vector>

namespace KenshiLua
{

    // ---------------------------------------------------------------------------
    // Hook implementation: Dialogue::_doActions
    // ---------------------------------------------------------------------------

    void DialogueScriptBridge(Dialogue* thisptr, DialogLineData* dialogLine)
    {
        if (dialogLine && dialogLine->data)
        {
            GameData* gd = dialogLine->data;
            auto sdataIt = gd->sdata.find("lua script");
            if (sdataIt != gd->sdata.end())
            {
                std::string filename = sdataIt->second;
                if (!filename.empty())
                {
                    std::string absolutePath = ScriptLoader::get().resolveScriptPath(filename);
                    if (!absolutePath.empty())
                    {
                        KenshiLua::logToFileDebug("DialogueScriptBridge: Triggered Dialogue action Lua script: " + filename);
                        lua_State* L = g_luaState ? g_luaState->getState() : nullptr;
                        if (L)
                        {
                            pushObject<Dialogue>(L, thisptr, DialogueBinding::getMetatableName());
                            lua_setglobal(L, "currentDialogue");

                            // Call the centralized sandboxed runner in ScriptLoader
                            ScriptLoader::get().runScriptSandboxed(L, absolutePath, "@" + filename);

                            lua_pushnil(L);
                            lua_setglobal(L, "currentDialogue");
                        }
                    }
                    else
                    {
                        KenshiLua::logToFileDebug("DialogueScriptBridge: Script file " + filename + " referenced by Dialogue not found in active mods.");
                    }
                }
            }
        }
    }

    // ---------------------------------------------------------------------------
    // Diagnostics check function
    // ---------------------------------------------------------------------------
    int luaCheckLuaScriptReferences(lua_State* L)
    {
        if (!::ou)
        {
            lua_pushstring(L, "Error: GameWorld (ou) is not initialized.");
            return 1;
        }

        std::stringstream ss;
        ss << "--- Scanning GameData for 'lua script' fields ---\n";

        int scriptFieldCount = 0;

        const auto& mainList = ::ou->gamedata.mainList;
        ss << "Total GameData items in mainList: " << mainList.size() << "\n\n";

        for (auto it = mainList.begin(); it != mainList.end(); ++it)
        {
            GameData* gd = *it;
            if (!gd) continue;

            auto sdataIt = gd->sdata.find("lua script");
            if (sdataIt != gd->sdata.end())
            {
                scriptFieldCount++;
                ss << "- Item Type: " << static_cast<int>(gd->type)
                   << " (\"" << gd->stringID << "\" / \"" << gd->name << "\")\n"
                   << "    lua script: \"" << sdataIt->second << "\"\n";
            }
        }
        ss << "Total items with 'lua script' fields: " << scriptFieldCount << "\n";
        ss << "--- Scan Complete ---\n";

        lua_pushstring(L, ss.str().c_str());
        return 1;
    }

    int luaGetGameData(lua_State* L)
    {
        if (!::ou)
        {
            lua_pushnil(L);
            return 1;
        }
        const char* sid = luaL_checkstring(L, 1);
        GameData* gd = ::ou->gamedata.getData(sid);
        if (!gd)
        {
            lua_pushnil(L);
            return 1;
        }
        pushObject<GameData>(L, gd, GameDataBinding::getMetatableName());
        return 1;
    }
}
