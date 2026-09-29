#include "pch.h"
#include "kenshi\gui\Tooltip.h"
#include "ToolTipInventoryBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Gui/ToolTipBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"

namespace KenshiLua
{

static ToolTipInventory* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTipInventory>(L, idx, ToolTipInventoryBinding::getMetatableName());
}

// --- Getters for ToolTipInventory ---
static int ToolTipInventory_get_compareTooltip(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    return pushObject<ToolTipInventory>(L, instance->compareTooltip, ToolTipInventoryBinding::getMetatableName());
}

// --- Setters for ToolTipInventory ---
static int ToolTipInventory_set_compareTooltip(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    instance->compareTooltip = lua_isnoneornil(L, 2) ? nullptr : checkObject<ToolTipInventory>(L, 2, ToolTipInventoryBinding::getMetatableName());
    return 0;
}

int ToolTipInventoryBinding::update(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");

    instance->update();
    return 0;
}

int ToolTipInventoryBinding::_NV_update(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");

    instance->_NV_update();
    return 0;
}

int ToolTipInventoryBinding::_setup(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_setup(widget);
    return 0;
}

int ToolTipInventoryBinding::_NV__setup(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV__setup(widget);
    return 0;
}

int ToolTipInventoryBinding::setup(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->setup(widget);
    return 0;
}

int ToolTipInventoryBinding::_NV_setup(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV_setup(widget);
    return 0;
}

int ToolTipInventoryBinding::show(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 3);
    instance->show(sender, pt);
    return 0;
}

int ToolTipInventoryBinding::_NV_show(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 3);
    instance->_NV_show(sender, pt);
    return 0;
}

int ToolTipInventoryBinding::setContent(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->setContent(widget);
    return 0;
}

int ToolTipInventoryBinding::_NV_setContent(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV_setContent(widget);
    return 0;
}

int ToolTipInventoryBinding::clearData(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->clearData(widget);
    return 0;
}

int ToolTipInventoryBinding::_NV_clearData(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* widget = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    instance->_NV_clearData(widget);
    return 0;
}

int ToolTipInventoryBinding::mouseMoved(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    int left = (int)luaL_checkinteger(L, 3);
    int top = (int)luaL_checkinteger(L, 4);
    instance->mouseMoved(sender, left, top);
    return 0;
}

int ToolTipInventoryBinding::setPosition(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 2);
    instance->setPosition(pt);
    return 0;
}

int ToolTipInventoryBinding::_NV_setPosition(lua_State* L)
{
    ToolTipInventory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipInventory is nil");
    MyGUI::IntPoint pt = MyGUIBindings::readIntPoint(L, 2);
    instance->_NV_setPosition(pt);
    return 0;
}

int ToolTipInventoryBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipInventoryBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTipInventory object");
    return 1;
}

void ToolTipInventoryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipInventoryBinding::gc },
        { "__tostring", ToolTipInventoryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", ToolTipInventoryBinding::update },
        { "_NV_update", ToolTipInventoryBinding::_NV_update },
        { "_setup", ToolTipInventoryBinding::_setup },
        { "_NV__setup", ToolTipInventoryBinding::_NV__setup },
        { "setup", ToolTipInventoryBinding::setup },
        { "_NV_setup", ToolTipInventoryBinding::_NV_setup },
        { "show", ToolTipInventoryBinding::show },
        { "_NV_show", ToolTipInventoryBinding::_NV_show },
        { "setContent", ToolTipInventoryBinding::setContent },
        { "_NV_setContent", ToolTipInventoryBinding::_NV_setContent },
        { "clearData", ToolTipInventoryBinding::clearData },
        { "_NV_clearData", ToolTipInventoryBinding::_NV_clearData },
        { "mouseMoved", ToolTipInventoryBinding::mouseMoved },
        { "setPosition", ToolTipInventoryBinding::setPosition },
        { "_NV_setPosition", ToolTipInventoryBinding::_NV_setPosition },
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipInventoryBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipInventoryBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "compareTooltip", ToolTipInventory_get_compareTooltip);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "compareTooltip", ToolTipInventory_set_compareTooltip);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ToolTip
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ToolTipInventoryBinding::getMetatableName(), ToolTipBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
