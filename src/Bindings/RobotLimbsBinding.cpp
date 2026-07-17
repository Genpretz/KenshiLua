#include "pch.h"
#include "kenshi\MedicalSystem.h"
#include "RobotLimbsBinding.h"
#include "RootObjectBinding.h"
#include "ItemBinding.h"
#include "CharacterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

typedef RobotLimbs::Limb Limb;

static RobotLimbs* getB(lua_State* L, int idx)
{
    return checkObject<RobotLimbs>(L, idx, RobotLimbsBinding::getMetatableName());
}

// --- Getters for RobotLimbs ---
static int RobotLimbs_get_character(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");
    return pushObject<Character>(L, b->character, CharacterBinding::getMetatableName());
}

static int RobotLimbs_get_inventory(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");
    return pushObject<RootObject>(L, b->inventory, RootObjectBinding::getMetatableName());
}

static int RobotLimbs_get_states(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");
    // TODO: Unsupported type for states (LimbState)
    return luaL_error(L, "Unsupported property 'states' (type: LimbState)");
}

static int RobotLimbs_get_items(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");
    lua_newtable(L);
    for (int i = 0; i < 4; ++i)
    {
        pushObject<Item>(L, b->items[i], ItemBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// --- Setters for RobotLimbs ---
static int RobotLimbs_set_character(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");
    return luaL_error(L, "Read-only or unsupported setter type for character");
}

static int RobotLimbs_set_inventory(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");
    return luaL_error(L, "Read-only or unsupported setter type for inventory");
}

static int RobotLimbs_set_states(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");
    return luaL_error(L, "Read-only or unsupported setter type for states");
}

static int RobotLimbs_set_items(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");
    return luaL_error(L, "Read-only or unsupported setter type for items");
}

int RobotLimbsBinding::_DESTRUCTOR(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");

    b->_DESTRUCTOR();
    return 0;
}

int RobotLimbsBinding::getLimb(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");

    Limb limb = (Limb)luaL_checkinteger(L, 2);
    Item* result = b->getLimb(limb);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int RobotLimbsBinding::getMask(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");

    int result = b->getMask();
    lua_pushinteger(L, result);
    return 1;
}

int RobotLimbsBinding::getInventoryInterface(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");

    bool create = lua_toboolean(L, 2) != 0;
    RootObject* result = b->getInventoryInterface(create);
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int RobotLimbsBinding::destroyInventoryInterface(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");

    b->destroyInventoryInterface();
    return 0;
}

int RobotLimbsBinding::getLimbItem(lua_State* L)
{
    RobotLimbs* b = getB(L, 1);
    if (!b) return luaL_error(L, "RobotLimbs is nil");

    Limb l = (Limb)luaL_checkinteger(L, 2);
    Item* result = b->getLimbItem(l);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 57: RobotLimbs* _CONSTRUCTOR(...) - unsupported arg type
  line 60: void load(...) - unsupported arg type
  line 61: void save(...) - unsupported arg type
  line 62: LimbState getState(...) - unsupported return type
  line 65: void setLimb(...) - unsupported arg type
*/

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
        { "_DESTRUCTOR", RobotLimbsBinding::_DESTRUCTOR },
        { "getLimb", RobotLimbsBinding::getLimb },
        { "getMask", RobotLimbsBinding::getMask },
        { "getInventoryInterface", RobotLimbsBinding::getInventoryInterface },
        { "destroyInventoryInterface", RobotLimbsBinding::destroyInventoryInterface },
        { "getLimbItem", RobotLimbsBinding::getLimbItem },
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