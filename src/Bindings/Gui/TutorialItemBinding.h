#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TutorialItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TutorialItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int getId(lua_State* L);
    static int isLastSubItem(lua_State* L);
    static int isSkippable(lua_State* L);
    static int isActive(lua_State* L);
    static int hasEnded(lua_State* L);
    static int getCurrentSubItem(lua_State* L);
    static int getSubItemAt(lua_State* L);
    static int getCurrentSubItemIndex(lua_State* L);
    static int getNumSubItems(lua_State* L);
    static int hasNextSubItem(lua_State* L);
    static int hasPrevSubItem(lua_State* L);
    static int nextSubItem(lua_State* L);
    static int prevSubItem(lua_State* L);
    static int getStarted(lua_State* L);
    static int getEnded(lua_State* L);
    static int reset(lua_State* L);
    static int _NV_reset(lua_State* L);
    static int conditionsMet(lua_State* L);
    static int start(lua_State* L);
    static int _NV_start(lua_State* L);
    static int run(lua_State* L);
    static int _NV_run(lua_State* L);
    static int end(lua_State* L);
    static int _NV_end(lua_State* L);
};
}