#include "pch.h"
#include "Bindings/MyGUI/MultiListBoxBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::MultiListBox* MultiListBoxBinding::getMultiListBox(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::MultiListBox>(false);
}

int MultiListBoxBinding::getColumnCount(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    if (mlb) lua_pushinteger(L, (lua_Integer)mlb->getColumnCount());
    else lua_pushinteger(L, 0);
    return 1;
}

int MultiListBoxBinding::insertColumnAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t col = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    int width = (int)luaL_optinteger(L, 4, 100);
    if (mlb) mlb->insertColumnAt(col, name, width);
    return 0;
}

int MultiListBoxBinding::addColumn(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    const char* name = luaL_checkstring(L, 2);
    int width = (int)luaL_optinteger(L, 3, 100);
    if (mlb) mlb->addColumn(name, width);
    return 0;
}

int MultiListBoxBinding::removeColumnAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t col = (size_t)luaL_checkinteger(L, 2);
    if (mlb) mlb->removeColumnAt(col);
    return 0;
}

int MultiListBoxBinding::removeAllColumns(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    if (mlb) mlb->removeAllColumns();
    return 0;
}

int MultiListBoxBinding::setColumnNameAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t col = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (mlb) mlb->setColumnNameAt(col, name);
    return 0;
}

int MultiListBoxBinding::setColumnWidthAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t col = (size_t)luaL_checkinteger(L, 2);
    int width = (int)luaL_checkinteger(L, 3);
    if (mlb) mlb->setColumnWidthAt(col, width);
    return 0;
}

int MultiListBoxBinding::getColumnNameAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t col = (size_t)luaL_checkinteger(L, 2);
    if (mlb && col < mlb->getColumnCount())
    {
        std::string n = mlb->getColumnNameAt(col).asUTF8();
        lua_pushstring(L, n.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int MultiListBoxBinding::getColumnWidthAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t col = (size_t)luaL_checkinteger(L, 2);
    if (mlb && col < mlb->getColumnCount())
    {
        lua_pushinteger(L, mlb->getColumnWidthAt(col));
        return 1;
    }
    lua_pushinteger(L, 0);
    return 1;
}

int MultiListBoxBinding::getItemCount(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    if (mlb) lua_pushinteger(L, (lua_Integer)mlb->getItemCount());
    else lua_pushinteger(L, 0);
    return 1;
}

int MultiListBoxBinding::insertItemAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (mlb) mlb->insertItemAt(idx, name);
    return 0;
}

int MultiListBoxBinding::addItem(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (mlb) mlb->addItem(name);
    return 0;
}

int MultiListBoxBinding::removeItemAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (mlb) mlb->removeItemAt(idx);
    return 0;
}

int MultiListBoxBinding::removeAllItems(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    if (mlb) mlb->removeAllItems();
    return 0;
}

int MultiListBoxBinding::swapItemsAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t i1 = (size_t)luaL_checkinteger(L, 2);
    size_t i2 = (size_t)luaL_checkinteger(L, 3);
    if (mlb) mlb->swapItemsAt(i1, i2);
    return 0;
}

int MultiListBoxBinding::setItemNameAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (mlb) mlb->setItemNameAt(idx, name);
    return 0;
}

