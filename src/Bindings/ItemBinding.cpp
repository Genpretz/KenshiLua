#include "pch.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/HandBinding.h"
#include "Bindings/GearBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/Character.h>
#include <kenshi/Gear.h>

#include <kenshi/Item.h>
#include <kenshi/util/hand.h>

#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>

#include <cstdio>
#include <cstring>

namespace KenshiLua
{

// -----------------------------------------------------------------------------
// InventoryItemBaseBinding
// -----------------------------------------------------------------------------

static InventoryItemBase* getBase(lua_State* L, int idx)
{
    return InventoryItemBaseBinding::checkItem(L, idx);
}

int InventoryItemBaseBinding::pushInventoryItemBase(lua_State* L, InventoryItemBase* item)
{
    if (item == nullptr)
    {
        lua_pushnil(L);
        return 1;
    }
    Item* it = dynamic_cast<Item*>(item);
    if (it)
    {
        return ItemBinding::pushItem(L, it);
    }
    return pushObject<InventoryItemBase>(L, item, InventoryItemBaseBinding::getMetatableName());
}

InventoryItemBase* InventoryItemBaseBinding::getItem(lua_State* L, int idx)
{
    InventoryItemBase* i = testObject<InventoryItemBase>(L, idx, InventoryItemBaseBinding::getMetatableName());
    if (i) return i;
    return ItemBinding::getItem(L, idx);
}

InventoryItemBase* InventoryItemBaseBinding::checkItem(lua_State* L, int idx)
{
    InventoryItemBase* i = getItem(L, idx);
    if (!i)
    {
        luaL_argerror(L, idx, "InventoryItemBase");
    }
    return i;
}

int InventoryItemBaseBinding::gc(lua_State* L) { return noopGc(L); }

int InventoryItemBaseBinding::tostring(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushstring(L, "InventoryItemBase:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "InventoryItemBase:%s(%p)", i->getName().c_str(), (void*)i);
    lua_pushstring(L, buf);
    return 1;
}

int InventoryItemBaseBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, InventoryItemBaseBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "isResearchArtifact") == 0) { lua_pushboolean(L, i->isResearchArtifact() ? 1 : 0); return 1; }
    if (strcmp(key, "isEquipped") == 0) { lua_pushboolean(L, i->isEquipped ? 1 : 0); return 1; }
    if (strcmp(key, "onGround") == 0) { lua_pushboolean(L, i->onGround() ? 1 : 0); return 1; }
    if (strcmp(key, "isValid") == 0) { lua_pushboolean(L, i->isValid() ? 1 : 0); return 1; }
    if (strcmp(key, "isInInventory") == 0) { lua_pushboolean(L, i->isInInventory ? 1 : 0); return 1; }
    if (strcmp(key, "isTradeItem") == 0) { lua_pushboolean(L, i->isTradeItem ? 1 : 0); return 1; }
    if (strcmp(key, "isUnique") == 0) { lua_pushboolean(L, i->isUnique ? 1 : 0); return 1; }
    if (strcmp(key, "deathItem") == 0) { lua_pushboolean(L, i->deathItem ? 1 : 0); return 1; }

    // --- float members ---
    if (strcmp(key, "quality") == 0) { lua_pushnumber(L, i->quality); return 1; }
    if (strcmp(key, "itemWeight") == 0) { lua_pushnumber(L, i->getItemWeight()); return 1; }
    if (strcmp(key, "itemWeightSingle") == 0) { lua_pushnumber(L, i->getItemWeightSingle()); return 1; }
    if (strcmp(key, "originalFullChargeAmount") == 0) { lua_pushnumber(L, i->originalFullChargeAmount); return 1; }
    if (strcmp(key, "chargesLeft") == 0) { lua_pushnumber(L, i->chargesLeft); return 1; }

    // --- integer/enum members ---
    if (strcmp(key, "level") == 0) { lua_pushinteger(L, i->getLevel()); return 1; }
    if (strcmp(key, "quantity") == 0) { lua_pushinteger(L, i->quantity); return 1; }
    if (strcmp(key, "slotType") == 0) { lua_pushinteger(L, (int)i->slotType); return 1; }
    if (strcmp(key, "itemFunction") == 0) { lua_pushinteger(L, (int)i->itemFunction); return 1; }
    if (strcmp(key, "itemWidth") == 0) { lua_pushinteger(L, i->itemWidth); return 1; }
    if (strcmp(key, "itemHeight") == 0) { lua_pushinteger(L, i->itemHeight); return 1; }
    if (strcmp(key, "objectType") == 0) { lua_pushinteger(L, (int)i->objectType); return 1; }

    // --- string members ---
    if (strcmp(key, "inventorySection") == 0) { lua_pushstring(L, i->inventorySection.c_str()); return 1; }

    // --- special/object members ---
    if (strcmp(key, "properOwner") == 0) {
        return HandBinding::pushHand(L, i->properOwner);
    }
    if (strcmp(key, "whosInventoryWeAreIn") == 0) {
        return HandBinding::pushHand(L, i->_whosInventoryWeAreIn);
    }
    if (strcmp(key, "manufacturerData") == 0) {
        return pushObject<GameData>(L, i->manufacturerData, GameDataBinding::getMetatableName());
    }
    if (strcmp(key, "materialData") == 0) {
        return pushObject<GameData>(L, i->materialData, GameDataBinding::getMetatableName());
    }
    if (strcmp(key, "coloriseData") == 0) {
        return pushObject<GameData>(L, i->coloriseData, GameDataBinding::getMetatableName());
    }
    if (strcmp(key, "inventoryPos") == 0) {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, i->inventoryPos.x); lua_setfield(L, -2, "x");
        lua_pushinteger(L, i->inventoryPos.y); lua_setfield(L, -2, "y");
        return 1;
    }

    // 3. Fall back to RootObject index
    return RootObjectBinding::index(L);
}

int InventoryItemBaseBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    InventoryItemBase* i = getBase(L, 1);
    if (!i) return luaL_error(L, "InventoryItemBase is nil");

    // --- writable members ---
    if (strcmp(key, "inventorySection") == 0) {
        i->inventorySection = luaL_checkstring(L, 3);
        return 0;
    }
    if (strcmp(key, "isResearchArtifact") == 0) { i->_isResearchArtifact = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "onGround") == 0) return luaL_error(L, "onGround is read-only");
    if (strcmp(key, "isValid") == 0) return luaL_error(L, "isValid is read-only");
    if (strcmp(key, "isInInventory") == 0) { i->isInInventory = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isTradeItem") == 0) { i->isTradeItem = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isUnique") == 0) { i->isUnique = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "deathItem") == 0) { i->deathItem = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isEquipped") == 0) { i->isEquipped = (lua_toboolean(L, 3) != 0); return 0; }

    if (strcmp(key, "quality") == 0) { i->quality = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "originalFullChargeAmount") == 0) { i->originalFullChargeAmount = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "chargesLeft") == 0) { i->chargesLeft = (float)luaL_checknumber(L, 3); return 0; }

    if (strcmp(key, "quantity") == 0) { i->quantity = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "slotType") == 0) { i->slotType = (AttachSlot)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "itemFunction") == 0) { i->itemFunction = (ItemFunction)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "itemWidth") == 0) { i->itemWidth = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "itemHeight") == 0) { i->itemHeight = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "objectType") == 0) { i->objectType = (itemType)luaL_checkinteger(L, 3); return 0; }

    if (strcmp(key, "properOwner") == 0) {
        if (lua_isnil(L, 3)) {
            i->properOwner.setNull();
        } else {
            hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
            if (h) i->properOwner = *h;
        }
        return 0;
    }
    if (strcmp(key, "whosInventoryWeAreIn") == 0) {
        if (lua_isnil(L, 3)) {
            i->_whosInventoryWeAreIn.setNull();
        } else {
            hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
            if (h) i->_whosInventoryWeAreIn = *h;
        }
        return 0;
    }
    if (strcmp(key, "inventoryPos") == 0) {
        if (!lua_istable(L, 3)) return luaL_error(L, "expected table {x,y}");
        lua_getfield(L, 3, "x"); i->inventoryPos.x = (int)luaL_checkinteger(L, -1); lua_pop(L, 1);
        lua_getfield(L, 3, "y"); i->inventoryPos.y = (int)luaL_checkinteger(L, -1); lua_pop(L, 1);
        return 0;
    }

    // Fall back to RootObject newindex
    return RootObjectBinding::newindex(L);
}

