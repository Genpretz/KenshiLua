#include "pch.h"
#include "Bindings/MyGUI/MenuBarBinding.h"
#include "Bindings/MyGUI/MenuControlBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::MenuBar* MenuBarBinding::getMenuBar(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::MenuBar>(false);
}

static int MenuBar_tostring(lua_State* L)
{
    MyGUI::MenuBar* mb = MenuBarBinding::getMenuBar(L, 1);
    char buf[128];
    if (mb)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.MenuBar('%s'):%p", mb->getName().c_str(), mb);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.MenuBar(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void MenuBarBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", MenuBar_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    setMetatableParent(L, getMetatableName(), MenuControlBinding::getMetatableName());
}

} // namespace KenshiLua
