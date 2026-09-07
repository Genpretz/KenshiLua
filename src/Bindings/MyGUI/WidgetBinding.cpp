#include "pch.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/MyGuiCallbacks.h"
#include "Bindings/MyGUI/TypesBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::Widget* WidgetBinding::getWidget(lua_State* L, int idx)
{
    return testObject<MyGUI::Widget>(L, idx, WidgetBinding::getMetatableName());
}

int WidgetBinding::setPosition(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        if (lua_gettop(L) >= 3)
        {
            int x = (int)luaL_checkinteger(L, 2);
            int y = (int)luaL_checkinteger(L, 3);
            w->setPosition(x, y);
        }
        else
        {
            MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 2);
            w->setPosition(pt);
        }
    }
    return 0;
}

int WidgetBinding::getPosition(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntPoint p = w->getPosition();
        lua_pushinteger(L, p.left);
        lua_pushinteger(L, p.top);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int WidgetBinding::setSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        if (lua_gettop(L) >= 3)
        {
            int width = (int)luaL_checkinteger(L, 2);
            int height = (int)luaL_checkinteger(L, 3);
            w->setSize(width, height);
        }
        else
        {
            MyGUI::IntSize sz = MyGUIBindings::readIntSize(L, 2);
            w->setSize(sz);
        }
    }
    return 0;
}

int WidgetBinding::getSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntSize s = w->getSize();
        lua_pushinteger(L, s.width);
        lua_pushinteger(L, s.height);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int WidgetBinding::setCoord(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        if (lua_gettop(L) >= 5)
        {
            int left = (int)luaL_checkinteger(L, 2);
            int top = (int)luaL_checkinteger(L, 3);
            int width = (int)luaL_checkinteger(L, 4);
            int height = (int)luaL_checkinteger(L, 5);
            w->setCoord(left, top, width, height);
        }
        else
        {
            MyGUI::IntCoord c = MyGUIBindings::readIntCoord(L, 2);
            w->setCoord(c);
        }
    }
    return 0;
}

int WidgetBinding::getCoord(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntCoord c = w->getCoord();
        lua_pushinteger(L, c.left);
        lua_pushinteger(L, c.top);
        lua_pushinteger(L, c.width);
        lua_pushinteger(L, c.height);
        return 4;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 4;
}

int WidgetBinding::setRealPosition(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        float left = (float)luaL_checknumber(L, 2);
        float top = (float)luaL_checknumber(L, 3);
        w->setRealPosition(left, top);
    }
    return 0;
}

int WidgetBinding::getRealPosition(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w && w->getParent())
    {
        MyGUI::IntSize pSize = w->getParentSize();
        if (pSize.width > 0 && pSize.height > 0)
        {
            MyGUI::IntPoint pos = w->getPosition();
            lua_pushnumber(L, (float)pos.left / (float)pSize.width);
            lua_pushnumber(L, (float)pos.top / (float)pSize.height);
            return 2;
        }
    }
    lua_pushnumber(L, 0.0);
    lua_pushnumber(L, 0.0);
    return 2;
}

int WidgetBinding::setRealSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        float width = (float)luaL_checknumber(L, 2);
        float height = (float)luaL_checknumber(L, 3);
        w->setRealSize(width, height);
    }
    return 0;
}

int WidgetBinding::getRealSize(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w && w->getParent())
    {
        MyGUI::IntSize pSize = w->getParentSize();
        if (pSize.width > 0 && pSize.height > 0)
        {
            MyGUI::IntSize sz = w->getSize();
            lua_pushnumber(L, (float)sz.width / (float)pSize.width);
            lua_pushnumber(L, (float)sz.height / (float)pSize.height);
            return 2;
        }
    }
    lua_pushnumber(L, 0.0);
    lua_pushnumber(L, 0.0);
    return 2;
}

int WidgetBinding::setRealCoord(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        float left = (float)luaL_checknumber(L, 2);
        float top = (float)luaL_checknumber(L, 3);
        float width = (float)luaL_checknumber(L, 4);
        float height = (float)luaL_checknumber(L, 5);
        w->setRealCoord(left, top, width, height);
    }
    return 0;
}

int WidgetBinding::getRealCoord(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w && w->getParent())
    {
        MyGUI::IntSize pSize = w->getParentSize();
        if (pSize.width > 0 && pSize.height > 0)
        {
            MyGUI::IntCoord c = w->getCoord();
            lua_pushnumber(L, (float)c.left / (float)pSize.width);
            lua_pushnumber(L, (float)c.top / (float)pSize.height);
            lua_pushnumber(L, (float)c.width / (float)pSize.width);
            lua_pushnumber(L, (float)c.height / (float)pSize.height);
            return 4;
        }
    }
    lua_pushnumber(L, 0.0);
    lua_pushnumber(L, 0.0);
    lua_pushnumber(L, 0.0);
    lua_pushnumber(L, 0.0);
    return 4;
}

int WidgetBinding::setVisible(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool v = lua_toboolean(L, 2) != 0;
    if (w) w->setVisible(v);
    return 0;
}

int WidgetBinding::getVisible(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushboolean(L, w->getVisible() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WidgetBinding::getInheritedVisible(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushboolean(L, w->getInheritedVisible() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WidgetBinding::setAlign(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int a = (int)luaL_checkinteger(L, 2);
    if (w) w->setAlign(MyGUI::Align((MyGUI::Align::Enum)a));
    return 0;
}

int WidgetBinding::getAlign(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushinteger(L, (lua_Integer)w->getAlign().getValue());
    else lua_pushinteger(L, 0);
    return 1;
}

int WidgetBinding::setAlpha(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    float alpha = (float)luaL_checknumber(L, 2);
    if (w) w->setAlpha(alpha);
    return 0;
}

int WidgetBinding::getAlpha(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushnumber(L, w->getAlpha());
    else lua_pushnumber(L, 1.0);
    return 1;
}

int WidgetBinding::setInheritsAlpha(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool val = lua_toboolean(L, 2) != 0;
    if (w) w->setInheritsAlpha(val);
    return 0;
}

int WidgetBinding::getInheritsAlpha(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushboolean(L, w->getInheritsAlpha() ? 1 : 0);
    else lua_pushboolean(L, 1);
    return 1;
}

int WidgetBinding::setColour(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::Colour col = MyGUIBindings::readColour(L, 2);
        w->setColour(col);
    }
    return 0;
}

int WidgetBinding::setDepth(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int depth = (int)luaL_checkinteger(L, 2);
    if (w) w->setDepth(depth);
    return 0;
}

int WidgetBinding::getDepth(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushinteger(L, w->getDepth());
    else lua_pushinteger(L, 0);
    return 1;
}

int WidgetBinding::setEnabled(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool e = lua_toboolean(L, 2) != 0;
    if (w) w->setEnabled(e);
    return 0;
}

int WidgetBinding::getEnabled(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushboolean(L, w->getEnabled() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WidgetBinding::getInheritedEnabled(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushboolean(L, w->getInheritedEnabled() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WidgetBinding::setCaption(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* text = luaL_checkstring(L, 2);
    if (w)
    {
        if (MyGUI::TextBox* tb = w->castType<MyGUI::TextBox>(false))
            tb->setCaption(text);
        else if (MyGUI::Window* win = w->castType<MyGUI::Window>(false))
            win->setCaption(text);
        else if (MyGUI::Button* btn = w->castType<MyGUI::Button>(false))
            btn->setCaption(text);
        else
            w->setProperty("Caption", text);
    }
    return 0;
}

int WidgetBinding::getCaption(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        if (MyGUI::TextBox* tb = w->castType<MyGUI::TextBox>(false))
        {
            lua_pushstring(L, tb->getCaption().asUTF8().c_str());
            return 1;
        }
        if (MyGUI::Window* win = w->castType<MyGUI::Window>(false))
        {
            lua_pushstring(L, win->getCaption().asUTF8().c_str());
            return 1;
        }
        if (MyGUI::Button* btn = w->castType<MyGUI::Button>(false))
        {
            lua_pushstring(L, btn->getCaption().asUTF8().c_str());
            return 1;
        }
    }
    lua_pushstring(L, "");
    return 1;
}

int WidgetBinding::setWidgetStyle(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    int style = (int)luaL_checkinteger(L, 2);
    const char* layer = luaL_optstring(L, 3, "");
    if (w) w->setWidgetStyle(MyGUI::WidgetStyle((MyGUI::WidgetStyle::Enum)style), layer);
    return 0;
}

int WidgetBinding::getWidgetStyle(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushinteger(L, (lua_Integer)w->getWidgetStyle().getValue());
    else lua_pushinteger(L, 0);
    return 1;
}

int WidgetBinding::setNeedKeyFocus(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool val = lua_toboolean(L, 2) != 0;
    if (w) w->setNeedKeyFocus(val);
    return 0;
}

int WidgetBinding::getNeedKeyFocus(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushboolean(L, w->getNeedKeyFocus() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WidgetBinding::setNeedMouseFocus(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool val = lua_toboolean(L, 2) != 0;
    if (w) w->setNeedMouseFocus(val);
    return 0;
}

int WidgetBinding::getNeedMouseFocus(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushboolean(L, w->getNeedMouseFocus() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WidgetBinding::setInheritsPick(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    bool val = lua_toboolean(L, 2) != 0;
    if (w) w->setInheritsPick(val);
    return 0;
}

int WidgetBinding::getInheritsPick(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushboolean(L, w->getInheritsPick() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WidgetBinding::setMaskPick(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* filename = luaL_checkstring(L, 2);
    if (w) w->setMaskPick(filename);
    return 0;
}

int WidgetBinding::setPointer(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* pointer = luaL_checkstring(L, 2);
    if (w) w->setPointer(pointer);
    return 0;
}

int WidgetBinding::getPointer(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        lua_pushstring(L, w->getPointer().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int WidgetBinding::setUserString(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* key = luaL_checkstring(L, 2);
    const char* val = luaL_checkstring(L, 3);
    if (w) w->setUserString(key, val);
    return 0;
}

int WidgetBinding::getUserString(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* key = luaL_checkstring(L, 2);
    if (w)
    {
        lua_pushstring(L, w->getUserString(key).c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int WidgetBinding::isUserString(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* key = luaL_checkstring(L, 2);
    if (w) lua_pushboolean(L, w->isUserString(key) ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WidgetBinding::clearUserString(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* key = luaL_checkstring(L, 2);
    if (w) w->clearUserString(key);
    return 0;
}

int WidgetBinding::createWidget(lua_State* L)
{
    MyGUI::Widget* parent = getWidget(L, 1);
    if (!parent) return luaL_error(L, "Parent widget is nil");

    const char* type = luaL_checkstring(L, 2);
    const char* skin = luaL_checkstring(L, 3);
    int left = (int)luaL_checkinteger(L, 4);
    int top = (int)luaL_checkinteger(L, 5);
    int width = (int)luaL_checkinteger(L, 6);
    int height = (int)luaL_checkinteger(L, 7);
    int align = (int)MyGUI::Align::Default;
    const char* name = "";
    if (lua_gettop(L) >= 8)
    {
        if (lua_type(L, 8) == LUA_TNUMBER)
        {
            align = (int)lua_tointeger(L, 8);
            name = luaL_optstring(L, 9, "");
        }
        else if (lua_isstring(L, 8))
        {
            name = lua_tostring(L, 8);
        }
    }

    MyGUIBindings::validateWidgetSkin(type, skin);
    MyGUI::Widget* child = parent->createWidgetT(type, skin, left, top, width, height, MyGUI::Align((MyGUI::Align::Enum)align), name);
    if (child)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, child, parent);
        return MyGUIBindings::pushWidget(L, child);
    }
    lua_pushnil(L);
    return 1;
}

int WidgetBinding::createWidgetReal(lua_State* L)
{
    MyGUI::Widget* parent = getWidget(L, 1);
    if (!parent) return luaL_error(L, "Parent widget is nil");

    const char* type = luaL_checkstring(L, 2);
    const char* skin = luaL_checkstring(L, 3);
    float left = (float)luaL_checknumber(L, 4);
    float top = (float)luaL_checknumber(L, 5);
    float width = (float)luaL_checknumber(L, 6);
    float height = (float)luaL_checknumber(L, 7);
    int align = (int)MyGUI::Align::Default;
    const char* name = "";
    if (lua_gettop(L) >= 8)
    {
        if (lua_type(L, 8) == LUA_TNUMBER)
        {
            align = (int)lua_tointeger(L, 8);
            name = luaL_optstring(L, 9, "");
        }
        else if (lua_isstring(L, 8))
        {
            name = lua_tostring(L, 8);
        }
    }

    MyGUIBindings::validateWidgetSkin(type, skin);
    MyGUI::Widget* child = parent->createWidgetRealT(type, skin, left, top, width, height, MyGUI::Align((MyGUI::Align::Enum)align), name);
    if (child)
    {
        MyGUIBindings::trackLuaCreatedWidget(L, child, parent);
        return MyGUIBindings::pushWidget(L, child);
    }
    lua_pushnil(L);
    return 1;
}

int WidgetBinding::getParent(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w && w->getParent())
    {
        return MyGUIBindings::pushWidget(L, w->getParent());
    }
    lua_pushnil(L);
    return 1;
}

int WidgetBinding::getRootWidget(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w && !w->isRootWidget())
    {
        MyGUI::Widget* cur = w;
        while (cur->getParent())
        {
            cur = cur->getParent();
        }
        return MyGUIBindings::pushWidget(L, cur);
    }
    else if (w)
    {
        return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

int WidgetBinding::isRootWidget(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushboolean(L, w->isRootWidget() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WidgetBinding::getChildCount(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w) lua_pushinteger(L, w->getChildCount());
    else lua_pushinteger(L, 0);
    return 1;
}

int WidgetBinding::getChildAt(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    size_t idx = (size_t)luaL_checkinteger(L, 2);
    if (w && idx < w->getChildCount())
    {
        return MyGUIBindings::pushWidget(L, w->getChildAt(idx));
    }
    lua_pushnil(L);
    return 1;
}

int WidgetBinding::findWidget(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (w)
    {
        MyGUI::Widget* found = w->findWidget(name);
        if (found) return MyGUIBindings::pushWidget(L, found);
    }
    lua_pushnil(L);
    return 1;
}

int WidgetBinding::getClientWidget(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        if (MyGUI::Window* win = w->castType<MyGUI::Window>(false))
        {
            MyGUI::Widget* client = win->getClientWidget();
            if (client) return MyGUIBindings::pushWidget(L, client);
        }
    }
    lua_pushnil(L);
    return 1;
}

int WidgetBinding::getClientCoord(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntCoord c = w->getClientCoord();
        lua_pushinteger(L, c.left);
        lua_pushinteger(L, c.top);
        lua_pushinteger(L, c.width);
        lua_pushinteger(L, c.height);
        return 4;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 4;
}

int WidgetBinding::getType(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        lua_pushstring(L, w->getTypeName().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int WidgetBinding::getName(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        lua_pushstring(L, w->getName().c_str());
        return 1;
    }
    lua_pushstring(L, "");
    return 1;
}

int WidgetBinding::getLayerName(lua_State* L)
{
    lua_pushstring(L, "");
    return 1;
}

int WidgetBinding::getAbsoluteCoord(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntCoord c = w->getAbsoluteCoord();
        lua_pushinteger(L, c.left);
        lua_pushinteger(L, c.top);
        lua_pushinteger(L, c.width);
        lua_pushinteger(L, c.height);
        return 4;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 4;
}

int WidgetBinding::getAbsolutePosition(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntPoint p = w->getAbsolutePosition();
        lua_pushinteger(L, p.left);
        lua_pushinteger(L, p.top);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int WidgetBinding::getAbsoluteRect(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUI::IntRect r = w->getAbsoluteRect();
        lua_pushinteger(L, r.left);
        lua_pushinteger(L, r.top);
        lua_pushinteger(L, r.right);
        lua_pushinteger(L, r.bottom);
        return 4;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 4;
}

int WidgetBinding::changeWidgetSkin(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* skin = luaL_checkstring(L, 2);
    if (w) w->changeWidgetSkin(skin);
    return 0;
}

int WidgetBinding::setProperty(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    const char* k = luaL_checkstring(L, 2);
    const char* v = luaL_checkstring(L, 3);
    if (w) w->setProperty(k, v);
    return 0;
}

int WidgetBinding::destroy(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w)
    {
        MyGUIBindings::cleanupWidgetRecursive(w);
        try
        {
            if (MyGUI::Gui::getInstancePtr())
            {
                MyGUI::Gui::getInstance().destroyWidget(w);
            }
        }
        catch (...)
        {
        }
    }
    return 0;
}

int WidgetBinding::registerCallback(lua_State* L)
{
    return MyGUIBindings::widget_registerCallback(L);
}

int WidgetBinding::upLayerItem(lua_State* L)
{
    MyGUI::Widget* w = getWidget(L, 1);
    if (w && MyGUI::LayerManager::getInstancePtr())
    {
        MyGUI::LayerManager::getInstance().upLayerItem(w);
    }
    return 0;
}

static int widget_index(lua_State* L)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
    if (!w) return luaL_error(L, "Widget is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "caption") == 0 || strcmp(key, "text") == 0)
    {
        return WidgetBinding::getCaption(L);
    }
    if (strcmp(key, "visible") == 0)
    {
        lua_pushboolean(L, w->getVisible() ? 1 : 0);
        return 1;
    }
    if (strcmp(key, "enabled") == 0)
    {
        lua_pushboolean(L, w->getEnabled() ? 1 : 0);
        return 1;
    }
    if (strcmp(key, "alpha") == 0)
    {
        lua_pushnumber(L, w->getAlpha());
        return 1;
    }
    if (strcmp(key, "name") == 0)
    {
        lua_pushstring(L, w->getName().c_str());
        return 1;
    }
    if (strcmp(key, "type") == 0)
    {
        lua_pushstring(L, w->getTypeName().c_str());
        return 1;
    }

    return genericPropertyIndex(L);
}

static int widget_newindex(lua_State* L)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
    if (!w) return luaL_error(L, "Widget is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "caption") == 0 || strcmp(key, "text") == 0)
    {
        const char* val = luaL_checkstring(L, 3);
        if (MyGUI::TextBox* tb = w->castType<MyGUI::TextBox>(false))
            tb->setCaption(val);
        else if (MyGUI::Window* win = w->castType<MyGUI::Window>(false))
            win->setCaption(val);
        else if (MyGUI::Button* btn = w->castType<MyGUI::Button>(false))
            btn->setCaption(val);
        else
            w->setProperty("Caption", val);
        return 0;
    }
    if (strcmp(key, "visible") == 0)
    {
        w->setVisible(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "enabled") == 0)
    {
        w->setEnabled(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "alpha") == 0)
    {
        w->setAlpha((float)luaL_checknumber(L, 3));
        return 0;
    }

    return genericPropertyNewIndex(L);
}

static int widget_tostring(lua_State* L)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
    char buf[128];
    if (w)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.%s('%s'):%p", w->getTypeName().c_str(), w->getName().c_str(), w);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.Widget(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void WidgetBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", widget_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setPosition",          setPosition },
        { "getPosition",          getPosition },
        { "setSize",              setSize },
        { "getSize",              getSize },
        { "setCoord",             setCoord },
        { "getCoord",             getCoord },
        { "setRealPosition",      setRealPosition },
        { "getRealPosition",      getRealPosition },
        { "setRealSize",          setRealSize },
        { "getRealSize",          getRealSize },
        { "setRealCoord",         setRealCoord },
        { "getRealCoord",         getRealCoord },
        { "setCoordReal",         setRealCoord },
        { "getCoordReal",         getRealCoord },
        { "setVisible",           setVisible },
        { "getVisible",           getVisible },
        { "getInheritedVisible",  getInheritedVisible },
        { "setAlign",             setAlign },
        { "getAlign",             getAlign },
        { "setAlpha",             setAlpha },
        { "getAlpha",             getAlpha },
        { "setInheritsAlpha",     setInheritsAlpha },
        { "getInheritsAlpha",     getInheritsAlpha },
        { "setColour",            setColour },
        { "setDepth",             setDepth },
        { "getDepth",             getDepth },
        { "setEnabled",           setEnabled },
        { "getEnabled",           getEnabled },
        { "getInheritedEnabled",  getInheritedEnabled },
        { "setCaption",           setCaption },
        { "getCaption",           getCaption },
        { "setWidgetStyle",       setWidgetStyle },
        { "getWidgetStyle",       getWidgetStyle },
        { "setNeedKeyFocus",      setNeedKeyFocus },
        { "getNeedKeyFocus",      getNeedKeyFocus },
        { "setNeedMouseFocus",    setNeedMouseFocus },
        { "getNeedMouseFocus",    getNeedMouseFocus },
        { "setInheritsPick",      setInheritsPick },
        { "getInheritsPick",      getInheritsPick },
        { "setMaskPick",          setMaskPick },
        { "setPointer",           setPointer },
        { "getPointer",           getPointer },
        { "setUserString",        setUserString },
        { "getUserString",        getUserString },
        { "isUserString",         isUserString },
        { "clearUserString",      clearUserString },
        { "createWidget",         createWidget },
        { "createWidgetReal",     createWidgetReal },
        { "getParent",            getParent },
        { "getRootWidget",        getRootWidget },
        { "isRootWidget",         isRootWidget },
        { "getChildCount",        getChildCount },
        { "getChildAt",           getChildAt },
        { "findWidget",           findWidget },
        { "getClientWidget",      getClientWidget },
        { "getClientCoord",       getClientCoord },
        { "getType",              getType },
        { "getName",              getName },
        { "getLayerName",         getLayerName },
        { "getAbsoluteCoord",     getAbsoluteCoord },
        { "getAbsolutePosition",  getAbsolutePosition },
        { "getAbsoluteRect",      getAbsoluteRect },
        { "changeWidgetSkin",     changeWidgetSkin },
        { "setProperty",          setProperty },
        { "destroy",              destroy },
        { "registerCallback",     registerCallback },
        { "upLayerItem",          upLayerItem },
        { "bringToFront",         upLayerItem },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, widget_index, widget_newindex);
}

} // namespace KenshiLua
