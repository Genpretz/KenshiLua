#include "pch.h"
#include "Bindings/Nx9Real_SBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Nx9Real::S* getInstance(lua_State* L, int idx)
{
    return checkObject<Nx9Real::S>(L, idx, Nx9Real_SBinding::getMetatableName());
}

// --- Getters for S ---
static int S_get__11(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    lua_pushnumber(L, inst->_11);
    return 1;
}

static int S_get__12(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    lua_pushnumber(L, inst->_12);
    return 1;
}

static int S_get__13(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    lua_pushnumber(L, inst->_13);
    return 1;
}

static int S_get__21(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    lua_pushnumber(L, inst->_21);
    return 1;
}

static int S_get__22(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    lua_pushnumber(L, inst->_22);
    return 1;
}

static int S_get__23(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    lua_pushnumber(L, inst->_23);
    return 1;
}

static int S_get__31(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    lua_pushnumber(L, inst->_31);
    return 1;
}

static int S_get__32(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    lua_pushnumber(L, inst->_32);
    return 1;
}

static int S_get__33(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    lua_pushnumber(L, inst->_33);
    return 1;
}

// --- Setters for S ---
static int S_set__11(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    inst->_11 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int S_set__12(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    inst->_12 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int S_set__13(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    inst->_13 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int S_set__21(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    inst->_21 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int S_set__22(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    inst->_22 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int S_set__23(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    inst->_23 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int S_set__31(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    inst->_31 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int S_set__32(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    inst->_32 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int S_set__33(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "Nx9Real::S is nil");
    inst->_33 = (float)luaL_checknumber(L, 2);
    return 0;
}

int Nx9Real_SBinding::gc(lua_State* L)
{
    return 0;
}

int Nx9Real_SBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Nx9Real_S object");
    return 1;
}

int Nx9Real_SBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->_11 == b->_11 && a->_12 == b->_12 && a->_13 == b->_13 && a->_21 == b->_21 && a->_22 == b->_22 && a->_23 == b->_23 && a->_31 == b->_31 && a->_32 == b->_32 && a->_33 == b->_33)) ? 1 : 0);
    return 1;
}

void Nx9Real_SBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "_11", S_get__11);
    registerGetter(L, "_12", S_get__12);
    registerGetter(L, "_13", S_get__13);
    registerGetter(L, "_21", S_get__21);
    registerGetter(L, "_22", S_get__22);
    registerGetter(L, "_23", S_get__23);
    registerGetter(L, "_31", S_get__31);
    registerGetter(L, "_32", S_get__32);
    registerGetter(L, "_33", S_get__33);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "_11", S_set__11);
    registerSetter(L, "_12", S_set__12);
    registerSetter(L, "_13", S_set__13);
    registerSetter(L, "_21", S_set__21);
    registerSetter(L, "_22", S_set__22);
    registerSetter(L, "_23", S_set__23);
    registerSetter(L, "_31", S_set__31);
    registerSetter(L, "_32", S_set__32);
    registerSetter(L, "_33", S_set__33);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
