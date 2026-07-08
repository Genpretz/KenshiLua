#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TutorialGUIBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TutorialGUI"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int startHighlight(lua_State* L);
    static int endHighlight(lua_State* L);
    static int _setHightlightCoords(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int setEnabled(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int arrangeList(lua_State* L);
    static int refreshUI(lua_State* L);
    static int closeTutorialWindow(lua_State* L);
    static int updateCurrentItem(lua_State* L);
};
}