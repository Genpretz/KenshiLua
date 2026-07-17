#include "pch.h"
<<<<<<< HEAD:src/Bindings/System/DamagesBinding.cpp
#include "Bindings/System/DamagesBinding.h"
=======
#include "kenshi\Damages.h"
#include "DamagesBinding.h"
>>>>>>> main:src/Bindings/DamagesBinding.cpp
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Damages* getB(lua_State* L, int idx)
{
    return checkObject<Damages>(L, idx, DamagesBinding::getMetatableName());
}

// --- Getters for Damages ---
static int Damages_get_cut(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, b->cut);
    return 1;
}

static int Damages_get_blunt(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, b->blunt);
    return 1;
}

static int Damages_get_pierce(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, b->pierce);
    return 1;
}

static int Damages_get_extraStun(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, b->extraStun);
    return 1;
}

static int Damages_get_bleedMult(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, b->bleedMult);
    return 1;
}

static int Damages_get_armourPenetration(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    lua_pushnumber(L, b->armourPenetration);
    return 1;
}

// --- Setters for Damages ---
static int Damages_set_cut(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    b->cut = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_blunt(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    b->blunt = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_pierce(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    b->pierce = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_extraStun(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    b->extraStun = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_bleedMult(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    b->bleedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Damages_set_armourPenetration(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");
    b->armourPenetration = (float)luaL_checknumber(L, 2);
    return 0;
}

// --- Methods for Damages ---
int DamagesBinding::multiply(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");

    float mult = (float)luaL_checknumber(L, 2);
    b->multiply(mult);
    return 0;
}

int DamagesBinding::total(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");

    float result = b->total();
    lua_pushnumber(L, result);
    return 1;
}

int DamagesBinding::_DESTRUCTOR(lua_State* L)
{
    Damages* b = getB(L, 1);
    if (!b) return luaL_error(L, "Damages is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 10: Damages* _CONSTRUCTOR(...) - overloaded method
  line 12: Damages* _CONSTRUCTOR(...) - overloaded method
  line 14: Damages* _CONSTRUCTOR(...) - overloaded method
*/

int DamagesBinding::gc(lua_State* L)
{
    void** ud = (void**)lua_touserdata(L, 1);
    if (ud && *ud) {
        Damages* d = (Damages*)*ud;
        d->~Damages();
        ::operator delete(d);
        *ud = nullptr;
    }
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
        { "_DESTRUCTOR", DamagesBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, Damages_get_cut);
    lua_setfield(L, -2, "cut");
    lua_pushcfunction(L, Damages_get_blunt);
    lua_setfield(L, -2, "blunt");
    lua_pushcfunction(L, Damages_get_pierce);
    lua_setfield(L, -2, "pierce");
    lua_pushcfunction(L, Damages_get_extraStun);
    lua_setfield(L, -2, "extraStun");
    lua_pushcfunction(L, Damages_get_bleedMult);
    lua_setfield(L, -2, "bleedMult");
    lua_pushcfunction(L, Damages_get_armourPenetration);
    lua_setfield(L, -2, "armourPenetration");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Damages_set_cut);
    lua_setfield(L, -2, "cut");
    lua_pushcfunction(L, Damages_set_blunt);
    lua_setfield(L, -2, "blunt");
    lua_pushcfunction(L, Damages_set_pierce);
    lua_setfield(L, -2, "pierce");
    lua_pushcfunction(L, Damages_set_extraStun);
    lua_setfield(L, -2, "extraStun");
    lua_pushcfunction(L, Damages_set_bleedMult);
    lua_setfield(L, -2, "bleedMult");
    lua_pushcfunction(L, Damages_set_armourPenetration);
    lua_setfield(L, -2, "armourPenetration");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua