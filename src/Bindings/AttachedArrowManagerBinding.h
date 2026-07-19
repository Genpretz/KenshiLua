#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AttachedArrowManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AttachedArrowManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int clearAll(lua_State* L);
    static int updateStart(lua_State* L);
    static int addArrow(lua_State* L);
    static int updateEnd(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
};
}