int InventoryItemBaseBinding::resetCharges(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) return luaL_error(L, "InventoryItemBase is nil");
    bool randomise = lua_toboolean(L, 2) != 0;
    i->resetCharges(randomise);
    return 0;
}

int InventoryItemBaseBinding::addQuantity(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) return luaL_error(L, "InventoryItemBase is nil");
    int amount = (int)luaL_checkinteger(L, 2);
    Item* addedItem = ItemBinding::checkItem(L, 3);
    InventorySection* section = nullptr;
    if (!lua_isnoneornil(L, 4))
    {
        section = (InventorySection*)testObject<InventorySection>(L, 4, InventorySectionBinding::getMetatableName());
    }
    i->addQuantity(amount, addedItem, section);
    lua_pushinteger(L, amount);
    return 1;
}

int InventoryItemBaseBinding::subtractQuantity(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) return luaL_error(L, "InventoryItemBase is nil");
    int amount = (int)luaL_checkinteger(L, 2);
    i->quantity -= amount;
    if (i->quantity < 0) i->quantity = 0;
    lua_pushinteger(L, i->quantity);
    return 1;
}

int InventoryItemBaseBinding::getItemWeight(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (i) lua_pushnumber(L, i->getItemWeight()); else lua_pushnil(L);
    return 1;
}

int InventoryItemBaseBinding::getItemWeightSingle(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (i) lua_pushnumber(L, i->getItemWeightSingle()); else lua_pushnil(L);
    return 1;
}

int InventoryItemBaseBinding::getValueSingle(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushinteger(L, 0); return 1; }
    bool isPlayer = lua_isnoneornil(L, 2) ? true : (lua_toboolean(L, 2) != 0);
    lua_pushinteger(L, i->getValueSingle(isPlayer));
    return 1;
}

int InventoryItemBaseBinding::getValueAll(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushinteger(L, 0); return 1; }
    bool isPlayer = lua_isnoneornil(L, 2) ? true : (lua_toboolean(L, 2) != 0);
    lua_pushinteger(L, i->getValueAll(isPlayer));
    return 1;
}

int InventoryItemBaseBinding::getQuantity(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (i) lua_pushinteger(L, i->quantity); else lua_pushnil(L);
    return 1;
}

int InventoryItemBaseBinding::getQuality(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (i) lua_pushnumber(L, i->quality); else lua_pushnil(L);
    return 1;
}

int InventoryItemBaseBinding::isResearchArtifact(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    lua_pushboolean(L, i && i->isResearchArtifact() ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::onGround(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    lua_pushboolean(L, i && i->onGround() ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::isStolen(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushboolean(L, 0); return 1; }
    bool includeUnknown = lua_toboolean(L, 2) != 0;
    lua_pushboolean(L, i->isStolen(includeUnknown) ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::getLevel(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (i) lua_pushinteger(L, i->getLevel()); else lua_pushnil(L);
    return 1;
}

int InventoryItemBaseBinding::getInventory(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushnil(L); return 1; }
    Inventory* inv = i->getInventory();
    if (inv) lua_pushlightuserdata(L, (void*)inv);
    else     lua_pushnil(L);
    return 1;
}

int InventoryItemBaseBinding::getMaxAffordable(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushinteger(L, 0); return 1; }
    int cash = (int)luaL_checkinteger(L, 2);
    bool isPlayer = lua_isnoneornil(L, 3) ? true : (lua_toboolean(L, 3) != 0);
    lua_pushinteger(L, i->getMaxAffordableNum(cash, isPlayer));
    return 1;
}

int InventoryItemBaseBinding::getItemType(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (i) lua_pushinteger(L, (int)i->getItemType()); else lua_pushnil(L);
    return 1;
}

int InventoryItemBaseBinding::getAvgPrice(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (i) lua_pushinteger(L, i->getAvgPrice()); else lua_pushnil(L);
    return 1;
}

int InventoryItemBaseBinding::isStackable(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushinteger(L, 0); return 1; }
    InventorySection* sec = (InventorySection*)testObject<InventorySection>(L, 2, "KenshiLua.InventorySection");
    lua_pushinteger(L, i->isStackable(sec));
    return 1;
}

int InventoryItemBaseBinding::canStackWith(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushboolean(L, 0); return 1; }
    InventoryItemBase* other = InventoryItemBaseBinding::getItem(L, 2);
    lua_pushboolean(L, i->canStackWith(other) ? 1 : 0);
    return 1;
}

int InventoryItemBaseBinding::getProperOwner(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) { lua_pushnil(L); return 1; }
    return HandBinding::pushHand(L, i->getProperOwner());
}

