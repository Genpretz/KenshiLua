#include "pch.h"
#include "Bindings/MyGUI/ScrollBarBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::ScrollBar* ScrollBarBinding::getScrollBar(lua_State* L, int idx)
{
    return MyGUIBindings::checkWidget<MyGUI::ScrollBar>(L, idx);
}

int ScrollBarBinding::setScrollRange(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    size_t range = (size_t)luaL_checkinteger(L, 2);
    if (sb) sb->setScrollRange(range);
    return 0;
}

int ScrollBarBinding::getScrollRange(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushinteger(L, (lua_Integer)sb->getScrollRange());
    else lua_pushinteger(L, 0);
    return 1;
}

int ScrollBarBinding::setScrollPosition(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    size_t pos = (size_t)luaL_checkinteger(L, 2);
    if (sb) sb->setScrollPosition(pos);
    return 0;
}

int ScrollBarBinding::getScrollPosition(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushinteger(L, (lua_Integer)sb->getScrollPosition());
    else lua_pushinteger(L, 0);
    return 1;
}

int ScrollBarBinding::setScrollPage(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    size_t page = (size_t)luaL_checkinteger(L, 2);
    if (sb) sb->setScrollPage(page);
    return 0;
}

int ScrollBarBinding::getScrollPage(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushinteger(L, (lua_Integer)sb->getScrollPage());
    else lua_pushinteger(L, 0);
    return 1;
}

int ScrollBarBinding::setScrollViewPage(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    size_t page = (size_t)luaL_checkinteger(L, 2);
    if (sb) sb->setScrollViewPage(page);
    return 0;
}

int ScrollBarBinding::getScrollViewPage(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushinteger(L, (lua_Integer)sb->getScrollViewPage());
    else lua_pushinteger(L, 0);
    return 1;
}

int ScrollBarBinding::setScrollWheelPage(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    size_t page = (size_t)luaL_checkinteger(L, 2);
    if (sb) sb->setScrollWheelPage(page);
    return 0;
}

int ScrollBarBinding::getScrollWheelPage(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushinteger(L, (lua_Integer)sb->getScrollWheelPage());
    else lua_pushinteger(L, 0);
    return 1;
}

int ScrollBarBinding::setVerticalAlignment(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    bool vert = lua_toboolean(L, 2) != 0;
    if (sb) sb->setVerticalAlignment(vert);
    return 0;
}

int ScrollBarBinding::getVerticalAlignment(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushboolean(L, sb->getVerticalAlignment() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ScrollBarBinding::setTrackSize(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    int sz = (int)luaL_checkinteger(L, 2);
    if (sb) sb->setTrackSize(sz);
    return 0;
}

int ScrollBarBinding::getTrackSize(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushinteger(L, sb->getTrackSize());
    else lua_pushinteger(L, 0);
    return 1;
}

int ScrollBarBinding::setMinTrackSize(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    int sz = (int)luaL_checkinteger(L, 2);
    if (sb) sb->setMinTrackSize(sz);
    return 0;
}

int ScrollBarBinding::getMinTrackSize(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushinteger(L, sb->getMinTrackSize());
    else lua_pushinteger(L, 0);
    return 1;
}

int ScrollBarBinding::getLineSize(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushinteger(L, sb->getLineSize());
    else lua_pushinteger(L, 0);
    return 1;
}

int ScrollBarBinding::setMoveToClick(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    bool mtc = lua_toboolean(L, 2) != 0;
    if (sb) sb->setMoveToClick(mtc);
    return 0;
}

int ScrollBarBinding::getMoveToClick(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushboolean(L, sb->getMoveToClick() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ScrollBarBinding::setRepeatEnabled(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    bool en = lua_toboolean(L, 2) != 0;
    if (sb) sb->setRepeatEnabled(en);
    return 0;
}

int ScrollBarBinding::getRepeatEnabled(lua_State* L)
{
    MyGUI::ScrollBar* sb = getScrollBar(L, 1);
    if (sb) lua_pushboolean(L, sb->getRepeatEnabled() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

static int ScrollBar_tostring(lua_State* L)
{
    MyGUI::Widget* w = MyGUIBindings::toWidget(L, 1);
    MyGUI::ScrollBar* sb = w ? w->castType<MyGUI::ScrollBar>(false) : nullptr;
    char buf[128];
    if (sb)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ScrollBar('%s'):%p", sb->getName().c_str(), sb);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ScrollBar(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void ScrollBarBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", ScrollBar_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setScrollRange",       setScrollRange },
        { "getScrollRange",       getScrollRange },
        { "setScrollPosition",    setScrollPosition },
        { "getScrollPosition",    getScrollPosition },
        { "setScrollPage",        setScrollPage },
        { "getScrollPage",        getScrollPage },
        { "setScrollViewPage",    setScrollViewPage },
        { "getScrollViewPage",    getScrollViewPage },
        { "setScrollWheelPage",   setScrollWheelPage },
        { "getScrollWheelPage",   getScrollWheelPage },
        { "setVerticalAlignment", setVerticalAlignment },
        { "getVerticalAlignment", getVerticalAlignment },
        { "setTrackSize",         setTrackSize },
        { "getTrackSize",         getTrackSize },
        { "setMinTrackSize",      setMinTrackSize },
        { "getMinTrackSize",      getMinTrackSize },
        { "getLineSize",          getLineSize },
        { "setMoveToClick",       setMoveToClick },
        { "getMoveToClick",       getMoveToClick },
        { "setRepeatEnabled",     setRepeatEnabled },
        { "getRepeatEnabled",     getRepeatEnabled },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L);
    registerGetter(L, "scrollPosition", ScrollBarBinding::getScrollPosition);
    registerGetter(L, "position", ScrollBarBinding::getScrollPosition);
    registerGetter(L, "scrollRange", ScrollBarBinding::getScrollRange);
    registerGetter(L, "range", ScrollBarBinding::getScrollRange);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "scrollPosition", ScrollBarBinding::setScrollPosition);
    registerSetter(L, "position", ScrollBarBinding::setScrollPosition);
    registerSetter(L, "scrollRange", ScrollBarBinding::setScrollRange);
    registerSetter(L, "range", ScrollBarBinding::setScrollRange);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);

    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
