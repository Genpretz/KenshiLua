#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DatapanelGUIBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DatapanelGUI"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setFrequentUpdateMode(lua_State* L);
    static int setPositionReal(lua_State* L);
    static int _NV_setPositionReal(lua_State* L);
    static int setPosition(lua_State* L);
    static int _NV_setPosition(lua_State* L);
    static int resize(lua_State* L);
    static int _NV_resize(lua_State* L);
    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int clearPage(lua_State* L);
    static int _NV_clearPage(lua_State* L);
    static int hideAllWidgets(lua_State* L);
    static int _NV_hideAllWidgets(lua_State* L);
    static int create(lua_State* L);
    static int _NV_create(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int show_NonSmooth(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int setPanelName(lua_State* L);
    static int showTabs(lua_State* L);
    static int _NV_showTabs(lua_State* L);
    static int addTab(lua_State* L);
    static int _NV_addTab(lua_State* L);
    static int setTabName(lua_State* L);
    static int _NV_setTabName(lua_State* L);
    static int setCaption(lua_State* L);
    static int setAutomaticRefresh(lua_State* L);
    static int _NV_setAutomaticRefresh(lua_State* L);
    static int setAutomaticTargeting(lua_State* L);
    static int _NV_setAutomaticTargeting(lua_State* L);
    static int _zeroLines(lua_State* L);
    static int _NV__zeroLines(lua_State* L);
    static int setLineStatInfo(lua_State* L);
    static int setLineFaction(lua_State* L);
    static int setLineTextButton(lua_State* L);
    static int setLineButton(lua_State* L);
    static int setLineToggleButton(lua_State* L);
    static int setLineProgress(lua_State* L);
    static int removeLine(lua_State* L);
    static int addSpace(lua_State* L);
    static int setCategoryIcon(lua_State* L);
    static int _NV_setCategoryIcon(lua_State* L);
    static int changeCategory(lua_State* L);
    static int _NV_changeCategory(lua_State* L);
    static int getCurrentCategory(lua_State* L);
    static int _NV_getCurrentCategory(lua_State* L);
    static int setLineSpacing(lua_State* L);
    static int _NV_setLineSpacing(lua_State* L);
    static int getLine(lua_State* L);
    static int _NV_getLine(lua_State* L);
    static int lineExists(lua_State* L);
    static int getContentHeight(lua_State* L);
    static int getNumLines(lua_State* L);
    static int getLineByNum(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int getNextVerticalPos(lua_State* L);
    static int dataExists(lua_State* L);
    static int clearCategoryTabs(lua_State* L);
};
}