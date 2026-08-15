#include "pch.h"
#include "kenshi\ZoneManager.h"
#include "MainthreadStateReaderTBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/ZoneManager.h>

namespace KenshiLua
{

static MainthreadStateReaderT* getInstance(lua_State* L, int idx)
{
    return checkObject<MainthreadStateReaderT>(L, idx, MainthreadStateReaderTBinding::getMetatableName());
}

// --- Getters for MainthreadStateReaderT ---
static int MainthreadStateReaderT_get_swapMutex(lua_State* L) { return 0; }

// --- Setters for MainthreadStateReaderT ---
static int MainthreadStateReaderT_set_swapMutex(lua_State* L) { return 0; }

int MainthreadStateReaderTBinding::gc(lua_State* L)
{
    return 0;
}

int MainthreadStateReaderTBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MainthreadStateReaderT object");
    return 1;
}

int MainthreadStateReaderTBinding::updateBackDataCheck(lua_State* L)
{
    MainthreadStateReaderT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainthreadStateReaderT is nil");
    bool result = instance->updateBackDataCheck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MainthreadStateReaderTBinding::_NV_updateBackDataCheck(lua_State* L)
{
    return 0;
}

int MainthreadStateReaderTBinding::getMainData(lua_State* L)
{
    return 0;
}

int MainthreadStateReaderTBinding::getBackData(lua_State* L)
{
    return 0;
}

void MainthreadStateReaderTBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MainthreadStateReaderTBinding::gc },
        { "__tostring", MainthreadStateReaderTBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "updateBackDataCheck", MainthreadStateReaderTBinding::updateBackDataCheck },
        { "_NV_updateBackDataCheck", MainthreadStateReaderTBinding::_NV_updateBackDataCheck },
        { "getMainData", MainthreadStateReaderTBinding::getMainData },
        { "getBackData", MainthreadStateReaderTBinding::getBackData },
        { 0, 0 }
    };

    registerClass(
        L, 
        MainthreadStateReaderTBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MainthreadStateReaderTBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "swapMutex", MainthreadStateReaderT_get_swapMutex);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "swapMutex", MainthreadStateReaderT_set_swapMutex);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua