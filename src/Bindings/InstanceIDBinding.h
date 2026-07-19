#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InstanceIDBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InstanceID"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int assign(lua_State* L);
    static int clear(lua_State* L);
    static int needsSaving(lua_State* L);
    static int notifyChange(lua_State* L);
    static int hasChanges(lua_State* L);
    static int notifySaved(lua_State* L);
    static int empty(lua_State* L);
    static int getBaseIndex(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}
