#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class EditBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.EditBox"; }
    static void registerBinding(lua_State* L);

    static MyGUI::EditBox* getEditBox(lua_State* L, int idx);

    static int getTextSelection(lua_State* L);
    static int setTextSelection(lua_State* L);
    static int deleteTextSelection(lua_State* L);
    static int isTextSelection(lua_State* L);
    static int getTextSelectionStart(lua_State* L);
    static int getTextSelectionEnd(lua_State* L);
    static int getTextSelectionLength(lua_State* L);
    static int getTextInterval(lua_State* L);
    static int setTextCursor(lua_State* L);
    static int getTextCursor(lua_State* L);
    static int getTextLength(lua_State* L);
    static int setOverflowToTheLeft(lua_State* L);
    static int getOverflowToTheLeft(lua_State* L);
    static int setMaxTextLength(lua_State* L);
    static int getMaxTextLength(lua_State* L);
    static int setEditWordWrap(lua_State* L);
    static int getEditWordWrap(lua_State* L);
    static int setEditReadOnly(lua_State* L);
    static int getEditReadOnly(lua_State* L);
    static int setEditMultiLine(lua_State* L);
    static int getEditMultiLine(lua_State* L);
    static int setEditPassword(lua_State* L);
    static int getEditPassword(lua_State* L);
    static int setEditStatic(lua_State* L);
    static int getEditStatic(lua_State* L);
    static int setPasswordChar(lua_State* L);
    static int getPasswordChar(lua_State* L);
    static int setOnlyText(lua_State* L);
    static int getOnlyText(lua_State* L);
    static int addText(lua_State* L);
    static int insertText(lua_State* L);
    static int eraseText(lua_State* L);
    static int setTextIntervalColour(lua_State* L);
    static int setTextSelectionColour(lua_State* L);
};

} // namespace KenshiLua
