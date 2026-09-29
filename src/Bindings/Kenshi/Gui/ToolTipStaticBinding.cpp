#include "pch.h"
#include "kenshi\gui\Tooltip.h"
#include "ToolTipStaticBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Gui/ToolTipBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"

namespace KenshiLua
{

static ToolTipStatic* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTipStatic>(L, idx, ToolTipStaticBinding::getMetatableName());
}

// --- Getters for ToolTipStatic ---
// --- Setters for ToolTipStatic ---
int ToolTipStaticBinding::update(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");

    instance->update();
    return 0;
}

int ToolTipStaticBinding::_NV_update(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");

    instance->_NV_update();
    return 0;
}

int ToolTipStaticBinding::setVisible(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int ToolTipStaticBinding::_NV_setVisible(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(visible);
    return 0;
}

int ToolTipStaticBinding::clear(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->clear(widget);
    return 0;
}

int ToolTipStaticBinding::_NV_clear(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV_clear(widget);
    return 0;
}

int ToolTipStaticBinding::_setup(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_setup(widget);
    return 0;
}

int ToolTipStaticBinding::_NV__setup(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV__setup(widget);
    return 0;
}

int ToolTipStaticBinding::setPosition(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");
    MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 2);
    instance->setPosition(pt);
    return 0;
}

int ToolTipStaticBinding::_NV_setPosition(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");
    MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 2);
    instance->_NV_setPosition(pt);
    return 0;
}

int ToolTipStaticBinding::mouseMoved(lua_State* L)
{
    ToolTipStatic* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipStatic is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    int left = (int)luaL_checkinteger(L, 3);
    int top = (int)luaL_checkinteger(L, 4);
    instance->mouseMoved(sender, left, top);
    return 0;
}

int ToolTipStaticBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipStaticBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTipStatic object");
    return 1;
}

void ToolTipStaticBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipStaticBinding::gc },
        { "__tostring", ToolTipStaticBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", ToolTipStaticBinding::update },
        { "_NV_update", ToolTipStaticBinding::_NV_update },
        { "setVisible", ToolTipStaticBinding::setVisible },
        { "_NV_setVisible", ToolTipStaticBinding::_NV_setVisible },
        { "clear", ToolTipStaticBinding::clear },
        { "_NV_clear", ToolTipStaticBinding::_NV_clear },
        { "_setup", ToolTipStaticBinding::_setup },
        { "_NV__setup", ToolTipStaticBinding::_NV__setup },
        { "setPosition", ToolTipStaticBinding::setPosition },
        { "_NV_setPosition", ToolTipStaticBinding::_NV_setPosition },
        { "mouseMoved", ToolTipStaticBinding::mouseMoved },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipStaticBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipStaticBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ToolTip
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ToolTipStaticBinding::getMetatableName(), ToolTipBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
