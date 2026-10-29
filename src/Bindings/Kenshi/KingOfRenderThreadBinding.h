#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class KingOfRenderThreadBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.KingOfRenderThread"; }
    static void registerBinding(lua_State* L);

    static int startup(lua_State* L);
    static int initialisation(lua_State* L);
    static int mainloop(lua_State* L);
    static int newGame(lua_State* L);
    static int newGameWithCharEdit(lua_State* L);
    static int error(lua_State* L);
    static int errorD(lua_State* L);
    static int loadTerrain(lua_State* L);
    static int analyseModel(lua_State* L);
    static int getBonesVertices(lua_State* L);
    static int getMeshData(lua_State* L);
    static int addTerrainBloodSplat(lua_State* L);
    static int deleteTitleScreen(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

