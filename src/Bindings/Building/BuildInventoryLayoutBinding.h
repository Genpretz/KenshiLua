#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BuildInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BuildInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int setInput(lua_State* L);
    static int setOutput(lua_State* L);
    static int setInputProgress(lua_State* L);
    static int setInputEnabled(lua_State* L);
    static int setOutputProgress(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}