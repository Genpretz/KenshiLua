#include "pch.h"
#include <kenshi/gui/OrdersPanel.h>
#include "OrdersPanelBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static OrdersPanel* getInstance(lua_State* L, int idx)
{
    return checkObject<OrdersPanel>(L, idx, OrdersPanelBinding::getMetatableName());
}

// --- Getters for OrdersPanel ---
static int OrdersPanel_get_ordersItemBox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->ordersItemBox);
    return 1;
}

static int OrdersPanel_get_ordersItemWidth(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushinteger(L, instance->ordersItemWidth);
    return 1;
}

static int OrdersPanel_get_ordersItemBoxScrollBarSize(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushinteger(L, instance->ordersItemBoxScrollBarSize);
    return 1;
}

static int OrdersPanel_get_ordersItemBoxMaxVisible(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushinteger(L, instance->ordersItemBoxMaxVisible);
    return 1;
}

static int OrdersPanel_get_ordersEmptyPanel(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->ordersEmptyPanel);
    return 1;
}

static int OrdersPanel_get_blocksCheckbox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->blocksCheckbox);
    return 1;
}

static int OrdersPanel_get_holdCheckBox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->holdCheckBox);
    return 1;
}

static int OrdersPanel_get_passiveCheckBox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->passiveCheckBox);
    return 1;
}

static int OrdersPanel_get_chaseCheckBox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->chaseCheckBox);
    return 1;
}

static int OrdersPanel_get_tauntCheckBox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->tauntCheckBox);
    return 1;
}

static int OrdersPanel_get_rangedCheckBox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->rangedCheckBox);
    return 1;
}

static int OrdersPanel_get_stealthCheckBox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->stealthCheckBox);
    return 1;
}

static int OrdersPanel_get_speedPrevButton(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->speedPrevButton);
    return 1;
}

static int OrdersPanel_get_speedNextButton(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->speedNextButton);
    return 1;
}

static int OrdersPanel_get_speedImagePanel(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushlightuserdata(L, (void*)instance->speedImagePanel);
    return 1;
}

static int OrdersPanel_get_speedImageNamesIdx(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    lua_pushinteger(L, instance->speedImageNamesIdx);
    return 1;
}

