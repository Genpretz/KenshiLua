#include "pch.h"
#include "Bindings/System/DamagesBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Damages.h>

#include <new>
#include <cstdio>

namespace KenshiLua
{

static Damages* getD(lua_State* L, int idx)
{
    return (Damages*)luaL_checkudata(L, idx, DamagesBinding::getMetatableName());
}

//int DamagesBinding::createNew(lua_State* L)
//{
//    float cut    = (float)luaL_optnumber(L, 1, 0.0);
//    float blunt  = (float)luaL_optnumber(L, 2, 0.0);
//    float pierce = (float)luaL_optnumber(L, 3, 0.0);
//    float bleed  = (float)luaL_optnumber(L, 4, 1.0);
//    float armour = (float)luaL_optnumber(L, 5, 0.0);
//
//    void* mem = lua_newuserdata(L, sizeof(Damages));
//    new (mem) Damages(cut, blunt, pierce, bleed, armour);
//    luaL_getmetatable(L, DamagesBinding::getMetatableName());
//    lua_setmetatable(L, -2);
//    return 1;
//}

int DamagesBinding::gc(lua_State* L)
{
    Damages* d = (Damages*)luaL_checkudata(L, 1, getMetatableName());
    if (d) d->~Damages();
    return 0;
}

int DamagesBinding::tostring(lua_State* L)
{
    Damages* d = getD(L, 1);
    if (!d) { lua_pushstring(L, "Damages:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "Damages(cut=%.2f, blunt=%.2f, pierce=%.2f)", d->cut, d->blunt, d->pierce);
    lua_pushstring(L, buf);
    return 1;
}

int DamagesBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, DamagesBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    // 2. Fall through to raw member variable access.
    Damages* d = getD(L, 1);
    if (!d) { lua_pushnil(L); return 1; }

    // --- float members ---
    if (strcmp(key, "cut") == 0) { lua_pushnumber(L, d->cut); return 1; }
    if (strcmp(key, "blunt") == 0) { lua_pushnumber(L, d->blunt); return 1; }
    if (strcmp(key, "pierce") == 0) { lua_pushnumber(L, d->pierce); return 1; }
    if (strcmp(key, "extraStun") == 0) { lua_pushnumber(L, d->extraStun); return 1; }
    if (strcmp(key, "bleed") == 0 || strcmp(key, "bleedMult") == 0) { lua_pushnumber(L, d->bleedMult); return 1; }
    if (strcmp(key, "armour") == 0 || strcmp(key, "armourPenetration") == 0) { lua_pushnumber(L, d->armourPenetration); return 1; }

    lua_pushnil(L);
    return 1;
}

int DamagesBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Damages* d = getD(L, 1);
    if (!d) return luaL_error(L, "Damages is nil");

    // --- writable float properties ---
    if (strcmp(key, "cut") == 0) { d->cut = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "blunt") == 0) { d->blunt = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "pierce") == 0) { d->pierce = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "extraStun") == 0) { d->extraStun = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bleed") == 0 || strcmp(key, "bleedMult") == 0) { d->bleedMult = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "armour") == 0 || strcmp(key, "armourPenetration") == 0) { d->armourPenetration = (float)luaL_checknumber(L, 3); return 0; }

    return luaL_error(L, "Damages: field '%s' does not exist", key);
}

int DamagesBinding::getCut(lua_State* L)              { Damages* d = getD(L, 1); if (d) lua_pushnumber(L, d->cut); else lua_pushnil(L); return 1; }
int DamagesBinding::setCut(lua_State* L)              { Damages* d = getD(L, 1); if (d) d->cut = (float)luaL_checknumber(L, 2); return 0; }
int DamagesBinding::getBlunt(lua_State* L)            { Damages* d = getD(L, 1); if (d) lua_pushnumber(L, d->blunt); else lua_pushnil(L); return 1; }
int DamagesBinding::setBlunt(lua_State* L)            { Damages* d = getD(L, 1); if (d) d->blunt = (float)luaL_checknumber(L, 2); return 0; }
int DamagesBinding::getPierce(lua_State* L)           { Damages* d = getD(L, 1); if (d) lua_pushnumber(L, d->pierce); else lua_pushnil(L); return 1; }
int DamagesBinding::setPierce(lua_State* L)           { Damages* d = getD(L, 1); if (d) d->pierce = (float)luaL_checknumber(L, 2); return 0; }
int DamagesBinding::getBleed(lua_State* L)            { Damages* d = getD(L, 1); if (d) lua_pushnumber(L, d->bleedMult); else lua_pushnil(L); return 1; }
int DamagesBinding::setBleed(lua_State* L)            { Damages* d = getD(L, 1); if (d) d->bleedMult = (float)luaL_checknumber(L, 2); return 0; }
int DamagesBinding::getArmourPenetration(lua_State* L){ Damages* d = getD(L, 1); if (d) lua_pushnumber(L, d->armourPenetration); else lua_pushnil(L); return 1; }
int DamagesBinding::setArmourPenetration(lua_State* L){ Damages* d = getD(L, 1); if (d) d->armourPenetration = (float)luaL_checknumber(L, 2); return 0; }
int DamagesBinding::total(lua_State* L)               { Damages* d = getD(L, 1); if (d) lua_pushnumber(L, d->total()); else lua_pushnil(L); return 1; }
int DamagesBinding::multiply(lua_State* L)            { Damages* d = getD(L, 1); if (d) d->multiply((float)luaL_checknumber(L, 2)); return 0; }

void DamagesBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DamagesBinding::gc },
        { "__tostring", DamagesBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        //{ "new",                  DamagesBinding::createNew },
        { "getCut",               DamagesBinding::getCut },
        { "setCut",               DamagesBinding::setCut },
        { "getBlunt",             DamagesBinding::getBlunt },
        { "setBlunt",             DamagesBinding::setBlunt },
        { "getPierce",            DamagesBinding::getPierce },
        { "setPierce",            DamagesBinding::setPierce },
        { "getBleed",             DamagesBinding::getBleed },
        { "setBleed",             DamagesBinding::setBleed },
        { "getArmourPenetration", DamagesBinding::getArmourPenetration },
        { "setArmourPenetration", DamagesBinding::setArmourPenetration },
        { "total",                DamagesBinding::total },
        { "multiply",             DamagesBinding::multiply },
        { 0, 0 }
    };
    registerClass(L, DamagesBinding::getMetatableName(), meta, methods, DamagesBinding::index, DamagesBinding::newindex);

    // Also expose Damages as a global table so scripts can do:
    //   local d = Damages.new(1, 2, 3)
    luaL_getmetatable(L, DamagesBinding::getMetatableName());
    lua_setglobal(L, "Damages");
}

} // namespace KenshiLua