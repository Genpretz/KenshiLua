#include "pch.h"
#include "Bindings/EdgeCache_EdgeBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static EdgeCache::Edge* getInstance(lua_State* L, int idx)
{
    return checkObject<EdgeCache::Edge>(L, idx, EdgeCache_EdgeBinding::getMetatableName());
}

// --- Getters for Edge ---
static int Edge_get_a(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache::Edge is nil");
    lua_pushlightuserdata(L, (void*)&inst->a);

    return 1;
}

static int Edge_get_b(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache::Edge is nil");
    lua_pushlightuserdata(L, (void*)&inst->b);

    return 1;
}

// --- Setters for Edge ---
static int Edge_set_a(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache::Edge is nil");
    inst->a = *(hkVector4f*)lua_touserdata(L, 2);
    return 0;
}

static int Edge_set_b(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache::Edge is nil");
    inst->b = *(hkVector4f*)lua_touserdata(L, 2);
    return 0;
}

int EdgeCache_EdgeBinding::gc(lua_State* L)
{
    return 0;
}

int EdgeCache_EdgeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.EdgeCache_Edge object");
    return 1;
}

int EdgeCache_EdgeBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void EdgeCache_EdgeBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "a", Edge_get_a);
    registerGetter(L, "b", Edge_get_b);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "a", Edge_set_a);
    registerSetter(L, "b", Edge_set_b);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