int InventoryItemBaseBinding::setProperOwner(lua_State* L)
{
    InventoryItemBase* i = getBase(L, 1);
    if (!i) return luaL_error(L, "InventoryItemBase is nil");
    if (lua_isnil(L, 2)) {
        i->setProperOwner(hand());
    } else {
        hand* h = (hand*)luaL_checkudata(L, 2, HandBinding::getMetatableName());
        if (h) i->setProperOwner(*h);
    }
    return 0;
}

void InventoryItemBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventoryItemBaseBinding::gc },
        { "__tostring", InventoryItemBaseBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "resetCharges",         InventoryItemBaseBinding::resetCharges },
        { "getItemType",          InventoryItemBaseBinding::getItemType },
        { "getItemWeight",        InventoryItemBaseBinding::getItemWeight },
        { "getItemWeightSingle",  InventoryItemBaseBinding::getItemWeightSingle },
        { "getAvgPrice",          InventoryItemBaseBinding::getAvgPrice },
        { "addQuantity",          InventoryItemBaseBinding::addQuantity },
        { "subtractQuantity",     InventoryItemBaseBinding::subtractQuantity },
        { "getValueSingle",       InventoryItemBaseBinding::getValueSingle },
        { "getValueAll",          InventoryItemBaseBinding::getValueAll },
        { "isStackable",          InventoryItemBaseBinding::isStackable },
        { "canStackWith",         InventoryItemBaseBinding::canStackWith },
        { "getInventory",         InventoryItemBaseBinding::getInventory },
        { "getProperOwner",       InventoryItemBaseBinding::getProperOwner },
        { "setProperOwner",       InventoryItemBaseBinding::setProperOwner },
        { "getQuantity",          InventoryItemBaseBinding::getQuantity },
        { "getQuality",           InventoryItemBaseBinding::getQuality },
        { "isResearchArtifact",   InventoryItemBaseBinding::isResearchArtifact },
        { "onGround",             InventoryItemBaseBinding::onGround },
        { "isStolen",             InventoryItemBaseBinding::isStolen },
        { "getLevel",             InventoryItemBaseBinding::getLevel },
        { "getMaxAffordable",     InventoryItemBaseBinding::getMaxAffordable },
        { 0, 0 }
    };
    registerClass(L, InventoryItemBaseBinding::getMetatableName(), meta, methods, InventoryItemBaseBinding::index, InventoryItemBaseBinding::newindex);
}


// -----------------------------------------------------------------------------
// ItemBinding
// -----------------------------------------------------------------------------

static Item* getI(lua_State* L, int idx)
{
    return ItemBinding::checkItem(L, idx);
}

