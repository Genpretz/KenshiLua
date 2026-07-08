#pragma once
#include <kenshi/gui/CharacterStatsWindow.h>


extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef CharacterStatsWindow::Stat Stat;
class StatBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Stat"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
};
}