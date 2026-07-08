#pragma once
#include <kenshi/gui/BuildModeWindow.h>


extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef BuildModeWindow::BuildingCategory BuildingCategory;
class BuildingCategoryBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BuildingCategory"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
};
}