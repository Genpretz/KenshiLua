#include "pch.h"
#include "kenshi\util\PerfTimer.h"
#include "CPerfTimerBinding.h"
#include "Lua/BindingHelpers.h"

__int64 CPerfTimer::m_Freq = 0;
__int64 CPerfTimer::m_Adjust = 0;

const double CPerfTimer::Resolution() { return 1.0 / (double)m_Freq; }
const double CPerfTimer::Resolutionms() { return 1000.0 / (double)m_Freq; }
const double CPerfTimer::Resolutionus() { return 1000000.0 / (double)m_Freq; }
BOOL CPerfTimer::IsSupported() { return m_Freq > 1; }

namespace KenshiLua
{

static CPerfTimer* getInstance(lua_State* L, int idx)
{
    return checkObject<CPerfTimer>(L, idx, CPerfTimerBinding::getMetatableName());
}

// --- Getters for CPerfTimer ---
// --- Setters for CPerfTimer ---
int CPerfTimerBinding::Start(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    BOOL bReset = lua_isboolean(L, 2) ? (lua_toboolean(L, 2) ? TRUE : FALSE) : FALSE;
    instance->Start(bReset);
    return 0;
}

int CPerfTimerBinding::Stop(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    instance->Stop();
    return 0;
}

int CPerfTimerBinding::IsRunning(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    BOOL result = instance->IsRunning();
    lua_pushboolean(L, result != FALSE);
    return 1;
}

int CPerfTimerBinding::IsSupported(lua_State* L)
{
    CPerfTimer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CPerfTimer is nil");

    BOOL result = instance->IsSupported();
    lua_pushboolean(L, result != FALSE);
    return 1;
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

int CPerfTimerBinding::operator_assign(lua_State* L)
{
    CPerfTimer* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "CPerfTimer is nil");

    CPerfTimer* b = checkObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    if (!b) return luaL_error(L, "Argument 1 to operator_assign must be CPerfTimer");

    *a = *b;
    lua_settop(L, 1);
    return 1;
}

int CPerfTimerBinding::operator_add(lua_State* L)
{
    CPerfTimer* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "Left operand must be CPerfTimer");

    CPerfTimer* b = testObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    if (b)
    {
        CPerfTimer res = *a + *b;
        return pushValue<CPerfTimer>(L, res, CPerfTimerBinding::getMetatableName());
    }
    else if (lua_isnumber(L, 2))
    {
        double secs = (double)lua_tonumber(L, 2);
        CPerfTimer res = *a + secs;
        return pushValue<CPerfTimer>(L, res, CPerfTimerBinding::getMetatableName());
    }
    return luaL_error(L, "Right operand must be CPerfTimer or number");
}

int CPerfTimerBinding::operator_sub(lua_State* L)
{
    CPerfTimer* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "Left operand must be CPerfTimer");

    CPerfTimer* b = testObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    if (b)
    {
        CPerfTimer res = *a - *b;
        return pushValue<CPerfTimer>(L, res, CPerfTimerBinding::getMetatableName());
    }
    else if (lua_isnumber(L, 2))
    {
        double secs = (double)lua_tonumber(L, 2);
        CPerfTimer res = *a - secs;
        return pushValue<CPerfTimer>(L, res, CPerfTimerBinding::getMetatableName());
    }
    return luaL_error(L, "Right operand must be CPerfTimer or number");
}

int CPerfTimerBinding::operator_add_assign(lua_State* L)
{
    CPerfTimer* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "Left operand must be CPerfTimer");

    CPerfTimer* b = testObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    if (b)
    {
        *a += *b;
        lua_settop(L, 1);
        return 1;
    }
    else if (lua_isnumber(L, 2))
    {
        double secs = (double)lua_tonumber(L, 2);
        *a += secs;
        lua_settop(L, 1);
        return 1;
    }
    return luaL_error(L, "Right operand must be CPerfTimer or number");
}

