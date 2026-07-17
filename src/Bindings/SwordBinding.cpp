#include "pch.h"
#include "kenshi\Gear.h"
#include "SwordBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Sword* getB(lua_State* L, int idx)
{
    return checkObject<Sword>(L, idx, SwordBinding::getMetatableName());
}

// --- Getters for Sword ---
static int Sword_get_cutDamage(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    lua_pushnumber(L, b->cutDamage);
    return 1;
}

static int Sword_get_bluntDamage(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    lua_pushnumber(L, b->bluntDamage);
    return 1;
}

static int Sword_get_minCutDamage(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    lua_pushnumber(L, b->minCutDamage);
    return 1;
}

static int Sword_get_modDefence(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    lua_pushinteger(L, b->modDefence);
    return 1;
}

static int Sword_get_modIndoors(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    lua_pushinteger(L, b->modIndoors);
    return 1;
}

// --- Setters for Sword ---
static int Sword_set_cutDamage(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    b->cutDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Sword_set_bluntDamage(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    b->bluntDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Sword_set_minCutDamage(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    b->minCutDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Sword_set_modDefence(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    b->modDefence = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Sword_set_modIndoors(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");
    b->modIndoors = (int)luaL_checkinteger(L, 2);
    return 0;
}

int SwordBinding::getClassType(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");

    itemType result = b->getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int SwordBinding::_NV_getClassType(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");

    itemType result = b->_NV_getClassType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int SwordBinding::isSword(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");

    Sword* result = b->isSword();
    return pushObject<Sword>(L, result, SwordBinding::getMetatableName());
}

int SwordBinding::_NV_isSword(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");

    Sword* result = b->_NV_isSword();
    return pushObject<Sword>(L, result, SwordBinding::getMetatableName());
}

int SwordBinding::getSkillModIndoors(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");

    int result = b->getSkillModIndoors();
    lua_pushinteger(L, result);
    return 1;
}

int SwordBinding::_NV_getSkillModIndoors(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");

    int result = b->_NV_getSkillModIndoors();
    lua_pushinteger(L, result);
    return 1;
}

int SwordBinding::_DESTRUCTOR(lua_State* L)
{
    Sword* b = getB(L, 1);
    if (!b) return luaL_error(L, "Sword is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 86: Sword* _CONSTRUCTOR(...) - unsupported arg type
  line 91: void setupStats(...) - unsupported arg type
  line 92: void getTooltipData1(...) - unsupported arg type
  line 93: void _NV_getTooltipData1(...) - unsupported arg type
  line 94: void getTooltipData2(...) - unsupported arg type
  line 95: void _NV_getTooltipData2(...) - unsupported arg type
*/

int SwordBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SwordBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Sword object");
    return 1;
}

void SwordBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SwordBinding::gc },
        { "__tostring", SwordBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getClassType", SwordBinding::getClassType },
        { "_NV_getClassType", SwordBinding::_NV_getClassType },
        { "isSword", SwordBinding::isSword },
        { "_NV_isSword", SwordBinding::_NV_isSword },
        { "getSkillModIndoors", SwordBinding::getSkillModIndoors },
        { "_NV_getSkillModIndoors", SwordBinding::_NV_getSkillModIndoors },
        { "_DESTRUCTOR", SwordBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        SwordBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SwordBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Sword_get_cutDamage);
    lua_setfield(L, -2, "cutDamage");
    lua_pushcfunction(L, Sword_get_bluntDamage);
    lua_setfield(L, -2, "bluntDamage");
    lua_pushcfunction(L, Sword_get_minCutDamage);
    lua_setfield(L, -2, "minCutDamage");
    lua_pushcfunction(L, Sword_get_modDefence);
    lua_setfield(L, -2, "modDefence");
    lua_pushcfunction(L, Sword_get_modIndoors);
    lua_setfield(L, -2, "modIndoors");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Sword_set_cutDamage);
    lua_setfield(L, -2, "cutDamage");
    lua_pushcfunction(L, Sword_set_bluntDamage);
    lua_setfield(L, -2, "bluntDamage");
    lua_pushcfunction(L, Sword_set_minCutDamage);
    lua_setfield(L, -2, "minCutDamage");
    lua_pushcfunction(L, Sword_set_modDefence);
    lua_setfield(L, -2, "modDefence");
    lua_pushcfunction(L, Sword_set_modIndoors);
    lua_setfield(L, -2, "modIndoors");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua