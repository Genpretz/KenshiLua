#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class WidgetBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.Widget"; }
    static void registerBinding(lua_State* L);

    static MyGUI::Widget* getWidget(lua_State* L, int idx);

    // Common widget methods
    static int setPosition(lua_State* L);
    static int getPosition(lua_State* L);
    static int setSize(lua_State* L);
    static int getSize(lua_State* L);
    static int setCoord(lua_State* L);
    static int getCoord(lua_State* L);
    static int setRealPosition(lua_State* L);
    static int getRealPosition(lua_State* L);
    static int setRealSize(lua_State* L);
    static int getRealSize(lua_State* L);
    static int setRealCoord(lua_State* L);
    static int getRealCoord(lua_State* L);
    static int setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int getInheritedVisible(lua_State* L);
    static int setAlign(lua_State* L);
    static int getAlign(lua_State* L);
    static int setAlpha(lua_State* L);
    static int getAlpha(lua_State* L);
    static int setInheritsAlpha(lua_State* L);
    static int getInheritsAlpha(lua_State* L);
    static int setColour(lua_State* L);
    static int setDepth(lua_State* L);
    static int getDepth(lua_State* L);
    static int setEnabled(lua_State* L);
    static int getEnabled(lua_State* L);
    static int getInheritedEnabled(lua_State* L);
    static int setCaption(lua_State* L);
    static int getCaption(lua_State* L);
    static int setWidgetStyle(lua_State* L);
    static int getWidgetStyle(lua_State* L);
    static int setNeedKeyFocus(lua_State* L);
    static int getNeedKeyFocus(lua_State* L);
    static int setNeedMouseFocus(lua_State* L);
    static int getNeedMouseFocus(lua_State* L);
    static int setInheritsPick(lua_State* L);
    static int getInheritsPick(lua_State* L);
    static int setMaskPick(lua_State* L);
    static int setPointer(lua_State* L);
    static int getPointer(lua_State* L);
    static int setUserString(lua_State* L);
    static int getUserString(lua_State* L);
    static int isUserString(lua_State* L);
    static int clearUserString(lua_State* L);
    static int createWidget(lua_State* L);
    static int createWidgetReal(lua_State* L);
    static int getParent(lua_State* L);
    static int getRootWidget(lua_State* L);
    static int isRootWidget(lua_State* L);
    static int getChildCount(lua_State* L);
    static int getChildAt(lua_State* L);
    static int findWidget(lua_State* L);
    static int getClientWidget(lua_State* L);
    static int getClientCoord(lua_State* L);
    static int getType(lua_State* L);
    static int getName(lua_State* L);
    static int getLayerName(lua_State* L);
    static int getAbsoluteCoord(lua_State* L);
    static int getAbsolutePosition(lua_State* L);
    static int getAbsoluteRect(lua_State* L);
    static int changeWidgetSkin(lua_State* L);
    static int setProperty(lua_State* L);
    static int destroy(lua_State* L);
    static int registerCallback(lua_State* L);
};

} // namespace KenshiLua
