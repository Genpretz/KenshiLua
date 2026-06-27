#include "pch.h"
#include "kenshi\Item.h"
#include "InventoryItemBaseBinding.h"
#include "kenshi/Inventory.h"
#include "InventoryBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/InventoryBinding.h"

namespace KenshiLua
{

static InventoryItemBase* getB(lua_State* L, int idx)
{
    return checkObject<InventoryItemBase>(L, idx, InventoryItemBaseBinding::getMetatableName());
}

// --- Getters for InventoryItemBase ---
static int InventoryItemBase_get_manufacturerData(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return pushObject<GameData>(L, b->manufacturerData, GameDataBinding::getMetatableName());
}

static int InventoryItemBase_get_materialData(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return pushObject<GameData>(L, b->materialData, GameDataBinding::getMetatableName());
}

static int InventoryItemBase_get_coloriseData(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return pushObject<GameData>(L, b->coloriseData, GameDataBinding::getMetatableName());
}

static int InventoryItemBase_get_isInInventory(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, b->isInInventory ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_inventoryPos(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    // TODO: Unsupported type for inventoryPos (iVector2)
    lua_pushnil(L);
    return 1;
}

static int InventoryItemBase_get_inventorySection(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushstring(L, b->inventorySection.c_str());
    return 1;
}

static int InventoryItemBase_get_slotType(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, (lua_Integer)b->slotType);
    return 1;
}

static int InventoryItemBase_get_originalFullChargeAmount(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushnumber(L, b->originalFullChargeAmount);
    return 1;
}

static int InventoryItemBase_get_chargesLeft(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushnumber(L, b->chargesLeft);
    return 1;
}

static int InventoryItemBase_get_quality(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushnumber(L, b->quality);
    return 1;
}

static int InventoryItemBase_get_weight(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushnumber(L, b->weight);
    return 1;
}

static int InventoryItemBase_get_itemFunction(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, (lua_Integer)b->itemFunction);
    return 1;
}

static int InventoryItemBase_get_isTradeItem(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, b->isTradeItem ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_isEquipped(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, b->isEquipped ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_isUnique(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, b->isUnique ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_quantity(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, b->quantity);
    return 1;
}

static int InventoryItemBase_get_itemWidth(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, b->itemWidth);
    return 1;
}

static int InventoryItemBase_get_itemHeight(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, b->itemHeight);
    return 1;
}

static int InventoryItemBase_get_deathItem(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, b->deathItem ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_objectType(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, (lua_Integer)b->objectType);
    return 1;
}

static int InventoryItemBase_get_properOwner(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    // TODO: Unsupported type for properOwner (hand)
    lua_pushnil(L);
    return 1;
}

static int InventoryItemBase_get__whosInventoryWeAreIn(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    // TODO: Unsupported type for _whosInventoryWeAreIn (hand)
    lua_pushnil(L);
    return 1;
}

