#include "pch.h"
#include "kenshi\Item.h"
#include "InventoryItemBaseBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/Util/iVector2Binding.h"
#include "Bindings/Util/HandBinding.h"
#include "InventoryBinding.h"
#include "kenshi/Inventory.h"

namespace KenshiLua
{

static InventoryItemBase* getInstance(lua_State* L, int idx)
{
    return checkObject<InventoryItemBase>(L, idx, InventoryItemBaseBinding::getMetatableName());
}

// --- Getters for InventoryItemBase ---
static int InventoryItemBase_get_manufacturerData(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    return pushObject<GameData>(L, instance->manufacturerData, GameDataBinding::getMetatableName());
}

static int InventoryItemBase_get_materialData(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    return pushObject<GameData>(L, instance->materialData, GameDataBinding::getMetatableName());
}

static int InventoryItemBase_get_coloriseData(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    return pushObject<GameData>(L, instance->coloriseData, GameDataBinding::getMetatableName());
}

static int InventoryItemBase_get_isInInventory(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, instance->isInInventory ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_inventoryPos(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    return pushObject<iVector2>(L, &instance->inventoryPos, iVector2Binding::getMetatableName());
}

static int InventoryItemBase_get_inventorySection(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushstring(L, instance->inventorySection.c_str());
    return 1;
}

static int InventoryItemBase_get_slotType(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, (lua_Integer)instance->slotType);
    return 1;
}

static int InventoryItemBase_get_originalFullChargeAmount(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushnumber(L, instance->originalFullChargeAmount);
    return 1;
}

static int InventoryItemBase_get_chargesLeft(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushnumber(L, instance->chargesLeft);
    return 1;
}

static int InventoryItemBase_get_quality(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushnumber(L, instance->quality);
    return 1;
}

static int InventoryItemBase_get_weight(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushnumber(L, instance->weight);
    return 1;
}

static int InventoryItemBase_get_itemFunction(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, (lua_Integer)instance->itemFunction);
    return 1;
}

static int InventoryItemBase_get_isTradeItem(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, instance->isTradeItem ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_isEquipped(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, instance->isEquipped ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_isUnique(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, instance->isUnique ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_quantity(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, instance->quantity);
    return 1;
}

static int InventoryItemBase_get_itemWidth(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, instance->itemWidth);
    return 1;
}

static int InventoryItemBase_get_itemHeight(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, instance->itemHeight);
    return 1;
}

