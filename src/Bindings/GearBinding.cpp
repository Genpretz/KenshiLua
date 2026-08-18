#include "pch.h"
#include "kenshi\Gear.h"
#include "GearBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static Gear* getInstance(lua_State* L, int idx)
{
    return checkObject<Gear>(L, idx, GearBinding::getMetatableName());
}

// --- Getters for Gear ---
static int Gear_get_isUniform(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    return pushObject<Faction>(L, instance->isUniform, FactionBinding::getMetatableName());
}

static int Gear_get_value(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    lua_pushinteger(L, instance->value);
    return 1;
}

static int Gear_get_crafter(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    lua_pushstring(L, instance->crafter.c_str());
    return 1;
}

static int Gear_get_level(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    lua_pushnumber(L, instance->level);
    return 1;
}

static int Gear_get_level_0_100(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    lua_pushinteger(L, instance->level_0_100);
    return 1;
}

// --- Setters for Gear ---
static int Gear_set_isUniform(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    instance->isUniform = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int Gear_set_value(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    instance->value = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Gear_set_crafter(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    instance->crafter = luaL_checkstring(L, 2);
    return 0;
}

static int Gear_set_level(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    instance->level = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Gear_set_level_0_100(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");
    instance->level_0_100 = (int)luaL_checkinteger(L, 2);
    return 0;
}

int GearBinding::isGear(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    Gear* result = instance->isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int GearBinding::_NV_isGear(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    Gear* result = instance->_NV_isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int GearBinding::getLevel01(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    float result = instance->getLevel01();
    lua_pushnumber(L, result);
    return 1;
}

int GearBinding::_NV_getLevel01(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    float result = instance->_NV_getLevel01();
    lua_pushnumber(L, result);
    return 1;
}

int GearBinding::getLevel(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    int result = instance->getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int GearBinding::_NV_getLevel(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    int result = instance->_NV_getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int GearBinding::isAFactionUniform(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    Faction* result = instance->isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int GearBinding::_NV_isAFactionUniform(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    Faction* result = instance->_NV_isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int GearBinding::_serialise(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GearBinding::_NV__serialise(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_NV__serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GearBinding::_loadFromSerialise(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_loadFromSerialise(container, state);
    return 0;
}

int GearBinding::_NV__loadFromSerialise(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_NV__loadFromSerialise(container, state);
    return 0;
}

int GearBinding::isPlayerCrafted(lua_State* L)
{
    Gear* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Gear is nil");

    bool result = instance->isPlayerCrafted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
*/

int GearBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GearBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Gear object");
    return 1;
}



int GearBinding::_NV_setInventoryWeAreIn(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->_NV_setInventoryWeAreIn(*h);
    return 0;
}


int GearBinding::setInventoryWeAreIn(lua_State* L)
{
    Item* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Item is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->setInventoryWeAreIn(*h);
    return 0;
}


void GearBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GearBinding::gc },
        { "__tostring", GearBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isGear", GearBinding::isGear },
        { "_NV_isGear", GearBinding::_NV_isGear },
        { "getLevel01", GearBinding::getLevel01 },
        { "_NV_getLevel01", GearBinding::_NV_getLevel01 },
        { "getLevel", GearBinding::getLevel },
        { "_NV_getLevel", GearBinding::_NV_getLevel },
        { "isAFactionUniform", GearBinding::isAFactionUniform },
        { "_NV_isAFactionUniform", GearBinding::_NV_isAFactionUniform },
        { "_serialise", GearBinding::_serialise },
        { "_NV__serialise", GearBinding::_NV__serialise },
        { "_loadFromSerialise", GearBinding::_loadFromSerialise },
        { "_NV__loadFromSerialise", GearBinding::_NV__loadFromSerialise },
        { "isPlayerCrafted", GearBinding::isPlayerCrafted },
                { "setInventoryWeAreIn", GearBinding::setInventoryWeAreIn },
        { "_NV_setInventoryWeAreIn", GearBinding::_NV_setInventoryWeAreIn },
        { 0, 0 }
    };

    registerClass(
        L, 
        GearBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GearBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "isUniform", Gear_get_isUniform);
    registerGetter(L, "value", Gear_get_value);
    registerGetter(L, "crafter", Gear_get_crafter);
    registerGetter(L, "level", Gear_get_level);
    registerGetter(L, "level_0_100", Gear_get_level_0_100);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "isUniform", Gear_set_isUniform);
    registerSetter(L, "value", Gear_set_value);
    registerSetter(L, "crafter", Gear_set_crafter);
    registerSetter(L, "level", Gear_set_level);
    registerSetter(L, "level_0_100", Gear_set_level_0_100);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Item
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, GearBinding::getMetatableName(), ItemBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
