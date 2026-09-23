#include "pch.h"
#include "kenshi\util\UtilityT.h"
#include "TimerClassBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TimerClass* getInstance(lua_State* L, int idx)
{
    return checkObject<TimerClass>(L, idx, TimerClassBinding::getMetatableName());
}

// --- Getters for TimerClass ---
// --- Setters for TimerClass ---

/*
Skipped properties needing manual binding:
  line 42: freq (__int64) - unsupported type
  line 43: ctr1 (__int64) - unsupported type
  line 44: ctr2 (__int64) - unsupported type
*/

int TimerClassBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TimerClassBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TimerClass object");
    return 1;
}

void TimerClassBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TimerClassBinding::gc },
        { "__tostring", TimerClassBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        TimerClassBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TimerClassBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua