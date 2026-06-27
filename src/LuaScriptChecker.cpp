#include "pch.h"
#include "LuaScriptChecker.h"
#include <kenshi/GameWorld.h>
#include <kenshi/GameData.h>
#include <kenshi/Globals.h>
#include <kenshi/ModInfo.h>
#include <kenshi/Dialogue.h>
#include <kenshi/WorldEventStateQuery.h>
#include <kenshi/util/lektor.h>
#include "Lua/Logger.h"
#include "Lua/LuaState.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/DialogueBinding.h"
#include "ModLoader.h"

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/system/error_code.hpp>
#include <core/Functions.h>

#include <sstream>
#include <vector>
#include <unordered_map>

namespace fs = boost::filesystem;

namespace KenshiLua
{
    // Extern pointer to the global LuaState singleton
    extern LuaState* g_luaState;

    // Reusable helper to extract the script filename from a LUA_SCRIPT GameData item
    static std::string getLuaScriptFilename(GameData* target)
    {
        if (!target) return "";
        auto sdataIt = target->sdata.find("filename");
        if (sdataIt != target->sdata.end()) return sdataIt->second;
        auto filesdataIt = target->filesdata.find("filename");
        if (filesdataIt != target->filesdata.end()) return filesdataIt->second;
        return "";
    }

    // Loads and executes a Lua script file in its own sandbox environment (_ENV)
    static bool RunLuaScriptSandboxed(lua_State* L, const std::string& absolutePath, const std::string& chunkName, bool expectBoolResult, bool& outResult)
    {
        if (!L) return false;
        int top = lua_gettop(L);

        fs::path path(absolutePath);
        fs::ifstream f(path, std::ios::binary | std::ios::ate);
        if (!f)
        {
            KenshiLua::logToFile("LuaScriptChecker: could not open script: " + absolutePath);
            return false;
        }

        std::streamsize sz = f.tellg();
        f.seekg(0, std::ios::beg);
        std::string buf;
        if (sz > 0)
        {
            buf.resize(static_cast<size_t>(sz));
            if (!f.read(&buf[0], sz))
            {
                KenshiLua::logToFile("LuaScriptChecker: failed to read script: " + absolutePath);
                lua_settop(L, top);
                return false;
            }
        }

        int loadResult = luaL_loadbuffer(L, buf.data(), buf.size(), chunkName.c_str());
        if (loadResult != LUA_OK)
        {
            const char* err = lua_tostring(L, -1);
            KenshiLua::logToFile("LuaScriptChecker: load failed for " + chunkName + " : " + (err ? err : "load error"));
            lua_settop(L, top);
            return false;
        }

        // Create sandbox environment table: stack [chunk, env]
        lua_newtable(L);

        // Meta table for sandbox table to allow fallback to global _G: stack [chunk, env, meta]
        lua_newtable(L);
        lua_pushglobaltable(L);         // stack [chunk, env, meta, _G]
        lua_setfield(L, -2, "__index");  // meta.__index = _G; stack [chunk, env, meta]
        lua_setmetatable(L, -2);        // setmetatable(env, meta); stack [chunk, env]

        // Self-reference _ENV inside the sandbox: stack [chunk, env, env]
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "_ENV");    // env._ENV = env; stack [chunk, env]

        // Setup environment as the first upvalue for the loaded chunk
        if (lua_setupvalue(L, -2, 1) == 0)
        {
            // Upvalue setup not successful (chunk might have no global references). Pop env.
            lua_pop(L, 1);
        }

        int nresults = expectBoolResult ? 1 : 0;
        if (lua_pcall(L, 0, nresults, 0) != LUA_OK)
        {
            const char* err = lua_tostring(L, -1);
            KenshiLua::logToFile("LuaScriptChecker: runtime error in " + chunkName + " : " + (err ? err : "unknown runtime error"));
            lua_settop(L, top);
            return false;
        }

        bool success = true;
        if (expectBoolResult)
        {
            if (lua_isboolean(L, -1))
            {
                outResult = (lua_toboolean(L, -1) != 0);
            }
            else
            {
                // Treat any truthy value as true, nil/false as false
                outResult = (lua_toboolean(L, -1) != 0);
            }
        }

