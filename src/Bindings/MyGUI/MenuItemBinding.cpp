#include "pch.h"
#include "Bindings/MyGUI/MenuItemBinding.h"
#include "Bindings/MyGUI/MenuControlBinding.h"
#include "Bindings/MyGUI/ButtonBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::MenuItem* MenuItemBinding::getMenuItem(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::MenuItem>(false);
}

int MenuItemBinding::setItemName(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (mi) mi->setItemName(name);
    return 0;
}

int MenuItemBinding::getItemName(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    if (mi)
    {
        lua_pushstring(L, mi->getItemName().asUTF8().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int MenuItemBinding::setItemId(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    const char* id = luaL_checkstring(L, 2);
    if (mi) mi->setItemId(id);
    return 0;
}

int MenuItemBinding::getItemId(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    if (mi)
    {
        lua_pushstring(L, mi->getItemId().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int MenuItemBinding::setItemType(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    int type = (int)luaL_checkinteger(L, 2);
    if (mi) mi->setItemType(MyGUI::MenuItemType((MyGUI::MenuItemType::Enum)type));
    return 0;
}

int MenuItemBinding::getItemType(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    if (mi)
    {
        lua_pushinteger(L, (lua_Integer)mi->getItemType().getValue());
        return 1;
    }
    lua_pushinteger(L, 0);
    return 1;
}

int MenuItemBinding::setItemData(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    const char* data = luaL_checkstring(L, 2);
    if (mi) mi->setItemData(std::string(data));
    return 0;
}

int MenuItemBinding::clearItemData(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    if (mi) mi->setItemData(MyGUI::Any::Null);
    return 0;
}

int MenuItemBinding::getItemIndex(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    if (mi)
    {
        size_t idx = mi->getItemIndex();
        if (idx == MyGUI::ITEM_NONE) lua_pushinteger(L, -1);
        else lua_pushinteger(L, (lua_Integer)idx);
        return 1;
    }
    lua_pushinteger(L, -1);
    return 1;
}

int MenuItemBinding::createItemChild(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    if (mi)
    {
        MyGUI::MenuControl* child = mi->createItemChild();
        if (child) return MyGUIBindings::pushWidget(L, child);
    }
    lua_pushnil(L);
    return 1;
}

int MenuItemBinding::removeItemChild(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    if (mi && mi->getMenuCtrlParent())
    {
        mi->getMenuCtrlParent()->removeItemChild(mi);
    }
    return 0;
}

int MenuItemBinding::getItemChild(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    if (mi && mi->getItemChild())
    {
        return MyGUIBindings::pushWidget(L, mi->getItemChild());
    }
    lua_pushnil(L);
    return 1;
}

int MenuItemBinding::setItemChildVisible(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    bool visible = lua_toboolean(L, 2) != 0;
    if (mi) mi->setItemChildVisible(visible);
    return 0;
}

int MenuItemBinding::setItemChecked(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    bool chk = lua_toboolean(L, 2) != 0;
    if (mi) mi->setItemChecked(chk);
    return 0;
}

int MenuItemBinding::getItemChecked(lua_State* L)
{
    MyGUI::MenuItem* mi = getMenuItem(L, 1);
    if (mi) lua_pushboolean(L, mi->getItemChecked() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

static int MenuItem_index(lua_State* L)
{
    MyGUI::MenuItem* mi = MenuItemBinding::getMenuItem(L, 1);
    if (!mi) return luaL_error(L, "MenuItem is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "itemName") == 0)
    {
        lua_pushstring(L, mi->getItemName().asUTF8().c_str());
        return 1;
    }
    if (strcmp(key, "itemId") == 0)
    {
        lua_pushstring(L, mi->getItemId().c_str());
        return 1;
    }
    if (strcmp(key, "checked") == 0)
    {
        lua_pushboolean(L, mi->getItemChecked() ? 1 : 0);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int MenuItem_newindex(lua_State* L)
{
    MyGUI::MenuItem* mi = MenuItemBinding::getMenuItem(L, 1);
    if (!mi) return luaL_error(L, "MenuItem is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "itemName") == 0)
    {
        mi->setItemName(luaL_checkstring(L, 3));
        return 0;
    }
    if (strcmp(key, "itemId") == 0)
    {
        mi->setItemId(luaL_checkstring(L, 3));
        return 0;
    }
    if (strcmp(key, "checked") == 0)
    {
        mi->setItemChecked(lua_toboolean(L, 3) != 0);
        return 0;
    }
    return genericPropertyNewIndex(L);
}

static int MenuItem_tostring(lua_State* L)
{
    MyGUI::MenuItem* mi = MenuItemBinding::getMenuItem(L, 1);
    char buf[128];
    if (mi)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.MenuItem('%s'):%p", mi->getName().c_str(), mi);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.MenuItem(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void MenuItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", MenuItem_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setItemName",         setItemName },
        { "getItemName",         getItemName },
        { "setItemId",           setItemId },
        { "getItemId",           getItemId },
        { "setItemType",         setItemType },
        { "getItemType",         getItemType },
        { "setItemData",         setItemData },
        { "clearItemData",       clearItemData },
        { "getItemIndex",        getItemIndex },
        { "createItemChild",     createItemChild },
        { "removeItemChild",     removeItemChild },
        { "getItemChild",        getItemChild },
        { "setItemChildVisible", setItemChildVisible },
        { "setItemChecked",      setItemChecked },
        { "getItemChecked",      getItemChecked },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, MenuItem_index, MenuItem_newindex);
    setMetatableParent(L, getMetatableName(), ButtonBinding::getMetatableName());
}

} // namespace KenshiLua
