#include "pch.h"
#include "kenshi\util\PerfTimer.h"
#include "CPerfTimerTBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static CPerfTimerT* getInstance(lua_State* L, int idx)
{
    return checkObject<CPerfTimerT>(L, idx, CPerfTimerTBinding::getMetatableName());
}

// --- Getters for CPerfTimerT ---
// --- Setters for CPerfTimerT ---


int CPerfTimerTBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CPerfTimerTBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CPerfTimerT object");
    return 1;
}

void CPerfTimerTBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CPerfTimerTBinding::gc },
        { "__tostring", CPerfTimerTBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        CPerfTimerTBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CPerfTimerTBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to CPerfTimer
    // setMetatableParent(L, CPerfTimerTBinding::getMetatableName(), CPerfTimerBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua