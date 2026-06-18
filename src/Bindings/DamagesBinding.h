#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
// Damages is a value type owned by Lua (placement-new into the userdata
// buffer; explicit ~Damages() in __gc).  Do NOT wrap engine-owned Damages
// instances with this binding without taking a copy first.
class DamagesBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Damages"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int createNew(lua_State* L);
    static int getCut(lua_State* L);
    static int setCut(lua_State* L);
    static int getBlunt(lua_State* L);
    static int setBlunt(lua_State* L);
    static int getPierce(lua_State* L);
    static int setPierce(lua_State* L);
    static int getBleed(lua_State* L);
    static int setBleed(lua_State* L);
    static int getArmourPenetration(lua_State* L);
    static int setArmourPenetration(lua_State* L);
    static int total(lua_State* L);
    static int multiply(lua_State* L);
};
}
