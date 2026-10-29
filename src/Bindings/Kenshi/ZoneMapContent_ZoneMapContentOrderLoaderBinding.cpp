#include "pch.h"
#include "kenshi/ZoneMapContent.h"
#include "ZoneMapContent_ZoneMapContentOrderLoaderBinding.h"
#include "SpecificItemLoadFirstBinding.h"
#include "GameSaveStateBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(ZoneMapContent::ZoneMapContentOrderLoader, newGameFirstTimeLoaded) == 0x40, "ZoneMapContent::ZoneMapContentOrderLoader::newGameFirstTimeLoaded offset mismatch");

static ZoneMapContent::ZoneMapContentOrderLoader* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneMapContent::ZoneMapContentOrderLoader>(L, idx, ZoneMapContent_ZoneMapContentOrderLoaderBinding::getMetatableName());
}

static int ZoneMapContentOrderLoader_get_newGameFirstTimeLoaded(lua_State* L)
{
    ZoneMapContent::ZoneMapContentOrderLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContentOrderLoader is nil");
    lua_pushboolean(L, instance->newGameFirstTimeLoaded ? 1 : 0);
    return 1;
}

static int ZoneMapContentOrderLoader_set_newGameFirstTimeLoaded(lua_State* L)
{
    ZoneMapContent::ZoneMapContentOrderLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContentOrderLoader is nil");
    instance->newGameFirstTimeLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

int ZoneMapContent_ZoneMapContentOrderLoaderBinding::shouldSkip(lua_State* L)
{
    ZoneMapContent::ZoneMapContentOrderLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContentOrderLoader is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool res = instance->shouldSkip(state);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int ZoneMapContent_ZoneMapContentOrderLoaderBinding::_NV_shouldSkip(lua_State* L)
{
    ZoneMapContent::ZoneMapContentOrderLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContentOrderLoader is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool res = instance->_NV_shouldSkip(state);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int ZoneMapContent_ZoneMapContentOrderLoaderBinding::gc(lua_State* L)
{
    return 0;
}

int ZoneMapContent_ZoneMapContentOrderLoaderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneMapContent.ZoneMapContentOrderLoader object");
    return 1;
}

void ZoneMapContent_ZoneMapContentOrderLoaderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneMapContent_ZoneMapContentOrderLoaderBinding::gc },
        { "__tostring", ZoneMapContent_ZoneMapContentOrderLoaderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "shouldSkip", ZoneMapContent_ZoneMapContentOrderLoaderBinding::shouldSkip },
        { "_NV_shouldSkip", ZoneMapContent_ZoneMapContentOrderLoaderBinding::_NV_shouldSkip },
        { 0, 0 }
    };

    registerClass(
        L,
        ZoneMapContent_ZoneMapContentOrderLoaderBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneMapContent_ZoneMapContentOrderLoaderBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "newGameFirstTimeLoaded", ZoneMapContentOrderLoader_get_newGameFirstTimeLoaded);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "newGameFirstTimeLoaded", ZoneMapContentOrderLoader_set_newGameFirstTimeLoaded);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua

