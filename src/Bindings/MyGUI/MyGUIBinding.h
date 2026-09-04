#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class MyGUIBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.Widget"; }
    static void registerBinding(lua_State* L);
    static void destroyWidgetsBySource(const std::string& source);
    static void shutdown();
};

typedef MyGUIBinding MyGuiBinding;

} // namespace KenshiLua
