#include "pch.h"
#include "Bindings/EdgeCacheBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static EdgeCache* getInstance(lua_State* L, int idx)
{
    return checkObject<EdgeCache>(L, idx, EdgeCacheBinding::getMetatableName());
}

// --- Getters for EdgeCache ---
static int EdgeCache_get_centre(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache is nil");
    lua_pushlightuserdata(L, (void*)&inst->centre);

    return 1;
}

static int EdgeCache_get_radius(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache is nil");
    lua_pushnumber(L, inst->radius);
    return 1;
}

static int EdgeCache_get_hasDoor(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache is nil");
    lua_pushboolean(L, inst->hasDoor ? 1 : 0);
    return 1;
}

// --- Setters for EdgeCache ---
static int EdgeCache_set_centre(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache is nil");
    inst->centre = *(hkVector4f*)lua_touserdata(L, 2);
    return 0;
}

static int EdgeCache_set_radius(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache is nil");
    inst->radius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EdgeCache_set_hasDoor(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgeCache is nil");
    inst->hasDoor = lua_toboolean(L, 2) != 0;
    return 0;
}

int EdgeCacheBinding::gc(lua_State* L)
{
    return 0;
}

int EdgeCacheBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.EdgeCache object");
    return 1;
}

int EdgeCacheBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void EdgeCacheBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "centre", EdgeCache_get_centre);
    registerGetter(L, "radius", EdgeCache_get_radius);
    registerGetter(L, "hasDoor", EdgeCache_get_hasDoor);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "centre", EdgeCache_set_centre);
    registerSetter(L, "radius", EdgeCache_set_radius);
    registerSetter(L, "hasDoor", EdgeCache_set_hasDoor);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
