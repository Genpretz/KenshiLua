#include "pch.h"
#include "Bindings/MyGUI/TabControlBinding.h"
#include "Bindings/MyGUI/TabItemBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::TabControl* TabControlBinding::getTabControl(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::TabControl>(false);
}

int TabControlBinding::getItemCount(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    if (tc) lua_pushinteger(L, (lua_Integer)tc->getItemCount());
    else lua_pushinteger(L, 0);
    return 1;
}

int TabControlBinding::insertItemAt(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (tc)
    {
        MyGUI::TabItem* item = tc->insertItemAt(idx, name);
        if (item) return MyGUIBindings::pushWidget(L, item);
    }
    lua_pushnil(L);
    return 1;
}

int TabControlBinding::addItem(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (tc)
    {
        MyGUI::TabItem* item = tc->addItem(name);
        if (item) return MyGUIBindings::pushWidget(L, item);
    }
    lua_pushnil(L);
    return 1;
}

int TabControlBinding::removeItemAt(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (tc) tc->removeItemAt(idx);
    return 0;
}

int TabControlBinding::removeAllItems(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    if (tc) tc->removeAllItems();
    return 0;
}

int TabControlBinding::getItemNameAt(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (tc && idx < tc->getItemCount())
    {
        std::string n = tc->getItemNameAt(idx).asUTF8();
        lua_pushstring(L, n.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int TabControlBinding::setItemNameAt(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (tc) tc->setItemNameAt(idx, name);
    return 0;
}

int TabControlBinding::getIndexSelected(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    if (tc)
    {
        size_t idx = tc->getIndexSelected();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int TabControlBinding::setIndexSelected(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    lua_Integer idx = luaL_checkinteger(L, 2);
    if (tc)
    {
        if (idx < 0) tc->setIndexSelected(MyGUI::ITEM_NONE);
        else tc->setIndexSelected((size_t)idx);
    }
    return 0;
}

int TabControlBinding::clearIndexSelected(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    if (tc) tc->setIndexSelected(MyGUI::ITEM_NONE);
    return 0;
}

int TabControlBinding::getItemAt(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (tc && idx < tc->getItemCount())
    {
        MyGUI::TabItem* item = tc->getItemAt(idx);
        if (item) return MyGUIBindings::pushWidget(L, item);
    }
    lua_pushnil(L);
    return 1;
}

int TabControlBinding::getItemSelected(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    if (tc)
    {
        MyGUI::TabItem* item = tc->getItemSelected();
        if (item) return MyGUIBindings::pushWidget(L, item);
    }
    lua_pushnil(L);
    return 1;
}

int TabControlBinding::setButtonWidthAt(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    int w = (int)luaL_checkinteger(L, 3);
    if (tc) tc->setButtonWidthAt(idx, w);
    return 0;
}

int TabControlBinding::getButtonWidthAt(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (tc) lua_pushinteger(L, tc->getButtonWidthAt(idx));
    else lua_pushinteger(L, 0);
    return 1;
}

int TabControlBinding::setButtonDefaultWidth(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    int w = (int)luaL_checkinteger(L, 2);
    if (tc) tc->setButtonDefaultWidth(w);
    return 0;
}

int TabControlBinding::getButtonDefaultWidth(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    if (tc) lua_pushinteger(L, tc->getButtonDefaultWidth());
    else lua_pushinteger(L, 0);
    return 1;
}

int TabControlBinding::setButtonAutoWidth(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    bool autoW = lua_toboolean(L, 2) != 0;
    if (tc) tc->setButtonAutoWidth(autoW);
    return 0;
}

int TabControlBinding::getButtonAutoWidth(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    if (tc) lua_pushboolean(L, tc->getButtonAutoWidth() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int TabControlBinding::setSmoothShow(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    bool smooth = lua_toboolean(L, 2) != 0;
    if (tc) tc->setSmoothShow(smooth);
    return 0;
}

int TabControlBinding::getSmoothShow(lua_State* L)
{
    MyGUI::TabControl* tc = getTabControl(L, 1);
    if (tc) lua_pushboolean(L, tc->getSmoothShow() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

static int TabControl_index(lua_State* L)
{
    MyGUI::TabControl* tc = TabControlBinding::getTabControl(L, 1);
    if (!tc) return luaL_error(L, "TabControl is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "itemCount") == 0 || strcmp(key, "count") == 0)
    {
        lua_pushinteger(L, (lua_Integer)tc->getItemCount());
        return 1;
    }
    if (strcmp(key, "indexSelected") == 0 || strcmp(key, "selectedIndex") == 0)
    {
        size_t idx = tc->getIndexSelected();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int TabControl_newindex(lua_State* L)
{
    MyGUI::TabControl* tc = TabControlBinding::getTabControl(L, 1);
    if (!tc) return luaL_error(L, "TabControl is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "indexSelected") == 0 || strcmp(key, "selectedIndex") == 0)
    {
        lua_Integer idx = luaL_checkinteger(L, 3);
        if (idx < 0) tc->setIndexSelected(MyGUI::ITEM_NONE);
        else tc->setIndexSelected((size_t)idx);
        return 0;
    }
    return genericPropertyNewIndex(L);
}

static int TabControl_tostring(lua_State* L)
{
    MyGUI::TabControl* tc = TabControlBinding::getTabControl(L, 1);
    char buf[128];
    if (tc)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.TabControl('%s'):%p", tc->getName().c_str(), tc);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.TabControl(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void TabControlBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", TabControl_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getItemCount",           getItemCount },
        { "insertItemAt",           insertItemAt },
        { "addItem",                addItem },
        { "removeItemAt",           removeItemAt },
        { "removeAllItems",         removeAllItems },
        { "getItemNameAt",          getItemNameAt },
        { "setItemNameAt",          setItemNameAt },
        { "getIndexSelected",       getIndexSelected },
        { "setIndexSelected",       setIndexSelected },
        { "clearIndexSelected",     clearIndexSelected },
        { "getItemAt",              getItemAt },
        { "getItemSelected",        getItemSelected },
        { "setButtonWidthAt",       setButtonWidthAt },
        { "getButtonWidthAt",       getButtonWidthAt },
        { "setButtonDefaultWidth",  setButtonDefaultWidth },
        { "getButtonDefaultWidth",  getButtonDefaultWidth },
        { "setButtonAutoWidth",     setButtonAutoWidth },
        { "getButtonAutoWidth",     getButtonAutoWidth },
        { "setSmoothShow",          setSmoothShow },
        { "getSmoothShow",          getSmoothShow },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, TabControl_index, TabControl_newindex);
    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
