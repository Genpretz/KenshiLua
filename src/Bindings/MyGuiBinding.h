#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class MyGuiBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.Widget"; }
    static void registerBinding(lua_State* L);
    static void shutdown();
};

} // namespace KenshiLua
