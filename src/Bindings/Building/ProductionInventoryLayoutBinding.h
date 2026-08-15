#pragma once

#include "kenshi/Building/ProductionBuilding.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ProductionInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ProductionInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}