int MultiListBoxBinding::getItemNameAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (mlb && idx < mlb->getItemCount())
    {
        std::string n = mlb->getItemNameAt(idx).asUTF8();
        lua_pushstring(L, n.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int MultiListBoxBinding::getIndexSelected(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    if (mlb)
    {
        size_t idx = mlb->getIndexSelected();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int MultiListBoxBinding::setIndexSelected(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    lua_Integer idx = luaL_checkinteger(L, 2);
    if (mlb)
    {
        if (idx < 0) mlb->clearIndexSelected();
        else mlb->setIndexSelected((size_t)idx);
    }
    return 0;
}

int MultiListBoxBinding::clearIndexSelected(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    if (mlb) mlb->clearIndexSelected();
    return 0;
}

int MultiListBoxBinding::setSubItemNameAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t col = (size_t)luaL_checkinteger(L, 2);
    size_t row = (size_t)luaL_checkinteger(L, 3);
    const char* name = luaL_checkstring(L, 4);
    if (mlb) mlb->setSubItemNameAt(col, row, name);
    return 0;
}

int MultiListBoxBinding::getSubItemNameAt(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t col = (size_t)luaL_checkinteger(L, 2);
    size_t row = (size_t)luaL_checkinteger(L, 3);
    if (mlb && col < mlb->getColumnCount() && row < mlb->getItemCount())
    {
        std::string n = mlb->getSubItemNameAt(col, row).asUTF8();
        lua_pushstring(L, n.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int MultiListBoxBinding::findSubItemWith(lua_State* L)
{
    MyGUI::MultiListBox* mlb = getMultiListBox(L, 1);
    size_t col = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (mlb)
    {
        size_t idx = mlb->findSubItemWith(col, name);
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

static int MultiListBox_index(lua_State* L)
{
    MyGUI::MultiListBox* mlb = MultiListBoxBinding::getMultiListBox(L, 1);
    if (!mlb) return luaL_error(L, "MultiListBox is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "itemCount") == 0 || strcmp(key, "count") == 0)
    {
        lua_pushinteger(L, (lua_Integer)mlb->getItemCount());
        return 1;
    }
    if (strcmp(key, "columnCount") == 0)
    {
        lua_pushinteger(L, (lua_Integer)mlb->getColumnCount());
        return 1;
    }
    if (strcmp(key, "indexSelected") == 0 || strcmp(key, "selectedIndex") == 0)
    {
        size_t idx = mlb->getIndexSelected();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int MultiListBox_newindex(lua_State* L)
{
    MyGUI::MultiListBox* mlb = MultiListBoxBinding::getMultiListBox(L, 1);
    if (!mlb) return luaL_error(L, "MultiListBox is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "indexSelected") == 0 || strcmp(key, "selectedIndex") == 0)
    {
        lua_Integer idx = luaL_checkinteger(L, 3);
        if (idx < 0) mlb->clearIndexSelected();
        else mlb->setIndexSelected((size_t)idx);
        return 0;
    }
    return genericPropertyNewIndex(L);
}

static int MultiListBox_tostring(lua_State* L)
{
    MyGUI::MultiListBox* mlb = MultiListBoxBinding::getMultiListBox(L, 1);
    char buf[128];
    if (mlb)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.MultiListBox('%s'):%p", mlb->getName().c_str(), mlb);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.MultiListBox(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void MultiListBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", MultiListBox_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getColumnCount",   getColumnCount },
        { "insertColumnAt",   insertColumnAt },
        { "addColumn",        addColumn },
        { "removeColumnAt",   removeColumnAt },
        { "removeAllColumns", removeAllColumns },
        { "setColumnNameAt",  setColumnNameAt },
        { "setColumnWidthAt", setColumnWidthAt },
        { "getColumnNameAt",  getColumnNameAt },
        { "getColumnWidthAt", getColumnWidthAt },
        { "getItemCount",     getItemCount },
        { "insertItemAt",     insertItemAt },
        { "addItem",          addItem },
        { "removeItemAt",     removeItemAt },
        { "removeAllItems",   removeAllItems },
        { "swapItemsAt",      swapItemsAt },
        { "setItemNameAt",    setItemNameAt },
        { "getItemNameAt",    getItemNameAt },
        { "getIndexSelected", getIndexSelected },
        { "setIndexSelected", setIndexSelected },
        { "clearIndexSelected", clearIndexSelected },
        { "setSubItemNameAt", setSubItemNameAt },
        { "getSubItemNameAt", getSubItemNameAt },
        { "findSubItemWith",  findSubItemWith },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, MultiListBox_index, MultiListBox_newindex);
    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
