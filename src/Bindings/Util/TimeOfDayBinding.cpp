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

/*
Skipped methods needing manual binding:
  line 9: TimeOfDay* _CONSTRUCTOR(...) - overloaded method
  line 11: TimeOfDay* _CONSTRUCTOR(...) - overloaded method
  line 17: bool operator>(...) - operator
  line 18: bool operator>=(...) - operator
  line 19: bool operator<(...) - operator
  line 20: bool operator<=(...) - operator
  line 21: bool operator==(...) - operator
  line 22: const TimeOfDay& operator=(...) - operator
*/

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
        { "__gc",       TimeOfDayBinding::gc },
        { "__tostring", TimeOfDayBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setNull", TimeOfDayBinding::setNull },
        { "isUnset", TimeOfDayBinding::isUnset },
        { "setTime", TimeOfDayBinding::setTime },
        { "addHours", TimeOfDayBinding::addHours },
        { "addMinutes", TimeOfDayBinding::addMinutes },
        { "getTotalHours", TimeOfDayBinding::getTotalHours },
        { "getTotalMinutes", TimeOfDayBinding::getTotalMinutes },
        { "getTotalSeconds", TimeOfDayBinding::getTotalSeconds },
        { "getRealLifeSeconds", TimeOfDayBinding::getRealLifeSeconds },
        { "getRealLifeSecondsPassed", TimeOfDayBinding::getRealLifeSecondsPassed },
        { "getTotalDays", TimeOfDayBinding::getTotalDays },
        { "stampTime", TimeOfDayBinding::stampTime },
        { "getHoursPassed", TimeOfDayBinding::getHoursPassed },
        { "getMinutesPassed", TimeOfDayBinding::getMinutesPassed },
        { "getSecondsPassed", TimeOfDayBinding::getSecondsPassed },
        { "timeOfDayHasPassed", TimeOfDayBinding::timeOfDayHasPassed },
        { "timePassed", TimeOfDayBinding::timePassed },
        { "getTimePassedString", TimeOfDayBinding::getTimePassedString },
        { "getTimeRemainingString", TimeOfDayBinding::getTimeRemainingString },
        { "getTotalTimeString", TimeOfDayBinding::getTotalTimeString },
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
    lua_pushcfunction(L, TimeOfDay_get_time);
    lua_setfield(L, -2, "time");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TimeOfDay_set_time);
    lua_setfield(L, -2, "time");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua