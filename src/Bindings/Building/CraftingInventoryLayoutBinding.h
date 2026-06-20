#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CraftingInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CraftingInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int refresh(lua_State* L);
    static int setOutputType(lua_State* L);
    static int setCraftingName(lua_State* L);
    static int getQueueButton(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}