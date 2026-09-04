#include "pch.h"
#include "Bindings/MyGUI/ListBoxBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::ListBox* ListBoxBinding::getListBox(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::ListBox>(false);
}

int ListBoxBinding::getItemCount(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    if (lb) lua_pushinteger(L, (lua_Integer)lb->getItemCount());
    else lua_pushinteger(L, 0);
    return 1;
}

int ListBoxBinding::insertItemAt(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (lb) lb->insertItemAt(idx, name);
    return 0;
}

int ListBoxBinding::addItem(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (lb) lb->addItem(name);
    return 0;
}

int ListBoxBinding::removeItemAt(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (lb) lb->removeItemAt(idx);
    return 0;
}

int ListBoxBinding::removeAllItems(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    if (lb) lb->removeAllItems();
    return 0;
}

int ListBoxBinding::swapItemsAt(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    size_t i1 = (size_t)luaL_checkinteger(L, 2);
    size_t i2 = (size_t)luaL_checkinteger(L, 3);
    if (lb) lb->swapItemsAt(i1, i2);
    return 0;
}

int ListBoxBinding::setItemNameAt(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (lb) lb->setItemNameAt(idx, name);
    return 0;
}

int ListBoxBinding::getItemNameAt(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (lb && idx < lb->getItemCount())
    {
        std::string n = lb->getItemNameAt(idx).asUTF8();
        lua_pushstring(L, n.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int ListBoxBinding::getIndexSelected(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    if (lb)
    {
        size_t idx = lb->getIndexSelected();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int ListBoxBinding::setIndexSelected(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    lua_Integer idx = luaL_checkinteger(L, 2);
    if (lb)
    {
        if (idx < 0) lb->clearIndexSelected();
        else lb->setIndexSelected((size_t)idx);
    }
    return 0;
}

int ListBoxBinding::clearIndexSelected(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    if (lb) lb->clearIndexSelected();
    return 0;
}

int ListBoxBinding::findItemIndexWith(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (lb)
    {
        size_t idx = lb->findItemIndexWith(name);
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int ListBoxBinding::beginToItemAt(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (lb) lb->beginToItemAt(idx);
    return 0;
}

int ListBoxBinding::beginToItemFirst(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    if (lb) lb->beginToItemFirst();
    return 0;
}

int ListBoxBinding::beginToItemLast(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    if (lb) lb->beginToItemLast();
    return 0;
}

int ListBoxBinding::beginToItemSelected(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    if (lb) lb->beginToItemSelected();
    return 0;
}

int ListBoxBinding::isItemVisibleAt(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    bool fill = lua_isboolean(L, 3) ? (lua_toboolean(L, 3) != 0) : true;
    if (lb) lua_pushboolean(L, lb->isItemVisibleAt(idx, fill) ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ListBoxBinding::isItemSelectedVisible(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    bool fill = lua_isboolean(L, 2) ? (lua_toboolean(L, 2) != 0) : true;
    if (lb) lua_pushboolean(L, lb->isItemSelectedVisible(fill) ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ListBoxBinding::setScrollVisible(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    bool visible = lua_toboolean(L, 2) != 0;
    if (lb) lb->setScrollVisible(visible);
    return 0;
}

int ListBoxBinding::setScrollPosition(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    size_t pos = (size_t)luaL_checkinteger(L, 2);
    if (lb) lb->setScrollPosition(pos);
    return 0;
}

int ListBoxBinding::getOptimalHeight(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    if (lb) lua_pushinteger(L, lb->getOptimalHeight());
    else lua_pushinteger(L, 0);
    return 1;
}

int ListBoxBinding::getWidgetByIndex(lua_State* L)
{
    MyGUI::ListBox* lb = getListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (lb && idx < lb->getItemCount())
    {
        MyGUI::Widget* w = lb->getWidgetByIndex(idx);
        if (w) return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

static int ListBox_index(lua_State* L)
{
    MyGUI::ListBox* lb = ListBoxBinding::getListBox(L, 1);
    if (!lb) return luaL_error(L, "ListBox is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "itemCount") == 0 || strcmp(key, "count") == 0)
    {
        lua_pushinteger(L, (lua_Integer)lb->getItemCount());
        return 1;
    }
    if (strcmp(key, "indexSelected") == 0 || strcmp(key, "selectedIndex") == 0)
    {
        size_t idx = lb->getIndexSelected();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int ListBox_newindex(lua_State* L)
{
    MyGUI::ListBox* lb = ListBoxBinding::getListBox(L, 1);
    if (!lb) return luaL_error(L, "ListBox is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "indexSelected") == 0 || strcmp(key, "selectedIndex") == 0)
    {
        lua_Integer idx = luaL_checkinteger(L, 3);
        if (idx < 0) lb->clearIndexSelected();
        else lb->setIndexSelected((size_t)idx);
        return 0;
    }
    return genericPropertyNewIndex(L);
}

static int ListBox_tostring(lua_State* L)
{
    MyGUI::ListBox* lb = ListBoxBinding::getListBox(L, 1);
    char buf[128];
    if (lb)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ListBox('%s'):%p", lb->getName().c_str(), lb);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ListBox(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void ListBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", ListBox_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getItemCount",           getItemCount },
        { "insertItemAt",           insertItemAt },
        { "addItem",                addItem },
        { "removeItemAt",           removeItemAt },
        { "removeAllItems",         removeAllItems },
        { "swapItemsAt",            swapItemsAt },
        { "setItemNameAt",          setItemNameAt },
        { "getItemNameAt",          getItemNameAt },
        { "getIndexSelected",       getIndexSelected },
        { "setIndexSelected",       setIndexSelected },
        { "clearIndexSelected",     clearIndexSelected },
        { "findItemIndexWith",      findItemIndexWith },
        { "beginToItemAt",          beginToItemAt },
        { "beginToItemFirst",       beginToItemFirst },
        { "beginToItemLast",        beginToItemLast },
        { "beginToItemSelected",    beginToItemSelected },
        { "isItemVisibleAt",        isItemVisibleAt },
        { "isItemSelectedVisible",  isItemSelectedVisible },
        { "setScrollVisible",       setScrollVisible },
        { "setScrollPosition",      setScrollPosition },
        { "getOptimalHeight",       getOptimalHeight },
        { "getWidgetByIndex",       getWidgetByIndex },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, ListBox_index, ListBox_newindex);
    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
