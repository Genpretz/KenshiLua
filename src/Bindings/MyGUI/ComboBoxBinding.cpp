#include "pch.h"
#include "Bindings/MyGUI/ComboBoxBinding.h"
#include "Bindings/MyGUI/EditBoxBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::ComboBox* ComboBoxBinding::getComboBox(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::ComboBox>(false);
}

int ComboBoxBinding::getItemCount(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) lua_pushinteger(L, (lua_Integer)cb->getItemCount());
    else lua_pushinteger(L, 0);
    return 1;
}

int ComboBoxBinding::insertItemAt(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (cb) cb->insertItemAt(idx, name);
    return 0;
}

int ComboBoxBinding::addItem(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (cb) cb->addItem(name);
    return 0;
}

int ComboBoxBinding::removeItemAt(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (cb) cb->removeItemAt(idx);
    return 0;
}

int ComboBoxBinding::removeAllItems(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) cb->removeAllItems();
    return 0;
}

int ComboBoxBinding::setItemNameAt(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (cb) cb->setItemNameAt(idx, name);
    return 0;
}

int ComboBoxBinding::getItemNameAt(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (cb && idx < cb->getItemCount())
    {
        std::string n = cb->getItemNameAt(idx).asUTF8();
        lua_pushstring(L, n.c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int ComboBoxBinding::getIndexSelected(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb)
    {
        size_t idx = cb->getIndexSelected();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int ComboBoxBinding::setIndexSelected(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    lua_Integer idx = luaL_checkinteger(L, 2);
    if (cb)
    {
        if (idx < 0) cb->clearIndexSelected();
        else cb->setIndexSelected((size_t)idx);
    }
    return 0;
}

int ComboBoxBinding::clearIndexSelected(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) cb->clearIndexSelected();
    return 0;
}

int ComboBoxBinding::findItemIndexWith(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (cb)
    {
        size_t idx = cb->findItemIndexWith(name);
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int ComboBoxBinding::beginToItemAt(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (cb) cb->beginToItemAt(idx);
    return 0;
}

int ComboBoxBinding::beginToItemFirst(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) cb->beginToItemFirst();
    return 0;
}

int ComboBoxBinding::beginToItemLast(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) cb->beginToItemLast();
    return 0;
}

int ComboBoxBinding::beginToItemSelected(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) cb->beginToItemSelected();
    return 0;
}

int ComboBoxBinding::setComboModeDrop(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    bool drop = lua_toboolean(L, 2) != 0;
    if (cb) cb->setComboModeDrop(drop);
    return 0;
}

int ComboBoxBinding::getComboModeDrop(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) lua_pushboolean(L, cb->getComboModeDrop() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ComboBoxBinding::setSmoothShow(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    bool smooth = lua_toboolean(L, 2) != 0;
    if (cb) cb->setSmoothShow(smooth);
    return 0;
}

int ComboBoxBinding::getSmoothShow(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) lua_pushboolean(L, cb->getSmoothShow() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ComboBoxBinding::setMaxListLength(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    int len = (int)luaL_checkinteger(L, 2);
    if (cb) cb->setMaxListLength(len);
    return 0;
}

int ComboBoxBinding::getMaxListLength(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) lua_pushinteger(L, cb->getMaxListLength());
    else lua_pushinteger(L, 0);
    return 1;
}

int ComboBoxBinding::setFlowDirection(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    int dir = (int)luaL_checkinteger(L, 2);
    if (cb) cb->setFlowDirection(MyGUI::FlowDirection((MyGUI::FlowDirection::Enum)dir));
    return 0;
}

int ComboBoxBinding::getFlowDirection(lua_State* L)
{
    MyGUI::ComboBox* cb = getComboBox(L, 1);
    if (cb) lua_pushinteger(L, (lua_Integer)cb->getFlowDirection().getValue());
    else lua_pushinteger(L, 0);
    return 1;
}

static int ComboBox_index(lua_State* L)
{
    MyGUI::ComboBox* cb = ComboBoxBinding::getComboBox(L, 1);
    if (!cb) return luaL_error(L, "ComboBox is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "itemCount") == 0 || strcmp(key, "count") == 0)
    {
        lua_pushinteger(L, (lua_Integer)cb->getItemCount());
        return 1;
    }
    if (strcmp(key, "indexSelected") == 0 || strcmp(key, "selectedIndex") == 0)
    {
        size_t idx = cb->getIndexSelected();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    if (strcmp(key, "comboModeDrop") == 0 || strcmp(key, "modeDrop") == 0)
    {
        lua_pushboolean(L, cb->getComboModeDrop() ? 1 : 0);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int ComboBox_newindex(lua_State* L)
{
    MyGUI::ComboBox* cb = ComboBoxBinding::getComboBox(L, 1);
    if (!cb) return luaL_error(L, "ComboBox is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "indexSelected") == 0 || strcmp(key, "selectedIndex") == 0)
    {
        lua_Integer idx = luaL_checkinteger(L, 3);
        if (idx < 0) cb->clearIndexSelected();
        else cb->setIndexSelected((size_t)idx);
        return 0;
    }
    if (strcmp(key, "comboModeDrop") == 0 || strcmp(key, "modeDrop") == 0)
    {
        cb->setComboModeDrop(lua_toboolean(L, 3) != 0);
        return 0;
    }
    return genericPropertyNewIndex(L);
}

static int ComboBox_tostring(lua_State* L)
{
    MyGUI::ComboBox* cb = ComboBoxBinding::getComboBox(L, 1);
    char buf[128];
    if (cb)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ComboBox('%s'):%p", cb->getName().c_str(), cb);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ComboBox(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void ComboBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", ComboBox_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getItemCount",        getItemCount },
        { "insertItemAt",        insertItemAt },
        { "addItem",             addItem },
        { "removeItemAt",        removeItemAt },
        { "removeAllItems",      removeAllItems },
        { "setItemNameAt",       setItemNameAt },
        { "getItemNameAt",       getItemNameAt },
        { "getIndexSelected",    getIndexSelected },
        { "setIndexSelected",    setIndexSelected },
        { "clearIndexSelected",  clearIndexSelected },
        { "findItemIndexWith",   findItemIndexWith },
        { "beginToItemAt",       beginToItemAt },
        { "beginToItemFirst",    beginToItemFirst },
        { "beginToItemLast",     beginToItemLast },
        { "beginToItemSelected", beginToItemSelected },
        { "setComboModeDrop",    setComboModeDrop },
        { "getComboModeDrop",    getComboModeDrop },
        { "setSmoothShow",       setSmoothShow },
        { "getSmoothShow",       getSmoothShow },
        { "setMaxListLength",    setMaxListLength },
        { "getMaxListLength",    getMaxListLength },
        { "setFlowDirection",    setFlowDirection },
        { "getFlowDirection",    getFlowDirection },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, ComboBox_index, ComboBox_newindex);
    setMetatableParent(L, getMetatableName(), EditBoxBinding::getMetatableName());
}

} // namespace KenshiLua
