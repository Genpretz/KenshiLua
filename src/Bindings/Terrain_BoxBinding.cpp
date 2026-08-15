#include "pch.h"
#include "Bindings/Terrain_BoxBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Terrain::Box* getInstance(lua_State* L, int idx)
{
    return checkObject<Terrain::Box>(L, idx, Terrain_BoxBinding::getMetatableName());
}

// --- Getters for Box ---
static int Box_get_top(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    lua_pushinteger(L, inst->top);
    return 1;
}

static int Box_get_left(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    lua_pushinteger(L, inst->left);
    return 1;
}

static int Box_get_right(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    lua_pushinteger(L, inst->right);
    return 1;
}

static int Box_get_bottom(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    lua_pushinteger(L, inst->bottom);
    return 1;
}

static int Box_get_cx(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    lua_pushinteger(L, inst->cx);
    return 1;
}

static int Box_get_cy(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    lua_pushinteger(L, inst->cy);
    return 1;
}

// --- Setters for Box ---
static int Box_set_top(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    inst->top = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Box_set_left(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    inst->left = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Box_set_right(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    inst->right = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Box_set_bottom(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    inst->bottom = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Box_set_cx(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    inst->cx = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Box_set_cy(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Terrain::Box is nil");
    inst->cy = (int)luaL_checkinteger(L, 2);
    return 0;
}

int Terrain_BoxBinding::gc(lua_State* L)
{
    return 0;
}

int Terrain_BoxBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Terrain_Box object");
    return 1;
}

int Terrain_BoxBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->top == b->top && a->left == b->left && a->right == b->right && a->bottom == b->bottom && a->cx == b->cx && a->cy == b->cy)) ? 1 : 0);
    return 1;
}

void Terrain_BoxBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "top", Box_get_top);
    registerGetter(L, "left", Box_get_left);
    registerGetter(L, "right", Box_get_right);
    registerGetter(L, "bottom", Box_get_bottom);
    registerGetter(L, "cx", Box_get_cx);
    registerGetter(L, "cy", Box_get_cy);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "top", Box_set_top);
    registerSetter(L, "left", Box_set_left);
    registerSetter(L, "right", Box_set_right);
    registerSetter(L, "bottom", Box_set_bottom);
    registerSetter(L, "cx", Box_set_cx);
    registerSetter(L, "cy", Box_set_cy);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
