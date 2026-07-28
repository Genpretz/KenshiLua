#include "pch.h"
#include "kenshi\logger.h"
#include "LoggerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Logger* getInstance(lua_State* L, int idx)
{
    return checkObject<Logger>(L, idx, LoggerBinding::getMetatableName());
}

// --- Getters for Logger ---
// --- Setters for Logger ---
/*
Skipped methods needing manual binding:
  line 18: void init(...) - static method
  line 19: void close(...) - static method
  line 20: void logMessage(...) - static method
  line 21: void logMessageDebug(...) - static method
  line 22: void logHeader(...) - static method
*/

int LoggerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LoggerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Logger object");
    return 1;
}

void LoggerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LoggerBinding::gc },
        { "__tostring", LoggerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        LoggerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LoggerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua