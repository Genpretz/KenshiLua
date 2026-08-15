#include "pch.h"
#include "kenshi\gui\OrdersPanel.h"
#include "OrdersPanelBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGuiBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/MainBarGUIBinding.h"
#include "Bindings/Gui/OrderDataBinding.h"
#include "Bindings/Gui/OrdersItemBoxBinding.h"

namespace KenshiLua
{

static OrdersPanel* getInstance(lua_State* L, int idx)
{
    return checkObject<OrdersPanel>(L, idx, OrdersPanelBinding::getMetatableName());
}

// --- Getters for OrdersPanel ---
static int OrdersPanel_get_ordersCharacter(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    return HandBinding::push(L, instance->ordersCharacter);
}

static int OrdersPanel_get_ordersItemBox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    return pushObject<OrdersItemBox>(L, instance->ordersItemBox, OrdersItemBoxBinding::getMetatableName());
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
static int OrdersPanel_set_ordersCharacter(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    instance->ordersCharacter = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int OrdersPanel_set_ordersItemBox(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");
    instance->ordersItemBox = lua_isnoneornil(L, 2) ? nullptr : checkObject<OrdersItemBox>(L, 2, OrdersItemBoxBinding::getMetatableName());
    return 0;
}

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

int OrdersPanelBinding::update(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->update(character);
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

int OrdersPanelBinding::removeJob(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    OrderData* data = checkObject<OrderData>(L, 2, OrderDataBinding::getMetatableName());
    instance->removeJob(data);
    return 0;
}

int OrdersPanelBinding::notifyEndDropOrder(lua_State* L)
{
    OrdersPanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersPanel is nil");

    wraps::BaseLayout* _sender = nullptr;
    if (lua_isuserdata(L, 2)) {
        void* raw = lua_touserdata(L, 2);
        _sender = (wraps::BaseLayout*)(raw ? *(void**)raw : nullptr);
    } else if (lua_islightuserdata(L, 2)) {
        _sender = (wraps::BaseLayout*)lua_touserdata(L, 2);
    }
    MyGUI::DDItemInfo myGuiInfo;
    wraps::DDItemInfo _info(myGuiInfo);
    bool _result = lua_toboolean(L, 4) != 0;
    instance->notifyEndDropOrder(_sender, _info, _result);
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
  line 92: void notifyStartDropOrder(...) - non-string reference arg
  line 93: void notifyRequestDropOrder(...) - non-string reference arg
  line 95: void toggleStealth(...) - unsupported arg type
  line 96: void toggleRanged(...) - unsupported arg type
  line 99: void speedPrevious(...) - unsupported arg type
  line 100: void speedNext(...) - unsupported arg type
  line 101: void blockmodeButton(...) - unsupported arg type
  line 102: void holdButtonCallback(...) - unsupported arg type
  line 103: void passiveButtonCallback(...) - unsupported arg type
  line 104: void chaseButtonCallback(...) - unsupported arg type
  line 105: void tauntButtonCallback(...) - unsupported arg type
  line 106: void medicButton(...) - unsupported arg type
  line 107: void liftButton(...) - unsupported arg type
  line 108: void prospectingButton(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - OrdersPanel_get_ordersEmptyPanel: MyGUI::Widget* (unbound pointer)
  - OrdersPanel_get_blocksCheckbox: MyGUI::Button* (unbound pointer)
  - OrdersPanel_get_holdCheckBox: MyGUI::Button* (unbound pointer)
  - OrdersPanel_get_passiveCheckBox: MyGUI::Button* (unbound pointer)
  - OrdersPanel_get_chaseCheckBox: MyGUI::Button* (unbound pointer)
  - OrdersPanel_get_tauntCheckBox: MyGUI::Button* (unbound pointer)
  - OrdersPanel_get_rangedCheckBox: MyGUI::Button* (unbound pointer)
  - OrdersPanel_get_stealthCheckBox: MyGUI::Button* (unbound pointer)
  - OrdersPanel_get_speedPrevButton: MyGUI::Button* (unbound pointer)
  - OrdersPanel_get_speedNextButton: MyGUI::Button* (unbound pointer)
  - OrdersPanel_get_speedImagePanel: MyGUI::ImageBox* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 115: orders (lektor<OrderData>) - unsupported type
  line 126: speedImageNames (Ogre::vector<std::string>::type) - unsupported type
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
        { "update", OrdersPanelBinding::update },
        { "clear", OrdersPanelBinding::clear },
        { "command", OrdersPanelBinding::command },
        { "refreshOrders", OrdersPanelBinding::refreshOrders },
        { "moveJob", OrdersPanelBinding::moveJob },
        { "removeJob", OrdersPanelBinding::removeJob },
        { "notifyEndDropOrder", OrdersPanelBinding::notifyEndDropOrder },
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
    registerGetter(L, "ordersCharacter", OrdersPanel_get_ordersCharacter);
    registerGetter(L, "ordersItemBox", OrdersPanel_get_ordersItemBox);
    registerGetter(L, "ordersItemWidth", OrdersPanel_get_ordersItemWidth);
    registerGetter(L, "ordersItemBoxScrollBarSize", OrdersPanel_get_ordersItemBoxScrollBarSize);
    registerGetter(L, "ordersItemBoxMaxVisible", OrdersPanel_get_ordersItemBoxMaxVisible);
    registerGetter(L, "ordersEmptyPanel", OrdersPanel_get_ordersEmptyPanel);
    registerGetter(L, "blocksCheckbox", OrdersPanel_get_blocksCheckbox);
    registerGetter(L, "holdCheckBox", OrdersPanel_get_holdCheckBox);
    registerGetter(L, "passiveCheckBox", OrdersPanel_get_passiveCheckBox);
    registerGetter(L, "chaseCheckBox", OrdersPanel_get_chaseCheckBox);
    registerGetter(L, "tauntCheckBox", OrdersPanel_get_tauntCheckBox);
    registerGetter(L, "rangedCheckBox", OrdersPanel_get_rangedCheckBox);
    registerGetter(L, "stealthCheckBox", OrdersPanel_get_stealthCheckBox);
    registerGetter(L, "speedPrevButton", OrdersPanel_get_speedPrevButton);
    registerGetter(L, "speedNextButton", OrdersPanel_get_speedNextButton);
    registerGetter(L, "speedImagePanel", OrdersPanel_get_speedImagePanel);
    registerGetter(L, "speedImageNamesIdx", OrdersPanel_get_speedImageNamesIdx);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "ordersCharacter", OrdersPanel_set_ordersCharacter);
    registerSetter(L, "ordersItemBox", OrdersPanel_set_ordersItemBox);
    registerSetter(L, "ordersItemWidth", OrdersPanel_set_ordersItemWidth);
    registerSetter(L, "ordersItemBoxScrollBarSize", OrdersPanel_set_ordersItemBoxScrollBarSize);
    registerSetter(L, "ordersItemBoxMaxVisible", OrdersPanel_set_ordersItemBoxMaxVisible);
    registerSetter(L, "speedImageNamesIdx", OrdersPanel_set_speedImageNamesIdx);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, OrdersPanelBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua