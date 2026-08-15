#include "pch.h"
#include "kenshi\ZoneManager.h"
#include "BackThreadMessagesToMainTBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/ZoneManager.h>

namespace KenshiLua
{

static BackThreadMessagesToMainT* getInstance(lua_State* L, int idx)
{
    return checkObject<BackThreadMessagesToMainT>(L, idx, BackThreadMessagesToMainTBinding::getMetatableName());
}

// --- Getters for BackThreadMessagesToMainT ---
static int BackThreadMessagesToMainT_get_swapMutex(lua_State* L) { return 0; }

// --- Setters for BackThreadMessagesToMainT ---
static int BackThreadMessagesToMainT_set_swapMutex(lua_State* L) { return 0; }

int BackThreadMessagesToMainTBinding::gc(lua_State* L)
{
    return 0;
}

int BackThreadMessagesToMainTBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BackThreadMessagesToMainT object");
    return 1;
}

int BackThreadMessagesToMainTBinding::flush(lua_State* L)
{
    BackThreadMessagesToMainT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BackThreadMessagesToMainT is nil");
    bool result = instance->flush();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BackThreadMessagesToMainTBinding::_NV_flush(lua_State* L)
{
    return 0;
}

void BackThreadMessagesToMainTBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BackThreadMessagesToMainTBinding::gc },
        { "__tostring", BackThreadMessagesToMainTBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "flush", BackThreadMessagesToMainTBinding::flush },
        { "_NV_flush", BackThreadMessagesToMainTBinding::_NV_flush },
        { 0, 0 }
    };

    registerClass(
        L, 
        BackThreadMessagesToMainTBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BackThreadMessagesToMainTBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "swapMutex", BackThreadMessagesToMainT_get_swapMutex);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "swapMutex", BackThreadMessagesToMainT_set_swapMutex);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua