#include "pch.h"
#include "kenshi\Gear.h"
#include "LockedArmourBinding.h"
#include "ArmourBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static LockedArmour* getB(lua_State* L, int idx)
{
    return checkObject<LockedArmour>(L, idx, LockedArmourBinding::getMetatableName());
}

// --- Getters for LockedArmour ---
static int LockedArmour_get_lock(lua_State* L)
{
    LockedArmour* b = getB(L, 1);
    if (!b) return luaL_error(L, "LockedArmour is nil");
    // TODO: Unsupported type for lock (DoorLock*)
    lua_pushnil(L);
    return 1;
}

// --- Setters for LockedArmour ---
static int LockedArmour_set_lock(lua_State* L)
{
    LockedArmour* b = getB(L, 1);
    if (!b) return luaL_error(L, "LockedArmour is nil");
    return luaL_error(L, "Read-only or unsupported setter type for lock");
}

int LockedArmourBinding::_DESTRUCTOR(lua_State* L)
{
    LockedArmour* b = getB(L, 1);
    if (!b) return luaL_error(L, "LockedArmour is nil");

    b->_DESTRUCTOR();
    return 0;
}

int LockedArmourBinding::isArmour(lua_State* L)
{
    LockedArmour* b = getB(L, 1);
    if (!b) return luaL_error(L, "LockedArmour is nil");

    Armour* result = b->isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int LockedArmourBinding::_NV_isArmour(lua_State* L)
{
    LockedArmour* b = getB(L, 1);
    if (!b) return luaL_error(L, "LockedArmour is nil");

    Armour* result = b->_NV_isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int LockedArmourBinding::isLockedArmour(lua_State* L)
{
    LockedArmour* b = getB(L, 1);
    if (!b) return luaL_error(L, "LockedArmour is nil");

    LockedArmour* result = b->isLockedArmour();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int LockedArmourBinding::_NV_isLockedArmour(lua_State* L)
{
    LockedArmour* b = getB(L, 1);
    if (!b) return luaL_error(L, "LockedArmour is nil");

    LockedArmour* result = b->_NV_isLockedArmour();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 221: LockedArmour* _CONSTRUCTOR(...) - unsupported arg type
  line 229: GameData* _serialise(...) - unsupported arg type
  line 230: GameData* _NV__serialise(...) - unsupported arg type
  line 231: void _loadFromSerialise(...) - unsupported arg type
  line 232: void _NV__loadFromSerialise(...) - unsupported arg type
  line 233: void getTooltipData1(...) - unsupported arg type
  line 234: void _NV_getTooltipData1(...) - unsupported arg type
  line 235: void getTooltipData2(...) - unsupported arg type
  line 236: void _NV_getTooltipData2(...) - unsupported arg type
*/

int LockedArmourBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LockedArmourBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LockedArmour object");
    return 1;
}

void LockedArmourBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LockedArmourBinding::gc },
        { "__tostring", LockedArmourBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", LockedArmourBinding::_DESTRUCTOR },
        { "isArmour", LockedArmourBinding::isArmour },
        { "_NV_isArmour", LockedArmourBinding::_NV_isArmour },
        { "isLockedArmour", LockedArmourBinding::isLockedArmour },
        { "_NV_isLockedArmour", LockedArmourBinding::_NV_isLockedArmour },
        { 0, 0 }
    };

    registerClass(
        L, 
        LockedArmourBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LockedArmourBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, LockedArmour_get_lock);
    lua_setfield(L, -2, "lock");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, LockedArmour_set_lock);
    lua_setfield(L, -2, "lock");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua