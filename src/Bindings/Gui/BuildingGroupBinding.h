#pragma once
#include <kenshi/gui/BuildModeWindow.h>


extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef BuildModeWindow::BuildingGroup BuildingGroup;
class BuildingGroupBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BuildingGroup"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
};
}