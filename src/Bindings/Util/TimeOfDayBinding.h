#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TimeOfDayBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TimeOfDay"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setNull(lua_State* L);
    static int isUnset(lua_State* L);
    static int setTime(lua_State* L);
    static int addHours(lua_State* L);
    static int addMinutes(lua_State* L);
    static int getTotalHours(lua_State* L);
    static int getTotalMinutes(lua_State* L);
    static int getTotalSeconds(lua_State* L);
    static int getRealLifeSeconds(lua_State* L);
    static int getRealLifeSecondsPassed(lua_State* L);
    static int getTotalDays(lua_State* L);
    static int stampTime(lua_State* L);
    static int getHoursPassed(lua_State* L);
    static int getMinutesPassed(lua_State* L);
    static int getSecondsPassed(lua_State* L);
    static int timeOfDayHasPassed(lua_State* L);
    static int timePassed(lua_State* L);
    static int getTimePassedString(lua_State* L);
    static int getTimeRemainingString(lua_State* L);
    static int getTotalTimeString(lua_State* L);
};
}