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
int LoggerBinding::init(lua_State* L)
{
    Logger::init();
    return 0;
}

int LoggerBinding::close(lua_State* L)
{
    Logger::close();
    return 0;
}

int LoggerBinding::logMessage(lua_State* L)
{
    const std::string msg = luaL_checkstring(L, 1);
    Logger::Severity sev = (Logger::Severity)luaL_optinteger(L, 2, (lua_Integer)Logger::Info);
    Logger::logMessage(msg, sev);
    return 0;
}

int LoggerBinding::logMessageDebug(lua_State* L)
{
    const std::string msg = luaL_checkstring(L, 1);
    Logger::logMessageDebug(msg);
    return 0;
}

int LoggerBinding::logHeader(lua_State* L)
{
    Logger::logHeader();
    return 0;
}

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
        { "init", LoggerBinding::init },
        { "close", LoggerBinding::close },
        { "logMessage", LoggerBinding::logMessage },
        { "logMessageDebug", LoggerBinding::logMessageDebug },
        { "logHeader", LoggerBinding::logHeader },
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

    // Global Logger table for static log calls
    lua_newtable(L);
    lua_pushcfunction(L, LoggerBinding::init); lua_setfield(L, -2, "init");
    lua_pushcfunction(L, LoggerBinding::close); lua_setfield(L, -2, "close");
    lua_pushcfunction(L, LoggerBinding::logMessage); lua_setfield(L, -2, "logMessage");
    lua_pushcfunction(L, LoggerBinding::logMessageDebug); lua_setfield(L, -2, "logMessageDebug");
    lua_pushcfunction(L, LoggerBinding::logHeader); lua_setfield(L, -2, "logHeader");
    setEnum(L, "Trace", (lua_Integer)Logger::Trace);
    setEnum(L, "Debug", (lua_Integer)Logger::Debug);
    setEnum(L, "Info", (lua_Integer)Logger::Info);
    setEnum(L, "Warning", (lua_Integer)Logger::Warning);
    setEnum(L, "Error", (lua_Integer)Logger::Error);
    setEnum(L, "Fatal", (lua_Integer)Logger::Fatal);
    lua_setglobal(L, "Logger");
}

} // namespace KenshiLua