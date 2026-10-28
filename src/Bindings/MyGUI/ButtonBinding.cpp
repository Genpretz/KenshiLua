#include "pch.h"
#include "Bindings/MyGUI/ButtonBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::Button* ButtonBinding::getButton(lua_State* L, int idx)
{
    return MyGUIBindings::checkWidget<MyGUI::Button>(L, idx);
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

static int Button_tostring(lua_State* L)
{
    MyGUI::Widget* w = MyGUIBindings::toWidget(L, 1);
    MyGUI::Button* b = w ? w->castType<MyGUI::Button>(false) : nullptr;
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
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L);
    registerGetter(L, "stateSelected", ButtonBinding::getStateSelected);
    registerGetter(L, "selected", ButtonBinding::getStateSelected);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "stateSelected", ButtonBinding::setStateSelected);
    registerSetter(L, "selected", ButtonBinding::setStateSelected);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);

    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
