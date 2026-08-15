#pragma once

#include "kenshi/TradeCulture.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TradeCultureBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TradeCulture"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int reset(lua_State* L);
    static int getAllIllegalItems(lua_State* L);
    static int isItemIllegal(lua_State* L);
    static int getTradePriceMultiplier(lua_State* L);
    static int hasTradePriceMultiplier(lua_State* L);
    static int getForbiddenItemsList(lua_State* L);
};
}
