#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SwordBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Sword"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getClassType(lua_State* L);
    static int _NV_getClassType(lua_State* L);
    static int isSword(lua_State* L);
    static int _NV_isSword(lua_State* L);
    static int getSkillModIndoors(lua_State* L);
    static int _NV_getSkillModIndoors(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}