int CPerfTimerBinding::operator_sub_assign(lua_State* L)
{
    CPerfTimer* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "Left operand must be CPerfTimer");

    CPerfTimer* b = testObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    if (b)
    {
        *a -= *b;
        lua_settop(L, 1);
        return 1;
    }
    else if (lua_isnumber(L, 2))
    {
        double secs = (double)lua_tonumber(L, 2);
        *a -= secs;
        lua_settop(L, 1);
        return 1;
    }
    return luaL_error(L, "Right operand must be CPerfTimer or number");
}

int CPerfTimerBinding::operator_lt(lua_State* L)
{
    CPerfTimer* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "Left operand must be CPerfTimer");

    CPerfTimer* b = testObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    if (b)
    {
        BOOL res = *a < *b;
        lua_pushboolean(L, res ? 1 : 0);
        return 1;
    }
    else if (lua_isnumber(L, 2))
    {
        double secs = (double)lua_tonumber(L, 2);
        BOOL res = *a < secs;
        lua_pushboolean(L, res ? 1 : 0);
        return 1;
    }
    return luaL_error(L, "Right operand must be CPerfTimer or number");
}

int CPerfTimerBinding::operator_le(lua_State* L)
{
    CPerfTimer* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "Left operand must be CPerfTimer");

    CPerfTimer* b = testObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    if (b)
    {
        BOOL res = *a <= *b;
        lua_pushboolean(L, res ? 1 : 0);
        return 1;
    }
    else if (lua_isnumber(L, 2))
    {
        double secs = (double)lua_tonumber(L, 2);
        BOOL res = *a <= secs;
        lua_pushboolean(L, res ? 1 : 0);
        return 1;
    }
    return luaL_error(L, "Right operand must be CPerfTimer or number");
}

int CPerfTimerBinding::operator_gt(lua_State* L)
{
    CPerfTimer* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "Left operand must be CPerfTimer");

    CPerfTimer* b = testObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    if (b)
    {
        BOOL res = *a > *b;
        lua_pushboolean(L, res ? 1 : 0);
        return 1;
    }
    else if (lua_isnumber(L, 2))
    {
        double secs = (double)lua_tonumber(L, 2);
        BOOL res = *a > secs;
        lua_pushboolean(L, res ? 1 : 0);
        return 1;
    }
    return luaL_error(L, "Right operand must be CPerfTimer or number");
}

int CPerfTimerBinding::operator_ge(lua_State* L)
{
    CPerfTimer* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "Left operand must be CPerfTimer");

    CPerfTimer* b = testObject<CPerfTimer>(L, 2, CPerfTimerBinding::getMetatableName());
    if (b)
    {
        BOOL res = *a >= *b;
        lua_pushboolean(L, res ? 1 : 0);
        return 1;
    }
    else if (lua_isnumber(L, 2))
    {
        double secs = (double)lua_tonumber(L, 2);
        BOOL res = *a >= secs;
        lua_pushboolean(L, res ? 1 : 0);
        return 1;
    }
    return luaL_error(L, "Right operand must be CPerfTimer or number");
}

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
        { "__add",      CPerfTimerBinding::operator_add },
        { "__sub",      CPerfTimerBinding::operator_sub },
        { "__lt",       CPerfTimerBinding::operator_lt },
        { "__le",       CPerfTimerBinding::operator_le },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "operator_assign", CPerfTimerBinding::operator_assign },
        { "operator_add", CPerfTimerBinding::operator_add },
        { "operator_sub", CPerfTimerBinding::operator_sub },
        { "operator_add_assign", CPerfTimerBinding::operator_add_assign },
        { "operator_sub_assign", CPerfTimerBinding::operator_sub_assign },
        { "operator_lt", CPerfTimerBinding::operator_lt },
        { "operator_le", CPerfTimerBinding::operator_le },
        { "operator_gt", CPerfTimerBinding::operator_gt },
        { "operator_ge", CPerfTimerBinding::operator_ge },
        { "Start", CPerfTimerBinding::Start },
        { "Stop", CPerfTimerBinding::Stop },
        { "IsRunning", CPerfTimerBinding::IsRunning },
        { "IsSupported", CPerfTimerBinding::IsSupported },
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