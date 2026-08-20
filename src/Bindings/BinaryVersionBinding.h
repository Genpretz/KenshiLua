#pragma once

#include <kenshi/Kenshi.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BinaryVersionBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BinaryVersion"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
    static int operator_lt(lua_State* L);

    // Methods
    static int GetPlatform(lua_State* L);
    static int GetPlatformStr(lua_State* L);
    static int GetBinaryName(lua_State* L);
    static int ToString(lua_State* L);
    static int GetVersion(lua_State* L);

    // Static function / Global
    static int GetKenshiVersion(lua_State* L);

    // Constructor
    static int create(lua_State* L);
};
} // namespace KenshiLua
