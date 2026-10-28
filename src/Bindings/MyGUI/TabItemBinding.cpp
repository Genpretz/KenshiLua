#include "pch.h"
#include "Bindings/MyGUI/TabItemBinding.h"
#include "Bindings/MyGUI/TextBoxBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::TabItem* TabItemBinding::getTabItem(lua_State* L, int idx)
{
    return MyGUIBindings::checkWidget<MyGUI::TabItem>(L, idx);
}

int TabItemBinding::setButtonWidth(lua_State* L)
{
    MyGUI::TabItem* ti = getTabItem(L, 1);
    int w = (int)luaL_optinteger(L, 2, MyGUI::DEFAULT);
    if (ti) ti->setButtonWidth(w);
    return 0;
}

static int TabItem_tostring(lua_State* L)
{
    MyGUI::Widget* w = MyGUIBindings::toWidget(L, 1);
    MyGUI::TabItem* ti = w ? w->castType<MyGUI::TabItem>(false) : nullptr;
    char buf[128];
    if (ti)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.TabItem('%s'):%p", ti->getName().c_str(), ti);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.TabItem(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void TabItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", TabItem_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setButtonWidth", setButtonWidth },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
    setMetatableParent(L, getMetatableName(), TextBoxBinding::getMetatableName());
}

} // namespace KenshiLua