int ItemBinding::pushItem(lua_State* L, Item* item)
{
    if (item == nullptr)
    {
        lua_pushnil(L);
        return 1;
    }
    if (item->isLockedArmour())
    {
        return pushObject<LockedArmour>(L, item->isLockedArmour(), LockedArmourBinding::getMetatableName());
    }
    if (item->isArmour())
    {
        return pushObject<Armour>(L, item->isArmour(), ArmourBinding::getMetatableName());
    }
    Weapon* w = item->isWeapon();
    if (w)
    {
        if (w->isSword())
        {
            return pushObject<Sword>(L, w->isSword(), SwordBinding::getMetatableName());
        }
        if (w->isCrossbow())
        {
            return pushObject<Crossbow>(L, w->isCrossbow(), CrossbowBinding::getMetatableName());
        }
        return pushObject<Weapon>(L, w, WeaponBinding::getMetatableName());
    }
    if (item->isGear())
    {
        return pushObject<Gear>(L, item->isGear(), GearBinding::getMetatableName());
    }
    return pushObject<Item>(L, item, ItemBinding::getMetatableName());
}

Item* ItemBinding::getItem(lua_State* L, int idx)
{
    Item* i = testObject<Item>(L, idx, ItemBinding::getMetatableName());
    if (i) return i;
    i = (Item*)testObject<LockedArmour>(L, idx, LockedArmourBinding::getMetatableName());
    if (i) return i;
    i = (Item*)testObject<Armour>(L, idx, ArmourBinding::getMetatableName());
    if (i) return i;
    i = (Item*)testObject<Sword>(L, idx, SwordBinding::getMetatableName());
    if (i) return i;
    i = (Item*)testObject<Crossbow>(L, idx, CrossbowBinding::getMetatableName());
    if (i) return i;
    i = (Item*)testObject<Weapon>(L, idx, WeaponBinding::getMetatableName());
    if (i) return i;
    i = (Item*)testObject<Gear>(L, idx, GearBinding::getMetatableName());
    if (i) return i;

    // Check generic InventoryItemBase and dynamic_cast it to Item*
    InventoryItemBase* baseItem = testObject<InventoryItemBase>(L, idx, InventoryItemBaseBinding::getMetatableName());
    if (baseItem)
    {
        return dynamic_cast<Item*>(baseItem);
    }
    return nullptr;
}

Item* ItemBinding::checkItem(lua_State* L, int idx)
{
    Item* i = getItem(L, idx);
    if (!i)
    {
        luaL_argerror(L, idx, "Item");
    }
    return i;
}

int ItemBinding::gc(lua_State* L)       { return noopGc(L); }

int ItemBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, ItemBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    Item* i = getI(L, 1);
    if (!i) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "visible") == 0) { lua_pushboolean(L, i->getVisible() ? 1 : 0); return 1; }
    if (strcmp(key, "isPersistant") == 0 || strcmp(key, "persistant") == 0) { lua_pushboolean(L, i->isPersistant() ? 1 : 0); return 1; }

    // --- float members ---
    if (strcmp(key, "athleticsMult") == 0) {
        float val = 1.0f;
        if (i->isArmour()) val = i->isArmour()->athleticsMult;
        else if (i->getClassType() == CONTAINER) val = ((ContainerItem*)i)->athleticsMult;
        lua_pushnumber(L, val);
        return 1;
    }
    if (strcmp(key, "stealthMult") == 0) {
        float val = 1.0f;
        if (i->isArmour()) val = i->isArmour()->stealthMult;
        else if (i->getClassType() == CONTAINER) val = ((ContainerItem*)i)->stealthMult;
        lua_pushnumber(L, val);
        return 1;
    }
    if (strcmp(key, "combatSpeedMult") == 0) {
        float val = 1.0f;
        if (i->isArmour()) val = i->isArmour()->combatSpeedMult;
        else if (i->getClassType() == CONTAINER) val = ((ContainerItem*)i)->combatSpeedMult;
        lua_pushnumber(L, val);
        return 1;
    }

    // --- integer/enum members ---
    if (strcmp(key, "classType") == 0) { lua_pushinteger(L, (int)i->getClassType()); return 1; }
    if (strcmp(key, "combatSkillBonus") == 0) {
        int val = 0;
        if (i->isArmour()) val = i->isArmour()->combatSkillBonusAttk;
        else if (i->getClassType() == CONTAINER) val = ((ContainerItem*)i)->combatSkillBonus;
        lua_pushinteger(L, val);
        return 1;
    }

    // --- string members ---
    if (strcmp(key, "modelName") == 0) { lua_pushstring(L, i->getModelName().c_str()); return 1; }

    // 3. Fall back to InventoryItemBase index
    return InventoryItemBaseBinding::index(L);
}

int ItemBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Item* i = getI(L, 1);
    if (!i) return luaL_error(L, "Item is nil");

    // --- boolean members ---
    if (strcmp(key, "visible") == 0) { i->setVisible(lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isPersistant") == 0 || strcmp(key, "persistant") == 0) {
        if (lua_isboolean(L, 3)) {
            i->setPersistant(lua_toboolean(L, 3) != 0);
        } else if (lua_isnil(L, 3)) {
            i->persistant.setNull();
        } else {
            hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
            if (h) i->setPersistant(*h);
        }
        return 0;
    }

    // --- float members ---
    if (strcmp(key, "athleticsMult") == 0) {
        float val = (float)luaL_checknumber(L, 3);
        if (i->isArmour()) i->isArmour()->athleticsMult = val;
        else if (i->getClassType() == CONTAINER) ((ContainerItem*)i)->athleticsMult = val;
        return 0;
    }
    if (strcmp(key, "stealthMult") == 0) {
        float val = (float)luaL_checknumber(L, 3);
        if (i->isArmour()) i->isArmour()->stealthMult = val;
        else if (i->getClassType() == CONTAINER) ((ContainerItem*)i)->stealthMult = val;
        return 0;
    }
    if (strcmp(key, "combatSpeedMult") == 0) {
        float val = (float)luaL_checknumber(L, 3);
        if (i->isArmour()) i->isArmour()->combatSpeedMult = val;
        else if (i->getClassType() == CONTAINER) ((ContainerItem*)i)->combatSpeedMult = val;
        return 0;
    }

    // --- integer members ---
    if (strcmp(key, "combatSkillBonus") == 0) {
        int val = (int)luaL_checkinteger(L, 3);
        if (i->isArmour()) {
            i->isArmour()->combatSkillBonusAttk = val;
        } else if (i->getClassType() == CONTAINER) {
            ((ContainerItem*)i)->combatSkillBonus = val;
        }
        return 0;
    }

    // Fall back to InventoryItemBase newindex
    return InventoryItemBaseBinding::newindex(L);
}

