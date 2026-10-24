#pragma once

#include "kenshi/AI/AITaskSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ActionDequeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ActionDeque"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getFirstTask(lua_State* L);
    static int getSecondTask(lua_State* L);
    static int getLastTask(lua_State* L);
    static int hasTask(lua_State* L);
    static int insertTask(lua_State* L);
    static int addTask(lua_State* L);
    static int clearAndDelete(lua_State* L);
    static int clearOnly(lua_State* L);
    static int passOnCurrentTask(lua_State* L);
    static int isEmpty(lua_State* L);
    static int isOnlyOne(lua_State* L);
};
}
