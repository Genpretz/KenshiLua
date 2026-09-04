#include "pch.h"
#include "Bindings/MyGUI/WindowBinding.h"
#include "Bindings/MyGUI/TextBoxBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/TypesBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::Window* WindowBinding::getWindow(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::Window>(false);
}

int WindowBinding::setVisibleSmooth(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    bool smooth = lua_toboolean(L, 2) != 0;
    if (win) win->setVisibleSmooth(smooth);
    return 0;
}

int WindowBinding::destroySmooth(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win)
    {
        MyGUIBindings::cleanupWidgetRecursive(win);
        win->destroySmooth();
    }
    return 0;
}

int WindowBinding::setAutoAlpha(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    bool autoAlpha = lua_toboolean(L, 2) != 0;
    if (win) win->setAutoAlpha(autoAlpha);
    return 0;
}

int WindowBinding::getAutoAlpha(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win) lua_pushboolean(L, win->getAutoAlpha() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WindowBinding::setSnap(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    bool snap = lua_toboolean(L, 2) != 0;
    if (win) win->setSnap(snap);
    return 0;
}

int WindowBinding::getSnap(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win) lua_pushboolean(L, win->getSnap() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WindowBinding::setMovable(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    bool m = lua_toboolean(L, 2) != 0;
    if (win) win->setMovable(m);
    return 0;
}

int WindowBinding::getMovable(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win) lua_pushboolean(L, win->getMovable() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int WindowBinding::setMinSize(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win)
    {
        if (lua_gettop(L) >= 3)
        {
            int w = (int)luaL_checkinteger(L, 2);
            int h = (int)luaL_checkinteger(L, 3);
            win->setMinSize(w, h);
        }
        else
        {
            MyGUI::IntSize sz = MyGUIBindings::readIntSize(L, 2);
            win->setMinSize(sz);
        }
    }
    return 0;
}

int WindowBinding::getMinSize(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win)
    {
        MyGUI::IntSize s = win->getMinSize();
        lua_pushinteger(L, s.width);
        lua_pushinteger(L, s.height);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int WindowBinding::setMaxSize(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win)
    {
        if (lua_gettop(L) >= 3)
        {
            int w = (int)luaL_checkinteger(L, 2);
            int h = (int)luaL_checkinteger(L, 3);
            win->setMaxSize(w, h);
        }
        else
        {
            MyGUI::IntSize sz = MyGUIBindings::readIntSize(L, 2);
            win->setMaxSize(sz);
        }
    }
    return 0;
}

int WindowBinding::getMaxSize(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win)
    {
        MyGUI::IntSize s = win->getMaxSize();
        lua_pushinteger(L, s.width);
        lua_pushinteger(L, s.height);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int WindowBinding::getActionScale(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win)
    {
        const MyGUI::IntCoord& c = win->getActionScale();
        return pushValue<MyGUI::IntCoord>(L, c, IntCoordBinding::getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

int WindowBinding::getCaptionWidget(lua_State* L)
{
    MyGUI::Window* win = getWindow(L, 1);
    if (win && win->getCaptionWidget())
    {
        return MyGUIBindings::pushWidget(L, win->getCaptionWidget());
    }
    lua_pushnil(L);
    return 1;
}

static int Window_index(lua_State* L)
{
    MyGUI::Window* win = WindowBinding::getWindow(L, 1);
    if (!win) return luaL_error(L, "Window is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "movable") == 0)
    {
        lua_pushboolean(L, win->getMovable() ? 1 : 0);
        return 1;
    }
    if (strcmp(key, "autoAlpha") == 0)
    {
        lua_pushboolean(L, win->getAutoAlpha() ? 1 : 0);
        return 1;
    }
    if (strcmp(key, "snap") == 0)
    {
        lua_pushboolean(L, win->getSnap() ? 1 : 0);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int Window_newindex(lua_State* L)
{
    MyGUI::Window* win = WindowBinding::getWindow(L, 1);
    if (!win) return luaL_error(L, "Window is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "movable") == 0)
    {
        win->setMovable(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "autoAlpha") == 0)
    {
        win->setAutoAlpha(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "snap") == 0)
    {
        win->setSnap(lua_toboolean(L, 3) != 0);
        return 0;
    }
    return genericPropertyNewIndex(L);
}

static int Window_tostring(lua_State* L)
{
    MyGUI::Window* win = WindowBinding::getWindow(L, 1);
    char buf[128];
    if (win)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.Window('%s'):%p", win->getName().c_str(), win);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.Window(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void WindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", Window_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setVisibleSmooth", setVisibleSmooth },
        { "destroySmooth",    destroySmooth },
        { "setAutoAlpha",     setAutoAlpha },
        { "getAutoAlpha",     getAutoAlpha },
        { "setSnap",          setSnap },
        { "getSnap",          getSnap },
        { "setMovable",       setMovable },
        { "getMovable",       getMovable },
        { "setMinSize",       setMinSize },
        { "getMinSize",       getMinSize },
        { "setMaxSize",       setMaxSize },
        { "getMaxSize",       getMaxSize },
        { "getActionScale",   getActionScale },
        { "getCaptionWidget", getCaptionWidget },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, Window_index, Window_newindex);
    setMetatableParent(L, getMetatableName(), TextBoxBinding::getMetatableName());
}

} // namespace KenshiLua
