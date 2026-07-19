#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SaveManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SaveManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isVisible(lua_State* L);
    static int showSave(lua_State* L);
    static int showLoad(lua_State* L);
    static int showImport(lua_State* L);
    static int hide(lua_State* L);
    static int newGame(lua_State* L);
    static int save(lua_State* L);
    static int savesExist(lua_State* L);
    static int saveExists(lua_State* L);
    static int execute(lua_State* L);
    static int versionCode(lua_State* L);
    static int updateAutoSave(lua_State* L);
    static int initialisePaths(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int saveGame(lua_State* L);
    static int loadGame(lua_State* L);
    static int importGame(lua_State* L);
    static int importPlayerBuildings(lua_State* L);
    static int importOldPlayerBuildings(lua_State* L);
};
}
