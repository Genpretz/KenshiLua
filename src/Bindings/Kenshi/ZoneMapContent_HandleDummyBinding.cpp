#include "pch.h"
#include "kenshi/ZoneMapContent.h"
#include "ZoneMapContent_HandleDummyBinding.h"
#include "ZoneMapContentBinding.h"
#include "RootObjectBaseBinding.h"
#include "GameSaveStateBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(ZoneMapContent::HandleDummy, me) == 0x78, "ZoneMapContent::HandleDummy::me offset mismatch");

static ZoneMapContent::HandleDummy* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneMapContent::HandleDummy>(L, idx, ZoneMapContent_HandleDummyBinding::getMetatableName());
}

static int HandleDummy_get_me(lua_State* L)
{
    ZoneMapContent::HandleDummy* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleDummy is nil");
    if (!instance->me) { lua_pushnil(L); return 1; }
    return pushObject<ZoneMapContent>(L, instance->me, ZoneMapContentBinding::getMetatableName());
}

static int HandleDummy_set_me(lua_State* L)
{
    ZoneMapContent::HandleDummy* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleDummy is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMapContent>(L, 2, ZoneMapContentBinding::getMetatableName());
    return 0;
}

int ZoneMapContent_HandleDummyBinding::getDataType(lua_State* L)
{
    ZoneMapContent::HandleDummy* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleDummy is nil");
    itemType res = instance->getDataType();
    lua_pushinteger(L, (lua_Integer)res);
    return 1;
}

int ZoneMapContent_HandleDummyBinding::_NV_getDataType(lua_State* L)
{
    ZoneMapContent::HandleDummy* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleDummy is nil");
    itemType res = instance->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)res);
    return 1;
}

int ZoneMapContent_HandleDummyBinding::loadFromSerialise(lua_State* L)
{
    ZoneMapContent::HandleDummy* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleDummy is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int ZoneMapContent_HandleDummyBinding::_NV_loadFromSerialise(lua_State* L)
{
    ZoneMapContent::HandleDummy* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleDummy is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int ZoneMapContent_HandleDummyBinding::gc(lua_State* L)
{
    return 0;
}

int ZoneMapContent_HandleDummyBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneMapContent.HandleDummy object");
    return 1;
}

void ZoneMapContent_HandleDummyBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneMapContent_HandleDummyBinding::gc },
        { "__tostring", ZoneMapContent_HandleDummyBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getDataType", ZoneMapContent_HandleDummyBinding::getDataType },
        { "_NV_getDataType", ZoneMapContent_HandleDummyBinding::_NV_getDataType },
        { "loadFromSerialise", ZoneMapContent_HandleDummyBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", ZoneMapContent_HandleDummyBinding::_NV_loadFromSerialise },
        { 0, 0 }
    };

    registerClass(
        L,
        ZoneMapContent_HandleDummyBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneMapContent_HandleDummyBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "me", HandleDummy_get_me);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "me", HandleDummy_set_me);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