int ItemBinding::tostring(lua_State* L)
{
    Item* it = getI(L, 1);
    if (!it) { lua_pushstring(L, "Item:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "Item:%s(%p)", it->getName().c_str(), (void*)it);
    lua_pushstring(L, buf);
    return 1;
}

int ItemBinding::getName(lua_State* L)
{
    Item* it = getI(L, 1);
    if (it) lua_pushstring(L, it->getName().c_str()); else lua_pushnil(L);
    return 1;
}

int ItemBinding::getPosition(lua_State* L)
{
    Item* it = getI(L, 1);
    if (!it) { lua_pushnil(L); return 1; }
    Ogre::Vector3 p = it->getPosition();
    pushVector3(L, p);
    return 1;
}

int ItemBinding::getClassType(lua_State* L)         { Item* i = getI(L, 1); if (i) lua_pushinteger(L, (int)i->getClassType()); else lua_pushnil(L); return 1; }
int ItemBinding::getVisible(lua_State* L)           { Item* i = getI(L, 1); lua_pushboolean(L, i && i->getVisible() ? 1 : 0); return 1; }
int ItemBinding::getLevel(lua_State* L)             { Item* i = getI(L, 1); if (i) lua_pushinteger(L, i->getLevel()); else lua_pushnil(L); return 1; }
int ItemBinding::getModelName(lua_State* L)         { Item* i = getI(L, 1); if (i) lua_pushstring(L, i->getModelName().c_str()); else lua_pushnil(L); return 1; }
int ItemBinding::isPersistant(lua_State* L)         { Item* i = getI(L, 1); lua_pushboolean(L, i && i->isPersistant() ? 1 : 0); return 1; }
int ItemBinding::isValid(lua_State* L)              { Item* i = getI(L, 1); lua_pushboolean(L, i && i->isValid() ? 1 : 0); return 1; }

int ItemBinding::getInventory(lua_State* L)
{
    Item* i = getI(L, 1);
    if (!i) { lua_pushnil(L); return 1; }
    Inventory* inv = i->getInventory();
    if (inv) lua_pushlightuserdata(L, (void*)inv);
    else     lua_pushnil(L);
    return 1;
}

int ItemBinding::setVisible(lua_State* L)
{
    Item* i = getI(L, 1);
    if (!i) return luaL_error(L, "Item is nil");
    i->setVisible(lua_toboolean(L, 2) != 0);
    return 0;
}

int ItemBinding::setPositionRotation(lua_State* L)
{
    Item* i = getI(L, 1);
    if (!i) return luaL_error(L, "Item is nil");
    Ogre::Vector3 pos(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, pos)) return luaL_error(L, "setPositionRotation: expected {x,y,z}");
    float qw = (float)luaL_optnumber(L, 3, 1.0);
    float qx = (float)luaL_optnumber(L, 4, 0.0);
    float qy = (float)luaL_optnumber(L, 5, 0.0);
    float qz = (float)luaL_optnumber(L, 6, 0.0);
    Ogre::Quaternion rot(qw, qx, qy, qz);
    bool fixed = lua_isnoneornil(L, 7) ? true : (lua_toboolean(L, 7) != 0);
    i->setPositionRotation(pos, rot, fixed);
    return 0;
}

int ItemBinding::setInventoryWeAreIn(lua_State* L)
{
    Item* i = getI(L, 1);
    if (!i) return luaL_error(L, "Item is nil");
    const char* handStr = luaL_checkstring(L, 2);
    hand h;
    h.fromString(handStr);
    i->setInventoryWeAreIn(h);
    return 0;
}

int ItemBinding::setPersistant(lua_State* L)
{
    Item* i = getI(L, 1);
    if (!i) return luaL_error(L, "Item is nil");
    i->setPersistant(lua_toboolean(L, 2) != 0);
    return 0;
}

int ItemBinding::stolenGoodsDetectionCheck(lua_State* L)
{
    Item* i = getI(L, 1);
    if (!i) return luaL_error(L, "Item is nil");
    Item* targetItem = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    if (!targetItem) return luaL_error(L, "stolenGoodsDetectionCheck: expected Item userdata as argument 2");
    RootObject* thief = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    if (!thief) {
        thief = (RootObject*)checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    }
    if (!thief) return luaL_error(L, "stolenGoodsDetectionCheck: expected RootObject/Character userdata as argument 3");
    
    lua_pushboolean(L, i->stolenGoodsDetectionCheck(targetItem, thief) ? 1 : 0);
    return 1;
}

void ItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ItemBinding::gc },
        { "__tostring", ItemBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getName",              ItemBinding::getName },
        { "getPosition",          ItemBinding::getPosition },
        { "getClassType",         ItemBinding::getClassType },
        { "getVisible",           ItemBinding::getVisible },
        { "getInventory",         ItemBinding::getInventory },
        { "getLevel",             ItemBinding::getLevel },
        { "getModelName",         ItemBinding::getModelName },
        { "isPersistant",         ItemBinding::isPersistant },
        { "isValid",              ItemBinding::isValid },
        { "setVisible",           ItemBinding::setVisible },
        { "setPositionRotation",  ItemBinding::setPositionRotation },
        { "setInventoryWeAreIn",  ItemBinding::setInventoryWeAreIn },
        { "setPersistant",        ItemBinding::setPersistant },
        { "stolenGoodsDetectionCheck", ItemBinding::stolenGoodsDetectionCheck },
        { 0, 0 }
    };
    registerClass(L, ItemBinding::getMetatableName(), meta, methods, ItemBinding::index, ItemBinding::newindex);
}

} // namespace KenshiLua
