#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AttackSlotManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AttackSlotManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int hasFreeAttackSlot(lua_State* L);
    static int freeAllSlotsH(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int update(lua_State* L);
    static int getNumAttackSlots(lua_State* L);
    static int getMaxPossibleAttackSlots(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}
