#include "pch.h"
#include "Bindings/MyGUI/ScrollViewBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::ScrollView* ScrollViewBinding::getScrollView(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::ScrollView>(false);
}

int ScrollViewBinding::setVisibleHScroll(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    bool v = lua_toboolean(L, 2) != 0;
    if (sv) sv->setVisibleHScroll(v);
    return 0;
}

int ScrollViewBinding::isVisibleHScroll(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    if (sv) lua_pushboolean(L, sv->isVisibleHScroll() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ScrollViewBinding::setVisibleVScroll(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    bool v = lua_toboolean(L, 2) != 0;
    if (sv) sv->setVisibleVScroll(v);
    return 0;
}

int ScrollViewBinding::isVisibleVScroll(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    if (sv) lua_pushboolean(L, sv->isVisibleVScroll() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ScrollViewBinding::setCanvasAlign(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    int a = (int)luaL_checkinteger(L, 2);
    if (sv) sv->setCanvasAlign(MyGUI::Align((MyGUI::Align::Enum)a));
    return 0;
}

int ScrollViewBinding::getCanvasAlign(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    if (sv) lua_pushinteger(L, (lua_Integer)sv->getCanvasAlign().getValue());
    else lua_pushinteger(L, 0);
    return 1;
}

int ScrollViewBinding::setCanvasSize(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    if (sv)
    {
        if (lua_gettop(L) >= 3)
        {
            int w = (int)luaL_checkinteger(L, 2);
            int h = (int)luaL_checkinteger(L, 3);
            sv->setCanvasSize(w, h);
        }
        else
        {
            MyGUI::IntSize sz = MyGUIBindings::readIntSize(L, 2);
            sv->setCanvasSize(sz);
        }
    }
    return 0;
}

int ScrollViewBinding::getCanvasSize(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    if (sv)
    {
        MyGUI::IntSize s = sv->getCanvasSize();
        lua_pushinteger(L, s.width);
        lua_pushinteger(L, s.height);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int ScrollViewBinding::setViewOffset(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    if (sv)
    {
        if (lua_gettop(L) >= 3)
        {
            int x = (int)luaL_checkinteger(L, 2);
            int y = (int)luaL_checkinteger(L, 3);
            sv->setViewOffset(MyGUI::IntPoint(x, y));
        }
        else
        {
            MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 2);
            sv->setViewOffset(pt);
        }
    }
    return 0;
}

int ScrollViewBinding::getViewOffset(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    if (sv)
    {
        MyGUI::IntPoint p = sv->getViewOffset();
        lua_pushinteger(L, p.left);
        lua_pushinteger(L, p.top);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int ScrollViewBinding::getViewCoord(lua_State* L)
{
    MyGUI::ScrollView* sv = getScrollView(L, 1);
    if (sv)
    {
        MyGUI::IntCoord c = sv->getViewCoord();
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

static int ScrollView_tostring(lua_State* L)
{
    MyGUI::ScrollView* sv = ScrollViewBinding::getScrollView(L, 1);
    char buf[128];
    if (sv)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ScrollView('%s'):%p", sv->getName().c_str(), sv);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ScrollView(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void ScrollViewBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", ScrollView_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setVisibleHScroll", setVisibleHScroll },
        { "isVisibleHScroll",  isVisibleHScroll },
        { "setVisibleVScroll", setVisibleVScroll },
        { "isVisibleVScroll",  isVisibleVScroll },
        { "setCanvasAlign",    setCanvasAlign },
        { "getCanvasAlign",    getCanvasAlign },
        { "setCanvasSize",     setCanvasSize },
        { "getCanvasSize",     getCanvasSize },
        { "setViewOffset",     setViewOffset },
        { "getViewOffset",     getViewOffset },
        { "getViewCoord",      getViewCoord },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
