#include "pch.h"
#include "kenshi\gui\Tooltip.h"
#include "ToolTipFixedBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Gui/ToolTipBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"

namespace KenshiLua
{

static ToolTipFixed* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTipFixed>(L, idx, ToolTipFixedBinding::getMetatableName());
}

// --- Getters for ToolTipFixed ---
static int ToolTipFixed_get_parentPanel(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    return MyGUIBindings::pushWidget(L, instance->parentPanel);
}

static int ToolTipFixed_set_parentPanel(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    instance->parentPanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int ToolTipFixed_get_minHeight(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    lua_pushinteger(L, instance->minHeight);
    return 1;
}

// --- Setters for ToolTipFixed ---
static int ToolTipFixed_set_minHeight(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    instance->minHeight = (int)luaL_checkinteger(L, 2);
    return 0;
}

int ToolTipFixedBinding::update(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");

    instance->update();
    return 0;
}

int ToolTipFixedBinding::_NV_update(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");

    instance->_NV_update();
    return 0;
}

int ToolTipFixedBinding::setVisible(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int ToolTipFixedBinding::_NV_setVisible(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(visible);
    return 0;
}

int ToolTipFixedBinding::clear(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->clear(widget);
    return 0;
}

int ToolTipFixedBinding::_NV_clear(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV_clear(widget);
    return 0;
}

int ToolTipFixedBinding::setBottomPosition(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 2);
    instance->setBottomPosition(pt);
    return 0;
}

int ToolTipFixedBinding::setPosition(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 2);
    instance->setPosition(pt);
    return 0;
}

int ToolTipFixedBinding::_NV_setPosition(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 2);
    instance->_NV_setPosition(pt);
    return 0;
}

int ToolTipFixedBinding::_setup(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_setup(widget);
    return 0;
}

int ToolTipFixedBinding::_NV__setup(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV__setup(widget);
    return 0;
}

int ToolTipFixedBinding::mouseMoved(lua_State* L)
{
    ToolTipFixed* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipFixed is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    int left = (int)luaL_checkinteger(L, 3);
    int top = (int)luaL_checkinteger(L, 4);
    instance->mouseMoved(sender, left, top);
    return 0;
}

int ToolTipFixedBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipFixedBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTipFixed object");
    return 1;
}

void ToolTipFixedBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipFixedBinding::gc },
        { "__tostring", ToolTipFixedBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", ToolTipFixedBinding::update },
        { "_NV_update", ToolTipFixedBinding::_NV_update },
        { "setVisible", ToolTipFixedBinding::setVisible },
        { "_NV_setVisible", ToolTipFixedBinding::_NV_setVisible },
        { "clear", ToolTipFixedBinding::clear },
        { "_NV_clear", ToolTipFixedBinding::_NV_clear },
        { "setBottomPosition", ToolTipFixedBinding::setBottomPosition },
        { "setPosition", ToolTipFixedBinding::setPosition },
        { "_NV_setPosition", ToolTipFixedBinding::_NV_setPosition },
        { "_setup", ToolTipFixedBinding::_setup },
        { "_NV__setup", ToolTipFixedBinding::_NV__setup },
        { "mouseMoved", ToolTipFixedBinding::mouseMoved },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipFixedBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipFixedBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "parentPanel", ToolTipFixed_get_parentPanel);
    registerGetter(L, "minHeight", ToolTipFixed_get_minHeight);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "parentPanel", ToolTipFixed_set_parentPanel);
    registerSetter(L, "minHeight", ToolTipFixed_set_minHeight);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ToolTip
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ToolTipFixedBinding::getMetatableName(), ToolTipBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
