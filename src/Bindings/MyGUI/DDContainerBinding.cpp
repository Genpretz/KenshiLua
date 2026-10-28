#include "pch.h"
#include "Bindings/MyGUI/DDContainerBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::DDContainer* DDContainerBinding::getDDContainer(lua_State* L, int idx)
{
    return MyGUIBindings::checkWidget<MyGUI::DDContainer>(L, idx);
}

int DDContainerBinding::setNeedDragDrop(lua_State* L)
{
    MyGUI::DDContainer* dd = getDDContainer(L, 1);
    bool nd = lua_toboolean(L, 2) != 0;
    if (dd) dd->setNeedDragDrop(nd);
    return 0;
}

int DDContainerBinding::getNeedDragDrop(lua_State* L)
{
    MyGUI::DDContainer* dd = getDDContainer(L, 1);
    if (dd) lua_pushboolean(L, dd->getNeedDragDrop() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int DDContainerBinding::resetDrag(lua_State* L)
{
    MyGUI::DDContainer* dd = getDDContainer(L, 1);
    if (dd) dd->resetDrag();
    return 0;
}

static int DDContainer_tostring(lua_State* L)
{
    MyGUI::Widget* w = MyGUIBindings::toWidget(L, 1);
    MyGUI::DDContainer* dd = w ? w->castType<MyGUI::DDContainer>(false) : nullptr;
    char buf[128];
    if (dd)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.DDContainer('%s'):%p", dd->getName().c_str(), dd);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.DDContainer(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void DDContainerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", DDContainer_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setNeedDragDrop", setNeedDragDrop },
        { "getNeedDragDrop", getNeedDragDrop },
        { "resetDrag",       resetDrag },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
