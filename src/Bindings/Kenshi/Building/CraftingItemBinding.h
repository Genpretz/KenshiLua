#pragma once

#include "kenshi/Building/CraftingBuilding.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CraftingItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CraftingItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};
}
