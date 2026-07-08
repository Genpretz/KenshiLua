#pragma once
#include <kenshi/gui/TutorialGUI.h>


extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef TutorialGUI::TutorialGUILine TutorialGUILine;
class TutorialGUILineBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TutorialGUILine"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int updateHighlight(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}