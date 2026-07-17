#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DialogueWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DialogueWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getVisible(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_show(lua_State* L);
    static int isVisible(lua_State* L);
    static int _NV_isVisible(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int getTop(lua_State* L);
    static int activateResponse(lua_State* L);
    static int setNPCText(lua_State* L);
    static int clearResponses(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int updatePanelsPosition(lua_State* L);
};
}