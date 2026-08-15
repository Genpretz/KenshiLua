#pragma once
#include <kenshi/SensoryData.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef SensoryData::SpottingPeopleMgr SpottingPeopleMgr;

class SpottingPeopleMgrBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SpottingPeopleMgr"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int resetSeenFlags(lua_State* L);
    static int update(lua_State* L);
    static int spot(lua_State* L);
    static int getTime(lua_State* L);
    static int cantSeeAnymore(lua_State* L);
    static int has(lua_State* L);
};
}