// --- Setters for OrdersPanel ---
static int OrdersPanel_set_ordersItemWidth(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    instance->ordersItemWidth = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OrdersPanel_set_ordersItemBoxScrollBarSize(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    instance->ordersItemBoxScrollBarSize = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OrdersPanel_set_ordersItemBoxMaxVisible(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    instance->ordersItemBoxMaxVisible = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OrdersPanel_set_speedImageNamesIdx(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    instance->speedImageNamesIdx = (char)luaL_checkinteger(L, 2);
    return 0;
}

int OrdersPanelBinding::_DESTRUCTOR(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int OrdersPanelBinding::clear(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    instance->clear();
    return 0;
}

int OrdersPanelBinding::command(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    int cmd = (int)luaL_checkinteger(L, 2);
    instance->command(cmd);
    return 0;
}

int OrdersPanelBinding::refreshOrders(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    instance->refreshOrders();
    return 0;
}

int OrdersPanelBinding::moveJob(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    int orderIdx = (int)luaL_checkinteger(L, 2);
    int targetIdx = (int)luaL_checkinteger(L, 3);
    instance->moveJob(orderIdx, targetIdx);
    return 0;
}

int OrdersPanelBinding::setSpeed(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    MoveSpeed moveSpeed = (MoveSpeed)luaL_checkinteger(L, 2);
    instance->setSpeed(moveSpeed);
    return 0;
}

int OrdersPanelBinding::setSpeedImage(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    MoveSpeed moveSpeed = (MoveSpeed)luaL_checkinteger(L, 2);
    instance->setSpeedImage(moveSpeed);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 81: OrdersPanel* _CONSTRUCTOR(...) - unsupported arg type
  line 84: void update(...) - unsupported arg type
  line 89: void removeJob(...) - unsupported arg type
  line 90: void notifyStartDropOrder(...) - pointer arg
  line 91: void notifyRequestDropOrder(...) - pointer arg
  line 92: void notifyEndDropOrder(...) - pointer arg
  line 93: void toggleStealth(...) - unsupported arg type
  line 94: void toggleRanged(...) - unsupported arg type
  line 97: void speedPrevious(...) - unsupported arg type
  line 98: void speedNext(...) - unsupported arg type
  line 99: void blockmodeButton(...) - unsupported arg type
  line 100: void holdButtonCallback(...) - unsupported arg type
  line 101: void passiveButtonCallback(...) - unsupported arg type
  line 102: void chaseButtonCallback(...) - unsupported arg type
  line 103: void tauntButtonCallback(...) - unsupported arg type
  line 104: void medicButton(...) - unsupported arg type
  line 105: void liftButton(...) - unsupported arg type
  line 106: void prospectingButton(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 107: ordersCharacter (hand) - unsupported type
  line 113: orders (lektor<OrderData>) - unsupported type
  line 124: speedImageNames (Ogre::vector<std::string>::type) - unsupported type
*/

int OrdersPanelBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int OrdersPanelBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.OrdersPanel object");
    return 1;
}

void OrdersPanelBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OrdersPanelBinding::gc },
        { "__tostring", OrdersPanelBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", OrdersPanelBinding::_DESTRUCTOR },
        { "clear", OrdersPanelBinding::clear },
        { "command", OrdersPanelBinding::command },
        { "refreshOrders", OrdersPanelBinding::refreshOrders },
        { "moveJob", OrdersPanelBinding::moveJob },
        { "setSpeed", OrdersPanelBinding::setSpeed },
        { "setSpeedImage", OrdersPanelBinding::setSpeedImage },
        { 0, 0 }
    };

    registerClass(
        L, 
        OrdersPanelBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OrdersPanelBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, OrdersPanel_get_ordersItemBox);
    lua_setfield(L, -2, "ordersItemBox");
    lua_pushcfunction(L, OrdersPanel_get_ordersItemWidth);
    lua_setfield(L, -2, "ordersItemWidth");
    lua_pushcfunction(L, OrdersPanel_get_ordersItemBoxScrollBarSize);
    lua_setfield(L, -2, "ordersItemBoxScrollBarSize");
    lua_pushcfunction(L, OrdersPanel_get_ordersItemBoxMaxVisible);
    lua_setfield(L, -2, "ordersItemBoxMaxVisible");
    lua_pushcfunction(L, OrdersPanel_get_ordersEmptyPanel);
    lua_setfield(L, -2, "ordersEmptyPanel");
    lua_pushcfunction(L, OrdersPanel_get_blocksCheckbox);
    lua_setfield(L, -2, "blocksCheckbox");
    lua_pushcfunction(L, OrdersPanel_get_holdCheckBox);
    lua_setfield(L, -2, "holdCheckBox");
    lua_pushcfunction(L, OrdersPanel_get_passiveCheckBox);
    lua_setfield(L, -2, "passiveCheckBox");
    lua_pushcfunction(L, OrdersPanel_get_chaseCheckBox);
    lua_setfield(L, -2, "chaseCheckBox");
    lua_pushcfunction(L, OrdersPanel_get_tauntCheckBox);
    lua_setfield(L, -2, "tauntCheckBox");
    lua_pushcfunction(L, OrdersPanel_get_rangedCheckBox);
    lua_setfield(L, -2, "rangedCheckBox");
    lua_pushcfunction(L, OrdersPanel_get_stealthCheckBox);
    lua_setfield(L, -2, "stealthCheckBox");
    lua_pushcfunction(L, OrdersPanel_get_speedPrevButton);
    lua_setfield(L, -2, "speedPrevButton");
    lua_pushcfunction(L, OrdersPanel_get_speedNextButton);
    lua_setfield(L, -2, "speedNextButton");
    lua_pushcfunction(L, OrdersPanel_get_speedImagePanel);
    lua_setfield(L, -2, "speedImagePanel");
    lua_pushcfunction(L, OrdersPanel_get_speedImageNamesIdx);
    lua_setfield(L, -2, "speedImageNamesIdx");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, OrdersPanel_set_ordersItemWidth);
    lua_setfield(L, -2, "ordersItemWidth");
    lua_pushcfunction(L, OrdersPanel_set_ordersItemBoxScrollBarSize);
    lua_setfield(L, -2, "ordersItemBoxScrollBarSize");
    lua_pushcfunction(L, OrdersPanel_set_ordersItemBoxMaxVisible);
    lua_setfield(L, -2, "ordersItemBoxMaxVisible");
    lua_pushcfunction(L, OrdersPanel_set_speedImageNamesIdx);
    lua_setfield(L, -2, "speedImageNamesIdx");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, OrdersPanelBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua