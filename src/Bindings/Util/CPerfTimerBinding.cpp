#include "pch.h"
#include "kenshi\util\PerfTimer.h"
#include "CPerfTimerBinding.h"
#include "Lua/BindingHelpers.h"

__int64 CPerfTimer::m_Freq = 0;
__int64 CPerfTimer::m_Adjust = 0;

const double CPerfTimer::Resolution() { return 1.0 / (double)m_Freq; }
const double CPerfTimer::Resolutionms() { return 1000.0 / (double)m_Freq; }
const double CPerfTimer::Resolutionus() { return 1000000.0 / (double)m_Freq; }

namespace KenshiLua
{

static CPerfTimer* getInstance(lua_State* L, int idx)
{
    return checkObject<CPerfTimer>(L, idx, CPerfTimerBinding::getMetatableName());
}

// --- Getters for CPerfTimer ---
// --- Setters for CPerfTimer ---
int CPerfTimerBinding::Stop(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    instance->Stop();
    return 0;
}

int CPerfTimerBinding::Resolution(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    const double result = instance->Resolution();
    lua_pushnumber(L, result);
    return 1;
}

int CPerfTimerBinding::Resolutionms(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    const double result = instance->Resolutionms();
    lua_pushnumber(L, result);
    return 1;
}

int CPerfTimerBinding::Resolutionus(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    const double result = instance->Resolutionus();
    lua_pushnumber(L, result);
    return 1;
}

int CPerfTimerBinding::Elapsed(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    const double result = instance->Elapsed();
    lua_pushnumber(L, result);
    return 1;
}

int CPerfTimerBinding::Elapsedms(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    const double result = instance->Elapsedms();
    lua_pushnumber(L, result);
    return 1;
}

int CPerfTimerBinding::Elapsedus(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    const double result = instance->Elapsedus();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 32: void Start(...) - unsupported arg type
  line 35: BOOL IsRunning(...) - unsupported return type
  line 37: BOOL IsSupported(...) - unsupported return type
  line 48: const CPerfTimer& operator=(...) - operator
  line 51: CPerfTimer operator+(...) - operator
  line 52: CPerfTimer operator-(...) - operator
  line 53: const CPerfTimer& operator+=(...) - operator
  line 54: const CPerfTimer& operator-=(...) - operator
  line 56: CPerfTimer operator+(...) - operator
  line 57: CPerfTimer operator-(...) - operator
  line 58: const CPerfTimer& operator+=(...) - operator
  line 59: const CPerfTimer& operator-=(...) - operator
  line 62: BOOL operator<(...) - operator
  line 63: BOOL operator>(...) - operator
  line 64: BOOL operator<=(...) - operator
  line 65: BOOL operator>=(...) - operator
  line 67: BOOL operator<(...) - operator
  line 68: BOOL operator>(...) - operator
  line 69: BOOL operator<=(...) - operator
  line 70: BOOL operator>=(...) - operator
*/

int CPerfTimerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CPerfTimerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CPerfTimer object");
    return 1;
}

void CPerfTimerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CPerfTimerBinding::gc },
        { "__tostring", CPerfTimerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "Stop", CPerfTimerBinding::Stop },
        { "Resolution", CPerfTimerBinding::Resolution },
        { "Resolutionms", CPerfTimerBinding::Resolutionms },
        { "Resolutionus", CPerfTimerBinding::Resolutionus },
        { "Elapsed", CPerfTimerBinding::Elapsed },
        { "Elapsedms", CPerfTimerBinding::Elapsedms },
        { "Elapsedus", CPerfTimerBinding::Elapsedus },
        { 0, 0 }
    };

    registerClass(
        L, 
        CPerfTimerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CPerfTimerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua