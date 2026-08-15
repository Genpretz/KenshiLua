#pragma once

#include "kenshi/CombatClass.h"
namespace KenshiLua
{
class CombatClass_EffectDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CombatClass_EffectData"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
