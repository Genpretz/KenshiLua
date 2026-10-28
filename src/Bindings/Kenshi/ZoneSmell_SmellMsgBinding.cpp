#include "pch.h"
#include "kenshi/ZoneSmell.h"
#include "ZoneSmell_SmellMsgBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(ZoneSmell::SmellMsg, type) == 0x0, "ZoneSmell::SmellMsg::type offset mismatch");
static_assert(offsetof(ZoneSmell::SmellMsg, pos) == 0x4, "ZoneSmell::SmellMsg::pos offset mismatch");

static ZoneSmell::SmellMsg* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneSmell::SmellMsg>(L, idx, ZoneSmell_SmellMsgBinding::getMetatableName());
}

static int SmellMsg_get_type(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::SmellMsg is nil");
    lua_pushinteger(L, (lua_Integer)inst->type);
    return 1;
}

static int SmellMsg_set_type(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::SmellMsg is nil");
    inst->type = (ZoneSmell::SmellMessageType)luaL_checkinteger(L, 2);
    return 0;
}

static int SmellMsg_get_pos(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::SmellMsg is nil");
    pushVector3(L, inst->pos);
    return 1;
}

static int SmellMsg_set_pos(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "ZoneSmell::SmellMsg is nil");
    readVector3(L, 2, inst->pos);
    return 0;
}

int ZoneSmell_SmellMsgBinding::gc(lua_State* L)
{
    return 0;
}

int ZoneSmell_SmellMsgBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneSmell_SmellMsg object");
    return 1;
}

int ZoneSmell_SmellMsgBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, a == b);
    return 1;
}

void ZoneSmell_SmellMsgBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneSmell_SmellMsgBinding::gc },
        { "__tostring", ZoneSmell_SmellMsgBinding::tostring },
        { "__eq",       ZoneSmell_SmellMsgBinding::operator_eq },
        { 0, 0 }
    };

    registerClass(
        L,
        ZoneSmell_SmellMsgBinding::getMetatableName(),
        meta,
        nullptr,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneSmell_SmellMsgBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "type", SmellMsg_get_type);
    registerGetter(L, "pos", SmellMsg_get_pos);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "type", SmellMsg_set_type);
    registerSetter(L, "pos", SmellMsg_set_pos);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
