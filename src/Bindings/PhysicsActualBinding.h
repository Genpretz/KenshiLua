#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PhysicsActualBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PhysicsActual"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int updateUT(lua_State* L);
    static int _NV_updateUT(lua_State* L);
    static int backThreadUpdate(lua_State* L);
    static int _NV_backThreadUpdate(lua_State* L);
    static int threadJunkPreBT(lua_State* L);
    static int threadJunkPostBT(lua_State* L);
    static int setup(lua_State* L);
    static int scytheGetFirstModelName(lua_State* L);
    static int _createTriggerHull(lua_State* L);
    static int _createStaticCapsule(lua_State* L);
    static int _createStaticBox(lua_State* L);
    static int uncookMesh(lua_State* L);
};
}