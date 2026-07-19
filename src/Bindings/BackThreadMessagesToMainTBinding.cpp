#include "pch.h"
#include <kenshi/ZoneManager.h>
#include "BackThreadMessagesToMainTBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static BackThreadMessagesToMainT* getInstance(lua_State* L, int idx)
{
    return checkObject<BackThreadMessagesToMainT>(L, idx, BackThreadMessagesToMainTBinding::getMetatableName());
}

// --- Getters for BackThreadMessagesToMainT ---

// --- Setters for BackThreadMessagesToMainT ---

int BackThreadMessagesToMainTBinding::_CONSTRUCTOR(lua_State* L)
{
    return 0;
}

int BackThreadMessagesToMainTBinding::_DESTRUCTOR(lua_State* L)
{
    BackThreadMessagesToMainT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BackThreadMessagesToMainT is nil");

    instance->~BackThreadMessagesToMainT();
    return 0;
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
    BackThreadMessagesToMainT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BackThreadMessagesToMainT is nil");

    bool result = instance->flush();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped properties needing manual binding:
  line 155: mainThreadData (std::set<T, std::less<T>, std::allocator<T> >) - unsupported type
  line 156: backThreadData (std::set<T, std::less<T>, std::allocator<T> >) - unsupported type
*/

int BackThreadMessagesToMainTBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BackThreadMessagesToMainTBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BackThreadMessagesToMainT object");
    return 1;
}

void BackThreadMessagesToMainTBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BackThreadMessagesToMainTBinding::gc },
        { "__tostring", BackThreadMessagesToMainTBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        // { "_CONSTRUCTOR", BackThreadMessagesToMainTBinding::_CONSTRUCTOR },
        // { "_DESTRUCTOR", BackThreadMessagesToMainTBinding::_DESTRUCTOR },
        { "flush", BackThreadMessagesToMainTBinding::flush },
        // { "_NV_flush", BackThreadMessagesToMainTBinding::_NV_flush },
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
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
