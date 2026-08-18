#pragma once

#include "kenshi/gui/MessageBoxManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MessageBoxManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MessageBoxManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int hideMessageBox(lua_State* L);
    static int hasModalMessage(lua_State* L);
};
}