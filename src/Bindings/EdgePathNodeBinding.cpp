#include "pch.h"
#include "Bindings/EdgePathNodeBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static EdgePathNode* getInstance(lua_State* L, int idx)
{
    return checkObject<EdgePathNode>(L, idx, EdgePathNodeBinding::getMetatableName());
}

// --- Getters for EdgePathNode ---
static int EdgePathNode_get_mLeft(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    lua_pushlightuserdata(L, (void*)&inst->mLeft);

    return 1;
}

static int EdgePathNode_get_mRight(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    lua_pushlightuserdata(L, (void*)&inst->mRight);

    return 1;
}

static int EdgePathNode_get_face(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    lua_pushinteger(L, inst->face);
    return 1;
}

static int EdgePathNode_get_edge(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    lua_pushinteger(L, inst->edge);
    return 1;
}

static int EdgePathNode_get_leftClearance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    lua_pushnumber(L, inst->leftClearance);
    return 1;
}

static int EdgePathNode_get_rightClearance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    lua_pushnumber(L, inst->rightClearance);
    return 1;
}

static int EdgePathNode_get_maxPoint(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    lua_pushnumber(L, inst->maxPoint);
    return 1;
}

// --- Setters for EdgePathNode ---
static int EdgePathNode_set_mLeft(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    inst->mLeft = *(hkVector4f*)lua_touserdata(L, 2);
    return 0;
}

static int EdgePathNode_set_mRight(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    inst->mRight = *(hkVector4f*)lua_touserdata(L, 2);
    return 0;
}

static int EdgePathNode_set_face(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    inst->face = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int EdgePathNode_set_edge(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    inst->edge = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int EdgePathNode_set_leftClearance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    inst->leftClearance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EdgePathNode_set_rightClearance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    inst->rightClearance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int EdgePathNode_set_maxPoint(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "EdgePathNode is nil");
    inst->maxPoint = (float)luaL_checknumber(L, 2);
    return 0;
}

int EdgePathNodeBinding::gc(lua_State* L)
{
    return 0;
}

int EdgePathNodeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.EdgePathNode object");
    return 1;
}

int EdgePathNodeBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->face == b->face && a->edge == b->edge && a->leftClearance == b->leftClearance && a->rightClearance == b->rightClearance && a->maxPoint == b->maxPoint)) ? 1 : 0);
    return 1;
}

void EdgePathNodeBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "mLeft", EdgePathNode_get_mLeft);
    registerGetter(L, "mRight", EdgePathNode_get_mRight);
    registerGetter(L, "face", EdgePathNode_get_face);
    registerGetter(L, "edge", EdgePathNode_get_edge);
    registerGetter(L, "leftClearance", EdgePathNode_get_leftClearance);
    registerGetter(L, "rightClearance", EdgePathNode_get_rightClearance);
    registerGetter(L, "maxPoint", EdgePathNode_get_maxPoint);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "mLeft", EdgePathNode_set_mLeft);
    registerSetter(L, "mRight", EdgePathNode_set_mRight);
    registerSetter(L, "face", EdgePathNode_set_face);
    registerSetter(L, "edge", EdgePathNode_set_edge);
    registerSetter(L, "leftClearance", EdgePathNode_set_leftClearance);
    registerSetter(L, "rightClearance", EdgePathNode_set_rightClearance);
    registerSetter(L, "maxPoint", EdgePathNode_set_maxPoint);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
