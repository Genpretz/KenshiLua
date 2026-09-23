#pragma once

#include "kenshi/FactionRelations.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RelationDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RelationData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int save(lua_State* L);
    static int load(lua_State* L);
};
}