#include "pch.h"
#include "Bindings/AkVectorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AkVector* getInstance(lua_State* L, int idx)
{
    return checkObject<AkVector>(L, idx, AkVectorBinding::getMetatableName());
}

// --- Getters for AkVector ---
static int AkVector_get_X(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkVector is nil");
    lua_pushnumber(L, inst->X);
    return 1;
}

static int AkVector_get_Y(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkVector is nil");
    lua_pushnumber(L, inst->Y);
    return 1;
}

static int AkVector_get_Z(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkVector is nil");
    lua_pushnumber(L, inst->Z);
    return 1;
}

// --- Setters for AkVector ---
static int AkVector_set_X(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkVector is nil");
    inst->X = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AkVector_set_Y(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkVector is nil");
    inst->Y = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AkVector_set_Z(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AkVector is nil");
    inst->Z = (float)luaL_checknumber(L, 2);
    return 0;
}

int AkVectorBinding::gc(lua_State* L)
{
    return 0;
}

int AkVectorBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AkVector object");
    return 1;
}

int AkVectorBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->X == b->X && a->Y == b->Y && a->Z == b->Z)) ? 1 : 0);
    return 1;
}

void AkVectorBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "X", AkVector_get_X);
    registerGetter(L, "Y", AkVector_get_Y);
    registerGetter(L, "Z", AkVector_get_Z);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "X", AkVector_set_X);
    registerSetter(L, "Y", AkVector_set_Y);
    registerSetter(L, "Z", AkVector_set_Z);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
