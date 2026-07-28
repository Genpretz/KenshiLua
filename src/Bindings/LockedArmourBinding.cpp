#include "pch.h"
#include "kenshi\Gear.h"
#include "LockedArmourBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ArmourBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "ArmourBinding.h"

namespace KenshiLua
{

static LockedArmour* getInstance(lua_State* L, int idx)
{
    return checkObject<LockedArmour>(L, idx, LockedArmourBinding::getMetatableName());
}

// --- Getters for LockedArmour ---
static int LockedArmour_get_lock(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");
    lua_pushlightuserdata(L, (void*)instance->lock);
    return 1;
}

// --- Setters for LockedArmour ---
int LockedArmourBinding::_CONSTRUCTOR(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    GameData* baseData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* _materialData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    hand _handle = *checkObject<hand>(L, 4, handBinding::getMetatableName());
    Faction* _uniformFlag = checkObject<Faction>(L, 5, FactionBinding::getMetatableName());
    int _level = (int)luaL_checkinteger(L, 6);
    LockedArmour* result = instance->_CONSTRUCTOR(baseData, _materialData, _handle, _uniformFlag, _level);
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int LockedArmourBinding::_DESTRUCTOR(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int LockedArmourBinding::isArmour(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    Armour* result = instance->isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int LockedArmourBinding::_NV_isArmour(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    Armour* result = instance->_NV_isArmour();
    return pushObject<Armour>(L, result, ArmourBinding::getMetatableName());
}

int LockedArmourBinding::isLockedArmour(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    LockedArmour* result = instance->isLockedArmour();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int LockedArmourBinding::_NV_isLockedArmour(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    LockedArmour* result = instance->_NV_isLockedArmour();
    return pushObject<LockedArmour>(L, result, LockedArmourBinding::getMetatableName());
}

int LockedArmourBinding::_serialise(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int LockedArmourBinding::_NV__serialise(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_NV__serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int LockedArmourBinding::_loadFromSerialise(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_loadFromSerialise(container, state);
    return 0;
}

int LockedArmourBinding::_NV__loadFromSerialise(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_NV__loadFromSerialise(container, state);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 233: void getTooltipData1(...) - unsupported arg type
  line 234: void _NV_getTooltipData1(...) - unsupported arg type
  line 235: void getTooltipData2(...) - unsupported arg type
  line 236: void _NV_getTooltipData2(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - LockedArmour_get_lock: DoorLock* (unbound pointer)
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



static int LockedArmour_set_lock(lua_State* L)
{
    LockedArmour* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LockedArmour is nil");
    return luaL_error(L, "Read-only or unsupported setter type for lock");
}


void LockedArmourBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LockedArmourBinding::gc },
        { "__tostring", LockedArmourBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", LockedArmourBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", LockedArmourBinding::_DESTRUCTOR },
        { "isArmour", LockedArmourBinding::isArmour },
        { "_NV_isArmour", LockedArmourBinding::_NV_isArmour },
        { "isLockedArmour", LockedArmourBinding::isLockedArmour },
        { "_NV_isLockedArmour", LockedArmourBinding::_NV_isLockedArmour },
        { "_serialise", LockedArmourBinding::_serialise },
        { "_NV__serialise", LockedArmourBinding::_NV__serialise },
        { "_loadFromSerialise", LockedArmourBinding::_loadFromSerialise },
        { "_NV__loadFromSerialise", LockedArmourBinding::_NV__loadFromSerialise },
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
    registerGetter(L, "lock", LockedArmour_get_lock);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
        registerSetter(L, "lock", LockedArmour_set_lock);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Armour
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, LockedArmourBinding::getMetatableName(), ArmourBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua