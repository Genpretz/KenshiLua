#pragma once
#include "pch.h"

namespace KenshiLua
{
class CombatClass_AttackSlotManager_SlotDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CombatClass_AttackSlotManager_SlotData"; }
    static void registerBinding(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
