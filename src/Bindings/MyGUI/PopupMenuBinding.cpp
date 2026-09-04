#include "pch.h"
#include "Bindings/MyGUI/PopupMenuBinding.h"
#include "Bindings/MyGUI/MenuControlBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::PopupMenu* PopupMenuBinding::getPopupMenu(lua_State* L, int idx)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, idx);
    if (!w) return nullptr;
    return w->castType<MyGUI::PopupMenu>(false);
}

static int PopupMenu_tostring(lua_State* L)
{
    MyGUI::PopupMenu* pm = PopupMenuBinding::getPopupMenu(L, 1);
    char buf[128];
    if (pm)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.PopupMenu('%s'):%p", pm->getName().c_str(), pm);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.PopupMenu(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void PopupMenuBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", PopupMenu_tostring },
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
