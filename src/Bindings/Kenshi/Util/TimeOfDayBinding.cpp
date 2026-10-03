#include "pch.h"
#include <kenshi\util\TimeOfDay.h>
#include "TimeOfDayBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TimeOfDay* getInstance(lua_State* L, int idx)
{
    return checkObject<TimeOfDay>(L, idx, TimeOfDayBinding::getMetatableName());
}

// --- Getters for TimeOfDay ---
static int TimeOfDay_get_time(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");
    lua_pushnumber(L, instance->time);
    return 1;
}

// --- Setters for TimeOfDay ---
static int TimeOfDay_set_time(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");
    instance->time = (double)luaL_checknumber(L, 2);
    return 0;
}

int TimeOfDayBinding::setNull(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    instance->setNull();
    return 0;
}

int TimeOfDayBinding::isUnset(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    bool result = instance->isUnset();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TimeOfDayBinding::setTime(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double hrs = (double)luaL_checknumber(L, 2);
    instance->setTime(hrs);
    return 0;
}

int TimeOfDayBinding::addHours(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double hours = (double)luaL_checknumber(L, 2);
    instance->addHours(hours);
    return 0;
}

int TimeOfDayBinding::addMinutes(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double mins = (double)luaL_checknumber(L, 2);
    instance->addMinutes(mins);
    return 0;
}

int TimeOfDayBinding::getTotalHours(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->getTotalHours();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::getTotalMinutes(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->getTotalMinutes();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::getTotalSeconds(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->getTotalSeconds();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::getRealLifeSeconds(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->getRealLifeSeconds();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::getRealLifeSecondsPassed(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->getRealLifeSecondsPassed();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::getTotalDays(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->getTotalDays();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::stampTime(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    instance->stampTime();
    return 0;
}

int TimeOfDayBinding::getHoursPassed(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->getHoursPassed();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::getMinutesPassed(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->getMinutesPassed();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::getSecondsPassed(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->getSecondsPassed();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::timeOfDayHasPassed(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double additionalHours = (double)luaL_checknumber(L, 2);
    bool result = instance->timeOfDayHasPassed(additionalHours);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TimeOfDayBinding::timePassed(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    double result = instance->timePassed();
    lua_pushnumber(L, result);
    return 1;
}

int TimeOfDayBinding::getTimePassedString(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    std::string result = instance->getTimePassedString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TimeOfDayBinding::getTimeRemainingString(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    std::string result = instance->getTimeRemainingString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TimeOfDayBinding::getTotalTimeString(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    std::string result = instance->getTotalTimeString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TimeOfDayBinding::operator_gt(lua_State* L)
{
    TimeOfDay* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "TimeOfDay is nil");

    TimeOfDay* b = getInstance(L, 2);
    if (!b) return luaL_error(L, "Argument 2 to operator_gt must be TimeOfDay");

    lua_pushboolean(L, (*a > *b) ? 1 : 0);
    return 1;
}

int TimeOfDayBinding::operator_ge(lua_State* L)
{
    TimeOfDay* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "TimeOfDay is nil");

    TimeOfDay* b = getInstance(L, 2);
    if (!b) return luaL_error(L, "Argument 2 to operator_ge must be TimeOfDay");

    lua_pushboolean(L, (*a >= *b) ? 1 : 0);
    return 1;
}

int TimeOfDayBinding::operator_lt(lua_State* L)
{
    TimeOfDay* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "TimeOfDay is nil");

    TimeOfDay* b = getInstance(L, 2);
    if (!b) return luaL_error(L, "Argument 2 to operator_lt must be TimeOfDay");

    lua_pushboolean(L, (*a < *b) ? 1 : 0);
    return 1;
}

int TimeOfDayBinding::operator_le(lua_State* L)
{
    TimeOfDay* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "TimeOfDay is nil");

    TimeOfDay* b = getInstance(L, 2);
    if (!b) return luaL_error(L, "Argument 2 to operator_le must be TimeOfDay");

    lua_pushboolean(L, (*a <= *b) ? 1 : 0);
    return 1;
}

int TimeOfDayBinding::operator_eq(lua_State* L)
{
    TimeOfDay* a = testObject<TimeOfDay>(L, 1, TimeOfDayBinding::getMetatableName());
    TimeOfDay* b = testObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());

    lua_pushboolean(L, (a && b && (*a == *b)) ? 1 : 0);
    return 1;
}

int TimeOfDayBinding::operator_assign(lua_State* L)
{
    TimeOfDay* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TimeOfDay is nil");

    TimeOfDay* other = getInstance(L, 2);
    if (!other) return luaL_error(L, "Argument 2 to operator_assign must be TimeOfDay");

    instance->operator=(*other);
    lua_pushvalue(L, 1);
    return 1;
}

int TimeOfDayBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TimeOfDayBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TimeOfDay object");
    return 1;
}

void TimeOfDayBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       TimeOfDayBinding::operator_eq },
        { "__lt",       TimeOfDayBinding::operator_lt },
        { "__le",       TimeOfDayBinding::operator_le },
        { "__gc",       TimeOfDayBinding::gc },
        { "__tostring", TimeOfDayBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setNull",                 TimeOfDayBinding::setNull },
        { "isUnset",                 TimeOfDayBinding::isUnset },
        { "setTime",                 TimeOfDayBinding::setTime },
        { "addHours",                TimeOfDayBinding::addHours },
        { "addMinutes",              TimeOfDayBinding::addMinutes },
        { "getTotalHours",           TimeOfDayBinding::getTotalHours },
        { "getTotalMinutes",         TimeOfDayBinding::getTotalMinutes },
        { "getTotalSeconds",         TimeOfDayBinding::getTotalSeconds },
        { "getRealLifeSeconds",      TimeOfDayBinding::getRealLifeSeconds },
        { "getRealLifeSecondsPassed",TimeOfDayBinding::getRealLifeSecondsPassed },
        { "getTotalDays",            TimeOfDayBinding::getTotalDays },
        { "stampTime",               TimeOfDayBinding::stampTime },
        { "getHoursPassed",          TimeOfDayBinding::getHoursPassed },
        { "getMinutesPassed",        TimeOfDayBinding::getMinutesPassed },
        { "getSecondsPassed",        TimeOfDayBinding::getSecondsPassed },
        { "timeOfDayHasPassed",      TimeOfDayBinding::timeOfDayHasPassed },
        { "timePassed",              TimeOfDayBinding::timePassed },
        { "getTimePassedString",     TimeOfDayBinding::getTimePassedString },
        { "getTimeRemainingString",  TimeOfDayBinding::getTimeRemainingString },
        { "getTotalTimeString",      TimeOfDayBinding::getTotalTimeString },
        { "operator_gt",             TimeOfDayBinding::operator_gt },
        { "operator_ge",             TimeOfDayBinding::operator_ge },
        { "operator_lt",             TimeOfDayBinding::operator_lt },
        { "operator_le",             TimeOfDayBinding::operator_le },
        { "operator_eq",             TimeOfDayBinding::operator_eq },
        { "operator_assign",         TimeOfDayBinding::operator_assign },
        { 0, 0 }
    };

    registerClass(
        L, 
        TimeOfDayBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TimeOfDayBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "time", TimeOfDay_get_time);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "time", TimeOfDay_set_time);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua