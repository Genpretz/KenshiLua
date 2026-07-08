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
#include "Bindings/DialogLineDataBinding.h"
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
        KenshiLua::logToFileDebug("DialogueScriptBridge entered.");
        if (!dialogLine)
        {
            KenshiLua::logToFileDebug("DialogueScriptBridge: dialogLine is null.");
            return;
        }
        if (!dialogLine->data)
        {
            KenshiLua::logToFileDebug("DialogueScriptBridge: dialogLine->data is null.");
            return;
        }

        GameData* gd = dialogLine->data;
        KenshiLua::logToFileDebug("DialogueScriptBridge: Checking GameData item Type=" + std::to_string((long long)gd->type) + " ID=" + gd->stringID + " Name=" + gd->name);

        // Log all filesdata keys
        for (auto it = gd->filesdata.begin(); it != gd->filesdata.end(); ++it)
        {
            KenshiLua::logToFileDebug("DialogueScriptBridge: filesdata key: '" + it->first + "' = '" + it->second + "'");
        }
        // Log all sdata keys
        for (auto it = gd->sdata.begin(); it != gd->sdata.end(); ++it)
        {
            KenshiLua::logToFileDebug("DialogueScriptBridge: sdata key: '" + it->first + "' = '" + it->second + "'");
        }

        auto filesdataIt = gd->filesdata.find("lua script");
        if (filesdataIt != gd->filesdata.end())
        {
            std::string filename = filesdataIt->second;
            KenshiLua::logToFileDebug("DialogueScriptBridge: Found lua script value: " + filename);
            if (!filename.empty())
            {
                std::string absolutePath = ScriptLoader::get().resolveScriptPath(filename);
                KenshiLua::logToFileDebug("DialogueScriptBridge: Resolved script path: " + absolutePath);
                if (!absolutePath.empty())
                {
                    KenshiLua::logToFile("DialogueScriptBridge: Triggered Dialogue action Lua script: " + filename);
                    lua_State* L = g_luaState ? g_luaState->getState() : nullptr;
                    if (L)
                    {
                        pushObject<Dialogue>(L, thisptr, DialogueBinding::getMetatableName());
                        lua_setglobal(L, "currentDialogue");

                        pushObject<DialogLineData>(L, dialogLine, DialogLineDataBinding::getMetatableName());
                        lua_setglobal(L, "currentDialogueLine");

                        // Call the centralized sandboxed runner in ScriptLoader
                        ScriptLoader::get().runScriptSandboxed(L, absolutePath, "@" + filename);

                        lua_pushnil(L);
                        lua_setglobal(L, "currentDialogue");

                        lua_pushnil(L);
                        lua_setglobal(L, "currentDialogueLine");
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

            auto filesdataIt = gd->filesdata.find("lua script");
            if (filesdataIt != gd->filesdata.end())
            {
                scriptFieldCount++;
                ss << "- Item Type: " << static_cast<int>(gd->type)
                   << " (\"" << gd->stringID << "\" / \"" << gd->name << "\")\n"
                   << "    lua script: \"" << filesdataIt->second << "\"\n";
            }
        }
        ss << "Total items with 'lua script' fields: " << scriptFieldCount << "\n";
        ss << "--- Scan Complete ---\n";

        lua_pushstring(L, ss.str().c_str());
        return 1;
    }
}
