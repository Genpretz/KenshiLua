#include "pch.h"
#include "Bindings/Terrain_HitBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Terrain::Hit* getInstance(lua_State* L, int idx)
{
    return checkObject<Terrain::Hit>(L, idx, Terrain_HitBinding::getMetatableName());
}

// --- Getters for Hit ---
static int Hit_get_hit(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Hit is nil");
    lua_pushboolean(L, inst->hit ? 1 : 0);
    return 1;
}

static int Hit_get_level(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Hit is nil");
    lua_pushinteger(L, inst->level);
    return 1;
}

static int Hit_get_point(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Hit is nil");
    pushVector3(L, inst->point);
    return 1;
}

static int Hit_get_normal(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Hit is nil");
    pushVector3(L, inst->normal);
    return 1;
}

// --- Setters for Hit ---
static int Hit_set_hit(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Hit is nil");
    inst->hit = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Hit_set_level(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Hit is nil");
    inst->level = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

static int Hit_set_point(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Hit is nil");
    readVector3(L, 2, inst->point);
    return 0;
}

static int Hit_set_normal(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Hit is nil");
    readVector3(L, 2, inst->normal);
    return 0;
}

int Terrain_HitBinding::gc(lua_State* L)
{
    return 0;
}

int Terrain_HitBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Terrain_Hit object");
    return 1;
}

int Terrain_HitBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->hit == b->hit && a->level == b->level && a->point == b->point && a->normal == b->normal)) ? 1 : 0);
    return 1;
}

void Terrain_HitBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "hit", Hit_get_hit);
    registerGetter(L, "level", Hit_get_level);
    registerGetter(L, "point", Hit_get_point);
    registerGetter(L, "normal", Hit_get_normal);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "hit", Hit_set_hit);
    registerSetter(L, "level", Hit_set_level);
    registerSetter(L, "point", Hit_set_point);
    registerSetter(L, "normal", Hit_set_normal);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
