#pragma once

#include "kenshi/AI/AITaskSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AITaskSytem_ActionsListMgrBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AITaskSytem_ActionsListMgr"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int copyFrom(lua_State* L);
    static int addFrom(lua_State* L);
    static int getTaskAfterCurrent(lua_State* L);
    static int get2TasksAfterCurrent(lua_State* L);
};
}
