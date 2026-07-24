#include "pch.h"
#include "kenshi\MedicalSystem.h"
#include "RobotLimbsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

typedef RobotLimbs::Limb Limb;

static RobotLimbs* getInstance(lua_State* L, int idx)
{
    return checkObject<RobotLimbs>(L, idx, RobotLimbsBinding::getMetatableName());
}

// --- Getters for RobotLimbs ---
static int RobotLimbs_get_character(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");
    return pushObject<Character>(L, instance->character, CharacterBinding::getMetatableName());
}

static int RobotLimbs_get_inventory(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");
    return pushObject<RootObject>(L, instance->inventory, RootObjectBinding::getMetatableName());
}

static int RobotLimbs_get_states(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");
    lua_newtable(L);
    for (int i = 0; i < 4; ++i)
    {
        lua_pushinteger(L, (lua_Integer)instance->states[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int RobotLimbs_get_items(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");
    lua_newtable(L);
    for (int i = 0; i < 4; ++i)
    {
        pushObject<Item>(L, instance->items[i], ItemBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// --- Setters for RobotLimbs ---
static int RobotLimbs_set_character(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");
    instance->character = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int RobotLimbs_set_inventory(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");
    instance->inventory = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
}

static int RobotLimbs_set_states(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");
    if (!lua_istable(L, 2)) return luaL_error(L, "Argument 2 to set 'states' must be a table of 4 LimbState integers");
    for (int i = 0; i < 4; ++i)
    {
        lua_rawgeti(L, 2, i + 1);
        if (!lua_isnil(L, -1))
        {
            instance->states[i] = (LimbState)lua_tointeger(L, -1);
        }
        lua_pop(L, 1);
    }
    return 0;
}

static int RobotLimbs_set_items(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");
    if (!lua_istable(L, 2)) return luaL_error(L, "Argument 2 to set 'items' must be a table of 4 Item objects or nils");
    for (int i = 0; i < 4; ++i)
    {
        lua_rawgeti(L, 2, i + 1);
        if (lua_isnil(L, -1))
        {
            instance->items[i] = nullptr;
        }
        else
        {
            instance->items[i] = checkObject<Item>(L, -1, ItemBinding::getMetatableName());
        }
        lua_pop(L, 1);
    }
    return 0;
}

int RobotLimbsBinding::_CONSTRUCTOR(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    RobotLimbs* result = instance->_CONSTRUCTOR(c);
    return pushObject<RobotLimbs>(L, result, RobotLimbsBinding::getMetatableName());
}

int RobotLimbsBinding::_DESTRUCTOR(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int RobotLimbsBinding::load(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(state);
    return 0;
}

int RobotLimbsBinding::save(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(state);
    return 0;
}

int RobotLimbsBinding::getLimb(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    Limb limb = (Limb)luaL_checkinteger(L, 2);
    Item* result = instance->getLimb(limb);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int RobotLimbsBinding::getMask(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    int result = instance->getMask();
    lua_pushinteger(L, result);
    return 1;
}

int RobotLimbsBinding::getInventoryInterface(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    bool create = lua_toboolean(L, 2) != 0;
    RootObject* result = instance->getInventoryInterface(create);
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int RobotLimbsBinding::destroyInventoryInterface(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    instance->destroyInventoryInterface();
    return 0;
}

int RobotLimbsBinding::getLimbItem(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    Limb l = (Limb)luaL_checkinteger(L, 2);
    Item* result = instance->getLimbItem(l);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int RobotLimbsBinding::getState(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    Limb limb = (Limb)luaL_checkinteger(L, 2);
    LimbState result = instance->getState(limb);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int RobotLimbsBinding::setLimb(lua_State* L)
{
    RobotLimbs* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbs is nil");

    Limb limb = (Limb)luaL_checkinteger(L, 2);
    LimbState state = (LimbState)luaL_checkinteger(L, 3);
    Item* item = lua_isnoneornil(L, 4) ? nullptr : checkObject<Item>(L, 4, ItemBinding::getMetatableName());
    instance->setLimb(limb, state, item);
    return 0;
}

int RobotLimbsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RobotLimbsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RobotLimbs object");
    return 1;
}

void RobotLimbsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RobotLimbsBinding::gc },
        { "__tostring", RobotLimbsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", RobotLimbsBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", RobotLimbsBinding::_DESTRUCTOR },
        { "load", RobotLimbsBinding::load },
        { "save", RobotLimbsBinding::save },
        { "getLimb", RobotLimbsBinding::getLimb },
        { "getMask", RobotLimbsBinding::getMask },
        { "getInventoryInterface", RobotLimbsBinding::getInventoryInterface },
        { "destroyInventoryInterface", RobotLimbsBinding::destroyInventoryInterface },
        { "getLimbItem", RobotLimbsBinding::getLimbItem },
        { "getState", RobotLimbsBinding::getState },
        { "setLimb", RobotLimbsBinding::setLimb },
        { 0, 0 }
    };

    registerClass(
        L, 
        RobotLimbsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RobotLimbsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, RobotLimbs_get_character);
    lua_setfield(L, -2, "character");
    lua_pushcfunction(L, RobotLimbs_get_inventory);
    lua_setfield(L, -2, "inventory");
    lua_pushcfunction(L, RobotLimbs_get_states);
    lua_setfield(L, -2, "states");
    lua_pushcfunction(L, RobotLimbs_get_items);
    lua_setfield(L, -2, "items");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RobotLimbs_set_character);
    lua_setfield(L, -2, "character");
    lua_pushcfunction(L, RobotLimbs_set_inventory);
    lua_setfield(L, -2, "inventory");
    lua_pushcfunction(L, RobotLimbs_set_states);
    lua_setfield(L, -2, "states");
    lua_pushcfunction(L, RobotLimbs_set_items);
    lua_setfield(L, -2, "items");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
