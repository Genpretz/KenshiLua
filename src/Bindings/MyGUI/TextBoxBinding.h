#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class TextBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.TextBox"; }
    static void registerBinding(lua_State* L);

    static MyGUI::TextBox* getTextBox(lua_State* L, int idx);

    static int getTextRegion(lua_State* L);
    static int getTextSize(lua_State* L);
    static int setFontName(lua_State* L);
    static int getFontName(lua_State* L);
    static int setFontHeight(lua_State* L);
    static int getFontHeight(lua_State* L);
    static int setTextAlign(lua_State* L);
    static int getTextAlign(lua_State* L);
    static int setTextColour(lua_State* L);
    static int getTextColour(lua_State* L);
    static int setCaptionWithReplacing(lua_State* L);
};

} // namespace KenshiLua
