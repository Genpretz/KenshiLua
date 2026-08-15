#include "pch.h"
#include "kenshi\Damages.h"
#include "DamagesBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Damages* getInstance(lua_State* L, int idx)
{
    return checkObject<Damages>(L, idx, DamagesBinding::getMetatableName());
}

// --- Getters for Damages ---
static int Damages_get_cut(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, instance->cut);
    return 1;
}

static int Damages_get_blunt(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, instance->blunt);
    return 1;
}

static int Damages_get_pierce(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, instance->pierce);
    return 1;
}

static int Damages_get_extraStun(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, instance->extraStun);
    return 1;
}

static int Damages_get_bleedMult(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, instance->bleedMult);
    return 1;
}

static int Damages_get_armourPenetration(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, instance->armourPenetration);
    return 1;
}

// --- Setters for Damages ---
static int Damages_set_cut(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    instance->cut = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_blunt(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    instance->blunt = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_pierce(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    instance->pierce = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_extraStun(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    instance->extraStun = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_bleedMult(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    instance->bleedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_armourPenetration(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");
    instance->armourPenetration = (float)luaL_checknumber(L, 2);
    return 0;
}

int DamagesBinding::multiply(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");

    float mult = (float)luaL_checknumber(L, 2);
    instance->multiply(mult);
    return 0;
}

int DamagesBinding::total(lua_State* L)
{
    Damages* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Damages is nil");

    float result = instance->total();
    lua_pushnumber(L, result);
    return 1;
}

int DamagesBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DamagesBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Damages object");
    return 1;
}

void DamagesBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DamagesBinding::gc },
        { "__tostring", DamagesBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "multiply", DamagesBinding::multiply },
        { "total", DamagesBinding::total },
        { 0, 0 }
    };

    registerClass(
        L, 
        DamagesBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DamagesBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "cut", Damages_get_cut);
    registerGetter(L, "blunt", Damages_get_blunt);
    registerGetter(L, "pierce", Damages_get_pierce);
    registerGetter(L, "extraStun", Damages_get_extraStun);
    registerGetter(L, "bleedMult", Damages_get_bleedMult);
    registerGetter(L, "armourPenetration", Damages_get_armourPenetration);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "cut", Damages_set_cut);
    registerSetter(L, "blunt", Damages_set_blunt);
    registerSetter(L, "pierce", Damages_set_pierce);
    registerSetter(L, "extraStun", Damages_set_extraStun);
    registerSetter(L, "bleedMult", Damages_set_bleedMult);
    registerSetter(L, "armourPenetration", Damages_set_armourPenetration);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, DamagesBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua