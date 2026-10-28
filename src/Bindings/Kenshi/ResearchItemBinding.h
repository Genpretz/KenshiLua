#pragma once
#include "kenshi/Research.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ResearchItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ResearchItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getCostItem(lua_State* L);
    static int getCostItemQuantity(lua_State* L);
    static int getNumDifferentCostItems(lua_State* L);
};
}
