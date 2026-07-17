#pragma once
#include <kenshi/gui/FactionsScreen.h>


extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef FactionsScreen::FactionRelationsLine FactionRelationsLine;
class FactionRelationsLineBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FactionRelationsLine"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}