static int InventoryItemBase_get__isResearchArtifact(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, b->_isResearchArtifact ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_itemGroup(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    // TODO: Unsupported type for itemGroup (BuildingItemGroup*)
    lua_pushnil(L);
    return 1;
}

// --- Setters for InventoryItemBase ---
static int InventoryItemBase_set_manufacturerData(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for manufacturerData");
}

static int InventoryItemBase_set_materialData(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for materialData");
}

static int InventoryItemBase_set_coloriseData(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for coloriseData");
}

static int InventoryItemBase_set_isInInventory(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->isInInventory = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_inventoryPos(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for inventoryPos");
}

static int InventoryItemBase_set_inventorySection(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->inventorySection = luaL_checkstring(L, 2);
    return 0;
}

static int InventoryItemBase_set_slotType(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->slotType = (AttachSlot)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_originalFullChargeAmount(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->originalFullChargeAmount = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventoryItemBase_set_chargesLeft(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->chargesLeft = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventoryItemBase_set_quality(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->quality = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventoryItemBase_set_weight(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->weight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventoryItemBase_set_itemFunction(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->itemFunction = (ItemFunction)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_isTradeItem(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->isTradeItem = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_isEquipped(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->isEquipped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_isUnique(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->isUnique = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_quantity(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->quantity = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_itemWidth(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->itemWidth = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_itemHeight(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->itemHeight = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_deathItem(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->deathItem = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_objectType(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->objectType = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_properOwner(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for properOwner");
}

static int InventoryItemBase_set__whosInventoryWeAreIn(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _whosInventoryWeAreIn");
}

static int InventoryItemBase_set__isResearchArtifact(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    b->_isResearchArtifact = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_itemGroup(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for itemGroup");
}

int InventoryItemBaseBinding::deactivate(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    b->deactivate();
    return 0;
}

int InventoryItemBaseBinding::resetAfterCopy(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    b->resetAfterCopy();
    return 0;
}

int InventoryItemBaseBinding::resetCharges(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    bool randomise = lua_toboolean(L, 2) != 0;
    b->resetCharges(randomise);
    return 0;
}

int InventoryItemBaseBinding::getItemType(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    itemType result = b->getItemType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int InventoryItemBaseBinding::getItemWeightSingle(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    float result = b->getItemWeightSingle();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getItemWeightSingle(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    float result = b->_NV_getItemWeightSingle();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryItemBaseBinding::getItemWeight(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    float result = b->getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getItemWeight(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    float result = b->_NV_getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryItemBaseBinding::getAvgPrice(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    int result = b->getAvgPrice();
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::getValueSingle(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = b->getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getValueSingle(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = b->_NV_getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::getValueAll(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = b->getValueAll(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getValueAll(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = b->_NV_getValueAll(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::getMaxAffordableNum(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    int cashLimit = (int)luaL_checkinteger(L, 2);
    bool isPlayer = lua_toboolean(L, 3) != 0;
    int result = b->getMaxAffordableNum(cashLimit, isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getMaxAffordableNum(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    int cashLimit = (int)luaL_checkinteger(L, 2);
    bool isPlayer = lua_toboolean(L, 3) != 0;
    int result = b->_NV_getMaxAffordableNum(cashLimit, isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::getInventory(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    Inventory* result = b->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryItemBaseBinding::_NV_getInventory(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    Inventory* result = b->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryItemBaseBinding::onGround(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    bool result = b->onGround();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::isResearchArtifact(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    bool result = b->isResearchArtifact();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::getLevel(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    int result = b->getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getLevel(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    int result = b->_NV_getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::getItemSound(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    const char* result = b->getItemSound();
    lua_pushstring(L, result);
    return 1;
}

int InventoryItemBaseBinding::isStolen(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    bool includeUnknown = lua_toboolean(L, 2) != 0;
    bool result = b->isStolen(includeUnknown);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::_DESTRUCTOR(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    b->_DESTRUCTOR();
    return 0;
}

int InventoryItemBaseBinding::merchantPriceMod(lua_State* L)
{
    InventoryItemBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "InventoryItemBase is nil");

    float result = b->merchantPriceMod();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 19: void activate(...) - overloaded method
  line 20: void activate(...) - overloaded method
  line 24: void getStolenItemGUIInfo(...) - unsupported arg type
  line 25: void getBuyBackGUIInfo(...) - unsupported arg type
  line 31: GameData* _serialise(...) - unsupported arg type
  line 32: void _loadFromSerialise(...) - unsupported arg type
  line 33: GameSaveState serialise(...) - unsupported return type
  line 34: void loadFromSerialise(...) - unsupported arg type
  line 35: GameData* serialiseInInventory(...) - unsupported arg type
  line 36: void loadFromSerialiseInInventory(...) - unsupported arg type
  line 37: void getTooltipData1(...) - unsupported arg type
  line 38: void _NV_getTooltipData1(...) - unsupported arg type
  line 39: void getTooltipData2(...) - unsupported arg type
  line 40: void _NV_getTooltipData2(...) - unsupported arg type
  line 41: void getGUIData(...) - unsupported arg type
  line 42: void _NV_getGUIData(...) - unsupported arg type
  line 50: int isStackable(...) - unsupported arg type
  line 51: bool canStackWith(...) - unsupported arg type
  line 54: bool isSameAs(...) - unsupported arg type
  line 55: bool _NV_isSameAs(...) - unsupported arg type
  line 57: void addQuantity(...) - non-string reference arg
  line 58: const hand& getProperOwner(...) - reference return type
  line 59: const hand& _NV_getProperOwner(...) - reference return type
  line 60: void setProperOwner(...) - unsupported arg type
  line 61: void _NV_setProperOwner(...) - unsupported arg type
  line 88: InventoryItemBase* _CONSTRUCTOR(...) - unsupported arg type
  line 91: void getTooltipTradeValue(...) - unsupported arg type
*/

int InventoryItemBaseBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InventoryItemBaseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InventoryItemBase object");
    return 1;
}

void InventoryItemBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventoryItemBaseBinding::gc },
        { "__tostring", InventoryItemBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "deactivate", InventoryItemBaseBinding::deactivate },
        { "resetAfterCopy", InventoryItemBaseBinding::resetAfterCopy },
        { "resetCharges", InventoryItemBaseBinding::resetCharges },
        { "getItemType", InventoryItemBaseBinding::getItemType },
        { "getItemWeightSingle", InventoryItemBaseBinding::getItemWeightSingle },
        { "_NV_getItemWeightSingle", InventoryItemBaseBinding::_NV_getItemWeightSingle },
        { "getItemWeight", InventoryItemBaseBinding::getItemWeight },
        { "_NV_getItemWeight", InventoryItemBaseBinding::_NV_getItemWeight },
        { "getAvgPrice", InventoryItemBaseBinding::getAvgPrice },
        { "getValueSingle", InventoryItemBaseBinding::getValueSingle },
        { "_NV_getValueSingle", InventoryItemBaseBinding::_NV_getValueSingle },
        { "getValueAll", InventoryItemBaseBinding::getValueAll },
        { "_NV_getValueAll", InventoryItemBaseBinding::_NV_getValueAll },
        { "getMaxAffordableNum", InventoryItemBaseBinding::getMaxAffordableNum },
        { "_NV_getMaxAffordableNum", InventoryItemBaseBinding::_NV_getMaxAffordableNum },
        { "getInventory", InventoryItemBaseBinding::getInventory },
        { "_NV_getInventory", InventoryItemBaseBinding::_NV_getInventory },
        { "onGround", InventoryItemBaseBinding::onGround },
        { "isResearchArtifact", InventoryItemBaseBinding::isResearchArtifact },
        { "getLevel", InventoryItemBaseBinding::getLevel },
        { "_NV_getLevel", InventoryItemBaseBinding::_NV_getLevel },
        { "getItemSound", InventoryItemBaseBinding::getItemSound },
        { "isStolen", InventoryItemBaseBinding::isStolen },
        { "_DESTRUCTOR", InventoryItemBaseBinding::_DESTRUCTOR },
        { "merchantPriceMod", InventoryItemBaseBinding::merchantPriceMod },
        { 0, 0 }
    };

    registerClass(
        L, 
        InventoryItemBaseBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InventoryItemBaseBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, InventoryItemBase_get_manufacturerData);
    lua_setfield(L, -2, "manufacturerData");
    lua_pushcfunction(L, InventoryItemBase_get_materialData);
    lua_setfield(L, -2, "materialData");
    lua_pushcfunction(L, InventoryItemBase_get_coloriseData);
    lua_setfield(L, -2, "coloriseData");
    lua_pushcfunction(L, InventoryItemBase_get_isInInventory);
    lua_setfield(L, -2, "isInInventory");
    lua_pushcfunction(L, InventoryItemBase_get_inventoryPos);
    lua_setfield(L, -2, "inventoryPos");
    lua_pushcfunction(L, InventoryItemBase_get_inventorySection);
    lua_setfield(L, -2, "inventorySection");
    lua_pushcfunction(L, InventoryItemBase_get_slotType);
    lua_setfield(L, -2, "slotType");
    lua_pushcfunction(L, InventoryItemBase_get_originalFullChargeAmount);
    lua_setfield(L, -2, "originalFullChargeAmount");
    lua_pushcfunction(L, InventoryItemBase_get_chargesLeft);
    lua_setfield(L, -2, "chargesLeft");
    lua_pushcfunction(L, InventoryItemBase_get_quality);
    lua_setfield(L, -2, "quality");
    lua_pushcfunction(L, InventoryItemBase_get_weight);
    lua_setfield(L, -2, "weight");
    lua_pushcfunction(L, InventoryItemBase_get_itemFunction);
    lua_setfield(L, -2, "itemFunction");
    lua_pushcfunction(L, InventoryItemBase_get_isTradeItem);
    lua_setfield(L, -2, "isTradeItem");
    lua_pushcfunction(L, InventoryItemBase_get_isEquipped);
    lua_setfield(L, -2, "isEquipped");
    lua_pushcfunction(L, InventoryItemBase_get_isUnique);
    lua_setfield(L, -2, "isUnique");
    lua_pushcfunction(L, InventoryItemBase_get_quantity);
    lua_setfield(L, -2, "quantity");
    lua_pushcfunction(L, InventoryItemBase_get_itemWidth);
    lua_setfield(L, -2, "itemWidth");
    lua_pushcfunction(L, InventoryItemBase_get_itemHeight);
    lua_setfield(L, -2, "itemHeight");
    lua_pushcfunction(L, InventoryItemBase_get_deathItem);
    lua_setfield(L, -2, "deathItem");
    lua_pushcfunction(L, InventoryItemBase_get_objectType);
    lua_setfield(L, -2, "objectType");
    lua_pushcfunction(L, InventoryItemBase_get_properOwner);
    lua_setfield(L, -2, "properOwner");
    lua_pushcfunction(L, InventoryItemBase_get__whosInventoryWeAreIn);
    lua_setfield(L, -2, "_whosInventoryWeAreIn");
    lua_pushcfunction(L, InventoryItemBase_get__isResearchArtifact);
    lua_setfield(L, -2, "_isResearchArtifact");
    lua_pushcfunction(L, InventoryItemBase_get_itemGroup);
    lua_setfield(L, -2, "itemGroup");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, InventoryItemBase_set_manufacturerData);
    lua_setfield(L, -2, "manufacturerData");
    lua_pushcfunction(L, InventoryItemBase_set_materialData);
    lua_setfield(L, -2, "materialData");
    lua_pushcfunction(L, InventoryItemBase_set_coloriseData);
    lua_setfield(L, -2, "coloriseData");
    lua_pushcfunction(L, InventoryItemBase_set_isInInventory);
    lua_setfield(L, -2, "isInInventory");
    lua_pushcfunction(L, InventoryItemBase_set_inventoryPos);
    lua_setfield(L, -2, "inventoryPos");
    lua_pushcfunction(L, InventoryItemBase_set_inventorySection);
    lua_setfield(L, -2, "inventorySection");
    lua_pushcfunction(L, InventoryItemBase_set_slotType);
    lua_setfield(L, -2, "slotType");
    lua_pushcfunction(L, InventoryItemBase_set_originalFullChargeAmount);
    lua_setfield(L, -2, "originalFullChargeAmount");
    lua_pushcfunction(L, InventoryItemBase_set_chargesLeft);
    lua_setfield(L, -2, "chargesLeft");
    lua_pushcfunction(L, InventoryItemBase_set_quality);
    lua_setfield(L, -2, "quality");
    lua_pushcfunction(L, InventoryItemBase_set_weight);
    lua_setfield(L, -2, "weight");
    lua_pushcfunction(L, InventoryItemBase_set_itemFunction);
    lua_setfield(L, -2, "itemFunction");
    lua_pushcfunction(L, InventoryItemBase_set_isTradeItem);
    lua_setfield(L, -2, "isTradeItem");
    lua_pushcfunction(L, InventoryItemBase_set_isEquipped);
    lua_setfield(L, -2, "isEquipped");
    lua_pushcfunction(L, InventoryItemBase_set_isUnique);
    lua_setfield(L, -2, "isUnique");
    lua_pushcfunction(L, InventoryItemBase_set_quantity);
    lua_setfield(L, -2, "quantity");
    lua_pushcfunction(L, InventoryItemBase_set_itemWidth);
    lua_setfield(L, -2, "itemWidth");
    lua_pushcfunction(L, InventoryItemBase_set_itemHeight);
    lua_setfield(L, -2, "itemHeight");
    lua_pushcfunction(L, InventoryItemBase_set_deathItem);
    lua_setfield(L, -2, "deathItem");
    lua_pushcfunction(L, InventoryItemBase_set_objectType);
    lua_setfield(L, -2, "objectType");
    lua_pushcfunction(L, InventoryItemBase_set_properOwner);
    lua_setfield(L, -2, "properOwner");
    lua_pushcfunction(L, InventoryItemBase_set__whosInventoryWeAreIn);
    lua_setfield(L, -2, "_whosInventoryWeAreIn");
    lua_pushcfunction(L, InventoryItemBase_set__isResearchArtifact);
    lua_setfield(L, -2, "_isResearchArtifact");
    lua_pushcfunction(L, InventoryItemBase_set_itemGroup);
    lua_setfield(L, -2, "itemGroup");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua