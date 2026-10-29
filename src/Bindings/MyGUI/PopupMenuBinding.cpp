#include "pch.h"
#include "Bindings/MyGUI/PopupMenuBinding.h"
#include "Bindings/MyGUI/MenuControlBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::PopupMenu* PopupMenuBinding::getPopupMenu(lua_State* L, int idx)
{
    return MyGUIBindings::checkWidget<MyGUI::PopupMenu>(L, idx);
}

static int PopupMenu_tostring(lua_State* L)
{
    MyGUI::Widget* w = MyGUIBindings::toWidget(L, 1);
    MyGUI::PopupMenu* pm = w ? w->castType<MyGUI::PopupMenu>(false) : nullptr;
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
