#pragma once

#include "kenshi/gui/FogEditor.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FogEditorBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FogEditor"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int show(lua_State* L);
    static int close(lua_State* L);
    static int isActive(lua_State* L);
    static int update(lua_State* L);
    static int save(lua_State* L);
    static int updateFogName(lua_State* L);
    static int updateFogValues(lua_State* L);
    static int selectNextEdge(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}