static int InventoryItemBase_get_deathItem(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, instance->deathItem ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_objectType(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushinteger(L, (lua_Integer)instance->objectType);
    return 1;
}

static int InventoryItemBase_get_properOwner(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    return handBinding::push(L, instance->properOwner);
}

static int InventoryItemBase_get__whosInventoryWeAreIn(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    return handBinding::push(L, instance->_whosInventoryWeAreIn);
}

static int InventoryItemBase_get__isResearchArtifact(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushboolean(L, instance->_isResearchArtifact ? 1 : 0);
    return 1;
}

static int InventoryItemBase_get_itemGroup(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    lua_pushlightuserdata(L, (void*)instance->itemGroup);
    return 1;
}

// --- Setters for InventoryItemBase ---
static int InventoryItemBase_set_manufacturerData(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->manufacturerData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int InventoryItemBase_set_materialData(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->materialData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int InventoryItemBase_set_coloriseData(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->coloriseData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int InventoryItemBase_set_isInInventory(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->isInInventory = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_inventoryPos(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->inventoryPos = *checkObject<iVector2>(L, 2, iVector2Binding::getMetatableName());
    return 0;
}

static int InventoryItemBase_set_inventorySection(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->inventorySection = luaL_checkstring(L, 2);
    return 0;
}

static int InventoryItemBase_set_slotType(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->slotType = (AttachSlot)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_originalFullChargeAmount(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->originalFullChargeAmount = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventoryItemBase_set_chargesLeft(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->chargesLeft = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventoryItemBase_set_quality(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->quality = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventoryItemBase_set_weight(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->weight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int InventoryItemBase_set_itemFunction(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->itemFunction = (ItemFunction)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_isTradeItem(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->isTradeItem = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_isEquipped(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->isEquipped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_isUnique(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->isUnique = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_quantity(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->quantity = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_itemWidth(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->itemWidth = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_itemHeight(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->itemHeight = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_deathItem(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->deathItem = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryItemBase_set_objectType(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->objectType = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryItemBase_set_properOwner(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->properOwner = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int InventoryItemBase_set__whosInventoryWeAreIn(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->_whosInventoryWeAreIn = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int InventoryItemBase_set__isResearchArtifact(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    instance->_isResearchArtifact = lua_toboolean(L, 2) != 0;
    return 0;
}

int InventoryItemBaseBinding::deactivate(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    instance->deactivate();
    return 0;
}

int InventoryItemBaseBinding::resetAfterCopy(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    instance->resetAfterCopy();
    return 0;
}

int InventoryItemBaseBinding::resetCharges(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    bool randomise = lua_toboolean(L, 2) != 0;
    instance->resetCharges(randomise);
    return 0;
}

int InventoryItemBaseBinding::getItemType(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    itemType result = instance->getItemType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int InventoryItemBaseBinding::getItemWeightSingle(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    float result = instance->getItemWeightSingle();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getItemWeightSingle(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    float result = instance->_NV_getItemWeightSingle();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryItemBaseBinding::getItemWeight(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    float result = instance->getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getItemWeight(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    float result = instance->_NV_getItemWeight();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryItemBaseBinding::_serialise(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    GameDataContainer* _a1 = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType _a2 = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_serialise(_a1, _a2);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int InventoryItemBaseBinding::_loadFromSerialise(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    GameDataContainer* _a1 = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* _a2 = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_loadFromSerialise(_a1, _a2);
    return 0;
}

int InventoryItemBaseBinding::loadFromSerialise(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    GameSaveState* _a1 = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(_a1);
    return 0;
}

int InventoryItemBaseBinding::serialiseInInventory(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    GameDataContainer* _a1 = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* _a2 = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* result = instance->serialiseInInventory(_a1, _a2);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int InventoryItemBaseBinding::loadFromSerialiseInInventory(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    GameDataContainer* _a1 = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* _a2 = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->loadFromSerialiseInInventory(_a1, _a2);
    return 0;
}

int InventoryItemBaseBinding::getGUIData(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, category);
    return 0;
}

int InventoryItemBaseBinding::_NV_getGUIData(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(datapanel, category);
    return 0;
}

int InventoryItemBaseBinding::getAvgPrice(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    int result = instance->getAvgPrice();
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::getValueSingle(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = instance->getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getValueSingle(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = instance->_NV_getValueSingle(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::getValueAll(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = instance->getValueAll(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getValueAll(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    bool isPlayer = lua_toboolean(L, 2) != 0;
    int result = instance->_NV_getValueAll(isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::getMaxAffordableNum(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    int cashLimit = (int)luaL_checkinteger(L, 2);
    bool isPlayer = lua_toboolean(L, 3) != 0;
    int result = instance->getMaxAffordableNum(cashLimit, isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getMaxAffordableNum(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    int cashLimit = (int)luaL_checkinteger(L, 2);
    bool isPlayer = lua_toboolean(L, 3) != 0;
    int result = instance->_NV_getMaxAffordableNum(cashLimit, isPlayer);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::isStackable(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    InventorySection* section = checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    int result = instance->isStackable(section);
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::canStackWith(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    InventoryItemBase* other = checkObject<InventoryItemBase>(L, 2, InventoryItemBaseBinding::getMetatableName());
    bool result = instance->canStackWith(other);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::getInventory(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryItemBaseBinding::_NV_getInventory(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryItemBaseBinding::isSameAs(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    InventoryItemBase* who = checkObject<InventoryItemBase>(L, 2, InventoryItemBaseBinding::getMetatableName());
    bool result = instance->isSameAs(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::_NV_isSameAs(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    InventoryItemBase* who = checkObject<InventoryItemBase>(L, 2, InventoryItemBaseBinding::getMetatableName());
    bool result = instance->_NV_isSameAs(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::onGround(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    bool result = instance->onGround();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::isResearchArtifact(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    bool result = instance->isResearchArtifact();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::getLevel(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    int result = instance->getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::_NV_getLevel(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    int result = instance->_NV_getLevel();
    lua_pushinteger(L, result);
    return 1;
}

int InventoryItemBaseBinding::getItemSound(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    const char* result = instance->getItemSound();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int InventoryItemBaseBinding::isStolen(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    bool includeUnknown = lua_toboolean(L, 2) != 0;
    bool result = instance->isStolen(includeUnknown);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::_CONSTRUCTOR(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    hand _handle = *checkObject<hand>(L, 3, handBinding::getMetatableName());
    GameData* manufacturerData = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    GameData* materialData = checkObject<GameData>(L, 5, GameDataBinding::getMetatableName());
    InventoryItemBase* result = instance->_CONSTRUCTOR(dat, _handle, manufacturerData, materialData);
    return pushObject<InventoryItemBase>(L, result, InventoryItemBaseBinding::getMetatableName());
}

int InventoryItemBaseBinding::_DESTRUCTOR(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int InventoryItemBaseBinding::merchantPriceMod(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");

    float result = instance->merchantPriceMod();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 19: void activate(...) - overloaded method
  line 20: void activate(...) - overloaded method
  line 24: void getStolenItemGUIInfo(...) - unsupported arg type
  line 25: void getBuyBackGUIInfo(...) - unsupported arg type
  line 33: GameSaveState serialise(...) - unsupported arg type
  line 37: void getTooltipData1(...) - unsupported arg type
  line 38: void _NV_getTooltipData1(...) - unsupported arg type
  line 39: void getTooltipData2(...) - unsupported arg type
  line 40: void _NV_getTooltipData2(...) - unsupported arg type
  line 57: void addQuantity(...) - non-string reference arg
  line 58: const hand& getProperOwner(...) - reference return type
  line 59: const hand& _NV_getProperOwner(...) - reference return type
  line 60: void setProperOwner(...) - non-string reference arg
  line 61: void _NV_setProperOwner(...) - non-string reference arg
  line 91: void getTooltipTradeValue(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - InventoryItemBase_get_itemGroup: BuildingItemGroup* (unbound pointer)
  - InventoryItemBaseBinding::getItemSound: const char* (unbound pointer)
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



static int InventoryItemBase_set_itemGroup(lua_State* L)
{
    InventoryItemBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryItemBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for itemGroup");
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
        { "_serialise", InventoryItemBaseBinding::_serialise },
        { "_loadFromSerialise", InventoryItemBaseBinding::_loadFromSerialise },
        { "loadFromSerialise", InventoryItemBaseBinding::loadFromSerialise },
        { "serialiseInInventory", InventoryItemBaseBinding::serialiseInInventory },
        { "loadFromSerialiseInInventory", InventoryItemBaseBinding::loadFromSerialiseInInventory },
        { "getGUIData", InventoryItemBaseBinding::getGUIData },
        { "_NV_getGUIData", InventoryItemBaseBinding::_NV_getGUIData },
        { "getAvgPrice", InventoryItemBaseBinding::getAvgPrice },
        { "getValueSingle", InventoryItemBaseBinding::getValueSingle },
        { "_NV_getValueSingle", InventoryItemBaseBinding::_NV_getValueSingle },
        { "getValueAll", InventoryItemBaseBinding::getValueAll },
        { "_NV_getValueAll", InventoryItemBaseBinding::_NV_getValueAll },
        { "getMaxAffordableNum", InventoryItemBaseBinding::getMaxAffordableNum },
        { "_NV_getMaxAffordableNum", InventoryItemBaseBinding::_NV_getMaxAffordableNum },
        { "isStackable", InventoryItemBaseBinding::isStackable },
        { "canStackWith", InventoryItemBaseBinding::canStackWith },
        { "getInventory", InventoryItemBaseBinding::getInventory },
        { "_NV_getInventory", InventoryItemBaseBinding::_NV_getInventory },
        { "isSameAs", InventoryItemBaseBinding::isSameAs },
        { "_NV_isSameAs", InventoryItemBaseBinding::_NV_isSameAs },
        { "onGround", InventoryItemBaseBinding::onGround },
        { "isResearchArtifact", InventoryItemBaseBinding::isResearchArtifact },
        { "getLevel", InventoryItemBaseBinding::getLevel },
        { "_NV_getLevel", InventoryItemBaseBinding::_NV_getLevel },
        { "getItemSound", InventoryItemBaseBinding::getItemSound },
        { "isStolen", InventoryItemBaseBinding::isStolen },
        { "_CONSTRUCTOR", InventoryItemBaseBinding::_CONSTRUCTOR },
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
    registerGetter(L, "manufacturerData", InventoryItemBase_get_manufacturerData);
    registerGetter(L, "materialData", InventoryItemBase_get_materialData);
    registerGetter(L, "coloriseData", InventoryItemBase_get_coloriseData);
    registerGetter(L, "isInInventory", InventoryItemBase_get_isInInventory);
    registerGetter(L, "inventoryPos", InventoryItemBase_get_inventoryPos);
    registerGetter(L, "inventorySection", InventoryItemBase_get_inventorySection);
    registerGetter(L, "slotType", InventoryItemBase_get_slotType);
    registerGetter(L, "originalFullChargeAmount", InventoryItemBase_get_originalFullChargeAmount);
    registerGetter(L, "chargesLeft", InventoryItemBase_get_chargesLeft);
    registerGetter(L, "quality", InventoryItemBase_get_quality);
    registerGetter(L, "weight", InventoryItemBase_get_weight);
    registerGetter(L, "itemFunction", InventoryItemBase_get_itemFunction);
    registerGetter(L, "isTradeItem", InventoryItemBase_get_isTradeItem);
    registerGetter(L, "isEquipped", InventoryItemBase_get_isEquipped);
    registerGetter(L, "isUnique", InventoryItemBase_get_isUnique);
    registerGetter(L, "quantity", InventoryItemBase_get_quantity);
    registerGetter(L, "itemWidth", InventoryItemBase_get_itemWidth);
    registerGetter(L, "itemHeight", InventoryItemBase_get_itemHeight);
    registerGetter(L, "deathItem", InventoryItemBase_get_deathItem);
    registerGetter(L, "objectType", InventoryItemBase_get_objectType);
    registerGetter(L, "properOwner", InventoryItemBase_get_properOwner);
    registerGetter(L, "_whosInventoryWeAreIn", InventoryItemBase_get__whosInventoryWeAreIn);
    registerGetter(L, "_isResearchArtifact", InventoryItemBase_get__isResearchArtifact);
    registerGetter(L, "itemGroup", InventoryItemBase_get_itemGroup);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "manufacturerData", InventoryItemBase_set_manufacturerData);
    registerSetter(L, "materialData", InventoryItemBase_set_materialData);
    registerSetter(L, "coloriseData", InventoryItemBase_set_coloriseData);
    registerSetter(L, "isInInventory", InventoryItemBase_set_isInInventory);
    registerSetter(L, "inventoryPos", InventoryItemBase_set_inventoryPos);
    registerSetter(L, "inventorySection", InventoryItemBase_set_inventorySection);
    registerSetter(L, "slotType", InventoryItemBase_set_slotType);
    registerSetter(L, "originalFullChargeAmount", InventoryItemBase_set_originalFullChargeAmount);
    registerSetter(L, "chargesLeft", InventoryItemBase_set_chargesLeft);
    registerSetter(L, "quality", InventoryItemBase_set_quality);
    registerSetter(L, "weight", InventoryItemBase_set_weight);
    registerSetter(L, "itemFunction", InventoryItemBase_set_itemFunction);
    registerSetter(L, "isTradeItem", InventoryItemBase_set_isTradeItem);
    registerSetter(L, "isEquipped", InventoryItemBase_set_isEquipped);
    registerSetter(L, "isUnique", InventoryItemBase_set_isUnique);
    registerSetter(L, "quantity", InventoryItemBase_set_quantity);
    registerSetter(L, "itemWidth", InventoryItemBase_set_itemWidth);
    registerSetter(L, "itemHeight", InventoryItemBase_set_itemHeight);
    registerSetter(L, "deathItem", InventoryItemBase_set_deathItem);
    registerSetter(L, "objectType", InventoryItemBase_set_objectType);
    registerSetter(L, "properOwner", InventoryItemBase_set_properOwner);
    registerSetter(L, "_whosInventoryWeAreIn", InventoryItemBase_set__whosInventoryWeAreIn);
    registerSetter(L, "_isResearchArtifact", InventoryItemBase_set__isResearchArtifact);
        registerSetter(L, "itemGroup", InventoryItemBase_set_itemGroup);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to RootObject
    setMetatableParent(L, InventoryItemBaseBinding::getMetatableName(), RootObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua