#include "pch.h"
#include "Bindings/MyGUI/ButtonBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::Button* ButtonBinding::getButton(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::Button>(false);
}

int ButtonBinding::setStateSelected(lua_State* L)
{
    MyGUI::Button* b = getButton(L, 1);
    bool s = lua_toboolean(L, 2) != 0;
    if (b) b->setStateSelected(s);
    return 0;
}

int ButtonBinding::getStateSelected(lua_State* L)
{
    MyGUI::Button* b = getButton(L, 1);
    if (b) lua_pushboolean(L, b->getStateSelected() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ButtonBinding::setModeImage(lua_State* L)
{
    MyGUI::Button* b = getButton(L, 1);
    bool m = lua_toboolean(L, 2) != 0;
    if (b) b->setModeImage(m);
    return 0;
}

int ButtonBinding::getModeImage(lua_State* L)
{
    MyGUI::Button* b = getButton(L, 1);
    if (b) lua_pushboolean(L, b->getModeImage() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ButtonBinding::setImageResource(lua_State* L)
{
    MyGUI::Button* b = getButton(L, 1);
    const char* name = luaL_checkstring(L, 2);
    if (b) b->setImageResource(name);
    return 0;
}

static int Button_index(lua_State* L)
{
    MyGUI::Button* b = ButtonBinding::getButton(L, 1);
    if (!b) return luaL_error(L, "Button is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "stateSelected") == 0 || strcmp(key, "selected") == 0)
    {
        lua_pushboolean(L, b->getStateSelected() ? 1 : 0);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int Button_newindex(lua_State* L)
{
    MyGUI::Button* b = ButtonBinding::getButton(L, 1);
    if (!b) return luaL_error(L, "Button is nil");
    const char* key = luaL_checkstring(L, 2);

    if (strcmp(key, "stateSelected") == 0 || strcmp(key, "selected") == 0)
    {
        b->setStateSelected(lua_toboolean(L, 3) != 0);
        return 0;
    }
    return genericPropertyNewIndex(L);
}

static int Button_tostring(lua_State* L)
{
    MyGUI::Button* b = ButtonBinding::getButton(L, 1);
    char buf[128];
    if (b)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.Button('%s'):%p", b->getName().c_str(), b);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.Button(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void ButtonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", Button_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setStateSelected", setStateSelected },
        { "getStateSelected", getStateSelected },
        { "setModeImage",     setModeImage },
        { "getModeImage",     getModeImage },
        { "setImageResource", setImageResource },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, Button_index, Button_newindex);
    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
