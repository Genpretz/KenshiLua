#include "pch.h"
#include "Bindings/MyGUI/ItemBoxBinding.h"
#include "Bindings/MyGUI/DDContainerBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::ItemBox* ItemBoxBinding::getItemBox(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::ItemBox>(false);
}

int ItemBoxBinding::getItemCount(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    if (ib) lua_pushinteger(L, (lua_Integer)ib->getItemCount());
    else lua_pushinteger(L, 0);
    return 1;
}

int ItemBoxBinding::insertItemAt(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (ib) ib->insertItemAt(idx);
    return 0;
}

int ItemBoxBinding::addItem(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    if (ib) ib->addItem();
    return 0;
}

int ItemBoxBinding::removeItemAt(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (ib) ib->removeItemAt(idx);
    return 0;
}

int ItemBoxBinding::removeAllItems(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    if (ib) ib->removeAllItems();
    return 0;
}

int ItemBoxBinding::getIndexSelected(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    if (ib)
    {
        size_t idx = ib->getIndexSelected();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int ItemBoxBinding::setIndexSelected(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    lua_Integer idx = luaL_checkinteger(L, 2);
    if (ib)
    {
        if (idx < 0) ib->clearIndexSelected();
        else ib->setIndexSelected((size_t)idx);
    }
    return 0;
}

int ItemBoxBinding::clearIndexSelected(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    if (ib) ib->clearIndexSelected();
    return 0;
}

int ItemBoxBinding::redrawItemAt(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (ib) ib->redrawItemAt(idx);
    return 0;
}

int ItemBoxBinding::redrawAllItems(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    if (ib) ib->redrawAllItems();
    return 0;
}

int ItemBoxBinding::resetDrag(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    if (ib) ib->resetDrag();
    return 0;
}

int ItemBoxBinding::getWidgetDrag(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    if (ib && ib->getWidgetDrag())
    {
        return MyGUIBindings::pushWidget(L, ib->getWidgetDrag());
    }
    lua_pushnil(L);
    return 1;
}

int ItemBoxBinding::getWidgetByIndex(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (ib && idx < ib->getItemCount())
    {
        MyGUI::Widget* w = ib->getWidgetByIndex(idx);
        if (w) return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

int ItemBoxBinding::getIndexByWidget(lua_State* L)
{
    MyGUI::ItemBox* ib = getItemBox(L, 1);
    MyGUI::Widget* w = WidgetBinding::getWidget(L, 2);
    if (ib && w)
    {
        size_t idx = ib->getIndexByWidget(w);
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

static int ItemBox_tostring(lua_State* L)
{
    MyGUI::ItemBox* ib = ItemBoxBinding::getItemBox(L, 1);
    char buf[128];
    if (ib)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ItemBox('%s'):%p", ib->getName().c_str(), ib);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ItemBox(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void ItemBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", ItemBox_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getItemCount",        getItemCount },
        { "insertItemAt",        insertItemAt },
        { "addItem",             addItem },
        { "removeItemAt",        removeItemAt },
        { "removeAllItems",      removeAllItems },
        { "getIndexSelected",    getIndexSelected },
        { "setIndexSelected",    setIndexSelected },
        { "clearIndexSelected",  clearIndexSelected },
        { "redrawItemAt",        redrawItemAt },
        { "redrawAllItems",      redrawAllItems },
        { "resetDrag",           resetDrag },
        { "getWidgetDrag",       getWidgetDrag },
        { "getWidgetByIndex",    getWidgetByIndex },
        { "getIndexByWidget",    getIndexByWidget },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    setMetatableParent(L, getMetatableName(), DDContainerBinding::getMetatableName());
}

} // namespace KenshiLua
