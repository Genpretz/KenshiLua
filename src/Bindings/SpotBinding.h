#pragma once

#include "kenshi/SensoryData.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef SensoryData::SpottingPeopleMgr::Spot Spot;

class SpotBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Spot"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
};
}
