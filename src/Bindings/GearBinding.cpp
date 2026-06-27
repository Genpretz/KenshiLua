#include "pch.h"
#include "kenshi\Gear.h"
#include "GearBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"

namespace KenshiLua
{

static Gear* getB(lua_State* L, int idx)
{
    return checkObject<Gear>(L, idx, GearBinding::getMetatableName());
}

// --- Getters for Gear ---
static int Gear_get_isUniform(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    return pushObject<Faction>(L, b->isUniform, FactionBinding::getMetatableName());
}

static int Gear_get_value(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    lua_pushinteger(L, b->value);
    return 1;
}

static int Gear_get_crafter(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    lua_pushstring(L, b->crafter.c_str());
    return 1;
}

static int Gear_get_level(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    lua_pushnumber(L, b->level);
    return 1;
}

static int Gear_get_level_0_100(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    lua_pushinteger(L, b->level_0_100);
    return 1;
}

// --- Setters for Gear ---
static int Gear_set_isUniform(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    return luaL_error(L, "Read-only or unsupported setter type for isUniform");
}

static int Gear_set_value(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    b->value = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Gear_set_crafter(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    b->crafter = luaL_checkstring(L, 2);
    return 0;
}

static int Gear_set_level(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    b->level = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Gear_set_level_0_100(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");
    b->level_0_100 = (int)luaL_checkinteger(L, 2);
    return 0;
}

int GearBinding::isGear(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    Gear* result = b->isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int GearBinding::_NV_isGear(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    Gear* result = b->_NV_isGear();
    return pushObject<Gear>(L, result, GearBinding::getMetatableName());
}

int GearBinding::getLevel01(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    float result = b->getLevel01();
    lua_pushnumber(L, result);
    return 1;
}

int GearBinding::_NV_getLevel01(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    float result = b->_NV_getLevel01();
    lua_pushnumber(L, result);
    return 1;
}

int GearBinding::getLevel(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    int result = b->getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int GearBinding::_NV_getLevel(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    int result = b->_NV_getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int GearBinding::isAFactionUniform(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    Faction* result = b->isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int GearBinding::_NV_isAFactionUniform(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    Faction* result = b->_NV_isAFactionUniform();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int GearBinding::isPlayerCrafted(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    bool result = b->isPlayerCrafted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GearBinding::_DESTRUCTOR(lua_State* L)
{
    Gear* b = getB(L, 1);
    if (!b) return luaL_error(L, "Gear is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: Gear* _CONSTRUCTOR(...) - unsupported arg type
  line 22: GameData* _serialise(...) - unsupported arg type
  line 23: GameData* _NV__serialise(...) - unsupported arg type
  line 24: void _loadFromSerialise(...) - unsupported arg type
  line 25: void _NV__loadFromSerialise(...) - unsupported arg type
  line 26: void setInventoryWeAreIn(...) - unsupported arg type
  line 27: void _NV_setInventoryWeAreIn(...) - unsupported arg type
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
        { "isPlayerCrafted", GearBinding::isPlayerCrafted },
        { "_DESTRUCTOR", GearBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, Gear_get_isUniform);
    lua_setfield(L, -2, "isUniform");
    lua_pushcfunction(L, Gear_get_value);
    lua_setfield(L, -2, "value");
    lua_pushcfunction(L, Gear_get_crafter);
    lua_setfield(L, -2, "crafter");
    lua_pushcfunction(L, Gear_get_level);
    lua_setfield(L, -2, "level");
    lua_pushcfunction(L, Gear_get_level_0_100);
    lua_setfield(L, -2, "level_0_100");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Gear_set_isUniform);
    lua_setfield(L, -2, "isUniform");
    lua_pushcfunction(L, Gear_set_value);
    lua_setfield(L, -2, "value");
    lua_pushcfunction(L, Gear_set_crafter);
    lua_setfield(L, -2, "crafter");
    lua_pushcfunction(L, Gear_set_level);
    lua_setfield(L, -2, "level");
    lua_pushcfunction(L, Gear_set_level_0_100);
    lua_setfield(L, -2, "level_0_100");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua