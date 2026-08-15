#pragma once
#include "kenshi/Faction.h"

namespace KenshiLua
{
class Faction_CharacteristicsDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Faction_CharacteristicsData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
