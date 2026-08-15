#include "pch.h"
#include "Bindings/Terrain_InfoBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Terrain::Info* getInstance(lua_State* L, int idx)
{
    return checkObject<Terrain::Info>(L, idx, Terrain_InfoBinding::getMetatableName());
}

// --- Getters for Info ---
static int Info_get_memory(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    lua_pushnumber(L, (lua_Number)inst->memory);

    return 1;
}

static int Info_get_patches(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    lua_pushnumber(L, (lua_Number)inst->patches);

    return 1;
}

static int Info_get_visible(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    lua_pushnumber(L, (lua_Number)inst->visible);

    return 1;
}

static int Info_get_triangles(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    lua_pushnumber(L, (lua_Number)inst->triangles);

    return 1;
}

static int Info_get_ogre(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    lua_pushnumber(L, (lua_Number)inst->ogre);

    return 1;
}

static int Info_get_unbuilt(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    lua_pushnumber(L, (lua_Number)inst->unbuilt);

    return 1;
}

// --- Setters for Info ---
static int Info_set_memory(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    inst->memory = (unsigned __int64)luaL_checknumber(L, 2);
    return 0;
}

static int Info_set_patches(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    inst->patches = (unsigned __int64)luaL_checknumber(L, 2);
    return 0;
}

static int Info_set_visible(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    inst->visible = (unsigned __int64)luaL_checknumber(L, 2);
    return 0;
}

static int Info_set_triangles(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    inst->triangles = (unsigned __int64)luaL_checknumber(L, 2);
    return 0;
}

static int Info_set_ogre(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    inst->ogre = (unsigned __int64)luaL_checknumber(L, 2);
    return 0;
}

static int Info_set_unbuilt(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Info is nil");
    inst->unbuilt = (unsigned __int64)luaL_checknumber(L, 2);
    return 0;
}

int Terrain_InfoBinding::gc(lua_State* L)
{
    return 0;
}

int Terrain_InfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Terrain_Info object");
    return 1;
}

int Terrain_InfoBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->memory == b->memory && a->patches == b->patches && a->visible == b->visible && a->triangles == b->triangles && a->ogre == b->ogre && a->unbuilt == b->unbuilt)) ? 1 : 0);
    return 1;
}

void Terrain_InfoBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "memory", Info_get_memory);
    registerGetter(L, "patches", Info_get_patches);
    registerGetter(L, "visible", Info_get_visible);
    registerGetter(L, "triangles", Info_get_triangles);
    registerGetter(L, "ogre", Info_get_ogre);
    registerGetter(L, "unbuilt", Info_get_unbuilt);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "memory", Info_set_memory);
    registerSetter(L, "patches", Info_set_patches);
    registerSetter(L, "visible", Info_set_visible);
    registerSetter(L, "triangles", Info_set_triangles);
    registerSetter(L, "ogre", Info_set_ogre);
    registerSetter(L, "unbuilt", Info_set_unbuilt);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
