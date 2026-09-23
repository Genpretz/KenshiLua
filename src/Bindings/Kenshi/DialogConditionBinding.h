#pragma once

#include "kenshi/Dialogue.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DialogConditionBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DialogCondition"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}