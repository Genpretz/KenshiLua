#include "pch.h"
#include "Bindings/hkResultBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkResult* getInstance(lua_State* L, int idx)
{
    return checkObject<hkResult>(L, idx, hkResultBinding::getMetatableName());
}

static int hkResult_get_m_enum(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkResult is nil");
    lua_pushinteger(L, (lua_Integer)inst->m_enum);
    return 1;
}

static int hkResult_set_m_enum(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "hkResult is nil");
    inst->m_enum = (hkResultEnum)luaL_checkinteger(L, 2);
    return 0;
}

int hkResultBinding::gc(lua_State* L)
{
    return 0;
}

int hkResultBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkResult object");
    return 1;
}

int hkResultBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && a->m_enum == b->m_enum) ? 1 : 0);
    return 1;
}

void hkResultBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "m_enum", hkResult_get_m_enum);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "m_enum", hkResult_set_m_enum);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
