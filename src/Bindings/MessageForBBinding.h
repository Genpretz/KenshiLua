#pragma once

#include <kenshi/Enums.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MessageForBBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MessageForB"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);

    // Constructor
    static int create(lua_State* L);
};
} // namespace KenshiLua
