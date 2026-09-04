#include "pch.h"
#include "Bindings/MyGUI/MenuControlBinding.h"
#include "Bindings/MyGUI/MenuItemBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::MenuControl* MenuControlBinding::getMenuControl(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::MenuControl>(false);
}

int MenuControlBinding::getItemCount(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    if (mc) lua_pushinteger(L, (lua_Integer)mc->getItemCount());
    else lua_pushinteger(L, 0);
    return 1;
}

int MenuControlBinding::insertItemAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    int type = (int)luaL_optinteger(L, 4, (int)MyGUI::MenuItemType::Normal);
    const char* id = luaL_optstring(L, 5, "");

    if (mc)
    {
        MyGUI::MenuItem* item = mc->insertItemAt(idx, name, MyGUI::MenuItemType((MyGUI::MenuItemType::Enum)type), id);
        if (item) return MyGUIBindings::pushWidget(L, item);
    }
    lua_pushnil(L);
    return 1;
}

int MenuControlBinding::addItem(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    const char* name = luaL_checkstring(L, 2);
    int type = (int)luaL_optinteger(L, 3, (int)MyGUI::MenuItemType::Normal);
    const char* id = luaL_optstring(L, 4, "");

    if (mc)
    {
        MyGUI::MenuItem* item = mc->addItem(name, MyGUI::MenuItemType((MyGUI::MenuItemType::Enum)type), id);
        if (item) return MyGUIBindings::pushWidget(L, item);
    }
    lua_pushnil(L);
    return 1;
}

int MenuControlBinding::removeItemAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (mc) mc->removeItemAt(idx);
    return 0;
}

int MenuControlBinding::removeAllItems(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    if (mc) mc->removeAllItems();
    return 0;
}

int MenuControlBinding::getItemNameAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (mc && idx < mc->getItemCount())
    {
        lua_pushstring(L, mc->getItemNameAt(idx).asUTF8().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int MenuControlBinding::setItemNameAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* name = luaL_checkstring(L, 3);
    if (mc && idx < mc->getItemCount())
    {
        mc->setItemNameAt(idx, name);
    }
    return 0;
}

int MenuControlBinding::getItemIdAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (mc && idx < mc->getItemCount())
    {
        lua_pushstring(L, mc->getItemIdAt(idx).c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int MenuControlBinding::setItemIdAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* id = luaL_checkstring(L, 3);
    if (mc && idx < mc->getItemCount())
    {
        mc->setItemIdAt(idx, id);
    }
    return 0;
}

int MenuControlBinding::getItemAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (mc && idx < mc->getItemCount())
    {
        MyGUI::MenuItem* item = mc->getItemAt(idx);
        if (item) return MyGUIBindings::pushWidget(L, item);
    }
    lua_pushnil(L);
    return 1;
}

int MenuControlBinding::getItemById(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    const char* id = luaL_checkstring(L, 2);
    if (mc)
    {
        MyGUI::MenuItem* item = mc->getItemById(id);
        if (item) return MyGUIBindings::pushWidget(L, item);
    }
    lua_pushnil(L);
    return 1;
}

int MenuControlBinding::getItemIndex(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    MyGUI::MenuItem* item = MenuItemBinding::getMenuItem(L, 2);
    if (mc && item)
    {
        size_t idx = mc->getItemIndex(item);
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int MenuControlBinding::getItemIndexById(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    const char* id = luaL_checkstring(L, 2);
    if (mc)
    {
        size_t idx = mc->getItemIndexById(id);
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int MenuControlBinding::findItemIndexWith(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (mc)
    {
        size_t idx = mc->findItemIndexWith(name);
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int MenuControlBinding::setItemDataAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    const char* data = luaL_checkstring(L, 3);
    if (mc && idx < mc->getItemCount())
    {
        mc->setItemDataAt(idx, std::string(data));
    }
    return 0;
}

int MenuControlBinding::clearItemDataAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (mc && idx < mc->getItemCount())
    {
        mc->clearItemDataAt(idx);
    }
    return 0;
}

int MenuControlBinding::setItemTypeAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    int type = (int)luaL_checkinteger(L, 3);
    if (mc && idx < mc->getItemCount())
    {
        mc->setItemTypeAt(idx, MyGUI::MenuItemType((MyGUI::MenuItemType::Enum)type));
    }
    return 0;
}

int MenuControlBinding::getItemTypeAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (mc && idx < mc->getItemCount())
    {
        lua_pushinteger(L, (lua_Integer)mc->getItemTypeAt(idx).getValue());
        return 1;
    }
    lua_pushinteger(L, 0);
    return 1;
}

int MenuControlBinding::setItemChildVisibleAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    bool visible = lua_toboolean(L, 3) != 0;
    if (mc && idx < mc->getItemCount())
    {
        mc->setItemChildVisibleAt(idx, visible);
    }
    return 0;
}

int MenuControlBinding::createItemChildAt(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (mc && idx < mc->getItemCount())
    {
        MyGUI::MenuControl* child = mc->createItemChildAt(idx);
        if (child) return MyGUIBindings::pushWidget(L, child);
    }
    lua_pushnil(L);
    return 1;
}

int MenuControlBinding::setPopupAccept(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    bool mode = lua_toboolean(L, 2) != 0;
    if (mc) mc->setPopupAccept(mode);
    return 0;
}

int MenuControlBinding::getPopupAccept(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    if (mc) lua_pushboolean(L, mc->getPopupAccept() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int MenuControlBinding::setVerticalAlignment(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    bool vert = lua_toboolean(L, 2) != 0;
    if (mc) mc->setVerticalAlignment(vert);
    return 0;
}

int MenuControlBinding::getVerticalAlignment(lua_State* L)
{
    MyGUI::MenuControl* mc = getMenuControl(L, 1);
    if (mc) lua_pushboolean(L, mc->getVerticalAlignment() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

static int MenuControl_tostring(lua_State* L)
{
    MyGUI::MenuControl* mc = MenuControlBinding::getMenuControl(L, 1);
    char buf[128];
    if (mc)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.MenuControl('%s'):%p", mc->getName().c_str(), mc);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.MenuControl(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void MenuControlBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", MenuControl_tostring },
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
        { "getItemIdAt",            getItemIdAt },
        { "setItemIdAt",            setItemIdAt },
        { "getItemAt",              getItemAt },
        { "getItemById",            getItemById },
        { "getItemIndex",           getItemIndex },
        { "getItemIndexById",       getItemIndexById },
        { "findItemIndexWith",      findItemIndexWith },
        { "setItemDataAt",          setItemDataAt },
        { "clearItemDataAt",        clearItemDataAt },
        { "setItemTypeAt",          setItemTypeAt },
        { "getItemTypeAt",          getItemTypeAt },
        { "setItemChildVisibleAt",  setItemChildVisibleAt },
        { "createItemChildAt",      createItemChildAt },
        { "setPopupAccept",         setPopupAccept },
        { "getPopupAccept",         getPopupAccept },
        { "setPopupMode",           setPopupAccept }, // alias
        { "getPopupMode",           getPopupAccept }, // alias
        { "setVerticalAlignment",   setVerticalAlignment },
        { "getVerticalAlignment",   getVerticalAlignment },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
