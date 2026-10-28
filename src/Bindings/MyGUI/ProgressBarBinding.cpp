#include "pch.h"
#include "Bindings/MyGUI/ProgressBarBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

MyGUI::ProgressBar* ProgressBarBinding::getProgressBar(lua_State* L, int idx)
{
    return MyGUIBindings::checkWidget<MyGUI::ProgressBar>(L, idx);
}

int ProgressBarBinding::setProgressRange(lua_State* L)
{
    MyGUI::ProgressBar* pb = getProgressBar(L, 1);
    size_t r = (size_t)luaL_checkinteger(L, 2);
    if (pb) pb->setProgressRange(r);
    return 0;
}

int ProgressBarBinding::getProgressRange(lua_State* L)
{
    MyGUI::ProgressBar* pb = getProgressBar(L, 1);
    if (pb) lua_pushinteger(L, (lua_Integer)pb->getProgressRange());
    else lua_pushinteger(L, 0);
    return 1;
}

int ProgressBarBinding::setProgressPosition(lua_State* L)
{
    MyGUI::ProgressBar* pb = getProgressBar(L, 1);
    size_t p = (size_t)luaL_checkinteger(L, 2);
    if (pb) pb->setProgressPosition(p);
    return 0;
}

int ProgressBarBinding::getProgressPosition(lua_State* L)
{
    MyGUI::ProgressBar* pb = getProgressBar(L, 1);
    if (pb) lua_pushinteger(L, (lua_Integer)pb->getProgressPosition());
    else lua_pushinteger(L, 0);
    return 1;
}

int ProgressBarBinding::setProgressAutoTrack(lua_State* L)
{
    MyGUI::ProgressBar* pb = getProgressBar(L, 1);
    bool at = lua_toboolean(L, 2) != 0;
    if (pb) pb->setProgressAutoTrack(at);
    return 0;
}

int ProgressBarBinding::getProgressAutoTrack(lua_State* L)
{
    MyGUI::ProgressBar* pb = getProgressBar(L, 1);
    if (pb) lua_pushboolean(L, pb->getProgressAutoTrack() ? 1 : 0);
    else lua_pushboolean(L, 0);
    return 1;
}

int ProgressBarBinding::setFlowDirection(lua_State* L)
{
    MyGUI::ProgressBar* pb = getProgressBar(L, 1);
    int dir = (int)luaL_checkinteger(L, 2);
    if (pb) pb->setFlowDirection(MyGUI::FlowDirection((MyGUI::FlowDirection::Enum)dir));
    return 0;
}

int ProgressBarBinding::getFlowDirection(lua_State* L)
{
    MyGUI::ProgressBar* pb = getProgressBar(L, 1);
    if (pb) lua_pushinteger(L, (lua_Integer)pb->getFlowDirection().getValue());
    else lua_pushinteger(L, 0);
    return 1;
}

static int ProgressBar_tostring(lua_State* L)
{
    MyGUI::Widget* w = MyGUIBindings::toWidget(L, 1);
    MyGUI::ProgressBar* pb = w ? w->castType<MyGUI::ProgressBar>(false) : nullptr;
    char buf[128];
    if (pb)
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ProgressBar('%s'):%p", pb->getName().c_str(), pb);
    }
    else
    {
        _snprintf(buf, sizeof(buf), "MyGUI.ProgressBar(nil)");
    }
    lua_pushstring(L, buf);
    return 1;
}

void ProgressBarBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", ProgressBar_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setProgressRange",     setProgressRange },
        { "getProgressRange",     getProgressRange },
        { "setProgressPosition",  setProgressPosition },
        { "getProgressPosition",  getProgressPosition },
        { "setProgressAutoTrack", setProgressAutoTrack },
        { "getProgressAutoTrack", getProgressAutoTrack },
        { "setFlowDirection",     setFlowDirection },
        { "getFlowDirection",     getFlowDirection },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L);
    registerGetter(L, "progressPosition", ProgressBarBinding::getProgressPosition);
    registerGetter(L, "position", ProgressBarBinding::getProgressPosition);
    registerGetter(L, "progressRange", ProgressBarBinding::getProgressRange);
    registerGetter(L, "range", ProgressBarBinding::getProgressRange);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "progressPosition", ProgressBarBinding::setProgressPosition);
    registerSetter(L, "position", ProgressBarBinding::setProgressPosition);
    registerSetter(L, "progressRange", ProgressBarBinding::setProgressRange);
    registerSetter(L, "range", ProgressBarBinding::setProgressRange);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);

    setMetatableParent(L, getMetatableName(), WidgetBinding::getMetatableName());
}

} // namespace KenshiLua