        lua_settop(L, top);
        return success;
    }

    // ---------------------------------------------------------------------------
    // Hook implementation: Dialogue::_doActions
    // ---------------------------------------------------------------------------
    static void (*Dialogue_doActions_orig)(Dialogue*, DialogLineData*) = nullptr;

    static void Dialogue_doActions_hook(Dialogue* thisptr, DialogLineData* dialogLine)
    {
        if (dialogLine && dialogLine->data)
        {
            GameData* gd = dialogLine->data;
            auto refIt = gd->objectReferences.find("run script");
            if (refIt != gd->objectReferences.end())
            {
                const auto& refVector = refIt->second;
                for (size_t i = 0; i < refVector.size(); ++i)
                {
                    const auto& ref = refVector[i];
                    GameData* target = ref.ptr;
                    if (!target && ::ou)
                    {
                        target = ::ou->gamedata.getData(ref.sid);
                    }

                    if (target && static_cast<int>(target->type) == 148) // LUA_SCRIPT
                    {
                        std::string filename = getLuaScriptFilename(target);
                        if (!filename.empty())
                        {
                            std::string absolutePath = ModLoader::get().resolveScriptPath(filename);
                            if (!absolutePath.empty())
                            {
                                KenshiLua::logToFile("LuaScriptChecker: Triggered Dialogue action Lua script: " + filename);
                                lua_State* L = g_luaState ? g_luaState->getState() : nullptr;
                                if (L)
                                {
                                    pushObject<Dialogue>(L, thisptr, DialogueBinding::getMetatableName());
                                    lua_setglobal(L, "currentDialogue");

                                    bool dummy = false;
                                    RunLuaScriptSandboxed(L, absolutePath, "@" + filename, false, dummy);

                                    lua_pushnil(L);
                                    lua_setglobal(L, "currentDialogue");
                                }
                            }
                            else
                            {
                                KenshiLua::logToFile("LuaScriptChecker: Script file " + filename + " referenced by Dialogue not found in active mods.");
                            }
                        }
                    }
                }
            }
        }

        // Call original Dialogue::_doActions function
        Dialogue_doActions_orig(thisptr, dialogLine);
    }

    // ---------------------------------------------------------------------------
    // Hook implementation: WorldEventStateQuery::isTrue
    // ---------------------------------------------------------------------------
    static bool (*WorldEventStateQuery_isTrue_orig)(const WorldEventStateQuery*) = nullptr;

    // Map cache to associate WorldEventStateQuery* with its GameData* owner
    static std::unordered_map<const WorldEventStateQuery*, GameData*> g_queryToGameDataMap;
    static bool g_queryMapPopulated = false;

    static void PopulateQueryToGameDataMap()
    {
        if (g_queryMapPopulated || !::ou) return;

        const auto& mainList = ::ou->gamedata.mainList;
        for (auto it = mainList.begin(); it != mainList.end(); ++it)
        {
            GameData* gd = *it;
            if (gd && gd->type == WORLD_EVENT_STATE)
            {
                WorldEventStateQuery* query = WorldEventStateQuery::getFromData(gd);
                if (query)
                {
                    g_queryToGameDataMap[query] = gd;
                }
            }
        }
        g_queryMapPopulated = true;
    }

    // Helper to find which GameData* corresponds to a WorldEventStateQuery* pointer
    static GameData* GetGameDataFromWorldEventStateQuery(const WorldEventStateQuery* query)
    {
        PopulateQueryToGameDataMap();
        auto it = g_queryToGameDataMap.find(query);
        if (it != g_queryToGameDataMap.end())
        {
            return it->second;
        }
        return nullptr;
    }

    static bool WorldEventStateQuery_isTrue_hook(const WorldEventStateQuery* thisptr)
    {
        if (thisptr)
        {
            GameData* gd = GetGameDataFromWorldEventStateQuery(thisptr);
            if (gd)
            {
                auto refIt = gd->objectReferences.find("run script");
                if (refIt != gd->objectReferences.end())
                {
                    const auto& refVector = refIt->second;
                    for (size_t i = 0; i < refVector.size(); ++i)
                    {
                        const auto& ref = refVector[i];
                        GameData* target = ref.ptr;
                        if (!target && ::ou)
                        {
                            target = ::ou->gamedata.getData(ref.sid);
                        }

                        if (target && static_cast<int>(target->type) == 148) // LUA_SCRIPT
                        {
                            std::string filename = getLuaScriptFilename(target);
                            if (!filename.empty())
                            {
                                std::string absolutePath = ModLoader::get().resolveScriptPath(filename);
                                if (!absolutePath.empty())
                                {
                                    KenshiLua::logToFile("LuaScriptChecker: Evaluating WorldEventStateQuery Lua script: " + filename);
                                    lua_State* L = g_luaState ? g_luaState->getState() : nullptr;
                                    if (L)
                                    {
                                        bool scriptResult = false;
                                        if (RunLuaScriptSandboxed(L, absolutePath, "@" + filename, true, scriptResult))
                                        {
                                            KenshiLua::logToFilef("LuaScriptChecker: WorldEventStateQuery script returned %s", scriptResult ? "true" : "false");
                                            return scriptResult;
                                        }
                                    }
                                }
                                else
                                {
                                    KenshiLua::logToFile("LuaScriptChecker: Script file " + filename + " referenced by WorldEventStateQuery not found in active mods.");
                                }
                            }
                        }
                    }
                }
            }
        }

        // Call original WorldEventStateQuery::isTrue function
        return WorldEventStateQuery_isTrue_orig(thisptr);
    }

    // ---------------------------------------------------------------------------
    // Install Hooks entry point
    // ---------------------------------------------------------------------------
    void InstallLuaScriptCheckerHooks()
    {
        // Hook Dialogue::_doActions
        intptr_t doActionsAddr = KenshiLib::GetRealAddress(&Dialogue::_doActions);
        if (doActionsAddr)
        {
            KenshiLib::HookStatus status = KenshiLib::AddHook(doActionsAddr, Dialogue_doActions_hook, &Dialogue_doActions_orig);
            if (status == KenshiLib::SUCCESS)
            {
                KenshiLua::logToFile("LuaScriptChecker: Hooked Dialogue::_doActions successfully.");
            }
            else
            {
                KenshiLua::logToFilef("LuaScriptChecker: Failed to hook Dialogue::_doActions (status %d).", (int)status);
            }
        }
        else
        {
            KenshiLua::logToFile("LuaScriptChecker: Failed to resolve address for Dialogue::_doActions.");
        }

        // Hook WorldEventStateQuery::isTrue
        intptr_t isTrueAddr = KenshiLib::GetRealAddress(&WorldEventStateQuery::isTrue);
        if (isTrueAddr)
        {
            KenshiLib::HookStatus status = KenshiLib::AddHook(isTrueAddr, WorldEventStateQuery_isTrue_hook, &WorldEventStateQuery_isTrue_orig);
            if (status == KenshiLib::SUCCESS)
            {
                KenshiLua::logToFile("LuaScriptChecker: Hooked WorldEventStateQuery::isTrue successfully.");
            }
            else
            {
                KenshiLua::logToFilef("LuaScriptChecker: Failed to hook WorldEventStateQuery::isTrue (status %d).", (int)status);
            }
        }
        else
        {
            KenshiLua::logToFile("LuaScriptChecker: Failed to resolve address for WorldEventStateQuery::isTrue.");
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
        ss << "--- Scanning GameData for LUA_SCRIPT (148) ---\n";

        const int targetItemType = 148;
        int luaScriptCount = 0;
        int referenceCount = 0;

        // Iterate over ou->gamedata.mainList
        const auto& mainList = ::ou->gamedata.mainList;
        ss << "Total GameData items in mainList: " << mainList.size() << "\n\n";

        // Step 1: Find and list all LUA_SCRIPT items
        ss << "LUA_SCRIPT Items:\n";
        for (auto it = mainList.begin(); it != mainList.end(); ++it)
        {
            GameData* gd = *it;
            if (!gd) continue;

            if (static_cast<int>(gd->type) == targetItemType)
            {
                luaScriptCount++;
                ss << "- StringID: \"" << gd->stringID << "\", Name: \"" << gd->name << "\"\n";

                // Print filename if it is specified in sdata or filesdata
                auto sdataIt = gd->sdata.find("filename");
                if (sdataIt != gd->sdata.end())
                {
                    ss << "    filename (sdata): \"" << sdataIt->second << "\"\n";
                }
                auto filesdataIt = gd->filesdata.find("filename");
                if (filesdataIt != gd->filesdata.end())
                {
                    ss << "    filename (filesdata): \"" << filesdataIt->second << "\"\n";
                }
            }
        }
        ss << "Total LUA_SCRIPT items found: " << luaScriptCount << "\n\n";

        // Step 2: Scan for any references pointing to these items
        ss << "References to LUA_SCRIPT Items:\n";
        for (auto it = mainList.begin(); it != mainList.end(); ++it)
        {
            GameData* gd = *it;
            if (!gd) continue;

            // Look through all lists of references in objectReferences
            for (auto refListIt = gd->objectReferences.begin(); refListIt != gd->objectReferences.end(); ++refListIt)
            {
                const std::string& refFieldName = refListIt->first;
                const auto& refVector = refListIt->second;

                for (size_t i = 0; i < refVector.size(); ++i)
                {
                    const auto& ref = refVector[i];
                    bool isTargetRef = false;
                    GameData* target = ref.ptr;

                    if (target)
                    {
                        if (static_cast<int>(target->type) == targetItemType)
                        {
                            isTargetRef = true;
                        }
                    }
                    else
                    {
                        // Resolve pointer by string ID if ptr is null
                        GameData* resolved = ::ou->gamedata.getData(ref.sid);
                        if (resolved && static_cast<int>(resolved->type) == targetItemType)
                        {
                            isTargetRef = true;
                            target = resolved;
                        }
                    }

                    if (isTargetRef)
                    {
                        referenceCount++;
                        ss << "- Item Type: " << static_cast<int>(gd->type)
                           << " (\"" << gd->stringID << "\" / \"" << gd->name << "\")\n"
                           << "    Field: \"" << refFieldName << "\"\n"
                           << "    Points to: \"" << ref.sid << "\"";
                        if (target)
                        {
                            ss << " (Name: \"" << target->name << "\")";
                        }
                        ss << "\n";
                    }
                }
            }
        }
        ss << "Total references to LUA_SCRIPT items: " << referenceCount << "\n";
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
