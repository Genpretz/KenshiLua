#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CombatTechniqueDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CombatTechniqueData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int hasSkillType(lua_State* L);
    static int numImpactPoints(lua_State* L);
    static int impactPoint(lua_State* L);
};
}
