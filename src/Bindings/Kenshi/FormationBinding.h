#pragma once
#include "kenshi/CharMovement.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FormationBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Formation"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int addToFormation(lua_State* L);
    static int _NV_addToFormation(lua_State* L);
    static int removeFromFormation(lua_State* L);
    static int _NV_removeFromFormation(lua_State* L);
    static int getFormationPos(lua_State* L);
    static int _NV_getFormationPos(lua_State* L);
};
}
